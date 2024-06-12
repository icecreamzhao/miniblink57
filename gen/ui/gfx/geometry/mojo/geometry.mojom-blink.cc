// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4056)
#pragma warning(disable : 4065)
#pragma warning(disable : 4756)
#endif

#include "ui/gfx/geometry/mojo/geometry.mojom-blink.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/Source/platform/mojo/GeometryStructTraits.h"
namespace gfx {
namespace mojom {
    namespace blink { // static
        PointPtr Point::New()
        {
            PointPtr rv;
            mojo::internal::StructHelper<Point>::Initialize(&rv);
            return rv;
        }

        Point::Point()
            : x()
            , y()
        {
        }

        Point::~Point()
        {
        }
        size_t Point::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->x);
            seed = mojo::internal::WTFHash(seed, this->y);
            return seed;
        } // static
        PointFPtr PointF::New()
        {
            PointFPtr rv;
            mojo::internal::StructHelper<PointF>::Initialize(&rv);
            return rv;
        }

        PointF::PointF()
            : x()
            , y()
        {
        }

        PointF::~PointF()
        {
        }
        size_t PointF::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->x);
            seed = mojo::internal::WTFHash(seed, this->y);
            return seed;
        } // static
        SizePtr Size::New()
        {
            SizePtr rv;
            mojo::internal::StructHelper<Size>::Initialize(&rv);
            return rv;
        }

        Size::Size()
            : width()
            , height()
        {
        }

        Size::~Size()
        {
        } // static
        SizeFPtr SizeF::New()
        {
            SizeFPtr rv;
            mojo::internal::StructHelper<SizeF>::Initialize(&rv);
            return rv;
        }

        SizeF::SizeF()
            : width()
            , height()
        {
        }

        SizeF::~SizeF()
        {
        }
        size_t SizeF::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->width);
            seed = mojo::internal::WTFHash(seed, this->height);
            return seed;
        } // static
        RectPtr Rect::New()
        {
            RectPtr rv;
            mojo::internal::StructHelper<Rect>::Initialize(&rv);
            return rv;
        }

        Rect::Rect()
            : x()
            , y()
            , width()
            , height()
        {
        }

        Rect::~Rect()
        {
        }
        size_t Rect::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->x);
            seed = mojo::internal::WTFHash(seed, this->y);
            seed = mojo::internal::WTFHash(seed, this->width);
            seed = mojo::internal::WTFHash(seed, this->height);
            return seed;
        } // static
        RectFPtr RectF::New()
        {
            RectFPtr rv;
            mojo::internal::StructHelper<RectF>::Initialize(&rv);
            return rv;
        }

        RectF::RectF()
            : x()
            , y()
            , width()
            , height()
        {
        }

        RectF::~RectF()
        {
        }
        size_t RectF::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->x);
            seed = mojo::internal::WTFHash(seed, this->y);
            seed = mojo::internal::WTFHash(seed, this->width);
            seed = mojo::internal::WTFHash(seed, this->height);
            return seed;
        } // static
        InsetsPtr Insets::New()
        {
            InsetsPtr rv;
            mojo::internal::StructHelper<Insets>::Initialize(&rv);
            return rv;
        }

        Insets::Insets()
            : top()
            , left()
            , bottom()
            , right()
        {
        }

        Insets::~Insets()
        {
        }
        size_t Insets::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->top);
            seed = mojo::internal::WTFHash(seed, this->left);
            seed = mojo::internal::WTFHash(seed, this->bottom);
            seed = mojo::internal::WTFHash(seed, this->right);
            return seed;
        } // static
        InsetsFPtr InsetsF::New()
        {
            InsetsFPtr rv;
            mojo::internal::StructHelper<InsetsF>::Initialize(&rv);
            return rv;
        }

        InsetsF::InsetsF()
            : top()
            , left()
            , bottom()
            , right()
        {
        }

        InsetsF::~InsetsF()
        {
        }
        size_t InsetsF::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->top);
            seed = mojo::internal::WTFHash(seed, this->left);
            seed = mojo::internal::WTFHash(seed, this->bottom);
            seed = mojo::internal::WTFHash(seed, this->right);
            return seed;
        } // static
        Vector2dPtr Vector2d::New()
        {
            Vector2dPtr rv;
            mojo::internal::StructHelper<Vector2d>::Initialize(&rv);
            return rv;
        }

        Vector2d::Vector2d()
            : x()
            , y()
        {
        }

        Vector2d::~Vector2d()
        {
        }
        size_t Vector2d::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->x);
            seed = mojo::internal::WTFHash(seed, this->y);
            return seed;
        } // static
        Vector2dFPtr Vector2dF::New()
        {
            Vector2dFPtr rv;
            mojo::internal::StructHelper<Vector2dF>::Initialize(&rv);
            return rv;
        }

        Vector2dF::Vector2dF()
            : x()
            , y()
        {
        }

        Vector2dF::~Vector2dF()
        {
        }
        size_t Vector2dF::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->x);
            seed = mojo::internal::WTFHash(seed, this->y);
            return seed;
        }
    } // namespace blink
} // namespace mojom
} // namespace gfx

