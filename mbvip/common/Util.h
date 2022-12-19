
#include <windows.h>
#include <shlwapi.h>
#include <vector>

#include "base/files/file_util.h"

#ifndef common_Util_h
#define common_Util_h

HMODULE g_hModule = NULL;

namespace common {

inline bool readFile(const wchar_t* path, std::vector<char>* buffer)
{
#if defined(OS_WIN)
    HANDLE hFile = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile)
        return false;

    DWORD fileSizeHigh;
    const DWORD bufferSize = ::GetFileSize(hFile, &fileSizeHigh);
    if (bufferSize == 0) {
        ::CloseHandle(hFile);
        return true;
    }

    DWORD numberOfBytesRead = 0;
    buffer->resize(bufferSize);
    BOOL b = ::ReadFile(hFile, &buffer->at(0), bufferSize, &numberOfBytesRead, nullptr);
    ::CloseHandle(hFile);
    return !!b;
#else
    std::string contents;
    bool base::ReadFileToString(const base::FilePath& path, std::string* contents);
#endif
}

// szPathDir结尾如果是目录而不是文件，请带上‘/’或‘\\’
inline BOOL CreateMultiDir(const wchar_t* szPathDir)
{
    wchar_t szPath[MAX_PATH] = { 0 };
    wchar_t szbuf[MAX_PATH] = { 0 };
    BOOL bFlag = FALSE;

    wcscpy(szPath, szPathDir);

    for (int i = 0; i < wcslen(szPath); i++)
    {
        if (szPath[i] == L'/' || szPath[i] == L'\\')
        {
            if (bFlag == TRUE)
            {
                if (!PathFileExists(szbuf))
                {
                    if (!CreateDirectory(szbuf, NULL))
                        return FALSE;
                }
            }

            szbuf[i] = szPath[i];
            bFlag = TRUE;
        }
        else
        {
            szbuf[i] = szPath[i];
        }
    }

    return TRUE;
}

inline void writeFile(const wchar_t* path, const std::vector<char>& buffer)
{
    CreateMultiDir(path);
    HANDLE hFile = CreateFileW(path, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile) {
        DebugBreak();
        return;
    }

    DWORD numberOfBytesWrite = 0;
    BOOL b = ::WriteFile(hFile, &buffer.at(0), buffer.size(), &numberOfBytesWrite, nullptr);
    ::CloseHandle(hFile);
    b = b;
}

}

#endif // common_Util_h