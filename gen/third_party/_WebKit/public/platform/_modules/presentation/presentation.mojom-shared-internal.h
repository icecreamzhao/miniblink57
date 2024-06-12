// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PRESENTATION_PRESENTATION_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PRESENTATION_PRESENTATION_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "url/mojo/url.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace blink {
namespace mojom {
    namespace internal {
        class PresentationSessionInfo_Data;
        class PresentationError_Data;
        class ConnectionMessage_Data;

        struct PresentationConnectionState_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
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

        struct PresentationConnectionCloseReason_Data {
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

        struct PresentationErrorType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
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

        struct PresentationMessageType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
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
        class PresentationSessionInfo_Data {
        public:
            static PresentationSessionInfo_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationSessionInfo_Data))) PresentationSessionInfo_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> url;
            mojo::internal::Pointer<mojo::internal::String_Data> id;

        private:
            PresentationSessionInfo_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationSessionInfo_Data() = delete;
        };
        static_assert(sizeof(PresentationSessionInfo_Data) == 24,
            "Bad sizeof(PresentationSessionInfo_Data)");
        class PresentationError_Data {
        public:
            static PresentationError_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationError_Data))) PresentationError_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error_type;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> message;

        private:
            PresentationError_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationError_Data() = delete;
        };
        static_assert(sizeof(PresentationError_Data) == 24,
            "Bad sizeof(PresentationError_Data)");
        class ConnectionMessage_Data {
        public:
            static ConnectionMessage_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ConnectionMessage_Data))) ConnectionMessage_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t type;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> message;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> data;

        private:
            ConnectionMessage_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ConnectionMessage_Data() = delete;
        };
        static_assert(sizeof(ConnectionMessage_Data) == 32,
            "Bad sizeof(ConnectionMessage_Data)");
        constexpr uint32_t kPresentationConnection_OnMessage_Name = 0;
        class PresentationConnection_OnMessage_Params_Data {
        public:
            static PresentationConnection_OnMessage_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationConnection_OnMessage_Params_Data))) PresentationConnection_OnMessage_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::ConnectionMessage_Data> message;

        private:
            PresentationConnection_OnMessage_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationConnection_OnMessage_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationConnection_OnMessage_Params_Data) == 16,
            "Bad sizeof(PresentationConnection_OnMessage_Params_Data)");
        class PresentationConnection_OnMessage_ResponseParams_Data {
        public:
            static PresentationConnection_OnMessage_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationConnection_OnMessage_ResponseParams_Data))) PresentationConnection_OnMessage_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            PresentationConnection_OnMessage_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationConnection_OnMessage_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(PresentationConnection_OnMessage_ResponseParams_Data) == 16,
            "Bad sizeof(PresentationConnection_OnMessage_ResponseParams_Data)");
        constexpr uint32_t kPresentationConnection_DidChangeState_Name = 1;
        class PresentationConnection_DidChangeState_Params_Data {
        public:
            static PresentationConnection_DidChangeState_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationConnection_DidChangeState_Params_Data))) PresentationConnection_DidChangeState_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t state;
            uint8_t padfinal_[4];

        private:
            PresentationConnection_DidChangeState_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationConnection_DidChangeState_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationConnection_DidChangeState_Params_Data) == 16,
            "Bad sizeof(PresentationConnection_DidChangeState_Params_Data)");
        constexpr uint32_t kPresentationService_SetClient_Name = 0;
        class PresentationService_SetClient_Params_Data {
        public:
            static PresentationService_SetClient_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationService_SetClient_Params_Data))) PresentationService_SetClient_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data client;

        private:
            PresentationService_SetClient_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationService_SetClient_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationService_SetClient_Params_Data) == 16,
            "Bad sizeof(PresentationService_SetClient_Params_Data)");
        constexpr uint32_t kPresentationService_SetDefaultPresentationUrls_Name = 1;
        class PresentationService_SetDefaultPresentationUrls_Params_Data {
        public:
            static PresentationService_SetDefaultPresentationUrls_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationService_SetDefaultPresentationUrls_Params_Data))) PresentationService_SetDefaultPresentationUrls_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::url::mojom::internal::Url_Data>>> presentation_urls;

        private:
            PresentationService_SetDefaultPresentationUrls_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationService_SetDefaultPresentationUrls_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationService_SetDefaultPresentationUrls_Params_Data) == 16,
            "Bad sizeof(PresentationService_SetDefaultPresentationUrls_Params_Data)");
        constexpr uint32_t kPresentationService_ListenForScreenAvailability_Name = 2;
        class PresentationService_ListenForScreenAvailability_Params_Data {
        public:
            static PresentationService_ListenForScreenAvailability_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationService_ListenForScreenAvailability_Params_Data))) PresentationService_ListenForScreenAvailability_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> availability_url;

        private:
            PresentationService_ListenForScreenAvailability_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationService_ListenForScreenAvailability_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationService_ListenForScreenAvailability_Params_Data) == 16,
            "Bad sizeof(PresentationService_ListenForScreenAvailability_Params_Data)");
        constexpr uint32_t kPresentationService_StopListeningForScreenAvailability_Name = 3;
        class PresentationService_StopListeningForScreenAvailability_Params_Data {
        public:
            static PresentationService_StopListeningForScreenAvailability_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationService_StopListeningForScreenAvailability_Params_Data))) PresentationService_StopListeningForScreenAvailability_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> availability_url;

        private:
            PresentationService_StopListeningForScreenAvailability_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationService_StopListeningForScreenAvailability_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationService_StopListeningForScreenAvailability_Params_Data) == 16,
            "Bad sizeof(PresentationService_StopListeningForScreenAvailability_Params_Data)");
        constexpr uint32_t kPresentationService_StartSession_Name = 4;
        class PresentationService_StartSession_Params_Data {
        public:
            static PresentationService_StartSession_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationService_StartSession_Params_Data))) PresentationService_StartSession_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::url::mojom::internal::Url_Data>>> presentation_urls;

        private:
            PresentationService_StartSession_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationService_StartSession_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationService_StartSession_Params_Data) == 16,
            "Bad sizeof(PresentationService_StartSession_Params_Data)");
        class PresentationService_StartSession_ResponseParams_Data {
        public:
            static PresentationService_StartSession_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationService_StartSession_ResponseParams_Data))) PresentationService_StartSession_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PresentationSessionInfo_Data> sessionInfo;
            mojo::internal::Pointer<internal::PresentationError_Data> error;

        private:
            PresentationService_StartSession_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationService_StartSession_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(PresentationService_StartSession_ResponseParams_Data) == 24,
            "Bad sizeof(PresentationService_StartSession_ResponseParams_Data)");
        constexpr uint32_t kPresentationService_JoinSession_Name = 5;
        class PresentationService_JoinSession_Params_Data {
        public:
            static PresentationService_JoinSession_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationService_JoinSession_Params_Data))) PresentationService_JoinSession_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::url::mojom::internal::Url_Data>>> presentation_urls;
            mojo::internal::Pointer<mojo::internal::String_Data> presentation_id;

        private:
            PresentationService_JoinSession_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationService_JoinSession_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationService_JoinSession_Params_Data) == 24,
            "Bad sizeof(PresentationService_JoinSession_Params_Data)");
        class PresentationService_JoinSession_ResponseParams_Data {
        public:
            static PresentationService_JoinSession_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationService_JoinSession_ResponseParams_Data))) PresentationService_JoinSession_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PresentationSessionInfo_Data> sessionInfo;
            mojo::internal::Pointer<internal::PresentationError_Data> error;

        private:
            PresentationService_JoinSession_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationService_JoinSession_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(PresentationService_JoinSession_ResponseParams_Data) == 24,
            "Bad sizeof(PresentationService_JoinSession_ResponseParams_Data)");
        constexpr uint32_t kPresentationService_SetPresentationConnection_Name = 6;
        class PresentationService_SetPresentationConnection_Params_Data {
        public:
            static PresentationService_SetPresentationConnection_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationService_SetPresentationConnection_Params_Data))) PresentationService_SetPresentationConnection_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PresentationSessionInfo_Data> sessionInfo;
            mojo::internal::Interface_Data controller_connection_ptr;
            mojo::internal::Handle_Data receiver_connection_request;
            uint8_t padfinal_[4];

        private:
            PresentationService_SetPresentationConnection_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationService_SetPresentationConnection_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationService_SetPresentationConnection_Params_Data) == 32,
            "Bad sizeof(PresentationService_SetPresentationConnection_Params_Data)");
        constexpr uint32_t kPresentationService_SendConnectionMessage_Name = 7;
        class PresentationService_SendConnectionMessage_Params_Data {
        public:
            static PresentationService_SendConnectionMessage_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationService_SendConnectionMessage_Params_Data))) PresentationService_SendConnectionMessage_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PresentationSessionInfo_Data> sessionInfo;
            mojo::internal::Pointer<internal::ConnectionMessage_Data> message_request;

        private:
            PresentationService_SendConnectionMessage_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationService_SendConnectionMessage_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationService_SendConnectionMessage_Params_Data) == 24,
            "Bad sizeof(PresentationService_SendConnectionMessage_Params_Data)");
        class PresentationService_SendConnectionMessage_ResponseParams_Data {
        public:
            static PresentationService_SendConnectionMessage_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationService_SendConnectionMessage_ResponseParams_Data))) PresentationService_SendConnectionMessage_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            PresentationService_SendConnectionMessage_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationService_SendConnectionMessage_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(PresentationService_SendConnectionMessage_ResponseParams_Data) == 16,
            "Bad sizeof(PresentationService_SendConnectionMessage_ResponseParams_Data)");
        constexpr uint32_t kPresentationService_CloseConnection_Name = 8;
        class PresentationService_CloseConnection_Params_Data {
        public:
            static PresentationService_CloseConnection_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationService_CloseConnection_Params_Data))) PresentationService_CloseConnection_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> presentation_url;
            mojo::internal::Pointer<mojo::internal::String_Data> presentation_id;

        private:
            PresentationService_CloseConnection_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationService_CloseConnection_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationService_CloseConnection_Params_Data) == 24,
            "Bad sizeof(PresentationService_CloseConnection_Params_Data)");
        constexpr uint32_t kPresentationService_Terminate_Name = 9;
        class PresentationService_Terminate_Params_Data {
        public:
            static PresentationService_Terminate_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationService_Terminate_Params_Data))) PresentationService_Terminate_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> presentation_url;
            mojo::internal::Pointer<mojo::internal::String_Data> presentation_id;

        private:
            PresentationService_Terminate_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationService_Terminate_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationService_Terminate_Params_Data) == 24,
            "Bad sizeof(PresentationService_Terminate_Params_Data)");
        constexpr uint32_t kPresentationService_ListenForConnectionMessages_Name = 10;
        class PresentationService_ListenForConnectionMessages_Params_Data {
        public:
            static PresentationService_ListenForConnectionMessages_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationService_ListenForConnectionMessages_Params_Data))) PresentationService_ListenForConnectionMessages_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PresentationSessionInfo_Data> sessionInfo;

        private:
            PresentationService_ListenForConnectionMessages_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationService_ListenForConnectionMessages_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationService_ListenForConnectionMessages_Params_Data) == 16,
            "Bad sizeof(PresentationService_ListenForConnectionMessages_Params_Data)");
        constexpr uint32_t kPresentationServiceClient_OnScreenAvailabilityNotSupported_Name = 0;
        class PresentationServiceClient_OnScreenAvailabilityNotSupported_Params_Data {
        public:
            static PresentationServiceClient_OnScreenAvailabilityNotSupported_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationServiceClient_OnScreenAvailabilityNotSupported_Params_Data))) PresentationServiceClient_OnScreenAvailabilityNotSupported_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> url;

        private:
            PresentationServiceClient_OnScreenAvailabilityNotSupported_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationServiceClient_OnScreenAvailabilityNotSupported_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationServiceClient_OnScreenAvailabilityNotSupported_Params_Data) == 16,
            "Bad sizeof(PresentationServiceClient_OnScreenAvailabilityNotSupported_Params_Data)");
        constexpr uint32_t kPresentationServiceClient_OnScreenAvailabilityUpdated_Name = 1;
        class PresentationServiceClient_OnScreenAvailabilityUpdated_Params_Data {
        public:
            static PresentationServiceClient_OnScreenAvailabilityUpdated_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationServiceClient_OnScreenAvailabilityUpdated_Params_Data))) PresentationServiceClient_OnScreenAvailabilityUpdated_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> url;
            uint8_t available : 1;
            uint8_t padfinal_[7];

        private:
            PresentationServiceClient_OnScreenAvailabilityUpdated_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationServiceClient_OnScreenAvailabilityUpdated_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationServiceClient_OnScreenAvailabilityUpdated_Params_Data) == 24,
            "Bad sizeof(PresentationServiceClient_OnScreenAvailabilityUpdated_Params_Data)");
        constexpr uint32_t kPresentationServiceClient_OnDefaultSessionStarted_Name = 2;
        class PresentationServiceClient_OnDefaultSessionStarted_Params_Data {
        public:
            static PresentationServiceClient_OnDefaultSessionStarted_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationServiceClient_OnDefaultSessionStarted_Params_Data))) PresentationServiceClient_OnDefaultSessionStarted_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PresentationSessionInfo_Data> sessionInfo;

        private:
            PresentationServiceClient_OnDefaultSessionStarted_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationServiceClient_OnDefaultSessionStarted_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationServiceClient_OnDefaultSessionStarted_Params_Data) == 16,
            "Bad sizeof(PresentationServiceClient_OnDefaultSessionStarted_Params_Data)");
        constexpr uint32_t kPresentationServiceClient_OnConnectionStateChanged_Name = 3;
        class PresentationServiceClient_OnConnectionStateChanged_Params_Data {
        public:
            static PresentationServiceClient_OnConnectionStateChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationServiceClient_OnConnectionStateChanged_Params_Data))) PresentationServiceClient_OnConnectionStateChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PresentationSessionInfo_Data> connection;
            int32_t newState;
            uint8_t padfinal_[4];

        private:
            PresentationServiceClient_OnConnectionStateChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationServiceClient_OnConnectionStateChanged_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationServiceClient_OnConnectionStateChanged_Params_Data) == 24,
            "Bad sizeof(PresentationServiceClient_OnConnectionStateChanged_Params_Data)");
        constexpr uint32_t kPresentationServiceClient_OnConnectionClosed_Name = 4;
        class PresentationServiceClient_OnConnectionClosed_Params_Data {
        public:
            static PresentationServiceClient_OnConnectionClosed_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationServiceClient_OnConnectionClosed_Params_Data))) PresentationServiceClient_OnConnectionClosed_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PresentationSessionInfo_Data> connection;
            int32_t reason;
            uint8_t pad1_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> message;

        private:
            PresentationServiceClient_OnConnectionClosed_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationServiceClient_OnConnectionClosed_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationServiceClient_OnConnectionClosed_Params_Data) == 32,
            "Bad sizeof(PresentationServiceClient_OnConnectionClosed_Params_Data)");
        constexpr uint32_t kPresentationServiceClient_OnConnectionMessagesReceived_Name = 5;
        class PresentationServiceClient_OnConnectionMessagesReceived_Params_Data {
        public:
            static PresentationServiceClient_OnConnectionMessagesReceived_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationServiceClient_OnConnectionMessagesReceived_Params_Data))) PresentationServiceClient_OnConnectionMessagesReceived_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PresentationSessionInfo_Data> sessionInfo;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::ConnectionMessage_Data>>> messages;

        private:
            PresentationServiceClient_OnConnectionMessagesReceived_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationServiceClient_OnConnectionMessagesReceived_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationServiceClient_OnConnectionMessagesReceived_Params_Data) == 24,
            "Bad sizeof(PresentationServiceClient_OnConnectionMessagesReceived_Params_Data)");
        constexpr uint32_t kPresentationServiceClient_OnReceiverConnectionAvailable_Name = 6;
        class PresentationServiceClient_OnReceiverConnectionAvailable_Params_Data {
        public:
            static PresentationServiceClient_OnReceiverConnectionAvailable_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PresentationServiceClient_OnReceiverConnectionAvailable_Params_Data))) PresentationServiceClient_OnReceiverConnectionAvailable_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PresentationSessionInfo_Data> sessionInfo;
            mojo::internal::Interface_Data controller_connection_ptr;
            mojo::internal::Handle_Data receiver_connection_request;
            uint8_t padfinal_[4];

        private:
            PresentationServiceClient_OnReceiverConnectionAvailable_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PresentationServiceClient_OnReceiverConnectionAvailable_Params_Data() = delete;
        };
        static_assert(sizeof(PresentationServiceClient_OnReceiverConnectionAvailable_Params_Data) == 32,
            "Bad sizeof(PresentationServiceClient_OnReceiverConnectionAvailable_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PRESENTATION_PRESENTATION_MOJOM_SHARED_INTERNAL_H_