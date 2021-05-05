#include "cc/output/software_output_device.h"

class SkCanvas;
typedef struct HDC__* HDC;

namespace content {

class RenderViewHost;

class BrowserSoftwareOutputDevice : public cc::SoftwareOutputDevice {
public:
    BrowserSoftwareOutputDevice(RenderViewHost* renderView);

    virtual void Resize(const gfx::Size& viewport_pixel_size, float scale_factor) override;

    virtual SkCanvas* BeginPaint(const gfx::Rect& damage_rect) override;

    virtual void EndPaint() override;

    void FirePaintEvent(HDC hdc, const RECT* paintRect);

private:
    RenderViewHost* m_renderView;
    SkCanvas* m_memoryCanvas;
};

}
// content