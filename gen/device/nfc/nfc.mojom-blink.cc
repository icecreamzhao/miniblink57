// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4056)
#pragma warning(disable : 4065)
#pragma warning(disable : 4756)
#endif

#include "device/nfc/nfc.mojom-blink.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
namespace device {
namespace nfc {
    namespace mojom {
        namespace blink { // static
            NFCErrorPtr NFCError::New()
            {
                NFCErrorPtr rv;
                mojo::internal::StructHelper<NFCError>::Initialize(&rv);
                return rv;
            }

            NFCError::NFCError()
                : error_type()
            {
            }

            NFCError::~NFCError()
            {
            }
            size_t NFCError::Hash(size_t seed) const
            {
                seed = mojo::internal::WTFHash(seed, this->error_type);
                return seed;
            } // static
            NFCRecordPtr NFCRecord::New()
            {
                NFCRecordPtr rv;
                mojo::internal::StructHelper<NFCRecord>::Initialize(&rv);
                return rv;
            }

            NFCRecord::NFCRecord()
                : record_type()
                , media_type()
                , data()
            {
            }

            NFCRecord::~NFCRecord()
            {
            } // static
            NFCMessagePtr NFCMessage::New()
            {
                NFCMessagePtr rv;
                mojo::internal::StructHelper<NFCMessage>::Initialize(&rv);
                return rv;
            }

            NFCMessage::NFCMessage()
                : data()
                , url()
            {
            }

            NFCMessage::~NFCMessage()
            {
            } // static
            NFCPushOptionsPtr NFCPushOptions::New()
            {
                NFCPushOptionsPtr rv;
                mojo::internal::StructHelper<NFCPushOptions>::Initialize(&rv);
                return rv;
            }

            NFCPushOptions::NFCPushOptions()
                : target()
                , timeout()
                , ignore_read()
            {
            }

            NFCPushOptions::~NFCPushOptions()
            {
            }
            size_t NFCPushOptions::Hash(size_t seed) const
            {
                seed = mojo::internal::WTFHash(seed, this->target);
                seed = mojo::internal::WTFHash(seed, this->timeout);
                seed = mojo::internal::WTFHash(seed, this->ignore_read);
                return seed;
            } // static
            NFCRecordTypeFilterPtr NFCRecordTypeFilter::New()
            {
                NFCRecordTypeFilterPtr rv;
                mojo::internal::StructHelper<NFCRecordTypeFilter>::Initialize(&rv);
                return rv;
            }

            NFCRecordTypeFilter::NFCRecordTypeFilter()
                : record_type()
            {
            }

            NFCRecordTypeFilter::~NFCRecordTypeFilter()
            {
            }
            size_t NFCRecordTypeFilter::Hash(size_t seed) const
            {
                seed = mojo::internal::WTFHash(seed, this->record_type);
                return seed;
            } // static
            NFCWatchOptionsPtr NFCWatchOptions::New()
            {
                NFCWatchOptionsPtr rv;
                mojo::internal::StructHelper<NFCWatchOptions>::Initialize(&rv);
                return rv;
            }

            NFCWatchOptions::NFCWatchOptions()
                : url()
                , record_filter()
                , media_type()
                , mode()
            {
            }

            NFCWatchOptions::~NFCWatchOptions()
            {
            }
            const char NFC::Name_[] = "device::nfc::mojom::NFC";

            class NFC_Push_ForwardToCallback
                : public mojo::MessageReceiver {
            public:
                NFC_Push_ForwardToCallback(
                    const NFC::PushCallback& callback,
                    scoped_refptr<mojo::AssociatedGroupController> group_controller)
                    : callback_(std::move(callback))
                    , serialization_context_(std::move(group_controller))
                {
                }
                bool Accept(mojo::Message* message) override;

            private:
                NFC::PushCallback callback_;
                mojo::internal::SerializationContext serialization_context_;
                DISALLOW_COPY_AND_ASSIGN(NFC_Push_ForwardToCallback);
            };
            bool NFC_Push_ForwardToCallback::Accept(
                mojo::Message* message)
            {
                internal::NFC_Push_ResponseParams_Data* params = reinterpret_cast<internal::NFC_Push_ResponseParams_Data*>(
                    message->mutable_payload());

                (&serialization_context_)->handles.Swap((message)->mutable_handles());
                bool success = true;
                NFCErrorPtr p_error {};
                NFC_Push_ResponseParamsDataView input_data_view(params,
                    &serialization_context_);

                if (!input_data_view.ReadError(&p_error))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "NFC::Push response deserializer");
                    return false;
                }
                if (!callback_.is_null()) {
                    mojo::internal::MessageDispatchContext context(message);
                    std::move(callback_).Run(
                        std::move(p_error));
                }
                return true;
            }

