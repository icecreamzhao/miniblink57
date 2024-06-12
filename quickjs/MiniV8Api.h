
// #include "G:/mycode/mininode/node-v8.2.1/deps/v8/include/v8.h"
// #include "G:/mycode/mininode/node-v8.2.1/deps/v8/include/v8-profiler.h"
// #include "G:/mycode/mininode/node-v8.2.1/deps/v8/include/v8-debug.h"
// #include "G:/mycode/mininode/node-v8.2.1/deps/v8/include/v8-inspector.h"
// #include "G:/mycode/mininode/node-v8.2.1/deps/v8/include/libplatform/v8-tracing.h"
// #include "G:/mycode/mininode/node-v8.2.1/deps/v8/include/libplatform/libplatform.h"

#include "G:/mycode/mb_temp/v8_5_7/include/v8.h"
#include "G:/mycode/mb_temp/v8_5_7/include/v8-profiler.h"
#include "G:/mycode/mb_temp/v8_5_7/include/v8-debug.h"
#include "G:/mycode/mb_temp/v8_5_7/include/v8-inspector.h"
#include "G:/mycode/mb_temp/v8_5_7/include/libplatform/v8-tracing.h"
#include "G:/mycode/mb_temp/v8_5_7/include/libplatform/libplatform.h"

#include <windows.h>
#include "g:/mycode/quickjs-master/quickjs.h"
#include <vector>
#include <map>
#include <set>
#include <string>

void printEmptyFuncInfo(const char* fun, bool isBreak);
void miniv8ReleaseAssert(bool b, const char* info);
void miniv8PrintWhenError(JSContext* ctx);
extern "C" void printDebug(const char* format, ...);
#define V8CALL 

namespace v8 {

class Utils {
public:
    template<class From, class To>
    static inline To* openHandle(const From* that, bool allowEmptyHandle = false);

    template<class From, class To>
    static inline Local<To> convert(From* obj);

    static inline void resetPtr(v8::Local<v8::Value> oldObj, void* that);

    template<class To>
    static inline To* toHandle(uintptr_t p);

    static inline void* maskPtr(void* obj);
};

}

namespace miniv8 {

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

enum V8ObjectType : intptr_t {
    kOTMin,
    kOTScript,
    kOTStackTrace,
    kOTContext,

    kOTValue,
    kOTData,
    kOTPrivate,
    kOTPrimitive,
    kOTNumber,
    kOTName,
    kOTBoolean,
    kOTSymbol,
    kOTString,
    kOTAccessorSignature,
    kOTExternal,

    kOTObject,
    kOTArray,
    kOTFunction,
    kOTArrayBuffer,
    kOTArrayBufferView,

    kOTUint8CArray,
    kOTInt8Array,
    kOTUint8Array,
    kOTInt16Array,
    kOTUint16Array,
    kOTInt32Array,
    kOTUint32Array,
#ifdef CONFIG_BIGNUM
    kOTInt64Array,
    kOTUint64Array,
#endif
    kOTFloat32Array,
    kOTFloat64Array,
    
    kOTLastObject = kOTFloat64Array, // �ǵ������������kOTObject���͵�

    kOTPromise,
    kOTResolver,

    kOTInt32,
    kOTUint32,
    kOTInteger,

    kOTLastValue = kOTInteger, // �ǵ������������value���͵�

    kOTTemplate,
    kOTObjectTemplate,
    kOTFunctionTemplate,
    kOTSignature,
    kOTMax
};

class V8Template;

typedef DWORD TlsIndexType;

struct V8Head;
typedef void (*V8HeadRefOrDerefFun)(V8Head* self, bool ref);
typedef void (*V8HeadTraceFun)(void* tracer, V8Head* self);

// ���ṹ�岻������ջ�Ϸ���
struct V8Head {
    V8ObjectType m_type; // ����������ǰ�棬����ʶ������ʲô����
    V8Head* m_next;
    V8Head* m_prev;
    void** m_isolatHandleScopeIndex; // ����v8::HandleScope::CreateHandle
    void** m_isolatGlobalScopeIndex;

    int m_countTest;
    JSValue m_qjsValue;

    intptr_t m_objectGroupId;
    uint16_t m_wrapperClassId;
    uint8_t m_nodeFlag;
    uint8_t m_nodeState;

    V8HeadRefOrDerefFun m_refOrDeref; // ���ص���ʾ��isolate��ժ��������ʱҪôdelete�Լ���Ҫôjs_freeval����������delete
    V8HeadTraceFun m_tracer; // gc��ʱ����������Ⱦɫ

    void* m_weakCallback;
    void* m_weakCallbackParam;

    enum { 
        kIsEternal = 1,
        kIsTemplateInFunction = 1 << 1, 
        kIsSetInternalField = 1 << 2, 
        kIsSetObjectField = 1 << 3,
        kIsRootIndex = 1, // Ĭ�ϵļ���V8Value
    };
    uint8_t m_unGcType; // ���⼸�����͵Ĳ�gc��
    //uint8_t m_isWeak;
    uint8_t m_markGC;
    uint8_t m_isInMember; // 
    uint8_t m_hasCallWeakCallback; // �Ѿ����ù�weak�ص��󣬲������ٽ�������������

    V8Head();
    ~V8Head();

    static void onTrace(void* tracer, V8Head* self);
    static void onTraceHelper(void* tracer, V8Head* self);

    uint8_t getNodeFlag(int shift)
    {
        uint8_t mask = static_cast<uint8_t>(1U << shift);
        return m_nodeFlag & mask;
    }
};

class V8Context;
class V8Value;

class V8Isolate {
public:
    V8Isolate(const v8::Isolate::CreateParams& params);
    ~V8Isolate();

    static V8Isolate* GetCurrent();

    bool isInContext() const;
    void enterContext(V8Context* ctx);
    void exitContext();
    void runGC();
    void runMicrotasks();
    void gcHandleScopeHandles(bool isForce);

    void onHeadDelete(V8Head* head);

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

    V8Context* getCurrentCtx() const;
    JSContext* getCurrentJsCtx() const;
    miniv8::V8Context* getEmptyCtx() const;

    JSRuntime* getRuntime() const { return m_runtime; }

    size_t registerTemplate(V8Template* t);
    V8Template* getTemplateById(size_t id);

    void** findGlobalizeHandleEmptyIndex();
    void** findHandleScopeEmptyIndex();
    void refGlobalizeHandleIndex(intptr_t idx);

    void visitHandlesWithClassIds(v8::PersistentHandleVisitor* visitor);

    void clearErr(JSContext* ctx);
    bool hasErr() const;
    JSValue getErrAndClear();

    void disposeGlobal(void* obj);
    void disposeGlobalImpl(V8Head* head, bool fromRunGlobalWeakCallback);

    void addGCPrologueCallback(v8::Isolate::GCCallback callback, v8::GCType gc_type);
    void addGCEpilogueCallback(v8::Isolate::GCCallback callback, v8::GCType gc_type);
    
    const v8::Isolate::CreateParams& getCreateParams() const { return m_v8CreateParams; }

    static const int kSlotSize = 64 * 10;
    void* m_apiPointer[kSlotSize]; // ����������ǰ�棬v8�Ļ������
    void* m_eternals[kSlotSize]; // ��������Ǵ�Ź̶���v8::Value
    v8::Persistent<v8::Value>* m_eternalsPersistents[kSlotSize];

    enum GcStep {
        kGcStepBeging,
        kGcStepEnd,
    };
   
    GcStep getGcStep() const { return m_gcStep; }

    void addActivedObjectGroupId(intptr_t objectGroupId)
    {
        m_activedObjectGroupId.insert(objectGroupId);
    }

    bool isActivedObjectGroupId(intptr_t objectGroupId) const
    {
        std::set<intptr_t>::const_iterator it = m_activedObjectGroupId.find(objectGroupId);
        return it != m_activedObjectGroupId.end();
    }

    void regContext(V8Context* ctx)
    {
        m_contexts.insert(ctx);
    }

private:
    void freedHeads(JSContext* ctx, bool isFirstCall);
    void runGlobalWeakCallback(V8Head* head);
    void runV8GcCallback(bool isPrologue);

    int getGlobalizeCountHandlesIndex(V8Head* head);
    V8Value* getEternalByIndex(int i);

    friend class v8::Isolate;
    friend struct V8Head;

    const int kHandlesSize = 0x10000;
    std::vector<void*> m_globalizeHandles;
    std::vector<int32_t> m_globalizeCountHandles; // �����Ǹ���������ü���
    int m_globalHandleIndex;

    bool m_isExiting;

    std::vector<void*> m_handleScopeHandles;
    int m_handleScopeHandleIndex;

    std::vector<std::pair<void*, void*>* > m_microtasks; // TODO: ������ʱ��ǵ�ÿ����ɾ��

    std::vector<V8Template*> m_templates; // ���е�ģ�涼ע������������ͷ��ˡ�
    std::set<V8Context*> m_contexts;

    v8::Isolate::GCCallback m_gcPrologueCallback;
    v8::Isolate::GCCallback m_gcEpilogueCallback;

    GcStep m_gcStep;
    JSRuntime* m_runtime;
    std::vector<V8Context*> m_currentCtxs;
    JSValue m_errorVal;

    v8::Isolate::CreateParams m_v8CreateParams;

    miniv8::V8Context* m_emptyContext; // ��ʱ�����ϵͳjs api��ʱ��û��ctx��ֻ�������ctx��
    v8::Persistent<v8::Context> m_emptyContextPersistents;

    std::vector<V8Head*> m_needFreedHeads;
    V8Head* m_gcObjects; // ���з����v8���������������

    friend void V8Head::onTrace(void* tracer, V8Head* self);
    std::set<intptr_t> m_activedObjectGroupId; // ��Щgroup�Ǽ���̬

    static TlsIndexType m_inst;
};

class V8StackTrace {
public:
    V8StackTrace()
    {
        m_head.m_type = kOTStackTrace;
        m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8StackTrace;
    }

