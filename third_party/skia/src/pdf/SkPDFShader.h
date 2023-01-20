<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkPDFShader_DEFINED
#define SkPDFShader_DEFINED

#include "SkPDFStream.h"
#include "SkPDFTypes.h"

class SkPDFCanon;
<<<<<<< HEAD
class SkPDFDocument;
=======
>>>>>>> miniblink49
class SkMatrix;
class SkShader;
struct SkIRect;

/** \class SkPDFShader

    In PDF parlance, this is a pattern, used in place of a color when the
    pattern color space is selected.
*/

class SkPDFShader {
public:
    class State;

    /** Get the PDF shader for the passed SkShader. If the SkShader is
<<<<<<< HEAD
     *  invalid in some way, returns nullptr. The reference count of
=======
     *  invalid in some way, returns NULL. The reference count of
>>>>>>> miniblink49
     *  the object is incremented and it is the caller's responsibility to
     *  unreference it when done.  This is needed to accommodate the weak
     *  reference pattern used when the returned object is new and has no
     *  other references.
     *  @param shader      The SkShader to emulate.
     *  @param matrix      The current transform. (PDF shaders are absolutely
     *                     positioned, relative to where the page is drawn.)
     *  @param surfceBBox  The bounding box of the drawing surface (with matrix
     *                     already applied).
     *  @param rasterScale Additional scale to be applied for early
     *                     rasterization.
     */
<<<<<<< HEAD
    static SkPDFObject* GetPDFShader(SkPDFDocument* doc,
        SkScalar dpi,
        SkShader* shader,
        const SkMatrix& matrix,
        const SkIRect& surfaceBBox,
        SkScalar rasterScale);

    static sk_sp<SkPDFArray> MakeRangeObject();
};

class SkPDFFunctionShader final : public SkPDFDict {
public:
    static SkPDFFunctionShader* Create(SkPDFCanon*,
        std::unique_ptr<SkPDFShader::State>*);
=======
    static SkPDFObject* GetPDFShader(SkPDFCanon* canon,
                                     SkScalar dpi,
                                     const SkShader& shader,
                                     const SkMatrix& matrix,
                                     const SkIRect& surfaceBBox,
                                     SkScalar rasterScale);
};

class SkPDFFunctionShader : public SkPDFDict {
    

public:
    static SkPDFFunctionShader* Create(SkPDFCanon*,
                                       SkAutoTDelete<SkPDFShader::State>*);
>>>>>>> miniblink49
    virtual ~SkPDFFunctionShader();
    bool equals(const SkPDFShader::State&) const;

private:
<<<<<<< HEAD
    std::unique_ptr<const SkPDFShader::State> fShaderState;
=======
    SkAutoTDelete<const SkPDFShader::State> fShaderState;
>>>>>>> miniblink49
    SkPDFFunctionShader(SkPDFShader::State*);
    typedef SkPDFDict INHERITED;
};

/**
 * A shader for PDF gradients. This encapsulates the function shader
 * inside a tiling pattern while providing a common pattern interface.
 * The encapsulation allows the use of a SMask for transparency gradients.
 */
<<<<<<< HEAD
class SkPDFAlphaFunctionShader final : public SkPDFStream {
public:
    static SkPDFAlphaFunctionShader* Create(SkPDFDocument*,
        SkScalar dpi,
        std::unique_ptr<SkPDFShader::State>*);
=======
class SkPDFAlphaFunctionShader : public SkPDFStream {
public:
    static SkPDFAlphaFunctionShader* Create(SkPDFCanon*,
                                            SkScalar dpi,
                                            SkAutoTDelete<SkPDFShader::State>*);
>>>>>>> miniblink49
    virtual ~SkPDFAlphaFunctionShader();
    bool equals(const SkPDFShader::State&) const;

private:
<<<<<<< HEAD
    std::unique_ptr<const SkPDFShader::State> fShaderState;
=======
    SkAutoTDelete<const SkPDFShader::State> fShaderState;
>>>>>>> miniblink49
    SkPDFAlphaFunctionShader(SkPDFShader::State*);
    typedef SkPDFStream INHERITED;
};

<<<<<<< HEAD
class SkPDFImageShader final : public SkPDFStream {
public:
    static SkPDFImageShader* Create(SkPDFDocument*,
        SkScalar dpi,
        std::unique_ptr<SkPDFShader::State>*);
=======
class SkPDFImageShader : public SkPDFStream {
public:
    static SkPDFImageShader* Create(SkPDFCanon*,
                                    SkScalar dpi,
                                    SkAutoTDelete<SkPDFShader::State>*);
>>>>>>> miniblink49
    virtual ~SkPDFImageShader();
    bool equals(const SkPDFShader::State&) const;

private:
<<<<<<< HEAD
    std::unique_ptr<const SkPDFShader::State> fShaderState;
=======
    SkAutoTDelete<const SkPDFShader::State> fShaderState;
>>>>>>> miniblink49
    SkPDFImageShader(SkPDFShader::State*);
    typedef SkPDFStream INHERITED;
};

#endif
