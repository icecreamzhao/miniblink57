
#define _CRT_SECURE_NO_WARNINGS 1

#include "MiniV8Api.h"
#include <windows.h>

#pragma optimize("", off)
#pragma clang optimize off

namespace miniv8 {
static JSValue onCFunctionCallback(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv, void* userdata);

static JSValue getReturnVal(JSContext* ctx, void* cehckPtr, void** retVal)
{
    if (cehckPtr == *retVal)
        return JS_UNDEFINED; // TODO: 不知道这样判断行不行

    // 如果*retVal的低位是1，说明是SMI：https://v8.dev/blog/pointer-compression
    if (V8Object::IsSmi((void*)(*retVal)) && v8::internal::Internals::IsValidSmi((intptr_t)(*retVal))) {
        int intV = v8::internal::Internals::SmiValue((const v8::internal::Object*)(*retVal));
        return JS_NewInt32(ctx, intV);
    }

    V8Value* ret = v8::Utils::openHandle<v8::Value, V8Value>((v8::Value*)(retVal));
    JSValue v = ret->v(ret); // TODO:Free
    JS_DupValue(ctx, v); // TODO: 需要增加引用吗？
    return v;
}

}

namespace v8 {

class MacroAssembler { // 为了能访问v8::PropertyCallbackInfo的私有变量，不得不借用MacroAssembler
public:
    static JSValue objectTemplateGetter(JSContext* ctx, JSValueConst thisVal, void* userdata);
    static JSValue objectTemplateSetter(JSContext* ctx, JSValueConst thisVal, JSValueConst val, void* userdata);

    static JSValue onIndexHandle(JSContext* ctx, JSValueConst thisVal, int32_t index, void* userdata);
    static JSValue onNamePropertyGet(JSContext* ctx, JSValueConst this_val, JSAtom prop, void* userdata);
    static JS_BOOL onNamePropertySet(JSContext* ctx, JSValueConst this_val, JSAtom prop, JSValueConst val, void* userdata);
    static int onNamePropertyQuery(JSContext* ctx, JSValueConst this_val, JSAtom prop, void* userdata);
    
    void* stub;
};

namespace internal {

class FunctionCallbackArguments { // 为了能访问v8::FunctionCallbackInfo的私有变量，不得不借用FunctionCallbackArguments
public:
    static JSValue objectTemplateFuncGetter(JSContext* ctx, JSValueConst thisVal, void* userdata);
    static JSValue objectTemplateFuncSetter(JSContext* ctx, JSValueConst thisVal, JSValueConst val, void* userdata);
    static JSValue onConstructorCallback(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv, void* userdata);
    static JSValue onCFunctionCallback(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv, void* userdata);

    static void createFunctionCallbackInfo(
        miniv8::V8Context* context,
        miniv8::V8Object* thisValV8,
        std::vector<void*>* argValue,
        void** implicitArgs,
        miniv8::V8External* external,
        miniv8::FunctionCallbackInfoWrap* functionCallbackInfoWrap,
        int argc,
        JSValueConst* argv
    );

    void* stub;
};

JSValue FunctionCallbackArguments::objectTemplateFuncGetter(JSContext* ctx, JSValueConst thisVal, void* userdata)
{
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Template::Accessor* accessor = (miniv8::V8Template::Accessor*)userdata;
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    miniv8::V8Isolate::AutoEnterExitContext autoEnterExitContext(context);

    if (JS_IsUndefined(thisVal))
        thisVal = JS_GetGlobalObject(ctx); // 直接调用alert，thisVal可能为undefined

    const int argc = 0;
    std::vector<void*> argValue;
    argValue.resize(argc + 2);

    argValue[0] = v8::Utils::maskPtr(miniv8::V8Object::create(context, thisVal));
    argValue[0 + 1] = argValue[0]; // 如果argc是0的话，v8会在FunctionCallbackInfo<T>::This()里取到这个地址

    void* returnValue[4] = { 0 };
    returnValue[1] = isolate;

    miniv8::V8External external(accessor->data);

    void* implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kHolderIndex] = argValue[argc]; // kHolderIndex
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kIsolateIndex] = isolate; // kIsolateIndex
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kReturnValueDefaultValueIndex] = nullptr; // kReturnValueDefaultValueIndex
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kReturnValueIndex] = nullptr; // &returnValue[2]; //kReturnValueIndex
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kDataIndex] = v8::Utils::maskPtr(&external); // kDataIndex
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kCalleeIndex] = argValue[argc]; // kCalleeIndex
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kContextSaveIndex] = nullptr; // kContextSaveIndex
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kNewTargetIndex] = nullptr; // kNewTargetIndex

    miniv8::FunctionCallbackInfoWrap functionCallbackInfoWrap;
    functionCallbackInfoWrap.implicitArgs = implicitArgs;
    functionCallbackInfoWrap.values = &argValue[argc ? argc - 1 : 0];
    functionCallbackInfoWrap.length = argc;

    void** retVal = (void**)&implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;

    v8::FunctionCallbackInfo<v8::Value>* functionCallbackInfoWrapV8 = (v8::FunctionCallbackInfo<v8::Value>*) & functionCallbackInfoWrap;
    accessor->getterFunc(*functionCallbackInfoWrapV8);

    JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);
    return v;
}

JSValue FunctionCallbackArguments::objectTemplateFuncSetter(JSContext* ctx, JSValueConst thisVal, JSValueConst val, void* userdata)
{
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Isolate::AutoEnterExitContext autoEnterExitContext(context);
    miniv8::V8Template::Accessor* accessor = (miniv8::V8Template::Accessor*)userdata;
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    miniv8::V8Object* thisValV8 = nullptr;
    void* thisValPtr = nullptr;

    if (JS_IsUndefined(thisVal))
        thisVal = JS_GetGlobalObject(ctx); // 直接调用alert，thisVal可能为undefined

    const int argc = 1;
    std::vector<void*> argValue;
    argValue.resize(argc + 2);

    miniv8::V8Value* v = miniv8::V8Value::create(context, val); // TODO:是不是也要用V8Object::create？
    argValue[0] = v8::Utils::maskPtr(v);

    argValue[argc] = v8::Utils::maskPtr(miniv8::V8Object::create(context, thisVal));
    argValue[argc + 1] = argValue[argc]; // 如果argc是0的话，v8会在FunctionCallbackInfo<T>::This()里取到这个地址

    void* returnValue[4] = { 0 };
    returnValue[1] = isolate;

    miniv8::V8External external(accessor->data);

    void* implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kHolderIndex] = argValue[argc]; // kHolderIndex
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kIsolateIndex] = isolate; // kIsolateIndex
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kReturnValueDefaultValueIndex] = nullptr; // kReturnValueDefaultValueIndex
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kReturnValueIndex] = &returnValue; // &returnValue[2]; //kReturnValueIndex
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kDataIndex] = v8::Utils::maskPtr(&external); // kDataIndex
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kCalleeIndex] = argValue[argc]; // kCalleeIndex
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kContextSaveIndex] = thisValV8; // kContextSaveIndex
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kNewTargetIndex] = thisValPtr; // kNewTargetIndex

    miniv8::FunctionCallbackInfoWrap functionCallbackInfoWrap;
    functionCallbackInfoWrap.implicitArgs = implicitArgs;
    functionCallbackInfoWrap.values = &argValue[argc ? argc - 1 : 0];
    functionCallbackInfoWrap.length = argc;

    v8::FunctionCallbackInfo<v8::Value>* functionCallbackInfoWrapV8 = (v8::FunctionCallbackInfo<v8::Value>*) & functionCallbackInfoWrap;
    accessor->setterFunc(*functionCallbackInfoWrapV8);
    return JS_UNDEFINED;
}

static JSValue onToStringOfFuncInst(JSContext* ctx, JSValueConst funcVal, int argc, JSValueConst* argv, void* userdata)
{
    miniv8::V8Function* self = (miniv8::V8Function*)userdata;
    std::string name = "[object ";
    name += self->getName();
    name += "]";
    return JS_NewString(ctx, name.c_str());
}

