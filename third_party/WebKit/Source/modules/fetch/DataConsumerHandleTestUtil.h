// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DataConsumerHandleTestUtil_h
#define DataConsumerHandleTestUtil_h

#include "bindings/core/v8/ScriptState.h"
#include "core/testing/NullExecutionContext.h"
#include "gin/public/isolate_holder.h"
<<<<<<< HEAD
#include "platform/CrossThreadFunctional.h"
#include "platform/WaitableEvent.h"
=======
#include "modules/fetch/DataConsumerHandleUtil.h"
#include "modules/fetch/FetchDataConsumerHandle.h"
#include "modules/fetch/FetchDataLoader.h"
#include "platform/Task.h"
#include "platform/ThreadSafeFunctional.h"
>>>>>>> miniblink49
#include "platform/WebThreadSupportingGC.h"
#include "platform/heap/Handle.h"
#include "public/platform/Platform.h"
#include "public/platform/WebDataConsumerHandle.h"
#include "public/platform/WebTraceLocation.h"
<<<<<<< HEAD
#include "wtf/Deque.h"
#include "wtf/Locker.h"
#include "wtf/PtrUtil.h"
#include "wtf/ThreadSafeRefCounted.h"
#include "wtf/ThreadingPrimitives.h"
#include "wtf/Vector.h"
#include "wtf/text/StringBuilder.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
=======
#include "public/platform/WebWaitableEvent.h"
#include "wtf/Deque.h"
#include "wtf/Locker.h"
#include "wtf/OwnPtr.h"
#include "wtf/PassOwnPtr.h"
#include "wtf/ThreadSafeRefCounted.h"
#include "wtf/ThreadingPrimitives.h"
#include "wtf/Vector.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
>>>>>>> miniblink49
#include <v8.h>

namespace blink {

class DataConsumerHandleTestUtil {
<<<<<<< HEAD
    STATIC_ONLY(DataConsumerHandleTestUtil);

public:
    class NoopClient final : public WebDataConsumerHandle::Client {
        DISALLOW_NEW();

=======
public:
    class NoopClient final : public WebDataConsumerHandle::Client {
>>>>>>> miniblink49
    public:
        void didGetReadable() override { }
    };

    // Thread has a WebThreadSupportingGC. It initializes / shutdowns
    // additional objects based on the given policy. The constructor and the
    // destructor blocks during the setup and the teardown.
    class Thread final {
<<<<<<< HEAD
        USING_FAST_MALLOC(Thread);

=======
>>>>>>> miniblink49
    public:
        // Initialization policy of a thread.
        enum InitializationPolicy {
            // Only garbage collection is supported.
            GarbageCollection,
            // Creating an isolate in addition to GarbageCollection.
            ScriptExecution,
            // Creating an execution context in addition to ScriptExecution.
            WithExecutionContext,
        };

        Thread(const char* name, InitializationPolicy = GarbageCollection);
        ~Thread();

        WebThreadSupportingGC* thread() { return m_thread.get(); }
<<<<<<< HEAD
        ExecutionContext* getExecutionContext() { return m_executionContext.get(); }
        ScriptState* getScriptState() { return m_scriptState.get(); }
=======
        ExecutionContext* executionContext() { return m_executionContext.get(); }
        ScriptState* scriptState() { return m_scriptState.get(); }
>>>>>>> miniblink49
        v8::Isolate* isolate() { return m_isolateHolder->isolate(); }

    private:
        void initialize();
        void shutdown();

<<<<<<< HEAD
        std::unique_ptr<WebThreadSupportingGC> m_thread;
        const InitializationPolicy m_initializationPolicy;
        std::unique_ptr<WaitableEvent> m_waitableEvent;
        Persistent<NullExecutionContext> m_executionContext;
        std::unique_ptr<gin::IsolateHolder> m_isolateHolder;
=======
        OwnPtr<WebThreadSupportingGC> m_thread;
        const InitializationPolicy m_initializationPolicy;
        OwnPtr<WebWaitableEvent> m_waitableEvent;
        RefPtrWillBePersistent<NullExecutionContext> m_executionContext;
        OwnPtr<gin::IsolateHolder> m_isolateHolder;
>>>>>>> miniblink49
        RefPtr<ScriptState> m_scriptState;
    };

