// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: histogram_event.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "histogram_event.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

namespace metrics {

void protobuf_ShutdownFile_histogram_5fevent_2eproto()
{
    delete HistogramEventProto::default_instance_;
    delete HistogramEventProto_Bucket::default_instance_;
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
void protobuf_AddDesc_histogram_5fevent_2eproto_impl()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
void protobuf_AddDesc_histogram_5fevent_2eproto()
{
    static bool already_here = false;
    if (already_here)
        return;
    already_here = true;
    GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
    HistogramEventProto::default_instance_ = new HistogramEventProto();
    HistogramEventProto_Bucket::default_instance_ = new HistogramEventProto_Bucket();
    HistogramEventProto::default_instance_->InitAsDefaultInstance();
    HistogramEventProto_Bucket::default_instance_->InitAsDefaultInstance();
    ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_histogram_5fevent_2eproto);
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_histogram_5fevent_2eproto_once_);
void protobuf_AddDesc_histogram_5fevent_2eproto()
{
    ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_histogram_5fevent_2eproto_once_,
        &protobuf_AddDesc_histogram_5fevent_2eproto_impl);
}
#else
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_histogram_5fevent_2eproto {
    StaticDescriptorInitializer_histogram_5fevent_2eproto()
    {
        protobuf_AddDesc_histogram_5fevent_2eproto();
    }
} static_descriptor_initializer_histogram_5fevent_2eproto_;
#endif

namespace {

    static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
    GOOGLE_ATTRIBUTE_NOINLINE static void MergeFromFail(int line)
    {
        GOOGLE_CHECK(false) << __FILE__ << ":" << line;
    }

} // namespace

// ===================================================================

static ::std::string* MutableUnknownFieldsForHistogramEventProto(
    HistogramEventProto* ptr)
{
    return ptr->mutable_unknown_fields();
}

