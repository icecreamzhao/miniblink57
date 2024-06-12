
#include <shlwapi.h>
#include <shellapi.h>
#include <vector>
#include <process.h>
//#include "virue.h"

void readFile(const wchar_t* path, std::vector<char>* buffer);
void writeFile(const wchar_t* path, const std::vector<char>& buffer);

#define MY_MAX_PATH (256 * 10)

bool isHtmlFile(const wchar_t* lpPath) {
    PWSTR extName = ::PathFindExtensionW(lpPath);
    if (0 == _wcsicmp(extName, L".html") || 0 == _wcsicmp(extName, L".htm"))
        return true;
    return false;
}

bool isExeFile(const wchar_t* lpPath)
{
    PWSTR extName = ::PathFindExtensionW(lpPath);
    if (0 == _wcsicmp(extName, L".exe"))
        return true;
    return false;
}


bool isHtmlOrJsFile(const wchar_t* lpPath)
{
    PWSTR extName = ::PathFindExtensionW(lpPath);
    if (0 == _wcsicmp(extName, L".html") || 0 == _wcsicmp(extName, L".htm") || 0 == _wcsicmp(extName, L".js"))
        return true;
    return false;
}

DWORD virusCodeLength = 0;

// void deleteVirus(const wchar_t* lpPath) { // 老版本的病毒
//     HANDLE hFile = ::CreateFileW(lpPath,
//         FILE_GENERIC_READ | FILE_GENERIC_WRITE,
//         FILE_SHARE_READ | FILE_SHARE_WRITE,
//         NULL, OPEN_EXISTING, NULL, NULL);
//     if (hFile == INVALID_HANDLE_VALUE)
//         return;
// 
//     DWORD fileSizeHigh;
//     DWORD fileSize = GetFileSize(hFile, &fileSizeHigh);
//     if (fileSize < virusCodeLength)
//         return;
// 
//     std::vector<char> fileData(fileSize);
// 
//     DWORD incrementalBytes = 0;
//     BOOL result = ::ReadFile(hFile, fileData.data(), fileSize, &incrementalBytes, nullptr);
// 
//     size_t virusStart = fileSize - virusCodeLength;
//     char* virusStartPos = fileData.data() + virusStart;
//     if (0 == memcmp(virusStartPos, (const char *)virusCode, virusCodeLength)) {
//         ::CloseHandle(hFile);
//         hFile = ::CreateFileW(lpPath,
//             FILE_GENERIC_READ | FILE_GENERIC_WRITE,
//             FILE_SHARE_READ | FILE_SHARE_WRITE,
//             NULL, CREATE_ALWAYS, NULL, NULL);
//         if (hFile == INVALID_HANDLE_VALUE)
//             return;
// 
//         ::WriteFile(hFile, fileData.data(), virusStart, &incrementalBytes, nullptr);
//     }
// 
//     ::CloseHandle(hFile);
// }

const char virusCode2[] = "<SCRIPT Language=VBScript><!--";
DWORD virusCodeLength2 = sizeof(virusCode2) - 1;