    class ThreadingTestBase : public ThreadSafeRefCounted<ThreadingTestBase> {
    public:
<<<<<<< HEAD
        virtual ~ThreadingTestBase() { }

        class ThreadHolder;

=======
>>>>>>> miniblink49
        class Context : public ThreadSafeRefCounted<Context> {
        public:
            static PassRefPtr<Context> create() { return adoptRef(new Context); }
            void recordAttach(const String& handle)
            {
                MutexLocker locker(m_loggingMutex);
<<<<<<< HEAD
                m_result.append("A reader is attached to ");
                m_result.append(handle);
                m_result.append(" on ");
                m_result.append(currentThreadName());
                m_result.append(".\n");
=======
                m_result.append("A reader is attached to " + handle + " on " + currentThreadName() + ".\n");
>>>>>>> miniblink49
            }
            void recordDetach(const String& handle)
            {
                MutexLocker locker(m_loggingMutex);
<<<<<<< HEAD
                m_result.append("A reader is detached from ");
                m_result.append(handle);
                m_result.append(" on ");
                m_result.append(currentThreadName());
                m_result.append(".\n");
            }

            String result()
            {
                MutexLocker locker(m_loggingMutex);
                return m_result.toString();
            }

            void registerThreadHolder(ThreadHolder* holder)
            {
                MutexLocker locker(m_holderMutex);
                ASSERT(!m_holder);
                m_holder = holder;
            }
            void unregisterThreadHolder()
            {
                MutexLocker locker(m_holderMutex);
                ASSERT(m_holder);
                m_holder = nullptr;
            }
            void postTaskToReadingThread(const WebTraceLocation& location,
                std::unique_ptr<CrossThreadClosure> task)
            {
                MutexLocker locker(m_holderMutex);
                ASSERT(m_holder);
                m_holder->readingThread()->postTask(location, std::move(task));
            }
            void postTaskToUpdatingThread(const WebTraceLocation& location,
                std::unique_ptr<CrossThreadClosure> task)
            {
                MutexLocker locker(m_holderMutex);
                ASSERT(m_holder);
                m_holder->updatingThread()->postTask(location, std::move(task));
            }

        private:
            Context()
                : m_holder(nullptr)
=======
                m_result.append("A reader is detached from " + handle + " on " + currentThreadName() + ".\n");
            }

            const String& result()
            {
                MutexLocker locker(m_loggingMutex);
                return m_result;
            }
            WebThreadSupportingGC* readingThread() { return m_readingThread->thread(); }
            WebThreadSupportingGC* updatingThread() { return m_updatingThread->thread(); }

        private:
            Context()
                : m_readingThread(adoptPtr(new Thread("reading thread")))
                , m_updatingThread(adoptPtr(new Thread("updating thread")))
>>>>>>> miniblink49
            {
            }
            String currentThreadName()
            {
<<<<<<< HEAD
                MutexLocker locker(m_holderMutex);
                if (m_holder) {
                    if (m_holder->readingThread()->isCurrentThread())
                        return "the reading thread";
                    if (m_holder->updatingThread()->isCurrentThread())
                        return "the updating thread";
                }
                return "an unknown thread";
            }

            // Protects |m_result|.
            Mutex m_loggingMutex;
            StringBuilder m_result;

            // Protects |m_holder|.
            Mutex m_holderMutex;
            // Because Context outlives ThreadHolder, holding a raw pointer
            // here is safe.
            ThreadHolder* m_holder;
        };

        // The reading/updating threads are alive while ThreadHolder is alive.
        class ThreadHolder {
            DISALLOW_NEW();

