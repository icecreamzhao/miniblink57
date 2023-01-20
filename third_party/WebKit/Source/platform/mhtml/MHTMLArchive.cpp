/*
 * Copyright (C) 2011 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
#include "platform/mhtml/MHTMLArchive.h"

#include "platform/DateComponents.h"
=======
#include "config.h"
#include "platform/mhtml/MHTMLArchive.h"

#include "platform/DateComponents.h"
#include "platform/MIMETypeRegistry.h"
>>>>>>> miniblink49
#include "platform/SerializedResource.h"
#include "platform/SharedBuffer.h"
#include "platform/mhtml/ArchiveResource.h"
#include "platform/mhtml/MHTMLParser.h"
<<<<<<< HEAD
#include "platform/network/mime/MIMETypeRegistry.h"
#include "platform/text/QuotedPrintable.h"
#include "platform/weborigin/SchemeRegistry.h"
#include "wtf/Assertions.h"
#include "wtf/CryptographicallyRandomNumber.h"
#include "wtf/CurrentTime.h"
=======
#include "platform/text/QuotedPrintable.h"
#include "platform/weborigin/SchemeRegistry.h"
#include "wtf/CryptographicallyRandomNumber.h"
>>>>>>> miniblink49
#include "wtf/DateMath.h"
#include "wtf/text/Base64.h"
#include "wtf/text/StringBuilder.h"

namespace blink {

const char* const quotedPrintable = "quoted-printable";
const char* const base64 = "base64";
const char* const binary = "binary";

<<<<<<< HEAD
=======
String MHTMLArchive::generateMHTMLBoundary()
{
    // Trying to generate random boundaries similar to IE/UnMHT
    // (ex: ----=_NextPart_000_001B_01CC157B.96F808A0).
    const size_t randomValuesLength = 10;
    char randomValues[randomValuesLength];
    cryptographicallyRandomValues(&randomValues, randomValuesLength);
    StringBuilder stringBuilder;
    stringBuilder.appendLiteral("----=_NextPart_000_");
    for (size_t i = 0; i < randomValuesLength; ++i) {
        if (i == 2)
            stringBuilder.append('_');
        else if (i == 6)
            stringBuilder.append('.');
        stringBuilder.append(lowerNibbleToASCIIHexDigit(randomValues[i]));
        stringBuilder.append(upperNibbleToASCIIHexDigit(randomValues[i]));
    }
    return stringBuilder.toString();
}

>>>>>>> miniblink49
static String replaceNonPrintableCharacters(const String& text)
{
    StringBuilder stringBuilder;
    for (size_t i = 0; i < text.length(); ++i) {
        if (isASCIIPrintable(text[i]))
            stringBuilder.append(text[i]);
        else
            stringBuilder.append('?');
    }
    return stringBuilder.toString();
}

<<<<<<< HEAD
MHTMLArchive::MHTMLArchive() { }

MHTMLArchive* MHTMLArchive::create(const KURL& url,
    PassRefPtr<const SharedBuffer> data)
{
    // MHTML pages can only be loaded from local URLs, http/https URLs, and
    // content URLs(Android specific).  The latter is now allowed due to full
    // sandboxing enforcement on MHTML pages.
    if (!canLoadArchive(url))
        return nullptr;

    MHTMLParser parser(std::move(data));
    HeapVector<Member<ArchiveResource>> resources = parser.parseArchive();
    if (resources.isEmpty())
        return nullptr; // Invalid MHTML file.

    MHTMLArchive* archive = new MHTMLArchive;

    size_t resourcesCount = resources.size();
    // The first document suitable resource is the main resource of the top frame.
    for (size_t i = 0; i < resourcesCount; ++i) {
        if (archive->mainResource()) {
            archive->addSubresource(resources[i].get());
            continue;
        }

        const AtomicString& mimeType = resources[i]->mimeType();
        bool isMimeTypeSuitableForMainResource = MIMETypeRegistry::isSupportedNonImageMIMEType(mimeType);
        // Want to allow image-only MHTML archives, but retain behavior for other
        // documents that have already been created expecting the first HTML page to
        // be considered the main resource.
        if (resourcesCount == 1 && MIMETypeRegistry::isSupportedImageResourceMIMEType(mimeType)) {
            isMimeTypeSuitableForMainResource = true;
        }
        // explicitly disallow JS and CSS as the main resource.
        if (MIMETypeRegistry::isSupportedJavaScriptMIMEType(mimeType) || MIMETypeRegistry::isSupportedStyleSheetMIMEType(mimeType))
            isMimeTypeSuitableForMainResource = false;

        if (isMimeTypeSuitableForMainResource)
            archive->setMainResource(resources[i].get());
        else
            archive->addSubresource(resources[i].get());
    }
    return archive;
}

bool MHTMLArchive::canLoadArchive(const KURL& url)
{
    // MHTML pages can only be loaded from local URLs, http/https URLs, and
    // content URLs(Android specific).  The latter is now allowed due to full
    // sandboxing enforcement on MHTML pages.
    if (SchemeRegistry::shouldTreatURLSchemeAsLocal(url.protocol()))
        return true;
    if (url.protocolIsInHTTPFamily())
        return true;
#if OS(ANDROID)
    if (url.protocolIs("content"))
        return true;
#endif
    return false;
}

void MHTMLArchive::generateMHTMLHeader(const String& boundary,
    const String& title,
    const String& mimeType,
    Vector<char>& outputBuffer)
{
    ASSERT(!boundary.isEmpty());
    ASSERT(!mimeType.isEmpty());

=======
MHTMLArchive::MHTMLArchive()
{
}

MHTMLArchive::~MHTMLArchive()
{
#if !ENABLE(OILPAN)
    // Because all frames know about each other we need to perform a deep clearing of the archives graph.
    clearAllSubframeArchives();
#endif
}

PassRefPtrWillBeRawPtr<MHTMLArchive> MHTMLArchive::create()
{
    return adoptRefWillBeNoop(new MHTMLArchive);
}

PassRefPtrWillBeRawPtr<MHTMLArchive> MHTMLArchive::create(const KURL& url, SharedBuffer* data)
{
    // For security reasons we only load MHTML pages from local URLs.
    if (!SchemeRegistry::shouldTreatURLSchemeAsLocal(url.protocol()))
        return nullptr;

    MHTMLParser parser(data);
    RefPtrWillBeRawPtr<MHTMLArchive> mainArchive = parser.parseArchive();
    if (!mainArchive)
        return nullptr; // Invalid MHTML file.

    // Since MHTML is a flat format, we need to make all frames aware of all resources.
    for (size_t i = 0; i < parser.frameCount(); ++i) {
        RefPtrWillBeRawPtr<MHTMLArchive> archive = parser.frameAt(i);
        for (size_t j = 1; j < parser.frameCount(); ++j) {
            if (i != j)
                archive->addSubframeArchive(parser.frameAt(j));
        }
        for (size_t j = 0; j < parser.subResourceCount(); ++j)
            archive->addSubresource(parser.subResourceAt(j));
    }
    return mainArchive.release();
}

void MHTMLArchive::generateMHTMLHeader(
    const String& boundary, const String& title, const String& mimeType,
    SharedBuffer& outputBuffer)
{
>>>>>>> miniblink49
    DateComponents now;
    now.setMillisecondsSinceEpochForDateTime(currentTimeMS());
    // TODO(lukasza): Passing individual date/time components seems fragile.
    String dateString = makeRFC2822DateString(
<<<<<<< HEAD
        now.weekDay(), now.monthDay(), now.month(), now.fullYear(), now.hour(),
        now.minute(), now.second(), 0);

    StringBuilder stringBuilder;
    stringBuilder.append("From: <Saved by Blink>\r\n");
    stringBuilder.append("Subject: ");
    // We replace non ASCII characters with '?' characters to match IE's behavior.
    stringBuilder.append(replaceNonPrintableCharacters(title));
    stringBuilder.append("\r\nDate: ");
    stringBuilder.append(dateString);
    stringBuilder.append("\r\nMIME-Version: 1.0\r\n");
    stringBuilder.append("Content-Type: multipart/related;\r\n");
    stringBuilder.append("\ttype=\"");
    stringBuilder.append(mimeType);
    stringBuilder.append("\";\r\n");
    stringBuilder.append("\tboundary=\"");
    stringBuilder.append(boundary);
    stringBuilder.append("\"\r\n\r\n");
=======
        now.weekDay(), now.monthDay(), now.month(), now.fullYear(),
        now.hour(), now.minute(), now.second(), 0);

    StringBuilder stringBuilder;
    stringBuilder.appendLiteral("From: <Saved by Blink>\r\n");
    stringBuilder.appendLiteral("Subject: ");
    // We replace non ASCII characters with '?' characters to match IE's behavior.
    stringBuilder.append(replaceNonPrintableCharacters(title));
    stringBuilder.appendLiteral("\r\nDate: ");
    stringBuilder.append(dateString);
    stringBuilder.appendLiteral("\r\nMIME-Version: 1.0\r\n");
    stringBuilder.appendLiteral("Content-Type: multipart/related;\r\n");
    stringBuilder.appendLiteral("\ttype=\"");
    stringBuilder.append(mimeType);
    stringBuilder.appendLiteral("\";\r\n");
    stringBuilder.appendLiteral("\tboundary=\"");
    stringBuilder.append(boundary);
    stringBuilder.appendLiteral("\"\r\n\r\n");
>>>>>>> miniblink49

    // We use utf8() below instead of ascii() as ascii() replaces CRLFs with ??
    // (we still only have put ASCII characters in it).
    ASSERT(stringBuilder.toString().containsOnlyASCII());
    CString asciiString = stringBuilder.toString().utf8();

    outputBuffer.append(asciiString.data(), asciiString.length());
}

<<<<<<< HEAD
void MHTMLArchive::generateMHTMLPart(const String& boundary,
    const String& contentID,
    EncodingPolicy encodingPolicy,
    const SerializedResource& resource,
    Vector<char>& outputBuffer)
{
    ASSERT(!boundary.isEmpty());
    ASSERT(contentID.isEmpty() || contentID[0] == '<');

    StringBuilder stringBuilder;
    stringBuilder.append("--");
    stringBuilder.append(boundary);
    stringBuilder.append("\r\n");

    stringBuilder.append("Content-Type: ");
    stringBuilder.append(resource.mimeType);
    stringBuilder.append("\r\n");

    if (!contentID.isEmpty()) {
        stringBuilder.append("Content-ID: ");
        stringBuilder.append(contentID);
        stringBuilder.append("\r\n");
    }
=======
void MHTMLArchive::generateMHTMLPart(
    const String& boundary,
    EncodingPolicy encodingPolicy,
    const SerializedResource& resource,
    SharedBuffer& outputBuffer)
{
    StringBuilder stringBuilder;
    stringBuilder.append("--" + boundary + "\r\n");
    stringBuilder.appendLiteral("Content-Type: ");
    stringBuilder.append(resource.mimeType);
>>>>>>> miniblink49

    const char* contentEncoding = 0;
    if (encodingPolicy == UseBinaryEncoding)
        contentEncoding = binary;
    else if (MIMETypeRegistry::isSupportedJavaScriptMIMEType(resource.mimeType) || MIMETypeRegistry::isSupportedNonImageMIMEType(resource.mimeType))
        contentEncoding = quotedPrintable;
    else
        contentEncoding = base64;

<<<<<<< HEAD
    stringBuilder.append("Content-Transfer-Encoding: ");
    stringBuilder.append(contentEncoding);
    stringBuilder.append("\r\n");

    if (!resource.url.protocolIsAbout()) {
        stringBuilder.append("Content-Location: ");
        stringBuilder.append(resource.url.getString());
        stringBuilder.append("\r\n");
    }

    stringBuilder.append("\r\n");
=======
    stringBuilder.appendLiteral("\r\nContent-Transfer-Encoding: ");
    stringBuilder.append(contentEncoding);
    stringBuilder.appendLiteral("\r\nContent-Location: ");
    stringBuilder.append(resource.url);
    stringBuilder.appendLiteral("\r\n\r\n");
>>>>>>> miniblink49

    CString asciiString = stringBuilder.toString().utf8();
    outputBuffer.append(asciiString.data(), asciiString.length());

    if (!strcmp(contentEncoding, binary)) {
        const char* data;
        size_t position = 0;
        while (size_t length = resource.data->getSomeData(data, position)) {
            outputBuffer.append(data, length);
            position += length;
        }
    } else {
<<<<<<< HEAD
        // FIXME: ideally we would encode the content as a stream without having to
        // fetch it all.
=======
        // FIXME: ideally we would encode the content as a stream without having to fetch it all.
>>>>>>> miniblink49
        const char* data = resource.data->data();
        size_t dataLength = resource.data->size();
        Vector<char> encodedData;
        if (!strcmp(contentEncoding, quotedPrintable)) {
            quotedPrintableEncode(data, dataLength, encodedData);
            outputBuffer.append(encodedData.data(), encodedData.size());
<<<<<<< HEAD
            outputBuffer.append("\r\n", 2u);
        } else {
            ASSERT(!strcmp(contentEncoding, base64));
            // We are not specifying insertLFs = true below as it would cut the lines
            // with LFs and MHTML requires CRLFs.
=======
            outputBuffer.append("\r\n", 2);
        } else {
            ASSERT(!strcmp(contentEncoding, base64));
            // We are not specifying insertLFs = true below as it would cut the lines with LFs and MHTML requires CRLFs.
>>>>>>> miniblink49
            base64Encode(data, dataLength, encodedData);
            const size_t maximumLineLength = 76;
            size_t index = 0;
            size_t encodedDataLength = encodedData.size();
            do {
                size_t lineLength = std::min(encodedDataLength - index, maximumLineLength);
                outputBuffer.append(encodedData.data() + index, lineLength);
<<<<<<< HEAD
                outputBuffer.append("\r\n", 2u);
=======
                outputBuffer.append("\r\n", 2);
>>>>>>> miniblink49
                index += maximumLineLength;
            } while (index < encodedDataLength);
        }
    }
}

<<<<<<< HEAD
void MHTMLArchive::generateMHTMLFooter(const String& boundary,
    Vector<char>& outputBuffer)
{
    ASSERT(!boundary.isEmpty());
=======
void MHTMLArchive::generateMHTMLFooter(
    const String& boundary,
    SharedBuffer& outputBuffer)
{
>>>>>>> miniblink49
    CString asciiString = String("--" + boundary + "--\r\n").utf8();
    outputBuffer.append(asciiString.data(), asciiString.length());
}

<<<<<<< HEAD
void MHTMLArchive::setMainResource(ArchiveResource* mainResource)
=======
PassRefPtr<SharedBuffer> MHTMLArchive::generateMHTMLData(
    const Vector<SerializedResource>& resources,
    EncodingPolicy encodingPolicy,
    const String& title, const String& mimeType)
{
    String boundary = MHTMLArchive::generateMHTMLBoundary();

    RefPtr<SharedBuffer> mhtmlData = SharedBuffer::create();
    MHTMLArchive::generateMHTMLHeader(boundary, title, mimeType, *mhtmlData);
    for (const auto& resource : resources) {
        MHTMLArchive::generateMHTMLPart(
            boundary, encodingPolicy, resource, *mhtmlData);
    }
    MHTMLArchive::generateMHTMLFooter(boundary, *mhtmlData);
    return mhtmlData.release();
}

#if !ENABLE(OILPAN)
void MHTMLArchive::clearAllSubframeArchives()
{
    SubFrameArchives clearedArchives;
    clearAllSubframeArchivesImpl(&clearedArchives);
}

void MHTMLArchive::clearAllSubframeArchivesImpl(SubFrameArchives* clearedArchives)
{
    for (SubFrameArchives::iterator it = m_subframeArchives.begin(); it != m_subframeArchives.end(); ++it) {
        if (!clearedArchives->contains(*it)) {
            clearedArchives->append(*it);
            (*it)->clearAllSubframeArchivesImpl(clearedArchives);
        }
    }
    m_subframeArchives.clear();
}
#endif

void MHTMLArchive::setMainResource(PassRefPtrWillBeRawPtr<ArchiveResource> mainResource)
>>>>>>> miniblink49
{
    m_mainResource = mainResource;
}

<<<<<<< HEAD
void MHTMLArchive::addSubresource(ArchiveResource* resource)
{
    const KURL& url = resource->url();
    m_subresources.set(url, resource);
    KURL cidURI = MHTMLParser::convertContentIDToURI(resource->contentID());
    if (cidURI.isValid())
        m_subresources.set(cidURI, resource);
}

ArchiveResource* MHTMLArchive::subresourceForURL(const KURL& url) const
{
    return m_subresources.get(url.getString());
=======
void MHTMLArchive::addSubresource(PassRefPtrWillBeRawPtr<ArchiveResource> subResource)
{
    m_subresources.append(subResource);
}

void MHTMLArchive::addSubframeArchive(PassRefPtrWillBeRawPtr<MHTMLArchive> subframeArchive)
{
    m_subframeArchives.append(subframeArchive);
>>>>>>> miniblink49
}

DEFINE_TRACE(MHTMLArchive)
{
    visitor->trace(m_mainResource);
    visitor->trace(m_subresources);
<<<<<<< HEAD
}

} // namespace blink
=======
    visitor->trace(m_subframeArchives);
}

}
>>>>>>> miniblink49
