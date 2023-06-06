
#include "content/OrigChromeMgr.h"
#include "content/media/audio_renderer_mixer_manager.h"
#include "base/at_exit.h"
#include "base/bind.h"
#include "base/command_line.h"
#include "base/message_loop/message_loop.h"
#include "cc/blink/web_compositor_support_impl.h"
//#include "cc/blink/web_external_bitmap_impl.h"
#include "content/RasterWorkerPool.h"
#include "content/WebSharedBitmapManager.h"
#include "content/gpu/ChildGpuMemoryBufferManager.h"
#include "content/media/audio_renderer_mixer_manager.h"
// #include "gpu/blink/webgraphicscontext3d_in_process_command_buffer_impl.h"
#include "media/audio/audio_manager.h"
#include "media/audio/audio_manager_base.h"
#include "media/audio/fake_audio_log_factory.h"
#include "media/audio/audio_device_description.h"
#include "media/base/media_log.h"
#include "media/base/media_permission.h"
#include "media/blink/webmediaplayer_impl.h"
#include "media/blink/webmediaplayer_params.h"
#include "media/renderers/default_renderer_factory.h"

#include "third_party/WebKit/public/platform/WebContentDecryptionModule.h"
#include "third_party/WebKit/public/web/WebLocalFrame.h"
//#include "third_party/WebKit/public/web/WebSecurityOrigin.h"
#include "third_party/WebKit/public/platform/WebMediaPlayerSource.h"
#include "ui/gl/gl_surface.h"
#include <shlwapi.h>
#include "base/atomic_mb.h"

namespace content {

OrigChromeMgr* OrigChromeMgr::m_inst = nullptr;

base::AtExitManager* g_exitManager = nullptr;

OrigChromeMgr::OrigChromeMgr()
{
    m_uiLoop = nullptr;
    m_blinkLoop = nullptr;
    m_rasterWorkerPool = nullptr;
    m_mediaThread = nullptr;
    m_mediaIoThread = nullptr;
    m_compositorThread = nullptr;
    m_sharedBitmapManager = nullptr;
    m_childGpuMemoryBufferManager = nullptr;
    m_audioRendererMixerManager = nullptr;
    m_hFfmpeg = nullptr;
    m_glImplType = kGLImplTypeNone;
    m_webglReady = false;
}

void OrigChromeMgr::init()
{
    if (m_inst)
        return;

    g_exitManager = new base::AtExitManager();
    m_inst = new OrigChromeMgr();

    base::CommandLine::Init(0, nullptr);
}

void OrigChromeMgr::setGLImplType(GLImplType type)
{
    m_glImplType = type;
}

OrigChromeMgr* OrigChromeMgr::getInst()
{
    return m_inst;
}

void OrigChromeMgr::shutdown()
{
    delete g_exitManager;
}

void OrigChromeMgr::runUntilIdleWithoutMsgPeek()
{
    if (!m_inst)
        return;
    base::MessageLoop::current()->RunUntilIdleWithoutMsgPeek();
}

void OrigChromeMgr::runUntilIdle()
{
    if (!m_inst)
        return;
    base::MessageLoop::current()->RunUntilIdle();
}

static long s_blinkThreadRunnerCount = 0;
static long s_uiThreadRunnerCount = 0;

static void blinkRunner(OrigTaskType task)
{
    MB_InterlockedDecrement((long*)&s_blinkThreadRunnerCount);
    task();
}

static void uiRunner(OrigTaskType task)
{
    MB_InterlockedDecrement((long*)&s_uiThreadRunnerCount);
    task();
}

void OrigChromeMgr::postBlinkTask(OrigTaskType task)
{
    if (!m_inst || s_blinkThreadRunnerCount > 0)
        return;

    MB_InterlockedIncrement((long*)&s_blinkThreadRunnerCount);
    m_inst->m_blinkLoop->PostTask(FROM_HERE, base::Bind(&blinkRunner, task));
}

void OrigChromeMgr::postUiTask(OrigTaskType task)
{
    if (!m_inst || s_uiThreadRunnerCount > 0)
        return;
    MB_InterlockedIncrement((long*)&s_uiThreadRunnerCount);
    m_inst->m_uiLoop->PostTask(FROM_HERE, base::Bind(&uiRunner, task));
}

static void webRunner(blink::WebThread::Task* task)
{
    task->run();
    delete task;
}

void OrigChromeMgr::postWebTask(const blink::WebTraceLocation& from, blink::WebThread::Task* task)
{
    base::MessageLoop* messageLoop = m_inst->m_blinkLoop;
    tracked_objects::Location location(from.function_name(), from.file_name(), -1, nullptr);

    messageLoop->PostTask(location, base::Bind(&webRunner, task));
}

void OrigChromeMgr::postWebDelayedTask(const blink::WebTraceLocation& from, blink::WebThread::Task* task, long long delayMs)
{
    base::MessageLoop* messageLoop = m_inst->m_blinkLoop;
    tracked_objects::Location location(from.function_name(), from.file_name(), -1, nullptr);

    messageLoop->PostDelayedTask(location, base::Bind(&webRunner, task), base::TimeDelta::FromMilliseconds(delayMs));
}

class TaskObserverAdapter : public base::MessageLoop::TaskObserver {
public:
    TaskObserverAdapter(blink::WebThread::TaskObserver* observer)
        : m_observer(observer)
    {
    }

