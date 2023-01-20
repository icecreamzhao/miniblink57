// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "platform/geometry/DoublePoint.h"
#include "platform/geometry/FloatSize.h"
#include "platform/geometry/LayoutPoint.h"
#include "wtf/text/WTFString.h"
=======
#include "config.h"
#include "platform/geometry/DoublePoint.h"
#include "platform/geometry/FloatSize.h"
#include "platform/geometry/LayoutPoint.h"
>>>>>>> miniblink49

namespace blink {

DoublePoint::DoublePoint(const LayoutPoint& p)
    : m_x(p.x().toDouble())
    , m_y(p.y().toDouble())
{
}

DoublePoint::DoublePoint(const FloatSize& size)
<<<<<<< HEAD
    : m_x(size.width())
    , m_y(size.height())
{
}

String DoublePoint::toString() const
{
    return String::format("%lg,%lg", x(), y());
}
=======
    : m_x(size.width()), m_y(size.height())
{
}

>>>>>>> miniblink49

} // namespace blink
