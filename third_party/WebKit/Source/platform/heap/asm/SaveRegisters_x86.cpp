#include "config.h"
#include "third_party/WebKit/Source/platform/heap/SafePoint.h"
#if !defined(OS_WIN)
//int mprotect(const void *addr, size_t len, int prot);
#include <sys/mman.h>
#endif

#pragma optimize("", off)
#pragma clang optimize off

#if defined(__LP64__) // arm64 or x64

#if defined(__aarch64__)

// .text: 0000000000000000                EXPORT pushAllRegisters
// .text: 0000000000000000                pushAllRegisters
// .text: 0000000000000000
// .text: 0000000000000000                var_60 = -0x60
// .text: 0000000000000000                var_50 = -0x50
// .text: 0000000000000000                var_40 = -0x40
// .text: 0000000000000000                var_30 = -0x30
// .text: 0000000000000000                var_20 = -0x20
// .text: 0000000000000000                var_10 = -0x10
// .text: 0000000000000000
// .text: 0000000000000000 FF 83 01 D1    SUB             SP, SP, #0x60
// .text: 0000000000000004 F3 53 05 A9    STP             X19, X20, [SP, #0x60 + var_10]
// .text: 0000000000000008 F5 5B 04 A9    STP             X21, X22, [SP, #0x60 + var_20]
// .text: 000000000000000C F7 63 03 A9    STP             X23, X24, [SP, #0x60 + var_30]
// .text: 0000000000000010 F9 6B 02 A9    STP             X25, X26, [SP, #0x60 + var_40]
// .text: 0000000000000014 FB 73 01 A9    STP             X27, X28, [SP, #0x60 + var_50]
// .text: 0000000000000018 FE 77 00 A9    STP             X30, X29, [SP, #0x60 + var_60]
// .text: 000000000000001C E3 03 02 AA    MOV             X3, X2
// .text: 0000000000000020 E2 03 00 91    MOV             X2, SP
// .text: 0000000000000024 60 00 3F D6    BLR             X3
// .text: 0000000000000024
// .text: 0000000000000028 FE 07 46 F8    LDR             X30, [SP + 0x60 + var_60], #0x60
// .text: 000000000000002C C0 03 5F D6    RET
// .text: 000000000000002C
// .text: 000000000000002C; End of function pushAllRegisters
// .text: 000000000000002C
// .text: 000000000000002C; .text ends
// .text: 000000000000002C
// .text: 000000000000002C                               END

unsigned char pushAllRegistersShellCode[] = {
    0xFF, 0x83, 0x01, 0xD1, // SUB             SP, SP, #0x60

    0x1F, 0x20, 0x03, 0xD5, // nop

    0xF3, 0x53, 0x05, 0xA9, // STP             X19, X20,[SP, #0x60 + var_10]
    0xF5, 0x5B, 0x04, 0xA9, // STP             X21, X22,[SP, #0x60 + var_20]
    0xF7, 0x63, 0x03, 0xA9, // STP             X23, X24,[SP, #0x60 + var_30]
    0xF9, 0x6B, 0x02, 0xA9, // STP             X25, X26,[SP, #0x60 + var_40]
    0xFB, 0x73, 0x01, 0xA9, // STP             X27, X28,[SP, #0x60 + var_50]
    0xFE, 0x77, 0x00, 0xA9, // STP             X30, X29,[SP, #0x60 + var_60]
    0xE3, 0x03, 0x02, 0xAA, // MOV             X3, X2
    0xE2, 0x03, 0x00, 0x91, // MOV             X2, SP
    0x60, 0x00, 0x3F, 0xD6, // BLR             X3
    0xFE, 0x07, 0x46, 0xF8, // LDR             X30,[SP + 0x60 + var_60], #0x60
    0xC0, 0x03, 0x5F, 0xD6, // RET
};

unsigned char pushAllRegistersShellCode2[] = {
    0x1F, 0x20, 0x03, 0xD5,
    0xC0, 0x03, 0x5F, 0xD6,
};

#else // if defined(_WIN64)

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
#endif // __aarch64__

namespace blink {

using PushAllRegistersCallback = void(*)(SafePointBarrier*, ThreadState*, intptr_t*);
static blink::PushAllRegistersCallback s_cb = nullptr;

void initPushAllRegistersShellcode()
{
    if (s_cb)
        return;

    void* pushAllRegistersPtr = (void*)pushAllRegistersShellCode;
#if defined(OS_WIN)
    s_cb = (blink::PushAllRegistersCallback)(pushAllRegistersPtr);

    DWORD oldProtect = 0;
    ::VirtualProtect(pushAllRegistersPtr, sizeof(pushAllRegistersShellCode), PAGE_EXECUTE_READWRITE, &oldProtect);
#else
    // mprotect(pushAllRegistersPtr, sizeof(pushAllRegistersShellCode), PROT_READ | PROT_EXEC);
    const size_t length = sizeof(pushAllRegistersShellCode);
    s_cb = (blink::PushAllRegistersCallback)mmap(0, length, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    memcpy((void*)s_cb, pushAllRegistersPtr, length);
#endif
}

extern "C" void pushAllRegisters(SafePointBarrier* p1, ThreadState* p2, PushAllRegistersCallback p3)
{
    OutputDebugStringA("pushAllRegisters entry!!\n");
    s_cb(p1, p2, (intptr_t*)p3);
    OutputDebugStringA("pushAllRegisters ok\n");
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
        ;; //Pass the two first arguments unchanged and the
        ;; //stack pointer after pushing callee - save registers
        ;; //to the callback.
        mov ecx, [esp + 28];
        push esp;
        push [esp + 28];
        push [esp + 28];
        call ecx;
        ;; //Pop arguments and the callee - saved registers.
        ;; //None of the callee - saved registers were modified
        ;; //so we do not need to restore them.
        add esp, 28;
        ret;
    }
}

#endif