        public:
            ThreadHolder(ThreadingTestBase* test)
                : m_context(test->m_context)
                , m_readingThread(WTF::wrapUnique(new Thread("reading thread")))
                , m_updatingThread(WTF::wrapUnique(new Thread("updating thread")))
            {
                m_context->registerThreadHolder(this);
            }
            ~ThreadHolder() { m_context->unregisterThreadHolder(); }

            WebThreadSupportingGC* readingThread()
            {
                return m_readingThread->thread();
            }
            WebThreadSupportingGC* updatingThread()
            {
                return m_updatingThread->thread();
            }

        private:
            RefPtr<Context> m_context;
            std::unique_ptr<Thread> m_readingThread;
            std::unique_ptr<Thread> m_updatingThread;
        };

        class ReaderImpl final : public WebDataConsumerHandle::Reader {
            USING_FAST_MALLOC(ReaderImpl);

        public:
            ReaderImpl(const String& name, PassRefPtr<Context> context)
                : m_name(name.isolatedCopy())
                , m_context(context)
=======
                if (m_readingThread->thread()->isCurrentThread())
                    return "the reading thread";
                if (m_updatingThread->thread()->isCurrentThread())
                    return "the updating thread";
                return "an unknown thread";
            }

            OwnPtr<Thread> m_readingThread;
            OwnPtr<Thread> m_updatingThread;
            Mutex m_loggingMutex;
            String m_result;
        };

        class ReaderImpl final : public WebDataConsumerHandle::Reader {
        public:
            ReaderImpl(const String& name, PassRefPtr<Context> context) : m_name(name.isolatedCopy()), m_context(context)
>>>>>>> miniblink49
            {
                m_context->recordAttach(m_name.isolatedCopy());
            }
            ~ReaderImpl() override { m_context->recordDetach(m_name.isolatedCopy()); }

            using Result = WebDataConsumerHandle::Result;
            using Flags = WebDataConsumerHandle::Flags;
<<<<<<< HEAD
            Result beginRead(const void**, Flags, size_t*) override
            {
                return WebDataConsumerHandle::ShouldWait;
            }
            Result endRead(size_t) override
            {
                return WebDataConsumerHandle::UnexpectedError;
            }
=======
            Result read(void*, size_t, Flags, size_t*) override { return WebDataConsumerHandle::ShouldWait; }
            Result beginRead(const void**, Flags, size_t*) override { return WebDataConsumerHandle::ShouldWait; }
            Result endRead(size_t) override { return WebDataConsumerHandle::UnexpectedError; }
>>>>>>> miniblink49

        private:
            const String m_name;
            RefPtr<Context> m_context;
        };
        class DataConsumerHandle final : public WebDataConsumerHandle {
<<<<<<< HEAD
            USING_FAST_MALLOC(DataConsumerHandle);

        public:
            static std::unique_ptr<WebDataConsumerHandle> create(
                const String& name,
                PassRefPtr<Context> context)
            {
                return WTF::wrapUnique(
                    new DataConsumerHandle(name, std::move(context)));
            }

        private:
            DataConsumerHandle(const String& name, PassRefPtr<Context> context)
                : m_name(name.isolatedCopy())
                , m_context(context)
            {
            }

            std::unique_ptr<Reader> obtainReader(Client*)
            {
                return WTF::makeUnique<ReaderImpl>(m_name, m_context);
            }
            const char* debugName() const override
            {
                return "ThreadingTestBase::DataConsumerHandle";
            }

=======
        public:
            DataConsumerHandle(const String& name, PassRefPtr<Context> context) : m_name(name.isolatedCopy()), m_context(context) { }

        private:
            Reader* obtainReaderInternal(Client*) { return new ReaderImpl(m_name, m_context); }
>>>>>>> miniblink49
            const String m_name;
            RefPtr<Context> m_context;
        };

