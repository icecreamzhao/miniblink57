// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: typed_url_specifics.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "typed_url_specifics.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

namespace sync_pb {

void protobuf_ShutdownFile_typed_5furl_5fspecifics_2eproto()
{
    delete TypedUrlSpecifics::default_instance_;
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
void protobuf_AddDesc_typed_5furl_5fspecifics_2eproto_impl()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
void protobuf_AddDesc_typed_5furl_5fspecifics_2eproto()
{
    static bool already_here = false;
    if (already_here)
        return;
    already_here = true;
    GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
    TypedUrlSpecifics::default_instance_ = new TypedUrlSpecifics();
    TypedUrlSpecifics::default_instance_->InitAsDefaultInstance();
    ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_typed_5furl_5fspecifics_2eproto);
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_typed_5furl_5fspecifics_2eproto_once_);
void protobuf_AddDesc_typed_5furl_5fspecifics_2eproto()
{
    ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_typed_5furl_5fspecifics_2eproto_once_,
        &protobuf_AddDesc_typed_5furl_5fspecifics_2eproto_impl);
}
#else
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_typed_5furl_5fspecifics_2eproto {
    StaticDescriptorInitializer_typed_5furl_5fspecifics_2eproto()
    {
        protobuf_AddDesc_typed_5furl_5fspecifics_2eproto();
    }
} static_descriptor_initializer_typed_5furl_5fspecifics_2eproto_;
#endif

namespace {

    static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
    GOOGLE_ATTRIBUTE_NOINLINE static void MergeFromFail(int line)
    {
        GOOGLE_CHECK(false) << __FILE__ << ":" << line;
    }

} // namespace

// ===================================================================

