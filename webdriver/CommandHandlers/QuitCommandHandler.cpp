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

#include "webdriver/CommandHandlers/QuitCommandHandler.h"
#include <functional>

namespace webdriver {

QuitCommandHandler::QuitCommandHandler(void)
{
}

QuitCommandHandler::~QuitCommandHandler(void)
{
}

void postToUiThreadSync(std::function<void(void)>&& closure);

void QuitCommandHandler::ExecuteInternal(const MBCommandExecutor& executor, const ParametersMap& command_parameters, Response* response)
{
    MBCommandExecutor& mutableExecutor = const_cast<MBCommandExecutor&>(executor);
    mutableExecutor.setIsQuitting(true);

    std::vector<std::string> browserHandles;
    executor.getManagedBrowserHandles(&browserHandles);

    std::vector<std::string>::iterator end = browserHandles.end();
    for (std::vector<std::string>::iterator it = browserHandles.begin(); it != end; ++it) {
//         BrowserHandle browser_wrapper;
//         int status_code = executor.getManagedBrowser(*it, &browser_wrapper);
//         if (status_code == WD_SUCCESS && !browser_wrapper->is_closing()) {
//             browser_wrapper->Close();
//         }
        mbWebView webview = NULL_WEBVIEW;
        mutableExecutor.getManagedBrowser(*it, &webview);
        if (NULL_WEBVIEW != webview) {
            postToUiThreadSync([&webview] {
                mbDestroyWebView(webview);
            });
        }
    }

    // Calling quit will always result in an invalid session.
    mutableExecutor.setIsValid(false);
    response->SetSuccessResponse(Json::Value::null);
}

} // namespace webdriver
