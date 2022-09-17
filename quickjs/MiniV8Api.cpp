
#include "MiniV8Api.h"
#include <windows.h>

unsigned int g_v8MemSize = 0;

extern "C" void printDebug(const char* format, ...)
{
    va_list argList;
    va_start(argList, format);

    char* output = (char*)malloc(1301);
    vsprintf(output, format, argList);
    OutputDebugStringA(output);
    free(output);

    va_end(argList);
}

void printEmptyFuncInfo(const char* fun, bool isBreak)
{
//     std::string output = fun;
//     output += "\n";
//     OutputDebugStringA(output.c_str());

//     if (isBreak)
//         DebugBreak();
}

static JSValue jsTestNode(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor)
{
    JSValueConst v = argv[0];
    miniv8::V8Object* obj = (miniv8::V8Object*)JS_GetUserdata(v);

    char* output = (char*)malloc(0x100);
    sprintf_s(output, 0x99, "jsTestNode: %p\n", obj);
    OutputDebugStringA(output);
    free(output);

    return JS_UNDEFINED;
}
static JSValue jsPrintStack(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor)
{
    JS_PrintStack(ctx);
    return JS_UNDEFINED;
}

static JSValue jsPrint(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor)
{
    int i;
    const char* str;

    for (i = 0; i < argc; i++) {
        if (i != 0)
            printDebug(" ");
        str = JS_ToCString(ctx, argv[i]);
        if (!str)
            return JS_EXCEPTION;
        OutputDebugStringA(str);
        JS_FreeCString(ctx, str);
    }
    OutputDebugStringA("\n");

    return JS_UNDEFINED;
}

static void printWhenError(JSContext* ctx)
{
    JSValue exception_val = JS_GetException(ctx);
    BOOL is_error = JS_IsError(ctx, exception_val);

    jsPrint(ctx, JS_NULL, 1, &exception_val, nullptr, FALSE);

    if (is_error) {
        JSValue val = JS_GetPropertyStr(ctx, exception_val, "stack");
        if (!JS_IsUndefined(val)) {
            const char* stack = JS_ToCString(ctx, val);
            OutputDebugStringA(stack);
            OutputDebugStringA("\n");
            JS_FreeCString(ctx, stack);
        }
        JS_FreeValue(ctx, val);
    }
}

void miniv8ReleaseAssert(bool b, const char* info)
{
    if (b)
        return;

    OutputDebugStringA(info);
    DebugBreak();
}

namespace v8 {

bool g_miniv8Enable = true;

// namespace platform {
// v8::Platform* CreateDefaultPlatform(int thread_pool_size);
// bool PumpMessageLoop(v8::Platform*, v8::Isolate*);
// }
}

namespace miniv8 {

V8Context::V8Context(V8Isolate* isolate, JSContext* ctx)
{
    m_head.m_type = kOTContext;
    m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Context;
    m_head.m_tracer = onV8HeadTraceOfV8Context;
    m_head.m_objectGroupId = (intptr_t)this; // context的组id设置成独一无二的一档
    m_isolate = isolate;
    m_ctx = ctx;
    m_isDetachGlobal = false;
    m_isCodeGenerationFromStringsAllowed = true;
    JS_SetContextOpaque(ctx, this);

    V8Isolate::GetCurrent()->regContext(this);

    printDebug("V8Context::V8Context 1: %p\n", this);
}

V8Context::V8Context(const V8Context& other)
{
    m_head.m_type = other.m_head.m_type;
    m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Context;
    m_head.m_tracer = onV8HeadTraceOfV8Context;

    m_isolate = other.m_isolate;
    m_ctx = other.m_ctx;
    m_isCodeGenerationFromStringsAllowed = other.m_isCodeGenerationFromStringsAllowed;

    printDebug("V8Context::V8Context 2: %p\n", this);
}

V8Context::~V8Context()
{
    printDebug("V8Context::~~V8Context: %p\n", this);
}

// void* V8Context::operator new(size_t size)
// {
//     return malloc(size);
// }

} // miniv8

//////////////////////////////////////////////////////////////////////////

// v8::Platform* v8::platform::CreateDefaultPlatform(int)
// {
//     printEmptyFuncInfo(__FUNCTION__, false);
//     return nullptr;
// }

v8::Platform* v8::platform::CreateDefaultPlatform(int, v8::platform::IdleTaskSupport)
{
    printEmptyFuncInfo(__FUNCTION__, false);
    return nullptr;
}

bool v8::platform::PumpMessageLoop(v8::Platform*, v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false);
    return true;
}

__int64 v8::Integer::Value(void) const
{
    //printEmptyFuncInfo(__FUNCTION__, true);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Data* self = v8::Utils::openHandle<v8::Integer, miniv8::V8Data>(this);
    if (!JS_IsInteger(self->v(self)))
        return 0;

    __int64 result = 0;
    if (0 == JS_ToInt64(ctx, &result, self->v(self)))
        return result;
    return 0;
}

__int64 v8::Value::IntegerValue(void) const
{
    //printEmptyFuncInfo(__FUNCTION__, true);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Data* self = v8::Utils::openHandle<v8::Value, miniv8::V8Data>(this);
    if (!JS_IsInteger(self->v(self)))
        return 0;

    __int64 result = 0;
    if (0 == JS_ToInt64(ctx, &result, self->v(self)))
        return result;
    return 0;
}

bool v8::ArrayBuffer::IsExternal(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false);
    return false;
}

bool v8::ArrayBuffer::IsNeuterable(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false);
    return false;
}

bool v8::Boolean::Value(void) const
{
    //printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Data* self = v8::Utils::openHandle<v8::Boolean, miniv8::V8Data>(this);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    return (0 != JS_ToBool(ctx, self->v(self)));
}

bool v8::BooleanObject::ValueOf(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Context::IsCodeGenerationFromStringsAllowed(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);
    
    return self->isCodeGenerationFromStringsAllowed();
}

bool v8::Isolate::AddMessageListener(void(__cdecl*)(v8::Local<v8::Message>, v8::Local<v8::Value>), v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false);
    return true;
}

bool v8::Isolate::GetHeapSpaceStatistics(v8::HeapSpaceStatistics*, size_t)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Isolate::IdleNotificationDeadline(double)
{
    printEmptyFuncInfo(__FUNCTION__, false);
    return true;
}

bool v8::Isolate::InContext(void)
{
    printEmptyFuncInfo(__FUNCTION__, false);
    miniv8::V8Isolate* self = (miniv8::V8Isolate*)this;
    return self->isInContext();
}

bool v8::Isolate::IsDead(void)
{
    printEmptyFuncInfo(__FUNCTION__, false);
    return false;
}

void v8::V8::DisposeGlobal(v8::internal::Object** obj)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    isolate->disposeGlobal(obj);
}

void v8::V8::MakeWeak(v8::internal::Object** obj, void* param, v8::WeakCallbackInfo<void>::Callback callback, v8::WeakCallbackType type)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();

    miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::toHandle<miniv8::V8Data>(*(intptr_t*)obj);
    head->m_isWeak = 1;
    head->m_weakCallback = (void*)callback;
    head->m_weakCallbackParam = param;

    if (head->m_type == miniv8::kOTObject) {
        miniv8::V8Object* obj = (miniv8::V8Object*)head;
        miniv8ReleaseAssert(!(obj->m_alignedPointerInInternalFields[1]) || param == obj->m_alignedPointerInInternalFields[1], "");
    }
}

// TODO：全局引用，把一些local的也放到全局句柄里
v8::internal::Object** v8::V8::GlobalizeReference(v8::internal::Isolate* isolate, v8::internal::Object** obj)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    miniv8::V8Data* vdata = Utils::toHandle<miniv8::V8Data>(*(intptr_t*)obj);
    miniv8::V8ObjectType type = vdata->m_head.m_type;

    void** index = nullptr;
    miniv8::V8Head* head = (miniv8::V8Head*)vdata;
    if (!head->m_isolatGlobalScopeIndex) {
        index = iso->findGlobalizeHandleEmptyIndex();
        iso->refGlobalizeHandleIndex((intptr_t)index);
        
        head->m_isolatGlobalScopeIndex = index;
        *index = v8::Utils::maskPtr(head);
    } else {
        index = (void**)head->m_isolatGlobalScopeIndex;
        iso->refGlobalizeHandleIndex((intptr_t)index);
        return (v8::internal::Object**)index;
    }

    miniv8::V8Context* v8ctx = iso->getCurrentCtx();
    JSContext* ctx = v8ctx ? v8ctx->ctx() : nullptr;

    switch (type) {
    case miniv8::kOTSignature:
    case miniv8::kOTScript:
    case miniv8::kOTExternal:
        break;

    case miniv8::kOTValue: {
        miniv8::V8Value* ptr = (miniv8::V8Value*)vdata;
        //JSValue val = ptr->v(ptr); //TODO:?
        //JS_DupValue(ctx, val);
        break;
    }
    case miniv8::kOTString: {
        miniv8::V8String* ptr = (miniv8::V8String*)vdata;
        //JSValue val = ptr->v(ptr); //TODO:?
        //JS_DupValue(ctx, val);
        break;
    }
    case miniv8::kOTContext: {
        miniv8::V8Context* ctx = (miniv8::V8Context*)vdata;
        break;
    }
    case miniv8::kOTData: {
        miniv8::V8Data* ptr = (miniv8::V8Data*)*obj;
        break;
    }
    case miniv8::kOTObject: {
        miniv8::V8Object* ptr = (miniv8::V8Object*)vdata;
        //         JSValue val = ptr->v(ptr);
        //         JS_DupValue(ctx, val);
        break;
    }
    case miniv8::kOTFunction: {
        miniv8::V8Function* ptr = (miniv8::V8Function*)vdata;
        break;
    }
    case miniv8::kOTObjectTemplate: {
        miniv8::V8ObjectTemplate* ptr = (miniv8::V8ObjectTemplate*)vdata;
        break;
    }
    case miniv8::kOTFunctionTemplate: {
        miniv8::V8FunctionTemplate* ptr = (miniv8::V8FunctionTemplate*)vdata;
        break;
    }
    case miniv8::kOTArrayBuffer: {
        miniv8::V8ArrayBuffer* ptr = (miniv8::V8ArrayBuffer*)vdata;
        break;
    }
    case miniv8::kOTArray:
    case miniv8::kOTUint8CArray:
    case miniv8::kOTInt8Array:
    case miniv8::kOTUint8Array:
    case miniv8::kOTInt16Array:
    case miniv8::kOTUint16Array:
    case miniv8::kOTInt32Array:
    case miniv8::kOTUint32Array:
#ifdef CONFIG_BIGNUM
    case miniv8::kOTInt64Array:
    case miniv8::kOTUint64Array:
#endif
    case miniv8::kOTFloat32Array:
    case miniv8::kOTFloat64Array:
        break;
    default:
        DebugBreak();
        break;
    }
    //printDebug("GlobalizeReference: %p %p\n", index, vdata);

    return (v8::internal::Object**)index;
}

v8::internal::Object** v8::HandleScope::CreateHandle(v8::internal::HeapObject*, v8::internal::Object*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return nullptr;
}

// TODO：局部引用，把一些local的也放到isoloate局部引用表里
v8::internal::Object** v8::HandleScope::CreateHandle(v8::internal::Isolate* isolate, v8::internal::Object* obj)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    miniv8::V8ObjectType type = (miniv8::V8ObjectType)(*(intptr_t*)obj);
    miniv8::V8Data* vdata = Utils::toHandle<miniv8::V8Data>((intptr_t)obj);

    void* ret = nullptr;
    switch (vdata->m_head.m_type) {
    case miniv8::kOTContext: {
        miniv8::V8Context* ptr = (miniv8::V8Context*)vdata;
        ret = ptr;// new miniv8::V8Context(*ctx);
        break;
    }
    case miniv8::kOTSignature: {
        miniv8::V8Data* ptr = (miniv8::V8Data*)vdata;
        ret = ptr;// new miniv8::V8Data(*ptr);
        break;
    }
    case miniv8::kOTData: {
        miniv8::V8Data* ptr = (miniv8::V8Data*)vdata;
        ret = ptr;// new miniv8::V8Data(*ptr);
        break;
    }
    case miniv8::kOTString: {
        miniv8::V8String* ptr = (miniv8::V8String*)vdata;
        ret = ptr;// new miniv8::V8FunctionTemplate(*ptr);
        break;
    }
    case miniv8::kOTObjectTemplate: {
        miniv8::V8ObjectTemplate* ptr = (miniv8::V8ObjectTemplate*)vdata;
        ret = ptr;// new miniv8::V8ObjectTemplate(*ptr);
        break;
    }
    case miniv8::kOTFunctionTemplate: {
        miniv8::V8FunctionTemplate* ptr = (miniv8::V8FunctionTemplate*)vdata;
        ret = ptr;// new miniv8::V8FunctionTemplate(*ptr);
        break;
    }
    case miniv8::kOTFunction: {
        miniv8::V8Function* ptr = (miniv8::V8Function*)vdata;
        ret = ptr;// new miniv8::V8FunctionTemplate(*ptr);
        break;
    }
    case miniv8::kOTObject: {
        miniv8::V8Object* ptr = (miniv8::V8Object*)vdata;
        ret = ptr;// new miniv8::V8FunctionTemplate(*ptr);
        break;
    }
    case miniv8::kOTValue: {
        miniv8::V8Value* ptr = (miniv8::V8Value*)vdata;
        ret = ptr;// new miniv8::V8FunctionTemplate(*ptr);
        break;
    }
    case miniv8::kOTScript: {
        miniv8::V8Script* ptr = (miniv8::V8Script*)vdata;
        ret = ptr;// new miniv8::V8FunctionTemplate(*ptr);
        break;
    }
    case miniv8::kOTExternal: {
        ret = vdata;// new miniv8::V8FunctionTemplate(*ptr);
        break;
    }
    case miniv8::kOTUint8Array: {
        ret = vdata;
        break;
    }
    default:
        DebugBreak();
        break;
    }

    void** index = nullptr;
    miniv8::V8Head* head = (miniv8::V8Head*)ret;

    if (head->m_isolatGlobalScopeIndex) { // 如果有全局句柄表引用，则用全局的
        index = (void**)head->m_isolatGlobalScopeIndex;
        //iso->refGlobalizeHandleIndex((intptr_t)index);
    } else if (head->m_isolatHandleScopeIndex) {
        index = (void**)head->m_isolatHandleScopeIndex;
    } else {
        index = iso->findHandleScopeEmptyIndex();
        head->m_isolatHandleScopeIndex = index;
        *index = v8::Utils::maskPtr(ret);
    }

    return (v8::internal::Object**)index;
}

bool v8::Isolate::IsExecutionTerminating(void)
{
    printEmptyFuncInfo(__FUNCTION__, false);
    return false;
}

bool v8::Isolate::WillAutorunMicrotasks(void) const
{
    //printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Message::IsOpaque(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Message::IsSharedCrossOrigin(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false);
    return false;
}

namespace miniv8 {

JSValue wrapGetter(JSContext* ctx, JSValueConst thisVal, void* userdata)
{
    miniv8::V8Object* self = (miniv8::V8Object*)JS_GetUserdata(thisVal);
    intptr_t hashVal = (intptr_t)userdata;

    std::map<intptr_t, miniv8::V8Object::AccessorData*>::iterator it = self->m_accessorMap.find(hashVal);
    if (it != self->m_accessorMap.end())
        DebugBreak();

    miniv8::V8Object::AccessorData* accessor = it->second;

    JSValue propQjs = JS_NewStringLen(ctx, accessor->name.c_str(), accessor->name.size());
    miniv8::V8String prop(self->v8Ctx(), propQjs);
    v8::Local<v8::String> propV8 = v8::Utils::convert<miniv8::V8String, v8::String>(&prop);

    JSRuntime* runtime = JS_GetRuntime(ctx);
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();

    miniv8::V8Context* contextOfSelf = self->v8Ctx();
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8ReleaseAssert(contextOfSelf == context, "wrapGetter fail\n");
    miniv8::V8Object* thisValV8 = miniv8::V8Object::create(context, thisVal); // TODO: free

    miniv8::V8Data dataV8(context, thisVal);

    void* returnValue[4] = { 0 };
    //returnValue[2]; // GetDefaultValue
    returnValue[1] = isolate;

    void* info[v8::PropertyCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    info[1] = thisValV8; // kHolderIndex
    info[2] = isolate; // kIsolateIndex
    info[4] = &returnValue[3]; // kReturnValueIndex
    info[5] = &dataV8; // kDataIndex
    info[6] = thisValV8; // kThisIndex

    v8::PropertyCallbackInfo<v8::Value>* infoV8 = (v8::PropertyCallbackInfo<v8::Value>*)info;
    if (accessor->getter)
        accessor->getter(propV8, *infoV8);
    else if (accessor->nameGetter)
        accessor->nameGetter(propV8, *infoV8);

    v8::ReturnValue<v8::Value>* returnValueV8 = (v8::ReturnValue<v8::Value>*)(&returnValue[3]);
    v8::Local<v8::Value> retV8 = returnValueV8->Get();
    miniv8::V8Value* ret = (miniv8::V8Value*)(*retV8);

    return ret->v(ret);
}

JSValue wrapSetter(JSContext* ctx, JSValueConst thisVal, JSValueConst val, void* userdata)
{
    //typedef void (V8CALL* AccessorSetterCallback)(Local<String> property, Local<Value> value, const PropertyCallbackInfo<void>& info)
    miniv8::V8Object* self = (miniv8::V8Object*)JS_GetUserdata(thisVal);
    intptr_t hashVal = (intptr_t)userdata;

    std::map<intptr_t, miniv8::V8Object::AccessorData*>::iterator it = self->m_accessorMap.find(hashVal);
    if (it != self->m_accessorMap.end())
        DebugBreak();

    miniv8::V8Object::AccessorData* accessor = it->second;

    JSValue propQjs = JS_NewStringLen(ctx, accessor->name.c_str(), accessor->name.size());
    miniv8::V8String prop(self->v8Ctx(), propQjs);
    v8::Local<v8::String> propV8 = v8::Utils::convert<miniv8::V8String, v8::String>(&prop);

    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    miniv8::V8Context* contextOfSelf = self->v8Ctx();
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8ReleaseAssert(contextOfSelf == context, "wrapSetter fail\n");

    miniv8::V8Value value(context, val);
    v8::Local<v8::Value> valueV8 = v8::Utils::convert<miniv8::V8Value, v8::Value>(&value);

    miniv8::V8Object* thisValV8 = miniv8::V8Object::create(context, thisVal);
    miniv8::V8Data dataV8(context, thisVal);

    void* returnValue[4] = { 0 };
    //returnValue[2]; // GetDefaultValue
    returnValue[1] = &isolate;

    void* info[v8::PropertyCallbackInfo<void>::kArgsLength] = { 0 };
    info[1] = thisValV8; // kHolderIndex
    info[2] = &isolate; // kIsolateIndex
    info[4] = &returnValue[3]; // kReturnValueIndex
    info[5] = &dataV8; // kDataIndex
    info[6] = thisValV8; // kThisIndex

    v8::PropertyCallbackInfo<void>* infoV8 = (v8::PropertyCallbackInfo<void>*)info;
    if (accessor->setter)
        accessor->setter(propV8, valueV8, *infoV8);
    else if (accessor->nameSetter)
        accessor->nameSetter(propV8, valueV8, *infoV8);

    return JS_UNDEFINED;
}

} // miniv8

v8::Maybe<bool> v8::Object::SetAccessor(
    v8::Local<v8::Context> v8context, 
    v8::Local<v8::Name> name,
    v8::AccessorNameGetterCallback getter,
    v8::AccessorNameSetterCallback setter,
    v8::MaybeLocal<v8::Value> data, 
    v8::AccessControl settings, 
    v8::PropertyAttribute attribute
    )
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* context = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*v8context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8String* namePtr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(name.As<v8::String>()));

    miniv8ReleaseAssert(namePtr->m_head.m_type == miniv8::V8ObjectType::kOTString, "v8::Object::SetAccessor fail\n");

    size_t nameLen = 0;
    const char* nameStr = JS_ToCStringLen(context->ctx(), &nameLen, namePtr->v(namePtr));
    uint32_t hashVal = miniv8::hash(nameStr, nameLen);

    std::map<intptr_t, miniv8::V8Object::AccessorData*>::iterator it = self->m_accessorMap.find(hashVal);
    if (it != self->m_accessorMap.end()) {
        delete it->second;
        self->m_accessorMap.erase(it);
    }

    if (!self->m_props)
        self->m_props = new std::vector<JSCFunctionListEntry>();

    uint8_t propFlags = JS_PROP_CONFIGURABLE;
    if (attribute & ALL_CAN_WRITE)
        propFlags |= JS_PROP_WRITABLE;

    JSCFunctionListEntry prop = { 0 };
    prop.name = strdup(nameStr); // TODO: free
    prop.prop_flags = propFlags;
    prop.def_type = JS_DEF_CGETSET;
    prop.magic = 0;
    prop.u.getset.get.getter = miniv8::wrapGetter;
    prop.u.getset.set.setter = miniv8::wrapSetter;
    prop.u.getset.userdata = (void*)(hashVal); // TODO:userdata

    self->m_props->push_back(prop);

    miniv8::V8Object::AccessorData* accessorData = new miniv8::V8Object::AccessorData(); // TODO delete
    accessorData->nameGetter = getter;
    accessorData->nameSetter = setter;
    accessorData->data = data.IsEmpty() ? nullptr : v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*(data.ToLocalChecked()));

    self->m_accessorMap.insert(std::make_pair(hashVal, accessorData));
    JS_SetPropertyFunctionList(context->ctx(), self->v(self), self->m_props->data(), self->m_props->size());

    JS_FreeCString(context->ctx(), nameStr);
    return v8::Just<bool>(true);
}

bool v8::Object::SetAccessor(
    v8::Local<v8::Name> name,
    void(__cdecl*)(v8::Local<v8::Name>, class v8::PropertyCallbackInfo<v8::Value> const&),
    void(__cdecl*)(v8::Local<v8::Name>, v8::Local<v8::Value>, v8::PropertyCallbackInfo<void> const&),
    v8::Local<v8::Value>,
    v8::AccessControl,
    v8::PropertyAttribute)
{
    printEmptyFuncInfo(__FUNCTION__, false);
    DebugBreak();

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8String* namePtr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(name.As<v8::String>()));
    if (namePtr->getStr() == "stack")
        return (true);
    return (false);
}

bool v8::Object::SetAccessor(
    v8::Local<v8::String> name,
    v8::AccessorGetterCallback getter,
    v8::AccessorSetterCallback setter,
    v8::Local<v8::Value> data,
    v8::AccessControl settings,
    v8::PropertyAttribute attribute
    )
{
    printEmptyFuncInfo(__FUNCTION__, false);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8String* namePtr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*name);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();

    size_t nameLen = 0;
    const char* nameStr = JS_ToCStringLen(ctx, &nameLen, namePtr->v(namePtr));
    uint32_t hashVal = miniv8::hash(nameStr, nameLen);

    if (self->m_accessorMap.find(hashVal) != self->m_accessorMap.end())
        DebugBreak();

    if (!self->m_props)
        self->m_props = new std::vector<JSCFunctionListEntry>();

    uint8_t propFlags = JS_PROP_CONFIGURABLE;
    if (attribute & ALL_CAN_WRITE)
        propFlags |= JS_PROP_WRITABLE;

    JSCFunctionListEntry prop = { 0 };
    prop.name = strdup(nameStr); //TODO: free
    prop.prop_flags = propFlags;
    prop.def_type = JS_DEF_CGETSET;
    prop.magic = 0;
    prop.u.getset.get.getter = miniv8::wrapGetter;
    prop.u.getset.set.setter = miniv8::wrapSetter;
    prop.u.getset.userdata = (void*)(hashVal); // TODO:userdata

    self->m_props->push_back(prop);

    miniv8::V8Object::AccessorData* accessorData = new miniv8::V8Object::AccessorData(); // TODO delete
    accessorData->getter = getter;
    accessorData->setter = setter;
    accessorData->data = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*data);

    self->m_accessorMap.insert(std::make_pair(hashVal, accessorData));

    JS_SetPropertyFunctionList(ctx, self->v(self), self->m_props->data(), self->m_props->size());
    JS_FreeCString(ctx, nameStr);

    return true;
}

v8::Maybe<bool> v8::Object::CreateDataProperty(v8::Local<v8::Context> context, unsigned int index, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, false);

    miniv8::V8Context* v8context = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* value = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);

    JSValueConst v = value->v(value);
    JS_DupValue(v8context->ctx(), v);
    int ret = JS_SetPropertyUint32(v8context->ctx(), self->v(self), index, v);
    if (TRUE == ret)
        return v8::Just<bool>(true);

    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::CreateDataProperty(v8::Local<v8::Context>context, v8::Local<v8::Name> key, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, false);

    if (key.IsEmpty() || val.IsEmpty()) // TODO:V8Document::preparePrototypeObject导致这里可能是空的
        return v8::Just<bool>(false);

    miniv8::V8Context* v8Ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* v8Key = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    miniv8::V8Value* valueQjs = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);
    JSContext* ctx = v8Ctx->ctx();

    JSAtom keyAtom = JS_ValueToAtom(ctx, v8Key->v(v8Key));

    JSValueConst v = valueQjs->v(valueQjs);
    JS_DupValue(ctx, v);
    int ret = JS_SetProperty(ctx, self->v(self), keyAtom, v);
    JS_FreeAtom(ctx, keyAtom);

    if (TRUE == ret)
        return v8::Just<bool>(true);
    
    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::DefineOwnProperty(v8::Local<v8::Context> context, v8::Local<v8::Name> key, v8::Local<v8::Value> value, v8::PropertyAttribute attributes)
{
    printEmptyFuncInfo(__FUNCTION__, false);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* v8Key = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    miniv8::V8Value* val = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*value);

    size_t keyStrLen = 0;
    const char* keyStr = JS_ToCStringLen(ctx->ctx(), &keyStrLen, v8Key->v(v8Key));
    
    int flag = 0;
    if (0 == (attributes & v8::ReadOnly))
        flag |= JS_PROP_WRITABLE;
    if (0 == (attributes & v8::DontEnum))
        flag |= JS_PROP_ENUMERABLE;
    if (0 == (attributes & v8::DontDelete))
        flag |= JS_PROP_CONFIGURABLE;

    int ret = JS_DefinePropertyValueStr(ctx->ctx(), self->v(self), keyStr, val->v(val), flag);
    JS_FreeCString(ctx->ctx(), keyStr);

    return v8::Just<bool>(TRUE == ret);
}

v8::Maybe<bool> v8::Object::Delete(v8::Local<v8::Context> context, unsigned int index)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);

    JSAtom prop = JS_NewAtomUInt32(ctx->ctx(), index);
    int ret = JS_DeleteProperty(ctx->ctx(), self->v(self), prop, 0);
    JS_FreeAtom(ctx->ctx(), prop);
    return v8::Just<bool>(TRUE == ret);
}

v8::Maybe<bool> v8::Object::Delete(v8::Local<v8::Context> context, v8::Local<v8::Value> key)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* v8Ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* v8Key = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    JSContext* ctx = v8Ctx->ctx();

    JSAtom prop = JS_ValueToAtom(ctx, v8Key->v(v8Key));
    int ret = JS_DeleteProperty(ctx, self->v(self), prop, 0);
    JS_FreeAtom(ctx, prop);

    return v8::Just<bool>(TRUE == ret);
}

v8::Maybe<bool> v8::Object::Has(v8::Local<v8::Context> context, unsigned int index)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::Has(v8::Local<v8::Context> context, v8::Local<v8::Value> key)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Context* v8Ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* v8Key = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    JSContext* ctx = v8Ctx->ctx();

    JSAtom prop = JS_ValueToAtom(ctx, v8Key->v(v8Key));
    int ret = JS_HasProperty(ctx, self->v(self), prop);
    JS_FreeAtom(ctx, prop);

    return v8::Just<bool>(TRUE == ret);
}

v8::Maybe<bool> v8::Object::HasOwnProperty(v8::Local<v8::Context> context, v8::Local<v8::Name> key)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    // TODO：V8Document::preparePrototypeObject -》 v8::Symbol::GetUnscopables，这个key可能是空的
    if (key.IsEmpty())
        return v8::Just<bool>(false);

    miniv8::V8Context* v8Ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* v8Key = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    JSContext* ctx = v8Ctx->ctx();

    JSAtom prop = JS_ValueToAtom(ctx, v8Key->v(v8Key));
    int ret = JS_HasProperty(ctx, self->v(self), prop);
    JS_FreeAtom(ctx, prop);

    return v8::Just<bool>(TRUE == ret);
}

v8::Maybe<bool> v8::Object::HasRealIndexedProperty(v8::Local<v8::Context> context, unsigned int index)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::HasRealNamedCallbackProperty(v8::Local<v8::Context>, v8::Local<v8::Name>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::HasRealNamedProperty(v8::Local<v8::Context>, v8::Local<v8::Name>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Just<bool>(false);
}

v8::MaybeLocal<v8::Value> v8::Object::CallAsFunction(v8::Local<v8::Context>, v8::Local<v8::Value>, int, v8::Local<v8::Value>* const)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::MaybeLocal<v8::Value>();
}

v8::MaybeLocal<v8::Value> v8::Object::Get(v8::Local<v8::Context> context, unsigned int index)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);

    JSValue v = JS_GetPropertyUint32(ctx->ctx(), self->v(self), index);

    miniv8::V8Value* val = miniv8::V8Value::create(ctx, v);
    v8::Local<v8::Value> ret = v8::Utils::convert<miniv8::V8Value, v8::Value>(val);
    JS_FreeValue(ctx->ctx(), v);

    return ret;
}

v8::Local<v8::Value> v8::Object::Get(unsigned int index)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    JSContext* ctx = miniv8::V8Context::getCurrentJsCtx();
    miniv8::V8Context* context = miniv8::V8Context::getCurrentCtx();

    JSValue selfV = self->v(self);
    JSValue val = JS_GetPropertyUint32(ctx, selfV, index);
    miniv8::V8Value* v = miniv8::V8Value::create(context, val); // TODO: 放到句柄域
    JS_FreeValue(ctx, val);

    v8::Local<v8::Value> ret = v8::Utils::convert<miniv8::V8Value, v8::Value>(v);
    return ret;
}

v8::Local<v8::Value> v8::Object::Get(v8::Local<v8::Value> key)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::MaybeLocal<v8::Value> ret = Get(isolate->GetCurrentContext(), key);
    if (ret.IsEmpty())
        return v8::Local<v8::Value>();
    return ret.ToLocalChecked();
}

v8::MaybeLocal<v8::Value> v8::Object::Get(v8::Local<v8::Context> context, v8::Local<v8::Value> keyVal)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8String* key = v8::Utils::openHandle<v8::Value, miniv8::V8String>(*keyVal);
    if (key->m_head.m_type != miniv8::kOTString && key->m_head.m_type != miniv8::kOTPrivate)
        return v8::MaybeLocal<v8::Value>();

    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    isolate->enterContext(ctx);

    JSContext* jsCtx = ctx->ctx();

    JSValue selfV= self->v(self);
    JSValue val;

    BOOL isFunction = JS_IsFunction(jsCtx, selfV);
    if (!isFunction && key->getStr() == "prototype") {
        val = JS_GetPrototype(jsCtx, selfV);
    } else {
        JSAtom prop = JS_ValueToAtom(jsCtx, key->v(key));
        val = JS_GetProperty(jsCtx, selfV, prop);
        JS_FreeAtom(jsCtx, prop);
    }

    miniv8::V8Value* v = miniv8::V8Value::create(ctx, val); // TODO: 放到句柄域
    v8::Local<v8::Value> ret = v8::Utils::convert<miniv8::V8Value, v8::Value>(v);
    JS_FreeValue(jsCtx, val);

    isolate->exitContext();

    return ret;
}

v8::MaybeLocal<v8::Value> v8::Object::GetOwnPropertyDescriptor(v8::Local<v8::Context>, v8::Local<v8::Name>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::MaybeLocal<v8::Value>();
}

v8::MaybeLocal<v8::Value> v8::Object::GetRealNamedProperty(v8::Local<v8::Context>, v8::Local<v8::Name>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::MaybeLocal<v8::Value>();
}

bool v8::Object::Delete(v8::Local<v8::Value> key)
{
    printEmptyFuncInfo(__FUNCTION__, false);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* keyPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();

    JSAtom prop = JS_ValueToAtom(ctx, keyPtr->v(keyPtr));
    if (0 == prop)
        return false;
    
    bool b = TRUE == JS_DeleteProperty(ctx, self->v(self), prop, 0);
    JS_FreeAtom(ctx, prop);
    return b;
}

bool v8::Object::IsCallable(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Object::Set(unsigned int index, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, false);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* valPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();

    JSValue value = valPtr->v(valPtr);
    JS_DupValue(valPtr->ctx(), value);
    return TRUE == JS_SetPropertyUint32(ctx, self->v(self), index, value);
}

bool v8::Object::Set(v8::Local<v8::Value> key, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, false);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* keyPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    miniv8::V8Value* valPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();

    JSAtom prop = JS_ValueToAtom(ctx, keyPtr->v(keyPtr));
    if (0 == prop)
        return false;

    JSValueConst value = valPtr->v(valPtr);
    bool b = TRUE == JS_SetProperty(ctx, self->v(self), prop, valPtr->v(valPtr));
    JS_DupValue(ctx, value);
    JS_FreeAtom(ctx, prop);

    return b;
}

const char* kPrivateKey = "__privatekey__";

v8::Maybe<bool> v8::Object::DeletePrivate(v8::Local<v8::Context> context, v8::Local<v8::Private> keyPrivate)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* key = v8::Utils::openHandle<v8::Private, miniv8::V8Value>(*keyPrivate);
    v8::Local<v8::Value> keyVal = v8::Utils::convert<miniv8::V8Value, v8::Value>(key);

    return Delete(context, keyVal);
}

v8::Maybe<bool> v8::Object::HasPrivate(v8::Local<v8::Context> context, v8::Local<v8::Private> keyPrivate)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* key = v8::Utils::openHandle<v8::Private, miniv8::V8Value>(*keyPrivate);
    v8::Local<v8::Value> keyVal = v8::Utils::convert<miniv8::V8Value, v8::Value>(key);

    return Has(context, keyVal);
}

v8::MaybeLocal<v8::Value> v8::Object::GetPrivate(v8::Local<v8::Context> context, v8::Local<v8::Private> keyPrivate)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* key = v8::Utils::openHandle<v8::Private, miniv8::V8Value>(*keyPrivate);
    v8::Local<v8::Value> keyVal = v8::Utils::convert<miniv8::V8Value, v8::Value>(key);
    return Get(context, keyVal);
}

v8::Local<v8::Private> v8::Private::ForApi(v8::Isolate* isolate, v8::Local<v8::String> name)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8String* nameStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*name);
    JSValue val = nameStr->v(nameStr);

    std::string str = nameStr->getStr();
    str += kPrivateKey;
    miniv8::V8Private* ret = new miniv8::V8Private(str);
    return v8::Utils::convert<miniv8::V8Private, v8::Private>(ret);
}

v8::Local<v8::Private> v8::Private::New(v8::Isolate*, v8::Local<v8::String> name)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* nameStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*name);
    std::string str = nameStr->getStr();
    str += kPrivateKey;
    miniv8::V8Private* ret = new miniv8::V8Private(str);
    return v8::Utils::convert<miniv8::V8Private, v8::Private>(ret);
}

v8::Maybe<bool> v8::Object::SetPrivate(v8::Local<v8::Context> context, v8::Local<v8::Private> keyPrivate, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* ctx = (miniv8::V8Context*)(*context);
    miniv8::V8Value* key = v8::Utils::openHandle<v8::Private, miniv8::V8Value>(*keyPrivate);
    v8::Local<v8::Value> keyVal = v8::Utils::convert<miniv8::V8Value, v8::Value>(key);
    //JSValue v = keyPri->v(keyPri);
    //v8::Local<v8::Value> key = v8::Utils::convert<miniv8::V8Value, v8::Value>(miniv8::V8Value::create(ctx, v));
    return Set(context, keyVal, val);
}

v8::Maybe<bool> v8::Object::Set(v8::Local<v8::Context> context, unsigned int index, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* valPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);
    miniv8::V8Context* v8context = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);

    JSValueConst value = valPtr->v(valPtr);
    JS_DupValue(v8context->ctx(), value);
    if (TRUE == JS_SetPropertyUint32(v8context->ctx(), self->v(self), index, value))
        return v8::Just<bool>(true);
    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::ForceSet(v8::Local<v8::Context> context, v8::Local<v8::Value> key, v8::Local<v8::Value> value, v8::PropertyAttribute attribs)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    return self->Set(context, key, value, true);
}

v8::Maybe<bool> v8::Object::Set(v8::Local<v8::Context> context, v8::Local<v8::Value> key, v8::Local<v8::Value> value)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    return self->Set(context, key, value, false);
}

void v8::Object::SetAccessorProperty(v8::Local<v8::Name>, v8::Local<v8::Function>, v8::Local<v8::Function>, v8::PropertyAttribute, v8::AccessControl)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::MaybeLocal<v8::Array> v8::Object::GetOwnPropertyNames(v8::Local<v8::Context> context)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Context* v8Context = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSContext* ctx = v8Context->ctx();
    JSValue val = self->v(self);
    JSPropertyEnum* tab = nullptr;
    uint32_t len = 0;

    v8::Local<v8::Array> ret = v8::Array::New(isolate, len);
    if (0 > JS_GetOwnPropertyNames(ctx, &tab, &len, val, JS_GPN_STRING_MASK | JS_GPN_SYMBOL_MASK | JS_GPN_ENUM_ONLY))
        return ret;

    for (size_t i = 0; i < len; ++i) {
        if (!(tab[i].is_enumerable))
            continue;
        const char* prop = JS_AtomToCString(ctx, tab[i].atom);
        v8::Local<v8::String> propStr = v8::String::NewFromOneByte(isolate, (const uint8_t*)prop, v8::NewStringType::kNormal, -1).ToLocalChecked();
        ret->Set(i, propStr);
        JS_FreeCString(ctx, prop);
    }

    JS_FreePropEnum(ctx, tab, len);
    JS_FreeValue(ctx, val);
    return ret;
}

v8::MaybeLocal<v8::Array> v8::Object::GetOwnPropertyNames(v8::Local<v8::Context> context, v8::PropertyFilter)
{
    return GetOwnPropertyNames(context);
}

v8::Local<v8::Array> v8::Object::GetOwnPropertyNames(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Array>();
}

v8::MaybeLocal<v8::Array> v8::Object::GetPropertyNames(v8::Local<v8::Context> context)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* v8Context = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    JSContext* ctx = v8Context->ctx();
    JSValue val = self->v(self);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    JSPropertyEnum* tab = nullptr;
    uint32_t len = 0;
    if (TRUE != JS_GetOwnPropertyNames(ctx, &tab, &len, val, JS_GPN_STRING_MASK|JS_GPN_SYMBOL_MASK|JS_GPN_ENUM_ONLY))
        return v8::MaybeLocal<v8::Array>();

    JSValue prototype = JS_GetPrototype(ctx, val);

    JSPropertyEnum* tab2 = nullptr;
    uint32_t len2 = 0;
    if (TRUE != JS_GetOwnPropertyNames(ctx, &tab2, &len2, prototype, JS_GPN_STRING_MASK | JS_GPN_SYMBOL_MASK | JS_GPN_ENUM_ONLY))
        len2 = 0;

    v8::Local<v8::Array> ret = v8::Array::New(isolate, len + len2);
    size_t i = 0;
    for (; i < len; ++i) {
        if (!(tab[i].is_enumerable))
            continue;
        const char* prop = JS_AtomToCString(ctx, tab[i].atom);
        v8::Local<v8::String> propStr = v8::String::NewFromOneByte(isolate, (const uint8_t*)prop, v8::NewStringType::kNormal, -1).ToLocalChecked();
        ret->Set(i, propStr);
        JS_FreeCString(ctx, prop);
    }

    for (; i < len + len2; ++i) {
        if (!(tab[i].is_enumerable))
            continue;
        const char* prop = JS_AtomToCString(ctx, tab2[i].atom);
        v8::Local<v8::String> propStr = v8::String::NewFromOneByte(isolate, (const uint8_t*)prop, v8::NewStringType::kNormal, -1).ToLocalChecked();
        ret->Set(i, propStr);
        JS_FreeCString(ctx, prop);
    }

    JS_FreeValue(ctx, val);
    JS_FreeValue(ctx, prototype);
    JS_FreePropEnum(ctx, tab2, len2);
    JS_FreePropEnum(ctx, tab2, len2);
    return ret;
}

int v8::Object::GetIdentityHash(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    return self->getId();
}

