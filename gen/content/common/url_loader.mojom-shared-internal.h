// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_URL_LOADER_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_URL_LOADER_MOJOM_SHARED_INTERNAL_H_

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
namespace content {
namespace mojom {
    namespace internal {
        using URLRequest_Data = mojo::internal::NativeStruct_Data;
        using URLResponseHead_Data = mojo::internal::NativeStruct_Data;
        using URLRequestRedirectInfo_Data = mojo::internal::NativeStruct_Data;
        using URLLoaderStatus_Data = mojo::internal::NativeStruct_Data;

#pragma pack(push, 1)
        constexpr uint32_t kURLLoader_FollowRedirect_Name = 0;
        class URLLoader_FollowRedirect_Params_Data {
        public:
            static URLLoader_FollowRedirect_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(URLLoader_FollowRedirect_Params_Data))) URLLoader_FollowRedirect_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            URLLoader_FollowRedirect_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~URLLoader_FollowRedirect_Params_Data() = delete;
        };
        static_assert(sizeof(URLLoader_FollowRedirect_Params_Data) == 8,
            "Bad sizeof(URLLoader_FollowRedirect_Params_Data)");
        constexpr uint32_t kURLLoaderClient_OnReceiveResponse_Name = 0;
        class URLLoaderClient_OnReceiveResponse_Params_Data {
        public:
            static URLLoaderClient_OnReceiveResponse_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(URLLoaderClient_OnReceiveResponse_Params_Data))) URLLoaderClient_OnReceiveResponse_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::URLResponseHead_Data> head;
            mojo::internal::Interface_Data downloaded_file;

        private:
            URLLoaderClient_OnReceiveResponse_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~URLLoaderClient_OnReceiveResponse_Params_Data() = delete;
        };
        static_assert(sizeof(URLLoaderClient_OnReceiveResponse_Params_Data) == 24,
            "Bad sizeof(URLLoaderClient_OnReceiveResponse_Params_Data)");
        constexpr uint32_t kURLLoaderClient_OnReceiveRedirect_Name = 1;
        class URLLoaderClient_OnReceiveRedirect_Params_Data {
        public:
            static URLLoaderClient_OnReceiveRedirect_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(URLLoaderClient_OnReceiveRedirect_Params_Data))) URLLoaderClient_OnReceiveRedirect_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::URLRequestRedirectInfo_Data> redirect_info;
            mojo::internal::Pointer<internal::URLResponseHead_Data> head;

        private:
            URLLoaderClient_OnReceiveRedirect_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~URLLoaderClient_OnReceiveRedirect_Params_Data() = delete;
        };
        static_assert(sizeof(URLLoaderClient_OnReceiveRedirect_Params_Data) == 24,
            "Bad sizeof(URLLoaderClient_OnReceiveRedirect_Params_Data)");
        constexpr uint32_t kURLLoaderClient_OnDataDownloaded_Name = 2;
        class URLLoaderClient_OnDataDownloaded_Params_Data {
        public:
            static URLLoaderClient_OnDataDownloaded_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(URLLoaderClient_OnDataDownloaded_Params_Data))) URLLoaderClient_OnDataDownloaded_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t data_length;
            int64_t encoded_length;

        private:
            URLLoaderClient_OnDataDownloaded_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~URLLoaderClient_OnDataDownloaded_Params_Data() = delete;
        };
        static_assert(sizeof(URLLoaderClient_OnDataDownloaded_Params_Data) == 24,
            "Bad sizeof(URLLoaderClient_OnDataDownloaded_Params_Data)");
        constexpr uint32_t kURLLoaderClient_OnReceiveCachedMetadata_Name = 3;
        class URLLoaderClient_OnReceiveCachedMetadata_Params_Data {
        public:
            static URLLoaderClient_OnReceiveCachedMetadata_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(URLLoaderClient_OnReceiveCachedMetadata_Params_Data))) URLLoaderClient_OnReceiveCachedMetadata_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> data;

        private:
            URLLoaderClient_OnReceiveCachedMetadata_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~URLLoaderClient_OnReceiveCachedMetadata_Params_Data() = delete;
        };
        static_assert(sizeof(URLLoaderClient_OnReceiveCachedMetadata_Params_Data) == 16,
            "Bad sizeof(URLLoaderClient_OnReceiveCachedMetadata_Params_Data)");
        constexpr uint32_t kURLLoaderClient_OnTransferSizeUpdated_Name = 4;
        class URLLoaderClient_OnTransferSizeUpdated_Params_Data {
        public:
            static URLLoaderClient_OnTransferSizeUpdated_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(URLLoaderClient_OnTransferSizeUpdated_Params_Data))) URLLoaderClient_OnTransferSizeUpdated_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t transfer_size_diff;
            uint8_t padfinal_[4];

        private:
            URLLoaderClient_OnTransferSizeUpdated_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~URLLoaderClient_OnTransferSizeUpdated_Params_Data() = delete;
        };
        static_assert(sizeof(URLLoaderClient_OnTransferSizeUpdated_Params_Data) == 16,
            "Bad sizeof(URLLoaderClient_OnTransferSizeUpdated_Params_Data)");
        constexpr uint32_t kURLLoaderClient_OnStartLoadingResponseBody_Name = 5;
        class URLLoaderClient_OnStartLoadingResponseBody_Params_Data {
        public:
            static URLLoaderClient_OnStartLoadingResponseBody_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(URLLoaderClient_OnStartLoadingResponseBody_Params_Data))) URLLoaderClient_OnStartLoadingResponseBody_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data body;
            uint8_t padfinal_[4];

        private:
            URLLoaderClient_OnStartLoadingResponseBody_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~URLLoaderClient_OnStartLoadingResponseBody_Params_Data() = delete;
        };
        static_assert(sizeof(URLLoaderClient_OnStartLoadingResponseBody_Params_Data) == 16,
            "Bad sizeof(URLLoaderClient_OnStartLoadingResponseBody_Params_Data)");
        constexpr uint32_t kURLLoaderClient_OnComplete_Name = 6;
        class URLLoaderClient_OnComplete_Params_Data {
        public:
            static URLLoaderClient_OnComplete_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(URLLoaderClient_OnComplete_Params_Data))) URLLoaderClient_OnComplete_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::URLLoaderStatus_Data> completion_status;

        private:
            URLLoaderClient_OnComplete_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~URLLoaderClient_OnComplete_Params_Data() = delete;
        };
        static_assert(sizeof(URLLoaderClient_OnComplete_Params_Data) == 16,
            "Bad sizeof(URLLoaderClient_OnComplete_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_URL_LOADER_MOJOM_SHARED_INTERNAL_H_