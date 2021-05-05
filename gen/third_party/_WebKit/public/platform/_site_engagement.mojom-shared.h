// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_SITE_ENGAGEMENT_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_SITE_ENGAGEMENT_MOJOM_SHARED_H_

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
#include "third_party/WebKit/public/platform/site_engagement.mojom-shared-internal.h"
#include "url/mojo/origin.mojom-shared.h"

namespace blink {
namespace mojom {

} // namespace mojom
} // namespace blink

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace blink {
namespace mojom {

    enum class EngagementLevel : int32_t {
        NONE,
        MINIMAL,
        LOW,
        MEDIUM,
        HIGH,
        MAX,
    };

    inline std::ostream& operator<<(std::ostream& os, EngagementLevel value)
    {
        switch (value) {
        case EngagementLevel::NONE:
            return os << "EngagementLevel::NONE";
        case EngagementLevel::MINIMAL:
            return os << "EngagementLevel::MINIMAL";
        case EngagementLevel::LOW:
            return os << "EngagementLevel::LOW";
        case EngagementLevel::MEDIUM:
            return os << "EngagementLevel::MEDIUM";
        case EngagementLevel::HIGH:
            return os << "EngagementLevel::HIGH";
        case EngagementLevel::MAX:
            return os << "EngagementLevel::MAX";
        default:
            return os << "Unknown EngagementLevel value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(EngagementLevel value)
    {
        return internal::EngagementLevel_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class EngagementClientInterfaceBase {
    };

    using EngagementClientPtrDataView = mojo::InterfacePtrDataView<EngagementClientInterfaceBase>;
    using EngagementClientRequestDataView = mojo::InterfaceRequestDataView<EngagementClientInterfaceBase>;
    using EngagementClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<EngagementClientInterfaceBase>;
    using EngagementClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<EngagementClientInterfaceBase>;
    class EngagementClient_SetEngagementLevel_ParamsDataView {
    public:
        EngagementClient_SetEngagementLevel_ParamsDataView() { }

        EngagementClient_SetEngagementLevel_ParamsDataView(
            internal::EngagementClient_SetEngagementLevel_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetOriginDataView(
            ::url::mojom::OriginDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrigin(UserType* output)
        {
            auto* pointer = data_->origin.Get();
            return mojo::internal::Deserialize<::url::mojom::OriginDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLevel(UserType* output) const
        {
            auto data_value = data_->level;
            return mojo::internal::Deserialize<::blink::mojom::EngagementLevel>(
                data_value, output);
        }

        EngagementLevel level() const
        {
            return static_cast<EngagementLevel>(data_->level);
        }

    private:
        internal::EngagementClient_SetEngagementLevel_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

template <>
struct hash<::blink::mojom::EngagementLevel>
    : public mojo::internal::EnumHashImpl<::blink::mojom::EngagementLevel> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::blink::mojom::EngagementLevel, ::blink::mojom::EngagementLevel> {
    static ::blink::mojom::EngagementLevel ToMojom(::blink::mojom::EngagementLevel input) { return input; }
    static bool FromMojom(::blink::mojom::EngagementLevel input, ::blink::mojom::EngagementLevel* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::EngagementLevel, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::EngagementLevel, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::EngagementLevel>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace blink {
namespace mojom {

    inline void EngagementClient_SetEngagementLevel_ParamsDataView::GetOriginDataView(
        ::url::mojom::OriginDataView* output)
    {
        auto pointer = data_->origin.Get();
        *output = ::url::mojom::OriginDataView(pointer, context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_SITE_ENGAGEMENT_MOJOM_SHARED_H_