    static void onV8HeadRefOrDerefOfV8StackTrace(V8Head* head, bool)
    {
        V8StackTrace* self = (V8StackTrace*)head;
        delete self;
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
    ~V8Context();

    JSContext* ctx() { return m_ctx; }
    V8Isolate* isolate() { return m_isolate; }

    static void onV8HeadRefOrDerefOfV8Context(V8Head* head, bool ref)
    {
        V8Context* self = (V8Context*)head;
        if (!ref)
            delete self;
    }

    static void onV8HeadTraceOfV8Context(void* tracer, V8Head* ptr)
    {
        V8Head::onTrace(tracer, ptr);
    }

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

    static JSContext* getEmptyJsCtx()
    {
        miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
        if (!isolate)
            return nullptr;
        return isolate->getEmptyCtx()->ctx();
    }

    static V8Context* getEmptyCtx()
    {
        miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
        if (!isolate)
            return nullptr;
        return isolate->getEmptyCtx();
    }

    static V8Context* getCurrentOrEmptyCtx()
    {
        V8Context* ctx = getCurrentCtx();
        if (ctx)
            return ctx;
        miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
        if (!isolate)
            return nullptr;
        return isolate->getEmptyCtx();
    }

    static JSContext* getCurrentOrEmptyJsCtx()
    {
        JSContext* ctx = getCurrentJsCtx();
        if (ctx)
            return ctx;
        return getEmptyJsCtx();
    }
    
    bool isCodeGenerationFromStringsAllowed() const { return m_isCodeGenerationFromStringsAllowed; }
    bool isDetachGlobal() const { return m_isDetachGlobal; }

private:
    friend class v8::Context;

    V8Head m_head;
    JSContext* m_ctx;
    V8Isolate* m_isolate;
    bool m_isDetachGlobal;
    bool m_isCodeGenerationFromStringsAllowed;

    std::map<int, void*> m_alignedPointerInEmbedderDatas;
};

// �������麯���������һ���ֶβ���m_type
class V8Data {
public:
    V8Data(V8Context* ctx, JSValue value)
    {
        m_head.m_type = kOTData;
        m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Data;
        m_head.m_tracer = onV8HeadTraceOfV8Data;
        m_ctx = ctx;
        m_head.m_qjsValue = value;
        m_nodeClassId = 0;

        if (ctx && ctx->ctx()) {
            JS_DupValue(ctx->ctx(), value); // TODO:free
        }

        v = V8Data_v;
        m_templId = -1;
        isObject = false;
        isExternal = false;
        isFunciton = false;
    }

    ~V8Data();

    static JSValue V8Data_v(V8Data* self)
    {
        return self->m_head.m_qjsValue;
    }

    // ����������������б�Ķ���Ҫ�������ǵò�Ҫ�ñ�����
    static void onJsUserDataWeakFunc(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step)
    {
        V8Data* self = (V8Data*)userdata;
        delete self;
    }

    static void onV8HeadRefOrDerefOfV8Data(V8Head* head, bool reference)
    {
        JSContext* ctx = V8Context::getCurrentOrEmptyJsCtx();
        V8Data* self = (V8Data*)head;
        if (reference) {
            JS_DupValue(ctx, self->m_head.m_qjsValue);
            return;
        }

        if (JS_VALUE_IS_EQ(self->m_head.m_qjsValue, JS_NULL)) {
            delete self;
            return;
        }
        
        JS_FreeValue(ctx, self->m_head.m_qjsValue); // �������лص���������V8Data
    }

    static void onV8HeadTraceOfV8Data(void* tracer, V8Head* self);

    JSContext* ctx() const
    {
        if (!m_ctx)
            return nullptr;
        return m_ctx->ctx();
    }
    V8Context* v8Ctx() const { return m_ctx; }

    V8Head m_head;
    uint16_t m_nodeClassId;

    void setTemplId(int id) { m_templId = id; }
    int getTemplId() const { return m_templId; }

protected:
    static void onJsUserDataWeakFuncOfV8Data(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step);
    V8Context* m_ctx;

    size_t m_templId; // �����һ��v8::Template����������id�������Ϳ���ʵ��v8::FunctionTemplate::HasInstance

    typedef JSValue(*FN_v)(V8Data* self);

public:
    FN_v v;
    bool isObject;
    bool isExternal;
    bool isFunciton;
};

class V8Value : public V8Data {
public:
    V8Value(V8Context* ctx, JSValue value);
    static V8Value* create(V8Context* ctx, JSValue value);
};

class V8Number : public V8Value {
public:
    V8Number(V8Context* ctx, JSValue value) : V8Value(ctx, value)
    {
        m_head.m_type = kOTNumber;
        m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Number;
    }
    V8Number(double num) : V8Value(nullptr, JS_NULL)
    {
        m_head.m_type = kOTNumber;
        m_head.m_qjsValue = JS_NewFloat64(nullptr, num);
        m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Number;
    }

    static void onV8HeadRefOrDerefOfV8Number(V8Head* head, bool reference)
    {
        V8Number* self = (V8Number*)head;
        if (!reference)
            delete self;
    }
};

class V8Object : public V8Value {
public:
    static V8Object* createFromType(V8Context* ctx, JSValue value, V8ObjectType type);
    static V8Object* create(V8Context* ctx, JSValue value);
    static V8Object* createFromClone(V8Context* ctx, JSValue value);
    ~V8Object();

