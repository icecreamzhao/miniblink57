#ifndef RENDER_GDI_H
#define RENDER_GDI_H

#include "render.h"

class CRenderGDI : public CRender {
public:
    CRenderGDI()
        :m_hView(NULL)
        , m_hDC(NULL)
        , m_width(0), m_height(0)
        , m_pixels(NULL) {
    }

    ~CRenderGDI() {
        HBITMAP hbmp = CreateCompatibleBitmap(m_hDC, 0, 0);
        hbmp = (HBITMAP)SelectObject(m_hDC, hbmp);
        if (hbmp) DeleteObject(hbmp);
        if (m_hDC) DeleteDC(m_hDC);
    }

    virtual bool init(HWND hView) {
        m_hView = hView;
        m_hDC = CreateCompatibleDC(0);

        RECT rect;
        GetClientRect(hView, &rect);
        resize(rect.right, rect.bottom);
        return true;
    }

    virtual void destroy() {
        delete this;
    }

    virtual void resize(unsigned int w, unsigned int h) {
        if (m_width == w && m_height == h)
            return;

        m_width = w;
        m_height = h;
        m_pixels = NULL;
    }

    virtual void render(wkeWebView webView, int a_ = -1) {
        HDC hDC;
        if (m_pixels == NULL)
            createBitmap(webView);
        if (!wkeIsDirty(webView)) return;

        hDC = GetDC(m_hView);
        wkePaint(webView, m_pixels, m_width << 2);

        if (WS_EX_LAYERED & GetWindowLong(m_hView, GWL_EXSTYLE)) {
            RECT r_; BLENDFUNCTION _Blend = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA, };
            GetWindowRect(m_hView, &r_);
            r_.right = r_.bottom = 0;

            //////////////////////////////////////////////////////////////////////////
            m_hDC = wkeGetViewDC(webView);
            //////////////////////////////////////////////////////////////////////////

            UpdateLayeredWindow(m_hView, hDC,
                (POINT *)&r_, (SIZE *)&m_width, m_hDC,
                (POINT *)&r_.right, 0xff, &_Blend, ULW_ALPHA);
        } else
            BitBlt(hDC, 0, 0, m_width, m_height, m_hDC, 0, 0, SRCCOPY);
        ReleaseDC(m_hView, hDC);
    }

    void createBitmap(wkeWebView webView) {
        memset(&bi, 0, sizeof(bi));
        bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        bi.bmiHeader.biWidth = (int)m_width;
        bi.bmiHeader.biHeight = -(int)m_height;
        bi.bmiHeader.biPlanes = 1;
        bi.bmiHeader.biBitCount = 32;
        bi.bmiHeader.biCompression = BI_RGB;

        HBITMAP hbmp = ::CreateDIBSection(0, &bi,
            DIB_RGB_COLORS, &m_pixels, NULL, 0);
        hbmp = (HBITMAP)SelectObject(m_hDC, hbmp);
        if (hbmp) DeleteObject(hbmp);
        wkeSetDirty(webView, true);
    }

private:
    BITMAPINFO bi;
    HWND m_hView;
    HDC m_hDC;
    unsigned int m_width, m_height;
    void* m_pixels;
};

#endif //! RENDER_GDI_H 

