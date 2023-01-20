/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkRecordOpts.h"

#include "SkRecordPattern.h"
#include "SkRecords.h"
#include "SkTDArray.h"

using namespace SkRecords;

<<<<<<< HEAD
// Most of the optimizations in this file are pattern-based.  These are all defined as structs with:
//   - a Match typedef
//   - a bool onMatch(SkRceord*, Match*, int begin, int end) method,
//     which returns true if it made changes and false if not.

// Run a pattern-based optimization once across the SkRecord, returning true if it made any changes.
// It looks for spans which match Pass::Match, and when found calls onMatch() with that pattern,
// record, and [begin,end) span of the commands that matched.
template <typename Pass>
static bool apply(Pass* pass, SkRecord* record)
{
    typename Pass::Match match;
    bool changed = false;
    int begin, end = 0;

    while (match.search(record, &begin, &end)) {
        changed |= pass->onMatch(record, &match, begin, end);
=======
void SkRecordOptimize(SkRecord* record) {
    // This might be useful  as a first pass in the future if we want to weed
    // out junk for other optimization passes.  Right now, nothing needs it,
    // and the bounding box hierarchy will do the work of skipping no-op
    // Save-NoDraw-Restore sequences better than we can here.
    //SkRecordNoopSaveRestores(record);

    SkRecordNoopSaveLayerDrawRestores(record);
    SkRecordMergeSvgOpacityAndFilterLayers(record);
}

// Most of the optimizations in this file are pattern-based.  These are all defined as structs with:
//   - a Pattern typedef
//   - a bool onMatch(SkRceord*, Pattern*, unsigned begin, unsigned end) method,
//     which returns true if it made changes and false if not.

// Run a pattern-based optimization once across the SkRecord, returning true if it made any changes.
// It looks for spans which match Pass::Pattern, and when found calls onMatch() with the pattern,
// record, and [begin,end) span of the commands that matched.
template <typename Pass>
static bool apply(Pass* pass, SkRecord* record) {
    typename Pass::Pattern pattern;
    bool changed = false;
    unsigned begin, end = 0;

    while (pattern.search(record, &begin, &end)) {
        changed |= pass->onMatch(record, &pattern, begin, end);
>>>>>>> miniblink49
    }
    return changed;
}

<<<<<<< HEAD
///////////////////////////////////////////////////////////////////////////////////////////////////

static void multiple_set_matrices(SkRecord* record)
{
    struct {
        typedef Pattern<Is<SetMatrix>,
            Greedy<Is<NoOp>>,
            Is<SetMatrix>>
            Match;

        bool onMatch(SkRecord* record, Match* pattern, int begin, int end)
        {
            record->replace<NoOp>(begin); // first SetMatrix
            return true;
        }
    } pass;
    while (apply(&pass, record))
        ;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

#if 0 // experimental, but needs knowledge of previous matrix to operate correctly
static void apply_matrix_to_draw_params(SkRecord* record) {
    struct {
        typedef Pattern<Is<SetMatrix>,
                        Greedy<Is<NoOp>>,
                        Is<SetMatrix> >
            Pattern;

        bool onMatch(SkRecord* record, Pattern* pattern, int begin, int end) {
            record->replace<NoOp>(begin);  // first SetMatrix
            return true;
        }
    } pass;
    // No need to loop, as we never "open up" opportunities for more of this type of optimization.
    apply(&pass, record);
}
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////

// Turns the logical NoOp Save and Restore in Save-Draw*-Restore patterns into actual NoOps.
struct SaveOnlyDrawsRestoreNooper {
    typedef Pattern<Is<Save>,
        Greedy<Or<Is<NoOp>, IsDraw>>,
        Is<Restore>>
        Match;

    bool onMatch(SkRecord* record, Match*, int begin, int end)
    {
        record->replace<NoOp>(begin); // Save
        record->replace<NoOp>(end - 1); // Restore
=======
// Turns the logical NoOp Save and Restore in Save-Draw*-Restore patterns into actual NoOps.
struct SaveOnlyDrawsRestoreNooper {
    typedef Pattern3<Is<Save>,
                     Star<Or<Is<NoOp>, IsDraw> >,
                     Is<Restore> >
        Pattern;

    bool onMatch(SkRecord* record, Pattern* pattern, unsigned begin, unsigned end) {
        record->replace<NoOp>(begin);  // Save
        record->replace<NoOp>(end-1);  // Restore
>>>>>>> miniblink49
        return true;
    }
};

static bool fold_opacity_layer_color_to_paint(const SkPaint& layerPaint,
<<<<<<< HEAD
    bool isSaveLayer,
    SkPaint* paint)
{
=======
                                              bool isSaveLayer,
                                              SkPaint* paint) {
>>>>>>> miniblink49
    // We assume layerPaint is always from a saveLayer.  If isSaveLayer is
    // true, we assume paint is too.

    // The alpha folding can proceed if the filter layer paint does not have properties which cause
    // the resulting filter layer to be "blended" in complex ways to the parent layer. For example,
    // looper drawing unmodulated filter layer twice and then modulating the result produces
    // different image to drawing modulated filter layer twice.
    // TODO: most likely the looper and only some xfer modes are the hard constraints
    if (paint->getXfermode() || paint->getLooper()) {
        return false;
    }

    if (!isSaveLayer && paint->getImageFilter()) {
        // For normal draws, the paint color is used as one input for the color for the draw. Image
        // filter will operate on the result, and thus we can not change the input.
        // For layer saves, the image filter is applied to the layer contents. The layer is then
        // modulated with the paint color, so it's fine to proceed with the fold for saveLayer
        // paints with image filters.
        return false;
    }

    if (paint->getColorFilter()) {
        // Filter input depends on the paint color.

        // Here we could filter the color if we knew the draw is going to be uniform color.  This
        // should be detectable as drawPath/drawRect/.. without a shader being uniform, while
        // drawBitmap/drawSprite or a shader being non-uniform. However, current matchers don't
        // give the type out easily, so just do not optimize that at the moment.
        return false;
    }

    const uint32_t layerColor = layerPaint.getColor();
    // The layer paint color must have only alpha component.
    if (SK_ColorTRANSPARENT != SkColorSetA(layerColor, SK_AlphaTRANSPARENT)) {
        return false;
    }

    // The layer paint can not have any effects.
<<<<<<< HEAD
    if (layerPaint.getPathEffect() || layerPaint.getShader() || layerPaint.getXfermode() || layerPaint.getMaskFilter() || layerPaint.getColorFilter() || layerPaint.getRasterizer() || layerPaint.getLooper() || layerPaint.getImageFilter()) {
=======
    if (layerPaint.getPathEffect() ||
        layerPaint.getShader()      ||
        layerPaint.getXfermode()    ||
        layerPaint.getMaskFilter()  ||
        layerPaint.getColorFilter() ||
        layerPaint.getRasterizer()  ||
        layerPaint.getLooper()      ||
        layerPaint.getImageFilter()) {
>>>>>>> miniblink49
        return false;
    }

    paint->setAlpha(SkMulDiv255Round(paint->getAlpha(), SkColorGetA(layerColor)));

    return true;
}

// Turns logical no-op Save-[non-drawing command]*-Restore patterns into actual no-ops.
struct SaveNoDrawsRestoreNooper {
<<<<<<< HEAD
    // Greedy matches greedily, so we also have to exclude Save and Restore.
    // Nested SaveLayers need to be excluded, or we'll match their Restore!
    typedef Pattern<Is<Save>,
        Greedy<Not<Or<Is<Save>,
            Is<SaveLayer>,
            Is<Restore>,
            IsDraw>>>,
        Is<Restore>>
        Match;

    bool onMatch(SkRecord* record, Match*, int begin, int end)
    {
        // The entire span between Save and Restore (inclusively) does nothing.
        for (int i = begin; i < end; i++) {
=======
    // Star matches greedily, so we also have to exclude Save and Restore.
    // Nested SaveLayers need to be excluded, or we'll match their Restore!
    typedef Pattern3<Is<Save>,
                     Star<Not<Or4<Is<Save>,
                                  Is<SaveLayer>,
                                  Is<Restore>,
                                  IsDraw> > >,
                     Is<Restore> >
        Pattern;

    bool onMatch(SkRecord* record, Pattern* pattern, unsigned begin, unsigned end) {
        // The entire span between Save and Restore (inclusively) does nothing.
        for (unsigned i = begin; i < end; i++) {
>>>>>>> miniblink49
            record->replace<NoOp>(i);
        }
        return true;
    }
};
<<<<<<< HEAD
void SkRecordNoopSaveRestores(SkRecord* record)
{
=======
void SkRecordNoopSaveRestores(SkRecord* record) {
>>>>>>> miniblink49
    SaveOnlyDrawsRestoreNooper onlyDraws;
    SaveNoDrawsRestoreNooper noDraws;

    // Run until they stop changing things.
<<<<<<< HEAD
    while (apply(&onlyDraws, record) || apply(&noDraws, record))
        ;
=======
    while (apply(&onlyDraws, record) || apply(&noDraws, record));
>>>>>>> miniblink49
}

// For some SaveLayer-[drawing command]-Restore patterns, merge the SaveLayer's alpha into the
// draw, and no-op the SaveLayer and Restore.
struct SaveLayerDrawRestoreNooper {
<<<<<<< HEAD
    typedef Pattern<Is<SaveLayer>, IsDraw, Is<Restore>> Match;

    bool onMatch(SkRecord* record, Match* match, int begin, int end)
    {
        if (match->first<SaveLayer>()->backdrop) {
            // can't throw away the layer if we have a backdrop
            return false;
        }

        // A SaveLayer's bounds field is just a hint, so we should be free to ignore it.
        SkPaint* layerPaint = match->first<SaveLayer>()->paint;
        if (nullptr == layerPaint) {
=======
    typedef Pattern3<Is<SaveLayer>, IsDraw, Is<Restore> > Pattern;

    bool onMatch(SkRecord* record, Pattern* pattern, unsigned begin, unsigned end) {
        // A SaveLayer's bounds field is just a hint, so we should be free to ignore it.
        SkPaint* layerPaint = pattern->first<SaveLayer>()->paint;
        if (NULL == layerPaint) {
>>>>>>> miniblink49
            // There wasn't really any point to this SaveLayer at all.
            return KillSaveLayerAndRestore(record, begin);
        }

<<<<<<< HEAD
        SkPaint* drawPaint = match->second<SkPaint>();
        if (drawPaint == nullptr) {
=======
        SkPaint* drawPaint = pattern->second<SkPaint>();
        if (drawPaint == NULL) {
>>>>>>> miniblink49
            // We can just give the draw the SaveLayer's paint.
            // TODO(mtklein): figure out how to do this clearly
            return false;
        }

        if (!fold_opacity_layer_color_to_paint(*layerPaint, false /*isSaveLayer*/, drawPaint)) {
            return false;
        }

        return KillSaveLayerAndRestore(record, begin);
    }

<<<<<<< HEAD
    static bool KillSaveLayerAndRestore(SkRecord* record, int saveLayerIndex)
    {
        record->replace<NoOp>(saveLayerIndex); // SaveLayer
        record->replace<NoOp>(saveLayerIndex + 2); // Restore
        return true;
    }
};
void SkRecordNoopSaveLayerDrawRestores(SkRecord* record)
{
=======
    static bool KillSaveLayerAndRestore(SkRecord* record, unsigned saveLayerIndex) {
        record->replace<NoOp>(saveLayerIndex);    // SaveLayer
        record->replace<NoOp>(saveLayerIndex+2);  // Restore
        return true;
    }
};
void SkRecordNoopSaveLayerDrawRestores(SkRecord* record) {
>>>>>>> miniblink49
    SaveLayerDrawRestoreNooper pass;
    apply(&pass, record);
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
/* For SVG generated:
  SaveLayer (non-opaque, typically for CSS opacity)
    Save
      ClipRect
      SaveLayer (typically for SVG filter)
      Restore
    Restore
  Restore
*/
struct SvgOpacityAndFilterLayerMergePass {
<<<<<<< HEAD
    typedef Pattern<Is<SaveLayer>, Is<Save>, Is<ClipRect>, Is<SaveLayer>,
        Is<Restore>, Is<Restore>, Is<Restore>>
        Match;

    bool onMatch(SkRecord* record, Match* match, int begin, int end)
    {
        if (match->first<SaveLayer>()->backdrop) {
            // can't throw away the layer if we have a backdrop
            return false;
        }

        SkPaint* opacityPaint = match->first<SaveLayer>()->paint;
        if (nullptr == opacityPaint) {
=======
    typedef Pattern7<Is<SaveLayer>, Is<Save>, Is<ClipRect>, Is<SaveLayer>,
                     Is<Restore>, Is<Restore>, Is<Restore> > Pattern;

    bool onMatch(SkRecord* record, Pattern* pattern, unsigned begin, unsigned end) {
        SkPaint* opacityPaint = pattern->first<SaveLayer>()->paint;
        if (NULL == opacityPaint) {
>>>>>>> miniblink49
            // There wasn't really any point to this SaveLayer at all.
            return KillSaveLayerAndRestore(record, begin);
        }

        // This layer typically contains a filter, but this should work for layers with for other
        // purposes too.
<<<<<<< HEAD
        SkPaint* filterLayerPaint = match->fourth<SaveLayer>()->paint;
        if (filterLayerPaint == nullptr) {
=======
        SkPaint* filterLayerPaint = pattern->fourth<SaveLayer>()->paint;
        if (filterLayerPaint == NULL) {
>>>>>>> miniblink49
            // We can just give the inner SaveLayer the paint of the outer SaveLayer.
            // TODO(mtklein): figure out how to do this clearly
            return false;
        }

        if (!fold_opacity_layer_color_to_paint(*opacityPaint, true /*isSaveLayer*/,
<<<<<<< HEAD
                filterLayerPaint)) {
=======
                                               filterLayerPaint)) {
>>>>>>> miniblink49
            return false;
        }

        return KillSaveLayerAndRestore(record, begin);
    }

<<<<<<< HEAD
    static bool KillSaveLayerAndRestore(SkRecord* record, int saveLayerIndex)
    {
        record->replace<NoOp>(saveLayerIndex); // SaveLayer
=======
    static bool KillSaveLayerAndRestore(SkRecord* record, unsigned saveLayerIndex) {
        record->replace<NoOp>(saveLayerIndex);     // SaveLayer
>>>>>>> miniblink49
        record->replace<NoOp>(saveLayerIndex + 6); // Restore
        return true;
    }
};

<<<<<<< HEAD
void SkRecordMergeSvgOpacityAndFilterLayers(SkRecord* record)
{
    SvgOpacityAndFilterLayerMergePass pass;
    apply(&pass, record);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void SkRecordOptimize(SkRecord* record)
{
    // This might be useful  as a first pass in the future if we want to weed
    // out junk for other optimization passes.  Right now, nothing needs it,
    // and the bounding box hierarchy will do the work of skipping no-op
    // Save-NoDraw-Restore sequences better than we can here.
    //SkRecordNoopSaveRestores(record);

    SkRecordNoopSaveLayerDrawRestores(record);
    SkRecordMergeSvgOpacityAndFilterLayers(record);

    record->defrag();
}

void SkRecordOptimize2(SkRecord* record)
{
    multiple_set_matrices(record);
    SkRecordNoopSaveRestores(record);
    SkRecordNoopSaveLayerDrawRestores(record);
    SkRecordMergeSvgOpacityAndFilterLayers(record);

    record->defrag();
}
=======
void SkRecordMergeSvgOpacityAndFilterLayers(SkRecord* record) {
    SvgOpacityAndFilterLayerMergePass pass;
    apply(&pass, record);
}
>>>>>>> miniblink49