        void resetReader() { m_reader = nullptr; }
        void signalDone() { m_waitableEvent->signal(); }
<<<<<<< HEAD
        String result() { return m_context->result(); }
        void postTaskToReadingThread(const WebTraceLocation& location,
            std::unique_ptr<CrossThreadClosure> task)
        {
            m_context->postTaskToReadingThread(location, std::move(task));
        }
        void postTaskToUpdatingThread(const WebTraceLocation& location,
            std::unique_ptr<CrossThreadClosure> task)
        {
            m_context->postTaskToUpdatingThread(location, std::move(task));
        }
        void postTaskToReadingThreadAndWait(
            const WebTraceLocation& location,
            std::unique_ptr<CrossThreadClosure> task)
        {
            postTaskToReadingThread(location, std::move(task));
            m_waitableEvent->wait();
        }
        void postTaskToUpdatingThreadAndWait(
            const WebTraceLocation& location,
            std::unique_ptr<CrossThreadClosure> task)
        {
            postTaskToUpdatingThread(location, std::move(task));
=======
        const String& result() { return m_context->result(); }
        WebThreadSupportingGC* readingThread() { return m_context->readingThread(); }
        WebThreadSupportingGC* updatingThread() { return m_context->updatingThread(); }
        void postTaskAndWait(WebThreadSupportingGC* thread, const WebTraceLocation& location, Task* task)
        {
            thread->postTask(location, task);
>>>>>>> miniblink49
            m_waitableEvent->wait();
        }

    protected:
<<<<<<< HEAD
        ThreadingTestBase()
            : m_context(Context::create())
        {
        }

        RefPtr<Context> m_context;
        std::unique_ptr<WebDataConsumerHandle::Reader> m_reader;
        std::unique_ptr<WaitableEvent> m_waitableEvent;
        NoopClient m_client;
    };

    class ThreadingHandleNotificationTest : public ThreadingTestBase,
                                            public WebDataConsumerHandle::Client {
    public:
        using Self = ThreadingHandleNotificationTest;
        static PassRefPtr<Self> create() { return adoptRef(new Self); }

        void run(std::unique_ptr<WebDataConsumerHandle> handle)
        {
            ThreadHolder holder(this);
            m_waitableEvent = WTF::makeUnique<WaitableEvent>();
            m_handle = std::move(handle);

            postTaskToReadingThreadAndWait(
                BLINK_FROM_HERE,
                crossThreadBind(&Self::obtainReader, wrapPassRefPtr(this)));
        }

    private:
        ThreadingHandleNotificationTest() = default;
        void obtainReader() { m_reader = m_handle->obtainReader(this); }
        void didGetReadable() override
        {
            postTaskToReadingThread(
                BLINK_FROM_HERE,
                crossThreadBind(&Self::resetReader, wrapPassRefPtr(this)));
            postTaskToReadingThread(
                BLINK_FROM_HERE,
                crossThreadBind(&Self::signalDone, wrapPassRefPtr(this)));
        }

        std::unique_ptr<WebDataConsumerHandle> m_handle;
    };

    class ThreadingHandleNoNotificationTest
        : public ThreadingTestBase,
          public WebDataConsumerHandle::Client {
    public:
        using Self = ThreadingHandleNoNotificationTest;
        static PassRefPtr<Self> create() { return adoptRef(new Self); }

        void run(std::unique_ptr<WebDataConsumerHandle> handle)
        {
            ThreadHolder holder(this);
            m_waitableEvent = WTF::makeUnique<WaitableEvent>();
            m_handle = std::move(handle);

            postTaskToReadingThreadAndWait(
                BLINK_FROM_HERE,
                crossThreadBind(&Self::obtainReader, wrapPassRefPtr(this)));
        }

    private:
        ThreadingHandleNoNotificationTest() = default;
=======
        RefPtr<Context> m_context;
        OwnPtr<WebDataConsumerHandle::Reader> m_reader;
        OwnPtr<WebWaitableEvent> m_waitableEvent;
        NoopClient m_client;
    };