            class NFC_CancelPush_ForwardToCallback
                : public mojo::MessageReceiver {
            public:
                NFC_CancelPush_ForwardToCallback(
                    const NFC::CancelPushCallback& callback,
                    scoped_refptr<mojo::AssociatedGroupController> group_controller)
                    : callback_(std::move(callback))
                    , serialization_context_(std::move(group_controller))
                {
                }
                bool Accept(mojo::Message* message) override;

            private:
                NFC::CancelPushCallback callback_;
                mojo::internal::SerializationContext serialization_context_;
                DISALLOW_COPY_AND_ASSIGN(NFC_CancelPush_ForwardToCallback);
            };
            bool NFC_CancelPush_ForwardToCallback::Accept(
                mojo::Message* message)
            {
                internal::NFC_CancelPush_ResponseParams_Data* params = reinterpret_cast<internal::NFC_CancelPush_ResponseParams_Data*>(
                    message->mutable_payload());

                (&serialization_context_)->handles.Swap((message)->mutable_handles());
                bool success = true;
                NFCErrorPtr p_error {};
                NFC_CancelPush_ResponseParamsDataView input_data_view(params,
                    &serialization_context_);

                if (!input_data_view.ReadError(&p_error))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "NFC::CancelPush response deserializer");
                    return false;
                }
                if (!callback_.is_null()) {
                    mojo::internal::MessageDispatchContext context(message);
                    std::move(callback_).Run(
                        std::move(p_error));
                }
                return true;
            }

            class NFC_Watch_ForwardToCallback
                : public mojo::MessageReceiver {
            public:
                NFC_Watch_ForwardToCallback(
                    const NFC::WatchCallback& callback,
                    scoped_refptr<mojo::AssociatedGroupController> group_controller)
                    : callback_(std::move(callback))
                    , serialization_context_(std::move(group_controller))
                {
                }
                bool Accept(mojo::Message* message) override;

            private:
                NFC::WatchCallback callback_;
                mojo::internal::SerializationContext serialization_context_;
                DISALLOW_COPY_AND_ASSIGN(NFC_Watch_ForwardToCallback);
            };
            bool NFC_Watch_ForwardToCallback::Accept(
                mojo::Message* message)
            {
                internal::NFC_Watch_ResponseParams_Data* params = reinterpret_cast<internal::NFC_Watch_ResponseParams_Data*>(
                    message->mutable_payload());

                (&serialization_context_)->handles.Swap((message)->mutable_handles());
                bool success = true;
                uint32_t p_id {};
                NFCErrorPtr p_error {};
                NFC_Watch_ResponseParamsDataView input_data_view(params,
                    &serialization_context_);

                p_id = input_data_view.id();
                if (!input_data_view.ReadError(&p_error))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "NFC::Watch response deserializer");
                    return false;
                }
                if (!callback_.is_null()) {
                    mojo::internal::MessageDispatchContext context(message);
                    std::move(callback_).Run(
                        std::move(p_id),
                        std::move(p_error));
                }
                return true;
            }

            class NFC_CancelWatch_ForwardToCallback
                : public mojo::MessageReceiver {
            public:
                NFC_CancelWatch_ForwardToCallback(
                    const NFC::CancelWatchCallback& callback,
                    scoped_refptr<mojo::AssociatedGroupController> group_controller)
                    : callback_(std::move(callback))
                    , serialization_context_(std::move(group_controller))
                {
                }
                bool Accept(mojo::Message* message) override;

            private:
                NFC::CancelWatchCallback callback_;
                mojo::internal::SerializationContext serialization_context_;
                DISALLOW_COPY_AND_ASSIGN(NFC_CancelWatch_ForwardToCallback);
            };
            bool NFC_CancelWatch_ForwardToCallback::Accept(
                mojo::Message* message)
            {
                internal::NFC_CancelWatch_ResponseParams_Data* params = reinterpret_cast<internal::NFC_CancelWatch_ResponseParams_Data*>(
                    message->mutable_payload());

                (&serialization_context_)->handles.Swap((message)->mutable_handles());
                bool success = true;
                NFCErrorPtr p_error {};
                NFC_CancelWatch_ResponseParamsDataView input_data_view(params,
                    &serialization_context_);

                if (!input_data_view.ReadError(&p_error))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "NFC::CancelWatch response deserializer");
                    return false;
                }
                if (!callback_.is_null()) {
                    mojo::internal::MessageDispatchContext context(message);
                    std::move(callback_).Run(
                        std::move(p_error));
                }
                return true;
            }

            class NFC_CancelAllWatches_ForwardToCallback
                : public mojo::MessageReceiver {
            public:
                NFC_CancelAllWatches_ForwardToCallback(
                    const NFC::CancelAllWatchesCallback& callback,
                    scoped_refptr<mojo::AssociatedGroupController> group_controller)
                    : callback_(std::move(callback))
                    , serialization_context_(std::move(group_controller))
                {
                }
                bool Accept(mojo::Message* message) override;

            private:
                NFC::CancelAllWatchesCallback callback_;
                mojo::internal::SerializationContext serialization_context_;
                DISALLOW_COPY_AND_ASSIGN(NFC_CancelAllWatches_ForwardToCallback);
            };
            bool NFC_CancelAllWatches_ForwardToCallback::Accept(
                mojo::Message* message)
            {
                internal::NFC_CancelAllWatches_ResponseParams_Data* params = reinterpret_cast<internal::NFC_CancelAllWatches_ResponseParams_Data*>(
                    message->mutable_payload());

                (&serialization_context_)->handles.Swap((message)->mutable_handles());
                bool success = true;
                NFCErrorPtr p_error {};
                NFC_CancelAllWatches_ResponseParamsDataView input_data_view(params,
                    &serialization_context_);

                if (!input_data_view.ReadError(&p_error))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "NFC::CancelAllWatches response deserializer");
                    return false;
                }
                if (!callback_.is_null()) {
                    mojo::internal::MessageDispatchContext context(message);
                    std::move(callback_).Run(
                        std::move(p_error));
                }
                return true;
            }

            NFCProxy::NFCProxy(mojo::MessageReceiverWithResponder* receiver)
                : receiver_(receiver)
            {
            }

            void NFCProxy::SetClient(
                NFCClientPtr in_client)
            {
                mojo::internal::SerializationContext serialization_context(
                    group_controller_);
                size_t size = sizeof(::device::nfc::mojom::internal::NFC_SetClient_Params_Data);
                mojo::internal::MessageBuilder builder(internal::kNFC_SetClient_Name, size);

                auto params = ::device::nfc::mojom::internal::NFC_SetClient_Params_Data::New(builder.buffer());
                ALLOW_UNUSED_LOCAL(params);
                mojo::internal::Serialize<::device::nfc::mojom::NFCClientPtrDataView>(
                    in_client, &params->client, &serialization_context);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !mojo::internal::IsHandleOrInterfaceValid(params->client),
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                    "invalid client in NFC.SetClient request");
                (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
                bool ok = receiver_->Accept(builder.message());
                // This return value may be ignored as !ok implies the Connector has
                // encountered an error, which will be visible through other means.
                ALLOW_UNUSED_LOCAL(ok);
            }

            void NFCProxy::Push(
                NFCMessagePtr in_message, NFCPushOptionsPtr in_options, const PushCallback& callback)
            {
                mojo::internal::SerializationContext serialization_context(
                    group_controller_);
                size_t size = sizeof(::device::nfc::mojom::internal::NFC_Push_Params_Data);
                size += mojo::internal::PrepareToSerialize<::device::nfc::mojom::NFCMessageDataView>(
                    in_message, &serialization_context);
                size += mojo::internal::PrepareToSerialize<::device::nfc::mojom::NFCPushOptionsDataView>(
                    in_options, &serialization_context);
                mojo::internal::RequestMessageBuilder builder(internal::kNFC_Push_Name, size);

                auto params = ::device::nfc::mojom::internal::NFC_Push_Params_Data::New(builder.buffer());
                ALLOW_UNUSED_LOCAL(params);
                typename decltype(params->message)::BaseType* message_ptr;
                mojo::internal::Serialize<::device::nfc::mojom::NFCMessageDataView>(
                    in_message, builder.buffer(), &message_ptr, &serialization_context);
                params->message.Set(message_ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    params->message.is_null(),
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null message in NFC.Push request");
                typename decltype(params->options)::BaseType* options_ptr;
                mojo::internal::Serialize<::device::nfc::mojom::NFCPushOptionsDataView>(
                    in_options, builder.buffer(), &options_ptr, &serialization_context);
                params->options.Set(options_ptr);
                (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
                mojo::MessageReceiver* responder = new NFC_Push_ForwardToCallback(
                    std::move(callback), group_controller_);
                if (!receiver_->AcceptWithResponder(builder.message(), responder))
                    delete responder;
            }

            void NFCProxy::CancelPush(
                NFCPushTarget in_target, const CancelPushCallback& callback)
            {
                mojo::internal::SerializationContext serialization_context(
                    group_controller_);
                size_t size = sizeof(::device::nfc::mojom::internal::NFC_CancelPush_Params_Data);
                mojo::internal::RequestMessageBuilder builder(internal::kNFC_CancelPush_Name, size);

                auto params = ::device::nfc::mojom::internal::NFC_CancelPush_Params_Data::New(builder.buffer());
                ALLOW_UNUSED_LOCAL(params);
                mojo::internal::Serialize<::device::nfc::mojom::NFCPushTarget>(
                    in_target, &params->target);
                (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
                mojo::MessageReceiver* responder = new NFC_CancelPush_ForwardToCallback(
                    std::move(callback), group_controller_);
                if (!receiver_->AcceptWithResponder(builder.message(), responder))
                    delete responder;
            }

            void NFCProxy::Watch(
                NFCWatchOptionsPtr in_options, const WatchCallback& callback)
            {
                mojo::internal::SerializationContext serialization_context(
                    group_controller_);
                size_t size = sizeof(::device::nfc::mojom::internal::NFC_Watch_Params_Data);
                size += mojo::internal::PrepareToSerialize<::device::nfc::mojom::NFCWatchOptionsDataView>(
                    in_options, &serialization_context);
                mojo::internal::RequestMessageBuilder builder(internal::kNFC_Watch_Name, size);

                auto params = ::device::nfc::mojom::internal::NFC_Watch_Params_Data::New(builder.buffer());
                ALLOW_UNUSED_LOCAL(params);
                typename decltype(params->options)::BaseType* options_ptr;
                mojo::internal::Serialize<::device::nfc::mojom::NFCWatchOptionsDataView>(
                    in_options, builder.buffer(), &options_ptr, &serialization_context);
                params->options.Set(options_ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    params->options.is_null(),
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null options in NFC.Watch request");
                (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
                mojo::MessageReceiver* responder = new NFC_Watch_ForwardToCallback(
                    std::move(callback), group_controller_);
                if (!receiver_->AcceptWithResponder(builder.message(), responder))
                    delete responder;
            }

            void NFCProxy::CancelWatch(
                uint32_t in_id, const CancelWatchCallback& callback)
            {
                mojo::internal::SerializationContext serialization_context(
                    group_controller_);
                size_t size = sizeof(::device::nfc::mojom::internal::NFC_CancelWatch_Params_Data);
                mojo::internal::RequestMessageBuilder builder(internal::kNFC_CancelWatch_Name, size);

                auto params = ::device::nfc::mojom::internal::NFC_CancelWatch_Params_Data::New(builder.buffer());
                ALLOW_UNUSED_LOCAL(params);
                params->id = in_id;
                (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
                mojo::MessageReceiver* responder = new NFC_CancelWatch_ForwardToCallback(
                    std::move(callback), group_controller_);
                if (!receiver_->AcceptWithResponder(builder.message(), responder))
                    delete responder;
            }

            void NFCProxy::CancelAllWatches(
                const CancelAllWatchesCallback& callback)
            {
                mojo::internal::SerializationContext serialization_context(
                    group_controller_);
                size_t size = sizeof(::device::nfc::mojom::internal::NFC_CancelAllWatches_Params_Data);
                mojo::internal::RequestMessageBuilder builder(internal::kNFC_CancelAllWatches_Name, size);

                auto params = ::device::nfc::mojom::internal::NFC_CancelAllWatches_Params_Data::New(builder.buffer());
                ALLOW_UNUSED_LOCAL(params);
                (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
                mojo::MessageReceiver* responder = new NFC_CancelAllWatches_ForwardToCallback(
                    std::move(callback), group_controller_);
                if (!receiver_->AcceptWithResponder(builder.message(), responder))
                    delete responder;
            }

            void NFCProxy::SuspendNFCOperations()
            {
                mojo::internal::SerializationContext serialization_context(
                    group_controller_);
                size_t size = sizeof(::device::nfc::mojom::internal::NFC_SuspendNFCOperations_Params_Data);
                mojo::internal::MessageBuilder builder(internal::kNFC_SuspendNFCOperations_Name, size);

                auto params = ::device::nfc::mojom::internal::NFC_SuspendNFCOperations_Params_Data::New(builder.buffer());
                ALLOW_UNUSED_LOCAL(params);
                (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
                bool ok = receiver_->Accept(builder.message());
                // This return value may be ignored as !ok implies the Connector has
                // encountered an error, which will be visible through other means.
                ALLOW_UNUSED_LOCAL(ok);
            }

            void NFCProxy::ResumeNFCOperations()
            {
                mojo::internal::SerializationContext serialization_context(
                    group_controller_);
                size_t size = sizeof(::device::nfc::mojom::internal::NFC_ResumeNFCOperations_Params_Data);
                mojo::internal::MessageBuilder builder(internal::kNFC_ResumeNFCOperations_Name, size);

                auto params = ::device::nfc::mojom::internal::NFC_ResumeNFCOperations_Params_Data::New(builder.buffer());
                ALLOW_UNUSED_LOCAL(params);
                (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
                bool ok = receiver_->Accept(builder.message());
                // This return value may be ignored as !ok implies the Connector has
                // encountered an error, which will be visible through other means.
                ALLOW_UNUSED_LOCAL(ok);
            }
            class NFC_Push_ProxyToResponder {
            public:
                static NFC::PushCallback CreateCallback(
                    uint64_t request_id,
                    bool is_sync,
                    mojo::MessageReceiverWithStatus* responder,
                    scoped_refptr<mojo::AssociatedGroupController>
                        group_controller)
                {
                    std::unique_ptr<NFC_Push_ProxyToResponder> proxy(
                        new NFC_Push_ProxyToResponder(
                            request_id, is_sync, responder, group_controller));
                    return base::Bind(&NFC_Push_ProxyToResponder::Run,
                        base::Passed(&proxy));
                }

                ~NFC_Push_ProxyToResponder()
                {
#if DCHECK_IS_ON()
                    if (responder_) {
                        // Is the Service destroying the callback without running it
                        // and without first closing the pipe?
                        responder_->DCheckInvalid("The callback passed to "
                                                  "NFC::Push() was never run.");
                    }
#endif
                    // If the Callback was dropped then deleting the responder will close
                    // the pipe so the calling application knows to stop waiting for a reply.
                    delete responder_;
                }

            private:
                NFC_Push_ProxyToResponder(
                    uint64_t request_id,
                    bool is_sync,
                    mojo::MessageReceiverWithStatus* responder,
                    scoped_refptr<mojo::AssociatedGroupController> group_controller)
                    : request_id_(request_id)
                    , is_sync_(is_sync)
                    , responder_(responder)
                    , serialization_context_(std::move(group_controller))
                {
                }

                void Run(
                    NFCErrorPtr in_error);

                uint64_t request_id_;
                bool is_sync_;
                mojo::MessageReceiverWithStatus* responder_;
                // TODO(yzshen): maybe I should use a ref to the original one?
                mojo::internal::SerializationContext serialization_context_;

                DISALLOW_COPY_AND_ASSIGN(NFC_Push_ProxyToResponder);
            };

            void NFC_Push_ProxyToResponder::Run(
                NFCErrorPtr in_error)
            {
                size_t size = sizeof(::device::nfc::mojom::internal::NFC_Push_ResponseParams_Data);
                size += mojo::internal::PrepareToSerialize<::device::nfc::mojom::NFCErrorDataView>(
                    in_error, &serialization_context_);
                mojo::internal::ResponseMessageBuilder builder(
                    internal::kNFC_Push_Name, size, request_id_,
                    is_sync_ ? mojo::Message::kFlagIsSync : 0);
                auto params = ::device::nfc::mojom::internal::NFC_Push_ResponseParams_Data::New(builder.buffer());
                ALLOW_UNUSED_LOCAL(params);
                typename decltype(params->error)::BaseType* error_ptr;
                mojo::internal::Serialize<::device::nfc::mojom::NFCErrorDataView>(
                    in_error, builder.buffer(), &error_ptr, &serialization_context_);
                params->error.Set(error_ptr);
                (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
                bool ok = responder_->Accept(builder.message());
                ALLOW_UNUSED_LOCAL(ok);
                // TODO(darin): !ok returned here indicates a malformed message, and that may
                // be good reason to close the connection. However, we don't have a way to do
                // that from here. We should add a way.
                delete responder_;
                responder_ = nullptr;
            }
            class NFC_CancelPush_ProxyToResponder {
            public:
                static NFC::CancelPushCallback CreateCallback(
                    uint64_t request_id,
                    bool is_sync,
                    mojo::MessageReceiverWithStatus* responder,
                    scoped_refptr<mojo::AssociatedGroupController>
                        group_controller)
                {
                    std::unique_ptr<NFC_CancelPush_ProxyToResponder> proxy(
                        new NFC_CancelPush_ProxyToResponder(
                            request_id, is_sync, responder, group_controller));
                    return base::Bind(&NFC_CancelPush_ProxyToResponder::Run,
                        base::Passed(&proxy));
                }

                ~NFC_CancelPush_ProxyToResponder()
                {
#if DCHECK_IS_ON()
                    if (responder_) {
                        // Is the Service destroying the callback without running it
                        // and without first closing the pipe?
                        responder_->DCheckInvalid("The callback passed to "
                                                  "NFC::CancelPush() was never run.");
                    }
#endif
                    // If the Callback was dropped then deleting the responder will close
                    // the pipe so the calling application knows to stop waiting for a reply.
                    delete responder_;
                }

            private:
                NFC_CancelPush_ProxyToResponder(
                    uint64_t request_id,
                    bool is_sync,
                    mojo::MessageReceiverWithStatus* responder,
                    scoped_refptr<mojo::AssociatedGroupController> group_controller)
                    : request_id_(request_id)
                    , is_sync_(is_sync)
                    , responder_(responder)
                    , serialization_context_(std::move(group_controller))
                {
                }

                void Run(
                    NFCErrorPtr in_error);

                uint64_t request_id_;
                bool is_sync_;
                mojo::MessageReceiverWithStatus* responder_;
                // TODO(yzshen): maybe I should use a ref to the original one?
                mojo::internal::SerializationContext serialization_context_;

                DISALLOW_COPY_AND_ASSIGN(NFC_CancelPush_ProxyToResponder);
            };

            void NFC_CancelPush_ProxyToResponder::Run(
                NFCErrorPtr in_error)
            {
                size_t size = sizeof(::device::nfc::mojom::internal::NFC_CancelPush_ResponseParams_Data);
                size += mojo::internal::PrepareToSerialize<::device::nfc::mojom::NFCErrorDataView>(
                    in_error, &serialization_context_);
                mojo::internal::ResponseMessageBuilder builder(
                    internal::kNFC_CancelPush_Name, size, request_id_,
                    is_sync_ ? mojo::Message::kFlagIsSync : 0);
                auto params = ::device::nfc::mojom::internal::NFC_CancelPush_ResponseParams_Data::New(builder.buffer());
                ALLOW_UNUSED_LOCAL(params);
                typename decltype(params->error)::BaseType* error_ptr;
                mojo::internal::Serialize<::device::nfc::mojom::NFCErrorDataView>(
                    in_error, builder.buffer(), &error_ptr, &serialization_context_);
                params->error.Set(error_ptr);
                (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
                bool ok = responder_->Accept(builder.message());
                ALLOW_UNUSED_LOCAL(ok);
                // TODO(darin): !ok returned here indicates a malformed message, and that may
                // be good reason to close the connection. However, we don't have a way to do
                // that from here. We should add a way.
                delete responder_;
                responder_ = nullptr;
            }
            class NFC_Watch_ProxyToResponder {
            public:
                static NFC::WatchCallback CreateCallback(
                    uint64_t request_id,
                    bool is_sync,
                    mojo::MessageReceiverWithStatus* responder,
                    scoped_refptr<mojo::AssociatedGroupController>
                        group_controller)
                {
                    std::unique_ptr<NFC_Watch_ProxyToResponder> proxy(
                        new NFC_Watch_ProxyToResponder(
                            request_id, is_sync, responder, group_controller));
                    return base::Bind(&NFC_Watch_ProxyToResponder::Run,
                        base::Passed(&proxy));
                }

                ~NFC_Watch_ProxyToResponder()
                {
#if DCHECK_IS_ON()
                    if (responder_) {
                        // Is the Service destroying the callback without running it
                        // and without first closing the pipe?
                        responder_->DCheckInvalid("The callback passed to "
                                                  "NFC::Watch() was never run.");
                    }
#endif
                    // If the Callback was dropped then deleting the responder will close
                    // the pipe so the calling application knows to stop waiting for a reply.
                    delete responder_;
                }

            private:
                NFC_Watch_ProxyToResponder(
                    uint64_t request_id,
                    bool is_sync,
                    mojo::MessageReceiverWithStatus* responder,
                    scoped_refptr<mojo::AssociatedGroupController> group_controller)
                    : request_id_(request_id)
                    , is_sync_(is_sync)
                    , responder_(responder)
                    , serialization_context_(std::move(group_controller))
                {
                }

                void Run(
                    uint32_t in_id, NFCErrorPtr in_error);

                uint64_t request_id_;
                bool is_sync_;
                mojo::MessageReceiverWithStatus* responder_;
                // TODO(yzshen): maybe I should use a ref to the original one?
                mojo::internal::SerializationContext serialization_context_;

                DISALLOW_COPY_AND_ASSIGN(NFC_Watch_ProxyToResponder);
            };

            void NFC_Watch_ProxyToResponder::Run(
                uint32_t in_id, NFCErrorPtr in_error)
            {
                size_t size = sizeof(::device::nfc::mojom::internal::NFC_Watch_ResponseParams_Data);
                size += mojo::internal::PrepareToSerialize<::device::nfc::mojom::NFCErrorDataView>(
                    in_error, &serialization_context_);
                mojo::internal::ResponseMessageBuilder builder(
                    internal::kNFC_Watch_Name, size, request_id_,
                    is_sync_ ? mojo::Message::kFlagIsSync : 0);
                auto params = ::device::nfc::mojom::internal::NFC_Watch_ResponseParams_Data::New(builder.buffer());
                ALLOW_UNUSED_LOCAL(params);
                params->id = in_id;
                typename decltype(params->error)::BaseType* error_ptr;
                mojo::internal::Serialize<::device::nfc::mojom::NFCErrorDataView>(
                    in_error, builder.buffer(), &error_ptr, &serialization_context_);
                params->error.Set(error_ptr);
                (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
                bool ok = responder_->Accept(builder.message());
                ALLOW_UNUSED_LOCAL(ok);
                // TODO(darin): !ok returned here indicates a malformed message, and that may
                // be good reason to close the connection. However, we don't have a way to do
                // that from here. We should add a way.
                delete responder_;
                responder_ = nullptr;
            }
            class NFC_CancelWatch_ProxyToResponder {
            public:
                static NFC::CancelWatchCallback CreateCallback(
                    uint64_t request_id,
                    bool is_sync,
                    mojo::MessageReceiverWithStatus* responder,
                    scoped_refptr<mojo::AssociatedGroupController>
                        group_controller)
                {
                    std::unique_ptr<NFC_CancelWatch_ProxyToResponder> proxy(
                        new NFC_CancelWatch_ProxyToResponder(
                            request_id, is_sync, responder, group_controller));
                    return base::Bind(&NFC_CancelWatch_ProxyToResponder::Run,
                        base::Passed(&proxy));
                }

                ~NFC_CancelWatch_ProxyToResponder()
                {
#if DCHECK_IS_ON()
                    if (responder_) {
                        // Is the Service destroying the callback without running it
                        // and without first closing the pipe?
                        responder_->DCheckInvalid("The callback passed to "
                                                  "NFC::CancelWatch() was never run.");
                    }
#endif
                    // If the Callback was dropped then deleting the responder will close
                    // the pipe so the calling application knows to stop waiting for a reply.
                    delete responder_;
                }

            private:
                NFC_CancelWatch_ProxyToResponder(
                    uint64_t request_id,
                    bool is_sync,
                    mojo::MessageReceiverWithStatus* responder,
                    scoped_refptr<mojo::AssociatedGroupController> group_controller)
                    : request_id_(request_id)
                    , is_sync_(is_sync)
                    , responder_(responder)
                    , serialization_context_(std::move(group_controller))
                {
                }

                void Run(
                    NFCErrorPtr in_error);

                uint64_t request_id_;
                bool is_sync_;
                mojo::MessageReceiverWithStatus* responder_;
                // TODO(yzshen): maybe I should use a ref to the original one?
                mojo::internal::SerializationContext serialization_context_;

                DISALLOW_COPY_AND_ASSIGN(NFC_CancelWatch_ProxyToResponder);
            };

            void NFC_CancelWatch_ProxyToResponder::Run(
                NFCErrorPtr in_error)
            {
                size_t size = sizeof(::device::nfc::mojom::internal::NFC_CancelWatch_ResponseParams_Data);
                size += mojo::internal::PrepareToSerialize<::device::nfc::mojom::NFCErrorDataView>(
                    in_error, &serialization_context_);
                mojo::internal::ResponseMessageBuilder builder(
                    internal::kNFC_CancelWatch_Name, size, request_id_,
                    is_sync_ ? mojo::Message::kFlagIsSync : 0);
                auto params = ::device::nfc::mojom::internal::NFC_CancelWatch_ResponseParams_Data::New(builder.buffer());
                ALLOW_UNUSED_LOCAL(params);
                typename decltype(params->error)::BaseType* error_ptr;
                mojo::internal::Serialize<::device::nfc::mojom::NFCErrorDataView>(
                    in_error, builder.buffer(), &error_ptr, &serialization_context_);
                params->error.Set(error_ptr);
                (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
                bool ok = responder_->Accept(builder.message());
                ALLOW_UNUSED_LOCAL(ok);
                // TODO(darin): !ok returned here indicates a malformed message, and that may
                // be good reason to close the connection. However, we don't have a way to do
                // that from here. We should add a way.
                delete responder_;
                responder_ = nullptr;
            }
            class NFC_CancelAllWatches_ProxyToResponder {
            public:
                static NFC::CancelAllWatchesCallback CreateCallback(
                    uint64_t request_id,
                    bool is_sync,
                    mojo::MessageReceiverWithStatus* responder,
                    scoped_refptr<mojo::AssociatedGroupController>
                        group_controller)
                {
                    std::unique_ptr<NFC_CancelAllWatches_ProxyToResponder> proxy(
                        new NFC_CancelAllWatches_ProxyToResponder(
                            request_id, is_sync, responder, group_controller));
                    return base::Bind(&NFC_CancelAllWatches_ProxyToResponder::Run,
                        base::Passed(&proxy));
                }

                ~NFC_CancelAllWatches_ProxyToResponder()
                {
#if DCHECK_IS_ON()
                    if (responder_) {
                        // Is the Service destroying the callback without running it
                        // and without first closing the pipe?
                        responder_->DCheckInvalid("The callback passed to "
                                                  "NFC::CancelAllWatches() was never run.");
                    }
#endif
                    // If the Callback was dropped then deleting the responder will close
                    // the pipe so the calling application knows to stop waiting for a reply.
                    delete responder_;
                }

            private:
                NFC_CancelAllWatches_ProxyToResponder(
                    uint64_t request_id,
                    bool is_sync,
                    mojo::MessageReceiverWithStatus* responder,
                    scoped_refptr<mojo::AssociatedGroupController> group_controller)
                    : request_id_(request_id)
                    , is_sync_(is_sync)
                    , responder_(responder)
                    , serialization_context_(std::move(group_controller))
                {
                }

                void Run(
                    NFCErrorPtr in_error);

                uint64_t request_id_;
                bool is_sync_;
                mojo::MessageReceiverWithStatus* responder_;
                // TODO(yzshen): maybe I should use a ref to the original one?
                mojo::internal::SerializationContext serialization_context_;

                DISALLOW_COPY_AND_ASSIGN(NFC_CancelAllWatches_ProxyToResponder);
            };

            void NFC_CancelAllWatches_ProxyToResponder::Run(
                NFCErrorPtr in_error)
            {
                size_t size = sizeof(::device::nfc::mojom::internal::NFC_CancelAllWatches_ResponseParams_Data);
                size += mojo::internal::PrepareToSerialize<::device::nfc::mojom::NFCErrorDataView>(
                    in_error, &serialization_context_);
                mojo::internal::ResponseMessageBuilder builder(
                    internal::kNFC_CancelAllWatches_Name, size, request_id_,
                    is_sync_ ? mojo::Message::kFlagIsSync : 0);
                auto params = ::device::nfc::mojom::internal::NFC_CancelAllWatches_ResponseParams_Data::New(builder.buffer());
                ALLOW_UNUSED_LOCAL(params);
                typename decltype(params->error)::BaseType* error_ptr;
                mojo::internal::Serialize<::device::nfc::mojom::NFCErrorDataView>(
                    in_error, builder.buffer(), &error_ptr, &serialization_context_);
                params->error.Set(error_ptr);
                (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
                bool ok = responder_->Accept(builder.message());
                ALLOW_UNUSED_LOCAL(ok);
                // TODO(darin): !ok returned here indicates a malformed message, and that may
                // be good reason to close the connection. However, we don't have a way to do
                // that from here. We should add a way.
                delete responder_;
                responder_ = nullptr;
            }

            // static
            bool NFCStubDispatch::Accept(
                NFC* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message)
            {
                switch (message->header()->name) {
                case internal::kNFC_SetClient_Name: {
                    internal::NFC_SetClient_Params_Data* params = reinterpret_cast<internal::NFC_SetClient_Params_Data*>(
                        message->mutable_payload());

                    (context)->handles.Swap((message)->mutable_handles());
                    bool success = true;
                    NFCClientPtr p_client {};
                    NFC_SetClient_ParamsDataView input_data_view(params,
                        context);

                    p_client = input_data_view.TakeClient<decltype(p_client)>();
                    if (!success) {
                        ReportValidationErrorForMessage(
                            message,
                            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                            "NFC::SetClient deserializer");
                        return false;
                    }
                    // A null |impl| means no implementation was bound.
                    assert(impl);
                    TRACE_EVENT0("mojom", "NFC::SetClient");
                    mojo::internal::MessageDispatchContext context(message);
                    impl->SetClient(
                        std::move(p_client));
                    return true;
                }
                case internal::kNFC_Push_Name: {
                    break;
                }
                case internal::kNFC_CancelPush_Name: {
                    break;
                }
                case internal::kNFC_Watch_Name: {
                    break;
                }
                case internal::kNFC_CancelWatch_Name: {
                    break;
                }
                case internal::kNFC_CancelAllWatches_Name: {
                    break;
                }
                case internal::kNFC_SuspendNFCOperations_Name: {
                    internal::NFC_SuspendNFCOperations_Params_Data* params = reinterpret_cast<internal::NFC_SuspendNFCOperations_Params_Data*>(
                        message->mutable_payload());

                    (context)->handles.Swap((message)->mutable_handles());
                    bool success = true;
                    NFC_SuspendNFCOperations_ParamsDataView input_data_view(params,
                        context);

                    if (!success) {
                        ReportValidationErrorForMessage(
                            message,
                            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                            "NFC::SuspendNFCOperations deserializer");
                        return false;
                    }
                    // A null |impl| means no implementation was bound.
                    assert(impl);
                    TRACE_EVENT0("mojom", "NFC::SuspendNFCOperations");
                    mojo::internal::MessageDispatchContext context(message);
                    impl->SuspendNFCOperations();
                    return true;
                }
                case internal::kNFC_ResumeNFCOperations_Name: {
                    internal::NFC_ResumeNFCOperations_Params_Data* params = reinterpret_cast<internal::NFC_ResumeNFCOperations_Params_Data*>(
                        message->mutable_payload());

                    (context)->handles.Swap((message)->mutable_handles());
                    bool success = true;
                    NFC_ResumeNFCOperations_ParamsDataView input_data_view(params,
                        context);

                    if (!success) {
                        ReportValidationErrorForMessage(
                            message,
                            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                            "NFC::ResumeNFCOperations deserializer");
                        return false;
                    }
                    // A null |impl| means no implementation was bound.
                    assert(impl);
                    TRACE_EVENT0("mojom", "NFC::ResumeNFCOperations");
                    mojo::internal::MessageDispatchContext context(message);
                    impl->ResumeNFCOperations();
                    return true;
                }
                }
                return false;
            }

            // static
            bool NFCStubDispatch::AcceptWithResponder(
                NFC* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder)
            {
                switch (message->header()->name) {
                case internal::kNFC_SetClient_Name: {
                    break;
                }
                case internal::kNFC_Push_Name: {
                    internal::NFC_Push_Params_Data* params = reinterpret_cast<internal::NFC_Push_Params_Data*>(
                        message->mutable_payload());

                    (context)->handles.Swap((message)->mutable_handles());
                    bool success = true;
                    NFCMessagePtr p_message {};
                    NFCPushOptionsPtr p_options {};
                    NFC_Push_ParamsDataView input_data_view(params,
                        context);

                    if (!input_data_view.ReadMessage(&p_message))
                        success = false;
                    if (!input_data_view.ReadOptions(&p_options))
                        success = false;
                    if (!success) {
                        ReportValidationErrorForMessage(
                            message,
                            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                            "NFC::Push deserializer");
                        return false;
                    }
                    NFC::PushCallback callback = NFC_Push_ProxyToResponder::CreateCallback(
                        message->request_id(),
                        message->has_flag(mojo::Message::kFlagIsSync), responder,
                        context->group_controller);
                    // A null |impl| means no implementation was bound.
                    assert(impl);
                    TRACE_EVENT0("mojom", "NFC::Push");
                    mojo::internal::MessageDispatchContext context(message);
                    impl->Push(
                        std::move(p_message),
                        std::move(p_options), std::move(callback));
                    return true;
                }
                case internal::kNFC_CancelPush_Name: {
                    internal::NFC_CancelPush_Params_Data* params = reinterpret_cast<internal::NFC_CancelPush_Params_Data*>(
                        message->mutable_payload());

                    (context)->handles.Swap((message)->mutable_handles());
                    bool success = true;
                    NFCPushTarget p_target {};
                    NFC_CancelPush_ParamsDataView input_data_view(params,
                        context);

                    if (!input_data_view.ReadTarget(&p_target))
                        success = false;
                    if (!success) {
                        ReportValidationErrorForMessage(
                            message,
                            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                            "NFC::CancelPush deserializer");
                        return false;
                    }
                    NFC::CancelPushCallback callback = NFC_CancelPush_ProxyToResponder::CreateCallback(
                        message->request_id(),
                        message->has_flag(mojo::Message::kFlagIsSync), responder,
                        context->group_controller);
                    // A null |impl| means no implementation was bound.
                    assert(impl);
                    TRACE_EVENT0("mojom", "NFC::CancelPush");
                    mojo::internal::MessageDispatchContext context(message);
                    impl->CancelPush(
                        std::move(p_target), std::move(callback));
                    return true;
                }
                case internal::kNFC_Watch_Name: {
                    internal::NFC_Watch_Params_Data* params = reinterpret_cast<internal::NFC_Watch_Params_Data*>(
                        message->mutable_payload());

                    (context)->handles.Swap((message)->mutable_handles());
                    bool success = true;
                    NFCWatchOptionsPtr p_options {};
                    NFC_Watch_ParamsDataView input_data_view(params,
                        context);

                    if (!input_data_view.ReadOptions(&p_options))
                        success = false;
                    if (!success) {
                        ReportValidationErrorForMessage(
                            message,
                            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                            "NFC::Watch deserializer");
                        return false;
                    }
                    NFC::WatchCallback callback = NFC_Watch_ProxyToResponder::CreateCallback(
                        message->request_id(),
                        message->has_flag(mojo::Message::kFlagIsSync), responder,
                        context->group_controller);
                    // A null |impl| means no implementation was bound.
                    assert(impl);
                    TRACE_EVENT0("mojom", "NFC::Watch");
                    mojo::internal::MessageDispatchContext context(message);
                    impl->Watch(
                        std::move(p_options), std::move(callback));
                    return true;
                }
                case internal::kNFC_CancelWatch_Name: {
                    internal::NFC_CancelWatch_Params_Data* params = reinterpret_cast<internal::NFC_CancelWatch_Params_Data*>(
                        message->mutable_payload());

                    (context)->handles.Swap((message)->mutable_handles());
                    bool success = true;
                    uint32_t p_id {};
                    NFC_CancelWatch_ParamsDataView input_data_view(params,
                        context);

                    p_id = input_data_view.id();
                    if (!success) {
                        ReportValidationErrorForMessage(
                            message,
                            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                            "NFC::CancelWatch deserializer");
                        return false;
                    }
                    NFC::CancelWatchCallback callback = NFC_CancelWatch_ProxyToResponder::CreateCallback(
                        message->request_id(),
                        message->has_flag(mojo::Message::kFlagIsSync), responder,
                        context->group_controller);
                    // A null |impl| means no implementation was bound.
                    assert(impl);
                    TRACE_EVENT0("mojom", "NFC::CancelWatch");
                    mojo::internal::MessageDispatchContext context(message);
                    impl->CancelWatch(
                        std::move(p_id), std::move(callback));
                    return true;
                }
                case internal::kNFC_CancelAllWatches_Name: {
                    internal::NFC_CancelAllWatches_Params_Data* params = reinterpret_cast<internal::NFC_CancelAllWatches_Params_Data*>(
                        message->mutable_payload());

                    (context)->handles.Swap((message)->mutable_handles());
                    bool success = true;
                    NFC_CancelAllWatches_ParamsDataView input_data_view(params,
                        context);

                    if (!success) {
                        ReportValidationErrorForMessage(
                            message,
                            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                            "NFC::CancelAllWatches deserializer");
                        return false;
                    }
                    NFC::CancelAllWatchesCallback callback = NFC_CancelAllWatches_ProxyToResponder::CreateCallback(
                        message->request_id(),
                        message->has_flag(mojo::Message::kFlagIsSync), responder,
                        context->group_controller);
                    // A null |impl| means no implementation was bound.
                    assert(impl);
                    TRACE_EVENT0("mojom", "NFC::CancelAllWatches");
                    mojo::internal::MessageDispatchContext context(message);
                    impl->CancelAllWatches(std::move(callback));
                    return true;
                }
                case internal::kNFC_SuspendNFCOperations_Name: {
                    break;
                }
                case internal::kNFC_ResumeNFCOperations_Name: {
                    break;
                }
                }
                return false;
            }

            bool NFCRequestValidator::Accept(mojo::Message* message)
            {
                if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                    return true;

                mojo::internal::ValidationContext validation_context(
                    message->data(), message->data_num_bytes(), message->handles()->size(),
                    message, "NFC RequestValidator");

                switch (message->header()->name) {
                case internal::kNFC_SetClient_Name: {
                    if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                            message, &validation_context)) {
                        return false;
                    }
                    if (!mojo::internal::ValidateMessagePayload<
                            internal::NFC_SetClient_Params_Data>(
                            message, &validation_context)) {
                        return false;
                    }
                    return true;
                }
                case internal::kNFC_Push_Name: {
                    if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                            message, &validation_context)) {
                        return false;
                    }
                    if (!mojo::internal::ValidateMessagePayload<
                            internal::NFC_Push_Params_Data>(
                            message, &validation_context)) {
                        return false;
                    }
                    return true;
                }
                case internal::kNFC_CancelPush_Name: {
                    if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                            message, &validation_context)) {
                        return false;
                    }
                    if (!mojo::internal::ValidateMessagePayload<
                            internal::NFC_CancelPush_Params_Data>(
                            message, &validation_context)) {
                        return false;
                    }
                    return true;
                }
                case internal::kNFC_Watch_Name: {
                    if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                            message, &validation_context)) {
                        return false;
                    }
                    if (!mojo::internal::ValidateMessagePayload<
                            internal::NFC_Watch_Params_Data>(
                            message, &validation_context)) {
                        return false;
                    }
                    return true;
                }
                case internal::kNFC_CancelWatch_Name: {
                    if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                            message, &validation_context)) {
                        return false;
                    }
                    if (!mojo::internal::ValidateMessagePayload<
                            internal::NFC_CancelWatch_Params_Data>(
                            message, &validation_context)) {
                        return false;
                    }
                    return true;
                }
                case internal::kNFC_CancelAllWatches_Name: {
                    if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                            message, &validation_context)) {
                        return false;
                    }
                    if (!mojo::internal::ValidateMessagePayload<
                            internal::NFC_CancelAllWatches_Params_Data>(
                            message, &validation_context)) {
                        return false;
                    }
                    return true;
                }
                case internal::kNFC_SuspendNFCOperations_Name: {
                    if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                            message, &validation_context)) {
                        return false;
                    }
                    if (!mojo::internal::ValidateMessagePayload<
                            internal::NFC_SuspendNFCOperations_Params_Data>(
                            message, &validation_context)) {
                        return false;
                    }
                    return true;
                }
                case internal::kNFC_ResumeNFCOperations_Name: {
                    if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                            message, &validation_context)) {
                        return false;
                    }
                    if (!mojo::internal::ValidateMessagePayload<
                            internal::NFC_ResumeNFCOperations_Params_Data>(
                            message, &validation_context)) {
                        return false;
                    }
                    return true;
                }
                default:
                    break;
                }

                // Unrecognized message.
                ReportValidationError(
                    &validation_context,
                    mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
                return false;
            }

            bool NFCResponseValidator::Accept(mojo::Message* message)
            {
                if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                    return true;

                mojo::internal::ValidationContext validation_context(
                    message->data(), message->data_num_bytes(), message->handles()->size(),
                    message, "NFC ResponseValidator");

                if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
                    return false;
                switch (message->header()->name) {
                case internal::kNFC_Push_Name: {
                    if (!mojo::internal::ValidateMessagePayload<
                            internal::NFC_Push_ResponseParams_Data>(
                            message, &validation_context)) {
                        return false;
                    }
                    return true;
                }
                case internal::kNFC_CancelPush_Name: {
                    if (!mojo::internal::ValidateMessagePayload<
                            internal::NFC_CancelPush_ResponseParams_Data>(
                            message, &validation_context)) {
                        return false;
                    }
                    return true;
                }
                case internal::kNFC_Watch_Name: {
                    if (!mojo::internal::ValidateMessagePayload<
                            internal::NFC_Watch_ResponseParams_Data>(
                            message, &validation_context)) {
                        return false;
                    }
                    return true;
                }
                case internal::kNFC_CancelWatch_Name: {
                    if (!mojo::internal::ValidateMessagePayload<
                            internal::NFC_CancelWatch_ResponseParams_Data>(
                            message, &validation_context)) {
                        return false;
                    }
                    return true;
                }
                case internal::kNFC_CancelAllWatches_Name: {
                    if (!mojo::internal::ValidateMessagePayload<
                            internal::NFC_CancelAllWatches_ResponseParams_Data>(
                            message, &validation_context)) {
                        return false;
                    }
                    return true;
                }
                default:
                    break;
                }

                // Unrecognized message.
                ReportValidationError(
                    &validation_context,
                    mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
                return false;
            }
            const char NFCClient::Name_[] = "device::nfc::mojom::NFCClient";

            NFCClientProxy::NFCClientProxy(mojo::MessageReceiverWithResponder* receiver)
                : receiver_(receiver)
            {
            }

            void NFCClientProxy::OnWatch(
                const WTF::Vector<uint32_t>& in_watch_ids, NFCMessagePtr in_message)
            {
                mojo::internal::SerializationContext serialization_context(
                    group_controller_);
                size_t size = sizeof(::device::nfc::mojom::internal::NFCClient_OnWatch_Params_Data);
                size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint32_t>>(
                    in_watch_ids, &serialization_context);
                size += mojo::internal::PrepareToSerialize<::device::nfc::mojom::NFCMessageDataView>(
                    in_message, &serialization_context);
                mojo::internal::MessageBuilder builder(internal::kNFCClient_OnWatch_Name, size);

                auto params = ::device::nfc::mojom::internal::NFCClient_OnWatch_Params_Data::New(builder.buffer());
                ALLOW_UNUSED_LOCAL(params);
                typename decltype(params->watch_ids)::BaseType* watch_ids_ptr;
                const mojo::internal::ContainerValidateParams watch_ids_validate_params(
                    0, false, nullptr);
                mojo::internal::Serialize<mojo::ArrayDataView<uint32_t>>(
                    in_watch_ids, builder.buffer(), &watch_ids_ptr, &watch_ids_validate_params,
                    &serialization_context);
                params->watch_ids.Set(watch_ids_ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    params->watch_ids.is_null(),
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null watch_ids in NFCClient.OnWatch request");
                typename decltype(params->message)::BaseType* message_ptr;
                mojo::internal::Serialize<::device::nfc::mojom::NFCMessageDataView>(
                    in_message, builder.buffer(), &message_ptr, &serialization_context);
                params->message.Set(message_ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    params->message.is_null(),
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null message in NFCClient.OnWatch request");
                (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
                bool ok = receiver_->Accept(builder.message());
                // This return value may be ignored as !ok implies the Connector has
                // encountered an error, which will be visible through other means.
                ALLOW_UNUSED_LOCAL(ok);
            }

            // static
            bool NFCClientStubDispatch::Accept(
                NFCClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message)
            {
                switch (message->header()->name) {
                case internal::kNFCClient_OnWatch_Name: {
                    internal::NFCClient_OnWatch_Params_Data* params = reinterpret_cast<internal::NFCClient_OnWatch_Params_Data*>(
                        message->mutable_payload());

                    (context)->handles.Swap((message)->mutable_handles());
                    bool success = true;
                    WTF::Vector<uint32_t> p_watch_ids {};
                    NFCMessagePtr p_message {};
                    NFCClient_OnWatch_ParamsDataView input_data_view(params,
                        context);

                    if (!input_data_view.ReadWatchIds(&p_watch_ids))
                        success = false;
                    if (!input_data_view.ReadMessage(&p_message))
                        success = false;
                    if (!success) {
                        ReportValidationErrorForMessage(
                            message,
                            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                            "NFCClient::OnWatch deserializer");
                        return false;
                    }
                    // A null |impl| means no implementation was bound.
                    assert(impl);
                    TRACE_EVENT0("mojom", "NFCClient::OnWatch");
                    mojo::internal::MessageDispatchContext context(message);
                    impl->OnWatch(
                        std::move(p_watch_ids),
                        std::move(p_message));
                    return true;
                }
                }
                return false;
            }

            // static
            bool NFCClientStubDispatch::AcceptWithResponder(
                NFCClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder)
            {
                switch (message->header()->name) {
                case internal::kNFCClient_OnWatch_Name: {
                    break;
                }
                }
                return false;
            }

            bool NFCClientRequestValidator::Accept(mojo::Message* message)
            {
                if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                    return true;

                mojo::internal::ValidationContext validation_context(
                    message->data(), message->data_num_bytes(), message->handles()->size(),
                    message, "NFCClient RequestValidator");

                switch (message->header()->name) {
                case internal::kNFCClient_OnWatch_Name: {
                    if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                            message, &validation_context)) {
                        return false;
                    }
                    if (!mojo::internal::ValidateMessagePayload<
                            internal::NFCClient_OnWatch_Params_Data>(
                            message, &validation_context)) {
                        return false;
                    }
                    return true;
                }
                default:
                    break;
                }

                // Unrecognized message.
                ReportValidationError(
                    &validation_context,
                    mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
                return false;
            }

        } // namespace blink
    } // namespace mojom
} // namespace nfc
} // namespace device

