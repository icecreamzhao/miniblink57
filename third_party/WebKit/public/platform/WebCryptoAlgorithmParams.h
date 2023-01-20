/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WebCryptoAlgorithmParams_h
#define WebCryptoAlgorithmParams_h

#include "WebCommon.h"
#include "WebCryptoAlgorithm.h"
#include "WebCryptoKey.h"
#include "WebVector.h"
<<<<<<< HEAD
#include "base/logging.h"
=======
>>>>>>> miniblink49

namespace blink {

// NOTE: For documentation on the meaning of each of the parameters see the
//       Web crypto spec:
//
//       http://www.w3.org/TR/WebCryptoAPI
//
//       For the most part, the parameters in the spec have the same name,
//       except that in the blink code:
//
//         - Structure names are prefixed by "WebCrypto"
//         - Optional fields are prefixed by "optional"
//         - Data length properties are suffixed by either "Bits" or "Bytes"

class WebCryptoAlgorithmParams {
public:
    WebCryptoAlgorithmParams() { }
    virtual ~WebCryptoAlgorithmParams() { }
    virtual WebCryptoAlgorithmParamsType type() const = 0;
};

class WebCryptoAesCbcParams : public WebCryptoAlgorithmParams {
public:
<<<<<<< HEAD
    explicit WebCryptoAesCbcParams(WebVector<unsigned char> iv)
        : m_iv(std::move(iv))
    {
    }

    virtual WebCryptoAlgorithmParamsType type() const
    {
        return WebCryptoAlgorithmParamsTypeAesCbcParams;
    }
=======
    WebCryptoAesCbcParams(const unsigned char* iv, unsigned ivSize)
        : m_iv(iv, ivSize)
    {
    }

    virtual WebCryptoAlgorithmParamsType type() const { return WebCryptoAlgorithmParamsTypeAesCbcParams; }
>>>>>>> miniblink49

    const WebVector<unsigned char>& iv() const { return m_iv; }

private:
    const WebVector<unsigned char> m_iv;
};

class WebCryptoAlgorithmParamsWithHash : public WebCryptoAlgorithmParams {
public:
    explicit WebCryptoAlgorithmParamsWithHash(const WebCryptoAlgorithm& hash)
        : m_hash(hash)
    {
<<<<<<< HEAD
        DCHECK(!hash.isNull());
=======
        BLINK_ASSERT(!hash.isNull());
>>>>>>> miniblink49
    }

    const WebCryptoAlgorithm& hash() const { return m_hash; }

private:
    const WebCryptoAlgorithm m_hash;
};

class WebCryptoAesCtrParams : public WebCryptoAlgorithmParams {
public:
<<<<<<< HEAD
    WebCryptoAesCtrParams(unsigned char lengthBits,
        WebVector<unsigned char> counter)
        : WebCryptoAlgorithmParams()
        , m_counter(std::move(counter))
=======
    WebCryptoAesCtrParams(unsigned char lengthBits, const unsigned char* counter, unsigned counterSize)
        : WebCryptoAlgorithmParams()
        , m_counter(counter, counterSize)
>>>>>>> miniblink49
        , m_lengthBits(lengthBits)
    {
    }

<<<<<<< HEAD
    virtual WebCryptoAlgorithmParamsType type() const
    {
        return WebCryptoAlgorithmParamsTypeAesCtrParams;
    }
=======
    virtual WebCryptoAlgorithmParamsType type() const { return WebCryptoAlgorithmParamsTypeAesCtrParams; }
>>>>>>> miniblink49

    const WebVector<unsigned char>& counter() const { return m_counter; }
    unsigned char lengthBits() const { return m_lengthBits; }

private:
    const WebVector<unsigned char> m_counter;
    const unsigned char m_lengthBits;
};

class WebCryptoAesKeyGenParams : public WebCryptoAlgorithmParams {
public:
    explicit WebCryptoAesKeyGenParams(unsigned short lengthBits)
        : m_lengthBits(lengthBits)
    {
    }

<<<<<<< HEAD
    virtual WebCryptoAlgorithmParamsType type() const
    {
        return WebCryptoAlgorithmParamsTypeAesKeyGenParams;
    }
=======
    virtual WebCryptoAlgorithmParamsType type() const { return WebCryptoAlgorithmParamsTypeAesKeyGenParams; }
>>>>>>> miniblink49

