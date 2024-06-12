// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: extension_specifics.proto

#ifndef PROTOBUF_extension_5fspecifics_2eproto__INCLUDED
#define PROTOBUF_extension_5fspecifics_2eproto__INCLUDED

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
void protobuf_AddDesc_extension_5fspecifics_2eproto();
void protobuf_AssignDesc_extension_5fspecifics_2eproto();
void protobuf_ShutdownFile_extension_5fspecifics_2eproto();

class ExtensionSpecifics;

// ===================================================================

class ExtensionSpecifics : public ::google::protobuf::MessageLite {
public:
    ExtensionSpecifics();
    virtual ~ExtensionSpecifics();

    ExtensionSpecifics(const ExtensionSpecifics& from);

    inline ExtensionSpecifics& operator=(const ExtensionSpecifics& from)
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

    static const ExtensionSpecifics& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    // Returns the internal default instance pointer. This function can
    // return NULL thus should not be used by the user. This is intended
    // for Protobuf internal code. Please use default_instance() declared
    // above instead.
    static inline const ExtensionSpecifics* internal_default_instance()
    {
        return default_instance_;
    }
#endif

    GOOGLE_ATTRIBUTE_NOINLINE void Swap(ExtensionSpecifics* other);

    // implements Message ----------------------------------------------

    inline ExtensionSpecifics* New() const { return New(NULL); }

    ExtensionSpecifics* New(::google::protobuf::Arena* arena) const;
    void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
    void CopyFrom(const ExtensionSpecifics& from);
    void MergeFrom(const ExtensionSpecifics& from);
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
    void InternalSwap(ExtensionSpecifics* other);

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

    // optional string id = 1;
    bool has_id() const;
    void clear_id();
    static const int kIdFieldNumber = 1;
    const ::std::string& id() const;
    void set_id(const ::std::string& value);
    void set_id(const char* value);
    void set_id(const char* value, size_t size);
    ::std::string* mutable_id();
    ::std::string* release_id();
    void set_allocated_id(::std::string* id);

    // optional string version = 2;
    bool has_version() const;
    void clear_version();
    static const int kVersionFieldNumber = 2;
    const ::std::string& version() const;
    void set_version(const ::std::string& value);
    void set_version(const char* value);
    void set_version(const char* value, size_t size);
    ::std::string* mutable_version();
    ::std::string* release_version();
    void set_allocated_version(::std::string* version);

    // optional string update_url = 3;
    bool has_update_url() const;
    void clear_update_url();
    static const int kUpdateUrlFieldNumber = 3;
    const ::std::string& update_url() const;
    void set_update_url(const ::std::string& value);
    void set_update_url(const char* value);
    void set_update_url(const char* value, size_t size);
    ::std::string* mutable_update_url();
    ::std::string* release_update_url();
    void set_allocated_update_url(::std::string* update_url);

    // optional bool enabled = 4;
    bool has_enabled() const;
    void clear_enabled();
    static const int kEnabledFieldNumber = 4;
    bool enabled() const;
    void set_enabled(bool value);

    // optional bool incognito_enabled = 5;
    bool has_incognito_enabled() const;
    void clear_incognito_enabled();
    static const int kIncognitoEnabledFieldNumber = 5;
    bool incognito_enabled() const;
    void set_incognito_enabled(bool value);

    // optional string name = 6;
    bool has_name() const;
    void clear_name();
    static const int kNameFieldNumber = 6;
    const ::std::string& name() const;
    void set_name(const ::std::string& value);
    void set_name(const char* value);
    void set_name(const char* value, size_t size);
    ::std::string* mutable_name();
    ::std::string* release_name();
    void set_allocated_name(::std::string* name);

    // optional bool remote_install = 7;
    bool has_remote_install() const;
    void clear_remote_install();
    static const int kRemoteInstallFieldNumber = 7;
    bool remote_install() const;
    void set_remote_install(bool value);

    // optional bool installed_by_custodian = 8;
    bool has_installed_by_custodian() const;
    void clear_installed_by_custodian();
    static const int kInstalledByCustodianFieldNumber = 8;
    bool installed_by_custodian() const;
    void set_installed_by_custodian(bool value);

