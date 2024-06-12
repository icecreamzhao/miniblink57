
#include "node_buffer.h"
#include "node_object_wrap.h"
#include <limits.h> // INT_MAX
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <memory>
#define NAPI_EXPERIMENTAL
#include "node/nodeblink.h"
#include "node_api.h"
#include "node_internals.h"
#include "env.h"
#include "env-inl.h"
#include "base-object-inl.h"
#include "node/uv/include/uv.h"

// using v8::Isolate;
// using v8::Local;
// using v8::Object;

namespace node {

template <typename T>
struct ResetInDestructorPersistentTraits {
    static const bool kResetInDestructor = true;
    template <typename S, typename M>
    // Disallow copy semantics by leaving this unimplemented.
    inline static void Copy(
        const v8::Persistent<S, M>&,
        v8::Persistent<T, ResetInDestructorPersistentTraits<T>>*);
};

// v8::Persistent does not reset the object slot in its destructor.  That is
// acknowledged as a flaw in the V8 API and expected to change in the future
// but for now node::Persistent is the easier and safer alternative.
template <typename T>
using Persistent = v8::Persistent<T, ResetInDestructorPersistentTraits<T>>;

class InternalCallbackScope;

typedef double async_id;
struct async_context {
    async_context()
    {
        async_id = -1;
        trigger_async_id = -1;
    }
    double async_id;
    double trigger_async_id;
};

/* This class works like `MakeCallback()` in that it sets up a specific
* asyncContext as the current one and informs the async_hooks and domains
* modules that this context is currently active.
*
* `MakeCallback()` is a wrapper around this class as well as
* `Function::Call()`. Either one of these mechanisms needs to be used for
* top-level calls into JavaScript (i.e. without any existing JS stack).
*
* This object should be stack-allocated to ensure that it is contained in a
* valid HandleScope.
*
* Exceptions happening within this scope will be treated like uncaught
* exceptions. If this behaviour is undesirable, a new `v8::TryCatch` scope
* needs to be created inside of this scope.
*/

class NODE_EXTERN CallbackScope {
public:
    CallbackScope(v8::Isolate* isolate, v8::Local<v8::Object> resource, async_context asyncContext);
    ~CallbackScope();

private:
    InternalCallbackScope* private_;
    v8::TryCatch try_catch_;

    void operator=(const CallbackScope&) = delete;
    void operator=(CallbackScope&&) = delete;
    CallbackScope(const CallbackScope&) = delete;
    CallbackScope(CallbackScope&&) = delete;
};

class InternalCallbackScope {
public:
    // Tell the constructor whether its `object` parameter may be empty or not.
    enum ResourceExpectation { kRequireResource,
        kAllowEmptyResource };
    InternalCallbackScope(Environment* env,
        v8::Local<v8::Object> object,
        const async_context& asyncContext,
        ResourceExpectation expect = kRequireResource);
    // Utility that can be used by AsyncWrap classes.
    explicit InternalCallbackScope(node::AsyncWrap* async_wrap);
    ~InternalCallbackScope();
    void Close();

    inline bool Failed() const { return failed_; }
    inline void MarkAsFailed() { failed_ = true; }

private:
    Environment* env_;
    async_context async_context_;
    v8::Local<v8::Object> object_;
    //Environment::AsyncCallbackScope callback_scope_;
    bool failed_ = false;
    bool pushed_ids_ = false;
    bool closed_ = false;
};

using AsyncHooks = Environment::AsyncHooks;

CallbackScope::CallbackScope(v8::Isolate* isolate,
    v8::Local<v8::Object> object,
    async_context asyncContext)
    : private_(new InternalCallbackScope(
        //         Environment::GetCurrent(isolate),
        nullptr,
        object,
        asyncContext))
    , try_catch_(isolate)
{
    try_catch_.SetVerbose(true);
}

CallbackScope::~CallbackScope()
{
    if (try_catch_.HasCaught())
        private_->MarkAsFailed();
    delete private_;
}

InternalCallbackScope::InternalCallbackScope(AsyncWrap* async_wrap)
    : InternalCallbackScope(
        async_wrap->env(),
        async_wrap->object(),
        async_context()
        // { async_wrap->get_async_id(), async_wrap->get_trigger_async_id() }
    )
{
}

InternalCallbackScope::InternalCallbackScope(Environment* env,
    v8::Local<v8::Object> object,
    const async_context& asyncContext,
    ResourceExpectation expect)
    : env_(env)
    , async_context_(asyncContext)
    , object_(object)
//callback_scope_(env)
{
    //     NODE_CHECK_IMPLIES(expect == kRequireResource, !object.IsEmpty());
    //     NODE_CHECK_NOT_NULL(env);
    //
    //     if (!env->can_call_into_js()) {
    //         failed_ = true;
    //         return;
    //     }
    //
    //     v8::HandleScope handle_scope(env->isolate());
    //     // If you hit this NODE_ASSERTion, you forgot to enter the v8::Context first.
    //     NODE_CHECK_EQ(Environment::GetCurrent(env->isolate()), env);
    //
    //     if (asyncContext.async_id != 0) {
    //         // No need to check a return value because the application will exit if
    //         // an exception occurs.
    //         AsyncWrap::EmitBefore(env, asyncContext.async_id);
    //     }
    //
    //     NODE_CHECK_GE(env->makecallback_depth(), 1);
    //     if (env->makecallback_depth() == 1) {
    //         env->tick_info()->set_has_thrown(false);
    //     }
    //
    //     env->async_hooks()->push_async_ids(async_context_.async_id, async_context_.trigger_async_id);
    //     pushed_ids_ = true;
}

InternalCallbackScope::~InternalCallbackScope()
{
    Close();
}

void InternalCallbackScope::Close()
{
    //     if (closed_)
    //         return;
    //     closed_ = true;
    //     v8::HandleScope handle_scope(env_->isolate());
    //
    //     if (!env_->can_call_into_js()) return;
    //     if (failed_ && !env_->is_main_thread() && env_->is_stopping_worker()) {
    //         env_->async_hooks()->clear_async_id_stack();
    //     }
    //
    //     if (pushed_ids_)
    //         env_->async_hooks()->pop_async_id(async_context_.async_id);
    //
    //     if (failed_) return;
    //
    //     if (async_context_.async_id != 0) {
    //         AsyncWrap::EmitAfter(env_, async_context_.async_id);
    //     }
    //
    //     if (env_->makecallback_depth() > 1) {
    //         return;
    //     }
    //
    //     Environment::TickInfo* tick_info = env_->tick_info();
    //
    //     if (!env_->can_call_into_js()) return;
    //     if (!tick_info->has_scheduled()) {
    //         env_->isolate()->RunMicrotasks();
    //     }
    //
    //     // Make sure the stack unwound properly. If there are nested MakeCallback's
    //     // then it should return early and not reach this code.
    //     if (env_->async_hooks()->fields()[AsyncHooks::kTotals]) {
    //         NODE_CHECK_EQ(env_->execution_async_id(), 0);
    //         NODE_CHECK_EQ(env_->trigger_async_id(), 0);
    //     }
    //
    //     if (!tick_info->has_scheduled() && !tick_info->has_promise_rejections()) {
    //         return;
    //     }
    //
    //     Local<Object> process = env_->process_object();
    //
    //     if (!env_->can_call_into_js()) return;
    //
    //     if (env_->tick_callback_function()->Call(process, 0, nullptr).IsEmpty()) {
    //         env_->tick_info()->set_has_thrown(true);
    //         failed_ = true;
    //     }
}

NODE_EXTERN async_context EmitAsyncInit(v8::Isolate* isolate,
    v8::Local<v8::Object> resource,
    const char* name,
    async_id trigger_async_id = -1)
{
    //DebugBreak();
    async_context ret;
    return ret;
}

NODE_EXTERN async_context EmitAsyncInit(v8::Isolate* isolate,
    v8::Local<v8::Object> resource,
    v8::Local<v8::String> name,
    async_id trigger_async_id = -1)
{
    //DebugBreak();
    async_context ret;
    return ret;
}

/* Helper class users can optionally inherit from. If
* `AsyncResource::MakeCallback()` is used, then all four callbacks will be
* called automatically. */
class AsyncResource {
public:
    AsyncResource(v8::Isolate* isolate,
        v8::Local<v8::Object> resource,
        const char* name,
        async_id trigger_async_id = -1)
        : isolate_(isolate)
        , resource_(isolate, resource)
    {
        async_context_ = EmitAsyncInit(isolate, resource, name, trigger_async_id);
    }

    AsyncResource(v8::Isolate* isolate,
        v8::Local<v8::Object> resource,
        v8::Local<v8::String> name,
        async_id trigger_async_id = -1)
        : isolate_(isolate)
        , resource_(isolate, resource)
    {
        //async_context_ = EmitAsyncInit(isolate, resource, name, trigger_async_id);
        DebugBreak();
    }

    virtual ~AsyncResource()
    {
        //EmitAsyncDestroy(isolate_, async_context_);
        DebugBreak();
        resource_.Reset();
    }

    v8::MaybeLocal<v8::Value> MakeCallback(
        v8::Local<v8::Function> callback,
        int argc,
        v8::Local<v8::Value>* argv)
    {
        return node::MakeCallback(isolate_, get_resource(),
            callback, argc, argv
            //, async_context_
        );
    }

    v8::MaybeLocal<v8::Value> MakeCallback(
        const char* method,
        int argc,
        v8::Local<v8::Value>* argv)
    {
        return node::MakeCallback(isolate_, get_resource(),
            method, argc, argv
            //, async_context_
        );
    }

    v8::MaybeLocal<v8::Value> MakeCallback(
        v8::Local<v8::String> symbol,
        int argc,
        v8::Local<v8::Value>* argv)
    {
        return node::MakeCallback(isolate_, get_resource(),
            symbol, argc, argv
            //, async_context_
        );
    }

    v8::Local<v8::Object> get_resource()
    {
        return resource_.Get(isolate_);
    }

    async_id get_async_id() const
    {
        return async_context_.async_id;
    }

    async_id get_trigger_async_id() const
    {
        return async_context_.trigger_async_id;
    }

protected:
    class CallbackScope : public node::CallbackScope {
    public:
        explicit CallbackScope(AsyncResource* res)
            : node::CallbackScope(res->isolate_,
                res->resource_.Get(res->isolate_),
                res->async_context_)
        {
        }
    };

private:
    v8::Isolate* isolate_;
    v8::Persistent<v8::Object> resource_;
    async_context async_context_;
};

class ThreadPoolWork {
public:
    explicit inline ThreadPoolWork(Environment* env)
        : env_(env)
    {
        //NODE_CHECK_NOT_NULL(env);
    }
    inline virtual ~ThreadPoolWork() = default;

    inline void ScheduleWork();
    inline int CancelWork();

    virtual void DoThreadPoolWork() = 0;
    virtual void AfterThreadPoolWork(int status) = 0;

private:
    Environment* env_;
    uv_work_t work_req_;
};

void ThreadPoolWork::ScheduleWork()
{
    //env_->IncreaseWaitingRequestCounter();
    int status = uv_queue_work(
        env_->event_loop(),
        &work_req_,
        [](uv_work_t* req) {
            ThreadPoolWork* self = ContainerOf(&ThreadPoolWork::work_req_, req);
            self->DoThreadPoolWork();
        },
        [](uv_work_t* req, int status) {
            ThreadPoolWork* self = ContainerOf(&ThreadPoolWork::work_req_, req);
            //self->env_->DecreaseWaitingRequestCounter();
            self->AfterThreadPoolWork(status);
        });
    NODE_CHECK_EQ(status, 0);
}

int ThreadPoolWork::CancelWork()
{
    return uv_cancel(reinterpret_cast<uv_req_t*>(&work_req_));
}

} // namespace node

static napi_status napi_set_last_error(napi_env env, napi_status error_code,
    uint32_t engine_error_code = 0,
    void* engine_reserved = nullptr);
static napi_status napi_clear_last_error(napi_env env);

struct napi_env__ {
    explicit napi_env__(v8::Isolate* _isolate, uv_loop_t* _loop)
        : isolate(_isolate)
        , last_error()
        , loop(_loop)
    {
    }
    v8::Isolate* isolate;
    node::Persistent<v8::Value> last_exception;
    napi_extended_error_info last_error;
    int open_handle_scopes = 0;
    int open_callback_scopes = 0;
    uv_loop_t* loop = nullptr;

    void* instance_data = nullptr;
    napi_finalize finalize_cb = nullptr;
    void* finalize_hint = nullptr;
};

