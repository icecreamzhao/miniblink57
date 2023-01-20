// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/fetch/BodyStreamBuffer.h"

#include "bindings/core/v8/V8BindingForTesting.h"
#include "core/dom/Document.h"
#include "core/html/FormData.h"
#include "modules/fetch/BlobBytesConsumer.h"
#include "modules/fetch/BytesConsumerTestUtil.h"
#include "modules/fetch/FormDataBytesConsumer.h"
#include "platform/blob/BlobData.h"
#include "platform/blob/BlobURL.h"
#include "platform/network/EncodedFormData.h"
#include "platform/testing/UnitTestHelpers.h"
#include "testing/gmock/include/gmock/gmock.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "wtf/PtrUtil.h"
#include <memory>
=======
#include "config.h"
#include "modules/fetch/BodyStreamBuffer.h"

#include "core/testing/DummyPageHolder.h"
#include "modules/fetch/DataConsumerHandleTestUtil.h"
#include "platform/testing/UnitTestHelpers.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
>>>>>>> miniblink49

namespace blink {

namespace {

<<<<<<< HEAD
    using ::testing::_;
    using ::testing::ByMove;
    using ::testing::InSequence;
    using ::testing::Return;
    using ::testing::SaveArg;
    using Checkpoint = ::testing::StrictMock<::testing::MockFunction<void(int)>>;
    using Command = BytesConsumerTestUtil::Command;
    using ReplayingBytesConsumer = BytesConsumerTestUtil::ReplayingBytesConsumer;
    using MockFetchDataLoaderClient = BytesConsumerTestUtil::MockFetchDataLoaderClient;

    class BodyStreamBufferTest : public ::testing::Test {
    protected:
        ScriptValue eval(ScriptState* scriptState, const char* s)
        {
            v8::Local<v8::String> source;
            v8::Local<v8::Script> script;
            v8::MicrotasksScope microtasks(scriptState->isolate(),
                v8::MicrotasksScope::kDoNotRunMicrotasks);
            if (!v8Call(v8::String::NewFromUtf8(scriptState->isolate(), s,
                            v8::NewStringType::kNormal),
                    source)) {
                ADD_FAILURE();
                return ScriptValue();
            }
            if (!v8Call(v8::Script::Compile(scriptState->context(), source), script)) {
                ADD_FAILURE() << "Compilation fails";
                return ScriptValue();
            }
            return ScriptValue(scriptState, script->Run(scriptState->context()));
        }
        ScriptValue evalWithPrintingError(ScriptState* scriptState, const char* s)
        {
            v8::TryCatch block(scriptState->isolate());
            ScriptValue r = eval(scriptState, s);
            if (block.HasCaught()) {
                ADD_FAILURE() << toCoreString(
                    block.Exception()->ToString(scriptState->isolate()))
                                     .utf8()
                                     .data();
                block.ReThrow();
            }
            return r;
        }
    };

    TEST_F(BodyStreamBufferTest, Tee)
    {
        V8TestingScope scope;
        Checkpoint checkpoint;
        MockFetchDataLoaderClient* client1 = MockFetchDataLoaderClient::create();
        MockFetchDataLoaderClient* client2 = MockFetchDataLoaderClient::create();

        InSequence s;
        EXPECT_CALL(checkpoint, Call(0));
        EXPECT_CALL(*client1, didFetchDataLoadedString(String("hello, world")));
        EXPECT_CALL(checkpoint, Call(1));
        EXPECT_CALL(checkpoint, Call(2));
        EXPECT_CALL(*client2, didFetchDataLoadedString(String("hello, world")));
        EXPECT_CALL(checkpoint, Call(3));
        EXPECT_CALL(checkpoint, Call(4));

        ReplayingBytesConsumer* src = new ReplayingBytesConsumer(&scope.document());
        src->add(Command(Command::Data, "hello, "));
        src->add(Command(Command::Data, "world"));
        src->add(Command(Command::Done));
        BodyStreamBuffer* buffer = new BodyStreamBuffer(scope.getScriptState(), src);

        BodyStreamBuffer* new1;
        BodyStreamBuffer* new2;
        buffer->tee(&new1, &new2);

        EXPECT_TRUE(buffer->isStreamLocked());
        EXPECT_TRUE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());

