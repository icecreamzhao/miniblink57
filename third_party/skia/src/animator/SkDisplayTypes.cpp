
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkDisplayTypes.h"
#include "SkAnimateBase.h"

bool SkDisplayDepend::canContainDependents() const
{
    return true;
}

void SkDisplayDepend::dirty()
{
    SkDisplayable** last = fDependents.end();
    for (SkDisplayable** depPtr = fDependents.begin(); depPtr < last; depPtr++) {
        SkAnimateBase* animate = (SkAnimateBase*)*depPtr;
=======

#include "SkDisplayTypes.h"
#include "SkAnimateBase.h"

bool SkDisplayDepend::canContainDependents() const {
    return true;
}

void SkDisplayDepend::dirty() {
    SkDisplayable** last = fDependents.end();
    for (SkDisplayable** depPtr = fDependents.begin(); depPtr < last; depPtr++) {
        SkAnimateBase* animate = (SkAnimateBase* ) *depPtr;
>>>>>>> miniblink49
        animate->setChanged(true);
    }
}

// Boolean
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkDisplayBoolean::fInfo[] = {
    SK_MEMBER(value, Boolean)
};

#endif

DEFINE_GET_MEMBER(SkDisplayBoolean);

<<<<<<< HEAD
SkDisplayBoolean::SkDisplayBoolean()
    : value(false)
{
}

#ifdef SK_DUMP_ENABLED
void SkDisplayBoolean::dump(SkAnimateMaker* maker)
{
=======
SkDisplayBoolean::SkDisplayBoolean() : value(false) {
}

#ifdef SK_DUMP_ENABLED
void SkDisplayBoolean::dump(SkAnimateMaker* maker){
>>>>>>> miniblink49
    dumpBase(maker);
    SkDebugf("value=\"%s\" />\n", value ? "true" : "false");
}
#endif

// int32_t
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkDisplayInt::fInfo[] = {
    SK_MEMBER(value, Int)
};

#endif

DEFINE_GET_MEMBER(SkDisplayInt);

<<<<<<< HEAD
SkDisplayInt::SkDisplayInt()
    : value(0)
{
}

#ifdef SK_DUMP_ENABLED
void SkDisplayInt::dump(SkAnimateMaker* maker)
{
=======
SkDisplayInt::SkDisplayInt() : value(0) {
}

#ifdef SK_DUMP_ENABLED
void SkDisplayInt::dump(SkAnimateMaker* maker){
>>>>>>> miniblink49
    dumpBase(maker);
    SkDebugf("value=\"%d\" />\n", value);
}
#endif

// SkScalar
#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkDisplayFloat::fInfo[] = {
    SK_MEMBER(value, Float)
};

#endif

DEFINE_GET_MEMBER(SkDisplayFloat);

<<<<<<< HEAD
SkDisplayFloat::SkDisplayFloat()
    : value(0)
{
}

#ifdef SK_DUMP_ENABLED
void SkDisplayFloat::dump(SkAnimateMaker* maker)
{
=======
SkDisplayFloat::SkDisplayFloat() : value(0) {
}

#ifdef SK_DUMP_ENABLED
void SkDisplayFloat::dump(SkAnimateMaker* maker) {
>>>>>>> miniblink49
    dumpBase(maker);
    SkDebugf("value=\"%g\" />\n", SkScalarToFloat(value));
}
#endif

// SkString
enum SkDisplayString_Functions {
    SK_FUNCTION(slice)
};

enum SkDisplayString_Properties {
    SK_PROPERTY(length)
};

const SkFunctionParamType SkDisplayString::fFunctionParameters[] = {
<<<<<<< HEAD
    (SkFunctionParamType)SkType_Int, // slice
    (SkFunctionParamType)SkType_Int,
    (SkFunctionParamType)0
=======
    (SkFunctionParamType) SkType_Int,   // slice
    (SkFunctionParamType) SkType_Int,
    (SkFunctionParamType) 0
>>>>>>> miniblink49
};

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkDisplayString::fInfo[] = {
    SK_MEMBER_PROPERTY(length, Int),
    SK_MEMBER_FUNCTION(slice, String),
    SK_MEMBER(value, String)
};

#endif

DEFINE_GET_MEMBER(SkDisplayString);

<<<<<<< HEAD
SkDisplayString::SkDisplayString()
{
}

SkDisplayString::SkDisplayString(SkString& copyFrom)
    : value(copyFrom)
{
}

void SkDisplayString::executeFunction(SkDisplayable* target, int index,
    SkTDArray<SkScriptValue>& parameters, SkDisplayTypes type,
    SkScriptValue* scriptValue)
{
    if (scriptValue == nullptr)
        return;
    SkASSERT(target == this);
    switch (index) {
    case SK_FUNCTION(slice):
        scriptValue->fType = SkType_String;
        SkASSERT(parameters[0].fType == SkType_Int);
        int start = parameters[0].fOperand.fS32;
        if (start < 0)
            start = (int)(value.size() - start);
        int end = (int)value.size();
        if (parameters.count() > 1) {
            SkASSERT(parameters[1].fType == SkType_Int);
            end = parameters[1].fOperand.fS32;
        }
        //if (end >= 0 && end < (int) value.size())
        if (end >= 0 && end <= (int)value.size())
            scriptValue->fOperand.fString = new SkString(&value.c_str()[start], end - start);
        else
            scriptValue->fOperand.fString = new SkString(value);
=======
SkDisplayString::SkDisplayString() {
}

SkDisplayString::SkDisplayString(SkString& copyFrom) : value(copyFrom) {
}

void SkDisplayString::executeFunction(SkDisplayable* target, int index,
        SkTDArray<SkScriptValue>& parameters, SkDisplayTypes type,
        SkScriptValue* scriptValue) {
    if (scriptValue == NULL)
        return;
    SkASSERT(target == this);
    switch (index) {
        case SK_FUNCTION(slice):
            scriptValue->fType = SkType_String;
            SkASSERT(parameters[0].fType == SkType_Int);
            int start =  parameters[0].fOperand.fS32;
            if (start < 0)
                start = (int) (value.size() - start);
            int end = (int) value.size();
            if (parameters.count() > 1) {
                SkASSERT(parameters[1].fType == SkType_Int);
                end = parameters[1].fOperand.fS32;
            }
            //if (end >= 0 && end < (int) value.size())
            if (end >= 0 && end <= (int) value.size())
                scriptValue->fOperand.fString = new SkString(&value.c_str()[start], end - start);
            else
                scriptValue->fOperand.fString = new SkString(value);
>>>>>>> miniblink49
        break;
    }
}

<<<<<<< HEAD
const SkFunctionParamType* SkDisplayString::getFunctionsParameters()
{
    return fFunctionParameters;
}

bool SkDisplayString::getProperty(int index, SkScriptValue* scriptValue) const
{
    switch (index) {
    case SK_PROPERTY(length):
        scriptValue->fType = SkType_Int;
        scriptValue->fOperand.fS32 = (int32_t)value.size();
        break;
    default:
        SkASSERT(0);
        return false;
=======
const SkFunctionParamType* SkDisplayString::getFunctionsParameters() {
    return fFunctionParameters;
}

bool SkDisplayString::getProperty(int index, SkScriptValue* scriptValue) const {
    switch (index) {
        case SK_PROPERTY(length):
            scriptValue->fType = SkType_Int;
            scriptValue->fOperand.fS32 = (int32_t) value.size();
            break;
        default:
            SkASSERT(0);
            return false;
>>>>>>> miniblink49
    }
    return true;
}

<<<<<<< HEAD
// SkArray
#if 0 // !!! reason enough to qualify enum with class name or move typedArray into its own file
=======

// SkArray
#if 0   // !!! reason enough to qualify enum with class name or move typedArray into its own file
>>>>>>> miniblink49
enum SkDisplayArray_Properties {
    SK_PROPERTY(length)
};
#endif

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkDisplayArray::fInfo[] = {
    SK_MEMBER_PROPERTY(length, Int),
    SK_MEMBER_ARRAY(values, Unknown)
};

#endif

DEFINE_GET_MEMBER(SkDisplayArray);

<<<<<<< HEAD
SkDisplayArray::SkDisplayArray()
{
}

SkDisplayArray::SkDisplayArray(SkTypedArray& copyFrom)
    : values(copyFrom)
{
}

SkDisplayArray::~SkDisplayArray()
{
=======
SkDisplayArray::SkDisplayArray() {
}

SkDisplayArray::SkDisplayArray(SkTypedArray& copyFrom) : values(copyFrom) {

}

SkDisplayArray::~SkDisplayArray() {
>>>>>>> miniblink49
    if (values.getType() == SkType_String) {
        for (int index = 0; index < values.count(); index++)
            delete values[index].fString;
        return;
    }
    if (values.getType() == SkType_Array) {
        for (int index = 0; index < values.count(); index++)
            delete values[index].fArray;
    }
}

<<<<<<< HEAD
bool SkDisplayArray::getProperty(int index, SkScriptValue* value) const
{
    switch (index) {
    case SK_PROPERTY(length):
        value->fType = SkType_Int;
        value->fOperand.fS32 = values.count();
        break;
    default:
        SkASSERT(0);
        return false;
=======
bool SkDisplayArray::getProperty(int index, SkScriptValue* value) const {
    switch (index) {
        case SK_PROPERTY(length):
            value->fType = SkType_Int;
            value->fOperand.fS32 = values.count();
            break;
        default:
            SkASSERT(0);
            return false;
>>>>>>> miniblink49
    }
    return true;
}
