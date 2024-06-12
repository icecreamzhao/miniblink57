// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_GPU_INFO_MOJOM_BLINK_H_
#define GPU_IPC_COMMON_GPU_INFO_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "gpu/ipc/common/dx_diag_node.mojom-blink.h"
#include "gpu/ipc/common/gpu_info.mojom-shared.h"
#include "mojo/common/time.mojom-blink.h"
#include "mojo/common/version.mojom-blink.h"
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
#include "ui/gfx/geometry/mojo/geometry.mojom-blink.h"

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebSize.h"

namespace gpu {
namespace mojom {
    namespace blink {
        using CollectInfoResult = CollectInfoResult; // Alias for definition in the parent namespace.
        using VideoCodecProfile = VideoCodecProfile; // Alias for definition in the parent namespace.
        class GpuDevice;
        using GpuDevicePtr = mojo::StructPtr<GpuDevice>;

        class VideoDecodeAcceleratorSupportedProfile;
        using VideoDecodeAcceleratorSupportedProfilePtr = mojo::StructPtr<VideoDecodeAcceleratorSupportedProfile>;

        class VideoDecodeAcceleratorCapabilities;
        using VideoDecodeAcceleratorCapabilitiesPtr = mojo::StructPtr<VideoDecodeAcceleratorCapabilities>;

        class VideoEncodeAcceleratorSupportedProfile;
        using VideoEncodeAcceleratorSupportedProfilePtr = mojo::StructPtr<VideoEncodeAcceleratorSupportedProfile>;

        class GpuInfo;
        using GpuInfoPtr = mojo::StructPtr<GpuInfo>;

        class GpuDevice {
        public:
            using DataView = GpuDeviceDataView;
            using Data_ = internal::GpuDevice_Data;

            static GpuDevicePtr New();

            template <typename U>
            static GpuDevicePtr From(const U& u)
            {
                return mojo::TypeConverter<GpuDevicePtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, GpuDevice>::Convert(*this);
            }

            GpuDevice();
            ~GpuDevice();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = GpuDevicePtr>
            GpuDevicePtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, GpuDevice>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    GpuDevice::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    GpuDevice::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            uint32_t vendor_id;
            uint32_t device_id;
            bool active;
            WTF::String vendor_string;
            WTF::String device_string;
        };

        class VideoDecodeAcceleratorSupportedProfile {
        public:
            using DataView = VideoDecodeAcceleratorSupportedProfileDataView;
            using Data_ = internal::VideoDecodeAcceleratorSupportedProfile_Data;

            static VideoDecodeAcceleratorSupportedProfilePtr New();

            template <typename U>
            static VideoDecodeAcceleratorSupportedProfilePtr From(const U& u)
            {
                return mojo::TypeConverter<VideoDecodeAcceleratorSupportedProfilePtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, VideoDecodeAcceleratorSupportedProfile>::Convert(*this);
            }

            VideoDecodeAcceleratorSupportedProfile();
            ~VideoDecodeAcceleratorSupportedProfile();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = VideoDecodeAcceleratorSupportedProfilePtr>
            VideoDecodeAcceleratorSupportedProfilePtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, VideoDecodeAcceleratorSupportedProfile>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    VideoDecodeAcceleratorSupportedProfile::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    VideoDecodeAcceleratorSupportedProfile::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            VideoCodecProfile profile;
            ::blink::WebSize max_resolution;
            ::blink::WebSize min_resolution;
            bool encrypted_only;
        };

        class VideoDecodeAcceleratorCapabilities {
        public:
            using DataView = VideoDecodeAcceleratorCapabilitiesDataView;
            using Data_ = internal::VideoDecodeAcceleratorCapabilities_Data;

            static VideoDecodeAcceleratorCapabilitiesPtr New();

            template <typename U>
            static VideoDecodeAcceleratorCapabilitiesPtr From(const U& u)
            {
                return mojo::TypeConverter<VideoDecodeAcceleratorCapabilitiesPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, VideoDecodeAcceleratorCapabilities>::Convert(*this);
            }