int v8::Object::InternalFieldCount(void)
{
    //printEmptyFuncInfo(__FUNCTION__, true);
//     return self->m_alignedPointerInInternalFields.size();

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);

    JSValue v = self->v(self);

    //printDebug("v8::Object::InternalFieldCount: %p, %d, %d\n", self, self->m_internalFieldCount, JS_IsUndefined(v));
    return self->m_internalFieldCount;
    //return miniv8::V8Object::kMaxaAlignedPointerArraySize;
}

v8::Local<v8::Value> v8::Object::SlowGetInternalField(int index)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8ReleaseAssert(index < miniv8::V8Object::kMaxaAlignedPointerArraySize, "v8::Object::GetInternalField fail\n");
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    if (!self->m_internalFields[index])
        return v8::Undefined((v8::Isolate*)isolate);

    v8::Local<v8::Value> ret = v8::Utils::convert<miniv8::V8Value, v8::Value>(self->m_internalFields[index]);
    return ret;
}

void v8::Object::SetInternalField(int index, v8::Local<v8::Value> value)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8ReleaseAssert(index < miniv8::V8Object::kMaxaAlignedPointerArraySize, "v8::Object::SetInternalField fail\n");
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* val = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*value);

    val->m_head.m_isInMember |= miniv8::V8Head::kIsSetInternalField;
    val->m_head.m_unGcType |= miniv8::V8Head::kIsSetInternalField;

    self->m_internalFields[index] = val; // TODO: GC的时候，有这个的可以不用回收
}

v8::Local<v8::Value> v8::Object::GetInternalField(int index)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8ReleaseAssert(index < miniv8::V8Object::kMaxaAlignedPointerArraySize, "v8::Object::GetInternalField fail\n");
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    if (!self->m_internalFields[index])
        return v8::Undefined((v8::Isolate *)isolate);

    v8::Local<v8::Value> ret = v8::Utils::convert<miniv8::V8Value, v8::Value>(self->m_internalFields[index]);
    return ret;
}

void v8::Object::SetAlignedPointerInInternalField(int index, void* value)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8ReleaseAssert(index < miniv8::V8Object::kMaxaAlignedPointerArraySize, "v8::Object::SetAlignedPointerInInternalField");
    //printDebug("v8::Object::SetAlignedPointerInInternalField: %p, index:%d, value:%p\n", self, index, value);

    self->m_alignedPointerInInternalFields[index] = value;

    if (1 == index) {
        miniv8ReleaseAssert(!(self->m_head.m_weakCallbackParam) || self->m_head.m_weakCallbackParam == value, "");
    }
}

static void copyEmytpIndex(void* arr1[], void* arr2[], int len)
{
    for (int i = 0; i < len; ++i) {
        if (nullptr != arr1[i])
            arr1[i] = arr2[i];
    }
}

void* v8::Object::GetAlignedPointerFromInternalField(int index)
{
    return SlowGetAlignedPointerFromInternalField(index);
}

void* v8::Object::SlowGetAlignedPointerFromInternalField(int index)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8ReleaseAssert(index < miniv8::V8Object::kMaxaAlignedPointerArraySize, "v8::Object::SlowGetAlignedPointerFromInternalField fail\n");

    void* it = self->m_alignedPointerInInternalFields[index];
    if (it)
        return it;

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);

    JSValueConst prototype = JS_GetPrototype(miniv8::V8Context::getCtx(ctx), self->v(self));
    miniv8::V8Object* prototypeObj = (miniv8::V8Object*)JS_GetUserdata(prototype);
    if (prototypeObj) {
        it = prototypeObj->m_alignedPointerInInternalFields[index];
        if (it) { // 拷贝一份，防止有些情况没有ctx获取不到prototype
            copyEmytpIndex(self->m_alignedPointerInInternalFields, prototypeObj->m_alignedPointerInInternalFields, miniv8::V8Object::kMaxaAlignedPointerArraySize);
            return it;
        }
    }

    // 见WindowProxy::installDOMWindow()，要查找原型的原型
    prototype = JS_GetPrototype(miniv8::V8Context::getCtx(ctx), prototype);
    prototypeObj = (miniv8::V8Object*)JS_GetUserdata(prototype);
    if (!prototypeObj)
        return nullptr;

    it = prototypeObj->m_alignedPointerInInternalFields[index];
    if (it) {
        copyEmytpIndex(self->m_alignedPointerInInternalFields, prototypeObj->m_alignedPointerInInternalFields, miniv8::V8Object::kMaxaAlignedPointerArraySize);
        return it;
    }

    return nullptr;
}

v8::Maybe<bool> v8::Object::SetPrototype(v8::Local<v8::Context> context, v8::Local<v8::Value> protoValue)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Context* v8ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Value* protoVal = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*protoValue);
    JSContext* ctx = v8ctx->ctx();

    if (self->SetPrototype(ctx, protoVal))
        return v8::Just<bool>(true);
    return v8::Just<bool>(false);
}

v8::Local<v8::Value> v8::Object::GetPrototype(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    return self->GetPrototype();
}

v8::Local<v8::Object> v8::Object::Clone(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);

    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    miniv8::V8Context* context = isolate->getCurrentCtx();
    JSContext* ctx = context->ctx();

    JSValue oldV = self->v(self);
    v8::Local<v8::Object> ret;
    if (1) {
        miniv8::V8Object* newObj = miniv8::V8Object::createFromClone(context, oldV);
        newObj->m_internalFieldCount = self->m_internalFieldCount;
        newObj->m_templId = self->m_templId;
        memcpy(newObj->m_alignedPointerInInternalFields, newObj->m_alignedPointerInInternalFields, sizeof(void*) * miniv8::V8Object::kMaxaAlignedPointerArraySize);

        ret = v8::Utils::convert<miniv8::V8Object, v8::Object>(newObj); // TODO: free
    } else {
        ret = v8::Utils::convert<miniv8::V8Object, v8::Object>(self);
    }

//     if (0) {
//         JSAtom prop = JS_NewAtom(ctx, "value");
//         JSValue test = JS_GetProperty(ctx, newV, prop);
//         test = JS_GetProperty(ctx, oldV, prop);
//     }
    return ret;
}

// 见v8::FunctionTemplate::HasInstance
v8::Local<v8::Object> v8::Object::FindInstanceInPrototypeChain(v8::Local<v8::FunctionTemplate> templ)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8ReleaseAssert(!templ.IsEmpty(), "v8::Object::FindInstanceInPrototypeChain fail\n"); // TODO; 这鬼函数有点奇葩

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8FunctionTemplate* funcTempl = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(*templ);

    JSValue v = self->v(self);
    JSValue proto = v;
    while (true) {
        miniv8::V8Object* protoV8 = (miniv8::V8Object*)JS_GetUserdata(proto);
        if (protoV8) {
            int id = protoV8->getTemplId();
            if (id == funcTempl->getId()) {
                if (JS_IsObject(protoV8->v(protoV8)))
                    return v8::Utils::convert<miniv8::V8Object, v8::Object>((miniv8::V8Object*)protoV8);
                else
                    return v8::Local<v8::Object>();
            }
        }

        JSValue next = JS_GetPrototypeFree(NULL, proto);
        if (JS_VALUE_IS_EQ(next, proto) || JS_VALUE_IS_EQ(next, JS_NULL) || JS_VALUE_IS_EQ(JS_UNDEFINED, next))
            return v8::Local<v8::Object>();
        proto = next;
    }
    return v8::Local<v8::Object>();
}

v8::Local<v8::Object> v8::Object::New(v8::Isolate* isolate)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSValue val = JS_NewObject(ctx->ctx());

    miniv8::V8Object* v = new miniv8::V8Object(ctx, val); // TODO: 放到句柄域
    v8::Local<v8::Object> ret = v8::Utils::convert<miniv8::V8Object, v8::Object>(v);

    return ret;
}

v8::Local<v8::Array> v8::Object::GetPropertyNames(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Array>();
}

v8::Isolate* v8::Object::GetIsolate(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    return (v8::Isolate*)(self->v8Ctx()->isolate());
}

v8::Local<v8::Context> v8::Object::CreationContext(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    if (self->m_ctx)
        return v8::Utils::convert<miniv8::V8Context, v8::Context>(self->m_ctx);
    return v8::Local<v8::Context>();
}

v8::Local<v8::String> v8::Object::GetConstructorName(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::String>();
}

// v8::Local<v8::Value> v8::Object::GetInternalField(int)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
//     return v8::Local<v8::Value>();
// }

v8::Maybe<v8::PropertyAttribute> v8::Object::GetPropertyAttributes(v8::Local<v8::Context>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Just<v8::PropertyAttribute>(v8::ReadOnly);
}

v8::Maybe<v8::PropertyAttribute> v8::Object::GetRealNamedPropertyAttributes(v8::Local<v8::Context>, v8::Local<v8::Name>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Just<v8::PropertyAttribute>(v8::ReadOnly);
}

v8::MaybeLocal<v8::String> v8::Object::ObjectProtoToString(v8::Local<v8::Context>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::MaybeLocal<v8::String>();
}

bool v8::Promise::HasHandler(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::StackFrame::IsEval(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::String::CanMakeExternal(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::String::ContainsOnlyOneByte(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();

    if (1 == JS_ContainsOnlyOneByte(ctx, self->v(self)))
        return true;
    return false;

//     const std::string& str = self->getStr();
//     if (-1 != self->m_isContainsOnlyOneByte)
//         return self->m_isContainsOnlyOneByte == 1;
// 
//     for (size_t i = 0; i < str.size(); ++i) {
//         char c = str[i];
//         if (!isascii(c)) {
//             self->m_isContainsOnlyOneByte = 0;
//             return false;
//         }
//     }
//     self->m_isContainsOnlyOneByte = 1;
//     return true;
}

bool v8::String::IsExternal(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    return !!self->m_twoByteExternalString;
}

bool v8::String::IsExternalOneByte(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    return !!self->m_oneByteExternalString;
}

bool v8::String::IsOneByte(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return true;
}

bool v8::String::MakeExternal(v8::String::ExternalOneByteStringResource* resource)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    self->m_oneByteExternalString = resource;
    return false;
}

bool v8::String::MakeExternal(v8::String::ExternalStringResource* resource)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    self->m_twoByteExternalString = resource;
    return false;
}

v8::String::ExternalStringResource* v8::String::GetExternalStringResource() const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    return self->m_twoByteExternalString;
}

v8::String::ExternalStringResourceBase* v8::String::GetExternalStringResourceBase(v8::String::Encoding* encoding_out) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    int tag = JS_VALUE_GET_TAG(self->m_head.m_qjsValue);
    if (self->m_twoByteExternalString)
        return self->m_twoByteExternalString;
    return self->m_oneByteExternalString;
}

const v8::String::ExternalOneByteStringResource* v8::String::GetExternalOneByteStringResource(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    int tag = JS_VALUE_GET_TAG(self->m_head.m_qjsValue);
    return self->m_oneByteExternalString;
}

int v8::String::Length(void) const
{
    //TODO: 这函数要搞个缓存，不然影响效率
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);

    int length = self->getStrCount();
    return length;
}

int v8::String::Utf8Length(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);

    const std::string& str = self->getStr();
    return str.size();
}

int v8::String::Write(uint16_t* buffer, int start, int length, int options) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);

    miniv8ReleaseAssert(0 == start, "v8::String::Write fail\n");

    const std::string& str = self->getStr();
    std::wstring wstr = miniv8::utf8ToUtf16(str);
    size_t len = length;
    if (len > wstr.size())
        len = wstr.size();
    memcpy(buffer, wstr.c_str(), len * sizeof(uint16_t));

    return (int)len;
}

int v8::String::WriteOneByte(uint8_t* buffer, int start, int length, int options) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);

    if (start != 0)
        DebugBreak();

    const std::string& str = self->getStr();
    int len = (int)str.size();
    if (start + length > len)
        length = len - start;

    memcpy(buffer, str.c_str() + start, length); // TODO: start+ length 没考虑溢出的情况
    return length;
}

int v8::String::WriteUtf8(char* buffer, int length, int* nchars_ref, int options) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);

    if (nchars_ref)
        DebugBreak();

    const std::string& str = self->getStr();
    size_t len = str.size();
    if (length > (int)len)  // v8好像规定如果写入结尾的0，len就要+1。如果不写，就不+1
        length = (int)len;

    memcpy(buffer, str.c_str(), length); // TODO: start+ length 没考虑溢出的情况
    return length;
}

v8::Local<v8::String> v8::String::Concat(v8::Local<v8::String> leftStr, v8::Local<v8::String> rightStr)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* left = v8::Utils::openHandle<v8::String, miniv8::V8String>(*leftStr);
    miniv8::V8String* right = v8::Utils::openHandle<v8::String, miniv8::V8String>(*rightStr);
    std::string str = left->getStr();
    str += right->getStr();

    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(str));
    return ret;
}

v8::Local<v8::String> v8::String::NewFromTwoByte(v8::Isolate* isolate, unsigned short const* lpszSrc, v8::String::NewStringType type, int length)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    if (-1 == length)
        length = (int)wcslen((const wchar_t *)lpszSrc);

    std::string utf8Str = miniv8::utf16ToChar((const wchar_t *)lpszSrc, length, CP_UTF8);
    return v8::String::NewFromUtf8(isolate, utf8Str.c_str(), type, utf8Str.size());
}

v8::Local<v8::String> v8::String::NewFromUtf8(v8::Isolate* isolate, char const* data, v8::String::NewStringType, int length)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    // TODO: 没考虑编码
    if (length == -1)
        length = strlen((const char*)data);
    std::string str((const char*)data, length);

    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(str)); // TODO free
    return ret;
}

v8::MaybeLocal<v8::String> v8::String::NewFromUtf8(v8::Isolate* isolate, const char* data, v8::NewStringType type, int length)
{
    printEmptyFuncInfo(__FUNCTION__, false);

    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    if (length == -1)
        length = strlen((const char*)data);
    std::string str((const char*)data, length);

    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(str)); // TODO free

    return ret;
}

v8::MaybeLocal<v8::String> v8::String::NewExternalOneByte(v8::Isolate* isolate, v8::String::ExternalOneByteStringResource* resource)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    // TODO:编码还没考虑
    if (!resource)
        return v8::MaybeLocal<v8::String>();         

    //std::string str(resource->data(), resource->length());
    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(resource)); // TODO free
    return ret;
}

v8::MaybeLocal<v8::String> v8::String::NewExternalTwoByte(v8::Isolate*, v8::String::ExternalStringResource* resource)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    if (!resource)
        return v8::MaybeLocal<v8::String>();
    //std::string str = miniv8::utf16ToChar((LPCWSTR)res->data(), res->length(), CP_UTF8);
    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(resource)); // TODO free
    return ret;
}

v8::Local<v8::String> v8::String::NewFromOneByte(v8::Isolate* isolate, unsigned char const* data, v8::String::NewStringType, int length)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    // TODO: 没考虑编码

    if (length == -1)
        length = strlen((const char*)data);
    std::string str((const char*)data, length);

    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(str)); // TODO free
    return ret;
}

v8::MaybeLocal<v8::String> v8::String::NewFromOneByte(v8::Isolate* isolate, unsigned char const* data, v8::NewStringType, int length)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    // TODO: 没考虑编码

    if (length == -1)
        length = strlen((const char*)data);
    std::string str((const char*)data, length);

    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(str)); // TODO free
    return ret;
}

v8::MaybeLocal<v8::String> v8::String::NewFromTwoByte(v8::Isolate* isolate, unsigned short const*, v8::NewStringType, int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::MaybeLocal<v8::String>();
}

v8::String::Utf8Value::Utf8Value(v8::Local<v8::Value> str)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    if (!str->IsString())
        DebugBreak();    
    miniv8::V8String* v8string = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(str.As<v8::String>()));
    const std::string& strv8 = v8string->getStr();

    this->str_ = (char*)strv8.c_str();
    this->length_ = (int)strv8.size();
}

v8::String::Utf8Value::~Utf8Value(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

#if V8_MINOR_VERSION < 8
v8::String::Value::Value(v8::Isolate* isolate, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* value = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);
    if (value->m_head.m_type != miniv8::kOTString) {
        DebugBreak();
        return;
    }

    miniv8::V8String* valueStr = (miniv8::V8String*)value;
    std::wstring str = miniv8::utf8ToUtf16(valueStr->getStr());
    length_ = (int)str.size();
    str_ = (uint16_t*)malloc(sizeof(uint16_t) * (length_ + 1));
    if (str.size() > 0)
        memcpy(str_, str.c_str(), sizeof(uint16_t) * (length_));
    str_[length_] = 0;
}
#endif

v8::String::Value::Value(v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

v8::String::Value::~Value(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    if (str_)
        free(str_);
}

bool v8::TryCatch::CanContinue(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)isolate_;
    return !isolate->hasErr();
}

bool v8::TryCatch::HasCaught(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)isolate_;
    return isolate->hasErr();
}

bool v8::TryCatch::HasTerminated(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

v8::TryCatch::TryCatch(v8::Isolate* isolate)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    isolate_ = (internal::Isolate*)isolate;
}

v8::TryCatch::TryCatch(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::TryCatch::~TryCatch(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::Local<v8::Value> v8::TryCatch::Exception(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);DebugBreak();
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::TryCatch::ReThrow(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Value>();
}

v8::Local<v8::Message> v8::TryCatch::Message(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Message>();
}

void v8::TryCatch::Reset(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)isolate_;
    isolate->clearErr(isolate->getCurrentJsCtx());
}

void v8::TryCatch::SetVerbose(bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}

bool v8::TryCatch::IsVerbose(void)const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return false;
}

// bool v8::V8::AddMessageListener(void(__cdecl*)(v8::Local<v8::Message>, v8::Local<v8::Value>), v8::Local<v8::Value>)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
//     return false;
// }

bool v8::V8::Initialize(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

// bool v8::V8::IsDead(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
//     return false;
// }

// bool v8::V8::IsExecutionTerminating(v8::Isolate*)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
//     return false;
// }

bool v8::Value::BooleanValue(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int ret = JS_ToBool(ctx, self->v(self));
    if (TRUE == ret)
        return true;
    return false;
}

bool v8::Value::Equals(v8::Local<v8::Value> other) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Value* otherPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*other);

    return JS_VALUE_IS_EQ(self->v(self), otherPtr->v(otherPtr));
}

bool v8::Value::IsArgumentsObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Value::IsArray(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int ret = JS_IsArray(ctx, self->v(self));
    return ret == TRUE;
}

bool v8::Value::IsArrayBuffer(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int ret = JS_IsArrayBuffer(self->v(self));
    return ret == TRUE;
}

bool v8::Value::IsArrayBufferView(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int ret = JS_IsArrayBufferView(self->v(self));
    return ret == TRUE;
}

bool v8::Value::IsBoolean(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsBool(self->v(self)) == TRUE;
}

bool v8::Value::IsBooleanObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsBool(self->v(self)) == TRUE;
}

bool v8::Value::IsDataView(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return false;
}

bool v8::Value::IsDate(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Value::IsExternal(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return self->m_head.m_type == miniv8::kOTExternal;
}

bool v8::Value::IsFunction(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return self->m_head.m_type == miniv8::V8ObjectType::kOTFunction || TRUE == JS_IsFunction(ctx, self->v(self));
}

bool v8::Value::IsGeneratorFunction(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Value::IsGeneratorObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Value::IsInt16Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Value::IsInt32(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsInteger(self->v(self)) == TRUE;
}

bool v8::Value::IsMap(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsMap(self->v(self)) == TRUE;
}

bool v8::Value::IsMapIterator(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsMapIterator(self->v(self)) == TRUE;
}

bool v8::Value::IsName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return false;
}

bool v8::Value::IsNativeError(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsException(self->v(self)) == TRUE;
}

bool v8::Value::IsNumber(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsNumber(self->v(self)) == TRUE;
}

bool v8::Value::IsNumberObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsNumber(self->v(self)) == TRUE;
}

bool v8::Value::IsObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTObject)
        return true;

    return JS_IsObject(self->v(self)) == TRUE;
}

bool v8::Value::IsPromise(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsPromise(self->v(self)) == TRUE;
}

bool v8::Value::IsProxy(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsProxy(self->v(self)) == TRUE;
}

bool v8::Value::IsRegExp(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsRegExp(self->v(self)) == TRUE;
}

bool v8::Value::IsSet(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsSet(self->v(self)) == TRUE;    
}

bool v8::Value::IsSetIterator(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsSetIterator(self->v(self)) == TRUE;
}

bool v8::Value::IsSharedArrayBuffer(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsSharedArrayBuffer(self->v(self)) == TRUE;
}

bool v8::Value::IsStringObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsString(self->v(self)) == TRUE;
}

bool v8::Value::IsSymbol(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTSymbol)
        return true;
    JSValue v = self->v(self);
    return JS_IsSymbol(v);
}

bool v8::Value::IsSymbolObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return IsSymbol();
}

bool v8::Value::IsFalse(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (JS_IsBool(self->v(self)) == TRUE) {
        int ret = JS_ToBool(ctx, self->v(self));
        if (FALSE == ret)
            return true;
    }
    return false;
}

bool v8::Value::IsTrue(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (!self)
        return false;
    if (JS_IsBool(self->v(self)) == TRUE) {
        int ret = JS_ToBool(ctx, self->v(self));
        if (TRUE == ret)
            return true;
    }
    return false;
}

bool v8::Value::IsTypedArray(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (miniv8::kOTUint8CArray <= self->m_head.m_type && self->m_head.m_type <= miniv8::kOTFloat64Array)
        return true;
    return JS_IsTypedArray(self->v(self));
}

bool v8::Value::IsUint16Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTUint16Array)
        return true;
    return JS_IsWhatTypedArray(self->v(self), JS_UINT16_TYPED_ARRAY);
}

bool v8::Value::IsUint32(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsInteger(self->v(self)) == TRUE;
}

bool v8::Value::IsUint32Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTUint32Array)
        return true;
    return JS_IsWhatTypedArray(self->v(self), JS_UINT32_TYPED_ARRAY);
}

bool v8::Value::IsUint8Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTUint8Array)
        return true;
    return JS_IsWhatTypedArray(self->v(self), JS_UINT8_TYPED_ARRAY);
}

bool v8::Value::IsUint8ClampedArray(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTUint8CArray)
        return true;
    return JS_IsWhatTypedArray(self->v(self), JS_UINT8C_TYPED_ARRAY);
}

bool v8::Value::IsFloat32Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTFloat32Array)
        return true;
    return JS_IsWhatTypedArray(self->v(self), JS_FLOAT32_TYPED_ARRAY);
}

bool v8::Value::IsFloat64Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTFloat64Array)
        return true;
    return JS_IsWhatTypedArray(self->v(self), JS_FLOAT64_TYPED_ARRAY);
}

bool v8::Value::IsInt32Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTInt32Array)
        return true;
    return JS_IsWhatTypedArray(self->v(self), JS_INT32_TYPED_ARRAY);
}

bool v8::Value::IsInt8Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTInt8Array)
        return true;
    return JS_IsWhatTypedArray(self->v(self), JS_INT8_TYPED_ARRAY);
}

bool v8::Value::IsWeakMap(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsWeakMap(self->v(self)) == TRUE;
}

bool v8::Value::IsWeakSet(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsWeakSet(self->v(self)) == TRUE;
}

bool v8::Value::StrictEquals(v8::Local<v8::Value> other) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    if (other.IsEmpty())
        return false;

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Value* otherVal = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*other);
    if (self == otherVal)
        return true;

    if (JS_VALUE_IS_EQ(self->v(self), otherVal->v(otherVal)))
        return true;
    return false;
}

double v8::Date::ValueOf(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

double v8::Number::Value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Number, miniv8::V8Value>(this);
    double res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    int ret = JS_ToFloat64(ctx, &res, self->v(self));
    if (0 == ret)
        return res;
    return 0;
}

double v8::NumberObject::ValueOf(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::NumberObject, miniv8::V8Value>(this);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    double res = 0;
    int ret = JS_ToFloat64(ctx, &res, self->v(self));
    if (0 == ret)
        return res;
    return 0;
}

double v8::Value::NumberValue(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    double res = 0;
    int ret = JS_ToFloat64(ctx, &res, self->v(self));
    if (0 == ret)
        return res;
    return 0;
}

v8::RegExp::Flags v8::RegExp::GetFlags(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::RegExp::kNone;
}

int v8::Function::GetScriptColumnNumber(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::Function::GetScriptLineNumber(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::Function::ScriptId(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::Int32::Value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Int32, miniv8::V8Value>(this);
    int32_t res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    int ret = JS_ToInt32(ctx, &res, self->v(self));
    if (0 == ret)
        return res;
    return 0;
}

int v8::Isolate::ContextDisposedNotification(bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::Message::GetEndColumn(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::Message::GetEndPosition(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::Message::GetLineNumber(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::Message::GetStartColumn(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::Message::GetStartPosition(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::StackFrame::GetColumn(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::StackFrame::GetLineNumber(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::StackFrame::GetScriptId(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::StackTrace::GetFrameCount(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::UnboundScript::GetId(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

#if V8_MINOR_VERSION < 8
v8::Local<v8::Value> v8::V8::GetEternal(v8::Isolate* iso, int index)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8ReleaseAssert(index < miniv8::V8Isolate::kSlotSize, "v8::V8::GetEternal fail\n");
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)iso;
    miniv8::V8Value* val = (miniv8::V8Value*)(isolate->m_eternals[index]);
    v8::Local<v8::Value> ret = v8::Utils::convert<miniv8::V8Value, v8::Value>(val);
    return ret;
}

void v8::V8::Eternalize(v8::Isolate* iso, v8::Value* v, int* index)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)iso;
    miniv8::V8Value* val = v8::Utils::toHandle<miniv8::V8Value>(*(uintptr_t*)v);
    val->m_head.m_unGcType |= miniv8::V8Head::kIsEternal; // 有这个标记的就不回收了

    for (int i = 0; i < miniv8::V8Isolate::kSlotSize; ++i) {
        if (isolate->m_eternals[i] == val) {
            *index = i;
            return;
        }
        if (!isolate->m_eternals[i]) {
            isolate->m_eternals[i] = val;
            *index = i;
            return;
        }
    }
    DebugBreak();
}

#else

v8::Value* v8::V8::Eternalize(v8::Isolate* iso, v8::Value* v)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)iso;
    miniv8::V8Value* val = v8::Utils::toHandle<miniv8::V8Value>(*(uintptr_t*)v);
    val->m_head.m_unGcType |= miniv8::V8Head::kIsEternal; // 有这个标记的就不回收了

    for (int i = 0; i < miniv8::V8Isolate::kSlotSize; ++i) {
        if (isolate->m_eternals[i] == val) {
            void* ptr = &isolate->m_eternals[i];
            return (v8::Value*)ptr;

        }
        if (!isolate->m_eternals[i]) {
            isolate->m_eternals[i] = v8::Utils::maskPtr(val);
            void* ptr = &isolate->m_eternals[i];
            return (v8::Value*)ptr;
        }
    }
    DebugBreak();
    return nullptr;
}
#endif

v8::internal::Object** v8::EscapableHandleScope::Escape(v8::internal::Object** obj)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return obj;
}

void* v8::V8::ClearWeak(v8::internal::Object** obj)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return obj;
}

void v8::Isolate::ReportExternalAllocationLimitReached(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

#if V8_MINOR_VERSION < 8
void v8::Isolate::SetObjectGroupId(v8::internal::Object** obj, v8::UniqueId uid)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //v8::internal::Internals::UpdateNodeFlag(obj, true, v8::internal::Internals::kNodeIsActiveShift); // 暂时简化处理，全部标记为激活态
    intptr_t id = *(intptr_t*)(&uid);
    miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)obj);
    head->m_objectGroupId = id;
}

void v8::Isolate::SetReference(v8::internal::Object** parent, v8::internal::Object** child)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    // 暂时简化处理，全部标记为激活态
//     v8::internal::Internals::UpdateNodeFlag(parent, true, v8::internal::Internals::kNodeIsActiveShift);
//     v8::internal::Internals::UpdateNodeFlag(child, true, v8::internal::Internals::kNodeIsActiveShift);

    miniv8::V8Head* parentHead = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)parent);
    miniv8::V8Head* childHead = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)child);

    childHead->m_objectGroupId = parentHead->m_objectGroupId;
}

void v8::Isolate::SetReferenceFromGroup(v8::UniqueId id, v8::internal::Object** obj)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    // 暂时简化处理，全部标记为激活态
    //v8::internal::Internals::UpdateNodeFlag(obj, true, v8::internal::Internals::kNodeIsActiveShift);
    SetObjectGroupId(obj, id);
}
#endif

void v8::V8::FromJustIsNothing(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::V8::ToLocalEmpty(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

const v8::ScriptCompiler::CachedData * v8::ScriptCompiler::StreamedSource::GetCachedData(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return nullptr;
}

unsigned int v8::Array::Length(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Array* arr = v8::Utils::openHandle<v8::Array, miniv8::V8Array>(this);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8::Isolate::GetCurrent();
    JSContext* ctx = miniv8::V8Context::getCurrentJsCtx();

    JSValue lengthVal = JS_GetPropertyStr(ctx, arr->v(arr), "length");
    if (!JS_IsInteger(lengthVal))
        return 0;

    int32_t res = 0;
    if (0 == JS_ToInt32(ctx, &res, lengthVal))
        return res;
    return 0;
}

unsigned int v8::CpuProfileNode::GetHitCount(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return 0;
}

unsigned int v8::CpuProfileNode::GetHitLineCount(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return 0;
}

unsigned int v8::CpuProfileNode::GetNodeId(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return 0;
}

unsigned int v8::HeapProfiler::GetHeapStats(v8::OutputStream*, __int64*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return 0;
}

unsigned int v8::HeapProfiler::GetObjectId(v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return 0;
}

size_t v8::Isolate::NumberOfHeapSpaces(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
    return 0;
}

uint32_t v8::Uint32::Value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Uint32, miniv8::V8Value>(this);
    int32_t res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    int ret = JS_ToInt32(ctx, &res, self->v(self));
    if (0 == ret)
        return res;
    return 0;
}

uint32_t v8::Value::Uint32Value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    uint32_t res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    int ret = JS_ToUint32(ctx, &res, self->v(self));
    if (0 == ret)
        return res;
    return 0;
}

v8::CpuProfile* v8::CpuProfiler::StopProfiling(v8::Local<v8::String>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return nullptr;
}

v8::CpuProfileNode const* v8::CpuProfile::GetSample(int) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return nullptr;
}

v8::CpuProfileNode const* v8::CpuProfile::GetTopDownRoot(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return nullptr;
}

v8::CpuProfileNode const* v8::CpuProfileNode::GetChild(int) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return nullptr;
}

v8::CpuProfiler* v8::Isolate::GetCpuProfiler(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return nullptr;
}

v8::EscapableHandleScope::EscapableHandleScope(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::HandleScope::HandleScope(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::HandleScope::~HandleScope(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::HeapProfiler* v8::Isolate::GetHeapProfiler(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return nullptr;
}

v8::HeapSnapshot const* v8::HeapProfiler::TakeHeapSnapshot(v8::ActivityControl*, v8::HeapProfiler::ObjectNameResolver*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return nullptr;
}

v8::HeapSpaceStatistics::HeapSpaceStatistics(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::HeapStatistics::HeapStatistics(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::Isolate* v8::Context::GetIsolate(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);
    return (v8::Isolate*)self->isolate();
}

v8::Isolate* v8::Isolate::GetCurrent(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return (v8::Isolate*)(miniv8::V8Isolate::GetCurrent());
}

v8::Isolate* v8::Isolate::New(const v8::Isolate::CreateParams& params)
{
    miniv8::V8Isolate* isolate = new miniv8::V8Isolate(params);
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8ReleaseAssert((v8::Isolate*)isolate == v8::Isolate::GetCurrent(), "v8::Isolate::New fail\n");
    return (v8::Isolate*)isolate;
}

// v8::Isolate::CreateParams::CreateParams(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
// }

v8::Local<v8::AccessorSignature> v8::AccessorSignature::New(v8::Isolate* v8Isolate, v8::Local<v8::FunctionTemplate> functionTemplate)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //return v8::Utils::convert<miniv8::V8AccessorSignature, v8::AccessorSignature>(new V8AccessorSignature());
    return v8::Local<v8::AccessorSignature>();
}

v8::Local<v8::Array> v8::Array::New(v8::Isolate* v8Isolate, int length)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8Isolate;
    
    miniv8::V8Context* ctx = isolate->getCurrentCtx();

    JSValue val = JS_NewArray(ctx->ctx());
    return v8::Utils::convert<miniv8::V8Array, v8::Array>(new miniv8::V8Array(ctx, val));
}

v8::Local<v8::Array> v8::Map::AsArray(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Array>();
}

v8::Local<v8::Array> v8::Set::AsArray(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Array>();
}

v8::Local<v8::Array> v8::StackTrace::AsArray(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Array>();
}

size_t v8::ArrayBuffer::ByteLength(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8ArrayBuffer* self = v8::Utils::openHandle<v8::ArrayBuffer, miniv8::V8ArrayBuffer>(this);

    size_t size = 0;
    uint8_t* data = self->getContents(&size);
    return size;
}

v8::ArrayBuffer::Contents v8::ArrayBuffer::Externalize(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return GetContents(); // TODO:暂时没搞明白Externalize和GetContents有啥区别
}

v8::ArrayBuffer::Contents v8::ArrayBuffer::GetContents(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8ArrayBuffer* self = v8::Utils::openHandle<v8::ArrayBuffer, miniv8::V8ArrayBuffer>(this);

    size_t size = 0;
    uint8_t* data = self->getContents(&size);

    v8::ArrayBuffer::Contents ret;
    ret.data_ = data;
    ret.byte_length_ = size;
    return ret;
}

v8::Local<v8::ArrayBuffer> v8::ArrayBuffer::New(v8::Isolate*, size_t)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::ArrayBuffer>();
}

void v8::ArrayBuffer::Neuter(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

static void onFreeArrayBufferDataFunc(JSRuntime* rt, void* opaque, void* ptr)
{
    v8::ArrayBuffer::Allocator* array_buffer_allocator = (v8::ArrayBuffer::Allocator*)opaque;
    array_buffer_allocator->Free(ptr, 0);
    DebugBreak();
}

v8::Local<v8::ArrayBuffer> v8::ArrayBuffer::New(v8::Isolate* v8Isolate, void* buf, size_t byte_length, v8::ArrayBufferCreationMode)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8Isolate;
    JSContext* jsCtx = isolate->getCurrentJsCtx();
    miniv8::V8Context* ctx = isolate->getCurrentCtx();

    void* arrayBufferAllocator = isolate->getCreateParams().array_buffer_allocator;
    JSValue v = JS_NewArrayBuffer(jsCtx, (uint8_t*)buf, byte_length, onFreeArrayBufferDataFunc, arrayBufferAllocator, TRUE);
    miniv8::V8ArrayBuffer* ret = new miniv8::V8ArrayBuffer(ctx, v);
    ret->m_internalFieldCount = 2;

    return v8::Utils::convert<miniv8::V8ArrayBuffer, v8::ArrayBuffer>(ret);
}

size_t v8::ArrayBufferView::ByteLength(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8ArrayBufferView* self = v8::Utils::openHandle<v8::ArrayBufferView, miniv8::V8ArrayBufferView>(this);
    return self->getByteLength();
}

size_t v8::ArrayBufferView::ByteOffset(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8ArrayBufferView* self = v8::Utils::openHandle<v8::ArrayBufferView, miniv8::V8ArrayBufferView>(this);
    return self->getByteOffset();
}

unsigned int v8::CpuProfileNode::GetCallUid(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return 0;
}

v8::Local<v8::ArrayBuffer> v8::ArrayBufferView::Buffer(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8ArrayBufferView* self = v8::Utils::openHandle<v8::ArrayBufferView, miniv8::V8ArrayBufferView>(this);
    return self->getBuffer();
}

v8::Local<v8::Object> v8::Context::Global(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);
    JSValue val = JS_GetGlobalObject(self->ctx());

    miniv8::V8Object* ret = miniv8::V8Object::create(self, val);
    return v8::Utils::convert<miniv8::V8Object, v8::Object>(ret);
}

v8::Local<v8::Context> v8::Context::New(v8::Isolate* isolate, v8::ExtensionConfiguration*, v8::MaybeLocal<v8::ObjectTemplate> globalTemplate, v8::MaybeLocal<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    JSContext* ctx = JS_NewContext(iso->getRuntime());
    miniv8::V8Context* ret = new miniv8::V8Context(iso, ctx);

    JSValue global = JS_GetGlobalObject(ctx);
    miniv8::V8Object* globalObj = miniv8::V8Object::create(ret, global);

    // blink会设置global的原型的原型，如果这里不设置一下，那么global的原型就是Object对象了
    // 这会导致innerGlobalObject->SetPrototype(context, windowWrapper)设置失败
    JSValue globalProto = JS_NewObject(ctx);
    JS_SetPrototype(ctx, global, globalProto);

    JS_SetPropertyStr(ctx, global, "jsPrint", JS_NewCFunction(ctx, jsPrint, "print", 0));
    JS_SetPropertyStr(ctx, global, "mbConsoleLog", JS_NewCFunction(ctx, jsPrint, "mbConsoleLog", 0));    
    JS_SetPropertyStr(ctx, global, "jsTestNode", JS_NewCFunction(ctx, jsTestNode, "jsTestNode", 0));
    JS_SetPropertyStr(ctx, global, "jsPrintStack", JS_NewCFunction(ctx, jsPrintStack, "jsPrintStack", 0));

    miniv8::V8ObjectTemplate* globalTempl = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(*(globalTemplate.ToLocalChecked()));
    if (globalTempl) {
        globalTempl->newTemplateInstance(globalObj, false);
        globalObj->setTemplId(globalTempl->getId());
    }
    // TODO: 没考虑m_instanceTemplate等情况

    return v8::Utils::convert<miniv8::V8Context, v8::Context>(ret);
}

v8::Local<v8::Context> v8::Isolate::GetCallingContext(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* self = (miniv8::V8Isolate*)this;
    miniv8::V8Context* ctx = self->getCurrentCtx();
    return v8::Utils::convert<miniv8::V8Context, v8::Context>(ctx);
}

v8::Local<v8::Context> v8::Isolate::GetCurrentContext(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* self = (miniv8::V8Isolate*)this;
    miniv8::V8Context* ctx = self->getCurrentCtx();
    return v8::Utils::convert<miniv8::V8Context, v8::Context>(ctx);
}

v8::Local<v8::Context> v8::Isolate::GetEnteredContext(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* self = (miniv8::V8Isolate*)this;
    miniv8::V8Context* ctx = self->getCurrentCtx();
    return v8::Utils::convert<miniv8::V8Context, v8::Context>(ctx);
}

v8::Local<v8::DataView> v8::DataView::New(v8::Local<v8::ArrayBuffer>, size_t, size_t)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::DataView>();
}

v8::Local<v8::External> v8::External::New(v8::Isolate* v8isolate, void* userdata)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8isolate;

    miniv8::V8External* ret = new miniv8::V8External(userdata);
    ret->m_userdata = userdata;
    return v8::Utils::convert<miniv8::V8External, v8::External>(ret);
}

v8::Local<v8::Function> v8::Function::New(v8::Isolate* isolate, v8::FunctionCallback callback, v8::Local<v8::Value> data, int length)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    //void* dataPtr = static_cast<void*>(v8::External::Cast(*data));

    miniv8::V8Function* ret = new miniv8::V8Function(ctx, callback, data);
    return v8::Utils::convert<miniv8::V8Function, v8::Function>(ret);
}

v8::MaybeLocal<v8::Function> v8::Function::New(v8::Local<v8::Context> context, v8::FunctionCallback callback, v8::Local<v8::Value> data, int length, v8::ConstructorBehavior behavior)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* ctx = (miniv8::V8Context*)(*context);

    //void* dataPtr = static_cast<void*>(v8::External::Cast(*data));
    miniv8::V8Function* ret = new miniv8::V8Function(ctx, callback, data);
    return v8::Utils::convert<miniv8::V8Function, v8::Function>(ret);
}

v8::Local<v8::Value> v8::Function::Call(v8::Local<v8::Value> recv, int argc, v8::Local<v8::Value> argv[])
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Function* self = v8::Utils::openHandle<v8::Function, miniv8::V8Function>(this);
    return Call(v8::Utils::convert<miniv8::V8Context, v8::Context>(self->v8Ctx()), recv, argc, argv).ToLocalChecked();
}

v8::MaybeLocal<v8::Value> v8::Function::Call(v8::Local<v8::Context> context, v8::Local<v8::Value> recv, int argc, v8::Local<v8::Value> argv[])
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Function* self = v8::Utils::openHandle<v8::Function, miniv8::V8Function>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Value* funcObj = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*recv);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    std::vector<JSValueConst> argvWrap;
    for (int i = 0; i < argc; ++i) {
        miniv8::V8Value* argVal = (miniv8::V8Value*)(*(argv[i]));
        argVal = v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)argVal);

        if (argVal->m_head.m_type > miniv8::V8ObjectType::kOTMax || argVal->m_head.m_type < miniv8::V8ObjectType::kOTMin)
            DebugBreak();

        JS_BOOL b = JS_IsNumber(argVal->v(argVal));

        argvWrap.push_back(argVal->v(argVal));
    }

    JSValue ret = JS_Call(ctx->ctx(), self->v(self), funcObj->v(funcObj), argc, 0 != argc ? &argvWrap[0] : nullptr);
    if (JS_IsException(ret)) {
        printWhenError(ctx->ctx());
        return v8::Undefined(isolate);
    }

    return v8::Utils::convert<miniv8::V8Value, v8::Value>(miniv8::V8Value::create(ctx, ret)); // TODO free
}

v8::Local<v8::Value> v8::Function::GetBoundFunction(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::Function::GetDisplayName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::Function::GetInferredName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Value>();
}

void v8::Function::SetName(v8::Local<v8::String> name)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Function* self = v8::Utils::openHandle<v8::Function, miniv8::V8Function>(this);
    miniv8::V8String* nameStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*name);

    std::string nameString = nameStr->getStr();
    self->m_name = nameString;
}

v8::Local<v8::Value> v8::Function::GetName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Function* self = v8::Utils::openHandle<v8::Function, miniv8::V8Function>(this);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    std::string name = self->getName();

    JSValue ret = JS_NewStringLen(ctx, name.c_str(), name.size());
    return v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(self->v8Ctx(), ret)); // TODO free
}

v8::MaybeLocal<v8::Object> v8::Function::NewInstance(v8::Local<Context> context, int argc, v8::Local<Value> argv[]) const
{
    printEmptyFuncInfo(__FUNCTION__, true);

    // 暂时没搞和Function::Call的区别
    miniv8::V8Function* self = v8::Utils::openHandle<v8::Function, miniv8::V8Function>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8::Isolate::GetCurrent();

    std::vector<JSValueConst> argvWrap;
    for (int i = 0; i < argc; ++i) {
        miniv8::V8Value* argVal = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*(argv[i]));
        argvWrap.push_back(argVal->v(argVal));
    }

    JSValue v = self->v(self); // will call JS_NewCFunction，获取Function
    // will call v8::internal::FunctionCallbackArguments::onConstructorCallback
    JSValue ret = JS_CallConstructor(ctx->ctx(), v, argc, 0 != argc ? &argvWrap[0] : nullptr);

    miniv8::V8Object* inst = miniv8::V8Object::create(ctx, ret);
    inst->setTemplId(self->getTemplId());

    inst->m_internalFieldCount = self->m_internalFieldCount;

    miniv8::V8Template* templ = isolate->getTemplateById(self->getTemplId());
    if (templ && templ->m_instanceTemplate) {
        templ->m_instanceTemplate->newTemplateInstance(inst, false);

        if (0 == inst->m_internalFieldCount)
            inst->m_internalFieldCount = templ->m_instanceTemplate->m_internalFieldCount;
    }
    return (v8::Utils::convert<miniv8::V8Object, v8::Object>(inst)); // TODO free
}

v8::ScriptOrigin v8::Function::GetScriptOrigin(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Function* self = v8::Utils::openHandle<v8::Function, miniv8::V8Function>(this);
    std::string name = self->getName();

    miniv8::V8Context* context = miniv8::V8Context::getCurrentOrEmptyCtx();

    JSValue nameVal = JS_NewStringLen(context->ctx(), name.c_str(), name.size());
    v8::Local<v8::String> nameStr = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(context, nameVal));

    return ScriptOrigin(nameStr);
}

//////////////////////////////////////////////////////////////////////////
// Template

// from G:\mycode\mb_temp\third_party\WebKit\Source\bindings\core\v8\V8DOMConfiguration.cpp doInstallMethodInternal
void v8::Template::Set(v8::Local<v8::Name> name, v8::Local<v8::Data> value, v8::PropertyAttribute attr)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    // value可以是v8::FunctionTemplate、v8::Integer等
    miniv8::V8Template* self = v8::Utils::openHandle<v8::Template, miniv8::V8Template>(this);
    self->Set(name, value, attr);
}

static void V8CALL functionCallbackEmpty(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    info.GetReturnValue().Set(info.This());
}

// static
v8::Local<v8::FunctionTemplate> v8::FunctionTemplate::New(
    v8::Isolate* isolate, 
    v8::FunctionCallback callback, 
    v8::Local<v8::Value> data, 
    v8::Local<v8::Signature> signature, 
    int length,
    v8::ConstructorBehavior behavior
    )
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8FunctionTemplate* self = new miniv8::V8FunctionTemplate();

    if (!data.IsEmpty()) {
        miniv8::V8External* dataVal = (miniv8::V8External*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*data); // TODO: free
        miniv8ReleaseAssert(dataVal->m_head.m_type == miniv8::kOTExternal, "v8::FunctionTemplate::New fail\n");

        self->m_userdata = dataVal->getUserdata();
    }
    self->m_constructor = callback ? callback : functionCallbackEmpty;
    self->m_argLength = length;
    self->m_signature.Reset(isolate, signature);

    v8::Local<v8::FunctionTemplate> ret = v8::Utils::convert<miniv8::V8FunctionTemplate, v8::FunctionTemplate>(self);
    return ret;
}

//look at v8::Object::FindInstanceInPrototypeChain 
bool v8::FunctionTemplate::HasInstance(v8::Local<v8::Value> object)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    if (object.IsEmpty())
        return false;

    miniv8::V8FunctionTemplate* self = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(this);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8::Isolate::GetCurrent();
    miniv8::V8Value* objVal = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*object);
    miniv8::V8Object* obj = miniv8::V8Object::getByQjsValue(objVal->v(objVal));
    if (!obj)
        return false;

    if (miniv8::V8ObjectType::kOTObject != obj->m_head.m_type &&
        miniv8::V8ObjectType::kOTArray != obj->m_head.m_type &&        
      (obj->m_head.m_type < miniv8::V8ObjectType::kOTUint8CArray || obj->m_head.m_type > miniv8::V8ObjectType::kOTFloat64Array)) {
        miniv8ReleaseAssert(false, "v8::FunctionTemplate::HasInstance fail\n");
        return false;
    } 

    miniv8::V8Template* objTempl = isolate->getTemplateById(obj->m_templId);
    
    while (objTempl) {
        if (objTempl->getId() == self->getId())
            return true;
        objTempl = objTempl->m_parentTemplate;
    }
    return false;
}

v8::Local<v8::ObjectTemplate> v8::FunctionTemplate::InstanceTemplate(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8FunctionTemplate* self = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(this);

    if (!self->m_instanceTemplate) { // TODO: 要记得检查m_parentTemplate是否设置过
        self->m_instanceTemplate = (new miniv8::V8ObjectTemplate());
        self->m_instanceTemplate->m_parentTemplate = self;
        self->m_instanceTemplate->m_internalFieldCount = self->m_internalFieldCount;
    }
    v8::Local<v8::ObjectTemplate> ret = v8::Utils::convert<miniv8::V8ObjectTemplate, v8::ObjectTemplate>(self->m_instanceTemplate);
    return ret;
}

v8::Local<v8::ObjectTemplate> v8::FunctionTemplate::PrototypeTemplate(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8FunctionTemplate* self = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(this);

    if (!self->m_prototypeTemplate) { // TODO: 要记得检查m_parentTemplate是否设置过
        self->m_prototypeTemplate = (new miniv8::V8ObjectTemplate());
        self->m_prototypeTemplate->m_parentTemplate = self;
        self->m_prototypeTemplate->m_internalFieldCount = self->m_internalFieldCount;
    }
    v8::Local<v8::ObjectTemplate> ret = v8::Utils::convert<miniv8::V8ObjectTemplate, v8::ObjectTemplate>(self->m_prototypeTemplate);
    return ret;
}

v8::Local<v8::Function> v8::FunctionTemplate::GetFunction(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8FunctionTemplate* self = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(this);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    return self->GetFunction(isolate->GetCurrentContext()).ToLocalChecked();
}

v8::MaybeLocal<v8::Function> v8::FunctionTemplate::GetFunction(v8::Local<v8::Context> context)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8FunctionTemplate* self = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(this);
    return self->GetFunction(context);
}

void v8::FunctionTemplate::Inherit(v8::Local<v8::FunctionTemplate> parentTemplate)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8FunctionTemplate* self = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(this);
    miniv8::V8FunctionTemplate* parent = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(*parentTemplate);
    self->inherit(parent);
}

void v8::FunctionTemplate::ReadOnlyPrototype(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::FunctionTemplate::RemovePrototype(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::FunctionTemplate::SetAcceptAnyReceiver(bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::FunctionTemplate::SetCallHandler(v8::FunctionCallback constructor, v8::Local<v8::Value> data
#if V8_MINOR_VERSION < 8
    , v8::experimental::FastAccessorBuilder* fastHandler
#endif
)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8External* dataExternal = nullptr;
    if (!data.IsEmpty())
        dataExternal = (miniv8::V8External*)(v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*data));

    miniv8ReleaseAssert(!dataExternal || dataExternal->m_head.m_type == miniv8::kOTExternal, "FunctionTemplate::SetCallHandler data fail\n");
#if V8_MINOR_VERSION < 8
    miniv8ReleaseAssert(!fastHandler, "FunctionTemplate::SetCallHandler fastHandler fail\n");
#endif

    miniv8::V8FunctionTemplate* self = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(this);
    self->m_constructor = constructor;
    self->m_userdata = dataExternal ? dataExternal->getUserdata() : nullptr;
}

void v8::FunctionTemplate::SetClassName(v8::Local<v8::String> name)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8FunctionTemplate* self = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(this);
    std::string nameStr = miniv8::getStringFromV8String(name);
    self->setClassName(nameStr);
}

void v8::FunctionTemplate::SetHiddenPrototype(bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::FunctionTemplate::SetLength(int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

//////////////////////////////////////////////////////////////////////////

// static
v8::Local<v8::ObjectTemplate> v8::ObjectTemplate::New(v8::Isolate*, v8::Local<v8::FunctionTemplate> constructor)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8ObjectTemplate* objTemp = new miniv8::V8ObjectTemplate();
    v8::Local<v8::ObjectTemplate> ret = v8::Utils::convert<miniv8::V8ObjectTemplate, v8::ObjectTemplate>(objTemp);
    return ret;
}

void v8::ObjectTemplate::MarkAsUndetectable(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::ObjectTemplate::SetAccessCheckCallback(bool(__cdecl*)(v8::Local<v8::Context>, v8::Local<v8::Object>, v8::Local<v8::Value>), v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Template::SetAccessorProperty(v8::Local<v8::Name> name, v8::Local<v8::FunctionTemplate> getter, v8::Local<v8::FunctionTemplate> setter, v8::PropertyAttribute, v8::AccessControl)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8ReleaseAssert(name->IsString(), "v8::Template::SetAccessorProperty fail 1\n");
    
    miniv8::V8Template* self = v8::Utils::openHandle<v8::Template, miniv8::V8Template>(this);
    miniv8::V8String* nameStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(name.As<v8::String>()));

    miniv8::V8FunctionTemplate* getterTempl = nullptr;
    if (!getter.IsEmpty())
        getterTempl = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(*getter);
    miniv8::V8FunctionTemplate* setterTempl = nullptr;
    if (!setter.IsEmpty())
        setterTempl = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(*setter);
    miniv8ReleaseAssert(getterTempl || setterTempl, "v8::Template::SetAccessorProperty fail 2\n");

    std::string nameString = nameStr->getStr();

    if (getterTempl && setterTempl)
        miniv8ReleaseAssert(getterTempl->m_userdata == setterTempl->m_userdata, "v8::Template::SetAccessorProperty fail 3\n");

//     std::map<std::string, miniv8::V8ObjectTemplate::Accessor>::const_iterator it = self->m_accessors.find(nameString);
//     if (it != self->m_accessors.end())
//         DebugBreak();

    miniv8::V8ObjectTemplate::Accessor accessor;
    accessor.getterFunc = getterTempl ? getterTempl->m_constructor : nullptr;
    accessor.setterFunc = setterTempl ? setterTempl->m_constructor : nullptr;
    accessor.data = getterTempl ? getterTempl->m_userdata : setterTempl->m_userdata;
    accessor.name = nameString;
    self->m_accessors.insert(std::make_pair(nameString, accessor));
}

void v8::Template::SetNativeDataProperty(
    v8::Local<v8::Name> name,
    v8::AccessorNameGetterCallback getter,
    v8::AccessorNameSetterCallback setter,
    v8::Local<v8::Value> data, 
    v8::PropertyAttribute attribute,
    v8::Local<v8::AccessorSignature> signature,
    v8::AccessControl settings
    )
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* nameStr = v8::Utils::openHandle<v8::Name, miniv8::V8String>(*name);

    size_t len = 0;
    std::string nameString = nameStr->getStr();
    if (nameString.empty())
        return;
    if (nameString == "length" || "name" == nameString || "toString" == nameString) // window属性的length暂不支持
        return;

    miniv8::V8External* external = v8::Utils::openHandle<v8::Value, miniv8::V8External>(*data);
    miniv8::V8Template* self = v8::Utils::openHandle<v8::Template, miniv8::V8Template>(this);
    miniv8::V8Template::Accessor accessor;
    accessor.nameGetter = getter;
    accessor.nameSetter = setter;
    accessor.data = external ? external->getUserdata() : nullptr;
    accessor.name = nameString;

    self->m_accessors.insert(std::make_pair(nameString, accessor));
}

void v8::ObjectTemplate::SetAccessor(
    v8::Local<v8::Name> name,
    v8::AccessorNameGetterCallback getter,
    v8::AccessorNameSetterCallback setter,
    v8::Local<v8::Value> data ,
    v8::AccessControl settings,
    v8::PropertyAttribute attribute,
    v8::Local<v8::AccessorSignature> signature
    )
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8String* nameStr = v8::Utils::openHandle<v8::Name, miniv8::V8String>(*name);

    size_t len = 0;
    std::string nameString = nameStr->getStr();
    if (nameString.empty())
        return;
    if (nameString == "length" || "name" == nameString || "toString" == nameString) // window属性的length暂不支持
        return;

    miniv8::V8External* external = v8::Utils::openHandle<v8::Value, miniv8::V8External>(*data);
    miniv8::V8ObjectTemplate* self = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(this);
    miniv8::V8ObjectTemplate::Accessor accessor;
    accessor.nameGetter = getter;
    accessor.nameSetter = setter;
    accessor.data = external->getUserdata();
    accessor.name = nameString;

    self->m_accessors.insert(std::make_pair(nameString, accessor));
}

void v8::ObjectTemplate::SetAccessor(
    v8::Local<v8::String> name,
    v8::AccessorGetterCallback getter,
    v8::AccessorSetterCallback setter, 
    v8::Local<v8::Value> data,
    v8::AccessControl settings,
    v8::PropertyAttribute attribute,
    v8::Local<v8::AccessorSignature> signature
    )
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8String* nameStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*name);
    size_t len = 0;
    std::string nameString = nameStr->getStr();
    if (nameString.empty())
        return;

    if (nameString == "length" || "name" == nameString || "toString" == nameString) // window属性的length暂不支持
        return;

    miniv8::V8External* external = v8::Utils::openHandle<v8::Value, miniv8::V8External>(*data);
    miniv8::V8ObjectTemplate* self = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(this);

    miniv8::V8ObjectTemplate::Accessor accessor;
    accessor.getter = getter;
    accessor.setter = setter;
    accessor.data = external ? external->getUserdata() : nullptr;

    self->m_accessors.insert(std::make_pair(nameString, accessor));
}

void v8::ObjectTemplate::SetCallAsFunctionHandler(v8::FunctionCallback cb, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    OutputDebugStringA("v8::ObjectTemplate::SetCallAsFunctionHandler not impl\n");
}

void v8::ObjectTemplate::SetHandler(const v8::IndexedPropertyHandlerConfiguration& indexedHandle)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8ObjectTemplate* self = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(this);
    self->m_indexedPropHandles = indexedHandle;
}

void v8::ObjectTemplate::SetHandler(const v8::NamedPropertyHandlerConfiguration& namedHandle)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8ObjectTemplate* self = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(this);
    self->m_namePropHandles = namedHandle;
}

void v8::ObjectTemplate::SetInternalFieldCount(int count)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8ObjectTemplate* self = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(this);
    self->m_internalFieldCount = count;

    if (self->m_parentTemplate) {
        int parentCount = self->m_parentTemplate->m_internalFieldCount;
        //miniv8ReleaseAssert(parentCount == 0 || parentCount == count, "v8::ObjectTemplate::SetInternalFieldCount fail\n");
        if (parentCount == 0)
            self->m_parentTemplate->m_internalFieldCount = count;
    }
    //printDebug("v8::ObjectTemplate::SetInternalFieldCount: %p, %d\n", this, count);
}

int v8::ObjectTemplate::InternalFieldCount()
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8ObjectTemplate* self = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(this);

    char* output = (char*)malloc(0x100);
    sprintf(output, "v8::ObjectTemplate::InternalFieldCount: %p\n", self);
    OutputDebugStringA(output);
    free(output);

    return self->m_internalFieldCount;
}

#if V8_MINOR_VERSION < 8


void v8::ObjectTemplate::SetNamedPropertyHandler(
    void(__cdecl*)(v8::Local<v8::Name>, v8::PropertyCallbackInfo<v8::Value> const&), 
    void(__cdecl*)(v8::Local<v8::Name>, v8::Local<v8::Value>, v8::PropertyCallbackInfo<v8::Value> const&), 
    void(__cdecl*)(v8::Local<v8::Name>, v8::PropertyCallbackInfo<v8::Integer> const&), 
    void(__cdecl*)(v8::Local<v8::Name>, v8::PropertyCallbackInfo<v8::Boolean> const&), 
    void(__cdecl*)(v8::PropertyCallbackInfo<v8::Array> const&), 
    v8::Local<v8::Value>
    )
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}
#else
void v8::ObjectTemplate::SetNamedPropertyHandler(
    v8::NamedPropertyGetterCallback getter,
    v8::NamedPropertySetterCallback setter,
    v8::NamedPropertyQueryCallback query,
    v8::NamedPropertyDeleterCallback deleter,
    v8::NamedPropertyEnumeratorCallback enumerator,
    v8::Local<v8::Value> data
    )
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}
#endif

v8::MaybeLocal<v8::Object> v8::ObjectTemplate::NewInstance(v8::Local<v8::Context> context)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8ObjectTemplate* self = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);

    JSValue v = JS_NewObject(ctx->ctx());
    miniv8::V8Object* obj = new miniv8::V8Object(ctx, v);
    self->newTemplateInstance(obj, false);

    v8::Local<v8::Object> ret = v8::Utils::convert<miniv8::V8Object, v8::Object>(obj);
    return v8::MaybeLocal<v8::Object>(ret);
}

//////////////////////////////////////////////////////////////////////////

v8::Local<v8::Int16Array> v8::Int16Array::New(v8::Local<v8::ArrayBuffer>, size_t, size_t)                                                      
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    miniv8::V8Int16Array* obj = nullptr;// new miniv8::Int16Array();
    v8::Local<v8::Int16Array> ret = v8::Utils::convert<miniv8::V8Int16Array, v8::Int16Array>(obj);
    
    return ret;
}

v8::Local<v8::Int32Array> v8::Int32Array::New(v8::Local<v8::ArrayBuffer>, size_t, size_t)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    miniv8::V8Int32Array* obj = nullptr;// new miniv8::Int16Array();
    v8::Local<v8::Int32Array> ret = v8::Utils::convert<miniv8::V8Int32Array, v8::Int32Array>(obj);

    return ret;
}

v8::Local<v8::Int8Array> v8::Int8Array::New(v8::Local<v8::ArrayBuffer>, size_t, size_t)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    miniv8::V8Int8Array* obj = nullptr;// new miniv8::Int16Array();
    v8::Local<v8::Int8Array> ret = v8::Utils::convert<miniv8::V8Int8Array, v8::Int8Array>(obj);

    return ret;
}

v8::Local<v8::Integer> v8::Integer::New(v8::Isolate*, int v)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Integer* obj = new miniv8::V8Integer(v);
    v8::Local<v8::Integer> ret = v8::Utils::convert<miniv8::V8Integer, v8::Integer>(obj);
    return ret;
}

v8::Local<v8::Integer> v8::Integer::NewFromUnsigned(v8::Isolate*, uint32_t v)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Integer* obj = new miniv8::V8Integer(v); // TODO: 没区分有无符号
    v8::Local<v8::Integer> ret = v8::Utils::convert<miniv8::V8Integer, v8::Integer>(obj);
    return ret;
}

size_t v8::TypedArray::Length(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8ArrayBufferView* arrayBufView = v8::Utils::openHandle<v8::TypedArray, miniv8::V8ArrayBufferView>(this);
    return arrayBufView->getEleCount();
}

template<typename V8TypeT, typename JsTypeT, JS_TYPED_ARRAY type>
static v8::Local<V8TypeT> typedArrayNew(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    JSContext* ctx = miniv8::V8Context::getCurrentJsCtx();
    miniv8::V8Context* context = miniv8::V8Context::getCurrentCtx();

    miniv8::V8ArrayBuffer* arrayBuf = v8::Utils::openHandle<v8::ArrayBuffer, miniv8::V8ArrayBuffer>(*arrayBuffer);
    JSValue val = JS_NewTypedArray(ctx, type, arrayBuf->v(arrayBuf), byteOffset, length);
    JsTypeT* ret = JsTypeT::create(context, val);
    JS_FreeValue(ctx, val);
    return v8::Utils::convert<JsTypeT, V8TypeT>(ret);
}

v8::Local<v8::Uint16Array> v8::Uint16Array::New(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return typedArrayNew<v8::Uint16Array, miniv8::V8Uint16Array, JS_UINT16_TYPED_ARRAY>(arrayBuffer, byteOffset, length);
}

v8::Local<v8::Uint32Array> v8::Uint32Array::New(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return typedArrayNew<v8::Uint32Array, miniv8::V8Uint32Array, JS_UINT32_TYPED_ARRAY>(arrayBuffer, byteOffset, length);
}

v8::Local<v8::Uint8Array> v8::Uint8Array::New(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return typedArrayNew<v8::Uint8Array, miniv8::V8Uint8Array, JS_UINT8_TYPED_ARRAY>(arrayBuffer, byteOffset, length);
}

v8::Local<v8::Uint8ClampedArray> v8::Uint8ClampedArray::New(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return typedArrayNew<v8::Uint8ClampedArray, miniv8::V8Uint8ClampedArray, JS_UINT8C_TYPED_ARRAY>(arrayBuffer, byteOffset, length);
}

v8::Local<v8::Float32Array> v8::Float32Array::New(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return typedArrayNew<v8::Float32Array, miniv8::V8Float32Array, JS_FLOAT32_TYPED_ARRAY>(arrayBuffer, byteOffset, length);
}

v8::Local<v8::Float64Array> v8::Float64Array::New(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return typedArrayNew<v8::Float64Array, miniv8::V8Float64Array, JS_FLOAT64_TYPED_ARRAY>(arrayBuffer, byteOffset, length);
}

v8::Local<v8::Map> v8::Map::New(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Map>();
}

v8::Local<v8::Message> v8::Exception::CreateMessage(v8::Isolate*, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Message>();
}

void v8::Isolate::IsolateInBackgroundNotification()
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::Local<v8::NativeWeakMap> v8::NativeWeakMap::New(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::NativeWeakMap>();
}

v8::Local<v8::Number> v8::Number::New(v8::Isolate*, double num)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Number* number = new miniv8::V8Number(num);
    v8::Local<v8::Number> ret = v8::Utils::convert<miniv8::V8Number, v8::Number>(number);
    return ret;
}

v8::Local<v8::Number> v8::Value::ToNumber(v8::Isolate*) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Number>();
}

// v8::Local<v8::Number> v8::Value::ToNumber(void) const
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
//     return v8::Local<v8::Number>();
// }

v8::Local<v8::Integer> v8::Value::ToInteger(v8::Isolate*) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::MaybeLocal<v8::Integer> ret = ToInteger(isolate->GetCurrentContext());
    return ret.ToLocalChecked();
}

v8::MaybeLocal<v8::Integer> v8::Value::ToInteger(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSValue v = self->v(self);
    miniv8::V8Integer* ret = nullptr;
    int32_t res;
    if (0 == JS_ToInt32(ctx->ctx(), &res, v)) {
        ret = new miniv8::V8Integer(res);
    } else
        ret = new miniv8::V8Integer(0);

    return v8::Utils::convert<miniv8::V8Integer, v8::Integer>(ret);
}

v8::MaybeLocal<v8::Number> v8::Value::ToNumber(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Number* num = nullptr;

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTNumber)
        return v8::Utils::convert<miniv8::V8Number, v8::Number>((miniv8::V8Number*)self);

    JSValue v = self->v(self);
    num = new miniv8::V8Number(ctx, v);

    //     int32_t res = 0;
    //     if (JS_IsInteger(v)) {
    //         JS_ToInt32(ctx, &res, v);
    //         num = new miniv8::V8Number();
    //     }
    return v8::Utils::convert<miniv8::V8Number, v8::Number>(num);
}

v8::MaybeLocal<v8::Object> v8::Value::ToObject(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    v8::Local<v8::Object> ret;
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    JSValue v = self->v(self);
    if (self->m_head.m_type == miniv8::kOTObject || JS_IsObject(v))
        ret = v8::Utils::convert<miniv8::V8Object, v8::Object>(miniv8::V8Object::create(ctx, v));
    else
        ret = v8::Object::New(isolate);

    return ret;
}

v8::Local<v8::Int32> v8::Value::ToInt32(v8::Isolate* isolate) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return ToInt32(isolate->GetCurrentContext()).ToLocalChecked();
}

v8::Maybe<int> v8::Value::Int32Value(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int32_t res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    int ret = JS_ToInt32(ctx, &res, self->v(self));
    if (0 <= ret)
        return v8::Just(res);
    return v8::Just(0);
}

int v8::Value::Int32Value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int32_t res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    int ret = JS_ToInt32(ctx, &res, self->v(self));
    if (0 <= ret)
        return res;
    return 0;
}

v8::MaybeLocal<v8::Int32> v8::Value::ToInt32(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int32_t res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    if (0 > JS_ToInt32(ctx, &res, self->v(self)))
        res = 0;
    miniv8::V8Int32* ret = new miniv8::V8Int32(res);
    return v8::Utils::convert<miniv8::V8Int32, v8::Int32>(ret);
}

v8::MaybeLocal<v8::Uint32> v8::Value::ToUint32(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int32_t res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    if (0 > JS_ToInt32(ctx, &res, self->v(self)))
        res = 0;
    miniv8::V8Uint32* ret = new miniv8::V8Uint32(res);
    return v8::Utils::convert<miniv8::V8Uint32, v8::Uint32>(ret);
}

v8::Maybe<unsigned int> v8::Value::Uint32Value(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int32_t res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    int ret = JS_ToInt32(ctx, &res, self->v(self));
    if (0 <= ret)
        return v8::Just((unsigned int)res);
    return v8::Just((unsigned int)0);
}

v8::MaybeLocal<v8::Uint32> v8::Value::ToArrayIndex(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Uint32> ret;
    DebugBreak();
    return ret;
}

v8::Local<v8::Boolean> v8::Value::ToBoolean(v8::Isolate* isolate) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return ToBoolean(isolate->GetCurrentContext()).ToLocalChecked();
}

v8::MaybeLocal<v8::Boolean> v8::Value::ToBoolean(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);

    bool b = 1 == JS_ToBool(ctx->ctx(), self->v(self));
    miniv8::V8Boolean* ret = new miniv8::V8Boolean(NULL, b);
    return v8::Utils::convert<miniv8::V8Boolean, v8::Boolean>(ret);
}

v8::Local<v8::Object> v8::Proxy::GetTarget(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Object>();
}

v8::Local<v8::Object> v8::Value::ToObject(v8::Isolate* isolata) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Context* context = miniv8::V8Context::getCurrentCtx();
    JSValue val = self->v(self);

//     if (self->m_head.m_type == miniv8::V8ObjectType::kOTObject) {
// //         miniv8::V8Object* ret = miniv8::V8Object::create(context, val);
// //         return v8::Utils::convert<miniv8::V8Object, v8::Object>(ret);
// 
//         return v8::Utils::convert<miniv8::V8Object, v8::Object>((miniv8::V8Object*)self);
// 
//     } else if (self->m_head.m_type == miniv8::V8ObjectType::kOTValue) {
//         if (JS_IsArrayBuffer(val)) {
// //             miniv8::V8Value* ret = miniv8::V8Value::create(context, val);
// //             return v8::Utils::convert<miniv8::V8Object, v8::Object>((miniv8::V8Object*)ret);
//             return v8::Utils::convert<miniv8::V8Object, v8::Object>((miniv8::V8Object*)self);
//         } else
//             DebugBreak();
//     } else
//         miniv8ReleaseAssert(false, "v8::Value::ToObject");

    switch (self->m_head.m_type) {
    case miniv8::V8ObjectType::kOTObject:
    case miniv8::V8ObjectType::kOTUint8CArray:
    case miniv8::V8ObjectType::kOTInt8Array:
    case miniv8::V8ObjectType::kOTUint8Array:
    case miniv8::V8ObjectType::kOTInt16Array:
    case miniv8::V8ObjectType::kOTUint16Array:
    case miniv8::V8ObjectType::kOTInt32Array:
    case miniv8::V8ObjectType::kOTUint32Array:
    case miniv8::V8ObjectType::kOTFloat32Array:
    case miniv8::V8ObjectType::kOTFloat64Array:
        return v8::Utils::convert<miniv8::V8Object, v8::Object>((miniv8::V8Object*)self);
    case miniv8::V8ObjectType::kOTValue:
        if (JS_IsObject(val)) {
            miniv8::V8Object* ret = miniv8::V8Object::create(context, val);
            return v8::Utils::convert<miniv8::V8Object, v8::Object>(ret);
        }
        DebugBreak();
    }

    return v8::Local<v8::Object>();
}

v8::Local<v8::Promise> v8::Promise::Resolver::GetPromise(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Promise>();
}

v8::Local<v8::Set> v8::Set::New(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Set>();
}

v8::Local<v8::Signature> v8::Signature::New(v8::Isolate*, v8::Local<v8::FunctionTemplate> templ)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8FunctionTemplate* templPtr = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(*templ);
    miniv8::V8Signature* ret = miniv8::V8Signature::create(templPtr);

    return v8::Utils::convert<miniv8::V8Signature, v8::Signature>(ret);
}

v8::Local<v8::StackFrame> v8::StackTrace::GetFrame(unsigned int) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::StackFrame>();
}

v8::Local<v8::StackTrace> v8::Message::GetStackTrace(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::StackTrace>();
}

v8::Local<v8::StackTrace> v8::StackTrace::CurrentStackTrace(v8::Isolate*, int, v8::StackTrace::StackTraceOptions)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8StackTrace* ret = new miniv8::V8StackTrace();
    return v8::Utils::convert<miniv8::V8StackTrace, v8::StackTrace>(ret);
}

v8::Local<v8::String> v8::CpuProfile::GetTitle(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::CpuProfileNode::GetFunctionName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::CpuProfileNode::GetScriptResourceName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::Message::Get(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::Message::GetSourceLine(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::RegExp::GetSource(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::StackFrame::GetFunctionName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::StackFrame::GetScriptName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::StackFrame::GetScriptNameOrSourceURL(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::StringObject::ValueOf(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::Value::ToString(v8::Isolate*) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8::Isolate::GetCurrent();
    miniv8::V8Context* context = isolate->getCurrentCtx();
    JSContext* ctx = isolate->getCurrentJsCtx();

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);

    JSValue v = self->v(self);
    JSValue retVal = JS_ToString(ctx, v);
    size_t len = 0;
    const char* ret = JS_ToCStringLen(ctx, &len, retVal);
    JS_FreeCString(ctx, ret);
    JS_FreeValue(ctx, retVal);
    return v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(context, retVal));
}

v8::Local<v8::Symbol> v8::Symbol::GetIterator(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Symbol* self = new miniv8::V8Symbol("Symbol.iterator");
    v8::Local<v8::Symbol> ret = v8::Utils::convert<miniv8::V8Symbol, v8::Symbol>(self);
    return ret;
}

v8::Local<v8::Symbol> v8::Symbol::GetToStringTag(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //printDebug("v8::Symbol::GetToStringTag not impl!\n");
    miniv8::V8Symbol* self = new miniv8::V8Symbol("Symbol.toStringTag");
    v8::Local<v8::Symbol> ret = v8::Utils::convert<miniv8::V8Symbol, v8::Symbol>(self);
    return ret;
}

v8::Local<v8::Symbol> v8::Symbol::GetUnscopables(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Symbol>();
}

v8::Local<v8::Symbol> v8::Symbol::New(v8::Isolate* isolate, v8::Local<v8::String> str)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* strVal = v8::Utils::openHandle<v8::String, miniv8::V8String>(*str);

    std::string symbolStr = "___";
    symbolStr += strVal->getStr();
    symbolStr += "___";
    miniv8::V8Symbol* self = new miniv8::V8Symbol(symbolStr);
    v8::Local<v8::Symbol> ret = v8::Utils::convert<miniv8::V8Symbol, v8::Symbol>(self);
    return ret;
}

v8::Local<v8::Symbol> v8::SymbolObject::ValueOf(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Symbol>();
}

v8::Local<v8::UnboundScript> v8::Script::GetUnboundScript(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::UnboundScript>();
}

v8::Local<v8::Value> v8::BooleanObject::New(v8::Isolate*, bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::Context::GetSecurityToken(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Value>();
}

static v8::Local<v8::Value> newError(v8::Local<v8::String> errorString, const char* type)
{
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::Local<v8::Object> err = v8::Object::New(isolate);
    v8::Local<v8::String> key = v8::String::NewFromUtf8(isolate, "error", v8::NewStringType::kNormal, -1).ToLocalChecked();
    err->Set(isolate->GetCurrentContext(), key, errorString);
    return err;
}

v8::Local<v8::Value> v8::Exception::Error(v8::Local<v8::String> errorString)
{
    printEmptyFuncInfo(__FUNCTION__, true);
//     miniv8::V8String* errStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*err);
//     miniv8::V8Exception* exc = new miniv8::V8Exception(errStr->getStr());
//     return v8::Utils::convert<miniv8::V8Value, v8::Value>((miniv8::V8Value*)exc);
    return newError(errorString, "error");
}

v8::Local<v8::Value> v8::Exception::RangeError(v8::Local<v8::String> errorString)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return newError(errorString, "error");
}

v8::Local<v8::Value> v8::Exception::ReferenceError(v8::Local<v8::String> errorString)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return newError(errorString, "error");
}

v8::Local<v8::Value> v8::Exception::SyntaxError(v8::Local<v8::String> errorString)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return newError(errorString, "error");
}

v8::Local<v8::Value> v8::Exception::TypeError(v8::Local<v8::String> errorString)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return newError(errorString, "error");
}

v8::Local<v8::Value> v8::HeapProfiler::FindObjectById(unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::Isolate::ThrowException(v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;
    miniv8::V8Context* context = isolate->getCurrentCtx();
    JSContext* ctx = context->ctx();
    JSValue v;

    std::string errorStr = "v8::Isolate::ThrowException!";

    //TODO: Free?
    if (val->IsObject()) {
        v8::Local<v8::Object> obj = val.As<v8::Object>();
        v8::Local<v8::String> key = v8::String::NewFromUtf8(this, "error", v8::NewStringType::kNormal, -1).ToLocalChecked();
        v8::MaybeLocal<v8::Value> err = obj->Get(this->GetCurrentContext(), key);
        if (!err.IsEmpty() && err.ToLocalChecked()->IsString()) {
            v8::Local<v8::String> errStr = err.ToLocalChecked().As<v8::String>();
            v8::String::Utf8Value errString(this, errStr);
            errorStr += *errString;
        }

        v = JS_ThrowTypeError(ctx, errorStr.c_str());
    } else if (val->IsString()) {
        miniv8::V8String* errStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(val.As<v8::String>()));
        v = JS_ThrowTypeError(ctx, errStr->getStr().c_str());
    }

    isolate->m_errorVal = v;
    return v8::Utils::convert<miniv8::V8Value, v8::Value>(new miniv8::V8Value(context, v));
}

v8::Local<v8::Value> v8::Message::GetScriptResourceName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::NativeWeakMap::Get(v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::NumberObject::New(v8::Isolate*, double)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::Proxy::GetHandler(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Value>();
}

// v8::Local<v8::Value> v8::StringObject::New(v8::Isolate*, v8::Local<v8::String>)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
//     return v8::Local<v8::Value>();
// }

v8::Local<v8::Value> v8::StringObject::New(v8::Local<v8::String>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::Symbol::Name(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Value>();
}

void v8::Locker::Initialize(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

// v8::Locker::Locker(v8::Isolate*)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
// }

v8::Locker::~Locker(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::Maybe<__int64> v8::Value::IntegerValue(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    __int64 val = 0;
    v8::Maybe<__int64> ret = v8::Just(val);
    DebugBreak();
    return ret;
}

v8::Maybe<bool> v8::Promise::Resolver::Reject(v8::Local<v8::Context>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<bool> ret = v8::Just(false);
    DebugBreak();
    return ret;
}

v8::Maybe<bool> v8::Promise::Resolver::Resolve(v8::Local<v8::Context>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<bool> ret = v8::Just(false);
    DebugBreak();
    return ret;
}

v8::Maybe<bool> v8::Value::BooleanValue(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSValue v = self->v(self);

    if (1 == JS_ToBool(ctx->ctx(), v))
        return v8::Just(true);
    return v8::Just(false);
}

v8::Maybe<double> v8::Value::NumberValue(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSValue v = self->v(self);
    double res = 0;
    if (0 == JS_ToFloat64(ctx->ctx(), &res, v))
        return v8::Just<double>(res);
    return v8::Just<double>(0);
}

v8::Maybe<int> v8::Message::GetEndColumn(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<int> ret = v8::Just(0);
    DebugBreak();
    return ret;
}

v8::Maybe<int> v8::Message::GetLineNumber(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<int> ret = v8::Just(0);
    DebugBreak();
    return ret;
}

v8::Maybe<int> v8::Message::GetStartColumn(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<int> ret = v8::Just(0);
    DebugBreak();
    return ret;
}

v8::MaybeLocal<v8::Map> v8::Map::Set(v8::Local<v8::Context>, v8::Local<v8::Value>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Map> ret;
    DebugBreak();
    return ret;
}

v8::MaybeLocal<v8::Promise::Resolver> v8::Promise::Resolver::New(v8::Local<v8::Context>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Promise::Resolver> ret;
    return ret;
}

v8::MaybeLocal<v8::Promise> v8::Promise::Catch(v8::Local<v8::Context>, v8::Local<v8::Function>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Promise> ret;
    return ret;
}

v8::MaybeLocal<v8::Promise> v8::Promise::Then(v8::Local<v8::Context>, v8::Local<v8::Function>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Promise> ret;
    return ret;
}

v8::MaybeLocal<v8::RegExp> v8::RegExp::New(v8::Local<v8::Context>, v8::Local<v8::String>, v8::RegExp::Flags)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::RegExp> ret;
    return ret;
}

v8::MaybeLocal<v8::Script> v8::Script::Compile(v8::Local<v8::Context> context, v8::Local<v8::String> source, v8::ScriptOrigin* scriptOrigin)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* sourceStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(source));
    std::string name = "[no name]";

    if (scriptOrigin) {
        v8::Local<v8::Value> resourceName = scriptOrigin->ResourceName();
        if (resourceName->IsString()) {
            miniv8::V8String* resName = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(resourceName.As<v8::String>()));
            name = resName->getStr();
        }
    }
    miniv8::V8Script* script = new miniv8::V8Script();
    script->setSource(sourceStr->getStr());
    script->setSourceName(name);
    v8::Local<v8::Script> ret = v8::Utils::convert<miniv8::V8Script, v8::Script>(script);
    return ret;
}

v8::MaybeLocal<v8::Script> v8::ScriptCompiler::Compile(v8::Local<v8::Context> context, v8::ScriptCompiler::Source* source, v8::ScriptCompiler::CompileOptions)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* sourceStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(source->source_string));
    std::string name;

    if (!source->resource_name.IsEmpty() && source->resource_name->IsString()) {
        v8::MaybeLocal<v8::String> sourceName = source->resource_name->ToString(context);
        miniv8::V8String* sourceNameStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(sourceName.ToLocalChecked()));
        name = sourceNameStr->getStr();
    }

    miniv8::V8Script* script = new miniv8::V8Script();
    script->setSource(sourceStr->getStr());
    script->setSourceName(name);
    v8::Local<v8::Script> ret = v8::Utils::convert<miniv8::V8Script, v8::Script>(script);
    return ret;
}

