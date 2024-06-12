#include "config.h"
#include "third_party/WebKit/Source/platform/heap/SafePoint.h"
#if !defined(OS_WIN)
//int mprotect(const void *addr, size_t len, int prot);
#include <sys/mman.h>
#endif

#if defined(__LP64__) || defined(_WIN64) 

unsigned char pushAllRegistersShellCode[] = {
    //;; Push all callee - saves registers to get them
    //;; on the stack for conservative stack scanning.
    //;; We maintain 16 - byte alignment at calls(required on Mac).
    //;; There is an 8 - byte return address on the stack and we push
    //;; 56 bytes which maintains 16 - byte stack alignment
    //;; at the call.
    0x6A, 0x00, // push 0    
    0x53,       // push rbx 
    0x55,       // push rbp
    0x41, 0x54, // push r12
    0x41, 0x55, // push r13
    0x41, 0x56, // push r14
    0x41, 0x57, // push r15
    //;; Pass the two first arguments unchanged(rdi, rsi)
    //;; and the stack pointer after pushing callee - saved
    //;; registers to the callback.
    0x4C, 0x8B, 0xC2, // mov r8, rdx  
    0x48, 0x8B, 0xD4, // mov rdx, rsp  
    0x41, 0xFF, 0xD0, // call r8
    0x48, 0x83, 0xC4, 0x38, // add rsp, 38h  
    0xC3, // ret
};

namespace blink {

using PushAllRegistersCallback = void(*)(SafePointBarrier*, ThreadState*, intptr_t*);

extern "C" void pushAllRegisters(SafePointBarrier* p1, ThreadState* p2, PushAllRegistersCallback p3)
{
    void* pushAllRegistersPtr = (void*)pushAllRegistersShellCode;
    static blink::PushAllRegistersCallback cb = nullptr;

    if (!cb) {
#if defined(OS_WIN)
        cb = (blink::PushAllRegistersCallback)(pushAllRegistersPtr);

        DWORD oldProtect = 0;
        ::VirtualProtect(pushAllRegistersPtr, sizeof(pushAllRegistersShellCode), PAGE_EXECUTE_READWRITE, &oldProtect);
#else
        // mprotect(pushAllRegistersPtr, sizeof(pushAllRegistersShellCode), PROT_READ | PROT_EXEC);
        const size_t length = sizeof(pushAllRegistersShellCode);
        cb = (blink::PushAllRegistersCallback)mmap(0, length, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
        memcpy((void*)cb, pushAllRegistersPtr, length);
#endif
    }
    cb(p1, p2, (intptr_t*)p3);
}

}

#else

extern "C" __declspec(naked) void pushAllRegisters(void*, void*, void*)
{
    // Push all callee - saves registers to get them
    // on the stack for conservative stack scanning.
    // We maintain 16 - byte alignment at calls(required on
    // Mac).There is a 4 - byte return address on the stack
    // and we push 28 bytes which maintains 16 - byte alignment
    //; at the call.
    __asm {
        push ebx;
        push ebp;
        push esi;
        push edi;
        ;; Pass the two first arguments unchanged and the
        ;; stack pointer after pushing callee - save registers
        ;; to the callback.
        mov ecx, [esp + 28];
        push esp;
        push [esp + 28];
        push [esp + 28];
        call ecx;
        ;; Pop arguments and the callee - saved registers.
        ;; None of the callee - saved registers were modified
        ;; so we do not need to restore them.
        add esp, 28;
        ret;
    }
}

#endif