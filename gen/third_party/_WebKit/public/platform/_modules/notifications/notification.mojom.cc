// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4056)
#pragma warning(disable : 4065)
#pragma warning(disable : 4756)
#endif

#include "third_party/WebKit/public/platform/modules/notifications/notification.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "content/common/bluetooth/web_bluetooth_device_id_struct_traits.h"
#include "content/common/media/media_session_struct_traits.h"
#include "content/public/common/referrer_struct_traits.h"
#include "device/bluetooth/public/interfaces/uuid_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/public/platform/ReferrerPolicyEnumTraits.h"
#include "third_party/WebKit/public/web/ConsoleMessageStructTraits.h"
#include "third_party/WebKit/public/web/WindowFeaturesStructTraits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "url/mojo/origin_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace blink {
namespace mojom { // static
    NotificationActionPtr NotificationAction::New()
    {
        NotificationActionPtr rv;
        mojo::internal::StructHelper<NotificationAction>::Initialize(&rv);
        return rv;
    }

    NotificationAction::NotificationAction()
        : type()
        , action()
        , title()
        , icon()
        , placeholder()
    {
    }

    NotificationAction::~NotificationAction()
    {
    } // static
    NotificationPtr Notification::New()
    {
        NotificationPtr rv;
        mojo::internal::StructHelper<Notification>::Initialize(&rv);
        return rv;
    }

    Notification::Notification()
        : title()
        , direction()
        , lang()
        , body()
        , tag()
        , icon()
        , badge()
        , vibration_pattern()
        , timestamp()
        , renotify(false)
        , silent(false)
        , require_interaction(false)
        , data()
        , actions()
    {
    }

    Notification::~Notification()
    {
    }
} // namespace mojom
} // namespace blink

namespace mojo {

// static
bool StructTraits<::blink::mojom::NotificationAction::DataView, ::blink::mojom::NotificationActionPtr>::Read(
    ::blink::mojom::NotificationAction::DataView input,
    ::blink::mojom::NotificationActionPtr* output)
{
    bool success = true;
    ::blink::mojom::NotificationActionPtr result(::blink::mojom::NotificationAction::New());

    if (!input.ReadType(&result->type))
        success = false;
    if (!input.ReadAction(&result->action))
        success = false;
    if (!input.ReadTitle(&result->title))
        success = false;
    if (!input.ReadIcon(&result->icon))
        success = false;
    if (!input.ReadPlaceholder(&result->placeholder))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::blink::mojom::Notification::DataView, ::blink::mojom::NotificationPtr>::Read(
    ::blink::mojom::Notification::DataView input,
    ::blink::mojom::NotificationPtr* output)
{
    bool success = true;
    ::blink::mojom::NotificationPtr result(::blink::mojom::Notification::New());

    if (!input.ReadTitle(&result->title))
        success = false;
    if (!input.ReadDirection(&result->direction))
        success = false;
    if (!input.ReadLang(&result->lang))
        success = false;
    if (!input.ReadBody(&result->body))
        success = false;
    if (!input.ReadTag(&result->tag))
        success = false;
    if (!input.ReadIcon(&result->icon))
        success = false;
    if (!input.ReadBadge(&result->badge))
        success = false;
    if (!input.ReadVibrationPattern(&result->vibration_pattern))
        success = false;
    result->timestamp = input.timestamp();
    result->renotify = input.renotify();
    result->silent = input.silent();
    result->require_interaction = input.require_interaction();
    if (!input.ReadData(&result->data))
        success = false;
    if (!input.ReadActions(&result->actions))
        success = false;
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif