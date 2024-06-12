// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_CONTENT_DECRYPTION_MODULE_MOJOM_SHARED_INTERNAL_H_
#define MEDIA_MOJO_INTERFACES_CONTENT_DECRYPTION_MODULE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "media/mojo/interfaces/decryptor.mojom-shared-internal.h"
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
namespace media {
namespace mojom {
    namespace internal {
        class CdmConfig_Data;
        class CdmPromiseResult_Data;
        class CdmKeyInformation_Data;
        using EmeInitDataType_Data = mojo::internal::NativeEnum_Data;
        using CdmPromiseResult_Exception_Data = mojo::internal::NativeEnum_Data;
        using CdmKeyInformation_KeyStatus_Data = mojo::internal::NativeEnum_Data;
        using ContentDecryptionModule_SessionType_Data = mojo::internal::NativeEnum_Data;
        using ContentDecryptionModuleClient_MessageType_Data = mojo::internal::NativeEnum_Data;

#pragma pack(push, 1)
        class CdmConfig_Data {
        public:
            static CdmConfig_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CdmConfig_Data))) CdmConfig_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t allow_distinctive_identifier : 1;
            uint8_t allow_persistent_state : 1;
            uint8_t use_hw_secure_codecs : 1;
            uint8_t padfinal_[7];

        private:
            CdmConfig_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CdmConfig_Data() = delete;
        };
        static_assert(sizeof(CdmConfig_Data) == 16,
            "Bad sizeof(CdmConfig_Data)");
        class CdmPromiseResult_Data {
        public:
            static CdmPromiseResult_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CdmPromiseResult_Data))) CdmPromiseResult_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t pad0_[3];
            int32_t exception;
            uint32_t system_code;
            uint8_t pad2_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> error_message;

        private:
            CdmPromiseResult_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CdmPromiseResult_Data() = delete;
        };
        static_assert(sizeof(CdmPromiseResult_Data) == 32,
            "Bad sizeof(CdmPromiseResult_Data)");
        class CdmKeyInformation_Data {
        public:
            static CdmKeyInformation_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CdmKeyInformation_Data))) CdmKeyInformation_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key_id;
            int32_t status;
            uint32_t system_code;

        private:
            CdmKeyInformation_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CdmKeyInformation_Data() = delete;
        };
        static_assert(sizeof(CdmKeyInformation_Data) == 24,
            "Bad sizeof(CdmKeyInformation_Data)");
        constexpr uint32_t kContentDecryptionModule_SetClient_Name = 0;
        class ContentDecryptionModule_SetClient_Params_Data {
        public:
            static ContentDecryptionModule_SetClient_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModule_SetClient_Params_Data))) ContentDecryptionModule_SetClient_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data client;

        private:
            ContentDecryptionModule_SetClient_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModule_SetClient_Params_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModule_SetClient_Params_Data) == 16,
            "Bad sizeof(ContentDecryptionModule_SetClient_Params_Data)");
        constexpr uint32_t kContentDecryptionModule_Initialize_Name = 1;
        class ContentDecryptionModule_Initialize_Params_Data {
        public:
            static ContentDecryptionModule_Initialize_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModule_Initialize_Params_Data))) ContentDecryptionModule_Initialize_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> key_system;
            mojo::internal::Pointer<mojo::internal::String_Data> security_origin;
            mojo::internal::Pointer<internal::CdmConfig_Data> cdm_config;

        private:
            ContentDecryptionModule_Initialize_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModule_Initialize_Params_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModule_Initialize_Params_Data) == 32,
            "Bad sizeof(ContentDecryptionModule_Initialize_Params_Data)");
        class ContentDecryptionModule_Initialize_ResponseParams_Data {
        public:
            static ContentDecryptionModule_Initialize_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModule_Initialize_ResponseParams_Data))) ContentDecryptionModule_Initialize_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::CdmPromiseResult_Data> result;
            int32_t cdm_id;
            mojo::internal::Interface_Data decryptor;
            uint8_t padfinal_[4];

        private:
            ContentDecryptionModule_Initialize_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModule_Initialize_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModule_Initialize_ResponseParams_Data) == 32,
            "Bad sizeof(ContentDecryptionModule_Initialize_ResponseParams_Data)");
        constexpr uint32_t kContentDecryptionModule_SetServerCertificate_Name = 2;
        class ContentDecryptionModule_SetServerCertificate_Params_Data {
        public:
            static ContentDecryptionModule_SetServerCertificate_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModule_SetServerCertificate_Params_Data))) ContentDecryptionModule_SetServerCertificate_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> certificate_data;

        private:
            ContentDecryptionModule_SetServerCertificate_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModule_SetServerCertificate_Params_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModule_SetServerCertificate_Params_Data) == 16,
            "Bad sizeof(ContentDecryptionModule_SetServerCertificate_Params_Data)");
        class ContentDecryptionModule_SetServerCertificate_ResponseParams_Data {
        public:
            static ContentDecryptionModule_SetServerCertificate_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModule_SetServerCertificate_ResponseParams_Data))) ContentDecryptionModule_SetServerCertificate_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::CdmPromiseResult_Data> result;

        private:
            ContentDecryptionModule_SetServerCertificate_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModule_SetServerCertificate_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModule_SetServerCertificate_ResponseParams_Data) == 16,
            "Bad sizeof(ContentDecryptionModule_SetServerCertificate_ResponseParams_Data)");
        constexpr uint32_t kContentDecryptionModule_CreateSessionAndGenerateRequest_Name = 3;
        class ContentDecryptionModule_CreateSessionAndGenerateRequest_Params_Data {
        public:
            static ContentDecryptionModule_CreateSessionAndGenerateRequest_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModule_CreateSessionAndGenerateRequest_Params_Data))) ContentDecryptionModule_CreateSessionAndGenerateRequest_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t session_type;
            int32_t init_data_type;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> init_data;

        private:
            ContentDecryptionModule_CreateSessionAndGenerateRequest_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModule_CreateSessionAndGenerateRequest_Params_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModule_CreateSessionAndGenerateRequest_Params_Data) == 24,
            "Bad sizeof(ContentDecryptionModule_CreateSessionAndGenerateRequest_Params_Data)");
        class ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams_Data {
        public:
            static ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams_Data))) ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::CdmPromiseResult_Data> result;
            mojo::internal::Pointer<mojo::internal::String_Data> session_id;

        private:
            ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams_Data) == 24,
            "Bad sizeof(ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams_Data)");
        constexpr uint32_t kContentDecryptionModule_LoadSession_Name = 4;
        class ContentDecryptionModule_LoadSession_Params_Data {
        public:
            static ContentDecryptionModule_LoadSession_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModule_LoadSession_Params_Data))) ContentDecryptionModule_LoadSession_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t session_type;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> session_id;

        private:
            ContentDecryptionModule_LoadSession_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModule_LoadSession_Params_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModule_LoadSession_Params_Data) == 24,
            "Bad sizeof(ContentDecryptionModule_LoadSession_Params_Data)");
        class ContentDecryptionModule_LoadSession_ResponseParams_Data {
        public:
            static ContentDecryptionModule_LoadSession_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModule_LoadSession_ResponseParams_Data))) ContentDecryptionModule_LoadSession_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::CdmPromiseResult_Data> result;
            mojo::internal::Pointer<mojo::internal::String_Data> session_id;

        private:
            ContentDecryptionModule_LoadSession_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModule_LoadSession_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModule_LoadSession_ResponseParams_Data) == 24,
            "Bad sizeof(ContentDecryptionModule_LoadSession_ResponseParams_Data)");
        constexpr uint32_t kContentDecryptionModule_UpdateSession_Name = 5;
        class ContentDecryptionModule_UpdateSession_Params_Data {
        public:
            static ContentDecryptionModule_UpdateSession_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModule_UpdateSession_Params_Data))) ContentDecryptionModule_UpdateSession_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> session_id;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> response;

        private:
            ContentDecryptionModule_UpdateSession_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModule_UpdateSession_Params_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModule_UpdateSession_Params_Data) == 24,
            "Bad sizeof(ContentDecryptionModule_UpdateSession_Params_Data)");
        class ContentDecryptionModule_UpdateSession_ResponseParams_Data {
        public:
            static ContentDecryptionModule_UpdateSession_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModule_UpdateSession_ResponseParams_Data))) ContentDecryptionModule_UpdateSession_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::CdmPromiseResult_Data> result;

        private:
            ContentDecryptionModule_UpdateSession_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModule_UpdateSession_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModule_UpdateSession_ResponseParams_Data) == 16,
            "Bad sizeof(ContentDecryptionModule_UpdateSession_ResponseParams_Data)");
        constexpr uint32_t kContentDecryptionModule_CloseSession_Name = 6;
        class ContentDecryptionModule_CloseSession_Params_Data {
        public:
            static ContentDecryptionModule_CloseSession_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModule_CloseSession_Params_Data))) ContentDecryptionModule_CloseSession_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> session_id;

        private:
            ContentDecryptionModule_CloseSession_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModule_CloseSession_Params_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModule_CloseSession_Params_Data) == 16,
            "Bad sizeof(ContentDecryptionModule_CloseSession_Params_Data)");
        class ContentDecryptionModule_CloseSession_ResponseParams_Data {
        public:
            static ContentDecryptionModule_CloseSession_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModule_CloseSession_ResponseParams_Data))) ContentDecryptionModule_CloseSession_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::CdmPromiseResult_Data> result;

        private:
            ContentDecryptionModule_CloseSession_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModule_CloseSession_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModule_CloseSession_ResponseParams_Data) == 16,
            "Bad sizeof(ContentDecryptionModule_CloseSession_ResponseParams_Data)");
        constexpr uint32_t kContentDecryptionModule_RemoveSession_Name = 7;
        class ContentDecryptionModule_RemoveSession_Params_Data {
        public:
            static ContentDecryptionModule_RemoveSession_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModule_RemoveSession_Params_Data))) ContentDecryptionModule_RemoveSession_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> session_id;

        private:
            ContentDecryptionModule_RemoveSession_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModule_RemoveSession_Params_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModule_RemoveSession_Params_Data) == 16,
            "Bad sizeof(ContentDecryptionModule_RemoveSession_Params_Data)");
        class ContentDecryptionModule_RemoveSession_ResponseParams_Data {
        public:
            static ContentDecryptionModule_RemoveSession_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModule_RemoveSession_ResponseParams_Data))) ContentDecryptionModule_RemoveSession_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::CdmPromiseResult_Data> result;

        private:
            ContentDecryptionModule_RemoveSession_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModule_RemoveSession_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModule_RemoveSession_ResponseParams_Data) == 16,
            "Bad sizeof(ContentDecryptionModule_RemoveSession_ResponseParams_Data)");
        constexpr uint32_t kContentDecryptionModuleClient_OnSessionMessage_Name = 0;
        class ContentDecryptionModuleClient_OnSessionMessage_Params_Data {
        public:
            static ContentDecryptionModuleClient_OnSessionMessage_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModuleClient_OnSessionMessage_Params_Data))) ContentDecryptionModuleClient_OnSessionMessage_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> session_id;
            int32_t message_type;
            uint8_t pad1_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> message;

        private:
            ContentDecryptionModuleClient_OnSessionMessage_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModuleClient_OnSessionMessage_Params_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModuleClient_OnSessionMessage_Params_Data) == 32,
            "Bad sizeof(ContentDecryptionModuleClient_OnSessionMessage_Params_Data)");
        constexpr uint32_t kContentDecryptionModuleClient_OnSessionClosed_Name = 1;
        class ContentDecryptionModuleClient_OnSessionClosed_Params_Data {
        public:
            static ContentDecryptionModuleClient_OnSessionClosed_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModuleClient_OnSessionClosed_Params_Data))) ContentDecryptionModuleClient_OnSessionClosed_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> session_id;

        private:
            ContentDecryptionModuleClient_OnSessionClosed_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModuleClient_OnSessionClosed_Params_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModuleClient_OnSessionClosed_Params_Data) == 16,
            "Bad sizeof(ContentDecryptionModuleClient_OnSessionClosed_Params_Data)");
        constexpr uint32_t kContentDecryptionModuleClient_OnSessionKeysChange_Name = 2;
        class ContentDecryptionModuleClient_OnSessionKeysChange_Params_Data {
        public:
            static ContentDecryptionModuleClient_OnSessionKeysChange_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModuleClient_OnSessionKeysChange_Params_Data))) ContentDecryptionModuleClient_OnSessionKeysChange_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> session_id;
            uint8_t has_additional_usable_key : 1;
            uint8_t pad1_[7];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::CdmKeyInformation_Data>>> keys_info;

        private:
            ContentDecryptionModuleClient_OnSessionKeysChange_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModuleClient_OnSessionKeysChange_Params_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModuleClient_OnSessionKeysChange_Params_Data) == 32,
            "Bad sizeof(ContentDecryptionModuleClient_OnSessionKeysChange_Params_Data)");
        constexpr uint32_t kContentDecryptionModuleClient_OnSessionExpirationUpdate_Name = 3;
        class ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params_Data {
        public:
            static ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params_Data))) ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> session_id;
            double new_expiry_time_sec;

        private:
            ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params_Data() = delete;
        };
        static_assert(sizeof(ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params_Data) == 24,
            "Bad sizeof(ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_CONTENT_DECRYPTION_MODULE_MOJOM_SHARED_INTERNAL_H_