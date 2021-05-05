// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_RECEIVER_MOJOM_SHARED_H_
#define SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_RECEIVER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/mojo/interfaces/media_types.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/video_capture/public/interfaces/receiver.mojom-shared-internal.h"

namespace video_capture {
namespace mojom {

} // namespace mojom
} // namespace video_capture

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace video_capture {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class ReceiverInterfaceBase {
    };

    using ReceiverPtrDataView = mojo::InterfacePtrDataView<ReceiverInterfaceBase>;
    using ReceiverRequestDataView = mojo::InterfaceRequestDataView<ReceiverInterfaceBase>;
    using ReceiverAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ReceiverInterfaceBase>;
    using ReceiverAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ReceiverInterfaceBase>;
    class Receiver_OnIncomingCapturedVideoFrame_ParamsDataView {
    public:
        Receiver_OnIncomingCapturedVideoFrame_ParamsDataView() { }

        Receiver_OnIncomingCapturedVideoFrame_ParamsDataView(
            internal::Receiver_OnIncomingCapturedVideoFrame_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFrameDataView(
            ::media::mojom::VideoFrameDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFrame(UserType* output)
        {
            auto* pointer = data_->frame.Get();
            return mojo::internal::Deserialize<::media::mojom::VideoFrameDataView>(
                pointer, output, context_);
        }

    private:
        internal::Receiver_OnIncomingCapturedVideoFrame_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Receiver_OnError_ParamsDataView {
    public:
        Receiver_OnError_ParamsDataView() { }

        Receiver_OnError_ParamsDataView(
            internal::Receiver_OnError_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Receiver_OnError_Params_Data* data_ = nullptr;
    };

    class Receiver_OnLog_ParamsDataView {
    public:
        Receiver_OnLog_ParamsDataView() { }

        Receiver_OnLog_ParamsDataView(
            internal::Receiver_OnLog_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetMessageDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMessage(UserType* output)
        {
            auto* pointer = data_->message.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Receiver_OnLog_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Receiver_OnBufferDestroyed_ParamsDataView {
    public:
        Receiver_OnBufferDestroyed_ParamsDataView() { }

        Receiver_OnBufferDestroyed_ParamsDataView(
            internal::Receiver_OnBufferDestroyed_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t buffer_id_to_drop() const
        {
            return data_->buffer_id_to_drop;
        }

    private:
        internal::Receiver_OnBufferDestroyed_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace video_capture

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace video_capture {
namespace mojom {

    inline void Receiver_OnIncomingCapturedVideoFrame_ParamsDataView::GetFrameDataView(
        ::media::mojom::VideoFrameDataView* output)
    {
        auto pointer = data_->frame.Get();
        *output = ::media::mojom::VideoFrameDataView(pointer, context_);
    }

    inline void Receiver_OnLog_ParamsDataView::GetMessageDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->message.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace video_capture

#endif // SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_RECEIVER_MOJOM_SHARED_H_
