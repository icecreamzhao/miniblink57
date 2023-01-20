// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebFrameLoadType_h
#define WebFrameLoadType_h

<<<<<<< HEAD
=======

>>>>>>> miniblink49
namespace blink {

// The type of load for a navigation.
// TODO(clamy): Return a WebFrameLoadType instead of a WebHistoryCommitType
// in DidCommitProvisionalLoad.
<<<<<<< HEAD
//
// Standard:
//   Follows network and cache protocols, e.g. using cached entries unless
//   they are expired. Used in usual navigations.
// BackForward:
//   Uses cached entries even if the entries are stale. Used in history back and
//   forward navigations.
// Reload:
//   Revalidates cached entries even if the entries are fresh. Used in usual
//   reload.
// ReloadMainResource:
//   Revalidates a cached entry for the main resource if one exists, but follows
//   protocols for other subresources. Blink internally uses this for the same
//   page navigation. Also used in optimized reload for mobiles in a field
//   trial.
// ReplaceCurrentItem:
//   Same as Standard, but replaces current navigation entry in the history.
// InitialInChildFrame:
//   Used in the first load for a subframe.
// InitialHistoryLoad:
//   Used in history navigation in a newly created frame.
// ReloadBypassingCache:
//   Bypasses any caches, memory and disk cache in the browser, and caches in
//   proxy servers, to fetch fresh contents directly from the end server.
//   Used in Shift-Reload.
=======
>>>>>>> miniblink49
enum class WebFrameLoadType {
    Standard,
    BackForward,
    Reload,
<<<<<<< HEAD
    ReloadMainResource,
    ReplaceCurrentItem,
    InitialInChildFrame,
    InitialHistoryLoad,
    ReloadBypassingCache,
=======
    Same, // user loads same URL again (but not reload button)
    RedirectWithLockedBackForwardList,
    InitialInChildFrame,
    InitialHistoryLoad, // history navigation in a newly created frame
    ReloadFromOrigin, // reload bypassing cache
>>>>>>> miniblink49
};

} // namespace blink

#endif // WebFrameLoadType_h
<<<<<<< HEAD
=======

>>>>>>> miniblink49
