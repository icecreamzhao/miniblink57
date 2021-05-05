// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_EVENTS_MOJO_LATENCY_INFO_MOJOM_H_
#define UI_EVENTS_MOJO_LATENCY_INFO_MOJOM_H_

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
#include "mojo/common/time.mojom.h"
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
#include "ui/events/event.h"
#include "ui/events/latency_info.h"
#include "ui/events/mojo/latency_info.mojom-shared.h"
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
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace ui {
namespace mojom {
    class LatencyComponentId;
    using LatencyComponentIdPtr = mojo::InlinedStructPtr<LatencyComponentId>;

    class LatencyComponent;
    using LatencyComponentPtr = mojo::StructPtr<LatencyComponent>;

    class LatencyComponentPair;
    using LatencyComponentPairPtr = mojo::StructPtr<LatencyComponentPair>;

    class LatencyInfo;
    using LatencyInfoPtr = mojo::StructPtr<LatencyInfo>;

    class LatencyComponentId {
    public:
        using DataView = LatencyComponentIdDataView;
        using Data_ = internal::LatencyComponentId_Data;

        static LatencyComponentIdPtr New();

        template <typename U>
        static LatencyComponentIdPtr From(const U& u)
        {
            return mojo::TypeConverter<LatencyComponentIdPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, LatencyComponentId>::Convert(*this);
        }

        LatencyComponentId();
        ~LatencyComponentId();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = LatencyComponentIdPtr>
        LatencyComponentIdPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, LatencyComponentId>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                LatencyComponentId::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                LatencyComponentId::DataView, std::vector<uint8_t>>(
                input, output);
        }

        LatencyComponentType type;
        int64_t id;
    };

    class LatencyComponent {
    public:
        using DataView = LatencyComponentDataView;
        using Data_ = internal::LatencyComponent_Data;

        static LatencyComponentPtr New();

        template <typename U>
        static LatencyComponentPtr From(const U& u)
        {
            return mojo::TypeConverter<LatencyComponentPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, LatencyComponent>::Convert(*this);
        }

        LatencyComponent();
        ~LatencyComponent();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = LatencyComponentPtr>
        LatencyComponentPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, LatencyComponent>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                LatencyComponent::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                LatencyComponent::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int64_t sequence_number;
        base::TimeTicks event_time;
        uint32_t event_count;
    };

    class LatencyComponentPair {
    public:
        using DataView = LatencyComponentPairDataView;
        using Data_ = internal::LatencyComponentPair_Data;

        static LatencyComponentPairPtr New();

        template <typename U>
        static LatencyComponentPairPtr From(const U& u)
        {
            return mojo::TypeConverter<LatencyComponentPairPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, LatencyComponentPair>::Convert(*this);
        }

        LatencyComponentPair();
        ~LatencyComponentPair();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = LatencyComponentPairPtr>
        LatencyComponentPairPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, LatencyComponentPair>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                LatencyComponentPair::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                LatencyComponentPair::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::pair<ui::LatencyComponentType, int64_t> key;
        ui::LatencyInfo::LatencyComponent value;
    };

    class LatencyInfo {
    public:
        using DataView = LatencyInfoDataView;
        using Data_ = internal::LatencyInfo_Data;

        static LatencyInfoPtr New();

        template <typename U>
        static LatencyInfoPtr From(const U& u)
        {
            return mojo::TypeConverter<LatencyInfoPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, LatencyInfo>::Convert(*this);
        }

        LatencyInfo();
        ~LatencyInfo();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = LatencyInfoPtr>
        LatencyInfoPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, LatencyInfo>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                LatencyInfo::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                LatencyInfo::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string trace_name;
        std::vector<LatencyComponentPairPtr> latency_components;
        std::vector<gfx::PointF> input_coordinates;
        int64_t trace_id;
        bool coalesced;
        bool terminated;

    private:
        DISALLOW_COPY_AND_ASSIGN(LatencyInfo);
    };

    template <typename StructPtrType>
    LatencyComponentIdPtr LatencyComponentId::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->type = mojo::internal::Clone(type);
        rv->id = mojo::internal::Clone(id);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, LatencyComponentId>::value>::type*>
    bool LatencyComponentId::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->type, other.type))
            return false;
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        return true;
    }
    template <typename StructPtrType>
    LatencyComponentPtr LatencyComponent::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->sequence_number = mojo::internal::Clone(sequence_number);
        rv->event_time = mojo::internal::Clone(event_time);
        rv->event_count = mojo::internal::Clone(event_count);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, LatencyComponent>::value>::type*>
    bool LatencyComponent::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->sequence_number, other.sequence_number))
            return false;
        if (!mojo::internal::Equals(this->event_time, other.event_time))
            return false;
        if (!mojo::internal::Equals(this->event_count, other.event_count))
            return false;
        return true;
    }
    template <typename StructPtrType>
    LatencyComponentPairPtr LatencyComponentPair::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->key = mojo::internal::Clone(key);
        rv->value = mojo::internal::Clone(value);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, LatencyComponentPair>::value>::type*>
    bool LatencyComponentPair::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->key, other.key))
            return false;
        if (!mojo::internal::Equals(this->value, other.value))
            return false;
        return true;
    }
    template <typename StructPtrType>
    LatencyInfoPtr LatencyInfo::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->trace_name = mojo::internal::Clone(trace_name);
        rv->latency_components = mojo::internal::Clone(latency_components);
        rv->input_coordinates = mojo::internal::Clone(input_coordinates);
        rv->trace_id = mojo::internal::Clone(trace_id);
        rv->coalesced = mojo::internal::Clone(coalesced);
        rv->terminated = mojo::internal::Clone(terminated);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, LatencyInfo>::value>::type*>
    bool LatencyInfo::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->trace_name, other.trace_name))
            return false;
        if (!mojo::internal::Equals(this->latency_components, other.latency_components))
            return false;
        if (!mojo::internal::Equals(this->input_coordinates, other.input_coordinates))
            return false;
        if (!mojo::internal::Equals(this->trace_id, other.trace_id))
            return false;
        if (!mojo::internal::Equals(this->coalesced, other.coalesced))
            return false;
        if (!mojo::internal::Equals(this->terminated, other.terminated))
            return false;
        return true;
    }

} // namespace mojom
} // namespace ui

