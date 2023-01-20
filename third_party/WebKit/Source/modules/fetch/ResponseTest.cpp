// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/fetch/Response.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/ScriptState.h"
<<<<<<< HEAD
#include "bindings/core/v8/V8BindingForTesting.h"
#include "core/dom/Document.h"
#include "core/frame/Frame.h"
#include "core/testing/DummyPageHolder.h"
#include "modules/fetch/BodyStreamBuffer.h"
#include "modules/fetch/BytesConsumer.h"
#include "modules/fetch/BytesConsumerTestUtil.h"
#include "modules/fetch/DataConsumerHandleTestUtil.h"
#include "modules/fetch/FetchResponseData.h"
#include "platform/blob/BlobData.h"
#include "platform/testing/UnitTestHelpers.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerResponse.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "wtf/PtrUtil.h"
#include "wtf/Vector.h"
#include <memory>
=======
#include "core/dom/Document.h"
#include "core/dom/ExceptionCode.h"
#include "core/frame/Frame.h"
#include "core/testing/DummyPageHolder.h"
#include "modules/fetch/BodyStreamBuffer.h"
#include "modules/fetch/DataConsumerHandleTestUtil.h"
#include "modules/fetch/DataConsumerHandleUtil.h"
#include "modules/fetch/FetchResponseData.h"
#include "platform/blob/BlobData.h"
#include "platform/testing/UnitTestHelpers.h"
#include "public/platform/WebServiceWorkerResponse.h"
#include <gtest/gtest.h>
>>>>>>> miniblink49

namespace blink {
namespace {

<<<<<<< HEAD
    std::unique_ptr<WebServiceWorkerResponse> createTestWebServiceWorkerResponse()
    {
        const KURL url(ParsedURLString, "http://www.webresponse.com/");
        const unsigned short status = 200;
        const String statusText = "the best status text";
        struct {
            const char* key;
            const char* value;
        } headers[] = { { "cache-control", "no-cache" },
            { "set-cookie", "foop" },
            { "foo", "bar" },
            { 0, 0 } };
        Vector<WebURL> urlList;
        urlList.push_back(url);
        std::unique_ptr<WebServiceWorkerResponse> webResponse = WTF::makeUnique<WebServiceWorkerResponse>();
        webResponse->setURLList(urlList);
        webResponse->setStatus(status);
        webResponse->setStatusText(statusText);
        webResponse->setResponseType(WebServiceWorkerResponseTypeDefault);
        for (int i = 0; headers[i].key; ++i)
            webResponse->setHeader(WebString::fromUTF8(headers[i].key),
                WebString::fromUTF8(headers[i].value));
        return webResponse;
    }

    TEST(ServiceWorkerResponseTest, FromFetchResponseData)
    {
        std::unique_ptr<DummyPageHolder> page = DummyPageHolder::create(IntSize(1, 1));
        const KURL url(ParsedURLString, "http://www.response.com");

        FetchResponseData* fetchResponseData = FetchResponseData::create();
        Vector<KURL> urlList;
        urlList.push_back(url);
        fetchResponseData->setURLList(urlList);
        Response* response = Response::create(&page->document(), fetchResponseData);
        ASSERT(response);
        EXPECT_EQ(url, response->url());
    }

    TEST(ServiceWorkerResponseTest, FromWebServiceWorkerResponse)
    {
        V8TestingScope scope;
        std::unique_ptr<WebServiceWorkerResponse> webResponse = createTestWebServiceWorkerResponse();
        Response* response = Response::create(scope.getScriptState(), *webResponse);
        ASSERT(response);
        ASSERT_EQ(1u, webResponse->urlList().size());
        EXPECT_EQ(webResponse->urlList()[0], response->url());
        EXPECT_EQ(webResponse->status(), response->status());
        EXPECT_STREQ(webResponse->statusText().utf8().c_str(),
            response->statusText().utf8().data());

        Headers* responseHeaders = response->headers();

        WebVector<WebString> keys = webResponse->getHeaderKeys();
        EXPECT_EQ(keys.size(), responseHeaders->headerList()->size());
        for (size_t i = 0, max = keys.size(); i < max; ++i) {
            WebString key = keys[i];
            DummyExceptionStateForTesting exceptionState;
            EXPECT_STREQ(webResponse->getHeader(key).utf8().c_str(),
                responseHeaders->get(key, exceptionState).utf8().data());
            EXPECT_FALSE(exceptionState.hadException());
        }
    }