    unsigned short lengthBits() const { return m_lengthBits; }

private:
    const unsigned short m_lengthBits;
};

class WebCryptoHmacImportParams : public WebCryptoAlgorithmParamsWithHash {
public:
<<<<<<< HEAD
    // FIXME: Remove this constructor once it is no longer used by Chromium.
    // http://crbug.com/431085
=======
    // FIXME: Remove this constructor once it is no longer used by Chromium. http://crbug.com/431085
>>>>>>> miniblink49
    explicit WebCryptoHmacImportParams(const WebCryptoAlgorithm& hash)
        : WebCryptoAlgorithmParamsWithHash(hash)
        , m_hasLengthBits(false)
        , m_optionalLengthBits(0)
    {
    }

<<<<<<< HEAD
    WebCryptoHmacImportParams(const WebCryptoAlgorithm& hash,
        bool hasLengthBits,
        unsigned lengthBits)
=======
    WebCryptoHmacImportParams(const WebCryptoAlgorithm& hash, bool hasLengthBits, unsigned lengthBits)
>>>>>>> miniblink49
        : WebCryptoAlgorithmParamsWithHash(hash)
        , m_hasLengthBits(hasLengthBits)
        , m_optionalLengthBits(lengthBits)
    {
<<<<<<< HEAD
        DCHECK(hasLengthBits || !lengthBits);
    }

    virtual WebCryptoAlgorithmParamsType type() const
    {
        return WebCryptoAlgorithmParamsTypeHmacImportParams;
    }
=======
        BLINK_ASSERT(hasLengthBits || !lengthBits);
    }

    virtual WebCryptoAlgorithmParamsType type() const { return WebCryptoAlgorithmParamsTypeHmacImportParams; }
>>>>>>> miniblink49

    bool hasLengthBits() const { return m_hasLengthBits; }

    unsigned optionalLengthBits() const { return m_optionalLengthBits; }

private:
    const bool m_hasLengthBits;
    const unsigned m_optionalLengthBits;
};

class WebCryptoHmacKeyGenParams : public WebCryptoAlgorithmParamsWithHash {
public:
<<<<<<< HEAD
    WebCryptoHmacKeyGenParams(const WebCryptoAlgorithm& hash,
        bool hasLengthBits,
        unsigned lengthBits)
=======
    WebCryptoHmacKeyGenParams(const WebCryptoAlgorithm& hash, bool hasLengthBits, unsigned lengthBits)
>>>>>>> miniblink49
        : WebCryptoAlgorithmParamsWithHash(hash)
        , m_hasLengthBits(hasLengthBits)
        , m_optionalLengthBits(lengthBits)
    {
<<<<<<< HEAD
        DCHECK(hasLengthBits || !lengthBits);
    }

    virtual WebCryptoAlgorithmParamsType type() const
    {
        return WebCryptoAlgorithmParamsTypeHmacKeyGenParams;
    }
=======
        BLINK_ASSERT(hasLengthBits || !lengthBits);
    }

    virtual WebCryptoAlgorithmParamsType type() const { return WebCryptoAlgorithmParamsTypeHmacKeyGenParams; }
>>>>>>> miniblink49

    bool hasLengthBits() const { return m_hasLengthBits; }

    unsigned optionalLengthBits() const { return m_optionalLengthBits; }

private:
    const bool m_hasLengthBits;
    const unsigned m_optionalLengthBits;
};

class WebCryptoAesGcmParams : public WebCryptoAlgorithmParams {
public:
<<<<<<< HEAD
    WebCryptoAesGcmParams(WebVector<unsigned char> iv,
        bool hasAdditionalData,
        WebVector<unsigned char> additionalData,
        bool hasTagLengthBits,
        unsigned char tagLengthBits)
        : m_iv(std::move(iv))
        , m_hasAdditionalData(hasAdditionalData)
        , m_optionalAdditionalData(std::move(additionalData))
        , m_hasTagLengthBits(hasTagLengthBits)
        , m_optionalTagLengthBits(tagLengthBits)
    {
        DCHECK(hasAdditionalData || m_optionalAdditionalData.isEmpty());
        DCHECK(hasTagLengthBits || !tagLengthBits);
    }

