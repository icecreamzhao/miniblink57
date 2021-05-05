// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_GEOMETRY_MOJO_GEOMETRY_MOJOM_BLINK_H_
#define UI_GFX_GEOMETRY_MOJO_GEOMETRY_MOJOM_BLINK_H_

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
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebSize.h"

namespace gfx {
namespace mojom {
    namespace blink {
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
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    Point::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    Point::DataView, WTF::Vector<uint8_t>>(
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
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    PointF::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    PointF::DataView, WTF::Vector<uint8_t>>(
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    Size::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    Size::DataView, WTF::Vector<uint8_t>>(
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
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    SizeF::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    SizeF::DataView, WTF::Vector<uint8_t>>(
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
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    Rect::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    Rect::DataView, WTF::Vector<uint8_t>>(
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
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    RectF::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    RectF::DataView, WTF::Vector<uint8_t>>(
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
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    Insets::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    Insets::DataView, WTF::Vector<uint8_t>>(
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
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    InsetsF::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    InsetsF::DataView, WTF::Vector<uint8_t>>(
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
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    Vector2d::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    Vector2d::DataView, WTF::Vector<uint8_t>>(
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
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    Vector2dF::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    Vector2dF::DataView, WTF::Vector<uint8_t>>(
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

    } // namespace blink
} // namespace mojom
} // namespace gfx

namespace mojo {

template <>
struct StructTraits<::gfx::mojom::blink::Point::DataView,
    ::gfx::mojom::blink::PointPtr> {
    static bool IsNull(const ::gfx::mojom::blink::PointPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::blink::PointPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::blink::Point::x) x(
        const ::gfx::mojom::blink::PointPtr& input)
    {
        return input->x;
    }

    static decltype(::gfx::mojom::blink::Point::y) y(
        const ::gfx::mojom::blink::PointPtr& input)
    {
        return input->y;
    }

    static bool Read(::gfx::mojom::blink::Point::DataView input, ::gfx::mojom::blink::PointPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::blink::PointF::DataView,
    ::gfx::mojom::blink::PointFPtr> {
    static bool IsNull(const ::gfx::mojom::blink::PointFPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::blink::PointFPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::blink::PointF::x) x(
        const ::gfx::mojom::blink::PointFPtr& input)
    {
        return input->x;
    }

    static decltype(::gfx::mojom::blink::PointF::y) y(
        const ::gfx::mojom::blink::PointFPtr& input)
    {
        return input->y;
    }

    static bool Read(::gfx::mojom::blink::PointF::DataView input, ::gfx::mojom::blink::PointFPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::blink::Size::DataView,
    ::gfx::mojom::blink::SizePtr> {
    static bool IsNull(const ::gfx::mojom::blink::SizePtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::blink::SizePtr* output) { output->reset(); }

    static decltype(::gfx::mojom::blink::Size::width) width(
        const ::gfx::mojom::blink::SizePtr& input)
    {
        return input->width;
    }

    static decltype(::gfx::mojom::blink::Size::height) height(
        const ::gfx::mojom::blink::SizePtr& input)
    {
        return input->height;
    }

    static bool Read(::gfx::mojom::blink::Size::DataView input, ::gfx::mojom::blink::SizePtr* output);
};

template <>
struct StructTraits<::gfx::mojom::blink::SizeF::DataView,
    ::gfx::mojom::blink::SizeFPtr> {
    static bool IsNull(const ::gfx::mojom::blink::SizeFPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::blink::SizeFPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::blink::SizeF::width) width(
        const ::gfx::mojom::blink::SizeFPtr& input)
    {
        return input->width;
    }

    static decltype(::gfx::mojom::blink::SizeF::height) height(
        const ::gfx::mojom::blink::SizeFPtr& input)
    {
        return input->height;
    }

    static bool Read(::gfx::mojom::blink::SizeF::DataView input, ::gfx::mojom::blink::SizeFPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::blink::Rect::DataView,
    ::gfx::mojom::blink::RectPtr> {
    static bool IsNull(const ::gfx::mojom::blink::RectPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::blink::RectPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::blink::Rect::x) x(
        const ::gfx::mojom::blink::RectPtr& input)
    {
        return input->x;
    }

    static decltype(::gfx::mojom::blink::Rect::y) y(
        const ::gfx::mojom::blink::RectPtr& input)
    {
        return input->y;
    }

    static decltype(::gfx::mojom::blink::Rect::width) width(
        const ::gfx::mojom::blink::RectPtr& input)
    {
        return input->width;
    }

    static decltype(::gfx::mojom::blink::Rect::height) height(
        const ::gfx::mojom::blink::RectPtr& input)
    {
        return input->height;
    }

    static bool Read(::gfx::mojom::blink::Rect::DataView input, ::gfx::mojom::blink::RectPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::blink::RectF::DataView,
    ::gfx::mojom::blink::RectFPtr> {
    static bool IsNull(const ::gfx::mojom::blink::RectFPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::blink::RectFPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::blink::RectF::x) x(
        const ::gfx::mojom::blink::RectFPtr& input)
    {
        return input->x;
    }

    static decltype(::gfx::mojom::blink::RectF::y) y(
        const ::gfx::mojom::blink::RectFPtr& input)
    {
        return input->y;
    }

    static decltype(::gfx::mojom::blink::RectF::width) width(
        const ::gfx::mojom::blink::RectFPtr& input)
    {
        return input->width;
    }

    static decltype(::gfx::mojom::blink::RectF::height) height(
        const ::gfx::mojom::blink::RectFPtr& input)
    {
        return input->height;
    }

    static bool Read(::gfx::mojom::blink::RectF::DataView input, ::gfx::mojom::blink::RectFPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::blink::Insets::DataView,
    ::gfx::mojom::blink::InsetsPtr> {
    static bool IsNull(const ::gfx::mojom::blink::InsetsPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::blink::InsetsPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::blink::Insets::top) top(
        const ::gfx::mojom::blink::InsetsPtr& input)
    {
        return input->top;
    }

    static decltype(::gfx::mojom::blink::Insets::left) left(
        const ::gfx::mojom::blink::InsetsPtr& input)
    {
        return input->left;
    }

    static decltype(::gfx::mojom::blink::Insets::bottom) bottom(
        const ::gfx::mojom::blink::InsetsPtr& input)
    {
        return input->bottom;
    }

    static decltype(::gfx::mojom::blink::Insets::right) right(
        const ::gfx::mojom::blink::InsetsPtr& input)
    {
        return input->right;
    }

    static bool Read(::gfx::mojom::blink::Insets::DataView input, ::gfx::mojom::blink::InsetsPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::blink::InsetsF::DataView,
    ::gfx::mojom::blink::InsetsFPtr> {
    static bool IsNull(const ::gfx::mojom::blink::InsetsFPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::blink::InsetsFPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::blink::InsetsF::top) top(
        const ::gfx::mojom::blink::InsetsFPtr& input)
    {
        return input->top;
    }

    static decltype(::gfx::mojom::blink::InsetsF::left) left(
        const ::gfx::mojom::blink::InsetsFPtr& input)
    {
        return input->left;
    }

    static decltype(::gfx::mojom::blink::InsetsF::bottom) bottom(
        const ::gfx::mojom::blink::InsetsFPtr& input)
    {
        return input->bottom;
    }

    static decltype(::gfx::mojom::blink::InsetsF::right) right(
        const ::gfx::mojom::blink::InsetsFPtr& input)
    {
        return input->right;
    }

    static bool Read(::gfx::mojom::blink::InsetsF::DataView input, ::gfx::mojom::blink::InsetsFPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::blink::Vector2d::DataView,
    ::gfx::mojom::blink::Vector2dPtr> {
    static bool IsNull(const ::gfx::mojom::blink::Vector2dPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::blink::Vector2dPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::blink::Vector2d::x) x(
        const ::gfx::mojom::blink::Vector2dPtr& input)
    {
        return input->x;
    }

    static decltype(::gfx::mojom::blink::Vector2d::y) y(
        const ::gfx::mojom::blink::Vector2dPtr& input)
    {
        return input->y;
    }

    static bool Read(::gfx::mojom::blink::Vector2d::DataView input, ::gfx::mojom::blink::Vector2dPtr* output);
};

template <>
struct StructTraits<::gfx::mojom::blink::Vector2dF::DataView,
    ::gfx::mojom::blink::Vector2dFPtr> {
    static bool IsNull(const ::gfx::mojom::blink::Vector2dFPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::blink::Vector2dFPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::blink::Vector2dF::x) x(
        const ::gfx::mojom::blink::Vector2dFPtr& input)
    {
        return input->x;
    }

    static decltype(::gfx::mojom::blink::Vector2dF::y) y(
        const ::gfx::mojom::blink::Vector2dFPtr& input)
    {
        return input->y;
    }

    static bool Read(::gfx::mojom::blink::Vector2dF::DataView input, ::gfx::mojom::blink::Vector2dFPtr* output);
};

} // namespace mojo

#endif // UI_GFX_GEOMETRY_MOJO_GEOMETRY_MOJOM_BLINK_H_