// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_GPU_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_GPU_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "gpu/ipc/common/gpu_info.mojom-shared.h"
#include "gpu/ipc/common/sync_token.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/ui/public/interfaces/gpu.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"
#include "ui/gfx/mojo/buffer_types.mojom-shared.h"

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
    class GpuInterfaceBase {
    };

    using GpuPtrDataView = mojo::InterfacePtrDataView<GpuInterfaceBase>;
    using GpuRequestDataView = mojo::InterfaceRequestDataView<GpuInterfaceBase>;
    using GpuAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<GpuInterfaceBase>;
    using GpuAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<GpuInterfaceBase>;
    class Gpu_EstablishGpuChannel_ParamsDataView {
    public:
        Gpu_EstablishGpuChannel_ParamsDataView() { }

        Gpu_EstablishGpuChannel_ParamsDataView(
            internal::Gpu_EstablishGpuChannel_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Gpu_EstablishGpuChannel_Params_Data* data_ = nullptr;
    };

    class Gpu_EstablishGpuChannel_ResponseParamsDataView {
    public:
        Gpu_EstablishGpuChannel_ResponseParamsDataView() { }

        Gpu_EstablishGpuChannel_ResponseParamsDataView(
            internal::Gpu_EstablishGpuChannel_ResponseParams_Data* data,
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
        mojo::ScopedMessagePipeHandle TakeChannelHandle()
        {
            mojo::ScopedMessagePipeHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedMessagePipeHandle>(
                &data_->channel_handle, &result, context_);
            DCHECK(ret);
            return result;
        }
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
        internal::Gpu_EstablishGpuChannel_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Gpu_CreateGpuMemoryBuffer_ParamsDataView {
    public:
        Gpu_CreateGpuMemoryBuffer_ParamsDataView() { }

        Gpu_CreateGpuMemoryBuffer_ParamsDataView(
            internal::Gpu_CreateGpuMemoryBuffer_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetIdDataView(
            ::gfx::mojom::GpuMemoryBufferIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadId(UserType* output)
        {
            auto* pointer = data_->id.Get();
            return mojo::internal::Deserialize<::gfx::mojom::GpuMemoryBufferIdDataView>(
                pointer, output, context_);
        }
        inline void GetSizeDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSize(UserType* output)
        {
            auto* pointer = data_->size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFormat(UserType* output) const
        {
            auto data_value = data_->format;
            return mojo::internal::Deserialize<::gfx::mojom::BufferFormat>(
                data_value, output);
        }

        ::gfx::mojom::BufferFormat format() const
        {
            return static_cast<::gfx::mojom::BufferFormat>(data_->format);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUsage(UserType* output) const
        {
            auto data_value = data_->usage;
            return mojo::internal::Deserialize<::gfx::mojom::BufferUsage>(
                data_value, output);
        }

        ::gfx::mojom::BufferUsage usage() const
        {
            return static_cast<::gfx::mojom::BufferUsage>(data_->usage);
        }

    private:
        internal::Gpu_CreateGpuMemoryBuffer_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Gpu_CreateGpuMemoryBuffer_ResponseParamsDataView {
    public:
        Gpu_CreateGpuMemoryBuffer_ResponseParamsDataView() { }

        Gpu_CreateGpuMemoryBuffer_ResponseParamsDataView(
            internal::Gpu_CreateGpuMemoryBuffer_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetBufferHandleDataView(
            ::gfx::mojom::GpuMemoryBufferHandleDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBufferHandle(UserType* output)
        {
            auto* pointer = data_->buffer_handle.Get();
            return mojo::internal::Deserialize<::gfx::mojom::GpuMemoryBufferHandleDataView>(
                pointer, output, context_);
        }

    private:
        internal::Gpu_CreateGpuMemoryBuffer_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Gpu_DestroyGpuMemoryBuffer_ParamsDataView {
    public:
        Gpu_DestroyGpuMemoryBuffer_ParamsDataView() { }

        Gpu_DestroyGpuMemoryBuffer_ParamsDataView(
            internal::Gpu_DestroyGpuMemoryBuffer_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetIdDataView(
            ::gfx::mojom::GpuMemoryBufferIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadId(UserType* output)
        {
            auto* pointer = data_->id.Get();
            return mojo::internal::Deserialize<::gfx::mojom::GpuMemoryBufferIdDataView>(
                pointer, output, context_);
        }
        inline void GetSyncTokenDataView(
            ::gpu::mojom::SyncTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSyncToken(UserType* output)
        {
            auto* pointer = data_->sync_token.Get();
            return mojo::internal::Deserialize<::gpu::mojom::SyncTokenDataView>(
                pointer, output, context_);
        }

    private:
        internal::Gpu_DestroyGpuMemoryBuffer_Params_Data* data_ = nullptr;
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

    inline void Gpu_EstablishGpuChannel_ResponseParamsDataView::GetGpuInfoDataView(
        ::gpu::mojom::GpuInfoDataView* output)
    {
        auto pointer = data_->gpu_info.Get();
        *output = ::gpu::mojom::GpuInfoDataView(pointer, context_);
    }

    inline void Gpu_CreateGpuMemoryBuffer_ParamsDataView::GetIdDataView(
        ::gfx::mojom::GpuMemoryBufferIdDataView* output)
    {
        auto pointer = data_->id.Get();
        *output = ::gfx::mojom::GpuMemoryBufferIdDataView(pointer, context_);
    }
    inline void Gpu_CreateGpuMemoryBuffer_ParamsDataView::GetSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }

    inline void Gpu_CreateGpuMemoryBuffer_ResponseParamsDataView::GetBufferHandleDataView(
        ::gfx::mojom::GpuMemoryBufferHandleDataView* output)
    {
        auto pointer = data_->buffer_handle.Get();
        *output = ::gfx::mojom::GpuMemoryBufferHandleDataView(pointer, context_);
    }

    inline void Gpu_DestroyGpuMemoryBuffer_ParamsDataView::GetIdDataView(
        ::gfx::mojom::GpuMemoryBufferIdDataView* output)
    {
        auto pointer = data_->id.Get();
        *output = ::gfx::mojom::GpuMemoryBufferIdDataView(pointer, context_);
    }
    inline void Gpu_DestroyGpuMemoryBuffer_ParamsDataView::GetSyncTokenDataView(
        ::gpu::mojom::SyncTokenDataView* output)
    {
        auto pointer = data_->sync_token.Get();
        *output = ::gpu::mojom::SyncTokenDataView(pointer, context_);
    }

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_GPU_MOJOM_SHARED_H_
