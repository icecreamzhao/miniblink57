
#ifndef __CMD_HANDLER_H__
#define __CMD_HANDLER_H__

#include <Windows.h>

/* buffer����󳤶� */
#define PIPE_BUFFER_SIZE 1024 * 10000
#define MAX_CMD 1024 * 10000

/* ������� */
typedef struct _CHCmdParam CHCmdParam;

struct _CHCmdParam {
    /* ��ʼ��Ϊ sizeof(CommandParam) */
    int iSize;

    /* �ⲿ�������Ҫ��������Ϊ-1, �ṩ���ⲿʹ��
    */
    int iCommand;

    /* ��ʱʱ�䣬��λ�� */
    int iTimeOut;

    /* ������Ҫִ�е����� */
    WCHAR szCommand[MAX_CMD];

    /* �û����� */
    void* pUserData;

    /* ����ִ�к�Ļص� */
    void (*OnCmdEvent)(const CHCmdParam* pParam, HRESULT hResultCode, const char* szResult);

    _CHCmdParam()
    {
        iSize = 0;
        iCommand = 0;
        iTimeOut = 0;
        memset(szCommand, 0, sizeof(WCHAR) * MAX_CMD);
        pUserData = nullptr;
        OnCmdEvent = nullptr;
    }
};

class CmdHandler {
private:
    BOOL m_bInit;
    STARTUPINFO m_startupInfo;
    PROCESS_INFORMATION m_processInfo;
    SECURITY_ATTRIBUTES m_saOutPipe;
    DWORD m_dwErrorCode;
    HANDLE m_hPipeRead;
    HANDLE m_hPipeWrite;
    CHCmdParam m_CommandParam;
    WCHAR m_szReadBuffer[PIPE_BUFFER_SIZE];
    WCHAR m_szWriteBuffer[PIPE_BUFFER_SIZE];
    char m_szPipeOut[PIPE_BUFFER_SIZE];
    HRESULT ExecuteCmdWait();

public:
    CmdHandler();
    ~CmdHandler();
    /*
    * ��ʼ���ӿڣ���������ӿ�֮ǰ����
    * �ɹ�����S_OK
    */
    HRESULT Initalize();
    /*
    * �����ӿ�
    */
    HRESULT Finish();
    /*
    * ִ������ӿڣ��ӿڵ��óɹ�����S_OK
    * param[in] pCommmandParam: ָ��һ��CHCmdParam��������ṹ��ָ��
    */
    HRESULT HandleCommand(CHCmdParam* pCommmandParam);
    /*
    * ���ش����룬���ڲ��ӿڵ���ʧ�ܺ����ʲô����
    */
    DWORD GetErrorCode() { return m_dwErrorCode; }
};

#endif // __CMD_HANDLER_H__