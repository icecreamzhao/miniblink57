// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_WINDOW_SERVER_TEST_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_WINDOW_SERVER_TEST_MOJOM_SHARED_H_

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
#include "services/ui/public/interfaces/window_server_test.mojom-shared-internal.h"

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
    class WindowServerTestInterfaceBase {
    };

    using WindowServerTestPtrDataView = mojo::InterfacePtrDataView<WindowServerTestInterfaceBase>;
    using WindowServerTestRequestDataView = mojo::InterfaceRequestDataView<WindowServerTestInterfaceBase>;
    using WindowServerTestAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<WindowServerTestInterfaceBase>;
    using WindowServerTestAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<WindowServerTestInterfaceBase>;
    class WindowServerTest_EnsureClientHasDrawnWindow_ParamsDataView {
    public:
        WindowServerTest_EnsureClientHasDrawnWindow_ParamsDataView() { }

        WindowServerTest_EnsureClientHasDrawnWindow_ParamsDataView(
            internal::WindowServerTest_EnsureClientHasDrawnWindow_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetClientNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadClientName(UserType* output)
        {
            auto* pointer = data_->client_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::WindowServerTest_EnsureClientHasDrawnWindow_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowServerTest_EnsureClientHasDrawnWindow_ResponseParamsDataView {
    public:
        WindowServerTest_EnsureClientHasDrawnWindow_ResponseParamsDataView() { }

        WindowServerTest_EnsureClientHasDrawnWindow_ResponseParamsDataView(
            internal::WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace ui

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace ui {
namespace mojom {

    inline void WindowServerTest_EnsureClientHasDrawnWindow_ParamsDataView::GetClientNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->client_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_WINDOW_SERVER_TEST_MOJOM_SHARED_H_
