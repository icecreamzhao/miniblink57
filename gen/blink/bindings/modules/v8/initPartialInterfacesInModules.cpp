// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "bindings/modules/v8/V8AudioTrackPartial.h"
#include "bindings/modules/v8/V8DataTransferItemPartial.h"
#include "bindings/modules/v8/V8DedicatedWorkerGlobalScopePartial.h"
#include "bindings/modules/v8/V8DevToolsHostPartial.h"
#include "bindings/modules/v8/V8HTMLCanvasElementPartial.h"
#include "bindings/modules/v8/V8HTMLIFrameElementPartial.h"
#include "bindings/modules/v8/V8HTMLInputElementPartial.h"
#include "bindings/modules/v8/V8HTMLMediaElementPartial.h"
#include "bindings/modules/v8/V8HTMLVideoElementPartial.h"
#include "bindings/modules/v8/V8NavigatorPartial.h"
#include "bindings/modules/v8/V8OffscreenCanvasPartial.h"
#include "bindings/modules/v8/V8ScreenPartial.h"
#include "bindings/modules/v8/V8SharedWorkerGlobalScopePartial.h"
#include "bindings/modules/v8/V8URLPartial.h"
#include "bindings/modules/v8/V8VideoTrackPartial.h"
#include "bindings/modules/v8/V8WindowPartial.h"
#include "bindings/modules/v8/V8WorkerGlobalScopePartial.h"
#include "bindings/modules/v8/V8WorkerNavigatorPartial.h"

namespace blink {

void initPartialInterfacesInModules()
{
    //V8AudioTrackPartial::initialize();
    V8DataTransferItemPartial::initialize();
    V8DedicatedWorkerGlobalScopePartial::initialize();
    V8DevToolsHostPartial::initialize();
    V8HTMLCanvasElementPartial::initialize();
    //V8HTMLIFrameElementPartial::initialize();
    V8HTMLInputElementPartial::initialize();
    //V8HTMLMediaElementPartial::initialize();
    //V8HTMLVideoElementPartial::initialize();
    V8NavigatorPartial::initialize();
    V8OffscreenCanvasPartial::initialize();
    //V8ScreenPartial::initialize();
    //V8SharedWorkerGlobalScopePartial::initialize();
    V8URLPartial::initialize();
    //V8VideoTrackPartial::initialize();
    V8WindowPartial::initialize();
    V8WorkerGlobalScopePartial::initialize();
    V8WorkerNavigatorPartial::initialize();
}

} // namespace blink
