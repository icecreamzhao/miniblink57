// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_CAPTURE_MOJO_IMAGE_CAPTURE_MOJOM_H_
#define MEDIA_CAPTURE_MOJO_IMAGE_CAPTURE_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "media/capture/mojo/image_capture.mojom-shared.h"
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

namespace media {
namespace mojom {
    class ImageCapture;
    using ImageCapturePtr = mojo::InterfacePtr<ImageCapture>;
    using ImageCapturePtrInfo = mojo::InterfacePtrInfo<ImageCapture>;
    using ThreadSafeImageCapturePtr = mojo::ThreadSafeInterfacePtr<ImageCapture>;
    using ImageCaptureRequest = mojo::InterfaceRequest<ImageCapture>;
    using ImageCaptureAssociatedPtr = mojo::AssociatedInterfacePtr<ImageCapture>;
    using ThreadSafeImageCaptureAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<ImageCapture>;
    using ImageCaptureAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<ImageCapture>;
    using ImageCaptureAssociatedRequest = mojo::AssociatedInterfaceRequest<ImageCapture>;

    class Range;
    using RangePtr = mojo::InlinedStructPtr<Range>;

    class PhotoCapabilities;
    using PhotoCapabilitiesPtr = mojo::StructPtr<PhotoCapabilities>;

    class Point2D;
    using Point2DPtr = mojo::InlinedStructPtr<Point2D>;

    class PhotoSettings;
    using PhotoSettingsPtr = mojo::StructPtr<PhotoSettings>;

    class Blob;
    using BlobPtr = mojo::StructPtr<Blob>;

    class ImageCaptureProxy;

    template <typename ImplRefTraits>
    class ImageCaptureStub;

    class ImageCaptureRequestValidator;
    class ImageCaptureResponseValidator;

    class ImageCapture
        : public ImageCaptureInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = ImageCaptureProxy;

        template <typename ImplRefTraits>
        using Stub_ = ImageCaptureStub<ImplRefTraits>;

        using RequestValidator_ = ImageCaptureRequestValidator;
        using ResponseValidator_ = ImageCaptureResponseValidator;
        enum MethodMinVersions : uint32_t {
            kGetCapabilitiesMinVersion = 0,
            kSetOptionsMinVersion = 0,
            kTakePhotoMinVersion = 0,
        };
        virtual ~ImageCapture() { }

        using GetCapabilitiesCallback = base::Callback<void(PhotoCapabilitiesPtr)>;
        virtual void GetCapabilities(const std::string& source_id, const GetCapabilitiesCallback& callback) = 0;

        using SetOptionsCallback = base::Callback<void(bool)>;
        virtual void SetOptions(const std::string& source_id, PhotoSettingsPtr settings, const SetOptionsCallback& callback) = 0;

        using TakePhotoCallback = base::Callback<void(BlobPtr)>;
        virtual void TakePhoto(const std::string& source_id, const TakePhotoCallback& callback) = 0;
    };

