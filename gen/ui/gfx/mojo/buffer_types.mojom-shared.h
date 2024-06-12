// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_MOJO_BUFFER_TYPES_MOJOM_SHARED_H_
#define UI_GFX_MOJO_BUFFER_TYPES_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "ui/gfx/mojo/buffer_types.mojom-shared-internal.h"

namespace gfx {
namespace mojom {
    class GpuMemoryBufferIdDataView;

    class NativePixmapPlaneDataView;

    class NativePixmapHandleDataView;

    class GpuMemoryBufferHandleDataView;

} // namespace mojom
} // namespace gfx

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::gfx::mojom::GpuMemoryBufferIdDataView> {
        using Data = ::gfx::mojom::internal::GpuMemoryBufferId_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::gfx::mojom::NativePixmapPlaneDataView> {
        using Data = ::gfx::mojom::internal::NativePixmapPlane_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::gfx::mojom::NativePixmapHandleDataView> {
        using Data = ::gfx::mojom::internal::NativePixmapHandle_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::gfx::mojom::GpuMemoryBufferHandleDataView> {
        using Data = ::gfx::mojom::internal::GpuMemoryBufferHandle_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace gfx {
namespace mojom {

    enum class BufferFormat : int32_t {
        ATC,
        ATCIA,
        DXT1,
        DXT5,
        ETC1,
        R_8,
        RG_88,
        BGR_565,
        RGBA_4444,
        RGBX_8888,
        RGBA_8888,
        BGRX_8888,
        BGRA_8888,
        YVU_420,
        YUV_420_BIPLANAR,
        UYVY_422,
        LAST = BufferFormat::UYVY_422,
    };

    inline std::ostream& operator<<(std::ostream& os, BufferFormat value)
    {
        switch (value) {
        case BufferFormat::ATC:
            return os << "BufferFormat::ATC";
        case BufferFormat::ATCIA:
            return os << "BufferFormat::ATCIA";
        case BufferFormat::DXT1:
            return os << "BufferFormat::DXT1";
        case BufferFormat::DXT5:
            return os << "BufferFormat::DXT5";
        case BufferFormat::ETC1:
            return os << "BufferFormat::ETC1";
        case BufferFormat::R_8:
            return os << "BufferFormat::R_8";
        case BufferFormat::RG_88:
            return os << "BufferFormat::RG_88";
        case BufferFormat::BGR_565:
            return os << "BufferFormat::BGR_565";
        case BufferFormat::RGBA_4444:
            return os << "BufferFormat::RGBA_4444";
        case BufferFormat::RGBX_8888:
            return os << "BufferFormat::RGBX_8888";
        case BufferFormat::RGBA_8888:
            return os << "BufferFormat::RGBA_8888";
        case BufferFormat::BGRX_8888:
            return os << "BufferFormat::BGRX_8888";
        case BufferFormat::BGRA_8888:
            return os << "BufferFormat::BGRA_8888";
        case BufferFormat::YVU_420:
            return os << "BufferFormat::YVU_420";
        case BufferFormat::YUV_420_BIPLANAR:
            return os << "BufferFormat::YUV_420_BIPLANAR";
        case BufferFormat::UYVY_422:
            return os << "BufferFormat::{UYVY_422, LAST}";
        default:
            return os << "Unknown BufferFormat value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(BufferFormat value)
    {
        return internal::BufferFormat_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class BufferUsage : int32_t {
        GPU_READ,
        SCANOUT,
        GPU_READ_CPU_READ_WRITE,
        GPU_READ_CPU_READ_WRITE_PERSISTENT,
        LAST = BufferUsage::GPU_READ_CPU_READ_WRITE_PERSISTENT,
    };

    inline std::ostream& operator<<(std::ostream& os, BufferUsage value)
    {
        switch (value) {
        case BufferUsage::GPU_READ:
            return os << "BufferUsage::GPU_READ";
        case BufferUsage::SCANOUT:
            return os << "BufferUsage::SCANOUT";
        case BufferUsage::GPU_READ_CPU_READ_WRITE:
            return os << "BufferUsage::GPU_READ_CPU_READ_WRITE";
        case BufferUsage::GPU_READ_CPU_READ_WRITE_PERSISTENT:
            return os << "BufferUsage::{GPU_READ_CPU_READ_WRITE_PERSISTENT, LAST}";
        default:
            return os << "Unknown BufferUsage value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(BufferUsage value)
    {
        return internal::BufferUsage_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class GpuMemoryBufferType : int32_t {
        EMPTY_BUFFER,
        SHARED_MEMORY_BUFFER,
        IO_SURFACE_BUFFER,
        OZONE_NATIVE_PIXMAP,
        LAST = GpuMemoryBufferType::OZONE_NATIVE_PIXMAP,
    };

    inline std::ostream& operator<<(std::ostream& os, GpuMemoryBufferType value)
    {
        switch (value) {
        case GpuMemoryBufferType::EMPTY_BUFFER:
            return os << "GpuMemoryBufferType::EMPTY_BUFFER";
        case GpuMemoryBufferType::SHARED_MEMORY_BUFFER:
            return os << "GpuMemoryBufferType::SHARED_MEMORY_BUFFER";
        case GpuMemoryBufferType::IO_SURFACE_BUFFER:
            return os << "GpuMemoryBufferType::IO_SURFACE_BUFFER";
        case GpuMemoryBufferType::OZONE_NATIVE_PIXMAP:
            return os << "GpuMemoryBufferType::{OZONE_NATIVE_PIXMAP, LAST}";
        default:
            return os << "Unknown GpuMemoryBufferType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(GpuMemoryBufferType value)
    {
        return internal::GpuMemoryBufferType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class GpuMemoryBufferIdDataView {
    public:
        GpuMemoryBufferIdDataView() { }

        GpuMemoryBufferIdDataView(
            internal::GpuMemoryBufferId_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t id() const
        {
            return data_->id;
        }

    private:
        internal::GpuMemoryBufferId_Data* data_ = nullptr;
    };

    class NativePixmapPlaneDataView {
    public:
        NativePixmapPlaneDataView() { }

        NativePixmapPlaneDataView(
            internal::NativePixmapPlane_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t stride() const
        {
            return data_->stride;
        }
        int32_t offset() const
        {
            return data_->offset;
        }
        uint64_t size() const
        {
            return data_->size;
        }
        uint64_t modifier() const
        {
            return data_->modifier;
        }

    private:
        internal::NativePixmapPlane_Data* data_ = nullptr;
    };

    class NativePixmapHandleDataView {
    public:
        NativePixmapHandleDataView() { }

        NativePixmapHandleDataView(
            internal::NativePixmapHandle_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFdsDataView(
            mojo::ArrayDataView<mojo::ScopedHandle>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFds(UserType* output)
        {
            auto* pointer = data_->fds.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<mojo::ScopedHandle>>(
                pointer, output, context_);
        }
        inline void GetPlanesDataView(
            mojo::ArrayDataView<NativePixmapPlaneDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPlanes(UserType* output)
        {
            auto* pointer = data_->planes.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::gfx::mojom::NativePixmapPlaneDataView>>(
                pointer, output, context_);
        }

    private:
        internal::NativePixmapHandle_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class GpuMemoryBufferHandleDataView {
    public:
        GpuMemoryBufferHandleDataView() { }

        GpuMemoryBufferHandleDataView(
            internal::GpuMemoryBufferHandle_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::gfx::mojom::GpuMemoryBufferType>(
                data_value, output);
        }

        GpuMemoryBufferType type() const
        {
            return static_cast<GpuMemoryBufferType>(data_->type);
        }
        inline void GetIdDataView(
            GpuMemoryBufferIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadId(UserType* output)
        {
            auto* pointer = data_->id.Get();
            return mojo::internal::Deserialize<::gfx::mojom::GpuMemoryBufferIdDataView>(
                pointer, output, context_);
        }
        mojo::ScopedHandle TakeSharedMemoryHandle()
        {
            mojo::ScopedHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedHandle>(
                &data_->shared_memory_handle, &result, context_);
            DCHECK(ret);
            return result;
        }
        uint32_t offset() const
        {
            return data_->offset;
        }
        uint32_t stride() const
        {
            return data_->stride;
        }
        inline void GetNativePixmapHandleDataView(
            NativePixmapHandleDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNativePixmapHandle(UserType* output)
        {
            auto* pointer = data_->native_pixmap_handle.Get();
            return mojo::internal::Deserialize<::gfx::mojom::NativePixmapHandleDataView>(
                pointer, output, context_);
        }
        mojo::ScopedHandle TakeMachPort()
        {
            mojo::ScopedHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedHandle>(
                &data_->mach_port, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::GpuMemoryBufferHandle_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace gfx

namespace std {

template <>
struct hash<::gfx::mojom::BufferFormat>
    : public mojo::internal::EnumHashImpl<::gfx::mojom::BufferFormat> {
};

template <>
struct hash<::gfx::mojom::BufferUsage>
    : public mojo::internal::EnumHashImpl<::gfx::mojom::BufferUsage> {
};

template <>
struct hash<::gfx::mojom::GpuMemoryBufferType>
    : public mojo::internal::EnumHashImpl<::gfx::mojom::GpuMemoryBufferType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::gfx::mojom::BufferFormat, ::gfx::mojom::BufferFormat> {
    static ::gfx::mojom::BufferFormat ToMojom(::gfx::mojom::BufferFormat input) { return input; }
    static bool FromMojom(::gfx::mojom::BufferFormat input, ::gfx::mojom::BufferFormat* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::BufferFormat, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::gfx::mojom::BufferFormat, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::gfx::mojom::BufferFormat>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::gfx::mojom::BufferUsage, ::gfx::mojom::BufferUsage> {
    static ::gfx::mojom::BufferUsage ToMojom(::gfx::mojom::BufferUsage input) { return input; }
    static bool FromMojom(::gfx::mojom::BufferUsage input, ::gfx::mojom::BufferUsage* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::BufferUsage, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::gfx::mojom::BufferUsage, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::gfx::mojom::BufferUsage>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::gfx::mojom::GpuMemoryBufferType, ::gfx::mojom::GpuMemoryBufferType> {
    static ::gfx::mojom::GpuMemoryBufferType ToMojom(::gfx::mojom::GpuMemoryBufferType input) { return input; }
    static bool FromMojom(::gfx::mojom::GpuMemoryBufferType input, ::gfx::mojom::GpuMemoryBufferType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::GpuMemoryBufferType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::gfx::mojom::GpuMemoryBufferType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::gfx::mojom::GpuMemoryBufferType>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::GpuMemoryBufferIdDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::GpuMemoryBufferIdDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::GpuMemoryBufferId_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::GpuMemoryBufferId_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::GpuMemoryBufferId_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->id = CallWithContext(Traits::id, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::GpuMemoryBufferId_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::GpuMemoryBufferIdDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::NativePixmapPlaneDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::NativePixmapPlaneDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::NativePixmapPlane_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::NativePixmapPlane_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::NativePixmapPlane_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->stride = CallWithContext(Traits::stride, input, custom_context);
            result->offset = CallWithContext(Traits::offset, input, custom_context);
            result->size = CallWithContext(Traits::size, input, custom_context);
            result->modifier = CallWithContext(Traits::modifier, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::NativePixmapPlane_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::NativePixmapPlaneDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::NativePixmapHandleDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::NativePixmapHandleDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::NativePixmapHandle_Data);
            decltype(CallWithContext(Traits::fds, input, custom_context)) in_fds = CallWithContext(Traits::fds, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<mojo::ScopedHandle>>(
                in_fds, context);
            decltype(CallWithContext(Traits::planes, input, custom_context)) in_planes = CallWithContext(Traits::planes, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::gfx::mojom::NativePixmapPlaneDataView>>(
                in_planes, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::NativePixmapHandle_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::NativePixmapHandle_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::fds, input, custom_context)) in_fds = CallWithContext(Traits::fds, input, custom_context);
            typename decltype(result->fds)::BaseType* fds_ptr;
            const mojo::internal::ContainerValidateParams fds_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<mojo::ScopedHandle>>(
                in_fds, buffer, &fds_ptr, &fds_validate_params,
                context);
            result->fds.Set(fds_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->fds.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null fds in NativePixmapHandle struct");
            decltype(CallWithContext(Traits::planes, input, custom_context)) in_planes = CallWithContext(Traits::planes, input, custom_context);
            typename decltype(result->planes)::BaseType* planes_ptr;
            const mojo::internal::ContainerValidateParams planes_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::gfx::mojom::NativePixmapPlaneDataView>>(
                in_planes, buffer, &planes_ptr, &planes_validate_params,
                context);
            result->planes.Set(planes_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->planes.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null planes in NativePixmapHandle struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::NativePixmapHandle_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::NativePixmapHandleDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::GpuMemoryBufferHandleDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::GpuMemoryBufferHandleDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::GpuMemoryBufferHandle_Data);
            decltype(CallWithContext(Traits::id, input, custom_context)) in_id = CallWithContext(Traits::id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::GpuMemoryBufferIdDataView>(
                in_id, context);
            decltype(CallWithContext(Traits::native_pixmap_handle, input, custom_context)) in_native_pixmap_handle = CallWithContext(Traits::native_pixmap_handle, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::NativePixmapHandleDataView>(
                in_native_pixmap_handle, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::GpuMemoryBufferHandle_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::GpuMemoryBufferHandle_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::gfx::mojom::GpuMemoryBufferType>(
                CallWithContext(Traits::type, input, custom_context), &result->type);
            decltype(CallWithContext(Traits::id, input, custom_context)) in_id = CallWithContext(Traits::id, input, custom_context);
            typename decltype(result->id)::BaseType* id_ptr;
            mojo::internal::Serialize<::gfx::mojom::GpuMemoryBufferIdDataView>(
                in_id, buffer, &id_ptr, context);
            result->id.Set(id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null id in GpuMemoryBufferHandle struct");
            decltype(CallWithContext(Traits::shared_memory_handle, input, custom_context)) in_shared_memory_handle = CallWithContext(Traits::shared_memory_handle, input, custom_context);
            mojo::internal::Serialize<mojo::ScopedHandle>(
                in_shared_memory_handle, &result->shared_memory_handle, context);
            result->offset = CallWithContext(Traits::offset, input, custom_context);
            result->stride = CallWithContext(Traits::stride, input, custom_context);
            decltype(CallWithContext(Traits::native_pixmap_handle, input, custom_context)) in_native_pixmap_handle = CallWithContext(Traits::native_pixmap_handle, input, custom_context);
            typename decltype(result->native_pixmap_handle)::BaseType* native_pixmap_handle_ptr;
            mojo::internal::Serialize<::gfx::mojom::NativePixmapHandleDataView>(
                in_native_pixmap_handle, buffer, &native_pixmap_handle_ptr, context);
            result->native_pixmap_handle.Set(native_pixmap_handle_ptr);
            decltype(CallWithContext(Traits::mach_port, input, custom_context)) in_mach_port = CallWithContext(Traits::mach_port, input, custom_context);
            mojo::internal::Serialize<mojo::ScopedHandle>(
                in_mach_port, &result->mach_port, context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::GpuMemoryBufferHandle_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::GpuMemoryBufferHandleDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace gfx {
namespace mojom {

    inline void NativePixmapHandleDataView::GetFdsDataView(
        mojo::ArrayDataView<mojo::ScopedHandle>* output)
    {
        auto pointer = data_->fds.Get();
        *output = mojo::ArrayDataView<mojo::ScopedHandle>(pointer, context_);
    }
    inline void NativePixmapHandleDataView::GetPlanesDataView(
        mojo::ArrayDataView<NativePixmapPlaneDataView>* output)
    {
        auto pointer = data_->planes.Get();
        *output = mojo::ArrayDataView<NativePixmapPlaneDataView>(pointer, context_);
    }

    inline void GpuMemoryBufferHandleDataView::GetIdDataView(
        GpuMemoryBufferIdDataView* output)
    {
        auto pointer = data_->id.Get();
        *output = GpuMemoryBufferIdDataView(pointer, context_);
    }
    inline void GpuMemoryBufferHandleDataView::GetNativePixmapHandleDataView(
        NativePixmapHandleDataView* output)
    {
        auto pointer = data_->native_pixmap_handle.Get();
        *output = NativePixmapHandleDataView(pointer, context_);
    }

} // namespace mojom
} // namespace gfx

#endif // UI_GFX_MOJO_BUFFER_TYPES_MOJOM_SHARED_H_
