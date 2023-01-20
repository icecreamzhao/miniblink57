/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkOSFile.h"

<<<<<<< HEAD
SkString SkOSPath::Join(const char* rootPath, const char* relativePath)
{
=======
SkString SkOSPath::Join(const char *rootPath, const char *relativePath) {
>>>>>>> miniblink49
    SkString result(rootPath);
    if (!result.endsWith(SkPATH_SEPARATOR) && !result.isEmpty()) {
        result.appendUnichar(SkPATH_SEPARATOR);
    }
    result.append(relativePath);
    return result;
}

<<<<<<< HEAD
SkString SkOSPath::Basename(const char* fullPath)
{
=======
SkString SkOSPath::Basename(const char* fullPath) {
>>>>>>> miniblink49
    if (!fullPath) {
        return SkString();
    }
    const char* filename = strrchr(fullPath, SkPATH_SEPARATOR);
<<<<<<< HEAD
    if (nullptr == filename) {
=======
    if (NULL == filename) {
>>>>>>> miniblink49
        filename = fullPath;
    } else {
        ++filename;
    }
    return SkString(filename);
}

<<<<<<< HEAD
SkString SkOSPath::Dirname(const char* fullPath)
{
=======
SkString SkOSPath::Dirname(const char* fullPath) {
>>>>>>> miniblink49
    if (!fullPath) {
        return SkString();
    }
    const char* end = strrchr(fullPath, SkPATH_SEPARATOR);
<<<<<<< HEAD
    if (nullptr == end) {
=======
    if (NULL == end) {
>>>>>>> miniblink49
        return SkString();
    }
    if (end == fullPath) {
        SkASSERT(fullPath[0] == SkPATH_SEPARATOR);
        ++end;
    }
    return SkString(fullPath, end - fullPath);
}
