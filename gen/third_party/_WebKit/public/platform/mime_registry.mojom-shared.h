// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MIME_REGISTRY_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MIME_REGISTRY_MOJOM_SHARED_H_

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
#include "third_party/WebKit/public/platform/mime_registry.mojom-shared-internal.h"

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
    // Interface base classes. They are used for type safety check.
    class MimeRegistryInterfaceBase {
    };

    using MimeRegistryPtrDataView = mojo::InterfacePtrDataView<MimeRegistryInterfaceBase>;
    using MimeRegistryRequestDataView = mojo::InterfaceRequestDataView<MimeRegistryInterfaceBase>;
    using MimeRegistryAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<MimeRegistryInterfaceBase>;
    using MimeRegistryAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<MimeRegistryInterfaceBase>;
    class MimeRegistry_GetMimeTypeFromExtension_ParamsDataView {
    public:
        MimeRegistry_GetMimeTypeFromExtension_ParamsDataView() { }

        MimeRegistry_GetMimeTypeFromExtension_ParamsDataView(
            internal::MimeRegistry_GetMimeTypeFromExtension_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetExtensionDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadExtension(UserType* output)
        {
            auto* pointer = data_->extension.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::MimeRegistry_GetMimeTypeFromExtension_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class MimeRegistry_GetMimeTypeFromExtension_ResponseParamsDataView {
    public:
        MimeRegistry_GetMimeTypeFromExtension_ResponseParamsDataView() { }

        MimeRegistry_GetMimeTypeFromExtension_ResponseParamsDataView(
            internal::MimeRegistry_GetMimeTypeFromExtension_ResponseParams_Data* data,
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
        internal::MimeRegistry_GetMimeTypeFromExtension_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace blink {
namespace mojom {

    inline void MimeRegistry_GetMimeTypeFromExtension_ParamsDataView::GetExtensionDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->extension.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void MimeRegistry_GetMimeTypeFromExtension_ResponseParamsDataView::GetMimeTypeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->mime_type.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MIME_REGISTRY_MOJOM_SHARED_H_