namespace mojo {

template <>
struct StructTraits<::ui::mojom::LatencyComponentId::DataView,
    ::ui::mojom::LatencyComponentIdPtr> {
    static bool IsNull(const ::ui::mojom::LatencyComponentIdPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::LatencyComponentIdPtr* output) { output->reset(); }

    static decltype(::ui::mojom::LatencyComponentId::type) type(
        const ::ui::mojom::LatencyComponentIdPtr& input)
    {
        return input->type;
    }

    static decltype(::ui::mojom::LatencyComponentId::id) id(
        const ::ui::mojom::LatencyComponentIdPtr& input)
    {
        return input->id;
    }

    static bool Read(::ui::mojom::LatencyComponentId::DataView input, ::ui::mojom::LatencyComponentIdPtr* output);
};

template <>
struct StructTraits<::ui::mojom::LatencyComponent::DataView,
    ::ui::mojom::LatencyComponentPtr> {
    static bool IsNull(const ::ui::mojom::LatencyComponentPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::LatencyComponentPtr* output) { output->reset(); }

    static decltype(::ui::mojom::LatencyComponent::sequence_number) sequence_number(
        const ::ui::mojom::LatencyComponentPtr& input)
    {
        return input->sequence_number;
    }

    static const decltype(::ui::mojom::LatencyComponent::event_time)& event_time(
        const ::ui::mojom::LatencyComponentPtr& input)
    {
        return input->event_time;
    }

    static decltype(::ui::mojom::LatencyComponent::event_count) event_count(
        const ::ui::mojom::LatencyComponentPtr& input)
    {
        return input->event_count;
    }

    static bool Read(::ui::mojom::LatencyComponent::DataView input, ::ui::mojom::LatencyComponentPtr* output);
};

template <>
struct StructTraits<::ui::mojom::LatencyComponentPair::DataView,
    ::ui::mojom::LatencyComponentPairPtr> {
    static bool IsNull(const ::ui::mojom::LatencyComponentPairPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::LatencyComponentPairPtr* output) { output->reset(); }

    static const decltype(::ui::mojom::LatencyComponentPair::key)& key(
        const ::ui::mojom::LatencyComponentPairPtr& input)
    {
        return input->key;
    }

    static const decltype(::ui::mojom::LatencyComponentPair::value)& value(
        const ::ui::mojom::LatencyComponentPairPtr& input)
    {
        return input->value;
    }

    static bool Read(::ui::mojom::LatencyComponentPair::DataView input, ::ui::mojom::LatencyComponentPairPtr* output);
};

template <>
struct StructTraits<::ui::mojom::LatencyInfo::DataView,
    ::ui::mojom::LatencyInfoPtr> {
    static bool IsNull(const ::ui::mojom::LatencyInfoPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::LatencyInfoPtr* output) { output->reset(); }

    static const decltype(::ui::mojom::LatencyInfo::trace_name)& trace_name(
        const ::ui::mojom::LatencyInfoPtr& input)
    {
        return input->trace_name;
    }

    static const decltype(::ui::mojom::LatencyInfo::latency_components)& latency_components(
        const ::ui::mojom::LatencyInfoPtr& input)
    {
        return input->latency_components;
    }

    static const decltype(::ui::mojom::LatencyInfo::input_coordinates)& input_coordinates(
        const ::ui::mojom::LatencyInfoPtr& input)
    {
        return input->input_coordinates;
    }

    static decltype(::ui::mojom::LatencyInfo::trace_id) trace_id(
        const ::ui::mojom::LatencyInfoPtr& input)
    {
        return input->trace_id;
    }

    static decltype(::ui::mojom::LatencyInfo::coalesced) coalesced(
        const ::ui::mojom::LatencyInfoPtr& input)
    {
        return input->coalesced;
    }

    static decltype(::ui::mojom::LatencyInfo::terminated) terminated(
        const ::ui::mojom::LatencyInfoPtr& input)
    {
        return input->terminated;
    }

    static bool Read(::ui::mojom::LatencyInfo::DataView input, ::ui::mojom::LatencyInfoPtr* output);
};

} // namespace mojo

#endif // UI_EVENTS_MOJO_LATENCY_INFO_MOJOM_H_