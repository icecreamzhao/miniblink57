// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format off
#ifndef InputEventInit_h
#define InputEventInit_h

#include "core/CoreExport.h"
#include "core/events/UIEventInit.h"
#include "platform/heap/Handle.h"
#include "wtf/text/WTFString.h"

namespace blink {

class Range;
class DataTransfer;

class CORE_EXPORT InputEventInit : public UIEventInit {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  InputEventInit();
  virtual ~InputEventInit();
  InputEventInit(const InputEventInit&);
  InputEventInit& operator=(const InputEventInit&);

  bool hasData() const;
  String data() const;
  void setData(String);
  void setDataToNull();

  bool hasDataTransfer() const;
  DataTransfer* dataTransfer() const;
  void setDataTransfer(DataTransfer*);
  void setDataTransferToNull();

  bool hasInputType() const;
  String inputType() const;
  void setInputType(String);

  bool hasIsComposing() const;
  bool isComposing() const;
  void setIsComposing(bool);

  bool hasRanges() const;
  const HeapVector<Member<Range>>& ranges() const;
  void setRanges(const HeapVector<Member<Range>>&);

  v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  DECLARE_VIRTUAL_TRACE();

 private:
  String m_data;
  Member<DataTransfer> m_dataTransfer;
  String m_inputType;
  bool m_hasIsComposing = false;
  bool m_isComposing;
  bool m_hasRanges = false;
  HeapVector<Member<Range>> m_ranges;

  friend class V8InputEventInit;
};

}  // namespace blink

#endif  // InputEventInit_h
