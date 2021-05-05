/*
 * DES & Triple DES EDE Cipher Algorithms.
 */

#ifndef __CRYPTO_DES_H
#define __CRYPTO_DES_H

namespace net {

typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

#define DES_KEY_SIZE 8
#define DES_EXPKEY_WORDS 32
#define DES_BLOCK_SIZE 8

#define DES3_EDE_KEY_SIZE (3 * DES_KEY_SIZE)
#define DES3_EDE_EXPKEY_WORDS (3 * DES_EXPKEY_WORDS)
#define DES3_EDE_BLOCK_SIZE DES_BLOCK_SIZE

struct des_ctx {
    u32 expkey[DES_EXPKEY_WORDS];
};

struct des3_ede_ctx {
    u32 expkey[DES3_EDE_EXPKEY_WORDS];
};

class DesUtil {

public:
    DesUtil(const char* encryptKey);
    ~DesUtil();
    int encrypt_domain(const char* domain, char** outData, int outLen);
    int decrypt_result(const char* results, char** outData, int outLen);

private:
    int des_setkey(struct des_ctx* ctx, const u8* key, unsigned int keylen);
    void des_encrypt(struct des_ctx* ctx, u8* dst, const u8* src);
    void des_decrypt(struct des_ctx* ctx, u8* dst, const u8* src);

    int des3_ede_setkey(struct des3_ede_ctx* dctx, const u8* key, unsigned int keylen);
    void des3_ede_encrypt(struct des3_ede_ctx* dctx, u8* dst, const u8* src);
    void des3_ede_decrypt(struct des3_ede_ctx* dctx, u8* dst, const u8* src);

    int encrypt_str(struct des_ctx* ctx, const unsigned char* src, unsigned int src_len, unsigned char* dest);
    int decrypt_str(struct des_ctx* ctx, const unsigned char* src, unsigned int src_len, unsigned char* dest);

    int StrToUChar(const char* src, unsigned char* dst);
    int UCharToStr(const unsigned char* src, unsigned int len, char* dst);
    unsigned long des_ekey(u32* pe, const u8* k);
    void dkey(u32* pe, const u8* k);
    int CharToValue(char ch);

private:
    struct des_ctx ctx_;
    unsigned char* encrypt_buf_;
    unsigned char* decrypt_buf_;
    static const int BUF_SIZE;
};
}
#endif /* __CRYPTO_DES_H */
