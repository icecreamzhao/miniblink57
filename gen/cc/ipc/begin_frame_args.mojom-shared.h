// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_BEGIN_FRAME_ARGS_MOJOM_SHARED_H_
#define CC_IPC_BEGIN_FRAME_ARGS_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/begin_frame_args.mojom-shared-internal.h"
#include "mojo/common/time.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace cc {
namespace mojom {
    class BeginFrameArgsDataView;

} // namespace mojom
} // namespace cc

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::cc::mojom::BeginFrameArgsDataView> {
        using Data = ::cc::mojom::internal::BeginFrameArgs_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace cc {
namespace mojom {

    enum class BeginFrameArgsType : int32_t {
        INVALID,
        NORMAL,
        MISSED,
        BEGIN_FRAME_ARGS_TYPE_MAX,
    };

    inline std::ostream& operator<<(std::ostream& os, BeginFrameArgsType value)
    {
        switch (value) {
        case BeginFrameArgsType::INVALID:
            return os << "BeginFrameArgsType::INVALID";
        case BeginFrameArgsType::NORMAL:
            return os << "BeginFrameArgsType::NORMAL";
        case BeginFrameArgsType::MISSED:
            return os << "BeginFrameArgsType::MISSED";
        case BeginFrameArgsType::BEGIN_FRAME_ARGS_TYPE_MAX:
            return os << "BeginFrameArgsType::BEGIN_FRAME_ARGS_TYPE_MAX";
        default:
            return os << "Unknown BeginFrameArgsType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(BeginFrameArgsType value)
    {
        return internal::BeginFrameArgsType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class BeginFrameArgsDataView {
    public:
        BeginFrameArgsDataView() { }

        BeginFrameArgsDataView(
            internal::BeginFrameArgs_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFrameTimeDataView(
            ::mojo::common::mojom::TimeTicksDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFrameTime(UserType* output)
        {
            auto* pointer = data_->frame_time.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeTicksDataView>(
                pointer, output, context_);
        }
        inline void GetDeadlineDataView(
            ::mojo::common::mojom::TimeTicksDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDeadline(UserType* output)
        {
            auto* pointer = data_->deadline.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeTicksDataView>(
                pointer, output, context_);
        }
        inline void GetIntervalDataView(
            ::mojo::common::mojom::TimeDeltaDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInterval(UserType* output)
        {
            auto* pointer = data_->interval.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDeltaDataView>(
                pointer, output, context_);
        }
        uint64_t sequence_number() const
        {
            return data_->sequence_number;
        }
        uint32_t source_id() const
        {
            return data_->source_id;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::cc::mojom::BeginFrameArgsType>(
                data_value, output);
        }

        BeginFrameArgsType type() const
        {
            return static_cast<BeginFrameArgsType>(data_->type);
        }
        bool on_critical_path() const
        {
            return data_->on_critical_path;
        }

    private:
        internal::BeginFrameArgs_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace cc

namespace std {

template <>
struct hash<::cc::mojom::BeginFrameArgsType>
    : public mojo::internal::EnumHashImpl<::cc::mojom::BeginFrameArgsType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::cc::mojom::BeginFrameArgsType, ::cc::mojom::BeginFrameArgsType> {
    static ::cc::mojom::BeginFrameArgsType ToMojom(::cc::mojom::BeginFrameArgsType input) { return input; }
    static bool FromMojom(::cc::mojom::BeginFrameArgsType input, ::cc::mojom::BeginFrameArgsType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::BeginFrameArgsType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::cc::mojom::BeginFrameArgsType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::cc::mojom::BeginFrameArgsType>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::BeginFrameArgsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::BeginFrameArgsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::BeginFrameArgs_Data);
            decltype(CallWithContext(Traits::frame_time, input, custom_context)) in_frame_time = CallWithContext(Traits::frame_time, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeTicksDataView>(
                in_frame_time, context);
            decltype(CallWithContext(Traits::deadline, input, custom_context)) in_deadline = CallWithContext(Traits::deadline, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeTicksDataView>(
                in_deadline, context);
            decltype(CallWithContext(Traits::interval, input, custom_context)) in_interval = CallWithContext(Traits::interval, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_interval, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::BeginFrameArgs_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::BeginFrameArgs_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::frame_time, input, custom_context)) in_frame_time = CallWithContext(Traits::frame_time, input, custom_context);
            typename decltype(result->frame_time)::BaseType* frame_time_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::TimeTicksDataView>(
                in_frame_time, buffer, &frame_time_ptr, context);
            result->frame_time.Set(frame_time_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->frame_time.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null frame_time in BeginFrameArgs struct");
            decltype(CallWithContext(Traits::deadline, input, custom_context)) in_deadline = CallWithContext(Traits::deadline, input, custom_context);
            typename decltype(result->deadline)::BaseType* deadline_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::TimeTicksDataView>(
                in_deadline, buffer, &deadline_ptr, context);
            result->deadline.Set(deadline_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->deadline.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null deadline in BeginFrameArgs struct");
            decltype(CallWithContext(Traits::interval, input, custom_context)) in_interval = CallWithContext(Traits::interval, input, custom_context);
            typename decltype(result->interval)::BaseType* interval_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::TimeDeltaDataView>(
                in_interval, buffer, &interval_ptr, context);
            result->interval.Set(interval_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->interval.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null interval in BeginFrameArgs struct");
            result->sequence_number = CallWithContext(Traits::sequence_number, input, custom_context);
            result->source_id = CallWithContext(Traits::source_id, input, custom_context);
            mojo::internal::Serialize<::cc::mojom::BeginFrameArgsType>(
                CallWithContext(Traits::type, input, custom_context), &result->type);
            result->on_critical_path = CallWithContext(Traits::on_critical_path, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::BeginFrameArgs_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::BeginFrameArgsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace cc {
namespace mojom {

    inline void BeginFrameArgsDataView::GetFrameTimeDataView(
        ::mojo::common::mojom::TimeTicksDataView* output)
    {
        auto pointer = data_->frame_time.Get();
        *output = ::mojo::common::mojom::TimeTicksDataView(pointer, context_);
    }
    inline void BeginFrameArgsDataView::GetDeadlineDataView(
        ::mojo::common::mojom::TimeTicksDataView* output)
    {
        auto pointer = data_->deadline.Get();
        *output = ::mojo::common::mojom::TimeTicksDataView(pointer, context_);
    }
    inline void BeginFrameArgsDataView::GetIntervalDataView(
        ::mojo::common::mojom::TimeDeltaDataView* output)
    {
        auto pointer = data_->interval.Get();
        *output = ::mojo::common::mojom::TimeDeltaDataView(pointer, context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_BEGIN_FRAME_ARGS_MOJOM_SHARED_H_
