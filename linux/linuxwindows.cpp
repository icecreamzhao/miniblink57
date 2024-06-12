
#if !defined(WIN32)
#include "base/strings/utf_string_conversions.h"
#include "base/time/time.h"
#include "mbvip/common/StringUtil.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <utility>
#include <stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
#include <signal.h>
#include <dlfcn.h>

#ifndef __x86_64__
# define _STAT_VER_LINUX	3
#else
# define _STAT_VER_LINUX	1
#endif

#define _STAT_VER		_STAT_VER_LINUX

void* __libc_stack_end;

namespace base {
namespace win {

bool IsUser32AndGdi32Available()
{
    return true;
}

} // namespace win

namespace debug {

void GDIBitmapAllocFailure(BITMAPINFOHEADER* header, HANDLE shared_section)
{
    DebugBreak();
}

} // namespace debug

}

extern "C" uint32_t __cdecl _byteswap_ulong(uint32_t num)
{
    return __builtin_bswap32(num);
}

extern "C" unsigned short __cdecl _byteswap_ushort(unsigned short num)
{
    return __builtin_bswap16(num);
}

extern "C" int __cdecl __cxa_atexit(void (*func) (void *), void * arg, void * dso_handle);
extern "C" int __cdecl open(char const* _FileName, int _OpenFlag, ...);
// extern "C" int __cdecl read(int _FileHandle, void* _DstBuf, unsigned int _MaxCharCount);
// extern "C" int __cdecl close(int _FileHandle);
// extern "C" int __cdecl write(int _FileHandle, void const* _Buf, unsigned int _MaxCharCount);

extern "C" int _open(char const* const _FileName, int const _OFlag, int const _PMode)
{
    return open(_FileName, _OFlag, _PMode);
}

extern "C" int __cdecl _close(int _FileHandle)
{
    return close(_FileHandle);
}

// https://refspecs.linuxbase.org/LSB_3.0.0/LSB-PDA/LSB-PDA/baselib-xstat-1.html
// https://blog.csdn.net/pk_20140716/article/details/77198747?spm=1001.2101.3001.6650.7&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-7.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-7.pc_relevant_default&utm_relevant_index=12
extern "C" int __cdecl atexit(void(__cdecl*)(void))
{
    return 0;
}
extern "C" int __cdecl __xstat64(int __ver, const char* __filename, struct stat64* __stat_buf);
extern "C" int __cdecl __xstat(int ver, const char* path, struct stat* stat_buf);
extern "C" int __cdecl __lxstat(int ver, const char* path, struct stat* stat_buf);
extern "C" int __cdecl __fxstat(int ver, int fildes, struct stat* stat_buf);
extern "C" int __cdecl __fxstat64(int ver, int fildes, struct stat64* stat_buf);
extern "C" int __cdecl __lxstat64(int ver, const char* path, struct stat64* stat_buf);

extern "C" int __cdecl stat64(int __ver, const char* __filename, struct stat64* __stat_buf)
{
    return __xstat64(__ver, __filename, __stat_buf);
}

extern "C" int __cdecl _read(int _FileHandle, void* _DstBuf, unsigned int _MaxCharCount)
{
    return read(_FileHandle, _DstBuf, _MaxCharCount);
}

extern "C" int __cdecl _write(int _FileHandle, void const* _Buf, unsigned int _MaxCharCount)
{
    return write(_FileHandle, _Buf, _MaxCharCount);
}

extern "C" int __cdecl lstat(const char* path, struct stat* stat_buf)
{
    return __lxstat(_STAT_VER, path, stat_buf);
}

extern "C" int __cdecl lstat64(const char* path, struct stat64* stat_buf)
{
    return __lxstat64(_STAT_VER, path, stat_buf);
}

extern "C" int __cdecl stat(const char* path, struct stat* stat_buf)
{
    return __xstat(_STAT_VER, path, stat_buf);
}

extern "C" int __cdecl fstat64(int fd, struct stat64* buf)
{
    return __fxstat64(_STAT_VER, fd, buf);
}

extern "C" int __cdecl fstat(int fd, struct stat* buf)
{
    return __fxstat(_STAT_VER, fd, buf);
}

//------------------------------

extern "C" void DebugBreak()
{
    printf("DebugBreak!\n");
    __debugbreak();
}

