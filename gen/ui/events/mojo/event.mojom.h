// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_EVENTS_MOJO_EVENT_MOJOM_H_
#define UI_EVENTS_MOJO_EVENT_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/control_message_proxy.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/lib/union_accessor.h"
#include "mojo/public/cpp/bindings/native_struct.h"
#include "mojo/public/cpp/bindings/no_interface.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"
#include "mojo/public/cpp/bindings/union_traits.h"
#include "ui/events/event.h"
#include "ui/events/latency_info.h"
#include "ui/events/mojo/event.mojom-shared.h"
#include "ui/events/mojo/event_constants.mojom.h"
#include "ui/events/mojo/keyboard_codes.mojom.h"
#include "ui/gfx/buffer_types.h"
#include "ui/gfx/color_space.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "ui/gfx/gpu_memory_buffer.h"
#include "ui/gfx/icc_profile.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace ui {
namespace mojom {
    class KeyData;
    using KeyDataPtr = mojo::StructPtr<KeyData>;

    class LocationData;
    using LocationDataPtr = mojo::InlinedStructPtr<LocationData>;

    class PointerData;
    using PointerDataPtr = mojo::StructPtr<PointerData>;

    class WheelData;
    using WheelDataPtr = mojo::InlinedStructPtr<WheelData>;

    class BrushData;
    using BrushDataPtr = mojo::StructPtr<BrushData>;

    class Event;
    using EventPtr = mojo::StructPtr<Event>;

    class LocationData {
    public:
        using DataView = LocationDataDataView;
        using Data_ = internal::LocationData_Data;

        static LocationDataPtr New();

        template <typename U>
        static LocationDataPtr From(const U& u)
        {
            return mojo::TypeConverter<LocationDataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, LocationData>::Convert(*this);
        }

        LocationData();
        ~LocationData();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = LocationDataPtr>
        LocationDataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, LocationData>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                LocationData::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                LocationData::DataView, std::vector<uint8_t>>(
                input, output);
        }

