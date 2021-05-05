// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_MOJO_SELECTION_BOUND_MOJOM_BLINK_H_
#define UI_GFX_MOJO_SELECTION_BOUND_MOJOM_BLINK_H_

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
#include "ui/gfx/geometry/mojo/geometry.mojom-blink.h"
#include "ui/gfx/mojo/selection_bound.mojom-shared.h"

#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebSize.h"

namespace gfx {
namespace mojom {
    namespace blink {
        using SelectionBoundType = SelectionBoundType; // Alias for definition in the parent namespace.
        class SelectionBound;
        using SelectionBoundPtr = mojo::StructPtr<SelectionBound>;

        class SelectionBound {
        public:
            using DataView = SelectionBoundDataView;
            using Data_ = internal::SelectionBound_Data;

            static SelectionBoundPtr New();

            template <typename U>
            static SelectionBoundPtr From(const U& u)
            {
                return mojo::TypeConverter<SelectionBoundPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, SelectionBound>::Convert(*this);
            }

            SelectionBound();
            ~SelectionBound();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = SelectionBoundPtr>
            SelectionBoundPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, SelectionBound>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    SelectionBound::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    SelectionBound::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            SelectionBoundType type;
            ::gfx::mojom::blink::PointFPtr edge_top;
            ::gfx::mojom::blink::PointFPtr edge_bottom;
            bool visible;

        private:
            DISALLOW_COPY_AND_ASSIGN(SelectionBound);
        };

        template <typename StructPtrType>
        SelectionBoundPtr SelectionBound::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->type = mojo::internal::Clone(type);
            rv->edge_top = mojo::internal::Clone(edge_top);
            rv->edge_bottom = mojo::internal::Clone(edge_bottom);
            rv->visible = mojo::internal::Clone(visible);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, SelectionBound>::value>::type*>
        bool SelectionBound::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->type, other.type))
                return false;
            if (!mojo::internal::Equals(this->edge_top, other.edge_top))
                return false;
            if (!mojo::internal::Equals(this->edge_bottom, other.edge_bottom))
                return false;
            if (!mojo::internal::Equals(this->visible, other.visible))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace gfx

namespace mojo {

template <>
struct StructTraits<::gfx::mojom::blink::SelectionBound::DataView,
    ::gfx::mojom::blink::SelectionBoundPtr> {
    static bool IsNull(const ::gfx::mojom::blink::SelectionBoundPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::blink::SelectionBoundPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::blink::SelectionBound::type) type(
        const ::gfx::mojom::blink::SelectionBoundPtr& input)
    {
        return input->type;
    }

    static const decltype(::gfx::mojom::blink::SelectionBound::edge_top)& edge_top(
        const ::gfx::mojom::blink::SelectionBoundPtr& input)
    {
        return input->edge_top;
    }

    static const decltype(::gfx::mojom::blink::SelectionBound::edge_bottom)& edge_bottom(
        const ::gfx::mojom::blink::SelectionBoundPtr& input)
    {
        return input->edge_bottom;
    }

    static decltype(::gfx::mojom::blink::SelectionBound::visible) visible(
        const ::gfx::mojom::blink::SelectionBoundPtr& input)
    {
        return input->visible;
    }

    static bool Read(::gfx::mojom::blink::SelectionBound::DataView input, ::gfx::mojom::blink::SelectionBoundPtr* output);
};

} // namespace mojo

#endif // UI_GFX_MOJO_SELECTION_BOUND_MOJOM_BLINK_H_