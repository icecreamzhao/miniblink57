<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkTypes.h"

#if defined(SK_BUILD_FOR_WIN)

<<<<<<< HEAD
#include "SkLeanWindows.h"

=======
#include <GL/gl.h>
#include <WindowsX.h>
#include "win/SkWGL.h"
#include "SkWindow.h"
>>>>>>> miniblink49
#include "SkCanvas.h"
#include "SkOSMenu.h"
#include "SkTime.h"
#include "SkUtils.h"
<<<<<<< HEAD
#include "SkWindow.h"
#include "win/SkWGL.h"
#include <GL/gl.h>
#include <WindowsX.h>
=======
>>>>>>> miniblink49

#include "SkGraphics.h"

#if SK_ANGLE
<<<<<<< HEAD
#include "GLES2/gl2.h"
#include "gl/GrGLAssembleInterface.h"
#include "gl/GrGLInterface.h"
#include <EGL/egl.h>
#include <EGL/eglext.h>
#endif // SK_ANGLE

const int kDefaultWindowWidth = 500;
const int kDefaultWindowHeight = 500;

#define GL_CALL(IFACE, X)         \
    SkASSERT(IFACE);              \
    do {                          \
        (IFACE)->fFunctions.f##X; \
    } while (false)

#define WM_EVENT_CALLBACK (WM_USER + 0)
=======
#include "gl/angle/SkANGLEGLContext.h"
#include "gl/GrGLInterface.h"
#include "GLES2/gl2.h"

#define ANGLE_GL_CALL(IFACE, X)                                 \
    do {                                                        \
        (IFACE)->fFunctions.f##X;                               \
    } while (false)

#endif

#define WM_EVENT_CALLBACK (WM_USER+0)
>>>>>>> miniblink49

void post_skwinevent(HWND hwnd)
{
    PostMessage(hwnd, WM_EVENT_CALLBACK, 0, 0);
}

SkTHashMap<void*, SkOSWindow*> SkOSWindow::gHwndToOSWindowMap;

<<<<<<< HEAD
SkOSWindow::SkOSWindow(const void* winInit)
{
    fWinInit = *(const WindowInit*)winInit;

    fHWND = CreateWindow(fWinInit.fClass, NULL, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, kDefaultWindowWidth, kDefaultWindowHeight, NULL, NULL,
        fWinInit.fInstance, NULL);
=======
SkOSWindow::SkOSWindow(const void* winInit) {
    fWinInit = *(const WindowInit*)winInit;

    fHWND = CreateWindow(fWinInit.fClass, NULL, WS_OVERLAPPEDWINDOW,
                         CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, fWinInit.fInstance, NULL);
>>>>>>> miniblink49
    gHwndToOSWindowMap.set(fHWND, this);
#if SK_SUPPORT_GPU
#if SK_ANGLE
    fDisplay = EGL_NO_DISPLAY;
    fContext = EGL_NO_CONTEXT;
    fSurface = EGL_NO_SURFACE;
#endif
<<<<<<< HEAD

=======
>>>>>>> miniblink49
    fHGLRC = NULL;
#endif
    fAttached = kNone_BackEndType;
    fFullscreen = false;
}

<<<<<<< HEAD
SkOSWindow::~SkOSWindow()
{
=======
SkOSWindow::~SkOSWindow() {
>>>>>>> miniblink49
#if SK_SUPPORT_GPU
    if (fHGLRC) {
        wglDeleteContext((HGLRC)fHGLRC);
    }
#if SK_ANGLE
    if (EGL_NO_CONTEXT != fContext) {
        eglDestroyContext(fDisplay, fContext);
        fContext = EGL_NO_CONTEXT;
    }

    if (EGL_NO_SURFACE != fSurface) {
        eglDestroySurface(fDisplay, fSurface);
        fSurface = EGL_NO_SURFACE;
    }

    if (EGL_NO_DISPLAY != fDisplay) {
        eglTerminate(fDisplay);
        fDisplay = EGL_NO_DISPLAY;
    }
#endif // SK_ANGLE
#endif // SK_SUPPORT_GPU
    this->closeWindow();
}

<<<<<<< HEAD
static SkKey winToskKey(WPARAM vk)
{
    static const struct {
        WPARAM fVK;
        SkKey fKey;
    } gPair[] = {
        { VK_BACK, kBack_SkKey },
        { VK_CLEAR, kBack_SkKey },
        { VK_RETURN, kOK_SkKey },
        { VK_UP, kUp_SkKey },
        { VK_DOWN, kDown_SkKey },
        { VK_LEFT, kLeft_SkKey },
        { VK_RIGHT, kRight_SkKey }
=======
static SkKey winToskKey(WPARAM vk) {
    static const struct {
        WPARAM    fVK;
        SkKey    fKey;
    } gPair[] = {
        { VK_BACK,    kBack_SkKey },
        { VK_CLEAR,    kBack_SkKey },
        { VK_RETURN, kOK_SkKey },
        { VK_UP,     kUp_SkKey },
        { VK_DOWN,     kDown_SkKey },
        { VK_LEFT,     kLeft_SkKey },
        { VK_RIGHT,     kRight_SkKey }
>>>>>>> miniblink49
    };
    for (size_t i = 0; i < SK_ARRAY_COUNT(gPair); i++) {
        if (gPair[i].fVK == vk) {
            return gPair[i].fKey;
        }
    }
    return kNONE_SkKey;
}

<<<<<<< HEAD
static unsigned getModifiers(UINT message)
{
    return 0; // TODO
}

bool SkOSWindow::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
    case WM_KEYDOWN: {
        SkKey key = winToskKey(wParam);
        if (kNONE_SkKey != key) {
            this->handleKey(key);
            return true;
        }
    } break;
    case WM_KEYUP: {
        SkKey key = winToskKey(wParam);
        if (kNONE_SkKey != key) {
            this->handleKeyUp(key);
            return true;
        }
    } break;
    case WM_UNICHAR:
        this->handleChar((SkUnichar)wParam);
        return true;
    case WM_CHAR: {
        const uint16_t* c = reinterpret_cast<uint16_t*>(&wParam);
        this->handleChar(SkUTF16_NextUnichar(&c));
        return true;
    } break;
    case WM_SIZE: {
        INT width = LOWORD(lParam);
        INT height = HIWORD(lParam);
        this->resize(width, height);
        break;
    }
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        this->doPaint(hdc);
        EndPaint(hWnd, &ps);
        return true;
    } break;

    case WM_LBUTTONDOWN:
        this->handleClick(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam),
            Click::kDown_State, NULL, getModifiers(message));
        return true;

    case WM_MOUSEMOVE:
        this->handleClick(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam),
            Click::kMoved_State, NULL, getModifiers(message));
        return true;

    case WM_LBUTTONUP:
        this->handleClick(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam),
            Click::kUp_State, NULL, getModifiers(message));
        return true;

    case WM_EVENT_CALLBACK:
        if (SkEvent::ProcessEvent()) {
            post_skwinevent(hWnd);
        }
        return true;
