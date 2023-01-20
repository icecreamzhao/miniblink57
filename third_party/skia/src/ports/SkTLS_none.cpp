/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkTLS.h"

<<<<<<< HEAD
static void* gSpecific = nullptr;

void* SkTLS::PlatformGetSpecific(bool)
{
    return gSpecific;
}

void SkTLS::PlatformSetSpecific(void* ptr)
{
=======
static void* gSpecific = NULL;

void* SkTLS::PlatformGetSpecific(bool) {
    return gSpecific;
}

void SkTLS::PlatformSetSpecific(void* ptr) {
>>>>>>> miniblink49
    gSpecific = ptr;
}
