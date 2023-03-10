/*
* Copyright 2016 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#ifndef Window_unix_DEFINED
#define Window_unix_DEFINED

#include "../Window.h"
#include "SkChecksum.h"
#include "SkTDynamicHash.h"
#include <GL/glx.h>
#include <X11/Xlib.h>

typedef Window XWindow;

namespace sk_app {

struct ContextPlatformData_unix {
    Display* fDisplay;
    XWindow fWindow;
    XVisualInfo* fVisualInfo;
};

class Window_unix : public Window {
public:
    Window_unix()
        : Window()
        , fDisplay(nullptr)
        , fWindow(0)
        , fGC(nullptr)
        , fVisualInfo(nullptr)
        , fMSAASampleCount(0)
    {
    }
    ~Window_unix() override { this->closeWindow(); }

    bool initWindow(Display* display, const DisplayParams* params);

    void setTitle(const char*) override;
    void show() override;

    bool attach(BackendType attachType, const DisplayParams& params) override;

    void onInval() override;

    bool handleEvent(const XEvent& event);

    static const XWindow& GetKey(const Window_unix& w)
    {
        return w.fWindow;
    }

    static uint32_t Hash(const XWindow& w)
    {
        return SkChecksum::Mix(w);
    }

    static SkTDynamicHash<Window_unix, XWindow> gWindowMap;

    void markPendingPaint() { fPendingPaint = true; }
    void finishPaint()
    {
        if (fPendingPaint) {
            this->onPaint();
            fPendingPaint = false;
        }
    }

    void markPendingResize(int width, int height)
    {
        fPendingWidth = width;
        fPendingHeight = height;
        fPendingResize = true;
    }
    void finishResize()
    {
        if (fPendingResize) {
            this->onResize(fPendingWidth, fPendingHeight);
            fPendingResize = false;
        }
    }

private:
    void closeWindow();

    Display* fDisplay;
    XWindow fWindow;
    GC fGC;
    XVisualInfo* fVisualInfo;
    int fMSAASampleCount;

    Atom fWmDeleteMessage;

    bool fPendingPaint;
    int fPendingWidth;
    int fPendingHeight;
    bool fPendingResize;
};

} // namespace sk_app

#endif
