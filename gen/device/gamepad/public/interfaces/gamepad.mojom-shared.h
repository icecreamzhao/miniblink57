// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_GAMEPAD_PUBLIC_INTERFACES_GAMEPAD_MOJOM_SHARED_H_
#define DEVICE_GAMEPAD_PUBLIC_INTERFACES_GAMEPAD_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/gamepad/public/interfaces/gamepad.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace device {
namespace mojom {
    class GamepadQuaternionDataView;

    class GamepadVectorDataView;

    class GamepadButtonDataView;

    class GamepadPoseDataView;

    class GamepadDataView;

} // namespace mojom
} // namespace device

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::device::mojom::GamepadQuaternionDataView> {
        using Data = ::device::mojom::internal::GamepadQuaternion_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::mojom::GamepadVectorDataView> {
        using Data = ::device::mojom::internal::GamepadVector_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::mojom::GamepadButtonDataView> {
        using Data = ::device::mojom::internal::GamepadButton_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::mojom::GamepadPoseDataView> {
        using Data = ::device::mojom::internal::GamepadPose_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::mojom::GamepadDataView> {
        using Data = ::device::mojom::internal::Gamepad_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace device {
namespace mojom {

    enum class GamepadHand : int32_t {
        GamepadHandNone = 0,
        GamepadHandLeft = 1,
        GamepadHandRight = 2,
    };

    inline std::ostream& operator<<(std::ostream& os, GamepadHand value)
    {
        switch (value) {
        case GamepadHand::GamepadHandNone:
            return os << "GamepadHand::GamepadHandNone";
        case GamepadHand::GamepadHandLeft:
            return os << "GamepadHand::GamepadHandLeft";
        case GamepadHand::GamepadHandRight:
            return os << "GamepadHand::GamepadHandRight";
        default:
            return os << "Unknown GamepadHand value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(GamepadHand value)
    {
        return internal::GamepadHand_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class GamepadObserverInterfaceBase {
    };

    using GamepadObserverPtrDataView = mojo::InterfacePtrDataView<GamepadObserverInterfaceBase>;
    using GamepadObserverRequestDataView = mojo::InterfaceRequestDataView<GamepadObserverInterfaceBase>;
    using GamepadObserverAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<GamepadObserverInterfaceBase>;
    using GamepadObserverAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<GamepadObserverInterfaceBase>;
    class GamepadMonitorInterfaceBase {
    };

    using GamepadMonitorPtrDataView = mojo::InterfacePtrDataView<GamepadMonitorInterfaceBase>;
    using GamepadMonitorRequestDataView = mojo::InterfaceRequestDataView<GamepadMonitorInterfaceBase>;
    using GamepadMonitorAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<GamepadMonitorInterfaceBase>;
    using GamepadMonitorAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<GamepadMonitorInterfaceBase>;
    class GamepadQuaternionDataView {
    public:
        GamepadQuaternionDataView() { }

        GamepadQuaternionDataView(
            internal::GamepadQuaternion_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        float x() const
        {
            return data_->x;
        }
        float y() const
        {
            return data_->y;
        }
        float z() const
        {
            return data_->z;
        }
        float w() const
        {
            return data_->w;
        }

    private:
        internal::GamepadQuaternion_Data* data_ = nullptr;
    };

    class GamepadVectorDataView {
    public:
        GamepadVectorDataView() { }

        GamepadVectorDataView(
            internal::GamepadVector_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        float x() const
        {
            return data_->x;
        }
        float y() const
        {
            return data_->y;
        }
        float z() const
        {
            return data_->z;
        }

    private:
        internal::GamepadVector_Data* data_ = nullptr;
    };

    class GamepadButtonDataView {
    public:
        GamepadButtonDataView() { }

        GamepadButtonDataView(
            internal::GamepadButton_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool pressed() const
        {
            return data_->pressed;
        }
        bool touched() const
        {
            return data_->touched;
        }
        double value() const
        {
            return data_->value;
        }

    private:
        internal::GamepadButton_Data* data_ = nullptr;
    };

    class GamepadPoseDataView {
    public:
        GamepadPoseDataView() { }

        GamepadPoseDataView(
            internal::GamepadPose_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetOrientationDataView(
            GamepadQuaternionDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrientation(UserType* output)
        {
            auto* pointer = data_->orientation.Get();
            return mojo::internal::Deserialize<::device::mojom::GamepadQuaternionDataView>(
                pointer, output, context_);
        }
        inline void GetPositionDataView(
            GamepadVectorDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPosition(UserType* output)
        {
            auto* pointer = data_->position.Get();
            return mojo::internal::Deserialize<::device::mojom::GamepadVectorDataView>(
                pointer, output, context_);
        }
        inline void GetAngularVelocityDataView(
            GamepadVectorDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAngularVelocity(UserType* output)
        {
            auto* pointer = data_->angular_velocity.Get();
            return mojo::internal::Deserialize<::device::mojom::GamepadVectorDataView>(
                pointer, output, context_);
        }
        inline void GetLinearVelocityDataView(
            GamepadVectorDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLinearVelocity(UserType* output)
        {
            auto* pointer = data_->linear_velocity.Get();
            return mojo::internal::Deserialize<::device::mojom::GamepadVectorDataView>(
                pointer, output, context_);
        }
        inline void GetAngularAccelerationDataView(
            GamepadVectorDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAngularAcceleration(UserType* output)
        {
            auto* pointer = data_->angular_acceleration.Get();
            return mojo::internal::Deserialize<::device::mojom::GamepadVectorDataView>(
                pointer, output, context_);
        }
        inline void GetLinearAccelerationDataView(
            GamepadVectorDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLinearAcceleration(UserType* output)
        {
            auto* pointer = data_->linear_acceleration.Get();
            return mojo::internal::Deserialize<::device::mojom::GamepadVectorDataView>(
                pointer, output, context_);
        }

    private:
        internal::GamepadPose_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class GamepadDataView {
    public:
        GamepadDataView() { }

        GamepadDataView(
            internal::Gamepad_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        bool connected() const
        {
            return data_->connected;
        }
        inline void GetIdDataView(
            mojo::ArrayDataView<uint16_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadId(UserType* output)
        {
            auto* pointer = data_->id.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint16_t>>(
                pointer, output, context_);
        }
        uint64_t timestamp() const
        {
            return data_->timestamp;
        }
        inline void GetAxesDataView(
            mojo::ArrayDataView<double>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAxes(UserType* output)
        {
            auto* pointer = data_->axes.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<double>>(
                pointer, output, context_);
        }
        inline void GetButtonsDataView(
            mojo::ArrayDataView<GamepadButtonDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadButtons(UserType* output)
        {
            auto* pointer = data_->buttons.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::device::mojom::GamepadButtonDataView>>(
                pointer, output, context_);
        }
        inline void GetMappingDataView(
            mojo::ArrayDataView<uint16_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMapping(UserType* output)
        {
            auto* pointer = data_->mapping.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint16_t>>(
                pointer, output, context_);
        }
        inline void GetPoseDataView(
            GamepadPoseDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPose(UserType* output)
        {
            auto* pointer = data_->pose.Get();
            return mojo::internal::Deserialize<::device::mojom::GamepadPoseDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadHand(UserType* output) const
        {
            auto data_value = data_->hand;
            return mojo::internal::Deserialize<::device::mojom::GamepadHand>(
                data_value, output);
        }

        GamepadHand hand() const
        {
            return static_cast<GamepadHand>(data_->hand);
        }
        uint32_t display_id() const
        {
            return data_->display_id;
        }

    private:
        internal::Gamepad_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class GamepadObserver_GamepadConnected_ParamsDataView {
    public:
        GamepadObserver_GamepadConnected_ParamsDataView() { }

        GamepadObserver_GamepadConnected_ParamsDataView(
            internal::GamepadObserver_GamepadConnected_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t index() const
        {
            return data_->index;
        }
        inline void GetGamepadDataView(
            GamepadDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGamepad(UserType* output)
        {
            auto* pointer = data_->gamepad.Get();
            return mojo::internal::Deserialize<::device::mojom::GamepadDataView>(
                pointer, output, context_);
        }

    private:
        internal::GamepadObserver_GamepadConnected_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class GamepadObserver_GamepadDisconnected_ParamsDataView {
    public:
        GamepadObserver_GamepadDisconnected_ParamsDataView() { }

        GamepadObserver_GamepadDisconnected_ParamsDataView(
            internal::GamepadObserver_GamepadDisconnected_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t index() const
        {
            return data_->index;
        }
        inline void GetGamepadDataView(
            GamepadDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGamepad(UserType* output)
        {
            auto* pointer = data_->gamepad.Get();
            return mojo::internal::Deserialize<::device::mojom::GamepadDataView>(
                pointer, output, context_);
        }

    private:
        internal::GamepadObserver_GamepadDisconnected_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class GamepadMonitor_GamepadStartPolling_ParamsDataView {
    public:
        GamepadMonitor_GamepadStartPolling_ParamsDataView() { }

        GamepadMonitor_GamepadStartPolling_ParamsDataView(
            internal::GamepadMonitor_GamepadStartPolling_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::GamepadMonitor_GamepadStartPolling_Params_Data* data_ = nullptr;
    };

    class GamepadMonitor_GamepadStartPolling_ResponseParamsDataView {
    public:
        GamepadMonitor_GamepadStartPolling_ResponseParamsDataView() { }

        GamepadMonitor_GamepadStartPolling_ResponseParamsDataView(
            internal::GamepadMonitor_GamepadStartPolling_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        mojo::ScopedSharedBufferHandle TakeMemoryHandle()
        {
            mojo::ScopedSharedBufferHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedSharedBufferHandle>(
                &data_->memory_handle, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::GamepadMonitor_GamepadStartPolling_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class GamepadMonitor_GamepadStopPolling_ParamsDataView {
    public:
        GamepadMonitor_GamepadStopPolling_ParamsDataView() { }

        GamepadMonitor_GamepadStopPolling_ParamsDataView(
            internal::GamepadMonitor_GamepadStopPolling_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::GamepadMonitor_GamepadStopPolling_Params_Data* data_ = nullptr;
    };

    class GamepadMonitor_GamepadStopPolling_ResponseParamsDataView {
    public:
        GamepadMonitor_GamepadStopPolling_ResponseParamsDataView() { }

        GamepadMonitor_GamepadStopPolling_ResponseParamsDataView(
            internal::GamepadMonitor_GamepadStopPolling_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::GamepadMonitor_GamepadStopPolling_ResponseParams_Data* data_ = nullptr;
    };

    class GamepadMonitor_SetObserver_ParamsDataView {
    public:
        GamepadMonitor_SetObserver_ParamsDataView() { }

        GamepadMonitor_SetObserver_ParamsDataView(
            internal::GamepadMonitor_SetObserver_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeGamepadObserver()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::device::mojom::GamepadObserverPtrDataView>(
                &data_->gamepad_observer, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::GamepadMonitor_SetObserver_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace device

namespace std {

template <>
struct hash<::device::mojom::GamepadHand>
    : public mojo::internal::EnumHashImpl<::device::mojom::GamepadHand> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::device::mojom::GamepadHand, ::device::mojom::GamepadHand> {
    static ::device::mojom::GamepadHand ToMojom(::device::mojom::GamepadHand input) { return input; }
    static bool FromMojom(::device::mojom::GamepadHand input, ::device::mojom::GamepadHand* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::GamepadHand, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::mojom::GamepadHand, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::mojom::GamepadHand>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::GamepadQuaternionDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::mojom::GamepadQuaternionDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::mojom::internal::GamepadQuaternion_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::mojom::internal::GamepadQuaternion_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::mojom::internal::GamepadQuaternion_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->x = CallWithContext(Traits::x, input, custom_context);
            result->y = CallWithContext(Traits::y, input, custom_context);
            result->z = CallWithContext(Traits::z, input, custom_context);
            result->w = CallWithContext(Traits::w, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::mojom::internal::GamepadQuaternion_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::mojom::GamepadQuaternionDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::GamepadVectorDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::mojom::GamepadVectorDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::mojom::internal::GamepadVector_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::mojom::internal::GamepadVector_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::mojom::internal::GamepadVector_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->x = CallWithContext(Traits::x, input, custom_context);
            result->y = CallWithContext(Traits::y, input, custom_context);
            result->z = CallWithContext(Traits::z, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::mojom::internal::GamepadVector_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::mojom::GamepadVectorDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::GamepadButtonDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::mojom::GamepadButtonDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::mojom::internal::GamepadButton_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::mojom::internal::GamepadButton_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::mojom::internal::GamepadButton_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->pressed = CallWithContext(Traits::pressed, input, custom_context);
            result->touched = CallWithContext(Traits::touched, input, custom_context);
            result->value = CallWithContext(Traits::value, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::mojom::internal::GamepadButton_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::mojom::GamepadButtonDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::GamepadPoseDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::mojom::GamepadPoseDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::mojom::internal::GamepadPose_Data);
            decltype(CallWithContext(Traits::orientation, input, custom_context)) in_orientation = CallWithContext(Traits::orientation, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::device::mojom::GamepadQuaternionDataView>(
                in_orientation, context);
            decltype(CallWithContext(Traits::position, input, custom_context)) in_position = CallWithContext(Traits::position, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::device::mojom::GamepadVectorDataView>(
                in_position, context);
            decltype(CallWithContext(Traits::angular_velocity, input, custom_context)) in_angular_velocity = CallWithContext(Traits::angular_velocity, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::device::mojom::GamepadVectorDataView>(
                in_angular_velocity, context);
            decltype(CallWithContext(Traits::linear_velocity, input, custom_context)) in_linear_velocity = CallWithContext(Traits::linear_velocity, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::device::mojom::GamepadVectorDataView>(
                in_linear_velocity, context);
            decltype(CallWithContext(Traits::angular_acceleration, input, custom_context)) in_angular_acceleration = CallWithContext(Traits::angular_acceleration, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::device::mojom::GamepadVectorDataView>(
                in_angular_acceleration, context);
            decltype(CallWithContext(Traits::linear_acceleration, input, custom_context)) in_linear_acceleration = CallWithContext(Traits::linear_acceleration, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::device::mojom::GamepadVectorDataView>(
                in_linear_acceleration, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::mojom::internal::GamepadPose_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::mojom::internal::GamepadPose_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::orientation, input, custom_context)) in_orientation = CallWithContext(Traits::orientation, input, custom_context);
            typename decltype(result->orientation)::BaseType* orientation_ptr;
            mojo::internal::Serialize<::device::mojom::GamepadQuaternionDataView>(
                in_orientation, buffer, &orientation_ptr, context);
            result->orientation.Set(orientation_ptr);
            decltype(CallWithContext(Traits::position, input, custom_context)) in_position = CallWithContext(Traits::position, input, custom_context);
            typename decltype(result->position)::BaseType* position_ptr;
            mojo::internal::Serialize<::device::mojom::GamepadVectorDataView>(
                in_position, buffer, &position_ptr, context);
            result->position.Set(position_ptr);
            decltype(CallWithContext(Traits::angular_velocity, input, custom_context)) in_angular_velocity = CallWithContext(Traits::angular_velocity, input, custom_context);
            typename decltype(result->angular_velocity)::BaseType* angular_velocity_ptr;
            mojo::internal::Serialize<::device::mojom::GamepadVectorDataView>(
                in_angular_velocity, buffer, &angular_velocity_ptr, context);
            result->angular_velocity.Set(angular_velocity_ptr);
            decltype(CallWithContext(Traits::linear_velocity, input, custom_context)) in_linear_velocity = CallWithContext(Traits::linear_velocity, input, custom_context);
            typename decltype(result->linear_velocity)::BaseType* linear_velocity_ptr;
            mojo::internal::Serialize<::device::mojom::GamepadVectorDataView>(
                in_linear_velocity, buffer, &linear_velocity_ptr, context);
            result->linear_velocity.Set(linear_velocity_ptr);
            decltype(CallWithContext(Traits::angular_acceleration, input, custom_context)) in_angular_acceleration = CallWithContext(Traits::angular_acceleration, input, custom_context);
            typename decltype(result->angular_acceleration)::BaseType* angular_acceleration_ptr;
            mojo::internal::Serialize<::device::mojom::GamepadVectorDataView>(
                in_angular_acceleration, buffer, &angular_acceleration_ptr, context);
            result->angular_acceleration.Set(angular_acceleration_ptr);
            decltype(CallWithContext(Traits::linear_acceleration, input, custom_context)) in_linear_acceleration = CallWithContext(Traits::linear_acceleration, input, custom_context);
            typename decltype(result->linear_acceleration)::BaseType* linear_acceleration_ptr;
            mojo::internal::Serialize<::device::mojom::GamepadVectorDataView>(
                in_linear_acceleration, buffer, &linear_acceleration_ptr, context);
            result->linear_acceleration.Set(linear_acceleration_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::mojom::internal::GamepadPose_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::mojom::GamepadPoseDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::GamepadDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::mojom::GamepadDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::mojom::internal::Gamepad_Data);
            decltype(CallWithContext(Traits::id, input, custom_context)) in_id = CallWithContext(Traits::id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint16_t>>(
                in_id, context);
            decltype(CallWithContext(Traits::axes, input, custom_context)) in_axes = CallWithContext(Traits::axes, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<double>>(
                in_axes, context);
            decltype(CallWithContext(Traits::buttons, input, custom_context)) in_buttons = CallWithContext(Traits::buttons, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::device::mojom::GamepadButtonDataView>>(
                in_buttons, context);
            decltype(CallWithContext(Traits::mapping, input, custom_context)) in_mapping = CallWithContext(Traits::mapping, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint16_t>>(
                in_mapping, context);
            decltype(CallWithContext(Traits::pose, input, custom_context)) in_pose = CallWithContext(Traits::pose, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::device::mojom::GamepadPoseDataView>(
                in_pose, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::mojom::internal::Gamepad_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::mojom::internal::Gamepad_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->connected = CallWithContext(Traits::connected, input, custom_context);
            decltype(CallWithContext(Traits::id, input, custom_context)) in_id = CallWithContext(Traits::id, input, custom_context);
            typename decltype(result->id)::BaseType* id_ptr;
            const mojo::internal::ContainerValidateParams id_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint16_t>>(
                in_id, buffer, &id_ptr, &id_validate_params,
                context);
            result->id.Set(id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null id in Gamepad struct");
            result->timestamp = CallWithContext(Traits::timestamp, input, custom_context);
            decltype(CallWithContext(Traits::axes, input, custom_context)) in_axes = CallWithContext(Traits::axes, input, custom_context);
            typename decltype(result->axes)::BaseType* axes_ptr;
            const mojo::internal::ContainerValidateParams axes_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<double>>(
                in_axes, buffer, &axes_ptr, &axes_validate_params,
                context);
            result->axes.Set(axes_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->axes.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null axes in Gamepad struct");
            decltype(CallWithContext(Traits::buttons, input, custom_context)) in_buttons = CallWithContext(Traits::buttons, input, custom_context);
            typename decltype(result->buttons)::BaseType* buttons_ptr;
            const mojo::internal::ContainerValidateParams buttons_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::device::mojom::GamepadButtonDataView>>(
                in_buttons, buffer, &buttons_ptr, &buttons_validate_params,
                context);
            result->buttons.Set(buttons_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->buttons.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null buttons in Gamepad struct");
            decltype(CallWithContext(Traits::mapping, input, custom_context)) in_mapping = CallWithContext(Traits::mapping, input, custom_context);
            typename decltype(result->mapping)::BaseType* mapping_ptr;
            const mojo::internal::ContainerValidateParams mapping_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint16_t>>(
                in_mapping, buffer, &mapping_ptr, &mapping_validate_params,
                context);
            result->mapping.Set(mapping_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->mapping.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null mapping in Gamepad struct");
            decltype(CallWithContext(Traits::pose, input, custom_context)) in_pose = CallWithContext(Traits::pose, input, custom_context);
            typename decltype(result->pose)::BaseType* pose_ptr;
            mojo::internal::Serialize<::device::mojom::GamepadPoseDataView>(
                in_pose, buffer, &pose_ptr, context);
            result->pose.Set(pose_ptr);
            mojo::internal::Serialize<::device::mojom::GamepadHand>(
                CallWithContext(Traits::hand, input, custom_context), &result->hand);
            result->display_id = CallWithContext(Traits::display_id, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::mojom::internal::Gamepad_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::mojom::GamepadDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace device {
namespace mojom {

    inline void GamepadPoseDataView::GetOrientationDataView(
        GamepadQuaternionDataView* output)
    {
        auto pointer = data_->orientation.Get();
        *output = GamepadQuaternionDataView(pointer, context_);
    }
    inline void GamepadPoseDataView::GetPositionDataView(
        GamepadVectorDataView* output)
    {
        auto pointer = data_->position.Get();
        *output = GamepadVectorDataView(pointer, context_);
    }
    inline void GamepadPoseDataView::GetAngularVelocityDataView(
        GamepadVectorDataView* output)
    {
        auto pointer = data_->angular_velocity.Get();
        *output = GamepadVectorDataView(pointer, context_);
    }
    inline void GamepadPoseDataView::GetLinearVelocityDataView(
        GamepadVectorDataView* output)
    {
        auto pointer = data_->linear_velocity.Get();
        *output = GamepadVectorDataView(pointer, context_);
    }
    inline void GamepadPoseDataView::GetAngularAccelerationDataView(
        GamepadVectorDataView* output)
    {
        auto pointer = data_->angular_acceleration.Get();
        *output = GamepadVectorDataView(pointer, context_);
    }
    inline void GamepadPoseDataView::GetLinearAccelerationDataView(
        GamepadVectorDataView* output)
    {
        auto pointer = data_->linear_acceleration.Get();
        *output = GamepadVectorDataView(pointer, context_);
    }

    inline void GamepadDataView::GetIdDataView(
        mojo::ArrayDataView<uint16_t>* output)
    {
        auto pointer = data_->id.Get();
        *output = mojo::ArrayDataView<uint16_t>(pointer, context_);
    }
    inline void GamepadDataView::GetAxesDataView(
        mojo::ArrayDataView<double>* output)
    {
        auto pointer = data_->axes.Get();
        *output = mojo::ArrayDataView<double>(pointer, context_);
    }
    inline void GamepadDataView::GetButtonsDataView(
        mojo::ArrayDataView<GamepadButtonDataView>* output)
    {
        auto pointer = data_->buttons.Get();
        *output = mojo::ArrayDataView<GamepadButtonDataView>(pointer, context_);
    }
    inline void GamepadDataView::GetMappingDataView(
        mojo::ArrayDataView<uint16_t>* output)
    {
        auto pointer = data_->mapping.Get();
        *output = mojo::ArrayDataView<uint16_t>(pointer, context_);
    }
    inline void GamepadDataView::GetPoseDataView(
        GamepadPoseDataView* output)
    {
        auto pointer = data_->pose.Get();
        *output = GamepadPoseDataView(pointer, context_);
    }

    inline void GamepadObserver_GamepadConnected_ParamsDataView::GetGamepadDataView(
        GamepadDataView* output)
    {
        auto pointer = data_->gamepad.Get();
        *output = GamepadDataView(pointer, context_);
    }

    inline void GamepadObserver_GamepadDisconnected_ParamsDataView::GetGamepadDataView(
        GamepadDataView* output)
    {
        auto pointer = data_->gamepad.Get();
        *output = GamepadDataView(pointer, context_);
    }

} // namespace mojom
} // namespace device

#endif // DEVICE_GAMEPAD_PUBLIC_INTERFACES_GAMEPAD_MOJOM_SHARED_H_
