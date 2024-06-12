// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_MOJO_BUFFER_TYPES_MOJOM_H_
#define UI_GFX_MOJO_BUFFER_TYPES_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
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
#include "ui/gfx/buffer_types.h"
#include "ui/gfx/color_space.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "ui/gfx/gpu_memory_buffer.h"
#include "ui/gfx/icc_profile.h"
#include "ui/gfx/mojo/buffer_types.mojom-shared.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace gfx {
namespace mojom {
    class GpuMemoryBufferId;
    using GpuMemoryBufferIdPtr = mojo::InlinedStructPtr<GpuMemoryBufferId>;

    class NativePixmapPlane;
    using NativePixmapPlanePtr = mojo::InlinedStructPtr<NativePixmapPlane>;

    class NativePixmapHandle;
    using NativePixmapHandlePtr = mojo::StructPtr<NativePixmapHandle>;

    class GpuMemoryBufferHandle;
    using GpuMemoryBufferHandlePtr = mojo::StructPtr<GpuMemoryBufferHandle>;

    class GpuMemoryBufferId {
    public:
        using DataView = GpuMemoryBufferIdDataView;
        using Data_ = internal::GpuMemoryBufferId_Data;

        static GpuMemoryBufferIdPtr New();

        template <typename U>
        static GpuMemoryBufferIdPtr From(const U& u)
        {
            return mojo::TypeConverter<GpuMemoryBufferIdPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, GpuMemoryBufferId>::Convert(*this);
        }

        GpuMemoryBufferId();
        ~GpuMemoryBufferId();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = GpuMemoryBufferIdPtr>
        GpuMemoryBufferIdPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, GpuMemoryBufferId>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                GpuMemoryBufferId::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                GpuMemoryBufferId::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int32_t id;
    };

    class NativePixmapPlane {
    public:
        using DataView = NativePixmapPlaneDataView;
        using Data_ = internal::NativePixmapPlane_Data;

        static NativePixmapPlanePtr New();

        template <typename U>
        static NativePixmapPlanePtr From(const U& u)
        {
            return mojo::TypeConverter<NativePixmapPlanePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, NativePixmapPlane>::Convert(*this);
        }

        NativePixmapPlane();
        ~NativePixmapPlane();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = NativePixmapPlanePtr>
        NativePixmapPlanePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, NativePixmapPlane>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                NativePixmapPlane::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                NativePixmapPlane::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t stride;
        int32_t offset;
        uint64_t size;
        uint64_t modifier;
    };

    class NativePixmapHandle {
    public:
        using DataView = NativePixmapHandleDataView;
        using Data_ = internal::NativePixmapHandle_Data;

        static NativePixmapHandlePtr New();

        template <typename U>
        static NativePixmapHandlePtr From(const U& u)
        {
            return mojo::TypeConverter<NativePixmapHandlePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, NativePixmapHandle>::Convert(*this);
        }

        NativePixmapHandle();
        ~NativePixmapHandle();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = NativePixmapHandlePtr>
        NativePixmapHandlePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, NativePixmapHandle>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                NativePixmapHandle::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                NativePixmapHandle::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::vector<mojo::ScopedHandle> fds;
        std::vector<gfx::NativePixmapPlane> planes;

    private:
        DISALLOW_COPY_AND_ASSIGN(NativePixmapHandle);
    };

    class GpuMemoryBufferHandle {
    public:
        using DataView = GpuMemoryBufferHandleDataView;
        using Data_ = internal::GpuMemoryBufferHandle_Data;

        static GpuMemoryBufferHandlePtr New();

        template <typename U>
        static GpuMemoryBufferHandlePtr From(const U& u)
        {
            return mojo::TypeConverter<GpuMemoryBufferHandlePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, GpuMemoryBufferHandle>::Convert(*this);
        }

        GpuMemoryBufferHandle();
        ~GpuMemoryBufferHandle();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = GpuMemoryBufferHandlePtr>
        GpuMemoryBufferHandlePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, GpuMemoryBufferHandle>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                GpuMemoryBufferHandle::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                GpuMemoryBufferHandle::DataView, std::vector<uint8_t>>(
                input, output);
        }

