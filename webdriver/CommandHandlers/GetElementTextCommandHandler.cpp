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

#include "GetElementTextCommandHandler.h"
#include "webdriver/CommandHandlers/ElementUtil.h"
#include "webdriver/server/errorcodes.h"
#include "webdriver/server/wd_logging.h"
#include "webdriver/MBCommandExecutor.h"
#include "webdriver/atoms.h"

namespace webdriver {

GetElementTextCommandHandler::GetElementTextCommandHandler(void)
{
}

GetElementTextCommandHandler::~GetElementTextCommandHandler(void)
{
}

void GetElementTextCommandHandler::ExecuteInternal(const MBCommandExecutor& executor, const ParametersMap& command_parameters, Response* response)
{
    ParametersMap::const_iterator id_parameter_iterator = command_parameters.find("id");
    if (id_parameter_iterator == command_parameters.end()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Missing parameter in URL: id");
        return;
    } 
    std::string element_id = id_parameter_iterator->second.asString();

    bool status = checkElement(element_id, response);
    if (!status)
        return;

    Json::Value args;
    args.append(createElement(element_id));
    callFunctionWithTimeout(executor.view(), response, webdriver::atoms::asString(webdriver::atoms::GET_TEXT), args, nullptr);
}

} // namespace webdriver
