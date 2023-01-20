/*
 * Copyright 2014 Google Inc.
 *
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 */
#include <v8.h>

<<<<<<< HEAD
#include "DrawingMethods.h"
#include "Global.h"
=======
#include "Global.h"
#include "DrawingMethods.h"
>>>>>>> miniblink49
#include "Path2D.h"
#include "SkCanvas.h"
#include "SkPaint.h"

<<<<<<< HEAD
DrawingMethods* DrawingMethods::Unwrap(v8::Handle<v8::Object> obj)
{
=======

DrawingMethods* DrawingMethods::Unwrap(v8::Handle<v8::Object> obj) {
>>>>>>> miniblink49
    v8::Handle<v8::External> field = v8::Handle<v8::External>::Cast(obj->GetInternalField(0));
    void* ptr = field->Value();
    return static_cast<DrawingMethods*>(ptr);
}

<<<<<<< HEAD
void DrawingMethods::Save(const v8::FunctionCallbackInfo<v8::Value>& args)
{
=======

void DrawingMethods::Save(const v8::FunctionCallbackInfo<v8::Value>& args) {
>>>>>>> miniblink49
    DrawingMethods* drawingMethods = Unwrap(args.This());
    SkCanvas* canvas = drawingMethods->getCanvas();
    if (NULL == canvas) {
        return;
    }

    canvas->save();
}

<<<<<<< HEAD
void DrawingMethods::Restore(const v8::FunctionCallbackInfo<v8::Value>& args)
{
=======
void DrawingMethods::Restore(const v8::FunctionCallbackInfo<v8::Value>& args) {
>>>>>>> miniblink49
    DrawingMethods* drawingMethods = Unwrap(args.This());
    SkCanvas* canvas = drawingMethods->getCanvas();
    if (NULL == canvas) {
        return;
    }

    canvas->restore();
}

<<<<<<< HEAD
void DrawingMethods::Rotate(const v8::FunctionCallbackInfo<v8::Value>& args)
{
=======
void DrawingMethods::Rotate(const v8::FunctionCallbackInfo<v8::Value>& args) {
>>>>>>> miniblink49
    DrawingMethods* drawingMethods = Unwrap(args.This());
    SkCanvas* canvas = drawingMethods->getCanvas();
    if (NULL == canvas) {
        return;
    }

    if (args.Length() != 1) {
        args.GetIsolate()->ThrowException(
<<<<<<< HEAD
            v8::String::NewFromUtf8(
                args.GetIsolate(), "Error: 1 arguments required."));
=======
                v8::String::NewFromUtf8(
                        args.GetIsolate(), "Error: 1 arguments required."));
>>>>>>> miniblink49
        return;
    }
    double angle = args[0]->NumberValue();
    canvas->rotate(SkRadiansToDegrees(angle));
}

<<<<<<< HEAD
void DrawingMethods::Translate(const v8::FunctionCallbackInfo<v8::Value>& args)
{
=======
void DrawingMethods::Translate(const v8::FunctionCallbackInfo<v8::Value>& args) {
>>>>>>> miniblink49
    DrawingMethods* drawingMethods = Unwrap(args.This());
    SkCanvas* canvas = drawingMethods->getCanvas();
    if (NULL == canvas) {
        return;
    }

    if (args.Length() != 2) {
        args.GetIsolate()->ThrowException(
<<<<<<< HEAD
            v8::String::NewFromUtf8(
                args.GetIsolate(), "Error: 2 arguments required."));
=======
                v8::String::NewFromUtf8(
                        args.GetIsolate(), "Error: 2 arguments required."));
>>>>>>> miniblink49
        return;
    }
    double dx = args[0]->NumberValue();
    double dy = args[1]->NumberValue();
    canvas->translate(SkDoubleToScalar(dx), SkDoubleToScalar(dy));
}

<<<<<<< HEAD
void DrawingMethods::ResetTransform(const v8::FunctionCallbackInfo<v8::Value>& args)
{
=======
void DrawingMethods::ResetTransform(const v8::FunctionCallbackInfo<v8::Value>& args) {
>>>>>>> miniblink49
    DrawingMethods* drawingMethods = Unwrap(args.This());
    SkCanvas* canvas = drawingMethods->getCanvas();
    if (NULL == canvas) {
        return;
    }

    canvas->resetMatrix();
}

<<<<<<< HEAD
void DrawingMethods::DrawPath(const v8::FunctionCallbackInfo<v8::Value>& args)
{
=======
void DrawingMethods::DrawPath(const v8::FunctionCallbackInfo<v8::Value>& args) {
>>>>>>> miniblink49
    DrawingMethods* drawingMethods = Unwrap(args.This());
    SkCanvas* canvas = drawingMethods->getCanvas();
    if (NULL == canvas) {
        return;
    }

    if (args.Length() != 1) {
        args.GetIsolate()->ThrowException(
<<<<<<< HEAD
            v8::String::NewFromUtf8(
                args.GetIsolate(), "Error: 1 argument required."));
=======
                v8::String::NewFromUtf8(
                        args.GetIsolate(), "Error: 1 argument required."));
>>>>>>> miniblink49
        return;
    }

    v8::Handle<v8::External> field = v8::Handle<v8::External>::Cast(
<<<<<<< HEAD
        args[0]->ToObject()->GetInternalField(0));
=======
            args[0]->ToObject()->GetInternalField(0));
>>>>>>> miniblink49
    void* ptr = field->Value();
    Path2D* path = static_cast<Path2D*>(ptr);
    if (NULL == path) {
        return;
    }
    // TODO(jcgregorio) Add support for Paint2D parameter after Paint2D is
    // implemented.
    SkPaint fillStyle;
    fillStyle.setColor(SK_ColorBLACK);
    fillStyle.setAntiAlias(true);
    fillStyle.setStyle(SkPaint::kFill_Style);
    canvas->drawPath(*(path->path()), fillStyle);
}

<<<<<<< HEAD
void DrawingMethods::GetWidth(v8::Local<v8::String> name,
    const v8::PropertyCallbackInfo<v8::Value>& info)
{
=======

void DrawingMethods::GetWidth(v8::Local<v8::String> name,
        const v8::PropertyCallbackInfo<v8::Value>& info) {
>>>>>>> miniblink49
    DrawingMethods* drawingMethods = Unwrap(info.This());
    SkCanvas* canvas = drawingMethods->getCanvas();
    if (NULL == canvas) {
        return;
    }

    info.GetReturnValue().Set(
<<<<<<< HEAD
        v8::Int32::New(
            drawingMethods->fGlobal->getIsolate(), canvas->imageInfo().width()));
}

void DrawingMethods::GetHeight(v8::Local<v8::String> name,
    const v8::PropertyCallbackInfo<v8::Value>& info)
{
=======
            v8::Int32::New(
                drawingMethods->fGlobal->getIsolate(), canvas->imageInfo().width()));
}

void DrawingMethods::GetHeight(v8::Local<v8::String> name,
        const v8::PropertyCallbackInfo<v8::Value>& info) {
>>>>>>> miniblink49
    DrawingMethods* drawingMethods = Unwrap(info.This());
    SkCanvas* canvas = drawingMethods->getCanvas();
    if (NULL == canvas) {
        return;
    }

    info.GetReturnValue().Set(
<<<<<<< HEAD
        v8::Int32::New(
            drawingMethods->fGlobal->getIsolate(), canvas->imageInfo().height()));
}

#define ADD_METHOD(name, fn)                        \
    tmpl->Set(v8::String::NewFromUtf8(              \
                  fGlobal->getIsolate(), name,      \
                  v8::String::kInternalizedString), \
        v8::FunctionTemplate::New(fGlobal->getIsolate(), fn))

void DrawingMethods::addAttributesAndMethods(v8::Handle<v8::ObjectTemplate> tmpl)
{
=======
            v8::Int32::New(
                drawingMethods->fGlobal->getIsolate(), canvas->imageInfo().height()));
}

#define ADD_METHOD(name, fn) \
    tmpl->Set(v8::String::NewFromUtf8( \
         fGlobal->getIsolate(), name, \
         v8::String::kInternalizedString), \
             v8::FunctionTemplate::New(fGlobal->getIsolate(), fn))

void DrawingMethods::addAttributesAndMethods(v8::Handle<v8::ObjectTemplate> tmpl) {
>>>>>>> miniblink49
    v8::HandleScope scope(fGlobal->getIsolate());

    // Add accessors for each of the fields of the context object.
    tmpl->SetAccessor(v8::String::NewFromUtf8(
<<<<<<< HEAD
                          fGlobal->getIsolate(), "width", v8::String::kInternalizedString),
        GetWidth);
    tmpl->SetAccessor(v8::String::NewFromUtf8(
                          fGlobal->getIsolate(), "height", v8::String::kInternalizedString),
        GetHeight);
=======
        fGlobal->getIsolate(), "width", v8::String::kInternalizedString),
            GetWidth);
    tmpl->SetAccessor(v8::String::NewFromUtf8(
        fGlobal->getIsolate(), "height", v8::String::kInternalizedString),
            GetHeight);
>>>>>>> miniblink49

    // Add methods.
    ADD_METHOD("save", Save);
    ADD_METHOD("restore", Restore);
    ADD_METHOD("rotate", Rotate);
    ADD_METHOD("translate", Translate);
    ADD_METHOD("resetTransform", ResetTransform);

    ADD_METHOD("drawPath", DrawPath);
}
