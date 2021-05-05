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

#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"

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
namespace interface_control { // static
    RunMessageParamsPtr RunMessageParams::New()
    {
        RunMessageParamsPtr rv;
        mojo::internal::StructHelper<RunMessageParams>::Initialize(&rv);
        return rv;
    }

    RunMessageParams::RunMessageParams()
        : input()
    {
    }

    RunMessageParams::~RunMessageParams()
    {
    }
    size_t RunMessageParams::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->input);
        return seed;
    } // static
    RunResponseMessageParamsPtr RunResponseMessageParams::New()
    {
        RunResponseMessageParamsPtr rv;
        mojo::internal::StructHelper<RunResponseMessageParams>::Initialize(&rv);
        return rv;
    }

    RunResponseMessageParams::RunResponseMessageParams()
        : output()
    {
    }

    RunResponseMessageParams::~RunResponseMessageParams()
    {
    } // static
    QueryVersionPtr QueryVersion::New()
    {
        QueryVersionPtr rv;
        mojo::internal::StructHelper<QueryVersion>::Initialize(&rv);
        return rv;
    }

    QueryVersion::QueryVersion()
    {
    }

    QueryVersion::~QueryVersion()
    {
    }
    size_t QueryVersion::Hash(size_t seed) const
    {
        return seed;
    } // static
    QueryVersionResultPtr QueryVersionResult::New()
    {
        QueryVersionResultPtr rv;
        mojo::internal::StructHelper<QueryVersionResult>::Initialize(&rv);
        return rv;
    }

    QueryVersionResult::QueryVersionResult()
        : version()
    {
    }

    QueryVersionResult::~QueryVersionResult()
    {
    }
    size_t QueryVersionResult::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->version);
        return seed;
    } // static
    FlushForTestingPtr FlushForTesting::New()
    {
        FlushForTestingPtr rv;
        mojo::internal::StructHelper<FlushForTesting>::Initialize(&rv);
        return rv;
    }

    FlushForTesting::FlushForTesting()
    {
    }

    FlushForTesting::~FlushForTesting()
    {
    }
    size_t FlushForTesting::Hash(size_t seed) const
    {
        return seed;
    } // static
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
    RequireVersionPtr RequireVersion::New()
    {
        RequireVersionPtr rv;
        mojo::internal::StructHelper<RequireVersion>::Initialize(&rv);
        return rv;
    }

    RequireVersion::RequireVersion()
        : version()
    {
    }

    RequireVersion::~RequireVersion()
    {
    }
    size_t RequireVersion::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->version);
        return seed;
    } // static
    SendDisconnectReasonPtr SendDisconnectReason::New()
    {
        SendDisconnectReasonPtr rv;
        mojo::internal::StructHelper<SendDisconnectReason>::Initialize(&rv);
        return rv;
    }

    SendDisconnectReason::SendDisconnectReason()
        : custom_reason()
        , description()
    {
    }

    SendDisconnectReason::~SendDisconnectReason()
    {
    }
    size_t SendDisconnectReason::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->custom_reason);
        seed = mojo::internal::Hash(seed, this->description);
        return seed;
    } // static
    RunInputPtr RunInput::New()
    {
        RunInputPtr rv;
        mojo::internal::StructHelper<RunInput>::Initialize(&rv);
        return rv;
    }

    RunInput::RunInput()
    {
        // TODO(azani): Implement default values here when/if we support them.
        // TODO(azani): Set to UNKNOWN when unknown is implemented.
        SetActive(static_cast<Tag>(0));
    }

    RunInput::~RunInput()
    {
        DestroyActive();
    }

    void RunInput::set_query_version(QueryVersionPtr query_version)
    {
        SwitchActive(Tag::QUERY_VERSION);

        *(data_.query_version) = std::move(query_version);
    }
    void RunInput::set_flush_for_testing(FlushForTestingPtr flush_for_testing)
    {
        SwitchActive(Tag::FLUSH_FOR_TESTING);

        *(data_.flush_for_testing) = std::move(flush_for_testing);
    }

    void RunInput::SwitchActive(Tag new_active)
    {
        if (new_active == tag_) {
            return;
        }

        DestroyActive();
        SetActive(new_active);
    }

    void RunInput::SetActive(Tag new_active)
    {
        switch (new_active) {

        case Tag::QUERY_VERSION:

            data_.query_version = new QueryVersionPtr();
            break;
        case Tag::FLUSH_FOR_TESTING:

            data_.flush_for_testing = new FlushForTestingPtr();
            break;
        }

        tag_ = new_active;
    }

    void RunInput::DestroyActive()
    {
        switch (tag_) {

        case Tag::QUERY_VERSION:

            delete data_.query_version;
            break;
        case Tag::FLUSH_FOR_TESTING:

            delete data_.flush_for_testing;
            break;
        }
    }
    size_t RunInput::Hash(size_t seed) const
    {
        seed = mojo::internal::HashCombine(seed, static_cast<uint32_t>(tag_));
        switch (tag_) {

        case Tag::QUERY_VERSION:
            return mojo::internal::Hash(seed, data_.query_version);
        case Tag::FLUSH_FOR_TESTING:
            return mojo::internal::Hash(seed, data_.flush_for_testing);
        default:
            NOTREACHED();
            return seed;
        }
    } // static
    RunOutputPtr RunOutput::New()
    {
        RunOutputPtr rv;
        mojo::internal::StructHelper<RunOutput>::Initialize(&rv);
        return rv;
    }

    RunOutput::RunOutput()
    {
        // TODO(azani): Implement default values here when/if we support them.
        // TODO(azani): Set to UNKNOWN when unknown is implemented.
        SetActive(static_cast<Tag>(0));
    }

    RunOutput::~RunOutput()
    {
        DestroyActive();
    }

    void RunOutput::set_query_version_result(QueryVersionResultPtr query_version_result)
    {
        SwitchActive(Tag::QUERY_VERSION_RESULT);

        *(data_.query_version_result) = std::move(query_version_result);
    }

    void RunOutput::SwitchActive(Tag new_active)
    {
        if (new_active == tag_) {
            return;
        }

        DestroyActive();
        SetActive(new_active);
    }

    void RunOutput::SetActive(Tag new_active)
    {
        switch (new_active) {

        case Tag::QUERY_VERSION_RESULT:

            data_.query_version_result = new QueryVersionResultPtr();
            break;
        }

        tag_ = new_active;
    }

    void RunOutput::DestroyActive()
    {
        switch (tag_) {

        case Tag::QUERY_VERSION_RESULT:

            delete data_.query_version_result;
            break;
        }
    }
    size_t RunOutput::Hash(size_t seed) const
    {
        seed = mojo::internal::HashCombine(seed, static_cast<uint32_t>(tag_));
        switch (tag_) {

        case Tag::QUERY_VERSION_RESULT:
            return mojo::internal::Hash(seed, data_.query_version_result);
        default:
            NOTREACHED();
            return seed;
        }
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

    void RunOrClosePipeInput::set_require_version(RequireVersionPtr require_version)
    {
        SwitchActive(Tag::REQUIRE_VERSION);

        *(data_.require_version) = std::move(require_version);
    }
    void RunOrClosePipeInput::set_send_disconnect_reason(SendDisconnectReasonPtr send_disconnect_reason)
    {
        SwitchActive(Tag::SEND_DISCONNECT_REASON);

        *(data_.send_disconnect_reason) = std::move(send_disconnect_reason);
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

        case Tag::REQUIRE_VERSION:

            data_.require_version = new RequireVersionPtr();
            break;
        case Tag::SEND_DISCONNECT_REASON:

            data_.send_disconnect_reason = new SendDisconnectReasonPtr();
            break;
        }

        tag_ = new_active;
    }

    void RunOrClosePipeInput::DestroyActive()
    {
        switch (tag_) {

        case Tag::REQUIRE_VERSION:

            delete data_.require_version;
            break;
        case Tag::SEND_DISCONNECT_REASON:

            delete data_.send_disconnect_reason;
            break;
        }
    }
    size_t RunOrClosePipeInput::Hash(size_t seed) const
    {
        seed = mojo::internal::HashCombine(seed, static_cast<uint32_t>(tag_));
        switch (tag_) {

        case Tag::REQUIRE_VERSION:
            return mojo::internal::Hash(seed, data_.require_version);
        case Tag::SEND_DISCONNECT_REASON:
            return mojo::internal::Hash(seed, data_.send_disconnect_reason);
        default:
            NOTREACHED();
            return seed;
        }
    }
} // namespace interface_control
} // namespace mojo

