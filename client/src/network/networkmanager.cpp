#include <algorithm>
#include <chrono>
#include <random>
#include <QRandomGenerator>
#include <QDateTime>

#include "networkmanager.h"
#include "serverlistmanager.h"
#include "src/appcore.h"
#include "src/config/appconfig.h"
#include "src/common/build_config.h"
#include "src/common/frequency_utils.h"
#include "src/common/notificationtype.h"
#include "src/common/utils.h"
#include "src/aircrafts/aircraft_visual_state.h"
#include "src/aircrafts/velocity_vector.h"

namespace xpilot
{
    NetworkManager::NetworkManager(XplaneAdapter &xplaneAdapter, QObject *owner) :
        QObject(owner),
        m_xplaneAdapter(xplaneAdapter)
    {
        QDir networkLogPath(pathAppend(AppConfig::getInstance()->dataRoot(), "NetworkLogs"));
        if(!networkLogPath.exists()) {
            networkLogPath.mkpath(".");
        }

        // keep only the last 5 log files
        QFileInfoList files = networkLogPath.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Time);
        const int MAX_LOGS_TO_RETAIN = 5;
        for(int index = files.size(); index >= MAX_LOGS_TO_RETAIN; --index) {
            const QFileInfo &info = files.at(index - 1);
            QFile::remove(info.absoluteFilePath());
        }

        m_networkLog.setFileName(pathAppend(networkLogPath.path(), QString("NetworkLog-%1.txt").arg(QDateTime::currentDateTimeUtc().toString("yyyyMMdd-hhmmss"))));
        if(m_networkLog.open(QFile::WriteOnly))
        {
            m_rawDataStream.setDevice(&m_networkLog);
        }

        connect(&m_fsd, &FsdClient::RaiseNetworkError, this, &NetworkManager::OnNetworkError);
        connect(&m_fsd, &FsdClient::RaiseProtocolErrorReceived, this, &NetworkManager::OnProtocolErrorReceived);
        connect(&m_fsd, &FsdClient::RaiseNetworkConnected, this, &NetworkManager::OnNetworkConnected);
        connect(&m_fsd, &FsdClient::RaiseNetworkDisconnected, this, &NetworkManager::OnNetworkDisconnected);
        connect(&m_fsd, &FsdClient::RaiseServerIdentificationReceived, this, &NetworkManager::OnServerIdentificationReceived);
        connect(&m_fsd, &FsdClient::RaiseClientQueryReceived, this, &NetworkManager::OnClientQueryReceived);
        connect(&m_fsd, &FsdClient::RaiseClientQueryResponseReceived, this, &NetworkManager::OnClientQueryResponseReceived);
        connect(&m_fsd, &FsdClient::RaisePilotPositionReceived, this, &NetworkManager::OnPilotPositionReceived);
        connect(&m_fsd, &FsdClient::RaiseFastPilotPositionReceived, this, &NetworkManager::OnFastPilotPositionReceived);
        connect(&m_fsd, &FsdClient::RaiseATCPositionReceived, this, &NetworkManager::OnATCPositionReceived);
        connect(&m_fsd, &FsdClient::RaiseDeletePilotReceived, this, &NetworkManager::OnDeletePilotReceived);
        connect(&m_fsd, &FsdClient::RaiseDeleteATCReceived, this, &NetworkManager::OnDeleteATCReceived);
        connect(&m_fsd, &FsdClient::RaisePingReceived, this, &NetworkManager::OnPingReceived);
        connect(&m_fsd, &FsdClient::RaiseTextMessageReceived, this, &NetworkManager::OnTextMessageReceived);
        connect(&m_fsd, &FsdClient::RaiseRadioMessageReceived, this, &NetworkManager::OnRadioMessageReceived);
        connect(&m_fsd, &FsdClient::RaiseBroadcastMessageReceived, this, &NetworkManager::OnBroadcastMessageReceived);
        connect(&m_fsd, &FsdClient::RaiseMetarResponseReceived, this, &NetworkManager::OnMetarResponseReceived);
        connect(&m_fsd, &FsdClient::RaisePlaneInfoRequestReceived, this, &NetworkManager::OnPlaneInfoRequestReceived);
        connect(&m_fsd, &FsdClient::RaisePlaneInfoResponseReceived, this, &NetworkManager::OnPlaneInfoResponseReceived);
        connect(&m_fsd, &FsdClient::RaiseKillRequestReceived, this, &NetworkManager::OnKillRequestReceived);
        connect(&m_fsd, &FsdClient::RaiseSendFastReceived, this, &NetworkManager::OnSendFastReceived);
        connect(&m_fsd, &FsdClient::RaiseRawDataSent, this, &NetworkManager::OnRawDataSent);
        connect(&m_fsd, &FsdClient::RaiseRawDataReceived, this, &NetworkManager::OnRawDataReceived);

