

#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "android/log.h"
#include "net/base/address_list.h"
#include "net/tencent/net_logger.h"
#include "tencent/util/crash_extra_message_manager.h"
#include "udp_dns_resolver.h"

#define DNS_HOST 0x01
#define DNS_CNAME 0x05

#define parse(__w, __p)   \
    do {                  \
        *__p = *__w << 8; \
        __w++;            \
        *__p |= *__w;     \
        __w++;            \
    } while (0)

namespace net {

static const char* DNS_TENCENT_SERVER = "119.29.29.29";
static const int MAX_DOMAIN_LENGTH = 253;
static const int MAX_DOMAIN_SECTION_LENGTH = 63;
static const int PARSE_DOMAIN_BUFFER_LEN = 512;

static const int SOCKET_SEND_RECV_BUF_LEN = 4096;
static const int SOCKET_CONNECT_TIME_OUT_SECONDS = 4;
static const int DNS_RESPONSE_HEADER_LENTH = 24;

UdpDnsResolver* UdpDnsResolver::_instance = NULL;

std::string byteToHexStr(const unsigned char byte_arr[], int arr_len)
{
    std::string hexstr;
    for (int i = 0; i < arr_len; i++) {
        char hex1;
        char hex2;
        //直接将unsigned char赋值给整型的值，系统会自动强制转换
        int value = byte_arr[i];
        int v1 = value / 16;
        int v2 = value % 16;

        //将商转成字母
        if (v1 >= 0 && v1 <= 9)
            hex1 = (char)(48 + v1);
        else
            hex1 = (char)(55 + v1);

        //将余数转成字母
        if (v2 >= 0 && v2 <= 9)
            hex2 = (char)(48 + v2);
        else
            hex2 = (char)(55 + v2);

        //将字母连接成串
        hexstr = hexstr + hex1 + hex2;
    }

    return hexstr;
}

uint32_t parseNAME(uint8_t* buffer, uint8_t* Domain)
{
    uint32_t i = 0, num = 0, a = 0;
    uint8_t j = *buffer;
    do {
        for (i = 0; i < j; i++) {
            buffer++;
            num++;
            Domain[a] = *buffer;
            a++;
        }
        Domain[a] = '.';
        a++;
        buffer++;
        num++;
        j = *buffer;
    } while (j != 0 && num <= MAX_DOMAIN_LENGTH && j <= MAX_DOMAIN_SECTION_LENGTH); //最长MAX_DOMAIN_LENGTH个字符的域名长度,每段最长MAX_DOMAIN_SECTION_LENGTH个字节。
    num += 5;
    return num;
}

std::string UdpDnsResolver::getTencentDnsServer()
{
    return DNS_TENCENT_SERVER;
}

int UdpDnsResolver::parseDNSInfo(const char* host, AddressFamily address_family, HostResolverFlags host_resolver_flags, AddressList* addr_list, int* os_error)
{
    struct addrinfo* ai = NULL;

    socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketfd < 0) {
        return errno | 0x2900; //41
    }

    struct timeval timeout = { SOCKET_CONNECT_TIME_OUT_SECONDS, 0 };
    int retsnd = setsockopt(socketfd, SOL_SOCKET, SO_SNDTIMEO, (char*)&timeout, sizeof(timeout));
    int retrcv = setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));

    //如果设置失败，不进行处理，继续运行.
    int sendbuf = SOCKET_SEND_RECV_BUF_LEN;
    int recvbuf = SOCKET_SEND_RECV_BUF_LEN;
    setsockopt(socketfd, SOL_SOCKET, SO_SNDBUF, &sendbuf, sizeof(sendbuf));
    setsockopt(socketfd, SOL_SOCKET, SO_RCVBUF, &recvbuf, sizeof(recvbuf));

    if (retsnd == -1 || retrcv == -1) {
        return errno | 0x3800; //56
    }

    bzero(&dest, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(53);
    dest.sin_addr.s_addr = inet_addr(DNS_TENCENT_SERVER);

    int sendRet = send_dns_request(host);
    if (sendRet < 0) {
        if (errno == 11) {
            sendRet = send_dns_request(host);

            if (sendRet < 0) {
                return errno | 0x4900; //73
            }
        } else {
            return errno | 0x4E00; //78 #################### 103 #########################
        }
    }

    return parse_dns_response(ai, addr_list);
}