namespace mojo {

// static
bool StructTraits<::mojo::interface_control::RunMessageParams::DataView, ::mojo::interface_control::RunMessageParamsPtr>::Read(
    ::mojo::interface_control::RunMessageParams::DataView input,
    ::mojo::interface_control::RunMessageParamsPtr* output)
{
    bool success = true;
    ::mojo::interface_control::RunMessageParamsPtr result(::mojo::interface_control::RunMessageParams::New());

    if (!input.ReadInput(&result->input))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::mojo::interface_control::RunResponseMessageParams::DataView, ::mojo::interface_control::RunResponseMessageParamsPtr>::Read(
    ::mojo::interface_control::RunResponseMessageParams::DataView input,
    ::mojo::interface_control::RunResponseMessageParamsPtr* output)
{
    bool success = true;
    ::mojo::interface_control::RunResponseMessageParamsPtr result(::mojo::interface_control::RunResponseMessageParams::New());

    if (!input.ReadOutput(&result->output))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::mojo::interface_control::QueryVersion::DataView, ::mojo::interface_control::QueryVersionPtr>::Read(
    ::mojo::interface_control::QueryVersion::DataView input,
    ::mojo::interface_control::QueryVersionPtr* output)
{
    bool success = true;
    ::mojo::interface_control::QueryVersionPtr result(::mojo::interface_control::QueryVersion::New());

    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::mojo::interface_control::QueryVersionResult::DataView, ::mojo::interface_control::QueryVersionResultPtr>::Read(
    ::mojo::interface_control::QueryVersionResult::DataView input,
    ::mojo::interface_control::QueryVersionResultPtr* output)
{
    bool success = true;
    ::mojo::interface_control::QueryVersionResultPtr result(::mojo::interface_control::QueryVersionResult::New());

    result->version = input.version();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::mojo::interface_control::FlushForTesting::DataView, ::mojo::interface_control::FlushForTestingPtr>::Read(
    ::mojo::interface_control::FlushForTesting::DataView input,
    ::mojo::interface_control::FlushForTestingPtr* output)
{
    bool success = true;
    ::mojo::interface_control::FlushForTestingPtr result(::mojo::interface_control::FlushForTesting::New());

    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::mojo::interface_control::RunOrClosePipeMessageParams::DataView, ::mojo::interface_control::RunOrClosePipeMessageParamsPtr>::Read(
    ::mojo::interface_control::RunOrClosePipeMessageParams::DataView input,
    ::mojo::interface_control::RunOrClosePipeMessageParamsPtr* output)
{
    bool success = true;
    ::mojo::interface_control::RunOrClosePipeMessageParamsPtr result(::mojo::interface_control::RunOrClosePipeMessageParams::New());

    if (!input.ReadInput(&result->input))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::mojo::interface_control::RequireVersion::DataView, ::mojo::interface_control::RequireVersionPtr>::Read(
    ::mojo::interface_control::RequireVersion::DataView input,
    ::mojo::interface_control::RequireVersionPtr* output)
{
    bool success = true;
    ::mojo::interface_control::RequireVersionPtr result(::mojo::interface_control::RequireVersion::New());

    result->version = input.version();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::mojo::interface_control::SendDisconnectReason::DataView, ::mojo::interface_control::SendDisconnectReasonPtr>::Read(
    ::mojo::interface_control::SendDisconnectReason::DataView input,
    ::mojo::interface_control::SendDisconnectReasonPtr* output)
{
    bool success = true;
    ::mojo::interface_control::SendDisconnectReasonPtr result(::mojo::interface_control::SendDisconnectReason::New());

    result->custom_reason = input.custom_reason();
    if (!input.ReadDescription(&result->description))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool UnionTraits<::mojo::interface_control::RunInput::DataView, ::mojo::interface_control::RunInputPtr>::Read(
    ::mojo::interface_control::RunInput::DataView input,
    ::mojo::interface_control::RunInputPtr* output)
{
    *output = ::mojo::interface_control::RunInput::New();
    ::mojo::interface_control::RunInputPtr& result = *output;

    internal::UnionAccessor<::mojo::interface_control::RunInput> result_acc(result.get());
    switch (input.tag()) {
    case ::mojo::interface_control::RunInput::Tag::QUERY_VERSION: {
        result_acc.SwitchActive(::mojo::interface_control::RunInput::Tag::QUERY_VERSION);
        if (!input.ReadQueryVersion(result_acc.data()->query_version))
            return false;
        break;
    }
    case ::mojo::interface_control::RunInput::Tag::FLUSH_FOR_TESTING: {
        result_acc.SwitchActive(::mojo::interface_control::RunInput::Tag::FLUSH_FOR_TESTING);
        if (!input.ReadFlushForTesting(result_acc.data()->flush_for_testing))
            return false;
        break;
    }
    default:
        return false;
    }
    return true;
}

// static
bool UnionTraits<::mojo::interface_control::RunOutput::DataView, ::mojo::interface_control::RunOutputPtr>::Read(
    ::mojo::interface_control::RunOutput::DataView input,
    ::mojo::interface_control::RunOutputPtr* output)
{
    *output = ::mojo::interface_control::RunOutput::New();
    ::mojo::interface_control::RunOutputPtr& result = *output;

    internal::UnionAccessor<::mojo::interface_control::RunOutput> result_acc(result.get());
    switch (input.tag()) {
    case ::mojo::interface_control::RunOutput::Tag::QUERY_VERSION_RESULT: {
        result_acc.SwitchActive(::mojo::interface_control::RunOutput::Tag::QUERY_VERSION_RESULT);
        if (!input.ReadQueryVersionResult(result_acc.data()->query_version_result))
            return false;
        break;
    }
    default:
        return false;
    }
    return true;
}

// static
bool UnionTraits<::mojo::interface_control::RunOrClosePipeInput::DataView, ::mojo::interface_control::RunOrClosePipeInputPtr>::Read(
    ::mojo::interface_control::RunOrClosePipeInput::DataView input,
    ::mojo::interface_control::RunOrClosePipeInputPtr* output)
{
    *output = ::mojo::interface_control::RunOrClosePipeInput::New();
    ::mojo::interface_control::RunOrClosePipeInputPtr& result = *output;

    internal::UnionAccessor<::mojo::interface_control::RunOrClosePipeInput> result_acc(result.get());
    switch (input.tag()) {
    case ::mojo::interface_control::RunOrClosePipeInput::Tag::REQUIRE_VERSION: {
        result_acc.SwitchActive(::mojo::interface_control::RunOrClosePipeInput::Tag::REQUIRE_VERSION);
        if (!input.ReadRequireVersion(result_acc.data()->require_version))
            return false;
        break;
    }
    case ::mojo::interface_control::RunOrClosePipeInput::Tag::SEND_DISCONNECT_REASON: {
        result_acc.SwitchActive(::mojo::interface_control::RunOrClosePipeInput::Tag::SEND_DISCONNECT_REASON);
        if (!input.ReadSendDisconnectReason(result_acc.data()->send_disconnect_reason))
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