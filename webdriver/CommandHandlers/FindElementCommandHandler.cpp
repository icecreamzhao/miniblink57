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

#include "webdriver/CommandHandlers/FindElementCommandHandler.h"

#include "webdriver/CommandHandlers/ElementUtil.h"
#include "webdriver/server/errorcodes.h"
#include "webdriver/MBCommandExecutor.h"
#include "webdriver/WebDriverConstants.h"
#include <ctime>

namespace webdriver {

FindElementCommandHandler::FindElementCommandHandler(void)
{
}

FindElementCommandHandler::~FindElementCommandHandler(void)
{
}

static void MB_CALL_TYPE onGetSourceCallback(mbWebView webView, void* param, const utf8* mhtml)
{
    int* waitFlag = (int*)param;
    *waitFlag = 1;

    if (!mhtml) {
        OutputDebugStringA("onGetSourceCallback fail\n");
        return;
    }
    std::string output = "onGetSourceCallback: ";
    output += mhtml;
    output += "\n";
//     if (output.size() > 500)
//         return;

    OutputDebugStringA(output.c_str());
}

void FindElementCommandHandler::ExecuteInternal(const MBCommandExecutor& executor, const ParametersMap& command_parameters, Response* response)
{
    ParametersMap::const_iterator usingIt = command_parameters.find("using");
    ParametersMap::const_iterator valueIt = command_parameters.find("value");
    if (usingIt == command_parameters.end()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Missing parameter: using");
        return;
    }
    if (!usingIt->second.isString()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "using parameter must be a string");
        return;
    }
    if (valueIt == command_parameters.end()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Missing parameter: value");
        return;
    }
    if (!valueIt->second.isString()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "value parameter must be a string");
        return;
    }

    std::string mechanism = usingIt->second.asString();
    std::string value = valueIt->second.asString();

    if (mechanism != "css selector" && mechanism != "tag name" && mechanism != "link text" && mechanism != "partial link text" && mechanism != "xpath") {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "using parameter value '" + mechanism + "' is not a valid value");
        return;
    }

    mbWebView webview = executor.view();
    JsQueryInfo* jsQueryInfo = (JsQueryInfo*)mbGetUserKeyValue(webview, "JsQueryInfo");
    for (int retryCount = 0; true; ++retryCount) {
        Json::Value result;
        bool ok = findElementCommon(1, true, nullptr, webview, mechanism, value, false, &result, response);
        if (!ok || !result.isNull())
            break;

        if (result.isNull() && jsQueryInfo->isAlertOpen) {
            response->SetErrorResponse(ERROR_UNEXPECTED_ALERT_OPEN, ERROR_UNEXPECTED_ALERT_OPEN);
            break;
        }
       
        if (retryCount > 4 && result.isNull()) {
            char* output = (char*)malloc(0x200);
            sprintf(output, "FindElementCommandHandler fail 1: %s\n", value.c_str());
            OutputDebugStringA(output);
            free(output);
            //MessageBoxA(0, "mhtml", "onGetSourceCallback", 0);

            int waitFlag = 0;
            mbGetSource(executor.view(), onGetSourceCallback, &waitFlag);
            while (waitFlag == 0) {
                ::Sleep(100);
            }
            OutputDebugStringA("FindElementCommandHandler fail 2\n");

            response->SetErrorResponse(ERROR_NO_SUCH_ELEMENT, "no such element");
            break;
        }
        ::Sleep(100);
    }
    //response->SetSuccessResponse(/*found_elements*/"{\"value\":{\"element-6066-11e4-a52e-4f735466cecf\":\"939eadc3-ef54-44cf-a4a8-5f35253d3a75\"}}");
}

} // namespace webdriver
