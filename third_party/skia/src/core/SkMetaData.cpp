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
#include "SkMetaData.h"
#include "SkRefCnt.h"

struct PtrPair {
<<<<<<< HEAD
    void* fPtr;
    SkMetaData::PtrProc fProc;
};

void* SkMetaData::RefCntProc(void* ptr, bool doRef)
{
=======
    void*               fPtr;
    SkMetaData::PtrProc fProc;
};

void* SkMetaData::RefCntProc(void* ptr, bool doRef) {
>>>>>>> miniblink49
    SkASSERT(ptr);
    SkRefCnt* refcnt = reinterpret_cast<SkRefCnt*>(ptr);

    if (doRef) {
        refcnt->ref();
    } else {
        refcnt->unref();
    }
    return ptr;
}

<<<<<<< HEAD
SkMetaData::SkMetaData()
    : fRec(nullptr)
{
}

SkMetaData::SkMetaData(const SkMetaData& src)
    : fRec(nullptr)
=======
SkMetaData::SkMetaData() : fRec(NULL)
{
}

SkMetaData::SkMetaData(const SkMetaData& src) : fRec(NULL)
>>>>>>> miniblink49
{
    *this = src;
}

SkMetaData::~SkMetaData()
{
    this->reset();
}

void SkMetaData::reset()
{
    Rec* rec = fRec;
    while (rec) {
        if (kPtr_Type == rec->fType) {
            PtrPair* pair = (PtrPair*)rec->data();
            if (pair->fProc && pair->fPtr) {
                pair->fPtr = pair->fProc(pair->fPtr, false);
            }
        }
        Rec* next = rec->fNext;
        Rec::Free(rec);
        rec = next;
    }
<<<<<<< HEAD
    fRec = nullptr;
=======
    fRec = NULL;
>>>>>>> miniblink49
}

