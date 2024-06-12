// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: theme_specifics.proto

#ifndef PROTOBUF_theme_5fspecifics_2eproto__INCLUDED
#define PROTOBUF_theme_5fspecifics_2eproto__INCLUDED

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

namespace sync_pb {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_theme_5fspecifics_2eproto();
void protobuf_AssignDesc_theme_5fspecifics_2eproto();
void protobuf_ShutdownFile_theme_5fspecifics_2eproto();

class ThemeSpecifics;

// ===================================================================

class ThemeSpecifics : public ::google::protobuf::MessageLite {
public:
    ThemeSpecifics();
    virtual ~ThemeSpecifics();

    ThemeSpecifics(const ThemeSpecifics& from);

    inline ThemeSpecifics& operator=(const ThemeSpecifics& from)
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

    static const ThemeSpecifics& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    // Returns the internal default instance pointer. This function can
    // return NULL thus should not be used by the user. This is intended
    // for Protobuf internal code. Please use default_instance() declared
    // above instead.
    static inline const ThemeSpecifics* internal_default_instance()
    {
        return default_instance_;
    }
#endif

    GOOGLE_ATTRIBUTE_NOINLINE void Swap(ThemeSpecifics* other);

    // implements Message ----------------------------------------------

    inline ThemeSpecifics* New() const { return New(NULL); }

    ThemeSpecifics* New(::google::protobuf::Arena* arena) const;
    void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
    void CopyFrom(const ThemeSpecifics& from);
    void MergeFrom(const ThemeSpecifics& from);
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
    void InternalSwap(ThemeSpecifics* other);

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

    // optional bool use_custom_theme = 1;
    bool has_use_custom_theme() const;
    void clear_use_custom_theme();
    static const int kUseCustomThemeFieldNumber = 1;
    bool use_custom_theme() const;
    void set_use_custom_theme(bool value);

    // optional bool use_system_theme_by_default = 2;
    bool has_use_system_theme_by_default() const;
    void clear_use_system_theme_by_default();
    static const int kUseSystemThemeByDefaultFieldNumber = 2;
    bool use_system_theme_by_default() const;
    void set_use_system_theme_by_default(bool value);

    // optional string custom_theme_name = 3;
    bool has_custom_theme_name() const;
    void clear_custom_theme_name();
    static const int kCustomThemeNameFieldNumber = 3;
    const ::std::string& custom_theme_name() const;
    void set_custom_theme_name(const ::std::string& value);
    void set_custom_theme_name(const char* value);
    void set_custom_theme_name(const char* value, size_t size);
    ::std::string* mutable_custom_theme_name();
    ::std::string* release_custom_theme_name();
    void set_allocated_custom_theme_name(::std::string* custom_theme_name);

    // optional string custom_theme_id = 4;
    bool has_custom_theme_id() const;
    void clear_custom_theme_id();
    static const int kCustomThemeIdFieldNumber = 4;
    const ::std::string& custom_theme_id() const;
    void set_custom_theme_id(const ::std::string& value);
    void set_custom_theme_id(const char* value);
    void set_custom_theme_id(const char* value, size_t size);
    ::std::string* mutable_custom_theme_id();
    ::std::string* release_custom_theme_id();
    void set_allocated_custom_theme_id(::std::string* custom_theme_id);

    // optional string custom_theme_update_url = 5;
    bool has_custom_theme_update_url() const;
    void clear_custom_theme_update_url();
    static const int kCustomThemeUpdateUrlFieldNumber = 5;
    const ::std::string& custom_theme_update_url() const;
    void set_custom_theme_update_url(const ::std::string& value);
    void set_custom_theme_update_url(const char* value);
    void set_custom_theme_update_url(const char* value, size_t size);
    ::std::string* mutable_custom_theme_update_url();
    ::std::string* release_custom_theme_update_url();
    void set_allocated_custom_theme_update_url(::std::string* custom_theme_update_url);

    // @@protoc_insertion_point(class_scope:sync_pb.ThemeSpecifics)
private:
    inline void set_has_use_custom_theme();
    inline void clear_has_use_custom_theme();
    inline void set_has_use_system_theme_by_default();
    inline void clear_has_use_system_theme_by_default();
    inline void set_has_custom_theme_name();
    inline void clear_has_custom_theme_name();
    inline void set_has_custom_theme_id();
    inline void clear_has_custom_theme_id();
    inline void set_has_custom_theme_update_url();
    inline void clear_has_custom_theme_update_url();

    ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
    ::google::protobuf::Arena* _arena_ptr_;

    ::google::protobuf::uint32 _has_bits_[1];
    mutable int _cached_size_;
    ::google::protobuf::internal::ArenaStringPtr custom_theme_name_;
    ::google::protobuf::internal::ArenaStringPtr custom_theme_id_;
    ::google::protobuf::internal::ArenaStringPtr custom_theme_update_url_;
    bool use_custom_theme_;
    bool use_system_theme_by_default_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    friend void protobuf_AddDesc_theme_5fspecifics_2eproto_impl();
#else
    friend void protobuf_AddDesc_theme_5fspecifics_2eproto();
#endif
    friend void protobuf_AssignDesc_theme_5fspecifics_2eproto();
    friend void protobuf_ShutdownFile_theme_5fspecifics_2eproto();

