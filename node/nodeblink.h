﻿#ifndef _NODEBLINK_H_
#define _NODEBLINK_H_

#include <stddef.h>

#if 1 // ENABLE_NODEJS

#define NODE_ARCH "ia32"
#if defined(WIN32)
#define NODE_PLATFORM "win32"
#else
#define NODE_PLATFORM "posix"
#endif
#define NODE_WANT_INTERNALS 1
#define HAVE_OPENSSL 1
#define HAVE_ETW 1
#if defined(WIN32)
#define HAVE_PERFCTR 1
#endif
#define V8_INSPECTOR_USE_STL 1
#define NODE_USE_V8_PLATFORM 0
#define USING_V8_SHARED 0
//#define USING_UV_SHARED 0
#define BUILDING_UV_SHARED 1
#define CARES_BUILDING_LIBRARY 0

// #include "node/src/node.h"
// #include "node/src/env.h"
// #include "node/src/env-inl.h"
// #include "node/uv/include/uv.h"

#ifdef _WIN32
# ifndef BUILDING_NODE_EXTENSION
#   define NODE_EXTERN __declspec(dllexport)
# else
#   define NODE_EXTERN __declspec(dllimport)
# endif
#else
# define NODE_EXTERN /* nothing */
#endif

namespace node {
class Environment;
}

namespace v8 {
class Isolate;
}

struct NodeNative {
    const char* name;
    const char* source;
    size_t sourceLen;
};

extern "C" NODE_EXTERN void* nodeCreateDefaultPlatform();
extern "C" NODE_EXTERN void nodeDeleteNodeEnvironment(node::Environment* env);

typedef void* BlinkMicrotaskSuppressionHandle;
extern "C" NODE_EXTERN BlinkMicrotaskSuppressionHandle nodeBlinkMicrotaskSuppressionEnter(v8::Isolate* isolate);
extern "C" NODE_EXTERN void nodeBlinkMicrotaskSuppressionLeave(BlinkMicrotaskSuppressionHandle handle);

extern "C" NODE_EXTERN void* nodeBlinkAllocateUninitialized(size_t length);
extern "C" NODE_EXTERN void nodeBlinkFree(void* data, size_t length);

extern "C" NODE_EXTERN void nodeModuleInitRegister();
extern "C" NODE_EXTERN char* nodeBufferGetData(void* buf, size_t* len);

struct NodeBindingInMbCore {
    void* env; // node::Environment* m_env
};
NodeBindingInMbCore* nodeBindNodejsOnDidCreateScriptContext(void* webView, void* frameId, void* ctx);
void nodeWillReleaseScriptContext(NodeBindingInMbCore* nodebinding);
bool isNodejsEnable();

#endif // ENABLE_NODEJS
#endif //_NODEBLINK_H_