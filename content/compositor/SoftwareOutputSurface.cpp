// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/compositor/SoftwareOutputSurface.h"

#include "content/RenderWidgetCompositor.h"
#include "content/compositor/BrowserContextProvider.h"
#include "content/compositor/SoftwareOutputDevice.h"

#include "cc/output/context_provider.h"
#include "cc/output/managed_memory_policy.h"
#include "cc/output/output_surface_frame.h"
#include "cc/output/output_surface_client.h"
#include "skia/ext/platform_canvas.h"
#include "base/bind.h"

namespace content {

std::unique_ptr<SoftwareOutputSurface> SoftwareOutputSurface::Create(WebPageOcBridge* webPageOcBridge, RenderWidgetCompositor* renderWidgetCompositor)
{
    return std::unique_ptr<SoftwareOutputSurface>(new SoftwareOutputSurface(webPageOcBridge, renderWidgetCompositor));
}

SoftwareOutputSurface::SoftwareOutputSurface(WebPageOcBridge* webPageOcBridge, RenderWidgetCompositor* renderWidgetCompositor)
    : OutputSurface(std::unique_ptr<SoftwareOutputDevice>(new SoftwareOutputDevice(webPageOcBridge)))
    , m_renderWidgetCompositor(renderWidgetCompositor)
{
    Initialize();
}

SoftwareOutputSurface::~SoftwareOutputSurface()
{
}

void SoftwareOutputSurface::Initialize()
{
    capabilities_.max_frames_pending = 1;
    //capabilities_.adjust_deadline_for_parent = false;
}

void SoftwareOutputSurface::EnsureBackbuffer()
{

}

void SoftwareOutputSurface::DiscardBackbuffer(void)
{

}

void SoftwareOutputSurface::BindFramebuffer(void)
{
    DebugBreak();
}

cc::OverlayCandidateValidator* SoftwareOutputSurface::GetOverlayCandidateValidator(void) const
{
    return nullptr;
}

bool SoftwareOutputSurface::IsDisplayedAsOverlayPlane(void) const
{
    return false;
}

unsigned int SoftwareOutputSurface::GetOverlayTextureId(void) const
{
    DebugBreak();
    return 0;
}

bool SoftwareOutputSurface::SurfaceIsSuspendForRecycle(void) const
{
    return false;
}

void SoftwareOutputSurface::Reshape(const gfx::Size& viewport_pixel_size, float scale_factor, const gfx::ColorSpace&, bool, bool)
{
    if (software_device_)
        software_device_->Resize(viewport_pixel_size, scale_factor);
}

bool SoftwareOutputSurface::HasExternalStencilTest(void) const
{

    return false;
}

void SoftwareOutputSurface::ApplyExternalStencil(void)
{
    DebugBreak();
}

uint32_t SoftwareOutputSurface::GetFramebufferCopyTextureFormat(void)
{
    DebugBreak();
    return 0;
}

void SoftwareOutputSurface::SwapBuffers(cc::OutputSurfaceFrame frame)
{
    SoftwareOutputDevice* softwareOutputDevice = (SoftwareOutputDevice*)software_device_.get();
    softwareOutputDevice->swapBuffers();

    m_renderWidgetCompositor->swapBuffers();
}

void SoftwareOutputSurface::BindToClient(cc::OutputSurfaceClient* client)
{
//     client->SetMemoryPolicy(cc::ManagedMemoryPolicy(
//         128 * 1024 * 1024,
//         gpu::MemoryAllocation::CUTOFF_ALLOW_NICE_TO_HAVE,
//         base::SharedMemory::GetHandleLimit() / 3));
    //cc::OutputSurface::BindToClient(client);
}

void SoftwareOutputSurface::firePaintEvent(HDC hdc, const RECT& paintRect)
{
    if (!software_device())
        return;
    ((SoftwareOutputDevice*)software_device())->firePaintEvent(hdc, paintRect);
}

} // content