// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef content_compositor_SoftwareOutputSurface_h
#define content_compositor_SoftwareOutputSurface_h

#include "cc/output/output_surface.h"

namespace content {

class WebPageOcBridge;
class RenderWidgetCompositor;

class SoftwareOutputSurface : public cc::OutputSurface {
public:
    static std::unique_ptr<SoftwareOutputSurface> Create(WebPageOcBridge* webPageOcBridge, RenderWidgetCompositor* renderWidgetCompositor);
    virtual ~SoftwareOutputSurface();

    // cc::OutputSurface
    virtual void EnsureBackbuffer(void) override;
    virtual void DiscardBackbuffer(void) override;
    virtual void BindFramebuffer(void) override;
    virtual cc::OverlayCandidateValidator* GetOverlayCandidateValidator(void) const override;
    virtual bool IsDisplayedAsOverlayPlane(void) const override;
    virtual unsigned int GetOverlayTextureId(void) const override;
    virtual bool SurfaceIsSuspendForRecycle(void) const override;
    virtual void Reshape(const gfx::Size&, float, const gfx::ColorSpace&, bool, bool) override;
    virtual bool HasExternalStencilTest(void) const override;
    virtual void ApplyExternalStencil(void) override;
    virtual uint32_t GetFramebufferCopyTextureFormat(void) override;

    virtual void SwapBuffers(cc::OutputSurfaceFrame frame) override;
    virtual void BindToClient(cc::OutputSurfaceClient* client) override;

    void firePaintEvent(HDC hdc, const RECT& paintRect);

private:
    SoftwareOutputSurface(WebPageOcBridge* webPageOcBridge, RenderWidgetCompositor* renderWidgetCompositor);
    void Initialize();

    RenderWidgetCompositor* m_renderWidgetCompositor;
};

} // content

#endif // content_compositor_SoftwareOutputSurface_h