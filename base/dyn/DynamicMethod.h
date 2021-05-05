/*
 * DynamicMethod.h
 *
 *  Created on: 2013-2-28
 *      Author: launliu
 */

#ifndef DYNAMICMETHOD_H_
#define DYNAMICMETHOD_H_

#include "DynamicLibrary.h"
#include <assert.h>
#include <stdio.h>

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(n) (sizeof(n) / sizeof(n[0]))
#endif

namespace tencent {

#define DEFINE_DYNAMIC_NEW_CLASS(ClassName, VarName, Constructor, ...) \
    ClassName* VarName = (ClassName*)malloc(sizeof(ClassName) + 100);  \
    memset(VarName, 0, sizeof(ClassName) + 100);                       \
    Constructor.call(VarName, ##__VA_ARGS__);

template <typename ObjectType, typename RetType>
class DynamicClassMethod {
public:
    DynamicClassMethod(DynamicLibrary& lib, const char* symbol)
        : m_funcPtr(lib.isValid() ? lib.resolveSymbol(symbol) : 0)
    {
    }

    DynamicClassMethod(DynamicLibrary& lib, const char* const* symbols, size_t length)
        : m_funcPtr(0)
    {
        if (!lib.isValid())
            return;
        for (size_t i = 0; i < length; i++) {
            if ((m_funcPtr = lib.resolveSymbol(symbols[i])) != 0)
                break;
        }
    }

    bool isValid() const { return m_funcPtr; }
    void* funcPtr() const { return m_funcPtr; }

    RetType call(ObjectType* instance)
    {
        typedef RetType (*FuncType)(ObjectType*);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(instance);
    }

    template <typename ArgType1>
    RetType call(ObjectType* instance, ArgType1 arg1)
    {
        typedef RetType (*FuncType)(ObjectType*, ArgType1);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(instance, arg1);
    }

    template <typename ArgType1, typename ArgType2>
    RetType call(ObjectType* instance, ArgType1 arg1, ArgType2 arg2)
    {
        typedef RetType (*FuncType)(ObjectType*, ArgType1, ArgType2);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(instance, arg1, arg2);
    }

    template <typename ArgType1, typename ArgType2, typename ArgType3>
    RetType call(ObjectType* instance, ArgType1 arg1, ArgType2 arg2, ArgType3 arg3)
    {
        typedef RetType (*FuncType)(ObjectType*, ArgType1, ArgType2, ArgType3);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(instance, arg1, arg2, arg3);
    }

    template <typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4>
    RetType call(ObjectType* instance, ArgType1 arg1, ArgType2 arg2, ArgType3 arg3, ArgType4 arg4)
    {
        typedef RetType (*FuncType)(ObjectType*, ArgType1, ArgType2, ArgType3, ArgType4);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(instance, arg1, arg2, arg3, arg4);
    }

    template <typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4, typename ArgType5>
    RetType call(ObjectType* instance, ArgType1 arg1, ArgType2 arg2, ArgType3 arg3, ArgType4 arg4, ArgType5 arg5)
    {
        typedef RetType (*FuncType)(ObjectType*, ArgType1, ArgType2, ArgType3, ArgType4, ArgType5);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(instance, arg1, arg2, arg3, arg4, arg5);
    }
    template <typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4, typename ArgType5, typename ArgType6>
    RetType call(ObjectType* instance, ArgType1 arg1, ArgType2 arg2, ArgType3 arg3, ArgType4 arg4, ArgType5 arg5, ArgType6 arg6)
    {
        typedef RetType (*FuncType)(ObjectType*, ArgType1, ArgType2, ArgType3, ArgType4, ArgType5, ArgType6);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(instance, arg1, arg2, arg3, arg4, arg5, arg6);
    }
    template <typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4, typename ArgType5, typename ArgType6, typename ArgType7, typename ArgType8, typename ArgType9>
    RetType call(ObjectType* instance, ArgType1 arg1, ArgType2 arg2, ArgType3 arg3, ArgType4 arg4, ArgType5 arg5, ArgType6 arg6, ArgType7 arg7, ArgType8 arg8, ArgType9 arg9)
    {
        typedef RetType (*FuncType)(ObjectType*, ArgType1, ArgType2, ArgType3, ArgType4, ArgType5, ArgType6, ArgType7, ArgType8, ArgType9);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(instance, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    }

    template <typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4, typename ArgType5, typename ArgType6, typename ArgType7, typename ArgType8, typename ArgType9, typename ArgType10>
    RetType call(ObjectType* instance, ArgType1 arg1, ArgType2 arg2, ArgType3 arg3, ArgType4 arg4, ArgType5 arg5, ArgType6 arg6, ArgType7 arg7, ArgType8 arg8, ArgType9 arg9, ArgType10 arg10)
    {
        typedef RetType (*FuncType)(ObjectType*, ArgType1, ArgType2, ArgType3, ArgType4, ArgType5, ArgType6, ArgType7, ArgType8, ArgType9, ArgType10);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(instance, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
    }

private:
    void* m_funcPtr;
};

int computeVirtualOffset(void* obj, void* method);
void* getVirtualMethodAtOffset(void* instance, int offset);

template <typename ObjectType, typename RetType>
class DynamicClassVirtualMethod {
public:
    DynamicClassVirtualMethod(ObjectType* matchedInstance, void* ptr)
    {
        assert(ptr != NULL);
        m_virtualOffset = computeVirtualOffset(reinterpret_cast<void*>(matchedInstance), ptr);
    }

    DynamicClassVirtualMethod(ObjectType* matchedInstance, DynamicLibrary& lib, const char* symbol)
    {
        setSymbol(matchedInstance, lib, symbol);
    }

    DynamicClassVirtualMethod()
    {
        m_virtualOffset = -1;
    }

    void setSymbol(ObjectType* matchedInstance, DynamicLibrary& lib, const char* symbol)
    {
        assert(lib.isValid());
        void* ptr = lib.resolveSymbol(symbol);
        m_virtualOffset = ptr ? computeVirtualOffset(reinterpret_cast<void*>(matchedInstance), ptr) : -1;
    }

    void setSymbols(ObjectType* matchedInstance, DynamicLibrary& lib, const char** symbols, size_t size, int* matchedIndex = 0)
    {
        assert(lib.isValid());
        void* ptr = 0;
        for (size_t i = 0; i < size; i++) {
            if ((ptr = lib.resolveSymbol(symbols[i])) != 0) {
                if (matchedIndex)
                    *matchedIndex = i;
                break;
            }
        }
        m_virtualOffset = ptr ? computeVirtualOffset(reinterpret_cast<void*>(matchedInstance), ptr) : -1;
    }

    bool isValid() const { return m_virtualOffset > 0; }

    int getVirtualOffset() const { return m_virtualOffset; }

    RetType call(ObjectType* instance)
    {
        typedef RetType (*FuncType)(ObjectType*);
        assert(isValid());
        return (reinterpret_cast<FuncType>(getVirtualMethod(instance)))(instance);
    }

    template <typename ArgType1>
    RetType call(ObjectType* instance, ArgType1 arg1)
    {
        typedef RetType (*FuncType)(ObjectType*, ArgType1);
        assert(isValid());
        return (reinterpret_cast<FuncType>(getVirtualMethod(instance)))(instance, arg1);
    }

    template <typename ArgType1, typename ArgType2>
    RetType call(ObjectType* instance, ArgType1 arg1, ArgType2 arg2)
    {
        typedef RetType (*FuncType)(ObjectType*, ArgType1, ArgType2);
        assert(isValid());
        return (reinterpret_cast<FuncType>(getVirtualMethod(instance)))(instance, arg1, arg2);
    }

    template <typename ArgType1, typename ArgType2, typename ArgType3>
    RetType call(ObjectType* instance, ArgType1 arg1, ArgType2 arg2, ArgType3 arg3)
    {
        typedef RetType (*FuncType)(ObjectType*, ArgType1, ArgType2, ArgType3);
        assert(isValid());
        return (reinterpret_cast<FuncType>(getVirtualMethod(instance)))(instance, arg1, arg2, arg3);
    }

    template <typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4>
    RetType call(ObjectType* instance, ArgType1 arg1, ArgType2 arg2, ArgType3 arg3, ArgType4 arg4)
    {
        typedef RetType (*FuncType)(ObjectType*, ArgType1, ArgType2, ArgType3, ArgType4);
        assert(isValid());
        return (reinterpret_cast<FuncType>(getVirtualMethod(instance)))(instance, arg1, arg2, arg3, arg4);
    }

    template <typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4, typename ArgType5>
    RetType call(ObjectType* instance, ArgType1 arg1, ArgType2 arg2, ArgType3 arg3, ArgType4 arg4, ArgType5 arg5)
    {
        typedef RetType (*FuncType)(ObjectType*, ArgType1, ArgType2, ArgType3, ArgType4, ArgType5);
        assert(isValid());
        return (reinterpret_cast<FuncType>(getVirtualMethod(instance)))(instance, arg1, arg2, arg3, arg4, arg5);
    }
    template <typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4, typename ArgType5, typename ArgType6>
    RetType call(ObjectType* instance, ArgType1 arg1, ArgType2 arg2, ArgType3 arg3, ArgType4 arg4, ArgType5 arg5, ArgType6 arg6)
    {
        typedef RetType (*FuncType)(ObjectType*, ArgType1, ArgType2, ArgType3, ArgType4, ArgType5, ArgType6);
        assert(isValid());
        return (reinterpret_cast<FuncType>(getVirtualMethod(instance)))(instance, arg1, arg2, arg3, arg4, arg5, arg6);
    }

public:
    inline void* getVirtualMethod(ObjectType* instance)
    {
        return getVirtualMethodAtOffset(instance, m_virtualOffset);
    }

private:
    int m_virtualOffset;
};

template <typename RetType>
class DynamicMethod {
public:
    DynamicMethod(DynamicLibrary& lib, const char* symbol)
        : m_funcPtr(lib.resolveSymbol(symbol))
    {
    }

    DynamicMethod(DynamicLibrary& lib, const char** symbols, size_t length)
        : m_funcPtr(0)
    {
        for (size_t i = 0; i < length; i++) {
            if ((m_funcPtr = lib.resolveSymbol(symbols[i])) != 0)
                break;
        }
    }

    template <typename FuncType>
    DynamicMethod(FuncType func)
        : m_funcPtr((void*)func)
    {
    }

    bool isValid() const { return m_funcPtr; }

    RetType call()
    {
        typedef RetType (*FuncType)();
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))();
    }

    template <typename ArgType1>
    RetType call(ArgType1 arg1)
    {
        typedef RetType (*FuncType)(ArgType1);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(arg1);
    }

    template <typename ArgType1, typename ArgType2>
    RetType call(ArgType1 arg1, ArgType2 arg2)
    {
        typedef RetType (*FuncType)(ArgType1, ArgType2);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(arg1, arg2);
    }

    template <typename ArgType1, typename ArgType2, typename ArgType3>
    RetType call(ArgType1 arg1, ArgType2 arg2, ArgType3 arg3)
    {
        typedef RetType (*FuncType)(ArgType1, ArgType2, ArgType3);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(arg1, arg2, arg3);
    }

    template <typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4>
    RetType call(ArgType1 arg1, ArgType2 arg2, ArgType3 arg3, ArgType4 arg4)
    {
        typedef RetType (*FuncType)(ArgType1, ArgType2, ArgType3, ArgType4);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(arg1, arg2, arg3, arg4);
    }

    template <typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4, typename ArgType5>
    RetType call(ArgType1 arg1, ArgType2 arg2, ArgType3 arg3, ArgType4 arg4, ArgType5 arg5)
    {
        typedef RetType (*FuncType)(ArgType1, ArgType2, ArgType3, ArgType4, ArgType5);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(arg1, arg2, arg3, arg4, arg5);
    }
    template <typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4, typename ArgType5, typename ArgType6>
    RetType call(ArgType1 arg1, ArgType2 arg2, ArgType3 arg3, ArgType4 arg4, ArgType5 arg5, ArgType6 arg6)
    {
        typedef RetType (*FuncType)(ArgType1, ArgType2, ArgType3, ArgType4, ArgType5, ArgType6);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(arg1, arg2, arg3, arg4, arg5, arg6);
    }
    template <typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4, typename ArgType5, typename ArgType6, typename ArgType7>
    RetType call(ArgType1 arg1, ArgType2 arg2, ArgType3 arg3, ArgType4 arg4, ArgType5 arg5, ArgType6 arg6, ArgType7 arg7)
    {
        typedef RetType (*FuncType)(ArgType1, ArgType2, ArgType3, ArgType4, ArgType5, ArgType6, ArgType7);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
    template <typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4, typename ArgType5, typename ArgType6, typename ArgType7, typename ArgType8>
    RetType call(ArgType1 arg1, ArgType2 arg2, ArgType3 arg3, ArgType4 arg4, ArgType5 arg5, ArgType6 arg6, ArgType7 arg7, ArgType8 arg8)
    {
        typedef RetType (*FuncType)(ArgType1, ArgType2, ArgType3, ArgType4, ArgType5, ArgType6, ArgType7, ArgType8);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    }
    template <typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4, typename ArgType5, typename ArgType6, typename ArgType7, typename ArgType8, typename ArgType9>
    RetType call(ArgType1 arg1, ArgType2 arg2, ArgType3 arg3, ArgType4 arg4, ArgType5 arg5, ArgType6 arg6, ArgType7 arg7, ArgType8 arg8, ArgType9 arg9)
    {
        typedef RetType (*FuncType)(ArgType1, ArgType2, ArgType3, ArgType4, ArgType5, ArgType6, ArgType7, ArgType8, ArgType9);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    }
    template <typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4, typename ArgType5, typename ArgType6, typename ArgType7, typename ArgType8, typename ArgType9, typename ArgType10>
    RetType call(ArgType1 arg1, ArgType2 arg2, ArgType3 arg3, ArgType4 arg4, ArgType5 arg5, ArgType6 arg6, ArgType7 arg7, ArgType8 arg8, ArgType9 arg9, ArgType10 arg10)
    {
        typedef RetType (*FuncType)(ArgType1, ArgType2, ArgType3, ArgType4, ArgType5, ArgType6, ArgType7, ArgType8, ArgType9, ArgType10);
        assert(isValid());
        return (reinterpret_cast<FuncType>(m_funcPtr))(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
    }

private:
    void* m_funcPtr;
};

} //namespace tencent

#endif /* DYNAMICMETHOD_H_ */
