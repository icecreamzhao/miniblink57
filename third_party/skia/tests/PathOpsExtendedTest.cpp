/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "PathOpsExtendedTest.h"
#include "PathOpsThreadedCommon.h"
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkForceLinking.h"
#include "SkMatrix.h"
#include "SkMutex.h"
#include "SkPaint.h"
#include "SkRTConf.h"
#include "SkStream.h"

<<<<<<< HEAD
#include <stdlib.h>

=======
>>>>>>> miniblink49
#ifdef SK_BUILD_FOR_MAC
#include <sys/sysctl.h>
#endif

__SK_FORCE_IMAGE_DECODER_LINKING;

DEFINE_bool2(runFail, f, false, "run tests known to fail.");
DEFINE_bool2(runBinary, f, false, "run tests known to fail binary sect.");

<<<<<<< HEAD
static const char marker[] = "</div>\n"
                             "\n"
                             "<script type=\"text/javascript\">\n"
                             "\n"
                             "var testDivs = [\n";
=======
static const char marker[] =
    "</div>\n"
    "\n"
    "<script type=\"text/javascript\">\n"
    "\n"
    "var testDivs = [\n";
>>>>>>> miniblink49

static const char* opStrs[] = {
    "kDifference_SkPathOp",
    "kIntersect_SkPathOp",
    "kUnion_SkPathOp",
    "kXor_PathOp",
    "kReverseDifference_SkPathOp",
};

static const char* opSuffixes[] = {
    "d",
    "i",
    "u",
    "o",
};

#if DEBUG_SHOW_TEST_NAME
<<<<<<< HEAD
static void showPathData(const SkPath& path)
{
    SkPath::RawIter iter(path);
    uint8_t verb;
    SkPoint pts[4];
    SkPoint firstPt = { 0, 0 }, lastPt = { 0, 0 };
=======
static void showPathData(const SkPath& path) {
    SkPath::RawIter iter(path);
    uint8_t verb;
    SkPoint pts[4];
    SkPoint firstPt = {0, 0}, lastPt = {0, 0};
>>>>>>> miniblink49
    bool firstPtSet = false;
    bool lastPtSet = true;
    while ((verb = iter.next(pts)) != SkPath::kDone_Verb) {
        switch (verb) {
<<<<<<< HEAD
        case SkPath::kMove_Verb:
            if (firstPtSet && lastPtSet && firstPt != lastPt) {
                SkDebugf("{{%1.9g,%1.9g}, {%1.9g,%1.9g}},\n", lastPt.fX, lastPt.fY,
                    firstPt.fX, firstPt.fY);
                lastPtSet = false;
            }
            firstPt = pts[0];
            firstPtSet = true;
            continue;
        case SkPath::kLine_Verb:
            SkDebugf("{{%1.9g,%1.9g}, {%1.9g,%1.9g}},\n", pts[0].fX, pts[0].fY,
                pts[1].fX, pts[1].fY);
            lastPt = pts[1];
            lastPtSet = true;
            break;
        case SkPath::kQuad_Verb:
            SkDebugf("{{%1.9g,%1.9g}, {%1.9g,%1.9g}, {%1.9g,%1.9g}},\n",
                pts[0].fX, pts[0].fY, pts[1].fX, pts[1].fY, pts[2].fX, pts[2].fY);
            lastPt = pts[2];
            lastPtSet = true;
            break;
        case SkPath::kConic_Verb:
            SkDebugf("{{%1.9g,%1.9g}, {%1.9g,%1.9g}, {%1.9g,%1.9g}},  //weight=%1.9g\n",
                pts[0].fX, pts[0].fY, pts[1].fX, pts[1].fY, pts[2].fX, pts[2].fY,
                iter.conicWeight());
            lastPt = pts[2];
            lastPtSet = true;
            break;
        case SkPath::kCubic_Verb:
            SkDebugf("{{%1.9g,%1.9g}, {%1.9g,%1.9g}, {%1.9g,%1.9g}, {%1.9g,%1.9g}},\n",
                pts[0].fX, pts[0].fY, pts[1].fX, pts[1].fY, pts[2].fX, pts[2].fY,
                pts[3].fX, pts[3].fY);
            lastPt = pts[3];
            lastPtSet = true;
            break;
        case SkPath::kClose_Verb:
            if (firstPtSet && lastPtSet && firstPt != lastPt) {
                SkDebugf("{{%1.9g,%1.9g}, {%1.9g,%1.9g}},\n", lastPt.fX, lastPt.fY,
                    firstPt.fX, firstPt.fY);
            }
            firstPtSet = lastPtSet = false;
            break;
        default:
            SkDEBUGFAIL("bad verb");
            return;
=======
            case SkPath::kMove_Verb:
                if (firstPtSet && lastPtSet && firstPt != lastPt) {
                    SkDebugf("{{%1.9g,%1.9g}, {%1.9g,%1.9g}},\n", lastPt.fX, lastPt.fY,
                            firstPt.fX, firstPt.fY);
                    lastPtSet = false;
                }
                firstPt = pts[0];
                firstPtSet = true;
                continue;
            case SkPath::kLine_Verb:
                SkDebugf("{{%1.9g,%1.9g}, {%1.9g,%1.9g}},\n", pts[0].fX, pts[0].fY,
                        pts[1].fX, pts[1].fY);
                lastPt = pts[1];
                lastPtSet = true;
                break;
            case SkPath::kQuad_Verb:
                SkDebugf("{{%1.9g,%1.9g}, {%1.9g,%1.9g}, {%1.9g,%1.9g}},\n",
                        pts[0].fX, pts[0].fY, pts[1].fX, pts[1].fY, pts[2].fX, pts[2].fY);
                lastPt = pts[2];
                lastPtSet = true;
                break;
            case SkPath::kConic_Verb:
                SkDebugf("{{%1.9g,%1.9g}, {%1.9g,%1.9g}, {%1.9g,%1.9g}},  //weight=%1.9g\n",
                        pts[0].fX, pts[0].fY, pts[1].fX, pts[1].fY, pts[2].fX, pts[2].fY,
                        iter.conicWeight());
                lastPt = pts[2];
                lastPtSet = true;
                break;
            case SkPath::kCubic_Verb:
                SkDebugf("{{%1.9g,%1.9g}, {%1.9g,%1.9g}, {%1.9g,%1.9g}, {%1.9g,%1.9g}},\n",
                        pts[0].fX, pts[0].fY, pts[1].fX, pts[1].fY, pts[2].fX, pts[2].fY,
                        pts[3].fX, pts[3].fY);
                lastPt = pts[3];
                lastPtSet = true;
                break;
            case SkPath::kClose_Verb:
                if (firstPtSet && lastPtSet && firstPt != lastPt) {
                    SkDebugf("{{%1.9g,%1.9g}, {%1.9g,%1.9g}},\n", lastPt.fX, lastPt.fY,
                            firstPt.fX, firstPt.fY);
                }
                firstPtSet = lastPtSet = false;
                break;
            default:
                SkDEBUGFAIL("bad verb");
                return;
>>>>>>> miniblink49
        }
    }
    if (firstPtSet && lastPtSet && firstPt != lastPt) {
        SkDebugf("{{%1.9g,%1.9g}, {%1.9g,%1.9g}},\n", lastPt.fX, lastPt.fY,
<<<<<<< HEAD
            firstPt.fX, firstPt.fY);
=======
                firstPt.fX, firstPt.fY);
>>>>>>> miniblink49
    }
}
#endif

