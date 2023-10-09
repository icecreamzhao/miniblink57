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

#include "webdriver/MBSession.h"

#include "webdriver/server/wd_logging.h"
#include "webdriver/CommandExecutor.h"
#include "webdriver/MBCommandExecutor.h"
#include "webdriver/messages.h"
#include "webdriver/StringUtilities.h"
#include "webdriver/WebDriverConstants.h"
#include <functional>

#ifdef _WIN32
#include <rpcdce.h>
#else
#include <stdlib.h>
#include <time.h>
#endif // _WIN32

#define MUTEX_NAME L"WD_INITIALIZATION_MUTEX"
#define MUTEX_WAIT_TIMEOUT 30000
#define THREAD_WAIT_TIMEOUT 30000
#define EXECUTOR_EXIT_WAIT_TIMEOUT 5000
#define EXECUTOR_EXIT_WAIT_INTERVAL 100

namespace webdriver {

MBSession::MBSession()
{
    m_commandExecutor = new MBCommandExecutor();
}

MBSession::~MBSession(void)
{
    delete m_commandExecutor;
}

std::string MBSession::uuidCreate()
{
    srand(time(NULL));
    char buf[100] = { 0 };
    sprintf(buf,
        "{%08X-%04X-%04X-%04X-%04X%04X%04X}",
        rand() & 0xffffffff,
        rand() & 0xffff,
        rand() & 0xffff,
        rand() & 0xffff,
        rand() & 0xffff, rand() & 0xffff, rand() & 0xffff
    );
    return buf;
}

void MBSession::Initialize(void* initParams)
{
    OutputDebugStringToFile("MBSession::Initialize 1\n");
    WDLOG(TRACE) << "Entering MBSession::Initialize";

    SessionParameters* sessionPara = (SessionParameters*)initParams;
    std::string sessionId = "";
#if 0 // def _WIN32
    UUID guid;
    RPC_WSTR guidString = NULL;
    RPC_STATUS status = ::UuidCreate(&guid);
    ::UuidToStringW(&guid, &guidString);

    sessionId = StringUtilities::ToString(std::wstring((const WCHAR*)(&guidString[0])));
#else
    sessionId = uuidCreate();
#endif
    this->set_session_id(sessionId);

    MBCommandExecutorThreadContext* threadContext = new MBCommandExecutorThreadContext();
    threadContext->port = sessionPara->port;
    threadContext->sessionId = sessionId;
    threadContext->commandExecutor = m_commandExecutor;

    //postToUiThreadSync([threadContext] {
        threadContext->commandExecutor->initialize(threadContext->port, threadContext->sessionId);
        delete threadContext;
    //});
}

void MBSession::ShutDown(void)
{
    DebugBreak();
}

bool MBSession::WaitForCommandExecutorExit(int timeout_in_milliseconds)
{
//     LOG(TRACE) << "Entering MBSession::WaitForCommandExecutorExit";
//     int is_quitting = static_cast<int>(::SendMessage(this->executor_window_handle_, WD_GET_QUIT_STATUS, NULL, NULL));
//     int retry_count = timeout_in_milliseconds / EXECUTOR_EXIT_WAIT_INTERVAL;
//     while (is_quitting > 0 && --retry_count > 0) {
//         ::Sleep(EXECUTOR_EXIT_WAIT_INTERVAL);
//         is_quitting = static_cast<int>(::SendMessage(this->executor_window_handle_, WD_GET_QUIT_STATUS, NULL, NULL));
//     }
//     return is_quitting == 0;
    DebugBreak();
    return false;
}

// 本函数执行在http server work线程
bool MBSession::ExecuteCommand(const std::string& serializedCommand, std::string* serializedResponse)
{
    WDLOG(TRACE) << "Entering MBSession::ExecuteCommand";

    MBSession* self = this;
    bool ret = false;
    //postToUiThreadSync([self, serializedCommand, serializedResponse, &ret] {
        ret = self->m_commandExecutor->executeCommand(serializedCommand, serializedResponse);
    //});
    return ret;
// 
//     // Sending a command consists of five actions:
//     // 1. Setting the command to be executed
//     // 2. Executing the command
//     // 3. Waiting for the response to be populated
//     // 4. Retrieving the response
//     // 5. Retrieving whether the command sent caused the session to be ready for shutdown
//     LRESULT set_command_result = ::SendMessage(this->executor_window_handle_, WD_SET_COMMAND, NULL, reinterpret_cast<LPARAM>(serialized_command.c_str()));
//     while (set_command_result == 0) {
//         ::Sleep(500);
//         set_command_result = ::SendMessage(this->executor_window_handle_, WD_SET_COMMAND, NULL, reinterpret_cast<LPARAM>(serialized_command.c_str()));
//     }
//     ::PostMessage(this->executor_window_handle_, WD_EXEC_COMMAND, NULL, NULL);
// 
//     int response_length = static_cast<int>(::SendMessage(this->executor_window_handle_, WD_GET_RESPONSE_LENGTH, NULL, NULL));
//     LOG(TRACE) << "Beginning wait for response length to be not zero";
//     while (response_length == 0) {
//         // Sleep a short time to prevent thread starvation on single-core machines.
//         ::Sleep(10);
//         response_length = static_cast<int>(::SendMessage(this->executor_window_handle_, WD_GET_RESPONSE_LENGTH, NULL, NULL));
//     }
//     LOG(TRACE) << "Found non-zero response length";
// 
//     // Must add one to the length to handle the terminating character.
//     std::vector<char> response_buffer(response_length + 1);
//     ::SendMessage(this->executor_window_handle_, WD_GET_RESPONSE, NULL, reinterpret_cast<LPARAM>(&response_buffer[0]));
//     *serialized_response = &response_buffer[0];
//     bool session_is_valid = ::SendMessage(this->executor_window_handle_, WD_IS_SESSION_VALID, NULL, NULL) != 0;
//     return session_is_valid;
}

} // namespace webdriver
