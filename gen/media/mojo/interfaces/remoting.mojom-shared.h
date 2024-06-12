// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_REMOTING_MOJOM_SHARED_H_
#define MEDIA_MOJO_INTERFACES_REMOTING_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/mojo/interfaces/remoting.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace media {
namespace mojom {

} // namespace mojom
} // namespace media

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace media {
namespace mojom {

    enum class RemotingStopReason : int32_t {
        ROUTE_TERMINATED,
        LOCAL_PLAYBACK,
        SOURCE_GONE,
        MESSAGE_SEND_FAILED,
        DATA_SEND_FAILED,
        UNEXPECTED_FAILURE,
    };

    inline std::ostream& operator<<(std::ostream& os, RemotingStopReason value)
    {
        switch (value) {
        case RemotingStopReason::ROUTE_TERMINATED:
            return os << "RemotingStopReason::ROUTE_TERMINATED";
        case RemotingStopReason::LOCAL_PLAYBACK:
            return os << "RemotingStopReason::LOCAL_PLAYBACK";
        case RemotingStopReason::SOURCE_GONE:
            return os << "RemotingStopReason::SOURCE_GONE";
        case RemotingStopReason::MESSAGE_SEND_FAILED:
            return os << "RemotingStopReason::MESSAGE_SEND_FAILED";
        case RemotingStopReason::DATA_SEND_FAILED:
            return os << "RemotingStopReason::DATA_SEND_FAILED";
        case RemotingStopReason::UNEXPECTED_FAILURE:
            return os << "RemotingStopReason::UNEXPECTED_FAILURE";
        default:
            return os << "Unknown RemotingStopReason value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(RemotingStopReason value)
    {
        return internal::RemotingStopReason_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class RemotingSinkCapabilities : int32_t {
        NONE,
        RENDERING_ONLY,
        CONTENT_DECRYPTION_AND_RENDERING,
    };

    inline std::ostream& operator<<(std::ostream& os, RemotingSinkCapabilities value)
    {
        switch (value) {
        case RemotingSinkCapabilities::NONE:
            return os << "RemotingSinkCapabilities::NONE";
        case RemotingSinkCapabilities::RENDERING_ONLY:
            return os << "RemotingSinkCapabilities::RENDERING_ONLY";
        case RemotingSinkCapabilities::CONTENT_DECRYPTION_AND_RENDERING:
            return os << "RemotingSinkCapabilities::CONTENT_DECRYPTION_AND_RENDERING";
        default:
            return os << "Unknown RemotingSinkCapabilities value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(RemotingSinkCapabilities value)
    {
        return internal::RemotingSinkCapabilities_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class RemotingStartFailReason : int32_t {
        CANNOT_START_MULTIPLE,
        ROUTE_TERMINATED,
    };

    inline std::ostream& operator<<(std::ostream& os, RemotingStartFailReason value)
    {
        switch (value) {
        case RemotingStartFailReason::CANNOT_START_MULTIPLE:
            return os << "RemotingStartFailReason::CANNOT_START_MULTIPLE";
        case RemotingStartFailReason::ROUTE_TERMINATED:
            return os << "RemotingStartFailReason::ROUTE_TERMINATED";
        default:
            return os << "Unknown RemotingStartFailReason value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(RemotingStartFailReason value)
    {
        return internal::RemotingStartFailReason_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class RemoterFactoryInterfaceBase {
    };

    using RemoterFactoryPtrDataView = mojo::InterfacePtrDataView<RemoterFactoryInterfaceBase>;
    using RemoterFactoryRequestDataView = mojo::InterfaceRequestDataView<RemoterFactoryInterfaceBase>;
    using RemoterFactoryAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<RemoterFactoryInterfaceBase>;
    using RemoterFactoryAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<RemoterFactoryInterfaceBase>;
    class RemotingDataStreamSenderInterfaceBase {
    };

    using RemotingDataStreamSenderPtrDataView = mojo::InterfacePtrDataView<RemotingDataStreamSenderInterfaceBase>;
    using RemotingDataStreamSenderRequestDataView = mojo::InterfaceRequestDataView<RemotingDataStreamSenderInterfaceBase>;
    using RemotingDataStreamSenderAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<RemotingDataStreamSenderInterfaceBase>;
    using RemotingDataStreamSenderAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<RemotingDataStreamSenderInterfaceBase>;
    class RemoterInterfaceBase {
    };

    using RemoterPtrDataView = mojo::InterfacePtrDataView<RemoterInterfaceBase>;
    using RemoterRequestDataView = mojo::InterfaceRequestDataView<RemoterInterfaceBase>;
    using RemoterAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<RemoterInterfaceBase>;
    using RemoterAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<RemoterInterfaceBase>;
    class RemotingSourceInterfaceBase {
    };

    using RemotingSourcePtrDataView = mojo::InterfacePtrDataView<RemotingSourceInterfaceBase>;
    using RemotingSourceRequestDataView = mojo::InterfaceRequestDataView<RemotingSourceInterfaceBase>;
    using RemotingSourceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<RemotingSourceInterfaceBase>;
    using RemotingSourceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<RemotingSourceInterfaceBase>;
    class RemoterFactory_Create_ParamsDataView {
    public:
        RemoterFactory_Create_ParamsDataView() { }

        RemoterFactory_Create_ParamsDataView(
            internal::RemoterFactory_Create_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeSource()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::media::mojom::RemotingSourcePtrDataView>(
                &data_->source, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeRemoter()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::media::mojom::RemoterRequestDataView>(
                &data_->remoter, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::RemoterFactory_Create_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RemotingDataStreamSender_ConsumeDataChunk_ParamsDataView {
    public:
        RemotingDataStreamSender_ConsumeDataChunk_ParamsDataView() { }

        RemotingDataStreamSender_ConsumeDataChunk_ParamsDataView(
            internal::RemotingDataStreamSender_ConsumeDataChunk_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t offset() const
        {
            return data_->offset;
        }
        uint32_t size() const
        {
            return data_->size;
        }
        uint32_t total_payload_size() const
        {
            return data_->total_payload_size;
        }

    private:
        internal::RemotingDataStreamSender_ConsumeDataChunk_Params_Data* data_ = nullptr;
    };

    class RemotingDataStreamSender_SendFrame_ParamsDataView {
    public:
        RemotingDataStreamSender_SendFrame_ParamsDataView() { }

        RemotingDataStreamSender_SendFrame_ParamsDataView(
            internal::RemotingDataStreamSender_SendFrame_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::RemotingDataStreamSender_SendFrame_Params_Data* data_ = nullptr;
    };

    class RemotingDataStreamSender_CancelInFlightData_ParamsDataView {
    public:
        RemotingDataStreamSender_CancelInFlightData_ParamsDataView() { }

        RemotingDataStreamSender_CancelInFlightData_ParamsDataView(
            internal::RemotingDataStreamSender_CancelInFlightData_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::RemotingDataStreamSender_CancelInFlightData_Params_Data* data_ = nullptr;
    };

    class Remoter_Start_ParamsDataView {
    public:
        Remoter_Start_ParamsDataView() { }

        Remoter_Start_ParamsDataView(
            internal::Remoter_Start_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Remoter_Start_Params_Data* data_ = nullptr;
    };

    class Remoter_StartDataStreams_ParamsDataView {
    public:
        Remoter_StartDataStreams_ParamsDataView() { }

        Remoter_StartDataStreams_ParamsDataView(
            internal::Remoter_StartDataStreams_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        mojo::ScopedDataPipeConsumerHandle TakeAudioPipe()
        {
            mojo::ScopedDataPipeConsumerHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedDataPipeConsumerHandle>(
                &data_->audio_pipe, &result, context_);
            DCHECK(ret);
            return result;
        }
        mojo::ScopedDataPipeConsumerHandle TakeVideoPipe()
        {
            mojo::ScopedDataPipeConsumerHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedDataPipeConsumerHandle>(
                &data_->video_pipe, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeAudioSender()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::media::mojom::RemotingDataStreamSenderRequestDataView>(
                &data_->audio_sender, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeVideoSender()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::media::mojom::RemotingDataStreamSenderRequestDataView>(
                &data_->video_sender, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::Remoter_StartDataStreams_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Remoter_Stop_ParamsDataView {
    public:
        Remoter_Stop_ParamsDataView() { }

        Remoter_Stop_ParamsDataView(
            internal::Remoter_Stop_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReason(UserType* output) const
        {
            auto data_value = data_->reason;
            return mojo::internal::Deserialize<::media::mojom::RemotingStopReason>(
                data_value, output);
        }

        RemotingStopReason reason() const
        {
            return static_cast<RemotingStopReason>(data_->reason);
        }

    private:
        internal::Remoter_Stop_Params_Data* data_ = nullptr;
    };

    class Remoter_SendMessageToSink_ParamsDataView {
    public:
        Remoter_SendMessageToSink_ParamsDataView() { }

        Remoter_SendMessageToSink_ParamsDataView(
            internal::Remoter_SendMessageToSink_Params_Data* data,
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
        internal::Remoter_SendMessageToSink_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RemotingSource_OnSinkAvailable_ParamsDataView {
    public:
        RemotingSource_OnSinkAvailable_ParamsDataView() { }

        RemotingSource_OnSinkAvailable_ParamsDataView(
            internal::RemotingSource_OnSinkAvailable_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCapabilities(UserType* output) const
        {
            auto data_value = data_->capabilities;
            return mojo::internal::Deserialize<::media::mojom::RemotingSinkCapabilities>(
                data_value, output);
        }

        RemotingSinkCapabilities capabilities() const
        {
            return static_cast<RemotingSinkCapabilities>(data_->capabilities);
        }

    private:
        internal::RemotingSource_OnSinkAvailable_Params_Data* data_ = nullptr;
    };

    class RemotingSource_OnSinkGone_ParamsDataView {
    public:
        RemotingSource_OnSinkGone_ParamsDataView() { }

        RemotingSource_OnSinkGone_ParamsDataView(
            internal::RemotingSource_OnSinkGone_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::RemotingSource_OnSinkGone_Params_Data* data_ = nullptr;
    };

    class RemotingSource_OnStarted_ParamsDataView {
    public:
        RemotingSource_OnStarted_ParamsDataView() { }

        RemotingSource_OnStarted_ParamsDataView(
            internal::RemotingSource_OnStarted_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::RemotingSource_OnStarted_Params_Data* data_ = nullptr;
    };

    class RemotingSource_OnStartFailed_ParamsDataView {
    public:
        RemotingSource_OnStartFailed_ParamsDataView() { }

        RemotingSource_OnStartFailed_ParamsDataView(
            internal::RemotingSource_OnStartFailed_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReason(UserType* output) const
        {
            auto data_value = data_->reason;
            return mojo::internal::Deserialize<::media::mojom::RemotingStartFailReason>(
                data_value, output);
        }

        RemotingStartFailReason reason() const
        {
            return static_cast<RemotingStartFailReason>(data_->reason);
        }

    private:
        internal::RemotingSource_OnStartFailed_Params_Data* data_ = nullptr;
    };

    class RemotingSource_OnMessageFromSink_ParamsDataView {
    public:
        RemotingSource_OnMessageFromSink_ParamsDataView() { }

        RemotingSource_OnMessageFromSink_ParamsDataView(
            internal::RemotingSource_OnMessageFromSink_Params_Data* data,
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
        internal::RemotingSource_OnMessageFromSink_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RemotingSource_OnStopped_ParamsDataView {
    public:
        RemotingSource_OnStopped_ParamsDataView() { }

        RemotingSource_OnStopped_ParamsDataView(
            internal::RemotingSource_OnStopped_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReason(UserType* output) const
        {
            auto data_value = data_->reason;
            return mojo::internal::Deserialize<::media::mojom::RemotingStopReason>(
                data_value, output);
        }

        RemotingStopReason reason() const
        {
            return static_cast<RemotingStopReason>(data_->reason);
        }

    private:
        internal::RemotingSource_OnStopped_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace media

namespace std {

template <>
struct hash<::media::mojom::RemotingStopReason>
    : public mojo::internal::EnumHashImpl<::media::mojom::RemotingStopReason> {
};

template <>
struct hash<::media::mojom::RemotingSinkCapabilities>
    : public mojo::internal::EnumHashImpl<::media::mojom::RemotingSinkCapabilities> {
};

template <>
struct hash<::media::mojom::RemotingStartFailReason>
    : public mojo::internal::EnumHashImpl<::media::mojom::RemotingStartFailReason> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::media::mojom::RemotingStopReason, ::media::mojom::RemotingStopReason> {
    static ::media::mojom::RemotingStopReason ToMojom(::media::mojom::RemotingStopReason input) { return input; }
    static bool FromMojom(::media::mojom::RemotingStopReason input, ::media::mojom::RemotingStopReason* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::RemotingStopReason, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::media::mojom::RemotingStopReason, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::media::mojom::RemotingStopReason>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::media::mojom::RemotingSinkCapabilities, ::media::mojom::RemotingSinkCapabilities> {
    static ::media::mojom::RemotingSinkCapabilities ToMojom(::media::mojom::RemotingSinkCapabilities input) { return input; }
    static bool FromMojom(::media::mojom::RemotingSinkCapabilities input, ::media::mojom::RemotingSinkCapabilities* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::RemotingSinkCapabilities, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::media::mojom::RemotingSinkCapabilities, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::media::mojom::RemotingSinkCapabilities>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::media::mojom::RemotingStartFailReason, ::media::mojom::RemotingStartFailReason> {
    static ::media::mojom::RemotingStartFailReason ToMojom(::media::mojom::RemotingStartFailReason input) { return input; }
    static bool FromMojom(::media::mojom::RemotingStartFailReason input, ::media::mojom::RemotingStartFailReason* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::RemotingStartFailReason, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::media::mojom::RemotingStartFailReason, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::media::mojom::RemotingStartFailReason>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace media {
namespace mojom {

    inline void Remoter_SendMessageToSink_ParamsDataView::GetMessageDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->message.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void RemotingSource_OnMessageFromSink_ParamsDataView::GetMessageDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->message.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_REMOTING_MOJOM_SHARED_H_
