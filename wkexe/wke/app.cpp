
#define _CRT_SECURE_NO_WARNINGS
#include "app.h"
#include "cmdline.h"
#include "path.h"

#include "G:/mycode/miniblink57/wke/wkedefine.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>

#include <shellapi.h>
#pragma comment(lib, "shell32.lib")

#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

#include "TestWnd.h"
#include "RootWindow.h"
#include <commctrl.h>
#include <TlHelp32.h>
#include <string>

bool saveDumpFile(const wchar_t* url, const char* buffer, unsigned int size);
void readFile(const wchar_t* path, std::vector<char>* buffer);
static bool hookUrl(void* job, const char* url, const char* hookedUrl, const wchar_t* localFile, const char* mime);

static const char* getUrl()
{
    int unuse = 0;
    const char* url = //urlA.c_str();
        "file:///G:/test/web_test/CallNumber/testSocket.html";
        "file:///G:/test/exe_test/npcom/dianxin_npplay.html";
        "https://www.sofascore.com";
        "file:///M:/doc/fingerprint/testfp/browserleaks_geo/test.htm";
        "https://ltao.seller.taobao.com/portal/login";
        "https://chowsangsang.tmall.com/";
        "file:///M:/doc/fingerprint/testfp/browserleaks_fonts/BrowserLeaks.html";
        "http://www.wamibao.com:8066/pages/CallNumber/pushDataCallNumber.html?id=abc1111&adCenterID=1";
        "http://aola.100bt.com/h5/";
        "https://www.yuque.com/yuque/ng1qth/dashboard";
        "http://news.4399.com/login/kbxy.html?pass=1";
        "file:///M:/doc/fingerprint/testfp/browserleaks_webrtc/Timezone.htm";
     
        "file:///G:/test/web_test/testSocket.html";
        "http://chat.workerman.net/";
        "http://103.203.219.153/nipissc/adminControl.action";
        "file:///G:/test/exe_test/Test53kf/test.html";
        "https://admindev.xinxcloud.com/login";
        "https://auth-preprod.ehealth.gov.ua/sign-in?client_id=9a1269f7-b001-43fb-bc8c-32ca4ce80a36&redirect_uri=https://eh-srv-preprod.mcmed.ua/&scope=capitation_report:read client:read connection:delete connection:read connection:refresh_secret connection:write contract:read contract:write contract_request:approve contract_request:create contract_request:read contract_request:sign contract_request:terminate declaration:read declaration_request:approve declaration_request:read declaration_request:reject declaration_request:write division:activate division:deactivate division:details division:read division:write employee:deactivate employee:details employee:read employee:write employee_request:approve employee_request:read employee_request:reject employee_request:write employee_role:read employee_role:write healthcare_service:read healthcare_service:write legal_entity:read medication_dispense:read medication_request:details otp:read otp:write person:read reimbursement_report:read related_legal_entities:read secret:refresh&email=markl@ukr.net&response_type=code";
        "file:///G:/test/web_test/videoblink.htm";
        "http://static.newayz.com/sv/videoblink.html";
        "file:///G:/test/web_test/zzz_test/html_/table_test1.html";
        "file:///G:/test/exe_test/npcom/193_168_10_95_8080/index.htm";
        "http://192.168.10.95:8080/cpoe-ui-server/?system=OUTP_DOCTOR#page._sde_new_template_";
       
        "file:///G:/test/exe_test/seconddev/secondDevelpment_new/cn/demo.html";
        "https://yunpan.360.cn/file/index#/fileManage/my/file/%2F";
        "file:///G:/test/web_test/nowifi.html";

        "https://ant.design/docs/react/introduce-cn";
        "file:///G:/test/web_test/zzz_test/queen.htm";
        "http://192.168.0.110:8000/vxe-demo/dist/index.html";
        "https://chowsangsang.tmall.com";
        "https://xuliangzhan_admin.gitee.io/vxe-table/#/table/scroll/scroll";

        "file:///G:/test/web_test/element/test_gc.htm";
        "https://element.eleme.cn/#/zh-CN/component/button";
       
        //"file:///G:/test/web_test/slow_demo/test_nodejs.htm";
        "file:///G:/test/web_test/pdf_np_bug/2.html";
        "https://store.steampowered.com/news/collection/featured/";
        "file:///G:/test/web_test/KT8003(C)2.6.8/IDCard_test.htm"
        "file:///G:/test/exe_test/npcom/Test123/editor-test.html";
        "http://demo.finebi.com/";
        "file:///G:/test/web_test/poc/poc-1/poc-1.html";
        "file:///G:/test/web_test/testherf/testhref.html";
        "file:///G:/test/exe_test/npcom/Tool-Test/Tool_test.html";
        "file:///G:/chromium_70_support_xp/src/chrome/test/data/select.html";
        "file:///G:/test/web_test/test_download.htm";
        "http://192.168.9.240:13000/#/"; // 供电系统测试网站
        "file:///G:/test/web_test/mgtv/test.htm";
        "http://demo.gin-vue-admin.com/#/login";
        "file:///G:/chromium_70_support_xp/src/chrome/test/data/select.html";
        "file:///P:/test/web_test/test_js_timer.html";
        "https://router.vuejs.org/api/";
        "https://tigerkin.net/aboutus?idx=1";
        "http://192.168.222.1:3010/aboutus?idx=1";
        "https://tigerkin.net/aboutus?idx=1";
        "http://192.168.0.103:8000/test_work_fetch.htm";
        "http://192.168.0.103:8000/bufferAll.html";
        "file:///G:/test/web_test/AnyChatWeb/src/AnyChatWebDemo/index.html";
        "file:///G:/test/web_test/53kf_socketio/2222.html";
        "http://www.7k7k.com/special/aola/";
        "https://www.bet365.dk/#/OF/";
        "yun.ysszzs.com";
        "https://www.layui.com/admin/std/dist/views/";
        "https://learning.hitecloud.cn/learning/default/index"; // 下拉菜单无效
        "file:///G:/test/web_test/shopee/recaptcha.htm";
        "file:///G:/test/web_test/shopee/hook_post.html";
        "file:///G:/test/web_test/nodejs.htm"; // QQ浏览器居然打开这个url就崩溃了
        "http://to.dke.cn/oY0c5w1t7C";
        "https://seller.xiapi.shopee.cn";
        "file:///G:/test/web_test/honghe_slow/run.htm";
        "https://www.hitecloud.cn/"; // v8 7.5很卡
        "file:///G:/test/web_test/input.htm";
        "https://www.w3school.com.cn/js/index.asp";
        "http://hn.gsxt.gov.cn/%7BEB023E5A83239F887014F959A1FF1DC4A0D69E66C6B0EE86BA1AC3A7D1627713FE88D6BE82226A7D7BA2B5B3FB165EFEA1451EEAD5CB63BFA1FA06DAC4D40324B935B935B99E038FA81EE06CE06CE07DCB47F77BF770FC4AC64AFA76C6FE8C6EDD0E37CF91732EC31AE2AF28981498917366602DD58B69FF1D080E074F585E1660827A37108D018D018D-1611158297511%7D";
        "http://hn.gsxt.gov.cn/corp-query-homepage.html";
        "file:///G:/test/web_test/newenergy/index.html";
        "file:///G:/test/web_test/wordpress/test.htm";
        "http://u.loon.com.cn/dell/wp-admin/post-new.php"; // 上传问题
        
        "https://observablehq.com/@d3/zoom-to-bounding-box";
        
        "file:///P:/test/web_test/vuetify_slow/index.htm";

        "https://vuetifyjs.com/zh-Hans/components/buttons/";
        "https://saodiyang.gitee.io/layui-soul-table/#/zh-CN/component/changelog";
        "file:///C:/test/web_test/reactjs_test/index.htm";
        "https://mms.pinduoduo.com/login?redirectUrl=https%3A%2F%2Fmms.pinduoduo.com%2Fhome%2F";
        "file:///G:/test/web_test/updata_proj/bin_2020.12.3_1/updata/1.htm";
        "http://127.0.0.1:8080/T01.html";
        "http://192.168.56.1:8000/index.htm";
        "http://192.168.56.1:8000/layui-soul-table.htm#/zh-CN/component/changelog";
        "http://192.168.56.1:8000/ajax.htm";

        "file:///G:/test/web_test/baidupan/html/land.html";
        "https://v.qq.com/x/cover/mzc00200n9j7blz.html";
        "https://v.6.cn/81788";
        "https://mp.toutiao.com/auth/page/login/?redirect_url=JTJG";
        "file:///G:/up5.html";
        "https://www.animejs.cn/documentation/#linearEasing";
        "http://02.build.kelexuexi.com";
        "file:///G:/test/web_test/kelexuexi/knowledge-matching/test.html";
        "file:///G:/test/web_test/kelexuexi/0017/index.html";
        
        "file:///D:/savedata/WeChat%20Files/weolar/FileStorage/File/2020-10/bugs/index.html";
        "https://www.aixuebanban.com/teacher/filemanager";
        "file:///G:/test/pakage/cef/index.html";
        "https://m.sm.cn/s?q=ui%E8%AE%BE%E8%AE%A1&from=smor&safe=1&by=suggest&snum=6";
        "file:///G:/test/exe_test/BlackList Test/Release/view/view.html";
        "file:///G:/test/exe_test/zhi cheng/1.htm";
        "file:///G:/test/web_test/flash_mouse/4399_60369_2.htm";
        "https://www.zhihu.com/zvideo/1282736240719126528";
        "https://uland.taobao.com/sem/tbsearch?keyword=%E6%BC%8F%E7%94%B5%E4%BF%9D%E6%8A%A4%E5%99%A8&refpid=mm_26632360_8858797_29866178&clk1=fdf97170963995b16d98e7fa24a68226&upsid=fdf97170963995b16d98e7fa24a68226";
        "file:///G:/test/web_test/taobaosou/load.htm";

        "Https://dream2023.gitee.io/f-render/";
        "file:///G:/test/web_test/huzhiyong_saidao/checkMobile.html";
        "file:///G:/test/web_test/huzhiyong_saidao/index.htm";
        "file:///G:/test/web_test/openlayers/image.html";
        "file:///G:/test/exe_test/test-linkease/web/index.html";
        "file:///E:/cache/qqcache/93527630/FileRecv/checkMobile.html";
        "file:///e:/test/web_test/Adeds/scroll.htm";
        "file:///e:/test/web_test/touch/checkTouch.html";
        "file:///G:/test/web_test/icoc/i18l.htm";
        "file:///G:/m75_xp-/src/chrome/test/data/permissions/flash.html";
        "file:///G:/test/web_test/baidupan/try_win_focus.htm";

        "file:///G:/test/web_test/test_frame/iframe.html";
        "http://pic.55.la/";

        "file:///G:/test/web_test/ggzuhao/click_input.html";
        "file:///G:/cache/qqcache/93527630/FileRecv/click_input.html";
        "https://www.w3school.com.cn/tiy/t.asp?f=html5_draganddrop";
        "file:///G:/test/web_test/tuoshao/2/index.html";
        "file:///G:/test/web_test/58/accept.htm";
        "http://localhost:4438/";
        "https://testmbperf.azurewebsites.net/";
        "https://zoom.okta.com/";
        "file:///G:/test/web_test/baidupan/test.htm";
        "file:///G:/test/web_test/tuoshao/1/index.html";
        "file:///G:/test/web_test/qianbahang/test/1.htm";
        "so.com";
        "https://login.zhipin.com/?ka=header-login";
        "http://1.205.23.121:7418/";
        "file:///G:/test/web_test/crash/index.html";
        "https://apexcharts.com/javascript-chart-demos/area-charts/irregular-timeseries/";
        "file:///G:/test/web_test/qianbahang/input.htm";
        "file:///G:/test/web_test/qianbahang/demo_k.html";
        "file:///G:/test/web_test/tuoshao/test_math_crash.htm";
        "http://zhilian.hitecloud.net/workappraise/#/web/home?mtoken=34331ad9c408630e6ab67adb76983b01";
        "https://gzgsv.xpshop.cn";
        "http://xyx.yulebuyu.com/140/";
        "file:///G:/test/web_test/tuoshao/bad/index.html";
        "file:///G:/test/web_test/tuoshao/index.html";
        "file:///G:/test/exe_test/qian/html/login.html";
        "bing.com";
        "https://wwo.wps.cn/office/w/134384?_w_appid=da03aba1141748ddaf1d743c577351ce&_w_fileid=134384&_w_filetype=Local&_w_ispreview=False&_w_machine=WIN-830B5K236TD&_w_userid=37659&_w_signature=OMugya%2bJexFV6HymImfBBYtKg%2fI%3d";
        "file:///K:/NetMiniblink/svgerr/index.html";
        "https://voice.baidu.com/act/newpneumonia/newpneumonia/?from=osari_pc_1";
        "http://ueditor.baidu.com/website/umeditor.html";
        "file:///E:/mycode/chromium/trunk/src/third_party/WebKit/LayoutTests/svg/as-image/resources/100px-green-rect.svg";
        "file:///G:/test/web_test/58/wbrTest.html";
        "http://api.soft.china.com/note/login?qq-pf-to=pcqq.c2c";
        "file:///G:/test/web_test/webhqchart.demo/demo/hq.html";
        "file:///G:/test/web_test/jq22/print.html";
        "https://zhuanlan.zhihu.com/p/134669417";
        "file:///G:/test/web_test/jq22/main.htm";
        "file:///G:/test/exe_test/HongheQtDemo/Bin/MathSubject/DyCourseware/GeoGebra/HTML5/5.0/previewggb.html";
        
    return url;
}

