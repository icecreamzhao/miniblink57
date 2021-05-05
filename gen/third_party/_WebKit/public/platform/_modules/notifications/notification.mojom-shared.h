// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_MOJOM_SHARED_H_

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
#include "third_party/WebKit/public/platform/modules/notifications/notification.mojom-shared-internal.h"

namespace blink {
namespace mojom {
    class NotificationActionDataView;

    class NotificationDataView;

} // namespace mojom
} // namespace blink

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::blink::mojom::NotificationActionDataView> {
        using Data = ::blink::mojom::internal::NotificationAction_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::blink::mojom::NotificationDataView> {
        using Data = ::blink::mojom::internal::Notification_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace blink {
namespace mojom {

    enum class NotificationActionType : int32_t {
        BUTTON,
        TEXT,
    };

    inline std::ostream& operator<<(std::ostream& os, NotificationActionType value)
    {
        switch (value) {
        case NotificationActionType::BUTTON:
            return os << "NotificationActionType::BUTTON";
        case NotificationActionType::TEXT:
            return os << "NotificationActionType::TEXT";
        default:
            return os << "Unknown NotificationActionType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(NotificationActionType value)
    {
        return internal::NotificationActionType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class NotificationDirection : int32_t {
        LEFT_TO_RIGHT,
        RIGHT_TO_LEFT,
        AUTO,
    };

    inline std::ostream& operator<<(std::ostream& os, NotificationDirection value)
    {
        switch (value) {
        case NotificationDirection::LEFT_TO_RIGHT:
            return os << "NotificationDirection::LEFT_TO_RIGHT";
        case NotificationDirection::RIGHT_TO_LEFT:
            return os << "NotificationDirection::RIGHT_TO_LEFT";
        case NotificationDirection::AUTO:
            return os << "NotificationDirection::AUTO";
        default:
            return os << "Unknown NotificationDirection value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(NotificationDirection value)
    {
        return internal::NotificationDirection_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class NotificationActionDataView {
    public:
        NotificationActionDataView() { }

        NotificationActionDataView(
            internal::NotificationAction_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::blink::mojom::NotificationActionType>(
                data_value, output);
        }

        NotificationActionType type() const
        {
            return static_cast<NotificationActionType>(data_->type);
        }
        inline void GetActionDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAction(UserType* output)
        {
            auto* pointer = data_->action.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetTitleDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTitle(UserType* output)
        {
            auto* pointer = data_->title.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetIconDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIcon(UserType* output)
        {
            auto* pointer = data_->icon.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetPlaceholderDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPlaceholder(UserType* output)
        {
            auto* pointer = data_->placeholder.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::NotificationAction_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class NotificationDataView {
    public:
        NotificationDataView() { }

        NotificationDataView(
            internal::Notification_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTitleDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTitle(UserType* output)
        {
            auto* pointer = data_->title.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDirection(UserType* output) const
        {
            auto data_value = data_->direction;
            return mojo::internal::Deserialize<::blink::mojom::NotificationDirection>(
                data_value, output);
        }

        NotificationDirection direction() const
        {
            return static_cast<NotificationDirection>(data_->direction);
        }
        inline void GetLangDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLang(UserType* output)
        {
            auto* pointer = data_->lang.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetBodyDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBody(UserType* output)
        {
            auto* pointer = data_->body.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetTagDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTag(UserType* output)
        {
            auto* pointer = data_->tag.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetIconDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIcon(UserType* output)
        {
            auto* pointer = data_->icon.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetBadgeDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBadge(UserType* output)
        {
            auto* pointer = data_->badge.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetVibrationPatternDataView(
            mojo::ArrayDataView<uint32_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadVibrationPattern(UserType* output)
        {
            auto* pointer = data_->vibration_pattern.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint32_t>>(
                pointer, output, context_);
        }
        double timestamp() const
        {
            return data_->timestamp;
        }
        bool renotify() const
        {
            return data_->renotify;
        }
        bool silent() const
        {
            return data_->silent;
        }
        bool require_interaction() const
        {
            return data_->require_interaction;
        }
        inline void GetDataDataView(
            mojo::ArrayDataView<int8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<int8_t>>(
                pointer, output, context_);
        }
        inline void GetActionsDataView(
            mojo::ArrayDataView<NotificationActionDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadActions(UserType* output)
        {
            auto* pointer = data_->actions.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::blink::mojom::NotificationActionDataView>>(
                pointer, output, context_);
        }

    private:
        internal::Notification_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

template <>
struct hash<::blink::mojom::NotificationActionType>
    : public mojo::internal::EnumHashImpl<::blink::mojom::NotificationActionType> {
};

template <>
struct hash<::blink::mojom::NotificationDirection>
    : public mojo::internal::EnumHashImpl<::blink::mojom::NotificationDirection> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::blink::mojom::NotificationActionType, ::blink::mojom::NotificationActionType> {
    static ::blink::mojom::NotificationActionType ToMojom(::blink::mojom::NotificationActionType input) { return input; }
    static bool FromMojom(::blink::mojom::NotificationActionType input, ::blink::mojom::NotificationActionType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::NotificationActionType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::NotificationActionType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::NotificationActionType>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::blink::mojom::NotificationDirection, ::blink::mojom::NotificationDirection> {
    static ::blink::mojom::NotificationDirection ToMojom(::blink::mojom::NotificationDirection input) { return input; }
    static bool FromMojom(::blink::mojom::NotificationDirection input, ::blink::mojom::NotificationDirection* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::NotificationDirection, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::NotificationDirection, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::NotificationDirection>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::NotificationActionDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::NotificationActionDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::NotificationAction_Data);
            decltype(CallWithContext(Traits::action, input, custom_context)) in_action = CallWithContext(Traits::action, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_action, context);
            decltype(CallWithContext(Traits::title, input, custom_context)) in_title = CallWithContext(Traits::title, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_title, context);
            decltype(CallWithContext(Traits::icon, input, custom_context)) in_icon = CallWithContext(Traits::icon, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_icon, context);
            decltype(CallWithContext(Traits::placeholder, input, custom_context)) in_placeholder = CallWithContext(Traits::placeholder, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_placeholder, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::NotificationAction_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::NotificationAction_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::blink::mojom::NotificationActionType>(
                CallWithContext(Traits::type, input, custom_context), &result->type);
            decltype(CallWithContext(Traits::action, input, custom_context)) in_action = CallWithContext(Traits::action, input, custom_context);
            typename decltype(result->action)::BaseType* action_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_action, buffer, &action_ptr, context);
            result->action.Set(action_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->action.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null action in NotificationAction struct");
            decltype(CallWithContext(Traits::title, input, custom_context)) in_title = CallWithContext(Traits::title, input, custom_context);
            typename decltype(result->title)::BaseType* title_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_title, buffer, &title_ptr, context);
            result->title.Set(title_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->title.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null title in NotificationAction struct");
            decltype(CallWithContext(Traits::icon, input, custom_context)) in_icon = CallWithContext(Traits::icon, input, custom_context);
            typename decltype(result->icon)::BaseType* icon_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_icon, buffer, &icon_ptr, context);
            result->icon.Set(icon_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->icon.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null icon in NotificationAction struct");
            decltype(CallWithContext(Traits::placeholder, input, custom_context)) in_placeholder = CallWithContext(Traits::placeholder, input, custom_context);
            typename decltype(result->placeholder)::BaseType* placeholder_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_placeholder, buffer, &placeholder_ptr, context);
            result->placeholder.Set(placeholder_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::NotificationAction_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::NotificationActionDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::NotificationDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::NotificationDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::Notification_Data);
            decltype(CallWithContext(Traits::title, input, custom_context)) in_title = CallWithContext(Traits::title, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_title, context);
            decltype(CallWithContext(Traits::lang, input, custom_context)) in_lang = CallWithContext(Traits::lang, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_lang, context);
            decltype(CallWithContext(Traits::body, input, custom_context)) in_body = CallWithContext(Traits::body, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_body, context);
            decltype(CallWithContext(Traits::tag, input, custom_context)) in_tag = CallWithContext(Traits::tag, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_tag, context);
            decltype(CallWithContext(Traits::icon, input, custom_context)) in_icon = CallWithContext(Traits::icon, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_icon, context);
            decltype(CallWithContext(Traits::badge, input, custom_context)) in_badge = CallWithContext(Traits::badge, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_badge, context);
            decltype(CallWithContext(Traits::vibration_pattern, input, custom_context)) in_vibration_pattern = CallWithContext(Traits::vibration_pattern, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint32_t>>(
                in_vibration_pattern, context);
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<int8_t>>(
                in_data, context);
            decltype(CallWithContext(Traits::actions, input, custom_context)) in_actions = CallWithContext(Traits::actions, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::blink::mojom::NotificationActionDataView>>(
                in_actions, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::Notification_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::Notification_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::title, input, custom_context)) in_title = CallWithContext(Traits::title, input, custom_context);
            typename decltype(result->title)::BaseType* title_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_title, buffer, &title_ptr, context);
            result->title.Set(title_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->title.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null title in Notification struct");
            mojo::internal::Serialize<::blink::mojom::NotificationDirection>(
                CallWithContext(Traits::direction, input, custom_context), &result->direction);
            decltype(CallWithContext(Traits::lang, input, custom_context)) in_lang = CallWithContext(Traits::lang, input, custom_context);
            typename decltype(result->lang)::BaseType* lang_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_lang, buffer, &lang_ptr, context);
            result->lang.Set(lang_ptr);
            decltype(CallWithContext(Traits::body, input, custom_context)) in_body = CallWithContext(Traits::body, input, custom_context);
            typename decltype(result->body)::BaseType* body_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_body, buffer, &body_ptr, context);
            result->body.Set(body_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->body.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null body in Notification struct");
            decltype(CallWithContext(Traits::tag, input, custom_context)) in_tag = CallWithContext(Traits::tag, input, custom_context);
            typename decltype(result->tag)::BaseType* tag_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_tag, buffer, &tag_ptr, context);
            result->tag.Set(tag_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->tag.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null tag in Notification struct");
            decltype(CallWithContext(Traits::icon, input, custom_context)) in_icon = CallWithContext(Traits::icon, input, custom_context);
            typename decltype(result->icon)::BaseType* icon_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_icon, buffer, &icon_ptr, context);
            result->icon.Set(icon_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->icon.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null icon in Notification struct");
            decltype(CallWithContext(Traits::badge, input, custom_context)) in_badge = CallWithContext(Traits::badge, input, custom_context);
            typename decltype(result->badge)::BaseType* badge_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_badge, buffer, &badge_ptr, context);
            result->badge.Set(badge_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->badge.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null badge in Notification struct");
            decltype(CallWithContext(Traits::vibration_pattern, input, custom_context)) in_vibration_pattern = CallWithContext(Traits::vibration_pattern, input, custom_context);
            typename decltype(result->vibration_pattern)::BaseType* vibration_pattern_ptr;
            const mojo::internal::ContainerValidateParams vibration_pattern_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint32_t>>(
                in_vibration_pattern, buffer, &vibration_pattern_ptr, &vibration_pattern_validate_params,
                context);
            result->vibration_pattern.Set(vibration_pattern_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->vibration_pattern.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null vibration_pattern in Notification struct");
            result->timestamp = CallWithContext(Traits::timestamp, input, custom_context);
            result->renotify = CallWithContext(Traits::renotify, input, custom_context);
            result->silent = CallWithContext(Traits::silent, input, custom_context);
            result->require_interaction = CallWithContext(Traits::require_interaction, input, custom_context);
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            typename decltype(result->data)::BaseType* data_ptr;
            const mojo::internal::ContainerValidateParams data_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<int8_t>>(
                in_data, buffer, &data_ptr, &data_validate_params,
                context);
            result->data.Set(data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null data in Notification struct");
            decltype(CallWithContext(Traits::actions, input, custom_context)) in_actions = CallWithContext(Traits::actions, input, custom_context);
            typename decltype(result->actions)::BaseType* actions_ptr;
            const mojo::internal::ContainerValidateParams actions_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::blink::mojom::NotificationActionDataView>>(
                in_actions, buffer, &actions_ptr, &actions_validate_params,
                context);
            result->actions.Set(actions_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->actions.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null actions in Notification struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::Notification_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::NotificationDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace blink {
namespace mojom {

    inline void NotificationActionDataView::GetActionDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->action.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void NotificationActionDataView::GetTitleDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->title.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void NotificationActionDataView::GetIconDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->icon.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void NotificationActionDataView::GetPlaceholderDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->placeholder.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void NotificationDataView::GetTitleDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->title.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void NotificationDataView::GetLangDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->lang.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void NotificationDataView::GetBodyDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->body.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void NotificationDataView::GetTagDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->tag.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void NotificationDataView::GetIconDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->icon.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void NotificationDataView::GetBadgeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->badge.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void NotificationDataView::GetVibrationPatternDataView(
        mojo::ArrayDataView<uint32_t>* output)
    {
        auto pointer = data_->vibration_pattern.Get();
        *output = mojo::ArrayDataView<uint32_t>(pointer, context_);
    }
    inline void NotificationDataView::GetDataDataView(
        mojo::ArrayDataView<int8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<int8_t>(pointer, context_);
    }
    inline void NotificationDataView::GetActionsDataView(
        mojo::ArrayDataView<NotificationActionDataView>* output)
    {
        auto pointer = data_->actions.Get();
        *output = mojo::ArrayDataView<NotificationActionDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_MOJOM_SHARED_H_
