// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_RECEIVER_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_RECEIVER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "media/mojo/interfaces/media_types.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace video_capture {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kReceiver_OnIncomingCapturedVideoFrame_Name = 0;
        class Receiver_OnIncomingCapturedVideoFrame_Params_Data {
        public:
            static Receiver_OnIncomingCapturedVideoFrame_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Receiver_OnIncomingCapturedVideoFrame_Params_Data))) Receiver_OnIncomingCapturedVideoFrame_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::media::mojom::internal::VideoFrame_Data> frame;

        private:
            Receiver_OnIncomingCapturedVideoFrame_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Receiver_OnIncomingCapturedVideoFrame_Params_Data() = delete;
        };
        static_assert(sizeof(Receiver_OnIncomingCapturedVideoFrame_Params_Data) == 16,
            "Bad sizeof(Receiver_OnIncomingCapturedVideoFrame_Params_Data)");
        constexpr uint32_t kReceiver_OnError_Name = 1;
        class Receiver_OnError_Params_Data {
        public:
            static Receiver_OnError_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Receiver_OnError_Params_Data))) Receiver_OnError_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Receiver_OnError_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Receiver_OnError_Params_Data() = delete;
        };
        static_assert(sizeof(Receiver_OnError_Params_Data) == 8,
            "Bad sizeof(Receiver_OnError_Params_Data)");
        constexpr uint32_t kReceiver_OnLog_Name = 2;
        class Receiver_OnLog_Params_Data {
        public:
            static Receiver_OnLog_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Receiver_OnLog_Params_Data))) Receiver_OnLog_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> message;

        private:
            Receiver_OnLog_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Receiver_OnLog_Params_Data() = delete;
        };
        static_assert(sizeof(Receiver_OnLog_Params_Data) == 16,
            "Bad sizeof(Receiver_OnLog_Params_Data)");
        constexpr uint32_t kReceiver_OnBufferDestroyed_Name = 3;
        class Receiver_OnBufferDestroyed_Params_Data {
        public:
            static Receiver_OnBufferDestroyed_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Receiver_OnBufferDestroyed_Params_Data))) Receiver_OnBufferDestroyed_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t buffer_id_to_drop;
            uint8_t padfinal_[4];

        private:
            Receiver_OnBufferDestroyed_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Receiver_OnBufferDestroyed_Params_Data() = delete;
        };
        static_assert(sizeof(Receiver_OnBufferDestroyed_Params_Data) == 16,
            "Bad sizeof(Receiver_OnBufferDestroyed_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace video_capture

#endif // SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_RECEIVER_MOJOM_SHARED_INTERNAL_H_