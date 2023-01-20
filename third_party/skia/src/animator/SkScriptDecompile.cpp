
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "SkScript2.h"

#ifdef SK_DEBUG

<<<<<<< HEAD
#define TypeOpName(op)           \
    {                            \
        SkScriptEngine2::op, #op \
    }
=======
#define TypeOpName(op) {SkScriptEngine2::op, #op }
>>>>>>> miniblink49

static const struct OpName {
    SkScriptEngine2::TypeOp fOp;
    const char* fName;
} gOpNames[] = {
    TypeOpName(kNop), // should never get generated
    TypeOpName(kAccumulatorPop),
    TypeOpName(kAccumulatorPush),
    TypeOpName(kAddInt),
    TypeOpName(kAddScalar),
    TypeOpName(kAddString), // string concat
    TypeOpName(kArrayIndex),
    TypeOpName(kArrayParam),
    TypeOpName(kArrayToken),
    TypeOpName(kBitAndInt),
    TypeOpName(kBitNotInt),
    TypeOpName(kBitOrInt),
    TypeOpName(kBoxToken),
    TypeOpName(kCallback),
    TypeOpName(kDivideInt),
    TypeOpName(kDivideScalar),
    TypeOpName(kDotOperator),
    TypeOpName(kElseOp),
    TypeOpName(kEnd),
    TypeOpName(kEqualInt),
    TypeOpName(kEqualScalar),
    TypeOpName(kEqualString),
    TypeOpName(kFunctionCall),
    TypeOpName(kFlipOpsOp),
    TypeOpName(kFunctionToken),
    TypeOpName(kGreaterEqualInt),
    TypeOpName(kGreaterEqualScalar),
    TypeOpName(kGreaterEqualString),
    TypeOpName(kIfOp),
    TypeOpName(kIntToScalar),
    TypeOpName(kIntToScalar2),
    TypeOpName(kIntToString),
    TypeOpName(kIntToString2),
    TypeOpName(kIntegerAccumulator),
    TypeOpName(kIntegerOperand),
    TypeOpName(kLogicalAndInt),
    TypeOpName(kLogicalNotInt),
    TypeOpName(kLogicalOrInt),
    TypeOpName(kMemberOp),
    TypeOpName(kMinusInt),
    TypeOpName(kMinusScalar),
    TypeOpName(kModuloInt),
    TypeOpName(kModuloScalar),
    TypeOpName(kMultiplyInt),
    TypeOpName(kMultiplyScalar),
    TypeOpName(kPropertyOp),
    TypeOpName(kScalarAccumulator),
    TypeOpName(kScalarOperand),
    TypeOpName(kScalarToInt),
    TypeOpName(kScalarToInt2),
    TypeOpName(kScalarToString),
    TypeOpName(kScalarToString2),
    TypeOpName(kShiftLeftInt),
    TypeOpName(kShiftRightInt), // signed
    TypeOpName(kStringAccumulator),
    TypeOpName(kStringOperand),
    TypeOpName(kStringToInt),
    TypeOpName(kStringToScalar),
    TypeOpName(kStringToScalar2),
    TypeOpName(kStringTrack),
    TypeOpName(kSubtractInt),
    TypeOpName(kSubtractScalar),
    TypeOpName(kToBool),
    TypeOpName(kUnboxToken),
    TypeOpName(kUnboxToken2),
    TypeOpName(kXorInt)
};

static size_t gOpNamesSize = sizeof(gOpNames) / sizeof(gOpNames[0]);

<<<<<<< HEAD
#define OperandName(op)     \
    {                       \
        SkOperand2::op, #op \
    }
=======
#define OperandName(op) {SkOperand2::op, #op }
>>>>>>> miniblink49

static const struct OperName {
    SkOperand2::OpType fType;
    const char* fName;
} gOperandNames[] = {
    OperandName(kNoType),
    OperandName(kS32),
    OperandName(kScalar),
    OperandName(kString),
    OperandName(kArray),
    OperandName(kObject)
};

static size_t gOperandNamesSize = sizeof(gOperandNames) / sizeof(gOperandNames[0]);

