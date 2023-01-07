#pragma once
#include <windows.h>
#include <xstring>
#include <vector>

std::string utf16ToUtf8(LPCWSTR lpszSrc);

std::wstring utf8ToUtf16(const std::string& utf8);