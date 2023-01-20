// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ClipPathRecorder_h
#define ClipPathRecorder_h

#include "platform/graphics/Path.h"
#include "platform/graphics/paint/DisplayItemClient.h"
<<<<<<< HEAD
#include "wtf/Allocator.h"
#include "wtf/Noncopyable.h"
=======
>>>>>>> miniblink49

namespace blink {

class GraphicsContext;

class PLATFORM_EXPORT ClipPathRecorder {
<<<<<<< HEAD
    USING_FAST_MALLOC(ClipPathRecorder);
    WTF_MAKE_NONCOPYABLE(ClipPathRecorder);

public:
    ClipPathRecorder(GraphicsContext&, const DisplayItemClient&, const Path&);
=======
    WTF_MAKE_FAST_ALLOCATED(ClipPathRecorder);
public:
    ClipPathRecorder(GraphicsContext&, const DisplayItemClientWrapper&, const Path&);
>>>>>>> miniblink49
    ~ClipPathRecorder();

private:
    GraphicsContext& m_context;
<<<<<<< HEAD
    const DisplayItemClient& m_client;
=======
    DisplayItemClientWrapper m_client;
>>>>>>> miniblink49
};

} // namespace blink

#endif // ClipPathRecorder_h
