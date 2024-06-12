// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_SELECTION_MOJOM_BLINK_H_
#define CC_IPC_SELECTION_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "cc/ipc/selection.mojom-shared.h"
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
#include "ui/gfx/mojo/selection_bound.mojom-blink.h"

#include "base/files/file.h"
#include "cc/output/begin_frame_args.h"
#include "cc/output/compositor_frame.h"
#include "cc/resources/returned_resource.h"
#include "cc/surfaces/frame_sink_id.h"
#include "cc/surfaces/local_frame_id.h"
#include "cc/surfaces/surface_id.h"
#include "cc/surfaces/surface_info.h"
#include "cc/surfaces/surface_sequence.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebSize.h"

namespace cc {
namespace mojom {
    namespace blink {
        class Selection;
        using SelectionPtr = mojo::StructPtr<Selection>;

        class Selection {
        public:
            using DataView = SelectionDataView;
            using Data_ = internal::Selection_Data;

            static SelectionPtr New();

            template <typename U>
            static SelectionPtr From(const U& u)
            {
                return mojo::TypeConverter<SelectionPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, Selection>::Convert(*this);
            }

            Selection();
            ~Selection();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = SelectionPtr>
            SelectionPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, Selection>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    Selection::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    Selection::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::gfx::mojom::blink::SelectionBoundPtr start;
            ::gfx::mojom::blink::SelectionBoundPtr end;
            bool is_editable;
            bool is_empty_text_form_control;

        private:
            DISALLOW_COPY_AND_ASSIGN(Selection);
        };

        template <typename StructPtrType>
        SelectionPtr Selection::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->start = mojo::internal::Clone(start);
            rv->end = mojo::internal::Clone(end);
            rv->is_editable = mojo::internal::Clone(is_editable);
            rv->is_empty_text_form_control = mojo::internal::Clone(is_empty_text_form_control);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, Selection>::value>::type*>
        bool Selection::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->start, other.start))
                return false;
            if (!mojo::internal::Equals(this->end, other.end))
                return false;
            if (!mojo::internal::Equals(this->is_editable, other.is_editable))
                return false;
            if (!mojo::internal::Equals(this->is_empty_text_form_control, other.is_empty_text_form_control))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::blink::Selection::DataView,
    ::cc::mojom::blink::SelectionPtr> {
    static bool IsNull(const ::cc::mojom::blink::SelectionPtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::SelectionPtr* output) { output->reset(); }

    static const decltype(::cc::mojom::blink::Selection::start)& start(
        const ::cc::mojom::blink::SelectionPtr& input)
    {
        return input->start;
    }

    static const decltype(::cc::mojom::blink::Selection::end)& end(
        const ::cc::mojom::blink::SelectionPtr& input)
    {
        return input->end;
    }

    static decltype(::cc::mojom::blink::Selection::is_editable) is_editable(
        const ::cc::mojom::blink::SelectionPtr& input)
    {
        return input->is_editable;
    }

    static decltype(::cc::mojom::blink::Selection::is_empty_text_form_control) is_empty_text_form_control(
        const ::cc::mojom::blink::SelectionPtr& input)
    {
        return input->is_empty_text_form_control;
    }

    static bool Read(::cc::mojom::blink::Selection::DataView input, ::cc::mojom::blink::SelectionPtr* output);
};

} // namespace mojo

#endif // CC_IPC_SELECTION_MOJOM_BLINK_H_