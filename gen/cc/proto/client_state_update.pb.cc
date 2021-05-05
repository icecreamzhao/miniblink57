// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: client_state_update.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "client_state_update.pb.h"

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

    void protobuf_ShutdownFile_client_5fstate_5fupdate_2eproto()
    {
        delete ScrollUpdate::default_instance_;
        delete ClientStateUpdate::default_instance_;
    }

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    void protobuf_AddDesc_client_5fstate_5fupdate_2eproto_impl()
    {
        GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
    void protobuf_AddDesc_client_5fstate_5fupdate_2eproto()
    {
        static bool already_here = false;
        if (already_here)
            return;
        already_here = true;
        GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
        ::cc::proto::protobuf_AddDesc_vector2df_2eproto();
        ScrollUpdate::default_instance_ = new ScrollUpdate();
        ClientStateUpdate::default_instance_ = new ClientStateUpdate();
        ScrollUpdate::default_instance_->InitAsDefaultInstance();
        ClientStateUpdate::default_instance_->InitAsDefaultInstance();
        ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_client_5fstate_5fupdate_2eproto);
    }

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_client_5fstate_5fupdate_2eproto_once_);
    void protobuf_AddDesc_client_5fstate_5fupdate_2eproto()
    {
        ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_client_5fstate_5fupdate_2eproto_once_,
            &protobuf_AddDesc_client_5fstate_5fupdate_2eproto_impl);
    }
#else
    // Force AddDescriptors() to be called at static initialization time.
    struct StaticDescriptorInitializer_client_5fstate_5fupdate_2eproto {
        StaticDescriptorInitializer_client_5fstate_5fupdate_2eproto()
        {
            protobuf_AddDesc_client_5fstate_5fupdate_2eproto();
        }
    } static_descriptor_initializer_client_5fstate_5fupdate_2eproto_;
#endif

    namespace {

        static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
        GOOGLE_ATTRIBUTE_NOINLINE static void MergeFromFail(int line)
        {
            GOOGLE_CHECK(false) << __FILE__ << ":" << line;
        }

    } // namespace

    // ===================================================================

    static ::std::string* MutableUnknownFieldsForScrollUpdate(
        ScrollUpdate* ptr)
    {
        return ptr->mutable_unknown_fields();
    }

#if !defined(_MSC_VER) || _MSC_VER >= 1900
    const int ScrollUpdate::kLayerIdFieldNumber;
    const int ScrollUpdate::kScrollDeltaFieldNumber;
