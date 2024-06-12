// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_LEVELDB_WRAPPER_MOJOM_H_
#define CONTENT_COMMON_LEVELDB_WRAPPER_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
#include "cc/input/selection.h"
#include "cc/output/begin_frame_args.h"
#include "cc/output/compositor_frame.h"
#include "cc/output/compositor_frame_metadata.h"
#include "cc/output/filter_operation.h"
#include "cc/output/filter_operations.h"
#include "cc/quads/draw_quad.h"
#include "cc/quads/render_pass.h"
#include "cc/quads/shared_quad_state.h"
#include "cc/resources/returned_resource.h"
#include "cc/resources/transferable_resource.h"
#include "cc/surfaces/frame_sink_id.h"
#include "cc/surfaces/local_frame_id.h"
#include "cc/surfaces/surface_id.h"
#include "cc/surfaces/surface_info.h"
#include "cc/surfaces/surface_reference.h"
#include "cc/surfaces/surface_sequence.h"
#include "components/leveldb/public/interfaces/leveldb.mojom.h"
#include "content/common/bluetooth/web_bluetooth_device_id.h"
#include "content/common/content_export.h"
#include "content/common/frame_owner_properties.h"
#include "content/common/frame_replication_state.h"
#include "content/common/indexed_db/indexed_db_key.h"
#include "content/common/indexed_db/indexed_db_key_path.h"
#include "content/common/indexed_db/indexed_db_key_range.h"
#include "content/common/indexed_db/indexed_db_metadata.h"
#include "content/common/leveldb_wrapper.mojom-shared.h"
#include "content/common/media/media_devices.h"
#include "content/common/resize_params.h"
#include "content/common/resource_request.h"
#include "content/common/resource_request_completion_status.h"
#include "content/common/service_worker/embedded_worker_start_params.h"
#include "content/common/service_worker/service_worker_status_code.h"
#include "content/common/service_worker/service_worker_types.h"
#include "content/public/common/media_metadata.h"
#include "content/public/common/push_event_payload.h"
#include "content/public/common/referrer.h"
#include "content/public/common/renderer_preferences.h"
#include "content/public/common/resource_response.h"
#include "content/public/common/web_preferences.h"
#include "device/bluetooth/bluetooth_uuid.h"
#include "gpu/command_buffer/common/capabilities.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/mailbox_holder.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/gpu_preferences.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info.h"
#include "gpu/ipc/common/surface_handle.h"
#include "media/base/audio_codecs.h"
#include "media/base/audio_parameters.h"
#include "media/base/buffering_state.h"
#include "media/base/cdm_key_information.h"
#include "media/base/cdm_promise.h"
#include "media/base/channel_layout.h"
#include "media/base/content_decryption_module.h"
#include "media/base/decode_status.h"
#include "media/base/decryptor.h"
#include "media/base/demuxer_stream.h"
#include "media/base/eme_constants.h"
#include "media/base/encryption_scheme.h"
#include "media/base/pipeline_status.h"
#include "media/base/sample_format.h"
#include "media/base/subsample_entry.h"
#include "media/base/video_codecs.h"
#include "media/base/video_types.h"
#include "media/capture/video/video_capture_device_descriptor.h"
#include "media/capture/video_capture_types.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/control_message_proxy.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/lib/union_accessor.h"
#include "mojo/public/cpp/bindings/native_struct.h"
#include "mojo/public/cpp/bindings/no_interface.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"
#include "mojo/public/cpp/bindings/union_traits.h"
#include "net/base/network_change_notifier.h"
#include "net/url_request/redirect_info.h"
#include "services/service_manager/public/cpp/identity.h"
#include "services/service_manager/public/cpp/interface_provider_spec.h"
#include "services/service_manager/public/cpp/service_info.h"
#include "services/video_capture/public/cpp/capture_settings.h"
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/platform/modules/indexeddb/WebIDBTypes.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebPopupType.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkImageFilter.h"
#include "ui/base/ime/composition_text.h"
#include "ui/base/ime/composition_underline.h"
#include "ui/base/ime/text_input_mode.h"
#include "ui/base/ime/text_input_type.h"
#include "ui/base/window_open_disposition.h"
#include "ui/display/display.h"
#include "ui/events/event.h"
#include "ui/events/latency_info.h"
#include "ui/gfx/buffer_types.h"
#include "ui/gfx/color_space.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "ui/gfx/gpu_memory_buffer.h"
#include "ui/gfx/icc_profile.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/range/range.h"
#include "ui/gfx/range/range_f.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include "url/gurl.h"
#include "url/origin.h"
#include <string>
#include <vector>

