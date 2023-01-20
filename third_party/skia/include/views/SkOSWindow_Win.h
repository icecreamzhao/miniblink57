
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef SkOSWindow_Win_DEFINED
#define SkOSWindow_Win_DEFINED

#include "../private/SkTHash.h"
#include "SkWindow.h"
#include <functional>
=======

#ifndef SkOSWindow_Win_DEFINED
#define SkOSWindow_Win_DEFINED

#include "SkWindow.h"
#include "../../src/core/SkFunction.h"
#include "../../src/core/SkTHash.h"
>>>>>>> miniblink49

#if SK_ANGLE
#include "EGL/egl.h"
#endif

class SkOSWindow : public SkWindow {
public:
    struct WindowInit {
<<<<<<< HEAD
        const TCHAR* fClass;
        HINSTANCE fInstance;
=======
        const TCHAR*    fClass;
        HINSTANCE       fInstance;
>>>>>>> miniblink49
    };

    SkOSWindow(const void* winInit);
    virtual ~SkOSWindow();

    static bool PostEvent(SkEvent* evt, SkEventSinkID, SkMSec delay);

    enum SkBackEndTypes {
        kNone_BackEndType,
#if SK_SUPPORT_GPU
        kNativeGL_BackEndType,
#if SK_ANGLE
        kANGLE_BackEndType,
#endif // SK_ANGLE
#endif // SK_SUPPORT_GPU
    };

<<<<<<< HEAD
    bool attach(SkBackEndTypes attachType, int msaaSampleCount, bool deepColor, AttachmentInfo*);
    void release();
=======
    bool attach(SkBackEndTypes attachType, int msaaSampleCount, AttachmentInfo*);
    void detach();
>>>>>>> miniblink49
    void present();

    bool wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    static bool QuitOnDeactivate(HWND hWnd);

    enum {
        SK_WM_SkEvent = WM_APP + 1000,
<<<<<<< HEAD
        SK_WM_SkTimerID = 0xFFFF // just need a non-zero value
=======
        SK_WM_SkTimerID = 0xFFFF    // just need a non-zero value
>>>>>>> miniblink49
    };

    bool makeFullscreen();
    void setVsync(bool);
    void closeWindow();

<<<<<<< HEAD
    static SkOSWindow* GetOSWindowForHWND(void* hwnd)
    {
=======
    static SkOSWindow* GetOSWindowForHWND(void* hwnd) {
>>>>>>> miniblink49
        SkOSWindow** win = gHwndToOSWindowMap.find(hwnd);
        if (!win) {
            return NULL;
        }
        return *win;
    }

<<<<<<< HEAD
    // Iterates f over all the SkOSWindows and their corresponding HWNDs.
    // The void* argument to f is a HWND.
    static void ForAllWindows(const std::function<void(void*, SkOSWindow**)>& f)
    {
        gHwndToOSWindowMap.foreach (f);
=======
    // Iterates SkFunction over all the SkOSWindows and their corresponding HWNDs.
    // The void* argument to the SkFunction is a HWND.
    static void ForAllWindows(const SkFunction<void(void*, SkOSWindow**)>& f) {
        gHwndToOSWindowMap.foreach(f);
>>>>>>> miniblink49
    }

protected:
    virtual bool quitOnDeactivate() { return true; }

    // overrides from SkWindow
    virtual void onHandleInval(const SkIRect&);
    // overrides from SkView
    virtual void onAddMenu(const SkOSMenu*);

    virtual void onSetTitle(const char title[]);

private:
    static SkTHashMap<void*, SkOSWindow*> gHwndToOSWindowMap;

<<<<<<< HEAD
    WindowInit fWinInit;
    void* fHWND;

    void doPaint(void* ctx);

#if SK_SUPPORT_GPU
    void* fHGLRC;
#if SK_ANGLE
    EGLDisplay fDisplay;
    EGLContext fContext;
    EGLSurface fSurface;
    EGLConfig fConfig;
    SkAutoTUnref<const GrGLInterface> fANGLEInterface;
#endif // SK_ANGLE
#endif // SK_SUPPORT_GPU

    bool fFullscreen;
=======
    WindowInit          fWinInit;
    void*               fHWND;

    void                doPaint(void* ctx);

#if SK_SUPPORT_GPU
    void*               fHGLRC;
#if SK_ANGLE
    EGLDisplay          fDisplay;
    EGLContext          fContext;
    EGLSurface          fSurface;
    EGLConfig           fConfig;
#endif // SK_ANGLE
#endif // SK_SUPPORT_GPU

    bool                fFullscreen;
>>>>>>> miniblink49
    struct SavedWindowState {
        bool fZoomed;
        LONG fStyle;
        LONG fExStyle;
        RECT fRect;
        LONG fScreenWidth;
        LONG fScreenHeight;
        LONG fScreenBits;
        void* fHWND;
    } fSavedWindowState;

<<<<<<< HEAD
    HMENU fMBar;

    SkBackEndTypes fAttached;

    void updateSize();
#if SK_SUPPORT_GPU
    bool attachGL(int msaaSampleCount, bool deepColor, AttachmentInfo* info);
=======
    HMENU               fMBar;

    SkBackEndTypes      fAttached;

    void updateSize();
#if SK_SUPPORT_GPU
    bool attachGL(int msaaSampleCount, AttachmentInfo* info);
>>>>>>> miniblink49
    void detachGL();
    void presentGL();

#if SK_ANGLE
    bool attachANGLE(int msaaSampleCount, AttachmentInfo* info);
    void detachANGLE();
    void presentANGLE();
#endif // SK_ANGLE
<<<<<<< HEAD

=======
>>>>>>> miniblink49
#endif // SK_SUPPORT_GPU

    typedef SkWindow INHERITED;
};

#endif
