// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_EVENTS_MOJO_LATENCY_INFO_MOJOM_BLINK_H_
#define UI_EVENTS_MOJO_LATENCY_INFO_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "mojo/common/time.mojom-blink.h"
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
#include "ui/events/mojo/latency_info.mojom-shared.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-blink.h"

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebSize.h"

namespace ui {
namespace mojom {
    namespace blink {
        using LatencyComponentType = LatencyComponentType; // Alias for definition in the parent namespace.
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
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    LatencyComponentId::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    LatencyComponentId::DataView, WTF::Vector<uint8_t>>(
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
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    LatencyComponent::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    LatencyComponent::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            int64_t sequence_number;
            ::mojo::common::mojom::blink::TimeTicksPtr event_time;
            uint32_t event_count;

        private:
            DISALLOW_COPY_AND_ASSIGN(LatencyComponent);
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
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    LatencyComponentPair::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    LatencyComponentPair::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            LatencyComponentIdPtr key;
            LatencyComponentPtr value;

        private:
            DISALLOW_COPY_AND_ASSIGN(LatencyComponentPair);
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    LatencyInfo::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    LatencyInfo::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::String trace_name;
            WTF::Vector<LatencyComponentPairPtr> latency_components;
            WTF::Vector<::gfx::mojom::blink::PointFPtr> input_coordinates;
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

    } // namespace blink
} // namespace mojom
} // namespace ui

namespace mojo {

template <>
struct StructTraits<::ui::mojom::blink::LatencyComponentId::DataView,
    ::ui::mojom::blink::LatencyComponentIdPtr> {
    static bool IsNull(const ::ui::mojom::blink::LatencyComponentIdPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::blink::LatencyComponentIdPtr* output) { output->reset(); }

    static decltype(::ui::mojom::blink::LatencyComponentId::type) type(
        const ::ui::mojom::blink::LatencyComponentIdPtr& input)
    {
        return input->type;
    }

    static decltype(::ui::mojom::blink::LatencyComponentId::id) id(
        const ::ui::mojom::blink::LatencyComponentIdPtr& input)
    {
        return input->id;
    }

    static bool Read(::ui::mojom::blink::LatencyComponentId::DataView input, ::ui::mojom::blink::LatencyComponentIdPtr* output);
};

template <>
struct StructTraits<::ui::mojom::blink::LatencyComponent::DataView,
    ::ui::mojom::blink::LatencyComponentPtr> {
    static bool IsNull(const ::ui::mojom::blink::LatencyComponentPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::blink::LatencyComponentPtr* output) { output->reset(); }

    static decltype(::ui::mojom::blink::LatencyComponent::sequence_number) sequence_number(
        const ::ui::mojom::blink::LatencyComponentPtr& input)
    {
        return input->sequence_number;
    }

    static const decltype(::ui::mojom::blink::LatencyComponent::event_time)& event_time(
        const ::ui::mojom::blink::LatencyComponentPtr& input)
    {
        return input->event_time;
    }

    static decltype(::ui::mojom::blink::LatencyComponent::event_count) event_count(
        const ::ui::mojom::blink::LatencyComponentPtr& input)
    {
        return input->event_count;
    }

    static bool Read(::ui::mojom::blink::LatencyComponent::DataView input, ::ui::mojom::blink::LatencyComponentPtr* output);
};

template <>
struct StructTraits<::ui::mojom::blink::LatencyComponentPair::DataView,
    ::ui::mojom::blink::LatencyComponentPairPtr> {
    static bool IsNull(const ::ui::mojom::blink::LatencyComponentPairPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::blink::LatencyComponentPairPtr* output) { output->reset(); }

    static const decltype(::ui::mojom::blink::LatencyComponentPair::key)& key(
        const ::ui::mojom::blink::LatencyComponentPairPtr& input)
    {
        return input->key;
    }

    static const decltype(::ui::mojom::blink::LatencyComponentPair::value)& value(
        const ::ui::mojom::blink::LatencyComponentPairPtr& input)
    {
        return input->value;
    }

    static bool Read(::ui::mojom::blink::LatencyComponentPair::DataView input, ::ui::mojom::blink::LatencyComponentPairPtr* output);
};

template <>
struct StructTraits<::ui::mojom::blink::LatencyInfo::DataView,
    ::ui::mojom::blink::LatencyInfoPtr> {
    static bool IsNull(const ::ui::mojom::blink::LatencyInfoPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::blink::LatencyInfoPtr* output) { output->reset(); }

    static const decltype(::ui::mojom::blink::LatencyInfo::trace_name)& trace_name(
        const ::ui::mojom::blink::LatencyInfoPtr& input)
    {
        return input->trace_name;
    }

    static const decltype(::ui::mojom::blink::LatencyInfo::latency_components)& latency_components(
        const ::ui::mojom::blink::LatencyInfoPtr& input)
    {
        return input->latency_components;
    }

    static const decltype(::ui::mojom::blink::LatencyInfo::input_coordinates)& input_coordinates(
        const ::ui::mojom::blink::LatencyInfoPtr& input)
    {
        return input->input_coordinates;
    }

    static decltype(::ui::mojom::blink::LatencyInfo::trace_id) trace_id(
        const ::ui::mojom::blink::LatencyInfoPtr& input)
    {
        return input->trace_id;
    }

    static decltype(::ui::mojom::blink::LatencyInfo::coalesced) coalesced(
        const ::ui::mojom::blink::LatencyInfoPtr& input)
    {
        return input->coalesced;
    }

    static decltype(::ui::mojom::blink::LatencyInfo::terminated) terminated(
        const ::ui::mojom::blink::LatencyInfoPtr& input)
    {
        return input->terminated;
    }

    static bool Read(::ui::mojom::blink::LatencyInfo::DataView input, ::ui::mojom::blink::LatencyInfoPtr* output);
};

} // namespace mojo

#endif // UI_EVENTS_MOJO_LATENCY_INFO_MOJOM_BLINK_H_