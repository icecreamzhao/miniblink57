
#include "content/compositor/SoftwareOutputDevice.h"

//#include "mc/base/BdColor.h"
#include "content/WebPageOcBridge.h"
#if defined(WIN32) 
#include "skia/ext/bitmap_platform_device_win.h"
#else
#include "skia/ext/bitmap_platform_device_cairo.h"
#endif
#include "skia/ext/platform_canvas.h"

namespace content {

SoftwareOutputDevice::SoftwareOutputDevice(WebPageOcBridge* webPageOcBridge)
{
    m_webPageOcBridge = webPageOcBridge;
    m_memoryCanvas = nullptr;
    m_hWnd = nullptr;
    ::InitializeCriticalSection(&m_memoryCanvasLock);
}

SoftwareOutputDevice::~SoftwareOutputDevice()
{
    ::EnterCriticalSection(&m_memoryCanvasLock);
    if (m_memoryCanvas)
        delete m_memoryCanvas;
    ::LeaveCriticalSection(&m_memoryCanvasLock);
}

void SoftwareOutputDevice::setHWND(HWND hWnd)
{
    m_hWnd = hWnd;
}

HDC SoftwareOutputDevice::getHdcLocked()
{
#if defined(WIN32)
    if (!m_memoryCanvas)
        return nullptr;

    ::EnterCriticalSection(&m_memoryCanvasLock);

    skia::BitmapPlatformDevice* device = (skia::BitmapPlatformDevice*)skia::GetPlatformDevice(skia::GetTopDevice(*m_memoryCanvas));
    if (!device) {
        ::LeaveCriticalSection(&m_memoryCanvasLock);
        return nullptr;
    }

    HDC hDC = device->GetBitmapDCUgly(m_hWnd);
    return hDC;
#else
    __debugbreak();
    return nullptr;
#endif
}

void SoftwareOutputDevice::releaseHdc()
{
    ::LeaveCriticalSection(&m_memoryCanvasLock);
}

void SoftwareOutputDevice::Resize(const gfx::Size& viewportPixelSize, float scalefactor)
{
    //scale_factor_ = scalefactor;

    if (viewport_pixel_size_ == viewportPixelSize)
        return;
    viewport_pixel_size_ = viewportPixelSize;

    ::EnterCriticalSection(&m_memoryCanvasLock);
    if (m_memoryCanvas)
        delete m_memoryCanvas;
#if defined(WIN32) 
    m_memoryCanvas = skia::CreatePlatformCanvas(viewportPixelSize.width(), viewportPixelSize.height(), true);
#else
    m_memoryCanvas = skia::CreatePlatformCanvas(viewportPixelSize.width(), viewportPixelSize.height(), true, nullptr, skia::CRASH_ON_FAILURE);
#endif
    COLORREF c = 0xffffff; // m_webPageOcBridge->getBackgroundColor();

    SkPaint clearColorPaint;
    clearColorPaint.setColor(c);

    // http://blog.csdn.net/to_be_designer/article/details/48530921
    clearColorPaint.setXfermodeMode(SkXfermode::kSrcOver_Mode);

    SkRect r = SkRect::MakeWH(viewportPixelSize.width(), viewportPixelSize.height());
    m_memoryCanvas->drawRect(r, clearColorPaint);

    ::LeaveCriticalSection(&m_memoryCanvasLock);
}

SkCanvas* SoftwareOutputDevice::BeginPaint(const gfx::Rect& damageRect)
{
    damage_rect_ = damageRect;
    return m_memoryCanvas;
}

void SoftwareOutputDevice::EndPaint()
{
    if (!m_hWnd || !m_memoryCanvas)
        return;

    bool needDrawToScreen = m_webPageOcBridge->onEndPaintStep1(nullptr, damage_rect_.ToRECT());

    if (needDrawToScreen) {
#if defined(WIN32) 
        HDC hdc = ::GetDC(m_hWnd);
        RECT r = damage_rect_.ToRECT();
        skia::DrawToNativeContext(m_memoryCanvas, hdc, damage_rect_.x(), damage_rect_.y(), &r);
        ::ReleaseDC(m_hWnd, hdc);
#else
        __debugbreak();
#endif
    }

    //m_memoryCanvas->clear(SK_ColorBLUE); // weolar

#if defined(OS_WIN)
    HDC hMemoryDC = skia::BeginPlatformPaint(m_hWnd, m_memoryCanvas);
    m_webPageOcBridge->onEndPaintStep2(hMemoryDC, damage_rect_.ToRECT());
    skia::EndPlatformPaint(m_memoryCanvas);
#else
    m_webPageOcBridge->onEndPaintStep2((HDC)m_memoryCanvas, damage_rect_.ToRECT());
#endif
}

void SoftwareOutputDevice::swapBuffers()
{

}

void SoftwareOutputDevice::firePaintEvent(HDC hdc, const RECT& paintRect)
{
#if defined(WIN32)
    if (!hdc || !m_memoryCanvas || gfx::Rect(paintRect).IsEmpty())
        return;

    ::EnterCriticalSection(&m_memoryCanvasLock);
    skia::DrawToNativeContext(m_memoryCanvas, hdc, paintRect.left, paintRect.top, &paintRect);
    ::LeaveCriticalSection(&m_memoryCanvasLock);
#else
    //__debugbreak();
#endif
}

};

// content