
#ifndef common_api_GetConstructorFromTls_h
#define common_api_GetConstructorFromTls_h

#include "base/threading/thread_local.h"

namespace atom {

class V8PersistentTls {
public:
    static v8::Persistent<v8::Function>* get(base::ThreadLocalPointer<v8::Persistent<v8::Function> >** constructorTlsKey)
    {
        v8::Persistent<v8::Function>* constructor = nullptr;
        if (0 == *constructorTlsKey)
            *constructorTlsKey = new base::ThreadLocalPointer<v8::Persistent<v8::Function> >();

        constructor = (*constructorTlsKey)->Get();
        if (!constructor) {
            constructor = new v8::Persistent<v8::Function>();
            (*constructorTlsKey)->Set(constructor);
        }
        return constructor;
    }
};

}

#endif // common_api_GetConstructorFromTls_h