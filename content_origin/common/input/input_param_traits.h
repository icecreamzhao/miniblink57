// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file defines IPC::ParamTraits<> specializations for several
// input-related types that require manual serialiation code.

#ifndef CONTENT_COMMON_INPUT_INPUT_PARAM_TRAITS_H_
#define CONTENT_COMMON_INPUT_INPUT_PARAM_TRAITS_H_

#include "content/common/content_export.h"
#include "content/common/content_param_traits_macros.h"
#include "content/common/input/synthetic_gesture_packet.h"
#include "third_party/WebKit/public/platform/WebCoalescedInputEvent.h"

namespace IPC {

template <>
struct CONTENT_EXPORT ParamTraits<blink::WebScopedInputEvent> {
    typedef blink::WebScopedInputEvent param_type;
    static void GetSize(base::PickleSizer* s, const param_type& p);
    static void Write(base::Pickle* m, const param_type& p);
    static bool Read(const base::Pickle* m,
        base::PickleIterator* iter,
        param_type* r);
    static void Log(const param_type& p, std::string* l);
};

template <>
struct CONTENT_EXPORT ParamTraits<content::SyntheticGesturePacket> {
    typedef content::SyntheticGesturePacket param_type;
    static void Write(base::Pickle* m, const param_type& p);
    static bool Read(const base::Pickle* m,
        base::PickleIterator* iter,
        param_type* r);
    static void Log(const param_type& p, std::string* l);
};

} // namespace IPC

#endif // CONTENT_COMMON_INPUT_INPUT_PARAM_TRAITS_H_
