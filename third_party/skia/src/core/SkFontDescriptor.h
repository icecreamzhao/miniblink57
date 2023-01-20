/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkFontDescriptor_DEFINED
#define SkFontDescriptor_DEFINED

<<<<<<< HEAD
#include "SkFixed.h"
=======
>>>>>>> miniblink49
#include "SkStream.h"
#include "SkString.h"
#include "SkTypeface.h"

class SkFontData {
public:
    /** This takes ownership of 'stream'. Makes a copy of the data in 'axis'. */
    SkFontData(SkStreamAsset* stream, int index, const SkFixed axis[], int axisCount)
<<<<<<< HEAD
        : fStream(stream)
        , fIndex(index)
        , fAxisCount(axisCount)
        , fAxis(axisCount)
=======
        : fStream(stream), fIndex(index), fAxisCount(axisCount), fAxis(axisCount)
>>>>>>> miniblink49
    {
        for (int i = 0; i < axisCount; ++i) {
            fAxis[i] = axis[i];
        }
    }
    SkFontData(const SkFontData& that)
        : fStream(that.fStream->duplicate())
        , fIndex(that.fIndex)
        , fAxisCount(that.fAxisCount)
        , fAxis(fAxisCount)
    {
        for (int i = 0; i < fAxisCount; ++i) {
            fAxis[i] = that.fAxis[i];
        }
    }
<<<<<<< HEAD
    bool hasStream() const { return fStream.get() != nullptr; }
    SkStreamAsset* duplicateStream() const { return fStream->duplicate(); }
    SkStreamAsset* detachStream() { return fStream.release(); }
=======
    bool hasStream() const { return fStream.get() != NULL; }
    SkStreamAsset* duplicateStream() const { return fStream->duplicate(); }
    SkStreamAsset* detachStream() { return fStream.detach(); }
>>>>>>> miniblink49
    SkStreamAsset* getStream() { return fStream.get(); }
    int getIndex() const { return fIndex; }
    int getAxisCount() const { return fAxisCount; }
    const SkFixed* getAxis() const { return fAxis.get(); }

private:
    SkAutoTDelete<SkStreamAsset> fStream;
    int fIndex;
    int fAxisCount;
    SkAutoSTMalloc<4, SkFixed> fAxis;
};

class SkFontDescriptor : SkNoncopyable {
public:
    SkFontDescriptor(SkTypeface::Style = SkTypeface::kNormal);
    // Does not affect ownership of SkStream.
<<<<<<< HEAD
    static bool Deserialize(SkStream*, SkFontDescriptor* result);
=======
    SkFontDescriptor(SkStream*);
>>>>>>> miniblink49

    void serialize(SkWStream*);

    SkTypeface::Style getStyle() { return fStyle; }
    void setStyle(SkTypeface::Style style) { fStyle = style; }

    const char* getFamilyName() const { return fFamilyName.c_str(); }
    const char* getFullName() const { return fFullName.c_str(); }
    const char* getPostscriptName() const { return fPostscriptName.c_str(); }
<<<<<<< HEAD
    bool hasFontData() const { return fFontData.get() != nullptr; }
    SkFontData* detachFontData() { return fFontData.release(); }
=======
    bool hasFontData() const { return fFontData.get() != NULL; }
    SkFontData* detachFontData() { return fFontData.detach(); }
>>>>>>> miniblink49

    void setFamilyName(const char* name) { fFamilyName.set(name); }
    void setFullName(const char* name) { fFullName.set(name); }
    void setPostscriptName(const char* name) { fPostscriptName.set(name); }
    /** Set the font data only if it is necessary for serialization.
     *  This method takes ownership of the font data. */
    void setFontData(SkFontData* data) { fFontData.reset(data); }

private:
    SkString fFamilyName;
    SkString fFullName;
    SkString fPostscriptName;
    SkAutoTDelete<SkFontData> fFontData;

    SkTypeface::Style fStyle;
};

#endif // SkFontDescriptor_DEFINED
