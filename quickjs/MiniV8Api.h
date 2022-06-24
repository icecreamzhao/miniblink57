
#include "G:/mycode/mb_temp/v8_5_7/include/v8.h"
#include "G:/mycode/mb_temp/v8_5_7/include/v8-profiler.h"
#include "G:/mycode/mb_temp/v8_5_7/include/v8-debug.h"
//#include "G:/mycode/mb_temp/v8_5_7/include/sys-info.h"

#include "g:/mycode/quickjs-master/quickjs.h"
#include <vector>
#include <map>
#include <string>

void printEmptyFuncInfo(const char* fun, bool isBreak);
void miniv8ReleaseAssert(bool b, const char* info);
extern "C" void printDebug(const char* format, ...);

namespace v8 {

class Utils {
public:
    template<class From, class To>
    static inline To* openHandle(const From* that, bool allowEmptyHandle = false);

    template<class From, class To>
    static inline Local<To> convert(From* obj);

    template<class To>
    static inline To* toHandle(uintptr_t p);

    static inline void* maskPtr(void* obj);
};

}

namespace miniv8 {

extern JSClassID g_mbClassId;

uint32_t hash(const char* arKey, size_t nKeyLength);
size_t getUtf8Length(const char* str, size_t clen);
std::string utf16ToUtf8(const std::wstring& u16str);
std::string utf16leToUtf8(const std::wstring& u16str);
std::string utf16beToUtf8(const std::wstring& u16str);
std::wstring utf8ToUtf16le(const std::string& u8str, bool addbom, bool* ok);
std::wstring utf8ToUtf16be(const std::string& u8str, bool addbom, bool* ok);

std::string utf16ToChar(const wchar_t* lpszSrc, size_t size, unsigned int codepage);
std::wstring utf8ToUtf16(const std::string& utf8);

class V8Context;

struct FunctionCallbackInfoWrap {
    void* implicitArgs;
    void* values;
    int length;
};

enum V8ObjectType : uint32_t {
    kObjectTypeMin,
    kObjectTypeScript,
    kObjectTypeStackTrace,
    kObjectTypeContext,
    kObjectTypeData,
    kObjectTypePrivate,
    kObjectTypeValue,
    kObjectTypePrimitive,
    kObjectTypeNumber,
    kObjectTypeName,
    kObjectTypeSymbol,
    kObjectTypeString,
    kObjectTypeAccessorSignature,
    kObjectTypeArray,
    kObjectTypeObject,
    kObjectTypeFunction,
    kObjectTypeExternal,
    kObjectTypeArrayBuffer,
    kObjectTypeInt16Array,
    kObjectTypeInt32Array,
    kObjectTypeInt8Array,
    kObjectTypeInt32,
    kObjectTypeInteger,
    kObjectTypeTemplate,
    kObjectTypeObjectTemplate,
    kObjectTypeFunctionTemplate,
    kObjectTypeSignature,
    kObjectTypeMax
};

class V8Template;

class V8Isolate {
public:
    V8Isolate();
    ~V8Isolate();

    static V8Isolate* GetCurrent()
    {
        return m_inst; // TODO: save at tls
    }

    bool isInContext(void);
    void enterContext(V8Context* ctx);
    void exitContext();

    class AutoEnterExitContext {
    public:
        AutoEnterExitContext(V8Context* ctx)
        {
            V8Isolate* isolate = V8Isolate::GetCurrent();
            isolate->enterContext(ctx);
        }
        ~AutoEnterExitContext()
        {
            V8Isolate* isolate = V8Isolate::GetCurrent();
            isolate->exitContext();
        }
    private:
    };

    V8Context* getCurrentCtx();
    //V8Context* setCurrentCtx(V8Context* ctx);

    JSRuntime* getRuntime() const { return m_runtime; }

    size_t registerTemplate(V8Template* t);
    V8Template* getTemplateById(size_t id);

    void** findGlobalizeHandleEmptyIndex();
    void** findHandleScopeEmptyIndex();

    void clearErr(JSContext* ctx);
    bool hasErr() const;
    JSValue getErrAndClear();

    static const int kSlotSize = 64 * 10;
    void* m_apiPointer[kSlotSize]; // 这个必须放最前面，v8的机制如此
    void* m_eternals[kSlotSize]; // 这个好像是存放固定的v8::Value

private:
    friend class v8::Isolate;

    const int kHandlesSize = 0x10000;
    std::vector<void*> m_globalizeHandles;
    int m_globalHandleIndex;

    std::vector<void*> m_handleScopeHandles;
    int m_handleScopeHandleIndex;

    std::map<void*, void*> m_microtasks;

    std::vector<V8Template*> m_templates; // 所有的模版都注册在这里，不用释放了。

    JSRuntime* m_runtime;
    std::vector<V8Context*> m_currentCtxs;
    JSValue m_errorVal;

    static V8Isolate* m_inst;
};

struct V8Head {
    V8ObjectType m_type; // 这个必须放最前面，方便识别这是什么类型
    void* m_isolatHandleScopeIndex; // 方便v8::HandleScope::CreateHandle
    void* m_isolatGlobalScopeIndex;

    V8Head()
    {
        m_type = kObjectTypeMin;
        m_isolatHandleScopeIndex = nullptr;
        m_isolatGlobalScopeIndex = nullptr;
    }
};

class V8StackTrace {
public:
    V8StackTrace()
    {
        m_head.m_type = kObjectTypeStackTrace;
    }

    int getFrameCount() const
    {
        return 0;
    }
    V8Head m_head;
};

class V8Context {
public:
    V8Context(V8Isolate* isolate, JSContext* ctx);
    V8Context(const V8Context& other);

    JSContext* ctx() { return m_ctx; }
    V8Isolate* isolate() { return m_isolate; }

    static JSContext* getCtx(V8Context* self)
    {
        if (self)
            return self->ctx();
        return nullptr;
    }

    static V8Context* getCurrentCtx()
    {
        miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
        if (!isolate)
            return nullptr;
        V8Context* ctx = isolate->getCurrentCtx();
        return ctx;
    }
    static JSContext* getCurrentJsCtx()
    {
        miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
        if (!isolate)
            return nullptr;
        V8Context* ctx = isolate->getCurrentCtx();
        if (ctx)
            return ctx->ctx();
        return nullptr;
    }
    
    bool isCodeGenerationFromStringsAllowed() const { return m_isCodeGenerationFromStringsAllowed; }

private:
    friend class v8::Context;

    V8Head m_head;
    JSContext* m_ctx;
    V8Isolate* m_isolate;
    
    bool m_isCodeGenerationFromStringsAllowed;

    std::map<int, void*> m_alignedPointerInEmbedderDatas;
};

// 不能有虚函数，否则第一个字段不是m_type
class V8Data {
public:
    V8Data(V8Context* ctx, JSValue value)
    {
        m_head.m_type = kObjectTypeData;
        m_ctx = ctx;
        m_qjsValue = value;
        m_nodeClassId = 0;
        m_nodeFlag = 0;
        m_nodeState = 0;
        if (ctx && ctx->ctx())
            JS_DupValue(ctx->ctx(), value); // TODO:free

        v = V8Data_v;
        m_templId = -1;
        isObject = false;
        isExternal = false;
        isFunciton = false;
        isEternal = false;
    }

    static JSValue V8Data_v(V8Data* self)
    {
        return self->m_qjsValue;
    }

    JSContext* ctx() const
    {
        if (!m_ctx)
            return nullptr;
        return m_ctx->ctx();
    }

    V8Context* v8Ctx() const
    {
        return m_ctx;
    }

    V8Head m_head;
    uint16_t m_nodeClassId;
    uint8_t m_nodeFlag;
    uint8_t m_nodeState;

    void setTemplId(int id) { 
        m_templId = id;
        if (941 == m_templId)
            printDebug("setTemplId!!!\n");
    }
    int getTemplId() const { return m_templId; }

protected:
    JSValue m_qjsValue;
    V8Context* m_ctx;

