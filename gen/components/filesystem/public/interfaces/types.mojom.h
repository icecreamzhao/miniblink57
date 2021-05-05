// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_TYPES_MOJOM_H_
#define COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_TYPES_MOJOM_H_

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
#include "components/filesystem/public/interfaces/types.mojom-shared.h"
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
#include <string>
#include <vector>

namespace filesystem {
namespace mojom {
    constexpr uint32_t kFlagOpen = 0x1U;
    constexpr uint32_t kFlagCreate = 0x2U;
    constexpr uint32_t kFlagOpenAlways = 0x4U;
    constexpr uint32_t kCreateAlways = 0x8U;
    constexpr uint32_t kFlagOpenTruncated = 0x10U;
    constexpr uint32_t kFlagRead = 0x20U;
    constexpr uint32_t kFlagWrite = 0x40U;
    constexpr uint32_t kFlagAppend = 0x80U;
    constexpr uint32_t kDeleteOnClose = 0x2000U;
    constexpr uint32_t kDeleteFlagRecursive = 0x1U;
    class TimespecOrNow;
    using TimespecOrNowPtr = mojo::InlinedStructPtr<TimespecOrNow>;

    class FileInformation;
    using FileInformationPtr = mojo::StructPtr<FileInformation>;

    class DirectoryEntry;
    using DirectoryEntryPtr = mojo::InlinedStructPtr<DirectoryEntry>;

    class TimespecOrNow {
    public:
        using DataView = TimespecOrNowDataView;
        using Data_ = internal::TimespecOrNow_Data;

        static TimespecOrNowPtr New();

        template <typename U>
        static TimespecOrNowPtr From(const U& u)
        {
            return mojo::TypeConverter<TimespecOrNowPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, TimespecOrNow>::Convert(*this);
        }

        TimespecOrNow();
        ~TimespecOrNow();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = TimespecOrNowPtr>
        TimespecOrNowPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, TimespecOrNow>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                TimespecOrNow::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                TimespecOrNow::DataView, std::vector<uint8_t>>(
                input, output);
        }

        bool now;
        double seconds;
    };

    class DirectoryEntry {
    public:
        using DataView = DirectoryEntryDataView;
        using Data_ = internal::DirectoryEntry_Data;

        static DirectoryEntryPtr New();

        template <typename U>
        static DirectoryEntryPtr From(const U& u)
        {
            return mojo::TypeConverter<DirectoryEntryPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, DirectoryEntry>::Convert(*this);
        }

        DirectoryEntry();
        ~DirectoryEntry();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = DirectoryEntryPtr>
        DirectoryEntryPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, DirectoryEntry>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                DirectoryEntry::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                DirectoryEntry::DataView, std::vector<uint8_t>>(
                input, output);
        }

        FsFileType type;
        std::string name;
    };

    class FileInformation {
    public:
        using DataView = FileInformationDataView;
        using Data_ = internal::FileInformation_Data;

        static FileInformationPtr New();

        template <typename U>
        static FileInformationPtr From(const U& u)
        {
            return mojo::TypeConverter<FileInformationPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, FileInformation>::Convert(*this);
        }

        FileInformation();
        ~FileInformation();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = FileInformationPtr>
        FileInformationPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, FileInformation>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                FileInformation::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                FileInformation::DataView, std::vector<uint8_t>>(
                input, output);
        }

        FsFileType type;
        int64_t size;
        double atime;
        double mtime;
        double ctime;
    };

    template <typename StructPtrType>
    TimespecOrNowPtr TimespecOrNow::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->now = mojo::internal::Clone(now);
        rv->seconds = mojo::internal::Clone(seconds);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, TimespecOrNow>::value>::type*>
    bool TimespecOrNow::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->now, other.now))
            return false;
        if (!mojo::internal::Equals(this->seconds, other.seconds))
            return false;
        return true;
    }
    template <typename StructPtrType>
    FileInformationPtr FileInformation::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->type = mojo::internal::Clone(type);
        rv->size = mojo::internal::Clone(size);
        rv->atime = mojo::internal::Clone(atime);
        rv->mtime = mojo::internal::Clone(mtime);
        rv->ctime = mojo::internal::Clone(ctime);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, FileInformation>::value>::type*>
    bool FileInformation::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->type, other.type))
            return false;
        if (!mojo::internal::Equals(this->size, other.size))
            return false;
        if (!mojo::internal::Equals(this->atime, other.atime))
            return false;
        if (!mojo::internal::Equals(this->mtime, other.mtime))
            return false;
        if (!mojo::internal::Equals(this->ctime, other.ctime))
            return false;
        return true;
    }
    template <typename StructPtrType>
    DirectoryEntryPtr DirectoryEntry::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->type = mojo::internal::Clone(type);
        rv->name = mojo::internal::Clone(name);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, DirectoryEntry>::value>::type*>
    bool DirectoryEntry::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->type, other.type))
            return false;
        if (!mojo::internal::Equals(this->name, other.name))
            return false;
        return true;
    }

} // namespace mojom
} // namespace filesystem