    class ImageCaptureProxy
        : public ImageCapture {
    public:
        explicit ImageCaptureProxy(mojo::MessageReceiverWithResponder* receiver);
        void GetCapabilities(const std::string& source_id, const GetCapabilitiesCallback& callback) override;
        void SetOptions(const std::string& source_id, PhotoSettingsPtr settings, const SetOptionsCallback& callback) override;
        void TakePhoto(const std::string& source_id, const TakePhotoCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class ImageCaptureStubDispatch {
    public:
        static bool Accept(ImageCapture* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(ImageCapture* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<ImageCapture>>
    class ImageCaptureStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        ImageCaptureStub() { }
        ~ImageCaptureStub() override { }

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
            return ImageCaptureStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ImageCaptureStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class ImageCaptureRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class ImageCaptureResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class Range {
    public:
        using DataView = RangeDataView;
        using Data_ = internal::Range_Data;

        static RangePtr New();

        template <typename U>
        static RangePtr From(const U& u)
        {
            return mojo::TypeConverter<RangePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Range>::Convert(*this);
        }

        Range();
        ~Range();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = RangePtr>
        RangePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Range>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Range::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Range::DataView, std::vector<uint8_t>>(
                input, output);
        }

        double max;
        double min;
        double current;
        double step;
    };

    class Point2D {
    public:
        using DataView = Point2DDataView;
        using Data_ = internal::Point2D_Data;

        static Point2DPtr New();

        template <typename U>
        static Point2DPtr From(const U& u)
        {
            return mojo::TypeConverter<Point2DPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Point2D>::Convert(*this);
        }

        Point2D();
        ~Point2D();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = Point2DPtr>
        Point2DPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Point2D>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Point2D::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Point2D::DataView, std::vector<uint8_t>>(
                input, output);
        }

        float x;
        float y;
    };

    class PhotoCapabilities {
    public:
        using DataView = PhotoCapabilitiesDataView;
        using Data_ = internal::PhotoCapabilities_Data;

        static PhotoCapabilitiesPtr New();

        template <typename U>
        static PhotoCapabilitiesPtr From(const U& u)
        {
            return mojo::TypeConverter<PhotoCapabilitiesPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PhotoCapabilities>::Convert(*this);
        }

        PhotoCapabilities();
        ~PhotoCapabilities();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PhotoCapabilitiesPtr>
        PhotoCapabilitiesPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PhotoCapabilities>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PhotoCapabilities::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PhotoCapabilities::DataView, std::vector<uint8_t>>(
                input, output);
        }

        MeteringMode white_balance_mode;
        RangePtr color_temperature;
        MeteringMode exposure_mode;
        RangePtr exposure_compensation;
        RangePtr iso;
        bool red_eye_reduction;
        MeteringMode focus_mode;
        RangePtr brightness;
        RangePtr contrast;
        RangePtr saturation;
        RangePtr sharpness;
        RangePtr height;
        RangePtr width;
        RangePtr zoom;
        FillLightMode fill_light_mode;

    private:
        DISALLOW_COPY_AND_ASSIGN(PhotoCapabilities);
    };

    class PhotoSettings {
    public:
        using DataView = PhotoSettingsDataView;
        using Data_ = internal::PhotoSettings_Data;

        static PhotoSettingsPtr New();

        template <typename U>
        static PhotoSettingsPtr From(const U& u)
        {
            return mojo::TypeConverter<PhotoSettingsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PhotoSettings>::Convert(*this);
        }

        PhotoSettings();
        ~PhotoSettings();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PhotoSettingsPtr>
        PhotoSettingsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PhotoSettings>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PhotoSettings::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PhotoSettings::DataView, std::vector<uint8_t>>(
                input, output);
        }

        bool has_white_balance_mode;
        MeteringMode white_balance_mode;
        bool has_color_temperature;
        double color_temperature;
        bool has_exposure_mode;
        MeteringMode exposure_mode;
        bool has_exposure_compensation;
        double exposure_compensation;
        bool has_iso;
        double iso;
        bool has_red_eye_reduction;
        bool red_eye_reduction;
        bool has_focus_mode;
        MeteringMode focus_mode;
        std::vector<Point2DPtr> points_of_interest;
        bool has_brightness;
        double brightness;
        bool has_contrast;
        double contrast;
        bool has_saturation;
        double saturation;
        bool has_sharpness;
        double sharpness;
        bool has_zoom;
        double zoom;
        bool has_width;
        double width;
        bool has_height;
        double height;
        bool has_fill_light_mode;
        FillLightMode fill_light_mode;

    private:
        DISALLOW_COPY_AND_ASSIGN(PhotoSettings);
    };

    class Blob {
    public:
        using DataView = BlobDataView;
        using Data_ = internal::Blob_Data;

        static BlobPtr New();

        template <typename U>
        static BlobPtr From(const U& u)
        {
            return mojo::TypeConverter<BlobPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Blob>::Convert(*this);
        }

        Blob();
        ~Blob();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = BlobPtr>
        BlobPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Blob>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Blob::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Blob::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string mime_type;
        std::vector<uint8_t> data;
    };

    template <typename StructPtrType>
    RangePtr Range::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->max = mojo::internal::Clone(max);
        rv->min = mojo::internal::Clone(min);
        rv->current = mojo::internal::Clone(current);
        rv->step = mojo::internal::Clone(step);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Range>::value>::type*>
    bool Range::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->max, other.max))
            return false;
        if (!mojo::internal::Equals(this->min, other.min))
            return false;
        if (!mojo::internal::Equals(this->current, other.current))
            return false;
        if (!mojo::internal::Equals(this->step, other.step))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PhotoCapabilitiesPtr PhotoCapabilities::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->white_balance_mode = mojo::internal::Clone(white_balance_mode);
        rv->color_temperature = mojo::internal::Clone(color_temperature);
        rv->exposure_mode = mojo::internal::Clone(exposure_mode);
        rv->exposure_compensation = mojo::internal::Clone(exposure_compensation);
        rv->iso = mojo::internal::Clone(iso);
        rv->red_eye_reduction = mojo::internal::Clone(red_eye_reduction);
        rv->focus_mode = mojo::internal::Clone(focus_mode);
        rv->brightness = mojo::internal::Clone(brightness);
        rv->contrast = mojo::internal::Clone(contrast);
        rv->saturation = mojo::internal::Clone(saturation);
        rv->sharpness = mojo::internal::Clone(sharpness);
        rv->height = mojo::internal::Clone(height);
        rv->width = mojo::internal::Clone(width);
        rv->zoom = mojo::internal::Clone(zoom);
        rv->fill_light_mode = mojo::internal::Clone(fill_light_mode);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PhotoCapabilities>::value>::type*>
    bool PhotoCapabilities::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->white_balance_mode, other.white_balance_mode))
            return false;
        if (!mojo::internal::Equals(this->color_temperature, other.color_temperature))
            return false;
        if (!mojo::internal::Equals(this->exposure_mode, other.exposure_mode))
            return false;
        if (!mojo::internal::Equals(this->exposure_compensation, other.exposure_compensation))
            return false;
        if (!mojo::internal::Equals(this->iso, other.iso))
            return false;
        if (!mojo::internal::Equals(this->red_eye_reduction, other.red_eye_reduction))
            return false;
        if (!mojo::internal::Equals(this->focus_mode, other.focus_mode))
            return false;
        if (!mojo::internal::Equals(this->brightness, other.brightness))
            return false;
        if (!mojo::internal::Equals(this->contrast, other.contrast))
            return false;
        if (!mojo::internal::Equals(this->saturation, other.saturation))
            return false;
        if (!mojo::internal::Equals(this->sharpness, other.sharpness))
            return false;
        if (!mojo::internal::Equals(this->height, other.height))
            return false;
        if (!mojo::internal::Equals(this->width, other.width))
            return false;
        if (!mojo::internal::Equals(this->zoom, other.zoom))
            return false;
        if (!mojo::internal::Equals(this->fill_light_mode, other.fill_light_mode))
            return false;
        return true;
    }
    template <typename StructPtrType>
    Point2DPtr Point2D::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->x = mojo::internal::Clone(x);
        rv->y = mojo::internal::Clone(y);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Point2D>::value>::type*>
    bool Point2D::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->x, other.x))
            return false;
        if (!mojo::internal::Equals(this->y, other.y))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PhotoSettingsPtr PhotoSettings::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->has_white_balance_mode = mojo::internal::Clone(has_white_balance_mode);
        rv->white_balance_mode = mojo::internal::Clone(white_balance_mode);
        rv->has_color_temperature = mojo::internal::Clone(has_color_temperature);
        rv->color_temperature = mojo::internal::Clone(color_temperature);
        rv->has_exposure_mode = mojo::internal::Clone(has_exposure_mode);
        rv->exposure_mode = mojo::internal::Clone(exposure_mode);
        rv->has_exposure_compensation = mojo::internal::Clone(has_exposure_compensation);
        rv->exposure_compensation = mojo::internal::Clone(exposure_compensation);
        rv->has_iso = mojo::internal::Clone(has_iso);
        rv->iso = mojo::internal::Clone(iso);
        rv->has_red_eye_reduction = mojo::internal::Clone(has_red_eye_reduction);
        rv->red_eye_reduction = mojo::internal::Clone(red_eye_reduction);
        rv->has_focus_mode = mojo::internal::Clone(has_focus_mode);
        rv->focus_mode = mojo::internal::Clone(focus_mode);
        rv->points_of_interest = mojo::internal::Clone(points_of_interest);
        rv->has_brightness = mojo::internal::Clone(has_brightness);
        rv->brightness = mojo::internal::Clone(brightness);
        rv->has_contrast = mojo::internal::Clone(has_contrast);
        rv->contrast = mojo::internal::Clone(contrast);
        rv->has_saturation = mojo::internal::Clone(has_saturation);
        rv->saturation = mojo::internal::Clone(saturation);
        rv->has_sharpness = mojo::internal::Clone(has_sharpness);
        rv->sharpness = mojo::internal::Clone(sharpness);
        rv->has_zoom = mojo::internal::Clone(has_zoom);
        rv->zoom = mojo::internal::Clone(zoom);
        rv->has_width = mojo::internal::Clone(has_width);
        rv->width = mojo::internal::Clone(width);
        rv->has_height = mojo::internal::Clone(has_height);
        rv->height = mojo::internal::Clone(height);
        rv->has_fill_light_mode = mojo::internal::Clone(has_fill_light_mode);
        rv->fill_light_mode = mojo::internal::Clone(fill_light_mode);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PhotoSettings>::value>::type*>
    bool PhotoSettings::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->has_white_balance_mode, other.has_white_balance_mode))
            return false;
        if (!mojo::internal::Equals(this->white_balance_mode, other.white_balance_mode))
            return false;
        if (!mojo::internal::Equals(this->has_color_temperature, other.has_color_temperature))
            return false;
        if (!mojo::internal::Equals(this->color_temperature, other.color_temperature))
            return false;
        if (!mojo::internal::Equals(this->has_exposure_mode, other.has_exposure_mode))
            return false;
        if (!mojo::internal::Equals(this->exposure_mode, other.exposure_mode))
            return false;
        if (!mojo::internal::Equals(this->has_exposure_compensation, other.has_exposure_compensation))
            return false;
        if (!mojo::internal::Equals(this->exposure_compensation, other.exposure_compensation))
            return false;
        if (!mojo::internal::Equals(this->has_iso, other.has_iso))
            return false;
        if (!mojo::internal::Equals(this->iso, other.iso))
            return false;
        if (!mojo::internal::Equals(this->has_red_eye_reduction, other.has_red_eye_reduction))
            return false;
        if (!mojo::internal::Equals(this->red_eye_reduction, other.red_eye_reduction))
            return false;
        if (!mojo::internal::Equals(this->has_focus_mode, other.has_focus_mode))
            return false;
        if (!mojo::internal::Equals(this->focus_mode, other.focus_mode))
            return false;
        if (!mojo::internal::Equals(this->points_of_interest, other.points_of_interest))
            return false;
        if (!mojo::internal::Equals(this->has_brightness, other.has_brightness))
            return false;
        if (!mojo::internal::Equals(this->brightness, other.brightness))
            return false;
        if (!mojo::internal::Equals(this->has_contrast, other.has_contrast))
            return false;
        if (!mojo::internal::Equals(this->contrast, other.contrast))
            return false;
        if (!mojo::internal::Equals(this->has_saturation, other.has_saturation))
            return false;
        if (!mojo::internal::Equals(this->saturation, other.saturation))
            return false;
        if (!mojo::internal::Equals(this->has_sharpness, other.has_sharpness))
            return false;
        if (!mojo::internal::Equals(this->sharpness, other.sharpness))
            return false;
        if (!mojo::internal::Equals(this->has_zoom, other.has_zoom))
            return false;
        if (!mojo::internal::Equals(this->zoom, other.zoom))
            return false;
        if (!mojo::internal::Equals(this->has_width, other.has_width))
            return false;
        if (!mojo::internal::Equals(this->width, other.width))
            return false;
        if (!mojo::internal::Equals(this->has_height, other.has_height))
            return false;
        if (!mojo::internal::Equals(this->height, other.height))
            return false;
        if (!mojo::internal::Equals(this->has_fill_light_mode, other.has_fill_light_mode))
            return false;
        if (!mojo::internal::Equals(this->fill_light_mode, other.fill_light_mode))
            return false;
        return true;
    }
    template <typename StructPtrType>
    BlobPtr Blob::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->mime_type = mojo::internal::Clone(mime_type);
        rv->data = mojo::internal::Clone(data);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Blob>::value>::type*>
    bool Blob::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->mime_type, other.mime_type))
            return false;
        if (!mojo::internal::Equals(this->data, other.data))
            return false;
        return true;
    }

} // namespace mojom
} // namespace media

