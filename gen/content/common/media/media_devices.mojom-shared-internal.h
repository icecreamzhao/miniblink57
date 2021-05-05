// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_MEDIA_MEDIA_DEVICES_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_MEDIA_MEDIA_DEVICES_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "url/mojo/origin.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace mojom {
namespace internal {
    using MediaDeviceInfo_Data = mojo::internal::NativeStruct_Data;
    using MediaDeviceType_Data = mojo::internal::NativeEnum_Data;

#pragma pack(push, 1)
    constexpr uint32_t kMediaDevicesDispatcherHost_EnumerateDevices_Name = 0;
    class MediaDevicesDispatcherHost_EnumerateDevices_Params_Data {
    public:
        static MediaDevicesDispatcherHost_EnumerateDevices_Params_Data* New(mojo::internal::Buffer* buf)
        {
            return new (buf->Allocate(sizeof(MediaDevicesDispatcherHost_EnumerateDevices_Params_Data))) MediaDevicesDispatcherHost_EnumerateDevices_Params_Data();
        }

        static bool Validate(const void* data,
            mojo::internal::ValidationContext* validation_context);

        mojo::internal::StructHeader header_;
        uint8_t request_audio_input : 1;
        uint8_t request_video_input : 1;
        uint8_t request_audio_output : 1;
        uint8_t pad2_[7];
        mojo::internal::Pointer<::url::mojom::internal::Origin_Data> security_origin;

    private:
        MediaDevicesDispatcherHost_EnumerateDevices_Params_Data()
            : header_({ sizeof(*this), 0 })
        {
        }
        ~MediaDevicesDispatcherHost_EnumerateDevices_Params_Data() = delete;
    };
    static_assert(sizeof(MediaDevicesDispatcherHost_EnumerateDevices_Params_Data) == 24,
        "Bad sizeof(MediaDevicesDispatcherHost_EnumerateDevices_Params_Data)");
    class MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data {
    public:
        static MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data* New(mojo::internal::Buffer* buf)
        {
            return new (buf->Allocate(sizeof(MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data))) MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data();
        }

        static bool Validate(const void* data,
            mojo::internal::ValidationContext* validation_context);

        mojo::internal::StructHeader header_;
        mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::MediaDeviceInfo_Data>>>>> enumeration;

    private:
        MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data()
            : header_({ sizeof(*this), 0 })
        {
        }
        ~MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data() = delete;
    };
    static_assert(sizeof(MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data) == 16,
        "Bad sizeof(MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data)");
    constexpr uint32_t kMediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Name = 1;
    class MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data {
    public:
        static MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data* New(mojo::internal::Buffer* buf)
        {
            return new (buf->Allocate(sizeof(MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data))) MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data();
        }

        static bool Validate(const void* data,
            mojo::internal::ValidationContext* validation_context);

        mojo::internal::StructHeader header_;
        int32_t type;
        uint32_t subscription_id;
        mojo::internal::Pointer<::url::mojom::internal::Origin_Data> security_origin;

    private:
        MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data()
            : header_({ sizeof(*this), 0 })
        {
        }
        ~MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data() = delete;
    };
    static_assert(sizeof(MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data) == 24,
        "Bad sizeof(MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data)");
    constexpr uint32_t kMediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Name = 2;
    class MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data {
    public:
        static MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data* New(mojo::internal::Buffer* buf)
        {
            return new (buf->Allocate(sizeof(MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data))) MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data();
        }

        static bool Validate(const void* data,
            mojo::internal::ValidationContext* validation_context);

        mojo::internal::StructHeader header_;
        int32_t type;
        uint32_t subscription_id;

    private:
        MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data()
            : header_({ sizeof(*this), 0 })
        {
        }
        ~MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data() = delete;
    };
    static_assert(sizeof(MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data) == 16,
        "Bad sizeof(MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data)");
    constexpr uint32_t kMediaDevicesListener_OnDevicesChanged_Name = 0;
    class MediaDevicesListener_OnDevicesChanged_Params_Data {
    public:
        static MediaDevicesListener_OnDevicesChanged_Params_Data* New(mojo::internal::Buffer* buf)
        {
            return new (buf->Allocate(sizeof(MediaDevicesListener_OnDevicesChanged_Params_Data))) MediaDevicesListener_OnDevicesChanged_Params_Data();
        }

        static bool Validate(const void* data,
            mojo::internal::ValidationContext* validation_context);

        mojo::internal::StructHeader header_;
        int32_t type;
        uint32_t subscription_id;
        mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::MediaDeviceInfo_Data>>> device_infos;

    private:
        MediaDevicesListener_OnDevicesChanged_Params_Data()
            : header_({ sizeof(*this), 0 })
        {
        }
        ~MediaDevicesListener_OnDevicesChanged_Params_Data() = delete;
    };
    static_assert(sizeof(MediaDevicesListener_OnDevicesChanged_Params_Data) == 24,
        "Bad sizeof(MediaDevicesListener_OnDevicesChanged_Params_Data)");

#pragma pack(pop)

} // namespace internal
} // namespace mojom

#endif // CONTENT_COMMON_MEDIA_MEDIA_DEVICES_MOJOM_SHARED_INTERNAL_H_