    static V8Object* getByQjsValue(JSValue value);

    bool SetPrototype(JSContext* ctx, miniv8::V8Value* protoVal);
    v8::Local<v8::Value> GetPrototype();

    // Tag information for Smi.
//     static const int kSmiTag = 0;
//     static const int kSmiTagSize = 1;
//     static const intptr_t kSmiTagMask = (1 << kSmiTagSize) - 1;

    inline static bool IsSmi(void* p) // ��λ��0��ʾ��SMI
    {
        bool b = (((intptr_t)(p) & v8::internal::kSmiTagMask) == v8::internal::kSmiTag);
        return b;
    }

    int getId() const
    {
        return m_id;
    }

    static const int kMaxaAlignedPointerArraySize = 8;

    v8::Maybe<bool> Set(v8::Local<v8::Context> context, v8::Local<v8::Value> key, v8::Local<v8::Value> val, bool force);
private:
    V8Object(V8Context* ctx, JSValue value);
    static void onJsUserDataWeakFuncOfV8Object(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step);
    static void onV8HeadTraceOfV8Object(void* tracer, V8Head* self);
    static void onV8HeadRefOrDerefOfV8Object(V8Head* head, bool reference);

    friend class v8::Object;
    friend class v8::ObjectTemplate;
    friend class v8::FunctionTemplate;
    friend class v8::Function;
    friend class v8::ArrayBuffer;
    friend class V8ArrayBufferView;
    friend class V8Array;
    friend class V8Function;
    friend class V8Isolate;
    friend class V8ArrayBuffer;
    friend class V8Template;
    friend class V8Promise;
    friend class V8Resolver;
    friend class V8FunctionTemplate;
    friend class v8::internal::FunctionCallbackArguments;
    friend class v8::MacroAssembler;

    struct AccessorData {
        std::string name;
        v8::AccessorGetterCallback getter;
        v8::AccessorSetterCallback setter;
        v8::AccessorNameGetterCallback nameGetter;
        v8::AccessorNameSetterCallback nameSetter;
        V8Value* data;
        AccessorData()
        {
            getter = nullptr;
            setter = nullptr;
            nameGetter = nullptr;
            nameSetter = nullptr;
            data = nullptr;
        }
    };

    std::vector<JSCFunctionListEntry>* m_props; // ������������
    std::map<intptr_t, AccessorData*> m_accessorMap;

public:
    void* m_alignedPointerInInternalFields[kMaxaAlignedPointerArraySize];
    int m_internalFieldCount;
    V8Value* m_internalFields[kMaxaAlignedPointerArraySize];
    int m_id;
};

class V8Primitive : public V8Value {
public:
    V8Primitive(V8Context* ctx, JSValue value) : V8Value(ctx, value)
    {
        m_head.m_type = kOTPrimitive;        
    }
};

class V8Boolean : public V8Primitive {
public:
    bool getValue() const
    {
        return JS_ToBool(NULL, m_head.m_qjsValue) == 1;
    }

    V8Boolean(V8Context* ctx, JSValue value) : V8Primitive(ctx, value)
    {
        m_head.m_type = kOTBoolean;
        m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Boolean;
    }

    V8Boolean(bool value) : V8Primitive(NULL, JS_NewBool(NULL, value))
    {
        m_head.m_type = kOTBoolean;
        m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Boolean;
    }
private:
    static void onV8HeadRefOrDerefOfV8Boolean(V8Head* head, bool reference)
    {
        V8Boolean* self = (V8Boolean*)head;
        if (!reference)
            delete self;
    }
};

class V8Name : public V8Primitive {
public:
    V8Name(V8Context* ctx, JSValue value) : V8Primitive(ctx, value)
    {
        m_head.m_type = kOTName;
        m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Name;
    }

    static void onV8HeadRefOrDerefOfV8Name(V8Head* head, bool reference)
    {
        V8Name* self = (V8Name*)head;
        if (!reference)
            delete self;
    }
};

class V8String : public V8Name {
public:
    V8String();
    V8String(const std::string& str);
    V8String(v8::String::ExternalOneByteStringResource* resource);
    V8String(v8::String::ExternalStringResource* resource);
    ~V8String();

    std::string getStr(); // ��������´��һ�����ݣ�����ע�ⲻҪ���ںܳ����ַ�������
    //std::string_view getStrData();
    size_t getStrCount(); // ��ȡ�ַ�����ע�ⲻ���ֽ���

    static JSValue V8String_v(V8Data* self);

    //void ensureQjsVal(V8Context* ctx, bool useEmptyCtx);

protected:
    friend class v8::String;
    friend V8Value* V8Value::create(V8Context* context, JSValue value);

    void init();

    void bindJsValue();

    static void onV8HeadRefOrDerefOfV8String(V8Head* head, bool reference);
    static void onJsUserDataWeakFuncOfV8String(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step);
   
    std::string* m_str;
    size_t m_strCount;

private:
    V8String(V8Context* ctx, JSValue value);
    
    int m_isContainsOnlyOneByte; // 1:true,0:false,-1:uninit

