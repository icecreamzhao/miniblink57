// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_NFC_NFC_MOJOM_BLINK_H_
#define DEVICE_NFC_NFC_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/nfc/nfc.mojom-shared.h"
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

#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"

namespace device {
namespace nfc {
    namespace mojom {
        namespace blink {
            using NFCErrorType = NFCErrorType; // Alias for definition in the parent namespace.
            using NFCRecordType = NFCRecordType; // Alias for definition in the parent namespace.
            using NFCPushTarget = NFCPushTarget; // Alias for definition in the parent namespace.
            using NFCWatchMode = NFCWatchMode; // Alias for definition in the parent namespace.
            class NFC;
            using NFCPtr = mojo::InterfacePtr<NFC>;
            using NFCPtrInfo = mojo::InterfacePtrInfo<NFC>;
            using ThreadSafeNFCPtr = mojo::ThreadSafeInterfacePtr<NFC>;
            using NFCRequest = mojo::InterfaceRequest<NFC>;
            using NFCAssociatedPtr = mojo::AssociatedInterfacePtr<NFC>;
            using ThreadSafeNFCAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<NFC>;
            using NFCAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<NFC>;
            using NFCAssociatedRequest = mojo::AssociatedInterfaceRequest<NFC>;

            class NFCClient;
            using NFCClientPtr = mojo::InterfacePtr<NFCClient>;
            using NFCClientPtrInfo = mojo::InterfacePtrInfo<NFCClient>;
            using ThreadSafeNFCClientPtr = mojo::ThreadSafeInterfacePtr<NFCClient>;
            using NFCClientRequest = mojo::InterfaceRequest<NFCClient>;
            using NFCClientAssociatedPtr = mojo::AssociatedInterfacePtr<NFCClient>;
            using ThreadSafeNFCClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<NFCClient>;
            using NFCClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<NFCClient>;
            using NFCClientAssociatedRequest = mojo::AssociatedInterfaceRequest<NFCClient>;

            class NFCError;
            using NFCErrorPtr = mojo::InlinedStructPtr<NFCError>;

            class NFCRecord;
            using NFCRecordPtr = mojo::StructPtr<NFCRecord>;

            class NFCMessage;
            using NFCMessagePtr = mojo::StructPtr<NFCMessage>;

            class NFCPushOptions;
            using NFCPushOptionsPtr = mojo::InlinedStructPtr<NFCPushOptions>;

            class NFCRecordTypeFilter;
            using NFCRecordTypeFilterPtr = mojo::InlinedStructPtr<NFCRecordTypeFilter>;

            class NFCWatchOptions;
            using NFCWatchOptionsPtr = mojo::StructPtr<NFCWatchOptions>;

            class NFCProxy;

            template <typename ImplRefTraits>
            class NFCStub;

            class NFCRequestValidator;
            class NFCResponseValidator;

