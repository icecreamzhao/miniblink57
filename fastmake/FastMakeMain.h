
#ifndef FastMakeMain_h
#define FastMakeMain_h

#include <string>

enum RebuildOpt {
    kRebuildOptAll,
    kRebuildOptPrebuildSrcAndLink, // Ԥ����
    kRebuildOptNotCompileOnlyLink, //ֻ����
    kRebuildOptCompileTimeOutFile, // ���볬ʱ�ļ�
};

void fmFastBuild(const std::wstring& buildJsonPath, RebuildOpt opt); // ����ǲ��Ե�
void fmBuild(const std::wstring& buildJsonPath);

#endif