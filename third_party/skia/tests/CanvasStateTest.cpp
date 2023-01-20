/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "CanvasStateHelpers.h"
#include "SkCanvas.h"
#include "SkCanvasStateUtils.h"
#include "SkCommandLineFlags.h"
#include "SkDrawFilter.h"
#include "SkError.h"
#include "SkPaint.h"
#include "SkRRect.h"
#include "SkRect.h"
<<<<<<< HEAD
#include "SkTLazy.h"
=======
>>>>>>> miniblink49
#include "Test.h"

// dlopen and the library flag are only used for tests which require this flag.
#ifdef SK_SUPPORT_LEGACY_CLIPTOLAYERFLAG
#include <dlfcn.h>

DEFINE_string(library, "", "Support library to use for CanvasState test. If empty (the default), "
                           "the test will be run without crossing a library boundary. Otherwise, "
                           "it is expected to be a full path to a shared library file, which will"
                           " be dynamically loaded. Functions from the library will be called to "
                           "test SkCanvasState. Instructions for generating the library are in "
                           "gyp/canvas_state_lib.gyp");

<<<<<<< HEAD
=======

>>>>>>> miniblink49
// This class calls dlopen on the library passed in to the command line flag library, and handles
// calling dlclose when it goes out of scope.
class OpenLibResult {
public:
    // If the flag library was passed to this run of the test, attempt to open it using dlopen and
    // report whether it succeeded.
<<<<<<< HEAD
    OpenLibResult(skiatest::Reporter* reporter)
    {
        if (FLAGS_library.count() == 1) {
            fHandle = dlopen(FLAGS_library[0], RTLD_LAZY | RTLD_LOCAL);
            REPORTER_ASSERT_MESSAGE(reporter, fHandle != nullptr, "Failed to open library!");
        } else {
            fHandle = nullptr;
=======
    OpenLibResult(skiatest::Reporter* reporter) {
        if (FLAGS_library.count() == 1) {
            fHandle = dlopen(FLAGS_library[0], RTLD_LAZY | RTLD_LOCAL);
            REPORTER_ASSERT_MESSAGE(reporter, fHandle != NULL, "Failed to open library!");
        } else {
            fHandle = NULL;
>>>>>>> miniblink49
        }
    }

    // Automatically call dlclose when going out of scope.
<<<<<<< HEAD
    ~OpenLibResult()
    {
=======
    ~OpenLibResult() {
>>>>>>> miniblink49
        if (fHandle) {
            dlclose(fHandle);
        }
    }

    // Pointer to the shared library object.
    void* handle() { return fHandle; }

private:
    void* fHandle;
};

<<<<<<< HEAD
DEF_TEST(CanvasState_test_complex_layers, reporter)
{
=======
DEF_TEST(CanvasState_test_complex_layers, reporter) {
>>>>>>> miniblink49
    const int WIDTH = 400;
    const int HEIGHT = 400;
    const int SPACER = 10;

    SkRect rect = SkRect::MakeXYWH(SkIntToScalar(SPACER), SkIntToScalar(SPACER),
<<<<<<< HEAD
        SkIntToScalar(WIDTH - (2 * SPACER)),
        SkIntToScalar((HEIGHT - (2 * SPACER)) / 7));
=======
                                   SkIntToScalar(WIDTH-(2*SPACER)),
                                   SkIntToScalar((HEIGHT-(2*SPACER)) / 7));
>>>>>>> miniblink49

    const SkColorType colorTypes[] = {
        kRGB_565_SkColorType, kN32_SkColorType
    };

    const int layerAlpha[] = { 255, 255, 0 };
<<<<<<< HEAD
    const SkCanvas::SaveLayerFlags flags[] = {
        static_cast<SkCanvas::SaveLayerFlags>(SkCanvas::kDontClipToLayer_Legacy_SaveLayerFlag),
        0,
        static_cast<SkCanvas::SaveLayerFlags>(SkCanvas::kDontClipToLayer_Legacy_SaveLayerFlag),
    };
    REPORTER_ASSERT(reporter, sizeof(layerAlpha) == sizeof(flags));

    bool (*drawFn)(SkCanvasState * state, float l, float t,
        float r, float b, int32_t s);

    OpenLibResult openLibResult(reporter);
    if (openLibResult.handle() != nullptr) {
        *(void**)(&drawFn) = dlsym(openLibResult.handle(),
            "complex_layers_draw_from_canvas_state");
=======
    const SkCanvas::SaveFlags flags[] = { SkCanvas::kARGB_NoClipLayer_SaveFlag,
                                          SkCanvas::kARGB_ClipLayer_SaveFlag,
                                          SkCanvas::kARGB_NoClipLayer_SaveFlag
    };
    REPORTER_ASSERT(reporter, sizeof(layerAlpha) == sizeof(flags));

    bool (*drawFn)(SkCanvasState* state, float l, float t,
                   float r, float b, int32_t s);

    OpenLibResult openLibResult(reporter);
    if (openLibResult.handle() != NULL) {
        *(void**) (&drawFn) = dlsym(openLibResult.handle(),
                                    "complex_layers_draw_from_canvas_state");
>>>>>>> miniblink49
    } else {
        drawFn = complex_layers_draw_from_canvas_state;
    }

    REPORTER_ASSERT(reporter, drawFn);
    if (!drawFn) {
        return;
    }

    for (size_t i = 0; i < SK_ARRAY_COUNT(colorTypes); ++i) {
        SkBitmap bitmaps[2];
        for (int j = 0; j < 2; ++j) {
            bitmaps[j].allocPixels(SkImageInfo::Make(WIDTH, HEIGHT,
<<<<<<< HEAD
                colorTypes[i],
                kPremul_SkAlphaType));
=======
                                                     colorTypes[i],
                                                     kPremul_SkAlphaType));
>>>>>>> miniblink49

            SkCanvas canvas(bitmaps[j]);

            canvas.drawColor(SK_ColorRED);

            for (size_t k = 0; k < SK_ARRAY_COUNT(layerAlpha); ++k) {
<<<<<<< HEAD
                SkTLazy<SkPaint> paint;
                if (layerAlpha[k] != 0xFF) {
                    paint.init()->setAlpha(layerAlpha[k]);
                }

                // draw a rect within the layer's bounds and again outside the layer's bounds
                canvas.saveLayer(SkCanvas::SaveLayerRec(&rect, paint.getMaybeNull(), flags[k]));
=======
                // draw a rect within the layer's bounds and again outside the layer's bounds
                canvas.saveLayerAlpha(&rect, layerAlpha[k], flags[k]);
>>>>>>> miniblink49

                if (j) {
                    // Capture from the first Skia.
                    SkCanvasState* state = SkCanvasStateUtils::CaptureCanvasState(&canvas);
                    REPORTER_ASSERT(reporter, state);

                    // And draw to it in the second Skia.
                    bool success = complex_layers_draw_from_canvas_state(state,
<<<<<<< HEAD
                        rect.fLeft, rect.fTop, rect.fRight, rect.fBottom, SPACER);
=======
                            rect.fLeft, rect.fTop, rect.fRight, rect.fBottom, SPACER);
>>>>>>> miniblink49
                    REPORTER_ASSERT(reporter, success);

                    // And release it in the *first* Skia.
                    SkCanvasStateUtils::ReleaseCanvasState(state);
                } else {
                    // Draw in the first Skia.
                    complex_layers_draw(&canvas, rect.fLeft, rect.fTop,
<<<<<<< HEAD
                        rect.fRight, rect.fBottom, SPACER);
=======
                                        rect.fRight, rect.fBottom, SPACER);
>>>>>>> miniblink49
                }

                canvas.restore();

                // translate the canvas for the next iteration
<<<<<<< HEAD
                canvas.translate(0, 2 * (rect.height() + SPACER));
=======
                canvas.translate(0, 2*(rect.height() + SPACER));
>>>>>>> miniblink49
            }
        }

        // now we memcmp the two bitmaps
        REPORTER_ASSERT(reporter, bitmaps[0].getSize() == bitmaps[1].getSize());
<<<<<<< HEAD
        REPORTER_ASSERT(reporter, !memcmp(bitmaps[0].getPixels(), bitmaps[1].getPixels(), bitmaps[0].getSize()));
=======
        REPORTER_ASSERT(reporter, !memcmp(bitmaps[0].getPixels(),
                                          bitmaps[1].getPixels(),
                                          bitmaps[0].getSize()));
>>>>>>> miniblink49
    }
}
#endif

