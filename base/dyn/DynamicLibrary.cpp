/*
 * CppResolver.cpp
 *
 *  Created on: 2013年2月26日
 *      Author: launliu
 */
#include <dlfcn.h>
#include <unistd.h>

#include "DynamicLibrary.h"

#include "base/android/jni_string.h"
#include "base/android/path_utils.h"

#define DEFINE_STATIC_LOCAL(type, name, arguments) \
    static type& name = *new type arguments

#define DEFINE_STATIC_LOCAL_EMPTY(type, name) \
    static type& name = *new type

#define ISBIT64 (sizeof(void*) == 8)

namespace tencent {

DynamicLibrary::DynamicLibrary(const char* path, bool systemLibrary)
{
    resolveLibrary(path, systemLibrary);
}

DynamicLibrary::~DynamicLibrary()
{
    if (m_fd)
        dlclose(m_fd);
}

void DynamicLibrary::resolveLibrary(const char* path, bool systemLibrary)
{
    m_fd = systemLibrary ? loadSystemLibrary(path) : loadLibrary(path);
    if (!m_fd) {
        //		ALOGV("library", "Can't load library %s: %s", path, dlerror());
    }
}

void* DynamicLibrary::resolveSymbol(const char* symbol)
{
    return m_fd ? dlsym(m_fd, symbol) : NULL;
}

void* DynamicLibrary::loadLibrary(const char* fileName)
{
    //	static OwnPtr< Vector<String> > sLibSearchPaths = adoptPtr(new Vector<String>(AppInfo::getLibrarySearchPaths()));
    //
    //	String path;
    //	for (Vector<String>::const_iterator iter = sLibSearchPaths->begin();
    //			iter != sLibSearchPaths->end(); ++iter) {
    //		path = *iter;
    //		path.append("/");
    //		path.append(fileName);

    if (void* ret = ::dlopen(fileName, RTLD_LAZY))
        return ret;
    //	}

    return NULL;
}

void* DynamicLibrary::loadSystemLibrary(const char* libName)
{
    return ::dlopen(libName, RTLD_LAZY);
}

DynamicLibrary& skiaLibrary()
{
    if (ISBIT64) {
        DEFINE_STATIC_LOCAL(DynamicLibrary, library, ("/system/lib64/libskia.so"));
        return library;
    } else {
        DEFINE_STATIC_LOCAL(DynamicLibrary, library, ("/system/lib/libskia.so"));
        return library;
    }
}

DynamicLibrary& minikinLibrary()
{
    if (ISBIT64) {
        DEFINE_STATIC_LOCAL(DynamicLibrary, library, ("/system/lib64/libminikin.so"));
        return library;
    } else {
        DEFINE_STATIC_LOCAL(DynamicLibrary, library, ("/system/lib/libminikin.so"));
        return library;
    }
}

DynamicLibrary& runtimeLibrary()
{
    if (ISBIT64) {
        DEFINE_STATIC_LOCAL(DynamicLibrary, library, ("/system/lib64/libandroid_runtime.so"));
        return library;
    } else {
        DEFINE_STATIC_LOCAL(DynamicLibrary, library, ("/system/lib/libandroid_runtime.so"));
        return library;
    }
}

DynamicLibrary& gnucLibrary()
{
    if (ISBIT64) {
        static DynamicLibrary library("/system/lib64/libc.so");
        return library;
    } else {
        static DynamicLibrary library("/system/lib/libc.so");
        return library;
    }
}

#ifdef TENCENT_PLUGINS
DynamicLibrary& guiLibrary()
{
    DEFINE_STATIC_LOCAL(DynamicLibrary, library, ("/system/lib/libgui.so"));
    return library;
}

DynamicLibrary& surfaceflingerClientLibrary()
{
    DEFINE_STATIC_LOCAL(DynamicLibrary, library, ("/system/lib/libsurfaceflinger_client.so"));
    return library;
}

DynamicLibrary& uiLibrary()
{
    DEFINE_STATIC_LOCAL(DynamicLibrary, library, ("/system/lib/libui.so"));
    return library;
}
#endif

DynamicLibrary& sharpPLibrary()
{
    DEFINE_STATIC_LOCAL_EMPTY(DynamicLibrary, library);

    if (library.isValid()) {
        return library;
    }

    base::FilePath dynLibPath;
    bool ret = base::android::GetNativeLibraryDirectory(&dynLibPath);
    if (!ret) {
        return library;
    }

    std::string sharpPPath = dynLibPath.value() + "/libSharpPDecoder.so";
    library.resolveLibrary(sharpPPath.c_str(), false);

    return library;
}

DynamicLibrary& wxHevcLibrary()
{
    DEFINE_STATIC_LOCAL_EMPTY(DynamicLibrary, library);

    if (library.isValid()) {
        return library;
    }

    base::FilePath dynLibPath;
    bool ret = base::android::GetNativeLibraryDirectory(&dynLibPath);
    if (!ret) {
        return library;
    }

    std::string wxHevcPath = dynLibPath.value() + "/libWxHevcDecoder.so";
    library.resolveLibrary(wxHevcPath.c_str(), false);

    return library;
}

} /* namespace tencent */
