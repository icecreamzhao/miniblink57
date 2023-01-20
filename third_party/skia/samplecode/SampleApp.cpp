/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SampleApp.h"

#include "OverView.h"
#include "Resources.h"
#include "SampleCode.h"
<<<<<<< HEAD
=======
#include "SamplePipeControllers.h"
>>>>>>> miniblink49
#include "SkAnimTimer.h"
#include "SkCanvas.h"
#include "SkCommandLineFlags.h"
#include "SkData.h"
<<<<<<< HEAD
#include "SkDocument.h"
#include "SkGraphics.h"
#include "SkImageEncoder.h"
#include "SkImage_Base.h"
#include "SkOSFile.h"
#include "SkPM4fPriv.h"
=======
#include "SkDeferredCanvas.h"
#include "SkDevice.h"
#include "SkDocument.h"
#include "SkGPipe.h"
#include "SkGraphics.h"
#include "SkImageEncoder.h"
#include "SkOSFile.h"
>>>>>>> miniblink49
#include "SkPaint.h"
#include "SkPaintFilterCanvas.h"
#include "SkPicture.h"
#include "SkPictureRecorder.h"
#include "SkStream.h"
#include "SkSurface.h"
#include "SkTSort.h"
<<<<<<< HEAD
#include "SkTemplates.h"
=======
>>>>>>> miniblink49
#include "SkTime.h"
#include "SkTypeface.h"
#include "SkWindow.h"
#include "sk_tool_utils.h"

#if SK_SUPPORT_GPU
<<<<<<< HEAD
#include "GrContext.h"
#include "GrRenderTarget.h"
#include "SkGr.h"
#include "gl/GrGLInterface.h"
#include "gl/GrGLUtil.h"
#if SK_ANGLE
#include "gl/angle/GLTestContext_angle.h"
#endif
=======
#include "gl/GrGLInterface.h"
#include "gl/GrGLUtil.h"
#include "GrRenderTarget.h"
#include "GrContext.h"
#include "SkGpuDevice.h"
>>>>>>> miniblink49
#else
class GrContext;
#endif

<<<<<<< HEAD
const struct {
    SkColorType fColorType;
    bool fSRGB;
    const char* fName;
} gConfig[] = {
    { kN32_SkColorType, false, "L32" },
    { kN32_SkColorType, true, "S32" },
    { kRGBA_F16_SkColorType, false, "F16" },
};

static const char* find_config_name(const SkImageInfo& info)
{
    for (const auto& config : gConfig) {
        if (config.fColorType == info.colorType() && config.fSRGB == (info.colorSpace() != nullptr)) {
            return config.fName;
        }
    }
    return "???";
}

// Should be 3x + 1
#define kMaxFatBitsScale 28

=======
>>>>>>> miniblink49
extern SampleView* CreateSamplePictFileView(const char filename[]);

class PictFileFactory : public SkViewFactory {
    SkString fFilename;
<<<<<<< HEAD

public:
    PictFileFactory(const SkString& filename)
        : fFilename(filename)
    {
    }
    SkView* operator()() const override
    {
=======
public:
    PictFileFactory(const SkString& filename) : fFilename(filename) {}
    SkView* operator() () const override {
>>>>>>> miniblink49
        return CreateSamplePictFileView(fFilename.c_str());
    }
};

#ifdef SAMPLE_PDF_FILE_VIEWER
extern SampleView* CreateSamplePdfFileViewer(const char filename[]);

class PdfFileViewerFactory : public SkViewFactory {
    SkString fFilename;
<<<<<<< HEAD

public:
    PdfFileViewerFactory(const SkString& filename)
        : fFilename(filename)
    {
    }
    SkView* operator()() const override
    {
        return CreateSamplePdfFileViewer(fFilename.c_str());
    }
};
#endif // SAMPLE_PDF_FILE_VIEWER
=======
public:
    PdfFileViewerFactory(const SkString& filename) : fFilename(filename) {}
    SkView* operator() () const override {
        return CreateSamplePdfFileViewer(fFilename.c_str());
    }
};
#endif  // SAMPLE_PDF_FILE_VIEWER

#define PIPE_FILEx
#ifdef  PIPE_FILE
#define FILE_PATH "/path/to/drawing.data"
#endif

#define PIPE_NETx
#ifdef  PIPE_NET
#include "SkSockets.h"
SkTCPServer gServer;
#endif
>>>>>>> miniblink49

#if SK_ANGLE
//#define DEFAULT_TO_ANGLE 1
#else
#define DEFAULT_TO_GPU 0 // if 1 default rendering is on GPU
#endif

#define ANIMATING_EVENTTYPE "nextSample"
<<<<<<< HEAD
#define ANIMATING_DELAY 250

#ifdef SK_DEBUG
#define FPS_REPEAT_MULTIPLIER 1
#else
#define FPS_REPEAT_MULTIPLIER 10
#endif
#define FPS_REPEAT_COUNT (10 * FPS_REPEAT_MULTIPLIER)
=======
#define ANIMATING_DELAY     250

#ifdef SK_DEBUG
    #define FPS_REPEAT_MULTIPLIER   1
#else
    #define FPS_REPEAT_MULTIPLIER   10
#endif
#define FPS_REPEAT_COUNT    (10 * FPS_REPEAT_MULTIPLIER)
>>>>>>> miniblink49

static SampleWindow* gSampleWindow;

static bool gShowGMBounds;