    size_t m_templId; // 如果和一个v8::Template关联，就有id，这样就可以实现v8::FunctionTemplate::HasInstance

    typedef JSValue(*FN_v)(V8Data* self);

public:
    FN_v v;
    bool isObject;
    bool isExternal;
    bool isFunciton;
    bool isEternal;
};

class V8Private : public V8Data {
public:
    V8Private(V8Context* ctx, JSValue value) : V8Data(ctx, value)
    {
        m_head.m_type = kObjectTypePrivate;
    }
};

class V8Value : public V8Data {
public:
    V8Value(V8Context* ctx, JSValue value) : V8Data(ctx, value)
    {
        m_head.m_type = kObjectTypeValue;
    }

    static V8Value* create(V8Context* ctx, JSValue value);
};

class V8Number : public V8Value {
public:
    V8Number(V8Context* ctx, JSValue value) : V8Value(ctx, value)
    {
        m_head.m_type = kObjectTypeNumber;
    }
    V8Number(double num) : V8Value(nullptr, JS_NULL)
    {
        m_head.m_type = kObjectTypeNumber;
        m_qjsValue = JS_NewFloat64(nullptr, num);
    }
};

class V8Object : public V8Value {
public:
    static V8Object* create(V8Context* ctx, JSValue value);
    static V8Object* createFromClone(V8Context* ctx, JSValue value);
    ~V8Object();

    static JSClassID getClassId() { return s_classId; }
    static V8Object* getByQjsValue(JSValue value);

    bool SetPrototype(JSContext* ctx, miniv8::V8Value* protoVal);
    v8::Local<v8::Value> GetPrototype();

    // Tag information for Smi.
//     static const int kSmiTag = 0;
//     static const int kSmiTagSize = 1;
//     static const intptr_t kSmiTagMask = (1 << kSmiTagSize) - 1;

    inline static bool IsSmi(void* p) // 低位是0表示是SMI
    {
        bool b = (((intptr_t)(p) & v8::internal::kSmiTagMask) == v8::internal::kSmiTag);
        return b;
    }

    static const int kMaxaAlignedPointerArraySize = 8;
private:
    V8Object(V8Context* ctx, JSValue value);

    friend class v8::Object;
    friend class v8::ObjectTemplate;
    friend class v8::FunctionTemplate;
    friend class v8::Function;
    friend class V8Array;
    friend class V8Function;
    friend class V8Function;
    friend class V8Template;
    friend class V8FunctionTemplate;
    friend class v8::internal::FunctionCallbackArguments;

    friend JSValue wrapGetter(JSContext* ctx, JSValueConst thisVal, void* userdata);
    friend JSValue wrapSetter(JSContext* ctx, JSValueConst this_val, JSValueConst val, void* userdata);

    struct AccessorData {
        std::string name;
        v8::AccessorGetterCallback getter;
        v8::AccessorSetterCallback setter;
        V8Value* data;
    };

    static JSClassID s_classId;
    std::vector<JSCFunctionListEntry>* m_props; // 不定长的数组
    std::map<uint32_t, AccessorData*> m_accessorMap;

    int m_internalFieldCount;
    void* m_alignedPointerInInternalFields[kMaxaAlignedPointerArraySize];
    V8Value* m_internalFields[kMaxaAlignedPointerArraySize];
};

class V8Primitive : public V8Value {
public:
    V8Primitive(V8Context* ctx, JSValue value) : V8Value(ctx, value)
    {
        m_head.m_type = kObjectTypePrimitive;
    }
};

class V8Name : public V8Primitive {
public:
    V8Name(V8Context* ctx, JSValue value) : V8Primitive(ctx, value)
    {
        m_head.m_type = kObjectTypeName;
    }
};

// class V8Exception {
// public:
//     V8Exception(const std::string& err) : V8Name(NULL, JS_NULL)
//     {
//         error = err;
//         m_head.m_type = kObjectTypeException;
//     }
//     std::string error;
// };

class V8String : public V8Name {
public:
    V8String(V8Context* ctx, JSValue value) : V8Name(ctx, value)
    {
        init();
    }

