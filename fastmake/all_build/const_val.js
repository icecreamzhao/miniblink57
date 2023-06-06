
const cmdstr = qfmGetCmdline();
jsPrint("cmdstr:" + cmdstr);
const cmd = JSON.parse(cmdstr);

var constValue = {
    "sdkPath":"C:/cygwin64/usr/local/x86_64-unknown-linux-gnu/x86_64-unknown-linux-gnu",
//    "clangPath":     "C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/llvm/prebuilt/windows-x86_64/bin",
//    "ndkIncludePath":"C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/llvm/prebuilt/windows-x86_64/lib64/clang/5.0/include",
//    "ndkBinPath":    "C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/aarch64-linux-android-4.9/prebuilt/windows-x86_64/aarch64-linux-android/bin",

    "clangPath":     "P:/Microsoft/AndroidNDK64/android-ndk-r21e/toolchains/llvm/prebuilt/windows-x86_64/bin",
    "ndkIncludePath":"P:/Microsoft/AndroidNDK64/android-ndk-r21e/toolchains/llvm/prebuilt/windows-x86_64/lib64/clang/5.0/include",
    "ndkBinPath":    "P:/Microsoft/AndroidNDK64/android-ndk-r21e/toolchains/aarch64-linux-android-4.9/prebuilt/windows-x86_64/aarch64-linux-android/bin",

    "srcPath":"g:/mycode/miniblink57",
    "targetDir":"linuxdebugx64",
    "isDebug": cmd.isDebug,
    "v8dir": cmd.v8dir,
    "sysroot": "G:/chromium/M84/build/linux/debian_sid_amd64-sysroot",
};
constValue.linker = constValue.ndkBinPath + "/ld.gold.exe"; //"${ndkBinPath}/ld.gold.exe"

constValue.isBuildElectronMode = cmd.isBuildElectronMode;
constValue.compileCfg = cmd.compileCfg;

jsPrint("constValue.isBuildElectronMode:" + constValue.isBuildElectronMode);
jsPrint("constValue.compileCfg:" + constValue.compileCfg);

if (cmd.compileCfg == "debug") {
    constValue.targetDir = "linuxdebugx64";
} else if (cmd.compileCfg == "release") {
    constValue.targetDir = "linuxreleasex64";
} else if (cmd.compileCfg == "release_v857") {
    constValue.targetDir = "linux_release_v857_x64";
} else {
    constValue.targetDir = "linux_release_sym_x64";
}

export const constVal = constValue;

export const buildCommonSetting = function(json) {
    json[0].compile.objdir = json[0].compile.objdir.replace("${srcPath}", constValue.srcPath);
    json[0].compile.objdir = json[0].compile.objdir.replace("${targetDir}", constValue.targetDir);
    
    json[0].compile.cmd.push("-fPIC");
    
    if (cmd.compileCfg == "debug") {
        json[0].compile.cmd.push("-g");
        json[0].compile.cmd.push("-D_DEBUG");
        json[0].compile.cmd.push("-O0");
    } else if (cmd.compileCfg == "release" || cmd.compileCfg == "release_v857") {
        json[0].compile.cmd.push("-finline-functions");
        json[0].compile.cmd.push(" -fomit-frame-pointer");
        json[0].compile.cmd.push("-msse2");
        json[0].compile.cmd.push("-O3");
        json[0].compile.cmd.push("-DNDEBUG");
        json[0].compile.cmd.push("-fvisibility=hidden");
        json[0].compile.linkerCmd.push("-strip-all");
    } else { // releaseSymbol
        json[0].compile.cmd.push("-g"); // debug core dump
        json[0].compile.cmd.push("-DNDEBUG");
        json[0].compile.cmd.push("-O2");
        json[0].compile.cmd.push("-fvisibility=hidden");
    }
    
    qfmRebuild(json[0].compile.objdir, JSON.stringify(json));
};
//export function FunctionName(){ print("22222"); };
//let k;
//export default k = 12;