#define NAPI_PRIVATE_KEY(context, suffix) \
    (node::Environment::GetCurrent((context))->napi_##suffix())

#define RETURN_STATUS_IF_FALSE(env, condition, status)   \
    do {                                                 \
        if (!(condition)) {                              \
            return napi_set_last_error((env), (status)); \
        }                                                \
    } while (0)

#define NODE_CHECK_ENV(env)          \
    do {                             \
        if ((env) == nullptr) {      \
            return napi_invalid_arg; \
        }                            \
    } while (0)

#define NODE_CHECK_ARG(env, arg) \
    RETURN_STATUS_IF_FALSE((env), ((arg) != nullptr), napi_invalid_arg)

#define NODE_CHECK_MAYBE_EMPTY(env, maybe, status) \
    RETURN_STATUS_IF_FALSE((env), !((maybe).IsEmpty()), (status))

#define NODE_CHECK_MAYBE_NOTHING(env, maybe, status) \
    RETURN_STATUS_IF_FALSE((env), !((maybe).IsNothing()), (status))

// NAPI_PREAMBLE is not wrapped in do..while: try_catch must have function scope
#define NAPI_PREAMBLE(env)                                         \
    NODE_CHECK_ENV((env));                                         \
    RETURN_STATUS_IF_FALSE((env), (env)->last_exception.IsEmpty(), \
        napi_pending_exception);                                   \
    napi_clear_last_error((env));                                  \
    v8impl::TryCatch try_catch((env))

#define NODE_CHECK_TO_TYPE(env, type, context, result, src, status)               \
    do {                                                                          \
        NODE_CHECK_ARG((env), (src));                                             \
        auto maybe = v8impl::V8LocalValueFromJsValue((src))->To##type((context)); \
        NODE_CHECK_MAYBE_EMPTY((env), maybe, (status));                           \
        (result) = maybe.ToLocalChecked();                                        \
    } while (0)

#define NODE_CHECK_TO_FUNCTION(env, result, src)                                \
    do {                                                                        \
        NODE_CHECK_ARG((env), (src));                                           \
        v8::Local<v8::Value> v8value = v8impl::V8LocalValueFromJsValue((src));  \
        RETURN_STATUS_IF_FALSE((env), v8value->IsFunction(), napi_invalid_arg); \
        (result) = v8value.As<v8::Function>();                                  \
    } while (0)

#define NODE_CHECK_TO_OBJECT(env, context, result, src) \
    NODE_CHECK_TO_TYPE((env), Object, (context), (result), (src), napi_object_expected)

#define NODE_CHECK_TO_STRING(env, context, result, src) \
    NODE_CHECK_TO_TYPE((env), String, (context), (result), (src), napi_string_expected)

#define NODE_CHECK_TO_NUMBER(env, context, result, src) \
    NODE_CHECK_TO_TYPE((env), Number, (context), (result), (src), napi_number_expected)

#define NODE_CHECK_TO_BOOL(env, context, result, src)              \
    NODE_CHECK_TO_TYPE((env), Boolean, (context), (result), (src), \
        napi_boolean_expected)

// n-api defines NAPI_AUTO_LENGHTH as the indicator that a string
// is null terminated. For V8 the equivalent is -1. The NODE_ASSERT
// validates that our cast of NAPI_AUTO_LENGTH results in -1 as
// needed by V8.
#define NODE_CHECK_NEW_FROM_UTF8_LEN(env, result, str, len)             \
    do {                                                                \
        static_assert(static_cast<int>(NAPI_AUTO_LENGTH) == -1,         \
            "Casting NAPI_AUTO_LENGTH to int must result in -1");       \
        RETURN_STATUS_IF_FALSE((env),                                   \
            (len == NAPI_AUTO_LENGTH) || len <= INT_MAX,                \
            napi_invalid_arg);                                          \
        auto str_maybe = v8::String::NewFromUtf8(                       \
            (env)->isolate, (str), v8::NewStringType::kInternalized,    \
            static_cast<int>(len));                                     \
        NODE_CHECK_MAYBE_EMPTY((env), str_maybe, napi_generic_failure); \
        (result) = str_maybe.ToLocalChecked();                          \
    } while (0)

#define NODE_CHECK_NEW_FROM_UTF8(env, result, str) \
    NODE_CHECK_NEW_FROM_UTF8_LEN((env), (result), (str), NAPI_AUTO_LENGTH)

#define GET_RETURN_STATUS(env)        \
    (!try_catch.HasCaught() ? napi_ok \
                            : napi_set_last_error((env), napi_pending_exception))

#define THROW_RANGE_ERROR_IF_FALSE(env, condition, error, message)   \
    do {                                                             \
        if (!(condition)) {                                          \
            napi_throw_range_error((env), (error), (message));       \
            return napi_set_last_error((env), napi_generic_failure); \
        }                                                            \
    } while (0)

#define CREATE_TYPED_ARRAY(                                                                                     \
    env, type, size_of_element, buffer, byte_offset, length, out)                                               \
    do {                                                                                                        \
        if ((size_of_element) > 1) {                                                                            \
            THROW_RANGE_ERROR_IF_FALSE(                                                                         \
                (env), (byte_offset) % (size_of_element) == 0,                                                  \
                "ERR_NAPI_INVALID_TYPEDARRAY_ALIGNMENT",                                                        \
                "start offset of " #type " should be a multiple of " #size_of_element);                         \
        }                                                                                                       \
        THROW_RANGE_ERROR_IF_FALSE((env), (length) * (size_of_element) + (byte_offset) <= buffer->ByteLength(), \
            "ERR_NAPI_INVALID_TYPEDARRAY_LENGTH",                                                               \
            "Invalid typed array length");                                                                      \
        (out) = v8::type::New((buffer), (byte_offset), (length));                                               \
    } while (0)

#define NAPI_CALL_INTO_MODULE(env, call, handle_exception)                         \
    do {                                                                           \
        int open_handle_scopes = (env)->open_handle_scopes;                        \
        int open_callback_scopes = (env)->open_callback_scopes;                    \
        napi_clear_last_error((env));                                              \
        call;                                                                      \
        NODE_CHECK_EQ((env)->open_handle_scopes, open_handle_scopes);              \
        NODE_CHECK_EQ((env)->open_callback_scopes, open_callback_scopes);          \
        if (!(env)->last_exception.IsEmpty()) {                                    \
            handle_exception(                                                      \
                v8::Local<v8::Value>::New((env)->isolate, (env)->last_exception)); \
            (env)->last_exception.Reset();                                         \
        }                                                                          \
    } while (0)

#define NAPI_CALL_INTO_MODULE_THROW(env, call) \
    NAPI_CALL_INTO_MODULE((env), call, (env)->isolate->ThrowException)

void napi_module_register_by_symbol(v8::Local<v8::Object> exports,
    v8::Local<v8::Value> module,
    v8::Local<v8::Context> context,
    napi_addon_register_func init);

namespace {
namespace v8impl {

    // convert from n-api property attributes to v8::PropertyAttribute
    static inline v8::PropertyAttribute V8PropertyAttributesFromDescriptor(
        const napi_property_descriptor* descriptor)
    {
        unsigned int attribute_flags = v8::PropertyAttribute::None;

        if (descriptor->getter != nullptr || descriptor->setter != nullptr) {
            // The napi_writable attribute is ignored for accessor descriptors, but
            // V8 requires the ReadOnly attribute to match nonexistence of a setter.
            attribute_flags |= (descriptor->setter == nullptr ? v8::PropertyAttribute::ReadOnly : v8::PropertyAttribute::None);
        } else if ((descriptor->attributes & napi_writable) == 0) {
            attribute_flags |= v8::PropertyAttribute::ReadOnly;
        }

        if ((descriptor->attributes & napi_enumerable) == 0) {
            attribute_flags |= v8::PropertyAttribute::DontEnum;
        }
        if ((descriptor->attributes & napi_configurable) == 0) {
            attribute_flags |= v8::PropertyAttribute::DontDelete;
        }

        return static_cast<v8::PropertyAttribute>(attribute_flags);
    }

    class HandleScopeWrapper {
    public:
        explicit HandleScopeWrapper(v8::Isolate* isolate)
            : scope(isolate)
        {
        }

    private:
        v8::HandleScope scope;
    };

    // In node v0.10 version of v8, there is no EscapableHandleScope and the
    // node v0.10 port use HandleScope::Close(Local<T> v) to mimic the behavior
    // of a EscapableHandleScope::Escape(Local<T> v), but it is not the same
    // semantics. This is an example of where the api abstraction fail to work
    // across different versions.
    class EscapableHandleScopeWrapper {
    public:
        explicit EscapableHandleScopeWrapper(v8::Isolate* isolate)
            : scope(isolate)
            , escape_called_(false)
        {
        }
        bool escape_called() const
        {
            return escape_called_;
        }
        template <typename T>
        v8::Local<T> Escape(v8::Local<T> handle)
        {
            escape_called_ = true;
            return scope.Escape(handle);
        }

    private:
        v8::EscapableHandleScope scope;
        bool escape_called_;
    };

    static napi_handle_scope JsHandleScopeFromV8HandleScope(HandleScopeWrapper* s)
    {
        return reinterpret_cast<napi_handle_scope>(s);
    }

    static HandleScopeWrapper* V8HandleScopeFromJsHandleScope(napi_handle_scope s)
    {
        return reinterpret_cast<HandleScopeWrapper*>(s);
    }

    static napi_escapable_handle_scope JsEscapableHandleScopeFromV8EscapableHandleScope(
        EscapableHandleScopeWrapper* s)
    {
        return reinterpret_cast<napi_escapable_handle_scope>(s);
    }

    static EscapableHandleScopeWrapper*
    V8EscapableHandleScopeFromJsEscapableHandleScope(
        napi_escapable_handle_scope s)
    {
        return reinterpret_cast<EscapableHandleScopeWrapper*>(s);
    }

    static napi_callback_scope JsCallbackScopeFromV8CallbackScope(
        node::CallbackScope* s)
    {
        return reinterpret_cast<napi_callback_scope>(s);
    }

    static node::CallbackScope* V8CallbackScopeFromJsCallbackScope(
        napi_callback_scope s)
    {
        return reinterpret_cast<node::CallbackScope*>(s);
    }

    //=== Conversion between V8 Handles and napi_value ========================

    // This NODE_ASSERTs v8::Local<> will always be implemented with a single
    // pointer field so that we can pass it around as a void*.
    static_assert(sizeof(v8::Local<v8::Value>) == sizeof(napi_value),
        "Cannot convert between v8::Local<v8::Value> and napi_value");

    static napi_deferred JsDeferredFromNodePersistent(node::Persistent<v8::Value>* local)
    {
        return reinterpret_cast<napi_deferred>(local);
    }

    static node::Persistent<v8::Value>* NodePersistentFromJsDeferred(napi_deferred local)
    {
        return reinterpret_cast<node::Persistent<v8::Value>*>(local);
    }

    static napi_value JsValueFromV8LocalValue(v8::Local<v8::Value> local)
    {
        return reinterpret_cast<napi_value>(*local);
    }

    static v8::Local<v8::Value> V8LocalValueFromJsValue(napi_value v)
    {
        v8::Local<v8::Value> local;
        memcpy(&local, &v, sizeof(v));
        return local;
    }

    static inline void trigger_fatal_exception(
        napi_env env, v8::Local<v8::Value> local_err)
    {
        //             v8::Local<v8::Message> local_msg = v8::Exception::CreateMessage(env->isolate, local_err);
        //             node::FatalException(env->isolate, local_err, local_msg);
        DebugBreak(); // weolar TODO
    }

    static inline napi_status V8NameFromPropertyDescriptor(napi_env env,
        const napi_property_descriptor* p,
        v8::Local<v8::Name>* result)
    {
        if (p->utf8name != nullptr) {
            NODE_CHECK_NEW_FROM_UTF8(env, *result, p->utf8name);
        } else {
            v8::Local<v8::Value> property_value = v8impl::V8LocalValueFromJsValue(p->name);

            RETURN_STATUS_IF_FALSE(env, property_value->IsName(), napi_name_expected);
            *result = property_value.As<v8::Name>();
        }

        return napi_ok;
    }

    // Adapter for napi_finalize callbacks.
    class Finalizer {
    protected:
        Finalizer(napi_env env,
            napi_finalize finalize_callback,
            void* finalize_data,
            void* finalize_hint)
            : _env(env)
            , _finalize_callback(finalize_callback)
            , _finalize_data(finalize_data)
            , _finalize_hint(finalize_hint)
        {
        }

        ~Finalizer()
        {
        }

    public:
        static Finalizer* New(napi_env env,
            napi_finalize finalize_callback = nullptr,
            void* finalize_data = nullptr,
            void* finalize_hint = nullptr)
        {
            return new Finalizer(
                env, finalize_callback, finalize_data, finalize_hint);
        }

        static void Delete(Finalizer* finalizer)
        {
            delete finalizer;
        }

        // node::Buffer::FreeCallback
        static void FinalizeBufferCallback(char* data, void* hint)
        {
            Finalizer* finalizer = static_cast<Finalizer*>(hint);
            if (finalizer->_finalize_callback != nullptr) {
                NAPI_CALL_INTO_MODULE_THROW(finalizer->_env,
                    finalizer->_finalize_callback(
                        finalizer->_env,
                        data,
                        finalizer->_finalize_hint));
            }

            Delete(finalizer);
        }

    protected:
        napi_env _env;
        napi_finalize _finalize_callback;
        void* _finalize_data;
        void* _finalize_hint;
    };

    // Wrapper around node::Persistent that implements reference counting.
    class Reference : private Finalizer {
    private:
        Reference(napi_env env,
            v8::Local<v8::Value> value,
            uint32_t initial_refcount,
            bool delete_self,
            napi_finalize finalize_callback,
            void* finalize_data,
            void* finalize_hint)
            : Finalizer(env, finalize_callback, finalize_data, finalize_hint)
            , _persistent(env->isolate, value)
            , _refcount(initial_refcount)
            , _delete_self(delete_self)
        {
            if (initial_refcount == 0) {
                _persistent.SetWeak(
                    this, FinalizeCallback, v8::WeakCallbackType::kParameter);
            }
        }

    public:
        void* Data()
        {
            return _finalize_data;
        }

        static Reference* New(napi_env env,
            v8::Local<v8::Value> value,
            uint32_t initial_refcount,
            bool delete_self,
            napi_finalize finalize_callback = nullptr,
            void* finalize_data = nullptr,
            void* finalize_hint = nullptr)
        {
            return new Reference(env,
                value,
                initial_refcount,
                delete_self,
                finalize_callback,
                finalize_data,
                finalize_hint);
        }

        static void Delete(Reference* reference)
        {
            delete reference;
        }

        uint32_t Ref()
        {
            if (++_refcount == 1) {
                _persistent.ClearWeak();
            }

            return _refcount;
        }

        uint32_t Unref()
        {
            if (_refcount == 0) {
                return 0;
            }
            if (--_refcount == 0) {
                _persistent.SetWeak(
                    this, FinalizeCallback, v8::WeakCallbackType::kParameter);
            }

            return _refcount;
        }

        uint32_t RefCount()
        {
            return _refcount;
        }

        v8::Local<v8::Value> Get()
        {
            if (_persistent.IsEmpty()) {
                return v8::Local<v8::Value>();
            } else {
                return v8::Local<v8::Value>::New(_env->isolate, _persistent);
            }
        }

    private:
        static void FinalizeCallback(const v8::WeakCallbackInfo<Reference>& data)
        {
            Reference* reference = data.GetParameter();
            reference->_persistent.Reset();

            // Check before calling the finalize callback, because the callback might
            // delete it.
            bool delete_self = reference->_delete_self;
            napi_env env = reference->_env;

            if (reference->_finalize_callback != nullptr) {
                NAPI_CALL_INTO_MODULE_THROW(env,
                    reference->_finalize_callback(
                        reference->_env,
                        reference->_finalize_data,
                        reference->_finalize_hint));
            }

            if (delete_self) {
                Delete(reference);
            }
        }

        node::Persistent<v8::Value> _persistent;
        uint32_t _refcount;
        bool _delete_self;
    };

    class TryCatch : public v8::TryCatch {
    public:
        explicit TryCatch(napi_env env)
            : v8::TryCatch(env->isolate)
            , _env(env)
        {
        }

        ~TryCatch()
        {
            if (HasCaught()) {
                _env->last_exception.Reset(_env->isolate, Exception());
            }
        }

    private:
        napi_env _env;
    };

    //=== Function napi_callback wrapper =================================

    // Use this data structure to associate callback data with each N-API function
    // exposed to JavaScript. The structure is stored in a v8::External which gets
    // passed into our callback wrapper. This reduces the performance impact of
    // calling through N-API.
    // Ref: benchmark/misc/function_call
    // Discussion (incl. perf. data): https://github.com/nodejs/node/pull/21072
    struct CallbackBundle {
        // Bind the lifecycle of `this` C++ object to a JavaScript object.
        // We never delete a CallbackBundle C++ object directly.
        void BindLifecycleTo(v8::Isolate* isolate, v8::Local<v8::Value> target)
        {
            handle.Reset(isolate, target);
            handle.SetWeak(this, WeakCallback, v8::WeakCallbackType::kParameter);
        }

        napi_env env; // Necessary to invoke C++ NAPI callback
        void* cb_data; // The user provided callback data
        napi_callback function_or_getter;
        napi_callback setter;
        node::Persistent<v8::Value> handle; // Die with this JavaScript object

    private:
        static void WeakCallback(v8::WeakCallbackInfo<CallbackBundle> const& info)
        {
            // Use the "WeakCallback mechanism" to delete the C++ `bundle` object.
            // This will be called when the v8::External containing `this` pointer
            // is being GC-ed.
            CallbackBundle* bundle = info.GetParameter();
            if (bundle != nullptr) {
                delete bundle;
            }
        }
    };

    // Base class extended by classes that wrap V8 function and property callback
    // info.
    class CallbackWrapper {
    public:
        CallbackWrapper(napi_value this_arg, size_t args_length, void* data)
            : _this(this_arg)
            , _args_length(args_length)
            , _data(data)
        {
        }

        virtual napi_value GetNewTarget() = 0;
        virtual void Args(napi_value* buffer, size_t bufferlength) = 0;
        virtual void SetReturnValue(napi_value value) = 0;

        napi_value This() { return _this; }

        size_t ArgsLength() { return _args_length; }

        void* Data() { return _data; }

    protected:
        const napi_value _this;
        const size_t _args_length;
        void* _data;
    };

    template <typename Info, napi_callback CallbackBundle::*FunctionField>
    class CallbackWrapperBase : public CallbackWrapper {
    public:
        CallbackWrapperBase(const Info& cbinfo, const size_t args_length)
            : CallbackWrapper(JsValueFromV8LocalValue(cbinfo.This()),
                args_length,
                nullptr)
            , _cbinfo(cbinfo)
        {
            _bundle = reinterpret_cast<CallbackBundle*>(
                v8::Local<v8::External>::Cast(cbinfo.Data())->Value());
            _data = _bundle->cb_data;
        }

        napi_value GetNewTarget() override { return nullptr; }

    protected:
        void InvokeCallback()
        {
            napi_callback_info cbinfo_wrapper = reinterpret_cast<napi_callback_info>(
                static_cast<CallbackWrapper*>(this));

            // All other pointers we need are stored in `_bundle`
            napi_env env = _bundle->env;
            napi_callback cb = _bundle->*FunctionField;

            napi_value result;
            NAPI_CALL_INTO_MODULE_THROW(env, result = cb(env, cbinfo_wrapper));

            if (result != nullptr) {
                this->SetReturnValue(result);
            }
        }

        const Info& _cbinfo;
        CallbackBundle* _bundle;
    };

    class FunctionCallbackWrapper
        : public CallbackWrapperBase<v8::FunctionCallbackInfo<v8::Value>,
              &CallbackBundle::function_or_getter> {
    public:
        static void Invoke(const v8::FunctionCallbackInfo<v8::Value>& info)
        {
            FunctionCallbackWrapper cbwrapper(info);
            cbwrapper.InvokeCallback();
        }

        explicit FunctionCallbackWrapper(
            const v8::FunctionCallbackInfo<v8::Value>& cbinfo)
            : CallbackWrapperBase(cbinfo, cbinfo.Length())
        {
        }

        napi_value GetNewTarget() override
        {
            if (_cbinfo.IsConstructCall()) {
                return v8impl::JsValueFromV8LocalValue(_cbinfo.NewTarget());
            } else {
                return nullptr;
            }
        }

        /*virtual*/
        void Args(napi_value* buffer, size_t buffer_length) override
        {
            size_t i = 0;
            size_t min = std::min(buffer_length, _args_length);

            for (; i < min; i += 1) {
                buffer[i] = v8impl::JsValueFromV8LocalValue(_cbinfo[i]);
            }

            if (i < buffer_length) {
                napi_value undefined = v8impl::JsValueFromV8LocalValue(v8::Undefined(_cbinfo.GetIsolate()));
                for (; i < buffer_length; i += 1) {
                    buffer[i] = undefined;
                }
            }
        }

        /*virtual*/
        void SetReturnValue(napi_value value) override
        {
            v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
            _cbinfo.GetReturnValue().Set(val);
        }
    };

    class GetterCallbackWrapper
        : public CallbackWrapperBase<v8::PropertyCallbackInfo<v8::Value>,
              &CallbackBundle::function_or_getter> {
    public:
        static void Invoke(v8::Local<v8::Name> property,
            const v8::PropertyCallbackInfo<v8::Value>& info)
        {
            GetterCallbackWrapper cbwrapper(info);
            cbwrapper.InvokeCallback();
        }

        explicit GetterCallbackWrapper(
            const v8::PropertyCallbackInfo<v8::Value>& cbinfo)
            : CallbackWrapperBase(cbinfo, 0)
        {
        }

        /*virtual*/
        void Args(napi_value* buffer, size_t buffer_length) override
        {
            if (buffer_length > 0) {
                napi_value undefined = v8impl::JsValueFromV8LocalValue(v8::Undefined(_cbinfo.GetIsolate()));
                for (size_t i = 0; i < buffer_length; i += 1) {
                    buffer[i] = undefined;
                }
            }
        }

        /*virtual*/
        void SetReturnValue(napi_value value) override
        {
            v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
            _cbinfo.GetReturnValue().Set(val);
        }
    };

    class SetterCallbackWrapper
        : public CallbackWrapperBase<v8::PropertyCallbackInfo<void>,
              &CallbackBundle::setter> {
    public:
        static void Invoke(v8::Local<v8::Name> property,
            v8::Local<v8::Value> value,
            const v8::PropertyCallbackInfo<void>& info)
        {
            SetterCallbackWrapper cbwrapper(info, value);
            cbwrapper.InvokeCallback();
        }

        SetterCallbackWrapper(const v8::PropertyCallbackInfo<void>& cbinfo,
            const v8::Local<v8::Value>& value)
            : CallbackWrapperBase(cbinfo, 1)
            , _value(value)
        {
        }

        /*virtual*/
        void Args(napi_value* buffer, size_t buffer_length) override
        {
            if (buffer_length > 0) {
                buffer[0] = v8impl::JsValueFromV8LocalValue(_value);

                if (buffer_length > 1) {
                    napi_value undefined = v8impl::JsValueFromV8LocalValue(
                        v8::Undefined(_cbinfo.GetIsolate()));
                    for (size_t i = 1; i < buffer_length; i += 1) {
                        buffer[i] = undefined;
                    }
                }
            }
        }

        /*virtual*/
        void SetReturnValue(napi_value value) override
        {
            // Ignore any value returned from a setter callback.
        }

    private:
        const v8::Local<v8::Value>& _value;
    };

    // Creates an object to be made available to the static function callback
    // wrapper, used to retrieve the native callback function and data pointer.
    static v8::Local<v8::Value> CreateFunctionCallbackData(napi_env env, napi_callback cb, void* data)
    {
        CallbackBundle* bundle = new CallbackBundle();
        bundle->function_or_getter = cb;
        bundle->cb_data = data;
        bundle->env = env;
        v8::Local<v8::Value> cbdata = v8::External::New(env->isolate, bundle);
        bundle->BindLifecycleTo(env->isolate, cbdata);

        return cbdata;
    }

    // Creates an object to be made available to the static getter/setter
    // callback wrapper, used to retrieve the native getter/setter callback
    // function and data pointer.
    static v8::Local<v8::Value> CreateAccessorCallbackData(napi_env env,
        napi_callback getter,
        napi_callback setter,
        void* data)
    {
        CallbackBundle* bundle = new CallbackBundle();
        bundle->function_or_getter = getter;
        bundle->setter = setter;
        bundle->cb_data = data;
        bundle->env = env;
        v8::Local<v8::Value> cbdata = v8::External::New(env->isolate, bundle);
        bundle->BindLifecycleTo(env->isolate, cbdata);

        return cbdata;
    }

    static void DeleteEnv(napi_env env, void* data, void* hint)
    {
        delete env;
    }

    static uv_loop_t* GetCurrentEventLoop(v8::Isolate* isolate)
    {
        v8::HandleScope handle_scope(isolate);
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        if (context.IsEmpty())
            return nullptr;
        node::Environment* env = node::Environment::GetCurrent(context);
        if (env == nullptr)
            return nullptr;
        return env->event_loop();
    }

    static napi_env GetEnv(v8::Local<v8::Context> context)
    {
        napi_env result;

        v8::Isolate* isolate = context->GetIsolate();
        v8::Local<v8::Object> global = context->Global();

        // In the case of the string for which we grab the private and the value of
        // the private on the global object we can call .ToLocalChecked() directly
        // because we need to stop hard if either of them is empty.
        //
        // Re https://github.com/nodejs/node/pull/14217#discussion_r128775149
        v8::Local<v8::Value> value = global->GetPrivate(context, NAPI_PRIVATE_KEY(context, env)).ToLocalChecked();

        if (value->IsExternal()) {
            result = static_cast<napi_env>(value.As<v8::External>()->Value());
        } else {
            result = new napi_env__(isolate, GetCurrentEventLoop(isolate));

            v8::Local<v8::External> external = v8::External::New(isolate, result);

            // We must also stop hard if the result of assigning the env to the global
            // is either nothing or false.
            NODE_CHECK(global->SetPrivate(context, NAPI_PRIVATE_KEY(context, env), external).FromJust());

            // Create a self-destructing reference to external that will get rid of the
            // napi_env when external goes out of scope.
            Reference::New(result, external, 0, true, DeleteEnv, nullptr, nullptr);
        }

        return result;
    }

    enum UnwrapAction {
        KeepWrap,
        RemoveWrap
    };

    static napi_status Unwrap(napi_env env, napi_value js_object, void** result, UnwrapAction action)
    {
        NAPI_PREAMBLE(env);
        NODE_CHECK_ARG(env, js_object);
        if (action == KeepWrap) {
            NODE_CHECK_ARG(env, result);
        }

        v8::Isolate* isolate = env->isolate;
        v8::Local<v8::Context> context = isolate->GetCurrentContext();

        v8::Local<v8::Value> value = v8impl::V8LocalValueFromJsValue(js_object);
        RETURN_STATUS_IF_FALSE(env, value->IsObject(), napi_invalid_arg);
        v8::Local<v8::Object> obj = value.As<v8::Object>();

        auto val = obj->GetPrivate(context, NAPI_PRIVATE_KEY(context, wrapper)).ToLocalChecked();
        RETURN_STATUS_IF_FALSE(env, val->IsExternal(), napi_invalid_arg);
        Reference* reference = static_cast<v8impl::Reference*>(val.As<v8::External>()->Value());

        if (result) {
            *result = reference->Data();
        }

        if (action == RemoveWrap) {
            NODE_CHECK(obj->DeletePrivate(context, NAPI_PRIVATE_KEY(context, wrapper)).FromJust());
            Reference::Delete(reference);
        }

        return GET_RETURN_STATUS(env);
    }

    static napi_status ConcludeDeferred(napi_env env,
        napi_deferred deferred,
        napi_value result,
        bool is_resolved)
    {
        NAPI_PREAMBLE(env);
        NODE_CHECK_ARG(env, result);

        v8::Local<v8::Context> context = env->isolate->GetCurrentContext();
        node::Persistent<v8::Value>* deferred_ref = NodePersistentFromJsDeferred(deferred);
        v8::Local<v8::Value> v8_deferred = v8::Local<v8::Value>::New(env->isolate, *deferred_ref);

        auto v8_resolver = v8::Local<v8::Promise::Resolver>::Cast(v8_deferred);

        v8::Maybe<bool> success = is_resolved ? v8_resolver->Resolve(context, v8impl::V8LocalValueFromJsValue(result)) : v8_resolver->Reject(context, v8impl::V8LocalValueFromJsValue(result));

        delete deferred_ref;

        RETURN_STATUS_IF_FALSE(env, success.FromMaybe(false), napi_generic_failure);

        return GET_RETURN_STATUS(env);
    }

    class ThreadSafeFunction : public node::AsyncResource {
    public:
        ThreadSafeFunction(v8::Local<v8::Function> func,
            v8::Local<v8::Object> resource,
            v8::Local<v8::String> name,
            v8::Local<v8::Context> v8_context,
            size_t thread_count_,
            void* context_,
            size_t max_queue_size_,
            napi_env env_,
            void* finalize_data_,
            napi_finalize finalize_cb_,
            napi_threadsafe_function_call_js call_js_cb_)
            : AsyncResource(env_->isolate, resource, (*v8::String::Utf8Value(name)), -1)
            ,

            m_thread_count(thread_count_)
            , m_is_closing(false)
            , m_context(context_)
            , m_max_queue_size(max_queue_size_)
            , m_env(env_)
            , m_finalize_data(finalize_data_)
            , m_finalize_cb(finalize_cb_)
            , m_call_js_cb(call_js_cb_ == nullptr ? CallJs : call_js_cb_)
            , handles_closing(false)
        {
            m_refFunction.Reset(m_env->isolate, func);
            m_v8_context.Reset(m_env->isolate, v8_context);
            node::AddEnvironmentCleanupHook(m_env->isolate, Cleanup, this);
        }

        ~ThreadSafeFunction()
        {
            m_v8_context.Reset();
            node::RemoveEnvironmentCleanupHook(m_env->isolate, Cleanup, this);
        }

        // These methods can be called from any thread.

        napi_status Push(void* data, napi_threadsafe_function_call_mode mode)
        {
            node::Mutex::ScopedLock lock(this->m_mutex);

            while (m_queue.size() >= m_max_queue_size && m_max_queue_size > 0 && !m_is_closing) {
                if (mode == napi_tsfn_nonblocking) {
                    return napi_queue_full;
                }
                m_cond->Wait(lock);
            }

            if (m_is_closing) {
                if (m_thread_count == 0) {
                    return napi_invalid_arg;
                } else {
                    m_thread_count--;
                    return napi_closing;
                }
            } else {
                if (uv_async_send(&m_async) != 0) {
                    return napi_generic_failure;
                }
                m_queue.push(data);
                return napi_ok;
            }
        }

        napi_status Acquire()
        {
            node::Mutex::ScopedLock lock(this->m_mutex);

            if (m_is_closing) {
                return napi_closing;
            }

            m_thread_count++;

            return napi_ok;
        }

        napi_status Release(napi_threadsafe_function_release_mode mode)
        {
            node::Mutex::ScopedLock lock(this->m_mutex);

            if (m_thread_count == 0) {
                return napi_invalid_arg;
            }

            m_thread_count--;

            if (m_thread_count == 0 || mode == napi_tsfn_abort) {
                if (!m_is_closing) {
                    m_is_closing = (mode == napi_tsfn_abort);
                    if (m_is_closing && m_max_queue_size > 0) {
                        m_cond->Signal(lock);
                    }
                    if (uv_async_send(&m_async) != 0) {
                        return napi_generic_failure;
                    }
                }
            }

            return napi_ok;
        }

        void EmptyQueueAndDelete()
        {
            for (; !m_queue.empty(); m_queue.pop()) {
                m_call_js_cb(nullptr, nullptr, m_context, m_queue.front());
            }
            delete this;
        }

        // These methods must only be called from the loop thread.

        napi_status Init()
        {
            ThreadSafeFunction* ts_fn = this;

            if (uv_async_init(m_env->loop, &m_async, AsyncCb) == 0) {
                if (m_max_queue_size > 0) {
                    m_cond.reset(new node::ConditionVariable);
                }
                if ((m_max_queue_size == 0 || m_cond.get() != nullptr) && uv_idle_init(m_env->loop, &m_idle) == 0) {
                    return napi_ok;
                }

                NodeEnv()->CloseHandle(reinterpret_cast<uv_handle_t*>(&m_async), [](uv_handle_t* handle) -> void {
                    ThreadSafeFunction* ts_fn = node::ContainerOf(&ThreadSafeFunction::m_async, reinterpret_cast<uv_async_t*>(handle));
                    delete ts_fn;
                });

                // Prevent the thread-safe function from being deleted here, because
                // the callback above will delete it.
                ts_fn = nullptr;
            }

            delete ts_fn;

            return napi_generic_failure;
        }

        napi_status Unref()
        {
            uv_unref(reinterpret_cast<uv_handle_t*>(&m_async));
            uv_unref(reinterpret_cast<uv_handle_t*>(&m_idle));

            return napi_ok;
        }

        napi_status Ref()
        {
            uv_ref(reinterpret_cast<uv_handle_t*>(&m_async));
            uv_ref(reinterpret_cast<uv_handle_t*>(&m_idle));

            return napi_ok;
        }

        void DispatchOne()
        {
            void* data = nullptr;
            bool popped_value = false;
            bool idle_stop_failed = false;

            {
                node::Mutex::ScopedLock lock(this->m_mutex);
                if (m_is_closing) {
                    CloseHandlesAndMaybeDelete();
                } else {
                    size_t size = m_queue.size();
                    if (size > 0) {
                        data = m_queue.front();
                        m_queue.pop();
                        popped_value = true;
                        if (size == m_max_queue_size && m_max_queue_size > 0) {
                            m_cond->Signal(lock);
                        }
                        size--;
                    }

                    if (size == 0) {
                        if (m_thread_count == 0) {
                            m_is_closing = true;
                            if (m_max_queue_size > 0) {
                                m_cond->Signal(lock);
                            }
                            CloseHandlesAndMaybeDelete();
                        } else {
                            if (uv_idle_stop(&m_idle) != 0) {
                                idle_stop_failed = true;
                            }
                        }
                    }
                }
            }

            if (popped_value || idle_stop_failed) {
                v8::HandleScope scope(m_env->isolate);
                v8::Local<v8::Context> v8_context = v8::Local<v8::Context>::New(m_env->isolate, m_v8_context);
                v8::Context::Scope context_scope(v8_context);
                CallbackScope cb_scope(this);

                if (idle_stop_failed) {
                    NODE_CHECK(napi_throw_error(m_env, "ERR_NAPI_TSFN_STOP_IDLE_LOOP", "Failed to stop the idle loop") == napi_ok);
                } else {
                    v8::Local<v8::Function> js_cb = v8::Local<v8::Function>::New(m_env->isolate, m_refFunction);
                    m_call_js_cb(m_env, v8impl::JsValueFromV8LocalValue(js_cb), m_context, data);
                }
            }
        }

        node::Environment* NodeEnv()
        {
            // Grabbing the Node.js environment requires a handle scope because it
            // looks up fields on the current context.
            v8::HandleScope scope(m_env->isolate);
            node::Environment* node_env = node::Environment::GetCurrent(m_env->isolate);
            //NODE_CHECK_NOT_NULL(node_env);
            return node_env;
        }

        void MaybeStartIdle()
        {
            if (uv_idle_start(&m_idle, IdleCb) != 0) {
                v8::HandleScope scope(m_env->isolate);
                CallbackScope cb_scope(this);
                NODE_CHECK(napi_throw_error(m_env,
                               "ERR_NAPI_TSFN_START_IDLE_LOOP",
                               "Failed to start the idle loop")
                    == napi_ok);
            }
        }

        void Finalize()
        {
            v8::HandleScope scope(m_env->isolate);
            if (m_finalize_cb) {
                CallbackScope cb_scope(this);
                m_finalize_cb(m_env, m_finalize_data, m_context);
            }
            EmptyQueueAndDelete();
        }

        inline void* Context()
        {
            return m_context;
        }

        void CloseHandlesAndMaybeDelete(bool set_closing = false)
        {
            if (set_closing) {
                node::Mutex::ScopedLock lock(this->m_mutex);
                m_is_closing = true;
                if (m_max_queue_size > 0) {
                    m_cond->Signal(lock);
                }
            }
            if (handles_closing) {
                return;
            }
            handles_closing = true;
            NodeEnv()->CloseHandle(reinterpret_cast<uv_handle_t*>(&m_async), [](uv_handle_t* handle) -> void {
                ThreadSafeFunction* ts_fn = node::ContainerOf(&ThreadSafeFunction::m_async, reinterpret_cast<uv_async_t*>(handle));

                ts_fn->NodeEnv()->CloseHandle(reinterpret_cast<uv_handle_t*>(&ts_fn->m_idle), [](uv_handle_t* handle) -> void {
                    ThreadSafeFunction* ts_fn = node::ContainerOf(&ThreadSafeFunction::m_idle, reinterpret_cast<uv_idle_t*>(handle));
                    ts_fn->Finalize();
                });
            });
        }

        // Default way of calling into JavaScript. Used when ThreadSafeFunction is
        //  without a call_js_cb_.
        static void CallJs(napi_env env, napi_value cb, void* context, void* data)
        {
            if (!(env == nullptr || cb == nullptr)) {
                napi_value recv;
                napi_status status;

                status = napi_get_undefined(env, &recv);
                if (status != napi_ok) {
                    napi_throw_error(env, "ERR_NAPI_TSFN_GET_UNDEFINED", "Failed to retrieve undefined value");
                    return;
                }

                status = napi_call_function(env, recv, cb, 0, nullptr, nullptr);
                if (status != napi_ok && status != napi_pending_exception) {
                    napi_throw_error(env, "ERR_NAPI_TSFN_CALL_JS", "Failed to call JS callback");
                    return;
                }
            }
        }

        static void IdleCb(uv_idle_t* idle)
        {
            ThreadSafeFunction* ts_fn = node::ContainerOf(&ThreadSafeFunction::m_idle, idle);
            ts_fn->DispatchOne();
        }

        static void AsyncCb(uv_async_t* async)
        {
            ThreadSafeFunction* ts_fn = node::ContainerOf(&ThreadSafeFunction::m_async, async);
            ts_fn->MaybeStartIdle();
        }

        static void Cleanup(void* data)
        {
            reinterpret_cast<ThreadSafeFunction*>(data)->CloseHandlesAndMaybeDelete(true);
        }

    private:
        // These are variables protected by the mutex.
        node::Mutex m_mutex;
        std::unique_ptr<node::ConditionVariable> m_cond;
        std::queue<void*> m_queue;
        uv_async_t m_async;
        uv_idle_t m_idle;
        size_t m_thread_count;
        bool m_is_closing;

        // These are variables set once, upon creation, and then never again, which
        // means we don't need the mutex to read them.
        void* m_context;
        size_t m_max_queue_size;

        // These are variables accessed only from the loop thread.
        node::Persistent<v8::Function> m_refFunction;
        node::Persistent<v8::Context> m_v8_context;
        napi_env m_env;
        void* m_finalize_data;
        napi_finalize m_finalize_cb;
        napi_threadsafe_function_call_js m_call_js_cb;
        bool handles_closing;
    };

    enum WrapType {
        retrievable,
        anonymous
    };

    template <WrapType wrap_type>
    static inline napi_status Wrap(napi_env env,
        napi_value js_object,
        void* native_object,
        napi_finalize finalize_cb,
        void* finalize_hint,
        napi_ref* result)
    {
        NAPI_PREAMBLE(env);
        NODE_CHECK_ARG(env, js_object);

        v8::Isolate* isolate = env->isolate;
        v8::Local<v8::Context> context = isolate->GetCurrentContext();

        v8::Local<v8::Value> value = v8impl::V8LocalValueFromJsValue(js_object);
        RETURN_STATUS_IF_FALSE(env, value->IsObject(), napi_invalid_arg);
        v8::Local<v8::Object> obj = value.As<v8::Object>();

        if (wrap_type == retrievable) {
            // If we've already wrapped this object, we error out.
            RETURN_STATUS_IF_FALSE(env,
                !obj->HasPrivate(context, NAPI_PRIVATE_KEY(context, wrapper))
                     .FromJust(),
                napi_invalid_arg);
        } else if (wrap_type == anonymous) {
            // If no finalize callback is provided, we error out.
            NODE_CHECK_ARG(env, finalize_cb);
        }

        v8impl::Reference* reference = nullptr;
        if (result != nullptr) {
            // The returned reference should be deleted via napi_delete_reference()
            // ONLY in response to the finalize callback invocation. (If it is deleted
            // before then, then the finalize callback will never be invoked.)
            // Therefore a finalize callback is required when returning a reference.
            NODE_CHECK_ARG(env, finalize_cb);
            reference = v8impl::Reference::New(
                env, obj, 0, false, finalize_cb, native_object, finalize_hint);
            *result = reinterpret_cast<napi_ref>(reference);
        } else {
            // Create a self-deleting reference.
            reference = v8impl::Reference::New(env, obj, 0, true, finalize_cb,
                native_object, finalize_cb == nullptr ? nullptr : finalize_hint);
        }

        if (wrap_type == retrievable) {
            NODE_CHECK(obj->SetPrivate(context, NAPI_PRIVATE_KEY(context, wrapper),
                              v8::External::New(isolate, reference))
                           .FromJust());
        }

        return GET_RETURN_STATUS(env);
    }

} // end of namespace v8impl

// Intercepts the Node-V8 module registration callback. Converts parameters
// to NAPI equivalents and then calls the registration callback specified
// by the NAPI module.
void napi_module_register_cb(v8::Local<v8::Object> exports,
    v8::Local<v8::Value> module,
    v8::Local<v8::Context> context,
    void* priv)
{
    napi_module_register_by_symbol(exports, module, context, static_cast<napi_module*>(priv)->nm_register_func);
}

} // end of anonymous namespace

void napi_module_register_by_symbol(v8::Local<v8::Object> exports,
    v8::Local<v8::Value> module,
    v8::Local<v8::Context> context,
    napi_addon_register_func init)
{
    if (init == nullptr) {
        node::Environment* node_env = node::Environment::GetCurrent(context);
        //NODE_CHECK_NOT_NULL(node_env);
        node_env->ThrowError("Module has no declared entry point.");
        return;
    }

    // Create a new napi_env for this module or reference one if a pre-existing
    // one is found.
    napi_env env = v8impl::GetEnv(context);

    napi_value _exports;
    NAPI_CALL_INTO_MODULE_THROW(env,
        _exports = init(env, v8impl::JsValueFromV8LocalValue(exports)));

    // If register function returned a non-null exports object different from
    // the exports object we passed it, set that as the "exports" property of
    // the module.
    if (_exports != nullptr && _exports != v8impl::JsValueFromV8LocalValue(exports)) {
        napi_value _module = v8impl::JsValueFromV8LocalValue(module);
        napi_set_named_property(env, _module, "exports", _exports);
    }
}

// Registers a NAPI module.
void napi_module_register(napi_module* mod)
{
    node::node_module* nm = new node::node_module {
        -1,
        mod->nm_flags,
        nullptr,
        mod->nm_filename,
        nullptr,
        napi_module_register_cb,
        mod->nm_modname,
        mod, // priv
        nullptr,
    };
    node::node_module_register(nm);
}

napi_status napi_add_env_cleanup_hook(napi_env env,
    void (*fun)(void* arg),
    void* arg)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, fun);

    node::AddEnvironmentCleanupHook(env->isolate, fun, arg);
    return napi_ok;
}

