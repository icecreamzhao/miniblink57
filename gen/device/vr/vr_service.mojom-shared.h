// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_VR_VR_SERVICE_MOJOM_SHARED_H_
#define DEVICE_VR_VR_SERVICE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/vr/vr_service.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace device {
namespace mojom {
    class VRFieldOfViewDataView;

    class VRPoseDataView;

    class VRDisplayCapabilitiesDataView;

    class VREyeParametersDataView;

    class VRStageParametersDataView;

    class VRDisplayInfoDataView;

    class VRLayerBoundsDataView;

} // namespace mojom
} // namespace device

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::device::mojom::VRFieldOfViewDataView> {
        using Data = ::device::mojom::internal::VRFieldOfView_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::mojom::VRPoseDataView> {
        using Data = ::device::mojom::internal::VRPose_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::mojom::VRDisplayCapabilitiesDataView> {
        using Data = ::device::mojom::internal::VRDisplayCapabilities_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::mojom::VREyeParametersDataView> {
        using Data = ::device::mojom::internal::VREyeParameters_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::mojom::VRStageParametersDataView> {
        using Data = ::device::mojom::internal::VRStageParameters_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::mojom::VRDisplayInfoDataView> {
        using Data = ::device::mojom::internal::VRDisplayInfo_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::mojom::VRLayerBoundsDataView> {
        using Data = ::device::mojom::internal::VRLayerBounds_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace device {
namespace mojom {

    enum class VRDisplayEventReason : int32_t {
        NONE = 0,
        NAVIGATION = 1,
        MOUNTED = 2,
        UNMOUNTED = 3,
    };

    inline std::ostream& operator<<(std::ostream& os, VRDisplayEventReason value)
    {
        switch (value) {
        case VRDisplayEventReason::NONE:
            return os << "VRDisplayEventReason::NONE";
        case VRDisplayEventReason::NAVIGATION:
            return os << "VRDisplayEventReason::NAVIGATION";
        case VRDisplayEventReason::MOUNTED:
            return os << "VRDisplayEventReason::MOUNTED";
        case VRDisplayEventReason::UNMOUNTED:
            return os << "VRDisplayEventReason::UNMOUNTED";
        default:
            return os << "Unknown VRDisplayEventReason value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(VRDisplayEventReason value)
    {
        return internal::VRDisplayEventReason_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class VRServiceInterfaceBase {
    };

    using VRServicePtrDataView = mojo::InterfacePtrDataView<VRServiceInterfaceBase>;
    using VRServiceRequestDataView = mojo::InterfaceRequestDataView<VRServiceInterfaceBase>;
    using VRServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<VRServiceInterfaceBase>;
    using VRServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<VRServiceInterfaceBase>;
    class VRServiceClientInterfaceBase {
    };

    using VRServiceClientPtrDataView = mojo::InterfacePtrDataView<VRServiceClientInterfaceBase>;
    using VRServiceClientRequestDataView = mojo::InterfaceRequestDataView<VRServiceClientInterfaceBase>;
    using VRServiceClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<VRServiceClientInterfaceBase>;
    using VRServiceClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<VRServiceClientInterfaceBase>;
    class VRDisplayInterfaceBase {
    };

    using VRDisplayPtrDataView = mojo::InterfacePtrDataView<VRDisplayInterfaceBase>;
    using VRDisplayRequestDataView = mojo::InterfaceRequestDataView<VRDisplayInterfaceBase>;
    using VRDisplayAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<VRDisplayInterfaceBase>;
    using VRDisplayAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<VRDisplayInterfaceBase>;
    class VRDisplayClientInterfaceBase {
    };

    using VRDisplayClientPtrDataView = mojo::InterfacePtrDataView<VRDisplayClientInterfaceBase>;
    using VRDisplayClientRequestDataView = mojo::InterfaceRequestDataView<VRDisplayClientInterfaceBase>;
    using VRDisplayClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<VRDisplayClientInterfaceBase>;
    using VRDisplayClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<VRDisplayClientInterfaceBase>;
    class VRFieldOfViewDataView {
    public:
        VRFieldOfViewDataView() { }

        VRFieldOfViewDataView(
            internal::VRFieldOfView_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        float upDegrees() const
        {
            return data_->upDegrees;
        }
        float downDegrees() const
        {
            return data_->downDegrees;
        }
        float leftDegrees() const
        {
            return data_->leftDegrees;
        }
        float rightDegrees() const
        {
            return data_->rightDegrees;
        }

    private:
        internal::VRFieldOfView_Data* data_ = nullptr;
    };

    class VRPoseDataView {
    public:
        VRPoseDataView() { }

        VRPoseDataView(
            internal::VRPose_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        double timestamp() const
        {
            return data_->timestamp;
        }
        inline void GetOrientationDataView(
            mojo::ArrayDataView<float>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrientation(UserType* output)
        {
            auto* pointer = data_->orientation.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<float>>(
                pointer, output, context_);
        }
        inline void GetPositionDataView(
            mojo::ArrayDataView<float>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPosition(UserType* output)
        {
            auto* pointer = data_->position.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<float>>(
                pointer, output, context_);
        }
        inline void GetAngularvelocityDataView(
            mojo::ArrayDataView<float>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAngularvelocity(UserType* output)
        {
            auto* pointer = data_->angularVelocity.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<float>>(
                pointer, output, context_);
        }
        inline void GetLinearvelocityDataView(
            mojo::ArrayDataView<float>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLinearvelocity(UserType* output)
        {
            auto* pointer = data_->linearVelocity.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<float>>(
                pointer, output, context_);
        }
        inline void GetAngularaccelerationDataView(
            mojo::ArrayDataView<float>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAngularacceleration(UserType* output)
        {
            auto* pointer = data_->angularAcceleration.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<float>>(
                pointer, output, context_);
        }
        inline void GetLinearaccelerationDataView(
            mojo::ArrayDataView<float>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLinearacceleration(UserType* output)
        {
            auto* pointer = data_->linearAcceleration.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<float>>(
                pointer, output, context_);
        }
        uint32_t poseIndex() const
        {
            return data_->poseIndex;
        }

    private:
        internal::VRPose_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VRDisplayCapabilitiesDataView {
    public:
        VRDisplayCapabilitiesDataView() { }

        VRDisplayCapabilitiesDataView(
            internal::VRDisplayCapabilities_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool hasOrientation() const
        {
            return data_->hasOrientation;
        }
        bool hasPosition() const
        {
            return data_->hasPosition;
        }
        bool hasExternalDisplay() const
        {
            return data_->hasExternalDisplay;
        }
        bool canPresent() const
        {
            return data_->canPresent;
        }

    private:
        internal::VRDisplayCapabilities_Data* data_ = nullptr;
    };

    class VREyeParametersDataView {
    public:
        VREyeParametersDataView() { }

        VREyeParametersDataView(
            internal::VREyeParameters_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFieldofviewDataView(
            VRFieldOfViewDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFieldofview(UserType* output)
        {
            auto* pointer = data_->fieldOfView.Get();
            return mojo::internal::Deserialize<::device::mojom::VRFieldOfViewDataView>(
                pointer, output, context_);
        }
        inline void GetOffsetDataView(
            mojo::ArrayDataView<float>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOffset(UserType* output)
        {
            auto* pointer = data_->offset.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<float>>(
                pointer, output, context_);
        }
        uint32_t renderWidth() const
        {
            return data_->renderWidth;
        }
        uint32_t renderHeight() const
        {
            return data_->renderHeight;
        }

    private:
        internal::VREyeParameters_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VRStageParametersDataView {
    public:
        VRStageParametersDataView() { }

        VRStageParametersDataView(
            internal::VRStageParameters_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetStandingtransformDataView(
            mojo::ArrayDataView<float>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStandingtransform(UserType* output)
        {
            auto* pointer = data_->standingTransform.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<float>>(
                pointer, output, context_);
        }
        float sizeX() const
        {
            return data_->sizeX;
        }
        float sizeZ() const
        {
            return data_->sizeZ;
        }

    private:
        internal::VRStageParameters_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VRDisplayInfoDataView {
    public:
        VRDisplayInfoDataView() { }

        VRDisplayInfoDataView(
            internal::VRDisplayInfo_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t index() const
        {
            return data_->index;
        }
        inline void GetDisplaynameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDisplayname(UserType* output)
        {
            auto* pointer = data_->displayName.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetCapabilitiesDataView(
            VRDisplayCapabilitiesDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCapabilities(UserType* output)
        {
            auto* pointer = data_->capabilities.Get();
            return mojo::internal::Deserialize<::device::mojom::VRDisplayCapabilitiesDataView>(
                pointer, output, context_);
        }
        inline void GetStageparametersDataView(
            VRStageParametersDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStageparameters(UserType* output)
        {
            auto* pointer = data_->stageParameters.Get();
            return mojo::internal::Deserialize<::device::mojom::VRStageParametersDataView>(
                pointer, output, context_);
        }
        inline void GetLefteyeDataView(
            VREyeParametersDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLefteye(UserType* output)
        {
            auto* pointer = data_->leftEye.Get();
            return mojo::internal::Deserialize<::device::mojom::VREyeParametersDataView>(
                pointer, output, context_);
        }
        inline void GetRighteyeDataView(
            VREyeParametersDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRighteye(UserType* output)
        {
            auto* pointer = data_->rightEye.Get();
            return mojo::internal::Deserialize<::device::mojom::VREyeParametersDataView>(
                pointer, output, context_);
        }

    private:
        internal::VRDisplayInfo_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VRLayerBoundsDataView {
    public:
        VRLayerBoundsDataView() { }

        VRLayerBoundsDataView(
            internal::VRLayerBounds_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        float left() const
        {
            return data_->left;
        }
        float top() const
        {
            return data_->top;
        }
        float width() const
        {
            return data_->width;
        }
        float height() const
        {
            return data_->height;
        }

    private:
        internal::VRLayerBounds_Data* data_ = nullptr;
    };

    class VRService_SetClient_ParamsDataView {
    public:
        VRService_SetClient_ParamsDataView() { }

        VRService_SetClient_ParamsDataView(
            internal::VRService_SetClient_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::device::mojom::VRServiceClientPtrDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::VRService_SetClient_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VRService_SetClient_ResponseParamsDataView {
    public:
        VRService_SetClient_ResponseParamsDataView() { }

        VRService_SetClient_ResponseParamsDataView(
            internal::VRService_SetClient_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t numberOfConnectedDevices() const
        {
            return data_->numberOfConnectedDevices;
        }

    private:
        internal::VRService_SetClient_ResponseParams_Data* data_ = nullptr;
    };

    class VRService_SetListeningForActivate_ParamsDataView {
    public:
        VRService_SetListeningForActivate_ParamsDataView() { }

        VRService_SetListeningForActivate_ParamsDataView(
            internal::VRService_SetListeningForActivate_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool listening() const
        {
            return data_->listening;
        }

    private:
        internal::VRService_SetListeningForActivate_Params_Data* data_ = nullptr;
    };

    class VRServiceClient_OnDisplayConnected_ParamsDataView {
    public:
        VRServiceClient_OnDisplayConnected_ParamsDataView() { }

        VRServiceClient_OnDisplayConnected_ParamsDataView(
            internal::VRServiceClient_OnDisplayConnected_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeDisplay()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::device::mojom::VRDisplayPtrDataView>(
                &data_->display, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::device::mojom::VRDisplayClientRequestDataView>(
                &data_->request, &result, context_);
            DCHECK(ret);
            return result;
        }
        inline void GetDisplayinfoDataView(
            VRDisplayInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDisplayinfo(UserType* output)
        {
            auto* pointer = data_->displayInfo.Get();
            return mojo::internal::Deserialize<::device::mojom::VRDisplayInfoDataView>(
                pointer, output, context_);
        }

    private:
        internal::VRServiceClient_OnDisplayConnected_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VRDisplay_GetPose_ParamsDataView {
    public:
        VRDisplay_GetPose_ParamsDataView() { }

        VRDisplay_GetPose_ParamsDataView(
            internal::VRDisplay_GetPose_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::VRDisplay_GetPose_Params_Data* data_ = nullptr;
    };

    class VRDisplay_GetPose_ResponseParamsDataView {
    public:
        VRDisplay_GetPose_ResponseParamsDataView() { }

        VRDisplay_GetPose_ResponseParamsDataView(
            internal::VRDisplay_GetPose_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPoseDataView(
            VRPoseDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPose(UserType* output)
        {
            auto* pointer = data_->pose.Get();
            return mojo::internal::Deserialize<::device::mojom::VRPoseDataView>(
                pointer, output, context_);
        }

    private:
        internal::VRDisplay_GetPose_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VRDisplay_ResetPose_ParamsDataView {
    public:
        VRDisplay_ResetPose_ParamsDataView() { }

        VRDisplay_ResetPose_ParamsDataView(
            internal::VRDisplay_ResetPose_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::VRDisplay_ResetPose_Params_Data* data_ = nullptr;
    };

    class VRDisplay_RequestPresent_ParamsDataView {
    public:
        VRDisplay_RequestPresent_ParamsDataView() { }

        VRDisplay_RequestPresent_ParamsDataView(
            internal::VRDisplay_RequestPresent_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool secureOrigin() const
        {
            return data_->secureOrigin;
        }

    private:
        internal::VRDisplay_RequestPresent_Params_Data* data_ = nullptr;
    };

    class VRDisplay_RequestPresent_ResponseParamsDataView {
    public:
        VRDisplay_RequestPresent_ResponseParamsDataView() { }

        VRDisplay_RequestPresent_ResponseParamsDataView(
            internal::VRDisplay_RequestPresent_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::VRDisplay_RequestPresent_ResponseParams_Data* data_ = nullptr;
    };

    class VRDisplay_ExitPresent_ParamsDataView {
    public:
        VRDisplay_ExitPresent_ParamsDataView() { }

        VRDisplay_ExitPresent_ParamsDataView(
            internal::VRDisplay_ExitPresent_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::VRDisplay_ExitPresent_Params_Data* data_ = nullptr;
    };

    class VRDisplay_SubmitFrame_ParamsDataView {
    public:
        VRDisplay_SubmitFrame_ParamsDataView() { }

        VRDisplay_SubmitFrame_ParamsDataView(
            internal::VRDisplay_SubmitFrame_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPoseDataView(
            VRPoseDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPose(UserType* output)
        {
            auto* pointer = data_->pose.Get();
            return mojo::internal::Deserialize<::device::mojom::VRPoseDataView>(
                pointer, output, context_);
        }

    private:
        internal::VRDisplay_SubmitFrame_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VRDisplay_UpdateLayerBounds_ParamsDataView {
    public:
        VRDisplay_UpdateLayerBounds_ParamsDataView() { }

        VRDisplay_UpdateLayerBounds_ParamsDataView(
            internal::VRDisplay_UpdateLayerBounds_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetLeftboundsDataView(
            VRLayerBoundsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLeftbounds(UserType* output)
        {
            auto* pointer = data_->leftBounds.Get();
            return mojo::internal::Deserialize<::device::mojom::VRLayerBoundsDataView>(
                pointer, output, context_);
        }
        inline void GetRightboundsDataView(
            VRLayerBoundsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRightbounds(UserType* output)
        {
            auto* pointer = data_->rightBounds.Get();
            return mojo::internal::Deserialize<::device::mojom::VRLayerBoundsDataView>(
                pointer, output, context_);
        }

    private:
        internal::VRDisplay_UpdateLayerBounds_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VRDisplayClient_OnChanged_ParamsDataView {
    public:
        VRDisplayClient_OnChanged_ParamsDataView() { }

        VRDisplayClient_OnChanged_ParamsDataView(
            internal::VRDisplayClient_OnChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDisplayDataView(
            VRDisplayInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDisplay(UserType* output)
        {
            auto* pointer = data_->display.Get();
            return mojo::internal::Deserialize<::device::mojom::VRDisplayInfoDataView>(
                pointer, output, context_);
        }

    private:
        internal::VRDisplayClient_OnChanged_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VRDisplayClient_OnExitPresent_ParamsDataView {
    public:
        VRDisplayClient_OnExitPresent_ParamsDataView() { }

        VRDisplayClient_OnExitPresent_ParamsDataView(
            internal::VRDisplayClient_OnExitPresent_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::VRDisplayClient_OnExitPresent_Params_Data* data_ = nullptr;
    };

    class VRDisplayClient_OnBlur_ParamsDataView {
    public:
        VRDisplayClient_OnBlur_ParamsDataView() { }

        VRDisplayClient_OnBlur_ParamsDataView(
            internal::VRDisplayClient_OnBlur_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::VRDisplayClient_OnBlur_Params_Data* data_ = nullptr;
    };

    class VRDisplayClient_OnFocus_ParamsDataView {
    public:
        VRDisplayClient_OnFocus_ParamsDataView() { }

        VRDisplayClient_OnFocus_ParamsDataView(
            internal::VRDisplayClient_OnFocus_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::VRDisplayClient_OnFocus_Params_Data* data_ = nullptr;
    };

    class VRDisplayClient_OnActivate_ParamsDataView {
    public:
        VRDisplayClient_OnActivate_ParamsDataView() { }

        VRDisplayClient_OnActivate_ParamsDataView(
            internal::VRDisplayClient_OnActivate_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReason(UserType* output) const
        {
            auto data_value = data_->reason;
            return mojo::internal::Deserialize<::device::mojom::VRDisplayEventReason>(
                data_value, output);
        }

        VRDisplayEventReason reason() const
        {
            return static_cast<VRDisplayEventReason>(data_->reason);
        }

    private:
        internal::VRDisplayClient_OnActivate_Params_Data* data_ = nullptr;
    };

    class VRDisplayClient_OnDeactivate_ParamsDataView {
    public:
        VRDisplayClient_OnDeactivate_ParamsDataView() { }

        VRDisplayClient_OnDeactivate_ParamsDataView(
            internal::VRDisplayClient_OnDeactivate_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReason(UserType* output) const
        {
            auto data_value = data_->reason;
            return mojo::internal::Deserialize<::device::mojom::VRDisplayEventReason>(
                data_value, output);
        }

        VRDisplayEventReason reason() const
        {
            return static_cast<VRDisplayEventReason>(data_->reason);
        }

    private:
        internal::VRDisplayClient_OnDeactivate_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace device

namespace std {

template <>
struct hash<::device::mojom::VRDisplayEventReason>
    : public mojo::internal::EnumHashImpl<::device::mojom::VRDisplayEventReason> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::device::mojom::VRDisplayEventReason, ::device::mojom::VRDisplayEventReason> {
    static ::device::mojom::VRDisplayEventReason ToMojom(::device::mojom::VRDisplayEventReason input) { return input; }
    static bool FromMojom(::device::mojom::VRDisplayEventReason input, ::device::mojom::VRDisplayEventReason* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::VRDisplayEventReason, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::mojom::VRDisplayEventReason, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::mojom::VRDisplayEventReason>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::VRFieldOfViewDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::mojom::VRFieldOfViewDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::mojom::internal::VRFieldOfView_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::mojom::internal::VRFieldOfView_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::mojom::internal::VRFieldOfView_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->upDegrees = CallWithContext(Traits::upDegrees, input, custom_context);
            result->downDegrees = CallWithContext(Traits::downDegrees, input, custom_context);
            result->leftDegrees = CallWithContext(Traits::leftDegrees, input, custom_context);
            result->rightDegrees = CallWithContext(Traits::rightDegrees, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::mojom::internal::VRFieldOfView_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::mojom::VRFieldOfViewDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::VRPoseDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::mojom::VRPoseDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::mojom::internal::VRPose_Data);
            decltype(CallWithContext(Traits::orientation, input, custom_context)) in_orientation = CallWithContext(Traits::orientation, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<float>>(
                in_orientation, context);
            decltype(CallWithContext(Traits::position, input, custom_context)) in_position = CallWithContext(Traits::position, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<float>>(
                in_position, context);
            decltype(CallWithContext(Traits::angularVelocity, input, custom_context)) in_angularVelocity = CallWithContext(Traits::angularVelocity, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<float>>(
                in_angularVelocity, context);
            decltype(CallWithContext(Traits::linearVelocity, input, custom_context)) in_linearVelocity = CallWithContext(Traits::linearVelocity, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<float>>(
                in_linearVelocity, context);
            decltype(CallWithContext(Traits::angularAcceleration, input, custom_context)) in_angularAcceleration = CallWithContext(Traits::angularAcceleration, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<float>>(
                in_angularAcceleration, context);
            decltype(CallWithContext(Traits::linearAcceleration, input, custom_context)) in_linearAcceleration = CallWithContext(Traits::linearAcceleration, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<float>>(
                in_linearAcceleration, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::mojom::internal::VRPose_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::mojom::internal::VRPose_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->timestamp = CallWithContext(Traits::timestamp, input, custom_context);
            decltype(CallWithContext(Traits::orientation, input, custom_context)) in_orientation = CallWithContext(Traits::orientation, input, custom_context);
            typename decltype(result->orientation)::BaseType* orientation_ptr;
            const mojo::internal::ContainerValidateParams orientation_validate_params(
                4, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<float>>(
                in_orientation, buffer, &orientation_ptr, &orientation_validate_params,
                context);
            result->orientation.Set(orientation_ptr);
            decltype(CallWithContext(Traits::position, input, custom_context)) in_position = CallWithContext(Traits::position, input, custom_context);
            typename decltype(result->position)::BaseType* position_ptr;
            const mojo::internal::ContainerValidateParams position_validate_params(
                3, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<float>>(
                in_position, buffer, &position_ptr, &position_validate_params,
                context);
            result->position.Set(position_ptr);
            decltype(CallWithContext(Traits::angularVelocity, input, custom_context)) in_angularVelocity = CallWithContext(Traits::angularVelocity, input, custom_context);
            typename decltype(result->angularVelocity)::BaseType* angularVelocity_ptr;
            const mojo::internal::ContainerValidateParams angularVelocity_validate_params(
                3, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<float>>(
                in_angularVelocity, buffer, &angularVelocity_ptr, &angularVelocity_validate_params,
                context);
            result->angularVelocity.Set(angularVelocity_ptr);
            decltype(CallWithContext(Traits::linearVelocity, input, custom_context)) in_linearVelocity = CallWithContext(Traits::linearVelocity, input, custom_context);
            typename decltype(result->linearVelocity)::BaseType* linearVelocity_ptr;
            const mojo::internal::ContainerValidateParams linearVelocity_validate_params(
                3, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<float>>(
                in_linearVelocity, buffer, &linearVelocity_ptr, &linearVelocity_validate_params,
                context);
            result->linearVelocity.Set(linearVelocity_ptr);
            decltype(CallWithContext(Traits::angularAcceleration, input, custom_context)) in_angularAcceleration = CallWithContext(Traits::angularAcceleration, input, custom_context);
            typename decltype(result->angularAcceleration)::BaseType* angularAcceleration_ptr;
            const mojo::internal::ContainerValidateParams angularAcceleration_validate_params(
                3, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<float>>(
                in_angularAcceleration, buffer, &angularAcceleration_ptr, &angularAcceleration_validate_params,
                context);
            result->angularAcceleration.Set(angularAcceleration_ptr);
            decltype(CallWithContext(Traits::linearAcceleration, input, custom_context)) in_linearAcceleration = CallWithContext(Traits::linearAcceleration, input, custom_context);
            typename decltype(result->linearAcceleration)::BaseType* linearAcceleration_ptr;
            const mojo::internal::ContainerValidateParams linearAcceleration_validate_params(
                3, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<float>>(
                in_linearAcceleration, buffer, &linearAcceleration_ptr, &linearAcceleration_validate_params,
                context);
            result->linearAcceleration.Set(linearAcceleration_ptr);
            result->poseIndex = CallWithContext(Traits::poseIndex, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::mojom::internal::VRPose_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::mojom::VRPoseDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::VRDisplayCapabilitiesDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::mojom::VRDisplayCapabilitiesDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::mojom::internal::VRDisplayCapabilities_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::mojom::internal::VRDisplayCapabilities_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::mojom::internal::VRDisplayCapabilities_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->hasOrientation = CallWithContext(Traits::hasOrientation, input, custom_context);
            result->hasPosition = CallWithContext(Traits::hasPosition, input, custom_context);
            result->hasExternalDisplay = CallWithContext(Traits::hasExternalDisplay, input, custom_context);
            result->canPresent = CallWithContext(Traits::canPresent, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::mojom::internal::VRDisplayCapabilities_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::mojom::VRDisplayCapabilitiesDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::VREyeParametersDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::mojom::VREyeParametersDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::mojom::internal::VREyeParameters_Data);
            decltype(CallWithContext(Traits::fieldOfView, input, custom_context)) in_fieldOfView = CallWithContext(Traits::fieldOfView, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::device::mojom::VRFieldOfViewDataView>(
                in_fieldOfView, context);
            decltype(CallWithContext(Traits::offset, input, custom_context)) in_offset = CallWithContext(Traits::offset, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<float>>(
                in_offset, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::mojom::internal::VREyeParameters_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::mojom::internal::VREyeParameters_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::fieldOfView, input, custom_context)) in_fieldOfView = CallWithContext(Traits::fieldOfView, input, custom_context);
            typename decltype(result->fieldOfView)::BaseType* fieldOfView_ptr;
            mojo::internal::Serialize<::device::mojom::VRFieldOfViewDataView>(
                in_fieldOfView, buffer, &fieldOfView_ptr, context);
            result->fieldOfView.Set(fieldOfView_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->fieldOfView.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null fieldOfView in VREyeParameters struct");
            decltype(CallWithContext(Traits::offset, input, custom_context)) in_offset = CallWithContext(Traits::offset, input, custom_context);
            typename decltype(result->offset)::BaseType* offset_ptr;
            const mojo::internal::ContainerValidateParams offset_validate_params(
                3, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<float>>(
                in_offset, buffer, &offset_ptr, &offset_validate_params,
                context);
            result->offset.Set(offset_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->offset.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null offset in VREyeParameters struct");
            result->renderWidth = CallWithContext(Traits::renderWidth, input, custom_context);
            result->renderHeight = CallWithContext(Traits::renderHeight, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::mojom::internal::VREyeParameters_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::mojom::VREyeParametersDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::VRStageParametersDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::mojom::VRStageParametersDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::mojom::internal::VRStageParameters_Data);
            decltype(CallWithContext(Traits::standingTransform, input, custom_context)) in_standingTransform = CallWithContext(Traits::standingTransform, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<float>>(
                in_standingTransform, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::mojom::internal::VRStageParameters_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::mojom::internal::VRStageParameters_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::standingTransform, input, custom_context)) in_standingTransform = CallWithContext(Traits::standingTransform, input, custom_context);
            typename decltype(result->standingTransform)::BaseType* standingTransform_ptr;
            const mojo::internal::ContainerValidateParams standingTransform_validate_params(
                16, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<float>>(
                in_standingTransform, buffer, &standingTransform_ptr, &standingTransform_validate_params,
                context);
            result->standingTransform.Set(standingTransform_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->standingTransform.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null standingTransform in VRStageParameters struct");
            result->sizeX = CallWithContext(Traits::sizeX, input, custom_context);
            result->sizeZ = CallWithContext(Traits::sizeZ, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::mojom::internal::VRStageParameters_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::mojom::VRStageParametersDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::VRDisplayInfoDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::mojom::VRDisplayInfoDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::mojom::internal::VRDisplayInfo_Data);
            decltype(CallWithContext(Traits::displayName, input, custom_context)) in_displayName = CallWithContext(Traits::displayName, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_displayName, context);
            decltype(CallWithContext(Traits::capabilities, input, custom_context)) in_capabilities = CallWithContext(Traits::capabilities, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::device::mojom::VRDisplayCapabilitiesDataView>(
                in_capabilities, context);
            decltype(CallWithContext(Traits::stageParameters, input, custom_context)) in_stageParameters = CallWithContext(Traits::stageParameters, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::device::mojom::VRStageParametersDataView>(
                in_stageParameters, context);
            decltype(CallWithContext(Traits::leftEye, input, custom_context)) in_leftEye = CallWithContext(Traits::leftEye, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::device::mojom::VREyeParametersDataView>(
                in_leftEye, context);
            decltype(CallWithContext(Traits::rightEye, input, custom_context)) in_rightEye = CallWithContext(Traits::rightEye, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::device::mojom::VREyeParametersDataView>(
                in_rightEye, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::mojom::internal::VRDisplayInfo_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::mojom::internal::VRDisplayInfo_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->index = CallWithContext(Traits::index, input, custom_context);
            decltype(CallWithContext(Traits::displayName, input, custom_context)) in_displayName = CallWithContext(Traits::displayName, input, custom_context);
            typename decltype(result->displayName)::BaseType* displayName_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_displayName, buffer, &displayName_ptr, context);
            result->displayName.Set(displayName_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->displayName.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null displayName in VRDisplayInfo struct");
            decltype(CallWithContext(Traits::capabilities, input, custom_context)) in_capabilities = CallWithContext(Traits::capabilities, input, custom_context);
            typename decltype(result->capabilities)::BaseType* capabilities_ptr;
            mojo::internal::Serialize<::device::mojom::VRDisplayCapabilitiesDataView>(
                in_capabilities, buffer, &capabilities_ptr, context);
            result->capabilities.Set(capabilities_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->capabilities.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null capabilities in VRDisplayInfo struct");
            decltype(CallWithContext(Traits::stageParameters, input, custom_context)) in_stageParameters = CallWithContext(Traits::stageParameters, input, custom_context);
            typename decltype(result->stageParameters)::BaseType* stageParameters_ptr;
            mojo::internal::Serialize<::device::mojom::VRStageParametersDataView>(
                in_stageParameters, buffer, &stageParameters_ptr, context);
            result->stageParameters.Set(stageParameters_ptr);
            decltype(CallWithContext(Traits::leftEye, input, custom_context)) in_leftEye = CallWithContext(Traits::leftEye, input, custom_context);
            typename decltype(result->leftEye)::BaseType* leftEye_ptr;
            mojo::internal::Serialize<::device::mojom::VREyeParametersDataView>(
                in_leftEye, buffer, &leftEye_ptr, context);
            result->leftEye.Set(leftEye_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->leftEye.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null leftEye in VRDisplayInfo struct");
            decltype(CallWithContext(Traits::rightEye, input, custom_context)) in_rightEye = CallWithContext(Traits::rightEye, input, custom_context);
            typename decltype(result->rightEye)::BaseType* rightEye_ptr;
            mojo::internal::Serialize<::device::mojom::VREyeParametersDataView>(
                in_rightEye, buffer, &rightEye_ptr, context);
            result->rightEye.Set(rightEye_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->rightEye.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null rightEye in VRDisplayInfo struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::mojom::internal::VRDisplayInfo_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::mojom::VRDisplayInfoDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::VRLayerBoundsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::mojom::VRLayerBoundsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::mojom::internal::VRLayerBounds_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::mojom::internal::VRLayerBounds_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::mojom::internal::VRLayerBounds_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->left = CallWithContext(Traits::left, input, custom_context);
            result->top = CallWithContext(Traits::top, input, custom_context);
            result->width = CallWithContext(Traits::width, input, custom_context);
            result->height = CallWithContext(Traits::height, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::mojom::internal::VRLayerBounds_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::mojom::VRLayerBoundsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace device {
namespace mojom {

    inline void VRPoseDataView::GetOrientationDataView(
        mojo::ArrayDataView<float>* output)
    {
        auto pointer = data_->orientation.Get();
        *output = mojo::ArrayDataView<float>(pointer, context_);
    }
    inline void VRPoseDataView::GetPositionDataView(
        mojo::ArrayDataView<float>* output)
    {
        auto pointer = data_->position.Get();
        *output = mojo::ArrayDataView<float>(pointer, context_);
    }
    inline void VRPoseDataView::GetAngularvelocityDataView(
        mojo::ArrayDataView<float>* output)
    {
        auto pointer = data_->angularVelocity.Get();
        *output = mojo::ArrayDataView<float>(pointer, context_);
    }
    inline void VRPoseDataView::GetLinearvelocityDataView(
        mojo::ArrayDataView<float>* output)
    {
        auto pointer = data_->linearVelocity.Get();
        *output = mojo::ArrayDataView<float>(pointer, context_);
    }
    inline void VRPoseDataView::GetAngularaccelerationDataView(
        mojo::ArrayDataView<float>* output)
    {
        auto pointer = data_->angularAcceleration.Get();
        *output = mojo::ArrayDataView<float>(pointer, context_);
    }
    inline void VRPoseDataView::GetLinearaccelerationDataView(
        mojo::ArrayDataView<float>* output)
    {
        auto pointer = data_->linearAcceleration.Get();
        *output = mojo::ArrayDataView<float>(pointer, context_);
    }

    inline void VREyeParametersDataView::GetFieldofviewDataView(
        VRFieldOfViewDataView* output)
    {
        auto pointer = data_->fieldOfView.Get();
        *output = VRFieldOfViewDataView(pointer, context_);
    }
    inline void VREyeParametersDataView::GetOffsetDataView(
        mojo::ArrayDataView<float>* output)
    {
        auto pointer = data_->offset.Get();
        *output = mojo::ArrayDataView<float>(pointer, context_);
    }

    inline void VRStageParametersDataView::GetStandingtransformDataView(
        mojo::ArrayDataView<float>* output)
    {
        auto pointer = data_->standingTransform.Get();
        *output = mojo::ArrayDataView<float>(pointer, context_);
    }

    inline void VRDisplayInfoDataView::GetDisplaynameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->displayName.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void VRDisplayInfoDataView::GetCapabilitiesDataView(
        VRDisplayCapabilitiesDataView* output)
    {
        auto pointer = data_->capabilities.Get();
        *output = VRDisplayCapabilitiesDataView(pointer, context_);
    }
    inline void VRDisplayInfoDataView::GetStageparametersDataView(
        VRStageParametersDataView* output)
    {
        auto pointer = data_->stageParameters.Get();
        *output = VRStageParametersDataView(pointer, context_);
    }
    inline void VRDisplayInfoDataView::GetLefteyeDataView(
        VREyeParametersDataView* output)
    {
        auto pointer = data_->leftEye.Get();
        *output = VREyeParametersDataView(pointer, context_);
    }
    inline void VRDisplayInfoDataView::GetRighteyeDataView(
        VREyeParametersDataView* output)
    {
        auto pointer = data_->rightEye.Get();
        *output = VREyeParametersDataView(pointer, context_);
    }

    inline void VRServiceClient_OnDisplayConnected_ParamsDataView::GetDisplayinfoDataView(
        VRDisplayInfoDataView* output)
    {
        auto pointer = data_->displayInfo.Get();
        *output = VRDisplayInfoDataView(pointer, context_);
    }

    inline void VRDisplay_GetPose_ResponseParamsDataView::GetPoseDataView(
        VRPoseDataView* output)
    {
        auto pointer = data_->pose.Get();
        *output = VRPoseDataView(pointer, context_);
    }

    inline void VRDisplay_SubmitFrame_ParamsDataView::GetPoseDataView(
        VRPoseDataView* output)
    {
        auto pointer = data_->pose.Get();
        *output = VRPoseDataView(pointer, context_);
    }

    inline void VRDisplay_UpdateLayerBounds_ParamsDataView::GetLeftboundsDataView(
        VRLayerBoundsDataView* output)
    {
        auto pointer = data_->leftBounds.Get();
        *output = VRLayerBoundsDataView(pointer, context_);
    }
    inline void VRDisplay_UpdateLayerBounds_ParamsDataView::GetRightboundsDataView(
        VRLayerBoundsDataView* output)
    {
        auto pointer = data_->rightBounds.Get();
        *output = VRLayerBoundsDataView(pointer, context_);
    }

    inline void VRDisplayClient_OnChanged_ParamsDataView::GetDisplayDataView(
        VRDisplayInfoDataView* output)
    {
        auto pointer = data_->display.Get();
        *output = VRDisplayInfoDataView(pointer, context_);
    }

} // namespace mojom
} // namespace device

#endif // DEVICE_VR_VR_SERVICE_MOJOM_SHARED_H_
