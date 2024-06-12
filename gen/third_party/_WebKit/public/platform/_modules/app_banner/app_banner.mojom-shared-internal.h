// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_APP_BANNER_APP_BANNER_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_APP_BANNER_APP_BANNER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

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
namespace blink {
namespace mojom {
    namespace internal {

        struct AppBannerPromptReply_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
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
        constexpr uint32_t kAppBannerController_BannerPromptRequest_Name = 0;
        class AppBannerController_BannerPromptRequest_Params_Data {
        public:
            static AppBannerController_BannerPromptRequest_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AppBannerController_BannerPromptRequest_Params_Data))) AppBannerController_BannerPromptRequest_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data service;
            mojo::internal::Handle_Data event;
            uint8_t pad1_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<mojo::internal::String_Data>>> platform;

        private:
            AppBannerController_BannerPromptRequest_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AppBannerController_BannerPromptRequest_Params_Data() = delete;
        };
        static_assert(sizeof(AppBannerController_BannerPromptRequest_Params_Data) == 32,
            "Bad sizeof(AppBannerController_BannerPromptRequest_Params_Data)");
        class AppBannerController_BannerPromptRequest_ResponseParams_Data {
        public:
            static AppBannerController_BannerPromptRequest_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AppBannerController_BannerPromptRequest_ResponseParams_Data))) AppBannerController_BannerPromptRequest_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t reply;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> referrer;

        private:
            AppBannerController_BannerPromptRequest_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AppBannerController_BannerPromptRequest_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(AppBannerController_BannerPromptRequest_ResponseParams_Data) == 24,
            "Bad sizeof(AppBannerController_BannerPromptRequest_ResponseParams_Data)");
        constexpr uint32_t kAppBannerEvent_BannerAccepted_Name = 0;
        class AppBannerEvent_BannerAccepted_Params_Data {
        public:
            static AppBannerEvent_BannerAccepted_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AppBannerEvent_BannerAccepted_Params_Data))) AppBannerEvent_BannerAccepted_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> platform;

        private:
            AppBannerEvent_BannerAccepted_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AppBannerEvent_BannerAccepted_Params_Data() = delete;
        };
        static_assert(sizeof(AppBannerEvent_BannerAccepted_Params_Data) == 16,
            "Bad sizeof(AppBannerEvent_BannerAccepted_Params_Data)");
        constexpr uint32_t kAppBannerEvent_BannerDismissed_Name = 1;
        class AppBannerEvent_BannerDismissed_Params_Data {
        public:
            static AppBannerEvent_BannerDismissed_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AppBannerEvent_BannerDismissed_Params_Data))) AppBannerEvent_BannerDismissed_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            AppBannerEvent_BannerDismissed_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AppBannerEvent_BannerDismissed_Params_Data() = delete;
        };
        static_assert(sizeof(AppBannerEvent_BannerDismissed_Params_Data) == 8,
            "Bad sizeof(AppBannerEvent_BannerDismissed_Params_Data)");
        constexpr uint32_t kAppBannerService_DisplayAppBanner_Name = 0;
        class AppBannerService_DisplayAppBanner_Params_Data {
        public:
            static AppBannerService_DisplayAppBanner_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AppBannerService_DisplayAppBanner_Params_Data))) AppBannerService_DisplayAppBanner_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            AppBannerService_DisplayAppBanner_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AppBannerService_DisplayAppBanner_Params_Data() = delete;
        };
        static_assert(sizeof(AppBannerService_DisplayAppBanner_Params_Data) == 8,
            "Bad sizeof(AppBannerService_DisplayAppBanner_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_APP_BANNER_APP_BANNER_MOJOM_SHARED_INTERNAL_H_