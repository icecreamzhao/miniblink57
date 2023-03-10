// Copyright (c) 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_COMPOSITOR_LAYER_THREADED_ANIMATION_DELEGATE_H_
#define UI_COMPOSITOR_LAYER_THREADED_ANIMATION_DELEGATE_H_

#include "base/memory/scoped_ptr.h"
#include "cc/animation/animation.h"
#include "ui/compositor/compositor_export.h"

namespace ui {

// Attach CC animations using this interface.
class COMPOSITOR_EXPORT LayerThreadedAnimationDelegate {
public:
    virtual void AddThreadedAnimation(scoped_ptr<cc::Animation> animation) = 0;
    virtual void RemoveThreadedAnimation(int animation_id) = 0;

protected:
    virtual ~LayerThreadedAnimationDelegate() { }
};

} // namespace ui

#endif // UI_COMPOSITOR_LAYER_THREADED_ANIMATION_DELEGATE_H_
