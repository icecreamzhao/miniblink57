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

#include "ui/gfx/geometry/mojo/geometry.mojom.h"

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
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
namespace gfx {
namespace mojom { // static
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
} // namespace mojom
} // namespace gfx

namespace mojo {

// static
bool StructTraits<::gfx::mojom::Point::DataView, ::gfx::mojom::PointPtr>::Read(
    ::gfx::mojom::Point::DataView input,
    ::gfx::mojom::PointPtr* output)
{
    bool success = true;
    ::gfx::mojom::PointPtr result(::gfx::mojom::Point::New());

    result->x = input.x();
    result->y = input.y();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::PointF::DataView, ::gfx::mojom::PointFPtr>::Read(
    ::gfx::mojom::PointF::DataView input,
    ::gfx::mojom::PointFPtr* output)
{
    bool success = true;
    ::gfx::mojom::PointFPtr result(::gfx::mojom::PointF::New());

    result->x = input.x();
    result->y = input.y();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::Size::DataView, ::gfx::mojom::SizePtr>::Read(
    ::gfx::mojom::Size::DataView input,
    ::gfx::mojom::SizePtr* output)
{
    bool success = true;
    ::gfx::mojom::SizePtr result(::gfx::mojom::Size::New());

    result->width = input.width();
    result->height = input.height();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::SizeF::DataView, ::gfx::mojom::SizeFPtr>::Read(
    ::gfx::mojom::SizeF::DataView input,
    ::gfx::mojom::SizeFPtr* output)
{
    bool success = true;
    ::gfx::mojom::SizeFPtr result(::gfx::mojom::SizeF::New());

    result->width = input.width();
    result->height = input.height();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::Rect::DataView, ::gfx::mojom::RectPtr>::Read(
    ::gfx::mojom::Rect::DataView input,
    ::gfx::mojom::RectPtr* output)
{
    bool success = true;
    ::gfx::mojom::RectPtr result(::gfx::mojom::Rect::New());

    result->x = input.x();
    result->y = input.y();
    result->width = input.width();
    result->height = input.height();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::RectF::DataView, ::gfx::mojom::RectFPtr>::Read(
    ::gfx::mojom::RectF::DataView input,
    ::gfx::mojom::RectFPtr* output)
{
    bool success = true;
    ::gfx::mojom::RectFPtr result(::gfx::mojom::RectF::New());

    result->x = input.x();
    result->y = input.y();
    result->width = input.width();
    result->height = input.height();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::Insets::DataView, ::gfx::mojom::InsetsPtr>::Read(
    ::gfx::mojom::Insets::DataView input,
    ::gfx::mojom::InsetsPtr* output)
{
    bool success = true;
    ::gfx::mojom::InsetsPtr result(::gfx::mojom::Insets::New());

    result->top = input.top();
    result->left = input.left();
    result->bottom = input.bottom();
    result->right = input.right();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::InsetsF::DataView, ::gfx::mojom::InsetsFPtr>::Read(
    ::gfx::mojom::InsetsF::DataView input,
    ::gfx::mojom::InsetsFPtr* output)
{
    bool success = true;
    ::gfx::mojom::InsetsFPtr result(::gfx::mojom::InsetsF::New());

    result->top = input.top();
    result->left = input.left();
    result->bottom = input.bottom();
    result->right = input.right();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::Vector2d::DataView, ::gfx::mojom::Vector2dPtr>::Read(
    ::gfx::mojom::Vector2d::DataView input,
    ::gfx::mojom::Vector2dPtr* output)
{
    bool success = true;
    ::gfx::mojom::Vector2dPtr result(::gfx::mojom::Vector2d::New());

    result->x = input.x();
    result->y = input.y();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::Vector2dF::DataView, ::gfx::mojom::Vector2dFPtr>::Read(
    ::gfx::mojom::Vector2dF::DataView input,
    ::gfx::mojom::Vector2dFPtr* output)
{
    bool success = true;
    ::gfx::mojom::Vector2dFPtr result(::gfx::mojom::Vector2dF::New());

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