﻿#ifndef content_browser_ContextMeun_h
#define content_browser_ContextMeun_h

#include "content/browser/WebPage.h"
//#include "content/browser/PostTaskHelper.h"
#include "content/web_impl_win/WebThreadImpl.h"
#include "third_party/WebKit/Source/web/WebViewImpl.h"
#include "third_party/WebKit/Source/platform/Timer.h"
#include "third_party/WebKit/Source/platform/CrossThreadFunctional.h"
#include "third_party/WebKit/Source/wtf/ThreadingPrimitives.h"
#include "third_party/WebKit/public/web/WebContextMenuData.h"
#include "third_party/WebKit/public/web/WebFrame.h"
#include "third_party/WebKit/public/web/WebLocalFrame.h"
#include "wke/wkeGlobalVar.h"
#include "wke/wkeWebView.h"
#include <windows.h>

#if defined(OS_WIN)

namespace content {

#define kContextMenuClassName L"MbContextMenu"
extern WebPageImpl* g_saveImageingWebPage;

class ContextMenu {
public:
    ContextMenu(WebPage* webPage)
    {
        m_popMenu = nullptr;
        m_hWnd = nullptr;
        m_webPage = webPage;
        m_isDestroyed = 0;

        ContextMenu* self = this;

        m_uiCallback = wke::g_wkeUiThreadPostTaskCallback;
        if (!m_uiCallback)
            m_uiCallback = onUiThreadCallback;

        asyncCallUiThread([self] {
            self->initImpl();
        });
    }

    void initImpl()
    {
        if (m_hWnd)
            return;

        registerClass();
        m_hWnd = CreateWindowExW(WS_EX_TOOLWINDOW, kContextMenuClassName, kContextMenuClassName, WS_POPUP, 
            0, 0, 1, 1, HWND_DESKTOP, NULL, nullptr, this);
        ::SetPropW(m_hWnd, kContextMenuClassName, (HANDLE)this);
        ::SetForegroundWindow(m_hWnd);
        ::ShowWindow(m_hWnd, SW_SHOW);
    }

    ~ContextMenu()
    {
        m_mutex.lock();
        _InterlockedIncrement(&m_isDestroyed);

        ContextMenu* self = this;
        HWND hWnd = m_hWnd;
        HMENU popMenu = m_popMenu;
        asyncCallUiThread([hWnd, popMenu] {
            ::SetPropW(hWnd, kContextMenuClassName, (HANDLE)nullptr);
            ::DestroyWindow(hWnd);

            if (popMenu)
                ::DestroyMenu(popMenu);
        });
        m_mutex.unlock();
    }

