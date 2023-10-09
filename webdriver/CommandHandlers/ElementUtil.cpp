
#include "webdriver/CommandHandlers/ElementUtil.h"

#include "webdriver/jsoncpp/jsoncpp.h"
#include "webdriver/server/errorcodes.h"
#include "webdriver/js.h"
#include "webdriver/atoms.h"
#include "webdriver/StringUtilities.h"
#include <windows.h>
#include <vector>
#include <string>
#include <memory>

namespace webdriver {

#if defined(_MSC_VER)
void readFile(const wchar_t* path, std::vector<char>* buffer)
{
    HANDLE hFile = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile) {
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
#endif

std::string findStringFromJson(const Json::Value& params, const std::string& key)
{
    if (params.isMember(key))
        return "";
    Json::Value val = params.get(key.c_str(), Json::Value::null);
    if (!val.isString())
        return "";
    return val.asString();
}

const char kElementKey[] = "ELEMENT";
const char kElementKeyW3C[] = "element-6066-11e4-a52e-4f735466cecf";
const char kShadowRootKey[] = "shadow-6066-11e4-a52e-4f735466cecf";

std::string getElementKey()
{
    //     Session* session = GetThreadLocalSession();
    //     if (session && session->w3c_compliant)
    //         return kElementKeyW3C;
    //     else
    //         return kElementKey;
    return kElementKeyW3C;
}

Json::Value createElementCommon(const std::string& key, const std::string& value)
{
    Json::Value element;
    element[key.c_str()] = value;
    return element;
}

Json::Value createElement(const std::string& element_id)
{
    return createElementCommon(getElementKey(), element_id);
}

Json::Value createShadowRoot(const std::string& shadow_root_id)
{
    return createElementCommon(kShadowRootKey, shadow_root_id);
}

bool parseCallFunctionResult(const Json::Value& tempResult, Json::Value* result, Response* response)
{
    if (!tempResult.isObject()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "call function result must be a dictionary");
        return false;
    }
    Json::Value statusCode = tempResult.get("status", Json::Value::null);

    if (statusCode == Json::Value::null || !statusCode.isInt()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "call function result missing int 'status'");
        return false;
    }

    if (statusCode.asInt() != 0) {
        Json::Value message = tempResult.get("value", Json::Value("call function fail"));
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, message.asString());
        return false;
    }

    Json::Value unscopedValue = tempResult.get("value", Json::Value::null);
    if (unscopedValue == Json::Value::null) {
        // Missing 'value' indicates the JavaScript code didn't return a value.
        return true;
    }
    result->copy(unscopedValue);
    return true;
}

bool hasFocus(mbWebView web_view, Response* response, bool* hasfocus)
{
    Json::Value value;
    bool status = evaluateScriptWithTimeout(web_view, 
        //"let ret = document.hasFocus(); window.mbQuery(0, \"{\\\"status\\\": 0, \\\"value\\\": \" + ret + \"}\", null)",
        "let ret = document.hasFocus(); window.mbQuery(0, \"\" + ret + \"\", null)",
        Json::Value::null, response, &value);
    if (!status)
        return false;
    if (!value.isBool()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "document.hasFocus() returns non-boolean");
        return false;
    }

    *hasfocus = value.asBool();
    return true;
}

bool getActiveElement(mbWebView webview, Response* response, Json::Value* value)
{
    Json::Value args;
    bool status = callFunctionWithTimeout(webview, response,
        "function() { return document.activeElement || document.body }", args, value);
    if (!status)
        return false;
    
    if (value->empty()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "getActiveElement return empty");
        return false;
    }
    return true;
}

bool isElementFocused(
    mbWebView webview,
    Response* response,
    const std::string& element_id,
    bool* is_focused)
{
    Json::Value result;
    bool status = hasFocus(webview, response, is_focused);
    if (!status)
        return false;
    if (!(*is_focused))
        return false;
    status = getActiveElement(webview, response, &result);
    if (!status)
        return false;

    Json::Value element_dict = createElement(element_id);
    *is_focused = result == element_dict;
    return true;
}

void MB_CALL_TYPE onRunJsCallback(mbWebView webView, void* param, mbJsExecState es, mbJsValue v)
{
    DebugBreak();
}

struct JsQueryInfo {
    int wait = 0;
    int msgType = -1;
    std::string result;
};
JsQueryInfo s_JsQueryInfo;

