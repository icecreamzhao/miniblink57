// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_PUBLIC_INTERFACES_BINDINGS_INTERFACE_CONTROL_MESSAGES_MOJOM_SHARED_H_
#define MOJO_PUBLIC_INTERFACES_BINDINGS_INTERFACE_CONTROL_MESSAGES_MOJOM_SHARED_H_

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
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom-shared-internal.h"

namespace mojo {
namespace interface_control {
    class RunMessageParamsDataView;

    class RunResponseMessageParamsDataView;

    class QueryVersionDataView;

    class QueryVersionResultDataView;

    class FlushForTestingDataView;

    class RunOrClosePipeMessageParamsDataView;

    class RequireVersionDataView;

    class SendDisconnectReasonDataView;

    class RunInputDataView;
    class RunOutputDataView;
    class RunOrClosePipeInputDataView;

} // namespace interface_control
} // namespace mojo

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::mojo::interface_control::RunMessageParamsDataView> {
        using Data = ::mojo::interface_control::internal::RunMessageParams_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::mojo::interface_control::RunResponseMessageParamsDataView> {
        using Data = ::mojo::interface_control::internal::RunResponseMessageParams_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::mojo::interface_control::QueryVersionDataView> {
        using Data = ::mojo::interface_control::internal::QueryVersion_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::mojo::interface_control::QueryVersionResultDataView> {
        using Data = ::mojo::interface_control::internal::QueryVersionResult_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::mojo::interface_control::FlushForTestingDataView> {
        using Data = ::mojo::interface_control::internal::FlushForTesting_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::mojo::interface_control::RunOrClosePipeMessageParamsDataView> {
        using Data = ::mojo::interface_control::internal::RunOrClosePipeMessageParams_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::mojo::interface_control::RequireVersionDataView> {
        using Data = ::mojo::interface_control::internal::RequireVersion_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::mojo::interface_control::SendDisconnectReasonDataView> {
        using Data = ::mojo::interface_control::internal::SendDisconnectReason_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::mojo::interface_control::RunInputDataView> {
        using Data = ::mojo::interface_control::internal::RunInput_Data;
        using DataAsArrayElement = Data;
        static constexpr MojomTypeCategory category = MojomTypeCategory::UNION;
    };

    template <>
    struct MojomTypeTraits<::mojo::interface_control::RunOutputDataView> {
        using Data = ::mojo::interface_control::internal::RunOutput_Data;
        using DataAsArrayElement = Data;
        static constexpr MojomTypeCategory category = MojomTypeCategory::UNION;
    };

    template <>
    struct MojomTypeTraits<::mojo::interface_control::RunOrClosePipeInputDataView> {
        using Data = ::mojo::interface_control::internal::RunOrClosePipeInput_Data;
        using DataAsArrayElement = Data;
        static constexpr MojomTypeCategory category = MojomTypeCategory::UNION;
    };

} // namespace internal
} // namespace mojo

namespace mojo {
namespace interface_control {
    class RunMessageParamsDataView {
    public:
        RunMessageParamsDataView() { }

        RunMessageParamsDataView(
            internal::RunMessageParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetInputDataView(
            RunInputDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInput(UserType* output)
        {
            auto* pointer = &data_->input;
            return mojo::internal::Deserialize<::mojo::interface_control::RunInputDataView>(
                pointer, output, context_);
        }

    private:
        internal::RunMessageParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RunResponseMessageParamsDataView {
    public:
        RunResponseMessageParamsDataView() { }

        RunResponseMessageParamsDataView(
            internal::RunResponseMessageParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetOutputDataView(
            RunOutputDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOutput(UserType* output)
        {
            auto* pointer = &data_->output;
            return mojo::internal::Deserialize<::mojo::interface_control::RunOutputDataView>(
                pointer, output, context_);
        }

    private:
        internal::RunResponseMessageParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class QueryVersionDataView {
    public:
        QueryVersionDataView() { }

        QueryVersionDataView(
            internal::QueryVersion_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::QueryVersion_Data* data_ = nullptr;
    };

    class QueryVersionResultDataView {
    public:
        QueryVersionResultDataView() { }

        QueryVersionResultDataView(
            internal::QueryVersionResult_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t version() const
        {
            return data_->version;
        }

    private:
        internal::QueryVersionResult_Data* data_ = nullptr;
    };

    class FlushForTestingDataView {
    public:
        FlushForTestingDataView() { }

        FlushForTestingDataView(
            internal::FlushForTesting_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::FlushForTesting_Data* data_ = nullptr;
    };

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
            return mojo::internal::Deserialize<::mojo::interface_control::RunOrClosePipeInputDataView>(
                pointer, output, context_);
        }

    private:
        internal::RunOrClosePipeMessageParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RequireVersionDataView {
    public:
        RequireVersionDataView() { }

        RequireVersionDataView(
            internal::RequireVersion_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t version() const
        {
            return data_->version;
        }

    private:
        internal::RequireVersion_Data* data_ = nullptr;
    };

    class SendDisconnectReasonDataView {
    public:
        SendDisconnectReasonDataView() { }

        SendDisconnectReasonDataView(
            internal::SendDisconnectReason_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t custom_reason() const
        {
            return data_->custom_reason;
        }
        inline void GetDescriptionDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDescription(UserType* output)
        {
            auto* pointer = data_->description.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::SendDisconnectReason_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RunInputDataView {
    public:
        using Tag = internal::RunInput_Data::RunInput_Tag;

        RunInputDataView() { }

        RunInputDataView(
            internal::RunInput_Data* data,
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
        bool is_query_version() const { return data_->tag == Tag::QUERY_VERSION; }
        inline void GetQueryVersionDataView(
            QueryVersionDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadQueryVersion(UserType* output)
        {
            DCHECK(is_query_version());
            return mojo::internal::Deserialize<::mojo::interface_control::QueryVersionDataView>(
                data_->data.f_query_version.Get(), output, context_);
        }
        bool is_flush_for_testing() const { return data_->tag == Tag::FLUSH_FOR_TESTING; }
        inline void GetFlushForTestingDataView(
            FlushForTestingDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFlushForTesting(UserType* output)
        {
            DCHECK(is_flush_for_testing());
            return mojo::internal::Deserialize<::mojo::interface_control::FlushForTestingDataView>(
                data_->data.f_flush_for_testing.Get(), output, context_);
        }

    private:
        internal::RunInput_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RunOutputDataView {
    public:
        using Tag = internal::RunOutput_Data::RunOutput_Tag;

        RunOutputDataView() { }

        RunOutputDataView(
            internal::RunOutput_Data* data,
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
        bool is_query_version_result() const { return data_->tag == Tag::QUERY_VERSION_RESULT; }
        inline void GetQueryVersionResultDataView(
            QueryVersionResultDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadQueryVersionResult(UserType* output)
        {
            DCHECK(is_query_version_result());
            return mojo::internal::Deserialize<::mojo::interface_control::QueryVersionResultDataView>(
                data_->data.f_query_version_result.Get(), output, context_);
        }

    private:
        internal::RunOutput_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
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
        bool is_require_version() const { return data_->tag == Tag::REQUIRE_VERSION; }
        inline void GetRequireVersionDataView(
            RequireVersionDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRequireVersion(UserType* output)
        {
            DCHECK(is_require_version());
            return mojo::internal::Deserialize<::mojo::interface_control::RequireVersionDataView>(
                data_->data.f_require_version.Get(), output, context_);
        }
        bool is_send_disconnect_reason() const { return data_->tag == Tag::SEND_DISCONNECT_REASON; }
        inline void GetSendDisconnectReasonDataView(
            SendDisconnectReasonDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSendDisconnectReason(UserType* output)
        {
            DCHECK(is_send_disconnect_reason());
            return mojo::internal::Deserialize<::mojo::interface_control::SendDisconnectReasonDataView>(
                data_->data.f_send_disconnect_reason.Get(), output, context_);
        }

    private:
        internal::RunOrClosePipeInput_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace interface_control
} // namespace mojo

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::interface_control::RunMessageParamsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::mojo::interface_control::RunMessageParamsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::mojo::interface_control::internal::RunMessageParams_Data);
            decltype(CallWithContext(Traits::input, input, custom_context)) in_input = CallWithContext(Traits::input, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::interface_control::RunInputDataView>(
                in_input, true, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::interface_control::internal::RunMessageParams_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::mojo::interface_control::internal::RunMessageParams_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::input, input, custom_context)) in_input = CallWithContext(Traits::input, input, custom_context);
            auto input_ptr = &result->input;
            mojo::internal::Serialize<::mojo::interface_control::RunInputDataView>(
                in_input, buffer, &input_ptr, true, context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->input.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null input in RunMessageParams struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::interface_control::internal::RunMessageParams_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::interface_control::RunMessageParamsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::interface_control::RunResponseMessageParamsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::mojo::interface_control::RunResponseMessageParamsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::mojo::interface_control::internal::RunResponseMessageParams_Data);
            decltype(CallWithContext(Traits::output, input, custom_context)) in_output = CallWithContext(Traits::output, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::interface_control::RunOutputDataView>(
                in_output, true, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::interface_control::internal::RunResponseMessageParams_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::mojo::interface_control::internal::RunResponseMessageParams_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::output, input, custom_context)) in_output = CallWithContext(Traits::output, input, custom_context);
            auto output_ptr = &result->output;
            mojo::internal::Serialize<::mojo::interface_control::RunOutputDataView>(
                in_output, buffer, &output_ptr, true, context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::interface_control::internal::RunResponseMessageParams_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::interface_control::RunResponseMessageParamsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::interface_control::QueryVersionDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::mojo::interface_control::QueryVersionDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::mojo::interface_control::internal::QueryVersion_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::interface_control::internal::QueryVersion_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::mojo::interface_control::internal::QueryVersion_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::interface_control::internal::QueryVersion_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::interface_control::QueryVersionDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::interface_control::QueryVersionResultDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::mojo::interface_control::QueryVersionResultDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::mojo::interface_control::internal::QueryVersionResult_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::interface_control::internal::QueryVersionResult_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::mojo::interface_control::internal::QueryVersionResult_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->version = CallWithContext(Traits::version, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::interface_control::internal::QueryVersionResult_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::interface_control::QueryVersionResultDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::interface_control::FlushForTestingDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::mojo::interface_control::FlushForTestingDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::mojo::interface_control::internal::FlushForTesting_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::interface_control::internal::FlushForTesting_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::mojo::interface_control::internal::FlushForTesting_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::interface_control::internal::FlushForTesting_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::interface_control::FlushForTestingDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::interface_control::RunOrClosePipeMessageParamsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::mojo::interface_control::RunOrClosePipeMessageParamsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::mojo::interface_control::internal::RunOrClosePipeMessageParams_Data);
            decltype(CallWithContext(Traits::input, input, custom_context)) in_input = CallWithContext(Traits::input, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::interface_control::RunOrClosePipeInputDataView>(
                in_input, true, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::interface_control::internal::RunOrClosePipeMessageParams_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::mojo::interface_control::internal::RunOrClosePipeMessageParams_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::input, input, custom_context)) in_input = CallWithContext(Traits::input, input, custom_context);
            auto input_ptr = &result->input;
            mojo::internal::Serialize<::mojo::interface_control::RunOrClosePipeInputDataView>(
                in_input, buffer, &input_ptr, true, context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->input.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null input in RunOrClosePipeMessageParams struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::interface_control::internal::RunOrClosePipeMessageParams_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::interface_control::RunOrClosePipeMessageParamsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::interface_control::RequireVersionDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::mojo::interface_control::RequireVersionDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::mojo::interface_control::internal::RequireVersion_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::interface_control::internal::RequireVersion_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::mojo::interface_control::internal::RequireVersion_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->version = CallWithContext(Traits::version, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::interface_control::internal::RequireVersion_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::interface_control::RequireVersionDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::interface_control::SendDisconnectReasonDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::mojo::interface_control::SendDisconnectReasonDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::mojo::interface_control::internal::SendDisconnectReason_Data);
            decltype(CallWithContext(Traits::description, input, custom_context)) in_description = CallWithContext(Traits::description, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_description, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::interface_control::internal::SendDisconnectReason_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::mojo::interface_control::internal::SendDisconnectReason_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->custom_reason = CallWithContext(Traits::custom_reason, input, custom_context);
            decltype(CallWithContext(Traits::description, input, custom_context)) in_description = CallWithContext(Traits::description, input, custom_context);
            typename decltype(result->description)::BaseType* description_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_description, buffer, &description_ptr, context);
            result->description.Set(description_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->description.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null description in SendDisconnectReason struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::interface_control::internal::SendDisconnectReason_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::interface_control::SendDisconnectReasonDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::interface_control::RunInputDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = UnionTraits<::mojo::interface_control::RunInputDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            bool inlined,
            SerializationContext* context)
        {
            size_t size = inlined ? 0 : sizeof(::mojo::interface_control::internal::RunInput_Data);

            if (CallIsNullIfExists<Traits>(input))
                return size;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            switch (CallWithContext(Traits::GetTag, input, custom_context)) {
            case ::mojo::interface_control::RunInputDataView::Tag::QUERY_VERSION: {
                decltype(CallWithContext(Traits::query_version, input, custom_context))
                    in_query_version
                    = CallWithContext(Traits::query_version, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::mojo::interface_control::QueryVersionDataView>(
                    in_query_version, context);
                break;
            }
            case ::mojo::interface_control::RunInputDataView::Tag::FLUSH_FOR_TESTING: {
                decltype(CallWithContext(Traits::flush_for_testing, input, custom_context))
                    in_flush_for_testing
                    = CallWithContext(Traits::flush_for_testing, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::mojo::interface_control::FlushForTestingDataView>(
                    in_flush_for_testing, context);
                break;
            }
            }
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::interface_control::internal::RunInput_Data** output,
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
                *output = ::mojo::interface_control::internal::RunInput_Data::New(buffer);

            ::mojo::interface_control::internal::RunInput_Data* result = *output;
            ALLOW_UNUSED_LOCAL(result);
            // TODO(azani): Handle unknown and objects.
            // Set the not-null flag.
            result->size = kUnionDataSize;
            result->tag = CallWithContext(Traits::GetTag, input, custom_context);
            switch (result->tag) {
            case ::mojo::interface_control::RunInputDataView::Tag::QUERY_VERSION: {
                decltype(CallWithContext(Traits::query_version, input, custom_context))
                    in_query_version
                    = CallWithContext(Traits::query_version, input,
                        custom_context);
                typename decltype(result->data.f_query_version)::BaseType* ptr;
                mojo::internal::Serialize<::mojo::interface_control::QueryVersionDataView>(
                    in_query_version, buffer, &ptr, context);
                result->data.f_query_version.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null query_version in RunInput union");
                break;
            }
            case ::mojo::interface_control::RunInputDataView::Tag::FLUSH_FOR_TESTING: {
                decltype(CallWithContext(Traits::flush_for_testing, input, custom_context))
                    in_flush_for_testing
                    = CallWithContext(Traits::flush_for_testing, input,
                        custom_context);
                typename decltype(result->data.f_flush_for_testing)::BaseType* ptr;
                mojo::internal::Serialize<::mojo::interface_control::FlushForTestingDataView>(
                    in_flush_for_testing, buffer, &ptr, context);
                result->data.f_flush_for_testing.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null flush_for_testing in RunInput union");
                break;
            }
            }

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::interface_control::internal::RunInput_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input || input->is_null())
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::interface_control::RunInputDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::interface_control::RunOutputDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = UnionTraits<::mojo::interface_control::RunOutputDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            bool inlined,
            SerializationContext* context)
        {
            size_t size = inlined ? 0 : sizeof(::mojo::interface_control::internal::RunOutput_Data);

            if (CallIsNullIfExists<Traits>(input))
                return size;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            switch (CallWithContext(Traits::GetTag, input, custom_context)) {
            case ::mojo::interface_control::RunOutputDataView::Tag::QUERY_VERSION_RESULT: {
                decltype(CallWithContext(Traits::query_version_result, input, custom_context))
                    in_query_version_result
                    = CallWithContext(Traits::query_version_result, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::mojo::interface_control::QueryVersionResultDataView>(
                    in_query_version_result, context);
                break;
            }
            }
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::interface_control::internal::RunOutput_Data** output,
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
                *output = ::mojo::interface_control::internal::RunOutput_Data::New(buffer);

            ::mojo::interface_control::internal::RunOutput_Data* result = *output;
            ALLOW_UNUSED_LOCAL(result);
            // TODO(azani): Handle unknown and objects.
            // Set the not-null flag.
            result->size = kUnionDataSize;
            result->tag = CallWithContext(Traits::GetTag, input, custom_context);
            switch (result->tag) {
            case ::mojo::interface_control::RunOutputDataView::Tag::QUERY_VERSION_RESULT: {
                decltype(CallWithContext(Traits::query_version_result, input, custom_context))
                    in_query_version_result
                    = CallWithContext(Traits::query_version_result, input,
                        custom_context);
                typename decltype(result->data.f_query_version_result)::BaseType* ptr;
                mojo::internal::Serialize<::mojo::interface_control::QueryVersionResultDataView>(
                    in_query_version_result, buffer, &ptr, context);
                result->data.f_query_version_result.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null query_version_result in RunOutput union");
                break;
            }
            }

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::interface_control::internal::RunOutput_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input || input->is_null())
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::interface_control::RunOutputDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::interface_control::RunOrClosePipeInputDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = UnionTraits<::mojo::interface_control::RunOrClosePipeInputDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            bool inlined,
            SerializationContext* context)
        {
            size_t size = inlined ? 0 : sizeof(::mojo::interface_control::internal::RunOrClosePipeInput_Data);

            if (CallIsNullIfExists<Traits>(input))
                return size;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            switch (CallWithContext(Traits::GetTag, input, custom_context)) {
            case ::mojo::interface_control::RunOrClosePipeInputDataView::Tag::REQUIRE_VERSION: {
                decltype(CallWithContext(Traits::require_version, input, custom_context))
                    in_require_version
                    = CallWithContext(Traits::require_version, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::mojo::interface_control::RequireVersionDataView>(
                    in_require_version, context);
                break;
            }
            case ::mojo::interface_control::RunOrClosePipeInputDataView::Tag::SEND_DISCONNECT_REASON: {
                decltype(CallWithContext(Traits::send_disconnect_reason, input, custom_context))
                    in_send_disconnect_reason
                    = CallWithContext(Traits::send_disconnect_reason, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::mojo::interface_control::SendDisconnectReasonDataView>(
                    in_send_disconnect_reason, context);
                break;
            }
            }
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::interface_control::internal::RunOrClosePipeInput_Data** output,
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
                *output = ::mojo::interface_control::internal::RunOrClosePipeInput_Data::New(buffer);

            ::mojo::interface_control::internal::RunOrClosePipeInput_Data* result = *output;
            ALLOW_UNUSED_LOCAL(result);
            // TODO(azani): Handle unknown and objects.
            // Set the not-null flag.
            result->size = kUnionDataSize;
            result->tag = CallWithContext(Traits::GetTag, input, custom_context);
            switch (result->tag) {
            case ::mojo::interface_control::RunOrClosePipeInputDataView::Tag::REQUIRE_VERSION: {
                decltype(CallWithContext(Traits::require_version, input, custom_context))
                    in_require_version
                    = CallWithContext(Traits::require_version, input,
                        custom_context);
                typename decltype(result->data.f_require_version)::BaseType* ptr;
                mojo::internal::Serialize<::mojo::interface_control::RequireVersionDataView>(
                    in_require_version, buffer, &ptr, context);
                result->data.f_require_version.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null require_version in RunOrClosePipeInput union");
                break;
            }
            case ::mojo::interface_control::RunOrClosePipeInputDataView::Tag::SEND_DISCONNECT_REASON: {
                decltype(CallWithContext(Traits::send_disconnect_reason, input, custom_context))
                    in_send_disconnect_reason
                    = CallWithContext(Traits::send_disconnect_reason, input,
                        custom_context);
                typename decltype(result->data.f_send_disconnect_reason)::BaseType* ptr;
                mojo::internal::Serialize<::mojo::interface_control::SendDisconnectReasonDataView>(
                    in_send_disconnect_reason, buffer, &ptr, context);
                result->data.f_send_disconnect_reason.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null send_disconnect_reason in RunOrClosePipeInput union");
                break;
            }
            }

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::interface_control::internal::RunOrClosePipeInput_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input || input->is_null())
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::interface_control::RunOrClosePipeInputDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace mojo {
namespace interface_control {

    inline void RunMessageParamsDataView::GetInputDataView(
        RunInputDataView* output)
    {
        auto pointer = &data_->input;
        *output = RunInputDataView(pointer, context_);
    }

    inline void RunResponseMessageParamsDataView::GetOutputDataView(
        RunOutputDataView* output)
    {
        auto pointer = &data_->output;
        *output = RunOutputDataView(pointer, context_);
    }

    inline void RunOrClosePipeMessageParamsDataView::GetInputDataView(
        RunOrClosePipeInputDataView* output)
    {
        auto pointer = &data_->input;
        *output = RunOrClosePipeInputDataView(pointer, context_);
    }

    inline void SendDisconnectReasonDataView::GetDescriptionDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->description.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void RunInputDataView::GetQueryVersionDataView(
        QueryVersionDataView* output)
    {
        DCHECK(is_query_version());
        *output = QueryVersionDataView(data_->data.f_query_version.Get(), context_);
    }
    inline void RunInputDataView::GetFlushForTestingDataView(
        FlushForTestingDataView* output)
    {
        DCHECK(is_flush_for_testing());
        *output = FlushForTestingDataView(data_->data.f_flush_for_testing.Get(), context_);
    }

    inline void RunOutputDataView::GetQueryVersionResultDataView(
        QueryVersionResultDataView* output)
    {
        DCHECK(is_query_version_result());
        *output = QueryVersionResultDataView(data_->data.f_query_version_result.Get(), context_);
    }

    inline void RunOrClosePipeInputDataView::GetRequireVersionDataView(
        RequireVersionDataView* output)
    {
        DCHECK(is_require_version());
        *output = RequireVersionDataView(data_->data.f_require_version.Get(), context_);
    }
    inline void RunOrClosePipeInputDataView::GetSendDisconnectReasonDataView(
        SendDisconnectReasonDataView* output)
    {
        DCHECK(is_send_disconnect_reason());
        *output = SendDisconnectReasonDataView(data_->data.f_send_disconnect_reason.Get(), context_);
    }

} // namespace interface_control
} // namespace mojo

#endif // MOJO_PUBLIC_INTERFACES_BINDINGS_INTERFACE_CONTROL_MESSAGES_MOJOM_SHARED_H_
