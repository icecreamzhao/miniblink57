// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_MEDIASESSION_MEDIA_SESSION_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_MEDIASESSION_MEDIA_SESSION_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/common/string16.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "third_party/WebKit/public/platform/modules/mediasession/media_session.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"
#include "url/mojo/url.mojom-shared.h"

namespace blink {
namespace mojom {
    class MediaImageDataView;

    class MediaMetadataDataView;

} // namespace mojom
} // namespace blink

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::blink::mojom::MediaImageDataView> {
        using Data = ::blink::mojom::internal::MediaImage_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::blink::mojom::MediaMetadataDataView> {
        using Data = ::blink::mojom::internal::MediaMetadata_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace blink {
namespace mojom {

    enum class MediaSessionAction : int32_t {
        PLAY,
        PAUSE,
        PREVIOUS_TRACK,
        NEXT_TRACK,
        SEEK_BACKWARD,
        SEEK_FORWARD,
        LAST = MediaSessionAction::SEEK_FORWARD,
    };

    inline std::ostream& operator<<(std::ostream& os, MediaSessionAction value)
    {
        switch (value) {
        case MediaSessionAction::PLAY:
            return os << "MediaSessionAction::PLAY";
        case MediaSessionAction::PAUSE:
            return os << "MediaSessionAction::PAUSE";
        case MediaSessionAction::PREVIOUS_TRACK:
            return os << "MediaSessionAction::PREVIOUS_TRACK";
        case MediaSessionAction::NEXT_TRACK:
            return os << "MediaSessionAction::NEXT_TRACK";
        case MediaSessionAction::SEEK_BACKWARD:
            return os << "MediaSessionAction::SEEK_BACKWARD";
        case MediaSessionAction::SEEK_FORWARD:
            return os << "MediaSessionAction::{SEEK_FORWARD, LAST}";
        default:
            return os << "Unknown MediaSessionAction value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(MediaSessionAction value)
    {
        return internal::MediaSessionAction_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class MediaSessionPlaybackState : int32_t {
        NONE,
        PAUSED,
        PLAYING,
    };

    inline std::ostream& operator<<(std::ostream& os, MediaSessionPlaybackState value)
    {
        switch (value) {
        case MediaSessionPlaybackState::NONE:
            return os << "MediaSessionPlaybackState::NONE";
        case MediaSessionPlaybackState::PAUSED:
            return os << "MediaSessionPlaybackState::PAUSED";
        case MediaSessionPlaybackState::PLAYING:
            return os << "MediaSessionPlaybackState::PLAYING";
        default:
            return os << "Unknown MediaSessionPlaybackState value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(MediaSessionPlaybackState value)
    {
        return internal::MediaSessionPlaybackState_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class MediaSessionClientInterfaceBase {
    };

    using MediaSessionClientPtrDataView = mojo::InterfacePtrDataView<MediaSessionClientInterfaceBase>;
    using MediaSessionClientRequestDataView = mojo::InterfaceRequestDataView<MediaSessionClientInterfaceBase>;
    using MediaSessionClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<MediaSessionClientInterfaceBase>;
    using MediaSessionClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<MediaSessionClientInterfaceBase>;
    class MediaSessionServiceInterfaceBase {
    };

    using MediaSessionServicePtrDataView = mojo::InterfacePtrDataView<MediaSessionServiceInterfaceBase>;
    using MediaSessionServiceRequestDataView = mojo::InterfaceRequestDataView<MediaSessionServiceInterfaceBase>;
    using MediaSessionServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<MediaSessionServiceInterfaceBase>;
    using MediaSessionServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<MediaSessionServiceInterfaceBase>;
    class MediaImageDataView {
    public:
        MediaImageDataView() { }

        MediaImageDataView(
            internal::MediaImage_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSrcDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSrc(UserType* output)
        {
            auto* pointer = data_->src.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetTypeDataView(
            ::mojo::common::mojom::String16DataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output)
        {
            auto* pointer = data_->type.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::String16DataView>(
                pointer, output, context_);
        }
        inline void GetSizesDataView(
            mojo::ArrayDataView<::gfx::mojom::SizeDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSizes(UserType* output)
        {
            auto* pointer = data_->sizes.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::gfx::mojom::SizeDataView>>(
                pointer, output, context_);
        }

    private:
        internal::MediaImage_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class MediaMetadataDataView {
    public:
        MediaMetadataDataView() { }

        MediaMetadataDataView(
            internal::MediaMetadata_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTitleDataView(
            ::mojo::common::mojom::String16DataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTitle(UserType* output)
        {
            auto* pointer = data_->title.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::String16DataView>(
                pointer, output, context_);
        }
        inline void GetArtistDataView(
            ::mojo::common::mojom::String16DataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadArtist(UserType* output)
        {
            auto* pointer = data_->artist.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::String16DataView>(
                pointer, output, context_);
        }
        inline void GetAlbumDataView(
            ::mojo::common::mojom::String16DataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAlbum(UserType* output)
        {
            auto* pointer = data_->album.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::String16DataView>(
                pointer, output, context_);
        }
        inline void GetArtworkDataView(
            mojo::ArrayDataView<MediaImageDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadArtwork(UserType* output)
        {
            auto* pointer = data_->artwork.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::blink::mojom::MediaImageDataView>>(
                pointer, output, context_);
        }

    private:
        internal::MediaMetadata_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class MediaSessionClient_DidReceiveAction_ParamsDataView {
    public:
        MediaSessionClient_DidReceiveAction_ParamsDataView() { }

        MediaSessionClient_DidReceiveAction_ParamsDataView(
            internal::MediaSessionClient_DidReceiveAction_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAction(UserType* output) const
        {
            auto data_value = data_->action;
            return mojo::internal::Deserialize<::blink::mojom::MediaSessionAction>(
                data_value, output);
        }

        MediaSessionAction action() const
        {
            return static_cast<MediaSessionAction>(data_->action);
        }

    private:
        internal::MediaSessionClient_DidReceiveAction_Params_Data* data_ = nullptr;
    };

    class MediaSessionService_SetClient_ParamsDataView {
    public:
        MediaSessionService_SetClient_ParamsDataView() { }

        MediaSessionService_SetClient_ParamsDataView(
            internal::MediaSessionService_SetClient_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::blink::mojom::MediaSessionClientPtrDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::MediaSessionService_SetClient_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class MediaSessionService_SetPlaybackState_ParamsDataView {
    public:
        MediaSessionService_SetPlaybackState_ParamsDataView() { }

        MediaSessionService_SetPlaybackState_ParamsDataView(
            internal::MediaSessionService_SetPlaybackState_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadState(UserType* output) const
        {
            auto data_value = data_->state;
            return mojo::internal::Deserialize<::blink::mojom::MediaSessionPlaybackState>(
                data_value, output);
        }

        MediaSessionPlaybackState state() const
        {
            return static_cast<MediaSessionPlaybackState>(data_->state);
        }

    private:
        internal::MediaSessionService_SetPlaybackState_Params_Data* data_ = nullptr;
    };

    class MediaSessionService_SetMetadata_ParamsDataView {
    public:
        MediaSessionService_SetMetadata_ParamsDataView() { }

        MediaSessionService_SetMetadata_ParamsDataView(
            internal::MediaSessionService_SetMetadata_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetMetadataDataView(
            MediaMetadataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMetadata(UserType* output)
        {
            auto* pointer = data_->metadata.Get();
            return mojo::internal::Deserialize<::blink::mojom::MediaMetadataDataView>(
                pointer, output, context_);
        }

    private:
        internal::MediaSessionService_SetMetadata_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class MediaSessionService_EnableAction_ParamsDataView {
    public:
        MediaSessionService_EnableAction_ParamsDataView() { }

        MediaSessionService_EnableAction_ParamsDataView(
            internal::MediaSessionService_EnableAction_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAction(UserType* output) const
        {
            auto data_value = data_->action;
            return mojo::internal::Deserialize<::blink::mojom::MediaSessionAction>(
                data_value, output);
        }

        MediaSessionAction action() const
        {
            return static_cast<MediaSessionAction>(data_->action);
        }

    private:
        internal::MediaSessionService_EnableAction_Params_Data* data_ = nullptr;
    };

    class MediaSessionService_DisableAction_ParamsDataView {
    public:
        MediaSessionService_DisableAction_ParamsDataView() { }

        MediaSessionService_DisableAction_ParamsDataView(
            internal::MediaSessionService_DisableAction_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAction(UserType* output) const
        {
            auto data_value = data_->action;
            return mojo::internal::Deserialize<::blink::mojom::MediaSessionAction>(
                data_value, output);
        }

        MediaSessionAction action() const
        {
            return static_cast<MediaSessionAction>(data_->action);
        }

    private:
        internal::MediaSessionService_DisableAction_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

template <>
struct hash<::blink::mojom::MediaSessionAction>
    : public mojo::internal::EnumHashImpl<::blink::mojom::MediaSessionAction> {
};

template <>
struct hash<::blink::mojom::MediaSessionPlaybackState>
    : public mojo::internal::EnumHashImpl<::blink::mojom::MediaSessionPlaybackState> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::blink::mojom::MediaSessionAction, ::blink::mojom::MediaSessionAction> {
    static ::blink::mojom::MediaSessionAction ToMojom(::blink::mojom::MediaSessionAction input) { return input; }
    static bool FromMojom(::blink::mojom::MediaSessionAction input, ::blink::mojom::MediaSessionAction* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::MediaSessionAction, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::MediaSessionAction, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::MediaSessionAction>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::blink::mojom::MediaSessionPlaybackState, ::blink::mojom::MediaSessionPlaybackState> {
    static ::blink::mojom::MediaSessionPlaybackState ToMojom(::blink::mojom::MediaSessionPlaybackState input) { return input; }
    static bool FromMojom(::blink::mojom::MediaSessionPlaybackState input, ::blink::mojom::MediaSessionPlaybackState* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::MediaSessionPlaybackState, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::MediaSessionPlaybackState, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::MediaSessionPlaybackState>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::MediaImageDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::MediaImageDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::MediaImage_Data);
            decltype(CallWithContext(Traits::src, input, custom_context)) in_src = CallWithContext(Traits::src, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_src, context);
            decltype(CallWithContext(Traits::type, input, custom_context)) in_type = CallWithContext(Traits::type, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
                in_type, context);
            decltype(CallWithContext(Traits::sizes, input, custom_context)) in_sizes = CallWithContext(Traits::sizes, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::gfx::mojom::SizeDataView>>(
                in_sizes, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::MediaImage_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::MediaImage_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::src, input, custom_context)) in_src = CallWithContext(Traits::src, input, custom_context);
            typename decltype(result->src)::BaseType* src_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_src, buffer, &src_ptr, context);
            result->src.Set(src_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->src.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null src in MediaImage struct");
            decltype(CallWithContext(Traits::type, input, custom_context)) in_type = CallWithContext(Traits::type, input, custom_context);
            typename decltype(result->type)::BaseType* type_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
                in_type, buffer, &type_ptr, context);
            result->type.Set(type_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->type.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null type in MediaImage struct");
            decltype(CallWithContext(Traits::sizes, input, custom_context)) in_sizes = CallWithContext(Traits::sizes, input, custom_context);
            typename decltype(result->sizes)::BaseType* sizes_ptr;
            const mojo::internal::ContainerValidateParams sizes_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::gfx::mojom::SizeDataView>>(
                in_sizes, buffer, &sizes_ptr, &sizes_validate_params,
                context);
            result->sizes.Set(sizes_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->sizes.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null sizes in MediaImage struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::MediaImage_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::MediaImageDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::MediaMetadataDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::MediaMetadataDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::MediaMetadata_Data);
            decltype(CallWithContext(Traits::title, input, custom_context)) in_title = CallWithContext(Traits::title, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
                in_title, context);
            decltype(CallWithContext(Traits::artist, input, custom_context)) in_artist = CallWithContext(Traits::artist, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
                in_artist, context);
            decltype(CallWithContext(Traits::album, input, custom_context)) in_album = CallWithContext(Traits::album, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
                in_album, context);
            decltype(CallWithContext(Traits::artwork, input, custom_context)) in_artwork = CallWithContext(Traits::artwork, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::blink::mojom::MediaImageDataView>>(
                in_artwork, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::MediaMetadata_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::MediaMetadata_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::title, input, custom_context)) in_title = CallWithContext(Traits::title, input, custom_context);
            typename decltype(result->title)::BaseType* title_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
                in_title, buffer, &title_ptr, context);
            result->title.Set(title_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->title.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null title in MediaMetadata struct");
            decltype(CallWithContext(Traits::artist, input, custom_context)) in_artist = CallWithContext(Traits::artist, input, custom_context);
            typename decltype(result->artist)::BaseType* artist_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
                in_artist, buffer, &artist_ptr, context);
            result->artist.Set(artist_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->artist.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null artist in MediaMetadata struct");
            decltype(CallWithContext(Traits::album, input, custom_context)) in_album = CallWithContext(Traits::album, input, custom_context);
            typename decltype(result->album)::BaseType* album_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
                in_album, buffer, &album_ptr, context);
            result->album.Set(album_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->album.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null album in MediaMetadata struct");
            decltype(CallWithContext(Traits::artwork, input, custom_context)) in_artwork = CallWithContext(Traits::artwork, input, custom_context);
            typename decltype(result->artwork)::BaseType* artwork_ptr;
            const mojo::internal::ContainerValidateParams artwork_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::blink::mojom::MediaImageDataView>>(
                in_artwork, buffer, &artwork_ptr, &artwork_validate_params,
                context);
            result->artwork.Set(artwork_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->artwork.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null artwork in MediaMetadata struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::MediaMetadata_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::MediaMetadataDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace blink {
namespace mojom {

    inline void MediaImageDataView::GetSrcDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->src.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void MediaImageDataView::GetTypeDataView(
        ::mojo::common::mojom::String16DataView* output)
    {
        auto pointer = data_->type.Get();
        *output = ::mojo::common::mojom::String16DataView(pointer, context_);
    }
    inline void MediaImageDataView::GetSizesDataView(
        mojo::ArrayDataView<::gfx::mojom::SizeDataView>* output)
    {
        auto pointer = data_->sizes.Get();
        *output = mojo::ArrayDataView<::gfx::mojom::SizeDataView>(pointer, context_);
    }

    inline void MediaMetadataDataView::GetTitleDataView(
        ::mojo::common::mojom::String16DataView* output)
    {
        auto pointer = data_->title.Get();
        *output = ::mojo::common::mojom::String16DataView(pointer, context_);
    }
    inline void MediaMetadataDataView::GetArtistDataView(
        ::mojo::common::mojom::String16DataView* output)
    {
        auto pointer = data_->artist.Get();
        *output = ::mojo::common::mojom::String16DataView(pointer, context_);
    }
    inline void MediaMetadataDataView::GetAlbumDataView(
        ::mojo::common::mojom::String16DataView* output)
    {
        auto pointer = data_->album.Get();
        *output = ::mojo::common::mojom::String16DataView(pointer, context_);
    }
    inline void MediaMetadataDataView::GetArtworkDataView(
        mojo::ArrayDataView<MediaImageDataView>* output)
    {
        auto pointer = data_->artwork.Get();
        *output = mojo::ArrayDataView<MediaImageDataView>(pointer, context_);
    }

    inline void MediaSessionService_SetMetadata_ParamsDataView::GetMetadataDataView(
        MediaMetadataDataView* output)
    {
        auto pointer = data_->metadata.Get();
        *output = MediaMetadataDataView(pointer, context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_MEDIASESSION_MEDIA_SESSION_MOJOM_SHARED_H_
