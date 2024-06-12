#ifndef WTF_MBCHAR_H
#define WTF_MBCHAR_H

// ugly hack to make UChar compatible with JSChar in API/JSStringRef.h
#if defined(WIN32) // || defined(Q_OS_WIN) || COMPILER(WINSCW) || (COMPILER(RVCT) && !OS(LINUX))
typedef wchar_t UChar;
#define u16(x) L ## x
#else
#define u16(x) u ## x
//typedef uint16_t UChar;
typedef char16_t UChar;
#endif

#if 1//!USE(QT_ICU_TEXT_BREAKING)
typedef uint32_t UChar32;
#endif

inline size_t u16len(const UChar* s)
{
    size_t i = 0;
    for (; s[i]; ++i) {
    }
    return i;
}

#endif // WTF_MBCHAR_H