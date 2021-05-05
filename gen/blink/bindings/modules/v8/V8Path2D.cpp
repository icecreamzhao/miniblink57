// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8Path2D.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8SVGMatrix.h"
#include "bindings/modules/v8/V8Path2D.h"
#include "core/dom/Document.h"
#include "core/frame/LocalDOMWindow.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8Path2D::wrapperTypeInfo = { gin::kEmbedderBlink, V8Path2D::domTemplate, V8Path2D::trace, V8Path2D::traceWrappers, 0, nullptr, "Path2D", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in Path2D.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& Path2D::s_wrapperTypeInfo = V8Path2D::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, Path2D>::value,
    "Path2D inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&Path2D::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "Path2D is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace Path2DV8Internal {

static void addPathMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Path2D* impl = V8Path2D::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("addPath", "Path2D", ExceptionMessages::notEnoughArguments(1, info.Length())));
    return;
  }

  Path2D* path;
  SVGMatrixTearOff* transform;
  int numArgsPassed = info.Length();
  while (numArgsPassed > 0) {
    if (!info[numArgsPassed - 1]->IsUndefined())
      break;
    --numArgsPassed;
  }
  path = V8Path2D::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!path) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("addPath", "Path2D", "parameter 1 is not of type 'Path2D'."));

    return;
  }

  if (UNLIKELY(numArgsPassed <= 1)) {
    impl->addPath(path);
    return;
  }
  transform = V8SVGMatrix::toImplWithTypeCheck(info.GetIsolate(), info[1]);
  if (!transform && !isUndefinedOrNull(info[1])) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("addPath", "Path2D", "parameter 2 is not of type 'SVGMatrix'."));

    return;
  }

  impl->addPath(path, transform);
}

MODULES_EXPORT  void addPathMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Path2DV8Internal::addPathMethod(info);
}

static void closePathMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Path2D* impl = V8Path2D::toImpl(info.Holder());

  impl->closePath();
}

MODULES_EXPORT  void closePathMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Path2DV8Internal::closePathMethod(info);
}

static void moveToMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Path2D", "moveTo");

  Path2D* impl = V8Path2D::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
    return;
  }

  float x;
  float y;
  x = toFloat(info.GetIsolate(), info[0], exceptionState);
  if (exceptionState.hadException())
    return;

  y = toFloat(info.GetIsolate(), info[1], exceptionState);
  if (exceptionState.hadException())
    return;

  impl->moveTo(x, y);
}

MODULES_EXPORT  void moveToMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Path2DV8Internal::moveToMethod(info);
}

static void lineToMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Path2D", "lineTo");

  Path2D* impl = V8Path2D::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
    return;
  }

  float x;
  float y;
  x = toFloat(info.GetIsolate(), info[0], exceptionState);
  if (exceptionState.hadException())
    return;

  y = toFloat(info.GetIsolate(), info[1], exceptionState);
  if (exceptionState.hadException())
    return;

  impl->lineTo(x, y);
}

MODULES_EXPORT  void lineToMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Path2DV8Internal::lineToMethod(info);
}

static void quadraticCurveToMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Path2D", "quadraticCurveTo");

  Path2D* impl = V8Path2D::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 4)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(4, info.Length()));
    return;
  }

  float cpx;
  float cpy;
  float x;
  float y;
  cpx = toFloat(info.GetIsolate(), info[0], exceptionState);
  if (exceptionState.hadException())
    return;

  cpy = toFloat(info.GetIsolate(), info[1], exceptionState);
  if (exceptionState.hadException())
    return;

  x = toFloat(info.GetIsolate(), info[2], exceptionState);
  if (exceptionState.hadException())
    return;

  y = toFloat(info.GetIsolate(), info[3], exceptionState);
  if (exceptionState.hadException())
    return;

  impl->quadraticCurveTo(cpx, cpy, x, y);
}

MODULES_EXPORT  void quadraticCurveToMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Path2DV8Internal::quadraticCurveToMethod(info);
}

static void bezierCurveToMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Path2D", "bezierCurveTo");

  Path2D* impl = V8Path2D::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 6)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(6, info.Length()));
    return;
  }

  float cp1x;
  float cp1y;
  float cp2x;
  float cp2y;
  float x;
  float y;
  cp1x = toFloat(info.GetIsolate(), info[0], exceptionState);
  if (exceptionState.hadException())
    return;

  cp1y = toFloat(info.GetIsolate(), info[1], exceptionState);
  if (exceptionState.hadException())
    return;

  cp2x = toFloat(info.GetIsolate(), info[2], exceptionState);
  if (exceptionState.hadException())
    return;

  cp2y = toFloat(info.GetIsolate(), info[3], exceptionState);
  if (exceptionState.hadException())
    return;

  x = toFloat(info.GetIsolate(), info[4], exceptionState);
  if (exceptionState.hadException())
    return;

  y = toFloat(info.GetIsolate(), info[5], exceptionState);
  if (exceptionState.hadException())
    return;

  impl->bezierCurveTo(cp1x, cp1y, cp2x, cp2y, x, y);
}

MODULES_EXPORT  void bezierCurveToMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Path2DV8Internal::bezierCurveToMethod(info);
}

static void arcToMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Path2D", "arcTo");

  Path2D* impl = V8Path2D::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 5)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(5, info.Length()));
    return;
  }

  float x1;
  float y1;
  float x2;
  float y2;
  float radius;
  x1 = toFloat(info.GetIsolate(), info[0], exceptionState);
  if (exceptionState.hadException())
    return;

  y1 = toFloat(info.GetIsolate(), info[1], exceptionState);
  if (exceptionState.hadException())
    return;

  x2 = toFloat(info.GetIsolate(), info[2], exceptionState);
  if (exceptionState.hadException())
    return;

  y2 = toFloat(info.GetIsolate(), info[3], exceptionState);
  if (exceptionState.hadException())
    return;

  radius = toFloat(info.GetIsolate(), info[4], exceptionState);
  if (exceptionState.hadException())
    return;

  impl->arcTo(x1, y1, x2, y2, radius, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

MODULES_EXPORT  void arcToMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Path2DV8Internal::arcToMethod(info);
}

static void rectMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Path2D", "rect");

  Path2D* impl = V8Path2D::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 4)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(4, info.Length()));
    return;
  }

  float x;
  float y;
  float width;
  float height;
  x = toFloat(info.GetIsolate(), info[0], exceptionState);
  if (exceptionState.hadException())
    return;

  y = toFloat(info.GetIsolate(), info[1], exceptionState);
  if (exceptionState.hadException())
    return;

  width = toFloat(info.GetIsolate(), info[2], exceptionState);
  if (exceptionState.hadException())
    return;

  height = toFloat(info.GetIsolate(), info[3], exceptionState);
  if (exceptionState.hadException())
    return;

  impl->rect(x, y, width, height);
}

MODULES_EXPORT  void rectMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Path2DV8Internal::rectMethod(info);
}

static void arcMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Path2D", "arc");

  Path2D* impl = V8Path2D::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 5)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(5, info.Length()));
    return;
  }

  float x;
  float y;
  float radius;
  float startAngle;
  float endAngle;
  bool anticlockwise;
  x = toFloat(info.GetIsolate(), info[0], exceptionState);
  if (exceptionState.hadException())
    return;

  y = toFloat(info.GetIsolate(), info[1], exceptionState);
  if (exceptionState.hadException())
    return;

  radius = toFloat(info.GetIsolate(), info[2], exceptionState);
  if (exceptionState.hadException())
    return;

  startAngle = toFloat(info.GetIsolate(), info[3], exceptionState);
  if (exceptionState.hadException())
    return;

  endAngle = toFloat(info.GetIsolate(), info[4], exceptionState);
  if (exceptionState.hadException())
    return;

  anticlockwise = toBoolean(info.GetIsolate(), info[5], exceptionState);
  if (exceptionState.hadException())
    return;

  impl->arc(x, y, radius, startAngle, endAngle, anticlockwise, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

MODULES_EXPORT  void arcMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Path2DV8Internal::arcMethod(info);
}