    virtual WebCryptoAlgorithmParamsType type() const
    {
        return WebCryptoAlgorithmParamsTypeAesGcmParams;
    }
=======
    WebCryptoAesGcmParams(const unsigned char* iv, unsigned ivSize, bool hasAdditionalData, const unsigned char* additionalData, unsigned additionalDataSize, bool hasTagLengthBits, unsigned char tagLengthBits)
        : m_iv(iv, ivSize)
        , m_hasAdditionalData(hasAdditionalData)
        , m_optionalAdditionalData(additionalData, additionalDataSize)
        , m_hasTagLengthBits(hasTagLengthBits)
        , m_optionalTagLengthBits(tagLengthBits)
    {
        BLINK_ASSERT(hasAdditionalData || !additionalDataSize);
        BLINK_ASSERT(hasTagLengthBits || !tagLengthBits);
    }

    virtual WebCryptoAlgorithmParamsType type() const { return WebCryptoAlgorithmParamsTypeAesGcmParams; }
>>>>>>> miniblink49

    const WebVector<unsigned char>& iv() const { return m_iv; }

    bool hasAdditionalData() const { return m_hasAdditionalData; }
<<<<<<< HEAD
    const WebVector<unsigned char>& optionalAdditionalData() const
    {
        return m_optionalAdditionalData;
    }
=======
    const WebVector<unsigned char>& optionalAdditionalData() const { return m_optionalAdditionalData; }
>>>>>>> miniblink49

    bool hasTagLengthBits() const { return m_hasTagLengthBits; }
    unsigned optionalTagLengthBits() const { return m_optionalTagLengthBits; }

private:
    const WebVector<unsigned char> m_iv;
    const bool m_hasAdditionalData;
    const WebVector<unsigned char> m_optionalAdditionalData;
    const bool m_hasTagLengthBits;
    const unsigned char m_optionalTagLengthBits;
};

class WebCryptoRsaHashedImportParams : public WebCryptoAlgorithmParamsWithHash {
public:
    explicit WebCryptoRsaHashedImportParams(const WebCryptoAlgorithm& hash)
        : WebCryptoAlgorithmParamsWithHash(hash)
    {
    }

<<<<<<< HEAD
    virtual WebCryptoAlgorithmParamsType type() const
    {
        return WebCryptoAlgorithmParamsTypeRsaHashedImportParams;
    }
=======
    virtual WebCryptoAlgorithmParamsType type() const { return WebCryptoAlgorithmParamsTypeRsaHashedImportParams; }
>>>>>>> miniblink49
};

class WebCryptoRsaHashedKeyGenParams : public WebCryptoAlgorithmParams {
public:
<<<<<<< HEAD
    WebCryptoRsaHashedKeyGenParams(const WebCryptoAlgorithm& hash,
        unsigned modulusLengthBits,
        WebVector<unsigned char> publicExponent)
        : m_modulusLengthBits(modulusLengthBits)
        , m_publicExponent(std::move(publicExponent))
        , m_hash(hash)
    {
        DCHECK(!hash.isNull());
    }

    virtual WebCryptoAlgorithmParamsType type() const
    {
        return WebCryptoAlgorithmParamsTypeRsaHashedKeyGenParams;
    }

    unsigned modulusLengthBits() const { return m_modulusLengthBits; }
    const WebVector<unsigned char>& publicExponent() const
    {
        return m_publicExponent;
    }
    const WebCryptoAlgorithm& hash() const { return m_hash; }

    // Converts the public exponent (big-endian WebCrypto BigInteger),
    // with or without leading zeros, to unsigned int. Returns true on success.
    bool convertPublicExponentToUnsigned(unsigned& result) const
    {
        result = 0;
        for (size_t i = 0; i < m_publicExponent.size(); ++i) {
            size_t iReversed = m_publicExponent.size() - i - 1;

            if (iReversed >= sizeof(result) && m_publicExponent[i])
                return false; // Too large for unsigned int.

            result |= m_publicExponent[i] << 8 * iReversed;
        }
        return true;
    }

=======
    explicit WebCryptoRsaHashedKeyGenParams(const WebCryptoAlgorithm& hash, unsigned modulusLengthBits, const unsigned char* publicExponent, unsigned publicExponentSize)
        : m_modulusLengthBits(modulusLengthBits)
        , m_publicExponent(publicExponent, publicExponentSize)
        , m_hash(hash)
    {
        BLINK_ASSERT(!hash.isNull());
    }

    virtual WebCryptoAlgorithmParamsType type() const { return WebCryptoAlgorithmParamsTypeRsaHashedKeyGenParams; }

