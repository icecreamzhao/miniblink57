
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkData.h"
#include "SkFloatingPoint.h"
#include "SkMath.h"
#include "SkOpArray.h"
#include "SkParse.h"
#include "SkScript2.h"
#include "SkScriptCallBack.h"
#include "SkScriptRuntime.h"
#include "SkString.h"

const SkScriptEngine2::OperatorAttributes SkScriptEngine2::gOpAttributes[] = {
    { SkOperand2::kNoType, SkOperand2::kNoType, kNoBias, kResultIsNotBoolean },
    { SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar | SkOperand2::kString),
        SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar | SkOperand2::kString), kTowardsString, kResultIsNotBoolean }, // kAdd
    { SkOperand2::kS32, SkOperand2::kS32, kNoBias, kResultIsNotBoolean }, // kBitAnd
    { SkOperand2::kNoType, SkOperand2::kS32, kNoBias, kResultIsNotBoolean }, // kBitNot
    { SkOperand2::kS32, SkOperand2::kS32, kNoBias, kResultIsNotBoolean }, // kBitOr
    { SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar),
        SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar), kNoBias, kResultIsNotBoolean }, // kDivide
    { SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar | SkOperand2::kString),
        SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar | SkOperand2::kString), kTowardsNumber,
        kResultIsBoolean }, // kEqual
    { SkOperand2::kS32, SkOperand2::kNoType, kNoBias, kResultIsNotBoolean }, // kFlipOps
    { SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar | SkOperand2::kString),
        SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar | SkOperand2::kString), kTowardsNumber,
        kResultIsBoolean }, // kGreaterEqual
    { SkOperand2::kNoType, SkOperand2::kS32, kNoBias, kResultIsNotBoolean }, // kLogicalAnd    (really, ToBool)
    { SkOperand2::kNoType, SkOperand2::kS32, kNoBias, kResultIsNotBoolean }, // kLogicalNot
    { SkOperand2::kS32, SkOperand2::kS32, kNoBias, kResultIsNotBoolean }, // kLogicalOr
    { SkOperand2::kNoType, SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar), kNoBias, kResultIsNotBoolean }, // kMinus
    { SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar),
        SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar), kNoBias, kResultIsNotBoolean }, // kModulo
    { SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar),
        SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar), kNoBias, kResultIsNotBoolean }, // kMultiply
    { SkOperand2::kS32, SkOperand2::kS32, kNoBias, kResultIsNotBoolean }, // kShiftLeft
    { SkOperand2::kS32, SkOperand2::kS32, kNoBias, kResultIsNotBoolean }, // kShiftRight
    { SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar),
        SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar), kNoBias, kResultIsNotBoolean }, // kSubtract
    { SkOperand2::kS32, SkOperand2::kS32, kNoBias, kResultIsNotBoolean } // kXor
=======
#include "SkScript2.h"
#include "SkData.h"
#include "SkFloatingPoint.h"
#include "SkMath.h"
#include "SkParse.h"
#include "SkScriptCallBack.h"
#include "SkScriptRuntime.h"
#include "SkString.h"
#include "SkOpArray.h"

const SkScriptEngine2::OperatorAttributes SkScriptEngine2::gOpAttributes[] = {
{ SkOperand2::kNoType, SkOperand2::kNoType, kNoBias, kResultIsNotBoolean },
{ SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar | SkOperand2::kString),
    SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar | SkOperand2::kString), kTowardsString, kResultIsNotBoolean },    // kAdd
{ SkOperand2::kS32, SkOperand2::kS32, kNoBias, kResultIsNotBoolean }, // kBitAnd
{ SkOperand2::kNoType, SkOperand2::kS32, kNoBias, kResultIsNotBoolean }, // kBitNot
{ SkOperand2::kS32, SkOperand2::kS32, kNoBias, kResultIsNotBoolean }, // kBitOr
{ SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar),
    SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar), kNoBias, kResultIsNotBoolean }, // kDivide
{ SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar | SkOperand2::kString),
    SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar |SkOperand2:: kString), kTowardsNumber,
    kResultIsBoolean }, // kEqual
{ SkOperand2::kS32, SkOperand2::kNoType, kNoBias, kResultIsNotBoolean },     // kFlipOps
{ SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar | SkOperand2::kString),
    SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar | SkOperand2::kString), kTowardsNumber,
    kResultIsBoolean }, // kGreaterEqual
{ SkOperand2::kNoType, SkOperand2::kS32, kNoBias, kResultIsNotBoolean }, // kLogicalAnd    (really, ToBool)
{ SkOperand2::kNoType, SkOperand2::kS32, kNoBias, kResultIsNotBoolean }, // kLogicalNot
{ SkOperand2::kS32, SkOperand2::kS32, kNoBias, kResultIsNotBoolean }, // kLogicalOr
{ SkOperand2::kNoType, SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar), kNoBias, kResultIsNotBoolean }, // kMinus
{ SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar),
    SkOperand2::OpType(SkOperand2::kS32 |SkOperand2:: kScalar), kNoBias, kResultIsNotBoolean }, // kModulo
{ SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar),
    SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar), kNoBias, kResultIsNotBoolean }, // kMultiply
{ SkOperand2::kS32, SkOperand2::kS32, kNoBias, kResultIsNotBoolean }, // kShiftLeft
{ SkOperand2::kS32, SkOperand2::kS32, kNoBias, kResultIsNotBoolean }, // kShiftRight
{ SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar),
    SkOperand2::OpType(SkOperand2::kS32 | SkOperand2::kScalar), kNoBias, kResultIsNotBoolean }, // kSubtract
{ SkOperand2::kS32, SkOperand2::kS32, kNoBias, kResultIsNotBoolean } // kXor
>>>>>>> miniblink49
};

#define kBracketPrecedence 16
#define kIfElsePrecedence 15

const signed char SkScriptEngine2::gPrecedence[] = {
    17, // kUnassigned,
    6, // kAdd,
    10, // kBitAnd,
    4, // kBitNot,
    12, // kBitOr,
    5, // kDivide,
    9, // kEqual,
    -1, // kFlipOps,
    8, // kGreaterEqual,
    13, // kLogicalAnd,
    4, // kLogicalNot,
    14, // kLogicalOr,
    4, // kMinus,
    5, // kModulo,
    5, // kMultiply,
    7, // kShiftLeft,
    7, // kShiftRight,    // signed
    6, // kSubtract,
    11, // kXor
    kBracketPrecedence, // kArrayOp
    kIfElsePrecedence, // kElse
    kIfElsePrecedence, // kIf
    kBracketPrecedence, // kParen
};

const SkScriptEngine2::TypeOp SkScriptEngine2::gTokens[] = {
    kNop, // unassigned
    kAddInt, // kAdd,
    kBitAndInt, // kBitAnd,
    kBitNotInt, // kBitNot,
    kBitOrInt, // kBitOr,
    kDivideInt, // kDivide,
    kEqualInt, // kEqual,
    kFlipOpsOp, // kFlipOps,
    kGreaterEqualInt, // kGreaterEqual,
    kLogicalAndInt, // kLogicalAnd,
    kLogicalNotInt, // kLogicalNot,
    kLogicalOrInt, // kLogicalOr,
    kMinusInt, // kMinus,
    kModuloInt, // kModulo,
    kMultiplyInt, // kMultiply,
    kShiftLeftInt, // kShiftLeft,
    kShiftRightInt, // kShiftRight,    // signed
    kSubtractInt, // kSubtract,
    kXorInt // kXor
};

static inline bool is_between(int c, int min, int max)
{
    return (unsigned)(c - min) <= (unsigned)(max - min);
}

static inline bool is_ws(int c)
{
    return is_between(c, 1, 32);
}

