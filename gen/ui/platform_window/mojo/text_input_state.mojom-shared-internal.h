// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_PLATFORM_WINDOW_MOJO_TEXT_INPUT_STATE_MOJOM_SHARED_INTERNAL_H_
#define UI_PLATFORM_WINDOW_MOJO_TEXT_INPUT_STATE_MOJOM_SHARED_INTERNAL_H_

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
namespace mojo {
namespace internal {
    class TextInputState_Data;

    struct TextInputType_Data {
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
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
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

    struct TextInputFlag_Data {
    public:
        static bool constexpr kIsExtensible = false;

        static bool IsKnownValue(int32_t value)
        {
            switch (value) {
            case 0:
            case 1:
            case 2:
            case 4:
            case 8:
            case 16:
            case 32:
            case 64:
            case 128:
            case 256:
            case 512:
            case 1023:
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
    class TextInputState_Data {
    public:
        static TextInputState_Data* New(mojo::internal::Buffer* buf)
        {
            return new (buf->Allocate(sizeof(TextInputState_Data))) TextInputState_Data();
        }

        static bool Validate(const void* data,
            mojo::internal::ValidationContext* validation_context);

        mojo::internal::StructHeader header_;
        int32_t type;
        int32_t flags;
        mojo::internal::Pointer<mojo::internal::String_Data> text;
        int32_t selection_start;
        int32_t selection_end;
        int32_t composition_start;
        int32_t composition_end;
        uint8_t can_compose_inline : 1;
        uint8_t padfinal_[7];

    private:
        TextInputState_Data()
            : header_({ sizeof(*this), 0 })
        {
        }
        ~TextInputState_Data() = delete;
    };
    static_assert(sizeof(TextInputState_Data) == 48,
        "Bad sizeof(TextInputState_Data)");

#pragma pack(pop)

} // namespace internal
} // namespace mojo

#endif // UI_PLATFORM_WINDOW_MOJO_TEXT_INPUT_STATE_MOJOM_SHARED_INTERNAL_H_