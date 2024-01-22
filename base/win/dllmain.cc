// Copyright 2012 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Windows doesn't support pthread_key_create's destr_function, and in fact
// it's a bit tricky to get code to run when a thread exits.  This is
// cargo-cult magic from http://www.codeproject.com/threads/tls.asp.
// We are trying to be compatible with both a LoadLibrary style invocation, as
// well as static linking. This code only needs to be included if we use
// LoadLibrary, but it hooks into the "standard" set of TLS callbacks that are
// provided for static linking.

// This code is deliberately written to match the style of calls seen in
// base/threading/thread_local_storage_win.cc.  Please keep the two in sync if
// coding conventions are changed.

// WARNING: Do *NOT* try to include this in the construction of the base
// library, even though it potentially drives code in
// base/threading/thread_local_storage_win.cc.  If you do, some users will end
// up getting duplicate definition of DllMain() in some of their later links.

// Force a reference to _tls_used to make the linker create the TLS directory
// if it's not already there (that is, even if __declspec(thread) is not used).
// Force a reference to p_thread_callback_dllmain_typical_entry to prevent whole
// program optimization from discarding the variables.

#include <windows.h>

#include "base/compiler_specific.h"
#include "base/win/win_util.h"

#if 1 // def SUPPORT_XP_CODE
#include <TlHelp32.h>
#include <set>
#pragma optimize("", off)
#pragma clang optimize off
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunreachable-code"
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-const-variable"
#pragma GCC diagnostic ignored "-Wunused-private-field"
#pragma GCC diagnostic ignored "-Wmicrosoft-cast"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunreachable-code-return"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

// Indicate if another service is scanning the callbacks.  When this becomes
// set to true, then DllMain() will stop supporting the callback service. This
// value is set to true the first time any of our callbacks are called, as that
// shows that some other service is handling callbacks.
static bool linker_notifications_are_active = false;

// This will be our mostly no-op callback that we'll list.  We won't
// deliberately call it, and if it is called, that means we don't need to do any
// of the callbacks anymore.  We expect such a call to arrive via a
// THREAD_ATTACH message, long before we'd have to perform our THREAD_DETACH
// callbacks.
static void NTAPI on_callback(PVOID h, DWORD reason, PVOID reserved);

#ifdef _WIN64

#pragma comment(linker, "/INCLUDE:_tls_used")
#pragma comment(linker, "/INCLUDE:p_thread_callback_dllmain_typical_entry")

#else  // _WIN64

#pragma comment(linker, "/INCLUDE:__tls_used")
#pragma comment(linker, "/INCLUDE:_p_thread_callback_dllmain_typical_entry")

#endif  // _WIN64

// Explicitly depend on VC\crt\src\tlssup.c variables
// to bracket the list of TLS callbacks.
extern "C" PIMAGE_TLS_CALLBACK __xl_a, __xl_z;

// extern "C" suppresses C++ name mangling so we know the symbol names for the
// linker /INCLUDE:symbol pragmas above.
extern "C" {
#ifdef _WIN64

    // .CRT section is merged with .rdata on x64 so it must be constant data.
#pragma data_seg(push, old_seg)
// Use a typical possible name in the .CRT$XL? list of segments.
#pragma const_seg(".CRT$XLB")
// When defining a const variable, it must have external linkage to be sure the
// linker doesn't discard it.
    extern const PIMAGE_TLS_CALLBACK p_thread_callback_dllmain_typical_entry;
    const PIMAGE_TLS_CALLBACK p_thread_callback_dllmain_typical_entry = on_callback;
#pragma data_seg(pop, old_seg)

#else  // _WIN64

#pragma data_seg(push, old_seg)
    // Use a typical possible name in the .CRT$XL? list of segments.
#pragma data_seg(".CRT$XLB")
    PIMAGE_TLS_CALLBACK p_thread_callback_dllmain_typical_entry = on_callback;
#pragma data_seg(pop, old_seg)

#endif  // _WIN64
}  // extern "C"

// Custom crash code to get a unique entry in crash reports.
NOINLINE static void CrashOnProcessDetach() 
{
    *static_cast<volatile int*>(nullptr) = 0x356;
}

#if 1 // def SUPPORT_XP_CODE
thread_local int* g_thread_local_stub = nullptr;
int g_unuse = 0;
std::set<DWORD>* g_tls_set_thread = nullptr; // 设置过的tls的线程的id
void* g_dll_base = nullptr;
typedef void* (WINAPI* FN_RtlImageDirectoryEntryToData)(PVOID Base, BOOLEAN MappedAsImage, USHORT DirectoryEntry, PULONG Size);
FN_RtlImageDirectoryEntryToData pRtlImageDirectoryEntryToData = NULL;
int g_is_xp = -1;

void* ThreadLocalFunStub() 
{
    void* ret_val = NULL;
    __asm {
        call NEXT;
    NEXT:
        pop eax;
        mov[ret_val], eax;
    }

    if (g_unuse == 1) {
        char output[64] = { 0 };
        sprintf(output, "ThreadLocalFunStub: %p %p %lx\n", g_thread_local_stub, ret_val, ::GetCurrentThreadId());
        OutputDebugStringA(output);
    }
    return ret_val;
}

void* SearchTlsIndex()
{
    unsigned char* ptr = (unsigned char*)(ThreadLocalFunStub());
    if (*ptr == 0xE9) {
        ptr = (unsigned char*)(*(void**)(ptr + 1));
    }
    void* addr = NULL;
    // A1 D0 B1 58 19       mov         eax, dword ptr[_tls_index(1958B1D0h)]
    // 64 8B 0D 2C 00 00 00 mov         ecx, dword ptr fs : [2Ch]
    // 8B 04 81             mov         eax, dword ptr[ecx + eax * 4]

    // 64 A1 2C 00 00 00    mov         eax, dword ptr fs : [0000002Ch]
    // 8B 0C 90             mov         ecx, dword ptr[eax + edx * 4]
    for (size_t i = 0; i < 300; ++i) {
        unsigned char c = ptr[i];
        if ((ptr[i] == 0x64 /*&& ptr[i + 1] == 0x8B*/ && ptr[i + 3] == 0x2C && ptr[i + 4] == 0x00 && ptr[i + 5] == 0x00 && ptr[i + 6] == 0x00) ||
            (ptr[i] == 0x64 && ptr[i + 2] == 0x2C && ptr[i + 3] == 0x00 && ptr[i + 4] == 0x00 && ptr[i + 5] == 0x00)) {
            addr = *(void**)(ptr + i - 4);

            char output[64] = { 0 };
            sprintf(output, "SearchTlsIndex:%p %lx\n", addr, ::GetCurrentThreadId());
            OutputDebugStringA(output);
            return addr;
        }
    }
    return NULL;
}

static bool AllocThreadLocalStoragePointer(void*** ThreadLocalStoragePointer, int32_t* tls_index)
{
    int dll_count = *tls_index;
    int old_tls_index = *tls_index;
    if (0 == dll_count) { // 为0就是主线程了，还需要知道多少个静态tls已经分配了
        for (; dll_count < 64; ++dll_count) {
            if (!ThreadLocalStoragePointer[dll_count]) {
                break;
            }
        }
    }

//     if (0 == dll_count)
//         return false;
    *tls_index = dll_count;

    char output[128] = { 0 };
    sprintf(output, "AllocTls: %d, %lx\n", dll_count, ::GetCurrentThreadId());
    OutputDebugStringA(output);

    dll_count = 400; // 搞个大的数组
    void** tls_vector = (void**)malloc(dll_count * sizeof(void*));
    memset(tls_vector, 0, dll_count * sizeof(void*));

    memcpy(tls_vector, *ThreadLocalStoragePointer, (*tls_index) * sizeof(void*));
    *ThreadLocalStoragePointer = tls_vector;

    // 重新分配本线程tls_index位置的指针
    const size_t kSize = 0x3000;
    (*ThreadLocalStoragePointer)[*tls_index] = malloc(kSize);
    memset((*ThreadLocalStoragePointer)[*tls_index], 0, kSize);

    // 拷贝本dll的tls表给xp系统
    ULONG tls_size;
    PIMAGE_TLS_DIRECTORY tls_image = (PIMAGE_TLS_DIRECTORY)pRtlImageDirectoryEntryToData(g_dll_base, TRUE, IMAGE_DIRECTORY_ENTRY_TLS, &tls_size);
    if (!tls_image) {
        OutputDebugStringA("AllocThreadLocalStoragePointer tls_image is null\n");
        return false;
    }
    ULONG tls_image_size = tls_image->EndAddressOfRawData - tls_image->StartAddressOfRawData;
    memcpy((*ThreadLocalStoragePointer)[*tls_index], (void*)tls_image->StartAddressOfRawData, tls_image_size);

    return true;
}