    void InitAsDefaultInstance();
    static ThemeSpecifics* default_instance_;
};
// ===================================================================

// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ThemeSpecifics

// optional bool use_custom_theme = 1;
inline bool ThemeSpecifics::has_use_custom_theme() const
{
    return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ThemeSpecifics::set_has_use_custom_theme()
{
    _has_bits_[0] |= 0x00000001u;
}
inline void ThemeSpecifics::clear_has_use_custom_theme()
{
    _has_bits_[0] &= ~0x00000001u;
}
inline void ThemeSpecifics::clear_use_custom_theme()
{
    use_custom_theme_ = false;
    clear_has_use_custom_theme();
}
inline bool ThemeSpecifics::use_custom_theme() const
{
    // @@protoc_insertion_point(field_get:sync_pb.ThemeSpecifics.use_custom_theme)
    return use_custom_theme_;
}
inline void ThemeSpecifics::set_use_custom_theme(bool value)
{
    set_has_use_custom_theme();
    use_custom_theme_ = value;
    // @@protoc_insertion_point(field_set:sync_pb.ThemeSpecifics.use_custom_theme)
}

// optional bool use_system_theme_by_default = 2;
inline bool ThemeSpecifics::has_use_system_theme_by_default() const
{
    return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ThemeSpecifics::set_has_use_system_theme_by_default()
{
    _has_bits_[0] |= 0x00000002u;
}
inline void ThemeSpecifics::clear_has_use_system_theme_by_default()
{
    _has_bits_[0] &= ~0x00000002u;
}
inline void ThemeSpecifics::clear_use_system_theme_by_default()
{
    use_system_theme_by_default_ = false;
    clear_has_use_system_theme_by_default();
}
inline bool ThemeSpecifics::use_system_theme_by_default() const
{
    // @@protoc_insertion_point(field_get:sync_pb.ThemeSpecifics.use_system_theme_by_default)
    return use_system_theme_by_default_;
}
inline void ThemeSpecifics::set_use_system_theme_by_default(bool value)
{
    set_has_use_system_theme_by_default();
    use_system_theme_by_default_ = value;
    // @@protoc_insertion_point(field_set:sync_pb.ThemeSpecifics.use_system_theme_by_default)
}

// optional string custom_theme_name = 3;
inline bool ThemeSpecifics::has_custom_theme_name() const
{
    return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ThemeSpecifics::set_has_custom_theme_name()
{
    _has_bits_[0] |= 0x00000004u;
}
inline void ThemeSpecifics::clear_has_custom_theme_name()
{
    _has_bits_[0] &= ~0x00000004u;
}
inline void ThemeSpecifics::clear_custom_theme_name()
{
    custom_theme_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_custom_theme_name();
}
inline const ::std::string& ThemeSpecifics::custom_theme_name() const
{
    // @@protoc_insertion_point(field_get:sync_pb.ThemeSpecifics.custom_theme_name)
    return custom_theme_name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ThemeSpecifics::set_custom_theme_name(const ::std::string& value)
{
    set_has_custom_theme_name();
    custom_theme_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
    // @@protoc_insertion_point(field_set:sync_pb.ThemeSpecifics.custom_theme_name)
}
inline void ThemeSpecifics::set_custom_theme_name(const char* value)
{
    set_has_custom_theme_name();
    custom_theme_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
    // @@protoc_insertion_point(field_set_char:sync_pb.ThemeSpecifics.custom_theme_name)
}
inline void ThemeSpecifics::set_custom_theme_name(const char* value, size_t size)
{
    set_has_custom_theme_name();
    custom_theme_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        ::std::string(reinterpret_cast<const char*>(value), size));
    // @@protoc_insertion_point(field_set_pointer:sync_pb.ThemeSpecifics.custom_theme_name)
}
inline ::std::string* ThemeSpecifics::mutable_custom_theme_name()
{
    set_has_custom_theme_name();
    // @@protoc_insertion_point(field_mutable:sync_pb.ThemeSpecifics.custom_theme_name)
    return custom_theme_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ThemeSpecifics::release_custom_theme_name()
{
    // @@protoc_insertion_point(field_release:sync_pb.ThemeSpecifics.custom_theme_name)
    clear_has_custom_theme_name();
    return custom_theme_name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ThemeSpecifics::set_allocated_custom_theme_name(::std::string* custom_theme_name)
{
    if (custom_theme_name != NULL) {
        set_has_custom_theme_name();
    } else {
        clear_has_custom_theme_name();
    }
    custom_theme_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), custom_theme_name);
    // @@protoc_insertion_point(field_set_allocated:sync_pb.ThemeSpecifics.custom_theme_name)
}

// optional string custom_theme_id = 4;
inline bool ThemeSpecifics::has_custom_theme_id() const
{
    return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void ThemeSpecifics::set_has_custom_theme_id()
{
    _has_bits_[0] |= 0x00000008u;
}
inline void ThemeSpecifics::clear_has_custom_theme_id()
{
    _has_bits_[0] &= ~0x00000008u;
}
inline void ThemeSpecifics::clear_custom_theme_id()
{
    custom_theme_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_custom_theme_id();
}
inline const ::std::string& ThemeSpecifics::custom_theme_id() const
{
    // @@protoc_insertion_point(field_get:sync_pb.ThemeSpecifics.custom_theme_id)
    return custom_theme_id_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ThemeSpecifics::set_custom_theme_id(const ::std::string& value)
{
    set_has_custom_theme_id();
    custom_theme_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
    // @@protoc_insertion_point(field_set:sync_pb.ThemeSpecifics.custom_theme_id)
}
inline void ThemeSpecifics::set_custom_theme_id(const char* value)
{
    set_has_custom_theme_id();
    custom_theme_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
    // @@protoc_insertion_point(field_set_char:sync_pb.ThemeSpecifics.custom_theme_id)
}
inline void ThemeSpecifics::set_custom_theme_id(const char* value, size_t size)
{
    set_has_custom_theme_id();
    custom_theme_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        ::std::string(reinterpret_cast<const char*>(value), size));
    // @@protoc_insertion_point(field_set_pointer:sync_pb.ThemeSpecifics.custom_theme_id)
}
inline ::std::string* ThemeSpecifics::mutable_custom_theme_id()
{
    set_has_custom_theme_id();
    // @@protoc_insertion_point(field_mutable:sync_pb.ThemeSpecifics.custom_theme_id)
    return custom_theme_id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ThemeSpecifics::release_custom_theme_id()
{
    // @@protoc_insertion_point(field_release:sync_pb.ThemeSpecifics.custom_theme_id)
    clear_has_custom_theme_id();
    return custom_theme_id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ThemeSpecifics::set_allocated_custom_theme_id(::std::string* custom_theme_id)
{
    if (custom_theme_id != NULL) {
        set_has_custom_theme_id();
    } else {
        clear_has_custom_theme_id();
    }
    custom_theme_id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), custom_theme_id);
    // @@protoc_insertion_point(field_set_allocated:sync_pb.ThemeSpecifics.custom_theme_id)
}

// optional string custom_theme_update_url = 5;
inline bool ThemeSpecifics::has_custom_theme_update_url() const
{
    return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void ThemeSpecifics::set_has_custom_theme_update_url()
{
    _has_bits_[0] |= 0x00000010u;
}
inline void ThemeSpecifics::clear_has_custom_theme_update_url()
{
    _has_bits_[0] &= ~0x00000010u;
}
inline void ThemeSpecifics::clear_custom_theme_update_url()
{
    custom_theme_update_url_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_custom_theme_update_url();
}
inline const ::std::string& ThemeSpecifics::custom_theme_update_url() const
{
    // @@protoc_insertion_point(field_get:sync_pb.ThemeSpecifics.custom_theme_update_url)
    return custom_theme_update_url_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ThemeSpecifics::set_custom_theme_update_url(const ::std::string& value)
{
    set_has_custom_theme_update_url();
    custom_theme_update_url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
    // @@protoc_insertion_point(field_set:sync_pb.ThemeSpecifics.custom_theme_update_url)
}
inline void ThemeSpecifics::set_custom_theme_update_url(const char* value)
{
    set_has_custom_theme_update_url();
    custom_theme_update_url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
    // @@protoc_insertion_point(field_set_char:sync_pb.ThemeSpecifics.custom_theme_update_url)
}
inline void ThemeSpecifics::set_custom_theme_update_url(const char* value, size_t size)
{
    set_has_custom_theme_update_url();
    custom_theme_update_url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        ::std::string(reinterpret_cast<const char*>(value), size));
    // @@protoc_insertion_point(field_set_pointer:sync_pb.ThemeSpecifics.custom_theme_update_url)
}
inline ::std::string* ThemeSpecifics::mutable_custom_theme_update_url()
{
    set_has_custom_theme_update_url();
    // @@protoc_insertion_point(field_mutable:sync_pb.ThemeSpecifics.custom_theme_update_url)
    return custom_theme_update_url_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ThemeSpecifics::release_custom_theme_update_url()
{
    // @@protoc_insertion_point(field_release:sync_pb.ThemeSpecifics.custom_theme_update_url)
    clear_has_custom_theme_update_url();
    return custom_theme_update_url_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ThemeSpecifics::set_allocated_custom_theme_update_url(::std::string* custom_theme_update_url)
{
    if (custom_theme_update_url != NULL) {
        set_has_custom_theme_update_url();
    } else {
        clear_has_custom_theme_update_url();
    }
    custom_theme_update_url_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), custom_theme_update_url);
    // @@protoc_insertion_point(field_set_allocated:sync_pb.ThemeSpecifics.custom_theme_update_url)
}

#endif // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

} // namespace sync_pb

// @@protoc_insertion_point(global_scope)

#endif // PROTOBUF_theme_5fspecifics_2eproto__INCLUDED