namespace content {
namespace mojom {
    class LevelDBObserver;
    using LevelDBObserverPtr = mojo::InterfacePtr<LevelDBObserver>;
    using LevelDBObserverPtrInfo = mojo::InterfacePtrInfo<LevelDBObserver>;
    using ThreadSafeLevelDBObserverPtr = mojo::ThreadSafeInterfacePtr<LevelDBObserver>;
    using LevelDBObserverRequest = mojo::InterfaceRequest<LevelDBObserver>;
    using LevelDBObserverAssociatedPtr = mojo::AssociatedInterfacePtr<LevelDBObserver>;
    using ThreadSafeLevelDBObserverAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<LevelDBObserver>;
    using LevelDBObserverAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<LevelDBObserver>;
    using LevelDBObserverAssociatedRequest = mojo::AssociatedInterfaceRequest<LevelDBObserver>;

    class LevelDBWrapperGetAllCallback;
    using LevelDBWrapperGetAllCallbackPtr = mojo::InterfacePtr<LevelDBWrapperGetAllCallback>;
    using LevelDBWrapperGetAllCallbackPtrInfo = mojo::InterfacePtrInfo<LevelDBWrapperGetAllCallback>;
    using ThreadSafeLevelDBWrapperGetAllCallbackPtr = mojo::ThreadSafeInterfacePtr<LevelDBWrapperGetAllCallback>;
    using LevelDBWrapperGetAllCallbackRequest = mojo::InterfaceRequest<LevelDBWrapperGetAllCallback>;
    using LevelDBWrapperGetAllCallbackAssociatedPtr = mojo::AssociatedInterfacePtr<LevelDBWrapperGetAllCallback>;
    using ThreadSafeLevelDBWrapperGetAllCallbackAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<LevelDBWrapperGetAllCallback>;
    using LevelDBWrapperGetAllCallbackAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<LevelDBWrapperGetAllCallback>;
    using LevelDBWrapperGetAllCallbackAssociatedRequest = mojo::AssociatedInterfaceRequest<LevelDBWrapperGetAllCallback>;

    class LevelDBWrapper;
    using LevelDBWrapperPtr = mojo::InterfacePtr<LevelDBWrapper>;
    using LevelDBWrapperPtrInfo = mojo::InterfacePtrInfo<LevelDBWrapper>;
    using ThreadSafeLevelDBWrapperPtr = mojo::ThreadSafeInterfacePtr<LevelDBWrapper>;
    using LevelDBWrapperRequest = mojo::InterfaceRequest<LevelDBWrapper>;
    using LevelDBWrapperAssociatedPtr = mojo::AssociatedInterfacePtr<LevelDBWrapper>;
    using ThreadSafeLevelDBWrapperAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<LevelDBWrapper>;
    using LevelDBWrapperAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<LevelDBWrapper>;
    using LevelDBWrapperAssociatedRequest = mojo::AssociatedInterfaceRequest<LevelDBWrapper>;

    class KeyValue;
    using KeyValuePtr = mojo::StructPtr<KeyValue>;

    class LevelDBObserverProxy;

    template <typename ImplRefTraits>
    class LevelDBObserverStub;

    class LevelDBObserverRequestValidator;

    class CONTENT_EXPORT LevelDBObserver
        : public LevelDBObserverInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = LevelDBObserverProxy;

        template <typename ImplRefTraits>
        using Stub_ = LevelDBObserverStub<ImplRefTraits>;

        using RequestValidator_ = LevelDBObserverRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kKeyAddedMinVersion = 0,
            kKeyChangedMinVersion = 0,
            kKeyDeletedMinVersion = 0,
            kAllDeletedMinVersion = 0,
        };
        virtual ~LevelDBObserver() { }

        virtual void KeyAdded(const std::vector<uint8_t>& key, const std::vector<uint8_t>& value, const std::string& source) = 0;

        virtual void KeyChanged(const std::vector<uint8_t>& key, const std::vector<uint8_t>& new_value, const std::vector<uint8_t>& old_value, const std::string& source) = 0;