SkMetaData& SkMetaData::operator=(const SkMetaData& src)
{
    this->reset();

    const Rec* rec = src.fRec;
<<<<<<< HEAD
    while (rec) {
=======
    while (rec)
    {
>>>>>>> miniblink49
        this->set(rec->name(), rec->data(), rec->fDataLen, (Type)rec->fType, rec->fDataCount);
        rec = rec->fNext;
    }
    return *this;
}

void SkMetaData::setS32(const char name[], int32_t value)
{
    (void)this->set(name, &value, sizeof(int32_t), kS32_Type, 1);
}

void SkMetaData::setScalar(const char name[], SkScalar value)
{
    (void)this->set(name, &value, sizeof(SkScalar), kScalar_Type, 1);
}

SkScalar* SkMetaData::setScalars(const char name[], int count, const SkScalar values[])
{
    SkASSERT(count > 0);
    if (count > 0)
        return (SkScalar*)this->set(name, values, sizeof(SkScalar), kScalar_Type, count);
<<<<<<< HEAD
    return nullptr;
=======
    return NULL;
>>>>>>> miniblink49
}

void SkMetaData::setString(const char name[], const char value[])
{
    (void)this->set(name, value, sizeof(char), kString_Type, SkToInt(strlen(value) + 1));
}

<<<<<<< HEAD
void SkMetaData::setPtr(const char name[], void* ptr, PtrProc proc)
{
=======
void SkMetaData::setPtr(const char name[], void* ptr, PtrProc proc) {
>>>>>>> miniblink49
    PtrPair pair = { ptr, proc };
    (void)this->set(name, &pair, sizeof(PtrPair), kPtr_Type, 1);
}

void SkMetaData::setBool(const char name[], bool value)
{
    (void)this->set(name, &value, sizeof(bool), kBool_Type, 1);
}

<<<<<<< HEAD
void SkMetaData::setData(const char name[], const void* data, size_t byteCount)
{
=======
void SkMetaData::setData(const char name[], const void* data, size_t byteCount) {
>>>>>>> miniblink49
    (void)this->set(name, data, sizeof(char), kData_Type, SkToInt(byteCount));
}

void* SkMetaData::set(const char name[], const void* data, size_t dataSize, Type type, int count)
{
    SkASSERT(name);
    SkASSERT(dataSize);
    SkASSERT(count > 0);

    (void)this->remove(name, type);

<<<<<<< HEAD
    size_t len = strlen(name);
    Rec* rec = Rec::Alloc(sizeof(Rec) + dataSize * count + len + 1);
=======
    size_t  len = strlen(name);
    Rec*    rec = Rec::Alloc(sizeof(Rec) + dataSize * count + len + 1);
>>>>>>> miniblink49

#ifndef SK_DEBUG
    rec->fType = SkToU8(type);
#else
    rec->fType = type;
#endif
    rec->fDataLen = SkToU8(dataSize);
    rec->fDataCount = SkToU16(count);
    if (data)
        memcpy(rec->data(), data, dataSize * count);
    memcpy(rec->name(), name, len + 1);

    if (kPtr_Type == type) {
        PtrPair* pair = (PtrPair*)rec->data();
        if (pair->fProc && pair->fPtr) {
            pair->fPtr = pair->fProc(pair->fPtr, true);
        }
    }

    rec->fNext = fRec;
    fRec = rec;
    return rec->data();
}

bool SkMetaData::findS32(const char name[], int32_t* value) const
{
    const Rec* rec = this->find(name, kS32_Type);
<<<<<<< HEAD
    if (rec) {
=======
    if (rec)
    {
>>>>>>> miniblink49
        SkASSERT(rec->fDataCount == 1);
        if (value)
            *value = *(const int32_t*)rec->data();
        return true;
    }
    return false;
}

bool SkMetaData::findScalar(const char name[], SkScalar* value) const
{
    const Rec* rec = this->find(name, kScalar_Type);
<<<<<<< HEAD
    if (rec) {
=======
    if (rec)
    {
>>>>>>> miniblink49
        SkASSERT(rec->fDataCount == 1);
        if (value)
            *value = *(const SkScalar*)rec->data();
        return true;
    }
    return false;
}

const SkScalar* SkMetaData::findScalars(const char name[], int* count, SkScalar values[]) const
{
    const Rec* rec = this->find(name, kScalar_Type);
<<<<<<< HEAD
    if (rec) {
=======
    if (rec)
    {
>>>>>>> miniblink49
        if (count)
            *count = rec->fDataCount;
        if (values)
            memcpy(values, rec->data(), rec->fDataCount * rec->fDataLen);
        return (const SkScalar*)rec->data();
    }
<<<<<<< HEAD
    return nullptr;
}

bool SkMetaData::findPtr(const char name[], void** ptr, PtrProc* proc) const
{
=======
    return NULL;
}

bool SkMetaData::findPtr(const char name[], void** ptr, PtrProc* proc) const {
>>>>>>> miniblink49
    const Rec* rec = this->find(name, kPtr_Type);
    if (rec) {
        SkASSERT(rec->fDataCount == 1);
        const PtrPair* pair = (const PtrPair*)rec->data();
        if (ptr) {
            *ptr = pair->fPtr;
        }
        if (proc) {
            *proc = pair->fProc;
        }
        return true;
    }
    return false;
}

const char* SkMetaData::findString(const char name[]) const
{
    const Rec* rec = this->find(name, kString_Type);
<<<<<<< HEAD
    SkASSERT(rec == nullptr || rec->fDataLen == sizeof(char));
    return rec ? (const char*)rec->data() : nullptr;
=======
    SkASSERT(rec == NULL || rec->fDataLen == sizeof(char));
    return rec ? (const char*)rec->data() : NULL;
>>>>>>> miniblink49
}

bool SkMetaData::findBool(const char name[], bool* value) const
{
    const Rec* rec = this->find(name, kBool_Type);
<<<<<<< HEAD
    if (rec) {
=======
    if (rec)
    {
>>>>>>> miniblink49
        SkASSERT(rec->fDataCount == 1);
        if (value)
            *value = *(const bool*)rec->data();
        return true;
    }
    return false;
}

<<<<<<< HEAD
const void* SkMetaData::findData(const char name[], size_t* length) const
{
=======
const void* SkMetaData::findData(const char name[], size_t* length) const {
>>>>>>> miniblink49
    const Rec* rec = this->find(name, kData_Type);
    if (rec) {
        SkASSERT(rec->fDataLen == sizeof(char));
        if (length) {
            *length = rec->fDataCount;
        }
        return rec->data();
    }
<<<<<<< HEAD
    return nullptr;
=======
    return NULL;
>>>>>>> miniblink49
}

const SkMetaData::Rec* SkMetaData::find(const char name[], Type type) const
{
    const Rec* rec = fRec;
<<<<<<< HEAD
    while (rec) {
=======
    while (rec)
    {
>>>>>>> miniblink49
        if (rec->fType == type && !strcmp(rec->name(), name))
            return rec;
        rec = rec->fNext;
    }
<<<<<<< HEAD
    return nullptr;
}

bool SkMetaData::remove(const char name[], Type type)
{
    Rec* rec = fRec;
    Rec* prev = nullptr;
=======
    return NULL;
}

bool SkMetaData::remove(const char name[], Type type) {
    Rec* rec = fRec;
    Rec* prev = NULL;
>>>>>>> miniblink49
    while (rec) {
        Rec* next = rec->fNext;
        if (rec->fType == type && !strcmp(rec->name(), name)) {
            if (prev) {
                prev->fNext = next;
            } else {
                fRec = next;
            }

            if (kPtr_Type == type) {
                PtrPair* pair = (PtrPair*)rec->data();
                if (pair->fProc && pair->fPtr) {
                    (void)pair->fProc(pair->fPtr, false);
                }
            }
            Rec::Free(rec);
            return true;
        }
        prev = rec;
        rec = next;
    }
    return false;
}

bool SkMetaData::removeS32(const char name[])
{
    return this->remove(name, kS32_Type);
}

bool SkMetaData::removeScalar(const char name[])
{
    return this->remove(name, kScalar_Type);
}

bool SkMetaData::removeString(const char name[])
{
    return this->remove(name, kString_Type);
}

bool SkMetaData::removePtr(const char name[])
{
    return this->remove(name, kPtr_Type);
}

bool SkMetaData::removeBool(const char name[])
{
    return this->remove(name, kBool_Type);
}

<<<<<<< HEAD
bool SkMetaData::removeData(const char name[])
{
=======
bool SkMetaData::removeData(const char name[]) {
>>>>>>> miniblink49
    return this->remove(name, kData_Type);
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkMetaData::Iter::Iter(const SkMetaData& metadata)
{
    fRec = metadata.fRec;
}

void SkMetaData::Iter::reset(const SkMetaData& metadata)
{
    fRec = metadata.fRec;
}

const char* SkMetaData::Iter::next(SkMetaData::Type* t, int* count)
{
    const char* name = nullptr;
=======
SkMetaData::Iter::Iter(const SkMetaData& metadata) {
    fRec = metadata.fRec;
}

void SkMetaData::Iter::reset(const SkMetaData& metadata) {
    fRec = metadata.fRec;
}

const char* SkMetaData::Iter::next(SkMetaData::Type* t, int* count) {
    const char* name = NULL;
>>>>>>> miniblink49

    if (fRec) {
        if (t) {
            *t = (SkMetaData::Type)fRec->fType;
        }
        if (count) {
            *count = fRec->fDataCount;
        }
        name = fRec->name();

        fRec = fRec->fNext;
    }
    return name;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkMetaData::Rec* SkMetaData::Rec::Alloc(size_t size)
{
    return (Rec*)sk_malloc_throw(size);
}

void SkMetaData::Rec::Free(Rec* rec)
{
=======
SkMetaData::Rec* SkMetaData::Rec::Alloc(size_t size) {
    return (Rec*)sk_malloc_throw(size);
}

void SkMetaData::Rec::Free(Rec* rec) {
>>>>>>> miniblink49
    sk_free(rec);
}