        connect(&xplaneAdapter, &XplaneAdapter::userAircraftDataChanged, this, &NetworkManager::OnUserAircraftDataUpdated);
        connect(&xplaneAdapter, &XplaneAdapter::userAircraftConfigDataChanged, this, &NetworkManager::OnUserAircraftConfigDataUpdated);
        connect(&xplaneAdapter, &XplaneAdapter::radioStackStateChanged, this, &NetworkManager::OnRadioStackStateChanged);
        connect(&xplaneAdapter, &XplaneAdapter::requestStationInfo, this, &NetworkManager::OnRequestControllerInfo);
        connect(&xplaneAdapter, &XplaneAdapter::radioMessageSent, this, &NetworkManager::sendRadioMessage);
        connect(&xplaneAdapter, &XplaneAdapter::privateMessageSent, this, &NetworkManager::sendPrivateMessage);
        connect(&xplaneAdapter, &XplaneAdapter::requestMetar, this, &NetworkManager::RequestMetar);
        connect(&xplaneAdapter, &XplaneAdapter::forceDisconnect, this, &NetworkManager::OnForceDisconnected);

        connect(this, &NetworkManager::notificationPosted, this, [&](int type, QString message)
        {
            auto msgType = static_cast<NotificationType>(type);
            switch(msgType)
            {
            case NotificationType::Error:
                m_xplaneAdapter.NotificationPosted(message, COLOR_RED);
            break;
            case NotificationType::Info:
                m_xplaneAdapter.NotificationPosted(message, COLOR_YELLOW);
            break;
            case NotificationType::RadioMessageSent:
                m_xplaneAdapter.NotificationPosted(message, COLOR_CYAN);
            break;
            case NotificationType::ServerMessage:
                m_xplaneAdapter.NotificationPosted(message, COLOR_GREEN);
            break;
            case NotificationType::Warning:
                m_xplaneAdapter.NotificationPosted(message, COLOR_ORANGE);
            break;
            }
        });

        m_slowPositionTimer = new QTimer(this);
        connect(m_slowPositionTimer, &QTimer::timeout, this, &NetworkManager::OnSlowPositionTimerElapsed);

