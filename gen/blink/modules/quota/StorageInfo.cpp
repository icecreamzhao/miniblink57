// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "StorageInfo.h"

namespace blink {

StorageInfo::StorageInfo()
{
}

StorageInfo::~StorageInfo() { }

StorageInfo::StorageInfo(const StorageInfo&) = default;

StorageInfo& StorageInfo::operator=(const StorageInfo&) = default;

bool StorageInfo::hasQuota() const
{
    return m_hasQuota;
}
unsigned long long StorageInfo::quota() const
{
    DCHECK(m_hasQuota);
    return m_quota;
}
void StorageInfo::setQuota(unsigned long long value)
{
    m_quota = value;
    m_hasQuota = true;
}
bool StorageInfo::hasUsage() const
{
    return m_hasUsage;
}
unsigned long long StorageInfo::usage() const
{
    DCHECK(m_hasUsage);
    return m_usage;
}
void StorageInfo::setUsage(unsigned long long value)
{
    m_usage = value;
    m_hasUsage = true;
}

DEFINE_TRACE(StorageInfo)
{
    IDLDictionaryBase::trace(visitor);
}

} // namespace blink
