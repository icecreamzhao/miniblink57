// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_EVENTS_MOJO_EVENT_MOJOM_SHARED_INTERNAL_H_
#define UI_EVENTS_MOJO_EVENT_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/events/mojo/event_constants.mojom-shared-internal.h"
#include "ui/events/mojo/keyboard_codes.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace ui {
namespace mojom {
    namespace internal {
        class KeyData_Data;
        class LocationData_Data;
        class PointerData_Data;
        class WheelData_Data;
        class BrushData_Data;
        class Event_Data;

#pragma pack(push, 1)
        class KeyData_Data {
        public:
            static KeyData_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(KeyData_Data))) KeyData_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t key_code;
            uint8_t is_char : 1;
            uint8_t pad1_[1];
            uint16_t character;
            int32_t windows_key_code;
            int32_t native_key_code;
            uint16_t text;
            uint16_t unmodified_text;
            uint8_t padfinal_[4];

        private:
            KeyData_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~KeyData_Data() = delete;
        };
        static_assert(sizeof(KeyData_Data) == 32,
            "Bad sizeof(KeyData_Data)");
        class LocationData_Data {
        public:
            static LocationData_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LocationData_Data))) LocationData_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            float x;
            float y;
            float screen_x;
            float screen_y;

        private:
            LocationData_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LocationData_Data() = delete;
        };
        static_assert(sizeof(LocationData_Data) == 24,
            "Bad sizeof(LocationData_Data)");
        class PointerData_Data {
        public:
            static PointerData_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PointerData_Data))) PointerData_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t pointer_id;
            int32_t changed_button_flags;
            int32_t kind;
            uint8_t pad2_[4];
            mojo::internal::Pointer<internal::LocationData_Data> location;
            mojo::internal::Pointer<internal::BrushData_Data> brush_data;
            mojo::internal::Pointer<internal::WheelData_Data> wheel_data;

        private:
            PointerData_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PointerData_Data() = delete;
        };
        static_assert(sizeof(PointerData_Data) == 48,
            "Bad sizeof(PointerData_Data)");
        class WheelData_Data {
        public:
            static WheelData_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WheelData_Data))) WheelData_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t mode;
            float delta_x;
            float delta_y;
            float delta_z;

        private:
            WheelData_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WheelData_Data() = delete;
        };
        static_assert(sizeof(WheelData_Data) == 24,
            "Bad sizeof(WheelData_Data)");
        class BrushData_Data {
        public:
            static BrushData_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BrushData_Data))) BrushData_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            float width;
            float height;
            float pressure;
            float tilt_x;
            float tilt_y;
            uint8_t padfinal_[4];

        private:
            BrushData_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BrushData_Data() = delete;
        };
        static_assert(sizeof(BrushData_Data) == 32,
            "Bad sizeof(BrushData_Data)");
        class Event_Data {
        public:
            static Event_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Event_Data))) Event_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t action;
            int32_t flags;
            int64_t time_stamp;
            mojo::internal::Pointer<internal::KeyData_Data> key_data;
            mojo::internal::Pointer<internal::PointerData_Data> pointer_data;

        private:
            Event_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Event_Data() = delete;
        };
        static_assert(sizeof(Event_Data) == 40,
            "Bad sizeof(Event_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // UI_EVENTS_MOJO_EVENT_MOJOM_SHARED_INTERNAL_H_