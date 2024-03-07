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

#include "webdriver/CommandHandlers/CreateNewWindowCommandHandler.h"

#include "webdriver/server/errorcodes.h"
#include "webdriver/server/wd_logging.h"
#include "webdriver/MBCommandExecutor.h"
#include "webdriver/CommandHandlers/ElementUtil.h"
#include "webdriver/WebDriverConstants.h"
#include "mbvip/core/mb.h"


namespace webdriver {

CreateNewWindowCommandHandler::CreateNewWindowCommandHandler(void)
{
}

CreateNewWindowCommandHandler::~CreateNewWindowCommandHandler(void)
{
}

void CreateNewWindowCommandHandler::ExecuteInternal(const MBCommandExecutor& executor, const ParametersMap& parameters, Response* response)
{
    ParametersMap::const_iterator typeIt = parameters.find("type");
    if (typeIt == parameters.end()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Missing parameter: type");
        return;
    }
    if (!typeIt->second.isString() && !typeIt->second.isNull()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "type parameter must be a string or null");
        return;
    }

    std::string window_type = WINDOW_WINDOW_TYPE;
    if (typeIt->second.isString()) {
        std::string parameter_value = typeIt->second.asString();
        if (parameter_value == TAB_WINDOW_TYPE) {
            window_type = TAB_WINDOW_TYPE;
        }
    }

    MBCommandExecutor& mutableExecutor = const_cast<MBCommandExecutor&>(executor);

    std::string errorMessage;
    mbWebView webview = NULL_WEBVIEW;
    std::string browserId;
    mutableExecutor.createNewBrowser(&errorMessage, &webview, &browserId);

    char* output = (char*)malloc(400);
    sprintf(output, "CreateNewWindowCommandHandler: %s\n", browserId.c_str());
    OutputDebugStringA(output);
    free(output);

    Json::Value result;
    result["handle"] = browserId;
    result["type"] = window_type;
    response->SetSuccessResponse(result);
}

} // namespace webdriver
