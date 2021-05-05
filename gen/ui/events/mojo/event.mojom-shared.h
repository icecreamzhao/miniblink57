// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_EVENTS_MOJO_EVENT_MOJOM_SHARED_H_
#define UI_EVENTS_MOJO_EVENT_MOJOM_SHARED_H_

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
#include "ui/events/mojo/event.mojom-shared-internal.h"
#include "ui/events/mojo/event_constants.mojom-shared.h"
#include "ui/events/mojo/keyboard_codes.mojom-shared.h"

namespace ui {
namespace mojom {
    class KeyDataDataView;

    class LocationDataDataView;

    class PointerDataDataView;

    class WheelDataDataView;

    class BrushDataDataView;

    class EventDataView;

} // namespace mojom
} // namespace ui

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::ui::mojom::KeyDataDataView> {
        using Data = ::ui::mojom::internal::KeyData_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::ui::mojom::LocationDataDataView> {
        using Data = ::ui::mojom::internal::LocationData_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::ui::mojom::PointerDataDataView> {
        using Data = ::ui::mojom::internal::PointerData_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::ui::mojom::WheelDataDataView> {
        using Data = ::ui::mojom::internal::WheelData_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::ui::mojom::BrushDataDataView> {
        using Data = ::ui::mojom::internal::BrushData_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::ui::mojom::EventDataView> {
        using Data = ::ui::mojom::internal::Event_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace ui {
namespace mojom {
    class KeyDataDataView {
    public:
        KeyDataDataView() { }

        KeyDataDataView(
            internal::KeyData_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t key_code() const
        {
            return data_->key_code;
        }
        bool is_char() const
        {
            return data_->is_char;
        }
        uint16_t character() const
        {
            return data_->character;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadWindowsKeyCode(UserType* output) const
        {
            auto data_value = data_->windows_key_code;
            return mojo::internal::Deserialize<::ui::mojom::KeyboardCode>(
                data_value, output);
        }

        ::ui::mojom::KeyboardCode windows_key_code() const
        {
            return static_cast<::ui::mojom::KeyboardCode>(data_->windows_key_code);
        }
        int32_t native_key_code() const
        {
            return data_->native_key_code;
        }
        uint16_t text() const
        {
            return data_->text;
        }
        uint16_t unmodified_text() const
        {
            return data_->unmodified_text;
        }

    private:
        internal::KeyData_Data* data_ = nullptr;
    };

    class LocationDataDataView {
    public:
        LocationDataDataView() { }

        LocationDataDataView(
            internal::LocationData_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        float x() const
        {
            return data_->x;
        }
        float y() const
        {
            return data_->y;
        }
        float screen_x() const
        {
            return data_->screen_x;
        }
        float screen_y() const
        {
            return data_->screen_y;
        }

    private:
        internal::LocationData_Data* data_ = nullptr;
    };

    class PointerDataDataView {
    public:
        PointerDataDataView() { }

        PointerDataDataView(
            internal::PointerData_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t pointer_id() const
        {
            return data_->pointer_id;
        }
        int32_t changed_button_flags() const
        {
            return data_->changed_button_flags;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKind(UserType* output) const
        {
            auto data_value = data_->kind;
            return mojo::internal::Deserialize<::ui::mojom::PointerKind>(
                data_value, output);
        }

        ::ui::mojom::PointerKind kind() const
        {
            return static_cast<::ui::mojom::PointerKind>(data_->kind);
        }
        inline void GetLocationDataView(
            LocationDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLocation(UserType* output)
        {
            auto* pointer = data_->location.Get();
            return mojo::internal::Deserialize<::ui::mojom::LocationDataDataView>(
                pointer, output, context_);
        }
        inline void GetBrushDataDataView(
            BrushDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBrushData(UserType* output)
        {
            auto* pointer = data_->brush_data.Get();
            return mojo::internal::Deserialize<::ui::mojom::BrushDataDataView>(
                pointer, output, context_);
        }
        inline void GetWheelDataDataView(
            WheelDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadWheelData(UserType* output)
        {
            auto* pointer = data_->wheel_data.Get();
            return mojo::internal::Deserialize<::ui::mojom::WheelDataDataView>(
                pointer, output, context_);
        }

    private:
        internal::PointerData_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WheelDataDataView {
    public:
        WheelDataDataView() { }

        WheelDataDataView(
            internal::WheelData_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMode(UserType* output) const
        {
            auto data_value = data_->mode;
            return mojo::internal::Deserialize<::ui::mojom::WheelMode>(
                data_value, output);
        }

        ::ui::mojom::WheelMode mode() const
        {
            return static_cast<::ui::mojom::WheelMode>(data_->mode);
        }
        float delta_x() const
        {
            return data_->delta_x;
        }
        float delta_y() const
        {
            return data_->delta_y;
        }
        float delta_z() const
        {
            return data_->delta_z;
        }

    private:
        internal::WheelData_Data* data_ = nullptr;
    };

    class BrushDataDataView {
    public:
        BrushDataDataView() { }

        BrushDataDataView(
            internal::BrushData_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        float width() const
        {
            return data_->width;
        }
        float height() const
        {
            return data_->height;
        }
        float pressure() const
        {
            return data_->pressure;
        }
        float tilt_x() const
        {
            return data_->tilt_x;
        }
        float tilt_y() const
        {
            return data_->tilt_y;
        }

    private:
        internal::BrushData_Data* data_ = nullptr;
    };

    class EventDataView {
    public:
        EventDataView() { }

        EventDataView(
            internal::Event_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAction(UserType* output) const
        {
            auto data_value = data_->action;
            return mojo::internal::Deserialize<::ui::mojom::EventType>(
                data_value, output);
        }

        ::ui::mojom::EventType action() const
        {
            return static_cast<::ui::mojom::EventType>(data_->action);
        }
        int32_t flags() const
        {
            return data_->flags;
        }
        int64_t time_stamp() const
        {
            return data_->time_stamp;
        }
        inline void GetKeyDataDataView(
            KeyDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKeyData(UserType* output)
        {
            auto* pointer = data_->key_data.Get();
            return mojo::internal::Deserialize<::ui::mojom::KeyDataDataView>(
                pointer, output, context_);
        }
        inline void GetPointerDataDataView(
            PointerDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPointerData(UserType* output)
        {
            auto* pointer = data_->pointer_data.Get();
            return mojo::internal::Deserialize<::ui::mojom::PointerDataDataView>(
                pointer, output, context_);
        }

    private:
        internal::Event_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace ui

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::KeyDataDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::KeyDataDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::KeyData_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::KeyData_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::KeyData_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->key_code = CallWithContext(Traits::key_code, input, custom_context);
            result->is_char = CallWithContext(Traits::is_char, input, custom_context);
            result->character = CallWithContext(Traits::character, input, custom_context);
            mojo::internal::Serialize<::ui::mojom::KeyboardCode>(
                CallWithContext(Traits::windows_key_code, input, custom_context), &result->windows_key_code);
            result->native_key_code = CallWithContext(Traits::native_key_code, input, custom_context);
            result->text = CallWithContext(Traits::text, input, custom_context);
            result->unmodified_text = CallWithContext(Traits::unmodified_text, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::KeyData_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::KeyDataDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::LocationDataDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::LocationDataDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::LocationData_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::LocationData_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::LocationData_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->x = CallWithContext(Traits::x, input, custom_context);
            result->y = CallWithContext(Traits::y, input, custom_context);
            result->screen_x = CallWithContext(Traits::screen_x, input, custom_context);
            result->screen_y = CallWithContext(Traits::screen_y, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::LocationData_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::LocationDataDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::PointerDataDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::PointerDataDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::PointerData_Data);
            decltype(CallWithContext(Traits::location, input, custom_context)) in_location = CallWithContext(Traits::location, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::ui::mojom::LocationDataDataView>(
                in_location, context);
            decltype(CallWithContext(Traits::brush_data, input, custom_context)) in_brush_data = CallWithContext(Traits::brush_data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::ui::mojom::BrushDataDataView>(
                in_brush_data, context);
            decltype(CallWithContext(Traits::wheel_data, input, custom_context)) in_wheel_data = CallWithContext(Traits::wheel_data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::ui::mojom::WheelDataDataView>(
                in_wheel_data, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::PointerData_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::PointerData_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->pointer_id = CallWithContext(Traits::pointer_id, input, custom_context);
            result->changed_button_flags = CallWithContext(Traits::changed_button_flags, input, custom_context);
            mojo::internal::Serialize<::ui::mojom::PointerKind>(
                CallWithContext(Traits::kind, input, custom_context), &result->kind);
            decltype(CallWithContext(Traits::location, input, custom_context)) in_location = CallWithContext(Traits::location, input, custom_context);
            typename decltype(result->location)::BaseType* location_ptr;
            mojo::internal::Serialize<::ui::mojom::LocationDataDataView>(
                in_location, buffer, &location_ptr, context);
            result->location.Set(location_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->location.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null location in PointerData struct");
            decltype(CallWithContext(Traits::brush_data, input, custom_context)) in_brush_data = CallWithContext(Traits::brush_data, input, custom_context);
            typename decltype(result->brush_data)::BaseType* brush_data_ptr;
            mojo::internal::Serialize<::ui::mojom::BrushDataDataView>(
                in_brush_data, buffer, &brush_data_ptr, context);
            result->brush_data.Set(brush_data_ptr);
            decltype(CallWithContext(Traits::wheel_data, input, custom_context)) in_wheel_data = CallWithContext(Traits::wheel_data, input, custom_context);
            typename decltype(result->wheel_data)::BaseType* wheel_data_ptr;
            mojo::internal::Serialize<::ui::mojom::WheelDataDataView>(
                in_wheel_data, buffer, &wheel_data_ptr, context);
            result->wheel_data.Set(wheel_data_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::PointerData_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::PointerDataDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::WheelDataDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::WheelDataDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::WheelData_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::WheelData_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::WheelData_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::ui::mojom::WheelMode>(
                CallWithContext(Traits::mode, input, custom_context), &result->mode);
            result->delta_x = CallWithContext(Traits::delta_x, input, custom_context);
            result->delta_y = CallWithContext(Traits::delta_y, input, custom_context);
            result->delta_z = CallWithContext(Traits::delta_z, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::WheelData_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::WheelDataDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::BrushDataDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::BrushDataDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::BrushData_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::BrushData_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::BrushData_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->width = CallWithContext(Traits::width, input, custom_context);
            result->height = CallWithContext(Traits::height, input, custom_context);
            result->pressure = CallWithContext(Traits::pressure, input, custom_context);
            result->tilt_x = CallWithContext(Traits::tilt_x, input, custom_context);
            result->tilt_y = CallWithContext(Traits::tilt_y, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::BrushData_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::BrushDataDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::EventDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::EventDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::Event_Data);
            decltype(CallWithContext(Traits::key_data, input, custom_context)) in_key_data = CallWithContext(Traits::key_data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::ui::mojom::KeyDataDataView>(
                in_key_data, context);
            decltype(CallWithContext(Traits::pointer_data, input, custom_context)) in_pointer_data = CallWithContext(Traits::pointer_data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::ui::mojom::PointerDataDataView>(
                in_pointer_data, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::Event_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::Event_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::ui::mojom::EventType>(
                CallWithContext(Traits::action, input, custom_context), &result->action);
            result->flags = CallWithContext(Traits::flags, input, custom_context);
            result->time_stamp = CallWithContext(Traits::time_stamp, input, custom_context);
            decltype(CallWithContext(Traits::key_data, input, custom_context)) in_key_data = CallWithContext(Traits::key_data, input, custom_context);
            typename decltype(result->key_data)::BaseType* key_data_ptr;
            mojo::internal::Serialize<::ui::mojom::KeyDataDataView>(
                in_key_data, buffer, &key_data_ptr, context);
            result->key_data.Set(key_data_ptr);
            decltype(CallWithContext(Traits::pointer_data, input, custom_context)) in_pointer_data = CallWithContext(Traits::pointer_data, input, custom_context);
            typename decltype(result->pointer_data)::BaseType* pointer_data_ptr;
            mojo::internal::Serialize<::ui::mojom::PointerDataDataView>(
                in_pointer_data, buffer, &pointer_data_ptr, context);
            result->pointer_data.Set(pointer_data_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::Event_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::EventDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace ui {
namespace mojom {

    inline void PointerDataDataView::GetLocationDataView(
        LocationDataDataView* output)
    {
        auto pointer = data_->location.Get();
        *output = LocationDataDataView(pointer, context_);
    }
    inline void PointerDataDataView::GetBrushDataDataView(
        BrushDataDataView* output)
    {
        auto pointer = data_->brush_data.Get();
        *output = BrushDataDataView(pointer, context_);
    }
    inline void PointerDataDataView::GetWheelDataDataView(
        WheelDataDataView* output)
    {
        auto pointer = data_->wheel_data.Get();
        *output = WheelDataDataView(pointer, context_);
    }

    inline void EventDataView::GetKeyDataDataView(
        KeyDataDataView* output)
    {
        auto pointer = data_->key_data.Get();
        *output = KeyDataDataView(pointer, context_);
    }
    inline void EventDataView::GetPointerDataDataView(
        PointerDataDataView* output)
    {
        auto pointer = data_->pointer_data.Get();
        *output = PointerDataDataView(pointer, context_);
    }

} // namespace mojom
} // namespace ui

#endif // UI_EVENTS_MOJO_EVENT_MOJOM_SHARED_H_
