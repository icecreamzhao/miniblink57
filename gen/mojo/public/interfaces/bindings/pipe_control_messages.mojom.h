// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_PUBLIC_INTERFACES_BINDINGS_PIPE_CONTROL_MESSAGES_MOJOM_H_
#define MOJO_PUBLIC_INTERFACES_BINDINGS_PIPE_CONTROL_MESSAGES_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/bindings_export.h"
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
#include "mojo/public/interfaces/bindings/pipe_control_messages.mojom-shared.h"
#include <string>
#include <vector>

namespace mojo {
namespace pipe_control {
    constexpr uint32_t kRunOrClosePipeMessageId = 0xFFFFFFFEU;
    class RunOrClosePipeMessageParams;
    using RunOrClosePipeMessageParamsPtr = mojo::StructPtr<RunOrClosePipeMessageParams>;

    class PeerAssociatedEndpointClosedEvent;
    using PeerAssociatedEndpointClosedEventPtr = mojo::InlinedStructPtr<PeerAssociatedEndpointClosedEvent>;

    class AssociatedEndpointClosedBeforeSentEvent;
    using AssociatedEndpointClosedBeforeSentEventPtr = mojo::InlinedStructPtr<AssociatedEndpointClosedBeforeSentEvent>;

    class RunOrClosePipeInput;

    typedef mojo::StructPtr<RunOrClosePipeInput> RunOrClosePipeInputPtr;

    class MOJO_CPP_BINDINGS_EXPORT PeerAssociatedEndpointClosedEvent {
    public:
        using DataView = PeerAssociatedEndpointClosedEventDataView;
        using Data_ = internal::PeerAssociatedEndpointClosedEvent_Data;

        static PeerAssociatedEndpointClosedEventPtr New();

        template <typename U>
        static PeerAssociatedEndpointClosedEventPtr From(const U& u)
        {
            return mojo::TypeConverter<PeerAssociatedEndpointClosedEventPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PeerAssociatedEndpointClosedEvent>::Convert(*this);
        }

        PeerAssociatedEndpointClosedEvent();
        ~PeerAssociatedEndpointClosedEvent();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PeerAssociatedEndpointClosedEventPtr>
        PeerAssociatedEndpointClosedEventPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PeerAssociatedEndpointClosedEvent>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PeerAssociatedEndpointClosedEvent::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PeerAssociatedEndpointClosedEvent::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t id;
    };

    class MOJO_CPP_BINDINGS_EXPORT AssociatedEndpointClosedBeforeSentEvent {
    public:
        using DataView = AssociatedEndpointClosedBeforeSentEventDataView;
        using Data_ = internal::AssociatedEndpointClosedBeforeSentEvent_Data;

        static AssociatedEndpointClosedBeforeSentEventPtr New();

        template <typename U>
        static AssociatedEndpointClosedBeforeSentEventPtr From(const U& u)
        {
            return mojo::TypeConverter<AssociatedEndpointClosedBeforeSentEventPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, AssociatedEndpointClosedBeforeSentEvent>::Convert(*this);
        }

        AssociatedEndpointClosedBeforeSentEvent();
        ~AssociatedEndpointClosedBeforeSentEvent();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = AssociatedEndpointClosedBeforeSentEventPtr>
        AssociatedEndpointClosedBeforeSentEventPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, AssociatedEndpointClosedBeforeSentEvent>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                AssociatedEndpointClosedBeforeSentEvent::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                AssociatedEndpointClosedBeforeSentEvent::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t id;
    };

    class MOJO_CPP_BINDINGS_EXPORT RunOrClosePipeInput {
    public:
        using DataView = RunOrClosePipeInputDataView;
        using Data_ = internal::RunOrClosePipeInput_Data;
        using Tag = Data_::RunOrClosePipeInput_Tag;

        static RunOrClosePipeInputPtr New();

        template <typename U>
        static RunOrClosePipeInputPtr From(const U& u)
        {
            return mojo::TypeConverter<RunOrClosePipeInputPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, RunOrClosePipeInput>::Convert(*this);
        }

        RunOrClosePipeInput();
        ~RunOrClosePipeInput();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename UnionPtrType = RunOrClosePipeInputPtr>
        RunOrClosePipeInputPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, RunOrClosePipeInput>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        Tag which() const
        {
            return tag_;
        }

        bool is_peer_associated_endpoint_closed_event() const { return tag_ == Tag::PEER_ASSOCIATED_ENDPOINT_CLOSED_EVENT; }