    v8::String::ExternalStringResource* m_twoByteExternalString;
    v8::String::ExternalOneByteStringResource* m_oneByteExternalString;
};

class V8Private : public V8String { // ��ʱ�趨Ϊstring������
public:
//     V8Private(V8Context* ctx, JSValue value) : V8String(ctx, value)
//     {
//         m_head.m_type = kOTPrivate;
//     }

    V8Private() : V8String()
    {
        m_head.m_type = kOTPrivate;
    }

    V8Private(const std::string& str) : V8String(str)
    {
        m_head.m_type = kOTPrivate;
    }
};

class V8Symbol : public V8String { // ��ʱ�趨Ϊstring������
public:
    V8Symbol(const std::string& str);

private:
    static void onV8HeadRefOrDerefOfV8Symbol(V8Head* head, bool ref);
};

class V8AccessorSignature : public V8Data {
public:
    V8AccessorSignature(V8Context* ctx, JSValue value)
        : V8Data(ctx, value)
    {
        m_head.m_type = kOTAccessorSignature;
        m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8AccessorSignature;
    }

    static void onV8HeadRefOrDerefOfV8AccessorSignature(V8Head* head, bool ref)
    {
        V8AccessorSignature* self = (V8AccessorSignature*)head;
        if (!ref)
            delete self;
    }
};

class V8Array : public V8Object {
public:
    V8Array(V8Context* ctx, JSValue value)
        : V8Object(ctx, value)
    {
        m_head.m_type = kOTArray;
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

    V8Function(V8Context* ctx, v8::FunctionCallback callback, v8::Local<v8::Value> data)
        : V8Object(ctx, JS_NULL)
    {
        init();
        m_callback = callback;
        m_data.Reset(v8::Isolate::GetCurrent(), data);
    }

    void init()
    {
        m_head.m_type = kOTFunction;
        m_callback = nullptr;
        isFunciton = true;
        v = V8Function_v;
        m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Function;
        m_head.m_tracer = onV8HeadTraceOfV8Function;
    }

    ~V8Function()
    {
        // TODO: m_signature
        //printDebug("~~V8Function: %p\n", this);
        if (m_head.m_countTest == 1131)
            OutputDebugStringA("");

        m_data.Reset();
        m_signature.Reset();
    }

    // Ϊ���ӳٳ�ʼ��
    static JSValue V8Function_v(V8Data* self);
    std::string getName();
    void setName(const std::string& name);

private:
    static void onJsUserDataWeakFuncOfV8Function(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step);
    static void onV8HeadRefOrDerefOfV8Function(V8Head* head, bool ref);
    static void onV8HeadTraceOfV8Function(void* tracer, V8Head* self);

    friend class v8::Function;
    friend class V8FunctionTemplate;
    friend class v8::internal::FunctionCallbackArguments;

    static JSValue onConstructorCallback(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor);

    v8::FunctionCallback m_callback;
    v8::Persistent<v8::Value> m_data; // ��ʱ���ͷ������ֵ���
    v8::Persistent<v8::Signature> m_signature;
    std::string m_name;
};

class V8External : public V8Value {
public:
    V8External(void* userdata);
    ~V8External();

    void* getUserdata() const { return m_userdata; }

private:
    static JSValue V8External_v(V8Data* ptr);
    void initQjsValue(bool isCheckCtx);
    static void onV8HeadRefOrDerefOfV8External(V8Head* head, bool ref);
    static void onUserDataWeakFuncOfV8External(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step);

    friend class v8::External;
    void* m_userdata;
};

class V8ObjectTemplate;

class V8Signature : public V8Data {
public:
    static V8Signature* create(V8FunctionTemplate* templ);
    int getFuncTemplId() const { return m_funcTemplId; }

private:
    static void onV8HeadRefOrDerefOfV8Signature(V8Head* head, bool ref)
    {
        V8External* self = (V8External*)head;
        if (!ref)
            delete self;
    }
    V8Signature(int funcTemplId);
    int m_funcTemplId;
};

class V8Template : public V8Data {
public:
    V8Template();
    ~V8Template();

    struct Accessor {
        std::string name;
        v8::AccessorGetterCallback getter;
        v8::AccessorSetterCallback setter;

        v8::AccessorNameGetterCallback nameGetter;
        v8::AccessorNameSetterCallback nameSetter;

        v8::FunctionCallback getterFunc; // ��Ҳû��������nameGetterΪɶ���и�getterFunc����v8�����в�ͬ�ķ�������ͨ��v8::Template::SetAccessorProperty
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
    void newTemplateInstance(miniv8::V8Object* obj, bool isSetPrototype);

    size_t getId() const { return m_id; }

    void Set(v8::Local<v8::Name> name, v8::Local<v8::Data> value, v8::PropertyAttribute attr);

    V8Template* getParentTemplate() const
    {
//         v8::Isolate* isolate = v8::Isolate::GetCurrent();
//         v8::Local<v8::Template> templ = m_parentTemplate.Get(isolate);
//         miniv8::V8Template* objTempl = v8::Utils::openHandle<v8::Template, miniv8::V8Template>(*templ);
//         return objTempl;
        return m_parentTemplate;
    }

    V8ObjectTemplate* getInstanceTemplate() const
    {
//         v8::Isolate* isolate = v8::Isolate::GetCurrent();
//         v8::Local<v8::ObjectTemplate> templ = m_instanceTemplate.Get(isolate);
//         miniv8::V8ObjectTemplate* objTempl = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(*templ);
//         return objTempl;
        return m_instanceTemplate;
    }

    V8ObjectTemplate* getPrototypeTemplate() const
    {
//         v8::Isolate* isolate = v8::Isolate::GetCurrent();
//         v8::Local<v8::ObjectTemplate> templ = m_prototypeTemplate.Get(isolate);
//         miniv8::V8ObjectTemplate* objTempl = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(*templ);
// 
//         return objTempl;
        return m_prototypeTemplate;
    }
protected:
    friend class v8::ObjectTemplate;
    friend class v8::FunctionTemplate;
    friend class v8::Template;
    friend class v8::Function;

    static void onV8HeadRefOrDerefOfV8Template(V8Head* head, bool ref);
    static void onV8HeadTraceOfV8Template(void* tracer, V8Head* ptr);
    static void onJsUserDataWeakFuncOfV8Template(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step);

    void destroy();
    bool m_isDestroyed;

    int m_internalFieldCount;
//     v8::Persistent<v8::Template> m_parentTemplate;
//     v8::Persistent<v8::ObjectTemplate> m_instanceTemplate;
//     v8::Persistent<v8::ObjectTemplate> m_prototypeTemplate;
    V8Template* m_parentTemplate;
    V8ObjectTemplate* m_instanceTemplate;
    V8ObjectTemplate* m_prototypeTemplate;

    size_t m_id;

    std::map<std::string, Accessor> m_accessors;
    std::map<std::string, JSValue> m_props;

    v8::IndexedPropertyHandlerConfiguration m_indexedPropHandles;
    v8::NamedPropertyHandlerConfiguration m_namePropHandles;

    miniv8::V8Function* m_funInst;
};

class V8ObjectTemplate : public V8Template {
public:
    V8ObjectTemplate() : V8Template()
    {
        //printDebug("V8ObjectTemplate: %p\n", this);
        m_head.m_type = V8ObjectType::kOTObjectTemplate;
        m_head.m_unGcType = V8Head::kIsTemplateInFunction;
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
        m_head.m_type = kOTFunctionTemplate;
        m_userdata = nullptr;
//         m_instanceTemplate = nullptr;
//         m_prototypeTemplate = nullptr;
        m_argLength = 0;
    }

    ~V8FunctionTemplate()
    {
        // TODO: m_signature
    }
    v8::MaybeLocal<v8::Function> GetFunction(v8::Local<v8::Context> context);
private:
    std::string getClassName();
    void setClassName(const std::string& name);

    v8::FunctionCallback m_constructor;
    void* m_userdata;
    std::string m_name;
    int m_argLength;
    v8::Persistent<v8::Signature> m_signature;
    
    friend class v8::Template;
    friend class v8::ObjectTemplate;
    friend class v8::FunctionTemplate;
    friend class v8::FunctionTemplate;
    friend class V8Value;
    friend class V8Template;
    friend class V8ObjectTemplate;
    static void onCall(const v8::FunctionCallbackInfo<v8::Value>& info);
};

class V8Script {
public:
    V8Script()
    {
        m_head.m_type = kOTScript;
        m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Script;
    }
    void setSource(const std::string& src) { m_src = src; }
    const std::string& getSource() const { return m_src; }

    void setSourceName(const std::string& name) { m_srcName = name; }
    const std::string& getSourceName() const { return m_srcName; }

private:
    static void onV8HeadRefOrDerefOfV8Script(V8Head* head, bool ref)
    {
        V8Script* self = (V8Script*)head;
        if (!ref)
            delete self;
    }

    V8Head m_head;
    std::string m_src;
    std::string m_srcName;
};

class V8UnboundScript {
public:
    V8UnboundScript()
    {
        m_head.m_type = kOTScript;
        m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8UnboundScript;
    }
    void setSource(const std::string& src) { m_src = src; }
    const std::string& getSource() const { return m_src; }

    void setSourceName(const std::string& name) { m_srcName = name; }
    const std::string& getSourceName() const { return m_srcName; }

private:
    static void onV8HeadRefOrDerefOfV8UnboundScript(V8Head* head, bool ref)
    {
        V8UnboundScript* self = (V8UnboundScript*)head;
        if (!ref)
            delete self;
    }

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

class V8ArrayBuffer : public V8Object {
public:
    V8ArrayBuffer(V8Context* ctx, JSValue value)
        : V8Object(ctx, value)
    {
        m_internalFieldCount = 2;
        m_head.m_type = kOTArrayBuffer;
    }