        float x;
        float y;
        float screen_x;
        float screen_y;
    };

    class WheelData {
    public:
        using DataView = WheelDataDataView;
        using Data_ = internal::WheelData_Data;

        static WheelDataPtr New();

        template <typename U>
        static WheelDataPtr From(const U& u)
        {
            return mojo::TypeConverter<WheelDataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, WheelData>::Convert(*this);
        }

        WheelData();
        ~WheelData();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = WheelDataPtr>
        WheelDataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, WheelData>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                WheelData::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                WheelData::DataView, std::vector<uint8_t>>(
                input, output);
        }

        ::ui::mojom::WheelMode mode;
        float delta_x;
        float delta_y;
        float delta_z;
    };

    class KeyData {
    public:
        using DataView = KeyDataDataView;
        using Data_ = internal::KeyData_Data;

        static KeyDataPtr New();

        template <typename U>
        static KeyDataPtr From(const U& u)
        {
            return mojo::TypeConverter<KeyDataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, KeyData>::Convert(*this);
        }

        KeyData();
        ~KeyData();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = KeyDataPtr>
        KeyDataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, KeyData>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                KeyData::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                KeyData::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int32_t key_code;
        bool is_char;
        uint16_t character;
        ::ui::mojom::KeyboardCode windows_key_code;
        int32_t native_key_code;
        uint16_t text;
        uint16_t unmodified_text;
    };

    class PointerData {
    public:
        using DataView = PointerDataDataView;
        using Data_ = internal::PointerData_Data;

        static PointerDataPtr New();

        template <typename U>
        static PointerDataPtr From(const U& u)
        {
            return mojo::TypeConverter<PointerDataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PointerData>::Convert(*this);
        }

        PointerData();
        ~PointerData();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PointerDataPtr>
        PointerDataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PointerData>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PointerData::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PointerData::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int32_t pointer_id;
        int32_t changed_button_flags;
        ::ui::mojom::PointerKind kind;
        LocationDataPtr location;
        BrushDataPtr brush_data;
        WheelDataPtr wheel_data;

    private:
        DISALLOW_COPY_AND_ASSIGN(PointerData);
    };

    class BrushData {
    public:
        using DataView = BrushDataDataView;
        using Data_ = internal::BrushData_Data;

        static BrushDataPtr New();

        template <typename U>
        static BrushDataPtr From(const U& u)
        {
            return mojo::TypeConverter<BrushDataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, BrushData>::Convert(*this);
        }

        BrushData();
        ~BrushData();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = BrushDataPtr>
        BrushDataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, BrushData>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                BrushData::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                BrushData::DataView, std::vector<uint8_t>>(
                input, output);
        }

        float width;
        float height;
        float pressure;
        float tilt_x;
        float tilt_y;
    };

    class Event {
    public:
        using DataView = EventDataView;
        using Data_ = internal::Event_Data;

        static EventPtr New();

        template <typename U>
        static EventPtr From(const U& u)
        {
            return mojo::TypeConverter<EventPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Event>::Convert(*this);
        }

        Event();
        ~Event();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = EventPtr>
        EventPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Event>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Event::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Event::DataView, std::vector<uint8_t>>(
                input, output);
        }

        ::ui::mojom::EventType action;
        int32_t flags;
        int64_t time_stamp;
        KeyDataPtr key_data;
        PointerDataPtr pointer_data;

    private:
        DISALLOW_COPY_AND_ASSIGN(Event);
    };

    template <typename StructPtrType>
    KeyDataPtr KeyData::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->key_code = mojo::internal::Clone(key_code);
        rv->is_char = mojo::internal::Clone(is_char);
        rv->character = mojo::internal::Clone(character);
        rv->windows_key_code = mojo::internal::Clone(windows_key_code);
        rv->native_key_code = mojo::internal::Clone(native_key_code);
        rv->text = mojo::internal::Clone(text);
        rv->unmodified_text = mojo::internal::Clone(unmodified_text);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, KeyData>::value>::type*>
    bool KeyData::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->key_code, other.key_code))
            return false;
        if (!mojo::internal::Equals(this->is_char, other.is_char))
            return false;
        if (!mojo::internal::Equals(this->character, other.character))
            return false;
        if (!mojo::internal::Equals(this->windows_key_code, other.windows_key_code))
            return false;
        if (!mojo::internal::Equals(this->native_key_code, other.native_key_code))
            return false;
        if (!mojo::internal::Equals(this->text, other.text))
            return false;
        if (!mojo::internal::Equals(this->unmodified_text, other.unmodified_text))
            return false;
        return true;
    }
    template <typename StructPtrType>
    LocationDataPtr LocationData::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->x = mojo::internal::Clone(x);
        rv->y = mojo::internal::Clone(y);
        rv->screen_x = mojo::internal::Clone(screen_x);
        rv->screen_y = mojo::internal::Clone(screen_y);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, LocationData>::value>::type*>
    bool LocationData::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->x, other.x))
            return false;
        if (!mojo::internal::Equals(this->y, other.y))
            return false;
        if (!mojo::internal::Equals(this->screen_x, other.screen_x))
            return false;
        if (!mojo::internal::Equals(this->screen_y, other.screen_y))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PointerDataPtr PointerData::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->pointer_id = mojo::internal::Clone(pointer_id);
        rv->changed_button_flags = mojo::internal::Clone(changed_button_flags);
        rv->kind = mojo::internal::Clone(kind);
        rv->location = mojo::internal::Clone(location);
        rv->brush_data = mojo::internal::Clone(brush_data);
        rv->wheel_data = mojo::internal::Clone(wheel_data);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PointerData>::value>::type*>
    bool PointerData::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->pointer_id, other.pointer_id))
            return false;
        if (!mojo::internal::Equals(this->changed_button_flags, other.changed_button_flags))
            return false;
        if (!mojo::internal::Equals(this->kind, other.kind))
            return false;
        if (!mojo::internal::Equals(this->location, other.location))
            return false;
        if (!mojo::internal::Equals(this->brush_data, other.brush_data))
            return false;
        if (!mojo::internal::Equals(this->wheel_data, other.wheel_data))
            return false;
        return true;
    }
    template <typename StructPtrType>
    WheelDataPtr WheelData::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->mode = mojo::internal::Clone(mode);
        rv->delta_x = mojo::internal::Clone(delta_x);
        rv->delta_y = mojo::internal::Clone(delta_y);
        rv->delta_z = mojo::internal::Clone(delta_z);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, WheelData>::value>::type*>
    bool WheelData::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->mode, other.mode))
            return false;
        if (!mojo::internal::Equals(this->delta_x, other.delta_x))
            return false;
        if (!mojo::internal::Equals(this->delta_y, other.delta_y))
            return false;
        if (!mojo::internal::Equals(this->delta_z, other.delta_z))
            return false;
        return true;
    }
    template <typename StructPtrType>
    BrushDataPtr BrushData::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->width = mojo::internal::Clone(width);
        rv->height = mojo::internal::Clone(height);
        rv->pressure = mojo::internal::Clone(pressure);
        rv->tilt_x = mojo::internal::Clone(tilt_x);
        rv->tilt_y = mojo::internal::Clone(tilt_y);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, BrushData>::value>::type*>
    bool BrushData::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->width, other.width))
            return false;
        if (!mojo::internal::Equals(this->height, other.height))
            return false;
        if (!mojo::internal::Equals(this->pressure, other.pressure))
            return false;
        if (!mojo::internal::Equals(this->tilt_x, other.tilt_x))
            return false;
        if (!mojo::internal::Equals(this->tilt_y, other.tilt_y))
            return false;
        return true;
    }
    template <typename StructPtrType>
    EventPtr Event::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->action = mojo::internal::Clone(action);
        rv->flags = mojo::internal::Clone(flags);
        rv->time_stamp = mojo::internal::Clone(time_stamp);
        rv->key_data = mojo::internal::Clone(key_data);
        rv->pointer_data = mojo::internal::Clone(pointer_data);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Event>::value>::type*>
    bool Event::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->action, other.action))
            return false;
        if (!mojo::internal::Equals(this->flags, other.flags))
            return false;
        if (!mojo::internal::Equals(this->time_stamp, other.time_stamp))
            return false;
        if (!mojo::internal::Equals(this->key_data, other.key_data))
            return false;
        if (!mojo::internal::Equals(this->pointer_data, other.pointer_data))
            return false;
        return true;
    }

} // namespace mojom
} // namespace ui

