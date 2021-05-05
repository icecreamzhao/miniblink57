// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: autofill_sync.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "autofill_sync.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

namespace autofill {

void protobuf_ShutdownFile_autofill_5fsync_2eproto()
{
    delete AutofillSyncStorageKey::default_instance_;
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
void protobuf_AddDesc_autofill_5fsync_2eproto_impl()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
void protobuf_AddDesc_autofill_5fsync_2eproto()
{
    static bool already_here = false;
    if (already_here)
        return;
    already_here = true;
    GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
    AutofillSyncStorageKey::default_instance_ = new AutofillSyncStorageKey();
    AutofillSyncStorageKey::default_instance_->InitAsDefaultInstance();
    ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_autofill_5fsync_2eproto);
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_autofill_5fsync_2eproto_once_);
void protobuf_AddDesc_autofill_5fsync_2eproto()
{
    ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_autofill_5fsync_2eproto_once_,
        &protobuf_AddDesc_autofill_5fsync_2eproto_impl);
}
#else
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_autofill_5fsync_2eproto {
    StaticDescriptorInitializer_autofill_5fsync_2eproto()
    {
        protobuf_AddDesc_autofill_5fsync_2eproto();
    }
} static_descriptor_initializer_autofill_5fsync_2eproto_;
#endif

namespace {

    static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
    GOOGLE_ATTRIBUTE_NOINLINE static void MergeFromFail(int line)
    {
        GOOGLE_CHECK(false) << __FILE__ << ":" << line;
    }

} // namespace

// ===================================================================

static ::std::string* MutableUnknownFieldsForAutofillSyncStorageKey(
    AutofillSyncStorageKey* ptr)
{
    return ptr->mutable_unknown_fields();
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int AutofillSyncStorageKey::kNameFieldNumber;
const int AutofillSyncStorageKey::kValueFieldNumber;
#endif // !defined(_MSC_VER) || _MSC_VER >= 1900

AutofillSyncStorageKey::AutofillSyncStorageKey()
    : ::google::protobuf::MessageLite()
    , _arena_ptr_(NULL)
{
    SharedCtor();
    // @@protoc_insertion_point(constructor:autofill.AutofillSyncStorageKey)
}

void AutofillSyncStorageKey::InitAsDefaultInstance()
{
}

AutofillSyncStorageKey::AutofillSyncStorageKey(const AutofillSyncStorageKey& from)
    : ::google::protobuf::MessageLite()
    , _arena_ptr_(NULL)
{
    SharedCtor();
    MergeFrom(from);
    // @@protoc_insertion_point(copy_constructor:autofill.AutofillSyncStorageKey)
}

void AutofillSyncStorageKey::SharedCtor()
{
    ::google::protobuf::internal::GetEmptyString();
    _cached_size_ = 0;
    _unknown_fields_.UnsafeSetDefault(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    value_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AutofillSyncStorageKey::~AutofillSyncStorageKey()
{
    // @@protoc_insertion_point(destructor:autofill.AutofillSyncStorageKey)
    SharedDtor();
}

void AutofillSyncStorageKey::SharedDtor()
{
    _unknown_fields_.DestroyNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    value_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    if (this != &default_instance()) {
#else
    if (this != default_instance_) {
#endif
    }
}

void AutofillSyncStorageKey::SetCachedSize(int size) const
{
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _cached_size_ = size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const AutofillSyncStorageKey& AutofillSyncStorageKey::default_instance()
{
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    protobuf_AddDesc_autofill_5fsync_2eproto();
#else
    if (default_instance_ == NULL)
        protobuf_AddDesc_autofill_5fsync_2eproto();
#endif
    return *default_instance_;
}

AutofillSyncStorageKey* AutofillSyncStorageKey::default_instance_ = NULL;

AutofillSyncStorageKey* AutofillSyncStorageKey::New(::google::protobuf::Arena* arena) const
{
    AutofillSyncStorageKey* n = new AutofillSyncStorageKey;
    if (arena != NULL) {
        arena->Own(n);
    }
    return n;
}

void AutofillSyncStorageKey::Clear()
{
    // @@protoc_insertion_point(message_clear_start:autofill.AutofillSyncStorageKey)
    if (_has_bits_[0 / 32] & 3u) {
        if (has_name()) {
            name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
        }
        if (has_value()) {
            value_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
        }
    }
    ::memset(_has_bits_, 0, sizeof(_has_bits_));
    _unknown_fields_.ClearToEmptyNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool AutofillSyncStorageKey::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input)
{
#define DO_(EXPRESSION)                   \
    if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) \
    goto failure
    ::google::protobuf::uint32 tag;
    ::google::protobuf::io::LazyStringOutputStream unknown_fields_string(
        ::google::protobuf::internal::NewPermanentCallback(
            &MutableUnknownFieldsForAutofillSyncStorageKey, this));
    ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
        &unknown_fields_string, false);
    // @@protoc_insertion_point(parse_start:autofill.AutofillSyncStorageKey)
    for (;;) {
        ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
        tag = p.first;
        if (!p.second)
            goto handle_unusual;
        switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
        // optional string name = 1;
        case 1: {
            if (tag == 10) {
                DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                    input, this->mutable_name()));
            } else {
                goto handle_unusual;
            }
            if (input->ExpectTag(18))
                goto parse_value;
            break;
        }

        // optional string value = 2;
        case 2: {
            if (tag == 18) {
            parse_value:
                DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                    input, this->mutable_value()));
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
    // @@protoc_insertion_point(parse_success:autofill.AutofillSyncStorageKey)
    return true;
failure:
    // @@protoc_insertion_point(parse_failure:autofill.AutofillSyncStorageKey)
    return false;
#undef DO_
}

void AutofillSyncStorageKey::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const
{
    // @@protoc_insertion_point(serialize_start:autofill.AutofillSyncStorageKey)
    // optional string name = 1;
    if (has_name()) {
        ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
            1, this->name(), output);
    }

    // optional string value = 2;
    if (has_value()) {
        ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
            2, this->value(), output);
    }

    output->WriteRaw(unknown_fields().data(),
        static_cast<int>(unknown_fields().size()));
    // @@protoc_insertion_point(serialize_end:autofill.AutofillSyncStorageKey)
}

