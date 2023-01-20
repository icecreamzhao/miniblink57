// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/Crypto.h"

#include "public/platform/Platform.h"
#include "public/platform/WebCrypto.h"
#include "public/platform/WebCryptoAlgorithm.h"
<<<<<<< HEAD
#include <memory>
=======
>>>>>>> miniblink49

namespace blink {

static WebCryptoAlgorithmId toWebCryptoAlgorithmId(HashAlgorithm algorithm)
{
    switch (algorithm) {
    case HashAlgorithmSha1:
        return WebCryptoAlgorithmIdSha1;
    case HashAlgorithmSha256:
        return WebCryptoAlgorithmIdSha256;
    case HashAlgorithmSha384:
        return WebCryptoAlgorithmIdSha384;
    case HashAlgorithmSha512:
        return WebCryptoAlgorithmIdSha512;
    };

    ASSERT_NOT_REACHED();
    return WebCryptoAlgorithmIdSha256;
}

<<<<<<< HEAD
bool computeDigest(HashAlgorithm algorithm,
    const char* digestable,
    size_t length,
    DigestValue& digestResult)
=======
bool computeDigest(HashAlgorithm algorithm, const char* digestable, size_t length, DigestValue& digestResult)
>>>>>>> miniblink49
{
    WebCryptoAlgorithmId algorithmId = toWebCryptoAlgorithmId(algorithm);
    WebCrypto* crypto = Platform::current()->crypto();
    unsigned char* result;
    unsigned resultSize;

    ASSERT(crypto);

<<<<<<< HEAD
    std::unique_ptr<WebCryptoDigestor> digestor = crypto->createDigestor(algorithmId);
    DCHECK(digestor);
    if (!digestor->consume(reinterpret_cast<const unsigned char*>(digestable),
            length)
        || !digestor->finish(result, resultSize))
=======
    OwnPtr<WebCryptoDigestor> digestor = adoptPtr(crypto->createDigestor(algorithmId));
    if (!digestor.get() || !digestor->consume(reinterpret_cast<const unsigned char*>(digestable), length) || !digestor->finish(result, resultSize))
>>>>>>> miniblink49
        return false;

    digestResult.append(static_cast<uint8_t*>(result), resultSize);
    return true;
}

<<<<<<< HEAD
std::unique_ptr<WebCryptoDigestor> createDigestor(HashAlgorithm algorithm)
{
    return Platform::current()->crypto()->createDigestor(
        toWebCryptoAlgorithmId(algorithm));
=======
PassOwnPtr<WebCryptoDigestor> createDigestor(HashAlgorithm algorithm)
{
    return adoptPtr(Platform::current()->crypto()->createDigestor(toWebCryptoAlgorithmId(algorithm)));
>>>>>>> miniblink49
}

void finishDigestor(WebCryptoDigestor* digestor, DigestValue& digestResult)
{
    unsigned char* result = 0;
    unsigned resultSize = 0;

    if (!digestor->finish(result, resultSize))
        return;

    ASSERT(result);

    digestResult.append(static_cast<uint8_t*>(result), resultSize);
}

} // namespace blink
