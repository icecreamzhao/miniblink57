
#ifndef webdriver_CommandHandlers_ElementUtil_h
#define webdriver_CommandHandlers_ElementUtil_h

#include "mbvip/core/mb.h"
#include "webdriver/server/response.h"
#include <string>

namespace webdriver {

struct JsQueryInfo {
    int wait = 0;
    int msgType = -1;
    std::string result;

    std::string alertText; // �����������ˣ���Ϊ���ü������鷳
    std::string alertWaitFlag;
    bool isAlertOpen = false; // ��עalert�����򿪹�
    mutable CRITICAL_SECTION lock;

    JsQueryInfo() 
    {
        ::InitializeCriticalSection(&lock);
    }
};
bool handleAlert(mbWebView webview, const std::string& unexpectedAlertBehavior,
    const std::string& commandType, Response* response, /*std::string* serializedResponse,*/ bool* isOk);

bool checkElement(const std::string& element_id, Response* response);

Json::Value createElement(const std::string& element_id);
Json::Value createShadowRoot(const std::string& shadow_root_id);
std::string getElementKey();

bool isElementFocused(mbWebView webview, Response* response, const std::string& element_id, bool* is_focused);

bool evaluateScriptWithTimeout(
    mbWebView webview,
    const std::string& function,
    const Json::Value& args, // must is list
    Response* response,
    Json::Value* result
    );

bool callUserAsyncFunction(
    mbWebView webview,
    Response* response,
    const std::string& function,
    const Json::Value& args,
    Json::Value* result);

bool callAtomsJs(mbWebView webview, Response* response, const char* const* atomFunction, const Json::Value& args, Json::Value* result);

bool callUserSyncScript(mbWebView webview, Response* response, const std::string& script, const Json::Value& args, Json::Value* result);

bool callFunctionWithTimeout(
    mbWebView webview,
    Response* response,
    const std::string& function,
    const Json::Value& args, // must is list
    Json::Value* result
    );

bool getElementAttribute(
    mbWebView webview,
    const std::string& element_id,
    const std::string& attribute_name,
    Response* response,
    Json::Value* value);

bool findElementCommon(int intervalMs,
    bool only_one,
    const std::string* rootElementId,
    mbWebView webview,
    const std::string& strategy,
    const std::string& target,
    bool isShadowRoot,
    Json::Value* result,
    Response* response);

bool isElementAttributeEqualToIgnoreCase(
    mbWebView webview,
    Response* response,
    const std::string& element_id,
    const std::string& attribute_name,
    const std::string& attribute_value,
    bool* is_equal);

}

#endif // webdriver_CommandHandlers_ElementUtil_h