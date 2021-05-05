// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4056)
#pragma warning(disable : 4065)
#pragma warning(disable : 4756)
#endif

#include "ui/gfx/mojo/buffer_types.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "ui/gfx/ipc/color/gfx_param_traits.h"
#include "ui/gfx/mojo/accelerated_widget_struct_traits.h"
#include "ui/gfx/mojo/buffer_types_traits.h"
#include "ui/gfx/mojo/icc_profile_struct_traits.h"
#include "ui/gfx/mojo/selection_bound_struct_traits.h"
#include "ui/gfx/mojo/transform_struct_traits.h"
namespace gfx {
namespace mojom { // static
    GpuMemoryBufferIdPtr GpuMemoryBufferId::New()
    {
        GpuMemoryBufferIdPtr rv;
        mojo::internal::StructHelper<GpuMemoryBufferId>::Initialize(&rv);
        return rv;
    }

    GpuMemoryBufferId::GpuMemoryBufferId()
        : id()
    {
    }

    GpuMemoryBufferId::~GpuMemoryBufferId()
    {
    } // static
    NativePixmapPlanePtr NativePixmapPlane::New()
    {
        NativePixmapPlanePtr rv;
        mojo::internal::StructHelper<NativePixmapPlane>::Initialize(&rv);
        return rv;
    }

    NativePixmapPlane::NativePixmapPlane()
        : stride()
        , offset()
        , size()
        , modifier()
    {
    }

    NativePixmapPlane::~NativePixmapPlane()
    {
    } // static
    NativePixmapHandlePtr NativePixmapHandle::New()
    {
        NativePixmapHandlePtr rv;
        mojo::internal::StructHelper<NativePixmapHandle>::Initialize(&rv);
        return rv;
    }

    NativePixmapHandle::NativePixmapHandle()
        : fds()
        , planes()
    {
    }

    NativePixmapHandle::~NativePixmapHandle()
    {
    } // static
    GpuMemoryBufferHandlePtr GpuMemoryBufferHandle::New()
    {
        GpuMemoryBufferHandlePtr rv;
        mojo::internal::StructHelper<GpuMemoryBufferHandle>::Initialize(&rv);
        return rv;
    }

    GpuMemoryBufferHandle::GpuMemoryBufferHandle()
        : type()
        , id()
        , shared_memory_handle()
        , offset()
        , stride()
        , native_pixmap_handle()
        , mach_port()
    {
    }

    GpuMemoryBufferHandle::~GpuMemoryBufferHandle()
    {
    }
} // namespace mojom
} // namespace gfx

namespace mojo {

// static
bool StructTraits<::gfx::mojom::GpuMemoryBufferId::DataView, ::gfx::mojom::GpuMemoryBufferIdPtr>::Read(
    ::gfx::mojom::GpuMemoryBufferId::DataView input,
    ::gfx::mojom::GpuMemoryBufferIdPtr* output)
{
    bool success = true;
    ::gfx::mojom::GpuMemoryBufferIdPtr result(::gfx::mojom::GpuMemoryBufferId::New());

    result->id = input.id();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::NativePixmapPlane::DataView, ::gfx::mojom::NativePixmapPlanePtr>::Read(
    ::gfx::mojom::NativePixmapPlane::DataView input,
    ::gfx::mojom::NativePixmapPlanePtr* output)
{
    bool success = true;
    ::gfx::mojom::NativePixmapPlanePtr result(::gfx::mojom::NativePixmapPlane::New());

    result->stride = input.stride();
    result->offset = input.offset();
    result->size = input.size();
    result->modifier = input.modifier();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::NativePixmapHandle::DataView, ::gfx::mojom::NativePixmapHandlePtr>::Read(
    ::gfx::mojom::NativePixmapHandle::DataView input,
    ::gfx::mojom::NativePixmapHandlePtr* output)
{
    bool success = true;
    ::gfx::mojom::NativePixmapHandlePtr result(::gfx::mojom::NativePixmapHandle::New());

    if (!input.ReadFds(&result->fds))
        success = false;
    if (!input.ReadPlanes(&result->planes))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::GpuMemoryBufferHandle::DataView, ::gfx::mojom::GpuMemoryBufferHandlePtr>::Read(
    ::gfx::mojom::GpuMemoryBufferHandle::DataView input,
    ::gfx::mojom::GpuMemoryBufferHandlePtr* output)
{
    bool success = true;
    ::gfx::mojom::GpuMemoryBufferHandlePtr result(::gfx::mojom::GpuMemoryBufferHandle::New());

    if (!input.ReadType(&result->type))
        success = false;
    if (!input.ReadId(&result->id))
        success = false;
    result->shared_memory_handle = input.TakeSharedMemoryHandle();
    result->offset = input.offset();
    result->stride = input.stride();
    if (!input.ReadNativePixmapHandle(&result->native_pixmap_handle))
        success = false;
    result->mach_port = input.TakeMachPort();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif