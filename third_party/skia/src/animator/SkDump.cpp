
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "SkDump.h"

#ifdef SK_DUMP_ENABLED

#include "SkAnimateMaker.h"
#include "SkAnimatorScript.h"
#include "SkDisplayEvents.h"
#include "SkDisplayList.h"
#include "SkString.h"

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkDump::fInfo[] = {
    SK_MEMBER(displayList, Boolean),
    SK_MEMBER(eventList, Boolean),
    SK_MEMBER(events, Boolean),
    SK_MEMBER(groups, Boolean),
    SK_MEMBER(name, String),
    SK_MEMBER(posts, Boolean),
    SK_MEMBER(script, String)
};

#endif

DEFINE_GET_MEMBER(SkDump);

<<<<<<< HEAD
SkDump::SkDump()
    : displayList(-1)
    , eventList(-1)
    , events(-1)
    , groups(-1)
    , posts(-1)
{
}

bool SkDump::enable(SkAnimateMaker& maker)
{
=======
SkDump::SkDump() : displayList(-1), eventList(-1), events(-1), groups(-1), posts(-1) {
}

bool SkDump::enable(SkAnimateMaker& maker ) {
>>>>>>> miniblink49
    if (script.size() > 0)
        return evaluate(maker);
    bool hasAttr = false;
    if (events > 0)
        hasAttr |= maker.fDumpEvents = true;
    if (posts > 0)
        hasAttr |= maker.fDumpPosts = true;
    if (groups > 0)
        hasAttr |= maker.fDumpGConditions = true;
    if ((hasAttr |= (eventList > 0)) == true)
        maker.fEvents.dump(maker);
    if ((hasAttr |= (name.size() > 0)) == true)
        maker.dump(name.c_str());
    if (displayList > 0 || (displayList != 0 && hasAttr == false))
        maker.fDisplayList.dump(&maker);
    return true;
}

<<<<<<< HEAD
bool SkDump::evaluate(SkAnimateMaker& maker)
{
    SkAnimatorScript scriptEngine(maker, nullptr, SkType_Int);
=======
bool SkDump::evaluate(SkAnimateMaker &maker) {
    SkAnimatorScript scriptEngine(maker, NULL, SkType_Int);
>>>>>>> miniblink49
    SkScriptValue value;
    const char* cScript = script.c_str();
    bool success = scriptEngine.evaluateScript(&cScript, &value);
    SkDebugf("%*s<dump script=\"%s\" answer=\" ", SkDisplayList::fIndent, "", script.c_str());
    if (success == false) {
        SkDebugf("INVALID\" />\n");
        return false;
    }
    switch (value.fType) {
<<<<<<< HEAD
    case SkType_Float:
        SkDebugf("%g\" />\n", SkScalarToFloat(value.fOperand.fScalar));
        break;
    case SkType_Int:
        SkDebugf("%d\" />\n", value.fOperand.fS32);
        break;
    case SkType_String:
        SkDebugf("%s\" />\n", value.fOperand.fString->c_str());
        break;
    default:
        return false;
=======
        case SkType_Float:
            SkDebugf("%g\" />\n", SkScalarToFloat(value.fOperand.fScalar));
            break;
        case SkType_Int:
            SkDebugf("%d\" />\n", value.fOperand.fS32);
            break;
        case SkType_String:
            SkDebugf("%s\" />\n", value.fOperand.fString->c_str());
            break;
        default:
            return false;
>>>>>>> miniblink49
    }
    return true;
}

<<<<<<< HEAD
bool SkDump::hasEnable() const
{
    return true;
}

void SkDump::GetEnumString(SkDisplayTypes type, int index, SkString* result)
{
    int badEnum = index;
    const SkDisplayEnumMap& map = SkAnimatorScript::GetEnumValues(type);
    const char* str = map.fValues;
    while (--index >= 0) {
        str = strchr(str, '|');
        if (str == nullptr) {
=======
bool SkDump::hasEnable() const {
    return true;
}

void SkDump::GetEnumString(SkDisplayTypes type, int index, SkString* result) {
    int badEnum = index;
    const SkDisplayEnumMap& map = SkAnimatorScript::GetEnumValues(type);
    const char* str  = map.fValues;
    while (--index >= 0) {
        str = strchr(str, '|');
        if (str == NULL) {
>>>>>>> miniblink49
            result->reset();
            result->appendS32(badEnum);
            return;
        }
        str += 1;
    }
    const char* end = strchr(str, '|');
<<<<<<< HEAD
    if (end == nullptr)
=======
    if (end == NULL)
>>>>>>> miniblink49
        end = str + strlen(str);
    result->set(str, end - str);
}

#else

// in the release version, <dump> is allowed, and its attributes are defined, but
// are not stored and have no effect

#if SK_USE_CONDENSED_INFO == 0

enum SkDump_Properties {
    SK_PROPERTY(displayList),
    SK_PROPERTY(eventList),
    SK_PROPERTY(events),
    SK_PROPERTY(groups),
    SK_PROPERTY(name),
    SK_PROPERTY(posts),
    SK_PROPERTY(script)
};

const SkMemberInfo SkDump::fInfo[] = {
    SK_MEMBER_PROPERTY(displayList, Boolean),
    SK_MEMBER_PROPERTY(eventList, Boolean),
    SK_MEMBER_PROPERTY(events, Boolean),
    SK_MEMBER_PROPERTY(groups, Boolean),
    SK_MEMBER_PROPERTY(name, String),
    SK_MEMBER_PROPERTY(posts, Boolean),
    SK_MEMBER_PROPERTY(script, String)
};

#endif

DEFINE_GET_MEMBER(SkDump);

<<<<<<< HEAD
bool SkDump::enable(SkAnimateMaker&)
{
    return true;
}

bool SkDump::hasEnable() const
{
    return true;
}

bool SkDump::setProperty(int index, SkScriptValue&)
{
=======
bool SkDump::enable(SkAnimateMaker&) {
    return true;
}

bool SkDump::hasEnable() const {
    return true;
}

bool SkDump::setProperty(int index, SkScriptValue&) {
>>>>>>> miniblink49
    return index <= SK_PROPERTY(posts);
}

#endif
