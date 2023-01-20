/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkTLS.h"

// enable to help debug TLS storage
//#define SK_TRACE_TLS_LIFETIME

<<<<<<< HEAD
#ifdef SK_TRACE_TLS_LIFETIME
#include "SkAtomics.h"
static int32_t gTLSRecCount;
#endif

struct SkTLSRec {
    SkTLSRec* fNext;
    void* fData;
    SkTLS::CreateProc fCreateProc;
    SkTLS::DeleteProc fDeleteProc;

#ifdef SK_TRACE_TLS_LIFETIME
    SkTLSRec()
    {
=======

#ifdef SK_TRACE_TLS_LIFETIME
    #include "SkAtomics.h"
    static int32_t gTLSRecCount;
#endif

struct SkTLSRec {
    SkTLSRec*           fNext;
    void*               fData;
    SkTLS::CreateProc   fCreateProc;
    SkTLS::DeleteProc   fDeleteProc;

#ifdef SK_TRACE_TLS_LIFETIME
    SkTLSRec() {
>>>>>>> miniblink49
        int n = sk_atomic_inc(&gTLSRecCount);
        SkDebugf(" SkTLSRec[%d]\n", n);
    }
#endif

<<<<<<< HEAD
    ~SkTLSRec()
    {
=======
    ~SkTLSRec() {
>>>>>>> miniblink49
        if (fDeleteProc) {
            fDeleteProc(fData);
        }
        // else we leak fData, or it will be managed by the caller

#ifdef SK_TRACE_TLS_LIFETIME
        int n = sk_atomic_dec(&gTLSRecCount);
        SkDebugf("~SkTLSRec[%d]\n", n - 1);
#endif
    }
};

<<<<<<< HEAD
void SkTLS::Destructor(void* ptr)
{
=======
void SkTLS::Destructor(void* ptr) {
>>>>>>> miniblink49
#ifdef SK_TRACE_TLS_LIFETIME
    SkDebugf("SkTLS::Destructor(%p)\n", ptr);
#endif

    SkTLSRec* rec = (SkTLSRec*)ptr;
    do {
        SkTLSRec* next = rec->fNext;
<<<<<<< HEAD
        delete rec;
=======
        SkDELETE(rec);
>>>>>>> miniblink49
        rec = next;
    } while (rec);
}

<<<<<<< HEAD
void* SkTLS::Get(CreateProc createProc, DeleteProc deleteProc)
{
    if (nullptr == createProc) {
        return nullptr;
=======
void* SkTLS::Get(CreateProc createProc, DeleteProc deleteProc) {
    if (NULL == createProc) {
        return NULL;
>>>>>>> miniblink49
    }

    void* ptr = SkTLS::PlatformGetSpecific(true);

    if (ptr) {
        const SkTLSRec* rec = (const SkTLSRec*)ptr;
        do {
            if (rec->fCreateProc == createProc) {
                SkASSERT(rec->fDeleteProc == deleteProc);
                return rec->fData;
            }
<<<<<<< HEAD
        } while ((rec = rec->fNext) != nullptr);
=======
        } while ((rec = rec->fNext) != NULL);
>>>>>>> miniblink49
        // not found, so create a new one
    }

    // add a new head of our change
    SkTLSRec* rec = new SkTLSRec;
    rec->fNext = (SkTLSRec*)ptr;

    SkTLS::PlatformSetSpecific(rec);

    rec->fData = createProc();
    rec->fCreateProc = createProc;
    rec->fDeleteProc = deleteProc;
    return rec->fData;
}

<<<<<<< HEAD
void* SkTLS::Find(CreateProc createProc)
{
    if (nullptr == createProc) {
        return nullptr;
=======
void* SkTLS::Find(CreateProc createProc) {
    if (NULL == createProc) {
        return NULL;
>>>>>>> miniblink49
    }

    void* ptr = SkTLS::PlatformGetSpecific(false);

    if (ptr) {
        const SkTLSRec* rec = (const SkTLSRec*)ptr;
        do {
            if (rec->fCreateProc == createProc) {
                return rec->fData;
            }
<<<<<<< HEAD
        } while ((rec = rec->fNext) != nullptr);
    }
    return nullptr;
}

void SkTLS::Delete(CreateProc createProc)
{
    if (nullptr == createProc) {
=======
        } while ((rec = rec->fNext) != NULL);
    }
    return NULL;
}

void SkTLS::Delete(CreateProc createProc) {
    if (NULL == createProc) {
>>>>>>> miniblink49
        return;
    }

    void* ptr = SkTLS::PlatformGetSpecific(false);

    SkTLSRec* curr = (SkTLSRec*)ptr;
<<<<<<< HEAD
    SkTLSRec* prev = nullptr;
=======
    SkTLSRec* prev = NULL;
>>>>>>> miniblink49
    while (curr) {
        SkTLSRec* next = curr->fNext;
        if (curr->fCreateProc == createProc) {
            if (prev) {
                prev->fNext = next;
            } else {
                // we have a new head of our chain
                SkTLS::PlatformSetSpecific(next);
            }
<<<<<<< HEAD
            delete curr;
=======
            SkDELETE(curr);
>>>>>>> miniblink49
            break;
        }
        prev = curr;
        curr = next;
    }
}
