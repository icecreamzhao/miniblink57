/*
 * Copyright 2013 Google Inc.
 *
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 */
<<<<<<< HEAD
#include <include/libplatform/libplatform.h>
#include <v8.h>

=======
#include <v8.h>
#include <include/libplatform/libplatform.h>

#include "SkV8Example.h"
>>>>>>> miniblink49
#include "Global.h"
#include "JsContext.h"
#include "Path2D.h"
#include "Path2DBuilder.h"
<<<<<<< HEAD
#include "SkV8Example.h"

#include "GrContext.h"
#include "GrRenderTarget.h"
=======

#include "gl/GrGLUtil.h"
#include "gl/GrGLDefines.h"
#include "gl/GrGLInterface.h"
#include "GrRenderTarget.h"
#include "GrContext.h"
>>>>>>> miniblink49
#include "SkApplication.h"
#include "SkCommandLineFlags.h"
#include "SkData.h"
#include "SkDraw.h"
#include "SkGpuDevice.h"
#include "SkGraphics.h"
#include "SkScalar.h"
#include "SkSurface.h"
<<<<<<< HEAD
#include "gl/GrGLDefines.h"
#include "gl/GrGLInterface.h"
#include "gl/GrGLUtil.h"
=======

>>>>>>> miniblink49

DEFINE_string2(infile, i, NULL, "Name of file to load JS from.\n");
DEFINE_bool(gpu, true, "Use the GPU for rendering.");