#endif // !defined(_MSC_VER) || _MSC_VER >= 1900

    ScrollUpdate::ScrollUpdate()
        : ::google::protobuf::MessageLite()
        , _arena_ptr_(NULL)
    {
        SharedCtor();
        // @@protoc_insertion_point(constructor:cc.proto.ScrollUpdate)
    }

    void ScrollUpdate::InitAsDefaultInstance()
    {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        scroll_delta_ = const_cast<::cc::proto::Vector2dF*>(
            ::cc::proto::Vector2dF::internal_default_instance());
#else
        scroll_delta_ = const_cast<::cc::proto::Vector2dF*>(&::cc::proto::Vector2dF::default_instance());
#endif
    }

    ScrollUpdate::ScrollUpdate(const ScrollUpdate& from)
        : ::google::protobuf::MessageLite()
        , _arena_ptr_(NULL)
    {
        SharedCtor();
        MergeFrom(from);
        // @@protoc_insertion_point(copy_constructor:cc.proto.ScrollUpdate)
    }

    void ScrollUpdate::SharedCtor()
    {
        ::google::protobuf::internal::GetEmptyString();
        _cached_size_ = 0;
        _unknown_fields_.UnsafeSetDefault(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
        layer_id_ = 0;
        scroll_delta_ = NULL;
        ::memset(_has_bits_, 0, sizeof(_has_bits_));
    }

    ScrollUpdate::~ScrollUpdate()
    {
        // @@protoc_insertion_point(destructor:cc.proto.ScrollUpdate)
        SharedDtor();
    }

    void ScrollUpdate::SharedDtor()
    {
        _unknown_fields_.DestroyNoArena(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        if (this != &default_instance()) {
#else
        if (this != default_instance_) {
#endif
            delete scroll_delta_;
        }
    }

    void ScrollUpdate::SetCachedSize(int size) const
    {
        GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
        _cached_size_ = size;
        GOOGLE_SAFE_CONCURRENT_WRITES_END();
    }
    const ScrollUpdate& ScrollUpdate::default_instance()
    {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        protobuf_AddDesc_client_5fstate_5fupdate_2eproto();
#else
        if (default_instance_ == NULL)
            protobuf_AddDesc_client_5fstate_5fupdate_2eproto();
#endif
        return *default_instance_;
    }

    ScrollUpdate* ScrollUpdate::default_instance_ = NULL;

    ScrollUpdate* ScrollUpdate::New(::google::protobuf::Arena* arena) const
    {
        ScrollUpdate* n = new ScrollUpdate;
        if (arena != NULL) {
            arena->Own(n);
        }
        return n;
    }

    void ScrollUpdate::Clear()
    {
        // @@protoc_insertion_point(message_clear_start:cc.proto.ScrollUpdate)
        if (_has_bits_[0 / 32] & 3u) {
            layer_id_ = 0;
            if (has_scroll_delta()) {
                if (scroll_delta_ != NULL)
                    scroll_delta_->::cc::proto::Vector2dF::Clear();
            }
        }
        ::memset(_has_bits_, 0, sizeof(_has_bits_));
        _unknown_fields_.ClearToEmptyNoArena(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    }

    bool ScrollUpdate::MergePartialFromCodedStream(
        ::google::protobuf::io::CodedInputStream* input)
    {
#define DO_(EXPRESSION)                   \
    if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) \
    goto failure
        ::google::protobuf::uint32 tag;
        ::google::protobuf::io::LazyStringOutputStream unknown_fields_string(
            ::google::protobuf::internal::NewPermanentCallback(
                &MutableUnknownFieldsForScrollUpdate, this));
        ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
            &unknown_fields_string, false);
        // @@protoc_insertion_point(parse_start:cc.proto.ScrollUpdate)
        for (;;) {
            ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
            tag = p.first;
            if (!p.second)
                goto handle_unusual;
            switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
            // optional int32 layer_id = 1;
            case 1: {
                if (tag == 8) {
                    DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                        ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                        input, &layer_id_)));
                    set_has_layer_id();
                } else {
                    goto handle_unusual;
                }
                if (input->ExpectTag(18))
                    goto parse_scroll_delta;
                break;
            }

            // optional .cc.proto.Vector2dF scroll_delta = 2;
            case 2: {
                if (tag == 18) {
                parse_scroll_delta:
                    DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                        input, mutable_scroll_delta()));
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
        // @@protoc_insertion_point(parse_success:cc.proto.ScrollUpdate)
        return true;
    failure:
        // @@protoc_insertion_point(parse_failure:cc.proto.ScrollUpdate)
        return false;
#undef DO_
    }

    void ScrollUpdate::SerializeWithCachedSizes(
        ::google::protobuf::io::CodedOutputStream* output) const
    {
        // @@protoc_insertion_point(serialize_start:cc.proto.ScrollUpdate)
        // optional int32 layer_id = 1;
        if (has_layer_id()) {
            ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->layer_id(), output);
        }

        // optional .cc.proto.Vector2dF scroll_delta = 2;
        if (has_scroll_delta()) {
            ::google::protobuf::internal::WireFormatLite::WriteMessage(
                2, *this->scroll_delta_, output);
        }

        output->WriteRaw(unknown_fields().data(),
            static_cast<int>(unknown_fields().size()));
        // @@protoc_insertion_point(serialize_end:cc.proto.ScrollUpdate)
    }

    int ScrollUpdate::ByteSize() const
    {
        // @@protoc_insertion_point(message_byte_size_start:cc.proto.ScrollUpdate)
        int total_size = 0;

        if (_has_bits_[0 / 32] & 3u) {
            // optional int32 layer_id = 1;
            if (has_layer_id()) {
                total_size += 1 + ::google::protobuf::internal::WireFormatLite::Int32Size(this->layer_id());
            }

            // optional .cc.proto.Vector2dF scroll_delta = 2;
            if (has_scroll_delta()) {
                total_size += 1 + ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(*this->scroll_delta_);
            }
        }
        total_size += unknown_fields().size();

        GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
        _cached_size_ = total_size;
        GOOGLE_SAFE_CONCURRENT_WRITES_END();
        return total_size;
    }

    void ScrollUpdate::CheckTypeAndMergeFrom(
        const ::google::protobuf::MessageLite& from)
    {
        MergeFrom(*::google::protobuf::down_cast<const ScrollUpdate*>(&from));
    }

    void ScrollUpdate::MergeFrom(const ScrollUpdate& from)
    {
        // @@protoc_insertion_point(class_specific_merge_from_start:cc.proto.ScrollUpdate)
        if (GOOGLE_PREDICT_FALSE(&from == this))
            MergeFromFail(__LINE__);
        if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
            if (from.has_layer_id()) {
                set_layer_id(from.layer_id());
            }
            if (from.has_scroll_delta()) {
                mutable_scroll_delta()->::cc::proto::Vector2dF::MergeFrom(from.scroll_delta());
            }
        }
        if (!from.unknown_fields().empty()) {
            mutable_unknown_fields()->append(from.unknown_fields());
        }
    }

    void ScrollUpdate::CopyFrom(const ScrollUpdate& from)
    {
        // @@protoc_insertion_point(class_specific_copy_from_start:cc.proto.ScrollUpdate)
        if (&from == this)
            return;
        Clear();
        MergeFrom(from);
    }

    bool ScrollUpdate::IsInitialized() const
    {

        return true;
    }

    void ScrollUpdate::Swap(ScrollUpdate* other)
    {
        if (other == this)
            return;
        InternalSwap(other);
    }
    void ScrollUpdate::InternalSwap(ScrollUpdate* other)
    {
        std::swap(layer_id_, other->layer_id_);
        std::swap(scroll_delta_, other->scroll_delta_);
        std::swap(_has_bits_[0], other->_has_bits_[0]);
        _unknown_fields_.Swap(&other->_unknown_fields_);
        std::swap(_cached_size_, other->_cached_size_);
    }

    ::std::string ScrollUpdate::GetTypeName() const
    {
        return "cc.proto.ScrollUpdate";
    }

#if PROTOBUF_INLINE_NOT_IN_HEADERS
    // ScrollUpdate

    // optional int32 layer_id = 1;
    bool ScrollUpdate::has_layer_id() const
    {
        return (_has_bits_[0] & 0x00000001u) != 0;
    }
    void ScrollUpdate::set_has_layer_id()
    {
        _has_bits_[0] |= 0x00000001u;
    }
    void ScrollUpdate::clear_has_layer_id()
    {
        _has_bits_[0] &= ~0x00000001u;
    }
    void ScrollUpdate::clear_layer_id()
    {
        layer_id_ = 0;
        clear_has_layer_id();
    }
    ::google::protobuf::int32 ScrollUpdate::layer_id() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.ScrollUpdate.layer_id)
        return layer_id_;
    }
    void ScrollUpdate::set_layer_id(::google::protobuf::int32 value)
    {
        set_has_layer_id();
        layer_id_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.ScrollUpdate.layer_id)
    }

    // optional .cc.proto.Vector2dF scroll_delta = 2;
    bool ScrollUpdate::has_scroll_delta() const
    {
        return (_has_bits_[0] & 0x00000002u) != 0;
    }
    void ScrollUpdate::set_has_scroll_delta()
    {
        _has_bits_[0] |= 0x00000002u;
    }
    void ScrollUpdate::clear_has_scroll_delta()
    {
        _has_bits_[0] &= ~0x00000002u;
    }
    void ScrollUpdate::clear_scroll_delta()
    {
        if (scroll_delta_ != NULL)
            scroll_delta_->::cc::proto::Vector2dF::Clear();
        clear_has_scroll_delta();
    }
    const ::cc::proto::Vector2dF& ScrollUpdate::scroll_delta() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.ScrollUpdate.scroll_delta)
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        return scroll_delta_ != NULL ? *scroll_delta_ : *default_instance().scroll_delta_;
#else
        return scroll_delta_ != NULL ? *scroll_delta_ : *default_instance_->scroll_delta_;
