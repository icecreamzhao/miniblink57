// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifdef BASE_ALLOCATOR_ALLOCATOR_SHIM_OVERRIDE_LINKER_WRAPPED_SYMBOLS_H_
#error This header is meant to be included only once by allocator_shim.cc
#endif
#define BASE_ALLOCATOR_ALLOCATOR_SHIM_OVERRIDE_LINKER_WRAPPED_SYMBOLS_H_

// This header overrides the __wrap_X symbols when using the link-time
// -Wl,-wrap,malloc shim-layer approach (see README.md).
// All references to malloc, free, etc. within the linker unit that gets the
// -wrap linker flags (e.g., libchrome.so) will be rewritten to the
// linker as references to __wrap_malloc, __wrap_free, which are defined here.

#include "base/allocator/allocator_shim_internals.h"

extern "C" {

SHIM_ALWAYS_EXPORT void* __wrap_calloc(size_t, size_t)
    SHIM_ALIAS_SYMBOL(ShimCalloc);

SHIM_ALWAYS_EXPORT void __wrap_free(void*)
    SHIM_ALIAS_SYMBOL(ShimFree);

SHIM_ALWAYS_EXPORT void* __wrap_malloc(size_t)
    SHIM_ALIAS_SYMBOL(ShimMalloc);

SHIM_ALWAYS_EXPORT void* __wrap_memalign(size_t, size_t)
    SHIM_ALIAS_SYMBOL(ShimMemalign);

SHIM_ALWAYS_EXPORT int __wrap_posix_memalign(void**, size_t, size_t)
    SHIM_ALIAS_SYMBOL(ShimPosixMemalign);

SHIM_ALWAYS_EXPORT void* __wrap_pvalloc(size_t)
    SHIM_ALIAS_SYMBOL(ShimPvalloc);

SHIM_ALWAYS_EXPORT void* __wrap_realloc(void*, size_t)
    SHIM_ALIAS_SYMBOL(ShimRealloc);

SHIM_ALWAYS_EXPORT void* __wrap_valloc(size_t)
    SHIM_ALIAS_SYMBOL(ShimValloc);

} // extern "C"