int UdpDnsResolver::parse_dns_response(struct addrinfo* ai, AddressList* addr_list)
{

    uint8_t buf[1024];
    bzero(buf, sizeof(buf));
    uint8_t* buffer = buf;

    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(struct sockaddr_in);

    int ret = recvfrom(socketfd, buf, sizeof(buf), 0, (struct sockaddr*)&addr, &addr_len);
    int recvDataLength = ret;
    if (ret <= -1) {
        if (errno == 11) {
            bzero(buf, sizeof(buf));
            ret = recvfrom(socketfd, buf, sizeof(buf), MSG_WAITALL, (struct sockaddr*)&addr, &addr_len);
            recvDataLength = ret;

            if (ret <= -1) {
                return errno | 0x6700; //103   ###################11#################
            }
        } else {
            return errno | 0x6C00; //108
        }
    }

    if (ret == 0) //the peer has performed an orderly shutdown.
        return -1;

    NET_LOG_DNS("Received data is %s", byteToHexStr(buf, ret).c_str());
    tencent::CrashExtraMessageManager::get()->ReportExtraMessageLogToRQDThreadSafe(string("dns_response"), byteToHexStr(buf, ret));
#if 0
	ptr += 4; /* move ptr to Questions */
	querys = ntohs(*((unsigned short*)ptr));
	ptr += 2; /* move ptr to Answer RRs */
	answers = ntohs(*((unsigned short*)ptr));
	ptr += 6; /* move ptr to Querys */
	/* move over Querys */
	for(i= 0 ; i < querys ; i ++){
		for(;;){
			flag = (int)ptr[0];
			ptr += (flag + 1);
			if(flag == 0)
				break;
		}
		ptr += 4;
	}

	/* now ptr points to Answers */
	for(i = 0 ; i < answers ; i ++){
		bzero(aname , sizeof(aname));
		len = 0;
		parse_dns_name(buf , ptr , aname , &len);
		ptr += 2; /* move ptr to Type*/
		type = htons(*((unsigned short*)ptr));
		ptr += 4; /* move ptr to Time to live */
		/*ttl = htonl(*((unsigned int*)ptr));*/
		ptr += 4; /* move ptr to Data lenth */
		datalen = ntohs(*((unsigned short*)ptr));
		ptr += 2; /* move ptr to Data*/

		if(type == DNS_CNAME){

            /*
			bzero(cname , sizeof(cname));
			len = 0;
			parse_dns_name(buf , ptr , cname , &len);
            */
			ptr += datalen;
		}

		if(type == DNS_HOST){
			bzero(ip , sizeof(ip));

			if(datalen == 4){
                struct sockaddr_in resolvedAddr;
                bzero(&resolvedAddr, sizeof(resolvedAddr));
                resolvedAddr.sin_family = AF_INET;
                resolvedAddr.sin_port = htons(80);

                memcpy(&resolvedAddr.sin_addr, ptr, datalen);

                IPEndPoint iep;
                if(iep.FromSockAddr((struct sockaddr *)&resolvedAddr, sizeof(resolvedAddr)))
                {
                    addr_list->push_back(iep);
                    break;
                }
			}
			ptr += datalen;
		}
 
	}
	ptr += 2;


    if(addr_list->size() > 0)
    {
        return 0;
    }
    else
    {
        return EAI_NODATA | 0xB600;//182
    }
#endif

    uint32_t transID;
    parse(buffer, &transID);
    if (transID != 0xff00) {
        NET_LOG_DNS("NET UDP DNS recvbuf error");
        return ret;
    } else {
        uint32_t Flags;
        parse(buffer, &Flags);
        //NET_LOG_DNS("Flags = %#x",Flags);

        uint32_t Question;
        parse(buffer, &Question);
        //NET_LOG_DNS("Question = %#x",Question);

        uint32_t AnserRRs;
        parse(buffer, &AnserRRs);
        //NET_LOG_DNS("AnserRRs = %#x",AnserRRs);

        uint32_t Authority;
        parse(buffer, &Authority);
        //NET_LOG_DNS("AdditionalRRs = %#x",Authority);

        uint32_t AdditionalRRs;
        parse(buffer, &AdditionalRRs);
        //NET_LOG_DNS("AdditionalRRs = %#x",AdditionalRRs);

        uint8_t Domain[PARSE_DOMAIN_BUFFER_LEN] = { 0 };
        uint32_t queryNameLength = parseNAME(buffer, Domain);
        if (queryNameLength + DNS_RESPONSE_HEADER_LENTH >= (uint32_t)recvDataLength)
            return -1;
        buffer += queryNameLength;
        //NET_LOG_DNS("Domain = %s ",Domain);

        //point to name
        while (*buffer == 0xc0) // c0 XXXXX c0 XXXXX c0 XXXXX
        {
            buffer += 2; //->type;
            buffer += 2; //->Class;
            buffer += 2; //->TTL;
            buffer += 4; //->length
            buffer += 1; //->little
            if (*buffer != 4) //not ip;
            {
                buffer += *buffer + 1;
            } else //is ip
            {

                struct in_addr* netip;
                buffer += 1;
                netip = (struct in_addr*)buffer;
                buffer += 4;
                NET_LOG_DNS("NET UDP DNS Resolved ip = %s", inet_ntoa(*netip));

                struct sockaddr_in resolvedAddr;
                bzero(&resolvedAddr, sizeof(resolvedAddr));
                resolvedAddr.sin_family = AF_INET;
                resolvedAddr.sin_port = htons(80);

                memcpy(&resolvedAddr.sin_addr, netip, 4);

                IPEndPoint iep;
                if (iep.FromSockAddr((struct sockaddr*)&resolvedAddr, sizeof(resolvedAddr))) {
                    addr_list->push_back(iep);
                    break;
                }
            }
        }
    }

    if (addr_list->size() > 0) {
        return 0;
    } else {
        return EAI_NODATA | 0xB600; //182
    }
}

void UdpDnsResolver::parse_dns_name(unsigned char* chunk, unsigned char* ptr, char* out, int* len)
{
    unsigned char n, flag;
    char* pos = out + (*len);

    for (;;) {
        flag = ptr[0];
        if (flag == 0)
            break;
        if (is_pointer(flag)) {
            n = ptr[1];
            ptr = chunk + n;
            parse_dns_name(chunk, ptr, out, len);
            break;
        } else {
            ptr++;
            memcpy(pos, ptr, flag);
            pos += flag;
            ptr += flag;
            *len += flag;
            if ((int)ptr[0] != 0) {
                memcpy(pos, ".", 1);
                pos += 1;
                (*len) += 1;
            }
        }
    }
}

int UdpDnsResolver::is_pointer(unsigned char in)
{
    return (in == 0xc0);
}

int UdpDnsResolver::send_dns_request(const char* dns_name)
{
    unsigned char request[256];
    unsigned char* ptr = request;
    unsigned char question[128];
    int question_len;

    const int DNS_HEADER_LEN = 12;

    //DNS Header.
    *((unsigned short*)ptr) = htons(0xff00);
    ptr += 2;
    *((unsigned short*)ptr) = htons(0x0100);
    ptr += 2;
    *((unsigned short*)ptr) = htons(1);
    ptr += 2;
    *((unsigned short*)ptr) = 0;
    ptr += 2;
    *((unsigned short*)ptr) = 0;
    ptr += 2;
    *((unsigned short*)ptr) = 0;
    ptr += 2;

    generate_question(dns_name, question, &question_len);

    memcpy(ptr, question, question_len);
    ptr += question_len;

    int sendRet = sendto(socketfd, request, question_len + DNS_HEADER_LEN, 0, (struct sockaddr*)&dest, sizeof(struct sockaddr));

    return sendRet;
}

void UdpDnsResolver::generate_question(const char* dns_name, unsigned char* buf, int* len)
{
    char* pos;
    unsigned char* ptr;
    int n;

    *len = 0;
    ptr = buf;
    pos = (char*)dns_name;
    for (;;) {
        n = strlen(pos) - (strstr(pos, ".") ? strlen(strstr(pos, ".")) : 0);
        *ptr++ = (unsigned char)n;
        memcpy(ptr, pos, n);
        *len += n + 1;
        ptr += n;
        if (!strstr(pos, ".")) {
            *ptr = (unsigned char)0;
            ptr++;
            *len += 1;
            break;
        }
        pos += n + 1;
    }

    //Query Header.
    *((unsigned short*)ptr) = htons(1);
    *len += 2;
    ptr += 2;
    *((unsigned short*)ptr) = htons(1);
    *len += 2;
}

}
