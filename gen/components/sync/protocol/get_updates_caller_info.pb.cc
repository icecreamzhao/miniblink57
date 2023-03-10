// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: get_updates_caller_info.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "get_updates_caller_info.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

namespace sync_pb {

void protobuf_ShutdownFile_get_5fupdates_5fcaller_5finfo_2eproto()
{
    delete GetUpdatesCallerInfo::default_instance_;
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
void protobuf_AddDesc_get_5fupdates_5fcaller_5finfo_2eproto_impl()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
void protobuf_AddDesc_get_5fupdates_5fcaller_5finfo_2eproto()
{
    static bool already_here = false;
    if (already_here)
        return;
    already_here = true;
    GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
    GetUpdatesCallerInfo::default_instance_ = new GetUpdatesCallerInfo();
    GetUpdatesCallerInfo::default_instance_->InitAsDefaultInstance();
    ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_get_5fupdates_5fcaller_5finfo_2eproto);
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_get_5fupdates_5fcaller_5finfo_2eproto_once_);
void protobuf_AddDesc_get_5fupdates_5fcaller_5finfo_2eproto()
{
    ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_get_5fupdates_5fcaller_5finfo_2eproto_once_,
        &protobuf_AddDesc_get_5fupdates_5fcaller_5finfo_2eproto_impl);
}
#else
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_get_5fupdates_5fcaller_5finfo_2eproto {
    StaticDescriptorInitializer_get_5fupdates_5fcaller_5finfo_2eproto()
    {
        protobuf_AddDesc_get_5fupdates_5fcaller_5finfo_2eproto();
    }
} static_descriptor_initializer_get_5fupdates_5fcaller_5finfo_2eproto_;
#endif

namespace {

    static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
    GOOGLE_ATTRIBUTE_NOINLINE static void MergeFromFail(int line)
    {
        GOOGLE_CHECK(false) << __FILE__ << ":" << line;
    }

} // namespace

// ===================================================================

static ::std::string* MutableUnknownFieldsForGetUpdatesCallerInfo(
    GetUpdatesCallerInfo* ptr)
{
    return ptr->mutable_unknown_fields();
}

bool GetUpdatesCallerInfo_GetUpdatesSource_IsValid(int value)
{
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 13:
    case 14:
        return true;
    default:
        return false;
    }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const GetUpdatesCallerInfo_GetUpdatesSource GetUpdatesCallerInfo::UNKNOWN;
const GetUpdatesCallerInfo_GetUpdatesSource GetUpdatesCallerInfo::FIRST_UPDATE;
const GetUpdatesCallerInfo_GetUpdatesSource GetUpdatesCallerInfo::LOCAL;
const GetUpdatesCallerInfo_GetUpdatesSource GetUpdatesCallerInfo::NOTIFICATION;
const GetUpdatesCallerInfo_GetUpdatesSource GetUpdatesCallerInfo::PERIODIC;
const GetUpdatesCallerInfo_GetUpdatesSource GetUpdatesCallerInfo::SYNC_CYCLE_CONTINUATION;
const GetUpdatesCallerInfo_GetUpdatesSource GetUpdatesCallerInfo::NEWLY_SUPPORTED_DATATYPE;
const GetUpdatesCallerInfo_GetUpdatesSource GetUpdatesCallerInfo::MIGRATION;
const GetUpdatesCallerInfo_GetUpdatesSource GetUpdatesCallerInfo::NEW_CLIENT;
const GetUpdatesCallerInfo_GetUpdatesSource GetUpdatesCallerInfo::RECONFIGURATION;
const GetUpdatesCallerInfo_GetUpdatesSource GetUpdatesCallerInfo::DATATYPE_REFRESH;
const GetUpdatesCallerInfo_GetUpdatesSource GetUpdatesCallerInfo::RETRY;
const GetUpdatesCallerInfo_GetUpdatesSource GetUpdatesCallerInfo::PROGRAMMATIC;
const GetUpdatesCallerInfo_GetUpdatesSource GetUpdatesCallerInfo::GetUpdatesSource_MIN;
const GetUpdatesCallerInfo_GetUpdatesSource GetUpdatesCallerInfo::GetUpdatesSource_MAX;
const int GetUpdatesCallerInfo::GetUpdatesSource_ARRAYSIZE;
#endif // !defined(_MSC_VER) || _MSC_VER >= 1900
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int GetUpdatesCallerInfo::kSourceFieldNumber;
const int GetUpdatesCallerInfo::kNotificationsEnabledFieldNumber;
#endif // !defined(_MSC_VER) || _MSC_VER >= 1900

GetUpdatesCallerInfo::GetUpdatesCallerInfo()
    : ::google::protobuf::MessageLite()
    , _arena_ptr_(NULL)
{
    SharedCtor();
    // @@protoc_insertion_point(constructor:sync_pb.GetUpdatesCallerInfo)
}

void GetUpdatesCallerInfo::InitAsDefaultInstance()
{
}

