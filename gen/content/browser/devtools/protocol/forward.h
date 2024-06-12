// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef content_protocol_Forward_h
#define content_protocol_Forward_h

#include "content/browser/devtools/protocol_string.h"
#include "content/common/content_export.h"

#include <vector>

namespace content {
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

} // namespace content
} // namespace protocol

#endif // !defined(content_protocol_Forward_h)

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef content_protocol_Allocator_h
#define content_protocol_Allocator_h

namespace content {
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

} // namespace content
} // namespace protocol

#endif // !defined(content_protocol_Allocator_h)

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef content_protocol_FrontendChannel_h
#define content_protocol_FrontendChannel_h

namespace content {
namespace protocol {

    class CONTENT_EXPORT Serializable {
    public:
        virtual String serialize() = 0;
        virtual ~Serializable() = default;
    };

    class CONTENT_EXPORT FrontendChannel {
    public:
        virtual ~FrontendChannel() { }
        virtual void sendProtocolResponse(int callId, std::unique_ptr<Serializable> message) = 0;
        virtual void sendProtocolNotification(std::unique_ptr<Serializable> message) = 0;
        virtual void flushProtocolNotifications() = 0;
    };

} // namespace content
} // namespace protocol

#endif // !defined(content_protocol_FrontendChannel_h)
