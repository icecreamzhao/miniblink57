// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: skregion.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "skregion.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

namespace cc {
namespace proto {

    void protobuf_ShutdownFile_skregion_2eproto()
    {
        delete SkRegion::default_instance_;
    }

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    void protobuf_AddDesc_skregion_2eproto_impl()
    {
        GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
    void protobuf_AddDesc_skregion_2eproto()
    {
        static bool already_here = false;
        if (already_here)
            return;
        already_here = true;
        GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
        SkRegion::default_instance_ = new SkRegion();
        SkRegion::default_instance_->InitAsDefaultInstance();
        ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_skregion_2eproto);
    }

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_skregion_2eproto_once_);
    void protobuf_AddDesc_skregion_2eproto()
    {
        ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_skregion_2eproto_once_,
            &protobuf_AddDesc_skregion_2eproto_impl);
    }
#else
    // Force AddDescriptors() to be called at static initialization time.
    struct StaticDescriptorInitializer_skregion_2eproto {
        StaticDescriptorInitializer_skregion_2eproto()
        {
            protobuf_AddDesc_skregion_2eproto();
        }
    } static_descriptor_initializer_skregion_2eproto_;
#endif

    namespace {

        static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
        GOOGLE_ATTRIBUTE_NOINLINE static void MergeFromFail(int line)
        {
            GOOGLE_CHECK(false) << __FILE__ << ":" << line;
        }

    } // namespace

    // ===================================================================

    static ::std::string* MutableUnknownFieldsForSkRegion(
        SkRegion* ptr)
    {
        return ptr->mutable_unknown_fields();
    }

    bool SkRegion_Op_IsValid(int value)
    {
        switch (value) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return true;
        default:
            return false;
        }
    }

#if !defined(_MSC_VER) || _MSC_VER >= 1900
    const SkRegion_Op SkRegion::DIFFERENCE_;
    const SkRegion_Op SkRegion::INTERSECT;
    const SkRegion_Op SkRegion::UNION;
    const SkRegion_Op SkRegion::XOR;
    const SkRegion_Op SkRegion::REVERSE_DIFFERENCE;
    const SkRegion_Op SkRegion::REPLACE;
    const SkRegion_Op SkRegion::Op_MIN;
    const SkRegion_Op SkRegion::Op_MAX;
    const int SkRegion::Op_ARRAYSIZE;
