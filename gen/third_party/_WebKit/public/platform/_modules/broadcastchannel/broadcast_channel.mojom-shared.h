// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BROADCASTCHANNEL_BROADCAST_CHANNEL_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BROADCASTCHANNEL_BROADCAST_CHANNEL_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "third_party/WebKit/public/platform/modules/broadcastchannel/broadcast_channel.mojom-shared-internal.h"
#include "url/mojo/origin.mojom-shared.h"

namespace blink {
namespace mojom {

} // namespace mojom
} // namespace blink

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace blink {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class BroadcastChannelClientInterfaceBase {
    };

    using BroadcastChannelClientPtrDataView = mojo::InterfacePtrDataView<BroadcastChannelClientInterfaceBase>;
    using BroadcastChannelClientRequestDataView = mojo::InterfaceRequestDataView<BroadcastChannelClientInterfaceBase>;
    using BroadcastChannelClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<BroadcastChannelClientInterfaceBase>;
    using BroadcastChannelClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<BroadcastChannelClientInterfaceBase>;
    class BroadcastChannelProviderInterfaceBase {
    };

    using BroadcastChannelProviderPtrDataView = mojo::InterfacePtrDataView<BroadcastChannelProviderInterfaceBase>;
    using BroadcastChannelProviderRequestDataView = mojo::InterfaceRequestDataView<BroadcastChannelProviderInterfaceBase>;
    using BroadcastChannelProviderAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<BroadcastChannelProviderInterfaceBase>;
    using BroadcastChannelProviderAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<BroadcastChannelProviderInterfaceBase>;
    class BroadcastChannelClient_OnMessage_ParamsDataView {
    public:
        BroadcastChannelClient_OnMessage_ParamsDataView() { }

        BroadcastChannelClient_OnMessage_ParamsDataView(
            internal::BroadcastChannelClient_OnMessage_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetMessageDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMessage(UserType* output)
        {
            auto* pointer = data_->message.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::BroadcastChannelClient_OnMessage_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class BroadcastChannelProvider_ConnectToChannel_ParamsDataView {
    public:
        BroadcastChannelProvider_ConnectToChannel_ParamsDataView() { }

        BroadcastChannelProvider_ConnectToChannel_ParamsDataView(
            internal::BroadcastChannelProvider_ConnectToChannel_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetOriginDataView(
            ::url::mojom::OriginDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrigin(UserType* output)
        {
            auto* pointer = data_->origin.Get();
            return mojo::internal::Deserialize<::url::mojom::OriginDataView>(
                pointer, output, context_);
        }
        inline void GetNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeReceiver()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::blink::mojom::BroadcastChannelClientAssociatedPtrInfoDataView>(
                &data_->receiver, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeSender()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::blink::mojom::BroadcastChannelClientAssociatedRequestDataView>(
                &data_->sender, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::BroadcastChannelProvider_ConnectToChannel_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace blink {
namespace mojom {

    inline void BroadcastChannelClient_OnMessage_ParamsDataView::GetMessageDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->message.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void BroadcastChannelProvider_ConnectToChannel_ParamsDataView::GetOriginDataView(
        ::url::mojom::OriginDataView* output)
    {
        auto pointer = data_->origin.Get();
        *output = ::url::mojom::OriginDataView(pointer, context_);
    }
    inline void BroadcastChannelProvider_ConnectToChannel_ParamsDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BROADCASTCHANNEL_BROADCAST_CHANNEL_MOJOM_SHARED_H_