namespace mojo {

template <>
struct StructTraits<::ui::mojom::KeyData::DataView,
    ::ui::mojom::KeyDataPtr> {
    static bool IsNull(const ::ui::mojom::KeyDataPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::KeyDataPtr* output) { output->reset(); }

    static decltype(::ui::mojom::KeyData::key_code) key_code(
        const ::ui::mojom::KeyDataPtr& input)
    {
        return input->key_code;
    }

    static decltype(::ui::mojom::KeyData::is_char) is_char(
        const ::ui::mojom::KeyDataPtr& input)
    {
        return input->is_char;
    }

    static decltype(::ui::mojom::KeyData::character) character(
        const ::ui::mojom::KeyDataPtr& input)
    {
        return input->character;
    }

    static decltype(::ui::mojom::KeyData::windows_key_code) windows_key_code(
        const ::ui::mojom::KeyDataPtr& input)
    {
        return input->windows_key_code;
    }

    static decltype(::ui::mojom::KeyData::native_key_code) native_key_code(
        const ::ui::mojom::KeyDataPtr& input)
    {
        return input->native_key_code;
    }

    static decltype(::ui::mojom::KeyData::text) text(
        const ::ui::mojom::KeyDataPtr& input)
    {
        return input->text;
    }

    static decltype(::ui::mojom::KeyData::unmodified_text) unmodified_text(
        const ::ui::mojom::KeyDataPtr& input)
    {
        return input->unmodified_text;
    }

    static bool Read(::ui::mojom::KeyData::DataView input, ::ui::mojom::KeyDataPtr* output);
};

template <>
struct StructTraits<::ui::mojom::LocationData::DataView,
    ::ui::mojom::LocationDataPtr> {
    static bool IsNull(const ::ui::mojom::LocationDataPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::LocationDataPtr* output) { output->reset(); }

    static decltype(::ui::mojom::LocationData::x) x(
        const ::ui::mojom::LocationDataPtr& input)
    {
        return input->x;
    }

    static decltype(::ui::mojom::LocationData::y) y(
        const ::ui::mojom::LocationDataPtr& input)
    {
        return input->y;
    }

    static decltype(::ui::mojom::LocationData::screen_x) screen_x(
        const ::ui::mojom::LocationDataPtr& input)
    {
        return input->screen_x;
    }

    static decltype(::ui::mojom::LocationData::screen_y) screen_y(
        const ::ui::mojom::LocationDataPtr& input)
    {
        return input->screen_y;
    }

    static bool Read(::ui::mojom::LocationData::DataView input, ::ui::mojom::LocationDataPtr* output);
};

template <>
struct StructTraits<::ui::mojom::PointerData::DataView,
    ::ui::mojom::PointerDataPtr> {
    static bool IsNull(const ::ui::mojom::PointerDataPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::PointerDataPtr* output) { output->reset(); }

    static decltype(::ui::mojom::PointerData::pointer_id) pointer_id(
        const ::ui::mojom::PointerDataPtr& input)
    {
        return input->pointer_id;
    }

    static decltype(::ui::mojom::PointerData::changed_button_flags) changed_button_flags(
        const ::ui::mojom::PointerDataPtr& input)
    {
        return input->changed_button_flags;
    }

    static decltype(::ui::mojom::PointerData::kind) kind(
        const ::ui::mojom::PointerDataPtr& input)
    {
        return input->kind;
    }

    static const decltype(::ui::mojom::PointerData::location)& location(
        const ::ui::mojom::PointerDataPtr& input)
    {
        return input->location;
    }

    static const decltype(::ui::mojom::PointerData::brush_data)& brush_data(
        const ::ui::mojom::PointerDataPtr& input)
    {
        return input->brush_data;
    }

    static const decltype(::ui::mojom::PointerData::wheel_data)& wheel_data(
        const ::ui::mojom::PointerDataPtr& input)
    {
        return input->wheel_data;
    }

    static bool Read(::ui::mojom::PointerData::DataView input, ::ui::mojom::PointerDataPtr* output);
};

template <>
struct StructTraits<::ui::mojom::WheelData::DataView,
    ::ui::mojom::WheelDataPtr> {
    static bool IsNull(const ::ui::mojom::WheelDataPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::WheelDataPtr* output) { output->reset(); }

    static decltype(::ui::mojom::WheelData::mode) mode(
        const ::ui::mojom::WheelDataPtr& input)
    {
        return input->mode;
    }

    static decltype(::ui::mojom::WheelData::delta_x) delta_x(
        const ::ui::mojom::WheelDataPtr& input)
    {
        return input->delta_x;
    }

    static decltype(::ui::mojom::WheelData::delta_y) delta_y(
        const ::ui::mojom::WheelDataPtr& input)
    {
        return input->delta_y;
    }

    static decltype(::ui::mojom::WheelData::delta_z) delta_z(
        const ::ui::mojom::WheelDataPtr& input)
    {
        return input->delta_z;
    }

    static bool Read(::ui::mojom::WheelData::DataView input, ::ui::mojom::WheelDataPtr* output);
};

template <>
struct StructTraits<::ui::mojom::BrushData::DataView,
    ::ui::mojom::BrushDataPtr> {
    static bool IsNull(const ::ui::mojom::BrushDataPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::BrushDataPtr* output) { output->reset(); }

    static decltype(::ui::mojom::BrushData::width) width(
        const ::ui::mojom::BrushDataPtr& input)
    {
        return input->width;
    }

    static decltype(::ui::mojom::BrushData::height) height(
        const ::ui::mojom::BrushDataPtr& input)
    {
        return input->height;
    }

    static decltype(::ui::mojom::BrushData::pressure) pressure(
        const ::ui::mojom::BrushDataPtr& input)
    {
        return input->pressure;
    }

    static decltype(::ui::mojom::BrushData::tilt_x) tilt_x(
        const ::ui::mojom::BrushDataPtr& input)
    {
        return input->tilt_x;
    }

    static decltype(::ui::mojom::BrushData::tilt_y) tilt_y(
        const ::ui::mojom::BrushDataPtr& input)
    {
        return input->tilt_y;
    }

    static bool Read(::ui::mojom::BrushData::DataView input, ::ui::mojom::BrushDataPtr* output);
};

template <>
struct StructTraits<::ui::mojom::Event::DataView,
    ::ui::mojom::EventPtr> {
    static bool IsNull(const ::ui::mojom::EventPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::EventPtr* output) { output->reset(); }

    static decltype(::ui::mojom::Event::action) action(
        const ::ui::mojom::EventPtr& input)
    {
        return input->action;
    }

    static decltype(::ui::mojom::Event::flags) flags(
        const ::ui::mojom::EventPtr& input)
    {
        return input->flags;
    }

    static decltype(::ui::mojom::Event::time_stamp) time_stamp(
        const ::ui::mojom::EventPtr& input)
    {
        return input->time_stamp;
    }

    static const decltype(::ui::mojom::Event::key_data)& key_data(
        const ::ui::mojom::EventPtr& input)
    {
        return input->key_data;
    }

    static const decltype(::ui::mojom::Event::pointer_data)& pointer_data(
        const ::ui::mojom::EventPtr& input)
    {
        return input->pointer_data;
    }

    static bool Read(::ui::mojom::Event::DataView input, ::ui::mojom::EventPtr* output);
};

} // namespace mojo

#endif // UI_EVENTS_MOJO_EVENT_MOJOM_H_