GetUpdatesCallerInfo::GetUpdatesCallerInfo(const GetUpdatesCallerInfo& from)
    : ::google::protobuf::MessageLite()
    , _arena_ptr_(NULL)
{
    SharedCtor();
    MergeFrom(from);
    // @@protoc_insertion_point(copy_constructor:sync_pb.GetUpdatesCallerInfo)
}

void GetUpdatesCallerInfo::SharedCtor()
{
    ::google::protobuf::internal::GetEmptyString();
    _cached_size_ = 0;
    _unknown_fields_.UnsafeSetDefault(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    source_ = 0;
    notifications_enabled_ = false;
    ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetUpdatesCallerInfo::~GetUpdatesCallerInfo()
{
    // @@protoc_insertion_point(destructor:sync_pb.GetUpdatesCallerInfo)
    SharedDtor();
}

void GetUpdatesCallerInfo::SharedDtor()
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

void GetUpdatesCallerInfo::SetCachedSize(int size) const
{
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _cached_size_ = size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const GetUpdatesCallerInfo& GetUpdatesCallerInfo::default_instance()
{
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    protobuf_AddDesc_get_5fupdates_5fcaller_5finfo_2eproto();
#else
    if (default_instance_ == NULL)
        protobuf_AddDesc_get_5fupdates_5fcaller_5finfo_2eproto();
#endif
    return *default_instance_;
}

GetUpdatesCallerInfo* GetUpdatesCallerInfo::default_instance_ = NULL;

GetUpdatesCallerInfo* GetUpdatesCallerInfo::New(::google::protobuf::Arena* arena) const
{
    GetUpdatesCallerInfo* n = new GetUpdatesCallerInfo;
    if (arena != NULL) {
        arena->Own(n);
    }
    return n;
}

void GetUpdatesCallerInfo::Clear()
{
// @@protoc_insertion_point(message_clear_start:sync_pb.GetUpdatesCallerInfo)
#if defined(__clang__)
#define ZR_HELPER_(f)                                                                                          \
    _Pragma("clang diagnostic push")                                                                           \
        _Pragma("clang diagnostic ignored \"-Winvalid-offsetof\"") __builtin_offsetof(GetUpdatesCallerInfo, f) \
            _Pragma("clang diagnostic pop")
#else
#define ZR_HELPER_(f) reinterpret_cast<char*>( \
    &reinterpret_cast<GetUpdatesCallerInfo*>(16)->f)
#endif

#define ZR_(first, last)                                          \
    do {                                                          \
        ::memset(&first, 0,                                       \
            ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last)); \
    } while (0)

    ZR_(source_, notifications_enabled_);

#undef ZR_HELPER_
#undef ZR_

    ::memset(_has_bits_, 0, sizeof(_has_bits_));
    _unknown_fields_.ClearToEmptyNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool GetUpdatesCallerInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input)
{
#define DO_(EXPRESSION)                   \
    if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) \
    goto failure
    ::google::protobuf::uint32 tag;
    ::google::protobuf::io::LazyStringOutputStream unknown_fields_string(
        ::google::protobuf::internal::NewPermanentCallback(
            &MutableUnknownFieldsForGetUpdatesCallerInfo, this));
    ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
        &unknown_fields_string, false);
    // @@protoc_insertion_point(parse_start:sync_pb.GetUpdatesCallerInfo)
    for (;;) {
        ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
        tag = p.first;
        if (!p.second)
            goto handle_unusual;
        switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
        // required .sync_pb.GetUpdatesCallerInfo.GetUpdatesSource source = 1;
        case 1: {
            if (tag == 8) {
                int value;
                DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                    int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                    input, &value)));
                if (::sync_pb::GetUpdatesCallerInfo_GetUpdatesSource_IsValid(value)) {
                    set_source(static_cast<::sync_pb::GetUpdatesCallerInfo_GetUpdatesSource>(value));
                } else {
                    unknown_fields_stream.WriteVarint32(8);
                    unknown_fields_stream.WriteVarint32(value);
                }
            } else {
                goto handle_unusual;
            }
            if (input->ExpectTag(16))
                goto parse_notifications_enabled;
            break;
        }

        // optional bool notifications_enabled = 2;
        case 2: {
            if (tag == 16) {
            parse_notifications_enabled:
                DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                    bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                    input, &notifications_enabled_)));
                set_has_notifications_enabled();
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
    // @@protoc_insertion_point(parse_success:sync_pb.GetUpdatesCallerInfo)
    return true;
failure:
    // @@protoc_insertion_point(parse_failure:sync_pb.GetUpdatesCallerInfo)
    return false;
#undef DO_
}

void GetUpdatesCallerInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const
{
    // @@protoc_insertion_point(serialize_start:sync_pb.GetUpdatesCallerInfo)
    // required .sync_pb.GetUpdatesCallerInfo.GetUpdatesSource source = 1;
    if (has_source()) {
        ::google::protobuf::internal::WireFormatLite::WriteEnum(
            1, this->source(), output);
    }

    // optional bool notifications_enabled = 2;
    if (has_notifications_enabled()) {
        ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->notifications_enabled(), output);
    }

    output->WriteRaw(unknown_fields().data(),
        static_cast<int>(unknown_fields().size()));
    // @@protoc_insertion_point(serialize_end:sync_pb.GetUpdatesCallerInfo)
}