extern "C" VOID OutputDebugStringA(LPCSTR lpOutputString)
{
    if (!lpOutputString)
        return;
    size_t len = strlen(lpOutputString);
    if (0 == len)
        return;

    std::vector<char> str(len);
    for (size_t i = 0; i < len; ++i) {
        if ('%' == lpOutputString[i])
            str[i] = '|';
        else
            str[i] = lpOutputString[i];
    }
    str.push_back('\0');
    if (len > 200)
        str[199] = '\0';
    printf(str.data());
}

extern "C" VOID OutputDebugStringW(LPCWSTR lpOutputString)
{
    if (!lpOutputString)
        return;
    size_t len = u16len(lpOutputString);
    if (0 == len)
        return;

    std::string str;
    base::UTF16ToUTF8(lpOutputString, len, &str);
    OutputDebugStringA(str.c_str());
}

static void handlePipe(int sig)
{
    //�����κδ�����
    printf("handlePipe!!!\n");
}

static void disablePipeError()
{
    struct sigaction sa;
    sa.sa_handler = SIG_IGN;
    sigaction(SIGPIPE, &sa, 0);

    // signal���õ��źž��ֻ����һ�����ã��źű�����һ�κ��źž���ͻᱻ��ԭ��Ĭ��ֵ�ˡ�
    // sigaction���õ��źž��������һֱ��Ч��ֵ�����ٴθı��������á�
    struct sigaction action;
    action.sa_handler = handlePipe;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGPIPE, &action, NULL);
}

typedef unsigned int (*FN_StartAddress)(void*);

void* _beginthreadexWrap(void* arg)
{
    disablePipeError();
    std::pair<void*, void*>* info = (std::pair<void*, void*>*)arg;
    FN_StartAddress startAddress = (FN_StartAddress)info->first;
    startAddress(info->second);
    delete info;
    return nullptr;
}

uintptr_t _beginthreadex(
    void* security,
    unsigned int stackSize,
    unsigned int (*startAddress)(void*),
    void* arglist,
    unsigned int initflag,
    unsigned int* thrdaddr)
{
    pthread_t tid;
    std::pair<void*, void*>* info = new std::pair<void*, void*>((void*)startAddress, arglist);
    pthread_create(&tid, NULL, &_beginthreadexWrap, info);
    return 1;
}

void* CreateThreadWrap(void* arg)
{
    disablePipeError();
    std::pair<void*, void*>* info = (std::pair<void*, void*>*)arg;
    PTHREAD_START_ROUTINE startAddress = (PTHREAD_START_ROUTINE)info->first;
    startAddress(info->second);
    delete info;
    return nullptr;
}

HANDLE CreateThread(
    void* lpThreadAttributes,
    SIZE_T dwStackSize,
    LPTHREAD_START_ROUTINE lpStartAddress,
    LPVOID lpParameter,
    DWORD dwCreationFlags,
    LPDWORD lpThreadId)
{
    printf("CreateThread\n");
    pthread_t tid;
    std::pair<void*, void*>* info = new std::pair<void*, void*>((void*)lpStartAddress, lpParameter);
    pthread_create(&tid, NULL, &CreateThreadWrap, info);
    return NULL;
}

HMODULE GetModuleHandleW(LPCWSTR lpModuleName)
{
    printf("GetModuleHandleW\n");
    return NULL;
}

BOOL SetForegroundWindow(HWND hWnd)
{
    printf("SetForegroundWindow\n");
    return FALSE;
}

BOOL PostMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    printf("PostMessageW\n");
    return FALSE;
}

BOOL PathIsDirectoryW(LPCWSTR pszPath)
{
    printf("PathIsDirectoryW\n");
    return FALSE;
}

BOOL TextOutW(HDC hdc, int x, int y, LPCWSTR lpString, int c)
{
    printf("TextOutW\n");
    return FALSE;
}

HPEN CreatePen(int iStyle, int cWidth, COLORREF color)
{
    printf("CreatePen\n");
    return NULL;
}

int GetObject(HANDLE h, int c, LPVOID pv)
{
    printf("GetObject\n");
    return 0;
}

BOOL DeleteObject(HGDIOBJ ho)
{
    printf("DeleteObject\n");
    return FALSE;
}

HDC GetDC(HWND hWnd)
{
    printf("GetDC\n");
    DebugBreak();
    return NULL;
}

HDC GetDCEx(HWND hWnd, HRGN hrgnClip, DWORD flags)
{
    printf("GetDCEx\n");
    return NULL;
}

int ReleaseDC(HWND hWnd, HDC hDC)
{
    printf("ReleaseDC\n");
    return 0;
}

void* GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{
    //printf("GetProcAddress:%s\n", lpProcName);
    return dlsym(hModule, lpProcName);
}

HDC CreateCompatibleDC(HDC hdc)
{
    printf("GetProcAddress\n");
    return NULL;
}

HGDIOBJ GetCurrentObject(HDC hdc, UINT type)
{
    printf("GetCurrentObject\n");
    return NULL;
}

HGDIOBJ SelectObject(HDC hdc, HGDIOBJ h)
{
    printf("SelectObject\n");
    return NULL;
}
int SetBkMode(HDC hdc, int mode)
{
    printf("SetBkMode\n");
    return 0;
}
COLORREF SetBkColor(HDC hdc, COLORREF color)
{
    printf("GetCurrentObject\n");
    return 0;
}
HBITMAP CreateBitmap(int nWidth, int nHeight, UINT nPlanes, UINT nBitCount, const void* lpBits)
{
    printf("CreateBitmap\n");
    return NULL;
}
HICON CreateIconIndirect(PICONINFO piconinfo)
{
    printf("CreateIconIndirect\n");
    return NULL;
}
HBITMAP CreateCompatibleBitmap(HDC hdc, int cx, int cy)
{
    printf("CreateCompatibleBitmap\n");
    return NULL;
}
COLORREF SetTextColor(HDC hdc, COLORREF color)
{
    printf("SetTextColor\n");
    return 0;
}
BOOL BitBlt(HDC hdc, int x, int y, int cx, int cy, HDC hdcSrc, int x1, int y1, DWORD rop)
{
    printf("BitBlt\n");
    return FALSE;
}

VOID Sleep(DWORD dwMilliseconds)
{
    usleep(dwMilliseconds * 1000);
}

HICON LoadIconW(HINSTANCE hInstance, LPCWSTR lpIconName)
{
    return NULL;
}

HANDLE CreateEventW(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState, LPCWSTR lpName)
{
    printf("CreateEventW\n");
    return NULL;
}

HANDLE FindFirstFileW(LPCWSTR lpFileName, LPWIN32_FIND_DATAW lpFindFileData)
{
    printf("FindFirstFileW\n");
    return NULL;
}
BOOL FindClose(HANDLE hFindFile)
{
    printf("FindClose\n");
    return FALSE;
}
BOOL PathAppendW(LPWSTR pszPath, LPCWSTR pMore)
{
    printf("PathAppendW\n");
    return FALSE;
}

DWORD GetTempPathW(DWORD nBufferLength, LPWSTR lpBuffer)
{
    printf("GetTempPathW\n");
    return 0;
}

BOOL FindNextFileW(HANDLE hFindFile, LPWIN32_FIND_DATAW lpFindFileData)
{
    printf("FindNextFileW\n");
    return FALSE;
}

HFONT CreateFontW(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, DWORD bItalic,
    DWORD bUnderline, DWORD bStrikeOut, DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision,
    DWORD iQuality, DWORD iPitchAndFamily, LPCWSTR pszFaceName)
{
    printf("CreateFontW\n");
    return NULL;
}

BOOL CloseHandle(HANDLE hObject)
{
    printf("CloseHandle~\n");
    //*(int*)1 = 1;
    return FALSE;
}
BOOL SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags)
{
    printf("SetWindowPos\n");
    return FALSE;
}

BOOL PathRemoveFileSpecW(LPWSTR pszPath)
{
    printf("PathRemoveFileSpecW\n");
    return FALSE;
}
DWORD GetModuleFileNameW(HMODULE hModule, LPWSTR lpFilename, DWORD nSize)
{
    printf("GetModuleFileNameW\n");
    return 0;
}
HMODULE LoadLibraryW(LPCWSTR lpLibFileName)
{
    printf("LoadLibraryW\n");
    return NULL;
}
int MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
    printf("MessageBoxA\n");
    return 0;
}
int MessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
    printf("MessageBoxW\n");
    return 0;
}
int GetDeviceCaps(HDC hdc, int index)
{
    printf("GetDeviceCaps\n");
    DebugBreak();
    return 0;
}
BOOL GetTextExtentPoint32W(HDC hdc, LPCWSTR lpString, int c, LPSIZE psizl)
{
    printf("GetTextExtentPoint32W\n");
    return FALSE;
}

HWND GetActiveWindow()
{
    printf("GetActiveWindow\n");
    return NULL;
}
HWND GetParent(HWND hWnd)
{
    printf("GetParent\n");
    return NULL;
}
BOOL EnableWindow(HWND hWnd, BOOL bEnable)
{
    printf("EnableWindow\n");
    return FALSE;
}

BOOL SetRectRgn(HRGN hrgn, int left, int top, int right, int bottom)
{
    printf("SetRectRgn\n");
    return FALSE;
}
int CombineRgn(HRGN hrgnDst, HRGN hrgnSrc1, HRGN hrgnSrc2, int iMode)
{
    printf("CombineRgn\n");
    return 0;
}

DWORD GetClipboardSequenceNumber()
{
    printf("GetClipboardSequenceNumber\n");
    return 0;
}
BOOL IsClipboardFormatAvailable(UINT format)
{
    printf("IsClipboardFormatAvailable\n");
    return FALSE;
}

HMONITOR MonitorFromPoint(POINT pt, DWORD dwFlags)
{
    printf("MonitorFromPoint\n");
    return NULL;
}
BOOL GetMonitorInfoW(HMONITOR hMonitor, LPMONITORINFO lpmi)
{
    printf("GetMonitorInfoW\n");
    return FALSE;
}

DWORD GetCurrentThreadId()
{
    pthread_t id = pthread_self();
    DWORD ret = 0;

    if (sizeof(pthread_t) == 8)
        ret = WTF::hashInt((uint64_t)id);
    else
        ret = id;
    return (DWORD)id;
}

UINT_PTR SetTimer(HWND hWnd, UINT_PTR nIDEvent, UINT uElapse, TIMERPROC lpTimerFunc)
{
    printf("SetTimer\n");
    return 0;
}

BOOL Rectangle(HDC hdc, int left, int top, int right, int bottom)
{
    printf("Rectangle\n");
    return FALSE;
}

BOOL UpdateWindow(HWND hWnd)
{
    printf("UpdateWindow\n");
    return TRUE;
}

HRGN CreateRectRgn(int x1, int y1, int x2, int y2)
{
    printf("CreateRectRgn\n");
    DebugBreak();
    return NULL;
}

BOOL KillTimer(HWND hWnd, UINT_PTR uIDEvent)
{
    printf("KillTimer\n");
    return FALSE;
}

HRESULT RevokeDragDrop(HWND hwnd)
{
    printf("RevokeDragDrop\n");
    return 0;
}
BOOL GetWindowRect(HWND hWnd, LPRECT lpRect)
{
    printf("GetWindowRect\n");
    return FALSE;
}

BOOL DestroyIcon(HICON hIcon)
{
    printf("DestroyIcon\n");
    return FALSE;
}
HCURSOR SetCursor(HCURSOR hCursor)
{
    printf("SetCursor\n");
    __debugbreak();
    return NULL;
}
HWND GetFocus()
{
    printf("GetFocus\n");
    return NULL;
}

HRESULT OleInitialize(IN LPVOID pvReserved)
{
    return 0;
}
#if defined(__cplusplus)
class IDropTarget;
HRESULT RegisterDragDrop(HWND hwnd, IDropTarget* pDropTarget)
{
    printf("RegisterDragDrop\n");
    return 0;
}
#endif

DWORD TlsAlloc()
{
    DebugBreak();
    pthread_key_t key;
    pthread_key_create(&key, NULL);
    return (DWORD)key;
}

LPVOID TlsGetValue(DWORD dwTlsIndex)
{
    return pthread_getspecific((pthread_key_t)dwTlsIndex);
}

BOOL TlsSetValue(DWORD dwTlsIndex, LPVOID lpTlsValue)
{
    pthread_setspecific((pthread_key_t)dwTlsIndex, lpTlsValue);
    return TRUE;
}

BOOL TlsFree(DWORD dwTlsIndex)
{
    pthread_key_delete((pthread_key_t)dwTlsIndex);
    return TRUE;
}

// DWORD GetFileSize(HANDLE hFile, LPDWORD lpFileSizeHigh)
// {
//     printf("GetFileSize\n");
//     DebugBreak();
//     return 0;
// }

BOOL ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, void* lpOverlapped)
{
    printf("ReadFile\n");
    return FALSE;
}

DWORD GetCurrentProcessId()
{
    pid_t pid = getpid();
    return pid;
}

HANDLE CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
    printf("CreateFileA\n");
    return NULL;
}
HANDLE CreateFileW(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
    printf("CreateFileW\n");
    return NULL;
}
BOOL WriteFile(HANDLE hFile, const VOID* lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, void* lpOverlapped)
{
    printf("WriteFile\n");
    return FALSE;
}
LPWSTR PathFindFileNameW(LPWSTR pszPath)
{
    printf("PathFindFileNameW\n");
    return NULL;
}

