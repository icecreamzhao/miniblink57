/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrInvariantOutput_DEFINED
#define GrInvariantOutput_DEFINED

#include "GrColor.h"

struct GrInitInvariantOutput {
    GrInitInvariantOutput()
<<<<<<< HEAD
        : fValidFlags(kNone_GrColorComponentFlags)
        , fColor(0)
        , fIsSingleComponent(false)
        , fIsLCDCoverage(false)
    {
    }

    void setKnownFourComponents(GrColor color)
    {
=======
        : fValidFlags(0)
        , fColor(0)
        , fIsSingleComponent(false)
        , fIsLCDCoverage(false) {}

    void setKnownFourComponents(GrColor color) {
>>>>>>> miniblink49
        fColor = color;
        fValidFlags = kRGBA_GrColorComponentFlags;
        fIsSingleComponent = false;
    }

<<<<<<< HEAD
    void setUnknownFourComponents()
    {
        fValidFlags = kNone_GrColorComponentFlags;
        fIsSingleComponent = false;
    }

    void setUnknownOpaqueFourComponents()
    {
        fColor = 0xffU << GrColor_SHIFT_A;
=======
    void setUnknownFourComponents() {
        fValidFlags = 0;
        fIsSingleComponent = false;
    }

    void setUnknownOpaqueFourComponents() {
        fColor = 0xff << GrColor_SHIFT_A;
>>>>>>> miniblink49
        fValidFlags = kA_GrColorComponentFlag;
        fIsSingleComponent = false;
    }

<<<<<<< HEAD
    void setKnownSingleComponent(uint8_t alpha)
    {
=======
    void setKnownSingleComponent(uint8_t alpha) {
>>>>>>> miniblink49
        fColor = GrColorPackRGBA(alpha, alpha, alpha, alpha);
        fValidFlags = kRGBA_GrColorComponentFlags;
        fIsSingleComponent = true;
    }

<<<<<<< HEAD
    void setUnknownSingleComponent()
    {
        fValidFlags = kNone_GrColorComponentFlags;
=======
    void setUnknownSingleComponent() {
        fValidFlags = 0;
>>>>>>> miniblink49
        fIsSingleComponent = true;
    }

    void setUsingLCDCoverage() { fIsLCDCoverage = true; }

<<<<<<< HEAD
    GrColorComponentFlags fValidFlags;
    GrColor fColor;
    bool fIsSingleComponent;
    bool fIsLCDCoverage; // Temorary data member until texture pixel configs are
        // updated
=======
    uint32_t fValidFlags;
    GrColor fColor;
    bool fIsSingleComponent;
    bool fIsLCDCoverage; // Temorary data member until texture pixel configs are updated
>>>>>>> miniblink49
};

class GrInvariantOutput {
public:
    GrInvariantOutput(GrColor color, GrColorComponentFlags flags, bool isSingleComponent)
        : fColor(color)
        , fValidFlags(flags)
        , fIsSingleComponent(isSingleComponent)
        , fNonMulStageFound(false)
        , fWillUseInputColor(true)
<<<<<<< HEAD
        , fIsLCDCoverage(false)
    {
    }
=======
        , fIsLCDCoverage(false) {}
>>>>>>> miniblink49

    GrInvariantOutput(const GrInitInvariantOutput& io)
        : fColor(io.fColor)
        , fValidFlags(io.fValidFlags)
        , fIsSingleComponent(io.fIsSingleComponent)
        , fNonMulStageFound(false)
        , fWillUseInputColor(false)
<<<<<<< HEAD
        , fIsLCDCoverage(io.fIsLCDCoverage)
    {
    }

    virtual ~GrInvariantOutput() { }
=======
        , fIsLCDCoverage(io.fIsLCDCoverage) {}

    virtual ~GrInvariantOutput() {}
>>>>>>> miniblink49

    enum ReadInput {
        kWill_ReadInput,
        kWillNot_ReadInput,
    };

<<<<<<< HEAD
    void mulByUnknownOpaqueFourComponents()
    {
=======
    void mulByUnknownOpaqueFourComponents() {
>>>>>>> miniblink49
        SkDEBUGCODE(this->validate());
        if (this->isOpaque()) {
            fValidFlags = kA_GrColorComponentFlag;
            fIsSingleComponent = false;
        } else {
            // Since the current state is not opaque we no longer care if the color being
            // multiplied is opaque.
            this->mulByUnknownFourComponents();
        }
        SkDEBUGCODE(this->validate());
    }

<<<<<<< HEAD
    void mulByUnknownFourComponents()
    {
=======
    void mulByUnknownFourComponents() {
>>>>>>> miniblink49
        SkDEBUGCODE(this->validate());
        if (this->hasZeroAlpha()) {
            this->internalSetToTransparentBlack();
        } else {
            this->internalSetToUnknown();
        }
        SkDEBUGCODE(this->validate());
    }

<<<<<<< HEAD
    void mulByUnknownSingleComponent()
    {
=======
    void mulByUnknownSingleComponent() {
>>>>>>> miniblink49
        SkDEBUGCODE(this->validate());
        if (this->hasZeroAlpha()) {
            this->internalSetToTransparentBlack();
        } else {
            // We don't need to change fIsSingleComponent in this case
<<<<<<< HEAD
            fValidFlags = kNone_GrColorComponentFlags;
=======
            fValidFlags = 0;
>>>>>>> miniblink49
        }
        SkDEBUGCODE(this->validate());
    }

<<<<<<< HEAD
    void mulByKnownSingleComponent(uint8_t alpha)
    {
=======
    void mulByKnownSingleComponent(uint8_t alpha) {
>>>>>>> miniblink49
        SkDEBUGCODE(this->validate());
        if (this->hasZeroAlpha() || 0 == alpha) {
            this->internalSetToTransparentBlack();
        } else {
            if (alpha != 255) {
                // Multiply color by alpha
                fColor = GrColorPackRGBA(SkMulDiv255Round(GrColorUnpackR(fColor), alpha),
<<<<<<< HEAD
                    SkMulDiv255Round(GrColorUnpackG(fColor), alpha),
                    SkMulDiv255Round(GrColorUnpackB(fColor), alpha),
                    SkMulDiv255Round(GrColorUnpackA(fColor), alpha));
=======
                                         SkMulDiv255Round(GrColorUnpackG(fColor), alpha),
                                         SkMulDiv255Round(GrColorUnpackB(fColor), alpha),
                                         SkMulDiv255Round(GrColorUnpackA(fColor), alpha));
>>>>>>> miniblink49
                // We don't need to change fIsSingleComponent in this case
            }
        }
        SkDEBUGCODE(this->validate());
    }

<<<<<<< HEAD
    void mulByKnownFourComponents(GrColor color)
    {
=======
    void mulByKnownFourComponents(GrColor color) {
>>>>>>> miniblink49
        SkDEBUGCODE(this->validate());
        uint32_t a;
        if (GetAlphaAndCheckSingleChannel(color, &a)) {
            this->mulByKnownSingleComponent(a);
        } else {
            if (color != 0xffffffff) {
                fColor = GrColorPackRGBA(
                    SkMulDiv255Round(GrColorUnpackR(fColor), GrColorUnpackR(color)),
                    SkMulDiv255Round(GrColorUnpackG(fColor), GrColorUnpackG(color)),
                    SkMulDiv255Round(GrColorUnpackB(fColor), GrColorUnpackB(color)),
                    SkMulDiv255Round(GrColorUnpackA(fColor), a));
                if (kRGBA_GrColorComponentFlags == fValidFlags) {
                    fIsSingleComponent = GetAlphaAndCheckSingleChannel(fColor, &a);
                }
            }
        }
        SkDEBUGCODE(this->validate());
    }

    // Ignores the incoming color's RGB and muls its alpha by color.
<<<<<<< HEAD
    void mulAlphaByKnownFourComponents(GrColor color)
    {
=======
    void mulAlphaByKnownFourComponents(GrColor color) {
>>>>>>> miniblink49
        SkDEBUGCODE(this->validate());
        uint32_t a;
        if (GetAlphaAndCheckSingleChannel(color, &a)) {
            this->mulAlphaByKnownSingleComponent(a);
        } else if (fValidFlags & kA_GrColorComponentFlag) {
            GrColor preAlpha = GrColorUnpackA(fColor);
            if (0 == preAlpha) {
                this->internalSetToTransparentBlack();
            } else {
                // We know that color has different component values
                fIsSingleComponent = false;
                fColor = GrColorPackRGBA(
                    SkMulDiv255Round(preAlpha, GrColorUnpackR(color)),
                    SkMulDiv255Round(preAlpha, GrColorUnpackG(color)),
                    SkMulDiv255Round(preAlpha, GrColorUnpackB(color)),
                    SkMulDiv255Round(preAlpha, a));
                fValidFlags = kRGBA_GrColorComponentFlags;
            }
        } else {
            fIsSingleComponent = false;
<<<<<<< HEAD
            fValidFlags = kNone_GrColorComponentFlags;
=======
            fValidFlags = 0;
>>>>>>> miniblink49
        }
        SkDEBUGCODE(this->validate());
    }

    // Ignores the incoming color's RGB and muls its alpha by the alpha param and sets all channels
    // equal to that value.
<<<<<<< HEAD
    void mulAlphaByKnownSingleComponent(uint8_t alpha)
    {
=======
    void mulAlphaByKnownSingleComponent(uint8_t alpha) {
>>>>>>> miniblink49
        SkDEBUGCODE(this->validate());
        if (0 == alpha || this->hasZeroAlpha()) {
            this->internalSetToTransparentBlack();
        } else {
            if (fValidFlags & kA_GrColorComponentFlag) {
                GrColor a = GrColorUnpackA(fColor);
                a = SkMulDiv255Round(alpha, a);
                fColor = GrColorPackRGBA(a, a, a, a);
                fValidFlags = kRGBA_GrColorComponentFlags;
            } else {
<<<<<<< HEAD
                fValidFlags = kNone_GrColorComponentFlags;
=======
                fValidFlags = 0;
>>>>>>> miniblink49
            }
            fIsSingleComponent = true;
        }
        SkDEBUGCODE(this->validate());
    }

<<<<<<< HEAD
    void invalidateComponents(GrColorComponentFlags invalidateFlags, ReadInput readsInput)
    {
        SkDEBUGCODE(this->validate());
        fValidFlags = (fValidFlags & ~invalidateFlags);
=======
    void invalidateComponents(uint8_t invalidateFlags, ReadInput readsInput) {
        SkDEBUGCODE(this->validate());
        fValidFlags &= ~invalidateFlags;
>>>>>>> miniblink49
        fIsSingleComponent = false;
        fNonMulStageFound = true;
        if (kWillNot_ReadInput == readsInput) {
            fWillUseInputColor = false;
        }
        SkDEBUGCODE(this->validate());
    }

<<<<<<< HEAD
    void setToOther(GrColorComponentFlags validFlags, GrColor color, ReadInput readsInput)
    {
=======
    void setToOther(uint8_t validFlags, GrColor color, ReadInput readsInput) {
>>>>>>> miniblink49
        SkDEBUGCODE(this->validate());
        fValidFlags = validFlags;
        fColor = color;
        fIsSingleComponent = false;
        fNonMulStageFound = true;
        if (kWillNot_ReadInput == readsInput) {
            fWillUseInputColor = false;
        }
        if (kRGBA_GrColorComponentFlags == fValidFlags) {
            uint32_t a;
            if (GetAlphaAndCheckSingleChannel(color, &a)) {
                fIsSingleComponent = true;
            }
<<<<<<< HEAD
=======
        } else if (kA_GrColorComponentFlag & fValidFlags) {
            // Assuming fColor is premul means if a is 0 the color must be all 0s.
            if (!GrColorUnpackA(fColor)) {
                this->internalSetToTransparentBlack();
            }
>>>>>>> miniblink49
        }
        SkDEBUGCODE(this->validate());
    }

<<<<<<< HEAD
    void setToUnknown(ReadInput readsInput)
    {
        SkDEBUGCODE(this->validate());
        this->internalSetToUnknown();
        fNonMulStageFound = true;
=======
    void setToUnknown(ReadInput readsInput) {
        SkDEBUGCODE(this->validate());
        this->internalSetToUnknown();
        fNonMulStageFound= true;
>>>>>>> miniblink49
        if (kWillNot_ReadInput == readsInput) {
            fWillUseInputColor = false;
        }
        SkDEBUGCODE(this->validate());
    }

    // Temporary setter to handle LCD text correctly until we improve texture pixel config queries
    // and thus can rely solely on number of coverage components for RGA vs single channel coverage.
<<<<<<< HEAD
    void setUsingLCDCoverage()
    {
=======
    void setUsingLCDCoverage() {
>>>>>>> miniblink49
        fIsLCDCoverage = true;
    }

    GrColor color() const { return fColor; }
<<<<<<< HEAD
    GrColorComponentFlags validFlags() const { return fValidFlags; }
    bool willUseInputColor() const { return fWillUseInputColor; }
=======
    uint8_t validFlags() const { return fValidFlags; }
>>>>>>> miniblink49

    /**
     * If isSingleComponent is true, then the flag values for r, g, b, and a must all be the
     * same. If the flags are all set then all color components must be equal.
     */
    SkDEBUGCODE(void validate() const;)

<<<<<<< HEAD
        private : friend class GrProcOptInfo;

    /** Extracts the alpha channel and returns true if r,g,b == a. */
    static bool GetAlphaAndCheckSingleChannel(GrColor color, uint32_t* alpha)
    {
        *alpha = GrColorUnpackA(color);
        return *alpha == GrColorUnpackR(color) && *alpha == GrColorUnpackG(color) && *alpha == GrColorUnpackB(color);
    }

    void reset(GrColor color, GrColorComponentFlags flags, bool isSingleComponent)
    {
=======
private:
    friend class GrProcOptInfo;

    /** Extracts the alpha channel and returns true if r,g,b == a. */
    static bool GetAlphaAndCheckSingleChannel(GrColor color, uint32_t* alpha) {
        *alpha = GrColorUnpackA(color);
        return *alpha == GrColorUnpackR(color) && *alpha == GrColorUnpackG(color) &&
               *alpha == GrColorUnpackB(color);
    }

    void reset(GrColor color, GrColorComponentFlags flags, bool isSingleComponent) {
>>>>>>> miniblink49
        fColor = color;
        fValidFlags = flags;
        fIsSingleComponent = isSingleComponent;
        fNonMulStageFound = false;
        fWillUseInputColor = true;
    }

<<<<<<< HEAD
    void reset(const GrInitInvariantOutput& io)
    {
=======
    void reset(const GrInitInvariantOutput& io) {
>>>>>>> miniblink49
        fColor = io.fColor;
        fValidFlags = io.fValidFlags;
        fIsSingleComponent = io.fIsSingleComponent;
        fNonMulStageFound = false;
        fWillUseInputColor = true;
        fIsLCDCoverage = io.fIsLCDCoverage;
    }

<<<<<<< HEAD
    void internalSetToTransparentBlack()
    {
=======
    void internalSetToTransparentBlack() {
>>>>>>> miniblink49
        fValidFlags = kRGBA_GrColorComponentFlags;
        fColor = 0;
        fIsSingleComponent = true;
    }

<<<<<<< HEAD
    void internalSetToUnknown()
    {
        fValidFlags = kNone_GrColorComponentFlags;
        fIsSingleComponent = false;
    }

    bool hasZeroAlpha() const
    {
        return ((fValidFlags & kA_GrColorComponentFlag) && 0 == GrColorUnpackA(fColor));
    }

    bool isOpaque() const
    {
        return ((fValidFlags & kA_GrColorComponentFlag) && 0xFF == GrColorUnpackA(fColor));
    }

    bool isSolidWhite() const
    {
=======
    void internalSetToUnknown() {
        fValidFlags = 0;
        fIsSingleComponent = false;
    }

    bool hasZeroAlpha() const {
        return ((fValidFlags & kA_GrColorComponentFlag) && 0 == GrColorUnpackA(fColor));
    }

    bool isOpaque() const {
        return ((fValidFlags & kA_GrColorComponentFlag) && 0xFF == GrColorUnpackA(fColor));
    }

    bool isSolidWhite() const {
>>>>>>> miniblink49
        return (fValidFlags == kRGBA_GrColorComponentFlags && 0xFFFFFFFF == fColor);
    }

    bool isSingleComponent() const { return fIsSingleComponent; }

<<<<<<< HEAD
=======
    bool willUseInputColor() const { return fWillUseInputColor; }
>>>>>>> miniblink49
    void resetWillUseInputColor() { fWillUseInputColor = true; }

    bool allStagesMulInput() const { return !fNonMulStageFound; }
    void resetNonMulStageFound() { fNonMulStageFound = false; }

    bool isLCDCoverage() const { return fIsLCDCoverage; }

    SkDEBUGCODE(bool colorComponentsAllEqual() const;)
<<<<<<< HEAD
        /**
     * If alpha is valid, check that any valid R,G,B values are <= A
     */
        SkDEBUGCODE(bool validPreMulColor() const;)

            GrColor fColor;
    GrColorComponentFlags fValidFlags;
=======
    /**
     * If alpha is valid, check that any valid R,G,B values are <= A
     */
    SkDEBUGCODE(bool validPreMulColor() const;)

    GrColor fColor;
    uint32_t fValidFlags;
>>>>>>> miniblink49
    bool fIsSingleComponent;
    bool fNonMulStageFound;
    bool fWillUseInputColor;
    bool fIsLCDCoverage; // Temorary data member until texture pixel configs are updated
<<<<<<< HEAD
};

#endif
=======

};

#endif

>>>>>>> miniblink49
