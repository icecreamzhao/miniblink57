// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_REMOTING_MOJOM_SHARED_INTERNAL_H_
#define MEDIA_MOJO_INTERFACES_REMOTING_MOJOM_SHARED_INTERNAL_H_

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
namespace media {
namespace mojom {
    namespace internal {

        struct RemotingStopReason_Data {
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

        struct RemotingSinkCapabilities_Data {
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

        struct RemotingStartFailReason_Data {
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
        constexpr uint32_t kRemoterFactory_Create_Name = 0;
        class RemoterFactory_Create_Params_Data {
        public:
            static RemoterFactory_Create_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RemoterFactory_Create_Params_Data))) RemoterFactory_Create_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data source;
            mojo::internal::Handle_Data remoter;
            uint8_t padfinal_[4];

        private:
            RemoterFactory_Create_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RemoterFactory_Create_Params_Data() = delete;
        };
        static_assert(sizeof(RemoterFactory_Create_Params_Data) == 24,
            "Bad sizeof(RemoterFactory_Create_Params_Data)");
        constexpr uint32_t kRemotingDataStreamSender_ConsumeDataChunk_Name = 0;
        class RemotingDataStreamSender_ConsumeDataChunk_Params_Data {
        public:
            static RemotingDataStreamSender_ConsumeDataChunk_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RemotingDataStreamSender_ConsumeDataChunk_Params_Data))) RemotingDataStreamSender_ConsumeDataChunk_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t offset;
            uint32_t size;
            uint32_t total_payload_size;
            uint8_t padfinal_[4];