LPVOID GlobalLock(HGLOBAL hMem)
{
    printf("GlobalLock\n");
    return NULL;
}
BOOL GlobalUnlock(HGLOBAL hMem)
{
    printf("GlobalUnlock\n");
    return FALSE;
}
HGLOBAL GlobalFree(HGLOBAL hMem)
{
    printf("GlobalUnlock\n");
    return NULL;
}
HGLOBAL GlobalAlloc(UINT uFlags, SIZE_T dwBytes)
{
    printf("GlobalAlloc\n");
    return NULL;
}
SIZE_T GlobalSize(HGLOBAL hMem)
{
    printf("GlobalSize\n");
    return 0;
}
BOOL EmptyClipboard()
{
    printf("EmptyClipboard\n");
    return FALSE;
}
HANDLE SetClipboardData(UINT uFormat, HANDLE hMem)
{
    printf("SetClipboardData\n");
    return NULL;
}
BOOL DeleteDC(HDC hdc)
{
    printf("DeleteDC\n");
    return FALSE;
}

BOOL ImpersonateAnonymousToken(HANDLE ThreadHandle)
{
    printf("ImpersonateAnonymousToken\n");
    return FALSE;
}

HANDLE GetCurrentThread()
{
    printf("GetCurrentThread\n");
    return NULL;
}
BOOL RevertToSelf()
{
    printf("RevertToSelf\n");
    return FALSE;
}
BOOL OpenClipboard(HWND hWndNewOwner)
{
    printf("OpenClipboard\n");
    return FALSE;
}
BOOL CloseClipboard()
{
    printf("CloseClipboard\n");
    return FALSE;
}

void InitializeCriticalSection(CRITICAL_SECTION* lpCriticalSection)
{
    pthread_mutex_init(&(lpCriticalSection->mutex), NULL);
}

void EnterCriticalSection(CRITICAL_SECTION* lpCriticalSection)
{
    pthread_mutex_lock(&(lpCriticalSection->mutex));
}

void LeaveCriticalSection(CRITICAL_SECTION* lpCriticalSection)
{
    pthread_mutex_unlock(&(lpCriticalSection->mutex));
}

VOID DeleteCriticalSection(CRITICAL_SECTION* lpCriticalSection)
{
    pthread_mutex_destroy(&(lpCriticalSection->mutex));
}

BOOL TryEnterCriticalSection(CRITICAL_SECTION* lpCriticalSection)
{
    int rv = pthread_mutex_trylock(&(lpCriticalSection->mutex));
    DCHECK(rv == 0 || rv == EBUSY) << ". " << strerror(rv);
    return rv == 0;
}

BOOL AppendMenuW(HMENU hMenu, UINT uFlags, UINT_PTR uIDNewItem, LPCWSTR lpNewItem)
{
    printf("AppendMenuW\n");
    return FALSE;
}
BOOL DestroyMenu(HMENU hMenu)
{
    printf("DestroyMenu\n");
    return FALSE;
}
HMENU CreatePopupMenu()
{
    printf("CreatePopupMenu\n");
    return NULL;
}
int GetMenuItemCount(HMENU hMenu)
{
    printf("GetMenuItemCount\n");
    return 0;
}
BOOL ReleaseCapture()
{
    printf("ReleaseCapture\n");
    return FALSE;
}
HWND SetCapture(HWND hWnd)
{
    printf("SetCapture\n");
    return NULL;
}

BOOL PtInRect(CONST RECT* prc, POINT pt)
{
    return ((pt.x >= prc->left) && (pt.x < prc->right) && (pt.y >= prc->top) && (pt.y < prc->bottom));
}

BOOL IsWindowVisible(HWND hWnd)
{
    printf("IsWindowVisible\n");
    return FALSE;
}
UINT GetDoubleClickTime()
{
    printf("GetDoubleClickTime\n");
    return 0;
}
HWND SetFocus(HWND hWnd)
{
    printf("SetFocus\n");
    return NULL;
}

BOOL SystemParametersInfoW(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fWinIni)
{
    if (SPI_GETWHEELSCROLLLINES == uiAction || SPI_GETWHEELSCROLLCHARS == uiAction) {
        ULONG* scrollLines = (ULONG*)pvParam;
        *scrollLines = 3;
        return TRUE;
    }
         
    printf("SystemParametersInfoW is not impl\n");
    return FALSE;
}

BOOL TrackPopupMenuEx(HMENU, UINT, int, int, HWND, LPTPMPARAMS)
{
    printf("TrackPopupMenuEx\n");
    return FALSE;
}

DWORD GetLastError(VOID)
{
    printf("GetLastError\n");
    return 0;
}
void PathStripPathW(LPWSTR pszPath)
{
    printf("PathStripPathW\n");
}

DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds)
{
    printf("WaitForSingleObject\n");
    return 0;
}
BOOL UnregisterClassW(LPCWSTR lpClassName, HINSTANCE hInstance)
{
    printf("UnregisterClassW\n");
    return FALSE;
}

UINT RegisterWindowMessageW(LPCWSTR lpString)
{
//     unsigned int hash = common::hashStringW(lpString);
//     std::string str = common::utf16ToUtf8(lpString);
//     printf("RegisterWindowMessageW:%d, %s\n", hash, str.c_str());
//     return hash;
    return 0;
}

BOOL SetEvent(HANDLE hEvent)
{
    printf("SetEvent\n");
    return FALSE;
}
UINT timeBeginPeriod(UINT uPeriod)
{
    printf("timeBeginPeriod\n");
    return 0;
}
UINT timeEndPeriod(UINT uPeriod)
{
    printf("timeEndPeriod\n");
    return 0;
}
HANDLE GetClipboardData(UINT uFormat)
{
    printf("GetClipboardData\n");
    return NULL;
}
BOOL QueryPerformanceCounter(LARGE_INTEGER* lpPerformanceCount)
{
    int64_t val = (DWORD)base::Time::Now().ToInternalValue();
    lpPerformanceCount->QuadPart = (unsigned __int64)val;
    return TRUE;
}

DWORD GetTickCount()
{
    return (DWORD)base::Time::Now().ToInternalValue();
}

BOOL AlphaBlend(HDC hdcDest, int xoriginDest, int yoriginDest, int wDest, int hDest, HDC hdcSrc, int xoriginSrc, int yoriginSrc, int wSrc, int hSrc, BLENDFUNCTION ftn)
{
    printf("AlphaBlend\n");
    return FALSE;
}
BOOL GdiAlphaBlend(HDC hdcDest, int xoriginDest, int yoriginDest, int wDest, int hDest, HDC hdcSrc, int xoriginSrc, int yoriginSrc, int wSrc, int hSrc, BLENDFUNCTION ftn)
{
    printf("GdiAlphaBlend\n");
    return FALSE;
}
HBITMAP CreateDIBSection(HDC hdc, CONST BITMAPINFO* lpbmi, UINT usage, VOID** ppvBits, HANDLE hSection, DWORD offset)
{
    printf("CreateDIBSection\n");
    return NULL;
}
BOOL UpdateLayeredWindow(HWND hWnd, HDC hdcDst, POINT* pptDst, SIZE* psize, HDC hdcSrc, POINT* pptSrc, COLORREF crKey, BLENDFUNCTION* pblend, DWORD dwFlags)
{
    printf("UpdateLayeredWindow\n");
    return FALSE;
}

VOID GetSystemTime(SYSTEMTIME* lpSystemTime)
{
    printf("GetSystemTime\n");
}
BOOL QueryPerformanceFrequency(LARGE_INTEGER* lpFrequency)
{
    printf("QueryPerformanceFrequency\n");
    return FALSE;
}

/*FILE*/void* _wfopen(const wchar_t* _FileName, const wchar_t* _Mode)
{
    printf("_wfopen\n");
    return NULL;
}
HINSTANCE ShellExecuteA(HWND hwnd, LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd)
{
    printf("ShellExecuteA\n");
    return NULL;
}
BOOL PathFileExistsW(LPCWSTR pszPath)
{
    printf("PathFileExistsW\n");
    return FALSE;
}
DWORD GetCurrentDirectoryW(DWORD nBufferLength, LPWSTR lpBuffer)
{
    printf("GetCurrentDirectoryW\n");
    return 0;
}

BOOL GetClassInfoW(HINSTANCE hInstance, LPCWSTR lpClassName, LPWNDCLASSW lpWndClass)
{
    printf("GetClassInfoW\n");
    return FALSE;
}
void DragAcceptFiles(HWND hWnd, BOOL fAccept)
{
    printf("DragAcceptFiles\n");
}
HANDLE RemovePropW(HWND hWnd, LPCWSTR lpString)
{
    printf("RemovePropW\n");
    return NULL;
}

BOOL IntersectRect(LPRECT prcDst, CONST RECT *prcSrc1, CONST RECT *prcSrc2)
{
    prcDst->left  = std::max(prcSrc1->left, prcSrc2->left);
    prcDst->right = std::min(prcSrc1->right, prcSrc2->right);

    // check for empty rect
    if (prcDst->left < prcDst->right) {
        prcDst->top = std::max(prcSrc1->top, prcSrc2->top);
        prcDst->bottom = std::min(prcSrc1->bottom, prcSrc2->bottom);

        // check for empty rect
        if (prcDst->top < prcDst->bottom)
            return TRUE; // not empty
    }

    memset(prcDst, 0, sizeof(RECT));
    return FALSE;
}

UINT DragQueryFileW(HDROP hDrop, UINT iFile, LPWSTR lpszFile, UINT cch)
{
    printf("DragQueryFileW\n");
    return 0;
}
BOOL SetWindowTextW(HWND hWnd, LPCWSTR lpString)
{
    printf("SetWindowTextW\n");
    return FALSE;
}
void DragFinish(HDROP hDrop)
{
    printf("DragFinish\n");
    return;
}
HGDIOBJ GetStockObject(int i)
{
    printf("GetStockObject\n");
    return NULL;
}

HIMC ImmGetContext(IN HWND)
{
    printf("ImmGetContext\n");
    return 0;
}
BOOL ImmSetCompositionWindow(HIMC, LPCOMPOSITIONFORM lpCompForm)
{
    printf("ImmSetCompositionWindow\n");
    return FALSE;
}
BOOL ImmReleaseContext(HWND, HIMC)
{
    printf("ImmReleaseContext\n");
    return FALSE;
}
int GetSystemMetrics(int nIndex)
{
    printf("GetSystemMetrics\n");
    return 0;
}
BOOL MoveWindow(HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint)
{
    printf("MoveWindow\n");
    return FALSE;
}
LONG ImmGetCompositionStringW(HIMC, DWORD, LPVOID lpBuf, DWORD dwBufLen)
{
    printf("ImmGetCompositionStringW\n");
    return 0;
}
BOOL DeleteFileW(LPCWSTR lpFileName)
{
    printf("DeleteFileW\n");
    return FALSE;
}
BOOL TerminateProcess(HANDLE hProcess, UINT uExitCode)
{
    printf("TerminateProcess\n");
    __debugbreak();
    std::exit(uExitCode);
    return FALSE;
}
void CoUninitialize(void)
{

}
VOID GetLocalTime(LPSYSTEMTIME lpSystemTime)
{
    printf("GetLocalTime\n");
}

BOOL PostThreadMessageW(DWORD idThread, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    printf("PostThreadMessageW\n");
    return FALSE;
}

int GetWindowTextW(HWND hWnd, LPWSTR lpString, int nMaxCount)
{
    printf("GetWindowTextW\n");
    return 0;
}
VOID PostQuitMessage(int nExitCode)
{
    printf("PostQuitMessage\n");
}
HBRUSH CreateSolidBrush(COLORREF color)
{
    printf("CreateSolidBrush\n");
    return NULL;
}
int FillRect(HDC hDC, CONST RECT* lprc, HBRUSH hbr)
{
    printf("FillRect\n");
    return 0;
}
LRESULT SendMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    printf("SendMessageW\n");
    return 0;
}
BOOL PtInRegion(HRGN hrgn, int x, int y)
{
    printf("PtInRegion\n");
    return FALSE;
}

VOID SetLastError(DWORD dwErrCode)
{
    printf("SetLastError\n");
}

HRGN CreateRectRgnIndirect(CONST RECT* lprect)
{
    printf("CreateRectRgnIndirect\n");
    return NULL;
}

BOOL SetWorldTransform(HDC hdc, CONST XFORM* lpxf)
{
    printf("SetWorldTransform\n");
    return FALSE;
}

BOOL GdiFlush(void)
{
    printf("GdiFlush\n");
    return FALSE;
}

HRESULT SHGetFolderPathW(HWND hwnd, int csidl, HANDLE hToken, DWORD dwFlags, LPWSTR pszPath)
{
    printf("SHGetFolderPathW\n");
    return 0;
}

DWORD SetFilePointer(HANDLE hFile, LONG lDistanceToMove, LONG* lpDistanceToMoveHigh, DWORD dwMoveMethod)
{
    printf("SetFilePointer\n");
    return 0;
}

BOOL UnmapViewOfFile(const void* lpBaseAddress)
{
    printf("UnmapViewOfFile\n");
    return FALSE;
}

