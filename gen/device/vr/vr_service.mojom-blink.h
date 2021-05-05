// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_VR_VR_SERVICE_MOJOM_BLINK_H_
#define DEVICE_VR_VR_SERVICE_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/vr/vr_service.mojom-shared.h"
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

#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"

namespace device {
namespace mojom {
    namespace blink {
        using VRDisplayEventReason = VRDisplayEventReason; // Alias for definition in the parent namespace.
        class VRService;
        using VRServicePtr = mojo::InterfacePtr<VRService>;
        using VRServicePtrInfo = mojo::InterfacePtrInfo<VRService>;
        using ThreadSafeVRServicePtr = mojo::ThreadSafeInterfacePtr<VRService>;
        using VRServiceRequest = mojo::InterfaceRequest<VRService>;
        using VRServiceAssociatedPtr = mojo::AssociatedInterfacePtr<VRService>;
        using ThreadSafeVRServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<VRService>;
        using VRServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<VRService>;
        using VRServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<VRService>;

        class VRServiceClient;
        using VRServiceClientPtr = mojo::InterfacePtr<VRServiceClient>;
        using VRServiceClientPtrInfo = mojo::InterfacePtrInfo<VRServiceClient>;
        using ThreadSafeVRServiceClientPtr = mojo::ThreadSafeInterfacePtr<VRServiceClient>;
        using VRServiceClientRequest = mojo::InterfaceRequest<VRServiceClient>;
        using VRServiceClientAssociatedPtr = mojo::AssociatedInterfacePtr<VRServiceClient>;
        using ThreadSafeVRServiceClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<VRServiceClient>;
        using VRServiceClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<VRServiceClient>;
        using VRServiceClientAssociatedRequest = mojo::AssociatedInterfaceRequest<VRServiceClient>;

        class VRDisplay;
        using VRDisplayPtr = mojo::InterfacePtr<VRDisplay>;
        using VRDisplayPtrInfo = mojo::InterfacePtrInfo<VRDisplay>;
        using ThreadSafeVRDisplayPtr = mojo::ThreadSafeInterfacePtr<VRDisplay>;
        using VRDisplayRequest = mojo::InterfaceRequest<VRDisplay>;
        using VRDisplayAssociatedPtr = mojo::AssociatedInterfacePtr<VRDisplay>;
        using ThreadSafeVRDisplayAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<VRDisplay>;
        using VRDisplayAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<VRDisplay>;
        using VRDisplayAssociatedRequest = mojo::AssociatedInterfaceRequest<VRDisplay>;

        class VRDisplayClient;
        using VRDisplayClientPtr = mojo::InterfacePtr<VRDisplayClient>;
        using VRDisplayClientPtrInfo = mojo::InterfacePtrInfo<VRDisplayClient>;
        using ThreadSafeVRDisplayClientPtr = mojo::ThreadSafeInterfacePtr<VRDisplayClient>;
        using VRDisplayClientRequest = mojo::InterfaceRequest<VRDisplayClient>;
        using VRDisplayClientAssociatedPtr = mojo::AssociatedInterfacePtr<VRDisplayClient>;
        using ThreadSafeVRDisplayClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<VRDisplayClient>;
        using VRDisplayClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<VRDisplayClient>;
        using VRDisplayClientAssociatedRequest = mojo::AssociatedInterfaceRequest<VRDisplayClient>;

        class VRFieldOfView;
        using VRFieldOfViewPtr = mojo::InlinedStructPtr<VRFieldOfView>;

        class VRPose;
        using VRPosePtr = mojo::StructPtr<VRPose>;

        class VRDisplayCapabilities;
        using VRDisplayCapabilitiesPtr = mojo::InlinedStructPtr<VRDisplayCapabilities>;

        class VREyeParameters;
        using VREyeParametersPtr = mojo::StructPtr<VREyeParameters>;

        class VRStageParameters;
        using VRStageParametersPtr = mojo::StructPtr<VRStageParameters>;

        class VRDisplayInfo;
        using VRDisplayInfoPtr = mojo::StructPtr<VRDisplayInfo>;

        class VRLayerBounds;
        using VRLayerBoundsPtr = mojo::InlinedStructPtr<VRLayerBounds>;