    TEST(ServiceWorkerResponseTest, FromWebServiceWorkerResponseDefault)
    {
        V8TestingScope scope;
        std::unique_ptr<WebServiceWorkerResponse> webResponse = createTestWebServiceWorkerResponse();
        webResponse->setResponseType(WebServiceWorkerResponseTypeDefault);
        Response* response = Response::create(scope.getScriptState(), *webResponse);

        Headers* responseHeaders = response->headers();
        DummyExceptionStateForTesting exceptionState;
        EXPECT_STREQ(
            "foop", responseHeaders->get("set-cookie", exceptionState).utf8().data());
        EXPECT_STREQ("bar",
            responseHeaders->get("foo", exceptionState).utf8().data());
        EXPECT_STREQ(
            "no-cache",
            responseHeaders->get("cache-control", exceptionState).utf8().data());
        EXPECT_FALSE(exceptionState.hadException());
    }

    TEST(ServiceWorkerResponseTest, FromWebServiceWorkerResponseBasic)
    {
        V8TestingScope scope;
        std::unique_ptr<WebServiceWorkerResponse> webResponse = createTestWebServiceWorkerResponse();
        webResponse->setResponseType(WebServiceWorkerResponseTypeBasic);
        Response* response = Response::create(scope.getScriptState(), *webResponse);

        Headers* responseHeaders = response->headers();
        DummyExceptionStateForTesting exceptionState;
        EXPECT_STREQ(
            "", responseHeaders->get("set-cookie", exceptionState).utf8().data());
        EXPECT_STREQ("bar",
            responseHeaders->get("foo", exceptionState).utf8().data());
        EXPECT_STREQ(
            "no-cache",
            responseHeaders->get("cache-control", exceptionState).utf8().data());
        EXPECT_FALSE(exceptionState.hadException());
    }

    TEST(ServiceWorkerResponseTest, FromWebServiceWorkerResponseCORS)
    {
        V8TestingScope scope;
        std::unique_ptr<WebServiceWorkerResponse> webResponse = createTestWebServiceWorkerResponse();
        webResponse->setResponseType(WebServiceWorkerResponseTypeCORS);
        Response* response = Response::create(scope.getScriptState(), *webResponse);

        Headers* responseHeaders = response->headers();
        DummyExceptionStateForTesting exceptionState;
        EXPECT_STREQ(
            "", responseHeaders->get("set-cookie", exceptionState).utf8().data());
        EXPECT_STREQ("", responseHeaders->get("foo", exceptionState).utf8().data());
        EXPECT_STREQ(
            "no-cache",
            responseHeaders->get("cache-control", exceptionState).utf8().data());
        EXPECT_FALSE(exceptionState.hadException());
    }

    TEST(ServiceWorkerResponseTest, FromWebServiceWorkerResponseOpaque)
    {
        V8TestingScope scope;
        std::unique_ptr<WebServiceWorkerResponse> webResponse = createTestWebServiceWorkerResponse();
        webResponse->setResponseType(WebServiceWorkerResponseTypeOpaque);
        Response* response = Response::create(scope.getScriptState(), *webResponse);

        Headers* responseHeaders = response->headers();
        DummyExceptionStateForTesting exceptionState;
        EXPECT_STREQ(
            "", responseHeaders->get("set-cookie", exceptionState).utf8().data());
        EXPECT_STREQ("", responseHeaders->get("foo", exceptionState).utf8().data());
        EXPECT_STREQ(
            "", responseHeaders->get("cache-control", exceptionState).utf8().data());
        EXPECT_FALSE(exceptionState.hadException());
    }