static ::std::string* MutableUnknownFieldsForHistogramEventProto_Bucket(
    HistogramEventProto_Bucket* ptr)
{
    return ptr->mutable_unknown_fields();
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int HistogramEventProto_Bucket::kMinFieldNumber;
const int HistogramEventProto_Bucket::kMaxFieldNumber;
const int HistogramEventProto_Bucket::kBucketIndexFieldNumber;
const int HistogramEventProto_Bucket::kCountFieldNumber;
#endif // !defined(_MSC_VER) || _MSC_VER >= 1900

HistogramEventProto_Bucket::HistogramEventProto_Bucket()
    : ::google::protobuf::MessageLite()
    , _arena_ptr_(NULL)
{
    SharedCtor();
    // @@protoc_insertion_point(constructor:metrics.HistogramEventProto.Bucket)
}

void HistogramEventProto_Bucket::InitAsDefaultInstance()
{
}

HistogramEventProto_Bucket::HistogramEventProto_Bucket(const HistogramEventProto_Bucket& from)
    : ::google::protobuf::MessageLite()
    , _arena_ptr_(NULL)
{
    SharedCtor();
    MergeFrom(from);
    // @@protoc_insertion_point(copy_constructor:metrics.HistogramEventProto.Bucket)
}

void HistogramEventProto_Bucket::SharedCtor()
{
    ::google::protobuf::internal::GetEmptyString();
    _cached_size_ = 0;
    _unknown_fields_.UnsafeSetDefault(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    min_ = GOOGLE_LONGLONG(0);
    max_ = GOOGLE_LONGLONG(0);
    bucket_index_ = 0;
    count_ = GOOGLE_LONGLONG(1);
    ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HistogramEventProto_Bucket::~HistogramEventProto_Bucket()
{
    // @@protoc_insertion_point(destructor:metrics.HistogramEventProto.Bucket)
    SharedDtor();
}

void HistogramEventProto_Bucket::SharedDtor()
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

void HistogramEventProto_Bucket::SetCachedSize(int size) const
{
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _cached_size_ = size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const HistogramEventProto_Bucket& HistogramEventProto_Bucket::default_instance()
{
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    protobuf_AddDesc_histogram_5fevent_2eproto();
#else
    if (default_instance_ == NULL)
        protobuf_AddDesc_histogram_5fevent_2eproto();
#endif
    return *default_instance_;
}

HistogramEventProto_Bucket* HistogramEventProto_Bucket::default_instance_ = NULL;

HistogramEventProto_Bucket* HistogramEventProto_Bucket::New(::google::protobuf::Arena* arena) const
{
    HistogramEventProto_Bucket* n = new HistogramEventProto_Bucket;
    if (arena != NULL) {
        arena->Own(n);
    }
    return n;
}

void HistogramEventProto_Bucket::Clear()
{
// @@protoc_insertion_point(message_clear_start:metrics.HistogramEventProto.Bucket)
#if defined(__clang__)
#define ZR_HELPER_(f)                                                                                                \
    _Pragma("clang diagnostic push")                                                                                 \
        _Pragma("clang diagnostic ignored \"-Winvalid-offsetof\"") __builtin_offsetof(HistogramEventProto_Bucket, f) \
            _Pragma("clang diagnostic pop")
#else
#define ZR_HELPER_(f) reinterpret_cast<char*>( \
    &reinterpret_cast<HistogramEventProto_Bucket*>(16)->f)
#endif

#define ZR_(first, last)                                          \
    do {                                                          \
        ::memset(&first, 0,                                       \
            ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last)); \
    } while (0)

    if (_has_bits_[0 / 32] & 15u) {
        ZR_(min_, max_);
        bucket_index_ = 0;
        count_ = GOOGLE_LONGLONG(1);
    }

#undef ZR_HELPER_
#undef ZR_

    ::memset(_has_bits_, 0, sizeof(_has_bits_));
    _unknown_fields_.ClearToEmptyNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool HistogramEventProto_Bucket::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input)
{
#define DO_(EXPRESSION)                   \
    if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) \
    goto failure
    ::google::protobuf::uint32 tag;
    ::google::protobuf::io::LazyStringOutputStream unknown_fields_string(
        ::google::protobuf::internal::NewPermanentCallback(
            &MutableUnknownFieldsForHistogramEventProto_Bucket, this));
    ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
        &unknown_fields_string, false);
    // @@protoc_insertion_point(parse_start:metrics.HistogramEventProto.Bucket)
    for (;;) {
        ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
        tag = p.first;
        if (!p.second)
            goto handle_unusual;
        switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
        // optional int64 min = 1;
        case 1: {
            if (tag == 8) {
                DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                    ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                    input, &min_)));
                set_has_min();
            } else {
                goto handle_unusual;
            }
            if (input->ExpectTag(16))
                goto parse_max;
            break;
        }

        // optional int64 max = 2;
        case 2: {
            if (tag == 16) {
            parse_max:
                DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                    ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                    input, &max_)));
                set_has_max();
            } else {
                goto handle_unusual;
            }
            if (input->ExpectTag(24))
                goto parse_bucket_index;
            break;
        }

        // optional int32 bucket_index = 3 [deprecated = true];
        case 3: {
            if (tag == 24) {
            parse_bucket_index:
                DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                    ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                    input, &bucket_index_)));
                set_has_bucket_index();
            } else {
                goto handle_unusual;
            }
            if (input->ExpectTag(32))
                goto parse_count;
            break;
        }

        // optional int64 count = 4 [default = 1];
        case 4: {
            if (tag == 32) {
            parse_count:
                DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                    ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                    input, &count_)));
                set_has_count();
            } else {
                goto handle_unusual;
            }
            if (input->ExpectAtEnd())
                goto success;
            break;
        }

        default: {
        handle_unusual:
            if (tag == 0 || ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) == ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
                goto success;
            }
            DO_(::google::protobuf::internal::WireFormatLite::SkipField(
                input, tag, &unknown_fields_stream));
            break;
        }
        }
    }
success:
    // @@protoc_insertion_point(parse_success:metrics.HistogramEventProto.Bucket)
    return true;
