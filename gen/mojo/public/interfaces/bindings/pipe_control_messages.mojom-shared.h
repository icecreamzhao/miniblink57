// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_PUBLIC_INTERFACES_BINDINGS_PIPE_CONTROL_MESSAGES_MOJOM_SHARED_H_
#define MOJO_PUBLIC_INTERFACES_BINDINGS_PIPE_CONTROL_MESSAGES_MOJOM_SHARED_H_

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
#include "mojo/public/interfaces/bindings/pipe_control_messages.mojom-shared-internal.h"

namespace mojo {
namespace pipe_control {
    class RunOrClosePipeMessageParamsDataView;

    class PeerAssociatedEndpointClosedEventDataView;

    class AssociatedEndpointClosedBeforeSentEventDataView;

    class RunOrClosePipeInputDataView;

} // namespace pipe_control
} // namespace mojo

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::mojo::pipe_control::RunOrClosePipeMessageParamsDataView> {
        using Data = ::mojo::pipe_control::internal::RunOrClosePipeMessageParams_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::mojo::pipe_control::PeerAssociatedEndpointClosedEventDataView> {
        using Data = ::mojo::pipe_control::internal::PeerAssociatedEndpointClosedEvent_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEventDataView> {
        using Data = ::mojo::pipe_control::internal::AssociatedEndpointClosedBeforeSentEvent_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::mojo::pipe_control::RunOrClosePipeInputDataView> {
        using Data = ::mojo::pipe_control::internal::RunOrClosePipeInput_Data;
        using DataAsArrayElement = Data;
        static constexpr MojomTypeCategory category = MojomTypeCategory::UNION;
    };

} // namespace internal
} // namespace mojo

namespace mojo {
namespace pipe_control {
    class RunOrClosePipeMessageParamsDataView {
    public:
        RunOrClosePipeMessageParamsDataView() { }

        RunOrClosePipeMessageParamsDataView(
            internal::RunOrClosePipeMessageParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetInputDataView(
            RunOrClosePipeInputDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInput(UserType* output)
        {
            auto* pointer = &data_->input;
            return mojo::internal::Deserialize<::mojo::pipe_control::RunOrClosePipeInputDataView>(
                pointer, output, context_);
        }

    private:
        internal::RunOrClosePipeMessageParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PeerAssociatedEndpointClosedEventDataView {
    public:
        PeerAssociatedEndpointClosedEventDataView() { }

        PeerAssociatedEndpointClosedEventDataView(
            internal::PeerAssociatedEndpointClosedEvent_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t id() const
        {
            return data_->id;
        }

    private:
        internal::PeerAssociatedEndpointClosedEvent_Data* data_ = nullptr;
    };

    class AssociatedEndpointClosedBeforeSentEventDataView {
    public:
        AssociatedEndpointClosedBeforeSentEventDataView() { }

        AssociatedEndpointClosedBeforeSentEventDataView(
            internal::AssociatedEndpointClosedBeforeSentEvent_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t id() const
        {
            return data_->id;
        }

    private:
        internal::AssociatedEndpointClosedBeforeSentEvent_Data* data_ = nullptr;
    };

    class RunOrClosePipeInputDataView {
    public:
        using Tag = internal::RunOrClosePipeInput_Data::RunOrClosePipeInput_Tag;

        RunOrClosePipeInputDataView() { }

        RunOrClosePipeInputDataView(
            internal::RunOrClosePipeInput_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const
        {
            // For inlined unions, |data_| is always non-null. In that case we need to
            // check |data_->is_null()|.
            return !data_ || data_->is_null();
        }

        Tag tag() const { return data_->tag; }
        bool is_peer_associated_endpoint_closed_event() const { return data_->tag == Tag::PEER_ASSOCIATED_ENDPOINT_CLOSED_EVENT; }
        inline void GetPeerAssociatedEndpointClosedEventDataView(
            PeerAssociatedEndpointClosedEventDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPeerAssociatedEndpointClosedEvent(UserType* output)
        {
            DCHECK(is_peer_associated_endpoint_closed_event());
            return mojo::internal::Deserialize<::mojo::pipe_control::PeerAssociatedEndpointClosedEventDataView>(
                data_->data.f_peer_associated_endpoint_closed_event.Get(), output, context_);
        }
        bool is_associated_endpoint_closed_before_sent_event() const { return data_->tag == Tag::ASSOCIATED_ENDPOINT_CLOSED_BEFORE_SENT_EVENT; }
        inline void GetAssociatedEndpointClosedBeforeSentEventDataView(
            AssociatedEndpointClosedBeforeSentEventDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAssociatedEndpointClosedBeforeSentEvent(UserType* output)
        {
            DCHECK(is_associated_endpoint_closed_before_sent_event());
            return mojo::internal::Deserialize<::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEventDataView>(
                data_->data.f_associated_endpoint_closed_before_sent_event.Get(), output, context_);
        }

    private:
        internal::RunOrClosePipeInput_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace pipe_control
} // namespace mojo

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::pipe_control::RunOrClosePipeMessageParamsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::mojo::pipe_control::RunOrClosePipeMessageParamsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::mojo::pipe_control::internal::RunOrClosePipeMessageParams_Data);
            decltype(CallWithContext(Traits::input, input, custom_context)) in_input = CallWithContext(Traits::input, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::pipe_control::RunOrClosePipeInputDataView>(
                in_input, true, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::pipe_control::internal::RunOrClosePipeMessageParams_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::mojo::pipe_control::internal::RunOrClosePipeMessageParams_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::input, input, custom_context)) in_input = CallWithContext(Traits::input, input, custom_context);
            auto input_ptr = &result->input;
            mojo::internal::Serialize<::mojo::pipe_control::RunOrClosePipeInputDataView>(
                in_input, buffer, &input_ptr, true, context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->input.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null input in RunOrClosePipeMessageParams struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::pipe_control::internal::RunOrClosePipeMessageParams_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::pipe_control::RunOrClosePipeMessageParamsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::pipe_control::PeerAssociatedEndpointClosedEventDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::mojo::pipe_control::PeerAssociatedEndpointClosedEventDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::mojo::pipe_control::internal::PeerAssociatedEndpointClosedEvent_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::pipe_control::internal::PeerAssociatedEndpointClosedEvent_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::mojo::pipe_control::internal::PeerAssociatedEndpointClosedEvent_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->id = CallWithContext(Traits::id, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::pipe_control::internal::PeerAssociatedEndpointClosedEvent_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::pipe_control::PeerAssociatedEndpointClosedEventDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEventDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEventDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::mojo::pipe_control::internal::AssociatedEndpointClosedBeforeSentEvent_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::pipe_control::internal::AssociatedEndpointClosedBeforeSentEvent_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::mojo::pipe_control::internal::AssociatedEndpointClosedBeforeSentEvent_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->id = CallWithContext(Traits::id, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::pipe_control::internal::AssociatedEndpointClosedBeforeSentEvent_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEventDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::pipe_control::RunOrClosePipeInputDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = UnionTraits<::mojo::pipe_control::RunOrClosePipeInputDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            bool inlined,
            SerializationContext* context)
        {
            size_t size = inlined ? 0 : sizeof(::mojo::pipe_control::internal::RunOrClosePipeInput_Data);

            if (CallIsNullIfExists<Traits>(input))
                return size;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            switch (CallWithContext(Traits::GetTag, input, custom_context)) {
            case ::mojo::pipe_control::RunOrClosePipeInputDataView::Tag::PEER_ASSOCIATED_ENDPOINT_CLOSED_EVENT: {
                decltype(CallWithContext(Traits::peer_associated_endpoint_closed_event, input, custom_context))
                    in_peer_associated_endpoint_closed_event
                    = CallWithContext(Traits::peer_associated_endpoint_closed_event, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::mojo::pipe_control::PeerAssociatedEndpointClosedEventDataView>(
                    in_peer_associated_endpoint_closed_event, context);
                break;
            }
            case ::mojo::pipe_control::RunOrClosePipeInputDataView::Tag::ASSOCIATED_ENDPOINT_CLOSED_BEFORE_SENT_EVENT: {
                decltype(CallWithContext(Traits::associated_endpoint_closed_before_sent_event, input, custom_context))
                    in_associated_endpoint_closed_before_sent_event
                    = CallWithContext(Traits::associated_endpoint_closed_before_sent_event, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEventDataView>(
                    in_associated_endpoint_closed_before_sent_event, context);
                break;
            }
            }
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::pipe_control::internal::RunOrClosePipeInput_Data** output,
            bool inlined,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                if (inlined)
                    (*output)->set_null();
                else
                    *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            if (!inlined)
                *output = ::mojo::pipe_control::internal::RunOrClosePipeInput_Data::New(buffer);

            ::mojo::pipe_control::internal::RunOrClosePipeInput_Data* result = *output;
            ALLOW_UNUSED_LOCAL(result);
            // TODO(azani): Handle unknown and objects.
            // Set the not-null flag.
            result->size = kUnionDataSize;
            result->tag = CallWithContext(Traits::GetTag, input, custom_context);
            switch (result->tag) {
            case ::mojo::pipe_control::RunOrClosePipeInputDataView::Tag::PEER_ASSOCIATED_ENDPOINT_CLOSED_EVENT: {
                decltype(CallWithContext(Traits::peer_associated_endpoint_closed_event, input, custom_context))
                    in_peer_associated_endpoint_closed_event
                    = CallWithContext(Traits::peer_associated_endpoint_closed_event, input,
                        custom_context);
                typename decltype(result->data.f_peer_associated_endpoint_closed_event)::BaseType* ptr;
                mojo::internal::Serialize<::mojo::pipe_control::PeerAssociatedEndpointClosedEventDataView>(
                    in_peer_associated_endpoint_closed_event, buffer, &ptr, context);
                result->data.f_peer_associated_endpoint_closed_event.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null peer_associated_endpoint_closed_event in RunOrClosePipeInput union");
                break;
            }
            case ::mojo::pipe_control::RunOrClosePipeInputDataView::Tag::ASSOCIATED_ENDPOINT_CLOSED_BEFORE_SENT_EVENT: {
                decltype(CallWithContext(Traits::associated_endpoint_closed_before_sent_event, input, custom_context))
                    in_associated_endpoint_closed_before_sent_event
                    = CallWithContext(Traits::associated_endpoint_closed_before_sent_event, input,
                        custom_context);
                typename decltype(result->data.f_associated_endpoint_closed_before_sent_event)::BaseType* ptr;
                mojo::internal::Serialize<::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEventDataView>(
                    in_associated_endpoint_closed_before_sent_event, buffer, &ptr, context);
                result->data.f_associated_endpoint_closed_before_sent_event.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null associated_endpoint_closed_before_sent_event in RunOrClosePipeInput union");
                break;
            }
            }

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::pipe_control::internal::RunOrClosePipeInput_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input || input->is_null())
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::pipe_control::RunOrClosePipeInputDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace mojo {
namespace pipe_control {

    inline void RunOrClosePipeMessageParamsDataView::GetInputDataView(
        RunOrClosePipeInputDataView* output)
    {
        auto pointer = &data_->input;
        *output = RunOrClosePipeInputDataView(pointer, context_);
    }

    inline void RunOrClosePipeInputDataView::GetPeerAssociatedEndpointClosedEventDataView(
        PeerAssociatedEndpointClosedEventDataView* output)
    {
        DCHECK(is_peer_associated_endpoint_closed_event());
        *output = PeerAssociatedEndpointClosedEventDataView(data_->data.f_peer_associated_endpoint_closed_event.Get(), context_);
    }
    inline void RunOrClosePipeInputDataView::GetAssociatedEndpointClosedBeforeSentEventDataView(
        AssociatedEndpointClosedBeforeSentEventDataView* output)
    {
        DCHECK(is_associated_endpoint_closed_before_sent_event());
        *output = AssociatedEndpointClosedBeforeSentEventDataView(data_->data.f_associated_endpoint_closed_before_sent_event.Get(), context_);
    }

} // namespace pipe_control
} // namespace mojo

#endif // MOJO_PUBLIC_INTERFACES_BINDINGS_PIPE_CONTROL_MESSAGES_MOJOM_SHARED_H_
