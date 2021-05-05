// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_RESOLVER_MOJOM_SHARED_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_RESOLVER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/common/file_path.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/service_manager/public/interfaces/interface_provider_spec.mojom-shared.h"
#include "services/service_manager/public/interfaces/resolver.mojom-shared-internal.h"

namespace service_manager {
namespace mojom {
    class ResolveResultDataView;

} // namespace mojom
} // namespace service_manager

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::service_manager::mojom::ResolveResultDataView> {
        using Data = ::service_manager::mojom::internal::ResolveResult_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace service_manager {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class ResolverInterfaceBase {
    };

    using ResolverPtrDataView = mojo::InterfacePtrDataView<ResolverInterfaceBase>;
    using ResolverRequestDataView = mojo::InterfaceRequestDataView<ResolverInterfaceBase>;
    using ResolverAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ResolverInterfaceBase>;
    using ResolverAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ResolverInterfaceBase>;
    class ResolveResultDataView {
    public:
        ResolveResultDataView() { }

        ResolveResultDataView(
            internal::ResolveResult_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetInterfaceProviderSpecsDataView(
            mojo::MapDataView<mojo::StringDataView, ::service_manager::mojom::InterfaceProviderSpecDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInterfaceProviderSpecs(UserType* output)
        {
            auto* pointer = data_->interface_provider_specs.Get();
            return mojo::internal::Deserialize<mojo::MapDataView<mojo::StringDataView, ::service_manager::mojom::InterfaceProviderSpecDataView>>(
                pointer, output, context_);
        }
        inline void GetPackagePathDataView(
            ::mojo::common::mojom::FilePathDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPackagePath(UserType* output)
        {
            auto* pointer = data_->package_path.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::FilePathDataView>(
                pointer, output, context_);
        }

    private:
        internal::ResolveResult_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Resolver_ResolveServiceName_ParamsDataView {
    public:
        Resolver_ResolveServiceName_ParamsDataView() { }

        Resolver_ResolveServiceName_ParamsDataView(
            internal::Resolver_ResolveServiceName_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetServiceNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadServiceName(UserType* output)
        {
            auto* pointer = data_->service_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Resolver_ResolveServiceName_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Resolver_ResolveServiceName_ResponseParamsDataView {
    public:
        Resolver_ResolveServiceName_ResponseParamsDataView() { }

        Resolver_ResolveServiceName_ResponseParamsDataView(
            internal::Resolver_ResolveServiceName_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetResultDataView(
            ResolveResultDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output)
        {
            auto* pointer = data_->result.Get();
            return mojo::internal::Deserialize<::service_manager::mojom::ResolveResultDataView>(
                pointer, output, context_);
        }
        inline void GetParentDataView(
            ResolveResultDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadParent(UserType* output)
        {
            auto* pointer = data_->parent.Get();
            return mojo::internal::Deserialize<::service_manager::mojom::ResolveResultDataView>(
                pointer, output, context_);
        }

    private:
        internal::Resolver_ResolveServiceName_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace service_manager

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::service_manager::mojom::ResolveResultDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::service_manager::mojom::ResolveResultDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::service_manager::mojom::internal::ResolveResult_Data);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_name, context);
            decltype(CallWithContext(Traits::interface_provider_specs, input, custom_context)) in_interface_provider_specs = CallWithContext(Traits::interface_provider_specs, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::MapDataView<mojo::StringDataView, ::service_manager::mojom::InterfaceProviderSpecDataView>>(
                in_interface_provider_specs, context);
            decltype(CallWithContext(Traits::package_path, input, custom_context)) in_package_path = CallWithContext(Traits::package_path, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::FilePathDataView>(
                in_package_path, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::service_manager::mojom::internal::ResolveResult_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::service_manager::mojom::internal::ResolveResult_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            typename decltype(result->name)::BaseType* name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_name, buffer, &name_ptr, context);
            result->name.Set(name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null name in ResolveResult struct");
            decltype(CallWithContext(Traits::interface_provider_specs, input, custom_context)) in_interface_provider_specs = CallWithContext(Traits::interface_provider_specs, input, custom_context);
            typename decltype(result->interface_provider_specs)::BaseType* interface_provider_specs_ptr;
            const mojo::internal::ContainerValidateParams interface_provider_specs_validate_params(
                new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)), new mojo::internal::ContainerValidateParams(0, false, nullptr));
            mojo::internal::Serialize<mojo::MapDataView<mojo::StringDataView, ::service_manager::mojom::InterfaceProviderSpecDataView>>(
                in_interface_provider_specs, buffer, &interface_provider_specs_ptr, &interface_provider_specs_validate_params,
                context);
            result->interface_provider_specs.Set(interface_provider_specs_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->interface_provider_specs.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null interface_provider_specs in ResolveResult struct");
            decltype(CallWithContext(Traits::package_path, input, custom_context)) in_package_path = CallWithContext(Traits::package_path, input, custom_context);
            typename decltype(result->package_path)::BaseType* package_path_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::FilePathDataView>(
                in_package_path, buffer, &package_path_ptr, context);
            result->package_path.Set(package_path_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->package_path.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null package_path in ResolveResult struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::service_manager::mojom::internal::ResolveResult_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::service_manager::mojom::ResolveResultDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace service_manager {
namespace mojom {

    inline void ResolveResultDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void ResolveResultDataView::GetInterfaceProviderSpecsDataView(
        mojo::MapDataView<mojo::StringDataView, ::service_manager::mojom::InterfaceProviderSpecDataView>* output)
    {
        auto pointer = data_->interface_provider_specs.Get();
        *output = mojo::MapDataView<mojo::StringDataView, ::service_manager::mojom::InterfaceProviderSpecDataView>(pointer, context_);
    }
    inline void ResolveResultDataView::GetPackagePathDataView(
        ::mojo::common::mojom::FilePathDataView* output)
    {
        auto pointer = data_->package_path.Get();
        *output = ::mojo::common::mojom::FilePathDataView(pointer, context_);
    }

    inline void Resolver_ResolveServiceName_ParamsDataView::GetServiceNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->service_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Resolver_ResolveServiceName_ResponseParamsDataView::GetResultDataView(
        ResolveResultDataView* output)
    {
        auto pointer = data_->result.Get();
        *output = ResolveResultDataView(pointer, context_);
    }
    inline void Resolver_ResolveServiceName_ResponseParamsDataView::GetParentDataView(
        ResolveResultDataView* output)
    {
        auto pointer = data_->parent.Get();
        *output = ResolveResultDataView(pointer, context_);
    }

} // namespace mojom
} // namespace service_manager

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_RESOLVER_MOJOM_SHARED_H_