bool WKE_CALL_TYPE handleLoadUrlBegin(wkeWebView webView, void* param, const char* url, void* job)
{
    OutputDebugStringA("handleLoadUrlBegin:");
    OutputDebugStringA(url);
    OutputDebugStringA("\n");
    
//     if (0 != strstr(url, "shadow.elemecdn.com/npm/vue@2.5.21/dist/vue.runtime.min.js")) {
//         wkeNetHookRequest(job);
//         //wkeNetChangeRequestUrl(job, "http://192.168.88.101:8000/van-analysis.min.js");
//         return true;
//     }

//     if (hookUrl(job, url, "moment.min.js", L"G:\\test\\web_test\\yuque\\moment.min.js", "text/javascript"))
//         return true;
// 
//     if (hookUrl(job, url, "pc.b1a27981.js", L"G:\\test\\web_test\\yuque\\pc.b1a27981.js", "text/javascript"))
//         return true;
//
//     if (hookUrl(job, url, "common.d8a477ba.async.js", L"G:\\test\\web_test\\yuque\\common.d8a477ba.async.js", "text/javascript"))
//         return true;
// 
//     if (hookUrl(job, url, "p__doc__routers.eb18ae3b.async.js", L"G:\\test\\web_test\\yuque\\p__doc__routers.eb18ae3b.async.js", "text/javascript"))
//         return true;
// 
//     if (hookUrl(job, url, "api-fetch.min.js", L"G:\\test\\web_test\\wordpress\\api-fetch.min.js", "text/javascript"))
//         return true;
// 
//     if (hookUrl(job, url, "wp-polyfill.min.js", L"G:\\test\\web_test\\wordpress\\wp-polyfill.min.js", "text/javascript"))
//       return true;
//
//     if (hookUrl(job, url, "editor.min.js", L"G:\\test\\web_test\\wordpress\\editor.min.js", "text/javascript"))
//         return true;

//     if (hookUrl(job, url, "media-utils.min.js", L"G:\\test\\web_test\\wordpress\\media-utils.min.js", "text/javascript"))
//         return true;

// 
//     if (hookUrl(job, url, "kmd-adapter/0.1.5/util.js", L"G:\\test\\web_test\\taobaosou\\util.js", "text/javascript"))
//         return true;
// 
//     if (hookUrl(job, url, "mtop.js", L"G:\\test\\web_test\\taobaosou\\mtop.js", "text/javascript"))
//         return true;

    // secdev/entry/index.js

    //     static int s_count = 0;
    //     if (0 != strstr(url, "scan/test.png?id")) {
    //         s_count++;
    // 
    //         char* output = (char*)malloc(0x100);
    //         sprintf_s(output, 0x99, "file:///G:/test/web_test/ueditor/QQ-%d.png", s_count % 2);
    // 
    //         wkeNetChangeRequestUrl(job, output);
    //         free(output);
    // 
    //         return true;
    //     }
    //
    // 
    //     if (0 != strstr(url, ".css")) {
    // //         wkeNetSetMIMEType(job, (const char*)"text/css");
    // //         wkeNetSetData(job, " ", 1);
    //         wkeNetHookRequest(job);
    //         return true;
    //     }

    //wkeNetHookRequest(job);

    return false;
}