    unsigned modulusLengthBits() const { return m_modulusLengthBits; }
    const WebVector<unsigned char>& publicExponent() const { return m_publicExponent; }
    const WebCryptoAlgorithm& hash() const { return m_hash; }

>>>>>>> miniblink49
private:
    const unsigned m_modulusLengthBits;
    const WebVector<unsigned char> m_publicExponent;
    const WebCryptoAlgorithm m_hash;
};

class WebCryptoRsaOaepParams : public WebCryptoAlgorithmParams {
public:
<<<<<<< HEAD
    WebCryptoRsaOaepParams(bool hasLabel, WebVector<unsigned char> label)
        : m_hasLabel(hasLabel)
        , m_optionalLabel(std::move(label))
    {
        DCHECK(hasLabel || m_optionalLabel.isEmpty());
    }

    virtual WebCryptoAlgorithmParamsType type() const
    {
        return WebCryptoAlgorithmParamsTypeRsaOaepParams;
    }

    bool hasLabel() const { return m_hasLabel; }
    const WebVector<unsigned char>& optionalLabel() const
    {
        return m_optionalLabel;
    }
=======
    WebCryptoRsaOaepParams(bool hasLabel, const unsigned char* label, unsigned labelSize)
        : m_hasLabel(hasLabel)
        , m_optionalLabel(label, labelSize)
    {
        BLINK_ASSERT(hasLabel || !labelSize);
    }

    virtual WebCryptoAlgorithmParamsType type() const { return WebCryptoAlgorithmParamsTypeRsaOaepParams; }

    bool hasLabel() const { return m_hasLabel; }
    const WebVector<unsigned char>& optionalLabel() const { return m_optionalLabel; }
>>>>>>> miniblink49

private:
    const bool m_hasLabel;
    const WebVector<unsigned char> m_optionalLabel;
};

class WebCryptoRsaPssParams : public WebCryptoAlgorithmParams {
public:
    explicit WebCryptoRsaPssParams(unsigned saltLengthBytes)
        : m_saltLengthBytes(saltLengthBytes)
    {
    }

<<<<<<< HEAD
    virtual WebCryptoAlgorithmParamsType type() const
    {
        return WebCryptoAlgorithmParamsTypeRsaPssParams;
    }
=======
    virtual WebCryptoAlgorithmParamsType type() const { return WebCryptoAlgorithmParamsTypeRsaPssParams; }
>>>>>>> miniblink49

    unsigned saltLengthBytes() const { return m_saltLengthBytes; }

private:
    const unsigned m_saltLengthBytes;
};

class WebCryptoEcdsaParams : public WebCryptoAlgorithmParamsWithHash {
public:
    explicit WebCryptoEcdsaParams(const WebCryptoAlgorithm& hash)
        : WebCryptoAlgorithmParamsWithHash(hash)
    {
    }

<<<<<<< HEAD
    virtual WebCryptoAlgorithmParamsType type() const
    {
        return WebCryptoAlgorithmParamsTypeEcdsaParams;
    }
=======
    virtual WebCryptoAlgorithmParamsType type() const { return WebCryptoAlgorithmParamsTypeEcdsaParams; }
>>>>>>> miniblink49
};

class WebCryptoEcKeyGenParams : public WebCryptoAlgorithmParams {
public:
    explicit WebCryptoEcKeyGenParams(WebCryptoNamedCurve namedCurve)
        : m_namedCurve(namedCurve)
    {
    }

<<<<<<< HEAD
    virtual WebCryptoAlgorithmParamsType type() const
    {
        return WebCryptoAlgorithmParamsTypeEcKeyGenParams;
    }
=======
    virtual WebCryptoAlgorithmParamsType type() const { return WebCryptoAlgorithmParamsTypeEcKeyGenParams; }
>>>>>>> miniblink49

    WebCryptoNamedCurve namedCurve() const { return m_namedCurve; }

private:
    const WebCryptoNamedCurve m_namedCurve;
};

class WebCryptoEcKeyImportParams : public WebCryptoAlgorithmParams {
public:
    explicit WebCryptoEcKeyImportParams(WebCryptoNamedCurve namedCurve)
        : m_namedCurve(namedCurve)
    {
    }

<<<<<<< HEAD
    virtual WebCryptoAlgorithmParamsType type() const
    {
        return WebCryptoAlgorithmParamsTypeEcKeyImportParams;
    }
=======
    virtual WebCryptoAlgorithmParamsType type() const { return WebCryptoAlgorithmParamsTypeEcKeyImportParams; }
>>>>>>> miniblink49

