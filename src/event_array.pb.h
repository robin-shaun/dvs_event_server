// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: event_array.proto

#ifndef PROTOBUF_event_5farray_2eproto__INCLUDED
#define PROTOBUF_event_5farray_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace event_array {
namespace protobuf {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_event_5farray_2eproto();
void protobuf_AssignDesc_event_5farray_2eproto();
void protobuf_ShutdownFile_event_5farray_2eproto();

class Event_Array;

// ===================================================================

class Event_Array : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:event_array.protobuf.Event_Array) */ {
 public:
  Event_Array();
  virtual ~Event_Array();

  Event_Array(const Event_Array& from);

  inline Event_Array& operator=(const Event_Array& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Event_Array& default_instance();

  void Swap(Event_Array* other);

  // implements Message ----------------------------------------------

  inline Event_Array* New() const { return New(NULL); }

  Event_Array* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Event_Array& from);
  void MergeFrom(const Event_Array& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Event_Array* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated double timestamp = 1;
  int timestamp_size() const;
  void clear_timestamp();
  static const int kTimestampFieldNumber = 1;
  double timestamp(int index) const;
  void set_timestamp(int index, double value);
  void add_timestamp(double value);
  const ::google::protobuf::RepeatedField< double >&
      timestamp() const;
  ::google::protobuf::RepeatedField< double >*
      mutable_timestamp();

  // repeated int32 x = 2;
  int x_size() const;
  void clear_x();
  static const int kXFieldNumber = 2;
  ::google::protobuf::int32 x(int index) const;
  void set_x(int index, ::google::protobuf::int32 value);
  void add_x(::google::protobuf::int32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      x() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_x();

  // repeated int32 y = 3;
  int y_size() const;
  void clear_y();
  static const int kYFieldNumber = 3;
  ::google::protobuf::int32 y(int index) const;
  void set_y(int index, ::google::protobuf::int32 value);
  void add_y(::google::protobuf::int32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      y() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_y();

  // repeated int32 polarity = 4;
  int polarity_size() const;
  void clear_polarity();
  static const int kPolarityFieldNumber = 4;
  ::google::protobuf::int32 polarity(int index) const;
  void set_polarity(int index, ::google::protobuf::int32 value);
  void add_polarity(::google::protobuf::int32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      polarity() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_polarity();

  // @@protoc_insertion_point(class_scope:event_array.protobuf.Event_Array)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::RepeatedField< double > timestamp_;
  mutable int _timestamp_cached_byte_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > x_;
  mutable int _x_cached_byte_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > y_;
  mutable int _y_cached_byte_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > polarity_;
  mutable int _polarity_cached_byte_size_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_event_5farray_2eproto();
  friend void protobuf_AssignDesc_event_5farray_2eproto();
  friend void protobuf_ShutdownFile_event_5farray_2eproto();

  void InitAsDefaultInstance();
  static Event_Array* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Event_Array

// repeated double timestamp = 1;
inline int Event_Array::timestamp_size() const {
  return timestamp_.size();
}
inline void Event_Array::clear_timestamp() {
  timestamp_.Clear();
}
inline double Event_Array::timestamp(int index) const {
  // @@protoc_insertion_point(field_get:event_array.protobuf.Event_Array.timestamp)
  return timestamp_.Get(index);
}
inline void Event_Array::set_timestamp(int index, double value) {
  timestamp_.Set(index, value);
  // @@protoc_insertion_point(field_set:event_array.protobuf.Event_Array.timestamp)
}
inline void Event_Array::add_timestamp(double value) {
  timestamp_.Add(value);
  // @@protoc_insertion_point(field_add:event_array.protobuf.Event_Array.timestamp)
}
inline const ::google::protobuf::RepeatedField< double >&
Event_Array::timestamp() const {
  // @@protoc_insertion_point(field_list:event_array.protobuf.Event_Array.timestamp)
  return timestamp_;
}
inline ::google::protobuf::RepeatedField< double >*
Event_Array::mutable_timestamp() {
  // @@protoc_insertion_point(field_mutable_list:event_array.protobuf.Event_Array.timestamp)
  return &timestamp_;
}

// repeated int32 x = 2;
inline int Event_Array::x_size() const {
  return x_.size();
}
inline void Event_Array::clear_x() {
  x_.Clear();
}
inline ::google::protobuf::int32 Event_Array::x(int index) const {
  // @@protoc_insertion_point(field_get:event_array.protobuf.Event_Array.x)
  return x_.Get(index);
}
inline void Event_Array::set_x(int index, ::google::protobuf::int32 value) {
  x_.Set(index, value);
  // @@protoc_insertion_point(field_set:event_array.protobuf.Event_Array.x)
}
inline void Event_Array::add_x(::google::protobuf::int32 value) {
  x_.Add(value);
  // @@protoc_insertion_point(field_add:event_array.protobuf.Event_Array.x)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
Event_Array::x() const {
  // @@protoc_insertion_point(field_list:event_array.protobuf.Event_Array.x)
  return x_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
Event_Array::mutable_x() {
  // @@protoc_insertion_point(field_mutable_list:event_array.protobuf.Event_Array.x)
  return &x_;
}

// repeated int32 y = 3;
inline int Event_Array::y_size() const {
  return y_.size();
}
inline void Event_Array::clear_y() {
  y_.Clear();
}
inline ::google::protobuf::int32 Event_Array::y(int index) const {
  // @@protoc_insertion_point(field_get:event_array.protobuf.Event_Array.y)
  return y_.Get(index);
}
inline void Event_Array::set_y(int index, ::google::protobuf::int32 value) {
  y_.Set(index, value);
  // @@protoc_insertion_point(field_set:event_array.protobuf.Event_Array.y)
}
inline void Event_Array::add_y(::google::protobuf::int32 value) {
  y_.Add(value);
  // @@protoc_insertion_point(field_add:event_array.protobuf.Event_Array.y)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
Event_Array::y() const {
  // @@protoc_insertion_point(field_list:event_array.protobuf.Event_Array.y)
  return y_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
Event_Array::mutable_y() {
  // @@protoc_insertion_point(field_mutable_list:event_array.protobuf.Event_Array.y)
  return &y_;
}

// repeated int32 polarity = 4;
inline int Event_Array::polarity_size() const {
  return polarity_.size();
}
inline void Event_Array::clear_polarity() {
  polarity_.Clear();
}
inline ::google::protobuf::int32 Event_Array::polarity(int index) const {
  // @@protoc_insertion_point(field_get:event_array.protobuf.Event_Array.polarity)
  return polarity_.Get(index);
}
inline void Event_Array::set_polarity(int index, ::google::protobuf::int32 value) {
  polarity_.Set(index, value);
  // @@protoc_insertion_point(field_set:event_array.protobuf.Event_Array.polarity)
}
inline void Event_Array::add_polarity(::google::protobuf::int32 value) {
  polarity_.Add(value);
  // @@protoc_insertion_point(field_add:event_array.protobuf.Event_Array.polarity)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
Event_Array::polarity() const {
  // @@protoc_insertion_point(field_list:event_array.protobuf.Event_Array.polarity)
  return polarity_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
Event_Array::mutable_polarity() {
  // @@protoc_insertion_point(field_mutable_list:event_array.protobuf.Event_Array.polarity)
  return &polarity_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf
}  // namespace event_array

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_event_5farray_2eproto__INCLUDED
