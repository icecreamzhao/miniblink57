// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef LockOrientationCallback_h
#define LockOrientationCallback_h

#include "platform/heap/Handle.h"
#include "public/platform/modules/screen_orientation/WebLockOrientationCallback.h"
#include "public/platform/modules/screen_orientation/WebScreenOrientationType.h"
#include "wtf/Noncopyable.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

class ScriptPromiseResolver;

// LockOrientationCallback is an implementation of WebLockOrientationCallback
// that will resolve the underlying promise depending on the result passed to
// the callback.
class LockOrientationCallback final : public WebLockOrientationCallback {
<<<<<<< HEAD
    USING_FAST_MALLOC(LockOrientationCallback);
    WTF_MAKE_NONCOPYABLE(LockOrientationCallback);

public:
    explicit LockOrientationCallback(ScriptPromiseResolver*);
=======
    WTF_MAKE_NONCOPYABLE(LockOrientationCallback);
public:
    explicit LockOrientationCallback(PassRefPtrWillBeRawPtr<ScriptPromiseResolver>);
>>>>>>> miniblink49
    ~LockOrientationCallback() override;

    void onSuccess() override;
    void onError(WebLockOrientationError) override;

private:
<<<<<<< HEAD
    Persistent<ScriptPromiseResolver> m_resolver;
=======
    RefPtrWillBePersistent<ScriptPromiseResolver> m_resolver;
>>>>>>> miniblink49
};

} // namespace blink

#endif // LockOrientationCallback_h
