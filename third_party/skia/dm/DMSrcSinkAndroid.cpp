/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "DMSrcSinkAndroid.h"
#include "DMSrcSink.h"

#include "SkAndroidSDKCanvas.h"
#include "SkCanvas.h"
#include "SkStream.h"
#include "SkiaCanvasProxy.h"
#include <utils/TestWindowContext.h>
=======
#include "DMSrcSink.h"
#include "DMSrcSinkAndroid.h"

#include "SkAndroidSDKCanvas.h"
#include "SkCanvas.h"
#include "SkHwuiRenderer.h"
#include "SkiaCanvasProxy.h"
#include "SkStream.h"
>>>>>>> miniblink49

/* These functions are only compiled in the Android Framework. */

namespace DM {

<<<<<<< HEAD
Error HWUISink::draw(const Src& src, SkBitmap* dst, SkWStream*, SkString*) const
{
    android::uirenderer::TestWindowContext renderer;
    renderer.initialize(src.size().width(), src.size().height());
=======
Error HWUISink::draw(const Src& src, SkBitmap* dst, SkWStream*, SkString*) const {
    SkHwuiRenderer renderer;
    renderer.initialize(src.size());
>>>>>>> miniblink49
    SkCanvas* canvas = renderer.prepareToDraw();
    Error err = src.draw(canvas);
    if (!err.isEmpty()) {
        return err;
    }
    renderer.finishDrawing();
<<<<<<< HEAD
    renderer.fence();
=======
    renderer.proxy->fence();
>>>>>>> miniblink49
    renderer.capturePixels(dst);
    return "";
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

<<<<<<< HEAD
ViaAndroidSDK::ViaAndroidSDK(Sink* sink)
    : fSink(sink)
{
}

Error ViaAndroidSDK::draw(const Src& src,
    SkBitmap* bitmap,
    SkWStream* stream,
    SkString* log) const
{
    struct ProxySrc : public Src {
        const Src& fSrc;
        ProxySrc(const Src& src)
            : fSrc(src)
        {
        }

        Error draw(SkCanvas* canvas) const override
        {
            // Pass through HWUI's upper layers to get operational transforms
            SkAutoTDelete<android::Canvas> ac(android::Canvas::create_canvas(canvas));
            SkAutoTUnref<android::uirenderer::SkiaCanvasProxy> scProxy(new android::uirenderer::SkiaCanvasProxy(ac));
=======
ViaAndroidSDK::ViaAndroidSDK(Sink* sink) : fSink(sink) { }

Error ViaAndroidSDK::draw(const Src& src,
                          SkBitmap* bitmap,
                          SkWStream* stream,
                          SkString* log) const {
    struct ProxySrc : public Src {
        const Src& fSrc;
        ProxySrc(const Src& src)
            : fSrc(src) {}

        Error draw(SkCanvas* canvas) const override {
            // Pass through HWUI's upper layers to get operational transforms
            SkAutoTDelete<android::Canvas> ac (android::Canvas::create_canvas(canvas));
            SkAutoTUnref<android::uirenderer::SkiaCanvasProxy> scProxy
                (new android::uirenderer::SkiaCanvasProxy(ac));
>>>>>>> miniblink49

            // Pass through another proxy to get paint transforms
            SkAndroidSDKCanvas fc;
            fc.reset(scProxy);

            fSrc.draw(&fc);

            return "";
        }
        SkISize size() const override { return fSrc.size(); }
<<<<<<< HEAD
        Name name() const override
        {
            sk_throw();
            return "";
        }
=======
        Name name() const override { sk_throw(); return ""; }
>>>>>>> miniblink49
    } proxy(src);

    return fSink->draw(proxy, bitmap, stream, log);
}

<<<<<<< HEAD
} // namespace DM
=======
}  // namespace DM
>>>>>>> miniblink49
