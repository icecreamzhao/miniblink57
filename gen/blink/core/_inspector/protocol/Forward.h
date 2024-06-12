// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef blink_protocol_Forward_h
#define blink_protocol_Forward_h

#include "core/CoreExport.h"
#include "core/inspector/V8InspectorString.h"

#include <vector>

namespace blink {
namespace protocol {

    template <typename T>
    class Array;
    class DictionaryValue;
    class DispatchResponse;
    class ErrorSupport;
    class FundamentalValue;
    class ListValue;
    template <typename T>
    class Maybe;
    class Object;
    using Response = DispatchResponse;
    class SerializedValue;
    class StringValue;
    class UberDispatcher;
    class Value;

} // namespace blink
} // namespace protocol

#endif // !defined(blink_protocol_Forward_h)

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef blink_protocol_Allocator_h
#define blink_protocol_Allocator_h

namespace blink {
namespace protocol {

    enum NotNullTagEnum { NotNullLiteral };

#define PROTOCOL_DISALLOW_NEW()                                 \
private:                                                        \
    void* operator new(size_t) = delete;                        \
    void* operator new(size_t, NotNullTagEnum, void*) = delete; \
    void* operator new(size_t, void*) = delete;                 \
                                                                \
public:

#define PROTOCOL_DISALLOW_COPY(ClassName) \
private:                                  \
    ClassName(const ClassName&) = delete; \
    ClassName& operator=(const ClassName&) = delete

} // namespace blink
} // namespace protocol

#endif // !defined(blink_protocol_Allocator_h)

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef blink_protocol_FrontendChannel_h
#define blink_protocol_FrontendChannel_h

namespace blink {
namespace protocol {

    class CORE_EXPORT Serializable {
    public:
        virtual String serialize() = 0;
        virtual ~Serializable() = default;
    };

    class CORE_EXPORT FrontendChannel {
    public:
        virtual ~FrontendChannel() { }
        virtual void sendProtocolResponse(int callId, std::unique_ptr<Serializable> message) = 0;
        virtual void sendProtocolNotification(std::unique_ptr<Serializable> message) = 0;
        virtual void flushProtocolNotifications() = 0;
    };

} // namespace blink
} // namespace protocol

#endif // !defined(blink_protocol_FrontendChannel_h)