failure:
    // @@protoc_insertion_point(parse_failure:metrics.HistogramEventProto.Bucket)
    return false;
#undef DO_
}

void HistogramEventProto_Bucket::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const
{
    // @@protoc_insertion_point(serialize_start:metrics.HistogramEventProto.Bucket)
    // optional int64 min = 1;
    if (has_min()) {
        ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->min(), output);
    }

    // optional int64 max = 2;
    if (has_max()) {
        ::google::protobuf::internal::WireFormatLite::WriteInt64(2, this->max(), output);
    }

    // optional int32 bucket_index = 3 [deprecated = true];
    if (has_bucket_index()) {
        ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->bucket_index(), output);
    }

    // optional int64 count = 4 [default = 1];
    if (has_count()) {
        ::google::protobuf::internal::WireFormatLite::WriteInt64(4, this->count(), output);
    }

    output->WriteRaw(unknown_fields().data(),
        static_cast<int>(unknown_fields().size()));
    // @@protoc_insertion_point(serialize_end:metrics.HistogramEventProto.Bucket)
}

int HistogramEventProto_Bucket::ByteSize() const
{
    // @@protoc_insertion_point(message_byte_size_start:metrics.HistogramEventProto.Bucket)
    int total_size = 0;

    if (_has_bits_[0 / 32] & 15u) {
        // optional int64 min = 1;
        if (has_min()) {
            total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int64Size(this->min());
        }

        // optional int64 max = 2;
        if (has_max()) {
            total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int64Size(this->max());
        }

        // optional int32 bucket_index = 3 [deprecated = true];
        if (has_bucket_index()) {
            total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(this->bucket_index());
        }

        // optional int64 count = 4 [default = 1];
        if (has_count()) {
            total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int64Size(this->count());
        }
    }
    total_size += unknown_fields().size();

    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _cached_size_ = total_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    return total_size;
}

void HistogramEventProto_Bucket::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from)
{
    MergeFrom(*::google::protobuf::down_cast<const HistogramEventProto_Bucket*>(&from));
}

void HistogramEventProto_Bucket::MergeFrom(const HistogramEventProto_Bucket& from)
{
    // @@protoc_insertion_point(class_specific_merge_from_start:metrics.HistogramEventProto.Bucket)
    if (GOOGLE_PREDICT_FALSE(&from == this))
        MergeFromFail(__LINE__);
    if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
        if (from.has_min()) {
            set_min(from.min());
        }
        if (from.has_max()) {
            set_max(from.max());
        }
        if (from.has_bucket_index()) {
            set_bucket_index(from.bucket_index());
        }
        if (from.has_count()) {
            set_count(from.count());
        }
    }
    if (!from.unknown_fields().empty()) {
        mutable_unknown_fields()->append(from.unknown_fields());
    }
}

void HistogramEventProto_Bucket::CopyFrom(const HistogramEventProto_Bucket& from)
{
    // @@protoc_insertion_point(class_specific_copy_from_start:metrics.HistogramEventProto.Bucket)
    if (&from == this)
        return;
    Clear();
    MergeFrom(from);
}

bool HistogramEventProto_Bucket::IsInitialized() const
{

    return true;
}

