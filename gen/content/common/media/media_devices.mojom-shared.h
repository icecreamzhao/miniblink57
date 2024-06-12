// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_MEDIA_MEDIA_DEVICES_MOJOM_SHARED_H_
#define CONTENT_COMMON_MEDIA_MEDIA_DEVICES_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/media/media_devices.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "url/mojo/origin.mojom-shared.h"

namespace mojom {
using MediaDeviceInfoDataView = mojo::NativeStructDataView;

} // namespace mojom

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace mojom {
using MediaDeviceType = mojo::NativeEnum;
// Interface base classes. They are used for type safety check.
class MediaDevicesDispatcherHostInterfaceBase {
};

using MediaDevicesDispatcherHostPtrDataView = mojo::InterfacePtrDataView<MediaDevicesDispatcherHostInterfaceBase>;
using MediaDevicesDispatcherHostRequestDataView = mojo::InterfaceRequestDataView<MediaDevicesDispatcherHostInterfaceBase>;
using MediaDevicesDispatcherHostAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<MediaDevicesDispatcherHostInterfaceBase>;
using MediaDevicesDispatcherHostAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<MediaDevicesDispatcherHostInterfaceBase>;
class MediaDevicesListenerInterfaceBase {
};

using MediaDevicesListenerPtrDataView = mojo::InterfacePtrDataView<MediaDevicesListenerInterfaceBase>;
using MediaDevicesListenerRequestDataView = mojo::InterfaceRequestDataView<MediaDevicesListenerInterfaceBase>;
using MediaDevicesListenerAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<MediaDevicesListenerInterfaceBase>;
using MediaDevicesListenerAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<MediaDevicesListenerInterfaceBase>;
class MediaDevicesDispatcherHost_EnumerateDevices_ParamsDataView {
public:
    MediaDevicesDispatcherHost_EnumerateDevices_ParamsDataView() { }

    MediaDevicesDispatcherHost_EnumerateDevices_ParamsDataView(
        internal::MediaDevicesDispatcherHost_EnumerateDevices_Params_Data* data,
        mojo::internal::SerializationContext* context)
        : data_(data)
        , context_(context)
    {
    }

    bool is_null() const { return !data_; }
    bool request_audio_input() const
    {
        return data_->request_audio_input;
    }
    bool request_video_input() const
    {
        return data_->request_video_input;
    }
    bool request_audio_output() const
    {
        return data_->request_audio_output;
    }
    inline void GetSecurityOriginDataView(
        ::url::mojom::OriginDataView* output);

    template <typename UserType>
    WARN_UNUSED_RESULT bool ReadSecurityOrigin(UserType* output)
    {
        auto* pointer = data_->security_origin.Get();
        return mojo::internal::Deserialize<::url::mojom::OriginDataView>(
            pointer, output, context_);
    }

private:
    internal::MediaDevicesDispatcherHost_EnumerateDevices_Params_Data* data_ = nullptr;
    mojo::internal::SerializationContext* context_ = nullptr;
};

class MediaDevicesDispatcherHost_EnumerateDevices_ResponseParamsDataView {
public:
    MediaDevicesDispatcherHost_EnumerateDevices_ResponseParamsDataView() { }

    MediaDevicesDispatcherHost_EnumerateDevices_ResponseParamsDataView(
        internal::MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data* data,
        mojo::internal::SerializationContext* context)
        : data_(data)
        , context_(context)
    {
    }

    bool is_null() const { return !data_; }
    inline void GetEnumerationDataView(
        mojo::ArrayDataView<mojo::ArrayDataView<MediaDeviceInfoDataView>>* output);

    template <typename UserType>
    WARN_UNUSED_RESULT bool ReadEnumeration(UserType* output)
    {
        auto* pointer = data_->enumeration.Get();
        return mojo::internal::Deserialize<mojo::ArrayDataView<mojo::ArrayDataView<::mojom::MediaDeviceInfoDataView>>>(
            pointer, output, context_);
    }

private:
    internal::MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data* data_ = nullptr;
    mojo::internal::SerializationContext* context_ = nullptr;
};

class MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_ParamsDataView {
public:
    MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_ParamsDataView() { }

    MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_ParamsDataView(
        internal::MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data* data,
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
        return mojo::internal::Deserialize<::mojom::MediaDeviceType>(
            data_value, output);
    }

    MediaDeviceType type() const
    {
        return static_cast<MediaDeviceType>(data_->type);
    }
    uint32_t subscription_id() const
    {
        return data_->subscription_id;
    }
    inline void GetSecurityOriginDataView(
        ::url::mojom::OriginDataView* output);

    template <typename UserType>
    WARN_UNUSED_RESULT bool ReadSecurityOrigin(UserType* output)
    {
        auto* pointer = data_->security_origin.Get();
        return mojo::internal::Deserialize<::url::mojom::OriginDataView>(
            pointer, output, context_);
    }

private:
    internal::MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data* data_ = nullptr;
    mojo::internal::SerializationContext* context_ = nullptr;
};

class MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_ParamsDataView {
public:
    MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_ParamsDataView() { }

    MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_ParamsDataView(
        internal::MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data* data,
        mojo::internal::SerializationContext* context)
        : data_(data)
    {
    }

    bool is_null() const { return !data_; }
    template <typename UserType>
    WARN_UNUSED_RESULT bool ReadType(UserType* output) const
    {
        auto data_value = data_->type;
        return mojo::internal::Deserialize<::mojom::MediaDeviceType>(
            data_value, output);
    }

    MediaDeviceType type() const
    {
        return static_cast<MediaDeviceType>(data_->type);
    }
    uint32_t subscription_id() const
    {
        return data_->subscription_id;
    }

private:
    internal::MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data* data_ = nullptr;
};

class MediaDevicesListener_OnDevicesChanged_ParamsDataView {
public:
    MediaDevicesListener_OnDevicesChanged_ParamsDataView() { }

    MediaDevicesListener_OnDevicesChanged_ParamsDataView(
        internal::MediaDevicesListener_OnDevicesChanged_Params_Data* data,
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
        return mojo::internal::Deserialize<::mojom::MediaDeviceType>(
            data_value, output);
    }

    MediaDeviceType type() const
    {
        return static_cast<MediaDeviceType>(data_->type);
    }
    uint32_t subscription_id() const
    {
        return data_->subscription_id;
    }
    inline void GetDeviceInfosDataView(
        mojo::ArrayDataView<MediaDeviceInfoDataView>* output);

    template <typename UserType>
    WARN_UNUSED_RESULT bool ReadDeviceInfos(UserType* output)
    {
        auto* pointer = data_->device_infos.Get();
        return mojo::internal::Deserialize<mojo::ArrayDataView<::mojom::MediaDeviceInfoDataView>>(
            pointer, output, context_);
    }

private:
    internal::MediaDevicesListener_OnDevicesChanged_Params_Data* data_ = nullptr;
    mojo::internal::SerializationContext* context_ = nullptr;
};

} // namespace mojom

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace mojom {

inline void MediaDevicesDispatcherHost_EnumerateDevices_ParamsDataView::GetSecurityOriginDataView(
    ::url::mojom::OriginDataView* output)
{
    auto pointer = data_->security_origin.Get();
    *output = ::url::mojom::OriginDataView(pointer, context_);
}

inline void MediaDevicesDispatcherHost_EnumerateDevices_ResponseParamsDataView::GetEnumerationDataView(
    mojo::ArrayDataView<mojo::ArrayDataView<MediaDeviceInfoDataView>>* output)
{
    auto pointer = data_->enumeration.Get();
    *output = mojo::ArrayDataView<mojo::ArrayDataView<MediaDeviceInfoDataView>>(pointer, context_);
}

inline void MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_ParamsDataView::GetSecurityOriginDataView(
    ::url::mojom::OriginDataView* output)
{
    auto pointer = data_->security_origin.Get();
    *output = ::url::mojom::OriginDataView(pointer, context_);
}

inline void MediaDevicesListener_OnDevicesChanged_ParamsDataView::GetDeviceInfosDataView(
    mojo::ArrayDataView<MediaDeviceInfoDataView>* output)
{
    auto pointer = data_->device_infos.Get();
    *output = mojo::ArrayDataView<MediaDeviceInfoDataView>(pointer, context_);
}

} // namespace mojom

#endif // CONTENT_COMMON_MEDIA_MEDIA_DEVICES_MOJOM_SHARED_H_