        gfx::GpuMemoryBufferType type;
        gfx::GpuMemoryBufferId id;
        mojo::ScopedHandle shared_memory_handle;
        uint32_t offset;
        uint32_t stride;
        base::Optional<gfx::NativePixmapHandle> native_pixmap_handle;
        mojo::ScopedHandle mach_port;

    private:
        DISALLOW_COPY_AND_ASSIGN(GpuMemoryBufferHandle);
    };

    template <typename StructPtrType>
    GpuMemoryBufferIdPtr GpuMemoryBufferId::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->id = mojo::internal::Clone(id);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, GpuMemoryBufferId>::value>::type*>
    bool GpuMemoryBufferId::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        return true;
    }
    template <typename StructPtrType>
    NativePixmapPlanePtr NativePixmapPlane::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->stride = mojo::internal::Clone(stride);
        rv->offset = mojo::internal::Clone(offset);
        rv->size = mojo::internal::Clone(size);
        rv->modifier = mojo::internal::Clone(modifier);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, NativePixmapPlane>::value>::type*>
    bool NativePixmapPlane::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->stride, other.stride))
            return false;
        if (!mojo::internal::Equals(this->offset, other.offset))
            return false;
        if (!mojo::internal::Equals(this->size, other.size))
            return false;
        if (!mojo::internal::Equals(this->modifier, other.modifier))
            return false;
        return true;
    }
    template <typename StructPtrType>
    NativePixmapHandlePtr NativePixmapHandle::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->fds = mojo::internal::Clone(fds);
        rv->planes = mojo::internal::Clone(planes);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, NativePixmapHandle>::value>::type*>
    bool NativePixmapHandle::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->fds, other.fds))
            return false;
        if (!mojo::internal::Equals(this->planes, other.planes))
            return false;
        return true;
    }
    template <typename StructPtrType>
    GpuMemoryBufferHandlePtr GpuMemoryBufferHandle::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->type = mojo::internal::Clone(type);
        rv->id = mojo::internal::Clone(id);
        rv->shared_memory_handle = mojo::internal::Clone(shared_memory_handle);
        rv->offset = mojo::internal::Clone(offset);
        rv->stride = mojo::internal::Clone(stride);
        rv->native_pixmap_handle = mojo::internal::Clone(native_pixmap_handle);
        rv->mach_port = mojo::internal::Clone(mach_port);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, GpuMemoryBufferHandle>::value>::type*>
    bool GpuMemoryBufferHandle::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->type, other.type))
            return false;
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        if (!mojo::internal::Equals(this->shared_memory_handle, other.shared_memory_handle))
            return false;
        if (!mojo::internal::Equals(this->offset, other.offset))
            return false;
        if (!mojo::internal::Equals(this->stride, other.stride))
            return false;
        if (!mojo::internal::Equals(this->native_pixmap_handle, other.native_pixmap_handle))
            return false;
        if (!mojo::internal::Equals(this->mach_port, other.mach_port))
            return false;
        return true;
    }

} // namespace mojom
} // namespace gfx