        PeerAssociatedEndpointClosedEventPtr& get_peer_associated_endpoint_closed_event() const
        {
            DCHECK(tag_ == Tag::PEER_ASSOCIATED_ENDPOINT_CLOSED_EVENT);
            return *(data_.peer_associated_endpoint_closed_event);
        }

        void set_peer_associated_endpoint_closed_event(PeerAssociatedEndpointClosedEventPtr peer_associated_endpoint_closed_event);
        bool is_associated_endpoint_closed_before_sent_event() const { return tag_ == Tag::ASSOCIATED_ENDPOINT_CLOSED_BEFORE_SENT_EVENT; }

        AssociatedEndpointClosedBeforeSentEventPtr& get_associated_endpoint_closed_before_sent_event() const
        {
            DCHECK(tag_ == Tag::ASSOCIATED_ENDPOINT_CLOSED_BEFORE_SENT_EVENT);
            return *(data_.associated_endpoint_closed_before_sent_event);
        }

        void set_associated_endpoint_closed_before_sent_event(AssociatedEndpointClosedBeforeSentEventPtr associated_endpoint_closed_before_sent_event);

    private:
        friend class mojo::internal::UnionAccessor<RunOrClosePipeInput>;
        union Union_ {
            Union_() { }
            ~Union_() { }
            PeerAssociatedEndpointClosedEventPtr* peer_associated_endpoint_closed_event;
            AssociatedEndpointClosedBeforeSentEventPtr* associated_endpoint_closed_before_sent_event;
        };
        void SwitchActive(Tag new_active);
        void SetActive(Tag new_active);
        void DestroyActive();
        Tag tag_;
        Union_ data_;
    };

    class MOJO_CPP_BINDINGS_EXPORT RunOrClosePipeMessageParams {
    public:
        using DataView = RunOrClosePipeMessageParamsDataView;
        using Data_ = internal::RunOrClosePipeMessageParams_Data;

        static RunOrClosePipeMessageParamsPtr New();

        template <typename U>
        static RunOrClosePipeMessageParamsPtr From(const U& u)
        {
            return mojo::TypeConverter<RunOrClosePipeMessageParamsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, RunOrClosePipeMessageParams>::Convert(*this);
        }

        RunOrClosePipeMessageParams();
        ~RunOrClosePipeMessageParams();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = RunOrClosePipeMessageParamsPtr>
        RunOrClosePipeMessageParamsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, RunOrClosePipeMessageParams>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                RunOrClosePipeMessageParams::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                RunOrClosePipeMessageParams::DataView, std::vector<uint8_t>>(
                input, output);
        }

        RunOrClosePipeInputPtr input;

    private:
        DISALLOW_COPY_AND_ASSIGN(RunOrClosePipeMessageParams);
    };

    template <typename UnionPtrType>
    RunOrClosePipeInputPtr RunOrClosePipeInput::Clone() const
    {
        // Use UnionPtrType to prevent the compiler from trying to compile this
        // without being asked.
        UnionPtrType rv(New());
        switch (tag_) {
        case Tag::PEER_ASSOCIATED_ENDPOINT_CLOSED_EVENT:
            rv->set_peer_associated_endpoint_closed_event(mojo::internal::Clone(*data_.peer_associated_endpoint_closed_event));
            break;
        case Tag::ASSOCIATED_ENDPOINT_CLOSED_BEFORE_SENT_EVENT:
            rv->set_associated_endpoint_closed_before_sent_event(mojo::internal::Clone(*data_.associated_endpoint_closed_before_sent_event));
            break;
        };
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, RunOrClosePipeInput>::value>::type*>
    bool RunOrClosePipeInput::Equals(const T& other) const
    {
        if (tag_ != other.which())
            return false;

        switch (tag_) {
        case Tag::PEER_ASSOCIATED_ENDPOINT_CLOSED_EVENT:
            return mojo::internal::Equals(*(data_.peer_associated_endpoint_closed_event), *(other.data_.peer_associated_endpoint_closed_event));
        case Tag::ASSOCIATED_ENDPOINT_CLOSED_BEFORE_SENT_EVENT:
            return mojo::internal::Equals(*(data_.associated_endpoint_closed_before_sent_event), *(other.data_.associated_endpoint_closed_before_sent_event));
        };

        return false;
    }
    template <typename StructPtrType>
    RunOrClosePipeMessageParamsPtr RunOrClosePipeMessageParams::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->input = mojo::internal::Clone(input);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, RunOrClosePipeMessageParams>::value>::type*>
    bool RunOrClosePipeMessageParams::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->input, other.input))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PeerAssociatedEndpointClosedEventPtr PeerAssociatedEndpointClosedEvent::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->id = mojo::internal::Clone(id);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PeerAssociatedEndpointClosedEvent>::value>::type*>
    bool PeerAssociatedEndpointClosedEvent::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        return true;
    }
    template <typename StructPtrType>
    AssociatedEndpointClosedBeforeSentEventPtr AssociatedEndpointClosedBeforeSentEvent::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->id = mojo::internal::Clone(id);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, AssociatedEndpointClosedBeforeSentEvent>::value>::type*>
    bool AssociatedEndpointClosedBeforeSentEvent::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        return true;
    }

} // namespace pipe_control
} // namespace mojo