    void checkResponseStream(ScriptState* scriptState,
        Response* response,
        bool checkResponseBodyStreamBuffer)
    {
        BodyStreamBuffer* originalInternal = response->internalBodyBuffer();
        if (checkResponseBodyStreamBuffer) {
            EXPECT_EQ(response->bodyBuffer(), originalInternal);
        } else {
            EXPECT_FALSE(response->bodyBuffer());
        }

        DummyExceptionStateForTesting exceptionState;
        Response* clonedResponse = response->clone(scriptState, exceptionState);
        EXPECT_FALSE(exceptionState.hadException());

        if (!response->internalBodyBuffer())
            FAIL() << "internalBodyBuffer() must not be null.";
        if (!clonedResponse->internalBodyBuffer())
            FAIL() << "internalBodyBuffer() must not be null.";
        EXPECT_TRUE(response->internalBodyBuffer());
        EXPECT_TRUE(clonedResponse->internalBodyBuffer());
        EXPECT_TRUE(response->internalBodyBuffer());
        EXPECT_TRUE(clonedResponse->internalBodyBuffer());
        EXPECT_NE(response->internalBodyBuffer(), originalInternal);
        EXPECT_NE(clonedResponse->internalBodyBuffer(), originalInternal);
        EXPECT_NE(response->internalBodyBuffer(),
            clonedResponse->internalBodyBuffer());
        if (checkResponseBodyStreamBuffer) {
            EXPECT_EQ(response->bodyBuffer(), response->internalBodyBuffer());
            EXPECT_EQ(clonedResponse->bodyBuffer(),
                clonedResponse->internalBodyBuffer());
        } else {
            EXPECT_FALSE(response->bodyBuffer());
            EXPECT_FALSE(clonedResponse->bodyBuffer());
        }
        BytesConsumerTestUtil::MockFetchDataLoaderClient* client1 = new BytesConsumerTestUtil::MockFetchDataLoaderClient();
        BytesConsumerTestUtil::MockFetchDataLoaderClient* client2 = new BytesConsumerTestUtil::MockFetchDataLoaderClient();
        EXPECT_CALL(*client1, didFetchDataLoadedString(String("Hello, world")));
        EXPECT_CALL(*client2, didFetchDataLoadedString(String("Hello, world")));

        response->internalBodyBuffer()->startLoading(
            FetchDataLoader::createLoaderAsString(), client1);
        clonedResponse->internalBodyBuffer()->startLoading(
            FetchDataLoader::createLoaderAsString(), client2);
        blink::testing::runPendingTasks();
    }

    BodyStreamBuffer* createHelloWorldBuffer(ScriptState* scriptState)
    {
        using Command = BytesConsumerTestUtil::Command;
        BytesConsumerTestUtil::ReplayingBytesConsumer* src = new BytesConsumerTestUtil::ReplayingBytesConsumer(
            scriptState->getExecutionContext());
        src->add(Command(Command::Data, "Hello, "));
        src->add(Command(Command::Data, "world"));
        src->add(Command(Command::Done));
        return new BodyStreamBuffer(scriptState, src);
    }

    TEST(ServiceWorkerResponseTest, BodyStreamBufferCloneDefault)
    {
        V8TestingScope scope;
        BodyStreamBuffer* buffer = createHelloWorldBuffer(scope.getScriptState());
        FetchResponseData* fetchResponseData = FetchResponseData::createWithBuffer(buffer);
        Vector<KURL> urlList;
        urlList.push_back(KURL(ParsedURLString, "http://www.response.com"));
        fetchResponseData->setURLList(urlList);
        Response* response = Response::create(scope.getExecutionContext(), fetchResponseData);
        EXPECT_EQ(response->internalBodyBuffer(), buffer);
        checkResponseStream(scope.getScriptState(), response, true);
    }

