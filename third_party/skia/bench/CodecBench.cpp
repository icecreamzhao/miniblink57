/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "CodecBench.h"
<<<<<<< HEAD
#include "CodecBenchPriv.h"
#include "SkBitmap.h"
#include "SkCodec.h"
#include "SkCommandLineFlags.h"
#include "SkOSFile.h"

// Actually zeroing the memory would throw off timing, so we just lie.
DEFINE_bool(zero_init, false, "Pretend our destination is zero-intialized, simulating Android?");

CodecBench::CodecBench(SkString baseName, SkData* encoded, SkColorType colorType,
    SkAlphaType alphaType)
    : fColorType(colorType)
    , fAlphaType(alphaType)
    , fData(SkRef(encoded))
{
    // Parse filename and the color type to give the benchmark a useful name
    fName.printf("Codec_%s_%s%s", baseName.c_str(), color_type_to_str(colorType),
        alpha_type_to_str(alphaType));
=======
#include "SkBitmap.h"
#include "SkCodec.h"
#include "SkOSFile.h"

CodecBench::CodecBench(SkString baseName, SkData* encoded, SkColorType colorType)
    : fColorType(colorType)
    , fData(SkRef(encoded))
{
    // Parse filename and the color type to give the benchmark a useful name
    const char* colorName;
    switch(colorType) {
        case kN32_SkColorType:
            colorName = "N32";
            break;
        case kRGB_565_SkColorType:
            colorName = "565";
            break;
        case kAlpha_8_SkColorType:
            colorName = "Alpha8";
            break;
        default:
            colorName = "Unknown";
    }
    fName.printf("Codec_%s_%s", baseName.c_str(), colorName);
>>>>>>> miniblink49
#ifdef SK_DEBUG
    // Ensure that we can create an SkCodec from this data.
    SkAutoTDelete<SkCodec> codec(SkCodec::NewFromData(fData));
    SkASSERT(codec);
#endif
}

<<<<<<< HEAD
const char* CodecBench::onGetName()
{
    return fName.c_str();
}

bool CodecBench::isSuitableFor(Backend backend)
{
    return kNonRendering_Backend == backend;
}

void CodecBench::onDelayedSetup()
{
    SkAutoTDelete<SkCodec> codec(SkCodec::NewFromData(fData));

    fInfo = codec->getInfo().makeColorType(fColorType).makeAlphaType(fAlphaType);
=======
const char* CodecBench::onGetName() {
    return fName.c_str();
}

bool CodecBench::isSuitableFor(Backend backend) {
    return kNonRendering_Backend == backend;
}

void CodecBench::onPreDraw() {
    SkAutoTDelete<SkCodec> codec(SkCodec::NewFromData(fData));

    fInfo = codec->getInfo().makeColorType(fColorType);
    SkAlphaType alphaType;
    // Caller should not have created this CodecBench if the alpha type was
    // invalid.
    SkAssertResult(SkColorTypeValidateAlphaType(fColorType, fInfo.alphaType(),
                                                &alphaType));
    if (alphaType != fInfo.alphaType()) {
        fInfo = fInfo.makeAlphaType(alphaType);
    }
>>>>>>> miniblink49

    fPixelStorage.reset(fInfo.getSafeSize(fInfo.minRowBytes()));
}

<<<<<<< HEAD
void CodecBench::onDraw(int n, SkCanvas* canvas)
{
    SkAutoTDelete<SkCodec> codec;
    SkPMColor colorTable[256];
    int colorCount;
    SkCodec::Options options;
    if (FLAGS_zero_init) {
        options.fZeroInitialized = SkCodec::kYes_ZeroInitialized;
    }
=======
void CodecBench::onDraw(const int n, SkCanvas* canvas) {
    SkAutoTDelete<SkCodec> codec;
    SkPMColor colorTable[256];
    int colorCount;
>>>>>>> miniblink49
    for (int i = 0; i < n; i++) {
        colorCount = 256;
        codec.reset(SkCodec::NewFromData(fData));
#ifdef SK_DEBUG
        const SkCodec::Result result =
#endif
<<<<<<< HEAD
            codec->getPixels(fInfo, fPixelStorage.get(), fInfo.minRowBytes(),
                &options, colorTable, &colorCount);
        SkASSERT(result == SkCodec::kSuccess
            || result == SkCodec::kIncompleteInput);
=======
        codec->getPixels(fInfo, fPixelStorage.get(), fInfo.minRowBytes(),
                         NULL, colorTable, &colorCount);
        SkASSERT(result == SkCodec::kSuccess
                 || result == SkCodec::kIncompleteInput);
>>>>>>> miniblink49
    }
}