napi_status napi_remove_env_cleanup_hook(napi_env env,
    void (*fun)(void* arg),
    void* arg)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, fun);

    node::RemoveEnvironmentCleanupHook(env->isolate, fun, arg);
    return napi_ok;
}

// Warning: Keep in-sync with napi_status enum
static const char* error_messages[] = {
    nullptr,
    "Invalid argument",
    "An object was expected",
    "A string was expected",
    "A string or symbol was expected",
    "A function was expected",
    "A number was expected",
    "A boolean was expected",
    "An array was expected",
    "Unknown failure",
    "An exception is pending",
    "The async work item was cancelled",
    "napi_escape_handle already called on scope",
    "Invalid handle scope usage",
    "Invalid callback scope usage",
    "Thread-safe function queue is full",
    "Thread-safe function handle is closing",
    "A bigint was expected",
};

static inline napi_status napi_clear_last_error(napi_env env)
{
    env->last_error.error_code = napi_ok;

    // TODO(boingoing): Should this be a callback?
    env->last_error.engine_error_code = 0;
    env->last_error.engine_reserved = nullptr;
    return napi_ok;
}

static inline napi_status napi_set_last_error(napi_env env, napi_status error_code,
    uint32_t engine_error_code,
    void* engine_reserved)
{
    env->last_error.error_code = error_code;
    env->last_error.engine_error_code = engine_error_code;
    env->last_error.engine_reserved = engine_reserved;
    return error_code;
}

