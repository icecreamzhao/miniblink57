// Licensed to the Software Freedom Conservancy (SFC) under one
// or more contributor license agreements. See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership. The SFC licenses this file
// to you under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "webdriver/CommandHandlers/SendKeysCommandHandler.h"
#include <ctime>
// #include <iomanip>
#include "webdriver/server/errorcodes.h"
#include "webdriver/server/keycodes.h"
#include "webdriver/server/wd_logging.h"
#include "webdriver/BrowserFactory.h"
#include "webdriver/MBCommandExecutor.h"
#include "webdriver/CommandHandlers/ElementUtil.h"
#include "webdriver/js.h"
#include "webdriver/atoms.h"
#include <set>

// #include "../InputManager.h"
#include "webdriver/StringUtilities.h"
// #include "../VariantUtilities.h"
// #include "../WindowUtilities.h"

#define MAXIMUM_DIALOG_FIND_RETRIES 50
#define MAXIMUM_CONTROL_FIND_RETRIES 10

namespace webdriver {


const int kFlickTouchEventsPerSecond = 30;
const std::set<std::string> textControlTypes = { "text", "search", "tel", "url", "password" };
const std::set<std::string> inputControlTypes = {
    "text",           "search", "url",   "tel",   "email",
    "password",       "date",   "month", "week",  "time",
    "datetime-local", "number", "range", "color", "file" };

const std::set<std::string> nontypeableControlTypes = { "color" };

const std::unordered_set<std::string> booleanAttributes = {
    "allowfullscreen",
    "allowpaymentrequest",
    "allowusermedia",
    "async",
    "autofocus",
    "autoplay",
    "checked",
    "compact",
    "complete",
    "controls",
    "declare",
    "default",
    "defaultchecked",
    "defaultselected",
    "defer",
    "disabled",
    "ended",
    "formnovalidate",
    "hidden",
    "indeterminate",
    "iscontenteditable",
    "ismap",
    "itemscope",
    "loop",
    "multiple",
    "muted",
    "nohref",
    "nomodule",
    "noresize",
    "noshade",
    "novalidate",
    "nowrap",
    "open",
    "paused",
    "playsinline",
    "pubdate",
    "readonly",
    "required",
    "reversed",
    "scoped",
    "seamless",
    "seeking",
    "selected",
    "truespeed",
    "typemustmatch",
    "willvalidate" };

SendKeysCommandHandler::SendKeysCommandHandler(void)
{
}

SendKeysCommandHandler::~SendKeysCommandHandler(void)
{
}

bool sendKeysOnWindow(mbWebView web_view, const Json::Value* key_list, bool release_modifiers, int* sticky_modifiers) 
{
//     std::u16string keys;
//     Status status = FlattenStringArray(key_list, &keys);
//     if (status.IsError())
//         return status;
//     std::vector<KeyEvent> events;
//     int sticky_modifiers_tmp = *sticky_modifiers;
//     status = ConvertKeysToKeyEvents(
//         keys, release_modifiers, &sticky_modifiers_tmp, &events);
//     if (status.IsError())
//         return status;
//     status = web_view->DispatchKeyEvents(events, false);
//     if (status.IsOk())
//         *sticky_modifiers = sticky_modifiers_tmp;
//     return status;
    return true;
}

bool isElementDisplayed(mbWebView webview, Response* response, const std::string& element_id, bool ignore_opacity, bool* is_displayed)
{
    bool status = checkElement(element_id, response);
    if (!status)
        return false;

    Json::Value args;
    args.append(createElement(element_id));
    args.append(ignore_opacity);
    Json::Value result;
    status = callAtomsJs(webview, response, webdriver::atoms::IS_DISPLAYED, args, &result);
    if (!status)
        return false;
    if (!result.isBool()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "IS_DISPLAYED should return a boolean value");
        return false;
    }
    *is_displayed = result.asBool();
    return true;
}

bool isElementEnabled(mbWebView webview, Response* response, const std::string& element_id, bool* is_enabled)
{
    bool status = checkElement(element_id, response);
    if (!status)
        return false;

    Json::Value args;
    args.append(createElement(element_id));
    Json::Value result;
    status = callAtomsJs(webview, response, webdriver::atoms::IS_ENABLED, args, &result);
    if (!status)
        return status;

    if (!result.isBool())
    {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "IS_ENABLED should return a boolean value");
        return false;
    }
    *is_enabled = result.asBool();
    return true;
}