void FunctionCallbackArguments::createFunctionCallbackInfo(
    miniv8::V8Context* context,
    miniv8::V8Object* thisValV8,
    std::vector<void*>* argValue, 
    void** implicitArgs,
    miniv8::V8External* external,
    miniv8::FunctionCallbackInfoWrap* functionCallbackInfoWrap,
    int argc, 
    JSValueConst* argv
    )
{
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    void* thisValPtr = v8::Utils::maskPtr(thisValV8);
    void* argValuePtr = argValue->data();

    // if argc == 3, argValue[3] == this, argValue[2] = arg[0], argValue[1] = arg[1], argValue[0] = arg[2]
    // if argc == 1, argValue[1] == this, argValue[0] = arg[0]
    // if argc == 0, argValue[1] == this, argValue[0] == null
    argValue->resize(argc + 2);
    (*argValue)[0] = thisValPtr;
    (*argValue)[1] = thisValPtr;
    (*argValue)[argc] = thisValPtr; // 如果argc是0的话，v8会在FunctionCallbackInfo<T>::This()里取到这个地址

    for (int i = 0; i < argc; ++i) {
        miniv8::V8Value* v = miniv8::V8Value::create(context, argv[i]);
        (*argValue)[argc - i - 1] = v8::Utils::maskPtr(v);
    }

    void* returnValue[4] = { 0 };
    returnValue[1] = isolate;

    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kHolderIndex] = thisValPtr;
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kIsolateIndex] = isolate;
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kReturnValueDefaultValueIndex] = nullptr;
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kReturnValueIndex] = &returnValue; // &returnValue[2]; //kReturnValueIndex
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kDataIndex] = v8::Utils::maskPtr(external);
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kCalleeIndex] = thisValPtr;
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kContextSaveIndex] = thisValV8;
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kNewTargetIndex] = thisValPtr;

    functionCallbackInfoWrap->implicitArgs = implicitArgs;

    // values[1] == this, values[0] == arg[0], values[-1] == arg[1];
    int pos = argc - 1 > 0 ? argc - 1 : 0;
    functionCallbackInfoWrap->values = &((*argValue)[pos]);
    functionCallbackInfoWrap->length = argc;
}

JSValue FunctionCallbackArguments::onConstructorCallback(JSContext* ctx, JSValueConst funcVal, int argc, JSValueConst* argv, void* userdata)
{
    miniv8::V8Function* self = (miniv8::V8Function*)userdata;
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();

    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Isolate::AutoEnterExitContext autoEnterExitContext(context);

    miniv8ReleaseAssert(!!context, "onConstructorCallback fail\n");
    miniv8::V8Object* func = miniv8::V8Object::create(context, self->v(self)); // 这个应该是Function的指针
    miniv8ReleaseAssert(self->v(self) == funcVal, "onConstructorCallback fail\n");

    if (0 == func->m_internalFieldCount)
        func->m_internalFieldCount = self->m_internalFieldCount;

    JSValue proto = JS_GetPropertyStr(ctx, funcVal, "prototype");
    JSValue newInst = JS_NewObjectProto(ctx, proto); // 创建这个function的实例，并且手动设置原型链。不然quickjs不会设置原型链

    miniv8::V8Object* thisValV8 = miniv8::V8Object::create(context, newInst);
    thisValV8->m_internalFieldCount = func->m_internalFieldCount;
    miniv8::V8Data dataV8(context, self->v(self));

    std::vector<void*> argValue;
    void* implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    miniv8::V8External external(self->m_data);
    miniv8::FunctionCallbackInfoWrap wrap;
    createFunctionCallbackInfo(context, thisValV8, &argValue, implicitArgs, &external, &wrap, argc, argv);

    v8::FunctionCallbackInfo<v8::Value>* wrapV8 = (v8::FunctionCallbackInfo<v8::Value>*)&wrap;
    void** retVal = (void**)&implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;

    isolate->clearErr(ctx);
    self->m_callback(*wrapV8); // to V8FunctionTemplate::onCall
    if (isolate->hasErr())
        return isolate->getErrAndClear();

    JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);

    JSValue toStringFuncVal = JS_NewCFunction2(ctx, onToStringOfFuncInst, NULL, 0, JS_CFUNC_generic, 0, self);
    JSAtom toStringAtom = JS_NewAtom(ctx, "toString");
    JS_SetProperty(ctx, v, /*JS_ATOM_toString*/toStringAtom, toStringFuncVal);

    JS_DupValue(ctx, v); // TODO: 需要增加引用吗？

    miniv8::V8Value* retV = miniv8::V8Value::create(context, v);
    if (-1 == retV->getTemplId())
        retV->setTemplId(self->getTemplId());
    else
        miniv8ReleaseAssert(retV->getTemplId() == self->getTemplId(), "onConstructorCallback fail\n");

    return v;
}

} // internal

JSValue MacroAssembler::objectTemplateGetter(JSContext* ctx, JSValueConst thisVal, void* userdata)
{
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Template::Accessor* accessor = (miniv8::V8Template::Accessor*)userdata;
    miniv8::V8Isolate::AutoEnterExitContext autoEnterExitContext(context);

    miniv8::V8String* name = new miniv8::V8String(accessor->name);
    name->ensureQjsVal(context);
    v8::Local<v8::Name> propertyName = (v8::Utils::convert<miniv8::V8String, v8::String>(name));

    miniv8::V8Object* thisValue = miniv8::V8Object::create(context, thisVal);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    void* returnValue[4] = { 0 };
    returnValue[0] = isolate;

    miniv8::V8External external(accessor->data);

    void* args[v8::PropertyCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    args[v8::PropertyCallbackInfo<v8::Value>::kShouldThrowOnErrorIndex] = nullptr;
    args[v8::PropertyCallbackInfo<v8::Value>::kHolderIndex] = v8::Utils::maskPtr(thisValue); // kHolderIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kIsolateIndex] = isolate; // kIsolateIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueDefaultValueIndex] = nullptr; // kReturnValueDefaultValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex] = nullptr;// &returnValue[2]; //kReturnValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kDataIndex] = v8::Utils::maskPtr(&external); // kDataIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kThisIndex] = v8::Utils::maskPtr(thisValue); // kThisIndex

    MacroAssembler infoStub; // 搞个假的，其实只是为了地址占位
    infoStub.stub = args;
    v8::PropertyCallbackInfo<v8::Value>* info = (v8::PropertyCallbackInfo<v8::Value>*)&infoStub;

    void** retVal = &args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;

    accessor->nameGetter(propertyName, *info);
    JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);
    return v;
//     if (nullptr == *retVal)
//         return JS_UNDEFINED;
//     if (miniv8::V8Object::IsSmi((void*)(*retVal)) && v8::internal::Internals::IsValidSmi((intptr_t)(*retVal))) {
//         int intV = v8::internal::Internals::SmiValue((const v8::internal::Object*)(*retVal));
//         return JS_NewInt32(context->ctx(), intV);
//     }
//     miniv8::V8Value* ret = v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)(retVal));
//     JSValue v = ret->v(ret); // TODO:Free
//     JS_DupValue(ctx, v);
//     return v;
}

JSValue MacroAssembler::objectTemplateSetter(JSContext* ctx, JSValueConst thisVal, JSValueConst val, void* userdata)
{
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Isolate::AutoEnterExitContext autoEnterExitContext(context);
    miniv8::V8Template::Accessor* accessor = (miniv8::V8Template::Accessor*)userdata;

    miniv8::V8String* name = new miniv8::V8String(accessor->name);
    name->ensureQjsVal(context);
    v8::Local<v8::Name> propertyName = (v8::Utils::convert<miniv8::V8String, v8::String>(name));

    miniv8::V8Object* thisValue = miniv8::V8Object::create(context, thisVal);

    miniv8::V8Value* value = miniv8::V8Value::create(context, val);// TODO:
    v8::Local<v8::Value> valueV8 = (v8::Utils::convert<miniv8::V8Value, v8::Value>(value)); 

    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    void* returnValue[4] = { 0 };
    returnValue[0] = isolate;

    miniv8::V8External external(accessor->data);

    void* args[v8::PropertyCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    args[v8::PropertyCallbackInfo<v8::Value>::kShouldThrowOnErrorIndex] = nullptr;
    args[v8::PropertyCallbackInfo<v8::Value>::kHolderIndex] = v8::Utils::maskPtr(thisValue); // kHolderIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kIsolateIndex] = isolate; // kIsolateIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueDefaultValueIndex] = nullptr; // kReturnValueDefaultValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex] = nullptr; // &returnValue[2]; //kReturnValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kDataIndex] = v8::Utils::maskPtr(&external); // kDataIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kThisIndex] = v8::Utils::maskPtr(thisValue); // kThisIndex

    MacroAssembler infoStub; // 搞个假的，其实只是为了地址占位
    infoStub.stub = args;
    v8::PropertyCallbackInfo<void>* info = (v8::PropertyCallbackInfo<void>*) & infoStub;
    void** retVal = &args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;
    accessor->nameSetter(propertyName, valueV8, *info);
    JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);
    return v;
}

int v8::MacroAssembler::onNamePropertyQuery(JSContext* ctx, JSValueConst thisVal, JSAtom prop, void* userdata)
{
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Isolate::AutoEnterExitContext autoEnterExitContext(context);
    v8::NamedPropertyHandlerConfiguration* cfg = (v8::NamedPropertyHandlerConfiguration*)userdata;
    miniv8::V8Object* thisValue = miniv8::V8Object::create(context, thisVal);
    miniv8::V8External* external = (miniv8::V8External*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*(cfg->data));
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    if (0)
        JS_PrintStack(ctx);

    const char* nameStr = JS_AtomToCString(ctx, prop);
    miniv8::V8String* name = new miniv8::V8String(std::string(nameStr));
    JS_FreeCString(ctx, nameStr);
    v8::Local<v8::String> nameV8 = v8::Utils::convert<miniv8::V8String, v8::String>(name);

    void* args[v8::PropertyCallbackInfo<v8::Integer>::kArgsLength] = { 0 };
    args[v8::PropertyCallbackInfo<v8::Integer>::kShouldThrowOnErrorIndex] = nullptr;
    args[v8::PropertyCallbackInfo<v8::Integer>::kHolderIndex] = v8::Utils::maskPtr(thisValue); // kHolderIndex
    args[v8::PropertyCallbackInfo<v8::Integer>::kIsolateIndex] = isolate; // kIsolateIndex
    args[v8::PropertyCallbackInfo<v8::Integer>::kReturnValueDefaultValueIndex] = nullptr; // kReturnValueDefaultValueIndex
    args[v8::PropertyCallbackInfo<v8::Integer>::kReturnValueIndex] = nullptr; // &returnValue[2]; //kReturnValueIndex
    args[v8::PropertyCallbackInfo<v8::Integer>::kDataIndex] = v8::Utils::maskPtr(external); // kDataIndex
    args[v8::PropertyCallbackInfo<v8::Integer>::kThisIndex] = v8::Utils::maskPtr(thisValue); // kThisIndex

    MacroAssembler infoStub; // 搞个假的，其实只是为了地址占位
    infoStub.stub = args;
    v8::PropertyCallbackInfo<v8::Integer>* info = (v8::PropertyCallbackInfo<v8::Integer>*)(&infoStub);
    void** retVal = &args[v8::PropertyCallbackInfo<v8::Integer>::kReturnValueIndex];
    *retVal = &retVal;

    cfg->query(nameV8, *info);
    if (&retVal == *retVal)
        return 0;

    if (miniv8::V8Object::IsSmi((void*)(*retVal)) && v8::internal::Internals::IsValidSmi((intptr_t)(*retVal))) {
        int intV = v8::internal::Internals::SmiValue((const v8::internal::Object*)(*retVal));
        if (0 == intV)
            return 1;
    }

    return -1;
}

JS_BOOL v8::MacroAssembler::onNamePropertySet(JSContext* ctx, JSValueConst thisVal, JSAtom prop, JSValueConst val, void* userdata)
{
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Isolate::AutoEnterExitContext autoEnterExitContext(context);
    v8::NamedPropertyHandlerConfiguration* cfg = (v8::NamedPropertyHandlerConfiguration*)userdata;
    miniv8::V8Object* thisValue = miniv8::V8Object::create(context, thisVal);
    miniv8::V8External* external = (miniv8::V8External*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*(cfg->data));
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    miniv8::V8Value* value = miniv8::V8Value::create(context, val);
    v8::Local<v8::Value> valueV8 = v8::Utils::convert<miniv8::V8Value, v8::Value>(value);

    if (0)
        JS_PrintStack(ctx);

    const char* nameStr = JS_AtomToCString(ctx, prop);
    miniv8::V8String* name = new miniv8::V8String(std::string(nameStr));
    JS_FreeCString(ctx, nameStr);
    v8::Local<v8::String> nameV8 = v8::Utils::convert<miniv8::V8String, v8::String>(name);

    void* args[v8::PropertyCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    args[v8::PropertyCallbackInfo<v8::Value>::kShouldThrowOnErrorIndex] = nullptr;
    args[v8::PropertyCallbackInfo<v8::Value>::kHolderIndex] = v8::Utils::maskPtr(thisValue); // kHolderIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kIsolateIndex] = isolate; // kIsolateIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueDefaultValueIndex] = nullptr; // kReturnValueDefaultValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex] = nullptr; // &returnValue[2]; //kReturnValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kDataIndex] = v8::Utils::maskPtr(external); // kDataIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kThisIndex] = v8::Utils::maskPtr(thisValue); // kThisIndex

    MacroAssembler infoStub; // 搞个假的，其实只是为了地址占位
    infoStub.stub = args;
    v8::PropertyCallbackInfo<v8::Value>* info = (v8::PropertyCallbackInfo<v8::Value>*)(&infoStub);
    void** retVal = &args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;

    cfg->setter(nameV8, valueV8, *info);
    JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);
    if (JS_UNDEFINED == v)
        return FALSE;
    return TRUE;
}

JSValue v8::MacroAssembler::onNamePropertyGet(JSContext* ctx, JSValueConst thisVal, JSAtom prop, void* userdata)
{
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Isolate::AutoEnterExitContext autoEnterExitContext(context);
    v8::NamedPropertyHandlerConfiguration* cfg = (v8::NamedPropertyHandlerConfiguration*)userdata;
    miniv8::V8Object* thisValue = miniv8::V8Object::create(context, thisVal);
    miniv8::V8External* external = (miniv8::V8External*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*(cfg->data));
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    if (0)
        JS_PrintStack(ctx);

    const char* nameStr = JS_AtomToCString(ctx, prop);
    miniv8::V8String* name = new miniv8::V8String(std::string(nameStr));
    JS_FreeCString(ctx, nameStr);
    v8::Local<v8::String> nameV8 = v8::Utils::convert<miniv8::V8String, v8::String>(name);

    void* args[v8::PropertyCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    args[v8::PropertyCallbackInfo<v8::Value>::kShouldThrowOnErrorIndex] = nullptr;
    args[v8::PropertyCallbackInfo<v8::Value>::kHolderIndex] = v8::Utils::maskPtr(thisValue); // kHolderIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kIsolateIndex] = isolate; // kIsolateIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueDefaultValueIndex] = nullptr; // kReturnValueDefaultValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex] = nullptr; // &returnValue[2]; //kReturnValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kDataIndex] = v8::Utils::maskPtr(external); // kDataIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kThisIndex] = v8::Utils::maskPtr(thisValue); // kThisIndex

    MacroAssembler infoStub; // 搞个假的，其实只是为了地址占位
    infoStub.stub = args;
    v8::PropertyCallbackInfo<v8::Value>* info = (v8::PropertyCallbackInfo<v8::Value>*)(&infoStub);
    void** retVal = &args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;

    cfg->getter(nameV8, *info);
    JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);
    return v;
}

