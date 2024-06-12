// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_SYNC_TOKEN_MOJOM_SHARED_H_
#define GPU_IPC_COMMON_SYNC_TOKEN_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "gpu/ipc/common/sync_token.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace gpu {
namespace mojom {
    class SyncTokenDataView;

} // namespace mojom
} // namespace gpu

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::gpu::mojom::SyncTokenDataView> {
        using Data = ::gpu::mojom::internal::SyncToken_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace gpu {
namespace mojom {

    enum class CommandBufferNamespace : int32_t {
        INVALID = -1,
        GPU_IO,
        IN_PROCESS,
        MOJO,
        MOJO_LOCAL,
        NUM_COMMAND_BUFFER_NAMESPACES,
    };

    inline std::ostream& operator<<(std::ostream& os, CommandBufferNamespace value)
    {
        switch (value) {
        case CommandBufferNamespace::INVALID:
            return os << "CommandBufferNamespace::INVALID";
        case CommandBufferNamespace::GPU_IO:
            return os << "CommandBufferNamespace::GPU_IO";
        case CommandBufferNamespace::IN_PROCESS:
            return os << "CommandBufferNamespace::IN_PROCESS";
        case CommandBufferNamespace::MOJO:
            return os << "CommandBufferNamespace::MOJO";
        case CommandBufferNamespace::MOJO_LOCAL:
            return os << "CommandBufferNamespace::MOJO_LOCAL";
        case CommandBufferNamespace::NUM_COMMAND_BUFFER_NAMESPACES:
            return os << "CommandBufferNamespace::NUM_COMMAND_BUFFER_NAMESPACES";
        default:
            return os << "Unknown CommandBufferNamespace value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(CommandBufferNamespace value)
    {
        return internal::CommandBufferNamespace_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class SyncTokenDataView {
    public:
        SyncTokenDataView() { }

        SyncTokenDataView(
            internal::SyncToken_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool verified_flush() const
        {
            return data_->verified_flush;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNamespaceId(UserType* output) const
        {
            auto data_value = data_->namespace_id;
            return mojo::internal::Deserialize<::gpu::mojom::CommandBufferNamespace>(
                data_value, output);
        }

        CommandBufferNamespace namespace_id() const
        {
            return static_cast<CommandBufferNamespace>(data_->namespace_id);
        }
        int32_t extra_data_field() const
        {
            return data_->extra_data_field;
        }
        uint64_t command_buffer_id() const
        {
            return data_->command_buffer_id;
        }
        uint64_t release_count() const
        {
            return data_->release_count;
        }

    private:
        internal::SyncToken_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace gpu

namespace std {

template <>
struct hash<::gpu::mojom::CommandBufferNamespace>
    : public mojo::internal::EnumHashImpl<::gpu::mojom::CommandBufferNamespace> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::gpu::mojom::CommandBufferNamespace, ::gpu::mojom::CommandBufferNamespace> {
    static ::gpu::mojom::CommandBufferNamespace ToMojom(::gpu::mojom::CommandBufferNamespace input) { return input; }
    static bool FromMojom(::gpu::mojom::CommandBufferNamespace input, ::gpu::mojom::CommandBufferNamespace* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gpu::mojom::CommandBufferNamespace, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::gpu::mojom::CommandBufferNamespace, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::gpu::mojom::CommandBufferNamespace>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gpu::mojom::SyncTokenDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gpu::mojom::SyncTokenDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gpu::mojom::internal::SyncToken_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gpu::mojom::internal::SyncToken_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gpu::mojom::internal::SyncToken_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->verified_flush = CallWithContext(Traits::verified_flush, input, custom_context);
            mojo::internal::Serialize<::gpu::mojom::CommandBufferNamespace>(
                CallWithContext(Traits::namespace_id, input, custom_context), &result->namespace_id);
            result->extra_data_field = CallWithContext(Traits::extra_data_field, input, custom_context);
            result->command_buffer_id = CallWithContext(Traits::command_buffer_id, input, custom_context);
            result->release_count = CallWithContext(Traits::release_count, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gpu::mojom::internal::SyncToken_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gpu::mojom::SyncTokenDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace gpu {
namespace mojom {

} // namespace mojom
} // namespace gpu

#endif // GPU_IPC_COMMON_SYNC_TOKEN_MOJOM_SHARED_H_
