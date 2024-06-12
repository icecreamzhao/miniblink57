// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sync_enums.proto

#ifndef PROTOBUF_sync_5fenums_2eproto__INCLUDED
#define PROTOBUF_sync_5fenums_2eproto__INCLUDED

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
#include <google/protobuf/generated_enum_util.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>
// @@protoc_insertion_point(includes)

namespace sync_pb {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_sync_5fenums_2eproto();
void protobuf_AssignDesc_sync_5fenums_2eproto();
void protobuf_ShutdownFile_sync_5fenums_2eproto();

class SyncEnums;

enum SyncEnums_SingletonDebugEventType {
    SyncEnums_SingletonDebugEventType_CONNECTION_STATUS_CHANGE = 1,
    SyncEnums_SingletonDebugEventType_UPDATED_TOKEN = 2,
    SyncEnums_SingletonDebugEventType_PASSPHRASE_REQUIRED = 3,
    SyncEnums_SingletonDebugEventType_PASSPHRASE_ACCEPTED = 4,
    SyncEnums_SingletonDebugEventType_INITIALIZATION_COMPLETE = 5,
    SyncEnums_SingletonDebugEventType_STOP_SYNCING_PERMANENTLY = 6,
    SyncEnums_SingletonDebugEventType_ENCRYPTION_COMPLETE = 7,
    SyncEnums_SingletonDebugEventType_ACTIONABLE_ERROR = 8,
    SyncEnums_SingletonDebugEventType_ENCRYPTED_TYPES_CHANGED = 9,
    SyncEnums_SingletonDebugEventType_PASSPHRASE_TYPE_CHANGED = 10,
    SyncEnums_SingletonDebugEventType_KEYSTORE_TOKEN_UPDATED = 11,
    SyncEnums_SingletonDebugEventType_CONFIGURE_COMPLETE = 12,
    SyncEnums_SingletonDebugEventType_BOOTSTRAP_TOKEN_UPDATED = 13
};
bool SyncEnums_SingletonDebugEventType_IsValid(int value);
const SyncEnums_SingletonDebugEventType SyncEnums_SingletonDebugEventType_SingletonDebugEventType_MIN = SyncEnums_SingletonDebugEventType_CONNECTION_STATUS_CHANGE;
const SyncEnums_SingletonDebugEventType SyncEnums_SingletonDebugEventType_SingletonDebugEventType_MAX = SyncEnums_SingletonDebugEventType_BOOTSTRAP_TOKEN_UPDATED;
const int SyncEnums_SingletonDebugEventType_SingletonDebugEventType_ARRAYSIZE = SyncEnums_SingletonDebugEventType_SingletonDebugEventType_MAX + 1;

enum SyncEnums_PageTransition {
    SyncEnums_PageTransition_LINK = 0,
    SyncEnums_PageTransition_TYPED = 1,
    SyncEnums_PageTransition_AUTO_BOOKMARK = 2,
    SyncEnums_PageTransition_AUTO_SUBFRAME = 3,
    SyncEnums_PageTransition_MANUAL_SUBFRAME = 4,
    SyncEnums_PageTransition_GENERATED = 5,
    SyncEnums_PageTransition_AUTO_TOPLEVEL = 6,
    SyncEnums_PageTransition_FORM_SUBMIT = 7,
    SyncEnums_PageTransition_RELOAD = 8,
    SyncEnums_PageTransition_KEYWORD = 9,
    SyncEnums_PageTransition_KEYWORD_GENERATED = 10
};
bool SyncEnums_PageTransition_IsValid(int value);
const SyncEnums_PageTransition SyncEnums_PageTransition_PageTransition_MIN = SyncEnums_PageTransition_LINK;
const SyncEnums_PageTransition SyncEnums_PageTransition_PageTransition_MAX = SyncEnums_PageTransition_KEYWORD_GENERATED;
const int SyncEnums_PageTransition_PageTransition_ARRAYSIZE = SyncEnums_PageTransition_PageTransition_MAX + 1;

enum SyncEnums_PageTransitionRedirectType {
    SyncEnums_PageTransitionRedirectType_CLIENT_REDIRECT = 1,
    SyncEnums_PageTransitionRedirectType_SERVER_REDIRECT = 2
};
bool SyncEnums_PageTransitionRedirectType_IsValid(int value);
const SyncEnums_PageTransitionRedirectType SyncEnums_PageTransitionRedirectType_PageTransitionRedirectType_MIN = SyncEnums_PageTransitionRedirectType_CLIENT_REDIRECT;
const SyncEnums_PageTransitionRedirectType SyncEnums_PageTransitionRedirectType_PageTransitionRedirectType_MAX = SyncEnums_PageTransitionRedirectType_SERVER_REDIRECT;
const int SyncEnums_PageTransitionRedirectType_PageTransitionRedirectType_ARRAYSIZE = SyncEnums_PageTransitionRedirectType_PageTransitionRedirectType_MAX + 1;

enum SyncEnums_ErrorType {
    SyncEnums_ErrorType_SUCCESS = 0,
    SyncEnums_ErrorType_DEPRECATED_ACCESS_DENIED = 1,
    SyncEnums_ErrorType_NOT_MY_BIRTHDAY = 2,
    SyncEnums_ErrorType_THROTTLED = 3,
    SyncEnums_ErrorType_DEPRECATED_AUTH_EXPIRED = 4,
    SyncEnums_ErrorType_DEPRECATED_USER_NOT_ACTIVATED = 5,
    SyncEnums_ErrorType_DEPRECATED_AUTH_INVALID = 6,
    SyncEnums_ErrorType_CLEAR_PENDING = 7,
    SyncEnums_ErrorType_TRANSIENT_ERROR = 8,
    SyncEnums_ErrorType_MIGRATION_DONE = 9,
    SyncEnums_ErrorType_DISABLED_BY_ADMIN = 10,
    SyncEnums_ErrorType_DEPRECATED_USER_ROLLBACK = 11,
    SyncEnums_ErrorType_PARTIAL_FAILURE = 12,
    SyncEnums_ErrorType_CLIENT_DATA_OBSOLETE = 13,
    SyncEnums_ErrorType_UNKNOWN = 100
};
bool SyncEnums_ErrorType_IsValid(int value);
const SyncEnums_ErrorType SyncEnums_ErrorType_ErrorType_MIN = SyncEnums_ErrorType_SUCCESS;
const SyncEnums_ErrorType SyncEnums_ErrorType_ErrorType_MAX = SyncEnums_ErrorType_UNKNOWN;
const int SyncEnums_ErrorType_ErrorType_ARRAYSIZE = SyncEnums_ErrorType_ErrorType_MAX + 1;

enum SyncEnums_Action {
    SyncEnums_Action_UPGRADE_CLIENT = 0,
    SyncEnums_Action_CLEAR_USER_DATA_AND_RESYNC = 1,
    SyncEnums_Action_ENABLE_SYNC_ON_ACCOUNT = 2,
    SyncEnums_Action_STOP_AND_RESTART_SYNC = 3,
    SyncEnums_Action_DISABLE_SYNC_ON_CLIENT = 4,
    SyncEnums_Action_UNKNOWN_ACTION = 5
};
bool SyncEnums_Action_IsValid(int value);
const SyncEnums_Action SyncEnums_Action_Action_MIN = SyncEnums_Action_UPGRADE_CLIENT;
const SyncEnums_Action SyncEnums_Action_Action_MAX = SyncEnums_Action_UNKNOWN_ACTION;
const int SyncEnums_Action_Action_ARRAYSIZE = SyncEnums_Action_Action_MAX + 1;

enum SyncEnums_DeviceType {
    SyncEnums_DeviceType_TYPE_WIN = 1,
    SyncEnums_DeviceType_TYPE_MAC = 2,
    SyncEnums_DeviceType_TYPE_LINUX = 3,
    SyncEnums_DeviceType_TYPE_CROS = 4,
    SyncEnums_DeviceType_TYPE_OTHER = 5,
    SyncEnums_DeviceType_TYPE_PHONE = 6,
    SyncEnums_DeviceType_TYPE_TABLET = 7
};
bool SyncEnums_DeviceType_IsValid(int value);
const SyncEnums_DeviceType SyncEnums_DeviceType_DeviceType_MIN = SyncEnums_DeviceType_TYPE_WIN;
const SyncEnums_DeviceType SyncEnums_DeviceType_DeviceType_MAX = SyncEnums_DeviceType_TYPE_TABLET;
const int SyncEnums_DeviceType_DeviceType_ARRAYSIZE = SyncEnums_DeviceType_DeviceType_MAX + 1;

enum SyncEnums_GetUpdatesOrigin {
    SyncEnums_GetUpdatesOrigin_UNKNOWN_ORIGIN = 0,
    SyncEnums_GetUpdatesOrigin_PERIODIC = 4,
    SyncEnums_GetUpdatesOrigin_NEWLY_SUPPORTED_DATATYPE = 7,
    SyncEnums_GetUpdatesOrigin_MIGRATION = 8,
    SyncEnums_GetUpdatesOrigin_NEW_CLIENT = 9,
    SyncEnums_GetUpdatesOrigin_RECONFIGURATION = 10,
    SyncEnums_GetUpdatesOrigin_GU_TRIGGER = 12,
    SyncEnums_GetUpdatesOrigin_RETRY = 13,
    SyncEnums_GetUpdatesOrigin_PROGRAMMATIC = 14
};
bool SyncEnums_GetUpdatesOrigin_IsValid(int value);
const SyncEnums_GetUpdatesOrigin SyncEnums_GetUpdatesOrigin_GetUpdatesOrigin_MIN = SyncEnums_GetUpdatesOrigin_UNKNOWN_ORIGIN;
const SyncEnums_GetUpdatesOrigin SyncEnums_GetUpdatesOrigin_GetUpdatesOrigin_MAX = SyncEnums_GetUpdatesOrigin_PROGRAMMATIC;
const int SyncEnums_GetUpdatesOrigin_GetUpdatesOrigin_ARRAYSIZE = SyncEnums_GetUpdatesOrigin_GetUpdatesOrigin_MAX + 1;

// ===================================================================

class SyncEnums : public ::google::protobuf::MessageLite {
public:
    SyncEnums();
    virtual ~SyncEnums();

    SyncEnums(const SyncEnums& from);

    inline SyncEnums& operator=(const SyncEnums& from)
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

    static const SyncEnums& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    // Returns the internal default instance pointer. This function can
    // return NULL thus should not be used by the user. This is intended
    // for Protobuf internal code. Please use default_instance() declared
    // above instead.
    static inline const SyncEnums* internal_default_instance()
    {
        return default_instance_;
    }
#endif

    GOOGLE_ATTRIBUTE_NOINLINE void Swap(SyncEnums* other);

    // implements Message ----------------------------------------------

    inline SyncEnums* New() const { return New(NULL); }

    SyncEnums* New(::google::protobuf::Arena* arena) const;
    void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
    void CopyFrom(const SyncEnums& from);
    void MergeFrom(const SyncEnums& from);
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
    void InternalSwap(SyncEnums* other);

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

    typedef SyncEnums_SingletonDebugEventType SingletonDebugEventType;
    static const SingletonDebugEventType CONNECTION_STATUS_CHANGE = SyncEnums_SingletonDebugEventType_CONNECTION_STATUS_CHANGE;
    static const SingletonDebugEventType UPDATED_TOKEN = SyncEnums_SingletonDebugEventType_UPDATED_TOKEN;
    static const SingletonDebugEventType PASSPHRASE_REQUIRED = SyncEnums_SingletonDebugEventType_PASSPHRASE_REQUIRED;
    static const SingletonDebugEventType PASSPHRASE_ACCEPTED = SyncEnums_SingletonDebugEventType_PASSPHRASE_ACCEPTED;
    static const SingletonDebugEventType INITIALIZATION_COMPLETE = SyncEnums_SingletonDebugEventType_INITIALIZATION_COMPLETE;
    static const SingletonDebugEventType STOP_SYNCING_PERMANENTLY = SyncEnums_SingletonDebugEventType_STOP_SYNCING_PERMANENTLY;
    static const SingletonDebugEventType ENCRYPTION_COMPLETE = SyncEnums_SingletonDebugEventType_ENCRYPTION_COMPLETE;
    static const SingletonDebugEventType ACTIONABLE_ERROR = SyncEnums_SingletonDebugEventType_ACTIONABLE_ERROR;
    static const SingletonDebugEventType ENCRYPTED_TYPES_CHANGED = SyncEnums_SingletonDebugEventType_ENCRYPTED_TYPES_CHANGED;
    static const SingletonDebugEventType PASSPHRASE_TYPE_CHANGED = SyncEnums_SingletonDebugEventType_PASSPHRASE_TYPE_CHANGED;
    static const SingletonDebugEventType KEYSTORE_TOKEN_UPDATED = SyncEnums_SingletonDebugEventType_KEYSTORE_TOKEN_UPDATED;
    static const SingletonDebugEventType CONFIGURE_COMPLETE = SyncEnums_SingletonDebugEventType_CONFIGURE_COMPLETE;
    static const SingletonDebugEventType BOOTSTRAP_TOKEN_UPDATED = SyncEnums_SingletonDebugEventType_BOOTSTRAP_TOKEN_UPDATED;
    static inline bool SingletonDebugEventType_IsValid(int value)
    {
        return SyncEnums_SingletonDebugEventType_IsValid(value);
    }
    static const SingletonDebugEventType SingletonDebugEventType_MIN = SyncEnums_SingletonDebugEventType_SingletonDebugEventType_MIN;
    static const SingletonDebugEventType SingletonDebugEventType_MAX = SyncEnums_SingletonDebugEventType_SingletonDebugEventType_MAX;
    static const int SingletonDebugEventType_ARRAYSIZE = SyncEnums_SingletonDebugEventType_SingletonDebugEventType_ARRAYSIZE;