napi_status napi_get_last_error_info(napi_env env,
    const napi_extended_error_info** result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    // you must update this NODE_ASSERT to reference the last message
    // in the napi_status enum each time a new error message is added.
    // We don't have a napi_status_last as this would result in an ABI
    // change each time a message was added.
    DebugBreak();
    //static_assert(node::arraysize(error_messages) == napi_bigint_expected + 1, "Count of error messages must match count of error values");
    NODE_CHECK_LE(env->last_error.error_code, napi_callback_scope_mismatch);

    // Wait until someone requests the last error information to fetch the error
    // message string
    env->last_error.error_message = error_messages[env->last_error.error_code];

    *result = &(env->last_error);
    return napi_ok;
}

napi_status napi_fatal_exception(napi_env env, napi_value err)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, err);

    v8::Local<v8::Value> local_err = v8impl::V8LocalValueFromJsValue(err);
    v8impl::trigger_fatal_exception(env, local_err);

    return napi_clear_last_error(env);
}

NAPI_NO_RETURN void napi_fatal_error(const char* location,
    size_t location_len,
    const char* message,
    size_t message_len)
{
    std::string location_string;
    std::string message_string;

    if (location_len != NAPI_AUTO_LENGTH) {
        location_string.assign(
            const_cast<char*>(location), location_len);
    } else {
        location_string.assign(
            const_cast<char*>(location), strlen(location));
    }

    if (message_len != NAPI_AUTO_LENGTH) {
        message_string.assign(
            const_cast<char*>(message), message_len);
    } else {
        message_string.assign(
            const_cast<char*>(message), strlen(message));
    }

    node::FatalError(location_string.c_str(), message_string.c_str());
}

napi_status napi_create_function(napi_env env,
    const char* utf8name,
    size_t length,
    napi_callback cb,
    void* callback_data,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, result);
    NODE_CHECK_ARG(env, cb);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Function> return_value;
    v8::EscapableHandleScope scope(isolate);
    v8::Local<v8::Value> cbdata = v8impl::CreateFunctionCallbackData(env, cb, callback_data);

    RETURN_STATUS_IF_FALSE(env, !cbdata.IsEmpty(), napi_generic_failure);

    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::MaybeLocal<v8::Function> maybe_function = v8::Function::New(context,
        v8impl::FunctionCallbackWrapper::Invoke,
        cbdata);
    NODE_CHECK_MAYBE_EMPTY(env, maybe_function, napi_generic_failure);

    return_value = scope.Escape(maybe_function.ToLocalChecked());

    if (utf8name != nullptr) {
        v8::Local<v8::String> name_string;
        NODE_CHECK_NEW_FROM_UTF8_LEN(env, name_string, utf8name, length);
        return_value->SetName(name_string);
    }

    *result = v8impl::JsValueFromV8LocalValue(return_value);

    return GET_RETURN_STATUS(env);
}

napi_status napi_define_class(napi_env env,
    const char* utf8name,
    size_t length,
    napi_callback constructor,
    void* callback_data,
    size_t property_count,
    const napi_property_descriptor* properties,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, result);
    NODE_CHECK_ARG(env, constructor);

    v8::Isolate* isolate = env->isolate;

    v8::EscapableHandleScope scope(isolate);
    v8::Local<v8::Value> cbdata = v8impl::CreateFunctionCallbackData(env, constructor, callback_data);

    RETURN_STATUS_IF_FALSE(env, !cbdata.IsEmpty(), napi_generic_failure);

    v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(
        isolate, v8impl::FunctionCallbackWrapper::Invoke, cbdata);

    v8::Local<v8::String> name_string;
    NODE_CHECK_NEW_FROM_UTF8_LEN(env, name_string, utf8name, length);
    tpl->SetClassName(name_string);

    size_t static_property_count = 0;
    for (size_t i = 0; i < property_count; i++) {
        const napi_property_descriptor* p = properties + i;

        if ((p->attributes & napi_static) != 0) {
            // Static properties are handled separately below.
            static_property_count++;
            continue;
        }

        v8::Local<v8::Name> property_name;
        napi_status status = v8impl::V8NameFromPropertyDescriptor(env, p, &property_name);

        if (status != napi_ok) {
            return napi_set_last_error(env, status);
        }

        v8::PropertyAttribute attributes = v8impl::V8PropertyAttributesFromDescriptor(p);

        // This code is similar to that in napi_define_properties(); the
        // difference is it applies to a template instead of an object.
        if (p->getter != nullptr || p->setter != nullptr) {
            v8::Local<v8::Value> cbdata = v8impl::CreateAccessorCallbackData(
                env, p->getter, p->setter, p->data);

            tpl->PrototypeTemplate()->SetAccessor(
                property_name,
                p->getter ? v8impl::GetterCallbackWrapper::Invoke : nullptr,
                p->setter ? v8impl::SetterCallbackWrapper::Invoke : nullptr,
                cbdata,
                v8::AccessControl::DEFAULT,
                attributes);
        } else if (p->method != nullptr) {
            v8::Local<v8::Value> cbdata = v8impl::CreateFunctionCallbackData(env, p->method, p->data);

            RETURN_STATUS_IF_FALSE(env, !cbdata.IsEmpty(), napi_generic_failure);

            v8::Local<v8::FunctionTemplate> t = v8::FunctionTemplate::New(isolate,
                v8impl::FunctionCallbackWrapper::Invoke,
                cbdata,
                v8::Signature::New(isolate, tpl));

            tpl->PrototypeTemplate()->Set(property_name, t, attributes);
        } else {
            v8::Local<v8::Value> value = v8impl::V8LocalValueFromJsValue(p->value);
            tpl->PrototypeTemplate()->Set(property_name, value, attributes);
        }
    }

    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    *result = v8impl::JsValueFromV8LocalValue(
        scope.Escape(tpl->GetFunction(context).ToLocalChecked()));

    if (static_property_count > 0) {
        std::vector<napi_property_descriptor> static_descriptors;
        static_descriptors.reserve(static_property_count);

        for (size_t i = 0; i < property_count; i++) {
            const napi_property_descriptor* p = properties + i;
            if ((p->attributes & napi_static) != 0) {
                static_descriptors.push_back(*p);
            }
        }

        napi_status status = napi_define_properties(env,
            *result,
            static_descriptors.size(),
            static_descriptors.data());
        if (status != napi_ok)
            return status;
    }

    return GET_RETURN_STATUS(env);
}

napi_status napi_get_property_names(napi_env env,
    napi_value object,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Object> obj;
    NODE_CHECK_TO_OBJECT(env, context, obj, object);

    auto maybe_propertynames = obj->GetPropertyNames(context);

    NODE_CHECK_MAYBE_EMPTY(env, maybe_propertynames, napi_generic_failure);

    *result = v8impl::JsValueFromV8LocalValue(
        maybe_propertynames.ToLocalChecked());
    return GET_RETURN_STATUS(env);
}

napi_status napi_set_property(napi_env env,
    napi_value object,
    napi_value key,
    napi_value value)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, key);
    NODE_CHECK_ARG(env, value);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Object> obj;

    NODE_CHECK_TO_OBJECT(env, context, obj, object);

    v8::Local<v8::Value> k = v8impl::V8LocalValueFromJsValue(key);
    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);

    v8::Maybe<bool> set_maybe = obj->Set(context, k, val);

    RETURN_STATUS_IF_FALSE(env, set_maybe.FromMaybe(false), napi_generic_failure);
    return GET_RETURN_STATUS(env);
}

napi_status napi_has_property(napi_env env,
    napi_value object,
    napi_value key,
    bool* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, result);
    NODE_CHECK_ARG(env, key);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Object> obj;

    NODE_CHECK_TO_OBJECT(env, context, obj, object);

    v8::Local<v8::Value> k = v8impl::V8LocalValueFromJsValue(key);
    v8::Maybe<bool> has_maybe = obj->Has(context, k);

    NODE_CHECK_MAYBE_NOTHING(env, has_maybe, napi_generic_failure);

    *result = has_maybe.FromMaybe(false);
    return GET_RETURN_STATUS(env);
}

napi_status napi_get_property(napi_env env,
    napi_value object,
    napi_value key,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, key);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Value> k = v8impl::V8LocalValueFromJsValue(key);
    v8::Local<v8::Object> obj;

    NODE_CHECK_TO_OBJECT(env, context, obj, object);

    auto get_maybe = obj->Get(context, k);

    NODE_CHECK_MAYBE_EMPTY(env, get_maybe, napi_generic_failure);

    v8::Local<v8::Value> val = get_maybe.ToLocalChecked();
    *result = v8impl::JsValueFromV8LocalValue(val);
    return GET_RETURN_STATUS(env);
}

napi_status napi_delete_property(napi_env env,
    napi_value object,
    napi_value key,
    bool* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, key);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Value> k = v8impl::V8LocalValueFromJsValue(key);
    v8::Local<v8::Object> obj;

    NODE_CHECK_TO_OBJECT(env, context, obj, object);
    v8::Maybe<bool> delete_maybe = obj->Delete(context, k);
    NODE_CHECK_MAYBE_NOTHING(env, delete_maybe, napi_generic_failure);

    if (result != nullptr)
        *result = delete_maybe.FromMaybe(false);

    return GET_RETURN_STATUS(env);
}

napi_status napi_has_own_property(napi_env env,
    napi_value object,
    napi_value key,
    bool* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, key);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Object> obj;

    NODE_CHECK_TO_OBJECT(env, context, obj, object);
    v8::Local<v8::Value> k = v8impl::V8LocalValueFromJsValue(key);
    RETURN_STATUS_IF_FALSE(env, k->IsName(), napi_name_expected);
    v8::Maybe<bool> has_maybe = obj->HasOwnProperty(context, k.As<v8::Name>());
    NODE_CHECK_MAYBE_NOTHING(env, has_maybe, napi_generic_failure);
    *result = has_maybe.FromMaybe(false);

    return GET_RETURN_STATUS(env);
}

napi_status napi_set_named_property(napi_env env,
    napi_value object,
    const char* utf8name,
    napi_value value)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, value);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Object> obj;

    NODE_CHECK_TO_OBJECT(env, context, obj, object);

    v8::Local<v8::Name> key;
    NODE_CHECK_NEW_FROM_UTF8(env, key, utf8name);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);

    v8::Maybe<bool> set_maybe = obj->Set(context, key, val);

    RETURN_STATUS_IF_FALSE(env, set_maybe.FromMaybe(false), napi_generic_failure);
    return GET_RETURN_STATUS(env);
}

