// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_GPU_INTERFACES_GPU_HOST_MOJOM_SHARED_H_
#define SERVICES_UI_GPU_INTERFACES_GPU_HOST_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "gpu/ipc/common/gpu_info.mojom-shared.h"
#include "gpu/ipc/common/surface_handle.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/ui/gpu/interfaces/context_lost_reason.mojom-shared.h"
#include "services/ui/gpu/interfaces/gpu_host.mojom-shared-internal.h"
#include "url/mojo/url.mojom-shared.h"

namespace ui {
namespace mojom {

} // namespace mojom
} // namespace ui

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace ui {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class GpuHostInterfaceBase {
    };

    using GpuHostPtrDataView = mojo::InterfacePtrDataView<GpuHostInterfaceBase>;
    using GpuHostRequestDataView = mojo::InterfaceRequestDataView<GpuHostInterfaceBase>;
    using GpuHostAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<GpuHostInterfaceBase>;
    using GpuHostAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<GpuHostInterfaceBase>;
    class GpuHost_DidInitialize_ParamsDataView {
    public:
        GpuHost_DidInitialize_ParamsDataView() { }

        GpuHost_DidInitialize_ParamsDataView(
            internal::GpuHost_DidInitialize_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetGpuInfoDataView(
            ::gpu::mojom::GpuInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGpuInfo(UserType* output)
        {
            auto* pointer = data_->gpu_info.Get();
            return mojo::internal::Deserialize<::gpu::mojom::GpuInfoDataView>(
                pointer, output, context_);
        }

    private:
        internal::GpuHost_DidInitialize_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class GpuHost_DidCreateOffscreenContext_ParamsDataView {
    public:
        GpuHost_DidCreateOffscreenContext_ParamsDataView() { }

        GpuHost_DidCreateOffscreenContext_ParamsDataView(
            internal::GpuHost_DidCreateOffscreenContext_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUrl(UserType* output)
        {
            auto* pointer = data_->url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }

    private:
        internal::GpuHost_DidCreateOffscreenContext_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class GpuHost_DidDestroyOffscreenContext_ParamsDataView {
    public:
        GpuHost_DidDestroyOffscreenContext_ParamsDataView() { }

        GpuHost_DidDestroyOffscreenContext_ParamsDataView(
            internal::GpuHost_DidDestroyOffscreenContext_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUrl(UserType* output)
        {
            auto* pointer = data_->url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }

    private:
        internal::GpuHost_DidDestroyOffscreenContext_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class GpuHost_DidDestroyChannel_ParamsDataView {
    public:
        GpuHost_DidDestroyChannel_ParamsDataView() { }

        GpuHost_DidDestroyChannel_ParamsDataView(
            internal::GpuHost_DidDestroyChannel_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t client_id() const
        {
            return data_->client_id;
        }

    private:
        internal::GpuHost_DidDestroyChannel_Params_Data* data_ = nullptr;
    };

    class GpuHost_DidLoseContext_ParamsDataView {
    public:
        GpuHost_DidLoseContext_ParamsDataView() { }

        GpuHost_DidLoseContext_ParamsDataView(
            internal::GpuHost_DidLoseContext_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        bool offscreen() const
        {
            return data_->offscreen;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReason(UserType* output) const
        {
            auto data_value = data_->reason;
            return mojo::internal::Deserialize<::ui::mojom::ContextLostReason>(
                data_value, output);
        }

        ::ui::mojom::ContextLostReason reason() const
        {
            return static_cast<::ui::mojom::ContextLostReason>(data_->reason);
        }
        inline void GetActiveUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadActiveUrl(UserType* output)
        {
            auto* pointer = data_->active_url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }

    private:
        internal::GpuHost_DidLoseContext_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class GpuHost_SetChildSurface_ParamsDataView {
    public:
        GpuHost_SetChildSurface_ParamsDataView() { }

        GpuHost_SetChildSurface_ParamsDataView(
            internal::GpuHost_SetChildSurface_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetParentDataView(
            ::gpu::mojom::SurfaceHandleDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadParent(UserType* output)
        {
            auto* pointer = data_->parent.Get();
            return mojo::internal::Deserialize<::gpu::mojom::SurfaceHandleDataView>(
                pointer, output, context_);
        }
        inline void GetChildDataView(
            ::gpu::mojom::SurfaceHandleDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadChild(UserType* output)
        {
            auto* pointer = data_->child.Get();
            return mojo::internal::Deserialize<::gpu::mojom::SurfaceHandleDataView>(
                pointer, output, context_);
        }

    private:
        internal::GpuHost_SetChildSurface_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class GpuHost_StoreShaderToDisk_ParamsDataView {
    public:
        GpuHost_StoreShaderToDisk_ParamsDataView() { }

        GpuHost_StoreShaderToDisk_ParamsDataView(
            internal::GpuHost_StoreShaderToDisk_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t client_id() const
        {
            return data_->client_id;
        }
        inline void GetKeyDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetShaderDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadShader(UserType* output)
        {
            auto* pointer = data_->shader.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::GpuHost_StoreShaderToDisk_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace ui

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace ui {
namespace mojom {

    inline void GpuHost_DidInitialize_ParamsDataView::GetGpuInfoDataView(
        ::gpu::mojom::GpuInfoDataView* output)
    {
        auto pointer = data_->gpu_info.Get();
        *output = ::gpu::mojom::GpuInfoDataView(pointer, context_);
    }

    inline void GpuHost_DidCreateOffscreenContext_ParamsDataView::GetUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }

    inline void GpuHost_DidDestroyOffscreenContext_ParamsDataView::GetUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }

    inline void GpuHost_DidLoseContext_ParamsDataView::GetActiveUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->active_url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }

    inline void GpuHost_SetChildSurface_ParamsDataView::GetParentDataView(
        ::gpu::mojom::SurfaceHandleDataView* output)
    {
        auto pointer = data_->parent.Get();
        *output = ::gpu::mojom::SurfaceHandleDataView(pointer, context_);
    }
    inline void GpuHost_SetChildSurface_ParamsDataView::GetChildDataView(
        ::gpu::mojom::SurfaceHandleDataView* output)
    {
        auto pointer = data_->child.Get();
        *output = ::gpu::mojom::SurfaceHandleDataView(pointer, context_);
    }

    inline void GpuHost_StoreShaderToDisk_ParamsDataView::GetKeyDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void GpuHost_StoreShaderToDisk_ParamsDataView::GetShaderDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->shader.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_GPU_INTERFACES_GPU_HOST_MOJOM_SHARED_H_
