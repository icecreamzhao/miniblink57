#include "browser/api/ApiWebContents.h"

#include "browser/api/WindowInterface.h"
#include "browser/api/WindowList.h"
#include "browser/api/ApiSession.h"
#include "common/ThreadCall.h"
#include "common/NodeRegisterHelp.h"
#include "common/IdLiveDetect.h"
#include "common/NodeBinding.h"
#include "common/api/EventEmitterCaller.h"
#include "common/StringUtil.h"
#include "common/WorldIDs.h"
#include "common/mbexport.h"
#include "gin/dictionary.h"
#include "gin/object_template_builder.h"
#include "base/values.h"
#include "node/src/node.h"
#include "node/src/env.h"
#include "node/src/env-inl.h"
#include "node/uv/include/uv.h"

namespace atom {

void WebContents::init(v8::Isolate* isolate, v8::Local<v8::Object> target, node::Environment* env)
{
    v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, WebContents::newFunction);

    prototype->SetClassName(v8::String::NewFromUtf8(isolate, "WebContents"));
    gin::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
    builder.SetMethod("getId", &WebContents::getIdApi);
    builder.SetMethod("getProcessId", &WebContents::getProcessIdApi);
    builder.SetMethod("equal", &WebContents::equalApi);
    builder.SetMethod("_loadURL", &WebContents::_loadURLApi);
    builder.SetMethod("loadURL", &WebContents::_loadURLApi);
    builder.SetMethod("downloadURL", &WebContents::nullFunction);
    builder.SetMethod("_getURL", &WebContents::_getURLApi);
    builder.SetMethod("getTitle", &WebContents::getTitleApi);
    builder.SetMethod("isLoading", &WebContents::isLoadingApi);
    builder.SetMethod("isLoadingMainFrame", &WebContents::isLoadingMainFrameApi);
    builder.SetMethod("isWaitingForResponse", &WebContents::isWaitingForResponseApi);
    builder.SetMethod("stop", &WebContents::stopApi);
    builder.SetMethod("goBack", &WebContents::goBackApi);
    builder.SetMethod("goForward", &WebContents::goForwardApi);
    builder.SetMethod("goToOffset", &WebContents::goToOffsetApi);
    builder.SetMethod("goToIndex", &WebContents::goToIndexApi);
    builder.SetMethod("isCrashed", &WebContents::isCrashedApi);
    builder.SetMethod("setUserAgent", &WebContents::setUserAgentApi);
    builder.SetMethod("getUserAgent", &WebContents::getUserAgentApi);
    builder.SetMethod("insertCSS", &WebContents::insertCSSApi);
    builder.SetMethod("savePage", &WebContents::savePageApi);
    builder.SetMethod("openDevTools", &WebContents::openDevToolsApi);
    builder.SetMethod("closeDevTools", &WebContents::closeDevToolsApi);
    builder.SetMethod("isDevToolsOpened", &WebContents::isDevToolsOpenedApi);
    builder.SetMethod("isDevToolsFocused", &WebContents::isDevToolsFocusedApi);
    builder.SetMethod("enableDeviceEmulation", &WebContents::enableDeviceEmulationApi);
    builder.SetMethod("disableDeviceEmulation", &WebContents::disableDeviceEmulationApi);
    builder.SetMethod("toggleDevTools", &WebContents::toggleDevToolsApi);
    builder.SetMethod("inspectElement", &WebContents::inspectElementApi);
    builder.SetMethod("setAudioMuted", &WebContents::setAudioMutedApi);
    builder.SetMethod("isAudioMuted", &WebContents::isAudioMutedApi);
    builder.SetMethod("undo", &WebContents::undoApi);
    builder.SetMethod("redo", &WebContents::redoApi);
    builder.SetMethod("cut", &WebContents::cutApi);
    builder.SetMethod("copy", &WebContents::copyApi);
    builder.SetMethod("paste", &WebContents::pasteApi);
    builder.SetMethod("pasteAndMatchStyle", &WebContents::pasteAndMatchStyleApi);
    builder.SetMethod("delete", &WebContents::_deleteApi);
    builder.SetMethod("selectAll", &WebContents::selectAllApi);
    builder.SetMethod("unselect", &WebContents::unselectApi);
    builder.SetMethod("replace", &WebContents::replaceApi);
    builder.SetMethod("replaceMisspelling", &WebContents::replaceMisspellingApi);
    builder.SetMethod("findInPage", &WebContents::findInPageApi);
    builder.SetMethod("stopFindInPage", &WebContents::stopFindInPageApi);
    builder.SetMethod("focus", &WebContents::focusApi);
    builder.SetMethod("isFocused", &WebContents::isFocusedApi);
    builder.SetMethod("tabTraverse", &WebContents::tabTraverseApi);
    builder.SetMethod("_send", &WebContents::_sendApi);
    builder.SetMethod("sendInputEvent", &WebContents::sendInputEventApi);
    builder.SetMethod("beginFrameSubscription", &WebContents::beginFrameSubscriptionApi);
    builder.SetMethod("endFrameSubscription", &WebContents::endFrameSubscriptionApi);
    builder.SetMethod("startDrag", &WebContents::startDragApi);
    builder.SetMethod("setSize", &WebContents::setSizeApi);
    builder.SetMethod("isGuest", &WebContents::isGuestApi);
    builder.SetMethod("isOffscreen", &WebContents::isOffscreenApi);
    builder.SetMethod("startPainting", &WebContents::startPaintingApi);
    builder.SetMethod("stopPainting", &WebContents::stopPaintingApi);
    builder.SetMethod("isPainting", &WebContents::isPaintingApi);
    builder.SetMethod("setFrameRate", &WebContents::setFrameRateApi);
    builder.SetMethod("getFrameRate", &WebContents::getFrameRateApi);
    builder.SetMethod("invalidate", &WebContents::invalidateApi);
    builder.SetMethod("getType", &WebContents::getTypeApi);
    builder.SetMethod("getWebPreferences", &WebContents::getWebPreferencesApi);
    builder.SetMethod("getOwnerBrowserWindow", &WebContents::getOwnerBrowserWindowApi);
    builder.SetMethod("hasServiceWorker", &WebContents::hasServiceWorkerApi);
    builder.SetMethod("unregisterServiceWorker", &WebContents::unregisterServiceWorkerApi);
    builder.SetMethod("inspectServiceWorker", &WebContents::inspectServiceWorkerApi);
    builder.SetMethod("print", &WebContents::printApi);
    builder.SetMethod("_printToPDF", &WebContents::_printToPDFApi);
    builder.SetMethod("addWorkSpace", &WebContents::addWorkSpaceApi);
    builder.SetMethod("reNullWorkSpace", &WebContents::reNullWorkSpaceApi);
    builder.SetMethod("showDefinitionForSelection", &WebContents::showDefinitionForSelectionApi);
    builder.SetMethod("copyImageAt", &WebContents::copyImageAtApi);
    builder.SetMethod("capturePage", &WebContents::capturePageApi);
    builder.SetMethod("setEmbedder", &WebContents::setEmbedderApi);
    builder.SetMethod("isDestroyed", &WebContents::isDestroyedApi);
    builder.SetMethod("reloadIgnoringCache", &WebContents::reloadIgnoringCacheApi);
    builder.SetProperty("id", &WebContents::getIdApi);
    builder.SetProperty("session", &WebContents::getSessionApi);

