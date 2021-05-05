// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4056)
#pragma warning(disable : 4065)
#pragma warning(disable : 4756)
#endif

#include "ui/events/mojo/event.mojom-blink.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/Source/platform/mojo/CommonCustomTypesStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/GeometryStructTraits.h"
namespace ui {
namespace mojom {
    namespace blink { // static
        KeyDataPtr KeyData::New()
        {
            KeyDataPtr rv;
            mojo::internal::StructHelper<KeyData>::Initialize(&rv);
            return rv;
        }

        KeyData::KeyData()
            : key_code()
            , is_char()
            , character()
            , windows_key_code()
            , native_key_code()
            , text()
            , unmodified_text()
        {
        }

        KeyData::~KeyData()
        {
        }
        size_t KeyData::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->key_code);
            seed = mojo::internal::WTFHash(seed, this->is_char);
            seed = mojo::internal::WTFHash(seed, this->character);
            seed = mojo::internal::WTFHash(seed, this->windows_key_code);
            seed = mojo::internal::WTFHash(seed, this->native_key_code);
            seed = mojo::internal::WTFHash(seed, this->text);
            seed = mojo::internal::WTFHash(seed, this->unmodified_text);
            return seed;
        } // static
        LocationDataPtr LocationData::New()
        {
            LocationDataPtr rv;
            mojo::internal::StructHelper<LocationData>::Initialize(&rv);
            return rv;
        }

        LocationData::LocationData()
            : x()
            , y()
            , screen_x()
            , screen_y()
        {
        }

        LocationData::~LocationData()
        {
        }
        size_t LocationData::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->x);
            seed = mojo::internal::WTFHash(seed, this->y);
            seed = mojo::internal::WTFHash(seed, this->screen_x);
            seed = mojo::internal::WTFHash(seed, this->screen_y);
            return seed;
        } // static
        PointerDataPtr PointerData::New()
        {
            PointerDataPtr rv;
            mojo::internal::StructHelper<PointerData>::Initialize(&rv);
            return rv;
        }

        PointerData::PointerData()
            : pointer_id()
            , changed_button_flags()
            , kind()
            , location()
            , brush_data()
            , wheel_data()
        {
        }

        PointerData::~PointerData()
        {
        } // static
        WheelDataPtr WheelData::New()
        {
            WheelDataPtr rv;
            mojo::internal::StructHelper<WheelData>::Initialize(&rv);
            return rv;
        }

        WheelData::WheelData()
            : mode()
            , delta_x()
            , delta_y()
            , delta_z()
        {
        }

        WheelData::~WheelData()
        {
        }
        size_t WheelData::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->mode);
            seed = mojo::internal::WTFHash(seed, this->delta_x);
            seed = mojo::internal::WTFHash(seed, this->delta_y);
            seed = mojo::internal::WTFHash(seed, this->delta_z);
            return seed;
        } // static
        BrushDataPtr BrushData::New()
        {
            BrushDataPtr rv;
            mojo::internal::StructHelper<BrushData>::Initialize(&rv);
            return rv;
        }

        BrushData::BrushData()
            : width()
            , height()
            , pressure()
            , tilt_x()
            , tilt_y()
        {
        }

        BrushData::~BrushData()
        {
        }
        size_t BrushData::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->width);
            seed = mojo::internal::WTFHash(seed, this->height);
            seed = mojo::internal::WTFHash(seed, this->pressure);
            seed = mojo::internal::WTFHash(seed, this->tilt_x);
            seed = mojo::internal::WTFHash(seed, this->tilt_y);
            return seed;
        } // static
        EventPtr Event::New()
        {
            EventPtr rv;
            mojo::internal::StructHelper<Event>::Initialize(&rv);
            return rv;
        }

        Event::Event()
            : action()
            , flags()
            , time_stamp()
            , key_data()
            , pointer_data()
        {
        }

        Event::~Event()
        {
        }
    } // namespace blink
} // namespace mojom
} // namespace ui

namespace mojo {

// static
bool StructTraits<::ui::mojom::blink::KeyData::DataView, ::ui::mojom::blink::KeyDataPtr>::Read(
    ::ui::mojom::blink::KeyData::DataView input,
    ::ui::mojom::blink::KeyDataPtr* output)
{
    bool success = true;
    ::ui::mojom::blink::KeyDataPtr result(::ui::mojom::blink::KeyData::New());

    result->key_code = input.key_code();
    result->is_char = input.is_char();
    result->character = input.character();
    if (!input.ReadWindowsKeyCode(&result->windows_key_code))
        success = false;
    result->native_key_code = input.native_key_code();
    result->text = input.text();
    result->unmodified_text = input.unmodified_text();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::blink::LocationData::DataView, ::ui::mojom::blink::LocationDataPtr>::Read(
    ::ui::mojom::blink::LocationData::DataView input,
    ::ui::mojom::blink::LocationDataPtr* output)
{
    bool success = true;
    ::ui::mojom::blink::LocationDataPtr result(::ui::mojom::blink::LocationData::New());

    result->x = input.x();
    result->y = input.y();
    result->screen_x = input.screen_x();
    result->screen_y = input.screen_y();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::blink::PointerData::DataView, ::ui::mojom::blink::PointerDataPtr>::Read(
    ::ui::mojom::blink::PointerData::DataView input,
    ::ui::mojom::blink::PointerDataPtr* output)
{
    bool success = true;
    ::ui::mojom::blink::PointerDataPtr result(::ui::mojom::blink::PointerData::New());

    result->pointer_id = input.pointer_id();
    result->changed_button_flags = input.changed_button_flags();
    if (!input.ReadKind(&result->kind))
        success = false;
    if (!input.ReadLocation(&result->location))
        success = false;
    if (!input.ReadBrushData(&result->brush_data))
        success = false;
    if (!input.ReadWheelData(&result->wheel_data))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::blink::WheelData::DataView, ::ui::mojom::blink::WheelDataPtr>::Read(
    ::ui::mojom::blink::WheelData::DataView input,
    ::ui::mojom::blink::WheelDataPtr* output)
{
    bool success = true;
    ::ui::mojom::blink::WheelDataPtr result(::ui::mojom::blink::WheelData::New());

    if (!input.ReadMode(&result->mode))
        success = false;
    result->delta_x = input.delta_x();
    result->delta_y = input.delta_y();
    result->delta_z = input.delta_z();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::blink::BrushData::DataView, ::ui::mojom::blink::BrushDataPtr>::Read(
    ::ui::mojom::blink::BrushData::DataView input,
    ::ui::mojom::blink::BrushDataPtr* output)
{
    bool success = true;
    ::ui::mojom::blink::BrushDataPtr result(::ui::mojom::blink::BrushData::New());

    result->width = input.width();
    result->height = input.height();
    result->pressure = input.pressure();
    result->tilt_x = input.tilt_x();
    result->tilt_y = input.tilt_y();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::blink::Event::DataView, ::ui::mojom::blink::EventPtr>::Read(
    ::ui::mojom::blink::Event::DataView input,
    ::ui::mojom::blink::EventPtr* output)
{
    bool success = true;
    ::ui::mojom::blink::EventPtr result(::ui::mojom::blink::Event::New());

    if (!input.ReadAction(&result->action))
        success = false;
    result->flags = input.flags();
    result->time_stamp = input.time_stamp();
    if (!input.ReadKeyData(&result->key_data))
        success = false;
    if (!input.ReadPointerData(&result->pointer_data))
        success = false;
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif