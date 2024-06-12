// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_MEDIASESSION_MEDIA_SESSION_MOJOM_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_MEDIASESSION_MEDIA_SESSION_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
#include "content/common/bluetooth/web_bluetooth_device_id.h"
#include "content/common/content_export.h"
#include "content/public/common/media_metadata.h"
#include "content/public/common/referrer.h"
#include "device/bluetooth/bluetooth_uuid.h"
#include "mojo/common/string16.mojom.h"
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
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/platform/modules/mediasession/media_session.mojom-shared.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/mojo/geometry.mojom.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "url/gurl.h"
#include "url/mojo/url.mojom.h"
#include "url/origin.h"
#include <string>
#include <vector>

namespace blink {
namespace mojom {
    class MediaSessionClient;
    using MediaSessionClientPtr = mojo::InterfacePtr<MediaSessionClient>;
    using MediaSessionClientPtrInfo = mojo::InterfacePtrInfo<MediaSessionClient>;
    using ThreadSafeMediaSessionClientPtr = mojo::ThreadSafeInterfacePtr<MediaSessionClient>;
    using MediaSessionClientRequest = mojo::InterfaceRequest<MediaSessionClient>;
    using MediaSessionClientAssociatedPtr = mojo::AssociatedInterfacePtr<MediaSessionClient>;
    using ThreadSafeMediaSessionClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<MediaSessionClient>;
    using MediaSessionClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<MediaSessionClient>;
    using MediaSessionClientAssociatedRequest = mojo::AssociatedInterfaceRequest<MediaSessionClient>;

    class MediaSessionService;
    using MediaSessionServicePtr = mojo::InterfacePtr<MediaSessionService>;
    using MediaSessionServicePtrInfo = mojo::InterfacePtrInfo<MediaSessionService>;
    using ThreadSafeMediaSessionServicePtr = mojo::ThreadSafeInterfacePtr<MediaSessionService>;
    using MediaSessionServiceRequest = mojo::InterfaceRequest<MediaSessionService>;
    using MediaSessionServiceAssociatedPtr = mojo::AssociatedInterfacePtr<MediaSessionService>;
    using ThreadSafeMediaSessionServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<MediaSessionService>;
    using MediaSessionServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<MediaSessionService>;
    using MediaSessionServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<MediaSessionService>;

    class MediaImage;
    using MediaImagePtr = mojo::StructPtr<MediaImage>;

    class MediaMetadata;
    using MediaMetadataPtr = mojo::StructPtr<MediaMetadata>;

    class MediaSessionClientProxy;

    template <typename ImplRefTraits>
    class MediaSessionClientStub;

    class MediaSessionClientRequestValidator;

    class CONTENT_EXPORT MediaSessionClient
        : public MediaSessionClientInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = MediaSessionClientProxy;

        template <typename ImplRefTraits>
        using Stub_ = MediaSessionClientStub<ImplRefTraits>;

        using RequestValidator_ = MediaSessionClientRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kDidReceiveActionMinVersion = 0,
        };
        virtual ~MediaSessionClient() { }

