
#include "node_url.h"
#include "node_internals.h"
#include "node_i18n.h"
#include "env.h"
#include "env-inl.h"
#include "util.h"
#include "v8.h"
#include "v8-debug.h"
#include "v8-profiler.h"

#include <string>
#include <vector>
#include <stdio.h>
#include <cmath>

namespace node {

using v8::Array;
using v8::Context;
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::HandleScope;
using v8::Int32;
using v8::Integer;
using v8::Isolate;
using v8::Local;
using v8::MaybeLocal;
using v8::Null;
using v8::Object;
using v8::String;
using v8::TryCatch;
using v8::Undefined;
using v8::Value;

inline Local<String> Utf8String(Isolate* isolate, const std::string& str)
{
    return String::NewFromUtf8(isolate,
        str.data(),
        v8::NewStringType::kNormal,
        str.length())
        .ToLocalChecked();
}

namespace url {

    namespace {

        // https://url.spec.whatwg.org/#eof-code-point
        const char kEOL = -1;

        // Used in ToUSVString().
        const char16_t kUnicodeReplacementCharacter = 0xFFFD;

        // https://url.spec.whatwg.org/#concept-host
        class URLHost {
        public:
            ~URLHost();

            void ParseIPv4Host(const char* input, size_t length, bool* is_ipv4);
            void ParseIPv6Host(const char* input, size_t length);
            void ParseOpaqueHost(const char* input, size_t length);
            void ParseHost(const char* input,
                size_t length,
                bool is_special,
                bool unicode = false);

            inline bool ParsingFailed() const { return type_ == HostType::H_FAILED; }
            std::string ToString() const;
            // Like ToString(), but avoids a copy in exchange for invalidating `*this`.
            std::string ToStringMove();

        private:
            enum class HostType {
                H_FAILED,
                H_DOMAIN,
                H_IPV4,
                H_IPV6,
                H_OPAQUE,
            };

            union Value {
                std::string domain_or_opaque;
                uint32_t ipv4;
                uint16_t ipv6[8];

                ~Value() { }
                Value()
                    : ipv4(0)
                {
                }
            };

            Value value_;
            HostType type_ = HostType::H_FAILED;

            inline void Reset()
            {
                using string = std::string;
                switch (type_) {
                case HostType::H_DOMAIN:
                case HostType::H_OPAQUE:
                    value_.domain_or_opaque.~string();
                    break;
                default:
                    break;
                }
                type_ = HostType::H_FAILED;
            }

            // Setting the string members of the union with = is brittle because
            // it relies on them being initialized to a state that requires no
            // destruction of old data.
            // For a long time, that worked well enough because ParseIPv6Host() happens
            // to zero-fill `value_`, but that really is relying on standard library
            // internals too much.
            // These helpers are the easiest solution but we might want to consider
            // just not forcing strings into an union.
            inline void SetOpaque(std::string&& string)
            {
                Reset();
                type_ = HostType::H_OPAQUE;
                new (&value_.domain_or_opaque) std::string(std::move(string));
            }

            inline void SetDomain(std::string&& string)
            {
                Reset();
                type_ = HostType::H_DOMAIN;
                new (&value_.domain_or_opaque) std::string(std::move(string));
            }
        };

        URLHost::~URLHost()
        {
            Reset();
        }

#define ARGS(XX)     \
    XX(ARG_FLAGS)    \
    XX(ARG_PROTOCOL) \
    XX(ARG_USERNAME) \
    XX(ARG_PASSWORD) \
    XX(ARG_HOST)     \
    XX(ARG_PORT)     \
    XX(ARG_PATH)     \
    XX(ARG_QUERY)    \
    XX(ARG_FRAGMENT) \
    XX(ARG_COUNT) // This one has to be last.

#define ERR_ARGS(XX)  \
    XX(ERR_ARG_FLAGS) \
    XX(ERR_ARG_INPUT)

        enum url_cb_args {
#define XX(name) name,
            ARGS(XX)
#undef XX
        };

