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
#include "SkParse.h"

#include <stdlib.h>
=======

#include "SkParse.h"
>>>>>>> miniblink49

static inline bool is_between(int c, int min, int max)
{
    return (unsigned)(c - min) <= (unsigned)(max - min);
}

static inline bool is_ws(int c)
{
    return is_between(c, 1, 32);
}

static inline bool is_digit(int c)
{
    return is_between(c, '0', '9');
}

static inline bool is_sep(int c)
{
    return is_ws(c) || c == ',' || c == ';';
}

static int to_hex(int c)
{
    if (is_digit(c))
        return c - '0';

<<<<<<< HEAD
    c |= 0x20; // make us lower-case
=======
    c |= 0x20;  // make us lower-case
>>>>>>> miniblink49
    if (is_between(c, 'a', 'f'))
        return c + 10 - 'a';
    else
        return -1;
}

static inline bool is_hex(int c)
{
    return to_hex(c) >= 0;
}

static const char* skip_ws(const char str[])
{
    SkASSERT(str);
    while (is_ws(*str))
        str++;
    return str;
}

static const char* skip_sep(const char str[])
{
    SkASSERT(str);
    while (is_sep(*str))
        str++;
    return str;
}

int SkParse::Count(const char str[])
{
    char c;
    int count = 0;
    goto skipLeading;
    do {
        count++;
        do {
            if ((c = *str++) == '\0')
                goto goHome;
        } while (is_sep(c) == false);
<<<<<<< HEAD
    skipLeading:
=======
skipLeading:
>>>>>>> miniblink49
        do {
            if ((c = *str++) == '\0')
                goto goHome;
        } while (is_sep(c));
    } while (true);
goHome:
    return count;
}

int SkParse::Count(const char str[], char separator)
{
    char c;
    int count = 0;
    goto skipLeading;
    do {
        count++;
        do {
            if ((c = *str++) == '\0')
                goto goHome;
        } while (c != separator);
<<<<<<< HEAD
    skipLeading:
=======
skipLeading:
>>>>>>> miniblink49
        do {
            if ((c = *str++) == '\0')
                goto goHome;
        } while (c == separator);
    } while (true);
goHome:
    return count;
}

