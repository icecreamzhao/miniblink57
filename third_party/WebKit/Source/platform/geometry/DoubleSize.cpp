// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "platform/geometry/DoubleSize.h"
#include "platform/geometry/LayoutSize.h"
#include "wtf/text/WTFString.h"
=======
#include "config.h"
#include "platform/geometry/DoubleSize.h"
#include "platform/geometry/LayoutSize.h"
>>>>>>> miniblink49

#include <limits>
#include <math.h>

namespace blink {

DoubleSize::DoubleSize(const LayoutSize& size)
    : m_width(size.width().toDouble())
    , m_height(size.height().toDouble())
{
}

bool DoubleSize::isZero() const
{
    return fabs(m_width) < std::numeric_limits<double>::epsilon() && fabs(m_height) < std::numeric_limits<double>::epsilon();
}

<<<<<<< HEAD
String DoubleSize::toString() const
{
    return String::format("%lgx%lg", width(), height());
}

} // namespace blink
=======
}
>>>>>>> miniblink49
