// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_EVENT_MATCHER_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_PUBLIC_INTERFACES_EVENT_MATCHER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/events/mojo/event_constants.mojom-shared-internal.h"
#include "ui/events/mojo/keyboard_codes.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace ui {
namespace mojom {
    namespace internal {
        class KeyEventMatcher_Data;
        class PointerKindMatcher_Data;
        class PointerLocationMatcher_Data;
        class EventTypeMatcher_Data;
        class EventFlagsMatcher_Data;
        class EventMatcher_Data;

#pragma pack(push, 1)
        class KeyEventMatcher_Data {
        public:
            static KeyEventMatcher_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(KeyEventMatcher_Data))) KeyEventMatcher_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t keyboard_code;
            uint8_t padfinal_[4];

        private:
            KeyEventMatcher_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~KeyEventMatcher_Data() = delete;
        };
        static_assert(sizeof(KeyEventMatcher_Data) == 16,
            "Bad sizeof(KeyEventMatcher_Data)");
        class PointerKindMatcher_Data {
        public:
            static PointerKindMatcher_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PointerKindMatcher_Data))) PointerKindMatcher_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t pointer_kind;
            uint8_t padfinal_[4];

        private:
            PointerKindMatcher_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PointerKindMatcher_Data() = delete;
        };
        static_assert(sizeof(PointerKindMatcher_Data) == 16,
            "Bad sizeof(PointerKindMatcher_Data)");
        class PointerLocationMatcher_Data {
        public:
            static PointerLocationMatcher_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PointerLocationMatcher_Data))) PointerLocationMatcher_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::RectF_Data> region;

        private:
            PointerLocationMatcher_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PointerLocationMatcher_Data() = delete;
        };
        static_assert(sizeof(PointerLocationMatcher_Data) == 16,
            "Bad sizeof(PointerLocationMatcher_Data)");
        class EventTypeMatcher_Data {
        public:
            static EventTypeMatcher_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(EventTypeMatcher_Data))) EventTypeMatcher_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t type;
            uint8_t padfinal_[4];

        private:
            EventTypeMatcher_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~EventTypeMatcher_Data() = delete;
        };
        static_assert(sizeof(EventTypeMatcher_Data) == 16,
            "Bad sizeof(EventTypeMatcher_Data)");
        class EventFlagsMatcher_Data {
        public:
            static EventFlagsMatcher_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(EventFlagsMatcher_Data))) EventFlagsMatcher_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t flags;
            uint8_t padfinal_[4];

        private:
            EventFlagsMatcher_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~EventFlagsMatcher_Data() = delete;
        };
        static_assert(sizeof(EventFlagsMatcher_Data) == 16,
            "Bad sizeof(EventFlagsMatcher_Data)");
        class EventMatcher_Data {
        public:
            static EventMatcher_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(EventMatcher_Data))) EventMatcher_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t accelerator_phase;
            uint8_t pad0_[4];
            mojo::internal::Pointer<internal::EventTypeMatcher_Data> type_matcher;
            mojo::internal::Pointer<internal::EventFlagsMatcher_Data> flags_matcher;
            mojo::internal::Pointer<internal::EventFlagsMatcher_Data> ignore_flags_matcher;
            mojo::internal::Pointer<internal::KeyEventMatcher_Data> key_matcher;
            mojo::internal::Pointer<internal::PointerKindMatcher_Data> pointer_kind_matcher;
            mojo::internal::Pointer<internal::PointerLocationMatcher_Data> pointer_location_matcher;

        private:
            EventMatcher_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~EventMatcher_Data() = delete;
        };
        static_assert(sizeof(EventMatcher_Data) == 64,
            "Bad sizeof(EventMatcher_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_EVENT_MATCHER_MOJOM_SHARED_INTERNAL_H_