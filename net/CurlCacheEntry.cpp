/*
 * Copyright (C) 2013 University of Szeged
 * All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY UNIVERSITY OF SZEGED ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL UNIVERSITY OF SZEGED OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"

#include "net/CurlCacheEntry.h"

#include "net/FileSystem.h"
#include "net/WebURLLoaderManager.h"
#include "third_party/WebKit/Source/platform/network/HTTPHeaderMap.h"
#include "third_party/WebKit/Source/platform/network/HTTPParsers.h"
//#include "third_party/skia/src/utils/SkSHA1.h"
#include "third_party/smhasher/src/sha1.h"
#include <wtf/CurrentTime.h>
#include <wtf/DateMath.h>
#include <wtf/HexNumber.h>
#include <wtf/Vector.h>

namespace net {

CurlCacheEntry::CurlCacheEntry(const String& url, WebURLLoaderInternal* job, const String& cacheDir, int Level)
    : m_headerFilename(cacheDir)
    , m_contentFilename(cacheDir)
    , m_contentFile(invalidPlatformFileHandle)
    , m_entrySize(0)
    , m_expireDate(-1)
    , m_headerParsed(false)
    , m_job(job)
    , m_headerMem(false)
    , m_contentMem(false)
    , m_fileTime(0)
    , m_cacheLevel(Level)
    , m_loading(false)
{
    if (m_cacheLevel == 2) {
        m_headerMem = true;
        m_contentMem = true;
        return;
    }
    generateBaseFilename(url.latin1());

    m_headerFilename.append(m_basename);
    m_headerFilename.append(".header");

    m_contentFilename.append(m_basename);
    m_contentFilename.append(".content");
}

CurlCacheEntry::~CurlCacheEntry()
{
    if (m_cacheLevel == 2) {
        m_loading = false;
        return;
    }
    closeContentFile();
}

bool CurlCacheEntry::isLoading() const
{
    if (m_cacheLevel == 2)
        return m_loading;
    return isHandleValid(m_contentFile);
}

// Cache manager should invalidate the entry on false
bool CurlCacheEntry::isCached()
{
    if (!m_headerMem || !m_contentMem) {
        if (!fileExists(m_contentFilename) || !fileExists(m_headerFilename))
            return false;
    }

    if (!m_headerParsed) {
        if (!loadResponseHeaders())
            return false;
    }

    if (m_expireDate < currentTimeMS()) {
        m_headerParsed = false;
        return false;
    }

    if (!entrySize())
        return false;

    return true;
}

bool CurlCacheEntry::saveCachedData(const char* data, size_t size)
{
    if (m_contentMem) {
        m_contentBuffer.append(data, size);
        m_contentMem = true;
    }

    if (m_cacheLevel == 2) {
        m_loading = true;
        return true;
    }

    if (!openContentFile())
        return false;

    writeToFile(m_contentFile, data, size);
    return true;
}

bool CurlCacheEntry::readCachedData(WebURLLoaderInternal* job)
{
    ASSERT(job->client());
    if (m_contentMem) {
        WebURLLoaderManager::sharedInstance()->didReceiveDataOrDownload(job, m_contentBuffer.data(), m_contentBuffer.size(), 0);
        return true;
    }

    Vector<char> buffer;
    if (!loadFileToBuffer(m_contentFilename, buffer))
        return false;

    WebURLLoaderManager::sharedInstance()->didReceiveDataOrDownload(job, buffer.data(), buffer.size(), 0);
    return true;
}

bool CurlCacheEntry::saveHeadersToFile()
{
    if (m_cacheLevel == 2)
        return true;
    PlatformFileHandle headerFile = openFile(m_headerFilename, OpenForWrite);
    if (!isHandleValid(headerFile)) {
        //LOG(Network, "Cache Error: Could not open %s for write\n", m_headerFilename.latin1().data());
        return false;
    }

    writeToFile(headerFile, m_headerBuffer.data(), m_headerBuffer.size());

    closeFile(headerFile);

    return true;
}

bool CurlCacheEntry::saveResponseHeaders(const ResourceResponse& response)
{
    if (m_headerMem) {
        m_fileTime = currentTimeMS(); // GMT
        m_headerBuffer.clear();

        // Headers
        blink::HTTPHeaderMap::const_iterator it = response.httpHeaderFields().begin();
        blink::HTTPHeaderMap::const_iterator end = response.httpHeaderFields().end();
        while (it != end) {
            String headerField = it->key;
            headerField.append(": ");
            headerField.append(it->value);
            headerField.append("\n");
            CString headerFieldLatin1 = headerField.latin1();
            m_headerBuffer.append(headerFieldLatin1.data(), headerFieldLatin1.length());
            m_cachedResponse.setHTTPHeaderField(it->key, it->value);
            ++it;
        }
    }
    else {
        PlatformFileHandle headerFile = openFile(m_headerFilename, OpenForWrite);
        if (!isHandleValid(headerFile)) {
            //LOG(Network, "Cache Error: Could not open %s for write\n", m_headerFilename.latin1().data());
            return false;
        }

        // Headers
        blink::HTTPHeaderMap::const_iterator it = response.httpHeaderFields().begin();
        blink::HTTPHeaderMap::const_iterator end = response.httpHeaderFields().end();
        while (it != end) {
            String headerField = it->key;
            headerField.append(": ");
            headerField.append(it->value);
            headerField.append("\n");
            CString headerFieldLatin1 = headerField.latin1();
            writeToFile(headerFile, headerFieldLatin1.data(), headerFieldLatin1.length());
            
            m_headerBuffer.append(headerFieldLatin1.data(), headerFieldLatin1.length());
            m_cachedResponse.setHTTPHeaderField(it->key, it->value);
            ++it;
        }

        closeFile(headerFile);

        m_headerMem = true;
    }
    return true;
}

bool CurlCacheEntry::loadResponseHeaders()
{
    //
    if (!m_headerMem) {
        if (!loadFileToBuffer(m_headerFilename, m_headerBuffer))
            return false;
        m_headerMem = true;
    }
    String headerContent = String(m_headerBuffer.data(), m_headerBuffer.size());
    Vector<String> headerFields;
    headerContent.split('\n', headerFields);

    Vector<String>::const_iterator it = headerFields.begin();
    Vector<String>::const_iterator end = headerFields.end();
    while (it != end) {
        size_t splitPosition = it->find(":");
        if (splitPosition != kNotFound)
            m_cachedResponse.setHTTPHeaderField(AtomicString(it->left(splitPosition)), AtomicString(it->substring(splitPosition+1).stripWhiteSpace()));
        ++it;
    }

    return parseResponseHeaders(m_cachedResponse);
}

// Set response headers from memory
void CurlCacheEntry::setResponseFromCachedHeaders(ResourceResponse& response)
{
    response.setHTTPStatusCode(304);
    response.setWasCached(true);

    // Integrate the headers in the response with the cached ones.
    blink::HTTPHeaderMap::const_iterator it = m_cachedResponse.httpHeaderFields().begin();
    blink::HTTPHeaderMap::const_iterator end = m_cachedResponse.httpHeaderFields().end();
    while (it != end) {
        if (response.httpHeaderField(it->key).isNull())
            response.setHTTPHeaderField(it->key, it->value);
        ++it;
    }

    // Try to parse expected content length
    long long contentLength = -1;
    if (!response.httpHeaderField("Content-Length").isNull()) {
        bool success = false;
        long long parsedContentLength = String(response.httpHeaderField("Content-Length")).toInt64(&success);
        if (success)
            contentLength = parsedContentLength;
    }
    response.setExpectedContentLength(contentLength); // -1 on parse error or null

    response.setMimeType(extractMIMETypeFromMediaType(response.httpHeaderField("Content-Type")));
    response.setTextEncodingName(AtomicString(extractCharsetFromMediaType(response.httpHeaderField("Content-Type"))));
}

void CurlCacheEntry::didFail()
{
    // The cache manager will call invalidate()
    if (m_cacheLevel == 2) {
        m_loading = false;
        return;
    }
    closeContentFile();
}

void CurlCacheEntry::didFinishLoading()
{
    if (m_cacheLevel == 2) {
        m_loading = false;
        return;
    }
    closeContentFile();
}

void CurlCacheEntry::generateBaseFilename(const CString& url)
{
//     SkSHA1 sha1;
// 
//     sha1.write(reinterpret_cast<const uint8_t*>(url.data()), url.length());
//     SkSHA1::Digest hash;
//     sha1.finish(hash);
//
//     uint8_t* rawdata = hash.data;
// 
//     for (size_t i = 0; i < 20; i++)
//         appendByteAsHex(rawdata[i], m_basename, Lowercase);

    SHA1_CTX context;
    SHA1_Init(&context);
    SHA1_Update(&context, reinterpret_cast<const uint8_t*>(url.data()), url.length());

    uint8_t rawdata[SHA1_DIGEST_SIZE] = { 0 };
    SHA1_Final(&context, rawdata);

    for (size_t i = 0; i < SHA1_DIGEST_SIZE; i++)
        appendByteAsHex(rawdata[i], m_basename, Lowercase);
}

bool CurlCacheEntry::loadFileToBuffer(const String& filepath, Vector<char>& buffer)
{
    if (m_cacheLevel == 2)
        return true;
    // Open the file
    PlatformFileHandle inputFile = openFile(filepath, OpenForRead);
    if (!isHandleValid(inputFile)) {
        //LOG(Network, "Cache Error: Could not open %s for read\n", filepath.latin1().data());
        return false;
    }

    long long filesize = -1;
    if (!getFileSize(filepath, filesize)) {
        //LOG(Network, "Cache Error: Could not get file size of %s\n", filepath.latin1().data());
        closeFile(inputFile);
        return false;
    }

    // Load the file content into buffer
    buffer.resize(filesize);
    int bufferPosition = 0;
    int bufferReadSize = 4096;
    int bytesRead = 0;
    while (filesize > bufferPosition) {
        if (filesize - bufferPosition < bufferReadSize)
            bufferReadSize = filesize - bufferPosition;

        bytesRead = readFromFile(inputFile, buffer.data() + bufferPosition, bufferReadSize);
        if (bytesRead != bufferReadSize) {
            //LOG(Network, "Cache Error: Could not read from %s\n", filepath.latin1().data());
            closeFile(inputFile);
            return false;
        }

        bufferPosition += bufferReadSize;
    }
    closeFile(inputFile);
    return true;
}

void CurlCacheEntry::invalidate()
{
    if (m_contentMem)
        m_contentBuffer.clear();
    if (m_headerMem)
        m_contentBuffer.clear();
    if (m_cacheLevel == 2) {
        m_loading = false;
        return;
    }
    closeContentFile();
    deleteFile(m_headerFilename);
    deleteFile(m_contentFilename);
    //LOG(Network, "Cache: invalidated %s\n", m_basename.latin1().data());
}

bool CurlCacheEntry::parseResponseHeaders(const ResourceResponse& response)
{
    time_t fileModificationDate;

    if (m_fileTime == 0) {
        if (getFileModificationTime(m_headerFilename, fileModificationDate)) {
            m_fileTime = (double)(uint64_t)(fileModificationDate);
            m_fileTime *= 1000.0;
        }
        else
            m_fileTime = currentTimeMS(); // GMT
    }

    //if (response.cacheControlContainsNoCache() || response.cacheControlContainsNoStore())
    //    return false;

    double maxAge = 0;
    bool maxAgeIsValid = false;

    //if (response.cacheControlContainsMustRevalidate())
    //    maxAge = 0;
    //else {
    //    maxAge = response.cacheControlMaxAge();
    //    if (std::isnan(maxAge))
    //        maxAge = 0;
    //    else
    //        maxAgeIsValid = true;
    //}

    if (!response.hasCacheValidatorFields())
        return false;


    double lastModificationDate = 0;
    double responseDate = 0;
    double expirationDate = 0;

    lastModificationDate = response.lastModified();
    if (std::isnan(lastModificationDate))
        lastModificationDate = 0;

    responseDate = response.date();
    if (std::isnan(responseDate))
        responseDate = 0;

    expirationDate = response.expires();
    if (std::isnan(expirationDate))
        expirationDate = 0;


    if (maxAgeIsValid) {
        // When both the cache entry and the response contain max-age, the lesser one takes priority
        double expires = m_fileTime + maxAge * 1000;
        if (m_expireDate == -1 || m_expireDate > expires)
            m_expireDate = expires;
    } else if (responseDate > 0 && expirationDate >= responseDate)
        m_expireDate = m_fileTime + (expirationDate - responseDate);

    // If there is no lifetime information
    if (m_expireDate == -1) {
        if (lastModificationDate > 0)
            m_expireDate = m_fileTime + (m_fileTime - lastModificationDate) * 0.1;
        else
            m_expireDate = 0;
    }

    AtomicString etag = response.httpHeaderField("ETag");
    if (!etag.isNull())
        m_requestHeaders.set("If-None-Match", etag);

    AtomicString lastModified = response.httpHeaderField("Last-Modified");
    if (!lastModified.isNull())
        m_requestHeaders.set("If-Modified-Since", lastModified);

    if (etag.isNull() && lastModified.isNull())
        return false;

    m_headerParsed = true;
    return true;
}

bool CurlCacheEntry::loadResponseHeaders(Vector<char>& header)
{
    m_headerBuffer = header;
    return loadResponseHeaders();
}

size_t CurlCacheEntry::entrySize()
{
    if (!m_entrySize) {
        long long headerFileSize;
        long long contentFileSize;
        
        if (m_headerMem) {
            headerFileSize = m_headerBuffer.size();
        }
        else if (!getFileSize(m_headerFilename, headerFileSize)) {
            //LOG(Network, "Cache Error: Could not get file size of %s\n", m_headerFilename.latin1().data());
            return m_entrySize;
        }
        
        if (m_contentMem) {
            contentFileSize = m_contentBuffer.size();
        }
        else if (!getFileSize(m_contentFilename, contentFileSize)) {
            //LOG(Network, "Cache Error: Could not get file size of %s\n", m_contentFilename.latin1().data());
            return m_entrySize;
        }

        m_entrySize = headerFileSize + contentFileSize;
    }

    return m_entrySize;
}

bool CurlCacheEntry::openContentFile()
{
    if (isHandleValid(m_contentFile))
        return true;
    
    m_contentFile = openFile(m_contentFilename, OpenForWrite);

    if (isHandleValid(m_contentFile))
        return true;
    
    //LOG(Network, "Cache Error: Could not open %s for write\n", m_contentFilename.latin1().data());
    return false;
}

bool CurlCacheEntry::closeContentFile()
{
    if (!isHandleValid(m_contentFile))
        return true;

    closeFile(m_contentFile);
    m_contentFile = invalidPlatformFileHandle;

    return true;
}

}
