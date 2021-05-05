// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef IPC_IPC_MOJOM_SHARED_H_
#define IPC_IPC_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "ipc/ipc.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace IPC {
namespace mojom {
    class SerializedHandleDataView;

} // namespace mojom
} // namespace IPC

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::IPC::mojom::SerializedHandleDataView> {
        using Data = ::IPC::mojom::internal::SerializedHandle_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace IPC {
namespace mojom {

    enum class SerializedHandle_Type : int32_t {
        MOJO_HANDLE,
        PLATFORM_FILE,
        WIN_HANDLE,
        MACH_PORT,
    };

    inline std::ostream& operator<<(std::ostream& os, SerializedHandle_Type value)
    {
        switch (value) {
        case SerializedHandle_Type::MOJO_HANDLE:
            return os << "SerializedHandle_Type::MOJO_HANDLE";
        case SerializedHandle_Type::PLATFORM_FILE:
            return os << "SerializedHandle_Type::PLATFORM_FILE";
        case SerializedHandle_Type::WIN_HANDLE:
            return os << "SerializedHandle_Type::WIN_HANDLE";
        case SerializedHandle_Type::MACH_PORT:
            return os << "SerializedHandle_Type::MACH_PORT";
        default:
            return os << "Unknown SerializedHandle_Type value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(SerializedHandle_Type value)
    {
        return internal::SerializedHandle_Type_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class GenericInterfaceInterfaceBase {
    };

    using GenericInterfacePtrDataView = mojo::InterfacePtrDataView<GenericInterfaceInterfaceBase>;
    using GenericInterfaceRequestDataView = mojo::InterfaceRequestDataView<GenericInterfaceInterfaceBase>;
    using GenericInterfaceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<GenericInterfaceInterfaceBase>;
    using GenericInterfaceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<GenericInterfaceInterfaceBase>;
    class ChannelInterfaceBase {
    };

    using ChannelPtrDataView = mojo::InterfacePtrDataView<ChannelInterfaceBase>;
    using ChannelRequestDataView = mojo::InterfaceRequestDataView<ChannelInterfaceBase>;
    using ChannelAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ChannelInterfaceBase>;
    using ChannelAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ChannelInterfaceBase>;
    class ChannelBootstrapInterfaceBase {
    };

    using ChannelBootstrapPtrDataView = mojo::InterfacePtrDataView<ChannelBootstrapInterfaceBase>;
    using ChannelBootstrapRequestDataView = mojo::InterfaceRequestDataView<ChannelBootstrapInterfaceBase>;
    using ChannelBootstrapAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ChannelBootstrapInterfaceBase>;
    using ChannelBootstrapAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ChannelBootstrapInterfaceBase>;
    class SerializedHandleDataView {
    public:
        SerializedHandleDataView() { }

        SerializedHandleDataView(
            internal::SerializedHandle_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        mojo::ScopedHandle TakeTheHandle()
        {
            mojo::ScopedHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedHandle>(
                &data_->the_handle, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::IPC::mojom::SerializedHandle_Type>(
                data_value, output);
        }

        SerializedHandle_Type type() const
        {
            return static_cast<SerializedHandle_Type>(data_->type);
        }

    private:
        internal::SerializedHandle_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Channel_SetPeerPid_ParamsDataView {
    public:
        Channel_SetPeerPid_ParamsDataView() { }

        Channel_SetPeerPid_ParamsDataView(
            internal::Channel_SetPeerPid_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t pid() const
        {
            return data_->pid;
        }

    private:
        internal::Channel_SetPeerPid_Params_Data* data_ = nullptr;
    };

    class Channel_Receive_ParamsDataView {
    public:
        Channel_Receive_ParamsDataView() { }

        Channel_Receive_ParamsDataView(
            internal::Channel_Receive_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetHandlesDataView(
            mojo::ArrayDataView<SerializedHandleDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadHandles(UserType* output)
        {
            auto* pointer = data_->handles.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::IPC::mojom::SerializedHandleDataView>>(
                pointer, output, context_);
        }

    private:
        internal::Channel_Receive_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Channel_GetAssociatedInterface_ParamsDataView {
    public:
        Channel_GetAssociatedInterface_ParamsDataView() { }

        Channel_GetAssociatedInterface_ParamsDataView(
            internal::Channel_GetAssociatedInterface_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::IPC::mojom::GenericInterfaceAssociatedRequestDataView>(
                &data_->request, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::Channel_GetAssociatedInterface_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace IPC

namespace std {

template <>
struct hash<::IPC::mojom::SerializedHandle_Type>
    : public mojo::internal::EnumHashImpl<::IPC::mojom::SerializedHandle_Type> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::IPC::mojom::SerializedHandle_Type, ::IPC::mojom::SerializedHandle_Type> {
    static ::IPC::mojom::SerializedHandle_Type ToMojom(::IPC::mojom::SerializedHandle_Type input) { return input; }
    static bool FromMojom(::IPC::mojom::SerializedHandle_Type input, ::IPC::mojom::SerializedHandle_Type* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::IPC::mojom::SerializedHandle_Type, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::IPC::mojom::SerializedHandle_Type, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::IPC::mojom::SerializedHandle_Type>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::IPC::mojom::SerializedHandleDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::IPC::mojom::SerializedHandleDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::IPC::mojom::internal::SerializedHandle_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::IPC::mojom::internal::SerializedHandle_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::IPC::mojom::internal::SerializedHandle_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::the_handle, input, custom_context)) in_the_handle = CallWithContext(Traits::the_handle, input, custom_context);
            mojo::internal::Serialize<mojo::ScopedHandle>(
                in_the_handle, &result->the_handle, context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(result->the_handle),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid the_handle in SerializedHandle struct");
            mojo::internal::Serialize<::IPC::mojom::SerializedHandle_Type>(
                CallWithContext(Traits::type, input, custom_context), &result->type);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::IPC::mojom::internal::SerializedHandle_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::IPC::mojom::SerializedHandleDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace IPC {
namespace mojom {

    inline void Channel_Receive_ParamsDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void Channel_Receive_ParamsDataView::GetHandlesDataView(
        mojo::ArrayDataView<SerializedHandleDataView>* output)
    {
        auto pointer = data_->handles.Get();
        *output = mojo::ArrayDataView<SerializedHandleDataView>(pointer, context_);
    }

    inline void Channel_GetAssociatedInterface_ParamsDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace IPC

#endif // IPC_IPC_MOJOM_SHARED_H_
