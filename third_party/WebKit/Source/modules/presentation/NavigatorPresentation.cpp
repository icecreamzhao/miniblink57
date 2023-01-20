// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/presentation/NavigatorPresentation.h"

#include "core/frame/Navigator.h"
#include "modules/presentation/Presentation.h"

namespace blink {

<<<<<<< HEAD
NavigatorPresentation::NavigatorPresentation() { }
=======
NavigatorPresentation::NavigatorPresentation()
{
}
>>>>>>> miniblink49

// static
const char* NavigatorPresentation::supplementName()
{
    return "NavigatorPresentation";
}

// static
NavigatorPresentation& NavigatorPresentation::from(Navigator& navigator)
{
<<<<<<< HEAD
    NavigatorPresentation* supplement = static_cast<NavigatorPresentation*>(
        Supplement<Navigator>::from(navigator, supplementName()));
=======
    NavigatorPresentation* supplement = static_cast<NavigatorPresentation*>(HeapSupplement<Navigator>::from(navigator, supplementName()));
>>>>>>> miniblink49
    if (!supplement) {
        supplement = new NavigatorPresentation();
        provideTo(navigator, supplementName(), supplement);
    }
    return *supplement;
}

// static
Presentation* NavigatorPresentation::presentation(Navigator& navigator)
{
    NavigatorPresentation& self = NavigatorPresentation::from(navigator);
    if (!self.m_presentation) {
        if (!navigator.frame())
            return nullptr;
        self.m_presentation = Presentation::create(navigator.frame());
    }
    return self.m_presentation;
}

DEFINE_TRACE(NavigatorPresentation)
{
    visitor->trace(m_presentation);
<<<<<<< HEAD
    Supplement<Navigator>::trace(visitor);
=======
    HeapSupplement<Navigator>::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