    WebCryptoNamedCurve namedCurve() const { return m_namedCurve; }

private:
    const WebCryptoNamedCurve m_namedCurve;
};

class WebCryptoEcdhKeyDeriveParams : public WebCryptoAlgorithmParams {
public:
    explicit WebCryptoEcdhKeyDeriveParams(const WebCryptoKey& publicKey)
        : m_publicKey(publicKey)
    {
    }

<<<<<<< HEAD
    virtual WebCryptoAlgorithmParamsType type() const
    {
        return WebCryptoAlgorithmParamsTypeEcdhKeyDeriveParams;
    }

    const WebCryptoKey& publicKey() const { return m_publicKey; }
=======
    virtual WebCryptoAlgorithmParamsType type() const { return WebCryptoAlgorithmParamsTypeEcdhKeyDeriveParams; }

    const WebCryptoKey publicKey() const { return m_publicKey; }
>>>>>>> miniblink49

private:
    const WebCryptoKey m_publicKey;
};

class WebCryptoAesDerivedKeyParams : public WebCryptoAlgorithmParams {
public:
    explicit WebCryptoAesDerivedKeyParams(unsigned short lengthBits)
        : m_lengthBits(lengthBits)
    {
    }

<<<<<<< HEAD
    virtual WebCryptoAlgorithmParamsType type() const override
    {
        return WebCryptoAlgorithmParamsTypeAesDerivedKeyParams;
    }
=======
    virtual WebCryptoAlgorithmParamsType type() const override { return WebCryptoAlgorithmParamsTypeAesDerivedKeyParams; }
>>>>>>> miniblink49

    unsigned short lengthBits() const { return m_lengthBits; }

private:
    const unsigned short m_lengthBits;
};

class WebCryptoHkdfParams : public WebCryptoAlgorithmParamsWithHash {
public:
<<<<<<< HEAD
    WebCryptoHkdfParams(const WebCryptoAlgorithm& hash,
        WebVector<unsigned char> salt,
        WebVector<unsigned char> info)
        : WebCryptoAlgorithmParamsWithHash(hash)
        , m_salt(std::move(salt))
        , m_info(std::move(info))
=======
    WebCryptoHkdfParams(const WebCryptoAlgorithm& hash, const unsigned char* salt, unsigned saltSize, const unsigned char* info, unsigned infoSize)
        : WebCryptoAlgorithmParamsWithHash(hash)
        , m_salt(salt, saltSize)
        , m_info(info, infoSize)
>>>>>>> miniblink49
    {
    }

    const WebVector<unsigned char>& salt() const { return m_salt; }

    const WebVector<unsigned char>& info() const { return m_info; }

    virtual WebCryptoAlgorithmParamsType type() const
    {
        return WebCryptoAlgorithmParamsTypeHkdfParams;
    }

private:
    const WebVector<unsigned char> m_salt;
    const WebVector<unsigned char> m_info;
};

class WebCryptoPbkdf2Params : public WebCryptoAlgorithmParamsWithHash {
public:
<<<<<<< HEAD
    WebCryptoPbkdf2Params(const WebCryptoAlgorithm& hash,
        WebVector<unsigned char> salt,
        unsigned iterations)
        : WebCryptoAlgorithmParamsWithHash(hash)
        , m_salt(std::move(salt))
=======
    WebCryptoPbkdf2Params(const WebCryptoAlgorithm& hash, const unsigned char* salt, unsigned saltLength, unsigned iterations)
        : WebCryptoAlgorithmParamsWithHash(hash)
        , m_salt(salt, saltLength)
>>>>>>> miniblink49
        , m_iterations(iterations)
    {
    }

<<<<<<< HEAD
    virtual WebCryptoAlgorithmParamsType type() const
    {
        return WebCryptoAlgorithmParamsTypePbkdf2Params;
    }
=======
    virtual WebCryptoAlgorithmParamsType type() const { return WebCryptoAlgorithmParamsTypePbkdf2Params; }
>>>>>>> miniblink49

    const WebVector<unsigned char>& salt() const { return m_salt; }
    unsigned iterations() const { return m_iterations; }

private:
    const WebVector<unsigned char> m_salt;
    const unsigned m_iterations;
};

} // namespace blink

#endif
