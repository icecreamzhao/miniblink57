// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BUDGET_SERVICE_BUDGET_SERVICE_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BUDGET_SERVICE_BUDGET_SERVICE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "third_party/WebKit/public/platform/modules/budget_service/budget_service.mojom-shared-internal.h"
#include "url/mojo/origin.mojom-shared.h"

namespace blink {
namespace mojom {
    class BudgetStateDataView;

} // namespace mojom
} // namespace blink

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::blink::mojom::BudgetStateDataView> {
        using Data = ::blink::mojom::internal::BudgetState_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace blink {
namespace mojom {

    enum class BudgetOperationType : int32_t {
        SILENT_PUSH,
        INVALID_OPERATION,
    };

    inline std::ostream& operator<<(std::ostream& os, BudgetOperationType value)
    {
        switch (value) {
        case BudgetOperationType::SILENT_PUSH:
            return os << "BudgetOperationType::SILENT_PUSH";
        case BudgetOperationType::INVALID_OPERATION:
            return os << "BudgetOperationType::INVALID_OPERATION";
        default:
            return os << "Unknown BudgetOperationType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(BudgetOperationType value)
    {
        return internal::BudgetOperationType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class BudgetServiceErrorType : int32_t {
        NONE,
        DATABASE_ERROR,
        NOT_SUPPORTED,
    };

    inline std::ostream& operator<<(std::ostream& os, BudgetServiceErrorType value)
    {
        switch (value) {
        case BudgetServiceErrorType::NONE:
            return os << "BudgetServiceErrorType::NONE";
        case BudgetServiceErrorType::DATABASE_ERROR:
            return os << "BudgetServiceErrorType::DATABASE_ERROR";
        case BudgetServiceErrorType::NOT_SUPPORTED:
            return os << "BudgetServiceErrorType::NOT_SUPPORTED";
        default:
            return os << "Unknown BudgetServiceErrorType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(BudgetServiceErrorType value)
    {
        return internal::BudgetServiceErrorType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class BudgetServiceInterfaceBase {
    };

    using BudgetServicePtrDataView = mojo::InterfacePtrDataView<BudgetServiceInterfaceBase>;
    using BudgetServiceRequestDataView = mojo::InterfaceRequestDataView<BudgetServiceInterfaceBase>;
    using BudgetServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<BudgetServiceInterfaceBase>;
    using BudgetServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<BudgetServiceInterfaceBase>;
    class BudgetStateDataView {
    public:
        BudgetStateDataView() { }

        BudgetStateDataView(
            internal::BudgetState_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        double budget_at() const
        {
            return data_->budget_at;
        }
        double time() const
        {
            return data_->time;
        }

    private:
        internal::BudgetState_Data* data_ = nullptr;
    };

    class BudgetService_GetCost_ParamsDataView {
    public:
        BudgetService_GetCost_ParamsDataView() { }

        BudgetService_GetCost_ParamsDataView(
            internal::BudgetService_GetCost_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOperation(UserType* output) const
        {
            auto data_value = data_->operation;
            return mojo::internal::Deserialize<::blink::mojom::BudgetOperationType>(
                data_value, output);
        }

        BudgetOperationType operation() const
        {
            return static_cast<BudgetOperationType>(data_->operation);
        }

    private:
        internal::BudgetService_GetCost_Params_Data* data_ = nullptr;
    };

    class BudgetService_GetCost_ResponseParamsDataView {
    public:
        BudgetService_GetCost_ResponseParamsDataView() { }

        BudgetService_GetCost_ResponseParamsDataView(
            internal::BudgetService_GetCost_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        double cost() const
        {
            return data_->cost;
        }

    private:
        internal::BudgetService_GetCost_ResponseParams_Data* data_ = nullptr;
    };

    class BudgetService_GetBudget_ParamsDataView {
    public:
        BudgetService_GetBudget_ParamsDataView() { }

        BudgetService_GetBudget_ParamsDataView(
            internal::BudgetService_GetBudget_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetOriginDataView(
            ::url::mojom::OriginDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrigin(UserType* output)
        {
            auto* pointer = data_->origin.Get();
            return mojo::internal::Deserialize<::url::mojom::OriginDataView>(
                pointer, output, context_);
        }

    private:
        internal::BudgetService_GetBudget_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class BudgetService_GetBudget_ResponseParamsDataView {
    public:
        BudgetService_GetBudget_ResponseParamsDataView() { }

        BudgetService_GetBudget_ResponseParamsDataView(
            internal::BudgetService_GetBudget_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadErrorType(UserType* output) const
        {
            auto data_value = data_->error_type;
            return mojo::internal::Deserialize<::blink::mojom::BudgetServiceErrorType>(
                data_value, output);
        }

        BudgetServiceErrorType error_type() const
        {
            return static_cast<BudgetServiceErrorType>(data_->error_type);
        }
        inline void GetBudgetDataView(
            mojo::ArrayDataView<BudgetStateDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBudget(UserType* output)
        {
            auto* pointer = data_->budget.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::blink::mojom::BudgetStateDataView>>(
                pointer, output, context_);
        }

    private:
        internal::BudgetService_GetBudget_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class BudgetService_Reserve_ParamsDataView {
    public:
        BudgetService_Reserve_ParamsDataView() { }

        BudgetService_Reserve_ParamsDataView(
            internal::BudgetService_Reserve_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetOriginDataView(
            ::url::mojom::OriginDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrigin(UserType* output)
        {
            auto* pointer = data_->origin.Get();
            return mojo::internal::Deserialize<::url::mojom::OriginDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOperation(UserType* output) const
        {
            auto data_value = data_->operation;
            return mojo::internal::Deserialize<::blink::mojom::BudgetOperationType>(
                data_value, output);
        }

        BudgetOperationType operation() const
        {
            return static_cast<BudgetOperationType>(data_->operation);
        }

    private:
        internal::BudgetService_Reserve_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class BudgetService_Reserve_ResponseParamsDataView {
    public:
        BudgetService_Reserve_ResponseParamsDataView() { }

        BudgetService_Reserve_ResponseParamsDataView(
            internal::BudgetService_Reserve_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadErrorType(UserType* output) const
        {
            auto data_value = data_->error_type;
            return mojo::internal::Deserialize<::blink::mojom::BudgetServiceErrorType>(
                data_value, output);
        }

        BudgetServiceErrorType error_type() const
        {
            return static_cast<BudgetServiceErrorType>(data_->error_type);
        }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::BudgetService_Reserve_ResponseParams_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

template <>
struct hash<::blink::mojom::BudgetOperationType>
    : public mojo::internal::EnumHashImpl<::blink::mojom::BudgetOperationType> {
};

template <>
struct hash<::blink::mojom::BudgetServiceErrorType>
    : public mojo::internal::EnumHashImpl<::blink::mojom::BudgetServiceErrorType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::blink::mojom::BudgetOperationType, ::blink::mojom::BudgetOperationType> {
    static ::blink::mojom::BudgetOperationType ToMojom(::blink::mojom::BudgetOperationType input) { return input; }
    static bool FromMojom(::blink::mojom::BudgetOperationType input, ::blink::mojom::BudgetOperationType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::BudgetOperationType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::BudgetOperationType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::BudgetOperationType>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::blink::mojom::BudgetServiceErrorType, ::blink::mojom::BudgetServiceErrorType> {
    static ::blink::mojom::BudgetServiceErrorType ToMojom(::blink::mojom::BudgetServiceErrorType input) { return input; }
    static bool FromMojom(::blink::mojom::BudgetServiceErrorType input, ::blink::mojom::BudgetServiceErrorType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::BudgetServiceErrorType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::BudgetServiceErrorType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::BudgetServiceErrorType>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::BudgetStateDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::BudgetStateDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::BudgetState_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::BudgetState_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::BudgetState_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->budget_at = CallWithContext(Traits::budget_at, input, custom_context);
            result->time = CallWithContext(Traits::time, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::BudgetState_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::BudgetStateDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace blink {
namespace mojom {

    inline void BudgetService_GetBudget_ParamsDataView::GetOriginDataView(
        ::url::mojom::OriginDataView* output)
    {
        auto pointer = data_->origin.Get();
        *output = ::url::mojom::OriginDataView(pointer, context_);
    }

    inline void BudgetService_GetBudget_ResponseParamsDataView::GetBudgetDataView(
        mojo::ArrayDataView<BudgetStateDataView>* output)
    {
        auto pointer = data_->budget.Get();
        *output = mojo::ArrayDataView<BudgetStateDataView>(pointer, context_);
    }

    inline void BudgetService_Reserve_ParamsDataView::GetOriginDataView(
        ::url::mojom::OriginDataView* output)
    {
        auto pointer = data_->origin.Get();
        *output = ::url::mojom::OriginDataView(pointer, context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BUDGET_SERVICE_BUDGET_SERVICE_MOJOM_SHARED_H_
