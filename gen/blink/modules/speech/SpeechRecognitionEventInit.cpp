// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "SpeechRecognitionEventInit.h"

#include "modules/speech/SpeechRecognitionResultList.h"

namespace blink {

SpeechRecognitionEventInit::SpeechRecognitionEventInit() {
}

SpeechRecognitionEventInit::~SpeechRecognitionEventInit() {}

SpeechRecognitionEventInit::SpeechRecognitionEventInit(const SpeechRecognitionEventInit&) = default;

SpeechRecognitionEventInit& SpeechRecognitionEventInit::operator=(const SpeechRecognitionEventInit&) = default;

bool SpeechRecognitionEventInit::hasResultIndex() const {
  return m_hasResultIndex;
}
unsigned SpeechRecognitionEventInit::resultIndex() const {
  DCHECK(m_hasResultIndex);
  return m_resultIndex;
}
void SpeechRecognitionEventInit::setResultIndex(unsigned value) {
  m_resultIndex = value;
  m_hasResultIndex = true;
}
bool SpeechRecognitionEventInit::hasResults() const {
  return m_results;
}
SpeechRecognitionResultList* SpeechRecognitionEventInit::results() const {
  return m_results;
}
void SpeechRecognitionEventInit::setResults(SpeechRecognitionResultList* value) {
  m_results = value;
}
void SpeechRecognitionEventInit::setResultsToNull() {
  m_results = Member<SpeechRecognitionResultList>();
}

DEFINE_TRACE(SpeechRecognitionEventInit) {
  visitor->trace(m_results);
  EventInit::trace(visitor);
}

}  // namespace blink
