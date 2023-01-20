<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkOSWindow_SDL.h"
#include "SkCanvas.h"
<<<<<<< HEAD

#if defined(SK_BUILD_FOR_ANDROID)
#include <GLES/gl.h>
#elif defined(SK_BUILD_FOR_UNIX)
#include <GL/gl.h>
#elif defined(SK_BUILD_FOR_MAC)
#include <gl.h>
#endif

const int kInitialWindowWidth = 640;
const int kInitialWindowHeight = 480;
static SkOSWindow* gCurrentWindow;

static void report_sdl_error(const char* failure)
{
    const char* error = SDL_GetError();
    SkASSERT(error); // Called only to check SDL error.
    SkDebugf("%s SDL Error: %s.\n", failure, error);
    SDL_ClearError();
}
SkOSWindow::SkOSWindow(void*)
    : fWindow(nullptr)
    , fGLContext(nullptr)
    , fWindowMSAASampleCount(0)
{

    SkASSERT(!gCurrentWindow);
    gCurrentWindow = this;

    this->createWindow(0);
}

SkOSWindow::~SkOSWindow()
{
    this->destroyWindow();
    gCurrentWindow = nullptr;
}

SkOSWindow* SkOSWindow::GetInstanceForWindowID(Uint32 windowID)
{
    if (gCurrentWindow && gCurrentWindow->fWindow && SDL_GetWindowID(gCurrentWindow->fWindow) == windowID) {
        return gCurrentWindow;
    }
    return nullptr;
}

void SkOSWindow::release()
{
    if (fGLContext) {
        SDL_GL_DeleteContext(fGLContext);
        fGLContext = nullptr;
    }
}

bool SkOSWindow::attach(SkBackEndTypes attachType, int msaaSampleCount, bool deepColor,
    AttachmentInfo* info)
{
    this->createWindow(msaaSampleCount);
    if (!fWindow) {
        return false;
    }
    if (!fGLContext) {
        fGLContext = SDL_GL_CreateContext(fWindow);
        if (!fGLContext) {
            report_sdl_error("Failed to create SDL GL context.");
            return false;
        }
        glClearColor(0, 0, 0, 0);
        glClearStencil(0);
        glStencilMask(0xffffffff);
        glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    }

    if (SDL_GL_MakeCurrent(fWindow, fGLContext) != 0) {
        report_sdl_error("Failed to make SDL GL context current.");
        this->release();
        return false;
    }

    info->fSampleCount = msaaSampleCount;
    info->fStencilBits = 8;

    glViewport(0, 0, SkScalarRoundToInt(this->width()), SkScalarRoundToInt(this->height()));
    return true;
}

void SkOSWindow::present()
{
    if (!fWindow) {
        return;
    }
    SDL_GL_SwapWindow(fWindow);
}

bool SkOSWindow::makeFullscreen()
{
    if (!fWindow) {
        return false;
    }
    SDL_SetWindowFullscreen(fWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
    return true;
}

void SkOSWindow::setVsync(bool vsync)
{
    if (!fWindow) {
        return;
    }
    SDL_GL_SetSwapInterval(vsync ? 1 : 0);
}

void SkOSWindow::closeWindow()
{
    this->destroyWindow();

    // Currently closing the window causes the app to quit.
    SDL_Event event;
    event.type = SDL_QUIT;
    SDL_PushEvent(&event);
}

static SkKey convert_sdlkey_to_skkey(SDL_Keycode src)
{
    switch (src) {
    case SDLK_UP:
        return kUp_SkKey;
    case SDLK_DOWN:
        return kDown_SkKey;
    case SDLK_LEFT:
        return kLeft_SkKey;
    case SDLK_RIGHT:
        return kRight_SkKey;
    case SDLK_HOME:
        return kHome_SkKey;
    case SDLK_END:
        return kEnd_SkKey;
    case SDLK_ASTERISK:
        return kStar_SkKey;
    case SDLK_HASH:
        return kHash_SkKey;
    case SDLK_0:
        return k0_SkKey;
    case SDLK_1:
        return k1_SkKey;
    case SDLK_2:
        return k2_SkKey;
    case SDLK_3:
        return k3_SkKey;
    case SDLK_4:
        return k4_SkKey;
    case SDLK_5:
        return k5_SkKey;
    case SDLK_6:
        return k6_SkKey;
    case SDLK_7:
        return k7_SkKey;
    case SDLK_8:
        return k8_SkKey;
    case SDLK_9:
        return k9_SkKey;
    default:
        return kNONE_SkKey;
    }
}

void SkOSWindow::createWindow(int msaaSampleCount)
{
    if (fWindowMSAASampleCount != msaaSampleCount) {
        this->destroyWindow();
    }
    if (fWindow) {
        return;
    }
    uint32_t windowFlags =
#if defined(SK_BUILD_FOR_ANDROID)
        SDL_WINDOW_BORDERLESS | SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_ALLOW_HIGHDPI |
#endif
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;

    // GL settings are part of SDL_WINDOW_OPENGL window creation arguments.
#if defined(SK_BUILD_FOR_ANDROID)
    // TODO we should try and get a 3.0 context first
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
#else
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
#endif
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
#if defined(SK_BUILD_FOR_UNIX)
    // Apparently MSAA request matches "slow caveat". Make SDL not set anything for caveat for MSAA
    // by setting -1 for ACCELERATED_VISUAL. For non-MSAA, set ACCELERATED_VISUAL to 1 just for
    // compatiblity with other platforms.
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, msaaSampleCount > 0 ? -1 : 1);
#else
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
#endif
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, msaaSampleCount > 0 ? 1 : 0);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, msaaSampleCount);

    // This is an approximation for sizing purposes.
    bool isInitialWindow = this->width() == 0 && this->height() == 0;
    SkScalar windowWidth = isInitialWindow ? kInitialWindowWidth : this->width();
    SkScalar windowHeight = isInitialWindow ? kInitialWindowHeight : this->height();

    fWindow = SDL_CreateWindow(this->getTitle(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        windowWidth, windowHeight, windowFlags);
    if (!fWindow) {
        report_sdl_error("Failed to create SDL window.");
        return;
    }
    fWindowMSAASampleCount = msaaSampleCount;
}

