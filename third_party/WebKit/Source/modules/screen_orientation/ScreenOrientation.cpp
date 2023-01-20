// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/screen_orientation/ScreenOrientation.h"

#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "core/dom/DOMException.h"
#include "core/dom/Document.h"
#include "core/dom/ExceptionCode.h"
#include "core/frame/LocalFrame.h"
#include "modules/EventTargetModules.h"
#include "modules/screen_orientation/LockOrientationCallback.h"
<<<<<<< HEAD
#include "modules/screen_orientation/ScreenOrientationControllerImpl.h"
#include "public/platform/modules/screen_orientation/WebScreenOrientationType.h"

// This code assumes that WebScreenOrientationType values are included in
// WebScreenOrientationLockType.
#define STATIC_ASSERT_ENUM(a, b)                              \
    static_assert(static_cast<int>(a) == static_cast<int>(b), \
        "mismatching enum: " #a)
STATIC_ASSERT_ENUM(blink::WebScreenOrientationPortraitPrimary,
    blink::WebScreenOrientationLockPortraitPrimary);
STATIC_ASSERT_ENUM(blink::WebScreenOrientationPortraitSecondary,
    blink::WebScreenOrientationLockPortraitSecondary);
STATIC_ASSERT_ENUM(blink::WebScreenOrientationLandscapePrimary,
    blink::WebScreenOrientationLockLandscapePrimary);
STATIC_ASSERT_ENUM(blink::WebScreenOrientationLandscapeSecondary,
    blink::WebScreenOrientationLockLandscapeSecondary);
=======
#include "modules/screen_orientation/ScreenOrientationController.h"
#include "public/platform/modules/screen_orientation/WebScreenOrientationType.h"

// This code assumes that WebScreenOrientationType values are included in WebScreenOrientationLockType.
#define STATIC_ASSERT_MATCHING_ENUM(enum1, enum2) \
    static_assert(static_cast<unsigned>(blink::enum1) == static_cast<unsigned>(blink::enum2), "mismatching enum values")
STATIC_ASSERT_MATCHING_ENUM(WebScreenOrientationPortraitPrimary, WebScreenOrientationLockPortraitPrimary);
STATIC_ASSERT_MATCHING_ENUM(WebScreenOrientationPortraitSecondary, WebScreenOrientationLockPortraitSecondary);
STATIC_ASSERT_MATCHING_ENUM(WebScreenOrientationLandscapePrimary, WebScreenOrientationLockLandscapePrimary);
STATIC_ASSERT_MATCHING_ENUM(WebScreenOrientationLandscapeSecondary, WebScreenOrientationLockLandscapeSecondary);
>>>>>>> miniblink49

namespace blink {

struct ScreenOrientationInfo {
    const AtomicString& name;
    unsigned orientation;
};

static ScreenOrientationInfo* orientationsMap(unsigned& length)
{
<<<<<<< HEAD
    DEFINE_STATIC_LOCAL(const AtomicString, portraitPrimary,
        ("portrait-primary"));
    DEFINE_STATIC_LOCAL(const AtomicString, portraitSecondary,
        ("portrait-secondary"));
    DEFINE_STATIC_LOCAL(const AtomicString, landscapePrimary,
        ("landscape-primary"));
    DEFINE_STATIC_LOCAL(const AtomicString, landscapeSecondary,
        ("landscape-secondary"));
    DEFINE_STATIC_LOCAL(const AtomicString, any, ("any"));
    DEFINE_STATIC_LOCAL(const AtomicString, portrait, ("portrait"));
    DEFINE_STATIC_LOCAL(const AtomicString, landscape, ("landscape"));
    DEFINE_STATIC_LOCAL(const AtomicString, natural, ("natural"));
=======
    DEFINE_STATIC_LOCAL(const AtomicString, portraitPrimary, ("portrait-primary", AtomicString::ConstructFromLiteral));
    DEFINE_STATIC_LOCAL(const AtomicString, portraitSecondary, ("portrait-secondary", AtomicString::ConstructFromLiteral));
    DEFINE_STATIC_LOCAL(const AtomicString, landscapePrimary, ("landscape-primary", AtomicString::ConstructFromLiteral));
    DEFINE_STATIC_LOCAL(const AtomicString, landscapeSecondary, ("landscape-secondary", AtomicString::ConstructFromLiteral));
    DEFINE_STATIC_LOCAL(const AtomicString, any, ("any", AtomicString::ConstructFromLiteral));
    DEFINE_STATIC_LOCAL(const AtomicString, portrait, ("portrait", AtomicString::ConstructFromLiteral));
    DEFINE_STATIC_LOCAL(const AtomicString, landscape, ("landscape", AtomicString::ConstructFromLiteral));
    DEFINE_STATIC_LOCAL(const AtomicString, natural, ("natural", AtomicString::ConstructFromLiteral));
>>>>>>> miniblink49

    static ScreenOrientationInfo orientationMap[] = {
        { portraitPrimary, WebScreenOrientationLockPortraitPrimary },
        { portraitSecondary, WebScreenOrientationLockPortraitSecondary },
        { landscapePrimary, WebScreenOrientationLockLandscapePrimary },
        { landscapeSecondary, WebScreenOrientationLockLandscapeSecondary },
        { any, WebScreenOrientationLockAny },
        { portrait, WebScreenOrientationLockPortrait },
        { landscape, WebScreenOrientationLockLandscape },
        { natural, WebScreenOrientationLockNatural }
    };
    length = WTF_ARRAY_LENGTH(orientationMap);

    return orientationMap;
}

<<<<<<< HEAD
const AtomicString& ScreenOrientation::orientationTypeToString(
    WebScreenOrientationType orientation)
=======
const AtomicString& ScreenOrientation::orientationTypeToString(WebScreenOrientationType orientation)
>>>>>>> miniblink49
{
    unsigned length = 0;
    ScreenOrientationInfo* orientationMap = orientationsMap(length);
    for (unsigned i = 0; i < length; ++i) {
        if (static_cast<unsigned>(orientation) == orientationMap[i].orientation)
            return orientationMap[i].name;
    }

    ASSERT_NOT_REACHED();
    return nullAtom;
}

<<<<<<< HEAD
static WebScreenOrientationLockType stringToOrientationLock(
    const AtomicString& orientationLockString)
=======
static WebScreenOrientationLockType stringToOrientationLock(const AtomicString& orientationLockString)
>>>>>>> miniblink49
{
    unsigned length = 0;
    ScreenOrientationInfo* orientationMap = orientationsMap(length);
    for (unsigned i = 0; i < length; ++i) {
        if (orientationMap[i].name == orientationLockString)
<<<<<<< HEAD
            return static_cast<WebScreenOrientationLockType>(
                orientationMap[i].orientation);
=======
            return static_cast<WebScreenOrientationLockType>(orientationMap[i].orientation);
>>>>>>> miniblink49
    }

    ASSERT_NOT_REACHED();
    return WebScreenOrientationLockDefault;
}

// static
ScreenOrientation* ScreenOrientation::create(LocalFrame* frame)
{
    ASSERT(frame);

    // Check if the ScreenOrientationController is supported for the
    // frame. It will not be for all LocalFrames, or the frame may
    // have been detached.
<<<<<<< HEAD
    if (!ScreenOrientationControllerImpl::from(*frame))
=======
    if (!ScreenOrientationController::from(*frame))
>>>>>>> miniblink49
        return nullptr;

    ScreenOrientation* orientation = new ScreenOrientation(frame);
    ASSERT(orientation->controller());
    // FIXME: ideally, we would like to provide the ScreenOrientationController
    // the case where it is not defined but for the moment, it is eagerly
    // created when the LocalFrame is created so we shouldn't be in that
    // situation.
    // In order to create the ScreenOrientationController lazily, we would need
    // to be able to access WebFrameClient from modules/.

    orientation->controller()->setOrientation(orientation);
    return orientation;
}

ScreenOrientation::ScreenOrientation(LocalFrame* frame)
<<<<<<< HEAD
    : ContextClient(frame)
=======
    : DOMWindowProperty(frame)
>>>>>>> miniblink49
    , m_type(WebScreenOrientationUndefined)
    , m_angle(0)
{
}

<<<<<<< HEAD
ScreenOrientation::~ScreenOrientation() { }
=======
ScreenOrientation::~ScreenOrientation()
{
}
>>>>>>> miniblink49

const WTF::AtomicString& ScreenOrientation::interfaceName() const
{
    return EventTargetNames::ScreenOrientation;
}

<<<<<<< HEAD
ExecutionContext* ScreenOrientation::getExecutionContext() const
{
    if (!frame())
        return 0;
    return frame()->document();
=======
ExecutionContext* ScreenOrientation::executionContext() const
{
    if (!m_frame)
        return 0;
    return m_frame->document();
>>>>>>> miniblink49
}

String ScreenOrientation::type() const
{
    return orientationTypeToString(m_type);
}

unsigned short ScreenOrientation::angle() const
{
    return m_angle;
}

void ScreenOrientation::setType(WebScreenOrientationType type)
{
    m_type = type;
}

void ScreenOrientation::setAngle(unsigned short angle)
{
    m_angle = angle;
}

ScriptPromise ScreenOrientation::lock(ScriptState* state, const AtomicString& lockString)
{
<<<<<<< HEAD
    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(state);
    ScriptPromise promise = resolver->promise();

    Document* document = frame() ? frame()->document() : 0;

    if (!document || !controller()) {
        DOMException* exception = DOMException::create(
            InvalidStateError, "The object is no longer associated to a document.");
=======
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(state);
    ScriptPromise promise = resolver->promise();

    Document* document = m_frame ? m_frame->document() : 0;

    if (!document || !controller()) {
        DOMException* exception = DOMException::create(InvalidStateError, "The object is no longer associated to a document.");
>>>>>>> miniblink49
        resolver->reject(exception);
        return promise;
    }

    if (document->isSandboxed(SandboxOrientationLock)) {
<<<<<<< HEAD
        DOMException* exception = DOMException::create(SecurityError,
            "The document is sandboxed and lacks the "
            "'allow-orientation-lock' flag.");
=======
        DOMException* exception = DOMException::create(SecurityError, "The document is sandboxed and lacks the 'allow-orientation-lock' flag.");
>>>>>>> miniblink49
        resolver->reject(exception);
        return promise;
    }

<<<<<<< HEAD
    controller()->lock(stringToOrientationLock(lockString),
        WTF::makeUnique<LockOrientationCallback>(resolver));
=======
    controller()->lock(stringToOrientationLock(lockString), new LockOrientationCallback(resolver));
>>>>>>> miniblink49
    return promise;
}

void ScreenOrientation::unlock()
{
    if (!controller())
        return;

    controller()->unlock();
}

<<<<<<< HEAD
ScreenOrientationControllerImpl* ScreenOrientation::controller()
{
    if (!frame())
        return 0;

    return ScreenOrientationControllerImpl::from(*frame());
=======
ScreenOrientationController* ScreenOrientation::controller()
{
    if (!m_frame)
        return 0;

    return ScreenOrientationController::from(*m_frame);
>>>>>>> miniblink49
}

DEFINE_TRACE(ScreenOrientation)
{
<<<<<<< HEAD
    EventTargetWithInlineData::trace(visitor);
    ContextClient::trace(visitor);
=======
    RefCountedGarbageCollectedEventTargetWithInlineData<ScreenOrientation>::trace(visitor);
    DOMWindowProperty::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
