// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: types.proto

#ifndef PROTOBUF_types_2eproto__INCLUDED
#define PROTOBUF_types_2eproto__INCLUDED

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

namespace ipc {
namespace invalidation {

    // Internal implementation detail -- do not call these.
    void protobuf_AddDesc_types_2eproto();
    void protobuf_AssignDesc_types_2eproto();
    void protobuf_ShutdownFile_types_2eproto();

    class ClientType;
    class Constants;
    class ObjectSource;

    enum ClientType_Type {
        ClientType_Type_INTERNAL = 1,
        ClientType_Type_TEST = 2,
        ClientType_Type_DEMO = 4,
        ClientType_Type_CHROME_SYNC = 1004,
        ClientType_Type_CHROME_SYNC_ANDROID = 1018,
        ClientType_Type_CHROME_SYNC_IOS = 1038,
        ClientType_Type_CHROME_SYNC_GCM_DESKTOP = 1055,
        ClientType_Type_CHROME_SYNC_GCM_IOS = 1056
    };
    bool ClientType_Type_IsValid(int value);
    const ClientType_Type ClientType_Type_Type_MIN = ClientType_Type_INTERNAL;
    const ClientType_Type ClientType_Type_Type_MAX = ClientType_Type_CHROME_SYNC_GCM_IOS;
    const int ClientType_Type_Type_ARRAYSIZE = ClientType_Type_Type_MAX + 1;

    enum ObjectSource_Type {
        ObjectSource_Type_INTERNAL = 1,
        ObjectSource_Type_TEST = 2,
        ObjectSource_Type_DEMO = 4,
        ObjectSource_Type_CHROME_SYNC = 1004,
        ObjectSource_Type_COSMO_CHANGELOG = 1014,
        ObjectSource_Type_CHROME_COMPONENTS = 1025,
        ObjectSource_Type_CHROME_PUSH_MESSAGING = 1030
    };
    bool ObjectSource_Type_IsValid(int value);
    const ObjectSource_Type ObjectSource_Type_Type_MIN = ObjectSource_Type_INTERNAL;
    const ObjectSource_Type ObjectSource_Type_Type_MAX = ObjectSource_Type_CHROME_PUSH_MESSAGING;
    const int ObjectSource_Type_Type_ARRAYSIZE = ObjectSource_Type_Type_MAX + 1;

    enum Constants_ObjectVersion {
        Constants_ObjectVersion_UNKNOWN = 0
    };
    bool Constants_ObjectVersion_IsValid(int value);
    const Constants_ObjectVersion Constants_ObjectVersion_ObjectVersion_MIN = Constants_ObjectVersion_UNKNOWN;
    const Constants_ObjectVersion Constants_ObjectVersion_ObjectVersion_MAX = Constants_ObjectVersion_UNKNOWN;
    const int Constants_ObjectVersion_ObjectVersion_ARRAYSIZE = Constants_ObjectVersion_ObjectVersion_MAX + 1;

    // ===================================================================

    class ClientType : public ::google::protobuf::MessageLite {
    public:
        ClientType();
        virtual ~ClientType();

        ClientType(const ClientType& from);

        inline ClientType& operator=(const ClientType& from)
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

        static const ClientType& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        // Returns the internal default instance pointer. This function can
        // return NULL thus should not be used by the user. This is intended
        // for Protobuf internal code. Please use default_instance() declared
        // above instead.
        static inline const ClientType* internal_default_instance()
        {
            return default_instance_;
        }
#endif

        GOOGLE_ATTRIBUTE_NOINLINE void Swap(ClientType* other);

        // implements Message ----------------------------------------------

        inline ClientType* New() const { return New(NULL); }

        ClientType* New(::google::protobuf::Arena* arena) const;
        void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
        void CopyFrom(const ClientType& from);
        void MergeFrom(const ClientType& from);
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
        void InternalSwap(ClientType* other);

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

        typedef ClientType_Type Type;
        static const Type INTERNAL = ClientType_Type_INTERNAL;
        static const Type TEST = ClientType_Type_TEST;
        static const Type DEMO = ClientType_Type_DEMO;
        static const Type CHROME_SYNC = ClientType_Type_CHROME_SYNC;
        static const Type CHROME_SYNC_ANDROID = ClientType_Type_CHROME_SYNC_ANDROID;
        static const Type CHROME_SYNC_IOS = ClientType_Type_CHROME_SYNC_IOS;
        static const Type CHROME_SYNC_GCM_DESKTOP = ClientType_Type_CHROME_SYNC_GCM_DESKTOP;
        static const Type CHROME_SYNC_GCM_IOS = ClientType_Type_CHROME_SYNC_GCM_IOS;
        static inline bool Type_IsValid(int value)
        {
            return ClientType_Type_IsValid(value);
        }
        static const Type Type_MIN = ClientType_Type_Type_MIN;
        static const Type Type_MAX = ClientType_Type_Type_MAX;
        static const int Type_ARRAYSIZE = ClientType_Type_Type_ARRAYSIZE;

