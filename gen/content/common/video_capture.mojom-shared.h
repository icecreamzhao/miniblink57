// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_VIDEO_CAPTURE_MOJOM_SHARED_H_
#define CONTENT_COMMON_VIDEO_CAPTURE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/video_capture.mojom-shared-internal.h"
#include "media/capture/mojo/video_capture_types.mojom-shared.h"
#include "media/mojo/interfaces/media_types.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace content {
namespace mojom {

} // namespace mojom
} // namespace content

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace content {
namespace mojom {

    enum class VideoCaptureState : int32_t {
        STARTED,
        PAUSED,
        RESUMED,
        STOPPED,
        FAILED,
        ENDED,
    };

    inline std::ostream& operator<<(std::ostream& os, VideoCaptureState value)
    {
        switch (value) {
        case VideoCaptureState::STARTED:
            return os << "VideoCaptureState::STARTED";
        case VideoCaptureState::PAUSED:
            return os << "VideoCaptureState::PAUSED";
        case VideoCaptureState::RESUMED:
            return os << "VideoCaptureState::RESUMED";
        case VideoCaptureState::STOPPED:
            return os << "VideoCaptureState::STOPPED";
        case VideoCaptureState::FAILED:
            return os << "VideoCaptureState::FAILED";
        case VideoCaptureState::ENDED:
            return os << "VideoCaptureState::ENDED";
        default:
            return os << "Unknown VideoCaptureState value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(VideoCaptureState value)
    {
        return internal::VideoCaptureState_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class VideoCaptureObserverInterfaceBase {
    };

    using VideoCaptureObserverPtrDataView = mojo::InterfacePtrDataView<VideoCaptureObserverInterfaceBase>;
    using VideoCaptureObserverRequestDataView = mojo::InterfaceRequestDataView<VideoCaptureObserverInterfaceBase>;
    using VideoCaptureObserverAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<VideoCaptureObserverInterfaceBase>;
    using VideoCaptureObserverAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<VideoCaptureObserverInterfaceBase>;
    class VideoCaptureHostInterfaceBase {
    };

    using VideoCaptureHostPtrDataView = mojo::InterfacePtrDataView<VideoCaptureHostInterfaceBase>;
    using VideoCaptureHostRequestDataView = mojo::InterfaceRequestDataView<VideoCaptureHostInterfaceBase>;
    using VideoCaptureHostAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<VideoCaptureHostInterfaceBase>;
    using VideoCaptureHostAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<VideoCaptureHostInterfaceBase>;
    class VideoCaptureObserver_OnStateChanged_ParamsDataView {
    public:
        VideoCaptureObserver_OnStateChanged_ParamsDataView() { }

        VideoCaptureObserver_OnStateChanged_ParamsDataView(
            internal::VideoCaptureObserver_OnStateChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadState(UserType* output) const
        {
            auto data_value = data_->state;
            return mojo::internal::Deserialize<::content::mojom::VideoCaptureState>(
                data_value, output);
        }

        VideoCaptureState state() const
        {
            return static_cast<VideoCaptureState>(data_->state);
        }

    private:
        internal::VideoCaptureObserver_OnStateChanged_Params_Data* data_ = nullptr;
    };

    class VideoCaptureObserver_OnBufferCreated_ParamsDataView {
    public:
        VideoCaptureObserver_OnBufferCreated_ParamsDataView() { }

        VideoCaptureObserver_OnBufferCreated_ParamsDataView(
            internal::VideoCaptureObserver_OnBufferCreated_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t buffer_id() const
        {
            return data_->buffer_id;
        }
        mojo::ScopedSharedBufferHandle TakeHandleFd()
        {
            mojo::ScopedSharedBufferHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedSharedBufferHandle>(
                &data_->handle_fd, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::VideoCaptureObserver_OnBufferCreated_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VideoCaptureObserver_OnBufferReady_ParamsDataView {
    public:
        VideoCaptureObserver_OnBufferReady_ParamsDataView() { }

        VideoCaptureObserver_OnBufferReady_ParamsDataView(
            internal::VideoCaptureObserver_OnBufferReady_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t buffer_id() const
        {
            return data_->buffer_id;
        }
        inline void GetInfoDataView(
            ::media::mojom::VideoFrameInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInfo(UserType* output)
        {
            auto* pointer = data_->info.Get();
            return mojo::internal::Deserialize<::media::mojom::VideoFrameInfoDataView>(
                pointer, output, context_);
        }

    private:
        internal::VideoCaptureObserver_OnBufferReady_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VideoCaptureObserver_OnBufferDestroyed_ParamsDataView {
    public:
        VideoCaptureObserver_OnBufferDestroyed_ParamsDataView() { }

        VideoCaptureObserver_OnBufferDestroyed_ParamsDataView(
            internal::VideoCaptureObserver_OnBufferDestroyed_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t buffer_id() const
        {
            return data_->buffer_id;
        }

    private:
        internal::VideoCaptureObserver_OnBufferDestroyed_Params_Data* data_ = nullptr;
    };

    class VideoCaptureHost_Start_ParamsDataView {
    public:
        VideoCaptureHost_Start_ParamsDataView() { }

        VideoCaptureHost_Start_ParamsDataView(
            internal::VideoCaptureHost_Start_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t device_id() const
        {
            return data_->device_id;
        }
        int32_t session_id() const
        {
            return data_->session_id;
        }
        inline void GetParamsDataView(
            ::media::mojom::VideoCaptureParamsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadParams(UserType* output)
        {
            auto* pointer = data_->params.Get();
            return mojo::internal::Deserialize<::media::mojom::VideoCaptureParamsDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeObserver()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::content::mojom::VideoCaptureObserverPtrDataView>(
                &data_->observer, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::VideoCaptureHost_Start_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VideoCaptureHost_Stop_ParamsDataView {
    public:
        VideoCaptureHost_Stop_ParamsDataView() { }

        VideoCaptureHost_Stop_ParamsDataView(
            internal::VideoCaptureHost_Stop_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t device_id() const
        {
            return data_->device_id;
        }

    private:
        internal::VideoCaptureHost_Stop_Params_Data* data_ = nullptr;
    };

    class VideoCaptureHost_Pause_ParamsDataView {
    public:
        VideoCaptureHost_Pause_ParamsDataView() { }

        VideoCaptureHost_Pause_ParamsDataView(
            internal::VideoCaptureHost_Pause_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t device_id() const
        {
            return data_->device_id;
        }

    private:
        internal::VideoCaptureHost_Pause_Params_Data* data_ = nullptr;
    };

    class VideoCaptureHost_Resume_ParamsDataView {
    public:
        VideoCaptureHost_Resume_ParamsDataView() { }

        VideoCaptureHost_Resume_ParamsDataView(
            internal::VideoCaptureHost_Resume_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t device_id() const
        {
            return data_->device_id;
        }
        int32_t session_id() const
        {
            return data_->session_id;
        }
        inline void GetParamsDataView(
            ::media::mojom::VideoCaptureParamsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadParams(UserType* output)
        {
            auto* pointer = data_->params.Get();
            return mojo::internal::Deserialize<::media::mojom::VideoCaptureParamsDataView>(
                pointer, output, context_);
        }

    private:
        internal::VideoCaptureHost_Resume_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VideoCaptureHost_RequestRefreshFrame_ParamsDataView {
    public:
        VideoCaptureHost_RequestRefreshFrame_ParamsDataView() { }

        VideoCaptureHost_RequestRefreshFrame_ParamsDataView(
            internal::VideoCaptureHost_RequestRefreshFrame_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t device_id() const
        {
            return data_->device_id;
        }

    private:
        internal::VideoCaptureHost_RequestRefreshFrame_Params_Data* data_ = nullptr;
    };

    class VideoCaptureHost_ReleaseBuffer_ParamsDataView {
    public:
        VideoCaptureHost_ReleaseBuffer_ParamsDataView() { }

        VideoCaptureHost_ReleaseBuffer_ParamsDataView(
            internal::VideoCaptureHost_ReleaseBuffer_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t device_id() const
        {
            return data_->device_id;
        }
        int32_t buffer_id() const
        {
            return data_->buffer_id;
        }
        double consumer_resource_utilization() const
        {
            return data_->consumer_resource_utilization;
        }

    private:
        internal::VideoCaptureHost_ReleaseBuffer_Params_Data* data_ = nullptr;
    };

    class VideoCaptureHost_GetDeviceSupportedFormats_ParamsDataView {
    public:
        VideoCaptureHost_GetDeviceSupportedFormats_ParamsDataView() { }

        VideoCaptureHost_GetDeviceSupportedFormats_ParamsDataView(
            internal::VideoCaptureHost_GetDeviceSupportedFormats_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t device_id() const
        {
            return data_->device_id;
        }
        int32_t session_id() const
        {
            return data_->session_id;
        }

    private:
        internal::VideoCaptureHost_GetDeviceSupportedFormats_Params_Data* data_ = nullptr;
    };

    class VideoCaptureHost_GetDeviceSupportedFormats_ResponseParamsDataView {
    public:
        VideoCaptureHost_GetDeviceSupportedFormats_ResponseParamsDataView() { }

        VideoCaptureHost_GetDeviceSupportedFormats_ResponseParamsDataView(
            internal::VideoCaptureHost_GetDeviceSupportedFormats_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFormatsSupportedDataView(
            mojo::ArrayDataView<::media::mojom::VideoCaptureFormatDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFormatsSupported(UserType* output)
        {
            auto* pointer = data_->formats_supported.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::media::mojom::VideoCaptureFormatDataView>>(
                pointer, output, context_);
        }

    private:
        internal::VideoCaptureHost_GetDeviceSupportedFormats_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VideoCaptureHost_GetDeviceFormatsInUse_ParamsDataView {
    public:
        VideoCaptureHost_GetDeviceFormatsInUse_ParamsDataView() { }

        VideoCaptureHost_GetDeviceFormatsInUse_ParamsDataView(
            internal::VideoCaptureHost_GetDeviceFormatsInUse_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t device_id() const
        {
            return data_->device_id;
        }
        int32_t session_id() const
        {
            return data_->session_id;
        }

    private:
        internal::VideoCaptureHost_GetDeviceFormatsInUse_Params_Data* data_ = nullptr;
    };

    class VideoCaptureHost_GetDeviceFormatsInUse_ResponseParamsDataView {
    public:
        VideoCaptureHost_GetDeviceFormatsInUse_ResponseParamsDataView() { }

        VideoCaptureHost_GetDeviceFormatsInUse_ResponseParamsDataView(
            internal::VideoCaptureHost_GetDeviceFormatsInUse_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFormatsInUseDataView(
            mojo::ArrayDataView<::media::mojom::VideoCaptureFormatDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFormatsInUse(UserType* output)
        {
            auto* pointer = data_->formats_in_use.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::media::mojom::VideoCaptureFormatDataView>>(
                pointer, output, context_);
        }

    private:
        internal::VideoCaptureHost_GetDeviceFormatsInUse_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace content

namespace std {

template <>
struct hash<::content::mojom::VideoCaptureState>
    : public mojo::internal::EnumHashImpl<::content::mojom::VideoCaptureState> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::content::mojom::VideoCaptureState, ::content::mojom::VideoCaptureState> {
    static ::content::mojom::VideoCaptureState ToMojom(::content::mojom::VideoCaptureState input) { return input; }
    static bool FromMojom(::content::mojom::VideoCaptureState input, ::content::mojom::VideoCaptureState* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::content::mojom::VideoCaptureState, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::content::mojom::VideoCaptureState, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::content::mojom::VideoCaptureState>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace content {
namespace mojom {

    inline void VideoCaptureObserver_OnBufferReady_ParamsDataView::GetInfoDataView(
        ::media::mojom::VideoFrameInfoDataView* output)
    {
        auto pointer = data_->info.Get();
        *output = ::media::mojom::VideoFrameInfoDataView(pointer, context_);
    }

    inline void VideoCaptureHost_Start_ParamsDataView::GetParamsDataView(
        ::media::mojom::VideoCaptureParamsDataView* output)
    {
        auto pointer = data_->params.Get();
        *output = ::media::mojom::VideoCaptureParamsDataView(pointer, context_);
    }

    inline void VideoCaptureHost_Resume_ParamsDataView::GetParamsDataView(
        ::media::mojom::VideoCaptureParamsDataView* output)
    {
        auto pointer = data_->params.Get();
        *output = ::media::mojom::VideoCaptureParamsDataView(pointer, context_);
    }

    inline void VideoCaptureHost_GetDeviceSupportedFormats_ResponseParamsDataView::GetFormatsSupportedDataView(
        mojo::ArrayDataView<::media::mojom::VideoCaptureFormatDataView>* output)
    {
        auto pointer = data_->formats_supported.Get();
        *output = mojo::ArrayDataView<::media::mojom::VideoCaptureFormatDataView>(pointer, context_);
    }

    inline void VideoCaptureHost_GetDeviceFormatsInUse_ResponseParamsDataView::GetFormatsInUseDataView(
        mojo::ArrayDataView<::media::mojom::VideoCaptureFormatDataView>* output)
    {
        auto pointer = data_->formats_in_use.Get();
        *output = mojo::ArrayDataView<::media::mojom::VideoCaptureFormatDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_VIDEO_CAPTURE_MOJOM_SHARED_H_
