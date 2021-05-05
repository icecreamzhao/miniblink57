// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PERMISSIONS_PERMISSION_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PERMISSIONS_PERMISSION_MOJOM_SHARED_H_

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
#include "third_party/WebKit/public/platform/modules/permissions/permission.mojom-shared-internal.h"
#include "third_party/WebKit/public/platform/modules/permissions/permission_status.mojom-shared.h"
#include "url/mojo/origin.mojom-shared.h"

namespace blink {
namespace mojom {
    class MidiPermissionDescriptorDataView;

    class PermissionDescriptorDataView;

    class PermissionDescriptorExtensionDataView;

} // namespace mojom
} // namespace blink

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::blink::mojom::MidiPermissionDescriptorDataView> {
        using Data = ::blink::mojom::internal::MidiPermissionDescriptor_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::blink::mojom::PermissionDescriptorDataView> {
        using Data = ::blink::mojom::internal::PermissionDescriptor_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::blink::mojom::PermissionDescriptorExtensionDataView> {
        using Data = ::blink::mojom::internal::PermissionDescriptorExtension_Data;
        using DataAsArrayElement = Data;
        static constexpr MojomTypeCategory category = MojomTypeCategory::UNION;
    };

} // namespace internal
} // namespace mojo

namespace blink {
namespace mojom {

    enum class PermissionName : int32_t {
        GEOLOCATION,
        NOTIFICATIONS,
        PUSH_NOTIFICATIONS,
        MIDI,
        PROTECTED_MEDIA_IDENTIFIER,
        DURABLE_STORAGE,
        AUDIO_CAPTURE,
        VIDEO_CAPTURE,
        BACKGROUND_SYNC,
    };

