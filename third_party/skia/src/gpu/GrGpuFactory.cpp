<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "GrGpuFactory.h"

#include "GrGpu.h"
#include "gl/GrGLConfig.h"
#include "gl/GrGLGpu.h"
<<<<<<< HEAD
#ifdef SK_VULKAN
#include "vk/GrVkGpu.h"
#endif

static CreateGpuProc gGpuFactories[kBackendCount] = { GrGLGpu::Create, nullptr };

#ifdef SK_VULKAN
GrGpuFactoryRegistrar gVkGpuFactoryProc(kVulkan_GrBackend, GrVkGpu::Create);
#endif

GrGpuFactoryRegistrar::GrGpuFactoryRegistrar(int i, CreateGpuProc proc)
{
=======

static const int kMaxNumBackends = 4;
static CreateGpuProc gGpuFactories[kMaxNumBackends] = {GrGLGpu::Create, NULL, NULL, NULL};

GrGpuFactoryRegistrar::GrGpuFactoryRegistrar(int i, CreateGpuProc proc) {
>>>>>>> miniblink49
    gGpuFactories[i] = proc;
}

GrGpu* GrGpu::Create(GrBackend backend,
<<<<<<< HEAD
    GrBackendContext backendContext,
    const GrContextOptions& options,
    GrContext* context)
{
    SkASSERT((int)backend < kBackendCount);
    if (!gGpuFactories[backend]) {
        return nullptr;
=======
                     GrBackendContext backendContext,
                     const GrContextOptions& options,
                     GrContext* context) {
    SkASSERT((int)backend < kMaxNumBackends);
    if (!gGpuFactories[backend]) {
        return NULL;
>>>>>>> miniblink49
    }
    return (gGpuFactories[backend])(backendContext, options, context);
}
