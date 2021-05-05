// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_VIDEO_CAPTURE_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_VIDEO_CAPTURE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "media/capture/mojo/video_capture_types.mojom-shared-internal.h"
#include "media/mojo/interfaces/media_types.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace content {
namespace mojom {
    namespace internal {

        struct VideoCaptureState_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

#pragma pack(push, 1)
        constexpr uint32_t kVideoCaptureObserver_OnStateChanged_Name = 0;
        class VideoCaptureObserver_OnStateChanged_Params_Data {
        public:
            static VideoCaptureObserver_OnStateChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoCaptureObserver_OnStateChanged_Params_Data))) VideoCaptureObserver_OnStateChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t state;
            uint8_t padfinal_[4];

        private:
            VideoCaptureObserver_OnStateChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoCaptureObserver_OnStateChanged_Params_Data() = delete;
        };
        static_assert(sizeof(VideoCaptureObserver_OnStateChanged_Params_Data) == 16,
            "Bad sizeof(VideoCaptureObserver_OnStateChanged_Params_Data)");
        constexpr uint32_t kVideoCaptureObserver_OnBufferCreated_Name = 1;
        class VideoCaptureObserver_OnBufferCreated_Params_Data {
        public:
            static VideoCaptureObserver_OnBufferCreated_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoCaptureObserver_OnBufferCreated_Params_Data))) VideoCaptureObserver_OnBufferCreated_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t buffer_id;
            mojo::internal::Handle_Data handle_fd;

        private:
            VideoCaptureObserver_OnBufferCreated_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoCaptureObserver_OnBufferCreated_Params_Data() = delete;
        };
        static_assert(sizeof(VideoCaptureObserver_OnBufferCreated_Params_Data) == 16,
            "Bad sizeof(VideoCaptureObserver_OnBufferCreated_Params_Data)");
        constexpr uint32_t kVideoCaptureObserver_OnBufferReady_Name = 2;
        class VideoCaptureObserver_OnBufferReady_Params_Data {
        public:
            static VideoCaptureObserver_OnBufferReady_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoCaptureObserver_OnBufferReady_Params_Data))) VideoCaptureObserver_OnBufferReady_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t buffer_id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::media::mojom::internal::VideoFrameInfo_Data> info;

        private:
            VideoCaptureObserver_OnBufferReady_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoCaptureObserver_OnBufferReady_Params_Data() = delete;
        };
        static_assert(sizeof(VideoCaptureObserver_OnBufferReady_Params_Data) == 24,
            "Bad sizeof(VideoCaptureObserver_OnBufferReady_Params_Data)");
        constexpr uint32_t kVideoCaptureObserver_OnBufferDestroyed_Name = 3;
        class VideoCaptureObserver_OnBufferDestroyed_Params_Data {
        public:
            static VideoCaptureObserver_OnBufferDestroyed_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoCaptureObserver_OnBufferDestroyed_Params_Data))) VideoCaptureObserver_OnBufferDestroyed_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t buffer_id;
            uint8_t padfinal_[4];

        private:
            VideoCaptureObserver_OnBufferDestroyed_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoCaptureObserver_OnBufferDestroyed_Params_Data() = delete;
        };
        static_assert(sizeof(VideoCaptureObserver_OnBufferDestroyed_Params_Data) == 16,
            "Bad sizeof(VideoCaptureObserver_OnBufferDestroyed_Params_Data)");
        constexpr uint32_t kVideoCaptureHost_Start_Name = 0;
        class VideoCaptureHost_Start_Params_Data {
        public:
            static VideoCaptureHost_Start_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoCaptureHost_Start_Params_Data))) VideoCaptureHost_Start_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t device_id;
            int32_t session_id;
            mojo::internal::Pointer<::media::mojom::internal::VideoCaptureParams_Data> params;
            mojo::internal::Interface_Data observer;

        private:
            VideoCaptureHost_Start_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoCaptureHost_Start_Params_Data() = delete;
        };
        static_assert(sizeof(VideoCaptureHost_Start_Params_Data) == 32,
            "Bad sizeof(VideoCaptureHost_Start_Params_Data)");
        constexpr uint32_t kVideoCaptureHost_Stop_Name = 1;
        class VideoCaptureHost_Stop_Params_Data {
        public:
            static VideoCaptureHost_Stop_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoCaptureHost_Stop_Params_Data))) VideoCaptureHost_Stop_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t device_id;
            uint8_t padfinal_[4];

        private:
            VideoCaptureHost_Stop_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoCaptureHost_Stop_Params_Data() = delete;
        };
        static_assert(sizeof(VideoCaptureHost_Stop_Params_Data) == 16,
            "Bad sizeof(VideoCaptureHost_Stop_Params_Data)");
        constexpr uint32_t kVideoCaptureHost_Pause_Name = 2;
        class VideoCaptureHost_Pause_Params_Data {
        public:
            static VideoCaptureHost_Pause_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoCaptureHost_Pause_Params_Data))) VideoCaptureHost_Pause_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t device_id;
            uint8_t padfinal_[4];

        private:
            VideoCaptureHost_Pause_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoCaptureHost_Pause_Params_Data() = delete;
        };
        static_assert(sizeof(VideoCaptureHost_Pause_Params_Data) == 16,
            "Bad sizeof(VideoCaptureHost_Pause_Params_Data)");
        constexpr uint32_t kVideoCaptureHost_Resume_Name = 3;
        class VideoCaptureHost_Resume_Params_Data {
        public:
            static VideoCaptureHost_Resume_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoCaptureHost_Resume_Params_Data))) VideoCaptureHost_Resume_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t device_id;
            int32_t session_id;
            mojo::internal::Pointer<::media::mojom::internal::VideoCaptureParams_Data> params;

        private:
            VideoCaptureHost_Resume_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoCaptureHost_Resume_Params_Data() = delete;
        };
        static_assert(sizeof(VideoCaptureHost_Resume_Params_Data) == 24,
            "Bad sizeof(VideoCaptureHost_Resume_Params_Data)");
        constexpr uint32_t kVideoCaptureHost_RequestRefreshFrame_Name = 4;
        class VideoCaptureHost_RequestRefreshFrame_Params_Data {
        public:
            static VideoCaptureHost_RequestRefreshFrame_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoCaptureHost_RequestRefreshFrame_Params_Data))) VideoCaptureHost_RequestRefreshFrame_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t device_id;
            uint8_t padfinal_[4];

        private:
            VideoCaptureHost_RequestRefreshFrame_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoCaptureHost_RequestRefreshFrame_Params_Data() = delete;
        };
        static_assert(sizeof(VideoCaptureHost_RequestRefreshFrame_Params_Data) == 16,
            "Bad sizeof(VideoCaptureHost_RequestRefreshFrame_Params_Data)");
        constexpr uint32_t kVideoCaptureHost_ReleaseBuffer_Name = 5;
        class VideoCaptureHost_ReleaseBuffer_Params_Data {
        public:
            static VideoCaptureHost_ReleaseBuffer_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoCaptureHost_ReleaseBuffer_Params_Data))) VideoCaptureHost_ReleaseBuffer_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t device_id;
            int32_t buffer_id;
            double consumer_resource_utilization;

        private:
            VideoCaptureHost_ReleaseBuffer_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoCaptureHost_ReleaseBuffer_Params_Data() = delete;
        };
        static_assert(sizeof(VideoCaptureHost_ReleaseBuffer_Params_Data) == 24,
            "Bad sizeof(VideoCaptureHost_ReleaseBuffer_Params_Data)");
        constexpr uint32_t kVideoCaptureHost_GetDeviceSupportedFormats_Name = 6;
        class VideoCaptureHost_GetDeviceSupportedFormats_Params_Data {
        public:
            static VideoCaptureHost_GetDeviceSupportedFormats_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoCaptureHost_GetDeviceSupportedFormats_Params_Data))) VideoCaptureHost_GetDeviceSupportedFormats_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t device_id;
            int32_t session_id;

        private:
            VideoCaptureHost_GetDeviceSupportedFormats_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoCaptureHost_GetDeviceSupportedFormats_Params_Data() = delete;
        };
        static_assert(sizeof(VideoCaptureHost_GetDeviceSupportedFormats_Params_Data) == 16,
            "Bad sizeof(VideoCaptureHost_GetDeviceSupportedFormats_Params_Data)");
        class VideoCaptureHost_GetDeviceSupportedFormats_ResponseParams_Data {
        public:
            static VideoCaptureHost_GetDeviceSupportedFormats_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoCaptureHost_GetDeviceSupportedFormats_ResponseParams_Data))) VideoCaptureHost_GetDeviceSupportedFormats_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::media::mojom::internal::VideoCaptureFormat_Data>>> formats_supported;

        private:
            VideoCaptureHost_GetDeviceSupportedFormats_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoCaptureHost_GetDeviceSupportedFormats_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(VideoCaptureHost_GetDeviceSupportedFormats_ResponseParams_Data) == 16,
            "Bad sizeof(VideoCaptureHost_GetDeviceSupportedFormats_ResponseParams_Data)");
        constexpr uint32_t kVideoCaptureHost_GetDeviceFormatsInUse_Name = 7;
        class VideoCaptureHost_GetDeviceFormatsInUse_Params_Data {
        public:
            static VideoCaptureHost_GetDeviceFormatsInUse_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoCaptureHost_GetDeviceFormatsInUse_Params_Data))) VideoCaptureHost_GetDeviceFormatsInUse_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t device_id;
            int32_t session_id;

        private:
            VideoCaptureHost_GetDeviceFormatsInUse_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoCaptureHost_GetDeviceFormatsInUse_Params_Data() = delete;
        };
        static_assert(sizeof(VideoCaptureHost_GetDeviceFormatsInUse_Params_Data) == 16,
            "Bad sizeof(VideoCaptureHost_GetDeviceFormatsInUse_Params_Data)");
        class VideoCaptureHost_GetDeviceFormatsInUse_ResponseParams_Data {
        public:
            static VideoCaptureHost_GetDeviceFormatsInUse_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VideoCaptureHost_GetDeviceFormatsInUse_ResponseParams_Data))) VideoCaptureHost_GetDeviceFormatsInUse_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::media::mojom::internal::VideoCaptureFormat_Data>>> formats_in_use;

        private:
            VideoCaptureHost_GetDeviceFormatsInUse_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VideoCaptureHost_GetDeviceFormatsInUse_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(VideoCaptureHost_GetDeviceFormatsInUse_ResponseParams_Data) == 16,
            "Bad sizeof(VideoCaptureHost_GetDeviceFormatsInUse_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_VIDEO_CAPTURE_MOJOM_SHARED_INTERNAL_H_