napi_status napi_has_named_property(napi_env env,
    napi_value object,
    const char* utf8name,
    bool* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Object> obj;

    NODE_CHECK_TO_OBJECT(env, context, obj, object);

    v8::Local<v8::Name> key;
    NODE_CHECK_NEW_FROM_UTF8(env, key, utf8name);

    v8::Maybe<bool> has_maybe = obj->Has(context, key);

    NODE_CHECK_MAYBE_NOTHING(env, has_maybe, napi_generic_failure);

    *result = has_maybe.FromMaybe(false);
    return GET_RETURN_STATUS(env);
}

napi_status napi_get_named_property(napi_env env,
    napi_value object,
    const char* utf8name,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Name> key;
    NODE_CHECK_NEW_FROM_UTF8(env, key, utf8name);

    v8::Local<v8::Object> obj;

    NODE_CHECK_TO_OBJECT(env, context, obj, object);

    auto get_maybe = obj->Get(context, key);

    NODE_CHECK_MAYBE_EMPTY(env, get_maybe, napi_generic_failure);

    v8::Local<v8::Value> val = get_maybe.ToLocalChecked();
    *result = v8impl::JsValueFromV8LocalValue(val);
    return GET_RETURN_STATUS(env);
}

napi_status napi_set_element(napi_env env,
    napi_value object,
    uint32_t index,
    napi_value value)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, value);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Object> obj;

    NODE_CHECK_TO_OBJECT(env, context, obj, object);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
    auto set_maybe = obj->Set(context, index, val);

    RETURN_STATUS_IF_FALSE(env, set_maybe.FromMaybe(false), napi_generic_failure);

    return GET_RETURN_STATUS(env);
}

napi_status napi_has_element(napi_env env,
    napi_value object,
    uint32_t index,
    bool* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Object> obj;

    NODE_CHECK_TO_OBJECT(env, context, obj, object);

    v8::Maybe<bool> has_maybe = obj->Has(context, index);

    NODE_CHECK_MAYBE_NOTHING(env, has_maybe, napi_generic_failure);

    *result = has_maybe.FromMaybe(false);
    return GET_RETURN_STATUS(env);
}

napi_status napi_get_element(napi_env env,
    napi_value object,
    uint32_t index,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Object> obj;

    NODE_CHECK_TO_OBJECT(env, context, obj, object);

    auto get_maybe = obj->Get(context, index);

    NODE_CHECK_MAYBE_EMPTY(env, get_maybe, napi_generic_failure);

    *result = v8impl::JsValueFromV8LocalValue(get_maybe.ToLocalChecked());
    return GET_RETURN_STATUS(env);
}

napi_status napi_delete_element(napi_env env,
    napi_value object,
    uint32_t index,
    bool* result)
{
    NAPI_PREAMBLE(env);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Object> obj;

    NODE_CHECK_TO_OBJECT(env, context, obj, object);
    v8::Maybe<bool> delete_maybe = obj->Delete(context, index);
    NODE_CHECK_MAYBE_NOTHING(env, delete_maybe, napi_generic_failure);

    if (result != nullptr)
        *result = delete_maybe.FromMaybe(false);

    return GET_RETURN_STATUS(env);
}

napi_status napi_define_properties(napi_env env,
    napi_value object,
    size_t property_count,
    const napi_property_descriptor* properties)
{
    NAPI_PREAMBLE(env);
    if (property_count > 0) {
        NODE_CHECK_ARG(env, properties);
    }

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Object> obj;
    NODE_CHECK_TO_OBJECT(env, context, obj, object);

    for (size_t i = 0; i < property_count; i++) {
        const napi_property_descriptor* p = &properties[i];

        v8::Local<v8::Name> property_name;
        napi_status status = v8impl::V8NameFromPropertyDescriptor(env, p, &property_name);

        if (status != napi_ok) {
            return napi_set_last_error(env, status);
        }

        v8::PropertyAttribute attributes = v8impl::V8PropertyAttributesFromDescriptor(p);

        if (p->getter != nullptr || p->setter != nullptr) {
            v8::Local<v8::Value> cbdata = v8impl::CreateAccessorCallbackData(
                env,
                p->getter,
                p->setter,
                p->data);

            auto set_maybe = obj->SetAccessor(
                context,
                property_name,
                p->getter ? v8impl::GetterCallbackWrapper::Invoke : nullptr,
                p->setter ? v8impl::SetterCallbackWrapper::Invoke : nullptr,
                cbdata,
                v8::AccessControl::DEFAULT,
                attributes);

            if (!set_maybe.FromMaybe(false)) {
                return napi_set_last_error(env, napi_invalid_arg);
            }
        } else if (p->method != nullptr) {
            v8::Local<v8::Value> cbdata = v8impl::CreateFunctionCallbackData(env, p->method, p->data);

            NODE_CHECK_MAYBE_EMPTY(env, cbdata, napi_generic_failure);

            v8::MaybeLocal<v8::Function> maybe_fn = v8::Function::New(context,
                v8impl::FunctionCallbackWrapper::Invoke,
                cbdata);

            NODE_CHECK_MAYBE_EMPTY(env, maybe_fn, napi_generic_failure);

            auto define_maybe = obj->DefineOwnProperty(
                context, property_name, maybe_fn.ToLocalChecked(), attributes);

            if (!define_maybe.FromMaybe(false)) {
                return napi_set_last_error(env, napi_generic_failure);
            }
        } else {
            v8::Local<v8::Value> value = v8impl::V8LocalValueFromJsValue(p->value);

            auto define_maybe = obj->DefineOwnProperty(context, property_name, value, attributes);

            if (!define_maybe.FromMaybe(false)) {
                return napi_set_last_error(env, napi_invalid_arg);
            }
        }
    }

    return GET_RETURN_STATUS(env);
}

napi_status napi_is_array(napi_env env, napi_value value, bool* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);

    *result = val->IsArray();
    return napi_clear_last_error(env);
}

napi_status napi_get_array_length(napi_env env,
    napi_value value,
    uint32_t* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
    RETURN_STATUS_IF_FALSE(env, val->IsArray(), napi_array_expected);

    v8::Local<v8::Array> arr = val.As<v8::Array>();
    *result = arr->Length();

    return GET_RETURN_STATUS(env);
}

napi_status napi_strict_equals(napi_env env,
    napi_value lhs,
    napi_value rhs,
    bool* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, lhs);
    NODE_CHECK_ARG(env, rhs);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> a = v8impl::V8LocalValueFromJsValue(lhs);
    v8::Local<v8::Value> b = v8impl::V8LocalValueFromJsValue(rhs);

    *result = a->StrictEquals(b);
    return GET_RETURN_STATUS(env);
}

napi_status napi_get_prototype(napi_env env,
    napi_value object,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Object> obj;
    NODE_CHECK_TO_OBJECT(env, context, obj, object);

    v8::Local<v8::Value> val = obj->GetPrototype();
    *result = v8impl::JsValueFromV8LocalValue(val);
    return GET_RETURN_STATUS(env);
}

napi_status napi_create_object(napi_env env, napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    *result = v8impl::JsValueFromV8LocalValue(
        v8::Object::New(env->isolate));

    return napi_clear_last_error(env);
}

napi_status napi_create_array(napi_env env, napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    *result = v8impl::JsValueFromV8LocalValue(
        v8::Array::New(env->isolate));

    return napi_clear_last_error(env);
}

napi_status napi_create_array_with_length(napi_env env,
    size_t length,
    napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    *result = v8impl::JsValueFromV8LocalValue(
        v8::Array::New(env->isolate, length));

    return napi_clear_last_error(env);
}

napi_status napi_create_string_latin1(napi_env env,
    const char* str,
    size_t length,
    napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    auto isolate = env->isolate;
    auto str_maybe = v8::String::NewFromOneByte(isolate,
        reinterpret_cast<const uint8_t*>(str),
        v8::NewStringType::kInternalized,
        length);
    NODE_CHECK_MAYBE_EMPTY(env, str_maybe, napi_generic_failure);

    *result = v8impl::JsValueFromV8LocalValue(str_maybe.ToLocalChecked());
    return napi_clear_last_error(env);
}

napi_status napi_create_string_utf8(napi_env env,
    const char* str,
    size_t length,
    napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::String> s;
    NODE_CHECK_NEW_FROM_UTF8_LEN(env, s, str, length);

    *result = v8impl::JsValueFromV8LocalValue(s);
    return napi_clear_last_error(env);
}

napi_status napi_create_string_utf16(napi_env env,
    const char16_t* str,
    size_t length,
    napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    auto isolate = env->isolate;
    auto str_maybe = v8::String::NewFromTwoByte(isolate,
        reinterpret_cast<const uint16_t*>(str),
        v8::NewStringType::kInternalized,
        length);
    NODE_CHECK_MAYBE_EMPTY(env, str_maybe, napi_generic_failure);

    *result = v8impl::JsValueFromV8LocalValue(str_maybe.ToLocalChecked());
    return napi_clear_last_error(env);
}

napi_status napi_create_double(napi_env env,
    double value,
    napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    *result = v8impl::JsValueFromV8LocalValue(
        v8::Number::New(env->isolate, value));

    return napi_clear_last_error(env);
}

napi_status napi_create_int32(napi_env env,
    int32_t value,
    napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    *result = v8impl::JsValueFromV8LocalValue(v8::Integer::New(env->isolate, value));

    return napi_clear_last_error(env);
}

napi_status napi_create_uint32(napi_env env,
    uint32_t value,
    napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    *result = v8impl::JsValueFromV8LocalValue(
        v8::Integer::NewFromUnsigned(env->isolate, value));

    return napi_clear_last_error(env);
}

napi_status napi_create_int64(napi_env env,
    int64_t value,
    napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    *result = v8impl::JsValueFromV8LocalValue(
        v8::Number::New(env->isolate, static_cast<double>(value)));

    return napi_clear_last_error(env);
}

napi_status napi_create_bigint_int64(napi_env env,
    int64_t value,
    napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    //*result = v8impl::JsValueFromV8LocalValue(v8::BigInt::New(env->isolate, value));
    DebugBreak();

    return napi_clear_last_error(env);
}

napi_status napi_create_bigint_uint64(napi_env env,
    uint64_t value,
    napi_value* result)
{
    //     NODE_CHECK_ENV(env);
    //     NODE_CHECK_ARG(env, result);
    //
    //     *result = v8impl::JsValueFromV8LocalValue(v8::BigInt::NewFromUnsigned(env->isolate, value));
    DebugBreak();
    return napi_clear_last_error(env);
}

napi_status napi_create_bigint_words(napi_env env,
    int sign_bit,
    size_t word_count,
    const uint64_t* words,
    napi_value* result)
{
    //     NAPI_PREAMBLE(env);
    //     NODE_CHECK_ARG(env, words);
    //     NODE_CHECK_ARG(env, result);
    //
    //     v8::Local<v8::Context> context = env->isolate->GetCurrentContext();
    //
    //     if (word_count > INT_MAX) {
    //         napi_throw_range_error(env, nullptr, "Maximum BigInt size exceeded");
    //         return napi_set_last_error(env, napi_pending_exception);
    //     }
    //
    //     v8::MaybeLocal<v8::BigInt> b = v8::BigInt::NewFromWords(
    //         context, sign_bit, word_count, words);
    //
    //     if (try_catch.HasCaught()) {
    //         return napi_set_last_error(env, napi_pending_exception);
    //     } else {
    //         NODE_CHECK_MAYBE_EMPTY(env, b, napi_generic_failure);
    //         *result = v8impl::JsValueFromV8LocalValue(b.ToLocalChecked());
    //         return napi_clear_last_error(env);
    //     }
    DebugBreak();
    return napi_ok;
}

napi_status napi_get_boolean(napi_env env, bool value, napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;

    if (value) {
        *result = v8impl::JsValueFromV8LocalValue(v8::True(isolate));
    } else {
        *result = v8impl::JsValueFromV8LocalValue(v8::False(isolate));
    }

    return napi_clear_last_error(env);
}

napi_status napi_create_symbol(napi_env env,
    napi_value description,
    napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;

    if (description == nullptr) {
        *result = v8impl::JsValueFromV8LocalValue(v8::Symbol::New(isolate));
    } else {
        v8::Local<v8::Value> desc = v8impl::V8LocalValueFromJsValue(description);
        RETURN_STATUS_IF_FALSE(env, desc->IsString(), napi_string_expected);

        *result = v8impl::JsValueFromV8LocalValue(
            v8::Symbol::New(isolate, desc.As<v8::String>()));
    }

    return napi_clear_last_error(env);
}

static napi_status set_error_code(napi_env env,
    v8::Local<v8::Value> error,
    napi_value code,
    const char* code_cstring)
{
    if ((code != nullptr) || (code_cstring != nullptr)) {
        v8::Isolate* isolate = env->isolate;
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::Local<v8::Object> err_object = error.As<v8::Object>();

        v8::Local<v8::Value> code_value = v8impl::V8LocalValueFromJsValue(code);
        if (code != nullptr) {
            code_value = v8impl::V8LocalValueFromJsValue(code);
            RETURN_STATUS_IF_FALSE(env, code_value->IsString(), napi_string_expected);
        } else {
            NODE_CHECK_NEW_FROM_UTF8(env, code_value, code_cstring);
        }

        v8::Local<v8::Name> code_key;
        NODE_CHECK_NEW_FROM_UTF8(env, code_key, "code");

        v8::Maybe<bool> set_maybe = err_object->Set(context, code_key, code_value);
        RETURN_STATUS_IF_FALSE(env,
            set_maybe.FromMaybe(false),
            napi_generic_failure);

        // now update the name to be "name [code]" where name is the
        // original name and code is the code associated with the Error
        v8::Local<v8::String> name_string;
        NODE_CHECK_NEW_FROM_UTF8(env, name_string, "");
        v8::Local<v8::Name> name_key;
        NODE_CHECK_NEW_FROM_UTF8(env, name_key, "name");

        auto maybe_name = err_object->Get(context, name_key);
        if (!maybe_name.IsEmpty()) {
            v8::Local<v8::Value> name = maybe_name.ToLocalChecked();
            if (name->IsString()) {
                name_string = v8::String::Concat(name_string, name.As<v8::String>());
            }
        }
        name_string = v8::String::Concat(name_string, FIXED_ONE_BYTE_STRING(isolate, " ["));
        name_string = v8::String::Concat(name_string, code_value.As<v8::String>());
        name_string = v8::String::Concat(name_string, FIXED_ONE_BYTE_STRING(isolate, "]"));

        set_maybe = err_object->Set(context, name_key, name_string);
        RETURN_STATUS_IF_FALSE(env,
            set_maybe.FromMaybe(false),
            napi_generic_failure);
    }
    return napi_ok;
}

napi_status napi_create_error(napi_env env,
    napi_value code,
    napi_value msg,
    napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, msg);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> message_value = v8impl::V8LocalValueFromJsValue(msg);
    RETURN_STATUS_IF_FALSE(env, message_value->IsString(), napi_string_expected);

    v8::Local<v8::Value> error_obj = v8::Exception::Error(message_value.As<v8::String>());
    napi_status status = set_error_code(env, error_obj, code, nullptr);
    if (status != napi_ok)
        return status;

    *result = v8impl::JsValueFromV8LocalValue(error_obj);

    return napi_clear_last_error(env);
}

napi_status napi_create_type_error(napi_env env,
    napi_value code,
    napi_value msg,
    napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, msg);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> message_value = v8impl::V8LocalValueFromJsValue(msg);
    RETURN_STATUS_IF_FALSE(env, message_value->IsString(), napi_string_expected);

    v8::Local<v8::Value> error_obj = v8::Exception::TypeError(message_value.As<v8::String>());
    napi_status status = set_error_code(env, error_obj, code, nullptr);
    if (status != napi_ok)
        return status;

    *result = v8impl::JsValueFromV8LocalValue(error_obj);

    return napi_clear_last_error(env);
}

napi_status napi_create_range_error(napi_env env,
    napi_value code,
    napi_value msg,
    napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, msg);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> message_value = v8impl::V8LocalValueFromJsValue(msg);
    RETURN_STATUS_IF_FALSE(env, message_value->IsString(), napi_string_expected);

    v8::Local<v8::Value> error_obj = v8::Exception::RangeError(message_value.As<v8::String>());
    napi_status status = set_error_code(env, error_obj, code, nullptr);
    if (status != napi_ok)
        return status;

    *result = v8impl::JsValueFromV8LocalValue(error_obj);

    return napi_clear_last_error(env);
}

napi_status napi_typeof(napi_env env,
    napi_value value,
    napi_valuetype* result)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> v = v8impl::V8LocalValueFromJsValue(value);

    if (v->IsNumber()) {
        *result = napi_number;
        //     } else if (v->IsBigInt()) {
        //         *result = napi_bigint;
    } else if (v->IsString()) {
        *result = napi_string;
    } else if (v->IsFunction()) {
        // This test has to come before IsObject because IsFunction
        // implies IsObject
        *result = napi_function;
    } else if (v->IsExternal()) {
        // This test has to come before IsObject because IsExternal
        // implies IsObject
        *result = napi_external;
    } else if (v->IsObject()) {
        *result = napi_object;
    } else if (v->IsBoolean()) {
        *result = napi_boolean;
    } else if (v->IsUndefined()) {
        *result = napi_undefined;
    } else if (v->IsSymbol()) {
        *result = napi_symbol;
    } else if (v->IsNull()) {
        *result = napi_null;
    } else {
        // Should not get here unless V8 has added some new kind of value.
        return napi_set_last_error(env, napi_invalid_arg);
    }

    return napi_clear_last_error(env);
}

