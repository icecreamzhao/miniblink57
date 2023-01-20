/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkTypes.h"
#if defined(SK_BUILD_FOR_WIN32)
=======
>>>>>>> miniblink49

#include "SkDWrite.h"
#include "SkHRESULT.h"
#include "SkOnce.h"
#include "SkString.h"

#include <dwrite.h>

<<<<<<< HEAD
static IDWriteFactory* gDWriteFactory = nullptr;

static void release_dwrite_factory()
{
=======
static IDWriteFactory* gDWriteFactory = NULL;

static void release_dwrite_factory() {
>>>>>>> miniblink49
    if (gDWriteFactory) {
        gDWriteFactory->Release();
    }
}

<<<<<<< HEAD
static void create_dwrite_factory(IDWriteFactory** factory)
{
=======
static void create_dwrite_factory(IDWriteFactory** factory) {
>>>>>>> miniblink49
    typedef decltype(DWriteCreateFactory)* DWriteCreateFactoryProc;
    DWriteCreateFactoryProc dWriteCreateFactoryProc = reinterpret_cast<DWriteCreateFactoryProc>(
        GetProcAddress(LoadLibraryW(L"dwrite.dll"), "DWriteCreateFactory"));

    if (!dWriteCreateFactoryProc) {
        HRESULT hr = HRESULT_FROM_WIN32(GetLastError());
        if (!IS_ERROR(hr)) {
            hr = ERROR_PROC_NOT_FOUND;
        }
        HRVM(hr, "Could not get DWriteCreateFactory proc.");
    }

    HRVM(dWriteCreateFactoryProc(DWRITE_FACTORY_TYPE_SHARED,
<<<<<<< HEAD
             __uuidof(IDWriteFactory),
             reinterpret_cast<IUnknown**>(factory)),
        "Could not create DirectWrite factory.");
    atexit(release_dwrite_factory);
}

IDWriteFactory* sk_get_dwrite_factory()
{
    static SkOnce once;
    once(create_dwrite_factory, &gDWriteFactory);
=======
                                 __uuidof(IDWriteFactory),
                                 reinterpret_cast<IUnknown**>(factory)),
         "Could not create DirectWrite factory.");
    atexit(release_dwrite_factory);
}


SK_DECLARE_STATIC_ONCE(once);
IDWriteFactory* sk_get_dwrite_factory() {
    SkOnce(&once, create_dwrite_factory, &gDWriteFactory);
>>>>>>> miniblink49
    return gDWriteFactory;
}

////////////////////////////////////////////////////////////////////////////////
// String conversion

/** Converts a utf8 string to a WCHAR string. */
<<<<<<< HEAD
HRESULT sk_cstring_to_wchar(const char* skname, SkSMallocWCHAR* name)
{
    int wlen = MultiByteToWideChar(CP_UTF8, 0, skname, -1, nullptr, 0);
=======
HRESULT sk_cstring_to_wchar(const char* skname, SkSMallocWCHAR* name) {
    int wlen = MultiByteToWideChar(CP_UTF8, 0, skname, -1, NULL, 0);
>>>>>>> miniblink49
    if (0 == wlen) {
        HRM(HRESULT_FROM_WIN32(GetLastError()),
            "Could not get length for wchar to utf-8 conversion.");
    }
    name->reset(wlen);
    wlen = MultiByteToWideChar(CP_UTF8, 0, skname, -1, name->get(), wlen);
    if (0 == wlen) {
        HRM(HRESULT_FROM_WIN32(GetLastError()), "Could not convert wchar to utf-8.");
    }
    return S_OK;
}

/** Converts a WCHAR string to a utf8 string. */
<<<<<<< HEAD
HRESULT sk_wchar_to_skstring(WCHAR* name, int nameLen, SkString* skname)
{
    int len = WideCharToMultiByte(CP_UTF8, 0, name, nameLen, nullptr, 0, nullptr, nullptr);
=======
HRESULT sk_wchar_to_skstring(WCHAR* name, int nameLen, SkString* skname) {
    int len = WideCharToMultiByte(CP_UTF8, 0, name, nameLen, NULL, 0, NULL, NULL);
>>>>>>> miniblink49
    if (0 == len) {
        if (nameLen <= 0) {
            skname->reset();
            return S_OK;
        }
        HRM(HRESULT_FROM_WIN32(GetLastError()),
            "Could not get length for utf-8 to wchar conversion.");
    }
    skname->resize(len);

<<<<<<< HEAD
    len = WideCharToMultiByte(CP_UTF8, 0, name, nameLen, skname->writable_str(), len, nullptr, nullptr);
=======
    len = WideCharToMultiByte(CP_UTF8, 0, name, nameLen, skname->writable_str(), len, NULL, NULL);
>>>>>>> miniblink49
    if (0 == len) {
        HRM(HRESULT_FROM_WIN32(GetLastError()), "Could not convert utf-8 to wchar.");
    }
    return S_OK;
}

////////////////////////////////////////////////////////////////////////////////
// Locale

void sk_get_locale_string(IDWriteLocalizedStrings* names, const WCHAR* preferedLocale,
<<<<<<< HEAD
    SkString* skname)
{
=======
                          SkString* skname) {
>>>>>>> miniblink49
    UINT32 nameIndex = 0;
    if (preferedLocale) {
        // Ignore any errors and continue with index 0 if there is a problem.
        BOOL nameExists;
        names->FindLocaleName(preferedLocale, &nameIndex, &nameExists);
        if (!nameExists) {
            nameIndex = 0;
        }
    }

    UINT32 nameLen;
    HRVM(names->GetStringLength(nameIndex, &nameLen), "Could not get name length.");

<<<<<<< HEAD
    SkSMallocWCHAR name(nameLen + 1);
    HRVM(names->GetString(nameIndex, name.get(), nameLen + 1), "Could not get string.");
=======
    SkSMallocWCHAR name(nameLen+1);
    HRVM(names->GetString(nameIndex, name.get(), nameLen+1), "Could not get string.");
>>>>>>> miniblink49

    HRV(sk_wchar_to_skstring(name.get(), nameLen, skname));
}

<<<<<<< HEAD
HRESULT SkGetGetUserDefaultLocaleNameProc(SkGetUserDefaultLocaleNameProc* proc)
{
    *proc = reinterpret_cast<SkGetUserDefaultLocaleNameProc>(
        GetProcAddress(LoadLibraryW(L"Kernel32.dll"), "GetUserDefaultLocaleName"));
=======
HRESULT SkGetGetUserDefaultLocaleNameProc(SkGetUserDefaultLocaleNameProc* proc) {
    *proc = reinterpret_cast<SkGetUserDefaultLocaleNameProc>(
        GetProcAddress(LoadLibraryW(L"Kernel32.dll"), "GetUserDefaultLocaleName")
    );
>>>>>>> miniblink49
    if (!*proc) {
        HRESULT hr = HRESULT_FROM_WIN32(GetLastError());
        if (!IS_ERROR(hr)) {
            hr = ERROR_PROC_NOT_FOUND;
        }
        return hr;
    }
    return S_OK;
}
<<<<<<< HEAD

#endif //defined(SK_BUILD_FOR_WIN32)
=======
>>>>>>> miniblink49
