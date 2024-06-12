// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_GPU_INTERFACES_GPU_MAIN_MOJOM_SHARED_H_
#define SERVICES_UI_GPU_INTERFACES_GPU_MAIN_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/display_compositor.mojom-shared.h"
#include "gpu/ipc/common/gpu_preferences.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/ui/gpu/interfaces/gpu_host.mojom-shared.h"
#include "services/ui/gpu/interfaces/gpu_main.mojom-shared-internal.h"
#include "services/ui/gpu/interfaces/gpu_service.mojom-shared.h"

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
    class GpuMainInterfaceBase {
    };

    using GpuMainPtrDataView = mojo::InterfacePtrDataView<GpuMainInterfaceBase>;
    using GpuMainRequestDataView = mojo::InterfaceRequestDataView<GpuMainInterfaceBase>;
    using GpuMainAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<GpuMainInterfaceBase>;
    using GpuMainAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<GpuMainInterfaceBase>;
    class GpuMain_CreateDisplayCompositor_ParamsDataView {
    public:
        GpuMain_CreateDisplayCompositor_ParamsDataView() { }

        GpuMain_CreateDisplayCompositor_ParamsDataView(
            internal::GpuMain_CreateDisplayCompositor_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeDisplayCompositor()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::cc::mojom::DisplayCompositorRequestDataView>(
                &data_->display_compositor, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeDisplayCompositorClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::cc::mojom::DisplayCompositorClientPtrDataView>(
                &data_->display_compositor_client, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::GpuMain_CreateDisplayCompositor_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class GpuMain_CreateGpuService_ParamsDataView {
    public:
        GpuMain_CreateGpuService_ParamsDataView() { }

        GpuMain_CreateGpuService_ParamsDataView(
            internal::GpuMain_CreateGpuService_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeGpuService()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::GpuServiceRequestDataView>(
                &data_->gpu_service, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeGpuHost()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::GpuHostPtrDataView>(
                &data_->gpu_host, &result, context_);
            DCHECK(ret);
            return result;
        }
        inline void GetPreferencesDataView(
            ::gpu::mojom::GpuPreferencesDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPreferences(UserType* output)
        {
            auto* pointer = data_->preferences.Get();
            return mojo::internal::Deserialize<::gpu::mojom::GpuPreferencesDataView>(
                pointer, output, context_);
        }

    private:
        internal::GpuMain_CreateGpuService_Params_Data* data_ = nullptr;
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

    inline void GpuMain_CreateGpuService_ParamsDataView::GetPreferencesDataView(
        ::gpu::mojom::GpuPreferencesDataView* output)
    {
        auto pointer = data_->preferences.Get();
        *output = ::gpu::mojom::GpuPreferencesDataView(pointer, context_);
    }

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_GPU_INTERFACES_GPU_MAIN_MOJOM_SHARED_H_
