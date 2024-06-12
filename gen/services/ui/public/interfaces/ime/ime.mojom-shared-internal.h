// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_IME_IME_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_PUBLIC_INTERFACES_IME_IME_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/common/text_direction.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/events/mojo/event.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"
#include "ui/gfx/range/mojo/range.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace ui {
namespace mojom {
    namespace internal {
        class CompositionUnderline_Data;
        class CompositionText_Data;
        class StartSessionDetails_Data;

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
                case 15:
                case 16:
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

        struct TextInputMode_Data {
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
        class CompositionUnderline_Data {
        public:
            static CompositionUnderline_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CompositionUnderline_Data))) CompositionUnderline_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t start_offset;
            uint32_t end_offset;
            uint8_t thick : 1;
            uint8_t pad2_[3];
            uint32_t color;
            uint32_t background_color;
            uint8_t padfinal_[4];

        private:
            CompositionUnderline_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CompositionUnderline_Data() = delete;
        };
        static_assert(sizeof(CompositionUnderline_Data) == 32,
            "Bad sizeof(CompositionUnderline_Data)");
        class CompositionText_Data {
        public:
            static CompositionText_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CompositionText_Data))) CompositionText_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> text;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::CompositionUnderline_Data>>> underlines;
            mojo::internal::Pointer<::gfx::mojom::internal::Range_Data> selection;

        private:
            CompositionText_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CompositionText_Data() = delete;
        };
        static_assert(sizeof(CompositionText_Data) == 32,
            "Bad sizeof(CompositionText_Data)");
        class StartSessionDetails_Data {
        public:
            static StartSessionDetails_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(StartSessionDetails_Data))) StartSessionDetails_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data client;
            mojo::internal::Handle_Data input_method_request;
            int32_t text_input_type;
            int32_t text_input_mode;
            int32_t text_direction;
            int32_t text_input_flags;
            uint8_t pad5_[4];
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> caret_bounds;

        private:
            StartSessionDetails_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~StartSessionDetails_Data() = delete;
        };
        static_assert(sizeof(StartSessionDetails_Data) == 48,
            "Bad sizeof(StartSessionDetails_Data)");
        constexpr uint32_t kIMEDriver_StartSession_Name = 0;
        class IMEDriver_StartSession_Params_Data {
        public:
            static IMEDriver_StartSession_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(IMEDriver_StartSession_Params_Data))) IMEDriver_StartSession_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t session_id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<internal::StartSessionDetails_Data> details;

        private:
            IMEDriver_StartSession_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~IMEDriver_StartSession_Params_Data() = delete;
        };
        static_assert(sizeof(IMEDriver_StartSession_Params_Data) == 24,
            "Bad sizeof(IMEDriver_StartSession_Params_Data)");
        constexpr uint32_t kIMEDriver_CancelSession_Name = 1;
        class IMEDriver_CancelSession_Params_Data {
        public:
            static IMEDriver_CancelSession_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(IMEDriver_CancelSession_Params_Data))) IMEDriver_CancelSession_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t session_id;
            uint8_t padfinal_[4];

        private:
            IMEDriver_CancelSession_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~IMEDriver_CancelSession_Params_Data() = delete;
        };
        static_assert(sizeof(IMEDriver_CancelSession_Params_Data) == 16,
            "Bad sizeof(IMEDriver_CancelSession_Params_Data)");
        constexpr uint32_t kIMEServer_StartSession_Name = 0;
        class IMEServer_StartSession_Params_Data {
        public:
            static IMEServer_StartSession_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(IMEServer_StartSession_Params_Data))) IMEServer_StartSession_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::StartSessionDetails_Data> details;

        private:
            IMEServer_StartSession_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~IMEServer_StartSession_Params_Data() = delete;
        };
        static_assert(sizeof(IMEServer_StartSession_Params_Data) == 16,
            "Bad sizeof(IMEServer_StartSession_Params_Data)");
        constexpr uint32_t kIMERegistrar_RegisterDriver_Name = 0;
        class IMERegistrar_RegisterDriver_Params_Data {
        public:
            static IMERegistrar_RegisterDriver_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(IMERegistrar_RegisterDriver_Params_Data))) IMERegistrar_RegisterDriver_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data driver;

        private:
            IMERegistrar_RegisterDriver_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~IMERegistrar_RegisterDriver_Params_Data() = delete;
        };
        static_assert(sizeof(IMERegistrar_RegisterDriver_Params_Data) == 16,
            "Bad sizeof(IMERegistrar_RegisterDriver_Params_Data)");
        constexpr uint32_t kInputMethod_OnTextInputTypeChanged_Name = 0;
        class InputMethod_OnTextInputTypeChanged_Params_Data {
        public:
            static InputMethod_OnTextInputTypeChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(InputMethod_OnTextInputTypeChanged_Params_Data))) InputMethod_OnTextInputTypeChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t text_input_type;
            uint8_t padfinal_[4];

        private:
            InputMethod_OnTextInputTypeChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~InputMethod_OnTextInputTypeChanged_Params_Data() = delete;
        };
        static_assert(sizeof(InputMethod_OnTextInputTypeChanged_Params_Data) == 16,
            "Bad sizeof(InputMethod_OnTextInputTypeChanged_Params_Data)");
        constexpr uint32_t kInputMethod_OnCaretBoundsChanged_Name = 1;
        class InputMethod_OnCaretBoundsChanged_Params_Data {
        public:
            static InputMethod_OnCaretBoundsChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(InputMethod_OnCaretBoundsChanged_Params_Data))) InputMethod_OnCaretBoundsChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> caret_bounds;

        private:
            InputMethod_OnCaretBoundsChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~InputMethod_OnCaretBoundsChanged_Params_Data() = delete;
        };
        static_assert(sizeof(InputMethod_OnCaretBoundsChanged_Params_Data) == 16,
            "Bad sizeof(InputMethod_OnCaretBoundsChanged_Params_Data)");
        constexpr uint32_t kInputMethod_ProcessKeyEvent_Name = 2;
        class InputMethod_ProcessKeyEvent_Params_Data {
        public:
            static InputMethod_ProcessKeyEvent_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(InputMethod_ProcessKeyEvent_Params_Data))) InputMethod_ProcessKeyEvent_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::ui::mojom::internal::Event_Data> key_event;

        private:
            InputMethod_ProcessKeyEvent_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~InputMethod_ProcessKeyEvent_Params_Data() = delete;
        };
        static_assert(sizeof(InputMethod_ProcessKeyEvent_Params_Data) == 16,
            "Bad sizeof(InputMethod_ProcessKeyEvent_Params_Data)");
        class InputMethod_ProcessKeyEvent_ResponseParams_Data {
        public:
            static InputMethod_ProcessKeyEvent_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(InputMethod_ProcessKeyEvent_ResponseParams_Data))) InputMethod_ProcessKeyEvent_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t handled : 1;
            uint8_t padfinal_[7];

        private:
            InputMethod_ProcessKeyEvent_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~InputMethod_ProcessKeyEvent_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(InputMethod_ProcessKeyEvent_ResponseParams_Data) == 16,
            "Bad sizeof(InputMethod_ProcessKeyEvent_ResponseParams_Data)");
        constexpr uint32_t kInputMethod_CancelComposition_Name = 3;
        class InputMethod_CancelComposition_Params_Data {
        public:
            static InputMethod_CancelComposition_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(InputMethod_CancelComposition_Params_Data))) InputMethod_CancelComposition_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            InputMethod_CancelComposition_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~InputMethod_CancelComposition_Params_Data() = delete;
        };
        static_assert(sizeof(InputMethod_CancelComposition_Params_Data) == 8,
            "Bad sizeof(InputMethod_CancelComposition_Params_Data)");
        constexpr uint32_t kTextInputClient_SetCompositionText_Name = 0;
        class TextInputClient_SetCompositionText_Params_Data {
        public:
            static TextInputClient_SetCompositionText_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(TextInputClient_SetCompositionText_Params_Data))) TextInputClient_SetCompositionText_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::CompositionText_Data> composition;

        private:
            TextInputClient_SetCompositionText_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~TextInputClient_SetCompositionText_Params_Data() = delete;
        };
        static_assert(sizeof(TextInputClient_SetCompositionText_Params_Data) == 16,
            "Bad sizeof(TextInputClient_SetCompositionText_Params_Data)");
        constexpr uint32_t kTextInputClient_ConfirmCompositionText_Name = 1;
        class TextInputClient_ConfirmCompositionText_Params_Data {
        public:
            static TextInputClient_ConfirmCompositionText_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(TextInputClient_ConfirmCompositionText_Params_Data))) TextInputClient_ConfirmCompositionText_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            TextInputClient_ConfirmCompositionText_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~TextInputClient_ConfirmCompositionText_Params_Data() = delete;
        };
        static_assert(sizeof(TextInputClient_ConfirmCompositionText_Params_Data) == 8,
            "Bad sizeof(TextInputClient_ConfirmCompositionText_Params_Data)");
        constexpr uint32_t kTextInputClient_ClearCompositionText_Name = 2;
        class TextInputClient_ClearCompositionText_Params_Data {
        public:
            static TextInputClient_ClearCompositionText_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(TextInputClient_ClearCompositionText_Params_Data))) TextInputClient_ClearCompositionText_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            TextInputClient_ClearCompositionText_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~TextInputClient_ClearCompositionText_Params_Data() = delete;
        };
        static_assert(sizeof(TextInputClient_ClearCompositionText_Params_Data) == 8,
            "Bad sizeof(TextInputClient_ClearCompositionText_Params_Data)");
        constexpr uint32_t kTextInputClient_InsertText_Name = 3;
        class TextInputClient_InsertText_Params_Data {
        public:
            static TextInputClient_InsertText_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(TextInputClient_InsertText_Params_Data))) TextInputClient_InsertText_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> text;

        private:
            TextInputClient_InsertText_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~TextInputClient_InsertText_Params_Data() = delete;
        };
        static_assert(sizeof(TextInputClient_InsertText_Params_Data) == 16,
            "Bad sizeof(TextInputClient_InsertText_Params_Data)");
        constexpr uint32_t kTextInputClient_InsertChar_Name = 4;
        class TextInputClient_InsertChar_Params_Data {
        public:
            static TextInputClient_InsertChar_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(TextInputClient_InsertChar_Params_Data))) TextInputClient_InsertChar_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::ui::mojom::internal::Event_Data> event;

        private:
            TextInputClient_InsertChar_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~TextInputClient_InsertChar_Params_Data() = delete;
        };
        static_assert(sizeof(TextInputClient_InsertChar_Params_Data) == 16,
            "Bad sizeof(TextInputClient_InsertChar_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_IME_IME_MOJOM_SHARED_INTERNAL_H_