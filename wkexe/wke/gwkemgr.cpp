#include "gwkemgr.h"
//#include "xy/myapp.h"
#include <windowsx.h>

int CREATE_WEBVIEW_INTERVAL = 1000;

GWkeMgr::GWkeMgr() : m_LastWebCreate(0) {
  wkeInit();
}

GWkeMgr::~GWkeMgr() {
  for (auto webViewUnit : m_WebViewList)
    wkeDestroyWebWindow(webViewUnit.webView);
  m_WebViewList.clear();
}

wkeWebView GWkeMgr::add_browser(WkeBinder *new_browser)
{
  //检查上次创建WebView时间，防止短时间内创建WebView过多导致crash
  DWORD curTick = GetTickCount();
  if (curTick - m_LastWebCreate < CREATE_WEBVIEW_INTERVAL)
    return NULL;

  m_LastWebCreate = curTick;

  if (!wkeIsInitialize())
    wkeInitialize();

  //创建WkeView
  wkeWebView webView = wkeCreateWebView();

  //if (!wkeIsWebviewValid(webView))
  //	return nullptr;
  
  wkeOnPaintBitUpdated(webView, on_paint_bit_updated_callback, NULL);
#ifdef _DEBUG
  //wkeSetDebugConfig(webView, "showDevTools", "D:\\download\\miniblink-20210131\\front_end\\inspector.html");
#endif
  wkeOnURLChanged(webView, on_url_changed_callback, NULL);
  wkeOnLoadUrlBegin(webView, on_load_url_begin, nullptr);
  wkeOnLoadUrlEnd(webView, on_load_url_end, nullptr);

  wkeShowWindow(webView, true);

  //加入列表
  WebViewUnit viewUnit = {webView, new_browser};
  m_WebViewList.push_back(viewUnit);

  wkeLoadURL(webView, "www.baidu.com");

  return webView;
}

void GWkeMgr::delete_browser(WkeBinder *browser)
{
  for (std::vector<WebViewUnit>::iterator iter = m_WebViewList.begin(); iter != m_WebViewList.end(); ++iter) {
    if (iter->browser == browser)
    {
      wkeDestroyWebWindow(iter->webView);
      m_WebViewList.erase(iter);
      break;
    }
  }
}

bool GWkeMgr::is_new_webview_valid() const
{
  DWORD curTick = GetTickCount();
  return curTick - m_LastWebCreate >= CREATE_WEBVIEW_INTERVAL;
}

void GWkeMgr::enable_open_new_webview(wkeWebView webView, bool enable)
{
  wkeSetNavigationToNewWindowEnable(webView, enable);
  if (enable)
    wkeOnCreateView(webView, on_create_webview, nullptr);
}

void GWkeMgr::on_paint_bit_updated_callback(wkeWebView webView, void* param, const void* buffer, const wkeRect* r, int width, int height)
{
  for (auto webViewUnit : GWkeMgr::instance()->m_WebViewList)
    if (webViewUnit.webView == webView)
      webViewUnit.browser->on_paint_bit_updated(buffer, r);
}

void GWkeMgr::on_url_changed_callback(wkeWebView webView, void* param, const wkeString url)
{
  for (auto webViewUnit : GWkeMgr::instance()->m_WebViewList)
    if (webViewUnit.webView == webView)
      webViewUnit.browser->on_url_changed(url);
}

bool GWkeMgr::on_load_url_begin(wkeWebView webView, void* param, const char* url, void *job)
{
  //OutputDebugString(WString().Format("load url begin %s\n", url));
  return true;
}

void GWkeMgr::on_load_url_end(wkeWebView webView, void* param, const char *url, void *job, void* buf, int len)
{
  //OutputDebugString(WString().Format("load url end %s\n", url));
}

wkeWebView GWkeMgr::on_create_webview(wkeWebView webView, void* param, wkeNavigationType navType, const wkeString urlStr, const wkeWindowFeatures* features)
{
  //ShellExecute(0, "open", wkeGetString(urlStr), NULL, NULL, SW_SHOWNORMAL);
  return nullptr;
}
