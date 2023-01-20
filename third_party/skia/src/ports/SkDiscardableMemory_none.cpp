/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkDiscardableMemory.h"
#include "SkDiscardableMemoryPool.h"
#include "SkTypes.h"

SkDiscardableMemory* SkDiscardableMemory::Create(size_t bytes)
{
=======
#include "SkDiscardableMemoryPool.h"
#include "SkTypes.h"

SkDiscardableMemory* SkDiscardableMemory::Create(size_t bytes) {
>>>>>>> miniblink49
    return SkGetGlobalDiscardableMemoryPool()->create(bytes);
}
