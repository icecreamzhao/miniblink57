/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkSpinlock.h"

<<<<<<< HEAD
void SkSpinlock::contendedAcquire()
{
    // To act as a mutex, we need an acquire barrier when we acquire the lock.
    while (fLocked.exchange(true, std::memory_order_acquire)) {
        /*spin*/
    }
=======
void SkPODSpinlock::contendedAcquire() {
    // To act as a mutex, we need an acquire barrier when we take the lock.
    while(sk_atomic_exchange(&fLocked, true, sk_memory_order_acquire)) { /*spin*/ }
>>>>>>> miniblink49
}
