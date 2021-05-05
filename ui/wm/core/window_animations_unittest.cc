// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/wm/core/window_animations.h"

#include "base/macros.h"
#include "base/time/time.h"
#include "ui/aura/test/aura_test_base.h"
#include "ui/aura/test/test_windows.h"
#include "ui/aura/window.h"
#include "ui/compositor/layer.h"
#include "ui/compositor/layer_animator.h"
#include "ui/compositor/scoped_animation_duration_scale_mode.h"
#include "ui/gfx/animation/animation_container_element.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/wm/core/transient_window_manager.h"
#include "ui/wm/core/transient_window_stacking_client.h"
#include "ui/wm/core/window_util.h"
#include "ui/wm/public/animation_host.h"

using aura::Window;
using ui::Layer;

namespace wm {
namespace {

    template <typename T>
    int GetZPosition(const T* child)
    {
        const T* parent = child->parent();
        const std::vector<T*> children = parent->children();
        typename std::vector<T*>::const_iterator iter = std::find(children.begin(), children.end(), child);
        DCHECK(iter != children.end());
        return iter - children.begin();
    }

    int GetWindowZPosition(const aura::Window* child)
    {
        return GetZPosition<aura::Window>(child);
    }

    int GetLayerZPosition(const ui::Layer* child)
    {
        return GetZPosition<ui::Layer>(child);
    }

} // namespace

class WindowAnimationsTest : public aura::test::AuraTestBase {
public:
    WindowAnimationsTest() { }

    void TearDown() override { AuraTestBase::TearDown(); }

private:
    DISALLOW_COPY_AND_ASSIGN(WindowAnimationsTest);
};

TEST_F(WindowAnimationsTest, LayerTargetVisibility)
{
    scoped_ptr<aura::Window> window(
        aura::test::CreateTestWindowWithId(0, NULL));

    // Layer target visibility changes according to Show/Hide.
    window->Show();
    EXPECT_TRUE(window->layer()->GetTargetVisibility());
    window->Hide();
    EXPECT_FALSE(window->layer()->GetTargetVisibility());
    window->Show();
    EXPECT_TRUE(window->layer()->GetTargetVisibility());
}

TEST_F(WindowAnimationsTest, LayerTargetVisibility_AnimateShow)
{
    // Tests if opacity and transform are reset when only show animation is
    // enabled.  See also LayerTargetVisibility_AnimateHide.
    // Since the window is not visible after Hide() is called, opacity and
    // transform shouldn't matter in case of ANIMATE_SHOW, but we reset them
    // to keep consistency.

    scoped_ptr<aura::Window> window(aura::test::CreateTestWindowWithId(0, NULL));
    SetWindowVisibilityAnimationTransition(window.get(), ANIMATE_SHOW);

    // Layer target visibility and opacity change according to Show/Hide.
    window->Show();
    AnimateOnChildWindowVisibilityChanged(window.get(), true);
    EXPECT_TRUE(window->layer()->GetTargetVisibility());
    EXPECT_EQ(1, window->layer()->opacity());

    window->Hide();
    AnimateOnChildWindowVisibilityChanged(window.get(), false);
    EXPECT_FALSE(window->layer()->GetTargetVisibility());
    EXPECT_EQ(0, window->layer()->opacity());
    EXPECT_EQ(gfx::Transform(), window->layer()->transform());

    window->Show();
    AnimateOnChildWindowVisibilityChanged(window.get(), true);
    EXPECT_TRUE(window->layer()->GetTargetVisibility());
    EXPECT_EQ(1, window->layer()->opacity());
}

TEST_F(WindowAnimationsTest, LayerTargetVisibility_AnimateHide)
{
    // Tests if opacity and transform are reset when only hide animation is
    // enabled.  Hide animation changes opacity and transform in addition to
    // visibility, so we need to reset not only visibility but also opacity
    // and transform to show the window.

    scoped_ptr<aura::Window> window(aura::test::CreateTestWindowWithId(0, NULL));
    SetWindowVisibilityAnimationTransition(window.get(), ANIMATE_HIDE);

    // Layer target visibility and opacity change according to Show/Hide.
    window->Show();
    AnimateOnChildWindowVisibilityChanged(window.get(), true);
    EXPECT_TRUE(window->layer()->GetTargetVisibility());
    EXPECT_EQ(1, window->layer()->opacity());
    EXPECT_EQ(gfx::Transform(), window->layer()->transform());

    window->Hide();
    AnimateOnChildWindowVisibilityChanged(window.get(), false);
    EXPECT_FALSE(window->layer()->GetTargetVisibility());
    EXPECT_EQ(0, window->layer()->opacity());

    window->Show();
    AnimateOnChildWindowVisibilityChanged(window.get(), true);
    EXPECT_TRUE(window->layer()->GetTargetVisibility());
    EXPECT_EQ(1, window->layer()->opacity());
    EXPECT_EQ(gfx::Transform(), window->layer()->transform());
}

TEST_F(WindowAnimationsTest, HideAnimationDetachLayers)
{
    scoped_ptr<aura::Window> parent(aura::test::CreateTestWindowWithId(0, NULL));

    scoped_ptr<aura::Window> other(
        aura::test::CreateTestWindowWithId(1, parent.get()));

    scoped_ptr<aura::Window> animating_window(
        aura::test::CreateTestWindowWithId(2, parent.get()));
    SetWindowVisibilityAnimationTransition(animating_window.get(), ANIMATE_HIDE);

    EXPECT_EQ(0, GetWindowZPosition(other.get()));
    EXPECT_EQ(1, GetWindowZPosition(animating_window.get()));
    EXPECT_EQ(0, GetLayerZPosition(other->layer()));
    EXPECT_EQ(1, GetLayerZPosition(animating_window->layer()));

    {
        ui::ScopedAnimationDurationScaleMode scale_mode(
            ui::ScopedAnimationDurationScaleMode::FAST_DURATION);
        ui::Layer* animating_layer = animating_window->layer();

        animating_window->Hide();
        EXPECT_TRUE(AnimateOnChildWindowVisibilityChanged(
            animating_window.get(), false));
        EXPECT_TRUE(animating_layer->GetAnimator()->is_animating());
        EXPECT_FALSE(animating_layer->delegate());

        // Make sure the Hide animation create another layer, and both are in
        // the parent layer.
        EXPECT_NE(animating_window->layer(), animating_layer);
        EXPECT_TRUE(
            std::find(parent->layer()->children().begin(),
                parent->layer()->children().end(),
                animating_layer)
            != parent->layer()->children().end());
        EXPECT_TRUE(
            std::find(parent->layer()->children().begin(),
                parent->layer()->children().end(),
                animating_window->layer())
            != parent->layer()->children().end());
        // Current layer must be already hidden.
        EXPECT_FALSE(animating_window->layer()->visible());

        EXPECT_EQ(1, GetWindowZPosition(animating_window.get()));
        EXPECT_EQ(1, GetLayerZPosition(animating_window->layer()));
        EXPECT_EQ(2, GetLayerZPosition(animating_layer));

        parent->StackChildAtTop(other.get());
        EXPECT_EQ(0, GetWindowZPosition(animating_window.get()));
        EXPECT_EQ(1, GetWindowZPosition(other.get()));

        EXPECT_EQ(0, GetLayerZPosition(animating_window->layer()));
        EXPECT_EQ(1, GetLayerZPosition(other->layer()));
        // Make sure the animating layer is on top.
        EXPECT_EQ(2, GetLayerZPosition(animating_layer));

        // Animating layer must be gone
        animating_layer->GetAnimator()->StopAnimating();
        EXPECT_TRUE(
            std::find(parent->layer()->children().begin(),
                parent->layer()->children().end(),
                animating_layer)
            == parent->layer()->children().end());
    }
}

TEST_F(WindowAnimationsTest, HideAnimationDetachLayersWithTransientChildren)
{
    TransientWindowStackingClient transient_stacking_client;

    scoped_ptr<aura::Window> parent(aura::test::CreateTestWindowWithId(0, NULL));

    scoped_ptr<aura::Window> other(
        aura::test::CreateTestWindowWithId(1, parent.get()));

    scoped_ptr<aura::Window> animating_window(
        aura::test::CreateTestWindowWithId(2, parent.get()));
    SetWindowVisibilityAnimationTransition(animating_window.get(), ANIMATE_HIDE);

    scoped_ptr<aura::Window> transient1(
        aura::test::CreateTestWindowWithId(3, parent.get()));
    scoped_ptr<aura::Window> transient2(
        aura::test::CreateTestWindowWithId(4, parent.get()));

    TransientWindowManager::Get(animating_window.get());
    AddTransientChild(animating_window.get(), transient1.get());
    AddTransientChild(animating_window.get(), transient2.get());

    EXPECT_EQ(0, GetWindowZPosition(other.get()));
    EXPECT_EQ(1, GetWindowZPosition(animating_window.get()));
    EXPECT_EQ(2, GetWindowZPosition(transient1.get()));
    EXPECT_EQ(3, GetWindowZPosition(transient2.get()));

    {
        ui::ScopedAnimationDurationScaleMode scale_mode(
            ui::ScopedAnimationDurationScaleMode::FAST_DURATION);
        ui::Layer* animating_layer = animating_window->layer();

        animating_window->Hide();
        EXPECT_TRUE(AnimateOnChildWindowVisibilityChanged(
            animating_window.get(), false));
        EXPECT_TRUE(animating_layer->GetAnimator()->is_animating());
        EXPECT_FALSE(animating_layer->delegate());

        EXPECT_EQ(1, GetWindowZPosition(animating_window.get()));
        EXPECT_EQ(2, GetWindowZPosition(transient1.get()));
        EXPECT_EQ(3, GetWindowZPosition(transient2.get()));

        EXPECT_EQ(1, GetLayerZPosition(animating_window->layer()));
        EXPECT_EQ(2, GetLayerZPosition(transient1->layer()));
        EXPECT_EQ(3, GetLayerZPosition(transient2->layer()));
        EXPECT_EQ(4, GetLayerZPosition(animating_layer));

        parent->StackChildAtTop(other.get());

        EXPECT_EQ(0, GetWindowZPosition(animating_window.get()));
        EXPECT_EQ(1, GetWindowZPosition(transient1.get()));
        EXPECT_EQ(2, GetWindowZPosition(transient2.get()));
        EXPECT_EQ(3, GetWindowZPosition(other.get()));

        EXPECT_EQ(0, GetLayerZPosition(animating_window->layer()));
        EXPECT_EQ(1, GetLayerZPosition(transient1->layer()));
        EXPECT_EQ(2, GetLayerZPosition(transient2->layer()));
        EXPECT_EQ(3, GetLayerZPosition(other->layer()));
        // Make sure the animating layer is on top of all windows.
        EXPECT_EQ(4, GetLayerZPosition(animating_layer));
    }
}

// A simple AnimationHost implementation for the NotifyHideCompleted test.
class NotifyHideCompletedAnimationHost : public aura::client::AnimationHost {
public:
    NotifyHideCompletedAnimationHost()
        : hide_completed_(false)
    {
    }
    ~NotifyHideCompletedAnimationHost() override { }