            class NFC
                : public NFCInterfaceBase {
            public:
                static const char Name_[];
                static constexpr uint32_t Version_ = 0;
                static constexpr bool PassesAssociatedKinds_ = false;
                static constexpr bool HasSyncMethods_ = false;

                using Proxy_ = NFCProxy;

                template <typename ImplRefTraits>
                using Stub_ = NFCStub<ImplRefTraits>;

                using RequestValidator_ = NFCRequestValidator;
                using ResponseValidator_ = NFCResponseValidator;
                enum MethodMinVersions : uint32_t {
                    kSetClientMinVersion = 0,
                    kPushMinVersion = 0,
                    kCancelPushMinVersion = 0,
                    kWatchMinVersion = 0,
                    kCancelWatchMinVersion = 0,
                    kCancelAllWatchesMinVersion = 0,
                    kSuspendNFCOperationsMinVersion = 0,
                    kResumeNFCOperationsMinVersion = 0,
                };
                virtual ~NFC() { }

                virtual void SetClient(NFCClientPtr client) = 0;

                using PushCallback = base::Callback<void(NFCErrorPtr)>;
                virtual void Push(NFCMessagePtr message, NFCPushOptionsPtr options, const PushCallback& callback) = 0;

                using CancelPushCallback = base::Callback<void(NFCErrorPtr)>;
                virtual void CancelPush(NFCPushTarget target, const CancelPushCallback& callback) = 0;

                using WatchCallback = base::Callback<void(uint32_t, NFCErrorPtr)>;
                virtual void Watch(NFCWatchOptionsPtr options, const WatchCallback& callback) = 0;

                using CancelWatchCallback = base::Callback<void(NFCErrorPtr)>;
                virtual void CancelWatch(uint32_t id, const CancelWatchCallback& callback) = 0;

                using CancelAllWatchesCallback = base::Callback<void(NFCErrorPtr)>;
                virtual void CancelAllWatches(const CancelAllWatchesCallback& callback) = 0;

                virtual void SuspendNFCOperations() = 0;

                virtual void ResumeNFCOperations() = 0;
            };

            class NFCClientProxy;

            template <typename ImplRefTraits>
            class NFCClientStub;

            class NFCClientRequestValidator;

            class NFCClient
                : public NFCClientInterfaceBase {
            public:
                static const char Name_[];
                static constexpr uint32_t Version_ = 0;
                static constexpr bool PassesAssociatedKinds_ = false;
                static constexpr bool HasSyncMethods_ = false;

                using Proxy_ = NFCClientProxy;

                template <typename ImplRefTraits>
                using Stub_ = NFCClientStub<ImplRefTraits>;

                using RequestValidator_ = NFCClientRequestValidator;
                using ResponseValidator_ = mojo::PassThroughFilter;
                enum MethodMinVersions : uint32_t {
                    kOnWatchMinVersion = 0,
                };
                virtual ~NFCClient() { }

                virtual void OnWatch(const WTF::Vector<uint32_t>& watch_ids, NFCMessagePtr message) = 0;
            };

            class NFCProxy
                : public NFC {
            public:
                explicit NFCProxy(mojo::MessageReceiverWithResponder* receiver);
                void SetClient(NFCClientPtr client) override;
                void Push(NFCMessagePtr message, NFCPushOptionsPtr options, const PushCallback& callback) override;
                void CancelPush(NFCPushTarget target, const CancelPushCallback& callback) override;
                void Watch(NFCWatchOptionsPtr options, const WatchCallback& callback) override;
                void CancelWatch(uint32_t id, const CancelWatchCallback& callback) override;
                void CancelAllWatches(const CancelAllWatchesCallback& callback) override;
                void SuspendNFCOperations() override;
                void ResumeNFCOperations() override;

                void set_group_controller(
                    scoped_refptr<mojo::AssociatedGroupController> group_controller)
                {
                    group_controller_ = std::move(group_controller);
                }

            private:
                mojo::MessageReceiverWithResponder* receiver_;
                scoped_refptr<mojo::AssociatedGroupController> group_controller_;
            };

            class NFCClientProxy
                : public NFCClient {
            public:
                explicit NFCClientProxy(mojo::MessageReceiverWithResponder* receiver);
                void OnWatch(const WTF::Vector<uint32_t>& watch_ids, NFCMessagePtr message) override;

                void set_group_controller(
                    scoped_refptr<mojo::AssociatedGroupController> group_controller)
                {
                    group_controller_ = std::move(group_controller);
                }

            private:
                mojo::MessageReceiverWithResponder* receiver_;
                scoped_refptr<mojo::AssociatedGroupController> group_controller_;
            };
            class NFCStubDispatch {
            public:
                static bool Accept(NFC* impl,
                    mojo::internal::SerializationContext* context,
                    mojo::Message* message);
                static bool AcceptWithResponder(NFC* impl,
                    mojo::internal::SerializationContext* context,
                    mojo::Message* message,
                    mojo::MessageReceiverWithStatus* responder);
            };