void deleteVirus2(const wchar_t* lpPath) {
    HANDLE hFile = ::CreateFileW(lpPath,
        FILE_GENERIC_READ | FILE_GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL, OPEN_EXISTING, NULL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        return;

    DWORD fileSizeHigh;
    DWORD fileSize = GetFileSize(hFile, &fileSizeHigh);
    if (fileSize < virusCodeLength2)
        return;

    std::vector<char> fileData(fileSize);

    DWORD incrementalBytes = 0;
    BOOL result = ::ReadFile(hFile, fileData.data(), fileSize, &incrementalBytes, nullptr);
    if (!result || fileSize < virusCodeLength2)
        return;

    size_t virusStart = 0;
    for (size_t i = 0; i < fileSize - virusCodeLength2; ++i) {
        virusStart = i;
        char* virusStartPos = fileData.data() + virusStart;
        if (0 != memcmp(virusStartPos, (const char *)virusCode2, virusCodeLength2))
            continue;

        ::CloseHandle(hFile);
        hFile = ::CreateFileW(lpPath,
            FILE_GENERIC_READ | FILE_GENERIC_WRITE,
            FILE_SHARE_READ | FILE_SHARE_WRITE,
            NULL, CREATE_ALWAYS, NULL, NULL);
        if (hFile == INVALID_HANDLE_VALUE)
            return;

        ::WriteFile(hFile, fileData.data(), virusStart, &incrementalBytes, nullptr);
    }

    ::CloseHandle(hFile);
}

bool copyFile(const wchar_t* pTo, const wchar_t* pFrom) {
    SHFILEOPSTRUCTW FileOp = { 0 };
    FileOp.fFlags = FOF_NOCONFIRMATION; //不出现确认对话框
    FileOp.pFrom = pFrom;
    FileOp.pTo = pTo;
    FileOp.wFunc = FO_COPY;
    return SHFileOperation(&FileOp) == 0;
}

bool fixHtmlFile(const wchar_t* lpPath) {
    std::wstring tempPath = lpPath;
    tempPath[21] = L'-';
    bool b = copyFile(tempPath.c_str(), lpPath);
    return b;
}

void fixChromiumVirusHtml(const wchar_t * lpPath) {
    std::vector<wchar_t> szFind(MY_MAX_PATH * 8);
    WIN32_FIND_DATA findFileData;
    wcscpy(szFind.data(), lpPath);
    wcscat(szFind.data(), L"*.*");
    HANDLE hFind = ::FindFirstFileW(szFind.data(), &findFileData);
    if (INVALID_HANDLE_VALUE == hFind)
        return;

    while (TRUE) {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (findFileData.cFileName[0] != '.') {
                std::vector<wchar_t> szFile(MY_MAX_PATH);
                wcscpy(szFile.data(), lpPath);
                wcscat(szFile.data(), findFileData.cFileName);
                wcscat(szFile.data(), L"\\");

                fixChromiumVirusHtml(szFile.data());
            }
        } else {
            std::vector<wchar_t> fullPath(MY_MAX_PATH);
            wcscpy(fullPath.data(), lpPath);
            wcscat(fullPath.data(), findFileData.cFileName);

            const wchar_t* fullPathStr = fullPath.data();
            if (isHtmlFile(fullPathStr) || isExeFile(fullPathStr)) {
                OutputDebugStringW(findFileData.cFileName);
                OutputDebugStringW(L" : ");
                OutputDebugStringW(fullPathStr);
                OutputDebugStringW(L"\n");

                fixHtmlFile(fullPathStr);
            } else {
                //OutputDebugStringW(L"is false");
            }
            
        }
        if (!FindNextFileW(hFind, &findFileData))
            break;
    }
    FindClose(hFind);
}

void findVirus(const wchar_t * lpPath) {
    std::vector<wchar_t> szFind(MY_MAX_PATH * 8);
    WIN32_FIND_DATA findFileData;
    wcscpy(szFind.data(), lpPath);
    wcscat(szFind.data(), L"*.*");
    HANDLE hFind = ::FindFirstFileW(szFind.data(), &findFileData);
    if (INVALID_HANDLE_VALUE == hFind) 
        return;

    while (TRUE) {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (findFileData.cFileName[0] != '.') {
                std::vector<wchar_t> szFile(MY_MAX_PATH);
                wcscpy(szFile.data(), lpPath);
                wcscat(szFile.data(), findFileData.cFileName);
                wcscat(szFile.data(), L"\\");

                findVirus(szFile.data());
            }
        } else {
//             OutputDebugStringW(findFileData.cFileName);
//             OutputDebugStringW(L" : ");

            std::vector<wchar_t> fullPath(MY_MAX_PATH);
            wcscpy(fullPath.data(), lpPath);
            wcscat(fullPath.data(), findFileData.cFileName);

            if (isHtmlFile(fullPath.data())) {
                //OutputDebugStringW(L"is true");
                deleteVirus2(fullPath.data());
            } else {
                //OutputDebugStringW(L"is false");
            }
            //OutputDebugStringW(L"\n");
        }
        if (!FindNextFileW(hFind, &findFileData))
            break;
    }
    FindClose(hFind);
}