static ::std::string* MutableUnknownFieldsForTypedUrlSpecifics(
    TypedUrlSpecifics* ptr)
{
    return ptr->mutable_unknown_fields();
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int TypedUrlSpecifics::kUrlFieldNumber;
const int TypedUrlSpecifics::kTitleFieldNumber;
const int TypedUrlSpecifics::kHiddenFieldNumber;
const int TypedUrlSpecifics::kVisitsFieldNumber;
const int TypedUrlSpecifics::kVisitTransitionsFieldNumber;
#endif // !defined(_MSC_VER) || _MSC_VER >= 1900

TypedUrlSpecifics::TypedUrlSpecifics()
    : ::google::protobuf::MessageLite()
    , _arena_ptr_(NULL)
{
    SharedCtor();
    // @@protoc_insertion_point(constructor:sync_pb.TypedUrlSpecifics)
}

void TypedUrlSpecifics::InitAsDefaultInstance()
{
}

TypedUrlSpecifics::TypedUrlSpecifics(const TypedUrlSpecifics& from)
    : ::google::protobuf::MessageLite()
    , _arena_ptr_(NULL)
{
    SharedCtor();
    MergeFrom(from);
    // @@protoc_insertion_point(copy_constructor:sync_pb.TypedUrlSpecifics)
}

void TypedUrlSpecifics::SharedCtor()
{
    ::google::protobuf::internal::GetEmptyString();
    _cached_size_ = 0;
    _unknown_fields_.UnsafeSetDefault(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    url_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    title_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    hidden_ = false;
    ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

TypedUrlSpecifics::~TypedUrlSpecifics()
{
    // @@protoc_insertion_point(destructor:sync_pb.TypedUrlSpecifics)
    SharedDtor();
}

void TypedUrlSpecifics::SharedDtor()
{
    _unknown_fields_.DestroyNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    url_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    title_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    if (this != &default_instance()) {
#else
    if (this != default_instance_) {
#endif
    }
}

void TypedUrlSpecifics::SetCachedSize(int size) const
{
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _cached_size_ = size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const TypedUrlSpecifics& TypedUrlSpecifics::default_instance()
{
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    protobuf_AddDesc_typed_5furl_5fspecifics_2eproto();
#else
    if (default_instance_ == NULL)
        protobuf_AddDesc_typed_5furl_5fspecifics_2eproto();
#endif
    return *default_instance_;
}

TypedUrlSpecifics* TypedUrlSpecifics::default_instance_ = NULL;

TypedUrlSpecifics* TypedUrlSpecifics::New(::google::protobuf::Arena* arena) const
{
    TypedUrlSpecifics* n = new TypedUrlSpecifics;
    if (arena != NULL) {
        arena->Own(n);
    }
    return n;
}

void TypedUrlSpecifics::Clear()
{
    // @@protoc_insertion_point(message_clear_start:sync_pb.TypedUrlSpecifics)
    if (_has_bits_[0 / 32] & 7u) {
        if (has_url()) {
            url_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
        }
        if (has_title()) {
            title_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
        }
        hidden_ = false;
    }
    visits_.Clear();
    visit_transitions_.Clear();
    ::memset(_has_bits_, 0, sizeof(_has_bits_));
    _unknown_fields_.ClearToEmptyNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool TypedUrlSpecifics::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input)
{
#define DO_(EXPRESSION)                   \
    if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) \
    goto failure
    ::google::protobuf::uint32 tag;
    ::google::protobuf::io::LazyStringOutputStream unknown_fields_string(
        ::google::protobuf::internal::NewPermanentCallback(
            &MutableUnknownFieldsForTypedUrlSpecifics, this));
    ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
        &unknown_fields_string, false);
    // @@protoc_insertion_point(parse_start:sync_pb.TypedUrlSpecifics)
    for (;;) {
        ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
        tag = p.first;
        if (!p.second)
            goto handle_unusual;
        switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
        // optional string url = 1;
        case 1: {
            if (tag == 10) {
                DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                    input, this->mutable_url()));
            } else {
                goto handle_unusual;
            }
            if (input->ExpectTag(18))
                goto parse_title;
            break;
        }

        // optional string title = 2;
        case 2: {
            if (tag == 18) {
            parse_title:
                DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                    input, this->mutable_title()));
            } else {
                goto handle_unusual;
            }
            if (input->ExpectTag(32))
                goto parse_hidden;
            break;
        }

        // optional bool hidden = 4;
        case 4: {
            if (tag == 32) {
            parse_hidden:
                DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                    bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                    input, &hidden_)));
                set_has_hidden();
            } else {
                goto handle_unusual;
            }
            if (input->ExpectTag(58))
                goto parse_visits;
            break;
        }

        // repeated int64 visits = 7 [packed = true];
        case 7: {
            if (tag == 58) {
            parse_visits:
                DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                    ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                    input, this->mutable_visits())));
            } else if (tag == 56) {
                DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                    ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                    1, 58, input, this->mutable_visits())));
            } else {
                goto handle_unusual;
            }
            if (input->ExpectTag(66))
                goto parse_visit_transitions;
            break;
        }

        // repeated int32 visit_transitions = 8 [packed = true];
        case 8: {
            if (tag == 66) {
            parse_visit_transitions:
                DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                    ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                    input, this->mutable_visit_transitions())));
            } else if (tag == 64) {
                DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                    ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                    1, 66, input, this->mutable_visit_transitions())));
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
    // @@protoc_insertion_point(parse_success:sync_pb.TypedUrlSpecifics)
    return true;
failure:
    // @@protoc_insertion_point(parse_failure:sync_pb.TypedUrlSpecifics)
    return false;
#undef DO_
}

