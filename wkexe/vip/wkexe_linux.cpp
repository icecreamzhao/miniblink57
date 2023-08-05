
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <utility>
#include <stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
#include <signal.h>
#include <dlfcn.h>
#include <string.h>
#include "../../mbvip/core/mb.h"

mbWebView MB_CALL_TYPE handleCreateView(mbWebView webView, void* param, mbNavigationType navigationType, const utf8* url, const mbWindowFeatures* windowFeatures)
{
    mbWebView mbView = mbCreateWebWindow(MB_WINDOW_TYPE_POPUP, NULL, 110, 60, 600, 700);
    ::mbOnCreateView(mbView, handleCreateView, nullptr);
    ::mbSetNavigationToNewWindowEnable(mbView, true);
    ::mbSetCspCheckEnable(mbView, true);

    ::mbShowWindow(mbView, TRUE);
    return mbView;
}

static BOOL MB_CALL_TYPE handleLoadUrlBegin(mbWebView webView, void* param, const char* url, void* job)
{
    printf("handleLoadUrlBegin: %s\n", url);
    //     std::string urlStr("handleLoadUrlBegin:");
    //     urlStr += url;
    //     urlStr += "\n";
    //     OutputDebugStringA(urlStr.c_str());

    //     if (hookUrl(job, url, "universal-report.min.js", L"G:\\test\\web_test\\51iwifi\\universal-report.min.js", "text/html"))
    //         return true;
    // 
    //     if (hookUrl(job, url, "_app-f54e3843f15fa10c7198.js", L"D:\\test\\web\\cc_163\\_app-f54e3843f15fa10c7198.js", "text/javascript"))
    //         return true;
    // 
    //     if (hookUrl(job, url, "act/webcc/link-pk-game/v1.9.1/index.js", L"D:\\test\\web\\cc_163\\webcc_191_index.js", "text/javascript"))
    //         return true;
    // 
    //     if (hookUrl(job, url, "act/webcc/performance-reporter/v1.2.0/index.js", L"D:\\test\\web\\cc_163\\performance-reporter.js", "text/javascript"))
    //         return true;
    // 
    if (0 != strstr(url, "mini_original.js?v")) {
        mbNetChangeRequestUrl(job, "http://192.168.83.1:8080/mini_original.js");
    }
    return TRUE;
}

int main()
{
//     printf("wkexe 11\n");
//     void* g_hMiniblinkMod = dlopen("/home/daniel/Desktop/wkexe/miniblink.so", RTLD_LAZY);
//     printf("wkexe 22: %p\n", g_hMiniblinkMod);
    mbInit(nullptr);
    printf("wkexe: %p\n", handleLoadUrlBegin);

    mbWebView mbView = mbCreateWebWindow(MB_WINDOW_TYPE_POPUP, NULL, 100, 50, 600, 700);
    ::mbOnLoadUrlBegin(mbView, handleLoadUrlBegin, nullptr);
    ::mbOnCreateView(mbView, handleCreateView, nullptr);
    ::mbSetNavigationToNewWindowEnable(mbView, true);
    //mbLoadURL(mbView, "view-source:https://www.baidu.com");
    //mbLoadURL(mbView, u8"view-source:/home/euweb/桌面/mini_electron/linux/main4.htm");
    //::mbLoadURL(mbView, "https://www.jjwxc.net/");
    ::mbLoadURL(mbView, "https://www.qidian.com/");

    ::mbShowWindow(mbView, TRUE);
    ::mbRunMessageLoop();
}