<<<<<<< HEAD
static void post_event_to_sink(SkEvent* evt, SkEventSink* sink)
{
=======
static void post_event_to_sink(SkEvent* evt, SkEventSink* sink) {
>>>>>>> miniblink49
    evt->setTargetID(sink->getSinkID())->post();
}

static SkAnimTimer gAnimTimer;

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static const char* skip_until(const char* str, const char* skip)
{
    if (!str) {
        return nullptr;
=======
static const char* skip_until(const char* str, const char* skip) {
    if (!str) {
        return NULL;
>>>>>>> miniblink49
    }
    return strstr(str, skip);
}

<<<<<<< HEAD
static const char* skip_past(const char* str, const char* skip)
{
    const char* found = skip_until(str, skip);
    if (!found) {
        return nullptr;
=======
static const char* skip_past(const char* str, const char* skip) {
    const char* found = skip_until(str, skip);
    if (!found) {
        return NULL;
>>>>>>> miniblink49
    }
    return found + strlen(skip);
}

static const char* gPrefFileName = "sampleapp_prefs.txt";

<<<<<<< HEAD
static bool readTitleFromPrefs(SkString* title)
{
=======
static bool readTitleFromPrefs(SkString* title) {
>>>>>>> miniblink49
    SkFILEStream stream(gPrefFileName);
    if (!stream.isValid()) {
        return false;
    }

    size_t len = stream.getLength();
    SkString data(len);
    stream.read(data.writable_str(), len);
    const char* s = data.c_str();

    s = skip_past(s, "curr-slide-title");
    s = skip_past(s, "=");
    s = skip_past(s, "\"");
    const char* stop = skip_until(s, "\"");
    if (stop > s) {
        title->set(s, stop - s);
        return true;
    }
    return false;
}

<<<<<<< HEAD
static void writeTitleToPrefs(const char* title)
{
=======
static void writeTitleToPrefs(const char* title) {
>>>>>>> miniblink49
    SkFILEWStream stream(gPrefFileName);
    SkString data;
    data.printf("curr-slide-title = \"%s\"\n", title);
    stream.write(data.c_str(), data.size());
}

///////////////////////////////////////////////////////////////////////////////

class SampleWindow::DefaultDeviceManager : public SampleWindow::DeviceManager {
public:
<<<<<<< HEAD
    DefaultDeviceManager()
    {
#if SK_SUPPORT_GPU
        fCurContext = nullptr;
        fCurIntf = nullptr;
        fCurRenderTarget = nullptr;
        fMSAASampleCount = 0;
        fDeepColor = false;
        fActualColorBits = 0;
=======

    DefaultDeviceManager() {
#if SK_SUPPORT_GPU
        fCurContext = NULL;
        fCurIntf = NULL;
        fCurRenderTarget = NULL;
        fMSAASampleCount = 0;
>>>>>>> miniblink49
#endif
        fBackend = kNone_BackEndType;
    }

<<<<<<< HEAD
    virtual ~DefaultDeviceManager()
    {
=======
    virtual ~DefaultDeviceManager() {
>>>>>>> miniblink49
#if SK_SUPPORT_GPU
        SkSafeUnref(fCurContext);
        SkSafeUnref(fCurIntf);
        SkSafeUnref(fCurRenderTarget);
#endif
    }

<<<<<<< HEAD
    void setUpBackend(SampleWindow* win, int msaaSampleCount, bool deepColor) override
    {
=======
    virtual void setUpBackend(SampleWindow* win, int msaaSampleCount) {
>>>>>>> miniblink49
        SkASSERT(kNone_BackEndType == fBackend);

        fBackend = kNone_BackEndType;

#if SK_SUPPORT_GPU
        switch (win->getDeviceType()) {
<<<<<<< HEAD
        case kRaster_DeviceType: // fallthrough
        case kGPU_DeviceType:
            // all these guys use the native backend
            fBackend = kNativeGL_BackEndType;
            break;
#if SK_ANGLE
        case kANGLE_DeviceType:
            // ANGLE is really the only odd man out
            fBackend = kANGLE_BackEndType;
            break;
#endif // SK_ANGLE
        default:
            SkASSERT(false);
            break;
        }
        AttachmentInfo attachmentInfo;
        bool result = win->attach(fBackend, msaaSampleCount, deepColor, &attachmentInfo);
=======
            case kRaster_DeviceType:    // fallthrough
            case kPicture_DeviceType:    // fallthrough
            case kDeferred_DeviceType:    // fallthrough
            case kGPU_DeviceType:
                // all these guys use the native backend
                fBackend = kNativeGL_BackEndType;
                break;
#if SK_ANGLE
            case kANGLE_DeviceType:
                // ANGLE is really the only odd man out
                fBackend = kANGLE_BackEndType;
                break;
#endif // SK_ANGLE
            default:
                SkASSERT(false);
                break;
        }
        AttachmentInfo attachmentInfo;
        bool result = win->attach(fBackend, msaaSampleCount, &attachmentInfo);
>>>>>>> miniblink49
        if (!result) {
            SkDebugf("Failed to initialize GL");
            return;
        }
        fMSAASampleCount = msaaSampleCount;
<<<<<<< HEAD
        fDeepColor = deepColor;
        // Assume that we have at least 24-bit output, for backends that don't supply this data
        fActualColorBits = SkTMax(attachmentInfo.fColorBits, 24);

        SkASSERT(nullptr == fCurIntf);
        SkAutoTUnref<const GrGLInterface> glInterface;
        switch (win->getDeviceType()) {
        case kRaster_DeviceType: // fallthrough
        case kGPU_DeviceType:
            // all these guys use the native interface
            glInterface.reset(GrGLCreateNativeInterface());
            break;
#if SK_ANGLE
        case kANGLE_DeviceType:
            glInterface.reset(sk_gpu_test::CreateANGLEGLInterface());
            break;
#endif // SK_ANGLE
        default:
            SkASSERT(false);
            break;
=======

        SkASSERT(NULL == fCurIntf);
        SkAutoTUnref<const GrGLInterface> glInterface;
        switch (win->getDeviceType()) {
            case kRaster_DeviceType:    // fallthrough
            case kPicture_DeviceType:   // fallthrough
            case kDeferred_DeviceType:  // fallthrough
            case kGPU_DeviceType:
                // all these guys use the native interface
                glInterface.reset(GrGLCreateNativeInterface());
                break;
#if SK_ANGLE
            case kANGLE_DeviceType:
                glInterface.reset(GrGLCreateANGLEInterface());
                break;
#endif // SK_ANGLE
            default:
                SkASSERT(false);
                break;
>>>>>>> miniblink49
        }

        // Currently SampleApp does not use NVPR. TODO: Provide an NVPR device type that is skipped
        // when the driver doesn't support NVPR.
        fCurIntf = GrGLInterfaceRemoveNVPR(glInterface.get());

<<<<<<< HEAD
        SkASSERT(nullptr == fCurContext);
        fCurContext = GrContext::Create(kOpenGL_GrBackend, (GrBackendContext)fCurIntf);

        if (nullptr == fCurContext || nullptr == fCurIntf) {
            // We need some context and interface to see results
            SkSafeUnref(fCurContext);
            SkSafeUnref(fCurIntf);
            fCurContext = nullptr;
            fCurIntf = nullptr;
            SkDebugf("Failed to setup 3D");

            win->release();
        }
#endif // SK_SUPPORT_GPU \
    // call windowSizeChanged to create the render target
        this->windowSizeChanged(win);
    }

    void tearDownBackend(SampleWindow* win) override
    {
=======
        SkASSERT(NULL == fCurContext);
        fCurContext = GrContext::Create(kOpenGL_GrBackend, (GrBackendContext) fCurIntf);

        if (NULL == fCurContext || NULL == fCurIntf) {
            // We need some context and interface to see results
            SkSafeUnref(fCurContext);
            SkSafeUnref(fCurIntf);
            fCurContext = NULL;
            fCurIntf = NULL;
            SkDebugf("Failed to setup 3D");

            win->detach();
        }
#endif // SK_SUPPORT_GPU
        // call windowSizeChanged to create the render target
        this->windowSizeChanged(win);
    }

    virtual void tearDownBackend(SampleWindow *win) {
>>>>>>> miniblink49
#if SK_SUPPORT_GPU
        if (fCurContext) {
            // in case we have outstanding refs to this guy (lua?)
            fCurContext->abandonContext();
            fCurContext->unref();
<<<<<<< HEAD
            fCurContext = nullptr;
        }

        SkSafeUnref(fCurIntf);
        fCurIntf = nullptr;

        SkSafeUnref(fCurRenderTarget);
        fCurRenderTarget = nullptr;
#endif
        win->release();
        fBackend = kNone_BackEndType;
    }

    SkSurface* createSurface(SampleWindow::DeviceType dType, SampleWindow* win) override
    {
#if SK_SUPPORT_GPU
        if (IsGpuDeviceType(dType) && fCurContext) {
            SkSurfaceProps props(win->getSurfaceProps());
            if (kRGBA_F16_SkColorType == win->info().colorType() || fActualColorBits > 24) {
                // If we're rendering to F16, we need an off-screen surface - the current render
                // target is most likely the wrong format.
                //
                // If we're using a deep (10-bit or higher) surface, we probably need an off-screen
                // surface. 10-bit, in particular, has strange gamma behavior.
                return SkSurface::MakeRenderTarget(fCurContext, SkBudgeted::kNo, win->info(),
                    fMSAASampleCount, &props)
                    .release();
            } else {
                return SkSurface::MakeRenderTargetDirect(fCurRenderTarget, &props).release();
            }
        }
#endif
        return nullptr;
    }

    void publishCanvas(SampleWindow::DeviceType dType,
        SkCanvas* canvas, SampleWindow* win) override
    {
=======
            fCurContext = NULL;
        }

        SkSafeUnref(fCurIntf);
        fCurIntf = NULL;

        SkSafeUnref(fCurRenderTarget);
        fCurRenderTarget = NULL;
#endif
        win->detach();
        fBackend = kNone_BackEndType;
    }

    virtual SkSurface* createSurface(SampleWindow::DeviceType dType,
                                     SampleWindow* win) override {
#if SK_SUPPORT_GPU
        if (IsGpuDeviceType(dType) && fCurContext) {
            SkSurfaceProps props(win->getSurfaceProps());
            return SkSurface::NewRenderTargetDirect(fCurRenderTarget, &props);
        }
#endif
        return NULL;
    }

    virtual void publishCanvas(SampleWindow::DeviceType dType,
                               SkCanvas* canvas,
                               SampleWindow* win) {
>>>>>>> miniblink49
#if SK_SUPPORT_GPU
        if (fCurContext) {
            // in case we have queued drawing calls
            fCurContext->flush();
<<<<<<< HEAD
        }

        if (!IsGpuDeviceType(dType) || kRGBA_F16_SkColorType == win->info().colorType() || fActualColorBits > 24) {
            // We made/have an off-screen surface. Get the contents as an SkImage:
            SkBitmap bm;
            bm.allocPixels(win->info());
            canvas->readPixels(&bm, 0, 0);
            SkPixmap pm;
            bm.peekPixels(&pm);
            sk_sp<SkImage> image(SkImage::MakeTextureFromPixmap(fCurContext, pm,
                SkBudgeted::kNo));
            GrTexture* texture = as_IB(image)->peekTexture();
            SkASSERT(texture);

            // With ten-bit output, we need to manually apply the gamma of the output device
            // (unless we're in non-gamma correct mode, in which case our data is already
            // fake-sRGB, like we're expected to put in the 10-bit buffer):
            bool doGamma = (fActualColorBits == 30) && SkImageInfoIsGammaCorrect(win->info());
            fCurContext->applyGamma(fCurRenderTarget, texture, doGamma ? 1.0f / 2.2f : 1.0f);
=======

            if (!IsGpuDeviceType(dType)) {
                // need to send the raster bits to the (gpu) window
                const SkBitmap& bm = win->getBitmap();
                fCurRenderTarget->writePixels(0, 0, bm.width(), bm.height(),
                                             SkImageInfo2GrPixelConfig(bm.colorType(),
                                                                       bm.alphaType(),
                                                                       bm.profileType()),
                                             bm.getPixels(),
                                             bm.rowBytes(),
                                             GrContext::kFlushWrites_PixelOp);
            }
>>>>>>> miniblink49
        }
#endif

        win->present();
    }

<<<<<<< HEAD
    void windowSizeChanged(SampleWindow* win) override
    {
#if SK_SUPPORT_GPU
        if (fCurContext) {
            AttachmentInfo attachmentInfo;
            win->attach(fBackend, fMSAASampleCount, fDeepColor, &attachmentInfo);
            SkSafeUnref(fCurRenderTarget);
            fActualColorBits = SkTMax(attachmentInfo.fColorBits, 24);
=======
    virtual void windowSizeChanged(SampleWindow* win) {
#if SK_SUPPORT_GPU
        if (fCurContext) {
            AttachmentInfo attachmentInfo;
            win->attach(fBackend, fMSAASampleCount, &attachmentInfo);
            SkSafeUnref(fCurRenderTarget);
>>>>>>> miniblink49
            fCurRenderTarget = win->renderTarget(attachmentInfo, fCurIntf, fCurContext);
        }
#endif
    }

<<<<<<< HEAD
    GrContext* getGrContext() override
    {
#if SK_SUPPORT_GPU
        return fCurContext;
#else
        return nullptr;
#endif
    }

    GrRenderTarget* getGrRenderTarget() override
    {
#if SK_SUPPORT_GPU
        return fCurRenderTarget;
#else
        return nullptr;
#endif
    }

    int getColorBits() override
    {
#if SK_SUPPORT_GPU
        return fActualColorBits;
#else
        return 24;
=======
    virtual GrContext* getGrContext() {
#if SK_SUPPORT_GPU
        return fCurContext;
#else
        return NULL;
#endif
    }

    GrRenderTarget* getGrRenderTarget() override {
#if SK_SUPPORT_GPU
        return fCurRenderTarget;
#else
        return NULL;
>>>>>>> miniblink49
#endif
    }

private:
<<<<<<< HEAD
#if SK_SUPPORT_GPU
    GrContext* fCurContext;
    const GrGLInterface* fCurIntf;
    GrRenderTarget* fCurRenderTarget;
    int fMSAASampleCount;
    bool fDeepColor;
    int fActualColorBits;
=======

#if SK_SUPPORT_GPU
    GrContext*              fCurContext;
    const GrGLInterface*    fCurIntf;
    GrRenderTarget*         fCurRenderTarget;
    int fMSAASampleCount;
>>>>>>> miniblink49
#endif

    SkOSWindow::SkBackEndTypes fBackend;

    typedef SampleWindow::DeviceManager INHERITED;
};

///////////////
static const char view_inval_msg[] = "view-inval-msg";

<<<<<<< HEAD
void SampleWindow::postInvalDelay()
{
    (new SkEvent(view_inval_msg, this->getSinkID()))->postDelay(1);
}

static bool isInvalEvent(const SkEvent& evt)
{
=======
void SampleWindow::postInvalDelay() {
    (new SkEvent(view_inval_msg, this->getSinkID()))->postDelay(1);
}

static bool isInvalEvent(const SkEvent& evt) {
>>>>>>> miniblink49
    return evt.isType(view_inval_msg);
}
//////////////////

<<<<<<< HEAD
#include "GMSampleView.h"

class AutoUnrefArray {
public:
    AutoUnrefArray() { }
    ~AutoUnrefArray()
    {
=======
SkFuncViewFactory::SkFuncViewFactory(SkViewCreateFunc func)
    : fCreateFunc(func) {
}

SkView* SkFuncViewFactory::operator() () const {
    return (*fCreateFunc)();
}

#include "GMSampleView.h"

SkGMSampleViewFactory::SkGMSampleViewFactory(GMFactoryFunc func)
    : fFunc(func) {
}

SkView* SkGMSampleViewFactory::operator() () const {
    skiagm::GM* gm = fFunc(NULL);
    gm->setMode(skiagm::GM::kSample_Mode);
    return new GMSampleView(gm);
}

SkViewRegister* SkViewRegister::gHead;
SkViewRegister::SkViewRegister(SkViewFactory* fact) : fFact(fact) {
    fFact->ref();
    fChain = gHead;
    gHead = this;
}

SkViewRegister::SkViewRegister(SkViewCreateFunc func) {
    fFact = new SkFuncViewFactory(func);
    fChain = gHead;
    gHead = this;
}

SkViewRegister::SkViewRegister(GMFactoryFunc func) {
    fFact = new SkGMSampleViewFactory(func);
    fChain = gHead;
    gHead = this;
}

class AutoUnrefArray {
public:
    AutoUnrefArray() {}
    ~AutoUnrefArray() {
>>>>>>> miniblink49
        int count = fObjs.count();
        for (int i = 0; i < count; ++i) {
            fObjs[i]->unref();
        }
    }
    SkRefCnt*& push_back() { return *fObjs.append(); }

private:
    SkTDArray<SkRefCnt*> fObjs;
};

// registers GMs as Samples
// This can't be performed during static initialization because it could be
// run before GMRegistry has been fully built.
<<<<<<< HEAD
static void SkGMRegistyToSampleRegistry()
{
=======
static void SkGMRegistyToSampleRegistry() {
>>>>>>> miniblink49
    static bool gOnce;
    static AutoUnrefArray fRegisters;

    if (!gOnce) {
        const skiagm::GMRegistry* gmreg = skiagm::GMRegistry::Head();
        while (gmreg) {
            fRegisters.push_back() = new SkViewRegister(gmreg->factory());
            gmreg = gmreg->next();
        }
        gOnce = true;
    }
}

//////////////////////////////////////////////////////////////////////////////

enum FlipAxisEnum {
    kFlipAxis_X = (1 << 0),
    kFlipAxis_Y = (1 << 1)
};

#include "SkDrawFilter.h"

struct HintingState {
    SkPaint::Hinting hinting;
    const char* name;
    const char* label;
};
static HintingState gHintingStates[] = {
<<<<<<< HEAD
    { SkPaint::kNo_Hinting, "Mixed", nullptr },
    { SkPaint::kNo_Hinting, "None", "H0 " },
    { SkPaint::kSlight_Hinting, "Slight", "Hs " },
    { SkPaint::kNormal_Hinting, "Normal", "Hn " },
    { SkPaint::kFull_Hinting, "Full", "Hf " },
};

struct PixelGeometryState {
    SkPixelGeometry pixelGeometry;
    const char* name;
    const char* label;
};
static PixelGeometryState gPixelGeometryStates[] = {
    { SkPixelGeometry::kUnknown_SkPixelGeometry, "Mixed", nullptr },
    { SkPixelGeometry::kUnknown_SkPixelGeometry, "Flat", "{Flat} " },
    { SkPixelGeometry::kRGB_H_SkPixelGeometry, "RGB H", "{RGB H} " },
    { SkPixelGeometry::kBGR_H_SkPixelGeometry, "BGR H", "{BGR H} " },
    { SkPixelGeometry::kRGB_V_SkPixelGeometry, "RGB_V", "{RGB V} " },
    { SkPixelGeometry::kBGR_V_SkPixelGeometry, "BGR_V", "{BGR V} " },
=======
    {SkPaint::kNo_Hinting, "Mixed", NULL },
    {SkPaint::kNo_Hinting, "None", "H0 " },
    {SkPaint::kSlight_Hinting, "Slight", "Hs " },
    {SkPaint::kNormal_Hinting, "Normal", "Hn " },
    {SkPaint::kFull_Hinting, "Full", "Hf " },
>>>>>>> miniblink49
};

struct FilterQualityState {
    SkFilterQuality fQuality;
<<<<<<< HEAD
    const char* fName;
    const char* fLabel;
};
static FilterQualityState gFilterQualityStates[] = {
    { kNone_SkFilterQuality, "Mixed", nullptr },
    { kNone_SkFilterQuality, "None", "F0 " },
    { kLow_SkFilterQuality, "Low", "F1 " },
    { kMedium_SkFilterQuality, "Medium", "F2 " },
    { kHigh_SkFilterQuality, "High", "F3 " },
=======
    const char*     fName;
    const char*     fLabel;
};
static FilterQualityState gFilterQualityStates[] = {
    { kNone_SkFilterQuality,   "Mixed",    NULL    },
    { kNone_SkFilterQuality,   "None",     "F0 "   },
    { kLow_SkFilterQuality,    "Low",      "F1 "   },
    { kMedium_SkFilterQuality, "Medium",   "F2 "   },
    { kHigh_SkFilterQuality,   "High",     "F3 "   },
>>>>>>> miniblink49
};

class FlagsFilterCanvas : public SkPaintFilterCanvas {
public:
    FlagsFilterCanvas(SkCanvas* canvas, SkOSMenu::TriState lcd, SkOSMenu::TriState aa,
<<<<<<< HEAD
        SkOSMenu::TriState subpixel, int hinting, int filterQuality)
        : INHERITED(canvas)
=======
                      SkOSMenu::TriState subpixel, int hinting, int filterQuality)
        : INHERITED(canvas->imageInfo().width(), canvas->imageInfo().height())
>>>>>>> miniblink49
        , fLCDState(lcd)
        , fAAState(aa)
        , fSubpixelState(subpixel)
        , fHintingState(hinting)
<<<<<<< HEAD
        , fFilterQualityIndex(filterQuality)
    {
        SkASSERT((unsigned)filterQuality < SK_ARRAY_COUNT(gFilterQualityStates));
    }

protected:
    bool onFilter(SkTCopyOnFirstWrite<SkPaint>* paint, Type t) const override
    {
        if (!*paint) {
            return true;
        }

        if (kText_Type == t && SkOSMenu::kMixedState != fLCDState) {
            paint->writable()->setLCDRenderText(SkOSMenu::kOnState == fLCDState);
        }
        if (SkOSMenu::kMixedState != fAAState) {
            paint->writable()->setAntiAlias(SkOSMenu::kOnState == fAAState);
        }
        if (0 != fFilterQualityIndex) {
            paint->writable()->setFilterQuality(gFilterQualityStates[fFilterQualityIndex].fQuality);
        }
        if (SkOSMenu::kMixedState != fSubpixelState) {
            paint->writable()->setSubpixelText(SkOSMenu::kOnState == fSubpixelState);
        }
        if (0 != fHintingState && fHintingState < (int)SK_ARRAY_COUNT(gHintingStates)) {
            paint->writable()->setHinting(gHintingStates[fHintingState].hinting);
        }
        return true;
    }

private:
    SkOSMenu::TriState fLCDState;
    SkOSMenu::TriState fAAState;
    SkOSMenu::TriState fSubpixelState;
=======
        , fFilterQualityIndex(filterQuality) {
        SkASSERT((unsigned)filterQuality < SK_ARRAY_COUNT(gFilterQualityStates));

        this->addCanvas(canvas);
    }

protected:
    void onFilterPaint(SkPaint* paint, Type t) const override {
        if (kText_Type == t && SkOSMenu::kMixedState != fLCDState) {
            paint->setLCDRenderText(SkOSMenu::kOnState == fLCDState);
        }
        if (SkOSMenu::kMixedState != fAAState) {
            paint->setAntiAlias(SkOSMenu::kOnState == fAAState);
        }
        if (0 != fFilterQualityIndex) {
            paint->setFilterQuality(gFilterQualityStates[fFilterQualityIndex].fQuality);
        }
        if (SkOSMenu::kMixedState != fSubpixelState) {
            paint->setSubpixelText(SkOSMenu::kOnState == fSubpixelState);
        }
        if (0 != fHintingState && fHintingState < (int)SK_ARRAY_COUNT(gHintingStates)) {
            paint->setHinting(gHintingStates[fHintingState].hinting);
        }
    }

private:
    SkOSMenu::TriState  fLCDState;
    SkOSMenu::TriState  fAAState;
    SkOSMenu::TriState  fSubpixelState;
>>>>>>> miniblink49
    int fHintingState;
    int fFilterQualityIndex;

    typedef SkPaintFilterCanvas INHERITED;
};

<<<<<<< HEAD
=======
//////////////////////////////////////////////////////////////////////////////

#define MAX_ZOOM_LEVEL  8
#define MIN_ZOOM_LEVEL  -8

static const char gCharEvtName[] = "SampleCode_Char_Event";
static const char gKeyEvtName[] = "SampleCode_Key_Event";
static const char gTitleEvtName[] = "SampleCode_Title_Event";
static const char gPrefSizeEvtName[] = "SampleCode_PrefSize_Event";
static const char gFastTextEvtName[] = "SampleCode_FastText_Event";
static const char gUpdateWindowTitleEvtName[] = "SampleCode_UpdateWindowTitle";

bool SampleCode::CharQ(const SkEvent& evt, SkUnichar* outUni) {
    if (evt.isType(gCharEvtName, sizeof(gCharEvtName) - 1)) {
        if (outUni) {
            *outUni = evt.getFast32();
        }
        return true;
    }
    return false;
}

bool SampleCode::KeyQ(const SkEvent& evt, SkKey* outKey) {
    if (evt.isType(gKeyEvtName, sizeof(gKeyEvtName) - 1)) {
        if (outKey) {
            *outKey = (SkKey)evt.getFast32();
        }
        return true;
    }
    return false;
}

bool SampleCode::TitleQ(const SkEvent& evt) {
    return evt.isType(gTitleEvtName, sizeof(gTitleEvtName) - 1);
}

void SampleCode::TitleR(SkEvent* evt, const char title[]) {
    SkASSERT(evt && TitleQ(*evt));
    evt->setString(gTitleEvtName, title);
}

bool SampleCode::RequestTitle(SkView* view, SkString* title) {
    SkEvent evt(gTitleEvtName);
    if (view->doQuery(&evt)) {
        title->set(evt.findString(gTitleEvtName));
        return true;
    }
    return false;
}

bool SampleCode::PrefSizeQ(const SkEvent& evt) {
    return evt.isType(gPrefSizeEvtName, sizeof(gPrefSizeEvtName) - 1);
}

void SampleCode::PrefSizeR(SkEvent* evt, SkScalar width, SkScalar height) {
    SkASSERT(evt && PrefSizeQ(*evt));
    SkScalar size[2];
    size[0] = width;
    size[1] = height;
    evt->setScalars(gPrefSizeEvtName, 2, size);
}

bool SampleCode::FastTextQ(const SkEvent& evt) {
    return evt.isType(gFastTextEvtName, sizeof(gFastTextEvtName) - 1);
}

>>>>>>> miniblink49
///////////////////////////////////////////////////////////////////////////////

enum TilingMode {
    kNo_Tiling,
    kAbs_128x128_Tiling,
    kAbs_256x256_Tiling,
    kRel_4x4_Tiling,
    kRel_1x16_Tiling,
    kRel_16x1_Tiling,

    kLast_TilingMode_Enum
};

struct TilingInfo {
    const char* label;
<<<<<<< HEAD
    SkScalar w, h;
};

static const struct TilingInfo gTilingInfo[] = {
    { "No tiling", SK_Scalar1, SK_Scalar1 }, // kNo_Tiling
    { "128x128", SkIntToScalar(128), SkIntToScalar(128) }, // kAbs_128x128_Tiling
    { "256x256", SkIntToScalar(256), SkIntToScalar(256) }, // kAbs_256x256_Tiling
    { "1/4x1/4", SK_Scalar1 / 4, SK_Scalar1 / 4 }, // kRel_4x4_Tiling
    { "1/1x1/16", SK_Scalar1, SK_Scalar1 / 16 }, // kRel_1x16_Tiling
    { "1/16x1/1", SK_Scalar1 / 16, SK_Scalar1 }, // kRel_16x1_Tiling
};
static_assert((SK_ARRAY_COUNT(gTilingInfo) == kLast_TilingMode_Enum),
    "Incomplete_tiling_labels");

SkSize SampleWindow::tileSize() const
{
    SkASSERT((TilingMode)fTilingMode < kLast_TilingMode_Enum);
    const struct TilingInfo* info = gTilingInfo + fTilingMode;
    return SkSize::Make(info->w > SK_Scalar1 ? info->w : this->width() * info->w,
        info->h > SK_Scalar1 ? info->h : this->height() * info->h);
}
//////////////////////////////////////////////////////////////////////////////

static SkView* curr_view(SkWindow* wind)
{
=======
    SkScalar    w, h;
};

static const struct TilingInfo gTilingInfo[] = {
    { "No tiling", SK_Scalar1        , SK_Scalar1         }, // kNo_Tiling
    { "128x128"  , SkIntToScalar(128), SkIntToScalar(128) }, // kAbs_128x128_Tiling
    { "256x256"  , SkIntToScalar(256), SkIntToScalar(256) }, // kAbs_256x256_Tiling
    { "1/4x1/4"  , SK_Scalar1 / 4    , SK_Scalar1 / 4     }, // kRel_4x4_Tiling
    { "1/1x1/16" , SK_Scalar1        , SK_Scalar1 / 16    }, // kRel_1x16_Tiling
    { "1/16x1/1" , SK_Scalar1 / 16   , SK_Scalar1         }, // kRel_16x1_Tiling
};
SK_COMPILE_ASSERT((SK_ARRAY_COUNT(gTilingInfo) == kLast_TilingMode_Enum),
                  Incomplete_tiling_labels);

SkSize SampleWindow::tileSize() const {
    SkASSERT((TilingMode)fTilingMode < kLast_TilingMode_Enum);
    const struct TilingInfo* info = gTilingInfo + fTilingMode;
    return SkSize::Make(info->w > SK_Scalar1 ? info->w : this->width() * info->w,
                        info->h > SK_Scalar1 ? info->h : this->height() * info->h);
}
//////////////////////////////////////////////////////////////////////////////

static SkView* curr_view(SkWindow* wind) {
>>>>>>> miniblink49
    SkView::F2BIter iter(wind);
    return iter.next();
}

<<<<<<< HEAD
static bool curr_title(SkWindow* wind, SkString* title)
{
=======
static bool curr_title(SkWindow* wind, SkString* title) {
>>>>>>> miniblink49
    SkView* view = curr_view(wind);
    if (view) {
        SkEvent evt(gTitleEvtName);
        if (view->doQuery(&evt)) {
            title->set(evt.findString(gTitleEvtName));
            return true;
        }
    }
    return false;
}

<<<<<<< HEAD
bool SampleWindow::sendAnimatePulse()
{
=======
bool SampleWindow::sendAnimatePulse() {
>>>>>>> miniblink49
    SkView* view = curr_view(this);
    if (SampleView::IsSampleView(view)) {
        return ((SampleView*)view)->animate(gAnimTimer);
    }
    return false;
}

void SampleWindow::setZoomCenter(float x, float y)
{
    fZoomCenterX = x;
    fZoomCenterY = y;
}

bool SampleWindow::zoomIn()
{
    // Arbitrarily decided
<<<<<<< HEAD
    if (fFatBitsScale == kMaxFatBitsScale)
        return false;
    fFatBitsScale++;
    this->inval(nullptr);
=======
    if (fFatBitsScale == 25) return false;
    fFatBitsScale++;
    this->inval(NULL);
>>>>>>> miniblink49
    return true;
}

bool SampleWindow::zoomOut()
{
<<<<<<< HEAD
    if (fFatBitsScale == 1)
        return false;
    fFatBitsScale--;
    this->inval(nullptr);
=======
    if (fFatBitsScale == 1) return false;
    fFatBitsScale--;
    this->inval(NULL);
>>>>>>> miniblink49
    return true;
}

void SampleWindow::updatePointer(int x, int y)
{
    fMouseX = x;
    fMouseY = y;
    if (fShowZoomer) {
<<<<<<< HEAD
        this->inval(nullptr);
    }
}

static inline SampleWindow::DeviceType cycle_devicetype(SampleWindow::DeviceType ct)
{
    static const SampleWindow::DeviceType gCT[] = {
        SampleWindow::kRaster_DeviceType
#if SK_SUPPORT_GPU
        ,
        SampleWindow::kGPU_DeviceType
#if SK_ANGLE
        ,
        SampleWindow::kANGLE_DeviceType
#endif // SK_ANGLE
#endif // SK_SUPPORT_GPU
    };
    static_assert(SK_ARRAY_COUNT(gCT) == SampleWindow::kDeviceTypeCnt, "array_size_mismatch");
    return gCT[ct];
}

static SkString getSampleTitle(const SkViewFactory* sampleFactory)
{
=======
        this->inval(NULL);
    }
}

static inline SampleWindow::DeviceType cycle_devicetype(SampleWindow::DeviceType ct) {
    static const SampleWindow::DeviceType gCT[] = {
        SampleWindow::kPicture_DeviceType,
#if SK_SUPPORT_GPU
        SampleWindow::kGPU_DeviceType,
#if SK_ANGLE
        SampleWindow::kANGLE_DeviceType,
#endif // SK_ANGLE
#endif // SK_SUPPORT_GPU
        SampleWindow::kDeferred_DeviceType,
        SampleWindow::kRaster_DeviceType,
    };
    SK_COMPILE_ASSERT(SK_ARRAY_COUNT(gCT) == SampleWindow::kDeviceTypeCnt, array_size_mismatch);
    return gCT[ct];
}

static SkString getSampleTitle(const SkViewFactory* sampleFactory) {
>>>>>>> miniblink49
    SkView* view = (*sampleFactory)();
    SkString title;
    SampleCode::RequestTitle(view, &title);
    view->unref();
    return title;
}

<<<<<<< HEAD
static bool compareSampleTitle(const SkViewFactory* first, const SkViewFactory* second)
{
    return strcmp(getSampleTitle(first).c_str(), getSampleTitle(second).c_str()) < 0;
}

static int find_by_title(const SkViewFactory* const* factories, int count, const char title[])
{
    for (int i = 0; i < count; i++) {
        if (getSampleTitle(factories[i]).equals(title)) {
            return i;
        }
    }
    return -1;
}

static void restrict_samples(SkTDArray<const SkViewFactory*>& factories, const SkString titles[],
    int count)
{
    int newCount = 0;
    for (int i = 0; i < count; ++i) {
        int index = find_by_title(factories.begin(), factories.count(), titles[i].c_str());
        if (index >= 0) {
            SkTSwap(factories.begin()[newCount], factories.begin()[index]);
            newCount += 1;
        }
    }
    if (newCount) {
        factories.setCount(newCount);
    }
}

DEFINE_string(slide, "", "Start on this sample.");
DEFINE_int32(msaa, 0, "Request multisampling with this count.");
DEFINE_bool(deepColor, false, "Request deep color (10-bit/channel or more) display buffer.");
DEFINE_string(pictureDir, "", "Read pictures from here.");
DEFINE_string(picture, "", "Path to single picture.");
DEFINE_string(sequence, "", "Path to file containing the desired samples/gms to show.");
DEFINE_bool(sort, false, "Sort samples by title.");
DEFINE_bool(list, false, "List samples?");
DEFINE_bool(gpu, false, "Start up with gpu?");
DEFINE_bool(redraw, false, "Force continuous redrawing, for profiling or debugging tools.");
DEFINE_string(key, "", ""); // dummy to enable gm tests that have platform-specific names
=======
static bool compareSampleTitle(const SkViewFactory* first, const SkViewFactory* second) {
    return strcmp(getSampleTitle(first).c_str(), getSampleTitle(second).c_str()) < 0;
}

DEFINE_string(slide, "", "Start on this sample.");
DEFINE_int32(msaa, 0, "Request multisampling with this count.");
DEFINE_string(pictureDir, "", "Read pictures from here.");
DEFINE_string(picture, "", "Path to single picture.");
DEFINE_bool(sort, false, "Sort samples by title.");
DEFINE_bool(list, false, "List samples?");
>>>>>>> miniblink49
#ifdef SAMPLE_PDF_FILE_VIEWER
DEFINE_string(pdfPath, "", "Path to direcotry of pdf files.");
#endif

#include "SkTaskGroup.h"

SampleWindow::SampleWindow(void* hwnd, int argc, char** argv, DeviceManager* devManager)
    : INHERITED(hwnd)
<<<<<<< HEAD
    , fDevManager(nullptr)
{
=======
    , fDevManager(NULL) {
>>>>>>> miniblink49

    SkCommandLineFlags::Parse(argc, argv);

    fCurrIndex = -1;

    if (!FLAGS_pictureDir.isEmpty()) {
        SkOSFile::Iter iter(FLAGS_pictureDir[0], "skp");
        SkString filename;
        while (iter.next(&filename)) {
            *fSamples.append() = new PictFileFactory(
                SkOSPath::Join(FLAGS_pictureDir[0], filename.c_str()));
        }
    }
    if (!FLAGS_picture.isEmpty()) {
        SkString path(FLAGS_picture[0]);
        fCurrIndex = fSamples.count();
        *fSamples.append() = new PictFileFactory(path);
    }
#ifdef SAMPLE_PDF_FILE_VIEWER
    if (!FLAGS_pdfPath.isEmpty()) {
        SkOSFile::Iter iter(FLAGS_pdfPath[0], "pdf");
        SkString filename;
        while (iter.next(&filename)) {
            *fSamples.append() = new PdfFileViewerFactory(
                SkOSPath::Join(FLAGS_pictureDir[0], filename.c_str()));
        }
    }
#endif
    SkGMRegistyToSampleRegistry();
    {
        const SkViewRegister* reg = SkViewRegister::Head();
        while (reg) {
            *fSamples.append() = reg->factory();
            reg = reg->next();
        }
    }

<<<<<<< HEAD
    if (!FLAGS_sequence.isEmpty()) {
        // The sequence file just contains a list (separated by CRs) of the samples or GM:gms
        // you want to restrict to. Only these will appear when you cycle through.
        // If none are found, or the file is empty, then it will be ignored, and all samples
        // will be available.
        SkFILEStream stream(FLAGS_sequence[0]);
        if (stream.isValid()) {
            size_t len = stream.getLength();
            SkAutoTMalloc<char> storage(len + 1);
            char* buffer = storage.get();
            stream.read(buffer, len);
            buffer[len] = 0;

            SkTArray<SkString> titles;
            SkStrSplit(buffer, "\n\r", &titles);
            restrict_samples(fSamples, titles.begin(), titles.count());
        }
    }

    if (FLAGS_sort) {
        // Sort samples, so foo.skp and foo.pdf are consecutive and we can quickly spot where
        // skp -> pdf -> png fails.
        SkTQSort(fSamples.begin(), fSamples.end() ? fSamples.end() - 1 : nullptr, compareSampleTitle);
=======
    if (FLAGS_sort) {
        // Sort samples, so foo.skp and foo.pdf are consecutive and we can quickly spot where
        // skp -> pdf -> png fails.
        SkTQSort(fSamples.begin(), fSamples.end() ? fSamples.end() - 1 : NULL, compareSampleTitle);
>>>>>>> miniblink49
    }

    if (!FLAGS_slide.isEmpty()) {
        fCurrIndex = findByTitle(FLAGS_slide[0]);
        if (fCurrIndex < 0) {
            fprintf(stderr, "Unknown sample \"%s\"\n", FLAGS_slide[0]);
            listTitles();
        }
    }

    fMSAASampleCount = FLAGS_msaa;
<<<<<<< HEAD
    fDeepColor = FLAGS_deepColor;
=======
>>>>>>> miniblink49

    if (FLAGS_list) {
        listTitles();
    }

    if (fCurrIndex < 0) {
        SkString title;
        if (readTitleFromPrefs(&title)) {
            fCurrIndex = findByTitle(title.c_str());
        }
    }

    if (fCurrIndex < 0) {
        fCurrIndex = 0;
    }

    static SkTaskGroup::Enabler enabled(-1);
    gSampleWindow = this;

<<<<<<< HEAD
    fDeviceType = kRaster_DeviceType;
#if SK_SUPPORT_GPU
    if (FLAGS_gpu) {
        fDeviceType = kGPU_DeviceType;
    }
#endif

=======
#ifdef  PIPE_FILE
    //Clear existing file or create file if it doesn't exist
    FILE* f = fopen(FILE_PATH, "wb");
    fclose(f);
#endif

    fDeviceType = kRaster_DeviceType;

>>>>>>> miniblink49
#if DEFAULT_TO_GPU
    fDeviceType = kGPU_DeviceType;
#endif
#if SK_ANGLE && DEFAULT_TO_ANGLE
    fDeviceType = kANGLE_DeviceType;
#endif

    fUseClip = false;
<<<<<<< HEAD
    fUsePicture = false;
=======
>>>>>>> miniblink49
    fAnimating = false;
    fRotate = false;
    fPerspAnim = false;
    fRequestGrabImage = false;
<<<<<<< HEAD
=======
    fPipeState = SkOSMenu::kOffState;
>>>>>>> miniblink49
    fTilingMode = kNo_Tiling;
    fMeasureFPS = false;
    fLCDState = SkOSMenu::kMixedState;
    fAAState = SkOSMenu::kMixedState;
    fSubpixelState = SkOSMenu::kMixedState;
    fHintingState = 0;
<<<<<<< HEAD
    fPixelGeometryIndex = 0;
    fFilterQualityIndex = 0;
    fFlipAxis = 0;

    fMouseX = fMouseY = 0;
    fFatBitsScale = 8;
    fTypeface = SkTypeface::MakeFromTypeface(nullptr, SkTypeface::kBold);
=======
    fFilterQualityIndex = 0;
    fFlipAxis = 0;
    fScrollTestX = fScrollTestY = 0;

    fMouseX = fMouseY = 0;
    fFatBitsScale = 8;
    fTypeface = SkTypeface::CreateFromTypeface(NULL, SkTypeface::kBold);
>>>>>>> miniblink49
    fShowZoomer = false;

    fZoomLevel = 0;
    fZoomScale = SK_Scalar1;
<<<<<<< HEAD
    fOffset = { 0, 0 };
=======
>>>>>>> miniblink49

    fMagnify = false;

    fSaveToPdf = false;
<<<<<<< HEAD
    fSaveToSKP = false;
=======

    fTransitionNext = 6;
    fTransitionPrev = 2;
>>>>>>> miniblink49

    int sinkID = this->getSinkID();
    fAppMenu = new SkOSMenu;
    fAppMenu->setTitle("Global Settings");
    int itemID;

<<<<<<< HEAD
    itemID = fAppMenu->appendList("ColorType", "ColorType", sinkID, 0,
        gConfig[0].fName, gConfig[1].fName, gConfig[2].fName, nullptr);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'C');

    itemID = fAppMenu->appendList("Device Type", "Device Type", sinkID, 0,
        "Raster",
        "OpenGL",
#if SK_ANGLE
        "ANGLE",
#endif
        nullptr);
=======
    itemID =fAppMenu->appendList("Device Type", "Device Type", sinkID, 0,
                                "Raster", "Picture", "OpenGL", "Deferred",
#if SK_ANGLE
                                "ANGLE",
#endif
                                NULL);
>>>>>>> miniblink49
    fAppMenu->assignKeyEquivalentToItem(itemID, 'd');
    itemID = fAppMenu->appendTriState("AA", "AA", sinkID, fAAState);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'b');
    itemID = fAppMenu->appendTriState("LCD", "LCD", sinkID, fLCDState);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'l');
    itemID = fAppMenu->appendList("FilterQuality", "FilterQuality", sinkID, fFilterQualityIndex,
<<<<<<< HEAD
        gFilterQualityStates[0].fName,
        gFilterQualityStates[1].fName,
        gFilterQualityStates[2].fName,
        gFilterQualityStates[3].fName,
        gFilterQualityStates[4].fName,
        nullptr);
=======
                                  gFilterQualityStates[0].fName,
                                  gFilterQualityStates[1].fName,
                                  gFilterQualityStates[2].fName,
                                  gFilterQualityStates[3].fName,
                                  gFilterQualityStates[4].fName,
                                  NULL);
>>>>>>> miniblink49
    fAppMenu->assignKeyEquivalentToItem(itemID, 'n');
    itemID = fAppMenu->appendTriState("Subpixel", "Subpixel", sinkID, fSubpixelState);
    fAppMenu->assignKeyEquivalentToItem(itemID, 's');
    itemID = fAppMenu->appendList("Hinting", "Hinting", sinkID, fHintingState,
<<<<<<< HEAD
        gHintingStates[0].name,
        gHintingStates[1].name,
        gHintingStates[2].name,
        gHintingStates[3].name,
        gHintingStates[4].name,
        nullptr);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'h');

    itemID = fAppMenu->appendList("Pixel Geometry", "Pixel Geometry", sinkID, fPixelGeometryIndex,
        gPixelGeometryStates[0].name,
        gPixelGeometryStates[1].name,
        gPixelGeometryStates[2].name,
        gPixelGeometryStates[3].name,
        gPixelGeometryStates[4].name,
        gPixelGeometryStates[5].name,
        nullptr);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'P');

    itemID = fAppMenu->appendList("Tiling", "Tiling", sinkID, fTilingMode,
        gTilingInfo[kNo_Tiling].label,
        gTilingInfo[kAbs_128x128_Tiling].label,
        gTilingInfo[kAbs_256x256_Tiling].label,
        gTilingInfo[kRel_4x4_Tiling].label,
        gTilingInfo[kRel_1x16_Tiling].label,
        gTilingInfo[kRel_16x1_Tiling].label,
        nullptr);
    fAppMenu->assignKeyEquivalentToItem(itemID, 't');

    itemID = fAppMenu->appendSwitch("Slide Show", "Slide Show", sinkID, false);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'a');
    itemID = fAppMenu->appendSwitch("Clip", "Clip", sinkID, fUseClip);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'c');
    itemID = fAppMenu->appendSwitch("Flip X", "Flip X", sinkID, false);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'x');
    itemID = fAppMenu->appendSwitch("Flip Y", "Flip Y", sinkID, false);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'y');
    itemID = fAppMenu->appendSwitch("Zoomer", "Zoomer", sinkID, fShowZoomer);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'z');
    itemID = fAppMenu->appendSwitch("Magnify", "Magnify", sinkID, fMagnify);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'm');

=======
                                  gHintingStates[0].name,
                                  gHintingStates[1].name,
                                  gHintingStates[2].name,
                                  gHintingStates[3].name,
                                  gHintingStates[4].name,
                                  NULL);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'h');

    fUsePipeMenuItemID = fAppMenu->appendTriState("Pipe", "Pipe" , sinkID,
                                                  fPipeState);
    fAppMenu->assignKeyEquivalentToItem(fUsePipeMenuItemID, 'P');

    itemID =fAppMenu->appendList("Tiling", "Tiling", sinkID, fTilingMode,
                                 gTilingInfo[kNo_Tiling].label,
                                 gTilingInfo[kAbs_128x128_Tiling].label,
                                 gTilingInfo[kAbs_256x256_Tiling].label,
                                 gTilingInfo[kRel_4x4_Tiling].label,
                                 gTilingInfo[kRel_1x16_Tiling].label,
                                 gTilingInfo[kRel_16x1_Tiling].label,
                                 NULL);
    fAppMenu->assignKeyEquivalentToItem(itemID, 't');

    itemID = fAppMenu->appendSwitch("Slide Show", "Slide Show" , sinkID, false);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'a');
    itemID = fAppMenu->appendSwitch("Clip", "Clip" , sinkID, fUseClip);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'c');
    itemID = fAppMenu->appendSwitch("Flip X", "Flip X" , sinkID, false);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'x');
    itemID = fAppMenu->appendSwitch("Flip Y", "Flip Y" , sinkID, false);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'y');
    itemID = fAppMenu->appendSwitch("Zoomer", "Zoomer" , sinkID, fShowZoomer);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'z');
    itemID = fAppMenu->appendSwitch("Magnify", "Magnify" , sinkID, fMagnify);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'm');
    itemID =fAppMenu->appendList("Transition-Next", "Transition-Next", sinkID,
                                fTransitionNext, "Up", "Up and Right", "Right",
                                "Down and Right", "Down", "Down and Left",
                                "Left", "Up and Left", NULL);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'j');
    itemID =fAppMenu->appendList("Transition-Prev", "Transition-Prev", sinkID,
                                fTransitionPrev, "Up", "Up and Right", "Right",
                                "Down and Right", "Down", "Down and Left",
                                "Left", "Up and Left", NULL);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'k');