namespace mojo {

// static
bool StructTraits<::gfx::mojom::blink::Point::DataView, ::gfx::mojom::blink::PointPtr>::Read(
    ::gfx::mojom::blink::Point::DataView input,
    ::gfx::mojom::blink::PointPtr* output)
{
    bool success = true;
    ::gfx::mojom::blink::PointPtr result(::gfx::mojom::blink::Point::New());

    result->x = input.x();
    result->y = input.y();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::blink::PointF::DataView, ::gfx::mojom::blink::PointFPtr>::Read(
    ::gfx::mojom::blink::PointF::DataView input,
    ::gfx::mojom::blink::PointFPtr* output)
{
    bool success = true;
    ::gfx::mojom::blink::PointFPtr result(::gfx::mojom::blink::PointF::New());

    result->x = input.x();
    result->y = input.y();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::blink::Size::DataView, ::gfx::mojom::blink::SizePtr>::Read(
    ::gfx::mojom::blink::Size::DataView input,
    ::gfx::mojom::blink::SizePtr* output)
{
    bool success = true;
    ::gfx::mojom::blink::SizePtr result(::gfx::mojom::blink::Size::New());

    result->width = input.width();
    result->height = input.height();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::blink::SizeF::DataView, ::gfx::mojom::blink::SizeFPtr>::Read(
    ::gfx::mojom::blink::SizeF::DataView input,
    ::gfx::mojom::blink::SizeFPtr* output)
{
    bool success = true;
    ::gfx::mojom::blink::SizeFPtr result(::gfx::mojom::blink::SizeF::New());

    result->width = input.width();
    result->height = input.height();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::blink::Rect::DataView, ::gfx::mojom::blink::RectPtr>::Read(
    ::gfx::mojom::blink::Rect::DataView input,
    ::gfx::mojom::blink::RectPtr* output)
{
    bool success = true;
    ::gfx::mojom::blink::RectPtr result(::gfx::mojom::blink::Rect::New());

    result->x = input.x();
    result->y = input.y();
    result->width = input.width();
    result->height = input.height();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::blink::RectF::DataView, ::gfx::mojom::blink::RectFPtr>::Read(
    ::gfx::mojom::blink::RectF::DataView input,
    ::gfx::mojom::blink::RectFPtr* output)
{
    bool success = true;
    ::gfx::mojom::blink::RectFPtr result(::gfx::mojom::blink::RectF::New());

    result->x = input.x();
    result->y = input.y();
    result->width = input.width();
    result->height = input.height();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::blink::Insets::DataView, ::gfx::mojom::blink::InsetsPtr>::Read(
    ::gfx::mojom::blink::Insets::DataView input,
    ::gfx::mojom::blink::InsetsPtr* output)
{
    bool success = true;
    ::gfx::mojom::blink::InsetsPtr result(::gfx::mojom::blink::Insets::New());

    result->top = input.top();
    result->left = input.left();
    result->bottom = input.bottom();
    result->right = input.right();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::blink::InsetsF::DataView, ::gfx::mojom::blink::InsetsFPtr>::Read(
    ::gfx::mojom::blink::InsetsF::DataView input,
    ::gfx::mojom::blink::InsetsFPtr* output)
{
    bool success = true;
    ::gfx::mojom::blink::InsetsFPtr result(::gfx::mojom::blink::InsetsF::New());

    result->top = input.top();
    result->left = input.left();
    result->bottom = input.bottom();
    result->right = input.right();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::blink::Vector2d::DataView, ::gfx::mojom::blink::Vector2dPtr>::Read(
    ::gfx::mojom::blink::Vector2d::DataView input,
    ::gfx::mojom::blink::Vector2dPtr* output)
{
    bool success = true;
    ::gfx::mojom::blink::Vector2dPtr result(::gfx::mojom::blink::Vector2d::New());

    result->x = input.x();
    result->y = input.y();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::blink::Vector2dF::DataView, ::gfx::mojom::blink::Vector2dFPtr>::Read(
    ::gfx::mojom::blink::Vector2dF::DataView input,
    ::gfx::mojom::blink::Vector2dFPtr* output)
{
    bool success = true;
    ::gfx::mojom::blink::Vector2dFPtr result(::gfx::mojom::blink::Vector2dF::New());

    result->x = input.x();
    result->y = input.y();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif