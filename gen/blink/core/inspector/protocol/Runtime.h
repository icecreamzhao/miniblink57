// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef blink_protocol_Runtime_imported_h
#define blink_protocol_Runtime_imported_h

#include "core/inspector/protocol/Protocol.h"
#include <v8-inspector-protocol.h>

namespace blink {
namespace protocol {

    template <>
    struct ValueConversions<v8_inspector::protocol::Runtime::API::RemoteObject> {
        static std::unique_ptr<v8_inspector::protocol::Runtime::API::RemoteObject> fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            DebugBreak();
            return nullptr;
//             if (!value) {
//                 errors->addError("value expected");
//                 return nullptr;
//             }
//             String json = value->serialize();
//             auto result = v8_inspector::protocol::Runtime::API::RemoteObject::fromJSONString(toV8InspectorStringView(json));
//             if (!result)
//                 errors->addError("cannot parse");
//             return result;
        }

        static std::unique_ptr<protocol::Value> toValue(const v8_inspector::protocol::Runtime::API::RemoteObject* value)
        {
            DebugBreak();
            return nullptr;
//             auto json = value->toJSONString();
//             return SerializedValue::create(toCoreString(std::move(json)));
        }

        static std::unique_ptr<protocol::Value> toValue(const std::unique_ptr<v8_inspector::protocol::Runtime::API::RemoteObject>& value)
        {
            return toValue(value.get());
        }
    };

    template <>
    struct ValueConversions<v8_inspector::protocol::Runtime::API::StackTrace> {
        static std::unique_ptr<v8_inspector::protocol::Runtime::API::StackTrace> fromValue(protocol::Value* value, ErrorSupport* errors)
        {
//             if (!value) {
//                 errors->addError("value expected");
//                 return nullptr;
//             }
//             String json = value->serialize();
//             auto result = v8_inspector::protocol::Runtime::API::StackTrace::fromJSONString(toV8InspectorStringView(json));
//             if (!result)
//                 errors->addError("cannot parse");
//             return result;
            DebugBreak();
            return nullptr;
        }

        static std::unique_ptr<protocol::Value> toValue(const v8_inspector::protocol::Runtime::API::StackTrace* value)
        {
            DebugBreak();
            return nullptr;
//             auto json = value->toJSONString();
//             return SerializedValue::create(toCoreString(std::move(json)));
        }

        static std::unique_ptr<protocol::Value> toValue(const std::unique_ptr<v8_inspector::protocol::Runtime::API::StackTrace>& value)
        {
            return toValue(value.get());
        }
    };

} // namespace blink
} // namespace protocol

#endif // !defined(blink_protocol_Runtime_imported_h)
