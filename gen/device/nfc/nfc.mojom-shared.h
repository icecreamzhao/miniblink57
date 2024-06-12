// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_NFC_NFC_MOJOM_SHARED_H_
#define DEVICE_NFC_NFC_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/nfc/nfc.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace device {
namespace nfc {
    namespace mojom {
        class NFCErrorDataView;

        class NFCRecordDataView;

        class NFCMessageDataView;

        class NFCPushOptionsDataView;

        class NFCRecordTypeFilterDataView;

        class NFCWatchOptionsDataView;

    } // namespace mojom
} // namespace nfc
} // namespace device

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::device::nfc::mojom::NFCErrorDataView> {
        using Data = ::device::nfc::mojom::internal::NFCError_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::nfc::mojom::NFCRecordDataView> {
        using Data = ::device::nfc::mojom::internal::NFCRecord_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::nfc::mojom::NFCMessageDataView> {
        using Data = ::device::nfc::mojom::internal::NFCMessage_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::nfc::mojom::NFCPushOptionsDataView> {
        using Data = ::device::nfc::mojom::internal::NFCPushOptions_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::nfc::mojom::NFCRecordTypeFilterDataView> {
        using Data = ::device::nfc::mojom::internal::NFCRecordTypeFilter_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::device::nfc::mojom::NFCWatchOptionsDataView> {
        using Data = ::device::nfc::mojom::internal::NFCWatchOptions_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace device {
namespace nfc {
    namespace mojom {

        enum class NFCErrorType : int32_t {
            SECURITY,
            NOT_SUPPORTED,
            DEVICE_DISABLED,
            NOT_FOUND,
            INVALID_MESSAGE,
            OPERATION_CANCELLED,
            TIMER_EXPIRED,
            CANNOT_CANCEL,
            IO_ERROR,
        };

        inline std::ostream& operator<<(std::ostream& os, NFCErrorType value)
        {
            switch (value) {
            case NFCErrorType::SECURITY:
                return os << "NFCErrorType::SECURITY";
            case NFCErrorType::NOT_SUPPORTED:
                return os << "NFCErrorType::NOT_SUPPORTED";
            case NFCErrorType::DEVICE_DISABLED:
                return os << "NFCErrorType::DEVICE_DISABLED";
            case NFCErrorType::NOT_FOUND:
                return os << "NFCErrorType::NOT_FOUND";
            case NFCErrorType::INVALID_MESSAGE:
                return os << "NFCErrorType::INVALID_MESSAGE";
            case NFCErrorType::OPERATION_CANCELLED:
                return os << "NFCErrorType::OPERATION_CANCELLED";
            case NFCErrorType::TIMER_EXPIRED:
                return os << "NFCErrorType::TIMER_EXPIRED";
            case NFCErrorType::CANNOT_CANCEL:
                return os << "NFCErrorType::CANNOT_CANCEL";
            case NFCErrorType::IO_ERROR:
                return os << "NFCErrorType::IO_ERROR";
            default:
                return os << "Unknown NFCErrorType value: " << static_cast<int32_t>(value);
            }
        }
        inline bool IsKnownEnumValue(NFCErrorType value)
        {
            return internal::NFCErrorType_Data::IsKnownValue(
                static_cast<int32_t>(value));
        }

        enum class NFCRecordType : int32_t {
            EMPTY,
            TEXT,
            URL,
            JSON,
            OPAQUE_RECORD,
        };

        inline std::ostream& operator<<(std::ostream& os, NFCRecordType value)
        {
            switch (value) {
            case NFCRecordType::EMPTY:
                return os << "NFCRecordType::EMPTY";
            case NFCRecordType::TEXT:
                return os << "NFCRecordType::TEXT";
            case NFCRecordType::URL:
                return os << "NFCRecordType::URL";
            case NFCRecordType::JSON:
                return os << "NFCRecordType::JSON";
            case NFCRecordType::OPAQUE_RECORD:
                return os << "NFCRecordType::OPAQUE_RECORD";
            default:
                return os << "Unknown NFCRecordType value: " << static_cast<int32_t>(value);
            }
        }
        inline bool IsKnownEnumValue(NFCRecordType value)
        {
            return internal::NFCRecordType_Data::IsKnownValue(
                static_cast<int32_t>(value));
        }

        enum class NFCPushTarget : int32_t {
            TAG,
            PEER,
            ANY,
        };

        inline std::ostream& operator<<(std::ostream& os, NFCPushTarget value)
        {
            switch (value) {
            case NFCPushTarget::TAG:
                return os << "NFCPushTarget::TAG";
            case NFCPushTarget::PEER:
                return os << "NFCPushTarget::PEER";
            case NFCPushTarget::ANY:
                return os << "NFCPushTarget::ANY";
            default:
                return os << "Unknown NFCPushTarget value: " << static_cast<int32_t>(value);
            }
        }
        inline bool IsKnownEnumValue(NFCPushTarget value)
        {
            return internal::NFCPushTarget_Data::IsKnownValue(
                static_cast<int32_t>(value));
        }

        enum class NFCWatchMode : int32_t {
            WEBNFC_ONLY,
            ANY,
        };

        inline std::ostream& operator<<(std::ostream& os, NFCWatchMode value)
        {
            switch (value) {
            case NFCWatchMode::WEBNFC_ONLY:
                return os << "NFCWatchMode::WEBNFC_ONLY";
            case NFCWatchMode::ANY:
                return os << "NFCWatchMode::ANY";
            default:
                return os << "Unknown NFCWatchMode value: " << static_cast<int32_t>(value);
            }
        }
        inline bool IsKnownEnumValue(NFCWatchMode value)
        {
            return internal::NFCWatchMode_Data::IsKnownValue(
                static_cast<int32_t>(value));
        }
        // Interface base classes. They are used for type safety check.
        class NFCInterfaceBase {
        };

        using NFCPtrDataView = mojo::InterfacePtrDataView<NFCInterfaceBase>;
        using NFCRequestDataView = mojo::InterfaceRequestDataView<NFCInterfaceBase>;
        using NFCAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<NFCInterfaceBase>;
        using NFCAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<NFCInterfaceBase>;
        class NFCClientInterfaceBase {
        };

        using NFCClientPtrDataView = mojo::InterfacePtrDataView<NFCClientInterfaceBase>;
        using NFCClientRequestDataView = mojo::InterfaceRequestDataView<NFCClientInterfaceBase>;
        using NFCClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<NFCClientInterfaceBase>;
        using NFCClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<NFCClientInterfaceBase>;
        class NFCErrorDataView {
        public:
            NFCErrorDataView() { }

            NFCErrorDataView(
                internal::NFCError_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
            {
            }

            bool is_null() const { return !data_; }
            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadErrorType(UserType* output) const
            {
                auto data_value = data_->error_type;
                return mojo::internal::Deserialize<::device::nfc::mojom::NFCErrorType>(
                    data_value, output);
            }

            NFCErrorType error_type() const
            {
                return static_cast<NFCErrorType>(data_->error_type);
            }

        private:
            internal::NFCError_Data* data_ = nullptr;
        };

        class NFCRecordDataView {
        public:
            NFCRecordDataView() { }

            NFCRecordDataView(
                internal::NFCRecord_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
                , context_(context)
            {
            }

            bool is_null() const { return !data_; }
            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadRecordType(UserType* output) const
            {
                auto data_value = data_->record_type;
                return mojo::internal::Deserialize<::device::nfc::mojom::NFCRecordType>(
                    data_value, output);
            }

            NFCRecordType record_type() const
            {
                return static_cast<NFCRecordType>(data_->record_type);
            }
            inline void GetMediaTypeDataView(
                mojo::StringDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadMediaType(UserType* output)
            {
                auto* pointer = data_->media_type.Get();
                return mojo::internal::Deserialize<mojo::StringDataView>(
                    pointer, output, context_);
            }
            inline void GetDataDataView(
                mojo::ArrayDataView<uint8_t>* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadData(UserType* output)
            {
                auto* pointer = data_->data.Get();
                return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                    pointer, output, context_);
            }

        private:
            internal::NFCRecord_Data* data_ = nullptr;
            mojo::internal::SerializationContext* context_ = nullptr;
        };

        class NFCMessageDataView {
        public:
            NFCMessageDataView() { }

            NFCMessageDataView(
                internal::NFCMessage_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
                , context_(context)
            {
            }

            bool is_null() const { return !data_; }
            inline void GetDataDataView(
                mojo::ArrayDataView<NFCRecordDataView>* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadData(UserType* output)
            {
                auto* pointer = data_->data.Get();
                return mojo::internal::Deserialize<mojo::ArrayDataView<::device::nfc::mojom::NFCRecordDataView>>(
                    pointer, output, context_);
            }
            inline void GetUrlDataView(
                mojo::StringDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadUrl(UserType* output)
            {
                auto* pointer = data_->url.Get();
                return mojo::internal::Deserialize<mojo::StringDataView>(
                    pointer, output, context_);
            }

        private:
            internal::NFCMessage_Data* data_ = nullptr;
            mojo::internal::SerializationContext* context_ = nullptr;
        };

        class NFCPushOptionsDataView {
        public:
            NFCPushOptionsDataView() { }

            NFCPushOptionsDataView(
                internal::NFCPushOptions_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
            {
            }

            bool is_null() const { return !data_; }
            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadTarget(UserType* output) const
            {
                auto data_value = data_->target;
                return mojo::internal::Deserialize<::device::nfc::mojom::NFCPushTarget>(
                    data_value, output);
            }

            NFCPushTarget target() const
            {
                return static_cast<NFCPushTarget>(data_->target);
            }
            double timeout() const
            {
                return data_->timeout;
            }
            bool ignore_read() const
            {
                return data_->ignore_read;
            }

        private:
            internal::NFCPushOptions_Data* data_ = nullptr;
        };

        class NFCRecordTypeFilterDataView {
        public:
            NFCRecordTypeFilterDataView() { }

            NFCRecordTypeFilterDataView(
                internal::NFCRecordTypeFilter_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
            {
            }

            bool is_null() const { return !data_; }
            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadRecordType(UserType* output) const
            {
                auto data_value = data_->record_type;
                return mojo::internal::Deserialize<::device::nfc::mojom::NFCRecordType>(
                    data_value, output);
            }

            NFCRecordType record_type() const
            {
                return static_cast<NFCRecordType>(data_->record_type);
            }

        private:
            internal::NFCRecordTypeFilter_Data* data_ = nullptr;
        };

        class NFCWatchOptionsDataView {
        public:
            NFCWatchOptionsDataView() { }

            NFCWatchOptionsDataView(
                internal::NFCWatchOptions_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
                , context_(context)
            {
            }

            bool is_null() const { return !data_; }
            inline void GetUrlDataView(
                mojo::StringDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadUrl(UserType* output)
            {
                auto* pointer = data_->url.Get();
                return mojo::internal::Deserialize<mojo::StringDataView>(
                    pointer, output, context_);
            }
            inline void GetRecordFilterDataView(
                NFCRecordTypeFilterDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadRecordFilter(UserType* output)
            {
                auto* pointer = data_->record_filter.Get();
                return mojo::internal::Deserialize<::device::nfc::mojom::NFCRecordTypeFilterDataView>(
                    pointer, output, context_);
            }
            inline void GetMediaTypeDataView(
                mojo::StringDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadMediaType(UserType* output)
            {
                auto* pointer = data_->media_type.Get();
                return mojo::internal::Deserialize<mojo::StringDataView>(
                    pointer, output, context_);
            }
            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadMode(UserType* output) const
            {
                auto data_value = data_->mode;
                return mojo::internal::Deserialize<::device::nfc::mojom::NFCWatchMode>(
                    data_value, output);
            }

            NFCWatchMode mode() const
            {
                return static_cast<NFCWatchMode>(data_->mode);
            }

        private:
            internal::NFCWatchOptions_Data* data_ = nullptr;
            mojo::internal::SerializationContext* context_ = nullptr;
        };

        class NFC_SetClient_ParamsDataView {
        public:
            NFC_SetClient_ParamsDataView() { }

            NFC_SetClient_ParamsDataView(
                internal::NFC_SetClient_Params_Data* data,
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
                bool ret = mojo::internal::Deserialize<::device::nfc::mojom::NFCClientPtrDataView>(
                    &data_->client, &result, context_);
                DCHECK(ret);
                return result;
            }

        private:
            internal::NFC_SetClient_Params_Data* data_ = nullptr;
            mojo::internal::SerializationContext* context_ = nullptr;
        };

        class NFC_Push_ParamsDataView {
        public:
            NFC_Push_ParamsDataView() { }

            NFC_Push_ParamsDataView(
                internal::NFC_Push_Params_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
                , context_(context)
            {
            }

            bool is_null() const { return !data_; }
            inline void GetMessageDataView(
                NFCMessageDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadMessage(UserType* output)
            {
                auto* pointer = data_->message.Get();
                return mojo::internal::Deserialize<::device::nfc::mojom::NFCMessageDataView>(
                    pointer, output, context_);
            }
            inline void GetOptionsDataView(
                NFCPushOptionsDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadOptions(UserType* output)
            {
                auto* pointer = data_->options.Get();
                return mojo::internal::Deserialize<::device::nfc::mojom::NFCPushOptionsDataView>(
                    pointer, output, context_);
            }

        private:
            internal::NFC_Push_Params_Data* data_ = nullptr;
            mojo::internal::SerializationContext* context_ = nullptr;
        };

        class NFC_Push_ResponseParamsDataView {
        public:
            NFC_Push_ResponseParamsDataView() { }

            NFC_Push_ResponseParamsDataView(
                internal::NFC_Push_ResponseParams_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
                , context_(context)
            {
            }

            bool is_null() const { return !data_; }
            inline void GetErrorDataView(
                NFCErrorDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadError(UserType* output)
            {
                auto* pointer = data_->error.Get();
                return mojo::internal::Deserialize<::device::nfc::mojom::NFCErrorDataView>(
                    pointer, output, context_);
            }

        private:
            internal::NFC_Push_ResponseParams_Data* data_ = nullptr;
            mojo::internal::SerializationContext* context_ = nullptr;
        };

        class NFC_CancelPush_ParamsDataView {
        public:
            NFC_CancelPush_ParamsDataView() { }

            NFC_CancelPush_ParamsDataView(
                internal::NFC_CancelPush_Params_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
            {
            }

            bool is_null() const { return !data_; }
            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadTarget(UserType* output) const
            {
                auto data_value = data_->target;
                return mojo::internal::Deserialize<::device::nfc::mojom::NFCPushTarget>(
                    data_value, output);
            }

            NFCPushTarget target() const
            {
                return static_cast<NFCPushTarget>(data_->target);
            }

        private:
            internal::NFC_CancelPush_Params_Data* data_ = nullptr;
        };

        class NFC_CancelPush_ResponseParamsDataView {
        public:
            NFC_CancelPush_ResponseParamsDataView() { }

            NFC_CancelPush_ResponseParamsDataView(
                internal::NFC_CancelPush_ResponseParams_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
                , context_(context)
            {
            }

            bool is_null() const { return !data_; }
            inline void GetErrorDataView(
                NFCErrorDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadError(UserType* output)
            {
                auto* pointer = data_->error.Get();
                return mojo::internal::Deserialize<::device::nfc::mojom::NFCErrorDataView>(
                    pointer, output, context_);
            }

        private:
            internal::NFC_CancelPush_ResponseParams_Data* data_ = nullptr;
            mojo::internal::SerializationContext* context_ = nullptr;
        };

        class NFC_Watch_ParamsDataView {
        public:
            NFC_Watch_ParamsDataView() { }

            NFC_Watch_ParamsDataView(
                internal::NFC_Watch_Params_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
                , context_(context)
            {
            }

            bool is_null() const { return !data_; }
            inline void GetOptionsDataView(
                NFCWatchOptionsDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadOptions(UserType* output)
            {
                auto* pointer = data_->options.Get();
                return mojo::internal::Deserialize<::device::nfc::mojom::NFCWatchOptionsDataView>(
                    pointer, output, context_);
            }

        private:
            internal::NFC_Watch_Params_Data* data_ = nullptr;
            mojo::internal::SerializationContext* context_ = nullptr;
        };

        class NFC_Watch_ResponseParamsDataView {
        public:
            NFC_Watch_ResponseParamsDataView() { }

            NFC_Watch_ResponseParamsDataView(
                internal::NFC_Watch_ResponseParams_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
                , context_(context)
            {
            }

            bool is_null() const { return !data_; }
            uint32_t id() const
            {
                return data_->id;
            }
            inline void GetErrorDataView(
                NFCErrorDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadError(UserType* output)
            {
                auto* pointer = data_->error.Get();
                return mojo::internal::Deserialize<::device::nfc::mojom::NFCErrorDataView>(
                    pointer, output, context_);
            }

        private:
            internal::NFC_Watch_ResponseParams_Data* data_ = nullptr;
            mojo::internal::SerializationContext* context_ = nullptr;
        };

        class NFC_CancelWatch_ParamsDataView {
        public:
            NFC_CancelWatch_ParamsDataView() { }

            NFC_CancelWatch_ParamsDataView(
                internal::NFC_CancelWatch_Params_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
            {
            }

            bool is_null() const { return !data_; }
            uint32_t id() const
            {
                return data_->id;
            }

        private:
            internal::NFC_CancelWatch_Params_Data* data_ = nullptr;
        };

        class NFC_CancelWatch_ResponseParamsDataView {
        public:
            NFC_CancelWatch_ResponseParamsDataView() { }

            NFC_CancelWatch_ResponseParamsDataView(
                internal::NFC_CancelWatch_ResponseParams_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
                , context_(context)
            {
            }

            bool is_null() const { return !data_; }
            inline void GetErrorDataView(
                NFCErrorDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadError(UserType* output)
            {
                auto* pointer = data_->error.Get();
                return mojo::internal::Deserialize<::device::nfc::mojom::NFCErrorDataView>(
                    pointer, output, context_);
            }

        private:
            internal::NFC_CancelWatch_ResponseParams_Data* data_ = nullptr;
            mojo::internal::SerializationContext* context_ = nullptr;
        };

        class NFC_CancelAllWatches_ParamsDataView {
        public:
            NFC_CancelAllWatches_ParamsDataView() { }

            NFC_CancelAllWatches_ParamsDataView(
                internal::NFC_CancelAllWatches_Params_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
            {
            }

            bool is_null() const { return !data_; }

        private:
            internal::NFC_CancelAllWatches_Params_Data* data_ = nullptr;
        };

        class NFC_CancelAllWatches_ResponseParamsDataView {
        public:
            NFC_CancelAllWatches_ResponseParamsDataView() { }

            NFC_CancelAllWatches_ResponseParamsDataView(
                internal::NFC_CancelAllWatches_ResponseParams_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
                , context_(context)
            {
            }

            bool is_null() const { return !data_; }
            inline void GetErrorDataView(
                NFCErrorDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadError(UserType* output)
            {
                auto* pointer = data_->error.Get();
                return mojo::internal::Deserialize<::device::nfc::mojom::NFCErrorDataView>(
                    pointer, output, context_);
            }

        private:
            internal::NFC_CancelAllWatches_ResponseParams_Data* data_ = nullptr;
            mojo::internal::SerializationContext* context_ = nullptr;
        };

        class NFC_SuspendNFCOperations_ParamsDataView {
        public:
            NFC_SuspendNFCOperations_ParamsDataView() { }

            NFC_SuspendNFCOperations_ParamsDataView(
                internal::NFC_SuspendNFCOperations_Params_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
            {
            }

            bool is_null() const { return !data_; }

        private:
            internal::NFC_SuspendNFCOperations_Params_Data* data_ = nullptr;
        };

        class NFC_ResumeNFCOperations_ParamsDataView {
        public:
            NFC_ResumeNFCOperations_ParamsDataView() { }

            NFC_ResumeNFCOperations_ParamsDataView(
                internal::NFC_ResumeNFCOperations_Params_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
            {
            }

            bool is_null() const { return !data_; }

        private:
            internal::NFC_ResumeNFCOperations_Params_Data* data_ = nullptr;
        };

        class NFCClient_OnWatch_ParamsDataView {
        public:
            NFCClient_OnWatch_ParamsDataView() { }

            NFCClient_OnWatch_ParamsDataView(
                internal::NFCClient_OnWatch_Params_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
                , context_(context)
            {
            }

            bool is_null() const { return !data_; }
            inline void GetWatchIdsDataView(
                mojo::ArrayDataView<uint32_t>* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadWatchIds(UserType* output)
            {
                auto* pointer = data_->watch_ids.Get();
                return mojo::internal::Deserialize<mojo::ArrayDataView<uint32_t>>(
                    pointer, output, context_);
            }
            inline void GetMessageDataView(
                NFCMessageDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadMessage(UserType* output)
            {
                auto* pointer = data_->message.Get();
                return mojo::internal::Deserialize<::device::nfc::mojom::NFCMessageDataView>(
                    pointer, output, context_);
            }

        private:
            internal::NFCClient_OnWatch_Params_Data* data_ = nullptr;
            mojo::internal::SerializationContext* context_ = nullptr;
        };

    } // namespace mojom
} // namespace nfc
} // namespace device

namespace std {

template <>
struct hash<::device::nfc::mojom::NFCErrorType>
    : public mojo::internal::EnumHashImpl<::device::nfc::mojom::NFCErrorType> {
};

template <>
struct hash<::device::nfc::mojom::NFCRecordType>
    : public mojo::internal::EnumHashImpl<::device::nfc::mojom::NFCRecordType> {
};

template <>
struct hash<::device::nfc::mojom::NFCPushTarget>
    : public mojo::internal::EnumHashImpl<::device::nfc::mojom::NFCPushTarget> {
};

template <>
struct hash<::device::nfc::mojom::NFCWatchMode>
    : public mojo::internal::EnumHashImpl<::device::nfc::mojom::NFCWatchMode> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::device::nfc::mojom::NFCErrorType, ::device::nfc::mojom::NFCErrorType> {
    static ::device::nfc::mojom::NFCErrorType ToMojom(::device::nfc::mojom::NFCErrorType input) { return input; }
    static bool FromMojom(::device::nfc::mojom::NFCErrorType input, ::device::nfc::mojom::NFCErrorType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::nfc::mojom::NFCErrorType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::nfc::mojom::NFCErrorType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::nfc::mojom::NFCErrorType>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::device::nfc::mojom::NFCRecordType, ::device::nfc::mojom::NFCRecordType> {
    static ::device::nfc::mojom::NFCRecordType ToMojom(::device::nfc::mojom::NFCRecordType input) { return input; }
    static bool FromMojom(::device::nfc::mojom::NFCRecordType input, ::device::nfc::mojom::NFCRecordType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::nfc::mojom::NFCRecordType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::nfc::mojom::NFCRecordType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::nfc::mojom::NFCRecordType>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::device::nfc::mojom::NFCPushTarget, ::device::nfc::mojom::NFCPushTarget> {
    static ::device::nfc::mojom::NFCPushTarget ToMojom(::device::nfc::mojom::NFCPushTarget input) { return input; }
    static bool FromMojom(::device::nfc::mojom::NFCPushTarget input, ::device::nfc::mojom::NFCPushTarget* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::nfc::mojom::NFCPushTarget, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::nfc::mojom::NFCPushTarget, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::nfc::mojom::NFCPushTarget>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::device::nfc::mojom::NFCWatchMode, ::device::nfc::mojom::NFCWatchMode> {
    static ::device::nfc::mojom::NFCWatchMode ToMojom(::device::nfc::mojom::NFCWatchMode input) { return input; }
    static bool FromMojom(::device::nfc::mojom::NFCWatchMode input, ::device::nfc::mojom::NFCWatchMode* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::nfc::mojom::NFCWatchMode, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::nfc::mojom::NFCWatchMode, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::nfc::mojom::NFCWatchMode>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::nfc::mojom::NFCErrorDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::nfc::mojom::NFCErrorDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::nfc::mojom::internal::NFCError_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::nfc::mojom::internal::NFCError_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::nfc::mojom::internal::NFCError_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::device::nfc::mojom::NFCErrorType>(
                CallWithContext(Traits::error_type, input, custom_context), &result->error_type);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::nfc::mojom::internal::NFCError_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::nfc::mojom::NFCErrorDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::nfc::mojom::NFCRecordDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::nfc::mojom::NFCRecordDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::nfc::mojom::internal::NFCRecord_Data);
            decltype(CallWithContext(Traits::media_type, input, custom_context)) in_media_type = CallWithContext(Traits::media_type, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_media_type, context);
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_data, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::nfc::mojom::internal::NFCRecord_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::nfc::mojom::internal::NFCRecord_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::device::nfc::mojom::NFCRecordType>(
                CallWithContext(Traits::record_type, input, custom_context), &result->record_type);
            decltype(CallWithContext(Traits::media_type, input, custom_context)) in_media_type = CallWithContext(Traits::media_type, input, custom_context);
            typename decltype(result->media_type)::BaseType* media_type_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_media_type, buffer, &media_type_ptr, context);
            result->media_type.Set(media_type_ptr);
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            typename decltype(result->data)::BaseType* data_ptr;
            const mojo::internal::ContainerValidateParams data_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_data, buffer, &data_ptr, &data_validate_params,
                context);
            result->data.Set(data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null data in NFCRecord struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::nfc::mojom::internal::NFCRecord_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::nfc::mojom::NFCRecordDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::nfc::mojom::NFCMessageDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::nfc::mojom::NFCMessageDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::nfc::mojom::internal::NFCMessage_Data);
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::device::nfc::mojom::NFCRecordDataView>>(
                in_data, context);
            decltype(CallWithContext(Traits::url, input, custom_context)) in_url = CallWithContext(Traits::url, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_url, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::nfc::mojom::internal::NFCMessage_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::nfc::mojom::internal::NFCMessage_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            typename decltype(result->data)::BaseType* data_ptr;
            const mojo::internal::ContainerValidateParams data_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::device::nfc::mojom::NFCRecordDataView>>(
                in_data, buffer, &data_ptr, &data_validate_params,
                context);
            result->data.Set(data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null data in NFCMessage struct");
            decltype(CallWithContext(Traits::url, input, custom_context)) in_url = CallWithContext(Traits::url, input, custom_context);
            typename decltype(result->url)::BaseType* url_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_url, buffer, &url_ptr, context);
            result->url.Set(url_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::nfc::mojom::internal::NFCMessage_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::nfc::mojom::NFCMessageDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::nfc::mojom::NFCPushOptionsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::nfc::mojom::NFCPushOptionsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::nfc::mojom::internal::NFCPushOptions_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::nfc::mojom::internal::NFCPushOptions_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::nfc::mojom::internal::NFCPushOptions_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::device::nfc::mojom::NFCPushTarget>(
                CallWithContext(Traits::target, input, custom_context), &result->target);
            result->timeout = CallWithContext(Traits::timeout, input, custom_context);
            result->ignore_read = CallWithContext(Traits::ignore_read, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::nfc::mojom::internal::NFCPushOptions_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::nfc::mojom::NFCPushOptionsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::nfc::mojom::NFCRecordTypeFilterDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::nfc::mojom::NFCRecordTypeFilterDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::nfc::mojom::internal::NFCRecordTypeFilter_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::nfc::mojom::internal::NFCRecordTypeFilter_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::nfc::mojom::internal::NFCRecordTypeFilter_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::device::nfc::mojom::NFCRecordType>(
                CallWithContext(Traits::record_type, input, custom_context), &result->record_type);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::nfc::mojom::internal::NFCRecordTypeFilter_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::nfc::mojom::NFCRecordTypeFilterDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::nfc::mojom::NFCWatchOptionsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::nfc::mojom::NFCWatchOptionsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::nfc::mojom::internal::NFCWatchOptions_Data);
            decltype(CallWithContext(Traits::url, input, custom_context)) in_url = CallWithContext(Traits::url, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_url, context);
            decltype(CallWithContext(Traits::record_filter, input, custom_context)) in_record_filter = CallWithContext(Traits::record_filter, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::device::nfc::mojom::NFCRecordTypeFilterDataView>(
                in_record_filter, context);
            decltype(CallWithContext(Traits::media_type, input, custom_context)) in_media_type = CallWithContext(Traits::media_type, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_media_type, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::nfc::mojom::internal::NFCWatchOptions_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::nfc::mojom::internal::NFCWatchOptions_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::url, input, custom_context)) in_url = CallWithContext(Traits::url, input, custom_context);
            typename decltype(result->url)::BaseType* url_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_url, buffer, &url_ptr, context);
            result->url.Set(url_ptr);
            decltype(CallWithContext(Traits::record_filter, input, custom_context)) in_record_filter = CallWithContext(Traits::record_filter, input, custom_context);
            typename decltype(result->record_filter)::BaseType* record_filter_ptr;
            mojo::internal::Serialize<::device::nfc::mojom::NFCRecordTypeFilterDataView>(
                in_record_filter, buffer, &record_filter_ptr, context);
            result->record_filter.Set(record_filter_ptr);
            decltype(CallWithContext(Traits::media_type, input, custom_context)) in_media_type = CallWithContext(Traits::media_type, input, custom_context);
            typename decltype(result->media_type)::BaseType* media_type_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_media_type, buffer, &media_type_ptr, context);
            result->media_type.Set(media_type_ptr);
            mojo::internal::Serialize<::device::nfc::mojom::NFCWatchMode>(
                CallWithContext(Traits::mode, input, custom_context), &result->mode);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::nfc::mojom::internal::NFCWatchOptions_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::nfc::mojom::NFCWatchOptionsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace device {
namespace nfc {
    namespace mojom {

        inline void NFCRecordDataView::GetMediaTypeDataView(
            mojo::StringDataView* output)
        {
            auto pointer = data_->media_type.Get();
            *output = mojo::StringDataView(pointer, context_);
        }
        inline void NFCRecordDataView::GetDataDataView(
            mojo::ArrayDataView<uint8_t>* output)
        {
            auto pointer = data_->data.Get();
            *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
        }

        inline void NFCMessageDataView::GetDataDataView(
            mojo::ArrayDataView<NFCRecordDataView>* output)
        {
            auto pointer = data_->data.Get();
            *output = mojo::ArrayDataView<NFCRecordDataView>(pointer, context_);
        }
        inline void NFCMessageDataView::GetUrlDataView(
            mojo::StringDataView* output)
        {
            auto pointer = data_->url.Get();
            *output = mojo::StringDataView(pointer, context_);
        }

        inline void NFCWatchOptionsDataView::GetUrlDataView(
            mojo::StringDataView* output)
        {
            auto pointer = data_->url.Get();
            *output = mojo::StringDataView(pointer, context_);
        }
        inline void NFCWatchOptionsDataView::GetRecordFilterDataView(
            NFCRecordTypeFilterDataView* output)
        {
            auto pointer = data_->record_filter.Get();
            *output = NFCRecordTypeFilterDataView(pointer, context_);
        }
        inline void NFCWatchOptionsDataView::GetMediaTypeDataView(
            mojo::StringDataView* output)
        {
            auto pointer = data_->media_type.Get();
            *output = mojo::StringDataView(pointer, context_);
        }

        inline void NFC_Push_ParamsDataView::GetMessageDataView(
            NFCMessageDataView* output)
        {
            auto pointer = data_->message.Get();
            *output = NFCMessageDataView(pointer, context_);
        }
        inline void NFC_Push_ParamsDataView::GetOptionsDataView(
            NFCPushOptionsDataView* output)
        {
            auto pointer = data_->options.Get();
            *output = NFCPushOptionsDataView(pointer, context_);
        }

        inline void NFC_Push_ResponseParamsDataView::GetErrorDataView(
            NFCErrorDataView* output)
        {
            auto pointer = data_->error.Get();
            *output = NFCErrorDataView(pointer, context_);
        }

        inline void NFC_CancelPush_ResponseParamsDataView::GetErrorDataView(
            NFCErrorDataView* output)
        {
            auto pointer = data_->error.Get();
            *output = NFCErrorDataView(pointer, context_);
        }

        inline void NFC_Watch_ParamsDataView::GetOptionsDataView(
            NFCWatchOptionsDataView* output)
        {
            auto pointer = data_->options.Get();
            *output = NFCWatchOptionsDataView(pointer, context_);
        }

        inline void NFC_Watch_ResponseParamsDataView::GetErrorDataView(
            NFCErrorDataView* output)
        {
            auto pointer = data_->error.Get();
            *output = NFCErrorDataView(pointer, context_);
        }

        inline void NFC_CancelWatch_ResponseParamsDataView::GetErrorDataView(
            NFCErrorDataView* output)
        {
            auto pointer = data_->error.Get();
            *output = NFCErrorDataView(pointer, context_);
        }

        inline void NFC_CancelAllWatches_ResponseParamsDataView::GetErrorDataView(
            NFCErrorDataView* output)
        {
            auto pointer = data_->error.Get();
            *output = NFCErrorDataView(pointer, context_);
        }

        inline void NFCClient_OnWatch_ParamsDataView::GetWatchIdsDataView(
            mojo::ArrayDataView<uint32_t>* output)
        {
            auto pointer = data_->watch_ids.Get();
            *output = mojo::ArrayDataView<uint32_t>(pointer, context_);
        }
        inline void NFCClient_OnWatch_ParamsDataView::GetMessageDataView(
            NFCMessageDataView* output)
        {
            auto pointer = data_->message.Get();
            *output = NFCMessageDataView(pointer, context_);
        }

    } // namespace mojom
} // namespace nfc
} // namespace device

#endif // DEVICE_NFC_NFC_MOJOM_SHARED_H_
