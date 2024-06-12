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

#include "services/service_manager/public/interfaces/interface_provider_spec.mojom-blink.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/Source/platform/mojo/CommonCustomTypesStructTraits.h"
namespace service_manager {
namespace mojom {
    namespace blink {
        const char kServiceManager_ConnectorSpec[] = "service_manager:connector"; // static
        InterfaceSetPtr InterfaceSet::New()
        {
            InterfaceSetPtr rv;
            mojo::internal::StructHelper<InterfaceSet>::Initialize(&rv);
            return rv;
        }

        InterfaceSet::InterfaceSet()
            : interfaces()
        {
        }

        InterfaceSet::~InterfaceSet()
        {
        } // static
        CapabilitySetPtr CapabilitySet::New()
        {
            CapabilitySetPtr rv;
            mojo::internal::StructHelper<CapabilitySet>::Initialize(&rv);
            return rv;
        }

        CapabilitySet::CapabilitySet()
            : capabilities()
        {
        }

        CapabilitySet::~CapabilitySet()
        {
        } // static
        InterfaceProviderSpecPtr InterfaceProviderSpec::New()
        {
            InterfaceProviderSpecPtr rv;
            mojo::internal::StructHelper<InterfaceProviderSpec>::Initialize(&rv);
            return rv;
        }

        InterfaceProviderSpec::InterfaceProviderSpec()
            : provides()
            , requires()
        {
        }

        InterfaceProviderSpec::~InterfaceProviderSpec()
        {
        }
    } // namespace blink
} // namespace mojom
} // namespace service_manager

namespace mojo {

// static
bool StructTraits<::service_manager::mojom::blink::InterfaceSet::DataView, ::service_manager::mojom::blink::InterfaceSetPtr>::Read(
    ::service_manager::mojom::blink::InterfaceSet::DataView input,
    ::service_manager::mojom::blink::InterfaceSetPtr* output)
{
    bool success = true;
    ::service_manager::mojom::blink::InterfaceSetPtr result(::service_manager::mojom::blink::InterfaceSet::New());

    if (!input.ReadInterfaces(&result->interfaces))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::service_manager::mojom::blink::CapabilitySet::DataView, ::service_manager::mojom::blink::CapabilitySetPtr>::Read(
    ::service_manager::mojom::blink::CapabilitySet::DataView input,
    ::service_manager::mojom::blink::CapabilitySetPtr* output)
{
    bool success = true;
    ::service_manager::mojom::blink::CapabilitySetPtr result(::service_manager::mojom::blink::CapabilitySet::New());

    if (!input.ReadCapabilities(&result->capabilities))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::service_manager::mojom::blink::InterfaceProviderSpec::DataView, ::service_manager::mojom::blink::InterfaceProviderSpecPtr>::Read(
    ::service_manager::mojom::blink::InterfaceProviderSpec::DataView input,
    ::service_manager::mojom::blink::InterfaceProviderSpecPtr* output)
{
    bool success = true;
    ::service_manager::mojom::blink::InterfaceProviderSpecPtr result(::service_manager::mojom::blink::InterfaceProviderSpec::New());

    if (!input.ReadProvides(&result->provides))
        success = false;
    if (!input.ReadRequires(&result->requires))
        success = false;
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif