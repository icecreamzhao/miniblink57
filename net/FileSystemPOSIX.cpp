/*
 * Copyright (C) 2007, 2008 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Apple Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "net/FileSystem.h"

#include "third_party/WebKit/Source/platform/FileMetadata.h"
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <fnmatch.h>
#include <libgen.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <glib.h>
#include "wtf/text/CString.h"
#include "wtf/text/WTFString.h"
#include "wtf/text/WTFStringUtil.h"

namespace net {

// M:\mycode\WebKit-r189384\Source\WebCore\platform\gtk\FileSystemGtk.cpp
// CString fileSystemRepresentationWrap(const String& path)
// {
// #if OS(WINDOWS)
//     return path.utf8();
// #else
//     GUniquePtr<gchar> filename = unescapedFilename(path);
//     return filename.get();
// #endif
// }

// M:\mycode\WebKit-r189384\Source\WebCore\platform\efl\FileSystemEfl.cpp
CString fileSystemRepresentationWrap(const String& path)
{
    Vector<UChar> buffer;
    // WARNING: this is just used by platform/network/soup, thus must be GLIB!!!
    // TODO: move this to CString and use it instead in both, being more standard
#if 1 // !PLATFORM(WIN_OS) && defined(USE_SOUP)
    char* filename = g_uri_unescape_string(path.utf8().data(), 0);
    CString cfilename(filename);
    g_free(filename);
    return cfilename;
#else
    return path.utf8();
#endif
}

bool fileExists(const String& path)
{
    if (path.isNull())
        return false;

    CString fsRep = fileSystemRepresentationWrap(path);

    if (!fsRep.data() || fsRep.data()[0] == '\0')
        return false;

    struct stat fileInfo;

    // stat(...) returns 0 on successful stat'ing of the file, and non-zero in any case where the file doesn't exist or cannot be accessed
    return !stat(fsRep.data(), &fileInfo);
}

bool deleteFile(const String& path)
{
    CString fsRep = fileSystemRepresentationWrap(path);

    if (!fsRep.data() || fsRep.data()[0] == '\0')
        return false;

    // unlink(...) returns 0 on successful deletion of the path and non-zero in any other case (including invalid permissions or non-existent file)
    return !unlink(fsRep.data());
}

PlatformFileHandle openFile(const String& path, FileOpenMode mode)
{
    CString fsRep = fileSystemRepresentationWrap(path);

    if (fsRep.isNull())
        return invalidPlatformFileHandle;

    int platformFlag = 0;
    if (mode == OpenForRead)
        platformFlag |= O_RDONLY;
    else if (mode == OpenForWrite)
        platformFlag |= (O_WRONLY | O_CREAT | O_TRUNC);
    return open(fsRep.data(), platformFlag, 0666);
}

void closeFile(PlatformFileHandle& handle)
{
    if (isHandleValid(handle)) {
        close(handle);
        handle = invalidPlatformFileHandle;
    }
}

// https://stackoverflow.com/questions/675039/how-can-i-create-directory-tree-in-c-linux
static bool isDirExist(const std::string& path)
{
#if defined(_WIN32)
    struct _stat info;
    if (_stat(path.c_str(), &info) != 0) {
        return false;
    }
    return (info.st_mode & _S_IFDIR) != 0;
#else 
    struct stat info;
    if (stat(path.c_str(), &info) != 0) {
        return false;
    }
    return (info.st_mode & S_IFDIR) != 0;
#endif
}

static bool makePath(const std::string& path)
{
#if defined(_WIN32)
    int ret = _mkdir(path.c_str());
#else
    mode_t mode = 0755;
    int ret = mkdir(path.c_str(), mode);
#endif
    if (ret == 0)
        return true;

    switch (errno) {
    case ENOENT:
        // parent didn't exist, try to create it
    {
        int pos = path.find_last_of('/');
        if (pos == std::string::npos)
#if defined(_WIN32)
            pos = path.find_last_of('\\');
        if (pos == std::string::npos)
#endif
            return false;
        if (!makePath(path.substr(0, pos)))
            return false;
    }
    // now, try to create again
#if defined(_WIN32)
    return 0 == _mkdir(path.c_str());
#else 
    return 0 == mkdir(path.c_str(), mode);
#endif

    case EEXIST:
        // done!
        return isDirExist(path);

    default:
        return false;
    }
}

bool createDirectory(const String& path)
{
    String pathA = WTF::ensureStringToUTF8String(path);
    std::string pathUTF8((const char*)pathA.characters8(), pathA.length());
    return makePath(pathUTF8);
}

long long seekFile(PlatformFileHandle handle, long long offset, FileSeekOrigin origin)
{
    int whence = SEEK_SET;
    switch (origin) {
    case SeekFromBeginning:
        whence = SEEK_SET;
        break;
    case SeekFromCurrent:
        whence = SEEK_CUR;
        break;
    case SeekFromEnd:
        whence = SEEK_END;
        break;
    default:
        ASSERT_NOT_REACHED();
    }
    return static_cast<long long>(lseek(handle, offset, whence));
}

bool truncateFile(PlatformFileHandle handle, long long offset)
{
    // ftruncate returns 0 to indicate the success.
    return !ftruncate(handle, offset);
}

int writeToFile(PlatformFileHandle handle, const char* data, int length)
{
    do {
        int bytesWritten = write(handle, data, static_cast<size_t>(length));
        if (bytesWritten >= 0)
            return bytesWritten;
    } while (errno == EINTR);
    return -1;
}

int readFromFile(PlatformFileHandle handle, char* data, int length)
{
    do {
        int bytesRead = read(handle, data, static_cast<size_t>(length));
        if (bytesRead >= 0)
            return bytesRead;
    } while (errno == EINTR);
    return -1;
}

#if USE(FILE_LOCK)
bool lockFile(PlatformFileHandle handle, FileLockMode lockMode)
{
    COMPILE_ASSERT(LOCK_SH == LockShared, LockSharedEncodingIsAsExpected);
    COMPILE_ASSERT(LOCK_EX == LockExclusive, LockExclusiveEncodingIsAsExpected);
    COMPILE_ASSERT(LOCK_NB == LockNonBlocking, LockNonBlockingEncodingIsAsExpected);
    int result = flock(handle, lockMode);
    return (result != -1);
}

bool unlockFile(PlatformFileHandle handle)
{
    int result = flock(handle, LOCK_UN);
    return (result != -1);
}
#endif

//#if !PLATFORM(MAC)
bool deleteEmptyDirectory(const String& path)
{
    CString fsRep = fileSystemRepresentationWrap(path);

    if (!fsRep.data() || fsRep.data()[0] == '\0')
        return false;

    // rmdir(...) returns 0 on successful deletion of the path and non-zero in any other case (including invalid permissions or non-existent file)
    return !rmdir(fsRep.data());
}
//#endif

bool getFileSize(const String& path, long long& result)
{
    CString fsRep = fileSystemRepresentationWrap(path);

    if (!fsRep.data() || fsRep.data()[0] == '\0')
        return false;

    struct stat fileInfo;

    if (stat(fsRep.data(), &fileInfo))
        return false;

    result = fileInfo.st_size;
    return true;
}

bool getFileSize(PlatformFileHandle handle, long long& result)
{
    struct stat fileInfo;
    if (fstat(handle, &fileInfo))
        return false;

    result = fileInfo.st_size;
    return true;
}

bool getFileCreationTime(const String& path, time_t& result)
{
#if 0 // OS(DARWIN) || OS(OPENBSD) || OS(NETBSD) || OS(FREEBSD)
    CString fsRep = fileSystemRepresentationWrap(path);

    if (!fsRep.data() || fsRep.data()[0] == '\0')
        return false;

    struct stat fileInfo;

    if (stat(fsRep.data(), &fileInfo))
        return false;

    result = fileInfo.st_birthtime;
    return true;
#else
    ALLOW_UNUSED_LOCAL(path);
    ALLOW_UNUSED_LOCAL(result);
    return false;
#endif
}

bool getFileModificationTime(const String& path, time_t& result)
{
    CString fsRep = fileSystemRepresentationWrap(path);

    if (!fsRep.data() || fsRep.data()[0] == '\0')
        return false;

    struct stat fileInfo;

    if (stat(fsRep.data(), &fileInfo))
        return false;

    result = fileInfo.st_mtime;
    return true;
}

bool getFileMetadata(const String& path, blink::FileMetadata& metadata)
{
    CString fsRep = fileSystemRepresentationWrap(path);

    if (!fsRep.data() || fsRep.data()[0] == '\0')
        return false;

    struct stat fileInfo;
    if (stat(fsRep.data(), &fileInfo))
        return false;

    metadata.modificationTime = fileInfo.st_mtime;
    metadata.length = fileInfo.st_size;
    metadata.type = S_ISDIR(fileInfo.st_mode) ? blink::FileMetadata::TypeDirectory : blink::FileMetadata::TypeFile;
    return true;
}

String pathByAppendingComponent(const String& path, const String& component)
{
    if (path.endsWith('/'))
        return path + component;
    return path + "/" + component;
}

bool makeAllDirectories(const String& path)
{
    CString fullPath = fileSystemRepresentationWrap(path);
    if (!access(fullPath.data(), F_OK))
        return true;

    char* p = (char*)fullPath.data() + 1;
    int length = fullPath.length();

    if(p[length - 1] == '/')
        p[length - 1] = '\0';
    for (; *p; ++p)
        if (*p == '/') {
            *p = '\0';
            if (access(fullPath.data(), F_OK))
                if (mkdir(fullPath.data(), S_IRWXU))
                    return false;
            *p = '/';
        }
    if (access(fullPath.data(), F_OK))
        if (mkdir(fullPath.data(), S_IRWXU))
            return false;

    return true;
}

String pathGetFileName(const String& path)
{
    return path.substring(path.reverseFind('/') + 1);
}

String directoryName(const String& path)
{
    CString fsRep = fileSystemRepresentationWrap(path);

    if (!fsRep.data() || fsRep.data()[0] == '\0')
        return String();

    return dirname((char*)fsRep./*mutableData*/data());
}

