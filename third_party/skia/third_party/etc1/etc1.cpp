// Copyright 2009 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//////////////////////////////////////////////////////////////////////////////////////////

// This is a fork of the AOSP project ETC1 codec. The original code can be found
// at the following web site:
// https://android.googlesource.com/platform/frameworks/native/+/master/opengl/include/ETC1/

//////////////////////////////////////////////////////////////////////////////////////////

#include "etc1.h"

#include <cstring>

/* From http://www.khronos.org/registry/gles/extensions/OES/OES_compressed_ETC1_RGB8_texture.txt

 The number of bits that represent a 4x4 texel block is 64 bits if
 <internalformat> is given by ETC1_RGB8_OES.

 The data for a block is a number of bytes,

 {q0, q1, q2, q3, q4, q5, q6, q7}

 where byte q0 is located at the lowest memory address and q7 at
 the highest. The 64 bits specifying the block is then represented
 by the following 64 bit integer:

 int64bit = 256*(256*(256*(256*(256*(256*(256*q0+q1)+q2)+q3)+q4)+q5)+q6)+q7;

 ETC1_RGB8_OES:

 a) bit layout in bits 63 through 32 if diffbit = 0

 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48
 -----------------------------------------------
 | base col1 | base col2 | base col1 | base col2 |
 | R1 (4bits)| R2 (4bits)| G1 (4bits)| G2 (4bits)|
 -----------------------------------------------

 47 46 45 44 43 42 41 40 39 38 37 36 35 34  33  32
 ---------------------------------------------------
 | base col1 | base col2 | table  | table  |diff|flip|
 | B1 (4bits)| B2 (4bits)| cw 1   | cw 2   |bit |bit |
 ---------------------------------------------------


 b) bit layout in bits 63 through 32 if diffbit = 1

 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48
 -----------------------------------------------
 | base col1    | dcol 2 | base col1    | dcol 2 |
 | R1' (5 bits) | dR2    | G1' (5 bits) | dG2    |
 -----------------------------------------------

 47 46 45 44 43 42 41 40 39 38 37 36 35 34  33  32
 ---------------------------------------------------
 | base col 1   | dcol 2 | table  | table  |diff|flip|
 | B1' (5 bits) | dB2    | cw 1   | cw 2   |bit |bit |
 ---------------------------------------------------


 c) bit layout in bits 31 through 0 (in both cases)

 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16
 -----------------------------------------------
 |       most significant pixel index bits       |
 | p| o| n| m| l| k| j| i| h| g| f| e| d| c| b| a|
 -----------------------------------------------

 15 14 13 12 11 10  9  8  7  6  5  4  3   2   1  0
 --------------------------------------------------
 |         least significant pixel index bits       |
 | p| o| n| m| l| k| j| i| h| g| f| e| d| c | b | a |
 --------------------------------------------------


 Add table 3.17.2: Intensity modifier sets for ETC1 compressed textures:

 table codeword                modifier table
 ------------------        ----------------------
 0                     -8  -2  2   8
 1                    -17  -5  5  17
 2                    -29  -9  9  29
 3                    -42 -13 13  42
 4                    -60 -18 18  60
 5                    -80 -24 24  80
 6                   -106 -33 33 106
 7                   -183 -47 47 183


 Add table 3.17.3 Mapping from pixel index values to modifier values for
 ETC1 compressed textures:

 pixel index value
 ---------------
 msb     lsb           resulting modifier value
 -----   -----          -------------------------
 1       1            -b (large negative value)
 1       0            -a (small negative value)
 0       0             a (small positive value)
 0       1             b (large positive value)


 */

static const int kModifierTable[] = {
<<<<<<< HEAD
    /* 0 */ 2, 8, -2, -8,
    /* 1 */ 5, 17, -5, -17,
    /* 2 */ 9, 29, -9, -29,
    /* 3 */ 13, 42, -13, -42,
    /* 4 */ 18, 60, -18, -60,
    /* 5 */ 24, 80, -24, -80,
    /* 6 */ 33, 106, -33, -106,
    /* 7 */ 47, 183, -47, -183
};

