
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkOSWindow_iOS_DEFINED
#define SkOSWindow_iOS_DEFINED

#include "SkWindow.h"

class SkOSWindow : public SkWindow {
public:
    SkOSWindow(void* hwnd);
    ~SkOSWindow();
<<<<<<< HEAD
    void* getHWND() const { return fHWND; }
=======
    void*   getHWND() const { return fHWND; }
>>>>>>> miniblink49

    enum SkBackEndTypes {
        kNone_BackEndType,
        kNativeGL_BackEndType,
    };

<<<<<<< HEAD
    void release();
    bool attach(SkBackEndTypes attachType, int msaaSampleCount, bool deepColor,
        AttachmentInfo*);
    void present();

    bool makeFullscreen() { return true; }
    void closeWindow()
    { /* Not impl yet */
    }
    void setVsync(bool)
    { /* Can't turn off vsync? */
    }
=======
    void    detach();
    bool    attach(SkBackEndTypes attachType, int msaaSampleCount, AttachmentInfo*);
    void    present();

    bool makeFullscreen() { return true; }
    void closeWindow() { /* Not impl yet */ }
    void setVsync(bool) { /* Can't turn off vsync? */ }
>>>>>>> miniblink49

protected:
    // overrides from SkEventSink
    virtual bool onEvent(const SkEvent& evt);
    // overrides from SkWindow
    virtual void onHandleInval(const SkIRect&);
    // overrides from SkView
    virtual void onAddMenu(const SkOSMenu*);
    virtual void onUpdateMenu(SkOSMenu*);
    virtual void onSetTitle(const char[]);

private:
<<<<<<< HEAD
    void* fHWND;
    bool fInvalEventIsPending;
    void* fNotifier;
=======
    void*   fHWND;
    bool    fInvalEventIsPending;
    void*   fNotifier;
>>>>>>> miniblink49
    typedef SkWindow INHERITED;
};

#endif
