/*
 * Copyright (C) 2011 Apple Inc. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ScrollbarThemeMock_h
#define ScrollbarThemeMock_h

#include "platform/scroll/ScrollbarTheme.h"

namespace blink {

<<<<<<< HEAD
// Scrollbar theme used in image snapshots, to eliminate appearance differences
// between platforms.
=======
// Scrollbar theme used in image snapshots, to eliminate appearance differences between platforms.
>>>>>>> miniblink49
class PLATFORM_EXPORT ScrollbarThemeMock : public ScrollbarTheme {
public:
    int scrollbarThickness(ScrollbarControlSize = RegularScrollbar) override;
    bool usesOverlayScrollbars() const override;

protected:
<<<<<<< HEAD
    bool hasButtons(const ScrollbarThemeClient&) override { return false; }
    bool hasThumb(const ScrollbarThemeClient&) override { return true; }

    IntRect backButtonRect(const ScrollbarThemeClient&,
        ScrollbarPart,
        bool /*painting*/ = false) override
    {
        return IntRect();
    }
    IntRect forwardButtonRect(const ScrollbarThemeClient&,
        ScrollbarPart,
        bool /*painting*/ = false) override
    {
        return IntRect();
    }
    IntRect trackRect(const ScrollbarThemeClient&,
        bool painting = false) override;

    void paintTrackBackground(GraphicsContext&,
        const Scrollbar&,
        const IntRect&) override;
    void paintThumb(GraphicsContext&, const Scrollbar&, const IntRect&) override;

    void paintScrollCorner(GraphicsContext&,
        const DisplayItemClient&,
        const IntRect& cornerRect) override;
=======
    bool hasButtons(ScrollbarThemeClient*) override { return false; }
    bool hasThumb(ScrollbarThemeClient*) override { return true; }

    IntRect backButtonRect(ScrollbarThemeClient*, ScrollbarPart, bool /*painting*/ = false) override { return IntRect(); }
    IntRect forwardButtonRect(ScrollbarThemeClient*, ScrollbarPart, bool /*painting*/ = false) override { return IntRect(); }
    IntRect trackRect(ScrollbarThemeClient*, bool painting = false) override;

    void paintTrackBackground(GraphicsContext*, ScrollbarThemeClient*, const IntRect&) override;
    void paintThumb(GraphicsContext*, ScrollbarThemeClient*, const IntRect&) override;
>>>>>>> miniblink49

private:
    bool isMockTheme() const final { return true; }
};

<<<<<<< HEAD
} // namespace blink
=======
}
>>>>>>> miniblink49
#endif // ScrollbarThemeMock_h