    size_t getByteLength();
    uint8_t* getContents(size_t* size);
};

class V8ArrayBufferView : public V8Object {
public:
    v8::Local<v8::ArrayBuffer> getBuffer();
    size_t getByteOffset();
    size_t getByteLength();
    size_t getEleCount(); // ����Ԫ�ظ�������ʵ�����ֽ�������sizeof(ele)
    size_t getCopyContents(void* dest, size_t byte_length);
    bool hasBuffer() const;

protected:
    friend class V8Object;
    V8ArrayBufferView(V8Context* ctx, JSValue value)
        : V8Object(ctx, value)
    {
        m_internalFieldCount = 2;
        m_head.m_type = kOTArrayBufferView;
    }
};

class V8Int16Array : public V8ArrayBufferView {
public:
    static V8Int16Array* create(V8Context* ctx, JSValue value)
    {
        return (V8Int16Array*)V8Object::createFromType(ctx, value, kOTInt16Array);
    }
private:
    friend class V8Object;
    V8Int16Array(V8Context* ctx, JSValue value)
        : V8ArrayBufferView(ctx, value)
    {
        m_head.m_type = kOTInt16Array;
    }
};

class V8Uint16Array : public V8ArrayBufferView {
public:
    static V8Uint16Array* create(V8Context* ctx, JSValue value)
    {
        return (V8Uint16Array*)V8Object::createFromType(ctx, value, kOTUint16Array);
    }
private:
    friend class V8Object;
    V8Uint16Array(V8Context* ctx, JSValue value)
        : V8ArrayBufferView(ctx, value)
    {
        m_head.m_type = kOTUint16Array;
    }
};

class V8Int32Array : public V8ArrayBufferView {
public:
    static V8Int32Array* create(V8Context* ctx, JSValue value)
    {
        return (V8Int32Array*)V8Object::createFromType(ctx, value, kOTInt32Array);
    }
private:
    friend class V8Object;
    V8Int32Array(V8Context* ctx, JSValue value)
        : V8ArrayBufferView(ctx, value)
    {
        m_head.m_type = kOTInt32Array;
    }
};
class V8Uint32Array : public V8ArrayBufferView {
public:
    static V8Uint32Array* create(V8Context* ctx, JSValue value)
    {
        return (V8Uint32Array*)V8Object::createFromType(ctx, value, kOTUint32Array);
    }
private:
    friend class V8Object;
    V8Uint32Array(V8Context* ctx, JSValue value)
        : V8ArrayBufferView(ctx, value)
    {
        m_head.m_type = kOTUint32Array;
    }
};

class V8Int8Array : public V8ArrayBufferView {
public:
    static V8Int8Array* create(V8Context* ctx, JSValue value)
    {
        return (V8Int8Array*)V8Object::createFromType(ctx, value, kOTInt8Array);
    }
private:
    friend class V8Object;
    V8Int8Array(V8Context* ctx, JSValue value)
        : V8ArrayBufferView(ctx, value)
    {
        m_head.m_type = kOTInt8Array;
    }
};

class V8Uint8Array : public V8ArrayBufferView {
public:
    static V8Uint8Array* create(V8Context* ctx, JSValue value)
    {
        return (V8Uint8Array*)V8Object::createFromType(ctx, value, kOTUint8Array);
    }
private:
    friend class V8Object;
    V8Uint8Array(V8Context* ctx, JSValue value)
        : V8ArrayBufferView(ctx, value)
    {
        m_head.m_type = kOTUint8Array;
    }
};

class V8Uint8ClampedArray : public V8ArrayBufferView {
public:
    static V8Uint8ClampedArray* create(V8Context* ctx, JSValue value)
    {
        return (V8Uint8ClampedArray*)V8Object::createFromType(ctx, value, kOTUint8CArray);
    }
private:
    friend class V8Object;
    V8Uint8ClampedArray(V8Context* ctx, JSValue value)
        : V8ArrayBufferView(ctx, value)
    {
        m_head.m_type = kOTUint8CArray;
    }
};

class V8Float32Array : public V8ArrayBufferView {
public:
    static V8Float32Array* create(V8Context* ctx, JSValue value)
    {
        return (V8Float32Array*)V8Object::createFromType(ctx, value, kOTFloat32Array);
    }
private:
    friend class V8Object;
    V8Float32Array(V8Context* ctx, JSValue value)
        : V8ArrayBufferView(ctx, value)
    {
        m_head.m_type = kOTFloat32Array;
    }
};

class V8Float64Array : public V8ArrayBufferView {
public:
    static V8Float64Array* create(V8Context* ctx, JSValue value)
    {
        return (V8Float64Array*)V8Object::createFromType(ctx, value, kOTFloat64Array);
    }
private:
    friend class V8Object;
    V8Float64Array(V8Context* ctx, JSValue value)
        : V8ArrayBufferView(ctx, value)
    {
        m_head.m_type = kOTFloat64Array;
    }
};

class V8Integer : public V8Value {
public:
    V8Integer(int32_t val)
        : V8Value(nullptr, JS_NULL)
    {
        m_head.m_type = kOTInteger;
        m_head.m_qjsValue = JS_NewInt32(nullptr, val);
        m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Integer;
    }

    V8Integer(uint32_t val)
        : V8Value(nullptr, JS_NULL)
    {
        m_head.m_type = kOTInteger;
        m_head.m_qjsValue = JS_NewUint32(nullptr, val);
        m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Integer;
    }