JSValue v8::MacroAssembler::onIndexHandle(JSContext* ctx, JSValueConst thisVal, int32_t index, void* userdata)
{
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Isolate::AutoEnterExitContext autoEnterExitContext(context);
    v8::IndexedPropertyHandlerConfiguration* cfg = (v8::IndexedPropertyHandlerConfiguration*)userdata;
    miniv8::V8Object* thisValue = miniv8::V8Object::create(context, thisVal);
    miniv8::V8External* external = (miniv8::V8External*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*(cfg->data));
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    void* args[v8::PropertyCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    args[v8::PropertyCallbackInfo<v8::Value>::kShouldThrowOnErrorIndex] = nullptr;
    args[v8::PropertyCallbackInfo<v8::Value>::kHolderIndex] = v8::Utils::maskPtr(thisValue); // kHolderIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kIsolateIndex] = isolate; // kIsolateIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueDefaultValueIndex] = nullptr; // kReturnValueDefaultValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex] = nullptr; // &returnValue[2]; //kReturnValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kDataIndex] = v8::Utils::maskPtr(external); // kDataIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kThisIndex] = v8::Utils::maskPtr(thisValue); // kThisIndex

    MacroAssembler infoStub; // 搞个假的，其实只是为了地址占位
    infoStub.stub = args;
    v8::PropertyCallbackInfo<v8::Value>* info = (v8::PropertyCallbackInfo<v8::Value>*) & infoStub;
    void** retVal = &args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;

    cfg->getter(index, *info);

    JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);
    return v;
}

} // v8

namespace miniv8 {

static inline uint16_t byteswap_ushort(uint16_t number)
{
#if defined(_MSC_VER) && _MSC_VER > 1310
    return _byteswap_ushort(number);
#elif defined(__GNUC__)
    return __builtin_bswap16(number);
#else
    return (number >> 8) | (number << 8);
#endif
}

//根据首字节,获取utf8字符所占字节数
inline int getUtf8charByteNum(unsigned char ch)
{
    int byteNum = 0;

    if (ch >= 0xFC && ch < 0xFE)
        byteNum = 6;
    else if (ch >= 0xF8)
        byteNum = 5;
    else if (ch >= 0xF0)
        byteNum = 4;
    else if (ch >= 0xE0)
        byteNum = 3;
    else if (ch >= 0xC0)
        byteNum = 2;
    else if (0 == (ch & 0x80))
        byteNum = 1;

    return byteNum;
}

//计算utf8字符串字符个数
size_t getUtf8Length(const char* str, size_t clen)
{
    size_t len = 0;
    int byteNum = 0;
    unsigned char ch;
    const char* ptr = str;

    if (NULL == str)
        return 0;

    if (0 == clen)
        clen = strlen(str);

    while (*ptr != '\0' && len < clen) {
        ch = (unsigned char)*ptr;
        if (0 == (byteNum = getUtf8charByteNum(ch)))
            return len;
        ptr += byteNum;
        len++;
    }

    return len;
}

uint32_t hash(const char* arKey, size_t nKeyLength)
{
    uint32_t h = 0, g;
    const char* arEnd = arKey + nKeyLength;

    while (arKey < arEnd) {
        h = (h << 4) + *arKey++;
        if ((g = (h & 0xF0000000))) {
            h = h ^ (g >> 24);
            h = h ^ g;
        }
    }
    return h;
}

V8Isolate* V8Isolate::m_inst = nullptr;

JSClassID g_mbClassId = 0;

V8Isolate::V8Isolate()
{
    m_runtime = JS_NewRuntime();
    JS_SetMaxStackSize(m_runtime, (256 * 1024 * 5));
    if (m_inst)
        DebugBreak();

    JS_NewClassID(&g_mbClassId);

    m_errorVal = JS_NULL;
    m_globalHandleIndex = 0;
    m_handleScopeHandleIndex = 0;
    m_globalizeHandles.resize(kHandlesSize);
    m_handleScopeHandles.resize(kHandlesSize);
    memset(m_globalizeHandles.data(), 0, sizeof(void*) * m_globalizeHandles.size());
    memset(m_handleScopeHandles.data(), 0, sizeof(void*) * m_handleScopeHandles.size());
    memset(m_apiPointer, 0, sizeof(void*) * kSlotSize);
    
    memset(m_eternals, 0, sizeof(void*) * kSlotSize);

    typedef v8::internal::Internals I;
    *I::GetRoot((v8::Isolate*)&m_apiPointer, I::kNullValueRootIndex) = (v8::internal::Object*)v8::Utils::maskPtr(new miniv8::V8Value(nullptr, JS_NULL));
    *I::GetRoot((v8::Isolate*)&m_apiPointer, I::kTrueValueRootIndex) = (v8::internal::Object*)v8::Utils::maskPtr(new miniv8::V8Value(nullptr, JS_TRUE));
    *I::GetRoot((v8::Isolate*)&m_apiPointer, I::kFalseValueRootIndex) = (v8::internal::Object*)v8::Utils::maskPtr(new miniv8::V8Value(nullptr, JS_FALSE));
    *I::GetRoot((v8::Isolate*)&m_apiPointer, I::kUndefinedValueRootIndex) = (v8::internal::Object*)v8::Utils::maskPtr(new miniv8::V8Value(nullptr, JS_UNDEFINED));
    *I::GetRoot((v8::Isolate*)&m_apiPointer, I::kEmptyStringRootIndex) = (v8::internal::Object*)v8::Utils::maskPtr(new miniv8::V8String(""));

    m_inst = this;
}

void V8Isolate::clearErr(JSContext* ctx)
{
    if (JS_NULL != m_errorVal)
        JS_FreeValue(nullptr, m_errorVal);
    m_errorVal = JS_NULL;
}

bool V8Isolate::hasErr() const
{
    return JS_NULL != m_errorVal;
}

JSValue V8Isolate::getErrAndClear()
{
    return m_errorVal;
}

static void** findHandleEmptyIndex(int* handleIndex, std::vector<void*>* handles)
{
    void** ret = nullptr;

    size_t count = 0;
    for (size_t i = *handleIndex; ; ++i, ++count) {
        if (count == handles->size()) {
            DebugBreak();
            break;
        }

        if (i >= handles->size()) {
            i = 0;
        }

        if (nullptr == handles->at(i)) {
            ret = (void**)(handles->data() + i);
            *handleIndex = i + 1;
            break;
        }
    }
    return ret;
}

void** V8Isolate::findGlobalizeHandleEmptyIndex()
{
    return findHandleEmptyIndex(&m_globalHandleIndex, &m_globalizeHandles);
}

void** V8Isolate::findHandleScopeEmptyIndex()
{
    return findHandleEmptyIndex(&m_handleScopeHandleIndex, &m_handleScopeHandles);
}

void V8Isolate::enterContext(V8Context* ctx)
{
    m_currentCtxs.push_back(ctx);
}

void V8Isolate::exitContext()
{
    m_currentCtxs.pop_back();
}

V8Context* V8Isolate::getCurrentCtx()
{
    if (isInContext())
        return m_currentCtxs[m_currentCtxs.size() - 1];

    return nullptr;
}

V8Isolate::~V8Isolate()
{

}

size_t V8Isolate::registerTemplate(V8Template* t)
{
    m_templates.push_back(t);
    //static int s_idGen = 1; // TODO: 没考虑多线程竞争情况
    //s_idGen++;
    return m_templates.size() - 1;
}

V8Template* V8Isolate::getTemplateById(size_t id)
{
    return id >= m_templates.size() ? 0 : m_templates[id];
}

bool V8Isolate::isInContext()
{
    return m_currentCtxs.size() > 0;
}

V8Value* V8Value::create(V8Context* context, JSValue value)
{
    V8Object* old = (V8Object*)JS_GetUserdata(value);
    JSContext* ctx = V8Context::getCtx(context);

    if (old) {
        JS_DupValue(ctx, value); // TODO: free
        JSValue oldV = JS_GetTestVal(value);
        miniv8ReleaseAssert(oldV == value, "V8Value::create fail\n");
        return old;
    }

    if (JS_IsString(value)) {
        JS_DupValue(ctx, value); // TODO: free
        return new V8String(context, value);
    }

    if (JS_IsFunction(ctx, value)) {
        JS_DupValue(ctx, value); // TODO: free
        return new V8Function(context, value);
    }

    if (JS_IsArray(ctx, value)) {
        JS_DupValue(ctx, value); // TODO: free
        return new V8Array(context, value);
    }

    // TODO: num等其他类型
    JS_DupValue(ctx, value); // TODO: free
    return new V8Value(context, value);
}

JSClassID V8Object::s_classId = 0;

V8Object* V8Object::create(V8Context* ctx, JSValue value)
{
    s_classId = g_mbClassId; // TODO: 以后再区分一下

    V8Object* old = (V8Object*)JS_GetUserdata(value);
    if (old) {
        JS_DupValue(ctx->ctx(), value); // TODO: free
        JSValue oldV = JS_GetTestVal(value);
        miniv8ReleaseAssert(oldV == value, "V8Object::create fail\n");
        return old;
    }
    // TODO:JS_IsUndefined\JS_IsNull
    return new V8Object(ctx, value);
}

V8Object* V8Object::createFromClone(V8Context* ctx, JSValue value)
{
    s_classId = g_mbClassId; // TODO: 以后再区分一下

    V8Object* old = (V8Object*)JS_GetUserdata(value);
    //miniv8ReleaseAssert(old, "V8Object::createFromClone fail\n");
    JS_SetUserdataFromClone(value, nullptr);
    JS_SetTestValFromClone(value, 0);

    // TODO:JS_IsUndefined\JS_IsNull
    return new V8Object(ctx, value);
}

V8Object::V8Object(V8Context* ctx, JSValue value) : V8Value(ctx, value)
{
    m_head.m_type = kObjectTypeObject;
    m_props = nullptr;
    isObject = true;
    m_internalFieldCount = 0;

    static int s_count = 0;
    s_count++;

//     if (s_count == 190)
//         printDebug("V8Object, %d, %I64u!!\n", s_count, value);
// 
//     if (s_count == 401)
//         printDebug("V8Object, %d, %I64u!!\n", s_count, value);
    //printDebug("V8Object: %p, %d, %I64u\n", this, s_count, value);

    V8Object* old = (V8Object*)JS_GetUserdata(value/*, JS_CLASS_OBJECT*/);
    if (old)
        DebugBreak();

    memset(m_alignedPointerInInternalFields, 0, sizeof(void*) * V8Object::kMaxaAlignedPointerArraySize);
    memset(m_internalFields, 0, sizeof(void*) * V8Object::kMaxaAlignedPointerArraySize);

    JS_SetUserdata(value, this);
    JS_SetTestVal(value, value);
}

V8Object::~V8Object()
{
    // TODO: 释放的时候要JS_GetUserdata
    if (m_props)
        delete m_props;
}

V8Object* V8Object::getByQjsValue(JSValue value)
{
    V8Object* old = (V8Object*)JS_GetUserdata(value);
    return old;
}

v8::Local<v8::Value> V8Object::GetPrototype()
{
    miniv8::V8Object* self = this;
    JSContext* ctx = self->ctx();
    miniv8::V8Context* v8ctx = self->v8Ctx();
    miniv8ReleaseAssert(ctx, "V8Object::GetPrototype fail\n");

    JSValue selfV = self->v(self);

    JSValue proto = JS_UNDEFINED;
    if (false && JS_IsFunction(ctx, selfV)) {
        proto = JS_GetPropertyStr(ctx, selfV, "prototype");
    } else {
        proto = JS_GetPrototype(ctx, selfV);
    }

    //printDebug("v8::Object::GetPrototype: %I64u, %I64u\n", selfV, proto);

    if (JS_IsException(proto))
        DebugBreak();

    if (JS_IsUndefined(proto)) {
        proto = JS_NewObject(ctx);
        JS_SetPropertyStr(ctx, selfV, "prototype", proto);
        //JS_SetPrototype(ctx, selfV, proto);
        DebugBreak();
    }

    miniv8::V8Object* obj = miniv8::V8Object::create(v8ctx, proto); // 这里返回的对象，可以是复用的
    obj->m_internalFieldCount = self->m_internalFieldCount;
    v8::Local<v8::Object> ret = v8::Utils::convert<miniv8::V8Object, v8::Object>(obj);
    return ret;
}

bool V8Object::SetPrototype(JSContext* ctx, miniv8::V8Value* protoVal)
{
    miniv8::V8Object* self = this;

    if (protoVal->m_head.m_type == miniv8::kObjectTypeObject) {
        miniv8::V8Object* protoObj = (miniv8::V8Object*)protoVal;

        //         miniv8ReleaseAssert(
        //             0 == self->m_alignedPointerInInternalFields.size() ||
        //             protoObj->m_alignedPointerInInternalFields.size() == self->m_alignedPointerInInternalFields.size(),
        //             "v8::Object::SetPrototype fail\n"); // TODO:
        //         self->m_alignedPointerInInternalFields = protoObj->m_alignedPointerInInternalFields;
        memcpy(self->m_alignedPointerInInternalFields, protoObj->m_alignedPointerInInternalFields, sizeof(void*) * miniv8::V8Object::kMaxaAlignedPointerArraySize);
    }

    JSValueConst protoV = protoVal->v(protoVal);
    miniv8ReleaseAssert(!JS_IsUndefined(protoV), "V8Object::SetPrototype fail\n");
    JSValue selfV = self->v(self);
    JSAtom prototypeAtom = JS_NewAtom(ctx, "prototype");

    BOOL isFunctionOfProtoVal = JS_IsFunction(ctx, protoV);

    int ret = -1;
    BOOL isFunction = JS_IsFunction(ctx, selfV);
    if (false && isFunction) { // 貌似v8::Object::SetPrototype就是设置__proto__的。刚好JS_SetPrototype也是设置__proto__
        JS_DupValue(ctx, protoV);
        ret = JS_SetPropertyFocus(ctx, selfV, prototypeAtom, protoV);
        //int ret = JS_DefinePropertyValue(ctx, selfV, prototypeAtom, protoV, 0);

        JSValue test = JS_GetProperty(ctx, selfV, prototypeAtom);
        BOOL isUndef = JS_IsUndefined(test);
        isUndef = isUndef;
    } else {
        ret = JS_SetPrototype(ctx, selfV, protoV);
    }

    //printDebug("v8::Object::SetPrototype: %I64u, %I64u\n", selfV, protoV);

    if (-1 == ret) { // -1有可能是protoV的原型链上，已经有v了。一般出现在global.prototype再设置prototype的时候
        JSValue global = JS_GetGlobalObject(ctx);
        JSValue globalPrototype = JS_GetPrototypeFree(ctx, global);
        if (globalPrototype == selfV) {
            miniv8ReleaseAssert(!isFunction, "V8Object::SetPrototype fail\n");

            miniv8::V8Object* protoObj = (miniv8::V8Object*)protoVal;
            protoObj = (miniv8::V8Object*)JS_GetUserdata(protoV); // test

            // 这里不规范，不过暂时先这么搞搞，把global.prototype.prototype = protoV 变成 global.prototype = protoV
            //printDebug("v8::Object::SetPrototype!: %I64u\n", protoV);
            ret = JS_SetPrototype(ctx, global, protoV);
            //ret = JS_SetPropertyStr(ctx, global, "prototype", protoV);
            //ret = JS_DefinePropertyValue(ctx, global, prototypeAtom, protoV, 0);
        }
    }

    return (TRUE == ret);
}

// 函数的实例被调用，通常是构造函数
JSValue V8Function::onConstructorCallback(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv, void* userdata)
{
    return v8::internal::FunctionCallbackArguments::onConstructorCallback(ctx, thisVal, argc, argv, userdata);
}

std::string V8Function::getName()
{
    if (m_name.empty()) {
        static int i = 0;
        ++i;
        char temp[64] = { 0 };
        sprintf(temp, "_miniv8_func_noname_%d\n", i);
        m_name = temp;
    }
    return m_name;
}

void V8Function::setName(const std::string& name)
{
    if (!m_name.empty())
        DebugBreak();
    m_name = name;
}

// function HTMLAllCollection() { [native code] }
static JSValue onToStringOfFunc(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv, void* userdata)
{
    V8Function* self = (V8Function*)userdata;
    std::string name = "function ";
    name += self->getName();
    name += "() { [native code] }";
    return JS_NewString(ctx, name.c_str());
}

JSValue V8Function::V8Function_v(V8Data* ptr)
{
    V8Function* self = (V8Function*)ptr;
    if (JS_NULL != self->m_qjsValue)
        return self->m_qjsValue;

    JSContext* ctx = self->m_ctx->ctx();

    std::string name = self->getName();
    self->m_qjsValue = JS_NewCFunction2(ctx, onConstructorCallback, name.c_str(), name.size(), JS_CFUNC_constructor, 0, self);
    JS_DupValue(ctx, self->m_qjsValue); // TODO:free

    JSValue toStringFuncVal = JS_NewCFunction2(ctx, onToStringOfFunc, name.c_str(), 0, JS_CFUNC_generic, 0, self);
    //JS_DupValue(ctx, toStringFuncVal); // TODO:free
    JSAtom toStringAtom = JS_NewAtom(ctx, "toString");
    JS_SetProperty(ctx, self->m_qjsValue, /*JS_ATOM_toString*/toStringAtom, toStringFuncVal);

    JS_SetUserdata(self->m_qjsValue, self);
    JS_SetTestVal(self->m_qjsValue, self->m_qjsValue);

    return self->m_qjsValue;
}

V8Signature* V8Signature::create(V8FunctionTemplate* templ)
{
    return new V8Signature(templ->getId());
}

V8Signature::V8Signature(int funcTemplId)
    : V8Data(nullptr, JS_NULL)
{
    m_head.m_type = kObjectTypeSignature;
    m_funcTemplId = funcTemplId;
}

void V8FunctionTemplate::setClassName(const std::string& name)
{
    if (!m_name.empty() && m_name != name)
        DebugBreak();
    m_name = name;
}

std::string V8FunctionTemplate::getClassName()
{
    if (m_name.empty()) {
        static int i = 0;
        ++i;
        char temp[64] = { 0 };
        sprintf(temp, "_miniv8_funtemp_noname_%d\n", i);
        m_name = temp;
    }
    return m_name;
}

// 函数模版的实例被调用，通常是构造函数
void V8FunctionTemplate::onCall(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    // 在构造实例的时候，绑定InstanceTemplate
    miniv8::V8FunctionTemplate* self = (miniv8::V8FunctionTemplate*)(v8::External::Cast(*info.Data())->Value());
    V8ObjectTemplate* objTempl = (V8ObjectTemplate*)self->m_instanceTemplate;
    if (!objTempl)
        return;

    V8Isolate* isolate = (V8Isolate*)info.GetIsolate();
    V8Context* ctx = isolate->getCurrentCtx();

    v8::Local<v8::Object> objV8 = info.This();
    miniv8::V8Object* obj = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(*objV8);

    std::map<std::string, JSValue>::iterator it = objTempl->m_props.begin();
    for (; it != objTempl->m_props.end(); ++it) {
        std::string name = it->first;
        JSValue val = it->second;
        JSAtom prop = JS_NewAtomLen(ctx->ctx(), name.c_str(), name.size());
        JS_DupValue(ctx->ctx(), val);
        JS_DefinePropertyValue(ctx->ctx(), obj->v(obj), prop, val, 0);
    }

    // TODO: 绑定setter

//     JSCFunctionListEntry jsMt19937ProtoFuncs[2] = {
//         //JS_CFUNC_DEF("generate", 1, jsMt19937Generate)
//         { "generate", JS_PROP_WRITABLE | JS_PROP_CONFIGURABLE, JS_DEF_CFUNC, 0,{ 1, JS_CFUNC_generic,{ jsMt19937Generate } } },
//         { "haha", JS_PROP_WRITABLE | JS_PROP_CONFIGURABLE, JS_DEF_CGETSET, 0,{ 0 } }
//     };
// 
//     JS_SetPropertyFunctionList(ctx->ctx(), obj->v(), jsMt19937ProtoFuncs, /*std::extent_v<decltype(jsMt19937ProtoFuncs)>*/ 2);

    if (self->m_constructor)
        self->m_constructor(info);
    else
        DebugBreak();
}

V8Template::V8Template()
    : V8Data(nullptr, JS_NULL)
    , m_indexedPropHandles()
    , m_namePropHandles()
{
    m_head.m_type = kObjectTypeTemplate;
    m_isInit = false;
    m_internalFieldCount = 0;
    m_parentTemplate = nullptr;
    m_instanceTemplate = nullptr;
    m_prototypeTemplate = nullptr;

    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8::Isolate::GetCurrent();
    m_id = isolate->registerTemplate(this);

    //if (0x177 == m_id)
    //    OutputDebugStringA("V8Template!\n"); 
    //     printDebug("V8Template: %p, %d\n", this, m_id);
}

struct FunctionTemplateInfo {
    void* userdata;
    v8::FunctionCallback constructor;
    miniv8::V8Signature* signature;
};

} // miniv8 

namespace v8 {
namespace internal {

static bool checkCallSignature(miniv8::V8Isolate* isolate,  miniv8::V8Context* context, miniv8::V8Signature* signature, miniv8::V8Object* holder)
{
    int holderTemplId = holder->getTemplId();
    if (!signature)
        return true;

    int signatureId = signature->getFuncTemplId();
    if (signatureId == holderTemplId)
        return true;

//     miniv8::V8Template* templ = isolate->getTemplateById(holderTemplId);
//     while (templ) {
//         if (signatureId == templ->getId())
//             return true;
//         templ = templ->getParentTemplate();
//     }

    JSValue val = holder->v(holder); // JS_GetPrototypeFree(context->ctx(), holder->v(holder)); // 
    while (true) {
        miniv8::V8Value* v = miniv8::V8Value::create(context, val);
        int templId = v->getTemplId();
        miniv8::V8Template* templ = isolate->getTemplateById(templId);
        while (templ) {
            if (signatureId == templ->getId())
                return true;
            templ = templ->getParentTemplate();
        }

        JSValue value = JS_GetPrototypeFree(context->ctx(), val);
        if (value == val || JS_NULL == value || JS_UNDEFINED == value)
            break;
        val = value;
    }

    return false;
}

JSValue FunctionCallbackArguments::onCFunctionCallback(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv, void* userdata)
{
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Isolate::AutoEnterExitContext autoEnterExitContext(context);
    miniv8::FunctionTemplateInfo* info = (miniv8::FunctionTemplateInfo*)userdata;
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    miniv8::V8Object* thisValV8 = nullptr;
    miniv8::V8Object* holder = nullptr;
    //void* thisValPtr = nullptr;

    if (JS_IsUndefined(thisVal))
        thisVal = JS_GetGlobalObject(ctx); // 直接调用alert，thisVal可能为undefined

    if (2 == argc) {
        uint32_t tag = JS_VALUE_GET_TAG(argv[1]);        
        if (!JS_TAG_IS_FLOAT64(tag) && tag != JS_TAG_INT &&
            tag != JS_TAG_BOOL &&
            tag != JS_TAG_NULL &&
            tag != JS_TAG_UNDEFINED &&
            tag != JS_TAG_OBJECT &&
            tag != JS_TAG_STRING)
            JS_PrintStack(ctx);
    }

    holder = miniv8::V8Object::create(context, thisVal);
    thisValV8 = holder;
    //         if (holder->m_head.m_type == miniv8::V8ObjectType::kObjectTypeFunction && 1 == argc) {
    //             const char* prop = JS_ToCString(ctx, argv[0]);
    //             bool isToString = strcmp(prop, "toString") == 0;
    //             JS_FreeCString(ctx, prop);
    //             // "" + window["DOMTokenList"].prototype 类似这样的调用，blink因为重载了toString（见gen\blink\bindings\core\v8\V8DOMTokenList.cpp）
    //             // 按照v8的处理是直接报错。这里仿照v8的处理结果
    //             if (isToString) //
    //                 return JS_ThrowTypeError(ctx, "Illegal invocation");
    //         }

    if (/*false &&*/ !checkCallSignature((miniv8::V8Isolate*)isolate, context, info->signature, holder))
        return JS_ThrowTypeError(ctx, "Illegal invocation");

//     std::vector<void*> argValue;
//     argValue.resize(argc + 2);
// 
//     for (int i = 0; i < argc; ++i) {
//         miniv8::V8Value* v = miniv8::V8Value::create(context, argv[argc - i - 1]); // TODO:是不是也要用V8Object::create？
//         argValue[i] = v8::Utils::maskPtr(v);
//     }
// 
//     argValue[argc] = v8::Utils::maskPtr(holder);
//     argValue[argc + 1] = argValue[argc]; // 如果argc是0的话，v8会在FunctionCallbackInfo<T>::This()里取到这个地址
// 
//     void* returnValue[4] = { 0 };
//     returnValue[1] = isolate;
// 
//     miniv8::V8External external(info->userdata);
// 
//     void* implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kArgsLength] = { 0 };
//     implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kHolderIndex] = argValue[argc]; // kHolderIndex
//     implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kIsolateIndex] = isolate; // kIsolateIndex
//     implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kReturnValueDefaultValueIndex] = nullptr; // kReturnValueDefaultValueIndex
//     implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kReturnValueIndex] = &returnValue; // &returnValue[2]; //kReturnValueIndex
//     implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kDataIndex] = v8::Utils::maskPtr(&external); // kDataIndex
//     implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kCalleeIndex] = argValue[argc]; // kCalleeIndex
//     implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kContextSaveIndex] = thisValV8; // kContextSaveIndex
//     implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kNewTargetIndex] = thisValPtr; // kNewTargetIndex
// 
//     miniv8::FunctionCallbackInfoWrap functionCallbackInfoWrap;
//     functionCallbackInfoWrap.implicitArgs = implicitArgs;
//     functionCallbackInfoWrap.values = &argValue[argc ? argc - 1 : 0];
//     functionCallbackInfoWrap.length = argc;
    std::vector<void*> argValue;
    void* implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    miniv8::V8External external(info->userdata);
    miniv8::FunctionCallbackInfoWrap wrap;
    createFunctionCallbackInfo(context, thisValV8, &argValue, implicitArgs, &external, &wrap, argc, argv);

    void** retVal = (void**)&implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;

    v8::FunctionCallbackInfo<v8::Value>* wrapV8 = (v8::FunctionCallbackInfo<v8::Value>*)(&wrap);
    info->constructor(*wrapV8);
    JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);
    return v;
}

} // internal
} // v8

namespace miniv8 {

void V8Template::Set(v8::Local<v8::Name> name, v8::Local<v8::Data> value, v8::PropertyAttribute attr)
{
    if (value.IsEmpty())
        return; // TODO: installConstantInternal->v8::Integer::New 没实现
    miniv8::V8Data* val = v8::Utils::openHandle<v8::Data, miniv8::V8Data>(*value); // TODO: free

    miniv8::V8String* nameStr = (miniv8::V8String*)v8::Utils::openHandle<v8::Name, miniv8::V8Name>(*name);
    miniv8ReleaseAssert(
        miniv8::kObjectTypeString == nameStr->m_head.m_type ||
        miniv8::kObjectTypeSymbol == nameStr->m_head.m_type, // frome setClassString
        "v8::Template::Set fail\n");

    if (nameStr->getStr() == "toString" && v8::None == attr) // installV8NodeTemplate等会调用到这里。暂时不需要这样
        return;

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    if (miniv8::kObjectTypeFunctionTemplate == val->m_head.m_type) {
        miniv8::V8FunctionTemplate* funcProp = (miniv8::V8FunctionTemplate*)val;
        miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);

        FunctionTemplateInfo* info = new FunctionTemplateInfo(); // TODO: Free
        info->constructor = funcProp->m_constructor;
        info->userdata = funcProp->m_userdata;
        info->signature = funcProp->m_signature;

        JSCFunction* func = &v8::internal::FunctionCallbackArguments::onCFunctionCallback;
        JSValue v = JS_NewCFunction2(ctx->ctx(), func, nameStr->getStr().c_str(), /*funcProp->m_argLength*/-1, JS_CFUNC_generic, 0, info);
        JS_DupValue(ctx->ctx(), v);
        this->m_props.insert(std::make_pair(nameStr->getStr(), v));
    } else if (miniv8::kObjectTypeString == val->m_head.m_type) {
        miniv8::V8String* valStr = (miniv8::V8String*)val;
        miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
        JSValue v = valStr->v(valStr);
        JS_DupValue(ctx->ctx(), v);
        this->m_props.insert(std::make_pair(nameStr->getStr(), v));
    } else if (miniv8::kObjectTypeInteger == val->m_head.m_type) {
        miniv8::V8Integer* valInt = (miniv8::V8Integer*)val;
        JSValue v = valInt->v(valInt);
        this->m_props.insert(std::make_pair(nameStr->getStr(), v));
    } else {
        DebugBreak();
    }
}

// 
// static const int kShouldThrowOnErrorIndex = 0;
// static const int kHolderIndex = 1;
// static const int kIsolateIndex = 2;
// static const int kReturnValueDefaultValueIndex = 3;
// static const int kReturnValueIndex = 4;
// static const int kDataIndex = 5;
// static const int kThisIndex = 6;

static void copyIndexedPropHandleIfNotEmpty(v8::IndexedPropertyHandlerConfiguration* src, const v8::IndexedPropertyHandlerConfiguration& target)
{
    if (!src->getter) // TODO:暂时只支持getter
        src->getter = target.getter;
}

static void copyNamePropHandleIfNotEmpty(v8::NamedPropertyHandlerConfiguration* src, const v8::NamedPropertyHandlerConfiguration& target)
{
    if (!src->getter) // TODO:暂时只支持getter
        src->getter = target.getter;
}

void V8Template::newTemplateInstance(miniv8::V8Context* context, miniv8::V8Object* obj, bool isSetPrototype)
{
    JSContext* ctx = context->ctx();
    JSValue v = obj->v(obj);

    obj->m_internalFieldCount = this->m_internalFieldCount > obj->m_internalFieldCount ? this->m_internalFieldCount : obj->m_internalFieldCount;
    if (0 == obj->m_internalFieldCount && this->m_parentTemplate)
        obj->m_internalFieldCount = this->m_parentTemplate->m_internalFieldCount;

    //printDebug("v8::ObjectTemplate::NewInstance: %p, obj->m_internalFieldCount:%d\n", obj, obj->m_internalFieldCount);
    if (m_indexedPropHandles.getter) { // TODO:暂时只支持getter
        JSCFunctionType indexer;
        indexer.indexer = &v8::MacroAssembler::onIndexHandle;
        JS_SetIndexedOrNamePropertyFunction(ctx, v, JS_CFUNC_indexer, indexer, &m_indexedPropHandles);
    }

    if (m_namePropHandles.getter) { // TODO:暂时只支持getter
        JSCFunctionType namePropGet;
        namePropGet.name_property_get = &v8::MacroAssembler::onNamePropertyGet;
        JS_SetIndexedOrNamePropertyFunction(ctx, v, JS_CFUNC_name_property_get, namePropGet, &m_namePropHandles);
    }

    if (m_namePropHandles.setter) { // TODO:暂时只支持setter
        JSCFunctionType namePropSet;
        namePropSet.name_property_set = &v8::MacroAssembler::onNamePropertySet;
        JS_SetIndexedOrNamePropertyFunction(ctx, v, JS_CFUNC_name_property_set, namePropSet, &m_namePropHandles);
    }

    if (m_namePropHandles.query) { // TODO:暂时只支持setter
        JSCFunctionType namePropQuery;
        namePropQuery.name_property_query = &v8::MacroAssembler::onNamePropertyQuery;
        JS_SetIndexedOrNamePropertyFunction(ctx, v, JS_CFUNC_name_property_query, namePropQuery, &m_namePropHandles);
    }

    // 注意，如果实例化是给function template做原型链对象，要特殊处理一下
    for (std::map<std::string, JSValue>::iterator it = this->m_props.begin(); it != this->m_props.end(); ++it) {
        std::string name = it->first;
        JSValue val = it->second;
        JSAtom prop = JS_NewAtomLen(ctx, name.c_str(), name.size());

        JS_DupValue(ctx, v); // JS_DefinePropertyValue里面会释放一次
        JS_DupValue(ctx, val);
        JS_DefinePropertyValue(ctx, v, prop, val, 0);
    }

    if (this->m_accessors.empty())
        return;

    JSCFunctionListEntry* accessorsFuncs = new JSCFunctionListEntry[this->m_accessors.size()];
    std::map<std::string, V8Template::Accessor>::iterator it = this->m_accessors.begin();
    for (int i = 0; it != this->m_accessors.end(); ++it, ++i) {
        const std::string& name = it->first;
        V8Template::Accessor* val = &it->second;
        miniv8ReleaseAssert(val->nameGetter || val->nameSetter || val->getterFunc || val->setterFunc, "V8Template::newTemplateInstance fail\n");

        accessorsFuncs[i].name = name.c_str();
        accessorsFuncs[i].prop_flags = JS_PROP_CONFIGURABLE;
        accessorsFuncs[i].def_type = JS_DEF_CGETSET;
        accessorsFuncs[i].magic = 0;
        accessorsFuncs[i].u.getset.get.getter = nullptr;
        accessorsFuncs[i].u.getset.set.setter = nullptr;

        if (val->nameGetter)
            accessorsFuncs[i].u.getset.get.getter = &v8::MacroAssembler::objectTemplateGetter;
        if (val->nameSetter)
            accessorsFuncs[i].u.getset.set.setter = &v8::MacroAssembler::objectTemplateSetter;

        if (val->getterFunc)
            accessorsFuncs[i].u.getset.get.getter = &v8::internal::FunctionCallbackArguments::objectTemplateFuncGetter;
        if (val->setterFunc)
            accessorsFuncs[i].u.getset.set.setter = &v8::internal::FunctionCallbackArguments::objectTemplateFuncSetter;

        accessorsFuncs[i].u.getset.userdata = val; // TODO:userdata
    }

    JS_DupValue(ctx, v);
    JS_SetPropertyFunctionList(ctx, v, accessorsFuncs, this->m_accessors.size());
}

