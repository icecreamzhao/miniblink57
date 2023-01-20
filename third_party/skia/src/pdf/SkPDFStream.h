<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkPDFStream_DEFINED
#define SkPDFStream_DEFINED

#include "SkPDFTypes.h"
<<<<<<< HEAD
#include "SkStream.h"
=======
#include "SkRefCnt.h"
#include "SkStream.h"
#include "SkTemplates.h"

class SkPDFObjNumMap;
>>>>>>> miniblink49

/** \class SkPDFStream

    A stream object in a PDF.  Note, all streams must be indirect objects (via
    SkObjRef).
*/
class SkPDFStream : public SkPDFDict {
<<<<<<< HEAD

public:
    /** Create a PDF stream. A Length entry is automatically added to the
     *  stream dictionary.
     *  @param data   The data part of the stream.  Will not take ownership.
     */
    explicit SkPDFStream(SkData* data) { this->setData(data); }

    /** Create a PDF stream. A Length entry is automatically added to the
     *  stream dictionary.
     *  @param stream The data part of the stream.  Will not take ownership.
     */
    explicit SkPDFStream(SkStreamAsset* stream) { this->setData(stream); }
=======
    
public:
    /** Create a PDF stream. A Length entry is automatically added to the
     *  stream dictionary.
     *  @param data   The data part of the stream.  Will be ref()ed.
     */
    explicit SkPDFStream(SkData* data);

    /** Create a PDF stream. A Length entry is automatically added to the
     *  stream dictionary.
     *  @param stream The data part of the stream.  Will be duplicate()d.
     */
    explicit SkPDFStream(SkStream* stream);
>>>>>>> miniblink49

    virtual ~SkPDFStream();

    // The SkPDFObject interface.
    void emitObject(SkWStream* stream,
<<<<<<< HEAD
        const SkPDFObjNumMap& objNumMap,
        const SkPDFSubstituteMap& substitutes) const override;
    void drop() override;

protected:
    /* Create a PDF stream with no data.  The setData method must be called to
     * set the data.
     */
    SkPDFStream() { }

    /** Only call this function once. */
    void setData(SkStreamAsset* stream);
    void setData(SkData* data)
    {
        SkMemoryStream memoryStream(data);
        this->setData(&memoryStream);
    }

private:
    std::unique_ptr<SkStreamAsset> fCompressedData;
=======
                    const SkPDFObjNumMap& objNumMap,
                    const SkPDFSubstituteMap& substitutes) override;

protected:
    enum State {
        kUnused_State,         //!< The stream hasn't been requested yet.
        kNoCompression_State,  //!< The stream's been requested in an
                               //   uncompressed form.
        kCompressed_State,     //!< The stream's already been compressed.
    };

    /* Create a PDF stream with no data.  The setData method must be called to
     * set the data.
     */
    SkPDFStream();

    void setData(SkData* data);
    void setData(SkStream* stream);

    size_t dataSize() const;

    void setState(State state) {
        fState = state;
    }

private:
    // Indicates what form (or if) the stream has been requested.
    State fState;

    SkAutoTDelete<SkStreamRewindable> fDataStream;
>>>>>>> miniblink49

    typedef SkPDFDict INHERITED;
};

#endif