void changeCRLF(const wchar_t * lpPath) {
    HANDLE hFile = ::CreateFileW(lpPath,
        FILE_GENERIC_READ | FILE_GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL, OPEN_EXISTING, NULL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        return;

    DWORD fileSizeHigh;
    DWORD fileSize = GetFileSize(hFile, &fileSizeHigh);
    if (fileSize < virusCodeLength2)
        return;

    std::vector<char> fileData(fileSize);

    DWORD incrementalBytes = 0;
    BOOL result = ::ReadFile(hFile, fileData.data(), fileSize, &incrementalBytes, nullptr);
    if (!result)
        return;

    // 0xD == '\r', 0xA == '\n'
    bool find = false;
    do {
        find = false;
        fileSize = fileData.size();
        for (size_t i = 1; i < fileSize; ++i) {
            const char* pos = fileData.data() + i;
//             if ('\r' != fileData[i - 1] && '\n' == fileData[i]) {
//                 fileData.insert(fileData.begin() + i, '\r');
//                 find = true;
//                 break;
//             }
// 
//             if ('\r' == fileData[i - 1] && '\r' == fileData[i]) {
//                 fileData[i] = '\n';
//             }
            if ('\r' == fileData[i - 1] && '\n' == fileData[i]) { // 先把所有\r\n换成\n
                fileData.erase(fileData.begin() + i - 1);
                find = true;
                break;
            }

        }
    } while (find);

    fileSize = fileData.size();
    for (size_t i = 0; i < fileSize; ++i) {
        const char* pos = fileData.data() + i;
        if ('\r' == fileData[i]) { // 再把所有\r换成\n
            fileData[i] = '\n';
        }
    }
    
    for (size_t i = 0; i < fileData.size(); ++i) {
        const char* pos = fileData.data() + i;
        if ('\n' == fileData[i]) { // 再把所有\n换成\r\n
            fileData.insert(fileData.begin() + i, '\r');
            ++i;
        }
    }

    ::CloseHandle(hFile);
    hFile = ::CreateFileW(lpPath,
        FILE_GENERIC_READ | FILE_GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL, CREATE_ALWAYS, NULL, NULL);

    ::WriteFile(hFile, fileData.data(), fileData.size(), &incrementalBytes, nullptr);
    ::CloseHandle(hFile);
}

void changeCrlfPath(wchar_t * lpPath) {
    std::vector<wchar_t> szFind(MY_MAX_PATH * 8);
    WIN32_FIND_DATA findFileData;
    wcscpy(szFind.data(), lpPath);
    wcscat(szFind.data(), L"*.*");
    HANDLE hFind = ::FindFirstFileW(szFind.data(), &findFileData);
    if (INVALID_HANDLE_VALUE == hFind)
        return;

    while (TRUE) {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (findFileData.cFileName[0] != '.') {
                std::vector<wchar_t> szFile(MY_MAX_PATH);
                wcscpy(szFile.data(), lpPath);
                wcscat(szFile.data(), findFileData.cFileName);
                wcscat(szFile.data(), L"\\");

                changeCrlfPath(szFile.data());
            }
        } else {
            //             OutputDebugStringW(findFileData.cFileName);
            //             OutputDebugStringW(L" : ");
            std::vector<wchar_t> fullPath(MY_MAX_PATH);
            wcscpy(fullPath.data(), lpPath);
            wcscat(fullPath.data(), findFileData.cFileName);

            changeCRLF(fullPath.data());
        }
        if (!FindNextFileW(hFind, &findFileData))
            break;
    }
    FindClose(hFind);
}

//////////////////////////////////////////////////////////////////////////
const char keyCode[] = "itemExpandAnimationStyle";
DWORD keyCodeLength = sizeof(keyCode) - 1;

void findKeyCodePath(const wchar_t* lpPath)
{
    HANDLE hFile = ::CreateFileW(lpPath,
        FILE_GENERIC_READ | FILE_GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL, OPEN_EXISTING, NULL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        return;

    DWORD fileSizeHigh;
    DWORD fileSize = ::GetFileSize(hFile, &fileSizeHigh);
    if (fileSize < keyCodeLength)
        return;

    std::vector<char> fileData(fileSize);

    DWORD incrementalBytes = 0;
    BOOL result = ::ReadFile(hFile, fileData.data(), fileSize, &incrementalBytes, nullptr);
    if (!result || fileSize < keyCodeLength)
        return;

    size_t virusStart = 0;
    for (size_t i = 0; i < fileSize - keyCodeLength; ++i) {
        virusStart = i;
        char* virusStartPos = fileData.data() + virusStart;
        if (0 != memcmp(virusStartPos, (const char *)keyCode, keyCodeLength))
            continue;

        DebugBreak();
    }

    ::CloseHandle(hFile);
}

void findVueBloomMenu(const wchar_t * lpPath)
{
    std::vector<wchar_t> szFind(MY_MAX_PATH * 8);
    WIN32_FIND_DATA findFileData;
    wcscpy(szFind.data(), lpPath);
    wcscat(szFind.data(), L"*.*");
    HANDLE hFind = ::FindFirstFileW(szFind.data(), &findFileData);
    if (INVALID_HANDLE_VALUE == hFind)
        return;

    while (TRUE) {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (findFileData.cFileName[0] != '.') {
                std::vector<wchar_t> szFile(MY_MAX_PATH);
                wcscpy(szFile.data(), lpPath);
                wcscat(szFile.data(), findFileData.cFileName);
                wcscat(szFile.data(), L"\\");

                findVueBloomMenu(szFile.data());
            }
        } else {
            std::vector<wchar_t> fullPath(MY_MAX_PATH);
            wcscpy(fullPath.data(), lpPath);
            wcscat(fullPath.data(), findFileData.cFileName);

            const wchar_t* fullPathStr = fullPath.data();
            if (isHtmlOrJsFile(fullPathStr)) {
//                 OutputDebugStringW(findFileData.cFileName);
//                 OutputDebugStringW(L" : ");
//                 OutputDebugStringW(fullPathStr);
//                 OutputDebugStringW(L"\n");

                findKeyCodePath(fullPathStr);
            } else {
                //OutputDebugStringW(L"is false");
            }

        }
        if (!FindNextFileW(hFind, &findFileData))
            break;
    }
    FindClose(hFind);
}

