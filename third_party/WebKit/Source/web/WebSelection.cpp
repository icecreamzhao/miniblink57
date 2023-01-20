// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"

>>>>>>> miniblink49
#include "public/web/WebSelection.h"

#include "core/editing/SelectionType.h"
#include "core/layout/compositing/CompositedSelection.h"

namespace blink {

<<<<<<< HEAD
static WebSelectionBound getWebSelectionBound(
    const CompositedSelection& selection,
    bool isStart)
{
    DCHECK_NE(selection.type, NoSelection);
    const CompositedSelectionBound& bound = isStart ? selection.start : selection.end;
    DCHECK(bound.layer);
=======
static WebSelectionBound getWebSelectionBound(const CompositedSelection& selection, bool isStart)
{
    ASSERT(selection.type != NoSelection);
    const CompositedSelectionBound& bound = isStart ? selection.start : selection.end;
    ASSERT(bound.layer);
>>>>>>> miniblink49

    WebSelectionBound::Type type = WebSelectionBound::Caret;
    if (selection.type == RangeSelection) {
        if (isStart)
<<<<<<< HEAD
            type = bound.isTextDirectionRTL ? WebSelectionBound::SelectionRight
                                            : WebSelectionBound::SelectionLeft;
        else
            type = bound.isTextDirectionRTL ? WebSelectionBound::SelectionLeft
                                            : WebSelectionBound::SelectionRight;
=======
            type = bound.isTextDirectionRTL ? WebSelectionBound::SelectionRight : WebSelectionBound::SelectionLeft;
        else
            type = bound.isTextDirectionRTL ? WebSelectionBound::SelectionLeft : WebSelectionBound::SelectionRight;
>>>>>>> miniblink49
    }

    WebSelectionBound result(type);
    result.layerId = bound.layer->platformLayer()->id();
    result.edgeTopInLayer = roundedIntPoint(bound.edgeTopInLayer);
    result.edgeBottomInLayer = roundedIntPoint(bound.edgeBottomInLayer);
    result.isTextDirectionRTL = bound.isTextDirectionRTL;
    return result;
}

<<<<<<< HEAD
// SelectionType enums have the same values; enforced in
// AssertMatchingEnums.cpp.
=======
// SelectionType enums have the same values; enforced in AssertMatchingEnums.cpp.
>>>>>>> miniblink49
WebSelection::WebSelection(const CompositedSelection& selection)
    : m_selectionType(static_cast<WebSelection::SelectionType>(selection.type))
    , m_start(getWebSelectionBound(selection, true))
    , m_end(getWebSelectionBound(selection, false))
    , m_isEditable(selection.isEditable)
<<<<<<< HEAD
    , m_isEmptyTextControl(selection.isEmptyTextControl)
=======
    , m_isEmptyTextFormControl(selection.isEmptyTextFormControl)
>>>>>>> miniblink49
{
}

WebSelection::WebSelection(const WebSelection& other)
    : m_selectionType(other.m_selectionType)
    , m_start(other.m_start)
    , m_end(other.m_end)
    , m_isEditable(other.m_isEditable)
<<<<<<< HEAD
    , m_isEmptyTextControl(other.m_isEmptyTextControl)
=======
    , m_isEmptyTextFormControl(other.m_isEmptyTextFormControl)
>>>>>>> miniblink49
{
}

} // namespace blink