namespace mojo {

template <>
struct StructTraits<::gfx::mojom::GpuMemoryBufferId::DataView,
    ::gfx::mojom::GpuMemoryBufferIdPtr> {
    static bool IsNull(const ::gfx::mojom::GpuMemoryBufferIdPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::GpuMemoryBufferIdPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::GpuMemoryBufferId::id) id(
        const ::gfx::mojom::GpuMemoryBufferIdPtr& input)
    {
        return input->id;
    }

    static bool Read(::gfx::mojom::GpuMemoryBufferId::DataView input, ::gfx::mojom::GpuMemoryBufferIdPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::NativePixmapPlane::DataView,
    ::gfx::mojom::NativePixmapPlanePtr> {
    static bool IsNull(const ::gfx::mojom::NativePixmapPlanePtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::NativePixmapPlanePtr* output) { output->reset(); }

    static decltype(::gfx::mojom::NativePixmapPlane::stride) stride(
        const ::gfx::mojom::NativePixmapPlanePtr& input)
    {
        return input->stride;
    }

    static decltype(::gfx::mojom::NativePixmapPlane::offset) offset(
        const ::gfx::mojom::NativePixmapPlanePtr& input)
    {
        return input->offset;
    }

    static decltype(::gfx::mojom::NativePixmapPlane::size) size(
        const ::gfx::mojom::NativePixmapPlanePtr& input)
    {
        return input->size;
    }

    static decltype(::gfx::mojom::NativePixmapPlane::modifier) modifier(
        const ::gfx::mojom::NativePixmapPlanePtr& input)
    {
        return input->modifier;
    }

    static bool Read(::gfx::mojom::NativePixmapPlane::DataView input, ::gfx::mojom::NativePixmapPlanePtr* output);
};

template <>
struct StructTraits<::gfx::mojom::NativePixmapHandle::DataView,
    ::gfx::mojom::NativePixmapHandlePtr> {
    static bool IsNull(const ::gfx::mojom::NativePixmapHandlePtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::NativePixmapHandlePtr* output) { output->reset(); }

    static decltype(::gfx::mojom::NativePixmapHandle::fds)& fds(
        ::gfx::mojom::NativePixmapHandlePtr& input)
    {
        return input->fds;
    }

    static const decltype(::gfx::mojom::NativePixmapHandle::planes)& planes(
        const ::gfx::mojom::NativePixmapHandlePtr& input)
    {
        return input->planes;
    }

    static bool Read(::gfx::mojom::NativePixmapHandle::DataView input, ::gfx::mojom::NativePixmapHandlePtr* output);
};

template <>
struct StructTraits<::gfx::mojom::GpuMemoryBufferHandle::DataView,
    ::gfx::mojom::GpuMemoryBufferHandlePtr> {
    static bool IsNull(const ::gfx::mojom::GpuMemoryBufferHandlePtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::GpuMemoryBufferHandlePtr* output) { output->reset(); }

    static decltype(::gfx::mojom::GpuMemoryBufferHandle::type) type(
        const ::gfx::mojom::GpuMemoryBufferHandlePtr& input)
    {
        return input->type;
    }

    static const decltype(::gfx::mojom::GpuMemoryBufferHandle::id)& id(
        const ::gfx::mojom::GpuMemoryBufferHandlePtr& input)
    {
        return input->id;
    }

    static decltype(::gfx::mojom::GpuMemoryBufferHandle::shared_memory_handle)& shared_memory_handle(
        ::gfx::mojom::GpuMemoryBufferHandlePtr& input)
    {
        return input->shared_memory_handle;
    }

    static decltype(::gfx::mojom::GpuMemoryBufferHandle::offset) offset(
        const ::gfx::mojom::GpuMemoryBufferHandlePtr& input)
    {
        return input->offset;
    }

    static decltype(::gfx::mojom::GpuMemoryBufferHandle::stride) stride(
        const ::gfx::mojom::GpuMemoryBufferHandlePtr& input)
    {
        return input->stride;
    }

    static decltype(::gfx::mojom::GpuMemoryBufferHandle::native_pixmap_handle)& native_pixmap_handle(
        ::gfx::mojom::GpuMemoryBufferHandlePtr& input)
    {
        return input->native_pixmap_handle;
    }

    static decltype(::gfx::mojom::GpuMemoryBufferHandle::mach_port)& mach_port(
        ::gfx::mojom::GpuMemoryBufferHandlePtr& input)
    {
        return input->mach_port;
    }

    static bool Read(::gfx::mojom::GpuMemoryBufferHandle::DataView input, ::gfx::mojom::GpuMemoryBufferHandlePtr* output);
};

} // namespace mojo

#endif // UI_GFX_MOJO_BUFFER_TYPES_MOJOM_H_