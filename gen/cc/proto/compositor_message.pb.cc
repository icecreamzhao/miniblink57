// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: compositor_message.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "compositor_message.pb.h"

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

    void protobuf_ShutdownFile_compositor_5fmessage_2eproto()
    {
        delete CompositorMessage::default_instance_;
    }

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    void protobuf_AddDesc_compositor_5fmessage_2eproto_impl()
    {
        GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
    void protobuf_AddDesc_compositor_5fmessage_2eproto()
    {
        static bool already_here = false;
        if (already_here)
            return;
        already_here = true;
        GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
        ::cc::proto::protobuf_AddDesc_client_5fstate_5fupdate_2eproto();
        ::cc::proto::protobuf_AddDesc_layer_5ftree_5fhost_2eproto();
        CompositorMessage::default_instance_ = new CompositorMessage();
        CompositorMessage::default_instance_->InitAsDefaultInstance();
        ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_compositor_5fmessage_2eproto);
    }

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_compositor_5fmessage_2eproto_once_);
    void protobuf_AddDesc_compositor_5fmessage_2eproto()
    {
        ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_compositor_5fmessage_2eproto_once_,
            &protobuf_AddDesc_compositor_5fmessage_2eproto_impl);
    }
#else
    // Force AddDescriptors() to be called at static initialization time.
    struct StaticDescriptorInitializer_compositor_5fmessage_2eproto {
        StaticDescriptorInitializer_compositor_5fmessage_2eproto()
        {
            protobuf_AddDesc_compositor_5fmessage_2eproto();
        }
    } static_descriptor_initializer_compositor_5fmessage_2eproto_;
#endif

    namespace {

        static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
        GOOGLE_ATTRIBUTE_NOINLINE static void MergeFromFail(int line)
        {
            GOOGLE_CHECK(false) << __FILE__ << ":" << line;
        }

    } // namespace

    // ===================================================================

    static ::std::string* MutableUnknownFieldsForCompositorMessage(
        CompositorMessage* ptr)
    {
        return ptr->mutable_unknown_fields();
    }

#if !defined(_MSC_VER) || _MSC_VER >= 1900
    const int CompositorMessage::kLayerTreeHostFieldNumber;
    const int CompositorMessage::kFrameAckFieldNumber;
    const int CompositorMessage::kClientStateUpdateFieldNumber;
    const int CompositorMessage::kClientStateUpdateAckFieldNumber;
