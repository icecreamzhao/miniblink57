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

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/crypto/DOMWindowCrypto.h"

#include "core/frame/LocalDOMWindow.h"
#include "modules/crypto/Crypto.h"

namespace blink {

DOMWindowCrypto::DOMWindowCrypto(LocalDOMWindow& window)
<<<<<<< HEAD
    : Supplement<LocalDOMWindow>(window)
{
}

=======
    : DOMWindowProperty(window.frame())
{
}

DEFINE_EMPTY_DESTRUCTOR_WILL_BE_REMOVED(DOMWindowCrypto);

>>>>>>> miniblink49
const char* DOMWindowCrypto::supplementName()
{
    return "DOMWindowCrypto";
}

DOMWindowCrypto& DOMWindowCrypto::from(LocalDOMWindow& window)
{
<<<<<<< HEAD
    DOMWindowCrypto* supplement = static_cast<DOMWindowCrypto*>(
        Supplement<LocalDOMWindow>::from(window, supplementName()));
    if (!supplement) {
        supplement = new DOMWindowCrypto(window);
        provideTo(window, supplementName(), supplement);
=======
    DOMWindowCrypto* supplement = static_cast<DOMWindowCrypto*>(WillBeHeapSupplement<LocalDOMWindow>::from(window, supplementName()));
    if (!supplement) {
        supplement = new DOMWindowCrypto(window);
        provideTo(window, supplementName(), adoptPtrWillBeNoop(supplement));
>>>>>>> miniblink49
    }
    return *supplement;
}

Crypto* DOMWindowCrypto::crypto(DOMWindow& window)
{
    return DOMWindowCrypto::from(toLocalDOMWindow(window)).crypto();
}

Crypto* DOMWindowCrypto::crypto() const
{
<<<<<<< HEAD
    if (!m_crypto)
=======
    if (!m_crypto && frame())
>>>>>>> miniblink49
        m_crypto = Crypto::create();
    return m_crypto.get();
}

DEFINE_TRACE(DOMWindowCrypto)
{
    visitor->trace(m_crypto);
<<<<<<< HEAD
    Supplement<LocalDOMWindow>::trace(visitor);
=======
    WillBeHeapSupplement<LocalDOMWindow>::trace(visitor);
    DOMWindowProperty::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
