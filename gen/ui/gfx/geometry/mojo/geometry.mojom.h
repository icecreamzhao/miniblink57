// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_GEOMETRY_MOJO_GEOMETRY_MOJOM_H_
#define UI_GFX_GEOMETRY_MOJO_GEOMETRY_MOJOM_H_

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
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"
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

namespace gfx {
namespace mojom {
    class Point;
    using PointPtr = mojo::InlinedStructPtr<Point>;

    class PointF;
    using PointFPtr = mojo::InlinedStructPtr<PointF>;

    class Size;
    using SizePtr = mojo::InlinedStructPtr<Size>;

    class SizeF;
    using SizeFPtr = mojo::InlinedStructPtr<SizeF>;

    class Rect;
    using RectPtr = mojo::InlinedStructPtr<Rect>;

    class RectF;
    using RectFPtr = mojo::InlinedStructPtr<RectF>;

    class Insets;
    using InsetsPtr = mojo::InlinedStructPtr<Insets>;

    class InsetsF;
    using InsetsFPtr = mojo::InlinedStructPtr<InsetsF>;

    class Vector2d;
    using Vector2dPtr = mojo::InlinedStructPtr<Vector2d>;

    class Vector2dF;
    using Vector2dFPtr = mojo::InlinedStructPtr<Vector2dF>;

    class Point {
    public:
        using DataView = PointDataView;
        using Data_ = internal::Point_Data;

        static PointPtr New();

        template <typename U>
        static PointPtr From(const U& u)
        {
            return mojo::TypeConverter<PointPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Point>::Convert(*this);
        }

        Point();
        ~Point();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PointPtr>
        PointPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Point>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Point::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Point::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int32_t x;
        int32_t y;
    };

    class PointF {
    public:
        using DataView = PointFDataView;
        using Data_ = internal::PointF_Data;

        static PointFPtr New();

        template <typename U>
        static PointFPtr From(const U& u)
        {
            return mojo::TypeConverter<PointFPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PointF>::Convert(*this);
        }

        PointF();
        ~PointF();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PointFPtr>
        PointFPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PointF>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PointF::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PointF::DataView, std::vector<uint8_t>>(
                input, output);
        }

        float x;
        float y;
    };

    class Size {
    public:
        using DataView = SizeDataView;
        using Data_ = internal::Size_Data;

        static SizePtr New();

        template <typename U>
        static SizePtr From(const U& u)
        {
            return mojo::TypeConverter<SizePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Size>::Convert(*this);
        }

        Size();
        ~Size();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = SizePtr>
        SizePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Size>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Size::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Size::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int32_t width;
        int32_t height;
    };

    class SizeF {
    public:
        using DataView = SizeFDataView;
        using Data_ = internal::SizeF_Data;

        static SizeFPtr New();

        template <typename U>
        static SizeFPtr From(const U& u)
        {
            return mojo::TypeConverter<SizeFPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, SizeF>::Convert(*this);
        }

        SizeF();
        ~SizeF();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = SizeFPtr>
        SizeFPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, SizeF>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                SizeF::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                SizeF::DataView, std::vector<uint8_t>>(
                input, output);
        }

