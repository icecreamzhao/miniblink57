// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_AUDIO_OUTPUT_MOJOM_SHARED_H_
#define MEDIA_MOJO_INTERFACES_AUDIO_OUTPUT_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/mojo/interfaces/audio_output.mojom-shared-internal.h"
#include "media/mojo/interfaces/audio_parameters.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace media {
namespace mojom {

} // namespace mojom
} // namespace media

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace media {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class AudioOutputStreamInterfaceBase {
    };

    using AudioOutputStreamPtrDataView = mojo::InterfacePtrDataView<AudioOutputStreamInterfaceBase>;
    using AudioOutputStreamRequestDataView = mojo::InterfaceRequestDataView<AudioOutputStreamInterfaceBase>;
    using AudioOutputStreamAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<AudioOutputStreamInterfaceBase>;
    using AudioOutputStreamAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<AudioOutputStreamInterfaceBase>;
    class AudioOutputInterfaceBase {
    };

    using AudioOutputPtrDataView = mojo::InterfacePtrDataView<AudioOutputInterfaceBase>;
    using AudioOutputRequestDataView = mojo::InterfaceRequestDataView<AudioOutputInterfaceBase>;
    using AudioOutputAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<AudioOutputInterfaceBase>;
    using AudioOutputAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<AudioOutputInterfaceBase>;
    class AudioOutputStream_Close_ParamsDataView {
    public:
        AudioOutputStream_Close_ParamsDataView() { }

        AudioOutputStream_Close_ParamsDataView(
            internal::AudioOutputStream_Close_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::AudioOutputStream_Close_Params_Data* data_ = nullptr;
    };

    class AudioOutput_CreateStream_ParamsDataView {
    public:
        AudioOutput_CreateStream_ParamsDataView() { }

        AudioOutput_CreateStream_ParamsDataView(
            internal::AudioOutput_CreateStream_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t stream_id() const
        {
            return data_->stream_id;
        }
        inline void GetParamsDataView(
            ::media::mojom::AudioParametersDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadParams(UserType* output)
        {
            auto* pointer = data_->params.Get();
            return mojo::internal::Deserialize<::media::mojom::AudioParametersDataView>(
                pointer, output, context_);
        }

    private:
        internal::AudioOutput_CreateStream_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AudioOutput_CreateStream_ResponseParamsDataView {
    public:
        AudioOutput_CreateStream_ResponseParamsDataView() { }

        AudioOutput_CreateStream_ResponseParamsDataView(
            internal::AudioOutput_CreateStream_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t stream_id() const
        {
            return data_->stream_id;
        }
        template <typename UserType>
        UserType TakeStream()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::media::mojom::AudioOutputStreamPtrDataView>(
                &data_->stream, &result, context_);
            DCHECK(ret);
            return result;
        }
        mojo::ScopedSharedBufferHandle TakeSharedBuffer()
        {
            mojo::ScopedSharedBufferHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedSharedBufferHandle>(
                &data_->shared_buffer, &result, context_);
            DCHECK(ret);
            return result;
        }
        mojo::ScopedHandle TakeSocketDescriptor()
        {
            mojo::ScopedHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedHandle>(
                &data_->socket_descriptor, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::AudioOutput_CreateStream_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace media

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace media {
namespace mojom {

    inline void AudioOutput_CreateStream_ParamsDataView::GetParamsDataView(
        ::media::mojom::AudioParametersDataView* output)
    {
        auto pointer = data_->params.Get();
        *output = ::media::mojom::AudioParametersDataView(pointer, context_);
    }

} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_AUDIO_OUTPUT_MOJOM_SHARED_H_
