// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_EVENT_MATCHER_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_EVENT_MATCHER_MOJOM_SHARED_H_

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
#include "services/ui/public/interfaces/event_matcher.mojom-shared-internal.h"
#include "ui/events/mojo/event_constants.mojom-shared.h"
#include "ui/events/mojo/keyboard_codes.mojom-shared.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace ui {
namespace mojom {
    class KeyEventMatcherDataView;

    class PointerKindMatcherDataView;

    class PointerLocationMatcherDataView;

    class EventTypeMatcherDataView;

    class EventFlagsMatcherDataView;

    class EventMatcherDataView;

} // namespace mojom
} // namespace ui

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::ui::mojom::KeyEventMatcherDataView> {
        using Data = ::ui::mojom::internal::KeyEventMatcher_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::ui::mojom::PointerKindMatcherDataView> {
        using Data = ::ui::mojom::internal::PointerKindMatcher_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::ui::mojom::PointerLocationMatcherDataView> {
        using Data = ::ui::mojom::internal::PointerLocationMatcher_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::ui::mojom::EventTypeMatcherDataView> {
        using Data = ::ui::mojom::internal::EventTypeMatcher_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::ui::mojom::EventFlagsMatcherDataView> {
        using Data = ::ui::mojom::internal::EventFlagsMatcher_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::ui::mojom::EventMatcherDataView> {
        using Data = ::ui::mojom::internal::EventMatcher_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace ui {
namespace mojom {
    class KeyEventMatcherDataView {
    public:
        KeyEventMatcherDataView() { }

        KeyEventMatcherDataView(
            internal::KeyEventMatcher_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKeyboardCode(UserType* output) const
        {
            auto data_value = data_->keyboard_code;
            return mojo::internal::Deserialize<::ui::mojom::KeyboardCode>(
                data_value, output);
        }

        ::ui::mojom::KeyboardCode keyboard_code() const
        {
            return static_cast<::ui::mojom::KeyboardCode>(data_->keyboard_code);
        }

    private:
        internal::KeyEventMatcher_Data* data_ = nullptr;
    };

    class PointerKindMatcherDataView {
    public:
        PointerKindMatcherDataView() { }

        PointerKindMatcherDataView(
            internal::PointerKindMatcher_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPointerKind(UserType* output) const
        {
            auto data_value = data_->pointer_kind;
            return mojo::internal::Deserialize<::ui::mojom::PointerKind>(
                data_value, output);
        }

        ::ui::mojom::PointerKind pointer_kind() const
        {
            return static_cast<::ui::mojom::PointerKind>(data_->pointer_kind);
        }

    private:
        internal::PointerKindMatcher_Data* data_ = nullptr;
    };

    class PointerLocationMatcherDataView {
    public:
        PointerLocationMatcherDataView() { }

        PointerLocationMatcherDataView(
            internal::PointerLocationMatcher_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetRegionDataView(
            ::gfx::mojom::RectFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRegion(UserType* output)
        {
            auto* pointer = data_->region.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectFDataView>(
                pointer, output, context_);
        }

    private:
        internal::PointerLocationMatcher_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class EventTypeMatcherDataView {
    public:
        EventTypeMatcherDataView() { }

        EventTypeMatcherDataView(
            internal::EventTypeMatcher_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::ui::mojom::EventType>(
                data_value, output);
        }

        ::ui::mojom::EventType type() const
        {
            return static_cast<::ui::mojom::EventType>(data_->type);
        }

    private:
        internal::EventTypeMatcher_Data* data_ = nullptr;
    };

    class EventFlagsMatcherDataView {
    public:
        EventFlagsMatcherDataView() { }

        EventFlagsMatcherDataView(
            internal::EventFlagsMatcher_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t flags() const
        {
            return data_->flags;
        }

    private:
        internal::EventFlagsMatcher_Data* data_ = nullptr;
    };

    class EventMatcherDataView {
    public:
        EventMatcherDataView() { }

        EventMatcherDataView(
            internal::EventMatcher_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAcceleratorPhase(UserType* output) const
        {
            auto data_value = data_->accelerator_phase;
            return mojo::internal::Deserialize<::ui::mojom::AcceleratorPhase>(
                data_value, output);
        }

        ::ui::mojom::AcceleratorPhase accelerator_phase() const
        {
            return static_cast<::ui::mojom::AcceleratorPhase>(data_->accelerator_phase);
        }
        inline void GetTypeMatcherDataView(
            EventTypeMatcherDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTypeMatcher(UserType* output)
        {
            auto* pointer = data_->type_matcher.Get();
            return mojo::internal::Deserialize<::ui::mojom::EventTypeMatcherDataView>(
                pointer, output, context_);
        }
        inline void GetFlagsMatcherDataView(
            EventFlagsMatcherDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFlagsMatcher(UserType* output)
        {
            auto* pointer = data_->flags_matcher.Get();
            return mojo::internal::Deserialize<::ui::mojom::EventFlagsMatcherDataView>(
                pointer, output, context_);
        }
        inline void GetIgnoreFlagsMatcherDataView(
            EventFlagsMatcherDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIgnoreFlagsMatcher(UserType* output)
        {
            auto* pointer = data_->ignore_flags_matcher.Get();
            return mojo::internal::Deserialize<::ui::mojom::EventFlagsMatcherDataView>(
                pointer, output, context_);
        }
        inline void GetKeyMatcherDataView(
            KeyEventMatcherDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKeyMatcher(UserType* output)
        {
            auto* pointer = data_->key_matcher.Get();
            return mojo::internal::Deserialize<::ui::mojom::KeyEventMatcherDataView>(
                pointer, output, context_);
        }
        inline void GetPointerKindMatcherDataView(
            PointerKindMatcherDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPointerKindMatcher(UserType* output)
        {
            auto* pointer = data_->pointer_kind_matcher.Get();
            return mojo::internal::Deserialize<::ui::mojom::PointerKindMatcherDataView>(
                pointer, output, context_);
        }
        inline void GetPointerLocationMatcherDataView(
            PointerLocationMatcherDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPointerLocationMatcher(UserType* output)
        {
            auto* pointer = data_->pointer_location_matcher.Get();
            return mojo::internal::Deserialize<::ui::mojom::PointerLocationMatcherDataView>(
                pointer, output, context_);
        }

    private:
        internal::EventMatcher_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace ui

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::KeyEventMatcherDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::KeyEventMatcherDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::KeyEventMatcher_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::KeyEventMatcher_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::KeyEventMatcher_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::ui::mojom::KeyboardCode>(
                CallWithContext(Traits::keyboard_code, input, custom_context), &result->keyboard_code);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::KeyEventMatcher_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::KeyEventMatcherDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::PointerKindMatcherDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::PointerKindMatcherDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::PointerKindMatcher_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::PointerKindMatcher_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::PointerKindMatcher_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::ui::mojom::PointerKind>(
                CallWithContext(Traits::pointer_kind, input, custom_context), &result->pointer_kind);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::PointerKindMatcher_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::PointerKindMatcherDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::PointerLocationMatcherDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::PointerLocationMatcherDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::PointerLocationMatcher_Data);
            decltype(CallWithContext(Traits::region, input, custom_context)) in_region = CallWithContext(Traits::region, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectFDataView>(
                in_region, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::PointerLocationMatcher_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::PointerLocationMatcher_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::region, input, custom_context)) in_region = CallWithContext(Traits::region, input, custom_context);
            typename decltype(result->region)::BaseType* region_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectFDataView>(
                in_region, buffer, &region_ptr, context);
            result->region.Set(region_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->region.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null region in PointerLocationMatcher struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::PointerLocationMatcher_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::PointerLocationMatcherDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::EventTypeMatcherDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::EventTypeMatcherDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::EventTypeMatcher_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::EventTypeMatcher_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::EventTypeMatcher_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::ui::mojom::EventType>(
                CallWithContext(Traits::type, input, custom_context), &result->type);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::EventTypeMatcher_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::EventTypeMatcherDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::EventFlagsMatcherDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::EventFlagsMatcherDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::EventFlagsMatcher_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::EventFlagsMatcher_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::EventFlagsMatcher_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->flags = CallWithContext(Traits::flags, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::EventFlagsMatcher_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::EventFlagsMatcherDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::EventMatcherDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::EventMatcherDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::EventMatcher_Data);
            decltype(CallWithContext(Traits::type_matcher, input, custom_context)) in_type_matcher = CallWithContext(Traits::type_matcher, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::ui::mojom::EventTypeMatcherDataView>(
                in_type_matcher, context);
            decltype(CallWithContext(Traits::flags_matcher, input, custom_context)) in_flags_matcher = CallWithContext(Traits::flags_matcher, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::ui::mojom::EventFlagsMatcherDataView>(
                in_flags_matcher, context);
            decltype(CallWithContext(Traits::ignore_flags_matcher, input, custom_context)) in_ignore_flags_matcher = CallWithContext(Traits::ignore_flags_matcher, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::ui::mojom::EventFlagsMatcherDataView>(
                in_ignore_flags_matcher, context);
            decltype(CallWithContext(Traits::key_matcher, input, custom_context)) in_key_matcher = CallWithContext(Traits::key_matcher, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::ui::mojom::KeyEventMatcherDataView>(
                in_key_matcher, context);
            decltype(CallWithContext(Traits::pointer_kind_matcher, input, custom_context)) in_pointer_kind_matcher = CallWithContext(Traits::pointer_kind_matcher, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::ui::mojom::PointerKindMatcherDataView>(
                in_pointer_kind_matcher, context);
            decltype(CallWithContext(Traits::pointer_location_matcher, input, custom_context)) in_pointer_location_matcher = CallWithContext(Traits::pointer_location_matcher, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::ui::mojom::PointerLocationMatcherDataView>(
                in_pointer_location_matcher, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::EventMatcher_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::EventMatcher_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::ui::mojom::AcceleratorPhase>(
                CallWithContext(Traits::accelerator_phase, input, custom_context), &result->accelerator_phase);
            decltype(CallWithContext(Traits::type_matcher, input, custom_context)) in_type_matcher = CallWithContext(Traits::type_matcher, input, custom_context);
            typename decltype(result->type_matcher)::BaseType* type_matcher_ptr;
            mojo::internal::Serialize<::ui::mojom::EventTypeMatcherDataView>(
                in_type_matcher, buffer, &type_matcher_ptr, context);
            result->type_matcher.Set(type_matcher_ptr);
            decltype(CallWithContext(Traits::flags_matcher, input, custom_context)) in_flags_matcher = CallWithContext(Traits::flags_matcher, input, custom_context);
            typename decltype(result->flags_matcher)::BaseType* flags_matcher_ptr;
            mojo::internal::Serialize<::ui::mojom::EventFlagsMatcherDataView>(
                in_flags_matcher, buffer, &flags_matcher_ptr, context);
            result->flags_matcher.Set(flags_matcher_ptr);
            decltype(CallWithContext(Traits::ignore_flags_matcher, input, custom_context)) in_ignore_flags_matcher = CallWithContext(Traits::ignore_flags_matcher, input, custom_context);
            typename decltype(result->ignore_flags_matcher)::BaseType* ignore_flags_matcher_ptr;
            mojo::internal::Serialize<::ui::mojom::EventFlagsMatcherDataView>(
                in_ignore_flags_matcher, buffer, &ignore_flags_matcher_ptr, context);
            result->ignore_flags_matcher.Set(ignore_flags_matcher_ptr);
            decltype(CallWithContext(Traits::key_matcher, input, custom_context)) in_key_matcher = CallWithContext(Traits::key_matcher, input, custom_context);
            typename decltype(result->key_matcher)::BaseType* key_matcher_ptr;
            mojo::internal::Serialize<::ui::mojom::KeyEventMatcherDataView>(
                in_key_matcher, buffer, &key_matcher_ptr, context);
            result->key_matcher.Set(key_matcher_ptr);
            decltype(CallWithContext(Traits::pointer_kind_matcher, input, custom_context)) in_pointer_kind_matcher = CallWithContext(Traits::pointer_kind_matcher, input, custom_context);
            typename decltype(result->pointer_kind_matcher)::BaseType* pointer_kind_matcher_ptr;
            mojo::internal::Serialize<::ui::mojom::PointerKindMatcherDataView>(
                in_pointer_kind_matcher, buffer, &pointer_kind_matcher_ptr, context);
            result->pointer_kind_matcher.Set(pointer_kind_matcher_ptr);
            decltype(CallWithContext(Traits::pointer_location_matcher, input, custom_context)) in_pointer_location_matcher = CallWithContext(Traits::pointer_location_matcher, input, custom_context);
            typename decltype(result->pointer_location_matcher)::BaseType* pointer_location_matcher_ptr;
            mojo::internal::Serialize<::ui::mojom::PointerLocationMatcherDataView>(
                in_pointer_location_matcher, buffer, &pointer_location_matcher_ptr, context);
            result->pointer_location_matcher.Set(pointer_location_matcher_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::EventMatcher_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::EventMatcherDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace ui {
namespace mojom {

    inline void PointerLocationMatcherDataView::GetRegionDataView(
        ::gfx::mojom::RectFDataView* output)
    {
        auto pointer = data_->region.Get();
        *output = ::gfx::mojom::RectFDataView(pointer, context_);
    }

    inline void EventMatcherDataView::GetTypeMatcherDataView(
        EventTypeMatcherDataView* output)
    {
        auto pointer = data_->type_matcher.Get();
        *output = EventTypeMatcherDataView(pointer, context_);
    }
    inline void EventMatcherDataView::GetFlagsMatcherDataView(
        EventFlagsMatcherDataView* output)
    {
        auto pointer = data_->flags_matcher.Get();
        *output = EventFlagsMatcherDataView(pointer, context_);
    }
    inline void EventMatcherDataView::GetIgnoreFlagsMatcherDataView(
        EventFlagsMatcherDataView* output)
    {
        auto pointer = data_->ignore_flags_matcher.Get();
        *output = EventFlagsMatcherDataView(pointer, context_);
    }
    inline void EventMatcherDataView::GetKeyMatcherDataView(
        KeyEventMatcherDataView* output)
    {
        auto pointer = data_->key_matcher.Get();
        *output = KeyEventMatcherDataView(pointer, context_);
    }
    inline void EventMatcherDataView::GetPointerKindMatcherDataView(
        PointerKindMatcherDataView* output)
    {
        auto pointer = data_->pointer_kind_matcher.Get();
        *output = PointerKindMatcherDataView(pointer, context_);
    }
    inline void EventMatcherDataView::GetPointerLocationMatcherDataView(
        PointerLocationMatcherDataView* output)
    {
        auto pointer = data_->pointer_location_matcher.Get();
        *output = PointerLocationMatcherDataView(pointer, context_);
    }

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_EVENT_MATCHER_MOJOM_SHARED_H_
