// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_INSTALLATION_INSTALLATION_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_INSTALLATION_INSTALLATION_MOJOM_SHARED_H_

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
#include "third_party/WebKit/public/platform/modules/installation/installation.mojom-shared-internal.h"

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
    class InstallationServiceInterfaceBase {
    };

    using InstallationServicePtrDataView = mojo::InterfacePtrDataView<InstallationServiceInterfaceBase>;
    using InstallationServiceRequestDataView = mojo::InterfaceRequestDataView<InstallationServiceInterfaceBase>;
    using InstallationServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<InstallationServiceInterfaceBase>;
    using InstallationServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<InstallationServiceInterfaceBase>;
    class InstallationService_OnInstall_ParamsDataView {
    public:
        InstallationService_OnInstall_ParamsDataView() { }

        InstallationService_OnInstall_ParamsDataView(
            internal::InstallationService_OnInstall_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::InstallationService_OnInstall_Params_Data* data_ = nullptr;
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

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_INSTALLATION_INSTALLATION_MOJOM_SHARED_H_