            template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<NFC>>
            class NFCStub
                : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
            public:
                using ImplPointerType = typename ImplRefTraits::PointerType;

                NFCStub() { }
                ~NFCStub() override { }

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
                    return NFCStubDispatch::Accept(
                        ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
                }

                bool AcceptWithResponder(
                    mojo::Message* message,
                    mojo::MessageReceiverWithStatus* responder) override
                {
                    if (ImplRefTraits::IsNull(sink_))
                        return false;
                    return NFCStubDispatch::AcceptWithResponder(
                        ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                        responder);
                }

            private:
                ImplPointerType sink_;
                mojo::internal::SerializationContext serialization_context_;
            };
            class NFCClientStubDispatch {
            public:
                static bool Accept(NFCClient* impl,
                    mojo::internal::SerializationContext* context,
                    mojo::Message* message);
                static bool AcceptWithResponder(NFCClient* impl,
                    mojo::internal::SerializationContext* context,
                    mojo::Message* message,
                    mojo::MessageReceiverWithStatus* responder);
            };

            template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<NFCClient>>
            class NFCClientStub
                : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
            public:
                using ImplPointerType = typename ImplRefTraits::PointerType;

                NFCClientStub() { }
                ~NFCClientStub() override { }

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
                    return NFCClientStubDispatch::Accept(
                        ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
                }

                bool AcceptWithResponder(
                    mojo::Message* message,
                    mojo::MessageReceiverWithStatus* responder) override
                {
                    if (ImplRefTraits::IsNull(sink_))
                        return false;
                    return NFCClientStubDispatch::AcceptWithResponder(
                        ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                        responder);
                }