    typedef SyncEnums_PageTransition PageTransition;
    static const PageTransition LINK = SyncEnums_PageTransition_LINK;
    static const PageTransition TYPED = SyncEnums_PageTransition_TYPED;
    static const PageTransition AUTO_BOOKMARK = SyncEnums_PageTransition_AUTO_BOOKMARK;
    static const PageTransition AUTO_SUBFRAME = SyncEnums_PageTransition_AUTO_SUBFRAME;
    static const PageTransition MANUAL_SUBFRAME = SyncEnums_PageTransition_MANUAL_SUBFRAME;
    static const PageTransition GENERATED = SyncEnums_PageTransition_GENERATED;
    static const PageTransition AUTO_TOPLEVEL = SyncEnums_PageTransition_AUTO_TOPLEVEL;
    static const PageTransition FORM_SUBMIT = SyncEnums_PageTransition_FORM_SUBMIT;
    static const PageTransition RELOAD = SyncEnums_PageTransition_RELOAD;
    static const PageTransition KEYWORD = SyncEnums_PageTransition_KEYWORD;
    static const PageTransition KEYWORD_GENERATED = SyncEnums_PageTransition_KEYWORD_GENERATED;
    static inline bool PageTransition_IsValid(int value)
    {
        return SyncEnums_PageTransition_IsValid(value);
    }
    static const PageTransition PageTransition_MIN = SyncEnums_PageTransition_PageTransition_MIN;
    static const PageTransition PageTransition_MAX = SyncEnums_PageTransition_PageTransition_MAX;
    static const int PageTransition_ARRAYSIZE = SyncEnums_PageTransition_PageTransition_ARRAYSIZE;

