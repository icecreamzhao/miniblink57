// Licensed to the Software Freedom Conservancy (SFC) under one
// or more contributor license agreements. See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership. The SFC licenses this file
// to you under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "webdriver/WebDriver.h"

#include "webdriver/CommandLineArguments.h"
#include "webdriver/server/wd_logging.h"
#include "StringUtilities.h"
#ifdef unix
#include "windows.h"
#include <list>
#include <process.h>
extern "C" void OutputDebugStringToFile(const char* str);
#endif

webdriver::Server* g_server = NULL;

webdriver::Server* StartServer(
    int port, const std::string& host, const std::string& log_level, const std::string& log_file, const std::string& version, const std::string& whitelist)
{
    WDLOG(TRACE) << "Entering StartServer";
    if (g_server == NULL) {
        WDLOG(DEBUG) << "Instantiating webdriver server";

        std::string converted_host = /*webdriver::StringUtilities::ToString*/(host);
        std::string converted_log_level = /*webdriver::StringUtilities::ToString*/(log_level);
        std::string converted_log_file = /*webdriver::StringUtilities::ToString*/(log_file);
        std::string converted_version = /*webdriver::StringUtilities::ToString*/(version);
        std::string converted_acl = /*webdriver::StringUtilities::ToString*/(whitelist);
        g_server = new webdriver::MBServer(port, converted_host, converted_log_level, converted_log_file, converted_version, converted_acl);
        if (!g_server->Start()) {
            WDLOG(TRACE) << "Starting of IEServer is failed";
            delete g_server;
            g_server = NULL;
        }
    }
    return g_server;
}

void StopServer()
{
    WDLOG(TRACE) << "Entering StopServer";
    if (g_server) {
        g_server->Stop();
        delete g_server;
        g_server = NULL;
    }
}

void mainComm(const std::string& cmd)
{
    const char* argArray[2] = { 0 };
    argArray[1] = cmd.c_str();

//     std::string debugoutput = "mainComm 1: ";
//     debugoutput += cmd.c_str();
//     debugoutput += "\n";
//     OutputDebugStringToFile(debugoutput.c_str());

    char* output = (char*)malloc(0x100);
    sprintf(output, "mainComm 1: %s\n", cmd.c_str());
    OutputDebugStringToFile(output);
    free(output);

    CommandLineArguments args(2, (char**)argArray);

    if (args.is_version_requested()) {
        OutputDebugStringToFile("is_version_requested\n");
        std::cout << "ChromeDriver 108.0.5359.71 (1e0e3868ee06e91ad636a874420e3ca3ae3756ac-refs/branch-heads/5359@{#1016})" << std::endl;
        //printf("ChromeDriver 108.0.5359.71 (1e0e3868ee06e91ad636a874420e3ca3ae3756ac-refs/branch-heads/5359@{#1016})\n");
        return;
    }
    
    std::string portStr = args.GetValue("port", "-1");
    int port = atoi(portStr.c_str());
    StartServer(port, "127.0.0.1", "INFO", "", "mb5775", "");

    //printf("mainComm 2: %p\n", g_server);

    while (g_server->is_stop()) {
        Sleep(100);
    }
    OutputDebugStringToFile("mainComm exit\n");
}

#ifdef _WIN32

extern "C" void OutputDebugStringToFile(const char* str)
{
    OutputDebugStringA(str);
}

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    //MessageBoxA(0, "wkeDriver", 0, 0);

    int numArgs = 0;
    LPWSTR* cmd = CommandLineToArgvW(lpCmdLine, &numArgs);
    if (0 == numArgs)
        return 0;

    std::string cmdA = webdriver::StringUtilities::ToString(*cmd);
    mainComm(cmdA);

    return 0;
}
#else

class LogThread {
public:
    LogThread()
    {
        setenv("SELENIUM_LOG_LEVEL", "FATAL", 1);

        //m_handle = fopen("/usr/bin/chromedriver.txt", "a");
        //m_handle = fopen("chromedriver.txt", "a");
        openFile("w");
        if (!m_handle)
            return;
        fclose(m_handle);
        openFile("a");
        if (!m_handle)
            return;

        unsigned int s_threadId = 0;
        _beginthreadex(NULL, 0, logThreadProc, (void*)(this), 0, &s_threadId);
        while (m_mutex == nullptr) {
            Sleep(100);
        }
    }

    void openFile(const char* mode)
    {
        m_handle = fopen("/home/weolar/test/livi-browser-gtk/build/chromedriver.txt", mode);
        if (!m_handle)
            m_handle = fopen("/tmp/mbdriver/mbdriver.txt", mode);
        if (!m_handle)
            m_handle = fopen("chromedriver.txt", mode);
    }

    static unsigned int logThreadProc(LPVOID lpParameter)
    {
        LogThread* self = (LogThread*)lpParameter;
        self->threadProc();
        return 0;
    }

    void pushStr(const char* str)
    {
        if (!str || !m_handle)
            return;

        EnterCriticalSection(m_mutex);
        m_logTexts.push_back(std::string(str));
        LeaveCriticalSection(m_mutex);

        while (true) {
            EnterCriticalSection(m_mutex);
            if (0 != m_logTexts.size()) {
                LeaveCriticalSection(m_mutex);
                Sleep(10);
            } else {
                LeaveCriticalSection(m_mutex);
                break;
            }
        }
    }

    void threadProc()
    {
        //printf("threadProc 1\n");
        if (!m_handle)
            return;

        CRITICAL_SECTION* mutex = new CRITICAL_SECTION();
        InitializeCriticalSection(mutex);
        m_mutex = mutex;
        //printf("threadProc 2\n");

        for (; true; Sleep(1)) {
            EnterCriticalSection(m_mutex);
            if (m_logTexts.size() == 0) {
                LeaveCriticalSection(m_mutex);
                continue;
            }

            std::list<std::string>::iterator it = m_logTexts.begin();
            std::string str = *it;
            m_logTexts.pop_front();
            LeaveCriticalSection(m_mutex);

            fwrite(str.c_str(), sizeof(char), str.size(), m_handle);
            fflush(m_handle);
        }
    }
private:
    FILE* m_handle = nullptr;
    std::list<std::string> m_logTexts;
    CRITICAL_SECTION* m_mutex = nullptr;
};
LogThread* g_logThread = nullptr;

extern "C" void OutputDebugStringToFile(const char* str)
{
    //g_logThread->pushStr(str);
    OutputDebugStringA(str);
}

int main(int argc, char* argv[])
{
    //printf("main 1: %d\n", argc);
    g_logThread = new LogThread();

    if (argc < 2)
        return 0;

    char* output = (char*)malloc(0x100);
    sprintf(output, "main 2, argc:%d, argv[1]:%s\n", argc, argv[1]);
    OutputDebugStringToFile(output);
    free(output);

    mainComm(argv[1]);

    OutputDebugStringToFile("exit main\n");
    Sleep(3000);
    return 0;
}
#endif