// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_NATIVE_TYPES_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_NATIVE_TYPES_MOJOM_SHARED_INTERNAL_H_

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
namespace content {
namespace mojom {
    namespace internal {
        using FrameOwnerProperties_Data = mojo::internal::NativeStruct_Data;
        using FrameReplicationState_Data = mojo::internal::NativeStruct_Data;
        using RendererPreferences_Data = mojo::internal::NativeStruct_Data;
        using ResizeParams_Data = mojo::internal::NativeStruct_Data;
        using WebPreferences_Data = mojo::internal::NativeStruct_Data;
        using ScrollbarButtonsPlacement_Data = mojo::internal::NativeEnum_Data;
        using ScrollerStyle_Data = mojo::internal::NativeEnum_Data;
        using NetworkConnectionType_Data = mojo::internal::NativeEnum_Data;
        using WebPopupType_Data = mojo::internal::NativeEnum_Data;

#pragma pack(push, 1)

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_NATIVE_TYPES_MOJOM_SHARED_INTERNAL_H_