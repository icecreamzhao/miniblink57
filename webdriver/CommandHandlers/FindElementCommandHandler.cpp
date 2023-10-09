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

void FindElementCommandHandler::ExecuteInternal(const MBCommandExecutor& executor, const ParametersMap& command_parameters, Response* response)
{
    ParametersMap::const_iterator using_parameter_iterator = command_parameters.find("using");
    ParametersMap::const_iterator value_parameter_iterator = command_parameters.find("value");
    if (using_parameter_iterator == command_parameters.end()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Missing parameter: using");
        return;
    }
    if (!using_parameter_iterator->second.isString()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "using parameter must be a string");
        return;
    }
    if (value_parameter_iterator == command_parameters.end()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Missing parameter: value");
        return;
    }
    if (!value_parameter_iterator->second.isString()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "value parameter must be a string");
        return;
    }

    std::string mechanism = using_parameter_iterator->second.asString();
    std::string value = value_parameter_iterator->second.asString();

    if (mechanism != "css selector" && mechanism != "tag name" && mechanism != "link text" && mechanism != "partial link text" && mechanism != "xpath") {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "using parameter value '" + mechanism + "' is not a valid value");
        return;
    }
    
    bool ok = findElementCommon(1, true,
        nullptr /*root_element_id*/,
        executor.view(),
        mechanism, value,
        //std::unique_ptr<base::Value>*value,
        false /*isShadowRoot*/,
        response);

    //response->SetSuccessResponse(/*found_elements*/"{\"value\":{\"element-6066-11e4-a52e-4f735466cecf\":\"939eadc3-ef54-44cf-a4a8-5f35253d3a75\"}}");
}

} // namespace webdriver
