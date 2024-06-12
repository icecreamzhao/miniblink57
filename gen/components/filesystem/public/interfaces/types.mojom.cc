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

#include "components/filesystem/public/interfaces/types.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
namespace filesystem {
namespace mojom { // static
    TimespecOrNowPtr TimespecOrNow::New()
    {
        TimespecOrNowPtr rv;
        mojo::internal::StructHelper<TimespecOrNow>::Initialize(&rv);
        return rv;
    }

    TimespecOrNow::TimespecOrNow()
        : now()
        , seconds()
    {
    }

    TimespecOrNow::~TimespecOrNow()
    {
    }
    size_t TimespecOrNow::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->now);
        seed = mojo::internal::Hash(seed, this->seconds);
        return seed;
    } // static
    FileInformationPtr FileInformation::New()
    {
        FileInformationPtr rv;
        mojo::internal::StructHelper<FileInformation>::Initialize(&rv);
        return rv;
    }

    FileInformation::FileInformation()
        : type()
        , size()
        , atime()
        , mtime()
        , ctime()
    {
    }

    FileInformation::~FileInformation()
    {
    }
    size_t FileInformation::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->type);
        seed = mojo::internal::Hash(seed, this->size);
        seed = mojo::internal::Hash(seed, this->atime);
        seed = mojo::internal::Hash(seed, this->mtime);
        seed = mojo::internal::Hash(seed, this->ctime);
        return seed;
    } // static
    DirectoryEntryPtr DirectoryEntry::New()
    {
        DirectoryEntryPtr rv;
        mojo::internal::StructHelper<DirectoryEntry>::Initialize(&rv);
        return rv;
    }

    DirectoryEntry::DirectoryEntry()
        : type()
        , name()
    {
    }

    DirectoryEntry::~DirectoryEntry()
    {
    }
    size_t DirectoryEntry::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->type);
        seed = mojo::internal::Hash(seed, this->name);
        return seed;
    }
} // namespace mojom
} // namespace filesystem

namespace mojo {

// static
bool StructTraits<::filesystem::mojom::TimespecOrNow::DataView, ::filesystem::mojom::TimespecOrNowPtr>::Read(
    ::filesystem::mojom::TimespecOrNow::DataView input,
    ::filesystem::mojom::TimespecOrNowPtr* output)
{
    bool success = true;
    ::filesystem::mojom::TimespecOrNowPtr result(::filesystem::mojom::TimespecOrNow::New());

    result->now = input.now();
    result->seconds = input.seconds();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::filesystem::mojom::FileInformation::DataView, ::filesystem::mojom::FileInformationPtr>::Read(
    ::filesystem::mojom::FileInformation::DataView input,
    ::filesystem::mojom::FileInformationPtr* output)
{
    bool success = true;
    ::filesystem::mojom::FileInformationPtr result(::filesystem::mojom::FileInformation::New());

    if (!input.ReadType(&result->type))
        success = false;
    result->size = input.size();
    result->atime = input.atime();
    result->mtime = input.mtime();
    result->ctime = input.ctime();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::filesystem::mojom::DirectoryEntry::DataView, ::filesystem::mojom::DirectoryEntryPtr>::Read(
    ::filesystem::mojom::DirectoryEntry::DataView input,
    ::filesystem::mojom::DirectoryEntryPtr* output)
{
    bool success = true;
    ::filesystem::mojom::DirectoryEntryPtr result(::filesystem::mojom::DirectoryEntry::New());

    if (!input.ReadType(&result->type))
        success = false;
    if (!input.ReadName(&result->name))
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