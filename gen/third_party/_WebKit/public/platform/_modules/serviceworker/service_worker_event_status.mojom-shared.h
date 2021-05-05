// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_SERVICEWORKER_SERVICE_WORKER_EVENT_STATUS_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_SERVICEWORKER_SERVICE_WORKER_EVENT_STATUS_MOJOM_SHARED_H_

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
#include "third_party/WebKit/public/platform/modules/serviceworker/service_worker_event_status.mojom-shared-internal.h"

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

    enum class ServiceWorkerEventStatus : int32_t {
        COMPLETED,
        REJECTED,
        ABORTED,
        MAX = ServiceWorkerEventStatus::ABORTED,
    };

    inline std::ostream& operator<<(std::ostream& os, ServiceWorkerEventStatus value)
    {
        switch (value) {
        case ServiceWorkerEventStatus::COMPLETED:
            return os << "ServiceWorkerEventStatus::COMPLETED";
        case ServiceWorkerEventStatus::REJECTED:
            return os << "ServiceWorkerEventStatus::REJECTED";
        case ServiceWorkerEventStatus::ABORTED:
            return os << "ServiceWorkerEventStatus::{ABORTED, MAX}";
        default:
            return os << "Unknown ServiceWorkerEventStatus value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(ServiceWorkerEventStatus value)
    {
        return internal::ServiceWorkerEventStatus_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

} // namespace mojom
} // namespace blink

namespace std {

template <>
struct hash<::blink::mojom::ServiceWorkerEventStatus>
    : public mojo::internal::EnumHashImpl<::blink::mojom::ServiceWorkerEventStatus> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::blink::mojom::ServiceWorkerEventStatus, ::blink::mojom::ServiceWorkerEventStatus> {
    static ::blink::mojom::ServiceWorkerEventStatus ToMojom(::blink::mojom::ServiceWorkerEventStatus input) { return input; }
    static bool FromMojom(::blink::mojom::ServiceWorkerEventStatus input, ::blink::mojom::ServiceWorkerEventStatus* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::ServiceWorkerEventStatus, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::ServiceWorkerEventStatus, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::ServiceWorkerEventStatus>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace blink {
namespace mojom {

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_SERVICEWORKER_SERVICE_WORKER_EVENT_STATUS_MOJOM_SHARED_H_