        class VRServiceProxy;

        template <typename ImplRefTraits>
        class VRServiceStub;

        class VRServiceRequestValidator;
        class VRServiceResponseValidator;

        class VRService
            : public VRServiceInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = VRServiceProxy;

            template <typename ImplRefTraits>
            using Stub_ = VRServiceStub<ImplRefTraits>;

            using RequestValidator_ = VRServiceRequestValidator;
            using ResponseValidator_ = VRServiceResponseValidator;
            enum MethodMinVersions : uint32_t {
                kSetClientMinVersion = 0,
                kSetListeningForActivateMinVersion = 0,
            };
            virtual ~VRService() { }

            using SetClientCallback = base::Callback<void(uint32_t)>;
            virtual void SetClient(VRServiceClientPtr client, const SetClientCallback& callback) = 0;

            virtual void SetListeningForActivate(bool listening) = 0;
        };

        class VRServiceClientProxy;

        template <typename ImplRefTraits>
        class VRServiceClientStub;

        class VRServiceClientRequestValidator;

        class VRServiceClient
            : public VRServiceClientInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = VRServiceClientProxy;

            template <typename ImplRefTraits>
            using Stub_ = VRServiceClientStub<ImplRefTraits>;

            using RequestValidator_ = VRServiceClientRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kOnDisplayConnectedMinVersion = 0,
            };
            virtual ~VRServiceClient() { }

