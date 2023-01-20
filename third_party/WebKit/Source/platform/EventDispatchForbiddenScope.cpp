// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/EventDispatchForbiddenScope.h"

namespace blink {

<<<<<<< HEAD
#if DCHECK_IS_ON()
unsigned EventDispatchForbiddenScope::s_count = 0;
#endif // DECHECK_IS_ON()
=======
#if ENABLE(ASSERT)
unsigned EventDispatchForbiddenScope::s_count = 0;
#endif // ENABLE(ASSERT)
>>>>>>> miniblink49

} // namespace blink
