// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_TRANSFERABLE_RESOURCE_MOJOM_SHARED_H_
#define CC_IPC_TRANSFERABLE_RESOURCE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/transferable_resource.mojom-shared-internal.h"
#include "gpu/ipc/common/mailbox_holder.mojom-shared.h"
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

namespace cc {
namespace mojom {
    class TransferableResourceDataView;

} // namespace mojom
} // namespace cc

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::cc::mojom::TransferableResourceDataView> {
        using Data = ::cc::mojom::internal::TransferableResource_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace cc {
namespace mojom {

    enum class ResourceFormat : int32_t {
        RGBA_8888,
        RGBA_4444,
        BGRA_8888,
        ALPHA_8,
        LUMINANCE_8,
        RGB_565,
        ETC1,
    };

    inline std::ostream& operator<<(std::ostream& os, ResourceFormat value)
    {
        switch (value) {
        case ResourceFormat::RGBA_8888:
            return os << "ResourceFormat::RGBA_8888";
        case ResourceFormat::RGBA_4444:
            return os << "ResourceFormat::RGBA_4444";
        case ResourceFormat::BGRA_8888:
            return os << "ResourceFormat::BGRA_8888";
        case ResourceFormat::ALPHA_8:
            return os << "ResourceFormat::ALPHA_8";
        case ResourceFormat::LUMINANCE_8:
            return os << "ResourceFormat::LUMINANCE_8";
        case ResourceFormat::RGB_565:
            return os << "ResourceFormat::RGB_565";
        case ResourceFormat::ETC1:
            return os << "ResourceFormat::ETC1";
        default:
            return os << "Unknown ResourceFormat value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(ResourceFormat value)
    {
        return internal::ResourceFormat_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class TransferableResourceDataView {
    public:
        TransferableResourceDataView() { }

        TransferableResourceDataView(
            internal::TransferableResource_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t id() const
        {
            return data_->id;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFormat(UserType* output) const
        {
            auto data_value = data_->format;
            return mojo::internal::Deserialize<::cc::mojom::ResourceFormat>(
                data_value, output);
        }

        ResourceFormat format() const
        {
            return static_cast<ResourceFormat>(data_->format);
        }
        uint32_t filter() const
        {
            return data_->filter;
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
        inline void GetMailboxHolderDataView(
            ::gpu::mojom::MailboxHolderDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMailboxHolder(UserType* output)
        {
            auto* pointer = data_->mailbox_holder.Get();
            return mojo::internal::Deserialize<::gpu::mojom::MailboxHolderDataView>(
                pointer, output, context_);
        }
        bool read_lock_fences_enabled() const
        {
            return data_->read_lock_fences_enabled;
        }
        bool is_software() const
        {
            return data_->is_software;
        }
        bool is_overlay_candidate() const
        {
            return data_->is_overlay_candidate;
        }
        bool is_backed_by_surface_texture() const
        {
            return data_->is_backed_by_surface_texture;
        }
        bool wants_promotion_hint() const
        {
            return data_->wants_promotion_hint;
        }

    private:
        internal::TransferableResource_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace cc

namespace std {

template <>
struct hash<::cc::mojom::ResourceFormat>
    : public mojo::internal::EnumHashImpl<::cc::mojom::ResourceFormat> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::cc::mojom::ResourceFormat, ::cc::mojom::ResourceFormat> {
    static ::cc::mojom::ResourceFormat ToMojom(::cc::mojom::ResourceFormat input) { return input; }
    static bool FromMojom(::cc::mojom::ResourceFormat input, ::cc::mojom::ResourceFormat* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::ResourceFormat, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::cc::mojom::ResourceFormat, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::cc::mojom::ResourceFormat>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::TransferableResourceDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::TransferableResourceDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::TransferableResource_Data);
            decltype(CallWithContext(Traits::size, input, custom_context)) in_size = CallWithContext(Traits::size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_size, context);
            decltype(CallWithContext(Traits::mailbox_holder, input, custom_context)) in_mailbox_holder = CallWithContext(Traits::mailbox_holder, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gpu::mojom::MailboxHolderDataView>(
                in_mailbox_holder, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::TransferableResource_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::TransferableResource_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->id = CallWithContext(Traits::id, input, custom_context);
            mojo::internal::Serialize<::cc::mojom::ResourceFormat>(
                CallWithContext(Traits::format, input, custom_context), &result->format);
            result->filter = CallWithContext(Traits::filter, input, custom_context);
            decltype(CallWithContext(Traits::size, input, custom_context)) in_size = CallWithContext(Traits::size, input, custom_context);
            typename decltype(result->size)::BaseType* size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_size, buffer, &size_ptr, context);
            result->size.Set(size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null size in TransferableResource struct");
            decltype(CallWithContext(Traits::mailbox_holder, input, custom_context)) in_mailbox_holder = CallWithContext(Traits::mailbox_holder, input, custom_context);
            typename decltype(result->mailbox_holder)::BaseType* mailbox_holder_ptr;
            mojo::internal::Serialize<::gpu::mojom::MailboxHolderDataView>(
                in_mailbox_holder, buffer, &mailbox_holder_ptr, context);
            result->mailbox_holder.Set(mailbox_holder_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->mailbox_holder.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null mailbox_holder in TransferableResource struct");
            result->read_lock_fences_enabled = CallWithContext(Traits::read_lock_fences_enabled, input, custom_context);
            result->is_software = CallWithContext(Traits::is_software, input, custom_context);
            result->is_overlay_candidate = CallWithContext(Traits::is_overlay_candidate, input, custom_context);
            result->is_backed_by_surface_texture = CallWithContext(Traits::is_backed_by_surface_texture, input, custom_context);
            result->wants_promotion_hint = CallWithContext(Traits::wants_promotion_hint, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::TransferableResource_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::TransferableResourceDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace cc {
namespace mojom {

    inline void TransferableResourceDataView::GetSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }
    inline void TransferableResourceDataView::GetMailboxHolderDataView(
        ::gpu::mojom::MailboxHolderDataView* output)
    {
        auto pointer = data_->mailbox_holder.Get();
        *output = ::gpu::mojom::MailboxHolderDataView(pointer, context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_TRANSFERABLE_RESOURCE_MOJOM_SHARED_H_