    gin::Dictionary webContentsClass(isolate, prototype->GetFunction());
    webContentsClass.SetMethod("getFocusedWebContents", &WebContents::getFocusedWebContentsApi);
    webContentsClass.SetMethod("getAllWebContents", &WebContents::getAllWebContentsApi);
    webContentsClass.SetMethod("fromId", &WebContents::fromIdApi);

    constructor.Reset(isolate, prototype->GetFunction());
    target->Set(v8::String::NewFromUtf8(isolate, "WebContents"), prototype->GetFunction());
}

WebContents* WebContents::create(v8::Isolate* isolate, gin::Dictionary options, WindowInterface* owner)
{
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = { gin::ConvertToV8(isolate, options) };
    v8::Local<v8::Function> constructorFunction = v8::Local<v8::Function>::New(isolate, constructor);

    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::MaybeLocal<v8::Object> obj = constructorFunction->NewInstance(context, argc, argv); // call into WebContents::WebContents
    if (obj.IsEmpty())
        return nullptr;

    v8::Local<v8::Object> objV8 = obj.ToLocalChecked();

    WebContents* self = (WebContents*)WrappableBase::GetNativePtr(objV8, &kWrapperInfo);
    self->m_liveSelf.Reset(isolate, objV8);
    self->m_owner = owner;
    return self;
}

WebContents::WebContents(v8::Isolate* isolate, v8::Local<v8::Object> wrapper, const gin::Dictionary& options)
{
    m_isNodeIntegration = false; // 新版本electron从12开始，默认关闭这个nodejs了
    m_isContextIsolation = true;
    m_isNodeIntegrationInSubframes = false;
    m_isLoading = false;
    m_nodeBinding = nullptr;
    m_id = IdLiveDetect::get()->constructed(this);
    m_view = NULL_WEBVIEW;
    int id = m_id;

    options.GetBydefaultVal("preload", "", &m_preloadScriptPath);
    gin::Wrappable<WebContents>::InitWith(isolate, wrapper);

    options.GetBydefaultVal("session", "", &m_sessionName); 
    if (m_sessionName.empty()) {
        options.GetBydefaultVal("partition", "", &m_sessionName); // 
    }
    if (!m_sessionName.empty()) {
        const char* persistPrefix = "persist:";
        size_t persistPrefixLen = strlen(persistPrefix);

        if (m_sessionName.substr(0, persistPrefixLen) == persistPrefix)
            m_sessionName = m_sessionName.substr(persistPrefixLen, std::string::npos);
    } else {
        m_sessionName = ApiSession::kDefaultSessionName;
    }

    WebContents* self = this;
    m_view = mbCreateWebView();
    mbSetUserKeyValue(m_view, "WebContents", self);
    mbSetAutoDrawToHwnd(m_view, FALSE);
    mbOnDidCreateScriptContext(m_view, &WebContents::staticDidCreateScriptContextCallback, this);
    mbOnWillReleaseScriptContext(m_view, &WebContents::staticOnWillReleaseScriptContextCallback, this);
    mbOnDownloadInBlinkThread(m_view, &WebContents::staticOnDownloadCallback, this);

    setUserAgentApi("UserAgent Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like XNT) Chrome/79.0.3945.130 Safari/537.36");

    ApiSession* session = SessionMgr::get()->findOrCreateSession(isolate, m_sessionName, true);
    
#if defined(WIN32) //TODO linux
    std::string cookiejar = session->getPath();
    cookiejar += "\\cookie.dat";
    mbSetCookieJarFullPath(m_view, StringUtil::UTF8ToUTF16(cookiejar).c_str());
    mbSetLocalStorageFullPath(m_view, StringUtil::UTF8ToUTF16(session->getPath()).c_str());
#endif
}

WebContents::~WebContents()
{
    // 在ui线程的js环境中可能因为gc机制被触发析构
    for (auto it : m_observers) {
        (it)->onWebContentsDeleted(this);
    }

    m_owner->close();

    mbSetUserKeyValue(m_view, "WebContents", nullptr);
    IdLiveDetect::get()->deconstructed(m_id);
}

void WebContents::addObserver(WebContentsObserver* observer)
{
    m_observers.insert(observer);
}

void WebContents::removeObserver(WebContentsObserver* observer)
{
    auto it = m_observers.find(observer);
    m_observers.erase(it);
}

void WebContents::newFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    v8::Isolate* isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    if (args.IsConstructCall()) {
        if (args.Length() > 1)
            return;

        gin::Dictionary options(args.GetIsolate(), args[0]->ToObject());
        WebContents* webContents = new WebContents(isolate, args.This(), options);

        args.GetReturnValue().Set(args.This());
    } else {
        const int argc = 2;
        v8::Local<v8::Value> argv[argc] = { args[0], args[1] };
        v8::Local<v8::Function> cons = v8::Local<v8::Function>::New(isolate, constructor);
        args.GetReturnValue().Set(cons->NewInstance(context, argc, argv).ToLocalChecked());
    }
}

// from BrowserWindow::newWindow         -> BrowserWindow::newWindowTaskInUiThread
// or   BrowserWindow::setBrowserViewApi -> BrowserView::newViewTaskInUiThread
// void WebContents::onNewWindowInUiThread(int x, int y, int width, int height, const CreateWindowParam* createWindowParam)
// {
//     mbWebView webView = getMbView();
//     if (createWindowParam->transparent)
//         mbSetTransparent(webView, true);
//     //mbSetDebugConfig(NULL_WEBVIEW, "paintCallbackInOtherThread", nullptr);
//     mbResize(webView, width, height);
// 
//     char* output = (char*)malloc(0x300);
//     sprintf_s(output, 0x299, "preload,WebContents::onNewWindowInUiThread: %p, %s\n", this, m_preloadScriptPath.c_str());
//     OutputDebugStringA(output);
//     free(output);
// }

void WebContents::staticDidCreateScriptContextCallback(mbWebView webView, mbWebFrameHandle param, mbWebFrameHandle frame, void* context, int extensionGroup, int worldId)
{
    WebContents* self = (WebContents*)param;
    self->onDidCreateScriptContext(webView, frame, (v8::Local<v8::Context>*)context, extensionGroup, worldId);
}

static void disableNodejsOfWindow(mbWebView webView, mbWebFrameHandle frame)
{
    mbRunJs(webView, frame, "window.require = null;", false, nullptr, nullptr, nullptr);
}

void WebContents::onDidCreateScriptContext(mbWebView webView, mbWebFrameHandle frame, v8::Local<v8::Context>* context, int extensionGroup, int worldId)
{   
    ThreadCall::callUiThreadAsync([webView] {
        std::string temp = "preload,onDidCreateScriptContext, url:";
        temp += mbGetUrl(webView);
        temp += "\n";
        OutputDebugStringA(temp.c_str());
    });

    NodeBindings::bindMbConsoleLog(*context, false);
    if (m_nodeBinding )
        return;

    const utf8* script = "window.Notification = function(){};";
    mbRunJs(webView, frame, script, false, nullptr, nullptr, nullptr);

    bool isMainWorld = WorldIDs::MAIN_WORLD_ID == worldId;
    bool shouldLoadNodejs = false;
    bool shouldPreLoad = false;
    bool shouldDisableNodejsOfWindow = false;

    if (m_isContextIsolation) {
        // 有预加载，只有隔离世界有nodejs。主世界没nodejs
        if (!isMainWorld)
            shouldLoadNodejs = true;
        else
            mbRunJs(webView, frame, "void 0", false, nullptr, nullptr, (void*)WorldIDs::ISOLATED_WORLD_ID); // 这句话会导致重入本函数
    } else if (m_isNodeIntegration && !m_isContextIsolation) {
        // 有预加载，预加载里有nodejs，而且预加载没隔离。主世界有nodejs
        if (!isMainWorld)
            DebugBreak();
        shouldLoadNodejs = true;
    } else if (!m_isNodeIntegration && !m_isContextIsolation) {
        shouldLoadNodejs = true; // 有预加载，预加载里有nodejs，而且预加载没隔离。主世界没nodejs
        shouldDisableNodejsOfWindow = true; // 想办法禁用主世界的nodejs
    }

    if (!m_isNodeIntegrationInSubframes && !mbIsMainFrame(webView, frame))
        shouldLoadNodejs = false;

    printf("WebContents::onDidCreateScriptContext: %d %d %d\n", shouldLoadNodejs, m_isContextIsolation, m_isNodeIntegration);
    if (shouldLoadNodejs) {
        BlinkMicrotaskSuppressionHandle handle = nodeBlinkMicrotaskSuppressionEnter((*context)->GetIsolate());
        m_nodeBinding = new NodeBindings(false);
        m_nodeBinding->setUvLoop(ThreadCall::getBlinkLoop());
        node::Environment* env = m_nodeBinding->createEnvironment(*context);
        m_nodeBinding->loadEnvironment();
        nodeBlinkMicrotaskSuppressionLeave(handle);

        if (!m_preloadScriptPath.empty()) {
            std::string preloadScriptPath = m_preloadScriptPath;
            for (size_t i = 0; i < preloadScriptPath.size(); ++i) {
                if ('\\' == preloadScriptPath[i])
                    preloadScriptPath[i] = '/';
            }

            std::string contents = "window.require('";
            contents += preloadScriptPath;
            contents += "');";
            mbRunJs(webView, frame, contents.c_str(), false, nullptr, nullptr, nullptr);
        }
    }
    if (shouldDisableNodejsOfWindow)
        disableNodejsOfWindow(webView, frame);
}

void WebContents::staticOnWillReleaseScriptContextCallback(mbWebView webView, void* param, mbWebFrameHandle frame, void* context, int worldId)
{
    WebContents* self = (WebContents*)param;
    self->onWillReleaseScriptContextCallback(webView, frame, (v8::Local<v8::Context>*)context, worldId);
}

