// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_EVENT_MATCHER_MOJOM_H_
#define SERVICES_UI_PUBLIC_INTERFACES_EVENT_MATCHER_MOJOM_H_

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
#include "cc/input/selection.h"
#include "cc/output/begin_frame_args.h"
#include "cc/output/compositor_frame.h"
#include "cc/output/compositor_frame_metadata.h"
#include "cc/output/filter_operation.h"
#include "cc/output/filter_operations.h"
#include "cc/quads/draw_quad.h"
#include "cc/quads/render_pass.h"
#include "cc/quads/shared_quad_state.h"
#include "cc/resources/returned_resource.h"
#include "cc/resources/transferable_resource.h"
#include "cc/surfaces/frame_sink_id.h"
#include "cc/surfaces/local_frame_id.h"
#include "cc/surfaces/surface_id.h"
#include "cc/surfaces/surface_info.h"
#include "cc/surfaces/surface_reference.h"
#include "cc/surfaces/surface_sequence.h"
#include "gpu/command_buffer/common/capabilities.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/mailbox_holder.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/gpu_preferences.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info.h"
#include "gpu/ipc/common/surface_handle.h"
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
#include "services/ui/public/interfaces/event_matcher.mojom-shared.h"
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkImageFilter.h"
#include "ui/base/ime/composition_text.h"
#include "ui/base/ime/composition_underline.h"
#include "ui/base/ime/text_input_mode.h"
#include "ui/base/ime/text_input_type.h"
#include "ui/display/display.h"
#include "ui/events/event.h"
#include "ui/events/latency_info.h"
#include "ui/events/mojo/event_constants.mojom.h"
#include "ui/events/mojo/keyboard_codes.mojom.h"
#include "ui/gfx/buffer_types.h"
#include "ui/gfx/color_space.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/mojo/geometry.mojom.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "ui/gfx/gpu_memory_buffer.h"
#include "ui/gfx/icc_profile.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/range/range.h"
#include "ui/gfx/range/range_f.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace ui {
namespace mojom {
    class KeyEventMatcher;
    using KeyEventMatcherPtr = mojo::InlinedStructPtr<KeyEventMatcher>;

    class PointerKindMatcher;
    using PointerKindMatcherPtr = mojo::InlinedStructPtr<PointerKindMatcher>;

    class PointerLocationMatcher;
    using PointerLocationMatcherPtr = mojo::StructPtr<PointerLocationMatcher>;

    class EventTypeMatcher;
    using EventTypeMatcherPtr = mojo::InlinedStructPtr<EventTypeMatcher>;

    class EventFlagsMatcher;
    using EventFlagsMatcherPtr = mojo::InlinedStructPtr<EventFlagsMatcher>;

    class EventMatcher;
    using EventMatcherPtr = mojo::StructPtr<EventMatcher>;

    class KeyEventMatcher {
    public:
        using DataView = KeyEventMatcherDataView;
        using Data_ = internal::KeyEventMatcher_Data;

        static KeyEventMatcherPtr New();

        template <typename U>
        static KeyEventMatcherPtr From(const U& u)
        {
            return mojo::TypeConverter<KeyEventMatcherPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, KeyEventMatcher>::Convert(*this);
        }

        KeyEventMatcher();
        ~KeyEventMatcher();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = KeyEventMatcherPtr>
        KeyEventMatcherPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, KeyEventMatcher>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                KeyEventMatcher::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                KeyEventMatcher::DataView, std::vector<uint8_t>>(
                input, output);
        }

