// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_EVENTS_MOJO_LATENCY_INFO_MOJOM_SHARED_H_
#define UI_EVENTS_MOJO_LATENCY_INFO_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
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
#include "ui/events/mojo/latency_info.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace ui {
namespace mojom {
    class LatencyComponentIdDataView;

    class LatencyComponentDataView;

    class LatencyComponentPairDataView;

    class LatencyInfoDataView;

} // namespace mojom
} // namespace ui

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::ui::mojom::LatencyComponentIdDataView> {
        using Data = ::ui::mojom::internal::LatencyComponentId_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::ui::mojom::LatencyComponentDataView> {
        using Data = ::ui::mojom::internal::LatencyComponent_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::ui::mojom::LatencyComponentPairDataView> {
        using Data = ::ui::mojom::internal::LatencyComponentPair_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::ui::mojom::LatencyInfoDataView> {
        using Data = ::ui::mojom::internal::LatencyInfo_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace ui {
namespace mojom {

    enum class LatencyComponentType : int32_t {
        INPUT_EVENT_LATENCY_BEGIN_RWH_COMPONENT,
        LATENCY_BEGIN_SCROLL_LISTENER_UPDATE_MAIN_COMPONENT,
        INPUT_EVENT_LATENCY_SCROLL_UPDATE_ORIGINAL_COMPONENT,
        INPUT_EVENT_LATENCY_FIRST_SCROLL_UPDATE_ORIGINAL_COMPONENT,
        INPUT_EVENT_LATENCY_ORIGINAL_COMPONENT,
        INPUT_EVENT_LATENCY_UI_COMPONENT,
        INPUT_EVENT_LATENCY_RENDERER_MAIN_COMPONENT,
        INPUT_EVENT_LATENCY_RENDERING_SCHEDULED_MAIN_COMPONENT,
        INPUT_EVENT_LATENCY_RENDERING_SCHEDULED_IMPL_COMPONENT,
        INPUT_EVENT_LATENCY_FORWARD_SCROLL_UPDATE_TO_MAIN_COMPONENT,
        INPUT_EVENT_LATENCY_ACK_RWH_COMPONENT,
        WINDOW_SNAPSHOT_FRAME_NUMBER_COMPONENT,
        TAB_SHOW_COMPONENT,
        INPUT_EVENT_LATENCY_RENDERER_SWAP_COMPONENT,
        INPUT_EVENT_BROWSER_RECEIVED_RENDERER_SWAP_COMPONENT,
        INPUT_EVENT_GPU_SWAP_BUFFER_COMPONENT,
        INPUT_EVENT_LATENCY_GENERATE_SCROLL_UPDATE_FROM_MOUSE_WHEEL,
        INPUT_EVENT_LATENCY_TERMINATED_MOUSE_COMPONENT,
        INPUT_EVENT_LATENCY_TERMINATED_MOUSE_WHEEL_COMPONENT,
        INPUT_EVENT_LATENCY_TERMINATED_KEYBOARD_COMPONENT,
        INPUT_EVENT_LATENCY_TERMINATED_TOUCH_COMPONENT,
        INPUT_EVENT_LATENCY_TERMINATED_GESTURE_COMPONENT,
        INPUT_EVENT_LATENCY_TERMINATED_FRAME_SWAP_COMPONENT,
        INPUT_EVENT_LATENCY_TERMINATED_COMMIT_FAILED_COMPONENT,
        INPUT_EVENT_LATENCY_TERMINATED_COMMIT_NO_UPDATE_COMPONENT,
        INPUT_EVENT_LATENCY_TERMINATED_SWAP_FAILED_COMPONENT,
        LATENCY_COMPONENT_TYPE_LAST = LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_SWAP_FAILED_COMPONENT,
    };

    inline std::ostream& operator<<(std::ostream& os, LatencyComponentType value)
    {
        switch (value) {
        case LatencyComponentType::INPUT_EVENT_LATENCY_BEGIN_RWH_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_BEGIN_RWH_COMPONENT";
        case LatencyComponentType::LATENCY_BEGIN_SCROLL_LISTENER_UPDATE_MAIN_COMPONENT:
            return os << "LatencyComponentType::LATENCY_BEGIN_SCROLL_LISTENER_UPDATE_MAIN_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_SCROLL_UPDATE_ORIGINAL_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_SCROLL_UPDATE_ORIGINAL_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_FIRST_SCROLL_UPDATE_ORIGINAL_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_FIRST_SCROLL_UPDATE_ORIGINAL_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_ORIGINAL_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_ORIGINAL_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_UI_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_UI_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_RENDERER_MAIN_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_RENDERER_MAIN_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_RENDERING_SCHEDULED_MAIN_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_RENDERING_SCHEDULED_MAIN_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_RENDERING_SCHEDULED_IMPL_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_RENDERING_SCHEDULED_IMPL_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_FORWARD_SCROLL_UPDATE_TO_MAIN_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_FORWARD_SCROLL_UPDATE_TO_MAIN_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_ACK_RWH_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_ACK_RWH_COMPONENT";
        case LatencyComponentType::WINDOW_SNAPSHOT_FRAME_NUMBER_COMPONENT:
            return os << "LatencyComponentType::WINDOW_SNAPSHOT_FRAME_NUMBER_COMPONENT";
        case LatencyComponentType::TAB_SHOW_COMPONENT:
            return os << "LatencyComponentType::TAB_SHOW_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_RENDERER_SWAP_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_RENDERER_SWAP_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_BROWSER_RECEIVED_RENDERER_SWAP_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_BROWSER_RECEIVED_RENDERER_SWAP_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_GPU_SWAP_BUFFER_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_GPU_SWAP_BUFFER_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_GENERATE_SCROLL_UPDATE_FROM_MOUSE_WHEEL:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_GENERATE_SCROLL_UPDATE_FROM_MOUSE_WHEEL";
        case LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_MOUSE_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_MOUSE_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_MOUSE_WHEEL_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_MOUSE_WHEEL_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_KEYBOARD_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_KEYBOARD_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_TOUCH_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_TOUCH_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_GESTURE_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_GESTURE_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_FRAME_SWAP_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_FRAME_SWAP_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_COMMIT_FAILED_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_COMMIT_FAILED_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_COMMIT_NO_UPDATE_COMPONENT:
            return os << "LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_COMMIT_NO_UPDATE_COMPONENT";
        case LatencyComponentType::INPUT_EVENT_LATENCY_TERMINATED_SWAP_FAILED_COMPONENT:
            return os << "LatencyComponentType::{INPUT_EVENT_LATENCY_TERMINATED_SWAP_FAILED_COMPONENT, LATENCY_COMPONENT_TYPE_LAST}";
        default:
            return os << "Unknown LatencyComponentType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(LatencyComponentType value)
    {
        return internal::LatencyComponentType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class LatencyComponentIdDataView {
    public:
        LatencyComponentIdDataView() { }

        LatencyComponentIdDataView(
            internal::LatencyComponentId_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::ui::mojom::LatencyComponentType>(
                data_value, output);
        }

        LatencyComponentType type() const
        {
            return static_cast<LatencyComponentType>(data_->type);
        }
        int64_t id() const
        {
            return data_->id;
        }

    private:
        internal::LatencyComponentId_Data* data_ = nullptr;
    };

    class LatencyComponentDataView {
    public:
        LatencyComponentDataView() { }

        LatencyComponentDataView(
            internal::LatencyComponent_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int64_t sequence_number() const
        {
            return data_->sequence_number;
        }
        inline void GetEventTimeDataView(
            ::mojo::common::mojom::TimeTicksDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEventTime(UserType* output)
        {
            auto* pointer = data_->event_time.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeTicksDataView>(
                pointer, output, context_);
        }
        uint32_t event_count() const
        {
            return data_->event_count;
        }

    private:
        internal::LatencyComponent_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LatencyComponentPairDataView {
    public:
        LatencyComponentPairDataView() { }

        LatencyComponentPairDataView(
            internal::LatencyComponentPair_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyDataView(
            LatencyComponentIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<::ui::mojom::LatencyComponentIdDataView>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            LatencyComponentDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<::ui::mojom::LatencyComponentDataView>(
                pointer, output, context_);
        }

    private:
        internal::LatencyComponentPair_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LatencyInfoDataView {
    public:
        LatencyInfoDataView() { }

        LatencyInfoDataView(
            internal::LatencyInfo_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTraceNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTraceName(UserType* output)
        {
            auto* pointer = data_->trace_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetLatencyComponentsDataView(
            mojo::ArrayDataView<LatencyComponentPairDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLatencyComponents(UserType* output)
        {
            auto* pointer = data_->latency_components.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::ui::mojom::LatencyComponentPairDataView>>(
                pointer, output, context_);
        }
        inline void GetInputCoordinatesDataView(
            mojo::ArrayDataView<::gfx::mojom::PointFDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInputCoordinates(UserType* output)
        {
            auto* pointer = data_->input_coordinates.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::gfx::mojom::PointFDataView>>(
                pointer, output, context_);
        }
        int64_t trace_id() const
        {
            return data_->trace_id;
        }
        bool coalesced() const
        {
            return data_->coalesced;
        }
        bool terminated() const
        {
            return data_->terminated;
        }

    private:
        internal::LatencyInfo_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace ui

namespace std {

template <>
struct hash<::ui::mojom::LatencyComponentType>
    : public mojo::internal::EnumHashImpl<::ui::mojom::LatencyComponentType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::ui::mojom::LatencyComponentType, ::ui::mojom::LatencyComponentType> {
    static ::ui::mojom::LatencyComponentType ToMojom(::ui::mojom::LatencyComponentType input) { return input; }
    static bool FromMojom(::ui::mojom::LatencyComponentType input, ::ui::mojom::LatencyComponentType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::LatencyComponentType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::ui::mojom::LatencyComponentType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::ui::mojom::LatencyComponentType>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::LatencyComponentIdDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::LatencyComponentIdDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::LatencyComponentId_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::LatencyComponentId_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::LatencyComponentId_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::ui::mojom::LatencyComponentType>(
                CallWithContext(Traits::type, input, custom_context), &result->type);
            result->id = CallWithContext(Traits::id, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::LatencyComponentId_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::LatencyComponentIdDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::LatencyComponentDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::LatencyComponentDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::LatencyComponent_Data);
            decltype(CallWithContext(Traits::event_time, input, custom_context)) in_event_time = CallWithContext(Traits::event_time, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeTicksDataView>(
                in_event_time, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::LatencyComponent_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::LatencyComponent_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->sequence_number = CallWithContext(Traits::sequence_number, input, custom_context);
            decltype(CallWithContext(Traits::event_time, input, custom_context)) in_event_time = CallWithContext(Traits::event_time, input, custom_context);
            typename decltype(result->event_time)::BaseType* event_time_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::TimeTicksDataView>(
                in_event_time, buffer, &event_time_ptr, context);
            result->event_time.Set(event_time_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->event_time.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null event_time in LatencyComponent struct");
            result->event_count = CallWithContext(Traits::event_count, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::LatencyComponent_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::LatencyComponentDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::LatencyComponentPairDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::LatencyComponentPairDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::LatencyComponentPair_Data);
            decltype(CallWithContext(Traits::key, input, custom_context)) in_key = CallWithContext(Traits::key, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::ui::mojom::LatencyComponentIdDataView>(
                in_key, context);
            decltype(CallWithContext(Traits::value, input, custom_context)) in_value = CallWithContext(Traits::value, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::ui::mojom::LatencyComponentDataView>(
                in_value, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::LatencyComponentPair_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::LatencyComponentPair_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::key, input, custom_context)) in_key = CallWithContext(Traits::key, input, custom_context);
            typename decltype(result->key)::BaseType* key_ptr;
            mojo::internal::Serialize<::ui::mojom::LatencyComponentIdDataView>(
                in_key, buffer, &key_ptr, context);
            result->key.Set(key_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->key.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null key in LatencyComponentPair struct");
            decltype(CallWithContext(Traits::value, input, custom_context)) in_value = CallWithContext(Traits::value, input, custom_context);
            typename decltype(result->value)::BaseType* value_ptr;
            mojo::internal::Serialize<::ui::mojom::LatencyComponentDataView>(
                in_value, buffer, &value_ptr, context);
            result->value.Set(value_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->value.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null value in LatencyComponentPair struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::LatencyComponentPair_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::LatencyComponentPairDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::LatencyInfoDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::LatencyInfoDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::LatencyInfo_Data);
            decltype(CallWithContext(Traits::trace_name, input, custom_context)) in_trace_name = CallWithContext(Traits::trace_name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_trace_name, context);
            decltype(CallWithContext(Traits::latency_components, input, custom_context)) in_latency_components = CallWithContext(Traits::latency_components, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::ui::mojom::LatencyComponentPairDataView>>(
                in_latency_components, context);
            decltype(CallWithContext(Traits::input_coordinates, input, custom_context)) in_input_coordinates = CallWithContext(Traits::input_coordinates, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::gfx::mojom::PointFDataView>>(
                in_input_coordinates, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::LatencyInfo_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::LatencyInfo_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::trace_name, input, custom_context)) in_trace_name = CallWithContext(Traits::trace_name, input, custom_context);
            typename decltype(result->trace_name)::BaseType* trace_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_trace_name, buffer, &trace_name_ptr, context);
            result->trace_name.Set(trace_name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->trace_name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null trace_name in LatencyInfo struct");
            decltype(CallWithContext(Traits::latency_components, input, custom_context)) in_latency_components = CallWithContext(Traits::latency_components, input, custom_context);
            typename decltype(result->latency_components)::BaseType* latency_components_ptr;
            const mojo::internal::ContainerValidateParams latency_components_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::ui::mojom::LatencyComponentPairDataView>>(
                in_latency_components, buffer, &latency_components_ptr, &latency_components_validate_params,
                context);
            result->latency_components.Set(latency_components_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->latency_components.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null latency_components in LatencyInfo struct");
            decltype(CallWithContext(Traits::input_coordinates, input, custom_context)) in_input_coordinates = CallWithContext(Traits::input_coordinates, input, custom_context);
            typename decltype(result->input_coordinates)::BaseType* input_coordinates_ptr;
            const mojo::internal::ContainerValidateParams input_coordinates_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::gfx::mojom::PointFDataView>>(
                in_input_coordinates, buffer, &input_coordinates_ptr, &input_coordinates_validate_params,
                context);
            result->input_coordinates.Set(input_coordinates_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->input_coordinates.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null input_coordinates in LatencyInfo struct");
            result->trace_id = CallWithContext(Traits::trace_id, input, custom_context);
            result->coalesced = CallWithContext(Traits::coalesced, input, custom_context);
            result->terminated = CallWithContext(Traits::terminated, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::LatencyInfo_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::LatencyInfoDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace ui {
namespace mojom {

    inline void LatencyComponentDataView::GetEventTimeDataView(
        ::mojo::common::mojom::TimeTicksDataView* output)
    {
        auto pointer = data_->event_time.Get();
        *output = ::mojo::common::mojom::TimeTicksDataView(pointer, context_);
    }

    inline void LatencyComponentPairDataView::GetKeyDataView(
        LatencyComponentIdDataView* output)
    {
        auto pointer = data_->key.Get();
        *output = LatencyComponentIdDataView(pointer, context_);
    }
    inline void LatencyComponentPairDataView::GetValueDataView(
        LatencyComponentDataView* output)
    {
        auto pointer = data_->value.Get();
        *output = LatencyComponentDataView(pointer, context_);
    }

    inline void LatencyInfoDataView::GetTraceNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->trace_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void LatencyInfoDataView::GetLatencyComponentsDataView(
        mojo::ArrayDataView<LatencyComponentPairDataView>* output)
    {
        auto pointer = data_->latency_components.Get();
        *output = mojo::ArrayDataView<LatencyComponentPairDataView>(pointer, context_);
    }
    inline void LatencyInfoDataView::GetInputCoordinatesDataView(
        mojo::ArrayDataView<::gfx::mojom::PointFDataView>* output)
    {
        auto pointer = data_->input_coordinates.Get();
        *output = mojo::ArrayDataView<::gfx::mojom::PointFDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace ui

#endif // UI_EVENTS_MOJO_LATENCY_INFO_MOJOM_SHARED_H_
