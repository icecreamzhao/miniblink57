/**
 * Copyright (C) 2008 Torch Mobile Inc. All rights reserved. (http://www.torchmobile.com/)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#include "config.h"

#if ENABLE_WML
#include "WMLVariables.h"

#include "WMLDocument.h"
#include <wtf/ASCIICType.h>

namespace blink {

// WML variables specification, excluding the
// pre-WML 1.0 deprecated variable syntax
//
// varname = ("_" | alpha) ("_" | alpha | digit)*
// conv = ":" ("e" ("scape")? | "n" ("oesc")? | "u" ("nesc")?)
// var = ("$" varname) | ("$(" varname (conv)? ")")

static bool isValidFirstVariableNameCharacter(const UChar& character)
{
    return WTF::isASCIIAlpha(character)
        || character == '_';
}

static bool isValidVariableNameCharacter(const UChar& character)
{
    return WTF::isASCIIAlpha(character)
        || WTF::isASCIIDigit(character)
        || character == '_';
}

static bool isValidVariableEscapingModeString(const String& mode, WMLVariableEscapingMode& escapeMode)
{
    if (mode == "e" || mode == "escape")
        escapeMode = WMLVariableEscapingEscape;
    else if (mode == "u" || mode == "unesc")
        escapeMode = WMLVariableEscapingUnescape;
    else if (mode == "n" || mode == "noesc")
        escapeMode = WMLVariableEscapingNone;
    else
        return false;

    return true;
}

bool isValidVariableName(const String& name)
{
    if (name.isEmpty() || name.isNull())
        return false;

    String nameW = name;
    if (nameW.is8Bit())
        nameW.ensure16Bit();
    const UChar* characters = name.characters16();

    if (!isValidFirstVariableNameCharacter(characters[0]))
        return false;

    unsigned length = nameW.length();
    for (unsigned i = 1; i < length; ++i) {
        if (!isValidVariableNameCharacter(characters[i]))
            return false;
    }

    return true;
}

bool containsVariableReference(const String& text, bool& isValid)
{
    isValid = true;
    bool foundReference = false;
    bool finished = false;
    int currentPosition = 0;

    if (text.isNull() || text.isEmpty())
        return false;

    String textW = text;
    if (textW.is8Bit())
        textW.ensure16Bit();
    const UChar* characters = textW.characters16();

    while (!finished) {
        // Find beginning of variable reference
        int referenceStartPosition = textW.find('$', currentPosition);
        if (referenceStartPosition == -1) {
            finished = true;
            break;
        }

        foundReference = true;

        int nameStartPosition = referenceStartPosition + 1;
        int nameEndPosition = -1;

        if (characters[nameStartPosition] == '(') {
            // If the input string contains an open brace, a close brace must exist as well
            nameEndPosition = textW.find(')', nameStartPosition + 1);
            if (nameEndPosition == -1) {
                finished = true;
                isValid = false;
                break;
            }

            ++nameStartPosition;
        } else {
            int length = textW.length();
            for (nameEndPosition = nameStartPosition; nameEndPosition < length; ++nameEndPosition) {
                if (!isValidVariableNameCharacter(textW[nameEndPosition]))
                    break;
            }
        }

        if (nameEndPosition < nameStartPosition) {
            finished = true;
            isValid = false;
            break;
        }

        // Eventually split of conversion string, and check its syntax afterwards
        String conversionString;
        String variableName = textW.substring(nameStartPosition, nameEndPosition - nameStartPosition);

        int conversionStringStart = variableName.find(':');
        if (conversionStringStart != -1) {
            conversionString = variableName.substring(conversionStringStart + 1, variableName.length() - (conversionStringStart + 1));
            variableName = variableName.left(conversionStringStart);
        }

        isValid = isValidVariableName(variableName);
        if (!isValid) {
            finished = true;
            break;
        }

        if (!conversionString.isEmpty()) {
            isValid = isValidVariableName(conversionString);
            if (!isValid) {
                finished = true;
                break;
            }

            WMLVariableEscapingMode escapeMode = WMLVariableEscapingNone;
            isValid = isValidVariableEscapingModeString(conversionString, escapeMode);
            if (!isValid) {
                finished = true;
                break;
            }
        }

        currentPosition = nameEndPosition;
    }

    return foundReference;
}

// SAMSUNG_WML_CRASH_FIX+
static bool containsSelfReference(const String& aname, const String& avalue)
{
    String value = avalue;
    String name = aname;

    if (value[0] == '$') {
        if (value[1] != '(') {
            value.remove(0, 1);
        } else {
            value.remove(0, 2);
            int endpos = value.find(")");
            value.remove(endpos, 1);
        }

        if (value == name)
            return true;
    }

    return false;
}

// SAMSUNG_WML_CRASH_FIX-
String substituteVariableReferences(const String& reference, Document* document, WMLVariableEscapingMode escapeMode)
{
    ASSERT(document);

    if (reference.isEmpty() || reference.isNull())
        return reference;

    WMLPageState* pageState = wmlPageStateForDocument(document);
    if (!pageState)
        return reference;

    String referenceW = reference;
    if (referenceW.is8Bit())
        referenceW.ensure16Bit();

    bool isValid = true;
    String remainingInput = referenceW;
    String result;

    while (!remainingInput.isEmpty()) {
        ASSERT(isValid);

        int start = remainingInput.find("$");
        if (start == -1) {
            // Consume all remaining characters, as there's nothing more to substitute
            result.append(remainingInput);
            break;
        }

        // Consume all characters until the variable reference beginning
        result.append(remainingInput.left(start));
        remainingInput.remove(0, start);

        // Transform adjacent dollar signs into a single dollar sign as string literal
        if (remainingInput[1] == '$') {
            result.append("$");
            remainingInput.remove(0, 2);
            continue;
        }

        String variableName;
        String conversionMode;

        if (remainingInput[1] == '(') {
            int referenceEndPosition = remainingInput.find(")");
            if (referenceEndPosition == -1) {
                isValid = false;
                break;
            }

            variableName = remainingInput.substring(2, referenceEndPosition - 2);
            remainingInput.remove(0, referenceEndPosition + 1);

            // Determine variable conversion mode string
            int pos = variableName.find(':');
            if (pos != -1) {
                conversionMode = variableName.substring(pos + 1, variableName.length() - (pos + 1));
                variableName = variableName.left(pos);
            }
        } else {
            int length = remainingInput.length();
            int referenceEndPosition = 1;

            for (; referenceEndPosition < length; ++referenceEndPosition) {
                if (!isValidVariableNameCharacter(remainingInput[referenceEndPosition]))
                    break;
            }

            variableName = remainingInput.substring(1, referenceEndPosition - 1);
            remainingInput.remove(0, referenceEndPosition);
        }

        isValid = isValidVariableName(variableName);
        if (!isValid)
            break;

        ASSERT(!variableName.isEmpty());

        String tempVariableName = pageState->getVariable(variableName);
        if (tempVariableName.isEmpty() || tempVariableName.isNull())
            continue;

        String variableValue = tempVariableName;
        if (tempVariableName.is8Bit())
            variableValue.ensure16Bit();

        if (containsVariableReference(variableValue, isValid)) {
            if (!isValid)
                break;

            // SAMSUNG_WML_CRASH_FIX+
            if (containsSelfReference(variableName, variableValue))
                continue;
            // SAMSUNG_WML_CRASH_FIX-
            variableValue = substituteVariableReferences(variableValue, document, escapeMode);
            continue;
        }

        if (!conversionMode.isEmpty()) {
            // Override default escape mode, if desired
            WMLVariableEscapingMode specifiedEscapeMode = WMLVariableEscapingNone;
            if ((isValid = isValidVariableEscapingModeString(conversionMode, specifiedEscapeMode)))
                escapeMode = specifiedEscapeMode;

            if (!isValid)
                break;
        }

        switch (escapeMode) {
        case WMLVariableEscapingNone:
            break;
        case WMLVariableEscapingEscape:
            variableValue = encodeWithURLEscapeSequences(variableValue);
            break;
        case WMLVariableEscapingUnescape:
            variableValue = decodeURLEscapeSequences(variableValue);
            break;
        }

        result.append(variableValue);
        ASSERT(isValid);
    }

    if (!isValid) {
        reportWMLError(document, WMLErrorInvalidVariableReference);
        return referenceW;
    }

    return result;
}

}

#endif
