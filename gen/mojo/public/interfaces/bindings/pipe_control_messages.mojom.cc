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

#include "mojo/public/interfaces/bindings/pipe_control_messages.mojom.h"

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
namespace mojo {
namespace pipe_control { // static
    RunOrClosePipeMessageParamsPtr RunOrClosePipeMessageParams::New()
    {
        RunOrClosePipeMessageParamsPtr rv;
        mojo::internal::StructHelper<RunOrClosePipeMessageParams>::Initialize(&rv);
        return rv;
    }

    RunOrClosePipeMessageParams::RunOrClosePipeMessageParams()
        : input()
    {
    }

    RunOrClosePipeMessageParams::~RunOrClosePipeMessageParams()
    {
    }
    size_t RunOrClosePipeMessageParams::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->input);
        return seed;
    } // static
    PeerAssociatedEndpointClosedEventPtr PeerAssociatedEndpointClosedEvent::New()
    {
        PeerAssociatedEndpointClosedEventPtr rv;
        mojo::internal::StructHelper<PeerAssociatedEndpointClosedEvent>::Initialize(&rv);
        return rv;
    }

    PeerAssociatedEndpointClosedEvent::PeerAssociatedEndpointClosedEvent()
        : id()
    {
    }

    PeerAssociatedEndpointClosedEvent::~PeerAssociatedEndpointClosedEvent()
    {
    }
    size_t PeerAssociatedEndpointClosedEvent::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->id);
        return seed;
    } // static
    AssociatedEndpointClosedBeforeSentEventPtr AssociatedEndpointClosedBeforeSentEvent::New()
    {
        AssociatedEndpointClosedBeforeSentEventPtr rv;
        mojo::internal::StructHelper<AssociatedEndpointClosedBeforeSentEvent>::Initialize(&rv);
        return rv;
    }

    AssociatedEndpointClosedBeforeSentEvent::AssociatedEndpointClosedBeforeSentEvent()
        : id()
    {
    }

    AssociatedEndpointClosedBeforeSentEvent::~AssociatedEndpointClosedBeforeSentEvent()
    {
    }
    size_t AssociatedEndpointClosedBeforeSentEvent::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->id);
        return seed;
    } // static
    RunOrClosePipeInputPtr RunOrClosePipeInput::New()
    {
        RunOrClosePipeInputPtr rv;
        mojo::internal::StructHelper<RunOrClosePipeInput>::Initialize(&rv);
        return rv;
    }

    RunOrClosePipeInput::RunOrClosePipeInput()
    {
        // TODO(azani): Implement default values here when/if we support them.
        // TODO(azani): Set to UNKNOWN when unknown is implemented.
        SetActive(static_cast<Tag>(0));
    }

    RunOrClosePipeInput::~RunOrClosePipeInput()
    {
        DestroyActive();
    }

    void RunOrClosePipeInput::set_peer_associated_endpoint_closed_event(PeerAssociatedEndpointClosedEventPtr peer_associated_endpoint_closed_event)
    {
        SwitchActive(Tag::PEER_ASSOCIATED_ENDPOINT_CLOSED_EVENT);

        *(data_.peer_associated_endpoint_closed_event) = std::move(peer_associated_endpoint_closed_event);
    }
    void RunOrClosePipeInput::set_associated_endpoint_closed_before_sent_event(AssociatedEndpointClosedBeforeSentEventPtr associated_endpoint_closed_before_sent_event)
    {
        SwitchActive(Tag::ASSOCIATED_ENDPOINT_CLOSED_BEFORE_SENT_EVENT);

        *(data_.associated_endpoint_closed_before_sent_event) = std::move(associated_endpoint_closed_before_sent_event);
    }

    void RunOrClosePipeInput::SwitchActive(Tag new_active)
    {
        if (new_active == tag_) {
            return;
        }

        DestroyActive();
        SetActive(new_active);
    }

    void RunOrClosePipeInput::SetActive(Tag new_active)
    {
        switch (new_active) {

        case Tag::PEER_ASSOCIATED_ENDPOINT_CLOSED_EVENT:

            data_.peer_associated_endpoint_closed_event = new PeerAssociatedEndpointClosedEventPtr();
            break;
        case Tag::ASSOCIATED_ENDPOINT_CLOSED_BEFORE_SENT_EVENT:

            data_.associated_endpoint_closed_before_sent_event = new AssociatedEndpointClosedBeforeSentEventPtr();
            break;
        }

        tag_ = new_active;
    }

    void RunOrClosePipeInput::DestroyActive()
    {
        switch (tag_) {

        case Tag::PEER_ASSOCIATED_ENDPOINT_CLOSED_EVENT:

            delete data_.peer_associated_endpoint_closed_event;
            break;
        case Tag::ASSOCIATED_ENDPOINT_CLOSED_BEFORE_SENT_EVENT:

            delete data_.associated_endpoint_closed_before_sent_event;
            break;
        }
    }
    size_t RunOrClosePipeInput::Hash(size_t seed) const
    {
        seed = mojo::internal::HashCombine(seed, static_cast<uint32_t>(tag_));
        switch (tag_) {

        case Tag::PEER_ASSOCIATED_ENDPOINT_CLOSED_EVENT:
            return mojo::internal::Hash(seed, data_.peer_associated_endpoint_closed_event);
        case Tag::ASSOCIATED_ENDPOINT_CLOSED_BEFORE_SENT_EVENT:
            return mojo::internal::Hash(seed, data_.associated_endpoint_closed_before_sent_event);
        default:
            NOTREACHED();
            return seed;
        }
    }
} // namespace pipe_control
} // namespace mojo