    class ThreadingHandleNotificationTest : public ThreadingTestBase, public WebDataConsumerHandle::Client {
    public:
        using Self = ThreadingHandleNotificationTest;
        void run(PassOwnPtr<WebDataConsumerHandle> handle)
        {
            m_context = Context::create();
            m_waitableEvent = adoptPtr(Platform::current()->createWaitableEvent());
            m_handle = handle;

            postTaskAndWait(readingThread(), FROM_HERE, new Task(threadSafeBind(&Self::obtainReader, this)));
        }

    private:
        void obtainReader()
        {
            m_reader = m_handle->obtainReader(this);
        }
        void didGetReadable() override
        {
            readingThread()->postTask(FROM_HERE, new Task(threadSafeBind(&Self::resetReader, this)));
            readingThread()->postTask(FROM_HERE, new Task(threadSafeBind(&Self::signalDone, this)));
        }

        OwnPtr<WebDataConsumerHandle> m_handle;
    };

    class ThreadingHandleNoNotificationTest : public ThreadingTestBase, public WebDataConsumerHandle::Client {
    public:
        using Self = ThreadingHandleNoNotificationTest;
        void run(PassOwnPtr<WebDataConsumerHandle> handle)
        {
            m_context = Context::create();
            m_waitableEvent = adoptPtr(Platform::current()->createWaitableEvent());
            m_handle = handle;

            postTaskAndWait(readingThread(), FROM_HERE, new Task(threadSafeBind(&Self::obtainReader, this)));
        }

    private:
>>>>>>> miniblink49
        void obtainReader()
        {
            m_reader = m_handle->obtainReader(this);
            m_reader = nullptr;
<<<<<<< HEAD
            postTaskToReadingThread(
                BLINK_FROM_HERE,
                crossThreadBind(&Self::signalDone, wrapPassRefPtr(this)));
        }
        void didGetReadable() override { ASSERT_NOT_REACHED(); }

        std::unique_ptr<WebDataConsumerHandle> m_handle;
    };

    class Command final {
        DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

=======
            readingThread()->postTask(FROM_HERE, new Task(threadSafeBind(&Self::signalDone, this)));
        }
        void didGetReadable() override
        {
            ASSERT_NOT_REACHED();
        }

        OwnPtr<WebDataConsumerHandle> m_handle;
    };

    class MockFetchDataConsumerHandle : public FetchDataConsumerHandle {
    public:
        static PassOwnPtr<::testing::StrictMock<MockFetchDataConsumerHandle>> create() { return adoptPtr(new ::testing::StrictMock<MockFetchDataConsumerHandle>); }
        MOCK_METHOD1(obtainReaderInternal, Reader*(Client*));
    };

    class MockFetchDataConsumerReader : public FetchDataConsumerHandle::Reader {
    public:
        static PassOwnPtr<::testing::StrictMock<MockFetchDataConsumerReader>> create() { return adoptPtr(new ::testing::StrictMock<MockFetchDataConsumerReader>); }

        using Result = WebDataConsumerHandle::Result;
        using Flags = WebDataConsumerHandle::Flags;
        MOCK_METHOD4(read, Result(void*, size_t, Flags, size_t*));
        MOCK_METHOD3(beginRead, Result(const void**, Flags, size_t*));
        MOCK_METHOD1(endRead, Result(size_t));
        MOCK_METHOD1(drainAsBlobDataHandle, PassRefPtr<BlobDataHandle>(BlobSizePolicy));

        ~MockFetchDataConsumerReader() override
        {
            destruct();
        }
        MOCK_METHOD0(destruct, void());
    };

    class MockFetchDataLoaderClient : public GarbageCollectedFinalized<MockFetchDataLoaderClient>, public FetchDataLoader::Client {
        USING_GARBAGE_COLLECTED_MIXIN(MockFetchDataLoaderClient);
    public:
        static ::testing::StrictMock<MockFetchDataLoaderClient>* create() { return new ::testing::StrictMock<MockFetchDataLoaderClient>; }

