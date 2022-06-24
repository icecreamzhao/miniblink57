
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

static JSValue jsTestNode(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, void* userdata)
{
    JSValueConst v = argv[0];
    miniv8::V8Object* obj = (miniv8::V8Object*)JS_GetUserdata(v);

    char* output = (char*)malloc(0x100);
    sprintf_s(output, 0x99, "jsTestNode: %p\n", obj);
    OutputDebugStringA(output);
    free(output);

    return JS_UNDEFINED;
}

static JSValue jsPrint(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, void* userdata)
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

    jsPrint(ctx, JS_NULL, 1, &exception_val, nullptr);

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

namespace platform {
v8::Platform* CreateDefaultPlatform(int thread_pool_size);
bool PumpMessageLoop(v8::Platform*, v8::Isolate*);
}
}

namespace miniv8 {

V8Context::V8Context(V8Isolate* isolate, JSContext* ctx)
{
    m_head.m_type = kObjectTypeContext;
    m_isolate = isolate;
    m_ctx = ctx;
    m_isCodeGenerationFromStringsAllowed = true;
    JS_SetContextOpaque(ctx, this);

    char* output = (char*)malloc(0x100);
    sprintf(output, "V8Context::V8Context 1: %p\n", this);
    OutputDebugStringA(output);
    free(output);
}

V8Context::V8Context(const V8Context& other)
{
    m_head.m_type = other.m_head.m_type;
    m_isolate = other.m_isolate;
    m_ctx = other.m_ctx;
    m_isCodeGenerationFromStringsAllowed = other.m_isCodeGenerationFromStringsAllowed;

    char* output = (char*)malloc(0x100);
    sprintf(output, "V8Context::V8Context 2: %p\n", this);
    OutputDebugStringA(output);
    free(output);
}

} // miniv8

//////////////////////////////////////////////////////////////////////////

v8::Platform* v8::platform::CreateDefaultPlatform(int)
{
    printEmptyFuncInfo(__FUNCTION__, false);
    return nullptr;
}

bool v8::platform::PumpMessageLoop(v8::Platform*, v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false);
    return false;
}

__int64 v8::Integer::Value(void) const
{
    //printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Data* self = v8::Utils::openHandle<v8::Integer, miniv8::V8Data>(this);
    if (!JS_IsInteger(self->v(self)))
        return 0;

    __int64 result = 0;
    if (0 == JS_ToInt64(self->ctx(), &result, self->v(self)))
        return result;
    return 0;
}

__int64 v8::Value::IntegerValue(void) const
{
    //printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Data* self = v8::Utils::openHandle<v8::Value, miniv8::V8Data>(this);
    if (!JS_IsInteger(self->v(self)))
        return 0;

    __int64 result = 0;
    if (0 == JS_ToInt64(self->ctx(), &result, self->v(self)))
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
    return (0 != JS_ToBool(self->ctx(), self->v(self)));
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

bool v8::Isolate::GetHeapSpaceStatistics(v8::HeapSpaceStatistics*, unsigned int)
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

bool v8::Object::Delete(v8::Local<v8::Value> key)
{
    printEmptyFuncInfo(__FUNCTION__, false);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* keyPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);

    if (keyPtr->ctx() != self->ctx())
        DebugBreak();

    JSAtom prop = JS_ValueToAtom(keyPtr->ctx(), keyPtr->v(keyPtr));
    if (0 == prop)
        return false;
    return TRUE == JS_DeleteProperty(self->ctx(), self->v(self), prop, 0);
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

    if (valPtr->ctx() != self->ctx())
        DebugBreak();

    JSAtom value = JS_ValueToAtom(valPtr->ctx(), valPtr->v(valPtr));
    if (0 == value)
        return false;
    JS_DupValue(valPtr->ctx(), value);
    return TRUE == JS_SetPropertyUint32(self->ctx(), self->v(self), index, value);
}

bool v8::Object::Set(v8::Local<v8::Value> key, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, false);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* keyPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    miniv8::V8Value* valPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);

    if (valPtr->ctx() != self->ctx())
        DebugBreak();

    JSAtom prop = JS_ValueToAtom(valPtr->ctx(), keyPtr->v(keyPtr));
    if (0 == prop)
        return false;

    JSValueConst value = valPtr->v(valPtr);
    JS_DupValue(valPtr->ctx(), value);
    return TRUE == JS_SetProperty(self->ctx(), self->v(self), prop, valPtr->v(valPtr));
}

v8::Maybe<bool> v8::Object::ForceSet(v8::Local<v8::Context> context, v8::Local<v8::Value> key, v8::Local<v8::Value> value, v8::PropertyAttribute attribs)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    return Set(context, key, value);
}

v8::Maybe<bool> v8::Object::SetPrivate(v8::Local<v8::Context> context, v8::Local<v8::Private> keyPrivate, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* ctx = (miniv8::V8Context*)(*context);
    miniv8::V8Private* keyPri = v8::Utils::openHandle<v8::Private, miniv8::V8Private>(*keyPrivate);
    JSValue v = keyPri->v(keyPri);

    v8::Local<v8::Value> key = v8::Utils::convert<miniv8::V8Value, v8::Value>(miniv8::V8Value::create(ctx, v));
    return Set(context, key, val);
}

v8::Maybe<bool> v8::Object::Set(v8::Local<v8::Context> context, unsigned int index, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* valPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);

    miniv8::V8Context* ctx = (miniv8::V8Context*)(*context);
    if (ctx->ctx() != self->ctx())
        DebugBreak();

    if (valPtr->ctx() != self->ctx())
        DebugBreak();

    JSAtom value = JS_ValueToAtom(valPtr->ctx(), valPtr->v(valPtr));
    if (0 == value)
        return v8::Just<bool>(false);

    JS_DupValue(valPtr->ctx(), value);
    if (TRUE == JS_SetPropertyUint32(self->ctx(), self->v(self), index, value))
        v8::Just<bool>(true);
    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::Set(v8::Local<v8::Context> context, v8::Local<v8::Value> key, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* keyPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    miniv8::V8Value* valPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSContext* jsCtx = miniv8::V8Context::getCtx(ctx);
    if (!jsCtx)
        jsCtx = miniv8::V8Context::getCurrentJsCtx();
    if (!jsCtx)
        jsCtx = self->ctx();

    if (jsCtx != self->ctx()) {
        //DebugBreak();
        OutputDebugStringA("v8::Object::Set fail\n");
    }

    if (valPtr->ctx() && valPtr->ctx() != self->ctx()) {
        //DebugBreak();
        OutputDebugStringA("v8::Object::Set fail\n");
    }

    JSAtom prop = JS_ValueToAtom(jsCtx, keyPtr->v(keyPtr));
    if (0 == prop)
        return v8::Just<bool>(false);

    JSValue value = valPtr->v(valPtr);
    JS_DupValue(jsCtx, value);
    if (TRUE == JS_SetProperty(jsCtx, self->v(self), prop, value))
        return v8::Just<bool>(true);

    return v8::Just<bool>(false);
}

namespace miniv8 {

JSValue wrapGetter(JSContext* ctx, JSValueConst thisVal, void* userdata)
{
    miniv8::V8Object* self = (miniv8::V8Object*)JS_GetUserdata(thisVal);
    uint32_t hashVal = (uint32_t)userdata;

    std::map<uint32_t, miniv8::V8Object::AccessorData*>::iterator it = self->m_accessorMap.find(hashVal);
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
    accessor->getter(propV8, *infoV8);

    v8::ReturnValue<v8::Value>* returnValueV8 = (v8::ReturnValue<v8::Value>*)(&returnValue[3]);
    v8::Local<v8::Value> retV8 = returnValueV8->Get();
    miniv8::V8Value* ret = (miniv8::V8Value*)(*retV8);

    return ret->v(ret);
}

JSValue wrapSetter(JSContext* ctx, JSValueConst thisVal, JSValueConst val, void* userdata)
{
    //typedef void (V8CALL* AccessorSetterCallback)(Local<String> property, Local<Value> value, const PropertyCallbackInfo<void>& info)
    miniv8::V8Object* self = (miniv8::V8Object*)JS_GetUserdata(thisVal);
    uint32_t hashVal = (uint32_t)userdata;

    std::map<uint32_t, miniv8::V8Object::AccessorData*>::iterator it = self->m_accessorMap.find(hashVal);
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
    accessor->setter(propV8, valueV8, *infoV8);

    return JS_UNDEFINED;
}

} // miniv8

v8::Maybe<bool> v8::Object::SetAccessor(
    v8::Local<v8::Context> context, 
    v8::Local<v8::Name> name,
    v8::AccessorNameGetterCallback getter,
    v8::AccessorNameSetterCallback setter,
    v8::MaybeLocal<v8::Value> data, 
    v8::AccessControl settings, 
    v8::PropertyAttribute attribute
    )
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8String* namePtr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(name.As<v8::String>()));
    if (namePtr->getStr() == "stack")
        return v8::Just<bool>(true);

    return v8::Just<bool>(false);
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

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8String* namePtr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(name.As<v8::String>()));
    if (namePtr->getStr() == "stack")
        return (true);
    DebugBreak();
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

    size_t nameLen = 0;
    const char* nameStr = JS_ToCStringLen(self->ctx(), &nameLen, namePtr->v(namePtr));
    uint32_t hashVal = miniv8::hash(nameStr, nameLen);

    if (self->m_accessorMap.find(hashVal) != self->m_accessorMap.end())
        DebugBreak();

    size_t oldSize = 0;
    if (self->m_props)
        oldSize = self->m_props->size();

    std::vector<JSCFunctionListEntry>* props = new std::vector<JSCFunctionListEntry>();
    props->resize(oldSize + 1);

    if (self->m_props) {
        memcpy(props->data(), self->m_props->data(), oldSize * sizeof(JSCFunctionListEntry));
        delete self->m_props;
    }
    self->m_props = props;

    uint8_t propFlags = JS_PROP_CONFIGURABLE;
    if (attribute & ALL_CAN_WRITE)
        propFlags |= JS_PROP_WRITABLE;

    JSCFunctionListEntry prop = { 0 };
    prop.name = nameStr;
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

//     if (0 == miniv8::V8Object::s_classId) {
//         JS_NewClassID(&miniv8::V8Object::s_classId);
//         JS_SetClassProto(self->ctx(), miniv8::V8Object::s_classId, self->v(self));
//         JS_SetUserdata(self->v(self), self);
//     }
    JS_SetPropertyFunctionList(self->ctx(), self->v(self), self->m_props->data(), self->m_props->size());

    JS_FreeCString(self->ctx(), nameStr);

    return true;
}

v8::Maybe<bool> v8::Object::CreateDataProperty(v8::Local<v8::Context> context, unsigned int index, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, false);

    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* value = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);

    JSValueConst v = value->v(value);
    JS_DupValue(value->ctx(), v);
    int ret = JS_SetPropertyUint32(ctx->ctx(), self->v(self), index, v);
    if (TRUE == ret)
        return v8::Just<bool>(true);

    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::CreateDataProperty(v8::Local<v8::Context>context, v8::Local<v8::Name> key, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, false);

    if (key.IsEmpty() || val.IsEmpty()) // TODO:V8Document::preparePrototypeObject导致这里可能是空的
        return v8::Just<bool>(false);

    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* keyQjs = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    miniv8::V8Value* valueQjs = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);

    JSAtom keyAtom = JS_ValueToAtom(ctx->ctx(), keyQjs->v(keyQjs));

    JSValueConst v = valueQjs->v(valueQjs);
    JS_DupValue(ctx->ctx(), v);
    int ret = JS_SetProperty(ctx->ctx(), self->v(self), keyAtom, v);
    if (TRUE == ret)
        return v8::Just<bool>(true);
    
    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::DefineOwnProperty(v8::Local<v8::Context> context, v8::Local<v8::Name> key, v8::Local<v8::Value> value, v8::PropertyAttribute attributes)
{
    printEmptyFuncInfo(__FUNCTION__, false);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* keyQjs = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    miniv8::V8Value* val = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*value);

    size_t keyStrLen = 0;
    const char* keyStr = JS_ToCStringLen(self->ctx(), &keyStrLen, keyQjs->v(keyQjs));
    
    int flag = 0;
    if (0 == (attributes & v8::ReadOnly))
        flag |= JS_PROP_WRITABLE;
    if (0 == (attributes & v8::DontEnum))
        flag |= JS_PROP_ENUMERABLE;
    if (0 == (attributes & v8::DontDelete))
        flag |= JS_PROP_CONFIGURABLE;

    int ret = JS_DefinePropertyValueStr(ctx->ctx(), self->v(self), keyStr, val->v(val), flag);

    JS_FreeCString(self->ctx(), keyStr);
    if (TRUE == ret)
        return v8::Just<bool>(true);

    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::Delete(v8::Local<v8::Context> context, unsigned int index)
{
    printEmptyFuncInfo(__FUNCTION__, true);
//     miniv8::V8Context* ctx = (miniv8::V8Context*)(*context);
//     JS_NewInt64(ctx->ctx(), index);

    return v8::Just<bool>(false);
    
}

v8::Maybe<bool> v8::Object::Delete(v8::Local<v8::Context> context, v8::Local<v8::Value> key)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* keyQjs = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);

    JSAtom prop = JS_ValueToAtom(ctx->ctx(), keyQjs->v(keyQjs));

    int ret = JS_DeleteProperty(ctx->ctx(), self->v(self), prop, 0);
    if (TRUE == ret)
        return v8::Just<bool>(true);

    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::DeletePrivate(v8::Local<v8::Context> context, v8::Local<v8::Private> key)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* keyQjs = v8::Utils::openHandle<v8::Private, miniv8::V8Value>(*key);

    JSAtom prop = JS_ValueToAtom(ctx->ctx(), keyQjs->v(keyQjs));

    int ret = JS_DeleteProperty(ctx->ctx(), self->v(self), prop, 0);
    if (TRUE == ret)
        return v8::Just<bool>(true);

    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::Has(v8::Local<v8::Context> context, unsigned int index)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::Has(v8::Local<v8::Context> context, v8::Local<v8::Value> key)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* keyQjs = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);

    JSAtom prop = JS_ValueToAtom(ctx->ctx(), keyQjs->v(keyQjs));

    int ret = JS_HasProperty(ctx->ctx(), self->v(self), prop);
    if (TRUE == ret)
        return v8::Just<bool>(true);

    return v8::Just<bool>(false);
}


v8::Maybe<bool> v8::Object::HasOwnProperty(v8::Local<v8::Context> context, v8::Local<v8::Name> key)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    // TODO：V8Document::preparePrototypeObject -》 v8::Symbol::GetUnscopables，这个key可能是空的
    if (key.IsEmpty())
        return v8::Just<bool>(false);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* keyQjs = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);

    JSAtom prop = JS_ValueToAtom(ctx->ctx(), keyQjs->v(keyQjs));
    int ret = JS_HasProperty(ctx->ctx(), self->v(self), prop);
    if (TRUE == ret)
        return v8::Just<bool>(true);
    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::HasPrivate(v8::Local<v8::Context> context, v8::Local<v8::Private> key)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* keyQjs = v8::Utils::openHandle<v8::Private, miniv8::V8Value>(*key);

    JSAtom prop = JS_ValueToAtom(ctx->ctx(), keyQjs->v(keyQjs));

    int ret = JS_HasProperty(ctx->ctx(), self->v(self), prop);
    if (TRUE == ret)
        return v8::Just<bool>(true);

    return v8::Just<bool>(false);
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
    return ret;
}

v8::Local<v8::Value> v8::Object::Get(unsigned int index)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::Object::Get(v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Value>();
}

v8::MaybeLocal<v8::Value> v8::Object::Get(v8::Local<v8::Context> context, v8::Local<v8::Value> keyVal)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8String* key = v8::Utils::openHandle<v8::Value, miniv8::V8String>(*keyVal);
    if (key->m_head.m_type != miniv8::kObjectTypeString)
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
    }

    isolate->exitContext();

    miniv8::V8Value* v = miniv8::V8Value::create(ctx, val); // TODO: 放到句柄域
    v8::Local<v8::Value> ret = v8::Utils::convert<miniv8::V8Value, v8::Value>(v);

    return ret;
}

