// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_ACCESSIBILITY_MANAGER_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_ACCESSIBILITY_MANAGER_MOJOM_SHARED_H_

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
#include "services/ui/public/interfaces/accessibility_manager.mojom-shared-internal.h"

namespace ui {
namespace mojom {

} // namespace mojom
} // namespace ui

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace ui {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class AccessibilityManagerInterfaceBase {
    };

    using AccessibilityManagerPtrDataView = mojo::InterfacePtrDataView<AccessibilityManagerInterfaceBase>;
    using AccessibilityManagerRequestDataView = mojo::InterfaceRequestDataView<AccessibilityManagerInterfaceBase>;
    using AccessibilityManagerAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<AccessibilityManagerInterfaceBase>;
    using AccessibilityManagerAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<AccessibilityManagerInterfaceBase>;
    class AccessibilityManager_SetHighContrastMode_ParamsDataView {
    public:
        AccessibilityManager_SetHighContrastMode_ParamsDataView() { }

        AccessibilityManager_SetHighContrastMode_ParamsDataView(
            internal::AccessibilityManager_SetHighContrastMode_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool enabled() const
        {
            return data_->enabled;
        }

    private:
        internal::AccessibilityManager_SetHighContrastMode_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace ui

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace ui {
namespace mojom {

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_ACCESSIBILITY_MANAGER_MOJOM_SHARED_H_
