<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD

#include "SkTypes.h"

#include <stdlib.h>

#define SK_DEBUGFAILF(fmt, ...) \
    SkASSERT((SkDebugf(fmt "\n", __VA_ARGS__), false))

static inline void sk_out_of_memory(size_t size)
{
    SK_DEBUGFAILF("sk_out_of_memory (asked for " SK_SIZE_T_SPECIFIER " bytes)",
        size);
    abort();
}

static inline void* throw_on_failure(size_t size, void* p)
{
    if (size > 0 && p == nullptr) {
        // If we've got a nullptr here, the only reason we should have failed is running out of RAM.
=======
#include "SkTypes.h"
#include <stdio.h>
#include <stdlib.h>

#define SK_DEBUGFAILF(fmt, ...) \
    SkASSERT((SkDebugf(fmt"\n", __VA_ARGS__), false))

static inline void sk_out_of_memory(size_t size) {
    SK_DEBUGFAILF("sk_out_of_memory (asked for " SK_SIZE_T_SPECIFIER " bytes)",
                  size);
    abort();
}

static inline void* throw_on_failure(size_t size, void* p) {
    if (size > 0 && p == NULL) {
        // If we've got a NULL here, the only reason we should have failed is running out of RAM.
>>>>>>> miniblink49
        sk_out_of_memory(size);
    }
    return p;
}

<<<<<<< HEAD
void sk_abort_no_print()
{
#if defined(SK_BUILD_FOR_WIN) && defined(SK_IS_BOT)
    // do not display a system dialog before aborting the process
    _set_abort_behavior(0, _WRITE_ABORT_MSG);
#endif
    abort();
}

void sk_out_of_memory(void)
{
=======
void sk_throw() {
    SkDEBUGFAIL("sk_throw");
    abort();
}

void sk_out_of_memory(void) {
>>>>>>> miniblink49
    SkDEBUGFAIL("sk_out_of_memory");
    abort();
}

<<<<<<< HEAD
void* sk_malloc_throw(size_t size)
{
    return sk_malloc_flags(size, SK_MALLOC_THROW);
}

void* sk_realloc_throw(void* addr, size_t size)
{
    return throw_on_failure(size, realloc(addr, size));
}

void sk_free(void* p)
{
=======
void* sk_malloc_throw(size_t size) {
    return sk_malloc_flags(size, SK_MALLOC_THROW);
}

void* sk_realloc_throw(void* addr, size_t size) {
    return throw_on_failure(size, realloc(addr, size));
}

void sk_free(void* p) {
>>>>>>> miniblink49
    if (p) {
        free(p);
    }
}

<<<<<<< HEAD
void* sk_malloc_flags(size_t size, unsigned flags)
{
=======
void* sk_malloc_flags(size_t size, unsigned flags) {
>>>>>>> miniblink49
    void* p = malloc(size);
    if (flags & SK_MALLOC_THROW) {
        return throw_on_failure(size, p);
    } else {
        return p;
    }
}

<<<<<<< HEAD
void* sk_calloc(size_t size)
{
    return calloc(size, 1);
}

void* sk_calloc_throw(size_t size)
{
=======
void* sk_calloc(size_t size) {
    return calloc(size, 1);
}

void* sk_calloc_throw(size_t size) {
>>>>>>> miniblink49
    return throw_on_failure(size, sk_calloc(size));
}