namespace mojo {

// static
bool StructTraits<::device::nfc::mojom::blink::NFCError::DataView, ::device::nfc::mojom::blink::NFCErrorPtr>::Read(
    ::device::nfc::mojom::blink::NFCError::DataView input,
    ::device::nfc::mojom::blink::NFCErrorPtr* output)
{
    bool success = true;
    ::device::nfc::mojom::blink::NFCErrorPtr result(::device::nfc::mojom::blink::NFCError::New());

    if (!input.ReadErrorType(&result->error_type))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::nfc::mojom::blink::NFCRecord::DataView, ::device::nfc::mojom::blink::NFCRecordPtr>::Read(
    ::device::nfc::mojom::blink::NFCRecord::DataView input,
    ::device::nfc::mojom::blink::NFCRecordPtr* output)
{
    bool success = true;
    ::device::nfc::mojom::blink::NFCRecordPtr result(::device::nfc::mojom::blink::NFCRecord::New());

    if (!input.ReadRecordType(&result->record_type))
        success = false;
    if (!input.ReadMediaType(&result->media_type))
        success = false;
    if (!input.ReadData(&result->data))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::nfc::mojom::blink::NFCMessage::DataView, ::device::nfc::mojom::blink::NFCMessagePtr>::Read(
    ::device::nfc::mojom::blink::NFCMessage::DataView input,
    ::device::nfc::mojom::blink::NFCMessagePtr* output)
{
    bool success = true;
    ::device::nfc::mojom::blink::NFCMessagePtr result(::device::nfc::mojom::blink::NFCMessage::New());

    if (!input.ReadData(&result->data))
        success = false;
    if (!input.ReadUrl(&result->url))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::nfc::mojom::blink::NFCPushOptions::DataView, ::device::nfc::mojom::blink::NFCPushOptionsPtr>::Read(
    ::device::nfc::mojom::blink::NFCPushOptions::DataView input,
    ::device::nfc::mojom::blink::NFCPushOptionsPtr* output)
{
    bool success = true;
    ::device::nfc::mojom::blink::NFCPushOptionsPtr result(::device::nfc::mojom::blink::NFCPushOptions::New());

    if (!input.ReadTarget(&result->target))
        success = false;
    result->timeout = input.timeout();
    result->ignore_read = input.ignore_read();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::nfc::mojom::blink::NFCRecordTypeFilter::DataView, ::device::nfc::mojom::blink::NFCRecordTypeFilterPtr>::Read(
    ::device::nfc::mojom::blink::NFCRecordTypeFilter::DataView input,
    ::device::nfc::mojom::blink::NFCRecordTypeFilterPtr* output)
{
    bool success = true;
    ::device::nfc::mojom::blink::NFCRecordTypeFilterPtr result(::device::nfc::mojom::blink::NFCRecordTypeFilter::New());

    if (!input.ReadRecordType(&result->record_type))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::nfc::mojom::blink::NFCWatchOptions::DataView, ::device::nfc::mojom::blink::NFCWatchOptionsPtr>::Read(
    ::device::nfc::mojom::blink::NFCWatchOptions::DataView input,
    ::device::nfc::mojom::blink::NFCWatchOptionsPtr* output)
{
    bool success = true;
    ::device::nfc::mojom::blink::NFCWatchOptionsPtr result(::device::nfc::mojom::blink::NFCWatchOptions::New());

    if (!input.ReadUrl(&result->url))
        success = false;
    if (!input.ReadRecordFilter(&result->record_filter))
        success = false;
    if (!input.ReadMediaType(&result->media_type))
        success = false;
    if (!input.ReadMode(&result->mode))
        success = false;
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif