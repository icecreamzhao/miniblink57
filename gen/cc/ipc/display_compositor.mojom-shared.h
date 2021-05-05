// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_DISPLAY_COMPOSITOR_MOJOM_SHARED_H_
#define CC_IPC_DISPLAY_COMPOSITOR_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/display_compositor.mojom-shared-internal.h"
#include "cc/ipc/frame_sink_id.mojom-shared.h"
#include "cc/ipc/mojo_compositor_frame_sink.mojom-shared.h"
#include "cc/ipc/surface_id.mojom-shared.h"
#include "cc/ipc/surface_info.mojom-shared.h"
#include "gpu/ipc/common/surface_handle.mojom-shared.h"
#include "mojo/common/time.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"
#include "ui/gfx/mojo/color_space.mojom-shared.h"

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
    class DisplayPrivateInterfaceBase {
    };

    using DisplayPrivatePtrDataView = mojo::InterfacePtrDataView<DisplayPrivateInterfaceBase>;
    using DisplayPrivateRequestDataView = mojo::InterfaceRequestDataView<DisplayPrivateInterfaceBase>;
    using DisplayPrivateAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<DisplayPrivateInterfaceBase>;
    using DisplayPrivateAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<DisplayPrivateInterfaceBase>;
    class DisplayCompositorInterfaceBase {
    };

    using DisplayCompositorPtrDataView = mojo::InterfacePtrDataView<DisplayCompositorInterfaceBase>;
    using DisplayCompositorRequestDataView = mojo::InterfaceRequestDataView<DisplayCompositorInterfaceBase>;
    using DisplayCompositorAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<DisplayCompositorInterfaceBase>;
    using DisplayCompositorAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<DisplayCompositorInterfaceBase>;
    class DisplayCompositorClientInterfaceBase {
    };

    using DisplayCompositorClientPtrDataView = mojo::InterfacePtrDataView<DisplayCompositorClientInterfaceBase>;
    using DisplayCompositorClientRequestDataView = mojo::InterfaceRequestDataView<DisplayCompositorClientInterfaceBase>;
    using DisplayCompositorClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<DisplayCompositorClientInterfaceBase>;
    using DisplayCompositorClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<DisplayCompositorClientInterfaceBase>;
    class DisplayPrivate_SetDisplayVisible_ParamsDataView {
    public:
        DisplayPrivate_SetDisplayVisible_ParamsDataView() { }

        DisplayPrivate_SetDisplayVisible_ParamsDataView(
            internal::DisplayPrivate_SetDisplayVisible_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool visible() const
        {
            return data_->visible;
        }

    private:
        internal::DisplayPrivate_SetDisplayVisible_Params_Data* data_ = nullptr;
    };

    class DisplayPrivate_ResizeDisplay_ParamsDataView {
    public:
        DisplayPrivate_ResizeDisplay_ParamsDataView() { }

        DisplayPrivate_ResizeDisplay_ParamsDataView(
            internal::DisplayPrivate_ResizeDisplay_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSizeInPixelDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSizeInPixel(UserType* output)
        {
            auto* pointer = data_->size_in_pixel.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }

    private:
        internal::DisplayPrivate_ResizeDisplay_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DisplayPrivate_SetDisplayColorSpace_ParamsDataView {
    public:
        DisplayPrivate_SetDisplayColorSpace_ParamsDataView() { }

        DisplayPrivate_SetDisplayColorSpace_ParamsDataView(
            internal::DisplayPrivate_SetDisplayColorSpace_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetColorSpaceDataView(
            ::gfx::mojom::ColorSpaceDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadColorSpace(UserType* output)
        {
            auto* pointer = data_->color_space.Get();
            return mojo::internal::Deserialize<::gfx::mojom::ColorSpaceDataView>(
                pointer, output, context_);
        }

    private:
        internal::DisplayPrivate_SetDisplayColorSpace_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DisplayPrivate_SetOutputIsSecure_ParamsDataView {
    public:
        DisplayPrivate_SetOutputIsSecure_ParamsDataView() { }

        DisplayPrivate_SetOutputIsSecure_ParamsDataView(
            internal::DisplayPrivate_SetOutputIsSecure_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool secure() const
        {
            return data_->secure;
        }

    private:
        internal::DisplayPrivate_SetOutputIsSecure_Params_Data* data_ = nullptr;
    };

    class DisplayCompositor_CreateDisplayCompositorFrameSink_ParamsDataView {
    public:
        DisplayCompositor_CreateDisplayCompositorFrameSink_ParamsDataView() { }

        DisplayCompositor_CreateDisplayCompositorFrameSink_ParamsDataView(
            internal::DisplayCompositor_CreateDisplayCompositorFrameSink_Params_Data* data,
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
        inline void GetWidgetDataView(
            ::gpu::mojom::SurfaceHandleDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadWidget(UserType* output)
        {
            auto* pointer = data_->widget.Get();
            return mojo::internal::Deserialize<::gpu::mojom::SurfaceHandleDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeCompositorFrameSink()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::cc::mojom::MojoCompositorFrameSinkRequestDataView>(
                &data_->compositor_frame_sink, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeCompositorFrameSinkPrivate()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::cc::mojom::MojoCompositorFrameSinkPrivateRequestDataView>(
                &data_->compositor_frame_sink_private, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeCompositorFrameSinkClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::cc::mojom::MojoCompositorFrameSinkClientPtrDataView>(
                &data_->compositor_frame_sink_client, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeDisplayPrivate()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::cc::mojom::DisplayPrivateRequestDataView>(
                &data_->display_private, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::DisplayCompositor_CreateDisplayCompositorFrameSink_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DisplayCompositor_CreateOffscreenCompositorFrameSink_ParamsDataView {
    public:
        DisplayCompositor_CreateOffscreenCompositorFrameSink_ParamsDataView() { }

        DisplayCompositor_CreateOffscreenCompositorFrameSink_ParamsDataView(
            internal::DisplayCompositor_CreateOffscreenCompositorFrameSink_Params_Data* data,
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
        UserType TakeCompositorFrameSink()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::cc::mojom::MojoCompositorFrameSinkRequestDataView>(
                &data_->compositor_frame_sink, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeCompositorFrameSinkPrivate()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::cc::mojom::MojoCompositorFrameSinkPrivateRequestDataView>(
                &data_->compositor_frame_sink_private, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeCompositorFrameSinkClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::cc::mojom::MojoCompositorFrameSinkClientPtrDataView>(
                &data_->compositor_frame_sink_client, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::DisplayCompositor_CreateOffscreenCompositorFrameSink_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DisplayCompositorClient_OnSurfaceCreated_ParamsDataView {
    public:
        DisplayCompositorClient_OnSurfaceCreated_ParamsDataView() { }

        DisplayCompositorClient_OnSurfaceCreated_ParamsDataView(
            internal::DisplayCompositorClient_OnSurfaceCreated_Params_Data* data,
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
        internal::DisplayCompositorClient_OnSurfaceCreated_Params_Data* data_ = nullptr;
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

    inline void DisplayPrivate_ResizeDisplay_ParamsDataView::GetSizeInPixelDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->size_in_pixel.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }

    inline void DisplayPrivate_SetDisplayColorSpace_ParamsDataView::GetColorSpaceDataView(
        ::gfx::mojom::ColorSpaceDataView* output)
    {
        auto pointer = data_->color_space.Get();
        *output = ::gfx::mojom::ColorSpaceDataView(pointer, context_);
    }

    inline void DisplayCompositor_CreateDisplayCompositorFrameSink_ParamsDataView::GetFrameSinkIdDataView(
        ::cc::mojom::FrameSinkIdDataView* output)
    {
        auto pointer = data_->frame_sink_id.Get();
        *output = ::cc::mojom::FrameSinkIdDataView(pointer, context_);
    }
    inline void DisplayCompositor_CreateDisplayCompositorFrameSink_ParamsDataView::GetWidgetDataView(
        ::gpu::mojom::SurfaceHandleDataView* output)
    {
        auto pointer = data_->widget.Get();
        *output = ::gpu::mojom::SurfaceHandleDataView(pointer, context_);
    }

    inline void DisplayCompositor_CreateOffscreenCompositorFrameSink_ParamsDataView::GetFrameSinkIdDataView(
        ::cc::mojom::FrameSinkIdDataView* output)
    {
        auto pointer = data_->frame_sink_id.Get();
        *output = ::cc::mojom::FrameSinkIdDataView(pointer, context_);
    }

    inline void DisplayCompositorClient_OnSurfaceCreated_ParamsDataView::GetSurfaceInfoDataView(
        ::cc::mojom::SurfaceInfoDataView* output)
    {
        auto pointer = data_->surface_info.Get();
        *output = ::cc::mojom::SurfaceInfoDataView(pointer, context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_DISPLAY_COMPOSITOR_MOJOM_SHARED_H_
