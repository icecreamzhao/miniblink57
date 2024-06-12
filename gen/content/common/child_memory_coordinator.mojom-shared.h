// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_CHILD_MEMORY_COORDINATOR_MOJOM_SHARED_H_
#define CONTENT_COMMON_CHILD_MEMORY_COORDINATOR_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/child_memory_coordinator.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace content {
namespace mojom {

} // namespace mojom
} // namespace content

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace content {
namespace mojom {

    enum class MemoryState : int32_t {
        UNKNOWN = -1,
        NORMAL = 0,
        THROTTLED = 1,
        SUSPENDED = 2,
    };

    inline std::ostream& operator<<(std::ostream& os, MemoryState value)
    {
        switch (value) {
        case MemoryState::UNKNOWN:
            return os << "MemoryState::UNKNOWN";
        case MemoryState::NORMAL:
            return os << "MemoryState::NORMAL";
        case MemoryState::THROTTLED:
            return os << "MemoryState::THROTTLED";
        case MemoryState::SUSPENDED:
            return os << "MemoryState::SUSPENDED";
        default:
            return os << "Unknown MemoryState value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(MemoryState value)
    {
        return internal::MemoryState_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class ChildMemoryCoordinatorInterfaceBase {
    };

    using ChildMemoryCoordinatorPtrDataView = mojo::InterfacePtrDataView<ChildMemoryCoordinatorInterfaceBase>;
    using ChildMemoryCoordinatorRequestDataView = mojo::InterfaceRequestDataView<ChildMemoryCoordinatorInterfaceBase>;
    using ChildMemoryCoordinatorAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ChildMemoryCoordinatorInterfaceBase>;
    using ChildMemoryCoordinatorAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ChildMemoryCoordinatorInterfaceBase>;
    class ChildMemoryCoordinator_OnStateChange_ParamsDataView {
    public:
        ChildMemoryCoordinator_OnStateChange_ParamsDataView() { }

        ChildMemoryCoordinator_OnStateChange_ParamsDataView(
            internal::ChildMemoryCoordinator_OnStateChange_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadState(UserType* output) const
        {
            auto data_value = data_->state;
            return mojo::internal::Deserialize<::content::mojom::MemoryState>(
                data_value, output);
        }

        MemoryState state() const
        {
            return static_cast<MemoryState>(data_->state);
        }

    private:
        internal::ChildMemoryCoordinator_OnStateChange_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace content

namespace std {

template <>
struct hash<::content::mojom::MemoryState>
    : public mojo::internal::EnumHashImpl<::content::mojom::MemoryState> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::content::mojom::MemoryState, ::content::mojom::MemoryState> {
    static ::content::mojom::MemoryState ToMojom(::content::mojom::MemoryState input) { return input; }
    static bool FromMojom(::content::mojom::MemoryState input, ::content::mojom::MemoryState* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::content::mojom::MemoryState, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::content::mojom::MemoryState, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::content::mojom::MemoryState>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace content {
namespace mojom {

} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_CHILD_MEMORY_COORDINATOR_MOJOM_SHARED_H_
