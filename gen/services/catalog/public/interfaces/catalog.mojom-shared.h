// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_CATALOG_PUBLIC_INTERFACES_CATALOG_MOJOM_SHARED_H_
#define SERVICES_CATALOG_PUBLIC_INTERFACES_CATALOG_MOJOM_SHARED_H_

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
#include "services/catalog/public/interfaces/catalog.mojom-shared-internal.h"

namespace catalog {
namespace mojom {
    class EntryDataView;

} // namespace mojom
} // namespace catalog

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::catalog::mojom::EntryDataView> {
        using Data = ::catalog::mojom::internal::Entry_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace catalog {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class CatalogInterfaceBase {
    };

    using CatalogPtrDataView = mojo::InterfacePtrDataView<CatalogInterfaceBase>;
    using CatalogRequestDataView = mojo::InterfaceRequestDataView<CatalogInterfaceBase>;
    using CatalogAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<CatalogInterfaceBase>;
    using CatalogAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<CatalogInterfaceBase>;
    class CatalogControlInterfaceBase {
    };

    using CatalogControlPtrDataView = mojo::InterfacePtrDataView<CatalogControlInterfaceBase>;
    using CatalogControlRequestDataView = mojo::InterfaceRequestDataView<CatalogControlInterfaceBase>;
    using CatalogControlAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<CatalogControlInterfaceBase>;
    using CatalogControlAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<CatalogControlInterfaceBase>;
    class EntryDataView {
    public:
        EntryDataView() { }

        EntryDataView(
            internal::Entry_Data* data,
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
        inline void GetDisplayNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDisplayName(UserType* output)
        {
            auto* pointer = data_->display_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Entry_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Catalog_GetEntries_ParamsDataView {
    public:
        Catalog_GetEntries_ParamsDataView() { }

        Catalog_GetEntries_ParamsDataView(
            internal::Catalog_GetEntries_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetNamesDataView(
            mojo::ArrayDataView<mojo::StringDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNames(UserType* output)
        {
            auto* pointer = data_->names.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<mojo::StringDataView>>(
                pointer, output, context_);
        }

    private:
        internal::Catalog_GetEntries_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Catalog_GetEntries_ResponseParamsDataView {
    public:
        Catalog_GetEntries_ResponseParamsDataView() { }

        Catalog_GetEntries_ResponseParamsDataView(
            internal::Catalog_GetEntries_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetEntriesDataView(
            mojo::ArrayDataView<EntryDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEntries(UserType* output)
        {
            auto* pointer = data_->entries.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::catalog::mojom::EntryDataView>>(
                pointer, output, context_);
        }

    private:
        internal::Catalog_GetEntries_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Catalog_GetEntriesProvidingCapability_ParamsDataView {
    public:
        Catalog_GetEntriesProvidingCapability_ParamsDataView() { }

        Catalog_GetEntriesProvidingCapability_ParamsDataView(
            internal::Catalog_GetEntriesProvidingCapability_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetCapabilityDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCapability(UserType* output)
        {
            auto* pointer = data_->capability.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Catalog_GetEntriesProvidingCapability_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Catalog_GetEntriesProvidingCapability_ResponseParamsDataView {
    public:
        Catalog_GetEntriesProvidingCapability_ResponseParamsDataView() { }

        Catalog_GetEntriesProvidingCapability_ResponseParamsDataView(
            internal::Catalog_GetEntriesProvidingCapability_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetEntriesDataView(
            mojo::ArrayDataView<EntryDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEntries(UserType* output)
        {
            auto* pointer = data_->entries.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::catalog::mojom::EntryDataView>>(
                pointer, output, context_);
        }

    private:
        internal::Catalog_GetEntriesProvidingCapability_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Catalog_GetEntriesConsumingMIMEType_ParamsDataView {
    public:
        Catalog_GetEntriesConsumingMIMEType_ParamsDataView() { }

        Catalog_GetEntriesConsumingMIMEType_ParamsDataView(
            internal::Catalog_GetEntriesConsumingMIMEType_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetMimeTypeDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMimeType(UserType* output)
        {
            auto* pointer = data_->mime_type.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Catalog_GetEntriesConsumingMIMEType_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Catalog_GetEntriesConsumingMIMEType_ResponseParamsDataView {
    public:
        Catalog_GetEntriesConsumingMIMEType_ResponseParamsDataView() { }

        Catalog_GetEntriesConsumingMIMEType_ResponseParamsDataView(
            internal::Catalog_GetEntriesConsumingMIMEType_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetEntriesDataView(
            mojo::ArrayDataView<EntryDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEntries(UserType* output)
        {
            auto* pointer = data_->entries.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::catalog::mojom::EntryDataView>>(
                pointer, output, context_);
        }

    private:
        internal::Catalog_GetEntriesConsumingMIMEType_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Catalog_GetEntriesSupportingScheme_ParamsDataView {
    public:
        Catalog_GetEntriesSupportingScheme_ParamsDataView() { }

        Catalog_GetEntriesSupportingScheme_ParamsDataView(
            internal::Catalog_GetEntriesSupportingScheme_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetProtocolSchemeDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadProtocolScheme(UserType* output)
        {
            auto* pointer = data_->protocol_scheme.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Catalog_GetEntriesSupportingScheme_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Catalog_GetEntriesSupportingScheme_ResponseParamsDataView {
    public:
        Catalog_GetEntriesSupportingScheme_ResponseParamsDataView() { }

        Catalog_GetEntriesSupportingScheme_ResponseParamsDataView(
            internal::Catalog_GetEntriesSupportingScheme_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetEntriesDataView(
            mojo::ArrayDataView<EntryDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEntries(UserType* output)
        {
            auto* pointer = data_->entries.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::catalog::mojom::EntryDataView>>(
                pointer, output, context_);
        }

    private:
        internal::Catalog_GetEntriesSupportingScheme_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class CatalogControl_OverrideManifestPath_ParamsDataView {
    public:
        CatalogControl_OverrideManifestPath_ParamsDataView() { }

        CatalogControl_OverrideManifestPath_ParamsDataView(
            internal::CatalogControl_OverrideManifestPath_Params_Data* data,
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
        inline void GetPathDataView(
            ::mojo::common::mojom::FilePathDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPath(UserType* output)
        {
            auto* pointer = data_->path.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::FilePathDataView>(
                pointer, output, context_);
        }

    private:
        internal::CatalogControl_OverrideManifestPath_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class CatalogControl_OverrideManifestPath_ResponseParamsDataView {
    public:
        CatalogControl_OverrideManifestPath_ResponseParamsDataView() { }

        CatalogControl_OverrideManifestPath_ResponseParamsDataView(
            internal::CatalogControl_OverrideManifestPath_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::CatalogControl_OverrideManifestPath_ResponseParams_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace catalog

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::catalog::mojom::EntryDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::catalog::mojom::EntryDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::catalog::mojom::internal::Entry_Data);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_name, context);
            decltype(CallWithContext(Traits::display_name, input, custom_context)) in_display_name = CallWithContext(Traits::display_name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_display_name, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::catalog::mojom::internal::Entry_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::catalog::mojom::internal::Entry_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            typename decltype(result->name)::BaseType* name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_name, buffer, &name_ptr, context);
            result->name.Set(name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null name in Entry struct");
            decltype(CallWithContext(Traits::display_name, input, custom_context)) in_display_name = CallWithContext(Traits::display_name, input, custom_context);
            typename decltype(result->display_name)::BaseType* display_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_display_name, buffer, &display_name_ptr, context);
            result->display_name.Set(display_name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->display_name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null display_name in Entry struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::catalog::mojom::internal::Entry_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::catalog::mojom::EntryDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace catalog {
namespace mojom {

    inline void EntryDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void EntryDataView::GetDisplayNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->display_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Catalog_GetEntries_ParamsDataView::GetNamesDataView(
        mojo::ArrayDataView<mojo::StringDataView>* output)
    {
        auto pointer = data_->names.Get();
        *output = mojo::ArrayDataView<mojo::StringDataView>(pointer, context_);
    }

    inline void Catalog_GetEntries_ResponseParamsDataView::GetEntriesDataView(
        mojo::ArrayDataView<EntryDataView>* output)
    {
        auto pointer = data_->entries.Get();
        *output = mojo::ArrayDataView<EntryDataView>(pointer, context_);
    }

    inline void Catalog_GetEntriesProvidingCapability_ParamsDataView::GetCapabilityDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->capability.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Catalog_GetEntriesProvidingCapability_ResponseParamsDataView::GetEntriesDataView(
        mojo::ArrayDataView<EntryDataView>* output)
    {
        auto pointer = data_->entries.Get();
        *output = mojo::ArrayDataView<EntryDataView>(pointer, context_);
    }

    inline void Catalog_GetEntriesConsumingMIMEType_ParamsDataView::GetMimeTypeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->mime_type.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Catalog_GetEntriesConsumingMIMEType_ResponseParamsDataView::GetEntriesDataView(
        mojo::ArrayDataView<EntryDataView>* output)
    {
        auto pointer = data_->entries.Get();
        *output = mojo::ArrayDataView<EntryDataView>(pointer, context_);
    }

    inline void Catalog_GetEntriesSupportingScheme_ParamsDataView::GetProtocolSchemeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->protocol_scheme.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Catalog_GetEntriesSupportingScheme_ResponseParamsDataView::GetEntriesDataView(
        mojo::ArrayDataView<EntryDataView>* output)
    {
        auto pointer = data_->entries.Get();
        *output = mojo::ArrayDataView<EntryDataView>(pointer, context_);
    }

    inline void CatalogControl_OverrideManifestPath_ParamsDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void CatalogControl_OverrideManifestPath_ParamsDataView::GetPathDataView(
        ::mojo::common::mojom::FilePathDataView* output)
    {
        auto pointer = data_->path.Get();
        *output = ::mojo::common::mojom::FilePathDataView(pointer, context_);
    }

} // namespace mojom
} // namespace catalog

#endif // SERVICES_CATALOG_PUBLIC_INTERFACES_CATALOG_MOJOM_SHARED_H_
