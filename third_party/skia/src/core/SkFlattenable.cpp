/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkFlattenable.h"
#include "SkPtrRecorder.h"
#include "SkReadBuffer.h"

<<<<<<< HEAD
SkNamedFactorySet::SkNamedFactorySet()
    : fNextAddedFactory(0)
{
}

uint32_t SkNamedFactorySet::find(SkFlattenable::Factory factory)
{
=======
SkNamedFactorySet::SkNamedFactorySet() : fNextAddedFactory(0) {}

uint32_t SkNamedFactorySet::find(SkFlattenable::Factory factory) {
>>>>>>> miniblink49
    uint32_t index = fFactorySet.find(factory);
    if (index > 0) {
        return index;
    }
    const char* name = SkFlattenable::FactoryToName(factory);
<<<<<<< HEAD
    if (nullptr == name) {
=======
    if (NULL == name) {
>>>>>>> miniblink49
        return 0;
    }
    *fNames.append() = name;
    return fFactorySet.add(factory);
}

<<<<<<< HEAD
const char* SkNamedFactorySet::getNextAddedFactoryName()
{
    if (fNextAddedFactory < fNames.count()) {
        return fNames[fNextAddedFactory++];
    }
    return nullptr;
=======
const char* SkNamedFactorySet::getNextAddedFactoryName() {
    if (fNextAddedFactory < fNames.count()) {
        return fNames[fNextAddedFactory++];
    }
    return NULL;
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkRefCntSet::~SkRefCntSet()
{
=======
SkRefCntSet::~SkRefCntSet() {
>>>>>>> miniblink49
    // call this now, while our decPtr() is sill in scope
    this->reset();
}

<<<<<<< HEAD
void SkRefCntSet::incPtr(void* ptr)
{
    ((SkRefCnt*)ptr)->ref();
}

void SkRefCntSet::decPtr(void* ptr)
{
=======
void SkRefCntSet::incPtr(void* ptr) {
    ((SkRefCnt*)ptr)->ref();
}

void SkRefCntSet::decPtr(void* ptr) {
>>>>>>> miniblink49
    ((SkRefCnt*)ptr)->unref();
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
#define MAX_ENTRY_COUNT 1024

struct Entry {
    const char* fName;
    SkFlattenable::Factory fFactory;
    SkFlattenable::Type fType;
};

static int gCount = 0;
static Entry gEntries[MAX_ENTRY_COUNT];

void SkFlattenable::Register(const char name[], Factory factory, SkFlattenable::Type type)
{
    SkASSERT(name);
    SkASSERT(factory);
=======
#define MAX_ENTRY_COUNT  1024

struct Entry {
    const char*             fName;
    SkFlattenable::Factory  fFactory;
    SkFlattenable::Type     fType;
};

static int gCount;
static Entry gEntries[MAX_ENTRY_COUNT];

void SkFlattenable::Register(const char name[], Factory factory, SkFlattenable::Type type) {
    SkASSERT(name);
    SkASSERT(factory);

    static bool gOnce = false;
    if (!gOnce) {
        gCount = 0;
        gOnce = true;
    }

>>>>>>> miniblink49
    SkASSERT(gCount < MAX_ENTRY_COUNT);

    gEntries[gCount].fName = name;
    gEntries[gCount].fFactory = factory;
    gEntries[gCount].fType = type;
    gCount += 1;
}

#ifdef SK_DEBUG
<<<<<<< HEAD
static void report_no_entries(const char* functionName)
{
    if (!gCount) {
        SkDebugf("%s has no registered name/factory/type entries."
                 " Call SkFlattenable::InitializeFlattenablesIfNeeded() before using gEntries",
            functionName);
=======
static void report_no_entries(const char* functionName) {
    if (!gCount) {
        SkDebugf("%s has no registered name/factory/type entries."
                 " Call SkFlattenable::InitializeFlattenablesIfNeeded() before using gEntries",
                 functionName);
>>>>>>> miniblink49
    }
}
#endif

<<<<<<< HEAD
SkFlattenable::Factory SkFlattenable::NameToFactory(const char name[])
{
=======
SkFlattenable::Factory SkFlattenable::NameToFactory(const char name[]) {
>>>>>>> miniblink49
    InitializeFlattenablesIfNeeded();
#ifdef SK_DEBUG
    report_no_entries(__FUNCTION__);
#endif
    const Entry* entries = gEntries;
    for (int i = gCount - 1; i >= 0; --i) {
        if (strcmp(entries[i].fName, name) == 0) {
            return entries[i].fFactory;
        }
    }
<<<<<<< HEAD
    return nullptr;
}

bool SkFlattenable::NameToType(const char name[], SkFlattenable::Type* type)
{
=======
    return NULL;
}

bool SkFlattenable::NameToType(const char name[], SkFlattenable::Type* type) {
>>>>>>> miniblink49
    SkASSERT(type);
    InitializeFlattenablesIfNeeded();
#ifdef SK_DEBUG
    report_no_entries(__FUNCTION__);
#endif
    const Entry* entries = gEntries;
    for (int i = gCount - 1; i >= 0; --i) {
        if (strcmp(entries[i].fName, name) == 0) {
            *type = entries[i].fType;
            return true;
        }
    }
    return false;
}

<<<<<<< HEAD
const char* SkFlattenable::FactoryToName(Factory fact)
{
=======
const char* SkFlattenable::FactoryToName(Factory fact) {
>>>>>>> miniblink49
    InitializeFlattenablesIfNeeded();
#ifdef SK_DEBUG
    report_no_entries(__FUNCTION__);
#endif
    const Entry* entries = gEntries;
    for (int i = gCount - 1; i >= 0; --i) {
        if (entries[i].fFactory == fact) {
            return entries[i].fName;
        }
    }
<<<<<<< HEAD
    return nullptr;
=======
    return NULL;
>>>>>>> miniblink49
}