void MB_CALL_TYPE onJsQueryCallback(mbWebView webView, void* param, mbJsExecState es, int64_t queryId, int customMsg, const utf8* request)
{
    s_JsQueryInfo.msgType = customMsg;
    s_JsQueryInfo.result = request;
    s_JsQueryInfo.wait = 0;
}

bool evaluateScriptWithTimeout(
    mbWebView webview,
    const std::string& function,
    const Json::Value& args, // must is list
    Response* response,
    Json::Value* result
    )
{
    mbRunJs(webview, mbWebFrameGetMainFrame(webview), function.c_str(), TRUE, nullptr, nullptr, nullptr);

    s_JsQueryInfo.wait = 1;
    while (1 == s_JsQueryInfo.wait) {
        Sleep(10);
    }
    if (s_JsQueryInfo.msgType < -1) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, s_JsQueryInfo.result);
        return false;
    }

    Json::CharReaderBuilder readerBuilder;
    readerBuilder["emitUTF8"] = true;
    std::unique_ptr<Json::CharReader> charRead(readerBuilder.newCharReader());
    std::string strerr;
    bool ok = charRead->parse(s_JsQueryInfo.result.c_str(), s_JsQueryInfo.result.c_str() + s_JsQueryInfo.result.size(), result, &strerr);
    if (!ok) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "callFunction json parse fail");
        return false;
    }

    return true;
}

bool callUserSyncScript(mbWebView webview, Response* response, const std::string& script, const Json::Value& args, Json::Value* result)
{
    Json::Value syncArgs;
    syncArgs.append(script);
    // Clone needed since Append only accepts Value as an rvalue.
    syncArgs.append(args);

    return callFunctionWithTimeout(webview, response, kExecuteScriptScript, syncArgs, result);
}

// WebDriver standard status codes.
enum StatusCode {
    kOk = 0,
    kInvalidSessionId = 6,
    kNoSuchElement = 7,
    kNoSuchFrame = 8,
    kUnknownCommand = 9,
    kStaleElementReference = 10,
    kElementNotVisible = 11,
    kInvalidElementState = 12,
    kUnknownError = 13,
    kJavaScriptError = 17,
    kXPathLookupError = 19,
    kTimeout = 21,
    kNoSuchWindow = 23,
    kInvalidCookieDomain = 24,
    kUnableToSetCookie = 25,
    kUnexpectedAlertOpen = 26,
    kNoSuchAlert = 27,
    kScriptTimeout = 28,
    kInvalidSelector = 32,
    kSessionNotCreated = 33,
    kMoveTargetOutOfBounds = 34,
    kElementNotInteractable = 60,
    kInvalidArgument = 61,
    kNoSuchCookie = 62,
    kElementClickIntercepted = 64,
    kNoSuchShadowRoot = 65,
    kDetachedShadowRoot = 66,
    kUnsupportedOperation = 405,
    // Chrome-specific status codes.
    kChromeNotReachable = 100,
    kNoSuchExecutionContext,
    kDisconnected,
    kForbidden = 103,
    kTabCrashed,
    kTargetDetached,
    kUnexpectedAlertOpen_Keep,
};

bool callFunction(mbWebView webview,
    Response* response,
    const std::string& function,
    const Json::Value& args,
    Json::Value* result)
{
    // Timeout set to Max is treated as no timeout.
    return callFunctionWithTimeout(webview, response, function, args, result);
}