void WebContents::onWillReleaseScriptContextCallback(mbWebView webView, mbWebFrameHandle frame, v8::Local<v8::Context>* context, int worldId)
{
    node::Environment* env = node::Environment::GetCurrent(*context);
    if (env && node::IsLiveObj((intptr_t)env))
        mate::emitEvent(env->isolate(), env->process_object(), "exit");

    delete m_nodeBinding;
    m_nodeBinding = nullptr;
}

mbDownloadOpt WebContents::staticOnDownloadCallback(mbWebView webView, void* param, size_t expectedContentLength, const char* url,
    const char* mime, const char* disposition, mbNetJob job, mbNetJobDataBind* dataBind)
{
    WebContents* self = (WebContents*)param;
    ApiSession* ses = SessionMgr::get()->findOrCreateSession(v8::Isolate::GetCurrent(), self->m_sessionName, false);
    return ses->onDownloadCallback(self, webView, expectedContentLength, url, mime, disposition, job, dataBind);
}

// channel是"ipc-message"字符串，和用户发送的channel不是一回事
void WebContents::rendererPostMessageToMain(const std::string& channel, const base::ListValue& listParams)
{
    int id = m_id;
    WebContents* self = this;
    base::ListValue* listParamsCopy = listParams.DeepCopy();
    std::string* channelCopy = new std::string(channel);
    if (channel != "ipc-message" && channel != "ipc-render-invoke")
        DebugBreak();    

    ThreadCall::callUiThreadAsync([self, id, channelCopy, listParamsCopy] {
        if (IdLiveDetect::get()->isLive(id)) {
            self->mate::EventEmitter<WebContents>::emit(channelCopy->c_str(), *listParamsCopy);
        }
        delete listParamsCopy;
        delete channelCopy;
    });
}

void WebContents::rendererSendMessageToMain(const std::string& channel, const base::ListValue& listParams, std::string* jsonRet)
{
    WebContents* self = this;
    const base::ListValue* listParamsPtr = &listParams;

    if (channel != "ipc-message-sync")
        DebugBreak();

    ThreadCall::callUiThreadSync([self, listParamsPtr, jsonRet] {
        self->mate::EventEmitter<WebContents>::emitWithSender(
            "ipc-message-sync", [jsonRet](const std::string& json) {
                jsonRet->assign(json.c_str(), json.size());
            },
        *listParamsPtr);
    });
}

static bool getIPCObject(v8::Isolate* isolate, v8::Local<v8::Context> context, v8::Local<v8::Object>* ipc)
{
    v8::Local<v8::String> key = gin::StringToV8(isolate, "ipc");
    v8::Local<v8::Private> privateKey = v8::Private::ForApi(isolate, key);
    v8::Local<v8::Object> global_object = context->Global();
    v8::Local<v8::Value> value;
    if (!global_object->GetPrivate(context, privateKey).ToLocal(&value))
        return false;
    if (value.IsEmpty() || !value->IsObject())
        return false;
    *ipc = value->ToObject();
    return true;
}

static std::vector<v8::Local<v8::Value>> listValueToVector(v8::Isolate* isolate, const base::ListValue& list)
{
    v8::Local<v8::Value> array = gin::ConvertToV8(isolate, list);
    std::vector<v8::Local<v8::Value>> result;
    gin::ConvertFromV8(isolate, array, &result);
    return result;
}

static void emitIPCEventImpl(WebContents* webContents, mbWebView view, mbWebFrameHandle frame, int worldID, const std::string& channel, const base::ListValue& args)
{
    if (!frame /*|| wkeIsWebRemoteFrame(view, frame)*/)
        return;

    v8::Isolate* isolate = (v8::Isolate*)mbGetBlinkMainThreadIsolate();
    v8::HandleScope handleScope(isolate);

    v8::Local<v8::Context> context;
    s_mbGetWorldScriptContextByWebFrame(view, frame, worldID, &context); 
    v8::Context::Scope contextScope(context);

    // Only emit IPC event for context with node integration.
    node::Environment* env = node::Environment::GetCurrent(context);
    if (!env)
        return;

    v8::Local<v8::Object> ipc;
    if (getIPCObject(isolate, context, &ipc)) {

        std::vector<v8::Local<v8::Value>> argsVector = listValueToVector(isolate, args);
        gin::Dictionary evt = gin::Dictionary::CreateEmpty(isolate);
#if 1 // 2.x版本electron的sender改成webContents(此处存疑，应该不是的)
        evt.Set("sender", ipc); // Insert the Event object, event.sender is ipc.
#else
        evt.Set("sender", webContents->GetWrapper(isolate));
#endif
        argsVector.insert(argsVector.begin(), evt.GetHandle());
        mate::emitEvent(isolate, ipc, channel, argsVector);
    }
}

