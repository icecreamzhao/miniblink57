
#ifndef net_DefaultFullPath_h
#define net_DefaultFullPath_h

#include "third_party/WebKit/Source/wtf/text/WTFString.h"

namespace net {

std::string getDefaultLocalStorageFullPath();
void setDefaultLocalStorageFullPath(const std::string& path);
std::string getDefaultCookiesFullpath();

}

#endif // net_DefaultFullPath_h