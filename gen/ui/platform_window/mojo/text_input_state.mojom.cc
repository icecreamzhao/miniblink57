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

#include "ui/platform_window/mojo/text_input_state.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
namespace mojo { // static
TextInputStatePtr TextInputState::New()
{
    TextInputStatePtr rv;
    mojo::internal::StructHelper<TextInputState>::Initialize(&rv);
    return rv;
}

TextInputState::TextInputState()
    : type()
    , flags()
    , text()
    , selection_start()
    , selection_end()
    , composition_start()
    , composition_end()
    , can_compose_inline()
{
}

TextInputState::~TextInputState()
{
}
} // namespace mojo

namespace mojo {

// static
bool StructTraits<::mojo::TextInputState::DataView, ::mojo::TextInputStatePtr>::Read(
    ::mojo::TextInputState::DataView input,
    ::mojo::TextInputStatePtr* output)
{
    bool success = true;
    ::mojo::TextInputStatePtr result(::mojo::TextInputState::New());

    if (!input.ReadType(&result->type))
        success = false;
    result->flags = input.flags();
    if (!input.ReadText(&result->text))
        success = false;
    result->selection_start = input.selection_start();
    result->selection_end = input.selection_end();
    result->composition_start = input.composition_start();
    result->composition_end = input.composition_end();
    result->can_compose_inline = input.can_compose_inline();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif