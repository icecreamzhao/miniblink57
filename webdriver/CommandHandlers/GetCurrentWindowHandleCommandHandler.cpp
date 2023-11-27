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

#include "webdriver/CommandHandlers/GetCurrentWindowHandleCommandHandler.h"

#include "webdriver/CommandHandlers/ElementUtil.h"
#include "webdriver/server/wd_logging.h"
#include "webdriver/server/errorcodes.h"
#include "webdriver/MBCommandExecutor.h"
#include "webdriver/StringUtilities.h"
#include "webdriver/WebDriverConstants.h"

namespace webdriver {

GetCurrentWindowHandleCommandHandler::GetCurrentWindowHandleCommandHandler(void)
{
}

GetCurrentWindowHandleCommandHandler::~GetCurrentWindowHandleCommandHandler(void)
{
}

void GetCurrentWindowHandleCommandHandler::ExecuteInternal(const MBCommandExecutor& executor, const ParametersMap& parameters, Response* response)
{
    std::string currentBrowserId = executor.browserId();
    mbWebView webview;
    int status_code = executor.getManagedBrowser(currentBrowserId, &webview);
    if (status_code != WD_SUCCESS) {
        OutputDebugStringA("GetCurrentWindowHandleCommandHandler fail: Window is closed\n");
        response->SetErrorResponse(ERROR_NO_SUCH_WINDOW, "Window is closed");
    } else {
        response->SetSuccessResponse(currentBrowserId);
    }
}

} // namespace webdriver
