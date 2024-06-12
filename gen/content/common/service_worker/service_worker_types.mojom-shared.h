// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_TYPES_MOJOM_SHARED_H_
#define CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_TYPES_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/service_worker/service_worker_types.mojom-shared-internal.h"
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

    enum class ServiceWorkerProviderType : int32_t {
        SERVICE_WORKER_PROVIDER_UNKNOWN,
        SERVICE_WORKER_PROVIDER_FOR_WINDOW,
        SERVICE_WORKER_PROVIDER_FOR_WORKER,
        SERVICE_WORKER_PROVIDER_FOR_SHARED_WORKER,
        SERVICE_WORKER_PROVIDER_FOR_CONTROLLER,
        SERVICE_WORKER_PROVIDER_TYPE_LAST = ServiceWorkerProviderType::SERVICE_WORKER_PROVIDER_FOR_CONTROLLER,
    };

    inline std::ostream& operator<<(std::ostream& os, ServiceWorkerProviderType value)
    {
        switch (value) {
        case ServiceWorkerProviderType::SERVICE_WORKER_PROVIDER_UNKNOWN:
            return os << "ServiceWorkerProviderType::SERVICE_WORKER_PROVIDER_UNKNOWN";
        case ServiceWorkerProviderType::SERVICE_WORKER_PROVIDER_FOR_WINDOW:
            return os << "ServiceWorkerProviderType::SERVICE_WORKER_PROVIDER_FOR_WINDOW";
        case ServiceWorkerProviderType::SERVICE_WORKER_PROVIDER_FOR_WORKER:
            return os << "ServiceWorkerProviderType::SERVICE_WORKER_PROVIDER_FOR_WORKER";
        case ServiceWorkerProviderType::SERVICE_WORKER_PROVIDER_FOR_SHARED_WORKER:
            return os << "ServiceWorkerProviderType::SERVICE_WORKER_PROVIDER_FOR_SHARED_WORKER";
        case ServiceWorkerProviderType::SERVICE_WORKER_PROVIDER_FOR_CONTROLLER:
            return os << "ServiceWorkerProviderType::{SERVICE_WORKER_PROVIDER_FOR_CONTROLLER, SERVICE_WORKER_PROVIDER_TYPE_LAST}";
        default:
            return os << "Unknown ServiceWorkerProviderType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(ServiceWorkerProviderType value)
    {
        return internal::ServiceWorkerProviderType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

} // namespace mojom
} // namespace content

namespace std {

template <>
struct hash<::content::mojom::ServiceWorkerProviderType>
    : public mojo::internal::EnumHashImpl<::content::mojom::ServiceWorkerProviderType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::content::mojom::ServiceWorkerProviderType, ::content::mojom::ServiceWorkerProviderType> {
    static ::content::mojom::ServiceWorkerProviderType ToMojom(::content::mojom::ServiceWorkerProviderType input) { return input; }
    static bool FromMojom(::content::mojom::ServiceWorkerProviderType input, ::content::mojom::ServiceWorkerProviderType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::content::mojom::ServiceWorkerProviderType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::content::mojom::ServiceWorkerProviderType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::content::mojom::ServiceWorkerProviderType>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace content {
namespace mojom {

} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_TYPES_MOJOM_SHARED_H_
