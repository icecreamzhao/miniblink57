/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "gl/GrGLAssembleInterface.h"
#include "gl/GrGLInterface.h"
=======

#include "gl/GrGLInterface.h"
#include "gl/GrGLAssembleInterface.h"
>>>>>>> miniblink49
#include "gl/GrGLUtil.h"

#include <GL/glx.h>

<<<<<<< HEAD
static GrGLFuncPtr glx_get(void* ctx, const char name[])
{
    SkASSERT(nullptr == ctx);
=======
static GrGLFuncPtr glx_get(void* ctx, const char name[]) {
    SkASSERT(NULL == ctx);
>>>>>>> miniblink49
    SkASSERT(glXGetCurrentContext());
    return glXGetProcAddress(reinterpret_cast<const GLubyte*>(name));
}

<<<<<<< HEAD
const GrGLInterface* GrGLCreateNativeInterface()
{
    if (nullptr == glXGetCurrentContext()) {
        return nullptr;
    }

    return GrGLAssembleInterface(nullptr, glx_get);
=======
const GrGLInterface* GrGLCreateNativeInterface() {
    if (NULL == glXGetCurrentContext()) {
        return NULL;
    }

    return GrGLAssembleInterface(NULL, glx_get);
>>>>>>> miniblink49
}
