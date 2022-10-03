
const cmdstr = qfmGetCmdline();
jsPrint("cmdstr:" + cmdstr);
const cmd = JSON.parse(cmdstr);

var constValue = {
	// 盟主的代码目录结构
	/*"sdkPath":"C:/cygwin64/usr/local/x86_64-unknown-linux-gnu/x86_64-unknown-linux-gnu",
	"clangPath":     "C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/llvm/prebuilt/windows-x86_64/bin",
	"ndkIncludePath":"C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/llvm/prebuilt/windows-x86_64/lib64/clang/5.0/include",
	"ndkBinPath":    "C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/aarch64-linux-android-4.9/prebuilt/windows-x86_64/aarch64-linux-android/bin",
	"srcPath":"G:/mycode/miniblink57",
	"targetDir":"linuxdebugx64",
	"isDebug": cmd.isDebug,
	"v8dir": "v8_5_7",
	"sysroot": "G:/chromium/M84/build/linux/debian_sid_amd64-sysroot",*/

	// 马铁的代码目录结构
	"sdkPath": "D:/MB/mb_linux_sdk/x86_64-unknown-linux-gnu/x86_64-unknown-linux-gnu",
	"clangPath": "D:/Android/android-ndk-r16b/toolchains/llvm/prebuilt/windows-x86_64/bin",
	"ndkIncludePath": "D:/Android/android-ndk-r16b/toolchains/llvm/prebuilt/windows-x86_64/lib64/clang/5.0/include",
	"ndkBinPath": "D:/Android/android-ndk-r16b/toolchains/aarch64-linux-android-4.9/prebuilt/windows-x86_64/aarch64-linux-android/bin",
	"srcPath": "D:/LiteView/miniblink57",
	"targetDir": "linux_debug_x64",
	"isDebug": cmd.isDebug,
	"v8dir": "v8_7_5",
	"sysroot": "D:/MB/mb_linux_sdk/debian_sid_amd64-sysroot",
};

constValue.isBuildElectronMode = cmd.isBuildElectronMode;
jsPrint("constValue.isBuildElectronMode:" + constValue.isBuildElectronMode);

if (cmd.isDebug) {
	constValue.targetDir = "linux_debug_x64";
} else {
	constValue.targetDir = "linux_release_x64";
}
//export { testImport };
export const constVal = constValue;

export const buildCommonSetting = function(json) {
	json[0].compile.objdir = json[0].compile.objdir.replace("${srcPath}", constValue.srcPath);
	json[0].compile.objdir = json[0].compile.objdir.replace("${targetDir}", constValue.targetDir);
	
	json[0].compile.cmd.push("-fPIC");
	
	if (constVal.isDebug) {
		json[0].compile.cmd.push("-g");
		json[0].compile.cmd.push("-D_DEBUG");
	} else {
		json[0].compile.cmd.push("-Oz");
		json[0].compile.cmd.push("-DNDEBUG");
		json[0].compile.cmd.push("-fvisibility=hidden");
		json[0].compile.linkerCmd.push("-strip-all");
		//"-fshort-wchar",
	}
	
	qfmRebuild(json[0].compile.objdir, JSON.stringify(json));
};
//export function FunctionName(){ print("22222"); };
//let k;
//export default k = 12;