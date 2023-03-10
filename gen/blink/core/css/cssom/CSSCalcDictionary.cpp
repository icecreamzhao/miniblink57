// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "CSSCalcDictionary.h"

namespace blink {

CSSCalcDictionary::CSSCalcDictionary()
{
}

CSSCalcDictionary::~CSSCalcDictionary() { }

CSSCalcDictionary::CSSCalcDictionary(const CSSCalcDictionary&) = default;

CSSCalcDictionary& CSSCalcDictionary::operator=(const CSSCalcDictionary&) = default;

bool CSSCalcDictionary::hasCh() const
{
    return m_hasCh;
}
double CSSCalcDictionary::ch() const
{
    DCHECK(m_hasCh);
    return m_ch;
}
void CSSCalcDictionary::setCh(double value)
{
    m_ch = value;
    m_hasCh = true;
}
void CSSCalcDictionary::setChToNull()
{
    m_hasCh = false;
}
bool CSSCalcDictionary::hasCm() const
{
    return m_hasCm;
}
double CSSCalcDictionary::cm() const
{
    DCHECK(m_hasCm);
    return m_cm;
}
void CSSCalcDictionary::setCm(double value)
{
    m_cm = value;
    m_hasCm = true;
}
void CSSCalcDictionary::setCmToNull()
{
    m_hasCm = false;
}
bool CSSCalcDictionary::hasEm() const
{
    return m_hasEm;
}
double CSSCalcDictionary::em() const
{
    DCHECK(m_hasEm);
    return m_em;
}
void CSSCalcDictionary::setEm(double value)
{
    m_em = value;
    m_hasEm = true;
}
void CSSCalcDictionary::setEmToNull()
{
    m_hasEm = false;
}
bool CSSCalcDictionary::hasEx() const
{
    return m_hasEx;
}
double CSSCalcDictionary::ex() const
{
    DCHECK(m_hasEx);
    return m_ex;
}
void CSSCalcDictionary::setEx(double value)
{
    m_ex = value;
    m_hasEx = true;
}
void CSSCalcDictionary::setExToNull()
{
    m_hasEx = false;
}
bool CSSCalcDictionary::hasIn() const
{
    return m_hasIn;
}
double CSSCalcDictionary::in() const
{
    DCHECK(m_hasIn);
    return m_in;
}
void CSSCalcDictionary::setIn(double value)
{
    m_in = value;
    m_hasIn = true;
}
void CSSCalcDictionary::setInToNull()
{
    m_hasIn = false;
}
bool CSSCalcDictionary::hasMm() const
{
    return m_hasMm;
}
double CSSCalcDictionary::mm() const
{
    DCHECK(m_hasMm);
    return m_mm;
}
void CSSCalcDictionary::setMm(double value)
{
    m_mm = value;
    m_hasMm = true;
}
void CSSCalcDictionary::setMmToNull()
{
    m_hasMm = false;
}
bool CSSCalcDictionary::hasPc() const
{
    return m_hasPc;
}
double CSSCalcDictionary::pc() const
{
    DCHECK(m_hasPc);
    return m_pc;
}
void CSSCalcDictionary::setPc(double value)
{
    m_pc = value;
    m_hasPc = true;
}
void CSSCalcDictionary::setPcToNull()
{
    m_hasPc = false;
}
bool CSSCalcDictionary::hasPercent() const
{
    return m_hasPercent;
}
double CSSCalcDictionary::percent() const
{
    DCHECK(m_hasPercent);
    return m_percent;
}
void CSSCalcDictionary::setPercent(double value)
{
    m_percent = value;
    m_hasPercent = true;
}
void CSSCalcDictionary::setPercentToNull()
{
    m_hasPercent = false;
}
bool CSSCalcDictionary::hasPt() const
{
    return m_hasPt;
}
double CSSCalcDictionary::pt() const
{
    DCHECK(m_hasPt);
    return m_pt;
}
void CSSCalcDictionary::setPt(double value)
{
    m_pt = value;
    m_hasPt = true;
}
void CSSCalcDictionary::setPtToNull()
{
    m_hasPt = false;
}
bool CSSCalcDictionary::hasPx() const
{
    return m_hasPx;
}
double CSSCalcDictionary::px() const
{
    DCHECK(m_hasPx);
    return m_px;
}
void CSSCalcDictionary::setPx(double value)
{
    m_px = value;
    m_hasPx = true;
}
void CSSCalcDictionary::setPxToNull()
{
    m_hasPx = false;
}
bool CSSCalcDictionary::hasRem() const
{
    return m_hasRem;
}
double CSSCalcDictionary::rem() const
{
    DCHECK(m_hasRem);
    return m_rem;
}
void CSSCalcDictionary::setRem(double value)
{
    m_rem = value;
    m_hasRem = true;
}
void CSSCalcDictionary::setRemToNull()
{
    m_hasRem = false;
}
bool CSSCalcDictionary::hasVh() const
{
    return m_hasVh;
}
double CSSCalcDictionary::vh() const
{
    DCHECK(m_hasVh);
    return m_vh;
}
void CSSCalcDictionary::setVh(double value)
{
    m_vh = value;
    m_hasVh = true;
}
void CSSCalcDictionary::setVhToNull()
{
    m_hasVh = false;
}
bool CSSCalcDictionary::hasVmax() const
{
    return m_hasVmax;
}
double CSSCalcDictionary::vmax() const
{
    DCHECK(m_hasVmax);
    return m_vmax;
}
void CSSCalcDictionary::setVmax(double value)
{
    m_vmax = value;
    m_hasVmax = true;
}
void CSSCalcDictionary::setVmaxToNull()
{
    m_hasVmax = false;
}
bool CSSCalcDictionary::hasVmin() const
{
    return m_hasVmin;
}
double CSSCalcDictionary::vmin() const
{
    DCHECK(m_hasVmin);
    return m_vmin;
}
void CSSCalcDictionary::setVmin(double value)
{
    m_vmin = value;
    m_hasVmin = true;
}
void CSSCalcDictionary::setVminToNull()
{
    m_hasVmin = false;
}
bool CSSCalcDictionary::hasVw() const
{
    return m_hasVw;
}
double CSSCalcDictionary::vw() const
{
    DCHECK(m_hasVw);
    return m_vw;
}
void CSSCalcDictionary::setVw(double value)
{
    m_vw = value;
    m_hasVw = true;
}
void CSSCalcDictionary::setVwToNull()
{
    m_hasVw = false;
}

DEFINE_TRACE(CSSCalcDictionary)
{
    IDLDictionaryBase::trace(visitor);
}

} // namespace blink