void SkOSWindow::destroyWindow()
{
    this->release();
    if (fWindow) {
        SDL_DestroyWindow(fWindow);
        fWindow = nullptr;
        fWindowMSAASampleCount = 0;
    }
}

bool SkOSWindow::HasDirtyWindows()
{
    if (gCurrentWindow && gCurrentWindow->fWindow) {
        return gCurrentWindow->isDirty();
    }
    return false;
}

void SkOSWindow::UpdateDirtyWindows()
{
    if (gCurrentWindow && gCurrentWindow->fWindow) {
        if (gCurrentWindow->isDirty()) {
            // This will call present.
            gCurrentWindow->update(nullptr);
        }
    }
}

void SkOSWindow::HandleEvent(const SDL_Event& event)
{
    switch (event.type) {
    case SDL_MOUSEMOTION:
        if (SkOSWindow* window = GetInstanceForWindowID(event.motion.windowID)) {
            if (event.motion.state == SDL_PRESSED) {
                window->handleClick(event.motion.x, event.motion.y,
                    SkView::Click::kMoved_State, nullptr);
            }
        }
        break;
    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP:
        if (SkOSWindow* window = GetInstanceForWindowID(event.button.windowID)) {
            window->handleClick(event.button.x, event.button.y,
                event.button.state == SDL_PRESSED ? SkView::Click::kDown_State : SkView::Click::kUp_State, nullptr);
        }
        break;
    case SDL_KEYDOWN:
        if (SkOSWindow* window = GetInstanceForWindowID(event.key.windowID)) {
            SDL_Keycode key = event.key.keysym.sym;
            SkKey sk = convert_sdlkey_to_skkey(key);
            if (kNONE_SkKey != sk) {
                if (event.key.state == SDL_PRESSED) {
                    window->handleKey(sk);
                } else {
                    window->handleKeyUp(sk);
                }
            } else if (key == SDLK_ESCAPE) {
                window->closeWindow();
            }
        }
        break;
    case SDL_TEXTINPUT:
        if (SkOSWindow* window = GetInstanceForWindowID(event.text.windowID)) {
            size_t len = strlen(event.text.text);
            for (size_t i = 0; i < len; i++) {
                window->handleChar((SkUnichar)event.text.text[i]);
            }
        }
        break;
    case SDL_WINDOWEVENT:
        switch (event.window.event) {
        case SDL_WINDOWEVENT_SHOWN:
            // For initialization purposes, we resize upon first show.
            // Fallthrough.
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            if (SkOSWindow* window = GetInstanceForWindowID(event.window.windowID)) {
                int w = 0;
                int h = 0;
                SDL_GetWindowSize(window->fWindow, &w, &h);
                window->resize(w, h);
            }
            break;
        case SDL_WINDOWEVENT_FOCUS_GAINED:
            if (GetInstanceForWindowID(event.text.windowID)) {
                SDL_StartTextInput();
            }
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

SkMSec gTimerDelay;

void SkOSWindow::RunEventLoop()
{
    for (;;) {
        SkEvent::ServiceQueueTimer();
        bool hasMoreSkEvents = SkEvent::ProcessEvent();

        SDL_Event event;
        bool hasSDLEvents = SDL_PollEvent(&event) == 1;

        // Invalidations do not post to event loop, rather we just go through the
        // windows for each event loop iteration.
        bool hasDirtyWindows = HasDirtyWindows();

        if (!hasSDLEvents && !hasMoreSkEvents && !hasDirtyWindows) {
            // If there is no SDL events, SkOSWindow updates or SkEvents
            // to be done, wait for the SDL events.
            if (gTimerDelay > 0) {
                hasSDLEvents = SDL_WaitEventTimeout(&event, gTimerDelay) == 1;
            } else {
                hasSDLEvents = SDL_WaitEvent(&event) == 1;
            }
        }
        while (hasSDLEvents) {
            if (event.type == SDL_QUIT) {
                return;
            }
            HandleEvent(event);
            hasSDLEvents = SDL_PollEvent(&event);
        }
        UpdateDirtyWindows();
    }
}

void SkOSWindow::onSetTitle(const char title[])
{
    if (!fWindow) {
        return;
    }
    this->updateWindowTitle();
}

void SkOSWindow::updateWindowTitle()
{
    SDL_SetWindowTitle(fWindow, this->getTitle());
}
///////////////////////////////////////////////////////////////////////////////////////

void SkEvent::SignalNonEmptyQueue()
{
    // nothing to do, since we spin on our event-queue
=======
#include "SkColorPriv.h"
#include "SkGLCanvas.h"
#include "SkOSMenu.h"
#include "SkTime.h"

static void post_SkEvent_event() {
    SDL_Event evt;
    evt.type = SDL_USEREVENT;
    evt.user.type = SDL_USEREVENT;
    evt.user.code = 0;
    evt.user.data1 = NULL;
    evt.user.data2 = NULL;
    SDL_PushEvent(&evt);
}

static bool skia_setBitmapFromSurface(SkBitmap* dst, SDL_Surface* src) {
    SkColorType ct;
    SkAlphaType at;

    switch (src->format->BytesPerPixel) {
        case 2:
            ct = kRGB_565_SkColorType;
            at = kOpaque_SkAlphaType;
            break;
        case 4:
            ct = kN32_SkColorType;
            at = kPremul_SkAlphaType;
            break;
        default:
            return false;
    }

    return dst->installPixels(SkImageInfo::Make(src->w, src->h, ct, at), src->pixels, src->pitch);
}

SkOSWindow::SkOSWindow(void* screen) {
    fScreen = reinterpret_cast<SDL_Surface*>(screen);
    this->resize(fScreen->w, fScreen->h);

    uint32_t rmask = SK_R32_MASK << SK_R32_SHIFT;
    uint32_t gmask = SK_G32_MASK << SK_G32_SHIFT;
    uint32_t bmask = SK_B32_MASK << SK_B32_SHIFT;
    uint32_t amask = SK_A32_MASK << SK_A32_SHIFT;

    if (fScreen->flags & SDL_OPENGL) {
        fSurface = NULL;
        fGLCanvas = new SkGLCanvas;
        fGLCanvas->setViewport(fScreen->w, fScreen->h);
    } else {
        fGLCanvas = NULL;
        fSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, fScreen->w, fScreen->h,
                                        32, rmask, gmask, bmask, amask);
    }
}

SkOSWindow::~SkOSWindow() {
    delete fGLCanvas;
    if (fSurface) {
        SDL_FreeSurface(fSurface);
    }
}

#include <OpenGL/gl.h>

void SkOSWindow::doDraw() {
    if (fGLCanvas) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
        glEnable(GL_TEXTURE_2D);
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        int count = fGLCanvas->save();
        this->draw(fGLCanvas);
        fGLCanvas->restoreToCount(count);
        SDL_GL_SwapBuffers( );
    } else {
        if ( SDL_MUSTLOCK(fSurface) ) {
            if ( SDL_LockSurface(fSurface) < 0 ) {
                return;
            }
        }

        SkBitmap bitmap;

        if (skia_setBitmapFromSurface(&bitmap, fSurface)) {
            SkCanvas canvas(bitmap);
            this->draw(&canvas);
        }

        if ( SDL_MUSTLOCK(fSurface) ) {
            SDL_UnlockSurface(fSurface);
        }

        int result = SDL_BlitSurface(fSurface, NULL, fScreen, NULL);
        if (result) {
            SkDebugf("------- SDL_BlitSurface returned %d\n", result);
        }
        SDL_UpdateRect(fScreen, 0, 0, fScreen->w, fScreen->h);
    }
}

static SkKey find_skkey(SDLKey src) {
    // this array must match the enum order in SkKey.h
    static const SDLKey gKeys[] = {
        SDLK_UNKNOWN,
        SDLK_UNKNOWN,   // left softkey
        SDLK_UNKNOWN,   // right softkey
        SDLK_UNKNOWN,   // home
        SDLK_UNKNOWN,   // back
        SDLK_UNKNOWN,   // send
        SDLK_UNKNOWN,   // end
        SDLK_0,
        SDLK_1,
        SDLK_2,
        SDLK_3,
        SDLK_4,
        SDLK_5,
        SDLK_6,
        SDLK_7,
        SDLK_8,
        SDLK_9,
        SDLK_ASTERISK,
        SDLK_HASH,
        SDLK_UP,
        SDLK_DOWN,
        SDLK_LEFT,
        SDLK_RIGHT,
        SDLK_RETURN,    // OK
        SDLK_UNKNOWN,   // volume up
        SDLK_UNKNOWN,   // volume down
        SDLK_UNKNOWN,   // power
        SDLK_UNKNOWN,   // camera
    };

    const SDLKey* array = gKeys;
    for (size_t i = 0; i < SK_ARRAY_COUNT(gKeys); i++) {
        if (array[i] == src) {
            return static_cast<SkKey>(i);
        }
    }
    return kNONE_SkKey;
}

void SkOSWindow::handleSDLEvent(const SDL_Event& event) {
    switch (event.type) {
        case SDL_VIDEORESIZE:
            this->resize(event.resize.w, event.resize.h);
            break;
        case SDL_VIDEOEXPOSE:
            this->doDraw();
            break;
        case SDL_MOUSEMOTION:
            if (event.motion.state == SDL_PRESSED) {
                this->handleClick(event.motion.x, event.motion.y,
                                   SkView::Click::kMoved_State);
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
            this->handleClick(event.button.x, event.button.y,
                               event.button.state == SDL_PRESSED ?
                               SkView::Click::kDown_State :
                               SkView::Click::kUp_State);
            break;
        case SDL_KEYDOWN: {
            SkKey sk = find_skkey(event.key.keysym.sym);
            if (kNONE_SkKey != sk) {
                if (event.key.state == SDL_PRESSED) {
                    this->handleKey(sk);
                } else {
                    this->handleKeyUp(sk);
                }
            }
            break;
        }
        case SDL_USEREVENT:
            if (SkEvent::ProcessEvent()) {
                post_SkEvent_event();
            }
            break;
    }
}

void SkOSWindow::onHandleInval(const SkIRect& r) {
    SDL_Event evt;
    evt.type = SDL_VIDEOEXPOSE;
    evt.expose.type = SDL_VIDEOEXPOSE;
    SDL_PushEvent(&evt);
}

void SkOSWindow::onSetTitle(const char title[]) {
    SDL_WM_SetCaption(title, NULL);
}

void SkOSWindow::onAddMenu(const SkOSMenu* sk_menu) {}

///////////////////////////////////////////////////////////////////////////////////////

void SkEvent::SignalNonEmptyQueue() {
    SkDebugf("-------- signal nonempty\n");
    post_SkEvent_event();
}

static Uint32 timer_callback(Uint32 interval) {
//    SkDebugf("-------- timercallback %d\n", interval);
    SkEvent::ServiceQueueTimer();
    return 0;
>>>>>>> miniblink49
}

void SkEvent::SignalQueueTimer(SkMSec delay)
{
<<<<<<< HEAD
    gTimerDelay = delay;
}

//////////////////////////////////////////////////////////////////////////////////////////////

#include "SkApplication.h"
#include "SkEvent.h"
#include "SkWindow.h"

#if defined(SK_BUILD_FOR_ANDROID)
int SDL_main(int argc, char** argv)
{
#else
int main(int argc, char** argv)
{
#endif
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        report_sdl_error("Failed to init SDL.");
        return -1;
    }

    application_init();

    SkOSWindow* window = create_sk_window(nullptr, argc, argv);

    // drain any events that occurred before |window| was assigned.
    while (SkEvent::ProcessEvent())
        ;

    SkOSWindow::RunEventLoop();

    delete window;
    application_term();

    SDL_Quit();

    return 0;
=======
    SDL_SetTimer(0, NULL);
    if (delay) {
        SDL_SetTimer(delay, timer_callback);
    }
>>>>>>> miniblink49
}
