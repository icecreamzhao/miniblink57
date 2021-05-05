// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_IME_IME_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_IME_IME_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/common/text_direction.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/ui/public/interfaces/ime/ime.mojom-shared-internal.h"
#include "ui/events/mojo/event.mojom-shared.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"
#include "ui/gfx/range/mojo/range.mojom-shared.h"

namespace ui {
namespace mojom {
    class CompositionUnderlineDataView;

    class CompositionTextDataView;

    class StartSessionDetailsDataView;

} // namespace mojom
} // namespace ui

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::ui::mojom::CompositionUnderlineDataView> {
        using Data = ::ui::mojom::internal::CompositionUnderline_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::ui::mojom::CompositionTextDataView> {
        using Data = ::ui::mojom::internal::CompositionText_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::ui::mojom::StartSessionDetailsDataView> {
        using Data = ::ui::mojom::internal::StartSessionDetails_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace ui {
namespace mojom {

    enum class TextInputType : int32_t {
        NONE,
        TEXT,
        PASSWORD,
        SEARCH,
        EMAIL,
        NUMBER,
        TELEPHONE,
        URL,
        DATE,
        TIME,
        DATETIME,
        DATETIME_LOCAL,
        MONTH,
        WEEK,
        TEXT_AREA,
        CONTENT_EDITABLE,
        DATETIME_FIELD,
    };

    inline std::ostream& operator<<(std::ostream& os, TextInputType value)
    {
        switch (value) {
        case TextInputType::NONE:
            return os << "TextInputType::NONE";
        case TextInputType::TEXT:
            return os << "TextInputType::TEXT";
        case TextInputType::PASSWORD:
            return os << "TextInputType::PASSWORD";
        case TextInputType::SEARCH:
            return os << "TextInputType::SEARCH";
        case TextInputType::EMAIL:
            return os << "TextInputType::EMAIL";
        case TextInputType::NUMBER:
            return os << "TextInputType::NUMBER";
        case TextInputType::TELEPHONE:
            return os << "TextInputType::TELEPHONE";
        case TextInputType::URL:
            return os << "TextInputType::URL";
        case TextInputType::DATE:
            return os << "TextInputType::DATE";
        case TextInputType::TIME:
            return os << "TextInputType::TIME";
        case TextInputType::DATETIME:
            return os << "TextInputType::DATETIME";
        case TextInputType::DATETIME_LOCAL:
            return os << "TextInputType::DATETIME_LOCAL";
        case TextInputType::MONTH:
            return os << "TextInputType::MONTH";
        case TextInputType::WEEK:
            return os << "TextInputType::WEEK";
        case TextInputType::TEXT_AREA:
            return os << "TextInputType::TEXT_AREA";
        case TextInputType::CONTENT_EDITABLE:
            return os << "TextInputType::CONTENT_EDITABLE";
        case TextInputType::DATETIME_FIELD:
            return os << "TextInputType::DATETIME_FIELD";
        default:
            return os << "Unknown TextInputType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(TextInputType value)
    {
        return internal::TextInputType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class TextInputMode : int32_t {
        DEFAULT,
        VERBATIM,
        LATIN,
        LATIN_NAME,
        LATIN_PROSE,
        FULL_WIDTH_LATIN,
        KANA,
        KANA_NAME,
        KATAKANA,
        NUMERIC,
        TEL,
        EMAIL,
        URL,
    };

    inline std::ostream& operator<<(std::ostream& os, TextInputMode value)
    {
        switch (value) {
        case TextInputMode::DEFAULT:
            return os << "TextInputMode::DEFAULT";
        case TextInputMode::VERBATIM:
            return os << "TextInputMode::VERBATIM";
        case TextInputMode::LATIN:
            return os << "TextInputMode::LATIN";
        case TextInputMode::LATIN_NAME:
            return os << "TextInputMode::LATIN_NAME";
        case TextInputMode::LATIN_PROSE:
            return os << "TextInputMode::LATIN_PROSE";
        case TextInputMode::FULL_WIDTH_LATIN:
            return os << "TextInputMode::FULL_WIDTH_LATIN";
        case TextInputMode::KANA:
            return os << "TextInputMode::KANA";
        case TextInputMode::KANA_NAME:
            return os << "TextInputMode::KANA_NAME";
        case TextInputMode::KATAKANA:
            return os << "TextInputMode::KATAKANA";
        case TextInputMode::NUMERIC:
            return os << "TextInputMode::NUMERIC";
        case TextInputMode::TEL:
            return os << "TextInputMode::TEL";
        case TextInputMode::EMAIL:
            return os << "TextInputMode::EMAIL";
        case TextInputMode::URL:
            return os << "TextInputMode::URL";
        default:
            return os << "Unknown TextInputMode value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(TextInputMode value)
    {
        return internal::TextInputMode_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class IMEDriverInterfaceBase {
    };

    using IMEDriverPtrDataView = mojo::InterfacePtrDataView<IMEDriverInterfaceBase>;
    using IMEDriverRequestDataView = mojo::InterfaceRequestDataView<IMEDriverInterfaceBase>;
    using IMEDriverAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<IMEDriverInterfaceBase>;
    using IMEDriverAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<IMEDriverInterfaceBase>;
    class IMEServerInterfaceBase {
    };

    using IMEServerPtrDataView = mojo::InterfacePtrDataView<IMEServerInterfaceBase>;
    using IMEServerRequestDataView = mojo::InterfaceRequestDataView<IMEServerInterfaceBase>;
    using IMEServerAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<IMEServerInterfaceBase>;
    using IMEServerAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<IMEServerInterfaceBase>;
    class IMERegistrarInterfaceBase {
    };

    using IMERegistrarPtrDataView = mojo::InterfacePtrDataView<IMERegistrarInterfaceBase>;
    using IMERegistrarRequestDataView = mojo::InterfaceRequestDataView<IMERegistrarInterfaceBase>;
    using IMERegistrarAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<IMERegistrarInterfaceBase>;
    using IMERegistrarAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<IMERegistrarInterfaceBase>;
    class InputMethodInterfaceBase {
    };

    using InputMethodPtrDataView = mojo::InterfacePtrDataView<InputMethodInterfaceBase>;
    using InputMethodRequestDataView = mojo::InterfaceRequestDataView<InputMethodInterfaceBase>;
    using InputMethodAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<InputMethodInterfaceBase>;
    using InputMethodAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<InputMethodInterfaceBase>;
    class TextInputClientInterfaceBase {
    };

    using TextInputClientPtrDataView = mojo::InterfacePtrDataView<TextInputClientInterfaceBase>;
    using TextInputClientRequestDataView = mojo::InterfaceRequestDataView<TextInputClientInterfaceBase>;
    using TextInputClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<TextInputClientInterfaceBase>;
    using TextInputClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<TextInputClientInterfaceBase>;
    class CompositionUnderlineDataView {
    public:
        CompositionUnderlineDataView() { }

        CompositionUnderlineDataView(
            internal::CompositionUnderline_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t start_offset() const
        {
            return data_->start_offset;
        }
        uint32_t end_offset() const
        {
            return data_->end_offset;
        }
        bool thick() const
        {
            return data_->thick;
        }
        uint32_t color() const
        {
            return data_->color;
        }
        uint32_t background_color() const
        {
            return data_->background_color;
        }

    private:
        internal::CompositionUnderline_Data* data_ = nullptr;
    };

    class CompositionTextDataView {
    public:
        CompositionTextDataView() { }

        CompositionTextDataView(
            internal::CompositionText_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTextDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadText(UserType* output)
        {
            auto* pointer = data_->text.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetUnderlinesDataView(
            mojo::ArrayDataView<CompositionUnderlineDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUnderlines(UserType* output)
        {
            auto* pointer = data_->underlines.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::ui::mojom::CompositionUnderlineDataView>>(
                pointer, output, context_);
        }
        inline void GetSelectionDataView(
            ::gfx::mojom::RangeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSelection(UserType* output)
        {
            auto* pointer = data_->selection.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RangeDataView>(
                pointer, output, context_);
        }

    private:
        internal::CompositionText_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class StartSessionDetailsDataView {
    public:
        StartSessionDetailsDataView() { }

        StartSessionDetailsDataView(
            internal::StartSessionDetails_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::TextInputClientPtrDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeInputMethodRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::InputMethodRequestDataView>(
                &data_->input_method_request, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTextInputType(UserType* output) const
        {
            auto data_value = data_->text_input_type;
            return mojo::internal::Deserialize<::ui::mojom::TextInputType>(
                data_value, output);
        }

        TextInputType text_input_type() const
        {
            return static_cast<TextInputType>(data_->text_input_type);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTextInputMode(UserType* output) const
        {
            auto data_value = data_->text_input_mode;
            return mojo::internal::Deserialize<::ui::mojom::TextInputMode>(
                data_value, output);
        }

        TextInputMode text_input_mode() const
        {
            return static_cast<TextInputMode>(data_->text_input_mode);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTextDirection(UserType* output) const
        {
            auto data_value = data_->text_direction;
            return mojo::internal::Deserialize<::mojo::common::mojom::TextDirection>(
                data_value, output);
        }

        ::mojo::common::mojom::TextDirection text_direction() const
        {
            return static_cast<::mojo::common::mojom::TextDirection>(data_->text_direction);
        }
        int32_t text_input_flags() const
        {
            return data_->text_input_flags;
        }
        inline void GetCaretBoundsDataView(
            ::gfx::mojom::RectDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCaretBounds(UserType* output)
        {
            auto* pointer = data_->caret_bounds.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectDataView>(
                pointer, output, context_);
        }

    private:
        internal::StartSessionDetails_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class IMEDriver_StartSession_ParamsDataView {
    public:
        IMEDriver_StartSession_ParamsDataView() { }

        IMEDriver_StartSession_ParamsDataView(
            internal::IMEDriver_StartSession_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t session_id() const
        {
            return data_->session_id;
        }
        inline void GetDetailsDataView(
            StartSessionDetailsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDetails(UserType* output)
        {
            auto* pointer = data_->details.Get();
            return mojo::internal::Deserialize<::ui::mojom::StartSessionDetailsDataView>(
                pointer, output, context_);
        }

    private:
        internal::IMEDriver_StartSession_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class IMEDriver_CancelSession_ParamsDataView {
    public:
        IMEDriver_CancelSession_ParamsDataView() { }

        IMEDriver_CancelSession_ParamsDataView(
            internal::IMEDriver_CancelSession_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t session_id() const
        {
            return data_->session_id;
        }

    private:
        internal::IMEDriver_CancelSession_Params_Data* data_ = nullptr;
    };

    class IMEServer_StartSession_ParamsDataView {
    public:
        IMEServer_StartSession_ParamsDataView() { }

        IMEServer_StartSession_ParamsDataView(
            internal::IMEServer_StartSession_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDetailsDataView(
            StartSessionDetailsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDetails(UserType* output)
        {
            auto* pointer = data_->details.Get();
            return mojo::internal::Deserialize<::ui::mojom::StartSessionDetailsDataView>(
                pointer, output, context_);
        }

    private:
        internal::IMEServer_StartSession_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class IMERegistrar_RegisterDriver_ParamsDataView {
    public:
        IMERegistrar_RegisterDriver_ParamsDataView() { }

        IMERegistrar_RegisterDriver_ParamsDataView(
            internal::IMERegistrar_RegisterDriver_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeDriver()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::IMEDriverPtrDataView>(
                &data_->driver, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::IMERegistrar_RegisterDriver_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class InputMethod_OnTextInputTypeChanged_ParamsDataView {
    public:
        InputMethod_OnTextInputTypeChanged_ParamsDataView() { }

        InputMethod_OnTextInputTypeChanged_ParamsDataView(
            internal::InputMethod_OnTextInputTypeChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTextInputType(UserType* output) const
        {
            auto data_value = data_->text_input_type;
            return mojo::internal::Deserialize<::ui::mojom::TextInputType>(
                data_value, output);
        }

        TextInputType text_input_type() const
        {
            return static_cast<TextInputType>(data_->text_input_type);
        }

    private:
        internal::InputMethod_OnTextInputTypeChanged_Params_Data* data_ = nullptr;
    };

    class InputMethod_OnCaretBoundsChanged_ParamsDataView {
    public:
        InputMethod_OnCaretBoundsChanged_ParamsDataView() { }

        InputMethod_OnCaretBoundsChanged_ParamsDataView(
            internal::InputMethod_OnCaretBoundsChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetCaretBoundsDataView(
            ::gfx::mojom::RectDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCaretBounds(UserType* output)
        {
            auto* pointer = data_->caret_bounds.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectDataView>(
                pointer, output, context_);
        }

    private:
        internal::InputMethod_OnCaretBoundsChanged_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class InputMethod_ProcessKeyEvent_ParamsDataView {
    public:
        InputMethod_ProcessKeyEvent_ParamsDataView() { }

        InputMethod_ProcessKeyEvent_ParamsDataView(
            internal::InputMethod_ProcessKeyEvent_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyEventDataView(
            ::ui::mojom::EventDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKeyEvent(UserType* output)
        {
            auto* pointer = data_->key_event.Get();
            return mojo::internal::Deserialize<::ui::mojom::EventDataView>(
                pointer, output, context_);
        }

    private:
        internal::InputMethod_ProcessKeyEvent_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class InputMethod_ProcessKeyEvent_ResponseParamsDataView {
    public:
        InputMethod_ProcessKeyEvent_ResponseParamsDataView() { }

        InputMethod_ProcessKeyEvent_ResponseParamsDataView(
            internal::InputMethod_ProcessKeyEvent_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool handled() const
        {
            return data_->handled;
        }

    private:
        internal::InputMethod_ProcessKeyEvent_ResponseParams_Data* data_ = nullptr;
    };

    class InputMethod_CancelComposition_ParamsDataView {
    public:
        InputMethod_CancelComposition_ParamsDataView() { }

        InputMethod_CancelComposition_ParamsDataView(
            internal::InputMethod_CancelComposition_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::InputMethod_CancelComposition_Params_Data* data_ = nullptr;
    };

    class TextInputClient_SetCompositionText_ParamsDataView {
    public:
        TextInputClient_SetCompositionText_ParamsDataView() { }

        TextInputClient_SetCompositionText_ParamsDataView(
            internal::TextInputClient_SetCompositionText_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetCompositionDataView(
            CompositionTextDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadComposition(UserType* output)
        {
            auto* pointer = data_->composition.Get();
            return mojo::internal::Deserialize<::ui::mojom::CompositionTextDataView>(
                pointer, output, context_);
        }

    private:
        internal::TextInputClient_SetCompositionText_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class TextInputClient_ConfirmCompositionText_ParamsDataView {
    public:
        TextInputClient_ConfirmCompositionText_ParamsDataView() { }

        TextInputClient_ConfirmCompositionText_ParamsDataView(
            internal::TextInputClient_ConfirmCompositionText_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::TextInputClient_ConfirmCompositionText_Params_Data* data_ = nullptr;
    };

    class TextInputClient_ClearCompositionText_ParamsDataView {
    public:
        TextInputClient_ClearCompositionText_ParamsDataView() { }

        TextInputClient_ClearCompositionText_ParamsDataView(
            internal::TextInputClient_ClearCompositionText_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::TextInputClient_ClearCompositionText_Params_Data* data_ = nullptr;
    };

    class TextInputClient_InsertText_ParamsDataView {
    public:
        TextInputClient_InsertText_ParamsDataView() { }

        TextInputClient_InsertText_ParamsDataView(
            internal::TextInputClient_InsertText_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTextDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadText(UserType* output)
        {
            auto* pointer = data_->text.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::TextInputClient_InsertText_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class TextInputClient_InsertChar_ParamsDataView {
    public:
        TextInputClient_InsertChar_ParamsDataView() { }

        TextInputClient_InsertChar_ParamsDataView(
            internal::TextInputClient_InsertChar_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetEventDataView(
            ::ui::mojom::EventDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEvent(UserType* output)
        {
            auto* pointer = data_->event.Get();
            return mojo::internal::Deserialize<::ui::mojom::EventDataView>(
                pointer, output, context_);
        }

    private:
        internal::TextInputClient_InsertChar_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace ui

namespace std {

template <>
struct hash<::ui::mojom::TextInputType>
    : public mojo::internal::EnumHashImpl<::ui::mojom::TextInputType> {
};

template <>
struct hash<::ui::mojom::TextInputMode>
    : public mojo::internal::EnumHashImpl<::ui::mojom::TextInputMode> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::ui::mojom::TextInputType, ::ui::mojom::TextInputType> {
    static ::ui::mojom::TextInputType ToMojom(::ui::mojom::TextInputType input) { return input; }
    static bool FromMojom(::ui::mojom::TextInputType input, ::ui::mojom::TextInputType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::TextInputType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::ui::mojom::TextInputType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::ui::mojom::TextInputType>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::ui::mojom::TextInputMode, ::ui::mojom::TextInputMode> {
    static ::ui::mojom::TextInputMode ToMojom(::ui::mojom::TextInputMode input) { return input; }
    static bool FromMojom(::ui::mojom::TextInputMode input, ::ui::mojom::TextInputMode* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::TextInputMode, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::ui::mojom::TextInputMode, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::ui::mojom::TextInputMode>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::CompositionUnderlineDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::CompositionUnderlineDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::CompositionUnderline_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::CompositionUnderline_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::CompositionUnderline_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->start_offset = CallWithContext(Traits::start_offset, input, custom_context);
            result->end_offset = CallWithContext(Traits::end_offset, input, custom_context);
            result->thick = CallWithContext(Traits::thick, input, custom_context);
            result->color = CallWithContext(Traits::color, input, custom_context);
            result->background_color = CallWithContext(Traits::background_color, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::CompositionUnderline_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::CompositionUnderlineDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::CompositionTextDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::CompositionTextDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::CompositionText_Data);
            decltype(CallWithContext(Traits::text, input, custom_context)) in_text = CallWithContext(Traits::text, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_text, context);
            decltype(CallWithContext(Traits::underlines, input, custom_context)) in_underlines = CallWithContext(Traits::underlines, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::ui::mojom::CompositionUnderlineDataView>>(
                in_underlines, context);
            decltype(CallWithContext(Traits::selection, input, custom_context)) in_selection = CallWithContext(Traits::selection, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RangeDataView>(
                in_selection, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::CompositionText_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::CompositionText_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::text, input, custom_context)) in_text = CallWithContext(Traits::text, input, custom_context);
            typename decltype(result->text)::BaseType* text_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_text, buffer, &text_ptr, context);
            result->text.Set(text_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->text.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null text in CompositionText struct");
            decltype(CallWithContext(Traits::underlines, input, custom_context)) in_underlines = CallWithContext(Traits::underlines, input, custom_context);
            typename decltype(result->underlines)::BaseType* underlines_ptr;
            const mojo::internal::ContainerValidateParams underlines_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::ui::mojom::CompositionUnderlineDataView>>(
                in_underlines, buffer, &underlines_ptr, &underlines_validate_params,
                context);
            result->underlines.Set(underlines_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->underlines.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null underlines in CompositionText struct");
            decltype(CallWithContext(Traits::selection, input, custom_context)) in_selection = CallWithContext(Traits::selection, input, custom_context);
            typename decltype(result->selection)::BaseType* selection_ptr;
            mojo::internal::Serialize<::gfx::mojom::RangeDataView>(
                in_selection, buffer, &selection_ptr, context);
            result->selection.Set(selection_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->selection.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null selection in CompositionText struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::CompositionText_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::CompositionTextDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::StartSessionDetailsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::StartSessionDetailsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::StartSessionDetails_Data);
            decltype(CallWithContext(Traits::caret_bounds, input, custom_context)) in_caret_bounds = CallWithContext(Traits::caret_bounds, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
                in_caret_bounds, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::StartSessionDetails_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::StartSessionDetails_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::client, input, custom_context)) in_client = CallWithContext(Traits::client, input, custom_context);
            mojo::internal::Serialize<::ui::mojom::TextInputClientPtrDataView>(
                in_client, &result->client, context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(result->client),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid client in StartSessionDetails struct");
            decltype(CallWithContext(Traits::input_method_request, input, custom_context)) in_input_method_request = CallWithContext(Traits::input_method_request, input, custom_context);
            mojo::internal::Serialize<::ui::mojom::InputMethodRequestDataView>(
                in_input_method_request, &result->input_method_request, context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(result->input_method_request),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid input_method_request in StartSessionDetails struct");
            mojo::internal::Serialize<::ui::mojom::TextInputType>(
                CallWithContext(Traits::text_input_type, input, custom_context), &result->text_input_type);
            mojo::internal::Serialize<::ui::mojom::TextInputMode>(
                CallWithContext(Traits::text_input_mode, input, custom_context), &result->text_input_mode);
            mojo::internal::Serialize<::mojo::common::mojom::TextDirection>(
                CallWithContext(Traits::text_direction, input, custom_context), &result->text_direction);
            result->text_input_flags = CallWithContext(Traits::text_input_flags, input, custom_context);
            decltype(CallWithContext(Traits::caret_bounds, input, custom_context)) in_caret_bounds = CallWithContext(Traits::caret_bounds, input, custom_context);
            typename decltype(result->caret_bounds)::BaseType* caret_bounds_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectDataView>(
                in_caret_bounds, buffer, &caret_bounds_ptr, context);
            result->caret_bounds.Set(caret_bounds_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->caret_bounds.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null caret_bounds in StartSessionDetails struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::StartSessionDetails_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::StartSessionDetailsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace ui {
namespace mojom {

    inline void CompositionTextDataView::GetTextDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->text.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void CompositionTextDataView::GetUnderlinesDataView(
        mojo::ArrayDataView<CompositionUnderlineDataView>* output)
    {
        auto pointer = data_->underlines.Get();
        *output = mojo::ArrayDataView<CompositionUnderlineDataView>(pointer, context_);
    }
    inline void CompositionTextDataView::GetSelectionDataView(
        ::gfx::mojom::RangeDataView* output)
    {
        auto pointer = data_->selection.Get();
        *output = ::gfx::mojom::RangeDataView(pointer, context_);
    }

    inline void StartSessionDetailsDataView::GetCaretBoundsDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->caret_bounds.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }

    inline void IMEDriver_StartSession_ParamsDataView::GetDetailsDataView(
        StartSessionDetailsDataView* output)
    {
        auto pointer = data_->details.Get();
        *output = StartSessionDetailsDataView(pointer, context_);
    }

    inline void IMEServer_StartSession_ParamsDataView::GetDetailsDataView(
        StartSessionDetailsDataView* output)
    {
        auto pointer = data_->details.Get();
        *output = StartSessionDetailsDataView(pointer, context_);
    }

    inline void InputMethod_OnCaretBoundsChanged_ParamsDataView::GetCaretBoundsDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->caret_bounds.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }

    inline void InputMethod_ProcessKeyEvent_ParamsDataView::GetKeyEventDataView(
        ::ui::mojom::EventDataView* output)
    {
        auto pointer = data_->key_event.Get();
        *output = ::ui::mojom::EventDataView(pointer, context_);
    }

    inline void TextInputClient_SetCompositionText_ParamsDataView::GetCompositionDataView(
        CompositionTextDataView* output)
    {
        auto pointer = data_->composition.Get();
        *output = CompositionTextDataView(pointer, context_);
    }

    inline void TextInputClient_InsertText_ParamsDataView::GetTextDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->text.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void TextInputClient_InsertChar_ParamsDataView::GetEventDataView(
        ::ui::mojom::EventDataView* output)
    {
        auto pointer = data_->event.Get();
        *output = ::ui::mojom::EventDataView(pointer, context_);
    }

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_IME_IME_MOJOM_SHARED_H_
