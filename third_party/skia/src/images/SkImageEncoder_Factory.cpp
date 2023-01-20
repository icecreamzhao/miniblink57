<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2009 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkImageEncoder.h"

template SkImageEncoder_EncodeReg* SkImageEncoder_EncodeReg::gHead;

<<<<<<< HEAD
SkImageEncoder* SkImageEncoder::Create(Type t)
{
    SkImageEncoder* codec = nullptr;
    const SkImageEncoder_EncodeReg* curr = SkImageEncoder_EncodeReg::Head();
    while (curr) {
        if ((codec = curr->factory()(t)) != nullptr) {
=======
SkImageEncoder* SkImageEncoder::Create(Type t) {
    SkImageEncoder* codec = NULL;
    const SkImageEncoder_EncodeReg* curr = SkImageEncoder_EncodeReg::Head();
    while (curr) {
        if ((codec = curr->factory()(t)) != NULL) {
>>>>>>> miniblink49
            return codec;
        }
        curr = curr->next();
    }
<<<<<<< HEAD
    return nullptr;
=======
    return NULL;
>>>>>>> miniblink49
}
