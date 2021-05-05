// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_INTERFACE_FACTORY_MOJOM_SHARED_H_
#define MEDIA_MOJO_INTERFACES_INTERFACE_FACTORY_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/mojo/interfaces/audio_decoder.mojom-shared.h"
#include "media/mojo/interfaces/content_decryption_module.mojom-shared.h"
#include "media/mojo/interfaces/interface_factory.mojom-shared-internal.h"
#include "media/mojo/interfaces/renderer.mojom-shared.h"
#include "media/mojo/interfaces/video_decoder.mojom-shared.h"
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
    class InterfaceFactoryInterfaceBase {
    };

    using InterfaceFactoryPtrDataView = mojo::InterfacePtrDataView<InterfaceFactoryInterfaceBase>;
    using InterfaceFactoryRequestDataView = mojo::InterfaceRequestDataView<InterfaceFactoryInterfaceBase>;
    using InterfaceFactoryAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<InterfaceFactoryInterfaceBase>;
    using InterfaceFactoryAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<InterfaceFactoryInterfaceBase>;
    class InterfaceFactory_CreateAudioDecoder_ParamsDataView {
    public:
        InterfaceFactory_CreateAudioDecoder_ParamsDataView() { }

        InterfaceFactory_CreateAudioDecoder_ParamsDataView(
            internal::InterfaceFactory_CreateAudioDecoder_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeAudioDecoder()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::media::mojom::AudioDecoderRequestDataView>(
                &data_->audio_decoder, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::InterfaceFactory_CreateAudioDecoder_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class InterfaceFactory_CreateVideoDecoder_ParamsDataView {
    public:
        InterfaceFactory_CreateVideoDecoder_ParamsDataView() { }

        InterfaceFactory_CreateVideoDecoder_ParamsDataView(
            internal::InterfaceFactory_CreateVideoDecoder_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeVideoDecoder()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::media::mojom::VideoDecoderRequestDataView>(
                &data_->video_decoder, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::InterfaceFactory_CreateVideoDecoder_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class InterfaceFactory_CreateRenderer_ParamsDataView {
    public:
        InterfaceFactory_CreateRenderer_ParamsDataView() { }

        InterfaceFactory_CreateRenderer_ParamsDataView(
            internal::InterfaceFactory_CreateRenderer_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetAudioDeviceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAudioDeviceId(UserType* output)
        {
            auto* pointer = data_->audio_device_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeRenderer()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::media::mojom::RendererRequestDataView>(
                &data_->renderer, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::InterfaceFactory_CreateRenderer_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class InterfaceFactory_CreateCdm_ParamsDataView {
    public:
        InterfaceFactory_CreateCdm_ParamsDataView() { }

        InterfaceFactory_CreateCdm_ParamsDataView(
            internal::InterfaceFactory_CreateCdm_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeCdm()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::media::mojom::ContentDecryptionModuleRequestDataView>(
                &data_->cdm, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::InterfaceFactory_CreateCdm_Params_Data* data_ = nullptr;
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

    inline void InterfaceFactory_CreateRenderer_ParamsDataView::GetAudioDeviceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->audio_device_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_INTERFACE_FACTORY_MOJOM_SHARED_H_