void WKE_CALL_TYPE handleLoadUrlEnd(wkeWebView webView, void* param, const char* url, void* job, void* buf, int len)
{
    if (0 == len)
        return;

    OutputDebugStringA("handleLoadUrlEnd::");
    OutputDebugStringA(url);
    OutputDebugStringA("\n");

    std::vector<char> dump(len);
    memcpy(dump.data(), buf, len);
    dump.push_back('\0');

    if (0 != strstr(dump.data(), "IntersectionObserver")) {
        saveDumpFile(L"p:\\1.js", (const char *)buf, len);
        OutputDebugStringA("");
    }

//     std::vector<char> buffer;
//     readFile(L"G:\\test\\web_test\\finebi\\van-analysis.min.js", &buffer);
// 
//     wkeNetSetData(job, buffer.data(), buffer.size());

//     if (0 != strstr(url, "IntersectionObserver") ) {
//         std::string strBuff((const char*)buf, len);
//         OutputDebugStringA("");
//     }
    // 
    //     const wkeSlist* xx = wkeNetGetRawResponseHead(job);
    // 
    //     OutputDebugStringA("handleLoadUrlEnd\n");
}

std::string utf16ToChar(LPCWSTR lpszSrc, UINT codepage)
{
    std::string sResult;
    if (lpszSrc != NULL) {
        int  nUTF8Len = WideCharToMultiByte(codepage, 0, lpszSrc, -1, NULL, 0, NULL, NULL);
        char* pUTF8 = new char[nUTF8Len + 1];
        if (pUTF8 != NULL) {
            ZeroMemory(pUTF8, nUTF8Len + 1);
            WideCharToMultiByte(codepage, 0, lpszSrc, -1, pUTF8, nUTF8Len, NULL, NULL);
            sResult = pUTF8;
            delete[] pUTF8;
        }
    }
    return sResult;
}

std::wstring utf8ToUtf16(const std::string& utf8)
{
    std::wstring utf16;
    size_t n = ::MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), utf8.size(), nullptr, 0);
    if (0 == n)
        return L"";
    std::vector<wchar_t> wbuf(n);
    ::MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), utf8.size(), &wbuf[0], n);
    utf16.resize(n + 5);
    utf16.assign(&wbuf[0], n);
    return utf16;
}

std::string utf8ToGBK(const std::string& utf8)
{
    std::wstring temp = utf8ToUtf16(utf8);
    if (0 == temp.size())
        return "";
    return utf16ToChar(temp.c_str(), CP_ACP);
}

BOOL fixupHtmlFileUrl(LPCWSTR pathOption, LPWSTR urlBuffer, size_t bufferSize)
{
    WCHAR htmlPath[MAX_PATH + 1] = { 0 };

    if (pathOption[0] == 0) {
        do {
            GetWorkingPath(htmlPath, MAX_PATH, L"index.html");
            if (PathFileExistsW(htmlPath))
                break;

            GetWorkingPath(htmlPath, MAX_PATH, L"main.html");
            if (PathFileExistsW(htmlPath))
                break;

            GetWorkingPath(htmlPath, MAX_PATH, L"wkexe.html");
            if (PathFileExistsW(htmlPath))
                break;

            GetProgramPath(htmlPath, MAX_PATH, L"index.html");
            if (PathFileExistsW(htmlPath))
                break;

            GetProgramPath(htmlPath, MAX_PATH, L"main.html");
            if (PathFileExistsW(htmlPath))
                break;

            GetProgramPath(htmlPath, MAX_PATH, L"wkexe.html");
            if (PathFileExistsW(htmlPath))
                break;

            return FALSE;
        } while (0);

        swprintf_s(urlBuffer, bufferSize, L"file:///%s", htmlPath);
        return TRUE;
    } else//if (!wcsstr(pathOption, L"://"))
    {
        do {
            GetWorkingPath(htmlPath, MAX_PATH, pathOption);
            if (PathFileExistsW(htmlPath))
                break;

            GetProgramPath(htmlPath, MAX_PATH, pathOption);
            if (PathFileExistsW(htmlPath))
                break;

            return FALSE;
        } while (0);

        swprintf_s(urlBuffer, bufferSize, L"file:///%s", htmlPath);
        return TRUE;
    }

    return FALSE;
}

BOOL fixupHtmlUrl(Application* app)
{
    LPWSTR htmlOption = app->options.htmlFile;
    std::vector<WCHAR> htmlUrl;
    htmlUrl.resize(kMaxUrlLegth + 1);

    // 包含 :// 说明是完整的URL
    if (wcsstr(htmlOption, L"://")) {
        wcsncpy_s(app->url, kMaxUrlLegth, htmlOption, kMaxUrlLegth);
        return TRUE;
    }

    // 若不是完整URL，补全之
    if (fixupHtmlFileUrl(htmlOption, &htmlUrl[0], kMaxUrlLegth)) {
        wcsncpy_s(app->url, kMaxUrlLegth, &htmlUrl[0], kMaxUrlLegth);
        return TRUE;
    }
    // 无法获得完整的URL，出错
    return FALSE;
}

BOOL processOptions(Application* app)
{
    int argc = 0;
    LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
    ParseOptions(argc, argv, &app->options);
    LocalFree(argv);

    return TRUE;
}

void WKE_CALL_TYPE handleWillMediaLoad(wkeWebView webView, void* param, const char* url, wkeMediaLoadInfo* info)
{
    info->duration = 12;
    info->width = 650;
    info->height = 370;
}

// 回调：点击了关闭、返回 true 将销毁窗口，返回 false 什么都不做。
bool WKE_CALL_TYPE handleWindowClosing(wkeWebView webWindow, void* param)
{
    Application* app = (Application*)param;
    //return IDYES == MessageBoxW(NULL, L"确定要退出程序吗？", L"wkexe", MB_YESNO|MB_ICONQUESTION);
    //asynStartCreateWnd(wkeGetHostHWND(webWindow));
    //wkeCut(webWindow);

    //wkePerformCookieCommand(wkeCookieCommandClearAllCookies);

    return true;

//     const char* scriptText =
//         "var dom = document.getElementById('myTextField'); dom.focus();";
//     wkeRunJS(webWindow, scriptText);
// 
//     return false;
}

