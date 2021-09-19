// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SelcalAlertReceived.proto

#include "SelcalAlertReceived.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace xpilot {
constexpr SelcalAlertReceived::SelcalAlertReceived(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : frequencies_()
  , timestamp_(nullptr){}
struct SelcalAlertReceivedDefaultTypeInternal {
  constexpr SelcalAlertReceivedDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~SelcalAlertReceivedDefaultTypeInternal() {}
  union {
    SelcalAlertReceived _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT SelcalAlertReceivedDefaultTypeInternal _SelcalAlertReceived_default_instance_;
}  // namespace xpilot
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_SelcalAlertReceived_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_SelcalAlertReceived_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_SelcalAlertReceived_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_SelcalAlertReceived_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::xpilot::SelcalAlertReceived, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::xpilot::SelcalAlertReceived, timestamp_),
  PROTOBUF_FIELD_OFFSET(::xpilot::SelcalAlertReceived, frequencies_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::xpilot::SelcalAlertReceived)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::xpilot::_SelcalAlertReceived_default_instance_),
};

const char descriptor_table_protodef_SelcalAlertReceived_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\031SelcalAlertReceived.proto\022\006xpilot\032\037goo"
  "gle/protobuf/timestamp.proto\"Y\n\023SelcalAl"
  "ertReceived\022-\n\ttimestamp\030\001 \001(\0132\032.google."
  "protobuf.Timestamp\022\023\n\013frequencies\030\002 \003(\tB"
  "\031\252\002\026Vatsim.Xpilot.Protobufb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_SelcalAlertReceived_2eproto_deps[1] = {
  &::descriptor_table_google_2fprotobuf_2ftimestamp_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_SelcalAlertReceived_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_SelcalAlertReceived_2eproto = {
  false, false, 194, descriptor_table_protodef_SelcalAlertReceived_2eproto, "SelcalAlertReceived.proto", 
  &descriptor_table_SelcalAlertReceived_2eproto_once, descriptor_table_SelcalAlertReceived_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_SelcalAlertReceived_2eproto::offsets,
  file_level_metadata_SelcalAlertReceived_2eproto, file_level_enum_descriptors_SelcalAlertReceived_2eproto, file_level_service_descriptors_SelcalAlertReceived_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_SelcalAlertReceived_2eproto_getter() {
  return &descriptor_table_SelcalAlertReceived_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_SelcalAlertReceived_2eproto(&descriptor_table_SelcalAlertReceived_2eproto);
namespace xpilot {

// ===================================================================

class SelcalAlertReceived::_Internal {
 public:
  static const PROTOBUF_NAMESPACE_ID::Timestamp& timestamp(const SelcalAlertReceived* msg);
};

const PROTOBUF_NAMESPACE_ID::Timestamp&
SelcalAlertReceived::_Internal::timestamp(const SelcalAlertReceived* msg) {
  return *msg->timestamp_;
}
void SelcalAlertReceived::clear_timestamp() {
  if (GetArenaForAllocation() == nullptr && timestamp_ != nullptr) {
    delete timestamp_;
  }
  timestamp_ = nullptr;
}
SelcalAlertReceived::SelcalAlertReceived(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  frequencies_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:xpilot.SelcalAlertReceived)
}
SelcalAlertReceived::SelcalAlertReceived(const SelcalAlertReceived& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      frequencies_(from.frequencies_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_timestamp()) {
    timestamp_ = new PROTOBUF_NAMESPACE_ID::Timestamp(*from.timestamp_);
  } else {
    timestamp_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:xpilot.SelcalAlertReceived)
}

void SelcalAlertReceived::SharedCtor() {
timestamp_ = nullptr;
}

SelcalAlertReceived::~SelcalAlertReceived() {
  // @@protoc_insertion_point(destructor:xpilot.SelcalAlertReceived)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void SelcalAlertReceived::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete timestamp_;
}

void SelcalAlertReceived::ArenaDtor(void* object) {
  SelcalAlertReceived* _this = reinterpret_cast< SelcalAlertReceived* >(object);
  (void)_this;
}
void SelcalAlertReceived::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void SelcalAlertReceived::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void SelcalAlertReceived::Clear() {
// @@protoc_insertion_point(message_clear_start:xpilot.SelcalAlertReceived)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  frequencies_.Clear();
  if (GetArenaForAllocation() == nullptr && timestamp_ != nullptr) {
    delete timestamp_;
  }
  timestamp_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* SelcalAlertReceived::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .google.protobuf.Timestamp timestamp = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_timestamp(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated string frequencies = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_frequencies();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "xpilot.SelcalAlertReceived.frequencies"));
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* SelcalAlertReceived::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:xpilot.SelcalAlertReceived)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .google.protobuf.Timestamp timestamp = 1;
  if (this->has_timestamp()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::timestamp(this), target, stream);
  }

  // repeated string frequencies = 2;
  for (int i = 0, n = this->_internal_frequencies_size(); i < n; i++) {
    const auto& s = this->_internal_frequencies(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      s.data(), static_cast<int>(s.length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "xpilot.SelcalAlertReceived.frequencies");
    target = stream->WriteString(2, s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:xpilot.SelcalAlertReceived)
  return target;
}

size_t SelcalAlertReceived::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:xpilot.SelcalAlertReceived)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated string frequencies = 2;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(frequencies_.size());
  for (int i = 0, n = frequencies_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      frequencies_.Get(i));
  }

  // .google.protobuf.Timestamp timestamp = 1;
  if (this->has_timestamp()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *timestamp_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void SelcalAlertReceived::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:xpilot.SelcalAlertReceived)
  GOOGLE_DCHECK_NE(&from, this);
  const SelcalAlertReceived* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<SelcalAlertReceived>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:xpilot.SelcalAlertReceived)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:xpilot.SelcalAlertReceived)
    MergeFrom(*source);
  }
}

void SelcalAlertReceived::MergeFrom(const SelcalAlertReceived& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:xpilot.SelcalAlertReceived)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  frequencies_.MergeFrom(from.frequencies_);
  if (from.has_timestamp()) {
    _internal_mutable_timestamp()->PROTOBUF_NAMESPACE_ID::Timestamp::MergeFrom(from._internal_timestamp());
  }
}

void SelcalAlertReceived::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:xpilot.SelcalAlertReceived)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SelcalAlertReceived::CopyFrom(const SelcalAlertReceived& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:xpilot.SelcalAlertReceived)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SelcalAlertReceived::IsInitialized() const {
  return true;
}

void SelcalAlertReceived::InternalSwap(SelcalAlertReceived* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  frequencies_.InternalSwap(&other->frequencies_);
  swap(timestamp_, other->timestamp_);
}

::PROTOBUF_NAMESPACE_ID::Metadata SelcalAlertReceived::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_SelcalAlertReceived_2eproto_getter, &descriptor_table_SelcalAlertReceived_2eproto_once,
      file_level_metadata_SelcalAlertReceived_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace xpilot
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::xpilot::SelcalAlertReceived* Arena::CreateMaybeMessage< ::xpilot::SelcalAlertReceived >(Arena* arena) {
  return Arena::CreateMessageInternal< ::xpilot::SelcalAlertReceived >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>