bool callAsyncFunctionInternal(
    mbWebView webview,
    Response* response,
    const std::string& function,
    const Json::Value& args,
    bool is_user_supplied,
    Json::Value* result)
{
    Json::Value asyncArgs;
    asyncArgs.append("return (" + function + ").apply(null, arguments);");
    asyncArgs.append(args);
    asyncArgs.append(is_user_supplied);
    Json::Value tmp;

    bool status = callFunctionWithTimeout(webview, response, kExecuteAsyncScriptScript, asyncArgs, &tmp);
    if (!status)
        return status;

    const char kDocUnloadError[] = "document unloaded while waiting for result";
    std::vector<char> buf;
    buf.resize(1000);
    sprintf(buf.data(),
        "function() {"
        "  var info = document.$chrome_asyncScriptInfo;"
        "  if (!info)"
        "    return {status: %d, value: '%s'};"
        "  var result = info.result;"
        "  if (!result)"
        "    return {status: 0};"
        "  delete info.result;"
        "  return result;"
        "}",
        kJavaScriptError,
        kDocUnloadError);
    std::string kQueryResult = buf.data();

    int retryCount = 0;
    while (true) {
        Json::Value no_args;
        Json::Value queryValue;
        status = callFunction(webview, response, kQueryResult, no_args, &queryValue);
        if (!status) {
//             if (status.code() == kNoSuchFrame)
//                 return Status(kJavaScriptError, kDocUnloadError);
            return status;
        }

        if (!queryValue.isObject()) {
            response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "async result info is not a dictionary");
            return false;
        }

        if (!queryValue.isMember("status")) {
            response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "async result info has no int 'status'");
            return false;
        }
        Json::Value statusCodeVal = queryValue.get("status", Json::Value::null);
        if (!statusCodeVal.isIntegral()) {
            response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "async result info has no int 'status'");
            return false;
        }
        int statusCode = statusCodeVal.asInt();

        if (statusCode != kOk) {
            Json::Value message = queryValue.get("value", Json::Value::null);
            std::string msg = "async function fail";
            if (message.isString())
                msg = message.asString();
            response->SetErrorResponse(ERROR_INVALID_ARGUMENT, msg);
            return false;
        }

        Json::Value value = queryValue.get("value", Json::Value::null);
        if (!value.empty()) {
            *result = value;
            return true;
        }

        retryCount++;
        // Since async-scripts return immediately, need to time period here instead.
        if (retryCount > 5) {
            MessageBoxA(0, "callAsyncFunctionInternal", 0, 0);
            response->SetErrorResponse(ERROR_SCRIPT_TIMEOUT, "time out");
            return false;
        }
        ::Sleep(1000);
    }
}

bool callUserAsyncFunction(
    mbWebView webview,
    Response* response,
    const std::string& function,
    const Json::Value& args,
    Json::Value* result)
{
    return callAsyncFunctionInternal(webview, response, function, args, true, result);
}

bool callFunctionWithTimeout(
    mbWebView webview,
    Response* response,
    const std::string& function,
    const Json::Value& args, // must is list
    Json::Value* result
    )
{
    Json::StreamWriterBuilder writer;
    std::string json(Json::writeString(writer, args));

    std::string w3c = true/*w3c_compliant_*/ ? "true" : "false";

    // TODO(zachconrad): Second null should be array of shadow host ids.
    //readFile(L"G:\\mycode\\miniblink57\\webdriver\\CommandHandlers\\findElements.js", &FIND_ELEMENTS);

    std::string expression("let ret = (");
    expression += kCallFunctionScript;
    expression += ").apply(null, [";
    expression += function;
    expression += ", ";
    expression += json;
    expression += ", ";
    expression += w3c;
    expression += "]);\n";
    expression += 
        "ret.then(function(r){\n"
        "  try {\n"
        "    let json = JSON.stringify(r);\n"
        "    window.mbQuery(0, json, null);\n"
        "  } catch (e) {\n"
        "    console.log((\"catch\" + e));"
        "    window.mbQuery(-1, e + \"\", null);\n"
        "  }\n"
        "})\n";
    expression += ".catch(function(e) { \nconsole.log(\"catch\" + e);\nwindow.mbQuery(-1, e + \"\", null);});\n";

    mbRunJs(webview, mbWebFrameGetMainFrame(webview), expression.c_str(), TRUE, nullptr, nullptr, nullptr);

    s_JsQueryInfo.wait = 1;
    while (1 == s_JsQueryInfo.wait) {
        Sleep(10);
    }
    if (s_JsQueryInfo.msgType < -1) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, s_JsQueryInfo.result);
        return false;
    }

    Json::CharReaderBuilder readerBuilder;
    readerBuilder["emitUTF8"] = true; //utf8支持,不加这句,utf8的中文字符会编程\uxxx
    std::unique_ptr<Json::CharReader> charRead(readerBuilder.newCharReader());
    Json::Value root;
    std::string strerr;
    std::string jsResultStr = s_JsQueryInfo.result;
    bool status = charRead->parse(jsResultStr.c_str(), jsResultStr.c_str() + jsResultStr.size(), &root, &strerr);
    if (!status) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "callFunction json parse fail");
        return false;
    }

    Json::Value value;
    status = parseCallFunctionResult(root, &value, response);
    if (!status)
        return false;
    response->SetResponse("", value);

    if (result)
        result->copy(value);
    return true;
}

