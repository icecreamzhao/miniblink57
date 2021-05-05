// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_NFC_NFC_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_NFC_NFC_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace device {
namespace nfc {
    namespace mojom {
        namespace internal {
            class NFCError_Data;
            class NFCRecord_Data;
            class NFCMessage_Data;
            class NFCPushOptions_Data;
            class NFCRecordTypeFilter_Data;
            class NFCWatchOptions_Data;

            struct NFCErrorType_Data {
            public:
                static bool constexpr kIsExtensible = false;

                static bool IsKnownValue(int32_t value)
                {
                    switch (value) {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
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

            struct NFCRecordType_Data {
            public:
                static bool constexpr kIsExtensible = false;

                static bool IsKnownValue(int32_t value)
                {
                    switch (value) {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
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

            struct NFCPushTarget_Data {
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

            struct NFCWatchMode_Data {
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
            class NFCError_Data {
            public:
                static NFCError_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFCError_Data))) NFCError_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                int32_t error_type;
                uint8_t padfinal_[4];

            private:
                NFCError_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFCError_Data() = delete;
            };
            static_assert(sizeof(NFCError_Data) == 16,
                "Bad sizeof(NFCError_Data)");
            class NFCRecord_Data {
            public:
                static NFCRecord_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFCRecord_Data))) NFCRecord_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                int32_t record_type;
                uint8_t pad0_[4];
                mojo::internal::Pointer<mojo::internal::String_Data> media_type;
                mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> data;

            private:
                NFCRecord_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFCRecord_Data() = delete;
            };
            static_assert(sizeof(NFCRecord_Data) == 32,
                "Bad sizeof(NFCRecord_Data)");
            class NFCMessage_Data {
            public:
                static NFCMessage_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFCMessage_Data))) NFCMessage_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::NFCRecord_Data>>> data;
                mojo::internal::Pointer<mojo::internal::String_Data> url;

            private:
                NFCMessage_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFCMessage_Data() = delete;
            };
            static_assert(sizeof(NFCMessage_Data) == 24,
                "Bad sizeof(NFCMessage_Data)");
            class NFCPushOptions_Data {
            public:
                static NFCPushOptions_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFCPushOptions_Data))) NFCPushOptions_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                int32_t target;
                uint8_t ignore_read : 1;
                uint8_t pad1_[3];
                double timeout;

            private:
                NFCPushOptions_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFCPushOptions_Data() = delete;
            };
            static_assert(sizeof(NFCPushOptions_Data) == 24,
                "Bad sizeof(NFCPushOptions_Data)");
            class NFCRecordTypeFilter_Data {
            public:
                static NFCRecordTypeFilter_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFCRecordTypeFilter_Data))) NFCRecordTypeFilter_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                int32_t record_type;
                uint8_t padfinal_[4];

            private:
                NFCRecordTypeFilter_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFCRecordTypeFilter_Data() = delete;
            };
            static_assert(sizeof(NFCRecordTypeFilter_Data) == 16,
                "Bad sizeof(NFCRecordTypeFilter_Data)");
            class NFCWatchOptions_Data {
            public:
                static NFCWatchOptions_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFCWatchOptions_Data))) NFCWatchOptions_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                mojo::internal::Pointer<mojo::internal::String_Data> url;
                mojo::internal::Pointer<internal::NFCRecordTypeFilter_Data> record_filter;
                mojo::internal::Pointer<mojo::internal::String_Data> media_type;
                int32_t mode;
                uint8_t padfinal_[4];

            private:
                NFCWatchOptions_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFCWatchOptions_Data() = delete;
            };
            static_assert(sizeof(NFCWatchOptions_Data) == 40,
                "Bad sizeof(NFCWatchOptions_Data)");
            constexpr uint32_t kNFC_SetClient_Name = 0;
            class NFC_SetClient_Params_Data {
            public:
                static NFC_SetClient_Params_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFC_SetClient_Params_Data))) NFC_SetClient_Params_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                mojo::internal::Interface_Data client;

            private:
                NFC_SetClient_Params_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFC_SetClient_Params_Data() = delete;
            };
            static_assert(sizeof(NFC_SetClient_Params_Data) == 16,
                "Bad sizeof(NFC_SetClient_Params_Data)");
            constexpr uint32_t kNFC_Push_Name = 1;
            class NFC_Push_Params_Data {
            public:
                static NFC_Push_Params_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFC_Push_Params_Data))) NFC_Push_Params_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                mojo::internal::Pointer<internal::NFCMessage_Data> message;
                mojo::internal::Pointer<internal::NFCPushOptions_Data> options;

            private:
                NFC_Push_Params_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFC_Push_Params_Data() = delete;
            };
            static_assert(sizeof(NFC_Push_Params_Data) == 24,
                "Bad sizeof(NFC_Push_Params_Data)");
            class NFC_Push_ResponseParams_Data {
            public:
                static NFC_Push_ResponseParams_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFC_Push_ResponseParams_Data))) NFC_Push_ResponseParams_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                mojo::internal::Pointer<internal::NFCError_Data> error;

            private:
                NFC_Push_ResponseParams_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFC_Push_ResponseParams_Data() = delete;
            };
            static_assert(sizeof(NFC_Push_ResponseParams_Data) == 16,
                "Bad sizeof(NFC_Push_ResponseParams_Data)");
            constexpr uint32_t kNFC_CancelPush_Name = 2;
            class NFC_CancelPush_Params_Data {
            public:
                static NFC_CancelPush_Params_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFC_CancelPush_Params_Data))) NFC_CancelPush_Params_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                int32_t target;
                uint8_t padfinal_[4];

            private:
                NFC_CancelPush_Params_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFC_CancelPush_Params_Data() = delete;
            };
            static_assert(sizeof(NFC_CancelPush_Params_Data) == 16,
                "Bad sizeof(NFC_CancelPush_Params_Data)");
            class NFC_CancelPush_ResponseParams_Data {
            public:
                static NFC_CancelPush_ResponseParams_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFC_CancelPush_ResponseParams_Data))) NFC_CancelPush_ResponseParams_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                mojo::internal::Pointer<internal::NFCError_Data> error;

            private:
                NFC_CancelPush_ResponseParams_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFC_CancelPush_ResponseParams_Data() = delete;
            };
            static_assert(sizeof(NFC_CancelPush_ResponseParams_Data) == 16,
                "Bad sizeof(NFC_CancelPush_ResponseParams_Data)");
            constexpr uint32_t kNFC_Watch_Name = 3;
            class NFC_Watch_Params_Data {
            public:
                static NFC_Watch_Params_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFC_Watch_Params_Data))) NFC_Watch_Params_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                mojo::internal::Pointer<internal::NFCWatchOptions_Data> options;

            private:
                NFC_Watch_Params_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFC_Watch_Params_Data() = delete;
            };
            static_assert(sizeof(NFC_Watch_Params_Data) == 16,
                "Bad sizeof(NFC_Watch_Params_Data)");
            class NFC_Watch_ResponseParams_Data {
            public:
                static NFC_Watch_ResponseParams_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFC_Watch_ResponseParams_Data))) NFC_Watch_ResponseParams_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                uint32_t id;
                uint8_t pad0_[4];
                mojo::internal::Pointer<internal::NFCError_Data> error;

            private:
                NFC_Watch_ResponseParams_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFC_Watch_ResponseParams_Data() = delete;
            };
            static_assert(sizeof(NFC_Watch_ResponseParams_Data) == 24,
                "Bad sizeof(NFC_Watch_ResponseParams_Data)");
            constexpr uint32_t kNFC_CancelWatch_Name = 4;
            class NFC_CancelWatch_Params_Data {
            public:
                static NFC_CancelWatch_Params_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFC_CancelWatch_Params_Data))) NFC_CancelWatch_Params_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                uint32_t id;
                uint8_t padfinal_[4];

            private:
                NFC_CancelWatch_Params_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFC_CancelWatch_Params_Data() = delete;
            };
            static_assert(sizeof(NFC_CancelWatch_Params_Data) == 16,
                "Bad sizeof(NFC_CancelWatch_Params_Data)");
            class NFC_CancelWatch_ResponseParams_Data {
            public:
                static NFC_CancelWatch_ResponseParams_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFC_CancelWatch_ResponseParams_Data))) NFC_CancelWatch_ResponseParams_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                mojo::internal::Pointer<internal::NFCError_Data> error;

            private:
                NFC_CancelWatch_ResponseParams_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFC_CancelWatch_ResponseParams_Data() = delete;
            };
            static_assert(sizeof(NFC_CancelWatch_ResponseParams_Data) == 16,
                "Bad sizeof(NFC_CancelWatch_ResponseParams_Data)");
            constexpr uint32_t kNFC_CancelAllWatches_Name = 5;
            class NFC_CancelAllWatches_Params_Data {
            public:
                static NFC_CancelAllWatches_Params_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFC_CancelAllWatches_Params_Data))) NFC_CancelAllWatches_Params_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;

            private:
                NFC_CancelAllWatches_Params_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFC_CancelAllWatches_Params_Data() = delete;
            };
            static_assert(sizeof(NFC_CancelAllWatches_Params_Data) == 8,
                "Bad sizeof(NFC_CancelAllWatches_Params_Data)");
            class NFC_CancelAllWatches_ResponseParams_Data {
            public:
                static NFC_CancelAllWatches_ResponseParams_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFC_CancelAllWatches_ResponseParams_Data))) NFC_CancelAllWatches_ResponseParams_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                mojo::internal::Pointer<internal::NFCError_Data> error;

            private:
                NFC_CancelAllWatches_ResponseParams_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFC_CancelAllWatches_ResponseParams_Data() = delete;
            };
            static_assert(sizeof(NFC_CancelAllWatches_ResponseParams_Data) == 16,
                "Bad sizeof(NFC_CancelAllWatches_ResponseParams_Data)");
            constexpr uint32_t kNFC_SuspendNFCOperations_Name = 6;
            class NFC_SuspendNFCOperations_Params_Data {
            public:
                static NFC_SuspendNFCOperations_Params_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFC_SuspendNFCOperations_Params_Data))) NFC_SuspendNFCOperations_Params_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;

            private:
                NFC_SuspendNFCOperations_Params_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFC_SuspendNFCOperations_Params_Data() = delete;
            };
            static_assert(sizeof(NFC_SuspendNFCOperations_Params_Data) == 8,
                "Bad sizeof(NFC_SuspendNFCOperations_Params_Data)");
            constexpr uint32_t kNFC_ResumeNFCOperations_Name = 7;
            class NFC_ResumeNFCOperations_Params_Data {
            public:
                static NFC_ResumeNFCOperations_Params_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFC_ResumeNFCOperations_Params_Data))) NFC_ResumeNFCOperations_Params_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;

            private:
                NFC_ResumeNFCOperations_Params_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFC_ResumeNFCOperations_Params_Data() = delete;
            };
            static_assert(sizeof(NFC_ResumeNFCOperations_Params_Data) == 8,
                "Bad sizeof(NFC_ResumeNFCOperations_Params_Data)");
            constexpr uint32_t kNFCClient_OnWatch_Name = 0;
            class NFCClient_OnWatch_Params_Data {
            public:
                static NFCClient_OnWatch_Params_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NFCClient_OnWatch_Params_Data))) NFCClient_OnWatch_Params_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                mojo::internal::Pointer<mojo::internal::Array_Data<uint32_t>> watch_ids;
                mojo::internal::Pointer<internal::NFCMessage_Data> message;

            private:
                NFCClient_OnWatch_Params_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NFCClient_OnWatch_Params_Data() = delete;
            };
            static_assert(sizeof(NFCClient_OnWatch_Params_Data) == 24,
                "Bad sizeof(NFCClient_OnWatch_Params_Data)");

#pragma pack(pop)

        } // namespace internal
    } // namespace mojom
} // namespace nfc
} // namespace device

#endif // DEVICE_NFC_NFC_MOJOM_SHARED_INTERNAL_H_