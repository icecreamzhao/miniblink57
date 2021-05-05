// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_GAMEPAD_PUBLIC_INTERFACES_GAMEPAD_MOJOM_H_
#define DEVICE_GAMEPAD_PUBLIC_INTERFACES_GAMEPAD_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/gamepad/public/interfaces/gamepad.mojom-shared.h"
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
#include "third_party/WebKit/public/platform/WebGamepad.h"
#include <string>
#include <vector>

namespace device {
namespace mojom {
    class GamepadObserver;
    using GamepadObserverPtr = mojo::InterfacePtr<GamepadObserver>;
    using GamepadObserverPtrInfo = mojo::InterfacePtrInfo<GamepadObserver>;
    using ThreadSafeGamepadObserverPtr = mojo::ThreadSafeInterfacePtr<GamepadObserver>;
    using GamepadObserverRequest = mojo::InterfaceRequest<GamepadObserver>;
    using GamepadObserverAssociatedPtr = mojo::AssociatedInterfacePtr<GamepadObserver>;
    using ThreadSafeGamepadObserverAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<GamepadObserver>;
    using GamepadObserverAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<GamepadObserver>;
    using GamepadObserverAssociatedRequest = mojo::AssociatedInterfaceRequest<GamepadObserver>;

    class GamepadMonitor;
    using GamepadMonitorPtr = mojo::InterfacePtr<GamepadMonitor>;
    using GamepadMonitorPtrInfo = mojo::InterfacePtrInfo<GamepadMonitor>;
    using ThreadSafeGamepadMonitorPtr = mojo::ThreadSafeInterfacePtr<GamepadMonitor>;
    using GamepadMonitorRequest = mojo::InterfaceRequest<GamepadMonitor>;
    using GamepadMonitorAssociatedPtr = mojo::AssociatedInterfacePtr<GamepadMonitor>;
    using ThreadSafeGamepadMonitorAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<GamepadMonitor>;
    using GamepadMonitorAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<GamepadMonitor>;
    using GamepadMonitorAssociatedRequest = mojo::AssociatedInterfaceRequest<GamepadMonitor>;

    class GamepadQuaternion;
    using GamepadQuaternionPtr = mojo::InlinedStructPtr<GamepadQuaternion>;

    class GamepadVector;
    using GamepadVectorPtr = mojo::InlinedStructPtr<GamepadVector>;

    class GamepadButton;
    using GamepadButtonPtr = mojo::InlinedStructPtr<GamepadButton>;

    class GamepadPose;
    using GamepadPosePtr = mojo::StructPtr<GamepadPose>;

    class Gamepad;
    using GamepadPtr = mojo::StructPtr<Gamepad>;

    class GamepadObserverProxy;

    template <typename ImplRefTraits>
    class GamepadObserverStub;

    class GamepadObserverRequestValidator;

    class GamepadObserver
        : public GamepadObserverInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = GamepadObserverProxy;

        template <typename ImplRefTraits>
        using Stub_ = GamepadObserverStub<ImplRefTraits>;

        using RequestValidator_ = GamepadObserverRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kGamepadConnectedMinVersion = 0,
            kGamepadDisconnectedMinVersion = 0,
        };
        virtual ~GamepadObserver() { }

        virtual void GamepadConnected(int32_t index, const blink::WebGamepad& gamepad) = 0;

