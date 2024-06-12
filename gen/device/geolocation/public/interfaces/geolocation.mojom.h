// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_GEOLOCATION_PUBLIC_INTERFACES_GEOLOCATION_MOJOM_H_
#define DEVICE_GEOLOCATION_PUBLIC_INTERFACES_GEOLOCATION_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/geolocation/public/interfaces/geolocation.mojom-shared.h"
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
#include <string>
#include <vector>

namespace device {
namespace mojom {
    class GeolocationService;
    using GeolocationServicePtr = mojo::InterfacePtr<GeolocationService>;
    using GeolocationServicePtrInfo = mojo::InterfacePtrInfo<GeolocationService>;
    using ThreadSafeGeolocationServicePtr = mojo::ThreadSafeInterfacePtr<GeolocationService>;
    using GeolocationServiceRequest = mojo::InterfaceRequest<GeolocationService>;
    using GeolocationServiceAssociatedPtr = mojo::AssociatedInterfacePtr<GeolocationService>;
    using ThreadSafeGeolocationServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<GeolocationService>;
    using GeolocationServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<GeolocationService>;
    using GeolocationServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<GeolocationService>;

    class Geoposition;
    using GeopositionPtr = mojo::StructPtr<Geoposition>;

    class GeolocationServiceProxy;

    template <typename ImplRefTraits>
    class GeolocationServiceStub;

    class GeolocationServiceRequestValidator;
    class GeolocationServiceResponseValidator;

    class GeolocationService
        : public GeolocationServiceInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = GeolocationServiceProxy;

        template <typename ImplRefTraits>
        using Stub_ = GeolocationServiceStub<ImplRefTraits>;

        using RequestValidator_ = GeolocationServiceRequestValidator;
        using ResponseValidator_ = GeolocationServiceResponseValidator;
        enum MethodMinVersions : uint32_t {
            kSetHighAccuracyMinVersion = 0,
            kQueryNextPositionMinVersion = 0,
        };
        virtual ~GeolocationService() { }

        virtual void SetHighAccuracy(bool high_accuracy) = 0;

        using QueryNextPositionCallback = base::Callback<void(GeopositionPtr)>;
        virtual void QueryNextPosition(const QueryNextPositionCallback& callback) = 0;
    };

    class GeolocationServiceProxy
        : public GeolocationService {
    public:
        explicit GeolocationServiceProxy(mojo::MessageReceiverWithResponder* receiver);
        void SetHighAccuracy(bool high_accuracy) override;
        void QueryNextPosition(const QueryNextPositionCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class GeolocationServiceStubDispatch {
    public:
        static bool Accept(GeolocationService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(GeolocationService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<GeolocationService>>
    class GeolocationServiceStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        GeolocationServiceStub() { }
        ~GeolocationServiceStub() override { }

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
            return GeolocationServiceStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return GeolocationServiceStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class GeolocationServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class GeolocationServiceResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class Geoposition {
    public:
        using DataView = GeopositionDataView;
        using Data_ = internal::Geoposition_Data;
        using ErrorCode = Geoposition_ErrorCode;

        static GeopositionPtr New();

        template <typename U>
        static GeopositionPtr From(const U& u)
        {
            return mojo::TypeConverter<GeopositionPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Geoposition>::Convert(*this);
        }

        Geoposition();
        ~Geoposition();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = GeopositionPtr>
        GeopositionPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Geoposition>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Geoposition::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Geoposition::DataView, std::vector<uint8_t>>(
                input, output);
        }

        bool valid;
        double latitude;
        double longitude;
        double altitude;
        double accuracy;
        double altitude_accuracy;
        double heading;
        double speed;
        double timestamp;
        Geoposition::ErrorCode error_code;
        std::string error_message;
    };

    template <typename StructPtrType>
    GeopositionPtr Geoposition::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->valid = mojo::internal::Clone(valid);
        rv->latitude = mojo::internal::Clone(latitude);
        rv->longitude = mojo::internal::Clone(longitude);
        rv->altitude = mojo::internal::Clone(altitude);
        rv->accuracy = mojo::internal::Clone(accuracy);
        rv->altitude_accuracy = mojo::internal::Clone(altitude_accuracy);
        rv->heading = mojo::internal::Clone(heading);
        rv->speed = mojo::internal::Clone(speed);
        rv->timestamp = mojo::internal::Clone(timestamp);
        rv->error_code = mojo::internal::Clone(error_code);
        rv->error_message = mojo::internal::Clone(error_message);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Geoposition>::value>::type*>
    bool Geoposition::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->valid, other.valid))
            return false;
        if (!mojo::internal::Equals(this->latitude, other.latitude))
            return false;
        if (!mojo::internal::Equals(this->longitude, other.longitude))
            return false;
        if (!mojo::internal::Equals(this->altitude, other.altitude))
            return false;
        if (!mojo::internal::Equals(this->accuracy, other.accuracy))
            return false;
        if (!mojo::internal::Equals(this->altitude_accuracy, other.altitude_accuracy))
            return false;
        if (!mojo::internal::Equals(this->heading, other.heading))
            return false;
        if (!mojo::internal::Equals(this->speed, other.speed))
            return false;
        if (!mojo::internal::Equals(this->timestamp, other.timestamp))
            return false;
        if (!mojo::internal::Equals(this->error_code, other.error_code))
            return false;
        if (!mojo::internal::Equals(this->error_message, other.error_message))
            return false;
        return true;
    }

} // namespace mojom
} // namespace device