bool focusToElement(mbWebView webview, Response* response, const std::string& element_id)
{
    bool status = checkElement(element_id, response);
    if (!status)
        return status;
    bool is_displayed = false;
    bool is_focused = false;
    int count = 0;
    while (true) {
        status = isElementDisplayed(webview, response, element_id, true, &is_displayed);
        if (!status)
            return status;
        if (is_displayed)
            break;
        status = isElementFocused(webview, response, element_id, &is_focused);
        if (!status)
            return status;
        if (is_focused)
            break;
        if (count > 4) {
            response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Element Not Visible");
            return false;
        }
        count++;
        Sleep(1000);
    }

    bool is_enabled = false;
    status = isElementEnabled(webview, response, element_id, &is_enabled);
    if (!status)
        return false;
    if (!is_enabled) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Invalid Element State");
        return false;
    }

    if (!is_focused) {
        Json::Value args;
        args.append(createElement(element_id));
        Json::Value result;
        status = callFunctionWithTimeout(webview, response, kFocusScript, args, &result);
        if (!status)
            return false;
    }
    return true;
}

bool sendKeysToElement(mbWebView webview, Response* response, const std::string& element_id, const bool is_text, const Json::Value* key_list)
{
    // If we were previously focused, we don't need to focus again.
    // But also, later we don't move the carat if we were already in focus.
    // However, non-text elements such as contenteditable elements needs to be
    // focused to ensure the keys will end up being sent to the correct place.
    // So in the case of non-text elements, we still focusToElement.
    bool wasPreviouslyFocused = false;
    isElementFocused(webview, response, element_id, &wasPreviouslyFocused);
    if (!wasPreviouslyFocused || !is_text) {
        bool status = focusToElement(webview, response, element_id);
        if (!status)
            return false;
    }

    // Move cursor/caret to append the input if we only just focused this
    // element. keys if element's type is text-related
    if (is_text && !wasPreviouslyFocused) {
        Json::Value args;
        args.append(createElement(element_id));
        Json::Value result;
        bool status = callFunctionWithTimeout(webview, response,
            "elem => elem.setSelectionRange(elem.value.length, elem.value.length)",
            args, &result);
        if (!status)
            return false;
    }

    int sticky_modifiers = 0;
    return sendKeysOnWindow(webview, key_list, true, &sticky_modifiers);
}

void SendKeysCommandHandler::ExecuteInternal(const MBCommandExecutor& executor, const ParametersMap& params, Response* response)
{
    ParametersMap::const_iterator idIt = params.find("id");
    std::string element_id = idIt->second.asString();

    bool status = checkElement(element_id, response);
    if (!status)
        return ;
    Json::Value key_list;
    Json::Value key_list_local;
    Json::Value text;
    std::string textStr;
    if (true/*session->w3c_compliant*/) {
        ParametersMap::const_iterator textIt = params.find("text");
        if (textIt == params.end()) {
            response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "'text' must be a string");
            return;
        }
        text = textIt->second;
        if (!text.isString()) {
            response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "'text' must be a string");
            return;
        }
        textStr = text.asString();
        if (textStr.empty()) {
            response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "'text' must be a string");
            return;
        }

        key_list_local.append(text);
        key_list = key_list_local;
    } else {
        ParametersMap::const_iterator keyListIt = params.find("value");
        if (keyListIt == params.end()) {
            response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "'value' must be a list");
            return;
        }
        key_list = keyListIt->second;
        if (!key_list.isArray()) {
            response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "'value' must be a list");
            return;
        }
    }

    bool is_input = false;
    status = isElementAttributeEqualToIgnoreCase(executor.view(), response, element_id, "tagName", "input", &is_input);
    if (!status)
        return;

    Json::Value get_element_type;
    status = getElementAttribute(executor.view(), element_id, "type", response, &get_element_type);
    if (!status)
        return;

    std::string element_type;
    if (get_element_type.isString())
        element_type = StringUtilities::toLowerASCII(get_element_type.asString());
    bool is_file = element_type == "file";
    bool is_nontypeable = nontypeableControlTypes.find(element_type) != nontypeableControlTypes.end();

    if (is_input && is_file) {
//         if (session->strict_file_interactability) {
//             status = FocusToElement(session, web_view, element_id);
//             if (status.IsError())
//                 return status;
//         }
//         // Compress array into a single string.
//         std::string paths_string;
//         for (const base::Value& i : *key_list) {
//             const std::string* path_part = i.GetIfString();
//             if (!path_part)
//                 return Status(kInvalidArgument, "'value' is invalid");
//             paths_string.append(*path_part);
//         }
// 
//         // w3c spec specifies empty path_part should throw invalidArgument error
//         if (paths_string.empty())
//             return Status(kInvalidArgument, "'text' is empty");
// 
//         ChromeDesktopImpl* chrome_desktop = nullptr;
//         bool is_desktop = session->chrome->GetAsDesktop(&chrome_desktop).IsOk();
// 
//         // Separate the string into separate paths, delimited by '\n'.
//         std::vector<base::FilePath> paths;
//         for (const auto& path_piece : base::SplitStringPiece(paths_string, "\n", base::TRIM_WHITESPACE, base::SPLIT_WANT_ALL)) {
//             // For local desktop browser, verify that the file exists.
//             // No easy way to do that for remote or mobile browser.
//             if (is_desktop &&
//                 !base::PathExists(base::FilePath::FromUTF8Unsafe(path_piece))) {
//                 return Status(
//                     kInvalidArgument,
//                     base::StringPrintf(
//                         "File not found : %" PRFilePath,
//                         base::FilePath::FromUTF8Unsafe(path_piece).value().c_str()));
//             }
//             paths.push_back(base::FilePath::FromUTF8Unsafe(path_piece));
//         }
// 
//         bool multiple = false;
//         status = IsElementAttributeEqualToIgnoreCase(
//             session, web_view, element_id, "multiple", "true", &multiple);
//         if (status.IsError())
//             return status;
//         if (!multiple && paths.size() > 1)
//             return Status(kInvalidArgument,
//                 "the element can not hold multiple files");
// 
//         base::Value element = CreateElement(element_id);
//         return web_view->SetFileInputFiles(session->GetCurrentFrameId(), element, paths, multiple);
        Json::Value nullValue;
        nullValue["value"] = Json::Value::null;
        response->SetResponse("", nullValue);
    } else if (/*session->w3c_compliant &&*/ is_input && is_nontypeable) {
        // Special handling for non-typeable inputs is only included in W3C Spec
        // The Spec calls for returning element not interactable if the element
        // has no value property, but this is included for all input elements, so
        // no check is needed here.

        // text is set only when session.w3c_compliant, so confirm here
        Json::Value args;
        args.append(createElement(element_id));
        args.append(textStr);

        // Set value to text as given by user; if this does not match the defined
        // format for the input type, results are not defined
        status = callFunctionWithTimeout(
            executor.view(), response,
            "(element, text) => element.value = text",
            args, nullptr);
        return;
    } else {
        Json::Value get_content_editable;
        Json::Value args;
        args.append(createElement(element_id));
        status = callFunctionWithTimeout(executor.view(), response,
            "element => element.isContentEditable", args, &get_content_editable);
        if (!status)
            return;

        // If element_type is in textControlTypes, sendKeys should append
        bool is_textControlType = is_input && textControlTypes.find(element_type) != textControlTypes.end();
        // If the element is a textarea, sendKeys should also append
        bool is_textarea = false;
        status = isElementAttributeEqualToIgnoreCase(executor.view(), response, element_id, "tagName", "textarea", &is_textarea);
        if (!status)
            return;
        bool is_text = is_textControlType || is_textarea;

        if (get_content_editable.isBool() && get_content_editable.asBool()) {
            // If element is contentEditable
            // check if element is focused
            bool is_focused = false;
            status = isElementFocused(executor.view(), response, element_id, &is_focused);
            if (!status)
                return;

            // Get top level contentEditable element
            Json::Value result;
            status = callFunctionWithTimeout(
                executor.view(), response,
                "function(element) {"
                "  while (element.parentElement && element.parentElement.isContentEditable) {"
                "    element = element.parentElement;"
                "  }"
                "  return element;"
                "}", args, &result);
            if (!status)
                return;
            std::string top_element_id;

            if (!result.isObject()) {
                response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "no element reference returned by script");
                return;
            }
            Json::Value elementDict = result.get(getElementKey(), Json::Value::null);
            if (!elementDict.isString()) {
                response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "no element reference returned by script");
                return;
            }
            top_element_id = elementDict.asString(); 
            if (top_element_id.empty()) {
                response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "no element reference returned by script");
                return;
            }

            // check if top level contentEditable element is focused
            bool is_top_focused = false;
            status = isElementFocused(executor.view(), response, top_element_id, &is_top_focused);
            if (!status)
                return;
            // If is_text we want to send keys to the element
            // Otherwise, send keys to the top element
            if ((is_text && !is_focused) || (!is_text && !is_top_focused)) {
                // If element does not currentley have focus
                // will move caret
                // at end of element text. W3C mandates that the
                // caret be moved "after any child content"
                // Set selection using the element itself
                status = callFunctionWithTimeout(executor.view(), response,
                    "function(element) {"
                    "var range = document.createRange();"
                    "range.selectNodeContents(element);"
                    "range.collapse();"
                    "var sel = window.getSelection();"
                    "sel.removeAllRanges();"
                    "sel.addRange(range);"
                    "}", args, nullptr);
                if (!status)
                    return;
            }
            // Use top level element id for the purpose of focusing
            if (!is_text) {
                sendKeysToElement(executor.view(), response, top_element_id, is_text, &key_list);
                return;
            }
        }
        sendKeysToElement(executor.view(), response, element_id, is_text, &key_list);
    }
}

} // namespace webdriver
