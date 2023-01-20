<<<<<<< HEAD
=======

>>>>>>> miniblink49
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

#include <EGL/egl.h>
#include <GLES2/gl2.h>

<<<<<<< HEAD
static GrGLFuncPtr egl_get_gl_proc(void* ctx, const char name[])
{
    SkASSERT(nullptr == ctx);
    GrGLFuncPtr ptr = eglGetProcAddress(name);
    if (!ptr) {
        if (0 == strcmp("eglQueryString", name)) {
            return (GrGLFuncPtr)eglQueryString;
        } else if (0 == strcmp("eglGetCurrentDisplay", name)) {
            return (GrGLFuncPtr)eglGetCurrentDisplay;
        }
    }
    return ptr;
}

const GrGLInterface* GrGLCreateNativeInterface()
{
    return GrGLAssembleInterface(nullptr, egl_get_gl_proc);
=======
static GrGLFuncPtr egl_get_gl_proc(void* ctx, const char name[]) {
    SkASSERT(NULL == ctx);
    return eglGetProcAddress(name);
}

const GrGLInterface* GrGLCreateNativeInterface() {
    return GrGLAssembleInterface(NULL, egl_get_gl_proc);
>>>>>>> miniblink49
}