>>>>>>> miniblink49
    itemID = fAppMenu->appendAction("Save to PDF", sinkID);
    fAppMenu->assignKeyEquivalentToItem(itemID, 'e');

    this->addMenu(fAppMenu);
    fSlideMenu = new SkOSMenu;
    this->addMenu(fSlideMenu);

    this->setVisibleP(true);
    this->setClipToBounds(false);

    this->loadView((*fSamples[fCurrIndex])());

<<<<<<< HEAD
    if (nullptr == devManager) {
=======
    if (NULL == devManager) {
>>>>>>> miniblink49
        fDevManager = new DefaultDeviceManager();
    } else {
        devManager->ref();
        fDevManager = devManager;
    }
<<<<<<< HEAD
    fDevManager->setUpBackend(this, fMSAASampleCount, fDeepColor);
=======
    fDevManager->setUpBackend(this, fMSAASampleCount);
>>>>>>> miniblink49

    // If another constructor set our dimensions, ensure that our
    // onSizeChange gets called.
    if (this->height() && this->width()) {
        this->onSizeChange();
    }

    // can't call this synchronously, since it may require a subclass to
    // to implement, or the caller may need us to have returned from the
    // constructor first. Hence we post an event to ourselves.
<<<<<<< HEAD
    //    this->updateTitle();
=======
//    this->updateTitle();
>>>>>>> miniblink49
    post_event_to_sink(new SkEvent(gUpdateWindowTitleEvtName), this);

    gAnimTimer.run();
}