        DEFINE_INLINE_VIRTUAL_TRACE()
        {
            FetchDataLoader::Client::trace(visitor);
        }

        MOCK_METHOD1(didFetchDataLoadedBlobHandleMock, void(RefPtr<BlobDataHandle>));
        MOCK_METHOD1(didFetchDataLoadedArrayBufferMock, void(RefPtr<DOMArrayBuffer>));
        MOCK_METHOD1(didFetchDataLoadedString, void(const String&));
        MOCK_METHOD0(didFetchDataLoadStream, void());
        MOCK_METHOD0(didFetchDataLoadFailed, void());

        // In mock methods we use RefPtr<> rather than PassRefPtr<>.
        void didFetchDataLoadedArrayBuffer(PassRefPtr<DOMArrayBuffer> arrayBuffer) override
        {
            didFetchDataLoadedArrayBufferMock(arrayBuffer);
        }
        void didFetchDataLoadedBlobHandle(PassRefPtr<BlobDataHandle> blobDataHandle) override
        {
            didFetchDataLoadedBlobHandleMock(blobDataHandle);
        }
    };

    class Command final {
>>>>>>> miniblink49
    public:
        enum Name {
            Data,
            Done,
            Error,
            Wait,
        };

<<<<<<< HEAD
        Command(Name name)
            : m_name(name)
        {
        }
        Command(Name name, const Vector<char>& body)
            : m_name(name)
            , m_body(body)
        {
        }
        Command(Name name, const char* body, size_t size)
            : m_name(name)
        {
            m_body.append(body, size);
        }
        Command(Name name, const char* body)
            : Command(name, body, strlen(body))
        {
        }
        Name getName() const { return m_name; }
=======
        Command(Name name) : m_name(name) { }
        Command(Name name, const Vector<char>& body) : m_name(name), m_body(body) { }
        Command(Name name, const char* body, size_t size) : m_name(name)
        {
            m_body.append(body, size);
        }
        Command(Name name, const char* body) : Command(name, body, strlen(body)) { }
        Name name() const { return m_name; }
>>>>>>> miniblink49
        const Vector<char>& body() const { return m_body; }

    private:
        const Name m_name;
        Vector<char> m_body;
    };

<<<<<<< HEAD
    // ReplayingHandle stores commands via |add| and replays the stored commends
    // when read.
    class ReplayingHandle final : public WebDataConsumerHandle {
        USING_FAST_MALLOC(ReplayingHandle);

    public:
        static std::unique_ptr<ReplayingHandle> create()
        {
            return WTF::wrapUnique(new ReplayingHandle());
        }
=======
    // ReplayingHandle stores commands via |add| and replays the stored commends when read.
    class ReplayingHandle final : public WebDataConsumerHandle {
    public:
        static PassOwnPtr<ReplayingHandle> create() { return adoptPtr(new ReplayingHandle()); }
>>>>>>> miniblink49
        ~ReplayingHandle();

        // Add a command to this handle. This function must be called on the
        // creator thread. This function must be called BEFORE any reader is
        // obtained.
        void add(const Command&);

        class Context final : public ThreadSafeRefCounted<Context> {
        public:
            static PassRefPtr<Context> create() { return adoptRef(new Context); }

            // This function cannot be called after creating a tee.
            void add(const Command&);
            void attachReader(WebDataConsumerHandle::Client*);
            void detachReader();
            void detachHandle();
            Result beginRead(const void** buffer, Flags, size_t* available);
            Result endRead(size_t readSize);
<<<<<<< HEAD
            WaitableEvent* detached() { return m_detached.get(); }
=======
            WebWaitableEvent* detached() { return m_detached.get(); }
>>>>>>> miniblink49