    bool registerClass()
    {
        WNDCLASSEXW wcex;

        wcex.cbSize = sizeof(WNDCLASSEXW);
        wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DROPSHADOW;
        wcex.lpfnWndProc = wndProc;
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.hInstance = nullptr;
        wcex.hIcon = nullptr;
        wcex.hCursor = LoadCursorW(0, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wcex.lpszMenuName = 0;
        wcex.lpszClassName = kContextMenuClassName;
        wcex.hIconSm = nullptr;
        return !!RegisterClassExW(&wcex);
    }

    enum MenuId {
        kSelectedAllId = 1 << 1,
        kSelectedTextId = 1 << 2,
        kUndoId = 1 << 3,
        kCopyImageId = 1 << 4,
        kInspectElementAtId = 1 << 5,
        kCutId = 1 << 6,
        kPasteId = 1 << 7,
        kPrintId = 1 << 8,
        kGoForwardId = 1 << 9,
        kGoBackId = 1 << 10,
        kReloadId = 1 << 11,
        kSaveImageId = 1 << 12,
    };

    static int WKE_CALL_TYPE onUiThreadCallback(HWND hWnd, wkeUiThreadRunCallback callback, void* param)
    {
        callback(hWnd, param);
        return 0;
    }

    void asyncCallUiThread(std::function<void()>&& func)
    {
        HWND hWnd = m_webPage->getHWND();
        m_uiCallback(hWnd, UiTaskCall::asyncFunc, new UiTaskCall(&m_mutex, std::move(func)));
    }

    class UiTaskCall {
    public:
        UiTaskCall(WTF::RecursiveMutex* mutex, std::function<void()>&& func)
            : m_func(func)
            , m_mutex(mutex) {}

        ~UiTaskCall() {}
        
    private:
        WTF::RecursiveMutex* m_mutex;
        std::function<void()> m_func;

    public:
        static void WKE_CALL_TYPE asyncFunc(HWND hWnd, void* param)
        {
            UiTaskCall* self = (UiTaskCall*)param;

            self->m_mutex->lock();
            (self->m_func)();
            self->m_mutex->unlock();

            delete self;
        }
    };

    void show(const blink::WebContextMenuData& data, int64_t frameId)
    {
        ContextMenu* self = this;
        m_data = data;
        m_frameId = frameId;

        UINT actionFlags = 0;
        if ((!data.selectedText.isNull() && !data.selectedText.isEmpty()))
            actionFlags |= kSelectedTextId;

        if (data.hasImageContents) {
            actionFlags |= kCopyImageId;
            actionFlags |= kSaveImageId;
            m_imagePos = blink::IntPoint(data.mousePosition);
        }

        if (m_webPage->isDevtoolsConneted())
            actionFlags |= kInspectElementAtId;

        if (data.isEditable) {
            actionFlags |= kCutId;
            actionFlags |= kPasteId;
            actionFlags |= kSelectedAllId;
            actionFlags |= kUndoId;
        }

        if (m_webPage->canGoForward())
            actionFlags |= kGoForwardId;
        if (m_webPage->canGoBack())
            actionFlags |= kGoBackId;
        actionFlags |= kReloadId;

        bool needCreatePrintItem = false;
        wkeOnContextMenuItemClickCallback clickCallback = m_webPage->wkeHandler().contextMenuItemClickCallback;
        void* callbackParam = m_webPage->wkeHandler().contextMenuItemClickCallbackParam;
        if (clickCallback)
            needCreatePrintItem = clickCallback(m_webPage->wkeWebView(), callbackParam, kWkeContextMenuItemClickTypePrint, kWkeContextMenuItemClickStepShow, (wkeWebFrameHandle)m_frameId, nullptr);
        if (needCreatePrintItem)
            actionFlags |= kPrintId;

        asyncCallUiThread([self, actionFlags] {
            if (0 < ContextMenu::m_isDestroyed)
                return;
            self->showImpl(actionFlags);
        });
    }

    static bool canShowItem(UINT actionFlags, MenuId id)
    {
        if ((actionFlags & id) && (wke::g_contextMenuItemMask & id))
            return true;
        return false;
    }

    void appendMenuText(UINT actionFlags)
    {
        if (!wke::g_language.get())
            return appendMenuTextZhcn(actionFlags);

        if (std::string::npos != wke::g_language->find("zh-cn"))
            return appendMenuTextZhcn(actionFlags);

        return appendMenuTextEn(actionFlags);
    }

    void appendMenuTextZhcn(UINT actionFlags)
    {
        if (canShowItem(actionFlags, kSelectedTextId))
            ::AppendMenuW(m_popMenu, MF_STRING, kSelectedTextId, L"复制");

        if (canShowItem(actionFlags, kCopyImageId))
            ::AppendMenuW(m_popMenu, MF_STRING, kCopyImageId, L"复制图片");
        if (canShowItem(actionFlags, kSaveImageId))
            ::AppendMenuW(m_popMenu, MF_STRING, kSaveImageId, L"图片另存为");

        if (canShowItem(actionFlags, kInspectElementAtId))
            ::AppendMenuW(m_popMenu, MF_STRING, kInspectElementAtId, L"检查");

        if (canShowItem(actionFlags, kCutId))
            ::AppendMenuW(m_popMenu, MF_STRING, kCutId, L"剪切");

        if (canShowItem(actionFlags, kPasteId))
            ::AppendMenuW(m_popMenu, MF_STRING, kPasteId, L"粘贴");

        if (canShowItem(actionFlags, kSelectedAllId))
            ::AppendMenuW(m_popMenu, MF_STRING, kSelectedAllId, L"全选");

        if (canShowItem(actionFlags, kUndoId))
            ::AppendMenuW(m_popMenu, MF_STRING, kUndoId, L"撤销");

        if (canShowItem(actionFlags, kGoForwardId))
            ::AppendMenuW(m_popMenu, MF_STRING, kGoForwardId, L"前进");

        if (canShowItem(actionFlags, kGoBackId))
            ::AppendMenuW(m_popMenu, MF_STRING, kGoBackId, L"后退");

        if (canShowItem(actionFlags, kReloadId))
            ::AppendMenuW(m_popMenu, MF_STRING, kReloadId, L"刷新");

        if (canShowItem(actionFlags, kPrintId))
            ::AppendMenuW(m_popMenu, MF_STRING, kPrintId, L"打印");
    }

    void appendMenuTextEn(UINT actionFlags)
    {
        if (canShowItem(actionFlags, kSelectedTextId))
            ::AppendMenuW(m_popMenu, MF_STRING, kSelectedTextId, L"Copy");

        if (canShowItem(actionFlags, kCopyImageId))
            ::AppendMenuW(m_popMenu, MF_STRING, kCopyImageId, L"CopyImage");
        if (canShowItem(actionFlags, kSaveImageId))
            ::AppendMenuW(m_popMenu, MF_STRING, kSaveImageId, L"Save as..");

        if (canShowItem(actionFlags, kInspectElementAtId))
            ::AppendMenuW(m_popMenu, MF_STRING, kInspectElementAtId, L"InspectElementAt");

        if (canShowItem(actionFlags, kCutId))
            ::AppendMenuW(m_popMenu, MF_STRING, kCutId, L"Cut");

        if (canShowItem(actionFlags, kPasteId))
            ::AppendMenuW(m_popMenu, MF_STRING, kPasteId, L"Paste");

        if (canShowItem(actionFlags, kSelectedAllId))
            ::AppendMenuW(m_popMenu, MF_STRING, kSelectedAllId, L"SelectedAll");

        if (canShowItem(actionFlags, kUndoId))
            ::AppendMenuW(m_popMenu, MF_STRING, kUndoId, L"Undo");

        if (canShowItem(actionFlags, kGoForwardId))
            ::AppendMenuW(m_popMenu, MF_STRING, kGoForwardId, L"GoForward");

        if (canShowItem(actionFlags, kGoBackId))
            ::AppendMenuW(m_popMenu, MF_STRING, kGoBackId, L"GoBack");

        if (canShowItem(actionFlags, kReloadId))
            ::AppendMenuW(m_popMenu, MF_STRING, kReloadId, L"Reload");

        if (canShowItem(actionFlags, kPrintId))
            ::AppendMenuW(m_popMenu, MF_STRING, kPrintId, L"Print");
    }

    void showImpl(UINT actionFlags)
    {
        POINT screenPt = { 0 };
        ::GetCursorPos(&screenPt);

        POINT clientPt = screenPt;
        ::ScreenToClient(m_hWnd, &clientPt);

        if (m_popMenu)
            ::DestroyMenu(m_popMenu);
        m_popMenu = ::CreatePopupMenu();
        
        //m_data = blink::WebContextMenuData();
        appendMenuText(actionFlags);        
        
        if (0 == ::GetMenuItemCount(m_popMenu)) {
            ::DestroyMenu(m_popMenu);
            m_popMenu = nullptr;
            return;
        }

        //m_data = data;

        //::ShowWindow(m_hWnd, SW_SHOWMINNOACTIVE);
        //::SetForegroundWindow(m_hWnd);
        ::SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOREPOSITION | SWP_NOACTIVATE);

        UINT flags = TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_VERPOSANIMATION | TPM_HORIZONTAL | TPM_LEFTALIGN | TPM_HORPOSANIMATION;
        ::TrackPopupMenuEx(m_popMenu, flags, clientPt.x, clientPt.y, m_hWnd, 0);
    }