    inline std::ostream& operator<<(std::ostream& os, PermissionName value)
    {
        switch (value) {
        case PermissionName::GEOLOCATION:
            return os << "PermissionName::GEOLOCATION";
        case PermissionName::NOTIFICATIONS:
            return os << "PermissionName::NOTIFICATIONS";
        case PermissionName::PUSH_NOTIFICATIONS:
            return os << "PermissionName::PUSH_NOTIFICATIONS";
        case PermissionName::MIDI:
            return os << "PermissionName::MIDI";
        case PermissionName::PROTECTED_MEDIA_IDENTIFIER:
            return os << "PermissionName::PROTECTED_MEDIA_IDENTIFIER";
        case PermissionName::DURABLE_STORAGE:
            return os << "PermissionName::DURABLE_STORAGE";
        case PermissionName::AUDIO_CAPTURE:
            return os << "PermissionName::AUDIO_CAPTURE";
        case PermissionName::VIDEO_CAPTURE:
            return os << "PermissionName::VIDEO_CAPTURE";
        case PermissionName::BACKGROUND_SYNC:
            return os << "PermissionName::BACKGROUND_SYNC";
        default:
            return os << "Unknown PermissionName value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(PermissionName value)
    {
        return internal::PermissionName_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class PermissionObserverInterfaceBase {
    };

    using PermissionObserverPtrDataView = mojo::InterfacePtrDataView<PermissionObserverInterfaceBase>;
    using PermissionObserverRequestDataView = mojo::InterfaceRequestDataView<PermissionObserverInterfaceBase>;
    using PermissionObserverAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<PermissionObserverInterfaceBase>;
    using PermissionObserverAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<PermissionObserverInterfaceBase>;
    class PermissionServiceInterfaceBase {
    };

    using PermissionServicePtrDataView = mojo::InterfacePtrDataView<PermissionServiceInterfaceBase>;
    using PermissionServiceRequestDataView = mojo::InterfaceRequestDataView<PermissionServiceInterfaceBase>;
    using PermissionServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<PermissionServiceInterfaceBase>;
    using PermissionServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<PermissionServiceInterfaceBase>;
    class MidiPermissionDescriptorDataView {
    public:
        MidiPermissionDescriptorDataView() { }

        MidiPermissionDescriptorDataView(
            internal::MidiPermissionDescriptor_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool sysex() const
        {
            return data_->sysex;
        }

    private:
        internal::MidiPermissionDescriptor_Data* data_ = nullptr;
    };

    class PermissionDescriptorDataView {
    public:
        PermissionDescriptorDataView() { }

        PermissionDescriptorDataView(
            internal::PermissionDescriptor_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output) const
        {
            auto data_value = data_->name;
            return mojo::internal::Deserialize<::blink::mojom::PermissionName>(
                data_value, output);
        }

        PermissionName name() const
        {
            return static_cast<PermissionName>(data_->name);
        }
        inline void GetExtensionDataView(
            PermissionDescriptorExtensionDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadExtension(UserType* output)
        {
            auto* pointer = &data_->extension;
            return mojo::internal::Deserialize<::blink::mojom::PermissionDescriptorExtensionDataView>(
                pointer, output, context_);
        }

    private:
        internal::PermissionDescriptor_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PermissionObserver_OnPermissionStatusChange_ParamsDataView {
    public:
        PermissionObserver_OnPermissionStatusChange_ParamsDataView() { }

        PermissionObserver_OnPermissionStatusChange_ParamsDataView(
            internal::PermissionObserver_OnPermissionStatusChange_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::blink::mojom::PermissionStatus>(
                data_value, output);
        }

        ::blink::mojom::PermissionStatus status() const
        {
            return static_cast<::blink::mojom::PermissionStatus>(data_->status);
        }

    private:
        internal::PermissionObserver_OnPermissionStatusChange_Params_Data* data_ = nullptr;
    };

    class PermissionService_HasPermission_ParamsDataView {
    public:
        PermissionService_HasPermission_ParamsDataView() { }

        PermissionService_HasPermission_ParamsDataView(
            internal::PermissionService_HasPermission_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPermissionDataView(
            PermissionDescriptorDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPermission(UserType* output)
        {
            auto* pointer = data_->permission.Get();
            return mojo::internal::Deserialize<::blink::mojom::PermissionDescriptorDataView>(
                pointer, output, context_);
        }
        inline void GetOriginDataView(
            ::url::mojom::OriginDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrigin(UserType* output)
        {
            auto* pointer = data_->origin.Get();
            return mojo::internal::Deserialize<::url::mojom::OriginDataView>(
                pointer, output, context_);
        }

    private:
        internal::PermissionService_HasPermission_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PermissionService_HasPermission_ResponseParamsDataView {
    public:
        PermissionService_HasPermission_ResponseParamsDataView() { }

        PermissionService_HasPermission_ResponseParamsDataView(
            internal::PermissionService_HasPermission_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::blink::mojom::PermissionStatus>(
                data_value, output);
        }

        ::blink::mojom::PermissionStatus status() const
        {
            return static_cast<::blink::mojom::PermissionStatus>(data_->status);
        }

    private:
        internal::PermissionService_HasPermission_ResponseParams_Data* data_ = nullptr;
    };

    class PermissionService_RequestPermission_ParamsDataView {
    public:
        PermissionService_RequestPermission_ParamsDataView() { }

        PermissionService_RequestPermission_ParamsDataView(
            internal::PermissionService_RequestPermission_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPermissionDataView(
            PermissionDescriptorDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPermission(UserType* output)
        {
            auto* pointer = data_->permission.Get();
            return mojo::internal::Deserialize<::blink::mojom::PermissionDescriptorDataView>(
                pointer, output, context_);
        }
        inline void GetOriginDataView(
            ::url::mojom::OriginDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrigin(UserType* output)
        {
            auto* pointer = data_->origin.Get();
            return mojo::internal::Deserialize<::url::mojom::OriginDataView>(
                pointer, output, context_);
        }
        bool user_gesture() const
        {
            return data_->user_gesture;
        }

    private:
        internal::PermissionService_RequestPermission_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PermissionService_RequestPermission_ResponseParamsDataView {
    public:
        PermissionService_RequestPermission_ResponseParamsDataView() { }

        PermissionService_RequestPermission_ResponseParamsDataView(
            internal::PermissionService_RequestPermission_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::blink::mojom::PermissionStatus>(
                data_value, output);
        }

        ::blink::mojom::PermissionStatus status() const
        {
            return static_cast<::blink::mojom::PermissionStatus>(data_->status);
        }

    private:
        internal::PermissionService_RequestPermission_ResponseParams_Data* data_ = nullptr;
    };

    class PermissionService_RequestPermissions_ParamsDataView {
    public:
        PermissionService_RequestPermissions_ParamsDataView() { }

        PermissionService_RequestPermissions_ParamsDataView(
            internal::PermissionService_RequestPermissions_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPermissionDataView(
            mojo::ArrayDataView<PermissionDescriptorDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPermission(UserType* output)
        {
            auto* pointer = data_->permission.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::blink::mojom::PermissionDescriptorDataView>>(
                pointer, output, context_);
        }
        inline void GetOriginDataView(
            ::url::mojom::OriginDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrigin(UserType* output)
        {
            auto* pointer = data_->origin.Get();
            return mojo::internal::Deserialize<::url::mojom::OriginDataView>(
                pointer, output, context_);
        }
        bool user_gesture() const
        {
            return data_->user_gesture;
        }

    private:
        internal::PermissionService_RequestPermissions_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PermissionService_RequestPermissions_ResponseParamsDataView {
    public:
        PermissionService_RequestPermissions_ResponseParamsDataView() { }

        PermissionService_RequestPermissions_ResponseParamsDataView(
            internal::PermissionService_RequestPermissions_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetStatusesDataView(
            mojo::ArrayDataView<::blink::mojom::PermissionStatus>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatuses(UserType* output)
        {
            auto* pointer = data_->statuses.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::blink::mojom::PermissionStatus>>(
                pointer, output, context_);
        }

    private:
        internal::PermissionService_RequestPermissions_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PermissionService_RevokePermission_ParamsDataView {
    public:
        PermissionService_RevokePermission_ParamsDataView() { }

        PermissionService_RevokePermission_ParamsDataView(
            internal::PermissionService_RevokePermission_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPermissionDataView(
            PermissionDescriptorDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPermission(UserType* output)
        {
            auto* pointer = data_->permission.Get();
            return mojo::internal::Deserialize<::blink::mojom::PermissionDescriptorDataView>(
                pointer, output, context_);
        }
        inline void GetOriginDataView(
            ::url::mojom::OriginDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrigin(UserType* output)
        {
            auto* pointer = data_->origin.Get();
            return mojo::internal::Deserialize<::url::mojom::OriginDataView>(
                pointer, output, context_);
        }

    private:
        internal::PermissionService_RevokePermission_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PermissionService_RevokePermission_ResponseParamsDataView {
    public:
        PermissionService_RevokePermission_ResponseParamsDataView() { }

        PermissionService_RevokePermission_ResponseParamsDataView(
            internal::PermissionService_RevokePermission_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::blink::mojom::PermissionStatus>(
                data_value, output);
        }

        ::blink::mojom::PermissionStatus status() const
        {
            return static_cast<::blink::mojom::PermissionStatus>(data_->status);
        }

    private:
        internal::PermissionService_RevokePermission_ResponseParams_Data* data_ = nullptr;
    };

    class PermissionService_AddPermissionObserver_ParamsDataView {
    public:
        PermissionService_AddPermissionObserver_ParamsDataView() { }

        PermissionService_AddPermissionObserver_ParamsDataView(
            internal::PermissionService_AddPermissionObserver_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPermissionDataView(
            PermissionDescriptorDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPermission(UserType* output)
        {
            auto* pointer = data_->permission.Get();
            return mojo::internal::Deserialize<::blink::mojom::PermissionDescriptorDataView>(
                pointer, output, context_);
        }
        inline void GetOriginDataView(
            ::url::mojom::OriginDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrigin(UserType* output)
        {
            auto* pointer = data_->origin.Get();
            return mojo::internal::Deserialize<::url::mojom::OriginDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLastKnownStatus(UserType* output) const
        {
            auto data_value = data_->last_known_status;
            return mojo::internal::Deserialize<::blink::mojom::PermissionStatus>(
                data_value, output);
        }

        ::blink::mojom::PermissionStatus last_known_status() const
        {
            return static_cast<::blink::mojom::PermissionStatus>(data_->last_known_status);
        }
        template <typename UserType>
        UserType TakeObserver()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::blink::mojom::PermissionObserverPtrDataView>(
                &data_->observer, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::PermissionService_AddPermissionObserver_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PermissionDescriptorExtensionDataView {
    public:
        using Tag = internal::PermissionDescriptorExtension_Data::PermissionDescriptorExtension_Tag;

        PermissionDescriptorExtensionDataView() { }

        PermissionDescriptorExtensionDataView(
            internal::PermissionDescriptorExtension_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const
        {
            // For inlined unions, |data_| is always non-null. In that case we need to
            // check |data_->is_null()|.
            return !data_ || data_->is_null();
        }

        Tag tag() const { return data_->tag; }
        bool is_midi() const { return data_->tag == Tag::MIDI; }
        inline void GetMidiDataView(
            MidiPermissionDescriptorDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMidi(UserType* output)
        {
            DCHECK(is_midi());
            return mojo::internal::Deserialize<::blink::mojom::MidiPermissionDescriptorDataView>(
                data_->data.f_midi.Get(), output, context_);
        }

    private:
        internal::PermissionDescriptorExtension_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

template <>
struct hash<::blink::mojom::PermissionName>
    : public mojo::internal::EnumHashImpl<::blink::mojom::PermissionName> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::blink::mojom::PermissionName, ::blink::mojom::PermissionName> {
    static ::blink::mojom::PermissionName ToMojom(::blink::mojom::PermissionName input) { return input; }
    static bool FromMojom(::blink::mojom::PermissionName input, ::blink::mojom::PermissionName* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::PermissionName, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::PermissionName, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::PermissionName>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::MidiPermissionDescriptorDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::MidiPermissionDescriptorDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::MidiPermissionDescriptor_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::MidiPermissionDescriptor_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::MidiPermissionDescriptor_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->sysex = CallWithContext(Traits::sysex, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::MidiPermissionDescriptor_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::MidiPermissionDescriptorDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::PermissionDescriptorDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::PermissionDescriptorDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::PermissionDescriptor_Data);
            decltype(CallWithContext(Traits::extension, input, custom_context)) in_extension = CallWithContext(Traits::extension, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::blink::mojom::PermissionDescriptorExtensionDataView>(
                in_extension, true, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::PermissionDescriptor_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::PermissionDescriptor_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::blink::mojom::PermissionName>(
                CallWithContext(Traits::name, input, custom_context), &result->name);
            decltype(CallWithContext(Traits::extension, input, custom_context)) in_extension = CallWithContext(Traits::extension, input, custom_context);
            auto extension_ptr = &result->extension;
            mojo::internal::Serialize<::blink::mojom::PermissionDescriptorExtensionDataView>(
                in_extension, buffer, &extension_ptr, true, context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::PermissionDescriptor_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::PermissionDescriptorDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::PermissionDescriptorExtensionDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = UnionTraits<::blink::mojom::PermissionDescriptorExtensionDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            bool inlined,
            SerializationContext* context)
        {
            size_t size = inlined ? 0 : sizeof(::blink::mojom::internal::PermissionDescriptorExtension_Data);

            if (CallIsNullIfExists<Traits>(input))
                return size;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            switch (CallWithContext(Traits::GetTag, input, custom_context)) {
            case ::blink::mojom::PermissionDescriptorExtensionDataView::Tag::MIDI: {
                decltype(CallWithContext(Traits::midi, input, custom_context))
                    in_midi
                    = CallWithContext(Traits::midi, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::blink::mojom::MidiPermissionDescriptorDataView>(
                    in_midi, context);
                break;
            }
            }
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::PermissionDescriptorExtension_Data** output,
            bool inlined,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                if (inlined)
                    (*output)->set_null();
                else
                    *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            if (!inlined)
                *output = ::blink::mojom::internal::PermissionDescriptorExtension_Data::New(buffer);

            ::blink::mojom::internal::PermissionDescriptorExtension_Data* result = *output;
            ALLOW_UNUSED_LOCAL(result);
            // TODO(azani): Handle unknown and objects.
            // Set the not-null flag.
            result->size = kUnionDataSize;
            result->tag = CallWithContext(Traits::GetTag, input, custom_context);
            switch (result->tag) {
            case ::blink::mojom::PermissionDescriptorExtensionDataView::Tag::MIDI: {
                decltype(CallWithContext(Traits::midi, input, custom_context))
                    in_midi
                    = CallWithContext(Traits::midi, input,
                        custom_context);
                typename decltype(result->data.f_midi)::BaseType* ptr;
                mojo::internal::Serialize<::blink::mojom::MidiPermissionDescriptorDataView>(
                    in_midi, buffer, &ptr, context);
                result->data.f_midi.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null midi in PermissionDescriptorExtension union");
                break;
            }
            }

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::PermissionDescriptorExtension_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input || input->is_null())
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::PermissionDescriptorExtensionDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace blink {
namespace mojom {

    inline void PermissionDescriptorDataView::GetExtensionDataView(
        PermissionDescriptorExtensionDataView* output)
    {
        auto pointer = &data_->extension;
        *output = PermissionDescriptorExtensionDataView(pointer, context_);
    }

    inline void PermissionService_HasPermission_ParamsDataView::GetPermissionDataView(
        PermissionDescriptorDataView* output)
    {
        auto pointer = data_->permission.Get();
        *output = PermissionDescriptorDataView(pointer, context_);
    }
    inline void PermissionService_HasPermission_ParamsDataView::GetOriginDataView(
        ::url::mojom::OriginDataView* output)
    {
        auto pointer = data_->origin.Get();
        *output = ::url::mojom::OriginDataView(pointer, context_);
    }

    inline void PermissionService_RequestPermission_ParamsDataView::GetPermissionDataView(
        PermissionDescriptorDataView* output)
    {
        auto pointer = data_->permission.Get();
        *output = PermissionDescriptorDataView(pointer, context_);
    }
    inline void PermissionService_RequestPermission_ParamsDataView::GetOriginDataView(
        ::url::mojom::OriginDataView* output)
    {
        auto pointer = data_->origin.Get();
        *output = ::url::mojom::OriginDataView(pointer, context_);
    }

    inline void PermissionService_RequestPermissions_ParamsDataView::GetPermissionDataView(
        mojo::ArrayDataView<PermissionDescriptorDataView>* output)
    {
        auto pointer = data_->permission.Get();
        *output = mojo::ArrayDataView<PermissionDescriptorDataView>(pointer, context_);
    }
    inline void PermissionService_RequestPermissions_ParamsDataView::GetOriginDataView(
        ::url::mojom::OriginDataView* output)
    {
        auto pointer = data_->origin.Get();
        *output = ::url::mojom::OriginDataView(pointer, context_);
    }

    inline void PermissionService_RequestPermissions_ResponseParamsDataView::GetStatusesDataView(
        mojo::ArrayDataView<::blink::mojom::PermissionStatus>* output)
    {
        auto pointer = data_->statuses.Get();
        *output = mojo::ArrayDataView<::blink::mojom::PermissionStatus>(pointer, context_);
    }

    inline void PermissionService_RevokePermission_ParamsDataView::GetPermissionDataView(
        PermissionDescriptorDataView* output)
    {
        auto pointer = data_->permission.Get();
        *output = PermissionDescriptorDataView(pointer, context_);
    }
    inline void PermissionService_RevokePermission_ParamsDataView::GetOriginDataView(
        ::url::mojom::OriginDataView* output)
    {
        auto pointer = data_->origin.Get();
        *output = ::url::mojom::OriginDataView(pointer, context_);
    }

    inline void PermissionService_AddPermissionObserver_ParamsDataView::GetPermissionDataView(
        PermissionDescriptorDataView* output)
    {
        auto pointer = data_->permission.Get();
        *output = PermissionDescriptorDataView(pointer, context_);
    }
    inline void PermissionService_AddPermissionObserver_ParamsDataView::GetOriginDataView(
        ::url::mojom::OriginDataView* output)
    {
        auto pointer = data_->origin.Get();
        *output = ::url::mojom::OriginDataView(pointer, context_);
    }

    inline void PermissionDescriptorExtensionDataView::GetMidiDataView(
        MidiPermissionDescriptorDataView* output)
    {
        DCHECK(is_midi());
        *output = MidiPermissionDescriptorDataView(data_->data.f_midi.Get(), context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PERMISSIONS_PERMISSION_MOJOM_SHARED_H_