#endif
    }
    ::cc::proto::Vector2dF* ScrollUpdate::mutable_scroll_delta()
    {
        set_has_scroll_delta();
        if (scroll_delta_ == NULL) {
            scroll_delta_ = new ::cc::proto::Vector2dF;
        }
        // @@protoc_insertion_point(field_mutable:cc.proto.ScrollUpdate.scroll_delta)
        return scroll_delta_;
    }
    ::cc::proto::Vector2dF* ScrollUpdate::release_scroll_delta()
    {
        // @@protoc_insertion_point(field_release:cc.proto.ScrollUpdate.scroll_delta)
        clear_has_scroll_delta();
        ::cc::proto::Vector2dF* temp = scroll_delta_;
        scroll_delta_ = NULL;
        return temp;
    }
    void ScrollUpdate::set_allocated_scroll_delta(::cc::proto::Vector2dF* scroll_delta)
    {
        delete scroll_delta_;
        scroll_delta_ = scroll_delta;
        if (scroll_delta) {
            set_has_scroll_delta();
        } else {
            clear_has_scroll_delta();
        }
        // @@protoc_insertion_point(field_set_allocated:cc.proto.ScrollUpdate.scroll_delta)
    }

#endif // PROTOBUF_INLINE_NOT_IN_HEADERS

    // ===================================================================

    static ::std::string* MutableUnknownFieldsForClientStateUpdate(
        ClientStateUpdate* ptr)
    {
        return ptr->mutable_unknown_fields();
    }

#if !defined(_MSC_VER) || _MSC_VER >= 1900
    const int ClientStateUpdate::kScrollUpdatesFieldNumber;
    const int ClientStateUpdate::kPageScaleDeltaFieldNumber;
#endif // !defined(_MSC_VER) || _MSC_VER >= 1900

    ClientStateUpdate::ClientStateUpdate()
        : ::google::protobuf::MessageLite()
        , _arena_ptr_(NULL)
    {
        SharedCtor();
        // @@protoc_insertion_point(constructor:cc.proto.ClientStateUpdate)
    }

    void ClientStateUpdate::InitAsDefaultInstance()
    {
    }

    ClientStateUpdate::ClientStateUpdate(const ClientStateUpdate& from)
        : ::google::protobuf::MessageLite()
        , _arena_ptr_(NULL)
    {
        SharedCtor();
        MergeFrom(from);
        // @@protoc_insertion_point(copy_constructor:cc.proto.ClientStateUpdate)
    }

    void ClientStateUpdate::SharedCtor()
    {
        ::google::protobuf::internal::GetEmptyString();
        _cached_size_ = 0;
        _unknown_fields_.UnsafeSetDefault(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
        page_scale_delta_ = 0;
        ::memset(_has_bits_, 0, sizeof(_has_bits_));
    }

    ClientStateUpdate::~ClientStateUpdate()
    {
        // @@protoc_insertion_point(destructor:cc.proto.ClientStateUpdate)
        SharedDtor();
    }

    void ClientStateUpdate::SharedDtor()
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

    void ClientStateUpdate::SetCachedSize(int size) const
    {
        GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
        _cached_size_ = size;
        GOOGLE_SAFE_CONCURRENT_WRITES_END();
    }
    const ClientStateUpdate& ClientStateUpdate::default_instance()
    {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        protobuf_AddDesc_client_5fstate_5fupdate_2eproto();
#else
        if (default_instance_ == NULL)
            protobuf_AddDesc_client_5fstate_5fupdate_2eproto();
#endif
        return *default_instance_;
    }

    ClientStateUpdate* ClientStateUpdate::default_instance_ = NULL;

    ClientStateUpdate* ClientStateUpdate::New(::google::protobuf::Arena* arena) const
    {
        ClientStateUpdate* n = new ClientStateUpdate;
        if (arena != NULL) {
            arena->Own(n);
        }
        return n;
    }

    void ClientStateUpdate::Clear()
    {
        // @@protoc_insertion_point(message_clear_start:cc.proto.ClientStateUpdate)
        page_scale_delta_ = 0;
        scroll_updates_.Clear();
        ::memset(_has_bits_, 0, sizeof(_has_bits_));
        _unknown_fields_.ClearToEmptyNoArena(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    }

    bool ClientStateUpdate::MergePartialFromCodedStream(
        ::google::protobuf::io::CodedInputStream* input)
    {
#define DO_(EXPRESSION)                   \
    if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) \
    goto failure
        ::google::protobuf::uint32 tag;
        ::google::protobuf::io::LazyStringOutputStream unknown_fields_string(
            ::google::protobuf::internal::NewPermanentCallback(
                &MutableUnknownFieldsForClientStateUpdate, this));
        ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
            &unknown_fields_string, false);
        // @@protoc_insertion_point(parse_start:cc.proto.ClientStateUpdate)
        for (;;) {
            ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
            tag = p.first;
            if (!p.second)
                goto handle_unusual;
            switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
            // repeated .cc.proto.ScrollUpdate scroll_updates = 1;
            case 1: {
                if (tag == 10) {
                    DO_(input->IncrementRecursionDepth());
                parse_loop_scroll_updates:
                    DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                        input, add_scroll_updates()));
                } else {
                    goto handle_unusual;
                }
                if (input->ExpectTag(10))
                    goto parse_loop_scroll_updates;
                input->UnsafeDecrementRecursionDepth();
                if (input->ExpectTag(21))
                    goto parse_page_scale_delta;
                break;
            }

            // optional float page_scale_delta = 2;
            case 2: {
                if (tag == 21) {
                parse_page_scale_delta:
                    DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                        float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                        input, &page_scale_delta_)));
                    set_has_page_scale_delta();
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
        // @@protoc_insertion_point(parse_success:cc.proto.ClientStateUpdate)
        return true;
    failure:
        // @@protoc_insertion_point(parse_failure:cc.proto.ClientStateUpdate)
        return false;
