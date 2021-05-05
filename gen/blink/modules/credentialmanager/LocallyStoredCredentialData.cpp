// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "LocallyStoredCredentialData.h"

namespace blink {

LocallyStoredCredentialData::LocallyStoredCredentialData() {
}

LocallyStoredCredentialData::~LocallyStoredCredentialData() {}

LocallyStoredCredentialData::LocallyStoredCredentialData(const LocallyStoredCredentialData&) = default;

LocallyStoredCredentialData& LocallyStoredCredentialData::operator=(const LocallyStoredCredentialData&) = default;

bool LocallyStoredCredentialData::hasIconURL() const {
  return !m_iconURL.isNull();
}
String LocallyStoredCredentialData::iconURL() const {
  return m_iconURL;
}
void LocallyStoredCredentialData::setIconURL(String value) {
  m_iconURL = value;
}
bool LocallyStoredCredentialData::hasName() const {
  return !m_name.isNull();
}
String LocallyStoredCredentialData::name() const {
  return m_name;
}
void LocallyStoredCredentialData::setName(String value) {
  m_name = value;
}

DEFINE_TRACE(LocallyStoredCredentialData) {
  CredentialData::trace(visitor);
}

}  // namespace blink
