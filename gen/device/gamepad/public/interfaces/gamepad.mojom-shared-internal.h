// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_GAMEPAD_PUBLIC_INTERFACES_GAMEPAD_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_GAMEPAD_PUBLIC_INTERFACES_GAMEPAD_MOJOM_SHARED_INTERNAL_H_

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
namespace device {
namespace mojom {
    namespace internal {
        class GamepadQuaternion_Data;
        class GamepadVector_Data;
        class GamepadButton_Data;
        class GamepadPose_Data;
        class Gamepad_Data;

        struct GamepadHand_Data {
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
        class GamepadQuaternion_Data {
        public:
            static GamepadQuaternion_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GamepadQuaternion_Data))) GamepadQuaternion_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            float x;
            float y;
            float z;
            float w;

        private:
            GamepadQuaternion_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GamepadQuaternion_Data() = delete;
        };
        static_assert(sizeof(GamepadQuaternion_Data) == 24,
            "Bad sizeof(GamepadQuaternion_Data)");
        class GamepadVector_Data {
        public:
            static GamepadVector_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GamepadVector_Data))) GamepadVector_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            float x;
            float y;
            float z;
            uint8_t padfinal_[4];

        private:
            GamepadVector_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GamepadVector_Data() = delete;
        };
        static_assert(sizeof(GamepadVector_Data) == 24,
            "Bad sizeof(GamepadVector_Data)");
        class GamepadButton_Data {
        public:
            static GamepadButton_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GamepadButton_Data))) GamepadButton_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t pressed : 1;
            uint8_t touched : 1;
            uint8_t pad1_[7];
            double value;

        private:
            GamepadButton_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GamepadButton_Data() = delete;
        };
        static_assert(sizeof(GamepadButton_Data) == 24,
            "Bad sizeof(GamepadButton_Data)");
        class GamepadPose_Data {
        public:
            static GamepadPose_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GamepadPose_Data))) GamepadPose_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::GamepadQuaternion_Data> orientation;
            mojo::internal::Pointer<internal::GamepadVector_Data> position;
            mojo::internal::Pointer<internal::GamepadVector_Data> angular_velocity;
            mojo::internal::Pointer<internal::GamepadVector_Data> linear_velocity;
            mojo::internal::Pointer<internal::GamepadVector_Data> angular_acceleration;
            mojo::internal::Pointer<internal::GamepadVector_Data> linear_acceleration;

        private:
            GamepadPose_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GamepadPose_Data() = delete;
        };
        static_assert(sizeof(GamepadPose_Data) == 56,
            "Bad sizeof(GamepadPose_Data)");
        class Gamepad_Data {
        public:
            static Gamepad_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Gamepad_Data))) Gamepad_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t connected : 1;
            uint8_t pad0_[3];
            int32_t hand;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint16_t>> id;
            uint64_t timestamp;
            mojo::internal::Pointer<mojo::internal::Array_Data<double>> axes;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::GamepadButton_Data>>> buttons;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint16_t>> mapping;
            mojo::internal::Pointer<internal::GamepadPose_Data> pose;
            uint32_t display_id;
            uint8_t padfinal_[4];

        private:
            Gamepad_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Gamepad_Data() = delete;
        };
        static_assert(sizeof(Gamepad_Data) == 72,
            "Bad sizeof(Gamepad_Data)");
        constexpr uint32_t kGamepadObserver_GamepadConnected_Name = 0;
        class GamepadObserver_GamepadConnected_Params_Data {
        public:
            static GamepadObserver_GamepadConnected_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GamepadObserver_GamepadConnected_Params_Data))) GamepadObserver_GamepadConnected_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t index;
            uint8_t pad0_[4];
            mojo::internal::Pointer<internal::Gamepad_Data> gamepad;

        private:
            GamepadObserver_GamepadConnected_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GamepadObserver_GamepadConnected_Params_Data() = delete;
        };
        static_assert(sizeof(GamepadObserver_GamepadConnected_Params_Data) == 24,
            "Bad sizeof(GamepadObserver_GamepadConnected_Params_Data)");
        constexpr uint32_t kGamepadObserver_GamepadDisconnected_Name = 1;
        class GamepadObserver_GamepadDisconnected_Params_Data {
        public:
            static GamepadObserver_GamepadDisconnected_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GamepadObserver_GamepadDisconnected_Params_Data))) GamepadObserver_GamepadDisconnected_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t index;
            uint8_t pad0_[4];
            mojo::internal::Pointer<internal::Gamepad_Data> gamepad;

        private:
            GamepadObserver_GamepadDisconnected_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GamepadObserver_GamepadDisconnected_Params_Data() = delete;
        };
        static_assert(sizeof(GamepadObserver_GamepadDisconnected_Params_Data) == 24,
            "Bad sizeof(GamepadObserver_GamepadDisconnected_Params_Data)");
        constexpr uint32_t kGamepadMonitor_GamepadStartPolling_Name = 0;
        class GamepadMonitor_GamepadStartPolling_Params_Data {
        public:
            static GamepadMonitor_GamepadStartPolling_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GamepadMonitor_GamepadStartPolling_Params_Data))) GamepadMonitor_GamepadStartPolling_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            GamepadMonitor_GamepadStartPolling_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GamepadMonitor_GamepadStartPolling_Params_Data() = delete;
        };
        static_assert(sizeof(GamepadMonitor_GamepadStartPolling_Params_Data) == 8,
            "Bad sizeof(GamepadMonitor_GamepadStartPolling_Params_Data)");
        class GamepadMonitor_GamepadStartPolling_ResponseParams_Data {
        public:
            static GamepadMonitor_GamepadStartPolling_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GamepadMonitor_GamepadStartPolling_ResponseParams_Data))) GamepadMonitor_GamepadStartPolling_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data memory_handle;
            uint8_t padfinal_[4];

        private:
            GamepadMonitor_GamepadStartPolling_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GamepadMonitor_GamepadStartPolling_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(GamepadMonitor_GamepadStartPolling_ResponseParams_Data) == 16,
            "Bad sizeof(GamepadMonitor_GamepadStartPolling_ResponseParams_Data)");
        constexpr uint32_t kGamepadMonitor_GamepadStopPolling_Name = 1;
        class GamepadMonitor_GamepadStopPolling_Params_Data {
        public:
            static GamepadMonitor_GamepadStopPolling_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GamepadMonitor_GamepadStopPolling_Params_Data))) GamepadMonitor_GamepadStopPolling_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            GamepadMonitor_GamepadStopPolling_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GamepadMonitor_GamepadStopPolling_Params_Data() = delete;
        };
        static_assert(sizeof(GamepadMonitor_GamepadStopPolling_Params_Data) == 8,
            "Bad sizeof(GamepadMonitor_GamepadStopPolling_Params_Data)");
        class GamepadMonitor_GamepadStopPolling_ResponseParams_Data {
        public:
            static GamepadMonitor_GamepadStopPolling_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GamepadMonitor_GamepadStopPolling_ResponseParams_Data))) GamepadMonitor_GamepadStopPolling_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            GamepadMonitor_GamepadStopPolling_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GamepadMonitor_GamepadStopPolling_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(GamepadMonitor_GamepadStopPolling_ResponseParams_Data) == 8,
            "Bad sizeof(GamepadMonitor_GamepadStopPolling_ResponseParams_Data)");
        constexpr uint32_t kGamepadMonitor_SetObserver_Name = 2;
        class GamepadMonitor_SetObserver_Params_Data {
        public:
            static GamepadMonitor_SetObserver_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GamepadMonitor_SetObserver_Params_Data))) GamepadMonitor_SetObserver_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data gamepad_observer;

        private:
            GamepadMonitor_SetObserver_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GamepadMonitor_SetObserver_Params_Data() = delete;
        };
        static_assert(sizeof(GamepadMonitor_SetObserver_Params_Data) == 16,
            "Bad sizeof(GamepadMonitor_SetObserver_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace device

#endif // DEVICE_GAMEPAD_PUBLIC_INTERFACES_GAMEPAD_MOJOM_SHARED_INTERNAL_H_