namespace mojo {

template <>
struct StructTraits<::device::mojom::Geoposition::DataView,
    ::device::mojom::GeopositionPtr> {
    static bool IsNull(const ::device::mojom::GeopositionPtr& input) { return !input; }
    static void SetToNull(::device::mojom::GeopositionPtr* output) { output->reset(); }

    static decltype(::device::mojom::Geoposition::valid) valid(
        const ::device::mojom::GeopositionPtr& input)
    {
        return input->valid;
    }

    static decltype(::device::mojom::Geoposition::latitude) latitude(
        const ::device::mojom::GeopositionPtr& input)
    {
        return input->latitude;
    }

    static decltype(::device::mojom::Geoposition::longitude) longitude(
        const ::device::mojom::GeopositionPtr& input)
    {
        return input->longitude;
    }

    static decltype(::device::mojom::Geoposition::altitude) altitude(
        const ::device::mojom::GeopositionPtr& input)
    {
        return input->altitude;
    }

    static decltype(::device::mojom::Geoposition::accuracy) accuracy(
        const ::device::mojom::GeopositionPtr& input)
    {
        return input->accuracy;
    }

    static decltype(::device::mojom::Geoposition::altitude_accuracy) altitude_accuracy(
        const ::device::mojom::GeopositionPtr& input)
    {
        return input->altitude_accuracy;
    }

    static decltype(::device::mojom::Geoposition::heading) heading(
        const ::device::mojom::GeopositionPtr& input)
    {
        return input->heading;
    }

    static decltype(::device::mojom::Geoposition::speed) speed(
        const ::device::mojom::GeopositionPtr& input)
    {
        return input->speed;
    }

    static decltype(::device::mojom::Geoposition::timestamp) timestamp(
        const ::device::mojom::GeopositionPtr& input)
    {
        return input->timestamp;
    }

    static decltype(::device::mojom::Geoposition::error_code) error_code(
        const ::device::mojom::GeopositionPtr& input)
    {
        return input->error_code;
    }

    static const decltype(::device::mojom::Geoposition::error_message)& error_message(
        const ::device::mojom::GeopositionPtr& input)
    {
        return input->error_message;
    }

    static bool Read(::device::mojom::Geoposition::DataView input, ::device::mojom::GeopositionPtr* output);
};

} // namespace mojo

#endif // DEVICE_GEOLOCATION_PUBLIC_INTERFACES_GEOLOCATION_MOJOM_H_