// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_WEB_WINDOW_FEATURES_MOJOM_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_WEB_WINDOW_FEATURES_MOJOM_H_

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
#include "content/common/bluetooth/web_bluetooth_device_id.h"
#include "content/common/content_export.h"
#include "content/public/common/media_metadata.h"
#include "content/public/common/referrer.h"
#include "device/bluetooth/bluetooth_uuid.h"
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
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"
#include "third_party/WebKit/public/web/window_features.mojom-shared.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "url/gurl.h"
#include "url/origin.h"
#include <string>
#include <vector>

namespace blink {
namespace mojom {
    class WindowFeatures;
    using WindowFeaturesPtr = mojo::StructPtr<WindowFeatures>;

    class CONTENT_EXPORT WindowFeatures {
    public:
        using DataView = WindowFeaturesDataView;
        using Data_ = internal::WindowFeatures_Data;

        static WindowFeaturesPtr New();

        template <typename U>
        static WindowFeaturesPtr From(const U& u)
        {
            return mojo::TypeConverter<WindowFeaturesPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, WindowFeatures>::Convert(*this);
        }

        WindowFeatures();
        ~WindowFeatures();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = WindowFeaturesPtr>
        WindowFeaturesPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, WindowFeatures>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                WindowFeatures::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                WindowFeatures::DataView, std::vector<uint8_t>>(
                input, output);
        }

        float x;
        bool has_x;
        float y;
        bool has_y;
        float width;
        bool has_width;
        float height;
        bool has_height;
        bool menu_bar_visible;
        bool status_bar_visible;
        bool tool_bar_visible;
        bool location_bar_visible;
        bool scrollbars_visible;
        bool resizable;
        bool fullscreen;
        bool dialog;
    };

    template <typename StructPtrType>
    WindowFeaturesPtr WindowFeatures::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->x = mojo::internal::Clone(x);
        rv->has_x = mojo::internal::Clone(has_x);
        rv->y = mojo::internal::Clone(y);
        rv->has_y = mojo::internal::Clone(has_y);
        rv->width = mojo::internal::Clone(width);
        rv->has_width = mojo::internal::Clone(has_width);
        rv->height = mojo::internal::Clone(height);
        rv->has_height = mojo::internal::Clone(has_height);
        rv->menu_bar_visible = mojo::internal::Clone(menu_bar_visible);
        rv->status_bar_visible = mojo::internal::Clone(status_bar_visible);
        rv->tool_bar_visible = mojo::internal::Clone(tool_bar_visible);
        rv->location_bar_visible = mojo::internal::Clone(location_bar_visible);
        rv->scrollbars_visible = mojo::internal::Clone(scrollbars_visible);
        rv->resizable = mojo::internal::Clone(resizable);
        rv->fullscreen = mojo::internal::Clone(fullscreen);
        rv->dialog = mojo::internal::Clone(dialog);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, WindowFeatures>::value>::type*>
    bool WindowFeatures::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->x, other.x))
            return false;
        if (!mojo::internal::Equals(this->has_x, other.has_x))
            return false;
        if (!mojo::internal::Equals(this->y, other.y))
            return false;
        if (!mojo::internal::Equals(this->has_y, other.has_y))
            return false;
        if (!mojo::internal::Equals(this->width, other.width))
            return false;
        if (!mojo::internal::Equals(this->has_width, other.has_width))
            return false;
        if (!mojo::internal::Equals(this->height, other.height))
            return false;
        if (!mojo::internal::Equals(this->has_height, other.has_height))
            return false;
        if (!mojo::internal::Equals(this->menu_bar_visible, other.menu_bar_visible))
            return false;
        if (!mojo::internal::Equals(this->status_bar_visible, other.status_bar_visible))
            return false;
        if (!mojo::internal::Equals(this->tool_bar_visible, other.tool_bar_visible))
            return false;
        if (!mojo::internal::Equals(this->location_bar_visible, other.location_bar_visible))
            return false;
        if (!mojo::internal::Equals(this->scrollbars_visible, other.scrollbars_visible))
            return false;
        if (!mojo::internal::Equals(this->resizable, other.resizable))
            return false;
        if (!mojo::internal::Equals(this->fullscreen, other.fullscreen))
            return false;
        if (!mojo::internal::Equals(this->dialog, other.dialog))
            return false;
        return true;
    }

} // namespace mojom
} // namespace blink

