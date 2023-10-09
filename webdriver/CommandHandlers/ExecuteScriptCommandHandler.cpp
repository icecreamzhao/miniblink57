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

#include "webdriver/CommandHandlers/ExecuteScriptCommandHandler.h"

#include "webdriver/server/errorcodes.h"
#include "webdriver/server/wd_logging.h"
#include "webdriver/MBCommandExecutor.h"
#include "webdriver/CommandHandlers/ElementUtil.h"
#include "mbvip/core/mb.h"

namespace webdriver {

ExecuteScriptCommandHandler::ExecuteScriptCommandHandler(void)
{
}

ExecuteScriptCommandHandler::~ExecuteScriptCommandHandler(void)
{
}

void ExecuteScriptCommandHandler::ExecuteInternal(const MBCommandExecutor& executor, const ParametersMap& params, Response* response)
{
    ParametersMap::const_iterator scriptIt = params.find("script");
    ParametersMap::const_iterator argsIt = params.find("args");
    if (scriptIt == params.end()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Missing parameter: script");
        return;
    }

    if (!scriptIt->second.isString()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "script parameter must be a string");
        return;
    }

    if (argsIt == params.end()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Missing parameter: args");
        return;
    }

    if (!argsIt->second.isArray()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "args parameter must be an array");
        return;
    }

    std::string scriptBody = scriptIt->second.asString();
    if (scriptBody == ":takeHeapSnapshot") {
        response->SetSuccessResponse(Json::Value::null);
        return;
    } else if (scriptBody == ":startProfile") {
        response->SetSuccessResponse(Json::Value::null);
        return;
    } else if (scriptBody == ":endProfile") {
        response->SetSuccessResponse(Json::Value::null);
        return;
    }

    if (scriptBody.find("//") != std::string::npos)
        scriptBody = scriptBody + "\n";

    Json::Value json_args(argsIt->second);
    Json::Value result;
    bool b = callUserSyncScript(executor.view(), response, scriptBody, json_args, &result);
    if (!b)
        return;
    response->SetResponse("", result);
}

} // namespace webdriver
