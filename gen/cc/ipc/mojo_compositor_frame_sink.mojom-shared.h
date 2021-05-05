// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_MOJO_COMPOSITOR_FRAME_SINK_MOJOM_SHARED_H_
#define CC_IPC_MOJO_COMPOSITOR_FRAME_SINK_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/begin_frame_args.mojom-shared.h"
#include "cc/ipc/compositor_frame.mojom-shared.h"
#include "cc/ipc/frame_sink_id.mojom-shared.h"
#include "cc/ipc/local_frame_id.mojom-shared.h"
#include "cc/ipc/mojo_compositor_frame_sink.mojom-shared-internal.h"
#include "cc/ipc/returned_resource.mojom-shared.h"
#include "cc/ipc/surface_reference.mojom-shared.h"
#include "cc/ipc/surface_sequence.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace cc {
namespace mojom {

} // namespace mojom
} // namespace cc

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace cc {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class MojoCompositorFrameSinkInterfaceBase {
    };

    using MojoCompositorFrameSinkPtrDataView = mojo::InterfacePtrDataView<MojoCompositorFrameSinkInterfaceBase>;
    using MojoCompositorFrameSinkRequestDataView = mojo::InterfaceRequestDataView<MojoCompositorFrameSinkInterfaceBase>;
    using MojoCompositorFrameSinkAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<MojoCompositorFrameSinkInterfaceBase>;
    using MojoCompositorFrameSinkAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<MojoCompositorFrameSinkInterfaceBase>;
    class MojoCompositorFrameSinkClientInterfaceBase {
    };

    using MojoCompositorFrameSinkClientPtrDataView = mojo::InterfacePtrDataView<MojoCompositorFrameSinkClientInterfaceBase>;
    using MojoCompositorFrameSinkClientRequestDataView = mojo::InterfaceRequestDataView<MojoCompositorFrameSinkClientInterfaceBase>;
    using MojoCompositorFrameSinkClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<MojoCompositorFrameSinkClientInterfaceBase>;
    using MojoCompositorFrameSinkClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<MojoCompositorFrameSinkClientInterfaceBase>;
    class MojoCompositorFrameSinkPrivateInterfaceBase {
    };

    using MojoCompositorFrameSinkPrivatePtrDataView = mojo::InterfacePtrDataView<MojoCompositorFrameSinkPrivateInterfaceBase>;
    using MojoCompositorFrameSinkPrivateRequestDataView = mojo::InterfaceRequestDataView<MojoCompositorFrameSinkPrivateInterfaceBase>;
    using MojoCompositorFrameSinkPrivateAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<MojoCompositorFrameSinkPrivateInterfaceBase>;
    using MojoCompositorFrameSinkPrivateAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<MojoCompositorFrameSinkPrivateInterfaceBase>;
    class MojoCompositorFrameSink_SetNeedsBeginFrame_ParamsDataView {
    public:
        MojoCompositorFrameSink_SetNeedsBeginFrame_ParamsDataView() { }

        MojoCompositorFrameSink_SetNeedsBeginFrame_ParamsDataView(
            internal::MojoCompositorFrameSink_SetNeedsBeginFrame_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool needs_begin_frame() const
        {
            return data_->needs_begin_frame;
        }

    private:
        internal::MojoCompositorFrameSink_SetNeedsBeginFrame_Params_Data* data_ = nullptr;
    };

    class MojoCompositorFrameSink_SubmitCompositorFrame_ParamsDataView {
    public:
        MojoCompositorFrameSink_SubmitCompositorFrame_ParamsDataView() { }

        MojoCompositorFrameSink_SubmitCompositorFrame_ParamsDataView(
            internal::MojoCompositorFrameSink_SubmitCompositorFrame_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetLocalFrameIdDataView(
            ::cc::mojom::LocalFrameIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLocalFrameId(UserType* output)
        {
            auto* pointer = data_->local_frame_id.Get();
            return mojo::internal::Deserialize<::cc::mojom::LocalFrameIdDataView>(
                pointer, output, context_);
        }
        inline void GetFrameDataView(
            ::cc::mojom::CompositorFrameDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFrame(UserType* output)
        {
            auto* pointer = data_->frame.Get();
            return mojo::internal::Deserialize<::cc::mojom::CompositorFrameDataView>(
                pointer, output, context_);
        }

    private:
        internal::MojoCompositorFrameSink_SubmitCompositorFrame_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class MojoCompositorFrameSink_EvictFrame_ParamsDataView {
    public:
        MojoCompositorFrameSink_EvictFrame_ParamsDataView() { }

        MojoCompositorFrameSink_EvictFrame_ParamsDataView(
            internal::MojoCompositorFrameSink_EvictFrame_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::MojoCompositorFrameSink_EvictFrame_Params_Data* data_ = nullptr;
    };

    class MojoCompositorFrameSink_Require_ParamsDataView {
    public:
        MojoCompositorFrameSink_Require_ParamsDataView() { }

        MojoCompositorFrameSink_Require_ParamsDataView(
            internal::MojoCompositorFrameSink_Require_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetLocalFrameIdDataView(
            ::cc::mojom::LocalFrameIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLocalFrameId(UserType* output)
        {
            auto* pointer = data_->local_frame_id.Get();
            return mojo::internal::Deserialize<::cc::mojom::LocalFrameIdDataView>(
                pointer, output, context_);
        }
        inline void GetSequenceDataView(
            ::cc::mojom::SurfaceSequenceDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSequence(UserType* output)
        {
            auto* pointer = data_->sequence.Get();
            return mojo::internal::Deserialize<::cc::mojom::SurfaceSequenceDataView>(
                pointer, output, context_);
        }

    private:
        internal::MojoCompositorFrameSink_Require_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class MojoCompositorFrameSink_Satisfy_ParamsDataView {
    public:
        MojoCompositorFrameSink_Satisfy_ParamsDataView() { }

        MojoCompositorFrameSink_Satisfy_ParamsDataView(
            internal::MojoCompositorFrameSink_Satisfy_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSequenceDataView(
            ::cc::mojom::SurfaceSequenceDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSequence(UserType* output)
        {
            auto* pointer = data_->sequence.Get();
            return mojo::internal::Deserialize<::cc::mojom::SurfaceSequenceDataView>(
                pointer, output, context_);
        }

    private:
        internal::MojoCompositorFrameSink_Satisfy_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_ParamsDataView {
    public:
        MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_ParamsDataView() { }

        MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_ParamsDataView(
            internal::MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params_Data* data_ = nullptr;
    };

    class MojoCompositorFrameSinkClient_OnBeginFrame_ParamsDataView {
    public:
        MojoCompositorFrameSinkClient_OnBeginFrame_ParamsDataView() { }

        MojoCompositorFrameSinkClient_OnBeginFrame_ParamsDataView(
            internal::MojoCompositorFrameSinkClient_OnBeginFrame_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetArgsDataView(
            ::cc::mojom::BeginFrameArgsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadArgs(UserType* output)
        {
            auto* pointer = data_->args.Get();
            return mojo::internal::Deserialize<::cc::mojom::BeginFrameArgsDataView>(
                pointer, output, context_);
        }

    private:
        internal::MojoCompositorFrameSinkClient_OnBeginFrame_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class MojoCompositorFrameSinkClient_ReclaimResources_ParamsDataView {
    public:
        MojoCompositorFrameSinkClient_ReclaimResources_ParamsDataView() { }

        MojoCompositorFrameSinkClient_ReclaimResources_ParamsDataView(
            internal::MojoCompositorFrameSinkClient_ReclaimResources_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetResourcesDataView(
            ::cc::mojom::ReturnedResourceArrayDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResources(UserType* output)
        {
            auto* pointer = data_->resources.Get();
            return mojo::internal::Deserialize<::cc::mojom::ReturnedResourceArrayDataView>(
                pointer, output, context_);
        }

    private:
        internal::MojoCompositorFrameSinkClient_ReclaimResources_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class MojoCompositorFrameSinkClient_WillDrawSurface_ParamsDataView {
    public:
        MojoCompositorFrameSinkClient_WillDrawSurface_ParamsDataView() { }

        MojoCompositorFrameSinkClient_WillDrawSurface_ParamsDataView(
            internal::MojoCompositorFrameSinkClient_WillDrawSurface_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::MojoCompositorFrameSinkClient_WillDrawSurface_Params_Data* data_ = nullptr;
    };

    class MojoCompositorFrameSinkPrivate_AddChildFrameSink_ParamsDataView {
    public:
        MojoCompositorFrameSinkPrivate_AddChildFrameSink_ParamsDataView() { }

        MojoCompositorFrameSinkPrivate_AddChildFrameSink_ParamsDataView(
            internal::MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetChildFrameSinkIdDataView(
            ::cc::mojom::FrameSinkIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadChildFrameSinkId(UserType* output)
        {
            auto* pointer = data_->child_frame_sink_id.Get();
            return mojo::internal::Deserialize<::cc::mojom::FrameSinkIdDataView>(
                pointer, output, context_);
        }

    private:
        internal::MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_ParamsDataView {
    public:
        MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_ParamsDataView() { }

        MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_ParamsDataView(
            internal::MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetChildFrameSinkIdDataView(
            ::cc::mojom::FrameSinkIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadChildFrameSinkId(UserType* output)
        {
            auto* pointer = data_->child_frame_sink_id.Get();
            return mojo::internal::Deserialize<::cc::mojom::FrameSinkIdDataView>(
                pointer, output, context_);
        }

    private:
        internal::MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace cc

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace cc {
namespace mojom {

    inline void MojoCompositorFrameSink_SubmitCompositorFrame_ParamsDataView::GetLocalFrameIdDataView(
        ::cc::mojom::LocalFrameIdDataView* output)
    {
        auto pointer = data_->local_frame_id.Get();
        *output = ::cc::mojom::LocalFrameIdDataView(pointer, context_);
    }
    inline void MojoCompositorFrameSink_SubmitCompositorFrame_ParamsDataView::GetFrameDataView(
        ::cc::mojom::CompositorFrameDataView* output)
    {
        auto pointer = data_->frame.Get();
        *output = ::cc::mojom::CompositorFrameDataView(pointer, context_);
    }

    inline void MojoCompositorFrameSink_Require_ParamsDataView::GetLocalFrameIdDataView(
        ::cc::mojom::LocalFrameIdDataView* output)
    {
        auto pointer = data_->local_frame_id.Get();
        *output = ::cc::mojom::LocalFrameIdDataView(pointer, context_);
    }
    inline void MojoCompositorFrameSink_Require_ParamsDataView::GetSequenceDataView(
        ::cc::mojom::SurfaceSequenceDataView* output)
    {
        auto pointer = data_->sequence.Get();
        *output = ::cc::mojom::SurfaceSequenceDataView(pointer, context_);
    }

    inline void MojoCompositorFrameSink_Satisfy_ParamsDataView::GetSequenceDataView(
        ::cc::mojom::SurfaceSequenceDataView* output)
    {
        auto pointer = data_->sequence.Get();
        *output = ::cc::mojom::SurfaceSequenceDataView(pointer, context_);
    }

    inline void MojoCompositorFrameSinkClient_OnBeginFrame_ParamsDataView::GetArgsDataView(
        ::cc::mojom::BeginFrameArgsDataView* output)
    {
        auto pointer = data_->args.Get();
        *output = ::cc::mojom::BeginFrameArgsDataView(pointer, context_);
    }

    inline void MojoCompositorFrameSinkClient_ReclaimResources_ParamsDataView::GetResourcesDataView(
        ::cc::mojom::ReturnedResourceArrayDataView* output)
    {
        auto pointer = data_->resources.Get();
        *output = ::cc::mojom::ReturnedResourceArrayDataView(pointer, context_);
    }

    inline void MojoCompositorFrameSinkPrivate_AddChildFrameSink_ParamsDataView::GetChildFrameSinkIdDataView(
        ::cc::mojom::FrameSinkIdDataView* output)
    {
        auto pointer = data_->child_frame_sink_id.Get();
        *output = ::cc::mojom::FrameSinkIdDataView(pointer, context_);
    }

    inline void MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_ParamsDataView::GetChildFrameSinkIdDataView(
        ::cc::mojom::FrameSinkIdDataView* output)
    {
        auto pointer = data_->child_frame_sink_id.Get();
        *output = ::cc::mojom::FrameSinkIdDataView(pointer, context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_MOJO_COMPOSITOR_FRAME_SINK_MOJOM_SHARED_H_