    // optional bool all_urls_enabled = 9;
    bool has_all_urls_enabled() const;
    void clear_all_urls_enabled();
    static const int kAllUrlsEnabledFieldNumber = 9;
    bool all_urls_enabled() const;
    void set_all_urls_enabled(bool value);

    // optional int32 disable_reasons = 10;
    bool has_disable_reasons() const;
    void clear_disable_reasons();
    static const int kDisableReasonsFieldNumber = 10;
    ::google::protobuf::int32 disable_reasons() const;
    void set_disable_reasons(::google::protobuf::int32 value);

    // @@protoc_insertion_point(class_scope:sync_pb.ExtensionSpecifics)
private:
    inline void set_has_id();
    inline void clear_has_id();
    inline void set_has_version();
    inline void clear_has_version();
    inline void set_has_update_url();
    inline void clear_has_update_url();
    inline void set_has_enabled();
    inline void clear_has_enabled();
    inline void set_has_incognito_enabled();
    inline void clear_has_incognito_enabled();
    inline void set_has_name();
    inline void clear_has_name();
    inline void set_has_remote_install();
    inline void clear_has_remote_install();
    inline void set_has_installed_by_custodian();
    inline void clear_has_installed_by_custodian();
    inline void set_has_all_urls_enabled();
    inline void clear_has_all_urls_enabled();
    inline void set_has_disable_reasons();
    inline void clear_has_disable_reasons();

    ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
    ::google::protobuf::Arena* _arena_ptr_;

    ::google::protobuf::uint32 _has_bits_[1];
    mutable int _cached_size_;
    ::google::protobuf::internal::ArenaStringPtr id_;
    ::google::protobuf::internal::ArenaStringPtr version_;
    ::google::protobuf::internal::ArenaStringPtr update_url_;
    ::google::protobuf::internal::ArenaStringPtr name_;
    bool enabled_;
    bool incognito_enabled_;
    bool remote_install_;
    bool installed_by_custodian_;
    bool all_urls_enabled_;
    ::google::protobuf::int32 disable_reasons_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    friend void protobuf_AddDesc_extension_5fspecifics_2eproto_impl();
#else
    friend void protobuf_AddDesc_extension_5fspecifics_2eproto();
#endif
    friend void protobuf_AssignDesc_extension_5fspecifics_2eproto();
    friend void protobuf_ShutdownFile_extension_5fspecifics_2eproto();

    void InitAsDefaultInstance();
    static ExtensionSpecifics* default_instance_;
};
// ===================================================================

// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ExtensionSpecifics