int AutofillSyncStorageKey::ByteSize() const
{
    // @@protoc_insertion_point(message_byte_size_start:autofill.AutofillSyncStorageKey)
    int total_size = 0;

    if (_has_bits_[0 / 32] & 3u) {
        // optional string name = 1;
        if (has_name()) {
            total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(this->name());
        }

        // optional string value = 2;
        if (has_value()) {
            total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(this->value());
        }
    }
    total_size += unknown_fields().size();

    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _cached_size_ = total_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    return total_size;
}

void AutofillSyncStorageKey::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from)
{
    MergeFrom(*::google::protobuf::down_cast<const AutofillSyncStorageKey*>(&from));
}

void AutofillSyncStorageKey::MergeFrom(const AutofillSyncStorageKey& from)
{
    // @@protoc_insertion_point(class_specific_merge_from_start:autofill.AutofillSyncStorageKey)
    if (GOOGLE_PREDICT_FALSE(&from == this))
        MergeFromFail(__LINE__);
    if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
        if (from.has_name()) {
            set_has_name();
            name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
        }
        if (from.has_value()) {
            set_has_value();
            value_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.value_);
        }
    }
    if (!from.unknown_fields().empty()) {
        mutable_unknown_fields()->append(from.unknown_fields());
    }
}

void AutofillSyncStorageKey::CopyFrom(const AutofillSyncStorageKey& from)
{
    // @@protoc_insertion_point(class_specific_copy_from_start:autofill.AutofillSyncStorageKey)
    if (&from == this)
        return;
    Clear();
    MergeFrom(from);
}

bool AutofillSyncStorageKey::IsInitialized() const
{

    return true;
}

void AutofillSyncStorageKey::Swap(AutofillSyncStorageKey* other)
{
    if (other == this)
        return;
    InternalSwap(other);
}
void AutofillSyncStorageKey::InternalSwap(AutofillSyncStorageKey* other)
{
    name_.Swap(&other->name_);
    value_.Swap(&other->value_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
}

::std::string AutofillSyncStorageKey::GetTypeName() const
{
    return "autofill.AutofillSyncStorageKey";
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// AutofillSyncStorageKey

// optional string name = 1;
bool AutofillSyncStorageKey::has_name() const
{
    return (_has_bits_[0] & 0x00000001u) != 0;
}
void AutofillSyncStorageKey::set_has_name()
{
    _has_bits_[0] |= 0x00000001u;
}
void AutofillSyncStorageKey::clear_has_name()
{
    _has_bits_[0] &= ~0x00000001u;
}
void AutofillSyncStorageKey::clear_name()
{
    name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_name();
}
const ::std::string& AutofillSyncStorageKey::name() const
{
    // @@protoc_insertion_point(field_get:autofill.AutofillSyncStorageKey.name)
    return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void AutofillSyncStorageKey::set_name(const ::std::string& value)
{
    set_has_name();
    name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
    // @@protoc_insertion_point(field_set:autofill.AutofillSyncStorageKey.name)
}
void AutofillSyncStorageKey::set_name(const char* value)
{
    set_has_name();
    name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
    // @@protoc_insertion_point(field_set_char:autofill.AutofillSyncStorageKey.name)
}
void AutofillSyncStorageKey::set_name(const char* value, size_t size)
{
    set_has_name();
    name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        ::std::string(reinterpret_cast<const char*>(value), size));
    // @@protoc_insertion_point(field_set_pointer:autofill.AutofillSyncStorageKey.name)
}
::std::string* AutofillSyncStorageKey::mutable_name()
{
    set_has_name();
    // @@protoc_insertion_point(field_mutable:autofill.AutofillSyncStorageKey.name)
    return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* AutofillSyncStorageKey::release_name()
{
    // @@protoc_insertion_point(field_release:autofill.AutofillSyncStorageKey.name)
    clear_has_name();
    return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void AutofillSyncStorageKey::set_allocated_name(::std::string* name)
{
    if (name != NULL) {
        set_has_name();
    } else {
        clear_has_name();
    }
    name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
    // @@protoc_insertion_point(field_set_allocated:autofill.AutofillSyncStorageKey.name)
}

// optional string value = 2;
bool AutofillSyncStorageKey::has_value() const
{
    return (_has_bits_[0] & 0x00000002u) != 0;
}
void AutofillSyncStorageKey::set_has_value()
{
    _has_bits_[0] |= 0x00000002u;
}
void AutofillSyncStorageKey::clear_has_value()
{
    _has_bits_[0] &= ~0x00000002u;
}
void AutofillSyncStorageKey::clear_value()
{
    value_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_value();
}
const ::std::string& AutofillSyncStorageKey::value() const
{
    // @@protoc_insertion_point(field_get:autofill.AutofillSyncStorageKey.value)
    return value_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void AutofillSyncStorageKey::set_value(const ::std::string& value)
{
    set_has_value();
    value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
    // @@protoc_insertion_point(field_set:autofill.AutofillSyncStorageKey.value)
}
void AutofillSyncStorageKey::set_value(const char* value)
{
    set_has_value();
    value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
    // @@protoc_insertion_point(field_set_char:autofill.AutofillSyncStorageKey.value)
}
void AutofillSyncStorageKey::set_value(const char* value, size_t size)
{
    set_has_value();
    value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        ::std::string(reinterpret_cast<const char*>(value), size));
    // @@protoc_insertion_point(field_set_pointer:autofill.AutofillSyncStorageKey.value)
}
::std::string* AutofillSyncStorageKey::mutable_value()
{
    set_has_value();
    // @@protoc_insertion_point(field_mutable:autofill.AutofillSyncStorageKey.value)
    return value_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* AutofillSyncStorageKey::release_value()
{
    // @@protoc_insertion_point(field_release:autofill.AutofillSyncStorageKey.value)
    clear_has_value();
    return value_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void AutofillSyncStorageKey::set_allocated_value(::std::string* value)
{
    if (value != NULL) {
        set_has_value();
    } else {
        clear_has_value();
    }
    value_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
    // @@protoc_insertion_point(field_set_allocated:autofill.AutofillSyncStorageKey.value)
}

#endif // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

} // namespace autofill

// @@protoc_insertion_point(global_scope)