napi_status napi_get_undefined(napi_env env, napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    *result = v8impl::JsValueFromV8LocalValue(
        v8::Undefined(env->isolate));

    return napi_clear_last_error(env);
}

napi_status napi_get_null(napi_env env, napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    *result = v8impl::JsValueFromV8LocalValue(
        v8::Null(env->isolate));

    return napi_clear_last_error(env);
}

// Gets all callback info in a single call. (Ugly, but faster.)
napi_status napi_get_cb_info(
    napi_env env, // [in] NAPI environment handle
    napi_callback_info cbinfo, // [in] Opaque callback-info handle
    size_t* argc, // [in-out] Specifies the size of the provided argv array
    // and receives the actual count of args.
    napi_value* argv, // [out] Array of values
    napi_value* this_arg, // [out] Receives the JS 'this' arg for the call
    void** data)
{ // [out] Receives the data pointer for the callback.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, cbinfo);

    v8impl::CallbackWrapper* info = reinterpret_cast<v8impl::CallbackWrapper*>(cbinfo);

    if (argv != nullptr) {
        NODE_CHECK_ARG(env, argc);
        info->Args(argv, *argc);
    }
    if (argc != nullptr) {
        *argc = info->ArgsLength();
    }
    if (this_arg != nullptr) {
        *this_arg = info->This();
    }
    if (data != nullptr) {
        *data = info->Data();
    }

    return napi_clear_last_error(env);
}

napi_status napi_get_new_target(napi_env env,
    napi_callback_info cbinfo,
    napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, cbinfo);
    NODE_CHECK_ARG(env, result);

    v8impl::CallbackWrapper* info = reinterpret_cast<v8impl::CallbackWrapper*>(cbinfo);

    *result = info->GetNewTarget();
    return napi_clear_last_error(env);
}

napi_status napi_call_function(napi_env env,
    napi_value recv,
    napi_value func,
    size_t argc,
    const napi_value* argv,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, recv);
    if (argc > 0) {
        NODE_CHECK_ARG(env, argv);
    }

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Value> v8recv = v8impl::V8LocalValueFromJsValue(recv);

    v8::Local<v8::Function> v8func;
    NODE_CHECK_TO_FUNCTION(env, v8func, func);

    auto maybe = v8func->Call(context, v8recv, argc,
        reinterpret_cast<v8::Local<v8::Value>*>(const_cast<napi_value*>(argv)));

    if (try_catch.HasCaught()) {
        return napi_set_last_error(env, napi_pending_exception);
    } else {
        if (result != nullptr) {
            NODE_CHECK_MAYBE_EMPTY(env, maybe, napi_generic_failure);
            *result = v8impl::JsValueFromV8LocalValue(maybe.ToLocalChecked());
        }
        return napi_clear_last_error(env);
    }
}

napi_status napi_get_global(napi_env env, napi_value* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;
    // TODO(ianhall): what if we need the global object from a different
    // context in the same isolate?
    // Should napi_env be the current context rather than the current isolate?
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    *result = v8impl::JsValueFromV8LocalValue(context->Global());

    return napi_clear_last_error(env);
}

napi_status napi_throw(napi_env env, napi_value error)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, error);

    v8::Isolate* isolate = env->isolate;

    isolate->ThrowException(v8impl::V8LocalValueFromJsValue(error));
    // any VM calls after this point and before returning
    // to the javascript invoker will fail
    return napi_clear_last_error(env);
}

napi_status napi_throw_error(napi_env env,
    const char* code,
    const char* msg)
{
    NAPI_PREAMBLE(env);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::String> str;
    NODE_CHECK_NEW_FROM_UTF8(env, str, msg);

    v8::Local<v8::Value> error_obj = v8::Exception::Error(str);
    napi_status status = set_error_code(env, error_obj, nullptr, code);
    if (status != napi_ok)
        return status;

    isolate->ThrowException(error_obj);
    // any VM calls after this point and before returning
    // to the javascript invoker will fail
    return napi_clear_last_error(env);
}

napi_status napi_throw_type_error(napi_env env,
    const char* code,
    const char* msg)
{
    NAPI_PREAMBLE(env);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::String> str;
    NODE_CHECK_NEW_FROM_UTF8(env, str, msg);

    v8::Local<v8::Value> error_obj = v8::Exception::TypeError(str);
    napi_status status = set_error_code(env, error_obj, nullptr, code);
    if (status != napi_ok)
        return status;

    isolate->ThrowException(error_obj);
    // any VM calls after this point and before returning
    // to the javascript invoker will fail
    return napi_clear_last_error(env);
}

napi_status napi_throw_range_error(napi_env env,
    const char* code,
    const char* msg)
{
    NAPI_PREAMBLE(env);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::String> str;
    NODE_CHECK_NEW_FROM_UTF8(env, str, msg);

    v8::Local<v8::Value> error_obj = v8::Exception::RangeError(str);
    napi_status status = set_error_code(env, error_obj, nullptr, code);
    if (status != napi_ok)
        return status;

    isolate->ThrowException(error_obj);
    // any VM calls after this point and before returning
    // to the javascript invoker will fail
    return napi_clear_last_error(env);
}

napi_status napi_is_error(napi_env env, napi_value value, bool* result)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot
    // throw JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
    *result = val->IsNativeError();

    return napi_clear_last_error(env);
}

napi_status napi_get_value_double(napi_env env,
    napi_value value,
    double* result)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
    RETURN_STATUS_IF_FALSE(env, val->IsNumber(), napi_number_expected);

    *result = val.As<v8::Number>()->Value();

    return napi_clear_last_error(env);
}

napi_status napi_get_value_int32(napi_env env,
    napi_value value,
    int32_t* result)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);

    if (val->IsInt32()) {
        *result = val.As<v8::Int32>()->Value();
    } else {
        RETURN_STATUS_IF_FALSE(env, val->IsNumber(), napi_number_expected);

        // Empty context: https://github.com/nodejs/node/issues/14379
        v8::Local<v8::Context> context;
        *result = val->Int32Value(context).FromJust();
    }

    return napi_clear_last_error(env);
}

napi_status napi_get_value_uint32(napi_env env,
    napi_value value,
    uint32_t* result)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);

    if (val->IsUint32()) {
        *result = val.As<v8::Uint32>()->Value();
    } else {
        RETURN_STATUS_IF_FALSE(env, val->IsNumber(), napi_number_expected);

        // Empty context: https://github.com/nodejs/node/issues/14379
        v8::Local<v8::Context> context;
        *result = val->Uint32Value(context).FromJust();
    }

    return napi_clear_last_error(env);
}

napi_status napi_get_value_int64(napi_env env,
    napi_value value,
    int64_t* result)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);

    // This is still a fast path very likely to be taken.
    if (val->IsInt32()) {
        *result = val.As<v8::Int32>()->Value();
        return napi_clear_last_error(env);
    }

    RETURN_STATUS_IF_FALSE(env, val->IsNumber(), napi_number_expected);

    // v8::Value::IntegerValue() converts NaN, +Inf, and -Inf to INT64_MIN,
    // inconsistent with v8::Value::Int32Value() which converts those values to 0.
    // Special-case all non-finite values to match that behavior.
    double doubleValue = val.As<v8::Number>()->Value();
    if (/*std::*/isfinite(doubleValue)) {
        // Empty context: https://github.com/nodejs/node/issues/14379
        v8::Local<v8::Context> context;
        *result = val->IntegerValue(context).FromJust();
    } else {
        *result = 0;
    }

    return napi_clear_last_error(env);
}

napi_status napi_get_value_bigint_int64(napi_env env,
    napi_value value,
    int64_t* result,
    bool* lossless)
{
    //     NODE_CHECK_ENV(env);
    //     NODE_CHECK_ARG(env, value);
    //     NODE_CHECK_ARG(env, result);
    //     NODE_CHECK_ARG(env, lossless);
    //
    //     v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
    //
    //     RETURN_STATUS_IF_FALSE(env, val->IsBigInt(), napi_bigint_expected);
    //
    //     *result = val.As<v8::BigInt>()->Int64Value(lossless);
    //
    //     return napi_clear_last_error(env);
    DebugBreak();
    return napi_ok;
}

napi_status napi_get_value_bigint_uint64(napi_env env,
    napi_value value,
    uint64_t* result,
    bool* lossless)
{
    //     NODE_CHECK_ENV(env);
    //     NODE_CHECK_ARG(env, value);
    //     NODE_CHECK_ARG(env, result);
    //     NODE_CHECK_ARG(env, lossless);
    //
    //     v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
    //
    //     RETURN_STATUS_IF_FALSE(env, val->IsBigInt(), napi_bigint_expected);
    //
    //     *result = val.As<v8::BigInt>()->Uint64Value(lossless);
    //
    //     return napi_clear_last_error(env);
    DebugBreak();
    return napi_ok;
}

napi_status napi_get_value_bigint_words(napi_env env,
    napi_value value,
    int* sign_bit,
    size_t* word_count,
    uint64_t* words)
{
    //     NODE_CHECK_ENV(env);
    //     NODE_CHECK_ARG(env, value);
    //     NODE_CHECK_ARG(env, word_count);
    //
    //     v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
    //
    //     RETURN_STATUS_IF_FALSE(env, val->IsBigInt(), napi_bigint_expected);
    //
    //     v8::Local<v8::BigInt> big = val.As<v8::BigInt>();
    //
    //     int word_count_int = *word_count;
    //
    //     if (sign_bit == nullptr && words == nullptr) {
    //         word_count_int = big->WordCount();
    //     } else {
    //         NODE_CHECK_ARG(env, sign_bit);
    //         NODE_CHECK_ARG(env, words);
    //         big->ToWordsArray(sign_bit, &word_count_int, words);
    //     }
    //
    //     *word_count = word_count_int;
    //
    //     return napi_clear_last_error(env);
    DebugBreak();
    return napi_ok;
}

napi_status napi_get_value_bool(napi_env env, napi_value value, bool* result)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
    RETURN_STATUS_IF_FALSE(env, val->IsBoolean(), napi_boolean_expected);

    *result = val.As<v8::Boolean>()->Value();

    return napi_clear_last_error(env);
}

// Copies a JavaScript string into a LATIN-1 string buffer. The result is the
// number of bytes (excluding the null terminator) copied into buf.
// A sufficient buffer size should be greater than the length of string,
// reserving space for null terminator.
// If bufsize is insufficient, the string will be truncated and null terminated.
// If buf is NULL, this method returns the length of the string (in bytes)
// via the result parameter.
// The result argument is optional unless buf is NULL.
napi_status napi_get_value_string_latin1(napi_env env,
    napi_value value,
    char* buf,
    size_t bufsize,
    size_t* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
    RETURN_STATUS_IF_FALSE(env, val->IsString(), napi_string_expected);

    if (!buf) {
        NODE_CHECK_ARG(env, result);
        *result = val.As<v8::String>()->Length();
    } else {
        int copied = val.As<v8::String>()->WriteOneByte(
            reinterpret_cast<uint8_t*>(buf),
            0,
            bufsize - 1,
            v8::String::NO_NULL_TERMINATION);

        buf[copied] = '\0';
        if (result != nullptr) {
            *result = copied;
        }
    }

    return napi_clear_last_error(env);
}

// Copies a JavaScript string into a UTF-8 string buffer. The result is the
// number of bytes (excluding the null terminator) copied into buf.
// A sufficient buffer size should be greater than the length of string,
// reserving space for null terminator.
// If bufsize is insufficient, the string will be truncated and null terminated.
// If buf is NULL, this method returns the length of the string (in bytes)
// via the result parameter.
// The result argument is optional unless buf is NULL.
napi_status napi_get_value_string_utf8(napi_env env,
    napi_value value,
    char* buf,
    size_t bufsize,
    size_t* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
    RETURN_STATUS_IF_FALSE(env, val->IsString(), napi_string_expected);

    if (!buf) {
        NODE_CHECK_ARG(env, result);
        *result = val.As<v8::String>()->Utf8Length();
    } else {
        int copied = val.As<v8::String>()->WriteUtf8(
            buf,
            bufsize - 1,
            nullptr,
            v8::String::REPLACE_INVALID_UTF8 | v8::String::NO_NULL_TERMINATION);

        buf[copied] = '\0';
        if (result != nullptr) {
            *result = copied;
        }
    }

    return napi_clear_last_error(env);
}

// Copies a JavaScript string into a UTF-16 string buffer. The result is the
// number of 2-byte code units (excluding the null terminator) copied into buf.
// A sufficient buffer size should be greater than the length of string,
// reserving space for null terminator.
// If bufsize is insufficient, the string will be truncated and null terminated.
// If buf is NULL, this method returns the length of the string (in 2-byte
// code units) via the result parameter.
// The result argument is optional unless buf is NULL.
napi_status napi_get_value_string_utf16(napi_env env,
    napi_value value,
    char16_t* buf,
    size_t bufsize,
    size_t* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
    RETURN_STATUS_IF_FALSE(env, val->IsString(), napi_string_expected);

    if (!buf) {
        NODE_CHECK_ARG(env, result);
        // V8 assumes UTF-16 length is the same as the number of characters.
        *result = val.As<v8::String>()->Length();
    } else {
        int copied = val.As<v8::String>()->Write(
            reinterpret_cast<uint16_t*>(buf),
            0,
            bufsize - 1,
            v8::String::NO_NULL_TERMINATION);

        buf[copied] = '\0';
        if (result != nullptr) {
            *result = copied;
        }
    }

    return napi_clear_last_error(env);
}

napi_status napi_coerce_to_object(napi_env env,
    napi_value value,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Object> obj;
    NODE_CHECK_TO_OBJECT(env, context, obj, value);

    *result = v8impl::JsValueFromV8LocalValue(obj);
    return GET_RETURN_STATUS(env);
}

napi_status napi_coerce_to_bool(napi_env env,
    napi_value value,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Boolean> b;

    NODE_CHECK_TO_BOOL(env, context, b, value);

    *result = v8impl::JsValueFromV8LocalValue(b);
    return GET_RETURN_STATUS(env);
}

napi_status napi_coerce_to_number(napi_env env,
    napi_value value,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Number> num;

    NODE_CHECK_TO_NUMBER(env, context, num, value);

    *result = v8impl::JsValueFromV8LocalValue(num);
    return GET_RETURN_STATUS(env);
}

napi_status napi_coerce_to_string(napi_env env,
    napi_value value,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::String> str;

    NODE_CHECK_TO_STRING(env, context, str, value);

    *result = v8impl::JsValueFromV8LocalValue(str);
    return GET_RETURN_STATUS(env);
}

napi_status napi_wrap(napi_env env,
    napi_value js_object,
    void* native_object,
    napi_finalize finalize_cb,
    void* finalize_hint,
    napi_ref* result)
{
    return v8impl::Wrap<v8impl::retrievable>(env,
        js_object,
        native_object,
        finalize_cb,
        finalize_hint,
        result);
}

napi_status napi_unwrap(napi_env env, napi_value obj, void** result)
{
    return v8impl::Unwrap(env, obj, result, v8impl::KeepWrap);
}

napi_status napi_remove_wrap(napi_env env, napi_value obj, void** result)
{
    return v8impl::Unwrap(env, obj, result, v8impl::RemoveWrap);
}

napi_status napi_create_external(napi_env env,
    void* data,
    napi_finalize finalize_cb,
    void* finalize_hint,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;

    v8::Local<v8::Value> external_value = v8::External::New(isolate, data);

    // The Reference object will delete itself after invoking the finalizer
    // callback.
    v8impl::Reference::New(env,
        external_value,
        0,
        true,
        finalize_cb,
        data,
        finalize_hint);

    *result = v8impl::JsValueFromV8LocalValue(external_value);

    return napi_clear_last_error(env);
}

napi_status napi_get_value_external(napi_env env,
    napi_value value,
    void** result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
    RETURN_STATUS_IF_FALSE(env, val->IsExternal(), napi_invalid_arg);

    v8::Local<v8::External> external_value = val.As<v8::External>();
    *result = external_value->Value();

    return napi_clear_last_error(env);
}

// Set initial_refcount to 0 for a weak reference, >0 for a strong reference.
napi_status napi_create_reference(napi_env env,
    napi_value value,
    uint32_t initial_refcount,
    napi_ref* result)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> v8_value = v8impl::V8LocalValueFromJsValue(value);

    if (!(v8_value->IsObject() || v8_value->IsFunction())) {
        return napi_set_last_error(env, napi_object_expected);
    }

    v8impl::Reference* reference = v8impl::Reference::New(env, v8_value, initial_refcount, false);

    *result = reinterpret_cast<napi_ref>(reference);
    return napi_clear_last_error(env);
}

