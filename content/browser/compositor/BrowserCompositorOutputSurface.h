// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_BROWSER_COMPOSITOR_BROWSER_COMPOSITOR_OUTPUT_SURFACE_H_
#define CONTENT_BROWSER_COMPOSITOR_BROWSER_COMPOSITOR_OUTPUT_SURFACE_H_

#include "cc/output/output_surface.h"

namespace content {

class RenderViewHost;

class BrowserCompositorOutputSurface : public cc::OutputSurface {
public:
    static std::unique_ptr<BrowserCompositorOutputSurface> Create(RenderViewHost* renderView);
    virtual ~BrowserCompositorOutputSurface();

    void FirePaintEvent(HDC hdc, const RECT* paintRect);

    virtual void BindToClient(cc::OutputSurfaceClient* client) override;

    virtual void EnsureBackbuffer() override;
    virtual void DiscardBackbuffer() override;

    // Bind the default framebuffer for drawing to, only valid for GL backed
    // OutputSurfaces.
    virtual void BindFramebuffer() override;

    // Get the class capable of informing cc of hardware overlay capability.
    virtual cc::OverlayCandidateValidator* GetOverlayCandidateValidator() const override;

    // Returns true if a main image overlay plane should be scheduled.
    virtual bool IsDisplayedAsOverlayPlane() const override;

    // Get the texture for the main image's overlay.
    virtual unsigned GetOverlayTextureId() const override;

    // If this returns true, then the surface will not attempt to draw.
    virtual bool SurfaceIsSuspendForRecycle() const override;

    virtual void Reshape(const gfx::Size& size,
        float device_scale_factor,
        const gfx::ColorSpace& color_space,
        bool has_alpha,
        bool use_stencil) override;

    virtual bool HasExternalStencilTest() const override;
    virtual void ApplyExternalStencil() override;

    // Gives the GL internal format that should be used for calling CopyTexImage2D
    // when the framebuffer is bound via BindFramebuffer().
    virtual uint32_t GetFramebufferCopyTextureFormat() override;

    // Swaps the current backbuffer to the screen. For successful swaps, the
    // implementation must call OutputSurfaceClient::DidReceiveSwapBuffersAck()
    // after returning from this method in order to unblock the next frame.
    virtual void SwapBuffers(cc::OutputSurfaceFrame frame) override;

private:
    BrowserCompositorOutputSurface(RenderViewHost* renderView);
    void Initialize();
};

} // content

#endif // CONTENT_BROWSER_COMPOSITOR_BROWSER_COMPOSITOR_OUTPUT_SURFACE_H_