// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_SENSITIVE_INPUT_VISIBILITY_SENSITIVE_INPUT_VISIBILITY_SERVICE_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_SENSITIVE_INPUT_VISIBILITY_SENSITIVE_INPUT_VISIBILITY_SERVICE_MOJOM_SHARED_H_

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
#include "third_party/WebKit/public/platform/modules/sensitive_input_visibility/sensitive_input_visibility_service.mojom-shared-internal.h"

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
    class SensitiveInputVisibilityServiceInterfaceBase {
    };

    using SensitiveInputVisibilityServicePtrDataView = mojo::InterfacePtrDataView<SensitiveInputVisibilityServiceInterfaceBase>;
    using SensitiveInputVisibilityServiceRequestDataView = mojo::InterfaceRequestDataView<SensitiveInputVisibilityServiceInterfaceBase>;
    using SensitiveInputVisibilityServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<SensitiveInputVisibilityServiceInterfaceBase>;
    using SensitiveInputVisibilityServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<SensitiveInputVisibilityServiceInterfaceBase>;
    class SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_ParamsDataView {
    public:
        SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_ParamsDataView() { }

        SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_ParamsDataView(
            internal::SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params_Data* data_ = nullptr;
    };

    class SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_ParamsDataView {
    public:
        SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_ParamsDataView() { }

        SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_ParamsDataView(
            internal::SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace blink {
namespace mojom {

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_SENSITIVE_INPUT_VISIBILITY_SENSITIVE_INPUT_VISIBILITY_SERVICE_MOJOM_SHARED_H_