            private:
                ImplPointerType sink_;
                mojo::internal::SerializationContext serialization_context_;
            };
            class NFCRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
            public:
                bool Accept(mojo::Message* message) override;
            };
            class NFCClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
            public:
                bool Accept(mojo::Message* message) override;
            };
            class NFCResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
            public:
                bool Accept(mojo::Message* message) override;
            };

            class NFCError {
            public:
                using DataView = NFCErrorDataView;
                using Data_ = internal::NFCError_Data;

                static NFCErrorPtr New();

                template <typename U>
                static NFCErrorPtr From(const U& u)
                {
                    return mojo::TypeConverter<NFCErrorPtr, U>::Convert(u);
                }

                template <typename U>
                U To() const
                {
                    return mojo::TypeConverter<U, NFCError>::Convert(*this);
                }

                NFCError();
                ~NFCError();

                // Clone() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Clone() or copy
                // constructor/assignment are available for members.
                template <typename StructPtrType = NFCErrorPtr>
                NFCErrorPtr Clone() const;

                // Equals() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Equals() or == operator
                // are available for members.
                template <typename T,
                    typename std::enable_if<std::is_same<
                        T, NFCError>::value>::type* = nullptr>
                bool Equals(const T& other) const;
                size_t Hash(size_t seed) const;

                template <typename UserType>
                static WTF::Vector<uint8_t> Serialize(UserType* input)
                {
                    return mojo::internal::StructSerializeImpl<
                        NFCError::DataView, WTF::Vector<uint8_t>>(input);
                }

                template <typename UserType>
                static bool Deserialize(const WTF::Vector<uint8_t>& input,
                    UserType* output)
                {
                    return mojo::internal::StructDeserializeImpl<
                        NFCError::DataView, WTF::Vector<uint8_t>>(
                        input, output);
                }

                NFCErrorType error_type;
            };

            class NFCPushOptions {
            public:
                using DataView = NFCPushOptionsDataView;
                using Data_ = internal::NFCPushOptions_Data;

                static NFCPushOptionsPtr New();

                template <typename U>
                static NFCPushOptionsPtr From(const U& u)
                {
                    return mojo::TypeConverter<NFCPushOptionsPtr, U>::Convert(u);
                }

                template <typename U>
                U To() const
                {
                    return mojo::TypeConverter<U, NFCPushOptions>::Convert(*this);
                }

                NFCPushOptions();
                ~NFCPushOptions();

                // Clone() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Clone() or copy
                // constructor/assignment are available for members.
                template <typename StructPtrType = NFCPushOptionsPtr>
                NFCPushOptionsPtr Clone() const;

                // Equals() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Equals() or == operator
                // are available for members.
                template <typename T,
                    typename std::enable_if<std::is_same<
                        T, NFCPushOptions>::value>::type* = nullptr>
                bool Equals(const T& other) const;
                size_t Hash(size_t seed) const;

                template <typename UserType>
                static WTF::Vector<uint8_t> Serialize(UserType* input)
                {
                    return mojo::internal::StructSerializeImpl<
                        NFCPushOptions::DataView, WTF::Vector<uint8_t>>(input);
                }

                template <typename UserType>
                static bool Deserialize(const WTF::Vector<uint8_t>& input,
                    UserType* output)
                {
                    return mojo::internal::StructDeserializeImpl<
                        NFCPushOptions::DataView, WTF::Vector<uint8_t>>(
                        input, output);
                }

                NFCPushTarget target;
                double timeout;
                bool ignore_read;
            };

            class NFCRecordTypeFilter {
            public:
                using DataView = NFCRecordTypeFilterDataView;
                using Data_ = internal::NFCRecordTypeFilter_Data;

                static NFCRecordTypeFilterPtr New();

                template <typename U>
                static NFCRecordTypeFilterPtr From(const U& u)
                {
                    return mojo::TypeConverter<NFCRecordTypeFilterPtr, U>::Convert(u);
                }

                template <typename U>
                U To() const
                {
                    return mojo::TypeConverter<U, NFCRecordTypeFilter>::Convert(*this);
                }

                NFCRecordTypeFilter();
                ~NFCRecordTypeFilter();

                // Clone() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Clone() or copy
                // constructor/assignment are available for members.
                template <typename StructPtrType = NFCRecordTypeFilterPtr>
                NFCRecordTypeFilterPtr Clone() const;

                // Equals() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Equals() or == operator
                // are available for members.
                template <typename T,
                    typename std::enable_if<std::is_same<
                        T, NFCRecordTypeFilter>::value>::type* = nullptr>
                bool Equals(const T& other) const;
                size_t Hash(size_t seed) const;

                template <typename UserType>
                static WTF::Vector<uint8_t> Serialize(UserType* input)
                {
                    return mojo::internal::StructSerializeImpl<
                        NFCRecordTypeFilter::DataView, WTF::Vector<uint8_t>>(input);
                }

                template <typename UserType>
                static bool Deserialize(const WTF::Vector<uint8_t>& input,
                    UserType* output)
                {
                    return mojo::internal::StructDeserializeImpl<
                        NFCRecordTypeFilter::DataView, WTF::Vector<uint8_t>>(
                        input, output);
                }

                NFCRecordType record_type;
            };

            class NFCRecord {
            public:
                using DataView = NFCRecordDataView;
                using Data_ = internal::NFCRecord_Data;

                static NFCRecordPtr New();

                template <typename U>
                static NFCRecordPtr From(const U& u)
                {
                    return mojo::TypeConverter<NFCRecordPtr, U>::Convert(u);
                }

                template <typename U>
                U To() const
                {
                    return mojo::TypeConverter<U, NFCRecord>::Convert(*this);
                }

                NFCRecord();
                ~NFCRecord();

                // Clone() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Clone() or copy
                // constructor/assignment are available for members.
                template <typename StructPtrType = NFCRecordPtr>
                NFCRecordPtr Clone() const;

                // Equals() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Equals() or == operator
                // are available for members.
                template <typename T,
                    typename std::enable_if<std::is_same<
                        T, NFCRecord>::value>::type* = nullptr>
                bool Equals(const T& other) const;

                template <typename UserType>
                static WTF::Vector<uint8_t> Serialize(UserType* input)
                {
                    return mojo::internal::StructSerializeImpl<
                        NFCRecord::DataView, WTF::Vector<uint8_t>>(input);
                }

                template <typename UserType>
                static bool Deserialize(const WTF::Vector<uint8_t>& input,
                    UserType* output)
                {
                    return mojo::internal::StructDeserializeImpl<
                        NFCRecord::DataView, WTF::Vector<uint8_t>>(
                        input, output);
                }

                NFCRecordType record_type;
                WTF::String media_type;
                WTF::Vector<uint8_t> data;
            };

            class NFCMessage {
            public:
                using DataView = NFCMessageDataView;
                using Data_ = internal::NFCMessage_Data;
                static constexpr uint32_t kMaxSize = 32768U;

                static NFCMessagePtr New();

                template <typename U>
                static NFCMessagePtr From(const U& u)
                {
                    return mojo::TypeConverter<NFCMessagePtr, U>::Convert(u);
                }

                template <typename U>
                U To() const
                {
                    return mojo::TypeConverter<U, NFCMessage>::Convert(*this);
                }

                NFCMessage();
                ~NFCMessage();

                // Clone() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Clone() or copy
                // constructor/assignment are available for members.
                template <typename StructPtrType = NFCMessagePtr>
                NFCMessagePtr Clone() const;

                // Equals() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Equals() or == operator
                // are available for members.
                template <typename T,
                    typename std::enable_if<std::is_same<
                        T, NFCMessage>::value>::type* = nullptr>
                bool Equals(const T& other) const;

                template <typename UserType>
                static WTF::Vector<uint8_t> Serialize(UserType* input)
                {
                    return mojo::internal::StructSerializeImpl<
                        NFCMessage::DataView, WTF::Vector<uint8_t>>(input);
                }

                template <typename UserType>
                static bool Deserialize(const WTF::Vector<uint8_t>& input,
                    UserType* output)
                {
                    return mojo::internal::StructDeserializeImpl<
                        NFCMessage::DataView, WTF::Vector<uint8_t>>(
                        input, output);
                }

                WTF::Vector<NFCRecordPtr> data;
                WTF::String url;

            private:
                DISALLOW_COPY_AND_ASSIGN(NFCMessage);
            };

            class NFCWatchOptions {
            public:
                using DataView = NFCWatchOptionsDataView;
                using Data_ = internal::NFCWatchOptions_Data;

                static NFCWatchOptionsPtr New();

                template <typename U>
                static NFCWatchOptionsPtr From(const U& u)
                {
                    return mojo::TypeConverter<NFCWatchOptionsPtr, U>::Convert(u);
                }

                template <typename U>
                U To() const
                {
                    return mojo::TypeConverter<U, NFCWatchOptions>::Convert(*this);
                }

                NFCWatchOptions();
                ~NFCWatchOptions();

                // Clone() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Clone() or copy
                // constructor/assignment are available for members.
                template <typename StructPtrType = NFCWatchOptionsPtr>
                NFCWatchOptionsPtr Clone() const;

                // Equals() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Equals() or == operator
                // are available for members.
                template <typename T,
                    typename std::enable_if<std::is_same<
                        T, NFCWatchOptions>::value>::type* = nullptr>
                bool Equals(const T& other) const;

                template <typename UserType>
                static WTF::Vector<uint8_t> Serialize(UserType* input)
                {
                    return mojo::internal::StructSerializeImpl<
                        NFCWatchOptions::DataView, WTF::Vector<uint8_t>>(input);
                }

                template <typename UserType>
                static bool Deserialize(const WTF::Vector<uint8_t>& input,
                    UserType* output)
                {
                    return mojo::internal::StructDeserializeImpl<
                        NFCWatchOptions::DataView, WTF::Vector<uint8_t>>(
                        input, output);
                }

                WTF::String url;
                NFCRecordTypeFilterPtr record_filter;
                WTF::String media_type;
                NFCWatchMode mode;

            private:
                DISALLOW_COPY_AND_ASSIGN(NFCWatchOptions);
            };

            template <typename StructPtrType>
            NFCErrorPtr NFCError::Clone() const
            {
                // Use StructPtrType to prevent the compiler from trying to compile this
                // without being asked.
                StructPtrType rv(New());
                rv->error_type = mojo::internal::Clone(error_type);
                return rv;
            }

            template <typename T,
                typename std::enable_if<std::is_same<
                    T, NFCError>::value>::type*>
            bool NFCError::Equals(const T& other) const
            {
                if (!mojo::internal::Equals(this->error_type, other.error_type))
                    return false;
                return true;
            }
            template <typename StructPtrType>
            NFCRecordPtr NFCRecord::Clone() const
            {
                // Use StructPtrType to prevent the compiler from trying to compile this
                // without being asked.
                StructPtrType rv(New());
                rv->record_type = mojo::internal::Clone(record_type);
                rv->media_type = mojo::internal::Clone(media_type);
                rv->data = mojo::internal::Clone(data);
                return rv;
            }

            template <typename T,
                typename std::enable_if<std::is_same<
                    T, NFCRecord>::value>::type*>
            bool NFCRecord::Equals(const T& other) const
            {
                if (!mojo::internal::Equals(this->record_type, other.record_type))
                    return false;
                if (!mojo::internal::Equals(this->media_type, other.media_type))
                    return false;
                if (!mojo::internal::Equals(this->data, other.data))
                    return false;
                return true;
            }
            template <typename StructPtrType>
            NFCMessagePtr NFCMessage::Clone() const
            {
                // Use StructPtrType to prevent the compiler from trying to compile this
                // without being asked.
                StructPtrType rv(New());
                rv->data = mojo::internal::Clone(data);
                rv->url = mojo::internal::Clone(url);
                return rv;
            }

            template <typename T,
                typename std::enable_if<std::is_same<
                    T, NFCMessage>::value>::type*>
            bool NFCMessage::Equals(const T& other) const
            {
                if (!mojo::internal::Equals(this->data, other.data))
                    return false;
                if (!mojo::internal::Equals(this->url, other.url))
                    return false;
                return true;
            }
            template <typename StructPtrType>
            NFCPushOptionsPtr NFCPushOptions::Clone() const
            {
                // Use StructPtrType to prevent the compiler from trying to compile this
                // without being asked.
                StructPtrType rv(New());
                rv->target = mojo::internal::Clone(target);
                rv->timeout = mojo::internal::Clone(timeout);
                rv->ignore_read = mojo::internal::Clone(ignore_read);
                return rv;
            }

            template <typename T,
                typename std::enable_if<std::is_same<
                    T, NFCPushOptions>::value>::type*>
            bool NFCPushOptions::Equals(const T& other) const
            {
                if (!mojo::internal::Equals(this->target, other.target))
                    return false;
                if (!mojo::internal::Equals(this->timeout, other.timeout))
                    return false;
                if (!mojo::internal::Equals(this->ignore_read, other.ignore_read))
                    return false;
                return true;
            }
            template <typename StructPtrType>
            NFCRecordTypeFilterPtr NFCRecordTypeFilter::Clone() const
            {
                // Use StructPtrType to prevent the compiler from trying to compile this
                // without being asked.
                StructPtrType rv(New());
                rv->record_type = mojo::internal::Clone(record_type);
                return rv;
            }

            template <typename T,
                typename std::enable_if<std::is_same<
                    T, NFCRecordTypeFilter>::value>::type*>
            bool NFCRecordTypeFilter::Equals(const T& other) const
            {
                if (!mojo::internal::Equals(this->record_type, other.record_type))
                    return false;
                return true;
            }
            template <typename StructPtrType>
            NFCWatchOptionsPtr NFCWatchOptions::Clone() const
            {
                // Use StructPtrType to prevent the compiler from trying to compile this
                // without being asked.
                StructPtrType rv(New());
                rv->url = mojo::internal::Clone(url);
                rv->record_filter = mojo::internal::Clone(record_filter);
                rv->media_type = mojo::internal::Clone(media_type);
                rv->mode = mojo::internal::Clone(mode);
                return rv;
            }

            template <typename T,
                typename std::enable_if<std::is_same<
                    T, NFCWatchOptions>::value>::type*>
            bool NFCWatchOptions::Equals(const T& other) const
            {
                if (!mojo::internal::Equals(this->url, other.url))
                    return false;
                if (!mojo::internal::Equals(this->record_filter, other.record_filter))
                    return false;
                if (!mojo::internal::Equals(this->media_type, other.media_type))
                    return false;
                if (!mojo::internal::Equals(this->mode, other.mode))
                    return false;
                return true;
            }

        } // namespace blink
    } // namespace mojom
} // namespace nfc
} // namespace device

