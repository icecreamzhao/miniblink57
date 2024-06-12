#pragma once

#include <vector>
#include "G:/mycode/mb/wke/wkedefine.h"

const char WKE_WINDOW_CLASS_NAME[] = "WkeViewWindow";

class WkeBinder
{
public:
  virtual void on_paint_bit_updated(const void* buffer, const wkeRect* r) = 0;
  virtual void on_url_changed(const wkeString url) = 0;
};

class GWkeMgr
{
public:
  static GWkeMgr* instance()
  {
    static GWkeMgr _inst;
    return &_inst;
  }

  wkeWebView add_browser(WkeBinder *new_browser);
  void delete_browser(WkeBinder *new_browser);
  bool is_new_webview_valid() const;
  void enable_open_new_webview(wkeWebView webView, bool enable);
private:
  GWkeMgr();
  ~GWkeMgr();

  struct WebViewUnit
  {
    wkeWebView webView;
    WkeBinder *browser;
  };
  std::vector<WebViewUnit> m_WebViewList;
  DWORD m_LastWebCreate;

  static void __cdecl on_paint_bit_updated_callback(wkeWebView webView, void* param, const void* buffer, const wkeRect* r, int width, int height);
  static void __cdecl on_url_changed_callback(wkeWebView webView, void* param, const wkeString url);
  static bool __cdecl on_load_url_begin(wkeWebView webView, void* param, const char* url, void *job);
  static void __cdecl on_load_url_end(wkeWebView webView, void* param, const char *url, void *job, void* buf, int len);
  static wkeWebView __cdecl on_create_webview(wkeWebView webView, void* param, wkeNavigationType navType, const wkeString urlStr, const wkeWindowFeatures* features);
};
