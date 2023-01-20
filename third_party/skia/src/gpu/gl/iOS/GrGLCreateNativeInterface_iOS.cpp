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
#include <dlfcn.h>

class GLLoader {
public:
<<<<<<< HEAD
    GLLoader()
    {
=======
    GLLoader() {
>>>>>>> miniblink49
        fLibrary = dlopen(
            "/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib",
            RTLD_LAZY);
    }

<<<<<<< HEAD
    ~GLLoader()
    {
=======
    ~GLLoader() {
>>>>>>> miniblink49
        if (fLibrary) {
            dlclose(fLibrary);
        }
    }

<<<<<<< HEAD
    void* handle() const
    {
        return nullptr == fLibrary ? RTLD_DEFAULT : fLibrary;
=======
    void* handle() const {
        return NULL == fLibrary ? RTLD_DEFAULT : fLibrary;
>>>>>>> miniblink49
    }

private:
    void* fLibrary;
};

class GLProcGetter {
public:
<<<<<<< HEAD
    GLProcGetter() { }

    GrGLFuncPtr getProc(const char name[]) const
    {
        return (GrGLFuncPtr)dlsym(fLoader.handle(), name);
    }

=======
    GLProcGetter() {}

    GrGLFuncPtr getProc(const char name[]) const {
        return (GrGLFuncPtr) dlsym(fLoader.handle(), name);
    }
    
>>>>>>> miniblink49
private:
    GLLoader fLoader;
};

<<<<<<< HEAD
static GrGLFuncPtr ios_get_gl_proc(void* ctx, const char name[])
{
    SkASSERT(ctx);
    const GLProcGetter* getter = (const GLProcGetter*)ctx;
    return getter->getProc(name);
}

const GrGLInterface* GrGLCreateNativeInterface()
{
=======
static GrGLFuncPtr ios_get_gl_proc(void* ctx, const char name[]) {
    SkASSERT(ctx);
    const GLProcGetter* getter = (const GLProcGetter*) ctx;
    return getter->getProc(name);
}

const GrGLInterface* GrGLCreateNativeInterface() {
>>>>>>> miniblink49
    GLProcGetter getter;
    return GrGLAssembleGLESInterface(&getter, ios_get_gl_proc);
}
