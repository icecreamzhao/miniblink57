// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: user_action_event.proto

#ifndef PROTOBUF_user_5faction_5fevent_2eproto__INCLUDED
#define PROTOBUF_user_5faction_5fevent_2eproto__INCLUDED

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
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>
// @@protoc_insertion_point(includes)

namespace metrics {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_user_5faction_5fevent_2eproto();
void protobuf_AssignDesc_user_5faction_5fevent_2eproto();
void protobuf_ShutdownFile_user_5faction_5fevent_2eproto();

class UserActionEventProto;

// ===================================================================

class UserActionEventProto : public ::google::protobuf::MessageLite {
public:
    UserActionEventProto();
    virtual ~UserActionEventProto();

    UserActionEventProto(const UserActionEventProto& from);

    inline UserActionEventProto& operator=(const UserActionEventProto& from)
    {
        CopyFrom(from);
        return *this;
    }

    inline const ::std::string& unknown_fields() const
    {
        return _unknown_fields_.GetNoArena(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    }

    inline ::std::string* mutable_unknown_fields()
    {
        return _unknown_fields_.MutableNoArena(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    }

    static const UserActionEventProto& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    // Returns the internal default instance pointer. This function can
    // return NULL thus should not be used by the user. This is intended
    // for Protobuf internal code. Please use default_instance() declared
    // above instead.
    static inline const UserActionEventProto* internal_default_instance()
    {
        return default_instance_;
    }
#endif

    GOOGLE_ATTRIBUTE_NOINLINE void Swap(UserActionEventProto* other);

    // implements Message ----------------------------------------------

    inline UserActionEventProto* New() const { return New(NULL); }

    UserActionEventProto* New(::google::protobuf::Arena* arena) const;
    void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
    void CopyFrom(const UserActionEventProto& from);
    void MergeFrom(const UserActionEventProto& from);
    void Clear();
    bool IsInitialized() const;

    int ByteSize() const;
    bool MergePartialFromCodedStream(
        ::google::protobuf::io::CodedInputStream* input);
    void SerializeWithCachedSizes(
        ::google::protobuf::io::CodedOutputStream* output) const;
    void DiscardUnknownFields();
    int GetCachedSize() const { return _cached_size_; }

private:
    void SharedCtor();
    void SharedDtor();
    void SetCachedSize(int size) const;
    void InternalSwap(UserActionEventProto* other);

private:
    inline ::google::protobuf::Arena* GetArenaNoVirtual() const
    {
        return _arena_ptr_;
    }
    inline ::google::protobuf::Arena* MaybeArenaPtr() const
    {
        return _arena_ptr_;
    }

public:
    ::std::string GetTypeName() const;

    // nested types ----------------------------------------------------

    // accessors -------------------------------------------------------

    // optional fixed64 name_hash = 1;
    bool has_name_hash() const;
    void clear_name_hash();
    static const int kNameHashFieldNumber = 1;
    ::google::protobuf::uint64 name_hash() const;
    void set_name_hash(::google::protobuf::uint64 value);

    // optional int64 time = 2;
    bool has_time() const;
    void clear_time();
    static const int kTimeFieldNumber = 2;
    ::google::protobuf::int64 time() const;
    void set_time(::google::protobuf::int64 value);

    // @@protoc_insertion_point(class_scope:metrics.UserActionEventProto)
private:
    inline void set_has_name_hash();
    inline void clear_has_name_hash();
    inline void set_has_time();
    inline void clear_has_time();

    ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
    ::google::protobuf::Arena* _arena_ptr_;

    ::google::protobuf::uint32 _has_bits_[1];
    mutable int _cached_size_;
    ::google::protobuf::uint64 name_hash_;
    ::google::protobuf::int64 time_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    friend void protobuf_AddDesc_user_5faction_5fevent_2eproto_impl();
#else
    friend void protobuf_AddDesc_user_5faction_5fevent_2eproto();
#endif
    friend void protobuf_AssignDesc_user_5faction_5fevent_2eproto();
    friend void protobuf_ShutdownFile_user_5faction_5fevent_2eproto();

    void InitAsDefaultInstance();
    static UserActionEventProto* default_instance_;
};
// ===================================================================

// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// UserActionEventProto

// optional fixed64 name_hash = 1;
inline bool UserActionEventProto::has_name_hash() const
{
    return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void UserActionEventProto::set_has_name_hash()
{
    _has_bits_[0] |= 0x00000001u;
}
inline void UserActionEventProto::clear_has_name_hash()
{
    _has_bits_[0] &= ~0x00000001u;
}
inline void UserActionEventProto::clear_name_hash()
{
    name_hash_ = GOOGLE_ULONGLONG(0);
    clear_has_name_hash();
}
inline ::google::protobuf::uint64 UserActionEventProto::name_hash() const
{
    // @@protoc_insertion_point(field_get:metrics.UserActionEventProto.name_hash)
    return name_hash_;
}
inline void UserActionEventProto::set_name_hash(::google::protobuf::uint64 value)
{
    set_has_name_hash();
    name_hash_ = value;
    // @@protoc_insertion_point(field_set:metrics.UserActionEventProto.name_hash)
}

// optional int64 time = 2;
inline bool UserActionEventProto::has_time() const
{
    return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void UserActionEventProto::set_has_time()
{
    _has_bits_[0] |= 0x00000002u;
}
inline void UserActionEventProto::clear_has_time()
{
    _has_bits_[0] &= ~0x00000002u;
}
inline void UserActionEventProto::clear_time()
{
    time_ = GOOGLE_LONGLONG(0);
    clear_has_time();
}
inline ::google::protobuf::int64 UserActionEventProto::time() const
{
    // @@protoc_insertion_point(field_get:metrics.UserActionEventProto.time)
    return time_;
}
inline void UserActionEventProto::set_time(::google::protobuf::int64 value)
{
    set_has_time();
    time_ = value;
    // @@protoc_insertion_point(field_set:metrics.UserActionEventProto.time)
}

#endif // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

} // namespace metrics

// @@protoc_insertion_point(global_scope)

#endif // PROTOBUF_user_5faction_5fevent_2eproto__INCLUDED
