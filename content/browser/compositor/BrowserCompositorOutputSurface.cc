// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/compositor/BrowserCompositorOutputSurface.h"

#include "base/bind.h"
#include "cc/output/compositor_frame.h"
#include "cc/output/context_provider.h"
#include "cc/output/output_surface_frame.h"
#include "content/browser/RenderViewHost.h"
#include "content/browser/compositor/BrowserContextProvider.h"
#include "content/browser/compositor/BrowserSoftwareOutputDevice.h"
#include "skia/ext/platform_canvas.h"

namespace content {

std::unique_ptr<BrowserCompositorOutputSurface> BrowserCompositorOutputSurface::Create(RenderViewHost* renderView)
{
    return std::unique_ptr<BrowserCompositorOutputSurface>(new BrowserCompositorOutputSurface(renderView));
}

BrowserCompositorOutputSurface::BrowserCompositorOutputSurface(RenderViewHost* renderView)
    : OutputSurface(std::unique_ptr<cc::SoftwareOutputDevice>(new BrowserSoftwareOutputDevice(renderView)))
{
    Initialize();
}

BrowserCompositorOutputSurface::~BrowserCompositorOutputSurface()
{
}

void BrowserCompositorOutputSurface::Initialize()
{
    capabilities_.max_frames_pending = 1;
    //capabilities_.adjust_deadline_for_parent = false;
}

void BrowserCompositorOutputSurface::SwapBuffers(cc::OutputSurfaceFrame frame)
{
    DebugBreak();
}

void BrowserCompositorOutputSurface::FirePaintEvent(HDC hdc, const RECT* paintRect)
{
    if (!software_device())
        return;
    ((BrowserSoftwareOutputDevice*)software_device())->FirePaintEvent(hdc, paintRect);
}

void BrowserCompositorOutputSurface::BindToClient(cc::OutputSurfaceClient* client)
{
    DebugBreak();
}

void BrowserCompositorOutputSurface::EnsureBackbuffer()
{
    DebugBreak();
}
void BrowserCompositorOutputSurface::DiscardBackbuffer()
{
    DebugBreak();
}

void BrowserCompositorOutputSurface::BindFramebuffer()
{
    DebugBreak();
}

cc::OverlayCandidateValidator* BrowserCompositorOutputSurface::GetOverlayCandidateValidator() const
{
    DebugBreak();
    return nullptr;
}

bool BrowserCompositorOutputSurface::IsDisplayedAsOverlayPlane() const
{
    DebugBreak();
    return nullptr;
}

unsigned BrowserCompositorOutputSurface::GetOverlayTextureId() const
{
    DebugBreak();
    return 0;
}

// If this returns true, then the surface will not attempt to draw.
bool BrowserCompositorOutputSurface::SurfaceIsSuspendForRecycle() const
{
    DebugBreak();
    return false;
}

void BrowserCompositorOutputSurface::Reshape(const gfx::Size& size,
    float device_scale_factor,
    const gfx::ColorSpace& color_space,
    bool has_alpha,
    bool use_stencil)
{
    DebugBreak();
}

bool BrowserCompositorOutputSurface::HasExternalStencilTest() const
{
    DebugBreak();
    return false;
}
void BrowserCompositorOutputSurface::ApplyExternalStencil()
{
    DebugBreak();
}

uint32_t BrowserCompositorOutputSurface::GetFramebufferCopyTextureFormat()
{
    DebugBreak();
    return 0;
}

} // content