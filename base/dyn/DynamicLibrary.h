/*
 * LIbrary.h
 *
 *  Created on: 2013年2月28日
 *      Author: launliu
 */

#ifndef DYNAMICLIBRARY_H_
#define DYNAMICLIBRARY_H_

#include "base/android/jni_android.h"
#include "base/files/file_path.h"

namespace tencent {

class DynamicLibrary {
public:
    DynamicLibrary(const char* path, bool systemLibrary = true);
    DynamicLibrary()
        : m_fd(0) {};
    virtual ~DynamicLibrary();

    void resolveLibrary(const char* path, bool systemLibrary = true);

    bool isValid() const { return m_fd; }

    void* resolveSymbol(const char*);
    void* fd() const { return m_fd; }

    static void* loadLibrary(const char* fileName);
    static void* loadSystemLibrary(const char* libName);

    static const base::FilePath& getDynLibPath();

private:
    void* m_fd;
};

extern DynamicLibrary& skiaLibrary();
extern DynamicLibrary& minikinLibrary();
extern DynamicLibrary& runtimeLibrary();

extern DynamicLibrary& gnucLibrary();

#ifdef TENCENT_PLUGINS
extern DynamicLibrary& guiLibrary();
extern DynamicLibrary& surfaceflingerClientLibrary();
extern DynamicLibrary& uiLibrary();
#endif

extern DynamicLibrary& sharpPLibrary();

extern DynamicLibrary& wxHevcLibrary();

} /* namespace tencent */

#endif /* LIBRARY_H_ */