        virtual void DidReceiveAction(MediaSessionAction action) = 0;
    };

    class MediaSessionServiceProxy;

    template <typename ImplRefTraits>
    class MediaSessionServiceStub;

    class MediaSessionServiceRequestValidator;

    class CONTENT_EXPORT MediaSessionService
        : public MediaSessionServiceInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = MediaSessionServiceProxy;

        template <typename ImplRefTraits>
        using Stub_ = MediaSessionServiceStub<ImplRefTraits>;

        using RequestValidator_ = MediaSessionServiceRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kSetClientMinVersion = 0,
            kSetPlaybackStateMinVersion = 0,
            kSetMetadataMinVersion = 0,
            kEnableActionMinVersion = 0,
            kDisableActionMinVersion = 0,
        };
        virtual ~MediaSessionService() { }

        virtual void SetClient(MediaSessionClientPtr client) = 0;

        virtual void SetPlaybackState(MediaSessionPlaybackState state) = 0;

        virtual void SetMetadata(const base::Optional<content::MediaMetadata>& metadata) = 0;

        virtual void EnableAction(MediaSessionAction action) = 0;

        virtual void DisableAction(MediaSessionAction action) = 0;
    };

    class CONTENT_EXPORT MediaSessionClientProxy
        : public MediaSessionClient {
    public:
        explicit MediaSessionClientProxy(mojo::MessageReceiverWithResponder* receiver);
        void DidReceiveAction(MediaSessionAction action) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class CONTENT_EXPORT MediaSessionServiceProxy
        : public MediaSessionService {
    public:
        explicit MediaSessionServiceProxy(mojo::MessageReceiverWithResponder* receiver);
        void SetClient(MediaSessionClientPtr client) override;
        void SetPlaybackState(MediaSessionPlaybackState state) override;
        void SetMetadata(const base::Optional<content::MediaMetadata>& metadata) override;
        void EnableAction(MediaSessionAction action) override;
        void DisableAction(MediaSessionAction action) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class CONTENT_EXPORT MediaSessionClientStubDispatch {
    public:
        static bool Accept(MediaSessionClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(MediaSessionClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<MediaSessionClient>>
    class MediaSessionClientStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        MediaSessionClientStub() { }
        ~MediaSessionClientStub() override { }

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
            return MediaSessionClientStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return MediaSessionClientStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT MediaSessionServiceStubDispatch {
    public:
        static bool Accept(MediaSessionService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(MediaSessionService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<MediaSessionService>>
    class MediaSessionServiceStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        MediaSessionServiceStub() { }
        ~MediaSessionServiceStub() override { }

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
            return MediaSessionServiceStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return MediaSessionServiceStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT MediaSessionClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT MediaSessionServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class CONTENT_EXPORT MediaImage {
    public:
        using DataView = MediaImageDataView;
        using Data_ = internal::MediaImage_Data;

        static MediaImagePtr New();

        template <typename U>
        static MediaImagePtr From(const U& u)
        {
            return mojo::TypeConverter<MediaImagePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, MediaImage>::Convert(*this);
        }

        MediaImage();
        ~MediaImage();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = MediaImagePtr>
        MediaImagePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, MediaImage>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                MediaImage::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                MediaImage::DataView, std::vector<uint8_t>>(
                input, output);
        }

        GURL src;
        base::string16 type;
        std::vector<gfx::Size> sizes;
    };

    class CONTENT_EXPORT MediaMetadata {
    public:
        using DataView = MediaMetadataDataView;
        using Data_ = internal::MediaMetadata_Data;

        static MediaMetadataPtr New();

        template <typename U>
        static MediaMetadataPtr From(const U& u)
        {
            return mojo::TypeConverter<MediaMetadataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, MediaMetadata>::Convert(*this);
        }

        MediaMetadata();
        ~MediaMetadata();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = MediaMetadataPtr>
        MediaMetadataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, MediaMetadata>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                MediaMetadata::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                MediaMetadata::DataView, std::vector<uint8_t>>(
                input, output);
        }

        base::string16 title;
        base::string16 artist;
        base::string16 album;
        std::vector<content::MediaMetadata::MediaImage> artwork;
    };

    template <typename StructPtrType>
    MediaImagePtr MediaImage::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->src = mojo::internal::Clone(src);
        rv->type = mojo::internal::Clone(type);
        rv->sizes = mojo::internal::Clone(sizes);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, MediaImage>::value>::type*>
    bool MediaImage::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->src, other.src))
            return false;
        if (!mojo::internal::Equals(this->type, other.type))
            return false;
        if (!mojo::internal::Equals(this->sizes, other.sizes))
            return false;
        return true;
    }
    template <typename StructPtrType>
    MediaMetadataPtr MediaMetadata::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->title = mojo::internal::Clone(title);
        rv->artist = mojo::internal::Clone(artist);
        rv->album = mojo::internal::Clone(album);
        rv->artwork = mojo::internal::Clone(artwork);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, MediaMetadata>::value>::type*>
    bool MediaMetadata::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->title, other.title))
            return false;
        if (!mojo::internal::Equals(this->artist, other.artist))
            return false;
        if (!mojo::internal::Equals(this->album, other.album))
            return false;
        if (!mojo::internal::Equals(this->artwork, other.artwork))
            return false;
        return true;
    }

} // namespace mojom
} // namespace blink

namespace mojo {

template <>
struct CONTENT_EXPORT StructTraits<::blink::mojom::MediaImage::DataView,
    ::blink::mojom::MediaImagePtr> {
    static bool IsNull(const ::blink::mojom::MediaImagePtr& input) { return !input; }
    static void SetToNull(::blink::mojom::MediaImagePtr* output) { output->reset(); }

    static const decltype(::blink::mojom::MediaImage::src)& src(
        const ::blink::mojom::MediaImagePtr& input)
    {
        return input->src;
    }

    static const decltype(::blink::mojom::MediaImage::type)& type(
        const ::blink::mojom::MediaImagePtr& input)
    {
        return input->type;
    }

    static const decltype(::blink::mojom::MediaImage::sizes)& sizes(
        const ::blink::mojom::MediaImagePtr& input)
    {
        return input->sizes;
    }

    static bool Read(::blink::mojom::MediaImage::DataView input, ::blink::mojom::MediaImagePtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::blink::mojom::MediaMetadata::DataView,
    ::blink::mojom::MediaMetadataPtr> {
    static bool IsNull(const ::blink::mojom::MediaMetadataPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::MediaMetadataPtr* output) { output->reset(); }

    static const decltype(::blink::mojom::MediaMetadata::title)& title(
        const ::blink::mojom::MediaMetadataPtr& input)
    {
        return input->title;
    }

    static const decltype(::blink::mojom::MediaMetadata::artist)& artist(
        const ::blink::mojom::MediaMetadataPtr& input)
    {
        return input->artist;
    }

    static const decltype(::blink::mojom::MediaMetadata::album)& album(
        const ::blink::mojom::MediaMetadataPtr& input)
    {
        return input->album;
    }

    static const decltype(::blink::mojom::MediaMetadata::artwork)& artwork(
        const ::blink::mojom::MediaMetadataPtr& input)
    {
        return input->artwork;
    }

    static bool Read(::blink::mojom::MediaMetadata::DataView input, ::blink::mojom::MediaMetadataPtr* output);
};

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_MEDIASESSION_MEDIA_SESSION_MOJOM_H_