/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrProgramElement.h"
#include "GrGpuResourceRef.h"
<<<<<<< HEAD
#include "SkAtomics.h"

uint32_t GrProgramElement::CreateUniqueID()
{
=======

uint32_t GrProgramElement::CreateUniqueID() {
>>>>>>> miniblink49
    static int32_t gUniqueID = SK_InvalidUniqueID;
    uint32_t id;
    do {
        id = static_cast<uint32_t>(sk_atomic_inc(&gUniqueID) + 1);
    } while (id == SK_InvalidUniqueID);
    return id;
}

<<<<<<< HEAD
void GrProgramElement::addPendingIOs() const
{
=======
void GrProgramElement::addPendingIOs() const {
>>>>>>> miniblink49
    for (int i = 0; i < fGpuResources.count(); ++i) {
        fGpuResources[i]->markPendingIO();
    }
}

<<<<<<< HEAD
void GrProgramElement::removeRefs() const
{
=======
void GrProgramElement::removeRefs() const {
>>>>>>> miniblink49
    for (int i = 0; i < fGpuResources.count(); ++i) {
        fGpuResources[i]->removeRef();
    }
}

<<<<<<< HEAD
void GrProgramElement::pendingIOComplete() const
{
=======
void GrProgramElement::pendingIOComplete() const {
>>>>>>> miniblink49
    for (int i = 0; i < fGpuResources.count(); ++i) {
        fGpuResources[i]->pendingIOComplete();
    }
}
<<<<<<< HEAD
=======

>>>>>>> miniblink49
