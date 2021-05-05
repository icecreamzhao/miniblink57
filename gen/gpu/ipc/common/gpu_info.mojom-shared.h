// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_GPU_INFO_MOJOM_SHARED_H_
#define GPU_IPC_COMMON_GPU_INFO_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "gpu/ipc/common/dx_diag_node.mojom-shared.h"
#include "gpu/ipc/common/gpu_info.mojom-shared-internal.h"
#include "mojo/common/time.mojom-shared.h"
#include "mojo/common/version.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace gpu {
namespace mojom {
    class GpuDeviceDataView;

    class VideoDecodeAcceleratorSupportedProfileDataView;

    class VideoDecodeAcceleratorCapabilitiesDataView;

    class VideoEncodeAcceleratorSupportedProfileDataView;

    class GpuInfoDataView;

} // namespace mojom
} // namespace gpu

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::gpu::mojom::GpuDeviceDataView> {
        using Data = ::gpu::mojom::internal::GpuDevice_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::gpu::mojom::VideoDecodeAcceleratorSupportedProfileDataView> {
        using Data = ::gpu::mojom::internal::VideoDecodeAcceleratorSupportedProfile_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::gpu::mojom::VideoDecodeAcceleratorCapabilitiesDataView> {
        using Data = ::gpu::mojom::internal::VideoDecodeAcceleratorCapabilities_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::gpu::mojom::VideoEncodeAcceleratorSupportedProfileDataView> {
        using Data = ::gpu::mojom::internal::VideoEncodeAcceleratorSupportedProfile_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::gpu::mojom::GpuInfoDataView> {
        using Data = ::gpu::mojom::internal::GpuInfo_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace gpu {
namespace mojom {

    enum class CollectInfoResult : int32_t {
        kCollectInfoNone = 0,
        kCollectInfoSuccess = 1,
        kCollectInfoNonFatalFailure = 2,
        kCollectInfoFatalFailure = 3,
    };

    inline std::ostream& operator<<(std::ostream& os, CollectInfoResult value)
    {
        switch (value) {
        case CollectInfoResult::kCollectInfoNone:
            return os << "CollectInfoResult::kCollectInfoNone";
        case CollectInfoResult::kCollectInfoSuccess:
            return os << "CollectInfoResult::kCollectInfoSuccess";
        case CollectInfoResult::kCollectInfoNonFatalFailure:
            return os << "CollectInfoResult::kCollectInfoNonFatalFailure";
        case CollectInfoResult::kCollectInfoFatalFailure:
            return os << "CollectInfoResult::kCollectInfoFatalFailure";
        default:
            return os << "Unknown CollectInfoResult value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(CollectInfoResult value)
    {
        return internal::CollectInfoResult_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class VideoCodecProfile : int32_t {
        VIDEO_CODEC_PROFILE_UNKNOWN = -1,
        H264PROFILE_BASELINE = 0,
        H264PROFILE_MAIN,
        H264PROFILE_EXTENDED,
        H264PROFILE_HIGH,
        H264PROFILE_HIGH10PROFILE,
        H264PROFILE_HIGH422PROFILE,
        H264PROFILE_HIGH444PREDICTIVEPROFILE,
        H264PROFILE_SCALABLEBASELINE,
        H264PROFILE_SCALABLEHIGH,
        H264PROFILE_STEREOHIGH,
        H264PROFILE_MULTIVIEWHIGH,
        VP8PROFILE_ANY,
        VP9PROFILE_PROFILE0,
        VP9PROFILE_PROFILE1,
        VP9PROFILE_PROFILE2,
        VP9PROFILE_PROFILE3,
        HEVCPROFILE_MAIN,
        HEVCPROFILE_MAIN10,
        HEVCPROFILE_MAIN_STILL_PICTURE,
    };

    inline std::ostream& operator<<(std::ostream& os, VideoCodecProfile value)
    {
        switch (value) {
        case VideoCodecProfile::VIDEO_CODEC_PROFILE_UNKNOWN:
            return os << "VideoCodecProfile::VIDEO_CODEC_PROFILE_UNKNOWN";
        case VideoCodecProfile::H264PROFILE_BASELINE:
            return os << "VideoCodecProfile::H264PROFILE_BASELINE";
        case VideoCodecProfile::H264PROFILE_MAIN:
            return os << "VideoCodecProfile::H264PROFILE_MAIN";
        case VideoCodecProfile::H264PROFILE_EXTENDED:
            return os << "VideoCodecProfile::H264PROFILE_EXTENDED";
        case VideoCodecProfile::H264PROFILE_HIGH:
            return os << "VideoCodecProfile::H264PROFILE_HIGH";
        case VideoCodecProfile::H264PROFILE_HIGH10PROFILE:
            return os << "VideoCodecProfile::H264PROFILE_HIGH10PROFILE";
        case VideoCodecProfile::H264PROFILE_HIGH422PROFILE:
            return os << "VideoCodecProfile::H264PROFILE_HIGH422PROFILE";
        case VideoCodecProfile::H264PROFILE_HIGH444PREDICTIVEPROFILE:
            return os << "VideoCodecProfile::H264PROFILE_HIGH444PREDICTIVEPROFILE";
        case VideoCodecProfile::H264PROFILE_SCALABLEBASELINE:
            return os << "VideoCodecProfile::H264PROFILE_SCALABLEBASELINE";
        case VideoCodecProfile::H264PROFILE_SCALABLEHIGH:
            return os << "VideoCodecProfile::H264PROFILE_SCALABLEHIGH";
        case VideoCodecProfile::H264PROFILE_STEREOHIGH:
            return os << "VideoCodecProfile::H264PROFILE_STEREOHIGH";
        case VideoCodecProfile::H264PROFILE_MULTIVIEWHIGH:
            return os << "VideoCodecProfile::H264PROFILE_MULTIVIEWHIGH";
        case VideoCodecProfile::VP8PROFILE_ANY:
            return os << "VideoCodecProfile::VP8PROFILE_ANY";
        case VideoCodecProfile::VP9PROFILE_PROFILE0:
            return os << "VideoCodecProfile::VP9PROFILE_PROFILE0";
        case VideoCodecProfile::VP9PROFILE_PROFILE1:
            return os << "VideoCodecProfile::VP9PROFILE_PROFILE1";
        case VideoCodecProfile::VP9PROFILE_PROFILE2:
            return os << "VideoCodecProfile::VP9PROFILE_PROFILE2";
        case VideoCodecProfile::VP9PROFILE_PROFILE3:
            return os << "VideoCodecProfile::VP9PROFILE_PROFILE3";
        case VideoCodecProfile::HEVCPROFILE_MAIN:
            return os << "VideoCodecProfile::HEVCPROFILE_MAIN";
        case VideoCodecProfile::HEVCPROFILE_MAIN10:
            return os << "VideoCodecProfile::HEVCPROFILE_MAIN10";
        case VideoCodecProfile::HEVCPROFILE_MAIN_STILL_PICTURE:
            return os << "VideoCodecProfile::HEVCPROFILE_MAIN_STILL_PICTURE";
        default:
            return os << "Unknown VideoCodecProfile value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(VideoCodecProfile value)
    {
        return internal::VideoCodecProfile_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class GpuDeviceDataView {
    public:
        GpuDeviceDataView() { }

        GpuDeviceDataView(
            internal::GpuDevice_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t vendor_id() const
        {
            return data_->vendor_id;
        }
        uint32_t device_id() const
        {
            return data_->device_id;
        }
        bool active() const
        {
            return data_->active;
        }
        inline void GetVendorStringDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadVendorString(UserType* output)
        {
            auto* pointer = data_->vendor_string.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetDeviceStringDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDeviceString(UserType* output)
        {
            auto* pointer = data_->device_string.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::GpuDevice_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VideoDecodeAcceleratorSupportedProfileDataView {
    public:
        VideoDecodeAcceleratorSupportedProfileDataView() { }

        VideoDecodeAcceleratorSupportedProfileDataView(
            internal::VideoDecodeAcceleratorSupportedProfile_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadProfile(UserType* output) const
        {
            auto data_value = data_->profile;
            return mojo::internal::Deserialize<::gpu::mojom::VideoCodecProfile>(
                data_value, output);
        }

        VideoCodecProfile profile() const
        {
            return static_cast<VideoCodecProfile>(data_->profile);
        }
        inline void GetMaxResolutionDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMaxResolution(UserType* output)
        {
            auto* pointer = data_->max_resolution.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        inline void GetMinResolutionDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMinResolution(UserType* output)
        {
            auto* pointer = data_->min_resolution.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        bool encrypted_only() const
        {
            return data_->encrypted_only;
        }

    private:
        internal::VideoDecodeAcceleratorSupportedProfile_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VideoDecodeAcceleratorCapabilitiesDataView {
    public:
        VideoDecodeAcceleratorCapabilitiesDataView() { }

        VideoDecodeAcceleratorCapabilitiesDataView(
            internal::VideoDecodeAcceleratorCapabilities_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSupportedProfilesDataView(
            mojo::ArrayDataView<VideoDecodeAcceleratorSupportedProfileDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSupportedProfiles(UserType* output)
        {
            auto* pointer = data_->supported_profiles.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::gpu::mojom::VideoDecodeAcceleratorSupportedProfileDataView>>(
                pointer, output, context_);
        }
        uint32_t flags() const
        {
            return data_->flags;
        }

    private:
        internal::VideoDecodeAcceleratorCapabilities_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VideoEncodeAcceleratorSupportedProfileDataView {
    public:
        VideoEncodeAcceleratorSupportedProfileDataView() { }

        VideoEncodeAcceleratorSupportedProfileDataView(
            internal::VideoEncodeAcceleratorSupportedProfile_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadProfile(UserType* output) const
        {
            auto data_value = data_->profile;
            return mojo::internal::Deserialize<::gpu::mojom::VideoCodecProfile>(
                data_value, output);
        }

        VideoCodecProfile profile() const
        {
            return static_cast<VideoCodecProfile>(data_->profile);
        }
        inline void GetMaxResolutionDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMaxResolution(UserType* output)
        {
            auto* pointer = data_->max_resolution.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        uint32_t max_framerate_numerator() const
        {
            return data_->max_framerate_numerator;
        }
        uint32_t max_framerate_denominator() const
        {
            return data_->max_framerate_denominator;
        }

    private:
        internal::VideoEncodeAcceleratorSupportedProfile_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class GpuInfoDataView {
    public:
        GpuInfoDataView() { }

        GpuInfoDataView(
            internal::GpuInfo_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetInitializationTimeDataView(
            ::mojo::common::mojom::TimeDeltaDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInitializationTime(UserType* output)
        {
            auto* pointer = data_->initialization_time.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDeltaDataView>(
                pointer, output, context_);
        }
        bool optimus() const
        {
            return data_->optimus;
        }
        bool amd_switchable() const
        {
            return data_->amd_switchable;
        }
        bool lenovo_dcute() const
        {
            return data_->lenovo_dcute;
        }
        inline void GetDisplayLinkVersionDataView(
            ::mojo::common::mojom::VersionDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDisplayLinkVersion(UserType* output)
        {
            auto* pointer = data_->display_link_version.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::VersionDataView>(
                pointer, output, context_);
        }
        inline void GetGpuDataView(
            GpuDeviceDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGpu(UserType* output)
        {
            auto* pointer = data_->gpu.Get();
            return mojo::internal::Deserialize<::gpu::mojom::GpuDeviceDataView>(
                pointer, output, context_);
        }
        inline void GetSecondaryGpusDataView(
            mojo::ArrayDataView<GpuDeviceDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSecondaryGpus(UserType* output)
        {
            auto* pointer = data_->secondary_gpus.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::gpu::mojom::GpuDeviceDataView>>(
                pointer, output, context_);
        }
        uint64_t adapter_luid() const
        {
            return data_->adapter_luid;
        }
        inline void GetDriverVendorDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDriverVendor(UserType* output)
        {
            auto* pointer = data_->driver_vendor.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetDriverVersionDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDriverVersion(UserType* output)
        {
            auto* pointer = data_->driver_version.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetDriverDateDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDriverDate(UserType* output)
        {
            auto* pointer = data_->driver_date.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetPixelShaderVersionDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPixelShaderVersion(UserType* output)
        {
            auto* pointer = data_->pixel_shader_version.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetVertexShaderVersionDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadVertexShaderVersion(UserType* output)
        {
            auto* pointer = data_->vertex_shader_version.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetMaxMsaaSamplesDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMaxMsaaSamples(UserType* output)
        {
            auto* pointer = data_->max_msaa_samples.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetMachineModelNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMachineModelName(UserType* output)
        {
            auto* pointer = data_->machine_model_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetMachineModelVersionDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMachineModelVersion(UserType* output)
        {
            auto* pointer = data_->machine_model_version.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetGlVersionDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGlVersion(UserType* output)
        {
            auto* pointer = data_->gl_version.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetGlVendorDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGlVendor(UserType* output)
        {
            auto* pointer = data_->gl_vendor.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetGlRendererDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGlRenderer(UserType* output)
        {
            auto* pointer = data_->gl_renderer.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetGlExtensionsDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGlExtensions(UserType* output)
        {
            auto* pointer = data_->gl_extensions.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetGlWsVendorDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGlWsVendor(UserType* output)
        {
            auto* pointer = data_->gl_ws_vendor.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetGlWsVersionDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGlWsVersion(UserType* output)
        {
            auto* pointer = data_->gl_ws_version.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetGlWsExtensionsDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGlWsExtensions(UserType* output)
        {
            auto* pointer = data_->gl_ws_extensions.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        uint32_t gl_reset_notification_strategy() const
        {
            return data_->gl_reset_notification_strategy;
        }
        bool software_rendering() const
        {
            return data_->software_rendering;
        }
        bool direct_rendering() const
        {
            return data_->direct_rendering;
        }
        bool sandboxed() const
        {
            return data_->sandboxed;
        }
        int32_t process_crash_count() const
        {
            return data_->process_crash_count;
        }
        bool in_process_gpu() const
        {
            return data_->in_process_gpu;
        }
        bool passthrough_cmd_decoder() const
        {
            return data_->passthrough_cmd_decoder;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBasicInfoState(UserType* output) const
        {
            auto data_value = data_->basic_info_state;
            return mojo::internal::Deserialize<::gpu::mojom::CollectInfoResult>(
                data_value, output);
        }

        CollectInfoResult basic_info_state() const
        {
            return static_cast<CollectInfoResult>(data_->basic_info_state);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadContextInfoState(UserType* output) const
        {
            auto data_value = data_->context_info_state;
            return mojo::internal::Deserialize<::gpu::mojom::CollectInfoResult>(
                data_value, output);
        }

        CollectInfoResult context_info_state() const
        {
            return static_cast<CollectInfoResult>(data_->context_info_state);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDxDiagnosticsInfoState(UserType* output) const
        {
            auto data_value = data_->dx_diagnostics_info_state;
            return mojo::internal::Deserialize<::gpu::mojom::CollectInfoResult>(
                data_value, output);
        }

        CollectInfoResult dx_diagnostics_info_state() const
        {
            return static_cast<CollectInfoResult>(data_->dx_diagnostics_info_state);
        }
        inline void GetDxDiagnosticsDataView(
            ::gpu::mojom::DxDiagNodeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDxDiagnostics(UserType* output)
        {
            auto* pointer = data_->dx_diagnostics.Get();
            return mojo::internal::Deserialize<::gpu::mojom::DxDiagNodeDataView>(
                pointer, output, context_);
        }
        inline void GetVideoDecodeAcceleratorCapabilitiesDataView(
            VideoDecodeAcceleratorCapabilitiesDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadVideoDecodeAcceleratorCapabilities(UserType* output)
        {
            auto* pointer = data_->video_decode_accelerator_capabilities.Get();
            return mojo::internal::Deserialize<::gpu::mojom::VideoDecodeAcceleratorCapabilitiesDataView>(
                pointer, output, context_);
        }
        inline void GetVideoEncodeAcceleratorSupportedProfilesDataView(
            mojo::ArrayDataView<VideoEncodeAcceleratorSupportedProfileDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadVideoEncodeAcceleratorSupportedProfiles(UserType* output)
        {
            auto* pointer = data_->video_encode_accelerator_supported_profiles.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::gpu::mojom::VideoEncodeAcceleratorSupportedProfileDataView>>(
                pointer, output, context_);
        }
        bool jpeg_decode_accelerator_supported() const
        {
            return data_->jpeg_decode_accelerator_supported;
        }
        uint64_t system_visual() const
        {
            return data_->system_visual;
        }
        uint64_t rgba_visual() const
        {
            return data_->rgba_visual;
        }

    private:
        internal::GpuInfo_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace gpu

namespace std {

template <>
struct hash<::gpu::mojom::CollectInfoResult>
    : public mojo::internal::EnumHashImpl<::gpu::mojom::CollectInfoResult> {
};

template <>
struct hash<::gpu::mojom::VideoCodecProfile>
    : public mojo::internal::EnumHashImpl<::gpu::mojom::VideoCodecProfile> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::gpu::mojom::CollectInfoResult, ::gpu::mojom::CollectInfoResult> {
    static ::gpu::mojom::CollectInfoResult ToMojom(::gpu::mojom::CollectInfoResult input) { return input; }
    static bool FromMojom(::gpu::mojom::CollectInfoResult input, ::gpu::mojom::CollectInfoResult* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gpu::mojom::CollectInfoResult, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::gpu::mojom::CollectInfoResult, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::gpu::mojom::CollectInfoResult>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::gpu::mojom::VideoCodecProfile, ::gpu::mojom::VideoCodecProfile> {
    static ::gpu::mojom::VideoCodecProfile ToMojom(::gpu::mojom::VideoCodecProfile input) { return input; }
    static bool FromMojom(::gpu::mojom::VideoCodecProfile input, ::gpu::mojom::VideoCodecProfile* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gpu::mojom::VideoCodecProfile, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::gpu::mojom::VideoCodecProfile, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::gpu::mojom::VideoCodecProfile>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gpu::mojom::GpuDeviceDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gpu::mojom::GpuDeviceDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gpu::mojom::internal::GpuDevice_Data);
            decltype(CallWithContext(Traits::vendor_string, input, custom_context)) in_vendor_string = CallWithContext(Traits::vendor_string, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_vendor_string, context);
            decltype(CallWithContext(Traits::device_string, input, custom_context)) in_device_string = CallWithContext(Traits::device_string, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_device_string, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gpu::mojom::internal::GpuDevice_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gpu::mojom::internal::GpuDevice_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->vendor_id = CallWithContext(Traits::vendor_id, input, custom_context);
            result->device_id = CallWithContext(Traits::device_id, input, custom_context);
            result->active = CallWithContext(Traits::active, input, custom_context);
            decltype(CallWithContext(Traits::vendor_string, input, custom_context)) in_vendor_string = CallWithContext(Traits::vendor_string, input, custom_context);
            typename decltype(result->vendor_string)::BaseType* vendor_string_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_vendor_string, buffer, &vendor_string_ptr, context);
            result->vendor_string.Set(vendor_string_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->vendor_string.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null vendor_string in GpuDevice struct");
            decltype(CallWithContext(Traits::device_string, input, custom_context)) in_device_string = CallWithContext(Traits::device_string, input, custom_context);
            typename decltype(result->device_string)::BaseType* device_string_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_device_string, buffer, &device_string_ptr, context);
            result->device_string.Set(device_string_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->device_string.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null device_string in GpuDevice struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gpu::mojom::internal::GpuDevice_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gpu::mojom::GpuDeviceDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gpu::mojom::VideoDecodeAcceleratorSupportedProfileDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gpu::mojom::VideoDecodeAcceleratorSupportedProfileDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gpu::mojom::internal::VideoDecodeAcceleratorSupportedProfile_Data);
            decltype(CallWithContext(Traits::max_resolution, input, custom_context)) in_max_resolution = CallWithContext(Traits::max_resolution, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_max_resolution, context);
            decltype(CallWithContext(Traits::min_resolution, input, custom_context)) in_min_resolution = CallWithContext(Traits::min_resolution, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_min_resolution, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gpu::mojom::internal::VideoDecodeAcceleratorSupportedProfile_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gpu::mojom::internal::VideoDecodeAcceleratorSupportedProfile_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::gpu::mojom::VideoCodecProfile>(
                CallWithContext(Traits::profile, input, custom_context), &result->profile);
            decltype(CallWithContext(Traits::max_resolution, input, custom_context)) in_max_resolution = CallWithContext(Traits::max_resolution, input, custom_context);
            typename decltype(result->max_resolution)::BaseType* max_resolution_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_max_resolution, buffer, &max_resolution_ptr, context);
            result->max_resolution.Set(max_resolution_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->max_resolution.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null max_resolution in VideoDecodeAcceleratorSupportedProfile struct");
            decltype(CallWithContext(Traits::min_resolution, input, custom_context)) in_min_resolution = CallWithContext(Traits::min_resolution, input, custom_context);
            typename decltype(result->min_resolution)::BaseType* min_resolution_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_min_resolution, buffer, &min_resolution_ptr, context);
            result->min_resolution.Set(min_resolution_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->min_resolution.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null min_resolution in VideoDecodeAcceleratorSupportedProfile struct");
            result->encrypted_only = CallWithContext(Traits::encrypted_only, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gpu::mojom::internal::VideoDecodeAcceleratorSupportedProfile_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gpu::mojom::VideoDecodeAcceleratorSupportedProfileDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gpu::mojom::VideoDecodeAcceleratorCapabilitiesDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gpu::mojom::VideoDecodeAcceleratorCapabilitiesDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gpu::mojom::internal::VideoDecodeAcceleratorCapabilities_Data);
            decltype(CallWithContext(Traits::supported_profiles, input, custom_context)) in_supported_profiles = CallWithContext(Traits::supported_profiles, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::gpu::mojom::VideoDecodeAcceleratorSupportedProfileDataView>>(
                in_supported_profiles, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gpu::mojom::internal::VideoDecodeAcceleratorCapabilities_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gpu::mojom::internal::VideoDecodeAcceleratorCapabilities_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::supported_profiles, input, custom_context)) in_supported_profiles = CallWithContext(Traits::supported_profiles, input, custom_context);
            typename decltype(result->supported_profiles)::BaseType* supported_profiles_ptr;
            const mojo::internal::ContainerValidateParams supported_profiles_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::gpu::mojom::VideoDecodeAcceleratorSupportedProfileDataView>>(
                in_supported_profiles, buffer, &supported_profiles_ptr, &supported_profiles_validate_params,
                context);
            result->supported_profiles.Set(supported_profiles_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->supported_profiles.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null supported_profiles in VideoDecodeAcceleratorCapabilities struct");
            result->flags = CallWithContext(Traits::flags, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gpu::mojom::internal::VideoDecodeAcceleratorCapabilities_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gpu::mojom::VideoDecodeAcceleratorCapabilitiesDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gpu::mojom::VideoEncodeAcceleratorSupportedProfileDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gpu::mojom::VideoEncodeAcceleratorSupportedProfileDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gpu::mojom::internal::VideoEncodeAcceleratorSupportedProfile_Data);
            decltype(CallWithContext(Traits::max_resolution, input, custom_context)) in_max_resolution = CallWithContext(Traits::max_resolution, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_max_resolution, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gpu::mojom::internal::VideoEncodeAcceleratorSupportedProfile_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gpu::mojom::internal::VideoEncodeAcceleratorSupportedProfile_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::gpu::mojom::VideoCodecProfile>(
                CallWithContext(Traits::profile, input, custom_context), &result->profile);
            decltype(CallWithContext(Traits::max_resolution, input, custom_context)) in_max_resolution = CallWithContext(Traits::max_resolution, input, custom_context);
            typename decltype(result->max_resolution)::BaseType* max_resolution_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_max_resolution, buffer, &max_resolution_ptr, context);
            result->max_resolution.Set(max_resolution_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->max_resolution.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null max_resolution in VideoEncodeAcceleratorSupportedProfile struct");
            result->max_framerate_numerator = CallWithContext(Traits::max_framerate_numerator, input, custom_context);
            result->max_framerate_denominator = CallWithContext(Traits::max_framerate_denominator, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gpu::mojom::internal::VideoEncodeAcceleratorSupportedProfile_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gpu::mojom::VideoEncodeAcceleratorSupportedProfileDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gpu::mojom::GpuInfoDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gpu::mojom::GpuInfoDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gpu::mojom::internal::GpuInfo_Data);
            decltype(CallWithContext(Traits::initialization_time, input, custom_context)) in_initialization_time = CallWithContext(Traits::initialization_time, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_initialization_time, context);
            decltype(CallWithContext(Traits::display_link_version, input, custom_context)) in_display_link_version = CallWithContext(Traits::display_link_version, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::VersionDataView>(
                in_display_link_version, context);
            decltype(CallWithContext(Traits::gpu, input, custom_context)) in_gpu = CallWithContext(Traits::gpu, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gpu::mojom::GpuDeviceDataView>(
                in_gpu, context);
            decltype(CallWithContext(Traits::secondary_gpus, input, custom_context)) in_secondary_gpus = CallWithContext(Traits::secondary_gpus, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::gpu::mojom::GpuDeviceDataView>>(
                in_secondary_gpus, context);
            decltype(CallWithContext(Traits::driver_vendor, input, custom_context)) in_driver_vendor = CallWithContext(Traits::driver_vendor, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_driver_vendor, context);
            decltype(CallWithContext(Traits::driver_version, input, custom_context)) in_driver_version = CallWithContext(Traits::driver_version, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_driver_version, context);
            decltype(CallWithContext(Traits::driver_date, input, custom_context)) in_driver_date = CallWithContext(Traits::driver_date, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_driver_date, context);
            decltype(CallWithContext(Traits::pixel_shader_version, input, custom_context)) in_pixel_shader_version = CallWithContext(Traits::pixel_shader_version, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_pixel_shader_version, context);
            decltype(CallWithContext(Traits::vertex_shader_version, input, custom_context)) in_vertex_shader_version = CallWithContext(Traits::vertex_shader_version, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_vertex_shader_version, context);
            decltype(CallWithContext(Traits::max_msaa_samples, input, custom_context)) in_max_msaa_samples = CallWithContext(Traits::max_msaa_samples, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_max_msaa_samples, context);
            decltype(CallWithContext(Traits::machine_model_name, input, custom_context)) in_machine_model_name = CallWithContext(Traits::machine_model_name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_machine_model_name, context);
            decltype(CallWithContext(Traits::machine_model_version, input, custom_context)) in_machine_model_version = CallWithContext(Traits::machine_model_version, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_machine_model_version, context);
            decltype(CallWithContext(Traits::gl_version, input, custom_context)) in_gl_version = CallWithContext(Traits::gl_version, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_gl_version, context);
            decltype(CallWithContext(Traits::gl_vendor, input, custom_context)) in_gl_vendor = CallWithContext(Traits::gl_vendor, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_gl_vendor, context);
            decltype(CallWithContext(Traits::gl_renderer, input, custom_context)) in_gl_renderer = CallWithContext(Traits::gl_renderer, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_gl_renderer, context);
            decltype(CallWithContext(Traits::gl_extensions, input, custom_context)) in_gl_extensions = CallWithContext(Traits::gl_extensions, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_gl_extensions, context);
            decltype(CallWithContext(Traits::gl_ws_vendor, input, custom_context)) in_gl_ws_vendor = CallWithContext(Traits::gl_ws_vendor, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_gl_ws_vendor, context);
            decltype(CallWithContext(Traits::gl_ws_version, input, custom_context)) in_gl_ws_version = CallWithContext(Traits::gl_ws_version, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_gl_ws_version, context);
            decltype(CallWithContext(Traits::gl_ws_extensions, input, custom_context)) in_gl_ws_extensions = CallWithContext(Traits::gl_ws_extensions, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_gl_ws_extensions, context);
            decltype(CallWithContext(Traits::dx_diagnostics, input, custom_context)) in_dx_diagnostics = CallWithContext(Traits::dx_diagnostics, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gpu::mojom::DxDiagNodeDataView>(
                in_dx_diagnostics, context);
            decltype(CallWithContext(Traits::video_decode_accelerator_capabilities, input, custom_context)) in_video_decode_accelerator_capabilities = CallWithContext(Traits::video_decode_accelerator_capabilities, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gpu::mojom::VideoDecodeAcceleratorCapabilitiesDataView>(
                in_video_decode_accelerator_capabilities, context);
            decltype(CallWithContext(Traits::video_encode_accelerator_supported_profiles, input, custom_context)) in_video_encode_accelerator_supported_profiles = CallWithContext(Traits::video_encode_accelerator_supported_profiles, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::gpu::mojom::VideoEncodeAcceleratorSupportedProfileDataView>>(
                in_video_encode_accelerator_supported_profiles, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gpu::mojom::internal::GpuInfo_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gpu::mojom::internal::GpuInfo_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::initialization_time, input, custom_context)) in_initialization_time = CallWithContext(Traits::initialization_time, input, custom_context);
            typename decltype(result->initialization_time)::BaseType* initialization_time_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_initialization_time, buffer, &initialization_time_ptr, context);
            result->initialization_time.Set(initialization_time_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->initialization_time.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null initialization_time in GpuInfo struct");
            result->optimus = CallWithContext(Traits::optimus, input, custom_context);
            result->amd_switchable = CallWithContext(Traits::amd_switchable, input, custom_context);
            result->lenovo_dcute = CallWithContext(Traits::lenovo_dcute, input, custom_context);
            decltype(CallWithContext(Traits::display_link_version, input, custom_context)) in_display_link_version = CallWithContext(Traits::display_link_version, input, custom_context);
            typename decltype(result->display_link_version)::BaseType* display_link_version_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::VersionDataView>(
                in_display_link_version, buffer, &display_link_version_ptr, context);
            result->display_link_version.Set(display_link_version_ptr);
            decltype(CallWithContext(Traits::gpu, input, custom_context)) in_gpu = CallWithContext(Traits::gpu, input, custom_context);
            typename decltype(result->gpu)::BaseType* gpu_ptr;
            mojo::internal::Serialize<::gpu::mojom::GpuDeviceDataView>(
                in_gpu, buffer, &gpu_ptr, context);
            result->gpu.Set(gpu_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->gpu.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null gpu in GpuInfo struct");
            decltype(CallWithContext(Traits::secondary_gpus, input, custom_context)) in_secondary_gpus = CallWithContext(Traits::secondary_gpus, input, custom_context);
            typename decltype(result->secondary_gpus)::BaseType* secondary_gpus_ptr;
            const mojo::internal::ContainerValidateParams secondary_gpus_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::gpu::mojom::GpuDeviceDataView>>(
                in_secondary_gpus, buffer, &secondary_gpus_ptr, &secondary_gpus_validate_params,
                context);
            result->secondary_gpus.Set(secondary_gpus_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->secondary_gpus.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null secondary_gpus in GpuInfo struct");
            result->adapter_luid = CallWithContext(Traits::adapter_luid, input, custom_context);
            decltype(CallWithContext(Traits::driver_vendor, input, custom_context)) in_driver_vendor = CallWithContext(Traits::driver_vendor, input, custom_context);
            typename decltype(result->driver_vendor)::BaseType* driver_vendor_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_driver_vendor, buffer, &driver_vendor_ptr, context);
            result->driver_vendor.Set(driver_vendor_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->driver_vendor.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null driver_vendor in GpuInfo struct");
            decltype(CallWithContext(Traits::driver_version, input, custom_context)) in_driver_version = CallWithContext(Traits::driver_version, input, custom_context);
            typename decltype(result->driver_version)::BaseType* driver_version_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_driver_version, buffer, &driver_version_ptr, context);
            result->driver_version.Set(driver_version_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->driver_version.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null driver_version in GpuInfo struct");
            decltype(CallWithContext(Traits::driver_date, input, custom_context)) in_driver_date = CallWithContext(Traits::driver_date, input, custom_context);
            typename decltype(result->driver_date)::BaseType* driver_date_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_driver_date, buffer, &driver_date_ptr, context);
            result->driver_date.Set(driver_date_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->driver_date.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null driver_date in GpuInfo struct");
            decltype(CallWithContext(Traits::pixel_shader_version, input, custom_context)) in_pixel_shader_version = CallWithContext(Traits::pixel_shader_version, input, custom_context);
            typename decltype(result->pixel_shader_version)::BaseType* pixel_shader_version_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_pixel_shader_version, buffer, &pixel_shader_version_ptr, context);
            result->pixel_shader_version.Set(pixel_shader_version_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->pixel_shader_version.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null pixel_shader_version in GpuInfo struct");
            decltype(CallWithContext(Traits::vertex_shader_version, input, custom_context)) in_vertex_shader_version = CallWithContext(Traits::vertex_shader_version, input, custom_context);
            typename decltype(result->vertex_shader_version)::BaseType* vertex_shader_version_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_vertex_shader_version, buffer, &vertex_shader_version_ptr, context);
            result->vertex_shader_version.Set(vertex_shader_version_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->vertex_shader_version.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null vertex_shader_version in GpuInfo struct");
            decltype(CallWithContext(Traits::max_msaa_samples, input, custom_context)) in_max_msaa_samples = CallWithContext(Traits::max_msaa_samples, input, custom_context);
            typename decltype(result->max_msaa_samples)::BaseType* max_msaa_samples_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_max_msaa_samples, buffer, &max_msaa_samples_ptr, context);
            result->max_msaa_samples.Set(max_msaa_samples_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->max_msaa_samples.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null max_msaa_samples in GpuInfo struct");
            decltype(CallWithContext(Traits::machine_model_name, input, custom_context)) in_machine_model_name = CallWithContext(Traits::machine_model_name, input, custom_context);
            typename decltype(result->machine_model_name)::BaseType* machine_model_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_machine_model_name, buffer, &machine_model_name_ptr, context);
            result->machine_model_name.Set(machine_model_name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->machine_model_name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null machine_model_name in GpuInfo struct");
            decltype(CallWithContext(Traits::machine_model_version, input, custom_context)) in_machine_model_version = CallWithContext(Traits::machine_model_version, input, custom_context);
            typename decltype(result->machine_model_version)::BaseType* machine_model_version_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_machine_model_version, buffer, &machine_model_version_ptr, context);
            result->machine_model_version.Set(machine_model_version_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->machine_model_version.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null machine_model_version in GpuInfo struct");
            decltype(CallWithContext(Traits::gl_version, input, custom_context)) in_gl_version = CallWithContext(Traits::gl_version, input, custom_context);
            typename decltype(result->gl_version)::BaseType* gl_version_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_gl_version, buffer, &gl_version_ptr, context);
            result->gl_version.Set(gl_version_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->gl_version.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null gl_version in GpuInfo struct");
            decltype(CallWithContext(Traits::gl_vendor, input, custom_context)) in_gl_vendor = CallWithContext(Traits::gl_vendor, input, custom_context);
            typename decltype(result->gl_vendor)::BaseType* gl_vendor_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_gl_vendor, buffer, &gl_vendor_ptr, context);
            result->gl_vendor.Set(gl_vendor_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->gl_vendor.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null gl_vendor in GpuInfo struct");
            decltype(CallWithContext(Traits::gl_renderer, input, custom_context)) in_gl_renderer = CallWithContext(Traits::gl_renderer, input, custom_context);
            typename decltype(result->gl_renderer)::BaseType* gl_renderer_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_gl_renderer, buffer, &gl_renderer_ptr, context);
            result->gl_renderer.Set(gl_renderer_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->gl_renderer.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null gl_renderer in GpuInfo struct");
            decltype(CallWithContext(Traits::gl_extensions, input, custom_context)) in_gl_extensions = CallWithContext(Traits::gl_extensions, input, custom_context);
            typename decltype(result->gl_extensions)::BaseType* gl_extensions_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_gl_extensions, buffer, &gl_extensions_ptr, context);
            result->gl_extensions.Set(gl_extensions_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->gl_extensions.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null gl_extensions in GpuInfo struct");
            decltype(CallWithContext(Traits::gl_ws_vendor, input, custom_context)) in_gl_ws_vendor = CallWithContext(Traits::gl_ws_vendor, input, custom_context);
            typename decltype(result->gl_ws_vendor)::BaseType* gl_ws_vendor_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_gl_ws_vendor, buffer, &gl_ws_vendor_ptr, context);
            result->gl_ws_vendor.Set(gl_ws_vendor_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->gl_ws_vendor.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null gl_ws_vendor in GpuInfo struct");
            decltype(CallWithContext(Traits::gl_ws_version, input, custom_context)) in_gl_ws_version = CallWithContext(Traits::gl_ws_version, input, custom_context);
            typename decltype(result->gl_ws_version)::BaseType* gl_ws_version_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_gl_ws_version, buffer, &gl_ws_version_ptr, context);
            result->gl_ws_version.Set(gl_ws_version_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->gl_ws_version.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null gl_ws_version in GpuInfo struct");
            decltype(CallWithContext(Traits::gl_ws_extensions, input, custom_context)) in_gl_ws_extensions = CallWithContext(Traits::gl_ws_extensions, input, custom_context);
            typename decltype(result->gl_ws_extensions)::BaseType* gl_ws_extensions_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_gl_ws_extensions, buffer, &gl_ws_extensions_ptr, context);
            result->gl_ws_extensions.Set(gl_ws_extensions_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->gl_ws_extensions.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null gl_ws_extensions in GpuInfo struct");
            result->gl_reset_notification_strategy = CallWithContext(Traits::gl_reset_notification_strategy, input, custom_context);
            result->software_rendering = CallWithContext(Traits::software_rendering, input, custom_context);
            result->direct_rendering = CallWithContext(Traits::direct_rendering, input, custom_context);
            result->sandboxed = CallWithContext(Traits::sandboxed, input, custom_context);
            result->process_crash_count = CallWithContext(Traits::process_crash_count, input, custom_context);
            result->in_process_gpu = CallWithContext(Traits::in_process_gpu, input, custom_context);
            result->passthrough_cmd_decoder = CallWithContext(Traits::passthrough_cmd_decoder, input, custom_context);
            mojo::internal::Serialize<::gpu::mojom::CollectInfoResult>(
                CallWithContext(Traits::basic_info_state, input, custom_context), &result->basic_info_state);
            mojo::internal::Serialize<::gpu::mojom::CollectInfoResult>(
                CallWithContext(Traits::context_info_state, input, custom_context), &result->context_info_state);
            mojo::internal::Serialize<::gpu::mojom::CollectInfoResult>(
                CallWithContext(Traits::dx_diagnostics_info_state, input, custom_context), &result->dx_diagnostics_info_state);
            decltype(CallWithContext(Traits::dx_diagnostics, input, custom_context)) in_dx_diagnostics = CallWithContext(Traits::dx_diagnostics, input, custom_context);
            typename decltype(result->dx_diagnostics)::BaseType* dx_diagnostics_ptr;
            mojo::internal::Serialize<::gpu::mojom::DxDiagNodeDataView>(
                in_dx_diagnostics, buffer, &dx_diagnostics_ptr, context);
            result->dx_diagnostics.Set(dx_diagnostics_ptr);
            decltype(CallWithContext(Traits::video_decode_accelerator_capabilities, input, custom_context)) in_video_decode_accelerator_capabilities = CallWithContext(Traits::video_decode_accelerator_capabilities, input, custom_context);
            typename decltype(result->video_decode_accelerator_capabilities)::BaseType* video_decode_accelerator_capabilities_ptr;
            mojo::internal::Serialize<::gpu::mojom::VideoDecodeAcceleratorCapabilitiesDataView>(
                in_video_decode_accelerator_capabilities, buffer, &video_decode_accelerator_capabilities_ptr, context);
            result->video_decode_accelerator_capabilities.Set(video_decode_accelerator_capabilities_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->video_decode_accelerator_capabilities.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null video_decode_accelerator_capabilities in GpuInfo struct");
            decltype(CallWithContext(Traits::video_encode_accelerator_supported_profiles, input, custom_context)) in_video_encode_accelerator_supported_profiles = CallWithContext(Traits::video_encode_accelerator_supported_profiles, input, custom_context);
            typename decltype(result->video_encode_accelerator_supported_profiles)::BaseType* video_encode_accelerator_supported_profiles_ptr;
            const mojo::internal::ContainerValidateParams video_encode_accelerator_supported_profiles_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::gpu::mojom::VideoEncodeAcceleratorSupportedProfileDataView>>(
                in_video_encode_accelerator_supported_profiles, buffer, &video_encode_accelerator_supported_profiles_ptr, &video_encode_accelerator_supported_profiles_validate_params,
                context);
            result->video_encode_accelerator_supported_profiles.Set(video_encode_accelerator_supported_profiles_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->video_encode_accelerator_supported_profiles.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null video_encode_accelerator_supported_profiles in GpuInfo struct");
            result->jpeg_decode_accelerator_supported = CallWithContext(Traits::jpeg_decode_accelerator_supported, input, custom_context);
            result->system_visual = CallWithContext(Traits::system_visual, input, custom_context);
            result->rgba_visual = CallWithContext(Traits::rgba_visual, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gpu::mojom::internal::GpuInfo_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gpu::mojom::GpuInfoDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace gpu {
namespace mojom {

    inline void GpuDeviceDataView::GetVendorStringDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->vendor_string.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuDeviceDataView::GetDeviceStringDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->device_string.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void VideoDecodeAcceleratorSupportedProfileDataView::GetMaxResolutionDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->max_resolution.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }
    inline void VideoDecodeAcceleratorSupportedProfileDataView::GetMinResolutionDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->min_resolution.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }

    inline void VideoDecodeAcceleratorCapabilitiesDataView::GetSupportedProfilesDataView(
        mojo::ArrayDataView<VideoDecodeAcceleratorSupportedProfileDataView>* output)
    {
        auto pointer = data_->supported_profiles.Get();
        *output = mojo::ArrayDataView<VideoDecodeAcceleratorSupportedProfileDataView>(pointer, context_);
    }

    inline void VideoEncodeAcceleratorSupportedProfileDataView::GetMaxResolutionDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->max_resolution.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }

    inline void GpuInfoDataView::GetInitializationTimeDataView(
        ::mojo::common::mojom::TimeDeltaDataView* output)
    {
        auto pointer = data_->initialization_time.Get();
        *output = ::mojo::common::mojom::TimeDeltaDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetDisplayLinkVersionDataView(
        ::mojo::common::mojom::VersionDataView* output)
    {
        auto pointer = data_->display_link_version.Get();
        *output = ::mojo::common::mojom::VersionDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetGpuDataView(
        GpuDeviceDataView* output)
    {
        auto pointer = data_->gpu.Get();
        *output = GpuDeviceDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetSecondaryGpusDataView(
        mojo::ArrayDataView<GpuDeviceDataView>* output)
    {
        auto pointer = data_->secondary_gpus.Get();
        *output = mojo::ArrayDataView<GpuDeviceDataView>(pointer, context_);
    }
    inline void GpuInfoDataView::GetDriverVendorDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->driver_vendor.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetDriverVersionDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->driver_version.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetDriverDateDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->driver_date.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetPixelShaderVersionDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->pixel_shader_version.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetVertexShaderVersionDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->vertex_shader_version.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetMaxMsaaSamplesDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->max_msaa_samples.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetMachineModelNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->machine_model_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetMachineModelVersionDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->machine_model_version.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetGlVersionDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->gl_version.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetGlVendorDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->gl_vendor.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetGlRendererDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->gl_renderer.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetGlExtensionsDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->gl_extensions.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetGlWsVendorDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->gl_ws_vendor.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetGlWsVersionDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->gl_ws_version.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetGlWsExtensionsDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->gl_ws_extensions.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetDxDiagnosticsDataView(
        ::gpu::mojom::DxDiagNodeDataView* output)
    {
        auto pointer = data_->dx_diagnostics.Get();
        *output = ::gpu::mojom::DxDiagNodeDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetVideoDecodeAcceleratorCapabilitiesDataView(
        VideoDecodeAcceleratorCapabilitiesDataView* output)
    {
        auto pointer = data_->video_decode_accelerator_capabilities.Get();
        *output = VideoDecodeAcceleratorCapabilitiesDataView(pointer, context_);
    }
    inline void GpuInfoDataView::GetVideoEncodeAcceleratorSupportedProfilesDataView(
        mojo::ArrayDataView<VideoEncodeAcceleratorSupportedProfileDataView>* output)
    {
        auto pointer = data_->video_encode_accelerator_supported_profiles.Get();
        *output = mojo::ArrayDataView<VideoEncodeAcceleratorSupportedProfileDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace gpu

#endif // GPU_IPC_COMMON_GPU_INFO_MOJOM_SHARED_H_
