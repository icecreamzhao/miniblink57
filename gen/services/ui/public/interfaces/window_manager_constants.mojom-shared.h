// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_CONSTANTS_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_CONSTANTS_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/ui/public/interfaces/display/display.mojom-shared.h"
#include "services/ui/public/interfaces/window_manager_constants.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace ui {
namespace mojom {
    class FrameDecorationValuesDataView;

    class WsDisplayDataView;

} // namespace mojom
} // namespace ui

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::ui::mojom::FrameDecorationValuesDataView> {
        using Data = ::ui::mojom::internal::FrameDecorationValues_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::ui::mojom::WsDisplayDataView> {
        using Data = ::ui::mojom::internal::WsDisplay_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace ui {
namespace mojom {

    enum class WindowManagerErrorCode : int32_t {
        SUCCESS,
        ACCESS_DENIED,
    };

    inline std::ostream& operator<<(std::ostream& os, WindowManagerErrorCode value)
    {
        switch (value) {
        case WindowManagerErrorCode::SUCCESS:
            return os << "WindowManagerErrorCode::SUCCESS";
        case WindowManagerErrorCode::ACCESS_DENIED:
            return os << "WindowManagerErrorCode::ACCESS_DENIED";
        default:
            return os << "Unknown WindowManagerErrorCode value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(WindowManagerErrorCode value)
    {
        return internal::WindowManagerErrorCode_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class ShowState : int32_t {
        DEFAULT,
        NORMAL,
        MINIMIZED,
        MAXIMIZED,
        INACTIVE,
        FULLSCREEN,
        DOCKED,
    };

    inline std::ostream& operator<<(std::ostream& os, ShowState value)
    {
        switch (value) {
        case ShowState::DEFAULT:
            return os << "ShowState::DEFAULT";
        case ShowState::NORMAL:
            return os << "ShowState::NORMAL";
        case ShowState::MINIMIZED:
            return os << "ShowState::MINIMIZED";
        case ShowState::MAXIMIZED:
            return os << "ShowState::MAXIMIZED";
        case ShowState::INACTIVE:
            return os << "ShowState::INACTIVE";
        case ShowState::FULLSCREEN:
            return os << "ShowState::FULLSCREEN";
        case ShowState::DOCKED:
            return os << "ShowState::DOCKED";
        default:
            return os << "Unknown ShowState value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(ShowState value)
    {
        return internal::ShowState_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class MoveLoopSource : int32_t {
        MOUSE,
        TOUCH,
    };

    inline std::ostream& operator<<(std::ostream& os, MoveLoopSource value)
    {
        switch (value) {
        case MoveLoopSource::MOUSE:
            return os << "MoveLoopSource::MOUSE";
        case MoveLoopSource::TOUCH:
            return os << "MoveLoopSource::TOUCH";
        default:
            return os << "Unknown MoveLoopSource value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(MoveLoopSource value)
    {
        return internal::MoveLoopSource_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class WindowType : int32_t {
        WINDOW,
        PANEL,
        WINDOW_FRAMELESS,
        CONTROL,
        POPUP,
        MENU,
        TOOLTIP,
        BUBBLE,
        DRAG,
        UNKNOWN,
    };

    inline std::ostream& operator<<(std::ostream& os, WindowType value)
    {
        switch (value) {
        case WindowType::WINDOW:
            return os << "WindowType::WINDOW";
        case WindowType::PANEL:
            return os << "WindowType::PANEL";
        case WindowType::WINDOW_FRAMELESS:
            return os << "WindowType::WINDOW_FRAMELESS";
        case WindowType::CONTROL:
            return os << "WindowType::CONTROL";
        case WindowType::POPUP:
            return os << "WindowType::POPUP";
        case WindowType::MENU:
            return os << "WindowType::MENU";
        case WindowType::TOOLTIP:
            return os << "WindowType::TOOLTIP";
        case WindowType::BUBBLE:
            return os << "WindowType::BUBBLE";
        case WindowType::DRAG:
            return os << "WindowType::DRAG";
        case WindowType::UNKNOWN:
            return os << "WindowType::UNKNOWN";
        default:
            return os << "Unknown WindowType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(WindowType value)
    {
        return internal::WindowType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class FrameDecorationValuesDataView {
    public:
        FrameDecorationValuesDataView() { }

        FrameDecorationValuesDataView(
            internal::FrameDecorationValues_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetNormalClientAreaInsetsDataView(
            ::gfx::mojom::InsetsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNormalClientAreaInsets(UserType* output)
        {
            auto* pointer = data_->normal_client_area_insets.Get();
            return mojo::internal::Deserialize<::gfx::mojom::InsetsDataView>(
                pointer, output, context_);
        }
        inline void GetMaximizedClientAreaInsetsDataView(
            ::gfx::mojom::InsetsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMaximizedClientAreaInsets(UserType* output)
        {
            auto* pointer = data_->maximized_client_area_insets.Get();
            return mojo::internal::Deserialize<::gfx::mojom::InsetsDataView>(
                pointer, output, context_);
        }
        uint32_t max_title_bar_button_width() const
        {
            return data_->max_title_bar_button_width;
        }

    private:
        internal::FrameDecorationValues_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WsDisplayDataView {
    public:
        WsDisplayDataView() { }

        WsDisplayDataView(
            internal::WsDisplay_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDisplayDataView(
            ::display::mojom::DisplayDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDisplay(UserType* output)
        {
            auto* pointer = data_->display.Get();
            return mojo::internal::Deserialize<::display::mojom::DisplayDataView>(
                pointer, output, context_);
        }
        inline void GetFrameDecorationValuesDataView(
            FrameDecorationValuesDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFrameDecorationValues(UserType* output)
        {
            auto* pointer = data_->frame_decoration_values.Get();
            return mojo::internal::Deserialize<::ui::mojom::FrameDecorationValuesDataView>(
                pointer, output, context_);
        }

    private:
        internal::WsDisplay_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace ui

namespace std {

template <>
struct hash<::ui::mojom::WindowManagerErrorCode>
    : public mojo::internal::EnumHashImpl<::ui::mojom::WindowManagerErrorCode> {
};

template <>
struct hash<::ui::mojom::ShowState>
    : public mojo::internal::EnumHashImpl<::ui::mojom::ShowState> {
};

template <>
struct hash<::ui::mojom::MoveLoopSource>
    : public mojo::internal::EnumHashImpl<::ui::mojom::MoveLoopSource> {
};

template <>
struct hash<::ui::mojom::WindowType>
    : public mojo::internal::EnumHashImpl<::ui::mojom::WindowType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::ui::mojom::WindowManagerErrorCode, ::ui::mojom::WindowManagerErrorCode> {
    static ::ui::mojom::WindowManagerErrorCode ToMojom(::ui::mojom::WindowManagerErrorCode input) { return input; }
    static bool FromMojom(::ui::mojom::WindowManagerErrorCode input, ::ui::mojom::WindowManagerErrorCode* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::WindowManagerErrorCode, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::ui::mojom::WindowManagerErrorCode, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::ui::mojom::WindowManagerErrorCode>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::ui::mojom::ShowState, ::ui::mojom::ShowState> {
    static ::ui::mojom::ShowState ToMojom(::ui::mojom::ShowState input) { return input; }
    static bool FromMojom(::ui::mojom::ShowState input, ::ui::mojom::ShowState* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::ShowState, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::ui::mojom::ShowState, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::ui::mojom::ShowState>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::ui::mojom::MoveLoopSource, ::ui::mojom::MoveLoopSource> {
    static ::ui::mojom::MoveLoopSource ToMojom(::ui::mojom::MoveLoopSource input) { return input; }
    static bool FromMojom(::ui::mojom::MoveLoopSource input, ::ui::mojom::MoveLoopSource* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::MoveLoopSource, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::ui::mojom::MoveLoopSource, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::ui::mojom::MoveLoopSource>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::ui::mojom::WindowType, ::ui::mojom::WindowType> {
    static ::ui::mojom::WindowType ToMojom(::ui::mojom::WindowType input) { return input; }
    static bool FromMojom(::ui::mojom::WindowType input, ::ui::mojom::WindowType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::WindowType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::ui::mojom::WindowType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::ui::mojom::WindowType>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::FrameDecorationValuesDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::FrameDecorationValuesDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::FrameDecorationValues_Data);
            decltype(CallWithContext(Traits::normal_client_area_insets, input, custom_context)) in_normal_client_area_insets = CallWithContext(Traits::normal_client_area_insets, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::InsetsDataView>(
                in_normal_client_area_insets, context);
            decltype(CallWithContext(Traits::maximized_client_area_insets, input, custom_context)) in_maximized_client_area_insets = CallWithContext(Traits::maximized_client_area_insets, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::InsetsDataView>(
                in_maximized_client_area_insets, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::FrameDecorationValues_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::FrameDecorationValues_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::normal_client_area_insets, input, custom_context)) in_normal_client_area_insets = CallWithContext(Traits::normal_client_area_insets, input, custom_context);
            typename decltype(result->normal_client_area_insets)::BaseType* normal_client_area_insets_ptr;
            mojo::internal::Serialize<::gfx::mojom::InsetsDataView>(
                in_normal_client_area_insets, buffer, &normal_client_area_insets_ptr, context);
            result->normal_client_area_insets.Set(normal_client_area_insets_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->normal_client_area_insets.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null normal_client_area_insets in FrameDecorationValues struct");
            decltype(CallWithContext(Traits::maximized_client_area_insets, input, custom_context)) in_maximized_client_area_insets = CallWithContext(Traits::maximized_client_area_insets, input, custom_context);
            typename decltype(result->maximized_client_area_insets)::BaseType* maximized_client_area_insets_ptr;
            mojo::internal::Serialize<::gfx::mojom::InsetsDataView>(
                in_maximized_client_area_insets, buffer, &maximized_client_area_insets_ptr, context);
            result->maximized_client_area_insets.Set(maximized_client_area_insets_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->maximized_client_area_insets.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null maximized_client_area_insets in FrameDecorationValues struct");
            result->max_title_bar_button_width = CallWithContext(Traits::max_title_bar_button_width, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::FrameDecorationValues_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::FrameDecorationValuesDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::WsDisplayDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::WsDisplayDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::WsDisplay_Data);
            decltype(CallWithContext(Traits::display, input, custom_context)) in_display = CallWithContext(Traits::display, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::display::mojom::DisplayDataView>(
                in_display, context);
            decltype(CallWithContext(Traits::frame_decoration_values, input, custom_context)) in_frame_decoration_values = CallWithContext(Traits::frame_decoration_values, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::ui::mojom::FrameDecorationValuesDataView>(
                in_frame_decoration_values, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::WsDisplay_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::WsDisplay_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::display, input, custom_context)) in_display = CallWithContext(Traits::display, input, custom_context);
            typename decltype(result->display)::BaseType* display_ptr;
            mojo::internal::Serialize<::display::mojom::DisplayDataView>(
                in_display, buffer, &display_ptr, context);
            result->display.Set(display_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->display.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null display in WsDisplay struct");
            decltype(CallWithContext(Traits::frame_decoration_values, input, custom_context)) in_frame_decoration_values = CallWithContext(Traits::frame_decoration_values, input, custom_context);
            typename decltype(result->frame_decoration_values)::BaseType* frame_decoration_values_ptr;
            mojo::internal::Serialize<::ui::mojom::FrameDecorationValuesDataView>(
                in_frame_decoration_values, buffer, &frame_decoration_values_ptr, context);
            result->frame_decoration_values.Set(frame_decoration_values_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->frame_decoration_values.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null frame_decoration_values in WsDisplay struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::WsDisplay_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::WsDisplayDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace ui {
namespace mojom {

    inline void FrameDecorationValuesDataView::GetNormalClientAreaInsetsDataView(
        ::gfx::mojom::InsetsDataView* output)
    {
        auto pointer = data_->normal_client_area_insets.Get();
        *output = ::gfx::mojom::InsetsDataView(pointer, context_);
    }
    inline void FrameDecorationValuesDataView::GetMaximizedClientAreaInsetsDataView(
        ::gfx::mojom::InsetsDataView* output)
    {
        auto pointer = data_->maximized_client_area_insets.Get();
        *output = ::gfx::mojom::InsetsDataView(pointer, context_);
    }

    inline void WsDisplayDataView::GetDisplayDataView(
        ::display::mojom::DisplayDataView* output)
    {
        auto pointer = data_->display.Get();
        *output = ::display::mojom::DisplayDataView(pointer, context_);
    }
    inline void WsDisplayDataView::GetFrameDecorationValuesDataView(
        FrameDecorationValuesDataView* output)
    {
        auto pointer = data_->frame_decoration_values.Get();
        *output = FrameDecorationValuesDataView(pointer, context_);
    }

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_CONSTANTS_MOJOM_SHARED_H_
