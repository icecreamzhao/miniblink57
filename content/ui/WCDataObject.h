/*
 * Copyright (C) 2007, 2014 Apple Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef WCDataObject_h
#define WCDataObject_h

#include <shlobj.h>
#include <objidl.h>
#include <memory>
#include <string>
#include <vector>

class SkBitmap;

namespace content {

struct StgMediumDeleter {
    void operator()(STGMEDIUM* medium)
    {
        ::ReleaseStgMedium(medium);
    }
};

//typedef HashMap<unsigned, Vector<String>> DragDataMap;

class WCDataObject : public IDataObject {
public:
    void CopyMedium(STGMEDIUM* pMedDest, STGMEDIUM* pMedSrc, FORMATETC* pFmtSrc);

    void writeString(const std::string& type, const std::string& data);
    void writeCustomPlainText(const std::string& customPlainText);
    void writeBitmap(const char* data, size_t size);
    //void writeHtml(const std::string& type, const std::string& data);

    //IUnknown
    virtual HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject);
    virtual ULONG __stdcall AddRef(void);
    virtual ULONG __stdcall Release(void);

    //IDataObject
    virtual HRESULT __stdcall GetData(FORMATETC* pformatIn, STGMEDIUM* pmedium);
    virtual HRESULT __stdcall GetDataHere(FORMATETC* pformat, STGMEDIUM* pmedium);
    virtual HRESULT __stdcall QueryGetData(FORMATETC* pformat);
    virtual HRESULT __stdcall GetCanonicalFormatEtc(FORMATETC* pformatectIn,FORMATETC* pformatOut);
    virtual HRESULT __stdcall SetData(FORMATETC* pformat, STGMEDIUM*pmedium, BOOL release);
    virtual HRESULT __stdcall EnumFormatEtc(DWORD dwDirection, IEnumFORMATETC** ppenumFormatEtc);
    virtual HRESULT __stdcall DAdvise(FORMATETC*, DWORD, IAdviseSink*, DWORD*);
    virtual HRESULT __stdcall DUnadvise(DWORD);
    virtual HRESULT __stdcall EnumDAdvise(IEnumSTATDATA**);

    void clearData(CLIPFORMAT);
    
    static HRESULT createInstance(WCDataObject**);
    //static HRESULT createInstance(WCDataObject**, const DragDataMap&);

    enum ClipboardDataType {
        kClipboardDataTypeNone, kClipboardDataTypeURL, kClipboardDataTypeText, kClipboardDataTypeTextHTML
    };

    static ClipboardDataType clipboardTypeFromMIMEType(const std::string& type);

private:
    WCDataObject();
    long m_ref;
//     Vector<std::unique_ptr<FORMATETC>> m_formats;
//     Vector<std::unique_ptr<STGMEDIUM, StgMediumDeleter>> m_medium;
    std::vector<FORMATETC*> m_formats;
    std::vector<STGMEDIUM*> m_medium;
};

}

#endif //!WCDataObject_h
