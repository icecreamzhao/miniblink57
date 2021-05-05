// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_WINDOW_SERVER_TEST_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_PUBLIC_INTERFACES_WINDOW_SERVER_TEST_MOJOM_SHARED_INTERNAL_H_

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

#pragma pack(push, 1)
        constexpr uint32_t kWindowServerTest_EnsureClientHasDrawnWindow_Name = 0;
        class WindowServerTest_EnsureClientHasDrawnWindow_Params_Data {
        public:
            static WindowServerTest_EnsureClientHasDrawnWindow_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowServerTest_EnsureClientHasDrawnWindow_Params_Data))) WindowServerTest_EnsureClientHasDrawnWindow_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> client_name;

        private:
            WindowServerTest_EnsureClientHasDrawnWindow_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowServerTest_EnsureClientHasDrawnWindow_Params_Data() = delete;
        };
        static_assert(sizeof(WindowServerTest_EnsureClientHasDrawnWindow_Params_Data) == 16,
            "Bad sizeof(WindowServerTest_EnsureClientHasDrawnWindow_Params_Data)");
        class WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams_Data {
        public:
            static WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams_Data))) WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams_Data) == 16,
            "Bad sizeof(WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_WINDOW_SERVER_TEST_MOJOM_SHARED_INTERNAL_H_