v8::MaybeLocal<v8::Script> v8::ScriptCompiler::Compile(v8::Local<v8::Context>, v8::ScriptCompiler::StreamedSource*, v8::Local<v8::String>, v8::ScriptOrigin const&)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Script> ret;
    DebugBreak();
    return ret;
}

v8::Local<v8::Value> v8::Script::Run(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    
    v8::MaybeLocal<v8::Value> ret = Run(isolate->GetCurrentContext());
    if (ret.IsEmpty())
        return v8::Local<v8::Value>();
    return ret.ToLocalChecked();
}

v8::MaybeLocal<v8::UnboundScript> v8::ScriptCompiler::CompileUnboundScript(v8::Isolate* isolate, v8::ScriptCompiler::Source* source, v8::ScriptCompiler::CompileOptions)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* sourceStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(source->source_string));
    std::string name;

    if (!source->resource_name.IsEmpty() && source->resource_name->IsString()) {
        v8::MaybeLocal<v8::String> sourceName = source->resource_name->ToString(isolate->GetCurrentContext());
        miniv8::V8String* sourceNameStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(sourceName.ToLocalChecked()));
        name = sourceNameStr->getStr();
    }

    miniv8::V8UnboundScript* script = new miniv8::V8UnboundScript();
    script->setSource(sourceStr->getStr());
    script->setSourceName(name);
    v8::Local<v8::UnboundScript> ret = v8::Utils::convert<miniv8::V8UnboundScript, v8::UnboundScript>(script);
    return ret;
}

v8::Local<v8::Script> v8::UnboundScript::BindToCurrentContext(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8UnboundScript* self = v8::Utils::openHandle<v8::UnboundScript, miniv8::V8UnboundScript>(this);

    miniv8::V8Script* script = new miniv8::V8Script();
    script->setSource(self->getSource());
    script->setSourceName(self->getSourceName());
    v8::Local<v8::Script> ret = v8::Utils::convert<miniv8::V8Script, v8::Script>(script);
    return ret;
}

/// <param name="buffer"></param>

bool saveDumpFile(const wchar_t* url, const char* buffer, unsigned int size)
{
    HANDLE hFile = CreateFileW(url, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE != hFile) {
        DWORD dwSize = 0;
        WriteFile(hFile, buffer, size, &dwSize, NULL);
        CloseHandle(hFile);
        return TRUE;
    }
    DebugBreak();
    return FALSE;
}

void readFile(const wchar_t* path, std::vector<char>* buffer)
{
    HANDLE hFile = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile) {
        DebugBreak();
    }

    DWORD fileSizeHigh;
    const DWORD bufferSize = ::GetFileSize(hFile, &fileSizeHigh);

    DWORD numberOfBytesRead = 0;
    buffer->resize(bufferSize);
    BOOL b = ::ReadFile(hFile, &buffer->at(0), bufferSize, &numberOfBytesRead, nullptr);
    ::CloseHandle(hFile);
    b = b;
}
v8::MaybeLocal<v8::Value> v8::Script::Run(v8::Local<v8::Context> context)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Script* self = v8::Utils::openHandle<v8::Script, miniv8::V8Script>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);

    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8::Isolate::GetCurrent();

    std::vector<char> buffer;
    
    // TODO: 返回值，可能是已经存在的dom之类的
    isolate->enterContext(ctx);

    JSValue ret;
    if ("bootstrap_node.js" == self->getSourceName()) {
        readFile(L"G:\\mycode\\mb_temp\\node\\lib\\internal\\bootstrap_node.js", &buffer);
        buffer.push_back(0);
        ret = JS_Eval(ctx->ctx(), buffer.data(), buffer.size() - 1, self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
//     } else if ("child_process.js" == self->getSourceName()) {
//         readFile(L"G:\\mycode\\mb_temp\\node\\lib\\child_process.js", &buffer);
//         buffer.push_back(0);
//         std::string src = "(function (exports, require, module, __filename, __dirname) { 'use strict';\n";
//         src += buffer.data();
//         src += "});";
//         ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
//     } else if ("stream.js" == self->getSourceName()) {
//         readFile(L"G:\\mycode\\mb_temp\\node\\lib\\stream.js", &buffer);
//         buffer.push_back(0);
//         std::string src = "(function (exports, require, module, __filename, __dirname) { 'use strict';\n";
//         src += buffer.data();
//         src += "});";
//         ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
//     } else if ("_stream_readable.js" == self->getSourceName()) {
//         readFile(L"G:\\test\\temp\\_stream_readable.js", &buffer);
//         buffer.push_back(0);
//         ret = JS_Eval(ctx->ctx(), buffer.data(), buffer.size() - 1, self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
// 
//     } else if ("_http_incoming.js" == self->getSourceName()) {
//         readFile(L"G:\\mycode\\mb_temp\\node\\lib\\_http_incoming.js", &buffer);
//         buffer.push_back(0);
//         std::string src = "(function (exports, require, module, __filename, __dirname) { 'use strict';\n";
//         src += buffer.data();
//         src += "});";
//         ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
//     } else if ("_http_common.js" == self->getSourceName()) {
//         readFile(L"G:\\mycode\\mb_temp\\node\\lib\\_http_common.js", &buffer);
//         buffer.push_back(0);
//         std::string src = "(function (exports, require, module, __filename, __dirname) { 'use strict';\n";
//         src += buffer.data();
//         src += "});";
//         ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
//    } else if ("buffer.js" == self->getSourceName()) {
//         readFile(L"G:\\mycode\\mininode\\node-v8.2.1\\lib\\buffer.js", &buffer);
//         buffer.push_back(0);
//         std::string src = "(function (exports, require, module, __filename, __dirname) {";
//         src += buffer.data();
//         src += "});";
//         ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
//     } else if ("fs.js" == self->getSourceName()) {
//         readFile(L"G:\\mycode\\mininode\\node-v8.2.1\\lib\\fs.js", &buffer);
//         buffer.push_back(0);
//         std::string src = "(function (exports, require, module, __filename, __dirname) {";
//         src += buffer.data();
//         src += "});";
//         ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
    } else if ("internal/child_process.js" == self->getSourceName()) {
        readFile(L"G:\\mycode\\mb_temp\\node\\lib\\internal\\child_process.js", &buffer);
        buffer.push_back(0);
        std::string src = "(function (exports, require, module, __filename, __dirname) {";
        src += buffer.data();
        src += "});";
        ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
    } else if ("net.js" == self->getSourceName()) {
        readFile(L"G:\\mycode\\mb_temp\\node\\lib\\net.js", &buffer);
        buffer.push_back(0);
        std::string src = "(function (exports, require, module, __filename, __dirname) {";
        src += buffer.data();
        src += "});";
        ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
    } else
        ret = JS_Eval(ctx->ctx(), self->getSource().c_str(), self->getSource().size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
    
    isolate->exitContext();

    if (JS_IsException(ret)) {
        printWhenError(ctx->ctx());
    }

    miniv8::V8Value* retVal = miniv8::V8Value::create(ctx, ret);
    return v8::Utils::convert<miniv8::V8Value, v8::Value>(retVal);
}

v8::MaybeLocal<v8::Set> v8::Set::Add(v8::Local<v8::Context>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Set> ret;
    return ret;
}

v8::MaybeLocal<v8::String> v8::Message::GetSourceLine(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::String> ret;
    return ret;
}

v8::MaybeLocal<v8::String> v8::Value::ToString(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::String> ret;

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8String* str = nullptr;

    JSValue v = self->v(self);
    if (miniv8::kOTString == self->m_head.m_type) {
        miniv8::V8String* str = (miniv8::V8String*)self;
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    } else if (miniv8::kOTValue == self->m_head.m_type) {
        
    } else if (JS_IsString(v)) {

    }

    char strbuf[126 * 2] = { 0 };
    uint32_t tag = JS_VALUE_GET_TAG(v);

    if (JS_TAG_IS_FLOAT64(tag)) {
        double d = JS_VALUE_GET_FLOAT64(v);
        sprintf_s(strbuf, "%f\n", d);

        str = new miniv8::V8String(strbuf);
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    }

    switch (tag) {
    case JS_TAG_INT: {
        int32_t int32Val = JS_VALUE_GET_INT(v);
        sprintf_s(strbuf, "%d\n", int32Val);
        str = new miniv8::V8String(strbuf);
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    }
    case JS_TAG_BOOL: {
        int32_t int32Val = JS_VALUE_GET_INT(v);
        str = new miniv8::V8String(int32Val == 0 ? "false" : "true");
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    }
    case JS_TAG_NULL: {
        str = new miniv8::V8String("null");
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    }
    case JS_TAG_UNDEFINED: {
        str = new miniv8::V8String("undefined");
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    }
    case JS_TAG_OBJECT: {
        str = new miniv8::V8String("[Object]");
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    }
    case JS_TAG_STRING: {
        str = new miniv8::V8String(ctx, v);
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    }
    default: {
        DebugBreak();
    }

    }
    return ret;
}

v8::MaybeLocal<v8::Value> v8::Date::New(v8::Local<v8::Context>, double)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    v8::MaybeLocal<v8::Value> ret;
    return ret;
}

v8::MaybeLocal<v8::Value> v8::JSON::Parse(v8::Isolate* isolate, v8::Local<v8::String> str)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    JSContext* ctx = miniv8::V8Context::getCurrentJsCtx(); 
    miniv8::V8Context* context = miniv8::V8Context::getCurrentCtx();

    miniv8::V8String* json = v8::Utils::openHandle<v8::String, miniv8::V8String>(*str);
    const std::string& jsonStr = json->getStr();
    JSValue val = JS_ParseJSON(ctx, jsonStr.c_str(), jsonStr.size(), "<JsonParse>");

    miniv8::V8Value* ret = miniv8::V8Value::create(context, val);
    return v8::Utils::convert<miniv8::V8Value, v8::Value>(ret);
}

v8::MaybeLocal<v8::Value> v8::Map::Get(v8::Local<v8::Context>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Value> ret;
    DebugBreak();
    return ret;
}

// v8::Platform* v8::platform::CreateDefaultPlatform(int)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
// }