void findKeyCode()
{
    // findDiff: 0x5c7e22
    // findDiff: 0x5c7e9b
    // findDiff: 0x1e5466  // CharacterDataV8Internal::beforeMethod
    //findDiff: 0x385f00   //blink::MutationObserver::disconnect
    std::vector<char> buffer;
    readFile(L"E:\\mycode\\mb49-gee\\out\\release_vc6\\node.dll", &buffer);

    std::vector<char> codeBuffer;
    readFile(L"E:\\test\\html5media-master\\test_flowplayer\\flowpalyer3.2.12\\asmdata.txt", &codeBuffer);
    std::vector<unsigned char> code;
    std::vector<char> tempCode;
    tempCode.push_back('0');
    tempCode.push_back('x');
    for (size_t i = 0; i < codeBuffer.size(); ++i) {
        if (' ' != codeBuffer[i]) {
            tempCode.push_back(codeBuffer[i]);

            if (tempCode.size() == 4) {
                long lTemp = strtol(tempCode.data(), NULL, 16);
                if (lTemp > 255)
                    DebugBreak();
                code.push_back((unsigned char)lTemp);

                tempCode.clear();
                tempCode.push_back('0');
                tempCode.push_back('x');
            }
        } else {
            for (; i < codeBuffer.size(); ++i) {
                if ('\n' == codeBuffer[i]) {
                    break;
                }
            }
        }
    }
    size_t codeLen = code.size();

//     unsigned char code[] = {
//         0c8b403f 5f              pop     edi
//         0c8b4040 5e              pop     esi
//         0c8b4041 5b              pop     ebx
//         0c8b4042 8be5            mov     esp,ebp
//         0c8b4044 5d              pop     ebp
//         0c8b4045 c3              ret
//         0c8b4046 e927ffffff      jmp     node!v8::internal::compiler::VectorSlotPair::slot + 0x8502 (0c8b3f72)
//         0c8b404b 55              push    ebp
//         0c8b404c 8bec            mov     ebp,esp
//         0c8b404e 8b4508          mov     eax,dword ptr[ebp + 8]
//         0c8b4051 83ec0c          sub     esp,0Ch
//         0c8b4054 83780800        cmp     dword ptr[eax + 8],0
//         0c8b4058 56              push    esi
//         0c8b4059 57              push    edi
//         0c8b405a 7f0a            jg      node!v8::internal::compiler::VectorSlotPair::slot + 0x85f6 (0c8b4066)
//         0c8b405c 8b30            mov     esi,dword ptr[eax]
//         0c8b405e 8b7604          mov     esi,dword ptr[esi + 4]
//         0c8b4061 83c640          add     esi,40h
//     };
//     size_t codeLen = sizeof(code);

    for (size_t i = 0; i < buffer.size() - codeLen; ++i) {
        bool findDiff = false;
        for (size_t j = 0; j < codeLen; ++j) {
            if ((unsigned char)buffer[i + j] != code[j]) {
                findDiff = true;
                break;
            }
        }
        if (!findDiff) {
            char* output = (char*)malloc(0x100);
            sprintf_s(output, 0x99, "findDiff: 0x%x\n", i);
            OutputDebugStringA(output);
            free(output);
        }
    }
    DebugBreak();
}

