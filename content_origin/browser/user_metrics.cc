// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/public/browser/user_metrics.h"

#include <vector>

#include "base/bind.h"
#include "base/metrics/user_metrics.h"
#include "content/public/browser/browser_thread.h"

namespace content {

void RecordAction(const base::UserMetricsAction& action)
{
    base::RecordAction(action);
}

void RecordComputedAction(const std::string& action)
{
    base::RecordComputedAction(action);
}

} // namespace content