v8::ResourceConstraints::ResourceConstraints(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::ScriptCompiler::CachedData::CachedData(unsigned char const*, int, v8::ScriptCompiler::CachedData::BufferPolicy)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::ScriptCompiler::CachedData::~CachedData(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::ScriptCompiler::ScriptStreamingTask* v8::ScriptCompiler::StartStreamingScript(v8::Isolate*, v8::ScriptCompiler::StreamedSource*, v8::ScriptCompiler::CompileOptions)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return nullptr;
}

v8::ScriptCompiler::StreamedSource::StreamedSource(v8::ScriptCompiler::ExternalSourceStream*, v8::ScriptCompiler::StreamedSource::Encoding)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::ScriptCompiler::StreamedSource::~StreamedSource(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::ScriptOrigin v8::Message::GetScriptOrigin(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);

    v8::Local<v8::String> resourceName = v8::String::NewFromUtf8(v8::Isolate::GetCurrent(), "v8::Message::GetScriptOrigin");
    return v8::ScriptOrigin(resourceName);
}
bool v8::ScriptCompiler::ExternalSourceStream::SetBookmark(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

void v8::ScriptCompiler::ExternalSourceStream::ResetToBookmark(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void* v8::External::Value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8External* self = v8::Utils::openHandle<v8::External, miniv8::V8External>(this);
    return self->getUserdata();
}

// void* v8::ScriptCompiler::CachedData::`scalar deleting destructor'(unsigned int)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
// }
// 
// void* v8::ScriptCompiler::StreamedSource::`scalar deleting destructor'(unsigned int)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
// }
// 
// void addAccessor(v8::Local<v8::Context>, char const*, __int64(__cdecl*)(struct JsExecStateInfo*, void*), void*, __int64(__cdecl*)(struct JsExecStateInfo*, void*), void*)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
// }

void v8::Context::AllowCodeGenerationFromStrings(bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Context::DetachGlobal(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);
    self->m_isDetachGlobal = true;
}

void v8::Context::Enter(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);

    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    isolate->enterContext(self);
}

void v8::Context::Exit(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    isolate->exitContext();
}

void v8::Context::SetErrorMessageForCodeGenerationFromStrings(v8::Local<v8::String>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Context::SetSecurityToken(v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Context::UseDefaultSecurityToken(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

// void v8::Eternal<v8::FunctionTemplate>::Set<v8::FunctionTemplate>(v8::Isolate*, v8::Local<v8::FunctionTemplate>)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
// }

void v8::HeapProfiler::ClearObjectIds(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

#if V8_MINOR_VERSION < 8
void v8::HeapProfiler::SetRetainedObjectInfo(v8::UniqueId, v8::RetainedObjectInfo*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}
#endif

void v8::HeapProfiler::SetWrapperClassInfoProvider(unsigned short, v8::RetainedObjectInfo * (__cdecl*)(unsigned short, v8::Local<v8::Value>))
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::HeapProfiler::StartTrackingHeapObjects(bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::HeapProfiler::StopTrackingHeapObjects(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::HeapSnapshot::Delete(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::HeapSnapshot::Serialize(v8::OutputStream*, v8::HeapSnapshot::SerializationFormat) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::AddCallCompletedCallback(void(__cdecl*)(void))
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::CancelTerminateExecution(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::Dispose(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::Enter(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::Exit(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::GetCodeRange(void**, size_t*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::GetHeapStatistics(v8::HeapStatistics*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::LowMemoryNotification(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate::GetCurrent()->runGC();
}

void v8::Isolate::RemoveCallCompletedCallback(void(__cdecl*)(void))
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::RequestInterrupt(void(__cdecl*)(v8::Isolate*, void*), void*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::EnqueueMicrotask(v8::MicrotaskCallback microtask, void* data)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;

    std::pair<void*, void*>* task = new std::pair<void*, void*>(microtask, data);
    isolate->m_microtasks.push_back(task);
}

void v8::Isolate::RunMicrotasks(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;
    isolate->runMicrotasks();
}

void v8::Isolate::SetAllowCodeGenerationFromStringsCallback(v8::AllowCodeGenerationFromStringsCallback callback)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::SetAutorunMicrotasks(bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::SetCaptureStackTraceForUncaughtExceptions(bool, int, v8::StackTrace::StackTraceOptions)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::SetEventLogger(void(__cdecl*)(char const*, int))
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::SetFailedAccessCheckCallbackFunction(void(__cdecl*)(v8::Local<v8::Object>, v8::AccessType, v8::Local<v8::Value>))
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::SetFatalErrorHandler(void(__cdecl*)(char const*, char const*))
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::SetPromiseRejectCallback(void(__cdecl*)(v8::PromiseRejectMessage))
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::SetStackLimit(size_t)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::SetUseCounterCallback(void(__cdecl*)(v8::Isolate*, v8::Isolate::UseCounterFeature))
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::TerminateExecution(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::NativeWeakMap::Set(v8::Local<v8::Value>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::RegisterExtension(v8::Extension*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::ResourceConstraints::ConfigureDefaults(unsigned __int64, unsigned __int64)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::V8::InitializePlatform(v8::Platform*)
{
    printEmptyFuncInfo(__FUNCTION__, false);
}

// void v8::V8::SetAllowCodeGenerationFromStringsCallback(bool(__cdecl*)(v8::Local<v8::Context>, v8::Local<v8::String>))
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
// }

// void v8::V8::SetCaptureStackTraceForUncaughtExceptions(bool, int, v8::StackTrace::StackTraceOptions)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
// }

void v8::V8::SetEntropySource(bool(__cdecl*)(unsigned char*, size_t))
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

// void v8::V8::SetFailedAccessCheckCallbackFunction(void(__cdecl*)(v8::Local<v8::Object>, v8::AccessType, v8::Local<v8::Value>))
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
// }

// void v8::V8::SetFatalErrorHandler(void(__cdecl*)(char const*, char const*))
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
// }

void v8::V8::SetFlagsFromCommandLine(int*, char**, bool)
{
    printEmptyFuncInfo(__FUNCTION__, false);
}

void v8::V8::SetFlagsFromString(char const*, int)
{
    printEmptyFuncInfo(__FUNCTION__, false);
}

// void v8::V8::TerminateExecution(v8::Isolate*)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
// }

__int64 v8::CpuProfile::GetEndTime(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

__int64 v8::CpuProfile::GetSampleTimestamp(int) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

__int64 v8::CpuProfile::GetStartTime(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

void v8::CpuProfile::Delete(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::CpuProfiler::SetIdle(bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::CpuProfiler::SetSamplingInterval(int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::CpuProfiler::StartProfiling(v8::Local<v8::String>, bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Debug::CancelDebugBreak(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Debug::DebugBreak(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Debug::ProcessDebugMessages(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Debug::SendCommand(v8::Isolate*, unsigned short const*, int, v8::Debug::ClientData*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Debug::SetLiveEditEnabled(v8::Isolate*, bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Debug::SetMessageHandler(v8::Isolate*, void(__cdecl*)(v8::Debug::Message const&))
{
    printEmptyFuncInfo(__FUNCTION__, true);
}
bool v8::Debug::CheckDebugBreak(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return true;
}

bool v8::Debug::SetDebugEventListener(v8::Isolate*, void(__cdecl*)(v8::Debug::EventDetails const&), v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return true;
}

int v8::CpuProfile::GetSamplesCount(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::CpuProfileNode::GetChildrenCount(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::CpuProfileNode::GetColumnNumber(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::CpuProfileNode::GetLineNumber(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::CpuProfileNode::GetScriptId(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

char const* v8::CpuProfileNode::GetBailoutReason(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return nullptr;
}

v8::Local<v8::Context> v8::Debug::GetDebugContext(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Context>();
}

v8::MaybeLocal<v8::Array> v8::Debug::GetInternalProperties(v8::Isolate*, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    ::DebugBreak();
    return v8::MaybeLocal<v8::Array>();
}

v8::MaybeLocal<v8::Value> v8::Debug::Call(v8::Local<v8::Context>, v8::Local<v8::Function>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::MaybeLocal<v8::Value>();
}

#if V8_MINOR_VERSION < 8
v8::MaybeLocal<v8::Value> v8::Debug::GetMirror(v8::Local<v8::Context>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::MaybeLocal<v8::Value>();
}
#endif

bool v8::CpuProfileNode::GetLineTicks(struct v8::CpuProfileNode::LineTick*, unsigned int) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

// int v8::internal::Internals::GetInstanceType(const v8::internal::Object* obj)
// {
// //     typedef internal::Object O;
// //     O* map = ReadField<O*>(obj, kHeapObjectMapOffset);
// //     // Map::InstanceType is defined so that it will always be loaded into
// //     // the LS 8 bits of one 16-bit word, regardless of endianess.
// //     return ReadField<uint16_t>(map, kMapInstanceTypeAndBitFieldOffset) & 0xff;
//     printEmptyFuncInfo(__FUNCTION__, true);
//     DebugBreak();
//     return 0;
// }

// int v8::internal::Internals::GetOddballKind(const v8::internal::Object* obj)
// {
// //     typedef internal::Object O;
// //     return SmiValue(ReadField<O*>(obj, kOddballKindOffset));
//     printEmptyFuncInfo(__FUNCTION__, true);
//     DebugBreak();
//     return 0;
// }

// bool v8::internal::Internals::IsExternalTwoByteString(int instance_type)
// {
//     int representation = (instance_type & kFullStringRepresentationMask);
//     return representation == kExternalTwoByteRepresentationTag;
// }

uint8_t v8::internal::Internals::GetNodeFlag(v8::internal::Object** obj, int shift)
{
//     uint8_t* addr = reinterpret_cast<uint8_t*>(obj) + kNodeFlagsOffset;
//     return *addr & static_cast<uint8_t>(1U << shift);
    printEmptyFuncInfo(__FUNCTION__, true);

    //miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::toHandle<miniv8::V8Data>((uintptr_t)obj);
    miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)obj);
//     uint8_t mask = static_cast<uint8_t>(1U << shift);
//     return head->m_nodeFlag & mask;
    return head->getNodeFlag(shift);
}

void v8::internal::Internals::UpdateNodeFlag(v8::internal::Object** obj, bool value, int shift)
{
//     uint8_t* addr = reinterpret_cast<uint8_t*>(obj) + kNodeFlagsOffset;
//     uint8_t mask = static_cast<uint8_t>(1U << shift);
//     *addr = static_cast<uint8_t>((*addr & ~mask) | (value << shift));
    printEmptyFuncInfo(__FUNCTION__, true);

    if (v8::internal::Internals::kNodeIsActiveShift == shift)
        OutputDebugStringA("");

    //miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::toHandle<miniv8::V8Data>((uintptr_t)obj);
    miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)obj);
    uint8_t mask = static_cast<uint8_t>(1U << shift);
    head->m_nodeFlag |= static_cast<uint8_t>((head->m_nodeFlag & ~mask) | (value << shift));
}

uint8_t v8::internal::Internals::GetNodeState(v8::internal::Object** obj)
{
//     uint8_t* addr = reinterpret_cast<uint8_t*>(obj) + kNodeFlagsOffset;
//     return *addr & kNodeStateMask;
    printEmptyFuncInfo(__FUNCTION__, true);
    //miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::toHandle<miniv8::V8Data>((uintptr_t)obj);
    miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)obj);
    return head->m_nodeState & kNodeStateMask;
}

void v8::internal::Internals::UpdateNodeState(v8::internal::Object** obj, uint8_t value)
{
//     uint8_t* addr = reinterpret_cast<uint8_t*>(obj) + kNodeFlagsOffset;
//     *addr = static_cast<uint8_t>((*addr & ~kNodeStateMask) | value);
    printEmptyFuncInfo(__FUNCTION__, true);
    //miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::toHandle<miniv8::V8Data>((uintptr_t)obj);
    miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)obj);
    head->m_nodeState = static_cast<uint8_t>((head->m_nodeState & ~kNodeStateMask) | value);
}

// v8::Local<v8::Primitive> v8::Undefined(Isolate* isolate)
// {
//     typedef internal::Object* S;
//     typedef internal::Internals I;
//     I::CheckInitialized(isolate);
//     S* slot = I::GetRoot(isolate, I::kUndefinedValueRootIndex);
//     return Local<Primitive>(reinterpret_cast<Primitive*>(slot));
// }
// 
// v8::Local<v8::Primitive> v8::Null(Isolate* isolate)
// {
//     typedef internal::Object* S;
//     typedef internal::Internals I;
//     I::CheckInitialized(isolate);
//     S* slot = I::GetRoot(isolate, I::kNullValueRootIndex);
//     return Local<Primitive>(reinterpret_cast<Primitive*>(slot));
// }
// 
// v8::Local<v8::Boolean> v8::True(v8::Isolate* isolate)
// {
//     typedef internal::Object* S;
//     typedef internal::Internals I;
//     I::CheckInitialized(isolate);
//     S* slot = I::GetRoot(isolate, I::kTrueValueRootIndex);
//     return Local<Boolean>(reinterpret_cast<Boolean*>(slot));
// }
// 
// v8::Local<v8::Boolean> v8::False(v8::Isolate* isolate)
// {
//     typedef internal::Object* S;
//     typedef internal::Internals I;
//     I::CheckInitialized(isolate);
//     S* slot = I::GetRoot(isolate, I::kFalseValueRootIndex);
//     return Local<Boolean>(reinterpret_cast<Boolean*>(slot));
// }

v8::Local<v8::String> v8::String::Empty(Isolate* isolate)
{
    typedef internal::Object* S;
    typedef internal::Internals I;
    I::CheckInitialized(isolate);
    S* slot = I::GetRoot(isolate, I::kEmptyStringRootIndex);
    return Local<String>(reinterpret_cast<String*>(slot));
}

bool v8::Value::IsUndefined() const
{
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (!self)
        return true;
    JSValue v = self->v(self);
    return !!JS_IsUndefined(v);
}

// bool v8::Value::QuickIsUndefined() const
// {
//     DebugBreak();
//     return false;
// }

bool v8::Value::IsNull() const
{
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    JSValue v = miniv8::V8Data::V8Data_v(self);
    return JS_VALUE_IS_EQ(v, JS_NULL);
}

// bool v8::Value::QuickIsNull() const
// {
//     DebugBreak();
//     return false;
// }

bool v8::Value::IsString() const
{
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);

    if (miniv8::kOTString == self->m_head.m_type)
        return true;
    JSValue v = self->v(self);
    return JS_IsString(v) != 0;
}

// bool v8::Value::QuickIsString() const
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
//     DebugBreak();
//     return false;
// }

v8::Local<v8::Value> v8::Context::SlowGetEmbedderData(int)
{
    DebugBreak();
    return v8::Local<v8::Value>();
}

bool v8::Value::FullIsNull(void)const
{
    DebugBreak();
    return false;
}

bool v8::Value::FullIsUndefined(void)const
{
    DebugBreak();
    return false;
}

#if V8_MINOR_VERSION >= 8
v8::MaybeLocal<v8::WasmCompiledModule> v8::ValueDeserializer::Delegate::GetWasmModuleFromId(v8::Isolate*, uint32_t)
{
    DebugBreak();
    return v8::MaybeLocal<v8::WasmCompiledModule>();
}

void v8::ArrayBuffer::Allocator::SetProtection(void* data, size_t length, v8::ArrayBuffer::Allocator::Protection protection)
{
    DebugBreak();
}

void v8::ArrayBuffer::Allocator::Free(void* data, size_t length, v8::ArrayBuffer::Allocator::AllocationMode mode)
{
    DebugBreak();
}

void* v8::ArrayBuffer::Allocator::Reserve(size_t length)
{
    DebugBreak();
    return nullptr;
}
#endif

void v8::Context::SetAlignedPointerInEmbedderData(int index, void* data)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);

    char* output = (char*)malloc(0x100);
    sprintf_s(output, 0x99, "v8::Context::SetAlignedPointerInEmbedderData: %p %p %p\n", self, this, data);
    OutputDebugStringA(output);
    free(output);

    self->m_alignedPointerInEmbedderDatas.insert(std::make_pair(index, data));
}

void v8::Context::SetEmbedderData(int, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

v8::Local<v8::Value> v8::Context::GetEmbedderData(int index)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Value>();
}

void* v8::Context::SlowGetAlignedPointerFromEmbedderData(int index)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);

    std::map<int, void *>::const_iterator it = self->m_alignedPointerInEmbedderDatas.find(index);
    if (it == self->m_alignedPointerInEmbedderDatas.end())
        return nullptr;
    return it->second;
}

void* v8::Context::GetAlignedPointerFromEmbedderData(int index)
{
    return SlowGetAlignedPointerFromEmbedderData(index);
}

namespace v8 {

namespace base {

class SysInfo {
public:
    // Returns the number of logical processors/core on the current machine.
    static int NumberOfProcessors();

    // Returns the number of bytes of physical memory on the current machine.
    static int64_t AmountOfPhysicalMemory();

    // Returns the number of bytes of virtual memory of this process. A return
    // value of zero means that there is no limit on the available virtual memory.
    static int64_t AmountOfVirtualMemory();
};

int SysInfo::NumberOfProcessors()
{
    return 0;
}

int64_t SysInfo::AmountOfPhysicalMemory()
{
    return 0;
}

int64_t SysInfo::AmountOfVirtualMemory()
{
    return 0;
}

}  // namespace base

bool g_patchForCreateDataProperty = false;
const int Function::kLineOffsetNotFound = 0;

v8::ValueSerializer::~ValueSerializer()
{
    printEmptyFuncInfo(__FUNCTION__, true);
}
v8::ValueSerializer::ValueSerializer(v8::Isolate*, v8::ValueSerializer::Delegate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

} // v8

void v8::Isolate::SetAbortOnUncaughtExceptionCallback(bool (__cdecl*)(v8::Isolate *))
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::ValueSerializer::SetTreatArrayBufferViewsAsHostObjects(bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

bool v8::Value::IsAsyncFunction(void)const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return false;
}

v8::Local<v8::Value> v8::Promise::Result(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Value>();
}

v8::Promise::PromiseState v8::Promise::State(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Promise::kRejected;
}

uint32_t v8::ScriptCompiler::CachedDataVersionTag(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return 0;
}

void v8::Isolate::SetPromiseHook(void(__cdecl*)(v8::PromiseHookType, v8::Local<v8::Promise>, v8::Local<v8::Value>))
{
    printEmptyFuncInfo(__FUNCTION__, true);
    OutputDebugStringA("v8::Isolate::SetPromiseHook is not impl\n");
}

v8::Maybe<uint32_t> v8::ValueSerializer::Delegate::GetSharedArrayBufferId(v8::Isolate*, v8::Local<v8::SharedArrayBuffer>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<uint32_t> ret = v8::Just<uint32_t>(0);
    DebugBreak();
    return ret;
}

v8::Maybe<bool> v8::ValueSerializer::Delegate::WriteHostObject(v8::Isolate*, v8::Local<v8::Object>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<bool> ret = v8::Just(false);
    DebugBreak();
    return ret;
}

void v8::ValueSerializer::WriteHeader()
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

v8::Maybe<bool> v8::ValueSerializer::WriteValue(v8::Local<v8::Context>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<bool> ret = v8::Just(false);
    DebugBreak();
    return ret;
}

// void v8::ValueSerializer::SetTreatArrayBufferViewsAsHostObjects(bool)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
// }

std::pair<uint8_t*, size_t> v8::ValueSerializer::Release()
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return std::make_pair(nullptr, 0);
}

void v8::ValueSerializer::TransferArrayBuffer(unsigned int, v8::Local<v8::ArrayBuffer>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

void v8::ValueSerializer::WriteUint32(unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

void v8::ValueSerializer::WriteUint64(uint64_t value)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

void v8::ValueSerializer::WriteDouble(double)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

void v8::ValueSerializer::WriteRawBytes(void const*, size_t)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

v8::ValueDeserializer::ValueDeserializer(v8::Isolate*, unsigned char const*, size_t, v8::ValueDeserializer::Delegate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

v8::ValueDeserializer::~ValueDeserializer()
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::MaybeLocal<v8::Object> v8::ValueDeserializer::Delegate::ReadHostObject(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return MaybeLocal<Object>();
}

v8::Maybe<bool> v8::ValueDeserializer::ReadHeader(v8::Local<v8::Context>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    v8::Maybe<bool> ret = v8::Just(false);
    return ret;
}

v8::MaybeLocal<v8::Value> v8::ValueDeserializer::ReadValue(v8::Local<v8::Context>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::MaybeLocal<Value>();
}

void v8::ValueDeserializer::TransferArrayBuffer(unsigned int, v8::Local<v8::ArrayBuffer>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

void v8::ValueDeserializer::TransferSharedArrayBuffer(unsigned int, v8::Local<v8::SharedArrayBuffer>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

uint32_t v8::ValueDeserializer::GetWireFormatVersion() const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

bool v8::ValueDeserializer::ReadUint32(uint32_t* value)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::ValueDeserializer::ReadUint64(uint64_t* value)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::ValueDeserializer::ReadDouble(double*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::ValueDeserializer::ReadRawBytes(size_t, void const**)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

v8::Maybe<uint32_t> v8::ValueSerializer::Delegate::GetWasmModuleTransferId(v8::Isolate*, v8::Local<v8::WasmCompiledModule>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<uint32_t> ret = v8::Just<uint32_t>(0);
    return ret;
}

void* v8::ValueSerializer::Delegate::ReallocateBufferMemory(void*, size_t, size_t*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return nullptr;
}

void v8::ValueSerializer::Delegate::FreeBufferMemory(void*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::PropertyDescriptor::set_configurable(bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::PropertyDescriptor::set_enumerable(bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::Maybe<bool> v8::Object::DefineProperty(v8::Local<v8::Context>, v8::Local<v8::Name>, v8::PropertyDescriptor&)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<bool> ret = v8::Just(false);
    return ret;
}

v8::PropertyDescriptor::PropertyDescriptor(v8::Local<v8::Value>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::PropertyDescriptor::~PropertyDescriptor()
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::PropertyDescriptor::PropertyDescriptor(v8::Local<v8::Value>, bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

// static
const char* v8::V8::GetVersion()
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return "5.7";
}

v8::SealHandleScope::SealHandleScope(v8::Isolate*) : isolate_(nullptr)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::SealHandleScope::~SealHandleScope()
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

bool v8::V8::Dispose()
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}


v8::MicrotasksScope::MicrotasksScope(Isolate* isolate, Type type)
    : isolate_((v8::internal::Isolate* const)isolate)
    // , microtask_queue_(nullptr)
    , run_(false)
{

}

v8::MicrotasksScope::~MicrotasksScope()
{

}

v8::Maybe<bool> v8::Object::SetIntegrityLevel(v8::Local<v8::Context>, v8::IntegrityLevel)
{
    OutputDebugStringA("v8::Object::SetIntegrityLevel is not impl\n");
    return v8::Just<bool>(true);
}

void v8::Object::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::ArrayBufferView::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::MaybeLocal<v8::String> v8::Value::ToDetailString(v8::Local<v8::Context>)const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::MaybeLocal<v8::String>();
}

void v8::Boolean::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}

void v8::Name::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}

void v8::String::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    // DebugBreak();
}

void v8::Symbol::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}

void v8::Number::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}

void v8::Integer::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}

void v8::Int32::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}

void v8::Uint32::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}

void v8::Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}

void v8::Map::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}

void v8::Set::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}

void v8::Function::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}

void v8::Promise::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}

void v8::Proxy::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}

void v8::WasmCompiledModule::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::ArrayBuffer::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::TypedArray::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::Uint8Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::Uint8ClampedArray::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::Int8Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::Uint16Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::Int16Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::Uint32Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    // DebugBreak();
}
void v8::Int32Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::Float32Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::Float64Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::DataView::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::SharedArrayBuffer::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::Date::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}

void v8::NumberObject::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::BooleanObject::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::StringObject::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::SymbolObject::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::RegExp::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}
void v8::External::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
}

void v8::Isolate::RemoveGCPrologueCallback(void(__cdecl*)(v8::Isolate*, v8::GCType, v8::GCCallbackFlags))
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

void v8::Isolate::RemoveGCEpilogueCallback(void(__cdecl*)(v8::Isolate*, enum v8::GCType, enum v8::GCCallbackFlags))
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

void v8::Isolate::RemoveMessageListeners(void(__cdecl*)(v8::Local<v8::Message>, v8::Local<v8::Value>))
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

void v8::Isolate::VisitExternalResources(v8::ExternalResourceVisitor*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

v8::SnapshotCreator::SnapshotCreator(intptr_t*, v8::StartupData*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

void v8::Unlocker::Initialize(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

void v8::Isolate::VisitHandlesForPartialDependence(v8::PersistentHandleVisitor*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

void v8::Promise::Resolver::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

namespace v8 {
namespace platform {
namespace tracing {

TracingController::TracingController()
{
    printEmptyFuncInfo(__FUNCTION__, true);
}
TracingController::~TracingController()
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void TraceBufferChunk::Reset(unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}
TraceBufferChunk::TraceBufferChunk(unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}
TraceObject* TraceBufferChunk::AddTraceEvent(size_t*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return nullptr;
}
TraceObject::~TraceObject()
{
    printEmptyFuncInfo(__FUNCTION__, true);
}
// static
TraceWriter* TraceWriter::CreateJSONTraceWriter(std::ostream&)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return nullptr;
}
void TraceConfig::AddIncludedCategory(char const*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}
void TracingController::Initialize(v8::platform::tracing::TraceBuffer*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}
void TracingController::StartTracing(v8::platform::tracing::TraceConfig*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}
void TracingController::StopTracing()
{
    printEmptyFuncInfo(__FUNCTION__, true);
}
}  // namespace tracing
}  // namespace platform
}  // namespace v8

class Miniv8Inspector : public v8_inspector::V8Inspector {
public:
    static std::unique_ptr<v8_inspector::V8Inspector> create(v8::Isolate*, v8_inspector::V8InspectorClient*)
    {
        std::unique_ptr<v8_inspector::V8Inspector> ret(new Miniv8Inspector());
        return std::move(ret);
    }
    virtual ~Miniv8Inspector() {}

    // Contexts instrumentation.
    virtual void contextCreated(const v8_inspector::V8ContextInfo&) override {}
    virtual void contextDestroyed(v8::Local<v8::Context>) override {}
    virtual void resetContextGroup(int contextGroupId) override {}

    // Various instrumentation.
#if V8_MINOR_VERSION < 8
    virtual void willExecuteScript(v8::Local<v8::Context>, int scriptId) override {}
    virtual void didExecuteScript(v8::Local<v8::Context>) override {}
#endif
    virtual void idleStarted() override {}
    virtual void idleFinished()override {}

    // Async stack traces instrumentation.
    virtual void asyncTaskScheduled(const v8_inspector::StringView& taskName, void* task, bool recurring) override {}
    virtual void asyncTaskCanceled(void* task) override {}
    virtual void asyncTaskStarted(void* task) override {}
    virtual void asyncTaskFinished(void* task) override {}
    virtual void allAsyncTasksCanceled()override {}

    // Exceptions instrumentation.
    virtual unsigned exceptionThrown(
        v8::Local<v8::Context>, const v8_inspector::StringView& message,
        v8::Local<v8::Value> exception, const v8_inspector::StringView& detailedMessage,
        const v8_inspector::StringView& url, unsigned lineNumber, unsigned columnNumber,
        std::unique_ptr<v8_inspector::V8StackTrace>, int scriptId) override
    {
        return 0;
    }
    virtual void exceptionRevoked(v8::Local<v8::Context>, unsigned exceptionId, const v8_inspector::StringView& message) override {}

    virtual std::unique_ptr<v8_inspector::V8InspectorSession> connect(int contextGroupId, v8_inspector::V8Inspector::Channel*, const v8_inspector::StringView& state) override
    {
        DebugBreak();
        return nullptr;
    }

    // API methods.
    virtual std::unique_ptr<v8_inspector::V8StackTrace> createStackTrace(v8::Local<v8::StackTrace>) override
    {
        DebugBreak();
        return nullptr;
    }
    virtual std::unique_ptr<v8_inspector::V8StackTrace> captureStackTrace(bool fullStack) override
    {
        DebugBreak();
        return nullptr;
    }
};

class Miniv8StringBuffer : public v8_inspector::StringBuffer {
public:
    Miniv8StringBuffer(const v8_inspector::StringView& str)
    {
        m_str = str;
    }

    virtual ~Miniv8StringBuffer() override {}
    virtual const v8_inspector::StringView& string() override
    {
        return m_str;
    }
    static std::unique_ptr<v8_inspector::StringBuffer> create(const v8_inspector::StringView& str)
    {
        std::unique_ptr<v8_inspector::StringBuffer> ret(new Miniv8StringBuffer(str));
        return std::move(ret);
    }
private:
    v8_inspector::StringView m_str;
};

std::unique_ptr<v8_inspector::StringBuffer> v8_inspector::StringBuffer::create(const v8_inspector::StringView& str)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return Miniv8StringBuffer::create(str);
}

std::unique_ptr<v8_inspector::V8Inspector> v8_inspector::V8Inspector::create(v8::Isolate* isolate, v8_inspector::V8InspectorClient* client)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return Miniv8Inspector::create(isolate, client);
}

void v8::Isolate::SetJitCodeEventHandler(v8::JitCodeEventOptions, v8::JitCodeEventHandler)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::AddGCPrologueCallback(v8::Isolate::GCCallback callback, v8::GCType gc_type)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;
    isolate->addGCPrologueCallback(callback, gc_type);
}

void v8::Isolate::AddGCEpilogueCallback(v8::Isolate::GCCallback callback, v8::GCType gc_type)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;
    isolate->addGCEpilogueCallback(callback, gc_type);
}

void v8::Isolate::VisitHandlesWithClassIds(v8::PersistentHandleVisitor* visitor)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;
    isolate->visitHandlesWithClassIds(visitor);
}

void v8::V8::AddGCEpilogueCallback(v8::GCCallback callback, v8::GCType gc_type)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    isolate->addGCEpilogueCallback((v8::Isolate::GCCallback)callback, gc_type);
}

void v8::V8::AddGCPrologueCallback(v8::GCCallback callback, v8::GCType gc_type)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    isolate->addGCPrologueCallback((v8::Isolate::GCCallback)callback, gc_type);
}

void v8::Isolate::VisitWeakHandles(v8::PersistentHandleVisitor* visitor)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;
    isolate->visitHandlesWithClassIds(visitor); // 暂时也走visitHandlesWithClassIds，以后再想办法
}

void v8::internal::Internals::CheckInitializedImpl(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

namespace v8 {
namespace platform {
void SetTracingController(Platform*, platform::tracing::TracingController*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}
}  // namespace platform
}  // namespace v8
