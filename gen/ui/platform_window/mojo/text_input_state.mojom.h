// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_PLATFORM_WINDOW_MOJO_TEXT_INPUT_STATE_MOJOM_H_
#define UI_PLATFORM_WINDOW_MOJO_TEXT_INPUT_STATE_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
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
#include "ui/platform_window/mojo/text_input_state.mojom-shared.h"
#include <string>
#include <vector>

namespace mojo {
class TextInputState;
using TextInputStatePtr = mojo::StructPtr<TextInputState>;

class TextInputState {
public:
    using DataView = TextInputStateDataView;
    using Data_ = internal::TextInputState_Data;

    static TextInputStatePtr New();

    template <typename U>
    static TextInputStatePtr From(const U& u)
    {
        return mojo::TypeConverter<TextInputStatePtr, U>::Convert(u);
    }

    template <typename U>
    U To() const
    {
        return mojo::TypeConverter<U, TextInputState>::Convert(*this);
    }

    TextInputState();
    ~TextInputState();

    // Clone() is a template so it is only instantiated if it is used. Thus, the
    // bindings generator does not need to know whether Clone() or copy
    // constructor/assignment are available for members.
    template <typename StructPtrType = TextInputStatePtr>
    TextInputStatePtr Clone() const;

    // Equals() is a template so it is only instantiated if it is used. Thus, the
    // bindings generator does not need to know whether Equals() or == operator
    // are available for members.
    template <typename T,
        typename std::enable_if<std::is_same<
            T, TextInputState>::value>::type* = nullptr>
    bool Equals(const T& other) const;

    template <typename UserType>
    static std::vector<uint8_t> Serialize(UserType* input)
    {
        return mojo::internal::StructSerializeImpl<
            TextInputState::DataView, std::vector<uint8_t>>(input);
    }

    template <typename UserType>
    static bool Deserialize(const std::vector<uint8_t>& input,
        UserType* output)
    {
        return mojo::internal::StructDeserializeImpl<
            TextInputState::DataView, std::vector<uint8_t>>(
            input, output);
    }

    TextInputType type;
    int32_t flags;
    base::Optional<std::string> text;
    int32_t selection_start;
    int32_t selection_end;
    int32_t composition_start;
    int32_t composition_end;
    bool can_compose_inline;
};

template <typename StructPtrType>
TextInputStatePtr TextInputState::Clone() const
{
    // Use StructPtrType to prevent the compiler from trying to compile this
    // without being asked.
    StructPtrType rv(New());
    rv->type = mojo::internal::Clone(type);
    rv->flags = mojo::internal::Clone(flags);
    rv->text = mojo::internal::Clone(text);
    rv->selection_start = mojo::internal::Clone(selection_start);
    rv->selection_end = mojo::internal::Clone(selection_end);
    rv->composition_start = mojo::internal::Clone(composition_start);
    rv->composition_end = mojo::internal::Clone(composition_end);
    rv->can_compose_inline = mojo::internal::Clone(can_compose_inline);
    return rv;
}

template <typename T,
    typename std::enable_if<std::is_same<
        T, TextInputState>::value>::type*>
bool TextInputState::Equals(const T& other) const
{
    if (!mojo::internal::Equals(this->type, other.type))
        return false;
    if (!mojo::internal::Equals(this->flags, other.flags))
        return false;
    if (!mojo::internal::Equals(this->text, other.text))
        return false;
    if (!mojo::internal::Equals(this->selection_start, other.selection_start))
        return false;
    if (!mojo::internal::Equals(this->selection_end, other.selection_end))
        return false;
    if (!mojo::internal::Equals(this->composition_start, other.composition_start))
        return false;
    if (!mojo::internal::Equals(this->composition_end, other.composition_end))
        return false;
    if (!mojo::internal::Equals(this->can_compose_inline, other.can_compose_inline))
        return false;
    return true;
}

} // namespace mojo

namespace mojo {

template <>
struct StructTraits<::mojo::TextInputState::DataView,
    ::mojo::TextInputStatePtr> {
    static bool IsNull(const ::mojo::TextInputStatePtr& input) { return !input; }
    static void SetToNull(::mojo::TextInputStatePtr* output) { output->reset(); }

    static decltype(::mojo::TextInputState::type) type(
        const ::mojo::TextInputStatePtr& input)
    {
        return input->type;
    }

    static decltype(::mojo::TextInputState::flags) flags(
        const ::mojo::TextInputStatePtr& input)
    {
        return input->flags;
    }

    static const decltype(::mojo::TextInputState::text)& text(
        const ::mojo::TextInputStatePtr& input)
    {
        return input->text;
    }

    static decltype(::mojo::TextInputState::selection_start) selection_start(
        const ::mojo::TextInputStatePtr& input)
    {
        return input->selection_start;
    }

    static decltype(::mojo::TextInputState::selection_end) selection_end(
        const ::mojo::TextInputStatePtr& input)
    {
        return input->selection_end;
    }

    static decltype(::mojo::TextInputState::composition_start) composition_start(
        const ::mojo::TextInputStatePtr& input)
    {
        return input->composition_start;
    }

    static decltype(::mojo::TextInputState::composition_end) composition_end(
        const ::mojo::TextInputStatePtr& input)
    {
        return input->composition_end;
    }

    static decltype(::mojo::TextInputState::can_compose_inline) can_compose_inline(
        const ::mojo::TextInputStatePtr& input)
    {
        return input->can_compose_inline;
    }

    static bool Read(::mojo::TextInputState::DataView input, ::mojo::TextInputStatePtr* output);
};

} // namespace mojo

#endif // UI_PLATFORM_WINDOW_MOJO_TEXT_INPUT_STATE_MOJOM_H_