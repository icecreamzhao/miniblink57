<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef SkLayerRasterizer_DEFINED
#define SkLayerRasterizer_DEFINED

#include "SkDeque.h"
#include "SkRasterizer.h"
=======

#ifndef SkLayerRasterizer_DEFINED
#define SkLayerRasterizer_DEFINED

#include "SkRasterizer.h"
#include "SkDeque.h"
>>>>>>> miniblink49
#include "SkScalar.h"

class SkPaint;

class SK_API SkLayerRasterizer : public SkRasterizer {
public:
    virtual ~SkLayerRasterizer();

    class SK_API Builder {
    public:
        Builder();
        ~Builder();

<<<<<<< HEAD
        void addLayer(const SkPaint& paint)
        {
=======
        void addLayer(const SkPaint& paint) {
>>>>>>> miniblink49
            this->addLayer(paint, 0, 0);
        }

        /**
          *  Add a new layer (above any previous layers) to the rasterizer.
          *  The layer will extract those fields that affect the mask from
          *  the specified paint, but will not retain a reference to the paint
          *  object itself, so it may be reused without danger of side-effects.
          */
        void addLayer(const SkPaint& paint, SkScalar dx, SkScalar dy);

        /**
          *  Pass queue of layers on to newly created layer rasterizer and return it. The builder
          *  *cannot* be used any more after calling this function. If no layers have been added,
          *  returns NULL.
          *
          *  The caller is responsible for calling unref() on the returned object, if non NULL.
          */
<<<<<<< HEAD
        sk_sp<SkLayerRasterizer> detach();
=======
        SkLayerRasterizer* detachRasterizer();
>>>>>>> miniblink49

        /**
          *  Create and return a new immutable SkLayerRasterizer that contains a shapshot of the
          *  layers that were added to the Builder, without modifying the Builder. The Builder
          *  *may* be used after calling this function. It will continue to hold any layers
          *  previously added, so consecutive calls to this function will return identical objects,
          *  and objects returned by future calls to this function contain all the layers in
          *  previously returned objects. If no layers have been added, returns NULL.
          *
          *  Future calls to addLayer will not affect rasterizers previously returned by this call.
          *
          *  The caller is responsible for calling unref() on the returned object, if non NULL.
          */
<<<<<<< HEAD
        sk_sp<SkLayerRasterizer> snapshot() const;

#ifdef SK_SUPPORT_LEGACY_MINOR_EFFECT_PTR
        SkLayerRasterizer* detachRasterizer()
        {
            return this->detach().release();
        }
        SkLayerRasterizer* snapshotRasterizer() const
        {
            return this->snapshot().release();
        }
#endif
=======
        SkLayerRasterizer* snapshotRasterizer() const;
>>>>>>> miniblink49

    private:
        SkDeque* fLayers;
    };

    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkLayerRasterizer)

protected:
    SkLayerRasterizer();
    SkLayerRasterizer(SkDeque* layers);
    void flatten(SkWriteBuffer&) const override;

    // override from SkRasterizer
    virtual bool onRasterize(const SkPath& path, const SkMatrix& matrix,
<<<<<<< HEAD
        const SkIRect* clipBounds,
        SkMask* mask, SkMask::CreateMode mode) const override;
=======
                             const SkIRect* clipBounds,
                             SkMask* mask, SkMask::CreateMode mode) const override;
>>>>>>> miniblink49

private:
    const SkDeque* const fLayers;

    static SkDeque* ReadLayers(SkReadBuffer& buffer);

    friend class LayerRasterizerTester;

    typedef SkRasterizer INHERITED;
};

#endif