            virtual void OnDisplayConnected(VRDisplayPtr display, VRDisplayClientRequest request, VRDisplayInfoPtr displayInfo) = 0;
        };

        class VRDisplayProxy;

        template <typename ImplRefTraits>
        class VRDisplayStub;

        class VRDisplayRequestValidator;
        class VRDisplayResponseValidator;

        class VRDisplay
            : public VRDisplayInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = true;

            using Proxy_ = VRDisplayProxy;

            template <typename ImplRefTraits>
            using Stub_ = VRDisplayStub<ImplRefTraits>;

            using RequestValidator_ = VRDisplayRequestValidator;
            using ResponseValidator_ = VRDisplayResponseValidator;
            enum MethodMinVersions : uint32_t {
                kGetPoseMinVersion = 0,
                kResetPoseMinVersion = 0,
                kRequestPresentMinVersion = 0,
                kExitPresentMinVersion = 0,
                kSubmitFrameMinVersion = 0,
                kUpdateLayerBoundsMinVersion = 0,
            };
            virtual ~VRDisplay() { }

            // Sync method. This signature is used by the client side; the service side
            // should implement the signature with callback below.
            virtual bool GetPose(VRPosePtr* pose);

            using GetPoseCallback = base::Callback<void(VRPosePtr)>;
            virtual void GetPose(const GetPoseCallback& callback) = 0;

            virtual void ResetPose() = 0;

            using RequestPresentCallback = base::Callback<void(bool)>;
            virtual void RequestPresent(bool secureOrigin, const RequestPresentCallback& callback) = 0;

            virtual void ExitPresent() = 0;

            virtual void SubmitFrame(VRPosePtr pose) = 0;

            virtual void UpdateLayerBounds(VRLayerBoundsPtr leftBounds, VRLayerBoundsPtr rightBounds) = 0;
        };

        class VRDisplayClientProxy;

        template <typename ImplRefTraits>
        class VRDisplayClientStub;

        class VRDisplayClientRequestValidator;

        class VRDisplayClient
            : public VRDisplayClientInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = VRDisplayClientProxy;

            template <typename ImplRefTraits>
            using Stub_ = VRDisplayClientStub<ImplRefTraits>;

            using RequestValidator_ = VRDisplayClientRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kOnChangedMinVersion = 0,
                kOnExitPresentMinVersion = 0,
                kOnBlurMinVersion = 0,
                kOnFocusMinVersion = 0,
                kOnActivateMinVersion = 0,
                kOnDeactivateMinVersion = 0,
            };
            virtual ~VRDisplayClient() { }

            virtual void OnChanged(VRDisplayInfoPtr display) = 0;

            virtual void OnExitPresent() = 0;

            virtual void OnBlur() = 0;

            virtual void OnFocus() = 0;

            virtual void OnActivate(VRDisplayEventReason reason) = 0;

            virtual void OnDeactivate(VRDisplayEventReason reason) = 0;
        };

        class VRServiceProxy
            : public VRService {
        public:
            explicit VRServiceProxy(mojo::MessageReceiverWithResponder* receiver);
            void SetClient(VRServiceClientPtr client, const SetClientCallback& callback) override;
            void SetListeningForActivate(bool listening) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class VRServiceClientProxy
            : public VRServiceClient {
        public:
            explicit VRServiceClientProxy(mojo::MessageReceiverWithResponder* receiver);
            void OnDisplayConnected(VRDisplayPtr display, VRDisplayClientRequest request, VRDisplayInfoPtr displayInfo) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class VRDisplayProxy
            : public VRDisplay {
        public:
            explicit VRDisplayProxy(mojo::MessageReceiverWithResponder* receiver);
            bool GetPose(VRPosePtr* pose) override;
            void GetPose(const GetPoseCallback& callback) override;
            void ResetPose() override;
            void RequestPresent(bool secureOrigin, const RequestPresentCallback& callback) override;
            void ExitPresent() override;
            void SubmitFrame(VRPosePtr pose) override;
            void UpdateLayerBounds(VRLayerBoundsPtr leftBounds, VRLayerBoundsPtr rightBounds) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class VRDisplayClientProxy
            : public VRDisplayClient {
        public:
            explicit VRDisplayClientProxy(mojo::MessageReceiverWithResponder* receiver);
            void OnChanged(VRDisplayInfoPtr display) override;
            void OnExitPresent() override;
            void OnBlur() override;
            void OnFocus() override;
            void OnActivate(VRDisplayEventReason reason) override;
            void OnDeactivate(VRDisplayEventReason reason) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class VRServiceStubDispatch {
        public:
            static bool Accept(VRService* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(VRService* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<VRService>>
        class VRServiceStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            VRServiceStub() { }
            ~VRServiceStub() override { }

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
                return VRServiceStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return VRServiceStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class VRServiceClientStubDispatch {
        public:
            static bool Accept(VRServiceClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(VRServiceClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<VRServiceClient>>
        class VRServiceClientStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            VRServiceClientStub() { }
            ~VRServiceClientStub() override { }

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
                return VRServiceClientStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return VRServiceClientStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class VRDisplayStubDispatch {
        public:
            static bool Accept(VRDisplay* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(VRDisplay* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<VRDisplay>>
        class VRDisplayStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            VRDisplayStub() { }
            ~VRDisplayStub() override { }

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
                return VRDisplayStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return VRDisplayStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class VRDisplayClientStubDispatch {
        public:
            static bool Accept(VRDisplayClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(VRDisplayClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<VRDisplayClient>>
        class VRDisplayClientStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            VRDisplayClientStub() { }
            ~VRDisplayClientStub() override { }

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
                return VRDisplayClientStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return VRDisplayClientStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class VRServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class VRServiceClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class VRDisplayRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class VRDisplayClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class VRServiceResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class VRDisplayResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

        class VRFieldOfView {
        public:
            using DataView = VRFieldOfViewDataView;
            using Data_ = internal::VRFieldOfView_Data;

            static VRFieldOfViewPtr New();

            template <typename U>
            static VRFieldOfViewPtr From(const U& u)
            {
                return mojo::TypeConverter<VRFieldOfViewPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, VRFieldOfView>::Convert(*this);
            }

            VRFieldOfView();
            ~VRFieldOfView();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = VRFieldOfViewPtr>
            VRFieldOfViewPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, VRFieldOfView>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    VRFieldOfView::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    VRFieldOfView::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            float upDegrees;
            float downDegrees;
            float leftDegrees;
            float rightDegrees;
        };

        class VRDisplayCapabilities {
        public:
            using DataView = VRDisplayCapabilitiesDataView;
            using Data_ = internal::VRDisplayCapabilities_Data;

            static VRDisplayCapabilitiesPtr New();

            template <typename U>
            static VRDisplayCapabilitiesPtr From(const U& u)
            {
                return mojo::TypeConverter<VRDisplayCapabilitiesPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, VRDisplayCapabilities>::Convert(*this);
            }

            VRDisplayCapabilities();
            ~VRDisplayCapabilities();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = VRDisplayCapabilitiesPtr>
            VRDisplayCapabilitiesPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, VRDisplayCapabilities>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    VRDisplayCapabilities::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    VRDisplayCapabilities::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            bool hasOrientation;
            bool hasPosition;
            bool hasExternalDisplay;
            bool canPresent;
        };

        class VRLayerBounds {
        public:
            using DataView = VRLayerBoundsDataView;
            using Data_ = internal::VRLayerBounds_Data;

            static VRLayerBoundsPtr New();

            template <typename U>
            static VRLayerBoundsPtr From(const U& u)
            {
                return mojo::TypeConverter<VRLayerBoundsPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, VRLayerBounds>::Convert(*this);
            }

            VRLayerBounds();
            ~VRLayerBounds();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = VRLayerBoundsPtr>
            VRLayerBoundsPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, VRLayerBounds>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    VRLayerBounds::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    VRLayerBounds::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            float left;
            float top;
            float width;
            float height;
        };

        class VRPose {
        public:
            using DataView = VRPoseDataView;
            using Data_ = internal::VRPose_Data;

            static VRPosePtr New();

            template <typename U>
            static VRPosePtr From(const U& u)
            {
                return mojo::TypeConverter<VRPosePtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, VRPose>::Convert(*this);
            }

            VRPose();
            ~VRPose();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = VRPosePtr>
            VRPosePtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, VRPose>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    VRPose::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    VRPose::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            double timestamp;
            WTF::Optional<WTF::Vector<float>> orientation;
            WTF::Optional<WTF::Vector<float>> position;
            WTF::Optional<WTF::Vector<float>> angularVelocity;
            WTF::Optional<WTF::Vector<float>> linearVelocity;
            WTF::Optional<WTF::Vector<float>> angularAcceleration;
            WTF::Optional<WTF::Vector<float>> linearAcceleration;
            uint32_t poseIndex;
        };

        class VREyeParameters {
        public:
            using DataView = VREyeParametersDataView;
            using Data_ = internal::VREyeParameters_Data;

            static VREyeParametersPtr New();

            template <typename U>
            static VREyeParametersPtr From(const U& u)
            {
                return mojo::TypeConverter<VREyeParametersPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, VREyeParameters>::Convert(*this);
            }

            VREyeParameters();
            ~VREyeParameters();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = VREyeParametersPtr>
            VREyeParametersPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, VREyeParameters>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    VREyeParameters::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    VREyeParameters::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            VRFieldOfViewPtr fieldOfView;
            WTF::Vector<float> offset;
            uint32_t renderWidth;
            uint32_t renderHeight;

        private:
            DISALLOW_COPY_AND_ASSIGN(VREyeParameters);
        };

        class VRStageParameters {
        public:
            using DataView = VRStageParametersDataView;
            using Data_ = internal::VRStageParameters_Data;

            static VRStageParametersPtr New();

            template <typename U>
            static VRStageParametersPtr From(const U& u)
            {
                return mojo::TypeConverter<VRStageParametersPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, VRStageParameters>::Convert(*this);
            }

            VRStageParameters();
            ~VRStageParameters();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = VRStageParametersPtr>
            VRStageParametersPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, VRStageParameters>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    VRStageParameters::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    VRStageParameters::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::Vector<float> standingTransform;
            float sizeX;
            float sizeZ;
        };

        class VRDisplayInfo {
        public:
            using DataView = VRDisplayInfoDataView;
            using Data_ = internal::VRDisplayInfo_Data;

            static VRDisplayInfoPtr New();

            template <typename U>
            static VRDisplayInfoPtr From(const U& u)
            {
                return mojo::TypeConverter<VRDisplayInfoPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, VRDisplayInfo>::Convert(*this);
            }

            VRDisplayInfo();
            ~VRDisplayInfo();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = VRDisplayInfoPtr>
            VRDisplayInfoPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, VRDisplayInfo>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    VRDisplayInfo::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    VRDisplayInfo::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            uint32_t index;
            WTF::String displayName;
            VRDisplayCapabilitiesPtr capabilities;
            VRStageParametersPtr stageParameters;
            VREyeParametersPtr leftEye;
            VREyeParametersPtr rightEye;

        private:
            DISALLOW_COPY_AND_ASSIGN(VRDisplayInfo);
        };

        template <typename StructPtrType>
        VRFieldOfViewPtr VRFieldOfView::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->upDegrees = mojo::internal::Clone(upDegrees);
            rv->downDegrees = mojo::internal::Clone(downDegrees);
            rv->leftDegrees = mojo::internal::Clone(leftDegrees);
            rv->rightDegrees = mojo::internal::Clone(rightDegrees);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, VRFieldOfView>::value>::type*>
        bool VRFieldOfView::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->upDegrees, other.upDegrees))
                return false;
            if (!mojo::internal::Equals(this->downDegrees, other.downDegrees))
                return false;
            if (!mojo::internal::Equals(this->leftDegrees, other.leftDegrees))
                return false;
            if (!mojo::internal::Equals(this->rightDegrees, other.rightDegrees))
                return false;
            return true;
        }
        template <typename StructPtrType>
        VRPosePtr VRPose::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->timestamp = mojo::internal::Clone(timestamp);
            rv->orientation = mojo::internal::Clone(orientation);
            rv->position = mojo::internal::Clone(position);
            rv->angularVelocity = mojo::internal::Clone(angularVelocity);
            rv->linearVelocity = mojo::internal::Clone(linearVelocity);
            rv->angularAcceleration = mojo::internal::Clone(angularAcceleration);
            rv->linearAcceleration = mojo::internal::Clone(linearAcceleration);
            rv->poseIndex = mojo::internal::Clone(poseIndex);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, VRPose>::value>::type*>
        bool VRPose::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->timestamp, other.timestamp))
                return false;
            if (!mojo::internal::Equals(this->orientation, other.orientation))
                return false;
            if (!mojo::internal::Equals(this->position, other.position))
                return false;
            if (!mojo::internal::Equals(this->angularVelocity, other.angularVelocity))
                return false;
            if (!mojo::internal::Equals(this->linearVelocity, other.linearVelocity))
                return false;
            if (!mojo::internal::Equals(this->angularAcceleration, other.angularAcceleration))
                return false;
            if (!mojo::internal::Equals(this->linearAcceleration, other.linearAcceleration))
                return false;
            if (!mojo::internal::Equals(this->poseIndex, other.poseIndex))
                return false;
            return true;
        }
        template <typename StructPtrType>
        VRDisplayCapabilitiesPtr VRDisplayCapabilities::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->hasOrientation = mojo::internal::Clone(hasOrientation);
            rv->hasPosition = mojo::internal::Clone(hasPosition);
            rv->hasExternalDisplay = mojo::internal::Clone(hasExternalDisplay);
            rv->canPresent = mojo::internal::Clone(canPresent);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, VRDisplayCapabilities>::value>::type*>
        bool VRDisplayCapabilities::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->hasOrientation, other.hasOrientation))
                return false;
            if (!mojo::internal::Equals(this->hasPosition, other.hasPosition))
                return false;
            if (!mojo::internal::Equals(this->hasExternalDisplay, other.hasExternalDisplay))
                return false;
            if (!mojo::internal::Equals(this->canPresent, other.canPresent))
                return false;
            return true;
        }
        template <typename StructPtrType>
        VREyeParametersPtr VREyeParameters::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->fieldOfView = mojo::internal::Clone(fieldOfView);
            rv->offset = mojo::internal::Clone(offset);
            rv->renderWidth = mojo::internal::Clone(renderWidth);
            rv->renderHeight = mojo::internal::Clone(renderHeight);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, VREyeParameters>::value>::type*>
        bool VREyeParameters::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->fieldOfView, other.fieldOfView))
                return false;
            if (!mojo::internal::Equals(this->offset, other.offset))
                return false;
            if (!mojo::internal::Equals(this->renderWidth, other.renderWidth))
                return false;
            if (!mojo::internal::Equals(this->renderHeight, other.renderHeight))
                return false;
            return true;
        }
        template <typename StructPtrType>
        VRStageParametersPtr VRStageParameters::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->standingTransform = mojo::internal::Clone(standingTransform);
            rv->sizeX = mojo::internal::Clone(sizeX);
            rv->sizeZ = mojo::internal::Clone(sizeZ);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, VRStageParameters>::value>::type*>
        bool VRStageParameters::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->standingTransform, other.standingTransform))
                return false;
            if (!mojo::internal::Equals(this->sizeX, other.sizeX))
                return false;
            if (!mojo::internal::Equals(this->sizeZ, other.sizeZ))
                return false;
            return true;
        }
        template <typename StructPtrType>
        VRDisplayInfoPtr VRDisplayInfo::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->index = mojo::internal::Clone(index);
            rv->displayName = mojo::internal::Clone(displayName);
            rv->capabilities = mojo::internal::Clone(capabilities);
            rv->stageParameters = mojo::internal::Clone(stageParameters);
            rv->leftEye = mojo::internal::Clone(leftEye);
            rv->rightEye = mojo::internal::Clone(rightEye);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, VRDisplayInfo>::value>::type*>
        bool VRDisplayInfo::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->index, other.index))
                return false;
            if (!mojo::internal::Equals(this->displayName, other.displayName))
                return false;
            if (!mojo::internal::Equals(this->capabilities, other.capabilities))
                return false;
            if (!mojo::internal::Equals(this->stageParameters, other.stageParameters))
                return false;
            if (!mojo::internal::Equals(this->leftEye, other.leftEye))
                return false;
            if (!mojo::internal::Equals(this->rightEye, other.rightEye))
                return false;
            return true;
        }
        template <typename StructPtrType>
        VRLayerBoundsPtr VRLayerBounds::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->left = mojo::internal::Clone(left);
            rv->top = mojo::internal::Clone(top);
            rv->width = mojo::internal::Clone(width);
            rv->height = mojo::internal::Clone(height);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, VRLayerBounds>::value>::type*>
        bool VRLayerBounds::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->left, other.left))
                return false;
            if (!mojo::internal::Equals(this->top, other.top))
                return false;
            if (!mojo::internal::Equals(this->width, other.width))
                return false;
            if (!mojo::internal::Equals(this->height, other.height))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace device