#undef DO_
    }

    void ClientStateUpdate::SerializeWithCachedSizes(
        ::google::protobuf::io::CodedOutputStream* output) const
    {
        // @@protoc_insertion_point(serialize_start:cc.proto.ClientStateUpdate)
        // repeated .cc.proto.ScrollUpdate scroll_updates = 1;
        for (unsigned int i = 0, n = this->scroll_updates_size(); i < n; i++) {
            ::google::protobuf::internal::WireFormatLite::WriteMessage(
                1, this->scroll_updates(i), output);
        }

        // optional float page_scale_delta = 2;
        if (has_page_scale_delta()) {
            ::google::protobuf::internal::WireFormatLite::WriteFloat(2, this->page_scale_delta(), output);
        }

        output->WriteRaw(unknown_fields().data(),
            static_cast<int>(unknown_fields().size()));
        // @@protoc_insertion_point(serialize_end:cc.proto.ClientStateUpdate)
    }

    int ClientStateUpdate::ByteSize() const
    {
        // @@protoc_insertion_point(message_byte_size_start:cc.proto.ClientStateUpdate)
        int total_size = 0;

        // optional float page_scale_delta = 2;
        if (has_page_scale_delta()) {
            total_size += 1 + 4;
        }

        // repeated .cc.proto.ScrollUpdate scroll_updates = 1;
        total_size += 1 * this->scroll_updates_size();
        for (int i = 0; i < this->scroll_updates_size(); i++) {
            total_size += ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
                this->scroll_updates(i));
        }

        total_size += unknown_fields().size();

        GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
        _cached_size_ = total_size;
        GOOGLE_SAFE_CONCURRENT_WRITES_END();
        return total_size;
    }

    void ClientStateUpdate::CheckTypeAndMergeFrom(
        const ::google::protobuf::MessageLite& from)
    {
        MergeFrom(*::google::protobuf::down_cast<const ClientStateUpdate*>(&from));
    }

    void ClientStateUpdate::MergeFrom(const ClientStateUpdate& from)
    {
        // @@protoc_insertion_point(class_specific_merge_from_start:cc.proto.ClientStateUpdate)
        if (GOOGLE_PREDICT_FALSE(&from == this))
            MergeFromFail(__LINE__);
        scroll_updates_.MergeFrom(from.scroll_updates_);
        if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
            if (from.has_page_scale_delta()) {
                set_page_scale_delta(from.page_scale_delta());
            }
        }
        if (!from.unknown_fields().empty()) {
            mutable_unknown_fields()->append(from.unknown_fields());
        }
    }

    void ClientStateUpdate::CopyFrom(const ClientStateUpdate& from)
    {
        // @@protoc_insertion_point(class_specific_copy_from_start:cc.proto.ClientStateUpdate)
        if (&from == this)
            return;
        Clear();
        MergeFrom(from);
    }

    bool ClientStateUpdate::IsInitialized() const
    {

        return true;
    }

    void ClientStateUpdate::Swap(ClientStateUpdate* other)
    {
        if (other == this)
            return;
        InternalSwap(other);
    }
    void ClientStateUpdate::InternalSwap(ClientStateUpdate* other)
    {
        scroll_updates_.UnsafeArenaSwap(&other->scroll_updates_);
        std::swap(page_scale_delta_, other->page_scale_delta_);
        std::swap(_has_bits_[0], other->_has_bits_[0]);
        _unknown_fields_.Swap(&other->_unknown_fields_);
        std::swap(_cached_size_, other->_cached_size_);
    }

    ::std::string ClientStateUpdate::GetTypeName() const
    {
        return "cc.proto.ClientStateUpdate";
    }