        enum url_error_cb_args {
#define XX(name) name,
            ERR_ARGS(XX)
#undef XX
        };

#define CHAR_TEST(bits, name, expr)                         \
    template <typename T>                                   \
    inline bool name(const T ch)                            \
    {                                                       \
        static_assert(sizeof(ch) >= (bits) / 8,             \
            "Character must be wider than " #bits " bits"); \
        return (expr);                                      \
    }

#define TWO_CHAR_STRING_TEST(bits, name, expr)              \
    template <typename T>                                   \
    inline bool name(const T ch1, const T ch2)              \
    {                                                       \
        static_assert(sizeof(ch1) >= (bits) / 8,            \
            "Character must be wider than " #bits " bits"); \
        return (expr);                                      \
    }                                                       \
    template <typename T>                                   \
    inline bool name(const std::basic_string<T>& str)       \
    {                                                       \
        static_assert(sizeof(str[0]) >= (bits) / 8,         \
            "Character must be wider than " #bits " bits"); \
        return str.length() >= 2 && name(str[0], str[1]);   \
    }

        // https://infra.spec.whatwg.org/#ascii-tab-or-newline
        CHAR_TEST(8, IsASCIITabOrNewline, (ch == '\t' || ch == '\n' || ch == '\r'))

        // https://infra.spec.whatwg.org/#c0-control-or-space
        CHAR_TEST(8, IsC0ControlOrSpace, (ch >= '\0' && ch <= ' '))

        // https://infra.spec.whatwg.org/#ascii-digit
        CHAR_TEST(8, IsASCIIDigit, (ch >= '0' && ch <= '9'))

        // https://infra.spec.whatwg.org/#ascii-hex-digit
        CHAR_TEST(8, IsASCIIHexDigit, (IsASCIIDigit(ch) || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f')))

        // https://infra.spec.whatwg.org/#ascii-alpha
        CHAR_TEST(8, IsASCIIAlpha, ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')))

        // https://infra.spec.whatwg.org/#ascii-alphanumeric
        CHAR_TEST(8, IsASCIIAlphanumeric, (IsASCIIDigit(ch) || IsASCIIAlpha(ch)))

        // https://infra.spec.whatwg.org/#ascii-lowercase
        template <typename T>
        inline T ASCIILowercase(T ch)
        {
            return IsASCIIAlpha(ch) ? (ch | 0x20) : ch;
        }

        // https://url.spec.whatwg.org/#forbidden-host-code-point
        CHAR_TEST(8, IsForbiddenHostCodePoint,
            ch == '\0' || ch == '\t' || ch == '\n' || ch == '\r' || ch == ' ' || ch == '#' || ch == '%' || ch == '/' || ch == ':' || ch == '?' || ch == '@' || ch == '[' || ch == '\\' || ch == ']')

        // https://url.spec.whatwg.org/#windows-drive-letter
        TWO_CHAR_STRING_TEST(8, IsWindowsDriveLetter,
            (IsASCIIAlpha(ch1) && (ch2 == ':' || ch2 == '|')))

        // https://url.spec.whatwg.org/#normalized-windows-drive-letter
        TWO_CHAR_STRING_TEST(8, IsNormalizedWindowsDriveLetter,
            (IsASCIIAlpha(ch1) && ch2 == ':'))

        // If a UTF-16 character is a low/trailing surrogate.
        CHAR_TEST(16, IsUnicodeTrail, (ch & 0xFC00) == 0xDC00)

        // If a UTF-16 character is a surrogate.
        CHAR_TEST(16, IsUnicodeSurrogate, (ch & 0xF800) == 0xD800)

        // If a UTF-16 surrogate is a low/trailing one.
        CHAR_TEST(16, IsUnicodeSurrogateTrail, (ch & 0x400) != 0)

#undef CHAR_TEST
#undef TWO_CHAR_STRING_TEST

        const char* hex[256] = {
            "%00", "%01", "%02", "%03", "%04", "%05", "%06", "%07",
            "%08", "%09", "%0A", "%0B", "%0C", "%0D", "%0E", "%0F",
            "%10", "%11", "%12", "%13", "%14", "%15", "%16", "%17",
            "%18", "%19", "%1A", "%1B", "%1C", "%1D", "%1E", "%1F",
            "%20", "%21", "%22", "%23", "%24", "%25", "%26", "%27",
            "%28", "%29", "%2A", "%2B", "%2C", "%2D", "%2E", "%2F",
            "%30", "%31", "%32", "%33", "%34", "%35", "%36", "%37",
            "%38", "%39", "%3A", "%3B", "%3C", "%3D", "%3E", "%3F",
            "%40", "%41", "%42", "%43", "%44", "%45", "%46", "%47",
            "%48", "%49", "%4A", "%4B", "%4C", "%4D", "%4E", "%4F",
            "%50", "%51", "%52", "%53", "%54", "%55", "%56", "%57",
            "%58", "%59", "%5A", "%5B", "%5C", "%5D", "%5E", "%5F",
            "%60", "%61", "%62", "%63", "%64", "%65", "%66", "%67",
            "%68", "%69", "%6A", "%6B", "%6C", "%6D", "%6E", "%6F",
            "%70", "%71", "%72", "%73", "%74", "%75", "%76", "%77",
            "%78", "%79", "%7A", "%7B", "%7C", "%7D", "%7E", "%7F",
            "%80", "%81", "%82", "%83", "%84", "%85", "%86", "%87",
            "%88", "%89", "%8A", "%8B", "%8C", "%8D", "%8E", "%8F",
            "%90", "%91", "%92", "%93", "%94", "%95", "%96", "%97",
            "%98", "%99", "%9A", "%9B", "%9C", "%9D", "%9E", "%9F",
            "%A0", "%A1", "%A2", "%A3", "%A4", "%A5", "%A6", "%A7",
            "%A8", "%A9", "%AA", "%AB", "%AC", "%AD", "%AE", "%AF",
            "%B0", "%B1", "%B2", "%B3", "%B4", "%B5", "%B6", "%B7",
            "%B8", "%B9", "%BA", "%BB", "%BC", "%BD", "%BE", "%BF",
            "%C0", "%C1", "%C2", "%C3", "%C4", "%C5", "%C6", "%C7",
            "%C8", "%C9", "%CA", "%CB", "%CC", "%CD", "%CE", "%CF",
            "%D0", "%D1", "%D2", "%D3", "%D4", "%D5", "%D6", "%D7",
            "%D8", "%D9", "%DA", "%DB", "%DC", "%DD", "%DE", "%DF",
            "%E0", "%E1", "%E2", "%E3", "%E4", "%E5", "%E6", "%E7",
            "%E8", "%E9", "%EA", "%EB", "%EC", "%ED", "%EE", "%EF",
            "%F0", "%F1", "%F2", "%F3", "%F4", "%F5", "%F6", "%F7",
            "%F8", "%F9", "%FA", "%FB", "%FC", "%FD", "%FE", "%FF"
        };

        const uint8_t C0_CONTROL_ENCODE_SET[32] = {
            // 00     01     02     03     04     05     06     07
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 08     09     0A     0B     0C     0D     0E     0F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 10     11     12     13     14     15     16     17
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 18     19     1A     1B     1C     1D     1E     1F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 20     21     22     23     24     25     26     27
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 28     29     2A     2B     2C     2D     2E     2F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 30     31     32     33     34     35     36     37
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 38     39     3A     3B     3C     3D     3E     3F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 40     41     42     43     44     45     46     47
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 48     49     4A     4B     4C     4D     4E     4F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 50     51     52     53     54     55     56     57
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 58     59     5A     5B     5C     5D     5E     5F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 60     61     62     63     64     65     66     67
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 68     69     6A     6B     6C     6D     6E     6F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 70     71     72     73     74     75     76     77
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 78     79     7A     7B     7C     7D     7E     7F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x80,
            // 80     81     82     83     84     85     86     87
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 88     89     8A     8B     8C     8D     8E     8F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 90     91     92     93     94     95     96     97
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 98     99     9A     9B     9C     9D     9E     9F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // A0     A1     A2     A3     A4     A5     A6     A7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // A8     A9     AA     AB     AC     AD     AE     AF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // B0     B1     B2     B3     B4     B5     B6     B7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // B8     B9     BA     BB     BC     BD     BE     BF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // C0     C1     C2     C3     C4     C5     C6     C7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // C8     C9     CA     CB     CC     CD     CE     CF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // D0     D1     D2     D3     D4     D5     D6     D7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // D8     D9     DA     DB     DC     DD     DE     DF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // E0     E1     E2     E3     E4     E5     E6     E7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // E8     E9     EA     EB     EC     ED     EE     EF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // F0     F1     F2     F3     F4     F5     F6     F7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // F8     F9     FA     FB     FC     FD     FE     FF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80
        };

        const uint8_t FRAGMENT_ENCODE_SET[32] = {
            // 00     01     02     03     04     05     06     07
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 08     09     0A     0B     0C     0D     0E     0F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 10     11     12     13     14     15     16     17
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 18     19     1A     1B     1C     1D     1E     1F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 20     21     22     23     24     25     26     27
            0x01 | 0x00 | 0x04 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 28     29     2A     2B     2C     2D     2E     2F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 30     31     32     33     34     35     36     37
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 38     39     3A     3B     3C     3D     3E     3F
            0x00 | 0x00 | 0x00 | 0x00 | 0x10 | 0x00 | 0x40 | 0x00,
            // 40     41     42     43     44     45     46     47
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 48     49     4A     4B     4C     4D     4E     4F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 50     51     52     53     54     55     56     57
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 58     59     5A     5B     5C     5D     5E     5F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 60     61     62     63     64     65     66     67
            0x01 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 68     69     6A     6B     6C     6D     6E     6F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 70     71     72     73     74     75     76     77
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 78     79     7A     7B     7C     7D     7E     7F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x80,
            // 80     81     82     83     84     85     86     87
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 88     89     8A     8B     8C     8D     8E     8F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 90     91     92     93     94     95     96     97
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 98     99     9A     9B     9C     9D     9E     9F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // A0     A1     A2     A3     A4     A5     A6     A7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // A8     A9     AA     AB     AC     AD     AE     AF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // B0     B1     B2     B3     B4     B5     B6     B7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // B8     B9     BA     BB     BC     BD     BE     BF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // C0     C1     C2     C3     C4     C5     C6     C7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // C8     C9     CA     CB     CC     CD     CE     CF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // D0     D1     D2     D3     D4     D5     D6     D7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // D8     D9     DA     DB     DC     DD     DE     DF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // E0     E1     E2     E3     E4     E5     E6     E7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // E8     E9     EA     EB     EC     ED     EE     EF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // F0     F1     F2     F3     F4     F5     F6     F7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // F8     F9     FA     FB     FC     FD     FE     FF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80
        };

        const uint8_t PATH_ENCODE_SET[32] = {
            // 00     01     02     03     04     05     06     07
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 08     09     0A     0B     0C     0D     0E     0F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 10     11     12     13     14     15     16     17
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 18     19     1A     1B     1C     1D     1E     1F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 20     21     22     23     24     25     26     27
            0x01 | 0x00 | 0x04 | 0x08 | 0x00 | 0x00 | 0x00 | 0x00,
            // 28     29     2A     2B     2C     2D     2E     2F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 30     31     32     33     34     35     36     37
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 38     39     3A     3B     3C     3D     3E     3F
            0x00 | 0x00 | 0x00 | 0x00 | 0x10 | 0x00 | 0x40 | 0x80,
            // 40     41     42     43     44     45     46     47
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 48     49     4A     4B     4C     4D     4E     4F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 50     51     52     53     54     55     56     57
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 58     59     5A     5B     5C     5D     5E     5F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 60     61     62     63     64     65     66     67
            0x01 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 68     69     6A     6B     6C     6D     6E     6F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 70     71     72     73     74     75     76     77
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 78     79     7A     7B     7C     7D     7E     7F
            0x00 | 0x00 | 0x00 | 0x08 | 0x00 | 0x20 | 0x00 | 0x80,
            // 80     81     82     83     84     85     86     87
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 88     89     8A     8B     8C     8D     8E     8F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 90     91     92     93     94     95     96     97
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 98     99     9A     9B     9C     9D     9E     9F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // A0     A1     A2     A3     A4     A5     A6     A7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // A8     A9     AA     AB     AC     AD     AE     AF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // B0     B1     B2     B3     B4     B5     B6     B7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // B8     B9     BA     BB     BC     BD     BE     BF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // C0     C1     C2     C3     C4     C5     C6     C7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // C8     C9     CA     CB     CC     CD     CE     CF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // D0     D1     D2     D3     D4     D5     D6     D7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // D8     D9     DA     DB     DC     DD     DE     DF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // E0     E1     E2     E3     E4     E5     E6     E7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // E8     E9     EA     EB     EC     ED     EE     EF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // F0     F1     F2     F3     F4     F5     F6     F7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // F8     F9     FA     FB     FC     FD     FE     FF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80
        };

        const uint8_t USERINFO_ENCODE_SET[32] = {
            // 00     01     02     03     04     05     06     07
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 08     09     0A     0B     0C     0D     0E     0F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 10     11     12     13     14     15     16     17
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 18     19     1A     1B     1C     1D     1E     1F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 20     21     22     23     24     25     26     27
            0x01 | 0x00 | 0x04 | 0x08 | 0x00 | 0x00 | 0x00 | 0x00,
            // 28     29     2A     2B     2C     2D     2E     2F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x80,
            // 30     31     32     33     34     35     36     37
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 38     39     3A     3B     3C     3D     3E     3F
            0x00 | 0x00 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 40     41     42     43     44     45     46     47
            0x01 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 48     49     4A     4B     4C     4D     4E     4F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 50     51     52     53     54     55     56     57
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 58     59     5A     5B     5C     5D     5E     5F
            0x00 | 0x00 | 0x00 | 0x08 | 0x10 | 0x20 | 0x40 | 0x00,
            // 60     61     62     63     64     65     66     67
            0x01 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 68     69     6A     6B     6C     6D     6E     6F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 70     71     72     73     74     75     76     77
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 78     79     7A     7B     7C     7D     7E     7F
            0x00 | 0x00 | 0x00 | 0x08 | 0x10 | 0x20 | 0x00 | 0x80,
            // 80     81     82     83     84     85     86     87
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 88     89     8A     8B     8C     8D     8E     8F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 90     91     92     93     94     95     96     97
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 98     99     9A     9B     9C     9D     9E     9F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // A0     A1     A2     A3     A4     A5     A6     A7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // A8     A9     AA     AB     AC     AD     AE     AF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // B0     B1     B2     B3     B4     B5     B6     B7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // B8     B9     BA     BB     BC     BD     BE     BF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // C0     C1     C2     C3     C4     C5     C6     C7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // C8     C9     CA     CB     CC     CD     CE     CF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // D0     D1     D2     D3     D4     D5     D6     D7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // D8     D9     DA     DB     DC     DD     DE     DF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // E0     E1     E2     E3     E4     E5     E6     E7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // E8     E9     EA     EB     EC     ED     EE     EF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // F0     F1     F2     F3     F4     F5     F6     F7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // F8     F9     FA     FB     FC     FD     FE     FF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80
        };

        const uint8_t QUERY_ENCODE_SET[32] = {
            // 00     01     02     03     04     05     06     07
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 08     09     0A     0B     0C     0D     0E     0F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 10     11     12     13     14     15     16     17
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 18     19     1A     1B     1C     1D     1E     1F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 20     21     22     23     24     25     26     27
            0x01 | 0x00 | 0x04 | 0x08 | 0x00 | 0x00 | 0x00 | 0x00,
            // 28     29     2A     2B     2C     2D     2E     2F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 30     31     32     33     34     35     36     37
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 38     39     3A     3B     3C     3D     3E     3F
            0x00 | 0x00 | 0x00 | 0x00 | 0x10 | 0x00 | 0x40 | 0x00,
            // 40     41     42     43     44     45     46     47
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 48     49     4A     4B     4C     4D     4E     4F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 50     51     52     53     54     55     56     57
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 58     59     5A     5B     5C     5D     5E     5F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 60     61     62     63     64     65     66     67
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 68     69     6A     6B     6C     6D     6E     6F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 70     71     72     73     74     75     76     77
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
            // 78     79     7A     7B     7C     7D     7E     7F
            0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x80,
            // 80     81     82     83     84     85     86     87
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 88     89     8A     8B     8C     8D     8E     8F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 90     91     92     93     94     95     96     97
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // 98     99     9A     9B     9C     9D     9E     9F
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // A0     A1     A2     A3     A4     A5     A6     A7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // A8     A9     AA     AB     AC     AD     AE     AF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // B0     B1     B2     B3     B4     B5     B6     B7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // B8     B9     BA     BB     BC     BD     BE     BF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // C0     C1     C2     C3     C4     C5     C6     C7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // C8     C9     CA     CB     CC     CD     CE     CF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // D0     D1     D2     D3     D4     D5     D6     D7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // D8     D9     DA     DB     DC     DD     DE     DF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // E0     E1     E2     E3     E4     E5     E6     E7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // E8     E9     EA     EB     EC     ED     EE     EF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // F0     F1     F2     F3     F4     F5     F6     F7
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
            // F8     F9     FA     FB     FC     FD     FE     FF
            0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80
        };

        inline bool BitAt(const uint8_t a[], const uint8_t i)
        {
            return !!(a[i >> 3] & (1 << (i & 7)));
        }

        // Appends ch to str. If ch position in encode_set is set, the ch will
        // be percent-encoded then appended.
        inline void AppendOrEscape(std::string* str,
            const unsigned char ch,
            const uint8_t encode_set[])
        {
            if (BitAt(encode_set, ch))
                *str += hex[ch];
            else
                *str += ch;
        }

        template <typename T>
        inline unsigned hex2bin(const T ch)
        {
            if (ch >= '0' && ch <= '9')
                return ch - '0';
            if (ch >= 'A' && ch <= 'F')
                return 10 + (ch - 'A');
            if (ch >= 'a' && ch <= 'f')
                return 10 + (ch - 'a');
            return static_cast<unsigned>(-1);
        }

        inline std::string PercentDecode(const char* input, size_t len)
        {
            std::string dest;
            if (len == 0)
                return dest;
            dest.reserve(len);
            const char* pointer = input;
            const char* end = input + len;

            while (pointer < end) {
                const char ch = pointer[0];
                const size_t remaining = end - pointer - 1;
                if (ch != '%' || remaining < 2 || (ch == '%' && (!IsASCIIHexDigit(pointer[1]) || !IsASCIIHexDigit(pointer[2])))) {
                    dest += ch;
                    pointer++;
                    continue;
                } else {
                    unsigned a = hex2bin(pointer[1]);
                    unsigned b = hex2bin(pointer[2]);
                    char c = static_cast<char>(a * 16 + b);
                    dest += c;
                    pointer += 3;
                }
            }
            return dest;
        }

#define SPECIALS(XX)  \
    XX("ftp:", 21)    \
    XX("file:", -1)   \
    XX("gopher:", 70) \
    XX("http:", 80)   \
    XX("https:", 443) \
    XX("ws:", 80)     \
    XX("wss:", 443)

        inline bool IsSpecial(const std::string& scheme)
        {
#define XX(name, _)     \
    if (scheme == name) \
        return true;
            SPECIALS(XX);
#undef XX
            return false;
        }

        // https://url.spec.whatwg.org/#start-with-a-windows-drive-letter
        inline bool StartsWithWindowsDriveLetter(const char* p, const char* end)
        {
            const size_t length = end - p;
            return length >= 2 && IsWindowsDriveLetter(p[0], p[1]) && (length == 2 || p[2] == '/' || p[2] == '\\' || p[2] == '?' || p[2] == '#');
        }

        inline int NormalizePort(const std::string& scheme, int p)
        {
#define XX(name, port)               \
    if (scheme == name && p == port) \
        return -1;
            SPECIALS(XX);
#undef XX
            return p;
        }

#if defined(NODE_HAVE_I18N_SUPPORT)
        inline bool ToUnicode(const std::string& input, std::string* output)
        {
            MaybeStackBuffer<char> buf;
            if (i18n::ToUnicode(&buf, input.c_str(), input.length()) < 0)
                return false;
            output->assign(*buf, buf.length());
            return true;
        }

        inline bool ToASCII(const std::string& input, std::string* output)
        {
            MaybeStackBuffer<char> buf;
            if (i18n::ToASCII(&buf, input.c_str(), input.length()) < 0)
                return false;
            output->assign(*buf, buf.length());
            return true;
        }
#else
        // Intentional non-ops if ICU is not present.
        inline bool ToUnicode(const std::string& input, std::string* output)
        {
            *output = input;
            return true;
        }

        inline bool ToASCII(const std::string& input, std::string* output)
        {
            *output = input;
            return true;
        }
#endif

        void URLHost::ParseIPv6Host(const char* input, size_t length)
        {
            //NODE_CHECK_EQ(type_, HostType::H_FAILED);
            for (unsigned n = 0; n < 8; n++)
                value_.ipv6[n] = 0;
            uint16_t* piece_pointer = &value_.ipv6[0];
            uint16_t* const buffer_end = piece_pointer + 8;
            uint16_t* compress_pointer = nullptr;
            const char* pointer = input;
            const char* end = pointer + length;
            unsigned value, len, swaps, numbers_seen;
            char ch = pointer < end ? pointer[0] : kEOL;
            if (ch == ':') {
                if (length < 2 || pointer[1] != ':')
                    return;
                pointer += 2;
                ch = pointer < end ? pointer[0] : kEOL;
                piece_pointer++;
                compress_pointer = piece_pointer;
            }
            while (ch != kEOL) {
                if (piece_pointer >= buffer_end)
                    return;
                if (ch == ':') {
                    if (compress_pointer != nullptr)
                        return;
                    pointer++;
                    ch = pointer < end ? pointer[0] : kEOL;
                    piece_pointer++;
                    compress_pointer = piece_pointer;
                    continue;
                }
                value = 0;
                len = 0;
                while (len < 4 && IsASCIIHexDigit(ch)) {
                    value = value * 0x10 + hex2bin(ch);
                    pointer++;
                    ch = pointer < end ? pointer[0] : kEOL;
                    len++;
                }
                switch (ch) {
                case '.':
                    if (len == 0)
                        return;
                    pointer -= len;
                    ch = pointer < end ? pointer[0] : kEOL;
                    if (piece_pointer > buffer_end - 2)
                        return;
                    numbers_seen = 0;
                    while (ch != kEOL) {
                        value = 0xffffffff;
                        if (numbers_seen > 0) {
                            if (ch == '.' && numbers_seen < 4) {
                                pointer++;
                                ch = pointer < end ? pointer[0] : kEOL;
                            } else {
                                return;
                            }
                        }
                        if (!IsASCIIDigit(ch))
                            return;
                        while (IsASCIIDigit(ch)) {
                            unsigned number = ch - '0';
                            if (value == 0xffffffff) {
                                value = number;
                            } else if (value == 0) {
                                return;
                            } else {
                                value = value * 10 + number;
                            }
                            if (value > 255)
                                return;
                            pointer++;
                            ch = pointer < end ? pointer[0] : kEOL;
                        }
                        *piece_pointer = *piece_pointer * 0x100 + value;
                        numbers_seen++;
                        if (numbers_seen == 2 || numbers_seen == 4)
                            piece_pointer++;
                    }
                    if (numbers_seen != 4)
                        return;
                    continue;
                case ':':
                    pointer++;
                    ch = pointer < end ? pointer[0] : kEOL;
                    if (ch == kEOL)
                        return;
                    break;
                case kEOL:
                    break;
                default:
                    return;
                }
                *piece_pointer = value;
                piece_pointer++;
            }

            if (compress_pointer != nullptr) {
                swaps = piece_pointer - compress_pointer;
                piece_pointer = buffer_end - 1;
                while (piece_pointer != &value_.ipv6[0] && swaps > 0) {
                    uint16_t temp = *piece_pointer;
                    uint16_t* swap_piece = compress_pointer + swaps - 1;
                    *piece_pointer = *swap_piece;
                    *swap_piece = temp;
                    piece_pointer--;
                    swaps--;
                }
            } else if (compress_pointer == nullptr && piece_pointer != buffer_end) {
                return;
            }
            type_ = HostType::H_IPV6;
        }

        inline int64_t ParseNumber(const char* start, const char* end)
        {
            unsigned R = 10;
            if (end - start >= 2 && start[0] == '0' && (start[1] | 0x20) == 'x') {
                start += 2;
                R = 16;
            }
            if (end - start == 0) {
                return 0;
            } else if (R == 10 && end - start > 1 && start[0] == '0') {
                start++;
                R = 8;
            }
            const char* p = start;

            while (p < end) {
                const char ch = p[0];
                switch (R) {
                case 8:
                    if (ch < '0' || ch > '7')
                        return -1;
                    break;
                case 10:
                    if (!IsASCIIDigit(ch))
                        return -1;
                    break;
                case 16:
                    if (!IsASCIIHexDigit(ch))
                        return -1;
                    break;
                }
                p++;
            }

            return /*strtoll*/ strtol(start, nullptr, R);
        }

        void URLHost::ParseIPv4Host(const char* input, size_t length, bool* is_ipv4)
        {
            //NODE_CHECK_EQ(type_, HostType::H_FAILED);
            *is_ipv4 = false;
            const char* pointer = input;
            const char* mark = input;
            const char* end = pointer + length;
            int parts = 0;
            uint32_t val = 0;
            uint64_t numbers[4];
            int tooBigNumbers = 0;
            if (length == 0)
                return;

            while (pointer <= end) {
                const char ch = pointer < end ? pointer[0] : kEOL;
                const int remaining = end - pointer - 1;
                if (ch == '.' || ch == kEOL) {
                    if (++parts > 4)
                        return;
                    if (pointer == mark)
                        return;
                    int64_t n = ParseNumber(mark, pointer);
                    if (n < 0)
                        return;

                    if (n > 255) {
                        tooBigNumbers++;
                    }
                    numbers[parts - 1] = n;
                    mark = pointer + 1;
                    if (ch == '.' && remaining == 0)
                        break;
                }
                pointer++;
            }
            //NODE_CHECK_GT(parts, 0);
            *is_ipv4 = true;

            // If any but the last item in numbers is greater than 255, return failure.
            // If the last item in numbers is greater than or equal to
            // 256^(5 - the number of items in numbers), return failure.
            if (tooBigNumbers > 1 || (tooBigNumbers == 1 && numbers[parts - 1] <= 255) || numbers[parts - 1] >= std::pow(256, static_cast<double>(5 - parts))) {
                return;
            }

            type_ = HostType::H_IPV4;
            val = numbers[parts - 1];
            for (int n = 0; n < parts - 1; n++) {
                double b = 3 - n;
                val += numbers[n] * std::pow(256, b);
            }

            value_.ipv4 = val;
        }

        void URLHost::ParseOpaqueHost(const char* input, size_t length)
        {
            //NODE_CHECK_EQ(type_, HostType::H_FAILED);
            std::string output;
            output.reserve(length);
            for (size_t i = 0; i < length; i++) {
                const char ch = input[i];
                if (ch != '%' && IsForbiddenHostCodePoint(ch)) {
                    return;
                } else {
                    AppendOrEscape(&output, ch, C0_CONTROL_ENCODE_SET);
                }
            }

            SetOpaque(std::move(output));
        }

        void URLHost::ParseHost(const char* input,
            size_t length,
            bool is_special,
            bool unicode)
        {
            //NODE_CHECK_EQ(type_, HostType::H_FAILED);
            const char* pointer = input;

            if (length == 0)
                return;

            if (pointer[0] == '[') {
                if (pointer[length - 1] != ']')
                    return;
                return ParseIPv6Host(++pointer, length - 2);
            }

            if (!is_special)
                return ParseOpaqueHost(input, length);

            // First, we have to percent decode
            std::string decoded = PercentDecode(input, length);

            // Then we have to punycode toASCII
            if (!ToASCII(decoded, &decoded))
                return;

            // If any of the following characters are still present, we have to fail
            for (size_t n = 0; n < decoded.size(); n++) {
                const char ch = decoded[n];
                if (IsForbiddenHostCodePoint(ch)) {
                    return;
                }
            }

            // Check to see if it's an IPv4 IP address
            bool is_ipv4;
            ParseIPv4Host(decoded.c_str(), decoded.length(), &is_ipv4);
            if (is_ipv4)
                return;

            // If the unicode flag is set, run the result through punycode ToUnicode
            if (unicode && !ToUnicode(decoded, &decoded))
                return;

            // It's not an IPv4 or IPv6 address, it must be a domain
            SetDomain(std::move(decoded));
        }

        // Locates the longest sequence of 0 segments in an IPv6 address
        // in order to use the :: compression when serializing
        template <typename T>
        inline T* FindLongestZeroSequence(T* values, size_t len)
        {
            T* start = values;
            T* end = start + len;
            T* result = nullptr;

            T* current = nullptr;
            unsigned counter = 0, longest = 1;

            while (start < end) {
                if (*start == 0) {
                    if (current == nullptr)
                        current = start;
                    counter++;
                } else {
                    if (counter > longest) {
                        longest = counter;
                        result = current;
                    }
                    counter = 0;
                    current = nullptr;
                }
                start++;
            }
            if (counter > longest)
                result = current;
            return result;
        }

        std::string URLHost::ToStringMove()
        {
            std::string return_value;
            switch (type_) {
            case HostType::H_DOMAIN:
            case HostType::H_OPAQUE:
                return_value = std::move(value_.domain_or_opaque);
                break;
            default:
                return_value = ToString();
                break;
            }
            Reset();
            return return_value;
        }

        std::string URLHost::ToString() const
        {
            std::string dest;
            switch (type_) {
            case HostType::H_DOMAIN:
            case HostType::H_OPAQUE:
                return value_.domain_or_opaque;
                break;
            case HostType::H_IPV4: {
                dest.reserve(15);
                uint32_t value = value_.ipv4;
                for (int n = 0; n < 4; n++) {
                    char buf[4];
                    sprintf(buf, /*sizeof(buf),*/ "%d", value % 256);
                    dest.insert(0, buf);
                    if (n < 3)
                        dest.insert((unsigned int)0, (unsigned int)1, '.');
                    value /= 256;
                }
                break;
            }
            case HostType::H_IPV6: {
                dest.reserve(41);
                dest += '[';
                const uint16_t* start = &value_.ipv6[0];
                const uint16_t* compress_pointer = FindLongestZeroSequence(start, 8);
                bool ignore0 = false;
                for (int n = 0; n <= 7; n++) {
                    const uint16_t* piece = &value_.ipv6[n];
                    if (ignore0 && *piece == 0)
                        continue;
                    else if (ignore0)
                        ignore0 = false;
                    if (compress_pointer == piece) {
                        dest += n == 0 ? "::" : ":";
                        ignore0 = true;
                        continue;
                    }
                    char buf[5];
                    sprintf(buf, /* sizeof(buf),*/ "%x", *piece);
                    dest += buf;
                    if (n < 7)
                        dest += ':';
                }
                dest += ']';
                break;
            }
            case HostType::H_FAILED:
                break;
            }
            return dest;
        }

        bool ParseHost(const std::string& input,
            std::string* output,
            bool is_special,
            bool unicode = false)
        {
            if (input.length() == 0) {
                //output->clear();
                *output = "";
                return true;
            }
            URLHost host;
            host.ParseHost(input.c_str(), input.length(), is_special, unicode);
            if (host.ParsingFailed())
                return false;
            *output = host.ToStringMove();
            return true;
        }

        inline std::vector<std::string> FromJSStringArray(Environment* env,
            Local<Array> array)
        {
            std::vector<std::string> vec;
            const int32_t len = array->Length();
            if (len == 0)
                return vec; // nothing to copy
            vec.reserve(len);
            for (int32_t n = 0; n < len; n++) {
                Local<Value> val = array->Get(env->context(), n).ToLocalChecked();
                if (val->IsString()) {
                    Utf8Value value(env->isolate(), val.As<String>());
                    vec.push_back(std::string(*value, value.length()));
                }
            }
            return vec;
        }

        inline Local<Array> ToJSStringArray(Environment* env,
            const std::vector<std::string>& vec)
        {
            Isolate* isolate = env->isolate();
            Local<Array> array = Array::New(isolate, vec.size());
            for (size_t n = 0; n < vec.size(); n++)
                array->Set(env->context(), n, Utf8String(isolate, vec[n])).FromJust();
            return array;
        }

        static Local<v8::String> CreateV8String(Environment* env, const char* name)
        {
            return v8::String::NewFromOneByte(env->isolate(), (const uint8_t*)name, v8::NewStringType::kNormal, -1).ToLocalChecked();
        }

        inline url_data HarvestBase(Environment* env, Local<Object> base_obj)
        {
            url_data base;
            Local<Context> context = env->context();
            Local<Value> flags = base_obj->Get(env->context(), env->flags_string()).ToLocalChecked();
            if (flags->IsInt32())
                base.flags = flags->Int32Value(context).FromJust();

            Local<Value> scheme = base_obj->Get(env->context(), CreateV8String(env, "scheme")).ToLocalChecked();
            base.scheme = Utf8Value(env->isolate(), scheme).out();

            auto GetStr = [&](std::string url_data::*member,
                              int flag,
                              Local<String> name) {
                Local<Value> value = base_obj->Get(env->context(), name).ToLocalChecked();
                if (value->IsString()) {
                    Utf8Value utf8value(env->isolate(), value.As<String>());
                    (base.*member).assign(*utf8value, utf8value.length());
                    base.flags |= flag;
                }
            };
            GetStr(&url_data::username, URL_FLAGS_HAS_USERNAME, CreateV8String(env, "username"));
            GetStr(&url_data::password, URL_FLAGS_HAS_PASSWORD, CreateV8String(env, "password"));
            GetStr(&url_data::host, URL_FLAGS_HAS_HOST, CreateV8String(env, "host"));
            GetStr(&url_data::query, URL_FLAGS_HAS_QUERY, CreateV8String(env, "query"));
            GetStr(&url_data::fragment, URL_FLAGS_HAS_FRAGMENT, CreateV8String(env, "fragment"));

            Local<Value> port = base_obj->Get(env->context(), CreateV8String(env, "port")).ToLocalChecked();
            if (port->IsInt32())
                base.port = port.As<Int32>()->Value();

            Local<Value>
                path = base_obj->Get(env->context(), CreateV8String(env, "path")).ToLocalChecked();
            if (path->IsArray()) {
                base.flags |= URL_FLAGS_HAS_PATH;
                base.path = FromJSStringArray(env, path.As<Array>());
            }
            return base;
        }

        inline url_data HarvestContext(Environment* env, Local<Object> context_obj)
        {
            url_data context;
            Local<Value> flags = context_obj->Get(env->context(), env->flags_string()).ToLocalChecked();
            if (flags->IsInt32()) {
                static const int32_t copy_flags_mask = URL_FLAGS_SPECIAL | URL_FLAGS_CANNOT_BE_BASE | URL_FLAGS_HAS_USERNAME | URL_FLAGS_HAS_PASSWORD | URL_FLAGS_HAS_HOST;
                context.flags |= flags.As<Int32>()->Value() & copy_flags_mask;
            }
            Local<Value> scheme = context_obj->Get(env->context(), CreateV8String(env, "scheme")).ToLocalChecked();
            if (scheme->IsString()) {
                Utf8Value value(env->isolate(), scheme);
                context.scheme.assign(*value, value.length());
            }
            Local<Value> port = context_obj->Get(env->context(), CreateV8String(env, "port")).ToLocalChecked();
            if (port->IsInt32())
                context.port = port.As<Int32>()->Value();
            if (context.flags & URL_FLAGS_HAS_USERNAME) {
                Local<Value> username = context_obj->Get(env->context(),
                                                       env->username_string())
                                            .ToLocalChecked();
                NODE_CHECK(username->IsString());
                Utf8Value value(env->isolate(), username);
                context.username.assign(*value, value.length());
            }
            if (context.flags & URL_FLAGS_HAS_PASSWORD) {
                Local<Value> password = context_obj->Get(env->context(), CreateV8String(env, "password")).ToLocalChecked();
                NODE_CHECK(password->IsString());
                Utf8Value value(env->isolate(), password);
                context.password.assign(*value, value.length());
            }
            Local<Value> host = context_obj->Get(env->context(), CreateV8String(env, "host")).ToLocalChecked();
            if (host->IsString()) {
                Utf8Value value(env->isolate(), host);
                context.host.assign(*value, value.length());
            }
            return context;
        }

        // Single dot segment can be ".", "%2e", or "%2E"
        inline bool IsSingleDotSegment(const std::string& str)
        {
            switch (str.size()) {
            case 1:
                return str == ".";
            case 3:
                return str[0] == '%' && str[1] == '2' && ASCIILowercase(str[2]) == 'e';
            default:
                return false;
            }
        }

        // Double dot segment can be:
        //   "..", ".%2e", ".%2E", "%2e.", "%2E.",
        //   "%2e%2e", "%2E%2E", "%2e%2E", or "%2E%2e"
        inline bool IsDoubleDotSegment(const std::string& str)
        {
            switch (str.size()) {
            case 2:
                return str == "..";
            case 4:
                if (str[0] != '.' && str[0] != '%')
                    return false;
                return ((str[0] == '.' && str[1] == '%' && str[2] == '2' && ASCIILowercase(str[3]) == 'e') || (str[0] == '%' && str[1] == '2' && ASCIILowercase(str[2]) == 'e' && str[3] == '.'));
            case 6:
                return (str[0] == '%' && str[1] == '2' && ASCIILowercase(str[2]) == 'e' && str[3] == '%' && str[4] == '2' && ASCIILowercase(str[5]) == 'e');
            default:
                return false;
            }
        }

        inline void ShortenUrlPath(struct url_data* url)
        {
            if (url->path.empty())
                return;
            if (url->path.size() == 1 && url->scheme == "file:" && IsNormalizedWindowsDriveLetter(url->path[0]))
                return;
            url->path.pop_back();
        }

    } // anonymous namespace

    void URL::Parse(const char* input,
        size_t len,
        enum url_parse_state state_override,
        struct url_data* url,
        bool has_url,
        const struct url_data* base,
        bool has_base)
    {
        const char* p = input;
        const char* end = input + len;

        if (!has_url) {
            for (const char* ptr = p; ptr < end; ptr++) {
                if (IsC0ControlOrSpace(*ptr))
                    p++;
                else
                    break;
            }
            for (const char* ptr = end - 1; ptr >= p; ptr--) {
                if (IsC0ControlOrSpace(*ptr))
                    end--;
                else
                    break;
            }
            len = end - p;
        }

        // The spec says we should strip out any ASCII tabs or newlines.
        // In those cases, we create another std::string instance with the filtered
        // contents, but in the general case we avoid the overhead.
        std::string whitespace_stripped;
        for (const char* ptr = p; ptr < end; ptr++) {
            if (!IsASCIITabOrNewline(*ptr))
                continue;
            // Hit tab or newline. Allocate storage, copy what we have until now,
            // and then iterate and filter all similar characters out.
            whitespace_stripped.reserve(len - 1);
            whitespace_stripped.assign(p, ptr - p);
            // 'ptr + 1' skips the current char, which we know to be tab or newline.
            for (ptr = ptr + 1; ptr < end; ptr++) {
                if (!IsASCIITabOrNewline(*ptr))
                    whitespace_stripped += *ptr;
            }

            // Update variables like they should have looked like if the string
            // had been stripped of whitespace to begin with.
            input = whitespace_stripped.c_str();
            len = whitespace_stripped.size();
            p = input;
            end = input + len;
            break;
        }

        bool atflag = false; // Set when @ has been seen.
        bool square_bracket_flag = false; // Set inside of [...]
        bool password_token_seen_flag = false; // Set after a : after an username.

        std::string buffer;

        // Set the initial parse state.
        const bool has_state_override = state_override != kUnknownState;
        enum url_parse_state state = has_state_override ? state_override : kSchemeStart;

        if (state < kSchemeStart || state > kFragment) {
            url->flags |= URL_FLAGS_INVALID_PARSE_STATE;
            return;
        }

        while (p <= end) {
            const char ch = p < end ? p[0] : kEOL;
            bool special = (url->flags & URL_FLAGS_SPECIAL);
            bool cannot_be_base;
            const bool special_back_slash = (special && ch == '\\');

            switch (state) {
            case kSchemeStart:
                if (IsASCIIAlpha(ch)) {
                    buffer += ASCIILowercase(ch);
                    state = kScheme;
                } else if (!has_state_override) {
                    state = kNoScheme;
                    continue;
                } else {
                    url->flags |= URL_FLAGS_FAILED;
                    return;
                }
                break;
            case kScheme:
                if (IsASCIIAlphanumeric(ch) || ch == '+' || ch == '-' || ch == '.') {
                    buffer += ASCIILowercase(ch);
                } else if (ch == ':' || (has_state_override && ch == kEOL)) {
                    if (has_state_override && buffer.size() == 0) {
                        url->flags |= URL_FLAGS_TERMINATED;
                        return;
                    }
                    buffer += ':';

                    bool new_is_special = IsSpecial(buffer);

                    if (has_state_override) {
                        if ((special != new_is_special) || ((buffer == "file:") && ((url->flags & URL_FLAGS_HAS_USERNAME) || (url->flags & URL_FLAGS_HAS_PASSWORD) || (url->port != -1)))) {
                            url->flags |= URL_FLAGS_TERMINATED;
                            return;
                        }

                        // File scheme && (host == empty or null) check left to JS-land
                        // as it can be done before even entering C++ binding.
                    }

                    url->scheme = std::move(buffer);
                    url->port = NormalizePort(url->scheme, url->port);
                    if (new_is_special) {
                        url->flags |= URL_FLAGS_SPECIAL;
                        special = true;
                    } else {
                        url->flags &= ~URL_FLAGS_SPECIAL;
                        special = false;
                    }
                    buffer = "";
                    if (has_state_override)
                        return;
                    if (url->scheme == "file:") {
                        state = kFile;
                    } else if (special && has_base && url->scheme == base->scheme) {
                        state = kSpecialRelativeOrAuthority;
                    } else if (special) {
                        state = kSpecialAuthoritySlashes;
                    } else if (p[1] == '/') {
                        state = kPathOrAuthority;
                        p++;
                    } else {
                        url->flags |= URL_FLAGS_CANNOT_BE_BASE;
                        url->flags |= URL_FLAGS_HAS_PATH;
                        url->path.push_back("");
                        state = kCannotBeBase;
                    }
                } else if (!has_state_override) {
                    buffer = "";
                    state = kNoScheme;
                    p = input;
                    continue;
                } else {
                    url->flags |= URL_FLAGS_FAILED;
                    return;
                }
                break;
            case kNoScheme:
                cannot_be_base = has_base && (base->flags & URL_FLAGS_CANNOT_BE_BASE);
                if (!has_base || (cannot_be_base && ch != '#')) {
                    url->flags |= URL_FLAGS_FAILED;
                    return;
                } else if (cannot_be_base && ch == '#') {
                    url->scheme = base->scheme;
                    if (IsSpecial(url->scheme)) {
                        url->flags |= URL_FLAGS_SPECIAL;
                        special = true;
                    } else {
                        url->flags &= ~URL_FLAGS_SPECIAL;
                        special = false;
                    }
                    if (base->flags & URL_FLAGS_HAS_PATH) {
                        url->flags |= URL_FLAGS_HAS_PATH;
                        url->path = base->path;
                    }
                    if (base->flags & URL_FLAGS_HAS_QUERY) {
                        url->flags |= URL_FLAGS_HAS_QUERY;
                        url->query = base->query;
                    }
                    if (base->flags & URL_FLAGS_HAS_FRAGMENT) {
                        url->flags |= URL_FLAGS_HAS_FRAGMENT;
                        url->fragment = base->fragment;
                    }
                    url->flags |= URL_FLAGS_CANNOT_BE_BASE;
                    state = kFragment;
                } else if (has_base && base->scheme != "file:") {
                    state = kRelative;
                    continue;
                } else {
                    url->scheme = "file:";
                    url->flags |= URL_FLAGS_SPECIAL;
                    special = true;
                    state = kFile;
                    continue;
                }
                break;
            case kSpecialRelativeOrAuthority:
                if (ch == '/' && p[1] == '/') {
                    state = kSpecialAuthorityIgnoreSlashes;
                    p++;
                } else {
                    state = kRelative;
                    continue;
                }
                break;
            case kPathOrAuthority:
                if (ch == '/') {
                    state = kAuthority;
                } else {
                    state = kPath;
                    continue;
                }
                break;
            case kRelative:
                url->scheme = base->scheme;
                if (IsSpecial(url->scheme)) {
                    url->flags |= URL_FLAGS_SPECIAL;
                    special = true;
                } else {
                    url->flags &= ~URL_FLAGS_SPECIAL;
                    special = false;
                }
                switch (ch) {
                case kEOL:
                    if (base->flags & URL_FLAGS_HAS_USERNAME) {
                        url->flags |= URL_FLAGS_HAS_USERNAME;
                        url->username = base->username;
                    }
                    if (base->flags & URL_FLAGS_HAS_PASSWORD) {
                        url->flags |= URL_FLAGS_HAS_PASSWORD;
                        url->password = base->password;
                    }
                    if (base->flags & URL_FLAGS_HAS_HOST) {
                        url->flags |= URL_FLAGS_HAS_HOST;
                        url->host = base->host;
                    }
                    if (base->flags & URL_FLAGS_HAS_QUERY) {
                        url->flags |= URL_FLAGS_HAS_QUERY;
                        url->query = base->query;
                    }
                    if (base->flags & URL_FLAGS_HAS_PATH) {
                        url->flags |= URL_FLAGS_HAS_PATH;
                        url->path = base->path;
                    }
                    url->port = base->port;
                    break;
                case '/':
                    state = kRelativeSlash;
                    break;
                case '?':
                    if (base->flags & URL_FLAGS_HAS_USERNAME) {
                        url->flags |= URL_FLAGS_HAS_USERNAME;
                        url->username = base->username;
                    }
                    if (base->flags & URL_FLAGS_HAS_PASSWORD) {
                        url->flags |= URL_FLAGS_HAS_PASSWORD;
                        url->password = base->password;
                    }
                    if (base->flags & URL_FLAGS_HAS_HOST) {
                        url->flags |= URL_FLAGS_HAS_HOST;
                        url->host = base->host;
                    }
                    if (base->flags & URL_FLAGS_HAS_PATH) {
                        url->flags |= URL_FLAGS_HAS_PATH;
                        url->path = base->path;
                    }
                    url->port = base->port;
                    state = kQuery;
                    break;
                case '#':
                    if (base->flags & URL_FLAGS_HAS_USERNAME) {
                        url->flags |= URL_FLAGS_HAS_USERNAME;
                        url->username = base->username;
                    }
                    if (base->flags & URL_FLAGS_HAS_PASSWORD) {
                        url->flags |= URL_FLAGS_HAS_PASSWORD;
                        url->password = base->password;
                    }
                    if (base->flags & URL_FLAGS_HAS_HOST) {
                        url->flags |= URL_FLAGS_HAS_HOST;
                        url->host = base->host;
                    }
                    if (base->flags & URL_FLAGS_HAS_QUERY) {
                        url->flags |= URL_FLAGS_HAS_QUERY;
                        url->query = base->query;
                    }
                    if (base->flags & URL_FLAGS_HAS_PATH) {
                        url->flags |= URL_FLAGS_HAS_PATH;
                        url->path = base->path;
                    }
                    url->port = base->port;
                    state = kFragment;
                    break;
                default:
                    if (special_back_slash) {
                        state = kRelativeSlash;
                    } else {
                        if (base->flags & URL_FLAGS_HAS_USERNAME) {
                            url->flags |= URL_FLAGS_HAS_USERNAME;
                            url->username = base->username;
                        }
                        if (base->flags & URL_FLAGS_HAS_PASSWORD) {
                            url->flags |= URL_FLAGS_HAS_PASSWORD;
                            url->password = base->password;
                        }
                        if (base->flags & URL_FLAGS_HAS_HOST) {
                            url->flags |= URL_FLAGS_HAS_HOST;
                            url->host = base->host;
                        }
                        if (base->flags & URL_FLAGS_HAS_PATH) {
                            url->flags |= URL_FLAGS_HAS_PATH;
                            url->path = base->path;
                            ShortenUrlPath(url);
                        }
                        url->port = base->port;
                        state = kPath;
                        continue;
                    }
                }
                break;
            case kRelativeSlash:
                if (IsSpecial(url->scheme) && (ch == '/' || ch == '\\')) {
                    state = kSpecialAuthorityIgnoreSlashes;
                } else if (ch == '/') {
                    state = kAuthority;
                } else {
                    if (base->flags & URL_FLAGS_HAS_USERNAME) {
                        url->flags |= URL_FLAGS_HAS_USERNAME;
                        url->username = base->username;
                    }
                    if (base->flags & URL_FLAGS_HAS_PASSWORD) {
                        url->flags |= URL_FLAGS_HAS_PASSWORD;
                        url->password = base->password;
                    }
                    if (base->flags & URL_FLAGS_HAS_HOST) {
                        url->flags |= URL_FLAGS_HAS_HOST;
                        url->host = base->host;
                    }
                    url->port = base->port;
                    state = kPath;
                    continue;
                }
                break;
            case kSpecialAuthoritySlashes:
                state = kSpecialAuthorityIgnoreSlashes;
                if (ch == '/' && p[1] == '/') {
                    p++;
                } else {
                    continue;
                }
                break;
            case kSpecialAuthorityIgnoreSlashes:
                if (ch != '/' && ch != '\\') {
                    state = kAuthority;
                    continue;
                }
                break;
            case kAuthority:
                if (ch == '@') {
                    if (atflag) {
                        buffer.reserve(buffer.size() + 3);
                        buffer.insert(0, "%40");
                    }
                    atflag = true;
                    const size_t blen = buffer.size();
                    if (blen > 0 && buffer[0] != ':') {
                        url->flags |= URL_FLAGS_HAS_USERNAME;
                    }
                    for (size_t n = 0; n < blen; n++) {
                        const char bch = buffer[n];
                        if (bch == ':') {
                            url->flags |= URL_FLAGS_HAS_PASSWORD;
                            if (!password_token_seen_flag) {
                                password_token_seen_flag = true;
                                continue;
                            }
                        }
                        if (password_token_seen_flag) {
                            AppendOrEscape(&url->password, bch, USERINFO_ENCODE_SET);
                        } else {
                            AppendOrEscape(&url->username, bch, USERINFO_ENCODE_SET);
                        }
                    }
                    buffer = "";
                } else if (ch == kEOL || ch == '/' || ch == '?' || ch == '#' || special_back_slash) {
                    if (atflag && buffer.size() == 0) {
                        url->flags |= URL_FLAGS_FAILED;
                        return;
                    }
                    p -= buffer.size() + 1;
                    buffer = "";
                    state = kHost;
                } else {
                    buffer += ch;
                }
                break;
            case kHost:
            case kHostname:
                if (has_state_override && url->scheme == "file:") {
                    state = kFileHost;
                    continue;
                } else if (ch == ':' && !square_bracket_flag) {
                    if (buffer.size() == 0) {
                        url->flags |= URL_FLAGS_FAILED;
                        return;
                    }
                    url->flags |= URL_FLAGS_HAS_HOST;
                    if (!ParseHost(buffer, &url->host, special)) {
                        url->flags |= URL_FLAGS_FAILED;
                        return;
                    }
                    buffer = "";
                    state = kPort;
                    if (state_override == kHostname) {
                        return;
                    }
                } else if (ch == kEOL || ch == '/' || ch == '?' || ch == '#' || special_back_slash) {
                    p--;
                    if (special && buffer.size() == 0) {
                        url->flags |= URL_FLAGS_FAILED;
                        return;
                    }
                    if (has_state_override && buffer.size() == 0 && ((url->username.size() > 0 || url->password.size() > 0) || url->port != -1)) {
                        url->flags |= URL_FLAGS_TERMINATED;
                        return;
                    }
                    url->flags |= URL_FLAGS_HAS_HOST;
                    if (!ParseHost(buffer, &url->host, special)) {
                        url->flags |= URL_FLAGS_FAILED;
                        return;
                    }
                    buffer = "";
                    state = kPathStart;
                    if (has_state_override) {
                        return;
                    }
                } else {
                    if (ch == '[')
                        square_bracket_flag = true;
                    if (ch == ']')
                        square_bracket_flag = false;
                    buffer += ch;
                }
                break;
            case kPort:
                if (IsASCIIDigit(ch)) {
                    buffer += ch;
                } else if (has_state_override || ch == kEOL || ch == '/' || ch == '?' || ch == '#' || special_back_slash) {
                    if (buffer.size() > 0) {
                        unsigned port = 0;
                        // the condition port <= 0xffff prevents integer overflow
                        for (size_t i = 0; port <= 0xffff && i < buffer.size(); i++)
                            port = port * 10 + buffer[i] - '0';
                        if (port > 0xffff) {
                            // TODO(TimothyGu): This hack is currently needed for the host
                            // setter since it needs access to hostname if it is valid, and
                            // if the FAILED flag is set the entire response to JS layer
                            // will be empty.
                            if (state_override == kHost)
                                url->port = -1;
                            else
                                url->flags |= URL_FLAGS_FAILED;
                            return;
                        }
                        // the port is valid
                        url->port = NormalizePort(url->scheme, static_cast<int>(port));
                        if (url->port == -1)
                            url->flags |= URL_FLAGS_IS_DEFAULT_SCHEME_PORT;
                        buffer = "";
                    } else if (has_state_override) {
                        // TODO(TimothyGu): Similar case as above.
                        if (state_override == kHost)
                            url->port = -1;
                        else
                            url->flags |= URL_FLAGS_TERMINATED;
                        return;
                    }
                    state = kPathStart;
                    continue;
                } else {
                    url->flags |= URL_FLAGS_FAILED;
                    return;
                }
                break;
            case kFile:
                url->scheme = "file:";
                if (ch == '/' || ch == '\\') {
                    state = kFileSlash;
                } else if (has_base && base->scheme == "file:") {
                    switch (ch) {
                    case kEOL:
                        if (base->flags & URL_FLAGS_HAS_HOST) {
                            url->flags |= URL_FLAGS_HAS_HOST;
                            url->host = base->host;
                        }
                        if (base->flags & URL_FLAGS_HAS_PATH) {
                            url->flags |= URL_FLAGS_HAS_PATH;
                            url->path = base->path;
                        }
                        if (base->flags & URL_FLAGS_HAS_QUERY) {
                            url->flags |= URL_FLAGS_HAS_QUERY;
                            url->query = base->query;
                        }
                        break;
                    case '?':
                        if (base->flags & URL_FLAGS_HAS_HOST) {
                            url->flags |= URL_FLAGS_HAS_HOST;
                            url->host = base->host;
                        }
                        if (base->flags & URL_FLAGS_HAS_PATH) {
                            url->flags |= URL_FLAGS_HAS_PATH;
                            url->path = base->path;
                        }
                        url->flags |= URL_FLAGS_HAS_QUERY;
                        url->query = "";
                        state = kQuery;
                        break;
                    case '#':
                        if (base->flags & URL_FLAGS_HAS_HOST) {
                            url->flags |= URL_FLAGS_HAS_HOST;
                            url->host = base->host;
                        }
                        if (base->flags & URL_FLAGS_HAS_PATH) {
                            url->flags |= URL_FLAGS_HAS_PATH;
                            url->path = base->path;
                        }
                        if (base->flags & URL_FLAGS_HAS_QUERY) {
                            url->flags |= URL_FLAGS_HAS_QUERY;
                            url->query = base->query;
                        }
                        url->flags |= URL_FLAGS_HAS_FRAGMENT;
                        url->fragment = "";
                        state = kFragment;
                        break;
                    default:
                        if (!StartsWithWindowsDriveLetter(p, end)) {
                            if (base->flags & URL_FLAGS_HAS_HOST) {
                                url->flags |= URL_FLAGS_HAS_HOST;
                                url->host = base->host;
                            }
                            if (base->flags & URL_FLAGS_HAS_PATH) {
                                url->flags |= URL_FLAGS_HAS_PATH;
                                url->path = base->path;
                            }
                            ShortenUrlPath(url);
                        }
                        state = kPath;
                        continue;
                    }
                } else {
                    state = kPath;
                    continue;
                }
                break;
            case kFileSlash:
                if (ch == '/' || ch == '\\') {
                    state = kFileHost;
                } else {
                    if (has_base && base->scheme == "file:" && !StartsWithWindowsDriveLetter(p, end)) {
                        if (IsNormalizedWindowsDriveLetter(base->path[0])) {
                            url->flags |= URL_FLAGS_HAS_PATH;
                            url->path.push_back(base->path[0]);
                        } else {
                            if (base->flags & URL_FLAGS_HAS_HOST) {
                                url->flags |= URL_FLAGS_HAS_HOST;
                                url->host = base->host;
                            } else {
                                url->flags &= ~URL_FLAGS_HAS_HOST;
                                url->host = "";
                            }
                        }
                    }
                    state = kPath;
                    continue;
                }
                break;
            case kFileHost:
                if (ch == kEOL || ch == '/' || ch == '\\' || ch == '?' || ch == '#') {
                    if (!has_state_override && buffer.size() == 2 && IsWindowsDriveLetter(buffer)) {
                        state = kPath;
                    } else if (buffer.size() == 0) {
                        url->flags |= URL_FLAGS_HAS_HOST;
                        url->host = "";
                        if (has_state_override)
                            return;
                        state = kPathStart;
                    } else {
                        std::string host;
                        if (!ParseHost(buffer, &host, special)) {
                            url->flags |= URL_FLAGS_FAILED;
                            return;
                        }
                        if (host == "localhost")
                            host = "";
                        url->flags |= URL_FLAGS_HAS_HOST;
                        url->host = host;
                        if (has_state_override)
                            return;
                        buffer = "";
                        state = kPathStart;
                    }
                    continue;
                } else {
                    buffer += ch;
                }
                break;
            case kPathStart:
                if (IsSpecial(url->scheme)) {
                    state = kPath;
                    if (ch != '/' && ch != '\\') {
                        continue;
                    }
                } else if (!has_state_override && ch == '?') {
                    url->flags |= URL_FLAGS_HAS_QUERY;
                    url->query = "";
                    state = kQuery;
                } else if (!has_state_override && ch == '#') {
                    url->flags |= URL_FLAGS_HAS_FRAGMENT;
                    url->fragment = "";
                    state = kFragment;
                } else if (ch != kEOL) {
                    state = kPath;
                    if (ch != '/') {
                        continue;
                    }
                }
                break;
            case kPath:
                if (ch == kEOL || ch == '/' || special_back_slash || (!has_state_override && (ch == '?' || ch == '#'))) {
                    if (IsDoubleDotSegment(buffer)) {
                        ShortenUrlPath(url);
                        if (ch != '/' && !special_back_slash) {
                            url->flags |= URL_FLAGS_HAS_PATH;
                            url->path.push_back("");
                        }
                    } else if (IsSingleDotSegment(buffer) && ch != '/' && !special_back_slash) {
                        url->flags |= URL_FLAGS_HAS_PATH;
                        url->path.push_back("");
                    } else if (!IsSingleDotSegment(buffer)) {
                        if (url->scheme == "file:" && url->path.empty() && buffer.size() == 2 && IsWindowsDriveLetter(buffer)) {
                            if ((url->flags & URL_FLAGS_HAS_HOST) && !url->host.empty()) {
                                url->host = "";
                                url->flags |= URL_FLAGS_HAS_HOST;
                            }
                            buffer[1] = ':';
                        }
                        url->flags |= URL_FLAGS_HAS_PATH;
                        url->path.push_back(/*std::move*/ (buffer));
                    }
                    buffer = "";
                    if (url->scheme == "file:" && (ch == kEOL || ch == '?' || ch == '#')) {
                        while (url->path.size() > 1 && url->path[0].length() == 0) {
                            url->path.erase(url->path.begin());
                        }
                    }
                    if (ch == '?') {
                        url->flags |= URL_FLAGS_HAS_QUERY;
                        state = kQuery;
                    } else if (ch == '#') {
                        state = kFragment;
                    }
                } else {
                    AppendOrEscape(&buffer, ch, PATH_ENCODE_SET);
                }
                break;
            case kCannotBeBase:
                switch (ch) {
                case '?':
                    state = kQuery;
                    break;
                case '#':
                    state = kFragment;
                    break;
                default:
                    if (url->path.size() == 0)
                        url->path.push_back("");
                    if (url->path.size() > 0 && ch != kEOL)
                        AppendOrEscape(&url->path[0], ch, C0_CONTROL_ENCODE_SET);
                }
                break;
            case kQuery:
                if (ch == kEOL || (!has_state_override && ch == '#')) {
                    url->flags |= URL_FLAGS_HAS_QUERY;
                    url->query = std::move(buffer);
                    buffer = "";
                    if (ch == '#')
                        state = kFragment;
                } else {
                    AppendOrEscape(&buffer, ch, QUERY_ENCODE_SET);
                }
                break;
            case kFragment:
                switch (ch) {
                case kEOL:
                    url->flags |= URL_FLAGS_HAS_FRAGMENT;
                    url->fragment = std::move(buffer);
                    break;
                case 0:
                    break;
                default:
                    AppendOrEscape(&buffer, ch, FRAGMENT_ENCODE_SET);
                }
                break;
            default:
                url->flags |= URL_FLAGS_INVALID_PARSE_STATE;
                return;
            }

            p++;
        }
    } // NOLINT(readability/fn_size)

    static inline void SetArgs(Environment* env,
        Local<Value> argv[ARG_COUNT],
        const struct url_data& url)
    {
        Isolate* isolate = env->isolate();
        argv[ARG_FLAGS] = Integer::NewFromUnsigned(isolate, url.flags);
        argv[ARG_PROTOCOL] = OneByteString(isolate, url.scheme.c_str());
        if (url.flags & URL_FLAGS_HAS_USERNAME)
            argv[ARG_USERNAME] = Utf8String(isolate, url.username);
        if (url.flags & URL_FLAGS_HAS_PASSWORD)
            argv[ARG_PASSWORD] = Utf8String(isolate, url.password);
        if (url.flags & URL_FLAGS_HAS_HOST)
            argv[ARG_HOST] = Utf8String(isolate, url.host);
        if (url.flags & URL_FLAGS_HAS_QUERY)
            argv[ARG_QUERY] = Utf8String(isolate, url.query);
        if (url.flags & URL_FLAGS_HAS_FRAGMENT)
            argv[ARG_FRAGMENT] = Utf8String(isolate, url.fragment);
        if (url.port > -1)
            argv[ARG_PORT] = Integer::New(isolate, url.port);
        if (url.flags & URL_FLAGS_HAS_PATH)
            argv[ARG_PATH] = ToJSStringArray(env, url.path);
    }

    static void Parse(Environment* env,
        Local<Value> recv,
        const char* input,
        const size_t len,
        enum url_parse_state state_override,
        Local<Value> base_obj,
        Local<Value> context_obj,
        Local<Function> cb,
        Local<Value> error_cb)
    {
        Isolate* isolate = env->isolate();
        Local<Context> context = env->context();
        HandleScope handle_scope(isolate);
        Context::Scope context_scope(context);

        const bool has_context = context_obj->IsObject();
        const bool has_base = base_obj->IsObject();

        url_data base;
        url_data url;
        if (has_context)
            url = HarvestContext(env, context_obj.As<Object>());
        if (has_base)
            base = HarvestBase(env, base_obj.As<Object>());

        URL::Parse(input, len, state_override, &url, has_context, &base, has_base);
        if ((url.flags & URL_FLAGS_INVALID_PARSE_STATE) || ((state_override != kUnknownState) && (url.flags & URL_FLAGS_TERMINATED)))
            return;

        // Define the return value placeholders
        const Local<Value> undef = Undefined(isolate);
        const Local<Value> null = Null(isolate);
        if (!(url.flags & URL_FLAGS_FAILED)) {
            Local<Value> argv[] = {
                undef,
                undef,
                undef,
                undef,
                null, // host defaults to null
                null, // port defaults to null
                undef,
                null, // query defaults to null
                null, // fragment defaults to null
            };
            SetArgs(env, argv, url);
            cb->Call(context, recv, arraysize(argv), argv).FromMaybe(Local<Value>());
        } else if (error_cb->IsFunction()) {
            Local<Value> argv[2] = { undef, undef };
            argv[ERR_ARG_FLAGS] = Integer::NewFromUnsigned(isolate, url.flags);
            argv[ERR_ARG_INPUT] = String::NewFromUtf8(env->isolate(),
                input,
                v8::NewStringType::kNormal)
                                      .ToLocalChecked();
            error_cb.As<Function>()->Call(context, recv, arraysize(argv), argv).FromMaybe(Local<Value>());
        }
    }

    static void Parse(const FunctionCallbackInfo<Value>& args)
    {
        Environment* env = Environment::GetCurrent(args);
        NODE_CHECK_GE(args.Length(), 5);
        NODE_CHECK(args[0]->IsString()); // input
        NODE_CHECK(args[2]->IsUndefined() || // base context
            args[2]->IsNull() || args[2]->IsObject());
        NODE_CHECK(args[3]->IsUndefined() || // context
            args[3]->IsNull() || args[3]->IsObject());
        NODE_CHECK(args[4]->IsFunction()); // complete callback
        NODE_CHECK(args[5]->IsUndefined() || args[5]->IsFunction()); // error callback

        Utf8Value input(env->isolate(), args[0]);
        enum url_parse_state state_override = kUnknownState;
        if (args[1]->IsNumber()) {
            state_override = static_cast<enum url_parse_state>(
                args[1]->Uint32Value(env->context()).FromJust());
        }

        Parse(env, args.This(),
            *input, input.length(),
            state_override,
            args[2],
            args[3],
            args[4].As<Function>(),
            args[5]);
    }

    static void EncodeAuthSet(const FunctionCallbackInfo<Value>& args)
    {
        Environment* env = Environment::GetCurrent(args);
        NODE_CHECK_GE(args.Length(), 1);
        NODE_CHECK(args[0]->IsString());
        Utf8Value value(env->isolate(), args[0]);
        std::string output;
        const size_t len = value.length();
        output.reserve(len);
        for (size_t n = 0; n < len; n++) {
            const char ch = (*value)[n];
            AppendOrEscape(&output, ch, USERINFO_ENCODE_SET);
        }
        args.GetReturnValue().Set(
            String::NewFromUtf8(env->isolate(),
                output.c_str(),
                v8::NewStringType::kNormal)
                .ToLocalChecked());
    }

    static void ToUSVString(const FunctionCallbackInfo<Value>& args)
    {
        Environment* env = Environment::GetCurrent(args);
        NODE_CHECK_GE(args.Length(), 2);
        NODE_CHECK(args[0]->IsString());
        NODE_CHECK(args[1]->IsNumber());

        TwoByteValue value(env->isolate(), args[0]);
        const size_t n = value.length();

        const int64_t start = args[1]->IntegerValue(env->context()).FromJust();
        NODE_CHECK_GE(start, 0);

        for (size_t i = start; i < n; i++) {
            char16_t c = value[i];
            if (!IsUnicodeSurrogate(c)) {
                continue;
            } else if (IsUnicodeSurrogateTrail(c) || i == n - 1) {
                value[i] = kUnicodeReplacementCharacter;
            } else {
                char16_t d = value[i + 1];
                if (IsUnicodeTrail(d)) {
                    i++;
                } else {
                    value[i] = kUnicodeReplacementCharacter;
                }
            }
        }

        args.GetReturnValue().Set(
            String::NewFromTwoByte(env->isolate(),
                *value,
                v8::NewStringType::kNormal,
                n)
                .ToLocalChecked());
    }

    static void DomainToASCII(const FunctionCallbackInfo<Value>& args)
    {
        Environment* env = Environment::GetCurrent(args);
        NODE_CHECK_GE(args.Length(), 1);
        NODE_CHECK(args[0]->IsString());
        Utf8Value value(env->isolate(), args[0]);

        URLHost host;
        // Assuming the host is used for a special scheme.
        host.ParseHost(*value, value.length(), true);
        if (host.ParsingFailed()) {
            args.GetReturnValue().Set(FIXED_ONE_BYTE_STRING(env->isolate(), ""));
            return;
        }
        std::string out = host.ToStringMove();
        args.GetReturnValue().Set(
            String::NewFromUtf8(env->isolate(),
                out.c_str(),
                v8::NewStringType::kNormal)
                .ToLocalChecked());
    }

    static void DomainToUnicode(const FunctionCallbackInfo<Value>& args)
    {
        Environment* env = Environment::GetCurrent(args);
        NODE_CHECK_GE(args.Length(), 1);
        NODE_CHECK(args[0]->IsString());
        Utf8Value value(env->isolate(), args[0]);

        URLHost host;
        // Assuming the host is used for a special scheme.
        host.ParseHost(*value, value.length(), true, true);
        if (host.ParsingFailed()) {
            args.GetReturnValue().Set(FIXED_ONE_BYTE_STRING(env->isolate(), ""));
            return;
        }
        std::string out = host.ToStringMove();
        args.GetReturnValue().Set(
            String::NewFromUtf8(env->isolate(),
                out.c_str(),
                v8::NewStringType::kNormal)
                .ToLocalChecked());
    }

    std::string URL::ToFilePath() const
    {
        if (context_.scheme != "file:") {
            return "";
        }

#ifdef _WIN32
        const char* slash = "\\";
        auto is_slash = [](char ch) {
            return ch == '/' || ch == '\\';
        };
#else
        const char* slash = "/";
        auto is_slash = [](char ch) {
            return ch == '/';
        };
        if ((context_.flags & URL_FLAGS_HAS_HOST) && context_.host.length() > 0) {
            return "";
        }
#endif
        std::string decoded_path;
        for (const std::string& part : context_.path) {
            std::string decoded = PercentDecode(part.c_str(), part.length());
            for (char& ch : decoded) {
                if (is_slash(ch)) {
                    return "";
                }
            }
            decoded_path += slash + decoded;
        }

#ifdef _WIN32
        // TODO(TimothyGu): Use "\\?\" long paths on Windows.

        // If hostname is set, then we have a UNC path. Pass the hostname through
        // ToUnicode just in case it is an IDN using punycode encoding. We do not
        // need to worry about percent encoding because the URL parser will have
        // already taken care of that for us. Note that this only causes IDNs with an
        // appropriate `xn--` prefix to be decoded.
        if ((context_.flags & URL_FLAGS_HAS_HOST) && context_.host.length() > 0) {
            std::string unicode_host;
            if (!ToUnicode(context_.host, &unicode_host)) {
                return "";
            }
            return "\\\\" + unicode_host + decoded_path;
        }
        // Otherwise, it's a local path that requires a drive letter.
        if (decoded_path.length() < 3) {
            return "";
        }
        if (decoded_path[2] != ':' || !IsASCIIAlpha(decoded_path[1])) {
            return "";
        }
        // Strip out the leading '\'.
        return decoded_path.substr(1);
#else
        return decoded_path;
#endif
    }

    // This function works by calling out to a JS function that creates and
    // returns the JS URL object. Be mindful of the JS<->Native boundary
    // crossing that is required.
    const Local<Value> URL::ToObject(Environment* env) const
    {
        Isolate* isolate = env->isolate();
        Local<Context> context = env->context();
        Context::Scope context_scope(context);

        const Local<Value> undef = Undefined(isolate);
        const Local<Value> null = Null(isolate);

        if (context_.flags & URL_FLAGS_FAILED)
            return Local<Value>();

        Local<Value> argv[] = {
            undef,
            undef,
            undef,
            undef,
            null, // host defaults to null
            null, // port defaults to null
            undef,
            null, // query defaults to null
            null, // fragment defaults to null
        };
        SetArgs(env, argv, context_);

        MaybeLocal<Value> ret;
        {
            FatalTryCatch try_catch(env);

            // The SetURLConstructor method must have been called already to
            // set the constructor function used below. SetURLConstructor is
            // called automatically when the internal/url.js module is loaded
            // during the internal/bootstrap/node.js processing.
            ret = env->url_constructor_function()
                      ->Call(env->context(), undef, arraysize(argv), argv);
        }

        return ret.ToLocalChecked();
    }

    static void SetURLConstructor(const FunctionCallbackInfo<Value>& args)
    {
        Environment* env = Environment::GetCurrent(args);
        NODE_CHECK_EQ(args.Length(), 1);
        NODE_CHECK(args[0]->IsFunction());
        env->set_url_constructor_function(args[0].As<Function>());
    }

    static void Initialize(Local<Object> target,
        Local<Value> unused,
        Local<Context> context,
        void* priv)
    {
        Environment* env = Environment::GetCurrent(context);
        env->SetMethod(target, "parse", Parse);
        env->SetMethod(target, "encodeAuth", EncodeAuthSet);
        env->SetMethod(target, "toUSVString", ToUSVString);
        env->SetMethod(target, "domainToASCII", DomainToASCII);
        env->SetMethod(target, "domainToUnicode", DomainToUnicode);
        env->SetMethod(target, "setURLConstructor", SetURLConstructor);

#define XX(name, _) NODE_DEFINE_CONSTANT(target, name);
        FLAGS(XX)
#undef XX

#define XX(name) NODE_DEFINE_CONSTANT(target, name);
        PARSESTATES(XX)
#undef XX
    }
} // namespace url
} // namespace node

//NODE_BUILTIN_MODULE_CONTEXT_AWARE(url, node::url::Initialize)
NODE_MODULE_CONTEXT_AWARE_BUILTIN(url, node::url::Initialize)