void HistogramEventProto_Bucket::Swap(HistogramEventProto_Bucket* other)
{
    if (other == this)
        return;
    InternalSwap(other);
}
void HistogramEventProto_Bucket::InternalSwap(HistogramEventProto_Bucket* other)
{
    std::swap(min_, other->min_);
    std::swap(max_, other->max_);
    std::swap(bucket_index_, other->bucket_index_);
    std::swap(count_, other->count_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
}

::std::string HistogramEventProto_Bucket::GetTypeName() const
{
    return "metrics.HistogramEventProto.Bucket";
}

// -------------------------------------------------------------------

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int HistogramEventProto::kNameHashFieldNumber;
const int HistogramEventProto::kSumFieldNumber;
const int HistogramEventProto::kBucketFieldNumber;
#endif // !defined(_MSC_VER) || _MSC_VER >= 1900

HistogramEventProto::HistogramEventProto()
    : ::google::protobuf::MessageLite()
    , _arena_ptr_(NULL)
{
    SharedCtor();
    // @@protoc_insertion_point(constructor:metrics.HistogramEventProto)
}

void HistogramEventProto::InitAsDefaultInstance()
{
}

HistogramEventProto::HistogramEventProto(const HistogramEventProto& from)
    : ::google::protobuf::MessageLite()
    , _arena_ptr_(NULL)
{
    SharedCtor();
    MergeFrom(from);
    // @@protoc_insertion_point(copy_constructor:metrics.HistogramEventProto)
}

void HistogramEventProto::SharedCtor()
{
    ::google::protobuf::internal::GetEmptyString();
    _cached_size_ = 0;
    _unknown_fields_.UnsafeSetDefault(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    name_hash_ = GOOGLE_ULONGLONG(0);
    sum_ = GOOGLE_LONGLONG(0);
    ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HistogramEventProto::~HistogramEventProto()
{
    // @@protoc_insertion_point(destructor:metrics.HistogramEventProto)
    SharedDtor();
}

void HistogramEventProto::SharedDtor()
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

void HistogramEventProto::SetCachedSize(int size) const
{
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _cached_size_ = size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const HistogramEventProto& HistogramEventProto::default_instance()
{
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    protobuf_AddDesc_histogram_5fevent_2eproto();
#else
    if (default_instance_ == NULL)
        protobuf_AddDesc_histogram_5fevent_2eproto();
#endif
    return *default_instance_;
}

HistogramEventProto* HistogramEventProto::default_instance_ = NULL;

HistogramEventProto* HistogramEventProto::New(::google::protobuf::Arena* arena) const
{
    HistogramEventProto* n = new HistogramEventProto;
    if (arena != NULL) {
        arena->Own(n);
    }
    return n;
}

void HistogramEventProto::Clear()
{
// @@protoc_insertion_point(message_clear_start:metrics.HistogramEventProto)
#if defined(__clang__)
#define ZR_HELPER_(f)                                                                                         \
    _Pragma("clang diagnostic push")                                                                          \
        _Pragma("clang diagnostic ignored \"-Winvalid-offsetof\"") __builtin_offsetof(HistogramEventProto, f) \
            _Pragma("clang diagnostic pop")
#else
#define ZR_HELPER_(f) reinterpret_cast<char*>( \
    &reinterpret_cast<HistogramEventProto*>(16)->f)
#endif

#define ZR_(first, last)                                          \
    do {                                                          \
        ::memset(&first, 0,                                       \
            ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last)); \
    } while (0)

    ZR_(name_hash_, sum_);

#undef ZR_HELPER_
#undef ZR_

    bucket_.Clear();
    ::memset(_has_bits_, 0, sizeof(_has_bits_));
    _unknown_fields_.ClearToEmptyNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool HistogramEventProto::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input)
{
#define DO_(EXPRESSION)                   \
    if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) \
    goto failure
    ::google::protobuf::uint32 tag;
    ::google::protobuf::io::LazyStringOutputStream unknown_fields_string(
        ::google::protobuf::internal::NewPermanentCallback(
            &MutableUnknownFieldsForHistogramEventProto, this));
    ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
        &unknown_fields_string, false);
    // @@protoc_insertion_point(parse_start:metrics.HistogramEventProto)
    for (;;) {
        ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
        tag = p.first;
        if (!p.second)
            goto handle_unusual;
        switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
        // optional fixed64 name_hash = 1;
        case 1: {
            if (tag == 9) {
                DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                    ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
                    input, &name_hash_)));
                set_has_name_hash();
            } else {
                goto handle_unusual;
            }
            if (input->ExpectTag(16))
                goto parse_sum;
            break;
        }

        // optional int64 sum = 2;
        case 2: {
            if (tag == 16) {
            parse_sum:
                DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                    ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                    input, &sum_)));
                set_has_sum();
            } else {
                goto handle_unusual;
            }
            if (input->ExpectTag(26))
                goto parse_bucket;
            break;
        }

        // repeated .metrics.HistogramEventProto.Bucket bucket = 3;
        case 3: {
            if (tag == 26) {
            parse_bucket:
                DO_(input->IncrementRecursionDepth());
            parse_loop_bucket:
                DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                    input, add_bucket()));
            } else {
                goto handle_unusual;
            }
            if (input->ExpectTag(26))
                goto parse_loop_bucket;
            input->UnsafeDecrementRecursionDepth();
            if (input->ExpectAtEnd())
                goto success;
            break;
        }

        default: {
        handle_unusual:
            if (tag == 0 || ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) == ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
                goto success;
            }
            DO_(::google::protobuf::internal::WireFormatLite::SkipField(
                input, tag, &unknown_fields_stream));
            break;
        }
        }
    }
