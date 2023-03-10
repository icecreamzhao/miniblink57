// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: pointf.proto

#ifndef PROTOBUF_pointf_2eproto__INCLUDED
#define PROTOBUF_pointf_2eproto__INCLUDED

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
#include "cc/proto/cc_proto_export.h"

namespace cc {
namespace proto {

    // Internal implementation detail -- do not call these.
    void CC_PROTO_EXPORT protobuf_AddDesc_pointf_2eproto();
    void protobuf_AssignDesc_pointf_2eproto();
    void protobuf_ShutdownFile_pointf_2eproto();

    class PointF;

    // ===================================================================

    class CC_PROTO_EXPORT PointF : public ::google::protobuf::MessageLite {
    public:
        PointF();
        virtual ~PointF();

        PointF(const PointF& from);

        inline PointF& operator=(const PointF& from)
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

        static const PointF& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        // Returns the internal default instance pointer. This function can
        // return NULL thus should not be used by the user. This is intended
        // for Protobuf internal code. Please use default_instance() declared
        // above instead.
        static inline const PointF* internal_default_instance()
        {
            return default_instance_;
        }
#endif

        GOOGLE_ATTRIBUTE_NOINLINE void Swap(PointF* other);

        // implements Message ----------------------------------------------

        inline PointF* New() const { return New(NULL); }

        PointF* New(::google::protobuf::Arena* arena) const;
        void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
        void CopyFrom(const PointF& from);
        void MergeFrom(const PointF& from);
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
        void InternalSwap(PointF* other);

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

        // optional float x = 1;
        bool has_x() const;
        void clear_x();
        static const int kXFieldNumber = 1;
        float x() const;
        void set_x(float value);

        // optional float y = 2;
        bool has_y() const;
        void clear_y();
        static const int kYFieldNumber = 2;
        float y() const;
        void set_y(float value);

        // @@protoc_insertion_point(class_scope:cc.proto.PointF)
    private:
        inline void set_has_x();
        inline void clear_has_x();
        inline void set_has_y();
        inline void clear_has_y();

        ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
        ::google::protobuf::Arena* _arena_ptr_;

        ::google::protobuf::uint32 _has_bits_[1];
        mutable int _cached_size_;
        float x_;
        float y_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        friend void CC_PROTO_EXPORT protobuf_AddDesc_pointf_2eproto_impl();
#else
        friend void CC_PROTO_EXPORT protobuf_AddDesc_pointf_2eproto();
#endif
        friend void protobuf_AssignDesc_pointf_2eproto();
        friend void protobuf_ShutdownFile_pointf_2eproto();

        void InitAsDefaultInstance();
        static PointF* default_instance_;
    };
    // ===================================================================

    // ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
    // PointF

    // optional float x = 1;
    inline bool PointF::has_x() const
    {
        return (_has_bits_[0] & 0x00000001u) != 0;
    }
    inline void PointF::set_has_x()
    {
        _has_bits_[0] |= 0x00000001u;
    }
    inline void PointF::clear_has_x()
    {
        _has_bits_[0] &= ~0x00000001u;
    }
    inline void PointF::clear_x()
    {
        x_ = 0;
        clear_has_x();
    }
    inline float PointF::x() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.PointF.x)
        return x_;
    }
    inline void PointF::set_x(float value)
    {
        set_has_x();
        x_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.PointF.x)
    }

    // optional float y = 2;
    inline bool PointF::has_y() const
    {
        return (_has_bits_[0] & 0x00000002u) != 0;
    }
    inline void PointF::set_has_y()
    {
        _has_bits_[0] |= 0x00000002u;
    }
    inline void PointF::clear_has_y()
    {
        _has_bits_[0] &= ~0x00000002u;
    }
    inline void PointF::clear_y()
    {
        y_ = 0;
        clear_has_y();
    }
    inline float PointF::y() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.PointF.y)
        return y_;
    }
    inline void PointF::set_y(float value)
    {
        set_has_y();
        y_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.PointF.y)
    }

#endif // !PROTOBUF_INLINE_NOT_IN_HEADERS

    // @@protoc_insertion_point(namespace_scope)

} // namespace proto
} // namespace cc

// @@protoc_insertion_point(global_scope)

#endif // PROTOBUF_pointf_2eproto__INCLUDED
