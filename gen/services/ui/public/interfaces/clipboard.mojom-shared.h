// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_CLIPBOARD_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_CLIPBOARD_MOJOM_SHARED_H_

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
#include "services/ui/public/interfaces/clipboard.mojom-shared-internal.h"

namespace ui {
namespace mojom {

} // namespace mojom
} // namespace ui

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace ui {
namespace mojom {

    enum class Clipboard_Type : int32_t {
        COPY_PASTE = 0,
        SELECTION = 1,
    };

    inline std::ostream& operator<<(std::ostream& os, Clipboard_Type value)
    {
        switch (value) {
        case Clipboard_Type::COPY_PASTE:
            return os << "Clipboard_Type::COPY_PASTE";
        case Clipboard_Type::SELECTION:
            return os << "Clipboard_Type::SELECTION";
        default:
            return os << "Unknown Clipboard_Type value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(Clipboard_Type value)
    {
        return internal::Clipboard_Type_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class ClipboardInterfaceBase {
    };

    using ClipboardPtrDataView = mojo::InterfacePtrDataView<ClipboardInterfaceBase>;
    using ClipboardRequestDataView = mojo::InterfaceRequestDataView<ClipboardInterfaceBase>;
    using ClipboardAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ClipboardInterfaceBase>;
    using ClipboardAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ClipboardInterfaceBase>;
    class Clipboard_GetSequenceNumber_ParamsDataView {
    public:
        Clipboard_GetSequenceNumber_ParamsDataView() { }

        Clipboard_GetSequenceNumber_ParamsDataView(
            internal::Clipboard_GetSequenceNumber_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadClipboardType(UserType* output) const
        {
            auto data_value = data_->clipboard_type;
            return mojo::internal::Deserialize<::ui::mojom::Clipboard_Type>(
                data_value, output);
        }

        Clipboard_Type clipboard_type() const
        {
            return static_cast<Clipboard_Type>(data_->clipboard_type);
        }

    private:
        internal::Clipboard_GetSequenceNumber_Params_Data* data_ = nullptr;
    };

    class Clipboard_GetSequenceNumber_ResponseParamsDataView {
    public:
        Clipboard_GetSequenceNumber_ResponseParamsDataView() { }

        Clipboard_GetSequenceNumber_ResponseParamsDataView(
            internal::Clipboard_GetSequenceNumber_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint64_t sequence() const
        {
            return data_->sequence;
        }

    private:
        internal::Clipboard_GetSequenceNumber_ResponseParams_Data* data_ = nullptr;
    };

    class Clipboard_GetAvailableMimeTypes_ParamsDataView {
    public:
        Clipboard_GetAvailableMimeTypes_ParamsDataView() { }

        Clipboard_GetAvailableMimeTypes_ParamsDataView(
            internal::Clipboard_GetAvailableMimeTypes_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadClipboardTypes(UserType* output) const
        {
            auto data_value = data_->clipboard_types;
            return mojo::internal::Deserialize<::ui::mojom::Clipboard_Type>(
                data_value, output);
        }

        Clipboard_Type clipboard_types() const
        {
            return static_cast<Clipboard_Type>(data_->clipboard_types);
        }

    private:
        internal::Clipboard_GetAvailableMimeTypes_Params_Data* data_ = nullptr;
    };

    class Clipboard_GetAvailableMimeTypes_ResponseParamsDataView {
    public:
        Clipboard_GetAvailableMimeTypes_ResponseParamsDataView() { }

        Clipboard_GetAvailableMimeTypes_ResponseParamsDataView(
            internal::Clipboard_GetAvailableMimeTypes_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint64_t sequence() const
        {
            return data_->sequence;
        }
        inline void GetTypesDataView(
            mojo::ArrayDataView<mojo::StringDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTypes(UserType* output)
        {
            auto* pointer = data_->types.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<mojo::StringDataView>>(
                pointer, output, context_);
        }

    private:
        internal::Clipboard_GetAvailableMimeTypes_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Clipboard_ReadClipboardData_ParamsDataView {
    public:
        Clipboard_ReadClipboardData_ParamsDataView() { }

        Clipboard_ReadClipboardData_ParamsDataView(
            internal::Clipboard_ReadClipboardData_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadClipboardType(UserType* output) const
        {
            auto data_value = data_->clipboard_type;
            return mojo::internal::Deserialize<::ui::mojom::Clipboard_Type>(
                data_value, output);
        }

        Clipboard_Type clipboard_type() const
        {
            return static_cast<Clipboard_Type>(data_->clipboard_type);
        }
        inline void GetMimeTypeDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMimeType(UserType* output)
        {
            auto* pointer = data_->mime_type.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Clipboard_ReadClipboardData_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Clipboard_ReadClipboardData_ResponseParamsDataView {
    public:
        Clipboard_ReadClipboardData_ResponseParamsDataView() { }

        Clipboard_ReadClipboardData_ResponseParamsDataView(
            internal::Clipboard_ReadClipboardData_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint64_t sequence() const
        {
            return data_->sequence;
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
        internal::Clipboard_ReadClipboardData_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Clipboard_WriteClipboardData_ParamsDataView {
    public:
        Clipboard_WriteClipboardData_ParamsDataView() { }

        Clipboard_WriteClipboardData_ParamsDataView(
            internal::Clipboard_WriteClipboardData_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadClipboardType(UserType* output) const
        {
            auto data_value = data_->clipboard_type;
            return mojo::internal::Deserialize<::ui::mojom::Clipboard_Type>(
                data_value, output);
        }

        Clipboard_Type clipboard_type() const
        {
            return static_cast<Clipboard_Type>(data_->clipboard_type);
        }
        inline void GetDataDataView(
            mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
                pointer, output, context_);
        }

    private:
        internal::Clipboard_WriteClipboardData_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Clipboard_WriteClipboardData_ResponseParamsDataView {
    public:
        Clipboard_WriteClipboardData_ResponseParamsDataView() { }

        Clipboard_WriteClipboardData_ResponseParamsDataView(
            internal::Clipboard_WriteClipboardData_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint64_t sequence() const
        {
            return data_->sequence;
        }

    private:
        internal::Clipboard_WriteClipboardData_ResponseParams_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace ui

namespace std {

template <>
struct hash<::ui::mojom::Clipboard_Type>
    : public mojo::internal::EnumHashImpl<::ui::mojom::Clipboard_Type> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::ui::mojom::Clipboard_Type, ::ui::mojom::Clipboard_Type> {
    static ::ui::mojom::Clipboard_Type ToMojom(::ui::mojom::Clipboard_Type input) { return input; }
    static bool FromMojom(::ui::mojom::Clipboard_Type input, ::ui::mojom::Clipboard_Type* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::Clipboard_Type, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::ui::mojom::Clipboard_Type, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::ui::mojom::Clipboard_Type>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace ui {
namespace mojom {

    inline void Clipboard_GetAvailableMimeTypes_ResponseParamsDataView::GetTypesDataView(
        mojo::ArrayDataView<mojo::StringDataView>* output)
    {
        auto pointer = data_->types.Get();
        *output = mojo::ArrayDataView<mojo::StringDataView>(pointer, context_);
    }

    inline void Clipboard_ReadClipboardData_ParamsDataView::GetMimeTypeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->mime_type.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Clipboard_ReadClipboardData_ResponseParamsDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void Clipboard_WriteClipboardData_ParamsDataView::GetDataDataView(
        mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>(pointer, context_);
    }

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_CLIPBOARD_MOJOM_SHARED_H_
