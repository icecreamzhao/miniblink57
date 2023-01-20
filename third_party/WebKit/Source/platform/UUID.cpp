<<<<<<< HEAD
// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "platform/UUID.h"

#include "base/guid.h"
#include "wtf/text/StringUTF8Adaptor.h"
=======
/*
* Copyright (C) 2010 Google Inc. All rights reserved.
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

#include "config.h"
#include "platform/UUID.h"

#include "wtf/CryptographicallyRandomNumber.h"
#include "wtf/HexNumber.h"
#include "wtf/text/StringBuilder.h"
>>>>>>> miniblink49

namespace blink {

String createCanonicalUUIDString()
{
<<<<<<< HEAD
    std::string uuid = base::GenerateGUID();
    return String::fromUTF8(uuid.data(), uuid.length());
=======
    unsigned randomData[4];
    cryptographicallyRandomValues(reinterpret_cast<unsigned char*>(randomData), sizeof(randomData));

    // Format as Version 4 UUID.
    StringBuilder builder;
    builder.reserveCapacity(36);
    appendUnsignedAsHexFixedSize(randomData[0], builder, 8, Lowercase);
    builder.append('-');
    appendUnsignedAsHexFixedSize(randomData[1] >> 16, builder, 4, Lowercase);
    builder.appendLiteral("-4");
    appendUnsignedAsHexFixedSize(randomData[1] & 0x00000fff, builder, 3, Lowercase);
    builder.append('-');
    appendUnsignedAsHexFixedSize((randomData[2] >> 30) | 0x8, builder, 1, Lowercase);
    appendUnsignedAsHexFixedSize((randomData[2] >> 16) & 0x00000fff, builder, 3, Lowercase);
    builder.append('-');
    appendUnsignedAsHexFixedSize(randomData[2] & 0x0000ffff, builder, 4, Lowercase);
    appendUnsignedAsHexFixedSize(randomData[3], builder, 8, Lowercase);
    return builder.toString();
}

static bool isLowercaseHex(char c)
{
    return (('0' <= c && c <= '9') || ('a' <= c && c <= 'f'));
>>>>>>> miniblink49
}

bool isValidUUID(const String& uuid)
{
<<<<<<< HEAD
    // In most (if not all) cases the given uuid should be utf-8, so this
    // conversion should be almost no-op.
    StringUTF8Adaptor utf8(uuid);
    return base::IsValidGUIDOutputString(utf8.asStringPiece());
}

} // namespace blink
=======
    // 32 digits + 4 hyphens = 36 characters.
    if (uuid.length() != 36)
        return false;

    for (size_t i = 0; i < uuid.length(); i++) {
        if (i == 8 || i == 13 || i == 18 || i == 23) {
            if (uuid[i] != '-')
                return false;
        } else {
            if (!isLowercaseHex(uuid[i]))
                return false;
        }
    }

    return true;
}

}
>>>>>>> miniblink49
