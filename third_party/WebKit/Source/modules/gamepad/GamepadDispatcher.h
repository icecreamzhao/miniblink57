// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GamepadDispatcher_h
#define GamepadDispatcher_h

#include "core/frame/PlatformEventDispatcher.h"
#include "platform/heap/Handle.h"
#include "public/platform/WebGamepad.h"
#include "public/platform/WebGamepadListener.h"

namespace blink {

class WebGamepads;

<<<<<<< HEAD
class GamepadDispatcher final
    : public GarbageCollectedFinalized<GamepadDispatcher>,
      public PlatformEventDispatcher,
      public WebGamepadListener {
    USING_GARBAGE_COLLECTED_MIXIN(GamepadDispatcher);

=======
class GamepadDispatcher final : public GarbageCollectedFinalized<GamepadDispatcher>, public PlatformEventDispatcher, public WebGamepadListener {
    USING_GARBAGE_COLLECTED_MIXIN(GamepadDispatcher);
>>>>>>> miniblink49
public:
    static GamepadDispatcher& instance();
    ~GamepadDispatcher() override;

    void sampleGamepads(WebGamepads&);

    struct ConnectionChange {
<<<<<<< HEAD
        DISALLOW_NEW();
=======
>>>>>>> miniblink49
        WebGamepad pad;
        unsigned index;
    };

<<<<<<< HEAD
    const ConnectionChange& latestConnectionChange() const
    {
        return m_latestChange;
    }
=======
    const ConnectionChange& latestConnectionChange() const { return m_latestChange; }
>>>>>>> miniblink49

    DECLARE_VIRTUAL_TRACE();

private:
    GamepadDispatcher();

    // WebGamepadListener
    void didConnectGamepad(unsigned index, const WebGamepad&) override;
    void didDisconnectGamepad(unsigned index, const WebGamepad&) override;

    // PlatformEventDispatcher
    void startListening() override;
    void stopListening() override;

<<<<<<< HEAD
    void dispatchDidConnectOrDisconnectGamepad(unsigned index,
        const WebGamepad&,
        bool connected);
=======
    void dispatchDidConnectOrDisconnectGamepad(unsigned index, const WebGamepad&, bool connected);
>>>>>>> miniblink49

    ConnectionChange m_latestChange;
};

} // namespace blink

#endif
