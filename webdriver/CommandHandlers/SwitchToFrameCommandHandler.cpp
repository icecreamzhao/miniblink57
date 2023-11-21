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

#include "webdriver/CommandHandlers/SwitchToFrameCommandHandler.h"

namespace webdriver {

SwitchToFrameCommandHandler::SwitchToFrameCommandHandler(void)
{
}

SwitchToFrameCommandHandler::~SwitchToFrameCommandHandler(void)
{
}

void SwitchToFrameCommandHandler::ExecuteInternal(const MBCommandExecutor& executor, const ParametersMap& parameters, Response* response)
{
    response->SetSuccessResponse(Json::Value::null);

//     Json::Value frameId = Json::Value::null;
//     ParametersMap::const_iterator it = parameters.find("id");
//     if (it != parameters.end()) {
//         frameId = it->second;
//     } else {
//         response->SetErrorResponse(ERROR_INVALID_ARGUMENT, "Missing parameter: id");
//         return;
//     }
//     BrowserHandle browser_wrapper;
//     int status_code = executor.GetCurrentBrowser(&browser_wrapper);
//     if (status_code != WD_SUCCESS) {
//         response->SetErrorResponse(ERROR_NO_SUCH_WINDOW, "Unable to get browser");
//         return;
//     }
// 
//     std::string error_message = "No frame found";
//     if (frameId.isNull()) {
//         status_code = browser_wrapper->SetFocusedFrameByElement(NULL);
//     } else if (frameId.isObject()) {
//         Json::Value element_id = frameId.get(JSON_ELEMENT_PROPERTY_NAME, Json::Value::null);
// 
//         if (element_id.isNull()) {
//             status_code = EINVALIDARGUMENT;
//             error_message = "Frame identifier was an object, but not a web element reference";
//         } else {
//             std::string frame_element_id = element_id.asString();
// 
//             ElementHandle frame_element_wrapper;
//             status_code = this->GetElement(executor, frame_element_id, &frame_element_wrapper);
//             if (status_code == WD_SUCCESS) {
//                 status_code = browser_wrapper->SetFocusedFrameByElement(frame_element_wrapper->element());
//             }
//         }
//     } else if (frameId.isIntegral()) {
//         int frame_index = frameId.asInt();
//         if (frame_index < 0 || frame_index > 65535) {
//             status_code = EINVALIDARGUMENT;
//             error_message = "Frame identifier was an integer, but must be between 0 and 65535 inclusive";
//         } else {
//             status_code = browser_wrapper->SetFocusedFrameByIndex(frame_index);
//         }
//     } else {
//         status_code = EINVALIDARGUMENT;
//         error_message = "Frame identifier argument must be null, an integer, or a web element reference";
//     }
// 
//     if (status_code != WD_SUCCESS) {
//         response->SetErrorResponse(status_code, error_message);
//     } else {
//         response->SetSuccessResponse(Json::Value::null);
//     }
}

} // namespace webdriver