        checkpoint.Call(0);
        new1->startLoading(FetchDataLoader::createLoaderAsString(), client1);
        checkpoint.Call(1);
        testing::runPendingTasks();
        checkpoint.Call(2);

        new2->startLoading(FetchDataLoader::createLoaderAsString(), client2);
        checkpoint.Call(3);
        testing::runPendingTasks();
        checkpoint.Call(4);
    }

    TEST_F(BodyStreamBufferTest, TeeFromHandleMadeFromStream)
    {
        V8TestingScope scope;
        ScriptValue stream = evalWithPrintingError(
            scope.getScriptState(),
            "stream = new ReadableStream({start: c => controller = c});"
            "controller.enqueue(new Uint8Array([0x41, 0x42]));"
            "controller.enqueue(new Uint8Array([0x55, 0x58]));"
            "controller.close();"
            "stream");
        Checkpoint checkpoint;
        MockFetchDataLoaderClient* client1 = MockFetchDataLoaderClient::create();
        MockFetchDataLoaderClient* client2 = MockFetchDataLoaderClient::create();

        InSequence s;
        EXPECT_CALL(checkpoint, Call(1));
        EXPECT_CALL(*client1, didFetchDataLoadedString(String("ABUX")));
        EXPECT_CALL(checkpoint, Call(2));
        EXPECT_CALL(checkpoint, Call(3));
        EXPECT_CALL(*client2, didFetchDataLoadedString(String("ABUX")));
        EXPECT_CALL(checkpoint, Call(4));

        BodyStreamBuffer* buffer = new BodyStreamBuffer(scope.getScriptState(), stream);

        BodyStreamBuffer* new1;
        BodyStreamBuffer* new2;
        buffer->tee(&new1, &new2);

        EXPECT_TRUE(buffer->isStreamLocked());
        // Note that this behavior is slightly different from for the behavior of
        // a BodyStreamBuffer made from a BytesConsumer. See the above test. In this
        // test, the stream will get disturbed when the microtask is performed.
        // TODO(yhirano): A uniformed behavior is preferred.
        EXPECT_FALSE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());

        v8::MicrotasksScope::PerformCheckpoint(scope.getScriptState()->isolate());

        EXPECT_TRUE(buffer->isStreamLocked());
        EXPECT_TRUE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());

        new1->startLoading(FetchDataLoader::createLoaderAsString(), client1);
        checkpoint.Call(1);
        testing::runPendingTasks();
        checkpoint.Call(2);

        new2->startLoading(FetchDataLoader::createLoaderAsString(), client2);
        checkpoint.Call(3);
        testing::runPendingTasks();
        checkpoint.Call(4);
    }

    TEST_F(BodyStreamBufferTest, DrainAsBlobDataHandle)
    {
        V8TestingScope scope;
        std::unique_ptr<BlobData> data = BlobData::create();
        data->appendText("hello", false);
        auto size = data->length();
        RefPtr<BlobDataHandle> blobDataHandle = BlobDataHandle::create(std::move(data), size);
        BodyStreamBuffer* buffer = new BodyStreamBuffer(
            scope.getScriptState(),
            new BlobBytesConsumer(scope.getExecutionContext(), blobDataHandle));

        EXPECT_FALSE(buffer->isStreamLocked());
        EXPECT_FALSE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());
        RefPtr<BlobDataHandle> outputBlobDataHandle = buffer->drainAsBlobDataHandle(
            BytesConsumer::BlobSizePolicy::AllowBlobWithInvalidSize);

        EXPECT_TRUE(buffer->isStreamLocked());
        EXPECT_TRUE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());
        EXPECT_EQ(blobDataHandle, outputBlobDataHandle);
    }

    TEST_F(BodyStreamBufferTest, DrainAsBlobDataHandleReturnsNull)
    {
        V8TestingScope scope;
        // This BytesConsumer is not drainable.
        BytesConsumer* src = new ReplayingBytesConsumer(&scope.document());
        BodyStreamBuffer* buffer = new BodyStreamBuffer(scope.getScriptState(), src);

        EXPECT_FALSE(buffer->isStreamLocked());
        EXPECT_FALSE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());

        EXPECT_FALSE(buffer->drainAsBlobDataHandle(
            BytesConsumer::BlobSizePolicy::AllowBlobWithInvalidSize));

        EXPECT_FALSE(buffer->isStreamLocked());
        EXPECT_FALSE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());
    }

    TEST_F(BodyStreamBufferTest,
        DrainAsBlobFromBufferMadeFromBufferMadeFromStream)
    {
        V8TestingScope scope;
        ScriptValue stream = evalWithPrintingError(scope.getScriptState(), "new ReadableStream()");
        BodyStreamBuffer* buffer = new BodyStreamBuffer(scope.getScriptState(), stream);

        EXPECT_FALSE(buffer->hasPendingActivity());
        EXPECT_FALSE(buffer->isStreamLocked());
        EXPECT_FALSE(buffer->isStreamDisturbed());
        EXPECT_TRUE(buffer->isStreamReadable());

        EXPECT_FALSE(buffer->drainAsBlobDataHandle(
            BytesConsumer::BlobSizePolicy::AllowBlobWithInvalidSize));

        EXPECT_FALSE(buffer->hasPendingActivity());
        EXPECT_FALSE(buffer->isStreamLocked());
        EXPECT_FALSE(buffer->isStreamDisturbed());
        EXPECT_TRUE(buffer->isStreamReadable());
    }

    TEST_F(BodyStreamBufferTest, DrainAsFormData)
    {
        V8TestingScope scope;
        FormData* data = FormData::create(UTF8Encoding());
        data->append("name1", "value1");
        data->append("name2", "value2");
        RefPtr<EncodedFormData> inputFormData = data->encodeMultiPartFormData();

        BodyStreamBuffer* buffer = new BodyStreamBuffer(
            scope.getScriptState(),
            new FormDataBytesConsumer(scope.getExecutionContext(), inputFormData));

        EXPECT_FALSE(buffer->isStreamLocked());
        EXPECT_FALSE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());
        RefPtr<EncodedFormData> outputFormData = buffer->drainAsFormData();

        EXPECT_TRUE(buffer->isStreamLocked());
        EXPECT_TRUE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());
        EXPECT_EQ(outputFormData->flattenToString(),
            inputFormData->flattenToString());
    }

    TEST_F(BodyStreamBufferTest, DrainAsFormDataReturnsNull)
    {
        V8TestingScope scope;
        // This BytesConsumer is not drainable.
        BytesConsumer* src = new ReplayingBytesConsumer(&scope.document());
        BodyStreamBuffer* buffer = new BodyStreamBuffer(scope.getScriptState(), src);

        EXPECT_FALSE(buffer->isStreamLocked());
        EXPECT_FALSE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());

        EXPECT_FALSE(buffer->drainAsFormData());

        EXPECT_FALSE(buffer->isStreamLocked());
        EXPECT_FALSE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());
    }

    TEST_F(BodyStreamBufferTest,
        DrainAsFormDataFromBufferMadeFromBufferMadeFromStream)
    {
        V8TestingScope scope;
        ScriptValue stream = evalWithPrintingError(scope.getScriptState(), "new ReadableStream()");
        BodyStreamBuffer* buffer = new BodyStreamBuffer(scope.getScriptState(), stream);

        EXPECT_FALSE(buffer->hasPendingActivity());
        EXPECT_FALSE(buffer->isStreamLocked());
        EXPECT_FALSE(buffer->isStreamDisturbed());
        EXPECT_TRUE(buffer->isStreamReadable());

        EXPECT_FALSE(buffer->drainAsFormData());

        EXPECT_FALSE(buffer->hasPendingActivity());
        EXPECT_FALSE(buffer->isStreamLocked());
        EXPECT_FALSE(buffer->isStreamDisturbed());
        EXPECT_TRUE(buffer->isStreamReadable());
    }

    TEST_F(BodyStreamBufferTest, LoadBodyStreamBufferAsArrayBuffer)
    {
        V8TestingScope scope;
        Checkpoint checkpoint;
        MockFetchDataLoaderClient* client = MockFetchDataLoaderClient::create();
        DOMArrayBuffer* arrayBuffer = nullptr;

        InSequence s;
        EXPECT_CALL(checkpoint, Call(1));
        EXPECT_CALL(*client, didFetchDataLoadedArrayBufferMock(_))
            .WillOnce(SaveArg<0>(&arrayBuffer));
        EXPECT_CALL(checkpoint, Call(2));

        ReplayingBytesConsumer* src = new ReplayingBytesConsumer(&scope.document());
        src->add(Command(Command::Wait));
        src->add(Command(Command::Data, "hello"));
        src->add(Command(Command::Done));
        BodyStreamBuffer* buffer = new BodyStreamBuffer(scope.getScriptState(), src);
        buffer->startLoading(FetchDataLoader::createLoaderAsArrayBuffer(), client);

        EXPECT_TRUE(buffer->isStreamLocked());
        EXPECT_TRUE(buffer->isStreamDisturbed());
        EXPECT_TRUE(buffer->hasPendingActivity());

        checkpoint.Call(1);
        testing::runPendingTasks();
        checkpoint.Call(2);

        EXPECT_TRUE(buffer->isStreamLocked());
        EXPECT_TRUE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());
        ASSERT_TRUE(arrayBuffer);
        EXPECT_EQ("hello", String(static_cast<const char*>(arrayBuffer->data()), arrayBuffer->byteLength()));
    }

    TEST_F(BodyStreamBufferTest, LoadBodyStreamBufferAsBlob)
    {
        V8TestingScope scope;
        Checkpoint checkpoint;
        MockFetchDataLoaderClient* client = MockFetchDataLoaderClient::create();
        RefPtr<BlobDataHandle> blobDataHandle;

        InSequence s;
        EXPECT_CALL(checkpoint, Call(1));
        EXPECT_CALL(*client, didFetchDataLoadedBlobHandleMock(_))
            .WillOnce(SaveArg<0>(&blobDataHandle));
        EXPECT_CALL(checkpoint, Call(2));

        ReplayingBytesConsumer* src = new ReplayingBytesConsumer(&scope.document());
        src->add(Command(Command::Wait));
        src->add(Command(Command::Data, "hello"));
        src->add(Command(Command::Done));
        BodyStreamBuffer* buffer = new BodyStreamBuffer(scope.getScriptState(), src);
        buffer->startLoading(FetchDataLoader::createLoaderAsBlobHandle("text/plain"),
            client);

        EXPECT_TRUE(buffer->isStreamLocked());
        EXPECT_TRUE(buffer->isStreamDisturbed());
        EXPECT_TRUE(buffer->hasPendingActivity());

        checkpoint.Call(1);
        testing::runPendingTasks();
        checkpoint.Call(2);

        EXPECT_TRUE(buffer->isStreamLocked());
        EXPECT_TRUE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());
        EXPECT_EQ(5u, blobDataHandle->size());
    }

    TEST_F(BodyStreamBufferTest, LoadBodyStreamBufferAsString)
    {
        V8TestingScope scope;
        Checkpoint checkpoint;
        MockFetchDataLoaderClient* client = MockFetchDataLoaderClient::create();

        InSequence s;
        EXPECT_CALL(checkpoint, Call(1));
        EXPECT_CALL(*client, didFetchDataLoadedString(String("hello")));
        EXPECT_CALL(checkpoint, Call(2));

        ReplayingBytesConsumer* src = new ReplayingBytesConsumer(&scope.document());
        src->add(Command(Command::Wait));
        src->add(Command(Command::Data, "hello"));
        src->add(Command(Command::Done));
        BodyStreamBuffer* buffer = new BodyStreamBuffer(scope.getScriptState(), src);
        buffer->startLoading(FetchDataLoader::createLoaderAsString(), client);

        EXPECT_TRUE(buffer->isStreamLocked());
        EXPECT_TRUE(buffer->isStreamDisturbed());
        EXPECT_TRUE(buffer->hasPendingActivity());

        checkpoint.Call(1);
        testing::runPendingTasks();
        checkpoint.Call(2);

        EXPECT_TRUE(buffer->isStreamLocked());
        EXPECT_TRUE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());
    }

    TEST_F(BodyStreamBufferTest, LoadClosedHandle)
    {
        V8TestingScope scope;
        Checkpoint checkpoint;
        MockFetchDataLoaderClient* client = MockFetchDataLoaderClient::create();

        InSequence s;
        EXPECT_CALL(checkpoint, Call(1));
        EXPECT_CALL(*client, didFetchDataLoadedString(String("")));
        EXPECT_CALL(checkpoint, Call(2));

        BodyStreamBuffer* buffer = new BodyStreamBuffer(
            scope.getScriptState(), BytesConsumer::createClosed());

        EXPECT_TRUE(buffer->isStreamClosed());

        EXPECT_FALSE(buffer->isStreamLocked());
        EXPECT_FALSE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());

        checkpoint.Call(1);
        buffer->startLoading(FetchDataLoader::createLoaderAsString(), client);
        checkpoint.Call(2);

        EXPECT_TRUE(buffer->isStreamLocked());
        EXPECT_TRUE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());
    }

    TEST_F(BodyStreamBufferTest, LoadErroredHandle)
    {
        V8TestingScope scope;
        Checkpoint checkpoint;
        MockFetchDataLoaderClient* client = MockFetchDataLoaderClient::create();

        InSequence s;
        EXPECT_CALL(checkpoint, Call(1));
        EXPECT_CALL(*client, didFetchDataLoadFailed());
        EXPECT_CALL(checkpoint, Call(2));

        BodyStreamBuffer* buffer = new BodyStreamBuffer(
            scope.getScriptState(),
            BytesConsumer::createErrored(BytesConsumer::Error()));

        EXPECT_TRUE(buffer->isStreamErrored());

        EXPECT_FALSE(buffer->isStreamLocked());
        EXPECT_FALSE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());

        checkpoint.Call(1);
        buffer->startLoading(FetchDataLoader::createLoaderAsString(), client);
        checkpoint.Call(2);

        EXPECT_TRUE(buffer->isStreamLocked());
        EXPECT_TRUE(buffer->isStreamDisturbed());
        EXPECT_FALSE(buffer->hasPendingActivity());
    }

    TEST_F(BodyStreamBufferTest, LoaderShouldBeKeptAliveByBodyStreamBuffer)
    {
        V8TestingScope scope;
        Checkpoint checkpoint;
        MockFetchDataLoaderClient* client = MockFetchDataLoaderClient::create();

        InSequence s;
        EXPECT_CALL(checkpoint, Call(1));
        EXPECT_CALL(*client, didFetchDataLoadedString(String("hello")));
        EXPECT_CALL(checkpoint, Call(2));

        ReplayingBytesConsumer* src = new ReplayingBytesConsumer(&scope.document());
        src->add(Command(Command::Wait));
        src->add(Command(Command::Data, "hello"));
        src->add(Command(Command::Done));
        Persistent<BodyStreamBuffer> buffer = new BodyStreamBuffer(scope.getScriptState(), src);
        buffer->startLoading(FetchDataLoader::createLoaderAsString(), client);

        ThreadState::current()->collectAllGarbage();
        checkpoint.Call(1);
        testing::runPendingTasks();
        checkpoint.Call(2);
    }

    TEST_F(BodyStreamBufferTest, SourceShouldBeCanceledWhenCanceled)
    {
        V8TestingScope scope;
        ReplayingBytesConsumer* consumer = new BytesConsumerTestUtil::ReplayingBytesConsumer(
            scope.getExecutionContext());

        BodyStreamBuffer* buffer = new BodyStreamBuffer(scope.getScriptState(), consumer);
        ScriptValue reason(scope.getScriptState(),
            v8String(scope.getScriptState()->isolate(), "reason"));
        EXPECT_FALSE(consumer->isCancelled());
        buffer->cancel(scope.getScriptState(), reason);
        EXPECT_TRUE(consumer->isCancelled());
    }
