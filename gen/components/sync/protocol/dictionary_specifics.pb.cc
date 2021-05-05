// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: dictionary_specifics.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "dictionary_specifics.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

namespace sync_pb {

void protobuf_ShutdownFile_dictionary_5fspecifics_2eproto()
{
    delete DictionarySpecifics::default_instance_;
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
void protobuf_AddDesc_dictionary_5fspecifics_2eproto_impl()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
void protobuf_AddDesc_dictionary_5fspecifics_2eproto()
{
    static bool already_here = false;
    if (already_here)
        return;
    already_here = true;
    GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
    DictionarySpecifics::default_instance_ = new DictionarySpecifics();
    DictionarySpecifics::default_instance_->InitAsDefaultInstance();
    ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_dictionary_5fspecifics_2eproto);
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_dictionary_5fspecifics_2eproto_once_);
void protobuf_AddDesc_dictionary_5fspecifics_2eproto()
{
    ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_dictionary_5fspecifics_2eproto_once_,
        &protobuf_AddDesc_dictionary_5fspecifics_2eproto_impl);
}
#else
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_dictionary_5fspecifics_2eproto {
    StaticDescriptorInitializer_dictionary_5fspecifics_2eproto()
    {
        protobuf_AddDesc_dictionary_5fspecifics_2eproto();
    }
} static_descriptor_initializer_dictionary_5fspecifics_2eproto_;
#endif

namespace {

    static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
    GOOGLE_ATTRIBUTE_NOINLINE static void MergeFromFail(int line)
    {
        GOOGLE_CHECK(false) << __FILE__ << ":" << line;
    }

} // namespace

// ===================================================================

static ::std::string* MutableUnknownFieldsForDictionarySpecifics(
    DictionarySpecifics* ptr)
{
    return ptr->mutable_unknown_fields();
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int DictionarySpecifics::kWordFieldNumber;
#endif // !defined(_MSC_VER) || _MSC_VER >= 1900

DictionarySpecifics::DictionarySpecifics()
    : ::google::protobuf::MessageLite()
    , _arena_ptr_(NULL)
{
    SharedCtor();
    // @@protoc_insertion_point(constructor:sync_pb.DictionarySpecifics)
}

void DictionarySpecifics::InitAsDefaultInstance()
{
}

DictionarySpecifics::DictionarySpecifics(const DictionarySpecifics& from)
    : ::google::protobuf::MessageLite()
    , _arena_ptr_(NULL)
{
    SharedCtor();
    MergeFrom(from);
    // @@protoc_insertion_point(copy_constructor:sync_pb.DictionarySpecifics)
}

void DictionarySpecifics::SharedCtor()
{
    ::google::protobuf::internal::GetEmptyString();
    _cached_size_ = 0;
    _unknown_fields_.UnsafeSetDefault(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    word_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

DictionarySpecifics::~DictionarySpecifics()
{
    // @@protoc_insertion_point(destructor:sync_pb.DictionarySpecifics)
    SharedDtor();
}

void DictionarySpecifics::SharedDtor()
{
    _unknown_fields_.DestroyNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    word_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    if (this != &default_instance()) {
#else
    if (this != default_instance_) {
#endif
    }
}

void DictionarySpecifics::SetCachedSize(int size) const
{
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _cached_size_ = size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const DictionarySpecifics& DictionarySpecifics::default_instance()
{
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    protobuf_AddDesc_dictionary_5fspecifics_2eproto();
#else
    if (default_instance_ == NULL)
        protobuf_AddDesc_dictionary_5fspecifics_2eproto();
#endif
    return *default_instance_;
}

DictionarySpecifics* DictionarySpecifics::default_instance_ = NULL;

DictionarySpecifics* DictionarySpecifics::New(::google::protobuf::Arena* arena) const
{
    DictionarySpecifics* n = new DictionarySpecifics;
    if (arena != NULL) {
        arena->Own(n);
    }
    return n;
}

void DictionarySpecifics::Clear()
{
    // @@protoc_insertion_point(message_clear_start:sync_pb.DictionarySpecifics)
    if (has_word()) {
        word_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    }
    ::memset(_has_bits_, 0, sizeof(_has_bits_));
    _unknown_fields_.ClearToEmptyNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool DictionarySpecifics::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input)
{
#define DO_(EXPRESSION)                   \
    if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) \
    goto failure
    ::google::protobuf::uint32 tag;
    ::google::protobuf::io::LazyStringOutputStream unknown_fields_string(
        ::google::protobuf::internal::NewPermanentCallback(
            &MutableUnknownFieldsForDictionarySpecifics, this));
    ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
        &unknown_fields_string, false);
    // @@protoc_insertion_point(parse_start:sync_pb.DictionarySpecifics)
    for (;;) {
        ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
        tag = p.first;
        if (!p.second)
            goto handle_unusual;
        switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
        // optional string word = 1;
        case 1: {
            if (tag == 10) {
                DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                    input, this->mutable_word()));
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
    // @@protoc_insertion_point(parse_success:sync_pb.DictionarySpecifics)
    return true;
failure:
    // @@protoc_insertion_point(parse_failure:sync_pb.DictionarySpecifics)
    return false;
#undef DO_
}

void DictionarySpecifics::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const
{
    // @@protoc_insertion_point(serialize_start:sync_pb.DictionarySpecifics)
    // optional string word = 1;
    if (has_word()) {
        ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
            1, this->word(), output);
    }

    output->WriteRaw(unknown_fields().data(),
        static_cast<int>(unknown_fields().size()));
    // @@protoc_insertion_point(serialize_end:sync_pb.DictionarySpecifics)
}

int DictionarySpecifics::ByteSize() const
{
    // @@protoc_insertion_point(message_byte_size_start:sync_pb.DictionarySpecifics)
    int total_size = 0;

    // optional string word = 1;
    if (has_word()) {
        total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(this->word());
    }

    total_size += unknown_fields().size();

    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _cached_size_ = total_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    return total_size;
}

void DictionarySpecifics::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from)
{
    MergeFrom(*::google::protobuf::down_cast<const DictionarySpecifics*>(&from));
}

void DictionarySpecifics::MergeFrom(const DictionarySpecifics& from)
{
    // @@protoc_insertion_point(class_specific_merge_from_start:sync_pb.DictionarySpecifics)
    if (GOOGLE_PREDICT_FALSE(&from == this))
        MergeFromFail(__LINE__);
    if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
        if (from.has_word()) {
            set_has_word();
            word_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.word_);
        }
    }
    if (!from.unknown_fields().empty()) {
        mutable_unknown_fields()->append(from.unknown_fields());
    }
}