namespace mojo {

// static
bool StructTraits<::mojo::pipe_control::RunOrClosePipeMessageParams::DataView, ::mojo::pipe_control::RunOrClosePipeMessageParamsPtr>::Read(
    ::mojo::pipe_control::RunOrClosePipeMessageParams::DataView input,
    ::mojo::pipe_control::RunOrClosePipeMessageParamsPtr* output)
{
    bool success = true;
    ::mojo::pipe_control::RunOrClosePipeMessageParamsPtr result(::mojo::pipe_control::RunOrClosePipeMessageParams::New());

    if (!input.ReadInput(&result->input))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::mojo::pipe_control::PeerAssociatedEndpointClosedEvent::DataView, ::mojo::pipe_control::PeerAssociatedEndpointClosedEventPtr>::Read(
    ::mojo::pipe_control::PeerAssociatedEndpointClosedEvent::DataView input,
    ::mojo::pipe_control::PeerAssociatedEndpointClosedEventPtr* output)
{
    bool success = true;
    ::mojo::pipe_control::PeerAssociatedEndpointClosedEventPtr result(::mojo::pipe_control::PeerAssociatedEndpointClosedEvent::New());

    result->id = input.id();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEvent::DataView, ::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEventPtr>::Read(
    ::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEvent::DataView input,
    ::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEventPtr* output)
{
    bool success = true;
    ::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEventPtr result(::mojo::pipe_control::AssociatedEndpointClosedBeforeSentEvent::New());

    result->id = input.id();
    *output = std::move(result);
    return success;
}

// static
bool UnionTraits<::mojo::pipe_control::RunOrClosePipeInput::DataView, ::mojo::pipe_control::RunOrClosePipeInputPtr>::Read(
    ::mojo::pipe_control::RunOrClosePipeInput::DataView input,
    ::mojo::pipe_control::RunOrClosePipeInputPtr* output)
{
    *output = ::mojo::pipe_control::RunOrClosePipeInput::New();
    ::mojo::pipe_control::RunOrClosePipeInputPtr& result = *output;

    internal::UnionAccessor<::mojo::pipe_control::RunOrClosePipeInput> result_acc(result.get());
    switch (input.tag()) {
    case ::mojo::pipe_control::RunOrClosePipeInput::Tag::PEER_ASSOCIATED_ENDPOINT_CLOSED_EVENT: {
        result_acc.SwitchActive(::mojo::pipe_control::RunOrClosePipeInput::Tag::PEER_ASSOCIATED_ENDPOINT_CLOSED_EVENT);
        if (!input.ReadPeerAssociatedEndpointClosedEvent(result_acc.data()->peer_associated_endpoint_closed_event))
            return false;
        break;
    }
    case ::mojo::pipe_control::RunOrClosePipeInput::Tag::ASSOCIATED_ENDPOINT_CLOSED_BEFORE_SENT_EVENT: {
        result_acc.SwitchActive(::mojo::pipe_control::RunOrClosePipeInput::Tag::ASSOCIATED_ENDPOINT_CLOSED_BEFORE_SENT_EVENT);
        if (!input.ReadAssociatedEndpointClosedBeforeSentEvent(result_acc.data()->associated_endpoint_closed_before_sent_event))
            return false;
        break;
    }
    default:
        return false;
    }
    return true;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif