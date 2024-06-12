// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_MOJOM_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
#include "content/common/bluetooth/web_bluetooth_device_id.h"
#include "content/common/content_export.h"
#include "content/public/common/media_metadata.h"
#include "content/public/common/referrer.h"
#include "device/bluetooth/bluetooth_uuid.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/control_message_proxy.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/lib/union_accessor.h"
#include "mojo/public/cpp/bindings/native_struct.h"
#include "mojo/public/cpp/bindings/no_interface.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"
#include "mojo/public/cpp/bindings/union_traits.h"
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/platform/modules/notifications/notification.mojom-shared.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "url/gurl.h"
#include "url/origin.h"
#include <string>
#include <vector>

namespace blink {
namespace mojom {
    class NotificationAction;
    using NotificationActionPtr = mojo::StructPtr<NotificationAction>;

    class Notification;
    using NotificationPtr = mojo::StructPtr<Notification>;

    class CONTENT_EXPORT NotificationAction {
    public:
        using DataView = NotificationActionDataView;
        using Data_ = internal::NotificationAction_Data;

        static NotificationActionPtr New();

        template <typename U>
        static NotificationActionPtr From(const U& u)
        {
            return mojo::TypeConverter<NotificationActionPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, NotificationAction>::Convert(*this);
        }

        NotificationAction();
        ~NotificationAction();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = NotificationActionPtr>
        NotificationActionPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, NotificationAction>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                NotificationAction::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                NotificationAction::DataView, std::vector<uint8_t>>(
                input, output);
        }

        NotificationActionType type;
        std::string action;
        std::string title;
        std::string icon;
        base::Optional<std::string> placeholder;
    };

    class CONTENT_EXPORT Notification {
    public:
        using DataView = NotificationDataView;
        using Data_ = internal::Notification_Data;
        static constexpr int32_t kMaximumDeveloperDataBytes = 1048576;

        static NotificationPtr New();

        template <typename U>
        static NotificationPtr From(const U& u)
        {
            return mojo::TypeConverter<NotificationPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Notification>::Convert(*this);
        }

        Notification();
        ~Notification();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = NotificationPtr>
        NotificationPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Notification>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Notification::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Notification::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string title;
        NotificationDirection direction;
        base::Optional<std::string> lang;
        std::string body;
        std::string tag;
        std::string icon;
        std::string badge;
        std::vector<uint32_t> vibration_pattern;
        double timestamp;
        bool renotify;
        bool silent;
        bool require_interaction;
        std::vector<int8_t> data;
        std::vector<NotificationActionPtr> actions;

    private:
        DISALLOW_COPY_AND_ASSIGN(Notification);
    };

    template <typename StructPtrType>
    NotificationActionPtr NotificationAction::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->type = mojo::internal::Clone(type);
        rv->action = mojo::internal::Clone(action);
        rv->title = mojo::internal::Clone(title);
        rv->icon = mojo::internal::Clone(icon);
        rv->placeholder = mojo::internal::Clone(placeholder);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, NotificationAction>::value>::type*>
    bool NotificationAction::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->type, other.type))
            return false;
        if (!mojo::internal::Equals(this->action, other.action))
            return false;
        if (!mojo::internal::Equals(this->title, other.title))
            return false;
        if (!mojo::internal::Equals(this->icon, other.icon))
            return false;
        if (!mojo::internal::Equals(this->placeholder, other.placeholder))
            return false;
        return true;
    }
    template <typename StructPtrType>
    NotificationPtr Notification::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->title = mojo::internal::Clone(title);
        rv->direction = mojo::internal::Clone(direction);
        rv->lang = mojo::internal::Clone(lang);
        rv->body = mojo::internal::Clone(body);
        rv->tag = mojo::internal::Clone(tag);
        rv->icon = mojo::internal::Clone(icon);
        rv->badge = mojo::internal::Clone(badge);
        rv->vibration_pattern = mojo::internal::Clone(vibration_pattern);
        rv->timestamp = mojo::internal::Clone(timestamp);
        rv->renotify = mojo::internal::Clone(renotify);
        rv->silent = mojo::internal::Clone(silent);
        rv->require_interaction = mojo::internal::Clone(require_interaction);
        rv->data = mojo::internal::Clone(data);
        rv->actions = mojo::internal::Clone(actions);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Notification>::value>::type*>
    bool Notification::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->title, other.title))
            return false;
        if (!mojo::internal::Equals(this->direction, other.direction))
            return false;
        if (!mojo::internal::Equals(this->lang, other.lang))
            return false;
        if (!mojo::internal::Equals(this->body, other.body))
            return false;
        if (!mojo::internal::Equals(this->tag, other.tag))
            return false;
        if (!mojo::internal::Equals(this->icon, other.icon))
            return false;
        if (!mojo::internal::Equals(this->badge, other.badge))
            return false;
        if (!mojo::internal::Equals(this->vibration_pattern, other.vibration_pattern))
            return false;
        if (!mojo::internal::Equals(this->timestamp, other.timestamp))
            return false;
        if (!mojo::internal::Equals(this->renotify, other.renotify))
            return false;
        if (!mojo::internal::Equals(this->silent, other.silent))
            return false;
        if (!mojo::internal::Equals(this->require_interaction, other.require_interaction))
            return false;
        if (!mojo::internal::Equals(this->data, other.data))
            return false;
        if (!mojo::internal::Equals(this->actions, other.actions))
            return false;
        return true;
    }

} // namespace mojom
} // namespace blink

