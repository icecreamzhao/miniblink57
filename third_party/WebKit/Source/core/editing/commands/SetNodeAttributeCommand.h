/*
 * Copyright (C) 2005, 2006, 2008 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SetNodeAttributeCommand_h
#define SetNodeAttributeCommand_h

#include "core/dom/QualifiedName.h"
#include "core/editing/commands/EditCommand.h"

namespace blink {

class SetNodeAttributeCommand final : public SimpleEditCommand {
public:
    static SetNodeAttributeCommand* create(Element* element,
        const QualifiedName& attribute,
        const AtomicString& value)
    {
        return new SetNodeAttributeCommand(element, attribute, value);
    }

    DECLARE_VIRTUAL_TRACE();

private:
    SetNodeAttributeCommand(Element*,
        const QualifiedName& attribute,
        const AtomicString& value);

    void doApply(EditingState*) override;
    void doUnapply() override;

    Member<Element> m_element;
    QualifiedName m_attribute;
    AtomicString m_value;
    AtomicString m_oldValue;
};

} // namespace blink

#endif // SetNodeAttributeCommand_h