    void onCommand(UINT itemID)
    {
        if (0 < ContextMenu::m_isDestroyed)
            return;

        content::WebThreadImpl* threadImpl = (content::WebThreadImpl*)(blink::Platform::current()->currentThread());
        threadImpl->fire();

        if (kSelectedTextId == itemID) {
            m_webPage->webViewImpl()->focusedFrame()->executeCommand("Copy");
        } else if (kSelectedAllId == itemID) {
            m_webPage->webViewImpl()->focusedFrame()->executeCommand("SelectAll");
        } else if (kUndoId == itemID) {
            m_webPage->webViewImpl()->focusedFrame()->executeCommand("Undo");
        } else if (kCopyImageId == itemID) {
            m_webPage->webViewImpl()->focusedFrame()->copyImageAt(m_imagePos);
        } else if (kSaveImageId == itemID) {
            if (!g_saveImageingWebPage) {
                g_saveImageingWebPage = m_webPage->webPageImpl();
                m_webPage->webViewImpl()->focusedFrame()->copyImageAt(m_imagePos);
            }
        } else if (kInspectElementAtId == itemID) {
            m_webPage->inspectElementAt(m_data.mousePosition.x, m_data.mousePosition.y);
        } else if (kCutId == itemID) {
            m_webPage->webViewImpl()->focusedFrame()->executeCommand("Cut");
        } else if (kPasteId == itemID) {
            m_webPage->webViewImpl()->focusedFrame()->executeCommand("Paste");
        } else if (kGoForwardId == itemID) {
            m_webPage->goForward();
        } else if (kGoBackId == itemID) {
            m_webPage->goBack();
        } else if (kReloadId == itemID) {
            m_webPage->mainFrame()->reload(blink::WebFrameLoadType::Reload);
        } else if (kPrintId == itemID) {
            wkeOnContextMenuItemClickCallback clickCallback = m_webPage->wkeHandler().contextMenuItemClickCallback;
            void* callbackParam = m_webPage->wkeHandler().contextMenuItemClickCallbackParam;
            if (clickCallback)
                clickCallback(m_webPage->wkeWebView(), callbackParam, kWkeContextMenuItemClickTypePrint, kWkeContextMenuItemClickStepClick, (wkeWebFrameHandle)m_frameId, nullptr);
        }
    }