        virtual void KeyDeleted(const std::vector<uint8_t>& key, const std::vector<uint8_t>& old_value, const std::string& source) = 0;

        virtual void AllDeleted(const std::string& source) = 0;
    };

    class LevelDBWrapperGetAllCallbackProxy;

    template <typename ImplRefTraits>
    class LevelDBWrapperGetAllCallbackStub;

    class LevelDBWrapperGetAllCallbackRequestValidator;

    class CONTENT_EXPORT LevelDBWrapperGetAllCallback
        : public LevelDBWrapperGetAllCallbackInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = LevelDBWrapperGetAllCallbackProxy;

        template <typename ImplRefTraits>
        using Stub_ = LevelDBWrapperGetAllCallbackStub<ImplRefTraits>;

        using RequestValidator_ = LevelDBWrapperGetAllCallbackRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kCompleteMinVersion = 0,
        };
        virtual ~LevelDBWrapperGetAllCallback() { }

        virtual void Complete(bool success) = 0;
    };

    class LevelDBWrapperProxy;

    template <typename ImplRefTraits>
    class LevelDBWrapperStub;

    class LevelDBWrapperRequestValidator;
    class LevelDBWrapperResponseValidator;

    class CONTENT_EXPORT LevelDBWrapper
        : public LevelDBWrapperInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = true;
        static constexpr bool HasSyncMethods_ = true;

        using Proxy_ = LevelDBWrapperProxy;

        template <typename ImplRefTraits>
        using Stub_ = LevelDBWrapperStub<ImplRefTraits>;

        using RequestValidator_ = LevelDBWrapperRequestValidator;
        using ResponseValidator_ = LevelDBWrapperResponseValidator;
        enum MethodMinVersions : uint32_t {
            kAddObserverMinVersion = 0,
            kPutMinVersion = 0,
            kDeleteMinVersion = 0,
            kDeleteAllMinVersion = 0,
            kGetMinVersion = 0,
            kGetAllMinVersion = 0,
        };
        virtual ~LevelDBWrapper() { }

        virtual void AddObserver(LevelDBObserverAssociatedPtrInfo observer) = 0;

        using PutCallback = base::Callback<void(bool)>;
        virtual void Put(const std::vector<uint8_t>& key, const std::vector<uint8_t>& value, const std::string& source, const PutCallback& callback) = 0;

        using DeleteCallback = base::Callback<void(bool)>;
        virtual void Delete(const std::vector<uint8_t>& key, const std::string& source, const DeleteCallback& callback) = 0;

        using DeleteAllCallback = base::Callback<void(bool)>;
        virtual void DeleteAll(const std::string& source, const DeleteAllCallback& callback) = 0;

        using GetCallback = base::Callback<void(bool, const std::vector<uint8_t>&)>;
        virtual void Get(const std::vector<uint8_t>& key, const GetCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool GetAll(LevelDBWrapperGetAllCallbackAssociatedPtrInfo complete_callback, ::leveldb::mojom::DatabaseError* status, std::vector<KeyValuePtr>* data);

        using GetAllCallback = base::Callback<void(::leveldb::mojom::DatabaseError, std::vector<KeyValuePtr>)>;
        virtual void GetAll(LevelDBWrapperGetAllCallbackAssociatedPtrInfo complete_callback, const GetAllCallback& callback) = 0;
    };

    class CONTENT_EXPORT LevelDBObserverProxy
        : public LevelDBObserver {
    public:
        explicit LevelDBObserverProxy(mojo::MessageReceiverWithResponder* receiver);
        void KeyAdded(const std::vector<uint8_t>& key, const std::vector<uint8_t>& value, const std::string& source) override;
        void KeyChanged(const std::vector<uint8_t>& key, const std::vector<uint8_t>& new_value, const std::vector<uint8_t>& old_value, const std::string& source) override;
        void KeyDeleted(const std::vector<uint8_t>& key, const std::vector<uint8_t>& old_value, const std::string& source) override;
        void AllDeleted(const std::string& source) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class CONTENT_EXPORT LevelDBWrapperGetAllCallbackProxy
        : public LevelDBWrapperGetAllCallback {
    public:
        explicit LevelDBWrapperGetAllCallbackProxy(mojo::MessageReceiverWithResponder* receiver);
        void Complete(bool success) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class CONTENT_EXPORT LevelDBWrapperProxy
        : public LevelDBWrapper {
    public:
        explicit LevelDBWrapperProxy(mojo::MessageReceiverWithResponder* receiver);
        void AddObserver(LevelDBObserverAssociatedPtrInfo observer) override;
        void Put(const std::vector<uint8_t>& key, const std::vector<uint8_t>& value, const std::string& source, const PutCallback& callback) override;
        void Delete(const std::vector<uint8_t>& key, const std::string& source, const DeleteCallback& callback) override;
        void DeleteAll(const std::string& source, const DeleteAllCallback& callback) override;
        void Get(const std::vector<uint8_t>& key, const GetCallback& callback) override;
        bool GetAll(LevelDBWrapperGetAllCallbackAssociatedPtrInfo complete_callback, ::leveldb::mojom::DatabaseError* status, std::vector<KeyValuePtr>* data) override;
        void GetAll(LevelDBWrapperGetAllCallbackAssociatedPtrInfo complete_callback, const GetAllCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class CONTENT_EXPORT LevelDBObserverStubDispatch {
    public:
        static bool Accept(LevelDBObserver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(LevelDBObserver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<LevelDBObserver>>
    class LevelDBObserverStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        LevelDBObserverStub() { }
        ~LevelDBObserverStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return LevelDBObserverStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return LevelDBObserverStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT LevelDBWrapperGetAllCallbackStubDispatch {
    public:
        static bool Accept(LevelDBWrapperGetAllCallback* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(LevelDBWrapperGetAllCallback* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<LevelDBWrapperGetAllCallback>>
    class LevelDBWrapperGetAllCallbackStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        LevelDBWrapperGetAllCallbackStub() { }
        ~LevelDBWrapperGetAllCallbackStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return LevelDBWrapperGetAllCallbackStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return LevelDBWrapperGetAllCallbackStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT LevelDBWrapperStubDispatch {
    public:
        static bool Accept(LevelDBWrapper* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(LevelDBWrapper* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<LevelDBWrapper>>
    class LevelDBWrapperStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        LevelDBWrapperStub() { }
        ~LevelDBWrapperStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return LevelDBWrapperStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return LevelDBWrapperStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT LevelDBObserverRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT LevelDBWrapperGetAllCallbackRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT LevelDBWrapperRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT LevelDBWrapperResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class CONTENT_EXPORT KeyValue {
    public:
        using DataView = KeyValueDataView;
        using Data_ = internal::KeyValue_Data;

        static KeyValuePtr New();

        template <typename U>
        static KeyValuePtr From(const U& u)
        {
            return mojo::TypeConverter<KeyValuePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, KeyValue>::Convert(*this);
        }

        KeyValue();
        ~KeyValue();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = KeyValuePtr>
        KeyValuePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, KeyValue>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                KeyValue::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                KeyValue::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::vector<uint8_t> key;
        std::vector<uint8_t> value;
    };

    template <typename StructPtrType>
    KeyValuePtr KeyValue::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->key = mojo::internal::Clone(key);
        rv->value = mojo::internal::Clone(value);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, KeyValue>::value>::type*>
    bool KeyValue::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->key, other.key))
            return false;
        if (!mojo::internal::Equals(this->value, other.value))
            return false;
        return true;
    }

} // namespace mojom
} // namespace content

namespace mojo {

template <>
struct CONTENT_EXPORT StructTraits<::content::mojom::KeyValue::DataView,
    ::content::mojom::KeyValuePtr> {
    static bool IsNull(const ::content::mojom::KeyValuePtr& input) { return !input; }
    static void SetToNull(::content::mojom::KeyValuePtr* output) { output->reset(); }

    static const decltype(::content::mojom::KeyValue::key)& key(
        const ::content::mojom::KeyValuePtr& input)
    {
        return input->key;
    }

    static const decltype(::content::mojom::KeyValue::value)& value(
        const ::content::mojom::KeyValuePtr& input)
    {
        return input->value;
    }

    static bool Read(::content::mojom::KeyValue::DataView input, ::content::mojom::KeyValuePtr* output);
};

} // namespace mojo

#endif // CONTENT_COMMON_LEVELDB_WRAPPER_MOJOM_H_