    typedef SyncEnums_PageTransitionRedirectType PageTransitionRedirectType;
    static const PageTransitionRedirectType CLIENT_REDIRECT = SyncEnums_PageTransitionRedirectType_CLIENT_REDIRECT;
    static const PageTransitionRedirectType SERVER_REDIRECT = SyncEnums_PageTransitionRedirectType_SERVER_REDIRECT;
    static inline bool PageTransitionRedirectType_IsValid(int value)
    {
        return SyncEnums_PageTransitionRedirectType_IsValid(value);
    }
    static const PageTransitionRedirectType PageTransitionRedirectType_MIN = SyncEnums_PageTransitionRedirectType_PageTransitionRedirectType_MIN;
    static const PageTransitionRedirectType PageTransitionRedirectType_MAX = SyncEnums_PageTransitionRedirectType_PageTransitionRedirectType_MAX;
    static const int PageTransitionRedirectType_ARRAYSIZE = SyncEnums_PageTransitionRedirectType_PageTransitionRedirectType_ARRAYSIZE;

    typedef SyncEnums_ErrorType ErrorType;
    static const ErrorType SUCCESS = SyncEnums_ErrorType_SUCCESS;
    static const ErrorType DEPRECATED_ACCESS_DENIED = SyncEnums_ErrorType_DEPRECATED_ACCESS_DENIED;
    static const ErrorType NOT_MY_BIRTHDAY = SyncEnums_ErrorType_NOT_MY_BIRTHDAY;
    static const ErrorType THROTTLED = SyncEnums_ErrorType_THROTTLED;
    static const ErrorType DEPRECATED_AUTH_EXPIRED = SyncEnums_ErrorType_DEPRECATED_AUTH_EXPIRED;
    static const ErrorType DEPRECATED_USER_NOT_ACTIVATED = SyncEnums_ErrorType_DEPRECATED_USER_NOT_ACTIVATED;
    static const ErrorType DEPRECATED_AUTH_INVALID = SyncEnums_ErrorType_DEPRECATED_AUTH_INVALID;
    static const ErrorType CLEAR_PENDING = SyncEnums_ErrorType_CLEAR_PENDING;
    static const ErrorType TRANSIENT_ERROR = SyncEnums_ErrorType_TRANSIENT_ERROR;
    static const ErrorType MIGRATION_DONE = SyncEnums_ErrorType_MIGRATION_DONE;
    static const ErrorType DISABLED_BY_ADMIN = SyncEnums_ErrorType_DISABLED_BY_ADMIN;
    static const ErrorType DEPRECATED_USER_ROLLBACK = SyncEnums_ErrorType_DEPRECATED_USER_ROLLBACK;
    static const ErrorType PARTIAL_FAILURE = SyncEnums_ErrorType_PARTIAL_FAILURE;
    static const ErrorType CLIENT_DATA_OBSOLETE = SyncEnums_ErrorType_CLIENT_DATA_OBSOLETE;
    static const ErrorType UNKNOWN = SyncEnums_ErrorType_UNKNOWN;
    static inline bool ErrorType_IsValid(int value)
    {
        return SyncEnums_ErrorType_IsValid(value);
    }
    static const ErrorType ErrorType_MIN = SyncEnums_ErrorType_ErrorType_MIN;
    static const ErrorType ErrorType_MAX = SyncEnums_ErrorType_ErrorType_MAX;
    static const int ErrorType_ARRAYSIZE = SyncEnums_ErrorType_ErrorType_ARRAYSIZE;