    static LRESULT CALLBACK wndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
//         String output = String::format("ContextMenu.wndProc: %d\n", uMsg);
//         OutputDebugStringA(output.utf8().data());

        PAINTSTRUCT ps;
        HDC hdc = nullptr;
        ContextMenu* self = (ContextMenu*)GetPropW(hWnd, kContextMenuClassName);

        switch (uMsg) {
        case WM_TIMER:
            //self->hide();
            break;

        case WM_PAINT:
            hdc = ::BeginPaint(hWnd, &ps);
            self->onPaint(hWnd, hdc);
            ::EndPaint(hWnd, &ps);
            break;
        case WM_COMMAND: {
            UINT itemID = LOWORD(wParam);
            if (WTF::isMainThread())
                self->onCommand(itemID);
            else {
                blink::Platform::current()->mainThread()->postTask(FROM_HERE, blink::crossThreadBind(&ContextMenu::onCommand, WTF::crossThreadUnretained(self), itemID));            
//                 postTaskToMainThread(FROM_HERE, [self, itemID] {
//                     self->onCommand(itemID);
//                 });
            }
        }
            break;
        case WM_CLOSE:
            break;
        case WM_EXITMENULOOP:
            //::ShowWindow(self->m_hWnd, SW_HIDE);
            break;
        }

        return ::DefWindowProcW(hWnd, uMsg, wParam, lParam);
    }

    void onPaint(HWND hWnd, HDC hdc)
    {

    }

    HWND m_hWnd;
    HMENU m_popMenu;
    blink::WebContextMenuData m_data;
    WebPage* m_webPage;

    blink::IntPoint m_imagePos;

    int m_lastX;
    int m_lastY;

    WTF::RecursiveMutex m_mutex;
    wkeUiThreadPostTaskCallback m_uiCallback;

    int64_t m_frameId;

public:
    static volatile long m_isDestroyed;
};

volatile long ContextMenu::m_isDestroyed = 0;

}

#endif

#endif // content_browser_ContextMeun_h