#endif // !defined(_MSC_VER) || _MSC_VER >= 1900

    CompositorMessage::CompositorMessage()
        : ::google::protobuf::MessageLite()
        , _arena_ptr_(NULL)
    {
        SharedCtor();
        // @@protoc_insertion_point(constructor:cc.proto.CompositorMessage)
    }

    void CompositorMessage::InitAsDefaultInstance()
    {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        layer_tree_host_ = const_cast<::cc::proto::LayerTreeHost*>(
            ::cc::proto::LayerTreeHost::internal_default_instance());
#else
        layer_tree_host_ = const_cast<::cc::proto::LayerTreeHost*>(&::cc::proto::LayerTreeHost::default_instance());
#endif
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        client_state_update_ = const_cast<::cc::proto::ClientStateUpdate*>(
            ::cc::proto::ClientStateUpdate::internal_default_instance());
#else
        client_state_update_ = const_cast<::cc::proto::ClientStateUpdate*>(&::cc::proto::ClientStateUpdate::default_instance());
#endif
    }

    CompositorMessage::CompositorMessage(const CompositorMessage& from)
        : ::google::protobuf::MessageLite()
        , _arena_ptr_(NULL)
    {
        SharedCtor();
        MergeFrom(from);
        // @@protoc_insertion_point(copy_constructor:cc.proto.CompositorMessage)
    }

    void CompositorMessage::SharedCtor()
    {
        ::google::protobuf::internal::GetEmptyString();
        _cached_size_ = 0;
        _unknown_fields_.UnsafeSetDefault(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
        layer_tree_host_ = NULL;
        frame_ack_ = false;
        client_state_update_ = NULL;
        client_state_update_ack_ = false;
        ::memset(_has_bits_, 0, sizeof(_has_bits_));
    }

    CompositorMessage::~CompositorMessage()
    {
        // @@protoc_insertion_point(destructor:cc.proto.CompositorMessage)
        SharedDtor();
    }

    void CompositorMessage::SharedDtor()
    {
        _unknown_fields_.DestroyNoArena(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        if (this != &default_instance()) {
#else
        if (this != default_instance_) {
#endif
            delete layer_tree_host_;
            delete client_state_update_;
        }
    }

    void CompositorMessage::SetCachedSize(int size) const
    {
        GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
        _cached_size_ = size;
        GOOGLE_SAFE_CONCURRENT_WRITES_END();
    }
    const CompositorMessage& CompositorMessage::default_instance()
    {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        protobuf_AddDesc_compositor_5fmessage_2eproto();
#else
        if (default_instance_ == NULL)
            protobuf_AddDesc_compositor_5fmessage_2eproto();
#endif
        return *default_instance_;
    }

    CompositorMessage* CompositorMessage::default_instance_ = NULL;

    CompositorMessage* CompositorMessage::New(::google::protobuf::Arena* arena) const
    {
        CompositorMessage* n = new CompositorMessage;
        if (arena != NULL) {
            arena->Own(n);
        }
        return n;
    }

    void CompositorMessage::Clear()
    {
// @@protoc_insertion_point(message_clear_start:cc.proto.CompositorMessage)
#if defined(__clang__)
#define ZR_HELPER_(f)                                                                                       \
    _Pragma("clang diagnostic push")                                                                        \
        _Pragma("clang diagnostic ignored \"-Winvalid-offsetof\"") __builtin_offsetof(CompositorMessage, f) \
            _Pragma("clang diagnostic pop")
#else
#define ZR_HELPER_(f) reinterpret_cast<char*>( \
    &reinterpret_cast<CompositorMessage*>(16)->f)
#endif

#define ZR_(first, last)                                          \
    do {                                                          \
        ::memset(&first, 0,                                       \
            ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last)); \
    } while (0)

        if (_has_bits_[0 / 32] & 15u) {
            ZR_(frame_ack_, client_state_update_ack_);
            if (has_layer_tree_host()) {
                if (layer_tree_host_ != NULL)
                    layer_tree_host_->::cc::proto::LayerTreeHost::Clear();
            }
            if (has_client_state_update()) {
                if (client_state_update_ != NULL)
                    client_state_update_->::cc::proto::ClientStateUpdate::Clear();
            }
        }

#undef ZR_HELPER_
#undef ZR_

        ::memset(_has_bits_, 0, sizeof(_has_bits_));
        _unknown_fields_.ClearToEmptyNoArena(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    }

    bool CompositorMessage::MergePartialFromCodedStream(
        ::google::protobuf::io::CodedInputStream* input)
    {
#define DO_(EXPRESSION)                   \
    if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) \
    goto failure
        ::google::protobuf::uint32 tag;
        ::google::protobuf::io::LazyStringOutputStream unknown_fields_string(
            ::google::protobuf::internal::NewPermanentCallback(
                &MutableUnknownFieldsForCompositorMessage, this));
        ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
            &unknown_fields_string, false);
        // @@protoc_insertion_point(parse_start:cc.proto.CompositorMessage)
        for (;;) {
            ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
            tag = p.first;
            if (!p.second)
                goto handle_unusual;
            switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
            // optional .cc.proto.LayerTreeHost layer_tree_host = 3;
            case 3: {
                if (tag == 26) {
                    DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                        input, mutable_layer_tree_host()));
                } else {
                    goto handle_unusual;
                }
                if (input->ExpectTag(32))
                    goto parse_frame_ack;
                break;
            }

            // optional bool frame_ack = 4;
            case 4: {
                if (tag == 32) {
                parse_frame_ack:
                    DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                        bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                        input, &frame_ack_)));
                    set_has_frame_ack();
                } else {
                    goto handle_unusual;
                }
                if (input->ExpectTag(42))
                    goto parse_client_state_update;
                break;
            }

            // optional .cc.proto.ClientStateUpdate client_state_update = 5;
            case 5: {
                if (tag == 42) {
                parse_client_state_update:
                    DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                        input, mutable_client_state_update()));
                } else {
                    goto handle_unusual;
                }
                if (input->ExpectTag(48))
                    goto parse_client_state_update_ack;
                break;
            }

            // optional bool client_state_update_ack = 6;
            case 6: {
                if (tag == 48) {
                parse_client_state_update_ack:
                    DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                        bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                        input, &client_state_update_ack_)));
                    set_has_client_state_update_ack();
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
        // @@protoc_insertion_point(parse_success:cc.proto.CompositorMessage)
        return true;
    failure:
        // @@protoc_insertion_point(parse_failure:cc.proto.CompositorMessage)
        return false;