    typedef SyncEnums_Action Action;
    static const Action UPGRADE_CLIENT = SyncEnums_Action_UPGRADE_CLIENT;
    static const Action CLEAR_USER_DATA_AND_RESYNC = SyncEnums_Action_CLEAR_USER_DATA_AND_RESYNC;
    static const Action ENABLE_SYNC_ON_ACCOUNT = SyncEnums_Action_ENABLE_SYNC_ON_ACCOUNT;
    static const Action STOP_AND_RESTART_SYNC = SyncEnums_Action_STOP_AND_RESTART_SYNC;
    static const Action DISABLE_SYNC_ON_CLIENT = SyncEnums_Action_DISABLE_SYNC_ON_CLIENT;
    static const Action UNKNOWN_ACTION = SyncEnums_Action_UNKNOWN_ACTION;
    static inline bool Action_IsValid(int value)
    {
        return SyncEnums_Action_IsValid(value);
    }
    static const Action Action_MIN = SyncEnums_Action_Action_MIN;
    static const Action Action_MAX = SyncEnums_Action_Action_MAX;
    static const int Action_ARRAYSIZE = SyncEnums_Action_Action_ARRAYSIZE;

    typedef SyncEnums_DeviceType DeviceType;
    static const DeviceType TYPE_WIN = SyncEnums_DeviceType_TYPE_WIN;
    static const DeviceType TYPE_MAC = SyncEnums_DeviceType_TYPE_MAC;
    static const DeviceType TYPE_LINUX = SyncEnums_DeviceType_TYPE_LINUX;
    static const DeviceType TYPE_CROS = SyncEnums_DeviceType_TYPE_CROS;
    static const DeviceType TYPE_OTHER = SyncEnums_DeviceType_TYPE_OTHER;
    static const DeviceType TYPE_PHONE = SyncEnums_DeviceType_TYPE_PHONE;
    static const DeviceType TYPE_TABLET = SyncEnums_DeviceType_TYPE_TABLET;
    static inline bool DeviceType_IsValid(int value)
    {
        return SyncEnums_DeviceType_IsValid(value);
    }
    static const DeviceType DeviceType_MIN = SyncEnums_DeviceType_DeviceType_MIN;
    static const DeviceType DeviceType_MAX = SyncEnums_DeviceType_DeviceType_MAX;
    static const int DeviceType_ARRAYSIZE = SyncEnums_DeviceType_DeviceType_ARRAYSIZE;