void* MapViewOfFile(HANDLE hFileMappingObject, DWORD dwDesiredAccess, DWORD dwFileOffsetHigh, DWORD dwFileOffsetLow, SIZE_T dwNumberOfBytesToMap)
{
    printf("MapViewOfFile\n");
    return NULL;
}

int SelectClipRgn(HDC hdc, HRGN hrgn)
{
    printf("SelectClipRgn\n");
    return 0;
}

BOOL SetBrushOrgEx(HDC hdc, int x, int y, LPPOINT lppt)
{
    printf("SetBrushOrgEx\n");
    return FALSE;
}

COLORREF SetDCBrushColor(HDC hdc, COLORREF color)
{
    printf("SetDCBrushColor\n");
    return 0;
}

COLORREF SetDCPenColor(HDC hdc, COLORREF color)
{
    printf("SetDCPenColor\n");
    return 0;
}

int SetGraphicsMode(HDC hdc, int iMode)
{
    printf("SetGraphicsMode\n");
    return 0;
}

int SetStretchBltMode(HDC hdc, int mode)
{
    printf("SetStretchBltMode\n");
    return 0;
}

int SetArcDirection(HDC hdc, int dir)
{
    printf("SetArcDirection\n");
    return 0;
}

int SetROP2(HDC hdc, int rop2)
{
    printf("SetROP2\n");
    return 0;
}

BOOL CreateDirectoryW(LPCWSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
    printf("CreateDirectoryW\n");
    return FALSE;
}
BOOL RemoveDirectoryW(LPCWSTR lpPathName)
{
    printf("RemoveDirectoryW\n");
    return FALSE;
}
int SHCreateDirectoryExW(HWND hwnd, LPCWSTR pszPath, const void* psa)
{
    printf("SHCreateDirectoryExW\n");
    return 0;
}

BOOL GetFileInformationByHandle(HANDLE hFile, LPBY_HANDLE_FILE_INFORMATION lpFileInformation)
{
    printf("GetFileInformationByHandle\n");
    return FALSE;
}

BOOL FreeLibrary(HMODULE hLibModule)
{
    printf("FreeLibrary\n");
    return FALSE;
}

int GetLocaleInfoW(LCID Locale, LCTYPE LCType, LPWSTR lpLCData, int cchData)
{
    printf("GetLocaleInfoW\n");
    return 0;
}

HRESULT CoInitializeEx(LPVOID pvReserved, DWORD dwCoInit)
{
    disablePipeError();
    return 0;
}

void ExitProcess(UINT uExitCode)
{
    std::exit(0);
}

BOOL IsZoomed(HWND hWnd)
{
    printf("IsZoomed\n");
    return FALSE;
}
BOOL IsIconic(HWND hWnd)
{
    printf("IsIconic\n");
    return FALSE;
}
HIMC ImmAssociateContext(HWND, HIMC)
{
    printf("ImmAssociateContext\n");
    return NULL;
}
BOOL IsWindowEnabled(HWND hWnd)
{
    printf("IsWindowEnabled\n");
    return FALSE;
}
BOOL SetMenu(HWND hWnd, HMENU hMenu)
{
    printf("SetMenu\n");
    return FALSE;
}
BOOL TrackPopupMenu(HMENU hMenu, UINT uFlags, int x, int y, int nReserved, HWND hWnd, const RECT* prcRect)
{
    printf("TrackPopupMenu\n");
    return FALSE;
}
BOOL SetMenuItemInfoW(HMENU hmenu, UINT item, BOOL fByPositon, MENUITEMINFOW* lpmii)
{
    printf("SetMenuItemInfoW\n");
    return FALSE;
}
BOOL GetMenuItemInfoW(HMENU hmenu, UINT item, BOOL fByPosition, MENUITEMINFOW* lpmii)
{
    printf("GetMenuItemInfoW\n");
    return FALSE;
}
HMENU CreateMenu()
{
    printf("CreateMenu\n");
    return NULL;
}
BOOL InsertMenuItemW(HMENU hmenu, UINT item, BOOL fByPosition, MENUITEMINFOW* lpmi)
{
    printf("InsertMenuItemW\n");
    return FALSE;
}
BOOL EnableMenuItem(HMENU hMenu, UINT uIDEnableItem, UINT uEnable)
{
    printf("EnableMenuItem\n");
    return FALSE;
}
HMENU GetSystemMenu(HWND hWnd, BOOL bRevert)
{
    printf("GetSystemMenu\n");
    return NULL;
}

#endif // WIN32