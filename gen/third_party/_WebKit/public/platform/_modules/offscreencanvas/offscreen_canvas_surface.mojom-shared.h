// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_OFFSCREENCANVAS_OFFSCREEN_CANVAS_SURFACE_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_OFFSCREENCANVAS_OFFSCREEN_CANVAS_SURFACE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/compositor_frame.mojom-shared.h"
#include "cc/ipc/frame_sink_id.mojom-shared.h"
#include "cc/ipc/mojo_compositor_frame_sink.mojom-shared.h"
#include "cc/ipc/surface_id.mojom-shared.h"
#include "cc/ipc/surface_info.mojom-shared.h"
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
#include "third_party/WebKit/public/platform/modules/offscreencanvas/offscreen_canvas_surface.mojom-shared-internal.h"

namespace blink {
namespace mojom {

} // namespace mojom
} // namespace blink

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace blink {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class OffscreenCanvasSurfaceInterfaceBase {
    };

    using OffscreenCanvasSurfacePtrDataView = mojo::InterfacePtrDataView<OffscreenCanvasSurfaceInterfaceBase>;
    using OffscreenCanvasSurfaceRequestDataView = mojo::InterfaceRequestDataView<OffscreenCanvasSurfaceInterfaceBase>;
    using OffscreenCanvasSurfaceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<OffscreenCanvasSurfaceInterfaceBase>;
    using OffscreenCanvasSurfaceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<OffscreenCanvasSurfaceInterfaceBase>;
    class OffscreenCanvasSurfaceClientInterfaceBase {
    };

    using OffscreenCanvasSurfaceClientPtrDataView = mojo::InterfacePtrDataView<OffscreenCanvasSurfaceClientInterfaceBase>;
    using OffscreenCanvasSurfaceClientRequestDataView = mojo::InterfaceRequestDataView<OffscreenCanvasSurfaceClientInterfaceBase>;
    using OffscreenCanvasSurfaceClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<OffscreenCanvasSurfaceClientInterfaceBase>;
    using OffscreenCanvasSurfaceClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<OffscreenCanvasSurfaceClientInterfaceBase>;
    class OffscreenCanvasSurfaceFactoryInterfaceBase {
    };

    using OffscreenCanvasSurfaceFactoryPtrDataView = mojo::InterfacePtrDataView<OffscreenCanvasSurfaceFactoryInterfaceBase>;
    using OffscreenCanvasSurfaceFactoryRequestDataView = mojo::InterfaceRequestDataView<OffscreenCanvasSurfaceFactoryInterfaceBase>;
    using OffscreenCanvasSurfaceFactoryAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<OffscreenCanvasSurfaceFactoryInterfaceBase>;
    using OffscreenCanvasSurfaceFactoryAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<OffscreenCanvasSurfaceFactoryInterfaceBase>;
    class OffscreenCanvasCompositorFrameSinkProviderInterfaceBase {
    };

    using OffscreenCanvasCompositorFrameSinkProviderPtrDataView = mojo::InterfacePtrDataView<OffscreenCanvasCompositorFrameSinkProviderInterfaceBase>;
    using OffscreenCanvasCompositorFrameSinkProviderRequestDataView = mojo::InterfaceRequestDataView<OffscreenCanvasCompositorFrameSinkProviderInterfaceBase>;
    using OffscreenCanvasCompositorFrameSinkProviderAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<OffscreenCanvasCompositorFrameSinkProviderInterfaceBase>;
    using OffscreenCanvasCompositorFrameSinkProviderAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<OffscreenCanvasCompositorFrameSinkProviderInterfaceBase>;
    class OffscreenCanvasSurface_Require_ParamsDataView {
    public:
        OffscreenCanvasSurface_Require_ParamsDataView() { }

        OffscreenCanvasSurface_Require_ParamsDataView(
            internal::OffscreenCanvasSurface_Require_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSurfaceIdDataView(
            ::cc::mojom::SurfaceIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSurfaceId(UserType* output)
        {
            auto* pointer = data_->surface_id.Get();
            return mojo::internal::Deserialize<::cc::mojom::SurfaceIdDataView>(
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
        internal::OffscreenCanvasSurface_Require_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class OffscreenCanvasSurface_Satisfy_ParamsDataView {
    public:
        OffscreenCanvasSurface_Satisfy_ParamsDataView() { }

        OffscreenCanvasSurface_Satisfy_ParamsDataView(
            internal::OffscreenCanvasSurface_Satisfy_Params_Data* data,
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
        internal::OffscreenCanvasSurface_Satisfy_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class OffscreenCanvasSurfaceClient_OnSurfaceCreated_ParamsDataView {
    public:
        OffscreenCanvasSurfaceClient_OnSurfaceCreated_ParamsDataView() { }

        OffscreenCanvasSurfaceClient_OnSurfaceCreated_ParamsDataView(
            internal::OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSurfaceInfoDataView(
            ::cc::mojom::SurfaceInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSurfaceInfo(UserType* output)
        {
            auto* pointer = data_->surface_info.Get();
            return mojo::internal::Deserialize<::cc::mojom::SurfaceInfoDataView>(
                pointer, output, context_);
        }

    private:
        internal::OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_ParamsDataView {
    public:
        OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_ParamsDataView() { }

        OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_ParamsDataView(
            internal::OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFrameSinkIdDataView(
            ::cc::mojom::FrameSinkIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFrameSinkId(UserType* output)
        {
            auto* pointer = data_->frame_sink_id.Get();
            return mojo::internal::Deserialize<::cc::mojom::FrameSinkIdDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::blink::mojom::OffscreenCanvasSurfaceClientPtrDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeService()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::blink::mojom::OffscreenCanvasSurfaceRequestDataView>(
                &data_->service, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_ParamsDataView {
    public:
        OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_ParamsDataView() { }

        OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_ParamsDataView(
            internal::OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFrameSinkIdDataView(
            ::cc::mojom::FrameSinkIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFrameSinkId(UserType* output)
        {
            auto* pointer = data_->frame_sink_id.Get();
            return mojo::internal::Deserialize<::cc::mojom::FrameSinkIdDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::cc::mojom::MojoCompositorFrameSinkClientPtrDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeSink()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::cc::mojom::MojoCompositorFrameSinkRequestDataView>(
                &data_->sink, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace blink {
namespace mojom {

    inline void OffscreenCanvasSurface_Require_ParamsDataView::GetSurfaceIdDataView(
        ::cc::mojom::SurfaceIdDataView* output)
    {
        auto pointer = data_->surface_id.Get();
        *output = ::cc::mojom::SurfaceIdDataView(pointer, context_);
    }
    inline void OffscreenCanvasSurface_Require_ParamsDataView::GetSequenceDataView(
        ::cc::mojom::SurfaceSequenceDataView* output)
    {
        auto pointer = data_->sequence.Get();
        *output = ::cc::mojom::SurfaceSequenceDataView(pointer, context_);
    }

    inline void OffscreenCanvasSurface_Satisfy_ParamsDataView::GetSequenceDataView(
        ::cc::mojom::SurfaceSequenceDataView* output)
    {
        auto pointer = data_->sequence.Get();
        *output = ::cc::mojom::SurfaceSequenceDataView(pointer, context_);
    }

    inline void OffscreenCanvasSurfaceClient_OnSurfaceCreated_ParamsDataView::GetSurfaceInfoDataView(
        ::cc::mojom::SurfaceInfoDataView* output)
    {
        auto pointer = data_->surface_info.Get();
        *output = ::cc::mojom::SurfaceInfoDataView(pointer, context_);
    }

    inline void OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_ParamsDataView::GetFrameSinkIdDataView(
        ::cc::mojom::FrameSinkIdDataView* output)
    {
        auto pointer = data_->frame_sink_id.Get();
        *output = ::cc::mojom::FrameSinkIdDataView(pointer, context_);
    }

    inline void OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_ParamsDataView::GetFrameSinkIdDataView(
        ::cc::mojom::FrameSinkIdDataView* output)
    {
        auto pointer = data_->frame_sink_id.Get();
        *output = ::cc::mojom::FrameSinkIdDataView(pointer, context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_OFFSCREENCANVAS_OFFSCREEN_CANVAS_SURFACE_MOJOM_SHARED_H_
