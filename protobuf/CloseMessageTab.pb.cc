// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CloseMessageTab.proto

#include "CloseMessageTab.pb.h"

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
constexpr CloseMessageTab::CloseMessageTab(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : tab_name_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct CloseMessageTabDefaultTypeInternal {
  constexpr CloseMessageTabDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~CloseMessageTabDefaultTypeInternal() {}
  union {
    CloseMessageTab _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT CloseMessageTabDefaultTypeInternal _CloseMessageTab_default_instance_;
}  // namespace xpilot
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_CloseMessageTab_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_CloseMessageTab_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_CloseMessageTab_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_CloseMessageTab_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::xpilot::CloseMessageTab, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::xpilot::CloseMessageTab, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::xpilot::CloseMessageTab, tab_name_),
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 6, sizeof(::xpilot::CloseMessageTab)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::xpilot::_CloseMessageTab_default_instance_),
};

const char descriptor_table_protodef_CloseMessageTab_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\025CloseMessageTab.proto\022\006xpilot\"5\n\017Close"
  "MessageTab\022\025\n\010tab_name\030\001 \001(\tH\000\210\001\001B\013\n\t_ta"
  "b_nameB\031\252\002\026Vatsim.Xpilot.Protobufb\006proto"
  "3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_CloseMessageTab_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_CloseMessageTab_2eproto = {
  false, false, 121, descriptor_table_protodef_CloseMessageTab_2eproto, "CloseMessageTab.proto", 
  &descriptor_table_CloseMessageTab_2eproto_once, nullptr, 0, 1,
  schemas, file_default_instances, TableStruct_CloseMessageTab_2eproto::offsets,
  file_level_metadata_CloseMessageTab_2eproto, file_level_enum_descriptors_CloseMessageTab_2eproto, file_level_service_descriptors_CloseMessageTab_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_CloseMessageTab_2eproto_getter() {
  return &descriptor_table_CloseMessageTab_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_CloseMessageTab_2eproto(&descriptor_table_CloseMessageTab_2eproto);
namespace xpilot {

// ===================================================================

class CloseMessageTab::_Internal {
 public:
  using HasBits = decltype(std::declval<CloseMessageTab>()._has_bits_);
  static void set_has_tab_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

CloseMessageTab::CloseMessageTab(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:xpilot.CloseMessageTab)
}
CloseMessageTab::CloseMessageTab(const CloseMessageTab& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  tab_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_tab_name()) {
    tab_name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_tab_name(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:xpilot.CloseMessageTab)
}

void CloseMessageTab::SharedCtor() {
tab_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

CloseMessageTab::~CloseMessageTab() {
  // @@protoc_insertion_point(destructor:xpilot.CloseMessageTab)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void CloseMessageTab::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  tab_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void CloseMessageTab::ArenaDtor(void* object) {
  CloseMessageTab* _this = reinterpret_cast< CloseMessageTab* >(object);
  (void)_this;
}
void CloseMessageTab::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void CloseMessageTab::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void CloseMessageTab::Clear() {
// @@protoc_insertion_point(message_clear_start:xpilot.CloseMessageTab)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    tab_name_.ClearNonDefaultToEmpty();
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CloseMessageTab::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // optional string tab_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_tab_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "xpilot.CloseMessageTab.tab_name"));
          CHK_(ptr);
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
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* CloseMessageTab::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:xpilot.CloseMessageTab)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // optional string tab_name = 1;
  if (_internal_has_tab_name()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_tab_name().data(), static_cast<int>(this->_internal_tab_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "xpilot.CloseMessageTab.tab_name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_tab_name(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:xpilot.CloseMessageTab)
  return target;
}

size_t CloseMessageTab::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:xpilot.CloseMessageTab)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional string tab_name = 1;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_tab_name());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CloseMessageTab::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:xpilot.CloseMessageTab)
  GOOGLE_DCHECK_NE(&from, this);
  const CloseMessageTab* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<CloseMessageTab>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:xpilot.CloseMessageTab)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:xpilot.CloseMessageTab)
    MergeFrom(*source);
  }
}

void CloseMessageTab::MergeFrom(const CloseMessageTab& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:xpilot.CloseMessageTab)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_tab_name()) {
    _internal_set_tab_name(from._internal_tab_name());
  }
}

void CloseMessageTab::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:xpilot.CloseMessageTab)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CloseMessageTab::CopyFrom(const CloseMessageTab& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:xpilot.CloseMessageTab)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CloseMessageTab::IsInitialized() const {
  return true;
}

void CloseMessageTab::InternalSwap(CloseMessageTab* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &tab_name_, GetArenaForAllocation(),
      &other->tab_name_, other->GetArenaForAllocation()
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata CloseMessageTab::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_CloseMessageTab_2eproto_getter, &descriptor_table_CloseMessageTab_2eproto_once,
      file_level_metadata_CloseMessageTab_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace xpilot
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::xpilot::CloseMessageTab* Arena::CreateMaybeMessage< ::xpilot::CloseMessageTab >(Arena* arena) {
  return Arena::CreateMessageInternal< ::xpilot::CloseMessageTab >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