    TEST(ServiceWorkerResponseTest, BodyStreamBufferCloneBasic)
    {
        V8TestingScope scope;
        BodyStreamBuffer* buffer = createHelloWorldBuffer(scope.getScriptState());
        FetchResponseData* fetchResponseData = FetchResponseData::createWithBuffer(buffer);
        Vector<KURL> urlList;
        urlList.push_back(KURL(ParsedURLString, "http://www.response.com"));
        fetchResponseData->setURLList(urlList);
        fetchResponseData = fetchResponseData->createBasicFilteredResponse();
        Response* response = Response::create(scope.getExecutionContext(), fetchResponseData);
        EXPECT_EQ(response->internalBodyBuffer(), buffer);
        checkResponseStream(scope.getScriptState(), response, true);
    }

    TEST(ServiceWorkerResponseTest, BodyStreamBufferCloneCORS)
    {
        V8TestingScope scope;
        BodyStreamBuffer* buffer = createHelloWorldBuffer(scope.getScriptState());
        FetchResponseData* fetchResponseData = FetchResponseData::createWithBuffer(buffer);
        Vector<KURL> urlList;
        urlList.push_back(KURL(ParsedURLString, "http://www.response.com"));
        fetchResponseData->setURLList(urlList);
        fetchResponseData = fetchResponseData->createCORSFilteredResponse();
        Response* response = Response::create(scope.getExecutionContext(), fetchResponseData);
        EXPECT_EQ(response->internalBodyBuffer(), buffer);
        checkResponseStream(scope.getScriptState(), response, true);
    }

    TEST(ServiceWorkerResponseTest, BodyStreamBufferCloneOpaque)
    {
        V8TestingScope scope;
        BodyStreamBuffer* buffer = createHelloWorldBuffer(scope.getScriptState());
        FetchResponseData* fetchResponseData = FetchResponseData::createWithBuffer(buffer);
        Vector<KURL> urlList;
        urlList.push_back(KURL(ParsedURLString, "http://www.response.com"));
        fetchResponseData->setURLList(urlList);
        fetchResponseData = fetchResponseData->createOpaqueFilteredResponse();
        Response* response = Response::create(scope.getExecutionContext(), fetchResponseData);
        EXPECT_EQ(response->internalBodyBuffer(), buffer);
        checkResponseStream(scope.getScriptState(), response, false);
    }

    TEST(ServiceWorkerResponseTest, BodyStreamBufferCloneError)
    {
        V8TestingScope scope;
        BodyStreamBuffer* buffer = new BodyStreamBuffer(
            scope.getScriptState(),
            BytesConsumer::createErrored(BytesConsumer::Error()));
        FetchResponseData* fetchResponseData = FetchResponseData::createWithBuffer(buffer);
        Vector<KURL> urlList;
        urlList.push_back(KURL(ParsedURLString, "http://www.response.com"));
        fetchResponseData->setURLList(urlList);
        Response* response = Response::create(scope.getExecutionContext(), fetchResponseData);
        DummyExceptionStateForTesting exceptionState;
        Response* clonedResponse = response->clone(scope.getScriptState(), exceptionState);
        EXPECT_FALSE(exceptionState.hadException());

        BytesConsumerTestUtil::MockFetchDataLoaderClient* client1 = new BytesConsumerTestUtil::MockFetchDataLoaderClient();
        BytesConsumerTestUtil::MockFetchDataLoaderClient* client2 = new BytesConsumerTestUtil::MockFetchDataLoaderClient();
        EXPECT_CALL(*client1, didFetchDataLoadFailed());
        EXPECT_CALL(*client2, didFetchDataLoadFailed());

        response->internalBodyBuffer()->startLoading(
            FetchDataLoader::createLoaderAsString(), client1);
        clonedResponse->internalBodyBuffer()->startLoading(
            FetchDataLoader::createLoaderAsString(), client2);
        blink::testing::runPendingTasks();
    }
=======
PassOwnPtr<WebServiceWorkerResponse> createTestWebServiceWorkerResponse()
{
    const KURL url(ParsedURLString, "http://www.webresponse.com/");
    const unsigned short status = 200;
    const String statusText = "the best status text";
    struct {
        const char* key;
        const char* value;
    } headers[] = { { "cache-control", "no-cache" }, { "set-cookie", "foop" }, { "foo", "bar" }, { 0, 0 } };

    OwnPtr<WebServiceWorkerResponse> webResponse = adoptPtr(new WebServiceWorkerResponse());
    webResponse->setURL(url);
    webResponse->setStatus(status);
    webResponse->setStatusText(statusText);
    webResponse->setResponseType(WebServiceWorkerResponseTypeDefault);
    for (int i = 0; headers[i].key; ++i)
        webResponse->setHeader(WebString::fromUTF8(headers[i].key), WebString::fromUTF8(headers[i].value));
    return webResponse.release();
}

class ServiceWorkerResponseTest : public ::testing::Test {
public:
    ServiceWorkerResponseTest()
        : m_page(DummyPageHolder::create(IntSize(1, 1))) { }

