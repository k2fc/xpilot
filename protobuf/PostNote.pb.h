// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PostNote.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_PostNote_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_PostNote_2eproto

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
#include <google/protobuf/timestamp.pb.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_PostNote_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_PostNote_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_PostNote_2eproto;
namespace xpilot {
class PostNote;
struct PostNoteDefaultTypeInternal;
extern PostNoteDefaultTypeInternal _PostNote_default_instance_;
}  // namespace xpilot
PROTOBUF_NAMESPACE_OPEN
template<> ::xpilot::PostNote* Arena::CreateMaybeMessage<::xpilot::PostNote>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace xpilot {

// ===================================================================

class PostNote final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:xpilot.PostNote) */ {
 public:
  inline PostNote() : PostNote(nullptr) {}
  ~PostNote() override;
  explicit constexpr PostNote(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PostNote(const PostNote& from);
  PostNote(PostNote&& from) noexcept
    : PostNote() {
    *this = ::std::move(from);
  }

  inline PostNote& operator=(const PostNote& from) {
    CopyFrom(from);
    return *this;
  }
  inline PostNote& operator=(PostNote&& from) noexcept {
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
  static const PostNote& default_instance() {
    return *internal_default_instance();
  }
  static inline const PostNote* internal_default_instance() {
    return reinterpret_cast<const PostNote*>(
               &_PostNote_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PostNote& a, PostNote& b) {
    a.Swap(&b);
  }
  inline void Swap(PostNote* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PostNote* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline PostNote* New() const final {
    return new PostNote();
  }

  PostNote* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<PostNote>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const PostNote& from);
  void MergeFrom(const PostNote& from);
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
  void InternalSwap(PostNote* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "xpilot.PostNote";
  }
  protected:
  explicit PostNote(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMessageFieldNumber = 2,
    kTimestampFieldNumber = 1,
  };
  // optional string message = 2;
  bool has_message() const;
  private:
  bool _internal_has_message() const;
  public:
  void clear_message();
  const std::string& message() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_message(ArgT0&& arg0, ArgT... args);
  std::string* mutable_message();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_message();
  void set_allocated_message(std::string* message);
  private:
  const std::string& _internal_message() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_message(const std::string& value);
  std::string* _internal_mutable_message();
  public:

  // .google.protobuf.Timestamp timestamp = 1;
  bool has_timestamp() const;
  private:
  bool _internal_has_timestamp() const;
  public:
  void clear_timestamp();
  const PROTOBUF_NAMESPACE_ID::Timestamp& timestamp() const;
  PROTOBUF_FUTURE_MUST_USE_RESULT PROTOBUF_NAMESPACE_ID::Timestamp* release_timestamp();
  PROTOBUF_NAMESPACE_ID::Timestamp* mutable_timestamp();
  void set_allocated_timestamp(PROTOBUF_NAMESPACE_ID::Timestamp* timestamp);
  private:
  const PROTOBUF_NAMESPACE_ID::Timestamp& _internal_timestamp() const;
  PROTOBUF_NAMESPACE_ID::Timestamp* _internal_mutable_timestamp();
  public:
  void unsafe_arena_set_allocated_timestamp(
      PROTOBUF_NAMESPACE_ID::Timestamp* timestamp);
  PROTOBUF_NAMESPACE_ID::Timestamp* unsafe_arena_release_timestamp();

  // @@protoc_insertion_point(class_scope:xpilot.PostNote)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr message_;
  PROTOBUF_NAMESPACE_ID::Timestamp* timestamp_;
  friend struct ::TableStruct_PostNote_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PostNote

// .google.protobuf.Timestamp timestamp = 1;
inline bool PostNote::_internal_has_timestamp() const {
  return this != internal_default_instance() && timestamp_ != nullptr;
}
inline bool PostNote::has_timestamp() const {
  return _internal_has_timestamp();
}
inline const PROTOBUF_NAMESPACE_ID::Timestamp& PostNote::_internal_timestamp() const {
  const PROTOBUF_NAMESPACE_ID::Timestamp* p = timestamp_;
  return p != nullptr ? *p : reinterpret_cast<const PROTOBUF_NAMESPACE_ID::Timestamp&>(
      PROTOBUF_NAMESPACE_ID::_Timestamp_default_instance_);
}
inline const PROTOBUF_NAMESPACE_ID::Timestamp& PostNote::timestamp() const {
  // @@protoc_insertion_point(field_get:xpilot.PostNote.timestamp)
  return _internal_timestamp();
}
inline void PostNote::unsafe_arena_set_allocated_timestamp(
    PROTOBUF_NAMESPACE_ID::Timestamp* timestamp) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(timestamp_);
  }
  timestamp_ = timestamp;
  if (timestamp) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:xpilot.PostNote.timestamp)
}
inline PROTOBUF_NAMESPACE_ID::Timestamp* PostNote::release_timestamp() {
  
  PROTOBUF_NAMESPACE_ID::Timestamp* temp = timestamp_;
  timestamp_ = nullptr;
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline PROTOBUF_NAMESPACE_ID::Timestamp* PostNote::unsafe_arena_release_timestamp() {
  // @@protoc_insertion_point(field_release:xpilot.PostNote.timestamp)
  
  PROTOBUF_NAMESPACE_ID::Timestamp* temp = timestamp_;
  timestamp_ = nullptr;
  return temp;
}
inline PROTOBUF_NAMESPACE_ID::Timestamp* PostNote::_internal_mutable_timestamp() {
  
  if (timestamp_ == nullptr) {
    auto* p = CreateMaybeMessage<PROTOBUF_NAMESPACE_ID::Timestamp>(GetArenaForAllocation());
    timestamp_ = p;
  }
  return timestamp_;
}
inline PROTOBUF_NAMESPACE_ID::Timestamp* PostNote::mutable_timestamp() {
  // @@protoc_insertion_point(field_mutable:xpilot.PostNote.timestamp)
  return _internal_mutable_timestamp();
}
inline void PostNote::set_allocated_timestamp(PROTOBUF_NAMESPACE_ID::Timestamp* timestamp) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(timestamp_);
  }
  if (timestamp) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<
            ::PROTOBUF_NAMESPACE_ID::MessageLite>::GetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(timestamp));
    if (message_arena != submessage_arena) {
      timestamp = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, timestamp, submessage_arena);
    }
    
  } else {
    
  }
  timestamp_ = timestamp;
  // @@protoc_insertion_point(field_set_allocated:xpilot.PostNote.timestamp)
}

// optional string message = 2;
inline bool PostNote::_internal_has_message() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool PostNote::has_message() const {
  return _internal_has_message();
}
inline void PostNote::clear_message() {
  message_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& PostNote::message() const {
  // @@protoc_insertion_point(field_get:xpilot.PostNote.message)
  return _internal_message();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void PostNote::set_message(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 message_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:xpilot.PostNote.message)
}
inline std::string* PostNote::mutable_message() {
  // @@protoc_insertion_point(field_mutable:xpilot.PostNote.message)
  return _internal_mutable_message();
}
inline const std::string& PostNote::_internal_message() const {
  return message_.Get();
}
inline void PostNote::_internal_set_message(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  message_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* PostNote::_internal_mutable_message() {
  _has_bits_[0] |= 0x00000001u;
  return message_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* PostNote::release_message() {
  // @@protoc_insertion_point(field_release:xpilot.PostNote.message)
  if (!_internal_has_message()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return message_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void PostNote::set_allocated_message(std::string* message) {
  if (message != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  message_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), message,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:xpilot.PostNote.message)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace xpilot

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_PostNote_2eproto
