// Copyright (c) 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   ui/accessibility/ax_enums.idl
// DO NOT EDIT.

#include "ui/accessibility/ax_enums.h"
#include "base/logging.h"
#include "base/memory/ptr_util.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "tools/json_schema_compiler/util.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace ui {
//
// Types
//

std::string ToString(AXEvent enum_param)
{
    switch (enum_param) {
    case AX_EVENT_ACTIVEDESCENDANTCHANGED:
        return "activedescendantchanged";
    case AX_EVENT_ALERT:
        return "alert";
    case AX_EVENT_ARIA_ATTRIBUTE_CHANGED:
        return "ariaAttributeChanged";
    case AX_EVENT_AUTOCORRECTION_OCCURED:
        return "autocorrectionOccured";
    case AX_EVENT_BLUR:
        return "blur";
    case AX_EVENT_CHECKED_STATE_CHANGED:
        return "checkedStateChanged";
    case AX_EVENT_CHILDREN_CHANGED:
        return "childrenChanged";
    case AX_EVENT_CLICKED:
        return "clicked";
    case AX_EVENT_DOCUMENT_SELECTION_CHANGED:
        return "documentSelectionChanged";
    case AX_EVENT_EXPANDED_CHANGED:
        return "expandedChanged";
    case AX_EVENT_FOCUS:
        return "focus";
    case AX_EVENT_HIDE:
        return "hide";
    case AX_EVENT_HOVER:
        return "hover";
    case AX_EVENT_IMAGE_FRAME_UPDATED:
        return "imageFrameUpdated";
    case AX_EVENT_INVALID_STATUS_CHANGED:
        return "invalidStatusChanged";
    case AX_EVENT_LAYOUT_COMPLETE:
        return "layoutComplete";
    case AX_EVENT_LIVE_REGION_CREATED:
        return "liveRegionCreated";
    case AX_EVENT_LIVE_REGION_CHANGED:
        return "liveRegionChanged";
    case AX_EVENT_LOAD_COMPLETE:
        return "loadComplete";
    case AX_EVENT_LOCATION_CHANGED:
        return "locationChanged";
    case AX_EVENT_MEDIA_STARTED_PLAYING:
        return "mediaStartedPlaying";
    case AX_EVENT_MEDIA_STOPPED_PLAYING:
        return "mediaStoppedPlaying";
    case AX_EVENT_MENU_END:
        return "menuEnd";
    case AX_EVENT_MENU_LIST_ITEM_SELECTED:
        return "menuListItemSelected";
    case AX_EVENT_MENU_LIST_VALUE_CHANGED:
        return "menuListValueChanged";
    case AX_EVENT_MENU_POPUP_END:
        return "menuPopupEnd";
    case AX_EVENT_MENU_POPUP_START:
        return "menuPopupStart";
    case AX_EVENT_MENU_START:
        return "menuStart";
    case AX_EVENT_MOUSE_CANCELED:
        return "mouseCanceled";
    case AX_EVENT_MOUSE_DRAGGED:
        return "mouseDragged";
    case AX_EVENT_MOUSE_MOVED:
        return "mouseMoved";
    case AX_EVENT_MOUSE_PRESSED:
        return "mousePressed";
    case AX_EVENT_MOUSE_RELEASED:
        return "mouseReleased";
    case AX_EVENT_ROW_COLLAPSED:
        return "rowCollapsed";
    case AX_EVENT_ROW_COUNT_CHANGED:
        return "rowCountChanged";
    case AX_EVENT_ROW_EXPANDED:
        return "rowExpanded";
    case AX_EVENT_SCROLL_POSITION_CHANGED:
        return "scrollPositionChanged";
    case AX_EVENT_SCROLLED_TO_ANCHOR:
        return "scrolledToAnchor";
    case AX_EVENT_SELECTED_CHILDREN_CHANGED:
        return "selectedChildrenChanged";
    case AX_EVENT_SELECTION:
        return "selection";
    case AX_EVENT_SELECTION_ADD:
        return "selectionAdd";
    case AX_EVENT_SELECTION_REMOVE:
        return "selectionRemove";
    case AX_EVENT_SHOW:
        return "show";
    case AX_EVENT_TEXT_CHANGED:
        return "textChanged";
    case AX_EVENT_TEXT_SELECTION_CHANGED:
        return "textSelectionChanged";
    case AX_EVENT_TREE_CHANGED:
        return "treeChanged";
    case AX_EVENT_VALUE_CHANGED:
        return "valueChanged";
    case AX_EVENT_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXEvent ParseAXEvent(const std::string& enum_string)
{
    if (enum_string == "activedescendantchanged")
        return AX_EVENT_ACTIVEDESCENDANTCHANGED;
    if (enum_string == "alert")
        return AX_EVENT_ALERT;
    if (enum_string == "ariaAttributeChanged")
        return AX_EVENT_ARIA_ATTRIBUTE_CHANGED;
    if (enum_string == "autocorrectionOccured")
        return AX_EVENT_AUTOCORRECTION_OCCURED;
    if (enum_string == "blur")
        return AX_EVENT_BLUR;
    if (enum_string == "checkedStateChanged")
        return AX_EVENT_CHECKED_STATE_CHANGED;
    if (enum_string == "childrenChanged")
        return AX_EVENT_CHILDREN_CHANGED;
    if (enum_string == "clicked")
        return AX_EVENT_CLICKED;
    if (enum_string == "documentSelectionChanged")
        return AX_EVENT_DOCUMENT_SELECTION_CHANGED;
    if (enum_string == "expandedChanged")
        return AX_EVENT_EXPANDED_CHANGED;
    if (enum_string == "focus")
        return AX_EVENT_FOCUS;
    if (enum_string == "hide")
        return AX_EVENT_HIDE;
    if (enum_string == "hover")
        return AX_EVENT_HOVER;
    if (enum_string == "imageFrameUpdated")
        return AX_EVENT_IMAGE_FRAME_UPDATED;
    if (enum_string == "invalidStatusChanged")
        return AX_EVENT_INVALID_STATUS_CHANGED;
    if (enum_string == "layoutComplete")
        return AX_EVENT_LAYOUT_COMPLETE;
    if (enum_string == "liveRegionCreated")
        return AX_EVENT_LIVE_REGION_CREATED;
    if (enum_string == "liveRegionChanged")
        return AX_EVENT_LIVE_REGION_CHANGED;
    if (enum_string == "loadComplete")
        return AX_EVENT_LOAD_COMPLETE;
    if (enum_string == "locationChanged")
        return AX_EVENT_LOCATION_CHANGED;
    if (enum_string == "mediaStartedPlaying")
        return AX_EVENT_MEDIA_STARTED_PLAYING;
    if (enum_string == "mediaStoppedPlaying")
        return AX_EVENT_MEDIA_STOPPED_PLAYING;
    if (enum_string == "menuEnd")
        return AX_EVENT_MENU_END;
    if (enum_string == "menuListItemSelected")
        return AX_EVENT_MENU_LIST_ITEM_SELECTED;
    if (enum_string == "menuListValueChanged")
        return AX_EVENT_MENU_LIST_VALUE_CHANGED;
    if (enum_string == "menuPopupEnd")
        return AX_EVENT_MENU_POPUP_END;
    if (enum_string == "menuPopupStart")
        return AX_EVENT_MENU_POPUP_START;
    if (enum_string == "menuStart")
        return AX_EVENT_MENU_START;
    if (enum_string == "mouseCanceled")
        return AX_EVENT_MOUSE_CANCELED;
    if (enum_string == "mouseDragged")
        return AX_EVENT_MOUSE_DRAGGED;
    if (enum_string == "mouseMoved")
        return AX_EVENT_MOUSE_MOVED;
    if (enum_string == "mousePressed")
        return AX_EVENT_MOUSE_PRESSED;
    if (enum_string == "mouseReleased")
        return AX_EVENT_MOUSE_RELEASED;
    if (enum_string == "rowCollapsed")
        return AX_EVENT_ROW_COLLAPSED;
    if (enum_string == "rowCountChanged")
        return AX_EVENT_ROW_COUNT_CHANGED;
    if (enum_string == "rowExpanded")
        return AX_EVENT_ROW_EXPANDED;
    if (enum_string == "scrollPositionChanged")
        return AX_EVENT_SCROLL_POSITION_CHANGED;
    if (enum_string == "scrolledToAnchor")
        return AX_EVENT_SCROLLED_TO_ANCHOR;
    if (enum_string == "selectedChildrenChanged")
        return AX_EVENT_SELECTED_CHILDREN_CHANGED;
    if (enum_string == "selection")
        return AX_EVENT_SELECTION;
    if (enum_string == "selectionAdd")
        return AX_EVENT_SELECTION_ADD;
    if (enum_string == "selectionRemove")
        return AX_EVENT_SELECTION_REMOVE;
    if (enum_string == "show")
        return AX_EVENT_SHOW;
    if (enum_string == "textChanged")
        return AX_EVENT_TEXT_CHANGED;
    if (enum_string == "textSelectionChanged")
        return AX_EVENT_TEXT_SELECTION_CHANGED;
    if (enum_string == "treeChanged")
        return AX_EVENT_TREE_CHANGED;
    if (enum_string == "valueChanged")
        return AX_EVENT_VALUE_CHANGED;
    return AX_EVENT_NONE;
}

std::string ToString(AXRole enum_param)
{
    switch (enum_param) {
    case AX_ROLE_ABBR:
        return "abbr";
    case AX_ROLE_ALERT_DIALOG:
        return "alertDialog";
    case AX_ROLE_ALERT:
        return "alert";
    case AX_ROLE_ANNOTATION:
        return "annotation";
    case AX_ROLE_APPLICATION:
        return "application";
    case AX_ROLE_ARTICLE:
        return "article";
    case AX_ROLE_AUDIO:
        return "audio";
    case AX_ROLE_BANNER:
        return "banner";
    case AX_ROLE_BLOCKQUOTE:
        return "blockquote";
    case AX_ROLE_BUSY_INDICATOR:
        return "busyIndicator";
    case AX_ROLE_BUTTON:
        return "button";
    case AX_ROLE_BUTTON_DROP_DOWN:
        return "buttonDropDown";
    case AX_ROLE_CANVAS:
        return "canvas";
    case AX_ROLE_CAPTION:
        return "caption";
    case AX_ROLE_CELL:
        return "cell";
    case AX_ROLE_CHECK_BOX:
        return "checkBox";
    case AX_ROLE_CLIENT:
        return "client";
    case AX_ROLE_COLOR_WELL:
        return "colorWell";
    case AX_ROLE_COLUMN_HEADER:
        return "columnHeader";
    case AX_ROLE_COLUMN:
        return "column";
    case AX_ROLE_COMBO_BOX:
        return "comboBox";
    case AX_ROLE_COMPLEMENTARY:
        return "complementary";
    case AX_ROLE_CONTENT_INFO:
        return "contentInfo";
    case AX_ROLE_DATE:
        return "date";
    case AX_ROLE_DATE_TIME:
        return "dateTime";
    case AX_ROLE_DEFINITION:
        return "definition";
    case AX_ROLE_DESCRIPTION_LIST_DETAIL:
        return "descriptionListDetail";
    case AX_ROLE_DESCRIPTION_LIST:
        return "descriptionList";
    case AX_ROLE_DESCRIPTION_LIST_TERM:
        return "descriptionListTerm";
    case AX_ROLE_DESKTOP:
        return "desktop";
    case AX_ROLE_DETAILS:
        return "details";
    case AX_ROLE_DIALOG:
        return "dialog";
    case AX_ROLE_DIRECTORY:
        return "directory";
    case AX_ROLE_DISCLOSURE_TRIANGLE:
        return "disclosureTriangle";
    case AX_ROLE_DIV:
        return "div";
    case AX_ROLE_DOCUMENT:
        return "document";
    case AX_ROLE_EMBEDDED_OBJECT:
        return "embeddedObject";
    case AX_ROLE_FEED:
        return "feed";
    case AX_ROLE_FIGCAPTION:
        return "figcaption";
    case AX_ROLE_FIGURE:
        return "figure";
    case AX_ROLE_FOOTER:
        return "footer";
    case AX_ROLE_FORM:
        return "form";
    case AX_ROLE_GRID:
        return "grid";
    case AX_ROLE_GROUP:
        return "group";
    case AX_ROLE_HEADING:
        return "heading";
    case AX_ROLE_IFRAME:
        return "iframe";
    case AX_ROLE_IFRAME_PRESENTATIONAL:
        return "iframePresentational";
    case AX_ROLE_IGNORED:
        return "ignored";
    case AX_ROLE_IMAGE_MAP_LINK:
        return "imageMapLink";
    case AX_ROLE_IMAGE_MAP:
        return "imageMap";
    case AX_ROLE_IMAGE:
        return "image";
    case AX_ROLE_INLINE_TEXT_BOX:
        return "inlineTextBox";
    case AX_ROLE_INPUT_TIME:
        return "inputTime";
    case AX_ROLE_LABEL_TEXT:
        return "labelText";
    case AX_ROLE_LEGEND:
        return "legend";
    case AX_ROLE_LINE_BREAK:
        return "lineBreak";
    case AX_ROLE_LINK:
        return "link";
    case AX_ROLE_LIST_BOX_OPTION:
        return "listBoxOption";
    case AX_ROLE_LIST_BOX:
        return "listBox";
    case AX_ROLE_LIST_ITEM:
        return "listItem";
    case AX_ROLE_LIST_MARKER:
        return "listMarker";
    case AX_ROLE_LIST:
        return "list";
    case AX_ROLE_LOCATION_BAR:
        return "locationBar";
    case AX_ROLE_LOG:
        return "log";
    case AX_ROLE_MAIN:
        return "main";
    case AX_ROLE_MARK:
        return "mark";
    case AX_ROLE_MARQUEE:
        return "marquee";
    case AX_ROLE_MATH:
        return "math";
    case AX_ROLE_MENU:
        return "menu";
    case AX_ROLE_MENU_BAR:
        return "menuBar";
    case AX_ROLE_MENU_BUTTON:
        return "menuButton";
    case AX_ROLE_MENU_ITEM:
        return "menuItem";
    case AX_ROLE_MENU_ITEM_CHECK_BOX:
        return "menuItemCheckBox";
    case AX_ROLE_MENU_ITEM_RADIO:
        return "menuItemRadio";
    case AX_ROLE_MENU_LIST_OPTION:
        return "menuListOption";
    case AX_ROLE_MENU_LIST_POPUP:
        return "menuListPopup";
    case AX_ROLE_METER:
        return "meter";
    case AX_ROLE_NAVIGATION:
        return "navigation";
    case AX_ROLE_NOTE:
        return "note";
    case AX_ROLE_OUTLINE:
        return "outline";
    case AX_ROLE_PANE:
        return "pane";
    case AX_ROLE_PARAGRAPH:
        return "paragraph";
    case AX_ROLE_POP_UP_BUTTON:
        return "popUpButton";
    case AX_ROLE_PRE:
        return "pre";
    case AX_ROLE_PRESENTATIONAL:
        return "presentational";
    case AX_ROLE_PROGRESS_INDICATOR:
        return "progressIndicator";
    case AX_ROLE_RADIO_BUTTON:
        return "radioButton";
    case AX_ROLE_RADIO_GROUP:
        return "radioGroup";
    case AX_ROLE_REGION:
        return "region";
    case AX_ROLE_ROOT_WEB_AREA:
        return "rootWebArea";
    case AX_ROLE_ROW_HEADER:
        return "rowHeader";
    case AX_ROLE_ROW:
        return "row";
    case AX_ROLE_RUBY:
        return "ruby";
    case AX_ROLE_RULER:
        return "ruler";
    case AX_ROLE_SVG_ROOT:
        return "svgRoot";
    case AX_ROLE_SCROLL_AREA:
        return "scrollArea";
    case AX_ROLE_SCROLL_BAR:
        return "scrollBar";
    case AX_ROLE_SEAMLESS_WEB_AREA:
        return "seamlessWebArea";
    case AX_ROLE_SEARCH:
        return "search";
    case AX_ROLE_SEARCH_BOX:
        return "searchBox";
    case AX_ROLE_SLIDER:
        return "slider";
    case AX_ROLE_SLIDER_THUMB:
        return "sliderThumb";
    case AX_ROLE_SPIN_BUTTON_PART:
        return "spinButtonPart";
    case AX_ROLE_SPIN_BUTTON:
        return "spinButton";
    case AX_ROLE_SPLITTER:
        return "splitter";
    case AX_ROLE_STATIC_TEXT:
        return "staticText";
    case AX_ROLE_STATUS:
        return "status";
    case AX_ROLE_SWITCH:
        return "switch";
    case AX_ROLE_TAB_GROUP:
        return "tabGroup";
    case AX_ROLE_TAB_LIST:
        return "tabList";
    case AX_ROLE_TAB_PANEL:
        return "tabPanel";
    case AX_ROLE_TAB:
        return "tab";
    case AX_ROLE_TABLE_HEADER_CONTAINER:
        return "tableHeaderContainer";
    case AX_ROLE_TABLE:
        return "table";
    case AX_ROLE_TERM:
        return "term";
    case AX_ROLE_TEXT_FIELD:
        return "textField";
    case AX_ROLE_TIME:
        return "time";
    case AX_ROLE_TIMER:
        return "timer";
    case AX_ROLE_TITLE_BAR:
        return "titleBar";
    case AX_ROLE_TOGGLE_BUTTON:
        return "toggleButton";
    case AX_ROLE_TOOLBAR:
        return "toolbar";
    case AX_ROLE_TREE_GRID:
        return "treeGrid";
    case AX_ROLE_TREE_ITEM:
        return "treeItem";
    case AX_ROLE_TREE:
        return "tree";
    case AX_ROLE_UNKNOWN:
        return "unknown";
    case AX_ROLE_TOOLTIP:
        return "tooltip";
    case AX_ROLE_VIDEO:
        return "video";
    case AX_ROLE_WEB_AREA:
        return "webArea";
    case AX_ROLE_WEB_VIEW:
        return "webView";
    case AX_ROLE_WINDOW:
        return "window";
    case AX_ROLE_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXRole ParseAXRole(const std::string& enum_string)
{
    if (enum_string == "abbr")
        return AX_ROLE_ABBR;
    if (enum_string == "alertDialog")
        return AX_ROLE_ALERT_DIALOG;
    if (enum_string == "alert")
        return AX_ROLE_ALERT;
    if (enum_string == "annotation")
        return AX_ROLE_ANNOTATION;
    if (enum_string == "application")
        return AX_ROLE_APPLICATION;
    if (enum_string == "article")
        return AX_ROLE_ARTICLE;
    if (enum_string == "audio")
        return AX_ROLE_AUDIO;
    if (enum_string == "banner")
        return AX_ROLE_BANNER;
    if (enum_string == "blockquote")
        return AX_ROLE_BLOCKQUOTE;
    if (enum_string == "busyIndicator")
        return AX_ROLE_BUSY_INDICATOR;
    if (enum_string == "button")
        return AX_ROLE_BUTTON;
    if (enum_string == "buttonDropDown")
        return AX_ROLE_BUTTON_DROP_DOWN;
    if (enum_string == "canvas")
        return AX_ROLE_CANVAS;
    if (enum_string == "caption")
        return AX_ROLE_CAPTION;
    if (enum_string == "cell")
        return AX_ROLE_CELL;
    if (enum_string == "checkBox")
        return AX_ROLE_CHECK_BOX;
    if (enum_string == "client")
        return AX_ROLE_CLIENT;
    if (enum_string == "colorWell")
        return AX_ROLE_COLOR_WELL;
    if (enum_string == "columnHeader")
        return AX_ROLE_COLUMN_HEADER;
    if (enum_string == "column")
        return AX_ROLE_COLUMN;
    if (enum_string == "comboBox")
        return AX_ROLE_COMBO_BOX;
    if (enum_string == "complementary")
        return AX_ROLE_COMPLEMENTARY;
    if (enum_string == "contentInfo")
        return AX_ROLE_CONTENT_INFO;
    if (enum_string == "date")
        return AX_ROLE_DATE;
    if (enum_string == "dateTime")
        return AX_ROLE_DATE_TIME;
    if (enum_string == "definition")
        return AX_ROLE_DEFINITION;
    if (enum_string == "descriptionListDetail")
        return AX_ROLE_DESCRIPTION_LIST_DETAIL;
    if (enum_string == "descriptionList")
        return AX_ROLE_DESCRIPTION_LIST;
    if (enum_string == "descriptionListTerm")
        return AX_ROLE_DESCRIPTION_LIST_TERM;
    if (enum_string == "desktop")
        return AX_ROLE_DESKTOP;
    if (enum_string == "details")
        return AX_ROLE_DETAILS;
    if (enum_string == "dialog")
        return AX_ROLE_DIALOG;
    if (enum_string == "directory")
        return AX_ROLE_DIRECTORY;
    if (enum_string == "disclosureTriangle")
        return AX_ROLE_DISCLOSURE_TRIANGLE;
    if (enum_string == "div")
        return AX_ROLE_DIV;
    if (enum_string == "document")
        return AX_ROLE_DOCUMENT;
    if (enum_string == "embeddedObject")
        return AX_ROLE_EMBEDDED_OBJECT;
    if (enum_string == "feed")
        return AX_ROLE_FEED;
    if (enum_string == "figcaption")
        return AX_ROLE_FIGCAPTION;
    if (enum_string == "figure")
        return AX_ROLE_FIGURE;
    if (enum_string == "footer")
        return AX_ROLE_FOOTER;
    if (enum_string == "form")
        return AX_ROLE_FORM;
    if (enum_string == "grid")
        return AX_ROLE_GRID;
    if (enum_string == "group")
        return AX_ROLE_GROUP;
    if (enum_string == "heading")
        return AX_ROLE_HEADING;
    if (enum_string == "iframe")
        return AX_ROLE_IFRAME;
    if (enum_string == "iframePresentational")
        return AX_ROLE_IFRAME_PRESENTATIONAL;
    if (enum_string == "ignored")
        return AX_ROLE_IGNORED;
    if (enum_string == "imageMapLink")
        return AX_ROLE_IMAGE_MAP_LINK;
    if (enum_string == "imageMap")
        return AX_ROLE_IMAGE_MAP;
    if (enum_string == "image")
        return AX_ROLE_IMAGE;
    if (enum_string == "inlineTextBox")
        return AX_ROLE_INLINE_TEXT_BOX;
    if (enum_string == "inputTime")
        return AX_ROLE_INPUT_TIME;
    if (enum_string == "labelText")
        return AX_ROLE_LABEL_TEXT;
    if (enum_string == "legend")
        return AX_ROLE_LEGEND;
    if (enum_string == "lineBreak")
        return AX_ROLE_LINE_BREAK;
    if (enum_string == "link")
        return AX_ROLE_LINK;
    if (enum_string == "listBoxOption")
        return AX_ROLE_LIST_BOX_OPTION;
    if (enum_string == "listBox")
        return AX_ROLE_LIST_BOX;
    if (enum_string == "listItem")
        return AX_ROLE_LIST_ITEM;
    if (enum_string == "listMarker")
        return AX_ROLE_LIST_MARKER;
    if (enum_string == "list")
        return AX_ROLE_LIST;
    if (enum_string == "locationBar")
        return AX_ROLE_LOCATION_BAR;
    if (enum_string == "log")
        return AX_ROLE_LOG;
    if (enum_string == "main")
        return AX_ROLE_MAIN;
    if (enum_string == "mark")
        return AX_ROLE_MARK;
    if (enum_string == "marquee")
        return AX_ROLE_MARQUEE;
    if (enum_string == "math")
        return AX_ROLE_MATH;
    if (enum_string == "menu")
        return AX_ROLE_MENU;
    if (enum_string == "menuBar")
        return AX_ROLE_MENU_BAR;
    if (enum_string == "menuButton")
        return AX_ROLE_MENU_BUTTON;
    if (enum_string == "menuItem")
        return AX_ROLE_MENU_ITEM;
    if (enum_string == "menuItemCheckBox")
        return AX_ROLE_MENU_ITEM_CHECK_BOX;
    if (enum_string == "menuItemRadio")
        return AX_ROLE_MENU_ITEM_RADIO;
    if (enum_string == "menuListOption")
        return AX_ROLE_MENU_LIST_OPTION;
    if (enum_string == "menuListPopup")
        return AX_ROLE_MENU_LIST_POPUP;
    if (enum_string == "meter")
        return AX_ROLE_METER;
    if (enum_string == "navigation")
        return AX_ROLE_NAVIGATION;
    if (enum_string == "note")
        return AX_ROLE_NOTE;
    if (enum_string == "outline")
        return AX_ROLE_OUTLINE;
    if (enum_string == "pane")
        return AX_ROLE_PANE;
    if (enum_string == "paragraph")
        return AX_ROLE_PARAGRAPH;
    if (enum_string == "popUpButton")
        return AX_ROLE_POP_UP_BUTTON;
    if (enum_string == "pre")
        return AX_ROLE_PRE;
    if (enum_string == "presentational")
        return AX_ROLE_PRESENTATIONAL;
    if (enum_string == "progressIndicator")
        return AX_ROLE_PROGRESS_INDICATOR;
    if (enum_string == "radioButton")
        return AX_ROLE_RADIO_BUTTON;
    if (enum_string == "radioGroup")
        return AX_ROLE_RADIO_GROUP;
    if (enum_string == "region")
        return AX_ROLE_REGION;
    if (enum_string == "rootWebArea")
        return AX_ROLE_ROOT_WEB_AREA;
    if (enum_string == "rowHeader")
        return AX_ROLE_ROW_HEADER;
    if (enum_string == "row")
        return AX_ROLE_ROW;
    if (enum_string == "ruby")
        return AX_ROLE_RUBY;
    if (enum_string == "ruler")
        return AX_ROLE_RULER;
    if (enum_string == "svgRoot")
        return AX_ROLE_SVG_ROOT;
    if (enum_string == "scrollArea")
        return AX_ROLE_SCROLL_AREA;
    if (enum_string == "scrollBar")
        return AX_ROLE_SCROLL_BAR;
    if (enum_string == "seamlessWebArea")
        return AX_ROLE_SEAMLESS_WEB_AREA;
    if (enum_string == "search")
        return AX_ROLE_SEARCH;
    if (enum_string == "searchBox")
        return AX_ROLE_SEARCH_BOX;
    if (enum_string == "slider")
        return AX_ROLE_SLIDER;
    if (enum_string == "sliderThumb")
        return AX_ROLE_SLIDER_THUMB;
    if (enum_string == "spinButtonPart")
        return AX_ROLE_SPIN_BUTTON_PART;
    if (enum_string == "spinButton")
        return AX_ROLE_SPIN_BUTTON;
    if (enum_string == "splitter")
        return AX_ROLE_SPLITTER;
    if (enum_string == "staticText")
        return AX_ROLE_STATIC_TEXT;
    if (enum_string == "status")
        return AX_ROLE_STATUS;
    if (enum_string == "switch")
        return AX_ROLE_SWITCH;
    if (enum_string == "tabGroup")
        return AX_ROLE_TAB_GROUP;
    if (enum_string == "tabList")
        return AX_ROLE_TAB_LIST;
    if (enum_string == "tabPanel")
        return AX_ROLE_TAB_PANEL;
    if (enum_string == "tab")
        return AX_ROLE_TAB;
    if (enum_string == "tableHeaderContainer")
        return AX_ROLE_TABLE_HEADER_CONTAINER;
    if (enum_string == "table")
        return AX_ROLE_TABLE;
    if (enum_string == "term")
        return AX_ROLE_TERM;
    if (enum_string == "textField")
        return AX_ROLE_TEXT_FIELD;
    if (enum_string == "time")
        return AX_ROLE_TIME;
    if (enum_string == "timer")
        return AX_ROLE_TIMER;
    if (enum_string == "titleBar")
        return AX_ROLE_TITLE_BAR;
    if (enum_string == "toggleButton")
        return AX_ROLE_TOGGLE_BUTTON;
    if (enum_string == "toolbar")
        return AX_ROLE_TOOLBAR;
    if (enum_string == "treeGrid")
        return AX_ROLE_TREE_GRID;
    if (enum_string == "treeItem")
        return AX_ROLE_TREE_ITEM;
    if (enum_string == "tree")
        return AX_ROLE_TREE;
    if (enum_string == "unknown")
        return AX_ROLE_UNKNOWN;
    if (enum_string == "tooltip")
        return AX_ROLE_TOOLTIP;
    if (enum_string == "video")
        return AX_ROLE_VIDEO;
    if (enum_string == "webArea")
        return AX_ROLE_WEB_AREA;
    if (enum_string == "webView")
        return AX_ROLE_WEB_VIEW;
    if (enum_string == "window")
        return AX_ROLE_WINDOW;
    return AX_ROLE_NONE;
}

std::string ToString(AXState enum_param)
{
    switch (enum_param) {
    case AX_STATE_BUSY:
        return "busy";
    case AX_STATE_CHECKED:
        return "checked";
    case AX_STATE_COLLAPSED:
        return "collapsed";
    case AX_STATE_DEFAULT:
        return "default";
    case AX_STATE_DISABLED:
        return "disabled";
    case AX_STATE_EDITABLE:
        return "editable";
    case AX_STATE_EXPANDED:
        return "expanded";
    case AX_STATE_FOCUSABLE:
        return "focusable";
    case AX_STATE_HASPOPUP:
        return "haspopup";
    case AX_STATE_HORIZONTAL:
        return "horizontal";
    case AX_STATE_HOVERED:
        return "hovered";
    case AX_STATE_INVISIBLE:
        return "invisible";
    case AX_STATE_LINKED:
        return "linked";
    case AX_STATE_MULTILINE:
        return "multiline";
    case AX_STATE_MULTISELECTABLE:
        return "multiselectable";
    case AX_STATE_OFFSCREEN:
        return "offscreen";
    case AX_STATE_PRESSED:
        return "pressed";
    case AX_STATE_PROTECTED:
        return "protected";
    case AX_STATE_READ_ONLY:
        return "readOnly";
    case AX_STATE_REQUIRED:
        return "required";
    case AX_STATE_RICHLY_EDITABLE:
        return "richlyEditable";
    case AX_STATE_SELECTABLE:
        return "selectable";
    case AX_STATE_SELECTED:
        return "selected";
    case AX_STATE_VERTICAL:
        return "vertical";
    case AX_STATE_VISITED:
        return "visited";
    case AX_STATE_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXState ParseAXState(const std::string& enum_string)
{
    if (enum_string == "busy")
        return AX_STATE_BUSY;
    if (enum_string == "checked")
        return AX_STATE_CHECKED;
    if (enum_string == "collapsed")
        return AX_STATE_COLLAPSED;
    if (enum_string == "default")
        return AX_STATE_DEFAULT;
    if (enum_string == "disabled")
        return AX_STATE_DISABLED;
    if (enum_string == "editable")
        return AX_STATE_EDITABLE;
    if (enum_string == "expanded")
        return AX_STATE_EXPANDED;
    if (enum_string == "focusable")
        return AX_STATE_FOCUSABLE;
    if (enum_string == "haspopup")
        return AX_STATE_HASPOPUP;
    if (enum_string == "horizontal")
        return AX_STATE_HORIZONTAL;
    if (enum_string == "hovered")
        return AX_STATE_HOVERED;
    if (enum_string == "invisible")
        return AX_STATE_INVISIBLE;
    if (enum_string == "linked")
        return AX_STATE_LINKED;
    if (enum_string == "multiline")
        return AX_STATE_MULTILINE;
    if (enum_string == "multiselectable")
        return AX_STATE_MULTISELECTABLE;
    if (enum_string == "offscreen")
        return AX_STATE_OFFSCREEN;
    if (enum_string == "pressed")
        return AX_STATE_PRESSED;
    if (enum_string == "protected")
        return AX_STATE_PROTECTED;
    if (enum_string == "readOnly")
        return AX_STATE_READ_ONLY;
    if (enum_string == "required")
        return AX_STATE_REQUIRED;
    if (enum_string == "richlyEditable")
        return AX_STATE_RICHLY_EDITABLE;
    if (enum_string == "selectable")
        return AX_STATE_SELECTABLE;
    if (enum_string == "selected")
        return AX_STATE_SELECTED;
    if (enum_string == "vertical")
        return AX_STATE_VERTICAL;
    if (enum_string == "visited")
        return AX_STATE_VISITED;
    return AX_STATE_NONE;
}

std::string ToString(AXAction enum_param)
{
    switch (enum_param) {
    case AX_ACTION_BLUR:
        return "blur";
    case AX_ACTION_DECREMENT:
        return "decrement";
    case AX_ACTION_DO_DEFAULT:
        return "doDefault";
    case AX_ACTION_FOCUS:
        return "focus";
    case AX_ACTION_GET_IMAGE_DATA:
        return "getImageData";
    case AX_ACTION_HIT_TEST:
        return "hitTest";
    case AX_ACTION_INCREMENT:
        return "increment";
    case AX_ACTION_REPLACE_SELECTED_TEXT:
        return "replaceSelectedText";
    case AX_ACTION_SCROLL_TO_MAKE_VISIBLE:
        return "scrollToMakeVisible";
    case AX_ACTION_SCROLL_TO_POINT:
        return "scrollToPoint";
    case AX_ACTION_SET_ACCESSIBILITY_FOCUS:
        return "setAccessibilityFocus";
    case AX_ACTION_SET_SCROLL_OFFSET:
        return "setScrollOffset";
    case AX_ACTION_SET_SELECTION:
        return "setSelection";
    case AX_ACTION_SET_SEQUENTIAL_FOCUS_NAVIGATION_STARTING_POINT:
        return "setSequentialFocusNavigationStartingPoint";
    case AX_ACTION_SET_VALUE:
        return "setValue";
    case AX_ACTION_SHOW_CONTEXT_MENU:
        return "showContextMenu";
    case AX_ACTION_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXAction ParseAXAction(const std::string& enum_string)
{
    if (enum_string == "blur")
        return AX_ACTION_BLUR;
    if (enum_string == "decrement")
        return AX_ACTION_DECREMENT;
    if (enum_string == "doDefault")
        return AX_ACTION_DO_DEFAULT;
    if (enum_string == "focus")
        return AX_ACTION_FOCUS;
    if (enum_string == "getImageData")
        return AX_ACTION_GET_IMAGE_DATA;
    if (enum_string == "hitTest")
        return AX_ACTION_HIT_TEST;
    if (enum_string == "increment")
        return AX_ACTION_INCREMENT;
    if (enum_string == "replaceSelectedText")
        return AX_ACTION_REPLACE_SELECTED_TEXT;
    if (enum_string == "scrollToMakeVisible")
        return AX_ACTION_SCROLL_TO_MAKE_VISIBLE;
    if (enum_string == "scrollToPoint")
        return AX_ACTION_SCROLL_TO_POINT;
    if (enum_string == "setAccessibilityFocus")
        return AX_ACTION_SET_ACCESSIBILITY_FOCUS;
    if (enum_string == "setScrollOffset")
        return AX_ACTION_SET_SCROLL_OFFSET;
    if (enum_string == "setSelection")
        return AX_ACTION_SET_SELECTION;
    if (enum_string == "setSequentialFocusNavigationStartingPoint")
        return AX_ACTION_SET_SEQUENTIAL_FOCUS_NAVIGATION_STARTING_POINT;
    if (enum_string == "setValue")
        return AX_ACTION_SET_VALUE;
    if (enum_string == "showContextMenu")
        return AX_ACTION_SHOW_CONTEXT_MENU;
    return AX_ACTION_NONE;
}

std::string ToString(AXActionFlags enum_param)
{
    switch (enum_param) {
    case AX_ACTION_FLAGS_REQUEST_IMAGES:
        return "requestImages";
    case AX_ACTION_FLAGS_REQUEST_INLINE_TEXT_BOXES:
        return "requestInlineTextBoxes";
    case AX_ACTION_FLAGS_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXActionFlags ParseAXActionFlags(const std::string& enum_string)
{
    if (enum_string == "requestImages")
        return AX_ACTION_FLAGS_REQUEST_IMAGES;
    if (enum_string == "requestInlineTextBoxes")
        return AX_ACTION_FLAGS_REQUEST_INLINE_TEXT_BOXES;
    return AX_ACTION_FLAGS_NONE;
}

std::string ToString(AXSupportedAction enum_param)
{
    switch (enum_param) {
    case AX_SUPPORTED_ACTION_ACTIVATE:
        return "activate";
    case AX_SUPPORTED_ACTION_CHECK:
        return "check";
    case AX_SUPPORTED_ACTION_CLICK:
        return "click";
    case AX_SUPPORTED_ACTION_JUMP:
        return "jump";
    case AX_SUPPORTED_ACTION_OPEN:
        return "open";
    case AX_SUPPORTED_ACTION_PRESS:
        return "press";
    case AX_SUPPORTED_ACTION_SELECT:
        return "select";
    case AX_SUPPORTED_ACTION_UNCHECK:
        return "uncheck";
    case AX_SUPPORTED_ACTION_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXSupportedAction ParseAXSupportedAction(const std::string& enum_string)
{
    if (enum_string == "activate")
        return AX_SUPPORTED_ACTION_ACTIVATE;
    if (enum_string == "check")
        return AX_SUPPORTED_ACTION_CHECK;
    if (enum_string == "click")
        return AX_SUPPORTED_ACTION_CLICK;
    if (enum_string == "jump")
        return AX_SUPPORTED_ACTION_JUMP;
    if (enum_string == "open")
        return AX_SUPPORTED_ACTION_OPEN;
    if (enum_string == "press")
        return AX_SUPPORTED_ACTION_PRESS;
    if (enum_string == "select")
        return AX_SUPPORTED_ACTION_SELECT;
    if (enum_string == "uncheck")
        return AX_SUPPORTED_ACTION_UNCHECK;
    return AX_SUPPORTED_ACTION_NONE;
}

std::string ToString(AXMutation enum_param)
{
    switch (enum_param) {
    case AX_MUTATION_NODE_CREATED:
        return "nodeCreated";
    case AX_MUTATION_SUBTREE_CREATED:
        return "subtreeCreated";
    case AX_MUTATION_NODE_CHANGED:
        return "nodeChanged";
    case AX_MUTATION_NODE_REMOVED:
        return "nodeRemoved";
    case AX_MUTATION_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXMutation ParseAXMutation(const std::string& enum_string)
{
    if (enum_string == "nodeCreated")
        return AX_MUTATION_NODE_CREATED;
    if (enum_string == "subtreeCreated")
        return AX_MUTATION_SUBTREE_CREATED;
    if (enum_string == "nodeChanged")
        return AX_MUTATION_NODE_CHANGED;
    if (enum_string == "nodeRemoved")
        return AX_MUTATION_NODE_REMOVED;
    return AX_MUTATION_NONE;
}

std::string ToString(AXStringAttribute enum_param)
{
    switch (enum_param) {
    case AX_ATTR_ACCESS_KEY:
        return "accessKey";
    case AX_ATTR_ARIA_INVALID_VALUE:
        return "ariaInvalidValue";
    case AX_ATTR_AUTO_COMPLETE:
        return "autoComplete";
    case AX_ATTR_CHROME_CHANNEL:
        return "chromeChannel";
    case AX_ATTR_CONTAINER_LIVE_RELEVANT:
        return "containerLiveRelevant";
    case AX_ATTR_CONTAINER_LIVE_STATUS:
        return "containerLiveStatus";
    case AX_ATTR_DESCRIPTION:
        return "description";
    case AX_ATTR_DISPLAY:
        return "display";
    case AX_ATTR_FONT_FAMILY:
        return "fontFamily";
    case AX_ATTR_HTML_TAG:
        return "htmlTag";
    case AX_ATTR_IMAGE_DATA_URL:
        return "imageDataUrl";
    case AX_ATTR_LANGUAGE:
        return "language";
    case AX_ATTR_NAME:
        return "name";
    case AX_ATTR_LIVE_RELEVANT:
        return "liveRelevant";
    case AX_ATTR_LIVE_STATUS:
        return "liveStatus";
    case AX_ATTR_PLACEHOLDER:
        return "placeholder";
    case AX_ATTR_ROLE:
        return "role";
    case AX_ATTR_SHORTCUT:
        return "shortcut";
    case AX_ATTR_URL:
        return "url";
    case AX_ATTR_VALUE:
        return "value";
    case AX_STRING_ATTRIBUTE_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXStringAttribute ParseAXStringAttribute(const std::string& enum_string)
{
    if (enum_string == "accessKey")
        return AX_ATTR_ACCESS_KEY;
    if (enum_string == "ariaInvalidValue")
        return AX_ATTR_ARIA_INVALID_VALUE;
    if (enum_string == "autoComplete")
        return AX_ATTR_AUTO_COMPLETE;
    if (enum_string == "chromeChannel")
        return AX_ATTR_CHROME_CHANNEL;
    if (enum_string == "containerLiveRelevant")
        return AX_ATTR_CONTAINER_LIVE_RELEVANT;
    if (enum_string == "containerLiveStatus")
        return AX_ATTR_CONTAINER_LIVE_STATUS;
    if (enum_string == "description")
        return AX_ATTR_DESCRIPTION;
    if (enum_string == "display")
        return AX_ATTR_DISPLAY;
    if (enum_string == "fontFamily")
        return AX_ATTR_FONT_FAMILY;
    if (enum_string == "htmlTag")
        return AX_ATTR_HTML_TAG;
    if (enum_string == "imageDataUrl")
        return AX_ATTR_IMAGE_DATA_URL;
    if (enum_string == "language")
        return AX_ATTR_LANGUAGE;
    if (enum_string == "name")
        return AX_ATTR_NAME;
    if (enum_string == "liveRelevant")
        return AX_ATTR_LIVE_RELEVANT;
    if (enum_string == "liveStatus")
        return AX_ATTR_LIVE_STATUS;
    if (enum_string == "placeholder")
        return AX_ATTR_PLACEHOLDER;
    if (enum_string == "role")
        return AX_ATTR_ROLE;
    if (enum_string == "shortcut")
        return AX_ATTR_SHORTCUT;
    if (enum_string == "url")
        return AX_ATTR_URL;
    if (enum_string == "value")
        return AX_ATTR_VALUE;
    return AX_STRING_ATTRIBUTE_NONE;
}

std::string ToString(AXIntAttribute enum_param)
{
    switch (enum_param) {
    case AX_ATTR_ACTION:
        return "action";
    case AX_ATTR_SCROLL_X:
        return "scrollX";
    case AX_ATTR_SCROLL_X_MIN:
        return "scrollXMin";
    case AX_ATTR_SCROLL_X_MAX:
        return "scrollXMax";
    case AX_ATTR_SCROLL_Y:
        return "scrollY";
    case AX_ATTR_SCROLL_Y_MIN:
        return "scrollYMin";
    case AX_ATTR_SCROLL_Y_MAX:
        return "scrollYMax";
    case AX_ATTR_TEXT_SEL_START:
        return "textSelStart";
    case AX_ATTR_TEXT_SEL_END:
        return "textSelEnd";
    case AX_ATTR_ARIA_COL_COUNT:
        return "ariaColCount";
    case AX_ATTR_ARIA_COL_INDEX:
        return "ariaColIndex";
    case AX_ATTR_ARIA_ROW_COUNT:
        return "ariaRowCount";
    case AX_ATTR_ARIA_ROW_INDEX:
        return "ariaRowIndex";
    case AX_ATTR_TABLE_ROW_COUNT:
        return "tableRowCount";
    case AX_ATTR_TABLE_COLUMN_COUNT:
        return "tableColumnCount";
    case AX_ATTR_TABLE_HEADER_ID:
        return "tableHeaderId";
    case AX_ATTR_TABLE_ROW_INDEX:
        return "tableRowIndex";
    case AX_ATTR_TABLE_ROW_HEADER_ID:
        return "tableRowHeaderId";
    case AX_ATTR_TABLE_COLUMN_INDEX:
        return "tableColumnIndex";
    case AX_ATTR_TABLE_COLUMN_HEADER_ID:
        return "tableColumnHeaderId";
    case AX_ATTR_TABLE_CELL_COLUMN_INDEX:
        return "tableCellColumnIndex";
    case AX_ATTR_TABLE_CELL_COLUMN_SPAN:
        return "tableCellColumnSpan";
    case AX_ATTR_TABLE_CELL_ROW_INDEX:
        return "tableCellRowIndex";
    case AX_ATTR_TABLE_CELL_ROW_SPAN:
        return "tableCellRowSpan";
    case AX_ATTR_SORT_DIRECTION:
        return "sortDirection";
    case AX_ATTR_HIERARCHICAL_LEVEL:
        return "hierarchicalLevel";
    case AX_ATTR_NAME_FROM:
        return "nameFrom";
    case AX_ATTR_DESCRIPTION_FROM:
        return "descriptionFrom";
    case AX_ATTR_ACTIVEDESCENDANT_ID:
        return "activedescendantId";
    case AX_ATTR_MEMBER_OF_ID:
        return "memberOfId";
    case AX_ATTR_NEXT_ON_LINE_ID:
        return "nextOnLineId";
    case AX_ATTR_PREVIOUS_ON_LINE_ID:
        return "previousOnLineId";
    case AX_ATTR_CHILD_TREE_ID:
        return "childTreeId";
    case AX_ATTR_SET_SIZE:
        return "setSize";
    case AX_ATTR_POS_IN_SET:
        return "posInSet";
    case AX_ATTR_COLOR_VALUE:
        return "colorValue";
    case AX_ATTR_ARIA_CURRENT_STATE:
        return "ariaCurrentState";
    case AX_ATTR_BACKGROUND_COLOR:
        return "backgroundColor";
    case AX_ATTR_COLOR:
        return "color";
    case AX_ATTR_INVALID_STATE:
        return "invalidState";
    case AX_ATTR_TEXT_DIRECTION:
        return "textDirection";
    case AX_ATTR_TEXT_STYLE:
        return "textStyle";
    case AX_INT_ATTRIBUTE_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXIntAttribute ParseAXIntAttribute(const std::string& enum_string)
{
    if (enum_string == "action")
        return AX_ATTR_ACTION;
    if (enum_string == "scrollX")
        return AX_ATTR_SCROLL_X;
    if (enum_string == "scrollXMin")
        return AX_ATTR_SCROLL_X_MIN;
    if (enum_string == "scrollXMax")
        return AX_ATTR_SCROLL_X_MAX;
    if (enum_string == "scrollY")
        return AX_ATTR_SCROLL_Y;
    if (enum_string == "scrollYMin")
        return AX_ATTR_SCROLL_Y_MIN;
    if (enum_string == "scrollYMax")
        return AX_ATTR_SCROLL_Y_MAX;
    if (enum_string == "textSelStart")
        return AX_ATTR_TEXT_SEL_START;
    if (enum_string == "textSelEnd")
        return AX_ATTR_TEXT_SEL_END;
    if (enum_string == "ariaColCount")
        return AX_ATTR_ARIA_COL_COUNT;
    if (enum_string == "ariaColIndex")
        return AX_ATTR_ARIA_COL_INDEX;
    if (enum_string == "ariaRowCount")
        return AX_ATTR_ARIA_ROW_COUNT;
    if (enum_string == "ariaRowIndex")
        return AX_ATTR_ARIA_ROW_INDEX;
    if (enum_string == "tableRowCount")
        return AX_ATTR_TABLE_ROW_COUNT;
    if (enum_string == "tableColumnCount")
        return AX_ATTR_TABLE_COLUMN_COUNT;
    if (enum_string == "tableHeaderId")
        return AX_ATTR_TABLE_HEADER_ID;
    if (enum_string == "tableRowIndex")
        return AX_ATTR_TABLE_ROW_INDEX;
    if (enum_string == "tableRowHeaderId")
        return AX_ATTR_TABLE_ROW_HEADER_ID;
    if (enum_string == "tableColumnIndex")
        return AX_ATTR_TABLE_COLUMN_INDEX;
    if (enum_string == "tableColumnHeaderId")
        return AX_ATTR_TABLE_COLUMN_HEADER_ID;
    if (enum_string == "tableCellColumnIndex")
        return AX_ATTR_TABLE_CELL_COLUMN_INDEX;
    if (enum_string == "tableCellColumnSpan")
        return AX_ATTR_TABLE_CELL_COLUMN_SPAN;
    if (enum_string == "tableCellRowIndex")
        return AX_ATTR_TABLE_CELL_ROW_INDEX;
    if (enum_string == "tableCellRowSpan")
        return AX_ATTR_TABLE_CELL_ROW_SPAN;
    if (enum_string == "sortDirection")
        return AX_ATTR_SORT_DIRECTION;
    if (enum_string == "hierarchicalLevel")
        return AX_ATTR_HIERARCHICAL_LEVEL;
    if (enum_string == "nameFrom")
        return AX_ATTR_NAME_FROM;
    if (enum_string == "descriptionFrom")
        return AX_ATTR_DESCRIPTION_FROM;
    if (enum_string == "activedescendantId")
        return AX_ATTR_ACTIVEDESCENDANT_ID;
    if (enum_string == "memberOfId")
        return AX_ATTR_MEMBER_OF_ID;
    if (enum_string == "nextOnLineId")
        return AX_ATTR_NEXT_ON_LINE_ID;
    if (enum_string == "previousOnLineId")
        return AX_ATTR_PREVIOUS_ON_LINE_ID;
    if (enum_string == "childTreeId")
        return AX_ATTR_CHILD_TREE_ID;
    if (enum_string == "setSize")
        return AX_ATTR_SET_SIZE;
    if (enum_string == "posInSet")
        return AX_ATTR_POS_IN_SET;
    if (enum_string == "colorValue")
        return AX_ATTR_COLOR_VALUE;
    if (enum_string == "ariaCurrentState")
        return AX_ATTR_ARIA_CURRENT_STATE;
    if (enum_string == "backgroundColor")
        return AX_ATTR_BACKGROUND_COLOR;
    if (enum_string == "color")
        return AX_ATTR_COLOR;
    if (enum_string == "invalidState")
        return AX_ATTR_INVALID_STATE;
    if (enum_string == "textDirection")
        return AX_ATTR_TEXT_DIRECTION;
    if (enum_string == "textStyle")
        return AX_ATTR_TEXT_STYLE;
    return AX_INT_ATTRIBUTE_NONE;
}

std::string ToString(AXFloatAttribute enum_param)
{
    switch (enum_param) {
    case AX_ATTR_VALUE_FOR_RANGE:
        return "valueForRange";
    case AX_ATTR_MIN_VALUE_FOR_RANGE:
        return "minValueForRange";
    case AX_ATTR_MAX_VALUE_FOR_RANGE:
        return "maxValueForRange";
    case AX_ATTR_FONT_SIZE:
        return "fontSize";
    case AX_FLOAT_ATTRIBUTE_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXFloatAttribute ParseAXFloatAttribute(const std::string& enum_string)
{
    if (enum_string == "valueForRange")
        return AX_ATTR_VALUE_FOR_RANGE;
    if (enum_string == "minValueForRange")
        return AX_ATTR_MIN_VALUE_FOR_RANGE;
    if (enum_string == "maxValueForRange")
        return AX_ATTR_MAX_VALUE_FOR_RANGE;
    if (enum_string == "fontSize")
        return AX_ATTR_FONT_SIZE;
    return AX_FLOAT_ATTRIBUTE_NONE;
}

std::string ToString(AXBoolAttribute enum_param)
{
    switch (enum_param) {
    case AX_ATTR_STATE_MIXED:
        return "STATEMixed";
    case AX_ATTR_CONTAINER_LIVE_ATOMIC:
        return "containerLiveAtomic";
    case AX_ATTR_CONTAINER_LIVE_BUSY:
        return "containerLiveBusy";
    case AX_ATTR_LIVE_ATOMIC:
        return "liveAtomic";
    case AX_ATTR_LIVE_BUSY:
        return "liveBusy";
    case AX_ATTR_ARIA_READONLY:
        return "ariaReadonly";
    case AX_ATTR_CAN_SET_VALUE:
        return "canSetValue";
    case AX_ATTR_UPDATE_LOCATION_ONLY:
        return "updateLocationOnly";
    case AX_ATTR_CANVAS_HAS_FALLBACK:
        return "canvasHasFallback";
    case AX_BOOL_ATTRIBUTE_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXBoolAttribute ParseAXBoolAttribute(const std::string& enum_string)
{
    if (enum_string == "STATEMixed")
        return AX_ATTR_STATE_MIXED;
    if (enum_string == "containerLiveAtomic")
        return AX_ATTR_CONTAINER_LIVE_ATOMIC;
    if (enum_string == "containerLiveBusy")
        return AX_ATTR_CONTAINER_LIVE_BUSY;
    if (enum_string == "liveAtomic")
        return AX_ATTR_LIVE_ATOMIC;
    if (enum_string == "liveBusy")
        return AX_ATTR_LIVE_BUSY;
    if (enum_string == "ariaReadonly")
        return AX_ATTR_ARIA_READONLY;
    if (enum_string == "canSetValue")
        return AX_ATTR_CAN_SET_VALUE;
    if (enum_string == "updateLocationOnly")
        return AX_ATTR_UPDATE_LOCATION_ONLY;
    if (enum_string == "canvasHasFallback")
        return AX_ATTR_CANVAS_HAS_FALLBACK;
    return AX_BOOL_ATTRIBUTE_NONE;
}

std::string ToString(AXIntListAttribute enum_param)
{
    switch (enum_param) {
    case AX_ATTR_INDIRECT_CHILD_IDS:
        return "indirectChildIds";
    case AX_ATTR_CONTROLS_IDS:
        return "controlsIds";
    case AX_ATTR_DESCRIBEDBY_IDS:
        return "describedbyIds";
    case AX_ATTR_FLOWTO_IDS:
        return "flowtoIds";
    case AX_ATTR_LABELLEDBY_IDS:
        return "labelledbyIds";
    case AX_ATTR_LINE_BREAKS:
        return "lineBreaks";
    case AX_ATTR_MARKER_TYPES:
        return "markerTypes";
    case AX_ATTR_MARKER_STARTS:
        return "markerStarts";
    case AX_ATTR_MARKER_ENDS:
        return "markerEnds";
    case AX_ATTR_CELL_IDS:
        return "cellIds";
    case AX_ATTR_UNIQUE_CELL_IDS:
        return "uniqueCellIds";
    case AX_ATTR_CHARACTER_OFFSETS:
        return "characterOffsets";
    case AX_ATTR_CACHED_LINE_STARTS:
        return "cachedLineStarts";
    case AX_ATTR_WORD_STARTS:
        return "wordStarts";
    case AX_ATTR_WORD_ENDS:
        return "wordEnds";
    case AX_INT_LIST_ATTRIBUTE_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXIntListAttribute ParseAXIntListAttribute(const std::string& enum_string)
{
    if (enum_string == "indirectChildIds")
        return AX_ATTR_INDIRECT_CHILD_IDS;
    if (enum_string == "controlsIds")
        return AX_ATTR_CONTROLS_IDS;
    if (enum_string == "describedbyIds")
        return AX_ATTR_DESCRIBEDBY_IDS;
    if (enum_string == "flowtoIds")
        return AX_ATTR_FLOWTO_IDS;
    if (enum_string == "labelledbyIds")
        return AX_ATTR_LABELLEDBY_IDS;
    if (enum_string == "lineBreaks")
        return AX_ATTR_LINE_BREAKS;
    if (enum_string == "markerTypes")
        return AX_ATTR_MARKER_TYPES;
    if (enum_string == "markerStarts")
        return AX_ATTR_MARKER_STARTS;
    if (enum_string == "markerEnds")
        return AX_ATTR_MARKER_ENDS;
    if (enum_string == "cellIds")
        return AX_ATTR_CELL_IDS;
    if (enum_string == "uniqueCellIds")
        return AX_ATTR_UNIQUE_CELL_IDS;
    if (enum_string == "characterOffsets")
        return AX_ATTR_CHARACTER_OFFSETS;
    if (enum_string == "cachedLineStarts")
        return AX_ATTR_CACHED_LINE_STARTS;
    if (enum_string == "wordStarts")
        return AX_ATTR_WORD_STARTS;
    if (enum_string == "wordEnds")
        return AX_ATTR_WORD_ENDS;
    return AX_INT_LIST_ATTRIBUTE_NONE;
}

std::string ToString(AXMarkerType enum_param)
{
    switch (enum_param) {
    case AX_MARKER_TYPE_SPELLING:
        return "spelling";
    case AX_MARKER_TYPE_GRAMMAR:
        return "grammar";
    case AX_MARKER_TYPE_SPELLING_GRAMMAR:
        return "spellingGrammar";
    case AX_MARKER_TYPE_TEXT_MATCH:
        return "textMatch";
    case AX_MARKER_TYPE_SPELLING_TEXT_MATCH:
        return "spellingTextMatch";
    case AX_MARKER_TYPE_GRAMMAR_TEXT_MATCH:
        return "grammarTextMatch";
    case AX_MARKER_TYPE_SPELLING_GRAMMAR_TEXT_MATCH:
        return "spellingGrammarTextMatch";
    case AX_MARKER_TYPE_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXMarkerType ParseAXMarkerType(const std::string& enum_string)
{
    if (enum_string == "spelling")
        return AX_MARKER_TYPE_SPELLING;
    if (enum_string == "grammar")
        return AX_MARKER_TYPE_GRAMMAR;
    if (enum_string == "spellingGrammar")
        return AX_MARKER_TYPE_SPELLING_GRAMMAR;
    if (enum_string == "textMatch")
        return AX_MARKER_TYPE_TEXT_MATCH;
    if (enum_string == "spellingTextMatch")
        return AX_MARKER_TYPE_SPELLING_TEXT_MATCH;
    if (enum_string == "grammarTextMatch")
        return AX_MARKER_TYPE_GRAMMAR_TEXT_MATCH;
    if (enum_string == "spellingGrammarTextMatch")
        return AX_MARKER_TYPE_SPELLING_GRAMMAR_TEXT_MATCH;
    return AX_MARKER_TYPE_NONE;
}

std::string ToString(AXTextDirection enum_param)
{
    switch (enum_param) {
    case AX_TEXT_DIRECTION_LTR:
        return "ltr";
    case AX_TEXT_DIRECTION_RTL:
        return "rtl";
    case AX_TEXT_DIRECTION_TTB:
        return "ttb";
    case AX_TEXT_DIRECTION_BTT:
        return "btt";
    case AX_TEXT_DIRECTION_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXTextDirection ParseAXTextDirection(const std::string& enum_string)
{
    if (enum_string == "ltr")
        return AX_TEXT_DIRECTION_LTR;
    if (enum_string == "rtl")
        return AX_TEXT_DIRECTION_RTL;
    if (enum_string == "ttb")
        return AX_TEXT_DIRECTION_TTB;
    if (enum_string == "btt")
        return AX_TEXT_DIRECTION_BTT;
    return AX_TEXT_DIRECTION_NONE;
}

std::string ToString(AXTextStyle enum_param)
{
    switch (enum_param) {
    case AX_TEXT_STYLE_BOLD:
        return "textStyleBold";
    case AX_TEXT_STYLE_ITALIC:
        return "textStyleItalic";
    case AX_TEXT_STYLE_BOLD_ITALIC:
        return "textStyleBoldItalic";
    case AX_TEXT_STYLE_UNDERLINE:
        return "textStyleUnderline";
    case AX_TEXT_STYLE_BOLD_UNDERLINE:
        return "textStyleBoldUnderline";
    case AX_TEXT_STYLE_ITALIC_UNDERLINE:
        return "textStyleItalicUnderline";
    case AX_TEXT_STYLE_BOLD_ITALIC_UNDERLINE:
        return "textStyleBoldItalicUnderline";
    case AX_TEXT_STYLE_LINE_THROUGH:
        return "textStyleLineThrough";
    case AX_TEXT_STYLE_BOLD_LINE_THROUGH:
        return "textStyleBoldLineThrough";
    case AX_TEXT_STYLE_ITALIC_LINE_THROUGH:
        return "textStyleItalicLineThrough";
    case AX_TEXT_STYLE_BOLD_ITALIC_LINE_THROUGH:
        return "textStyleBoldItalicLineThrough";
    case AX_TEXT_STYLE_UNDERLINE_LINE_THROUGH:
        return "textStyleUnderlineLineThrough";
    case AX_TEXT_STYLE_BOLD_UNDERLINE_LINE_THROUGH:
        return "textStyleBoldUnderlineLineThrough";
    case AX_TEXT_STYLE_ITALIC_UNDERLINE_LINE_THROUGH:
        return "textStyleItalicUnderlineLineThrough";
    case AX_TEXT_STYLE_BOLD_ITALIC_UNDERLINE_LINE_THROUGH:
        return "textStyleBoldItalicUnderlineLineThrough";
    case AX_TEXT_STYLE_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXTextStyle ParseAXTextStyle(const std::string& enum_string)
{
    if (enum_string == "textStyleBold")
        return AX_TEXT_STYLE_BOLD;
    if (enum_string == "textStyleItalic")
        return AX_TEXT_STYLE_ITALIC;
    if (enum_string == "textStyleBoldItalic")
        return AX_TEXT_STYLE_BOLD_ITALIC;
    if (enum_string == "textStyleUnderline")
        return AX_TEXT_STYLE_UNDERLINE;
    if (enum_string == "textStyleBoldUnderline")
        return AX_TEXT_STYLE_BOLD_UNDERLINE;
    if (enum_string == "textStyleItalicUnderline")
        return AX_TEXT_STYLE_ITALIC_UNDERLINE;
    if (enum_string == "textStyleBoldItalicUnderline")
        return AX_TEXT_STYLE_BOLD_ITALIC_UNDERLINE;
    if (enum_string == "textStyleLineThrough")
        return AX_TEXT_STYLE_LINE_THROUGH;
    if (enum_string == "textStyleBoldLineThrough")
        return AX_TEXT_STYLE_BOLD_LINE_THROUGH;
    if (enum_string == "textStyleItalicLineThrough")
        return AX_TEXT_STYLE_ITALIC_LINE_THROUGH;
    if (enum_string == "textStyleBoldItalicLineThrough")
        return AX_TEXT_STYLE_BOLD_ITALIC_LINE_THROUGH;
    if (enum_string == "textStyleUnderlineLineThrough")
        return AX_TEXT_STYLE_UNDERLINE_LINE_THROUGH;
    if (enum_string == "textStyleBoldUnderlineLineThrough")
        return AX_TEXT_STYLE_BOLD_UNDERLINE_LINE_THROUGH;
    if (enum_string == "textStyleItalicUnderlineLineThrough")
        return AX_TEXT_STYLE_ITALIC_UNDERLINE_LINE_THROUGH;
    if (enum_string == "textStyleBoldItalicUnderlineLineThrough")
        return AX_TEXT_STYLE_BOLD_ITALIC_UNDERLINE_LINE_THROUGH;
    return AX_TEXT_STYLE_NONE;
}

std::string ToString(AXAriaCurrentState enum_param)
{
    switch (enum_param) {
    case AX_ARIA_CURRENT_STATE_FALSE:
        return "false";
    case AX_ARIA_CURRENT_STATE_TRUE:
        return "true";
    case AX_ARIA_CURRENT_STATE_PAGE:
        return "page";
    case AX_ARIA_CURRENT_STATE_STEP:
        return "step";
    case AX_ARIA_CURRENT_STATE_LOCATION:
        return "location";
    case AX_ARIA_CURRENT_STATE_DATE:
        return "date";
    case AX_ARIA_CURRENT_STATE_TIME:
        return "time";
    case AX_ARIA_CURRENT_STATE_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXAriaCurrentState ParseAXAriaCurrentState(const std::string& enum_string)
{
    if (enum_string == "false")
        return AX_ARIA_CURRENT_STATE_FALSE;
    if (enum_string == "true")
        return AX_ARIA_CURRENT_STATE_TRUE;
    if (enum_string == "page")
        return AX_ARIA_CURRENT_STATE_PAGE;
    if (enum_string == "step")
        return AX_ARIA_CURRENT_STATE_STEP;
    if (enum_string == "location")
        return AX_ARIA_CURRENT_STATE_LOCATION;
    if (enum_string == "date")
        return AX_ARIA_CURRENT_STATE_DATE;
    if (enum_string == "time")
        return AX_ARIA_CURRENT_STATE_TIME;
    return AX_ARIA_CURRENT_STATE_NONE;
}

std::string ToString(AXInvalidState enum_param)
{
    switch (enum_param) {
    case AX_INVALID_STATE_FALSE:
        return "false";
    case AX_INVALID_STATE_TRUE:
        return "true";
    case AX_INVALID_STATE_SPELLING:
        return "spelling";
    case AX_INVALID_STATE_GRAMMAR:
        return "grammar";
    case AX_INVALID_STATE_OTHER:
        return "other";
    case AX_INVALID_STATE_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXInvalidState ParseAXInvalidState(const std::string& enum_string)
{
    if (enum_string == "false")
        return AX_INVALID_STATE_FALSE;
    if (enum_string == "true")
        return AX_INVALID_STATE_TRUE;
    if (enum_string == "spelling")
        return AX_INVALID_STATE_SPELLING;
    if (enum_string == "grammar")
        return AX_INVALID_STATE_GRAMMAR;
    if (enum_string == "other")
        return AX_INVALID_STATE_OTHER;
    return AX_INVALID_STATE_NONE;
}

std::string ToString(AXSortDirection enum_param)
{
    switch (enum_param) {
    case AX_SORT_DIRECTION_UNSORTED:
        return "unsorted";
    case AX_SORT_DIRECTION_ASCENDING:
        return "ascending";
    case AX_SORT_DIRECTION_DESCENDING:
        return "descending";
    case AX_SORT_DIRECTION_OTHER:
        return "other";
    case AX_SORT_DIRECTION_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXSortDirection ParseAXSortDirection(const std::string& enum_string)
{
    if (enum_string == "unsorted")
        return AX_SORT_DIRECTION_UNSORTED;
    if (enum_string == "ascending")
        return AX_SORT_DIRECTION_ASCENDING;
    if (enum_string == "descending")
        return AX_SORT_DIRECTION_DESCENDING;
    if (enum_string == "other")
        return AX_SORT_DIRECTION_OTHER;
    return AX_SORT_DIRECTION_NONE;
}

std::string ToString(AXNameFrom enum_param)
{
    switch (enum_param) {
    case AX_NAME_FROM_UNINITIALIZED:
        return "uninitialized";
    case AX_NAME_FROM_ATTRIBUTE:
        return "attribute";
    case AX_NAME_FROM_CONTENTS:
        return "contents";
    case AX_NAME_FROM_PLACEHOLDER:
        return "placeholder";
    case AX_NAME_FROM_RELATED_ELEMENT:
        return "relatedElement";
    case AX_NAME_FROM_VALUE:
        return "value";
    case AX_NAME_FROM_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXNameFrom ParseAXNameFrom(const std::string& enum_string)
{
    if (enum_string == "uninitialized")
        return AX_NAME_FROM_UNINITIALIZED;
    if (enum_string == "attribute")
        return AX_NAME_FROM_ATTRIBUTE;
    if (enum_string == "contents")
        return AX_NAME_FROM_CONTENTS;
    if (enum_string == "placeholder")
        return AX_NAME_FROM_PLACEHOLDER;
    if (enum_string == "relatedElement")
        return AX_NAME_FROM_RELATED_ELEMENT;
    if (enum_string == "value")
        return AX_NAME_FROM_VALUE;
    return AX_NAME_FROM_NONE;
}

std::string ToString(AXDescriptionFrom enum_param)
{
    switch (enum_param) {
    case AX_DESCRIPTION_FROM_UNINITIALIZED:
        return "uninitialized";
    case AX_DESCRIPTION_FROM_ATTRIBUTE:
        return "attribute";
    case AX_DESCRIPTION_FROM_CONTENTS:
        return "contents";
    case AX_DESCRIPTION_FROM_PLACEHOLDER:
        return "placeholder";
    case AX_DESCRIPTION_FROM_RELATED_ELEMENT:
        return "relatedElement";
    case AX_DESCRIPTION_FROM_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXDescriptionFrom ParseAXDescriptionFrom(const std::string& enum_string)
{
    if (enum_string == "uninitialized")
        return AX_DESCRIPTION_FROM_UNINITIALIZED;
    if (enum_string == "attribute")
        return AX_DESCRIPTION_FROM_ATTRIBUTE;
    if (enum_string == "contents")
        return AX_DESCRIPTION_FROM_CONTENTS;
    if (enum_string == "placeholder")
        return AX_DESCRIPTION_FROM_PLACEHOLDER;
    if (enum_string == "relatedElement")
        return AX_DESCRIPTION_FROM_RELATED_ELEMENT;
    return AX_DESCRIPTION_FROM_NONE;
}

std::string ToString(AXEventFrom enum_param)
{
    switch (enum_param) {
    case AX_EVENT_FROM_USER:
        return "user";
    case AX_EVENT_FROM_PAGE:
        return "page";
    case AX_EVENT_FROM_ACTION:
        return "action";
    case AX_EVENT_FROM_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXEventFrom ParseAXEventFrom(const std::string& enum_string)
{
    if (enum_string == "user")
        return AX_EVENT_FROM_USER;
    if (enum_string == "page")
        return AX_EVENT_FROM_PAGE;
    if (enum_string == "action")
        return AX_EVENT_FROM_ACTION;
    return AX_EVENT_FROM_NONE;
}

std::string ToString(AXGesture enum_param)
{
    switch (enum_param) {
    case AX_GESTURE_CLICK:
        return "click";
    case AX_GESTURE_SWIPE_LEFT_1:
        return "swipeLeft1";
    case AX_GESTURE_SWIPE_UP_1:
        return "swipeUp1";
    case AX_GESTURE_SWIPE_RIGHT_1:
        return "swipeRight1";
    case AX_GESTURE_SWIPE_DOWN_1:
        return "swipeDown1";
    case AX_GESTURE_SWIPE_LEFT_2:
        return "swipeLeft2";
    case AX_GESTURE_SWIPE_UP_2:
        return "swipeUp2";
    case AX_GESTURE_SWIPE_RIGHT_2:
        return "swipeRight2";
    case AX_GESTURE_SWIPE_DOWN_2:
        return "swipeDown2";
    case AX_GESTURE_SWIPE_LEFT_3:
        return "swipeLeft3";
    case AX_GESTURE_SWIPE_UP_3:
        return "swipeUp3";
    case AX_GESTURE_SWIPE_RIGHT_3:
        return "swipeRight3";
    case AX_GESTURE_SWIPE_DOWN_3:
        return "swipeDown3";
    case AX_GESTURE_SWIPE_LEFT_4:
        return "swipeLeft4";
    case AX_GESTURE_SWIPE_UP_4:
        return "swipeUp4";
    case AX_GESTURE_SWIPE_RIGHT_4:
        return "swipeRight4";
    case AX_GESTURE_SWIPE_DOWN_4:
        return "swipeDown4";
    case AX_GESTURE_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXGesture ParseAXGesture(const std::string& enum_string)
{
    if (enum_string == "click")
        return AX_GESTURE_CLICK;
    if (enum_string == "swipeLeft1")
        return AX_GESTURE_SWIPE_LEFT_1;
    if (enum_string == "swipeUp1")
        return AX_GESTURE_SWIPE_UP_1;
    if (enum_string == "swipeRight1")
        return AX_GESTURE_SWIPE_RIGHT_1;
    if (enum_string == "swipeDown1")
        return AX_GESTURE_SWIPE_DOWN_1;
    if (enum_string == "swipeLeft2")
        return AX_GESTURE_SWIPE_LEFT_2;
    if (enum_string == "swipeUp2")
        return AX_GESTURE_SWIPE_UP_2;
    if (enum_string == "swipeRight2")
        return AX_GESTURE_SWIPE_RIGHT_2;
    if (enum_string == "swipeDown2")
        return AX_GESTURE_SWIPE_DOWN_2;
    if (enum_string == "swipeLeft3")
        return AX_GESTURE_SWIPE_LEFT_3;
    if (enum_string == "swipeUp3")
        return AX_GESTURE_SWIPE_UP_3;
    if (enum_string == "swipeRight3")
        return AX_GESTURE_SWIPE_RIGHT_3;
    if (enum_string == "swipeDown3")
        return AX_GESTURE_SWIPE_DOWN_3;
    if (enum_string == "swipeLeft4")
        return AX_GESTURE_SWIPE_LEFT_4;
    if (enum_string == "swipeUp4")
        return AX_GESTURE_SWIPE_UP_4;
    if (enum_string == "swipeRight4")
        return AX_GESTURE_SWIPE_RIGHT_4;
    if (enum_string == "swipeDown4")
        return AX_GESTURE_SWIPE_DOWN_4;
    return AX_GESTURE_NONE;
}

std::string ToString(AXTextAffinity enum_param)
{
    switch (enum_param) {
    case AX_TEXT_AFFINITY_DOWNSTREAM:
        return "downstream";
    case AX_TEXT_AFFINITY_UPSTREAM:
        return "upstream";
    case AX_TEXT_AFFINITY_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXTextAffinity ParseAXTextAffinity(const std::string& enum_string)
{
    if (enum_string == "downstream")
        return AX_TEXT_AFFINITY_DOWNSTREAM;
    if (enum_string == "upstream")
        return AX_TEXT_AFFINITY_UPSTREAM;
    return AX_TEXT_AFFINITY_NONE;
}

std::string ToString(AXTreeOrder enum_param)
{
    switch (enum_param) {
    case AX_TREE_ORDER_UNDEFINED:
        return "undefined";
    case AX_TREE_ORDER_BEFORE:
        return "before";
    case AX_TREE_ORDER_EQUAL:
        return "equal";
    case AX_TREE_ORDER_AFTER:
        return "after";
    case AX_TREE_ORDER_NONE:
        return "";
    }
    NOTREACHED();
    return "";
}

AXTreeOrder ParseAXTreeOrder(const std::string& enum_string)
{
    if (enum_string == "undefined")
        return AX_TREE_ORDER_UNDEFINED;
    if (enum_string == "before")
        return AX_TREE_ORDER_BEFORE;
    if (enum_string == "equal")
        return AX_TREE_ORDER_EQUAL;
    if (enum_string == "after")
        return AX_TREE_ORDER_AFTER;
    return AX_TREE_ORDER_NONE;
}

} // namespace ui