// Deletes a reference. The referenced value is released, and may be GC'd unless
// there are other references to it.
napi_status napi_delete_reference(napi_env env, napi_ref ref)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, ref);

    v8impl::Reference::Delete(reinterpret_cast<v8impl::Reference*>(ref));

    return napi_clear_last_error(env);
}

// Increments the reference count, optionally returning the resulting count.
// After this call the reference will be a strong reference because its
// refcount is >0, and the referenced object is effectively "pinned".
// Calling this when the refcount is 0 and the object is unavailable
// results in an error.
napi_status napi_reference_ref(napi_env env, napi_ref ref, uint32_t* result)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, ref);

    v8impl::Reference* reference = reinterpret_cast<v8impl::Reference*>(ref);
    uint32_t count = reference->Ref();

    if (result != nullptr) {
        *result = count;
    }

    return napi_clear_last_error(env);
}

// Decrements the reference count, optionally returning the resulting count. If
// the result is 0 the reference is now weak and the object may be GC'd at any
// time if there are no other references. Calling this when the refcount is
// already 0 results in an error.
napi_status napi_reference_unref(napi_env env, napi_ref ref, uint32_t* result)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, ref);

    v8impl::Reference* reference = reinterpret_cast<v8impl::Reference*>(ref);

    if (reference->RefCount() == 0) {
        return napi_set_last_error(env, napi_generic_failure);
    }

    uint32_t count = reference->Unref();

    if (result != nullptr) {
        *result = count;
    }

    return napi_clear_last_error(env);
}

// Attempts to get a referenced value. If the reference is weak, the value might
// no longer be available, in that case the call is still successful but the
// result is NULL.
napi_status napi_get_reference_value(napi_env env,
    napi_ref ref,
    napi_value* result)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, ref);
    NODE_CHECK_ARG(env, result);

    v8impl::Reference* reference = reinterpret_cast<v8impl::Reference*>(ref);
    *result = v8impl::JsValueFromV8LocalValue(reference->Get());

    return napi_clear_last_error(env);
}

napi_status napi_open_handle_scope(napi_env env, napi_handle_scope* result)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    *result = v8impl::JsHandleScopeFromV8HandleScope(
        new v8impl::HandleScopeWrapper(env->isolate));
    env->open_handle_scopes++;
    return napi_clear_last_error(env);
}

napi_status napi_close_handle_scope(napi_env env, napi_handle_scope scope)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, scope);
    if (env->open_handle_scopes == 0) {
        return napi_handle_scope_mismatch;
    }

    env->open_handle_scopes--;
    delete v8impl::V8HandleScopeFromJsHandleScope(scope);
    return napi_clear_last_error(env);
}

napi_status napi_open_escapable_handle_scope(
    napi_env env,
    napi_escapable_handle_scope* result)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    *result = v8impl::JsEscapableHandleScopeFromV8EscapableHandleScope(
        new v8impl::EscapableHandleScopeWrapper(env->isolate));
    env->open_handle_scopes++;
    return napi_clear_last_error(env);
}

napi_status napi_close_escapable_handle_scope(
    napi_env env,
    napi_escapable_handle_scope scope)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, scope);
    if (env->open_handle_scopes == 0) {
        return napi_handle_scope_mismatch;
    }

    delete v8impl::V8EscapableHandleScopeFromJsEscapableHandleScope(scope);
    env->open_handle_scopes--;
    return napi_clear_last_error(env);
}

napi_status napi_escape_handle(napi_env env,
    napi_escapable_handle_scope scope,
    napi_value escapee,
    napi_value* result)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, scope);
    NODE_CHECK_ARG(env, escapee);
    NODE_CHECK_ARG(env, result);

    v8impl::EscapableHandleScopeWrapper* s = v8impl::V8EscapableHandleScopeFromJsEscapableHandleScope(scope);
    if (!s->escape_called()) {
        *result = v8impl::JsValueFromV8LocalValue(
            s->Escape(v8impl::V8LocalValueFromJsValue(escapee)));
        return napi_clear_last_error(env);
    }
    return napi_set_last_error(env, napi_escape_called_twice);
}

napi_status napi_open_callback_scope(napi_env env,
    napi_value resource_object,
    napi_async_context async_context_handle,
    napi_callback_scope* result)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Context> context = env->isolate->GetCurrentContext();

    node::async_context* node_async_context = reinterpret_cast<node::async_context*>(async_context_handle);

    v8::Local<v8::Object> resource;
    NODE_CHECK_TO_OBJECT(env, context, resource, resource_object);

    *result = v8impl::JsCallbackScopeFromV8CallbackScope(
        new node::CallbackScope(env->isolate,
            resource,
            *node_async_context));

    env->open_callback_scopes++;
    return napi_clear_last_error(env);
}

napi_status napi_close_callback_scope(napi_env env, napi_callback_scope scope)
{
    // Omit NAPI_PREAMBLE and GET_RETURN_STATUS because V8 calls here cannot throw
    // JS exceptions.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, scope);
    if (env->open_callback_scopes == 0) {
        return napi_callback_scope_mismatch;
    }

    env->open_callback_scopes--;
    delete v8impl::V8CallbackScopeFromJsCallbackScope(scope);
    return napi_clear_last_error(env);
}

napi_status napi_new_instance(napi_env env,
    napi_value constructor,
    size_t argc,
    const napi_value* argv,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, constructor);
    if (argc > 0) {
        NODE_CHECK_ARG(env, argv);
    }
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Function> ctor;
    NODE_CHECK_TO_FUNCTION(env, ctor, constructor);

    auto maybe = ctor->NewInstance(context, argc,
        reinterpret_cast<v8::Local<v8::Value>*>(const_cast<napi_value*>(argv)));

    NODE_CHECK_MAYBE_EMPTY(env, maybe, napi_generic_failure);

    *result = v8impl::JsValueFromV8LocalValue(maybe.ToLocalChecked());
    return GET_RETURN_STATUS(env);
}

napi_status napi_instanceof(napi_env env,
    napi_value object,
    napi_value constructor,
    bool* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, object);
    NODE_CHECK_ARG(env, result);

    *result = false;

    v8::Local<v8::Object> ctor;
    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    NODE_CHECK_TO_OBJECT(env, context, ctor, constructor);

    if (!ctor->IsFunction()) {
        napi_throw_type_error(env,
            "ERR_NAPI_CONS_FUNCTION",
            "Constructor must be a function");

        return napi_set_last_error(env, napi_function_expected);
    }

    napi_status status = napi_generic_failure;

    //     v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(object);
    //     auto maybe_result = val->InstanceOf(context, ctor);
    //     NODE_CHECK_MAYBE_NOTHING(env, maybe_result, status);
    //     *result = maybe_result.FromJust();
    DebugBreak();
    return GET_RETURN_STATUS(env);
}

napi_status napi_async_init(napi_env env,
    napi_value async_resource,
    napi_value async_resource_name,
    napi_async_context* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, async_resource_name);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Object> v8_resource;
    if (async_resource != nullptr) {
        NODE_CHECK_TO_OBJECT(env, context, v8_resource, async_resource);
    } else {
        v8_resource = v8::Object::New(isolate);
    }

    v8::Local<v8::String> v8_resource_name;
    NODE_CHECK_TO_STRING(env, context, v8_resource_name, async_resource_name);

    // TODO(jasongin): Consider avoiding allocation here by using
    // a tagged pointer with 2×31 bit fields instead.
    node::async_context* async_context = new node::async_context();

    *async_context = node::EmitAsyncInit(isolate, v8_resource, v8_resource_name);
    *result = reinterpret_cast<napi_async_context>(async_context);

    return napi_clear_last_error(env);
}

napi_status napi_async_destroy(napi_env env,
    napi_async_context async_context)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, async_context);

    v8::Isolate* isolate = env->isolate;
    node::async_context* node_async_context = reinterpret_cast<node::async_context*>(async_context);
    //node::EmitAsyncDestroy(isolate, *node_async_context);
    DebugBreak();

    delete node_async_context;

    return napi_clear_last_error(env);
}

napi_status napi_make_callback(napi_env env,
    napi_async_context async_context,
    napi_value recv,
    napi_value func,
    size_t argc,
    const napi_value* argv,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, recv);
    if (argc > 0) {
        NODE_CHECK_ARG(env, argv);
    }

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Object> v8recv;
    NODE_CHECK_TO_OBJECT(env, context, v8recv, recv);

    v8::Local<v8::Function> v8func;
    NODE_CHECK_TO_FUNCTION(env, v8func, func);

    node::async_context* node_async_context = reinterpret_cast<node::async_context*>(async_context);
    if (node_async_context == nullptr) {
        static node::async_context empty_context;
        node_async_context = &empty_context;
    }

    v8::MaybeLocal<v8::Value> callback_result = node::MakeCallback(
        isolate, v8recv, v8func, argc,
        reinterpret_cast<v8::Local<v8::Value>*>(const_cast<napi_value*>(argv))
        //, *node_async_context
    );

    if (try_catch.HasCaught()) {
        return napi_set_last_error(env, napi_pending_exception);
    } else {
        NODE_CHECK_MAYBE_EMPTY(env, callback_result, napi_generic_failure);
        if (result != nullptr) {
            *result = v8impl::JsValueFromV8LocalValue(
                callback_result.ToLocalChecked());
        }
    }

    return GET_RETURN_STATUS(env);
}

// Methods to support catching exceptions
napi_status napi_is_exception_pending(napi_env env, bool* result)
{
    // NAPI_PREAMBLE is not used here: this function must execute when there is a
    // pending exception.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    *result = !env->last_exception.IsEmpty();
    return napi_clear_last_error(env);
}

napi_status napi_get_and_clear_last_exception(napi_env env,
    napi_value* result)
{
    // NAPI_PREAMBLE is not used here: this function must execute when there is a
    // pending exception.
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);

    if (env->last_exception.IsEmpty()) {
        return napi_get_undefined(env, result);
    } else {
        *result = v8impl::JsValueFromV8LocalValue(
            v8::Local<v8::Value>::New(env->isolate, env->last_exception));
        env->last_exception.Reset();
    }

    return napi_clear_last_error(env);
}

napi_status napi_create_buffer(napi_env env,
    size_t length,
    void** data,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, result);

    auto maybe = node::Buffer::New(env->isolate, length);

    NODE_CHECK_MAYBE_EMPTY(env, maybe, napi_generic_failure);

    v8::Local<v8::Object> buffer = maybe.ToLocalChecked();

    *result = v8impl::JsValueFromV8LocalValue(buffer);

    if (data != nullptr) {
        *data = node::Buffer::Data(buffer);
    }

    return GET_RETURN_STATUS(env);
}

napi_status napi_create_external_buffer(napi_env env,
    size_t length,
    void* data,
    napi_finalize finalize_cb,
    void* finalize_hint,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;

    // The finalizer object will delete itself after invoking the callback.
    v8impl::Finalizer* finalizer = v8impl::Finalizer::New(
        env, finalize_cb, nullptr, finalize_hint);

    auto maybe = node::Buffer::New(isolate,
        static_cast<char*>(data),
        length,
        v8impl::Finalizer::FinalizeBufferCallback,
        finalizer);

    NODE_CHECK_MAYBE_EMPTY(env, maybe, napi_generic_failure);

    *result = v8impl::JsValueFromV8LocalValue(maybe.ToLocalChecked());
    return GET_RETURN_STATUS(env);
    // Tell coverity that 'finalizer' should not be freed when we return
    // as it will be deleted when the buffer to which it is associated
    // is finalized.
    // coverity[leaked_storage]
}

napi_status napi_create_buffer_copy(napi_env env,
    size_t length,
    const void* data,
    void** result_data,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, result);

    auto maybe = node::Buffer::Copy(env->isolate,
        static_cast<const char*>(data), length);

    NODE_CHECK_MAYBE_EMPTY(env, maybe, napi_generic_failure);

    v8::Local<v8::Object> buffer = maybe.ToLocalChecked();
    *result = v8impl::JsValueFromV8LocalValue(buffer);

    if (result_data != nullptr) {
        *result_data = node::Buffer::Data(buffer);
    }

    return GET_RETURN_STATUS(env);
}

napi_status napi_is_buffer(napi_env env, napi_value value, bool* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    *result = node::Buffer::HasInstance(v8impl::V8LocalValueFromJsValue(value));
    return napi_clear_last_error(env);
}

napi_status napi_get_buffer_info(napi_env env,
    napi_value value,
    void** data,
    size_t* length)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);

    v8::Local<v8::Value> buffer = v8impl::V8LocalValueFromJsValue(value);

    if (data != nullptr) {
        *data = node::Buffer::Data(buffer);
    }
    if (length != nullptr) {
        *length = node::Buffer::Length(buffer);
    }

    return napi_clear_last_error(env);
}

napi_status napi_is_arraybuffer(napi_env env, napi_value value, bool* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
    *result = val->IsArrayBuffer();

    return napi_clear_last_error(env);
}

napi_status napi_create_arraybuffer(napi_env env,
    size_t byte_length,
    void** data,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::ArrayBuffer> buffer = v8::ArrayBuffer::New(isolate, byte_length);

    // Optionally return a pointer to the buffer's data, to avoid another call to
    // retrieve it.
    if (data != nullptr) {
        *data = buffer->GetContents().Data();
    }

    *result = v8impl::JsValueFromV8LocalValue(buffer);
    return GET_RETURN_STATUS(env);
}

napi_status napi_create_external_arraybuffer(napi_env env,
    void* external_data,
    size_t byte_length,
    napi_finalize finalize_cb,
    void* finalize_hint,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, result);

    v8::Isolate* isolate = env->isolate;
    v8::Local<v8::ArrayBuffer> buffer = v8::ArrayBuffer::New(isolate, external_data, byte_length);

    if (finalize_cb != nullptr) {
        // Create a self-deleting weak reference that invokes the finalizer
        // callback.
        v8impl::Reference::New(env,
            buffer,
            0,
            true,
            finalize_cb,
            external_data,
            finalize_hint);
    }

    *result = v8impl::JsValueFromV8LocalValue(buffer);
    return GET_RETURN_STATUS(env);
}

napi_status napi_get_arraybuffer_info(napi_env env,
    napi_value arraybuffer,
    void** data,
    size_t* byte_length)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, arraybuffer);

    v8::Local<v8::Value> value = v8impl::V8LocalValueFromJsValue(arraybuffer);
    RETURN_STATUS_IF_FALSE(env, value->IsArrayBuffer(), napi_invalid_arg);

    v8::ArrayBuffer::Contents contents = value.As<v8::ArrayBuffer>()->GetContents();

    if (data != nullptr) {
        *data = contents.Data();
    }

    if (byte_length != nullptr) {
        *byte_length = contents.ByteLength();
    }

    return napi_clear_last_error(env);
}

napi_status napi_is_typedarray(napi_env env, napi_value value, bool* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
    *result = val->IsTypedArray();

    return napi_clear_last_error(env);
}

napi_status napi_create_typedarray(napi_env env,
    napi_typedarray_type type,
    size_t length,
    napi_value arraybuffer,
    size_t byte_offset,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, arraybuffer);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> value = v8impl::V8LocalValueFromJsValue(arraybuffer);
    RETURN_STATUS_IF_FALSE(env, value->IsArrayBuffer(), napi_invalid_arg);

    v8::Local<v8::ArrayBuffer> buffer = value.As<v8::ArrayBuffer>();
    v8::Local<v8::TypedArray> typedArray;

    switch (type) {
    case napi_int8_array:
        CREATE_TYPED_ARRAY(
            env, Int8Array, 1, buffer, byte_offset, length, typedArray);
        break;
    case napi_uint8_array:
        CREATE_TYPED_ARRAY(
            env, Uint8Array, 1, buffer, byte_offset, length, typedArray);
        break;
    case napi_uint8_clamped_array:
        CREATE_TYPED_ARRAY(
            env, Uint8ClampedArray, 1, buffer, byte_offset, length, typedArray);
        break;
    case napi_int16_array:
        CREATE_TYPED_ARRAY(
            env, Int16Array, 2, buffer, byte_offset, length, typedArray);
        break;
    case napi_uint16_array:
        CREATE_TYPED_ARRAY(
            env, Uint16Array, 2, buffer, byte_offset, length, typedArray);
        break;
    case napi_int32_array:
        CREATE_TYPED_ARRAY(
            env, Int32Array, 4, buffer, byte_offset, length, typedArray);
        break;
    case napi_uint32_array:
        CREATE_TYPED_ARRAY(
            env, Uint32Array, 4, buffer, byte_offset, length, typedArray);
        break;
    case napi_float32_array:
        CREATE_TYPED_ARRAY(
            env, Float32Array, 4, buffer, byte_offset, length, typedArray);
        break;
    case napi_float64_array:
        CREATE_TYPED_ARRAY(
            env, Float64Array, 8, buffer, byte_offset, length, typedArray);
        break;
        //     case napi_bigint64_array:
        //         CREATE_TYPED_ARRAY(
        //             env, BigInt64Array, 8, buffer, byte_offset, length, typedArray);
        //         break;
        //     case napi_biguint64_array:
        //         CREATE_TYPED_ARRAY(
        //             env, BigUint64Array, 8, buffer, byte_offset, length, typedArray);
        //         break;
    default:
        return napi_set_last_error(env, napi_invalid_arg);
    }

    *result = v8impl::JsValueFromV8LocalValue(typedArray);
    return GET_RETURN_STATUS(env);
}

