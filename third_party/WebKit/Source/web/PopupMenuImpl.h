// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PopupMenuImpl_h
#define PopupMenuImpl_h

<<<<<<< HEAD
=======
#include "core/html/forms/PopupMenuClient.h"
>>>>>>> miniblink49
#include "core/page/PagePopupClient.h"
#include "platform/PopupMenu.h"

namespace blink {

class ChromeClientImpl;
class PagePopup;
class HTMLElement;
class HTMLHRElement;
class HTMLOptGroupElement;
class HTMLOptionElement;
<<<<<<< HEAD
class HTMLSelectElement;

class PopupMenuImpl final : public PopupMenu, public PagePopupClient {
public:
    static PopupMenuImpl* create(ChromeClientImpl*, HTMLSelectElement&);
    ~PopupMenuImpl() override;
    DECLARE_VIRTUAL_TRACE();
=======

class PopupMenuImpl final : public PopupMenu, public PagePopupClient {
public:
    static PassRefPtrWillBeRawPtr<PopupMenuImpl> create(ChromeClientImpl*, PopupMenuClient*);
    ~PopupMenuImpl() override;
>>>>>>> miniblink49

    void update();

    void dispose();

private:
<<<<<<< HEAD
    PopupMenuImpl(ChromeClientImpl*, HTMLSelectElement&);
=======
    PopupMenuImpl(ChromeClientImpl*, PopupMenuClient*);
>>>>>>> miniblink49

    class ItemIterationContext;
    void addOption(ItemIterationContext&, HTMLOptionElement&);
    void addOptGroup(ItemIterationContext&, HTMLOptGroupElement&);
    void addSeparator(ItemIterationContext&, HTMLHRElement&);
    void addElementStyle(ItemIterationContext&, HTMLElement&);

    // PopupMenu functions:
<<<<<<< HEAD
    void show() override;
    void hide() override;
    void disconnectClient() override;
    void updateFromElement(UpdateReason) override;

    // PagePopupClient functions:
=======
    void show(const FloatQuad& controlPosition, const IntSize& controlSize, int index) override;
    void hide() override;
    void disconnectClient() override;
    void updateFromElement() override;

    // PagePopupClient functions:
    IntSize contentSize() override;
>>>>>>> miniblink49
    void writeDocument(SharedBuffer*) override;
    void selectFontsFromOwnerDocument(Document&) override;
    void setValueAndClosePopup(int, const String&) override;
    void setValue(const String&) override;
    void closePopup() override;
    Element& ownerElement() override;
<<<<<<< HEAD
    float zoomFactor() override { return 1.0; }
    Locale& locale() override;
    void didClosePopup() override;

    Member<ChromeClientImpl> m_chromeClient;
    Member<HTMLSelectElement> m_ownerElement;
=======
    Locale& locale() override;
    void didClosePopup() override;

    ChromeClientImpl* m_chromeClient;
    PopupMenuClient* m_client;
>>>>>>> miniblink49
    PagePopup* m_popup;
    bool m_needsUpdate;
};

<<<<<<< HEAD
} // namespace blink
=======
}
>>>>>>> miniblink49

#endif // PopupMenuImpl_h