v8::MaybeLocal<v8::Value> v8::Object::GetOwnPropertyDescriptor(v8::Local<v8::Context>, v8::Local<v8::String>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::MaybeLocal<v8::Value>();
}

v8::MaybeLocal<v8::Value> v8::Object::GetPrivate(v8::Local<v8::Context>, v8::Local<v8::Private>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::MaybeLocal<v8::Value>();
}

v8::MaybeLocal<v8::Value> v8::Object::GetRealNamedProperty(v8::Local<v8::Context>, v8::Local<v8::Name>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::MaybeLocal<v8::Value>();
}

void v8::Object::SetAccessorProperty(v8::Local<v8::Name>, v8::Local<v8::Function>, v8::Local<v8::Function>, v8::PropertyAttribute, v8::AccessControl)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::MaybeLocal<v8::Array> v8::Object::GetOwnPropertyNames(v8::Local<v8::Context>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::MaybeLocal<v8::Array>();
}

v8::MaybeLocal<v8::Array> v8::Object::GetPropertyNames(v8::Local<v8::Context>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::MaybeLocal<v8::Array>();
}

int v8::Object::GetIdentityHash(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

int v8::Object::InternalFieldCount(void)
{
    //printEmptyFuncInfo(__FUNCTION__, true);
//     return self->m_alignedPointerInInternalFields.size();

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);

    JSValue v = self->v(self);

    //printDebug("v8::Object::InternalFieldCount: %p, %d, %d\n", self, self->m_internalFieldCount, JS_IsUndefined(v));
    return self->m_internalFieldCount;
}

v8::Local<v8::Value> v8::Object::SlowGetInternalField(int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Value>();
}

void v8::Object::SetInternalField(int index, v8::Local<v8::Value> value)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8ReleaseAssert(index < miniv8::V8Object::kMaxaAlignedPointerArraySize, "v8::Object::SetInternalField fail\n");
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* val = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*value);

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

    JSValue newV = JS_NULL;
    JSValue oldV = self->v(self);
    v8::Local<v8::Object> ret;
    if (1) {
        newV = JS_CloneValue(ctx, oldV);
        JS_DupValue(ctx, newV);

        miniv8::V8Object* newObj = miniv8::V8Object::createFromClone(context, newV);
        newObj->m_internalFieldCount = self->m_internalFieldCount;
        newObj->m_templId = self->m_templId;
        memcpy(newObj->m_alignedPointerInInternalFields, newObj->m_alignedPointerInInternalFields, sizeof(void*) * miniv8::V8Object::kMaxaAlignedPointerArraySize);

        ret = v8::Utils::convert<miniv8::V8Object, v8::Object>(newObj); // TODO: free
    } else {
        ret = v8::Utils::convert<miniv8::V8Object, v8::Object>(self);
    }
    if (0) {
        JSAtom prop = JS_NewAtom(ctx, "value");
        JSValue test = JS_GetProperty(ctx, newV, prop);
        test = JS_GetProperty(ctx, oldV, prop);
    }
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
        if (next == proto || next == JS_NULL || JS_UNDEFINED == next)
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

v8::Local<v8::Array> v8::Object::GetOwnPropertyNames(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::Array>();
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
    const std::string& str = self->getStr();
    if (-1 != self->m_isContainsOnlyOneByte)
        return self->m_isContainsOnlyOneByte == 1;

    for (size_t i = 0; i < str.size(); ++i) {
        char c = str[i];
        if (!isascii(c)) {
            self->m_isContainsOnlyOneByte = 0;
            return false;
        }
    }
    self->m_isContainsOnlyOneByte = 1;
    return true;
}

bool v8::String::IsExternal(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::String::IsExternalOneByte(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return true;
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
    self->m_externalString = resource;
    return false;
}

bool v8::String::MakeExternal(v8::String::ExternalStringResource* resource)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    self->m_externalString = resource;
    return false;
}

v8::String::ExternalStringResource* v8::String::GetExternalStringResource() const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    return (v8::String::ExternalStringResource*)self->m_externalString;
}

v8::String::ExternalStringResourceBase* v8::String::GetExternalStringResourceBase(v8::String::Encoding* encoding_out) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    int tag = JS_VALUE_GET_TAG(self->m_qjsValue);
    return self->m_externalString;
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
    size_t len = 0;

    const std::string& str = self->getStr();
    memcpy(buffer + start, str.c_str(), length); // TODO: start+ length 没考虑溢出的情况
    return start;
}

int v8::String::WriteUtf8(char*, int, int*, int) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return 0;
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

v8::Local<v8::String> v8::String::NewFromOneByte(v8::Isolate*, unsigned char const*, v8::String::NewStringType, int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::String::NewFromTwoByte(v8::Isolate*, unsigned short const*, v8::String::NewStringType, int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::String::NewFromUtf8(v8::Isolate*, char const*, v8::String::NewStringType, int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::String>();
}

v8::MaybeLocal<v8::String> v8::String::NewFromUtf8(v8::Isolate* isolate, const char* str, v8::NewStringType type, int len)
{
    printEmptyFuncInfo(__FUNCTION__, false);

    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(str)); // TODO free

    return ret;
}

v8::MaybeLocal<v8::String> v8::String::NewExternalOneByte(v8::Isolate* isolate, v8::String::ExternalOneByteStringResource* resource)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    // TODO:编码还没考虑
    if (!resource)
        return v8::MaybeLocal<v8::String>();         

    std::string str(resource->data(), resource->length());
    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(str)); // TODO free
    return ret;
}

v8::MaybeLocal<v8::String> v8::String::NewExternalTwoByte(v8::Isolate*, v8::String::ExternalStringResource* res)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    std::string str = miniv8::utf16ToChar((LPCWSTR)res->data(), res->length(), CP_UTF8);
    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(str)); // TODO free
    return ret;
}

v8::MaybeLocal<v8::String> v8::String::NewFromOneByte(v8::Isolate*, unsigned char const*, v8::NewStringType, int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::MaybeLocal<v8::String>();
}

v8::MaybeLocal<v8::String> v8::String::NewFromTwoByte(v8::Isolate*, unsigned short const*, v8::NewStringType, int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::MaybeLocal<v8::String>();
}

