// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_TEST_DISPLAY_CONTROLLER_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_TEST_DISPLAY_CONTROLLER_MOJOM_SHARED_H_

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
#include "services/ui/public/interfaces/display/test_display_controller.mojom-shared-internal.h"

namespace display {
namespace mojom {

} // namespace mojom
} // namespace display

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace display {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class TestDisplayControllerInterfaceBase {
    };

    using TestDisplayControllerPtrDataView = mojo::InterfacePtrDataView<TestDisplayControllerInterfaceBase>;
    using TestDisplayControllerRequestDataView = mojo::InterfaceRequestDataView<TestDisplayControllerInterfaceBase>;
    using TestDisplayControllerAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<TestDisplayControllerInterfaceBase>;
    using TestDisplayControllerAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<TestDisplayControllerInterfaceBase>;
    class TestDisplayController_ToggleAddRemoveDisplay_ParamsDataView {
    public:
        TestDisplayController_ToggleAddRemoveDisplay_ParamsDataView() { }

        TestDisplayController_ToggleAddRemoveDisplay_ParamsDataView(
            internal::TestDisplayController_ToggleAddRemoveDisplay_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::TestDisplayController_ToggleAddRemoveDisplay_Params_Data* data_ = nullptr;
    };

    class TestDisplayController_ToggleDisplayResolution_ParamsDataView {
    public:
        TestDisplayController_ToggleDisplayResolution_ParamsDataView() { }

        TestDisplayController_ToggleDisplayResolution_ParamsDataView(
            internal::TestDisplayController_ToggleDisplayResolution_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::TestDisplayController_ToggleDisplayResolution_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace display

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace display {
namespace mojom {

} // namespace mojom
} // namespace display

#endif // SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_TEST_DISPLAY_CONTROLLER_MOJOM_SHARED_H_
