// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_MOJO_ACCELERATED_WIDGET_MOJOM_BLINK_H_
#define UI_GFX_MOJO_ACCELERATED_WIDGET_MOJOM_BLINK_H_

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
#include "ui/gfx/mojo/accelerated_widget.mojom-shared.h"

#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebSize.h"

namespace gfx {
namespace mojom {
    namespace blink {
        class AcceleratedWidget;
        using AcceleratedWidgetPtr = mojo::InlinedStructPtr<AcceleratedWidget>;

        class AcceleratedWidget {
        public:
            using DataView = AcceleratedWidgetDataView;
            using Data_ = internal::AcceleratedWidget_Data;

            static AcceleratedWidgetPtr New();

            template <typename U>
            static AcceleratedWidgetPtr From(const U& u)
            {
                return mojo::TypeConverter<AcceleratedWidgetPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, AcceleratedWidget>::Convert(*this);
            }

            AcceleratedWidget();
            ~AcceleratedWidget();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = AcceleratedWidgetPtr>
            AcceleratedWidgetPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, AcceleratedWidget>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    AcceleratedWidget::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    AcceleratedWidget::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            uint64_t widget;
        };

        template <typename StructPtrType>
        AcceleratedWidgetPtr AcceleratedWidget::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->widget = mojo::internal::Clone(widget);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, AcceleratedWidget>::value>::type*>
        bool AcceleratedWidget::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->widget, other.widget))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace gfx

namespace mojo {

template <>
struct StructTraits<::gfx::mojom::blink::AcceleratedWidget::DataView,
    ::gfx::mojom::blink::AcceleratedWidgetPtr> {
    static bool IsNull(const ::gfx::mojom::blink::AcceleratedWidgetPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::blink::AcceleratedWidgetPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::blink::AcceleratedWidget::widget) widget(
        const ::gfx::mojom::blink::AcceleratedWidgetPtr& input)
    {
        return input->widget;
    }

    static bool Read(::gfx::mojom::blink::AcceleratedWidget::DataView input, ::gfx::mojom::blink::AcceleratedWidgetPtr* output);
};

} // namespace mojo

#endif // UI_GFX_MOJO_ACCELERATED_WIDGET_MOJOM_BLINK_H_