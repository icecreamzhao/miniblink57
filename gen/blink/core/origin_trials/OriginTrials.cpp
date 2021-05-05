// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/origin_trials/OriginTrials.h"

#include "core/origin_trials/OriginTrialContext.h"
#include "platform/RuntimeEnabledFeatures.h"

namespace blink {

bool OriginTrials::foreignFetchEnabled(ExecutionContext* executionContext)
{
    if (RuntimeEnabledFeatures::foreignFetchEnabled())
        return true;

    OriginTrialContext* context = OriginTrialContext::from(executionContext,
        OriginTrialContext::DontCreateIfNotExists);
    return context && context->isTrialEnabled("ForeignFetch");
}

bool OriginTrials::gamepadExtensionsEnabled(ExecutionContext* executionContext)
{
    if (RuntimeEnabledFeatures::gamepadExtensionsEnabled())
        return true;

    OriginTrialContext* context = OriginTrialContext::from(executionContext,
        OriginTrialContext::DontCreateIfNotExists);
    return context && context->isTrialEnabled("WebVR");
}

bool OriginTrials::imageCaptureEnabled(ExecutionContext* executionContext)
{
    if (RuntimeEnabledFeatures::imageCaptureEnabled())
        return true;

    OriginTrialContext* context = OriginTrialContext::from(executionContext,
        OriginTrialContext::DontCreateIfNotExists);
    return context && context->isTrialEnabled("ImageCapture");
}

bool OriginTrials::linkServiceWorkerEnabled(ExecutionContext* executionContext)
{
    if (RuntimeEnabledFeatures::linkServiceWorkerEnabled())
        return true;

    OriginTrialContext* context = OriginTrialContext::from(executionContext,
        OriginTrialContext::DontCreateIfNotExists);
    return context && context->isTrialEnabled("ForeignFetch");
}

bool OriginTrials::longTaskObserverEnabled(ExecutionContext* executionContext)
{
    if (RuntimeEnabledFeatures::longTaskObserverEnabled())
        return true;

    OriginTrialContext* context = OriginTrialContext::from(executionContext,
        OriginTrialContext::DontCreateIfNotExists);
    return context && context->isTrialEnabled("LongTaskObserver");
}

bool OriginTrials::originTrialsSampleAPIEnabled(ExecutionContext* executionContext)
{
    if (RuntimeEnabledFeatures::originTrialsSampleAPIEnabled())
        return true;

    OriginTrialContext* context = OriginTrialContext::from(executionContext,
        OriginTrialContext::DontCreateIfNotExists);
    return context && context->isTrialEnabled("Frobulate");
}

bool OriginTrials::serviceWorkerNavigationPreloadEnabled(ExecutionContext* executionContext)
{
    if (RuntimeEnabledFeatures::serviceWorkerNavigationPreloadEnabled())
        return true;

    OriginTrialContext* context = OriginTrialContext::from(executionContext,
        OriginTrialContext::DontCreateIfNotExists);
    return context && context->isTrialEnabled("ServiceWorkerNavigationPreload");
}

bool OriginTrials::webUSBEnabled(ExecutionContext* executionContext)
{
    if (RuntimeEnabledFeatures::webUSBEnabled())
        return true;

    OriginTrialContext* context = OriginTrialContext::from(executionContext,
        OriginTrialContext::DontCreateIfNotExists);
    return context && context->isTrialEnabled("WebUSB2");
}

bool OriginTrials::webVREnabled(ExecutionContext* executionContext)
{
    if (RuntimeEnabledFeatures::webVREnabled())
        return true;

    OriginTrialContext* context = OriginTrialContext::from(executionContext,
        OriginTrialContext::DontCreateIfNotExists);
    return context && context->isTrialEnabled("WebVR");
}

bool OriginTrials::webShareEnabled(ExecutionContext* executionContext)
{
    if (RuntimeEnabledFeatures::webShareEnabled())
        return true;
#if defined(OS_ANDROID)
    OriginTrialContext* context = OriginTrialContext::from(executionContext,
        OriginTrialContext::DontCreateIfNotExists);
    return context && context->isTrialEnabled("WebShare");
#else
    return false;
#endif
}

} // namespace blink
