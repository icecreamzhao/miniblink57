// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8Range.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8ClientRect.h"
#include "bindings/core/v8/V8ClientRectList.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8DocumentFragment.h"
#include "bindings/core/v8/V8Node.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8Range.h"
#include "core/dom/Document.h"
#include "core/dom/custom/CEReactionsScope.h"
#include "core/dom/custom/V0CustomElementProcessingStack.h"
#include "core/frame/Deprecation.h"
#include "core/frame/LocalDOMWindow.h"
#include "core/frame/UseCounter.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8Range::wrapperTypeInfo = { gin::kEmbedderBlink, V8Range::domTemplate, V8Range::trace, V8Range::traceWrappers, 0, nullptr, "Range", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in Range.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& Range::s_wrapperTypeInfo = V8Range::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, Range>::value,
    "Range inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&Range::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "Range is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace RangeV8Internal {

static void startContainerAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Range* impl = V8Range::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->startContainer()), impl);
}

CORE_EXPORT void startContainerAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::startContainerAttributeGetter(info);
}

static void startOffsetAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Range* impl = V8Range::toImpl(holder);

  v8SetReturnValueInt(info, impl->startOffset());
}

CORE_EXPORT void startOffsetAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::startOffsetAttributeGetter(info);
}

static void endContainerAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Range* impl = V8Range::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->endContainer()), impl);
}

CORE_EXPORT void endContainerAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::endContainerAttributeGetter(info);
}

static void endOffsetAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Range* impl = V8Range::toImpl(holder);

  v8SetReturnValueInt(info, impl->endOffset());
}

CORE_EXPORT void endOffsetAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::endOffsetAttributeGetter(info);
}

static void collapsedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Range* impl = V8Range::toImpl(holder);

  v8SetReturnValueBool(info, impl->collapsed());
}

CORE_EXPORT void collapsedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::collapsedAttributeGetter(info);
}

static void commonAncestorContainerAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Range* impl = V8Range::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->commonAncestorContainer()), impl);
}

CORE_EXPORT void commonAncestorContainerAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::commonAncestorContainerAttributeGetter(info);
}

static void setStartMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "setStart");

  Range* impl = V8Range::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
    return;
  }

  Node* node;
  int offset;
  node = V8Node::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!node) {
    exceptionState.throwTypeError("parameter 1 is not of type 'Node'.");

    return;
  }

  offset = toInt32(info.GetIsolate(), info[1], NormalConversion, exceptionState);
  if (exceptionState.hadException())
    return;

  impl->setStart(node, offset, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

CORE_EXPORT  void setStartMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::setStartMethod(info);
}

static void setEndMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "setEnd");

  Range* impl = V8Range::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
    return;
  }

  Node* node;
  int offset;
  node = V8Node::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!node) {
    exceptionState.throwTypeError("parameter 1 is not of type 'Node'.");

    return;
  }

  offset = toInt32(info.GetIsolate(), info[1], NormalConversion, exceptionState);
  if (exceptionState.hadException())
    return;

  impl->setEnd(node, offset, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

CORE_EXPORT  void setEndMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::setEndMethod(info);
}

static void setStartBeforeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "setStartBefore");

  Range* impl = V8Range::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  Node* node;
  node = V8Node::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!node) {
    exceptionState.throwTypeError("parameter 1 is not of type 'Node'.");

    return;
  }

  impl->setStartBefore(node, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

CORE_EXPORT  void setStartBeforeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::setStartBeforeMethod(info);
}

static void setStartAfterMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "setStartAfter");

  Range* impl = V8Range::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  Node* node;
  node = V8Node::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!node) {
    exceptionState.throwTypeError("parameter 1 is not of type 'Node'.");

    return;
  }

  impl->setStartAfter(node, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

CORE_EXPORT  void setStartAfterMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::setStartAfterMethod(info);
}

static void setEndBeforeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "setEndBefore");

  Range* impl = V8Range::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  Node* node;
  node = V8Node::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!node) {
    exceptionState.throwTypeError("parameter 1 is not of type 'Node'.");

    return;
  }

  impl->setEndBefore(node, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

CORE_EXPORT  void setEndBeforeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::setEndBeforeMethod(info);
}

static void setEndAfterMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "setEndAfter");

  Range* impl = V8Range::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  Node* node;
  node = V8Node::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!node) {
    exceptionState.throwTypeError("parameter 1 is not of type 'Node'.");

    return;
  }

  impl->setEndAfter(node, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

CORE_EXPORT  void setEndAfterMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::setEndAfterMethod(info);
}

static void collapseMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "collapse");

  Range* impl = V8Range::toImpl(info.Holder());

  bool toStart;
  if (!info[0]->IsUndefined()) {
    toStart = toBoolean(info.GetIsolate(), info[0], exceptionState);
    if (exceptionState.hadException())
      return;
  } else {
    toStart = false;
  }

  impl->collapse(toStart);
}

CORE_EXPORT  void collapseMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::collapseMethod(info);
}

static void selectNodeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "selectNode");

  Range* impl = V8Range::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  Node* node;
  node = V8Node::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!node) {
    exceptionState.throwTypeError("parameter 1 is not of type 'Node'.");

    return;
  }

  impl->selectNode(node, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

CORE_EXPORT  void selectNodeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::selectNodeMethod(info);
}

static void selectNodeContentsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "selectNodeContents");

  Range* impl = V8Range::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  Node* node;
  node = V8Node::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!node) {
    exceptionState.throwTypeError("parameter 1 is not of type 'Node'.");

    return;
  }

  impl->selectNodeContents(node, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

CORE_EXPORT  void selectNodeContentsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::selectNodeContentsMethod(info);
}

static void compareBoundaryPointsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "compareBoundaryPoints");

  Range* impl = V8Range::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
    return;
  }

  unsigned how;
  Range* sourceRange;
  how = toUInt16(info.GetIsolate(), info[0], NormalConversion, exceptionState);
  if (exceptionState.hadException())
    return;

  sourceRange = V8Range::toImplWithTypeCheck(info.GetIsolate(), info[1]);
  if (!sourceRange) {
    exceptionState.throwTypeError("parameter 2 is not of type 'Range'.");

    return;
  }

  int result = impl->compareBoundaryPoints(how, sourceRange, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValueInt(info, result);
}

CORE_EXPORT  void compareBoundaryPointsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::compareBoundaryPointsMethod(info);
}

static void deleteContentsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "deleteContents");

  Range* impl = V8Range::toImpl(info.Holder());

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  impl->deleteContents(exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

CORE_EXPORT  void deleteContentsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  CEReactionsScope ceReactionsScope;
  RangeV8Internal::deleteContentsMethod(info);
}

static void extractContentsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "extractContents");

  Range* impl = V8Range::toImpl(info.Holder());

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  DocumentFragment* result = impl->extractContents(exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  // [NewObject] must always create a new wrapper.  Check that a wrapper
  // does not exist yet.
  DCHECK(!result || DOMDataStore::getWrapper(result, info.GetIsolate()).IsEmpty());
  v8SetReturnValue(info, result);
}

CORE_EXPORT  void extractContentsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  CEReactionsScope ceReactionsScope;
  RangeV8Internal::extractContentsMethod(info);
}

static void cloneContentsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "cloneContents");

  Range* impl = V8Range::toImpl(info.Holder());

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  DocumentFragment* result = impl->cloneContents(exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  // [NewObject] must always create a new wrapper.  Check that a wrapper
  // does not exist yet.
  DCHECK(!result || DOMDataStore::getWrapper(result, info.GetIsolate()).IsEmpty());
  v8SetReturnValue(info, result);
}

CORE_EXPORT  void cloneContentsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  CEReactionsScope ceReactionsScope;
  RangeV8Internal::cloneContentsMethod(info);
}

static void insertNodeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "insertNode");

  Range* impl = V8Range::toImpl(info.Holder());

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  Node* node;
  node = V8Node::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!node) {
    exceptionState.throwTypeError("parameter 1 is not of type 'Node'.");

    return;
  }

  impl->insertNode(node, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

CORE_EXPORT  void insertNodeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  CEReactionsScope ceReactionsScope;
  RangeV8Internal::insertNodeMethod(info);
}

