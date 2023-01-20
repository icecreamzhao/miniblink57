/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkOSFile.h"
<<<<<<< HEAD
#include "SkTypes.h"
=======
>>>>>>> miniblink49

#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
<<<<<<< HEAD
=======
#include <sys/types.h>
>>>>>>> miniblink49

#ifdef _WIN32
#include <direct.h>
#include <io.h>
#endif

<<<<<<< HEAD
#ifdef SK_BUILD_FOR_IOS
#import <CoreFoundation/CoreFoundation.h>

static FILE* ios_open_from_bundle(const char path[], const char* perm)
{
    // Get a reference to the main bundle
    CFBundleRef mainBundle = CFBundleGetMainBundle();

    // Get a reference to the file's URL
    CFStringRef pathRef = CFStringCreateWithCString(NULL, path, kCFStringEncodingUTF8);
    CFURLRef imageURL = CFBundleCopyResourceURL(mainBundle, pathRef, NULL, NULL);
    if (!imageURL) {
        return nullptr;
    }

    // Convert the URL reference into a string reference
    CFStringRef imagePath = CFURLCopyFileSystemPath(imageURL, kCFURLPOSIXPathStyle);

    // Get the system encoding method
    CFStringEncoding encodingMethod = CFStringGetSystemEncoding();

    // Convert the string reference into a C string
    const char* finalPath = CFStringGetCStringPtr(imagePath, encodingMethod);

    return fopen(finalPath, perm);
}
#endif

