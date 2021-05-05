// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_MOJOM_H_
#define SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_MOJOM_H_

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
#include "services/shape_detection/public/interfaces/facedetection.mojom-shared.h"
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
    class FaceDetection;
    using FaceDetectionPtr = mojo::InterfacePtr<FaceDetection>;
    using FaceDetectionPtrInfo = mojo::InterfacePtrInfo<FaceDetection>;
    using ThreadSafeFaceDetectionPtr = mojo::ThreadSafeInterfacePtr<FaceDetection>;
    using FaceDetectionRequest = mojo::InterfaceRequest<FaceDetection>;
    using FaceDetectionAssociatedPtr = mojo::AssociatedInterfacePtr<FaceDetection>;
    using ThreadSafeFaceDetectionAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<FaceDetection>;
    using FaceDetectionAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<FaceDetection>;
    using FaceDetectionAssociatedRequest = mojo::AssociatedInterfaceRequest<FaceDetection>;

    class FaceDetectionResult;
    using FaceDetectionResultPtr = mojo::StructPtr<FaceDetectionResult>;

    class FaceDetectorOptions;
    using FaceDetectorOptionsPtr = mojo::InlinedStructPtr<FaceDetectorOptions>;

    class FaceDetectionProxy;

    template <typename ImplRefTraits>
    class FaceDetectionStub;

    class FaceDetectionRequestValidator;
    class FaceDetectionResponseValidator;

    class FaceDetection
        : public FaceDetectionInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = FaceDetectionProxy;

        template <typename ImplRefTraits>
        using Stub_ = FaceDetectionStub<ImplRefTraits>;

        using RequestValidator_ = FaceDetectionRequestValidator;
        using ResponseValidator_ = FaceDetectionResponseValidator;
        enum MethodMinVersions : uint32_t {
            kDetectMinVersion = 0,
        };
        virtual ~FaceDetection() { }

        using DetectCallback = base::Callback<void(FaceDetectionResultPtr)>;
        virtual void Detect(mojo::ScopedSharedBufferHandle frame_data, uint32_t width, uint32_t height, const DetectCallback& callback) = 0;
    };

    class FaceDetectionProxy
        : public FaceDetection {
    public:
        explicit FaceDetectionProxy(mojo::MessageReceiverWithResponder* receiver);
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
    class FaceDetectionStubDispatch {
    public:
        static bool Accept(FaceDetection* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(FaceDetection* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<FaceDetection>>
    class FaceDetectionStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        FaceDetectionStub() { }
        ~FaceDetectionStub() override { }

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
            return FaceDetectionStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return FaceDetectionStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class FaceDetectionRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class FaceDetectionResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class FaceDetectorOptions {
    public:
        using DataView = FaceDetectorOptionsDataView;
        using Data_ = internal::FaceDetectorOptions_Data;

        static FaceDetectorOptionsPtr New();

        template <typename U>
        static FaceDetectorOptionsPtr From(const U& u)
        {
            return mojo::TypeConverter<FaceDetectorOptionsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, FaceDetectorOptions>::Convert(*this);
        }

        FaceDetectorOptions();
        ~FaceDetectorOptions();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = FaceDetectorOptionsPtr>
        FaceDetectorOptionsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, FaceDetectorOptions>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                FaceDetectorOptions::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                FaceDetectorOptions::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t max_detected_faces;
        bool fast_mode;
    };

    class FaceDetectionResult {
    public:
        using DataView = FaceDetectionResultDataView;
        using Data_ = internal::FaceDetectionResult_Data;

        static FaceDetectionResultPtr New();

        template <typename U>
        static FaceDetectionResultPtr From(const U& u)
        {
            return mojo::TypeConverter<FaceDetectionResultPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, FaceDetectionResult>::Convert(*this);
        }

        FaceDetectionResult();
        ~FaceDetectionResult();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = FaceDetectionResultPtr>
        FaceDetectionResultPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, FaceDetectionResult>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                FaceDetectionResult::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                FaceDetectionResult::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::vector<gfx::RectF> bounding_boxes;
    };

    template <typename StructPtrType>
    FaceDetectionResultPtr FaceDetectionResult::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->bounding_boxes = mojo::internal::Clone(bounding_boxes);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, FaceDetectionResult>::value>::type*>
    bool FaceDetectionResult::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->bounding_boxes, other.bounding_boxes))
            return false;
        return true;
    }
    template <typename StructPtrType>
    FaceDetectorOptionsPtr FaceDetectorOptions::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->max_detected_faces = mojo::internal::Clone(max_detected_faces);
        rv->fast_mode = mojo::internal::Clone(fast_mode);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, FaceDetectorOptions>::value>::type*>
    bool FaceDetectorOptions::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->max_detected_faces, other.max_detected_faces))
            return false;
        if (!mojo::internal::Equals(this->fast_mode, other.fast_mode))
            return false;
        return true;
    }

} // namespace mojom
} // namespace shape_detection

namespace mojo {

template <>
struct StructTraits<::shape_detection::mojom::FaceDetectionResult::DataView,
    ::shape_detection::mojom::FaceDetectionResultPtr> {
    static bool IsNull(const ::shape_detection::mojom::FaceDetectionResultPtr& input) { return !input; }
    static void SetToNull(::shape_detection::mojom::FaceDetectionResultPtr* output) { output->reset(); }

    static const decltype(::shape_detection::mojom::FaceDetectionResult::bounding_boxes)& bounding_boxes(
        const ::shape_detection::mojom::FaceDetectionResultPtr& input)
    {
        return input->bounding_boxes;
    }

    static bool Read(::shape_detection::mojom::FaceDetectionResult::DataView input, ::shape_detection::mojom::FaceDetectionResultPtr* output);
};

template <>
struct StructTraits<::shape_detection::mojom::FaceDetectorOptions::DataView,
    ::shape_detection::mojom::FaceDetectorOptionsPtr> {
    static bool IsNull(const ::shape_detection::mojom::FaceDetectorOptionsPtr& input) { return !input; }
    static void SetToNull(::shape_detection::mojom::FaceDetectorOptionsPtr* output) { output->reset(); }

    static decltype(::shape_detection::mojom::FaceDetectorOptions::max_detected_faces) max_detected_faces(
        const ::shape_detection::mojom::FaceDetectorOptionsPtr& input)
    {
        return input->max_detected_faces;
    }

    static decltype(::shape_detection::mojom::FaceDetectorOptions::fast_mode) fast_mode(
        const ::shape_detection::mojom::FaceDetectorOptionsPtr& input)
    {
        return input->fast_mode;
    }

    static bool Read(::shape_detection::mojom::FaceDetectorOptions::DataView input, ::shape_detection::mojom::FaceDetectorOptionsPtr* output);
};

} // namespace mojo

#endif // SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_MOJOM_H_