=======
using ::testing::InSequence;
using ::testing::_;
using ::testing::Return;
using Checkpoint = ::testing::StrictMock<::testing::MockFunction<void(int)>>;
using Command = DataConsumerHandleTestUtil::Command;
using ReplayingHandle = DataConsumerHandleTestUtil::ReplayingHandle;
using MockFetchDataConsumerHandle = DataConsumerHandleTestUtil::MockFetchDataConsumerHandle;
using MockFetchDataConsumerReader = DataConsumerHandleTestUtil::MockFetchDataConsumerReader;
using MockFetchDataLoaderClient = DataConsumerHandleTestUtil::MockFetchDataLoaderClient;

const FetchDataConsumerHandle::Reader::BlobSizePolicy kAllowBlobWithInvalidSize = FetchDataConsumerHandle::Reader::AllowBlobWithInvalidSize;

class MockDrainingStreamNotificationClient : public GarbageCollectedFinalized<MockDrainingStreamNotificationClient>, public BodyStreamBuffer::DrainingStreamNotificationClient {
    USING_GARBAGE_COLLECTED_MIXIN(MockDrainingStreamNotificationClient);
public:
    static ::testing::StrictMock<MockDrainingStreamNotificationClient>* create() { return new ::testing::StrictMock<MockDrainingStreamNotificationClient>; }