#undef DO_
    }

    void CompositorMessage::SerializeWithCachedSizes(
        ::google::protobuf::io::CodedOutputStream* output) const
    {
        // @@protoc_insertion_point(serialize_start:cc.proto.CompositorMessage)
        // optional .cc.proto.LayerTreeHost layer_tree_host = 3;
        if (has_layer_tree_host()) {
            ::google::protobuf::internal::WireFormatLite::WriteMessage(
                3, *this->layer_tree_host_, output);
        }

        // optional bool frame_ack = 4;
        if (has_frame_ack()) {
            ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->frame_ack(), output);
        }

        // optional .cc.proto.ClientStateUpdate client_state_update = 5;
        if (has_client_state_update()) {
            ::google::protobuf::internal::WireFormatLite::WriteMessage(
                5, *this->client_state_update_, output);
        }

        // optional bool client_state_update_ack = 6;
        if (has_client_state_update_ack()) {
            ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->client_state_update_ack(), output);
        }

        output->WriteRaw(unknown_fields().data(),
            static_cast<int>(unknown_fields().size()));
        // @@protoc_insertion_point(serialize_end:cc.proto.CompositorMessage)
    }

    int CompositorMessage::ByteSize() const
    {
        // @@protoc_insertion_point(message_byte_size_start:cc.proto.CompositorMessage)
        int total_size = 0;

        if (_has_bits_[0 / 32] & 15u) {
            // optional .cc.proto.LayerTreeHost layer_tree_host = 3;
            if (has_layer_tree_host()) {
                total_size += 1 + ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(*this->layer_tree_host_);
            }

            // optional bool frame_ack = 4;
            if (has_frame_ack()) {
                total_size += 1 + 1;
            }

            // optional .cc.proto.ClientStateUpdate client_state_update = 5;
            if (has_client_state_update()) {
                total_size += 1 + ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(*this->client_state_update_);
            }

            // optional bool client_state_update_ack = 6;
            if (has_client_state_update_ack()) {
                total_size += 1 + 1;
            }
        }
        total_size += unknown_fields().size();

        GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
        _cached_size_ = total_size;
        GOOGLE_SAFE_CONCURRENT_WRITES_END();
        return total_size;
    }

    void CompositorMessage::CheckTypeAndMergeFrom(
        const ::google::protobuf::MessageLite& from)
    {
        MergeFrom(*::google::protobuf::down_cast<const CompositorMessage*>(&from));
    }

    void CompositorMessage::MergeFrom(const CompositorMessage& from)
    {
        // @@protoc_insertion_point(class_specific_merge_from_start:cc.proto.CompositorMessage)
        if (GOOGLE_PREDICT_FALSE(&from == this))
            MergeFromFail(__LINE__);
        if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
            if (from.has_layer_tree_host()) {
                mutable_layer_tree_host()->::cc::proto::LayerTreeHost::MergeFrom(from.layer_tree_host());
            }
            if (from.has_frame_ack()) {
                set_frame_ack(from.frame_ack());
            }
            if (from.has_client_state_update()) {
                mutable_client_state_update()->::cc::proto::ClientStateUpdate::MergeFrom(from.client_state_update());
            }
            if (from.has_client_state_update_ack()) {
                set_client_state_update_ack(from.client_state_update_ack());
            }
        }
        if (!from.unknown_fields().empty()) {
            mutable_unknown_fields()->append(from.unknown_fields());
        }
    }

    void CompositorMessage::CopyFrom(const CompositorMessage& from)
    {
        // @@protoc_insertion_point(class_specific_copy_from_start:cc.proto.CompositorMessage)
        if (&from == this)
            return;
        Clear();
        MergeFrom(from);
    }

    bool CompositorMessage::IsInitialized() const
    {

        return true;
    }

    void CompositorMessage::Swap(CompositorMessage* other)
    {
        if (other == this)
            return;
        InternalSwap(other);
    }
    void CompositorMessage::InternalSwap(CompositorMessage* other)
    {
        std::swap(layer_tree_host_, other->layer_tree_host_);
        std::swap(frame_ack_, other->frame_ack_);
        std::swap(client_state_update_, other->client_state_update_);
        std::swap(client_state_update_ack_, other->client_state_update_ack_);
        std::swap(_has_bits_[0], other->_has_bits_[0]);
        _unknown_fields_.Swap(&other->_unknown_fields_);
        std::swap(_cached_size_, other->_cached_size_);
    }

    ::std::string CompositorMessage::GetTypeName() const
    {
        return "cc.proto.CompositorMessage";
    }

