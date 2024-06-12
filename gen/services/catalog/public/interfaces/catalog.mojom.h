// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_CATALOG_PUBLIC_INTERFACES_CATALOG_MOJOM_H_
#define SERVICES_CATALOG_PUBLIC_INTERFACES_CATALOG_MOJOM_H_

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
#include "mojo/common/file_path.mojom.h"
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
#include "services/catalog/public/interfaces/catalog.mojom-shared.h"
#include <string>
#include <vector>

namespace catalog {
namespace mojom {
    class Catalog;
    using CatalogPtr = mojo::InterfacePtr<Catalog>;
    using CatalogPtrInfo = mojo::InterfacePtrInfo<Catalog>;
    using ThreadSafeCatalogPtr = mojo::ThreadSafeInterfacePtr<Catalog>;
    using CatalogRequest = mojo::InterfaceRequest<Catalog>;
    using CatalogAssociatedPtr = mojo::AssociatedInterfacePtr<Catalog>;
    using ThreadSafeCatalogAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Catalog>;
    using CatalogAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Catalog>;
    using CatalogAssociatedRequest = mojo::AssociatedInterfaceRequest<Catalog>;

    class CatalogControl;
    using CatalogControlPtr = mojo::InterfacePtr<CatalogControl>;
    using CatalogControlPtrInfo = mojo::InterfacePtrInfo<CatalogControl>;
    using ThreadSafeCatalogControlPtr = mojo::ThreadSafeInterfacePtr<CatalogControl>;
    using CatalogControlRequest = mojo::InterfaceRequest<CatalogControl>;
    using CatalogControlAssociatedPtr = mojo::AssociatedInterfacePtr<CatalogControl>;
    using ThreadSafeCatalogControlAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<CatalogControl>;
    using CatalogControlAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<CatalogControl>;
    using CatalogControlAssociatedRequest = mojo::AssociatedInterfaceRequest<CatalogControl>;

    class Entry;
    using EntryPtr = mojo::InlinedStructPtr<Entry>;

    class CatalogProxy;

    template <typename ImplRefTraits>
    class CatalogStub;

    class CatalogRequestValidator;
    class CatalogResponseValidator;

    class Catalog
        : public CatalogInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = true;

        using Proxy_ = CatalogProxy;

        template <typename ImplRefTraits>
        using Stub_ = CatalogStub<ImplRefTraits>;

        using RequestValidator_ = CatalogRequestValidator;
        using ResponseValidator_ = CatalogResponseValidator;
        enum MethodMinVersions : uint32_t {
            kGetEntriesMinVersion = 0,
            kGetEntriesProvidingCapabilityMinVersion = 0,
            kGetEntriesConsumingMIMETypeMinVersion = 0,
            kGetEntriesSupportingSchemeMinVersion = 0,
        };
        virtual ~Catalog() { }

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool GetEntries(const base::Optional<std::vector<std::string>>& names, std::vector<EntryPtr>* entries);

        using GetEntriesCallback = base::Callback<void(std::vector<EntryPtr>)>;
        virtual void GetEntries(const base::Optional<std::vector<std::string>>& names, const GetEntriesCallback& callback) = 0;

        using GetEntriesProvidingCapabilityCallback = base::Callback<void(std::vector<EntryPtr>)>;
        virtual void GetEntriesProvidingCapability(const std::string& capability, const GetEntriesProvidingCapabilityCallback& callback) = 0;

        using GetEntriesConsumingMIMETypeCallback = base::Callback<void(std::vector<EntryPtr>)>;
        virtual void GetEntriesConsumingMIMEType(const std::string& mime_type, const GetEntriesConsumingMIMETypeCallback& callback) = 0;

        using GetEntriesSupportingSchemeCallback = base::Callback<void(std::vector<EntryPtr>)>;
        virtual void GetEntriesSupportingScheme(const std::string& protocol_scheme, const GetEntriesSupportingSchemeCallback& callback) = 0;
    };

    class CatalogControlProxy;

    template <typename ImplRefTraits>
    class CatalogControlStub;

    class CatalogControlRequestValidator;
    class CatalogControlResponseValidator;

    class CatalogControl
        : public CatalogControlInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = true;