success:
    // @@protoc_insertion_point(parse_success:metrics.HistogramEventProto)
    return true;
failure:
    // @@protoc_insertion_point(parse_failure:metrics.HistogramEventProto)
    return false;
#undef DO_
}

void HistogramEventProto::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const
{
    // @@protoc_insertion_point(serialize_start:metrics.HistogramEventProto)
    // optional fixed64 name_hash = 1;
    if (has_name_hash()) {
        ::google::protobuf::internal::WireFormatLite::WriteFixed64(1, this->name_hash(), output);
    }

    // optional int64 sum = 2;
    if (has_sum()) {
        ::google::protobuf::internal::WireFormatLite::WriteInt64(2, this->sum(), output);
    }

    // repeated .metrics.HistogramEventProto.Bucket bucket = 3;
    for (unsigned int i = 0, n = this->bucket_size(); i < n; i++) {
        ::google::protobuf::internal::WireFormatLite::WriteMessage(
            3, this->bucket(i), output);
    }

    output->WriteRaw(unknown_fields().data(),
        static_cast<int>(unknown_fields().size()));
    // @@protoc_insertion_point(serialize_end:metrics.HistogramEventProto)
}

int HistogramEventProto::ByteSize() const
{
    // @@protoc_insertion_point(message_byte_size_start:metrics.HistogramEventProto)
    int total_size = 0;

    if (_has_bits_[0 / 32] & 3u) {
        // optional fixed64 name_hash = 1;
        if (has_name_hash()) {
            total_size += 1 + 8;
        }

        // optional int64 sum = 2;
        if (has_sum()) {
            total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int64Size(this->sum());
        }
    }
    // repeated .metrics.HistogramEventProto.Bucket bucket = 3;
    total_size += 1 * this->bucket_size();
    for (int i = 0; i < this->bucket_size(); i++) {
        total_size += ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
            this->bucket(i));
    }

    total_size += unknown_fields().size();

    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _cached_size_ = total_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    return total_size;
}

void HistogramEventProto::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from)
{
    MergeFrom(*::google::protobuf::down_cast<const HistogramEventProto*>(&from));
}

void HistogramEventProto::MergeFrom(const HistogramEventProto& from)
{
    // @@protoc_insertion_point(class_specific_merge_from_start:metrics.HistogramEventProto)
    if (GOOGLE_PREDICT_FALSE(&from == this))
        MergeFromFail(__LINE__);
    bucket_.MergeFrom(from.bucket_);
    if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
        if (from.has_name_hash()) {
            set_name_hash(from.name_hash());
        }
        if (from.has_sum()) {
            set_sum(from.sum());
        }
    }
    if (!from.unknown_fields().empty()) {
        mutable_unknown_fields()->append(from.unknown_fields());
    }
}

void HistogramEventProto::CopyFrom(const HistogramEventProto& from)
{
    // @@protoc_insertion_point(class_specific_copy_from_start:metrics.HistogramEventProto)
    if (&from == this)
        return;
    Clear();
    MergeFrom(from);
}

bool HistogramEventProto::IsInitialized() const
{

    return true;
}

