// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_HYPHENATION_HYPHENATION_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_HYPHENATION_HYPHENATION_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/common/file.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "third_party/WebKit/public/platform/modules/hyphenation/hyphenation.mojom-shared-internal.h"

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
    class HyphenationInterfaceBase {
    };

    using HyphenationPtrDataView = mojo::InterfacePtrDataView<HyphenationInterfaceBase>;
    using HyphenationRequestDataView = mojo::InterfaceRequestDataView<HyphenationInterfaceBase>;
    using HyphenationAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<HyphenationInterfaceBase>;
    using HyphenationAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<HyphenationInterfaceBase>;
    class Hyphenation_OpenDictionary_ParamsDataView {
    public:
        Hyphenation_OpenDictionary_ParamsDataView() { }

        Hyphenation_OpenDictionary_ParamsDataView(
            internal::Hyphenation_OpenDictionary_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetLocaleDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLocale(UserType* output)
        {
            auto* pointer = data_->locale.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Hyphenation_OpenDictionary_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Hyphenation_OpenDictionary_ResponseParamsDataView {
    public:
        Hyphenation_OpenDictionary_ResponseParamsDataView() { }

        Hyphenation_OpenDictionary_ResponseParamsDataView(
            internal::Hyphenation_OpenDictionary_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetHyphenationDictionaryHandleDataView(
            ::mojo::common::mojom::FileDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadHyphenationDictionaryHandle(UserType* output)
        {
            auto* pointer = data_->hyphenation_dictionary_handle.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::FileDataView>(
                pointer, output, context_);
        }

    private:
        internal::Hyphenation_OpenDictionary_ResponseParams_Data* data_ = nullptr;
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

    inline void Hyphenation_OpenDictionary_ParamsDataView::GetLocaleDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->locale.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Hyphenation_OpenDictionary_ResponseParamsDataView::GetHyphenationDictionaryHandleDataView(
        ::mojo::common::mojom::FileDataView* output)
    {
        auto pointer = data_->hyphenation_dictionary_handle.Get();
        *output = ::mojo::common::mojom::FileDataView(pointer, context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_HYPHENATION_HYPHENATION_MOJOM_SHARED_H_