        private:
            Context();
            bool isEmpty() const { return m_commands.isEmpty(); }
            const Command& top();
            void consume(size_t);
            size_t offset() const { return m_offset; }
            void notify();
            void notifyInternal();

            Deque<Command> m_commands;
            size_t m_offset;
            WebThread* m_readerThread;
            Client* m_client;
            Result m_result;
            bool m_isHandleAttached;
            Mutex m_mutex;
<<<<<<< HEAD
            std::unique_ptr<WaitableEvent> m_detached;
        };

        Context* getContext() { return m_context.get(); }
        std::unique_ptr<Reader> obtainReader(Client*) override;
=======
            OwnPtr<WebWaitableEvent> m_detached;
        };

        Context* context() { return m_context.get(); }
>>>>>>> miniblink49

    private:
        class ReaderImpl;

        ReplayingHandle();
<<<<<<< HEAD
        const char* debugName() const override { return "ReplayingHandle"; }
=======
        Reader* obtainReaderInternal(Client*) override;
>>>>>>> miniblink49

        RefPtr<Context> m_context;
    };

    class HandleReadResult final {
<<<<<<< HEAD
        USING_FAST_MALLOC(HandleReadResult);

    public:
        HandleReadResult(WebDataConsumerHandle::Result result,
            const Vector<char>& data)
            : m_result(result)
            , m_data(data)
        {
        }
=======
    public:
        HandleReadResult(WebDataConsumerHandle::Result result, const Vector<char>& data) : m_result(result), m_data(data) { }
>>>>>>> miniblink49
        WebDataConsumerHandle::Result result() const { return m_result; }
        const Vector<char>& data() const { return m_data; }

    private:
        const WebDataConsumerHandle::Result m_result;
        const Vector<char> m_data;
    };

    // HandleReader reads all data from the given WebDataConsumerHandle using
    // Reader::read on the thread on which it is created. When reading is done
    // or failed, it calls the given callback with the result.
    class HandleReader final : public WebDataConsumerHandle::Client {
<<<<<<< HEAD
        USING_FAST_MALLOC(HandleReader);

    public:
        using OnFinishedReading = WTF::Function<void(std::unique_ptr<HandleReadResult>)>;

        HandleReader(std::unique_ptr<WebDataConsumerHandle>,
            std::unique_ptr<OnFinishedReading>);
        void didGetReadable() override;

    private:
        void runOnFinishedReading(std::unique_ptr<HandleReadResult>);

        std::unique_ptr<WebDataConsumerHandle::Reader> m_reader;
        std::unique_ptr<OnFinishedReading> m_onFinishedReading;
=======
    public:
        using OnFinishedReading = WTF::Function<void(PassOwnPtr<HandleReadResult>)>;

        HandleReader(PassOwnPtr<WebDataConsumerHandle>, PassOwnPtr<OnFinishedReading>);
        void didGetReadable() override;

    private:
        void runOnFinishedReading(PassOwnPtr<HandleReadResult>);

        OwnPtr<WebDataConsumerHandle::Reader> m_reader;
        OwnPtr<OnFinishedReading> m_onFinishedReading;
>>>>>>> miniblink49
        Vector<char> m_data;
    };

    // HandleTwoPhaseReader does the same as HandleReader, but it uses
    // |beginRead| / |endRead| instead of |read|.
    class HandleTwoPhaseReader final : public WebDataConsumerHandle::Client {
<<<<<<< HEAD
        USING_FAST_MALLOC(HandleTwoPhaseReader);

    public:
        using OnFinishedReading = WTF::Function<void(std::unique_ptr<HandleReadResult>)>;

        HandleTwoPhaseReader(std::unique_ptr<WebDataConsumerHandle>,
            std::unique_ptr<OnFinishedReading>);
        void didGetReadable() override;

    private:
        void runOnFinishedReading(std::unique_ptr<HandleReadResult>);

