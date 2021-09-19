// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MarkAsRead.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_MarkAsRead_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_MarkAsRead_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_MarkAsRead_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_MarkAsRead_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_MarkAsRead_2eproto;
namespace xpilot {
class MarkAsRead;
struct MarkAsReadDefaultTypeInternal;
extern MarkAsReadDefaultTypeInternal _MarkAsRead_default_instance_;
}  // namespace xpilot
PROTOBUF_NAMESPACE_OPEN
template<> ::xpilot::MarkAsRead* Arena::CreateMaybeMessage<::xpilot::MarkAsRead>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace xpilot {

// ===================================================================

class MarkAsRead final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:xpilot.MarkAsRead) */ {
 public:
  inline MarkAsRead() : MarkAsRead(nullptr) {}
  ~MarkAsRead() override;
  explicit constexpr MarkAsRead(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  MarkAsRead(const MarkAsRead& from);
  MarkAsRead(MarkAsRead&& from) noexcept
    : MarkAsRead() {
    *this = ::std::move(from);
  }

  inline MarkAsRead& operator=(const MarkAsRead& from) {
    CopyFrom(from);
    return *this;
  }
  inline MarkAsRead& operator=(MarkAsRead&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const MarkAsRead& default_instance() {
    return *internal_default_instance();
  }
  static inline const MarkAsRead* internal_default_instance() {
    return reinterpret_cast<const MarkAsRead*>(
               &_MarkAsRead_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(MarkAsRead& a, MarkAsRead& b) {
    a.Swap(&b);
  }
  inline void Swap(MarkAsRead* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(MarkAsRead* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline MarkAsRead* New() const final {
    return new MarkAsRead();
  }

  MarkAsRead* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<MarkAsRead>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const MarkAsRead& from);
  void MergeFrom(const MarkAsRead& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MarkAsRead* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "xpilot.MarkAsRead";
  }
  protected:
  explicit MarkAsRead(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTabNameFieldNumber = 1,
  };
  // optional string tab_name = 1;
  bool has_tab_name() const;
  private:
  bool _internal_has_tab_name() const;
  public:
  void clear_tab_name();
  const std::string& tab_name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_tab_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_tab_name();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_tab_name();
  void set_allocated_tab_name(std::string* tab_name);
  private:
  const std::string& _internal_tab_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_tab_name(const std::string& value);
  std::string* _internal_mutable_tab_name();
  public:

  // @@protoc_insertion_point(class_scope:xpilot.MarkAsRead)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr tab_name_;
  friend struct ::TableStruct_MarkAsRead_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MarkAsRead

// optional string tab_name = 1;
inline bool MarkAsRead::_internal_has_tab_name() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool MarkAsRead::has_tab_name() const {
  return _internal_has_tab_name();
}
inline void MarkAsRead::clear_tab_name() {
  tab_name_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& MarkAsRead::tab_name() const {
  // @@protoc_insertion_point(field_get:xpilot.MarkAsRead.tab_name)
  return _internal_tab_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void MarkAsRead::set_tab_name(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 tab_name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:xpilot.MarkAsRead.tab_name)
}
inline std::string* MarkAsRead::mutable_tab_name() {
  // @@protoc_insertion_point(field_mutable:xpilot.MarkAsRead.tab_name)
  return _internal_mutable_tab_name();
}
inline const std::string& MarkAsRead::_internal_tab_name() const {
  return tab_name_.Get();
}
inline void MarkAsRead::_internal_set_tab_name(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  tab_name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* MarkAsRead::_internal_mutable_tab_name() {
  _has_bits_[0] |= 0x00000001u;
  return tab_name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* MarkAsRead::release_tab_name() {
  // @@protoc_insertion_point(field_release:xpilot.MarkAsRead.tab_name)
  if (!_internal_has_tab_name()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return tab_name_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void MarkAsRead::set_allocated_tab_name(std::string* tab_name) {
  if (tab_name != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  tab_name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), tab_name,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:xpilot.MarkAsRead.tab_name)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace xpilot

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_MarkAsRead_2eproto
