// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/test/test_message_loop.h"
#include "base/run_loop.h"

namespace base {

TestMessageLoop::TestMessageLoop() { }

TestMessageLoop::TestMessageLoop(MessageLoop::Type type)
    : loop_(type)
{
}

TestMessageLoop::~TestMessageLoop()
{
    RunLoop().RunUntilIdle();
}

} // namespace base