namespace mojo {

template <>
struct MOJO_CPP_BINDINGS_EXPORT StructTraits<::mojo::pipe_control::RunOrClosePipeMessageParams::DataView,
    ::mojo::pipe_control::RunOrClosePipeMessageParamsPtr> {
    static bool IsNull(const ::mojo::pipe_control::RunOrClosePipeMessageParamsPtr& input) { return !input; }
    static void SetToNull(::mojo::pipe_control::RunOrClosePipeMessageParamsPtr* output) { output->reset(); }

    static const decltype(::mojo::pipe_control::RunOrClosePipeMessageParams::input)& input(
        const ::mojo::pipe_control::RunOrClosePipeMessageParamsPtr& input)
    {
        return input->input;
    }

    static bool Read(::mojo::pipe_control::RunOrClosePipeMessageParams::DataView input, ::mojo::pipe_control::RunOrClosePipeMessageParamsPtr* output);
};

template <>
struct MOJO_CPP_BINDINGS_EXPORT StructTraits<::mojo::pipe_control::PeerAssociatedEndpointClosedEvent::DataView,
    ::mojo::pipe_control::PeerAssociatedEndpointClosedEventPtr> {
    static bool IsNull(const ::mojo::pipe_control::PeerAssociatedEndpointClosedEventPtr& input) { return !input; }
    static void SetToNull(::mojo::pipe_control::PeerAssociatedEndpointClosedEventPtr* output) { output->reset(); }

    static decltype(::mojo::pipe_control::PeerAssociatedEndpointClosedEvent::id) id(
        const ::mojo::pipe_control::PeerAssociatedEndpointClosedEventPtr& input)
    {
        return input->id;
    }

    static bool Read(::mojo::pipe_control::PeerAssociatedEndpointClosedEvent::DataView input, ::mojo::pipe_control::PeerAssociatedEndpointClosedEventPtr* output);
};

template <>
struct MOJO_CPP_BINDINGS_EXPORT StructTraits<::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEvent::DataView,
    ::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEventPtr> {
    static bool IsNull(const ::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEventPtr& input) { return !input; }
    static void SetToNull(::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEventPtr* output) { output->reset(); }

    static decltype(::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEvent::id) id(
        const ::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEventPtr& input)
    {
        return input->id;
    }

    static bool Read(::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEvent::DataView input, ::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEventPtr* output);
};

template <>
struct MOJO_CPP_BINDINGS_EXPORT UnionTraits<::mojo::pipe_control::RunOrClosePipeInput::DataView,
    ::mojo::pipe_control::RunOrClosePipeInputPtr> {
    static bool IsNull(const ::mojo::pipe_control::RunOrClosePipeInputPtr& input) { return !input; }
    static void SetToNull(::mojo::pipe_control::RunOrClosePipeInputPtr* output) { output->reset(); }

    static ::mojo::pipe_control::RunOrClosePipeInput::Tag GetTag(const ::mojo::pipe_control::RunOrClosePipeInputPtr& input)
    {
        return input->which();
    }

    static const ::mojo::pipe_control::PeerAssociatedEndpointClosedEventPtr& peer_associated_endpoint_closed_event(const ::mojo::pipe_control::RunOrClosePipeInputPtr& input)
    {
        return input->get_peer_associated_endpoint_closed_event();
    }

    static const ::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEventPtr& associated_endpoint_closed_before_sent_event(const ::mojo::pipe_control::RunOrClosePipeInputPtr& input)
    {
        return input->get_associated_endpoint_closed_before_sent_event();
    }

    static bool Read(::mojo::pipe_control::RunOrClosePipeInput::DataView input, ::mojo::pipe_control::RunOrClosePipeInputPtr* output);
};

} // namespace mojo

#endif // MOJO_PUBLIC_INTERFACES_BINDINGS_PIPE_CONTROL_MESSAGES_MOJOM_H_