#if PROTOBUF_INLINE_NOT_IN_HEADERS
    // CompositorMessage

    // optional .cc.proto.LayerTreeHost layer_tree_host = 3;
    bool CompositorMessage::has_layer_tree_host() const
    {
        return (_has_bits_[0] & 0x00000001u) != 0;
    }
    void CompositorMessage::set_has_layer_tree_host()
    {
        _has_bits_[0] |= 0x00000001u;
    }
    void CompositorMessage::clear_has_layer_tree_host()
    {
        _has_bits_[0] &= ~0x00000001u;
    }
    void CompositorMessage::clear_layer_tree_host()
    {
        if (layer_tree_host_ != NULL)
            layer_tree_host_->::cc::proto::LayerTreeHost::Clear();
        clear_has_layer_tree_host();
    }
    const ::cc::proto::LayerTreeHost& CompositorMessage::layer_tree_host() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.CompositorMessage.layer_tree_host)
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        return layer_tree_host_ != NULL ? *layer_tree_host_ : *default_instance().layer_tree_host_;
#else
        return layer_tree_host_ != NULL ? *layer_tree_host_ : *default_instance_->layer_tree_host_;
#endif
    }
    ::cc::proto::LayerTreeHost* CompositorMessage::mutable_layer_tree_host()
    {
        set_has_layer_tree_host();
        if (layer_tree_host_ == NULL) {
            layer_tree_host_ = new ::cc::proto::LayerTreeHost;
        }
        // @@protoc_insertion_point(field_mutable:cc.proto.CompositorMessage.layer_tree_host)
        return layer_tree_host_;
    }
    ::cc::proto::LayerTreeHost* CompositorMessage::release_layer_tree_host()
    {
        // @@protoc_insertion_point(field_release:cc.proto.CompositorMessage.layer_tree_host)
        clear_has_layer_tree_host();
        ::cc::proto::LayerTreeHost* temp = layer_tree_host_;
        layer_tree_host_ = NULL;
        return temp;
    }
    void CompositorMessage::set_allocated_layer_tree_host(::cc::proto::LayerTreeHost* layer_tree_host)
    {
        delete layer_tree_host_;
        layer_tree_host_ = layer_tree_host;
        if (layer_tree_host) {
            set_has_layer_tree_host();
        } else {
            clear_has_layer_tree_host();
        }
        // @@protoc_insertion_point(field_set_allocated:cc.proto.CompositorMessage.layer_tree_host)
    }

    // optional bool frame_ack = 4;
    bool CompositorMessage::has_frame_ack() const
    {
        return (_has_bits_[0] & 0x00000002u) != 0;
    }
    void CompositorMessage::set_has_frame_ack()
    {
        _has_bits_[0] |= 0x00000002u;
    }
    void CompositorMessage::clear_has_frame_ack()
    {
        _has_bits_[0] &= ~0x00000002u;
    }
    void CompositorMessage::clear_frame_ack()
    {
        frame_ack_ = false;
        clear_has_frame_ack();
    }
    bool CompositorMessage::frame_ack() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.CompositorMessage.frame_ack)
        return frame_ack_;
    }
    void CompositorMessage::set_frame_ack(bool value)
    {
        set_has_frame_ack();
        frame_ack_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.CompositorMessage.frame_ack)
    }

    // optional .cc.proto.ClientStateUpdate client_state_update = 5;
    bool CompositorMessage::has_client_state_update() const
    {
        return (_has_bits_[0] & 0x00000004u) != 0;
    }
    void CompositorMessage::set_has_client_state_update()
    {
        _has_bits_[0] |= 0x00000004u;
    }
    void CompositorMessage::clear_has_client_state_update()
    {
        _has_bits_[0] &= ~0x00000004u;
    }
    void CompositorMessage::clear_client_state_update()
    {
        if (client_state_update_ != NULL)
            client_state_update_->::cc::proto::ClientStateUpdate::Clear();
        clear_has_client_state_update();
    }
    const ::cc::proto::ClientStateUpdate& CompositorMessage::client_state_update() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.CompositorMessage.client_state_update)
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        return client_state_update_ != NULL ? *client_state_update_ : *default_instance().client_state_update_;
#else
        return client_state_update_ != NULL ? *client_state_update_ : *default_instance_->client_state_update_;