napi_status napi_get_typedarray_info(napi_env env,
    napi_value typedarray,
    napi_typedarray_type* type,
    size_t* length,
    void** data,
    napi_value* arraybuffer,
    size_t* byte_offset)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, typedarray);

    v8::Local<v8::Value> value = v8impl::V8LocalValueFromJsValue(typedarray);
    RETURN_STATUS_IF_FALSE(env, value->IsTypedArray(), napi_invalid_arg);

    v8::Local<v8::TypedArray> array = value.As<v8::TypedArray>();

    if (type != nullptr) {
        if (value->IsInt8Array()) {
            *type = napi_int8_array;
        } else if (value->IsUint8Array()) {
            *type = napi_uint8_array;
        } else if (value->IsUint8ClampedArray()) {
            *type = napi_uint8_clamped_array;
        } else if (value->IsInt16Array()) {
            *type = napi_int16_array;
        } else if (value->IsUint16Array()) {
            *type = napi_uint16_array;
        } else if (value->IsInt32Array()) {
            *type = napi_int32_array;
        } else if (value->IsUint32Array()) {
            *type = napi_uint32_array;
        } else if (value->IsFloat32Array()) {
            *type = napi_float32_array;
        } else if (value->IsFloat64Array()) {
            *type = napi_float64_array;
            //         } else if (value->IsBigInt64Array()) {
            //             *type = napi_bigint64_array;
            //         } else if (value->IsBigUint64Array()) {
            //             *type = napi_biguint64_array;
        }
    }

    if (length != nullptr) {
        *length = array->Length();
    }

    v8::Local<v8::ArrayBuffer> buffer = array->Buffer();
    if (data != nullptr) {
        *data = static_cast<uint8_t*>(buffer->GetContents().Data()) + array->ByteOffset();
    }

    if (arraybuffer != nullptr) {
        *arraybuffer = v8impl::JsValueFromV8LocalValue(buffer);
    }

    if (byte_offset != nullptr) {
        *byte_offset = array->ByteOffset();
    }

    return napi_clear_last_error(env);
}

napi_status napi_create_dataview(napi_env env,
    size_t byte_length,
    napi_value arraybuffer,
    size_t byte_offset,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, arraybuffer);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> value = v8impl::V8LocalValueFromJsValue(arraybuffer);
    RETURN_STATUS_IF_FALSE(env, value->IsArrayBuffer(), napi_invalid_arg);

    v8::Local<v8::ArrayBuffer> buffer = value.As<v8::ArrayBuffer>();
    if (byte_length + byte_offset > buffer->ByteLength()) {
        napi_throw_range_error(
            env,
            "ERR_NAPI_INVALID_DATAVIEW_ARGS",
            "byte_offset + byte_length should be less than or "
            "equal to the size in bytes of the array passed in");
        return napi_set_last_error(env, napi_pending_exception);
    }
    v8::Local<v8::DataView> DataView = v8::DataView::New(buffer, byte_offset,
        byte_length);

    *result = v8impl::JsValueFromV8LocalValue(DataView);
    return GET_RETURN_STATUS(env);
}

napi_status napi_is_dataview(napi_env env, napi_value value, bool* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, value);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> val = v8impl::V8LocalValueFromJsValue(value);
    *result = val->IsDataView();

    return napi_clear_last_error(env);
}

napi_status napi_get_dataview_info(napi_env env,
    napi_value dataview,
    size_t* byte_length,
    void** data,
    napi_value* arraybuffer,
    size_t* byte_offset)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, dataview);

    v8::Local<v8::Value> value = v8impl::V8LocalValueFromJsValue(dataview);
    RETURN_STATUS_IF_FALSE(env, value->IsDataView(), napi_invalid_arg);

    v8::Local<v8::DataView> array = value.As<v8::DataView>();

    if (byte_length != nullptr) {
        *byte_length = array->ByteLength();
    }

    v8::Local<v8::ArrayBuffer> buffer = array->Buffer();
    if (data != nullptr) {
        *data = static_cast<uint8_t*>(buffer->GetContents().Data()) + array->ByteOffset();
    }

    if (arraybuffer != nullptr) {
        *arraybuffer = v8impl::JsValueFromV8LocalValue(buffer);
    }

    if (byte_offset != nullptr) {
        *byte_offset = array->ByteOffset();
    }

    return napi_clear_last_error(env);
}

napi_status napi_get_version(napi_env env, uint32_t* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);
    *result = NAPI_VERSION;
    return napi_clear_last_error(env);
}

napi_status napi_get_node_version(napi_env env,
    const napi_node_version** result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, result);
    static const napi_node_version version = {
        NODE_MAJOR_VERSION,
        NODE_MINOR_VERSION,
        NODE_PATCH_VERSION,
        "NODE_RELEASE"
    };
    *result = &version;
    return napi_clear_last_error(env);
}

napi_status napi_adjust_external_memory(napi_env env,
    int64_t change_in_bytes,
    int64_t* adjusted_value)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, adjusted_value);

    *adjusted_value = env->isolate->AdjustAmountOfExternalAllocatedMemory(
        change_in_bytes);

    return napi_clear_last_error(env);
}

namespace {
namespace uvimpl {

    static napi_status ConvertUVErrorCode(int code)
    {
        switch (code) {
        case 0:
            return napi_ok;
        case UV_EINVAL:
            return napi_invalid_arg;
        case UV_ECANCELED:
            return napi_cancelled;
        }

        return napi_generic_failure;
    }

    // Wrapper around uv_work_t which calls user-provided callbacks.
    class Work : public node::AsyncResource, public node::ThreadPoolWork {
    private:
        explicit Work(napi_env env,
            v8::Local<v8::Object> async_resource,
            v8::Local<v8::String> async_resource_name,
            napi_async_execute_callback execute,
            napi_async_complete_callback complete = nullptr,
            void* data = nullptr)
            : AsyncResource(env->isolate, async_resource, *v8::String::Utf8Value(async_resource_name))
            , ThreadPoolWork(node::Environment::GetCurrent(env->isolate))
            , _env(env)
            , _data(data)
            , _execute(execute)
            , _complete(complete)
        {
        }

        virtual ~Work() { }

    public:
        static Work* New(napi_env env,
            v8::Local<v8::Object> async_resource,
            v8::Local<v8::String> async_resource_name,
            napi_async_execute_callback execute,
            napi_async_complete_callback complete,
            void* data)
        {
            return new Work(env, async_resource, async_resource_name,
                execute, complete, data);
        }

        static void Delete(Work* work)
        {
            delete work;
        }

        void DoThreadPoolWork() override
        {
            _execute(_env, _data);
        }

        void AfterThreadPoolWork(int status) override
        {
            if (_complete == nullptr)
                return;

            // Establish a handle scope here so that every callback doesn't have to.
            // Also it is needed for the exception-handling below.
            v8::HandleScope scope(_env->isolate);

            CallbackScope callback_scope(this);

            // We have to back up the env here because the `NAPI_CALL_INTO_MODULE` macro
            // makes use of it after the call into the module completes, but the module
            // may have deallocated **this**, and along with it the place where _env is
            // stored.
            napi_env env = _env;

            NAPI_CALL_INTO_MODULE(env,
                _complete(_env, ConvertUVErrorCode(status), _data),
                [env](v8::Local<v8::Value> local_err) {
                    // If there was an unhandled exception in the complete callback,
                    // report it as a fatal exception. (There is no JavaScript on the
                    // callstack that can possibly handle it.)
                    v8impl::trigger_fatal_exception(env, local_err);
                });

            // Note: Don't access `work` after this point because it was
            // likely deleted by the complete callback.
        }

    private:
        napi_env _env;
        void* _data;
        napi_async_execute_callback _execute;
        napi_async_complete_callback _complete;
    };

} // end of namespace uvimpl
} // end of anonymous namespace

#define CALL_UV(env, condition)                                  \
    do {                                                         \
        int result = (condition);                                \
        napi_status status = uvimpl::ConvertUVErrorCode(result); \
        if (status != napi_ok) {                                 \
            return napi_set_last_error(env, status, result);     \
        }                                                        \
    } while (0)

napi_status napi_create_async_work(napi_env env,
    napi_value async_resource,
    napi_value async_resource_name,
    napi_async_execute_callback execute,
    napi_async_complete_callback complete,
    void* data,
    napi_async_work* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, execute);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Context> context = env->isolate->GetCurrentContext();

    v8::Local<v8::Object> resource;
    if (async_resource != nullptr) {
        NODE_CHECK_TO_OBJECT(env, context, resource, async_resource);
    } else {
        resource = v8::Object::New(env->isolate);
    }

    v8::Local<v8::String> resource_name;
    NODE_CHECK_TO_STRING(env, context, resource_name, async_resource_name);

    uvimpl::Work* work = uvimpl::Work::New(env, resource, resource_name,
        execute, complete, data);

    *result = reinterpret_cast<napi_async_work>(work);

    return napi_clear_last_error(env);
}

napi_status napi_delete_async_work(napi_env env, napi_async_work work)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, work);

    uvimpl::Work::Delete(reinterpret_cast<uvimpl::Work*>(work));

    return napi_clear_last_error(env);
}

napi_status napi_get_uv_event_loop(napi_env env, uv_loop_t** loop)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, loop);
    *loop = env->loop;
    return napi_clear_last_error(env);
}

napi_status napi_queue_async_work(napi_env env, napi_async_work work)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, work);

    napi_status status;
    uv_loop_t* event_loop = nullptr;
    status = napi_get_uv_event_loop(env, &event_loop);
    if (status != napi_ok)
        return napi_set_last_error(env, status);

    uvimpl::Work* w = reinterpret_cast<uvimpl::Work*>(work);

    w->ScheduleWork();

    return napi_clear_last_error(env);
}

napi_status napi_cancel_async_work(napi_env env, napi_async_work work)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, work);

    uvimpl::Work* w = reinterpret_cast<uvimpl::Work*>(work);

    CALL_UV(env, w->CancelWork());

    return napi_clear_last_error(env);
}

napi_status napi_create_promise(napi_env env,
    napi_deferred* deferred,
    napi_value* promise)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, deferred);
    NODE_CHECK_ARG(env, promise);

    auto maybe = v8::Promise::Resolver::New(env->isolate->GetCurrentContext());
    NODE_CHECK_MAYBE_EMPTY(env, maybe, napi_generic_failure);

    auto v8_resolver = maybe.ToLocalChecked();
    auto v8_deferred = new node::Persistent<v8::Value>();
    v8_deferred->Reset(env->isolate, v8_resolver);

    *deferred = v8impl::JsDeferredFromNodePersistent(v8_deferred);
    *promise = v8impl::JsValueFromV8LocalValue(v8_resolver->GetPromise());
    return GET_RETURN_STATUS(env);
}

napi_status napi_resolve_deferred(napi_env env,
    napi_deferred deferred,
    napi_value resolution)
{
    return v8impl::ConcludeDeferred(env, deferred, resolution, true);
}

napi_status napi_reject_deferred(napi_env env,
    napi_deferred deferred,
    napi_value resolution)
{
    return v8impl::ConcludeDeferred(env, deferred, resolution, false);
}

napi_status napi_is_promise(napi_env env,
    napi_value promise,
    bool* is_promise)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, promise);
    NODE_CHECK_ARG(env, is_promise);

    *is_promise = v8impl::V8LocalValueFromJsValue(promise)->IsPromise();

    return napi_clear_last_error(env);
}

napi_status napi_run_script(napi_env env,
    napi_value script,
    napi_value* result)
{
    NAPI_PREAMBLE(env);
    NODE_CHECK_ARG(env, script);
    NODE_CHECK_ARG(env, result);

    v8::Local<v8::Value> v8_script = v8impl::V8LocalValueFromJsValue(script);

    if (!v8_script->IsString()) {
        return napi_set_last_error(env, napi_string_expected);
    }

    v8::Local<v8::Context> context = env->isolate->GetCurrentContext();

    auto maybe_script = v8::Script::Compile(context,
        v8::Local<v8::String>::Cast(v8_script));
    NODE_CHECK_MAYBE_EMPTY(env, maybe_script, napi_generic_failure);

    auto script_result = maybe_script.ToLocalChecked()->Run(context);
    NODE_CHECK_MAYBE_EMPTY(env, script_result, napi_generic_failure);

    *result = v8impl::JsValueFromV8LocalValue(script_result.ToLocalChecked());
    return GET_RETURN_STATUS(env);
}

napi_status napi_create_threadsafe_function(napi_env env,
    napi_value func,
    napi_value async_resource,
    napi_value async_resource_name,
    size_t max_queue_size,
    size_t initial_thread_count,
    void* thread_finalize_data,
    napi_finalize thread_finalize_cb,
    void* context,
    napi_threadsafe_function_call_js call_js_cb,
    napi_threadsafe_function* result)
{
    NODE_CHECK_ENV(env);
    NODE_CHECK_ARG(env, func);
    NODE_CHECK_ARG(env, async_resource_name);
    RETURN_STATUS_IF_FALSE(env, initial_thread_count > 0, napi_invalid_arg);
    NODE_CHECK_ARG(env, result);

    napi_status status = napi_ok;

    v8::Local<v8::Function> v8_func;
    NODE_CHECK_TO_FUNCTION(env, v8_func, func);

    v8::Local<v8::Context> v8_context = env->isolate->GetCurrentContext();

    v8::Local<v8::Object> v8_resource;
    if (async_resource == nullptr) {
        v8_resource = v8::Object::New(env->isolate);
    } else {
        NODE_CHECK_TO_OBJECT(env, v8_context, v8_resource, async_resource);
    }

    v8::Local<v8::String> v8_name;
    NODE_CHECK_TO_STRING(env, v8_context, v8_name, async_resource_name);

    v8impl::ThreadSafeFunction* ts_fn = new v8impl::ThreadSafeFunction(v8_func,
        v8_resource,
        v8_name,
        v8_context,
        initial_thread_count,
        context,
        max_queue_size,
        env,
        thread_finalize_data,
        thread_finalize_cb,
        call_js_cb);

    if (ts_fn == nullptr) {
        status = napi_generic_failure;
    } else {
        // Init deletes ts_fn upon failure.
        status = ts_fn->Init();
        if (status == napi_ok) {
            *result = reinterpret_cast<napi_threadsafe_function>(ts_fn);
        }
    }

    return napi_set_last_error(env, status);
}

napi_status
napi_get_threadsafe_function_context(napi_threadsafe_function func,
    void** result)
{
    NODE_CHECK(func != nullptr);
    NODE_CHECK(result != nullptr);

    *result = reinterpret_cast<v8impl::ThreadSafeFunction*>(func)->Context();
    return napi_ok;
}

napi_status
napi_call_threadsafe_function(napi_threadsafe_function func,
    void* data,
    napi_threadsafe_function_call_mode is_blocking)
{
    NODE_CHECK(func != nullptr);
    return reinterpret_cast<v8impl::ThreadSafeFunction*>(func)->Push(data,
        is_blocking);
}

napi_status
napi_acquire_threadsafe_function(napi_threadsafe_function func)
{
    NODE_CHECK(func != nullptr);
    return reinterpret_cast<v8impl::ThreadSafeFunction*>(func)->Acquire();
}

napi_status
napi_release_threadsafe_function(napi_threadsafe_function func,
    napi_threadsafe_function_release_mode mode)
{
    NODE_CHECK(func != nullptr);
    return reinterpret_cast<v8impl::ThreadSafeFunction*>(func)->Release(mode);
}

napi_status
napi_unref_threadsafe_function(napi_env env, napi_threadsafe_function func)
{
    NODE_CHECK(func != nullptr);
    return reinterpret_cast<v8impl::ThreadSafeFunction*>(func)->Unref();
}

napi_status
napi_ref_threadsafe_function(napi_env env, napi_threadsafe_function func)
{
    NODE_CHECK(func != nullptr);
    return reinterpret_cast<v8impl::ThreadSafeFunction*>(func)->Ref();
}

napi_status napi_add_finalizer(napi_env env,
    napi_value js_object,
    void* native_object,
    napi_finalize finalize_cb,
    void* finalize_hint,
    napi_ref* result)
{
    return v8impl::Wrap<v8impl::anonymous>(env, js_object, native_object, finalize_cb, finalize_hint, result);
}

napi_status napi_set_instance_data(napi_env env,
    void* data,
    napi_finalize finalize_cb,
    void* finalize_hint)
{
    env->instance_data = data;
    env->finalize_cb = finalize_cb;
    env->finalize_hint = finalize_hint;

    char* output = (char*)malloc(0x100);
    sprintf(output, "napi_set_instance_data: env:%p data:%p\n", env, data);
    OutputDebugStringA(output);
    free(output);

    return napi_clear_last_error(env);
}

napi_status napi_get_instance_data(napi_env env, void** data)
{
    *data = env->instance_data;

    char* output = (char*)malloc(0x100);
    sprintf(output, "napi_get_instance_data: env:%p data:%p\n", env, *data);
    OutputDebugStringA(output);
    free(output);

    return napi_clear_last_error(env);
}