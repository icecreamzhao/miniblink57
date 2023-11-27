
#include "webdriver/CommandHandlers/ElementUtil.h"

#include "webdriver/MBCommandExecutor.h"
#include "webdriver/WebDriverConstants.h"
#include "webdriver/js.h"
#include "webdriver/atoms.h"
#include "webdriver/StringUtilities.h"
#include "webdriver/jsoncpp/jsoncpp.h"
#include "webdriver/server/wd_logging.h"
#include "webdriver/server/errorcodes.h"
#include "webdriver/server/command_types.h"
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

bool checkNotifyUnexpectedAlert(const std::string& unexpectedAlertBehavior)
{
    bool isNotifyUnexpectedAlert = unexpectedAlertBehavior.size() == 0 || unexpectedAlertBehavior == IGNORE_UNEXPECTED_ALERTS
        || unexpectedAlertBehavior == DISMISS_AND_NOTIFY_UNEXPECTED_ALERTS || unexpectedAlertBehavior == ACCEPT_AND_NOTIFY_UNEXPECTED_ALERTS;
    //isNotifyUnexpectedAlert = isNotifyUnexpectedAlert && dialog.is_standard_alert();
    return isNotifyUnexpectedAlert;
}

bool handleUnexpectedAlert(mbWebView webview, const std::string& unexpectedAlertBehavior, bool forceUseDismiss, std::string* alertText)
{
    JsQueryInfo* jsQueryInfo = (JsQueryInfo*)mbGetUserKeyValue(webview, "JsQueryInfo");
    ::EnterCriticalSection(&jsQueryInfo->lock);
    *alertText = jsQueryInfo->alertText;

    if (unexpectedAlertBehavior == ACCEPT_UNEXPECTED_ALERTS || unexpectedAlertBehavior == ACCEPT_AND_NOTIFY_UNEXPECTED_ALERTS) {
        WDLOG(DEBUG) << "Automatically accepting the alert, " << unexpectedAlertBehavior;
        jsQueryInfo->alertWaitFlag = "accept";
        jsQueryInfo->alertText = "";
        jsQueryInfo->isAlertOpen = false;
    } else if (unexpectedAlertBehavior.size() == 0 || unexpectedAlertBehavior == DISMISS_UNEXPECTED_ALERTS
        || unexpectedAlertBehavior == DISMISS_AND_NOTIFY_UNEXPECTED_ALERTS || forceUseDismiss) {
        // If a quit command was issued, we should not ignore an unhandled
        // alert, even if the alert behavior is set to "ignore".
        WDLOG(DEBUG) << "Automatically dismissing the alert, " << unexpectedAlertBehavior;
        //         if (dialog.is_standard_alert() || dialog.is_security_alert()) {
        //             dialog.Dismiss();
        //         } else {
        //             // The dialog was non-standard. The most common case of this is
        //             // an onBeforeUnload dialog, which must be accepted to continue.
        //             dialog.Accept();
        //         }
        jsQueryInfo->alertWaitFlag = "dismiss";
        jsQueryInfo->alertText = "";
        jsQueryInfo->isAlertOpen = false;
    } else { // 如果是IGNORE_UNEXPECTED_ALERTS，则什么都不做，等python自己操作，或者用户手动关闭alert

    }    
    ::LeaveCriticalSection(&jsQueryInfo->lock);

    bool isNotifyUnexpectedAlert = checkNotifyUnexpectedAlert(unexpectedAlertBehavior);
    return isNotifyUnexpectedAlert;
}

static bool isCommandValidWithAlertPresent(const std::string& commandType)
{
    if (commandType == webdriver::CommandType::GetAlertText || commandType == webdriver::CommandType::SendKeysToAlert
        || commandType == webdriver::CommandType::AcceptAlert || commandType == webdriver::CommandType::DismissAlert
        || commandType == webdriver::CommandType::SetAlertCredentials || commandType == webdriver::CommandType::GetTimeouts
        || commandType == webdriver::CommandType::SetTimeouts || commandType == webdriver::CommandType::Screenshot
        || commandType == webdriver::CommandType::ElementScreenshot || commandType == webdriver::CommandType::GetCurrentWindowHandle
        || commandType == webdriver::CommandType::GetWindowHandles || commandType == webdriver::CommandType::SwitchToWindow) {
        return true;
    }
    return false;
}