static void surroundContentsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "surroundContents");

  Range* impl = V8Range::toImpl(info.Holder());

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  Node* newParent;
  newParent = V8Node::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!newParent) {
    exceptionState.throwTypeError("parameter 1 is not of type 'Node'.");

    return;
  }

  impl->surroundContents(newParent, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

CORE_EXPORT  void surroundContentsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  CEReactionsScope ceReactionsScope;
  RangeV8Internal::surroundContentsMethod(info);
}

static void cloneRangeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Range* impl = V8Range::toImpl(info.Holder());

  Range* result = impl->cloneRange();
  // [NewObject] must always create a new wrapper.  Check that a wrapper
  // does not exist yet.
  DCHECK(!result || DOMDataStore::getWrapper(result, info.GetIsolate()).IsEmpty());
  v8SetReturnValue(info, result);
}

CORE_EXPORT  void cloneRangeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::cloneRangeMethod(info);
}

static void detachMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Range* impl = V8Range::toImpl(info.Holder());

  impl->detach();
}

CORE_EXPORT  void detachMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::RangeDetach);
  RangeV8Internal::detachMethod(info);
}

static void isPointInRangeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "isPointInRange");

  Range* impl = V8Range::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
    return;
  }

  Node* node;
  int offset;
  node = V8Node::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!node) {
    exceptionState.throwTypeError("parameter 1 is not of type 'Node'.");

    return;
  }

  offset = toInt32(info.GetIsolate(), info[1], NormalConversion, exceptionState);
  if (exceptionState.hadException())
    return;

  bool result = impl->isPointInRange(node, offset, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValueBool(info, result);
}

CORE_EXPORT  void isPointInRangeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::isPointInRangeMethod(info);
}

static void comparePointMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "comparePoint");

  Range* impl = V8Range::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
    return;
  }

  Node* node;
  int offset;
  node = V8Node::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!node) {
    exceptionState.throwTypeError("parameter 1 is not of type 'Node'.");

    return;
  }

  offset = toInt32(info.GetIsolate(), info[1], NormalConversion, exceptionState);
  if (exceptionState.hadException())
    return;

  int result = impl->comparePoint(node, offset, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValueInt(info, result);
}

CORE_EXPORT  void comparePointMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::comparePointMethod(info);
}

static void intersectsNodeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "intersectsNode");

  Range* impl = V8Range::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  Node* node;
  node = V8Node::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!node) {
    exceptionState.throwTypeError("parameter 1 is not of type 'Node'.");

    return;
  }

  bool result = impl->intersectsNode(node, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValueBool(info, result);
}

CORE_EXPORT  void intersectsNodeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::intersectsNodeMethod(info);
}

static void getClientRectsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Range* impl = V8Range::toImpl(info.Holder());

  v8SetReturnValue(info, impl->getClientRects());
}

CORE_EXPORT  void getClientRectsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::getClientRectsMethod(info);
}

static void getBoundingClientRectMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Range* impl = V8Range::toImpl(info.Holder());

  v8SetReturnValue(info, impl->getBoundingClientRect());
}

CORE_EXPORT  void getBoundingClientRectMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::getBoundingClientRectMethod(info);
}

static void createContextualFragmentMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "createContextualFragment");

  Range* impl = V8Range::toImpl(info.Holder());

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  V8StringResource<> fragment;
  fragment = info[0];
  if (!fragment.prepare())
    return;

  DocumentFragment* result = impl->createContextualFragment(fragment, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  // [NewObject] must always create a new wrapper.  Check that a wrapper
  // does not exist yet.
  DCHECK(!result || DOMDataStore::getWrapper(result, info.GetIsolate()).IsEmpty());
  v8SetReturnValue(info, result);
}

CORE_EXPORT  void createContextualFragmentMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  CEReactionsScope ceReactionsScope;
  RangeV8Internal::createContextualFragmentMethod(info);
}

static void expandMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Range", "expand");

  Range* impl = V8Range::toImpl(info.Holder());

  V8StringResource<> unit;
  unit = info[0];
  if (!unit.prepare())
    return;

  impl->expand(unit, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

CORE_EXPORT  void expandMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Deprecation::countDeprecation(currentExecutionContext(info.GetIsolate()), UseCounter::RangeExpand);
  RangeV8Internal::expandMethod(info);
}

static void toStringMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Range* impl = V8Range::toImpl(info.Holder());

  v8SetReturnValueString(info, impl->toString(), info.GetIsolate());
}