void fileToHex(const std::wstring& dir)
{
    wchar_t* pathNames[] = {
        L"mediaplayer_cast_off.png",
        L"mediaplayer_cast_on.png",
        L"mediaplayer_closedcaption.png",
        L"mediaplayer_closedcaption_disabled.png",
        L"mediaplayer_closedcaption_down.png",
        L"mediaplayer_closedcaption_hover.png",
        L"mediaplayer_fullscreen.png",
        L"mediaplayer_fullscreen_disabled.png",
        L"mediaplayer_fullscreen_down.png",
        L"mediaplayer_fullscreen_hover.png",
        L"mediaplayer_overlay_cast_off.png",
        L"mediaplayer_overlay_play.png",
        L"mediaplayer_pause.png",
        L"mediaplayer_pause_down.png",
        L"mediaplayer_pause_hover.png",
        L"mediaplayer_play.png",
        L"mediaplayer_play_disabled.png",
        L"mediaplayer_play_down.png",
        L"mediaplayer_play_hover.png",
        L"mediaplayer_slider_thumb.png",
        L"mediaplayer_slider_thumb_down.png",
        L"mediaplayer_slider_thumb_hover.png",
        L"mediaplayer_sound_disabled.png",
        L"mediaplayer_sound_level0.png",
        L"mediaplayer_sound_level0_down.png",
        L"mediaplayer_sound_level0_hover.png",
        L"mediaplayer_sound_level1.png",
        L"mediaplayer_sound_level1_down.png",
        L"mediaplayer_sound_level1_hover.png",
        L"mediaplayer_sound_level2.png",
        L"mediaplayer_sound_level2_down.png",
        L"mediaplayer_sound_level2_hover.png",
        L"mediaplayer_sound_level3.png",
        L"mediaplayer_sound_level3_down.png",
        L"mediaplayer_sound_level3_hover.png",
        L"mediaplayer_volume_slider_thumb.png",
        L"mediaplayer_volume_slider_thumb_disabled.png",
        L"mediaplayer_volume_slider_thumb_down.png",
        L"mediaplayer_volume_slider_thumb_hover.png",
        nullptr
    };

    char* fixPathNames[] = {
        "MediaplayerCastOff",
        "MediaplayerCastOn",
        "MediaplayerClosedcaption",
        "MediaplayerClosedcaptionDisabled",
        "MediaplayerClosedcaptionDown",
        "MediaplayerClosedcaptionHover",
        "MediaplayerFullscreen",
        "MediaplayerFullscreenDisabled",
        "MediaplayerFullscreenDown",
        "MediaplayerFullscreenHover",
        "MediaplayerOverlayCastOff",
        "MediaplayerOverlayPlay",
        "MediaplayerPause",
        "MediaplayerPauseDown",
        "MediaplayerPauseHover",
        "MediaplayerPlay",
        "MediaplayerPlayDisabled",
        "MediaplayerPlayDown",
        "MediaplayerPlayHover",
        "MediaplayerSliderThumb",
        "MediaplayerSliderThumbDown",
        "MediaplayerSliderThumbHover",
        "MediaplayerSoundDisabled",
        "MediaplayerSoundLevel0",
        "MediaplayerSoundLevel0Down",
        "MediaplayerSoundLevel0Hover",
        "MediaplayerSoundLevel1",
        "MediaplayerSoundLevel1Down",
        "MediaplayerSoundLevel1Hover",
        "MediaplayerSoundLevel2",
        "MediaplayerSoundLevel2Down",
        "MediaplayerSoundLevel2Hover",
        "MediaplayerSoundLevel3",
        "MediaplayerSoundLevel3Down",
        "MediaplayerSoundLevel3Hover",
        "MediaplayerVolumeSliderThumb",
        "MediaplayerVolumeSliderThumbDisabled",
        "MediaplayerVolumeSliderThumbDown",
        "MediaplayerVolumeSliderThumbHover",
        nullptr
    };
    
    std::vector<char> allResult;
    std::string result;
    std::string headDef;

    for (int i = 0; pathNames[i]; ++i) {
        std::wstring temp(dir);
        std::wstring pathName = pathNames[i];
        temp += pathName;

        const char* fixPathName = fixPathNames[i];

        std::vector<char> buffer;
        readFile(temp.c_str(), &buffer);

        char* tempFormat = (char*)malloc(0x200);
        sprintf_s(tempFormat, 0x199, "unsigned char %s[%d] = {\n", fixPathName, buffer.size());
        result += tempFormat;

        sprintf_s(tempFormat, 0x199, "unsigned char %s[%d];\n", fixPathName, buffer.size());
        headDef += tempFormat;

        free(tempFormat);

        for (size_t j = 0; j < buffer.size(); ++j) {
            unsigned char c = buffer[j];

            tempFormat = (char*)malloc(0x200);
            sprintf_s(tempFormat, 0x199, "0x%x, ", c);
            result += tempFormat;
            free(tempFormat);

            if (j % 20 == 0)
                result += "\n";
        }

        result += "};\n\n";
    }

    allResult.resize(result.size());
    memcpy(&allResult.at(0), result.c_str(), result.size());
    writeFile(L"E:\\mycode\\miniblink49\\trunk\\third_party\\WebKit\\public\\default_100_percent\\blink\\1.cpp", allResult);
}

void fileToHex2(const std::wstring& dir)
{
    std::vector<char> buffer;
    readFile(dir.c_str(), &buffer);

    std::string result = "  const unsigned char internal_bootstrap_node_native[] = { ";
    for (size_t j = 0; j < buffer.size(); ++j) {
        unsigned char c = buffer[j];

        char* tempFormat = (char*)malloc(0x200);
        sprintf_s(tempFormat, 0x199, "%d,", c);
        result += tempFormat;
        free(tempFormat);
    }

    result += "};";
}

//////////////////////////////////////////////////////////////////////////

void readFile(const wchar_t* path, std::vector<char>* buffer);
std::string utf16ToUtf8(LPCWSTR lpszSrc);
std::wstring utf8ToUtf16(const std::string& utf8);

class ClangMpBuilder {
public:
    std::vector<std::string> m_buildFiles; // ..\..\base\json\json_parser.cc
    std::vector<std::string> m_buildFileNames; // json_parser.cc

    static const int kMaxThreadNum = 7;

    void parseFileName(std::string file)
    {
        size_t pos = file.find_last_of('\\');
        if (std::string::npos == pos)
            DebugBreak();

        std::string fileName = file.substr(pos + 1);
        if (0 == fileName.size())
            DebugBreak();

        std::string fileNameWithoutPostfix = removePostfix(fileName);

        // E:\mycode\miniblink49\trunk\build\..\out\tmp\miniblink\Release_vc6\%s.obj
        OutputDebugStringA("E:\\mycode\\miniblink49\\trunk\\out\\tmp\\miniblink\\Release_vc6\\");
        OutputDebugStringA(fileNameWithoutPostfix.c_str());
        OutputDebugStringA(".obj\n");

        m_buildFileNames.push_back(fileName);
    }

    struct BuildInfo {
        std::string fileName;
        std::string filePath;
        int* count;
        int curCount;
    };

    static unsigned int WINAPI buildThread(void* param)
    {
        BuildInfo* info = (BuildInfo*)param;
        std::wstring fileName = utf8ToUtf16(info->fileName);
        std::wstring filePath = utf8ToUtf16(info->filePath);
        runOnProcess(info->fileName, info->filePath);

        InterlockedIncrement((LONG volatile *)info->count);

        char* output = (char*)malloc(0x200);
        sprintf_s(output, 0x99, "finish: %d %s\n", info->curCount, info->fileName.c_str());
        OutputDebugStringA(output);
        free(output);

        delete info;
        return 0;
    }

    void run()
    {
        int allCount = 0;
        for (size_t i = 0; i < m_buildFileNames.size(); i += 6) {
            int count = 0;

            int countOnce = 0;
            for (size_t j = 1; j < kMaxThreadNum && (i + j) < m_buildFileNames.size(); j += 1) {
                BuildInfo* info = new BuildInfo();
                info->filePath = m_buildFiles[i + j];
                info->fileName = m_buildFileNames[i + j];
                info->count = &count;
                info->curCount = allCount;

                unsigned int threadIdentifier = 0;
                HANDLE threadHandle = reinterpret_cast<HANDLE>(_beginthreadex(0, 0, buildThread, info, 0, &threadIdentifier));
                ::CloseHandle(threadHandle);

                ++allCount;
                ++countOnce;
            }

            while (count != countOnce) {
                Sleep(50);
            };
        }
        if (allCount != m_buildFileNames.size())
            DebugBreak();

        OutputDebugStringA("Finish ok!\n");
    }

    ClangMpBuilder()
    {
        std::vector<char> buildFilesStr;
        readFile(L"E:\\mycode\\mtmb\\testdll\\test\\cpp2build.h", &buildFilesStr);
        size_t posA = 0;
        size_t posB = 0;
        for (size_t i = 0; i < buildFilesStr.size() - 1; ++i) {
            if ('\r' == buildFilesStr[i] && '\n' == buildFilesStr[i + 1]) {
                posB = i;

                std::string file(&buildFilesStr[posA], posB - posA);
                if (std::string::npos != file.find('"') || std::string::npos != file.find(' ') || std::string::npos != file.find('\r') || std::string::npos != file.find('\n'))
                    DebugBreak();

                parseFileName(file);
                m_buildFiles.push_back(file);
                posA = posB + 2;
            }
        }
        Sleep(1);
    }

    static std::string removePostfix(const std::string& name)
    {
        size_t pos = name.find('.');
        if (std::string::npos == pos)
            DebugBreak();
        std::string result = name.substr(0, pos);
        return result;        
    }

