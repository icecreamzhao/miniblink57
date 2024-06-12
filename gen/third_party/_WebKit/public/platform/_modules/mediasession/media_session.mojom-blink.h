// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_MEDIASESSION_MEDIA_SESSION_MOJOM_BLINK_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_MEDIASESSION_MEDIA_SESSION_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "mojo/common/string16.mojom-blink.h"
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
#include "third_party/WebKit/public/platform/modules/mediasession/media_session.mojom-shared.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-blink.h"
#include "url/mojo/url.mojom-blink.h"

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/platform/weborigin/KURL.h"
#include "third_party/WebKit/Source/platform/weborigin/SecurityOrigin.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebCommon.h"
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/platform/WebSize.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"

namespace blink {
namespace mojom {
    namespace blink {
        using MediaSessionAction = MediaSessionAction; // Alias for definition in the parent namespace.
        using MediaSessionPlaybackState = MediaSessionPlaybackState; // Alias for definition in the parent namespace.
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

        class BLINK_PLATFORM_EXPORT MediaSessionClient
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

        class BLINK_PLATFORM_EXPORT MediaSessionService
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

            virtual void SetMetadata(MediaMetadataPtr metadata) = 0;

            virtual void EnableAction(MediaSessionAction action) = 0;

            virtual void DisableAction(MediaSessionAction action) = 0;
        };

        class BLINK_PLATFORM_EXPORT MediaSessionClientProxy
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

        class BLINK_PLATFORM_EXPORT MediaSessionServiceProxy
            : public MediaSessionService {
        public:
            explicit MediaSessionServiceProxy(mojo::MessageReceiverWithResponder* receiver);
            void SetClient(MediaSessionClientPtr client) override;
            void SetPlaybackState(MediaSessionPlaybackState state) override;
            void SetMetadata(MediaMetadataPtr metadata) override;
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
        class BLINK_PLATFORM_EXPORT MediaSessionClientStubDispatch {
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
        class BLINK_PLATFORM_EXPORT MediaSessionServiceStubDispatch {
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
        class BLINK_PLATFORM_EXPORT MediaSessionClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT MediaSessionServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

        class BLINK_PLATFORM_EXPORT MediaImage {
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    MediaImage::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    MediaImage::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::blink::KURL src;
            WTF::String type;
            WTF::Vector<::blink::WebSize> sizes;
        };

        class BLINK_PLATFORM_EXPORT MediaMetadata {
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    MediaMetadata::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    MediaMetadata::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::String title;
            WTF::String artist;
            WTF::String album;
            WTF::Vector<MediaImagePtr> artwork;

        private:
            DISALLOW_COPY_AND_ASSIGN(MediaMetadata);
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

    } // namespace blink
} // namespace mojom
} // namespace blink

namespace mojo {

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::MediaImage::DataView,
    ::blink::mojom::blink::MediaImagePtr> {
    static bool IsNull(const ::blink::mojom::blink::MediaImagePtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::MediaImagePtr* output) { output->reset(); }

    static const decltype(::blink::mojom::blink::MediaImage::src)& src(
        const ::blink::mojom::blink::MediaImagePtr& input)
    {
        return input->src;
    }

    static const decltype(::blink::mojom::blink::MediaImage::type)& type(
        const ::blink::mojom::blink::MediaImagePtr& input)
    {
        return input->type;
    }

    static const decltype(::blink::mojom::blink::MediaImage::sizes)& sizes(
        const ::blink::mojom::blink::MediaImagePtr& input)
    {
        return input->sizes;
    }

    static bool Read(::blink::mojom::blink::MediaImage::DataView input, ::blink::mojom::blink::MediaImagePtr* output);
};

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::MediaMetadata::DataView,
    ::blink::mojom::blink::MediaMetadataPtr> {
    static bool IsNull(const ::blink::mojom::blink::MediaMetadataPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::MediaMetadataPtr* output) { output->reset(); }

    static const decltype(::blink::mojom::blink::MediaMetadata::title)& title(
        const ::blink::mojom::blink::MediaMetadataPtr& input)
    {
        return input->title;
    }

    static const decltype(::blink::mojom::blink::MediaMetadata::artist)& artist(
        const ::blink::mojom::blink::MediaMetadataPtr& input)
    {
        return input->artist;
    }

    static const decltype(::blink::mojom::blink::MediaMetadata::album)& album(
        const ::blink::mojom::blink::MediaMetadataPtr& input)
    {
        return input->album;
    }

    static const decltype(::blink::mojom::blink::MediaMetadata::artwork)& artwork(
        const ::blink::mojom::blink::MediaMetadataPtr& input)
    {
        return input->artwork;
    }

    static bool Read(::blink::mojom::blink::MediaMetadata::DataView input, ::blink::mojom::blink::MediaMetadataPtr* output);
};

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_MEDIASESSION_MEDIA_SESSION_MOJOM_BLINK_H_