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
#include "SkTagList.h"

SkTagList::~SkTagList()
{
}

SkTagList* SkTagList::Find(SkTagList* rec, U8CPU tag)
{
    SkASSERT(tag < kSkTagListCount);

<<<<<<< HEAD
    while (rec != nullptr) {
=======
    while (rec != NULL)
    {
>>>>>>> miniblink49
        if (rec->fTag == tag)
            break;
        rec = rec->fNext;
    }
    return rec;
}

void SkTagList::DeleteTag(SkTagList** head, U8CPU tag)
{
    SkASSERT(tag < kSkTagListCount);

    SkTagList* rec = *head;
<<<<<<< HEAD
    SkTagList* prev = nullptr;

    while (rec != nullptr) {
        SkTagList* next = rec->fNext;

        if (rec->fTag == tag) {
=======
    SkTagList* prev = NULL;

    while (rec != NULL)
    {
        SkTagList* next = rec->fNext;

        if (rec->fTag == tag)
        {
>>>>>>> miniblink49
            if (prev)
                prev->fNext = next;
            else
                *head = next;
            delete rec;
            break;
        }
        prev = rec;
        rec = next;
    }
}

void SkTagList::DeleteAll(SkTagList* rec)
{
<<<<<<< HEAD
    while (rec) {
=======
    while (rec)
    {
>>>>>>> miniblink49
        SkTagList* next = rec->fNext;
        delete rec;
        rec = next;
    }
}