////////////////////////////////////////////////////////////////////////////////

#ifdef SK_SUPPORT_LEGACY_CLIPTOLAYERFLAG
<<<<<<< HEAD
DEF_TEST(CanvasState_test_complex_clips, reporter)
{
=======
DEF_TEST(CanvasState_test_complex_clips, reporter) {
>>>>>>> miniblink49
    const int WIDTH = 400;
    const int HEIGHT = 400;
    const int SPACER = 10;

    SkIRect layerRect = SkIRect::MakeWH(WIDTH, HEIGHT / 4);
<<<<<<< HEAD
    layerRect.inset(2 * SPACER, 2 * SPACER);

    SkIRect clipRect = layerRect;
    clipRect.fRight = clipRect.fLeft + (clipRect.width() / 2) - (2 * SPACER);
    clipRect.outset(SPACER, SPACER);

    SkIRect regionBounds = clipRect;
    regionBounds.offset(clipRect.width() + (2 * SPACER), 0);

    SkIRect regionInterior = regionBounds;
    regionInterior.inset(SPACER * 3, SPACER * 3);
=======
    layerRect.inset(2*SPACER, 2*SPACER);

    SkIRect clipRect = layerRect;
    clipRect.fRight = clipRect.fLeft + (clipRect.width() / 2) - (2*SPACER);
    clipRect.outset(SPACER, SPACER);

    SkIRect regionBounds = clipRect;
    regionBounds.offset(clipRect.width() + (2*SPACER), 0);

    SkIRect regionInterior = regionBounds;
    regionInterior.inset(SPACER*3, SPACER*3);
>>>>>>> miniblink49

    SkRegion clipRegion;
    clipRegion.setRect(regionBounds);
    clipRegion.op(regionInterior, SkRegion::kDifference_Op);

<<<<<<< HEAD
    const SkRegion::Op clipOps[] = {
        SkRegion::kIntersect_Op,
        SkRegion::kIntersect_Op,
        SkRegion::kReplace_Op,
    };
    const SkCanvas::SaveLayerFlags flags[] = {
        static_cast<SkCanvas::SaveLayerFlags>(SkCanvas::kDontClipToLayer_Legacy_SaveLayerFlag),
        0,
        static_cast<SkCanvas::SaveLayerFlags>(SkCanvas::kDontClipToLayer_Legacy_SaveLayerFlag),
    };
    REPORTER_ASSERT(reporter, sizeof(clipOps) == sizeof(flags));

    bool (*drawFn)(SkCanvasState * state, int32_t l, int32_t t,
        int32_t r, int32_t b, int32_t clipOp,
        int32_t regionRects, int32_t * rectCoords);

    OpenLibResult openLibResult(reporter);
    if (openLibResult.handle() != nullptr) {
        *(void**)(&drawFn) = dlsym(openLibResult.handle(),
            "complex_clips_draw_from_canvas_state");
=======

    const SkRegion::Op clipOps[] = { SkRegion::kIntersect_Op,
                                     SkRegion::kIntersect_Op,
                                     SkRegion::kReplace_Op,
    };
    const SkCanvas::SaveFlags flags[] = { SkCanvas::kARGB_NoClipLayer_SaveFlag,
                                          SkCanvas::kARGB_ClipLayer_SaveFlag,
                                          SkCanvas::kARGB_NoClipLayer_SaveFlag,
    };
    REPORTER_ASSERT(reporter, sizeof(clipOps) == sizeof(flags));

    bool (*drawFn)(SkCanvasState* state, int32_t l, int32_t t,
                   int32_t r, int32_t b, int32_t clipOp,
                   int32_t regionRects, int32_t* rectCoords);

    OpenLibResult openLibResult(reporter);
    if (openLibResult.handle() != NULL) {
        *(void**) (&drawFn) = dlsym(openLibResult.handle(),
                                    "complex_clips_draw_from_canvas_state");
>>>>>>> miniblink49
    } else {
        drawFn = complex_clips_draw_from_canvas_state;
    }

    REPORTER_ASSERT(reporter, drawFn);
    if (!drawFn) {
        return;
    }

    SkBitmap bitmaps[2];
    for (int i = 0; i < 2; ++i) {
        bitmaps[i].allocN32Pixels(WIDTH, HEIGHT);

        SkCanvas canvas(bitmaps[i]);

        canvas.drawColor(SK_ColorRED);

        SkRegion localRegion = clipRegion;

<<<<<<< HEAD
        SkPaint paint;
        paint.setAlpha(128);
        for (size_t j = 0; j < SK_ARRAY_COUNT(flags); ++j) {
            SkRect layerBounds = SkRect::Make(layerRect);
            canvas.saveLayer(SkCanvas::SaveLayerRec(&layerBounds, &paint, flags[j]));
=======
        for (size_t j = 0; j < SK_ARRAY_COUNT(flags); ++j) {
            SkRect layerBounds = SkRect::Make(layerRect);
            canvas.saveLayerAlpha(&layerBounds, 128, flags[j]);
>>>>>>> miniblink49

            if (i) {
                SkCanvasState* state = SkCanvasStateUtils::CaptureCanvasState(&canvas);
                REPORTER_ASSERT(reporter, state);

                SkRegion::Iterator iter(localRegion);
                SkTDArray<int32_t> rectCoords;
                for (; !iter.done(); iter.next()) {
                    const SkIRect& rect = iter.rect();
                    *rectCoords.append() = rect.fLeft;
                    *rectCoords.append() = rect.fTop;
                    *rectCoords.append() = rect.fRight;
                    *rectCoords.append() = rect.fBottom;
                }
                bool success = drawFn(state, clipRect.fLeft, clipRect.fTop,
<<<<<<< HEAD
                    clipRect.fRight, clipRect.fBottom, clipOps[j],
                    rectCoords.count() / 4, rectCoords.begin());
=======
                                      clipRect.fRight, clipRect.fBottom, clipOps[j],
                                      rectCoords.count() / 4, rectCoords.begin());
>>>>>>> miniblink49
                REPORTER_ASSERT(reporter, success);

                SkCanvasStateUtils::ReleaseCanvasState(state);
            } else {
                complex_clips_draw(&canvas, clipRect.fLeft, clipRect.fTop,
<<<<<<< HEAD
                    clipRect.fRight, clipRect.fBottom, clipOps[j],
                    localRegion);
=======
                                   clipRect.fRight, clipRect.fBottom, clipOps[j],
                                   localRegion);
>>>>>>> miniblink49
            }

            canvas.restore();

            // translate the canvas and region for the next iteration
<<<<<<< HEAD
            canvas.translate(0, SkIntToScalar(2 * (layerRect.height() + (SPACER))));
            localRegion.translate(0, 2 * (layerRect.height() + SPACER));
=======
            canvas.translate(0, SkIntToScalar(2*(layerRect.height() + (SPACER))));
            localRegion.translate(0, 2*(layerRect.height() + SPACER));
>>>>>>> miniblink49
        }
    }

    // now we memcmp the two bitmaps
    REPORTER_ASSERT(reporter, bitmaps[0].getSize() == bitmaps[1].getSize());
<<<<<<< HEAD
    REPORTER_ASSERT(reporter, !memcmp(bitmaps[0].getPixels(), bitmaps[1].getPixels(), bitmaps[0].getSize()));
=======
    REPORTER_ASSERT(reporter, !memcmp(bitmaps[0].getPixels(),
                                      bitmaps[1].getPixels(),
                                      bitmaps[0].getSize()));
>>>>>>> miniblink49
}
#endif

////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
#ifdef SK_SUPPORT_LEGACY_DRAWFILTER

=======
>>>>>>> miniblink49
class TestDrawFilter : public SkDrawFilter {
public:
    bool filter(SkPaint*, Type) override { return true; }
};

<<<<<<< HEAD
DEF_TEST(CanvasState_test_draw_filters, reporter)
{
=======
DEF_TEST(CanvasState_test_draw_filters, reporter) {
>>>>>>> miniblink49
    TestDrawFilter drawFilter;
    SkBitmap bitmap;
    bitmap.allocN32Pixels(10, 10);
    SkCanvas canvas(bitmap);

    canvas.setDrawFilter(&drawFilter);

    SkCanvasState* state = SkCanvasStateUtils::CaptureCanvasState(&canvas);
    REPORTER_ASSERT(reporter, state);
    SkCanvas* tmpCanvas = SkCanvasStateUtils::CreateFromCanvasState(state);
    REPORTER_ASSERT(reporter, tmpCanvas);

    REPORTER_ASSERT(reporter, canvas.getDrawFilter());
<<<<<<< HEAD
    REPORTER_ASSERT(reporter, nullptr == tmpCanvas->getDrawFilter());
=======
    REPORTER_ASSERT(reporter, NULL == tmpCanvas->getDrawFilter());
>>>>>>> miniblink49

    tmpCanvas->unref();
    SkCanvasStateUtils::ReleaseCanvasState(state);
}

<<<<<<< HEAD
#endif

////////////////////////////////////////////////////////////////////////////////

// we need this function to prevent SkError from printing to stdout
static void error_callback(SkError code, void* ctx) { }

DEF_TEST(CanvasState_test_soft_clips, reporter)
{
=======
////////////////////////////////////////////////////////////////////////////////

// we need this function to prevent SkError from printing to stdout
static void error_callback(SkError code, void* ctx) {}

DEF_TEST(CanvasState_test_soft_clips, reporter) {
>>>>>>> miniblink49
    SkBitmap bitmap;
    bitmap.allocN32Pixels(10, 10);
    SkCanvas canvas(bitmap);

    SkRRect roundRect;
    roundRect.setOval(SkRect::MakeWH(5, 5));

    canvas.clipRRect(roundRect, SkRegion::kIntersect_Op, true);

<<<<<<< HEAD
    SkSetErrorCallback(error_callback, nullptr);
=======
    SkSetErrorCallback(error_callback, NULL);
>>>>>>> miniblink49

    SkCanvasState* state = SkCanvasStateUtils::CaptureCanvasState(&canvas);
    REPORTER_ASSERT(reporter, !state);

    REPORTER_ASSERT(reporter, kInvalidOperation_SkError == SkGetLastError());
    SkClearLastError();
}

#ifdef SK_SUPPORT_LEGACY_CLIPTOLAYERFLAG
<<<<<<< HEAD
#include "SkClipStack.h"
DEF_TEST(CanvasState_test_saveLayer_clip, reporter)
{
=======
DEF_TEST(CanvasState_test_saveLayer_clip, reporter) {
>>>>>>> miniblink49
    const int WIDTH = 100;
    const int HEIGHT = 100;
    const int LAYER_WIDTH = 50;
    const int LAYER_HEIGHT = 50;

    SkBitmap bitmap;
    bitmap.allocN32Pixels(WIDTH, HEIGHT);
    SkCanvas canvas(bitmap);

    SkRect bounds = SkRect::MakeWH(SkIntToScalar(LAYER_WIDTH), SkIntToScalar(LAYER_HEIGHT));
    canvas.clipRect(SkRect::MakeWH(SkIntToScalar(WIDTH), SkIntToScalar(HEIGHT)));

    // Check that saveLayer without the kClipToLayer_SaveFlag leaves the
    // clip stack unchanged.
<<<<<<< HEAD
    canvas.saveLayer(SkCanvas::SaveLayerRec(&bounds,
        nullptr,
        SkCanvas::kDontClipToLayer_Legacy_SaveLayerFlag));
    SkRect clipStackBounds;
    SkClipStack::BoundsType boundsType;
    canvas.getClipStack()->getBounds(&clipStackBounds, &boundsType);
    // The clip stack will return its bounds, or it may be "full" : i.e. empty + inside_out.
    // Either result is consistent with this test, since the canvas' size is WIDTH/HEIGHT
    if (SkClipStack::kInsideOut_BoundsType == boundsType) {
        REPORTER_ASSERT(reporter, clipStackBounds.isEmpty());
    } else {
        REPORTER_ASSERT(reporter, clipStackBounds.width() == WIDTH);
        REPORTER_ASSERT(reporter, clipStackBounds.height() == HEIGHT);
    }
=======
    canvas.saveLayer(&bounds, NULL, SkCanvas::kARGB_NoClipLayer_SaveFlag);
    SkRect clipStackBounds;
    SkClipStack::BoundsType boundsType;
    canvas.getClipStack()->getBounds(&clipStackBounds, &boundsType);
    REPORTER_ASSERT(reporter, clipStackBounds.width() == WIDTH);
    REPORTER_ASSERT(reporter, clipStackBounds.height() == HEIGHT);
>>>>>>> miniblink49
    canvas.restore();

    // Check that saveLayer with the kClipToLayer_SaveFlag sets the clip
    // stack to the layer bounds.
<<<<<<< HEAD
    canvas.saveLayer(&bounds, nullptr);
=======
    canvas.saveLayer(&bounds, NULL, SkCanvas::kARGB_ClipLayer_SaveFlag);
>>>>>>> miniblink49
    canvas.getClipStack()->getBounds(&clipStackBounds, &boundsType);
    REPORTER_ASSERT(reporter, clipStackBounds.width() == LAYER_WIDTH);
    REPORTER_ASSERT(reporter, clipStackBounds.height() == LAYER_HEIGHT);

    canvas.restore();
}
#endif