void WKE_CALL_TYPE handleWindowDestroy(wkeWebView webWindow, void* param)
{
    Application* app = (Application*)param;
    if (!app)
        return;
    PostQuitMessage(0);
}

bool saveDumpFile(const wchar_t* url, const char* buffer, unsigned int size)
{
    HANDLE hFile = CreateFileW(url, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if (INVALID_HANDLE_VALUE != hFile) {
        DWORD dwSize = 0;
        WriteFile(hFile, buffer, size, &dwSize, NULL);
        CloseHandle(hFile);
        return TRUE;
    }
    return FALSE;
}

// int enableDebugPriv(const wchar_t* name)
// {
//     HANDLE hToken;
//     TOKEN_PRIVILEGES tp;
//     LUID luid;
// 
//     if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
//         return -1;
//     }
// 
//     if (!LookupPrivilegeValueW(NULL, name, &luid)) {
//         fprintf(stderr, "LookupPrivilegeValue error\n");
//     }
// 
//     tp.PrivilegeCount = 1;
//     tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
//     tp.Privileges[0].Luid = luid;
// 
//     if (!AdjustTokenPrivileges(hToken, 0, &tp, sizeof(TOKEN_PRIVILEGES), NULL, NULL)) {
//         return -1;
//     }
// 
//     return 0;
// 
// }
// 
// jsValue WKE_CALL_TYPE jsCheckIsProcess(jsExecState es, void* param)
// {
//     enableDebugPriv(SE_DEBUG_NAME);
// 
//     jsValue val = jsArg(es, 0);
//     DWORD processId  = jsToInt(es, val);
//     HANDLE processHandle = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//     if (processHandle == INVALID_HANDLE_VALUE)
//         return jsFalse();
// 
//     bool result = false;
//     int i = 0;
//     PROCESSENTRY32W pe32;
//     pe32.dwSize = sizeof(PROCESSENTRY32W);
//     bool needContinue = ::Process32First(processHandle, &pe32);
//     while (needContinue) {
//         if (pe32.th32ProcessID == processId) {
//             result = true;
//             break;
//         }
//         i++;
// 
//         needContinue = ::Process32Next(processHandle, &pe32);
//     }
// 
//     ::CloseHandle(processHandle);
//     return result ? jsTrue() : jsFalse();
// }
// 
// jsValue WKE_CALL_TYPE jsNotifyIcon(jsExecState es, void* param)
// {
//     jsValue val = jsArg(es, 0);
// 
//     wkeMemBuf* buf = jsGetArrayBuffer(es, jsArg(es, 0));
// 
//     wkeWebView  webView = jsGetWebView(es);
//     HWND wnd = wkeGetHostHWND(webView);
//     
//     std::vector<wchar_t> tempPathBuffer;
//     tempPathBuffer.resize(MAX_PATH);
//     ::GetTempPath(MAX_PATH, tempPathBuffer.data());
//     ::PathAppend(tempPathBuffer.data(), L"mb_temt_icon.ico");
// 
//     ::DeleteFileW(tempPathBuffer.data());
//     saveDumpFile(tempPathBuffer.data(), (const char *)buf->data, buf->length);
// 
//     HWND rootWnd = wnd;
//     do {
//         rootWnd = wnd;
//         wnd = ::GetParent(rootWnd);
//     } while (wnd);
//     
//     HICON hIcon = (HICON)::LoadImage(
//         NULL,
//         tempPathBuffer.data(),
//         IMAGE_ICON,
//         0, 0,
//         LR_DEFAULTCOLOR | LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
//     ::SendMessage(rootWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
// 
//     return jsUndefined();
// }

jsValue WKE_CALL_TYPE onJsGetPropertyCallback(jsExecState es, jsValue object, const char* propertyName)
{
    return jsInt(22);
}

bool WKE_CALL_TYPE onJsSetPropertyCallback(jsExecState es, jsValue object, const char* propertyName, jsValue value)
{
    return true;
}

jsValue WKE_CALL_TYPE onJsCallAsFunctionCallback(jsExecState es, jsValue object, jsValue* args, int argCount)
{
    return jsInt(11);
}

void WKE_CALL_TYPE onJsFinalizeCallback(jsData* data)
{
    // DebugBreak();
}

// https://blog.csdn.net/yang2011079080010/article/details/52528261
jsValue WKE_CALL_TYPE mbOpenFile(jsExecState es, void* param)
{
    if (2 != jsArgCount(es))
        return jsNull();

    if (!jsIsString(jsArg(es, 0)) || !jsIsString(jsArg(es, 1)))
        return jsNull();

    const wchar_t* path = jsToTempStringW(es, jsArg(es, 0));
    const wchar_t* mode = jsToTempStringW(es, jsArg(es, 1));

    FILE* handle = _wfopen(path, mode);
    if  (!handle)
        return jsNull();

    return jsInt((int)handle);
}

jsValue WKE_CALL_TYPE mbWriteFile(jsExecState es, void* param)
{
    if (2 != jsArgCount(es))
        return jsInt(0);

    if (!jsIsNumber(jsArg(es, 0)))
        return jsInt(0);

    FILE* handle = (FILE*)jsToInt(es, jsArg(es, 0));
    if (!handle)
        return jsInt(0);

    wkeMemBuf* buf = jsGetArrayBuffer(es, jsArg(es, 1));
    if (!buf || 0 == buf->length)
        return jsInt(0);

    size_t size = fwrite(buf->data, 1, buf->length, handle);
    return jsInt((int)size);
}

jsValue WKE_CALL_TYPE mbReadFile(jsExecState es, void* param)
{
    if (1 != jsArgCount(es))
        return jsNull();

    if (!jsIsNumber(jsArg(es, 0)))
        return jsNull();

    FILE* handle = (FILE*)jsToInt(es, jsArg(es, 0));
    if (!handle)
        return jsNull();

    fseek(handle, 0, SEEK_END);
    size_t size = ftell(handle);
    fseek(handle, 0, SEEK_SET);
    if (0 == handle)
        return jsNull();

    void* buffer = malloc(size);

    size_t readSize = fread(buffer, 1, size, handle);
    return jsArrayBuffer(es, (const char*)buffer, readSize);
}

jsValue WKE_CALL_TYPE mbCloseFile(jsExecState es, void* param)
{
    if (1 != jsArgCount(es))
        return jsUndefined();

    if (!jsIsNumber(jsArg(es, 0)))
        return jsUndefined();

    FILE* handle = (FILE*)jsToInt(es, jsArg(es, 0));
    if (!handle)
        return jsUndefined();
    fclose(handle);
    return jsUndefined();
}

jsValue WKE_CALL_TYPE js_JSCallback_test(jsExecState es, jsValue object, jsValue* args, int argCount)
{
    jsValue param1 = args[0];
    jsValue param2 = args[1];
    jsValue param3 = args[3];

    jsType type = jsTypeOf(param2);
    int arrarLength = jsGetLength(es, param2);

    jsValue result = jsGetAt(es, param2, 2);
    type = jsTypeOf(result);

    result = jsGetAt(es, param2, 3);
    type = jsTypeOf(result);

    return jsInt(222);
}

jsValue WKE_CALL_TYPE bindFunction(jsExecState es, jsValue object, const char *name, jsCallAsFunctionCallback func)
{
    jsData *data = new jsData{ 0 };
    data->callAsFunction = func;

    jsValue v = jsFunction(es, data);
    jsSet(es, object, name, v);
    return v;
}

static jsValue WKE_CALL_TYPE js_callAsFunction(jsExecState es, jsValue object, jsValue* args, int argCount)
{
    const wchar_t* jxx = jsToTempStringW(es, jsArg(es, 0));
    
    wkeSetFocus(wkeGetWebViewForCurrentContext());

    return jsInt(0);
}

static void WKE_CALL_TYPE js_releaseFunction(jsData* data)
{
    delete data;
}

static void bindToGlobal(jsExecState es)
{
    jsData* data = new jsData();
    memset(data, 0, sizeof(jsData));
    strcpy_s(data->typeName, "Function");
    data->callAsFunction = js_callAsFunction;
    data->finalize = js_releaseFunction;

    jsValue func = jsFunction(es, data);
    jsSetGlobal(es, "testbutton", func);
}

void WKE_CALL_TYPE onNetGetFavicon(wkeWebView webView, void* param, const utf8* url, wkeMemBuf* buf)
{
    OutputDebugStringA("");
}

// 回调：文档加载成功
void WKE_CALL_TYPE handleDocumentReady(wkeWebView webWindow, void* param)
{
    wkeShowWindow(webWindow, TRUE);

    //wkeRunJS(webWindow, "setTimeout(function(){console.log('ok')},1000)");

    //jsExecState es = wkeGlobalExec(webWindow);

    //jsValue window = jsGlobalObject(es);
    //wkeWebView testWebview = jsGetWebView(es);

    //bindFunction(es, window, "JSCallback_test", js_JSCallback_test);
    //jsValue rootObj = jsGlobalObject(es);

    //bindToGlobal(es);
    //     jsValue val = jsGet(es, rootObj, "initialize");
    // 
    //     //wkeResize(webWindow, 100, 100);
    //     wkeRepaintIfNeeded(webWindow);
    // 
    //     bool isFun = jsIsString(val);
    //     OutputDebugStringA("isFun:"); OutputDebugStringA(isFun ? "true\n" : "false\n");
    // 
    //     isFun = jsIsFunction(val);
    //     OutputDebugStringA("isFun:"); OutputDebugStringA(isFun ? "true\n" : "false\n");
    // 
    //     isFun = jsIsUndefined(val);
    //     OutputDebugStringA("isFun:"); OutputDebugStringA(isFun ? "true\n" : "false\n");
    // 
    //     isFun = jsIsNull(val);
    //     OutputDebugStringA("isFun:"); OutputDebugStringA(isFun ? "true\n" : "false\n");
    // 
//     jsValue jsFunc = jsGet(es, rootObj, "onHitTest");
//     
//     jsValue args[3] = { 0 };
//     args[0] = jsInt(1);
//     args[1] = jsInt(2);
// 
//     //jsData* obj = { "testJsData", onJsGetPropertyCallback, onJsSetPropertyCallback, onJsFinalizeCallback, onJsCallAsFunctionCallback};
//     jsData* obj = new jsData();
//     obj->propertyGet = onJsGetPropertyCallback;
//     obj->propertySet = onJsSetPropertyCallback;
//     obj->finalize = onJsFinalizeCallback;
//     obj->callAsFunction = onJsCallAsFunctionCallback;
//     args[2] = jsObject(es, obj);
// 
//     jsValue jsRet = jsCall(es, jsFunc, rootObj, args, 3);

    return;
}

static std::wstring getVersionString()
{
    static std::wstring* s_title = nullptr;
    if (s_title)
        return *s_title;

    std::vector<wchar_t> versionPath;
    versionPath.resize(MAX_PATH);
    ::GetModuleFileNameW(nullptr, &versionPath[0], MAX_PATH);
    ::PathRemoveFileSpecW(&versionPath[0]);
#ifdef _WIN64
    ::PathAppend(&versionPath[0], L"miniblink_x64.dll");
#else
    ::PathAppend(&versionPath[0], L"node.dll");
#endif
    wchar_t versionCurrent[35];
    DWORD fileVersionSize = ::GetFileVersionInfoSizeW(&versionPath[0], 0);
    wchar_t * lpData = new wchar_t[fileVersionSize];
    if (!::GetFileVersionInfoW(&versionPath[0], NULL, fileVersionSize, lpData)) {
        delete lpData;
        return L"";
    }

    VS_FIXEDFILEINFO *versionInfo;
    PUINT uint = 0;
    if (!VerQueryValueW(lpData, L"\\", (LPVOID*)&versionInfo, uint)) {
        delete lpData;
        return L"";
    }
    wnsprintf(versionCurrent, 35, L" [%d.%d.%d.%d] ",
        HIWORD(versionInfo->dwProductVersionMS),
        LOWORD(versionInfo->dwProductVersionMS),
        HIWORD(versionInfo->dwProductVersionLS),
        LOWORD(versionInfo->dwProductVersionLS));

    s_title = new std::wstring(versionCurrent);
    return *s_title;
}

void WKE_CALL_TYPE handleTitleChanged(wkeWebView webWindow, void* param, const wkeString title)
{
    std::wstring titleString = wkeGetStringW(title);
    titleString = L"Miniblink" + getVersionString() + titleString;

    HWND hWnd = wkeGetHostHWND(webWindow);
    hWnd = ::GetParent(hWnd);
    ::SetWindowText(hWnd, titleString.c_str());
}

static void WKE_CALL_TYPE onAlert(wkeWebView webView, void* param, const wkeString msg)
{
    const utf8* callstack = jsGetCallstack(nullptr);
    const wchar_t* message = wkeGetStringW(msg);
    MessageBoxW(NULL, message, L"MB", 0);
}

void WKE_CALL_TYPE onLoadingFinish(wkeWebView webView, void* param, const wkeString url, wkeLoadingResult result, const wkeString failedReason)
{
    //wkeNetGetFavicon(webView, onNetGetFavicon, nullptr);
    OutputDebugStringA("onLoadingFinish\n");
}

static void initSettings(wkeWebView webWindow);

// 回调：创建新的页面，比如说调用了 window.open 或者点击了 <a target="_blank" .../>
wkeWebView WKE_CALL_TYPE handleCreateView(wkeWebView webWindow, void* param, wkeNavigationType navType, const wkeString url, const wkeWindowFeatures* features)
{
    RootWindow* rootWin = new RootWindow();
    wkeWebView newWindow = rootWin->createRootWindow();
    initSettings(newWindow);

    wkeShowWindow(newWindow, true);
    //wkeSetHeadlessEnabled(newWindow, true);
    //wkeSetDebugConfig(newWindow, "setCookieJarPath", "d:\\");
    return newWindow;
}

void* fileOpenHook(const char* path)
{
    FILE* handle = nullptr;
    fopen_s(&handle, path, "rb");
    return handle;
}

void fileCloseHook(void* handle)
{
    fclose((FILE*)handle);
}

int fileReadHook(void* handle, void* buffer, size_t size)
{
    if (0 == size)
        return 0;
    int result = fread(buffer, size, 1, (FILE*)handle);
    return result * size;
}

size_t fileSizeHook(void* handle)
{
    if (!handle)
        return 0;

    fseek((FILE*)handle, 0, SEEK_END);
    long pos = ftell((FILE*)handle);
    fseek((FILE*)handle, 0, SEEK_SET);
    return pos;
}

int fileSeekHook(void* handle, int offset, int origin)
{
    return 0;
}

void readFile(const wchar_t* path, std::vector<char>* buffer)
{
    HANDLE hFile = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile) {

        std::vector<WCHAR> filenameBuffer;
        filenameBuffer.resize(MAX_PATH + 3);
        ::GetModuleFileNameW(NULL, filenameBuffer.data(), MAX_PATH);
        ::PathRemoveFileSpecW(filenameBuffer.data());

        ::PathAppendW(filenameBuffer.data(), L"node.exp");
        if (::PathFileExistsW(filenameBuffer.data()))
            DebugBreak();
        return;
    }

    DWORD fileSizeHigh;
    const DWORD bufferSize = ::GetFileSize(hFile, &fileSizeHigh);

    DWORD numberOfBytesRead = 0;
    buffer->resize(bufferSize);
    BOOL b = ::ReadFile(hFile, &buffer->at(0), bufferSize, &numberOfBytesRead, nullptr);
    ::CloseHandle(hFile);
    b = b;
}

