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

#ifndef WEBDRIVER_IE_COMMANDHANDLER_H_
#define WEBDRIVER_IE_COMMANDHANDLER_H_

#include <map>
#include <string>

#include "webdriver/server/command_handler.h"
#include "webdriver/server/command.h"
#include "webdriver/server/response.h"
#include "webdriver/CustomTypes.h"

namespace webdriver {

// Forward declaration of classes to avoid
// circular include files.
class MBCommandExecutor;

class MBCommandHandler : public CommandHandler<MBCommandExecutor> {
public:
    MBCommandHandler(void);
    virtual ~MBCommandHandler(void);

protected:
    virtual void ExecuteInternal(const MBCommandExecutor& executor, const ParametersMap& command_parameters, Response* response);
    int GetElement(const MBCommandExecutor& executor, const std::string& element_id, ElementHandle* element_wrapper);
    Json::Value RecreateJsonParameterObject(const ParametersMap& command_parameters);
};

} // namespace webdriver

#endif // WEBDRIVER_IE_COMMANDHANDLER_H_
