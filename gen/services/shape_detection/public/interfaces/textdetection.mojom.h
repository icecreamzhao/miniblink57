// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_TEXTDETECTION_MOJOM_H_
#define SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_TEXTDETECTION_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
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
#include "services/shape_detection/public/interfaces/textdetection.mojom-shared.h"
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
#include <string>
#include <vector>

namespace shape_detection {
namespace mojom {
    class TextDetection;
    using TextDetectionPtr = mojo::InterfacePtr<TextDetection>;
    using TextDetectionPtrInfo = mojo::InterfacePtrInfo<TextDetection>;
    using ThreadSafeTextDetectionPtr = mojo::ThreadSafeInterfacePtr<TextDetection>;
    using TextDetectionRequest = mojo::InterfaceRequest<TextDetection>;
    using TextDetectionAssociatedPtr = mojo::AssociatedInterfacePtr<TextDetection>;
    using ThreadSafeTextDetectionAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<TextDetection>;
    using TextDetectionAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<TextDetection>;
    using TextDetectionAssociatedRequest = mojo::AssociatedInterfaceRequest<TextDetection>;

    class TextDetectionResult;
    using TextDetectionResultPtr = mojo::StructPtr<TextDetectionResult>;

    class TextDetectionProxy;

    template <typename ImplRefTraits>
    class TextDetectionStub;

    class TextDetectionRequestValidator;
    class TextDetectionResponseValidator;

    class TextDetection
        : public TextDetectionInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = TextDetectionProxy;

        template <typename ImplRefTraits>
        using Stub_ = TextDetectionStub<ImplRefTraits>;

        using RequestValidator_ = TextDetectionRequestValidator;
        using ResponseValidator_ = TextDetectionResponseValidator;
        enum MethodMinVersions : uint32_t {
            kDetectMinVersion = 0,
        };
        virtual ~TextDetection() { }

        using DetectCallback = base::Callback<void(std::vector<TextDetectionResultPtr>)>;
        virtual void Detect(mojo::ScopedSharedBufferHandle frame_data, uint32_t width, uint32_t height, const DetectCallback& callback) = 0;
    };

    class TextDetectionProxy
        : public TextDetection {
    public:
        explicit TextDetectionProxy(mojo::MessageReceiverWithResponder* receiver);
        void Detect(mojo::ScopedSharedBufferHandle frame_data, uint32_t width, uint32_t height, const DetectCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class TextDetectionStubDispatch {
    public:
        static bool Accept(TextDetection* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(TextDetection* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<TextDetection>>
    class TextDetectionStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        TextDetectionStub() { }
        ~TextDetectionStub() override { }

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
            return TextDetectionStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return TextDetectionStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class TextDetectionRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class TextDetectionResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class TextDetectionResult {
    public:
        using DataView = TextDetectionResultDataView;
        using Data_ = internal::TextDetectionResult_Data;

        static TextDetectionResultPtr New();

        template <typename U>
        static TextDetectionResultPtr From(const U& u)
        {
            return mojo::TypeConverter<TextDetectionResultPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, TextDetectionResult>::Convert(*this);
        }

        TextDetectionResult();
        ~TextDetectionResult();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = TextDetectionResultPtr>
        TextDetectionResultPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, TextDetectionResult>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                TextDetectionResult::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                TextDetectionResult::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string raw_value;
        gfx::RectF bounding_box;
    };

    template <typename StructPtrType>
    TextDetectionResultPtr TextDetectionResult::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->raw_value = mojo::internal::Clone(raw_value);
        rv->bounding_box = mojo::internal::Clone(bounding_box);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, TextDetectionResult>::value>::type*>
    bool TextDetectionResult::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->raw_value, other.raw_value))
            return false;
        if (!mojo::internal::Equals(this->bounding_box, other.bounding_box))
            return false;
        return true;
    }

} // namespace mojom
} // namespace shape_detection

namespace mojo {

template <>
struct StructTraits<::shape_detection::mojom::TextDetectionResult::DataView,
    ::shape_detection::mojom::TextDetectionResultPtr> {
    static bool IsNull(const ::shape_detection::mojom::TextDetectionResultPtr& input) { return !input; }
    static void SetToNull(::shape_detection::mojom::TextDetectionResultPtr* output) { output->reset(); }

    static const decltype(::shape_detection::mojom::TextDetectionResult::raw_value)& raw_value(
        const ::shape_detection::mojom::TextDetectionResultPtr& input)
    {
        return input->raw_value;
    }

    static const decltype(::shape_detection::mojom::TextDetectionResult::bounding_box)& bounding_box(
        const ::shape_detection::mojom::TextDetectionResultPtr& input)
    {
        return input->bounding_box;
    }

    static bool Read(::shape_detection::mojom::TextDetectionResult::DataView input, ::shape_detection::mojom::TextDetectionResultPtr* output);
};

} // namespace mojo

#endif // SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_TEXTDETECTION_MOJOM_H_