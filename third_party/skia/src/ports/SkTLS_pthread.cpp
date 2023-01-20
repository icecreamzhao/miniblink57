/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkOnce.h"
=======
>>>>>>> miniblink49
#include "SkTLS.h"

#include <pthread.h>

static pthread_key_t gSkTLSKey;
<<<<<<< HEAD

void* SkTLS::PlatformGetSpecific(bool forceCreateTheSlot)
{
    // should we use forceCreateTheSlot to potentially just return nullptr if
    // we've never been called with forceCreateTheSlot==true ?
    static SkOnce once;
    once(pthread_key_create, &gSkTLSKey, SkTLS::Destructor);
    return pthread_getspecific(gSkTLSKey);
}

void SkTLS::PlatformSetSpecific(void* ptr)
{
=======
static pthread_once_t gSkTLSKey_Once = PTHREAD_ONCE_INIT;

static void sk_tls_make_key() {
    (void)pthread_key_create(&gSkTLSKey, SkTLS::Destructor);
}

void* SkTLS::PlatformGetSpecific(bool forceCreateTheSlot) {
    // should we use forceCreateTheSlot to potentially skip calling pthread_once
    // and just return NULL if we've never been called with
    // forceCreateTheSlot==true ?

    (void)pthread_once(&gSkTLSKey_Once, sk_tls_make_key);
    return pthread_getspecific(gSkTLSKey);
}

void SkTLS::PlatformSetSpecific(void* ptr) {
>>>>>>> miniblink49
    (void)pthread_setspecific(gSkTLSKey, ptr);
}
