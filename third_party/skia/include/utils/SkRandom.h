/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkRandom_DEFINED
#define SkRandom_DEFINED

<<<<<<< HEAD
#include "../private/SkFixed.h"
=======
>>>>>>> miniblink49
#include "SkScalar.h"

/** \class SkRandom

 Utility class that implements pseudo random 32bit numbers using Marsaglia's
 multiply-with-carry "mother of all" algorithm. Unlike rand(), this class holds
 its own state, so that multiple instances can be used with no side-effects.

 Has a large period and all bits are well-randomized.
 */
class SkRandom {
public:
    SkRandom() { init(0); }
    SkRandom(uint32_t seed) { init(seed); }
<<<<<<< HEAD
    SkRandom(const SkRandom& rand)
        : fK(rand.fK)
        , fJ(rand.fJ)
    {
    }

    SkRandom& operator=(const SkRandom& rand)
    {
=======
    SkRandom(const SkRandom& rand) : fK(rand.fK), fJ(rand.fJ) {}

    SkRandom& operator=(const SkRandom& rand) {
>>>>>>> miniblink49
        fK = rand.fK;
        fJ = rand.fJ;

        return *this;
    }

    /** Return the next pseudo random number as an unsigned 32bit value.
     */
<<<<<<< HEAD
    uint32_t nextU()
    {
        fK = kKMul * (fK & 0xffff) + (fK >> 16);
        fJ = kJMul * (fJ & 0xffff) + (fJ >> 16);
=======
    uint32_t nextU() {
        fK = kKMul*(fK & 0xffff) + (fK >> 16);
        fJ = kJMul*(fJ & 0xffff) + (fJ >> 16);
>>>>>>> miniblink49
        return (((fK << 16) | (fK >> 16)) + fJ);
    }

    /** Return the next pseudo random number as a signed 32bit value.
     */
    int32_t nextS() { return (int32_t)this->nextU(); }

    /** Return the next pseudo random number as an unsigned 16bit value.
     */
    U16CPU nextU16() { return this->nextU() >> 16; }

    /** Return the next pseudo random number as a signed 16bit value.
     */
    S16CPU nextS16() { return this->nextS() >> 16; }

    /**
     *  Returns value [0...1) as an IEEE float
     */
<<<<<<< HEAD
    float nextF()
    {
=======
    float nextF() {
>>>>>>> miniblink49
        unsigned int floatint = 0x3f800000 | (this->nextU() >> 9);
        float f = SkBits2Float(floatint) - 1.0f;
        return f;
    }

    /**
     *  Returns value [min...max) as a float
     */
<<<<<<< HEAD
    float nextRangeF(float min, float max)
    {
=======
    float nextRangeF(float min, float max) {
>>>>>>> miniblink49
        return min + this->nextF() * (max - min);
    }

    /** Return the next pseudo random number, as an unsigned value of
     at most bitCount bits.
     @param bitCount The maximum number of bits to be returned
     */
<<<<<<< HEAD
    uint32_t nextBits(unsigned bitCount)
    {
=======
    uint32_t nextBits(unsigned bitCount) {
>>>>>>> miniblink49
        SkASSERT(bitCount > 0 && bitCount <= 32);
        return this->nextU() >> (32 - bitCount);
    }

    /** Return the next pseudo random unsigned number, mapped to lie within
     [min, max] inclusive.
     */
<<<<<<< HEAD
    uint32_t nextRangeU(uint32_t min, uint32_t max)
    {
=======
    uint32_t nextRangeU(uint32_t min, uint32_t max) {
>>>>>>> miniblink49
        SkASSERT(min <= max);
        uint32_t range = max - min + 1;
        if (0 == range) {
            return this->nextU();
        } else {
            return min + this->nextU() % range;
        }
    }

    /** Return the next pseudo random unsigned number, mapped to lie within
     [0, count).
     */
<<<<<<< HEAD
    uint32_t nextULessThan(uint32_t count)
    {
=======
    uint32_t nextULessThan(uint32_t count) {
>>>>>>> miniblink49
        SkASSERT(count > 0);
        return this->nextRangeU(0, count - 1);
    }

<<<<<<< HEAD
=======
    /** Return the next pseudo random number expressed as an unsigned SkFixed
     in the range [0..SK_Fixed1).
     */
    SkFixed nextUFixed1() { return this->nextU() >> 16; }

    /** Return the next pseudo random number expressed as a signed SkFixed
     in the range (-SK_Fixed1..SK_Fixed1).
     */
    SkFixed nextSFixed1() { return this->nextS() >> 15; }

>>>>>>> miniblink49
    /** Return the next pseudo random number expressed as a SkScalar
     in the range [0..SK_Scalar1).
     */
    SkScalar nextUScalar1() { return SkFixedToScalar(this->nextUFixed1()); }

    /** Return the next pseudo random number expressed as a SkScalar
     in the range [min..max).
     */
<<<<<<< HEAD
    SkScalar nextRangeScalar(SkScalar min, SkScalar max)
    {
=======
    SkScalar nextRangeScalar(SkScalar min, SkScalar max) {
>>>>>>> miniblink49
        return this->nextUScalar1() * (max - min) + min;
    }

    /** Return the next pseudo random number expressed as a SkScalar
<<<<<<< HEAD
     in the range [-SK_Scalar1..SK_Scalar1).
=======
     in the range (-SK_Scalar1..SK_Scalar1).
>>>>>>> miniblink49
     */
    SkScalar nextSScalar1() { return SkFixedToScalar(this->nextSFixed1()); }

    /** Return the next pseudo random number as a bool.
     */
    bool nextBool() { return this->nextU() >= 0x80000000; }

    /** A biased version of nextBool().
     */
<<<<<<< HEAD
    bool nextBiasedBool(SkScalar fractionTrue)
    {
=======
    bool nextBiasedBool(SkScalar fractionTrue) {
>>>>>>> miniblink49
        SkASSERT(fractionTrue >= 0 && fractionTrue <= SK_Scalar1);
        return this->nextUScalar1() <= fractionTrue;
    }

    /**
     *  Return the next pseudo random number as a signed 64bit value.
     */
<<<<<<< HEAD
    int64_t next64()
    {
=======
    int64_t next64() {
>>>>>>> miniblink49
        int64_t hi = this->nextS();
        return (hi << 32) | this->nextU();
    }

    /** Reset the random object.
     */
    void setSeed(uint32_t seed) { init(seed); }

private:
    // Initialize state variables with LCG.
    // We must ensure that both J and K are non-zero, otherwise the
    // multiply-with-carry step will forevermore return zero.
<<<<<<< HEAD
    void init(uint32_t seed)
    {
=======
    void init(uint32_t seed) {
>>>>>>> miniblink49
        fK = NextLCG(seed);
        if (0 == fK) {
            fK = NextLCG(fK);
        }
        fJ = NextLCG(fK);
        if (0 == fJ) {
            fJ = NextLCG(fJ);
        }
        SkASSERT(0 != fK && 0 != fJ);
    }
<<<<<<< HEAD
    static uint32_t NextLCG(uint32_t seed) { return kMul * seed + kAdd; }

    /** Return the next pseudo random number expressed as an unsigned SkFixed
     in the range [0..SK_Fixed1).
     */
    SkFixed nextUFixed1() { return this->nextU() >> 16; }

    /** Return the next pseudo random number expressed as a signed SkFixed
     in the range [-SK_Fixed1..SK_Fixed1).
     */
    SkFixed nextSFixed1() { return this->nextS() >> 15; }
=======
    static uint32_t NextLCG(uint32_t seed) { return kMul*seed + kAdd; }
>>>>>>> miniblink49

    //  See "Numerical Recipes in C", 1992 page 284 for these constants
    //  For the LCG that sets the initial state from a seed
    enum {
        kMul = 1664525,
        kAdd = 1013904223
    };
    // Constants for the multiply-with-carry steps
    enum {
        kKMul = 30345,
        kJMul = 18000,
    };

    uint32_t fK;
    uint32_t fJ;
};

#endif