    V8String(const std::string& str);

    ~V8String()
    {
        if (m_str)
            delete m_str;
    }

    const std::string& getStr();
    size_t getStrCount(); // 获取字符数，注意不是字节数

    static JSValue V8String_v(V8Data* self);

    void ensureQjsVal(V8Context* ctx);

protected:
    void init()
    {
        m_head.m_type = kObjectTypeString;
        v = V8String_v;
        m_externalString = nullptr;
        m_strCount = -1;
        m_isContainsOnlyOneByte = -1;
        m_str = nullptr;
    }

    friend class v8::String;
    std::string* m_str;
    size_t m_strCount;
    int m_isContainsOnlyOneByte; // 1:true,0:false,-1:uninit

    v8::String::ExternalStringResourceBase* m_externalString;
};

class V8Symbol : public V8String { // 暂时设定为string的子类
public:
    V8Symbol(V8Context* ctx, JSValue value) : V8String(ctx, value)
    {
        m_head.m_type = kObjectTypeSymbol;
        v = V8String_v;
    }
    V8Symbol(const std::string& str) : V8String(nullptr, JS_NULL)
    {
        m_head.m_type = kObjectTypeSymbol;
        m_str = new std::string(str);
        v = V8String_v;
    }
};

class V8AccessorSignature : public V8Data {
public:
    V8AccessorSignature(V8Context* ctx, JSValue value)
        : V8Data(ctx, value)
    {
        m_head.m_type = kObjectTypeAccessorSignature;
    }
};

class V8Array : public V8Object {
public:
    V8Array(V8Context* ctx, JSValue value)
        : V8Object(ctx, value)
    {
        m_head.m_type = kObjectTypeArray;
    }
};

class V8Signature;

class V8Function : public V8Object {
public:
    V8Function(V8Context* ctx, JSValue v)
        : V8Object(ctx, v)
    {
        init();
    }

    V8Function(V8Context* ctx, v8::FunctionCallback callback, void* data)
        : V8Object(ctx, JS_NULL)
    {
        init();
        m_callback = callback;
        m_data = data;
    }

    void init()
    {
        m_head.m_type = kObjectTypeFunction;
        m_callback = nullptr;
        m_data = nullptr;
        isFunciton = true;
        v = V8Function_v;
        m_signature = nullptr;
    }

    // 为了延迟初始化
    static JSValue V8Function_v(V8Data* self);
    std::string getName();
    void setName(const std::string& name);

private:
    friend class v8::Function;
    friend class V8FunctionTemplate;
    friend class v8::internal::FunctionCallbackArguments;

    static JSValue onConstructorCallback(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, void* userdata);

    v8::FunctionCallback m_callback;
    void* m_data;
    std::string m_name;
    V8Signature* m_signature;
};

class V8External : public V8Value {
public:
    V8External(void* userdata) : V8Value(nullptr, JS_NULL)
    {
        m_head.m_type = kObjectTypeExternal;
        m_userdata = userdata;
        isExternal = true;
    }

    void* getUserdata()
    {
        return m_userdata;
    }

private:
    friend class v8::External;
    void* m_userdata;
};

class V8ObjectTemplate;

class V8Signature : public V8Data {
public:
    static V8Signature* create(V8FunctionTemplate* templ);
    int getFuncTemplId() const { return m_funcTemplId; }

private:
    V8Signature(int funcTemplId);
    int m_funcTemplId;
};

class V8Template : public V8Data {
public:
    V8Template();

    struct Accessor {
        std::string name;
        v8::AccessorGetterCallback getter;
        v8::AccessorSetterCallback setter;

        v8::AccessorNameGetterCallback nameGetter;
        v8::AccessorNameSetterCallback nameSetter;

        v8::FunctionCallback getterFunc; // 我也没搞明白有nameGetter为啥还有个getterFunc。但v8就是有不同的访问器，通过v8::Template::SetAccessorProperty
        v8::FunctionCallback setterFunc;

        void* data;
        Accessor()
        {
            getter = nullptr;
            setter = nullptr;
            nameGetter = nullptr;
            nameSetter = nullptr;
            getterFunc = nullptr;
            setterFunc = nullptr;
            data = nullptr;
        }
    };
    void inherit(const V8Template* parent);
    void newTemplateInstance(miniv8::V8Context* ctx, miniv8::V8Object* obj, bool isSetPrototype);

    size_t getId() const { return m_id; }

    void Set(v8::Local<v8::Name> name, v8::Local<v8::Data> value, v8::PropertyAttribute attr);

    V8Template* getParentTemplate() const { return m_parentTemplate; }
protected:
    friend class v8::ObjectTemplate;
    friend class v8::FunctionTemplate;
    friend class v8::Template;
    friend class v8::Function;

    int m_internalFieldCount;
    V8Template* m_parentTemplate;
    V8ObjectTemplate* m_instanceTemplate;
    V8ObjectTemplate* m_prototypeTemplate;

    size_t m_id;

    std::map<std::string, Accessor> m_accessors;
    std::map<std::string, JSValue> m_props;

    v8::IndexedPropertyHandlerConfiguration m_indexedPropHandles;
    v8::NamedPropertyHandlerConfiguration m_namePropHandles;

    bool m_isInit;
};

class V8ObjectTemplate : public V8Template {
public:
    V8ObjectTemplate() : V8Template()
    {
        //printDebug("V8ObjectTemplate: %p\n", this);
        m_head.m_type = kObjectTypeObjectTemplate;
    }

private:
    friend class v8::ObjectTemplate;
    friend class v8::FunctionTemplate;
    friend class V8FunctionTemplate;
};

class V8FunctionTemplate : public V8Template {
public:
    V8FunctionTemplate()
        : V8Template()
    {
        m_head.m_type = kObjectTypeFunctionTemplate;
        m_userdata = nullptr;
        m_instanceTemplate = nullptr;
        m_prototypeTemplate = nullptr;
        m_argLength = 0;
        m_signature = nullptr;

//         static int s_count = 0;
//         if (346 == s_count)
//             printDebug("!\n");
//         printDebug("V8FunctionTemplate: %p, %d\n", this, s_count);
//         s_count++;
    }
    v8::MaybeLocal<v8::Function> GetFunction(v8::Local<v8::Context> context);
private:
    std::string getClassName();
    void setClassName(const std::string& name);

    v8::FunctionCallback m_constructor;
    void* m_userdata;
    std::string m_name;
    int m_argLength;
    miniv8::V8Signature* m_signature;
    
    friend class v8::Template;
    friend class v8::ObjectTemplate;
    friend class v8::FunctionTemplate;
    friend class v8::FunctionTemplate;
    friend class V8Value;
    friend class V8Template;
    friend class V8ObjectTemplate;
    static void V8CALL onCall(const v8::FunctionCallbackInfo<v8::Value>& info);
};

class V8Script {
public:
    V8Script()
    {
        m_head.m_type = kObjectTypeScript;
    }
    void setSource(const std::string& src) { m_src = src; }
    const std::string& getSource() const { return m_src; }

    void setSourceName(const std::string& name) { m_srcName = name; }
    const std::string& getSourceName() const { return m_srcName; }

private:
    V8Head m_head;
    std::string m_src;
    std::string m_srcName;
};

inline std::string getStringFromV8String(v8::Local<v8::String> str)
{
    printEmptyFuncInfo(__FUNCTION__, true);

    miniv8::V8String* v8string = v8::Utils::openHandle<v8::String, miniv8::V8String>(*str);

//     miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
//     JSContext* ctx = v8string->ctx();
//     if (!ctx)
//         ctx = isolate->getCurrentCtx()->ctx();
// 
//     size_t len = 0;
//     const char* nameString = JS_ToCStringLen(ctx, &len, v8string->v(v8string));
//     std::string ret(nameString);
//     JS_FreeCString(v8string->ctx(), nameString);
// 
//     return ret;
    return v8string->getStr();
}

class V8ArrayBuffer : public V8Value {
public:
    V8ArrayBuffer(V8Context* ctx, JSValue value)
        : V8Value(ctx, value)
    {
        m_head.m_type = kObjectTypeArrayBuffer;
    }
};

class V8Int16Array : public V8ArrayBuffer {
public:
    V8Int16Array(V8Context* ctx, JSValue value)
        : V8ArrayBuffer(ctx, value)
    {
        m_head.m_type = kObjectTypeInt16Array;
    }
};

class V8Int32Array : public V8ArrayBuffer {
public:
    V8Int32Array(V8Context* ctx, JSValue value)
        : V8ArrayBuffer(ctx, value)
    {
        m_head.m_type = kObjectTypeInt32Array;
    }
};

class V8Int8Array : public V8ArrayBuffer {
public:
    V8Int8Array(V8Context* ctx, JSValue value)
        : V8ArrayBuffer(ctx, value)
    {
        m_head.m_type = kObjectTypeInt8Array;
    }
};

class V8Int32 : public V8Value {
public:
    V8Int32(V8Context* ctx, JSValue value)
        : V8Value(ctx, value)
    {
        m_head.m_type = kObjectTypeInt32;
    }
};

class V8Integer : public V8Value {
public:
    V8Integer(V8Context* ctx, JSValue value)
        : V8Value(ctx, value)
    {
        m_head.m_type = kObjectTypeInteger;
    }

    V8Integer(int32_t val)
        : V8Value(nullptr, JS_NULL)
    {
        m_head.m_type = kObjectTypeInteger;
        m_qjsValue = JS_NewInt32(nullptr, val);
    }

    V8Integer(uint32_t val)
        : V8Value(nullptr, JS_NULL)
    {
        m_head.m_type = kObjectTypeInteger;
        m_qjsValue = JS_NewUint32(nullptr, val);
    }

    V8Integer(int64_t val)
        : V8Value(nullptr, JS_NULL)
    {
        m_head.m_type = kObjectTypeInteger;
        m_qjsValue = JS_NewInt64(nullptr, val);
    }
private:
};

} // miniv8

//////////////////////////////////////////////////////////////////////////

namespace v8 {

template<class To>
static inline To* Utils::toHandle(uintptr_t p)
{
#ifdef _DEBUG
    if ((p & 1) == 0)
        DebugBreak();
#endif
    p &= ~((uintptr_t)1); // https://v8.dev/blog/pointer-compression 去掉低位的1才是真正的指针地址
    return (To*)(void*)p;
}

template<class From, class To>
static inline To* Utils::openHandle(const From* that, bool allowEmptyHandle)
{
    if (!that)
        return nullptr;
    uintptr_t p = *(uintptr_t*)that;
    return toHandle<To>(p);
}

void* Utils::maskPtr(void* obj)
{
    return (void*)((uintptr_t)obj | v8::internal::kSmiTagMask);
}

template<class From, class To>
static inline v8::Local<To> Utils::convert(From* obj)
{
    //return Local<To>(reinterpret_cast<To*>(obj));
    if (!obj)
        return Local<To>(nullptr);

#ifdef _DEBUG
    if (((uintptr_t)obj & 1) == 1)
        DebugBreak();
#endif

    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    void** ret = nullptr;

    miniv8::V8Head* head = (miniv8::V8Head*)obj;
    miniv8ReleaseAssert(
        head->m_type > miniv8::V8ObjectType::kObjectTypeMin && 
        head->m_type < miniv8::V8ObjectType::kObjectTypeMax, "Utils::convert fail\n");

    if (!head->m_isolatHandleScopeIndex) {
        ret = isolate->findHandleScopeEmptyIndex();
        head->m_isolatHandleScopeIndex = ret;
    } else {
        ret = (void**)head->m_isolatHandleScopeIndex;
    }

    //void** ret = isolate->findHandleScopeEmptyIndex();
    *ret = maskPtr(obj);
    
    return Local<To>(reinterpret_cast<To*>(ret));
}

} // v8
