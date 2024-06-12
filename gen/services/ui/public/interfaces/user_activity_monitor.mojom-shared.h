// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_USER_ACTIVITY_MONITOR_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_USER_ACTIVITY_MONITOR_MOJOM_SHARED_H_

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
#include "services/ui/public/interfaces/user_activity_monitor.mojom-shared-internal.h"

namespace ui {
namespace mojom {

} // namespace mojom
} // namespace ui

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace ui {
namespace mojom {

    enum class UserIdleObserver_IdleState : int32_t {
        ACTIVE,
        IDLE,
    };

    inline std::ostream& operator<<(std::ostream& os, UserIdleObserver_IdleState value)
    {
        switch (value) {
        case UserIdleObserver_IdleState::ACTIVE:
            return os << "UserIdleObserver_IdleState::ACTIVE";
        case UserIdleObserver_IdleState::IDLE:
            return os << "UserIdleObserver_IdleState::IDLE";
        default:
            return os << "Unknown UserIdleObserver_IdleState value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(UserIdleObserver_IdleState value)
    {
        return internal::UserIdleObserver_IdleState_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class UserActivityObserverInterfaceBase {
    };

    using UserActivityObserverPtrDataView = mojo::InterfacePtrDataView<UserActivityObserverInterfaceBase>;
    using UserActivityObserverRequestDataView = mojo::InterfaceRequestDataView<UserActivityObserverInterfaceBase>;
    using UserActivityObserverAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<UserActivityObserverInterfaceBase>;
    using UserActivityObserverAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<UserActivityObserverInterfaceBase>;
    class UserIdleObserverInterfaceBase {
    };

    using UserIdleObserverPtrDataView = mojo::InterfacePtrDataView<UserIdleObserverInterfaceBase>;
    using UserIdleObserverRequestDataView = mojo::InterfaceRequestDataView<UserIdleObserverInterfaceBase>;
    using UserIdleObserverAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<UserIdleObserverInterfaceBase>;
    using UserIdleObserverAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<UserIdleObserverInterfaceBase>;
    class UserActivityMonitorInterfaceBase {
    };

    using UserActivityMonitorPtrDataView = mojo::InterfacePtrDataView<UserActivityMonitorInterfaceBase>;
    using UserActivityMonitorRequestDataView = mojo::InterfaceRequestDataView<UserActivityMonitorInterfaceBase>;
    using UserActivityMonitorAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<UserActivityMonitorInterfaceBase>;
    using UserActivityMonitorAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<UserActivityMonitorInterfaceBase>;
    class UserActivityObserver_OnUserActivity_ParamsDataView {
    public:
        UserActivityObserver_OnUserActivity_ParamsDataView() { }

        UserActivityObserver_OnUserActivity_ParamsDataView(
            internal::UserActivityObserver_OnUserActivity_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::UserActivityObserver_OnUserActivity_Params_Data* data_ = nullptr;
    };

    class UserIdleObserver_OnUserIdleStateChanged_ParamsDataView {
    public:
        UserIdleObserver_OnUserIdleStateChanged_ParamsDataView() { }

        UserIdleObserver_OnUserIdleStateChanged_ParamsDataView(
            internal::UserIdleObserver_OnUserIdleStateChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNewState(UserType* output) const
        {
            auto data_value = data_->new_state;
            return mojo::internal::Deserialize<::ui::mojom::UserIdleObserver_IdleState>(
                data_value, output);
        }

        UserIdleObserver_IdleState new_state() const
        {
            return static_cast<UserIdleObserver_IdleState>(data_->new_state);
        }

    private:
        internal::UserIdleObserver_OnUserIdleStateChanged_Params_Data* data_ = nullptr;
    };

    class UserActivityMonitor_AddUserActivityObserver_ParamsDataView {
    public:
        UserActivityMonitor_AddUserActivityObserver_ParamsDataView() { }

        UserActivityMonitor_AddUserActivityObserver_ParamsDataView(
            internal::UserActivityMonitor_AddUserActivityObserver_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t delay_between_notify_secs() const
        {
            return data_->delay_between_notify_secs;
        }
        template <typename UserType>
        UserType TakeObserver()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::UserActivityObserverPtrDataView>(
                &data_->observer, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::UserActivityMonitor_AddUserActivityObserver_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class UserActivityMonitor_AddUserIdleObserver_ParamsDataView {
    public:
        UserActivityMonitor_AddUserIdleObserver_ParamsDataView() { }

        UserActivityMonitor_AddUserIdleObserver_ParamsDataView(
            internal::UserActivityMonitor_AddUserIdleObserver_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t idle_time_in_minutes() const
        {
            return data_->idle_time_in_minutes;
        }
        template <typename UserType>
        UserType TakeObserver()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::UserIdleObserverPtrDataView>(
                &data_->observer, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::UserActivityMonitor_AddUserIdleObserver_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace ui

namespace std {

template <>
struct hash<::ui::mojom::UserIdleObserver_IdleState>
    : public mojo::internal::EnumHashImpl<::ui::mojom::UserIdleObserver_IdleState> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::ui::mojom::UserIdleObserver_IdleState, ::ui::mojom::UserIdleObserver_IdleState> {
    static ::ui::mojom::UserIdleObserver_IdleState ToMojom(::ui::mojom::UserIdleObserver_IdleState input) { return input; }
    static bool FromMojom(::ui::mojom::UserIdleObserver_IdleState input, ::ui::mojom::UserIdleObserver_IdleState* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::UserIdleObserver_IdleState, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::ui::mojom::UserIdleObserver_IdleState, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::ui::mojom::UserIdleObserver_IdleState>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace ui {
namespace mojom {

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_USER_ACTIVITY_MONITOR_MOJOM_SHARED_H_