static void emitIPCEvent(WebContents* webContents, mbWebView view, mbWebFrameHandle frame, const std::string& channel, const base::ListValue& args)
{
    emitIPCEventImpl(webContents, view, frame, WorldIDs::MAIN_WORLD_ID, channel, args);
    emitIPCEventImpl(webContents, view, frame, WorldIDs::ISOLATED_WORLD_ID, channel, args);
}

void WebContents::rendererSendMessageToRenderer(mbWebView view, mbWebFrameHandle frame, const std::string& channel, const base::ListValue& args)
{
    emitIPCEvent(nullptr, view, frame, channel, args);
}

void WebContents::anyPostMessageToRenderer(const std::string& channel, const base::ListValue& listParams)
{
    int id = m_id;
    WebContents* self = this;
    std::string* channelWrap = new std::string(channel);
    base::ListValue* listParamsWrap = listParams.DeepCopy();

    if ("window-load" == channel)
        OutputDebugStringA("");

    ThreadCall::callBlinkThreadAsync([self, id, channelWrap, listParamsWrap] {
        if (IdLiveDetect::get()->isLive(id)) {
            emitIPCEvent(self, self->m_view, mbWebFrameGetMainFrame(self->m_view), *channelWrap, *listParamsWrap);
        }

        delete channelWrap;
        delete listParamsWrap;
    });
}

void WebContents::getFocusedWebContentsApi(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Local<v8::Value> result = WindowInterface::getFocusedContents(info.GetIsolate());
    info.GetReturnValue().Set(result);
}

void WebContents::getAllWebContentsApi(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    WindowList* lists = WindowList::getInstance();

    v8::Local<v8::Array> results = v8::Array::New(info.GetIsolate(), lists->size());
    int count = 0;
    for (WindowList::iterator it = lists->begin(); it != lists->end(); ++it, ++count) {
        WebContents* content = (*it)->getWebContents();

        v8::Local<v8::Value> result = content->GetWrapper(info.GetIsolate());
        results->Set(count, result);
    }
    info.GetReturnValue().Set(results);
}

WebContents* WebContents::fromId(int id)
{
    WindowList* lists = WindowList::getInstance();

    WebContents* findedContent = nullptr;
    for (WindowList::iterator it = lists->begin(); it != lists->end(); ++it) {
        WebContents* content = (*it)->getWebContents();
        if ((int32_t)content->m_id != id)
            continue;
        findedContent = content;
        break;
    }
    return findedContent;
}

void WebContents::fromIdApi(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (1 != info.Length())
        return;
    v8::Local<v8::Value> arg0 = info[0];
    if (!arg0->IsInt32())
        return;

    int32_t id = arg0->Int32Value();
    WebContents* self = WebContents::fromId(id);
    v8::Isolate* isolate = info.GetIsolate();
    if (!self) {
        info.GetReturnValue().Set(v8::Null(isolate));
        return;
    }
    v8::Local<v8::Value> result = v8::Local<v8::Value>::New(isolate, self->GetWrapper(isolate));
    info.GetReturnValue().Set(result);
}

int WebContents::getIdApi() const
{
    return (int)m_id;
}

void WebContents::getSessionApi(const v8::FunctionCallbackInfo<v8::Value>& info) const
{
    v8::Isolate* isolate = info.GetIsolate();
    ApiSession* ses = SessionMgr::get()->findOrCreateSession(isolate, m_sessionName, false);
    info.GetReturnValue().Set(ses->GetWrapper(isolate));
}

int WebContents::getProcessIdApi() const
{
    return (int)::GetCurrentProcessId();
}

bool WebContents::equalApi() const
{
    return false;
}