namespace mojo {

template <>
struct StructTraits<::device::mojom::blink::VRFieldOfView::DataView,
    ::device::mojom::blink::VRFieldOfViewPtr> {
    static bool IsNull(const ::device::mojom::blink::VRFieldOfViewPtr& input) { return !input; }
    static void SetToNull(::device::mojom::blink::VRFieldOfViewPtr* output) { output->reset(); }

    static decltype(::device::mojom::blink::VRFieldOfView::upDegrees) upDegrees(
        const ::device::mojom::blink::VRFieldOfViewPtr& input)
    {
        return input->upDegrees;
    }

    static decltype(::device::mojom::blink::VRFieldOfView::downDegrees) downDegrees(
        const ::device::mojom::blink::VRFieldOfViewPtr& input)
    {
        return input->downDegrees;
    }

    static decltype(::device::mojom::blink::VRFieldOfView::leftDegrees) leftDegrees(
        const ::device::mojom::blink::VRFieldOfViewPtr& input)
    {
        return input->leftDegrees;
    }

    static decltype(::device::mojom::blink::VRFieldOfView::rightDegrees) rightDegrees(
        const ::device::mojom::blink::VRFieldOfViewPtr& input)
    {
        return input->rightDegrees;
    }

    static bool Read(::device::mojom::blink::VRFieldOfView::DataView input, ::device::mojom::blink::VRFieldOfViewPtr* output);
};

template <>
struct StructTraits<::device::mojom::blink::VRPose::DataView,
    ::device::mojom::blink::VRPosePtr> {
    static bool IsNull(const ::device::mojom::blink::VRPosePtr& input) { return !input; }
    static void SetToNull(::device::mojom::blink::VRPosePtr* output) { output->reset(); }

    static decltype(::device::mojom::blink::VRPose::timestamp) timestamp(
        const ::device::mojom::blink::VRPosePtr& input)
    {
        return input->timestamp;
    }

    static const decltype(::device::mojom::blink::VRPose::orientation)& orientation(
        const ::device::mojom::blink::VRPosePtr& input)
    {
        return input->orientation;
    }

    static const decltype(::device::mojom::blink::VRPose::position)& position(
        const ::device::mojom::blink::VRPosePtr& input)
    {
        return input->position;
    }

    static const decltype(::device::mojom::blink::VRPose::angularVelocity)& angularVelocity(
        const ::device::mojom::blink::VRPosePtr& input)
    {
        return input->angularVelocity;
    }

    static const decltype(::device::mojom::blink::VRPose::linearVelocity)& linearVelocity(
        const ::device::mojom::blink::VRPosePtr& input)
    {
        return input->linearVelocity;
    }

    static const decltype(::device::mojom::blink::VRPose::angularAcceleration)& angularAcceleration(
        const ::device::mojom::blink::VRPosePtr& input)
    {
        return input->angularAcceleration;
    }

    static const decltype(::device::mojom::blink::VRPose::linearAcceleration)& linearAcceleration(
        const ::device::mojom::blink::VRPosePtr& input)
    {
        return input->linearAcceleration;
    }

    static decltype(::device::mojom::blink::VRPose::poseIndex) poseIndex(
        const ::device::mojom::blink::VRPosePtr& input)
    {
        return input->poseIndex;
    }

    static bool Read(::device::mojom::blink::VRPose::DataView input, ::device::mojom::blink::VRPosePtr* output);
};

template <>
struct StructTraits<::device::mojom::blink::VRDisplayCapabilities::DataView,
    ::device::mojom::blink::VRDisplayCapabilitiesPtr> {
    static bool IsNull(const ::device::mojom::blink::VRDisplayCapabilitiesPtr& input) { return !input; }
    static void SetToNull(::device::mojom::blink::VRDisplayCapabilitiesPtr* output) { output->reset(); }

    static decltype(::device::mojom::blink::VRDisplayCapabilities::hasOrientation) hasOrientation(
        const ::device::mojom::blink::VRDisplayCapabilitiesPtr& input)
    {
        return input->hasOrientation;
    }

    static decltype(::device::mojom::blink::VRDisplayCapabilities::hasPosition) hasPosition(
        const ::device::mojom::blink::VRDisplayCapabilitiesPtr& input)
    {
        return input->hasPosition;
    }

    static decltype(::device::mojom::blink::VRDisplayCapabilities::hasExternalDisplay) hasExternalDisplay(
        const ::device::mojom::blink::VRDisplayCapabilitiesPtr& input)
    {
        return input->hasExternalDisplay;
    }

    static decltype(::device::mojom::blink::VRDisplayCapabilities::canPresent) canPresent(
        const ::device::mojom::blink::VRDisplayCapabilitiesPtr& input)
    {
        return input->canPresent;
    }

    static bool Read(::device::mojom::blink::VRDisplayCapabilities::DataView input, ::device::mojom::blink::VRDisplayCapabilitiesPtr* output);
};

template <>
struct StructTraits<::device::mojom::blink::VREyeParameters::DataView,
    ::device::mojom::blink::VREyeParametersPtr> {
    static bool IsNull(const ::device::mojom::blink::VREyeParametersPtr& input) { return !input; }
    static void SetToNull(::device::mojom::blink::VREyeParametersPtr* output) { output->reset(); }

    static const decltype(::device::mojom::blink::VREyeParameters::fieldOfView)& fieldOfView(
        const ::device::mojom::blink::VREyeParametersPtr& input)
    {
        return input->fieldOfView;
    }

    static const decltype(::device::mojom::blink::VREyeParameters::offset)& offset(
        const ::device::mojom::blink::VREyeParametersPtr& input)
    {
        return input->offset;
    }

    static decltype(::device::mojom::blink::VREyeParameters::renderWidth) renderWidth(
        const ::device::mojom::blink::VREyeParametersPtr& input)
    {
        return input->renderWidth;
    }

    static decltype(::device::mojom::blink::VREyeParameters::renderHeight) renderHeight(
        const ::device::mojom::blink::VREyeParametersPtr& input)
    {
        return input->renderHeight;
    }

    static bool Read(::device::mojom::blink::VREyeParameters::DataView input, ::device::mojom::blink::VREyeParametersPtr* output);
};

template <>
struct StructTraits<::device::mojom::blink::VRStageParameters::DataView,
    ::device::mojom::blink::VRStageParametersPtr> {
    static bool IsNull(const ::device::mojom::blink::VRStageParametersPtr& input) { return !input; }
    static void SetToNull(::device::mojom::blink::VRStageParametersPtr* output) { output->reset(); }

    static const decltype(::device::mojom::blink::VRStageParameters::standingTransform)& standingTransform(
        const ::device::mojom::blink::VRStageParametersPtr& input)
    {
        return input->standingTransform;
    }

    static decltype(::device::mojom::blink::VRStageParameters::sizeX) sizeX(
        const ::device::mojom::blink::VRStageParametersPtr& input)
    {
        return input->sizeX;
    }

    static decltype(::device::mojom::blink::VRStageParameters::sizeZ) sizeZ(
        const ::device::mojom::blink::VRStageParametersPtr& input)
    {
        return input->sizeZ;
    }

    static bool Read(::device::mojom::blink::VRStageParameters::DataView input, ::device::mojom::blink::VRStageParametersPtr* output);
};

template <>
struct StructTraits<::device::mojom::blink::VRDisplayInfo::DataView,
    ::device::mojom::blink::VRDisplayInfoPtr> {
    static bool IsNull(const ::device::mojom::blink::VRDisplayInfoPtr& input) { return !input; }
    static void SetToNull(::device::mojom::blink::VRDisplayInfoPtr* output) { output->reset(); }

    static decltype(::device::mojom::blink::VRDisplayInfo::index) index(
        const ::device::mojom::blink::VRDisplayInfoPtr& input)
    {
        return input->index;
    }

    static const decltype(::device::mojom::blink::VRDisplayInfo::displayName)& displayName(
        const ::device::mojom::blink::VRDisplayInfoPtr& input)
    {
        return input->displayName;
    }

    static const decltype(::device::mojom::blink::VRDisplayInfo::capabilities)& capabilities(
        const ::device::mojom::blink::VRDisplayInfoPtr& input)
    {
        return input->capabilities;
    }

    static const decltype(::device::mojom::blink::VRDisplayInfo::stageParameters)& stageParameters(
        const ::device::mojom::blink::VRDisplayInfoPtr& input)
    {
        return input->stageParameters;
    }

    static const decltype(::device::mojom::blink::VRDisplayInfo::leftEye)& leftEye(
        const ::device::mojom::blink::VRDisplayInfoPtr& input)
    {
        return input->leftEye;
    }

    static const decltype(::device::mojom::blink::VRDisplayInfo::rightEye)& rightEye(
        const ::device::mojom::blink::VRDisplayInfoPtr& input)
    {
        return input->rightEye;
    }

    static bool Read(::device::mojom::blink::VRDisplayInfo::DataView input, ::device::mojom::blink::VRDisplayInfoPtr* output);
};

template <>
struct StructTraits<::device::mojom::blink::VRLayerBounds::DataView,
    ::device::mojom::blink::VRLayerBoundsPtr> {
    static bool IsNull(const ::device::mojom::blink::VRLayerBoundsPtr& input) { return !input; }
    static void SetToNull(::device::mojom::blink::VRLayerBoundsPtr* output) { output->reset(); }

    static decltype(::device::mojom::blink::VRLayerBounds::left) left(
        const ::device::mojom::blink::VRLayerBoundsPtr& input)
    {
        return input->left;
    }

    static decltype(::device::mojom::blink::VRLayerBounds::top) top(
        const ::device::mojom::blink::VRLayerBoundsPtr& input)
    {
        return input->top;
    }

    static decltype(::device::mojom::blink::VRLayerBounds::width) width(
        const ::device::mojom::blink::VRLayerBoundsPtr& input)
    {
        return input->width;
    }

    static decltype(::device::mojom::blink::VRLayerBounds::height) height(
        const ::device::mojom::blink::VRLayerBoundsPtr& input)
    {
        return input->height;
    }

    static bool Read(::device::mojom::blink::VRLayerBounds::DataView input, ::device::mojom::blink::VRLayerBoundsPtr* output);
};

} // namespace mojo

#endif // DEVICE_VR_VR_SERVICE_MOJOM_BLINK_H_