    V8Integer(int64_t val)
        : V8Value(nullptr, JS_NULL)
    {
        m_head.m_type = kOTInteger;
        m_head.m_qjsValue = JS_NewInt64(nullptr, val);
        m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Integer;
    }
private:
    static void onV8HeadRefOrDerefOfV8Integer(V8Head* head, bool ref)
    {
        V8Integer* self = (V8Integer*)head;
        if (!ref)
            delete self;
    }
};

class V8Int32 : public V8Integer {
public:
    int32_t getValue() const
    {
        int32_t res = 0;
        if (JS_ToInt32(NULL, &res, m_head.m_qjsValue) >= 0)
            return res;
        return 0;
    }

    V8Int32(int32_t value) : V8Integer(value)
    {
        m_head.m_type = kOTInt32;
    }
private:
};

class V8Uint32 : public V8Integer {
public:
    int32_t getValue() const
    {
        int32_t res = 0;
        if (JS_ToInt32(NULL, &res, m_head.m_qjsValue) >= 0)
            return res;
        return 0;
    }

    V8Uint32(uint32_t value) : V8Integer(value)
    {
        m_head.m_type = kOTUint32;
    }
private:
};

class V8Promise : public V8Object {
public:
    ~V8Promise();
    static V8Promise* create(V8Context* ctx, JSValue value);

protected:
private:
    friend class V8Resolver;
    friend class v8::Promise::Resolver;
    friend class V8Object;

    V8Promise(V8Context* ctx, JSValue value);
    static void onJsUserDataWeakFuncOfV8Promise(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step);
    static void onV8HeadRefOrDerefOfV8Promise(V8Head* head, bool ref);

    JSValue m_resolvingFuncs[2];
};

class V8Resolver : public V8Object {
public:
    ~V8Resolver();

protected:
private:
    friend class v8::Promise;
    friend class v8::Promise::Resolver;
    friend class V8Object;
    V8Resolver(V8Context* ctx, JSValue value);

    static void onJsUserDataWeakFuncOfV8Resolver(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step);
    static void onV8HeadRefOrDerefOfV8Resolver(V8Head* head, bool ref);
    static void onV8HeadTraceOfV8Resolver(void* tracer, V8Head* ptr);

    V8Promise* m_promise;
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
    p &= ~((uintptr_t)1); // https://v8.dev/blog/pointer-compression ȥ����λ��1����������ָ���ַ
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

inline void Utils::resetPtr(v8::Local<v8::Value> oldObj, void* thatPtr)
{
    miniv8::V8Head* that = (miniv8::V8Head*)thatPtr;
    void* ptr = (void*)(*oldObj);
    miniv8::V8Head* head = openHandle<v8::Value, miniv8::V8Head>((const v8::Value*)ptr);
    miniv8ReleaseAssert(
        !that->m_isolatGlobalScopeIndex &&
        (head->m_isolatGlobalScopeIndex) &&
        (head->m_type > miniv8::V8ObjectType::kOTMin && head->m_type < miniv8::V8ObjectType::kOTMax),
        "Utils::resetPtr fail\n");

    int refCount1 = JS_GetRefCount(NULL, head->m_qjsValue);
    int refCount2 = JS_GetRefCount(NULL, that->m_qjsValue);

    void** indexPtr = (void**)head->m_isolatGlobalScopeIndex;
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    isolate->disposeGlobal(ptr);

    that->m_isolatGlobalScopeIndex = indexPtr;
    *indexPtr = maskPtr(that);

    head->m_isolatGlobalScopeIndex = nullptr;

    printDebug("Utils::resetPtr: %p %p %p\n", indexPtr, that, *indexPtr);
}

template<class From, class To>
static inline v8::Local<To> Utils::convert(From* obj)
{
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
        head->m_type > miniv8::V8ObjectType::kOTMin && 
        head->m_type < miniv8::V8ObjectType::kOTMax, "Utils::convert fail\n");

    if (!head->m_isolatHandleScopeIndex) {
        ret = isolate->findHandleScopeEmptyIndex();
        head->m_isolatHandleScopeIndex = ret;
    } else {
        ret = (void**)head->m_isolatHandleScopeIndex;
    }

    *ret = maskPtr(obj);
    
    return Local<To>(reinterpret_cast<To*>(ret));
}

class MacroAssembler { // Ϊ���ܷ���v8::PropertyCallbackInfo��˽�б��������ò�����MacroAssembler
public:
    static JSValue objectTemplateNameGetter(JSContext* ctx, JSValueConst thisVal, void* userdata);
    static JSValue objectTemplateNameSetter(JSContext* ctx, JSValueConst thisVal, JSValueConst val, void* userdata);

    static JSValue onIndexHandle(JSContext* ctx, JSValueConst thisVal, int32_t index, void* userdata);
    static JSValue onNamePropertyGet(JSContext* ctx, JSValueConst this_val, JSAtom prop, void* userdata);
    static JS_BOOL onNamePropertySet(JSContext* ctx, JSValueConst this_val, JSAtom prop, JSValueConst val, void* userdata);
    static int onNamePropertyQuery(JSContext* ctx, JSValueConst this_val, JSAtom prop, void* userdata);

    static JSValue wrapGetter(JSContext* ctx, JSValueConst thisVal, void* userdata);
    static JSValue wrapSetter(JSContext* ctx, JSValueConst thisVal, JSValueConst val, void* userdata);

    void* stub;
};

} // v8
