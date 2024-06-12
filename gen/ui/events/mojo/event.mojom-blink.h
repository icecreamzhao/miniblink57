// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_EVENTS_MOJO_EVENT_MOJOM_BLINK_H_
#define UI_EVENTS_MOJO_EVENT_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
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
#include "ui/events/mojo/event.mojom-shared.h"
#include "ui/events/mojo/event_constants.mojom-blink.h"
#include "ui/events/mojo/keyboard_codes.mojom-blink.h"

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebSize.h"

namespace ui {
namespace mojom {
    namespace blink {
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    LocationData::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    LocationData::DataView, WTF::Vector<uint8_t>>(
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    WheelData::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    WheelData::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::ui::mojom::blink::WheelMode mode;
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    KeyData::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    KeyData::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            int32_t key_code;
            bool is_char;
            uint16_t character;
            ::ui::mojom::blink::KeyboardCode windows_key_code;
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    PointerData::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    PointerData::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            int32_t pointer_id;
            int32_t changed_button_flags;
            ::ui::mojom::blink::PointerKind kind;
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    BrushData::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    BrushData::DataView, WTF::Vector<uint8_t>>(
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    Event::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    Event::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::ui::mojom::blink::EventType action;
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

    } // namespace blink
} // namespace mojom
} // namespace ui

namespace mojo {

template <>
struct StructTraits<::ui::mojom::blink::KeyData::DataView,
    ::ui::mojom::blink::KeyDataPtr> {
    static bool IsNull(const ::ui::mojom::blink::KeyDataPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::blink::KeyDataPtr* output) { output->reset(); }

    static decltype(::ui::mojom::blink::KeyData::key_code) key_code(
        const ::ui::mojom::blink::KeyDataPtr& input)
    {
        return input->key_code;
    }

    static decltype(::ui::mojom::blink::KeyData::is_char) is_char(
        const ::ui::mojom::blink::KeyDataPtr& input)
    {
        return input->is_char;
    }

    static decltype(::ui::mojom::blink::KeyData::character) character(
        const ::ui::mojom::blink::KeyDataPtr& input)
    {
        return input->character;
    }

    static decltype(::ui::mojom::blink::KeyData::windows_key_code) windows_key_code(
        const ::ui::mojom::blink::KeyDataPtr& input)
    {
        return input->windows_key_code;
    }

    static decltype(::ui::mojom::blink::KeyData::native_key_code) native_key_code(
        const ::ui::mojom::blink::KeyDataPtr& input)
    {
        return input->native_key_code;
    }

    static decltype(::ui::mojom::blink::KeyData::text) text(
        const ::ui::mojom::blink::KeyDataPtr& input)
    {
        return input->text;
    }

    static decltype(::ui::mojom::blink::KeyData::unmodified_text) unmodified_text(
        const ::ui::mojom::blink::KeyDataPtr& input)
    {
        return input->unmodified_text;
    }

    static bool Read(::ui::mojom::blink::KeyData::DataView input, ::ui::mojom::blink::KeyDataPtr* output);
};

template <>
struct StructTraits<::ui::mojom::blink::LocationData::DataView,
    ::ui::mojom::blink::LocationDataPtr> {
    static bool IsNull(const ::ui::mojom::blink::LocationDataPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::blink::LocationDataPtr* output) { output->reset(); }

    static decltype(::ui::mojom::blink::LocationData::x) x(
        const ::ui::mojom::blink::LocationDataPtr& input)
    {
        return input->x;
    }

    static decltype(::ui::mojom::blink::LocationData::y) y(
        const ::ui::mojom::blink::LocationDataPtr& input)
    {
        return input->y;
    }

    static decltype(::ui::mojom::blink::LocationData::screen_x) screen_x(
        const ::ui::mojom::blink::LocationDataPtr& input)
    {
        return input->screen_x;
    }

    static decltype(::ui::mojom::blink::LocationData::screen_y) screen_y(
        const ::ui::mojom::blink::LocationDataPtr& input)
    {
        return input->screen_y;
    }

    static bool Read(::ui::mojom::blink::LocationData::DataView input, ::ui::mojom::blink::LocationDataPtr* output);
};

template <>
struct StructTraits<::ui::mojom::blink::PointerData::DataView,
    ::ui::mojom::blink::PointerDataPtr> {
    static bool IsNull(const ::ui::mojom::blink::PointerDataPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::blink::PointerDataPtr* output) { output->reset(); }

    static decltype(::ui::mojom::blink::PointerData::pointer_id) pointer_id(
        const ::ui::mojom::blink::PointerDataPtr& input)
    {
        return input->pointer_id;
    }

    static decltype(::ui::mojom::blink::PointerData::changed_button_flags) changed_button_flags(
        const ::ui::mojom::blink::PointerDataPtr& input)
    {
        return input->changed_button_flags;
    }

    static decltype(::ui::mojom::blink::PointerData::kind) kind(
        const ::ui::mojom::blink::PointerDataPtr& input)
    {
        return input->kind;
    }

    static const decltype(::ui::mojom::blink::PointerData::location)& location(
        const ::ui::mojom::blink::PointerDataPtr& input)
    {
        return input->location;
    }

    static const decltype(::ui::mojom::blink::PointerData::brush_data)& brush_data(
        const ::ui::mojom::blink::PointerDataPtr& input)
    {
        return input->brush_data;
    }

    static const decltype(::ui::mojom::blink::PointerData::wheel_data)& wheel_data(
        const ::ui::mojom::blink::PointerDataPtr& input)
    {
        return input->wheel_data;
    }

    static bool Read(::ui::mojom::blink::PointerData::DataView input, ::ui::mojom::blink::PointerDataPtr* output);
};

template <>
struct StructTraits<::ui::mojom::blink::WheelData::DataView,
    ::ui::mojom::blink::WheelDataPtr> {
    static bool IsNull(const ::ui::mojom::blink::WheelDataPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::blink::WheelDataPtr* output) { output->reset(); }

    static decltype(::ui::mojom::blink::WheelData::mode) mode(
        const ::ui::mojom::blink::WheelDataPtr& input)
    {
        return input->mode;
    }

    static decltype(::ui::mojom::blink::WheelData::delta_x) delta_x(
        const ::ui::mojom::blink::WheelDataPtr& input)
    {
        return input->delta_x;
    }

    static decltype(::ui::mojom::blink::WheelData::delta_y) delta_y(
        const ::ui::mojom::blink::WheelDataPtr& input)
    {
        return input->delta_y;
    }

    static decltype(::ui::mojom::blink::WheelData::delta_z) delta_z(
        const ::ui::mojom::blink::WheelDataPtr& input)
    {
        return input->delta_z;
    }

    static bool Read(::ui::mojom::blink::WheelData::DataView input, ::ui::mojom::blink::WheelDataPtr* output);
};

template <>
struct StructTraits<::ui::mojom::blink::BrushData::DataView,
    ::ui::mojom::blink::BrushDataPtr> {
    static bool IsNull(const ::ui::mojom::blink::BrushDataPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::blink::BrushDataPtr* output) { output->reset(); }

    static decltype(::ui::mojom::blink::BrushData::width) width(
        const ::ui::mojom::blink::BrushDataPtr& input)
    {
        return input->width;
    }

    static decltype(::ui::mojom::blink::BrushData::height) height(
        const ::ui::mojom::blink::BrushDataPtr& input)
    {
        return input->height;
    }

    static decltype(::ui::mojom::blink::BrushData::pressure) pressure(
        const ::ui::mojom::blink::BrushDataPtr& input)
    {
        return input->pressure;
    }

    static decltype(::ui::mojom::blink::BrushData::tilt_x) tilt_x(
        const ::ui::mojom::blink::BrushDataPtr& input)
    {
        return input->tilt_x;
    }

    static decltype(::ui::mojom::blink::BrushData::tilt_y) tilt_y(
        const ::ui::mojom::blink::BrushDataPtr& input)
    {
        return input->tilt_y;
    }

    static bool Read(::ui::mojom::blink::BrushData::DataView input, ::ui::mojom::blink::BrushDataPtr* output);
};

template <>
struct StructTraits<::ui::mojom::blink::Event::DataView,
    ::ui::mojom::blink::EventPtr> {
    static bool IsNull(const ::ui::mojom::blink::EventPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::blink::EventPtr* output) { output->reset(); }

    static decltype(::ui::mojom::blink::Event::action) action(
        const ::ui::mojom::blink::EventPtr& input)
    {
        return input->action;
    }

    static decltype(::ui::mojom::blink::Event::flags) flags(
        const ::ui::mojom::blink::EventPtr& input)
    {
        return input->flags;
    }

    static decltype(::ui::mojom::blink::Event::time_stamp) time_stamp(
        const ::ui::mojom::blink::EventPtr& input)
    {
        return input->time_stamp;
    }

    static const decltype(::ui::mojom::blink::Event::key_data)& key_data(
        const ::ui::mojom::blink::EventPtr& input)
    {
        return input->key_data;
    }

    static const decltype(::ui::mojom::blink::Event::pointer_data)& pointer_data(
        const ::ui::mojom::blink::EventPtr& input)
    {
        return input->pointer_data;
    }

    static bool Read(::ui::mojom::blink::Event::DataView input, ::ui::mojom::blink::EventPtr* output);
};

} // namespace mojo

#endif // UI_EVENTS_MOJO_EVENT_MOJOM_BLINK_H_