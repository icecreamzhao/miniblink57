#include "config.h"
#include <windows.h>

#undef min
#undef max
#include <algorithm>

using std::max;
using std::min;
#include "GDIPlusInit.h"
#include <gdiplus.h>

namespace blink {

CLSID s_bmpClsid = { 0 };
CLSID s_jpgClsid = { 0 };
CLSID s_pngClsid = { 0 };
static bool s_bInitClsid = false;

static int getEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
    UINT num = 0; // number of image encoders
    UINT size = 0; // size of the image encoder array in bytes

    Gdiplus::ImageCodecInfo* pImageCodecInfo = NULL;

    Gdiplus::GetImageEncodersSize(&num, &size);
    if (size == 0)
        return -1; // Failure

    pImageCodecInfo = (Gdiplus::ImageCodecInfo*)(malloc(size));
    if (pImageCodecInfo == NULL)
        return -1; // Failure

    GetImageEncoders(num, size, pImageCodecInfo);

    for (UINT j = 0; j < num; ++j) {
        if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0) {
            *pClsid = pImageCodecInfo[j].Clsid;
            free(pImageCodecInfo);
            return j; // Success
        }
    }

    free(pImageCodecInfo);
    return -1; // Failure
}

bool initGDIPlusClsids()
{
    if (s_bInitClsid)
        return true;

    static ULONG_PTR g_nGdiplusToken = 0;
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    Gdiplus::GdiplusStartup(&g_nGdiplusToken, &gdiplusStartupInput, NULL);

    s_bInitClsid = true;

    if (-1 == getEncoderClsid(L"image/bmp", &s_bmpClsid))
        return false;

    if (-1 == getEncoderClsid(L"image/jpeg", &s_jpgClsid))
        return false;

    if (-1 == getEncoderClsid(L"image/png", &s_pngClsid))
        return false;

    return true;
}

} // blink