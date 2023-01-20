// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ClipRecorder_h
#define ClipRecorder_h

<<<<<<< HEAD
#include "platform/graphics/paint/DisplayItem.h"
#include "wtf/Allocator.h"
#include "wtf/Noncopyable.h"
=======
#include "SkRegion.h"
#include "platform/geometry/LayoutRect.h"
#include "platform/graphics/paint/DisplayItem.h"
>>>>>>> miniblink49

namespace blink {

class GraphicsContext;

class PLATFORM_EXPORT ClipRecorder {
<<<<<<< HEAD
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
    WTF_MAKE_NONCOPYABLE(ClipRecorder);

public:
    ClipRecorder(GraphicsContext&,
        const DisplayItemClient&,
        DisplayItem::Type,
        const IntRect& clipRect);
    ~ClipRecorder();

private:
    const DisplayItemClient& m_client;
=======
    WTF_MAKE_FAST_ALLOCATED(ClipRecorder);
public:
    ClipRecorder(GraphicsContext&, const DisplayItemClientWrapper&, DisplayItem::Type, const LayoutRect& clipRect);
    ~ClipRecorder();
private:
    DisplayItemClientWrapper m_client;
>>>>>>> miniblink49
    GraphicsContext& m_context;
    DisplayItem::Type m_type;
};

} // namespace blink

#endif // ClipRecorder_h