void TypedUrlSpecifics::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const
{
    // @@protoc_insertion_point(serialize_start:sync_pb.TypedUrlSpecifics)
    // optional string url = 1;
    if (has_url()) {
        ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
            1, this->url(), output);
    }

    // optional string title = 2;
    if (has_title()) {
        ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
            2, this->title(), output);
    }

    // optional bool hidden = 4;
    if (has_hidden()) {
        ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->hidden(), output);
    }

    // repeated int64 visits = 7 [packed = true];
    if (this->visits_size() > 0) {
        ::google::protobuf::internal::WireFormatLite::WriteTag(7, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        output->WriteVarint32(_visits_cached_byte_size_);
    }
    for (int i = 0; i < this->visits_size(); i++) {
        ::google::protobuf::internal::WireFormatLite::WriteInt64NoTag(
            this->visits(i), output);
    }

    // repeated int32 visit_transitions = 8 [packed = true];
    if (this->visit_transitions_size() > 0) {
        ::google::protobuf::internal::WireFormatLite::WriteTag(8, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
        output->WriteVarint32(_visit_transitions_cached_byte_size_);
    }
    for (int i = 0; i < this->visit_transitions_size(); i++) {
        ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(
            this->visit_transitions(i), output);
    }

    output->WriteRaw(unknown_fields().data(),
        static_cast<int>(unknown_fields().size()));
    // @@protoc_insertion_point(serialize_end:sync_pb.TypedUrlSpecifics)
}

int TypedUrlSpecifics::ByteSize() const
{
    // @@protoc_insertion_point(message_byte_size_start:sync_pb.TypedUrlSpecifics)
    int total_size = 0;

    if (_has_bits_[0 / 32] & 7u) {
        // optional string url = 1;
        if (has_url()) {
            total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(this->url());
        }

        // optional string title = 2;
        if (has_title()) {
            total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(this->title());
        }

        // optional bool hidden = 4;
        if (has_hidden()) {
            total_size += 1 + 1;
        }
    }
    // repeated int64 visits = 7 [packed = true];
    {
        int data_size = 0;
        for (int i = 0; i < this->visits_size(); i++) {
            data_size += ::google::protobuf::internal::WireFormatLite::
                Int64Size(this->visits(i));
        }
        if (data_size > 0) {
            total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
        }
        GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
        _visits_cached_byte_size_ = data_size;
        GOOGLE_SAFE_CONCURRENT_WRITES_END();
        total_size += data_size;
    }

    // repeated int32 visit_transitions = 8 [packed = true];
    {
        int data_size = 0;
        for (int i = 0; i < this->visit_transitions_size(); i++) {
            data_size += ::google::protobuf::internal::WireFormatLite::
                Int32Size(this->visit_transitions(i));
        }
        if (data_size > 0) {
            total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
        }
        GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
        _visit_transitions_cached_byte_size_ = data_size;
        GOOGLE_SAFE_CONCURRENT_WRITES_END();
        total_size += data_size;
    }

    total_size += unknown_fields().size();

    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _cached_size_ = total_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    return total_size;
}

void TypedUrlSpecifics::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from)
{
    MergeFrom(*::google::protobuf::down_cast<const TypedUrlSpecifics*>(&from));
}

void TypedUrlSpecifics::MergeFrom(const TypedUrlSpecifics& from)
{
    // @@protoc_insertion_point(class_specific_merge_from_start:sync_pb.TypedUrlSpecifics)
    if (GOOGLE_PREDICT_FALSE(&from == this))
        MergeFromFail(__LINE__);
    visits_.MergeFrom(from.visits_);
    visit_transitions_.MergeFrom(from.visit_transitions_);
    if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
        if (from.has_url()) {
            set_has_url();
            url_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.url_);
        }
        if (from.has_title()) {
            set_has_title();
            title_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.title_);
        }
        if (from.has_hidden()) {
            set_hidden(from.hidden());
        }
    }
    if (!from.unknown_fields().empty()) {
        mutable_unknown_fields()->append(from.unknown_fields());
    }
}

void TypedUrlSpecifics::CopyFrom(const TypedUrlSpecifics& from)
{
    // @@protoc_insertion_point(class_specific_copy_from_start:sync_pb.TypedUrlSpecifics)
    if (&from == this)
        return;
    Clear();
    MergeFrom(from);
}

bool TypedUrlSpecifics::IsInitialized() const
{

    return true;
}

