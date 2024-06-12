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

#define CLICK_OPTION_EVENT_NAME L"ClickOptionEvent"

#include "webdriver/CommandHandlers/ClickElementCommandHandler.h"

#include "webdriver/CommandHandlers/ElementUtil.h"
#include "webdriver/server/errorcodes.h"
#include "webdriver/server/wd_logging.h"
#include "webdriver/MBCommandExecutor.h"
#include "webdriver/StringUtilities.h"
#include "webdriver/WebDriverConstants.h"

namespace webdriver {

ClickElementCommandHandler::ClickElementCommandHandler(void)
{
}

ClickElementCommandHandler::~ClickElementCommandHandler(void)
{
}

// Specifies the mouse buttons.
enum MouseButton {
    kLeftMouseButton = 0,
    kMiddleMouseButton,
    kRightMouseButton,
    kBackMouseButton,
    kForwardMouseButton,
    kNoneMouseButton
};

// Status GetMouseButton(const base::Value::Dict& params, MouseButton* button) 
// {
//     // Default to left mouse button.
//     int button_num = params.FindInt("button").value_or(0);
//     if (button_num < 0 || button_num > 2) {
//         return Status(kInvalidArgument,
//             base::StringPrintf("invalid button: %d", button_num));
//     }
//     *button = static_cast<MouseButton>(button_num);
//     return Status(kOk);
// }

void ClickElementCommandHandler::ExecuteInternal(const MBCommandExecutor& executor, const ParametersMap& params, Response* response)
{
    ParametersMap::const_iterator idIt = params.find("id");
    if (idIt == params.end()) {
        response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Missing parameter in URL: id");
        return;
    }

    std::string element_id = idIt->second.asString();
    Json::Value result;
    Json::Value args;
    args.append(createElement(element_id));

    bool status = callFunctionWithTimeout(
        executor.view(), response,
        "function(element) {"
        "  element.click();"
        "}", args, &result);
    if (!status)
        return;

// 
//     MouseButton button;
//     Status status = GetMouseButton(params, &button);
//     if (status.IsError())
//         return status;
//     std::vector<MouseEvent> events;
//     events.push_back(
//         MouseEvent(kPressedMouseEventType, button, session->mouse_position.x,
//             session->mouse_position.y, session->sticky_modifiers, 0, 1));
//     events.push_back(
//         MouseEvent(kReleasedMouseEventType, button, session->mouse_position.x,
//             session->mouse_position.y, session->sticky_modifiers,
//             MouseButtonToButtons(button), 1));
//     session->pressed_mouse_button = kNoneMouseButton;
//     return web_view->DispatchMouseEvents(events, session->GetCurrentFrameId(), false);
}

} // namespace webdriver
