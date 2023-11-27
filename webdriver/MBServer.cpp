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

#include "webdriver/MBServer.h"

#include "webdriver/server/wd_logging.h"
#include "webdriver/MBSession.h"
//#include "webdriver/FileUtilities.h"
#include "webdriver/server/server.h"
#include <time.h>

namespace webdriver {

MBServer::MBServer(
    int port, const std::string& host, const std::string& log_level, const std::string& log_file, const std::string& version, const std::string& acl)
    : Server(port, host, log_level, log_file, acl)
{
    WDLOG(TRACE) << "Entering MBServer::MBServer";
    WDLOG(INFO) << "Driver version: " << version;
    this->version_ = version;
    this->AddCommand("/session/:sessionid/ie/script/background", "POST", "executeBackgroundScript");
    srand(time(NULL));
}

MBServer::~MBServer(void)
{
}

SessionHandle MBServer::InitializeSession()
{
    WDLOG(TRACE) << "Entering MBServer::InitializeSession";
    OutputDebugStringToFile("MBServer::InitializeSession 1\n");
    SessionHandle sessionHandle(new MBSession());
    SessionParameters params;
    params.port = this->port();

    sessionHandle->Initialize(reinterpret_cast<void*>(&params));
    return sessionHandle;
}

std::string MBServer::GetStatus()
{
    DebugBreak();
    return "";
//     WDLOG(TRACE) << "Entering MBServer::GetStatus";
//     SYSTEM_INFO system_info;
//     ::ZeroMemory(&system_info, sizeof(SYSTEM_INFO));
//     ::GetNativeSystemInfo(&system_info);
// 
//     std::string os_version = FileUtilities::GetFileVersion("kernel32.dll");
// 
//     std::string arch = "x86";
//     if (system_info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64) {
//         arch = "x64";
//     }
// 
//     Json::Value build;
//     build["version"] = this->version_;
// 
//     Json::Value os;
//     os["arch"] = arch;
//     os["name"] = "windows";
//     os["version"] = os_version;
// 
//     bool is_ready = this->session_count() < 1;
//     std::string message = "Ready to create session";
//     if (!is_ready) {
//         message = "Maximum number of sessions already created";
//     }
// 
//     Json::Value status;
//     status["build"] = build;
//     status["os"] = os;
//     status["ready"] = is_ready;
//     status["message"] = message;
//     Response response;
//     response.SetSuccessResponse(status);
//     return response.Serialize();
}

void MBServer::ShutDown()
{
//     WDLOG(TRACE) << "Entering MBServer::ShutDown";
//     DWORD process_id = ::GetCurrentProcessId();
//     std::wstring process_id_string = std::to_wstring(static_cast<long long>(process_id));
//     std::wstring event_name = IESERVER_SHUTDOWN_EVENT_NAME + process_id_string;
//     HANDLE event_handle = ::OpenEvent(EVENT_MODIFY_STATE, FALSE, event_name.c_str());
//     if (event_handle) {
//         ::SetEvent(event_handle);
//         ::CloseHandle(event_handle);
//     }
    Stop();
}

} //namespace webdriver