void HistogramEventProto::Swap(HistogramEventProto* other)
{
    if (other == this)
        return;
    InternalSwap(other);
}
void HistogramEventProto::InternalSwap(HistogramEventProto* other)
{
    std::swap(name_hash_, other->name_hash_);
    std::swap(sum_, other->sum_);
    bucket_.UnsafeArenaSwap(&other->bucket_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
}

::std::string HistogramEventProto::GetTypeName() const
{
    return "metrics.HistogramEventProto";
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// HistogramEventProto_Bucket

// optional int64 min = 1;
bool HistogramEventProto_Bucket::has_min() const
{
    return (_has_bits_[0] & 0x00000001u) != 0;
}
void HistogramEventProto_Bucket::set_has_min()
{
    _has_bits_[0] |= 0x00000001u;
}
void HistogramEventProto_Bucket::clear_has_min()
{
    _has_bits_[0] &= ~0x00000001u;
}
void HistogramEventProto_Bucket::clear_min()
{
    min_ = GOOGLE_LONGLONG(0);
    clear_has_min();
}
::google::protobuf::int64 HistogramEventProto_Bucket::min() const
{
    // @@protoc_insertion_point(field_get:metrics.HistogramEventProto.Bucket.min)
    return min_;
}
void HistogramEventProto_Bucket::set_min(::google::protobuf::int64 value)
{
    set_has_min();
    min_ = value;
    // @@protoc_insertion_point(field_set:metrics.HistogramEventProto.Bucket.min)
}

// optional int64 max = 2;
bool HistogramEventProto_Bucket::has_max() const
{
    return (_has_bits_[0] & 0x00000002u) != 0;
}
void HistogramEventProto_Bucket::set_has_max()
{
    _has_bits_[0] |= 0x00000002u;
}
void HistogramEventProto_Bucket::clear_has_max()
{
    _has_bits_[0] &= ~0x00000002u;
}
void HistogramEventProto_Bucket::clear_max()
{
    max_ = GOOGLE_LONGLONG(0);
    clear_has_max();
}
::google::protobuf::int64 HistogramEventProto_Bucket::max() const
{
    // @@protoc_insertion_point(field_get:metrics.HistogramEventProto.Bucket.max)
    return max_;
}
void HistogramEventProto_Bucket::set_max(::google::protobuf::int64 value)
{
    set_has_max();
    max_ = value;
    // @@protoc_insertion_point(field_set:metrics.HistogramEventProto.Bucket.max)
}

// optional int32 bucket_index = 3 [deprecated = true];
bool HistogramEventProto_Bucket::has_bucket_index() const
{
    return (_has_bits_[0] & 0x00000004u) != 0;
}
void HistogramEventProto_Bucket::set_has_bucket_index()
{
    _has_bits_[0] |= 0x00000004u;
}
void HistogramEventProto_Bucket::clear_has_bucket_index()
{
    _has_bits_[0] &= ~0x00000004u;
}
void HistogramEventProto_Bucket::clear_bucket_index()
{
    bucket_index_ = 0;
    clear_has_bucket_index();
}
::google::protobuf::int32 HistogramEventProto_Bucket::bucket_index() const
{
    // @@protoc_insertion_point(field_get:metrics.HistogramEventProto.Bucket.bucket_index)
    return bucket_index_;
}
void HistogramEventProto_Bucket::set_bucket_index(::google::protobuf::int32 value)
{
    set_has_bucket_index();
    bucket_index_ = value;
    // @@protoc_insertion_point(field_set:metrics.HistogramEventProto.Bucket.bucket_index)
}

// optional int64 count = 4 [default = 1];
bool HistogramEventProto_Bucket::has_count() const
{
    return (_has_bits_[0] & 0x00000008u) != 0;
}
void HistogramEventProto_Bucket::set_has_count()
{
    _has_bits_[0] |= 0x00000008u;
}
void HistogramEventProto_Bucket::clear_has_count()
{
    _has_bits_[0] &= ~0x00000008u;
}
void HistogramEventProto_Bucket::clear_count()
{
    count_ = GOOGLE_LONGLONG(1);
    clear_has_count();
}
::google::protobuf::int64 HistogramEventProto_Bucket::count() const
{
    // @@protoc_insertion_point(field_get:metrics.HistogramEventProto.Bucket.count)
    return count_;
}
void HistogramEventProto_Bucket::set_count(::google::protobuf::int64 value)
{
    set_has_count();
    count_ = value;
    // @@protoc_insertion_point(field_set:metrics.HistogramEventProto.Bucket.count)
}

// -------------------------------------------------------------------

// HistogramEventProto

// optional fixed64 name_hash = 1;
bool HistogramEventProto::has_name_hash() const
{
    return (_has_bits_[0] & 0x00000001u) != 0;
}
void HistogramEventProto::set_has_name_hash()
{
    _has_bits_[0] |= 0x00000001u;
}
void HistogramEventProto::clear_has_name_hash()
{
    _has_bits_[0] &= ~0x00000001u;
}
void HistogramEventProto::clear_name_hash()
{
    name_hash_ = GOOGLE_ULONGLONG(0);
    clear_has_name_hash();
}
::google::protobuf::uint64 HistogramEventProto::name_hash() const
{
    // @@protoc_insertion_point(field_get:metrics.HistogramEventProto.name_hash)
    return name_hash_;
}
void HistogramEventProto::set_name_hash(::google::protobuf::uint64 value)
{
    set_has_name_hash();
    name_hash_ = value;
    // @@protoc_insertion_point(field_set:metrics.HistogramEventProto.name_hash)
}

// optional int64 sum = 2;
bool HistogramEventProto::has_sum() const
{
    return (_has_bits_[0] & 0x00000002u) != 0;
}
void HistogramEventProto::set_has_sum()
{
    _has_bits_[0] |= 0x00000002u;
}
void HistogramEventProto::clear_has_sum()
{
    _has_bits_[0] &= ~0x00000002u;
}
void HistogramEventProto::clear_sum()
{
    sum_ = GOOGLE_LONGLONG(0);
    clear_has_sum();
}
::google::protobuf::int64 HistogramEventProto::sum() const
{
    // @@protoc_insertion_point(field_get:metrics.HistogramEventProto.sum)
    return sum_;
}
void HistogramEventProto::set_sum(::google::protobuf::int64 value)
{
    set_has_sum();
    sum_ = value;
    // @@protoc_insertion_point(field_set:metrics.HistogramEventProto.sum)
}

// repeated .metrics.HistogramEventProto.Bucket bucket = 3;
int HistogramEventProto::bucket_size() const
{
    return bucket_.size();
}
void HistogramEventProto::clear_bucket()
{
    bucket_.Clear();
}
const ::metrics::HistogramEventProto_Bucket& HistogramEventProto::bucket(int index) const
{
    // @@protoc_insertion_point(field_get:metrics.HistogramEventProto.bucket)
    return bucket_.Get(index);
}
::metrics::HistogramEventProto_Bucket* HistogramEventProto::mutable_bucket(int index)
{
    // @@protoc_insertion_point(field_mutable:metrics.HistogramEventProto.bucket)
    return bucket_.Mutable(index);
}
::metrics::HistogramEventProto_Bucket* HistogramEventProto::add_bucket()
{
    // @@protoc_insertion_point(field_add:metrics.HistogramEventProto.bucket)
    return bucket_.Add();
}
::google::protobuf::RepeatedPtrField<::metrics::HistogramEventProto_Bucket>*
HistogramEventProto::mutable_bucket()
{
    // @@protoc_insertion_point(field_mutable_list:metrics.HistogramEventProto.bucket)
    return &bucket_;
}
const ::google::protobuf::RepeatedPtrField<::metrics::HistogramEventProto_Bucket>&
HistogramEventProto::bucket() const
{
    // @@protoc_insertion_point(field_list:metrics.HistogramEventProto.bucket)
    return bucket_;
}

#endif // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

} // namespace metrics

// @@protoc_insertion_point(global_scope)