struct XP_PEB {
    char unuse[0x2C];
    PVOID* ThreadLocalStoragePointer;
};

// G:\code\win_xp_code\nt5src\XPSP1\base\ntdll\ldrinit.c LdrpAllocateTls
void FixTlsIndex()
{
    char output[128 * 2] = { 0 };
    //   if (!g_tls_set_thread)
    //     g_tls_set_thread = new std::set<DWORD>();
    //   if (g_tls_set_thread->end() != g_tls_set_thread->find(::GetCurrentThreadId())) {
    //     sprintf(output, "FixTlsIndex fail 0: %lx\n", ::GetCurrentThreadId());
    //     OutputDebugStringA(output);
    //     DebugBreak();
    //   }
    //   g_tls_set_thread->insert(::GetCurrentThreadId());

    XP_PEB* peb = (XP_PEB*)NtCurrentTeb();

    int32_t* tls_index_addr = (int32_t*)SearchTlsIndex();
    if (!tls_index_addr) {
        sprintf(output, "FixTlsIndex fail 1: %lx, %p, %x\n", ::GetCurrentThreadId(), tls_index_addr, tls_index_addr ? *tls_index_addr : 0);
        OutputDebugStringA(output);
        return;
    }

    int32_t tls_index = *tls_index_addr;
    void** ThreadLocalStoragePointer = (void**)((ULONG_PTR)__readfsdword(0x2c)); // ThreadLocalStoragePointer is PVOID *TlsVector;
    PVOID* ThreadLocalStoragePointerDump = peb->ThreadLocalStoragePointer;

    sprintf(output, "FixTlsIndex --: %lx, %p\n", ::GetCurrentThreadId(), ThreadLocalStoragePointerDump);
    OutputDebugStringA(output);

    if (ThreadLocalStoragePointerDump != ThreadLocalStoragePointer) {
        sprintf(output, "FixTlsIndex fail 2: %lx\n", ::GetCurrentThreadId());
        OutputDebugStringA(output);
        return;
    }

    if (!AllocThreadLocalStoragePointer(&ThreadLocalStoragePointer, &tls_index)) {
        sprintf(output, "FixTlsIndex fail 3: %lx, %d\n", ::GetCurrentThreadId(), tls_index);
        OutputDebugStringA(output);
        return;
    }
    if (0 != *tls_index_addr && *tls_index_addr != tls_index) { // 不同线程查到的应该是一样的
        sprintf(output, "FixTlsIndex fail 4: %lx, %d, %d\n", ::GetCurrentThreadId(), tls_index, *tls_index_addr);
        OutputDebugStringA(output);
        DebugBreak();
    }

    peb->ThreadLocalStoragePointer = ThreadLocalStoragePointer;
    if (0 == *tls_index_addr) { // 如果dll第一次（一般是主线程）走到，_tls_index 还没分配
        *tls_index_addr = tls_index; // 如果不是主线程走到，还是用以前存储好的
    }

    sprintf(output, "FixTlsIndex ok 2: %d, %p %lx\n", tls_index, ThreadLocalStoragePointer, ::GetCurrentThreadId());
    OutputDebugStringA(output);
}

typedef void* (WINAPI* FN_CreateThread)(void* lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
FN_CreateThread s_origCreateThread = nullptr;

struct ThreadStartAddrStubInfo {
    LPTHREAD_START_ROUTINE old_addr = nullptr;
    void* old_param = nullptr;
};

DWORD WINAPI ThreadStartAddrStub(LPVOID param) 
{
    OutputDebugStringA("DllMain ThreadStartAddrStub!!!!!!!\n");
    ThreadStartAddrStubInfo* info = (ThreadStartAddrStubInfo*)param;
    FixTlsIndex();
    DWORD ret = info->old_addr(info->old_param);
    delete info;
    return ret;
}

HANDLE WINAPI CreateThreadStub(void* lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId) {
    ThreadStartAddrStubInfo* info = new ThreadStartAddrStubInfo();
    info->old_addr = lpStartAddress;
    info->old_param = lpParameter;
    return s_origCreateThread(lpThreadAttributes, dwStackSize, ThreadStartAddrStub, info, dwCreationFlags, lpThreadId);
}

BOOL HookAddrByHotpatch(void* addr, void* pfnNew, void** pfnOld) 
{
    void* pFunc = (void*)addr;
    DWORD dwOldProtect = 0;
    DWORD dwAddress = 0;

    BYTE pBuf[5] = { 0xE9, 0, };
    BYTE pBuf2[2] = { 0xEB, 0xF9 };

    PBYTE pByte = (PBYTE)pFunc;
    if (pByte[0] != 0x8B && pByte[1] != 0xff)
        return FALSE;

    if (pfnOld)
        *pfnOld = (void*)&pByte[2];

    VirtualProtect((LPVOID)((DWORD)pFunc - 5), 7, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    dwAddress = (DWORD)pfnNew - (DWORD)pFunc; //计算Hook函数和被Hook函数的地址偏移

    memcpy(&pBuf[1], &dwAddress, 4); //将偏移地址拼凑到“JMP XXXXx"中

    memcpy((LPVOID)((DWORD)pFunc - 5), pBuf, 5); //将“JMP pfnNew”写入pFunc-5的位置，也就是五个NOP的位置

    // 2. MOV EDI, EDI (0x8BFF)
    // 将“JMP-7”写入pFunc的位置，也就是MOV EDI, EDI的位置
    memcpy((void*)pFunc, pBuf2, 2);

    VirtualProtect((LPVOID)((DWORD)pFunc - 5), 7, dwOldProtect, &dwOldProtect);
    return TRUE;
}
#endif

BOOL HookByHotpatch(LPCWSTR szDllName, LPCSTR szFuncName, void* pfnNew, void** pfnOld) 
{
    void* pFunc = (void*)GetProcAddress(LoadLibraryW(szDllName), szFuncName);
    return HookAddrByHotpatch((void*)pFunc, pfnNew, pfnOld);
}

// Make DllMain call the listed callbacks.  This way any third parties that are
// linked in will also be called.
BOOL WINAPI BaseDllMain(PVOID h, DWORD reason, PVOID reserved)
{
    if (DLL_PROCESS_DETACH == reason && base::win::ShouldCrashOnProcessDetach())
        CrashOnProcessDetach();

#if 1 // def SUPPORT_XP_CODE
    if (DLL_PROCESS_ATTACH == reason) {
        g_dll_base = h;

        if (-1 == g_is_xp) {
            HMODULE handle = GetModuleHandle(L"Kernel32.dll");
            g_is_xp = GetProcAddress(handle, "QueryThreadCycleTime") ? 0 : 1;
        }
        if (1 == g_is_xp) {
            HookByHotpatch(L"kernel32.DLL", (LPCSTR)"CreateThread", ((void*)(CreateThreadStub)), (void**)&s_origCreateThread);
            pRtlImageDirectoryEntryToData = (FN_RtlImageDirectoryEntryToData)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "RtlImageDirectoryEntryToData");

            if (linker_notifications_are_active)
                return true;

            OutputDebugStringA("DllMain FixTlsIndex!!!!!!!\n");

            FixTlsIndex();
            for (PIMAGE_TLS_CALLBACK* it = &__xl_a; it < &__xl_z; ++it) {
                if (*it == nullptr || *it == on_callback)
                    continue;  // Don't bother to call our own callback.
                (*it)(h, reason, reserved);
            }
        }
    }
#endif

    if (DLL_THREAD_DETACH != reason && DLL_PROCESS_DETACH != reason)
        return true;  // We won't service THREAD_ATTACH calls.

    if (linker_notifications_are_active)
        return true;  // Some other service is doing this work.

#if 1 // def SUPPORT_XP_CODE
    if (g_is_xp)
        return true;
#endif

    for (PIMAGE_TLS_CALLBACK* it = &__xl_a; it < &__xl_z; ++it) {
        if (*it == nullptr || *it == on_callback)
            continue;  // Don't bother to call our own callback.
        (*it)(h, reason, reserved);
    }

    return true;
}

static void NTAPI on_callback(PVOID h, DWORD reason, PVOID reserved) 
{
    // Do nothing.  We were just a place holder in the list used to test that we
    // call all items.
    // If we are called, it means that some other system is scanning the callbacks
    // and we don't need to do so in DllMain().
    linker_notifications_are_active = true;
    // Note: If some other routine some how plays this same game... we could both
    // decide not to do the scanning <sigh>, but this trick should suppress
    // duplicate calls on Vista, where the runtime takes care of the callbacks,
    // and allow us to do the callbacks on XP, where we are currently devoid of
    // callbacks (due to an explicit LoadLibrary call).
}