bool findElementCommon(int intervalMs,
    bool only_one,
    const std::string* rootElementId,
    mbWebView webview,
    const std::string& strategy,
    const std::string& target,
    //std::unique_ptr<base::Value>* value,
    bool isShadowRoot,
    Response* response)
{
    /*
     * Currently there is an opened discussion about if the
     * following values has to be supported for a Shadow Root
     * because the current implementation doesn't support them.
     * We have them disabled for now.
     * https://github.com/w3c/webdriver/issues/1610
     */
    if (isShadowRoot && (strategy == "tag name" || strategy == "xpath")) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "invalid locator");
        return false;
    }

    std::vector<char> kFIND_ELEMENTS;

    std::string script;
//     if (only_one) {
//         readFile(L"G:\\mycode\\miniblink57\\webdriver\\CommandHandlers\\findElements.js", &FIND_ELEMENTS);
//         FIND_ELEMENT.push_back('\0');
//         script = FIND_ELEMENT.data();
//     } else {
//         readFile(L"G:\\mycode\\miniblink57\\webdriver\\CommandHandlers\\findElements.js", &FIND_ELEMENTS);
//         FIND_ELEMENTS.push_back('\0');
//         script = FIND_ELEMENTS.data();
//     }

    if (only_one)
        script = webdriver::atoms::asString(webdriver::atoms::FIND_ELEMENT);
    else
        script = webdriver::atoms::asString(webdriver::atoms::FIND_ELEMENTS);

    Json::Value locator;
    locator[strategy] = target;
    Json::Value arguments;
    arguments.append(std::move(locator));
    if (rootElementId) {
        if (isShadowRoot)
            arguments.append(createShadowRoot(*rootElementId));
        else
            arguments.append(createElement(*rootElementId));
    }

    return callFunctionWithTimeout(webview, response, script, arguments, nullptr);
}

// example of element_id - d9cf1666-0066-4c07-bb86-03edcbab6680
// should contain only 0-9 or a-f
// format xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
bool checkElement(const std::string& element_id, Response* response) 
{
    //Session* session = GetThreadLocalSession();
    if (/*session && session->w3c_compliant*/true) {
        if (element_id.length() != 36) {
            response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Element_id length is invalid");
            return false;
        }

        for (std::string::size_type i = 0; i < element_id.length(); ++i) {
            if (i == 8 || i == 13 || i == 18 || i == 23) {
                if (element_id[i] != '-') {
                    response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Element_id format is invalid");
                    return false;
                }
            } else {
                if (!(element_id[i] >= '0' && element_id[i] <= '9') &&
                    !(element_id[i] >= 'a' && element_id[i] <= 'f')) {
                    response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Element_id contains invalid letter on position");
                    return false;
                }
            }
        }
    }
    return true;
}

bool callAtomsJs(mbWebView webview, Response* response, const char* const* atomFunction, const Json::Value& args, Json::Value* result)
{
    return callFunctionWithTimeout(webview, response, webdriver::atoms::asString(atomFunction), args, result);
}

bool callAtomsStrJs(mbWebView webview, Response* response, const char* atomFunction, const Json::Value& args, Json::Value* result)
{
    return callFunctionWithTimeout(webview, response, atomFunction, args, result);
}

bool getElementAttribute(
    mbWebView webview,
    const std::string& element_id,
    const std::string& attribute_name,
    Response* response,
    Json::Value* value)
{
    bool status = checkElement(element_id, response);
    if (!status)
        return false;
    Json::Value args;
    args.append(createElement(element_id));
    args.append(attribute_name);

    return callAtomsJs(webview, response, webdriver::atoms::GET_ATTRIBUTE, args, value);

//     std::vector<char> buffer;
//     readFile(L"G:\\mycode\\miniblink57\\webdriver\\GET_ATTRIBUTE.js", &buffer);
//     buffer.push_back('\0');
//     return callAtomsStrJs(webview, response, buffer.data(), args, value);
}

bool isElementAttributeEqualToIgnoreCase(
    //Session* session,
    mbWebView webview,
    Response* response,
    const std::string& element_id,
    const std::string& attribute_name,
    const std::string& attribute_value,
    bool* is_equal)
{
    Json::Value result;
    bool status = getElementAttribute(webview, element_id, attribute_name, response, &result);
    if (!status)
        return false;

    if (result.isString()) {
        *is_equal = StringUtilities::compareStringsIgnoreCase(result.asString(), attribute_value);
    } else {
        *is_equal = false;
    }
    return status;
}

}