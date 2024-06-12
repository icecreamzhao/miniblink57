// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef EventTypeNames_h
#define EventTypeNames_h

#include "core/CoreExport.h"
#include "wtf/text/AtomicString.h"

// Generated from:
// - ../../third_party/WebKit/Source/core/events/EventTypeNames.in

namespace blink {
namespace EventTypeNames {

    CORE_EXPORT extern const WTF::AtomicString& DOMActivate;
    CORE_EXPORT extern const WTF::AtomicString& DOMCharacterDataModified;
    CORE_EXPORT extern const WTF::AtomicString& DOMContentLoaded;
    CORE_EXPORT extern const WTF::AtomicString& DOMFocusIn;
    CORE_EXPORT extern const WTF::AtomicString& DOMFocusOut;
    CORE_EXPORT extern const WTF::AtomicString& DOMNodeInserted;
    CORE_EXPORT extern const WTF::AtomicString& DOMNodeInsertedIntoDocument;
    CORE_EXPORT extern const WTF::AtomicString& DOMNodeRemoved;
    CORE_EXPORT extern const WTF::AtomicString& DOMNodeRemovedFromDocument;
    CORE_EXPORT extern const WTF::AtomicString& DOMSubtreeModified;
    CORE_EXPORT extern const WTF::AtomicString& abort;
    CORE_EXPORT extern const WTF::AtomicString& activate;
    CORE_EXPORT extern const WTF::AtomicString& active;
    CORE_EXPORT extern const WTF::AtomicString& addsourcebuffer;
    CORE_EXPORT extern const WTF::AtomicString& addstream;
    CORE_EXPORT extern const WTF::AtomicString& addtrack;
    CORE_EXPORT extern const WTF::AtomicString& animationend;
    CORE_EXPORT extern const WTF::AtomicString& animationiteration;
    CORE_EXPORT extern const WTF::AtomicString& animationstart;
    CORE_EXPORT extern const WTF::AtomicString& appinstalled;
    CORE_EXPORT extern const WTF::AtomicString& audioend;
    CORE_EXPORT extern const WTF::AtomicString& audioprocess;
    CORE_EXPORT extern const WTF::AtomicString& audiostart;
    CORE_EXPORT extern const WTF::AtomicString& auxclick;
    CORE_EXPORT extern const WTF::AtomicString& availablechange;
    CORE_EXPORT extern const WTF::AtomicString& beforecopy;
    CORE_EXPORT extern const WTF::AtomicString& beforecut;
    CORE_EXPORT extern const WTF::AtomicString& beforeinput;
    CORE_EXPORT extern const WTF::AtomicString& beforeinstallprompt;
    CORE_EXPORT extern const WTF::AtomicString& beforepaste;
    CORE_EXPORT extern const WTF::AtomicString& beforeunload;
    CORE_EXPORT extern const WTF::AtomicString& beginEvent;
    CORE_EXPORT extern const WTF::AtomicString& blocked;
    CORE_EXPORT extern const WTF::AtomicString& blur;
    CORE_EXPORT extern const WTF::AtomicString& boundary;
    CORE_EXPORT extern const WTF::AtomicString& bufferedamountlow;
    CORE_EXPORT extern const WTF::AtomicString& cached;
    CORE_EXPORT extern const WTF::AtomicString& cancel;
    CORE_EXPORT extern const WTF::AtomicString& canplay;
    CORE_EXPORT extern const WTF::AtomicString& canplaythrough;
    CORE_EXPORT extern const WTF::AtomicString& change;
    CORE_EXPORT extern const WTF::AtomicString& characteristicvaluechanged;
    CORE_EXPORT extern const WTF::AtomicString& chargingchange;
    CORE_EXPORT extern const WTF::AtomicString& chargingtimechange;
    CORE_EXPORT extern const WTF::AtomicString& checking;
    CORE_EXPORT extern const WTF::AtomicString& click;
    CORE_EXPORT extern const WTF::AtomicString& close;
    CORE_EXPORT extern const WTF::AtomicString& complete;
    CORE_EXPORT extern const WTF::AtomicString& compositionend;
    CORE_EXPORT extern const WTF::AtomicString& compositionstart;
    CORE_EXPORT extern const WTF::AtomicString& compositionupdate;
    CORE_EXPORT extern const WTF::AtomicString& connect;
    CORE_EXPORT extern const WTF::AtomicString& connecting;
    CORE_EXPORT extern const WTF::AtomicString& connectionavailable;
    CORE_EXPORT extern const WTF::AtomicString& contextlost;
    CORE_EXPORT extern const WTF::AtomicString& contextmenu;
    CORE_EXPORT extern const WTF::AtomicString& contextrestored;
    CORE_EXPORT extern const WTF::AtomicString& controllerchange;
    CORE_EXPORT extern const WTF::AtomicString& copy;
    CORE_EXPORT extern const WTF::AtomicString& crossoriginmessage;
    CORE_EXPORT extern const WTF::AtomicString& cuechange;
    CORE_EXPORT extern const WTF::AtomicString& cut;
    CORE_EXPORT extern const WTF::AtomicString& dataavailable;
    CORE_EXPORT extern const WTF::AtomicString& datachannel;
    CORE_EXPORT extern const WTF::AtomicString& dblclick;
    CORE_EXPORT extern const WTF::AtomicString& defaultsessionstart;
    CORE_EXPORT extern const WTF::AtomicString& devicechange;
    CORE_EXPORT extern const WTF::AtomicString& devicelight;
    CORE_EXPORT extern const WTF::AtomicString& devicemotion;
    CORE_EXPORT extern const WTF::AtomicString& deviceorientation;
    CORE_EXPORT extern const WTF::AtomicString& deviceorientationabsolute;
    CORE_EXPORT extern const WTF::AtomicString& dischargingtimechange;
    CORE_EXPORT extern const WTF::AtomicString& disconnect;
    CORE_EXPORT extern const WTF::AtomicString& display;
    CORE_EXPORT extern const WTF::AtomicString& downloading;
    CORE_EXPORT extern const WTF::AtomicString& drag;
    CORE_EXPORT extern const WTF::AtomicString& dragend;
    CORE_EXPORT extern const WTF::AtomicString& dragenter;
    CORE_EXPORT extern const WTF::AtomicString& dragleave;
    CORE_EXPORT extern const WTF::AtomicString& dragover;
    CORE_EXPORT extern const WTF::AtomicString& dragstart;
    CORE_EXPORT extern const WTF::AtomicString& drop;
    CORE_EXPORT extern const WTF::AtomicString& durationchange;
    CORE_EXPORT extern const WTF::AtomicString& emptied;
    CORE_EXPORT extern const WTF::AtomicString& encrypted;
    CORE_EXPORT extern const WTF::AtomicString& end;
    CORE_EXPORT extern const WTF::AtomicString& endEvent;
    CORE_EXPORT extern const WTF::AtomicString& ended;
    CORE_EXPORT extern const WTF::AtomicString& enter;
    CORE_EXPORT extern const WTF::AtomicString& error;
    CORE_EXPORT extern const WTF::AtomicString& exit;
    CORE_EXPORT extern const WTF::AtomicString& fetch;
    CORE_EXPORT extern const WTF::AtomicString& finish;
    CORE_EXPORT extern const WTF::AtomicString& focus;
    CORE_EXPORT extern const WTF::AtomicString& focusin;
    CORE_EXPORT extern const WTF::AtomicString& focusout;
    CORE_EXPORT extern const WTF::AtomicString& foreignfetch;
    CORE_EXPORT extern const WTF::AtomicString& frametimingbufferfull;
    CORE_EXPORT extern const WTF::AtomicString& fullscreenchange;
    CORE_EXPORT extern const WTF::AtomicString& fullscreenerror;
    CORE_EXPORT extern const WTF::AtomicString& gamepadconnected;
    CORE_EXPORT extern const WTF::AtomicString& gamepaddisconnected;
    CORE_EXPORT extern const WTF::AtomicString& gattserverdisconnected;
    CORE_EXPORT extern const WTF::AtomicString& geofenceenter;
    CORE_EXPORT extern const WTF::AtomicString& geofenceleave;
    CORE_EXPORT extern const WTF::AtomicString& gestureflingstart;
    CORE_EXPORT extern const WTF::AtomicString& gesturelongpress;
    CORE_EXPORT extern const WTF::AtomicString& gesturescrollend;
    CORE_EXPORT extern const WTF::AtomicString& gesturescrollstart;
    CORE_EXPORT extern const WTF::AtomicString& gesturescrollupdate;
    CORE_EXPORT extern const WTF::AtomicString& gestureshowpress;
    CORE_EXPORT extern const WTF::AtomicString& gesturetap;
    CORE_EXPORT extern const WTF::AtomicString& gesturetapdown;
    CORE_EXPORT extern const WTF::AtomicString& gesturetapunconfirmed;
    CORE_EXPORT extern const WTF::AtomicString& gotpointercapture;
    CORE_EXPORT extern const WTF::AtomicString& hashchange;
    CORE_EXPORT extern const WTF::AtomicString& icecandidate;
    CORE_EXPORT extern const WTF::AtomicString& iceconnectionstatechange;
    CORE_EXPORT extern const WTF::AtomicString& inactive;
    CORE_EXPORT extern const WTF::AtomicString& input;
    CORE_EXPORT extern const WTF::AtomicString& install;
    CORE_EXPORT extern const WTF::AtomicString& invalid;
    CORE_EXPORT extern const WTF::AtomicString& keydown;
    CORE_EXPORT extern const WTF::AtomicString& keypress;
    CORE_EXPORT extern const WTF::AtomicString& keystatuseschange;
    CORE_EXPORT extern const WTF::AtomicString& keyup;
    CORE_EXPORT extern const WTF::AtomicString& languagechange;
    CORE_EXPORT extern const WTF::AtomicString& levelchange;
    CORE_EXPORT extern const WTF::AtomicString& load;
    CORE_EXPORT extern const WTF::AtomicString& loadeddata;
    CORE_EXPORT extern const WTF::AtomicString& loadedmetadata;
    CORE_EXPORT extern const WTF::AtomicString& loadend;
    CORE_EXPORT extern const WTF::AtomicString& loading;
    CORE_EXPORT extern const WTF::AtomicString& loadingdone;
    CORE_EXPORT extern const WTF::AtomicString& loadingerror;
    CORE_EXPORT extern const WTF::AtomicString& loadstart;
    CORE_EXPORT extern const WTF::AtomicString& lostpointercapture;
    CORE_EXPORT extern const WTF::AtomicString& mark;
    CORE_EXPORT extern const WTF::AtomicString& message;
    CORE_EXPORT extern const WTF::AtomicString& midimessage;
    CORE_EXPORT extern const WTF::AtomicString& mousedown;
    CORE_EXPORT extern const WTF::AtomicString& mouseenter;
    CORE_EXPORT extern const WTF::AtomicString& mouseleave;
    CORE_EXPORT extern const WTF::AtomicString& mousemove;
    CORE_EXPORT extern const WTF::AtomicString& mouseout;
    CORE_EXPORT extern const WTF::AtomicString& mouseover;
    CORE_EXPORT extern const WTF::AtomicString& mouseup;
    CORE_EXPORT extern const WTF::AtomicString& mousewheel;
    CORE_EXPORT extern const WTF::AtomicString& mute;
    CORE_EXPORT extern const WTF::AtomicString& negotiationneeded;
    CORE_EXPORT extern const WTF::AtomicString& nomatch;
    CORE_EXPORT extern const WTF::AtomicString& notificationclick;
    CORE_EXPORT extern const WTF::AtomicString& notificationclose;
    CORE_EXPORT extern const WTF::AtomicString& notificationerror;
    CORE_EXPORT extern const WTF::AtomicString& noupdate;
    CORE_EXPORT extern const WTF::AtomicString& obsolete;
    CORE_EXPORT extern const WTF::AtomicString& offline;
    CORE_EXPORT extern const WTF::AtomicString& online;
    CORE_EXPORT extern const WTF::AtomicString& open;
    CORE_EXPORT extern const WTF::AtomicString& orientationchange;
    CORE_EXPORT extern const WTF::AtomicString& pagehide;
    CORE_EXPORT extern const WTF::AtomicString& pageshow;
    CORE_EXPORT extern const WTF::AtomicString& paste;
    CORE_EXPORT extern const WTF::AtomicString& pause;
    CORE_EXPORT extern const WTF::AtomicString& paymentrequest;
    CORE_EXPORT extern const WTF::AtomicString& periodicsync;
    CORE_EXPORT extern const WTF::AtomicString& play;
    CORE_EXPORT extern const WTF::AtomicString& playing;
    CORE_EXPORT extern const WTF::AtomicString& pointercancel;
    CORE_EXPORT extern const WTF::AtomicString& pointerdown;
    CORE_EXPORT extern const WTF::AtomicString& pointerenter;
    CORE_EXPORT extern const WTF::AtomicString& pointerleave;
    CORE_EXPORT extern const WTF::AtomicString& pointerlockchange;
    CORE_EXPORT extern const WTF::AtomicString& pointerlockerror;
    CORE_EXPORT extern const WTF::AtomicString& pointermove;
    CORE_EXPORT extern const WTF::AtomicString& pointerout;
    CORE_EXPORT extern const WTF::AtomicString& pointerover;
    CORE_EXPORT extern const WTF::AtomicString& pointerup;
    CORE_EXPORT extern const WTF::AtomicString& popstate;
    CORE_EXPORT extern const WTF::AtomicString& progress;
    CORE_EXPORT extern const WTF::AtomicString& push;
    CORE_EXPORT extern const WTF::AtomicString& ratechange;
    CORE_EXPORT extern const WTF::AtomicString& readystatechange;
    CORE_EXPORT extern const WTF::AtomicString& rejectionhandled;
    CORE_EXPORT extern const WTF::AtomicString& removesourcebuffer;
    CORE_EXPORT extern const WTF::AtomicString& removestream;
    CORE_EXPORT extern const WTF::AtomicString& removetrack;
    CORE_EXPORT extern const WTF::AtomicString& repeatEvent;
    CORE_EXPORT extern const WTF::AtomicString& reset;
    CORE_EXPORT extern const WTF::AtomicString& resize;
    CORE_EXPORT extern const WTF::AtomicString& resourcetimingbufferfull;
    CORE_EXPORT extern const WTF::AtomicString& result;
    CORE_EXPORT extern const WTF::AtomicString& resume;
    CORE_EXPORT extern const WTF::AtomicString& scroll;
    CORE_EXPORT extern const WTF::AtomicString& search;
    CORE_EXPORT extern const WTF::AtomicString& securitypolicyviolation;
    CORE_EXPORT extern const WTF::AtomicString& seeked;
    CORE_EXPORT extern const WTF::AtomicString& seeking;
    CORE_EXPORT extern const WTF::AtomicString& select;
    CORE_EXPORT extern const WTF::AtomicString& selectionchange;
    CORE_EXPORT extern const WTF::AtomicString& selectstart;
    CORE_EXPORT extern const WTF::AtomicString& shippingaddresschange;
    CORE_EXPORT extern const WTF::AtomicString& shippingoptionchange;
    CORE_EXPORT extern const WTF::AtomicString& show;
    CORE_EXPORT extern const WTF::AtomicString& signalingstatechange;
    CORE_EXPORT extern const WTF::AtomicString& slotchange;
    CORE_EXPORT extern const WTF::AtomicString& soundend;
    CORE_EXPORT extern const WTF::AtomicString& soundstart;
    CORE_EXPORT extern const WTF::AtomicString& sourceclose;
    CORE_EXPORT extern const WTF::AtomicString& sourceended;
    CORE_EXPORT extern const WTF::AtomicString& sourceopen;
    CORE_EXPORT extern const WTF::AtomicString& speechend;
    CORE_EXPORT extern const WTF::AtomicString& speechstart;
    CORE_EXPORT extern const WTF::AtomicString& stalled;
    CORE_EXPORT extern const WTF::AtomicString& start;
    CORE_EXPORT extern const WTF::AtomicString& statechange;
    CORE_EXPORT extern const WTF::AtomicString& stop;
    CORE_EXPORT extern const WTF::AtomicString& storage;
    CORE_EXPORT extern const WTF::AtomicString& submit;
    CORE_EXPORT extern const WTF::AtomicString& success;
    CORE_EXPORT extern const WTF::AtomicString& suspend;
    CORE_EXPORT extern const WTF::AtomicString& sync;
    CORE_EXPORT extern const WTF::AtomicString& terminate;
    CORE_EXPORT extern const WTF::AtomicString& textInput;
    CORE_EXPORT extern const WTF::AtomicString& timeout;
    CORE_EXPORT extern const WTF::AtomicString& timeupdate;
    CORE_EXPORT extern const WTF::AtomicString& toggle;
    CORE_EXPORT extern const WTF::AtomicString& tonechange;
    CORE_EXPORT extern const WTF::AtomicString& touchcancel;
    CORE_EXPORT extern const WTF::AtomicString& touchend;
    CORE_EXPORT extern const WTF::AtomicString& touchmove;
    CORE_EXPORT extern const WTF::AtomicString& touchstart;
    CORE_EXPORT extern const WTF::AtomicString& transitionend;
    CORE_EXPORT extern const WTF::AtomicString& typechange;
    CORE_EXPORT extern const WTF::AtomicString& unhandledrejection;
    CORE_EXPORT extern const WTF::AtomicString& unload;
    CORE_EXPORT extern const WTF::AtomicString& unmute;
    CORE_EXPORT extern const WTF::AtomicString& update;
    CORE_EXPORT extern const WTF::AtomicString& updateend;
    CORE_EXPORT extern const WTF::AtomicString& updatefound;
    CORE_EXPORT extern const WTF::AtomicString& updateready;
    CORE_EXPORT extern const WTF::AtomicString& updatestart;
    CORE_EXPORT extern const WTF::AtomicString& upgradeneeded;
    CORE_EXPORT extern const WTF::AtomicString& versionchange;
    CORE_EXPORT extern const WTF::AtomicString& visibilitychange;
    CORE_EXPORT extern const WTF::AtomicString& voiceschanged;
    CORE_EXPORT extern const WTF::AtomicString& volumechange;
    CORE_EXPORT extern const WTF::AtomicString& vrdisplayactivate;
    CORE_EXPORT extern const WTF::AtomicString& vrdisplayblur;
    CORE_EXPORT extern const WTF::AtomicString& vrdisplayconnect;
    CORE_EXPORT extern const WTF::AtomicString& vrdisplaydeactivate;
    CORE_EXPORT extern const WTF::AtomicString& vrdisplaydisconnect;
    CORE_EXPORT extern const WTF::AtomicString& vrdisplayfocus;
    CORE_EXPORT extern const WTF::AtomicString& vrdisplaypresentchange;
    CORE_EXPORT extern const WTF::AtomicString& waiting;
    CORE_EXPORT extern const WTF::AtomicString& waitingforkey;
    CORE_EXPORT extern const WTF::AtomicString& webglcontextcreationerror;
    CORE_EXPORT extern const WTF::AtomicString& webglcontextlost;
    CORE_EXPORT extern const WTF::AtomicString& webglcontextrestored;
    CORE_EXPORT extern const WTF::AtomicString& webkitAnimationEnd;
    CORE_EXPORT extern const WTF::AtomicString& webkitAnimationIteration;
    CORE_EXPORT extern const WTF::AtomicString& webkitAnimationStart;
    CORE_EXPORT extern const WTF::AtomicString& webkitBeforeTextInserted;
    CORE_EXPORT extern const WTF::AtomicString& webkitEditableContentChanged;
    CORE_EXPORT extern const WTF::AtomicString& webkitTransitionEnd;
    CORE_EXPORT extern const WTF::AtomicString& webkitfullscreenchange;
    CORE_EXPORT extern const WTF::AtomicString& webkitfullscreenerror;
    CORE_EXPORT extern const WTF::AtomicString& webkitprerenderdomcontentloaded;
    CORE_EXPORT extern const WTF::AtomicString& webkitprerenderload;
    CORE_EXPORT extern const WTF::AtomicString& webkitprerenderstart;
    CORE_EXPORT extern const WTF::AtomicString& webkitprerenderstop;
    CORE_EXPORT extern const WTF::AtomicString& webkitspeechchange;
    CORE_EXPORT extern const WTF::AtomicString& webkitvisibilitychange;
    CORE_EXPORT extern const WTF::AtomicString& wheel;
    CORE_EXPORT extern const WTF::AtomicString& write;
    CORE_EXPORT extern const WTF::AtomicString& writeend;
    CORE_EXPORT extern const WTF::AtomicString& writestart;
    CORE_EXPORT extern const WTF::AtomicString& zoom;

    const unsigned EventTypeNamesCount = 278;

    CORE_EXPORT void init();

} // EventTypeNames
} // namespace blink

#endif
