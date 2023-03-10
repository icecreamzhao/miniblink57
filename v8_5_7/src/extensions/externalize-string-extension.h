// Copyright 2010 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_EXTENSIONS_EXTERNALIZE_STRING_EXTENSION_H_
#define V8_EXTENSIONS_EXTERNALIZE_STRING_EXTENSION_H_

#include "include/v8.h"

namespace v8 {
namespace internal {

class ExternalizeStringExtension : public v8::Extension {
 public:
  ExternalizeStringExtension() : v8::Extension("v8/externalize", kSource) {}
  virtual v8::Local<v8::FunctionTemplate> GetNativeFunctionTemplate(
      v8::Isolate* isolate, v8::Local<v8::String> name);
  static void V8CALL Externalize(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void V8CALL IsOneByte(const v8::FunctionCallbackInfo<v8::Value>& args);

 private:
  static const char* const kSource;
};

}  // namespace internal
}  // namespace v8

#endif  // V8_EXTENSIONS_EXTERNALIZE_STRING_EXTENSION_H_