        // accessors -------------------------------------------------------

        // optional .ipc.invalidation.ClientType.Type type = 1;
        bool has_type() const;
        void clear_type();
        static const int kTypeFieldNumber = 1;
        ::ipc::invalidation::ClientType_Type type() const;
        void set_type(::ipc::invalidation::ClientType_Type value);

        // @@protoc_insertion_point(class_scope:ipc.invalidation.ClientType)
    private:
        inline void set_has_type();
        inline void clear_has_type();

        ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
        ::google::protobuf::Arena* _arena_ptr_;

        ::google::protobuf::uint32 _has_bits_[1];
        mutable int _cached_size_;
        int type_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        friend void protobuf_AddDesc_types_2eproto_impl();
#else
        friend void protobuf_AddDesc_types_2eproto();
#endif
        friend void protobuf_AssignDesc_types_2eproto();
        friend void protobuf_ShutdownFile_types_2eproto();

        void InitAsDefaultInstance();
        static ClientType* default_instance_;
    };
    // -------------------------------------------------------------------

    class ObjectSource : public ::google::protobuf::MessageLite {
    public:
        ObjectSource();
        virtual ~ObjectSource();

        ObjectSource(const ObjectSource& from);

        inline ObjectSource& operator=(const ObjectSource& from)
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

        static const ObjectSource& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        // Returns the internal default instance pointer. This function can
        // return NULL thus should not be used by the user. This is intended
        // for Protobuf internal code. Please use default_instance() declared
        // above instead.
        static inline const ObjectSource* internal_default_instance()
        {
            return default_instance_;
        }
#endif

        GOOGLE_ATTRIBUTE_NOINLINE void Swap(ObjectSource* other);

        // implements Message ----------------------------------------------

        inline ObjectSource* New() const { return New(NULL); }

        ObjectSource* New(::google::protobuf::Arena* arena) const;
        void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
        void CopyFrom(const ObjectSource& from);
        void MergeFrom(const ObjectSource& from);
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
        void InternalSwap(ObjectSource* other);

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

        typedef ObjectSource_Type Type;
        static const Type INTERNAL = ObjectSource_Type_INTERNAL;
        static const Type TEST = ObjectSource_Type_TEST;
        static const Type DEMO = ObjectSource_Type_DEMO;
        static const Type CHROME_SYNC = ObjectSource_Type_CHROME_SYNC;
        static const Type COSMO_CHANGELOG = ObjectSource_Type_COSMO_CHANGELOG;
        static const Type CHROME_COMPONENTS = ObjectSource_Type_CHROME_COMPONENTS;
        static const Type CHROME_PUSH_MESSAGING = ObjectSource_Type_CHROME_PUSH_MESSAGING;
        static inline bool Type_IsValid(int value)
        {
            return ObjectSource_Type_IsValid(value);
        }
        static const Type Type_MIN = ObjectSource_Type_Type_MIN;
        static const Type Type_MAX = ObjectSource_Type_Type_MAX;
        static const int Type_ARRAYSIZE = ObjectSource_Type_Type_ARRAYSIZE;

        // accessors -------------------------------------------------------

        // optional .ipc.invalidation.ObjectSource.Type type = 1;
        bool has_type() const;
        void clear_type();
        static const int kTypeFieldNumber = 1;
        ::ipc::invalidation::ObjectSource_Type type() const;
        void set_type(::ipc::invalidation::ObjectSource_Type value);

        // @@protoc_insertion_point(class_scope:ipc.invalidation.ObjectSource)
    private:
        inline void set_has_type();
        inline void clear_has_type();

        ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
        ::google::protobuf::Arena* _arena_ptr_;

        ::google::protobuf::uint32 _has_bits_[1];
        mutable int _cached_size_;
        int type_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        friend void protobuf_AddDesc_types_2eproto_impl();
#else
        friend void protobuf_AddDesc_types_2eproto();
#endif
        friend void protobuf_AssignDesc_types_2eproto();
        friend void protobuf_ShutdownFile_types_2eproto();

        void InitAsDefaultInstance();
        static ObjectSource* default_instance_;
    };
    // -------------------------------------------------------------------

    class Constants : public ::google::protobuf::MessageLite {
    public:
        Constants();
        virtual ~Constants();

        Constants(const Constants& from);

        inline Constants& operator=(const Constants& from)
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

        static const Constants& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        // Returns the internal default instance pointer. This function can
        // return NULL thus should not be used by the user. This is intended
        // for Protobuf internal code. Please use default_instance() declared
        // above instead.
        static inline const Constants* internal_default_instance()
        {
            return default_instance_;
        }
#endif

        GOOGLE_ATTRIBUTE_NOINLINE void Swap(Constants* other);

