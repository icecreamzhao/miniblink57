/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkSize_DEFINED
#define SkSize_DEFINED

#include "SkScalar.h"

<<<<<<< HEAD
template <typename T>
struct SkTSize {
    T fWidth;
    T fHeight;

    static SkTSize Make(T w, T h)
    {
=======
template <typename T> struct SkTSize {
    T fWidth;
    T fHeight;

    static SkTSize Make(T w, T h) {
>>>>>>> miniblink49
        SkTSize s;
        s.fWidth = w;
        s.fHeight = h;
        return s;
    }

<<<<<<< HEAD
    void set(T w, T h)
    {
=======
    void set(T w, T h) {
>>>>>>> miniblink49
        fWidth = w;
        fHeight = h;
    }

    /** Returns true iff fWidth == 0 && fHeight == 0
     */
<<<<<<< HEAD
    bool isZero() const
    {
=======
    bool isZero() const {
>>>>>>> miniblink49
        return 0 == fWidth && 0 == fHeight;
    }

    /** Returns true if either widht or height are <= 0 */
<<<<<<< HEAD
    bool isEmpty() const
    {
=======
    bool isEmpty() const {
>>>>>>> miniblink49
        return fWidth <= 0 || fHeight <= 0;
    }

    /** Set the width and height to 0 */
<<<<<<< HEAD
    void setEmpty()
    {
=======
    void setEmpty() {
>>>>>>> miniblink49
        fWidth = fHeight = 0;
    }

    T width() const { return fWidth; }
    T height() const { return fHeight; }

    /** If width or height is < 0, it is set to 0 */
<<<<<<< HEAD
    void clampNegToZero()
    {
=======
    void clampNegToZero() {
>>>>>>> miniblink49
        if (fWidth < 0) {
            fWidth = 0;
        }
        if (fHeight < 0) {
            fHeight = 0;
        }
    }

<<<<<<< HEAD
    bool equals(T w, T h) const
    {
=======
    bool equals(T w, T h) const {
>>>>>>> miniblink49
        return fWidth == w && fHeight == h;
    }
};

template <typename T>
<<<<<<< HEAD
static inline bool operator==(const SkTSize<T>& a, const SkTSize<T>& b)
{
=======
static inline bool operator==(const SkTSize<T>& a, const SkTSize<T>& b) {
>>>>>>> miniblink49
    return a.fWidth == b.fWidth && a.fHeight == b.fHeight;
}

template <typename T>
<<<<<<< HEAD
static inline bool operator!=(const SkTSize<T>& a, const SkTSize<T>& b)
{
=======
static inline bool operator!=(const SkTSize<T>& a, const SkTSize<T>& b) {
>>>>>>> miniblink49
    return !(a == b);
}

///////////////////////////////////////////////////////////////////////////////

typedef SkTSize<int32_t> SkISize;

struct SkSize : public SkTSize<SkScalar> {
<<<<<<< HEAD
    static SkSize Make(SkScalar w, SkScalar h)
    {
=======
    static SkSize Make(SkScalar w, SkScalar h) {
>>>>>>> miniblink49
        SkSize s;
        s.fWidth = w;
        s.fHeight = h;
        return s;
    }

<<<<<<< HEAD
    SkSize& operator=(const SkISize& src)
    {
=======

    SkSize& operator=(const SkISize& src) {
>>>>>>> miniblink49
        this->set(SkIntToScalar(src.fWidth), SkIntToScalar(src.fHeight));
        return *this;
    }

<<<<<<< HEAD
    SkISize toRound() const
    {
=======
    SkISize toRound() const {
>>>>>>> miniblink49
        SkISize s;
        s.set(SkScalarRoundToInt(fWidth), SkScalarRoundToInt(fHeight));
        return s;
    }

<<<<<<< HEAD
    SkISize toCeil() const
    {
=======
    SkISize toCeil() const {
>>>>>>> miniblink49
        SkISize s;
        s.set(SkScalarCeilToInt(fWidth), SkScalarCeilToInt(fHeight));
        return s;
    }

<<<<<<< HEAD
    SkISize toFloor() const
    {
=======
    SkISize toFloor() const {
>>>>>>> miniblink49
        SkISize s;
        s.set(SkScalarFloorToInt(fWidth), SkScalarFloorToInt(fHeight));
        return s;
    }
};

#endif
