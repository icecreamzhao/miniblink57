
#include "content/browser/compositor/BrowserSoftwareOutputDevice.h"

#include "content/browser/RenderViewHost.h"
#include "skia/ext/platform_canvas.h"

namespace content {

BrowserSoftwareOutputDevice::BrowserSoftwareOutputDevice(RenderViewHost* renderView)
{
    m_renderView = renderView;
    m_memoryCanvas = nullptr;
}

void BrowserSoftwareOutputDevice::Resize(const gfx::Size& viewport_pixel_size, float scale_factor)
{
    if (viewport_pixel_size_ == viewport_pixel_size)
        return;
    viewport_pixel_size_ = viewport_pixel_size;

    m_memoryCanvas = skia::CreatePlatformCanvas(viewport_pixel_size.width(), viewport_pixel_size.height(), true);

    //cc::SoftwareOutputDevice::Resize(viewport_pixel_size, scale_factor);
}

SkCanvas* BrowserSoftwareOutputDevice::BeginPaint(const gfx::Rect& damage_rect)
{
    //return cc::SoftwareOutputDevice::BeginPaint(damage_rect);
    damage_rect_ = damage_rect;
    return m_memoryCanvas;
}

void BrowserSoftwareOutputDevice::EndPaint()
{
    HDC hdc = ::GetDC(m_renderView->getPlatformHWND());
    skia::DrawToNativeContext(m_memoryCanvas, hdc, damage_rect_.x(), damage_rect_.y(), &damage_rect_.ToRECT());
    ::ReleaseDC(m_renderView->getPlatformHWND(), hdc);
}

void BrowserSoftwareOutputDevice::FirePaintEvent(HDC hdc, const RECT* paintRect)
{
    if (!m_memoryCanvas || gfx::Rect(*paintRect).IsEmpty())
        return;

    skia::DrawToNativeContext(m_memoryCanvas, hdc, paintRect->left, paintRect->top, paintRect);
}

};

// content