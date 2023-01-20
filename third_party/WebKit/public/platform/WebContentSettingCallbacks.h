// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebContentSettingCallbacks_h
#define WebContentSettingCallbacks_h

#include "WebPrivatePtr.h"

<<<<<<< HEAD
#if INSIDE_BLINK
#include <memory>
#endif
=======
namespace WTF { template <typename T> class PassOwnPtr; }
>>>>>>> miniblink49

namespace blink {

class ContentSettingCallbacks;
class WebContentSettingCallbacksPrivate;

class WebContentSettingCallbacks {
public:
    ~WebContentSettingCallbacks() { reset(); }
    WebContentSettingCallbacks() { }
    WebContentSettingCallbacks(const WebContentSettingCallbacks& c) { assign(c); }
    WebContentSettingCallbacks& operator=(const WebContentSettingCallbacks& c)
    {
        assign(c);
        return *this;
    }

    BLINK_PLATFORM_EXPORT void reset();
    BLINK_PLATFORM_EXPORT void assign(const WebContentSettingCallbacks&);

#if INSIDE_BLINK
<<<<<<< HEAD
    BLINK_PLATFORM_EXPORT WebContentSettingCallbacks(
        std::unique_ptr<ContentSettingCallbacks>&&);
=======
    BLINK_PLATFORM_EXPORT WebContentSettingCallbacks(const WTF::PassOwnPtr<ContentSettingCallbacks>&);
>>>>>>> miniblink49
#endif

    BLINK_PLATFORM_EXPORT void doAllow();
    BLINK_PLATFORM_EXPORT void doDeny();

private:
    WebPrivatePtr<WebContentSettingCallbacksPrivate> m_private;
};

} // namespace blink

#endif
