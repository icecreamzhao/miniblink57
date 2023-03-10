// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: skregion.proto

#ifndef PROTOBUF_skregion_2eproto__INCLUDED
#define PROTOBUF_skregion_2eproto__INCLUDED

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
#include "cc/proto/cc_proto_export.h"

namespace cc {
namespace proto {

    // Internal implementation detail -- do not call these.
    void CC_PROTO_EXPORT protobuf_AddDesc_skregion_2eproto();
    void protobuf_AssignDesc_skregion_2eproto();
    void protobuf_ShutdownFile_skregion_2eproto();

    class SkRegion;

    enum SkRegion_Op {
        SkRegion_Op_DIFFERENCE_ = 0,
        SkRegion_Op_INTERSECT = 1,
        SkRegion_Op_UNION = 2,
        SkRegion_Op_XOR = 3,
        SkRegion_Op_REVERSE_DIFFERENCE = 4,
        SkRegion_Op_REPLACE = 5
    };
    CC_PROTO_EXPORT bool SkRegion_Op_IsValid(int value);
    const SkRegion_Op SkRegion_Op_Op_MIN = SkRegion_Op_DIFFERENCE_;
    const SkRegion_Op SkRegion_Op_Op_MAX = SkRegion_Op_REPLACE;
    const int SkRegion_Op_Op_ARRAYSIZE = SkRegion_Op_Op_MAX + 1;

    // ===================================================================

    class CC_PROTO_EXPORT SkRegion : public ::google::protobuf::MessageLite {
    public:
        SkRegion();
        virtual ~SkRegion();

        SkRegion(const SkRegion& from);

        inline SkRegion& operator=(const SkRegion& from)
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

        static const SkRegion& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        // Returns the internal default instance pointer. This function can
        // return NULL thus should not be used by the user. This is intended
        // for Protobuf internal code. Please use default_instance() declared
        // above instead.
        static inline const SkRegion* internal_default_instance()
        {
            return default_instance_;
        }
#endif

        GOOGLE_ATTRIBUTE_NOINLINE void Swap(SkRegion* other);

        // implements Message ----------------------------------------------

        inline SkRegion* New() const { return New(NULL); }

        SkRegion* New(::google::protobuf::Arena* arena) const;
        void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
        void CopyFrom(const SkRegion& from);
        void MergeFrom(const SkRegion& from);
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
        void InternalSwap(SkRegion* other);

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

        typedef SkRegion_Op Op;
        static const Op DIFFERENCE_ = SkRegion_Op_DIFFERENCE_;
        static const Op INTERSECT = SkRegion_Op_INTERSECT;
        static const Op UNION = SkRegion_Op_UNION;
        static const Op XOR = SkRegion_Op_XOR;
        static const Op REVERSE_DIFFERENCE = SkRegion_Op_REVERSE_DIFFERENCE;
        static const Op REPLACE = SkRegion_Op_REPLACE;
        static inline bool Op_IsValid(int value)
        {
            return SkRegion_Op_IsValid(value);
        }
        static const Op Op_MIN = SkRegion_Op_Op_MIN;
        static const Op Op_MAX = SkRegion_Op_Op_MAX;
        static const int Op_ARRAYSIZE = SkRegion_Op_Op_ARRAYSIZE;

        // accessors -------------------------------------------------------

        // @@protoc_insertion_point(class_scope:cc.proto.SkRegion)
    private:
        ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
        ::google::protobuf::Arena* _arena_ptr_;

        ::google::protobuf::uint32 _has_bits_[1];
        mutable int _cached_size_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        friend void CC_PROTO_EXPORT protobuf_AddDesc_skregion_2eproto_impl();
#else
        friend void CC_PROTO_EXPORT protobuf_AddDesc_skregion_2eproto();
#endif
        friend void protobuf_AssignDesc_skregion_2eproto();
        friend void protobuf_ShutdownFile_skregion_2eproto();

        void InitAsDefaultInstance();
        static SkRegion* default_instance_;
    };
    // ===================================================================

    // ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
    // SkRegion

#endif // !PROTOBUF_INLINE_NOT_IN_HEADERS

    // @@protoc_insertion_point(namespace_scope)

} // namespace proto
} // namespace cc

#ifndef SWIG
namespace google {
namespace protobuf {

    template <>
    struct is_proto_enum<::cc::proto::SkRegion_Op> : ::google::protobuf::internal::true_type {
    };

} // namespace protobuf
} // namespace google
#endif // SWIG

// @@protoc_insertion_point(global_scope)

#endif // PROTOBUF_skregion_2eproto__INCLUDED