    DEFINE_INLINE_VIRTUAL_TRACE()
    {
        DrainingStreamNotificationClient::trace(visitor);
    }

    MOCK_METHOD0(didFetchDataLoadFinishedFromDrainingStream, void());
};

class DrainingBodyStreamBufferTest : public ::testing::Test {
public:
    DrainingBodyStreamBufferTest()
        : m_page(DummyPageHolder::create(IntSize(1, 1))) { }

    ScriptState* scriptState() { return ScriptState::forMainWorld(m_page->document().frame()); }
    ExecutionContext* executionContext() { return scriptState()->executionContext(); }

private:
    OwnPtr<DummyPageHolder> m_page;
};

TEST_F(DrainingBodyStreamBufferTest, NotifyOnDestruction)
{
    Checkpoint checkpoint;
    InSequence s;

    MockDrainingStreamNotificationClient* client = MockDrainingStreamNotificationClient::create();

    EXPECT_CALL(checkpoint, Call(1));
    EXPECT_CALL(*client, didFetchDataLoadFinishedFromDrainingStream());
    EXPECT_CALL(checkpoint, Call(2));

    BodyStreamBuffer* buffer = BodyStreamBuffer::createEmpty();
    OwnPtr<DrainingBodyStreamBuffer> drainingBuffer = DrainingBodyStreamBuffer::create(buffer, client);
    checkpoint.Call(1);
    drainingBuffer.clear();
    checkpoint.Call(2);
}

