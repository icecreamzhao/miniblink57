// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_SERVICE_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_SERVICE_MOJOM_SHARED_H_

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
#include "third_party/WebKit/public/platform/modules/notifications/notification_service.mojom-shared-internal.h"
#include "third_party/WebKit/public/platform/modules/permissions/permission_status.mojom-shared.h"

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
    class NotificationServiceInterfaceBase {
    };

    using NotificationServicePtrDataView = mojo::InterfacePtrDataView<NotificationServiceInterfaceBase>;
    using NotificationServiceRequestDataView = mojo::InterfaceRequestDataView<NotificationServiceInterfaceBase>;
    using NotificationServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<NotificationServiceInterfaceBase>;
    using NotificationServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<NotificationServiceInterfaceBase>;
    class NotificationService_GetPermissionStatus_ParamsDataView {
    public:
        NotificationService_GetPermissionStatus_ParamsDataView() { }

        NotificationService_GetPermissionStatus_ParamsDataView(
            internal::NotificationService_GetPermissionStatus_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetOriginDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrigin(UserType* output)
        {
            auto* pointer = data_->origin.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::NotificationService_GetPermissionStatus_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class NotificationService_GetPermissionStatus_ResponseParamsDataView {
    public:
        NotificationService_GetPermissionStatus_ResponseParamsDataView() { }

        NotificationService_GetPermissionStatus_ResponseParamsDataView(
            internal::NotificationService_GetPermissionStatus_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::blink::mojom::PermissionStatus>(
                data_value, output);
        }

        ::blink::mojom::PermissionStatus status() const
        {
            return static_cast<::blink::mojom::PermissionStatus>(data_->status);
        }

    private:
        internal::NotificationService_GetPermissionStatus_ResponseParams_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace blink {
namespace mojom {

    inline void NotificationService_GetPermissionStatus_ParamsDataView::GetOriginDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->origin.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_SERVICE_MOJOM_SHARED_H_
