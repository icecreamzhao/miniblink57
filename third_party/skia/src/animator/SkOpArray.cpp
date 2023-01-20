
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkOpArray.h"

<<<<<<< HEAD
SkOpArray::SkOpArray()
    : fType(SkOperand2::kNoType)
{
}

SkOpArray::SkOpArray(SkOperand2::OpType type)
    : fType(type)
{
}

bool SkOpArray::getIndex(int index, SkOperand2* operand)
{
=======
SkOpArray::SkOpArray() : fType(SkOperand2::kNoType) {
}

SkOpArray::SkOpArray(SkOperand2::OpType type) : fType(type) {
}

bool SkOpArray::getIndex(int index, SkOperand2* operand) {
>>>>>>> miniblink49
    if (index >= count()) {
        SkASSERT(0);
        return false;
    }
    *operand = begin()[index];
    return true;
}