    typedef SyncEnums_GetUpdatesOrigin GetUpdatesOrigin;
    static const GetUpdatesOrigin UNKNOWN_ORIGIN = SyncEnums_GetUpdatesOrigin_UNKNOWN_ORIGIN;
    static const GetUpdatesOrigin PERIODIC = SyncEnums_GetUpdatesOrigin_PERIODIC;
    static const GetUpdatesOrigin NEWLY_SUPPORTED_DATATYPE = SyncEnums_GetUpdatesOrigin_NEWLY_SUPPORTED_DATATYPE;
    static const GetUpdatesOrigin MIGRATION = SyncEnums_GetUpdatesOrigin_MIGRATION;
    static const GetUpdatesOrigin NEW_CLIENT = SyncEnums_GetUpdatesOrigin_NEW_CLIENT;
    static const GetUpdatesOrigin RECONFIGURATION = SyncEnums_GetUpdatesOrigin_RECONFIGURATION;
    static const GetUpdatesOrigin GU_TRIGGER = SyncEnums_GetUpdatesOrigin_GU_TRIGGER;
    static const GetUpdatesOrigin RETRY = SyncEnums_GetUpdatesOrigin_RETRY;
    static const GetUpdatesOrigin PROGRAMMATIC = SyncEnums_GetUpdatesOrigin_PROGRAMMATIC;
    static inline bool GetUpdatesOrigin_IsValid(int value)
    {
        return SyncEnums_GetUpdatesOrigin_IsValid(value);
    }
    static const GetUpdatesOrigin GetUpdatesOrigin_MIN = SyncEnums_GetUpdatesOrigin_GetUpdatesOrigin_MIN;
    static const GetUpdatesOrigin GetUpdatesOrigin_MAX = SyncEnums_GetUpdatesOrigin_GetUpdatesOrigin_MAX;
    static const int GetUpdatesOrigin_ARRAYSIZE = SyncEnums_GetUpdatesOrigin_GetUpdatesOrigin_ARRAYSIZE;

    // accessors -------------------------------------------------------

    // @@protoc_insertion_point(class_scope:sync_pb.SyncEnums)
private:
    ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
    ::google::protobuf::Arena* _arena_ptr_;

    ::google::protobuf::uint32 _has_bits_[1];
    mutable int _cached_size_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    friend void protobuf_AddDesc_sync_5fenums_2eproto_impl();
#else
    friend void protobuf_AddDesc_sync_5fenums_2eproto();
#endif
    friend void protobuf_AssignDesc_sync_5fenums_2eproto();
    friend void protobuf_ShutdownFile_sync_5fenums_2eproto();

    void InitAsDefaultInstance();
    static SyncEnums* default_instance_;
};
// ===================================================================

// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// SyncEnums

#endif // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

} // namespace sync_pb

#ifndef SWIG
namespace google {
namespace protobuf {

    template <>
    struct is_proto_enum<::sync_pb::SyncEnums_SingletonDebugEventType> : ::google::protobuf::internal::true_type {
    };
    template <>
    struct is_proto_enum<::sync_pb::SyncEnums_PageTransition> : ::google::protobuf::internal::true_type {
    };
    template <>
    struct is_proto_enum<::sync_pb::SyncEnums_PageTransitionRedirectType> : ::google::protobuf::internal::true_type {
    };
    template <>
    struct is_proto_enum<::sync_pb::SyncEnums_ErrorType> : ::google::protobuf::internal::true_type {
    };
    template <>
    struct is_proto_enum<::sync_pb::SyncEnums_Action> : ::google::protobuf::internal::true_type {
    };
    template <>
    struct is_proto_enum<::sync_pb::SyncEnums_DeviceType> : ::google::protobuf::internal::true_type {
    };
    template <>
    struct is_proto_enum<::sync_pb::SyncEnums_GetUpdatesOrigin> : ::google::protobuf::internal::true_type {
    };

} // namespace protobuf
} // namespace google
#endif // SWIG

// @@protoc_insertion_point(global_scope)

#endif // PROTOBUF_sync_5fenums_2eproto__INCLUDED
