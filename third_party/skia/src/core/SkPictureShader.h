/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkPictureShader_DEFINED
#define SkPictureShader_DEFINED

#include "SkShader.h"

class SkBitmap;
class SkPicture;

/*
 * An SkPictureShader can be used to draw SkPicture-based patterns.
 *
 * The SkPicture is first rendered into a tile, which is then used to shade the area according
 * to specified tiling rules.
 */
class SkPictureShader : public SkShader {
public:
<<<<<<< HEAD
    static sk_sp<SkShader> Make(sk_sp<SkPicture>, TileMode, TileMode, const SkMatrix*,
        const SkRect*);
=======
    static SkShader* Create(const SkPicture*, TileMode, TileMode, const SkMatrix*,
                                   const SkRect*);
    virtual ~SkPictureShader();

    size_t contextSize() const override;
>>>>>>> miniblink49

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkPictureShader)

<<<<<<< HEAD
#if SK_SUPPORT_GPU
    sk_sp<GrFragmentProcessor> asFragmentProcessor(GrContext*,
        const SkMatrix& viewM,
        const SkMatrix*,
        SkFilterQuality,
        SkSourceGammaTreatment) const override;
#endif
=======
    bool asFragmentProcessor(GrContext*, const SkPaint&, const SkMatrix& viewM, const SkMatrix*,
                             GrColor*, GrProcessorDataManager*,
                             GrFragmentProcessor**) const override;
>>>>>>> miniblink49

protected:
    SkPictureShader(SkReadBuffer&);
    void flatten(SkWriteBuffer&) const override;
<<<<<<< HEAD
    size_t onContextSize(const ContextRec&) const override;
    Context* onCreateContext(const ContextRec&, void* storage) const override;

private:
    SkPictureShader(sk_sp<SkPicture>, TileMode, TileMode, const SkMatrix*, const SkRect*);

    sk_sp<SkShader> refBitmapShader(const SkMatrix&, const SkMatrix* localMatrix,
        const int maxTextureSize = 0) const;

    sk_sp<SkPicture> fPicture;
    SkRect fTile;
    TileMode fTmx, fTmy;
=======
    Context* onCreateContext(const ContextRec&, void* storage) const override;

private:
    SkPictureShader(const SkPicture*, TileMode, TileMode, const SkMatrix*, const SkRect*);

    SkShader* refBitmapShader(const SkMatrix&, const SkMatrix* localMatrix, const int maxTextureSize = 0) const;

    const SkPicture* fPicture;
    SkRect           fTile;
    TileMode         fTmx, fTmy;
>>>>>>> miniblink49

    class PictureShaderContext : public SkShader::Context {
    public:
        static Context* Create(void* storage, const SkPictureShader&, const ContextRec&,
<<<<<<< HEAD
            sk_sp<SkShader> bitmapShader);
=======
                               SkShader* bitmapShader);
>>>>>>> miniblink49

        virtual ~PictureShaderContext();

        uint32_t getFlags() const override;

        ShadeProc asAShadeProc(void** ctx) override;
        void shadeSpan(int x, int y, SkPMColor dstC[], int count) override;
<<<<<<< HEAD

    private:
        PictureShaderContext(const SkPictureShader&, const ContextRec&,
            sk_sp<SkShader> bitmapShader);

        sk_sp<SkShader> fBitmapShader;
        SkShader::Context* fBitmapShaderContext;
        void* fBitmapShaderContextStorage;
=======
        void shadeSpan16(int x, int y, uint16_t dstC[], int count) override;

    private:
        PictureShaderContext(const SkPictureShader&, const ContextRec&, SkShader* bitmapShader);

        SkAutoTUnref<SkShader>  fBitmapShader;
        SkShader::Context*      fBitmapShaderContext;
        void*                   fBitmapShaderContextStorage;
>>>>>>> miniblink49

        typedef SkShader::Context INHERITED;
    };

    typedef SkShader INHERITED;
};

#endif // SkPictureShader_DEFINED
