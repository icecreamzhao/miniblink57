
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "SkTypes.h"
#if defined SK_BUILD_CONDENSED
#include "SkMemberInfo.h"
#if SK_USE_CONDENSED_INFO == 1
#error "SK_USE_CONDENSED_INFO must be zero to build condensed info"
#endif
#if !defined SK_BUILD_FOR_WIN32
#error "SK_BUILD_FOR_WIN32 must be defined to build condensed info"
#endif
#include "SkDisplayType.h"
#include "SkIntArray.h"
#include <stdio.h>

SkTDMemberInfoArray gInfos;
SkTDIntArray gInfosCounts;
SkTDDisplayTypesArray gInfosTypeIDs;
SkTDMemberInfoArray gUnknowns;
SkTDIntArray gUnknownsCounts;

<<<<<<< HEAD
static void AddInfo(SkDisplayTypes type, const SkMemberInfo* info, int infoCount)
{
    SkASSERT(gInfos[type] == nullptr);
=======
static void AddInfo(SkDisplayTypes type, const SkMemberInfo* info, int infoCount) {
    SkASSERT(gInfos[type] == NULL);
>>>>>>> miniblink49
    gInfos[type] = info;
    gInfosCounts[type] = infoCount;
    *gInfosTypeIDs.append() = type;
    size_t allStrs = 0;
    for (int inner = 0; inner < infoCount; inner++) {
        SkASSERT(info[inner].fCount < 256);
<<<<<<< HEAD
        int offset = (int)info[inner].fOffset;
        SkASSERT(offset < 128 && offset > -129);
        SkASSERT(allStrs < 256);
        if (info[inner].fType == SkType_BaseClassInfo) {
            const SkMemberInfo* innerInfo = (const SkMemberInfo*)info[inner].fName;
=======
        int offset = (int) info[inner].fOffset;
        SkASSERT(offset < 128 && offset > -129);
        SkASSERT(allStrs < 256);
        if (info[inner].fType == SkType_BaseClassInfo) {
            const SkMemberInfo* innerInfo = (const SkMemberInfo*) info[inner].fName;
>>>>>>> miniblink49
            if (gUnknowns.find(innerInfo) == -1) {
                *gUnknowns.append() = innerInfo;
                *gUnknownsCounts.append() = info[inner].fCount;
            }
        }
        if (info[inner].fType != SkType_BaseClassInfo && info[inner].fName)
            allStrs += strlen(info[inner].fName);
        allStrs += 1;
        SkASSERT(info[inner].fType < 256);
    }
}

static void WriteInfo(FILE* condensed, const SkMemberInfo* info, int infoCount,
<<<<<<< HEAD
    const char* typeName, bool draw, bool display)
{
=======
            const char* typeName, bool draw, bool display) {
>>>>>>> miniblink49
    fprintf(condensed, "static const char g%sStrings[] = \n", typeName);
    int inner;
    // write strings
    for (inner = 0; inner < infoCount; inner++) {
<<<<<<< HEAD
        const char* name = (info[inner].fType != SkType_BaseClassInfo && info[inner].fName) ? info[inner].fName : "";
=======
        const char* name = (info[inner].fType != SkType_BaseClassInfo && info[inner].fName) ?
            info[inner].fName : "";
>>>>>>> miniblink49
        const char* zero = inner < infoCount - 1 ? "\\0" : "";
        fprintf(condensed, "\t\"%s%s\"\n", name, zero);
    }
    fprintf(condensed, ";\n\nstatic const SkMemberInfo g%s", draw ? "Draw" : display ? "Display" : "");
    fprintf(condensed, "%sInfo[] = {", typeName);
    size_t nameOffset = 0;
    // write info tables
    for (inner = 0; inner < infoCount; inner++) {
        size_t offset = info[inner].fOffset;
        if (info[inner].fType == SkType_BaseClassInfo) {
<<<<<<< HEAD
            offset = (size_t)gInfos.find((const SkMemberInfo*)info[inner].fName);
            SkASSERT((int)offset >= 0);
            offset = gInfosTypeIDs.find((SkDisplayTypes)offset);
            SkASSERT((int)offset >= 0);
=======
            offset = (size_t) gInfos.find((const SkMemberInfo* ) info[inner].fName);
            SkASSERT((int) offset >= 0);
            offset = gInfosTypeIDs.find((SkDisplayTypes) offset);
            SkASSERT((int) offset >= 0);
>>>>>>> miniblink49
        }
        fprintf(condensed, "\n\t{%d, %d, %d, %d}", nameOffset, offset,
            info[inner].fType, info[inner].fCount);
        if (inner < infoCount - 1)
            putc(',', condensed);
        if (info[inner].fType != SkType_BaseClassInfo && info[inner].fName)
            nameOffset += strlen(info[inner].fName);
        nameOffset += 1;
    }
    fprintf(condensed, "\n};\n\n");
}

<<<<<<< HEAD
static void Get3DName(char* scratch, const char* name)
{
    if (strncmp("skia3d:", name, sizeof("skia3d:") - 1) == 0) {
        strcpy(scratch, "3D_");
        scratch[3] = name[7] & ~0x20;
=======
static void Get3DName(char* scratch, const char* name) {
    if (strncmp("skia3d:", name, sizeof("skia3d:") - 1) == 0) {
        strcpy(scratch, "3D_");
        scratch[3]= name[7] & ~0x20;
>>>>>>> miniblink49
        strcpy(&scratch[4], &name[8]);
    } else {
        scratch[0] = name[0] & ~0x20;
        strcpy(&scratch[1], &name[1]);
    }
}

<<<<<<< HEAD
int type_compare(const void* a, const void* b)
{
    SkDisplayTypes first = *(SkDisplayTypes*)a;
    SkDisplayTypes second = *(SkDisplayTypes*)b;
    return first < second ? -1 : first == second ? 0 : 1;
}

void SkDisplayType::BuildCondensedInfo(SkAnimateMaker* maker)
{
=======
int type_compare(const void* a, const void* b) {
    SkDisplayTypes first = *(SkDisplayTypes*) a;
    SkDisplayTypes second = *(SkDisplayTypes*) b;
    return first < second ? -1 : first == second ? 0 : 1;
}

void SkDisplayType::BuildCondensedInfo(SkAnimateMaker* maker) {
>>>>>>> miniblink49
    gInfos.setCount(kNumberOfTypes);
    memset(gInfos.begin(), 0, sizeof(gInfos[0]) * kNumberOfTypes);
    gInfosCounts.setCount(kNumberOfTypes);
    memset(gInfosCounts.begin(), -1, sizeof(gInfosCounts[0]) * kNumberOfTypes);
    // check to see if it is condensable
    int index, infoCount;
    for (index = 0; index < kTypeNamesSize; index++) {
        const SkMemberInfo* info = GetMembers(maker, gTypeNames[index].fType, &infoCount);
<<<<<<< HEAD
        if (info == nullptr)
            continue;
        AddInfo(gTypeNames[index].fType, info, infoCount);
    }
    const SkMemberInfo* extraInfo = SkDisplayType::GetMembers(maker, SkType_3D_Point, &infoCount);
    AddInfo(SkType_Point, extraInfo, infoCount);
    AddInfo(SkType_3D_Point, extraInfo, infoCount);
    //  int baseInfos = gInfos.count();
=======
        if (info == NULL)
            continue;
        AddInfo(gTypeNames[index].fType, info, infoCount);
    }
    const SkMemberInfo* extraInfo =
        SkDisplayType::GetMembers(maker, SkType_3D_Point, &infoCount);
    AddInfo(SkType_Point, extraInfo, infoCount);
    AddInfo(SkType_3D_Point, extraInfo, infoCount);
//  int baseInfos = gInfos.count();
>>>>>>> miniblink49
    do {
        SkTDMemberInfoArray oldRefs = gUnknowns;
        SkTDIntArray oldRefCounts = gUnknownsCounts;
        gUnknowns.reset();
        gUnknownsCounts.reset();
        for (index = 0; index < oldRefs.count(); index++) {
            const SkMemberInfo* info = oldRefs[index];
            if (gInfos.find(info) == -1) {
                int typeIndex = 0;
                for (; typeIndex < kNumberOfTypes; typeIndex++) {
                    const SkMemberInfo* temp = SkDisplayType::GetMembers(
<<<<<<< HEAD
                        maker, (SkDisplayTypes)typeIndex, nullptr);
=======
                        maker, (SkDisplayTypes) typeIndex, NULL);
>>>>>>> miniblink49
                    if (temp == info)
                        break;
                }
                SkASSERT(typeIndex < kNumberOfTypes);
<<<<<<< HEAD
                AddInfo((SkDisplayTypes)typeIndex, info, oldRefCounts[index]);
=======
                AddInfo((SkDisplayTypes) typeIndex, info, oldRefCounts[index]);
>>>>>>> miniblink49
            }
        }
    } while (gUnknowns.count() > 0);
    qsort(gInfosTypeIDs.begin(), gInfosTypeIDs.count(), sizeof(gInfosTypeIDs[0]), &type_compare);
#ifdef SK_DEBUG
    FILE* condensed = fopen("../../src/animator/SkCondensedDebug.cpp", "w+");
    fprintf(condensed, "#include \"SkTypes.h\"\n");
    fprintf(condensed, "#ifdef SK_DEBUG\n");
#else
    FILE* condensed = fopen("../../src/animator/SkCondensedRelease.cpp", "w+");
    fprintf(condensed, "#include \"SkTypes.h\"\n");
    fprintf(condensed, "#ifdef SK_RELEASE\n");
#endif
    // write header
    fprintf(condensed, "// This file was automatically generated.\n");
    fprintf(condensed, "// To change it, edit the file with the matching debug info.\n");
    fprintf(condensed, "// Then execute SkDisplayType::BuildCondensedInfo() to "
<<<<<<< HEAD
                       "regenerate this file.\n\n");
=======
        "regenerate this file.\n\n");
>>>>>>> miniblink49
    // write name of memberInfo
    int typeNameIndex = 0;
    int unknown = 1;
    for (index = 0; index < gInfos.count(); index++) {
        const SkMemberInfo* info = gInfos[index];
<<<<<<< HEAD
        if (info == nullptr)
=======
        if (info == NULL)
>>>>>>> miniblink49
            continue;
        char scratch[64];
        bool drawPrefix, displayPrefix;
        while (gTypeNames[typeNameIndex].fType < index)
            typeNameIndex++;
        if (gTypeNames[typeNameIndex].fType == index) {
            Get3DName(scratch, gTypeNames[typeNameIndex].fName);
            drawPrefix = gTypeNames[typeNameIndex].fDrawPrefix;
            displayPrefix = gTypeNames[typeNameIndex].fDisplayPrefix;
        } else {
            sprintf(scratch, "Unknown%d", unknown++);
            drawPrefix = displayPrefix = false;
        }
        WriteInfo(condensed, info, gInfosCounts[index], scratch, drawPrefix, displayPrefix);
    }
    // write array of table pointers
<<<<<<< HEAD
    //  start here;
=======
//  start here;
>>>>>>> miniblink49
    fprintf(condensed, "static const SkMemberInfo* const gInfoTables[] = {");
    typeNameIndex = 0;
    unknown = 1;
    for (index = 0; index < gInfos.count(); index++) {
        const SkMemberInfo* info = gInfos[index];
<<<<<<< HEAD
        if (info == nullptr)
=======
        if (info == NULL)
>>>>>>> miniblink49
            continue;
        char scratch[64];
        bool drawPrefix, displayPrefix;
        while (gTypeNames[typeNameIndex].fType < index)
            typeNameIndex++;
        if (gTypeNames[typeNameIndex].fType == index) {
            Get3DName(scratch, gTypeNames[typeNameIndex].fName);
            drawPrefix = gTypeNames[typeNameIndex].fDrawPrefix;
            displayPrefix = gTypeNames[typeNameIndex].fDisplayPrefix;
        } else {
            sprintf(scratch, "Unknown%d", unknown++);
            drawPrefix = displayPrefix = false;
        }
        fprintf(condensed, "\n\tg");
        if (drawPrefix)
            fprintf(condensed, "Draw");
        if (displayPrefix)
            fprintf(condensed, "Display");
        fprintf(condensed, "%sInfo", scratch);
        if (index < gInfos.count() - 1)
<<<<<<< HEAD
            putc(',', condensed);
=======
                putc(',', condensed);
>>>>>>> miniblink49
    }
    fprintf(condensed, "\n};\n\n");
    // write the array of number of entries in the info table
    fprintf(condensed, "static const unsigned char gInfoCounts[] = {\n\t");
    int written = 0;
    for (index = 0; index < gInfosCounts.count(); index++) {
        int count = gInfosCounts[index];
        if (count < 0)
            continue;
        if (written > 0)
            putc(',', condensed);
        if (written % 20 == 19)
            fprintf(condensed, "\n\t");
<<<<<<< HEAD
        fprintf(condensed, "%d", count);
=======
        fprintf(condensed, "%d",count);
>>>>>>> miniblink49
        written++;
    }
    fprintf(condensed, "\n};\n\n");
    // write array of type ids table entries correspond to
    fprintf(condensed, "static const unsigned char gTypeIDs[] = {\n\t");
    int typeIDCount = 0;
    typeNameIndex = 0;
    unknown = 1;
    for (index = 0; index < gInfosCounts.count(); index++) {
        const SkMemberInfo* info = gInfos[index];
<<<<<<< HEAD
        if (info == nullptr)
=======
        if (info == NULL)
>>>>>>> miniblink49
            continue;
        typeIDCount++;
        char scratch[64];
        while (gTypeNames[typeNameIndex].fType < index)
            typeNameIndex++;
        if (gTypeNames[typeNameIndex].fType == index) {
            Get3DName(scratch, gTypeNames[typeNameIndex].fName);
        } else
            sprintf(scratch, "Unknown%d", unknown++);
        fprintf(condensed, "%d%c // %s\n\t", index,
            index < gInfosCounts.count() ? ',' : ' ', scratch);
    }
    fprintf(condensed, "\n};\n\n");
    fprintf(condensed, "static const int kTypeIDs = %d;\n\n", typeIDCount);
    // write the array of string pointers
    fprintf(condensed, "static const char* const gInfoNames[] = {");
    typeNameIndex = 0;
    unknown = 1;
    written = 0;
    for (index = 0; index < gInfosCounts.count(); index++) {
        const SkMemberInfo* info = gInfos[index];
<<<<<<< HEAD
        if (info == nullptr)
            continue;
        if (written > 0)
            putc(',', condensed);
=======
        if (info == NULL)
            continue;
        if (written > 0)
                putc(',', condensed);
>>>>>>> miniblink49
        written++;
        fprintf(condensed, "\n\tg");
        char scratch[64];
        while (gTypeNames[typeNameIndex].fType < index)
            typeNameIndex++;
        if (gTypeNames[typeNameIndex].fType == index) {
            Get3DName(scratch, gTypeNames[typeNameIndex].fName);
        } else
            sprintf(scratch, "Unknown%d", unknown++);
        fprintf(condensed, "%sStrings", scratch);
    }
    fprintf(condensed, "\n};\n\n");
    fprintf(condensed, "#endif\n");
    fclose(condensed);
    gInfos.reset();
    gInfosCounts.reset();
    gInfosTypeIDs.reset();
    gUnknowns.reset();
    gUnknownsCounts.reset();
}

#elif defined SK_DEBUG
#include "SkDisplayType.h"
<<<<<<< HEAD
void SkDisplayType::BuildCondensedInfo(SkAnimateMaker*) { }
=======
void SkDisplayType::BuildCondensedInfo(SkAnimateMaker* ) {}
>>>>>>> miniblink49
#endif
