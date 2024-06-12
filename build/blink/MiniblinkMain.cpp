#include "stdafx.h"

LRESULT CALLBACK MiniblinkMainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    bool bNeedCallDefWindowProc = true;
    KdPagePtr pKdGUIPage = 0;
    LRESULT lResult = 0;

    if (message == WM_NCCREATE) {
        LPCREATESTRUCT lpcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
        pKdGUIPage = static_cast<KdPagePtr>(lpcs->lpCreateParams);
        ::SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LPARAM>(pKdGUIPage));

        pKdGUIPage->Init(hWnd);
        pKdGUIPage->m_messageStackVar = NULL;
    } else {
        pKdGUIPage = reinterpret_cast<KdPagePtr>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));
        //         if( message == WM_NCDESTROY && pKdGUIPage != NULL ) {
        //             return 0;}
    }

    if (!pKdGUIPage) {
        goto Exit1;
    }

    PFN_KdPageWinMsgCallback msgPostCallBack = pKdGUIPage->m_callbacks.m_msgPostCallBack;
    void* pMainContext = pKdGUIPage->getKdGuiObjPtr() ? pKdGUIPage->getKdGuiObjPtr()->pForeignPtr : 0;
    void* pPageContext = pKdGUIPage->getForeignPtr();

    if (pKdGUIPage->m_callbacks.m_msgPreCallBack) {
        lResult = pKdGUIPage->m_callbacks.m_msgPreCallBack(pKdGUIPage,
            pKdGUIPage->getKdGuiObjPtr() ? pKdGUIPage->getKdGuiObjPtr()->pForeignPtr : 0,
            pKdGUIPage->getForeignPtr(),
            hWnd, message, wParam, lParam, &bNeedCallDefWindowProc);
        if (false == bNeedCallDefWindowProc) {
            return lResult;
        }
    }

    if (IsInputEvent(message)) {
        bNeedCallDefWindowProc = true;
        if (1 != KdSendInputEvent(pKdGUIPage, hWnd, message, wParam, lParam)) {
            bNeedCallDefWindowProc = false;
        }

        goto Exit0;
    }

    switch (message) {
    case WM_TIMER:
        KdSendTimerEvent(pKdGUIPage);
        break;
    case WM_SIZE:
        KdSendResizeEvent(pKdGUIPage, hWnd, message, wParam, lParam);
        break;
    case WM_PAINT:
        KdSendPaintEvent(pKdGUIPage, hWnd, message, wParam, lParam);
        break;
    case WM_NCDESTROY:
        KdDeletePageNotCloseWindow(pKdGUIPage, hWnd, message, wParam, lParam);
        pKdGUIPage = 0;
        break;
    case WM_LBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_XBUTTONDOWN:
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MOUSEMOVE:
    case WM_MOUSELEAVE:
        KdSendMouseEvent(pKdGUIPage, hWnd, message, wParam, lParam);
        break;
    case WM_CAPTURECHANGED: // 这条消息会在WM_NCLBUTTONDOWN后收到，要做点特殊处理~详情见：http://hi.baidu.com/killdbg/item/03a64ea738382d038919d3f0
        KdSendCaptureChanged(pKdGUIPage, hWnd, message, wParam, lParam);
        break;
    case WM_NCCALCSIZE:
        if ((BOOL)wParam) {
            NCCALCSIZE_PARAMS* lpncsp = (NCCALCSIZE_PARAMS FAR*)lParam;
            lpncsp = 0;
        }

        break;
    case WM_CLOSE: // no break
        //         KdDeletePageNotCloseWindow(pKdGUIPage, hWnd, message, wParam, lParam);
        //         pKdGUIPage = 0;
        break;
    case WM_KILLFOCUS:
        // KdSendKillFocusEvent(pKdGUIPage, hWnd, message, wParam, lParam);
        break;
        //     case WM_SHOWDEBUGNODEDATA: // 0x14CCC = 85196
        //         KdShowDebugNodeData(pKdGUIPage);
        //         break;
    default:
        //        bNeedCallDefWindowProc = !KdSendOtherEvent(pKdGUIPage, hWnd, message, wParam, lParam);
        bNeedCallDefWindowProc = true;
        break;
    }

Exit0:
    if (msgPostCallBack) {
        //bNeedCallDefWindowProc = true;
        lResult = msgPostCallBack(pKdGUIPage, pMainContext, pPageContext,
            hWnd, message, wParam, lParam, &bNeedCallDefWindowProc);
    }

    if (false == bNeedCallDefWindowProc) {
        return lResult;
    }

Exit1:
    return DefWindowProc(hWnd, message, wParam, lParam);
}