// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_RENDER_PASS_MOJOM_BLINK_H_
#define CC_IPC_RENDER_PASS_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "cc/ipc/filter_operations.mojom-blink.h"
#include "cc/ipc/quads.mojom-blink.h"
#include "cc/ipc/render_pass.mojom-shared.h"
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
#include "ui/gfx/mojo/transform.mojom-blink.h"

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
        class RenderPass;
        using RenderPassPtr = mojo::StructPtr<RenderPass>;

        class RenderPass {
        public:
            using DataView = RenderPassDataView;
            using Data_ = internal::RenderPass_Data;

            static RenderPassPtr New();

            template <typename U>
            static RenderPassPtr From(const U& u)
            {
                return mojo::TypeConverter<RenderPassPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, RenderPass>::Convert(*this);
            }

            RenderPass();
            ~RenderPass();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = RenderPassPtr>
            RenderPassPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, RenderPass>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    RenderPass::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    RenderPass::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            int32_t id;
            ::gfx::mojom::blink::RectPtr output_rect;
            ::gfx::mojom::blink::RectPtr damage_rect;
            ::gfx::mojom::blink::TransformPtr transform_to_root_target;
            ::cc::mojom::blink::FilterOperationsPtr filters;
            ::cc::mojom::blink::FilterOperationsPtr background_filters;
            bool has_transparent_background;
            WTF::Vector<::cc::mojom::blink::DrawQuadPtr> quad_list;

        private:
            DISALLOW_COPY_AND_ASSIGN(RenderPass);
        };

        template <typename StructPtrType>
        RenderPassPtr RenderPass::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->id = mojo::internal::Clone(id);
            rv->output_rect = mojo::internal::Clone(output_rect);
            rv->damage_rect = mojo::internal::Clone(damage_rect);
            rv->transform_to_root_target = mojo::internal::Clone(transform_to_root_target);
            rv->filters = mojo::internal::Clone(filters);
            rv->background_filters = mojo::internal::Clone(background_filters);
            rv->has_transparent_background = mojo::internal::Clone(has_transparent_background);
            rv->quad_list = mojo::internal::Clone(quad_list);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, RenderPass>::value>::type*>
        bool RenderPass::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->id, other.id))
                return false;
            if (!mojo::internal::Equals(this->output_rect, other.output_rect))
                return false;
            if (!mojo::internal::Equals(this->damage_rect, other.damage_rect))
                return false;
            if (!mojo::internal::Equals(this->transform_to_root_target, other.transform_to_root_target))
                return false;
            if (!mojo::internal::Equals(this->filters, other.filters))
                return false;
            if (!mojo::internal::Equals(this->background_filters, other.background_filters))
                return false;
            if (!mojo::internal::Equals(this->has_transparent_background, other.has_transparent_background))
                return false;
            if (!mojo::internal::Equals(this->quad_list, other.quad_list))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::blink::RenderPass::DataView,
    ::cc::mojom::blink::RenderPassPtr> {
    static bool IsNull(const ::cc::mojom::blink::RenderPassPtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::RenderPassPtr* output) { output->reset(); }

    static decltype(::cc::mojom::blink::RenderPass::id) id(
        const ::cc::mojom::blink::RenderPassPtr& input)
    {
        return input->id;
    }

    static const decltype(::cc::mojom::blink::RenderPass::output_rect)& output_rect(
        const ::cc::mojom::blink::RenderPassPtr& input)
    {
        return input->output_rect;
    }

    static const decltype(::cc::mojom::blink::RenderPass::damage_rect)& damage_rect(
        const ::cc::mojom::blink::RenderPassPtr& input)
    {
        return input->damage_rect;
    }

    static const decltype(::cc::mojom::blink::RenderPass::transform_to_root_target)& transform_to_root_target(
        const ::cc::mojom::blink::RenderPassPtr& input)
    {
        return input->transform_to_root_target;
    }

    static const decltype(::cc::mojom::blink::RenderPass::filters)& filters(
        const ::cc::mojom::blink::RenderPassPtr& input)
    {
        return input->filters;
    }

    static const decltype(::cc::mojom::blink::RenderPass::background_filters)& background_filters(
        const ::cc::mojom::blink::RenderPassPtr& input)
    {
        return input->background_filters;
    }

    static decltype(::cc::mojom::blink::RenderPass::has_transparent_background) has_transparent_background(
        const ::cc::mojom::blink::RenderPassPtr& input)
    {
        return input->has_transparent_background;
    }

    static const decltype(::cc::mojom::blink::RenderPass::quad_list)& quad_list(
        const ::cc::mojom::blink::RenderPassPtr& input)
    {
        return input->quad_list;
    }

    static bool Read(::cc::mojom::blink::RenderPass::DataView input, ::cc::mojom::blink::RenderPassPtr* output);
};

} // namespace mojo

#endif // CC_IPC_RENDER_PASS_MOJOM_BLINK_H_