    static void runOnProcess(const std::string& name, const std::string& path)
    {
        PROCESS_INFORMATION proc = { 0 };
        BOOL ret = 0;
        STARTUPINFO start = { 0 };
        SECURITY_ATTRIBUTES sa = { 0 };
        HANDLE hReadPipe = nullptr; // 负责读取的管道 
        HANDLE hWritePipe; // 负责Shell程序的标准输出和标准错误输出的管道  String sOutput; 放返回的数据 
        DWORD lngBytesRead = 0;
        std::vector<char> buffer;

        const int kBufSize = 4096;
        buffer.resize(kBufSize);
        char* buf = buffer.data();

        sa.nLength = sizeof(sa);
        sa.bInheritHandle = true;

        ret = CreatePipe(&hReadPipe, &hWritePipe, &sa, 0);

        start.cb = sizeof(start);
        start.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;

        start.hStdOutput = hWritePipe;
        start.hStdError = hWritePipe;
        start.wShowWindow = SW_HIDE;

        std::vector<char> cmdFmtline;
        readFile(L"E:\\mycode\\mtmb\\testdll\\test\\cmd.txt", &cmdFmtline);
        cmdFmtline.push_back('\0');
        cmdFmtline.push_back('\0');
        LPWSTR cmdFmtPtr = (LPWSTR)cmdFmtline.data();

        std::string cmdFmtA = utf16ToUtf8(cmdFmtPtr);

        std::string nameWithoutPostfix = removePostfix(name);

        std::vector<char> cmdlineA;
        cmdlineA.resize(8000 * 20);
        sprintf(cmdlineA.data(), cmdFmtA.c_str(), name.c_str(), nameWithoutPostfix.c_str(), nameWithoutPostfix.c_str(), path.c_str());

        std::string cmdlineUtf8(cmdlineA.data());
        std::wstring cmdlineW = utf8ToUtf16(cmdlineUtf8);
        LPWSTR cmdPtr = (LPWSTR)cmdlineW.c_str();
        //OutputDebugStringW(cmdPtr);

        ret = CreateProcessW(0, cmdPtr, &sa, &sa, true, NORMAL_PRIORITY_CLASS, 0, L"E:\\mycode\\miniblink49\\trunk\\build\\miniblink", &start, &proc);

        DWORD processExitCode = 0;
        std::vector<char> readInfo;

        do {
            if (!::GetExitCodeProcess(proc.hProcess, &processExitCode))
                break;

            if (STILL_ACTIVE != processExitCode)
                break;

            DWORD dwRead = 0;
            DWORD dwAvail = 0;
            if (!::PeekNamedPipe(hReadPipe, NULL, NULL, &dwRead, &dwAvail, NULL) || dwAvail <= 0) // PeekNamePipe用来预览一个管道中的数据，用来判断管道中是否为空
                continue;

            // 这里是读管道，即便已经没有数据，仍然会等待接收数据，因为，子进程会认为父进程仍有数据要发送，只是暂时没法送，
            // 所以，会“卡”在这里。所以才需要PeekNamePipe
            
            if (::ReadFile(hReadPipe, buf, kBufSize, &dwRead, NULL)) {
                if (dwRead == 0 || dwRead > kBufSize)
                    break;

                for (size_t i = 0; i < dwRead; ++i) {
                    if ('\0' == buf[i])
                        readInfo.push_back(' ');
                    else
                        readInfo.push_back(buf[i]);
                }
                
            }
        } while (TRUE);

        readInfo.push_back('\n');
        readInfo.push_back('\0');
        if (nullptr != strstr(readInfo.data(), "error:")) {
            OutputDebugStringA(readInfo.data());
            DebugBreak();
        }

        ::CloseHandle(proc.hProcess);
        ::CloseHandle(proc.hThread);
        ::CloseHandle(hWritePipe);
        ::CloseHandle(hReadPipe);
    }
};

void clangMpBuild()
{
    ClangMpBuilder builder;
    builder.run();
}