bool WKE_CALL_TYPE handleNavigationCallback(wkeWebView webView, void* param, wkeNavigationType navigationType, const wkeString url)
{
    const wchar_t* urlW = wkeGetStringW(url);
    return true;
}

bool WKE_CALL_TYPE onDownloadCallback(wkeWebView webView, void* param, const char *url)
{
    //OutputDebugStringA("onDownloadCallback\n");
    return false;
}

bool WKE_CALL_TYPE onResponseCallback(wkeWebView webView, void* param, const char* url, void* job)
{
    wkeNetGetHTTPHeaderFieldFromResponse(job, "content-type");

//     wkeString mime = wkeCreateStringW(L"", 0);
//     wkeNetGetMIMEType(job, mime);
//     const utf8* mimeString = wkeGetString(mime);
// 
//     //http://static.ws.126.net/f2e/modules/ne2015/common-nav/images/products_sprites0727.svg
// 
//     std::string output = "onResponseCallback:[";
//     output += url;
//     output += "], [";
//     output += mimeString;
//     output += "]\n";
// 
//     OutputDebugStringA(output.c_str());
// 
//     wkeDeleteString(mime);

    return false;
}

void WKE_CALL_TYPE onDocumentReady2(wkeWebView webView, void* param, wkeWebFrameHandle frameId)
{
//     jsExecState es = wkeGlobalExec(webView);
//     jsValue document = jsEval(es, "console.log(\"{0}* { 1 }\", (1 == 2 ? 3 : 4) / 2, \"10\");");
//     jsValue getElementById = jsGet(es, document, "getElementById");
// 
//     jsValue win = jsEval(es, "return window");
//     jsValue GetElementById = jsGet(es, win, "GetElementById");
// 
//     jsValue s = jsString(es, "kw");
//     jsValue kw = jsCall(es, GetElementById, jsUndefined(), &s, 1);
//     jsType t = jsTypeOf(kw);
//     wkeSetDeviceParameter(webView, "navigator.maxTouchPoints", "win23", 30, 2.0);
//     jsValue v = wkeRunJS(webView, "console.log('navigator.maxTouchPoints:' + navigator.maxTouchPoints);");
    //int b = jsToInt(es, v);
    //b = b;

//   jsValue r = wkeRunJS(webView, "return jsTestCall()");
//   int i = jsToInt(wkeGlobalExec(webView), r);
// 
//   OutputDebugStringA("");

//     wkeViewSettings settings = { sizeof(wkeViewSettings), 0xffffffff };
//     wkeSetViewSettings(webView, &settings);
}