int GetUpdatesCallerInfo::ByteSize() const
{
    // @@protoc_insertion_point(message_byte_size_start:sync_pb.GetUpdatesCallerInfo)
    int total_size = 0;

    // required .sync_pb.GetUpdatesCallerInfo.GetUpdatesSource source = 1;
    if (has_source()) {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::EnumSize(this->source());
    }
    // optional bool notifications_enabled = 2;
    if (has_notifications_enabled()) {
        total_size += 1 + 1;
    }

    total_size += unknown_fields().size();

    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _cached_size_ = total_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    return total_size;
}

void GetUpdatesCallerInfo::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from)
{
    MergeFrom(*::google::protobuf::down_cast<const GetUpdatesCallerInfo*>(&from));
}

void GetUpdatesCallerInfo::MergeFrom(const GetUpdatesCallerInfo& from)
{
    // @@protoc_insertion_point(class_specific_merge_from_start:sync_pb.GetUpdatesCallerInfo)
    if (GOOGLE_PREDICT_FALSE(&from == this))
        MergeFromFail(__LINE__);
    if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
        if (from.has_source()) {
            set_source(from.source());
        }
        if (from.has_notifications_enabled()) {
            set_notifications_enabled(from.notifications_enabled());
        }
    }
    if (!from.unknown_fields().empty()) {
        mutable_unknown_fields()->append(from.unknown_fields());
    }
}

void GetUpdatesCallerInfo::CopyFrom(const GetUpdatesCallerInfo& from)
{
    // @@protoc_insertion_point(class_specific_copy_from_start:sync_pb.GetUpdatesCallerInfo)
    if (&from == this)
        return;
    Clear();
    MergeFrom(from);
}

bool GetUpdatesCallerInfo::IsInitialized() const
{
    if ((_has_bits_[0] & 0x00000001) != 0x00000001)
        return false;

    return true;
}

void GetUpdatesCallerInfo::Swap(GetUpdatesCallerInfo* other)
{
    if (other == this)
        return;
    InternalSwap(other);
}
void GetUpdatesCallerInfo::InternalSwap(GetUpdatesCallerInfo* other)
{
    std::swap(source_, other->source_);
    std::swap(notifications_enabled_, other->notifications_enabled_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
}

::std::string GetUpdatesCallerInfo::GetTypeName() const
{
    return "sync_pb.GetUpdatesCallerInfo";
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// GetUpdatesCallerInfo

// required .sync_pb.GetUpdatesCallerInfo.GetUpdatesSource source = 1;
bool GetUpdatesCallerInfo::has_source() const
{
    return (_has_bits_[0] & 0x00000001u) != 0;
}
void GetUpdatesCallerInfo::set_has_source()
{
    _has_bits_[0] |= 0x00000001u;
}
void GetUpdatesCallerInfo::clear_has_source()
{
    _has_bits_[0] &= ~0x00000001u;
}
void GetUpdatesCallerInfo::clear_source()
{
    source_ = 0;
    clear_has_source();
}
::sync_pb::GetUpdatesCallerInfo_GetUpdatesSource GetUpdatesCallerInfo::source() const
{
    // @@protoc_insertion_point(field_get:sync_pb.GetUpdatesCallerInfo.source)
    return static_cast<::sync_pb::GetUpdatesCallerInfo_GetUpdatesSource>(source_);
}
void GetUpdatesCallerInfo::set_source(::sync_pb::GetUpdatesCallerInfo_GetUpdatesSource value)
{
    assert(::sync_pb::GetUpdatesCallerInfo_GetUpdatesSource_IsValid(value));
    set_has_source();
    source_ = value;
    // @@protoc_insertion_point(field_set:sync_pb.GetUpdatesCallerInfo.source)
}

// optional bool notifications_enabled = 2;
bool GetUpdatesCallerInfo::has_notifications_enabled() const
{
    return (_has_bits_[0] & 0x00000002u) != 0;
}
void GetUpdatesCallerInfo::set_has_notifications_enabled()
{
    _has_bits_[0] |= 0x00000002u;
}
void GetUpdatesCallerInfo::clear_has_notifications_enabled()
{
    _has_bits_[0] &= ~0x00000002u;
}
void GetUpdatesCallerInfo::clear_notifications_enabled()
{
    notifications_enabled_ = false;
    clear_has_notifications_enabled();
}
bool GetUpdatesCallerInfo::notifications_enabled() const
{
    // @@protoc_insertion_point(field_get:sync_pb.GetUpdatesCallerInfo.notifications_enabled)
    return notifications_enabled_;
}
void GetUpdatesCallerInfo::set_notifications_enabled(bool value)
{
    set_has_notifications_enabled();
    notifications_enabled_ = value;
    // @@protoc_insertion_point(field_set:sync_pb.GetUpdatesCallerInfo.notifications_enabled)
}

#endif // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

} // namespace sync_pb

// @@protoc_insertion_point(global_scope)
