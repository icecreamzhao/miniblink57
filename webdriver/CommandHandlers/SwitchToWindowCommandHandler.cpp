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

#include "webdriver/CommandHandlers/SwitchToWindowCommandHandler.h"
#include "webdriver/MBCommandExecutor.h"
#include "webdriver/server/errorcodes.h"

namespace webdriver {

SwitchToWindowCommandHandler::SwitchToWindowCommandHandler(void)
{
}

SwitchToWindowCommandHandler::~SwitchToWindowCommandHandler(void)
{
}

void SwitchToWindowCommandHandler::ExecuteInternal(const MBCommandExecutor& executor, const ParametersMap& params, Response* response)
{
    ParametersMap::const_iterator it = params.find("handle");
    if (it == params.end()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Missing parameter: name");
        return;
    }

    std::string foundBrowserId = "";
    std::string desiredName = it->second.asString();

    unsigned int limit = 10;
    unsigned int tries = 0;
    mbWebView foundBrowserWebview = NULL_WEBVIEW;
    do {
        tries++;

        std::vector<std::string> browsers;
        executor.getManagedBrowserHandles(&browsers);

        for (unsigned int i = 0; i < browsers.size(); ++i) {
            mbWebView browser;
            int get_handle_loop_status_code = executor.getManagedBrowser(browsers[i], &browser);
            if (get_handle_loop_status_code == WD_SUCCESS) {
                std::string browserName = browsers[i];
                if (browserName == desiredName) {
                    foundBrowserId = browsers[i];
                    foundBrowserWebview = browser;
                    break;
                }
            }
        }

        // Wait until new window name becomes available
        ::Sleep(100);
    } while (tries < limit && foundBrowserId == "");

    if (foundBrowserId == "") {
        response->SetErrorResponse(ERROR_NO_SUCH_WINDOW, "No window found");
        return;
    }

    // Reset the path to the focused frame before switching window context.

    mbWebView currentBrowser = executor.view();
    if (MBCommandExecutor::isValidWebView(currentBrowser))
        mbSetFocus(currentBrowser);

    MBCommandExecutor& mutableExecutor = const_cast<MBCommandExecutor&>(executor);
    mutableExecutor.setView(foundBrowserWebview, foundBrowserId);

//     mutableExecutor.set_current_browser_id(found_browser_handle);
//     status_code = executor.GetCurrentBrowser(&current_browser);
//     current_browser->set_wait_required(true);
    response->SetSuccessResponse(Json::Value::null);
}

} // namespace webdriver