namespace mojo {

template <>
struct CONTENT_EXPORT StructTraits<::blink::mojom::NotificationAction::DataView,
    ::blink::mojom::NotificationActionPtr> {
    static bool IsNull(const ::blink::mojom::NotificationActionPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::NotificationActionPtr* output) { output->reset(); }

    static decltype(::blink::mojom::NotificationAction::type) type(
        const ::blink::mojom::NotificationActionPtr& input)
    {
        return input->type;
    }

    static const decltype(::blink::mojom::NotificationAction::action)& action(
        const ::blink::mojom::NotificationActionPtr& input)
    {
        return input->action;
    }

    static const decltype(::blink::mojom::NotificationAction::title)& title(
        const ::blink::mojom::NotificationActionPtr& input)
    {
        return input->title;
    }

    static const decltype(::blink::mojom::NotificationAction::icon)& icon(
        const ::blink::mojom::NotificationActionPtr& input)
    {
        return input->icon;
    }

    static const decltype(::blink::mojom::NotificationAction::placeholder)& placeholder(
        const ::blink::mojom::NotificationActionPtr& input)
    {
        return input->placeholder;
    }

    static bool Read(::blink::mojom::NotificationAction::DataView input, ::blink::mojom::NotificationActionPtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::blink::mojom::Notification::DataView,
    ::blink::mojom::NotificationPtr> {
    static bool IsNull(const ::blink::mojom::NotificationPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::NotificationPtr* output) { output->reset(); }

    static const decltype(::blink::mojom::Notification::title)& title(
        const ::blink::mojom::NotificationPtr& input)
    {
        return input->title;
    }

    static decltype(::blink::mojom::Notification::direction) direction(
        const ::blink::mojom::NotificationPtr& input)
    {
        return input->direction;
    }

    static const decltype(::blink::mojom::Notification::lang)& lang(
        const ::blink::mojom::NotificationPtr& input)
    {
        return input->lang;
    }

    static const decltype(::blink::mojom::Notification::body)& body(
        const ::blink::mojom::NotificationPtr& input)
    {
        return input->body;
    }

    static const decltype(::blink::mojom::Notification::tag)& tag(
        const ::blink::mojom::NotificationPtr& input)
    {
        return input->tag;
    }

    static const decltype(::blink::mojom::Notification::icon)& icon(
        const ::blink::mojom::NotificationPtr& input)
    {
        return input->icon;
    }

    static const decltype(::blink::mojom::Notification::badge)& badge(
        const ::blink::mojom::NotificationPtr& input)
    {
        return input->badge;
    }

    static const decltype(::blink::mojom::Notification::vibration_pattern)& vibration_pattern(
        const ::blink::mojom::NotificationPtr& input)
    {
        return input->vibration_pattern;
    }

    static decltype(::blink::mojom::Notification::timestamp) timestamp(
        const ::blink::mojom::NotificationPtr& input)
    {
        return input->timestamp;
    }

    static decltype(::blink::mojom::Notification::renotify) renotify(
        const ::blink::mojom::NotificationPtr& input)
    {
        return input->renotify;
    }

    static decltype(::blink::mojom::Notification::silent) silent(
        const ::blink::mojom::NotificationPtr& input)
    {
        return input->silent;
    }

    static decltype(::blink::mojom::Notification::require_interaction) require_interaction(
        const ::blink::mojom::NotificationPtr& input)
    {
        return input->require_interaction;
    }

    static const decltype(::blink::mojom::Notification::data)& data(
        const ::blink::mojom::NotificationPtr& input)
    {
        return input->data;
    }

    static const decltype(::blink::mojom::Notification::actions)& actions(
        const ::blink::mojom::NotificationPtr& input)
    {
        return input->actions;
    }

    static bool Read(::blink::mojom::Notification::DataView input, ::blink::mojom::NotificationPtr* output);
};

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_MOJOM_H_