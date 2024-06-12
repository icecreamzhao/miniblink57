// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/offscreencanvas/OffscreenCanvas.h"

#include "core/dom/ExceptionCode.h"
#include "core/fileapi/Blob.h"
#include "core/frame/ImageBitmap.h"
#include "core/html/ImageData.h"
#include "core/html/canvas/CanvasAsyncBlobCreator.h"
#include "core/html/canvas/CanvasContextCreationAttributes.h"
#include "core/html/canvas/CanvasRenderingContext.h"
#include "core/html/canvas/CanvasRenderingContextFactory.h"
#include "platform/graphics/Image.h"
#include "platform/graphics/ImageBuffer.h"
//#include "platform/graphics/OffscreenCanvasFrameDispatcherImpl.h"
#include "platform/graphics/StaticBitmapImage.h"
#include "platform/image-encoders/ImageEncoderUtils.h"
#include "wtf/MathExtras.h"
#include <memory>

namespace blink {

OffscreenCanvas::OffscreenCanvas(const IntSize& size)
    : m_size(size)
{
}

OffscreenCanvas* OffscreenCanvas::create(unsigned width, unsigned height)
{
    return new OffscreenCanvas(
        IntSize(clampTo<int>(width), clampTo<int>(height)));
}

OffscreenCanvas::~OffscreenCanvas() { }

void OffscreenCanvas::dispose()
{
    DebugBreak();
}

void OffscreenCanvas::setWidth(unsigned width)
{
    DebugBreak();
}

void OffscreenCanvas::setHeight(unsigned height)
{
    DebugBreak();
}

void OffscreenCanvas::setSize(const IntSize& size)
{
    DebugBreak();
}

void OffscreenCanvas::setNeutered()
{
    ASSERT(!m_context);
    m_isNeutered = true;
    m_size.setWidth(0);
    m_size.setHeight(0);
}

ImageBitmap* OffscreenCanvas::transferToImageBitmap(
    ScriptState* scriptState,
    ExceptionState& exceptionState)
{
    DebugBreak();
    return nullptr;
}

PassRefPtr<Image> OffscreenCanvas::getSourceImageForCanvas(
    SourceImageStatus* status,
    AccelerationHint hint,
    SnapshotReason reason,
    const FloatSize& size) const
{
    DebugBreak();
    return nullptr;
}

IntSize OffscreenCanvas::bitmapSourceSize() const
{
    return m_size;
}

ScriptPromise OffscreenCanvas::createImageBitmap(
    ScriptState* scriptState,
    EventTarget&,
    Optional<IntRect> cropRect,
    const ImageBitmapOptions& options,
    ExceptionState& exceptionState)
{
    DebugBreak();
    return ScriptPromise();
}

bool OffscreenCanvas::isOpaque() const
{
    if (!m_context)
        return false;
    return !m_context->creationAttributes().hasAlpha();
}

CanvasRenderingContext* OffscreenCanvas::getCanvasRenderingContext(
    ScriptState* scriptState,
    const String& id,
    const CanvasContextCreationAttributes& attributes)
{
    DebugBreak();
    return nullptr;
}

OffscreenCanvas::ContextFactoryVector&
OffscreenCanvas::renderingContextFactories()
{
    DEFINE_STATIC_LOCAL(ContextFactoryVector, s_contextFactories,
        (CanvasRenderingContext::ContextTypeCount));
    return s_contextFactories;
}

CanvasRenderingContextFactory* OffscreenCanvas::getRenderingContextFactory(
    int type)
{
    ASSERT(type < CanvasRenderingContext::ContextTypeCount);
    DebugBreak();
    return nullptr;
}

void OffscreenCanvas::registerRenderingContextFactory(
    std::unique_ptr<CanvasRenderingContextFactory> renderingContextFactory)
{
    DebugBreak();
}

bool OffscreenCanvas::originClean() const
{
    return m_originClean && !m_disableReadingFromCanvas;
}

bool OffscreenCanvas::isPaintable() const
{
    DebugBreak();
    return false;
}

bool OffscreenCanvas::isAccelerated() const
{
    DebugBreak();
    return false;
}

OffscreenCanvasFrameDispatcher* OffscreenCanvas::getOrCreateFrameDispatcher()
{
    DebugBreak();
    return nullptr;
}

ScriptPromise OffscreenCanvas::commit(RefPtr<StaticBitmapImage> image,
    bool isWebGLSoftwareRendering,
    ScriptState* scriptState)
{
    DebugBreak();
    return ScriptPromise();
}

void OffscreenCanvas::doCommit(RefPtr<StaticBitmapImage> image,
    bool isWebGLSoftwareRendering)
{
    DebugBreak();
}

void OffscreenCanvas::beginFrame()
{
    DebugBreak();
}

ScriptPromise OffscreenCanvas::convertToBlob(ScriptState* scriptState,
    const ImageEncodeOptions& options,
    ExceptionState& exceptionState)
{
    DebugBreak();
    return ScriptPromise();
}

DEFINE_TRACE(OffscreenCanvas)
{
    DebugBreak();
}

} // namespace blink
