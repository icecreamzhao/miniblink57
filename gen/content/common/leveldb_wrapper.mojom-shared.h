// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_LEVELDB_WRAPPER_MOJOM_SHARED_H_
#define CONTENT_COMMON_LEVELDB_WRAPPER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "components/leveldb/public/interfaces/leveldb.mojom-shared.h"
#include "content/common/leveldb_wrapper.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace content {
namespace mojom {
    class KeyValueDataView;

} // namespace mojom
} // namespace content

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::content::mojom::KeyValueDataView> {
        using Data = ::content::mojom::internal::KeyValue_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace content {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class LevelDBObserverInterfaceBase {
    };

    using LevelDBObserverPtrDataView = mojo::InterfacePtrDataView<LevelDBObserverInterfaceBase>;
    using LevelDBObserverRequestDataView = mojo::InterfaceRequestDataView<LevelDBObserverInterfaceBase>;
    using LevelDBObserverAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<LevelDBObserverInterfaceBase>;
    using LevelDBObserverAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<LevelDBObserverInterfaceBase>;
    class LevelDBWrapperGetAllCallbackInterfaceBase {
    };

    using LevelDBWrapperGetAllCallbackPtrDataView = mojo::InterfacePtrDataView<LevelDBWrapperGetAllCallbackInterfaceBase>;
    using LevelDBWrapperGetAllCallbackRequestDataView = mojo::InterfaceRequestDataView<LevelDBWrapperGetAllCallbackInterfaceBase>;
    using LevelDBWrapperGetAllCallbackAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<LevelDBWrapperGetAllCallbackInterfaceBase>;
    using LevelDBWrapperGetAllCallbackAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<LevelDBWrapperGetAllCallbackInterfaceBase>;
    class LevelDBWrapperInterfaceBase {
    };

    using LevelDBWrapperPtrDataView = mojo::InterfacePtrDataView<LevelDBWrapperInterfaceBase>;
    using LevelDBWrapperRequestDataView = mojo::InterfaceRequestDataView<LevelDBWrapperInterfaceBase>;
    using LevelDBWrapperAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<LevelDBWrapperInterfaceBase>;
    using LevelDBWrapperAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<LevelDBWrapperInterfaceBase>;
    class KeyValueDataView {
    public:
        KeyValueDataView() { }

        KeyValueDataView(
            internal::KeyValue_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::KeyValue_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBObserver_KeyAdded_ParamsDataView {
    public:
        LevelDBObserver_KeyAdded_ParamsDataView() { }

        LevelDBObserver_KeyAdded_ParamsDataView(
            internal::LevelDBObserver_KeyAdded_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetSourceDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSource(UserType* output)
        {
            auto* pointer = data_->source.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBObserver_KeyAdded_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBObserver_KeyChanged_ParamsDataView {
    public:
        LevelDBObserver_KeyChanged_ParamsDataView() { }

        LevelDBObserver_KeyChanged_ParamsDataView(
            internal::LevelDBObserver_KeyChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetNewValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNewValue(UserType* output)
        {
            auto* pointer = data_->new_value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetOldValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOldValue(UserType* output)
        {
            auto* pointer = data_->old_value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetSourceDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSource(UserType* output)
        {
            auto* pointer = data_->source.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBObserver_KeyChanged_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBObserver_KeyDeleted_ParamsDataView {
    public:
        LevelDBObserver_KeyDeleted_ParamsDataView() { }

        LevelDBObserver_KeyDeleted_ParamsDataView(
            internal::LevelDBObserver_KeyDeleted_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetOldValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOldValue(UserType* output)
        {
            auto* pointer = data_->old_value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetSourceDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSource(UserType* output)
        {
            auto* pointer = data_->source.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBObserver_KeyDeleted_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBObserver_AllDeleted_ParamsDataView {
    public:
        LevelDBObserver_AllDeleted_ParamsDataView() { }

        LevelDBObserver_AllDeleted_ParamsDataView(
            internal::LevelDBObserver_AllDeleted_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSourceDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSource(UserType* output)
        {
            auto* pointer = data_->source.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBObserver_AllDeleted_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBWrapperGetAllCallback_Complete_ParamsDataView {
    public:
        LevelDBWrapperGetAllCallback_Complete_ParamsDataView() { }

        LevelDBWrapperGetAllCallback_Complete_ParamsDataView(
            internal::LevelDBWrapperGetAllCallback_Complete_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::LevelDBWrapperGetAllCallback_Complete_Params_Data* data_ = nullptr;
    };

    class LevelDBWrapper_AddObserver_ParamsDataView {
    public:
        LevelDBWrapper_AddObserver_ParamsDataView() { }

        LevelDBWrapper_AddObserver_ParamsDataView(
            internal::LevelDBWrapper_AddObserver_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeObserver()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::content::mojom::LevelDBObserverAssociatedPtrInfoDataView>(
                &data_->observer, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::LevelDBWrapper_AddObserver_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBWrapper_Put_ParamsDataView {
    public:
        LevelDBWrapper_Put_ParamsDataView() { }

        LevelDBWrapper_Put_ParamsDataView(
            internal::LevelDBWrapper_Put_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetSourceDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSource(UserType* output)
        {
            auto* pointer = data_->source.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBWrapper_Put_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBWrapper_Put_ResponseParamsDataView {
    public:
        LevelDBWrapper_Put_ResponseParamsDataView() { }

        LevelDBWrapper_Put_ResponseParamsDataView(
            internal::LevelDBWrapper_Put_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::LevelDBWrapper_Put_ResponseParams_Data* data_ = nullptr;
    };

    class LevelDBWrapper_Delete_ParamsDataView {
    public:
        LevelDBWrapper_Delete_ParamsDataView() { }

        LevelDBWrapper_Delete_ParamsDataView(
            internal::LevelDBWrapper_Delete_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetSourceDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSource(UserType* output)
        {
            auto* pointer = data_->source.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBWrapper_Delete_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBWrapper_Delete_ResponseParamsDataView {
    public:
        LevelDBWrapper_Delete_ResponseParamsDataView() { }

        LevelDBWrapper_Delete_ResponseParamsDataView(
            internal::LevelDBWrapper_Delete_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::LevelDBWrapper_Delete_ResponseParams_Data* data_ = nullptr;
    };

    class LevelDBWrapper_DeleteAll_ParamsDataView {
    public:
        LevelDBWrapper_DeleteAll_ParamsDataView() { }

        LevelDBWrapper_DeleteAll_ParamsDataView(
            internal::LevelDBWrapper_DeleteAll_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSourceDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSource(UserType* output)
        {
            auto* pointer = data_->source.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBWrapper_DeleteAll_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBWrapper_DeleteAll_ResponseParamsDataView {
    public:
        LevelDBWrapper_DeleteAll_ResponseParamsDataView() { }

        LevelDBWrapper_DeleteAll_ResponseParamsDataView(
            internal::LevelDBWrapper_DeleteAll_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::LevelDBWrapper_DeleteAll_ResponseParams_Data* data_ = nullptr;
    };

    class LevelDBWrapper_Get_ParamsDataView {
    public:
        LevelDBWrapper_Get_ParamsDataView() { }

        LevelDBWrapper_Get_ParamsDataView(
            internal::LevelDBWrapper_Get_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBWrapper_Get_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBWrapper_Get_ResponseParamsDataView {
    public:
        LevelDBWrapper_Get_ResponseParamsDataView() { }

        LevelDBWrapper_Get_ResponseParamsDataView(
            internal::LevelDBWrapper_Get_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBWrapper_Get_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBWrapper_GetAll_ParamsDataView {
    public:
        LevelDBWrapper_GetAll_ParamsDataView() { }

        LevelDBWrapper_GetAll_ParamsDataView(
            internal::LevelDBWrapper_GetAll_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeCompleteCallback()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::content::mojom::LevelDBWrapperGetAllCallbackAssociatedPtrInfoDataView>(
                &data_->complete_callback, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::LevelDBWrapper_GetAll_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBWrapper_GetAll_ResponseParamsDataView {
    public:
        LevelDBWrapper_GetAll_ResponseParamsDataView() { }

        LevelDBWrapper_GetAll_ResponseParamsDataView(
            internal::LevelDBWrapper_GetAll_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        ::leveldb::mojom::DatabaseError status() const
        {
            return static_cast<::leveldb::mojom::DatabaseError>(data_->status);
        }
        inline void GetDataDataView(
            mojo::ArrayDataView<KeyValueDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::content::mojom::KeyValueDataView>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBWrapper_GetAll_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace content

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::content::mojom::KeyValueDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::content::mojom::KeyValueDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::content::mojom::internal::KeyValue_Data);
            decltype(CallWithContext(Traits::key, input, custom_context)) in_key = CallWithContext(Traits::key, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_key, context);
            decltype(CallWithContext(Traits::value, input, custom_context)) in_value = CallWithContext(Traits::value, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_value, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::content::mojom::internal::KeyValue_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::content::mojom::internal::KeyValue_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::key, input, custom_context)) in_key = CallWithContext(Traits::key, input, custom_context);
            typename decltype(result->key)::BaseType* key_ptr;
            const mojo::internal::ContainerValidateParams key_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_key, buffer, &key_ptr, &key_validate_params,
                context);
            result->key.Set(key_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->key.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null key in KeyValue struct");
            decltype(CallWithContext(Traits::value, input, custom_context)) in_value = CallWithContext(Traits::value, input, custom_context);
            typename decltype(result->value)::BaseType* value_ptr;
            const mojo::internal::ContainerValidateParams value_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_value, buffer, &value_ptr, &value_validate_params,
                context);
            result->value.Set(value_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->value.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null value in KeyValue struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::content::mojom::internal::KeyValue_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::content::mojom::KeyValueDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace content {
namespace mojom {

    inline void KeyValueDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void KeyValueDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBObserver_KeyAdded_ParamsDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void LevelDBObserver_KeyAdded_ParamsDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void LevelDBObserver_KeyAdded_ParamsDataView::GetSourceDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->source.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void LevelDBObserver_KeyChanged_ParamsDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void LevelDBObserver_KeyChanged_ParamsDataView::GetNewValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->new_value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void LevelDBObserver_KeyChanged_ParamsDataView::GetOldValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->old_value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void LevelDBObserver_KeyChanged_ParamsDataView::GetSourceDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->source.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void LevelDBObserver_KeyDeleted_ParamsDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void LevelDBObserver_KeyDeleted_ParamsDataView::GetOldValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->old_value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void LevelDBObserver_KeyDeleted_ParamsDataView::GetSourceDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->source.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void LevelDBObserver_AllDeleted_ParamsDataView::GetSourceDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->source.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void LevelDBWrapper_Put_ParamsDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void LevelDBWrapper_Put_ParamsDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void LevelDBWrapper_Put_ParamsDataView::GetSourceDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->source.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void LevelDBWrapper_Delete_ParamsDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void LevelDBWrapper_Delete_ParamsDataView::GetSourceDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->source.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void LevelDBWrapper_DeleteAll_ParamsDataView::GetSourceDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->source.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void LevelDBWrapper_Get_ParamsDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBWrapper_Get_ResponseParamsDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBWrapper_GetAll_ResponseParamsDataView::GetDataDataView(
        mojo::ArrayDataView<KeyValueDataView>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<KeyValueDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_LEVELDB_WRAPPER_MOJOM_SHARED_H_
