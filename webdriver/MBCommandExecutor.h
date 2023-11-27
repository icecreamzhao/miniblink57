
#ifndef WEBDRIVER_MBCOMMANDEXECUTOR_H_
#define WEBDRIVER_MBCOMMANDEXECUTOR_H_

#include <ctime>
#include <map>
#include <mutex>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "webdriver/server/command.h"
#include "webdriver/CustomTypes.h"
//#include "IElementManager.h"
#include "webdriver/BrowserFactory.h"
#include "webdriver/messages.h"
#include "mbvip/core/mb.h"

namespace webdriver {

class CommandHandlerRepository;
class Response;

class MBCommandExecutor {
public:
    MBCommandExecutor();

    std::string sessionId() const
    {
        return this->m_sessionId;
    }

    int port() const
    {
        return this->m_port;
    }

    void setView(mbWebView view, const std::string& browserId);

    mbWebView view() const
    {
        return m_mbView;
    }

    std::string browserId() const
    {
        return m_browserId;
    }

    bool is_valid(void) const
    {
        return this->m_isValid;
    }

    void setIsValid(const bool session_is_valid)
    {
        this->m_isValid = session_is_valid;
    }

    bool is_quitting(void) const
    {
        return this->m_isQuitting;
    }
    void setIsQuitting(const bool session_is_quitting)
    {
        this->m_isQuitting = session_is_quitting;
    }

    void setCurrentBrowserId(const std::string& id);

    std::string session_id(void) const
    {
        return this->m_sessionId;
    }

    std::string getUnexpectedAlertBehavior(void) const
    {
        return m_unexpectedAlertBehavior;
    }

    void setUnexpectedAlertBehavior(const std::string& behavior)
    {
        std::string output("setUnexpectedAlertBehavior:");
        output += behavior;
        output += "\n";
        OutputDebugStringA(output.c_str());
//         if (!behavior.empty())
//             MessageBoxA(0, "setUnexpectedAlertBehavior", 0, 0);
        m_unexpectedAlertBehavior = behavior;
    }

    const BrowserFactorySettings& settings() const
    {
        return m_settings;
    }

    size_t managedWindowCount() const
    {
        return m_managedBrowsers.size();
    }

    static bool isValidWebView(mbWebView webviewHandle);
    void closeAllWindow();

    int createNewBrowser(std::string* errorMessage, mbWebView* mbwebview, std::string* browserId);
    int getManagedBrowser(const std::string& browserId, mbWebView* webview) const;
    void getManagedBrowserHandles(std::vector<std::string>* managedBrowsers) const;
    void eraseManagedBrowserHandle(mbWebView webview);

    bool executeCommand(const std::string& serialized_command, std::string* serialized_response);
    void initialize(int port, const std::string& sessionId);

    static unsigned int CALLBACK threadProc(LPVOID lpParameter);

private:
    void initWebview(mbWebView mbView);

    static mbWebView MB_CALL_TYPE onCreateViewCallback(mbWebView webView, void* param, mbNavigationType navigationType, const utf8* url, const mbWindowFeatures* windowFeatures);
    void addManagedBrowser(mbWebView mbView, const std::string& browserId);

    mbWebView m_mbView = NULL_WEBVIEW;
    std::string m_browserId;

    CommandHandlerRepository* m_commandHandlers = nullptr;
    BrowserFactorySettings m_settings;
    std::string m_sessionId;
    int m_port = -1;
    bool m_isValid = true;
    bool m_isQuitting = false;

    std::string m_unexpectedAlertBehavior;

    mutable CRITICAL_SECTION m_managedBrowsersLock;

    typedef std::unordered_map<std::string, mbWebView> BrowserMap;
    BrowserMap m_managedBrowsers;
};

}

#endif 