﻿#include "common/NodeBinding.h"

#include "uv.h"
#include "node/nodeblink.h"
#include "node/src/node.h"
#include "node/src/env.h"
#include "node/src/env-inl.h"
#include "node/uv/include/uv.h"
#include "gin/dictionary.h"
#include "base/file_path.h"
#include "common/StringUtil.h"
#include "common/AtomVersion.h"
#include "common/ChromeVersion.h"
#include "common/AtomCommandLine.h"
#include "common/api/EventEmitterCaller.h"
#include "base/path_service.h"
#include "base/strings/utf_string_conversions.h"
#include "base/process/process_metrics.h"
#include <xstring>
#include <vector>
#include <memory>
#include <shlwapi.h>

namespace atom {

namespace {

    void crash(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DebugBreak();
    }

    void hang(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        for (;;) {
            ::Sleep(1000);
        };
    }

    void getProcessMemoryInfo(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Isolate* isolate = info.GetIsolate();
        //std::unique_ptr<base::ProcessMetrics> metrics(base::ProcessMetrics::CreateCurrentProcessMetrics());

        gin::Dictionary dict = gin::Dictionary::CreateEmpty(isolate);
        dict.Set("workingSetSize", /*static_cast<double>(metrics->GetWorkingSetSize() >> 10)*/ 1000);
        dict.Set("peakWorkingSetSize", /*static_cast<double>(metrics->GetPeakWorkingSetSize() >> 10)*/ 1000);

        //size_t private_bytes, shared_bytes;
        //if (metrics->GetMemoryBytes(&private_bytes, &shared_bytes)) {
        dict.Set("privateBytes", /*static_cast<double>(private_bytes >> 10)*/ 1000);
        dict.Set("sharedBytes", /*static_cast<double>(shared_bytes >> 10)*/ 1000);
        //}

        info.GetReturnValue().Set(gin::Converter<gin::Dictionary>::ToV8(isolate, dict));
    }

    void getSystemMemoryInfo(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Isolate* isolate = info.GetIsolate();
        //     base::SystemMemoryInfoKB mem_info;
        //     if (!base::GetSystemMemoryInfo(&mem_info)) {
        //         args->ThrowError("Unable to retrieve system memory information");
        //         return v8::Undefined(isolate);
        //     }

        gin::Dictionary dict = gin::Dictionary::CreateEmpty(isolate);
        dict.Set("total", /*mem_info.total*/ 10);
        dict.Set("free", /*mem_info.free*/ 10);

        // NB: These return bogus values on macOS
#if !defined(OS_MACOSX)
        dict.Set("swapTotal", /*mem_info.swap_total*/ 10);
        dict.Set("swapFree", /*mem_info.swap_free*/ 10);
#endif

        info.GetReturnValue().Set(gin::Converter<gin::Dictionary>::ToV8(isolate, dict));
    }

    // Called when there is a fatal error in V8, we just crash the process here so
    // we can get the stack trace.
    void fatalErrorCallback(const char* location, const char* message)
    {
        //crash(info);
        DebugBreak();
    }

    void log(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        //std::cout << message << std::flush;
        crash(info);
    }

