// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_TYPES_MOJOM_SHARED_H_
#define COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_TYPES_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "components/filesystem/public/interfaces/types.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace filesystem {
namespace mojom {
    class TimespecOrNowDataView;

    class FileInformationDataView;

    class DirectoryEntryDataView;

} // namespace mojom
} // namespace filesystem

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::filesystem::mojom::TimespecOrNowDataView> {
        using Data = ::filesystem::mojom::internal::TimespecOrNow_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::filesystem::mojom::FileInformationDataView> {
        using Data = ::filesystem::mojom::internal::FileInformation_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::filesystem::mojom::DirectoryEntryDataView> {
        using Data = ::filesystem::mojom::internal::DirectoryEntry_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace filesystem {
namespace mojom {

    enum class FileError : int32_t {
        OK = 0,
        FAILED = -1,
        IN_USE = -2,
        EXISTS = -3,
        NOT_FOUND = -4,
        ACCESS_DENIED = -5,
        TOO_MANY_OPENED = -6,
        NO_MEMORY = -7,
        NO_SPACE = -8,
        NOT_A_DIRECTORY = -9,
        INVALID_OPERATION = -10,
        SECURITY = -11,
        ABORT = -12,
        NOT_A_FILE = -13,
        NOT_EMPTY = -14,
        INVALID_URL = -15,
        IO = -16,
    };

    inline std::ostream& operator<<(std::ostream& os, FileError value)
    {
        switch (value) {
        case FileError::IO:
            return os << "FileError::IO";
        case FileError::INVALID_URL:
            return os << "FileError::INVALID_URL";
        case FileError::NOT_EMPTY:
            return os << "FileError::NOT_EMPTY";
        case FileError::NOT_A_FILE:
            return os << "FileError::NOT_A_FILE";
        case FileError::ABORT:
            return os << "FileError::ABORT";
        case FileError::SECURITY:
            return os << "FileError::SECURITY";
        case FileError::INVALID_OPERATION:
            return os << "FileError::INVALID_OPERATION";
        case FileError::NOT_A_DIRECTORY:
            return os << "FileError::NOT_A_DIRECTORY";
        case FileError::NO_SPACE:
            return os << "FileError::NO_SPACE";
        case FileError::NO_MEMORY:
            return os << "FileError::NO_MEMORY";
        case FileError::TOO_MANY_OPENED:
            return os << "FileError::TOO_MANY_OPENED";
        case FileError::ACCESS_DENIED:
            return os << "FileError::ACCESS_DENIED";
        case FileError::NOT_FOUND:
            return os << "FileError::NOT_FOUND";
        case FileError::EXISTS:
            return os << "FileError::EXISTS";
        case FileError::IN_USE:
            return os << "FileError::IN_USE";
        case FileError::FAILED:
            return os << "FileError::FAILED";
        case FileError::OK:
            return os << "FileError::OK";
        default:
            return os << "Unknown FileError value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(FileError value)
    {
        return internal::FileError_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class Whence : int32_t {
        FROM_BEGIN = 0,
        FROM_CURRENT = 1,
        FROM_END = 2,
    };

    inline std::ostream& operator<<(std::ostream& os, Whence value)
    {
        switch (value) {
        case Whence::FROM_BEGIN:
            return os << "Whence::FROM_BEGIN";
        case Whence::FROM_CURRENT:
            return os << "Whence::FROM_CURRENT";
        case Whence::FROM_END:
            return os << "Whence::FROM_END";
        default:
            return os << "Unknown Whence value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(Whence value)
    {
        return internal::Whence_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class FsFileType : int32_t {
        UNKNOWN = 0,
        REGULAR_FILE,
        DIRECTORY,
    };

    inline std::ostream& operator<<(std::ostream& os, FsFileType value)
    {
        switch (value) {
        case FsFileType::UNKNOWN:
            return os << "FsFileType::UNKNOWN";
        case FsFileType::REGULAR_FILE:
            return os << "FsFileType::REGULAR_FILE";
        case FsFileType::DIRECTORY:
            return os << "FsFileType::DIRECTORY";
        default:
            return os << "Unknown FsFileType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(FsFileType value)
    {
        return internal::FsFileType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class TimespecOrNowDataView {
    public:
        TimespecOrNowDataView() { }

        TimespecOrNowDataView(
            internal::TimespecOrNow_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool now() const
        {
            return data_->now;
        }
        double seconds() const
        {
            return data_->seconds;
        }

    private:
        internal::TimespecOrNow_Data* data_ = nullptr;
    };

    class FileInformationDataView {
    public:
        FileInformationDataView() { }

        FileInformationDataView(
            internal::FileInformation_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::filesystem::mojom::FsFileType>(
                data_value, output);
        }

        FsFileType type() const
        {
            return static_cast<FsFileType>(data_->type);
        }
        int64_t size() const
        {
            return data_->size;
        }
        double atime() const
        {
            return data_->atime;
        }
        double mtime() const
        {
            return data_->mtime;
        }
        double ctime() const
        {
            return data_->ctime;
        }

    private:
        internal::FileInformation_Data* data_ = nullptr;
    };

    class DirectoryEntryDataView {
    public:
        DirectoryEntryDataView() { }

        DirectoryEntryDataView(
            internal::DirectoryEntry_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::filesystem::mojom::FsFileType>(
                data_value, output);
        }

        FsFileType type() const
        {
            return static_cast<FsFileType>(data_->type);
        }
        inline void GetNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::DirectoryEntry_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace filesystem

namespace std {

template <>
struct hash<::filesystem::mojom::FileError>
    : public mojo::internal::EnumHashImpl<::filesystem::mojom::FileError> {
};

template <>
struct hash<::filesystem::mojom::Whence>
    : public mojo::internal::EnumHashImpl<::filesystem::mojom::Whence> {
};

template <>
struct hash<::filesystem::mojom::FsFileType>
    : public mojo::internal::EnumHashImpl<::filesystem::mojom::FsFileType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::filesystem::mojom::FileError, ::filesystem::mojom::FileError> {
    static ::filesystem::mojom::FileError ToMojom(::filesystem::mojom::FileError input) { return input; }
    static bool FromMojom(::filesystem::mojom::FileError input, ::filesystem::mojom::FileError* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::filesystem::mojom::FileError, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::filesystem::mojom::FileError, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::filesystem::mojom::FileError>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::filesystem::mojom::Whence, ::filesystem::mojom::Whence> {
    static ::filesystem::mojom::Whence ToMojom(::filesystem::mojom::Whence input) { return input; }
    static bool FromMojom(::filesystem::mojom::Whence input, ::filesystem::mojom::Whence* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::filesystem::mojom::Whence, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::filesystem::mojom::Whence, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::filesystem::mojom::Whence>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::filesystem::mojom::FsFileType, ::filesystem::mojom::FsFileType> {
    static ::filesystem::mojom::FsFileType ToMojom(::filesystem::mojom::FsFileType input) { return input; }
    static bool FromMojom(::filesystem::mojom::FsFileType input, ::filesystem::mojom::FsFileType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::filesystem::mojom::FsFileType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::filesystem::mojom::FsFileType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::filesystem::mojom::FsFileType>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::filesystem::mojom::TimespecOrNowDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::filesystem::mojom::TimespecOrNowDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::filesystem::mojom::internal::TimespecOrNow_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::filesystem::mojom::internal::TimespecOrNow_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::filesystem::mojom::internal::TimespecOrNow_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->now = CallWithContext(Traits::now, input, custom_context);
            result->seconds = CallWithContext(Traits::seconds, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::filesystem::mojom::internal::TimespecOrNow_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::filesystem::mojom::TimespecOrNowDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::filesystem::mojom::FileInformationDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::filesystem::mojom::FileInformationDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::filesystem::mojom::internal::FileInformation_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::filesystem::mojom::internal::FileInformation_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::filesystem::mojom::internal::FileInformation_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::filesystem::mojom::FsFileType>(
                CallWithContext(Traits::type, input, custom_context), &result->type);
            result->size = CallWithContext(Traits::size, input, custom_context);
            result->atime = CallWithContext(Traits::atime, input, custom_context);
            result->mtime = CallWithContext(Traits::mtime, input, custom_context);
            result->ctime = CallWithContext(Traits::ctime, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::filesystem::mojom::internal::FileInformation_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::filesystem::mojom::FileInformationDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::filesystem::mojom::DirectoryEntryDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::filesystem::mojom::DirectoryEntryDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::filesystem::mojom::internal::DirectoryEntry_Data);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_name, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::filesystem::mojom::internal::DirectoryEntry_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::filesystem::mojom::internal::DirectoryEntry_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::filesystem::mojom::FsFileType>(
                CallWithContext(Traits::type, input, custom_context), &result->type);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            typename decltype(result->name)::BaseType* name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_name, buffer, &name_ptr, context);
            result->name.Set(name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null name in DirectoryEntry struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::filesystem::mojom::internal::DirectoryEntry_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::filesystem::mojom::DirectoryEntryDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace filesystem {
namespace mojom {

    inline void DirectoryEntryDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace filesystem

#endif // COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_TYPES_MOJOM_SHARED_H_
