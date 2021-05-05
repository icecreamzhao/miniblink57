// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_COMMON_FILE_PATH_MOJOM_SHARED_INTERNAL_H_
#define MOJO_COMMON_FILE_PATH_MOJOM_SHARED_INTERNAL_H_

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
namespace mojo {
namespace common {
    namespace mojom {
        namespace internal {
            using FilePath_Data = mojo::internal::NativeStruct_Data;

#pragma pack(push, 1)

#pragma pack(pop)

        } // namespace internal
    } // namespace mojom
} // namespace common
} // namespace mojo

#endif // MOJO_COMMON_FILE_PATH_MOJOM_SHARED_INTERNAL_H_