TEST_F(DrainingBodyStreamBufferTest, NotifyWhenBlobDataHandleIsDrained)
{
    Checkpoint checkpoint;
    InSequence s;

    OwnPtr<MockFetchDataConsumerHandle> src(MockFetchDataConsumerHandle::create());
    OwnPtr<MockFetchDataConsumerReader> reader(MockFetchDataConsumerReader::create());
    RefPtr<BlobDataHandle> blobDataHandle = BlobDataHandle::create();

    MockDrainingStreamNotificationClient* client = MockDrainingStreamNotificationClient::create();

    EXPECT_CALL(checkpoint, Call(1));
    EXPECT_CALL(checkpoint, Call(2));
    EXPECT_CALL(*src, obtainReaderInternal(_)).WillOnce(Return(reader.get()));
    EXPECT_CALL(*reader, drainAsBlobDataHandle(kAllowBlobWithInvalidSize)).WillOnce(Return(blobDataHandle));
    EXPECT_CALL(*client, didFetchDataLoadFinishedFromDrainingStream());
    EXPECT_CALL(checkpoint, Call(3));
    EXPECT_CALL(checkpoint, Call(4));

    // |reader| is adopted by |obtainReader|.
    ASSERT_TRUE(reader.leakPtr());

    BodyStreamBuffer* buffer = BodyStreamBuffer::create(src.release());
    checkpoint.Call(1);
    OwnPtr<DrainingBodyStreamBuffer> drainingBuffer = DrainingBodyStreamBuffer::create(buffer, client);
    checkpoint.Call(2);
    EXPECT_EQ(blobDataHandle, drainingBuffer->drainAsBlobDataHandle(kAllowBlobWithInvalidSize));
    checkpoint.Call(3);
    drainingBuffer.clear();
    checkpoint.Call(4);
}

