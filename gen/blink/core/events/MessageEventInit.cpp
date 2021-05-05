// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "MessageEventInit.h"

#include "core/dom/MessagePort.h"
#include "core/events/EventTarget.h"
#include "wtf/Vector.h"

namespace blink {

MessageEventInit::MessageEventInit() {
}

MessageEventInit::~MessageEventInit() {}

MessageEventInit::MessageEventInit(const MessageEventInit&) = default;

MessageEventInit& MessageEventInit::operator=(const MessageEventInit&) = default;

bool MessageEventInit::hasData() const {
  return !(m_data.isEmpty() || m_data.isNull() || m_data.isUndefined());
}
ScriptValue MessageEventInit::data() const {
  return m_data;
}
void MessageEventInit::setData(ScriptValue value) {
  m_data = value;
}
bool MessageEventInit::hasLastEventId() const {
  return !m_lastEventId.isNull();
}
String MessageEventInit::lastEventId() const {
  return m_lastEventId;
}
void MessageEventInit::setLastEventId(String value) {
  m_lastEventId = value;
}
bool MessageEventInit::hasOrigin() const {
  return !m_origin.isNull();
}
String MessageEventInit::origin() const {
  return m_origin;
}
void MessageEventInit::setOrigin(String value) {
  m_origin = value;
}
bool MessageEventInit::hasPorts() const {
  return m_hasPorts;
}
const HeapVector<Member<MessagePort>>& MessageEventInit::ports() const {
  DCHECK(m_hasPorts);
  return m_ports;
}
void MessageEventInit::setPorts(const HeapVector<Member<MessagePort>>& value) {
  m_ports = value;
  m_hasPorts = true;
}
void MessageEventInit::setPortsToNull() {
  m_hasPorts = false;
}
bool MessageEventInit::hasSource() const {
  return m_source;
}
EventTarget* MessageEventInit::source() const {
  return m_source;
}
void MessageEventInit::setSource(EventTarget* value) {
  m_source = value;
}
void MessageEventInit::setSourceToNull() {
  m_source = Member<EventTarget>();
}

DEFINE_TRACE(MessageEventInit) {
  visitor->trace(m_ports);
  visitor->trace(m_source);
  EventInit::trace(visitor);
}

}  // namespace blink