void DictionarySpecifics::CopyFrom(const DictionarySpecifics& from)
{
    // @@protoc_insertion_point(class_specific_copy_from_start:sync_pb.DictionarySpecifics)
    if (&from == this)
        return;
    Clear();
    MergeFrom(from);
}

bool DictionarySpecifics::IsInitialized() const
{

    return true;
}

void DictionarySpecifics::Swap(DictionarySpecifics* other)
{
    if (other == this)
        return;
    InternalSwap(other);
}
void DictionarySpecifics::InternalSwap(DictionarySpecifics* other)
{
    word_.Swap(&other->word_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
}

::std::string DictionarySpecifics::GetTypeName() const
{
    return "sync_pb.DictionarySpecifics";
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// DictionarySpecifics

// optional string word = 1;
bool DictionarySpecifics::has_word() const
{
    return (_has_bits_[0] & 0x00000001u) != 0;
}
void DictionarySpecifics::set_has_word()
{
    _has_bits_[0] |= 0x00000001u;
}
void DictionarySpecifics::clear_has_word()
{
    _has_bits_[0] &= ~0x00000001u;
}
void DictionarySpecifics::clear_word()
{
    word_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_word();
}
const ::std::string& DictionarySpecifics::word() const
{
    // @@protoc_insertion_point(field_get:sync_pb.DictionarySpecifics.word)
    return word_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void DictionarySpecifics::set_word(const ::std::string& value)
{
    set_has_word();
    word_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
    // @@protoc_insertion_point(field_set:sync_pb.DictionarySpecifics.word)
}
void DictionarySpecifics::set_word(const char* value)
{
    set_has_word();
    word_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
    // @@protoc_insertion_point(field_set_char:sync_pb.DictionarySpecifics.word)
}
void DictionarySpecifics::set_word(const char* value, size_t size)
{
    set_has_word();
    word_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        ::std::string(reinterpret_cast<const char*>(value), size));
    // @@protoc_insertion_point(field_set_pointer:sync_pb.DictionarySpecifics.word)
}
::std::string* DictionarySpecifics::mutable_word()
{
    set_has_word();
    // @@protoc_insertion_point(field_mutable:sync_pb.DictionarySpecifics.word)
    return word_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* DictionarySpecifics::release_word()
{
    // @@protoc_insertion_point(field_release:sync_pb.DictionarySpecifics.word)
    clear_has_word();
    return word_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void DictionarySpecifics::set_allocated_word(::std::string* word)
{
    if (word != NULL) {
        set_has_word();
    } else {
        clear_has_word();
    }
    word_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), word);
    // @@protoc_insertion_point(field_set_allocated:sync_pb.DictionarySpecifics.word)
}

#endif // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

} // namespace sync_pb

// @@protoc_insertion_point(global_scope)
