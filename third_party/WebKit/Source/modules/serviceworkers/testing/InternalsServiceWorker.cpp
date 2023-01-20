// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/serviceworkers/testing/InternalsServiceWorker.h"

#include "modules/serviceworkers/ServiceWorker.h"

namespace blink {

<<<<<<< HEAD
void InternalsServiceWorker::terminateServiceWorker(Internals& internals,
    ServiceWorker* worker)
=======
void InternalsServiceWorker::terminateServiceWorker(Internals& internals, ServiceWorker* worker)
>>>>>>> miniblink49
{
    worker->internalsTerminate();
}

} // namespace blink
