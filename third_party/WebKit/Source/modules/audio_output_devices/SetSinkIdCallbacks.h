// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SetSinkIdCallbacks_h
#define SetSinkIdCallbacks_h

#include "platform/Timer.h"
#include "platform/heap/Handle.h"
<<<<<<< HEAD
#include "public/platform/WebSetSinkIdCallbacks.h"
#include "wtf/Noncopyable.h"
#include "wtf/RefPtr.h"
#include "wtf/text/WTFString.h"
=======
#include "public/platform/WebCallbacks.h"
#include "wtf/Noncopyable.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RefPtr.h"
>>>>>>> miniblink49

namespace blink {

class HTMLMediaElement;
class ScriptPromiseResolver;
<<<<<<< HEAD

class SetSinkIdCallbacks final : public WebSetSinkIdCallbacks {
    // FIXME(tasak): When making public/platform classes to use PartitionAlloc,
    // the following macro should be moved to WebCallbacks defined in
    // public/platform/WebCallbacks.h.
    USING_FAST_MALLOC(SetSinkIdCallbacks);
    WTF_MAKE_NONCOPYABLE(SetSinkIdCallbacks);

public:
    SetSinkIdCallbacks(ScriptPromiseResolver*,
        HTMLMediaElement&,
        const String& sinkId);
    ~SetSinkIdCallbacks() override;

    void onSuccess() override;
    void onError(WebSetSinkIdError) override;

private:
    Persistent<ScriptPromiseResolver> m_resolver;
    Persistent<HTMLMediaElement> m_element;
=======
struct WebSetSinkIdError;

class SetSinkIdCallbacks final : public WebCallbacks<void, WebSetSinkIdError> {
    WTF_MAKE_NONCOPYABLE(SetSinkIdCallbacks);
public:
    SetSinkIdCallbacks(PassRefPtrWillBeRawPtr<ScriptPromiseResolver>, HTMLMediaElement&, const String& sinkId);
    ~SetSinkIdCallbacks() override;

    void onSuccess() override;
    void onError(WebSetSinkIdError*) override;

private:
    RefPtrWillBePersistent<ScriptPromiseResolver> m_resolver;
    RefPtrWillBePersistent<HTMLMediaElement> m_element;
>>>>>>> miniblink49
    String m_sinkId;
};

} // namespace blink

#endif // SetSinkIdCallbacks_h