// false表示没处理，继续往下执行别的cmd
bool handleAlert(mbWebView webview, const std::string& unexpectedAlertBehavior,
    const std::string& commandType, Response* response, /*std::string* serializedResponse,*/ bool* isOk)
{
    if (webview == NULL_WEBVIEW)
        return false;

    JsQueryInfo* jsQueryInfo = (JsQueryInfo*)mbGetUserKeyValue(webview, "JsQueryInfo");
    if (!jsQueryInfo->isAlertOpen)
        return false;

    if (isCommandValidWithAlertPresent(commandType))
        return false;

    //MessageBoxA(0, "MBCommandExecutor::handleAlert", 0, 0);
    // 只有部分命令需要拒绝alert，不然alert没法接收dismiss了

    bool isQuitCommand = commandType == webdriver::CommandType::Quit;
    std::string alertText;
    bool isNotifyUnexpectedAlert = handleUnexpectedAlert(webview, unexpectedAlertBehavior, isQuitCommand, &alertText);
    if (isQuitCommand)
        return false;

    if (isNotifyUnexpectedAlert) {
        // To keep pace with what the specification suggests, we'll
        // return the text of the alert in the error response.
        response->SetErrorResponse(EUNEXPECTEDALERTOPEN, "{Alert text : " + alertText + "}");
        response->AddAdditionalData("text", alertText);
        response->AddAdditionalData("data.text", alertText);
        //*serializedResponse = response->Serialize();
        *isOk = false;

        WDLOG(DEBUG) << "handleAlert: unexpected alert open. unexpectedAlertBehavior: " << unexpectedAlertBehavior;
    } else {
//         WDLOG(DEBUG) << "Command other than quit was issued, and option to not notify was specified. Continuing with "
//             << "command after automatically closing alert.";
        // Push a wait cycle, then re-execute the current command (which
        // hasn't actually been executed yet). Note that an empty string
        // for the deferred response parameter of CreateWaitThread will
        // re-queue the execution of the command.
        //this->CreateWaitThread("", true);
        //
        //response->SetSuccessResponse(Json::Value::null);
        //*isOk = true;
        OutputDebugStringA("handleAlert: SetSuccessResponse\n");
        return false;        
    }
    return true;
}

static void assertAlertOpen(JsQueryInfo* jsQueryInfo, const char* failText)
{
    if (jsQueryInfo->isAlertOpen) { // 之前进入cmd处理的时候就应该把alert都干掉了。另外下面的callFunctionWithTimeout有可能产生新的alert
        MessageBoxA(0, failText, 0, 0);
        OutputDebugStringA(failText);
    }
}

static bool waitUtilReady(mbWebView webview, Response* response)
{
    JsQueryInfo* jsQueryInfo = (JsQueryInfo*)mbGetUserKeyValue(webview, "JsQueryInfo");
    MBCommandExecutor* exec = (MBCommandExecutor*)mbGetUserKeyValue(webview, "MBCommandExecutor");
    int count = 0;
    while (count++ < 100) {
//         bool isOk = false;
//         if (handleAlert(webview, exec->getUnexpectedAlertBehavior(), CommandType::ExecuteAsyncScript, response, &isOk)) {
//             OutputDebugStringA("waitUtilReady: unexpected alert open\n");
//             return isOk;
//         }
        assertAlertOpen(jsQueryInfo, "waitUtilReady, isAlertOpen!");
        int state = mbQueryState(webview, "dispatchWillCommitProvisionalLoad");
        if (-1 == state) {
            OutputDebugStringA("waitUtilReady: webview is not valid\n");
            response->SetErrorResponse(ERROR_INVALID_SESSION_ID, "invalid session id");
            return false;
        } else if (1 == state) {
            return true;
        }
        ::Sleep(10);
    }

    OutputDebugStringA("waitUtilReady: webview is not Ready\n");
    response->SetErrorResponse(ERROR_NO_SUCH_ELEMENT, "no such element");
    return false;
}