        // implements Message ----------------------------------------------

        inline Constants* New() const { return New(NULL); }

        Constants* New(::google::protobuf::Arena* arena) const;
        void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
        void CopyFrom(const Constants& from);
        void MergeFrom(const Constants& from);
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
        void InternalSwap(Constants* other);

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

        typedef Constants_ObjectVersion ObjectVersion;
        static const ObjectVersion UNKNOWN = Constants_ObjectVersion_UNKNOWN;
        static inline bool ObjectVersion_IsValid(int value)
        {
            return Constants_ObjectVersion_IsValid(value);
        }
        static const ObjectVersion ObjectVersion_MIN = Constants_ObjectVersion_ObjectVersion_MIN;
        static const ObjectVersion ObjectVersion_MAX = Constants_ObjectVersion_ObjectVersion_MAX;
        static const int ObjectVersion_ARRAYSIZE = Constants_ObjectVersion_ObjectVersion_ARRAYSIZE;

        // accessors -------------------------------------------------------

        // @@protoc_insertion_point(class_scope:ipc.invalidation.Constants)
    private:
        ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
        ::google::protobuf::Arena* _arena_ptr_;

        ::google::protobuf::uint32 _has_bits_[1];
        mutable int _cached_size_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        friend void protobuf_AddDesc_types_2eproto_impl();
#else
        friend void protobuf_AddDesc_types_2eproto();
#endif
        friend void protobuf_AssignDesc_types_2eproto();
        friend void protobuf_ShutdownFile_types_2eproto();

        void InitAsDefaultInstance();
        static Constants* default_instance_;
    };
    // ===================================================================

    // ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
    // ClientType

    // optional .ipc.invalidation.ClientType.Type type = 1;
    inline bool ClientType::has_type() const
    {
        return (_has_bits_[0] & 0x00000001u) != 0;
    }
    inline void ClientType::set_has_type()
    {
        _has_bits_[0] |= 0x00000001u;
    }
    inline void ClientType::clear_has_type()
    {
        _has_bits_[0] &= ~0x00000001u;
    }
    inline void ClientType::clear_type()
    {
        type_ = 1;
        clear_has_type();
    }
    inline ::ipc::invalidation::ClientType_Type ClientType::type() const
    {
        // @@protoc_insertion_point(field_get:ipc.invalidation.ClientType.type)
        return static_cast<::ipc::invalidation::ClientType_Type>(type_);
    }
    inline void ClientType::set_type(::ipc::invalidation::ClientType_Type value)
    {
        assert(::ipc::invalidation::ClientType_Type_IsValid(value));
        set_has_type();
        type_ = value;
        // @@protoc_insertion_point(field_set:ipc.invalidation.ClientType.type)
    }

    // -------------------------------------------------------------------

    // ObjectSource

    // optional .ipc.invalidation.ObjectSource.Type type = 1;
    inline bool ObjectSource::has_type() const
    {
        return (_has_bits_[0] & 0x00000001u) != 0;
    }
    inline void ObjectSource::set_has_type()
    {
        _has_bits_[0] |= 0x00000001u;
    }
    inline void ObjectSource::clear_has_type()
    {
        _has_bits_[0] &= ~0x00000001u;
    }
    inline void ObjectSource::clear_type()
    {
        type_ = 1;
        clear_has_type();
    }
    inline ::ipc::invalidation::ObjectSource_Type ObjectSource::type() const
    {
        // @@protoc_insertion_point(field_get:ipc.invalidation.ObjectSource.type)
        return static_cast<::ipc::invalidation::ObjectSource_Type>(type_);
    }
    inline void ObjectSource::set_type(::ipc::invalidation::ObjectSource_Type value)
    {
        assert(::ipc::invalidation::ObjectSource_Type_IsValid(value));
        set_has_type();
        type_ = value;
        // @@protoc_insertion_point(field_set:ipc.invalidation.ObjectSource.type)
    }

    // -------------------------------------------------------------------

    // Constants

#endif // !PROTOBUF_INLINE_NOT_IN_HEADERS
    // -------------------------------------------------------------------

    // -------------------------------------------------------------------

    // @@protoc_insertion_point(namespace_scope)

} // namespace invalidation
} // namespace ipc

#ifndef SWIG
namespace google {
namespace protobuf {

    template <>
    struct is_proto_enum<::ipc::invalidation::ClientType_Type> : ::google::protobuf::internal::true_type {
    };
    template <>
    struct is_proto_enum<::ipc::invalidation::ObjectSource_Type> : ::google::protobuf::internal::true_type {
    };
    template <>
    struct is_proto_enum<::ipc::invalidation::Constants_ObjectVersion> : ::google::protobuf::internal::true_type {
    };

} // namespace protobuf
} // namespace google
#endif // SWIG

// @@protoc_insertion_point(global_scope)

#endif // PROTOBUF_types_2eproto__INCLUDED
