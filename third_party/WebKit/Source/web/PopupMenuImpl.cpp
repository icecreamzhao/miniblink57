// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "web/PopupMenuImpl.h"

#include "core/HTMLNames.h"
#include "core/css/CSSFontSelector.h"
#include "core/dom/ElementTraversal.h"
#include "core/dom/ExecutionContextTask.h"
#include "core/dom/NodeComputedStyle.h"
#include "core/dom/StyleEngine.h"
<<<<<<< HEAD
#include "core/dom/TaskRunnerHelper.h"
#include "core/events/ScopedEventQueue.h"
#include "core/frame/FrameView.h"
#include "core/frame/LocalFrame.h"
=======
#include "core/frame/FrameView.h"
>>>>>>> miniblink49
#include "core/html/HTMLHRElement.h"
#include "core/html/HTMLOptGroupElement.h"
#include "core/html/HTMLOptionElement.h"
#include "core/html/HTMLSelectElement.h"
#include "core/html/parser/HTMLParserIdioms.h"
#include "core/layout/LayoutTheme.h"
#include "core/page/PagePopup.h"
#include "platform/geometry/IntRect.h"
#include "platform/text/PlatformLocale.h"
#include "public/platform/Platform.h"
#include "public/web/WebColorChooser.h"
#include "web/ChromeClientImpl.h"
#include "web/WebViewImpl.h"

namespace blink {

namespace {

<<<<<<< HEAD
    const char* fontWeightToString(FontWeight weight)
    {
        switch (weight) {
        case FontWeight100:
            return "100";
        case FontWeight200:
            return "200";
        case FontWeight300:
            return "300";
        case FontWeight400:
            return "400";
        case FontWeight500:
            return "500";
        case FontWeight600:
            return "600";
        case FontWeight700:
            return "700";
        case FontWeight800:
            return "800";
        case FontWeight900:
            return "900";
        }
        NOTREACHED();
        return nullptr;
    }

    // TODO crbug.com/516675 Add stretch to serialization

    const char* fontStyleToString(FontStyle style)
    {
        switch (style) {
        case FontStyleNormal:
            return "normal";
        case FontStyleOblique:
            return "oblique";
        case FontStyleItalic:
            return "italic";
        }
        NOTREACHED();
        return nullptr;
    }

    const char* textTransformToString(ETextTransform transform)
    {
        switch (transform) {
        case ETextTransform::kCapitalize:
            return "capitalize";
        case ETextTransform::kUppercase:
            return "uppercase";
        case ETextTransform::kLowercase:
            return "lowercase";
        case ETextTransform::kNone:
            return "none";
        }
        NOTREACHED();
        return "";
    }

} // anonymous namespace

class PopupMenuCSSFontSelector : public CSSFontSelector,
                                 private CSSFontSelectorClient {
    USING_GARBAGE_COLLECTED_MIXIN(PopupMenuCSSFontSelector);

public:
    static PopupMenuCSSFontSelector* create(Document* document,
        CSSFontSelector* ownerFontSelector)
    {
        return new PopupMenuCSSFontSelector(document, ownerFontSelector);
=======
const char* fontWeightToString(FontWeight weight)
{
    switch (weight) {
    case FontWeight100:
        return "100";
    case FontWeight200:
        return "200";
    case FontWeight300:
        return "300";
    case FontWeight400:
        return "400";
    case FontWeight500:
        return "500";
    case FontWeight600:
        return "600";
    case FontWeight700:
        return "700";
    case FontWeight800:
        return "800";
    case FontWeight900:
        return "900";
    }
    ASSERT_NOT_REACHED();
    return nullptr;
}

const char* fontVariantToString(FontVariant variant)
{
    switch (variant) {
    case FontVariantNormal:
        return "normal";
    case FontVariantSmallCaps:
        return "small-caps";
    }
    ASSERT_NOT_REACHED();
    return nullptr;
}

const char* fontStyleToString(FontStyle style)
{
    switch (style) {
    case FontStyleNormal:
        return "normal";
    case FontStyleItalic:
        return "italic";
    }
    ASSERT_NOT_REACHED();
    return nullptr;
}

const char* textTransformToString(ETextTransform transform)
{
    switch (transform) {
    case CAPITALIZE:
        return "capitalize";
    case UPPERCASE:
        return "uppercase";
    case LOWERCASE:
        return "lowercase";
    case TTNONE:
        return "none";
    }
    ASSERT_NOT_REACHED();
    return "";
}

} // anonymous namespace

class PopupMenuCSSFontSelector : public CSSFontSelector, private CSSFontSelectorClient {
    WILL_BE_USING_GARBAGE_COLLECTED_MIXIN(PopupMenuCSSFontSelector);
public:
    static PassRefPtrWillBeRawPtr<PopupMenuCSSFontSelector> create(Document* document, CSSFontSelector* ownerFontSelector)
    {
        return adoptRefWillBeNoop(new PopupMenuCSSFontSelector(document, ownerFontSelector));
>>>>>>> miniblink49
    }

    ~PopupMenuCSSFontSelector();

    // We don't override willUseFontData() for now because the old PopupListBox
    // only worked with fonts loaded when opening the popup.
<<<<<<< HEAD
    PassRefPtr<FontData> getFontData(const FontDescription&,
        const AtomicString&) override;
=======
    PassRefPtr<FontData> getFontData(const FontDescription&, const AtomicString&) override;
>>>>>>> miniblink49

    DECLARE_VIRTUAL_TRACE();

private:
    PopupMenuCSSFontSelector(Document*, CSSFontSelector*);

    void fontsNeedUpdate(CSSFontSelector*) override;

<<<<<<< HEAD
    Member<CSSFontSelector> m_ownerFontSelector;
};

PopupMenuCSSFontSelector::PopupMenuCSSFontSelector(
    Document* document,
    CSSFontSelector* ownerFontSelector)
=======
    RefPtrWillBeMember<CSSFontSelector> m_ownerFontSelector;
};

PopupMenuCSSFontSelector::PopupMenuCSSFontSelector(Document* document, CSSFontSelector* ownerFontSelector)
>>>>>>> miniblink49
    : CSSFontSelector(document)
    , m_ownerFontSelector(ownerFontSelector)
{
    m_ownerFontSelector->registerForInvalidationCallbacks(this);
}

<<<<<<< HEAD
PopupMenuCSSFontSelector::~PopupMenuCSSFontSelector() { }

PassRefPtr<FontData> PopupMenuCSSFontSelector::getFontData(
    const FontDescription& description,
    const AtomicString& name)
=======
PopupMenuCSSFontSelector::~PopupMenuCSSFontSelector()
{
#if !ENABLE(OILPAN)
    m_ownerFontSelector->unregisterForInvalidationCallbacks(this);
#endif
}

PassRefPtr<FontData> PopupMenuCSSFontSelector::getFontData(const FontDescription& description, const AtomicString& name)
>>>>>>> miniblink49
{
    return m_ownerFontSelector->getFontData(description, name);
}

void PopupMenuCSSFontSelector::fontsNeedUpdate(CSSFontSelector* fontSelector)
{
    dispatchInvalidationCallbacks();
}

DEFINE_TRACE(PopupMenuCSSFontSelector)
{
    visitor->trace(m_ownerFontSelector);
    CSSFontSelector::trace(visitor);
    CSSFontSelectorClient::trace(visitor);
}

// ----------------------------------------------------------------

class PopupMenuImpl::ItemIterationContext {
    STACK_ALLOCATED();
<<<<<<< HEAD

public:
    ItemIterationContext(const ComputedStyle& style, SharedBuffer* buffer)
        : m_baseStyle(style)
        , m_backgroundColor(
              style.visitedDependentColor(CSSPropertyBackgroundColor))
        , m_listIndex(0)
        , m_isInGroup(false)
        , m_buffer(buffer)
    {
        DCHECK(m_buffer);
=======
public:
    ItemIterationContext(const ComputedStyle& style, SharedBuffer* buffer)
        : m_direction(style.direction())
        , m_foregroundColor(style.visitedDependentColor(CSSPropertyColor))
        , m_backgroundColor(style.visitedDependentColor(CSSPropertyBackgroundColor))
        , m_textTransform(style.textTransform())
        , m_fontDescription(style.fontDescription())
        , m_listIndex(0)
        , m_buffer(buffer)
    {
        ASSERT(m_buffer);
>>>>>>> miniblink49
#if OS(LINUX)
        // On other platforms, the <option> background color is the same as the
        // <select> background color. On Linux, that makes the <option>
        // background color very dark, so by default, try to use a lighter
        // background color for <option>s.
        if (LayoutTheme::theme().systemColor(CSSValueButtonface) == m_backgroundColor)
            m_backgroundColor = LayoutTheme::theme().systemColor(CSSValueMenu);
#endif
    }

    void serializeBaseStyle()
    {
<<<<<<< HEAD
        DCHECK(!m_isInGroup);
        PagePopupClient::addString("baseStyle: {", m_buffer);
        addProperty("backgroundColor", m_backgroundColor.serialized(), m_buffer);
        addProperty(
            "color",
            baseStyle().visitedDependentColor(CSSPropertyColor).serialized(),
            m_buffer);
        addProperty("textTransform",
            String(textTransformToString(baseStyle().textTransform())),
            m_buffer);
        addProperty("fontSize", baseFont().computedPixelSize(), m_buffer);
        addProperty("fontStyle", String(fontStyleToString(baseFont().style())),
            m_buffer);
        addProperty("fontVariant",
            baseFont().variantCaps() == FontDescription::SmallCaps
                ? String("small-caps")
                : String(),
            m_buffer);

        PagePopupClient::addString("fontFamily: [", m_buffer);
        for (const FontFamily* f = &baseFont().family(); f; f = f->next()) {
            addJavaScriptString(f->family().getString(), m_buffer);
=======
        PagePopupClient::addString("baseStyle: {", m_buffer);
        addProperty("backgroundColor", m_backgroundColor.serialized(), m_buffer);
        addProperty("color", m_foregroundColor.serialized(), m_buffer);
        addProperty("textTransform", String(textTransformToString(m_textTransform)), m_buffer);
        addProperty("fontSize", fontSize(), m_buffer);
        addProperty("fontStyle", String(fontStyleToString(fontStyle())), m_buffer);
        addProperty("fontVariant", String(fontVariantToString(fontVariant())), m_buffer);

        PagePopupClient::addString("fontFamily: [", m_buffer);
        for (const FontFamily* f = &fontFamily(); f; f = f->next()) {
            addJavaScriptString(f->family().string(), m_buffer);
>>>>>>> miniblink49
            if (f->next())
                PagePopupClient::addString(",", m_buffer);
        }
        PagePopupClient::addString("]", m_buffer);
        PagePopupClient::addString("},\n", m_buffer);
    }

<<<<<<< HEAD
    Color backgroundColor() const
    {
        return m_isInGroup
            ? m_groupStyle->visitedDependentColor(CSSPropertyBackgroundColor)
            : m_backgroundColor;
    }
    // Do not use baseStyle() for background-color, use backgroundColor()
    // instead.
    const ComputedStyle& baseStyle()
    {
        return m_isInGroup ? *m_groupStyle : m_baseStyle;
    }
    const FontDescription& baseFont()
    {
        return m_isInGroup ? m_groupStyle->getFontDescription()
                           : m_baseStyle.getFontDescription();
    }
    void startGroupChildren(const ComputedStyle& groupStyle)
    {
        DCHECK(!m_isInGroup);
        PagePopupClient::addString("children: [", m_buffer);
        m_isInGroup = true;
        m_groupStyle = &groupStyle;
    }
    void finishGroupIfNecessary()
    {
        if (!m_isInGroup)
            return;
        PagePopupClient::addString("],},\n", m_buffer);
        m_isInGroup = false;
        m_groupStyle = nullptr;
    }

    const ComputedStyle& m_baseStyle;
    Color m_backgroundColor;
    const ComputedStyle* m_groupStyle;

    unsigned m_listIndex;
    bool m_isInGroup;
=======
    int fontSize() const { return m_fontDescription.computedPixelSize(); }
    FontStyle fontStyle() const { return m_fontDescription.style(); }
    FontVariant fontVariant() const { return m_fontDescription.variant(); }
    const FontFamily& fontFamily() const { return m_fontDescription.family(); }

    TextDirection m_direction;
    Color m_foregroundColor;
    Color m_backgroundColor;
    ETextTransform m_textTransform;
    const FontDescription& m_fontDescription;

    int m_listIndex;
>>>>>>> miniblink49
    SharedBuffer* m_buffer;
};

// ----------------------------------------------------------------

<<<<<<< HEAD
PopupMenuImpl* PopupMenuImpl::create(ChromeClientImpl* chromeClient,
    HTMLSelectElement& ownerElement)
{
    return new PopupMenuImpl(chromeClient, ownerElement);
}

PopupMenuImpl::PopupMenuImpl(ChromeClientImpl* chromeClient,
    HTMLSelectElement& ownerElement)
    : m_chromeClient(chromeClient)
    , m_ownerElement(ownerElement)
=======
PassRefPtrWillBeRawPtr<PopupMenuImpl> PopupMenuImpl::create(ChromeClientImpl* chromeClient, PopupMenuClient* client)
{
    return adoptRefWillBeNoop(new PopupMenuImpl(chromeClient, client));
}

PopupMenuImpl::PopupMenuImpl(ChromeClientImpl* chromeClient, PopupMenuClient* client)
    : m_chromeClient(chromeClient)
    , m_client(client)
>>>>>>> miniblink49
    , m_popup(nullptr)
    , m_needsUpdate(false)
{
}

PopupMenuImpl::~PopupMenuImpl()
{
<<<<<<< HEAD
    DCHECK(!m_popup);
}

DEFINE_TRACE(PopupMenuImpl)
{
    visitor->trace(m_chromeClient);
    visitor->trace(m_ownerElement);
    PopupMenu::trace(visitor);
=======
    ASSERT(!m_popup);
}

IntSize PopupMenuImpl::contentSize()
{
    return IntSize();
>>>>>>> miniblink49
}

void PopupMenuImpl::writeDocument(SharedBuffer* data)
{
<<<<<<< HEAD
    HTMLSelectElement& ownerElement = *m_ownerElement;
    IntRect anchorRectInScreen = m_chromeClient->viewportToScreen(
        ownerElement.visibleBoundsInVisualViewport(),
        ownerElement.document().view());

    PagePopupClient::addString(
        "<!DOCTYPE html><head><meta charset='UTF-8'><style>\n", data);
    data->append(Platform::current()->loadResource("pickerCommon.css"));
    data->append(Platform::current()->loadResource("listPicker.css"));
    PagePopupClient::addString(
        "</style></head><body><div id=main>Loading...</div><script>\n"
        "window.dialogArguments = {\n",
        data);
    addProperty("selectedIndex", ownerElement.selectedListIndex(), data);
    const ComputedStyle* ownerStyle = ownerElement.computedStyle();
    ItemIterationContext context(*ownerStyle, data);
    context.serializeBaseStyle();
    PagePopupClient::addString("children: [\n", data);
    const HeapVector<Member<HTMLElement>>& items = ownerElement.listItems();
    for (; context.m_listIndex < items.size(); ++context.m_listIndex) {
        Element& child = *items[context.m_listIndex];
        if (!isHTMLOptGroupElement(child.parentNode()))
            context.finishGroupIfNecessary();
        if (isHTMLOptionElement(child))
            addOption(context, toHTMLOptionElement(child));
        else if (isHTMLOptGroupElement(child))
            addOptGroup(context, toHTMLOptGroupElement(child));
        else if (isHTMLHRElement(child))
            addSeparator(context, toHTMLHRElement(child));
    }
    context.finishGroupIfNecessary();
    PagePopupClient::addString("],\n", data);

    addProperty("anchorRectInScreen", anchorRectInScreen, data);
    float scaleFactor = m_chromeClient->windowToViewportScalar(1.f);
    addProperty("zoomFactor", 1, data);
    addProperty("scaleFactor", scaleFactor, data);
    bool isRTL = !ownerStyle->isLeftToRightDirection();
    addProperty("isRTL", isRTL, data);
    addProperty("paddingStart",
        isRTL ? ownerElement.clientPaddingRight().toDouble()
              : ownerElement.clientPaddingLeft().toDouble(),
        data);
=======
    IntRect anchorRectInScreen = m_chromeClient->viewportToScreen(m_client->elementRectRelativeToViewport());

    PagePopupClient::addString("<!DOCTYPE html><head><meta charset='UTF-8'><style>\n", data);
    data->append(Platform::current()->loadResource("pickerCommon.css"));
    data->append(Platform::current()->loadResource("listPicker.css"));
    PagePopupClient::addString("</style></head><body><div id=main>Loading...</div><script>\n"
        "window.dialogArguments = {\n", data);
    addProperty("selectedIndex", m_client->selectedIndex(), data);
    const ComputedStyle* ownerStyle = ownerElement().computedStyle();
    ItemIterationContext context(*ownerStyle, data);
    context.serializeBaseStyle();
    PagePopupClient::addString("children: [\n", data);
    for (HTMLElement& child : Traversal<HTMLElement>::childrenOf(ownerElement())) {
        if (isHTMLOptionElement(child))
            addOption(context, toHTMLOptionElement(child));
        if (isHTMLOptGroupElement(child))
            addOptGroup(context, toHTMLOptGroupElement(child));
        if (isHTMLHRElement(child))
            addSeparator(context, toHTMLHRElement(child));
    }
    PagePopupClient::addString("],\n", data);

    addProperty("anchorRectInScreen", anchorRectInScreen, data);
    bool isRTL = !ownerStyle->isLeftToRightDirection();
    addProperty("isRTL", isRTL, data);
    addProperty("paddingStart", isRTL ? m_client->clientPaddingRight().toDouble() : m_client->clientPaddingLeft().toDouble(), data);
>>>>>>> miniblink49
    PagePopupClient::addString("};\n", data);
    data->append(Platform::current()->loadResource("pickerCommon.js"));
    data->append(Platform::current()->loadResource("listPicker.js"));
    PagePopupClient::addString("</script></body>\n", data);
}

<<<<<<< HEAD
void PopupMenuImpl::addElementStyle(ItemIterationContext& context,
    HTMLElement& element)
{
    const ComputedStyle* style = m_ownerElement->itemComputedStyle(element);
    DCHECK(style);
=======
void PopupMenuImpl::addElementStyle(ItemIterationContext& context, HTMLElement& element)
{
    const ComputedStyle* style = m_client->computedStyleForItem(element);
    ASSERT(style);
>>>>>>> miniblink49
    SharedBuffer* data = context.m_buffer;
    // TODO(tkent): We generate unnecessary "style: {\n},\n" even if no
    // additional style.
    PagePopupClient::addString("style: {\n", data);
<<<<<<< HEAD
    if (style->visibility() == EVisibility::kHidden)
        addProperty("visibility", String("hidden"), data);
    if (style->display() == EDisplay::None)
        addProperty("display", String("none"), data);
    const ComputedStyle& baseStyle = context.baseStyle();
    if (baseStyle.direction() != style->direction()) {
        addProperty(
            "direction",
            String(style->direction() == TextDirection::kRtl ? "rtl" : "ltr"),
            data);
    }
    if (isOverride(style->getUnicodeBidi()))
        addProperty("unicodeBidi", String("bidi-override"), data);
    Color foregroundColor = style->visitedDependentColor(CSSPropertyColor);
    if (baseStyle.visitedDependentColor(CSSPropertyColor) != foregroundColor)
        addProperty("color", foregroundColor.serialized(), data);
    Color backgroundColor = style->visitedDependentColor(CSSPropertyBackgroundColor);
    if (context.backgroundColor() != backgroundColor && backgroundColor != Color::transparent)
        addProperty("backgroundColor", backgroundColor.serialized(), data);
    const FontDescription& baseFont = context.baseFont();
    const FontDescription& fontDescription = style->font().getFontDescription();
    if (baseFont.computedPixelSize() != fontDescription.computedPixelSize()) {
        // We don't use FontDescription::specifiedSize() because this element
        // might have its own zoom level.
        addProperty("fontSize", fontDescription.computedPixelSize(), data);
    }
    // Our UA stylesheet has font-weight:normal for OPTION.
    if (FontWeightNormal != fontDescription.weight())
        addProperty("fontWeight",
            String(fontWeightToString(fontDescription.weight())), data);
    if (baseFont.family() != fontDescription.family()) {
        PagePopupClient::addString("fontFamily: [\n", data);
        for (const FontFamily* f = &fontDescription.family(); f; f = f->next()) {
            addJavaScriptString(f->family().getString(), data);
=======
    if (style->visibility() == HIDDEN)
        addProperty("visibility", String("hidden"), data);
    if (style->display() == NONE)
        addProperty("display", String("none"), data);
    if (context.m_direction != style->direction())
        addProperty("direction", String(style->direction() == RTL ? "rtl" : "ltr"), data);
    if (isOverride(style->unicodeBidi()))
        addProperty("unicodeBidi", String("bidi-override"), data);
    Color foregroundColor = style->visitedDependentColor(CSSPropertyColor);
    if (context.m_foregroundColor != foregroundColor)
        addProperty("color", foregroundColor.serialized(), data);
    Color backgroundColor = style->visitedDependentColor(CSSPropertyBackgroundColor);
    if (context.m_backgroundColor != backgroundColor && backgroundColor != Color::transparent)
        addProperty("backgroundColor", backgroundColor.serialized(), data);
    const FontDescription& fontDescription = style->font().fontDescription();
    if (context.fontSize() != fontDescription.computedPixelSize())
        addProperty("fontSize", fontDescription.computedPixelSize(), data);
    // Our UA stylesheet has font-weight:normal for OPTION.
    if (FontWeightNormal != fontDescription.weight())
        addProperty("fontWeight", String(fontWeightToString(fontDescription.weight())), data);
    if (context.fontFamily() != fontDescription.family()) {
        PagePopupClient::addString("fontFamily: [\n", data);
        for (const FontFamily* f = &fontDescription.family(); f; f = f->next()) {
            addJavaScriptString(f->family().string(), data);
>>>>>>> miniblink49
            if (f->next())
                PagePopupClient::addString(",\n", data);
        }
        PagePopupClient::addString("],\n", data);
    }
<<<<<<< HEAD
    if (baseFont.style() != fontDescription.style())
        addProperty("fontStyle", String(fontStyleToString(fontDescription.style())),
            data);

    if (baseFont.variantCaps() != fontDescription.variantCaps() && fontDescription.variantCaps() == FontDescription::SmallCaps)
        addProperty("fontVariant", String("small-caps"), data);

    if (baseStyle.textTransform() != style->textTransform())
        addProperty("textTransform",
            String(textTransformToString(style->textTransform())), data);
=======
    if (context.fontStyle() != fontDescription.style())
        addProperty("fontStyle", String(fontStyleToString(fontDescription.style())), data);
    if (context.fontVariant() != fontDescription.variant())
        addProperty("fontVariant", String(fontVariantToString(fontDescription.variant())), data);
    if (context.m_textTransform != style->textTransform())
        addProperty("textTransform", String(textTransformToString(style->textTransform())), data);
>>>>>>> miniblink49

    PagePopupClient::addString("},\n", data);
}

<<<<<<< HEAD
void PopupMenuImpl::addOption(ItemIterationContext& context,
    HTMLOptionElement& element)
{
    SharedBuffer* data = context.m_buffer;
    PagePopupClient::addString("{", data);
    addProperty("label", element.displayLabel(), data);
    addProperty("value", context.m_listIndex, data);
=======
void PopupMenuImpl::addOption(ItemIterationContext& context, HTMLOptionElement& element)
{
    SharedBuffer* data = context.m_buffer;
    PagePopupClient::addString("{", data);
    addProperty("label", element.text(), data);
    ASSERT(context.m_listIndex == element.listIndex());
    addProperty("value", context.m_listIndex++, data);
>>>>>>> miniblink49
    if (!element.title().isEmpty())
        addProperty("title", element.title(), data);
    const AtomicString& ariaLabel = element.fastGetAttribute(HTMLNames::aria_labelAttr);
    if (!ariaLabel.isEmpty())
        addProperty("ariaLabel", ariaLabel, data);
    if (element.isDisabledFormControl())
        addProperty("disabled", true, data);
    addElementStyle(context, element);
    PagePopupClient::addString("},", data);
}

<<<<<<< HEAD
void PopupMenuImpl::addOptGroup(ItemIterationContext& context,
    HTMLOptGroupElement& element)
{
    SharedBuffer* data = context.m_buffer;
=======
void PopupMenuImpl::addOptGroup(ItemIterationContext& context, HTMLOptGroupElement& element)
{
    SharedBuffer* data = context.m_buffer;
    ++context.m_listIndex;
>>>>>>> miniblink49
    PagePopupClient::addString("{\n", data);
    PagePopupClient::addString("type: \"optgroup\",\n", data);
    addProperty("label", element.groupLabelText(), data);
    addProperty("title", element.title(), data);
<<<<<<< HEAD
    addProperty("ariaLabel", element.fastGetAttribute(HTMLNames::aria_labelAttr),
        data);
    addProperty("disabled", element.isDisabledFormControl(), data);
    addElementStyle(context, element);
    context.startGroupChildren(*m_ownerElement->itemComputedStyle(element));
    // We should call ItemIterationContext::finishGroupIfNecessary() later.
}

void PopupMenuImpl::addSeparator(ItemIterationContext& context,
    HTMLHRElement& element)
{
    SharedBuffer* data = context.m_buffer;
    PagePopupClient::addString("{\n", data);
    PagePopupClient::addString("type: \"separator\",\n", data);
    addProperty("title", element.title(), data);
    addProperty("ariaLabel", element.fastGetAttribute(HTMLNames::aria_labelAttr),
        data);
=======
    addProperty("ariaLabel", element.fastGetAttribute(HTMLNames::aria_labelAttr), data);
    addProperty("disabled", element.isDisabledFormControl(), data);
    addElementStyle(context, element);
    PagePopupClient::addString("children: [", data);
    for (HTMLElement& child : Traversal<HTMLElement>::childrenOf(element)) {
        if (isHTMLOptionElement(child))
            addOption(context, toHTMLOptionElement(child));
        // TODO(tkent): Ignore nested OPTGROUP. crbug.com/502101.
        if (isHTMLOptGroupElement(child))
            addOptGroup(context, toHTMLOptGroupElement(child));
        if (isHTMLHRElement(child))
            addSeparator(context, toHTMLHRElement(child));
    }
    PagePopupClient::addString("],\n", data);
    PagePopupClient::addString("},\n", data);
}

void PopupMenuImpl::addSeparator(ItemIterationContext& context, HTMLHRElement& element)
{
    SharedBuffer* data = context.m_buffer;
    ++context.m_listIndex;
    PagePopupClient::addString("{\n", data);
    PagePopupClient::addString("type: \"separator\",\n", data);
    addProperty("title", element.title(), data);
    addProperty("ariaLabel", element.fastGetAttribute(HTMLNames::aria_labelAttr), data);
>>>>>>> miniblink49
    addProperty("disabled", element.isDisabledFormControl(), data);
    addElementStyle(context, element);
    PagePopupClient::addString("},\n", data);
}

void PopupMenuImpl::selectFontsFromOwnerDocument(Document& document)
{
    Document& ownerDocument = ownerElement().document();
<<<<<<< HEAD
    document.styleEngine().setFontSelector(PopupMenuCSSFontSelector::create(
        &document, ownerDocument.styleEngine().fontSelector()));
}

void PopupMenuImpl::setValueAndClosePopup(int numValue,
    const String& stringValue)
{
    DCHECK(m_popup);
    DCHECK(m_ownerElement);
    if (!stringValue.isEmpty()) {
        bool success;
        int listIndex = stringValue.toInt(&success);
        DCHECK(success);

        EventQueueScope scope;
        m_ownerElement->selectOptionByPopup(listIndex);
        if (m_popup)
            m_chromeClient->closePagePopup(m_popup);
        // 'change' event is dispatched here.  For compatbility with
        // Angular 1.2, we need to dispatch a change event before
        // mouseup/click events.
    } else {
        if (m_popup)
            m_chromeClient->closePagePopup(m_popup);
    }
    // We dispatch events on the owner element to match the legacy behavior.
    // Other browsers dispatch click events before and after showing the popup.
    if (m_ownerElement) {
        PlatformMouseEvent event;
        Element* owner = &ownerElement();
=======
    document.styleEngine().setFontSelector(PopupMenuCSSFontSelector::create(&document, ownerDocument.styleEngine().fontSelector()));
}

void PopupMenuImpl::setValueAndClosePopup(int numValue, const String& stringValue)
{
    ASSERT(m_popup);
    ASSERT(m_client);
    RefPtrWillBeRawPtr<PopupMenuImpl> protector(this);
    bool success;
    int listIndex = stringValue.toInt(&success);
    ASSERT(success);
    m_client->selectionChanged(listIndex);
    m_client->valueChanged(listIndex);
    if (m_popup)
        m_chromeClient->closePagePopup(m_popup);
    // We dispatch events on the owner element to match the legacy behavior.
    // Other browsers dispatch click events before and after showing the popup.
    if (m_client) {
        PlatformMouseEvent event;
        RefPtrWillBeRawPtr<Element> owner = &ownerElement();
>>>>>>> miniblink49
        owner->dispatchMouseEvent(event, EventTypeNames::mouseup);
        owner->dispatchMouseEvent(event, EventTypeNames::click);
    }
}

void PopupMenuImpl::setValue(const String& value)
{
<<<<<<< HEAD
    DCHECK(m_ownerElement);
    bool success;
    int listIndex = value.toInt(&success);
    DCHECK(success);
    m_ownerElement->provisionalSelectionChanged(listIndex);
=======
    ASSERT(m_client);
    bool success;
    int listIndex = value.toInt(&success);
    ASSERT(success);
    m_client->provisionalSelectionChanged(listIndex);
>>>>>>> miniblink49
}

void PopupMenuImpl::didClosePopup()
{
    // Clearing m_popup first to prevent from trying to close the popup again.
    m_popup = nullptr;
<<<<<<< HEAD
    if (m_ownerElement)
        m_ownerElement->popupDidHide();
=======
    RefPtrWillBeRawPtr<PopupMenuImpl> protector(this);
    if (m_client)
        m_client->popupDidHide();
>>>>>>> miniblink49
}

Element& PopupMenuImpl::ownerElement()
{
<<<<<<< HEAD
    return *m_ownerElement;
=======
    return m_client->ownerElement();
>>>>>>> miniblink49
}

Locale& PopupMenuImpl::locale()
{
    return Locale::defaultLocale();
}

void PopupMenuImpl::closePopup()
{
    if (m_popup)
        m_chromeClient->closePagePopup(m_popup);
<<<<<<< HEAD
    if (m_ownerElement)
        m_ownerElement->popupDidCancel();
=======
    if (m_client)
        m_client->popupDidCancel();
>>>>>>> miniblink49
}

void PopupMenuImpl::dispose()
{
    if (m_popup)
        m_chromeClient->closePagePopup(m_popup);
}

<<<<<<< HEAD
void PopupMenuImpl::show()
{
    DCHECK(!m_popup);
=======
void PopupMenuImpl::show(const FloatQuad& /*controlPosition*/, const IntSize& /*controlSize*/, int /*index*/)
{
    ASSERT(!m_popup);
>>>>>>> miniblink49
    m_popup = m_chromeClient->openPagePopup(this);
}

void PopupMenuImpl::hide()
{
<<<<<<< HEAD
    closePopup();
}

void PopupMenuImpl::updateFromElement(UpdateReason)
=======
    if (m_popup)
        m_chromeClient->closePagePopup(m_popup);
}

void PopupMenuImpl::updateFromElement()
>>>>>>> miniblink49
{
    if (m_needsUpdate)
        return;
    m_needsUpdate = true;
<<<<<<< HEAD
    ownerElement().document().postTask(
        TaskType::UserInteraction, BLINK_FROM_HERE,
        createSameThreadTask(&PopupMenuImpl::update, wrapPersistent(this)));
=======
    ownerElement().document().postTask(FROM_HERE, createSameThreadTask(&PopupMenuImpl::update, PassRefPtrWillBeRawPtr<PopupMenuImpl>(this)));
>>>>>>> miniblink49
}

void PopupMenuImpl::update()
{
<<<<<<< HEAD
    if (!m_popup || !m_ownerElement)
        return;
    ownerElement().document().updateStyleAndLayoutTree();
    // disconnectClient() might have been called.
    if (!m_ownerElement)
        return;
    m_needsUpdate = false;

    if (!ownerElement()
             .document()
             .frame()
             ->view()
             ->visibleContentRect()
             .intersects(ownerElement().pixelSnappedBoundingBox())) {
        hide();
        return;
    }

    RefPtr<SharedBuffer> data = SharedBuffer::create();
    PagePopupClient::addString("window.updateData = {\n", data.get());
    PagePopupClient::addString("type: \"update\",\n", data.get());
    ItemIterationContext context(*m_ownerElement->computedStyle(), data.get());
    context.serializeBaseStyle();
    PagePopupClient::addString("children: [", data.get());
    const HeapVector<Member<HTMLElement>>& items = m_ownerElement->listItems();
    for (; context.m_listIndex < items.size(); ++context.m_listIndex) {
        Element& child = *items[context.m_listIndex];
        if (!isHTMLOptGroupElement(child.parentNode()))
            context.finishGroupIfNecessary();
        if (isHTMLOptionElement(child))
            addOption(context, toHTMLOptionElement(child));
        else if (isHTMLOptGroupElement(child))
            addOptGroup(context, toHTMLOptGroupElement(child));
        else if (isHTMLHRElement(child))
            addSeparator(context, toHTMLHRElement(child));
    }
    context.finishGroupIfNecessary();
    PagePopupClient::addString("],\n", data.get());
    IntRect anchorRectInScreen = m_chromeClient->viewportToScreen(
        m_ownerElement->visibleBoundsInVisualViewport(),
        ownerElement().document().view());
    addProperty("anchorRectInScreen", anchorRectInScreen, data.get());
=======
    if (!m_popup || !m_client)
        return;
    ownerElement().document().updateLayoutTreeIfNeeded();
    if (!m_client)
        return;
    m_needsUpdate = false;
    RefPtr<SharedBuffer> data = SharedBuffer::create();
    PagePopupClient::addString("window.updateData = {\n", data.get());
    PagePopupClient::addString("type: \"update\",\n", data.get());
    ItemIterationContext context(*ownerElement().computedStyle(), data.get());
    context.serializeBaseStyle();
    PagePopupClient::addString("children: [", data.get());
    for (HTMLElement& child : Traversal<HTMLElement>::childrenOf(ownerElement())) {
        if (isHTMLOptionElement(child))
            addOption(context, toHTMLOptionElement(child));
        if (isHTMLOptGroupElement(child))
            addOptGroup(context, toHTMLOptGroupElement(child));
        if (isHTMLHRElement(child))
            addSeparator(context, toHTMLHRElement(child));
    }
    PagePopupClient::addString("],\n", data.get());
>>>>>>> miniblink49
    PagePopupClient::addString("}\n", data.get());
    m_popup->postMessage(String::fromUTF8(data->data(), data->size()));
}

<<<<<<< HEAD
void PopupMenuImpl::disconnectClient()
{
    m_ownerElement = nullptr;
=======

void PopupMenuImpl::disconnectClient()
{
    m_client = nullptr;
>>>>>>> miniblink49
    // Cannot be done during finalization, so instead done when the
    // layout object is destroyed and disconnected.
    dispose();
}

} // namespace blink
