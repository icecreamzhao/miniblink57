/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkPDFCanon.h"
#include "SkImage.h"
#include "SkPDFBitmap.h"
#include "SkPDFFont.h"

////////////////////////////////////////////////////////////////////////////////

void SkPDFCanon::reset()
{
=======
#include "SkPDFBitmap.h"
#include "SkPDFCanon.h"
#include "SkPDFFont.h"
#include "SkPDFShader.h"

////////////////////////////////////////////////////////////////////////////////

void SkPDFCanon::reset() {
>>>>>>> miniblink49
    for (int i = 0; i < fFontRecords.count(); ++i) {
        fFontRecords[i].fFont->unref();
    }
    fFontRecords.reset();
    fFunctionShaderRecords.unrefAll();
    fFunctionShaderRecords.reset();
    fAlphaShaderRecords.unrefAll();
    fAlphaShaderRecords.reset();
    fImageShaderRecords.unrefAll();
    fImageShaderRecords.reset();
    fGraphicStateRecords.foreach ([](WrapGS w) { w.fPtr->unref(); });
    fGraphicStateRecords.reset();
<<<<<<< HEAD

    fPDFBitmapMap.foreach ([](SkBitmapKey, SkPDFObject** p) { (*p)->unref(); });
    fPDFBitmapMap.reset();
=======
    fBitmapRecords.unrefAll();
    fBitmapRecords.reset();
>>>>>>> miniblink49
}

////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
template <class T>
T* assert_ptr(T* p)
{
    SkASSERT(p);
    return p;
}

// requires `bool T::equals(const U&) const`
template <typename T, typename U>
T* find_item(const SkTDArray<T*>& ptrArray, const U& object)
{
=======
template <class T> T* assert_ptr(T* p) { SkASSERT(p); return p; }

// requires `bool T::equals(const U&) const`
template <typename T, typename U>
T* find_item(const SkTDArray<T*>& ptrArray, const U& object) {
>>>>>>> miniblink49
    for (int i = 0; i < ptrArray.count(); ++i) {
        if (ptrArray[i]->equals(object)) {
            return ptrArray[i];
        }
    }
<<<<<<< HEAD
    return nullptr;
=======
    return NULL;
>>>>>>> miniblink49
}

////////////////////////////////////////////////////////////////////////////////

SkPDFFont* SkPDFCanon::findFont(uint32_t fontID,
<<<<<<< HEAD
    uint16_t glyphID,
    SkPDFFont** relatedFontPtr) const
{
    SkASSERT(relatedFontPtr);

    SkPDFFont* relatedFont = nullptr;
    for (int i = 0; i < fFontRecords.count(); ++i) {
        SkPDFFont::Match match = SkPDFFont::IsMatch(
            fFontRecords[i].fFont, fFontRecords[i].fFontID,
            fFontRecords[i].fGlyphID, fontID, glyphID);
=======
                                uint16_t glyphID,
                                SkPDFFont** relatedFontPtr) const {
    SkASSERT(relatedFontPtr);

    SkPDFFont* relatedFont = NULL;
    for (int i = 0; i < fFontRecords.count(); ++i) {
        SkPDFFont::Match match = SkPDFFont::IsMatch(
                fFontRecords[i].fFont, fFontRecords[i].fFontID,
                fFontRecords[i].fGlyphID, fontID, glyphID);
>>>>>>> miniblink49
        if (SkPDFFont::kExact_Match == match) {
            return fFontRecords[i].fFont;
        } else if (!relatedFont && SkPDFFont::kRelated_Match == match) {
            relatedFont = fFontRecords[i].fFont;
        }
    }
<<<<<<< HEAD
    *relatedFontPtr = relatedFont; // May still be nullptr.
    return nullptr;
}

void SkPDFCanon::addFont(SkPDFFont* font, uint32_t fontID, uint16_t fGlyphID)
{
=======
    *relatedFontPtr = relatedFont;  // May still be NULL.
    return NULL;
}

void SkPDFCanon::addFont(SkPDFFont* font, uint32_t fontID, uint16_t fGlyphID) {
>>>>>>> miniblink49
    SkPDFCanon::FontRec* rec = fFontRecords.push();
    rec->fFont = SkRef(font);
    rec->fFontID = fontID;
    rec->fGlyphID = fGlyphID;
}

////////////////////////////////////////////////////////////////////////////////

SkPDFFunctionShader* SkPDFCanon::findFunctionShader(
<<<<<<< HEAD
    const SkPDFShader::State& state) const
{
    return find_item(fFunctionShaderRecords, state);
}
void SkPDFCanon::addFunctionShader(SkPDFFunctionShader* pdfShader)
{
=======
        const SkPDFShader::State& state) const {
    return find_item(fFunctionShaderRecords, state);
}
void SkPDFCanon::addFunctionShader(SkPDFFunctionShader* pdfShader) {
>>>>>>> miniblink49
    fFunctionShaderRecords.push(SkRef(pdfShader));
}

////////////////////////////////////////////////////////////////////////////////

SkPDFAlphaFunctionShader* SkPDFCanon::findAlphaShader(
<<<<<<< HEAD
    const SkPDFShader::State& state) const
{
    return find_item(fAlphaShaderRecords, state);
}
void SkPDFCanon::addAlphaShader(SkPDFAlphaFunctionShader* pdfShader)
{
=======
        const SkPDFShader::State& state) const {
    return find_item(fAlphaShaderRecords, state);
}
void SkPDFCanon::addAlphaShader(SkPDFAlphaFunctionShader* pdfShader) {
>>>>>>> miniblink49
    fAlphaShaderRecords.push(SkRef(pdfShader));
}

////////////////////////////////////////////////////////////////////////////////

SkPDFImageShader* SkPDFCanon::findImageShader(
<<<<<<< HEAD
    const SkPDFShader::State& state) const
{
    return find_item(fImageShaderRecords, state);
}

void SkPDFCanon::addImageShader(SkPDFImageShader* pdfShader)
{
=======
        const SkPDFShader::State& state) const {
    return find_item(fImageShaderRecords, state);
}

void SkPDFCanon::addImageShader(SkPDFImageShader* pdfShader) {
>>>>>>> miniblink49
    fImageShaderRecords.push(SkRef(pdfShader));
}

////////////////////////////////////////////////////////////////////////////////

const SkPDFGraphicState* SkPDFCanon::findGraphicState(
<<<<<<< HEAD
    const SkPDFGraphicState& key) const
{
    const WrapGS* ptr = fGraphicStateRecords.find(WrapGS(&key));
    return ptr ? ptr->fPtr : nullptr;
}

void SkPDFCanon::addGraphicState(const SkPDFGraphicState* state)
{
=======
        const SkPDFGraphicState& key) const {
    const WrapGS* ptr = fGraphicStateRecords.find(WrapGS(&key));
    return ptr ? ptr->fPtr : NULL;
}

void SkPDFCanon::addGraphicState(const SkPDFGraphicState* state) {
>>>>>>> miniblink49
    SkASSERT(state);
    WrapGS w(SkRef(state));
    SkASSERT(!fGraphicStateRecords.contains(w));
    fGraphicStateRecords.add(w);
}

////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
sk_sp<SkPDFObject> SkPDFCanon::findPDFBitmap(SkBitmapKey key) const
{
    SkPDFObject** ptr = fPDFBitmapMap.find(key);
    return ptr ? sk_ref_sp(*ptr) : sk_sp<SkPDFObject>();
}

void SkPDFCanon::addPDFBitmap(SkBitmapKey key, sk_sp<SkPDFObject> pdfBitmap)
{
    fPDFBitmapMap.set(key, pdfBitmap.release());
}

////////////////////////////////////////////////////////////////////////////////

sk_sp<SkPDFStream> SkPDFCanon::makeInvertFunction()
{
    if (fInvertFunction) {
        return fInvertFunction;
    }
    fInvertFunction = SkPDFGraphicState::MakeInvertFunction();
    return fInvertFunction;
}
sk_sp<SkPDFDict> SkPDFCanon::makeNoSmaskGraphicState()
{
    if (fNoSmaskGraphicState) {
        return fNoSmaskGraphicState;
    }
    fNoSmaskGraphicState = SkPDFGraphicState::MakeNoSmaskGraphicState();
    return fNoSmaskGraphicState;
}
sk_sp<SkPDFArray> SkPDFCanon::makeRangeObject()
{
    if (fRangeObject) {
        return fRangeObject;
    }
    fRangeObject = SkPDFShader::MakeRangeObject();
    return fRangeObject;
=======
SkPDFBitmap* SkPDFCanon::findBitmap(const SkBitmap& bm) const {
    return find_item(fBitmapRecords, bm);
}

void SkPDFCanon::addBitmap(SkPDFBitmap* pdfBitmap) {
    fBitmapRecords.push(SkRef(pdfBitmap));
>>>>>>> miniblink49
}
