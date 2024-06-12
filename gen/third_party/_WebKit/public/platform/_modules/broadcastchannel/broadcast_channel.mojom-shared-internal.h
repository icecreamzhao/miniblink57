// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BROADCASTCHANNEL_BROADCAST_CHANNEL_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BROADCASTCHANNEL_BROADCAST_CHANNEL_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "url/mojo/origin.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace blink {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kBroadcastChannelClient_OnMessage_Name = 0;
        class BroadcastChannelClient_OnMessage_Params_Data {
        public:
            static BroadcastChannelClient_OnMessage_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BroadcastChannelClient_OnMessage_Params_Data))) BroadcastChannelClient_OnMessage_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> message;

        private:
            BroadcastChannelClient_OnMessage_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BroadcastChannelClient_OnMessage_Params_Data() = delete;
        };
        static_assert(sizeof(BroadcastChannelClient_OnMessage_Params_Data) == 16,
            "Bad sizeof(BroadcastChannelClient_OnMessage_Params_Data)");
        constexpr uint32_t kBroadcastChannelProvider_ConnectToChannel_Name = 0;
        class BroadcastChannelProvider_ConnectToChannel_Params_Data {
        public:
            static BroadcastChannelProvider_ConnectToChannel_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BroadcastChannelProvider_ConnectToChannel_Params_Data))) BroadcastChannelProvider_ConnectToChannel_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Origin_Data> origin;
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::AssociatedInterface_Data receiver;
            mojo::internal::AssociatedInterfaceRequest_Data sender;
            uint8_t padfinal_[4];

        private:
            BroadcastChannelProvider_ConnectToChannel_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BroadcastChannelProvider_ConnectToChannel_Params_Data() = delete;
        };
        static_assert(sizeof(BroadcastChannelProvider_ConnectToChannel_Params_Data) == 40,
            "Bad sizeof(BroadcastChannelProvider_ConnectToChannel_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BROADCASTCHANNEL_BROADCAST_CHANNEL_MOJOM_SHARED_INTERNAL_H_