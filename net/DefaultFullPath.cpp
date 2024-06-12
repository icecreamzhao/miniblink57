#include "net/DefaultFullPath.h"
#include "third_party/WebKit/Source/wtf/ThreadingPrimitives.h"
#include "third_party/libcurl/include/curl/curl.h"
#include "net/WebURLLoaderManagerUtil.h"
#include "base/path_service.h"
#include "base/files/file_path.h"
#include <shlwapi.h>

namespace net {

static base::FilePath* kDefaultLocalStorageFullPath = nullptr;

void setDefaultLocalStorageFullPath(const std::string& path)
{
    WTF::RecursiveMutex* mutex = sharedResourceMutex(CURL_LOCK_DATA_COOKIE);
    WTF::Locker<WTF::RecursiveMutex> locker(*mutex);

    if (path.empty())
        return;
    
    if (kDefaultLocalStorageFullPath)
        delete kDefaultLocalStorageFullPath;

    kDefaultLocalStorageFullPath = new base::FilePath(base::FilePath::FromUTF8Unsafe(path));

    if (!kDefaultLocalStorageFullPath->EndsWithSeparator())
        *kDefaultLocalStorageFullPath = kDefaultLocalStorageFullPath->Append(base::FilePath::kSeparators);
}

std::string getDefaultLocalStorageFullPath()
{
    WTF::RecursiveMutex* mutex = sharedResourceMutex(CURL_LOCK_DATA_COOKIE);
    WTF::Locker<WTF::RecursiveMutex> locker(*mutex);

    if (kDefaultLocalStorageFullPath)
        return kDefaultLocalStorageFullPath->AsUTF8Unsafe();


//     std::vector<wchar_t> path;
//     path.resize(2 * MAX_PATH);
//     memset(&path.at(0), 0, sizeof(wchar_t) * (2 * MAX_PATH));
//     ::GetModuleFileNameW(nullptr, &path.at(0), MAX_PATH);
//     ::PathRemoveFileSpecW(&path.at(0));
//     ::PathAppendW(&path.at(0), L"LocalStorage");
// 
//     size_t size = wcslen(&path.at(0));
// 
//     kDefaultLocalStorageFullPath = new String(&path.at(0), size);
//     UChar c = kDefaultLocalStorageFullPath->characters16()[size - 1];
//     if (L'\\' != c && L'/' != c)
//         kDefaultLocalStorageFullPath->append(L'\\');
// 
//     return *kDefaultLocalStorageFullPath;

    kDefaultLocalStorageFullPath = new base::FilePath();
    base::PathService::Get(base::DIR_MODULE, kDefaultLocalStorageFullPath);
    *kDefaultLocalStorageFullPath = kDefaultLocalStorageFullPath->AppendASCII("LocalStorage");
    return kDefaultLocalStorageFullPath->AsUTF8Unsafe();
}

std::string getDefaultCookiesFullpath()
{
#if 0 // defined(OS_WIN)
    std::vector<wchar_t> path;
    path.resize(MAX_PATH + 1);
    memset(&path[0], 0, sizeof(wchar_t) * (MAX_PATH + 1));
    ::GetModuleFileNameW(nullptr, &path[0], MAX_PATH);
    ::PathRemoveFileSpecW(&path[0]);
    ::PathAppendW(&path[0], L"cookies.dat");

    std::vector<char> pathStrA;
    WTF::WCharToMByte(&path[0], wcslen(&path[0]), &pathStrA, CP_UTF8);

    return std::string(&pathStrA[0], pathStrA.size());
#else
    //     std::vector<char> buffer(MAX_PATH + 1);
    //     memset(buffer.data(), 0, MAX_PATH + 1);
    //     
    //     int cnt = readlink("/proc/self/exe", buffer.data(), MAX_PATH);
    //     RELEASE_ASSERT(-1 != cnt);
    //     buffer[cnt] = '\0';
    // 
    //     base::FilePath pathStr(std::string(buffer.data()));
    //     pathStr = pathStr.DirName();
    //     pathStr = pathStr.Append("cookies.dat");
    //     std::string ret = pathStr.AsUTF8Unsafe();
    base::FilePath path;
    base::PathService::Get(base::DIR_MODULE, &path);
    path = path.AppendASCII("cookies.dat");
    std::string ret = path.AsUTF8Unsafe();
    //std::string ret2 = path.value();
    // printf("getDefaultCookiesFullpath 2: %lu, %s, %lu, %s\n", ret.size(), ret.c_str(), ret2.size(), ret2.c_str());
    return ret;
#endif
}

}