// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_WEB_WINDOW_FEATURES_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_WEB_WINDOW_FEATURES_MOJOM_SHARED_INTERNAL_H_

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
        class WindowFeatures_Data;

#pragma pack(push, 1)
        class WindowFeatures_Data {
        public:
            static WindowFeatures_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowFeatures_Data))) WindowFeatures_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            float x;
            uint8_t has_x : 1;
            uint8_t has_y : 1;
            uint8_t has_width : 1;
            uint8_t has_height : 1;
            uint8_t menu_bar_visible : 1;
            uint8_t status_bar_visible : 1;
            uint8_t tool_bar_visible : 1;
            uint8_t location_bar_visible : 1;
            uint8_t scrollbars_visible : 1;
            uint8_t resizable : 1;
            uint8_t fullscreen : 1;
            uint8_t dialog : 1;
            uint8_t pad12_[2];
            float y;
            float width;
            float height;
            uint8_t padfinal_[4];

        private:
            WindowFeatures_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowFeatures_Data() = delete;
        };
        static_assert(sizeof(WindowFeatures_Data) == 32,
            "Bad sizeof(WindowFeatures_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_WEB_WINDOW_FEATURES_MOJOM_SHARED_INTERNAL_H_