TEST_F(DrainingBodyStreamBufferTest, DoNotNotifyWhenNullBlobDataHandleIsDrained)
{
    Checkpoint checkpoint;
    InSequence s;

    MockDrainingStreamNotificationClient* client = MockDrainingStreamNotificationClient::create();

    EXPECT_CALL(checkpoint, Call(1));
    EXPECT_CALL(checkpoint, Call(2));
    EXPECT_CALL(*client, didFetchDataLoadFinishedFromDrainingStream());
    EXPECT_CALL(checkpoint, Call(3));

    BodyStreamBuffer* buffer = BodyStreamBuffer::createEmpty();
    OwnPtr<DrainingBodyStreamBuffer> drainingBuffer = DrainingBodyStreamBuffer::create(buffer, client);
    checkpoint.Call(1);
    EXPECT_FALSE(drainingBuffer->drainAsBlobDataHandle(kAllowBlobWithInvalidSize));
    checkpoint.Call(2);
    drainingBuffer.clear();
    checkpoint.Call(3);
}

TEST_F(DrainingBodyStreamBufferTest, DoNotNotifyWhenBufferIsLeaked)
{
    Checkpoint checkpoint;
    InSequence s;

    MockDrainingStreamNotificationClient* client = MockDrainingStreamNotificationClient::create();

    EXPECT_CALL(checkpoint, Call(1));
    EXPECT_CALL(checkpoint, Call(2));
    EXPECT_CALL(checkpoint, Call(3));

    BodyStreamBuffer* buffer = BodyStreamBuffer::createEmpty();

    OwnPtr<DrainingBodyStreamBuffer> drainingBuffer = DrainingBodyStreamBuffer::create(buffer, client);
    checkpoint.Call(1);
    EXPECT_EQ(buffer, drainingBuffer->leakBuffer());
    checkpoint.Call(2);
    drainingBuffer.clear();
    checkpoint.Call(3);
}

TEST_F(DrainingBodyStreamBufferTest, NotifyOnStartLoading)
{
    Checkpoint checkpoint;
    InSequence s;

    OwnPtr<ReplayingHandle> src(ReplayingHandle::create());
    src->add(Command(Command::Data, "hello, world."));
    src->add(Command(Command::Done));

    MockDrainingStreamNotificationClient* client = MockDrainingStreamNotificationClient::create();
    MockFetchDataLoaderClient* fetchDataLoaderClient = MockFetchDataLoaderClient::create();
    FetchDataLoader* fetchDataLoader = FetchDataLoader::createLoaderAsString();

    EXPECT_CALL(checkpoint, Call(1));
    EXPECT_CALL(checkpoint, Call(2));
    EXPECT_CALL(checkpoint, Call(3));
    EXPECT_CALL(checkpoint, Call(4));
    EXPECT_CALL(*fetchDataLoaderClient, didFetchDataLoadedString(String("hello, world.")));
    EXPECT_CALL(*client, didFetchDataLoadFinishedFromDrainingStream());
    EXPECT_CALL(checkpoint, Call(5));

    Persistent<BodyStreamBuffer> buffer = BodyStreamBuffer::create(createFetchDataConsumerHandleFromWebHandle(src.release()));
    OwnPtr<DrainingBodyStreamBuffer> drainingBuffer = DrainingBodyStreamBuffer::create(buffer, client);
    checkpoint.Call(1);
    drainingBuffer->startLoading(executionContext(), fetchDataLoader, fetchDataLoaderClient);
    checkpoint.Call(2);
    drainingBuffer.clear();
    checkpoint.Call(3);
    // Loading continues as long as |buffer| is alive.
    Heap::collectAllGarbage();
    checkpoint.Call(4);
    testing::runPendingTasks();
    checkpoint.Call(5);
}
>>>>>>> miniblink49

} // namespace

} // namespace blink