void TypedUrlSpecifics::Swap(TypedUrlSpecifics* other)
{
    if (other == this)
        return;
    InternalSwap(other);
}
void TypedUrlSpecifics::InternalSwap(TypedUrlSpecifics* other)
{
    url_.Swap(&other->url_);
    title_.Swap(&other->title_);
    std::swap(hidden_, other->hidden_);
    visits_.UnsafeArenaSwap(&other->visits_);
    visit_transitions_.UnsafeArenaSwap(&other->visit_transitions_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
}

::std::string TypedUrlSpecifics::GetTypeName() const
{
    return "sync_pb.TypedUrlSpecifics";
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// TypedUrlSpecifics

// optional string url = 1;
bool TypedUrlSpecifics::has_url() const
{
    return (_has_bits_[0] & 0x00000001u) != 0;
}
void TypedUrlSpecifics::set_has_url()
{
    _has_bits_[0] |= 0x00000001u;
}
void TypedUrlSpecifics::clear_has_url()
{
    _has_bits_[0] &= ~0x00000001u;
}
void TypedUrlSpecifics::clear_url()
{
    url_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_url();
}
const ::std::string& TypedUrlSpecifics::url() const
{
    // @@protoc_insertion_point(field_get:sync_pb.TypedUrlSpecifics.url)
    return url_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void TypedUrlSpecifics::set_url(const ::std::string& value)
{
    set_has_url();
    url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
    // @@protoc_insertion_point(field_set:sync_pb.TypedUrlSpecifics.url)
}
void TypedUrlSpecifics::set_url(const char* value)
{
    set_has_url();
    url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
    // @@protoc_insertion_point(field_set_char:sync_pb.TypedUrlSpecifics.url)
}
void TypedUrlSpecifics::set_url(const char* value, size_t size)
{
    set_has_url();
    url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        ::std::string(reinterpret_cast<const char*>(value), size));
    // @@protoc_insertion_point(field_set_pointer:sync_pb.TypedUrlSpecifics.url)
}
::std::string* TypedUrlSpecifics::mutable_url()
{
    set_has_url();
    // @@protoc_insertion_point(field_mutable:sync_pb.TypedUrlSpecifics.url)
    return url_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* TypedUrlSpecifics::release_url()
{
    // @@protoc_insertion_point(field_release:sync_pb.TypedUrlSpecifics.url)
    clear_has_url();
    return url_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void TypedUrlSpecifics::set_allocated_url(::std::string* url)
{
    if (url != NULL) {
        set_has_url();
    } else {
        clear_has_url();
    }
    url_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), url);
    // @@protoc_insertion_point(field_set_allocated:sync_pb.TypedUrlSpecifics.url)
}

// optional string title = 2;
bool TypedUrlSpecifics::has_title() const
{
    return (_has_bits_[0] & 0x00000002u) != 0;
}
void TypedUrlSpecifics::set_has_title()
{
    _has_bits_[0] |= 0x00000002u;
}
void TypedUrlSpecifics::clear_has_title()
{
    _has_bits_[0] &= ~0x00000002u;
}
void TypedUrlSpecifics::clear_title()
{
    title_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_title();
}
const ::std::string& TypedUrlSpecifics::title() const
{
    // @@protoc_insertion_point(field_get:sync_pb.TypedUrlSpecifics.title)
    return title_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void TypedUrlSpecifics::set_title(const ::std::string& value)
{
    set_has_title();
    title_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
    // @@protoc_insertion_point(field_set:sync_pb.TypedUrlSpecifics.title)
}
void TypedUrlSpecifics::set_title(const char* value)
{
    set_has_title();
    title_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
    // @@protoc_insertion_point(field_set_char:sync_pb.TypedUrlSpecifics.title)
}
void TypedUrlSpecifics::set_title(const char* value, size_t size)
{
    set_has_title();
    title_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        ::std::string(reinterpret_cast<const char*>(value), size));
    // @@protoc_insertion_point(field_set_pointer:sync_pb.TypedUrlSpecifics.title)
}
::std::string* TypedUrlSpecifics::mutable_title()
{
    set_has_title();
    // @@protoc_insertion_point(field_mutable:sync_pb.TypedUrlSpecifics.title)
    return title_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* TypedUrlSpecifics::release_title()
{
    // @@protoc_insertion_point(field_release:sync_pb.TypedUrlSpecifics.title)
    clear_has_title();
    return title_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void TypedUrlSpecifics::set_allocated_title(::std::string* title)
{
    if (title != NULL) {
        set_has_title();
    } else {
        clear_has_title();
    }
    title_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), title);
    // @@protoc_insertion_point(field_set_allocated:sync_pb.TypedUrlSpecifics.title)
}

// optional bool hidden = 4;
bool TypedUrlSpecifics::has_hidden() const
{
    return (_has_bits_[0] & 0x00000004u) != 0;
}
void TypedUrlSpecifics::set_has_hidden()
{
    _has_bits_[0] |= 0x00000004u;
}
void TypedUrlSpecifics::clear_has_hidden()
{
    _has_bits_[0] &= ~0x00000004u;
}
void TypedUrlSpecifics::clear_hidden()
{
    hidden_ = false;
    clear_has_hidden();
}
bool TypedUrlSpecifics::hidden() const
{
    // @@protoc_insertion_point(field_get:sync_pb.TypedUrlSpecifics.hidden)
    return hidden_;
}
void TypedUrlSpecifics::set_hidden(bool value)
{
    set_has_hidden();
    hidden_ = value;
    // @@protoc_insertion_point(field_set:sync_pb.TypedUrlSpecifics.hidden)
}

// repeated int64 visits = 7 [packed = true];
int TypedUrlSpecifics::visits_size() const
{
    return visits_.size();
}
void TypedUrlSpecifics::clear_visits()
{
    visits_.Clear();
}
::google::protobuf::int64 TypedUrlSpecifics::visits(int index) const
{
    // @@protoc_insertion_point(field_get:sync_pb.TypedUrlSpecifics.visits)
    return visits_.Get(index);
}
void TypedUrlSpecifics::set_visits(int index, ::google::protobuf::int64 value)
{
    visits_.Set(index, value);
    // @@protoc_insertion_point(field_set:sync_pb.TypedUrlSpecifics.visits)
}
void TypedUrlSpecifics::add_visits(::google::protobuf::int64 value)
{
    visits_.Add(value);
    // @@protoc_insertion_point(field_add:sync_pb.TypedUrlSpecifics.visits)
}
const ::google::protobuf::RepeatedField<::google::protobuf::int64>&
TypedUrlSpecifics::visits() const
{
    // @@protoc_insertion_point(field_list:sync_pb.TypedUrlSpecifics.visits)
    return visits_;
}
::google::protobuf::RepeatedField<::google::protobuf::int64>*
TypedUrlSpecifics::mutable_visits()
{
    // @@protoc_insertion_point(field_mutable_list:sync_pb.TypedUrlSpecifics.visits)
    return &visits_;
}

// repeated int32 visit_transitions = 8 [packed = true];
int TypedUrlSpecifics::visit_transitions_size() const
{
    return visit_transitions_.size();
}
void TypedUrlSpecifics::clear_visit_transitions()
{
    visit_transitions_.Clear();
}
::google::protobuf::int32 TypedUrlSpecifics::visit_transitions(int index) const
{
    // @@protoc_insertion_point(field_get:sync_pb.TypedUrlSpecifics.visit_transitions)
    return visit_transitions_.Get(index);
}
void TypedUrlSpecifics::set_visit_transitions(int index, ::google::protobuf::int32 value)
{
    visit_transitions_.Set(index, value);
    // @@protoc_insertion_point(field_set:sync_pb.TypedUrlSpecifics.visit_transitions)
}
void TypedUrlSpecifics::add_visit_transitions(::google::protobuf::int32 value)
{
    visit_transitions_.Add(value);
    // @@protoc_insertion_point(field_add:sync_pb.TypedUrlSpecifics.visit_transitions)
}
const ::google::protobuf::RepeatedField<::google::protobuf::int32>&
TypedUrlSpecifics::visit_transitions() const
{
    // @@protoc_insertion_point(field_list:sync_pb.TypedUrlSpecifics.visit_transitions)
    return visit_transitions_;
}
::google::protobuf::RepeatedField<::google::protobuf::int32>*
TypedUrlSpecifics::mutable_visit_transitions()
{
    // @@protoc_insertion_point(field_mutable_list:sync_pb.TypedUrlSpecifics.visit_transitions)
    return &visit_transitions_;
}

#endif // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

} // namespace sync_pb

// @@protoc_insertion_point(global_scope)