namespace mojo {

template <>
struct StructTraits<::device::nfc::mojom::blink::NFCError::DataView,
    ::device::nfc::mojom::blink::NFCErrorPtr> {
    static bool IsNull(const ::device::nfc::mojom::blink::NFCErrorPtr& input) { return !input; }
    static void SetToNull(::device::nfc::mojom::blink::NFCErrorPtr* output) { output->reset(); }

    static decltype(::device::nfc::mojom::blink::NFCError::error_type) error_type(
        const ::device::nfc::mojom::blink::NFCErrorPtr& input)
    {
        return input->error_type;
    }

    static bool Read(::device::nfc::mojom::blink::NFCError::DataView input, ::device::nfc::mojom::blink::NFCErrorPtr* output);
};

template <>
struct StructTraits<::device::nfc::mojom::blink::NFCRecord::DataView,
    ::device::nfc::mojom::blink::NFCRecordPtr> {
    static bool IsNull(const ::device::nfc::mojom::blink::NFCRecordPtr& input) { return !input; }
    static void SetToNull(::device::nfc::mojom::blink::NFCRecordPtr* output) { output->reset(); }

    static decltype(::device::nfc::mojom::blink::NFCRecord::record_type) record_type(
        const ::device::nfc::mojom::blink::NFCRecordPtr& input)
    {
        return input->record_type;
    }

    static const decltype(::device::nfc::mojom::blink::NFCRecord::media_type)& media_type(
        const ::device::nfc::mojom::blink::NFCRecordPtr& input)
    {
        return input->media_type;
    }

    static const decltype(::device::nfc::mojom::blink::NFCRecord::data)& data(
        const ::device::nfc::mojom::blink::NFCRecordPtr& input)
    {
        return input->data;
    }

    static bool Read(::device::nfc::mojom::blink::NFCRecord::DataView input, ::device::nfc::mojom::blink::NFCRecordPtr* output);
};

template <>
struct StructTraits<::device::nfc::mojom::blink::NFCMessage::DataView,
    ::device::nfc::mojom::blink::NFCMessagePtr> {
    static bool IsNull(const ::device::nfc::mojom::blink::NFCMessagePtr& input) { return !input; }
    static void SetToNull(::device::nfc::mojom::blink::NFCMessagePtr* output) { output->reset(); }

    static const decltype(::device::nfc::mojom::blink::NFCMessage::data)& data(
        const ::device::nfc::mojom::blink::NFCMessagePtr& input)
    {
        return input->data;
    }

    static const decltype(::device::nfc::mojom::blink::NFCMessage::url)& url(
        const ::device::nfc::mojom::blink::NFCMessagePtr& input)
    {
        return input->url;
    }

    static bool Read(::device::nfc::mojom::blink::NFCMessage::DataView input, ::device::nfc::mojom::blink::NFCMessagePtr* output);
};

template <>
struct StructTraits<::device::nfc::mojom::blink::NFCPushOptions::DataView,
    ::device::nfc::mojom::blink::NFCPushOptionsPtr> {
    static bool IsNull(const ::device::nfc::mojom::blink::NFCPushOptionsPtr& input) { return !input; }
    static void SetToNull(::device::nfc::mojom::blink::NFCPushOptionsPtr* output) { output->reset(); }

    static decltype(::device::nfc::mojom::blink::NFCPushOptions::target) target(
        const ::device::nfc::mojom::blink::NFCPushOptionsPtr& input)
    {
        return input->target;
    }

    static decltype(::device::nfc::mojom::blink::NFCPushOptions::timeout) timeout(
        const ::device::nfc::mojom::blink::NFCPushOptionsPtr& input)
    {
        return input->timeout;
    }

    static decltype(::device::nfc::mojom::blink::NFCPushOptions::ignore_read) ignore_read(
        const ::device::nfc::mojom::blink::NFCPushOptionsPtr& input)
    {
        return input->ignore_read;
    }

    static bool Read(::device::nfc::mojom::blink::NFCPushOptions::DataView input, ::device::nfc::mojom::blink::NFCPushOptionsPtr* output);
};

template <>
struct StructTraits<::device::nfc::mojom::blink::NFCRecordTypeFilter::DataView,
    ::device::nfc::mojom::blink::NFCRecordTypeFilterPtr> {
    static bool IsNull(const ::device::nfc::mojom::blink::NFCRecordTypeFilterPtr& input) { return !input; }
    static void SetToNull(::device::nfc::mojom::blink::NFCRecordTypeFilterPtr* output) { output->reset(); }

    static decltype(::device::nfc::mojom::blink::NFCRecordTypeFilter::record_type) record_type(
        const ::device::nfc::mojom::blink::NFCRecordTypeFilterPtr& input)
    {
        return input->record_type;
    }

    static bool Read(::device::nfc::mojom::blink::NFCRecordTypeFilter::DataView input, ::device::nfc::mojom::blink::NFCRecordTypeFilterPtr* output);
};

template <>
struct StructTraits<::device::nfc::mojom::blink::NFCWatchOptions::DataView,
    ::device::nfc::mojom::blink::NFCWatchOptionsPtr> {
    static bool IsNull(const ::device::nfc::mojom::blink::NFCWatchOptionsPtr& input) { return !input; }
    static void SetToNull(::device::nfc::mojom::blink::NFCWatchOptionsPtr* output) { output->reset(); }

    static const decltype(::device::nfc::mojom::blink::NFCWatchOptions::url)& url(
        const ::device::nfc::mojom::blink::NFCWatchOptionsPtr& input)
    {
        return input->url;
    }

    static const decltype(::device::nfc::mojom::blink::NFCWatchOptions::record_filter)& record_filter(
        const ::device::nfc::mojom::blink::NFCWatchOptionsPtr& input)
    {
        return input->record_filter;
    }

    static const decltype(::device::nfc::mojom::blink::NFCWatchOptions::media_type)& media_type(
        const ::device::nfc::mojom::blink::NFCWatchOptionsPtr& input)
    {
        return input->media_type;
    }

    static decltype(::device::nfc::mojom::blink::NFCWatchOptions::mode) mode(
        const ::device::nfc::mojom::blink::NFCWatchOptionsPtr& input)
    {
        return input->mode;
    }

    static bool Read(::device::nfc::mojom::blink::NFCWatchOptions::DataView input, ::device::nfc::mojom::blink::NFCWatchOptionsPtr* output);
};

} // namespace mojo

#endif // DEVICE_NFC_NFC_MOJOM_BLINK_H_