    ScriptState* scriptState() { return ScriptState::forMainWorld(m_page->document().frame()); }
    ExecutionContext* executionContext() { return scriptState()->executionContext(); }

private:
    OwnPtr<DummyPageHolder> m_page;
};


TEST_F(ServiceWorkerResponseTest, FromFetchResponseData)
{
    const KURL url(ParsedURLString, "http://www.response.com");

    FetchResponseData* fetchResponseData = FetchResponseData::create();
    fetchResponseData->setURL(url);

    Response* response = Response::create(executionContext(), fetchResponseData);
    ASSERT(response);
    EXPECT_EQ(url, response->url());
}

TEST_F(ServiceWorkerResponseTest, FromWebServiceWorkerResponse)
{
    OwnPtr<WebServiceWorkerResponse> webResponse = createTestWebServiceWorkerResponse();
    Response* response = Response::create(executionContext(), *webResponse);
    ASSERT(response);
    EXPECT_EQ(webResponse->url(), response->url());
    EXPECT_EQ(webResponse->status(), response->status());
    EXPECT_STREQ(webResponse->statusText().utf8().c_str(), response->statusText().utf8().data());

    Headers* responseHeaders = response->headers();

    WebVector<WebString> keys = webResponse->getHeaderKeys();
    EXPECT_EQ(keys.size(), responseHeaders->headerList()->size());
    for (size_t i = 0, max = keys.size(); i < max; ++i) {
        WebString key = keys[i];
        TrackExceptionState exceptionState;
        EXPECT_STREQ(webResponse->getHeader(key).utf8().c_str(), responseHeaders->get(key, exceptionState).utf8().data());
        EXPECT_FALSE(exceptionState.hadException());
    }
}

TEST_F(ServiceWorkerResponseTest, FromWebServiceWorkerResponseDefault)
{
    OwnPtr<WebServiceWorkerResponse> webResponse = createTestWebServiceWorkerResponse();
    webResponse->setResponseType(WebServiceWorkerResponseTypeDefault);
    Response* response = Response::create(executionContext(), *webResponse);

    Headers* responseHeaders = response->headers();
    TrackExceptionState exceptionState;
    EXPECT_STREQ("foop", responseHeaders->get("set-cookie", exceptionState).utf8().data());
    EXPECT_STREQ("bar", responseHeaders->get("foo", exceptionState).utf8().data());
    EXPECT_STREQ("no-cache", responseHeaders->get("cache-control", exceptionState).utf8().data());
    EXPECT_FALSE(exceptionState.hadException());
}

TEST_F(ServiceWorkerResponseTest, FromWebServiceWorkerResponseBasic)
{
    OwnPtr<WebServiceWorkerResponse> webResponse = createTestWebServiceWorkerResponse();
    webResponse->setResponseType(WebServiceWorkerResponseTypeBasic);
    Response* response = Response::create(executionContext(), *webResponse);

    Headers* responseHeaders = response->headers();
    TrackExceptionState exceptionState;
    EXPECT_STREQ("", responseHeaders->get("set-cookie", exceptionState).utf8().data());
    EXPECT_STREQ("bar", responseHeaders->get("foo", exceptionState).utf8().data());
    EXPECT_STREQ("no-cache", responseHeaders->get("cache-control", exceptionState).utf8().data());
    EXPECT_FALSE(exceptionState.hadException());
}

TEST_F(ServiceWorkerResponseTest, FromWebServiceWorkerResponseCORS)
{
    OwnPtr<WebServiceWorkerResponse> webResponse = createTestWebServiceWorkerResponse();
    webResponse->setResponseType(WebServiceWorkerResponseTypeCORS);
    Response* response = Response::create(executionContext(), *webResponse);

    Headers* responseHeaders = response->headers();
    TrackExceptionState exceptionState;
    EXPECT_STREQ("", responseHeaders->get("set-cookie", exceptionState).utf8().data());
    EXPECT_STREQ("", responseHeaders->get("foo", exceptionState).utf8().data());
    EXPECT_STREQ("no-cache", responseHeaders->get("cache-control", exceptionState).utf8().data());
    EXPECT_FALSE(exceptionState.hadException());
}

TEST_F(ServiceWorkerResponseTest, FromWebServiceWorkerResponseOpaque)
{
    OwnPtr<WebServiceWorkerResponse> webResponse = createTestWebServiceWorkerResponse();
    webResponse->setResponseType(WebServiceWorkerResponseTypeOpaque);
    Response* response = Response::create(executionContext(), *webResponse);

    Headers* responseHeaders = response->headers();
    TrackExceptionState exceptionState;
    EXPECT_STREQ("", responseHeaders->get("set-cookie", exceptionState).utf8().data());
    EXPECT_STREQ("", responseHeaders->get("foo", exceptionState).utf8().data());
    EXPECT_STREQ("", responseHeaders->get("cache-control", exceptionState).utf8().data());
    EXPECT_FALSE(exceptionState.hadException());
}

void loadInternalBufferAsString(Response* response, FetchDataLoader::Client* client)
{
    FetchDataLoader* fetchDataLoader = FetchDataLoader::createLoaderAsString();
    OwnPtr<DrainingBodyStreamBuffer> buffer = response->createInternalDrainingStream();
    buffer->startLoading(response->executionContext(), fetchDataLoader, client);
}

void checkResponseStream(Response* response, bool checkResponseBodyStreamBuffer)
{
    void* buffer = response->internalBufferForTest();
    if (checkResponseBodyStreamBuffer) {
        EXPECT_EQ(response->bufferForTest(), buffer);
    } else {
        EXPECT_FALSE(response->bufferForTest());
    }

    TrackExceptionState exceptionState;
    Response* clonedResponse = response->clone(exceptionState);
    EXPECT_FALSE(exceptionState.hadException());

    EXPECT_TRUE(response->internalBufferForTest());
    EXPECT_TRUE(clonedResponse->internalBufferForTest());
    EXPECT_NE(response->internalBufferForTest(), buffer);
    EXPECT_NE(clonedResponse->internalBufferForTest(), buffer);
    EXPECT_NE(response->internalBufferForTest(), clonedResponse->internalBufferForTest());
    if (checkResponseBodyStreamBuffer) {
        EXPECT_EQ(response->bufferForTest(), response->internalBufferForTest());
        EXPECT_EQ(clonedResponse->bufferForTest(), clonedResponse->internalBufferForTest());
    } else {
        EXPECT_FALSE(response->bufferForTest());
        EXPECT_FALSE(clonedResponse->bufferForTest());
    }
    DataConsumerHandleTestUtil::MockFetchDataLoaderClient* client1 = new DataConsumerHandleTestUtil::MockFetchDataLoaderClient();
    DataConsumerHandleTestUtil::MockFetchDataLoaderClient* client2 = new DataConsumerHandleTestUtil::MockFetchDataLoaderClient();
    EXPECT_CALL(*client1, didFetchDataLoadedString(String("Hello, world")));
    EXPECT_CALL(*client2, didFetchDataLoadedString(String("Hello, world")));

    loadInternalBufferAsString(response, client1);
    loadInternalBufferAsString(clonedResponse, client2);
    blink::testing::runPendingTasks();
}

BodyStreamBuffer* createHelloWorldBuffer()
{
    using Command = DataConsumerHandleTestUtil::Command;
    OwnPtr<DataConsumerHandleTestUtil::ReplayingHandle> src(DataConsumerHandleTestUtil::ReplayingHandle::create());
    src->add(Command(Command::Data, "Hello, "));
    src->add(Command(Command::Data, "world"));
    src->add(Command(Command::Done));
    return BodyStreamBuffer::create(createFetchDataConsumerHandleFromWebHandle(src.release()));
}

TEST_F(ServiceWorkerResponseTest, BodyStreamBufferCloneDefault)
{
    BodyStreamBuffer* buffer = createHelloWorldBuffer();
    FetchResponseData* fetchResponseData = FetchResponseData::createWithBuffer(buffer);
    fetchResponseData->setURL(KURL(ParsedURLString, "http://www.response.com"));
    Response* response = Response::create(executionContext(), fetchResponseData);
    EXPECT_EQ(response->internalBufferForTest(), buffer);
    checkResponseStream(response, true);
}

TEST_F(ServiceWorkerResponseTest, BodyStreamBufferCloneBasic)
{
    BodyStreamBuffer* buffer = createHelloWorldBuffer();
    FetchResponseData* fetchResponseData = FetchResponseData::createWithBuffer(buffer);
    fetchResponseData->setURL(KURL(ParsedURLString, "http://www.response.com"));
    fetchResponseData = fetchResponseData->createBasicFilteredResponse();
    Response* response = Response::create(executionContext(), fetchResponseData);
    EXPECT_EQ(response->internalBufferForTest(), buffer);
    checkResponseStream(response, true);
}

TEST_F(ServiceWorkerResponseTest, BodyStreamBufferCloneCORS)
{
    BodyStreamBuffer* buffer = createHelloWorldBuffer();
    FetchResponseData* fetchResponseData = FetchResponseData::createWithBuffer(buffer);
    fetchResponseData->setURL(KURL(ParsedURLString, "http://www.response.com"));
    fetchResponseData = fetchResponseData->createCORSFilteredResponse();
    Response* response = Response::create(executionContext(), fetchResponseData);
    EXPECT_EQ(response->internalBufferForTest(), buffer);
    checkResponseStream(response, true);
}

TEST_F(ServiceWorkerResponseTest, BodyStreamBufferCloneOpaque)
{
    BodyStreamBuffer* buffer = createHelloWorldBuffer();
    FetchResponseData* fetchResponseData = FetchResponseData::createWithBuffer(buffer);
    fetchResponseData->setURL(KURL(ParsedURLString, "http://www.response.com"));
    fetchResponseData = fetchResponseData->createOpaqueFilteredResponse();
    Response* response = Response::create(executionContext(), fetchResponseData);
    EXPECT_EQ(response->internalBufferForTest(), buffer);
    checkResponseStream(response, false);
}

TEST_F(ServiceWorkerResponseTest, BodyStreamBufferCloneError)
{
    BodyStreamBuffer* buffer = BodyStreamBuffer::create(createFetchDataConsumerHandleFromWebHandle(createUnexpectedErrorDataConsumerHandle()));
    FetchResponseData* fetchResponseData = FetchResponseData::createWithBuffer(buffer);
    fetchResponseData->setURL(KURL(ParsedURLString, "http://www.response.com"));
    Response* response = Response::create(executionContext(), fetchResponseData);
    TrackExceptionState exceptionState;
    Response* clonedResponse = response->clone(exceptionState);
    EXPECT_FALSE(exceptionState.hadException());

    DataConsumerHandleTestUtil::MockFetchDataLoaderClient* client1 = new DataConsumerHandleTestUtil::MockFetchDataLoaderClient();
    DataConsumerHandleTestUtil::MockFetchDataLoaderClient* client2 = new DataConsumerHandleTestUtil::MockFetchDataLoaderClient();
    EXPECT_CALL(*client1, didFetchDataLoadFailed());
    EXPECT_CALL(*client2, didFetchDataLoadFailed());

    loadInternalBufferAsString(response, client1);
    loadInternalBufferAsString(clonedResponse, client2);
    blink::testing::runPendingTasks();
}
>>>>>>> miniblink49

} // namespace
} // namespace blink
