
const cmdstr = qfmGetCmdline();
jsPrint("cmdstr:" + cmdstr);
const cmd = JSON.parse(cmdstr);

var constValue = {
    "sdkPath":       "C:/cygwin64/usr/local/x86_64-unknown-linux-gnu/x86_64-unknown-linux-gnu",
    "clangPath":     "C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/llvm/prebuilt/windows-x86_64/bin",
    "ndkBinPath":    "C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/aarch64-linux-android-4.9/prebuilt/windows-x86_64/aarch64-linux-android/bin",
    "ndkIncludePath":"C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/llvm/prebuilt/windows-x86_64/lib64/clang/5.0/include",
    "srcPath":"g:/mycode/miniblink57",
    "targetDir":"linux_debug_x64",
    "isDebug": cmd.isDebug,
    "v8dir": cmd.v8dir,
    //"sysroot": "G:/chromium/M84/build/linux/debian_sid_amd64-sysroot",
    "sysroot":       "C:/Microsoft/AndroidNDK64/debian_sid_arm64_sysroot",
};
constValue.linker = constValue.ndkBinPath + "/ld.gold.exe"; //"${ndkBinPath}/ld.gold.exe"

constValue.isBuildElectronMode = cmd.isBuildElectronMode;
constValue.compileCfg = cmd.compileCfg;
constValue.target = "x86_64-linux-guneabi";

jsPrint("constValue.isBuildElectronMode:" + constValue.isBuildElectronMode);
jsPrint("constValue.compileCfg:" + constValue.compileCfg);

if (cmd.compileCfg == "debug") {
    constValue.targetDir = "linux_debug_x64";
} else if (cmd.compileCfg == "release") {
    constValue.targetDir = "linux_release_x64";
} else if (cmd.compileCfg == "release_v857") {
    constValue.targetDir = "linux_release_v857_x64";
} else if (cmd.compileCfg == "release_v875_arm") {
    constValue.target = "aarch64-linux-guneabi"
    constValue.targetDir = "linux_release_v875_arm";
} else {
    constValue.targetDir = "linux_release_sym_x64";
}

if ("aarch64-linux-guneabi" == constValue.target) {
    constValue.sdkPath        = "C:/Microsoft/AndroidNDK64/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu",
    constValue.clangPath      = "C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/llvm/prebuilt/windows-x86_64/bin",
    constValue.ndkBinPath     = "C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/arm-linux-androideabi-4.9/prebuilt/windows-x86_64/arm-linux-androideabi/bin",
    constValue.ndkIncludePath = "C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/llvm/prebuilt/windows-x86_64/lib64/clang/5.0/include",
}

export const constVal = constValue;

export const buildCommonSetting = function(json) {
    json[0].compile.objdir = json[0].compile.objdir.replace("${srcPath}", constValue.srcPath);
    json[0].compile.objdir = json[0].compile.objdir.replace("${targetDir}", constValue.targetDir);
    
    json[0].compile.cmd.push("-fPIC");
    
    json[0].compile.cmd.push("--target=" + constValue.target);
    
    if (cmd.compileCfg == "debug") {
        json[0].compile.cmd.push("-g");
        json[0].compile.cmd.push("-D_DEBUG");
        json[0].compile.cmd.push("-O0");
    } else if (cmd.compileCfg == "release" || cmd.compileCfg == "release_v857" || cmd.compileCfg == "release_v875_arm") {
        //json[0].compile.cmd.push("-finline-functions");
        json[0].compile.cmd.push("-fomit-frame-pointer");
        //json[0].compile.cmd.push("-msse2");
        json[0].compile.cmd.push("-Os");
        json[0].compile.cmd.push("-DNDEBUG");
        json[0].compile.cmd.push("-fno-rtti");
        json[0].compile.cmd.push("-fvisibility=hidden");
        json[0].compile.cmd.push("-fno-exceptions");
        json[0].compile.linkerCmd.push("-strip-all");
    } else { // releaseSymbol
        json[0].compile.cmd.push("-g"); // debug core dump
        json[0].compile.cmd.push("-DNDEBUG");
        //json[0].compile.cmd.push("-DENABLE_ASSERT=1");
        json[0].compile.cmd.push("-fno-rtti");
        //json[0].compile.cmd.push("-Os");
        json[0].compile.cmd.push("-fno-exceptions");
        json[0].compile.cmd.push("-fvisibility=hidden");
    }
    
    qfmRebuild(json[0].compile.objdir, JSON.stringify(json));
};