namespace mojo {

template <>
struct StructTraits<::filesystem::mojom::TimespecOrNow::DataView,
    ::filesystem::mojom::TimespecOrNowPtr> {
    static bool IsNull(const ::filesystem::mojom::TimespecOrNowPtr& input) { return !input; }
    static void SetToNull(::filesystem::mojom::TimespecOrNowPtr* output) { output->reset(); }

    static decltype(::filesystem::mojom::TimespecOrNow::now) now(
        const ::filesystem::mojom::TimespecOrNowPtr& input)
    {
        return input->now;
    }

    static decltype(::filesystem::mojom::TimespecOrNow::seconds) seconds(
        const ::filesystem::mojom::TimespecOrNowPtr& input)
    {
        return input->seconds;
    }

    static bool Read(::filesystem::mojom::TimespecOrNow::DataView input, ::filesystem::mojom::TimespecOrNowPtr* output);
};

template <>
struct StructTraits<::filesystem::mojom::FileInformation::DataView,
    ::filesystem::mojom::FileInformationPtr> {
    static bool IsNull(const ::filesystem::mojom::FileInformationPtr& input) { return !input; }
    static void SetToNull(::filesystem::mojom::FileInformationPtr* output) { output->reset(); }

    static decltype(::filesystem::mojom::FileInformation::type) type(
        const ::filesystem::mojom::FileInformationPtr& input)
    {
        return input->type;
    }

    static decltype(::filesystem::mojom::FileInformation::size) size(
        const ::filesystem::mojom::FileInformationPtr& input)
    {
        return input->size;
    }

    static decltype(::filesystem::mojom::FileInformation::atime) atime(
        const ::filesystem::mojom::FileInformationPtr& input)
    {
        return input->atime;
    }

    static decltype(::filesystem::mojom::FileInformation::mtime) mtime(
        const ::filesystem::mojom::FileInformationPtr& input)
    {
        return input->mtime;
    }

    static decltype(::filesystem::mojom::FileInformation::ctime) ctime(
        const ::filesystem::mojom::FileInformationPtr& input)
    {
        return input->ctime;
    }

    static bool Read(::filesystem::mojom::FileInformation::DataView input, ::filesystem::mojom::FileInformationPtr* output);
};

template <>
struct StructTraits<::filesystem::mojom::DirectoryEntry::DataView,
    ::filesystem::mojom::DirectoryEntryPtr> {
    static bool IsNull(const ::filesystem::mojom::DirectoryEntryPtr& input) { return !input; }
    static void SetToNull(::filesystem::mojom::DirectoryEntryPtr* output) { output->reset(); }

    static decltype(::filesystem::mojom::DirectoryEntry::type) type(
        const ::filesystem::mojom::DirectoryEntryPtr& input)
    {
        return input->type;
    }

    static const decltype(::filesystem::mojom::DirectoryEntry::name)& name(
        const ::filesystem::mojom::DirectoryEntryPtr& input)
    {
        return input->name;
    }

    static bool Read(::filesystem::mojom::DirectoryEntry::DataView input, ::filesystem::mojom::DirectoryEntryPtr* output);
};

} // namespace mojo

#endif // COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_TYPES_MOJOM_H_