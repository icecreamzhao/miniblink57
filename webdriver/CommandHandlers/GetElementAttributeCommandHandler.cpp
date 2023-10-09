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

#include "webdriver/CommandHandlers/GetElementAttributeCommandHandler.h"

#include "webdriver/CommandHandlers/ElementUtil.h"
#include "webdriver/server/errorcodes.h"
#include "webdriver/server/wd_logging.h"
#include "webdriver/StringUtilities.h"
#include "webdriver/MBCommandExecutor.h"
#include "mbvip/core/mb.h"
#include <unordered_set>

namespace webdriver {

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

GetElementAttributeCommandHandler::GetElementAttributeCommandHandler(void)
{
}

GetElementAttributeCommandHandler::~GetElementAttributeCommandHandler(void)
{
}

void GetElementAttributeCommandHandler::ExecuteInternal(const MBCommandExecutor& executor, const ParametersMap& params, Response* response)
{
    ParametersMap::const_iterator idIt = params.find("id");
    ParametersMap::const_iterator nameIt = params.find("name");
    if (idIt == params.end()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Missing parameter in URL: id");
        return;
    } else if (nameIt == params.end()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Missing parameter in URL: name");
        return;
    }

    std::string elementId = idIt->second.asString();
    std::string name = nameIt->second.asString();

    bool status = checkElement(elementId, response);
    if (!status)
        return;

    Json::Value args;
    args.append(createElement(elementId));
    args.append(name);

    Json::Value result;
    status = callFunctionWithTimeout(executor.view(), response,
        booleanAttributes.count(StringUtilities::toLowerASCII(name))
        ? "(elem, attribute) => elem.hasAttribute(attribute) ? 'true' : null"
        : "(elem, attribute) => elem.getAttribute(attribute)",
        args, &result);
    if (!status)
        return;

    response->SetResponse("", result);

//         BrowserHandle browser_wrapper;
//         int status_code = executor.GetCurrentBrowser(&browser_wrapper);
//         if (status_code != WD_SUCCESS) {
//             response->SetErrorResponse(ERROR_NO_SUCH_WINDOW, "Unable to get browser");
//             return;
//         }
// 
//         ElementHandle element_wrapper;
//         status_code = this->GetElement(executor, element_id, &element_wrapper);
//         if (status_code == WD_SUCCESS) {
//             CComVariant attribute_value;
//             IECommandExecutor& mutable_executor = const_cast<IECommandExecutor&>(executor);
//             Json::Value value;
//             status_code = element_wrapper->GetAttributeValue(name, &attribute_value);
//             VariantUtilities::VariantAsJsonValue(mutable_executor.element_manager(), attribute_value, &value);
//             if (status_code != WD_SUCCESS) {
//                 response->SetErrorResponse(status_code, "Unable to get attribute");
//                 return;
//             } else {
//                 response->SetSuccessResponse(value);
//                 return;
//             }
//         } else if (status_code == ENOSUCHELEMENT) {
//             response->SetErrorResponse(ERROR_NO_SUCH_ELEMENT, "Invalid internal element ID requested: " + element_id);
//             return;
//         } else {
//             response->SetErrorResponse(ERROR_STALE_ELEMENT_REFERENCE, "Element is no longer valid");
//             return;
//         }
}

} // namespace webdriver