    void getSystemVersion(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
#if defined(WIN32)
        OSVERSIONINFOEXW os = { 0 };
        os.dwOSVersionInfoSize = sizeof(os);
        ::GetVersionEx(reinterpret_cast<LPOSVERSIONINFOW>(&os));

        std::vector<char> buf(201);
        sprintf(buf.data(), "%d.%d.%d\n", os.dwMajorVersion, os.dwMinorVersion, os.dwBuildNumber);

        v8::Local<v8::String> result = v8::String::NewFromUtf8(args.GetIsolate(), buf.data(), v8::String::kNormalString, -1);
        args.GetReturnValue().Set(result);
#else
        __debugbreak();
#endif
    }

} // namespace

NodeBindings::NodeBindings(bool isBrowser)
    : m_isBrowser(isBrowser)
    , m_uvLoop(nullptr)
    , m_env(nullptr)
    , m_callNextTickAsync(new uv_async_t())
{
}

NodeBindings::~NodeBindings()
{
    if (!m_env)
        return;
    nodeDeleteNodeEnvironment(m_env);
    delete m_callNextTickAsync;
}

//static std::string* kResPath = nullptr;

base::FilePath getResourcesPath(const std::string& name)
{
#if defined(WIN32)
    base::string16 out;
    if (kResPath) {
        out += *kResPath + name;
        return out;
    }

    std::vector<wchar_t> path;
    path.resize(MAX_PATH + 1);
    ::GetModuleFileName(nullptr, &path[0], MAX_PATH);

    ::PathRemoveFileSpecW(&path[0]);
    out += &path[0];

    base::string16 temp(out);
    temp += L"\\node.exp";
    if (!::PathFileExists(temp.c_str()))
        out += L"\\resources\\miniblink.asar\\";
    else
        out += L"\\..\\..\\electron\\lib\\";

    kResPath = new base::string16(out);
    out += name;
    return out;
#else
    base::FilePath path;
    base::PathService::Get(base::DIR_MODULE, &path);
    path = path.Append("resources/miniblink.asar/");
    path = path.Append(name);

    return path;
#endif
}

#if defined(WIN32)
void loadNodeScriptFromRes(void* path)
{
    NodeNative* nativePath = (NodeNative*)path;
    base::string16 sourceW;
    for (size_t i = 0; i < nativePath->sourceLen; ++i)
        sourceW += nativePath->source[i];

    if (L'.' == sourceW[0] && L'/' == sourceW[1])
        sourceW = sourceW.substr(2, sourceW.size() - 2);
    sourceW += L".js";
    sourceW = getResourcesPath(sourceW);

    WIN32_FILE_ATTRIBUTE_DATA attrs;
    if (::GetFileAttributesExW(sourceW.c_str(), GetFileExInfoStandard, &attrs) == 0)
        return;

    HANDLE fileHandle = ::CreateFileW(sourceW.c_str(), FILE_READ_DATA, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
    if (fileHandle == INVALID_HANDLE_VALUE)
        return;

    std::vector<char>* buffer = new std::vector<char>(); // 内存泄漏
    buffer->resize(attrs.nFileSizeLow);

    DWORD bytesRead;
    int retval = ::ReadFile(fileHandle, &buffer->at(0), attrs.nFileSizeLow, &bytesRead, 0);
    ::CloseHandle(fileHandle);

    if (retval == 0 || bytesRead != attrs.nFileSizeLow)
        return;

    nativePath->source = &buffer->at(0);
    nativePath->sourceLen = bytesRead;
}

#endif

// Convert the given vector to an array of C-strings. The strings in the
// returned vector are only guaranteed valid so long as the vector of strings
// is not modified.
std::unique_ptr<const char* []> stringVectorToArgArray(const std::vector<std::string>& vector)
{
    std::unique_ptr<const char*[]> argsArray(new const char*[vector.size()]);
    for (size_t i = 0; i < vector.size(); ++i) {
        argsArray[i] = vector[i].c_str();
    }
    return argsArray;
}

void NodeBindings::initNodeEnv()
{
    std::vector<std::string> args = AtomCommandLine::argv();
    int argsSize = args.size();

    std::unique_ptr<const char*[]> c_argv = stringVectorToArgArray(args);
    int exec_argc;
    const char** exec_argv = nullptr;
    node::Init(&argsSize, c_argv.get(), &exec_argc, &exec_argv);
}

void NodeBindings::bindFunction(gin::Dictionary* dict)
{
    NodeBindings* self = this;
    dict->SetMethod("crash", &crash);
    dict->SetMethod("hang", &hang);
    dict->SetMethod("log", &log);
    dict->SetMethod("getProcessMemoryInfo", &getProcessMemoryInfo);
    dict->SetMethod("getSystemMemoryInfo", &getSystemMemoryInfo);
#if defined(OS_POSIX)
    //dict->SetMethod("setFdLimit", &base::SetFdLimit);
#endif
    dict->SetMethod("activateUvLoop", [self](const v8::FunctionCallbackInfo<v8::Value>& info) { self->activateUVLoop(info.GetIsolate()); });

#if defined(MAS_BUILD)
    dict->Set("mas", true);
#endif
    dict->SetMethod("getSystemVersion", getSystemVersion); // M:\chromium\electron14\electron\shell\common\api\electron_bindings.cc

    gin::Dictionary versions = gin::Dictionary::CreateEmpty(dict->isolate());
    if (dict->Get("versions", &versions)) {
        versions.Set("atom-project-name", std::string(ATOM_VERSION_STRING));
        versions.Set("atom-shell", std::string(ATOM_VERSION_STRING)); // For compatibility.
        versions.Set("chrome", std::string(CHROME_VERSION_STRING));
        versions.Set("electron", std::string(ATOM_VERSION_STRING));
    }
}

struct MbConsoleLogInfo {
    MbConsoleLogInfo(bool isMainNode)
        : m_isMainNode(isMainNode)
    {
    }

    bool getIsMainNode() const
    {
        return m_isMainNode;
    };

private:
    bool m_isMainNode;
};

static void mbConsoleLog(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    MbConsoleLogInfo* consoleLogInfo = static_cast<MbConsoleLogInfo*>(v8::External::Cast(*info.Data())->Value());

    v8::Local<v8::Value> param0 = info[0];
    v8::Local<v8::String> param0V8String = param0->ToString(isolate);

    v8::String::Utf8Value param0String(param0V8String);
    std::string str = "mbConsoleLog, ";
    str += consoleLogInfo->getIsMainNode() ? ("MainNode :") : ("RenderNode: ");
    str += *param0String;
    str += "\n";

    if (std::string::npos != str.find("__callstack__")) {
        const v8::StackTrace::StackTraceOptions options = static_cast<v8::StackTrace::StackTraceOptions>(
            v8::StackTrace::kLineNumber
            | v8::StackTrace::kColumnOffset
            | v8::StackTrace::kScriptId
            | v8::StackTrace::kScriptNameOrSourceURL
            | v8::StackTrace::kFunctionName);

        int stackNum = 50;
        v8::HandleScope handleScope(info.GetIsolate());
        v8::Local<v8::StackTrace> stackTrace(v8::StackTrace::CurrentStackTrace(info.GetIsolate(), stackNum, options));
        int count = stackTrace->GetFrameCount();

        char* output = (char*)malloc(0x100);
        sprintf(output, "mbConsoleLog: %d\n", count);
        OutputDebugStringA(output);
        free(output);

        for (int i = 0; i < count; ++i) {
            v8::Local<v8::StackFrame> stackFrame = stackTrace->GetFrame(info.GetIsolate(), i);
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

    base::string16 strW = base::UTF8ToUTF16(str);
    OutputDebugStringW(strW.c_str());
}

static void addFunction(v8::Local<v8::Context> context, const char* name, v8::FunctionCallback callback, bool isMainNode)
{
    v8::Isolate* isolate = context->GetIsolate();
    if (!isolate->InContext())
        return;
    v8::HandleScope handleScope(isolate);
    v8::Context::Scope contextScope(context);

    v8::Local<v8::Object> object = context->Global();
    v8::Local<v8::FunctionTemplate> tmpl = v8::FunctionTemplate::New(isolate);
    v8::Local<v8::Value> data = v8::External::New(isolate, new MbConsoleLogInfo(isMainNode));

    // Set the function handler callback.
    tmpl->SetCallHandler(callback, data);

    // Retrieve the function object and set the name.
    v8::Local<v8::Function> func = tmpl->GetFunction();
    if (func.IsEmpty())
        return;

    v8::MaybeLocal<v8::String> nameV8 = v8::String::NewFromUtf8(isolate, name, v8::NewStringType::kNormal, -1);
    if (nameV8.IsEmpty())
        return;
    v8::Local<v8::String> nameV8Local = nameV8.ToLocalChecked();
    func->SetName(nameV8Local);

    object->Set(nameV8Local, func);
}

void NodeBindings::bindMbConsoleLog(v8::Local<v8::Context> context, bool isBrowserProcess)
{
    addFunction(context, "mbConsoleLog", mbConsoleLog, isBrowserProcess);
}

node::Environment* NodeBindings::createEnvironment(v8::Local<v8::Context> context)
{
    uv_async_init(m_uvLoop, m_callNextTickAsync, onCallNextTick);
    m_callNextTickAsync->data = this;

    std::vector<std::string> args = AtomCommandLine::argv();

    // Feed node the path to initialization script.
    std::string processType = m_isBrowser ? /*FILE_PATH_LITERAL*/("browser") : /*FILE_PATH_LITERAL*/("renderer");
    base::FilePath resourcesPath = getResourcesPath(/*FILE_PATH_LITERAL*/(""));
    base::FilePath scriptFilePath = resourcesPath.Append(processType);
    scriptFilePath = scriptFilePath.Append(/*FILE_PATH_LITERAL*/("init.js"));
    std::string scriptPath = scriptFilePath.AsUTF8Unsafe();

    printf("NodeBindings::createEnvironment, resourcesPath: %s\n", resourcesPath.AsUTF8Unsafe().c_str());
    printf("NodeBindings::createEnvironment, scriptPath: %s\n", scriptPath.c_str());

    // electron里的process.resourcesPath指的是xxx/resources目录。而main.js一般在xxx/resources/app下
    if (args.size() > 1) {
#if defined(WIN32)
        resourcesPath = StringUtil::MultiByteToUTF16(/*CP_ACP*/ (936), args[1]);
        const wchar_t* resourcesPos = wcsstr(resourcesPath.c_str(), L"resources");
        if (!resourcesPos) {
            std::vector<wchar_t> wbuf(resourcesPath.size() + 1);
            memset(&wbuf[0], 0, 2 * (resourcesPath.size() + 1));
            wcsncpy(&wbuf[0], resourcesPath.c_str(), resourcesPath.size());
            ::PathRemoveFileSpecW(&wbuf[0]);
            resourcesPath = &wbuf[0];
        } else {
            resourcesPath = base::string16(resourcesPath.c_str(), resourcesPos - resourcesPath.c_str() + 9);
        }
#else

#endif
    }

#if defined(WIN32)
    if (scriptPath.length() > 0 && scriptPath[0] >= /*u16*/('a') && scriptPath[0] <= ('z'))
        scriptPath[0] += /*u16*/('A') - /*u16*/('a');
#endif
    args.insert(args.begin() + 1, scriptPath.c_str());

    std::unique_ptr<const char*[]> c_argv = stringVectorToArgArray(args);
    m_env = node::CreateEnvironment(context->GetIsolate(), m_uvLoop, context, args.size(), c_argv.get(), 0, nullptr);
    if (!m_isBrowser)
        m_env->set_is_blink_core();

    //     const char* argv1[] = { "electron.exe", "E:\\mycode\\miniblink49\\trunk\\electron\\lib\\init.js" };
    //     node::Environment* env = node::CreateEnvironment(context->GetIsolate(), m_uvLoop, context, 2, argv1, 2, argv1);
    //     node::Environment* env = node::CreateEnvironment(context->GetIsolate(), m_uvLoop, context, 2, argv1, 2, argv1);

    // Node turns off AutorunMicrotasks, but we need it in web pages to match the
    // behavior of Chrome.
    //     if (!m_isBrowser)


    gin::Dictionary process(context->GetIsolate(), m_env->process_object());
    process.Set("type", /*StringUtil::UTF16ToUTF8*/(processType));
    process.Set("resourcesPath", /*StringUtil::UTF16ToUTF8*/(resourcesPath.AsUTF8Unsafe()));
    // Do not set DOM globals for renderer process.
    if (!m_isBrowser)
        process.Set("_noBrowserGlobals", /*StringUtil::UTF16ToUTF8*/(resourcesPath.AsUTF8Unsafe()));

    bindFunction(&process);

    // The path to helper app.
    //     base::FilePath helper_exec_path;
    //     PathService::Get(content::CHILD_PROCESS_EXE, &helper_exec_path);
    //     process.Set("helperExecPath", helper_exec_path);
    return m_env;
}

void NodeBindings::loadEnvironment()
{
    node::LoadEnvironment(m_env);
    mate::emitEvent(m_env->isolate(), m_env->process_object(), "loaded");
}

void NodeBindings::activateUVLoop(v8::Isolate* isoloate)
{
    node::Environment* env = node::Environment::GetCurrent(isoloate);
    if (std::find(m_pendingNextTicks.begin(), m_pendingNextTicks.end(), env) != m_pendingNextTicks.end())
        return;

    m_pendingNextTicks.push_back(env);
    uv_async_send(m_callNextTickAsync);
}

// static
void NodeBindings::onCallNextTick(uv_async_t* handle)
{
    NodeBindings* self = static_cast<NodeBindings*>(handle->data);

    for (std::list<node::Environment*>::const_iterator it = self->m_pendingNextTicks.begin(); it != self->m_pendingNextTicks.end(); ++it) {
        node::Environment* env = *it;
        v8::HandleScope handleScope(env->isolate());

        // KickNextTick, copied from node.cc:
        node::Environment::AsyncCallbackScope callbackScope(env);
        if (callbackScope.in_makecallback())
            continue;

        v8::Context::Scope contextScope(env->context());

        v8::Isolate* isolate = env->isolate();
        v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
        v8::Isolate* isolate2 = v8::Isolate::GetCurrent();

        node::Environment::TickInfo* tickInfo = env->tick_info();
        if (tickInfo->length() == 0)
            env->isolate()->RunMicrotasks();

        v8::Local<v8::Object> process = env->process_object();
        if (tickInfo->length() == 0)
            tickInfo->set_index(0);

        env->tick_callback_function()->Call(process, 0, nullptr).IsEmpty();
    }

    self->m_pendingNextTicks.clear();
}

} // atom