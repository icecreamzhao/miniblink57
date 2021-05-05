// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_FACTORY_MOJOM_H_
#define SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_FACTORY_MOJOM_H_

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
#include "media/capture/mojo/video_capture_types.mojom.h"
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
#include "services/service_manager/public/cpp/identity.h"
#include "services/service_manager/public/cpp/interface_provider_spec.h"
#include "services/service_manager/public/cpp/service_info.h"
#include "services/video_capture/public/cpp/capture_settings.h"
#include "services/video_capture/public/interfaces/capture_settings.mojom.h"
#include "services/video_capture/public/interfaces/device.mojom.h"
#include "services/video_capture/public/interfaces/device_descriptor.mojom.h"
#include "services/video_capture/public/interfaces/device_factory.mojom-shared.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "url/gurl.h"
#include <string>
#include <vector>

namespace video_capture {
namespace mojom {
    class DeviceFactory;
    using DeviceFactoryPtr = mojo::InterfacePtr<DeviceFactory>;
    using DeviceFactoryPtrInfo = mojo::InterfacePtrInfo<DeviceFactory>;
    using ThreadSafeDeviceFactoryPtr = mojo::ThreadSafeInterfacePtr<DeviceFactory>;
    using DeviceFactoryRequest = mojo::InterfaceRequest<DeviceFactory>;
    using DeviceFactoryAssociatedPtr = mojo::AssociatedInterfacePtr<DeviceFactory>;
    using ThreadSafeDeviceFactoryAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<DeviceFactory>;
    using DeviceFactoryAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<DeviceFactory>;
    using DeviceFactoryAssociatedRequest = mojo::AssociatedInterfaceRequest<DeviceFactory>;

    class DeviceFactoryProxy;

    template <typename ImplRefTraits>
    class DeviceFactoryStub;

    class DeviceFactoryRequestValidator;
    class DeviceFactoryResponseValidator;

    class DeviceFactory
        : public DeviceFactoryInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = DeviceFactoryProxy;

        template <typename ImplRefTraits>
        using Stub_ = DeviceFactoryStub<ImplRefTraits>;

        using RequestValidator_ = DeviceFactoryRequestValidator;
        using ResponseValidator_ = DeviceFactoryResponseValidator;
        enum MethodMinVersions : uint32_t {
            kEnumerateDeviceDescriptorsMinVersion = 0,
            kGetSupportedFormatsMinVersion = 0,
            kCreateDeviceMinVersion = 0,
        };
        virtual ~DeviceFactory() { }

        using EnumerateDeviceDescriptorsCallback = base::Callback<void(const std::vector<media::VideoCaptureDeviceDescriptor>&)>;
        virtual void EnumerateDeviceDescriptors(const EnumerateDeviceDescriptorsCallback& callback) = 0;

        using GetSupportedFormatsCallback = base::Callback<void(const std::vector<video_capture::I420CaptureFormat>&)>;
        virtual void GetSupportedFormats(const std::string& device_id, const GetSupportedFormatsCallback& callback) = 0;

        using CreateDeviceCallback = base::Callback<void(DeviceAccessResultCode)>;
        virtual void CreateDevice(const std::string& device_id, ::video_capture::mojom::DeviceRequest device_request, const CreateDeviceCallback& callback) = 0;
    };

    class DeviceFactoryProxy
        : public DeviceFactory {
    public:
        explicit DeviceFactoryProxy(mojo::MessageReceiverWithResponder* receiver);
        void EnumerateDeviceDescriptors(const EnumerateDeviceDescriptorsCallback& callback) override;
        void GetSupportedFormats(const std::string& device_id, const GetSupportedFormatsCallback& callback) override;
        void CreateDevice(const std::string& device_id, ::video_capture::mojom::DeviceRequest device_request, const CreateDeviceCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class DeviceFactoryStubDispatch {
    public:
        static bool Accept(DeviceFactory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(DeviceFactory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<DeviceFactory>>
    class DeviceFactoryStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        DeviceFactoryStub() { }
        ~DeviceFactoryStub() override { }

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
            return DeviceFactoryStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DeviceFactoryStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class DeviceFactoryRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class DeviceFactoryResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace video_capture

namespace mojo {

} // namespace mojo

#endif // SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_FACTORY_MOJOM_H_