Vector<String> listDirectory(const String& path, const String& filter)
{
    Vector<String> entries;
    CString cpath = path.utf8();
    CString cfilter = filter.utf8();
    DIR* dir = opendir(cpath.data());
    if (dir) {
        struct dirent* dp;
        while ((dp = readdir(dir))) {
            const char* name = dp->d_name;
            if (!strcmp(name, ".") || !strcmp(name, ".."))
                continue;
            if (fnmatch(cfilter.data(), name, 0))
                continue;
            char filePath[1024];
            if (static_cast<int>(sizeof(filePath) - 1) < snprintf(filePath, sizeof(filePath), "%s/%s", cpath.data(), name))
                continue; // buffer overflow
            entries.append(filePath);
        }
        closedir(dir);
    }
    return entries;
}

#if 1// !OS(DARWIN) || PLATFORM(EFL) || PLATFORM(GTK)
String openTemporaryFile(const String& prefix, PlatformFileHandle& handle)
{
    char buffer[PATH_MAX];
    const char* tmpDir = getenv("TMPDIR");

    if (!tmpDir)
        tmpDir = "/tmp";

    if (snprintf(buffer, PATH_MAX, "%s/%sXXXXXX", tmpDir, prefix.utf8().data()) >= PATH_MAX)
        goto end;

    handle = mkstemp(buffer);
    if (handle < 0)
        goto end;

    return String::fromUTF8(buffer);

end:
    handle = invalidPlatformFileHandle;
    return String();
}
#endif

} // namespace WebCore