        virtual void GamepadDisconnected(int32_t index, const blink::WebGamepad& gamepad) = 0;
    };

    class GamepadMonitorProxy;

    template <typename ImplRefTraits>
    class GamepadMonitorStub;

    class GamepadMonitorRequestValidator;
    class GamepadMonitorResponseValidator;

    class GamepadMonitor
        : public GamepadMonitorInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = true;

        using Proxy_ = GamepadMonitorProxy;

        template <typename ImplRefTraits>
        using Stub_ = GamepadMonitorStub<ImplRefTraits>;

        using RequestValidator_ = GamepadMonitorRequestValidator;
        using ResponseValidator_ = GamepadMonitorResponseValidator;
        enum MethodMinVersions : uint32_t {
            kGamepadStartPollingMinVersion = 0,
            kGamepadStopPollingMinVersion = 0,
            kSetObserverMinVersion = 0,
        };
        virtual ~GamepadMonitor() { }

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool GamepadStartPolling(mojo::ScopedSharedBufferHandle* memory_handle);

        using GamepadStartPollingCallback = base::Callback<void(mojo::ScopedSharedBufferHandle)>;
        virtual void GamepadStartPolling(const GamepadStartPollingCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool GamepadStopPolling();

        using GamepadStopPollingCallback = base::Callback<void()>;
        virtual void GamepadStopPolling(const GamepadStopPollingCallback& callback) = 0;

        virtual void SetObserver(GamepadObserverPtr gamepad_observer) = 0;
    };

    class GamepadObserverProxy
        : public GamepadObserver {
    public:
        explicit GamepadObserverProxy(mojo::MessageReceiverWithResponder* receiver);
        void GamepadConnected(int32_t index, const blink::WebGamepad& gamepad) override;
        void GamepadDisconnected(int32_t index, const blink::WebGamepad& gamepad) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class GamepadMonitorProxy
        : public GamepadMonitor {
    public:
        explicit GamepadMonitorProxy(mojo::MessageReceiverWithResponder* receiver);
        bool GamepadStartPolling(mojo::ScopedSharedBufferHandle* memory_handle) override;
        void GamepadStartPolling(const GamepadStartPollingCallback& callback) override;
        bool GamepadStopPolling() override;
        void GamepadStopPolling(const GamepadStopPollingCallback& callback) override;
        void SetObserver(GamepadObserverPtr gamepad_observer) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class GamepadObserverStubDispatch {
    public:
        static bool Accept(GamepadObserver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(GamepadObserver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<GamepadObserver>>
    class GamepadObserverStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        GamepadObserverStub() { }
        ~GamepadObserverStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return GamepadObserverStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return GamepadObserverStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class GamepadMonitorStubDispatch {
    public:
        static bool Accept(GamepadMonitor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(GamepadMonitor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<GamepadMonitor>>
    class GamepadMonitorStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        GamepadMonitorStub() { }
        ~GamepadMonitorStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return GamepadMonitorStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return GamepadMonitorStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class GamepadObserverRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class GamepadMonitorRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class GamepadMonitorResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class GamepadQuaternion {
    public:
        using DataView = GamepadQuaternionDataView;
        using Data_ = internal::GamepadQuaternion_Data;

        static GamepadQuaternionPtr New();

        template <typename U>
        static GamepadQuaternionPtr From(const U& u)
        {
            return mojo::TypeConverter<GamepadQuaternionPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, GamepadQuaternion>::Convert(*this);
        }

        GamepadQuaternion();
        ~GamepadQuaternion();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = GamepadQuaternionPtr>
        GamepadQuaternionPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, GamepadQuaternion>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                GamepadQuaternion::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                GamepadQuaternion::DataView, std::vector<uint8_t>>(
                input, output);
        }

        float x;
        float y;
        float z;
        float w;
    };

    class GamepadVector {
    public:
        using DataView = GamepadVectorDataView;
        using Data_ = internal::GamepadVector_Data;

        static GamepadVectorPtr New();

        template <typename U>
        static GamepadVectorPtr From(const U& u)
        {
            return mojo::TypeConverter<GamepadVectorPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, GamepadVector>::Convert(*this);
        }

        GamepadVector();
        ~GamepadVector();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = GamepadVectorPtr>
        GamepadVectorPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, GamepadVector>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                GamepadVector::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                GamepadVector::DataView, std::vector<uint8_t>>(
                input, output);
        }

        float x;
        float y;
        float z;
    };

    class GamepadButton {
    public:
        using DataView = GamepadButtonDataView;
        using Data_ = internal::GamepadButton_Data;

        static GamepadButtonPtr New();

        template <typename U>
        static GamepadButtonPtr From(const U& u)
        {
            return mojo::TypeConverter<GamepadButtonPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, GamepadButton>::Convert(*this);
        }

        GamepadButton();
        ~GamepadButton();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = GamepadButtonPtr>
        GamepadButtonPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, GamepadButton>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                GamepadButton::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                GamepadButton::DataView, std::vector<uint8_t>>(
                input, output);
        }

        bool pressed;
        bool touched;
        double value;
    };

    class GamepadPose {
    public:
        using DataView = GamepadPoseDataView;
        using Data_ = internal::GamepadPose_Data;

        static GamepadPosePtr New();

        template <typename U>
        static GamepadPosePtr From(const U& u)
        {
            return mojo::TypeConverter<GamepadPosePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, GamepadPose>::Convert(*this);
        }

        GamepadPose();
        ~GamepadPose();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = GamepadPosePtr>
        GamepadPosePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, GamepadPose>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                GamepadPose::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                GamepadPose::DataView, std::vector<uint8_t>>(
                input, output);
        }

        blink::WebGamepadQuaternion orientation;
        blink::WebGamepadVector position;
        blink::WebGamepadVector angular_velocity;
        blink::WebGamepadVector linear_velocity;
        blink::WebGamepadVector angular_acceleration;
        blink::WebGamepadVector linear_acceleration;
    };

    class Gamepad {
    public:
        using DataView = GamepadDataView;
        using Data_ = internal::Gamepad_Data;

        static GamepadPtr New();

        template <typename U>
        static GamepadPtr From(const U& u)
        {
            return mojo::TypeConverter<GamepadPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Gamepad>::Convert(*this);
        }

        Gamepad();
        ~Gamepad();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = GamepadPtr>
        GamepadPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Gamepad>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Gamepad::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Gamepad::DataView, std::vector<uint8_t>>(
                input, output);
        }

        bool connected;
        std::vector<uint16_t> id;
        uint64_t timestamp;
        std::vector<double> axes;
        std::vector<blink::WebGamepadButton> buttons;
        std::vector<uint16_t> mapping;
        blink::WebGamepadPose pose;
        blink::WebGamepadHand hand;
        uint32_t display_id;
    };

    template <typename StructPtrType>
    GamepadQuaternionPtr GamepadQuaternion::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->x = mojo::internal::Clone(x);
        rv->y = mojo::internal::Clone(y);
        rv->z = mojo::internal::Clone(z);
        rv->w = mojo::internal::Clone(w);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, GamepadQuaternion>::value>::type*>
    bool GamepadQuaternion::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->x, other.x))
            return false;
        if (!mojo::internal::Equals(this->y, other.y))
            return false;
        if (!mojo::internal::Equals(this->z, other.z))
            return false;
        if (!mojo::internal::Equals(this->w, other.w))
            return false;
        return true;
    }
    template <typename StructPtrType>
    GamepadVectorPtr GamepadVector::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->x = mojo::internal::Clone(x);
        rv->y = mojo::internal::Clone(y);
        rv->z = mojo::internal::Clone(z);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, GamepadVector>::value>::type*>
    bool GamepadVector::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->x, other.x))
            return false;
        if (!mojo::internal::Equals(this->y, other.y))
            return false;
        if (!mojo::internal::Equals(this->z, other.z))
            return false;
        return true;
    }
    template <typename StructPtrType>
    GamepadButtonPtr GamepadButton::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->pressed = mojo::internal::Clone(pressed);
        rv->touched = mojo::internal::Clone(touched);
        rv->value = mojo::internal::Clone(value);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, GamepadButton>::value>::type*>
    bool GamepadButton::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->pressed, other.pressed))
            return false;
        if (!mojo::internal::Equals(this->touched, other.touched))
            return false;
        if (!mojo::internal::Equals(this->value, other.value))
            return false;
        return true;
    }
    template <typename StructPtrType>
    GamepadPosePtr GamepadPose::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->orientation = mojo::internal::Clone(orientation);
        rv->position = mojo::internal::Clone(position);
        rv->angular_velocity = mojo::internal::Clone(angular_velocity);
        rv->linear_velocity = mojo::internal::Clone(linear_velocity);
        rv->angular_acceleration = mojo::internal::Clone(angular_acceleration);
        rv->linear_acceleration = mojo::internal::Clone(linear_acceleration);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, GamepadPose>::value>::type*>
    bool GamepadPose::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->orientation, other.orientation))
            return false;
        if (!mojo::internal::Equals(this->position, other.position))
            return false;
        if (!mojo::internal::Equals(this->angular_velocity, other.angular_velocity))
            return false;
        if (!mojo::internal::Equals(this->linear_velocity, other.linear_velocity))
            return false;
        if (!mojo::internal::Equals(this->angular_acceleration, other.angular_acceleration))
            return false;
        if (!mojo::internal::Equals(this->linear_acceleration, other.linear_acceleration))
            return false;
        return true;
    }
    template <typename StructPtrType>
    GamepadPtr Gamepad::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->connected = mojo::internal::Clone(connected);
        rv->id = mojo::internal::Clone(id);
        rv->timestamp = mojo::internal::Clone(timestamp);
        rv->axes = mojo::internal::Clone(axes);
        rv->buttons = mojo::internal::Clone(buttons);
        rv->mapping = mojo::internal::Clone(mapping);
        rv->pose = mojo::internal::Clone(pose);
        rv->hand = mojo::internal::Clone(hand);
        rv->display_id = mojo::internal::Clone(display_id);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Gamepad>::value>::type*>
    bool Gamepad::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->connected, other.connected))
            return false;
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        if (!mojo::internal::Equals(this->timestamp, other.timestamp))
            return false;
        if (!mojo::internal::Equals(this->axes, other.axes))
            return false;
        if (!mojo::internal::Equals(this->buttons, other.buttons))
            return false;
        if (!mojo::internal::Equals(this->mapping, other.mapping))
            return false;
        if (!mojo::internal::Equals(this->pose, other.pose))
            return false;
        if (!mojo::internal::Equals(this->hand, other.hand))
            return false;
        if (!mojo::internal::Equals(this->display_id, other.display_id))
            return false;
        return true;
    }

} // namespace mojom
} // namespace device

