
#ifndef browser_api_ProtocolInterface_h
#define browser_api_ProtocolInterface_h

namespace atom {

class ProtocolInterface {
public:
    static ProtocolInterface* inst()
    {
        return m_inst;
    }

    virtual bool handleLoadUrlBegin(void* param, const char* url, void* job) = 0;
    virtual ~ProtocolInterface()
    {

    }

protected:
    static ProtocolInterface* m_inst;
};

}

#endif // browser_api_ProtocolInterface_h