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
#include "SkTypes.h"
#if defined(SK_BUILD_FOR_WIN32)

#include "SkLeanWindows.h"

#include "gl/GrGLAssembleInterface.h"
#include "gl/GrGLInterface.h"
#include "gl/GrGLUtil.h"

class AutoLibraryUnload {
public:
    AutoLibraryUnload(const char* moduleName)
    {
        fModule = LoadLibraryA(moduleName);
    }
    ~AutoLibraryUnload()
    {
=======

#include "gl/GrGLInterface.h"
#include "gl/GrGLAssembleInterface.h"
#include "gl/GrGLUtil.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

class AutoLibraryUnload {
public:
    AutoLibraryUnload(const char* moduleName) {
        fModule = LoadLibrary(moduleName);
    }
    ~AutoLibraryUnload() {
>>>>>>> miniblink49
        if (fModule) {
            FreeLibrary(fModule);
        }
    }
    HMODULE get() const { return fModule; }

private:
    HMODULE fModule;
};

class GLProcGetter {
public:
<<<<<<< HEAD
    GLProcGetter()
        : fGLLib("opengl32.dll")
    {
    }

    bool isInitialized() const { return SkToBool(fGLLib.get()); }

    GrGLFuncPtr getProc(const char name[]) const
    {
        GrGLFuncPtr proc;
        if ((proc = (GrGLFuncPtr)GetProcAddress(fGLLib.get(), name))) {
            return proc;
        }
        if ((proc = (GrGLFuncPtr)wglGetProcAddress(name))) {
            return proc;
        }
        return nullptr;
=======
    GLProcGetter() : fGLLib("opengl32.dll") {}

    bool isInitialized() const { return SkToBool(fGLLib.get()); }

    GrGLFuncPtr getProc(const char name[]) const {
        GrGLFuncPtr proc;
        if ((proc = (GrGLFuncPtr) GetProcAddress(fGLLib.get(), name))) {
            return proc;
        }
        if ((proc = (GrGLFuncPtr) wglGetProcAddress(name))) {
            return proc;
        }
        return NULL;
>>>>>>> miniblink49
    }

private:
    AutoLibraryUnload fGLLib;
};

<<<<<<< HEAD
static GrGLFuncPtr win_get_gl_proc(void* ctx, const char name[])
{
    SkASSERT(ctx);
    SkASSERT(wglGetCurrentContext());
    const GLProcGetter* getter = (const GLProcGetter*)ctx;
=======
static GrGLFuncPtr win_get_gl_proc(void* ctx, const char name[]) {
    SkASSERT(ctx);
    SkASSERT(wglGetCurrentContext());
    const GLProcGetter* getter = (const GLProcGetter*) ctx;
>>>>>>> miniblink49
    return getter->getProc(name);
}

/*
 * Windows makes the GL funcs all be __stdcall instead of __cdecl :(
 * This implementation will only work if GR_GL_FUNCTION_TYPE is __stdcall.
 * Otherwise, a springboard would be needed that hides the calling convention.
 */
<<<<<<< HEAD
const GrGLInterface* GrGLCreateNativeInterface()
{
    if (nullptr == wglGetCurrentContext()) {
        return nullptr;
=======
const GrGLInterface* GrGLCreateNativeInterface() {
    if (NULL == wglGetCurrentContext()) {
        return NULL;
>>>>>>> miniblink49
    }

    GLProcGetter getter;
    if (!getter.isInitialized()) {
<<<<<<< HEAD
        return nullptr;
    }

    GrGLGetStringProc getString = (GrGLGetStringProc)getter.getProc("glGetString");
    if (nullptr == getString) {
        return nullptr;
=======
        return NULL;
    }

    GrGLGetStringProc getString = (GrGLGetStringProc)getter.getProc("glGetString");
    if (NULL == getString) {
        return NULL;
>>>>>>> miniblink49
    }
    const char* verStr = reinterpret_cast<const char*>(getString(GR_GL_VERSION));
    GrGLStandard standard = GrGLGetStandardInUseFromString(verStr);

    if (kGLES_GrGLStandard == standard) {
        return GrGLAssembleGLESInterface(&getter, win_get_gl_proc);
    } else if (kGL_GrGLStandard == standard) {
        return GrGLAssembleGLInterface(&getter, win_get_gl_proc);
    }
<<<<<<< HEAD
    return nullptr;
}

#endif //defined(SK_BUILD_FOR_WIN32)
=======
    return NULL;
}
>>>>>>> miniblink49