namespace mojo {

template <>
struct StructTraits<::device::mojom::GamepadQuaternion::DataView,
    ::device::mojom::GamepadQuaternionPtr> {
    static bool IsNull(const ::device::mojom::GamepadQuaternionPtr& input) { return !input; }
    static void SetToNull(::device::mojom::GamepadQuaternionPtr* output) { output->reset(); }

    static decltype(::device::mojom::GamepadQuaternion::x) x(
        const ::device::mojom::GamepadQuaternionPtr& input)
    {
        return input->x;
    }

    static decltype(::device::mojom::GamepadQuaternion::y) y(
        const ::device::mojom::GamepadQuaternionPtr& input)
    {
        return input->y;
    }

    static decltype(::device::mojom::GamepadQuaternion::z) z(
        const ::device::mojom::GamepadQuaternionPtr& input)
    {
        return input->z;
    }

    static decltype(::device::mojom::GamepadQuaternion::w) w(
        const ::device::mojom::GamepadQuaternionPtr& input)
    {
        return input->w;
    }

    static bool Read(::device::mojom::GamepadQuaternion::DataView input, ::device::mojom::GamepadQuaternionPtr* output);
};

template <>
struct StructTraits<::device::mojom::GamepadVector::DataView,
    ::device::mojom::GamepadVectorPtr> {
    static bool IsNull(const ::device::mojom::GamepadVectorPtr& input) { return !input; }
    static void SetToNull(::device::mojom::GamepadVectorPtr* output) { output->reset(); }

    static decltype(::device::mojom::GamepadVector::x) x(
        const ::device::mojom::GamepadVectorPtr& input)
    {
        return input->x;
    }

    static decltype(::device::mojom::GamepadVector::y) y(
        const ::device::mojom::GamepadVectorPtr& input)
    {
        return input->y;
    }

    static decltype(::device::mojom::GamepadVector::z) z(
        const ::device::mojom::GamepadVectorPtr& input)
    {
        return input->z;
    }

    static bool Read(::device::mojom::GamepadVector::DataView input, ::device::mojom::GamepadVectorPtr* output);
};

template <>
struct StructTraits<::device::mojom::GamepadButton::DataView,
    ::device::mojom::GamepadButtonPtr> {
    static bool IsNull(const ::device::mojom::GamepadButtonPtr& input) { return !input; }
    static void SetToNull(::device::mojom::GamepadButtonPtr* output) { output->reset(); }

    static decltype(::device::mojom::GamepadButton::pressed) pressed(
        const ::device::mojom::GamepadButtonPtr& input)
    {
        return input->pressed;
    }

    static decltype(::device::mojom::GamepadButton::touched) touched(
        const ::device::mojom::GamepadButtonPtr& input)
    {
        return input->touched;
    }

    static decltype(::device::mojom::GamepadButton::value) value(
        const ::device::mojom::GamepadButtonPtr& input)
    {
        return input->value;
    }

    static bool Read(::device::mojom::GamepadButton::DataView input, ::device::mojom::GamepadButtonPtr* output);
};

template <>
struct StructTraits<::device::mojom::GamepadPose::DataView,
    ::device::mojom::GamepadPosePtr> {
    static bool IsNull(const ::device::mojom::GamepadPosePtr& input) { return !input; }
    static void SetToNull(::device::mojom::GamepadPosePtr* output) { output->reset(); }

    static const decltype(::device::mojom::GamepadPose::orientation)& orientation(
        const ::device::mojom::GamepadPosePtr& input)
    {
        return input->orientation;
    }

    static const decltype(::device::mojom::GamepadPose::position)& position(
        const ::device::mojom::GamepadPosePtr& input)
    {
        return input->position;
    }

    static const decltype(::device::mojom::GamepadPose::angular_velocity)& angular_velocity(
        const ::device::mojom::GamepadPosePtr& input)
    {
        return input->angular_velocity;
    }

    static const decltype(::device::mojom::GamepadPose::linear_velocity)& linear_velocity(
        const ::device::mojom::GamepadPosePtr& input)
    {
        return input->linear_velocity;
    }

    static const decltype(::device::mojom::GamepadPose::angular_acceleration)& angular_acceleration(
        const ::device::mojom::GamepadPosePtr& input)
    {
        return input->angular_acceleration;
    }

    static const decltype(::device::mojom::GamepadPose::linear_acceleration)& linear_acceleration(
        const ::device::mojom::GamepadPosePtr& input)
    {
        return input->linear_acceleration;
    }

    static bool Read(::device::mojom::GamepadPose::DataView input, ::device::mojom::GamepadPosePtr* output);
};

template <>
struct StructTraits<::device::mojom::Gamepad::DataView,
    ::device::mojom::GamepadPtr> {
    static bool IsNull(const ::device::mojom::GamepadPtr& input) { return !input; }
    static void SetToNull(::device::mojom::GamepadPtr* output) { output->reset(); }

    static decltype(::device::mojom::Gamepad::connected) connected(
        const ::device::mojom::GamepadPtr& input)
    {
        return input->connected;
    }

    static const decltype(::device::mojom::Gamepad::id)& id(
        const ::device::mojom::GamepadPtr& input)
    {
        return input->id;
    }

    static decltype(::device::mojom::Gamepad::timestamp) timestamp(
        const ::device::mojom::GamepadPtr& input)
    {
        return input->timestamp;
    }

    static const decltype(::device::mojom::Gamepad::axes)& axes(
        const ::device::mojom::GamepadPtr& input)
    {
        return input->axes;
    }

    static const decltype(::device::mojom::Gamepad::buttons)& buttons(
        const ::device::mojom::GamepadPtr& input)
    {
        return input->buttons;
    }

    static const decltype(::device::mojom::Gamepad::mapping)& mapping(
        const ::device::mojom::GamepadPtr& input)
    {
        return input->mapping;
    }

    static const decltype(::device::mojom::Gamepad::pose)& pose(
        const ::device::mojom::GamepadPtr& input)
    {
        return input->pose;
    }

    static decltype(::device::mojom::Gamepad::hand) hand(
        const ::device::mojom::GamepadPtr& input)
    {
        return input->hand;
    }

    static decltype(::device::mojom::Gamepad::display_id) display_id(
        const ::device::mojom::GamepadPtr& input)
    {
        return input->display_id;
    }

    static bool Read(::device::mojom::Gamepad::DataView input, ::device::mojom::GamepadPtr* output);
};

} // namespace mojo

#endif // DEVICE_GAMEPAD_PUBLIC_INTERFACES_GAMEPAD_MOJOM_H_