const char* SkParse::FindHex(const char str[], uint32_t* value)
{
    SkASSERT(str);
    str = skip_ws(str);

    if (!is_hex(*str))
<<<<<<< HEAD
        return nullptr;
=======
        return NULL;
>>>>>>> miniblink49

    uint32_t n = 0;
    int max_digits = 8;
    int digit;

<<<<<<< HEAD
    while ((digit = to_hex(*str)) >= 0) {
        if (--max_digits < 0)
            return nullptr;
=======
    while ((digit = to_hex(*str)) >= 0)
    {
        if (--max_digits < 0)
            return NULL;
>>>>>>> miniblink49
        n = (n << 4) | digit;
        str += 1;
    }

<<<<<<< HEAD
    if (*str == 0 || is_ws(*str)) {
=======
    if (*str == 0 || is_ws(*str))
    {
>>>>>>> miniblink49
        if (value)
            *value = n;
        return str;
    }
<<<<<<< HEAD
    return nullptr;
=======
    return NULL;
>>>>>>> miniblink49
}

const char* SkParse::FindS32(const char str[], int32_t* value)
{
    SkASSERT(str);
    str = skip_ws(str);

    int sign = 0;
<<<<<<< HEAD
    if (*str == '-') {
=======
    if (*str == '-')
    {
>>>>>>> miniblink49
        sign = -1;
        str += 1;
    }

    if (!is_digit(*str))
<<<<<<< HEAD
        return nullptr;

    int n = 0;
    while (is_digit(*str)) {
        n = 10 * n + *str - '0';
=======
        return NULL;

    int n = 0;
    while (is_digit(*str))
    {
        n = 10*n + *str - '0';
>>>>>>> miniblink49
        str += 1;
    }
    if (value)
        *value = (n ^ sign) - sign;
    return str;
}

const char* SkParse::FindMSec(const char str[], SkMSec* value)
{
    SkASSERT(str);
    str = skip_ws(str);

    int sign = 0;
<<<<<<< HEAD
    if (*str == '-') {
=======
    if (*str == '-')
    {
>>>>>>> miniblink49
        sign = -1;
        str += 1;
    }

    if (!is_digit(*str))
<<<<<<< HEAD
        return nullptr;

    int n = 0;
    while (is_digit(*str)) {
        n = 10 * n + *str - '0';
=======
        return NULL;

    int n = 0;
    while (is_digit(*str))
    {
        n = 10*n + *str - '0';
>>>>>>> miniblink49
        str += 1;
    }
    int remaining10s = 3;
    if (*str == '.') {
        str++;
<<<<<<< HEAD
        while (is_digit(*str)) {
            n = 10 * n + *str - '0';
=======
        while (is_digit(*str))
        {
            n = 10*n + *str - '0';
>>>>>>> miniblink49
            str += 1;
            if (--remaining10s == 0)
                break;
        }
    }
    while (--remaining10s >= 0)
        n *= 10;
    if (value)
        *value = (n ^ sign) - sign;
    return str;
}

<<<<<<< HEAD
const char* SkParse::FindScalar(const char str[], SkScalar* value)
{
=======
const char* SkParse::FindScalar(const char str[], SkScalar* value) {
>>>>>>> miniblink49
    SkASSERT(str);
    str = skip_ws(str);

    char* stop;
    float v = (float)strtod(str, &stop);
    if (str == stop) {
<<<<<<< HEAD
        return nullptr;
=======
        return NULL;
>>>>>>> miniblink49
    }
    if (value) {
        *value = v;
    }
    return stop;
}

const char* SkParse::FindScalars(const char str[], SkScalar value[], int count)
{
    SkASSERT(count >= 0);

<<<<<<< HEAD
    if (count > 0) {
        for (;;) {
            str = SkParse::FindScalar(str, value);
            if (--count == 0 || str == nullptr)
=======
    if (count > 0)
    {
        for (;;)
        {
            str = SkParse::FindScalar(str, value);
            if (--count == 0 || str == NULL)
>>>>>>> miniblink49
                break;

            // keep going
            str = skip_sep(str);
            if (value)
                value += 1;
        }
    }
    return str;
}

static bool lookup_str(const char str[], const char** table, int count)
{
    while (--count >= 0)
        if (!strcmp(str, table[count]))
            return true;
    return false;
}

bool SkParse::FindBool(const char str[], bool* value)
{
    static const char* gYes[] = { "yes", "1", "true" };
    static const char* gNo[] = { "no", "0", "false" };

<<<<<<< HEAD
    if (lookup_str(str, gYes, SK_ARRAY_COUNT(gYes))) {
        if (value)
            *value = true;
        return true;
    } else if (lookup_str(str, gNo, SK_ARRAY_COUNT(gNo))) {
        if (value)
            *value = false;
=======
    if (lookup_str(str, gYes, SK_ARRAY_COUNT(gYes)))
    {
        if (value) *value = true;
        return true;
    }
    else if (lookup_str(str, gNo, SK_ARRAY_COUNT(gNo)))
    {
        if (value) *value = false;
>>>>>>> miniblink49
        return true;
    }
    return false;
}

int SkParse::FindList(const char target[], const char list[])
{
<<<<<<< HEAD
    size_t len = strlen(target);
    int index = 0;

    for (;;) {
        const char* end = strchr(list, ',');
        size_t entryLen;

        if (end == nullptr) // last entry
=======
    size_t  len = strlen(target);
    int     index = 0;

    for (;;)
    {
        const char* end = strchr(list, ',');
        size_t      entryLen;

        if (end == NULL) // last entry
>>>>>>> miniblink49
            entryLen = strlen(list);
        else
            entryLen = end - list;

        if (entryLen == len && memcmp(target, list, len) == 0)
            return index;
<<<<<<< HEAD
        if (end == nullptr)
=======
        if (end == NULL)
>>>>>>> miniblink49
            break;

        list = end + 1; // skip the ','
        index += 1;
    }
    return -1;
}

#ifdef SK_SUPPORT_UNITTEST
void SkParse::UnitTest()
{
    // !!! additional parse tests go here
    SkParse::TestColor();
}
#endif
