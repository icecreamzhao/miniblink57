
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
// TODO: add unittests for all these operations

#ifndef SkOSFile_DEFINED
#define SkOSFile_DEFINED

<<<<<<< HEAD
#include <stdio.h>

#include "SkString.h"

enum SkFILE_Flags {
    kRead_SkFILE_Flag = 0x01,
    kWrite_SkFILE_Flag = 0x02
=======
#include "SkString.h"

struct SkFILE;

enum SkFILE_Flags {
    kRead_SkFILE_Flag   = 0x01,
    kWrite_SkFILE_Flag  = 0x02
>>>>>>> miniblink49
};

#ifdef _WIN32
const static char SkPATH_SEPARATOR = '\\';
#else
const static char SkPATH_SEPARATOR = '/';
#endif

<<<<<<< HEAD
FILE* sk_fopen(const char path[], SkFILE_Flags);
void sk_fclose(FILE*);

size_t sk_fgetsize(FILE*);
/** Return true if the file could seek back to the beginning
*/
bool sk_frewind(FILE*);

size_t sk_fread(void* buffer, size_t byteCount, FILE*);
size_t sk_fwrite(const void* buffer, size_t byteCount, FILE*);

char* sk_fgets(char* str, int size, FILE* f);

void sk_fflush(FILE*);
void sk_fsync(FILE*);

bool sk_fseek(FILE*, size_t);
bool sk_fmove(FILE*, long);
size_t sk_ftell(FILE*);
=======
SkFILE* sk_fopen(const char path[], SkFILE_Flags);
void    sk_fclose(SkFILE*);

size_t  sk_fgetsize(SkFILE*);
/** Return true if the file could seek back to the beginning
*/
bool    sk_frewind(SkFILE*);

size_t  sk_fread(void* buffer, size_t byteCount, SkFILE*);
size_t  sk_fwrite(const void* buffer, size_t byteCount, SkFILE*);

char*   sk_fgets(char* str, int size, SkFILE* f);

void    sk_fflush(SkFILE*);

bool    sk_fseek(SkFILE*, size_t);
bool    sk_fmove(SkFILE*, long);
size_t  sk_ftell(SkFILE*);
>>>>>>> miniblink49

/** Maps a file into memory. Returns the address and length on success, NULL otherwise.
 *  The mapping is read only.
 *  When finished with the mapping, free the returned pointer with sk_fmunmap.
 */
<<<<<<< HEAD
void* sk_fmmap(FILE* f, size_t* length);
=======
void*   sk_fmmap(SkFILE* f, size_t* length);
>>>>>>> miniblink49

/** Maps a file descriptor into memory. Returns the address and length on success, NULL otherwise.
 *  The mapping is read only.
 *  When finished with the mapping, free the returned pointer with sk_fmunmap.
 */
<<<<<<< HEAD
void* sk_fdmmap(int fd, size_t* length);
=======
void*   sk_fdmmap(int fd, size_t* length);
>>>>>>> miniblink49

/** Unmaps a file previously mapped by sk_fmmap or sk_fdmmap.
 *  The length parameter must be the same as returned from sk_fmmap.
 */
<<<<<<< HEAD
void sk_fmunmap(const void* addr, size_t length);

/** Returns true if the two point at the exact same filesystem object. */
bool sk_fidentical(FILE* a, FILE* b);
=======
void    sk_fmunmap(const void* addr, size_t length);

/** Returns true if the two point at the exact same filesystem object. */
bool    sk_fidentical(SkFILE* a, SkFILE* b);
>>>>>>> miniblink49

/** Returns the underlying file descriptor for the given file.
 *  The return value will be < 0 on failure.
 */
<<<<<<< HEAD
int sk_fileno(FILE* f);
=======
int     sk_fileno(SkFILE* f);
>>>>>>> miniblink49

/** Returns true if something (file, directory, ???) exists at this path,
 *  and has the specified access flags.
 */
<<<<<<< HEAD
bool sk_exists(const char* path, SkFILE_Flags = (SkFILE_Flags)0);

// Returns true if a directory exists at this path.
bool sk_isdir(const char* path);

// Have we reached the end of the file?
int sk_feof(FILE*);
=======
bool    sk_exists(const char *path, SkFILE_Flags = (SkFILE_Flags)0);

// Returns true if a directory exists at this path.
bool    sk_isdir(const char *path);

// Have we reached the end of the file?
int sk_feof(SkFILE *);

>>>>>>> miniblink49

// Create a new directory at this path; returns true if successful.
// If the directory already existed, this will return true.
// Description of the error, if any, will be written to stderr.
<<<<<<< HEAD
bool sk_mkdir(const char* path);
=======
bool    sk_mkdir(const char* path);
>>>>>>> miniblink49

class SkOSFile {
public:
    class Iter {
    public:
        Iter();
        Iter(const char path[], const char suffix[] = NULL);
        ~Iter();

        void reset(const char path[], const char suffix[] = NULL);
        /** If getDir is true, only returns directories.
            Results are undefined if true and false calls are
            interleaved on a single iterator.
        */
        bool next(SkString* name, bool getDir = false);

        static const size_t kStorageSize = 40;
<<<<<<< HEAD

=======
>>>>>>> miniblink49
    private:
        SkAlignedSStorage<kStorageSize> fSelf;
    };
};

/**
 *  Functions for modifying SkStrings which represent paths on the filesystem.
 */
<<<<<<< HEAD
class SkOSPath {
=======
class SkOSPath   {
>>>>>>> miniblink49
public:
    /**
     * Assembles rootPath and relativePath into a single path, like this:
     * rootPath/relativePath.
     * It is okay to call with a NULL rootPath and/or relativePath. A path
     * separator will still be inserted.
     *
     * Uses SkPATH_SEPARATOR, to work on all platforms.
     */
    static SkString Join(const char* rootPath, const char* relativePath);

    /**
     *  Return the name of the file, ignoring the directory structure.
     *  Behaves like python's os.path.basename. If the fullPath is
     *  /dir/subdir/, an empty string is returned.
     *  @param fullPath Full path to the file.
     *  @return SkString The basename of the file - anything beyond the
     *      final slash, or the full name if there is no slash.
     */
    static SkString Basename(const char* fullPath);

    /**
     *  Given a qualified file name returns the directory.
     *  Behaves like python's os.path.dirname. If the fullPath is
     *  /dir/subdir/ the return will be /dir/subdir/
     *  @param fullPath Full path to the file.
     *  @return SkString The dir containing the file - anything preceding the
     *      final slash, or the full name if ending in a slash.
     */
    static SkString Dirname(const char* fullPath);
};

#endif