wkeWebView g_testWebview = nullptr;

void WKE_CALL_TYPE onDidCreateScriptContext(wkeWebView webView, void* param, wkeWebFrameHandle frameId, void* context, int extensionGroup, int worldId)
{
     g_testWebview = webView;
//     const utf8* script = "eval('var eC = 1234; var hahaha = eC1 % 2 > 0 ? 0 : 1;console.log(`eC:` + eC)');";
//     wkeRunJsByFrame(webView, frameId, script, false);
     jsExecState es = wkeGlobalExec(webView);
//     jsExceptionInfo* exc = jsGetLastErrorIfException(es);
// 
//     script = "eval('var eC = 1234; var hahaha = eC % 2 > 0 ? 0 : 1;console.log(`eC:` + eC)');";
//     wkeRunJsByFrame(webView, frameId, script, false);
// 
//     exc = jsGetLastErrorIfException(es);
//     exc = exc;
// 
//     jsValue window = jsGlobalObject(es);

     wkeJsBindFunction("mbOpenFile", mbOpenFile, nullptr, 2);
     wkeJsBindFunction("mbWriteFile", mbWriteFile, nullptr, 2);
     wkeJsBindFunction("mbReadFile", mbReadFile, nullptr, 1);
     wkeJsBindFunction("mbCloseFile", mbCloseFile, nullptr, 1);
     
//     const wchar_t* script = L"return 1;";
//     jsValue v = jsEvalExW(es, script, false);
//     jsType t = jsTypeOf(v);
//     t = t;
    OutputDebugStringA("");
}

void WKE_CALL_TYPE onOtherLoadCallback(wkeWebView webView, void* param, wkeOtherLoadType type, wkeTempCallbackInfo* info)
{
    if (WKE_DID_POST_REQUEST == type) {
//         wkePostBodyElements* postBody = info->postBody;
//         for (size_t i = 0; i < postBody->elementSize; ++i) {
//             wkePostBodyElement* element = postBody->element[i];
//             element->type;
//             OutputDebugStringA("");
//         }
    }
}

static void WKE_CALL_TYPE onConsoleCallback(wkeWebView webView, void* param, wkeConsoleLevel level,
    const wkeString message, const wkeString sourceName, unsigned sourceLine, const wkeString stackTrace) 
{
//     const utf8* msg = wkeToString(message);
//     if (nullptr != strstr(msg, "__callstack__")) {
//         OutputDebugStringA("dragenter!!!!\n");
//     }
    OutputDebugStringA("");
}

static double lowResUTCTime()
{
    const double msPerSecond = 1000.0;
#if 1 // OS(WINCE)
    SYSTEMTIME systemTime;
    ::GetSystemTime(&systemTime);
    struct tm tmtime;
    tmtime.tm_year = systemTime.wYear - 1900;
    tmtime.tm_mon = systemTime.wMonth - 1;
    tmtime.tm_mday = systemTime.wDay;
    tmtime.tm_wday = systemTime.wDayOfWeek;
    tmtime.tm_hour = systemTime.wHour;
    tmtime.tm_min = systemTime.wMinute;
    tmtime.tm_sec = systemTime.wSecond;
    time_t timet = mktime(&tmtime);
    return timet * msPerSecond + systemTime.wMilliseconds;
#else
    struct _timeb timebuffer;
    _ftime(&timebuffer);
    return timebuffer.time * msPerSecond + timebuffer.millitm;
#endif
}

double g_time0 = 0;

static bool hookUrl(void* job, const char* url, const char* matchStr, const wchar_t* localFile, const char* mime)
{
    if (0 == strstr(url, matchStr))
        return false;

    // wkeNetSetURL(job, url);
    // wkeNetSetHTTPHeaderField(job, L"Content-Type", L"text/xml", true);
    // "text/html" "text/javascript"
    wkeNetSetMIMEType(job, (const char*)mime); 

    std::vector<char> buffer;
    readFile(localFile, &buffer);
    if (0 == buffer.size())
        return false;

    wkeNetSetData(job, &buffer[0], buffer.size());

    OutputDebugStringA("HookUrl:");
    OutputDebugStringA(matchStr);
    OutputDebugStringA("\n");
    OutputDebugStringA(url);
    OutputDebugStringA("\n\n");

    return true;    
}

HFONT m_hFont = nullptr;

