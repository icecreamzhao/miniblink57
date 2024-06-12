import { constVal, buildCommonSetting } from "./const_val.js";

var json = [{
    "var":[
        {"sdkPath":constVal.sdkPath},
        {"clangPath":constVal.clangPath},
        {"srcPath":constVal.srcPath},
        {"ndkIncludePath":constVal.ndkIncludePath},
        {"ndkBinPath":constVal.ndkBinPath},
        {"targetDir": constVal.targetDir},
        {"sysroot": constVal.sysroot},
    ],
    "compile":{
        "ccompiler":"${clangPath}/clang.exe",
        "cppcompiler":"${clangPath}/clang++.exe",
            
        "include":[
//            "${sdkPath}/include/c++/7.2.0",
//            "${sdkPath}/include/c++/7.2.0/include",
//            "${ndkIncludePath}",
//            "${sdkPath}/include/c++/7.2.0/x86_64-unknown-linux-gnu/",
//            "${sdkPath}/sysroot/usr/include",
//            "${sdkPath}/sysroot/usr/",
//            "${sdkPath}/sysroot/usr/include/linux",
            ...constVal.includePaths,
            "${srcPath}",
            "${srcPath}/linux",
            "${srcPath}/third_party/freetype/src/include",
            "${srcPath}/third_party/zlib",
            "${srcPath}/third_party/libcurl/",
            "${srcPath}/third_party/libcurl/src",
            "${srcPath}/third_party/libcurl/include",
            "${srcPath}/node/openssl",
            "${srcPath}/node/openssl/openssl/include",
            "${srcPath}/node/cares/include"
        ],
        "prebuildSrc":[
            "${srcPath}/third_party/libcurl/src/vauth/ntlm.c",
        ],
        "src":[
            "${srcPath}/third_party/libcurl/src/vauth/digest_sspi.c",
            "${srcPath}/third_party/libcurl/src/vauth/krb5_gssapi.c",
            "${srcPath}/third_party/libcurl/src/vauth/krb5_sspi.c",
            "${srcPath}/third_party/libcurl/src/vauth/ntlm.c",
            "${srcPath}/third_party/libcurl/src/vauth/ntlm_sspi.c",
            "${srcPath}/third_party/libcurl/src/vauth/oauth2.c",
            "${srcPath}/third_party/libcurl/src/vauth/spnego_gssapi.c",
            "${srcPath}/third_party/libcurl/src/vauth/spnego_sspi.c",
            "${srcPath}/third_party/libcurl/src/vauth/vauth.c",
            "${srcPath}/third_party/libcurl/src/vauth/cleartext.c",
            "${srcPath}/third_party/libcurl/src/vauth/cram.c",
            "${srcPath}/third_party/libcurl/src/vauth/digest.c",
            "${srcPath}/third_party/libcurl/src/tftp.c",
            "${srcPath}/third_party/libcurl/src/timeval.c",
            "${srcPath}/third_party/libcurl/src/transfer.c",
            "${srcPath}/third_party/libcurl/src/url.c",
            "${srcPath}/third_party/libcurl/src/version.c",
            "${srcPath}/third_party/libcurl/src/warnless.c",
            "${srcPath}/third_party/libcurl/src/wildcard.c",
            "${srcPath}/third_party/libcurl/src/x509asn1.c",
            "${srcPath}/third_party/libcurl/src/amigaos.c",
            "${srcPath}/third_party/libcurl/src/base64.c",
            "${srcPath}/third_party/libcurl/src/conncache.c",
            "${srcPath}/third_party/libcurl/src/connect.c",
            "${srcPath}/third_party/libcurl/src/content_encoding.c",
            "${srcPath}/third_party/libcurl/src/cookie.c",
            "${srcPath}/third_party/libcurl/src/curl_addrinfo.c",
            "${srcPath}/third_party/libcurl/src/curl_des.c",
            "${srcPath}/third_party/libcurl/src/curl_endian.c",
            "${srcPath}/third_party/libcurl/src/curl_fnmatch.c",
            "${srcPath}/third_party/libcurl/src/curl_gethostname.c",
            "${srcPath}/third_party/libcurl/src/curl_gssapi.c",
            "${srcPath}/third_party/libcurl/src/curl_memrchr.c",
            "${srcPath}/third_party/libcurl/src/curl_multibyte.c",
            "${srcPath}/third_party/libcurl/src/curl_ntlm_core.c",
            "${srcPath}/third_party/libcurl/src/curl_ntlm_wb.c",
            "${srcPath}/third_party/libcurl/src/curl_rtmp.c",
            "${srcPath}/third_party/libcurl/src/curl_sasl.c",
            "${srcPath}/third_party/libcurl/src/curl_sspi.c",
            "${srcPath}/third_party/libcurl/src/curl_threads.c",
            "${srcPath}/third_party/libcurl/src/dict.c",
            "${srcPath}/third_party/libcurl/src/dotdot.c",
            "${srcPath}/third_party/libcurl/src/easy.c",
            "${srcPath}/third_party/libcurl/src/escape.c",
            "${srcPath}/third_party/libcurl/src/file.c",
            "${srcPath}/third_party/libcurl/src/fileinfo.c",
            "${srcPath}/third_party/libcurl/src/formdata.c",
            "${srcPath}/third_party/libcurl/src/ftp.c",
            "${srcPath}/third_party/libcurl/src/ftplistparser.c",
            "${srcPath}/third_party/libcurl/src/getenv.c",
            "${srcPath}/third_party/libcurl/src/getinfo.c",
            "${srcPath}/third_party/libcurl/src/gopher.c",
            "${srcPath}/third_party/libcurl/src/hash.c",
            "${srcPath}/third_party/libcurl/src/hmac.c",
            "${srcPath}/third_party/libcurl/src/hostasyn.c",
            "${srcPath}/third_party/libcurl/src/hostcheck.c",
            "${srcPath}/third_party/libcurl/src/hostip.c",
            "${srcPath}/third_party/libcurl/src/hostip4.c",
            "${srcPath}/third_party/libcurl/src/hostip6.c",
            "${srcPath}/third_party/libcurl/src/hostsyn.c",
            "${srcPath}/third_party/libcurl/src/http.c",
            "${srcPath}/third_party/libcurl/src/http_chunks.c",
            "${srcPath}/third_party/libcurl/src/http_digest.c",
            "${srcPath}/third_party/libcurl/src/http_negotiate.c",
            "${srcPath}/third_party/libcurl/src/http_ntlm.c",
            "${srcPath}/third_party/libcurl/src/http_proxy.c",
            "${srcPath}/third_party/libcurl/src/http2.c",
            "${srcPath}/third_party/libcurl/src/idn_win32.c",
            "${srcPath}/third_party/libcurl/src/if2ip.c",
            "${srcPath}/third_party/libcurl/src/imap.c",
            "${srcPath}/third_party/libcurl/src/inet_ntop.c",
            "${srcPath}/third_party/libcurl/src/inet_pton.c",
            "${srcPath}/third_party/libcurl/src/krb5.c",
            "${srcPath}/third_party/libcurl/src/ldap.c",
            "${srcPath}/third_party/libcurl/src/llist.c",
            "${srcPath}/third_party/libcurl/src/md4.c",
            "${srcPath}/third_party/libcurl/src/md5.c",
            "${srcPath}/third_party/libcurl/src/memdebug.c",
            "${srcPath}/third_party/libcurl/src/mime.c",
            "${srcPath}/third_party/libcurl/src/mprintf.c",
            "${srcPath}/third_party/libcurl/src/multi.c",
            "${srcPath}/third_party/libcurl/src/netrc.c",
            "${srcPath}/third_party/libcurl/src/non-ascii.c",
            "${srcPath}/third_party/libcurl/src/nonblock.c",
            "${srcPath}/third_party/libcurl/src/nwlib.c",
            "${srcPath}/third_party/libcurl/src/nwos.c",
            "${srcPath}/third_party/libcurl/src/openldap.c",
            "${srcPath}/third_party/libcurl/src/parsedate.c",
            "${srcPath}/third_party/libcurl/src/pingpong.c",
            "${srcPath}/third_party/libcurl/src/pop3.c",
            "${srcPath}/third_party/libcurl/src/progress.c",
            "${srcPath}/third_party/libcurl/src/rand.c",
            "${srcPath}/third_party/libcurl/src/rtsp.c",
            "${srcPath}/third_party/libcurl/src/security.c",
            "${srcPath}/third_party/libcurl/src/select.c",
            "${srcPath}/third_party/libcurl/src/sendf.c",
            "${srcPath}/third_party/libcurl/src/setopt.c",
            "${srcPath}/third_party/libcurl/src/sha256.c",
            "${srcPath}/third_party/libcurl/src/share.c",
            "${srcPath}/third_party/libcurl/src/slist.c",
            "${srcPath}/third_party/libcurl/src/smb.c",
            "${srcPath}/third_party/libcurl/src/smtp.c",
            "${srcPath}/third_party/libcurl/src/socks.c",
            "${srcPath}/third_party/libcurl/src/socks_gssapi.c",
            "${srcPath}/third_party/libcurl/src/socks_sspi.c",
            "${srcPath}/third_party/libcurl/src/speedcheck.c",
            "${srcPath}/third_party/libcurl/src/splay.c",
            "${srcPath}/third_party/libcurl/src/strcase.c",
            "${srcPath}/third_party/libcurl/src/strdup.c",
            "${srcPath}/third_party/libcurl/src/strerror.c",
            "${srcPath}/third_party/libcurl/src/strtok.c",
            "${srcPath}/third_party/libcurl/src/strtoofft.c",
            "${srcPath}/third_party/libcurl/src/system_win32.c",
            "${srcPath}/third_party/libcurl/src/telnet.c",
            "${srcPath}/third_party/libcurl/src/curl_ctype.c",
            "${srcPath}/third_party/libcurl/src/curl_range.c",
            "${srcPath}/third_party/libcurl/src/vtls/polarssl_threadlock.c",
            "${srcPath}/third_party/libcurl/src/vtls/schannel.c",
            "${srcPath}/third_party/libcurl/src/vtls/schannel_verify.c",
            "${srcPath}/third_party/libcurl/src/vtls/vtls.c",
            "${srcPath}/third_party/libcurl/src/vtls/gskit.c",
            "${srcPath}/third_party/libcurl/src/vtls/gtls.c",
            "${srcPath}/third_party/libcurl/src/vtls/mbedtls.c",
            "${srcPath}/third_party/libcurl/src/vtls/nss.c",
            "${srcPath}/third_party/libcurl/src/vtls/openssl.c",
            "${srcPath}/third_party/libcurl/src/vtls/polarssl.c",
            "${srcPath}/third_party/libcurl/src/pipeline.c",
            "${srcPath}/third_party/libcurl/src/vtls/cyassl.c",
            "${srcPath}/third_party/libcurl/src/asyn-thread.c"
        ],
        // 
        "cmd":[
            //"--target=x86_64-linux-guneabi",
            "-fms-extensions",
            "-fno-exceptions",
            //"-fshort-wchar",
            "-D_GNU_SOURCE",
            "-DHAVE_CONFIG_H",
            "-DOS_LINUX_FOR_WIN",
            "-DHAVE_LIBZ=1",
            "-DHAVE_ZLIB_H=1",
            "-DCURLRES_ARES=1",
            "-DCURL_STATICLIB",
            "-DBUILDING_LIBCURL",
            "-DCURL_DISABLE_FTP=1",
            "-DCURL_DISABLE_IMAP=1",
            "-DCURL_DISABLE_LDAP=1",
            "-DCURL_DISABLE_POP3=1",
            "-DCURL_DISABLE_RTSP=1",
            "-DCURL_DISABLE_SMTP=1",
            "-DCURL_DISABLE_TELNET=1",
            "-DCURL_DISABLE_TFTP=1",
            "-DUSE_THREADS_POSIX=1",
            "-DUSE_OPENSSL=1"
        ],
        "objdir":"${srcPath}/out/tmp/curl/${targetDir}",
        "outdir":"${srcPath}/out/${targetDir}",
        "target":"libcurl.a",
        "beginLibs":[
        ],
        "linkerCmd":[],
        "endLibs":[
        ],
        "linker":"${ndkBinPath}/ar.exe"
    }
}];

buildCommonSetting(json);