<<<<<<< HEAD
static int token_length(const char* start)
{
    char ch = start[0];
    if (!is_between(ch, 'a', 'z') && !is_between(ch, 'A', 'Z') && ch != '_' && ch != '$')
=======
static int token_length(const char* start) {
    char ch = start[0];
    if (! is_between(ch, 'a' , 'z') &&  ! is_between(ch, 'A', 'Z') && ch != '_' && ch != '$')
>>>>>>> miniblink49
        return -1;
    int length = 0;
    do
        ch = start[++length];
<<<<<<< HEAD
    while (is_between(ch, 'a', 'z') || is_between(ch, 'A', 'Z') || is_between(ch, '0', '9') || ch == '_' || ch == '$');
    return length;
}

SkScriptEngine2::SkScriptEngine2(SkOperand2::OpType returnType)
    : fActiveStream(&fStream)
    , fTokenLength(0)
    , fReturnType(returnType)
    , fError(kNoError)
    , fAccumulatorType(SkOperand2::kNoType)
    , fBranchPopAllowed(true)
    , fConstExpression(true)
    , fOperandInUse(false)
{
    Branch branch(kUnassigned, 0, 0);
    fBranchStack.push(branch);
    *fOpStack.push() = (Op)kParen;
}

SkScriptEngine2::~SkScriptEngine2()
{
=======
    while (is_between(ch, 'a' , 'z') || is_between(ch, 'A', 'Z') || is_between(ch, '0', '9') ||
           ch == '_' || ch == '$');
    return length;
}

SkScriptEngine2::SkScriptEngine2(SkOperand2::OpType returnType) : fActiveStream(&fStream),
fTokenLength(0), fReturnType(returnType), fError(kNoError),
fAccumulatorType(SkOperand2::kNoType),
fBranchPopAllowed(true), fConstExpression(true), fOperandInUse(false)
{
    Branch branch(kUnassigned, 0, 0);
    fBranchStack.push(branch);
    *fOpStack.push() = (Op) kParen;
}

SkScriptEngine2::~SkScriptEngine2() {
>>>>>>> miniblink49
    for (SkString** stringPtr = fTrackString.begin(); stringPtr < fTrackString.end(); stringPtr++)
        delete *stringPtr;
    for (SkOpArray** arrayPtr = fTrackArray.begin(); arrayPtr < fTrackArray.end(); arrayPtr++)
        delete *arrayPtr;
}

<<<<<<< HEAD
void SkScriptEngine2::addToken(SkScriptEngine2::TypeOp op)
{
=======
void SkScriptEngine2::addToken(SkScriptEngine2::TypeOp op) {
>>>>>>> miniblink49
    int limit = fBranchStack.count() - 1;
    for (int index = 0; index < limit; index++) {
        Branch& branch = fBranchStack.index(index);
        if (branch.fPrimed == Branch::kIsPrimed)
            resolveBranch(branch);
    }
    if (fBranchPopAllowed) {
        while (fBranchStack.top().fDone == Branch::kIsDone)
            fBranchStack.pop();
    }
<<<<<<< HEAD
    unsigned char charOp = (unsigned char)op;
=======
    unsigned char charOp = (unsigned char) op;
>>>>>>> miniblink49
    fActiveStream->write(&charOp, sizeof(charOp));
}

void SkScriptEngine2::addTokenConst(SkScriptValue2* value, AddTokenRegister reg,
<<<<<<< HEAD
    SkOperand2::OpType toType, SkScriptEngine2::TypeOp op)
{
=======
                                    SkOperand2::OpType toType, SkScriptEngine2::TypeOp op) {
>>>>>>> miniblink49
    if (value->fIsConstant == SkScriptValue2::kConstant && convertTo(toType, value))
        return;
    addTokenValue(*value, reg);
    addToken(op);
    value->fIsWritten = SkScriptValue2::kWritten;
    value->fType = toType;
}

<<<<<<< HEAD
void SkScriptEngine2::addTokenInt(int integer)
{
    fActiveStream->write(&integer, sizeof(integer));
}

void SkScriptEngine2::addTokenScalar(SkScalar scalar)
{
    fActiveStream->write(&scalar, sizeof(scalar));
}

void SkScriptEngine2::addTokenString(const SkString& string)
{
=======
void SkScriptEngine2::addTokenInt(int integer) {
    fActiveStream->write(&integer, sizeof(integer));
}

void SkScriptEngine2::addTokenScalar(SkScalar scalar) {
    fActiveStream->write(&scalar, sizeof(scalar));
}

void SkScriptEngine2::addTokenString(const SkString& string) {
>>>>>>> miniblink49
    int size = SkToInt(string.size());
    addTokenInt(size);
    fActiveStream->write(string.c_str(), size);
}

<<<<<<< HEAD
void SkScriptEngine2::addTokenValue(const SkScriptValue2& value, AddTokenRegister reg)
{
=======
void SkScriptEngine2::addTokenValue(const SkScriptValue2& value, AddTokenRegister reg) {
>>>>>>> miniblink49
    if (value.isConstant() == false) {
        if (reg == kAccumulator) {
            if (fAccumulatorType == SkOperand2::kNoType)
                addToken(kAccumulatorPop);
        } else {
            ; // !!! incomplete?
        }
        return;
    }
    if (reg == kAccumulator && fAccumulatorType != SkOperand2::kNoType)
        addToken(kAccumulatorPush);
    switch (value.fType) {
<<<<<<< HEAD
    case SkOperand2::kS32:
        addToken(reg == kAccumulator ? kIntegerAccumulator : kIntegerOperand);
        addTokenInt(value.fOperand.fS32);
        if (reg == kAccumulator)
            fAccumulatorType = SkOperand2::kS32;
        else
            fOperandInUse = true;
        break;
    case SkOperand2::kScalar:
        addToken(reg == kAccumulator ? kScalarAccumulator : kScalarOperand);
        addTokenScalar(value.fOperand.fScalar);
        if (reg == kAccumulator)
            fAccumulatorType = SkOperand2::kScalar;
        else
            fOperandInUse = true;
        break;
    case SkOperand2::kString:
        addToken(reg == kAccumulator ? kStringAccumulator : kStringOperand);
        addTokenString(*value.fOperand.fString);
        if (reg == kAccumulator)
            fAccumulatorType = SkOperand2::kString;
        else
            fOperandInUse = true;
        break;
    default:
        SkASSERT(0); //!!! not implemented yet
    }
}

int SkScriptEngine2::arithmeticOp(char ch, char nextChar, bool lastPush)
{
=======
        case SkOperand2::kS32:
            addToken(reg == kAccumulator ? kIntegerAccumulator : kIntegerOperand);
            addTokenInt(value.fOperand.fS32);
            if (reg == kAccumulator)
                fAccumulatorType = SkOperand2::kS32;
            else
                fOperandInUse = true;
            break;
        case SkOperand2::kScalar:
            addToken(reg == kAccumulator ? kScalarAccumulator : kScalarOperand);
            addTokenScalar(value.fOperand.fScalar);
            if (reg == kAccumulator)
                fAccumulatorType = SkOperand2::kScalar;
            else
                fOperandInUse = true;
            break;
        case SkOperand2::kString:
            addToken(reg == kAccumulator ? kStringAccumulator : kStringOperand);
            addTokenString(*value.fOperand.fString);
            if (reg == kAccumulator)
                fAccumulatorType = SkOperand2::kString;
            else
                fOperandInUse = true;
            break;
        default:
            SkASSERT(0); //!!! not implemented yet
    }
}

int SkScriptEngine2::arithmeticOp(char ch, char nextChar, bool lastPush) {
>>>>>>> miniblink49
    Op op = kUnassigned;
    bool reverseOperands = false;
    bool negateResult = false;
    int advance = 1;
    switch (ch) {
<<<<<<< HEAD
    case '+':
        // !!! ignoring unary plus as implemented here has the side effect of
        // suppressing errors like +"hi"
        if (lastPush == false) // unary plus, don't push an operator
            return advance;
        op = kAdd;
        break;
    case '-':
        op = lastPush ? kSubtract : kMinus;
        break;
    case '*':
        op = kMultiply;
        break;
    case '/':
        op = kDivide;
        break;
    case '>':
        if (nextChar == '>') {
            op = kShiftRight;
            goto twoChar;
        }
        op = kGreaterEqual;
        if (nextChar == '=')
            goto twoChar;
        reverseOperands = negateResult = true;
        break;
    case '<':
        if (nextChar == '<') {
            op = kShiftLeft;
            goto twoChar;
        }
        op = kGreaterEqual;
        reverseOperands = nextChar == '=';
        negateResult = !reverseOperands;
        advance += reverseOperands;
        break;
    case '=':
        if (nextChar == '=') {
            op = kEqual;
            goto twoChar;
        }
        break;
    case '!':
        if (nextChar == '=') {
            op = kEqual;
            negateResult = true;
        twoChar:
            advance++;
            break;
        }
        op = kLogicalNot;
        break;
    case '?':
        op = (Op)kIf;
        break;
    case ':':
        op = (Op)kElse;
        break;
    case '^':
        op = kXor;
        break;
    case '(':
        *fOpStack.push() = (Op)kParen;
        return advance;
    case '&':
        SkASSERT(nextChar != '&');
        op = kBitAnd;
        break;
    case '|':
        SkASSERT(nextChar != '|');
        op = kBitOr;
        break;
    case '%':
        op = kModulo;
        break;
    case '~':
        op = kBitNot;
        break;
=======
        case '+':
            // !!! ignoring unary plus as implemented here has the side effect of
            // suppressing errors like +"hi"
            if (lastPush == false)    // unary plus, don't push an operator
                return advance;
            op = kAdd;
            break;
        case '-':
            op = lastPush ? kSubtract : kMinus;
            break;
        case '*':
            op = kMultiply;
            break;
        case '/':
            op = kDivide;
            break;
        case '>':
            if (nextChar == '>') {
                op = kShiftRight;
                goto twoChar;
            }
            op = kGreaterEqual;
            if (nextChar == '=')
                goto twoChar;
                reverseOperands = negateResult = true;
            break;
        case '<':
            if (nextChar == '<') {
                op = kShiftLeft;
                goto twoChar;
            }
            op = kGreaterEqual;
            reverseOperands = nextChar == '=';
            negateResult = ! reverseOperands;
            advance += reverseOperands;
            break;
        case '=':
            if (nextChar == '=') {
                op = kEqual;
                goto twoChar;
            }
            break;
        case '!':
            if (nextChar == '=') {
                op = kEqual;
                negateResult = true;
twoChar:
                    advance++;
                break;
            }
            op = kLogicalNot;
            break;
        case '?':
            op =(Op)  kIf;
            break;
        case ':':
            op = (Op) kElse;
            break;
        case '^':
            op = kXor;
            break;
        case '(':
            *fOpStack.push() = (Op) kParen;
            return advance;
        case '&':
            SkASSERT(nextChar != '&');
            op = kBitAnd;
            break;
        case '|':
            SkASSERT(nextChar != '|');
            op = kBitOr;
            break;
        case '%':
            op = kModulo;
            break;
        case '~':
            op = kBitNot;
            break;
>>>>>>> miniblink49
    }
    if (op == kUnassigned)
        return 0;
    signed char precedence = gPrecedence[op];
    do {
        int idx = 0;
        Op compare;
        do {
            compare = fOpStack.index(idx);
            if ((compare & kArtificialOp) == 0)
                break;
            idx++;
        } while (true);
        signed char topPrecedence = gPrecedence[compare];
        SkASSERT(topPrecedence != -1);
<<<<<<< HEAD
        if (topPrecedence > precedence || (topPrecedence == precedence && gOpAttributes[op].fLeftType == SkOperand2::kNoType)) {
=======
        if (topPrecedence > precedence || (topPrecedence == precedence &&
            gOpAttributes[op].fLeftType == SkOperand2::kNoType)) {
>>>>>>> miniblink49
            break;
        }
        processOp();
    } while (true);
    if (negateResult)
<<<<<<< HEAD
        *fOpStack.push() = (Op)(kLogicalNot | kArtificialOp);
    fOpStack.push(op);
    if (reverseOperands)
        *fOpStack.push() = (Op)(kFlipOps | kArtificialOp);
=======
        *fOpStack.push() = (Op) (kLogicalNot | kArtificialOp);
    fOpStack.push(op);
    if (reverseOperands)
        *fOpStack.push() = (Op) (kFlipOps | kArtificialOp);
>>>>>>> miniblink49

    return advance;
}

bool SkScriptEngine2::convertParams(SkTDArray<SkScriptValue2>* params,
<<<<<<< HEAD
    const SkOperand2::OpType* paramTypes, int paramCount)
{
    int count = params->count();
    if (count > paramCount) {
        SkASSERT(0);
        return false; // too many parameters passed
=======
                                    const SkOperand2::OpType* paramTypes, int paramCount) {
    int count = params->count();
    if (count > paramCount) {
        SkASSERT(0);
        return false;    // too many parameters passed
>>>>>>> miniblink49
    }
    for (int index = 0; index < count; index++)
        convertTo(paramTypes[index], &(*params)[index]);
    return true;
}

<<<<<<< HEAD
bool SkScriptEngine2::convertTo(SkOperand2::OpType toType, SkScriptValue2* value)
{
=======
bool SkScriptEngine2::convertTo(SkOperand2::OpType toType, SkScriptValue2* value ) {
>>>>>>> miniblink49
    SkOperand2::OpType type = value->fType;
    if (type == toType)
        return true;
    if (type == SkOperand2::kObject) {
        if (handleUnbox(value) == false)
            return false;
        return convertTo(toType, value);
    }
    return ConvertTo(this, toType, value);
}

<<<<<<< HEAD
bool SkScriptEngine2::evaluateDot(const char*& script)
{
    size_t fieldLength = token_length(++script); // skip dot
=======
bool SkScriptEngine2::evaluateDot(const char*& script) {
    size_t fieldLength = token_length(++script);        // skip dot
>>>>>>> miniblink49
    SkASSERT(fieldLength > 0); // !!! add error handling
    const char* field = script;
    script += fieldLength;
    bool success = handleProperty();
    if (success == false) {
        fError = kCouldNotFindReferencedID;
        goto error;
    }
    return evaluateDotParam(script, field, fieldLength);
error:
<<<<<<< HEAD
    return false;
}

bool SkScriptEngine2::evaluateDotParam(const char*& script, const char* field, size_t fieldLength)
{
=======
        return false;
}

bool SkScriptEngine2::evaluateDotParam(const char*& script, const char* field, size_t fieldLength) {
>>>>>>> miniblink49
    SkScriptValue2& top = fValueStack.top();
    if (top.fType != SkOperand2::kObject)
        return false;
    void* object = top.fOperand.fObject;
    fValueStack.pop();
    char ch; // see if it is a simple member or a function
    while (is_ws(ch = script[0]))
        script++;
    bool success = true;
    if (ch != '(')
        success = handleMember(field, fieldLength, object);
    else {
        SkTDArray<SkScriptValue2> params;
        *fBraceStack.push() = kFunctionBrace;
        success = functionParams(&script, &params);
        if (success)
            success = handleMemberFunction(field, fieldLength, object, &params);
    }
    return success;
}

<<<<<<< HEAD
bool SkScriptEngine2::evaluateScript(const char** scriptPtr, SkScriptValue2* value)
{
=======
bool SkScriptEngine2::evaluateScript(const char** scriptPtr, SkScriptValue2* value) {
>>>>>>> miniblink49
    //    fArrayOffset = 0;        // no support for structures for now
    bool success;
    const char* inner;
    if (strncmp(*scriptPtr, "#script:", sizeof("#script:") - 1) == 0) {
        *scriptPtr += sizeof("#script:") - 1;
        if (fReturnType == SkOperand2::kNoType || fReturnType == SkOperand2::kString) {
            success = innerScript(scriptPtr, value);
            SkASSERT(success);
            inner = value->fOperand.fString->c_str();
            scriptPtr = &inner;
        }
    }
    success = innerScript(scriptPtr, value);
    const char* script = *scriptPtr;
    char ch;
    while (is_ws(ch = script[0]))
        script++;
    if (ch != '\0') {
        // error may trigger on scripts like "50,0" that were intended to be written as "[50, 0]"
        return false;
    }
    return success;
}

<<<<<<< HEAD
void SkScriptEngine2::forget(SkOpArray* array)
{
=======
void SkScriptEngine2::forget(SkOpArray* array) {
>>>>>>> miniblink49
    if (array->getType() == SkOperand2::kString) {
        for (int index = 0; index < array->count(); index++) {
            SkString* string = (*array)[index].fString;
            int found = fTrackString.find(string);
            if (found >= 0)
                fTrackString.remove(found);
        }
        return;
    }
    if (array->getType() == SkOperand2::kArray) {
        for (int index = 0; index < array->count(); index++) {
            SkOpArray* child = (*array)[index].fArray;
<<<<<<< HEAD
            forget(child); // forgets children of child
=======
            forget(child);    // forgets children of child
>>>>>>> miniblink49
            int found = fTrackArray.find(child);
            if (found >= 0)
                fTrackArray.remove(found);
        }
    }
}

<<<<<<< HEAD
bool SkScriptEngine2::functionParams(const char** scriptPtr, SkTDArray<SkScriptValue2>* params)
{
    (*scriptPtr)++; // skip open paren
    *fOpStack.push() = (Op)kParen;
=======
bool SkScriptEngine2::functionParams(const char** scriptPtr, SkTDArray<SkScriptValue2>* params) {
    (*scriptPtr)++; // skip open paren
    *fOpStack.push() = (Op) kParen;
>>>>>>> miniblink49
    *fBraceStack.push() = kFunctionBrace;
    do {
        SkScriptValue2 value;
        bool success = innerScript(scriptPtr, &value);
        SkASSERT(success);
        if (success == false)
            return false;
        *params->append() = value;
    } while ((*scriptPtr)[-1] == ',');
    fBraceStack.pop();
    fOpStack.pop(); // pop paren
    (*scriptPtr)++; // advance beyond close paren
    return true;
}

<<<<<<< HEAD
size_t SkScriptEngine2::getTokenOffset()
{
    return fActiveStream->getOffset();
}

SkOperand2::OpType SkScriptEngine2::getUnboxType(SkOperand2 scriptValue)
{
=======
size_t SkScriptEngine2::getTokenOffset() {
    return fActiveStream->getOffset();
}

SkOperand2::OpType SkScriptEngine2::getUnboxType(SkOperand2 scriptValue) {
>>>>>>> miniblink49
    for (SkScriptCallBack** callBack = fCallBackArray.begin(); callBack < fCallBackArray.end(); callBack++) {
        if ((*callBack)->getType() != SkScriptCallBack::kUnbox)
            continue;
        return (*callBack)->getReturnType(0, &scriptValue);
    }
    return SkOperand2::kObject;
}

<<<<<<< HEAD
bool SkScriptEngine2::innerScript(const char** scriptPtr, SkScriptValue2* value)
{
=======
bool SkScriptEngine2::innerScript(const char** scriptPtr, SkScriptValue2* value) {
>>>>>>> miniblink49
    const char* script = *scriptPtr;
    char ch;
    bool lastPush = false;
    bool success = true;
    int opBalance = fOpStack.count();
    int baseBrace = fBraceStack.count();
    int branchBalance = fBranchStack.count();
    while ((ch = script[0]) != '\0') {
        if (is_ws(ch)) {
            script++;
            continue;
        }
        SkScriptValue2 operand;
        const char* dotCheck;
        if (fBraceStack.count() > baseBrace) {
            if (fBraceStack.top() == kArrayBrace) {
                SkScriptValue2 tokenValue;
<<<<<<< HEAD
                success = innerScript(&script, &tokenValue); // terminate and return on comma, close brace
=======
                success = innerScript(&script, &tokenValue);    // terminate and return on comma, close brace
>>>>>>> miniblink49
                SkASSERT(success);
                {
                    SkOperand2::OpType type = fReturnType;
                    if (fReturnType == SkOperand2::kNoType) {
                        // !!! short sighted; in the future, allow each returned array component to carry
                        // its own type, and let caller do any needed conversions
                        if (value->fOperand.fArray->count() == 0)
                            value->fOperand.fArray->setType(type = tokenValue.fType);
                        else
                            type = value->fOperand.fArray->getType();
                    }
                    if (tokenValue.fType != type)
                        convertTo(type, &tokenValue);
                    *value->fOperand.fArray->append() = tokenValue.fOperand;
                }
                lastPush = false;
                continue;
            } else {
                SkASSERT(token_length(script) > 0);
            }
        }
        if (lastPush != false && fTokenLength > 0) {
            if (ch == '(') {
                *fBraceStack.push() = kFunctionBrace;
                SkString functionName(fToken, fTokenLength);

                if (handleFunction(&script) == false)
                    return false;
                lastPush = true;
                continue;
            } else if (ch == '[') {
                if (handleProperty() == false) {
                    SkASSERT(0);
                    return false;
                }
                if (handleArrayIndexer(&script) == false)
                    return false;
                lastPush = true;
                continue;
            } else if (ch != '.') {
                if (handleProperty() == false) {
                    SkASSERT(0);
                    return false;
                }
                lastPush = true;
                continue;
            }
        }
        if (ch == '0' && (script[1] & ~0x20) == 'X') {
            SkASSERT(lastPush == false);
            script += 2;
<<<<<<< HEAD
            script = SkParse::FindHex(script, (uint32_t*)&operand.fOperand.fS32);
=======
            script = SkParse::FindHex(script, (uint32_t*) &operand.fOperand.fS32);
>>>>>>> miniblink49
            SkASSERT(script);
            goto intCommon;
        }
        if (lastPush == false && ch == '.')
            goto scalarCommon;
        if (ch >= '0' && ch <= '9') {
            SkASSERT(lastPush == false);
            dotCheck = SkParse::FindS32(script, &operand.fOperand.fS32);
            if (dotCheck[0] != '.') {
                script = dotCheck;
<<<<<<< HEAD
            intCommon:
                operand.fType = SkOperand2::kS32;
            } else {
            scalarCommon:
=======
intCommon:
                operand.fType = SkOperand2::kS32;
            } else {
scalarCommon:
>>>>>>> miniblink49
                script = SkParse::FindScalar(script, &operand.fOperand.fScalar);
                operand.fType = SkOperand2::kScalar;
            }
            operand.fIsConstant = SkScriptValue2::kConstant;
            fValueStack.push(operand);
            lastPush = true;
            continue;
        }
        int length = token_length(script);
        if (length > 0) {
            SkASSERT(lastPush == false);
            fToken = script;
            fTokenLength = length;
            script += length;
            lastPush = true;
            continue;
        }
        char startQuote = ch;
        if (startQuote == '\'' || startQuote == '\"') {
            SkASSERT(lastPush == false);
            operand.fOperand.fString = new SkString();
            ++script;
            const char* stringStart = script;
<<<<<<< HEAD
            do { // measure string
=======
            do {    // measure string
>>>>>>> miniblink49
                if (script[0] == '\\')
                    ++script;
                ++script;
                SkASSERT(script[0]); // !!! throw an error
            } while (script[0] != startQuote);
            operand.fOperand.fString->set(stringStart, script - stringStart);
            script = stringStart;
            char* stringWrite = operand.fOperand.fString->writable_str();
<<<<<<< HEAD
            do { // copy string
=======
            do {    // copy string
>>>>>>> miniblink49
                if (script[0] == '\\')
                    ++script;
                *stringWrite++ = script[0];
                ++script;
                SkASSERT(script[0]); // !!! throw an error
            } while (script[0] != startQuote);
            ++script;
            track(operand.fOperand.fString);
            operand.fType = SkOperand2::kString;
            operand.fIsConstant = SkScriptValue2::kConstant;
            fValueStack.push(operand);
            lastPush = true;
            continue;
        }
<<<<<<< HEAD
        if (ch == '.') {
=======
        if (ch ==  '.') {
>>>>>>> miniblink49
            if (fTokenLength == 0) {
                int tokenLength = token_length(++script);
                const char* token = script;
                script += tokenLength;
                SkASSERT(fValueStack.count() > 0); // !!! add error handling
                SkScriptValue2 top;
                fValueStack.pop(&top);

                addTokenInt(top.fType);
                addToken(kBoxToken);
                top.fType = SkOperand2::kObject;
                top.fIsConstant = SkScriptValue2::kVariable;
                fConstExpression = false;
                fValueStack.push(top);
                success = evaluateDotParam(script, token, tokenLength);
                SkASSERT(success);
                lastPush = true;
                continue;
            }
            // get next token, and evaluate immediately
            success = evaluateDot(script);
            if (success == false) {
                //                SkASSERT(0);
                return false;
            }
            lastPush = true;
            continue;
        }
        if (ch == '[') {
            if (lastPush == false) {
                script++;
                *fBraceStack.push() = kArrayBrace;
                operand.fOperand.fArray = value->fOperand.fArray = new SkOpArray(fReturnType);
                track(value->fOperand.fArray);

                operand.fType = SkOperand2::kArray;
                operand.fIsConstant = SkScriptValue2::kVariable;
                fValueStack.push(operand);
                continue;
            }
            if (handleArrayIndexer(&script) == false)
                return false;
            lastPush = true;
            continue;
        }
#if 0 // structs not supported for now
        if (ch == '{') {
            if (lastPush == false) {
                script++;
                *fBraceStack.push() = kStructBrace;
                operand.fS32 = 0;
                *fTypeStack.push() = (SkOpType) kStruct;
                fOperandStack.push(operand);
                continue;
            }
            SkASSERT(0); // braces in other contexts aren't supported yet
        }
#endif
        if (ch == ')' && fBraceStack.count() > 0) {
            BraceStyle braceStyle = fBraceStack.top();
            if (braceStyle == kFunctionBrace) {
                fBraceStack.pop();
                break;
            }
        }
        if (ch == ',' || ch == ']') {
            if (ch != ',') {
                BraceStyle match;
                fBraceStack.pop(&match);
                SkASSERT(match == kArrayBrace);
            }
            script++;
            // !!! see if brace or bracket is correct closer
            break;
        }
        char nextChar = script[1];
        int advance = logicalOp(ch, nextChar);
        if (advance == 0)
            advance = arithmeticOp(ch, nextChar, lastPush);
        if (advance == 0) // unknown token
            return false;
        if (advance > 0)
            script += advance;
        lastPush = ch == ']' || ch == ')';
    }
    if (fTokenLength > 0) {
        success = handleProperty();
        SkASSERT(success);
    }
    int branchIndex = 0;
    branchBalance = fBranchStack.count() - branchBalance;
    fBranchPopAllowed = false;
    while (branchIndex < branchBalance) {
        Branch& branch = fBranchStack.index(branchIndex++);
        if (branch.fPrimed == Branch::kIsPrimed)
            break;
        Op branchOp = branch.fOperator;
        SkOperand2::OpType lastType = fValueStack.top().fType;
        addTokenValue(fValueStack.top(), kAccumulator);
        fValueStack.pop();
        if (branchOp == kLogicalAnd || branchOp == kLogicalOr) {
            if (branch.fOperator == kLogicalAnd)
                branch.prime();
            addToken(kToBool);
        } else {
            resolveBranch(branch);
            SkScriptValue2 operand;
            operand.fType = lastType;
            // !!! note that many branching expressions could be constant
            // today, we always evaluate branches as returning variables
            operand.fIsConstant = SkScriptValue2::kVariable;
            fValueStack.push(operand);
        }
        if (branch.fDone == Branch::kIsNotDone)
            branch.prime();
    }
    fBranchPopAllowed = true;
    while (fBranchStack.top().fDone == Branch::kIsDone)
        fBranchStack.pop();
<<<<<<< HEAD
    while (fOpStack.count() > opBalance) { // leave open paren
=======
    while (fOpStack.count() > opBalance) {     // leave open paren
>>>>>>> miniblink49
        if (processOp() == false)
            return false;
    }
    SkOperand2::OpType topType = fValueStack.count() > 0 ? fValueStack.top().fType : SkOperand2::kNoType;
<<<<<<< HEAD
    if (topType != fReturnType && topType == SkOperand2::kString && fReturnType != SkOperand2::kNoType) { // if result is a string, give handle property a chance to convert it to the property value
=======
    if (topType != fReturnType &&
        topType == SkOperand2::kString && fReturnType != SkOperand2::kNoType) { // if result is a string, give handle property a chance to convert it to the property value
>>>>>>> miniblink49
        SkString* string = fValueStack.top().fOperand.fString;
        fToken = string->c_str();
        fTokenLength = string->size();
        fValueStack.pop();
        success = handleProperty();
<<<<<<< HEAD
        if (success == false) { // if it couldn't convert, return string (error?)
            SkScriptValue2 operand;
            operand.fType = SkOperand2::kString;
            operand.fOperand.fString = string;
            operand.fIsConstant = SkScriptValue2::kVariable; // !!! ?
=======
        if (success == false) {    // if it couldn't convert, return string (error?)
            SkScriptValue2 operand;
            operand.fType = SkOperand2::kString;
            operand.fOperand.fString = string;
            operand.fIsConstant = SkScriptValue2::kVariable;     // !!! ?
>>>>>>> miniblink49
            fValueStack.push(operand);
        }
    }
    if (fStream.getOffset() > 0) {
        addToken(kEnd);
        SkAutoDataUnref data(fStream.copyToData());
#ifdef SK_DEBUG
        decompile(data->bytes(), data->size());
#endif
        SkScriptRuntime runtime(fCallBackArray);
<<<<<<< HEAD
        runtime.executeTokens((unsigned char*)data->bytes());
=======
        runtime.executeTokens((unsigned char*) data->bytes());
>>>>>>> miniblink49
        SkScriptValue2 value1;
        runtime.getResult(&value1.fOperand);
        value1.fType = fReturnType;
        fValueStack.push(value1);
    }
    if (value) {
        if (fValueStack.count() == 0)
            return false;
        fValueStack.pop(value);
<<<<<<< HEAD
        if (value->fType != fReturnType && value->fType == SkOperand2::kObject && fReturnType != SkOperand2::kNoType)
=======
        if (value->fType != fReturnType && value->fType == SkOperand2::kObject &&
            fReturnType != SkOperand2::kNoType)
>>>>>>> miniblink49
            convertTo(fReturnType, value);
    }
    //    if (fBranchStack.top().fOpStackDepth > fOpStack.count())
    //        resolveBranch();
    *scriptPtr = script;
    return true; // no error
}

<<<<<<< HEAD
bool SkScriptEngine2::handleArrayIndexer(const char** scriptPtr)
{
    SkScriptValue2 scriptValue;
    (*scriptPtr)++;
    *fOpStack.push() = (Op)kParen;
=======
bool SkScriptEngine2::handleArrayIndexer(const char** scriptPtr) {
    SkScriptValue2 scriptValue;
    (*scriptPtr)++;
    *fOpStack.push() = (Op) kParen;
>>>>>>> miniblink49
    *fBraceStack.push() = kArrayBrace;
    SkOperand2::OpType saveType = fReturnType;
    fReturnType = SkOperand2::kS32;
    bool success = innerScript(scriptPtr, &scriptValue);
    fReturnType = saveType;
    SkASSERT(success);
    success = convertTo(SkOperand2::kS32, &scriptValue);
    SkASSERT(success);
    int index = scriptValue.fOperand.fS32;
    fValueStack.pop(&scriptValue);
    if (scriptValue.fType == SkOperand2::kObject) {
        success = handleUnbox(&scriptValue);
        SkASSERT(success);
        SkASSERT(scriptValue.fType == SkOperand2::kArray);
    }
    scriptValue.fType = scriptValue.fOperand.fArray->getType();
    //    SkASSERT(index >= 0);
<<<<<<< HEAD
    if ((unsigned)index >= (unsigned)scriptValue.fOperand.fArray->count()) {
=======
    if ((unsigned) index >= (unsigned) scriptValue.fOperand.fArray->count()) {
>>>>>>> miniblink49
        fError = kArrayIndexOutOfBounds;
        return false;
    }
    scriptValue.fOperand = scriptValue.fOperand.fArray->begin()[index];
    scriptValue.fIsConstant = SkScriptValue2::kVariable;
    fValueStack.push(scriptValue);
    fOpStack.pop(); // pop paren
    return success;
}

<<<<<<< HEAD
bool SkScriptEngine2::handleFunction(const char** scriptPtr)
{
=======
bool SkScriptEngine2::handleFunction(const char** scriptPtr) {
>>>>>>> miniblink49
    const char* functionName = fToken;
    size_t functionNameLen = fTokenLength;
    fTokenLength = 0;
    SkTDArray<SkScriptValue2> params;
    bool success = functionParams(scriptPtr, &params);
    if (success == false)
        goto done;
    {
        for (SkScriptCallBack** callBack = fCallBackArray.begin(); callBack < fCallBackArray.end(); callBack++) {
            if ((*callBack)->getType() != SkScriptCallBack::kFunction)
                continue;
            SkScriptValue2 callbackResult;
            success = (*callBack)->getReference(functionName, functionNameLen, &callbackResult);
            if (success) {
<<<<<<< HEAD
                callbackResult.fType = (*callBack)->getReturnType(callbackResult.fOperand.fReference, nullptr);
=======
                callbackResult.fType = (*callBack)->getReturnType(callbackResult.fOperand.fReference, NULL);
>>>>>>> miniblink49
                callbackResult.fIsConstant = SkScriptValue2::kVariable;
                fValueStack.push(callbackResult);
                goto done;
            }
        }
    }
    return false;
done:
<<<<<<< HEAD
    fOpStack.pop();
    return success;
}

bool SkScriptEngine2::handleMember(const char* field, size_t len, void* object)
{
=======
        fOpStack.pop();
    return success;
}

bool SkScriptEngine2::handleMember(const char* field, size_t len, void* object) {
>>>>>>> miniblink49
    bool success = true;
    for (SkScriptCallBack** callBack = fCallBackArray.begin(); callBack < fCallBackArray.end(); callBack++) {
        if ((*callBack)->getType() != SkScriptCallBack::kMember)
            continue;
        SkScriptValue2 callbackResult;
        success = (*callBack)->getReference(field, len, &callbackResult);
        if (success) {
            if (callbackResult.fType == SkOperand2::kString)
                track(callbackResult.fOperand.fString);
            callbackResult.fIsConstant = SkScriptValue2::kVariable;
            fValueStack.push(callbackResult);
            goto done;
        }
    }
    return false;
done:
<<<<<<< HEAD
    return success;
}

bool SkScriptEngine2::handleMemberFunction(const char* field, size_t len, void* object,
    SkTDArray<SkScriptValue2>* params)
{
=======
        return success;
}

bool SkScriptEngine2::handleMemberFunction(const char* field, size_t len, void* object,
                                           SkTDArray<SkScriptValue2>* params) {
>>>>>>> miniblink49
    bool success = true;
    for (SkScriptCallBack** callBack = fCallBackArray.begin(); callBack < fCallBackArray.end(); callBack++) {
        if ((*callBack)->getType() != SkScriptCallBack::kMemberFunction)
            continue;
        SkScriptValue2 callbackResult;
        success = (*callBack)->getReference(field, len, &callbackResult);
        if (success) {
            if (callbackResult.fType == SkOperand2::kString)
                track(callbackResult.fOperand.fString);
            callbackResult.fIsConstant = SkScriptValue2::kVariable;
            fValueStack.push(callbackResult);
            goto done;
        }
    }
    return false;
done:
<<<<<<< HEAD
    return success;
}

bool SkScriptEngine2::handleProperty()
{
=======
        return success;
}

bool SkScriptEngine2::handleProperty() {
>>>>>>> miniblink49
    bool success = true;
    for (SkScriptCallBack** callBack = fCallBackArray.begin(); callBack < fCallBackArray.end(); callBack++) {
        if ((*callBack)->getType() != SkScriptCallBack::kProperty)
            continue;
        SkScriptValue2 callbackResult;
        success = (*callBack)->getReference(fToken, fTokenLength, &callbackResult);
        if (success) {
<<<<<<< HEAD
            if (callbackResult.fType == SkOperand2::kString && callbackResult.fOperand.fString == nullptr) {
=======
            if (callbackResult.fType == SkOperand2::kString && callbackResult.fOperand.fString == NULL) {
>>>>>>> miniblink49
                callbackResult.fOperand.fString = new SkString(fToken, fTokenLength);
                track(callbackResult.fOperand.fString);
            }
            callbackResult.fIsConstant = SkScriptValue2::kVariable;
            fValueStack.push(callbackResult);
            goto done;
        }
    }
done:
<<<<<<< HEAD
    fTokenLength = 0;
    return success;
}

bool SkScriptEngine2::handleUnbox(SkScriptValue2* scriptValue)
{
=======
        fTokenLength = 0;
    return success;
}

bool SkScriptEngine2::handleUnbox(SkScriptValue2* scriptValue) {
>>>>>>> miniblink49
    bool success = true;
    for (SkScriptCallBack** callBack = fCallBackArray.begin(); callBack < fCallBackArray.end(); callBack++) {
        if ((*callBack)->getType() != SkScriptCallBack::kUnbox)
            continue;
<<<<<<< HEAD
        SkScriptCallBackConvert* callBackConvert = (SkScriptCallBackConvert*)*callBack;
=======
        SkScriptCallBackConvert* callBackConvert = (SkScriptCallBackConvert*) *callBack;
>>>>>>> miniblink49
        success = callBackConvert->convert(scriptValue->fType, &scriptValue->fOperand);
        if (success) {
            if (scriptValue->fType == SkOperand2::kString)
                track(scriptValue->fOperand.fString);
            goto done;
        }
    }
    return false;
done:
<<<<<<< HEAD
    return success;
=======
        return success;
>>>>>>> miniblink49
}

// note that entire expression is treated as if it were enclosed in parens
// an open paren is always the first thing in the op stack

<<<<<<< HEAD
int SkScriptEngine2::logicalOp(char ch, char nextChar)
{
=======
int SkScriptEngine2::logicalOp(char ch, char nextChar) {
>>>>>>> miniblink49
    int advance = 1;
    Op op;
    signed char precedence;
    switch (ch) {
<<<<<<< HEAD
    case ')':
        op = (Op)kParen;
        break;
    case ']':
        op = (Op)kArrayOp;
        break;
    case '?':
        op = (Op)kIf;
        break;
    case ':':
        op = (Op)kElse;
        break;
    case '&':
        if (nextChar != '&')
            goto noMatch;
        op = kLogicalAnd;
        advance = 2;
        break;
    case '|':
        if (nextChar != '|')
            goto noMatch;
        op = kLogicalOr;
        advance = 2;
        break;
    default:
    noMatch:
        return 0;
=======
        case ')':
            op = (Op) kParen;
            break;
        case ']':
            op = (Op) kArrayOp;
            break;
        case '?':
            op = (Op) kIf;
            break;
        case ':':
            op = (Op) kElse;
            break;
        case '&':
            if (nextChar != '&')
                goto noMatch;
            op = kLogicalAnd;
            advance = 2;
            break;
        case '|':
            if (nextChar != '|')
                goto noMatch;
            op = kLogicalOr;
            advance = 2;
            break;
        default:
            noMatch:
            return 0;
>>>>>>> miniblink49
    }
    precedence = gPrecedence[op];
    int branchIndex = 0;
    fBranchPopAllowed = false;
    do {
        while (gPrecedence[fOpStack.top() & ~kArtificialOp] < precedence)
            processOp();
        Branch& branch = fBranchStack.index(branchIndex++);
        Op branchOp = branch.fOperator;
        if (gPrecedence[branchOp] >= precedence)
            break;
        addTokenValue(fValueStack.top(), kAccumulator);
        fValueStack.pop();
        if (branchOp == kLogicalAnd || branchOp == kLogicalOr) {
            if (branch.fOperator == kLogicalAnd)
                branch.prime();
            addToken(kToBool);
        } else
            resolveBranch(branch);
        if (branch.fDone == Branch::kIsNotDone)
            branch.prime();
    } while (true);
    fBranchPopAllowed = true;
    while (fBranchStack.top().fDone == Branch::kIsDone)
        fBranchStack.pop();
    processLogicalOp(op);
    return advance;
}

<<<<<<< HEAD
void SkScriptEngine2::processLogicalOp(Op op)
{
    switch (op) {
    case kParen:
    case kArrayOp:
        SkASSERT(fOpStack.count() > 1 && fOpStack.top() == op); // !!! add error handling
        if (op == kParen)
            fOpStack.pop();
        else {
            SkScriptValue2 value;
            fValueStack.pop(&value);
            SkASSERT(value.fType == SkOperand2::kS32 || value.fType == SkOperand2::kScalar); // !!! add error handling (although, could permit strings eventually)
            int index = value.fType == SkOperand2::kScalar ? SkScalarFloorToInt(value.fOperand.fScalar) : value.fOperand.fS32;
            SkScriptValue2 arrayValue;
            fValueStack.pop(&arrayValue);
            SkASSERT(arrayValue.fType == SkOperand2::kArray); // !!! add error handling
            SkOpArray* array = arrayValue.fOperand.fArray;
            SkOperand2 operand;
            SkDEBUGCODE(bool success =) array->getIndex(index, &operand);
            SkASSERT(success); // !!! add error handling
            SkScriptValue2 resultValue;
            resultValue.fType = array->getType();
            resultValue.fOperand = operand;
            resultValue.fIsConstant = SkScriptValue2::kVariable;
            fValueStack.push(resultValue);
        }
        break;
    case kIf: {
        if (fAccumulatorType == SkOperand2::kNoType) {
            addTokenValue(fValueStack.top(), kAccumulator);
            fValueStack.pop();
        }
        SkASSERT(fAccumulatorType != SkOperand2::kString); // !!! add error handling
        addToken(kIfOp);
        Branch branch(op, fOpStack.count(), getTokenOffset());
        *fBranchStack.push() = branch;
        addTokenInt(0); // placeholder for future branch
        fAccumulatorType = SkOperand2::kNoType;
    } break;
    case kElse: {
        addTokenValue(fValueStack.top(), kAccumulator);
        fValueStack.pop();
        addToken(kElseOp);
        size_t newOffset = getTokenOffset();
        addTokenInt(0); // placeholder for future branch
        Branch& branch = fBranchStack.top();
        resolveBranch(branch);
        branch.fOperator = op;
        branch.fDone = Branch::kIsNotDone;
        SkASSERT(branch.fOpStackDepth == fOpStack.count());
        branch.fOffset = SkToU16(newOffset);
        fAccumulatorType = SkOperand2::kNoType;
    } break;
    case kLogicalAnd:
    case kLogicalOr: {
        Branch& oldTop = fBranchStack.top();
        Branch::Primed wasPrime = oldTop.fPrimed;
        Branch::Done wasDone = oldTop.fDone;
        oldTop.fPrimed = Branch::kIsNotPrimed;
        oldTop.fDone = Branch::kIsNotDone;
        if (fAccumulatorType == SkOperand2::kNoType) {
            SkASSERT(fValueStack.top().fType == SkOperand2::kS32); // !!! add error handling, and conversion to int?
            addTokenValue(fValueStack.top(), kAccumulator);
            fValueStack.pop();
        } else {
            SkASSERT(fAccumulatorType == SkOperand2::kS32);
        }
        // if 'and', write beq goto opcode after end of predicate (after to bool)
        // if 'or', write bne goto to bool
        addToken(op == kLogicalAnd ? kLogicalAndInt : kLogicalOrInt);
        Branch branch(op, fOpStack.count(), getTokenOffset());
        addTokenInt(0); // placeholder for future branch
        oldTop.fPrimed = wasPrime;
        oldTop.fDone = wasDone;
        *fBranchStack.push() = branch;
        fAccumulatorType = SkOperand2::kNoType;
    } break;
    default:
        SkASSERT(0);
    }
}

bool SkScriptEngine2::processOp()
{
    Op op;
    fOpStack.pop(&op);
    op = (Op)(op & ~kArtificialOp);
=======
void SkScriptEngine2::processLogicalOp(Op op) {
    switch (op) {
        case kParen:
        case kArrayOp:
            SkASSERT(fOpStack.count() > 1 && fOpStack.top() == op);    // !!! add error handling
            if (op == kParen)
                fOpStack.pop();
            else {
                SkScriptValue2 value;
                fValueStack.pop(&value);
                SkASSERT(value.fType == SkOperand2::kS32 || value.fType == SkOperand2::kScalar); // !!! add error handling (although, could permit strings eventually)
                int index = value.fType == SkOperand2::kScalar ? SkScalarFloorToInt(value.fOperand.fScalar) :
                    value.fOperand.fS32;
                SkScriptValue2 arrayValue;
                fValueStack.pop(&arrayValue);
                SkASSERT(arrayValue.fType == SkOperand2::kArray);  // !!! add error handling
                SkOpArray* array = arrayValue.fOperand.fArray;
                SkOperand2 operand;
                SkDEBUGCODE(bool success = ) array->getIndex(index, &operand);
                SkASSERT(success); // !!! add error handling
                SkScriptValue2 resultValue;
                resultValue.fType = array->getType();
                resultValue.fOperand = operand;
                resultValue.fIsConstant = SkScriptValue2::kVariable;
                fValueStack.push(resultValue);
            }
                break;
        case kIf: {
            if (fAccumulatorType == SkOperand2::kNoType) {
                addTokenValue(fValueStack.top(), kAccumulator);
                fValueStack.pop();
            }
            SkASSERT(fAccumulatorType != SkOperand2::kString); // !!! add error handling
            addToken(kIfOp);
            Branch branch(op, fOpStack.count(), getTokenOffset());
            *fBranchStack.push() = branch;
            addTokenInt(0); // placeholder for future branch
            fAccumulatorType = SkOperand2::kNoType;
        } break;
        case kElse: {
            addTokenValue(fValueStack.top(), kAccumulator);
            fValueStack.pop();
            addToken(kElseOp);
            size_t newOffset = getTokenOffset();
            addTokenInt(0); // placeholder for future branch
            Branch& branch = fBranchStack.top();
            resolveBranch(branch);
            branch.fOperator = op;
            branch.fDone = Branch::kIsNotDone;
            SkASSERT(branch.fOpStackDepth == fOpStack.count());
            branch.fOffset = SkToU16(newOffset);
            fAccumulatorType = SkOperand2::kNoType;
        } break;
        case kLogicalAnd:
        case kLogicalOr: {
            Branch& oldTop = fBranchStack.top();
            Branch::Primed wasPrime = oldTop.fPrimed;
            Branch::Done wasDone = oldTop.fDone;
            oldTop.fPrimed = Branch::kIsNotPrimed;
            oldTop.fDone = Branch::kIsNotDone;
            if (fAccumulatorType == SkOperand2::kNoType) {
                SkASSERT(fValueStack.top().fType == SkOperand2::kS32); // !!! add error handling, and conversion to int?
                addTokenValue(fValueStack.top(), kAccumulator);
                fValueStack.pop();
            } else {
                SkASSERT(fAccumulatorType == SkOperand2::kS32);
            }
            // if 'and', write beq goto opcode after end of predicate (after to bool)
            // if 'or', write bne goto to bool
            addToken(op == kLogicalAnd ? kLogicalAndInt : kLogicalOrInt);
            Branch branch(op, fOpStack.count(), getTokenOffset());
            addTokenInt(0); // placeholder for future branch
            oldTop.fPrimed = wasPrime;
            oldTop.fDone = wasDone;
            *fBranchStack.push() = branch;
            fAccumulatorType = SkOperand2::kNoType;
        }    break;
        default:
            SkASSERT(0);
    }
}

bool SkScriptEngine2::processOp() {
    Op op;
    fOpStack.pop(&op);
    op = (Op) (op & ~kArtificialOp);
>>>>>>> miniblink49
    const OperatorAttributes* attributes = &gOpAttributes[op];
    SkScriptValue2 value1;
    memset(&value1, 0, sizeof(SkScriptValue2));
    SkScriptValue2 value2;
    fValueStack.pop(&value2);
    value2.fIsWritten = SkScriptValue2::kUnwritten;
    //    SkScriptEngine2::SkTypeOp convert1[3];
    //    SkScriptEngine2::SkTypeOp convert2[3];
    //    SkScriptEngine2::SkTypeOp* convert2Ptr = convert2;
    bool constantOperands = value2.fIsConstant == SkScriptValue2::kConstant;
    if (attributes->fLeftType != SkOperand2::kNoType) {
        fValueStack.pop(&value1);
        constantOperands &= value1.fIsConstant == SkScriptValue2::kConstant;
        value1.fIsWritten = SkScriptValue2::kUnwritten;
        if (op == kFlipOps) {
            SkTSwap(value1, value2);
            fOpStack.pop(&op);
<<<<<<< HEAD
            op = (Op)(op & ~kArtificialOp);
=======
            op = (Op) (op & ~kArtificialOp);
>>>>>>> miniblink49
            attributes = &gOpAttributes[op];
            if (constantOperands == false)
                addToken(kFlipOpsOp);
        }
        if (value1.fType == SkOperand2::kObject && (value1.fType & attributes->fLeftType) == 0) {
            value1.fType = getUnboxType(value1.fOperand);
            addToken(kUnboxToken);
        }
    }
    if (value2.fType == SkOperand2::kObject && (value2.fType & attributes->fLeftType) == 0) {
        value1.fType = getUnboxType(value2.fOperand);
        addToken(kUnboxToken2);
    }
    if (attributes->fLeftType != SkOperand2::kNoType) {
        if (value1.fType != value2.fType) {
<<<<<<< HEAD
            if ((attributes->fLeftType & SkOperand2::kString) && attributes->fBias & kTowardsString && ((value1.fType | value2.fType) & SkOperand2::kString)) {
                if (value1.fType == SkOperand2::kS32 || value1.fType == SkOperand2::kScalar) {
                    addTokenConst(&value1, kAccumulator, SkOperand2::kString,
                        value1.fType == SkOperand2::kS32 ? kIntToString : kScalarToString);
                }
                if (value2.fType == SkOperand2::kS32 || value2.fType == SkOperand2::kScalar) {
                    addTokenConst(&value2, kOperand, SkOperand2::kString,
                        value2.fType == SkOperand2::kS32 ? kIntToString2 : kScalarToString2);
                }
            } else if (attributes->fLeftType & SkOperand2::kScalar && ((value1.fType | value2.fType) & SkOperand2::kScalar)) {
=======
            if ((attributes->fLeftType & SkOperand2::kString) && attributes->fBias & kTowardsString &&
                ((value1.fType | value2.fType) & SkOperand2::kString)) {
                if (value1.fType == SkOperand2::kS32 || value1.fType == SkOperand2::kScalar) {
                    addTokenConst(&value1, kAccumulator, SkOperand2::kString,
                                  value1.fType == SkOperand2::kS32 ? kIntToString : kScalarToString);
                }
                if (value2.fType == SkOperand2::kS32 || value2.fType == SkOperand2::kScalar) {
                    addTokenConst(&value2, kOperand, SkOperand2::kString,
                                  value2.fType == SkOperand2::kS32 ? kIntToString2 : kScalarToString2);
                }
            } else if (attributes->fLeftType & SkOperand2::kScalar && ((value1.fType | value2.fType) &
                                                                       SkOperand2::kScalar)) {
>>>>>>> miniblink49
                if (value1.fType == SkOperand2::kS32)
                    addTokenConst(&value1, kAccumulator, SkOperand2::kScalar, kIntToScalar);
                if (value2.fType == SkOperand2::kS32)
                    addTokenConst(&value2, kOperand, SkOperand2::kScalar, kIntToScalar2);
            }
        }
        if ((value1.fType & attributes->fLeftType) == 0 || value1.fType != value2.fType) {
            if (value1.fType == SkOperand2::kString)
                addTokenConst(&value1, kAccumulator, SkOperand2::kScalar, kStringToScalar);
<<<<<<< HEAD
            if (value1.fType == SkOperand2::kScalar && (attributes->fLeftType == SkOperand2::kS32 || value2.fType == SkOperand2::kS32))
                addTokenConst(&value1, kAccumulator, SkOperand2::kS32, kScalarToInt);
        }
    }
    AddTokenRegister rhRegister = attributes->fLeftType != SkOperand2::kNoType ? kOperand : kAccumulator;
    if ((value2.fType & attributes->fRightType) == 0 || value1.fType != value2.fType) {
        if (value2.fType == SkOperand2::kString)
            addTokenConst(&value2, rhRegister, SkOperand2::kScalar, kStringToScalar2);
        if (value2.fType == SkOperand2::kScalar && (attributes->fRightType == SkOperand2::kS32 || value1.fType == SkOperand2::kS32))
=======
            if (value1.fType == SkOperand2::kScalar && (attributes->fLeftType == SkOperand2::kS32 ||
                                                        value2.fType == SkOperand2::kS32))
                addTokenConst(&value1, kAccumulator, SkOperand2::kS32, kScalarToInt);
        }
    }
    AddTokenRegister rhRegister = attributes->fLeftType != SkOperand2::kNoType ?
        kOperand : kAccumulator;
    if ((value2.fType & attributes->fRightType) == 0 || value1.fType != value2.fType) {
        if (value2.fType == SkOperand2::kString)
            addTokenConst(&value2, rhRegister, SkOperand2::kScalar, kStringToScalar2);
        if (value2.fType == SkOperand2::kScalar && (attributes->fRightType == SkOperand2::kS32 ||
                                                    value1.fType == SkOperand2::kS32))
>>>>>>> miniblink49
            addTokenConst(&value2, rhRegister, SkOperand2::kS32, kScalarToInt2);
    }
    TypeOp typeOp = gTokens[op];
    if (value2.fType == SkOperand2::kScalar)
<<<<<<< HEAD
        typeOp = (TypeOp)(typeOp + 1);
    else if (value2.fType == SkOperand2::kString)
        typeOp = (TypeOp)(typeOp + 2);
=======
        typeOp = (TypeOp) (typeOp + 1);
    else if (value2.fType == SkOperand2::kString)
        typeOp = (TypeOp) (typeOp + 2);
>>>>>>> miniblink49
    SkDynamicMemoryWStream stream;
    SkOperand2::OpType saveType = SkOperand2::kNoType;
    SkBool saveOperand = false;
    if (constantOperands) {
        fActiveStream = &stream;
        saveType = fAccumulatorType;
        saveOperand = fOperandInUse;
        fAccumulatorType = SkOperand2::kNoType;
        fOperandInUse = false;
    }
<<<<<<< HEAD
    if (attributes->fLeftType != SkOperand2::kNoType) { // two operands
=======
    if (attributes->fLeftType != SkOperand2::kNoType) {    // two operands
>>>>>>> miniblink49
        if (value1.fIsWritten == SkScriptValue2::kUnwritten)
            addTokenValue(value1, kAccumulator);
    }
    if (value2.fIsWritten == SkScriptValue2::kUnwritten)
        addTokenValue(value2, rhRegister);
    addToken(typeOp);
    if (constantOperands) {
        addToken(kEnd);
        SkAutoDataUnref data(fStream.copyToData());
#ifdef SK_DEBUG
        decompile(data->bytes(), data->size());
#endif
        SkScriptRuntime runtime(fCallBackArray);
        runtime.executeTokens((unsigned char*)data->bytes());
        runtime.getResult(&value1.fOperand);
        if (attributes->fResultIsBoolean == kResultIsBoolean)
            value1.fType = SkOperand2::kS32;
        else if (attributes->fLeftType == SkOperand2::kNoType) // unary operand
            value1.fType = value2.fType;
        fValueStack.push(value1);
        if (value1.fType == SkOperand2::kString)
            runtime.untrack(value1.fOperand.fString);
        else if (value1.fType == SkOperand2::kArray)
            runtime.untrack(value1.fOperand.fArray);
        fActiveStream = &fStream;
        fAccumulatorType = saveType;
        fOperandInUse = saveOperand;
        return true;
    }
    value2.fIsConstant = SkScriptValue2::kVariable;
    fValueStack.push(value2);
    return true;
}

<<<<<<< HEAD
void SkScriptEngine2::Branch::resolve(SkDynamicMemoryWStream* stream, size_t off)
{
=======
void SkScriptEngine2::Branch::resolve(SkDynamicMemoryWStream* stream, size_t off) {
>>>>>>> miniblink49
    SkASSERT(fDone == kIsNotDone);
    fPrimed = kIsNotPrimed;
    fDone = kIsDone;
    SkASSERT(off > fOffset + sizeof(size_t));
    size_t offset = off - fOffset - sizeof(offset);
    stream->write(&offset, fOffset, sizeof(offset));
}

<<<<<<< HEAD
void SkScriptEngine2::resolveBranch(SkScriptEngine2::Branch& branch)
{
    branch.resolve(fActiveStream, getTokenOffset());
}

bool SkScriptEngine2::ConvertTo(SkScriptEngine2* engine, SkOperand2::OpType toType, SkScriptValue2* value)
{
=======
void SkScriptEngine2::resolveBranch(SkScriptEngine2::Branch& branch) {
    branch.resolve(fActiveStream, getTokenOffset());
}

bool SkScriptEngine2::ConvertTo(SkScriptEngine2* engine, SkOperand2::OpType toType, SkScriptValue2* value ) {
>>>>>>> miniblink49
    SkASSERT(value);
    SkOperand2::OpType type = value->fType;
    if (type == toType)
        return true;
    SkOperand2& operand = value->fOperand;
    bool success = true;
    switch (toType) {
<<<<<<< HEAD
    case SkOperand2::kS32:
        if (type == SkOperand2::kScalar)
            operand.fS32 = SkScalarFloorToInt(operand.fScalar);
        else {
            SkASSERT(type == SkOperand2::kString);
            success = SkParse::FindS32(operand.fString->c_str(), &operand.fS32) != nullptr;
        }
        break;
    case SkOperand2::kScalar:
        if (type == SkOperand2::kS32)
            operand.fScalar = IntToScalar(operand.fS32);
        else {
            SkASSERT(type == SkOperand2::kString);
            success = SkParse::FindScalar(operand.fString->c_str(), &operand.fScalar) != nullptr;
        }
        break;
    case SkOperand2::kString: {
        SkString* strPtr = new SkString();
        SkASSERT(engine);
        engine->track(strPtr);
        if (type == SkOperand2::kS32)
            strPtr->appendS32(operand.fS32);
        else {
            SkASSERT(type == SkOperand2::kScalar);
            strPtr->appendScalar(operand.fScalar);
        }
        operand.fString = strPtr;
    } break;
    case SkOperand2::kArray: {
        SkOpArray* array = new SkOpArray(type);
        *array->append() = operand;
        engine->track(array);
        operand.fArray = array;
    } break;
    default:
        SkASSERT(0);
=======
        case SkOperand2::kS32:
            if (type == SkOperand2::kScalar)
                operand.fS32 = SkScalarFloorToInt(operand.fScalar);
            else {
                SkASSERT(type == SkOperand2::kString);
                success = SkParse::FindS32(operand.fString->c_str(), &operand.fS32) != NULL;
            }
                break;
        case SkOperand2::kScalar:
            if (type == SkOperand2::kS32)
                operand.fScalar = IntToScalar(operand.fS32);
            else {
                SkASSERT(type == SkOperand2::kString);
                success = SkParse::FindScalar(operand.fString->c_str(), &operand.fScalar) != NULL;
            }
                break;
        case SkOperand2::kString: {
            SkString* strPtr = new SkString();
            SkASSERT(engine);
            engine->track(strPtr);
            if (type == SkOperand2::kS32)
                strPtr->appendS32(operand.fS32);
            else {
                SkASSERT(type == SkOperand2::kScalar);
                strPtr->appendScalar(operand.fScalar);
            }
            operand.fString = strPtr;
        } break;
        case SkOperand2::kArray: {
            SkOpArray* array = new SkOpArray(type);
            *array->append() = operand;
            engine->track(array);
            operand.fArray = array;
        } break;
        default:
            SkASSERT(0);
>>>>>>> miniblink49
    }
    value->fType = toType;
    return success;
}

<<<<<<< HEAD
SkScalar SkScriptEngine2::IntToScalar(int32_t s32)
{
    SkScalar scalar;
    if (s32 == (int32_t)SK_NaN32)
=======
SkScalar SkScriptEngine2::IntToScalar(int32_t s32) {
    SkScalar scalar;
    if (s32 == (int32_t) SK_NaN32)
>>>>>>> miniblink49
        scalar = SK_ScalarNaN;
    else if (SkAbs32(s32) == SK_MaxS32)
        scalar = SkSign32(s32) * SK_ScalarMax;
    else
        scalar = SkIntToScalar(s32);
    return scalar;
}

<<<<<<< HEAD
bool SkScriptEngine2::ValueToString(const SkScriptValue2& value, SkString* string)
{
    switch (value.fType) {
    case SkOperand2::kS32:
        string->reset();
        string->appendS32(value.fOperand.fS32);
        break;
    case SkOperand2::kScalar:
        string->reset();
        string->appendScalar(value.fOperand.fScalar);
        break;
    case SkOperand2::kString:
        string->set(*value.fOperand.fString);
        break;
    default:
        SkASSERT(0);
        return false;
=======
bool SkScriptEngine2::ValueToString(const SkScriptValue2& value, SkString* string) {
    switch (value.fType) {
        case SkOperand2::kS32:
            string->reset();
            string->appendS32(value.fOperand.fS32);
            break;
        case SkOperand2::kScalar:
            string->reset();
            string->appendScalar(value.fOperand.fScalar);
            break;
        case SkOperand2::kString:
            string->set(*value.fOperand.fString);
            break;
        default:
            SkASSERT(0);
            return false;
>>>>>>> miniblink49
    }
    return true; // no error
}

#ifdef SK_DEBUG
#if defined(SK_SUPPORT_UNITTEST)

<<<<<<< HEAD
#define testInt(expression)                                   \
    {                                                         \
#expression, SkOperand2::kS32, expression, 0, nullptr \
    }
#define testScalar(expression)                                            \
    {                                                                     \
#expression, SkOperand2::kScalar, 0, (float)(expression), nullptr \
    }
#define testRemainder(exp1, exp2)                                                         \
    {                                                                                     \
#exp1 "%" #exp2, SkOperand2::kScalar, 0, fmodf((float)exp1, (float)exp2), nullptr \
    }
#define testTrue(expression)                         \
    {                                                \
#expression, SkOperand2::kS32, 1, 0, nullptr \
    }
#define testFalse(expression)                        \
    {                                                \
#expression, SkOperand2::kS32, 0, 0, nullptr \
    }

static const SkScriptNAnswer2 scriptTests[] = {
    testInt(1 || (0 && 3)),
    testScalar(--5.5 - -1.5),
    testScalar(1.0 + 5),
    testInt((6 + 7) * 8),
    testInt(3 * (4 + 5)),
    testScalar(1.0 + 2.0),
    testScalar(3.0 - 1.0),
    testScalar(6 - 1.0),
    testScalar(2.5 * 6.),
    testScalar(0.5 * 4),
    testScalar(4.5 / .5),
    testScalar(9.5 / 19),
    testRemainder(9.5, 0.5),
    testRemainder(9., 2),
    testRemainder(9, 2.5),
    testRemainder(-9, 2.5),
    testTrue(-9 == -9.0),
    testTrue(-9. == -4.0 - 5),
    testTrue(-9. * 1 == -4 - 5),
    testFalse(-9 != -9.0),
    testFalse(-9. != -4.0 - 5),
    testFalse(-9. * 1 != -4 - 5),
    testInt(0x123),
    testInt(0XABC),
    testInt(0xdeadBEEF),
    { "'123'+\"456\"", SkOperand2::kString, 0, 0, "123456" },
    { "123+\"456\"", SkOperand2::kString, 0, 0, "123456" },
    { "'123'+456", SkOperand2::kString, 0, 0, "123456" },
    { "'123'|\"456\"", SkOperand2::kS32, 123 | 456, 0, nullptr },
    { "123|\"456\"", SkOperand2::kS32, 123 | 456, 0, nullptr },
    { "'123'|456", SkOperand2::kS32, 123 | 456, 0, nullptr },
    { "'2'<11", SkOperand2::kS32, 1, 0, nullptr },
    { "2<'11'", SkOperand2::kS32, 1, 0, nullptr },
    { "'2'<'11'", SkOperand2::kS32, 0, 0, nullptr },
    testInt(123),
    testInt(-345),
    testInt(+678),
    testInt(1 + 2 + 3),
    testInt(3 * 4 + 5),
    testInt(6 + 7 * 8),
    testInt(-1 - 2 - 8 / 4),
    testInt(-9 % 4),
    testInt(9 % -4),
    testInt(-9 % -4),
    testInt(123 | 978),
    testInt(123 & 978),
    testInt(123 ^ 978),
    testInt(2 << 4),
    testInt(99 >> 3),
=======
#define testInt(expression) { #expression, SkOperand2::kS32, expression, 0, NULL }
#define testScalar(expression) { #expression, SkOperand2::kScalar, 0, (float) (expression), NULL }
#define testRemainder(exp1, exp2) { #exp1 "%" #exp2, SkOperand2::kScalar, 0, fmodf((float) exp1, (float) exp2), NULL }
#define testTrue(expression) { #expression, SkOperand2::kS32, 1, 0, NULL }
#define testFalse(expression) { #expression, SkOperand2::kS32, 0, 0, NULL }

static const SkScriptNAnswer2 scriptTests[]  = {
    testInt(1||(0&&3)),
    testScalar(- -5.5- -1.5),
    testScalar(1.0+5),
    testInt((6+7)*8),
    testInt(3*(4+5)),
    testScalar(1.0+2.0),
    testScalar(3.0-1.0),
    testScalar(6-1.0),
    testScalar(2.5*6.),
    testScalar(0.5*4),
    testScalar(4.5/.5),
    testScalar(9.5/19),
    testRemainder(9.5, 0.5),
    testRemainder(9.,2),
    testRemainder(9,2.5),
    testRemainder(-9,2.5),
    testTrue(-9==-9.0),
    testTrue(-9.==-4.0-5),
    testTrue(-9.*1==-4-5),
    testFalse(-9!=-9.0),
    testFalse(-9.!=-4.0-5),
    testFalse(-9.*1!=-4-5),
    testInt(0x123),
    testInt(0XABC),
    testInt(0xdeadBEEF),
    {    "'123'+\"456\"", SkOperand2::kString, 0, 0, "123456" },
    {    "123+\"456\"", SkOperand2::kString, 0, 0, "123456" },
    {    "'123'+456", SkOperand2::kString, 0, 0, "123456" },
    {    "'123'|\"456\"", SkOperand2::kS32, 123|456, 0, NULL },
    {    "123|\"456\"", SkOperand2::kS32, 123|456, 0, NULL },
    {    "'123'|456", SkOperand2::kS32, 123|456, 0, NULL },
    {    "'2'<11", SkOperand2::kS32, 1, 0, NULL },
    {    "2<'11'", SkOperand2::kS32, 1, 0, NULL },
    {    "'2'<'11'", SkOperand2::kS32, 0, 0, NULL },
    testInt(123),
    testInt(-345),
    testInt(+678),
    testInt(1+2+3),
    testInt(3*4+5),
    testInt(6+7*8),
    testInt(-1-2-8/4),
    testInt(-9%4),
    testInt(9%-4),
    testInt(-9%-4),
    testInt(123|978),
    testInt(123&978),
    testInt(123^978),
    testInt(2<<4),
    testInt(99>>3),
>>>>>>> miniblink49
    testInt(~55),
    testInt(~~55),
    testInt(!55),
    testInt(!!55),
    // both int
<<<<<<< HEAD
    testInt(2 < 2),
    testInt(2 < 11),
    testInt(20 < 11),
    testInt(2 <= 2),
    testInt(2 <= 11),
    testInt(20 <= 11),
    testInt(2 > 2),
    testInt(2 > 11),
    testInt(20 > 11),
    testInt(2 >= 2),
    testInt(2 >= 11),
    testInt(20 >= 11),
    testInt(2 == 2),
    testInt(2 == 11),
    testInt(20 == 11),
    testInt(2 != 2),
    testInt(2 != 11),
    testInt(20 != 11),
    // left int, right scalar
    testInt(2 < 2.),
    testInt(2 < 11.),
    testInt(20 < 11.),
    testInt(2 <= 2.),
    testInt(2 <= 11.),
    testInt(20 <= 11.),
    testInt(2 > 2.),
    testInt(2 > 11.),
    testInt(20 > 11.),
    testInt(2 >= 2.),
    testInt(2 >= 11.),
    testInt(20 >= 11.),
    testInt(2 == 2.),
    testInt(2 == 11.),
    testInt(20 == 11.),
    testInt(2 != 2.),
    testInt(2 != 11.),
    testInt(20 != 11.),
    // left scalar, right int
    testInt(2. < 2),
    testInt(2. < 11),
    testInt(20. < 11),
    testInt(2. <= 2),
    testInt(2. <= 11),
    testInt(20. <= 11),
    testInt(2. > 2),
    testInt(2. > 11),
    testInt(20. > 11),
    testInt(2. >= 2),
    testInt(2. >= 11),
    testInt(20. >= 11),
    testInt(2. == 2),
    testInt(2. == 11),
    testInt(20. == 11),
    testInt(2. != 2),
    testInt(2. != 11),
    testInt(20. != 11),
    // both scalar
    testInt(2. < 11.),
    testInt(20. < 11.),
    testInt(2. <= 2.),
    testInt(2. <= 11.),
    testInt(20. <= 11.),
    testInt(2. > 2.),
    testInt(2. > 11.),
    testInt(20. > 11.),
    testInt(2. >= 2.),
    testInt(2. >= 11.),
    testInt(20. >= 11.),
    testInt(2. == 2.),
    testInt(2. == 11.),
    testInt(20. == 11.),
    testInt(2. != 2.),
    testInt(2. != 11.),
    testInt(20. != 11.),
    // int, string (string is int)
    testFalse(2 < '2'),
    testTrue(2 < '11'),
    testFalse(20 < '11'),
    testTrue(2 <= '2'),
    testTrue(2 <= '11'),
    testFalse(20 <= '11'),
    testFalse(2 > '2'),
    testFalse(2 > '11'),
    testTrue(20 > '11'),
    testTrue(2 >= '2'),
    testFalse(2 >= '11'),
    testTrue(20 >= '11'),
    testTrue(2 == '2'),
    testFalse(2 == '11'),
    testFalse(2 != '2'),
    testTrue(2 != '11'),
    // int, string (string is scalar)
    testFalse(2 < '2.'),
    testTrue(2 < '11.'),
    testFalse(20 < '11.'),
    testTrue(2 == '2.'),
    testFalse(2 == '11.'),
    // scalar, string
    testFalse(2. < '2.'),
    testTrue(2. < '11.'),
    testFalse(20. < '11.'),
    testTrue(2. == '2.'),
    testFalse(2. == '11.'),
    // string, int
    testFalse('2' < 2),
    testTrue('2' < 11),
    testFalse('20' < 11),
    testTrue('2' == 2),
    testFalse('2' == 11),
    // string, scalar
    testFalse('2' < 2.),
    testTrue('2' < 11.),
    testFalse('20' < 11.),
    testTrue('2' == 2.),
    testFalse('2' == 11.),
    // string, string
    testFalse('2' < '2'),
    testFalse('2' < '11'),
    testFalse('20' < '11'),
    testTrue('2' == '2'),
    testFalse('2' == '11'),
    // logic
    testInt(1 ? 2 : 3),
    testInt(0 ? 2 : 3),
    testInt((1 && 2) || 3),
    testInt((1 && 0) || 3),
    testInt((1 && 0) || 0),
    testInt(1 || (0 && 3)),
    testInt(0 || (0 && 3)),
    testInt(0 || (1 && 3)),
    testInt(0 && 1 ? 2 : 3), { "123.5", SkOperand2::kScalar, 0, SkIntToScalar(123) + SK_Scalar1 / 2, nullptr }
};

#define SkScriptNAnswer_testCount SK_ARRAY_COUNT(scriptTests)
#endif // SK_SUPPORT_UNITTEST

void SkScriptEngine2::UnitTest()
{
=======
    testInt(2<2),
    testInt(2<11),
    testInt(20<11),
    testInt(2<=2),
    testInt(2<=11),
    testInt(20<=11),
    testInt(2>2),
    testInt(2>11),
    testInt(20>11),
    testInt(2>=2),
    testInt(2>=11),
    testInt(20>=11),
    testInt(2==2),
    testInt(2==11),
    testInt(20==11),
    testInt(2!=2),
    testInt(2!=11),
    testInt(20!=11),
    // left int, right scalar
    testInt(2<2.),
    testInt(2<11.),
    testInt(20<11.),
    testInt(2<=2.),
    testInt(2<=11.),
    testInt(20<=11.),
    testInt(2>2.),
    testInt(2>11.),
    testInt(20>11.),
    testInt(2>=2.),
    testInt(2>=11.),
    testInt(20>=11.),
    testInt(2==2.),
    testInt(2==11.),
    testInt(20==11.),
    testInt(2!=2.),
    testInt(2!=11.),
    testInt(20!=11.),
    // left scalar, right int
    testInt(2.<2),
    testInt(2.<11),
    testInt(20.<11),
    testInt(2.<=2),
    testInt(2.<=11),
    testInt(20.<=11),
    testInt(2.>2),
    testInt(2.>11),
    testInt(20.>11),
    testInt(2.>=2),
    testInt(2.>=11),
    testInt(20.>=11),
    testInt(2.==2),
    testInt(2.==11),
    testInt(20.==11),
    testInt(2.!=2),
    testInt(2.!=11),
    testInt(20.!=11),
    // both scalar
    testInt(2.<11.),
    testInt(20.<11.),
    testInt(2.<=2.),
    testInt(2.<=11.),
    testInt(20.<=11.),
    testInt(2.>2.),
    testInt(2.>11.),
    testInt(20.>11.),
    testInt(2.>=2.),
    testInt(2.>=11.),
    testInt(20.>=11.),
    testInt(2.==2.),
    testInt(2.==11.),
    testInt(20.==11.),
    testInt(2.!=2.),
    testInt(2.!=11.),
    testInt(20.!=11.),
    // int, string (string is int)
    testFalse(2<'2'),
    testTrue(2<'11'),
    testFalse(20<'11'),
    testTrue(2<='2'),
    testTrue(2<='11'),
    testFalse(20<='11'),
    testFalse(2>'2'),
    testFalse(2>'11'),
    testTrue(20>'11'),
    testTrue(2>='2'),
    testFalse(2>='11'),
    testTrue(20>='11'),
    testTrue(2=='2'),
    testFalse(2=='11'),
    testFalse(2!='2'),
    testTrue(2!='11'),
    // int, string (string is scalar)
    testFalse(2<'2.'),
    testTrue(2<'11.'),
    testFalse(20<'11.'),
    testTrue(2=='2.'),
    testFalse(2=='11.'),
    // scalar, string
    testFalse(2.<'2.'),
    testTrue(2.<'11.'),
    testFalse(20.<'11.'),
    testTrue(2.=='2.'),
    testFalse(2.=='11.'),
    // string, int
    testFalse('2'<2),
    testTrue('2'<11),
    testFalse('20'<11),
    testTrue('2'==2),
    testFalse('2'==11),
    // string, scalar
    testFalse('2'<2.),
    testTrue('2'<11.),
    testFalse('20'<11.),
    testTrue('2'==2.),
    testFalse('2'==11.),
    // string, string
    testFalse('2'<'2'),
    testFalse('2'<'11'),
    testFalse('20'<'11'),
    testTrue('2'=='2'),
    testFalse('2'=='11'),
    // logic
    testInt(1?2:3),
    testInt(0?2:3),
    testInt((1&&2)||3),
    testInt((1&&0)||3),
    testInt((1&&0)||0),
    testInt(1||(0&&3)),
    testInt(0||(0&&3)),
    testInt(0||(1&&3)),
    testInt(0&&1?2:3)
    , {    "123.5", SkOperand2::kScalar, 0, SkIntToScalar(123) + SK_Scalar1/2, NULL }
};

#define SkScriptNAnswer_testCount    SK_ARRAY_COUNT(scriptTests)
#endif  // SK_SUPPORT_UNITTEST

void SkScriptEngine2::UnitTest() {
>>>>>>> miniblink49
#if defined(SK_SUPPORT_UNITTEST)
    ValidateDecompileTable();
    for (size_t index = 0; index < SkScriptNAnswer_testCount; index++) {
        SkScriptEngine2 engine(scriptTests[index].fType);
        SkScriptValue2 value;
        const char* script = scriptTests[index].fScript;
        const char* scriptPtr = script;
        SkASSERT(engine.evaluateScript(&scriptPtr, &value) == true);
        SkASSERT(value.fType == scriptTests[index].fType);
        SkScalar error;
        switch (value.fType) {
<<<<<<< HEAD
        case SkOperand2::kS32:
            if (value.fOperand.fS32 != scriptTests[index].fIntAnswer)
                SkDEBUGF(("script '%s' == value %d != expected answer %d\n", script, value.fOperand.fS32, scriptTests[index].fIntAnswer));
            SkASSERT(value.fOperand.fS32 == scriptTests[index].fIntAnswer);
            break;
        case SkOperand2::kScalar:
            error = SkScalarAbs(value.fOperand.fScalar - scriptTests[index].fScalarAnswer);
            if (error >= SK_Scalar1 / 10000)
                SkDEBUGF(("script '%s' == value %g != expected answer %g\n", script, value.fOperand.fScalar / (1.0f * SK_Scalar1), scriptTests[index].fScalarAnswer / (1.0f * SK_Scalar1)));
            SkASSERT(error < SK_Scalar1 / 10000);
            break;
        case SkOperand2::kString:
            SkASSERT(value.fOperand.fString->equals(scriptTests[index].fStringAnswer));
            break;
        default:
            SkASSERT(0);
        }
    }
#endif // SK_SUPPORT_UNITTEST
}
#endif // SK_DEBUG
=======
            case SkOperand2::kS32:
                if (value.fOperand.fS32 != scriptTests[index].fIntAnswer)
                    SkDEBUGF(("script '%s' == value %d != expected answer %d\n", script, value.fOperand.fS32, scriptTests[index].fIntAnswer));
                SkASSERT(value.fOperand.fS32 == scriptTests[index].fIntAnswer);
                break;
            case SkOperand2::kScalar:
                error = SkScalarAbs(value.fOperand.fScalar - scriptTests[index].fScalarAnswer);
                if (error >= SK_Scalar1 / 10000)
                    SkDEBUGF(("script '%s' == value %g != expected answer %g\n", script, value.fOperand.fScalar / (1.0f * SK_Scalar1), scriptTests[index].fScalarAnswer / (1.0f * SK_Scalar1)));
                SkASSERT(error < SK_Scalar1 / 10000);
                break;
            case SkOperand2::kString:
                SkASSERT(value.fOperand.fString->equals(scriptTests[index].fStringAnswer));
                break;
            default:
                SkASSERT(0);
        }
    }
#endif  // SK_SUPPORT_UNITTEST
}
#endif  // SK_DEBUG
>>>>>>> miniblink49