#if PROTOBUF_INLINE_NOT_IN_HEADERS
    // ClientStateUpdate

    // repeated .cc.proto.ScrollUpdate scroll_updates = 1;
    int ClientStateUpdate::scroll_updates_size() const
    {
        return scroll_updates_.size();
    }
    void ClientStateUpdate::clear_scroll_updates()
    {
        scroll_updates_.Clear();
    }
    const ::cc::proto::ScrollUpdate& ClientStateUpdate::scroll_updates(int index) const
    {
        // @@protoc_insertion_point(field_get:cc.proto.ClientStateUpdate.scroll_updates)
        return scroll_updates_.Get(index);
    }
    ::cc::proto::ScrollUpdate* ClientStateUpdate::mutable_scroll_updates(int index)
    {
        // @@protoc_insertion_point(field_mutable:cc.proto.ClientStateUpdate.scroll_updates)
        return scroll_updates_.Mutable(index);
    }
    ::cc::proto::ScrollUpdate* ClientStateUpdate::add_scroll_updates()
    {
        // @@protoc_insertion_point(field_add:cc.proto.ClientStateUpdate.scroll_updates)
        return scroll_updates_.Add();
    }
    ::google::protobuf::RepeatedPtrField<::cc::proto::ScrollUpdate>*
    ClientStateUpdate::mutable_scroll_updates()
    {
        // @@protoc_insertion_point(field_mutable_list:cc.proto.ClientStateUpdate.scroll_updates)
        return &scroll_updates_;
    }
    const ::google::protobuf::RepeatedPtrField<::cc::proto::ScrollUpdate>&
    ClientStateUpdate::scroll_updates() const
    {
        // @@protoc_insertion_point(field_list:cc.proto.ClientStateUpdate.scroll_updates)
        return scroll_updates_;
    }

    // optional float page_scale_delta = 2;
    bool ClientStateUpdate::has_page_scale_delta() const
    {
        return (_has_bits_[0] & 0x00000002u) != 0;
    }
    void ClientStateUpdate::set_has_page_scale_delta()
    {
        _has_bits_[0] |= 0x00000002u;
    }
    void ClientStateUpdate::clear_has_page_scale_delta()
    {
        _has_bits_[0] &= ~0x00000002u;
    }
    void ClientStateUpdate::clear_page_scale_delta()
    {
        page_scale_delta_ = 0;
        clear_has_page_scale_delta();
    }
    float ClientStateUpdate::page_scale_delta() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.ClientStateUpdate.page_scale_delta)
        return page_scale_delta_;
    }
    void ClientStateUpdate::set_page_scale_delta(float value)
    {
        set_has_page_scale_delta();
        page_scale_delta_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.ClientStateUpdate.page_scale_delta)
    }

#endif // PROTOBUF_INLINE_NOT_IN_HEADERS

    // @@protoc_insertion_point(namespace_scope)

} // namespace proto
} // namespace cc

// @@protoc_insertion_point(global_scope)