=======
static unsigned getModifiers(UINT message) {
    return 0;   // TODO
}

bool SkOSWindow::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_KEYDOWN: {
            SkKey key = winToskKey(wParam);
            if (kNONE_SkKey != key) {
                this->handleKey(key);
                return true;
            }
        } break;
        case WM_KEYUP: {
            SkKey key = winToskKey(wParam);
            if (kNONE_SkKey != key) {
                this->handleKeyUp(key);
                return true;
            }
        } break;
        case WM_UNICHAR:
            this->handleChar((SkUnichar) wParam);
            return true;
        case WM_CHAR: {
            this->handleChar(SkUTF8_ToUnichar((char*)&wParam));
            return true;
        } break;
        case WM_SIZE: {
            INT width = LOWORD(lParam);
            INT height = HIWORD(lParam);
            this->resize(width, height);
            break;
        }
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            this->doPaint(hdc);
            EndPaint(hWnd, &ps);
            return true;
            } break;

        case WM_LBUTTONDOWN:
            this->handleClick(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam),
                              Click::kDown_State, NULL, getModifiers(message));
            return true;

        case WM_MOUSEMOVE:
            this->handleClick(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam),
                              Click::kMoved_State, NULL, getModifiers(message));
            return true;

        case WM_LBUTTONUP:
            this->handleClick(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam),
                              Click::kUp_State, NULL, getModifiers(message));
            return true;

        case WM_EVENT_CALLBACK:
            if (SkEvent::ProcessEvent()) {
                post_skwinevent(hWnd);
            }
            return true;
>>>>>>> miniblink49
    }
    return false;
}

