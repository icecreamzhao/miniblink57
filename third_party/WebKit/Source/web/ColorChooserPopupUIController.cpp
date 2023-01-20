/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
#include "web/ColorChooserPopupUIController.h"

#include "core/frame/FrameView.h"
#include "core/frame/LocalFrame.h"
=======
#include "config.h"
#include "web/ColorChooserPopupUIController.h"

#include "core/frame/FrameView.h"
>>>>>>> miniblink49
#include "core/html/forms/ColorChooserClient.h"
#include "core/page/PagePopup.h"
#include "platform/geometry/IntRect.h"
#include "public/platform/Platform.h"
#include "public/web/WebColorChooser.h"
#include "web/ChromeClientImpl.h"
#include "web/WebViewImpl.h"

namespace blink {

// Keep in sync with Actions in colorSuggestionPicker.js.
enum ColorPickerPopupAction {
    ColorPickerPopupActionChooseOtherColor = -2,
    ColorPickerPopupActionCancel = -1,
    ColorPickerPopupActionSetValue = 0
};

<<<<<<< HEAD
ColorChooserPopupUIController::ColorChooserPopupUIController(
    LocalFrame* frame,
    ChromeClientImpl* chromeClient,
    ColorChooserClient* client)
    : ColorChooserUIController(frame, client)
    , m_chromeClient(chromeClient)
    , m_popup(nullptr)
=======
ColorChooserPopupUIController::ColorChooserPopupUIController(LocalFrame* frame, ChromeClientImpl* chromeClient, ColorChooserClient* client)
    : ColorChooserUIController(frame, client)
    , m_chromeClient(chromeClient)
    , m_popup(0)
>>>>>>> miniblink49
    , m_locale(Locale::defaultLocale())
{
}

<<<<<<< HEAD
ColorChooserPopupUIController::~ColorChooserPopupUIController() { }

void ColorChooserPopupUIController::dispose()
{
    // Finalized earlier so as to access m_chromeClient while alive.
    closePopup();
    // ~ColorChooserUIController calls endChooser().
}

DEFINE_TRACE(ColorChooserPopupUIController)
{
    visitor->trace(m_chromeClient);
    ColorChooserUIController::trace(visitor);
=======
ColorChooserPopupUIController::~ColorChooserPopupUIController()
{
    closePopup();
    // ~ColorChooserUIController ends the ColorChooser.
>>>>>>> miniblink49
}

void ColorChooserPopupUIController::openUI()
{
    if (m_client->shouldShowSuggestions())
        openPopup();
    else
        openColorChooser();
}

void ColorChooserPopupUIController::endChooser()
{
    if (m_chooser)
        m_chooser->endChooser();

    closePopup();
}

AXObject* ColorChooserPopupUIController::rootAXObject()
{
<<<<<<< HEAD
    //return m_popup ? m_popup->rootAXObject() : nullptr;
    DebugBreak();
    return nullptr;
=======
    return m_popup ? m_popup->rootAXObject() : 0;
}

IntSize ColorChooserPopupUIController::contentSize()
{
    return IntSize(0, 0);
>>>>>>> miniblink49
}

void ColorChooserPopupUIController::writeDocument(SharedBuffer* data)
{
    Vector<ColorSuggestion> suggestions = m_client->suggestions();
    Vector<String> suggestionValues;
    for (unsigned i = 0; i < suggestions.size(); i++)
<<<<<<< HEAD
        suggestionValues.push_back(suggestions[i].color.serialized());
    IntRect anchorRectInScreen = m_chromeClient->viewportToScreen(
        m_client->elementRectRelativeToViewport(), m_frame->view());

    PagePopupClient::addString(
        "<!DOCTYPE html><head><meta charset='UTF-8'><style>\n", data);
    data->append(Platform::current()->loadResource("pickerCommon.css"));
    data->append(Platform::current()->loadResource("colorSuggestionPicker.css"));
    PagePopupClient::addString(
        "</style></head><body><div id=main>Loading...</div><script>\n"
        "window.dialogArguments = {\n",
        data);
    PagePopupClient::addProperty("values", suggestionValues, data);
    PagePopupClient::addProperty(
        "otherColorLabel",
        locale().queryString(WebLocalizedString::OtherColorLabel), data);
    addProperty("anchorRectInScreen", anchorRectInScreen, data);
    addProperty("zoomFactor", zoomFactor(), data);
=======
        suggestionValues.append(suggestions[i].color.serialized());
    IntRect anchorRectInScreen = m_chromeClient->viewportToScreen(m_client->elementRectRelativeToViewport());

    PagePopupClient::addString("<!DOCTYPE html><head><meta charset='UTF-8'><style>\n", data);
    data->append(Platform::current()->loadResource("pickerCommon.css"));
    data->append(Platform::current()->loadResource("colorSuggestionPicker.css"));
    PagePopupClient::addString("</style></head><body><div id=main>Loading...</div><script>\n"
        "window.dialogArguments = {\n", data);
    PagePopupClient::addProperty("values", suggestionValues, data);
    PagePopupClient::addProperty("otherColorLabel", locale().queryString(WebLocalizedString::OtherColorLabel), data);
    addProperty("anchorRectInScreen", anchorRectInScreen, data);
>>>>>>> miniblink49
    PagePopupClient::addString("};\n", data);
    data->append(Platform::current()->loadResource("pickerCommon.js"));
    data->append(Platform::current()->loadResource("colorSuggestionPicker.js"));
    PagePopupClient::addString("</script></body>\n", data);
}

Locale& ColorChooserPopupUIController::locale()
{
    return m_locale;
}

<<<<<<< HEAD
void ColorChooserPopupUIController::setValueAndClosePopup(
    int numValue,
    const String& stringValue)
{
    DCHECK(m_popup);
    DCHECK(m_client);
=======
void ColorChooserPopupUIController::setValueAndClosePopup(int numValue, const String& stringValue)
{
    ASSERT(m_popup);
    ASSERT(m_client);
>>>>>>> miniblink49
    if (numValue == ColorPickerPopupActionSetValue)
        setValue(stringValue);
    if (numValue == ColorPickerPopupActionChooseOtherColor)
        openColorChooser();
    closePopup();
}

void ColorChooserPopupUIController::setValue(const String& value)
{
<<<<<<< HEAD
    DCHECK(m_client);
    Color color;
    bool success = color.setFromString(value);
    DCHECK(success);
=======
    ASSERT(m_client);
    Color color;
    bool success = color.setFromString(value);
    ASSERT_UNUSED(success, success);
>>>>>>> miniblink49
    m_client->didChooseColor(color);
}

void ColorChooserPopupUIController::didClosePopup()
{
<<<<<<< HEAD
    m_popup = nullptr;
=======
    m_popup = 0;
>>>>>>> miniblink49

    if (!m_chooser)
        didEndChooser();
}

Element& ColorChooserPopupUIController::ownerElement()
{
    return m_client->ownerElement();
}

void ColorChooserPopupUIController::openPopup()
{
<<<<<<< HEAD
    DCHECK(!m_popup);
=======
    ASSERT(!m_popup);
>>>>>>> miniblink49
    m_popup = m_chromeClient->openPagePopup(this);
}

void ColorChooserPopupUIController::closePopup()
{
    if (!m_popup)
        return;
    m_chromeClient->closePagePopup(m_popup);
}

} // namespace blink