FILE* sk_fopen(const char path[], SkFILE_Flags flags)
{
    char perm[4];
    char* p = perm;
=======
SkFILE* sk_fopen(const char path[], SkFILE_Flags flags) {
#ifdef MINIBLINK_NOT_IMPLEMENTED
    char    perm[4];
    char*   p = perm;
>>>>>>> miniblink49

    if (flags & kRead_SkFILE_Flag) {
        *p++ = 'r';
    }
    if (flags & kWrite_SkFILE_Flag) {
        *p++ = 'w';
    }
    *p++ = 'b';
    *p = 0;

    //TODO: on Windows fopen is just ASCII or the current code page,
    //convert to utf16 and use _wfopen
<<<<<<< HEAD
    FILE* file = nullptr;
#ifdef SK_BUILD_FOR_IOS
    // if read-only, try to open from bundle first
    if (kRead_SkFILE_Flag == flags) {
        file = ios_open_from_bundle(path, perm);
    }
    // otherwise just read from the Documents directory (default)
    if (!file) {
#endif
        file = fopen(path, perm);
#ifdef SK_BUILD_FOR_IOS
    }
#endif
    if (nullptr == file && (flags & kWrite_SkFILE_Flag)) {
        SkDEBUGF(("sk_fopen: fopen(\"%s\", \"%s\") returned NULL (errno:%d): %s\n",
            path, perm, errno, strerror(errno)));
    }
    return file;
}

char* sk_fgets(char* str, int size, FILE* f)
{
    return fgets(str, size, (FILE*)f);
}

int sk_feof(FILE* f)
{
    // no :: namespace qualifier because it breaks android
    return feof((FILE*)f);
}

size_t sk_fgetsize(FILE* f)
{
    SkASSERT(f);

    long curr = ftell(f); // remember where we are
=======
    return (SkFILE*)::fopen(path, perm);
#endif // MINIBLINK_NOT_IMPLEMENTED
    DebugBreak();
    return NULL;
}

char* sk_fgets(char* str, int size, SkFILE* f) {
    return ::fgets(str, size, (FILE *)f);
}

int sk_feof(SkFILE *f) {
    // no :: namespace qualifier because it breaks android
    return feof((FILE *)f);
}

size_t sk_fgetsize(SkFILE* f) {
    SkASSERT(f);

    long curr = ::ftell((FILE*)f); // remember where we are
>>>>>>> miniblink49
    if (curr < 0) {
        return 0;
    }

<<<<<<< HEAD
    fseek(f, 0, SEEK_END); // go to the end
    long size = ftell(f); // record the size
=======
    ::fseek((FILE*)f, 0, SEEK_END); // go to the end
    long size = ::ftell((FILE*)f); // record the size
>>>>>>> miniblink49
    if (size < 0) {
        size = 0;
    }

<<<<<<< HEAD
    fseek(f, curr, SEEK_SET); // go back to our prev location
    return size;
}

bool sk_frewind(FILE* f)
{
    SkASSERT(f);
    ::rewind(f);
    return true;
}

size_t sk_fread(void* buffer, size_t byteCount, FILE* f)
{
    SkASSERT(f);
    if (buffer == nullptr) {
        size_t curr = ftell(f);
        if ((long)curr == -1) {
            SkDEBUGF(("sk_fread: ftell(%p) returned -1 feof:%d ferror:%d\n", f, feof(f), ferror(f)));
            return 0;
        }
        int err = fseek(f, (long)byteCount, SEEK_CUR);
        if (err != 0) {
            SkDEBUGF(("sk_fread: fseek(%d) tell:%d failed with feof:%d ferror:%d returned:%d\n",
                byteCount, curr, feof(f), ferror(f), err));
            return 0;
        }
        return byteCount;
    } else
        return fread(buffer, 1, byteCount, f);
}

size_t sk_fwrite(const void* buffer, size_t byteCount, FILE* f)
{
    SkASSERT(f);
    return fwrite(buffer, 1, byteCount, f);
}

void sk_fflush(FILE* f)
{
    SkASSERT(f);
    fflush(f);
}

void sk_fsync(FILE* f)
{
#if !defined(_WIN32) && !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__) \
    && !defined(_NEWLIB_VERSION)
    int fd = fileno(f);
    fsync(fd);
#endif
}

bool sk_fseek(FILE* f, size_t byteCount)
{
    int err = fseek(f, (long)byteCount, SEEK_SET);
    return err == 0;
}

bool sk_fmove(FILE* f, long byteCount)
{
    int err = fseek(f, byteCount, SEEK_CUR);
    return err == 0;
}

size_t sk_ftell(FILE* f)
{
    long curr = ftell(f);
=======
    ::fseek((FILE*)f, curr, SEEK_SET); // go back to our prev location
    return size;
}

bool sk_frewind(SkFILE* f) {
    SkASSERT(f);
    ::rewind((FILE*)f);
    return true;
}

size_t sk_fread(void* buffer, size_t byteCount, SkFILE* f) {
    SkASSERT(f);
    if (buffer == NULL) {
        size_t curr = ::ftell((FILE*)f);
        if ((long)curr == -1) {
            SkDEBUGF(("sk_fread: ftell(%p) returned -1 feof:%d ferror:%d\n", f, feof((FILE*)f), ferror((FILE*)f)));
            return 0;
        }
        int err = ::fseek((FILE*)f, (long)byteCount, SEEK_CUR);
        if (err != 0) {
            SkDEBUGF(("sk_fread: fseek(%d) tell:%d failed with feof:%d ferror:%d returned:%d\n",
                        byteCount, curr, feof((FILE*)f), ferror((FILE*)f), err));
            return 0;
        }
        return byteCount;
    }
    else
        return ::fread(buffer, 1, byteCount, (FILE*)f);
}

size_t sk_fwrite(const void* buffer, size_t byteCount, SkFILE* f) {
    SkASSERT(f);
    return ::fwrite(buffer, 1, byteCount, (FILE*)f);
}

void sk_fflush(SkFILE* f) {
    SkASSERT(f);
    ::fflush((FILE*)f);
}

bool sk_fseek(SkFILE* f, size_t byteCount) {
    int err = ::fseek((FILE*)f, (long)byteCount, SEEK_SET);
    return err == 0;
}

bool sk_fmove(SkFILE* f, long byteCount) {
    int err = ::fseek((FILE*)f, byteCount, SEEK_CUR);
    return err == 0;
}

size_t sk_ftell(SkFILE* f) {
    long curr = ::ftell((FILE*)f);
>>>>>>> miniblink49
    if (curr < 0) {
        return 0;
    }
    return curr;
}

<<<<<<< HEAD
void sk_fclose(FILE* f)
{
    SkASSERT(f);
    fclose(f);
}

bool sk_isdir(const char* path)
{
=======
void sk_fclose(SkFILE* f) {
    SkASSERT(f);
    ::fclose((FILE*)f);
}

bool sk_isdir(const char *path) {
>>>>>>> miniblink49
    struct stat status;
    if (0 != stat(path, &status)) {
        return false;
    }
    return SkToBool(status.st_mode & S_IFDIR);
}

<<<<<<< HEAD
bool sk_mkdir(const char* path)
{
=======
bool sk_mkdir(const char* path) {
>>>>>>> miniblink49
    if (sk_isdir(path)) {
        return true;
    }
    if (sk_exists(path)) {
        fprintf(stderr,
<<<<<<< HEAD
            "sk_mkdir: path '%s' already exists but is not a directory\n",
            path);
=======
                "sk_mkdir: path '%s' already exists but is not a directory\n",
                path);
>>>>>>> miniblink49
        return false;
    }

    int retval;
#ifdef _WIN32
    retval = _mkdir(path);
#else
    retval = mkdir(path, 0777);
#endif
    if (0 == retval) {
        return true;
    } else {
        fprintf(stderr, "sk_mkdir: error %d creating dir '%s'\n", errno, path);
        return false;
    }
}