// check to see that there are no missing or duplicate entries
<<<<<<< HEAD
void SkScriptEngine2::ValidateDecompileTable()
{
=======
void SkScriptEngine2::ValidateDecompileTable() {
>>>>>>> miniblink49
    SkScriptEngine2::TypeOp op = SkScriptEngine2::kNop;
    size_t index;
    for (index = 0; index < gOpNamesSize; index++) {
        SkASSERT(gOpNames[index].fOp == op);
<<<<<<< HEAD
        op = (SkScriptEngine2::TypeOp)(op + 1);
=======
        op = (SkScriptEngine2::TypeOp) (op + 1);
>>>>>>> miniblink49
    }
    index = 0;
    SkOperand2::OpType type = SkOperand2::kNoType;
    SkASSERT(gOperandNames[index].fType == type);
<<<<<<< HEAD
    for (; index < gOperandNamesSize - 1;) {
        type = (SkOperand2::OpType)(1 << index);
=======
    for (; index < gOperandNamesSize - 1; ) {
        type = (SkOperand2::OpType) (1 << index);
>>>>>>> miniblink49
        SkASSERT(gOperandNames[++index].fType == type);
    }
}

<<<<<<< HEAD
void SkScriptEngine2::decompile(const unsigned char* start, size_t length)
{
=======
void SkScriptEngine2::decompile(const unsigned char* start, size_t length) {
>>>>>>> miniblink49
    SkASSERT(length > 0);
    const unsigned char* opCode = start;
    do {
        SkASSERT((size_t)(opCode - start) < length);
<<<<<<< HEAD
        SkScriptEngine2::TypeOp op = (SkScriptEngine2::TypeOp)*opCode++;
=======
        SkScriptEngine2::TypeOp op = (SkScriptEngine2::TypeOp) *opCode++;
>>>>>>> miniblink49
        SkASSERT((size_t)op < gOpNamesSize);
        SkDebugf("%d: %s", opCode - start - 1, gOpNames[op].fName);
        switch (op) {
        case SkScriptEngine2::kCallback: {
            int index;
            memcpy(&index, opCode, sizeof(index));
            opCode += sizeof(index);
            SkDebugf(" index: %d", index);
<<<<<<< HEAD
        } break;
=======
            } break;
>>>>>>> miniblink49
        case SkScriptEngine2::kFunctionCall:
        case SkScriptEngine2::kMemberOp:
        case SkScriptEngine2::kPropertyOp: {
            size_t ref;
            memcpy(&ref, opCode, sizeof(ref));
            opCode += sizeof(ref);
            SkDebugf(" ref: %d", ref);
<<<<<<< HEAD
        } break;
=======
            } break;
>>>>>>> miniblink49
        case SkScriptEngine2::kIntegerAccumulator:
        case SkScriptEngine2::kIntegerOperand: {
            int32_t integer;
            memcpy(&integer, opCode, sizeof(integer));
            opCode += sizeof(int32_t);
            SkDebugf(" integer: %d", integer);
<<<<<<< HEAD
        } break;
=======
            } break;
>>>>>>> miniblink49
        case SkScriptEngine2::kScalarAccumulator:
        case SkScriptEngine2::kScalarOperand: {
            SkScalar scalar;
            memcpy(&scalar, opCode, sizeof(scalar));
            opCode += sizeof(SkScalar);
            SkDebugf(" scalar: %g", SkScalarToFloat(scalar));
<<<<<<< HEAD
        } break;
=======
            } break;
>>>>>>> miniblink49
        case SkScriptEngine2::kStringAccumulator:
        case SkScriptEngine2::kStringOperand: {
            int size;
            SkString* strPtr = new SkString();
            memcpy(&size, opCode, sizeof(size));
            opCode += sizeof(size);
<<<<<<< HEAD
            strPtr->set((char*)opCode, size);
            opCode += size;
            SkDebugf(" string: %s", strPtr->c_str());
            delete strPtr;
        } break;
=======
            strPtr->set((char*) opCode, size);
            opCode += size;
            SkDebugf(" string: %s", strPtr->c_str());
            delete strPtr;
            } break;
>>>>>>> miniblink49
        case SkScriptEngine2::kBoxToken: {
            SkOperand2::OpType type;
            memcpy(&type, opCode, sizeof(type));
            opCode += sizeof(type);
            size_t index = 0;
            if (type == 0)
                SkDebugf(" type: %s", gOperandNames[index].fName);
            else {
                while (type != 0) {
                    SkASSERT(index + 1 < gOperandNamesSize);
                    if (type & (1 << index)) {
<<<<<<< HEAD
                        type = (SkOperand2::OpType)(type & ~(1 << index));
=======
                        type = (SkOperand2::OpType) (type & ~(1 << index));
>>>>>>> miniblink49
                        SkDebugf(" type: %s", gOperandNames[index + 1].fName);
                    }
                    index++;
                }
            }
<<<<<<< HEAD
        } break;
=======
            } break;
>>>>>>> miniblink49
        case SkScriptEngine2::kIfOp:
        case SkScriptEngine2::kLogicalAndInt:
        case SkScriptEngine2::kElseOp:
        case SkScriptEngine2::kLogicalOrInt: {
            int size;
            memcpy(&size, opCode, sizeof(size));
            opCode += sizeof(size);
            SkDebugf(" offset (address): %d (%d)", size, opCode - start + size);
<<<<<<< HEAD
        } break;
        case SkScriptEngine2::kEnd:
            goto done;
        case SkScriptEngine2::kNop:
            SkASSERT(0);
        default:
            break;
        }
        SkDebugf("\n");
=======
            } break;
        case SkScriptEngine2::kEnd:
            goto done;
        case SkScriptEngine2::kNop:
                SkASSERT(0);
        default:
            break;
    }
    SkDebugf("\n");
>>>>>>> miniblink49
    } while (true);
done:
    SkDebugf("\n");
}

#endif
