// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_INTERFACE_PROVIDER_SPEC_MOJOM_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_INTERFACE_PROVIDER_SPEC_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
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
#include "services/service_manager/public/cpp/identity.h"
#include "services/service_manager/public/cpp/interface_provider_spec.h"
#include "services/service_manager/public/cpp/service_info.h"
#include "services/service_manager/public/interfaces/interface_provider_spec.mojom-shared.h"
#include <string>
#include <vector>

namespace service_manager {
namespace mojom {
    extern const char kServiceManager_ConnectorSpec[];
    class InterfaceSet;
    using InterfaceSetPtr = mojo::StructPtr<InterfaceSet>;

    class CapabilitySet;
    using CapabilitySetPtr = mojo::StructPtr<CapabilitySet>;

    class InterfaceProviderSpec;
    using InterfaceProviderSpecPtr = mojo::StructPtr<InterfaceProviderSpec>;

    class InterfaceSet {
    public:
        using DataView = InterfaceSetDataView;
        using Data_ = internal::InterfaceSet_Data;

        static InterfaceSetPtr New();

        template <typename U>
        static InterfaceSetPtr From(const U& u)
        {
            return mojo::TypeConverter<InterfaceSetPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, InterfaceSet>::Convert(*this);
        }

        InterfaceSet();
        ~InterfaceSet();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = InterfaceSetPtr>
        InterfaceSetPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, InterfaceSet>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                InterfaceSet::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                InterfaceSet::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::vector<std::string> interfaces;
    };

    class CapabilitySet {
    public:
        using DataView = CapabilitySetDataView;
        using Data_ = internal::CapabilitySet_Data;

        static CapabilitySetPtr New();

        template <typename U>
        static CapabilitySetPtr From(const U& u)
        {
            return mojo::TypeConverter<CapabilitySetPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, CapabilitySet>::Convert(*this);
        }

        CapabilitySet();
        ~CapabilitySet();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = CapabilitySetPtr>
        CapabilitySetPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, CapabilitySet>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                CapabilitySet::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                CapabilitySet::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::vector<std::string> capabilities;
    };

    class InterfaceProviderSpec {
    public:
        using DataView = InterfaceProviderSpecDataView;
        using Data_ = internal::InterfaceProviderSpec_Data;

        static InterfaceProviderSpecPtr New();

        template <typename U>
        static InterfaceProviderSpecPtr From(const U& u)
        {
            return mojo::TypeConverter<InterfaceProviderSpecPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, InterfaceProviderSpec>::Convert(*this);
        }

        InterfaceProviderSpec();
        ~InterfaceProviderSpec();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = InterfaceProviderSpecPtr>
        InterfaceProviderSpecPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, InterfaceProviderSpec>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                InterfaceProviderSpec::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                InterfaceProviderSpec::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::unordered_map<std::string, ::service_manager::InterfaceSet> provides;
        std::unordered_map<std::string, ::service_manager::CapabilitySet> requires;
    };

    template <typename StructPtrType>
    InterfaceSetPtr InterfaceSet::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->interfaces = mojo::internal::Clone(interfaces);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, InterfaceSet>::value>::type*>
    bool InterfaceSet::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->interfaces, other.interfaces))
            return false;
        return true;
    }
    template <typename StructPtrType>
    CapabilitySetPtr CapabilitySet::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->capabilities = mojo::internal::Clone(capabilities);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, CapabilitySet>::value>::type*>
    bool CapabilitySet::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->capabilities, other.capabilities))
            return false;
        return true;
    }
    template <typename StructPtrType>
    InterfaceProviderSpecPtr InterfaceProviderSpec::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->provides = mojo::internal::Clone(provides);
        rv->requires = mojo::internal::Clone(requires);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, InterfaceProviderSpec>::value>::type*>
    bool InterfaceProviderSpec::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->provides, other.provides))
            return false;
        if (!mojo::internal::Equals(this->requires, other.requires))
            return false;
        return true;
    }

} // namespace mojom
} // namespace service_manager

namespace mojo {

template <>
struct StructTraits<::service_manager::mojom::InterfaceSet::DataView,
    ::service_manager::mojom::InterfaceSetPtr> {
    static bool IsNull(const ::service_manager::mojom::InterfaceSetPtr& input) { return !input; }
    static void SetToNull(::service_manager::mojom::InterfaceSetPtr* output) { output->reset(); }

    static const decltype(::service_manager::mojom::InterfaceSet::interfaces)& interfaces(
        const ::service_manager::mojom::InterfaceSetPtr& input)
    {
        return input->interfaces;
    }

    static bool Read(::service_manager::mojom::InterfaceSet::DataView input, ::service_manager::mojom::InterfaceSetPtr* output);
};

template <>
struct StructTraits<::service_manager::mojom::CapabilitySet::DataView,
    ::service_manager::mojom::CapabilitySetPtr> {
    static bool IsNull(const ::service_manager::mojom::CapabilitySetPtr& input) { return !input; }
    static void SetToNull(::service_manager::mojom::CapabilitySetPtr* output) { output->reset(); }

    static const decltype(::service_manager::mojom::CapabilitySet::capabilities)& capabilities(
        const ::service_manager::mojom::CapabilitySetPtr& input)
    {
        return input->capabilities;
    }

    static bool Read(::service_manager::mojom::CapabilitySet::DataView input, ::service_manager::mojom::CapabilitySetPtr* output);
};

template <>
struct StructTraits<::service_manager::mojom::InterfaceProviderSpec::DataView,
    ::service_manager::mojom::InterfaceProviderSpecPtr> {
    static bool IsNull(const ::service_manager::mojom::InterfaceProviderSpecPtr& input) { return !input; }
    static void SetToNull(::service_manager::mojom::InterfaceProviderSpecPtr* output) { output->reset(); }

    static const decltype(::service_manager::mojom::InterfaceProviderSpec::provides)& provides(
        const ::service_manager::mojom::InterfaceProviderSpecPtr& input)
    {
        return input->provides;
    }

    static const decltype(::service_manager::mojom::InterfaceProviderSpec::requires)& requires(
        const ::service_manager::mojom::InterfaceProviderSpecPtr& input)
    {
        return input->requires;
    }

    static bool Read(::service_manager::mojom::InterfaceProviderSpec::DataView input, ::service_manager::mojom::InterfaceProviderSpecPtr* output);
};

} // namespace mojo

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_INTERFACE_PROVIDER_SPEC_MOJOM_H_