static void ellipseMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Path2D", "ellipse");

  Path2D* impl = V8Path2D::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 7)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(7, info.Length()));
    return;
  }

  float x;
  float y;
  float radiusX;
  float radiusY;
  float rotation;
  float startAngle;
  float endAngle;
  bool anticlockwise;
  x = toFloat(info.GetIsolate(), info[0], exceptionState);
  if (exceptionState.hadException())
    return;

  y = toFloat(info.GetIsolate(), info[1], exceptionState);
  if (exceptionState.hadException())
    return;

  radiusX = toFloat(info.GetIsolate(), info[2], exceptionState);
  if (exceptionState.hadException())
    return;

  radiusY = toFloat(info.GetIsolate(), info[3], exceptionState);
  if (exceptionState.hadException())
    return;

  rotation = toFloat(info.GetIsolate(), info[4], exceptionState);
  if (exceptionState.hadException())
    return;

  startAngle = toFloat(info.GetIsolate(), info[5], exceptionState);
  if (exceptionState.hadException())
    return;

  endAngle = toFloat(info.GetIsolate(), info[6], exceptionState);
  if (exceptionState.hadException())
    return;

  anticlockwise = toBoolean(info.GetIsolate(), info[7], exceptionState);
  if (exceptionState.hadException())
    return;

  impl->ellipse(x, y, radiusX, radiusY, rotation, startAngle, endAngle, anticlockwise, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

MODULES_EXPORT  void ellipseMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Path2DV8Internal::ellipseMethod(info);
}

static void constructor1(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Path2D* impl = Path2D::create();
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8Path2D::wrapperTypeInfo, wrapper);
  v8SetReturnValue(info, wrapper);
}

static void constructor2(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Path2D* path;
  path = V8Path2D::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!path) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToConstruct("Path2D", "parameter 1 is not of type 'Path2D'."));

    return;
  }

  Path2D* impl = Path2D::create(path);
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8Path2D::wrapperTypeInfo, wrapper);
  v8SetReturnValue(info, wrapper);
}

static void constructor3(const v8::FunctionCallbackInfo<v8::Value>& info) {
  V8StringResource<> text;
  text = info[0];
  if (!text.prepare())
    return;

  Path2D* impl = Path2D::create(text);
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8Path2D::wrapperTypeInfo, wrapper);
  v8SetReturnValue(info, wrapper);
}

static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "Path2D");
  switch (std::min(1, info.Length())) {
    case 0:
      if (true) {
        Path2DV8Internal::constructor1(info);
        return;
      }
      break;
    case 1:
      if (V8Path2D::hasInstance(info[0], info.GetIsolate())) {
        Path2DV8Internal::constructor2(info);
        return;
      }
      if (true) {
        Path2DV8Internal::constructor3(info);
        return;
      }
      break;
    default:
      exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(0, info.Length()));
      return;
  }
  exceptionState.throwTypeError("No matching constructor signature.");
}

} // namespace Path2DV8Internal

const V8DOMConfiguration::MethodConfiguration V8Path2DMethods[] = {
    {"closePath", Path2DV8Internal::closePathMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"moveTo", Path2DV8Internal::moveToMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"lineTo", Path2DV8Internal::lineToMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"quadraticCurveTo", Path2DV8Internal::quadraticCurveToMethodCallback, 0, 4, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"bezierCurveTo", Path2DV8Internal::bezierCurveToMethodCallback, 0, 6, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"arcTo", Path2DV8Internal::arcToMethodCallback, 0, 5, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"rect", Path2DV8Internal::rectMethodCallback, 0, 4, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"arc", Path2DV8Internal::arcMethodCallback, 0, 5, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"ellipse", Path2DV8Internal::ellipseMethodCallback, 0, 7, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

void V8Path2D::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  if (!info.IsConstructCall()) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("Path2D"));
    return;
  }

  if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
    v8SetReturnValue(info, info.Holder());
    return;
  }

  Path2DV8Internal::constructor(info);
}

static void installV8Path2DTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8Path2D::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8Path2D::internalFieldCount);
  interfaceTemplate->SetCallHandler(V8Path2D::constructorCallback);
  interfaceTemplate->SetLength(0);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8Path2DMethods, WTF_ARRAY_LENGTH(V8Path2DMethods));

  if (RuntimeEnabledFeatures::experimentalCanvasFeaturesEnabled()) {
    const V8DOMConfiguration::MethodConfiguration addPathMethodConfiguration = {"addPath", Path2DV8Internal::addPathMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder};
    V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, addPathMethodConfiguration);
  }
}

v8::Local<v8::FunctionTemplate> V8Path2D::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8Path2DTemplate);
}

bool V8Path2D::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8Path2D::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

Path2D* V8Path2D::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
