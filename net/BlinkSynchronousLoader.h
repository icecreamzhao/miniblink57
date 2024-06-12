
namespace net {

class BlinkSynchronousLoader : public blink::WebURLLoaderClient {
    WTF_MAKE_NONCOPYABLE(BlinkSynchronousLoader);
public:
    BlinkSynchronousLoader(blink::WebURLError&, blink::WebURLResponse&, Vector<char>&);
    ~BlinkSynchronousLoader();

    void didReceiveResponse(const blink::WebURLResponse&) override;
    void didReceiveData(const char* data, int dataLength) override;
    void didFinishLoading(double finishTime, int64_t totalEncodedDataLength, int64_t totalEncodedBodyLength) override;
    void didFail(const blink::WebURLError&, int64_t totalEncodedDataLength, int64_t totalEncodedBodyLength) override;

private:
    blink::WebURLError& m_error;
    blink::WebURLResponse& m_response;
    Vector<char>& m_data;
};

inline BlinkSynchronousLoader::BlinkSynchronousLoader(blink::WebURLError& error, blink::WebURLResponse& response, Vector<char>& data)
    : m_error(error)
    , m_response(response)
    , m_data(data)
{
}

inline BlinkSynchronousLoader::~BlinkSynchronousLoader()
{

}

inline void BlinkSynchronousLoader::didReceiveResponse(const blink::WebURLResponse& response)
{
    m_response = response;
}

inline void BlinkSynchronousLoader::didReceiveData(const char* data, int dataLength)
{
    m_data.append(data, dataLength);
}

inline void BlinkSynchronousLoader::didFinishLoading(double finishTime, int64_t totalEncodedDataLength, int64_t totalEncodedBodyLength)
{
}

inline void BlinkSynchronousLoader::didFail(const blink::WebURLError& error, int64_t totalEncodedDataLength, int64_t totalEncodedBodyLength)
{
    m_error = error;
}

}