static std::string* trimUrl(const std::string& url)
{
    std::string* str = new std::string(url);

    // file:\c:\ 处理这种字符串
    if (str->size() > 9 && str->substr(0, 6) == "file:\\" && str->at(7) == ':') {
        std::string* strTemp = new std::string(str->substr(6));
        strTemp->insert(0, "file:///");
        delete str;
        str = strTemp;
    }

    if (str->size() > 9 && str->substr(0, 7) == "file://") {
        if (str->at(7) != '/')
            str->insert(7, 1, '/');

        for (size_t i = 0; i < str->size(); ++i) { // 如果是中文路径，则把问号前面的内容解码
            char c = str->at(i);
            if ('?' != c)
                continue;

            std::string urldecodeHead = StringUtil::urlDecode(str->c_str(), i + 1);
            urldecodeHead += str->substr(i, str->size() - i);
            *str = urldecodeHead;
            break;
        }
    }

    char invalideHead[] = "http:\\";
    int invalideHeadLength = sizeof(invalideHead) - 1;
    if (((int)str->size() > invalideHeadLength) && str->substr(0, invalideHeadLength) == invalideHead) {
        for (size_t i = 0; i < str->size(); ++i) { // 反斜杠替换成斜杠
            char c = str->at(i);
            if ('\\' != c)
                continue;
            str->at(i) = '/';
        }
        char c = str->at(invalideHeadLength);
        if (c != '/')
            str->insert(str->begin() + invalideHeadLength, 1, '/');
    }

    return str;
}

void WebContents::_loadURLApi(const std::string& url)
{
    std::string* str = trimUrl(url);
    m_isLoading = true;

    printf("_loadURLApi: %x %x %x %x\n", url[17], url[18], url[19], url[20]);

    mbLoadURL(m_view, str->c_str());

    delete str;
    m_isLoading = false;
}

std::string WebContents::_getURLApi()
{
    return m_url;
}

std::string WebContents::getTitleApi()
{
    return m_title;
}

bool WebContents::isLoadingApi()
{
    bool isLoading = false;
    WebContents* self = this;
    int id = m_id;
    return isLoading;
}

bool WebContents::isLoadingMainFrameApi()
{
    //todo
    return false;
}

bool WebContents::isWaitingForResponseApi()
{
    //todo
    return false;
}

void WebContents::stopApi()
{
    mbStopLoading(m_view);
}

void WebContents::goBackApi()
{
    mbGoBack(m_view);
}

void WebContents::goForwardApi()
{
    mbGoForward(m_view);
}

void WebContents::goToOffsetApi(int offset)
{
    mbGoToOffset(m_view, offset);
}

void WebContents::goToIndexApi(int index)
{
    mbGoToIndex(m_view, index);
}

bool WebContents::isCrashedApi()
{
    return false;
}

void WebContents::setUserAgentApi(const std::string userAgent)
{
    m_ua = userAgent;
    mbSetUserAgent(m_view, userAgent.c_str());
}

std::string WebContents::getUserAgentApi()
{
    return m_ua;
}

void WebContents::insertCSSApi(const std::string& cssText)
{
    mbInsertCSSByFrame(m_view, mbWebFrameGetMainFrame(m_view), cssText.c_str());
}

void WebContents::savePageApi()
{
    //todo
}

void WebContents::openDevToolsApi()
{
    //todo
}

void WebContents::closeDevToolsApi()
{
    //todo
}

bool WebContents::isDevToolsOpenedApi()
{
    return false;
}

bool WebContents::isDevToolsFocusedApi()
{
    //todo
    return true;
}

void WebContents::enableDeviceEmulationApi()
{
    //todo
}

void WebContents::disableDeviceEmulationApi()
{
    //todo
}

void WebContents::toggleDevToolsApi()
{
    //todo
}

void WebContents::inspectElementApi()
{
    //todo
}

void WebContents::setAudioMutedApi()
{
    /*Isolate* isolate = args.GetIsolate();

    WebContents* webContents = ObjectWrap::Unwrap<WebContents>(args.Holder());

    ThreadCall::callBlinkThreadSync([webContents] {
        mbSetMediaVolume(webContents->m_view, 0.0);
    });*/
}

void WebContents::isAudioMutedApi()
{
}

void WebContents::undoApi()
{
    mbEditorUndo(m_view);
}

void WebContents::redoApi()
{
    mbEditorRedo(m_view);
}

void WebContents::cutApi()
{
    mbEditorCut(m_view);
}

void WebContents::copyApi()
{
    mbEditorCopy(m_view);
}

void WebContents::pasteApi()
{
    mbEditorPaste(m_view);
}

void WebContents::pasteAndMatchStyleApi()
{
    //todo
}

