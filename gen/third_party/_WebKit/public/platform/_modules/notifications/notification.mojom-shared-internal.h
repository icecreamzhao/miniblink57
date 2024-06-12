// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_MOJOM_SHARED_INTERNAL_H_

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
        class NotificationAction_Data;
        class Notification_Data;

        struct NotificationActionType_Data {
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

        struct NotificationDirection_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
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
        class NotificationAction_Data {
        public:
            static NotificationAction_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(NotificationAction_Data))) NotificationAction_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t type;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> action;
            mojo::internal::Pointer<mojo::internal::String_Data> title;
            mojo::internal::Pointer<mojo::internal::String_Data> icon;
            mojo::internal::Pointer<mojo::internal::String_Data> placeholder;

        private:
            NotificationAction_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~NotificationAction_Data() = delete;
        };
        static_assert(sizeof(NotificationAction_Data) == 48,
            "Bad sizeof(NotificationAction_Data)");
        class Notification_Data {
        public:
            static Notification_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Notification_Data))) Notification_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> title;
            int32_t direction;
            uint8_t renotify : 1;
            uint8_t silent : 1;
            uint8_t require_interaction : 1;
            uint8_t pad4_[3];
            mojo::internal::Pointer<mojo::internal::String_Data> lang;
            mojo::internal::Pointer<mojo::internal::String_Data> body;
            mojo::internal::Pointer<mojo::internal::String_Data> tag;
            mojo::internal::Pointer<mojo::internal::String_Data> icon;
            mojo::internal::Pointer<mojo::internal::String_Data> badge;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint32_t>> vibration_pattern;
            double timestamp;
            mojo::internal::Pointer<mojo::internal::Array_Data<int8_t>> data;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::NotificationAction_Data>>> actions;

        private:
            Notification_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Notification_Data() = delete;
        };
        static_assert(sizeof(Notification_Data) == 96,
            "Bad sizeof(Notification_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_MOJOM_SHARED_INTERNAL_H_