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
=======

>>>>>>> miniblink49
#ifndef SkAntiRun_DEFINED
#define SkAntiRun_DEFINED

#include "SkBlitter.h"

/** Sparse array of run-length-encoded alpha (supersampling coverage) values.
    Sparseness allows us to independently compose several paths into the
    same SkAlphaRuns buffer.
*/

class SkAlphaRuns {
public:
<<<<<<< HEAD
    int16_t* fRuns;
    uint8_t* fAlpha;

    /// Returns true if the scanline contains only a single run,
    /// of alpha value 0.
    bool empty() const
    {
=======
    int16_t*    fRuns;
    uint8_t*     fAlpha;

    /// Returns true if the scanline contains only a single run,
    /// of alpha value 0.
    bool empty() const {
>>>>>>> miniblink49
        SkASSERT(fRuns[0] > 0);
        return fAlpha[0] == 0 && fRuns[fRuns[0]] == 0;
    }

    /// Reinitialize for a new scanline.
<<<<<<< HEAD
    void reset(int width);
=======
    void    reset(int width);
>>>>>>> miniblink49

    /**
     *  Insert into the buffer a run starting at (x-offsetX):
     *      if startAlpha > 0
     *          one pixel with value += startAlpha,
     *              max 255
     *      if middleCount > 0
     *          middleCount pixels with value += maxValue
     *      if stopAlpha > 0
     *          one pixel with value += stopAlpha
     *  Returns the offsetX value that should be passed on the next call,
     *  assuming we're on the same scanline. If the caller is switching
     *  scanlines, then offsetX should be 0 when this is called.
     */
    SK_ALWAYS_INLINE int add(int x, U8CPU startAlpha, int middleCount, U8CPU stopAlpha,
<<<<<<< HEAD
        U8CPU maxValue, int offsetX)
    {
=======
                             U8CPU maxValue, int offsetX) {
>>>>>>> miniblink49
        SkASSERT(middleCount >= 0);
        SkASSERT(x >= 0 && x + (startAlpha != 0) + middleCount + (stopAlpha != 0) <= fWidth);

        SkASSERT(fRuns[offsetX] >= 0);

<<<<<<< HEAD
        int16_t* runs = fRuns + offsetX;
        uint8_t* alpha = fAlpha + offsetX;
        uint8_t* lastAlpha = alpha;
=======
        int16_t*    runs = fRuns + offsetX;
        uint8_t*    alpha = fAlpha + offsetX;
        uint8_t*    lastAlpha = alpha;
>>>>>>> miniblink49
        x -= offsetX;

        if (startAlpha) {
            SkAlphaRuns::Break(runs, alpha, x, 1);
            /*  I should be able to just add alpha[x] + startAlpha.
                However, if the trailing edge of the previous span and the leading
                edge of the current span round to the same super-sampled x value,
                I might overflow to 256 with this add, hence the funny subtract (crud).
            */
            unsigned tmp = alpha[x] + startAlpha;
            SkASSERT(tmp <= 256);
<<<<<<< HEAD
            alpha[x] = SkToU8(tmp - (tmp >> 8)); // was (tmp >> 7), but that seems wrong if we're trying to catch 256
=======
            alpha[x] = SkToU8(tmp - (tmp >> 8));    // was (tmp >> 7), but that seems wrong if we're trying to catch 256
>>>>>>> miniblink49

            runs += x + 1;
            alpha += x + 1;
            x = 0;
<<<<<<< HEAD
=======
            lastAlpha += x; // we don't want the +1
>>>>>>> miniblink49
            SkDEBUGCODE(this->validate();)
        }

        if (middleCount) {
            SkAlphaRuns::Break(runs, alpha, x, middleCount);
            alpha += x;
            runs += x;
            x = 0;
            do {
                alpha[0] = SkToU8(alpha[0] + maxValue);
                int n = runs[0];
                SkASSERT(n <= middleCount);
                alpha += n;
                runs += n;
                middleCount -= n;
            } while (middleCount > 0);
            SkDEBUGCODE(this->validate();)
<<<<<<< HEAD
                lastAlpha
                = alpha;
=======
            lastAlpha = alpha;
>>>>>>> miniblink49
        }

        if (stopAlpha) {
            SkAlphaRuns::Break(runs, alpha, x, 1);
            alpha += x;
            alpha[0] = SkToU8(alpha[0] + stopAlpha);
            SkDEBUGCODE(this->validate();)
<<<<<<< HEAD
                lastAlpha
                = alpha;
        }

        return SkToS32(lastAlpha - fAlpha); // new offsetX
    }

    SkDEBUGCODE(void assertValid(int y, int maxStep) const;)
        SkDEBUGCODE(void dump() const;)

        /**
=======
            lastAlpha = alpha;
        }

        return SkToS32(lastAlpha - fAlpha);  // new offsetX
    }

    SkDEBUGCODE(void assertValid(int y, int maxStep) const;)
    SkDEBUGCODE(void dump() const;)

    /**
>>>>>>> miniblink49
     * Break the runs in the buffer at offsets x and x+count, properly
     * updating the runs to the right and left.
     *   i.e. from the state AAAABBBB, run-length encoded as A4B4,
     *   Break(..., 2, 5) would produce AAAABBBB rle as A2A2B3B1.
     * Allows add() to sum another run to some of the new sub-runs.
     *   i.e. adding ..CCCCC. would produce AADDEEEB, rle as A2D2E3B1.
     */
<<<<<<< HEAD
        static void Break(int16_t runs[], uint8_t alpha[], int x, int count)
    {
=======
    static void Break(int16_t runs[], uint8_t alpha[], int x, int count) {
>>>>>>> miniblink49
        SkASSERT(count > 0 && x >= 0);

        //  SkAlphaRuns::BreakAt(runs, alpha, x);
        //  SkAlphaRuns::BreakAt(&runs[x], &alpha[x], count);

        int16_t* next_runs = runs + x;
<<<<<<< HEAD
        uint8_t* next_alpha = alpha + x;
=======
        uint8_t*  next_alpha = alpha + x;
>>>>>>> miniblink49

        while (x > 0) {
            int n = runs[0];
            SkASSERT(n > 0);

            if (x < n) {
                alpha[x] = alpha[0];
                runs[0] = SkToS16(x);
                runs[x] = SkToS16(n - x);
                break;
            }
            runs += n;
            alpha += n;
            x -= n;
        }

        runs = next_runs;
        alpha = next_alpha;
        x = count;

        for (;;) {
            int n = runs[0];
            SkASSERT(n > 0);

            if (x < n) {
                alpha[x] = alpha[0];
                runs[0] = SkToS16(x);
                runs[x] = SkToS16(n - x);
                break;
            }
            x -= n;
            if (x <= 0) {
                break;
            }
            runs += n;
            alpha += n;
        }
    }

    /**
     * Cut (at offset x in the buffer) a run into two shorter runs with
     * matching alpha values.
     * Used by the RectClipBlitter to trim a RLE encoding to match the
     * clipping rectangle.
     */
<<<<<<< HEAD
    static void BreakAt(int16_t runs[], uint8_t alpha[], int x)
    {
=======
    static void BreakAt(int16_t runs[], uint8_t alpha[], int x) {
>>>>>>> miniblink49
        while (x > 0) {
            int n = runs[0];
            SkASSERT(n > 0);

            if (x < n) {
                alpha[x] = alpha[0];
                runs[0] = SkToS16(x);
                runs[x] = SkToS16(n - x);
                break;
            }
            runs += n;
            alpha += n;
            x -= n;
        }
    }

private:
    SkDEBUGCODE(int fWidth;)
<<<<<<< HEAD
        SkDEBUGCODE(void validate() const;)
=======
    SkDEBUGCODE(void validate() const;)
>>>>>>> miniblink49
};

#endif
