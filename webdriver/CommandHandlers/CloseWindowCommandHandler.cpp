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

#include "webdriver/CommandHandlers/CloseWindowCommandHandler.h"

#include "webdriver/CommandHandlers/ElementUtil.h"
#include "webdriver/MBCommandExecutor.h"
#include "webdriver/server/wd_logging.h"
#include "webdriver/server/errorcodes.h"
#include "mbvip/core/mb.h"
#include <functional>

namespace webdriver {

CloseWindowCommandHandler::CloseWindowCommandHandler(void)
{
}

CloseWindowCommandHandler::~CloseWindowCommandHandler(void)
{
}

void postToUiThreadSync(std::function<void(void)>&& closure);

void CloseWindowCommandHandler::ExecuteInternal(const MBCommandExecutor& executor, const ParametersMap& command_parameters, Response* response)
{
    // The session should end if the user sends a quit command,
    // or if the user sends a close command with exactly 1 window
    // open, per spec. Removing the window from the managed browser
    // list depends on events, which may be asynchronous, so cache
    // the window count *before* closing the current window.
    size_t current_window_count = executor.managedWindowCount();

    // TODO: Check HRESULT values for errors.
    mbWebView webview = executor.view();
    if (NULL_WEBVIEW == webview) {
        response->SetErrorResponse(ERROR_NO_SUCH_WINDOW, "Unable to get browser");
        return;
    }

    MBCommandExecutor* executorPtr = (MBCommandExecutor*)&executor;
    executorPtr->eraseManagedBrowserHandle(webview);

    CloseWindowCommandHandler* self = this;
    postToUiThreadSync([self, &webview] {
        mbDestroyWebView(webview);
    });

    if (current_window_count == 1) {
        MBCommandExecutor& mutableExecutor = const_cast<MBCommandExecutor&>(executor);
        mutableExecutor.setIsValid(false);
        mutableExecutor.setIsQuitting(true);
        Json::Value handles(Json::arrayValue);
        response->SetSuccessResponse(handles);
    }
}

} // namespace webdriver