bool hasFocus(mbWebView webview, Response* response, bool* hasfocus)
{
    Json::Value value;
    bool status = evaluateScriptWithTimeout(webview,
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

void MB_CALL_TYPE onRunJsCallback(mbWebView webview, void* param, mbJsExecState es, mbJsValue v)
{
    DebugBreak();
}

void MB_CALL_TYPE onJsQueryCallback(mbWebView webview, void* param, mbJsExecState es, int64_t queryId, int customMsg, const utf8* request)
{
    JsQueryInfo* jsQueryInfo = (JsQueryInfo*)mbGetUserKeyValue(webview, "JsQueryInfo");
    jsQueryInfo->msgType = customMsg;
    jsQueryInfo->result = request;
    jsQueryInfo->wait = 0;
}

static void fillAlertErrorResponse(const JsQueryInfo* jsQueryInfo, Response* response)
{
    ::EnterCriticalSection(&jsQueryInfo->lock);
    std::string alertText = "{Alert text : ";
    alertText += jsQueryInfo->alertText;
    alertText += "}";
    response->SetErrorResponse(ERROR_UNEXPECTED_ALERT_OPEN, alertText);
    ::LeaveCriticalSection(&jsQueryInfo->lock);
}

bool evaluateScriptWithTimeout(
    mbWebView webview,
    const std::string& function,
    const Json::Value& args, // must is list
    Response* response,
    Json::Value* result
    )
{
    JsQueryInfo* jsQueryInfo = (JsQueryInfo*)mbGetUserKeyValue(webview, "JsQueryInfo");
    MBCommandExecutor* exec = (MBCommandExecutor*)mbGetUserKeyValue(webview, "MBCommandExecutor");
    if (!waitUtilReady(webview, response))
        return false;
    mbRunJs(webview, mbWebFrameGetMainFrame(webview), function.c_str(), TRUE, nullptr, nullptr, nullptr);

    jsQueryInfo->wait = 1;
    while (1 == jsQueryInfo->wait) {
//         bool isOk = false;
//         if (handleAlert(webview, exec->getUnexpectedAlertBehavior(), CommandType::ExecuteAsyncScript, response, &isOk)) {
//             OutputDebugStringA("evaluateScriptWithTimeout: unexpected alert open\n");
//             return isOk;
//         }
        if (jsQueryInfo->isAlertOpen) {
            fillAlertErrorResponse(jsQueryInfo, response);
            return false;
        }
        Sleep(10);
    }
    if (jsQueryInfo->msgType < -1) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, jsQueryInfo->result);
        return false;
    }

    Json::CharReaderBuilder readerBuilder;
    readerBuilder["emitUTF8"] = true;
    std::unique_ptr<Json::CharReader> charRead(readerBuilder.newCharReader());
    std::string strerr;
    bool ok = charRead->parse(jsQueryInfo->result.c_str(), jsQueryInfo->result.c_str() + jsQueryInfo->result.size(), result, &strerr);
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

//     std::vector<char> kExecuteAsyncScriptScriptBuffer;
//     readFile(L"G:\\mycode\\miniblink57\\tmp\\kExecuteAsyncScriptScript.js", &kExecuteAsyncScriptScriptBuffer);
//     kExecuteAsyncScriptScriptBuffer.push_back('\0');

    JsQueryInfo* jsQueryInfo = (JsQueryInfo*)mbGetUserKeyValue(webview, "JsQueryInfo");
    // 之前进入cmd处理的时候就应该把alert都干掉了。另外下面的callFunctionWithTimeout有可能产生新的alert
    assertAlertOpen(jsQueryInfo, "callAsyncFunctionInternal, isAlertOpen!\n");
    bool status = callFunctionWithTimeout(webview, response, kExecuteAsyncScriptScript/*kExecuteAsyncScriptScriptBuffer.data()*/, asyncArgs, &tmp);
    if (!status)
        return status;

    ::Sleep(100);
    OutputDebugStringA("callAsyncFunctionInternal entry\n");

    const char kDocUnloadError[] = "document unloaded while waiting for result";
    std::vector<char> buf;
    buf.resize(1000);
    sprintf(buf.data(),
        "function() {\n"
        "  var info = document.$chrome_asyncScriptInfo;\n"
        "  if (!info) {\n"
        "    console.log('kQueryResult, callAsyncFunctionInternal -------------fail 1:' + info);\n"
        "    return {status: %d, value: '%s'};\n"
        "  }\n"
        "  var result = info.result;\n"
        "  if (!result) {\n"
        "    console.log('kQueryResult, callAsyncFunctionInternal -------------fail 2:' + result);\n"
        "    console.log('kQueryResult, callAsyncFunctionInternal -------------fail result:' + JSON.stringify(info));\n"
        "    return {status: 0};"
        "  }"
        "  delete info.result;"
        "  return result;"
        "}",
        kJavaScriptError,
        kDocUnloadError);
    std::string kQueryResult = buf.data();


    int retryCount = 0;
    while (true) {
        if (jsQueryInfo->isAlertOpen) {
            Json::Value value = Json::Value::null;
            *result = value;
            // 参考E:\chroium\M108\src\chrome\test\chromedriver\window_commands.cc ExecuteWindowCommand，这里返回ok了
            response->SetSuccessResponse(value);
            return true;
        }

        Json::Value no_args;
        Json::Value queryValue;
        status = callFunction(webview, response, kQueryResult, no_args, &queryValue);
        if (!status) {
//             if (status.code() == kNoSuchFrame)
//                 return Status(kJavaScriptError, kDocUnloadError);
// 
            // 在执行js的时候弹出alert，本次直接返回成功，也不用等执行结果了。但下次执行js的时候会根据options行为看是否要报错
            if (response->error() == ERROR_UNEXPECTED_ALERT_OPEN) {
                assertAlertOpen(jsQueryInfo, "callAsyncFunctionInternal, wait result alert fail!\n");
                Json::Value value = Json::Value::null;
                *result = value;
                // 参考E:\chroium\M108\src\chrome\test\chromedriver\window_commands.cc ExecuteWindowCommand，这里返回ok了
                response->SetSuccessResponse(value);
                return true;
            }
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

        if (queryValue.isMember("value")) {
            Json::Value value = queryValue.get("value", Json::Value::null);
            *result = value;
            return true;
        }

//         if (jsQueryInfo->isAlertOpen) {
//             // response->SetErrorResponse(ERROR_UNEXPECTED_ALERT_OPEN, ERROR_UNEXPECTED_ALERT_OPEN);
//             // return false;
// 
//             Json::Value value = Json::Value::null;
//             *result = value;
//             response->SetSuccessResponse(value);
//             return true;
//         }
        
        retryCount++;
        // Since async-scripts return immediately, need to time period here instead.
        if (retryCount > 10) {
            OutputDebugStringA("callAsyncFunctionInternal, time out\n");
            MessageBoxA(0, "ElementUtil.cpp: callAsyncFunctionInternal, time out", 0, 0);
            response->SetErrorResponse(ERROR_SCRIPT_TIMEOUT, "time out");
            return false;
        }
        ::Sleep(100);
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
    JsQueryInfo* jsQueryInfo = (JsQueryInfo*)mbGetUserKeyValue(webview, "JsQueryInfo");
    MBCommandExecutor* exec = (MBCommandExecutor*)mbGetUserKeyValue(webview, "MBCommandExecutor");
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
        "    console.log((\"catch:\" + e));\n"
        "    window.mbQuery(-1, e + \"\", null);\n"
        "  }\n"
        "})\n";
    expression += ".catch(function(e) { \nconsole.log(\"catch:\" + e);\nwindow.mbQuery(-1, e + \"\", null);});\n";

    if (!waitUtilReady(webview, response))
        return false;
    mbRunJs(webview, mbWebFrameGetMainFrame(webview), expression.c_str(), TRUE, nullptr, nullptr, nullptr);

    Json::Value value = Json::Value::null;
    jsQueryInfo->wait = 1;
    while (1 == jsQueryInfo->wait) {
//         bool isOk = false; // 参考E:\chroium\M108\src\chrome\test\chromedriver\window_commands.cc ExecuteWindowCommand，这里返回ok了
//         if (handleAlert(webview, exec->getUnexpectedAlertBehavior(), CommandType::ExecuteAsyncScript, response, &isOk)) {
//             *result = value;
//             OutputDebugStringA("callFunctionWithTimeout: unexpected alert open\n");
//             return isOk;
//         }
        if (jsQueryInfo->isAlertOpen) {
            fillAlertErrorResponse(jsQueryInfo, response);
            return false;
        }
        Sleep(10);
    }
    if (jsQueryInfo->msgType < -1) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, jsQueryInfo->result);
        return false;
    }

    Json::CharReaderBuilder readerBuilder;
    readerBuilder["emitUTF8"] = true; //utf8支持,不加这句,utf8的中文字符会编程\uxxx
    std::unique_ptr<Json::CharReader> charRead(readerBuilder.newCharReader());
    Json::Value root;
    std::string strerr;
    std::string jsResultStr = jsQueryInfo->result;
    bool status = charRead->parse(jsResultStr.c_str(), jsResultStr.c_str() + jsResultStr.size(), &root, &strerr);
    if (!status) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "callFunction json parse fail");
        return false;
    }

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
    bool isShadowRoot,
    Json::Value* result,
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

    return callFunctionWithTimeout(webview, response, script, arguments, result);
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