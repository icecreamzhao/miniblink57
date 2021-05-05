// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_BARCODEDETECTION_MOJOM_H_
#define SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_BARCODEDETECTION_MOJOM_H_

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
#include "services/shape_detection/public/interfaces/barcodedetection.mojom-shared.h"
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
    class BarcodeDetection;
    using BarcodeDetectionPtr = mojo::InterfacePtr<BarcodeDetection>;
    using BarcodeDetectionPtrInfo = mojo::InterfacePtrInfo<BarcodeDetection>;
    using ThreadSafeBarcodeDetectionPtr = mojo::ThreadSafeInterfacePtr<BarcodeDetection>;
    using BarcodeDetectionRequest = mojo::InterfaceRequest<BarcodeDetection>;
    using BarcodeDetectionAssociatedPtr = mojo::AssociatedInterfacePtr<BarcodeDetection>;
    using ThreadSafeBarcodeDetectionAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<BarcodeDetection>;
    using BarcodeDetectionAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<BarcodeDetection>;
    using BarcodeDetectionAssociatedRequest = mojo::AssociatedInterfaceRequest<BarcodeDetection>;

    class BarcodeDetectionResult;
    using BarcodeDetectionResultPtr = mojo::StructPtr<BarcodeDetectionResult>;

    class BarcodeDetectionProxy;

    template <typename ImplRefTraits>
    class BarcodeDetectionStub;

    class BarcodeDetectionRequestValidator;
    class BarcodeDetectionResponseValidator;

    class BarcodeDetection
        : public BarcodeDetectionInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = BarcodeDetectionProxy;

        template <typename ImplRefTraits>
        using Stub_ = BarcodeDetectionStub<ImplRefTraits>;

        using RequestValidator_ = BarcodeDetectionRequestValidator;
        using ResponseValidator_ = BarcodeDetectionResponseValidator;
        enum MethodMinVersions : uint32_t {
            kDetectMinVersion = 0,
        };
        virtual ~BarcodeDetection() { }

        using DetectCallback = base::Callback<void(std::vector<BarcodeDetectionResultPtr>)>;
        virtual void Detect(mojo::ScopedSharedBufferHandle frame_data, uint32_t width, uint32_t height, const DetectCallback& callback) = 0;
    };

    class BarcodeDetectionProxy
        : public BarcodeDetection {
    public:
        explicit BarcodeDetectionProxy(mojo::MessageReceiverWithResponder* receiver);
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
    class BarcodeDetectionStubDispatch {
    public:
        static bool Accept(BarcodeDetection* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(BarcodeDetection* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<BarcodeDetection>>
    class BarcodeDetectionStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        BarcodeDetectionStub() { }
        ~BarcodeDetectionStub() override { }

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
            return BarcodeDetectionStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return BarcodeDetectionStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class BarcodeDetectionRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class BarcodeDetectionResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class BarcodeDetectionResult {
    public:
        using DataView = BarcodeDetectionResultDataView;
        using Data_ = internal::BarcodeDetectionResult_Data;

        static BarcodeDetectionResultPtr New();

        template <typename U>
        static BarcodeDetectionResultPtr From(const U& u)
        {
            return mojo::TypeConverter<BarcodeDetectionResultPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, BarcodeDetectionResult>::Convert(*this);
        }

        BarcodeDetectionResult();
        ~BarcodeDetectionResult();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = BarcodeDetectionResultPtr>
        BarcodeDetectionResultPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, BarcodeDetectionResult>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                BarcodeDetectionResult::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                BarcodeDetectionResult::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string raw_value;
        gfx::RectF bounding_box;
        std::vector<gfx::PointF> corner_points;
    };

    template <typename StructPtrType>
    BarcodeDetectionResultPtr BarcodeDetectionResult::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->raw_value = mojo::internal::Clone(raw_value);
        rv->bounding_box = mojo::internal::Clone(bounding_box);
        rv->corner_points = mojo::internal::Clone(corner_points);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, BarcodeDetectionResult>::value>::type*>
    bool BarcodeDetectionResult::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->raw_value, other.raw_value))
            return false;
        if (!mojo::internal::Equals(this->bounding_box, other.bounding_box))
            return false;
        if (!mojo::internal::Equals(this->corner_points, other.corner_points))
            return false;
        return true;
    }

} // namespace mojom
} // namespace shape_detection

namespace mojo {

template <>
struct StructTraits<::shape_detection::mojom::BarcodeDetectionResult::DataView,
    ::shape_detection::mojom::BarcodeDetectionResultPtr> {
    static bool IsNull(const ::shape_detection::mojom::BarcodeDetectionResultPtr& input) { return !input; }
    static void SetToNull(::shape_detection::mojom::BarcodeDetectionResultPtr* output) { output->reset(); }

    static const decltype(::shape_detection::mojom::BarcodeDetectionResult::raw_value)& raw_value(
        const ::shape_detection::mojom::BarcodeDetectionResultPtr& input)
    {
        return input->raw_value;
    }

    static const decltype(::shape_detection::mojom::BarcodeDetectionResult::bounding_box)& bounding_box(
        const ::shape_detection::mojom::BarcodeDetectionResultPtr& input)
    {
        return input->bounding_box;
    }

    static const decltype(::shape_detection::mojom::BarcodeDetectionResult::corner_points)& corner_points(
        const ::shape_detection::mojom::BarcodeDetectionResultPtr& input)
    {
        return input->corner_points;
    }

    static bool Read(::shape_detection::mojom::BarcodeDetectionResult::DataView input, ::shape_detection::mojom::BarcodeDetectionResultPtr* output);
};

} // namespace mojo

#endif // SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_BARCODEDETECTION_MOJOM_H_