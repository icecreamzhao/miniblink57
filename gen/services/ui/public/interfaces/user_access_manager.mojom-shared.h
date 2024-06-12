// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_USER_ACCESS_MANAGER_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_USER_ACCESS_MANAGER_MOJOM_SHARED_H_

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
#include "services/ui/public/interfaces/user_access_manager.mojom-shared-internal.h"

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
    class UserAccessManagerInterfaceBase {
    };

    using UserAccessManagerPtrDataView = mojo::InterfacePtrDataView<UserAccessManagerInterfaceBase>;
    using UserAccessManagerRequestDataView = mojo::InterfaceRequestDataView<UserAccessManagerInterfaceBase>;
    using UserAccessManagerAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<UserAccessManagerInterfaceBase>;
    using UserAccessManagerAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<UserAccessManagerInterfaceBase>;
    class UserAccessManager_SetActiveUser_ParamsDataView {
    public:
        UserAccessManager_SetActiveUser_ParamsDataView() { }

        UserAccessManager_SetActiveUser_ParamsDataView(
            internal::UserAccessManager_SetActiveUser_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetUserIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUserId(UserType* output)
        {
            auto* pointer = data_->user_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::UserAccessManager_SetActiveUser_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace ui

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace ui {
namespace mojom {

    inline void UserAccessManager_SetActiveUser_ParamsDataView::GetUserIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->user_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_USER_ACCESS_MANAGER_MOJOM_SHARED_H_
