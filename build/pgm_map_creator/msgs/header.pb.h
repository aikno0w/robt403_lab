// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: header.proto

#ifndef PROTOBUF_INCLUDED_header_2eproto
#define PROTOBUF_INCLUDED_header_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "time.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_header_2eproto 

namespace protobuf_header_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_header_2eproto
namespace gazebo {
namespace msgs {
class Header;
class HeaderDefaultTypeInternal;
extern HeaderDefaultTypeInternal _Header_default_instance_;
}  // namespace msgs
}  // namespace gazebo
namespace google {
namespace protobuf {
template<> ::gazebo::msgs::Header* Arena::CreateMaybeMessage<::gazebo::msgs::Header>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace gazebo {
namespace msgs {

// ===================================================================

class Header : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:gazebo.msgs.Header) */ {
 public:
  Header();
  virtual ~Header();

  Header(const Header& from);

  inline Header& operator=(const Header& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Header(Header&& from) noexcept
    : Header() {
    *this = ::std::move(from);
  }

  inline Header& operator=(Header&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Header& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Header* internal_default_instance() {
    return reinterpret_cast<const Header*>(
               &_Header_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Header* other);
  friend void swap(Header& a, Header& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Header* New() const final {
    return CreateMaybeMessage<Header>(NULL);
  }

  Header* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Header>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Header& from);
  void MergeFrom(const Header& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Header* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string str_id = 1;
  bool has_str_id() const;
  void clear_str_id();
  static const int kStrIdFieldNumber = 1;
  const ::std::string& str_id() const;
  void set_str_id(const ::std::string& value);
  #if LANG_CXX11
  void set_str_id(::std::string&& value);
  #endif
  void set_str_id(const char* value);
  void set_str_id(const char* value, size_t size);
  ::std::string* mutable_str_id();
  ::std::string* release_str_id();
  void set_allocated_str_id(::std::string* str_id);

  // optional .gazebo.msgs.Time stamp = 2;
  bool has_stamp() const;
  void clear_stamp();
  static const int kStampFieldNumber = 2;
  private:
  const ::gazebo::msgs::Time& _internal_stamp() const;
  public:
  const ::gazebo::msgs::Time& stamp() const;
  ::gazebo::msgs::Time* release_stamp();
  ::gazebo::msgs::Time* mutable_stamp();
  void set_allocated_stamp(::gazebo::msgs::Time* stamp);

  // optional int32 index = 3;
  bool has_index() const;
  void clear_index();
  static const int kIndexFieldNumber = 3;
  ::google::protobuf::int32 index() const;
  void set_index(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:gazebo.msgs.Header)
 private:
  void set_has_str_id();
  void clear_has_str_id();
  void set_has_stamp();
  void clear_has_stamp();
  void set_has_index();
  void clear_has_index();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr str_id_;
  ::gazebo::msgs::Time* stamp_;
  ::google::protobuf::int32 index_;
  friend struct ::protobuf_header_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Header

// optional string str_id = 1;
inline bool Header::has_str_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Header::set_has_str_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Header::clear_has_str_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Header::clear_str_id() {
  str_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_str_id();
}
inline const ::std::string& Header::str_id() const {
  // @@protoc_insertion_point(field_get:gazebo.msgs.Header.str_id)
  return str_id_.GetNoArena();
}
inline void Header::set_str_id(const ::std::string& value) {
  set_has_str_id();
  str_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:gazebo.msgs.Header.str_id)
}
#if LANG_CXX11
inline void Header::set_str_id(::std::string&& value) {
  set_has_str_id();
  str_id_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:gazebo.msgs.Header.str_id)
}
#endif
inline void Header::set_str_id(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_str_id();
  str_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:gazebo.msgs.Header.str_id)
}
inline void Header::set_str_id(const char* value, size_t size) {
  set_has_str_id();
  str_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:gazebo.msgs.Header.str_id)
}
inline ::std::string* Header::mutable_str_id() {
  set_has_str_id();
  // @@protoc_insertion_point(field_mutable:gazebo.msgs.Header.str_id)
  return str_id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Header::release_str_id() {
  // @@protoc_insertion_point(field_release:gazebo.msgs.Header.str_id)
  if (!has_str_id()) {
    return NULL;
  }
  clear_has_str_id();
  return str_id_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Header::set_allocated_str_id(::std::string* str_id) {
  if (str_id != NULL) {
    set_has_str_id();
  } else {
    clear_has_str_id();
  }
  str_id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), str_id);
  // @@protoc_insertion_point(field_set_allocated:gazebo.msgs.Header.str_id)
}

// optional .gazebo.msgs.Time stamp = 2;
inline bool Header::has_stamp() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Header::set_has_stamp() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Header::clear_has_stamp() {
  _has_bits_[0] &= ~0x00000002u;
}
inline const ::gazebo::msgs::Time& Header::_internal_stamp() const {
  return *stamp_;
}
inline const ::gazebo::msgs::Time& Header::stamp() const {
  const ::gazebo::msgs::Time* p = stamp_;
  // @@protoc_insertion_point(field_get:gazebo.msgs.Header.stamp)
  return p != NULL ? *p : *reinterpret_cast<const ::gazebo::msgs::Time*>(
      &::gazebo::msgs::_Time_default_instance_);
}
inline ::gazebo::msgs::Time* Header::release_stamp() {
  // @@protoc_insertion_point(field_release:gazebo.msgs.Header.stamp)
  clear_has_stamp();
  ::gazebo::msgs::Time* temp = stamp_;
  stamp_ = NULL;
  return temp;
}
inline ::gazebo::msgs::Time* Header::mutable_stamp() {
  set_has_stamp();
  if (stamp_ == NULL) {
    auto* p = CreateMaybeMessage<::gazebo::msgs::Time>(GetArenaNoVirtual());
    stamp_ = p;
  }
  // @@protoc_insertion_point(field_mutable:gazebo.msgs.Header.stamp)
  return stamp_;
}
inline void Header::set_allocated_stamp(::gazebo::msgs::Time* stamp) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(stamp_);
  }
  if (stamp) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      stamp = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, stamp, submessage_arena);
    }
    set_has_stamp();
  } else {
    clear_has_stamp();
  }
  stamp_ = stamp;
  // @@protoc_insertion_point(field_set_allocated:gazebo.msgs.Header.stamp)
}

// optional int32 index = 3;
inline bool Header::has_index() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Header::set_has_index() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Header::clear_has_index() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Header::clear_index() {
  index_ = 0;
  clear_has_index();
}
inline ::google::protobuf::int32 Header::index() const {
  // @@protoc_insertion_point(field_get:gazebo.msgs.Header.index)
  return index_;
}
inline void Header::set_index(::google::protobuf::int32 value) {
  set_has_index();
  index_ = value;
  // @@protoc_insertion_point(field_set:gazebo.msgs.Header.index)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace msgs
}  // namespace gazebo

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_header_2eproto
