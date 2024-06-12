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

#include "gpu/ipc/common/mailbox_holder.mojom-blink.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/Source/platform/mojo/CommonCustomTypesStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/GeometryStructTraits.h"
namespace gpu {
namespace mojom {
    namespace blink { // static
        MailboxHolderPtr MailboxHolder::New()
        {
            MailboxHolderPtr rv;
            mojo::internal::StructHelper<MailboxHolder>::Initialize(&rv);
            return rv;
        }

        MailboxHolder::MailboxHolder()
            : mailbox()
            , sync_token()
            , texture_target()
        {
        }

        MailboxHolder::~MailboxHolder()
        {
        }
    } // namespace blink
} // namespace mojom
} // namespace gpu

namespace mojo {

// static
bool StructTraits<::gpu::mojom::blink::MailboxHolder::DataView, ::gpu::mojom::blink::MailboxHolderPtr>::Read(
    ::gpu::mojom::blink::MailboxHolder::DataView input,
    ::gpu::mojom::blink::MailboxHolderPtr* output)
{
    bool success = true;
    ::gpu::mojom::blink::MailboxHolderPtr result(::gpu::mojom::blink::MailboxHolder::New());

    if (!input.ReadMailbox(&result->mailbox))
        success = false;
    if (!input.ReadSyncToken(&result->sync_token))
        success = false;
    result->texture_target = input.texture_target();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif