// Copyright 2018 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/builtins/builtins-utils-inl.h"
#include "src/counters.h"
#include "src/objects/js-weak-refs-inl.h"

namespace v8 {
namespace internal {

    BUILTIN(FinalizationGroupConstructor)
    {
        HandleScope scope(isolate);
        Handle<JSFunction> target = args.target();
        if (args.new_target()->IsUndefined(isolate)) { // [[Call]]
            THROW_NEW_ERROR_RETURN_FAILURE(
                isolate, NewTypeError(MessageTemplate::kConstructorNotFunction, handle(target->shared()->Name(), isolate)));
        }
        // [[Construct]]
        Handle<JSReceiver> new_target = Handle<JSReceiver>::cast(args.new_target());
        Handle<Object> cleanup = args.atOrUndefined(isolate, 1);

        if (!cleanup->IsCallable()) {
            THROW_NEW_ERROR_RETURN_FAILURE(
                isolate, NewTypeError(MessageTemplate::kWeakRefsCleanupMustBeCallable));
        }

        Handle<JSObject> result;
        ASSIGN_RETURN_FAILURE_ON_EXCEPTION(
            isolate, result,
            JSObject::New(target, new_target, Handle<AllocationSite>::null()));

        Handle<JSFinalizationGroup> finalization_group = Handle<JSFinalizationGroup>::cast(result);
        finalization_group->set_native_context(*isolate->native_context());
        finalization_group->set_cleanup(*cleanup);
        finalization_group->set_flags(
            JSFinalizationGroup::ScheduledForCleanupField::encode(false));

        DCHECK(finalization_group->active_cells()->IsUndefined(isolate));
        DCHECK(finalization_group->cleared_cells()->IsUndefined(isolate));
        DCHECK(finalization_group->key_map()->IsUndefined(isolate));
        return *finalization_group;
    }

    BUILTIN(FinalizationGroupRegister)
    {
        HandleScope scope(isolate);
        const char* method_name = "FinalizationGroup.prototype.register";

        CHECK_RECEIVER(JSFinalizationGroup, finalization_group, method_name);

        Handle<Object> target = args.atOrUndefined(isolate, 1);
        if (!target->IsJSReceiver()) {
            THROW_NEW_ERROR_RETURN_FAILURE(
                isolate,
                NewTypeError(MessageTemplate::kWeakRefsRegisterTargetMustBeObject));
        }
        Handle<Object> holdings = args.atOrUndefined(isolate, 2);
        if (target->SameValue(*holdings)) {
            THROW_NEW_ERROR_RETURN_FAILURE(
                isolate,
                NewTypeError(
                    MessageTemplate::kWeakRefsRegisterTargetAndHoldingsMustNotBeSame));
        }

        Handle<Object> key = args.atOrUndefined(isolate, 3);
        // TODO(marja, gsathya): Restrictions on "key" (e.g., does it need to be an
        // object).

        // TODO(marja): Realms.

        JSFinalizationGroup::Register(finalization_group,
            Handle<JSReceiver>::cast(target), holdings, key,
            isolate);
        return ReadOnlyRoots(isolate).undefined_value();
    }

    BUILTIN(FinalizationGroupUnregister)
    {
        HandleScope scope(isolate);
        const char* method_name = "FinalizationGroup.prototype.unregister";

        CHECK_RECEIVER(JSFinalizationGroup, finalization_group, method_name);

        Handle<Object> key = args.atOrUndefined(isolate, 1);
        JSFinalizationGroup::Unregister(finalization_group, key, isolate);
        return ReadOnlyRoots(isolate).undefined_value();
    }

    BUILTIN(FinalizationGroupCleanupSome)
    {
        HandleScope scope(isolate);
        const char* method_name = "FinalizationGroup.prototype.cleanupSome";

        CHECK_RECEIVER(JSFinalizationGroup, finalization_group, method_name);

        // TODO(marja, gsathya): Add missing "cleanup" callback.

        // Don't do set_scheduled_for_cleanup(false); we still have the microtask
        // scheduled and don't want to schedule another one in case the user never
        // executes microtasks.
        JSFinalizationGroup::Cleanup(finalization_group, isolate);
        return ReadOnlyRoots(isolate).undefined_value();
    }

    BUILTIN(FinalizationGroupCleanupIteratorNext)
    {
        HandleScope scope(isolate);
        CHECK_RECEIVER(JSFinalizationGroupCleanupIterator, iterator, "next");

        Handle<JSFinalizationGroup> finalization_group(iterator->finalization_group(),
            isolate);
        if (!finalization_group->NeedsCleanup()) {
            return *isolate->factory()->NewJSIteratorResult(
                handle(ReadOnlyRoots(isolate).undefined_value(), isolate), true);
        }
        Handle<Object> holdings = handle(
            JSFinalizationGroup::PopClearedCellHoldings(finalization_group, isolate),
            isolate);

        return *isolate->factory()->NewJSIteratorResult(holdings, false);
    }

    BUILTIN(WeakRefConstructor)
    {
        HandleScope scope(isolate);
        Handle<JSFunction> target = args.target();
        if (args.new_target()->IsUndefined(isolate)) { // [[Call]]
            THROW_NEW_ERROR_RETURN_FAILURE(
                isolate, NewTypeError(MessageTemplate::kConstructorNotFunction, handle(target->shared()->Name(), isolate)));
        }
        // [[Construct]]
        Handle<JSReceiver> new_target = Handle<JSReceiver>::cast(args.new_target());
        Handle<Object> target_object = args.atOrUndefined(isolate, 1);
        if (!target_object->IsJSReceiver()) {
            THROW_NEW_ERROR_RETURN_FAILURE(
                isolate,
                NewTypeError(
                    MessageTemplate::kWeakRefsWeakRefConstructorTargetMustBeObject));
        }
        Handle<JSReceiver> target_receiver = handle(JSReceiver::cast(*target_object), isolate);
        isolate->heap()->AddKeepDuringJobTarget(target_receiver);

        // TODO(marja): Realms.

        Handle<JSObject> result;
        ASSIGN_RETURN_FAILURE_ON_EXCEPTION(
            isolate, result,
            JSObject::New(target, new_target, Handle<AllocationSite>::null()));

        Handle<JSWeakRef> weak_ref = Handle<JSWeakRef>::cast(result);
        weak_ref->set_target(*target_receiver);
        return *weak_ref;
    }

    BUILTIN(WeakRefDeref)
    {
        HandleScope scope(isolate);
        CHECK_RECEIVER(JSWeakRef, weak_ref, "WeakRef.prototype.deref");
        if (weak_ref->target()->IsJSReceiver()) {
            Handle<JSReceiver> target = handle(JSReceiver::cast(weak_ref->target()), isolate);
            // AddKeepDuringJobTarget might allocate and cause a GC, but it won't clear
            // weak_ref since we hold a Handle to its target.
            isolate->heap()->AddKeepDuringJobTarget(target);
        } else {
            DCHECK(weak_ref->target()->IsUndefined(isolate));
        }
        return weak_ref->target();
    }

} // namespace internal
} // namespace v8