CORE_EXPORT  void toStringMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RangeV8Internal::toStringMethod(info);
}

static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Document& document = *toDocument(currentExecutionContext(info.GetIsolate()));
  Range* impl = Range::create(document);
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8Range::wrapperTypeInfo, wrapper);
  v8SetReturnValue(info, wrapper);
}

} // namespace RangeV8Internal

const V8DOMConfiguration::AccessorConfiguration V8RangeAccessors[] = {
    {"startContainer", RangeV8Internal::startContainerAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"startOffset", RangeV8Internal::startOffsetAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"endContainer", RangeV8Internal::endContainerAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"endOffset", RangeV8Internal::endOffsetAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"collapsed", RangeV8Internal::collapsedAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"commonAncestorContainer", RangeV8Internal::commonAncestorContainerAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8RangeMethods[] = {
    {"setStart", RangeV8Internal::setStartMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"setEnd", RangeV8Internal::setEndMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"setStartBefore", RangeV8Internal::setStartBeforeMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"setStartAfter", RangeV8Internal::setStartAfterMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"setEndBefore", RangeV8Internal::setEndBeforeMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"setEndAfter", RangeV8Internal::setEndAfterMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"collapse", RangeV8Internal::collapseMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"selectNode", RangeV8Internal::selectNodeMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"selectNodeContents", RangeV8Internal::selectNodeContentsMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"compareBoundaryPoints", RangeV8Internal::compareBoundaryPointsMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"deleteContents", RangeV8Internal::deleteContentsMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"extractContents", RangeV8Internal::extractContentsMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"cloneContents", RangeV8Internal::cloneContentsMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"insertNode", RangeV8Internal::insertNodeMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"surroundContents", RangeV8Internal::surroundContentsMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"cloneRange", RangeV8Internal::cloneRangeMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"detach", RangeV8Internal::detachMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"isPointInRange", RangeV8Internal::isPointInRangeMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"comparePoint", RangeV8Internal::comparePointMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"intersectsNode", RangeV8Internal::intersectsNodeMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"getClientRects", RangeV8Internal::getClientRectsMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"getBoundingClientRect", RangeV8Internal::getBoundingClientRectMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"createContextualFragment", RangeV8Internal::createContextualFragmentMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"expand", RangeV8Internal::expandMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"toString", RangeV8Internal::toStringMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

void V8Range::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  if (!info.IsConstructCall()) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("Range"));
    return;
  }

  if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
    v8SetReturnValue(info, info.Holder());
    return;
  }

  RangeV8Internal::constructor(info);
}

static void installV8RangeTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8Range::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8Range::internalFieldCount);
  interfaceTemplate->SetCallHandler(V8Range::constructorCallback);
  interfaceTemplate->SetLength(0);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  const V8DOMConfiguration::ConstantConfiguration V8RangeConstants[] = {
      {"START_TO_START", 0, 0, V8DOMConfiguration::ConstantTypeUnsignedShort},
      {"START_TO_END", 1, 0, V8DOMConfiguration::ConstantTypeUnsignedShort},
      {"END_TO_END", 2, 0, V8DOMConfiguration::ConstantTypeUnsignedShort},
      {"END_TO_START", 3, 0, V8DOMConfiguration::ConstantTypeUnsignedShort},
  };
  V8DOMConfiguration::installConstants(isolate, interfaceTemplate, prototypeTemplate, V8RangeConstants, WTF_ARRAY_LENGTH(V8RangeConstants));
  static_assert(0 == Range::kStartToStart, "the value of Range_kStartToStart does not match with implementation");
  static_assert(1 == Range::kStartToEnd, "the value of Range_kStartToEnd does not match with implementation");
  static_assert(2 == Range::kEndToEnd, "the value of Range_kEndToEnd does not match with implementation");
  static_assert(3 == Range::kEndToStart, "the value of Range_kEndToStart does not match with implementation");
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8RangeAccessors, WTF_ARRAY_LENGTH(V8RangeAccessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8RangeMethods, WTF_ARRAY_LENGTH(V8RangeMethods));
}

v8::Local<v8::FunctionTemplate> V8Range::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8RangeTemplate);
}

bool V8Range::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8Range::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

Range* V8Range::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
