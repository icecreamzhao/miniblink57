/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkPixelSerializer_DEFINED
#define SkPixelSerializer_DEFINED

<<<<<<< HEAD
#include "SkPixmap.h"
#include "SkRefCnt.h"

class SkData;
=======
#include "SkRefCnt.h"

class SkData;
struct SkImageInfo;
>>>>>>> miniblink49

/**
 *  Interface for serializing pixels, e.g. SkBitmaps in an SkPicture.
 */
class SkPixelSerializer : public SkRefCnt {
public:
<<<<<<< HEAD
    virtual ~SkPixelSerializer() { }
=======
    virtual ~SkPixelSerializer() {}
>>>>>>> miniblink49

    /**
     *  Call to determine if the client wants to serialize the encoded data. If
     *  false, serialize another version (e.g. the result of encodePixels).
     */
<<<<<<< HEAD
    bool useEncodedData(const void* data, size_t len)
    {
=======
    bool useEncodedData(const void* data, size_t len) {
>>>>>>> miniblink49
        return this->onUseEncodedData(data, len);
    }

    /**
     *  Call to get the client's version of encoding these pixels. If it
     *  returns NULL, serialize the raw pixels.
     */
<<<<<<< HEAD
    SkData* encode(const SkPixmap& pixmap) { return this->onEncode(pixmap); }
=======
    SkData* encodePixels(const SkImageInfo& info, const void* pixels, size_t rowBytes) {
        return this->onEncodePixels(info, pixels, rowBytes);
    }
>>>>>>> miniblink49

protected:
    /**
     *  Return true if you want to serialize the encoded data, false if you want
<<<<<<< HEAD
     *  another version serialized (e.g. the result of this->encode()).
=======
     *  another version serialized (e.g. the result of encodePixels).
>>>>>>> miniblink49
     */
    virtual bool onUseEncodedData(const void* data, size_t len) = 0;

    /**
     *  If you want to encode these pixels, return the encoded data as an SkData
     *  Return null if you want to serialize the raw pixels.
     */
<<<<<<< HEAD
    virtual SkData* onEncode(const SkPixmap&) = 0;
=======
    virtual SkData* onEncodePixels(const SkImageInfo&, const void* pixels, size_t rowBytes) = 0;
>>>>>>> miniblink49
};
#endif // SkPixelSerializer_DEFINED