    void WillProcessTask(const base::PendingTask& pending_task) override
    {
        m_observer->willProcessTask();
    }

    void DidProcessTask(const base::PendingTask& pending_task) override
    {
        m_observer->didProcessTask();
    }

private:
    blink::WebThread::TaskObserver* m_observer;
};

void OrigChromeMgr::addTaskObserver(blink::WebThread::TaskObserver* observer)
{
    if (!m_inst->m_blinkLoop) {
        m_inst->m_blinkLoop = new base::MessageLoop(base::MessageLoop::TYPE_IO);
//         const char* kThreadName = "MbBlinkThread";
//         m_inst->m_blinkLoop->set_thread_name(kThreadName);
    }
    base::MessageLoop* messageLoop = m_inst->m_blinkLoop;

    std::pair<TaskObserverMap::iterator, bool> result = m_inst->m_taskObserverMap.insert(std::make_pair(observer, nullptr));
    if (result.second)
        result.first->second = new TaskObserverAdapter(observer);

    messageLoop->AddTaskObserver(result.first->second);
}

void OrigChromeMgr::removeTaskObserver(blink::WebThread::TaskObserver* observer)
{
    base::MessageLoop* messageLoop = m_inst->m_blinkLoop;
    TaskObserverMap::iterator iter = m_inst->m_taskObserverMap.find(observer);
    if (iter == m_inst->m_taskObserverMap.end())
        return;
    messageLoop->RemoveTaskObserver(iter->second);
    delete iter->second;
    m_inst->m_taskObserverMap.erase(iter);
}

void OrigChromeMgr::onCreateWebview()
{
    ;
}

cc::TaskGraphRunner* OrigChromeMgr::getTaskGraphRunner()
{
    return m_rasterWorkerPool->GetTaskGraphRunner();
}

void OrigChromeMgr::initUiThread()
{
    m_uiLoop = new base::MessageLoop(base::MessageLoop::TYPE_UI);

//     const char* kThreadName = "MbUiThread";
//     m_uiLoop->set_thread_name(kThreadName);
}

static std::unique_ptr<cc::SharedBitmap> SharedBitmapAllocation(const gfx::Size& size)
{
    return std::move(OrigChromeMgr::getInst()->getSharedBitmapManager()->AllocateSharedBitmap(size));
}

void OrigChromeMgr::initBlinkThread()
{
    m_rasterWorkerPool = new RasterWorkerPool();
    m_rasterWorkerPool->Start(1, base::SimpleThread::Options());

//     if (kGLImplTypeEGLGLES2 == m_glImplType) {
//         if (!gfx::GLSurface::InitializeForce(gfx::kGLImplementationEGLGLES2)) {
//             OutputDebugStringA("gfx::GLSurface::Initialize EGLGLES2 failed\n");
//             m_glImplType = kGLImplTypeNone;
//         } else
//             m_webglReady = true;
//     } else if (kGLImplTypeEgles2Swiftshader == m_glImplType || kGLImplTypeNone == m_glImplType) {
//         if (!gfx::GLSurface::InitializeForce(gfx::kGLImplementationEGLGLES2SwiftShader)) {
//             OutputDebugStringA("gfx::GLSurface::Initialize SwiftShader failed\n");
//             m_glImplType = kGLImplTypeNone;
//         } else
//             m_webglReady = true;
//     }

    m_sharedBitmapManager = new WebSharedBitmapManager();
    m_childGpuMemoryBufferManager = nullptr;

//     if (m_webglReady)
//         cc_blink::SetSharedBitmapAllocationFunction(&SharedBitmapAllocation);

    if (kGLImplTypeEGLGLES2 == m_glImplType || kGLImplTypeEgles2Swiftshader == m_glImplType) {
        //m_childGpuMemoryBufferManager = new ChildGpuMemoryBufferManager();
        DebugBreak();
    }
}

base::Thread* OrigChromeMgr::getOrCreateCompositorThread()
{
    if (!m_compositorThread) {
        m_compositorThread = (new base::Thread("CompositorThread"));
        m_compositorThread->Start();
    }
    return m_compositorThread;
}

void OrigChromeMgr::createMediaThreadIfNeeded()
{
#if defined(OS_WIN)
    //DCHECK(message_loop() == base::MessageLoop::current());
    if (m_mediaThread)
        return;

    std::vector<WCHAR> fullpath;
    fullpath.resize(MAX_PATH + 1);
    memset(fullpath.data(), 0, sizeof(wchar_t) * (MAX_PATH + 1));
    ::GetModuleFileNameW(NULL, fullpath.data(), MAX_PATH);
    ::PathRemoveFileSpecW(fullpath.data());

    std::wstring name = fullpath.data();
    name += L"\\plugins\\ffmpeg\\ffmpeg.dll";
    m_hFfmpeg = LoadLibraryW(name.c_str());
    if (!m_hFfmpeg)
        return;

    m_mediaThread = (new base::Thread("MediaThread"));
    m_mediaThread->Start();

    m_mediaIoThread = (new base::Thread("MediaIoThread"));
    m_mediaIoThread->Start();

    m_audioManager = media::AudioManager::Create(m_mediaIoThread->task_runner(), m_mediaThread->task_runner(), new media::FakeAudioLogFactory());

    media::AudioParameters outputParams = m_audioManager->GetDefaultOutputStreamParameters();
    media::AudioParameters inputParams = m_audioManager->GetInputStreamParameters(media::AudioDeviceDescription::kDefaultDeviceId);
    //m_audioHardwareConfig = new media::AudioHardwareConfig(inputParams, outputParams);
#endif
}

blink::WebCompositorSupport* OrigChromeMgr::createWebCompositorSupport()
{
    return new cc_blink::WebCompositorSupportImpl();
}

// class MediaPermissionDispatcherImpl : public media::MediaPermission {
// public:
//     explicit MediaPermissionDispatcherImpl() { }
//     ~MediaPermissionDispatcherImpl() override { }
// 
//     // media::MediaPermission implementation.
//     void HasPermission(media::MediaPermission::Type type, const blink::WebURL& security_origin, const media::MediaPermission::PermissionStatusCB& permission_status_cb) override
//     {
//     }
// 
//     // MediaStreamDevicePermissionContext doesn't support RequestPermission yet
//     // and will always return CONTENT_SETTING_BLOCK.
//     void RequestPermission(media::MediaPermission::Type type, const blink::WebURL& security_origin, const media::MediaPermission::PermissionStatusCB& permission_status_cb) override
//     {
//     }
// };

MediaPermissionDispatcherImpl* OrigChromeMgr::getMediaPermission()
{
//     if (!m_mediaPermissionDispatcherImpl)
//         m_mediaPermissionDispatcherImpl = new MediaPermissionDispatcherImpl();
//     return m_mediaPermissionDispatcherImpl;
    DebugBreak();
    return nullptr;
}

int64_t adjustAmountOfExternalAllocatedMemory(int64_t)
{
    return 0;
}

AudioRendererMixerManager* OrigChromeMgr::getAudioRendererMixerManager()
{
#if defined(OS_WIN)
    if (!m_audioRendererMixerManager)
        m_audioRendererMixerManager = (new AudioRendererMixerManager());
    return m_audioRendererMixerManager;
#endif
    return nullptr;
}

static media::GpuVideoAcceleratorFactories* getGpuFactoriesCb()
{
    DebugBreak();
    return nullptr;
}

class EmptyAudioRendererSink
    : public media::SwitchableAudioRendererSink {
public:
    void Initialize(const media::AudioParameters& params, media::AudioRendererSink::RenderCallback* callback) override
    {
        DebugBreak();
    }

    void Start() override
    {
        DebugBreak();
    }
    void Stop() override
    {

    }
    void Pause() override
    {
        DebugBreak();
    }
    void Play() override
    {
        DebugBreak();
    }
    bool SetVolume(double volume) override
    {
        DebugBreak();
        return false;
    }

    media::AudioParameters DummyParams()
    {
        return media::AudioParameters(
            media::AudioParameters::AUDIO_FAKE, media::CHANNEL_LAYOUT_STEREO,
            media::AudioParameters::kAudioCDSampleRate, 16,
            media::AudioParameters::kAudioCDSampleRate / 10);
    }

    media::OutputDeviceInfo GetOutputDeviceInfo() override
    {
        return media::OutputDeviceInfo();
    }

    bool CurrentThreadIsRenderingThread() override
    {
        DebugBreak();
        return false;
    }

    void SwitchOutputDevice(const std::string& device_id,
        const url::Origin& security_origin,
        const media::OutputDeviceStatusCB& callback) override
    {
        DebugBreak();
    }

protected:
    ~EmptyAudioRendererSink() override
    {
    }
};

blink::WebMediaPlayer* OrigChromeMgr::createWebMediaPlayer(
    //blink::WebLocalFrame* frame, const blink::WebURL& url, blink::WebMediaPlayerClient* client
    blink::WebLocalFrame* frame,
    const blink::WebMediaPlayerSource& source,
    blink::WebMediaPlayerClient* client,
    blink::WebMediaPlayerEncryptedMediaClient*,
    blink::WebContentDecryptionModule*,
    const blink::WebString& sinkId,
    linked_ptr<media::UrlIndex> urlIndex
    )
{
#if defined(OS_WIN)
    if (!m_inst)
        return nullptr;
    AudioRendererMixerManager* audioRendererMixerManager = m_inst->getAudioRendererMixerManager();
    std::string origin = "";// frame->securityOrigin().toString().utf8();
    media::SwitchableAudioRendererSink* sink = reinterpret_cast<media::SwitchableAudioRendererSink*>(audioRendererMixerManager->CreateInput(0, "", origin));

    //     scoped_refptr<media::SwitchableAudioRendererSink> audio_renderer_sink =
//         AudioDeviceFactory::NewSwitchableAudioRendererSink(
//             AudioDeviceFactory::kSourceMediaElement, routing_id_, 0,
//             sink_id.utf8(), frame_->getSecurityOrigin());

    scoped_refptr<media::SwitchableAudioRendererSink> audio_renderer_sink(/*new EmptyAudioRendererSink()*/sink);

    media::WebMediaPlayerParams::Context3DCB context_3d_cb;

    m_inst->createMediaThreadIfNeeded();
    if (!m_inst->m_hFfmpeg)
        return nullptr;

    scoped_refptr<base::SingleThreadTaskRunner> mediaThreadTaskRunner = m_inst->m_mediaThread->task_runner();
    scoped_refptr<base::SingleThreadTaskRunner> compositorTaskRunner = m_inst->m_uiLoop->task_runner();

    blink::WebContentDecryptionModule* initialCdm = nullptr;
    scoped_refptr<media::MediaLog> media_log(new media::MediaLog());

    m_inst->m_rasterWorkerPool->AddRef(); // WebMediaPlayerImpl::~WebMediaPlayerImpl will release

    media::WebMediaPlayerParams params(
        media::WebMediaPlayerParams::DeferLoadCB(),
        audio_renderer_sink, 
        media_log, 
        mediaThreadTaskRunner,
        m_inst->m_rasterWorkerPool,
        compositorTaskRunner, 
        context_3d_cb,
        base::Bind(&adjustAmountOfExternalAllocatedMemory), // base::Bind(&v8::Isolate::AdjustAmountOfExternalAllocatedMemory, base::Unretained(blink::mainThreadIsolate())),
        initialCdm, 
        /*surface_manager*/nullptr, 
        nullptr/*base::WeakPtr<MediaObserver>*/
    );

    media::DefaultRendererFactory::GetGpuFactoriesCB getGpuFactoriesCB = base::Bind(getGpuFactoriesCb);
    getGpuFactoriesCB.Reset();

    std::unique_ptr<media::RendererFactory> media_renderer_factory;
    media_renderer_factory.reset(new media::DefaultRendererFactory(
        media_log, /*render_thread->GetGpuFactories()*/ nullptr, getGpuFactoriesCB));

    return new media::WebMediaPlayerImpl(
        frame, 
        client, 
        nullptr, 
        base::WeakPtr<media::WebMediaPlayerDelegate>(), 
        std::move(media_renderer_factory), 
        urlIndex, 
        params        
    );
#endif
    return nullptr;
}

// blink::WebGraphicsContext3D* OrigChromeMgr::createOffscreenGraphicsContext3D(
//     const blink::WebGraphicsContext3D::Attributes& attr,
//     blink::WebGraphicsContext3D* shareCxt,
//     blink::WebGLInfo* glInfo)
// {
//     if (!m_inst->m_webglReady)
//         return nullptr;
// 
//     bool loseContextWhenOutOfMemory = false;
//     scoped_ptr<gpu_blink::WebGraphicsContext3DInProcessCommandBufferImpl> commandBuffer;
//     commandBuffer = gpu_blink::WebGraphicsContext3DInProcessCommandBufferImpl::CreateOffscreenContext(attr, loseContextWhenOutOfMemory);
//     commandBuffer->InitializeOnCurrentThread();
// 
//     return commandBuffer.release();
// }

}