        m_fastPositionTimer = new QTimer(this);
        m_fastPositionTimer->setInterval(200);
        connect(m_fastPositionTimer, &QTimer::timeout, this, &NetworkManager::OnFastPositionTimerElapsed);
    }

    NetworkManager::~NetworkManager()
    {
        m_networkLog.close();
    }

    void NetworkManager::OnNetworkConnected()
    {
        if(m_connectInfo.ObserverMode) {
            emit notificationPosted((int)NotificationType::Info, "Connected to network in observer mode.");
        }
        else if(m_connectInfo.TowerViewMode) {
            emit notificationPosted((int)NotificationType::Info, "Connected to TowerView proxy.");
        } else {
            emit notificationPosted((int)NotificationType::Info, "Connected to network.");
        }
        emit networkConnected(m_connectInfo.Callsign, !m_connectInfo.TowerViewMode && !AppConfig::getInstance()->VelocityEnabled);

        if(!m_connectInfo.TowerViewMode) {
            QJsonObject reply;
            reply.insert("type", "NetworkConnected");
            QJsonObject data;
            data.insert("callsign", m_connectInfo.Callsign);
            reply.insert("data", data);
            QJsonDocument doc(reply);
            m_xplaneAdapter.sendSocketMessage(QString(doc.toJson(QJsonDocument::Compact)));
        }
    }

    void NetworkManager::OnNetworkDisconnected()
    {
        m_fastPositionTimer->stop();
        m_slowPositionTimer->stop();

        if(m_connectInfo.TowerViewMode) {
            emit notificationPosted((int)NotificationType::Info, "Disconnected from TowerView proxy.");
        }
        else {
            if(m_forcedDisconnect) {
                if(!m_forcedDisconnectReason.isEmpty()) {
                    emit notificationPosted((int)NotificationType::Error, "Forcibly disconnected from network: " + m_forcedDisconnectReason);
                }
                else {
                    emit notificationPosted((int)NotificationType::Error, "Forcibly disconnected from network.");
                }
            }
            else {
                emit notificationPosted((int)NotificationType::Info, "Disconnected from network.");
            }
        }

        QJsonObject reply;
        reply.insert("type", "NetworkDisconnected");
        QJsonDocument doc(reply);
        m_xplaneAdapter.sendSocketMessage(QString(doc.toJson(QJsonDocument::Compact)));

        emit networkDisconnected(m_forcedDisconnect);

        m_intentionalDisconnect = false;
        m_forcedDisconnect = false;
        m_forcedDisconnectReason = "";
    }

    void NetworkManager::OnForceDisconnected(QString reason)
    {
        m_forcedDisconnect = true;
        m_forcedDisconnectReason = reason;

        m_fsd.SendPDU(PDUDeletePilot(m_connectInfo.Callsign, AppConfig::getInstance()->VatsimId));
        m_fsd.Disconnect();
    }

    void NetworkManager::OnServerIdentificationReceived(PDUServerIdentification pdu)
    {
        m_fsd.SendPDU(PDUClientIdentification(m_connectInfo.Callsign, BuildConfig::VatsimClientId(), "xPilot", 1, 2, AppConfig::getInstance()->VatsimId, GetSystemUid(), ""));

        if(m_connectInfo.ObserverMode) {
            m_fsd.SendPDU(PDUAddATC(m_connectInfo.Callsign, AppConfig::getInstance()->Name, AppConfig::getInstance()->VatsimId,
                                    AppConfig::getInstance()->VatsimPasswordDecrypted, NetworkRating::OBS, ProtocolRevision::VatsimAuth));
        }
        else {
            m_fsd.SendPDU(PDUAddPilot(m_connectInfo.Callsign, AppConfig::getInstance()->VatsimId, AppConfig::getInstance()->VatsimPasswordDecrypted,
                                      NetworkRating::OBS, ProtocolRevision::VatsimAuth, SimulatorType::XPlane, AppConfig::getInstance()->NameWithHomeAirport()));
        }

        m_fsd.SendPDU(PDUClientQuery(m_connectInfo.Callsign, "SERVER", ClientQueryType::PublicIP));
        SendSlowPositionPacket();
        SendEmptyFastPositionPacket();
        m_slowPositionTimer->setInterval(m_connectInfo.ObserverMode ? 15000 : 5000);
        m_slowPositionTimer->start();
    }

    void NetworkManager::OnClientQueryReceived(PDUClientQuery pdu)
    {
        switch(pdu.QueryType)
        {
        case ClientQueryType::AircraftConfiguration:
            emit aircraftConfigurationInfoReceived(pdu.From, pdu.Payload.join(":"));
        break;
        case ClientQueryType::Capabilities:
            if(pdu.From.toUpper() != "SERVER")
            {
                emit capabilitiesRequestReceived(pdu.From);
            }
            SendCapabilities(pdu.From);
        break;
        case ClientQueryType::COM1Freq:
        {
            QStringList payload;
            QString freq = QString::number(m_radioStackState.Com1Frequency / 1000.0, 'f', 3);
            payload.append(freq);
            m_fsd.SendPDU(PDUClientQueryResponse(m_connectInfo.Callsign, pdu.From, ClientQueryType::COM1Freq, payload));
        }
        break;
        case ClientQueryType::RealName:
        {
            QStringList realName;
            realName.append(AppConfig::getInstance()->NameWithHomeAirport());
            realName.append("");
            realName.append(QString::number((int)NetworkRating::OBS));
            m_fsd.SendPDU(PDUClientQueryResponse(m_connectInfo.Callsign, pdu.From, ClientQueryType::RealName, realName));
        }
        break;
        case ClientQueryType::INF:
            QString inf = QString("xPilot %1 PID=%2 (%3) IP=%4 SYS_UID=%5 FS_VER=XPlane LT=%6 LO=%7 AL=%8")
                    .arg(BuildConfig::getVersionString(),
                         AppConfig::getInstance()->VatsimId,
                         AppConfig::getInstance()->NameWithHomeAirport(),
                         m_publicIp,
                         GetSystemUid(),
                         QString::number(m_userAircraftData.Latitude),
                         QString::number(m_userAircraftData.Longitude),
                         QString::number(m_userAircraftData.AltitudeMslM * 3.28084));
            m_fsd.SendPDU(PDUTextMessage(m_connectInfo.Callsign, pdu.From, inf));
        break;
        }
    }

    void NetworkManager::OnClientQueryResponseReceived(PDUClientQueryResponse pdu)
    {
        switch(pdu.QueryType)
        {
        case ClientQueryType::PublicIP:
            m_publicIp = pdu.Payload.size() > 0 ? pdu.Payload[0] : "";
        break;
        case ClientQueryType::IsValidATC:
            if(pdu.Payload.at(0).toUpper() == "Y") {
                emit isValidAtcReceived(pdu.Payload.at(1).toUpper());
            }
        break;
        case ClientQueryType::RealName:
            emit realNameReceived(pdu.From, pdu.Payload.at(0));
        break;
        case ClientQueryType::ATIS:
            if(pdu.Payload.at(0) == "E")
            {
                // atis end
                if(m_mapAtisMessages.contains(pdu.From.toUpper()))
                {
                    emit controllerAtisReceived(pdu.From.toUpper(), m_mapAtisMessages[pdu.From.toUpper()]);

                    m_xplaneAdapter.NotificationPosted(pdu.From.toUpper() + " ATIS:", COLOR_BRIGHT_GREEN);
                    for(const auto& line : std::as_const(m_mapAtisMessages[pdu.From.toUpper()])) {
                        m_xplaneAdapter.NotificationPosted(line, COLOR_BRIGHT_GREEN);
                    }

                    m_mapAtisMessages.remove(pdu.From.toUpper());
                }
            }
            else if(pdu.Payload.at(0) == "Z")
            {
                // controller info/controller logoff time
                if(m_mapAtisMessages.contains(pdu.From.toUpper()))
                {
                    m_mapAtisMessages[pdu.From.toUpper()].push_back(QString("Estimated logoff time: %1").arg(pdu.Payload[1]));
                }
            }
            else if(pdu.Payload.at(0) == "T")
            {
                // controller info/controller logoff time
                if(m_mapAtisMessages.contains(pdu.From.toUpper()))
                {
                    m_mapAtisMessages[pdu.From.toUpper()].push_back(pdu.Payload[1]);
                }
            }
        break;
        case ClientQueryType::Capabilities:
            emit capabilitiesResponseReceived(pdu.From, pdu.Payload.join(":"));
        break;
        }
    }

    void NetworkManager::OnPilotPositionReceived(PDUPilotPosition pdu)
    {
        QRegularExpression re("^"+ QRegularExpression::escape(pdu.From) +"[A-Z]$");

        if(!m_connectInfo.ObserverMode || !re.match(m_connectInfo.Callsign).hasMatch())
        {
            AircraftVisualState visualState {};
            visualState.Latitude = pdu.Lat;
            visualState.Longitude = pdu.Lon;
            visualState.Altitude = pdu.TrueAltitude;
            visualState.Pitch = pdu.Pitch;
            visualState.Heading = pdu.Heading;
            visualState.Bank = pdu.Bank;

            emit slowPositionUpdateReceived(pdu.From, visualState, pdu.GroundSpeed);
        }
    }

    void NetworkManager::OnFastPilotPositionReceived(PDUFastPilotPosition pdu)
    {
        AircraftVisualState visualState {};
        visualState.Latitude = pdu.Lat;
        visualState.Longitude = pdu.Lon;
        visualState.Altitude = pdu.Altitude;
        visualState.Pitch = pdu.Pitch;
        visualState.Heading = pdu.Heading;
        visualState.Bank = pdu.Bank;
        visualState.NoseWheelAngle = pdu.NoseWheelAngle;

        VelocityVector positionalVelocityVector {};
        positionalVelocityVector.X = pdu.VelocityLongitude;
        positionalVelocityVector.Y = pdu.VelocityAltitude;
        positionalVelocityVector.Z = pdu.VelocityLatitude;

        VelocityVector rotationalVelocityVector {};
        rotationalVelocityVector.X = pdu.VelocityPitch;
        rotationalVelocityVector.Y = pdu.VelocityHeading;
        rotationalVelocityVector.Z = pdu.VelocityBank;

        emit fastPositionUpdateReceived(pdu.From, visualState, positionalVelocityVector, rotationalVelocityVector);
    }

    void NetworkManager::OnATCPositionReceived(PDUATCPosition pdu)
    {
        emit controllerUpdateReceived(pdu.From, pdu.Frequency, pdu.Lat, pdu.Lon);
    }

    void NetworkManager::OnMetarResponseReceived(PDUMetarResponse pdu)
    {
        emit metarReceived(pdu.From.toUpper(), pdu.Metar);
        m_xplaneAdapter.NotificationPosted(QString("METAR: %1").arg(pdu.Metar), COLOR_BRIGHT_GREEN);
    }

    void NetworkManager::OnDeletePilotReceived(PDUDeletePilot pdu)
    {
        emit pilotDeleted(pdu.From.toUpper());
    }

    void NetworkManager::OnDeleteATCReceived(PDUDeleteATC pdu)
    {
        emit controllerDeleted(pdu.From.toUpper());
    }

    void NetworkManager::OnPingReceived(PDUPing pdu)
    {
        m_fsd.SendPDU(PDUPong(pdu.To, pdu.From, pdu.Timestamp));
    }

    void NetworkManager::OnTextMessageReceived(PDUTextMessage pdu)
    {
        if(pdu.From.toUpper() == "SERVER")
        {
            emit serverMessageReceived(pdu.Message);
            m_xplaneAdapter.NotificationPosted(pdu.Message, COLOR_GREEN);
        }
        else
        {
            emit privateMessageReceived(pdu.From, pdu.Message);
            m_xplaneAdapter.PrivateMessageReceived(pdu.From.toUpper(), pdu.Message);
        }
    }

    void NetworkManager::OnBroadcastMessageReceived(PDUBroadcastMessage pdu)
    {
        emit broadcastMessageReceived(pdu.From.toUpper(), pdu.Message);
    }

    void NetworkManager::OnRadioMessageReceived(PDURadioMessage pdu)
    {
        QList<uint> frequencies;

        for(int i = 0; i < pdu.Frequencies.size(); i++) {

            uint frequency = (uint)pdu.Frequencies[i];

            if(m_radioStackState.Com1ReceiveEnabled && FromNetworkFormat(Normalize25KhzFsdFrequency(frequency)) ==
                    Normalize25KhzFsdFrequency(m_radioStackState.Com1Frequency))
            {
                if(!frequencies.contains(frequency))
                {
                    frequencies.push_back(frequency);
                }
            }
            else if(m_radioStackState.Com2ReceiveEnabled && FromNetworkFormat(Normalize25KhzFsdFrequency(frequency)) ==
                    Normalize25KhzFsdFrequency(m_radioStackState.Com2Frequency))
            {
                if(!frequencies.contains(frequency))
                {
                    frequencies.push_back(frequency);
                }
            }
        }

        if(frequencies.size() == 0) return;

        QRegularExpression re("^SELCAL ([A-Z][A-Z]-?[A-Z][A-Z])$");
        QRegularExpressionMatch match = re.match(pdu.Messages);

        if(match.hasMatch())
        {
            QString selcal = QString("SELCAL %1").arg(match.captured(1).replace("-",""));
            if(!m_connectInfo.SelcalCode.isEmpty() && selcal == "SELCAL " + m_connectInfo.SelcalCode.replace("-",""))
            {
                emit selcalAlertReceived(pdu.From.toUpper(), frequencies);
            }
        }
        else
        {
            bool direct = pdu.Messages.toUpper().startsWith(m_connectInfo.Callsign.toUpper());

            RadioMessageReceived args{};
            args.Frequencies = QVariant::fromValue(frequencies);
            args.From = pdu.From.toUpper();
            args.Message = pdu.Messages;
            args.IsDirect = direct;
            args.DualReceiver = m_radioStackState.Com1ReceiveEnabled && m_radioStackState.Com2ReceiveEnabled;

            emit radioMessageReceived(args);
            m_xplaneAdapter.RadioMessageReceived(pdu.From.toUpper(), pdu.Messages, direct);
        }
    }

    void NetworkManager::OnPlaneInfoRequestReceived(PDUPlaneInfoRequest pdu)
    {
        QRegularExpression re("^([A-Z]{3})\\d+");
        QRegularExpressionMatch match = re.match(m_connectInfo.Callsign);

        m_fsd.SendPDU(PDUPlaneInfoResponse(m_connectInfo.Callsign, pdu.From, m_connectInfo.TypeCode, match.hasMatch() ? match.captured(1)  : "", "", ""));
    }

    void NetworkManager::OnPlaneInfoResponseReceived(PDUPlaneInfoResponse pdu)
    {
        emit aircraftInfoReceived(pdu.From, pdu.Equipment, pdu.Airline);
    }

    void NetworkManager::OnKillRequestReceived(PDUKillRequest pdu)
    {
        m_forcedDisconnect = true;
        m_forcedDisconnectReason = pdu.Reason;
    }

    void NetworkManager::OnSendFastReceived(PDUSendFast pdu)
    {
        if(pdu.To.toUpper() == m_connectInfo.Callsign.toUpper())
        {
            if(pdu.DoSendFast)
            {
                m_fastPositionTimer->start();
            }
            else
            {
                m_fastPositionTimer->stop();
            }
        }
    }

    void NetworkManager::OnUserAircraftDataUpdated(UserAircraftData data)
    {
        if(m_userAircraftData != data)
        {
            m_userAircraftData = data;
        }
    }

    void NetworkManager::OnUserAircraftConfigDataUpdated(UserAircraftConfigData data)
    {
        if(m_userAircraftConfigData != data)
        {
            m_userAircraftConfigData = data;
        }
    }

    void NetworkManager::OnRadioStackStateChanged(RadioStackState radioStack)
    {
        if(m_radioStackState != radioStack)
        {
            m_radioStackState = radioStack;

            m_transmitFreqs.clear();
            if(m_radioStackState.Com1TransmitEnabled)
            {
                m_transmitFreqs.append(Normalize25KhzFsdFrequency(MatchFsdFormat(m_radioStackState.Com1Frequency)));
                if(!m_transmitFreqs.contains(Denormalize25KhzFsdFrequency(MatchFsdFormat(m_radioStackState.Com1Frequency))))
                {
                    m_transmitFreqs.append(Denormalize25KhzFsdFrequency(MatchFsdFormat(m_radioStackState.Com1Frequency)));
                }
            }
            else if(m_radioStackState.Com2TransmitEnabled)
            {
                m_transmitFreqs.append(Normalize25KhzFsdFrequency(MatchFsdFormat(m_radioStackState.Com2Frequency)));
                if(!m_transmitFreqs.contains(Denormalize25KhzFsdFrequency(MatchFsdFormat(m_radioStackState.Com2Frequency))))
                {
                    m_transmitFreqs.append(Denormalize25KhzFsdFrequency(MatchFsdFormat(m_radioStackState.Com2Frequency)));
                }
            }
        }
    }

    void NetworkManager::OnRequestControllerInfo(QString callsign)
    {
        requestControllerAtis(callsign);
    }

    void NetworkManager::SendSlowPositionPacket()
    {
        if(m_connectInfo.ObserverMode) {
            m_fsd.SendPDU(PDUATCPosition(m_connectInfo.Callsign,99998, NetworkFacility::OBS, 40, NetworkRating::OBS,
                                         m_userAircraftData.Latitude, m_userAircraftData.Longitude));
        }
        else {
            m_fsd.SendPDU(PDUPilotPosition(m_connectInfo.Callsign,
                                           m_radioStackState.TransponderCode,
                                           m_radioStackState.SquawkingModeC,
                                           m_radioStackState.SquawkingIdent,
                                           NetworkRating::OBS,
                                           m_userAircraftData.Latitude,
                                           m_userAircraftData.Longitude,
                                           m_userAircraftData.AltitudeMslM * 3.28084,
                                           m_userAircraftData.AltitudePressure,
                                           m_userAircraftData.GroundSpeed,
                                           m_userAircraftData.Pitch,
                                           m_userAircraftData.Heading,
                                           m_userAircraftData.Bank));
        }
    }

    void NetworkManager::SendFastPositionPacket()
    {
        if(AppConfig::getInstance()->VelocityEnabled && !m_connectInfo.ObserverMode)
        {
            m_fsd.SendPDU(PDUFastPilotPosition(m_connectInfo.Callsign,
                                               m_userAircraftData.Latitude,
                                               m_userAircraftData.Longitude,
                                               m_userAircraftData.AltitudeMslM * 3.28084,
                                               m_userAircraftData.Pitch,
                                               m_userAircraftData.Heading,
                                               m_userAircraftData.Bank,
                                               m_userAircraftData.LongitudeVelocity,
                                               m_userAircraftData.AltitudeVelocity,
                                               m_userAircraftData.LatitudeVelocity,
                                               m_userAircraftData.PitchVelocity,
                                               m_userAircraftData.HeadingVelocity,
                                               m_userAircraftData.BankVelocity,
                                               m_userAircraftData.NoseWheelAngle));
        }
    }

    void NetworkManager::SendEmptyFastPositionPacket()
    {
        if(!m_connectInfo.ObserverMode && AppConfig::getInstance()->VelocityEnabled)
        {
            m_fsd.SendPDU(PDUFastPilotPosition(m_connectInfo.Callsign,
                                               m_userAircraftData.Latitude,
                                               m_userAircraftData.Longitude,
                                               m_userAircraftData.AltitudeMslM * 3.28084,
                                               m_userAircraftData.Pitch,
                                               m_userAircraftData.Heading,
                                               m_userAircraftData.Bank,
                                               0.0,
                                               0.0,
                                               0.0,
                                               0.0,
                                               0.0,
                                               0.0,
                                               0.0));
        }
    }

    void NetworkManager::OnSlowPositionTimerElapsed()
    {
        SendSlowPositionPacket();
        SendFastPositionPacket();
    }

    void NetworkManager::OnFastPositionTimerElapsed()
    {
        if(!PositionalVelocityIsZero(m_userAircraftData)) {
            SendFastPositionPacket();
        }
    }

    void NetworkManager::SendAircraftConfigurationUpdate(AircraftConfiguration config)
    {
        SendAircraftConfigurationUpdate("@94836", config);
    }

    void NetworkManager::SendAircraftConfigurationUpdate(QString to, AircraftConfiguration config)
    {
        AircraftConfigurationInfo acconfig{};
        acconfig.Config = config;

        m_fsd.SendPDU(PDUClientQuery(m_connectInfo.Callsign, to, ClientQueryType::AircraftConfiguration, {acconfig.ToJson()}));
    }

    void NetworkManager::SendCapabilities(QString to)
    {
        QStringList caps;
        caps.append("VERSION=1");
        caps.append("ATCINFO=1");
        caps.append("MODELDESC=1");
        caps.append("ACCONFIG=1");
        caps.append("VISUPDATE=1");
        m_fsd.SendPDU(PDUClientQueryResponse(m_connectInfo.Callsign, to, ClientQueryType::Capabilities, caps));
    }

    void NetworkManager::RequestMetar(QString station)
    {
        m_fsd.SendPDU(PDUMetarRequest(m_connectInfo.Callsign, station));
    }

    void NetworkManager::requestRealName(QString callsign)
    {
        m_fsd.SendPDU(PDUClientQuery(m_connectInfo.Callsign, callsign, ClientQueryType::RealName));
    }

    void NetworkManager::requestControllerAtis(QString callsign)
    {
        if(!m_mapAtisMessages.contains(callsign.toUpper()))
        {
            m_mapAtisMessages.insert(callsign.toUpper(), {});
            m_fsd.SendPDU(PDUClientQuery(m_connectInfo.Callsign, callsign, ClientQueryType::ATIS));
        }
    }

    void NetworkManager::requestMetar(QString station)
    {
        m_fsd.SendPDU(PDUMetarRequest(m_connectInfo.Callsign, station));
    }

    void NetworkManager::sendWallop(QString message)
    {
        m_fsd.SendPDU(PDUWallop(m_connectInfo.Callsign, message));
    }

    void NetworkManager::RequestIsValidATC(QString callsign)
    {
        QStringList args;
        args.append(callsign);
        m_fsd.SendPDU(PDUClientQuery(m_connectInfo.Callsign, "SERVER", ClientQueryType::IsValidATC, args));
    }

    void NetworkManager::RequestCapabilities(QString callsign)
    {
        m_fsd.SendPDU(PDUClientQuery(m_connectInfo.Callsign, callsign, ClientQueryType::Capabilities));
    }

    void NetworkManager::SendAircraftInfoRequest(QString callsign)
    {
        m_fsd.SendPDU(PDUPlaneInfoRequest(m_connectInfo.Callsign, callsign));
    }

    void NetworkManager::SendAircraftConfigurationRequest(QString callsign)
    {
        AircraftConfigurationInfo acconfig;
        acconfig.FullRequest = true;

        QStringList args;
        args.append(acconfig.ToJson());

        m_fsd.SendPDU(PDUClientQuery(m_connectInfo.Callsign, callsign, ClientQueryType::AircraftConfiguration, args));
    }

    void NetworkManager::connectToNetwork(QString callsign, QString typeCode, QString selcal, bool observer)
    {
        if(AppConfig::getInstance()->configRequired()) {
            emit notificationPosted((int)NotificationType::Error, "It looks like this may be the first time you've run xPilot on this computer. "
"Some configuration items are required before you can connect to the network. Open Settings and verify your network credentials are saved.");
            return;
        }
        if(!callsign.isEmpty() && !typeCode.isEmpty()) {
            ConnectInfo connectInfo{};
            connectInfo.Callsign = callsign;
            connectInfo.TypeCode = typeCode;
            connectInfo.SelcalCode = selcal;
            connectInfo.ObserverMode = observer;
            m_connectInfo = connectInfo;

            if(AppConfig::getInstance()->VelocityEnabled)
            {
                QStringList serverList{"vps.downstairsgeek.com", "c.downstairsgeek.com"};
                unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
                std::default_random_engine e(seed);
                std::shuffle(serverList.begin(), serverList.end(), e);

                emit notificationPosted((int)NotificationType::Info, "Connecting to network (Velocity Beta)...");
                m_fsd.Connect(serverList.first(), 6809);
            }
            else
            {
                emit notificationPosted((int)NotificationType::Info, "Connecting to network...");
                m_fsd.Connect(AppConfig::getInstance()->getNetworkServer(), 6809);
            }
        }
        else
        {
            emit notificationPosted((int)NotificationType::Error, "Callsign and Type Code are required.");
        }
    }

    void NetworkManager::connectTowerView(QString callsign, QString address)
    {
        if(AppConfig::getInstance()->configRequired()) {
            emit notificationPosted((int)NotificationType::Error, "It looks like this may be the first time you've run xPilot on this computer. "
"Some configuration items are required before you can connect to the network. Open Settings and verify your network credentials are saved.");
            return;
        }
        if(!callsign.isEmpty() && !address.isEmpty())
        {
            ConnectInfo connectInfo{};
            connectInfo.Callsign = callsign;
            connectInfo.TowerViewMode = true;
            m_connectInfo = connectInfo;

            emit notificationPosted((int)NotificationType::Info, "Connecting to TowerView proxy...");
            m_fsd.Connect(address, 6809, false);
        }
    }

    void NetworkManager::disconnectFromNetwork()
    {
        if(!m_fsd.IsConnected())
        {
            return;
        }

        m_intentionalDisconnect = true;
        m_fsd.SendPDU(PDUDeletePilot(m_connectInfo.Callsign, AppConfig::getInstance()->VatsimId));
        m_fsd.Disconnect();
    }

    void NetworkManager::sendRadioMessage(QString message)
    {
        if(m_transmitFreqs.size() > 0) {
            m_fsd.SendPDU(PDURadioMessage(m_connectInfo.Callsign, m_transmitFreqs, message));
            m_xplaneAdapter.SendRadioMessage(message);
        }
    }

    void NetworkManager::sendPrivateMessage(QString to, QString message)
    {
        m_fsd.SendPDU(PDUTextMessage(m_connectInfo.Callsign, to.toUpper(), message));
        m_xplaneAdapter.SendPrivateMessage(to, message);
        emit privateMessageSent(to, message);
    }

    void NetworkManager::OnNetworkError(QString error)
    {
        emit notificationPosted((int)NotificationType::Error, error);
    }

    void NetworkManager::OnProtocolErrorReceived(PDUProtocolError error)
    {
        emit notificationPosted((int)NotificationType::Error, QString("Network Error: %1").arg(error.Message));
    }

    void NetworkManager::OnRawDataSent(QString data)
    {
        m_rawDataStream << QString("[%1] >>> %2").arg(QDateTime::currentDateTimeUtc().toString("HH:mm:ss.zzz"),
                                                      data.replace(AppConfig::getInstance()->VatsimPasswordDecrypted, "********"));
        m_rawDataStream.flush();
    }

    void NetworkManager::OnRawDataReceived(QString data)
    {
        m_rawDataStream << QString("[%1] <<< %2").arg(QDateTime::currentDateTimeUtc().toString("HH:mm:ss.zzz"), data);
        m_rawDataStream.flush();
    }
}
