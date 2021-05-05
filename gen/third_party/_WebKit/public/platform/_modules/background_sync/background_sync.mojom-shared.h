// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BACKGROUND_SYNC_BACKGROUND_SYNC_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BACKGROUND_SYNC_BACKGROUND_SYNC_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "third_party/WebKit/public/platform/modules/background_sync/background_sync.mojom-shared-internal.h"

namespace blink {
namespace mojom {
    class SyncRegistrationDataView;

} // namespace mojom
} // namespace blink

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::blink::mojom::SyncRegistrationDataView> {
        using Data = ::blink::mojom::internal::SyncRegistration_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace blink {
namespace mojom {

    enum class BackgroundSyncNetworkState : int32_t {
        ANY,
        AVOID_CELLULAR,
        ONLINE,
        MAX = BackgroundSyncNetworkState::ONLINE,
    };

    inline std::ostream& operator<<(std::ostream& os, BackgroundSyncNetworkState value)
    {
        switch (value) {
        case BackgroundSyncNetworkState::ANY:
            return os << "BackgroundSyncNetworkState::ANY";
        case BackgroundSyncNetworkState::AVOID_CELLULAR:
            return os << "BackgroundSyncNetworkState::AVOID_CELLULAR";
        case BackgroundSyncNetworkState::ONLINE:
            return os << "BackgroundSyncNetworkState::{ONLINE, MAX}";
        default:
            return os << "Unknown BackgroundSyncNetworkState value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(BackgroundSyncNetworkState value)
    {
        return internal::BackgroundSyncNetworkState_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class BackgroundSyncError : int32_t {
        NONE,
        STORAGE,
        NOT_FOUND,
        NO_SERVICE_WORKER,
        NOT_ALLOWED,
        PERMISSION_DENIED,
        MAX = BackgroundSyncError::PERMISSION_DENIED,
    };

    inline std::ostream& operator<<(std::ostream& os, BackgroundSyncError value)
    {
        switch (value) {
        case BackgroundSyncError::NONE:
            return os << "BackgroundSyncError::NONE";
        case BackgroundSyncError::STORAGE:
            return os << "BackgroundSyncError::STORAGE";
        case BackgroundSyncError::NOT_FOUND:
            return os << "BackgroundSyncError::NOT_FOUND";
        case BackgroundSyncError::NO_SERVICE_WORKER:
            return os << "BackgroundSyncError::NO_SERVICE_WORKER";
        case BackgroundSyncError::NOT_ALLOWED:
            return os << "BackgroundSyncError::NOT_ALLOWED";
        case BackgroundSyncError::PERMISSION_DENIED:
            return os << "BackgroundSyncError::{PERMISSION_DENIED, MAX}";
        default:
            return os << "Unknown BackgroundSyncError value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(BackgroundSyncError value)
    {
        return internal::BackgroundSyncError_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class BackgroundSyncState : int32_t {
        PENDING,
        FIRING,
        REREGISTERED_WHILE_FIRING,
    };

    inline std::ostream& operator<<(std::ostream& os, BackgroundSyncState value)
    {
        switch (value) {
        case BackgroundSyncState::PENDING:
            return os << "BackgroundSyncState::PENDING";
        case BackgroundSyncState::FIRING:
            return os << "BackgroundSyncState::FIRING";
        case BackgroundSyncState::REREGISTERED_WHILE_FIRING:
            return os << "BackgroundSyncState::REREGISTERED_WHILE_FIRING";
        default:
            return os << "Unknown BackgroundSyncState value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(BackgroundSyncState value)
    {
        return internal::BackgroundSyncState_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class BackgroundSyncEventLastChance : int32_t {
        IS_NOT_LAST_CHANCE,
        IS_LAST_CHANCE,
    };

    inline std::ostream& operator<<(std::ostream& os, BackgroundSyncEventLastChance value)
    {
        switch (value) {
        case BackgroundSyncEventLastChance::IS_NOT_LAST_CHANCE:
            return os << "BackgroundSyncEventLastChance::IS_NOT_LAST_CHANCE";
        case BackgroundSyncEventLastChance::IS_LAST_CHANCE:
            return os << "BackgroundSyncEventLastChance::IS_LAST_CHANCE";
        default:
            return os << "Unknown BackgroundSyncEventLastChance value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(BackgroundSyncEventLastChance value)
    {
        return internal::BackgroundSyncEventLastChance_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class BackgroundSyncServiceInterfaceBase {
    };

    using BackgroundSyncServicePtrDataView = mojo::InterfacePtrDataView<BackgroundSyncServiceInterfaceBase>;
    using BackgroundSyncServiceRequestDataView = mojo::InterfaceRequestDataView<BackgroundSyncServiceInterfaceBase>;
    using BackgroundSyncServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<BackgroundSyncServiceInterfaceBase>;
    using BackgroundSyncServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<BackgroundSyncServiceInterfaceBase>;
    class SyncRegistrationDataView {
    public:
        SyncRegistrationDataView() { }

        SyncRegistrationDataView(
            internal::SyncRegistration_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int64_t id() const
        {
            return data_->id;
        }
        inline void GetTagDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTag(UserType* output)
        {
            auto* pointer = data_->tag.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNetworkState(UserType* output) const
        {
            auto data_value = data_->network_state;
            return mojo::internal::Deserialize<::blink::mojom::BackgroundSyncNetworkState>(
                data_value, output);
        }

        BackgroundSyncNetworkState network_state() const
        {
            return static_cast<BackgroundSyncNetworkState>(data_->network_state);
        }

    private:
        internal::SyncRegistration_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class BackgroundSyncService_Register_ParamsDataView {
    public:
        BackgroundSyncService_Register_ParamsDataView() { }

        BackgroundSyncService_Register_ParamsDataView(
            internal::BackgroundSyncService_Register_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetOptionsDataView(
            SyncRegistrationDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOptions(UserType* output)
        {
            auto* pointer = data_->options.Get();
            return mojo::internal::Deserialize<::blink::mojom::SyncRegistrationDataView>(
                pointer, output, context_);
        }
        int64_t service_worker_registration_id() const
        {
            return data_->service_worker_registration_id;
        }

    private:
        internal::BackgroundSyncService_Register_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class BackgroundSyncService_Register_ResponseParamsDataView {
    public:
        BackgroundSyncService_Register_ResponseParamsDataView() { }

        BackgroundSyncService_Register_ResponseParamsDataView(
            internal::BackgroundSyncService_Register_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadErr(UserType* output) const
        {
            auto data_value = data_->err;
            return mojo::internal::Deserialize<::blink::mojom::BackgroundSyncError>(
                data_value, output);
        }

        BackgroundSyncError err() const
        {
            return static_cast<BackgroundSyncError>(data_->err);
        }
        inline void GetOptionsDataView(
            SyncRegistrationDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOptions(UserType* output)
        {
            auto* pointer = data_->options.Get();
            return mojo::internal::Deserialize<::blink::mojom::SyncRegistrationDataView>(
                pointer, output, context_);
        }

    private:
        internal::BackgroundSyncService_Register_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class BackgroundSyncService_GetRegistrations_ParamsDataView {
    public:
        BackgroundSyncService_GetRegistrations_ParamsDataView() { }

        BackgroundSyncService_GetRegistrations_ParamsDataView(
            internal::BackgroundSyncService_GetRegistrations_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int64_t service_worker_registration_id() const
        {
            return data_->service_worker_registration_id;
        }

    private:
        internal::BackgroundSyncService_GetRegistrations_Params_Data* data_ = nullptr;
    };

    class BackgroundSyncService_GetRegistrations_ResponseParamsDataView {
    public:
        BackgroundSyncService_GetRegistrations_ResponseParamsDataView() { }

        BackgroundSyncService_GetRegistrations_ResponseParamsDataView(
            internal::BackgroundSyncService_GetRegistrations_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadErr(UserType* output) const
        {
            auto data_value = data_->err;
            return mojo::internal::Deserialize<::blink::mojom::BackgroundSyncError>(
                data_value, output);
        }

        BackgroundSyncError err() const
        {
            return static_cast<BackgroundSyncError>(data_->err);
        }
        inline void GetRegistrationsDataView(
            mojo::ArrayDataView<SyncRegistrationDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRegistrations(UserType* output)
        {
            auto* pointer = data_->registrations.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::blink::mojom::SyncRegistrationDataView>>(
                pointer, output, context_);
        }

    private:
        internal::BackgroundSyncService_GetRegistrations_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

template <>
struct hash<::blink::mojom::BackgroundSyncNetworkState>
    : public mojo::internal::EnumHashImpl<::blink::mojom::BackgroundSyncNetworkState> {
};

template <>
struct hash<::blink::mojom::BackgroundSyncError>
    : public mojo::internal::EnumHashImpl<::blink::mojom::BackgroundSyncError> {
};

template <>
struct hash<::blink::mojom::BackgroundSyncState>
    : public mojo::internal::EnumHashImpl<::blink::mojom::BackgroundSyncState> {
};

template <>
struct hash<::blink::mojom::BackgroundSyncEventLastChance>
    : public mojo::internal::EnumHashImpl<::blink::mojom::BackgroundSyncEventLastChance> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::blink::mojom::BackgroundSyncNetworkState, ::blink::mojom::BackgroundSyncNetworkState> {
    static ::blink::mojom::BackgroundSyncNetworkState ToMojom(::blink::mojom::BackgroundSyncNetworkState input) { return input; }
    static bool FromMojom(::blink::mojom::BackgroundSyncNetworkState input, ::blink::mojom::BackgroundSyncNetworkState* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::BackgroundSyncNetworkState, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::BackgroundSyncNetworkState, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::BackgroundSyncNetworkState>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::blink::mojom::BackgroundSyncError, ::blink::mojom::BackgroundSyncError> {
    static ::blink::mojom::BackgroundSyncError ToMojom(::blink::mojom::BackgroundSyncError input) { return input; }
    static bool FromMojom(::blink::mojom::BackgroundSyncError input, ::blink::mojom::BackgroundSyncError* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::BackgroundSyncError, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::BackgroundSyncError, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::BackgroundSyncError>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::blink::mojom::BackgroundSyncState, ::blink::mojom::BackgroundSyncState> {
    static ::blink::mojom::BackgroundSyncState ToMojom(::blink::mojom::BackgroundSyncState input) { return input; }
    static bool FromMojom(::blink::mojom::BackgroundSyncState input, ::blink::mojom::BackgroundSyncState* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::BackgroundSyncState, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::BackgroundSyncState, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::BackgroundSyncState>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::blink::mojom::BackgroundSyncEventLastChance, ::blink::mojom::BackgroundSyncEventLastChance> {
    static ::blink::mojom::BackgroundSyncEventLastChance ToMojom(::blink::mojom::BackgroundSyncEventLastChance input) { return input; }
    static bool FromMojom(::blink::mojom::BackgroundSyncEventLastChance input, ::blink::mojom::BackgroundSyncEventLastChance* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::BackgroundSyncEventLastChance, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::BackgroundSyncEventLastChance, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::BackgroundSyncEventLastChance>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::SyncRegistrationDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::SyncRegistrationDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::SyncRegistration_Data);
            decltype(CallWithContext(Traits::tag, input, custom_context)) in_tag = CallWithContext(Traits::tag, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_tag, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::SyncRegistration_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::SyncRegistration_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->id = CallWithContext(Traits::id, input, custom_context);
            decltype(CallWithContext(Traits::tag, input, custom_context)) in_tag = CallWithContext(Traits::tag, input, custom_context);
            typename decltype(result->tag)::BaseType* tag_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_tag, buffer, &tag_ptr, context);
            result->tag.Set(tag_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->tag.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null tag in SyncRegistration struct");
            mojo::internal::Serialize<::blink::mojom::BackgroundSyncNetworkState>(
                CallWithContext(Traits::network_state, input, custom_context), &result->network_state);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::SyncRegistration_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::SyncRegistrationDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace blink {
namespace mojom {

    inline void SyncRegistrationDataView::GetTagDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->tag.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void BackgroundSyncService_Register_ParamsDataView::GetOptionsDataView(
        SyncRegistrationDataView* output)
    {
        auto pointer = data_->options.Get();
        *output = SyncRegistrationDataView(pointer, context_);
    }

    inline void BackgroundSyncService_Register_ResponseParamsDataView::GetOptionsDataView(
        SyncRegistrationDataView* output)
    {
        auto pointer = data_->options.Get();
        *output = SyncRegistrationDataView(pointer, context_);
    }

    inline void BackgroundSyncService_GetRegistrations_ResponseParamsDataView::GetRegistrationsDataView(
        mojo::ArrayDataView<SyncRegistrationDataView>* output)
    {
        auto pointer = data_->registrations.Get();
        *output = mojo::ArrayDataView<SyncRegistrationDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BACKGROUND_SYNC_BACKGROUND_SYNC_MOJOM_SHARED_H_