#endif
    }
    ::cc::proto::ClientStateUpdate* CompositorMessage::mutable_client_state_update()
    {
        set_has_client_state_update();
        if (client_state_update_ == NULL) {
            client_state_update_ = new ::cc::proto::ClientStateUpdate;
        }
        // @@protoc_insertion_point(field_mutable:cc.proto.CompositorMessage.client_state_update)
        return client_state_update_;
    }
    ::cc::proto::ClientStateUpdate* CompositorMessage::release_client_state_update()
    {
        // @@protoc_insertion_point(field_release:cc.proto.CompositorMessage.client_state_update)
        clear_has_client_state_update();
        ::cc::proto::ClientStateUpdate* temp = client_state_update_;
        client_state_update_ = NULL;
        return temp;
    }
    void CompositorMessage::set_allocated_client_state_update(::cc::proto::ClientStateUpdate* client_state_update)
    {
        delete client_state_update_;
        client_state_update_ = client_state_update;
        if (client_state_update) {
            set_has_client_state_update();
        } else {
            clear_has_client_state_update();
        }
        // @@protoc_insertion_point(field_set_allocated:cc.proto.CompositorMessage.client_state_update)
    }

    // optional bool client_state_update_ack = 6;
    bool CompositorMessage::has_client_state_update_ack() const
    {
        return (_has_bits_[0] & 0x00000008u) != 0;
    }
    void CompositorMessage::set_has_client_state_update_ack()
    {
        _has_bits_[0] |= 0x00000008u;
    }
    void CompositorMessage::clear_has_client_state_update_ack()
    {
        _has_bits_[0] &= ~0x00000008u;
    }
    void CompositorMessage::clear_client_state_update_ack()
    {
        client_state_update_ack_ = false;
        clear_has_client_state_update_ack();
    }
    bool CompositorMessage::client_state_update_ack() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.CompositorMessage.client_state_update_ack)
        return client_state_update_ack_;
    }
    void CompositorMessage::set_client_state_update_ack(bool value)
    {
        set_has_client_state_update_ack();
        client_state_update_ack_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.CompositorMessage.client_state_update_ack)
    }

#endif // PROTOBUF_INLINE_NOT_IN_HEADERS

    // @@protoc_insertion_point(namespace_scope)

} // namespace proto
} // namespace cc

// @@protoc_insertion_point(global_scope)