void onPaintX(HWND hWnd, HDC hdc) {
    if (!m_hFont) {
        m_hFont = CreateFont(18, 0, 0, 0, FW_THIN, FALSE, FALSE, FALSE,
            GB2312_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, FIXED_PITCH | FF_MODERN, L"微软雅黑");
    }

    RECT rc = { 0 };
    ::GetClientRect(hWnd, &rc);

    HPEN hCurrentPen = ::CreatePen(PS_SOLID, 1, RGB(126, 126, 126));
    HGDIOBJ hOldPen = SelectObject(hdc, hCurrentPen);
    ::Rectangle(hdc, 0, 0, rc.right - rc.left, rc.bottom - rc.top);
    ::SelectObject(hdc, hOldPen);
    ::DeleteObject(hCurrentPen);

    ::SelectObject(hdc, m_hFont);
    ::SetTextColor(hdc, RGB(86, 86, 86));
    ::SetBkColor(hdc, RGB(255, 255, 255));
    ::TextOut(hdc, 4, 2, L"哈哈aaaa", 6);
}

static void initSettings(wkeWebView webWindow)
{
//     wkeSettings settings;
//     settings.mask = WKE_SETTING_PAINTCALLBACK_IN_OTHER_THREAD;
//     wkeConfigure(&settings);

    wkeSetLanguage(webWindow, "fr-CH,fr;q=0.9");

    //wkeSetDebugConfig(webWindow, "enableNodejs", nullptr);
    wkeSetLanguage(webWindow, "en");
    wkeSetDebugConfig(webWindow, "cutOutsNpapiRects", nullptr);
    wkeSetDebugConfig(webWindow, "wakeMinInterval", "5"); // 最佳搭配是1-200
    wkeSetDebugConfig(webWindow, "drawMinInterval", "300");
    wkeSetDebugConfig(webWindow, "contentScale", "100");
//     wkeSetDebugConfig(webWindow, "disableNavigatorPlugins", "");
//     wkeSetNpapiPluginsEnabled(webWindow, false);
    //wkeSetDebugConfig(webWindow, "tipCallback", (const char*)onPaintX);
    wkeSetCookieEnabled(webWindow, true);
    //wkeSetHeadlessEnabled(webWindow, true);
    wkeSetNavigationToNewWindowEnable(webWindow, false);
    wkeOnWillMediaLoad(webWindow, handleWillMediaLoad, nullptr);
    wkeOnWindowClosing(webWindow, handleWindowClosing, nullptr);
    wkeOnWindowDestroy(webWindow, handleWindowDestroy, nullptr);
    wkeOnDocumentReady(webWindow, handleDocumentReady, nullptr);
    wkeOnTitleChanged(webWindow, handleTitleChanged, nullptr);
    wkeOnCreateView(webWindow, handleCreateView, nullptr);
    wkeOnLoadUrlBegin(webWindow, handleLoadUrlBegin, nullptr);
    wkeOnLoadUrlEnd(webWindow, handleLoadUrlEnd, nullptr);
    wkeOnNavigation(webWindow, handleNavigationCallback, nullptr);
    wkeSetNavigationToNewWindowEnable(webWindow, true);
    wkeOnConsole(webWindow, onConsoleCallback, nullptr);
    //wkeOnAlertBox(webWindow, onAlert, nullptr);
    wkeSetZoomFactor(webWindow, 1.0);
    wkeOnOtherLoad(webWindow, onOtherLoadCallback, nullptr);
    wkeOnLoadingFinish(webWindow, onLoadingFinish, nullptr);
    //wkeSetCookieJarFullPath(webWindow, L"E:\\mycode\\mb49-gee\\out\\Debug\\我\\cookies22.dat");
    //wkeSetContextMenuItemShow(webWindow, kWkeMenuPrintId, true);
    //wkeSetDragDropEnable(webWindow, true);
    wkeSetCspCheckEnable(webWindow, true);
    wkeSetDragEnable(webWindow, false);
    wkeSetNpapiPluginsEnabled(webWindow, true);

    //wkeSetTouchEnabled(webWindow, true);
    wkeSetMouseEnabled(webWindow, true);

    //wkeSetUserAgent(webWindow, "Mozilla/5.0 (iPhone 92; CPU iPhone OS 10_2_1 like Mac OS X) AppleWebKit/602.4.6 (KHTML, like Gecko) Version/10.0 MQQBrowser/7.3 Mobile/14D27 Safari/8536.25 MttCustomUA/2 QBWebViewType/1");
    //wkeSetDeviceParameter(webWindow, "navigator.languages", "zh|111|xxx", 0, 0);

//     static int count = 1;
//     wchar_t* cookiesPath = (wchar_t*)malloc(0x100);
//     wsprintf(cookiesPath, L"G:\\test\\exe_test\\publicdll\\%d.dat", count++);
//     wkeSetCookieJarFullPath(webWindow, cookiesPath);
//     free(cookiesPath);

    std::wstring titleString;
    titleString = L"Miniblink" + getVersionString();
    HWND hWnd = wkeGetHostHWND(webWindow);
    hWnd = ::GetParent(hWnd);
    ::SetWindowText(hWnd, titleString.c_str());
}

static int s_testCount = 1;
jsValue WKE_CALL_TYPE js_getTestCount(jsExecState es, void* param)
{
    return jsInt(s_testCount);
}

jsValue WKE_CALL_TYPE js_setTestCount(jsExecState es, void* param)
{
    s_testCount = jsToInt(es, jsArg(es, 0));

    return jsUndefined();
}

