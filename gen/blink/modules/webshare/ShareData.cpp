// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "ShareData.h"

namespace blink {

ShareData::ShareData()
{
}

ShareData::~ShareData() { }

ShareData::ShareData(const ShareData&) = default;

ShareData& ShareData::operator=(const ShareData&) = default;

bool ShareData::hasText() const
{
    return !m_text.isNull();
}
String ShareData::text() const
{
    return m_text;
}
void ShareData::setText(String value)
{
    m_text = value;
}
void ShareData::setTextToNull()
{
    m_text = String();
}
bool ShareData::hasTitle() const
{
    return !m_title.isNull();
}
String ShareData::title() const
{
    return m_title;
}
void ShareData::setTitle(String value)
{
    m_title = value;
}
void ShareData::setTitleToNull()
{
    m_title = String();
}
bool ShareData::hasURL() const
{
    return !m_url.isNull();
}
String ShareData::url() const
{
    return m_url;
}
void ShareData::setURL(String value)
{
    m_url = value;
}
void ShareData::setURLToNull()
{
    m_url = String();
}

DEFINE_TRACE(ShareData)
{
    IDLDictionaryBase::trace(visitor);
}

} // namespace blink