            VideoDecodeAcceleratorCapabilities();
            ~VideoDecodeAcceleratorCapabilities();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = VideoDecodeAcceleratorCapabilitiesPtr>
            VideoDecodeAcceleratorCapabilitiesPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, VideoDecodeAcceleratorCapabilities>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    VideoDecodeAcceleratorCapabilities::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    VideoDecodeAcceleratorCapabilities::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::Vector<VideoDecodeAcceleratorSupportedProfilePtr> supported_profiles;
            uint32_t flags;

        private:
            DISALLOW_COPY_AND_ASSIGN(VideoDecodeAcceleratorCapabilities);
        };

        class VideoEncodeAcceleratorSupportedProfile {
        public:
            using DataView = VideoEncodeAcceleratorSupportedProfileDataView;
            using Data_ = internal::VideoEncodeAcceleratorSupportedProfile_Data;

            static VideoEncodeAcceleratorSupportedProfilePtr New();

            template <typename U>
            static VideoEncodeAcceleratorSupportedProfilePtr From(const U& u)
            {
                return mojo::TypeConverter<VideoEncodeAcceleratorSupportedProfilePtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, VideoEncodeAcceleratorSupportedProfile>::Convert(*this);
            }

            VideoEncodeAcceleratorSupportedProfile();
            ~VideoEncodeAcceleratorSupportedProfile();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = VideoEncodeAcceleratorSupportedProfilePtr>
            VideoEncodeAcceleratorSupportedProfilePtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, VideoEncodeAcceleratorSupportedProfile>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    VideoEncodeAcceleratorSupportedProfile::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    VideoEncodeAcceleratorSupportedProfile::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            VideoCodecProfile profile;
            ::blink::WebSize max_resolution;
            uint32_t max_framerate_numerator;
            uint32_t max_framerate_denominator;
        };

        class GpuInfo {
        public:
            using DataView = GpuInfoDataView;
            using Data_ = internal::GpuInfo_Data;

            static GpuInfoPtr New();

            template <typename U>
            static GpuInfoPtr From(const U& u)
            {
                return mojo::TypeConverter<GpuInfoPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, GpuInfo>::Convert(*this);
            }

            GpuInfo();
            ~GpuInfo();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = GpuInfoPtr>
            GpuInfoPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, GpuInfo>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    GpuInfo::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    GpuInfo::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::mojo::common::mojom::blink::TimeDeltaPtr initialization_time;
            bool optimus;
            bool amd_switchable;
            bool lenovo_dcute;
            ::mojo::common::mojom::blink::VersionPtr display_link_version;
            GpuDevicePtr gpu;
            WTF::Vector<GpuDevicePtr> secondary_gpus;
            uint64_t adapter_luid;
            WTF::String driver_vendor;
            WTF::String driver_version;
            WTF::String driver_date;
            WTF::String pixel_shader_version;
            WTF::String vertex_shader_version;
            WTF::String max_msaa_samples;
            WTF::String machine_model_name;
            WTF::String machine_model_version;
            WTF::String gl_version;
            WTF::String gl_vendor;
            WTF::String gl_renderer;
            WTF::String gl_extensions;
            WTF::String gl_ws_vendor;
            WTF::String gl_ws_version;
            WTF::String gl_ws_extensions;
            uint32_t gl_reset_notification_strategy;
            bool software_rendering;
            bool direct_rendering;
            bool sandboxed;
            int32_t process_crash_count;
            bool in_process_gpu;
            bool passthrough_cmd_decoder;
            CollectInfoResult basic_info_state;
            CollectInfoResult context_info_state;
            CollectInfoResult dx_diagnostics_info_state;
            ::gpu::mojom::blink::DxDiagNodePtr dx_diagnostics;
            VideoDecodeAcceleratorCapabilitiesPtr video_decode_accelerator_capabilities;
            WTF::Vector<VideoEncodeAcceleratorSupportedProfilePtr> video_encode_accelerator_supported_profiles;
            bool jpeg_decode_accelerator_supported;
            uint64_t system_visual;
            uint64_t rgba_visual;

        private:
            DISALLOW_COPY_AND_ASSIGN(GpuInfo);
        };

        template <typename StructPtrType>
        GpuDevicePtr GpuDevice::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->vendor_id = mojo::internal::Clone(vendor_id);
            rv->device_id = mojo::internal::Clone(device_id);
            rv->active = mojo::internal::Clone(active);
            rv->vendor_string = mojo::internal::Clone(vendor_string);
            rv->device_string = mojo::internal::Clone(device_string);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, GpuDevice>::value>::type*>
        bool GpuDevice::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->vendor_id, other.vendor_id))
                return false;
            if (!mojo::internal::Equals(this->device_id, other.device_id))
                return false;
            if (!mojo::internal::Equals(this->active, other.active))
                return false;
            if (!mojo::internal::Equals(this->vendor_string, other.vendor_string))
                return false;
            if (!mojo::internal::Equals(this->device_string, other.device_string))
                return false;
            return true;
        }
        template <typename StructPtrType>
        VideoDecodeAcceleratorSupportedProfilePtr VideoDecodeAcceleratorSupportedProfile::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->profile = mojo::internal::Clone(profile);
            rv->max_resolution = mojo::internal::Clone(max_resolution);
            rv->min_resolution = mojo::internal::Clone(min_resolution);
            rv->encrypted_only = mojo::internal::Clone(encrypted_only);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, VideoDecodeAcceleratorSupportedProfile>::value>::type*>
        bool VideoDecodeAcceleratorSupportedProfile::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->profile, other.profile))
                return false;
            if (!mojo::internal::Equals(this->max_resolution, other.max_resolution))
                return false;
            if (!mojo::internal::Equals(this->min_resolution, other.min_resolution))
                return false;
            if (!mojo::internal::Equals(this->encrypted_only, other.encrypted_only))
                return false;
            return true;
        }
        template <typename StructPtrType>
        VideoDecodeAcceleratorCapabilitiesPtr VideoDecodeAcceleratorCapabilities::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->supported_profiles = mojo::internal::Clone(supported_profiles);
            rv->flags = mojo::internal::Clone(flags);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, VideoDecodeAcceleratorCapabilities>::value>::type*>
        bool VideoDecodeAcceleratorCapabilities::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->supported_profiles, other.supported_profiles))
                return false;
            if (!mojo::internal::Equals(this->flags, other.flags))
                return false;
            return true;
        }
        template <typename StructPtrType>
        VideoEncodeAcceleratorSupportedProfilePtr VideoEncodeAcceleratorSupportedProfile::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->profile = mojo::internal::Clone(profile);
            rv->max_resolution = mojo::internal::Clone(max_resolution);
            rv->max_framerate_numerator = mojo::internal::Clone(max_framerate_numerator);
            rv->max_framerate_denominator = mojo::internal::Clone(max_framerate_denominator);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, VideoEncodeAcceleratorSupportedProfile>::value>::type*>
        bool VideoEncodeAcceleratorSupportedProfile::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->profile, other.profile))
                return false;
            if (!mojo::internal::Equals(this->max_resolution, other.max_resolution))
                return false;
            if (!mojo::internal::Equals(this->max_framerate_numerator, other.max_framerate_numerator))
                return false;
            if (!mojo::internal::Equals(this->max_framerate_denominator, other.max_framerate_denominator))
                return false;
            return true;
        }
        template <typename StructPtrType>
        GpuInfoPtr GpuInfo::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->initialization_time = mojo::internal::Clone(initialization_time);
            rv->optimus = mojo::internal::Clone(optimus);
            rv->amd_switchable = mojo::internal::Clone(amd_switchable);
            rv->lenovo_dcute = mojo::internal::Clone(lenovo_dcute);
            rv->display_link_version = mojo::internal::Clone(display_link_version);
            rv->gpu = mojo::internal::Clone(gpu);
            rv->secondary_gpus = mojo::internal::Clone(secondary_gpus);
            rv->adapter_luid = mojo::internal::Clone(adapter_luid);
            rv->driver_vendor = mojo::internal::Clone(driver_vendor);
            rv->driver_version = mojo::internal::Clone(driver_version);
            rv->driver_date = mojo::internal::Clone(driver_date);
            rv->pixel_shader_version = mojo::internal::Clone(pixel_shader_version);
            rv->vertex_shader_version = mojo::internal::Clone(vertex_shader_version);
            rv->max_msaa_samples = mojo::internal::Clone(max_msaa_samples);
            rv->machine_model_name = mojo::internal::Clone(machine_model_name);
            rv->machine_model_version = mojo::internal::Clone(machine_model_version);
            rv->gl_version = mojo::internal::Clone(gl_version);
            rv->gl_vendor = mojo::internal::Clone(gl_vendor);
            rv->gl_renderer = mojo::internal::Clone(gl_renderer);
            rv->gl_extensions = mojo::internal::Clone(gl_extensions);
            rv->gl_ws_vendor = mojo::internal::Clone(gl_ws_vendor);
            rv->gl_ws_version = mojo::internal::Clone(gl_ws_version);
            rv->gl_ws_extensions = mojo::internal::Clone(gl_ws_extensions);
            rv->gl_reset_notification_strategy = mojo::internal::Clone(gl_reset_notification_strategy);
            rv->software_rendering = mojo::internal::Clone(software_rendering);
            rv->direct_rendering = mojo::internal::Clone(direct_rendering);
            rv->sandboxed = mojo::internal::Clone(sandboxed);
            rv->process_crash_count = mojo::internal::Clone(process_crash_count);
            rv->in_process_gpu = mojo::internal::Clone(in_process_gpu);
            rv->passthrough_cmd_decoder = mojo::internal::Clone(passthrough_cmd_decoder);
            rv->basic_info_state = mojo::internal::Clone(basic_info_state);
            rv->context_info_state = mojo::internal::Clone(context_info_state);
            rv->dx_diagnostics_info_state = mojo::internal::Clone(dx_diagnostics_info_state);
            rv->dx_diagnostics = mojo::internal::Clone(dx_diagnostics);
            rv->video_decode_accelerator_capabilities = mojo::internal::Clone(video_decode_accelerator_capabilities);
            rv->video_encode_accelerator_supported_profiles = mojo::internal::Clone(video_encode_accelerator_supported_profiles);
            rv->jpeg_decode_accelerator_supported = mojo::internal::Clone(jpeg_decode_accelerator_supported);
            rv->system_visual = mojo::internal::Clone(system_visual);
            rv->rgba_visual = mojo::internal::Clone(rgba_visual);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, GpuInfo>::value>::type*>
        bool GpuInfo::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->initialization_time, other.initialization_time))
                return false;
            if (!mojo::internal::Equals(this->optimus, other.optimus))
                return false;
            if (!mojo::internal::Equals(this->amd_switchable, other.amd_switchable))
                return false;
            if (!mojo::internal::Equals(this->lenovo_dcute, other.lenovo_dcute))
                return false;
            if (!mojo::internal::Equals(this->display_link_version, other.display_link_version))
                return false;
            if (!mojo::internal::Equals(this->gpu, other.gpu))
                return false;
            if (!mojo::internal::Equals(this->secondary_gpus, other.secondary_gpus))
                return false;
            if (!mojo::internal::Equals(this->adapter_luid, other.adapter_luid))
                return false;
            if (!mojo::internal::Equals(this->driver_vendor, other.driver_vendor))
                return false;
            if (!mojo::internal::Equals(this->driver_version, other.driver_version))
                return false;
            if (!mojo::internal::Equals(this->driver_date, other.driver_date))
                return false;
            if (!mojo::internal::Equals(this->pixel_shader_version, other.pixel_shader_version))
                return false;
            if (!mojo::internal::Equals(this->vertex_shader_version, other.vertex_shader_version))
                return false;
            if (!mojo::internal::Equals(this->max_msaa_samples, other.max_msaa_samples))
                return false;
            if (!mojo::internal::Equals(this->machine_model_name, other.machine_model_name))
                return false;
            if (!mojo::internal::Equals(this->machine_model_version, other.machine_model_version))
                return false;
            if (!mojo::internal::Equals(this->gl_version, other.gl_version))
                return false;
            if (!mojo::internal::Equals(this->gl_vendor, other.gl_vendor))
                return false;
            if (!mojo::internal::Equals(this->gl_renderer, other.gl_renderer))
                return false;
            if (!mojo::internal::Equals(this->gl_extensions, other.gl_extensions))
                return false;
            if (!mojo::internal::Equals(this->gl_ws_vendor, other.gl_ws_vendor))
                return false;
            if (!mojo::internal::Equals(this->gl_ws_version, other.gl_ws_version))
                return false;
            if (!mojo::internal::Equals(this->gl_ws_extensions, other.gl_ws_extensions))
                return false;
            if (!mojo::internal::Equals(this->gl_reset_notification_strategy, other.gl_reset_notification_strategy))
                return false;
            if (!mojo::internal::Equals(this->software_rendering, other.software_rendering))
                return false;
            if (!mojo::internal::Equals(this->direct_rendering, other.direct_rendering))
                return false;
            if (!mojo::internal::Equals(this->sandboxed, other.sandboxed))
                return false;
            if (!mojo::internal::Equals(this->process_crash_count, other.process_crash_count))
                return false;
            if (!mojo::internal::Equals(this->in_process_gpu, other.in_process_gpu))
                return false;
            if (!mojo::internal::Equals(this->passthrough_cmd_decoder, other.passthrough_cmd_decoder))
                return false;
            if (!mojo::internal::Equals(this->basic_info_state, other.basic_info_state))
                return false;
            if (!mojo::internal::Equals(this->context_info_state, other.context_info_state))
                return false;
            if (!mojo::internal::Equals(this->dx_diagnostics_info_state, other.dx_diagnostics_info_state))
                return false;
            if (!mojo::internal::Equals(this->dx_diagnostics, other.dx_diagnostics))
                return false;
            if (!mojo::internal::Equals(this->video_decode_accelerator_capabilities, other.video_decode_accelerator_capabilities))
                return false;
            if (!mojo::internal::Equals(this->video_encode_accelerator_supported_profiles, other.video_encode_accelerator_supported_profiles))
                return false;
            if (!mojo::internal::Equals(this->jpeg_decode_accelerator_supported, other.jpeg_decode_accelerator_supported))
                return false;
            if (!mojo::internal::Equals(this->system_visual, other.system_visual))
                return false;
            if (!mojo::internal::Equals(this->rgba_visual, other.rgba_visual))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace gpu