namespace mojo {

template <>
struct StructTraits<::media::mojom::Range::DataView,
    ::media::mojom::RangePtr> {
    static bool IsNull(const ::media::mojom::RangePtr& input) { return !input; }
    static void SetToNull(::media::mojom::RangePtr* output) { output->reset(); }

    static decltype(::media::mojom::Range::max) max(
        const ::media::mojom::RangePtr& input)
    {
        return input->max;
    }

    static decltype(::media::mojom::Range::min) min(
        const ::media::mojom::RangePtr& input)
    {
        return input->min;
    }

    static decltype(::media::mojom::Range::current) current(
        const ::media::mojom::RangePtr& input)
    {
        return input->current;
    }

    static decltype(::media::mojom::Range::step) step(
        const ::media::mojom::RangePtr& input)
    {
        return input->step;
    }

    static bool Read(::media::mojom::Range::DataView input, ::media::mojom::RangePtr* output);
};

template <>
struct StructTraits<::media::mojom::PhotoCapabilities::DataView,
    ::media::mojom::PhotoCapabilitiesPtr> {
    static bool IsNull(const ::media::mojom::PhotoCapabilitiesPtr& input) { return !input; }
    static void SetToNull(::media::mojom::PhotoCapabilitiesPtr* output) { output->reset(); }

    static decltype(::media::mojom::PhotoCapabilities::white_balance_mode) white_balance_mode(
        const ::media::mojom::PhotoCapabilitiesPtr& input)
    {
        return input->white_balance_mode;
    }

    static const decltype(::media::mojom::PhotoCapabilities::color_temperature)& color_temperature(
        const ::media::mojom::PhotoCapabilitiesPtr& input)
    {
        return input->color_temperature;
    }

    static decltype(::media::mojom::PhotoCapabilities::exposure_mode) exposure_mode(
        const ::media::mojom::PhotoCapabilitiesPtr& input)
    {
        return input->exposure_mode;
    }

    static const decltype(::media::mojom::PhotoCapabilities::exposure_compensation)& exposure_compensation(
        const ::media::mojom::PhotoCapabilitiesPtr& input)
    {
        return input->exposure_compensation;
    }

    static const decltype(::media::mojom::PhotoCapabilities::iso)& iso(
        const ::media::mojom::PhotoCapabilitiesPtr& input)
    {
        return input->iso;
    }

    static decltype(::media::mojom::PhotoCapabilities::red_eye_reduction) red_eye_reduction(
        const ::media::mojom::PhotoCapabilitiesPtr& input)
    {
        return input->red_eye_reduction;
    }

    static decltype(::media::mojom::PhotoCapabilities::focus_mode) focus_mode(
        const ::media::mojom::PhotoCapabilitiesPtr& input)
    {
        return input->focus_mode;
    }

    static const decltype(::media::mojom::PhotoCapabilities::brightness)& brightness(
        const ::media::mojom::PhotoCapabilitiesPtr& input)
    {
        return input->brightness;
    }

    static const decltype(::media::mojom::PhotoCapabilities::contrast)& contrast(
        const ::media::mojom::PhotoCapabilitiesPtr& input)
    {
        return input->contrast;
    }

    static const decltype(::media::mojom::PhotoCapabilities::saturation)& saturation(
        const ::media::mojom::PhotoCapabilitiesPtr& input)
    {
        return input->saturation;
    }

    static const decltype(::media::mojom::PhotoCapabilities::sharpness)& sharpness(
        const ::media::mojom::PhotoCapabilitiesPtr& input)
    {
        return input->sharpness;
    }

    static const decltype(::media::mojom::PhotoCapabilities::height)& height(
        const ::media::mojom::PhotoCapabilitiesPtr& input)
    {
        return input->height;
    }

    static const decltype(::media::mojom::PhotoCapabilities::width)& width(
        const ::media::mojom::PhotoCapabilitiesPtr& input)
    {
        return input->width;
    }

    static const decltype(::media::mojom::PhotoCapabilities::zoom)& zoom(
        const ::media::mojom::PhotoCapabilitiesPtr& input)
    {
        return input->zoom;
    }

    static decltype(::media::mojom::PhotoCapabilities::fill_light_mode) fill_light_mode(
        const ::media::mojom::PhotoCapabilitiesPtr& input)
    {
        return input->fill_light_mode;
    }

    static bool Read(::media::mojom::PhotoCapabilities::DataView input, ::media::mojom::PhotoCapabilitiesPtr* output);
};

template <>
struct StructTraits<::media::mojom::Point2D::DataView,
    ::media::mojom::Point2DPtr> {
    static bool IsNull(const ::media::mojom::Point2DPtr& input) { return !input; }
    static void SetToNull(::media::mojom::Point2DPtr* output) { output->reset(); }

    static decltype(::media::mojom::Point2D::x) x(
        const ::media::mojom::Point2DPtr& input)
    {
        return input->x;
    }

    static decltype(::media::mojom::Point2D::y) y(
        const ::media::mojom::Point2DPtr& input)
    {
        return input->y;
    }

    static bool Read(::media::mojom::Point2D::DataView input, ::media::mojom::Point2DPtr* output);
};

template <>
struct StructTraits<::media::mojom::PhotoSettings::DataView,
    ::media::mojom::PhotoSettingsPtr> {
    static bool IsNull(const ::media::mojom::PhotoSettingsPtr& input) { return !input; }
    static void SetToNull(::media::mojom::PhotoSettingsPtr* output) { output->reset(); }

    static decltype(::media::mojom::PhotoSettings::has_white_balance_mode) has_white_balance_mode(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->has_white_balance_mode;
    }

    static decltype(::media::mojom::PhotoSettings::white_balance_mode) white_balance_mode(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->white_balance_mode;
    }

    static decltype(::media::mojom::PhotoSettings::has_color_temperature) has_color_temperature(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->has_color_temperature;
    }

    static decltype(::media::mojom::PhotoSettings::color_temperature) color_temperature(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->color_temperature;
    }

    static decltype(::media::mojom::PhotoSettings::has_exposure_mode) has_exposure_mode(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->has_exposure_mode;
    }

    static decltype(::media::mojom::PhotoSettings::exposure_mode) exposure_mode(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->exposure_mode;
    }

    static decltype(::media::mojom::PhotoSettings::has_exposure_compensation) has_exposure_compensation(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->has_exposure_compensation;
    }

    static decltype(::media::mojom::PhotoSettings::exposure_compensation) exposure_compensation(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->exposure_compensation;
    }

    static decltype(::media::mojom::PhotoSettings::has_iso) has_iso(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->has_iso;
    }

    static decltype(::media::mojom::PhotoSettings::iso) iso(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->iso;
    }

    static decltype(::media::mojom::PhotoSettings::has_red_eye_reduction) has_red_eye_reduction(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->has_red_eye_reduction;
    }

    static decltype(::media::mojom::PhotoSettings::red_eye_reduction) red_eye_reduction(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->red_eye_reduction;
    }

    static decltype(::media::mojom::PhotoSettings::has_focus_mode) has_focus_mode(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->has_focus_mode;
    }

    static decltype(::media::mojom::PhotoSettings::focus_mode) focus_mode(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->focus_mode;
    }

    static const decltype(::media::mojom::PhotoSettings::points_of_interest)& points_of_interest(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->points_of_interest;
    }

    static decltype(::media::mojom::PhotoSettings::has_brightness) has_brightness(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->has_brightness;
    }

    static decltype(::media::mojom::PhotoSettings::brightness) brightness(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->brightness;
    }

    static decltype(::media::mojom::PhotoSettings::has_contrast) has_contrast(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->has_contrast;
    }

    static decltype(::media::mojom::PhotoSettings::contrast) contrast(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->contrast;
    }

    static decltype(::media::mojom::PhotoSettings::has_saturation) has_saturation(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->has_saturation;
    }

    static decltype(::media::mojom::PhotoSettings::saturation) saturation(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->saturation;
    }

    static decltype(::media::mojom::PhotoSettings::has_sharpness) has_sharpness(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->has_sharpness;
    }

    static decltype(::media::mojom::PhotoSettings::sharpness) sharpness(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->sharpness;
    }

    static decltype(::media::mojom::PhotoSettings::has_zoom) has_zoom(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->has_zoom;
    }

    static decltype(::media::mojom::PhotoSettings::zoom) zoom(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->zoom;
    }

    static decltype(::media::mojom::PhotoSettings::has_width) has_width(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->has_width;
    }

    static decltype(::media::mojom::PhotoSettings::width) width(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->width;
    }

    static decltype(::media::mojom::PhotoSettings::has_height) has_height(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->has_height;
    }

    static decltype(::media::mojom::PhotoSettings::height) height(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->height;
    }

    static decltype(::media::mojom::PhotoSettings::has_fill_light_mode) has_fill_light_mode(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->has_fill_light_mode;
    }

    static decltype(::media::mojom::PhotoSettings::fill_light_mode) fill_light_mode(
        const ::media::mojom::PhotoSettingsPtr& input)
    {
        return input->fill_light_mode;
    }

    static bool Read(::media::mojom::PhotoSettings::DataView input, ::media::mojom::PhotoSettingsPtr* output);
};

template <>
struct StructTraits<::media::mojom::Blob::DataView,
    ::media::mojom::BlobPtr> {
    static bool IsNull(const ::media::mojom::BlobPtr& input) { return !input; }
    static void SetToNull(::media::mojom::BlobPtr* output) { output->reset(); }

    static const decltype(::media::mojom::Blob::mime_type)& mime_type(
        const ::media::mojom::BlobPtr& input)
    {
        return input->mime_type;
    }

    static const decltype(::media::mojom::Blob::data)& data(
        const ::media::mojom::BlobPtr& input)
    {
        return input->data;
    }

    static bool Read(::media::mojom::Blob::DataView input, ::media::mojom::BlobPtr* output);
};

} // namespace mojo

#endif // MEDIA_CAPTURE_MOJO_IMAGE_CAPTURE_MOJOM_H_