v8::MaybeLocal<v8::Function> V8FunctionTemplate::GetFunction(v8::Local<v8::Context> context)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8FunctionTemplate* self = this;
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);

    //printDebug("v8::FunctionTemplate::GetFunction: %p\n", self);

    // miniv8ReleaseAssert(!self->m_isInit, "v8::FunctionTemplate::GetFunction fail\n");
    self->m_isInit = true;

    miniv8::V8Function* fun = new miniv8::V8Function(ctx, &miniv8::V8FunctionTemplate::onCall, self);
    fun->m_internalFieldCount = self->m_internalFieldCount;
    fun->m_signature = self->m_signature;
    fun->setName(self->getClassName());
    fun->setTemplId(self->getId());

    self->newTemplateInstance(ctx, fun, false);

    v8::MaybeLocal<v8::Object> prototype;
#if 0 // 这个m_instanceTemplate的属性，要放到v8::Function::NewInstance里去设置
    if (self->m_instanceTemplate)
        self->m_instanceTemplate->newTemplateInstance(ctx, fun); // TODO: 没考虑m_instanceTemplate的m_instanceTemplate递归情况了
#endif

    if (self->m_prototypeTemplate) {
        //self->m_prototypeTemplate->newTemplateInstance(ctx, fun, true);

        v8::Local<v8::ObjectTemplate> prototypeTemplate = v8::Utils::convert<miniv8::V8ObjectTemplate, v8::ObjectTemplate>(self->m_prototypeTemplate);
        prototype = prototypeTemplate->NewInstance(context); // 这句里面会调用self->m_prototypeTemplate->newTemplateInstance(ctx, fun, true);
    }
    if (!prototype.IsEmpty()) {
        miniv8::V8Object* prototypeObject = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(*(prototype.ToLocalChecked()));
        //self->m_prototypeTemplate->newTemplateInstance(ctx, prototypeObject, false);

        //printDebug("V8FunctionTemplate::GetFunction, prototypeTemplate: fun: %I64u, prototype: %I64u\n",  fun->v(fun), prototypeObject->v(prototypeObject));

        JS_SetConstructor(ctx->ctx(), fun->v(fun), prototypeObject->v(prototypeObject)); // TODO free: 没考虑释放问题，另外不清楚那些访问器能否起作用
    }

    // TODO：没考虑继承

    v8::Local<v8::Function> ret = v8::Utils::convert<miniv8::V8Function, v8::Function>(fun);
    return v8::MaybeLocal<v8::Function>(ret);
}

void V8Template::inherit(const V8Template* parent)
{
//     if (m_head.m_type == V8ObjectType::kObjectTypeFunctionTemplate&&parent->m_head.m_type == V8ObjectType::kObjectTypeFunctionTemplate) {
//         const V8FunctionTemplate* parentPtr = (const V8FunctionTemplate*)parent;
//         V8FunctionTemplate* self = (V8FunctionTemplate*)this;
//         if (!self->m_constructor)
//             self->m_constructor = parentPtr->m_constructor;
//     }

    copyIndexedPropHandleIfNotEmpty(&m_indexedPropHandles, parent->m_indexedPropHandles);
    copyNamePropHandleIfNotEmpty(&m_namePropHandles, parent->m_namePropHandles);

    // 要考虑父模版的InstanceTemplate和PrototypeTemplate是否都要继承，以及这两模版的访问器是否也要继承
    for (std::map<std::string, miniv8::V8Template::Accessor>::const_iterator parentIt = parent->m_accessors.begin(); parentIt != parent->m_accessors.end(); ++parentIt) {
        std::map<std::string, miniv8::V8Template::Accessor>::iterator it = m_accessors.find(parentIt->first);
        if (it == m_accessors.end())
            m_accessors.insert(std::make_pair(parentIt->first, parentIt->second));
    }

    for (std::map<std::string, JSValue>::const_iterator parentIt = parent->m_props.begin(); parentIt != parent->m_props.end(); ++parentIt) {
        std::map<std::string, JSValue>::iterator it = m_props.find(parentIt->first);
        if (it == m_props.end())
            m_props.insert(std::make_pair(parentIt->first, parentIt->second));
    }

    if (parent->m_instanceTemplate) {
        if (!m_instanceTemplate)
            m_instanceTemplate = parent->m_instanceTemplate;
        else
            m_instanceTemplate->inherit(parent->m_instanceTemplate);
    }
    if (parent->m_prototypeTemplate) {
        if (!m_prototypeTemplate)
            m_prototypeTemplate = parent->m_prototypeTemplate;
        else
            m_prototypeTemplate->inherit(parent->m_prototypeTemplate);
    }

    m_parentTemplate = (V8Template*)parent;
}

V8String::V8String(const std::string& str) : V8Name(nullptr, JS_NULL)
{
    init();
    m_str = new std::string(str);

    // 先初始化一次。不过不一定能获取到
    V8Context* ctx = V8Context::getCurrentCtx();
    ensureQjsVal(ctx);
}

void V8String::ensureQjsVal(V8Context* context)
{
    V8Context* m_ctx = context;
    if (m_qjsValue != JS_NULL)
        return;
    JSContext* ctx = V8Context::getCtx(context);
    if (!ctx)
        return;
    m_qjsValue = JS_NewStringLen(ctx, m_str->c_str(), m_str->size());
    //m_str = ""; // TODO:暂时不清空缓存。 
}

JSValue V8String::V8String_v(V8Data* ptr)
{
    V8String* self = (V8String*)ptr;
    V8Context* ctx = V8Context::getCurrentCtx();
    self->ensureQjsVal(ctx);
    miniv8ReleaseAssert(self->m_qjsValue != JS_NULL, "V8String_v fail\n");

    return self->m_qjsValue;
}

const std::string& V8String::getStr()
{
    if (m_str)
        return *m_str;

    size_t len = 0;

    JSContext* context = ctx();
    if (!context)
        context = V8Context::getCurrentJsCtx();
    
    const char* nameString = JS_ToCStringLen(context, &len, m_qjsValue);
    if (!nameString)
        DebugBreak();
    m_str = new std::string(nameString);
    JS_FreeCString(context, nameString);
    return *m_str;
}

size_t V8String::getStrCount()
{
    if (-1 != m_strCount)
        return m_strCount;

    const std::string& str = getStr();
    m_strCount = miniv8::getUtf8Length(str.c_str(), str.size());
    return m_strCount;
}

}