<<<<<<< HEAD
void showOp(const SkPathOp op)
{
    switch (op) {
    case kDifference_SkPathOp:
        SkDebugf("op difference\n");
        break;
    case kIntersect_SkPathOp:
        SkDebugf("op intersect\n");
        break;
    case kUnion_SkPathOp:
        SkDebugf("op union\n");
        break;
    case kXOR_SkPathOp:
        SkDebugf("op xor\n");
        break;
    case kReverseDifference_SkPathOp:
        SkDebugf("op reverse difference\n");
        break;
    default:
        SkASSERT(0);
=======
void showOp(const SkPathOp op) {
    switch (op) {
        case kDifference_SkPathOp:
            SkDebugf("op difference\n");
            break;
        case kIntersect_SkPathOp:
            SkDebugf("op intersect\n");
            break;
        case kUnion_SkPathOp:
            SkDebugf("op union\n");
            break;
        case kXOR_SkPathOp:
            SkDebugf("op xor\n");
            break;
        case kReverseDifference_SkPathOp:
            SkDebugf("op reverse difference\n");
            break;
        default:
            SkASSERT(0);
>>>>>>> miniblink49
    }
}

#if DEBUG_SHOW_TEST_NAME
<<<<<<< HEAD
static char hexorator(int x)
{
=======
static char hexorator(int x) {
>>>>>>> miniblink49
    if (x < 10) {
        return x + '0';
    }
    x -= 10;
    SkASSERT(x < 26);
    return x + 'A';
}
#endif

<<<<<<< HEAD
void ShowTestName(PathOpsThreadState* state, int a, int b, int c, int d)
{
=======
void ShowTestName(PathOpsThreadState* state, int a, int b, int c, int d) {
>>>>>>> miniblink49
#if DEBUG_SHOW_TEST_NAME
    state->fSerialNo[0] = hexorator(state->fA);
    state->fSerialNo[1] = hexorator(state->fB);
    state->fSerialNo[2] = hexorator(state->fC);
    state->fSerialNo[3] = hexorator(state->fD);
    state->fSerialNo[4] = hexorator(a);
    state->fSerialNo[5] = hexorator(b);
    state->fSerialNo[6] = hexorator(c);
    state->fSerialNo[7] = hexorator(d);
    state->fSerialNo[8] = '\0';
    SkDebugf("%s\n", state->fSerialNo);
    if (strcmp(state->fSerialNo, state->fKey) == 0) {
        SkDebugf("%s\n", state->fPathStr);
    }
#endif
}

const int bitWidth = 64;
const int bitHeight = 64;

<<<<<<< HEAD
static void scaleMatrix(const SkPath& one, const SkPath& two, SkMatrix& scale)
{
=======
static void scaleMatrix(const SkPath& one, const SkPath& two, SkMatrix& scale) {
>>>>>>> miniblink49
    SkRect larger = one.getBounds();
    larger.join(two.getBounds());
    SkScalar largerWidth = larger.width();
    if (largerWidth < 4) {
        largerWidth = 4;
    }
    SkScalar largerHeight = larger.height();
    if (largerHeight < 4) {
        largerHeight = 4;
    }
    SkScalar hScale = (bitWidth - 2) / largerWidth;
    SkScalar vScale = (bitHeight - 2) / largerHeight;
    scale.reset();
    scale.preScale(hScale, vScale);
<<<<<<< HEAD
    larger.fLeft *= hScale;
    larger.fRight *= hScale;
    larger.fTop *= vScale;
    larger.fBottom *= vScale;
    SkScalar dx = -16000 > larger.fLeft ? -16000 - larger.fLeft
                                        : 16000 < larger.fRight ? 16000 - larger.fRight : 0;
    SkScalar dy = -16000 > larger.fTop ? -16000 - larger.fTop
                                       : 16000 < larger.fBottom ? 16000 - larger.fBottom : 0;
    scale.postTranslate(dx, dy);
}

static int pathsDrawTheSame(SkBitmap& bits, const SkPath& scaledOne, const SkPath& scaledTwo,
    int& error2x2)
{
=======
}

static int pathsDrawTheSame(SkBitmap& bits, const SkPath& scaledOne, const SkPath& scaledTwo,
        int& error2x2) {
>>>>>>> miniblink49
    if (bits.width() == 0) {
        bits.allocN32Pixels(bitWidth * 2, bitHeight);
    }
    SkCanvas canvas(bits);
    canvas.drawColor(SK_ColorWHITE);
    SkPaint paint;
    canvas.save();
    const SkRect& bounds1 = scaledOne.getBounds();
    canvas.translate(-bounds1.fLeft + 1, -bounds1.fTop + 1);
    canvas.drawPath(scaledOne, paint);
    canvas.restore();
    canvas.save();
    canvas.translate(-bounds1.fLeft + 1 + bitWidth, -bounds1.fTop + 1);
    canvas.drawPath(scaledTwo, paint);
    canvas.restore();
    int errors2 = 0;
    int errors = 0;
    for (int y = 0; y < bitHeight - 1; ++y) {
        uint32_t* addr1 = bits.getAddr32(0, y);
        uint32_t* addr2 = bits.getAddr32(0, y + 1);
        uint32_t* addr3 = bits.getAddr32(bitWidth, y);
        uint32_t* addr4 = bits.getAddr32(bitWidth, y + 1);
        for (int x = 0; x < bitWidth - 1; ++x) {
            // count 2x2 blocks
            bool err = addr1[x] != addr3[x];
            if (err) {
                errors2 += addr1[x + 1] != addr3[x + 1]
<<<<<<< HEAD
                    && addr2[x] != addr4[x] && addr2[x + 1] != addr4[x + 1];
=======
                        && addr2[x] != addr4[x] && addr2[x + 1] != addr4[x + 1];
>>>>>>> miniblink49
                errors++;
            }
        }
    }
    error2x2 = errors2;
    return errors;
}

static int pathsDrawTheSame(const SkPath& one, const SkPath& two, SkBitmap& bits, SkPath& scaledOne,
<<<<<<< HEAD
    SkPath& scaledTwo, int& error2x2)
{
=======
        SkPath& scaledTwo, int& error2x2) {
>>>>>>> miniblink49
    SkMatrix scale;
    scaleMatrix(one, two, scale);
    one.transform(scale, &scaledOne);
    two.transform(scale, &scaledTwo);
    return pathsDrawTheSame(bits, scaledOne, scaledTwo, error2x2);
}

<<<<<<< HEAD
bool drawAsciiPaths(const SkPath& one, const SkPath& two, bool drawPaths)
{
=======
bool drawAsciiPaths(const SkPath& one, const SkPath& two, bool drawPaths) {
>>>>>>> miniblink49
    if (!drawPaths) {
        return true;
    }
    const SkRect& bounds1 = one.getBounds();
    const SkRect& bounds2 = two.getBounds();
    SkRect larger = bounds1;
    larger.join(bounds2);
    SkBitmap bits;
    char out[256];
    int bitWidth = SkScalarCeilToInt(larger.width()) + 2;
<<<<<<< HEAD
    if (bitWidth * 2 + 1 >= (int)sizeof(out)) {
        return false;
    }
    int bitHeight = SkScalarCeilToInt(larger.height()) + 2;
    if (bitHeight >= (int)sizeof(out)) {
=======
    if (bitWidth * 2 + 1 >= (int) sizeof(out)) {
        return false;
    }
    int bitHeight = SkScalarCeilToInt(larger.height()) + 2;
    if (bitHeight >= (int) sizeof(out)) {
>>>>>>> miniblink49
        return false;
    }
    bits.allocN32Pixels(bitWidth * 2, bitHeight);
    SkCanvas canvas(bits);
    canvas.drawColor(SK_ColorWHITE);
    SkPaint paint;
    canvas.save();
    canvas.translate(-bounds1.fLeft + 1, -bounds1.fTop + 1);
    canvas.drawPath(one, paint);
    canvas.restore();
    canvas.save();
    canvas.translate(-bounds1.fLeft + 1 + bitWidth, -bounds1.fTop + 1);
    canvas.drawPath(two, paint);
    canvas.restore();
    for (int y = 0; y < bitHeight; ++y) {
        uint32_t* addr1 = bits.getAddr32(0, y);
        int x;
        char* outPtr = out;
        for (x = 0; x < bitWidth; ++x) {
<<<<<<< HEAD
            *outPtr++ = addr1[x] == (uint32_t)-1 ? '_' : 'x';
        }
        *outPtr++ = '|';
        for (x = bitWidth; x < bitWidth * 2; ++x) {
            *outPtr++ = addr1[x] == (uint32_t)-1 ? '_' : 'x';
=======
            *outPtr++ = addr1[x] == (uint32_t) -1 ? '_' : 'x';
        }
        *outPtr++ = '|';
        for (x = bitWidth; x < bitWidth * 2; ++x) {
            *outPtr++ = addr1[x] == (uint32_t) -1 ? '_' : 'x';
>>>>>>> miniblink49
        }
        *outPtr++ = '\0';
        SkDebugf("%s\n", out);
    }
    return true;
}

int comparePaths(skiatest::Reporter* reporter, const char* filename, const SkPath& one,
<<<<<<< HEAD
    const SkPath& two, SkBitmap& bitmap)
{
    int errors2x2;
    SkPath scaledOne, scaledTwo;
    (void)pathsDrawTheSame(one, two, bitmap, scaledOne, scaledTwo, errors2x2);
=======
        const SkPath& two, SkBitmap& bitmap) {
    int errors2x2;
    SkPath scaledOne, scaledTwo;
    (void) pathsDrawTheSame(one, two, bitmap, scaledOne, scaledTwo, errors2x2);
>>>>>>> miniblink49
    if (errors2x2 == 0) {
        return 0;
    }
    const int MAX_ERRORS = 9;
    return errors2x2 > MAX_ERRORS ? errors2x2 : 0;
}

<<<<<<< HEAD
static SkTDArray<SkPathOp> gTestOp;

static void showPathOpPath(const char* testName, const SkPath& one, const SkPath& two,
    const SkPath& a, const SkPath& b, const SkPath& scaledOne, const SkPath& scaledTwo,
    const SkPathOp shapeOp, const SkMatrix& scale)
{
    SkASSERT((unsigned)shapeOp < SK_ARRAY_COUNT(opStrs));
    if (!testName) {
        testName = "xOp";
    }
    SkDebugf("static void %s_%s(skiatest::Reporter* reporter, const char* filename) {\n",
        testName, opSuffixes[shapeOp]);
    *gTestOp.append() = shapeOp;
=======
const int gTestFirst = 41;
static int gTestNo = gTestFirst;
static SkTDArray<SkPathOp> gTestOp;

static void showPathOpPath(const char* testName, const SkPath& one, const SkPath& two,
        const SkPath& a, const SkPath& b, const SkPath& scaledOne, const SkPath& scaledTwo,
        const SkPathOp shapeOp, const SkMatrix& scale) {
    SkASSERT((unsigned) shapeOp < SK_ARRAY_COUNT(opStrs));
    if (!testName) {
        testName = "xOp";
    }
    SkDebugf("static void %s%d%s(skiatest::Reporter* reporter, const char* filename) {\n",
        testName, gTestNo, opSuffixes[shapeOp]);
    *gTestOp.append() = shapeOp;
    ++gTestNo;
>>>>>>> miniblink49
    SkDebugf("    SkPath path, pathB;\n");
    SkPathOpsDebug::ShowOnePath(a, "path", false);
    SkPathOpsDebug::ShowOnePath(b, "pathB", false);
    SkDebugf("    testPathOp(reporter, path, pathB, %s, filename);\n", opStrs[shapeOp]);
    SkDebugf("}\n");
<<<<<<< HEAD
    drawAsciiPaths(scaledOne, scaledTwo, true);
=======
    drawAsciiPaths(scaledOne, scaledTwo, false);
}

void ShowTestArray(const char* testName) {
    if (!testName) {
        testName = "xOp";
    }
    for (int x = gTestFirst; x < gTestNo; ++x) {
        SkDebugf("    TEST(%s%d%s),\n", testName, x, opSuffixes[gTestOp[x - gTestFirst]]);
    }
>>>>>>> miniblink49
}

SK_DECLARE_STATIC_MUTEX(compareDebugOut3);

static int comparePaths(skiatest::Reporter* reporter, const char* testName, const SkPath& one,
<<<<<<< HEAD
    const SkPath& scaledOne, const SkPath& two, const SkPath& scaledTwo, SkBitmap& bitmap,
    const SkPath& a, const SkPath& b, const SkPathOp shapeOp, const SkMatrix& scale,
    bool expectSuccess)
{
    int errors2x2;
    const int MAX_ERRORS = 8;
    (void)pathsDrawTheSame(bitmap, scaledOne, scaledTwo, errors2x2);
=======
        const SkPath& scaledOne, const SkPath& two, const SkPath& scaledTwo, SkBitmap& bitmap,
        const SkPath& a, const SkPath& b, const SkPathOp shapeOp, const SkMatrix& scale,
        bool expectSuccess) {
    int errors2x2;
    const int MAX_ERRORS = 8;
    (void) pathsDrawTheSame(bitmap, scaledOne, scaledTwo, errors2x2);
>>>>>>> miniblink49
    if (!expectSuccess) {
        if (errors2x2 < MAX_ERRORS) {
            REPORTER_ASSERT(reporter, 0);
        }
        return 0;
    }
    if (errors2x2 == 0) {
        return 0;
    }
    if (errors2x2 >= MAX_ERRORS) {
        SkAutoMutexAcquire autoM(compareDebugOut3);
        showPathOpPath(testName, one, two, a, b, scaledOne, scaledTwo, shapeOp, scale);
        SkDebugf("\n/*");
        REPORTER_ASSERT(reporter, 0);
        SkDebugf(" */\n");
    }
    return errors2x2 >= MAX_ERRORS ? errors2x2 : 0;
}

// Default values for when reporter->verbose() is false.
static int testNumber = 55;
static const char* testName = "pathOpTest";

<<<<<<< HEAD
static void writeTestName(const char* nameSuffix, SkMemoryWStream& outFile)
{
=======
static void writeTestName(const char* nameSuffix, SkMemoryWStream& outFile) {
>>>>>>> miniblink49
    outFile.writeText(testName);
    outFile.writeDecAsText(testNumber);
    ++testNumber;
    if (nameSuffix) {
        outFile.writeText(nameSuffix);
    }
}

static void outputToStream(const char* pathStr, const char* pathPrefix, const char* nameSuffix,
<<<<<<< HEAD
    const char* testFunction, bool twoPaths, SkMemoryWStream& outFile)
{
=======
        const char* testFunction, bool twoPaths, SkMemoryWStream& outFile) {
>>>>>>> miniblink49
#if 0
    outFile.writeText("\n<div id=\"");
    writeTestName(nameSuffix, outFile);
    outFile.writeText("\">\n");
    if (pathPrefix) {
        outFile.writeText(pathPrefix);
    }
    outFile.writeText(pathStr);
    outFile.writeText("</div>\n\n");

    outFile.writeText(marker);
    outFile.writeText("    ");
    writeTestName(nameSuffix, outFile);
    outFile.writeText(",\n\n\n");
#endif
    outFile.writeText("static void ");
    writeTestName(nameSuffix, outFile);
    outFile.writeText("(skiatest::Reporter* reporter) {\n    SkPath path");
    if (twoPaths) {
        outFile.writeText(", pathB");
    }
    outFile.writeText(";\n");
    if (pathPrefix) {
        outFile.writeText(pathPrefix);
    }
    outFile.writeText(pathStr);
    outFile.writeText("    ");
    outFile.writeText(testFunction);
    outFile.writeText("\n}\n\n");
#if 0
    outFile.writeText("static void (*firstTest)() = ");
    writeTestName(nameSuffix, outFile);
    outFile.writeText(";\n\n");

    outFile.writeText("static struct {\n");
    outFile.writeText("    void (*fun)();\n");
    outFile.writeText("    const char* str;\n");
    outFile.writeText("} tests[] = {\n");
    outFile.writeText("    TEST(");
    writeTestName(nameSuffix, outFile);
    outFile.writeText("),\n");
#endif
    outFile.flush();
}

SK_DECLARE_STATIC_MUTEX(simplifyDebugOut);

bool testSimplify(SkPath& path, bool useXor, SkPath& out, PathOpsThreadState& state,
<<<<<<< HEAD
    const char* pathStr)
{
=======
                  const char* pathStr) {
>>>>>>> miniblink49
    SkPath::FillType fillType = useXor ? SkPath::kEvenOdd_FillType : SkPath::kWinding_FillType;
    path.setFillType(fillType);
    state.fReporter->bumpTestCount();
    if (!Simplify(path, &out)) {
        SkDebugf("%s did not expect failure\n", __FUNCTION__);
        REPORTER_ASSERT(state.fReporter, 0);
        return false;
    }
    if (!state.fReporter->verbose()) {
        return true;
    }
<<<<<<< HEAD
    int result = comparePaths(state.fReporter, nullptr, path, out, *state.fBitmap);
=======
    int result = comparePaths(state.fReporter, NULL, path, out, *state.fBitmap);
>>>>>>> miniblink49
    if (result) {
        SkAutoMutexAcquire autoM(simplifyDebugOut);
        char temp[8192];
        sk_bzero(temp, sizeof(temp));
        SkMemoryWStream stream(temp, sizeof(temp));
<<<<<<< HEAD
        const char* pathPrefix = nullptr;
        const char* nameSuffix = nullptr;
=======
        const char* pathPrefix = NULL;
        const char* nameSuffix = NULL;
>>>>>>> miniblink49
        if (fillType == SkPath::kEvenOdd_FillType) {
            pathPrefix = "    path.setFillType(SkPath::kEvenOdd_FillType);\n";
            nameSuffix = "x";
        }
        const char testFunction[] = "testSimplify(reporter, path);";
        outputToStream(pathStr, pathPrefix, nameSuffix, testFunction, false, stream);
        SkDebugf("%s", temp);
        REPORTER_ASSERT(state.fReporter, 0);
    }
    state.fReporter->bumpTestCount();
    return result == 0;
}

static bool inner_simplify(skiatest::Reporter* reporter, const SkPath& path, const char* filename,
<<<<<<< HEAD
    bool checkFail)
{
=======
        bool checkFail) {
>>>>>>> miniblink49
#if 0 && DEBUG_SHOW_TEST_NAME
    showPathData(path);
#endif
    SkPath out;
    if (!Simplify(path, &out)) {
        SkDebugf("%s did not expect %s failure\n", __FUNCTION__, filename);
        REPORTER_ASSERT(reporter, 0);
        return false;
    }
    SkBitmap bitmap;
    int errors = comparePaths(reporter, filename, path, out, bitmap);
    if (!checkFail) {
        if (!errors) {
            SkDebugf("%s failing test %s now succeeds\n", __FUNCTION__, filename);
            REPORTER_ASSERT(reporter, 0);
            return false;
        }
    } else if (errors) {
        REPORTER_ASSERT(reporter, 0);
    }
    reporter->bumpTestCount();
    return errors == 0;
}

<<<<<<< HEAD
bool testSimplify(skiatest::Reporter* reporter, const SkPath& path, const char* filename)
{
=======
bool testSimplify(skiatest::Reporter* reporter, const SkPath& path, const char* filename) {
>>>>>>> miniblink49
    return inner_simplify(reporter, path, filename, true);
}

bool testSimplifyCheck(skiatest::Reporter* reporter, const SkPath& path, const char* filename,
<<<<<<< HEAD
    bool checkFail)
{
=======
        bool checkFail) {
>>>>>>> miniblink49
    return inner_simplify(reporter, path, filename, checkFail);
}

#if DEBUG_SHOW_TEST_NAME
<<<<<<< HEAD
static void showName(const SkPath& a, const SkPath& b, const SkPathOp shapeOp)
{
=======
static void showName(const SkPath& a, const SkPath& b, const SkPathOp shapeOp) {
>>>>>>> miniblink49
    SkDebugf("\n");
    showPathData(a);
    showOp(shapeOp);
    showPathData(b);
}
#endif

<<<<<<< HEAD
bool OpDebug(const SkPath& one, const SkPath& two, SkPathOp op, SkPath* result SkDEBUGPARAMS(bool skipAssert) SkDEBUGPARAMS(const char* testName));

static bool innerPathOp(skiatest::Reporter* reporter, const SkPath& a, const SkPath& b,
    const SkPathOp shapeOp, const char* testName, bool expectSuccess, bool skipAssert)
{
=======
bool OpDebug(const SkPath& one, const SkPath& two, SkPathOp op, SkPath* result, bool expectSuccess);

static bool innerPathOp(skiatest::Reporter* reporter, const SkPath& a, const SkPath& b,
        const SkPathOp shapeOp, const char* testName, bool expectSuccess) {
>>>>>>> miniblink49
#if 0 && DEBUG_SHOW_TEST_NAME
    showName(a, b, shapeOp);
#endif
    SkPath out;
<<<<<<< HEAD
    if (!OpDebug(a, b, shapeOp, &out SkDEBUGPARAMS(skipAssert) SkDEBUGPARAMS(testName))) {
        if (expectSuccess) {
            SkDebugf("%s did not expect failure\n", __FUNCTION__);
            REPORTER_ASSERT(reporter, 0);
        }
=======
    if (!OpDebug(a, b, shapeOp, &out, expectSuccess)) {
        SkDebugf("%s did not expect failure\n", __FUNCTION__);
        REPORTER_ASSERT(reporter, 0);
>>>>>>> miniblink49
        return false;
    }
    if (!reporter->verbose()) {
        return true;
    }
    SkPath pathOut, scaledPathOut;
    SkRegion rgnA, rgnB, openClip, rgnOut;
    openClip.setRect(-16000, -16000, 16000, 16000);
    rgnA.setPath(a, openClip);
    rgnB.setPath(b, openClip);
<<<<<<< HEAD
    rgnOut.op(rgnA, rgnB, (SkRegion::Op)shapeOp);
=======
    rgnOut.op(rgnA, rgnB, (SkRegion::Op) shapeOp);
>>>>>>> miniblink49
    rgnOut.getBoundaryPath(&pathOut);

    SkMatrix scale;
    scaleMatrix(a, b, scale);
    SkRegion scaledRgnA, scaledRgnB, scaledRgnOut;
    SkPath scaledA, scaledB;
    scaledA.addPath(a, scale);
    scaledA.setFillType(a.getFillType());
    scaledB.addPath(b, scale);
    scaledB.setFillType(b.getFillType());
    scaledRgnA.setPath(scaledA, openClip);
    scaledRgnB.setPath(scaledB, openClip);
<<<<<<< HEAD
    scaledRgnOut.op(scaledRgnA, scaledRgnB, (SkRegion::Op)shapeOp);
=======
    scaledRgnOut.op(scaledRgnA, scaledRgnB, (SkRegion::Op) shapeOp);
>>>>>>> miniblink49
    scaledRgnOut.getBoundaryPath(&scaledPathOut);
    SkBitmap bitmap;
    SkPath scaledOut;
    scaledOut.addPath(out, scale);
    scaledOut.setFillType(out.getFillType());
    int result = comparePaths(reporter, testName, pathOut, scaledPathOut, out, scaledOut, bitmap,
<<<<<<< HEAD
        a, b, shapeOp, scale, expectSuccess);
=======
            a, b, shapeOp, scale, expectSuccess);
>>>>>>> miniblink49
    reporter->bumpTestCount();
    return result == 0;
}

bool testPathOp(skiatest::Reporter* reporter, const SkPath& a, const SkPath& b,
<<<<<<< HEAD
    const SkPathOp shapeOp, const char* testName)
{
    return innerPathOp(reporter, a, b, shapeOp, testName, true, false);
}

bool testPathOpCheck(skiatest::Reporter* reporter, const SkPath& a, const SkPath& b,
    const SkPathOp shapeOp, const char* testName, bool checkFail)
{
    return innerPathOp(reporter, a, b, shapeOp, testName, checkFail, false);
}

bool testPathOpFailCheck(skiatest::Reporter* reporter, const SkPath& a, const SkPath& b,
    const SkPathOp shapeOp, const char* testName)
{
    return innerPathOp(reporter, a, b, shapeOp, testName, false, false);
}

bool testPathSkipAssertOp(skiatest::Reporter* reporter, const SkPath& a, const SkPath& b,
    const SkPathOp shapeOp, const char* testName)
{
    return innerPathOp(reporter, a, b, shapeOp, testName, true, true);
}

bool testPathFailSkipAssertOp(skiatest::Reporter* reporter, const SkPath& a, const SkPath& b,
    const SkPathOp shapeOp, const char* testName)
{
    return innerPathOp(reporter, a, b, shapeOp, testName, false, true);
}

bool testPathFailOp(skiatest::Reporter* reporter, const SkPath& a, const SkPath& b,
    const SkPathOp shapeOp, const char* testName)
{
=======
        const SkPathOp shapeOp, const char* testName) {
    return innerPathOp(reporter, a, b, shapeOp, testName, true);
}

bool testPathOpCheck(skiatest::Reporter* reporter, const SkPath& a, const SkPath& b,
        const SkPathOp shapeOp, const char* testName, bool checkFail) {
    return innerPathOp(reporter, a, b, shapeOp, testName, checkFail);
}

bool testPathOpFailCheck(skiatest::Reporter* reporter, const SkPath& a, const SkPath& b,
        const SkPathOp shapeOp, const char* testName) {
    return innerPathOp(reporter, a, b, shapeOp, testName, false);
}

bool testPathFailOp(skiatest::Reporter* reporter, const SkPath& a, const SkPath& b,
                 const SkPathOp shapeOp, const char* testName) {
>>>>>>> miniblink49
#if DEBUG_SHOW_TEST_NAME
    showName(a, b, shapeOp);
#endif
    SkPath orig;
    orig.lineTo(54, 43);
    SkPath out = orig;
<<<<<<< HEAD
    if (Op(a, b, shapeOp, &out)) {
=======
    if (Op(a, b, shapeOp, &out) ) {
>>>>>>> miniblink49
        SkDebugf("%s test is expected to fail\n", __FUNCTION__);
        REPORTER_ASSERT(reporter, 0);
        return false;
    }
    SkASSERT(out == orig);
    return true;
}

SK_DECLARE_STATIC_MUTEX(gMutex);

<<<<<<< HEAD
void initializeTests(skiatest::Reporter* reporter, const char* test)
{
#if 0 // doesn't work yet
=======
void initializeTests(skiatest::Reporter* reporter, const char* test) {
#if 0  // doesn't work yet
>>>>>>> miniblink49
    SK_CONF_SET("images.jpeg.suppressDecoderWarnings", true);
    SK_CONF_SET("images.png.suppressDecoderWarnings", true);
#endif
    if (reporter->verbose()) {
        SkAutoMutexAcquire lock(gMutex);
        testName = test;
        size_t testNameSize = strlen(test);
        SkFILEStream inFile("../../experimental/Intersection/op.htm");
        if (inFile.isValid()) {
            SkTDArray<char> inData;
<<<<<<< HEAD
            inData.setCount((int)inFile.getLength());
            size_t inLen = inData.count();
            inFile.read(inData.begin(), inLen);
            inFile.setPath(nullptr);
=======
            inData.setCount((int) inFile.getLength());
            size_t inLen = inData.count();
            inFile.read(inData.begin(), inLen);
            inFile.setPath(NULL);
>>>>>>> miniblink49
            char* insert = strstr(inData.begin(), marker);
            if (insert) {
                insert += sizeof(marker) - 1;
                const char* numLoc = insert + 4 /* indent spaces */ + testNameSize - 1;
                testNumber = atoi(numLoc) + 1;
            }
        }
    }
}

<<<<<<< HEAD
void outputProgress(char* ramStr, const char* pathStr, SkPath::FillType pathFillType)
{
    const char testFunction[] = "testSimplify(path);";
    const char* pathPrefix = nullptr;
    const char* nameSuffix = nullptr;
=======
void outputProgress(char* ramStr, const char* pathStr, SkPath::FillType pathFillType) {
    const char testFunction[] = "testSimplify(path);";
    const char* pathPrefix = NULL;
    const char* nameSuffix = NULL;
>>>>>>> miniblink49
    if (pathFillType == SkPath::kEvenOdd_FillType) {
        pathPrefix = "    path.setFillType(SkPath::kEvenOdd_FillType);\n";
        nameSuffix = "x";
    }
    SkMemoryWStream rRamStream(ramStr, PATH_STR_SIZE);
    outputToStream(pathStr, pathPrefix, nameSuffix, testFunction, false, rRamStream);
}

<<<<<<< HEAD
void outputProgress(char* ramStr, const char* pathStr, SkPathOp op)
{
    const char testFunction[] = "testOp(path);";
    SkASSERT((size_t)op < SK_ARRAY_COUNT(opSuffixes));
    const char* nameSuffix = opSuffixes[op];
    SkMemoryWStream rRamStream(ramStr, PATH_STR_SIZE);
    outputToStream(pathStr, nullptr, nameSuffix, testFunction, true, rRamStream);
}

void RunTestSet(skiatest::Reporter* reporter, TestDesc tests[], size_t count,
    void (*firstTest)(skiatest::Reporter*, const char* filename),
    void (*skipTest)(skiatest::Reporter*, const char* filename),
    void (*stopTest)(skiatest::Reporter*, const char* filename), bool reverse)
{
=======
void outputProgress(char* ramStr, const char* pathStr, SkPathOp op) {
    const char testFunction[] = "testOp(path);";
    SkASSERT((size_t) op < SK_ARRAY_COUNT(opSuffixes));
    const char* nameSuffix = opSuffixes[op];
    SkMemoryWStream rRamStream(ramStr, PATH_STR_SIZE);
    outputToStream(pathStr, NULL, nameSuffix, testFunction, true, rRamStream);
}

void RunTestSet(skiatest::Reporter* reporter, TestDesc tests[], size_t count,
                void (*firstTest)(skiatest::Reporter* , const char* filename),
                void (*skipTest)(skiatest::Reporter* , const char* filename),
                void (*stopTest)(skiatest::Reporter* , const char* filename), bool reverse) {
>>>>>>> miniblink49
    size_t index;
    if (firstTest) {
        index = count - 1;
        while (index > 0 && tests[index].fun != firstTest) {
            --index;
        }
#if DEBUG_SHOW_TEST_NAME
        SkDebugf("\n<div id=\"%s\">\n", tests[index].str);
#endif
        (*tests[index].fun)(reporter, tests[index].str);
        if (tests[index].fun == stopTest) {
            return;
        }
    }
    index = reverse ? count - 1 : 0;
    size_t last = reverse ? 0 : count - 1;
    bool foundSkip = !skipTest;
    do {
        if (tests[index].fun == skipTest) {
            foundSkip = true;
        }
        if (foundSkip && tests[index].fun != firstTest) {
<<<<<<< HEAD
#if DEBUG_SHOW_TEST_NAME
            SkDebugf("\n<div id=\"%s\">\n", tests[index].str);
#endif
=======
    #if DEBUG_SHOW_TEST_NAME
            SkDebugf("\n<div id=\"%s\">\n", tests[index].str);
    #endif
>>>>>>> miniblink49
            (*tests[index].fun)(reporter, tests[index].str);
        }
        if (tests[index].fun == stopTest || index == last) {
            break;
        }
        index += reverse ? -1 : 1;
    } while (true);
#if DEBUG_SHOW_TEST_NAME
    SkDebugf(
<<<<<<< HEAD
        "\n"
        "</div>\n"
        "\n"
        "<script type=\"text/javascript\">\n"
        "\n"
        "var testDivs = [\n");
=======
            "\n"
            "</div>\n"
            "\n"
            "<script type=\"text/javascript\">\n"
            "\n"
            "var testDivs = [\n"
    );
>>>>>>> miniblink49
    index = reverse ? count - 1 : 0;
    last = reverse ? 0 : count - 1;
    foundSkip = !skipTest;
    do {
        if (tests[index].fun == skipTest) {
            foundSkip = true;
        }
        if (foundSkip && tests[index].fun != firstTest) {
            SkDebugf("    %s,\n", tests[index].str);
        }
        if (tests[index].fun == stopTest || index == last) {
            break;
        }
        index += reverse ? -1 : 1;
    } while (true);
#endif
}