#endif // !defined(_MSC_VER) || _MSC_VER >= 1900
#if !defined(_MSC_VER) || _MSC_VER >= 1900
#endif // !defined(_MSC_VER) || _MSC_VER >= 1900

    SkRegion::SkRegion()
        : ::google::protobuf::MessageLite()
        , _arena_ptr_(NULL)
    {
        SharedCtor();
        // @@protoc_insertion_point(constructor:cc.proto.SkRegion)
    }

    void SkRegion::InitAsDefaultInstance()
    {
    }

    SkRegion::SkRegion(const SkRegion& from)
        : ::google::protobuf::MessageLite()
        , _arena_ptr_(NULL)
    {
        SharedCtor();
        MergeFrom(from);
        // @@protoc_insertion_point(copy_constructor:cc.proto.SkRegion)
    }

    void SkRegion::SharedCtor()
    {
        ::google::protobuf::internal::GetEmptyString();
        _cached_size_ = 0;
        _unknown_fields_.UnsafeSetDefault(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
        ::memset(_has_bits_, 0, sizeof(_has_bits_));
    }

    SkRegion::~SkRegion()
    {
        // @@protoc_insertion_point(destructor:cc.proto.SkRegion)
        SharedDtor();
    }

    void SkRegion::SharedDtor()
    {
        _unknown_fields_.DestroyNoArena(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        if (this != &default_instance()) {
#else
        if (this != default_instance_) {
#endif
        }
    }

    void SkRegion::SetCachedSize(int size) const
    {
        GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
        _cached_size_ = size;
        GOOGLE_SAFE_CONCURRENT_WRITES_END();
    }
    const SkRegion& SkRegion::default_instance()
    {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        protobuf_AddDesc_skregion_2eproto();
#else
        if (default_instance_ == NULL)
            protobuf_AddDesc_skregion_2eproto();
#endif
        return *default_instance_;
    }

    SkRegion* SkRegion::default_instance_ = NULL;

    SkRegion* SkRegion::New(::google::protobuf::Arena* arena) const
    {
        SkRegion* n = new SkRegion;
        if (arena != NULL) {
            arena->Own(n);
        }
        return n;
    }

    void SkRegion::Clear()
    {
        // @@protoc_insertion_point(message_clear_start:cc.proto.SkRegion)
        ::memset(_has_bits_, 0, sizeof(_has_bits_));
        _unknown_fields_.ClearToEmptyNoArena(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    }

    bool SkRegion::MergePartialFromCodedStream(
        ::google::protobuf::io::CodedInputStream* input)
    {
#define DO_(EXPRESSION)                   \
    if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) \
    goto failure
        ::google::protobuf::uint32 tag;
        ::google::protobuf::io::LazyStringOutputStream unknown_fields_string(
            ::google::protobuf::internal::NewPermanentCallback(
                &MutableUnknownFieldsForSkRegion, this));
        ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
            &unknown_fields_string, false);
        // @@protoc_insertion_point(parse_start:cc.proto.SkRegion)
        for (;;) {
            ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
            tag = p.first;
            if (!p.second)
                goto handle_unusual;
        handle_unusual:
            if (tag == 0 || ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) == ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
                goto success;
            }
            DO_(::google::protobuf::internal::WireFormatLite::SkipField(
                input, tag, &unknown_fields_stream));
        }
    success:
        // @@protoc_insertion_point(parse_success:cc.proto.SkRegion)
        return true;
    failure:
        // @@protoc_insertion_point(parse_failure:cc.proto.SkRegion)
        return false;
#undef DO_
    }

    void SkRegion::SerializeWithCachedSizes(
        ::google::protobuf::io::CodedOutputStream* output) const
    {
        // @@protoc_insertion_point(serialize_start:cc.proto.SkRegion)
        output->WriteRaw(unknown_fields().data(),
            static_cast<int>(unknown_fields().size()));
        // @@protoc_insertion_point(serialize_end:cc.proto.SkRegion)
    }

    int SkRegion::ByteSize() const
    {
        // @@protoc_insertion_point(message_byte_size_start:cc.proto.SkRegion)
        int total_size = 0;

        total_size += unknown_fields().size();

        GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
        _cached_size_ = total_size;
        GOOGLE_SAFE_CONCURRENT_WRITES_END();
        return total_size;
    }

    void SkRegion::CheckTypeAndMergeFrom(
        const ::google::protobuf::MessageLite& from)
    {
        MergeFrom(*::google::protobuf::down_cast<const SkRegion*>(&from));
    }

    void SkRegion::MergeFrom(const SkRegion& from)
    {
        // @@protoc_insertion_point(class_specific_merge_from_start:cc.proto.SkRegion)
        if (GOOGLE_PREDICT_FALSE(&from == this))
            MergeFromFail(__LINE__);
        if (!from.unknown_fields().empty()) {
            mutable_unknown_fields()->append(from.unknown_fields());
        }
    }

    void SkRegion::CopyFrom(const SkRegion& from)
    {
        // @@protoc_insertion_point(class_specific_copy_from_start:cc.proto.SkRegion)
        if (&from == this)
            return;
        Clear();
        MergeFrom(from);
    }

    bool SkRegion::IsInitialized() const
    {

        return true;
    }

    void SkRegion::Swap(SkRegion* other)
    {
        if (other == this)
            return;
        InternalSwap(other);
    }
    void SkRegion::InternalSwap(SkRegion* other)
    {
        _unknown_fields_.Swap(&other->_unknown_fields_);
        std::swap(_cached_size_, other->_cached_size_);
    }

    ::std::string SkRegion::GetTypeName() const
    {
        return "cc.proto.SkRegion";
    }

#if PROTOBUF_INLINE_NOT_IN_HEADERS
    // SkRegion

#endif // PROTOBUF_INLINE_NOT_IN_HEADERS

    // @@protoc_insertion_point(namespace_scope)

} // namespace proto
} // namespace cc

// @@protoc_insertion_point(global_scope)
