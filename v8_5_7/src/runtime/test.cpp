
#include "G:\\mycode\\mb\\v8_5_7\\include\\v8.h"
#include <windows.h>

void PrintCallstackTest(void* ptr)
{
    v8::Isolate* isolate = (v8::Isolate*)ptr;

    const v8::StackTrace::StackTraceOptions options = static_cast<v8::StackTrace::StackTraceOptions>(
        v8::StackTrace::kLineNumber
        | v8::StackTrace::kColumnOffset
        | v8::StackTrace::kScriptId
        | v8::StackTrace::kScriptNameOrSourceURL
        | v8::StackTrace::kFunctionName);

    int stackNum = 50;
    v8::HandleScope handleScope(isolate);
    v8::Local<v8::StackTrace> stackTrace(v8::StackTrace::CurrentStackTrace(isolate, stackNum, options));
    int count = stackTrace->GetFrameCount();

    char* output = (char*)malloc(0x100);
    sprintf(output, "FatalException: %d\n", count);
    OutputDebugStringA(output);
    free(output);

    for (int i = 0; i < count; ++i) {
        v8::Local<v8::StackFrame> stackFrame = stackTrace->GetFrame(i);
        int frameCount = stackTrace->GetFrameCount();
        int line = stackFrame->GetLineNumber();
        v8::Local<v8::String> scriptName = stackFrame->GetScriptNameOrSourceURL();
        v8::Local<v8::String> funcName = stackFrame->GetFunctionName();

        std::string scriptNameWTF;
        std::string funcNameWTF;

        if (!scriptName.IsEmpty()) {
            v8::String::Utf8Value scriptNameUtf8(scriptName);
            scriptNameWTF = *scriptNameUtf8;
        }

        if (!funcName.IsEmpty()) {
            v8::String::Utf8Value funcNameUtf8(funcName);
            funcNameWTF = *funcNameUtf8;
        }
        std::vector<char> output;
        output.resize(1000);
        sprintf(&output[0], "line:%d, [", line);
        OutputDebugStringA(&output[0]);

        if (!scriptNameWTF.empty()) {
            OutputDebugStringA(scriptNameWTF.c_str());
        }
        OutputDebugStringA("] , [");

        if (!funcNameWTF.empty()) {
            OutputDebugStringA(funcNameWTF.c_str());
        }
        OutputDebugStringA("]\n");
    }
    OutputDebugStringA("\n");
}