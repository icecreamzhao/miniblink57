
#ifndef FastMakeMain_h
#define FastMakeMain_h

#include <string>

enum RebuildOpt {
    kRebuildOptAll,
    kRebuildOptPrebuildSrcAndLink,
    kRebuildOptNotCompileOnlyLink,
    kRebuildOptCompileTimeOutFile,
};

void fmFastBuild(const std::wstring& buildJsonPath, RebuildOpt opt); // 这个是测试的
void fmBuild(const std::wstring& buildJsonPath);

#endif