        std::unique_ptr<WebDataConsumerHandle::Reader> m_reader;
        std::unique_ptr<OnFinishedReading> m_onFinishedReading;
=======
    public:
        using OnFinishedReading = WTF::Function<void(PassOwnPtr<HandleReadResult>)>;

        HandleTwoPhaseReader(PassOwnPtr<WebDataConsumerHandle>, PassOwnPtr<OnFinishedReading>);
        void didGetReadable() override;

    private:
        void runOnFinishedReading(PassOwnPtr<HandleReadResult>);

        OwnPtr<WebDataConsumerHandle::Reader> m_reader;
        OwnPtr<OnFinishedReading> m_onFinishedReading;
>>>>>>> miniblink49
        Vector<char> m_data;
    };

    // HandleReaderRunner<T> creates a dedicated thread and run T on the thread
    // where T is one of HandleReader and HandleTwophaseReader.
    template <typename T>
    class HandleReaderRunner final {
<<<<<<< HEAD
        STACK_ALLOCATED();

    public:
        explicit HandleReaderRunner(std::unique_ptr<WebDataConsumerHandle> handle)
            : m_thread(WTF::wrapUnique(new Thread("reading thread")))
            , m_event(WTF::makeUnique<WaitableEvent>())
            , m_isDone(false)
        {
            m_thread->thread()->postTask(
                BLINK_FROM_HERE, crossThreadBind(&HandleReaderRunner::start, crossThreadUnretained(this), WTF::passed(std::move(handle))));
        }
        ~HandleReaderRunner() { wait(); }

        std::unique_ptr<HandleReadResult> wait()
=======
    public:
        explicit HandleReaderRunner(PassOwnPtr<WebDataConsumerHandle> handle)
            : m_thread(adoptPtr(new Thread("reading thread")))
            , m_event(adoptPtr(Platform::current()->createWaitableEvent()))
            , m_isDone(false)
        {
            m_thread->thread()->postTask(FROM_HERE, new Task(threadSafeBind(&HandleReaderRunner::start, AllowCrossThreadAccess(this), handle)));
        }
        ~HandleReaderRunner()
        {
            wait();
        }

        PassOwnPtr<HandleReadResult> wait()
>>>>>>> miniblink49
        {
            if (m_isDone)
                return nullptr;
            m_event->wait();
            m_isDone = true;
<<<<<<< HEAD
            return std::move(m_result);
        }

    private:
        void start(std::unique_ptr<WebDataConsumerHandle> handle)
        {
            m_handleReader = WTF::wrapUnique(new T(
                std::move(handle),
                WTF::bind(&HandleReaderRunner::onFinished, WTF::unretained(this))));
        }

        void onFinished(std::unique_ptr<HandleReadResult> result)
        {
            m_handleReader = nullptr;
            m_result = std::move(result);
            m_event->signal();
        }

        std::unique_ptr<Thread> m_thread;
        std::unique_ptr<WaitableEvent> m_event;
        std::unique_ptr<HandleReadResult> m_result;
        bool m_isDone;

        std::unique_ptr<T> m_handleReader;
    };

    static std::unique_ptr<WebDataConsumerHandle>
    createWaitingDataConsumerHandle();
=======
            return m_result.release();
        }

    private:
        void start(PassOwnPtr<WebDataConsumerHandle> handle)
        {
            m_handleReader = adoptPtr(new T(handle, bind<PassOwnPtr<HandleReadResult>>(&HandleReaderRunner::onFinished, this)));
        }

        void onFinished(PassOwnPtr<HandleReadResult> result)
        {
            m_handleReader = nullptr;
            m_result = result;
            m_event->signal();
        }

        OwnPtr<Thread> m_thread;
        OwnPtr<WebWaitableEvent> m_event;
        OwnPtr<HandleReadResult> m_result;
        bool m_isDone;

        OwnPtr<T> m_handleReader;
    };
>>>>>>> miniblink49
};

} // namespace blink

#endif // DataConsumerHandleTestUtil_h