    // Overridden from TestWindowDelegate:
    void OnWindowHidingAnimationCompleted() override { hide_completed_ = true; }

    void SetHostTransitionOffsets(const gfx::Vector2d& top_left,
        const gfx::Vector2d& bottom_right) override { }

    bool hide_completed() const { return hide_completed_; }

private:
    bool hide_completed_;

    DISALLOW_COPY_AND_ASSIGN(NotifyHideCompletedAnimationHost);
};

TEST_F(WindowAnimationsTest, NotifyHideCompleted)
{
    NotifyHideCompletedAnimationHost animation_host;
    scoped_ptr<aura::Window> window(aura::test::CreateTestWindowWithId(0, NULL));
    aura::client::SetAnimationHost(window.get(), &animation_host);
    wm::SetWindowVisibilityAnimationType(
        window.get(), WINDOW_VISIBILITY_ANIMATION_TYPE_FADE);
    AnimateOnChildWindowVisibilityChanged(window.get(), true);
    EXPECT_TRUE(window->layer()->visible());

    EXPECT_FALSE(animation_host.hide_completed());
    AnimateOnChildWindowVisibilityChanged(window.get(), false);
    EXPECT_TRUE(animation_host.hide_completed());
}

// The rotation animation for hiding a window should not leak the animation
// observer.
TEST_F(WindowAnimationsTest, RotateHideNoLeak)
{
    ui::ScopedAnimationDurationScaleMode scale_mode(
        ui::ScopedAnimationDurationScaleMode::FAST_DURATION);

    scoped_ptr<aura::Window> window(aura::test::CreateTestWindowWithId(0, NULL));
    ui::Layer* animating_layer = window->layer();
    wm::SetWindowVisibilityAnimationType(window.get(),
        WINDOW_VISIBILITY_ANIMATION_TYPE_ROTATE);

    AnimateOnChildWindowVisibilityChanged(window.get(), true);
    AnimateOnChildWindowVisibilityChanged(window.get(), false);

    animating_layer->GetAnimator()->StopAnimating();
}

// The rotation animation for hiding a window should not crash when terminated
// by LayerAnimator::StopAnimating().
TEST_F(WindowAnimationsTest, RotateHideNoCrash)
{
    ui::ScopedAnimationDurationScaleMode scale_mode(
        ui::ScopedAnimationDurationScaleMode::FAST_DURATION);

    scoped_ptr<aura::Window> window(aura::test::CreateTestWindowWithId(0, NULL));
    ui::Layer* animating_layer = window->layer();
    wm::SetWindowVisibilityAnimationType(window.get(),
        WINDOW_VISIBILITY_ANIMATION_TYPE_ROTATE);
    AnimateOnChildWindowVisibilityChanged(window.get(), true);
    window->layer()->GetAnimator()->Step(base::TimeTicks::Now() + base::TimeDelta::FromSeconds(5));
    AnimateOnChildWindowVisibilityChanged(window.get(), false);
    animating_layer->GetAnimator()->StopAnimating();
}

} // namespace wm
