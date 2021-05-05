// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: region.proto

#ifndef PROTOBUF_region_2eproto__INCLUDED
#define PROTOBUF_region_2eproto__INCLUDED

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

#include "rect.pb.h"
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
    void CC_PROTO_EXPORT protobuf_AddDesc_region_2eproto();
    void protobuf_AssignDesc_region_2eproto();
    void protobuf_ShutdownFile_region_2eproto();

    class Region;

    // ===================================================================

    class CC_PROTO_EXPORT Region : public ::google::protobuf::MessageLite {
    public:
        Region();
        virtual ~Region();

        Region(const Region& from);

        inline Region& operator=(const Region& from)
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

        static const Region& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        // Returns the internal default instance pointer. This function can
        // return NULL thus should not be used by the user. This is intended
        // for Protobuf internal code. Please use default_instance() declared
        // above instead.
        static inline const Region* internal_default_instance()
        {
            return default_instance_;
        }
#endif

        GOOGLE_ATTRIBUTE_NOINLINE void Swap(Region* other);

        // implements Message ----------------------------------------------

        inline Region* New() const { return New(NULL); }

        Region* New(::google::protobuf::Arena* arena) const;
        void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
        void CopyFrom(const Region& from);
        void MergeFrom(const Region& from);
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
        void InternalSwap(Region* other);

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

        // repeated .cc.proto.Rect rects = 1;
        int rects_size() const;
        void clear_rects();
        static const int kRectsFieldNumber = 1;
        const ::cc::proto::Rect& rects(int index) const;
        ::cc::proto::Rect* mutable_rects(int index);
        ::cc::proto::Rect* add_rects();
        ::google::protobuf::RepeatedPtrField<::cc::proto::Rect>*
        mutable_rects();
        const ::google::protobuf::RepeatedPtrField<::cc::proto::Rect>&
        rects() const;

        // @@protoc_insertion_point(class_scope:cc.proto.Region)
    private:
        ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
        ::google::protobuf::Arena* _arena_ptr_;

        ::google::protobuf::uint32 _has_bits_[1];
        mutable int _cached_size_;
        ::google::protobuf::RepeatedPtrField<::cc::proto::Rect> rects_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        friend void CC_PROTO_EXPORT protobuf_AddDesc_region_2eproto_impl();
#else
        friend void CC_PROTO_EXPORT protobuf_AddDesc_region_2eproto();
#endif
        friend void protobuf_AssignDesc_region_2eproto();
        friend void protobuf_ShutdownFile_region_2eproto();

        void InitAsDefaultInstance();
        static Region* default_instance_;
    };
    // ===================================================================

    // ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
    // Region

    // repeated .cc.proto.Rect rects = 1;
    inline int Region::rects_size() const
    {
        return rects_.size();
    }
    inline void Region::clear_rects()
    {
        rects_.Clear();
    }
    inline const ::cc::proto::Rect& Region::rects(int index) const
    {
        // @@protoc_insertion_point(field_get:cc.proto.Region.rects)
        return rects_.Get(index);
    }
    inline ::cc::proto::Rect* Region::mutable_rects(int index)
    {
        // @@protoc_insertion_point(field_mutable:cc.proto.Region.rects)
        return rects_.Mutable(index);
    }
    inline ::cc::proto::Rect* Region::add_rects()
    {
        // @@protoc_insertion_point(field_add:cc.proto.Region.rects)
        return rects_.Add();
    }
    inline ::google::protobuf::RepeatedPtrField<::cc::proto::Rect>*
    Region::mutable_rects()
    {
        // @@protoc_insertion_point(field_mutable_list:cc.proto.Region.rects)
        return &rects_;
    }
    inline const ::google::protobuf::RepeatedPtrField<::cc::proto::Rect>&
    Region::rects() const
    {
        // @@protoc_insertion_point(field_list:cc.proto.Region.rects)
        return rects_;
    }

#endif // !PROTOBUF_INLINE_NOT_IN_HEADERS

    // @@protoc_insertion_point(namespace_scope)

} // namespace proto
} // namespace cc

// @@protoc_insertion_point(global_scope)

#endif // PROTOBUF_region_2eproto__INCLUDED