        using Proxy_ = CatalogControlProxy;

        template <typename ImplRefTraits>
        using Stub_ = CatalogControlStub<ImplRefTraits>;

        using RequestValidator_ = CatalogControlRequestValidator;
        using ResponseValidator_ = CatalogControlResponseValidator;
        enum MethodMinVersions : uint32_t {
            kOverrideManifestPathMinVersion = 0,
        };
        virtual ~CatalogControl() { }

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool OverrideManifestPath(const std::string& name, const base::FilePath& path);

        using OverrideManifestPathCallback = base::Callback<void()>;
        virtual void OverrideManifestPath(const std::string& name, const base::FilePath& path, const OverrideManifestPathCallback& callback) = 0;
    };

    class CatalogProxy
        : public Catalog {
    public:
        explicit CatalogProxy(mojo::MessageReceiverWithResponder* receiver);
        bool GetEntries(const base::Optional<std::vector<std::string>>& names, std::vector<EntryPtr>* entries) override;
        void GetEntries(const base::Optional<std::vector<std::string>>& names, const GetEntriesCallback& callback) override;
        void GetEntriesProvidingCapability(const std::string& capability, const GetEntriesProvidingCapabilityCallback& callback) override;
        void GetEntriesConsumingMIMEType(const std::string& mime_type, const GetEntriesConsumingMIMETypeCallback& callback) override;
        void GetEntriesSupportingScheme(const std::string& protocol_scheme, const GetEntriesSupportingSchemeCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class CatalogControlProxy
        : public CatalogControl {
    public:
        explicit CatalogControlProxy(mojo::MessageReceiverWithResponder* receiver);
        bool OverrideManifestPath(const std::string& name, const base::FilePath& path) override;
        void OverrideManifestPath(const std::string& name, const base::FilePath& path, const OverrideManifestPathCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class CatalogStubDispatch {
    public:
        static bool Accept(Catalog* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Catalog* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Catalog>>
    class CatalogStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        CatalogStub() { }
        ~CatalogStub() override { }

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
            return CatalogStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return CatalogStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CatalogControlStubDispatch {
    public:
        static bool Accept(CatalogControl* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(CatalogControl* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<CatalogControl>>
    class CatalogControlStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        CatalogControlStub() { }
        ~CatalogControlStub() override { }

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
            return CatalogControlStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return CatalogControlStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CatalogRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CatalogControlRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CatalogResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CatalogControlResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class Entry {
    public:
        using DataView = EntryDataView;
        using Data_ = internal::Entry_Data;

        static EntryPtr New();

        template <typename U>
        static EntryPtr From(const U& u)
        {
            return mojo::TypeConverter<EntryPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Entry>::Convert(*this);
        }

        Entry();
        ~Entry();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = EntryPtr>
        EntryPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Entry>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Entry::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Entry::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string name;
        std::string display_name;
    };

    template <typename StructPtrType>
    EntryPtr Entry::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->name = mojo::internal::Clone(name);
        rv->display_name = mojo::internal::Clone(display_name);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Entry>::value>::type*>
    bool Entry::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->name, other.name))
            return false;
        if (!mojo::internal::Equals(this->display_name, other.display_name))
            return false;
        return true;
    }

} // namespace mojom
} // namespace catalog

namespace mojo {

template <>
struct StructTraits<::catalog::mojom::Entry::DataView,
    ::catalog::mojom::EntryPtr> {
    static bool IsNull(const ::catalog::mojom::EntryPtr& input) { return !input; }
    static void SetToNull(::catalog::mojom::EntryPtr* output) { output->reset(); }

    static const decltype(::catalog::mojom::Entry::name)& name(
        const ::catalog::mojom::EntryPtr& input)
    {
        return input->name;
    }

    static const decltype(::catalog::mojom::Entry::display_name)& display_name(
        const ::catalog::mojom::EntryPtr& input)
    {
        return input->display_name;
    }

    static bool Read(::catalog::mojom::Entry::DataView input, ::catalog::mojom::EntryPtr* output);
};

} // namespace mojo

#endif // SERVICES_CATALOG_PUBLIC_INTERFACES_CATALOG_MOJOM_H_