void WebContents::_deleteApi()
{
    mbEditorDelete(m_view);
}

void WebContents::selectAllApi()
{
    mbEditorSelectAll(m_view);
}

void WebContents::unselectApi()
{
    mbEditorUnSelect(m_view);
}

void WebContents::replaceApi()
{
    //todo
}

void WebContents::replaceMisspellingApi()
{
    //todo
}

void WebContents::findInPageApi()
{
    //todo
}

void WebContents::stopFindInPageApi()
{
    //todo
}

void WebContents::focusApi()
{
    mbSetFocus(m_view);
}

bool WebContents::isFocusedApi()
{
    //todo
    return false;
}

void WebContents::tabTraverseApi()
{
    //todo
}

bool WebContents::_sendApi(bool isAllFrames, const std::string& channel, const base::ListValue& args)
{
    if (!isAllFrames) {
        anyPostMessageToRenderer(channel, args);
        return true;
    }
    WindowList::iterator winIt = WindowList::getInstance()->begin();
    for (; winIt != WindowList::getInstance()->end(); ++winIt) {
        WindowInterface* windowInterface = *winIt;
        WebContents* webContents = windowInterface->getWebContents();
        webContents->anyPostMessageToRenderer(channel, args);
    }
    return true;
}

void WebContents::sendInputEventApi()
{
    //todo
}

void WebContents::beginFrameSubscriptionApi()
{
    //todo
}

void WebContents::endFrameSubscriptionApi()
{
    //todo
}

void WebContents::startDragApi()
{
    //todo
}

void WebContents::setSizeApi()
{
    //todo
}

bool WebContents::isGuestApi()
{
    //todo
    return false;
}

bool WebContents::isOffscreenApi()
{
    //todo
    return false;
}

void WebContents::startPaintingApi()
{
    //todo
}

void WebContents::stopPaintingApi()
{
    //todo
}

bool WebContents::isPaintingApi()
{
    //todo
    return false;
}

void WebContents::setFrameRateApi(int frameRate)
{
    m_frameRate = frameRate;
}

int WebContents::getFrameRateApi()
{
    return m_frameRate;
}

void WebContents::invalidateApi()
{
    //todo
}

void WebContents::getTypeApi()
{
    //todo
}

void WebContents::getWebPreferencesApi()
{
    //todo
}

v8::Local<v8::Value> WebContents::getOwnerBrowserWindowApi()
{
    if (m_owner)
        return m_owner->getWrapper();

    return v8::Null(isolate());
}

bool WebContents::hasServiceWorkerApi()
{
    return false;
}

void WebContents::unregisterServiceWorkerApi()
{
    //todo
}

void WebContents::inspectServiceWorkerApi()
{
    //todo
}

void WebContents::printApi()
{
    //todo
}

void WebContents::_printToPDFApi()
{
    //todo
}

void WebContents::addWorkSpaceApi()
{
    //todo
}

void WebContents::reNullWorkSpaceApi()
{
    //todo
}

void WebContents::showDefinitionForSelectionApi()
{
    //todo
}

void WebContents::copyImageAtApi()
{
    //todo
}

void WebContents::capturePageApi()
{
    //todo
}

void WebContents::setEmbedderApi()
{
    //todo
}

bool WebContents::isDestroyedApi() const
{
    return false;
}

void WebContents::reloadIgnoringCacheApi()
{
    mbReload(m_view);
}

void WebContents::nullFunction()
{
}

gin::WrapperInfo WebContents::kWrapperInfo = { gin::kEmbedderNativeGin };
v8::Persistent<v8::Function> WebContents::constructor;

static void initializeWebContentApi(v8::Local<v8::Object> target, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, const NodeNative* native)
{
    node::Environment* env = node::Environment::GetCurrent(context);
    WebContents::init(env->isolate(), target, env);
}

static const char WebContentsSricpt[] = "exports = {};";

static NodeNative nativeBrowserWebContentsNative { "WebContents", WebContentsSricpt, sizeof(WebContentsSricpt) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(atom_browser_web_contents, initializeWebContentApi, &nativeBrowserWebContentsNative)

} // atom

namespace gin {

v8::Local<v8::Value> ConvertToV8(v8::Isolate* isolate, const atom::WebContents& content)
{
    atom::WebContents* ctx = (atom::WebContents*)&content;
    return ctx->GetWrapper(isolate);
}

}