const v8::String::ExternalOneByteStringResource* v8::String::GetExternalOneByteStringResource(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return nullptr;
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

v8::String::Value::Value(v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

v8::String::Value::~Value(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

bool v8::TryCatch::CanContinue(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::TryCatch::HasCaught(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::TryCatch::HasTerminated(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
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
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int ret = JS_ToBool(self->ctx(), self->v(self));
    if (TRUE == ret)
        return true;
    return false;
}

bool v8::Value::Equals(v8::Local<v8::Value> other) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Value* otherPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*other);

    return self->v(self) == otherPtr->v(otherPtr);
}

bool v8::Value::IsArgumentsObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Value::IsArray(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int ret = JS_IsArray(self->ctx(), self->v(self));
    return ret == TRUE;
}

bool v8::Value::IsArrayBuffer(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int ret = JS_IsArray(self->ctx(), self->v(self));
    return ret == TRUE;
}

bool v8::Value::IsArrayBufferView(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int ret = JS_IsArray(self->ctx(), self->v(self));
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
    return self->m_head.m_type == miniv8::kObjectTypeExternal;
}

bool v8::Value::IsFloat32Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Value::IsFloat64Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Value::IsFunction(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return self->m_head.m_type == miniv8::V8ObjectType::kObjectTypeFunction || TRUE == JS_IsFunction(self->ctx(), self->v(self));
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

bool v8::Value::IsInt32Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Value::IsInt8Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Value::IsMap(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Value::IsMapIterator(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Value::IsName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Value::IsNativeError(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
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
    if (self->m_head.m_type == miniv8::kObjectTypeObject)
        return true;

    return JS_IsObject(self->v(self)) != 0;
}

bool v8::Value::IsPromise(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsPromise(self->v(self));
}

bool v8::Value::IsProxy(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsProxy(self->v(self));
}

bool v8::Value::IsRegExp(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsRegExp(self->v(self));
}

bool v8::Value::IsSet(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsSet(self->v(self));    
}

bool v8::Value::IsSetIterator(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Value::IsSharedArrayBuffer(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return false;
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
    if (self->m_head.m_type == miniv8::kObjectTypeSymbol)
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
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (JS_IsBool(self->v(self)) == TRUE) {
        int ret = JS_ToBool(self->ctx(), self->v(self));
        if (FALSE == ret)
            return true;
    }
    return false;
}

bool v8::Value::IsTrue(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (JS_IsBool(self->v(self)) == TRUE) {
        int ret = JS_ToBool(self->ctx(), self->v(self));
        if (TRUE == ret)
            return true;
    }
    return false;
}

bool v8::Value::IsTypedArray(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return false;
}

bool v8::Value::IsUint16Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return false;
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
    DebugBreak();
    return false;
}

bool v8::Value::IsUint8Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return false;
}

bool v8::Value::IsUint8ClampedArray(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

bool v8::Value::IsWeakMap(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return false;
}

bool v8::Value::IsWeakSet(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return false;
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

    if (self->v(self) == otherVal->v(otherVal))
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
    int ret = JS_ToFloat64(self->ctx(), &res, self->v(self));
    if (TRUE == ret)
        return res;
    return 0;
}

double v8::NumberObject::ValueOf(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::NumberObject, miniv8::V8Value>(this);
    double res = 0;
    int ret = JS_ToFloat64(self->ctx(), &res, self->v(self));
    if (TRUE == ret)
        return res;
    return 0;
}

double v8::Value::NumberValue(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    double res = 0;
    int ret = JS_ToFloat64(self->ctx(), &res, self->v(self));
    if (TRUE == ret)
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
    int ret = JS_ToInt32(self->ctx(), &res, self->v(self));
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

int v8::Value::Int32Value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int32_t res = 0;
    int ret = JS_ToInt32(self->ctx(), &res, self->v(self));
    if (0 == ret)
        return res;
    return 0;
}

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
    val->isEternal = true; // 有这个标记的就不回收了

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

v8::internal::Object** v8::EscapableHandleScope::Escape(v8::internal::Object**)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return nullptr;
}

void* v8::V8::ClearWeak(v8::internal::Object**)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return nullptr;
}

void v8::Isolate::ReportExternalAllocationLimitReached(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::SetObjectGroupId(v8::internal::Object**, v8::UniqueId)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::SetReference(v8::internal::Object**, v8::internal::Object**)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::SetReferenceFromGroup(v8::UniqueId, v8::internal::Object**)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::V8::DisposeGlobal(v8::internal::Object**)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::V8::FromJustIsNothing(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::V8::MakeWeak(v8::internal::Object**, void*, void(__cdecl*)(v8::WeakCallbackInfo<void> const&), v8::WeakCallbackType)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::V8::ToLocalEmpty(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

// TODO：全局引用，把一些local的也放到全局句柄里
v8::internal::Object** v8::V8::GlobalizeReference(v8::internal::Isolate* isolate, v8::internal::Object** obj)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;

    miniv8::V8Data* vdata = Utils::toHandle<miniv8::V8Data>(*(uint32_t*)obj);

    miniv8::V8ObjectType type = vdata->m_head.m_type;

    void** index = nullptr;
    miniv8::V8Head* head = (miniv8::V8Head*)vdata;
    if (!head->m_isolatGlobalScopeIndex) {
        index = iso->findGlobalizeHandleEmptyIndex();
        head->m_isolatGlobalScopeIndex = index;
        *index = v8::Utils::maskPtr(head);
    } else {
        index = (void**)head->m_isolatGlobalScopeIndex;
        return (v8::internal::Object **)index;
    }

    miniv8::V8Context* v8ctx = iso->getCurrentCtx();
    JSContext* ctx = v8ctx ? v8ctx->ctx() : nullptr;

    switch (type) {
    case miniv8::kObjectTypeValue: {
        miniv8::V8Value* ptr = (miniv8::V8Value*)vdata;
        //JSValue val = ptr->v(ptr); //TODO:?
        //JS_DupValue(ctx, val);
        break;
    }
    case miniv8::kObjectTypeString: {
        miniv8::V8String* ptr = (miniv8::V8String*)vdata;
        //JSValue val = ptr->v(ptr); //TODO:?
        //JS_DupValue(ctx, val);
        break;
    }
    case miniv8::kObjectTypeContext: {
        miniv8::V8Context* ctx = (miniv8::V8Context*)vdata;
        break;
    }
    case miniv8::kObjectTypeData: {
        miniv8::V8Data* ptr = (miniv8::V8Data*)*obj;
        break;
    }
    case miniv8::kObjectTypeObject: {
        miniv8::V8Object* ptr = (miniv8::V8Object*)vdata;
        JSValue val = ptr->v(ptr);
        JS_DupValue(ctx, val);
        break;
    }
    case miniv8::kObjectTypeFunction: {
        miniv8::V8Function* ptr = (miniv8::V8Function*)vdata;
        break;
    }
    case miniv8::kObjectTypeObjectTemplate: {
        miniv8::V8ObjectTemplate* ptr = (miniv8::V8ObjectTemplate*)vdata;
        break;
    }
    case miniv8::kObjectTypeFunctionTemplate: {
        miniv8::V8FunctionTemplate* ptr = (miniv8::V8FunctionTemplate*)vdata;
        break;
    }
    default:
        DebugBreak();
        break;
    }
    //printDebug("GlobalizeReference: %p %p\n", index, vdata);

    return (v8::internal::Object **)index;
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
    
    miniv8::V8ObjectType type = (miniv8::V8ObjectType)(*(uint32_t*)obj);
    miniv8::V8Data* vdata = Utils::toHandle<miniv8::V8Data>((uint32_t)obj);
    
    void* ret = nullptr;
    switch (vdata->m_head.m_type) {
    case miniv8::kObjectTypeContext: {
        miniv8::V8Context* ptr = (miniv8::V8Context*)vdata;
        ret = ptr;// new miniv8::V8Context(*ctx);
        break;
    }
    case miniv8::kObjectTypeData: {
        miniv8::V8Data* ptr = (miniv8::V8Data*)vdata;
        ret = ptr;// new miniv8::V8Data(*ptr);
        break;
    }
    case miniv8::kObjectTypeString: {
        miniv8::V8String* ptr = (miniv8::V8String*)vdata;
        ret = ptr;// new miniv8::V8FunctionTemplate(*ptr);
        break;
    }
    case miniv8::kObjectTypeObjectTemplate: {
        miniv8::V8ObjectTemplate* ptr = (miniv8::V8ObjectTemplate*)vdata;
        ret = ptr;// new miniv8::V8ObjectTemplate(*ptr);
        break;
    }
    case miniv8::kObjectTypeFunctionTemplate: {
        miniv8::V8FunctionTemplate* ptr = (miniv8::V8FunctionTemplate*)vdata;
        ret = ptr;// new miniv8::V8FunctionTemplate(*ptr);
        break;
    }
    case miniv8::kObjectTypeFunction: {
        miniv8::V8Function* ptr = (miniv8::V8Function*)vdata;
        ret = ptr;// new miniv8::V8FunctionTemplate(*ptr);
        break;
    }
    case miniv8::kObjectTypeObject: {
        miniv8::V8Object* ptr = (miniv8::V8Object*)vdata;
        ret = ptr;// new miniv8::V8FunctionTemplate(*ptr);
        break;
    }
    case miniv8::kObjectTypeValue: {
        miniv8::V8Value* ptr = (miniv8::V8Value*)vdata;
        ret = ptr;// new miniv8::V8FunctionTemplate(*ptr);
        break;
    }
    default:
        DebugBreak();
        break;
    }

    void** index = nullptr;
    miniv8::V8Head* head = (miniv8::V8Head*)ret;
    if (!head->m_isolatHandleScopeIndex) {
        index = iso->findHandleScopeEmptyIndex();
        head->m_isolatHandleScopeIndex = index;
        *index = v8::Utils::maskPtr(ret);
    } else {
        index = (void**)head->m_isolatHandleScopeIndex;
    }

//     char* output = (char*)malloc(0x100);
//     sprintf(output, "HandleScope::CreateHandle: %p %p\n", index, ret);
//     OutputDebugStringA(output);
//     free(output);

    return (v8::internal::Object **)index;
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
    JS_ToInt32(ctx, &res, lengthVal);

    return res;
}

unsigned int v8::ArrayBuffer::ByteLength(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

unsigned int v8::ArrayBufferView::ByteLength(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

unsigned int v8::ArrayBufferView::ByteOffset(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

unsigned int v8::CpuProfileNode::GetCallUid(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

unsigned int v8::CpuProfileNode::GetHitCount(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

unsigned int v8::CpuProfileNode::GetHitLineCount(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

unsigned int v8::CpuProfileNode::GetNodeId(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

unsigned int v8::HeapProfiler::GetHeapStats(v8::OutputStream*, __int64*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

unsigned int v8::HeapProfiler::GetObjectId(v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

unsigned int v8::Isolate::NumberOfHeapSpaces(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

unsigned int v8::TypedArray::Length(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return 0;
}

unsigned int v8::Uint32::Value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Uint32, miniv8::V8Value>(this);
    int32_t res = 0;
    int ret = JS_ToInt32(self->ctx(), &res, self->v(self));
    if (0 == ret)
        return res;
    return 0;
}

unsigned int v8::Value::Uint32Value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    uint32_t res = 0;
    int ret = JS_ToUint32(self->ctx(), &res, self->v(self));
    if (TRUE == ret)
        return res;
    return 0;
}

v8::ArrayBuffer::Contents v8::ArrayBuffer::Externalize(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::ArrayBuffer::Contents();
}

v8::ArrayBuffer::Contents v8::ArrayBuffer::GetContents(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::ArrayBuffer::Contents();
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

v8::Isolate* v8::Isolate::New(struct v8::Isolate::CreateParams const&)
{
    miniv8::V8Isolate* isolate = new miniv8::V8Isolate();
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

v8::Local<v8::ArrayBuffer> v8::ArrayBuffer::New(v8::Isolate*, unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::ArrayBuffer>();
}

v8::Local<v8::ArrayBuffer> v8::ArrayBuffer::New(v8::Isolate*, void*, unsigned int, v8::ArrayBufferCreationMode)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::ArrayBuffer>();
}

v8::Local<v8::ArrayBuffer> v8::ArrayBufferView::Buffer(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::ArrayBuffer>();
}

v8::Local<v8::Boolean> v8::Value::ToBoolean(v8::Isolate*) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Boolean>();
}

v8::Local<v8::Context> v8::Context::New(v8::Isolate* isolate, v8::ExtensionConfiguration*, v8::MaybeLocal<v8::ObjectTemplate> globalTemplate, v8::MaybeLocal<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    JSContext* ctx = JS_NewContext(iso->getRuntime());
    miniv8::V8Context* ret = new miniv8::V8Context(iso, ctx);

    JSValue global = JS_GetGlobalObject(ctx);
    miniv8::V8Object* globalObj = miniv8::V8Object::create(ret, global);

    miniv8::V8ObjectTemplate* globalTempl = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(*(globalTemplate.ToLocalChecked()));
    if (globalTempl) {
        globalTempl->newTemplateInstance(ret, globalObj, false);
        globalObj->setTemplId(globalTempl->getId());
    }
    // TODO: 没考虑m_instanceTemplate等情况

    return v8::Utils::convert<miniv8::V8Context, v8::Context>(ret);
}

v8::Local<v8::Object> v8::Context::Global(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);
    JSValue val = JS_GetGlobalObject(self->ctx());

    static int s_count = 0;
    if (s_count == 0) {
        s_count = 1;
        JS_SetPropertyStr(self->ctx(), val, "jsPrint", JS_NewCFunction(self->ctx(), jsPrint, "print", 0));
        JS_SetPropertyStr(self->ctx(), val, "jsTestNode", JS_NewCFunction(self->ctx(), jsTestNode, "jsTestNode", 0));
    }

    miniv8::V8Object* ret = miniv8::V8Object::create(self, val);
    return v8::Utils::convert<miniv8::V8Object, v8::Object>(ret);
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

v8::Local<v8::DataView> v8::DataView::New(v8::Local<v8::ArrayBuffer>, unsigned int, unsigned int)
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

v8::Local<v8::Float32Array> v8::Float32Array::New(v8::Local<v8::ArrayBuffer>, unsigned int, unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Float32Array>();
}

v8::Local<v8::Float64Array> v8::Float64Array::New(v8::Local<v8::ArrayBuffer>, unsigned int, unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Float64Array>();
}

v8::Local<v8::Function> v8::Function::New(v8::Isolate* isolate, v8::FunctionCallback callback, v8::Local<v8::Value> data, int length)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    void* dataPtr = static_cast<void*>(v8::External::Cast(*data));

    miniv8::V8Function* ret = new miniv8::V8Function(ctx, callback, dataPtr);
    return v8::Utils::convert<miniv8::V8Function, v8::Function>(ret);
}

v8::MaybeLocal<v8::Function> v8::Function::New(v8::Local<v8::Context> context, v8::FunctionCallback callback, v8::Local<v8::Value> data, int length, v8::ConstructorBehavior behavior)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* ctx = (miniv8::V8Context*)(*context);

    void* dataPtr = static_cast<void*>(v8::External::Cast(*data));
    miniv8::V8Function* ret = new miniv8::V8Function(ctx, callback, dataPtr);
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

        if (argVal->m_head.m_type > miniv8::V8ObjectType::kObjectTypeMax || argVal->m_head.m_type < miniv8::V8ObjectType::kObjectTypeMin)
            DebugBreak();

        JS_BOOL b = JS_IsNumber(argVal->v(argVal));

        argvWrap.push_back(argVal->v(argVal));
    }

//     static int s_count = 0;
//     char* output = (char*)malloc(0x100);
//     sprintf_s(output, 0x99, "v8::Function::Call: %d\n", s_count++);
//     OutputDebugStringA(output);
//     free(output);

    JSValue ret = JS_Call(self->ctx(), self->v(self), funcObj->v(funcObj), argc, 0 != argc ? &argvWrap[0] : nullptr);
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

    std::string name = self->getName();

    JSValue ret = JS_NewStringLen(self->ctx(), name.c_str(), name.size());
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
        miniv8::V8Value* argVal = (miniv8::V8Value*)(*(argv[i]));
        argvWrap.push_back(argVal->v(argVal));
    }

    JSValue v = self->v(self); // will call JS_NewCFunction，获取Function
    // will call v8::internal::FunctionCallbackArguments::onConstructorCallback
    JSValue ret = JS_CallConstructor(self->ctx(), v, argc, 0 != argc ? &argvWrap[0] : nullptr);

    miniv8::V8Object* inst = miniv8::V8Object::create(ctx, ret);
    inst->setTemplId(self->getTemplId());

    inst->m_internalFieldCount = self->m_internalFieldCount;

    miniv8::V8Template* templ = isolate->getTemplateById(self->getTemplId());
    if (templ->m_instanceTemplate) {
        templ->m_instanceTemplate->newTemplateInstance(ctx, inst, false);

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

    JSValue nameVal = JS_NewStringLen(self->ctx(), name.c_str(), name.size());
    v8::Local<v8::String> nameStr = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(self->v8Ctx(), nameVal));

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
    miniv8::V8Signature* signaturePtr = nullptr;
    if (!signature.IsEmpty())
        signaturePtr = v8::Utils::openHandle<v8::Signature, miniv8::V8Signature>(*signature);

    if (!data.IsEmpty()) {
        miniv8::V8External* dataVal = (miniv8::V8External*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*data); // TODO: free
        miniv8ReleaseAssert(dataVal->m_head.m_type == miniv8::kObjectTypeExternal, "v8::FunctionTemplate::New fail\n");

        self->m_userdata = dataVal->getUserdata();
    }
    self->m_constructor = callback ? callback : functionCallbackEmpty;
    self->m_argLength = length;
    self->m_signature = signaturePtr;

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

    miniv8::V8Template* objTempl = isolate->getTemplateById(obj->m_templId);
    miniv8ReleaseAssert(miniv8::V8ObjectType::kObjectTypeObject == obj->m_head.m_type, "v8::FunctionTemplate::HasInstance fail\n");
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
    DebugBreak();
    return v8::Local<v8::Function>();
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

void v8::FunctionTemplate::SetCallHandler(v8::FunctionCallback constructor, v8::Local<v8::Value> data, v8::experimental::FastAccessorBuilder* fastHandler)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8External* dataExternal = nullptr;
    if (!data.IsEmpty())
        dataExternal = (miniv8::V8External*)(v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*data));

    miniv8ReleaseAssert(!dataExternal || dataExternal->m_head.m_type == miniv8::kObjectTypeExternal, "FunctionTemplate::SetCallHandler data fail\n");
    //miniv8ReleaseAssert(data.IsEmpty(), "FunctionTemplate::SetCallHandler data fail\n");
    miniv8ReleaseAssert(!fastHandler, "FunctionTemplate::SetCallHandler fastHandler fail\n");

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

    std::map<std::string, miniv8::V8ObjectTemplate::Accessor>::const_iterator it = self->m_accessors.find(nameString);
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
    accessor.data = external->getUserdata();

    self->m_accessors.insert(std::make_pair(nameString, accessor));
}

void v8::ObjectTemplate::SetCallAsFunctionHandler(v8::FunctionCallback cb, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    //DebugBreak();
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

//     char* output = (char*)malloc(0x100);
//     sprintf(output, "v8::ObjectTemplate::SetInternalFieldCount: %p, %d\n", this, count);
//     OutputDebugStringA(output);
//     free(output);
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

void v8::ObjectTemplate::SetNamedPropertyHandler(void(__cdecl*)(v8::Local<v8::Name>, v8::PropertyCallbackInfo<v8::Value> const&), void(__cdecl*)(v8::Local<v8::Name>, v8::Local<v8::Value>, v8::PropertyCallbackInfo<v8::Value> const&), void(__cdecl*)(v8::Local<v8::Name>, v8::PropertyCallbackInfo<v8::Integer> const&), void(__cdecl*)(v8::Local<v8::Name>, v8::PropertyCallbackInfo<v8::Boolean> const&), void(__cdecl*)(v8::PropertyCallbackInfo<v8::Array> const&), v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
}

v8::MaybeLocal<v8::Object> v8::ObjectTemplate::NewInstance(v8::Local<v8::Context> context)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8ObjectTemplate* self = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);

    JSValue v = JS_NewObject(ctx->ctx());
    miniv8::V8Object* obj = new miniv8::V8Object(ctx, v);
    self->newTemplateInstance(ctx, obj, false);

    v8::Local<v8::Object> ret = v8::Utils::convert<miniv8::V8Object, v8::Object>(obj);
    return v8::MaybeLocal<v8::Object>(ret);
}

//////////////////////////////////////////////////////////////////////////

v8::Local<v8::Int16Array> v8::Int16Array::New(v8::Local<v8::ArrayBuffer>, unsigned int, unsigned int)                                                      
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Int16Array* obj = nullptr;// new miniv8::Int16Array();
    v8::Local<v8::Int16Array> ret = v8::Utils::convert<miniv8::V8Int16Array, v8::Int16Array>(obj);

    return ret;
}
                                                                         
v8::Local<v8::Int32> v8::Value::ToInt32(v8::Isolate*) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Int32* obj = nullptr;// new miniv8::V8Int32();
    v8::Local<v8::Int32> ret = v8::Utils::convert<miniv8::V8Int32, v8::Int32>(obj);
    return ret;
}

v8::Local<v8::Int32Array> v8::Int32Array::New(v8::Local<v8::ArrayBuffer>, unsigned int, unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Int32Array* obj = nullptr;// new miniv8::Int16Array();
    v8::Local<v8::Int32Array> ret = v8::Utils::convert<miniv8::V8Int32Array, v8::Int32Array>(obj);

    return ret;
}

v8::Local<v8::Int8Array> v8::Int8Array::New(v8::Local<v8::ArrayBuffer>, unsigned int, unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
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

v8::Local<v8::Integer> v8::Integer::NewFromUnsigned(v8::Isolate*, unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Integer* obj = nullptr;// new miniv8::Int16Array();
    v8::Local<v8::Integer> ret = v8::Utils::convert<miniv8::V8Integer, v8::Integer>(obj);
    return ret;
}

v8::Local<v8::Integer> v8::Value::ToInteger(v8::Isolate*) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Integer>();
}

// v8::Local<v8::Integer> v8::Value::ToInteger(void) const
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
//     return v8::Local<v8::Integer>();
// }

v8::Local<v8::Uint16Array> v8::Uint16Array::New(v8::Local<v8::ArrayBuffer>, unsigned int, unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Uint16Array>();
}

v8::Local<v8::Uint32Array> v8::Uint32Array::New(v8::Local<v8::ArrayBuffer>, unsigned int, unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Uint32Array>();
}

v8::Local<v8::Uint8Array> v8::Uint8Array::New(v8::Local<v8::ArrayBuffer>, unsigned int, unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Uint8Array>();
}

v8::Local<v8::Uint8ClampedArray> v8::Uint8ClampedArray::New(v8::Local<v8::ArrayBuffer>, unsigned int, unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Uint8ClampedArray>();
}

v8::Local<v8::Map> v8::Map::New(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Map>();
}

v8::Local<v8::Message> v8::Exception::CreateMessage(v8::Isolate*, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Message>();
}

v8::String::Value::Value(v8::Isolate*, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

// void v8::Isolate::AddGCPrologueCallback(v8::GCCallback callback, v8::GCType gc_type_filter)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
// }

void v8::Isolate::IsolateInBackgroundNotification()
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::Local<v8::Message> v8::TryCatch::Message(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Message>();
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

v8::Local<v8::Object> v8::Proxy::GetTarget(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Object>();
}

v8::Local<v8::Object> v8::Value::ToObject(v8::Isolate*) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Object>();
}

v8::Local<v8::Private> v8::Private::ForApi(v8::Isolate* isolate, v8::Local<v8::String> name)
{
    printEmptyFuncInfo(__FUNCTION__, true);

//     miniv8::V8String* nameStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*name);
//     JSValue val = nameStr->v(nameStr);
// 
//     v8::Local<v8::Context> context = isolate->GetCurrentContext();
//     miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);

    miniv8::V8Private* ret = new miniv8::V8Private(NULL, JS_UNDEFINED);
    return v8::Utils::convert<miniv8::V8Private, v8::Private>(ret);
}

v8::Local<v8::Promise> v8::Promise::Resolver::GetPromise(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Promise>();
}

v8::Local<v8::Script> v8::UnboundScript::BindToCurrentContext(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Script>();
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
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::Value::ToString(v8::Isolate*) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return v8::Local<v8::String>();
}

v8::Local<v8::Symbol> v8::Symbol::GetIterator(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    printDebug("v8::Symbol::GetIterator not impl!\n");
    miniv8::V8Symbol* self = new miniv8::V8Symbol("GetIterator");
    v8::Local<v8::Symbol> ret = v8::Utils::convert<miniv8::V8Symbol, v8::Symbol>(self);
    return ret;
}

v8::Local<v8::Symbol> v8::Symbol::GetToStringTag(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Symbol* self = new miniv8::V8Symbol("ToString");
    v8::Local<v8::Symbol> ret = v8::Utils::convert<miniv8::V8Symbol, v8::Symbol>(self);
    return ret;
}

v8::Local<v8::Symbol> v8::Symbol::GetUnscopables(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Symbol>();
}

v8::Local<v8::Symbol> v8::Symbol::New(v8::Isolate*, v8::Local<v8::String>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Symbol>();
}

v8::Local<v8::Symbol> v8::SymbolObject::ValueOf(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
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

v8::Local<v8::Value> v8::Exception::Error(v8::Local<v8::String> err)
{
    printEmptyFuncInfo(__FUNCTION__, true);
//     miniv8::V8String* errStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*err);
//     miniv8::V8Exception* exc = new miniv8::V8Exception(errStr->getStr());
//     return v8::Utils::convert<miniv8::V8Value, v8::Value>((miniv8::V8Value*)exc);
    return err;
}

v8::Local<v8::Value> v8::Exception::RangeError(v8::Local<v8::String> err)
{
    printEmptyFuncInfo(__FUNCTION__, true);
//     miniv8::V8String* errStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*err);
//     miniv8::V8Exception* exc = new miniv8::V8Exception(errStr->getStr());
//     return v8::Utils::convert<miniv8::V8Value, v8::Value>((miniv8::V8Value*)exc);
    return err;
}

v8::Local<v8::Value> v8::Exception::ReferenceError(v8::Local<v8::String> err)
{
    printEmptyFuncInfo(__FUNCTION__, true);
//     miniv8::V8String* errStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*err);
//     miniv8::V8Exception* exc = new miniv8::V8Exception(errStr->getStr());
//     return v8::Utils::convert<miniv8::V8Value, v8::Value>((miniv8::V8Value*)exc);
    return err;
}

v8::Local<v8::Value> v8::Exception::SyntaxError(v8::Local<v8::String> err)
{
    printEmptyFuncInfo(__FUNCTION__, true);
//     miniv8::V8String* errStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*err);
//     miniv8::V8Exception* exc = new miniv8::V8Exception(errStr->getStr());
//     return v8::Utils::convert<miniv8::V8Value, v8::Value>((miniv8::V8Value*)exc);
    return err;
}

v8::Local<v8::Value> v8::Exception::TypeError(v8::Local<v8::String> err)
{
    printEmptyFuncInfo(__FUNCTION__, true);
//     miniv8::V8String* errStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*err);
//     miniv8::V8Exception* exc = new miniv8::V8Exception(errStr->getStr());
//     return v8::Utils::convert<miniv8::V8Value, v8::Value>((miniv8::V8Value*)exc);
    return err;
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
    if (!val->IsString())
        v = JS_ThrowTypeError(ctx, "v8::Isolate::ThrowException!");
    else {
        miniv8::V8String* errStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(val.As<v8::String>()));
        v = JS_ThrowTypeError(ctx, errStr->getStr().c_str());
    }

    isolate->m_errorVal = v;
    return v8::Utils::convert<miniv8::V8Value, v8::Value>(new miniv8::V8Value(context, v));
}

v8::Local<v8::Value> v8::Message::GetScriptResourceName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::NativeWeakMap::Get(v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::NumberObject::New(v8::Isolate*, double)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Value>();
}


v8::Local<v8::Value> v8::Proxy::GetHandler(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::Script::Run(void)
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

v8::Local<v8::Value> v8::TryCatch::Exception(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::TryCatch::ReThrow(void)
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
    return ret;
}

v8::Maybe<bool> v8::Promise::Resolver::Reject(v8::Local<v8::Context>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<bool> ret = v8::Just(false);
    return ret;
}

v8::Maybe<bool> v8::Promise::Resolver::Resolve(v8::Local<v8::Context>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<bool> ret = v8::Just(false);
    return ret;
}

v8::Maybe<bool> v8::Value::BooleanValue(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<bool> ret = v8::Just(false);
    return ret;
}

v8::Maybe<double> v8::Value::NumberValue(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<double> ret = v8::Just(0.0);
    return ret;
}

v8::Maybe<int> v8::Message::GetEndColumn(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<int> ret = v8::Just(0);
    return ret;
}

v8::Maybe<int> v8::Message::GetLineNumber(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<int> ret = v8::Just(0);
    return ret;
}

v8::Maybe<int> v8::Message::GetStartColumn(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<int> ret = v8::Just(0);
    return ret;
}

v8::Maybe<int> v8::Value::Int32Value(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<int> ret = v8::Just(0);
    return ret;
}

v8::Maybe<unsigned int> v8::Value::Uint32Value(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::Maybe<unsigned int> ret = v8::Just<unsigned int>(0);
    return ret;
}

v8::MaybeLocal<v8::Boolean> v8::Value::ToBoolean(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<Boolean> ret;
    return ret;
}

v8::MaybeLocal<v8::Integer> v8::Value::ToInteger(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Integer> ret;
    DebugBreak();
    return ret;
}

v8::MaybeLocal<v8::Map> v8::Map::Set(v8::Local<v8::Context>, v8::Local<v8::Value>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Map> ret;
    return ret;
}

v8::MaybeLocal<v8::Number> v8::Value::ToNumber(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Number* num = nullptr;

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kObjectTypeNumber)
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
    if (self->m_head.m_type == miniv8::kObjectTypeObject || JS_IsObject(v))
        ret = v8::Utils::convert<miniv8::V8Object, v8::Object>(miniv8::V8Object::create(ctx, v));
    else
        ret = v8::Object::New(isolate);

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

v8::MaybeLocal<v8::Script> v8::Script::Compile(v8::Local<v8::Context>, v8::Local<v8::String>, v8::ScriptOrigin*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Script> ret;
    return ret;
}

v8::MaybeLocal<v8::Script> v8::ScriptCompiler::Compile(v8::Local<v8::Context> context, v8::ScriptCompiler::Source* source, v8::ScriptCompiler::CompileOptions)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8String* sourceStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(source->source_string));
    std::string src = sourceStr->getStr();
    std::string name;

    if (!source->resource_name.IsEmpty() && source->resource_name->IsString()) {
        v8::MaybeLocal<v8::String> sourceName = source->resource_name->ToString(context);
        miniv8::V8String* sourceNameStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(sourceName.ToLocalChecked()));
        name = sourceNameStr->getStr();
    }

    miniv8::V8Script* script = new miniv8::V8Script();
    script->setSource(src);
    script->setSourceName(name);
    v8::Local<v8::Script> ret = v8::Utils::convert<miniv8::V8Script, v8::Script>(script);
    return ret;
}

v8::MaybeLocal<v8::Script> v8::ScriptCompiler::Compile(v8::Local<v8::Context>, v8::ScriptCompiler::StreamedSource*, v8::Local<v8::String>, v8::ScriptOrigin const&)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Script> ret;
    return ret;
}

v8::MaybeLocal<v8::Value> v8::Script::Run(v8::Local<v8::Context> context)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Script* self = v8::Utils::openHandle<v8::Script, miniv8::V8Script>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);

    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8::Isolate::GetCurrent();
    
    // TODO: 返回值，可能是已经存在的dom之类的
    isolate->enterContext(ctx);
    JSValue ret = JS_Eval(ctx->ctx(), self->getSource().c_str(), self->getSource().size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
    isolate->exitContext();

    if (JS_IsException(ret))
        printWhenError(ctx->ctx());

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
    if (miniv8::kObjectTypeString == self->m_head.m_type) {
        miniv8::V8String* str = (miniv8::V8String*)self;
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    } else if (miniv8::kObjectTypeValue == self->m_head.m_type) {
        
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

v8::MaybeLocal<v8::Uint32> v8::Value::ToArrayIndex(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Uint32> ret;
    return ret;
}

v8::MaybeLocal<v8::Uint32> v8::Value::ToUint32(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Uint32> ret;
    return ret;
}

v8::MaybeLocal<v8::UnboundScript> v8::ScriptCompiler::CompileUnboundScript(v8::Isolate*, v8::ScriptCompiler::Source*, v8::ScriptCompiler::CompileOptions)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::UnboundScript> ret;
    return ret;
}

v8::MaybeLocal<v8::Value> v8::Date::New(v8::Local<v8::Context>, double)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Value> ret;
    return ret;
}

v8::MaybeLocal<v8::Value> v8::JSON::Parse(v8::Isolate*, v8::Local<v8::String>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Value> ret;
    return ret;
}

v8::MaybeLocal<v8::Value> v8::Map::Get(v8::Local<v8::Context>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    v8::MaybeLocal<v8::Value> ret;
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

v8::TryCatch::TryCatch(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::TryCatch::TryCatch(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

v8::TryCatch::~TryCatch(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
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

void v8::ArrayBuffer::Neuter(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Context::AllowCodeGenerationFromStrings(bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Context::DetachGlobal(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
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

void v8::HeapProfiler::SetRetainedObjectInfo(v8::UniqueId, v8::RetainedObjectInfo*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

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

void v8::Isolate::GetCodeRange(void**, unsigned int*)
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

    isolate->m_microtasks.insert(std::make_pair(microtask, data));
}

void v8::Isolate::RunMicrotasks(void)
{
    //printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;

    for (std::map<void*, void*>::const_iterator it = isolate->m_microtasks.begin(); it != isolate->m_microtasks.end(); ++it) {
        v8::MicrotaskCallback microtask = (v8::MicrotaskCallback)it->first;
        microtask(it->second);
    }
    isolate->m_microtasks.clear();

    JSContext* pctx;
    int ret = JS_ExecutePendingJob(isolate->m_runtime, &pctx);
    ret = ret;
}

void v8::Isolate::SetAllowCodeGenerationFromStringsCallback(bool(__cdecl*)(v8::Local<v8::Context>, v8::Local<v8::String>))
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

// void v8::Isolate::SetObjectGroupId<v8::Object>(v8::Persistent<v8::Object, v8::NonCopyablePersistentTraits<v8::Object> > const&, v8::UniqueId)
// {
//     printEmptyFuncInfo(__FUNCTION__, true);
// }

void v8::Isolate::SetPromiseRejectCallback(void(__cdecl*)(v8::PromiseRejectMessage))
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::SetStackLimit(unsigned int)
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

void v8::Isolate::VisitHandlesWithClassIds(v8::PersistentHandleVisitor*)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::Isolate::VisitWeakHandles(v8::PersistentHandleVisitor*)
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

void v8::TryCatch::Reset(void)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::TryCatch::SetVerbose(bool)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::V8::AddGCEpilogueCallback(void(__cdecl*)(v8::GCType, v8::GCCallbackFlags), v8::GCType)
{
    printEmptyFuncInfo(__FUNCTION__, true);
}

void v8::V8::AddGCPrologueCallback(void(__cdecl*)(v8::GCType, v8::GCCallbackFlags), v8::GCType)
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

void v8::V8::SetEntropySource(bool(__cdecl*)(unsigned char*, unsigned int))
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

v8::MaybeLocal<v8::Value> v8::Debug::GetMirror(v8::Local<v8::Context>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return v8::MaybeLocal<v8::Value>();
}

bool v8::CpuProfileNode::GetLineTicks(struct v8::CpuProfileNode::LineTick*, unsigned int) const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    return false;
}

int v8::internal::Internals::GetInstanceType(const v8::internal::Object* obj)
{
//     typedef internal::Object O;
//     O* map = ReadField<O*>(obj, kHeapObjectMapOffset);
//     // Map::InstanceType is defined so that it will always be loaded into
//     // the LS 8 bits of one 16-bit word, regardless of endianess.
//     return ReadField<uint16_t>(map, kMapInstanceTypeAndBitFieldOffset) & 0xff;
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return 0;
}

int v8::internal::Internals::GetOddballKind(const v8::internal::Object* obj)
{
//     typedef internal::Object O;
//     return SmiValue(ReadField<O*>(obj, kOddballKindOffset));
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return 0;
}

bool v8::internal::Internals::IsExternalTwoByteString(int instance_type)
{
    int representation = (instance_type & kFullStringRepresentationMask);
    return representation == kExternalTwoByteRepresentationTag;
}

uint8_t v8::internal::Internals::GetNodeFlag(v8::internal::Object** obj, int shift)
{
//     uint8_t* addr = reinterpret_cast<uint8_t*>(obj) + kNodeFlagsOffset;
//     return *addr & static_cast<uint8_t>(1U << shift);
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return 0;
}

void v8::internal::Internals::UpdateNodeFlag(v8::internal::Object** obj, bool value, int shift)
{
//     uint8_t* addr = reinterpret_cast<uint8_t*>(obj) + kNodeFlagsOffset;
//     uint8_t mask = static_cast<uint8_t>(1U << shift);
//     *addr = static_cast<uint8_t>((*addr & ~mask) | (value << shift));
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8Data* self = v8::Utils::openHandle<v8::Value, miniv8::V8Data>((const v8::Value*)obj);
    uint8_t mask = static_cast<uint8_t>(1U << shift);
    self->m_nodeFlag |= static_cast<uint8_t>((self->m_nodeFlag & ~mask) | (value << shift));
}

uint8_t v8::internal::Internals::GetNodeState(v8::internal::Object** obj)
{
//     uint8_t* addr = reinterpret_cast<uint8_t*>(obj) + kNodeFlagsOffset;
//     return *addr & kNodeStateMask;
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Data* self = v8::Utils::openHandle<v8::Value, miniv8::V8Data>((const v8::Value*)obj);
    return self->m_nodeState & kNodeStateMask;
}

void v8::internal::Internals::UpdateNodeState(v8::internal::Object** obj, uint8_t value)
{
//     uint8_t* addr = reinterpret_cast<uint8_t*>(obj) + kNodeFlagsOffset;
//     *addr = static_cast<uint8_t>((*addr & ~kNodeStateMask) | value);
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Data* self = v8::Utils::openHandle<v8::Value, miniv8::V8Data>((const v8::Value*)obj);
    self->m_nodeState = static_cast<uint8_t>((self->m_nodeState & ~kNodeStateMask) | value);
}

v8::Local<v8::Primitive> v8::Undefined(Isolate* isolate)
{
    typedef internal::Object* S;
    typedef internal::Internals I;
    I::CheckInitialized(isolate);
    S* slot = I::GetRoot(isolate, I::kUndefinedValueRootIndex);
    return Local<Primitive>(reinterpret_cast<Primitive*>(slot));
    
//     v8::Local<v8::Primitive> ret = v8::Utils::convert<miniv8::V8Data, v8::Primitive>(new miniv8::V8Data(nullptr, JS_UNDEFINED));
//     return ret;
}

v8::Local<v8::Primitive> v8::Null(Isolate* isolate)
{
    typedef internal::Object* S;
    typedef internal::Internals I;
    I::CheckInitialized(isolate);
    S* slot = I::GetRoot(isolate, I::kNullValueRootIndex);
    return Local<Primitive>(reinterpret_cast<Primitive*>(slot));
//     v8::Local<v8::Primitive> ret = v8::Utils::convert<miniv8::V8Data, v8::Primitive>(new miniv8::V8Data(nullptr, JS_NULL));
//     return ret;
}

v8::Local<v8::Boolean> v8::True(v8::Isolate* isolate)
{
    typedef internal::Object* S;
    typedef internal::Internals I;
    I::CheckInitialized(isolate);
    S* slot = I::GetRoot(isolate, I::kTrueValueRootIndex);
    return Local<Boolean>(reinterpret_cast<Boolean*>(slot));
//     v8::Local<v8::Boolean> ret = v8::Utils::convert<miniv8::V8Data, v8::Boolean>(new miniv8::V8Data(nullptr, JS_TRUE));
//     return ret;
}

v8::Local<v8::Boolean> v8::False(v8::Isolate* isolate)
{
    typedef internal::Object* S;
    typedef internal::Internals I;
    I::CheckInitialized(isolate);
    S* slot = I::GetRoot(isolate, I::kFalseValueRootIndex);
    return Local<Boolean>(reinterpret_cast<Boolean*>(slot));

//     v8::Local<v8::Boolean> ret = v8::Utils::convert<miniv8::V8Data, v8::Boolean>(new miniv8::V8Data(nullptr, JS_FALSE));
//     return ret;
}

v8::Local<v8::String> v8::String::Empty(Isolate* isolate)
{
//     typedef internal::Object* S;
//     typedef internal::Internals I;
//     I::CheckInitialized(isolate);
//     S* slot = I::GetRoot(isolate, I::kEmptyStringRootIndex);
//     return Local<String>(reinterpret_cast<String*>(slot));

    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(""));
    return ret;
}

bool v8::Value::IsUndefined() const
{
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    JSValue v = miniv8::V8Data::V8Data_v(self);
    return !!JS_IsUndefined(v);
}

bool v8::Value::QuickIsUndefined() const
{
    DebugBreak();
    return false;
}

bool v8::Value::IsNull() const
{
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    JSValue v = miniv8::V8Data::V8Data_v(self);
    return v == JS_NULL;
}

bool v8::Value::QuickIsNull() const
{
    DebugBreak();
    return false;
}

bool v8::Value::IsString() const
{
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);

    if (miniv8::kObjectTypeString == self->m_head.m_type)
        return true;
    JSValue v = self->v(self);
    return JS_IsString(v) != 0;
}

bool v8::Value::QuickIsString() const
{
    printEmptyFuncInfo(__FUNCTION__, true);
    DebugBreak();
    return false;
}

void v8::Context::SetAlignedPointerInEmbedderData(int index, void* data)
{
    printEmptyFuncInfo(__FUNCTION__, true);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);

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

}  // namespace v8