        float width;
        float height;
    };

    class Rect {
    public:
        using DataView = RectDataView;
        using Data_ = internal::Rect_Data;

        static RectPtr New();

        template <typename U>
        static RectPtr From(const U& u)
        {
            return mojo::TypeConverter<RectPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Rect>::Convert(*this);
        }

        Rect();
        ~Rect();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = RectPtr>
        RectPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Rect>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Rect::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Rect::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int32_t x;
        int32_t y;
        int32_t width;
        int32_t height;
    };

    class RectF {
    public:
        using DataView = RectFDataView;
        using Data_ = internal::RectF_Data;

        static RectFPtr New();

        template <typename U>
        static RectFPtr From(const U& u)
        {
            return mojo::TypeConverter<RectFPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, RectF>::Convert(*this);
        }

        RectF();
        ~RectF();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = RectFPtr>
        RectFPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, RectF>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                RectF::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                RectF::DataView, std::vector<uint8_t>>(
                input, output);
        }

        float x;
        float y;
        float width;
        float height;
    };

    class Insets {
    public:
        using DataView = InsetsDataView;
        using Data_ = internal::Insets_Data;

        static InsetsPtr New();

        template <typename U>
        static InsetsPtr From(const U& u)
        {
            return mojo::TypeConverter<InsetsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Insets>::Convert(*this);
        }

        Insets();
        ~Insets();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = InsetsPtr>
        InsetsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Insets>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Insets::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Insets::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int32_t top;
        int32_t left;
        int32_t bottom;
        int32_t right;
    };

    class InsetsF {
    public:
        using DataView = InsetsFDataView;
        using Data_ = internal::InsetsF_Data;

        static InsetsFPtr New();

        template <typename U>
        static InsetsFPtr From(const U& u)
        {
            return mojo::TypeConverter<InsetsFPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, InsetsF>::Convert(*this);
        }

        InsetsF();
        ~InsetsF();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = InsetsFPtr>
        InsetsFPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, InsetsF>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                InsetsF::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                InsetsF::DataView, std::vector<uint8_t>>(
                input, output);
        }

        float top;
        float left;
        float bottom;
        float right;
    };

    class Vector2d {
    public:
        using DataView = Vector2dDataView;
        using Data_ = internal::Vector2d_Data;

        static Vector2dPtr New();

        template <typename U>
        static Vector2dPtr From(const U& u)
        {
            return mojo::TypeConverter<Vector2dPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Vector2d>::Convert(*this);
        }

        Vector2d();
        ~Vector2d();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = Vector2dPtr>
        Vector2dPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Vector2d>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Vector2d::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Vector2d::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int32_t x;
        int32_t y;
    };

    class Vector2dF {
    public:
        using DataView = Vector2dFDataView;
        using Data_ = internal::Vector2dF_Data;

        static Vector2dFPtr New();

        template <typename U>
        static Vector2dFPtr From(const U& u)
        {
            return mojo::TypeConverter<Vector2dFPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Vector2dF>::Convert(*this);
        }

        Vector2dF();
        ~Vector2dF();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = Vector2dFPtr>
        Vector2dFPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Vector2dF>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Vector2dF::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Vector2dF::DataView, std::vector<uint8_t>>(
                input, output);
        }

        float x;
        float y;
    };

    template <typename StructPtrType>
    PointPtr Point::Clone() const
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
            T, Point>::value>::type*>
    bool Point::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->x, other.x))
            return false;
        if (!mojo::internal::Equals(this->y, other.y))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PointFPtr PointF::Clone() const
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
            T, PointF>::value>::type*>
    bool PointF::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->x, other.x))
            return false;
        if (!mojo::internal::Equals(this->y, other.y))
            return false;
        return true;
    }
    template <typename StructPtrType>
    SizePtr Size::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->width = mojo::internal::Clone(width);
        rv->height = mojo::internal::Clone(height);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Size>::value>::type*>
    bool Size::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->width, other.width))
            return false;
        if (!mojo::internal::Equals(this->height, other.height))
            return false;
        return true;
    }
    template <typename StructPtrType>
    SizeFPtr SizeF::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->width = mojo::internal::Clone(width);
        rv->height = mojo::internal::Clone(height);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, SizeF>::value>::type*>
    bool SizeF::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->width, other.width))
            return false;
        if (!mojo::internal::Equals(this->height, other.height))
            return false;
        return true;
    }
    template <typename StructPtrType>
    RectPtr Rect::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->x = mojo::internal::Clone(x);
        rv->y = mojo::internal::Clone(y);
        rv->width = mojo::internal::Clone(width);
        rv->height = mojo::internal::Clone(height);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Rect>::value>::type*>
    bool Rect::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->x, other.x))
            return false;
        if (!mojo::internal::Equals(this->y, other.y))
            return false;
        if (!mojo::internal::Equals(this->width, other.width))
            return false;
        if (!mojo::internal::Equals(this->height, other.height))
            return false;
        return true;
    }
    template <typename StructPtrType>
    RectFPtr RectF::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->x = mojo::internal::Clone(x);
        rv->y = mojo::internal::Clone(y);
        rv->width = mojo::internal::Clone(width);
        rv->height = mojo::internal::Clone(height);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, RectF>::value>::type*>
    bool RectF::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->x, other.x))
            return false;
        if (!mojo::internal::Equals(this->y, other.y))
            return false;
        if (!mojo::internal::Equals(this->width, other.width))
            return false;
        if (!mojo::internal::Equals(this->height, other.height))
            return false;
        return true;
    }
    template <typename StructPtrType>
    InsetsPtr Insets::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->top = mojo::internal::Clone(top);
        rv->left = mojo::internal::Clone(left);
        rv->bottom = mojo::internal::Clone(bottom);
        rv->right = mojo::internal::Clone(right);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Insets>::value>::type*>
    bool Insets::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->top, other.top))
            return false;
        if (!mojo::internal::Equals(this->left, other.left))
            return false;
        if (!mojo::internal::Equals(this->bottom, other.bottom))
            return false;
        if (!mojo::internal::Equals(this->right, other.right))
            return false;
        return true;
    }
    template <typename StructPtrType>
    InsetsFPtr InsetsF::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->top = mojo::internal::Clone(top);
        rv->left = mojo::internal::Clone(left);
        rv->bottom = mojo::internal::Clone(bottom);
        rv->right = mojo::internal::Clone(right);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, InsetsF>::value>::type*>
    bool InsetsF::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->top, other.top))
            return false;
        if (!mojo::internal::Equals(this->left, other.left))
            return false;
        if (!mojo::internal::Equals(this->bottom, other.bottom))
            return false;
        if (!mojo::internal::Equals(this->right, other.right))
            return false;
        return true;
    }
    template <typename StructPtrType>
    Vector2dPtr Vector2d::Clone() const
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
            T, Vector2d>::value>::type*>
    bool Vector2d::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->x, other.x))
            return false;
        if (!mojo::internal::Equals(this->y, other.y))
            return false;
        return true;
    }
    template <typename StructPtrType>
    Vector2dFPtr Vector2dF::Clone() const
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
            T, Vector2dF>::value>::type*>
    bool Vector2dF::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->x, other.x))
            return false;
        if (!mojo::internal::Equals(this->y, other.y))
            return false;
        return true;
    }

} // namespace mojom
} // namespace gfx

namespace mojo {

template <>
struct StructTraits<::gfx::mojom::Point::DataView,
    ::gfx::mojom::PointPtr> {
    static bool IsNull(const ::gfx::mojom::PointPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::PointPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::Point::x) x(
        const ::gfx::mojom::PointPtr& input)
    {
        return input->x;
    }

    static decltype(::gfx::mojom::Point::y) y(
        const ::gfx::mojom::PointPtr& input)
    {
        return input->y;
    }

    static bool Read(::gfx::mojom::Point::DataView input, ::gfx::mojom::PointPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::PointF::DataView,
    ::gfx::mojom::PointFPtr> {
    static bool IsNull(const ::gfx::mojom::PointFPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::PointFPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::PointF::x) x(
        const ::gfx::mojom::PointFPtr& input)
    {
        return input->x;
    }

    static decltype(::gfx::mojom::PointF::y) y(
        const ::gfx::mojom::PointFPtr& input)
    {
        return input->y;
    }

    static bool Read(::gfx::mojom::PointF::DataView input, ::gfx::mojom::PointFPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::Size::DataView,
    ::gfx::mojom::SizePtr> {
    static bool IsNull(const ::gfx::mojom::SizePtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::SizePtr* output) { output->reset(); }

    static decltype(::gfx::mojom::Size::width) width(
        const ::gfx::mojom::SizePtr& input)
    {
        return input->width;
    }

    static decltype(::gfx::mojom::Size::height) height(
        const ::gfx::mojom::SizePtr& input)
    {
        return input->height;
    }

    static bool Read(::gfx::mojom::Size::DataView input, ::gfx::mojom::SizePtr* output);
};

template <>
struct StructTraits<::gfx::mojom::SizeF::DataView,
    ::gfx::mojom::SizeFPtr> {
    static bool IsNull(const ::gfx::mojom::SizeFPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::SizeFPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::SizeF::width) width(
        const ::gfx::mojom::SizeFPtr& input)
    {
        return input->width;
    }

    static decltype(::gfx::mojom::SizeF::height) height(
        const ::gfx::mojom::SizeFPtr& input)
    {
        return input->height;
    }

    static bool Read(::gfx::mojom::SizeF::DataView input, ::gfx::mojom::SizeFPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::Rect::DataView,
    ::gfx::mojom::RectPtr> {
    static bool IsNull(const ::gfx::mojom::RectPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::RectPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::Rect::x) x(
        const ::gfx::mojom::RectPtr& input)
    {
        return input->x;
    }

    static decltype(::gfx::mojom::Rect::y) y(
        const ::gfx::mojom::RectPtr& input)
    {
        return input->y;
    }

    static decltype(::gfx::mojom::Rect::width) width(
        const ::gfx::mojom::RectPtr& input)
    {
        return input->width;
    }

    static decltype(::gfx::mojom::Rect::height) height(
        const ::gfx::mojom::RectPtr& input)
    {
        return input->height;
    }

    static bool Read(::gfx::mojom::Rect::DataView input, ::gfx::mojom::RectPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::RectF::DataView,
    ::gfx::mojom::RectFPtr> {
    static bool IsNull(const ::gfx::mojom::RectFPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::RectFPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::RectF::x) x(
        const ::gfx::mojom::RectFPtr& input)
    {
        return input->x;
    }

    static decltype(::gfx::mojom::RectF::y) y(
        const ::gfx::mojom::RectFPtr& input)
    {
        return input->y;
    }

    static decltype(::gfx::mojom::RectF::width) width(
        const ::gfx::mojom::RectFPtr& input)
    {
        return input->width;
    }

    static decltype(::gfx::mojom::RectF::height) height(
        const ::gfx::mojom::RectFPtr& input)
    {
        return input->height;
    }

    static bool Read(::gfx::mojom::RectF::DataView input, ::gfx::mojom::RectFPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::Insets::DataView,
    ::gfx::mojom::InsetsPtr> {
    static bool IsNull(const ::gfx::mojom::InsetsPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::InsetsPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::Insets::top) top(
        const ::gfx::mojom::InsetsPtr& input)
    {
        return input->top;
    }

    static decltype(::gfx::mojom::Insets::left) left(
        const ::gfx::mojom::InsetsPtr& input)
    {
        return input->left;
    }

    static decltype(::gfx::mojom::Insets::bottom) bottom(
        const ::gfx::mojom::InsetsPtr& input)
    {
        return input->bottom;
    }

    static decltype(::gfx::mojom::Insets::right) right(
        const ::gfx::mojom::InsetsPtr& input)
    {
        return input->right;
    }

    static bool Read(::gfx::mojom::Insets::DataView input, ::gfx::mojom::InsetsPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::InsetsF::DataView,
    ::gfx::mojom::InsetsFPtr> {
    static bool IsNull(const ::gfx::mojom::InsetsFPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::InsetsFPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::InsetsF::top) top(
        const ::gfx::mojom::InsetsFPtr& input)
    {
        return input->top;
    }

    static decltype(::gfx::mojom::InsetsF::left) left(
        const ::gfx::mojom::InsetsFPtr& input)
    {
        return input->left;
    }

    static decltype(::gfx::mojom::InsetsF::bottom) bottom(
        const ::gfx::mojom::InsetsFPtr& input)
    {
        return input->bottom;
    }

    static decltype(::gfx::mojom::InsetsF::right) right(
        const ::gfx::mojom::InsetsFPtr& input)
    {
        return input->right;
    }

    static bool Read(::gfx::mojom::InsetsF::DataView input, ::gfx::mojom::InsetsFPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::Vector2d::DataView,
    ::gfx::mojom::Vector2dPtr> {
    static bool IsNull(const ::gfx::mojom::Vector2dPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::Vector2dPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::Vector2d::x) x(
        const ::gfx::mojom::Vector2dPtr& input)
    {
        return input->x;
    }

    static decltype(::gfx::mojom::Vector2d::y) y(
        const ::gfx::mojom::Vector2dPtr& input)
    {
        return input->y;
    }

    static bool Read(::gfx::mojom::Vector2d::DataView input, ::gfx::mojom::Vector2dPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::Vector2dF::DataView,
    ::gfx::mojom::Vector2dFPtr> {
    static bool IsNull(const ::gfx::mojom::Vector2dFPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::Vector2dFPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::Vector2dF::x) x(
        const ::gfx::mojom::Vector2dFPtr& input)
    {
        return input->x;
    }

    static decltype(::gfx::mojom::Vector2dF::y) y(
        const ::gfx::mojom::Vector2dFPtr& input)
    {
        return input->y;
    }

    static bool Read(::gfx::mojom::Vector2dF::DataView input, ::gfx::mojom::Vector2dFPtr* output);
};

} // namespace mojo

#endif // UI_GFX_GEOMETRY_MOJO_GEOMETRY_MOJOM_H_