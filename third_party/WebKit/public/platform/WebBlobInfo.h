// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebBlobInfo_h
#define WebBlobInfo_h

#include "WebCommon.h"
#include "WebString.h"

namespace blink {

class WebBlobInfo {
public:
    WebBlobInfo()
        : m_isFile(false)
        , m_size(-1)
        , m_lastModified(0)
    {
    }
    WebBlobInfo(const WebString& uuid, const WebString& type, long long size)
        : m_isFile(false)
        , m_uuid(uuid)
        , m_type(type)
        , m_size(size)
        , m_lastModified(0)
    {
    }
<<<<<<< HEAD
    WebBlobInfo(const WebString& uuid,
        const WebString& filePath,
        const WebString& fileName,
        const WebString& type)
=======
    WebBlobInfo(const WebString& uuid, const WebString& filePath, const WebString& fileName, const WebString& type)
>>>>>>> miniblink49
        : m_isFile(true)
        , m_uuid(uuid)
        , m_type(type)
        , m_size(-1)
        , m_filePath(filePath)
        , m_fileName(fileName)
        , m_lastModified(0)
    {
    }
<<<<<<< HEAD
    WebBlobInfo(const WebString& uuid,
        const WebString& filePath,
        const WebString& fileName,
        const WebString& type,
        double lastModified,
        long long size)
=======
    WebBlobInfo(const WebString& uuid, const WebString& filePath, const WebString& fileName, const WebString& type, double lastModified, long long size)
>>>>>>> miniblink49
        : m_isFile(true)
        , m_uuid(uuid)
        , m_type(type)
        , m_size(size)
        , m_filePath(filePath)
        , m_fileName(fileName)
        , m_lastModified(lastModified)
    {
    }
<<<<<<< HEAD
    bool isFile() const { return m_isFile; }
    const WebString& uuid() const { return m_uuid; }
    const WebString& type() const { return m_type; }
    long long size() const { return m_size; }
    const WebString& filePath() const { return m_filePath; }
    const WebString& fileName() const { return m_fileName; }
    double lastModified() const { return m_lastModified; }
=======
    bool isFile() const
    {
        return m_isFile;
    }
    const WebString& uuid() const
    {
        return m_uuid;
    }
    const WebString& type() const
    {
        return m_type;
    }
    long long size() const
    {
        return m_size;
    }
    const WebString& filePath() const
    {
        return m_filePath;
    }
    const WebString& fileName() const
    {
        return m_fileName;
    }
    double lastModified() const
    {
        return m_lastModified;
    }
>>>>>>> miniblink49

private:
    bool m_isFile;
    WebString m_uuid;
    WebString m_type; // MIME type
    long long m_size;
    WebString m_filePath; // Only for File
    WebString m_fileName; // Only for File
    double m_lastModified; // Only for File
};

} // namespace blink

#endif
