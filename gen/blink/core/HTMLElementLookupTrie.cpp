// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "HTMLElementLookupTrie.h"

#include "HTMLNames.h"

namespace blink {

using namespace HTMLNames;

StringImpl* lookupHTMLTag(const UChar* data, unsigned length)
{
    DCHECK(data);
    DCHECK(length);
    switch (length) {
    case 1:
        switch (data[0]) {
        case 'a':
            return aTag.localName().impl();
        case 'b':
            return bTag.localName().impl();
        case 'i':
            return iTag.localName().impl();
        case 'p':
            return pTag.localName().impl();
        case 'q':
            return qTag.localName().impl();
        case 's':
            return sTag.localName().impl();
        case 'u':
            return uTag.localName().impl();
        }
        break;
    case 2:
        switch (data[0]) {
        case 'b':
            if (data[1] == 'r')
                return brTag.localName().impl();
            break;
        case 'd':
            switch (data[1]) {
            case 'd':
                return ddTag.localName().impl();
            case 'l':
                return dlTag.localName().impl();
            case 't':
                return dtTag.localName().impl();
            }
            break;
        case 'e':
            if (data[1] == 'm')
                return emTag.localName().impl();
            break;
        case 'h':
            switch (data[1]) {
            case '1':
                return h1Tag.localName().impl();
            case '2':
                return h2Tag.localName().impl();
            case '3':
                return h3Tag.localName().impl();
            case '4':
                return h4Tag.localName().impl();
            case '5':
                return h5Tag.localName().impl();
            case '6':
                return h6Tag.localName().impl();
            case 'r':
                return hrTag.localName().impl();
            }
            break;
        case 'l':
            if (data[1] == 'i')
                return liTag.localName().impl();
            break;
        case 'o':
            if (data[1] == 'l')
                return olTag.localName().impl();
            break;
        case 'r':
            switch (data[1]) {
            case 'b':
                return rbTag.localName().impl();
            case 'p':
                return rpTag.localName().impl();
            case 't':
                return rtTag.localName().impl();
            }
            break;
        case 't':
            switch (data[1]) {
            case 'd':
                return tdTag.localName().impl();
            case 'h':
                return thTag.localName().impl();
            case 'r':
                return trTag.localName().impl();
            case 't':
                return ttTag.localName().impl();
            }
            break;
        case 'u':
            if (data[1] == 'l')
                return ulTag.localName().impl();
            break;
        }
        break;
    case 3:
        switch (data[0]) {
        case 'b':
            switch (data[1]) {
            case 'd':
                switch (data[2]) {
                case 'i':
                    return bdiTag.localName().impl();
                case 'o':
                    return bdoTag.localName().impl();
                }
                break;
            case 'i':
                if (data[2] == 'g')
                    return bigTag.localName().impl();
                break;
            }
            break;
        case 'c':
            if (data[1] == 'o' && data[2] == 'l')
                return colTag.localName().impl();
            break;
        case 'd':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'l')
                    return delTag.localName().impl();
                break;
            case 'f':
                if (data[2] == 'n')
                    return dfnTag.localName().impl();
                break;
            case 'i':
                switch (data[2]) {
                case 'r':
                    return dirTag.localName().impl();
                case 'v':
                    return divTag.localName().impl();
                }
                break;
            }
            break;
        case 'i':
            switch (data[1]) {
            case 'm':
                if (data[2] == 'g')
                    return imgTag.localName().impl();
                break;
            case 'n':
                if (data[2] == 's')
                    return insTag.localName().impl();
                break;
            }
            break;
        case 'k':
            if (data[1] == 'b' && data[2] == 'd')
                return kbdTag.localName().impl();
            break;
        case 'm':
            if (data[1] == 'a' && data[2] == 'p')
                return mapTag.localName().impl();
            break;
        case 'n':
            if (data[1] == 'a' && data[2] == 'v')
                return navTag.localName().impl();
            break;
        case 'p':
            if (data[1] == 'r' && data[2] == 'e')
                return preTag.localName().impl();
            break;
        case 'r':
            if (data[1] == 't' && data[2] == 'c')
                return rtcTag.localName().impl();
            break;
        case 's':
            switch (data[1]) {
            case 'u':
                switch (data[2]) {
                case 'b':
                    return subTag.localName().impl();
                case 'p':
                    return supTag.localName().impl();
                }
                break;
            }
            break;
        case 'v':
            if (data[1] == 'a' && data[2] == 'r')
                return varTag.localName().impl();
            break;
        case 'w':
            if (data[1] == 'b' && data[2] == 'r')
                return wbrTag.localName().impl();
            break;
        case 'x':
            if (data[1] == 'm' && data[2] == 'p')
                return xmpTag.localName().impl();
            break;
        }
        break;
    case 4:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'b':
                if (data[2] == 'b' && data[3] == 'r')
                    return abbrTag.localName().impl();
                break;
            case 'r':
                if (data[2] == 'e' && data[3] == 'a')
                    return areaTag.localName().impl();
                break;
            }
            break;
        case 'b':
            switch (data[1]) {
            case 'a':
                if (data[2] == 's' && data[3] == 'e')
                    return baseTag.localName().impl();
                break;
            case 'o':
                if (data[2] == 'd' && data[3] == 'y')
                    return bodyTag.localName().impl();
                break;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'i':
                if (data[2] == 't' && data[3] == 'e')
                    return citeTag.localName().impl();
                break;
            case 'o':
                if (data[2] == 'd' && data[3] == 'e')
                    return codeTag.localName().impl();
                break;
            }
            break;
        case 'f':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'n':
                    if (data[3] == 't')
                        return fontTag.localName().impl();
                    break;
                case 'r':
                    if (data[3] == 'm')
                        return formTag.localName().impl();
                    break;
                }
                break;
            }
            break;
        case 'h':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'a' && data[3] == 'd')
                    return headTag.localName().impl();
                break;
            case 't':
                if (data[2] == 'm' && data[3] == 'l')
                    return htmlTag.localName().impl();
                break;
            }
            break;
        case 'l':
            if (data[1] == 'i' && data[2] == 'n' && data[3] == 'k')
                return linkTag.localName().impl();
            break;
        case 'm':
            switch (data[1]) {
            case 'a':
                switch (data[2]) {
                case 'i':
                    if (data[3] == 'n')
                        return mainTag.localName().impl();
                    break;
                case 'r':
                    if (data[3] == 'k')
                        return markTag.localName().impl();
                    break;
                }
                break;
            case 'e':
                switch (data[2]) {
                case 'n':
                    if (data[3] == 'u')
                        return menuTag.localName().impl();
                    break;
                case 't':
                    if (data[3] == 'a')
                        return metaTag.localName().impl();
                    break;
                }
                break;
            }
            break;
        case 'n':
            if (data[1] == 'o' && data[2] == 'b' && data[3] == 'r')
                return nobrTag.localName().impl();
            break;
        case 'r':
            if (data[1] == 'u' && data[2] == 'b' && data[3] == 'y')
                return rubyTag.localName().impl();
            break;
        case 's':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'm' && data[3] == 'p')
                    return sampTag.localName().impl();
                break;
            case 'l':
                if (data[2] == 'o' && data[3] == 't')
                    return slotTag.localName().impl();
                break;
            case 'p':
                if (data[2] == 'a' && data[3] == 'n')
                    return spanTag.localName().impl();
                break;
            }
            break;
        }
        break;
    case 5:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 's':
                if (data[2] == 'i' && data[3] == 'd' && data[4] == 'e')
                    return asideTag.localName().impl();
                break;
            case 'u':
                if (data[2] == 'd' && data[3] == 'i' && data[4] == 'o')
                    return audioTag.localName().impl();
                break;
            }
            break;
        case 'e':
            if (data[1] == 'm' && data[2] == 'b' && data[3] == 'e' && data[4] == 'd')
                return embedTag.localName().impl();
            break;
        case 'f':
            if (data[1] == 'r' && data[2] == 'a' && data[3] == 'm' && data[4] == 'e')
                return frameTag.localName().impl();
            break;
        case 'i':
            switch (data[1]) {
            case 'm':
                if (data[2] == 'a' && data[3] == 'g' && data[4] == 'e')
                    return imageTag.localName().impl();
                break;
            case 'n':
                if (data[2] == 'p' && data[3] == 'u' && data[4] == 't')
                    return inputTag.localName().impl();
                break;
            }
            break;
        case 'l':
            switch (data[1]) {
            case 'a':
                switch (data[2]) {
                case 'b':
                    if (data[3] == 'e' && data[4] == 'l')
                        return labelTag.localName().impl();
                    break;
                case 'y':
                    if (data[3] == 'e' && data[4] == 'r')
                        return layerTag.localName().impl();
                    break;
                }
                break;
            }
            break;
        case 'm':
            if (data[1] == 'e' && data[2] == 't' && data[3] == 'e' && data[4] == 'r')
                return meterTag.localName().impl();
            break;
        case 'p':
            if (data[1] == 'a' && data[2] == 'r' && data[3] == 'a' && data[4] == 'm')
                return paramTag.localName().impl();
            break;
        case 's':
            switch (data[1]) {
            case 'm':
                if (data[2] == 'a' && data[3] == 'l' && data[4] == 'l')
                    return smallTag.localName().impl();
                break;
            case 't':
                if (data[2] == 'y' && data[3] == 'l' && data[4] == 'e')
                    return styleTag.localName().impl();
                break;
            }
            break;
        case 't':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'b' && data[3] == 'l' && data[4] == 'e')
                    return tableTag.localName().impl();
                break;
            case 'b':
                if (data[2] == 'o' && data[3] == 'd' && data[4] == 'y')
                    return tbodyTag.localName().impl();
                break;
            case 'f':
                if (data[2] == 'o' && data[3] == 'o' && data[4] == 't')
                    return tfootTag.localName().impl();
                break;
            case 'h':
                if (data[2] == 'e' && data[3] == 'a' && data[4] == 'd')
                    return theadTag.localName().impl();
                break;
            case 'i':
                if (data[2] == 't' && data[3] == 'l' && data[4] == 'e')
                    return titleTag.localName().impl();
                break;
            case 'r':
                if (data[2] == 'a' && data[3] == 'c' && data[4] == 'k')
                    return trackTag.localName().impl();
                break;
            }
            break;
        case 'v':
            if (data[1] == 'i' && data[2] == 'd' && data[3] == 'e' && data[4] == 'o')
                return videoTag.localName().impl();
            break;
        }
        break;
    case 6:
        switch (data[0]) {
        case 'a':
            if (data[1] == 'p' && data[2] == 'p' && data[3] == 'l' && data[4] == 'e' && data[5] == 't')
                return appletTag.localName().impl();
            break;
        case 'b':
            if (data[1] == 'u' && data[2] == 't' && data[3] == 't' && data[4] == 'o' && data[5] == 'n')
                return buttonTag.localName().impl();
            break;
        case 'c':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'n' && data[3] == 'v' && data[4] == 'a' && data[5] == 's')
                    return canvasTag.localName().impl();
                break;
            case 'e':
                if (data[2] == 'n' && data[3] == 't' && data[4] == 'e' && data[5] == 'r')
                    return centerTag.localName().impl();
                break;
            }
            break;
        case 'd':
            if (data[1] == 'i' && data[2] == 'a' && data[3] == 'l' && data[4] == 'o' && data[5] == 'g')
                return dialogTag.localName().impl();
            break;
        case 'f':
            switch (data[1]) {
            case 'i':
                if (data[2] == 'g' && data[3] == 'u' && data[4] == 'r' && data[5] == 'e')
                    return figureTag.localName().impl();
                break;
            case 'o':
                if (data[2] == 'o' && data[3] == 't' && data[4] == 'e' && data[5] == 'r')
                    return footerTag.localName().impl();
                break;
            }
            break;
        case 'h':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'a' && data[3] == 'd' && data[4] == 'e' && data[5] == 'r')
                    return headerTag.localName().impl();
                break;
            case 'g':
                if (data[2] == 'r' && data[3] == 'o' && data[4] == 'u' && data[5] == 'p')
                    return hgroupTag.localName().impl();
                break;
            }
            break;
        case 'i':
            if (data[1] == 'f' && data[2] == 'r' && data[3] == 'a' && data[4] == 'm' && data[5] == 'e')
                return iframeTag.localName().impl();
            break;
        case 'k':
            if (data[1] == 'e' && data[2] == 'y' && data[3] == 'g' && data[4] == 'e' && data[5] == 'n')
                return keygenTag.localName().impl();
            break;
        case 'l':
            if (data[1] == 'e' && data[2] == 'g' && data[3] == 'e' && data[4] == 'n' && data[5] == 'd')
                return legendTag.localName().impl();
            break;
        case 'o':
            switch (data[1]) {
            case 'b':
                if (data[2] == 'j' && data[3] == 'e' && data[4] == 'c' && data[5] == 't')
                    return objectTag.localName().impl();
                break;
            case 'p':
                if (data[2] == 't' && data[3] == 'i' && data[4] == 'o' && data[5] == 'n')
                    return optionTag.localName().impl();
                break;
            case 'u':
                if (data[2] == 't' && data[3] == 'p' && data[4] == 'u' && data[5] == 't')
                    return outputTag.localName().impl();
                break;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'c':
                if (data[2] == 'r' && data[3] == 'i' && data[4] == 'p' && data[5] == 't')
                    return scriptTag.localName().impl();
                break;
            case 'e':
                if (data[2] == 'l' && data[3] == 'e' && data[4] == 'c' && data[5] == 't')
                    return selectTag.localName().impl();
                break;
            case 'h':
                if (data[2] == 'a' && data[3] == 'd' && data[4] == 'o' && data[5] == 'w')
                    return shadowTag.localName().impl();
                break;
            case 'o':
                if (data[2] == 'u' && data[3] == 'r' && data[4] == 'c' && data[5] == 'e')
                    return sourceTag.localName().impl();
                break;
            case 't':
                switch (data[2]) {
                case 'r':
                    switch (data[3]) {
                    case 'i':
                        if (data[4] == 'k' && data[5] == 'e')
                            return strikeTag.localName().impl();
                        break;
                    case 'o':
                        if (data[4] == 'n' && data[5] == 'g')
                            return strongTag.localName().impl();
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        }
        break;
    case 7:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'c':
                if (data[2] == 'r' && data[3] == 'o' && data[4] == 'n' && data[5] == 'y' && data[6] == 'm')
                    return acronymTag.localName().impl();
                break;
            case 'd':
                if (data[2] == 'd' && data[3] == 'r' && data[4] == 'e' && data[5] == 's' && data[6] == 's')
                    return addressTag.localName().impl();
                break;
            case 'r':
                if (data[2] == 't' && data[3] == 'i' && data[4] == 'c' && data[5] == 'l' && data[6] == 'e')
                    return articleTag.localName().impl();
                break;
            }
            break;
        case 'b':
            if (data[1] == 'g' && data[2] == 's' && data[3] == 'o' && data[4] == 'u' && data[5] == 'n' && data[6] == 'd')
                return bgsoundTag.localName().impl();
            break;
        case 'c':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'p' && data[3] == 't' && data[4] == 'i' && data[5] == 'o' && data[6] == 'n')
                    return captionTag.localName().impl();
                break;
            case 'o':
                switch (data[2]) {
                case 'm':
                    if (data[3] == 'm' && data[4] == 'a' && data[5] == 'n' && data[6] == 'd')
                        return commandTag.localName().impl();
                    break;
                case 'n':
                    if (data[3] == 't' && data[4] == 'e' && data[5] == 'n' && data[6] == 't')
                        return contentTag.localName().impl();
                    break;
                }
                break;
            }
            break;
        case 'd':
            if (data[1] == 'e' && data[2] == 't' && data[3] == 'a' && data[4] == 'i' && data[5] == 'l' && data[6] == 's')
                return detailsTag.localName().impl();
            break;
        case 'l':
            if (data[1] == 'i' && data[2] == 's' && data[3] == 't' && data[4] == 'i' && data[5] == 'n' && data[6] == 'g')
                return listingTag.localName().impl();
            break;
        case 'm':
            if (data[1] == 'a' && data[2] == 'r' && data[3] == 'q' && data[4] == 'u' && data[5] == 'e' && data[6] == 'e')
                return marqueeTag.localName().impl();
            break;
        case 'n':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'e':
                    if (data[3] == 'm' && data[4] == 'b' && data[5] == 'e' && data[6] == 'd')
                        return noembedTag.localName().impl();
                    break;
                case 'l':
                    if (data[3] == 'a' && data[4] == 'y' && data[5] == 'e' && data[6] == 'r')
                        return nolayerTag.localName().impl();
                    break;
                }
                break;
            }
            break;
        case 'p':
            if (data[1] == 'i' && data[2] == 'c' && data[3] == 't' && data[4] == 'u' && data[5] == 'r' && data[6] == 'e')
                return pictureTag.localName().impl();
            break;
        case 's':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'c' && data[3] == 't' && data[4] == 'i' && data[5] == 'o' && data[6] == 'n')
                    return sectionTag.localName().impl();
                break;
            case 'u':
                if (data[2] == 'm' && data[3] == 'm' && data[4] == 'a' && data[5] == 'r' && data[6] == 'y')
                    return summaryTag.localName().impl();
                break;
            }
            break;
        }
        break;
    case 8:
        switch (data[0]) {
        case 'b':
            if (data[1] == 'a' && data[2] == 's' && data[3] == 'e' && data[4] == 'f' && data[5] == 'o' && data[6] == 'n' && data[7] == 't')
                return basefontTag.localName().impl();
            break;
        case 'c':
            if (data[1] == 'o' && data[2] == 'l' && data[3] == 'g' && data[4] == 'r' && data[5] == 'o' && data[6] == 'u' && data[7] == 'p')
                return colgroupTag.localName().impl();
            break;
        case 'd':
            if (data[1] == 'a' && data[2] == 't' && data[3] == 'a' && data[4] == 'l' && data[5] == 'i' && data[6] == 's' && data[7] == 't')
                return datalistTag.localName().impl();
            break;
        case 'f':
            switch (data[1]) {
            case 'i':
                if (data[2] == 'e' && data[3] == 'l' && data[4] == 'd' && data[5] == 's' && data[6] == 'e' && data[7] == 't')
                    return fieldsetTag.localName().impl();
                break;
            case 'r':
                if (data[2] == 'a' && data[3] == 'm' && data[4] == 'e' && data[5] == 's' && data[6] == 'e' && data[7] == 't')
                    return framesetTag.localName().impl();
                break;
            }
            break;
        case 'm':
            if (data[1] == 'e' && data[2] == 'n' && data[3] == 'u' && data[4] == 'i' && data[5] == 't' && data[6] == 'e' && data[7] == 'm')
                return menuitemTag.localName().impl();
            break;
        case 'n':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'f':
                    if (data[3] == 'r' && data[4] == 'a' && data[5] == 'm' && data[6] == 'e' && data[7] == 's')
                        return noframesTag.localName().impl();
                    break;
                case 's':
                    if (data[3] == 'c' && data[4] == 'r' && data[5] == 'i' && data[6] == 'p' && data[7] == 't')
                        return noscriptTag.localName().impl();
                    break;
                }
                break;
            }
            break;
        case 'o':
            if (data[1] == 'p' && data[2] == 't' && data[3] == 'g' && data[4] == 'r' && data[5] == 'o' && data[6] == 'u' && data[7] == 'p')
                return optgroupTag.localName().impl();
            break;
        case 'p':
            if (data[1] == 'r' && data[2] == 'o' && data[3] == 'g' && data[4] == 'r' && data[5] == 'e' && data[6] == 's' && data[7] == 's')
                return progressTag.localName().impl();
            break;
        case 't':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'm':
                    if (data[3] == 'p' && data[4] == 'l' && data[5] == 'a' && data[6] == 't' && data[7] == 'e')
                        return templateTag.localName().impl();
                    break;
                case 'x':
                    if (data[3] == 't' && data[4] == 'a' && data[5] == 'r' && data[6] == 'e' && data[7] == 'a')
                        return textareaTag.localName().impl();
                    break;
                }
                break;
            }
            break;
        }
        break;
    case 9:
        switch (data[0]) {
        case 'p':
            if (data[1] == 'l' && data[2] == 'a' && data[3] == 'i' && data[4] == 'n' && data[5] == 't' && data[6] == 'e' && data[7] == 'x' && data[8] == 't')
                return plaintextTag.localName().impl();
            break;
        }
        break;
    case 10:
        switch (data[0]) {
        case 'b':
            if (data[1] == 'l' && data[2] == 'o' && data[3] == 'c' && data[4] == 'k' && data[5] == 'q' && data[6] == 'u' && data[7] == 'o' && data[8] == 't' && data[9] == 'e')
                return blockquoteTag.localName().impl();
            break;
        case 'f':
            if (data[1] == 'i' && data[2] == 'g' && data[3] == 'c' && data[4] == 'a' && data[5] == 'p' && data[6] == 't' && data[7] == 'i' && data[8] == 'o' && data[9] == 'n')
                return figcaptionTag.localName().impl();
            break;
        }
        break;
    }
    return nullptr;
}

} // namespace blink