// optional string id = 1;
inline bool ExtensionSpecifics::has_id() const
{
    return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ExtensionSpecifics::set_has_id()
{
    _has_bits_[0] |= 0x00000001u;
}
inline void ExtensionSpecifics::clear_has_id()
{
    _has_bits_[0] &= ~0x00000001u;
}
inline void ExtensionSpecifics::clear_id()
{
    id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_id();
}
inline const ::std::string& ExtensionSpecifics::id() const
{
    // @@protoc_insertion_point(field_get:sync_pb.ExtensionSpecifics.id)
    return id_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ExtensionSpecifics::set_id(const ::std::string& value)
{
    set_has_id();
    id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
    // @@protoc_insertion_point(field_set:sync_pb.ExtensionSpecifics.id)
}
inline void ExtensionSpecifics::set_id(const char* value)
{
    set_has_id();
    id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
    // @@protoc_insertion_point(field_set_char:sync_pb.ExtensionSpecifics.id)
}
inline void ExtensionSpecifics::set_id(const char* value, size_t size)
{
    set_has_id();
    id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        ::std::string(reinterpret_cast<const char*>(value), size));
    // @@protoc_insertion_point(field_set_pointer:sync_pb.ExtensionSpecifics.id)
}
inline ::std::string* ExtensionSpecifics::mutable_id()
{
    set_has_id();
    // @@protoc_insertion_point(field_mutable:sync_pb.ExtensionSpecifics.id)
    return id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ExtensionSpecifics::release_id()
{
    // @@protoc_insertion_point(field_release:sync_pb.ExtensionSpecifics.id)
    clear_has_id();
    return id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ExtensionSpecifics::set_allocated_id(::std::string* id)
{
    if (id != NULL) {
        set_has_id();
    } else {
        clear_has_id();
    }
    id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), id);
    // @@protoc_insertion_point(field_set_allocated:sync_pb.ExtensionSpecifics.id)
}

// optional string version = 2;
inline bool ExtensionSpecifics::has_version() const
{
    return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ExtensionSpecifics::set_has_version()
{
    _has_bits_[0] |= 0x00000002u;
}
inline void ExtensionSpecifics::clear_has_version()
{
    _has_bits_[0] &= ~0x00000002u;
}
inline void ExtensionSpecifics::clear_version()
{
    version_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_version();
}
inline const ::std::string& ExtensionSpecifics::version() const
{
    // @@protoc_insertion_point(field_get:sync_pb.ExtensionSpecifics.version)
    return version_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ExtensionSpecifics::set_version(const ::std::string& value)
{
    set_has_version();
    version_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
    // @@protoc_insertion_point(field_set:sync_pb.ExtensionSpecifics.version)
}
inline void ExtensionSpecifics::set_version(const char* value)
{
    set_has_version();
    version_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
    // @@protoc_insertion_point(field_set_char:sync_pb.ExtensionSpecifics.version)
}
inline void ExtensionSpecifics::set_version(const char* value, size_t size)
{
    set_has_version();
    version_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        ::std::string(reinterpret_cast<const char*>(value), size));
    // @@protoc_insertion_point(field_set_pointer:sync_pb.ExtensionSpecifics.version)
}
inline ::std::string* ExtensionSpecifics::mutable_version()
{
    set_has_version();
    // @@protoc_insertion_point(field_mutable:sync_pb.ExtensionSpecifics.version)
    return version_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ExtensionSpecifics::release_version()
{
    // @@protoc_insertion_point(field_release:sync_pb.ExtensionSpecifics.version)
    clear_has_version();
    return version_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ExtensionSpecifics::set_allocated_version(::std::string* version)
{
    if (version != NULL) {
        set_has_version();
    } else {
        clear_has_version();
    }
    version_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), version);
    // @@protoc_insertion_point(field_set_allocated:sync_pb.ExtensionSpecifics.version)
}

// optional string update_url = 3;
inline bool ExtensionSpecifics::has_update_url() const
{
    return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ExtensionSpecifics::set_has_update_url()
{
    _has_bits_[0] |= 0x00000004u;
}
inline void ExtensionSpecifics::clear_has_update_url()
{
    _has_bits_[0] &= ~0x00000004u;
}
inline void ExtensionSpecifics::clear_update_url()
{
    update_url_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_update_url();
}
inline const ::std::string& ExtensionSpecifics::update_url() const
{
    // @@protoc_insertion_point(field_get:sync_pb.ExtensionSpecifics.update_url)
    return update_url_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ExtensionSpecifics::set_update_url(const ::std::string& value)
{
    set_has_update_url();
    update_url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
    // @@protoc_insertion_point(field_set:sync_pb.ExtensionSpecifics.update_url)
}
inline void ExtensionSpecifics::set_update_url(const char* value)
{
    set_has_update_url();
    update_url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
    // @@protoc_insertion_point(field_set_char:sync_pb.ExtensionSpecifics.update_url)
}
inline void ExtensionSpecifics::set_update_url(const char* value, size_t size)
{
    set_has_update_url();
    update_url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        ::std::string(reinterpret_cast<const char*>(value), size));
    // @@protoc_insertion_point(field_set_pointer:sync_pb.ExtensionSpecifics.update_url)
}
inline ::std::string* ExtensionSpecifics::mutable_update_url()
{
    set_has_update_url();
    // @@protoc_insertion_point(field_mutable:sync_pb.ExtensionSpecifics.update_url)
    return update_url_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ExtensionSpecifics::release_update_url()
{
    // @@protoc_insertion_point(field_release:sync_pb.ExtensionSpecifics.update_url)
    clear_has_update_url();
    return update_url_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ExtensionSpecifics::set_allocated_update_url(::std::string* update_url)
{
    if (update_url != NULL) {
        set_has_update_url();
    } else {
        clear_has_update_url();
    }
    update_url_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), update_url);
    // @@protoc_insertion_point(field_set_allocated:sync_pb.ExtensionSpecifics.update_url)
}

// optional bool enabled = 4;
inline bool ExtensionSpecifics::has_enabled() const
{
    return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void ExtensionSpecifics::set_has_enabled()
{
    _has_bits_[0] |= 0x00000008u;
}
inline void ExtensionSpecifics::clear_has_enabled()
{
    _has_bits_[0] &= ~0x00000008u;
}
inline void ExtensionSpecifics::clear_enabled()
{
    enabled_ = false;
    clear_has_enabled();
}
inline bool ExtensionSpecifics::enabled() const
{
    // @@protoc_insertion_point(field_get:sync_pb.ExtensionSpecifics.enabled)
    return enabled_;
}
inline void ExtensionSpecifics::set_enabled(bool value)
{
    set_has_enabled();
    enabled_ = value;
    // @@protoc_insertion_point(field_set:sync_pb.ExtensionSpecifics.enabled)
}

// optional bool incognito_enabled = 5;
inline bool ExtensionSpecifics::has_incognito_enabled() const
{
    return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void ExtensionSpecifics::set_has_incognito_enabled()
{
    _has_bits_[0] |= 0x00000010u;
}
inline void ExtensionSpecifics::clear_has_incognito_enabled()
{
    _has_bits_[0] &= ~0x00000010u;
}
inline void ExtensionSpecifics::clear_incognito_enabled()
{
    incognito_enabled_ = false;
    clear_has_incognito_enabled();
}
inline bool ExtensionSpecifics::incognito_enabled() const
{
    // @@protoc_insertion_point(field_get:sync_pb.ExtensionSpecifics.incognito_enabled)
    return incognito_enabled_;
}
inline void ExtensionSpecifics::set_incognito_enabled(bool value)
{
    set_has_incognito_enabled();
    incognito_enabled_ = value;
    // @@protoc_insertion_point(field_set:sync_pb.ExtensionSpecifics.incognito_enabled)
}

// optional string name = 6;
inline bool ExtensionSpecifics::has_name() const
{
    return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void ExtensionSpecifics::set_has_name()
{
    _has_bits_[0] |= 0x00000020u;
}
inline void ExtensionSpecifics::clear_has_name()
{
    _has_bits_[0] &= ~0x00000020u;
}
inline void ExtensionSpecifics::clear_name()
{
    name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_name();
}
inline const ::std::string& ExtensionSpecifics::name() const
{
    // @@protoc_insertion_point(field_get:sync_pb.ExtensionSpecifics.name)
    return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ExtensionSpecifics::set_name(const ::std::string& value)
{
    set_has_name();
    name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
    // @@protoc_insertion_point(field_set:sync_pb.ExtensionSpecifics.name)
}
inline void ExtensionSpecifics::set_name(const char* value)
{
    set_has_name();
    name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
    // @@protoc_insertion_point(field_set_char:sync_pb.ExtensionSpecifics.name)
}
inline void ExtensionSpecifics::set_name(const char* value, size_t size)
{
    set_has_name();
    name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        ::std::string(reinterpret_cast<const char*>(value), size));
    // @@protoc_insertion_point(field_set_pointer:sync_pb.ExtensionSpecifics.name)
}
inline ::std::string* ExtensionSpecifics::mutable_name()
{
    set_has_name();
    // @@protoc_insertion_point(field_mutable:sync_pb.ExtensionSpecifics.name)
    return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ExtensionSpecifics::release_name()
{
    // @@protoc_insertion_point(field_release:sync_pb.ExtensionSpecifics.name)
    clear_has_name();
    return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ExtensionSpecifics::set_allocated_name(::std::string* name)
{
    if (name != NULL) {
        set_has_name();
    } else {
        clear_has_name();
    }
    name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
    // @@protoc_insertion_point(field_set_allocated:sync_pb.ExtensionSpecifics.name)
}

// optional bool remote_install = 7;
inline bool ExtensionSpecifics::has_remote_install() const
{
    return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void ExtensionSpecifics::set_has_remote_install()
{
    _has_bits_[0] |= 0x00000040u;
}
inline void ExtensionSpecifics::clear_has_remote_install()
{
    _has_bits_[0] &= ~0x00000040u;
}
inline void ExtensionSpecifics::clear_remote_install()
{
    remote_install_ = false;
    clear_has_remote_install();
}
inline bool ExtensionSpecifics::remote_install() const
{
    // @@protoc_insertion_point(field_get:sync_pb.ExtensionSpecifics.remote_install)
    return remote_install_;
}
inline void ExtensionSpecifics::set_remote_install(bool value)
{
    set_has_remote_install();
    remote_install_ = value;
    // @@protoc_insertion_point(field_set:sync_pb.ExtensionSpecifics.remote_install)
}

// optional bool installed_by_custodian = 8;
inline bool ExtensionSpecifics::has_installed_by_custodian() const
{
    return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void ExtensionSpecifics::set_has_installed_by_custodian()
{
    _has_bits_[0] |= 0x00000080u;
}
inline void ExtensionSpecifics::clear_has_installed_by_custodian()
{
    _has_bits_[0] &= ~0x00000080u;
}
inline void ExtensionSpecifics::clear_installed_by_custodian()
{
    installed_by_custodian_ = false;
    clear_has_installed_by_custodian();
}
inline bool ExtensionSpecifics::installed_by_custodian() const
{
    // @@protoc_insertion_point(field_get:sync_pb.ExtensionSpecifics.installed_by_custodian)
    return installed_by_custodian_;
}
inline void ExtensionSpecifics::set_installed_by_custodian(bool value)
{
    set_has_installed_by_custodian();
    installed_by_custodian_ = value;
    // @@protoc_insertion_point(field_set:sync_pb.ExtensionSpecifics.installed_by_custodian)
}

// optional bool all_urls_enabled = 9;
inline bool ExtensionSpecifics::has_all_urls_enabled() const
{
    return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void ExtensionSpecifics::set_has_all_urls_enabled()
{
    _has_bits_[0] |= 0x00000100u;
}
inline void ExtensionSpecifics::clear_has_all_urls_enabled()
{
    _has_bits_[0] &= ~0x00000100u;
}
inline void ExtensionSpecifics::clear_all_urls_enabled()
{
    all_urls_enabled_ = false;
    clear_has_all_urls_enabled();
}
inline bool ExtensionSpecifics::all_urls_enabled() const
{
    // @@protoc_insertion_point(field_get:sync_pb.ExtensionSpecifics.all_urls_enabled)
    return all_urls_enabled_;
}
inline void ExtensionSpecifics::set_all_urls_enabled(bool value)
{
    set_has_all_urls_enabled();
    all_urls_enabled_ = value;
    // @@protoc_insertion_point(field_set:sync_pb.ExtensionSpecifics.all_urls_enabled)
}

// optional int32 disable_reasons = 10;
inline bool ExtensionSpecifics::has_disable_reasons() const
{
    return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void ExtensionSpecifics::set_has_disable_reasons()
{
    _has_bits_[0] |= 0x00000200u;
}
inline void ExtensionSpecifics::clear_has_disable_reasons()
{
    _has_bits_[0] &= ~0x00000200u;
}
inline void ExtensionSpecifics::clear_disable_reasons()
{
    disable_reasons_ = 0;
    clear_has_disable_reasons();
}
inline ::google::protobuf::int32 ExtensionSpecifics::disable_reasons() const
{
    // @@protoc_insertion_point(field_get:sync_pb.ExtensionSpecifics.disable_reasons)
    return disable_reasons_;
}
inline void ExtensionSpecifics::set_disable_reasons(::google::protobuf::int32 value)
{
    set_has_disable_reasons();
    disable_reasons_ = value;
    // @@protoc_insertion_point(field_set:sync_pb.ExtensionSpecifics.disable_reasons)
}

#endif // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

} // namespace sync_pb

// @@protoc_insertion_point(global_scope)

#endif // PROTOBUF_extension_5fspecifics_2eproto__INCLUDED