<<<<<<< HEAD
SampleWindow::~SampleWindow()
{
    SkSafeUnref(fDevManager);
}

int SampleWindow::findByTitle(const char title[])
{
=======
SampleWindow::~SampleWindow() {
    SkSafeUnref(fTypeface);
    SkSafeUnref(fDevManager);
}


int SampleWindow::findByTitle(const char title[]) {
>>>>>>> miniblink49
    int i, count = fSamples.count();
    for (i = 0; i < count; i++) {
        if (getSampleTitle(i).equals(title)) {
            return i;
        }
    }
    return -1;
}

<<<<<<< HEAD
void SampleWindow::listTitles()
{
=======
void SampleWindow::listTitles() {
>>>>>>> miniblink49
    int count = fSamples.count();
    SkDebugf("All Slides:\n");
    for (int i = 0; i < count; i++) {
        SkDebugf("    %s\n", getSampleTitle(i).c_str());
    }
}

<<<<<<< HEAD
static SkBitmap capture_bitmap(SkCanvas* canvas)
{
=======
static SkBitmap capture_bitmap(SkCanvas* canvas) {
>>>>>>> miniblink49
    SkBitmap bm;
    if (bm.tryAllocPixels(canvas->imageInfo())) {
        canvas->readPixels(&bm, 0, 0);
    }
    return bm;
}

<<<<<<< HEAD
static void drawText(SkCanvas* canvas, SkString str, SkScalar left, SkScalar top, SkPaint& paint)
{
=======
static void drawText(SkCanvas* canvas, SkString str, SkScalar left, SkScalar top, SkPaint& paint) {
>>>>>>> miniblink49
    SkColor desiredColor = paint.getColor();
    paint.setColor(SK_ColorWHITE);
    const char* c_str = str.c_str();
    size_t size = str.size();
    SkRect bounds;
    paint.measureText(c_str, size, &bounds);
    bounds.offset(left, top);
    SkScalar inset = SkIntToScalar(-2);
    bounds.inset(inset, inset);
    canvas->drawRect(bounds, paint);
    if (desiredColor != SK_ColorBLACK) {
        paint.setColor(SK_ColorBLACK);
        canvas->drawText(c_str, size, left + SK_Scalar1, top + SK_Scalar1, paint);
    }
    paint.setColor(desiredColor);
    canvas->drawText(c_str, size, left, top, paint);
}

<<<<<<< HEAD
#define XCLIP_N 8
#define YCLIP_N 8

void SampleWindow::draw(SkCanvas* canvas)
{
=======
#define XCLIP_N  8
#define YCLIP_N  8

void SampleWindow::draw(SkCanvas* canvas) {
>>>>>>> miniblink49
    gAnimTimer.updateTime();

    if (fGesture.isActive()) {
        this->updateMatrix();
    }

    if (fMeasureFPS) {
        fMeasureFPS_Time = 0;
    }

    SkSize tile = this->tileSize();

    if (kNo_Tiling == fTilingMode) {
        this->INHERITED::draw(canvas); // no looping or surfaces needed
    } else {
<<<<<<< HEAD
        const SkScalar w = SkScalarCeilToScalar(tile.width());
        const SkScalar h = SkScalarCeilToScalar(tile.height());
        SkImageInfo info = SkImageInfo::MakeN32Premul(SkScalarTruncToInt(w), SkScalarTruncToInt(h));
        auto surface(canvas->makeSurface(info));
        SkCanvas* tileCanvas = surface->getCanvas();

        for (SkScalar y = 0; y < height(); y += h) {
            for (SkScalar x = 0; x < width(); x += w) {
=======
        const int w = SkScalarRoundToInt(tile.width());
        const int h = SkScalarRoundToInt(tile.height());
        SkImageInfo info = SkImageInfo::MakeN32Premul(w, h);
        SkAutoTUnref<SkSurface> surface(canvas->newSurface(info));
        SkCanvas* tileCanvas = surface->getCanvas();

        for (SkScalar y = 0; y < height(); y += tile.height()) {
            for (SkScalar x = 0; x < width(); x += tile.width()) {
>>>>>>> miniblink49
                SkAutoCanvasRestore acr(tileCanvas, true);
                tileCanvas->translate(-x, -y);
                tileCanvas->clear(0);
                this->INHERITED::draw(tileCanvas);
<<<<<<< HEAD
                surface->draw(canvas, x, y, nullptr);
=======
                surface->draw(canvas, x, y, NULL);
>>>>>>> miniblink49
            }
        }

        // for drawing the borders between tiles
        SkPaint paint;
        paint.setColor(0x60FF00FF);
        paint.setStyle(SkPaint::kStroke_Style);

        for (SkScalar y = 0; y < height(); y += tile.height()) {
            for (SkScalar x = 0; x < width(); x += tile.width()) {
                canvas->drawRect(SkRect::MakeXYWH(x, y, tile.width(), tile.height()), paint);
            }
        }
    }

    if (fShowZoomer && !fSaveToPdf) {
        showZoomer(canvas);
    }
    if (fMagnify && !fSaveToPdf) {
        magnify(canvas);
    }

    if (fMeasureFPS && fMeasureFPS_Time) {
        this->updateTitle();
        this->postInvalDelay();
    }

<<<<<<< HEAD
    if (this->sendAnimatePulse() || FLAGS_redraw) {
        this->inval(nullptr);
=======
    if (this->sendAnimatePulse()) {
        this->inval(NULL);
>>>>>>> miniblink49
    }

    // do this last
    fDevManager->publishCanvas(fDeviceType, canvas, this);
}

static float clipW = 200;
static float clipH = 200;
<<<<<<< HEAD
void SampleWindow::magnify(SkCanvas* canvas)
{
=======
void SampleWindow::magnify(SkCanvas* canvas) {
>>>>>>> miniblink49
    SkRect r;
    int count = canvas->save();

    SkMatrix m = canvas->getTotalMatrix();
    if (!m.invert(&m)) {
        return;
    }
    SkPoint offset, center;
    SkScalar mouseX = fMouseX * SK_Scalar1;
    SkScalar mouseY = fMouseY * SK_Scalar1;
<<<<<<< HEAD
    m.mapXY(mouseX - clipW / 2, mouseY - clipH / 2, &offset);
=======
    m.mapXY(mouseX - clipW/2, mouseY - clipH/2, &offset);
>>>>>>> miniblink49
    m.mapXY(mouseX, mouseY, &center);

    r.set(0, 0, clipW * m.getScaleX(), clipH * m.getScaleX());
    r.offset(offset.fX, offset.fY);

    SkPaint paint;
    paint.setColor(0xFF66AAEE);
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(10.f * m.getScaleX());
    //lense offset
    //canvas->translate(0, -250);
    canvas->drawRect(r, paint);
    canvas->clipRect(r);

    m = canvas->getTotalMatrix();
    m.setTranslate(-center.fX, -center.fY);
    m.postScale(0.5f * fFatBitsScale, 0.5f * fFatBitsScale);
    m.postTranslate(center.fX, center.fY);
    canvas->concat(m);

    this->INHERITED::draw(canvas);

    canvas->restoreToCount(count);
}

<<<<<<< HEAD
static SkPaint& set_color_ref(SkPaint& paint, SkColor c)
{
    paint.setColor(c);
    return paint;
}

static void show_lcd_box(SkCanvas* canvas, SkScalar x, SkScalar y, SkColor c,
    SkScalar sx, SkScalar sy)
{
    const SkScalar w = (1 - 1 / sx) / 3;
    SkPaint paint;
    SkRect r = SkRect::MakeXYWH(x, y, w, 1 - 1 / sy);
    canvas->drawRect(r, set_color_ref(paint, SkColorSetRGB(SkColorGetR(c), 0, 0)));
    r.offset(w, 0);
    canvas->drawRect(r, set_color_ref(paint, SkColorSetRGB(0, SkColorGetG(c), 0)));
    r.offset(w, 0);
    canvas->drawRect(r, set_color_ref(paint, SkColorSetRGB(0, 0, SkColorGetB(c))));
}

static void show_lcd_circle(SkCanvas* canvas, SkScalar x, SkScalar y, SkColor c,
    SkScalar, SkScalar)
{
    const SkRect r = SkRect::MakeXYWH(x, y, 1, 1);
    const SkScalar cx = x + 0.5f;
    const SkScalar cy = y + 0.5f;

    SkPaint paint;
    paint.setAntiAlias(true);

    SkPath path;
    path.addArc(r, 0, 120);
    path.lineTo(cx, cy);
    canvas->drawPath(path, set_color_ref(paint, SkColorSetRGB(SkColorGetR(c), 0, 0)));

    path.reset();
    path.addArc(r, 120, 120);
    path.lineTo(cx, cy);
    canvas->drawPath(path, set_color_ref(paint, SkColorSetRGB(0, SkColorGetG(c), 0)));

    path.reset();
    path.addArc(r, 240, 120);
    path.lineTo(cx, cy);
    canvas->drawPath(path, set_color_ref(paint, SkColorSetRGB(0, 0, SkColorGetB(c))));
}

typedef void (*ShowLCDProc)(SkCanvas*, SkScalar, SkScalar, SkColor, SkScalar, SkScalar);

/*
 *  Like drawBitmapRect but we manually draw each pixels in RGB
 */
static void show_lcd_grid(SkCanvas* canvas, const SkBitmap& bitmap,
    const SkIRect& origSrc, const SkRect& dst, ShowLCDProc proc)
{
    SkIRect src;
    if (!src.intersect(origSrc, bitmap.bounds())) {
        return;
    }
    const SkScalar sx = dst.width() / src.width();
    const SkScalar sy = dst.height() / src.height();

    SkAutoCanvasRestore acr(canvas, true);
    canvas->translate(dst.left(), dst.top());
    canvas->scale(sx, sy);

    for (int y = 0; y < src.height(); ++y) {
        for (int x = 0; x < src.width(); ++x) {
            proc(canvas, SkIntToScalar(x), SkIntToScalar(y),
                bitmap.getColor(src.left() + x, src.top() + y), sx, sy);
        }
    }
}

void SampleWindow::showZoomer(SkCanvas* canvas)
{
    int count = canvas->save();
    canvas->resetMatrix();
    // Ensure the mouse position is on screen.
    int width = SkScalarRoundToInt(this->width());
    int height = SkScalarRoundToInt(this->height());
    if (fMouseX >= width)
        fMouseX = width - 1;
    else if (fMouseX < 0)
        fMouseX = 0;
    if (fMouseY >= height)
        fMouseY = height - 1;
    else if (fMouseY < 0)
        fMouseY = 0;

    SkBitmap bitmap = capture_bitmap(canvas);
    bitmap.lockPixels();

    // Find the size of the zoomed in view, forced to be odd, so the examined pixel is in the middle.
    int zoomedWidth = (width >> 1) | 1;
    int zoomedHeight = (height >> 1) | 1;
    SkIRect src;
    src.set(0, 0, zoomedWidth / fFatBitsScale, zoomedHeight / fFatBitsScale);
    src.offset(fMouseX - (src.width() >> 1), fMouseY - (src.height() >> 1));
    SkRect dest;
    dest.set(0, 0, SkIntToScalar(zoomedWidth), SkIntToScalar(zoomedHeight));
    dest.offset(SkIntToScalar(width - zoomedWidth), SkIntToScalar(height - zoomedHeight));
    SkPaint paint;
    // Clear the background behind our zoomed in view
    paint.setColor(SK_ColorWHITE);
    canvas->drawRect(dest, paint);
    switch (fFatBitsScale) {
    case kMaxFatBitsScale:
        show_lcd_grid(canvas, bitmap, src, dest, show_lcd_box);
        break;
    case kMaxFatBitsScale - 1:
        show_lcd_grid(canvas, bitmap, src, dest, show_lcd_circle);
        break;
    default:
        canvas->drawBitmapRect(bitmap, src, dest, nullptr);
        break;
    }

    paint.setColor(SK_ColorBLACK);
    paint.setStyle(SkPaint::kStroke_Style);
    // Draw a border around the pixel in the middle
    SkRect originalPixel;
    originalPixel.set(SkIntToScalar(fMouseX), SkIntToScalar(fMouseY), SkIntToScalar(fMouseX + 1), SkIntToScalar(fMouseY + 1));
    SkMatrix matrix;
    SkRect scalarSrc;
    scalarSrc.set(src);
    SkColor color = bitmap.getColor(fMouseX, fMouseY);
    if (matrix.setRectToRect(scalarSrc, dest, SkMatrix::kFill_ScaleToFit)) {
        SkRect pixel;
        matrix.mapRect(&pixel, originalPixel);
        // TODO Perhaps measure the values and make the outline white if it's "dark"
        if (color == SK_ColorBLACK) {
            paint.setColor(SK_ColorWHITE);
        }
        canvas->drawRect(pixel, paint);
    }
    paint.setColor(SK_ColorBLACK);
    // Draw a border around the destination rectangle
    canvas->drawRect(dest, paint);
    paint.setStyle(SkPaint::kStrokeAndFill_Style);
    // Identify the pixel and its color on screen
    paint.setTypeface(fTypeface);
    paint.setAntiAlias(true);
    SkScalar lineHeight = paint.getFontMetrics(nullptr);
    SkString string;
    string.appendf("(%i, %i)", fMouseX, fMouseY);
    SkScalar left = dest.fLeft + SkIntToScalar(3);
    SkScalar i = SK_Scalar1;
    drawText(canvas, string, left, SkScalarMulAdd(lineHeight, i, dest.fTop), paint);
    // Alpha
    i += SK_Scalar1;
    string.reset();
    string.appendf("A: %X", SkColorGetA(color));
    drawText(canvas, string, left, SkScalarMulAdd(lineHeight, i, dest.fTop), paint);
    // Red
    i += SK_Scalar1;
    string.reset();
    string.appendf("R: %X", SkColorGetR(color));
    paint.setColor(SK_ColorRED);
    drawText(canvas, string, left, SkScalarMulAdd(lineHeight, i, dest.fTop), paint);
    // Green
    i += SK_Scalar1;
    string.reset();
    string.appendf("G: %X", SkColorGetG(color));
    paint.setColor(SK_ColorGREEN);
    drawText(canvas, string, left, SkScalarMulAdd(lineHeight, i, dest.fTop), paint);
    // Blue
    i += SK_Scalar1;
    string.reset();
    string.appendf("B: %X", SkColorGetB(color));
    paint.setColor(SK_ColorBLUE);
    drawText(canvas, string, left, SkScalarMulAdd(lineHeight, i, dest.fTop), paint);
    canvas->restoreToCount(count);
}

void SampleWindow::onDraw(SkCanvas* canvas)
{
=======
void SampleWindow::showZoomer(SkCanvas* canvas) {
        int count = canvas->save();
        canvas->resetMatrix();
        // Ensure the mouse position is on screen.
        int width = SkScalarRoundToInt(this->width());
        int height = SkScalarRoundToInt(this->height());
        if (fMouseX >= width) fMouseX = width - 1;
        else if (fMouseX < 0) fMouseX = 0;
        if (fMouseY >= height) fMouseY = height - 1;
        else if (fMouseY < 0) fMouseY = 0;

        SkBitmap bitmap = capture_bitmap(canvas);
        bitmap.lockPixels();

        // Find the size of the zoomed in view, forced to be odd, so the examined pixel is in the middle.
        int zoomedWidth = (width >> 1) | 1;
        int zoomedHeight = (height >> 1) | 1;
        SkIRect src;
        src.set(0, 0, zoomedWidth / fFatBitsScale, zoomedHeight / fFatBitsScale);
        src.offset(fMouseX - (src.width()>>1), fMouseY - (src.height()>>1));
        SkRect dest;
        dest.set(0, 0, SkIntToScalar(zoomedWidth), SkIntToScalar(zoomedHeight));
        dest.offset(SkIntToScalar(width - zoomedWidth), SkIntToScalar(height - zoomedHeight));
        SkPaint paint;
        // Clear the background behind our zoomed in view
        paint.setColor(SK_ColorWHITE);
        canvas->drawRect(dest, paint);
        canvas->drawBitmapRect(bitmap, &src, dest);
        paint.setColor(SK_ColorBLACK);
        paint.setStyle(SkPaint::kStroke_Style);
        // Draw a border around the pixel in the middle
        SkRect originalPixel;
        originalPixel.set(SkIntToScalar(fMouseX), SkIntToScalar(fMouseY), SkIntToScalar(fMouseX + 1), SkIntToScalar(fMouseY + 1));
        SkMatrix matrix;
        SkRect scalarSrc;
        scalarSrc.set(src);
        SkColor color = bitmap.getColor(fMouseX, fMouseY);
        if (matrix.setRectToRect(scalarSrc, dest, SkMatrix::kFill_ScaleToFit)) {
            SkRect pixel;
            matrix.mapRect(&pixel, originalPixel);
            // TODO Perhaps measure the values and make the outline white if it's "dark"
            if (color == SK_ColorBLACK) {
                paint.setColor(SK_ColorWHITE);
            }
            canvas->drawRect(pixel, paint);
        }
        paint.setColor(SK_ColorBLACK);
        // Draw a border around the destination rectangle
        canvas->drawRect(dest, paint);
        paint.setStyle(SkPaint::kStrokeAndFill_Style);
        // Identify the pixel and its color on screen
        paint.setTypeface(fTypeface);
        paint.setAntiAlias(true);
        SkScalar lineHeight = paint.getFontMetrics(NULL);
        SkString string;
        string.appendf("(%i, %i)", fMouseX, fMouseY);
        SkScalar left = dest.fLeft + SkIntToScalar(3);
        SkScalar i = SK_Scalar1;
        drawText(canvas, string, left, SkScalarMulAdd(lineHeight, i, dest.fTop), paint);
        // Alpha
        i += SK_Scalar1;
        string.reset();
        string.appendf("A: %X", SkColorGetA(color));
        drawText(canvas, string, left, SkScalarMulAdd(lineHeight, i, dest.fTop), paint);
        // Red
        i += SK_Scalar1;
        string.reset();
        string.appendf("R: %X", SkColorGetR(color));
        paint.setColor(SK_ColorRED);
        drawText(canvas, string, left, SkScalarMulAdd(lineHeight, i, dest.fTop), paint);
        // Green
        i += SK_Scalar1;
        string.reset();
        string.appendf("G: %X", SkColorGetG(color));
        paint.setColor(SK_ColorGREEN);
        drawText(canvas, string, left, SkScalarMulAdd(lineHeight, i, dest.fTop), paint);
        // Blue
        i += SK_Scalar1;
        string.reset();
        string.appendf("B: %X", SkColorGetB(color));
        paint.setColor(SK_ColorBLUE);
        drawText(canvas, string, left, SkScalarMulAdd(lineHeight, i, dest.fTop), paint);
        canvas->restoreToCount(count);
}

void SampleWindow::onDraw(SkCanvas* canvas) {
>>>>>>> miniblink49
}

#include "SkColorPriv.h"

void SampleWindow::saveToPdf()
{
<<<<<<< HEAD
#if SK_SUPPORT_PDF
    fSaveToPdf = true;
    this->inval(nullptr);
#endif // SK_SUPPORT_PDF
}

SkCanvas* SampleWindow::beforeChildren(SkCanvas* canvas)
{
=======
    fSaveToPdf = true;
    this->inval(NULL);
}

SkCanvas* SampleWindow::beforeChildren(SkCanvas* canvas) {
>>>>>>> miniblink49
    if (fSaveToPdf) {
        SkString name;
        if (!this->getRawTitle(&name)) {
            name.set("unknown_sample");
        }
        name.append(".pdf");
#ifdef SK_BUILD_FOR_ANDROID
        name.prepend("/sdcard/");
#endif
<<<<<<< HEAD
        fPDFDocument = SkDocument::MakePDF(name.c_str());
        canvas = fPDFDocument->beginPage(this->width(), this->height());
    } else if (fSaveToSKP) {
        canvas = fRecorder.beginRecording(9999, 9999, nullptr, 0);
    } else if (fUsePicture) {
        canvas = fRecorder.beginRecording(9999, 9999, nullptr, 0);
=======
        fPDFDocument.reset(SkDocument::CreatePDF(name.c_str()));
        canvas = fPDFDocument->beginPage(this->width(), this->height());
    } else if (kPicture_DeviceType == fDeviceType) {
        canvas = fRecorder.beginRecording(9999, 9999, NULL, 0);
    } else if (kDeferred_DeviceType == fDeviceType) {
        fDeferredSurface.reset(canvas->newSurface(canvas->imageInfo()));
        if (fDeferredSurface.get()) {
            fDeferredCanvas.reset(SkDeferredCanvas::Create(fDeferredSurface));
            canvas = fDeferredCanvas;
        }
>>>>>>> miniblink49
    } else {
        canvas = this->INHERITED::beforeChildren(canvas);
    }

    if (fUseClip) {
        canvas->drawColor(0xFFFF88FF);
        canvas->clipPath(fClipPath, SkRegion::kIntersect_Op, true);
    }

    // Install a flags filter proxy canvas if needed
<<<<<<< HEAD
    if (fLCDState != SkOSMenu::kMixedState || fAAState != SkOSMenu::kMixedState || fSubpixelState != SkOSMenu::kMixedState || fHintingState > 0 || fFilterQualityIndex > 0) {
        canvas = new FlagsFilterCanvas(canvas, fLCDState, fAAState, fSubpixelState, fHintingState,
            fFilterQualityIndex);
=======
    if (fLCDState != SkOSMenu::kMixedState ||
        fAAState != SkOSMenu::kMixedState ||
        fSubpixelState != SkOSMenu::kMixedState ||
        fHintingState > 0 ||
        fFilterQualityIndex > 0) {

        canvas = SkNEW_ARGS(FlagsFilterCanvas, (canvas, fLCDState, fAAState, fSubpixelState,
                                                fHintingState, fFilterQualityIndex));
>>>>>>> miniblink49
        fFlagsFilterCanvas.reset(canvas);
    }

    return canvas;
}
#include "SkMultiPictureDraw.h"
<<<<<<< HEAD
void SampleWindow::afterChildren(SkCanvas* orig)
{
    fFlagsFilterCanvas.reset(nullptr);
=======
void SampleWindow::afterChildren(SkCanvas* orig) {
    fFlagsFilterCanvas.reset(NULL);
>>>>>>> miniblink49

    if (fSaveToPdf) {
        fSaveToPdf = false;
        fPDFDocument->endPage();
<<<<<<< HEAD
        fPDFDocument.reset(nullptr);
        // We took over the draw calls in order to create the PDF, so we need
        // to redraw.
        this->inval(nullptr);
=======
        fPDFDocument.reset(NULL);
        // We took over the draw calls in order to create the PDF, so we need
        // to redraw.
        this->inval(NULL);
>>>>>>> miniblink49
        return;
    }

    if (fRequestGrabImage) {
        fRequestGrabImage = false;

        SkBitmap bmp = capture_bitmap(orig);
        if (!bmp.isNull()) {
            static int gSampleGrabCounter;
            SkString name;
            name.printf("sample_grab_%d.png", gSampleGrabCounter++);
            SkImageEncoder::EncodeFile(name.c_str(), bmp,
<<<<<<< HEAD
                SkImageEncoder::kPNG_Type, 100);
        }
        this->inval(nullptr);
        return;
    }

    if (fSaveToSKP) {
        sk_sp<SkPicture> picture(fRecorder.finishRecordingAsPicture());
        SkFILEWStream stream("sample_app.skp");
        picture->serialize(&stream);
        fSaveToSKP = false;
        this->inval(nullptr);
        return;
    }

    if (fUsePicture) {
        sk_sp<SkPicture> picture(fRecorder.finishRecordingAsPicture());

        // serialize/deserialize?
        if (false) {
            SkDynamicMemoryWStream wstream;
            picture->serialize(&wstream);

            SkAutoTDelete<SkStream> rstream(wstream.detachAsStream());
            picture = SkPicture::MakeFromStream(rstream);
        }
        orig->drawPicture(picture.get());
    }

    // Do this after presentGL and other finishing, rather than in afterChild
    if (fMeasureFPS) {
        orig->flush();
        fTimer.end();
        fMeasureFPS_Time += fTimer.fWall;
    }
}

void SampleWindow::beforeChild(SkView* child, SkCanvas* canvas)
{
=======
                                       SkImageEncoder::kPNG_Type, 100);
        }
    }

    if (kPicture_DeviceType == fDeviceType) {
        SkAutoTUnref<const SkPicture> picture(fRecorder.endRecording());

        if (true) {
            if (true) {
                SkImageInfo info;
                size_t rowBytes;
                void* addr = orig->accessTopLayerPixels(&info, &rowBytes);
                if (addr) {
                    SkSurface* surfs[4];
                    SkMultiPictureDraw md;

                    SkImageInfo n = SkImageInfo::Make(info.width()/2, info.height()/2,
                                                      info.colorType(), info.alphaType());
                    int index = 0;
                    for (int y = 0; y < 2; ++y) {
                        for (int x = 0; x < 2; ++x) {
                            char* p = (char*)addr;
                            p += y * n.height() * rowBytes;
                            p += x * n.width() * sizeof(SkPMColor);
                            surfs[index] = SkSurface::NewRasterDirect(n, p, rowBytes);
                            SkCanvas* c = surfs[index]->getCanvas();
                            c->translate(SkIntToScalar(-x * n.width()),
                                         SkIntToScalar(-y * n.height()));
                            c->concat(orig->getTotalMatrix());
                            md.add(c, picture, NULL, NULL);
                            index++;
                        }
                    }
                    md.draw();
                    for (int i = 0; i < 4; ++i) {
                        surfs[i]->unref();
                    }
                }
            } else {
                orig->drawPicture(picture);
            }
        } else if (true) {
            SkDynamicMemoryWStream ostream;
            picture->serialize(&ostream);

            SkAutoDataUnref data(ostream.copyToData());
            SkMemoryStream istream(data->data(), data->size());
            SkAutoTUnref<SkPicture> pict(SkPicture::CreateFromStream(&istream));
            if (pict.get() != NULL) {
                orig->drawPicture(pict.get());
            }
        } else {
            picture->playback(orig);
        }
    } else if (kDeferred_DeviceType == fDeviceType) {
        SkAutoTUnref<SkImage> image(fDeferredCanvas->newImageSnapshot());
        if (image) {
            orig->drawImage(image, 0, 0, NULL);
        }
        fDeferredCanvas.reset(NULL);
        fDeferredSurface.reset(NULL);
    }

    // Do this after presentGL and other finishing, rather than in afterChild
    if (fMeasureFPS && fMeasureFPS_StartTime) {
        fMeasureFPS_Time += SkTime::GetMSecs() - fMeasureFPS_StartTime;
    }
}

void SampleWindow::beforeChild(SkView* child, SkCanvas* canvas) {
>>>>>>> miniblink49
    if (fRotate) {
        SkScalar cx = this->width() / 2;
        SkScalar cy = this->height() / 2;
        canvas->translate(cx, cy);
        canvas->rotate(gAnimTimer.scaled(10));
        canvas->translate(-cx, -cy);
    }

    if (fPerspAnim) {
        SkScalar secs = gAnimTimer.scaled(1);

        static const SkScalar gAnimPeriod = 10 * SK_Scalar1;
        static const SkScalar gAnimMag = SK_Scalar1 / 1000;
        SkScalar t = SkScalarMod(secs, gAnimPeriod);
        if (SkScalarFloorToInt(secs / gAnimPeriod) & 0x1) {
            t = gAnimPeriod - t;
        }
        t = 2 * t - gAnimPeriod;
        t *= gAnimMag / gAnimPeriod;
        SkMatrix m;
        m.reset();
#if 1
        m.setPerspY(t);
#else
        m.setPerspY(SK_Scalar1 / 1000);
        m.setSkewX(8.0f / 25);
        m.dump();
#endif
        canvas->concat(m);
    }

    if (fMeasureFPS) {
<<<<<<< HEAD
        (void)SampleView::SetRepeatDraw(child, FPS_REPEAT_COUNT);
        fTimer.start();
=======
        if (SampleView::SetRepeatDraw(child, FPS_REPEAT_COUNT)) {
            fMeasureFPS_StartTime = SkTime::GetMSecs();
        }
>>>>>>> miniblink49
    } else {
        (void)SampleView::SetRepeatDraw(child, 1);
    }
    if (fPerspAnim || fRotate) {
<<<<<<< HEAD
        this->inval(nullptr);
    }
}

void SampleWindow::changeOffset(SkVector delta)
{
    fOffset += delta;
    this->updateMatrix();
}

void SampleWindow::changeZoomLevel(float delta)
{
=======
        this->inval(NULL);
    }
}

void SampleWindow::changeZoomLevel(float delta) {
>>>>>>> miniblink49
    fZoomLevel += delta;
    if (fZoomLevel > 0) {
        fZoomLevel = SkMinScalar(fZoomLevel, MAX_ZOOM_LEVEL);
        fZoomScale = fZoomLevel + SK_Scalar1;
    } else if (fZoomLevel < 0) {
        fZoomLevel = SkMaxScalar(fZoomLevel, MIN_ZOOM_LEVEL);
        fZoomScale = SK_Scalar1 / (SK_Scalar1 - fZoomLevel);
    } else {
        fZoomScale = SK_Scalar1;
    }
    this->updateMatrix();
}

<<<<<<< HEAD
void SampleWindow::updateMatrix()
{
    SkMatrix m;
    m.reset();

=======
void SampleWindow::updateMatrix(){
    SkMatrix m;
    m.reset();
>>>>>>> miniblink49
    if (fZoomLevel) {
        SkPoint center;
        //m = this->getLocalMatrix();//.invert(&m);
        m.mapXY(fZoomCenterX, fZoomCenterY, &center);
        SkScalar cx = center.fX;
        SkScalar cy = center.fY;

        m.setTranslate(-cx, -cy);
        m.postScale(fZoomScale, fZoomScale);
        m.postTranslate(cx, cy);
    }

<<<<<<< HEAD
    m.postTranslate(fOffset.fX, fOffset.fY);

=======
>>>>>>> miniblink49
    if (fFlipAxis) {
        m.preTranslate(fZoomCenterX, fZoomCenterY);
        if (fFlipAxis & kFlipAxis_X) {
            m.preScale(-SK_Scalar1, SK_Scalar1);
        }
        if (fFlipAxis & kFlipAxis_Y) {
            m.preScale(SK_Scalar1, -SK_Scalar1);
        }
        m.preTranslate(-fZoomCenterX, -fZoomCenterY);
        //canvas->concat(m);
    }
    // Apply any gesture matrix
    m.preConcat(fGesture.localM());
    m.preConcat(fGesture.globalM());

    this->setLocalMatrix(m);

    this->updateTitle();
<<<<<<< HEAD
    this->inval(nullptr);
}
bool SampleWindow::previousSample()
{
=======
    this->inval(NULL);
}
bool SampleWindow::previousSample() {
>>>>>>> miniblink49
    fCurrIndex = (fCurrIndex - 1 + fSamples.count()) % fSamples.count();
    this->loadView((*fSamples[fCurrIndex])());
    return true;
}

<<<<<<< HEAD
#include "SkGlyphCache.h"
#include "SkResourceCache.h"
bool SampleWindow::nextSample()
{
    fCurrIndex = (fCurrIndex + 1) % fSamples.count();
    this->loadView((*fSamples[fCurrIndex])());

    if (false) {
        SkResourceCache::TestDumpMemoryStatistics();
        SkGlyphCache::Dump();
        SkDebugf("\n");
    }

    return true;
}

bool SampleWindow::goToSample(int i)
{
=======
bool SampleWindow::nextSample() {
    fCurrIndex = (fCurrIndex + 1) % fSamples.count();
    this->loadView((*fSamples[fCurrIndex])());
    return true;
}

bool SampleWindow::goToSample(int i) {
>>>>>>> miniblink49
    fCurrIndex = (i) % fSamples.count();
    this->loadView((*fSamples[fCurrIndex])());
    return true;
}

<<<<<<< HEAD
SkString SampleWindow::getSampleTitle(int i)
{
    return ::getSampleTitle(fSamples[i]);
}

int SampleWindow::sampleCount()
{
    return fSamples.count();
}

void SampleWindow::showOverview()
{
    this->loadView(create_overview(fSamples.count(), fSamples.begin()));
}

void SampleWindow::postAnimatingEvent()
{
=======
SkString SampleWindow::getSampleTitle(int i) {
    return ::getSampleTitle(fSamples[i]);
}

int SampleWindow::sampleCount() {
    return fSamples.count();
}

void SampleWindow::showOverview() {
    this->loadView(create_overview(fSamples.count(), fSamples.begin()));
}

void SampleWindow::postAnimatingEvent() {
>>>>>>> miniblink49
    if (fAnimating) {
        (new SkEvent(ANIMATING_EVENTTYPE, this->getSinkID()))->postDelay(ANIMATING_DELAY);
    }
}

<<<<<<< HEAD
bool SampleWindow::onEvent(const SkEvent& evt)
{
=======
bool SampleWindow::onEvent(const SkEvent& evt) {
>>>>>>> miniblink49
    if (evt.isType(gUpdateWindowTitleEvtName)) {
        this->updateTitle();
        return true;
    }
    if (evt.isType(ANIMATING_EVENTTYPE)) {
        if (fAnimating) {
            this->nextSample();
            this->postAnimatingEvent();
        }
        return true;
    }
    if (evt.isType("set-curr-index")) {
        this->goToSample(evt.getFast32());
        return true;
    }
    if (isInvalEvent(evt)) {
<<<<<<< HEAD
        this->inval(nullptr);
=======
        this->inval(NULL);
>>>>>>> miniblink49
        return true;
    }
    int selected = -1;
    if (SkOSMenu::FindListIndex(evt, "Device Type", &selected)) {
        this->setDeviceType((DeviceType)selected);
        return true;
    }
<<<<<<< HEAD
    if (SkOSMenu::FindListIndex(evt, "ColorType", &selected)) {
        auto srgbColorSpace = SkColorSpace::NewNamed(SkColorSpace::kSRGB_Named);
        this->setDeviceColorType(gConfig[selected].fColorType,
            gConfig[selected].fSRGB ? srgbColorSpace : nullptr);
        return true;
    }
    if (SkOSMenu::FindSwitchState(evt, "Slide Show", nullptr)) {
        this->toggleSlideshow();
        return true;
    }
    if (SkOSMenu::FindTriState(evt, "AA", &fAAState) || SkOSMenu::FindTriState(evt, "LCD", &fLCDState) || SkOSMenu::FindListIndex(evt, "FilterQuality", &fFilterQualityIndex) || SkOSMenu::FindTriState(evt, "Subpixel", &fSubpixelState) || SkOSMenu::FindListIndex(evt, "Hinting", &fHintingState) || SkOSMenu::FindSwitchState(evt, "Clip", &fUseClip) || SkOSMenu::FindSwitchState(evt, "Zoomer", &fShowZoomer) || SkOSMenu::FindSwitchState(evt, "Magnify", &fMagnify)) {
        this->inval(nullptr);
        this->updateTitle();
        return true;
    }
    if (SkOSMenu::FindListIndex(evt, "Pixel Geometry", &fPixelGeometryIndex)) {
        this->setPixelGeometry(fPixelGeometryIndex);
        return true;
    }
=======
    if (SkOSMenu::FindTriState(evt, "Pipe", &fPipeState)) {
#ifdef PIPE_NET
        if (!fPipeState != SkOSMenu::kOnState)
            gServer.disconnectAll();
#endif
        (void)SampleView::SetUsePipe(curr_view(this), fPipeState);
        this->updateTitle();
        this->inval(NULL);
        return true;
    }
    if (SkOSMenu::FindSwitchState(evt, "Slide Show", NULL)) {
        this->toggleSlideshow();
        return true;
    }
    if (SkOSMenu::FindTriState(evt, "AA", &fAAState) ||
        SkOSMenu::FindTriState(evt, "LCD", &fLCDState) ||
        SkOSMenu::FindListIndex(evt, "FilterQuality", &fFilterQualityIndex) ||
        SkOSMenu::FindTriState(evt, "Subpixel", &fSubpixelState) ||
        SkOSMenu::FindListIndex(evt, "Hinting", &fHintingState) ||
        SkOSMenu::FindSwitchState(evt, "Clip", &fUseClip) ||
        SkOSMenu::FindSwitchState(evt, "Zoomer", &fShowZoomer) ||
        SkOSMenu::FindSwitchState(evt, "Magnify", &fMagnify) ||
        SkOSMenu::FindListIndex(evt, "Transition-Next", &fTransitionNext) ||
        SkOSMenu::FindListIndex(evt, "Transition-Prev", &fTransitionPrev)) {
        this->inval(NULL);
        this->updateTitle();
        return true;
    }
>>>>>>> miniblink49
    if (SkOSMenu::FindListIndex(evt, "Tiling", &fTilingMode)) {
        if (SampleView::IsSampleView(curr_view(this))) {
            ((SampleView*)curr_view(this))->onTileSizeChanged(this->tileSize());
        }
<<<<<<< HEAD
        this->inval(nullptr);
        this->updateTitle();
        return true;
    }
    if (SkOSMenu::FindSwitchState(evt, "Flip X", nullptr)) {
=======
        this->inval(NULL);
        this->updateTitle();
        return true;
    }
    if (SkOSMenu::FindSwitchState(evt, "Flip X", NULL)) {
>>>>>>> miniblink49
        fFlipAxis ^= kFlipAxis_X;
        this->updateMatrix();
        return true;
    }
<<<<<<< HEAD
    if (SkOSMenu::FindSwitchState(evt, "Flip Y", nullptr)) {
=======
    if (SkOSMenu::FindSwitchState(evt, "Flip Y", NULL)) {
>>>>>>> miniblink49
        fFlipAxis ^= kFlipAxis_Y;
        this->updateMatrix();
        return true;
    }
<<<<<<< HEAD
    if (SkOSMenu::FindAction(evt, "Save to PDF")) {
=======
    if (SkOSMenu::FindAction(evt,"Save to PDF")) {
>>>>>>> miniblink49
        this->saveToPdf();
        return true;
    }
    return this->INHERITED::onEvent(evt);
}

<<<<<<< HEAD
bool SampleWindow::onQuery(SkEvent* query)
{
=======
bool SampleWindow::onQuery(SkEvent* query) {
>>>>>>> miniblink49
    if (query->isType("get-slide-count")) {
        query->setFast32(fSamples.count());
        return true;
    }
    if (query->isType("get-slide-title")) {
        SkView* view = (*fSamples[query->getFast32()])();
        SkEvent evt(gTitleEvtName);
        if (view->doQuery(&evt)) {
            query->setString("title", evt.findString(gTitleEvtName));
        }
        SkSafeUnref(view);
        return true;
    }
    if (query->isType("use-fast-text")) {
        SkEvent evt(gFastTextEvtName);
        return curr_view(this)->doQuery(&evt);
    }
    if (query->isType("ignore-window-bitmap")) {
<<<<<<< HEAD
        query->setFast32(this->getGrContext() != nullptr);
=======
        query->setFast32(this->getGrContext() != NULL);
>>>>>>> miniblink49
        return true;
    }
    return this->INHERITED::onQuery(query);
}

DECLARE_bool(portableFonts);

<<<<<<< HEAD
bool SampleWindow::onHandleChar(SkUnichar uni)
{
=======
bool SampleWindow::onHandleChar(SkUnichar uni) {
>>>>>>> miniblink49
    {
        SkView* view = curr_view(this);
        if (view) {
            SkEvent evt(gCharEvtName);
            evt.setFast32(uni);
            if (view->doQuery(&evt)) {
                return true;
            }
        }
    }

    int dx = 0xFF;
    int dy = 0xFF;

    switch (uni) {
<<<<<<< HEAD
    case '5':
        dx = 0;
        dy = 0;
        break;
    case '8':
        dx = 0;
        dy = -1;
        break;
    case '6':
        dx = 1;
        dy = 0;
        break;
    case '2':
        dx = 0;
        dy = 1;
        break;
    case '4':
        dx = -1;
        dy = 0;
        break;
    case '7':
        dx = -1;
        dy = -1;
        break;
    case '9':
        dx = 1;
        dy = -1;
        break;
    case '3':
        dx = 1;
        dy = 1;
        break;
    case '1':
        dx = -1;
        dy = 1;
        break;

    default:
        break;
    }

    if (0xFF != dx && 0xFF != dy) {
        this->changeOffset({ SkIntToScalar(dx / 32.0f), SkIntToScalar(dy / 32.0f) });
=======
        case '5': dx =  0; dy =  0; break;
        case '8': dx =  0; dy = -1; break;
        case '6': dx =  1; dy =  0; break;
        case '2': dx =  0; dy =  1; break;
        case '4': dx = -1; dy =  0; break;
        case '7': dx = -1; dy = -1; break;
        case '9': dx =  1; dy = -1; break;
        case '3': dx =  1; dy =  1; break;
        case '1': dx = -1; dy =  1; break;

        default:
            break;
    }

    if (0xFF != dx && 0xFF != dy) {
        if ((dx | dy) == 0) {
            fScrollTestX = fScrollTestY = 0;
        } else {
            fScrollTestX += dx;
            fScrollTestY += dy;
        }
        this->inval(NULL);
>>>>>>> miniblink49
        return true;
    }

    switch (uni) {
<<<<<<< HEAD
    case 27: // ESC
        gAnimTimer.stop();
        if (this->sendAnimatePulse()) {
            this->inval(nullptr);
        }
        break;
    case ' ':
        gAnimTimer.togglePauseResume();
        if (this->sendAnimatePulse()) {
            this->inval(nullptr);
        }
        break;
    case 'B':
        post_event_to_sink(new SkEvent("PictFileView::toggleBBox"), curr_view(this));
        // Cannot call updateTitle() synchronously, because the toggleBBox event is still in
        // the queue.
        post_event_to_sink(new SkEvent(gUpdateWindowTitleEvtName), this);
        this->inval(nullptr);
        break;
    case 'D':
        toggleDistanceFieldFonts();
        break;
    case 'f':
        // only
        toggleFPS();
        break;
    case 'F':
        FLAGS_portableFonts ^= true;
        this->inval(nullptr);
        break;
    case 'g':
        fRequestGrabImage = true;
        this->inval(nullptr);
        break;
    case 'G':
        gShowGMBounds = !gShowGMBounds;
        post_event_to_sink(GMSampleView::NewShowSizeEvt(gShowGMBounds),
            curr_view(this));
        this->inval(nullptr);
        break;
    case 'i':
        this->zoomIn();
        break;
    case 'o':
        this->zoomOut();
        break;
    case 'r':
        fRotate = !fRotate;
        this->inval(nullptr);
        this->updateTitle();
        return true;
    case 'k':
        fPerspAnim = !fPerspAnim;
        this->inval(nullptr);
        this->updateTitle();
        return true;
    case 'K':
        fSaveToSKP = true;
        this->inval(nullptr);
        return true;
    case 'M':
        fUsePicture = !fUsePicture;
        this->inval(nullptr);
        this->updateTitle();
        return true;
#if SK_SUPPORT_GPU
    case 'p': {
        GrContext* grContext = this->getGrContext();
        if (grContext) {
            size_t cacheBytes;
            grContext->getResourceCacheUsage(nullptr, &cacheBytes);
            grContext->freeGpuResources();
            SkDebugf("Purged %d bytes from the GPU resource cache.\n", cacheBytes);
        }
    }
        return true;
#endif
    default:
        break;
    }

    if (fAppMenu->handleKeyEquivalent(uni) || fSlideMenu->handleKeyEquivalent(uni)) {
=======
        case 27:    // ESC
            gAnimTimer.stop();
            if (this->sendAnimatePulse()) {
                this->inval(NULL);
            }
            break;
        case ' ':
            gAnimTimer.togglePauseResume();
            if (this->sendAnimatePulse()) {
                this->inval(NULL);
            }
            break;
        case 'B':
            post_event_to_sink(SkNEW_ARGS(SkEvent, ("PictFileView::toggleBBox")), curr_view(this));
            // Cannot call updateTitle() synchronously, because the toggleBBox event is still in
            // the queue.
            post_event_to_sink(SkNEW_ARGS(SkEvent, (gUpdateWindowTitleEvtName)), this);
            this->inval(NULL);
            break;
        case 'D':
            toggleDistanceFieldFonts();
            break;
        case 'f':
            // only
            toggleFPS();
            break;
        case 'F':
            FLAGS_portableFonts ^= true;
            this->inval(NULL);
            break;
        case 'g':
            fRequestGrabImage = true;
            this->inval(NULL);
            break;
        case 'G':
            gShowGMBounds = !gShowGMBounds;
            post_event_to_sink(GMSampleView::NewShowSizeEvt(gShowGMBounds),
                            curr_view(this));
            this->inval(NULL);
            break;
        case 'i':
            this->zoomIn();
            break;
        case 'o':
            this->zoomOut();
            break;
        case 'r':
            fRotate = !fRotate;
            this->inval(NULL);
            this->updateTitle();
            return true;
        case 'k':
            fPerspAnim = !fPerspAnim;
            this->inval(NULL);
            this->updateTitle();
            return true;
#if SK_SUPPORT_GPU
        case 'p':
            {
                GrContext* grContext = this->getGrContext();
                if (grContext) {
                    size_t cacheBytes;
                    grContext->getResourceCacheUsage(NULL, &cacheBytes);
                    grContext->freeGpuResources();
                    SkDebugf("Purged %d bytes from the GPU resource cache.\n", cacheBytes);
                }
            }
            return true;
#endif
        default:
            break;
    }

    if (fAppMenu->handleKeyEquivalent(uni)|| fSlideMenu->handleKeyEquivalent(uni)) {
>>>>>>> miniblink49
        this->onUpdateMenu(fAppMenu);
        this->onUpdateMenu(fSlideMenu);
        return true;
    }
    return this->INHERITED::onHandleChar(uni);
}

<<<<<<< HEAD
void SampleWindow::setDeviceType(DeviceType type)
{
=======
void SampleWindow::setDeviceType(DeviceType type) {
>>>>>>> miniblink49
    if (type == fDeviceType)
        return;

    fDevManager->tearDownBackend(this);
<<<<<<< HEAD
    fDeviceType = type;
    fDevManager->setUpBackend(this, fMSAASampleCount, fDeepColor);

    this->updateTitle();
    this->inval(nullptr);
}

void SampleWindow::setDeviceColorType(SkColorType ct, sk_sp<SkColorSpace> cs)
{
    this->setColorType(ct, std::move(cs));

    fDevManager->tearDownBackend(this);
    fDevManager->setUpBackend(this, fMSAASampleCount, fDeepColor);

    this->updateTitle();
    this->inval(nullptr);
}

void SampleWindow::toggleSlideshow()
{
=======

    fDeviceType = type;

    fDevManager->setUpBackend(this, fMSAASampleCount);

    this->updateTitle();
    this->inval(NULL);
}

void SampleWindow::toggleSlideshow() {
>>>>>>> miniblink49
    fAnimating = !fAnimating;
    this->postAnimatingEvent();
    this->updateTitle();
}

<<<<<<< HEAD
void SampleWindow::toggleRendering()
{
    this->setDeviceType(cycle_devicetype(fDeviceType));
    this->updateTitle();
    this->inval(nullptr);
}

void SampleWindow::toggleFPS()
{
    fMeasureFPS = !fMeasureFPS;
    this->updateTitle();
    this->inval(nullptr);
}

void SampleWindow::toggleDistanceFieldFonts()
{
    // reset backend
    fDevManager->tearDownBackend(this);
    fDevManager->setUpBackend(this, fMSAASampleCount, fDeepColor);

    SkSurfaceProps props = this->getSurfaceProps();
    uint32_t flags = props.flags() ^ SkSurfaceProps::kUseDeviceIndependentFonts_Flag;
    this->setSurfaceProps(SkSurfaceProps(flags, props.pixelGeometry()));

    this->updateTitle();
    this->inval(nullptr);
}

void SampleWindow::setPixelGeometry(int pixelGeometryIndex)
{
    // reset backend
    fDevManager->tearDownBackend(this);
    fDevManager->setUpBackend(this, fMSAASampleCount, fDeepColor);

    const SkSurfaceProps& oldProps = this->getSurfaceProps();
    SkSurfaceProps newProps(oldProps.flags(), SkSurfaceProps::kLegacyFontHost_InitType);
    if (pixelGeometryIndex > 0) {
        newProps = SkSurfaceProps(oldProps.flags(),
            gPixelGeometryStates[pixelGeometryIndex].pixelGeometry);
    }
    this->setSurfaceProps(newProps);

    this->updateTitle();
    this->inval(nullptr);
=======
void SampleWindow::toggleRendering() {
    this->setDeviceType(cycle_devicetype(fDeviceType));
    this->updateTitle();
    this->inval(NULL);
}

void SampleWindow::toggleFPS() {
    fMeasureFPS = !fMeasureFPS;
    this->updateTitle();
    this->inval(NULL);
}

void SampleWindow::toggleDistanceFieldFonts() {
    SkSurfaceProps props = this->getSurfaceProps();
    uint32_t flags = props.flags() ^ SkSurfaceProps::kUseDistanceFieldFonts_Flag;
    this->setSurfaceProps(SkSurfaceProps(flags, props.pixelGeometry()));

    this->updateTitle();
    this->inval(NULL);
>>>>>>> miniblink49
}

#include "SkDumpCanvas.h"

<<<<<<< HEAD
bool SampleWindow::onHandleKey(SkKey key)
{
=======
bool SampleWindow::onHandleKey(SkKey key) {
>>>>>>> miniblink49
    {
        SkView* view = curr_view(this);
        if (view) {
            SkEvent evt(gKeyEvtName);
            evt.setFast32(key);
            if (view->doQuery(&evt)) {
                return true;
            }
        }
    }
<<<<<<< HEAD

    int dx = 0xFF;
    int dy = 0xFF;

    switch (key) {
    case kRight_SkKey:
        if (this->nextSample()) {
            return true;
        }
        break;
    case kLeft_SkKey:
        if (this->previousSample()) {
            return true;
        }
        return true;
    case kUp_SkKey:
        this->changeZoomLevel(1.f / 32.f);
        return true;
    case kDown_SkKey:
        this->changeZoomLevel(-1.f / 32.f);
        return true;
    case kOK_SkKey: {
        SkString title;
        if (curr_title(this, &title)) {
            writeTitleToPrefs(title.c_str());
        }
        return true;
    }
    case kBack_SkKey:
        this->showOverview();
        return true;

    case k5_SkKey:
        dx = 0;
        dy = 0;
        break;
    case k8_SkKey:
        dx = 0;
        dy = -1;
        break;
    case k6_SkKey:
        dx = 1;
        dy = 0;
        break;
    case k2_SkKey:
        dx = 0;
        dy = 1;
        break;
    case k4_SkKey:
        dx = -1;
        dy = 0;
        break;
    case k7_SkKey:
        dx = -1;
        dy = -1;
        break;
    case k9_SkKey:
        dx = 1;
        dy = -1;
        break;
    case k3_SkKey:
        dx = 1;
        dy = 1;
        break;
    case k1_SkKey:
        dx = -1;
        dy = 1;
        break;

    default:
        break;
    }

    if (0xFF != dx && 0xFF != dy) {
        this->changeOffset({ SkIntToScalar(dx / 32.0f), SkIntToScalar(dy / 32.0f) });
        return true;
    }

=======
    switch (key) {
        case kRight_SkKey:
            if (this->nextSample()) {
                return true;
            }
            break;
        case kLeft_SkKey:
            if (this->previousSample()) {
                return true;
            }
            return true;
        case kUp_SkKey:
            this->changeZoomLevel(1.f / 32.f);
            return true;
        case kDown_SkKey:
            this->changeZoomLevel(-1.f / 32.f);
            return true;
        case kOK_SkKey: {
            SkString title;
            if (curr_title(this, &title)) {
                writeTitleToPrefs(title.c_str());
            }
            return true;
        }
        case kBack_SkKey:
            this->showOverview();
            return true;
        default:
            break;
    }
>>>>>>> miniblink49
    return this->INHERITED::onHandleKey(key);
}

///////////////////////////////////////////////////////////////////////////////

static const char gGestureClickType[] = "GestureClickType";

bool SampleWindow::onDispatchClick(int x, int y, Click::State state,
<<<<<<< HEAD
    void* owner, unsigned modi)
{
=======
        void* owner, unsigned modi) {
>>>>>>> miniblink49
    if (Click::kMoved_State == state) {
        updatePointer(x, y);
    }
    int w = SkScalarRoundToInt(this->width());
    int h = SkScalarRoundToInt(this->height());

    // check for the resize-box
    if (w - x < 16 && h - y < 16) {
<<<<<<< HEAD
        return false; // let the OS handle the click
    } else if (fMagnify) {
        //it's only necessary to update the drawing if there's a click
        this->inval(nullptr);
=======
        return false;   // let the OS handle the click
    }
    else if (fMagnify) {
        //it's only necessary to update the drawing if there's a click
        this->inval(NULL);
>>>>>>> miniblink49
        return false; //prevent dragging while magnify is enabled
    } else {
        // capture control+option, and trigger debugger
        if ((modi & kControl_SkModifierKey) && (modi & kOption_SkModifierKey)) {
            if (Click::kDown_State == state) {
                SkEvent evt("debug-hit-test");
                evt.setS32("debug-hit-test-x", x);
                evt.setS32("debug-hit-test-y", y);
                curr_view(this)->doEvent(evt);
            }
            return true;
        } else {
            return this->INHERITED::onDispatchClick(x, y, state, owner, modi);
        }
    }
}

class GestureClick : public SkView::Click {
public:
<<<<<<< HEAD
    GestureClick(SkView* target)
        : SkView::Click(target)
    {
        this->setType(gGestureClickType);
    }

    static bool IsGesture(Click* click)
    {
=======
    GestureClick(SkView* target) : SkView::Click(target) {
        this->setType(gGestureClickType);
    }

    static bool IsGesture(Click* click) {
>>>>>>> miniblink49
        return click->isType(gGestureClickType);
    }
};

SkView::Click* SampleWindow::onFindClickHandler(SkScalar x, SkScalar y,
<<<<<<< HEAD
    unsigned modi)
{
    return new GestureClick(this);
}

bool SampleWindow::onClick(Click* click)
{
=======
                                                unsigned modi) {
    return new GestureClick(this);
}

bool SampleWindow::onClick(Click* click) {
>>>>>>> miniblink49
    if (GestureClick::IsGesture(click)) {
        float x = static_cast<float>(click->fICurr.fX);
        float y = static_cast<float>(click->fICurr.fY);

        switch (click->fState) {
<<<<<<< HEAD
        case SkView::Click::kDown_State:
            fGesture.touchBegin(click->fOwner, x, y);
            break;
        case SkView::Click::kMoved_State:
            fGesture.touchMoved(click->fOwner, x, y);
            this->updateMatrix();
            break;
        case SkView::Click::kUp_State:
            fGesture.touchEnd(click->fOwner);
            this->updateMatrix();
            break;
=======
            case SkView::Click::kDown_State:
                fGesture.touchBegin(click->fOwner, x, y);
                break;
            case SkView::Click::kMoved_State:
                fGesture.touchMoved(click->fOwner, x, y);
                this->updateMatrix();
                break;
            case SkView::Click::kUp_State:
                fGesture.touchEnd(click->fOwner);
                this->updateMatrix();
                break;
>>>>>>> miniblink49
        }
        return true;
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SampleWindow::loadView(SkView* view)
{
=======
void SampleWindow::loadView(SkView* view) {
>>>>>>> miniblink49
    SkView::F2BIter iter(this);
    SkView* prev = iter.next();
    if (prev) {
        prev->detachFromParent();
    }

    view->setVisibleP(true);
    view->setClipToBounds(false);
    this->attachChildToFront(view)->unref();
    view->setSize(this->width(), this->height());

    //repopulate the slide menu when a view is loaded
    fSlideMenu->reset();

<<<<<<< HEAD
=======
    (void)SampleView::SetUsePipe(view, fPipeState);
    if (SampleView::IsSampleView(view)) {
        SampleView* sampleView = (SampleView*)view;
        sampleView->requestMenu(fSlideMenu);
        sampleView->onTileSizeChanged(this->tileSize());
    }
>>>>>>> miniblink49
    this->onUpdateMenu(fSlideMenu);
    this->updateTitle();
}

static const char* gDeviceTypePrefix[] = {
    "raster: ",
<<<<<<< HEAD
=======
    "picture: ",
>>>>>>> miniblink49
#if SK_SUPPORT_GPU
    "opengl: ",
#if SK_ANGLE
    "angle: ",
#endif // SK_ANGLE
#endif // SK_SUPPORT_GPU
<<<<<<< HEAD
};
static_assert(SK_ARRAY_COUNT(gDeviceTypePrefix) == SampleWindow::kDeviceTypeCnt,
    "array_size_mismatch");

static const char* trystate_str(SkOSMenu::TriState state,
    const char trueStr[], const char falseStr[])
{
=======
    "deferred: ",
};
SK_COMPILE_ASSERT(SK_ARRAY_COUNT(gDeviceTypePrefix) == SampleWindow::kDeviceTypeCnt,
                  array_size_mismatch);

static const char* trystate_str(SkOSMenu::TriState state,
                                const char trueStr[], const char falseStr[]) {
>>>>>>> miniblink49
    if (SkOSMenu::kOnState == state) {
        return trueStr;
    } else if (SkOSMenu::kOffState == state) {
        return falseStr;
    }
<<<<<<< HEAD
    return nullptr;
}

bool SampleWindow::getRawTitle(SkString* title)
{
    return curr_title(this, title);
}

void SampleWindow::updateTitle()
{
=======
    return NULL;
}

bool SampleWindow::getRawTitle(SkString* title) {
    return curr_title(this, title);
}

void SampleWindow::updateTitle() {
>>>>>>> miniblink49
    SkString title;
    if (!this->getRawTitle(&title)) {
        title.set("<unknown>");
    }

    title.prepend(gDeviceTypePrefix[fDeviceType]);

<<<<<<< HEAD
=======
    title.prepend(" ");
    title.prepend(sk_tool_utils::colortype_name(this->getBitmap().colorType()));

>>>>>>> miniblink49
    if (fTilingMode != kNo_Tiling) {
        title.prependf("<T: %s> ", gTilingInfo[fTilingMode].label);
    }
    if (fAnimating) {
        title.prepend("<A> ");
    }
    if (fRotate) {
        title.prepend("<R> ");
    }
    if (fPerspAnim) {
        title.prepend("<K> ");
    }
<<<<<<< HEAD
    if (this->getSurfaceProps().flags() & SkSurfaceProps::kUseDeviceIndependentFonts_Flag) {
        title.prepend("<DIF> ");
    }
    if (fUsePicture) {
        title.prepend("<P> ");
=======
    if (this->getSurfaceProps().flags() & SkSurfaceProps::kUseDistanceFieldFonts_Flag) {
        title.prepend("<DFF> ");
>>>>>>> miniblink49
    }

    title.prepend(trystate_str(fLCDState, "LCD ", "lcd "));
    title.prepend(trystate_str(fAAState, "AA ", "aa "));
    title.prepend(gFilterQualityStates[fFilterQualityIndex].fLabel);
    title.prepend(trystate_str(fSubpixelState, "S ", "s "));
<<<<<<< HEAD
    title.prepend(fFlipAxis & kFlipAxis_X ? "X " : nullptr);
    title.prepend(fFlipAxis & kFlipAxis_Y ? "Y " : nullptr);
    title.prepend(gHintingStates[fHintingState].label);
    title.prepend(gPixelGeometryStates[fPixelGeometryIndex].label);

    if (fOffset.fX || fOffset.fY) {
        title.prependf("(%.2f, %.2f) ", SkScalarToFloat(fOffset.fX), SkScalarToFloat(fOffset.fY));
    }
=======
    title.prepend(fFlipAxis & kFlipAxis_X ? "X " : NULL);
    title.prepend(fFlipAxis & kFlipAxis_Y ? "Y " : NULL);
    title.prepend(gHintingStates[fHintingState].label);

>>>>>>> miniblink49
    if (fZoomLevel) {
        title.prependf("{%.2f} ", SkScalarToFloat(fZoomLevel));
    }

    if (fMeasureFPS) {
<<<<<<< HEAD
        title.appendf(" %8.4f ms", fMeasureFPS_Time / (float)FPS_REPEAT_COUNT);
    }

#if SK_SUPPORT_GPU
    if (IsGpuDeviceType(fDeviceType) && fDevManager && fDevManager->getGrRenderTarget() && fDevManager->getGrRenderTarget()->numColorSamples() > 0) {
        title.appendf(" [MSAA: %d]",
            fDevManager->getGrRenderTarget()->numColorSamples());
    }
#endif

    title.appendf(" %s", find_config_name(this->info()));

    if (fDevManager && fDevManager->getColorBits() > 24) {
        title.appendf(" %d bpc", fDevManager->getColorBits());
    }

    this->setTitle(title.c_str());
}

void SampleWindow::onSizeChange()
{
=======
        title.appendf(" %8.3f ms", fMeasureFPS_Time / (float)FPS_REPEAT_COUNT);
    }

    SkView* view = curr_view(this);
    if (SampleView::IsSampleView(view)) {
        switch (fPipeState) {
            case SkOSMenu::kOnState:
                title.prepend("<Pipe> ");
                break;
            case SkOSMenu::kMixedState:
                title.prepend("<Tiled Pipe> ");
                break;

            default:
                break;
        }
        title.prepend("! ");
    }

#if SK_SUPPORT_GPU
    if (IsGpuDeviceType(fDeviceType) &&
        fDevManager &&
        fDevManager->getGrRenderTarget() &&
        fDevManager->getGrRenderTarget()->numColorSamples() > 0) {
        title.appendf(" [MSAA: %d]",
                       fDevManager->getGrRenderTarget()->numColorSamples());
    }
#endif

    this->setTitle(title.c_str());
}

void SampleWindow::onSizeChange() {
>>>>>>> miniblink49
    this->INHERITED::onSizeChange();

    SkView::F2BIter iter(this);
    SkView* view = iter.next();
    view->setSize(this->width(), this->height());

    // rebuild our clippath
    {
        const SkScalar W = this->width();
        const SkScalar H = this->height();

        fClipPath.reset();
#if 0
        for (SkScalar y = SK_Scalar1; y < H; y += SkIntToScalar(32)) {
            SkRect r;
            r.set(SK_Scalar1, y, SkIntToScalar(30), y + SkIntToScalar(30));
            for (; r.fLeft < W; r.offset(SkIntToScalar(32), 0))
                fClipPath.addRect(r);
        }
#else
        SkRect r;
        r.set(0, 0, W, H);
        fClipPath.addRect(r, SkPath::kCCW_Direction);
<<<<<<< HEAD
        r.set(W / 4, H / 4, W * 3 / 4, H * 3 / 4);
=======
        r.set(W/4, H/4, W*3/4, H*3/4);
>>>>>>> miniblink49
        fClipPath.addRect(r, SkPath::kCW_Direction);
#endif
    }

    fZoomCenterX = SkScalarHalf(this->width());
    fZoomCenterY = SkScalarHalf(this->height());

#ifdef SK_BUILD_FOR_ANDROID
    // FIXME: The first draw after a size change does not work on Android, so
    // we post an invalidate.
    this->postInvalDelay();
#endif
<<<<<<< HEAD
    this->updateTitle(); // to refresh our config
=======
    this->updateTitle();    // to refresh our config
>>>>>>> miniblink49
    fDevManager->windowSizeChanged(this);

    if (fTilingMode != kNo_Tiling && SampleView::IsSampleView(view)) {
        ((SampleView*)view)->onTileSizeChanged(this->tileSize());
    }
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
template <typename T>
void SkTBSort(T array[], int count)
{
    for (int i = 1; i < count - 1; i++) {
        bool didSwap = false;
        for (int j = count - 1; j > i; --j) {
            if (array[j] < array[j - 1]) {
                T tmp(array[j - 1]);
                array[j - 1] = array[j];
=======
static const char is_sample_view_tag[] = "sample-is-sample-view";
static const char repeat_count_tag[] = "sample-set-repeat-count";
static const char set_use_pipe_tag[] = "sample-set-use-pipe";

bool SampleView::IsSampleView(SkView* view) {
    SkEvent evt(is_sample_view_tag);
    return view->doQuery(&evt);
}

bool SampleView::SetRepeatDraw(SkView* view, int count) {
    SkEvent evt(repeat_count_tag);
    evt.setFast32(count);
    return view->doEvent(evt);
}

bool SampleView::SetUsePipe(SkView* view, SkOSMenu::TriState state) {
    SkEvent evt;
    evt.setS32(set_use_pipe_tag, state);
    return view->doEvent(evt);
}

bool SampleView::onEvent(const SkEvent& evt) {
    if (evt.isType(repeat_count_tag)) {
        fRepeatCount = evt.getFast32();
        return true;
    }

    int32_t pipeHolder;
    if (evt.findS32(set_use_pipe_tag, &pipeHolder)) {
        fPipeState = static_cast<SkOSMenu::TriState>(pipeHolder);
        return true;
    }

    return this->INHERITED::onEvent(evt);
}

bool SampleView::onQuery(SkEvent* evt) {
    if (evt->isType(is_sample_view_tag)) {
        return true;
    }
    return this->INHERITED::onQuery(evt);
}


class SimplePC : public SkGPipeController {
public:
    SimplePC(SkCanvas* target);
    ~SimplePC();

    virtual void* requestBlock(size_t minRequest, size_t* actual);
    virtual void notifyWritten(size_t bytes);

private:
    SkGPipeReader   fReader;
    void*           fBlock;
    size_t          fBlockSize;
    size_t          fBytesWritten;
    int             fAtomsWritten;
    SkGPipeReader::Status   fStatus;

    size_t        fTotalWritten;
};

SimplePC::SimplePC(SkCanvas* target) : fReader(target) {
    fBlock = NULL;
    fBlockSize = fBytesWritten = 0;
    fStatus = SkGPipeReader::kDone_Status;
    fTotalWritten = 0;
    fAtomsWritten = 0;
    fReader.setBitmapDecoder(&SkImageDecoder::DecodeMemory);
}

SimplePC::~SimplePC() {
//    SkASSERT(SkGPipeReader::kDone_Status == fStatus);
    if (fTotalWritten) {
        SkDebugf("--- %d bytes %d atoms, status %d\n", fTotalWritten,
                 fAtomsWritten, fStatus);
#ifdef  PIPE_FILE
        //File is open in append mode
        FILE* f = fopen(FILE_PATH, "ab");
        SkASSERT(f != NULL);
        fwrite((const char*)fBlock + fBytesWritten, 1, bytes, f);
        fclose(f);
#endif
#ifdef PIPE_NET
        if (fAtomsWritten > 1 && fTotalWritten > 4) { //ignore done
            gServer.acceptConnections();
            gServer.writePacket(fBlock, fTotalWritten);
        }
#endif
    }
    sk_free(fBlock);
}

void* SimplePC::requestBlock(size_t minRequest, size_t* actual) {
    sk_free(fBlock);

    fBlockSize = minRequest * 4;
    fBlock = sk_malloc_throw(fBlockSize);
    fBytesWritten = 0;
    *actual = fBlockSize;
    return fBlock;
}

void SimplePC::notifyWritten(size_t bytes) {
    SkASSERT(fBytesWritten + bytes <= fBlockSize);
    fStatus = fReader.playback((const char*)fBlock + fBytesWritten, bytes);
    SkASSERT(SkGPipeReader::kError_Status != fStatus);
    fBytesWritten += bytes;
    fTotalWritten += bytes;

    fAtomsWritten += 1;
}

void SampleView::draw(SkCanvas* canvas) {
    if (SkOSMenu::kOffState == fPipeState) {
        this->INHERITED::draw(canvas);
    } else {
        SkGPipeWriter writer;
        SimplePC controller(canvas);
        SkBitmap bitmap = capture_bitmap(canvas);
        TiledPipeController tc(bitmap, &SkImageDecoder::DecodeMemory, &canvas->getTotalMatrix());
        SkGPipeController* pc;
        if (SkOSMenu::kMixedState == fPipeState) {
            pc = &tc;
        } else {
            pc = &controller;
        }
        uint32_t flags = SkGPipeWriter::kCrossProcess_Flag;

        canvas = writer.startRecording(pc, flags);
        //Must draw before controller goes out of scope and sends data
        this->INHERITED::draw(canvas);
        //explicitly end recording to ensure writer is flushed before the memory
        //is freed in the deconstructor of the controller
        writer.endRecording();
    }
}

void SampleView::onDraw(SkCanvas* canvas) {
    if (!fHaveCalledOnceBeforeDraw) {
        fHaveCalledOnceBeforeDraw = true;
        this->onOnceBeforeDraw();
    }
    this->onDrawBackground(canvas);

    for (int i = 0; i < fRepeatCount; i++) {
        SkAutoCanvasRestore acr(canvas, true);
        this->onDrawContent(canvas);
    }
}

void SampleView::onDrawBackground(SkCanvas* canvas) {
    canvas->drawColor(fBGColor);
}

///////////////////////////////////////////////////////////////////////////////

template <typename T> void SkTBSort(T array[], int count) {
    for (int i = 1; i < count - 1; i++) {
        bool didSwap = false;
        for (int j = count - 1; j > i; --j) {
            if (array[j] < array[j-1]) {
                T tmp(array[j-1]);
                array[j-1] = array[j];
>>>>>>> miniblink49
                array[j] = tmp;
                didSwap = true;
            }
        }
        if (!didSwap) {
            break;
        }
    }

    for (int k = 0; k < count - 1; k++) {
<<<<<<< HEAD
        SkASSERT(!(array[k + 1] < array[k]));
=======
        SkASSERT(!(array[k+1] < array[k]));
>>>>>>> miniblink49
    }
}

#include "SkRandom.h"

<<<<<<< HEAD
static void rand_rect(SkIRect* rect, SkRandom& rand)
{
    int bits = 8;
    int shift = 32 - bits;
    rect->set(rand.nextU() >> shift, rand.nextU() >> shift,
        rand.nextU() >> shift, rand.nextU() >> shift);
    rect->sort();
}

static void dumpRect(const SkIRect& r)
{
    SkDebugf(" { %d, %d, %d, %d },\n",
        r.fLeft, r.fTop,
        r.fRight, r.fBottom);
}

static void test_rects(const SkIRect rect[], int count)
{
=======
static void rand_rect(SkIRect* rect, SkRandom& rand) {
    int bits = 8;
    int shift = 32 - bits;
    rect->set(rand.nextU() >> shift, rand.nextU() >> shift,
              rand.nextU() >> shift, rand.nextU() >> shift);
    rect->sort();
}

static void dumpRect(const SkIRect& r) {
    SkDebugf(" { %d, %d, %d, %d },\n",
             r.fLeft, r.fTop,
             r.fRight, r.fBottom);
}

static void test_rects(const SkIRect rect[], int count) {
>>>>>>> miniblink49
    SkRegion rgn0, rgn1;

    for (int i = 0; i < count; i++) {
        rgn0.op(rect[i], SkRegion::kUnion_Op);
<<<<<<< HEAD
        //   dumpRect(rect[i]);
=======
     //   dumpRect(rect[i]);
>>>>>>> miniblink49
    }
    rgn1.setRects(rect, count);

    if (rgn0 != rgn1) {
        SkDebugf("\n");
        for (int i = 0; i < count; i++) {
            dumpRect(rect[i]);
        }
        SkDebugf("\n");
    }
}

<<<<<<< HEAD
static void test()
{
=======
static void test() {
>>>>>>> miniblink49
    size_t i;

    const SkIRect r0[] = {
        { 0, 0, 1, 1 },
        { 2, 2, 3, 3 },
    };
    const SkIRect r1[] = {
        { 0, 0, 1, 3 },
        { 1, 1, 2, 2 },
        { 2, 0, 3, 3 },
    };
    const SkIRect r2[] = {
        { 0, 0, 1, 2 },
        { 2, 1, 3, 3 },
        { 4, 0, 5, 1 },
        { 6, 0, 7, 4 },
    };

    static const struct {
        const SkIRect* fRects;
<<<<<<< HEAD
        int fCount;
=======
        int            fCount;
>>>>>>> miniblink49
    } gRecs[] = {
        { r0, SK_ARRAY_COUNT(r0) },
        { r1, SK_ARRAY_COUNT(r1) },
        { r2, SK_ARRAY_COUNT(r2) },
    };

    for (i = 0; i < SK_ARRAY_COUNT(gRecs); i++) {
        test_rects(gRecs[i].fRects, gRecs[i].fCount);
    }

    SkRandom rand;
    for (i = 0; i < 10000; i++) {
        SkRegion rgn0, rgn1;

        const int N = 8;
        SkIRect rect[N];
        for (int j = 0; j < N; j++) {
            rand_rect(&rect[j], rand);
        }
        test_rects(rect, N);
    }
}

// FIXME: this should be in a header
SkOSWindow* create_sk_window(void* hwnd, int argc, char** argv);
<<<<<<< HEAD
SkOSWindow* create_sk_window(void* hwnd, int argc, char** argv)
{
    if (false) { // avoid bit rot, suppress warning
        test();
    }
    return new SampleWindow(hwnd, argc, argv, nullptr);
=======
SkOSWindow* create_sk_window(void* hwnd, int argc, char** argv) {
    if (false) { // avoid bit rot, suppress warning
        test();
    }
    return new SampleWindow(hwnd, argc, argv, NULL);
>>>>>>> miniblink49
}

// FIXME: this should be in a header
void get_preferred_size(int* x, int* y, int* width, int* height);
<<<<<<< HEAD
void get_preferred_size(int* x, int* y, int* width, int* height)
{
=======
void get_preferred_size(int* x, int* y, int* width, int* height) {
>>>>>>> miniblink49
    *x = 10;
    *y = 50;
    *width = 640;
    *height = 480;
}

#ifdef SK_BUILD_FOR_IOS
#include "SkApplication.h"
<<<<<<< HEAD
IOS_launch_type set_cmd_line_args(int, char*[], const char* resourceDir)
{
=======
IOS_launch_type set_cmd_line_args(int , char *[], const char* resourceDir) {
>>>>>>> miniblink49
    SetResourcePath(resourceDir);
    return kApplication__iOSLaunchType;
}
#endif

<<<<<<< HEAD
void application_init()
{
=======
void application_init() {
>>>>>>> miniblink49
//    setenv("ANDROID_ROOT", "../../../data", 0);
#ifdef SK_BUILD_FOR_MAC
    setenv("ANDROID_ROOT", "/android/device/data", 0);
#endif
    SkGraphics::Init();
    SkEvent::Init();
}

<<<<<<< HEAD
void application_term()
{
    SkEvent::Term();
=======
void application_term() {
    SkEvent::Term();
    SkGraphics::Term();
>>>>>>> miniblink49
}
