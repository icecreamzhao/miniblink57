// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_USER_ACTIVITY_MONITOR_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_PUBLIC_INTERFACES_USER_ACTIVITY_MONITOR_MOJOM_SHARED_INTERNAL_H_

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
namespace ui {
namespace mojom {
    namespace internal {

        struct UserIdleObserver_IdleState_Data {
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
        constexpr uint32_t kUserActivityObserver_OnUserActivity_Name = 0;
        class UserActivityObserver_OnUserActivity_Params_Data {
        public:
            static UserActivityObserver_OnUserActivity_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(UserActivityObserver_OnUserActivity_Params_Data))) UserActivityObserver_OnUserActivity_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            UserActivityObserver_OnUserActivity_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~UserActivityObserver_OnUserActivity_Params_Data() = delete;
        };
        static_assert(sizeof(UserActivityObserver_OnUserActivity_Params_Data) == 8,
            "Bad sizeof(UserActivityObserver_OnUserActivity_Params_Data)");
        constexpr uint32_t kUserIdleObserver_OnUserIdleStateChanged_Name = 0;
        class UserIdleObserver_OnUserIdleStateChanged_Params_Data {
        public:
            static UserIdleObserver_OnUserIdleStateChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(UserIdleObserver_OnUserIdleStateChanged_Params_Data))) UserIdleObserver_OnUserIdleStateChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t new_state;
            uint8_t padfinal_[4];

        private:
            UserIdleObserver_OnUserIdleStateChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~UserIdleObserver_OnUserIdleStateChanged_Params_Data() = delete;
        };
        static_assert(sizeof(UserIdleObserver_OnUserIdleStateChanged_Params_Data) == 16,
            "Bad sizeof(UserIdleObserver_OnUserIdleStateChanged_Params_Data)");
        constexpr uint32_t kUserActivityMonitor_AddUserActivityObserver_Name = 0;
        class UserActivityMonitor_AddUserActivityObserver_Params_Data {
        public:
            static UserActivityMonitor_AddUserActivityObserver_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(UserActivityMonitor_AddUserActivityObserver_Params_Data))) UserActivityMonitor_AddUserActivityObserver_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t delay_between_notify_secs;
            mojo::internal::Interface_Data observer;
            uint8_t padfinal_[4];

        private:
            UserActivityMonitor_AddUserActivityObserver_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~UserActivityMonitor_AddUserActivityObserver_Params_Data() = delete;
        };
        static_assert(sizeof(UserActivityMonitor_AddUserActivityObserver_Params_Data) == 24,
            "Bad sizeof(UserActivityMonitor_AddUserActivityObserver_Params_Data)");
        constexpr uint32_t kUserActivityMonitor_AddUserIdleObserver_Name = 1;
        class UserActivityMonitor_AddUserIdleObserver_Params_Data {
        public:
            static UserActivityMonitor_AddUserIdleObserver_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(UserActivityMonitor_AddUserIdleObserver_Params_Data))) UserActivityMonitor_AddUserIdleObserver_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t idle_time_in_minutes;
            mojo::internal::Interface_Data observer;
            uint8_t padfinal_[4];

        private:
            UserActivityMonitor_AddUserIdleObserver_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~UserActivityMonitor_AddUserIdleObserver_Params_Data() = delete;
        };
        static_assert(sizeof(UserActivityMonitor_AddUserIdleObserver_Params_Data) == 24,
            "Bad sizeof(UserActivityMonitor_AddUserIdleObserver_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_USER_ACTIVITY_MONITOR_MOJOM_SHARED_INTERNAL_H_