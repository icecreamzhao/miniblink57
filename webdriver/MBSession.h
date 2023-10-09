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

#ifndef WEBDRIVER_IE_IESESSION_H_
#define WEBDRIVER_IE_IESESSION_H_

#include "webdriver/server/session.h"
#include <string>

namespace webdriver {

class MBCommandExecutor;

// Structure to be used for storing session initialization parameters
struct SessionParameters {
    int port;
};

class MBSession : public Session {
public:
    MBSession();
    virtual ~MBSession(void);

    void Initialize(void* init_params);
    void ShutDown(void);
    bool ExecuteCommand(const std::string& serialized_command, std::string* serialized_response);

    static std::string uuidCreate();

private:
    bool WaitForCommandExecutorExit(int timeout_in_milliseconds);
    MBCommandExecutor* m_commandExecutor = nullptr;
};

} // namespace webdriver

#endif // WEBDRIVER_IE_IESESSION_H_
