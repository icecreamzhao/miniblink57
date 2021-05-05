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

#include "services/service_manager/public/interfaces/interface_provider_spec.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "services/service_manager/public/cpp/identity_struct_traits.h"
#include "services/service_manager/public/cpp/interface_provider_spec_struct_traits.h"
#include "services/service_manager/public/cpp/service_info_struct_traits.h"
namespace service_manager {
namespace mojom {
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
} // namespace mojom
} // namespace service_manager

namespace mojo {

// static
bool StructTraits<::service_manager::mojom::InterfaceSet::DataView, ::service_manager::mojom::InterfaceSetPtr>::Read(
    ::service_manager::mojom::InterfaceSet::DataView input,
    ::service_manager::mojom::InterfaceSetPtr* output)
{
    bool success = true;
    ::service_manager::mojom::InterfaceSetPtr result(::service_manager::mojom::InterfaceSet::New());

    if (!input.ReadInterfaces(&result->interfaces))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::service_manager::mojom::CapabilitySet::DataView, ::service_manager::mojom::CapabilitySetPtr>::Read(
    ::service_manager::mojom::CapabilitySet::DataView input,
    ::service_manager::mojom::CapabilitySetPtr* output)
{
    bool success = true;
    ::service_manager::mojom::CapabilitySetPtr result(::service_manager::mojom::CapabilitySet::New());

    if (!input.ReadCapabilities(&result->capabilities))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::service_manager::mojom::InterfaceProviderSpec::DataView, ::service_manager::mojom::InterfaceProviderSpecPtr>::Read(
    ::service_manager::mojom::InterfaceProviderSpec::DataView input,
    ::service_manager::mojom::InterfaceProviderSpecPtr* output)
{
    bool success = true;
    ::service_manager::mojom::InterfaceProviderSpecPtr result(::service_manager::mojom::InterfaceProviderSpec::New());

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