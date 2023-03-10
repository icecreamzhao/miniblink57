// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FileUploadControlPainter_h
#define FileUploadControlPainter_h

#include "wtf/Allocator.h"

namespace blink {

struct PaintInfo;
class LayoutPoint;
class LayoutFileUploadControl;

class FileUploadControlPainter {
    STACK_ALLOCATED();

public:
    FileUploadControlPainter(
        const LayoutFileUploadControl& layoutFileUploadControl)
        : m_layoutFileUploadControl(layoutFileUploadControl)
    {
    }

    void paintObject(const PaintInfo&, const LayoutPoint&);

private:
    const LayoutFileUploadControl& m_layoutFileUploadControl;
};

} // namespace blink

#endif // FileUploadControlPainter_h
