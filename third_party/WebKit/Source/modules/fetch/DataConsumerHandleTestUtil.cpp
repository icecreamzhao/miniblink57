// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/fetch/DataConsumerHandleTestUtil.h"

#include "bindings/core/v8/DOMWrapperWorld.h"
#include "public/platform/WebScheduler.h"
#include "wtf/PtrUtil.h"
#include <memory>

namespace blink {

using Result = WebDataConsumerHandle::Result;

namespace {

    class WaitingHandle final : public WebDataConsumerHandle {
    private:
        class ReaderImpl final : public WebDataConsumerHandle::Reader {
        public:
            Result beginRead(const void** buffer,
                WebDataConsumerHandle::Flags,
                size_t* available) override
            {
                *available = 0;
                *buffer = nullptr;
                return ShouldWait;
            }
            Result endRead(size_t) override { return UnexpectedError; }
        };
        std::unique_ptr<Reader> obtainReader(Client*) override
        {
            return WTF::wrapUnique(new ReaderImpl);
        }

        const char* debugName() const override { return "WaitingHandle"; }
    };

} // namespace

DataConsumerHandleTestUtil::Thread::Thread(
    const char* name,
    InitializationPolicy initializationPolicy)
    : m_thread(WebThreadSupportingGC::create(name))
    , m_initializationPolicy(initializationPolicy)
    , m_waitableEvent(WTF::makeUnique<WaitableEvent>())
{
    m_thread->postTask(
        BLINK_FROM_HERE,
        crossThreadBind(&Thread::initialize, crossThreadUnretained(this)));
=======
#include "config.h"
#include "modules/fetch/DataConsumerHandleTestUtil.h"

#include "bindings/core/v8/DOMWrapperWorld.h"

namespace blink {

DataConsumerHandleTestUtil::Thread::Thread(const char* name, InitializationPolicy initializationPolicy)
    : m_thread(WebThreadSupportingGC::create(name))
    , m_initializationPolicy(initializationPolicy)
    , m_waitableEvent(adoptPtr(Platform::current()->createWaitableEvent()))
{
    m_thread->postTask(FROM_HERE, new Task(threadSafeBind(&Thread::initialize, AllowCrossThreadAccess(this))));
>>>>>>> miniblink49
    m_waitableEvent->wait();
}

DataConsumerHandleTestUtil::Thread::~Thread()
{
<<<<<<< HEAD
    m_thread->postTask(
        BLINK_FROM_HERE,
        crossThreadBind(&Thread::shutdown, crossThreadUnretained(this)));
=======
    m_thread->postTask(FROM_HERE, new Task(threadSafeBind(&Thread::shutdown, AllowCrossThreadAccess(this))));
>>>>>>> miniblink49
    m_waitableEvent->wait();
}

void DataConsumerHandleTestUtil::Thread::initialize()
{
    if (m_initializationPolicy >= ScriptExecution) {
<<<<<<< HEAD
        m_isolateHolder = WTF::makeUnique<gin::IsolateHolder>(Platform::current()
                                                                  ->currentThread()
                                                                  ->scheduler()
                                                                  ->loadingTaskRunner()
                                                                  ->toSingleThreadTaskRunner());
=======
        m_isolateHolder = adoptPtr(new gin::IsolateHolder());
>>>>>>> miniblink49
        isolate()->Enter();
    }
    m_thread->initialize();
    if (m_initializationPolicy >= ScriptExecution) {
        v8::HandleScope handleScope(isolate());
<<<<<<< HEAD
        m_scriptState = ScriptState::create(v8::Context::New(isolate()),
            DOMWrapperWorld::create(isolate()));
    }
    if (m_initializationPolicy >= WithExecutionContext) {
        m_executionContext = new NullExecutionContext();
=======
        m_scriptState = ScriptState::create(v8::Context::New(isolate()), DOMWrapperWorld::create(isolate()));
    }
    if (m_initializationPolicy >= WithExecutionContext) {
        m_executionContext = adoptRefWillBeNoop(new NullExecutionContext());
>>>>>>> miniblink49
    }
    m_waitableEvent->signal();
}

void DataConsumerHandleTestUtil::Thread::shutdown()
{
    m_executionContext = nullptr;
<<<<<<< HEAD
    if (m_scriptState) {
        m_scriptState->disposePerContextData();
    }
=======
>>>>>>> miniblink49
    m_scriptState = nullptr;
    m_thread->shutdown();
    if (m_isolateHolder) {
        isolate()->Exit();
<<<<<<< HEAD
        isolate()->RequestGarbageCollectionForTesting(
            isolate()->kFullGarbageCollection);
=======
>>>>>>> miniblink49
        m_isolateHolder = nullptr;
    }
    m_waitableEvent->signal();
}

<<<<<<< HEAD
class DataConsumerHandleTestUtil::ReplayingHandle::ReaderImpl final
    : public Reader {
=======
class DataConsumerHandleTestUtil::ReplayingHandle::ReaderImpl final : public Reader {
>>>>>>> miniblink49
public:
    ReaderImpl(PassRefPtr<Context> context, Client* client)
        : m_context(context)
    {
        m_context->attachReader(client);
    }
<<<<<<< HEAD
    ~ReaderImpl() { m_context->detachReader(); }

    Result beginRead(const void** buffer,
        Flags flags,
        size_t* available) override
=======
    ~ReaderImpl()
    {
        m_context->detachReader();
    }

    Result read(void* buffer, size_t size, Flags flags, size_t* readSize) override
    {
        const void* src = nullptr;
        Result result = beginRead(&src, flags, readSize);
        if (result != Ok)
            return result;
        *readSize = std::min(*readSize, size);
        memcpy(buffer, src, *readSize);
        return endRead(*readSize);
    }
    Result beginRead(const void** buffer, Flags flags, size_t* available) override
>>>>>>> miniblink49
    {
        return m_context->beginRead(buffer, flags, available);
    }
    Result endRead(size_t readSize) override
    {
        return m_context->endRead(readSize);
    }

private:
    RefPtr<Context> m_context;
};

<<<<<<< HEAD
void DataConsumerHandleTestUtil::ReplayingHandle::Context::add(
    const Command& command)
=======
void DataConsumerHandleTestUtil::ReplayingHandle::Context::add(const Command& command)
>>>>>>> miniblink49
{
    MutexLocker locker(m_mutex);
    m_commands.append(command);
}

<<<<<<< HEAD
void DataConsumerHandleTestUtil::ReplayingHandle::Context::attachReader(
    WebDataConsumerHandle::Client* client)
{
    MutexLocker locker(m_mutex);
    DCHECK(!m_readerThread);
    DCHECK(!m_client);
=======
void DataConsumerHandleTestUtil::ReplayingHandle::Context::attachReader(WebDataConsumerHandle::Client* client)
{
    MutexLocker locker(m_mutex);
    ASSERT(!m_readerThread);
    ASSERT(!m_client);
>>>>>>> miniblink49
    m_readerThread = Platform::current()->currentThread();
    m_client = client;

    if (m_client && !(isEmpty() && m_result == ShouldWait))
        notify();
}

void DataConsumerHandleTestUtil::ReplayingHandle::Context::detachReader()
{
    MutexLocker locker(m_mutex);
<<<<<<< HEAD
    DCHECK(m_readerThread && m_readerThread->isCurrentThread());
=======
    ASSERT(m_readerThread && m_readerThread->isCurrentThread());
>>>>>>> miniblink49
    m_readerThread = nullptr;
    m_client = nullptr;
    if (!m_isHandleAttached)
        m_detached->signal();
}

void DataConsumerHandleTestUtil::ReplayingHandle::Context::detachHandle()
{
    MutexLocker locker(m_mutex);
    m_isHandleAttached = false;
    if (!m_readerThread)
        m_detached->signal();
}

<<<<<<< HEAD
WebDataConsumerHandle::Result
DataConsumerHandleTestUtil::ReplayingHandle::Context::beginRead(
    const void** buffer,
    Flags,
    size_t* available)
=======
WebDataConsumerHandle::Result DataConsumerHandleTestUtil::ReplayingHandle::Context::beginRead(const void** buffer, Flags, size_t* available)
>>>>>>> miniblink49
{
    MutexLocker locker(m_mutex);
    *buffer = nullptr;
    *available = 0;
    if (isEmpty())
        return m_result;

    const Command& command = top();
    Result result = Ok;
<<<<<<< HEAD
    switch (command.getName()) {
=======
    switch (command.name()) {
>>>>>>> miniblink49
    case Command::Data: {
        auto& body = command.body();
        *available = body.size() - offset();
        *buffer = body.data() + offset();
        result = Ok;
        break;
    }
    case Command::Done:
        m_result = result = Done;
        consume(0);
        break;
    case Command::Wait:
        consume(0);
        result = ShouldWait;
        notify();
        break;
    case Command::Error:
        m_result = result = UnexpectedError;
        consume(0);
        break;
    }
    return result;
}

<<<<<<< HEAD
WebDataConsumerHandle::Result
DataConsumerHandleTestUtil::ReplayingHandle::Context::endRead(size_t readSize)
=======
WebDataConsumerHandle::Result DataConsumerHandleTestUtil::ReplayingHandle::Context::endRead(size_t readSize)
>>>>>>> miniblink49
{
    MutexLocker locker(m_mutex);
    consume(readSize);
    return Ok;
}

DataConsumerHandleTestUtil::ReplayingHandle::Context::Context()
    : m_offset(0)
    , m_readerThread(nullptr)
    , m_client(nullptr)
    , m_result(ShouldWait)
    , m_isHandleAttached(true)
<<<<<<< HEAD
    , m_detached(WTF::makeUnique<WaitableEvent>())
{
}

const DataConsumerHandleTestUtil::Command&
DataConsumerHandleTestUtil::ReplayingHandle::Context::top()
{
    DCHECK(!isEmpty());
    return m_commands.first();
}

void DataConsumerHandleTestUtil::ReplayingHandle::Context::consume(
    size_t size)
{
    DCHECK(!isEmpty());
    DCHECK(size + m_offset <= top().body().size());
=======
    , m_detached(adoptPtr(Platform::current()->createWaitableEvent()))
{
}

const DataConsumerHandleTestUtil::Command& DataConsumerHandleTestUtil::ReplayingHandle::Context::top()
{
    ASSERT(!isEmpty());
    return m_commands.first();
}

void DataConsumerHandleTestUtil::ReplayingHandle::Context::consume(size_t size)
{
    ASSERT(!isEmpty());
    ASSERT(size + m_offset <= top().body().size());
>>>>>>> miniblink49
    bool fullyConsumed = (size + m_offset >= top().body().size());
    if (fullyConsumed) {
        m_offset = 0;
        m_commands.removeFirst();
    } else {
        m_offset += size;
    }
}

void DataConsumerHandleTestUtil::ReplayingHandle::Context::notify()
{
    if (!m_client)
        return;
<<<<<<< HEAD
    DCHECK(m_readerThread);
    m_readerThread->getWebTaskRunner()->postTask(
        BLINK_FROM_HERE,
        crossThreadBind(&Context::notifyInternal, wrapPassRefPtr(this)));
=======
    ASSERT(m_readerThread);
    m_readerThread->postTask(FROM_HERE, new Task(threadSafeBind(&Context::notifyInternal, this)));
>>>>>>> miniblink49
}

void DataConsumerHandleTestUtil::ReplayingHandle::Context::notifyInternal()
{
    {
        MutexLocker locker(m_mutex);
        if (!m_client || !m_readerThread->isCurrentThread()) {
            // There is no client, or a new reader is attached.
            return;
        }
    }
    // The reading thread is the current thread.
    m_client->didGetReadable();
}

DataConsumerHandleTestUtil::ReplayingHandle::ReplayingHandle()
    : m_context(Context::create())
{
}

DataConsumerHandleTestUtil::ReplayingHandle::~ReplayingHandle()
{
    m_context->detachHandle();
}

<<<<<<< HEAD
std::unique_ptr<WebDataConsumerHandle::Reader>
DataConsumerHandleTestUtil::ReplayingHandle::obtainReader(Client* client)
{
    return WTF::makeUnique<ReaderImpl>(m_context, client);
=======
WebDataConsumerHandle::Reader* DataConsumerHandleTestUtil::ReplayingHandle::obtainReaderInternal(Client* client)
{
    return new ReaderImpl(m_context, client);
>>>>>>> miniblink49
}

void DataConsumerHandleTestUtil::ReplayingHandle::add(const Command& command)
{
    m_context->add(command);
}

<<<<<<< HEAD
DataConsumerHandleTestUtil::HandleReader::HandleReader(
    std::unique_ptr<WebDataConsumerHandle> handle,
    std::unique_ptr<OnFinishedReading> onFinishedReading)
    : m_reader(handle->obtainReader(this))
    , m_onFinishedReading(std::move(onFinishedReading))
=======
DataConsumerHandleTestUtil::HandleReader::HandleReader(PassOwnPtr<WebDataConsumerHandle> handle, PassOwnPtr<OnFinishedReading> onFinishedReading)
    : m_reader(handle->obtainReader(this))
    , m_onFinishedReading(onFinishedReading)
>>>>>>> miniblink49
{
}

void DataConsumerHandleTestUtil::HandleReader::didGetReadable()
{
    WebDataConsumerHandle::Result r = WebDataConsumerHandle::UnexpectedError;
    char buffer[3];
    while (true) {
        size_t size;
<<<<<<< HEAD
        r = m_reader->read(buffer, sizeof(buffer), WebDataConsumerHandle::FlagNone,
            &size);
=======
        r = m_reader->read(buffer, sizeof(buffer), WebDataConsumerHandle::FlagNone, &size);
>>>>>>> miniblink49
        if (r == WebDataConsumerHandle::ShouldWait)
            return;
        if (r != WebDataConsumerHandle::Ok)
            break;
        m_data.append(buffer, size);
    }
<<<<<<< HEAD
    std::unique_ptr<HandleReadResult> result = WTF::makeUnique<HandleReadResult>(r, m_data);
    m_data.clear();
    Platform::current()->currentThread()->getWebTaskRunner()->postTask(
        BLINK_FROM_HERE,
        WTF::bind(&HandleReader::runOnFinishedReading, WTF::unretained(this),
            WTF::passed(std::move(result))));
    m_reader = nullptr;
}

void DataConsumerHandleTestUtil::HandleReader::runOnFinishedReading(
    std::unique_ptr<HandleReadResult> result)
{
    DCHECK(m_onFinishedReading);
    std::unique_ptr<OnFinishedReading> onFinishedReading(
        std::move(m_onFinishedReading));
    (*onFinishedReading)(std::move(result));
}

DataConsumerHandleTestUtil::HandleTwoPhaseReader::HandleTwoPhaseReader(
    std::unique_ptr<WebDataConsumerHandle> handle,
    std::unique_ptr<OnFinishedReading> onFinishedReading)
    : m_reader(handle->obtainReader(this))
    , m_onFinishedReading(std::move(onFinishedReading))
=======
    OwnPtr<HandleReadResult> result = adoptPtr(new HandleReadResult(r, m_data));
    m_data.clear();
    Platform::current()->currentThread()->postTask(FROM_HERE, new Task(bind(&HandleReader::runOnFinishedReading, this, result.release())));
    m_reader = nullptr;
}

void DataConsumerHandleTestUtil::HandleReader::runOnFinishedReading(PassOwnPtr<HandleReadResult> result)
{
    ASSERT(m_onFinishedReading);
    (*m_onFinishedReading.release())(result);
}

DataConsumerHandleTestUtil::HandleTwoPhaseReader::HandleTwoPhaseReader(PassOwnPtr<WebDataConsumerHandle> handle, PassOwnPtr<OnFinishedReading> onFinishedReading)
    : m_reader(handle->obtainReader(this))
    , m_onFinishedReading(onFinishedReading)
>>>>>>> miniblink49
{
}

void DataConsumerHandleTestUtil::HandleTwoPhaseReader::didGetReadable()
{
    WebDataConsumerHandle::Result r = WebDataConsumerHandle::UnexpectedError;
    while (true) {
        const void* buffer = nullptr;
        size_t size;
        r = m_reader->beginRead(&buffer, WebDataConsumerHandle::FlagNone, &size);
        if (r == WebDataConsumerHandle::ShouldWait)
            return;
        if (r != WebDataConsumerHandle::Ok)
            break;
        // Read smaller than available in order to test |endRead|.
        size_t readSize = std::min(size, std::max(size * 2 / 3, static_cast<size_t>(1)));
        m_data.append(static_cast<const char*>(buffer), readSize);
        m_reader->endRead(readSize);
    }
<<<<<<< HEAD
    std::unique_ptr<HandleReadResult> result = WTF::makeUnique<HandleReadResult>(r, m_data);
    m_data.clear();
    Platform::current()->currentThread()->getWebTaskRunner()->postTask(
        BLINK_FROM_HERE,
        WTF::bind(&HandleTwoPhaseReader::runOnFinishedReading,
            WTF::unretained(this), WTF::passed(std::move(result))));
    m_reader = nullptr;
}

void DataConsumerHandleTestUtil::HandleTwoPhaseReader::runOnFinishedReading(
    std::unique_ptr<HandleReadResult> result)
{
    DCHECK(m_onFinishedReading);
    std::unique_ptr<OnFinishedReading> onFinishedReading(
        std::move(m_onFinishedReading));
    (*onFinishedReading)(std::move(result));
}

std::unique_ptr<WebDataConsumerHandle>
DataConsumerHandleTestUtil::createWaitingDataConsumerHandle()
{
    return WTF::wrapUnique(new WaitingHandle);
=======
    OwnPtr<HandleReadResult> result = adoptPtr(new HandleReadResult(r, m_data));
    m_data.clear();
    Platform::current()->currentThread()->postTask(FROM_HERE, new Task(bind(&HandleTwoPhaseReader::runOnFinishedReading, this, result.release())));
    m_reader = nullptr;
}

void DataConsumerHandleTestUtil::HandleTwoPhaseReader::runOnFinishedReading(PassOwnPtr<HandleReadResult> result)
{
    ASSERT(m_onFinishedReading);
    (*m_onFinishedReading.release())(result);
>>>>>>> miniblink49
}

} // namespace blink