        ::ui::mojom::KeyboardCode keyboard_code;
    };

    class PointerKindMatcher {
    public:
        using DataView = PointerKindMatcherDataView;
        using Data_ = internal::PointerKindMatcher_Data;

        static PointerKindMatcherPtr New();

        template <typename U>
        static PointerKindMatcherPtr From(const U& u)
        {
            return mojo::TypeConverter<PointerKindMatcherPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PointerKindMatcher>::Convert(*this);
        }

        PointerKindMatcher();
        ~PointerKindMatcher();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PointerKindMatcherPtr>
        PointerKindMatcherPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PointerKindMatcher>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PointerKindMatcher::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PointerKindMatcher::DataView, std::vector<uint8_t>>(
                input, output);
        }

        ::ui::mojom::PointerKind pointer_kind;
    };

    class EventTypeMatcher {
    public:
        using DataView = EventTypeMatcherDataView;
        using Data_ = internal::EventTypeMatcher_Data;

        static EventTypeMatcherPtr New();

        template <typename U>
        static EventTypeMatcherPtr From(const U& u)
        {
            return mojo::TypeConverter<EventTypeMatcherPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, EventTypeMatcher>::Convert(*this);
        }

        EventTypeMatcher();
        ~EventTypeMatcher();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = EventTypeMatcherPtr>
        EventTypeMatcherPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, EventTypeMatcher>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                EventTypeMatcher::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                EventTypeMatcher::DataView, std::vector<uint8_t>>(
                input, output);
        }

        ::ui::mojom::EventType type;
    };

    class EventFlagsMatcher {
    public:
        using DataView = EventFlagsMatcherDataView;
        using Data_ = internal::EventFlagsMatcher_Data;

        static EventFlagsMatcherPtr New();

        template <typename U>
        static EventFlagsMatcherPtr From(const U& u)
        {
            return mojo::TypeConverter<EventFlagsMatcherPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, EventFlagsMatcher>::Convert(*this);
        }

        EventFlagsMatcher();
        ~EventFlagsMatcher();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = EventFlagsMatcherPtr>
        EventFlagsMatcherPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, EventFlagsMatcher>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                EventFlagsMatcher::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                EventFlagsMatcher::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int32_t flags;
    };

    class PointerLocationMatcher {
    public:
        using DataView = PointerLocationMatcherDataView;
        using Data_ = internal::PointerLocationMatcher_Data;

        static PointerLocationMatcherPtr New();

        template <typename U>
        static PointerLocationMatcherPtr From(const U& u)
        {
            return mojo::TypeConverter<PointerLocationMatcherPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PointerLocationMatcher>::Convert(*this);
        }

        PointerLocationMatcher();
        ~PointerLocationMatcher();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PointerLocationMatcherPtr>
        PointerLocationMatcherPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PointerLocationMatcher>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PointerLocationMatcher::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PointerLocationMatcher::DataView, std::vector<uint8_t>>(
                input, output);
        }

        gfx::RectF region;
    };

    class EventMatcher {
    public:
        using DataView = EventMatcherDataView;
        using Data_ = internal::EventMatcher_Data;

        static EventMatcherPtr New();

        template <typename U>
        static EventMatcherPtr From(const U& u)
        {
            return mojo::TypeConverter<EventMatcherPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, EventMatcher>::Convert(*this);
        }

        EventMatcher();
        ~EventMatcher();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = EventMatcherPtr>
        EventMatcherPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, EventMatcher>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                EventMatcher::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                EventMatcher::DataView, std::vector<uint8_t>>(
                input, output);
        }

        ::ui::mojom::AcceleratorPhase accelerator_phase;
        EventTypeMatcherPtr type_matcher;
        EventFlagsMatcherPtr flags_matcher;
        EventFlagsMatcherPtr ignore_flags_matcher;
        KeyEventMatcherPtr key_matcher;
        PointerKindMatcherPtr pointer_kind_matcher;
        PointerLocationMatcherPtr pointer_location_matcher;

    private:
        DISALLOW_COPY_AND_ASSIGN(EventMatcher);
    };

    template <typename StructPtrType>
    KeyEventMatcherPtr KeyEventMatcher::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->keyboard_code = mojo::internal::Clone(keyboard_code);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, KeyEventMatcher>::value>::type*>
    bool KeyEventMatcher::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->keyboard_code, other.keyboard_code))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PointerKindMatcherPtr PointerKindMatcher::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->pointer_kind = mojo::internal::Clone(pointer_kind);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PointerKindMatcher>::value>::type*>
    bool PointerKindMatcher::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->pointer_kind, other.pointer_kind))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PointerLocationMatcherPtr PointerLocationMatcher::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->region = mojo::internal::Clone(region);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PointerLocationMatcher>::value>::type*>
    bool PointerLocationMatcher::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->region, other.region))
            return false;
        return true;
    }
    template <typename StructPtrType>
    EventTypeMatcherPtr EventTypeMatcher::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->type = mojo::internal::Clone(type);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, EventTypeMatcher>::value>::type*>
    bool EventTypeMatcher::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->type, other.type))
            return false;
        return true;
    }
    template <typename StructPtrType>
    EventFlagsMatcherPtr EventFlagsMatcher::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->flags = mojo::internal::Clone(flags);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, EventFlagsMatcher>::value>::type*>
    bool EventFlagsMatcher::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->flags, other.flags))
            return false;
        return true;
    }
    template <typename StructPtrType>
    EventMatcherPtr EventMatcher::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->accelerator_phase = mojo::internal::Clone(accelerator_phase);
        rv->type_matcher = mojo::internal::Clone(type_matcher);
        rv->flags_matcher = mojo::internal::Clone(flags_matcher);
        rv->ignore_flags_matcher = mojo::internal::Clone(ignore_flags_matcher);
        rv->key_matcher = mojo::internal::Clone(key_matcher);
        rv->pointer_kind_matcher = mojo::internal::Clone(pointer_kind_matcher);
        rv->pointer_location_matcher = mojo::internal::Clone(pointer_location_matcher);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, EventMatcher>::value>::type*>
    bool EventMatcher::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->accelerator_phase, other.accelerator_phase))
            return false;
        if (!mojo::internal::Equals(this->type_matcher, other.type_matcher))
            return false;
        if (!mojo::internal::Equals(this->flags_matcher, other.flags_matcher))
            return false;
        if (!mojo::internal::Equals(this->ignore_flags_matcher, other.ignore_flags_matcher))
            return false;
        if (!mojo::internal::Equals(this->key_matcher, other.key_matcher))
            return false;
        if (!mojo::internal::Equals(this->pointer_kind_matcher, other.pointer_kind_matcher))
            return false;
        if (!mojo::internal::Equals(this->pointer_location_matcher, other.pointer_location_matcher))
            return false;
        return true;
    }

} // namespace mojom
} // namespace ui

namespace mojo {

template <>
struct StructTraits<::ui::mojom::KeyEventMatcher::DataView,
    ::ui::mojom::KeyEventMatcherPtr> {
    static bool IsNull(const ::ui::mojom::KeyEventMatcherPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::KeyEventMatcherPtr* output) { output->reset(); }

    static decltype(::ui::mojom::KeyEventMatcher::keyboard_code) keyboard_code(
        const ::ui::mojom::KeyEventMatcherPtr& input)
    {
        return input->keyboard_code;
    }

    static bool Read(::ui::mojom::KeyEventMatcher::DataView input, ::ui::mojom::KeyEventMatcherPtr* output);
};

template <>
struct StructTraits<::ui::mojom::PointerKindMatcher::DataView,
    ::ui::mojom::PointerKindMatcherPtr> {
    static bool IsNull(const ::ui::mojom::PointerKindMatcherPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::PointerKindMatcherPtr* output) { output->reset(); }

    static decltype(::ui::mojom::PointerKindMatcher::pointer_kind) pointer_kind(
        const ::ui::mojom::PointerKindMatcherPtr& input)
    {
        return input->pointer_kind;
    }

    static bool Read(::ui::mojom::PointerKindMatcher::DataView input, ::ui::mojom::PointerKindMatcherPtr* output);
};

template <>
struct StructTraits<::ui::mojom::PointerLocationMatcher::DataView,
    ::ui::mojom::PointerLocationMatcherPtr> {
    static bool IsNull(const ::ui::mojom::PointerLocationMatcherPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::PointerLocationMatcherPtr* output) { output->reset(); }

    static const decltype(::ui::mojom::PointerLocationMatcher::region)& region(
        const ::ui::mojom::PointerLocationMatcherPtr& input)
    {
        return input->region;
    }

    static bool Read(::ui::mojom::PointerLocationMatcher::DataView input, ::ui::mojom::PointerLocationMatcherPtr* output);
};

template <>
struct StructTraits<::ui::mojom::EventTypeMatcher::DataView,
    ::ui::mojom::EventTypeMatcherPtr> {
    static bool IsNull(const ::ui::mojom::EventTypeMatcherPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::EventTypeMatcherPtr* output) { output->reset(); }

    static decltype(::ui::mojom::EventTypeMatcher::type) type(
        const ::ui::mojom::EventTypeMatcherPtr& input)
    {
        return input->type;
    }

    static bool Read(::ui::mojom::EventTypeMatcher::DataView input, ::ui::mojom::EventTypeMatcherPtr* output);
};

template <>
struct StructTraits<::ui::mojom::EventFlagsMatcher::DataView,
    ::ui::mojom::EventFlagsMatcherPtr> {
    static bool IsNull(const ::ui::mojom::EventFlagsMatcherPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::EventFlagsMatcherPtr* output) { output->reset(); }

    static decltype(::ui::mojom::EventFlagsMatcher::flags) flags(
        const ::ui::mojom::EventFlagsMatcherPtr& input)
    {
        return input->flags;
    }

    static bool Read(::ui::mojom::EventFlagsMatcher::DataView input, ::ui::mojom::EventFlagsMatcherPtr* output);
};

template <>
struct StructTraits<::ui::mojom::EventMatcher::DataView,
    ::ui::mojom::EventMatcherPtr> {
    static bool IsNull(const ::ui::mojom::EventMatcherPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::EventMatcherPtr* output) { output->reset(); }

    static decltype(::ui::mojom::EventMatcher::accelerator_phase) accelerator_phase(
        const ::ui::mojom::EventMatcherPtr& input)
    {
        return input->accelerator_phase;
    }

    static const decltype(::ui::mojom::EventMatcher::type_matcher)& type_matcher(
        const ::ui::mojom::EventMatcherPtr& input)
    {
        return input->type_matcher;
    }

    static const decltype(::ui::mojom::EventMatcher::flags_matcher)& flags_matcher(
        const ::ui::mojom::EventMatcherPtr& input)
    {
        return input->flags_matcher;
    }

    static const decltype(::ui::mojom::EventMatcher::ignore_flags_matcher)& ignore_flags_matcher(
        const ::ui::mojom::EventMatcherPtr& input)
    {
        return input->ignore_flags_matcher;
    }

    static const decltype(::ui::mojom::EventMatcher::key_matcher)& key_matcher(
        const ::ui::mojom::EventMatcherPtr& input)
    {
        return input->key_matcher;
    }

    static const decltype(::ui::mojom::EventMatcher::pointer_kind_matcher)& pointer_kind_matcher(
        const ::ui::mojom::EventMatcherPtr& input)
    {
        return input->pointer_kind_matcher;
    }

    static const decltype(::ui::mojom::EventMatcher::pointer_location_matcher)& pointer_location_matcher(
        const ::ui::mojom::EventMatcherPtr& input)
    {
        return input->pointer_location_matcher;
    }

    static bool Read(::ui::mojom::EventMatcher::DataView input, ::ui::mojom::EventMatcherPtr* output);
};

} // namespace mojo

#endif // SERVICES_UI_PUBLIC_INTERFACES_EVENT_MATCHER_MOJOM_H_