        private:
            RemotingDataStreamSender_ConsumeDataChunk_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RemotingDataStreamSender_ConsumeDataChunk_Params_Data() = delete;
        };
        static_assert(sizeof(RemotingDataStreamSender_ConsumeDataChunk_Params_Data) == 24,
            "Bad sizeof(RemotingDataStreamSender_ConsumeDataChunk_Params_Data)");
        constexpr uint32_t kRemotingDataStreamSender_SendFrame_Name = 1;
        class RemotingDataStreamSender_SendFrame_Params_Data {
        public:
            static RemotingDataStreamSender_SendFrame_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RemotingDataStreamSender_SendFrame_Params_Data))) RemotingDataStreamSender_SendFrame_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            RemotingDataStreamSender_SendFrame_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RemotingDataStreamSender_SendFrame_Params_Data() = delete;
        };
        static_assert(sizeof(RemotingDataStreamSender_SendFrame_Params_Data) == 8,
            "Bad sizeof(RemotingDataStreamSender_SendFrame_Params_Data)");
        constexpr uint32_t kRemotingDataStreamSender_CancelInFlightData_Name = 2;
        class RemotingDataStreamSender_CancelInFlightData_Params_Data {
        public:
            static RemotingDataStreamSender_CancelInFlightData_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RemotingDataStreamSender_CancelInFlightData_Params_Data))) RemotingDataStreamSender_CancelInFlightData_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            RemotingDataStreamSender_CancelInFlightData_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RemotingDataStreamSender_CancelInFlightData_Params_Data() = delete;
        };
        static_assert(sizeof(RemotingDataStreamSender_CancelInFlightData_Params_Data) == 8,
            "Bad sizeof(RemotingDataStreamSender_CancelInFlightData_Params_Data)");
        constexpr uint32_t kRemoter_Start_Name = 0;
        class Remoter_Start_Params_Data {
        public:
            static Remoter_Start_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Remoter_Start_Params_Data))) Remoter_Start_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Remoter_Start_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Remoter_Start_Params_Data() = delete;
        };
        static_assert(sizeof(Remoter_Start_Params_Data) == 8,
            "Bad sizeof(Remoter_Start_Params_Data)");
        constexpr uint32_t kRemoter_StartDataStreams_Name = 1;
        class Remoter_StartDataStreams_Params_Data {
        public:
            static Remoter_StartDataStreams_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Remoter_StartDataStreams_Params_Data))) Remoter_StartDataStreams_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data audio_pipe;
            mojo::internal::Handle_Data video_pipe;
            mojo::internal::Handle_Data audio_sender;
            mojo::internal::Handle_Data video_sender;

        private:
            Remoter_StartDataStreams_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Remoter_StartDataStreams_Params_Data() = delete;
        };
        static_assert(sizeof(Remoter_StartDataStreams_Params_Data) == 24,
            "Bad sizeof(Remoter_StartDataStreams_Params_Data)");
        constexpr uint32_t kRemoter_Stop_Name = 2;
        class Remoter_Stop_Params_Data {
        public:
            static Remoter_Stop_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Remoter_Stop_Params_Data))) Remoter_Stop_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t reason;
            uint8_t padfinal_[4];

        private:
            Remoter_Stop_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Remoter_Stop_Params_Data() = delete;
        };
        static_assert(sizeof(Remoter_Stop_Params_Data) == 16,
            "Bad sizeof(Remoter_Stop_Params_Data)");
        constexpr uint32_t kRemoter_SendMessageToSink_Name = 3;
        class Remoter_SendMessageToSink_Params_Data {
        public:
            static Remoter_SendMessageToSink_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Remoter_SendMessageToSink_Params_Data))) Remoter_SendMessageToSink_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> message;

        private:
            Remoter_SendMessageToSink_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Remoter_SendMessageToSink_Params_Data() = delete;
        };
        static_assert(sizeof(Remoter_SendMessageToSink_Params_Data) == 16,
            "Bad sizeof(Remoter_SendMessageToSink_Params_Data)");
        constexpr uint32_t kRemotingSource_OnSinkAvailable_Name = 0;
        class RemotingSource_OnSinkAvailable_Params_Data {
        public:
            static RemotingSource_OnSinkAvailable_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RemotingSource_OnSinkAvailable_Params_Data))) RemotingSource_OnSinkAvailable_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t capabilities;
            uint8_t padfinal_[4];

        private:
            RemotingSource_OnSinkAvailable_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RemotingSource_OnSinkAvailable_Params_Data() = delete;
        };
        static_assert(sizeof(RemotingSource_OnSinkAvailable_Params_Data) == 16,
            "Bad sizeof(RemotingSource_OnSinkAvailable_Params_Data)");
        constexpr uint32_t kRemotingSource_OnSinkGone_Name = 1;
        class RemotingSource_OnSinkGone_Params_Data {
        public:
            static RemotingSource_OnSinkGone_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RemotingSource_OnSinkGone_Params_Data))) RemotingSource_OnSinkGone_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            RemotingSource_OnSinkGone_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RemotingSource_OnSinkGone_Params_Data() = delete;
        };
        static_assert(sizeof(RemotingSource_OnSinkGone_Params_Data) == 8,
            "Bad sizeof(RemotingSource_OnSinkGone_Params_Data)");
        constexpr uint32_t kRemotingSource_OnStarted_Name = 2;
        class RemotingSource_OnStarted_Params_Data {
        public:
            static RemotingSource_OnStarted_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RemotingSource_OnStarted_Params_Data))) RemotingSource_OnStarted_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            RemotingSource_OnStarted_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RemotingSource_OnStarted_Params_Data() = delete;
        };
        static_assert(sizeof(RemotingSource_OnStarted_Params_Data) == 8,
            "Bad sizeof(RemotingSource_OnStarted_Params_Data)");
        constexpr uint32_t kRemotingSource_OnStartFailed_Name = 3;
        class RemotingSource_OnStartFailed_Params_Data {
        public:
            static RemotingSource_OnStartFailed_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RemotingSource_OnStartFailed_Params_Data))) RemotingSource_OnStartFailed_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t reason;
            uint8_t padfinal_[4];

        private:
            RemotingSource_OnStartFailed_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RemotingSource_OnStartFailed_Params_Data() = delete;
        };
        static_assert(sizeof(RemotingSource_OnStartFailed_Params_Data) == 16,
            "Bad sizeof(RemotingSource_OnStartFailed_Params_Data)");
        constexpr uint32_t kRemotingSource_OnMessageFromSink_Name = 4;
        class RemotingSource_OnMessageFromSink_Params_Data {
        public:
            static RemotingSource_OnMessageFromSink_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RemotingSource_OnMessageFromSink_Params_Data))) RemotingSource_OnMessageFromSink_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> message;

        private:
            RemotingSource_OnMessageFromSink_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RemotingSource_OnMessageFromSink_Params_Data() = delete;
        };
        static_assert(sizeof(RemotingSource_OnMessageFromSink_Params_Data) == 16,
            "Bad sizeof(RemotingSource_OnMessageFromSink_Params_Data)");
        constexpr uint32_t kRemotingSource_OnStopped_Name = 5;
        class RemotingSource_OnStopped_Params_Data {
        public:
            static RemotingSource_OnStopped_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RemotingSource_OnStopped_Params_Data))) RemotingSource_OnStopped_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t reason;
            uint8_t padfinal_[4];

        private:
            RemotingSource_OnStopped_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RemotingSource_OnStopped_Params_Data() = delete;
        };
        static_assert(sizeof(RemotingSource_OnStopped_Params_Data) == 16,
            "Bad sizeof(RemotingSource_OnStopped_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_REMOTING_MOJOM_SHARED_INTERNAL_H_