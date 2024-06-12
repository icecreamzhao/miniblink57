// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_WEB_WINDOW_FEATURES_MOJOM_BLINK_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_WEB_WINDOW_FEATURES_MOJOM_BLINK_H_

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
#include "third_party/WebKit/public/web/window_features.mojom-shared.h"

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/platform/weborigin/KURL.h"
#include "third_party/WebKit/Source/platform/weborigin/SecurityOrigin.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebCommon.h"
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/platform/WebSize.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"

namespace blink {
namespace mojom {
    namespace blink {
        class WindowFeatures;
        using WindowFeaturesPtr = mojo::StructPtr<WindowFeatures>;

        class BLINK_PLATFORM_EXPORT WindowFeatures {
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    WindowFeatures::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    WindowFeatures::DataView, WTF::Vector<uint8_t>>(
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

    } // namespace blink
} // namespace mojom
} // namespace blink

namespace mojo {

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::WindowFeatures::DataView,
    ::blink::mojom::blink::WindowFeaturesPtr> {
    static bool IsNull(const ::blink::mojom::blink::WindowFeaturesPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::WindowFeaturesPtr* output) { output->reset(); }

    static decltype(::blink::mojom::blink::WindowFeatures::x) x(
        const ::blink::mojom::blink::WindowFeaturesPtr& input)
    {
        return input->x;
    }

    static decltype(::blink::mojom::blink::WindowFeatures::has_x) has_x(
        const ::blink::mojom::blink::WindowFeaturesPtr& input)
    {
        return input->has_x;
    }

    static decltype(::blink::mojom::blink::WindowFeatures::y) y(
        const ::blink::mojom::blink::WindowFeaturesPtr& input)
    {
        return input->y;
    }

    static decltype(::blink::mojom::blink::WindowFeatures::has_y) has_y(
        const ::blink::mojom::blink::WindowFeaturesPtr& input)
    {
        return input->has_y;
    }

    static decltype(::blink::mojom::blink::WindowFeatures::width) width(
        const ::blink::mojom::blink::WindowFeaturesPtr& input)
    {
        return input->width;
    }

    static decltype(::blink::mojom::blink::WindowFeatures::has_width) has_width(
        const ::blink::mojom::blink::WindowFeaturesPtr& input)
    {
        return input->has_width;
    }

    static decltype(::blink::mojom::blink::WindowFeatures::height) height(
        const ::blink::mojom::blink::WindowFeaturesPtr& input)
    {
        return input->height;
    }

    static decltype(::blink::mojom::blink::WindowFeatures::has_height) has_height(
        const ::blink::mojom::blink::WindowFeaturesPtr& input)
    {
        return input->has_height;
    }

    static decltype(::blink::mojom::blink::WindowFeatures::menu_bar_visible) menu_bar_visible(
        const ::blink::mojom::blink::WindowFeaturesPtr& input)
    {
        return input->menu_bar_visible;
    }

    static decltype(::blink::mojom::blink::WindowFeatures::status_bar_visible) status_bar_visible(
        const ::blink::mojom::blink::WindowFeaturesPtr& input)
    {
        return input->status_bar_visible;
    }

    static decltype(::blink::mojom::blink::WindowFeatures::tool_bar_visible) tool_bar_visible(
        const ::blink::mojom::blink::WindowFeaturesPtr& input)
    {
        return input->tool_bar_visible;
    }

    static decltype(::blink::mojom::blink::WindowFeatures::location_bar_visible) location_bar_visible(
        const ::blink::mojom::blink::WindowFeaturesPtr& input)
    {
        return input->location_bar_visible;
    }

    static decltype(::blink::mojom::blink::WindowFeatures::scrollbars_visible) scrollbars_visible(
        const ::blink::mojom::blink::WindowFeaturesPtr& input)
    {
        return input->scrollbars_visible;
    }

    static decltype(::blink::mojom::blink::WindowFeatures::resizable) resizable(
        const ::blink::mojom::blink::WindowFeaturesPtr& input)
    {
        return input->resizable;
    }

    static decltype(::blink::mojom::blink::WindowFeatures::fullscreen) fullscreen(
        const ::blink::mojom::blink::WindowFeaturesPtr& input)
    {
        return input->fullscreen;
    }

    static decltype(::blink::mojom::blink::WindowFeatures::dialog) dialog(
        const ::blink::mojom::blink::WindowFeaturesPtr& input)
    {
        return input->dialog;
    }

    static bool Read(::blink::mojom::blink::WindowFeatures::DataView input, ::blink::mojom::blink::WindowFeaturesPtr* output);
};

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_WEB_WINDOW_FEATURES_MOJOM_BLINK_H_