BOOL createWebWindow(Application* app)
{
//     wkeProxy proxy = { WKE_PROXY_HTTP , "127.0.0.1", 10809};
//     wkeSetProxy(&proxy);
    wkeSetMemoryCacheEnable(nullptr, true);
    wkeSetDragDropEnable(nullptr, true);
    wkeSetDebugConfig(nullptr, "backKeydownEnable", "1");

    //wkeSetHeadlessEnabled(nullptr, true);
    //wkeSetDebugConfig(nullptr, "drawDirtyDebugLine", "");
    //wkeSetDebugConfig(nullptr, "drawTileLine", "");
//     wkeSetDebugConfig(app->window, "alwaysIsNotSolideColor", "");
//     wkeSetDebugConfig(app->window, "alwaysInflateDirtyRect", "");
    wkeSetDebugConfig(nullptr, "antiAlias", "1");
    //wkeSetDebugConfig(app->window, "consoleOutput", "0");
    //wkeAddPluginDirectory(nullptr, L"E:\\test\\VideoLAN\\VLC");

    //wkeSetLocalStorageFullPath(NULL, L"C:\\ProgramData\\Temp\\");

//     wkeJsBindGetter("testCount", js_getTestCount, nullptr);
//     wkeJsBindSetter("testCount", js_setTestCount, nullptr);

    wkeWebView window;
    if (app->options.transparent)
        window = wkeCreateWebWindow(WKE_WINDOW_TYPE_TRANSPARENT, NULL, 0, 0, 1080, 680);
    else {
        RootWindow* rootWin = new RootWindow();
        window = rootWin->createRootWindow();
    }

    if (!window)
        return FALSE;

    initSettings(window);
    wkeOnWindowDestroy(window, handleWindowDestroy, app);
    
//     wkeJsBindFunction("jsNotifyIcon", jsNotifyIcon, (void*)app, 1);
//     wkeJsBindFunction("jsCheckIsProcess", jsCheckIsProcess, (void*)app, 1);
    
    //wkeSetFileSystem(fileOpenHook, fileCloseHook, fileSizeHook, fileReadHook, fileSeekHook);
    //wkeSetUserAgent(window, "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/57.0.2987.98 Safari/537.36");    
    //wkeSetUserAgent(window, "Mozilla/5.0 (MSIE 10.0; Windows NT 6.3; WOW64; Trident/7.0; MDDRJS; rv:11.0) like Gecko");
    //wkeSetUserAgent(window, "Mozilla/5.0 (iPhone; CPU iPhone OS 10_2_1 like Mac OS X; zh-CN) AppleWebKit/537.51.1 (KHTML, like Gecko) Mobile/14D27 UCBrowser/11.5.4.970 Mobile  AliApp(TUnionSDK/0.1.15)");
    //wkeSetUserAgent(window, "MQQBrowser/26 Mozilla/5.0 (linux; U; Android 2.3.7; zh-cn; MB200 Build/GRJ22; CyanogenMod-7) AppleWebKit/533.1 (KHTML, like Gecko) Version/4.0 Mobile Safari/533.1");
    //wkeSetUserAgent(window, "Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN; rv:1.9.1) Gecko/20090624 Firefox/3.5");
    //wkeMoveToCenter(window);

    wkeOnDownload(window, onDownloadCallback, nullptr);
    wkeNetOnResponse(window, onResponseCallback, nullptr);
    wkeOnDocumentReady2(window, onDocumentReady2, nullptr);
    wkeOnDidCreateScriptContext(window, onDidCreateScriptContext, nullptr);

    //wkeSetDebugConfig(window, "disableNavigatorPlugins", nullptr);

    const wchar_t* htmlW = L"<html><head></head><body style='font-size:16px;'>"
        L"输入网址: &nbsp<input id=myurl style='width:400px;' onkeydown=if(event.keyCode==13)GoURL(); value='http://www.4399.com/flash/112689_3.htm'><button onclick=GoURL();>GO</button><hr />"
        L"<a href='http://www.taobao.com/'>淘宝</a><br />"
        L"<a href='http://www.youku.com/'>优酷</a><br />"
        L"<a href='http://kugou.id.sn.cn/parse.php'>audio元素测试</a><br />"
        L"<a href='http://www.youzu.com/'>游族</a><br />"
        L"<a href='http://www.baidu.com/'>百度</a><br />"
        L"<a href='http://pan.baidu.com/'>百度网盘</a><br />"
        L"<a href='http://map.baidu.com/'>百度地图</a><br />"
        L"<a href='http://www.le.com/'>乐视</a><br />"
        L"<a href='http://download.csdn.net/'>CSDN</a><br />"
        L"<a href='http://www.yvoschaap.com/chainrxn/'>2D测试</a><br />"
        L"<a href='https://www.benjoffe.com/code/demos/canvascape/textures'>3D测试</a><br />"
        L"<a href='http://www.jz5u.com/soft/softdown.asp?softid=18109'>下载测试</a><br />"
        L"<a href='http://workerman.net:8383/'>蝌蚪聊天室</a><br />"
        L"<a href='http://chat.workerman.net/'>Websocket聊天室</a><br />"
        L"<a href='http://www.workerman.net/demos/browserquest/'>Websocket在线游戏</a><br />"
        L"<a href='http://www.163.com/'>网易</a><br />"
        //L"<span onclick=JsCall('')>JsCall</span>"
        L"</body><script>function GoURL(){document.location=document.getElementById('myurl').value;}</script></html>";
    std::string htmlA = utf16ToChar(htmlW, CP_UTF8);

//     if (app->url && 0 < wcslen(app->url))
//         wkeLoadURLW(window, app->url);
//     else
//         wkeLoadHtmlWithBaseUrl(window, htmlA.c_str(), "file:///E:/test/baidu/baike/main_files/");

    if (app->url && 0 < wcslen(app->url)) {
        if (NULL != wcsstr(app->url, L"use_res_url")) {
            const char* url = getUrl();
            wkeLoadURL(window, url);
        } else
            wkeLoadURLW(window, app->url);
    }
    else
        wkeLoadHtmlWithBaseUrl(window, htmlA.c_str(), "file:///E:/test/baidu/baike/main_files/");

//     htmlA = utf16ToUtf8(L"file:///G:/test/web_test/单病种/单病种质量管理系统.html");
//     wkeLoadURL(window, htmlA.c_str());

    //wkeLoadURL(window, "http://223.247.198.224:7010/MSunReportWeb/report/%E4%BD%8F%E9%99%A2%E6%94%B6%E8%B4%B9%E6%9F%A5%E8%AF%A2%E5%8F%91%E7%94%9F%E5%88%B6%EF%BC%88%E6%82%A3%E8%80%85%E7%A7%91%E5%AE%A4%EF%BC%891559721804506.htm?userSysId=");
    //wkeLoadURL(window, "file:///F:/test/exe_test/npruntime/Codeproject.html")

    return TRUE;
}

void printHelpAndQuit()
{
    PrintHelp();
    PostQuitMessage(0);
}

void runMessageLoop()
{
//     wkeRunMessageLoop();
//     return;

    MSG msg = { 0 };
#if 0
    static DWORD s_lastTime = 0;

    while (WM_QUIT != msg.message) {
        DWORD t1 = ::GetTickCount();

        if (!::PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
            ::Sleep(5);
            continue;
        }

        if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (WM_TIMER != msg.message) {
                DWORD t4 = ::GetTickCount();

//                 char* output = (char*)malloc(0x100);
//                 sprintf_s(output, 0x99, "runMessageLoop: %x %d\n", msg.message, t4 - s_lastTime);
//                 OutputDebugStringA(output);
//                 free(output);

                s_lastTime = t4;
            }
            
            ::TranslateMessage(&msg);
            ::DispatchMessageW(&msg);
        }
        DWORD t2 = ::GetTickCount();
        
        if (msg.message == WM_KEYDOWN && msg.wParam == 113) {
//             jsExecState es = wkeGlobalExec(g_testWebview);
//             jsCallGlobal(es, g_testOnNativeFunc, &g_testVal, 1);
//             jsReleaseRef(es, g_testOnNativeFunc);
//             jsReleaseRef(es, g_testVal);

//             const char* scriptText =
//                 "var dom = document.getElementById('myTextField'); dom.focus();";
//             wkeRunJS(g_testWebview, scriptText);
            wkeSetDebugConfig(g_testWebview, "inspectElementAt", nullptr);
        }

        wkeWake(nullptr);

        if (msg.message < WM_USER)
            ::Sleep(5);

        DWORD t3 = ::GetTickCount();

//         char* output = (char*)malloc(0x100);
//         sprintf_s(output, 0x99, "runMessageLoop: %d %d %d\n", t3 - t2, t2 - t1, t3 - s_lastTime);
//         OutputDebugStringA(output);
//         free(output);

        //s_lastTime = t3;
    }
#elif 1
    while (::GetMessageW(&msg, NULL, 0, 0)) {
        ::TranslateMessage(&msg);
        ::DispatchMessageW(&msg);

        wkeWake(nullptr);
    }
#else
    BOOL bRet = FALSE;
    LARGE_INTEGER lastFrequency = { 0 };

    while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0) {
        if (WM_QUIT == msg.message) {
            return;
        }

        while (true) {
            do {
                wkeWake(nullptr);

                if (!TranslateAccelerator(msg.hwnd, NULL, &msg)) {
                    ::TranslateMessage(&msg);
                    ::DispatchMessage(&msg);
                }

                if (!::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
                    msg.hwnd = NULL;
                if (WM_QUIT == msg.message) {
                    return;
                }
            } while (INVALID_HANDLE_VALUE != msg.hwnd && NULL != msg.hwnd);

            if (NULL == msg.hwnd) {
                break;
            }
        }
    }
#endif

}

void runApplication(Application* app)
{
    //memset(app, 0, sizeof(Application));

    if (!processOptions(app)) {
        printHelpAndQuit();
        return;
    }

    if (!fixupHtmlUrl(app)) {
        //PrintHelpAndQuit(app);
        //打开默认页面
        //wcsncpy_s(app->url, MAX_PATH, L"http://www.baidu.com", MAX_PATH);
    }

    if (!createWebWindow(app)) {
        printHelpAndQuit();
        return;
    }

    runMessageLoop();
}