static const int kLookup[8] = { 0, 1, 2, 3, -4, -3, -2, -1 };

static inline etc1_byte clamp(int x)
{
    return (etc1_byte)(x >= 0 ? (x < 255 ? x : 255) : 0);
}

static inline int convert4To8(int b)
{
=======
/* 0 */2, 8, -2, -8,
/* 1 */5, 17, -5, -17,
/* 2 */9, 29, -9, -29,
/* 3 */13, 42, -13, -42,
/* 4 */18, 60, -18, -60,
/* 5 */24, 80, -24, -80,
/* 6 */33, 106, -33, -106,
/* 7 */47, 183, -47, -183 };

static const int kLookup[8] = { 0, 1, 2, 3, -4, -3, -2, -1 };

static inline etc1_byte clamp(int x) {
    return (etc1_byte) (x >= 0 ? (x < 255 ? x : 255) : 0);
}

static
inline int convert4To8(int b) {
>>>>>>> miniblink49
    int c = b & 0xf;
    return (c << 4) | c;
}

<<<<<<< HEAD
static inline int convert5To8(int b)
{
=======
static
inline int convert5To8(int b) {
>>>>>>> miniblink49
    int c = b & 0x1f;
    return (c << 3) | (c >> 2);
}

<<<<<<< HEAD
static inline int convert6To8(int b)
{
=======
static
inline int convert6To8(int b) {
>>>>>>> miniblink49
    int c = b & 0x3f;
    return (c << 2) | (c >> 4);
}

<<<<<<< HEAD
static inline int divideBy255(int d)
{
    return (d + 128 + (d >> 8)) >> 8;
}

static inline int convert8To4(int b)
{
=======
static
inline int divideBy255(int d) {
    return (d + 128 + (d >> 8)) >> 8;
}

static
inline int convert8To4(int b) {
>>>>>>> miniblink49
    int c = b & 0xff;
    return divideBy255(c * 15);
}

<<<<<<< HEAD
static inline int convert8To5(int b)
{
=======
static
inline int convert8To5(int b) {
>>>>>>> miniblink49
    int c = b & 0xff;
    return divideBy255(c * 31);
}

<<<<<<< HEAD
static inline int convertDiff(int base, int diff)
{
    return convert5To8((0x1f & base) + kLookup[0x7 & diff]);
}

static void decode_subblock(etc1_byte* pOut, int r, int g, int b, const int* table,
    etc1_uint32 low, bool second, bool flipped)
{
=======
static
inline int convertDiff(int base, int diff) {
    return convert5To8((0x1f & base) + kLookup[0x7 & diff]);
}

static
void decode_subblock(etc1_byte* pOut, int r, int g, int b, const int* table,
        etc1_uint32 low, bool second, bool flipped) {
>>>>>>> miniblink49
    int baseX = 0;
    int baseY = 0;
    if (second) {
        if (flipped) {
            baseY = 2;
        } else {
            baseX = 2;
        }
    }
    for (int i = 0; i < 8; i++) {
        int x, y;
        if (flipped) {
            x = baseX + (i >> 1);
            y = baseY + (i & 1);
        } else {
            x = baseX + (i >> 2);
            y = baseY + (i & 3);
        }
        int k = y + (x * 4);
        int offset = ((low >> k) & 1) | ((low >> (k + 15)) & 2);
        int delta = table[offset];
        etc1_byte* q = pOut + 3 * (x + 4 * y);
        *q++ = clamp(r + delta);
        *q++ = clamp(g + delta);
        *q++ = clamp(b + delta);
    }
}

// Input is an ETC1 compressed version of the data.
// Output is a 4 x 4 square of 3-byte pixels in form R, G, B

<<<<<<< HEAD
void etc1_decode_block(const etc1_byte* pIn, etc1_byte* pOut)
{
=======
void etc1_decode_block(const etc1_byte* pIn, etc1_byte* pOut) {
>>>>>>> miniblink49
    etc1_uint32 high = (pIn[0] << 24) | (pIn[1] << 16) | (pIn[2] << 8) | pIn[3];
    etc1_uint32 low = (pIn[4] << 24) | (pIn[5] << 16) | (pIn[6] << 8) | pIn[7];
    int r1, r2, g1, g2, b1, b2;
    if (high & 2) {
        // differential
        int rBase = high >> 27;
        int gBase = high >> 19;
        int bBase = high >> 11;
        r1 = convert5To8(rBase);
        r2 = convertDiff(rBase, high >> 24);
        g1 = convert5To8(gBase);
        g2 = convertDiff(gBase, high >> 16);
        b1 = convert5To8(bBase);
        b2 = convertDiff(bBase, high >> 8);
    } else {
        // not differential
        r1 = convert4To8(high >> 28);
        r2 = convert4To8(high >> 24);
        g1 = convert4To8(high >> 20);
        g2 = convert4To8(high >> 16);
        b1 = convert4To8(high >> 12);
        b2 = convert4To8(high >> 8);
    }
    int tableIndexA = 7 & (high >> 5);
    int tableIndexB = 7 & (high >> 2);
    const int* tableA = kModifierTable + tableIndexA * 4;
    const int* tableB = kModifierTable + tableIndexB * 4;
    bool flipped = (high & 1) != 0;
    decode_subblock(pOut, r1, g1, b1, tableA, low, false, flipped);
    decode_subblock(pOut, r2, g2, b2, tableB, low, true, flipped);
}

typedef struct {
    etc1_uint32 high;
    etc1_uint32 low;
    etc1_uint32 score; // Lower is more accurate
} etc_compressed;

<<<<<<< HEAD
static inline void take_best(etc_compressed* a, const etc_compressed* b)
{
=======
static
inline void take_best(etc_compressed* a, const etc_compressed* b) {
>>>>>>> miniblink49
    if (a->score > b->score) {
        *a = *b;
    }
}

<<<<<<< HEAD
static void etc_average_colors_subblock(const etc1_byte* pIn, etc1_uint32 inMask,
    etc1_byte* pColors, bool flipped, bool second)
{
=======
static
void etc_average_colors_subblock(const etc1_byte* pIn, etc1_uint32 inMask,
        etc1_byte* pColors, bool flipped, bool second) {
>>>>>>> miniblink49
    int r = 0;
    int g = 0;
    int b = 0;

    if (flipped) {
        int by = 0;
        if (second) {
            by = 2;
        }
        for (int y = 0; y < 2; y++) {
            int yy = by + y;
            for (int x = 0; x < 4; x++) {
                int i = x + 4 * yy;
                if (inMask & (1 << i)) {
                    const etc1_byte* p = pIn + i * 3;
                    r += *(p++);
                    g += *(p++);
                    b += *(p++);
                }
            }
        }
    } else {
        int bx = 0;
        if (second) {
            bx = 2;
        }
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 2; x++) {
                int xx = bx + x;
                int i = xx + 4 * y;
                if (inMask & (1 << i)) {
                    const etc1_byte* p = pIn + i * 3;
                    r += *(p++);
                    g += *(p++);
                    b += *(p++);
                }
            }
        }
    }
    pColors[0] = (etc1_byte)((r + 4) >> 3);
    pColors[1] = (etc1_byte)((g + 4) >> 3);
    pColors[2] = (etc1_byte)((b + 4) >> 3);
}

<<<<<<< HEAD
static inline int square(int x)
{
=======
static
inline int square(int x) {
>>>>>>> miniblink49
    return x * x;
}

static etc1_uint32 chooseModifier(const etc1_byte* pBaseColors,
<<<<<<< HEAD
    const etc1_byte* pIn, etc1_uint32* pLow, int bitIndex,
    const int* pModifierTable)
{
=======
        const etc1_byte* pIn, etc1_uint32 *pLow, int bitIndex,
        const int* pModifierTable) {
>>>>>>> miniblink49
    etc1_uint32 bestScore = ~0;
    int bestIndex = 0;
    int pixelR = pIn[0];
    int pixelG = pIn[1];
    int pixelB = pIn[2];
    int r = pBaseColors[0];
    int g = pBaseColors[1];
    int b = pBaseColors[2];
    for (int i = 0; i < 4; i++) {
        int modifier = pModifierTable[i];
        int decodedG = clamp(g + modifier);
<<<<<<< HEAD
        etc1_uint32 score = (etc1_uint32)(6 * square(decodedG - pixelG));
=======
        etc1_uint32 score = (etc1_uint32) (6 * square(decodedG - pixelG));
>>>>>>> miniblink49
        if (score >= bestScore) {
            continue;
        }
        int decodedR = clamp(r + modifier);
<<<<<<< HEAD
        score += (etc1_uint32)(3 * square(decodedR - pixelR));
=======
        score += (etc1_uint32) (3 * square(decodedR - pixelR));
>>>>>>> miniblink49
        if (score >= bestScore) {
            continue;
        }
        int decodedB = clamp(b + modifier);
<<<<<<< HEAD
        score += (etc1_uint32)square(decodedB - pixelB);
=======
        score += (etc1_uint32) square(decodedB - pixelB);
>>>>>>> miniblink49
        if (score < bestScore) {
            bestScore = score;
            bestIndex = i;
        }
    }
    etc1_uint32 lowMask = (((bestIndex >> 1) << 16) | (bestIndex & 1))
<<<<<<< HEAD
        << bitIndex;
=======
            << bitIndex;
>>>>>>> miniblink49
    *pLow |= lowMask;
    return bestScore;
}

<<<<<<< HEAD
static void etc_encode_subblock_helper(const etc1_byte* pIn, etc1_uint32 inMask,
    etc_compressed* pCompressed, bool flipped, bool second,
    const etc1_byte* pBaseColors, const int* pModifierTable)
{
=======
static
void etc_encode_subblock_helper(const etc1_byte* pIn, etc1_uint32 inMask,
        etc_compressed* pCompressed, bool flipped, bool second,
        const etc1_byte* pBaseColors, const int* pModifierTable) {
>>>>>>> miniblink49
    int score = pCompressed->score;
    if (flipped) {
        int by = 0;
        if (second) {
            by = 2;
        }
        for (int y = 0; y < 2; y++) {
            int yy = by + y;
            for (int x = 0; x < 4; x++) {
                int i = x + 4 * yy;
                if (inMask & (1 << i)) {
                    score += chooseModifier(pBaseColors, pIn + i * 3,
<<<<<<< HEAD
                        &pCompressed->low, yy + x * 4, pModifierTable);
=======
                            &pCompressed->low, yy + x * 4, pModifierTable);
>>>>>>> miniblink49
                }
            }
        }
    } else {
        int bx = 0;
        if (second) {
            bx = 2;
        }
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 2; x++) {
                int xx = bx + x;
                int i = xx + 4 * y;
                if (inMask & (1 << i)) {
                    score += chooseModifier(pBaseColors, pIn + i * 3,
<<<<<<< HEAD
                        &pCompressed->low, y + xx * 4, pModifierTable);
=======
                            &pCompressed->low, y + xx * 4, pModifierTable);
>>>>>>> miniblink49
                }
            }
        }
    }
    pCompressed->score = score;
}

<<<<<<< HEAD
static bool inRange4bitSigned(int color)
{
=======
static bool inRange4bitSigned(int color) {
>>>>>>> miniblink49
    return color >= -4 && color <= 3;
}

static void etc_encodeBaseColors(etc1_byte* pBaseColors,
<<<<<<< HEAD
    const etc1_byte* pColors, etc_compressed* pCompressed)
{
=======
        const etc1_byte* pColors, etc_compressed* pCompressed) {
>>>>>>> miniblink49
    int r1, g1, b1, r2, g2, b2; // 8 bit base colors for sub-blocks
    bool differential;
    {
        int r51 = convert8To5(pColors[0]);
        int g51 = convert8To5(pColors[1]);
        int b51 = convert8To5(pColors[2]);
        int r52 = convert8To5(pColors[3]);
        int g52 = convert8To5(pColors[4]);
        int b52 = convert8To5(pColors[5]);

        r1 = convert5To8(r51);
        g1 = convert5To8(g51);
        b1 = convert5To8(b51);

        int dr = r52 - r51;
        int dg = g52 - g51;
        int db = b52 - b51;

        differential = inRange4bitSigned(dr) && inRange4bitSigned(dg)
<<<<<<< HEAD
            && inRange4bitSigned(db);
=======
                && inRange4bitSigned(db);
>>>>>>> miniblink49
        if (differential) {
            r2 = convert5To8(r51 + dr);
            g2 = convert5To8(g51 + dg);
            b2 = convert5To8(b51 + db);
            pCompressed->high |= (r51 << 27) | ((7 & dr) << 24) | (g51 << 19)
<<<<<<< HEAD
                | ((7 & dg) << 16) | (b51 << 11) | ((7 & db) << 8) | 2;
=======
                    | ((7 & dg) << 16) | (b51 << 11) | ((7 & db) << 8) | 2;
>>>>>>> miniblink49
        }
    }

    if (!differential) {
        int r41 = convert8To4(pColors[0]);
        int g41 = convert8To4(pColors[1]);
        int b41 = convert8To4(pColors[2]);
        int r42 = convert8To4(pColors[3]);
        int g42 = convert8To4(pColors[4]);
        int b42 = convert8To4(pColors[5]);
        r1 = convert4To8(r41);
        g1 = convert4To8(g41);
        b1 = convert4To8(b41);
        r2 = convert4To8(r42);
        g2 = convert4To8(g42);
        b2 = convert4To8(b42);
<<<<<<< HEAD
        pCompressed->high |= (r41 << 28) | (r42 << 24) | (g41 << 20) | (g42 << 16) | (b41 << 12) | (b42 << 8);
=======
        pCompressed->high |= (r41 << 28) | (r42 << 24) | (g41 << 20) | (g42
                << 16) | (b41 << 12) | (b42 << 8);
>>>>>>> miniblink49
    }
    pBaseColors[0] = r1;
    pBaseColors[1] = g1;
    pBaseColors[2] = b1;
    pBaseColors[3] = r2;
    pBaseColors[4] = g2;
    pBaseColors[5] = b2;
}

<<<<<<< HEAD
static void etc_encode_block_helper(const etc1_byte* pIn, etc1_uint32 inMask,
    const etc1_byte* pColors, etc_compressed* pCompressed, bool flipped)
{
=======
static
void etc_encode_block_helper(const etc1_byte* pIn, etc1_uint32 inMask,
        const etc1_byte* pColors, etc_compressed* pCompressed, bool flipped) {
>>>>>>> miniblink49
    pCompressed->score = ~0;
    pCompressed->high = (flipped ? 1 : 0);
    pCompressed->low = 0;

    etc1_byte pBaseColors[6];

    etc_encodeBaseColors(pBaseColors, pColors, pCompressed);

    int originalHigh = pCompressed->high;

    const int* pModifierTable = kModifierTable;
    for (int i = 0; i < 8; i++, pModifierTable += 4) {
        etc_compressed temp;
        temp.score = 0;
        temp.high = originalHigh | (i << 5);
        temp.low = 0;
        etc_encode_subblock_helper(pIn, inMask, &temp, flipped, false,
<<<<<<< HEAD
            pBaseColors, pModifierTable);
=======
                pBaseColors, pModifierTable);
>>>>>>> miniblink49
        take_best(pCompressed, &temp);
    }
    pModifierTable = kModifierTable;
    etc_compressed firstHalf = *pCompressed;
    for (int i = 0; i < 8; i++, pModifierTable += 4) {
        etc_compressed temp;
        temp.score = firstHalf.score;
        temp.high = firstHalf.high | (i << 2);
        temp.low = firstHalf.low;
        etc_encode_subblock_helper(pIn, inMask, &temp, flipped, true,
<<<<<<< HEAD
            pBaseColors + 3, pModifierTable);
=======
                pBaseColors + 3, pModifierTable);
>>>>>>> miniblink49
        if (i == 0) {
            *pCompressed = temp;
        } else {
            take_best(pCompressed, &temp);
        }
    }
}

<<<<<<< HEAD
static void writeBigEndian(etc1_byte* pOut, etc1_uint32 d)
{
    pOut[0] = (etc1_byte)(d >> 24);
    pOut[1] = (etc1_byte)(d >> 16);
    pOut[2] = (etc1_byte)(d >> 8);
    pOut[3] = (etc1_byte)d;
=======
static void writeBigEndian(etc1_byte* pOut, etc1_uint32 d) {
    pOut[0] = (etc1_byte)(d >> 24);
    pOut[1] = (etc1_byte)(d >> 16);
    pOut[2] = (etc1_byte)(d >> 8);
    pOut[3] = (etc1_byte) d;
>>>>>>> miniblink49
}

// Input is a 4 x 4 square of 3-byte pixels in form R, G, B
// inmask is a 16-bit mask where bit (1 << (x + y * 4)) tells whether the corresponding (x,y)
// pixel is valid or not. Invalid pixel color values are ignored when compressing.
// Output is an ETC1 compressed version of the data.

void etc1_encode_block(const etc1_byte* pIn, etc1_uint32 inMask,
<<<<<<< HEAD
    etc1_byte* pOut)
{
=======
        etc1_byte* pOut) {
>>>>>>> miniblink49
    etc1_byte colors[6];
    etc1_byte flippedColors[6];
    etc_average_colors_subblock(pIn, inMask, colors, false, false);
    etc_average_colors_subblock(pIn, inMask, colors + 3, false, true);
    etc_average_colors_subblock(pIn, inMask, flippedColors, true, false);
    etc_average_colors_subblock(pIn, inMask, flippedColors + 3, true, true);

    etc_compressed a, b;
    etc_encode_block_helper(pIn, inMask, colors, &a, false);
    etc_encode_block_helper(pIn, inMask, flippedColors, &b, true);
    take_best(&a, &b);
    writeBigEndian(pOut, a.high);
    writeBigEndian(pOut + 4, a.low);
}

// Return the size of the encoded image data (does not include size of PKM header).

<<<<<<< HEAD
etc1_uint32 etc1_get_encoded_data_size(etc1_uint32 width, etc1_uint32 height)
{
=======
etc1_uint32 etc1_get_encoded_data_size(etc1_uint32 width, etc1_uint32 height) {
>>>>>>> miniblink49
    return (((width + 3) & ~3) * ((height + 3) & ~3)) >> 1;
}

// Encode an entire image.
// pIn - pointer to the image data. Formatted such that the Red component of
//       pixel (x,y) is at pIn + pixelSize * x + stride * y + redOffset;
// pOut - pointer to encoded data. Must be large enough to store entire encoded image.

int etc1_encode_image(const etc1_byte* pIn, etc1_uint32 width, etc1_uint32 height,
<<<<<<< HEAD
    etc1_uint32 pixelSize, etc1_uint32 stride, etc1_byte* pOut)
{
=======
        etc1_uint32 pixelSize, etc1_uint32 stride, etc1_byte* pOut) {
>>>>>>> miniblink49
    if (pixelSize < 2 || pixelSize > 3) {
        return -1;
    }
    static const unsigned short kYMask[] = { 0x0, 0xf, 0xff, 0xfff, 0xffff };
    static const unsigned short kXMask[] = { 0x0, 0x1111, 0x3333, 0x7777,
<<<<<<< HEAD
        0xffff };
=======
            0xffff };
>>>>>>> miniblink49
    etc1_byte block[ETC1_DECODED_BLOCK_SIZE];
    etc1_byte encoded[ETC1_ENCODED_BLOCK_SIZE];

    etc1_uint32 encodedWidth = (width + 3) & ~3;
    etc1_uint32 encodedHeight = (height + 3) & ~3;

    for (etc1_uint32 y = 0; y < encodedHeight; y += 4) {
        etc1_uint32 yEnd = height - y;
        if (yEnd > 4) {
            yEnd = 4;
        }
        int ymask = kYMask[yEnd];
        for (etc1_uint32 x = 0; x < encodedWidth; x += 4) {
            etc1_uint32 xEnd = width - x;
            if (xEnd > 4) {
                xEnd = 4;
            }
            int mask = ymask & kXMask[xEnd];
            for (etc1_uint32 cy = 0; cy < yEnd; cy++) {
                etc1_byte* q = block + (cy * 4) * 3;
                const etc1_byte* p = pIn + pixelSize * x + stride * (y + cy);
                if (pixelSize == 3) {
                    memcpy(q, p, xEnd * 3);
                } else {
                    for (etc1_uint32 cx = 0; cx < xEnd; cx++) {
                        int pixel = (p[1] << 8) | p[0];
                        *q++ = convert5To8(pixel >> 11);
                        *q++ = convert6To8(pixel >> 5);
                        *q++ = convert5To8(pixel);
                        p += pixelSize;
                    }
                }
            }
            etc1_encode_block(block, mask, encoded);
            memcpy(pOut, encoded, sizeof(encoded));
            pOut += sizeof(encoded);
        }
    }
    return 0;
}

// Decode an entire image.
// pIn - pointer to encoded data.
// pOut - pointer to the image data. Will be written such that the Red component of
//       pixel (x,y) is at pIn + pixelSize * x + stride * y + redOffset. Must be
//        large enough to store entire image.

<<<<<<< HEAD
int etc1_decode_image(const etc1_byte* pIn, etc1_byte* pOut,
    etc1_uint32 width, etc1_uint32 height,
    etc1_uint32 pixelSize, etc1_uint32 stride)
{
=======

int etc1_decode_image(const etc1_byte* pIn, etc1_byte* pOut,
        etc1_uint32 width, etc1_uint32 height,
        etc1_uint32 pixelSize, etc1_uint32 stride) {
>>>>>>> miniblink49
    if (pixelSize < 2 || pixelSize > 3) {
        return -1;
    }
    etc1_byte block[ETC1_DECODED_BLOCK_SIZE];

    etc1_uint32 encodedWidth = (width + 3) & ~3;
    etc1_uint32 encodedHeight = (height + 3) & ~3;

    for (etc1_uint32 y = 0; y < encodedHeight; y += 4) {
        etc1_uint32 yEnd = height - y;
        if (yEnd > 4) {
            yEnd = 4;
        }
        for (etc1_uint32 x = 0; x < encodedWidth; x += 4) {
            etc1_uint32 xEnd = width - x;
            if (xEnd > 4) {
                xEnd = 4;
            }
            etc1_decode_block(pIn, block);
            pIn += ETC1_ENCODED_BLOCK_SIZE;
            for (etc1_uint32 cy = 0; cy < yEnd; cy++) {
                const etc1_byte* q = block + (cy * 4) * 3;
                etc1_byte* p = pOut + pixelSize * x + stride * (y + cy);
                if (pixelSize == 3) {
                    memcpy(p, q, xEnd * 3);
                } else {
                    for (etc1_uint32 cx = 0; cx < xEnd; cx++) {
                        etc1_byte r = *q++;
                        etc1_byte g = *q++;
                        etc1_byte b = *q++;
                        etc1_uint32 pixel = ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3);
<<<<<<< HEAD
                        *p++ = (etc1_byte)pixel;
                        *p++ = (etc1_byte)(pixel >> 8);
=======
                        *p++ = (etc1_byte) pixel;
                        *p++ = (etc1_byte) (pixel >> 8);
>>>>>>> miniblink49
                    }
                }
            }
        }
    }
    return 0;
}

static const char kMagic[] = { 'P', 'K', 'M', ' ', '1', '0' };

static const etc1_uint32 ETC1_PKM_FORMAT_OFFSET = 6;
static const etc1_uint32 ETC1_PKM_ENCODED_WIDTH_OFFSET = 8;
static const etc1_uint32 ETC1_PKM_ENCODED_HEIGHT_OFFSET = 10;
static const etc1_uint32 ETC1_PKM_WIDTH_OFFSET = 12;
static const etc1_uint32 ETC1_PKM_HEIGHT_OFFSET = 14;

static const etc1_uint32 ETC1_RGB_NO_MIPMAPS = 0;

<<<<<<< HEAD
static void writeBEUint16(etc1_byte* pOut, etc1_uint32 data)
{
    pOut[0] = (etc1_byte)(data >> 8);
    pOut[1] = (etc1_byte)data;
}

static etc1_uint32 readBEUint16(const etc1_byte* pIn)
{
=======
static void writeBEUint16(etc1_byte* pOut, etc1_uint32 data) {
    pOut[0] = (etc1_byte) (data >> 8);
    pOut[1] = (etc1_byte) data;
}

static etc1_uint32 readBEUint16(const etc1_byte* pIn) {
>>>>>>> miniblink49
    return (pIn[0] << 8) | pIn[1];
}

// Format a PKM header

<<<<<<< HEAD
void etc1_pkm_format_header(etc1_byte* pHeader, etc1_uint32 width, etc1_uint32 height)
{
=======
void etc1_pkm_format_header(etc1_byte* pHeader, etc1_uint32 width, etc1_uint32 height) {
>>>>>>> miniblink49
    memcpy(pHeader, kMagic, sizeof(kMagic));
    etc1_uint32 encodedWidth = (width + 3) & ~3;
    etc1_uint32 encodedHeight = (height + 3) & ~3;
    writeBEUint16(pHeader + ETC1_PKM_FORMAT_OFFSET, ETC1_RGB_NO_MIPMAPS);
    writeBEUint16(pHeader + ETC1_PKM_ENCODED_WIDTH_OFFSET, encodedWidth);
    writeBEUint16(pHeader + ETC1_PKM_ENCODED_HEIGHT_OFFSET, encodedHeight);
    writeBEUint16(pHeader + ETC1_PKM_WIDTH_OFFSET, width);
    writeBEUint16(pHeader + ETC1_PKM_HEIGHT_OFFSET, height);
}

// Check if a PKM header is correctly formatted.

<<<<<<< HEAD
etc1_bool etc1_pkm_is_valid(const etc1_byte* pHeader)
{
=======
etc1_bool etc1_pkm_is_valid(const etc1_byte* pHeader) {
>>>>>>> miniblink49
    if (memcmp(pHeader, kMagic, sizeof(kMagic))) {
        return false;
    }
    etc1_uint32 format = readBEUint16(pHeader + ETC1_PKM_FORMAT_OFFSET);
    etc1_uint32 encodedWidth = readBEUint16(pHeader + ETC1_PKM_ENCODED_WIDTH_OFFSET);
    etc1_uint32 encodedHeight = readBEUint16(pHeader + ETC1_PKM_ENCODED_HEIGHT_OFFSET);
    etc1_uint32 width = readBEUint16(pHeader + ETC1_PKM_WIDTH_OFFSET);
    etc1_uint32 height = readBEUint16(pHeader + ETC1_PKM_HEIGHT_OFFSET);
<<<<<<< HEAD
    return format == ETC1_RGB_NO_MIPMAPS && encodedWidth >= width && encodedWidth - width < 4 && encodedHeight >= height && encodedHeight - height < 4;
=======
    return format == ETC1_RGB_NO_MIPMAPS &&
            encodedWidth >= width && encodedWidth - width < 4 &&
            encodedHeight >= height && encodedHeight - height < 4;
>>>>>>> miniblink49
}

// Read the image width from a PKM header

<<<<<<< HEAD
etc1_uint32 etc1_pkm_get_width(const etc1_byte* pHeader)
{
=======
etc1_uint32 etc1_pkm_get_width(const etc1_byte* pHeader) {
>>>>>>> miniblink49
    return readBEUint16(pHeader + ETC1_PKM_WIDTH_OFFSET);
}

// Read the image height from a PKM header

<<<<<<< HEAD
etc1_uint32 etc1_pkm_get_height(const etc1_byte* pHeader)
{
=======
etc1_uint32 etc1_pkm_get_height(const etc1_byte* pHeader){
>>>>>>> miniblink49
    return readBEUint16(pHeader + ETC1_PKM_HEIGHT_OFFSET);
}