<<<<<<< HEAD
void application_init()
{
=======
void application_init() {
>>>>>>> miniblink49
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

SkV8ExampleWindow::SkV8ExampleWindow(void* hwnd, JsContext* context)
    : INHERITED(hwnd)
    , fJsContext(context)
#if SK_SUPPORT_GPU
    , fCurContext(NULL)
    , fCurIntf(NULL)
    , fCurRenderTarget(NULL)
    , fCurSurface(NULL)
#endif
{
<<<<<<< HEAD
=======
    this->setColorType(kBGRA_8888_SkColorType);
>>>>>>> miniblink49
    this->setVisibleP(true);
    this->setClipToBounds(false);

#if SK_SUPPORT_GPU
    this->windowSizeChanged();
#endif
}

<<<<<<< HEAD
SkV8ExampleWindow::~SkV8ExampleWindow()
{
=======
SkV8ExampleWindow::~SkV8ExampleWindow() {
>>>>>>> miniblink49
#if SK_SUPPORT_GPU
    SkSafeUnref(fCurContext);
    SkSafeUnref(fCurIntf);
    SkSafeUnref(fCurRenderTarget);
    SkSafeUnref(fCurSurface);
#endif
}

#if SK_SUPPORT_GPU
<<<<<<< HEAD
void SkV8ExampleWindow::windowSizeChanged()
{
    if (FLAGS_gpu) {
        SkOSWindow::AttachmentInfo attachmentInfo;
        bool result = this->attach(
            SkOSWindow::kNativeGL_BackEndType, 0, false, &attachmentInfo);
=======
void SkV8ExampleWindow::windowSizeChanged() {
    if (FLAGS_gpu) {
        SkOSWindow::AttachmentInfo attachmentInfo;
        bool result = this->attach(
                SkOSWindow::kNativeGL_BackEndType, 0, &attachmentInfo);
>>>>>>> miniblink49
        if (!result) {
            printf("Failed to attach.");
            exit(1);
        }

        fCurIntf = GrGLCreateNativeInterface();
        fCurContext = GrContext::Create(
<<<<<<< HEAD
            kOpenGL_GrBackend, (GrBackendContext)fCurIntf);
=======
                kOpenGL_GrBackend, (GrBackendContext) fCurIntf);
>>>>>>> miniblink49
        if (NULL == fCurIntf || NULL == fCurContext) {
            printf("Failed to initialize GL.");
            exit(1);
        }

        GrBackendRenderTargetDesc desc;
        desc.fWidth = SkScalarRoundToInt(this->width());
        desc.fHeight = SkScalarRoundToInt(this->height());
        desc.fConfig = kSkia8888_GrPixelConfig;
        desc.fOrigin = kBottomLeft_GrSurfaceOrigin;
        desc.fSampleCnt = attachmentInfo.fSampleCount;
        desc.fStencilBits = attachmentInfo.fStencilBits;
        GrGLint buffer;
        GR_GL_GetIntegerv(fCurIntf, GR_GL_FRAMEBUFFER_BINDING, &buffer);
        desc.fRenderTargetHandle = buffer;

        SkSafeUnref(fCurRenderTarget);
        fCurRenderTarget = fCurContext->wrapBackendRenderTarget(desc);
        SkSafeUnref(fCurSurface);
        fCurSurface = SkSurface::NewRenderTargetDirect(fCurRenderTarget);
    }
}
#endif

#if SK_SUPPORT_GPU
<<<<<<< HEAD
SkSurface* SkV8ExampleWindow::createSurface()
{
=======
SkSurface* SkV8ExampleWindow::createSurface() {
>>>>>>> miniblink49
    if (FLAGS_gpu) {
        // Increase the ref count since callers of createSurface put the
        // results in a SkAutoTUnref.
        fCurSurface->ref();
        return fCurSurface;
    } else {
        return this->INHERITED::createSurface();
    }
}
#endif

<<<<<<< HEAD
void SkV8ExampleWindow::onSizeChange()
{
=======
void SkV8ExampleWindow::onSizeChange() {
>>>>>>> miniblink49
    this->INHERITED::onSizeChange();

#if SK_SUPPORT_GPU
    this->windowSizeChanged();
#endif
}

Global* global = NULL;

<<<<<<< HEAD
void SkV8ExampleWindow::onDraw(SkCanvas* canvas)
{
=======
void SkV8ExampleWindow::onDraw(SkCanvas* canvas) {
>>>>>>> miniblink49

    canvas->save();
    canvas->drawColor(SK_ColorWHITE);

    // Now jump into JS and call the onDraw(canvas) method defined there.
    fJsContext->onDraw(canvas);

    canvas->restore();

    this->INHERITED::onDraw(canvas);

#if SK_SUPPORT_GPU
    if (FLAGS_gpu) {
        fCurContext->flush();
        this->present();
    }
#endif
}

#ifdef SK_BUILD_FOR_WIN
<<<<<<< HEAD
void SkV8ExampleWindow::onHandleInval(const SkIRect& rect)
{
=======
void SkV8ExampleWindow::onHandleInval(const SkIRect& rect) {
>>>>>>> miniblink49
    RECT winRect;
    winRect.top = rect.top();
    winRect.bottom = rect.bottom();
    winRect.right = rect.right();
    winRect.left = rect.left();
    InvalidateRect((HWND)this->getHWND(), &winRect, false);
}
#endif

<<<<<<< HEAD
SkOSWindow* create_sk_window(void* hwnd, int argc, char** argv)
{
=======

SkOSWindow* create_sk_window(void* hwnd, int argc, char** argv) {
>>>>>>> miniblink49
    printf("Started\n");

    v8::V8::SetFlagsFromCommandLine(&argc, argv, true);
    SkCommandLineFlags::Parse(argc, argv);

    v8::V8::InitializeICU();
    v8::Platform* platform = v8::platform::CreateDefaultPlatform();
    v8::V8::InitializePlatform(platform);
    v8::V8::Initialize();

    v8::Isolate* isolate = v8::Isolate::New();
    v8::Isolate::Scope isolate_scope(isolate);
    v8::HandleScope handle_scope(isolate);
    isolate->Enter();

    global = new Global(isolate);

<<<<<<< HEAD
    // Set up things to look like a browser by creating
    // a console object that invokes our print function.
    const char* startupScript = "function Console() {};                   \n"
                                "Console.prototype.log = function() {     \n"
                                "  var args = Array.prototype.slice.call(arguments).join(' '); \n"
                                "  print(args);                      \n"
                                "};                                       \n"
                                "console = new Console();                 \n";
=======

    // Set up things to look like a browser by creating
    // a console object that invokes our print function.
    const char* startupScript =
            "function Console() {};                   \n"
            "Console.prototype.log = function() {     \n"
            "  var args = Array.prototype.slice.call(arguments).join(' '); \n"
            "  print(args);                      \n"
            "};                                       \n"
            "console = new Console();                 \n";
>>>>>>> miniblink49

    if (!global->parseScript(startupScript)) {
        printf("Failed to parse startup script: %s.\n", FLAGS_infile[0]);
        exit(1);
    }

<<<<<<< HEAD
    const char* script = "function onDraw(canvas) {              \n"
                         "    canvas.fillStyle = '#00FF00';      \n"
                         "    canvas.fillRect(20, 20, 100, 100); \n"
                         "    canvas.inval();                    \n"
                         "}                                      \n";
=======
    const char* script =
            "function onDraw(canvas) {              \n"
            "    canvas.fillStyle = '#00FF00';      \n"
            "    canvas.fillRect(20, 20, 100, 100); \n"
            "    canvas.inval();                    \n"
            "}                                      \n";
>>>>>>> miniblink49

    SkAutoTUnref<SkData> data;
    if (FLAGS_infile.count()) {
        data.reset(SkData::NewFromFileName(FLAGS_infile[0]));
        script = static_cast<const char*>(data->data());
    }
    if (NULL == script) {
        printf("Could not load file: %s.\n", FLAGS_infile[0]);
        exit(1);
    }
    Path2DBuilder::AddToGlobal(global);
    Path2D::AddToGlobal(global);

    if (!global->parseScript(script)) {
        printf("Failed to parse file: %s.\n", FLAGS_infile[0]);
        exit(1);
    }

<<<<<<< HEAD
=======

>>>>>>> miniblink49
    JsContext* jsContext = new JsContext(global);

    if (!jsContext->initialize()) {
        printf("Failed to initialize.\n");
        exit(1);
    }
    SkV8ExampleWindow* win = new SkV8ExampleWindow(hwnd, jsContext);
    global->setWindow(win);

    return win;
}
