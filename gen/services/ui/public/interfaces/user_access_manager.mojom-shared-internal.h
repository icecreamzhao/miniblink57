// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_USER_ACCESS_MANAGER_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_PUBLIC_INTERFACES_USER_ACCESS_MANAGER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace ui {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kUserAccessManager_SetActiveUser_Name = 0;
        class UserAccessManager_SetActiveUser_Params_Data {
        public:
            static UserAccessManager_SetActiveUser_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(UserAccessManager_SetActiveUser_Params_Data))) UserAccessManager_SetActiveUser_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> user_id;

        private:
            UserAccessManager_SetActiveUser_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~UserAccessManager_SetActiveUser_Params_Data() = delete;
        };
        static_assert(sizeof(UserAccessManager_SetActiveUser_Params_Data) == 16,
            "Bad sizeof(UserAccessManager_SetActiveUser_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_USER_ACCESS_MANAGER_MOJOM_SHARED_INTERNAL_H_