<<<<<<< HEAD
void SkOSWindow::doPaint(void* ctx)
{
    this->update(NULL);

    if (kNone_BackEndType == fAttached) {
=======
void SkOSWindow::doPaint(void* ctx) {
    this->update(NULL);

    if (kNone_BackEndType == fAttached)
    {
>>>>>>> miniblink49
        HDC hdc = (HDC)ctx;
        const SkBitmap& bitmap = this->getBitmap();

        BITMAPINFO bmi;
        memset(&bmi, 0, sizeof(bmi));
<<<<<<< HEAD
        bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        bmi.bmiHeader.biWidth = bitmap.width();
        bmi.bmiHeader.biHeight = -bitmap.height(); // top-down image
        bmi.bmiHeader.biPlanes = 1;
        bmi.bmiHeader.biBitCount = 32;
        bmi.bmiHeader.biCompression = BI_RGB;
        bmi.bmiHeader.biSizeImage = 0;
=======
        bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
        bmi.bmiHeader.biWidth       = bitmap.width();
        bmi.bmiHeader.biHeight      = -bitmap.height(); // top-down image
        bmi.bmiHeader.biPlanes      = 1;
        bmi.bmiHeader.biBitCount    = 32;
        bmi.bmiHeader.biCompression = BI_RGB;
        bmi.bmiHeader.biSizeImage   = 0;
>>>>>>> miniblink49

        //
        // Do the SetDIBitsToDevice.
        //
        // TODO(wjmaclean):
        //       Fix this call to handle SkBitmaps that have rowBytes != width,
        //       i.e. may have padding at the end of lines. The SkASSERT below
        //       may be ignored by builds, and the only obviously safe option
        //       seems to be to copy the bitmap to a temporary (contiguous)
        //       buffer before passing to SetDIBitsToDevice().
        SkASSERT(bitmap.width() * bitmap.bytesPerPixel() == bitmap.rowBytes());
        bitmap.lockPixels();
        int ret = SetDIBitsToDevice(hdc,
            0, 0,
            bitmap.width(), bitmap.height(),
            0, 0,
            0, bitmap.height(),
            bitmap.getPixels(),
            &bmi,
            DIB_RGB_COLORS);
        (void)ret; // we're ignoring potential failures for now.
        bitmap.unlockPixels();
    }
}

void SkOSWindow::updateSize()
{
<<<<<<< HEAD
    RECT r;
=======
    RECT    r;
>>>>>>> miniblink49
    GetWindowRect((HWND)fHWND, &r);
    this->resize(r.right - r.left, r.bottom - r.top);
}

<<<<<<< HEAD
void SkOSWindow::onHandleInval(const SkIRect& r)
{
    RECT rect;
    rect.left = r.fLeft;
    rect.top = r.fTop;
    rect.right = r.fRight;
    rect.bottom = r.fBottom;
=======
void SkOSWindow::onHandleInval(const SkIRect& r) {
    RECT rect;
    rect.left    = r.fLeft;
    rect.top     = r.fTop;
    rect.right   = r.fRight;
    rect.bottom  = r.fBottom;
>>>>>>> miniblink49
    InvalidateRect((HWND)fHWND, &rect, FALSE);
}

void SkOSWindow::onAddMenu(const SkOSMenu* sk_menu)
{
}

<<<<<<< HEAD
void SkOSWindow::onSetTitle(const char title[])
{
=======
void SkOSWindow::onSetTitle(const char title[]){
>>>>>>> miniblink49
    SetWindowTextA((HWND)fHWND, title);
}

enum {
<<<<<<< HEAD
    SK_MacReturnKey = 36,
    SK_MacDeleteKey = 51,
    SK_MacEndKey = 119,
    SK_MacLeftKey = 123,
    SK_MacRightKey = 124,
    SK_MacDownKey = 125,
    SK_MacUpKey = 126,

    SK_Mac0Key = 0x52,
    SK_Mac1Key = 0x53,
    SK_Mac2Key = 0x54,
    SK_Mac3Key = 0x55,
    SK_Mac4Key = 0x56,
    SK_Mac5Key = 0x57,
    SK_Mac6Key = 0x58,
    SK_Mac7Key = 0x59,
    SK_Mac8Key = 0x5b,
    SK_Mac9Key = 0x5c
=======
    SK_MacReturnKey     = 36,
    SK_MacDeleteKey     = 51,
    SK_MacEndKey        = 119,
    SK_MacLeftKey       = 123,
    SK_MacRightKey      = 124,
    SK_MacDownKey       = 125,
    SK_MacUpKey         = 126,

    SK_Mac0Key          = 0x52,
    SK_Mac1Key          = 0x53,
    SK_Mac2Key          = 0x54,
    SK_Mac3Key          = 0x55,
    SK_Mac4Key          = 0x56,
    SK_Mac5Key          = 0x57,
    SK_Mac6Key          = 0x58,
    SK_Mac7Key          = 0x59,
    SK_Mac8Key          = 0x5b,
    SK_Mac9Key          = 0x5c
>>>>>>> miniblink49
};

static SkKey raw2key(uint32_t raw)
{
    static const struct {
<<<<<<< HEAD
        uint32_t fRaw;
        SkKey fKey;
    } gKeys[] = {
        { SK_MacUpKey, kUp_SkKey },
        { SK_MacDownKey, kDown_SkKey },
        { SK_MacLeftKey, kLeft_SkKey },
        { SK_MacRightKey, kRight_SkKey },
        { SK_MacReturnKey, kOK_SkKey },
        { SK_MacDeleteKey, kBack_SkKey },
        { SK_MacEndKey, kEnd_SkKey },
        { SK_Mac0Key, k0_SkKey },
        { SK_Mac1Key, k1_SkKey },
        { SK_Mac2Key, k2_SkKey },
        { SK_Mac3Key, k3_SkKey },
        { SK_Mac4Key, k4_SkKey },
        { SK_Mac5Key, k5_SkKey },
        { SK_Mac6Key, k6_SkKey },
        { SK_Mac7Key, k7_SkKey },
        { SK_Mac8Key, k8_SkKey },
        { SK_Mac9Key, k9_SkKey }
=======
        uint32_t  fRaw;
        SkKey   fKey;
    } gKeys[] = {
        { SK_MacUpKey,      kUp_SkKey       },
        { SK_MacDownKey,    kDown_SkKey     },
        { SK_MacLeftKey,    kLeft_SkKey     },
        { SK_MacRightKey,   kRight_SkKey    },
        { SK_MacReturnKey,  kOK_SkKey       },
        { SK_MacDeleteKey,  kBack_SkKey     },
        { SK_MacEndKey,     kEnd_SkKey      },
        { SK_Mac0Key,       k0_SkKey        },
        { SK_Mac1Key,       k1_SkKey        },
        { SK_Mac2Key,       k2_SkKey        },
        { SK_Mac3Key,       k3_SkKey        },
        { SK_Mac4Key,       k4_SkKey        },
        { SK_Mac5Key,       k5_SkKey        },
        { SK_Mac6Key,       k6_SkKey        },
        { SK_Mac7Key,       k7_SkKey        },
        { SK_Mac8Key,       k8_SkKey        },
        { SK_Mac9Key,       k9_SkKey        }
>>>>>>> miniblink49
    };

    for (unsigned i = 0; i < SK_ARRAY_COUNT(gKeys); i++)
        if (gKeys[i].fRaw == raw)
            return gKeys[i].fKey;
    return kNONE_SkKey;
}

///////////////////////////////////////////////////////////////////////////////////////

void SkEvent::SignalNonEmptyQueue()
{
    SkOSWindow::ForAllWindows([](void* hWND, SkOSWindow**) {
        post_skwinevent((HWND)hWND);
    });
}

static UINT_PTR gTimer;

VOID CALLBACK sk_timer_proc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
    SkEvent::ServiceQueueTimer();
    //SkDebugf("timer task fired\n");
}

void SkEvent::SignalQueueTimer(SkMSec delay)
{
<<<<<<< HEAD
    if (gTimer) {
        KillTimer(NULL, gTimer);
        gTimer = NULL;
    }
    if (delay) {
=======
    if (gTimer)
    {
        KillTimer(NULL, gTimer);
        gTimer = NULL;
    }
    if (delay)
    {
>>>>>>> miniblink49
        gTimer = SetTimer(NULL, 0, delay, sk_timer_proc);
        //SkDebugf("SetTimer of %d returned %d\n", delay, gTimer);
    }
}

#if SK_SUPPORT_GPU

<<<<<<< HEAD
bool SkOSWindow::attachGL(int msaaSampleCount, bool deepColor, AttachmentInfo* info)
{
    HDC dc = GetDC((HWND)fHWND);
    if (NULL == fHGLRC) {
        fHGLRC = SkCreateWGLContext(dc, msaaSampleCount, deepColor,
            kGLPreferCompatibilityProfile_SkWGLContextRequest);
=======
bool SkOSWindow::attachGL(int msaaSampleCount, AttachmentInfo* info) {
    HDC dc = GetDC((HWND)fHWND);
    if (NULL == fHGLRC) {
        fHGLRC = SkCreateWGLContext(dc, msaaSampleCount,
                kGLPreferCompatibilityProfile_SkWGLContextRequest);
>>>>>>> miniblink49
        if (NULL == fHGLRC) {
            return false;
        }
        glClearStencil(0);
        glClearColor(0, 0, 0, 0);
        glStencilMask(0xffffffff);
        glClear(GL_STENCIL_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    }
    if (wglMakeCurrent(dc, (HGLRC)fHGLRC)) {
<<<<<<< HEAD
        // use DescribePixelFormat to get the stencil and color bit depth.
=======
        // use DescribePixelFormat to get the stencil bit depth.
>>>>>>> miniblink49
        int pixelFormat = GetPixelFormat(dc);
        PIXELFORMATDESCRIPTOR pfd;
        DescribePixelFormat(dc, pixelFormat, sizeof(pfd), &pfd);
        info->fStencilBits = pfd.cStencilBits;
<<<<<<< HEAD
        // pfd.cColorBits includes alpha, so it will be 32 in 8/8/8/8 and 10/10/10/2
        info->fColorBits = pfd.cRedBits + pfd.cGreenBits + pfd.cBlueBits;
=======
>>>>>>> miniblink49

        // Get sample count if the MSAA WGL extension is present
        SkWGLExtensions extensions;
        if (extensions.hasExtension(dc, "WGL_ARB_multisample")) {
            static const int kSampleCountAttr = SK_WGL_SAMPLES;
            extensions.getPixelFormatAttribiv(dc,
<<<<<<< HEAD
                pixelFormat,
                0,
                1,
                &kSampleCountAttr,
                &info->fSampleCount);
=======
                                              pixelFormat,
                                              0,
                                              1,
                                              &kSampleCountAttr,
                                              &info->fSampleCount);
>>>>>>> miniblink49
        } else {
            info->fSampleCount = 0;
        }

        glViewport(0, 0,
<<<<<<< HEAD
            SkScalarRoundToInt(this->width()),
            SkScalarRoundToInt(this->height()));
=======
                   SkScalarRoundToInt(this->width()),
                   SkScalarRoundToInt(this->height()));
>>>>>>> miniblink49
        return true;
    }
    return false;
}

<<<<<<< HEAD
void SkOSWindow::detachGL()
{
=======
void SkOSWindow::detachGL() {
>>>>>>> miniblink49
    wglMakeCurrent(GetDC((HWND)fHWND), 0);
    wglDeleteContext((HGLRC)fHGLRC);
    fHGLRC = NULL;
}

<<<<<<< HEAD
void SkOSWindow::presentGL()
{
=======
void SkOSWindow::presentGL() {
>>>>>>> miniblink49
    HDC dc = GetDC((HWND)fHWND);
    SwapBuffers(dc);
    ReleaseDC((HWND)fHWND, dc);
}

#if SK_ANGLE

<<<<<<< HEAD
static void* get_angle_egl_display(void* nativeDisplay)
{
    PFNEGLGETPLATFORMDISPLAYEXTPROC eglGetPlatformDisplayEXT;
    eglGetPlatformDisplayEXT = (PFNEGLGETPLATFORMDISPLAYEXTPROC)eglGetProcAddress("eglGetPlatformDisplayEXT");

    // We expect ANGLE to support this extension
    if (!eglGetPlatformDisplayEXT) {
        return EGL_NO_DISPLAY;
    }

    EGLDisplay display = EGL_NO_DISPLAY;
    // Try for an ANGLE D3D11 context, fall back to D3D9, and finally GL.
    EGLint attribs[3][3] = {
        { EGL_PLATFORM_ANGLE_TYPE_ANGLE,
            EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,
            EGL_NONE },
        { EGL_PLATFORM_ANGLE_TYPE_ANGLE,
            EGL_PLATFORM_ANGLE_TYPE_D3D9_ANGLE,
            EGL_NONE },
    };
    for (int i = 0; i < 3 && display == EGL_NO_DISPLAY; ++i) {
        display = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, nativeDisplay, attribs[i]);
    }
    return display;
}

struct ANGLEAssembleContext {
    ANGLEAssembleContext()
    {
        fEGL = GetModuleHandle("libEGL.dll");
        fGL = GetModuleHandle("libGLESv2.dll");
    }

    bool isValid() const { return SkToBool(fEGL) && SkToBool(fGL); }

    HMODULE fEGL;
    HMODULE fGL;
};

static GrGLFuncPtr angle_get_gl_proc(void* ctx, const char name[])
{
    const ANGLEAssembleContext& context = *reinterpret_cast<const ANGLEAssembleContext*>(ctx);
    GrGLFuncPtr proc = (GrGLFuncPtr)GetProcAddress(context.fGL, name);
    if (proc) {
        return proc;
    }
    proc = (GrGLFuncPtr)GetProcAddress(context.fEGL, name);
    if (proc) {
        return proc;
    }
    return eglGetProcAddress(name);
}

static const GrGLInterface* get_angle_gl_interface()
{
    ANGLEAssembleContext context;
    if (!context.isValid()) {
        return nullptr;
    }
    return GrGLAssembleGLESInterface(&context, angle_get_gl_proc);
}

bool create_ANGLE(EGLNativeWindowType hWnd,
    int msaaSampleCount,
    EGLDisplay* eglDisplay,
    EGLContext* eglContext,
    EGLSurface* eglSurface,
    EGLConfig* eglConfig)
{
=======
bool create_ANGLE(EGLNativeWindowType hWnd,
                  int msaaSampleCount,
                  EGLDisplay* eglDisplay,
                  EGLContext* eglContext,
                  EGLSurface* eglSurface,
                  EGLConfig* eglConfig) {
>>>>>>> miniblink49
    static const EGLint contextAttribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE, EGL_NONE
    };
    static const EGLint configAttribList[] = {
<<<<<<< HEAD
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_DEPTH_SIZE, 8,
        EGL_STENCIL_SIZE, 8,
=======
        EGL_RED_SIZE,       8,
        EGL_GREEN_SIZE,     8,
        EGL_BLUE_SIZE,      8,
        EGL_ALPHA_SIZE,     8,
        EGL_DEPTH_SIZE,     8,
        EGL_STENCIL_SIZE,   8,
>>>>>>> miniblink49
        EGL_NONE
    };
    static const EGLint surfaceAttribList[] = {
        EGL_NONE, EGL_NONE
    };

<<<<<<< HEAD
    EGLDisplay display = get_angle_egl_display(GetDC(hWnd));
=======
    EGLDisplay display = SkANGLEGLContext::GetD3DEGLDisplay(GetDC(hWnd));
>>>>>>> miniblink49

    if (EGL_NO_DISPLAY == display) {
        SkDebugf("Could not create ANGLE egl display!\n");
        return false;
    }

    // Initialize EGL
    EGLint majorVersion, minorVersion;
    if (!eglInitialize(display, &majorVersion, &minorVersion)) {
<<<<<<< HEAD
        return false;
=======
       return false;
>>>>>>> miniblink49
    }

    EGLint numConfigs;
    if (!eglGetConfigs(display, NULL, 0, &numConfigs)) {
<<<<<<< HEAD
        return false;
=======
       return false;
>>>>>>> miniblink49
    }

    // Choose config
    bool foundConfig = false;
    if (msaaSampleCount) {
<<<<<<< HEAD
        static const int kConfigAttribListCnt = SK_ARRAY_COUNT(configAttribList);
        EGLint msaaConfigAttribList[kConfigAttribListCnt + 4];
        memcpy(msaaConfigAttribList,
            configAttribList,
            sizeof(configAttribList));
=======
        static const int kConfigAttribListCnt =
                                SK_ARRAY_COUNT(configAttribList);
        EGLint msaaConfigAttribList[kConfigAttribListCnt + 4];
        memcpy(msaaConfigAttribList,
               configAttribList,
               sizeof(configAttribList));
>>>>>>> miniblink49
        SkASSERT(EGL_NONE == msaaConfigAttribList[kConfigAttribListCnt - 1]);
        msaaConfigAttribList[kConfigAttribListCnt - 1] = EGL_SAMPLE_BUFFERS;
        msaaConfigAttribList[kConfigAttribListCnt + 0] = 1;
        msaaConfigAttribList[kConfigAttribListCnt + 1] = EGL_SAMPLES;
        msaaConfigAttribList[kConfigAttribListCnt + 2] = msaaSampleCount;
        msaaConfigAttribList[kConfigAttribListCnt + 3] = EGL_NONE;
<<<<<<< HEAD
        if (eglChooseConfig(display, msaaConfigAttribList, eglConfig, 1, &numConfigs)) {
=======
        if (eglChooseConfig(display, configAttribList, eglConfig, 1, &numConfigs)) {
>>>>>>> miniblink49
            SkASSERT(numConfigs > 0);
            foundConfig = true;
        }
    }
    if (!foundConfig) {
        if (!eglChooseConfig(display, configAttribList, eglConfig, 1, &numConfigs)) {
<<<<<<< HEAD
            return false;
=======
           return false;
>>>>>>> miniblink49
        }
    }

    // Create a surface
    EGLSurface surface = eglCreateWindowSurface(display, *eglConfig,
<<<<<<< HEAD
        (EGLNativeWindowType)hWnd,
        surfaceAttribList);
    if (surface == EGL_NO_SURFACE) {
        return false;
=======
                                                (EGLNativeWindowType)hWnd,
                                                surfaceAttribList);
    if (surface == EGL_NO_SURFACE) {
       return false;
>>>>>>> miniblink49
    }

    // Create a GL context
    EGLContext context = eglCreateContext(display, *eglConfig,
<<<<<<< HEAD
        EGL_NO_CONTEXT,
        contextAttribs);
    if (context == EGL_NO_CONTEXT) {
        return false;
=======
                                          EGL_NO_CONTEXT,
                                          contextAttribs );
    if (context == EGL_NO_CONTEXT ) {
       return false;
>>>>>>> miniblink49
    }

    // Make the context current
    if (!eglMakeCurrent(display, surface, surface, context)) {
<<<<<<< HEAD
        return false;
=======
       return false;
>>>>>>> miniblink49
    }

    *eglDisplay = display;
    *eglContext = context;
    *eglSurface = surface;
    return true;
}

<<<<<<< HEAD
bool SkOSWindow::attachANGLE(int msaaSampleCount, AttachmentInfo* info)
{
    if (EGL_NO_DISPLAY == fDisplay) {
        bool bResult = create_ANGLE((HWND)fHWND,
            msaaSampleCount,
            &fDisplay,
            &fContext,
            &fSurface,
            &fConfig);
        if (false == bResult) {
            return false;
        }
        fANGLEInterface.reset(get_angle_gl_interface());
        if (!fANGLEInterface) {
            this->detachANGLE();
            return false;
        }
        GL_CALL(fANGLEInterface, ClearStencil(0));
        GL_CALL(fANGLEInterface, ClearColor(0, 0, 0, 0));
        GL_CALL(fANGLEInterface, StencilMask(0xffffffff));
        GL_CALL(fANGLEInterface, Clear(GL_STENCIL_BUFFER_BIT | GL_COLOR_BUFFER_BIT));
    }
    if (!eglMakeCurrent(fDisplay, fSurface, fSurface, fContext)) {
        this->detachANGLE();
        return false;
    }
    eglGetConfigAttrib(fDisplay, fConfig, EGL_STENCIL_SIZE, &info->fStencilBits);
    eglGetConfigAttrib(fDisplay, fConfig, EGL_SAMPLES, &info->fSampleCount);

    GL_CALL(fANGLEInterface, Viewport(0, 0, SkScalarRoundToInt(this->width()), SkScalarRoundToInt(this->height())));
    return true;
}

void SkOSWindow::detachANGLE()
{
    fANGLEInterface.reset(nullptr);
    eglMakeCurrent(fDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
=======
bool SkOSWindow::attachANGLE(int msaaSampleCount, AttachmentInfo* info) {
    if (EGL_NO_DISPLAY == fDisplay) {
        bool bResult = create_ANGLE((HWND)fHWND,
                                    msaaSampleCount,
                                    &fDisplay,
                                    &fContext,
                                    &fSurface,
                                    &fConfig);
        if (false == bResult) {
            return false;
        }
        SkAutoTUnref<const GrGLInterface> intf(GrGLCreateANGLEInterface());

        if (intf) {
            ANGLE_GL_CALL(intf, ClearStencil(0));
            ANGLE_GL_CALL(intf, ClearColor(0, 0, 0, 0));
            ANGLE_GL_CALL(intf, StencilMask(0xffffffff));
            ANGLE_GL_CALL(intf, Clear(GL_STENCIL_BUFFER_BIT |GL_COLOR_BUFFER_BIT));
        }
    }
    if (eglMakeCurrent(fDisplay, fSurface, fSurface, fContext)) {
        eglGetConfigAttrib(fDisplay, fConfig, EGL_STENCIL_SIZE, &info->fStencilBits);
        eglGetConfigAttrib(fDisplay, fConfig, EGL_SAMPLES, &info->fSampleCount);

        SkAutoTUnref<const GrGLInterface> intf(GrGLCreateANGLEInterface());

        if (intf ) {
            ANGLE_GL_CALL(intf, Viewport(0, 0,
                                         SkScalarRoundToInt(this->width()),
                                         SkScalarRoundToInt(this->height())));
        }
        return true;
    }
    return false;
}

void SkOSWindow::detachANGLE() {
    eglMakeCurrent(fDisplay, EGL_NO_SURFACE , EGL_NO_SURFACE , EGL_NO_CONTEXT);
>>>>>>> miniblink49

    eglDestroyContext(fDisplay, fContext);
    fContext = EGL_NO_CONTEXT;

    eglDestroySurface(fDisplay, fSurface);
    fSurface = EGL_NO_SURFACE;

    eglTerminate(fDisplay);
    fDisplay = EGL_NO_DISPLAY;
}

<<<<<<< HEAD
void SkOSWindow::presentANGLE()
{
    GL_CALL(fANGLEInterface, Flush());
=======
void SkOSWindow::presentANGLE() {
    SkAutoTUnref<const GrGLInterface> intf(GrGLCreateANGLEInterface());

    if (intf) {
        ANGLE_GL_CALL(intf, Flush());
    }
>>>>>>> miniblink49

    eglSwapBuffers(fDisplay, fSurface);
}
#endif // SK_ANGLE
<<<<<<< HEAD

#endif // SK_SUPPORT_GPU

// return true on success
bool SkOSWindow::attach(SkBackEndTypes attachType, int msaaSampleCount, bool deepColor,
    AttachmentInfo* info)
{
=======
#endif // SK_SUPPORT_GPU

// return true on success
bool SkOSWindow::attach(SkBackEndTypes attachType, int msaaSampleCount, AttachmentInfo* info) {
>>>>>>> miniblink49

    // attach doubles as "windowResize" so we need to allo
    // already bound states to pass through again
    // TODO: split out the resize functionality
<<<<<<< HEAD
    //    SkASSERT(kNone_BackEndType == fAttached);
=======
//    SkASSERT(kNone_BackEndType == fAttached);
>>>>>>> miniblink49
    bool result = true;

    switch (attachType) {
    case kNone_BackEndType:
        // nothing to do
        break;
#if SK_SUPPORT_GPU
    case kNativeGL_BackEndType:
<<<<<<< HEAD
        result = attachGL(msaaSampleCount, deepColor, info);
=======
        result = attachGL(msaaSampleCount, info);
>>>>>>> miniblink49
        break;
#if SK_ANGLE
    case kANGLE_BackEndType:
        result = attachANGLE(msaaSampleCount, info);
        break;
#endif // SK_ANGLE
#endif // SK_SUPPORT_GPU
    default:
        SkASSERT(false);
        result = false;
        break;
    }

    if (result) {
        fAttached = attachType;
    }

    return result;
}

<<<<<<< HEAD
void SkOSWindow::release()
{
=======
void SkOSWindow::detach() {
>>>>>>> miniblink49
    switch (fAttached) {
    case kNone_BackEndType:
        // nothing to do
        break;
#if SK_SUPPORT_GPU
    case kNativeGL_BackEndType:
        detachGL();
        break;
#if SK_ANGLE
    case kANGLE_BackEndType:
        detachANGLE();
        break;
#endif // SK_ANGLE
#endif // SK_SUPPORT_GPU
    default:
        SkASSERT(false);
        break;
    }
    fAttached = kNone_BackEndType;
}

<<<<<<< HEAD
void SkOSWindow::present()
{
=======
void SkOSWindow::present() {
>>>>>>> miniblink49
    switch (fAttached) {
    case kNone_BackEndType:
        // nothing to do
        return;
#if SK_SUPPORT_GPU
    case kNativeGL_BackEndType:
        presentGL();
        break;
#if SK_ANGLE
    case kANGLE_BackEndType:
        presentANGLE();
        break;
#endif // SK_ANGLE
#endif // SK_SUPPORT_GPU
    default:
        SkASSERT(false);
        break;
    }
}

<<<<<<< HEAD
bool SkOSWindow::makeFullscreen()
{
    if (fFullscreen) {
        return true;
    }
#if SK_SUPPORT_GPU
    if (fHGLRC) {
        this->detachGL();
    }
#endif // SK_SUPPORT_GPU
=======
bool SkOSWindow::makeFullscreen() {
    if (fFullscreen) {
        return true;
    }
    if (fHGLRC) {
        this->detachGL();
    }
>>>>>>> miniblink49
    // This is hacked together from various sources on the web. It can certainly be improved and be
    // made more robust.

    // Save current window/resolution information. We do this in case we ever implement switching
    // back to windowed mode.
    fSavedWindowState.fZoomed = SkToBool(IsZoomed((HWND)fHWND));
    if (fSavedWindowState.fZoomed) {
        SendMessage((HWND)fHWND, WM_SYSCOMMAND, SC_RESTORE, 0);
    }
    fSavedWindowState.fStyle = GetWindowLong((HWND)fHWND, GWL_STYLE);
    fSavedWindowState.fExStyle = GetWindowLong((HWND)fHWND, GWL_EXSTYLE);
    GetWindowRect((HWND)fHWND, &fSavedWindowState.fRect);
    DEVMODE currScreenSettings;
<<<<<<< HEAD
    memset(&currScreenSettings, 0, sizeof(currScreenSettings));
=======
    memset(&currScreenSettings,0,sizeof(currScreenSettings));
>>>>>>> miniblink49
    currScreenSettings.dmSize = sizeof(currScreenSettings);
    EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &currScreenSettings);
    fSavedWindowState.fScreenWidth = currScreenSettings.dmPelsWidth;
    fSavedWindowState.fScreenHeight = currScreenSettings.dmPelsHeight;
    fSavedWindowState.fScreenBits = currScreenSettings.dmBitsPerPel;
    fSavedWindowState.fHWND = fHWND;

    // Try different sizes to find an allowed setting? Use ChangeDisplaySettingsEx?
    static const int kWidth = 1280;
    static const int kHeight = 1024;
    DEVMODE newScreenSettings;
    memset(&newScreenSettings, 0, sizeof(newScreenSettings));
    newScreenSettings.dmSize = sizeof(newScreenSettings);
<<<<<<< HEAD
    newScreenSettings.dmPelsWidth = kWidth;
    newScreenSettings.dmPelsHeight = kHeight;
    newScreenSettings.dmBitsPerPel = 32;
    newScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
=======
    newScreenSettings.dmPelsWidth    = kWidth;
    newScreenSettings.dmPelsHeight   = kHeight;
    newScreenSettings.dmBitsPerPel   = 32;
    newScreenSettings.dmFields = DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;
>>>>>>> miniblink49
    if (ChangeDisplaySettings(&newScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL) {
        return false;
    }
    RECT WindowRect;
    WindowRect.left = 0;
    WindowRect.right = kWidth;
    WindowRect.top = 0;
<<<<<<< HEAD
    WindowRect.bottom = kHeight;
=======
    WindowRect.bottom = kHeight;     
>>>>>>> miniblink49
    ShowCursor(FALSE);
    AdjustWindowRectEx(&WindowRect, WS_POPUP, FALSE, WS_EX_APPWINDOW);
    HWND fsHWND = CreateWindowEx(
        WS_EX_APPWINDOW,
        fWinInit.fClass,
        NULL,
        WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
<<<<<<< HEAD
        0, 0, WindowRect.right - WindowRect.left, WindowRect.bottom - WindowRect.top,
        NULL,
        NULL,
        fWinInit.fInstance,
        NULL);
=======
        0, 0, WindowRect.right-WindowRect.left, WindowRect.bottom-WindowRect.top,
        NULL,
        NULL,
        fWinInit.fInstance,
        NULL
    );
>>>>>>> miniblink49
    if (!fsHWND) {
        return false;
    }
    // Hide the old window and set the entry in the global mapping for this SkOSWindow to the
    // new HWND.
    ShowWindow((HWND)fHWND, SW_HIDE);
    gHwndToOSWindowMap.remove(fHWND);
    fHWND = fsHWND;
    gHwndToOSWindowMap.set(fHWND, this);
    this->updateSize();

    fFullscreen = true;
    return true;
}

<<<<<<< HEAD
void SkOSWindow::setVsync(bool enable)
{
=======
void SkOSWindow::setVsync(bool enable) {
>>>>>>> miniblink49
    SkWGLExtensions wgl;
    wgl.swapInterval(enable ? 1 : 0);
}

<<<<<<< HEAD
void SkOSWindow::closeWindow()
{
=======
void SkOSWindow::closeWindow() {
>>>>>>> miniblink49
    DestroyWindow((HWND)fHWND);
    if (fFullscreen) {
        DestroyWindow((HWND)fSavedWindowState.fHWND);
    }
    gHwndToOSWindowMap.remove(fHWND);
}
#endif