namespace mojo {

template <>
struct CONTENT_EXPORT StructTraits<::blink::mojom::WindowFeatures::DataView,
    ::blink::mojom::WindowFeaturesPtr> {
    static bool IsNull(const ::blink::mojom::WindowFeaturesPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::WindowFeaturesPtr* output) { output->reset(); }

    static decltype(::blink::mojom::WindowFeatures::x) x(
        const ::blink::mojom::WindowFeaturesPtr& input)
    {
        return input->x;
    }

    static decltype(::blink::mojom::WindowFeatures::has_x) has_x(
        const ::blink::mojom::WindowFeaturesPtr& input)
    {
        return input->has_x;
    }

    static decltype(::blink::mojom::WindowFeatures::y) y(
        const ::blink::mojom::WindowFeaturesPtr& input)
    {
        return input->y;
    }

    static decltype(::blink::mojom::WindowFeatures::has_y) has_y(
        const ::blink::mojom::WindowFeaturesPtr& input)
    {
        return input->has_y;
    }

    static decltype(::blink::mojom::WindowFeatures::width) width(
        const ::blink::mojom::WindowFeaturesPtr& input)
    {
        return input->width;
    }

    static decltype(::blink::mojom::WindowFeatures::has_width) has_width(
        const ::blink::mojom::WindowFeaturesPtr& input)
    {
        return input->has_width;
    }

    static decltype(::blink::mojom::WindowFeatures::height) height(
        const ::blink::mojom::WindowFeaturesPtr& input)
    {
        return input->height;
    }

    static decltype(::blink::mojom::WindowFeatures::has_height) has_height(
        const ::blink::mojom::WindowFeaturesPtr& input)
    {
        return input->has_height;
    }

    static decltype(::blink::mojom::WindowFeatures::menu_bar_visible) menu_bar_visible(
        const ::blink::mojom::WindowFeaturesPtr& input)
    {
        return input->menu_bar_visible;
    }

    static decltype(::blink::mojom::WindowFeatures::status_bar_visible) status_bar_visible(
        const ::blink::mojom::WindowFeaturesPtr& input)
    {
        return input->status_bar_visible;
    }

    static decltype(::blink::mojom::WindowFeatures::tool_bar_visible) tool_bar_visible(
        const ::blink::mojom::WindowFeaturesPtr& input)
    {
        return input->tool_bar_visible;
    }

    static decltype(::blink::mojom::WindowFeatures::location_bar_visible) location_bar_visible(
        const ::blink::mojom::WindowFeaturesPtr& input)
    {
        return input->location_bar_visible;
    }

    static decltype(::blink::mojom::WindowFeatures::scrollbars_visible) scrollbars_visible(
        const ::blink::mojom::WindowFeaturesPtr& input)
    {
        return input->scrollbars_visible;
    }

    static decltype(::blink::mojom::WindowFeatures::resizable) resizable(
        const ::blink::mojom::WindowFeaturesPtr& input)
    {
        return input->resizable;
    }

    static decltype(::blink::mojom::WindowFeatures::fullscreen) fullscreen(
        const ::blink::mojom::WindowFeaturesPtr& input)
    {
        return input->fullscreen;
    }

    static decltype(::blink::mojom::WindowFeatures::dialog) dialog(
        const ::blink::mojom::WindowFeaturesPtr& input)
    {
        return input->dialog;
    }

    static bool Read(::blink::mojom::WindowFeatures::DataView input, ::blink::mojom::WindowFeaturesPtr* output);
};

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_WEB_WINDOW_FEATURES_MOJOM_H_