
/*
 * Copyright 2009 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkTRegistry_DEFINED
#define SkTRegistry_DEFINED

#include "SkTypes.h"

/** Template class that registers itself (in the constructor) into a linked-list
    and provides a function-pointer. This can be used to auto-register a set of
    services, e.g. a set of image codecs.
 */
<<<<<<< HEAD
template <typename T>
class SkTRegistry : SkNoncopyable {
public:
    typedef T Factory;

    explicit SkTRegistry(T fact)
        : fFact(fact)
    {
=======
template <typename T> class SkTRegistry : SkNoncopyable {
public:
    typedef T Factory;

    explicit SkTRegistry(T fact) : fFact(fact) {
>>>>>>> miniblink49
#ifdef SK_BUILD_FOR_ANDROID
        // work-around for double-initialization bug
        {
            SkTRegistry* reg = gHead;
            while (reg) {
                if (reg == this) {
                    return;
                }
                reg = reg->fChain;
            }
        }
#endif
        fChain = gHead;
<<<<<<< HEAD
        gHead = this;
=======
        gHead  = this;
>>>>>>> miniblink49
    }

    static const SkTRegistry* Head() { return gHead; }

    const SkTRegistry* next() const { return fChain; }
    const Factory& factory() const { return fFact; }

private:
<<<<<<< HEAD
    Factory fFact;
=======
    Factory      fFact;
>>>>>>> miniblink49
    SkTRegistry* fChain;

    static SkTRegistry* gHead;
};

// The caller still needs to declare an instance of this somewhere
<<<<<<< HEAD
template <typename T>
SkTRegistry<T>* SkTRegistry<T>::gHead;
=======
template <typename T> SkTRegistry<T>* SkTRegistry<T>::gHead;
>>>>>>> miniblink49

#endif
