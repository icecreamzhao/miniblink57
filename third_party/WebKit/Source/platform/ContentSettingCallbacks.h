// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ContentSettingCallbacks_h
#define ContentSettingCallbacks_h

#include "platform/PlatformExport.h"
<<<<<<< HEAD
#include "wtf/Allocator.h"
#include "wtf/Functional.h"
#include "wtf/Noncopyable.h"
#include <memory>
=======
#include "wtf/Functional.h"
#include "wtf/Noncopyable.h"
#include "wtf/OwnPtr.h"
#include "wtf/PassOwnPtr.h"
>>>>>>> miniblink49

namespace blink {

class PLATFORM_EXPORT ContentSettingCallbacks {
<<<<<<< HEAD
    USING_FAST_MALLOC(ContentSettingCallbacks);
    WTF_MAKE_NONCOPYABLE(ContentSettingCallbacks);

public:
    static std::unique_ptr<ContentSettingCallbacks> create(
        std::unique_ptr<WTF::Closure> allowed,
        std::unique_ptr<WTF::Closure> denied);
=======
    WTF_MAKE_NONCOPYABLE(ContentSettingCallbacks);
public:
    static PassOwnPtr<ContentSettingCallbacks> create(PassOwnPtr<Closure> allowed, PassOwnPtr<Closure> denied);
>>>>>>> miniblink49
    virtual ~ContentSettingCallbacks() { }

    void onAllowed() { (*m_allowed)(); }
    void onDenied() { (*m_denied)(); }

private:
<<<<<<< HEAD
    ContentSettingCallbacks(std::unique_ptr<WTF::Closure> allowed,
        std::unique_ptr<WTF::Closure> denied);

    std::unique_ptr<WTF::Closure> m_allowed;
    std::unique_ptr<WTF::Closure> m_denied;
=======
    ContentSettingCallbacks(PassOwnPtr<Closure> allowed, PassOwnPtr<Closure> denied);

    OwnPtr<Closure> m_allowed;
    OwnPtr<Closure> m_denied;
>>>>>>> miniblink49
};

} // namespace blink

#endif // ContentSettingCallbacks_h
