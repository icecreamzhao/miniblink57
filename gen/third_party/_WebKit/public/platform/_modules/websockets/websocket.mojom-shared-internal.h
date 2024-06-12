// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSOCKETS_WEBSOCKET_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSOCKETS_WEBSOCKET_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "url/mojo/origin.mojom-shared-internal.h"
#include "url/mojo/url.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace blink {
namespace mojom {
    namespace internal {
        class HttpHeader_Data;
        class WebSocketHandshakeRequest_Data;
        class WebSocketHandshakeResponse_Data;

        struct WebSocketMessageType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

#pragma pack(push, 1)
        class HttpHeader_Data {
        public:
            static HttpHeader_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(HttpHeader_Data))) HttpHeader_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::Pointer<mojo::internal::String_Data> value;

        private:
            HttpHeader_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~HttpHeader_Data() = delete;
        };
        static_assert(sizeof(HttpHeader_Data) == 24,
            "Bad sizeof(HttpHeader_Data)");
        class WebSocketHandshakeRequest_Data {
        public:
            static WebSocketHandshakeRequest_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebSocketHandshakeRequest_Data))) WebSocketHandshakeRequest_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> url;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::HttpHeader_Data>>> headers;
            mojo::internal::Pointer<mojo::internal::String_Data> headers_text;

        private:
            WebSocketHandshakeRequest_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebSocketHandshakeRequest_Data() = delete;
        };
        static_assert(sizeof(WebSocketHandshakeRequest_Data) == 32,
            "Bad sizeof(WebSocketHandshakeRequest_Data)");
        class WebSocketHandshakeResponse_Data {
        public:
            static WebSocketHandshakeResponse_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebSocketHandshakeResponse_Data))) WebSocketHandshakeResponse_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> url;
            int32_t status_code;
            uint8_t pad1_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> status_text;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::HttpHeader_Data>>> headers;
            mojo::internal::Pointer<mojo::internal::String_Data> headers_text;

        private:
            WebSocketHandshakeResponse_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebSocketHandshakeResponse_Data() = delete;
        };
        static_assert(sizeof(WebSocketHandshakeResponse_Data) == 48,
            "Bad sizeof(WebSocketHandshakeResponse_Data)");
        constexpr uint32_t kWebSocketClient_OnFailChannel_Name = 0;
        class WebSocketClient_OnFailChannel_Params_Data {
        public:
            static WebSocketClient_OnFailChannel_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebSocketClient_OnFailChannel_Params_Data))) WebSocketClient_OnFailChannel_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> reason;

        private:
            WebSocketClient_OnFailChannel_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebSocketClient_OnFailChannel_Params_Data() = delete;
        };
        static_assert(sizeof(WebSocketClient_OnFailChannel_Params_Data) == 16,
            "Bad sizeof(WebSocketClient_OnFailChannel_Params_Data)");
        constexpr uint32_t kWebSocketClient_OnStartOpeningHandshake_Name = 1;
        class WebSocketClient_OnStartOpeningHandshake_Params_Data {
        public:
            static WebSocketClient_OnStartOpeningHandshake_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebSocketClient_OnStartOpeningHandshake_Params_Data))) WebSocketClient_OnStartOpeningHandshake_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::WebSocketHandshakeRequest_Data> request;

        private:
            WebSocketClient_OnStartOpeningHandshake_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebSocketClient_OnStartOpeningHandshake_Params_Data() = delete;
        };
        static_assert(sizeof(WebSocketClient_OnStartOpeningHandshake_Params_Data) == 16,
            "Bad sizeof(WebSocketClient_OnStartOpeningHandshake_Params_Data)");
        constexpr uint32_t kWebSocketClient_OnFinishOpeningHandshake_Name = 2;
        class WebSocketClient_OnFinishOpeningHandshake_Params_Data {
        public:
            static WebSocketClient_OnFinishOpeningHandshake_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebSocketClient_OnFinishOpeningHandshake_Params_Data))) WebSocketClient_OnFinishOpeningHandshake_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::WebSocketHandshakeResponse_Data> response;

        private:
            WebSocketClient_OnFinishOpeningHandshake_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebSocketClient_OnFinishOpeningHandshake_Params_Data() = delete;
        };
        static_assert(sizeof(WebSocketClient_OnFinishOpeningHandshake_Params_Data) == 16,
            "Bad sizeof(WebSocketClient_OnFinishOpeningHandshake_Params_Data)");
        constexpr uint32_t kWebSocketClient_OnAddChannelResponse_Name = 3;
        class WebSocketClient_OnAddChannelResponse_Params_Data {
        public:
            static WebSocketClient_OnAddChannelResponse_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebSocketClient_OnAddChannelResponse_Params_Data))) WebSocketClient_OnAddChannelResponse_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> selected_protocol;
            mojo::internal::Pointer<mojo::internal::String_Data> extensions;

        private:
            WebSocketClient_OnAddChannelResponse_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebSocketClient_OnAddChannelResponse_Params_Data() = delete;
        };
        static_assert(sizeof(WebSocketClient_OnAddChannelResponse_Params_Data) == 24,
            "Bad sizeof(WebSocketClient_OnAddChannelResponse_Params_Data)");
        constexpr uint32_t kWebSocketClient_OnDataFrame_Name = 4;
        class WebSocketClient_OnDataFrame_Params_Data {
        public:
            static WebSocketClient_OnDataFrame_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebSocketClient_OnDataFrame_Params_Data))) WebSocketClient_OnDataFrame_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t fin : 1;
            uint8_t pad0_[3];
            int32_t type;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> data;

        private:
            WebSocketClient_OnDataFrame_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebSocketClient_OnDataFrame_Params_Data() = delete;
        };
        static_assert(sizeof(WebSocketClient_OnDataFrame_Params_Data) == 24,
            "Bad sizeof(WebSocketClient_OnDataFrame_Params_Data)");
        constexpr uint32_t kWebSocketClient_OnFlowControl_Name = 5;
        class WebSocketClient_OnFlowControl_Params_Data {
        public:
            static WebSocketClient_OnFlowControl_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebSocketClient_OnFlowControl_Params_Data))) WebSocketClient_OnFlowControl_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t quota;

        private:
            WebSocketClient_OnFlowControl_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebSocketClient_OnFlowControl_Params_Data() = delete;
        };
        static_assert(sizeof(WebSocketClient_OnFlowControl_Params_Data) == 16,
            "Bad sizeof(WebSocketClient_OnFlowControl_Params_Data)");
        constexpr uint32_t kWebSocketClient_OnDropChannel_Name = 6;
        class WebSocketClient_OnDropChannel_Params_Data {
        public:
            static WebSocketClient_OnDropChannel_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebSocketClient_OnDropChannel_Params_Data))) WebSocketClient_OnDropChannel_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t was_clean : 1;
            uint8_t pad0_[1];
            uint16_t code;
            uint8_t pad1_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> reason;

        private:
            WebSocketClient_OnDropChannel_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebSocketClient_OnDropChannel_Params_Data() = delete;
        };
        static_assert(sizeof(WebSocketClient_OnDropChannel_Params_Data) == 24,
            "Bad sizeof(WebSocketClient_OnDropChannel_Params_Data)");
        constexpr uint32_t kWebSocketClient_OnClosingHandshake_Name = 7;
        class WebSocketClient_OnClosingHandshake_Params_Data {
        public:
            static WebSocketClient_OnClosingHandshake_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebSocketClient_OnClosingHandshake_Params_Data))) WebSocketClient_OnClosingHandshake_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            WebSocketClient_OnClosingHandshake_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebSocketClient_OnClosingHandshake_Params_Data() = delete;
        };
        static_assert(sizeof(WebSocketClient_OnClosingHandshake_Params_Data) == 8,
            "Bad sizeof(WebSocketClient_OnClosingHandshake_Params_Data)");
        constexpr uint32_t kWebSocket_AddChannelRequest_Name = 0;
        class WebSocket_AddChannelRequest_Params_Data {
        public:
            static WebSocket_AddChannelRequest_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebSocket_AddChannelRequest_Params_Data))) WebSocket_AddChannelRequest_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> url;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<mojo::internal::String_Data>>> requested_protocols;
            mojo::internal::Pointer<::url::mojom::internal::Origin_Data> origin;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> first_party_for_cookies;
            mojo::internal::Pointer<mojo::internal::String_Data> user_agent_override;
            mojo::internal::Interface_Data client;

        private:
            WebSocket_AddChannelRequest_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebSocket_AddChannelRequest_Params_Data() = delete;
        };
        static_assert(sizeof(WebSocket_AddChannelRequest_Params_Data) == 56,
            "Bad sizeof(WebSocket_AddChannelRequest_Params_Data)");
        constexpr uint32_t kWebSocket_SendFrame_Name = 1;
        class WebSocket_SendFrame_Params_Data {
        public:
            static WebSocket_SendFrame_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebSocket_SendFrame_Params_Data))) WebSocket_SendFrame_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t fin : 1;
            uint8_t pad0_[3];
            int32_t type;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> data;

        private:
            WebSocket_SendFrame_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebSocket_SendFrame_Params_Data() = delete;
        };
        static_assert(sizeof(WebSocket_SendFrame_Params_Data) == 24,
            "Bad sizeof(WebSocket_SendFrame_Params_Data)");
        constexpr uint32_t kWebSocket_SendFlowControl_Name = 2;
        class WebSocket_SendFlowControl_Params_Data {
        public:
            static WebSocket_SendFlowControl_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebSocket_SendFlowControl_Params_Data))) WebSocket_SendFlowControl_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t quota;

        private:
            WebSocket_SendFlowControl_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebSocket_SendFlowControl_Params_Data() = delete;
        };
        static_assert(sizeof(WebSocket_SendFlowControl_Params_Data) == 16,
            "Bad sizeof(WebSocket_SendFlowControl_Params_Data)");
        constexpr uint32_t kWebSocket_StartClosingHandshake_Name = 3;
        class WebSocket_StartClosingHandshake_Params_Data {
        public:
            static WebSocket_StartClosingHandshake_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebSocket_StartClosingHandshake_Params_Data))) WebSocket_StartClosingHandshake_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint16_t code;
            uint8_t pad0_[6];
            mojo::internal::Pointer<mojo::internal::String_Data> reason;

        private:
            WebSocket_StartClosingHandshake_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebSocket_StartClosingHandshake_Params_Data() = delete;
        };
        static_assert(sizeof(WebSocket_StartClosingHandshake_Params_Data) == 24,
            "Bad sizeof(WebSocket_StartClosingHandshake_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSOCKETS_WEBSOCKET_MOJOM_SHARED_INTERNAL_H_