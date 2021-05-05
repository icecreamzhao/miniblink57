// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_INSTALLATION_INSTALLATION_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_INSTALLATION_INSTALLATION_MOJOM_SHARED_INTERNAL_H_

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
namespace blink {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kInstallationService_OnInstall_Name = 0;
        class InstallationService_OnInstall_Params_Data {
        public:
            static InstallationService_OnInstall_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(InstallationService_OnInstall_Params_Data))) InstallationService_OnInstall_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            InstallationService_OnInstall_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~InstallationService_OnInstall_Params_Data() = delete;
        };
        static_assert(sizeof(InstallationService_OnInstall_Params_Data) == 8,
            "Bad sizeof(InstallationService_OnInstall_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_INSTALLATION_INSTALLATION_MOJOM_SHARED_INTERNAL_H_