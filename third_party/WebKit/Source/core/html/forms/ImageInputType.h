/*
 * Copyright (C) 2010 Google Inc. All rights reserved.
 * Copyright (C) 2011 Apple Inc. All rights reserved.
 * Copyright (C) 2012 Samsung Electronics. All rights reserved.
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

#ifndef ImageInputType_h
#define ImageInputType_h

#include "core/html/forms/BaseButtonInputType.h"
#include "platform/geometry/IntPoint.h"

namespace blink {

class ImageInputType final : public BaseButtonInputType {
public:
    static InputType* create(HTMLInputElement&);
    virtual PassRefPtr<ComputedStyle> customStyleForLayoutObject(
        PassRefPtr<ComputedStyle>);

private:
    ImageInputType(HTMLInputElement&);
    const AtomicString& formControlType() const override;
    bool isFormDataAppendable() const override;
    void appendToFormData(FormData&) const override;
    String resultForDialogSubmit() const override;
    bool supportsValidation() const override;
    LayoutObject* createLayoutObject(const ComputedStyle&) const override;
    void handleDOMActivateEvent(Event*) override;
    void altAttributeChanged() override;
    void srcAttributeChanged() override;
    void valueAttributeChanged() override;
    void startResourceLoading() override;
    bool shouldRespectAlignAttribute() override;
    bool canBeSuccessfulSubmitButton() override;
    bool isEnumeratable() override;
    bool shouldRespectHeightAndWidthAttributes() override;
    unsigned height() const override;
    unsigned width() const override;
    bool hasLegalLinkAttribute(const QualifiedName&) const override;
    const QualifiedName& subResourceAttributeName() const override;
    void ensureFallbackContent() override;
    void ensurePrimaryContent() override;
    void createShadowSubtree() override;

    void reattachFallbackContent();
    void setUseFallbackContent();
    bool hasFallbackContent() const { return m_useFallbackContent; }

    // Valid only during HTMLFormElement::prepareForSubmission().
    IntPoint m_clickLocation;

    bool m_useFallbackContent;
};

} // namespace blink

#endif // ImageInputType_h
