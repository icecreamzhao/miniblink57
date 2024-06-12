// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "ForeignFetchEventInit.h"

#include "modules/fetch/Request.h"

namespace blink {

ForeignFetchEventInit::ForeignFetchEventInit()
{
    setOrigin(String("null"));
}

ForeignFetchEventInit::~ForeignFetchEventInit() { }

ForeignFetchEventInit::ForeignFetchEventInit(const ForeignFetchEventInit&) = default;

ForeignFetchEventInit& ForeignFetchEventInit::operator=(const ForeignFetchEventInit&) = default;

bool ForeignFetchEventInit::hasOrigin() const
{
    return !m_origin.isNull();
}
String ForeignFetchEventInit::origin() const
{
    return m_origin;
}
void ForeignFetchEventInit::setOrigin(String value)
{
    m_origin = value;
}
bool ForeignFetchEventInit::hasRequest() const
{
    return m_request;
}
Request* ForeignFetchEventInit::request() const
{
    return m_request;
}
void ForeignFetchEventInit::setRequest(Request* value)
{
    m_request = value;
}

DEFINE_TRACE(ForeignFetchEventInit)
{
    visitor->trace(m_request);
    ExtendableEventInit::trace(visitor);
}

} // namespace blink
