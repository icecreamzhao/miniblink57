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

#include "ui/gfx/mojo/buffer_types.mojom-blink.h"

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
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/Source/platform/mojo/GeometryStructTraits.h"
namespace gfx {
namespace mojom {
    namespace blink { // static
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
        }
        size_t GpuMemoryBufferId::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->id);
            return seed;
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
        }
        size_t NativePixmapPlane::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->stride);
            seed = mojo::internal::WTFHash(seed, this->offset);
            seed = mojo::internal::WTFHash(seed, this->size);
            seed = mojo::internal::WTFHash(seed, this->modifier);
            return seed;
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
    } // namespace blink
} // namespace mojom
} // namespace gfx

namespace mojo {

// static
bool StructTraits<::gfx::mojom::blink::GpuMemoryBufferId::DataView, ::gfx::mojom::blink::GpuMemoryBufferIdPtr>::Read(
    ::gfx::mojom::blink::GpuMemoryBufferId::DataView input,
    ::gfx::mojom::blink::GpuMemoryBufferIdPtr* output)
{
    bool success = true;
    ::gfx::mojom::blink::GpuMemoryBufferIdPtr result(::gfx::mojom::blink::GpuMemoryBufferId::New());

    result->id = input.id();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::blink::NativePixmapPlane::DataView, ::gfx::mojom::blink::NativePixmapPlanePtr>::Read(
    ::gfx::mojom::blink::NativePixmapPlane::DataView input,
    ::gfx::mojom::blink::NativePixmapPlanePtr* output)
{
    bool success = true;
    ::gfx::mojom::blink::NativePixmapPlanePtr result(::gfx::mojom::blink::NativePixmapPlane::New());

    result->stride = input.stride();
    result->offset = input.offset();
    result->size = input.size();
    result->modifier = input.modifier();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::blink::NativePixmapHandle::DataView, ::gfx::mojom::blink::NativePixmapHandlePtr>::Read(
    ::gfx::mojom::blink::NativePixmapHandle::DataView input,
    ::gfx::mojom::blink::NativePixmapHandlePtr* output)
{
    bool success = true;
    ::gfx::mojom::blink::NativePixmapHandlePtr result(::gfx::mojom::blink::NativePixmapHandle::New());

    if (!input.ReadFds(&result->fds))
        success = false;
    if (!input.ReadPlanes(&result->planes))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::blink::GpuMemoryBufferHandle::DataView, ::gfx::mojom::blink::GpuMemoryBufferHandlePtr>::Read(
    ::gfx::mojom::blink::GpuMemoryBufferHandle::DataView input,
    ::gfx::mojom::blink::GpuMemoryBufferHandlePtr* output)
{
    bool success = true;
    ::gfx::mojom::blink::GpuMemoryBufferHandlePtr result(::gfx::mojom::blink::GpuMemoryBufferHandle::New());

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