namespace mojo {

template <>
struct StructTraits<::gpu::mojom::blink::GpuDevice::DataView,
    ::gpu::mojom::blink::GpuDevicePtr> {
    static bool IsNull(const ::gpu::mojom::blink::GpuDevicePtr& input) { return !input; }
    static void SetToNull(::gpu::mojom::blink::GpuDevicePtr* output) { output->reset(); }

    static decltype(::gpu::mojom::blink::GpuDevice::vendor_id) vendor_id(
        const ::gpu::mojom::blink::GpuDevicePtr& input)
    {
        return input->vendor_id;
    }

    static decltype(::gpu::mojom::blink::GpuDevice::device_id) device_id(
        const ::gpu::mojom::blink::GpuDevicePtr& input)
    {
        return input->device_id;
    }

    static decltype(::gpu::mojom::blink::GpuDevice::active) active(
        const ::gpu::mojom::blink::GpuDevicePtr& input)
    {
        return input->active;
    }

    static const decltype(::gpu::mojom::blink::GpuDevice::vendor_string)& vendor_string(
        const ::gpu::mojom::blink::GpuDevicePtr& input)
    {
        return input->vendor_string;
    }

    static const decltype(::gpu::mojom::blink::GpuDevice::device_string)& device_string(
        const ::gpu::mojom::blink::GpuDevicePtr& input)
    {
        return input->device_string;
    }

    static bool Read(::gpu::mojom::blink::GpuDevice::DataView input, ::gpu::mojom::blink::GpuDevicePtr* output);
};

template <>
struct StructTraits<::gpu::mojom::blink::VideoDecodeAcceleratorSupportedProfile::DataView,
    ::gpu::mojom::blink::VideoDecodeAcceleratorSupportedProfilePtr> {
    static bool IsNull(const ::gpu::mojom::blink::VideoDecodeAcceleratorSupportedProfilePtr& input) { return !input; }
    static void SetToNull(::gpu::mojom::blink::VideoDecodeAcceleratorSupportedProfilePtr* output) { output->reset(); }

    static decltype(::gpu::mojom::blink::VideoDecodeAcceleratorSupportedProfile::profile) profile(
        const ::gpu::mojom::blink::VideoDecodeAcceleratorSupportedProfilePtr& input)
    {
        return input->profile;
    }

    static const decltype(::gpu::mojom::blink::VideoDecodeAcceleratorSupportedProfile::max_resolution)& max_resolution(
        const ::gpu::mojom::blink::VideoDecodeAcceleratorSupportedProfilePtr& input)
    {
        return input->max_resolution;
    }

    static const decltype(::gpu::mojom::blink::VideoDecodeAcceleratorSupportedProfile::min_resolution)& min_resolution(
        const ::gpu::mojom::blink::VideoDecodeAcceleratorSupportedProfilePtr& input)
    {
        return input->min_resolution;
    }

    static decltype(::gpu::mojom::blink::VideoDecodeAcceleratorSupportedProfile::encrypted_only) encrypted_only(
        const ::gpu::mojom::blink::VideoDecodeAcceleratorSupportedProfilePtr& input)
    {
        return input->encrypted_only;
    }

    static bool Read(::gpu::mojom::blink::VideoDecodeAcceleratorSupportedProfile::DataView input, ::gpu::mojom::blink::VideoDecodeAcceleratorSupportedProfilePtr* output);
};

template <>
struct StructTraits<::gpu::mojom::blink::VideoDecodeAcceleratorCapabilities::DataView,
    ::gpu::mojom::blink::VideoDecodeAcceleratorCapabilitiesPtr> {
    static bool IsNull(const ::gpu::mojom::blink::VideoDecodeAcceleratorCapabilitiesPtr& input) { return !input; }
    static void SetToNull(::gpu::mojom::blink::VideoDecodeAcceleratorCapabilitiesPtr* output) { output->reset(); }

    static const decltype(::gpu::mojom::blink::VideoDecodeAcceleratorCapabilities::supported_profiles)& supported_profiles(
        const ::gpu::mojom::blink::VideoDecodeAcceleratorCapabilitiesPtr& input)
    {
        return input->supported_profiles;
    }

    static decltype(::gpu::mojom::blink::VideoDecodeAcceleratorCapabilities::flags) flags(
        const ::gpu::mojom::blink::VideoDecodeAcceleratorCapabilitiesPtr& input)
    {
        return input->flags;
    }

    static bool Read(::gpu::mojom::blink::VideoDecodeAcceleratorCapabilities::DataView input, ::gpu::mojom::blink::VideoDecodeAcceleratorCapabilitiesPtr* output);
};

template <>
struct StructTraits<::gpu::mojom::blink::VideoEncodeAcceleratorSupportedProfile::DataView,
    ::gpu::mojom::blink::VideoEncodeAcceleratorSupportedProfilePtr> {
    static bool IsNull(const ::gpu::mojom::blink::VideoEncodeAcceleratorSupportedProfilePtr& input) { return !input; }
    static void SetToNull(::gpu::mojom::blink::VideoEncodeAcceleratorSupportedProfilePtr* output) { output->reset(); }

    static decltype(::gpu::mojom::blink::VideoEncodeAcceleratorSupportedProfile::profile) profile(
        const ::gpu::mojom::blink::VideoEncodeAcceleratorSupportedProfilePtr& input)
    {
        return input->profile;
    }

    static const decltype(::gpu::mojom::blink::VideoEncodeAcceleratorSupportedProfile::max_resolution)& max_resolution(
        const ::gpu::mojom::blink::VideoEncodeAcceleratorSupportedProfilePtr& input)
    {
        return input->max_resolution;
    }

    static decltype(::gpu::mojom::blink::VideoEncodeAcceleratorSupportedProfile::max_framerate_numerator) max_framerate_numerator(
        const ::gpu::mojom::blink::VideoEncodeAcceleratorSupportedProfilePtr& input)
    {
        return input->max_framerate_numerator;
    }

    static decltype(::gpu::mojom::blink::VideoEncodeAcceleratorSupportedProfile::max_framerate_denominator) max_framerate_denominator(
        const ::gpu::mojom::blink::VideoEncodeAcceleratorSupportedProfilePtr& input)
    {
        return input->max_framerate_denominator;
    }

    static bool Read(::gpu::mojom::blink::VideoEncodeAcceleratorSupportedProfile::DataView input, ::gpu::mojom::blink::VideoEncodeAcceleratorSupportedProfilePtr* output);
};

template <>
struct StructTraits<::gpu::mojom::blink::GpuInfo::DataView,
    ::gpu::mojom::blink::GpuInfoPtr> {
    static bool IsNull(const ::gpu::mojom::blink::GpuInfoPtr& input) { return !input; }
    static void SetToNull(::gpu::mojom::blink::GpuInfoPtr* output) { output->reset(); }

    static const decltype(::gpu::mojom::blink::GpuInfo::initialization_time)& initialization_time(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->initialization_time;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::optimus) optimus(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->optimus;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::amd_switchable) amd_switchable(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->amd_switchable;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::lenovo_dcute) lenovo_dcute(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->lenovo_dcute;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::display_link_version)& display_link_version(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->display_link_version;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::gpu)& gpu(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->gpu;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::secondary_gpus)& secondary_gpus(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->secondary_gpus;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::adapter_luid) adapter_luid(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->adapter_luid;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::driver_vendor)& driver_vendor(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->driver_vendor;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::driver_version)& driver_version(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->driver_version;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::driver_date)& driver_date(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->driver_date;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::pixel_shader_version)& pixel_shader_version(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->pixel_shader_version;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::vertex_shader_version)& vertex_shader_version(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->vertex_shader_version;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::max_msaa_samples)& max_msaa_samples(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->max_msaa_samples;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::machine_model_name)& machine_model_name(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->machine_model_name;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::machine_model_version)& machine_model_version(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->machine_model_version;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::gl_version)& gl_version(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->gl_version;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::gl_vendor)& gl_vendor(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->gl_vendor;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::gl_renderer)& gl_renderer(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->gl_renderer;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::gl_extensions)& gl_extensions(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->gl_extensions;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::gl_ws_vendor)& gl_ws_vendor(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->gl_ws_vendor;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::gl_ws_version)& gl_ws_version(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->gl_ws_version;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::gl_ws_extensions)& gl_ws_extensions(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->gl_ws_extensions;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::gl_reset_notification_strategy) gl_reset_notification_strategy(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->gl_reset_notification_strategy;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::software_rendering) software_rendering(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->software_rendering;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::direct_rendering) direct_rendering(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->direct_rendering;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::sandboxed) sandboxed(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->sandboxed;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::process_crash_count) process_crash_count(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->process_crash_count;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::in_process_gpu) in_process_gpu(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->in_process_gpu;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::passthrough_cmd_decoder) passthrough_cmd_decoder(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->passthrough_cmd_decoder;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::basic_info_state) basic_info_state(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->basic_info_state;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::context_info_state) context_info_state(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->context_info_state;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::dx_diagnostics_info_state) dx_diagnostics_info_state(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->dx_diagnostics_info_state;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::dx_diagnostics)& dx_diagnostics(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->dx_diagnostics;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::video_decode_accelerator_capabilities)& video_decode_accelerator_capabilities(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->video_decode_accelerator_capabilities;
    }

    static const decltype(::gpu::mojom::blink::GpuInfo::video_encode_accelerator_supported_profiles)& video_encode_accelerator_supported_profiles(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->video_encode_accelerator_supported_profiles;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::jpeg_decode_accelerator_supported) jpeg_decode_accelerator_supported(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->jpeg_decode_accelerator_supported;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::system_visual) system_visual(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->system_visual;
    }

    static decltype(::gpu::mojom::blink::GpuInfo::rgba_visual) rgba_visual(
        const ::gpu::mojom::blink::GpuInfoPtr& input)
    {
        return input->rgba_visual;
    }

    static bool Read(::gpu::mojom::blink::GpuInfo::DataView input, ::gpu::mojom::blink::GpuInfoPtr* output);
};

} // namespace mojo

#endif // GPU_IPC_COMMON_GPU_INFO_MOJOM_BLINK_H_