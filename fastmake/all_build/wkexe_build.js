import { constVal, buildCommonSetting } from "./const_val.js";

var json = [{
	"var":[
		{"sdkPath":constVal.sdkPath},
		{"clangPath":constVal.clangPath},
		{"srcPath":constVal.srcPath},
		{"ndkIncludePath":constVal.ndkIncludePath},
		{"ndkBinPath":constVal.ndkBinPath},
		{"v8dir": constVal.v8dir},
		{"targetDir": constVal.targetDir},
		{"sysroot": constVal.sysroot},
		
	],
	"compile":{
		"ccompiler":"${clangPath}/clang.exe",
		"cppcompiler":"${clangPath}/clang++.exe",
			
		"include":[
			"${sdkPath}/include/c++/7.2.0",
			"${sdkPath}/include/c++/7.2.0/include",
			"${ndkIncludePath}",
			"${sdkPath}/include/c++/7.2.0/x86_64-unknown-linux-gnu/",
			"${srcPath}",
			"${sdkPath}/sysroot/usr/include",
			"${sdkPath}/sysroot/usr/",
			"${sdkPath}/sysroot/usr/include/linux",
			"${sysroot}/usr/include/cairo",
			"${sysroot}/usr/include/glib-2.0",
			"${sysroot}/usr/include/gtk-3.0",
			"${sysroot}/usr/include/gdk-pixbuf-2.0",
			"${sysroot}/usr/include/atk-1.0",
			"${sysroot}/usr/include/pango-1.0",
			"${sysroot}/usr/lib/x86_64-linux-gnu/glib-2.0/include",
			"${srcPath}/linux",
			"${srcPath}/gen/${v8dir}/include",
			"${srcPath}/${v8dir}",
			"${srcPath}/${v8dir}/include",
			"${srcPath}/third_party/",
			"${srcPath}/third_party/npapi",
			"${srcPath}/third_party/WebKit",
			"${srcPath}/third_party/WebKit/Source",
			"${srcPath}/cef",
			"${srcPath}/third_party/icu/source/common",
			"${srcPath}/gen/blink",
			"${srcPath}/gen/blink/core",
			"${srcPath}/gen/blink/bindings/modules/v8",
			"${srcPath}/gen/blink/bindings/core/v8",
			"${srcPath}/gen/third_party/WebKit",
			"${srcPath}/gpu",
			"${srcPath}/node/uv/src",
			"${srcPath}/node/cares/include",
			"${srcPath}/node/cares/config/linux",
			"${srcPath}/node/uv/include",
			"${srcPath}/third_party/khronos",
			"${srcPath}/third_party/libxml/src/include",
			"${srcPath}/third_party/libxml/win32/include",
			"${srcPath}/third_party/skia/include/core",
			"${srcPath}/third_party/skia/include/config",
			"${srcPath}/third_party/skia/include/codec",
			"${srcPath}/third_party/skia/include/device",
			"${srcPath}/third_party/skia/include/effects",
			"${srcPath}/third_party/skia/include/images",
			"${srcPath}/third_party/skia/include/pathops",
			"${srcPath}/third_party/skia/include/ports",
			"${srcPath}/third_party/skia/include/private",
			"${srcPath}/third_party/skia/include/utils",
			"${srcPath}/third_party/skia/include/gpu",
			"${srcPath}/third_party/angle/include",
			"${srcPath}/third_party/angle/src"
		],
		"prebuildSrc":[
//			"${srcPath}/linux/linuxwindows.cpp",
//			"${srcPath}/linux/linuxgdi.cpp",
//			"${srcPath}/linux/testmain.cpp",
//			"${srcPath}/skia/ext/convolver_SSE2.cc",
			
			"${srcPath}/wkexe/vip/wkexe_linux.cpp",
			"${srcPath}/wkexe/vip/wkexe_linux_exp.cpp",
		],
		"src":[
			"${srcPath}/wkexe/vip/wkexe_linux.cpp",
			"${srcPath}/wkexe/vip/wkexe_linux_exp.cpp",
		],
		"cmd":[
			"-fno-exceptions",
			"--target=x86_64-linux-guneabi", 
			"-std=c++14",
			"-fms-extensions",
			//"-fshort-wchar",
			"-D_GLIBCXX17_INLINE=inline",
			"-D_GNU_SOURCE",
			"-DUSE_AURA",
			"-DOS_LINUX_FOR_WIN",
			"-DINSIDE_BLINK",
			"-DBLINK_IMPLEMENTATION",
			"-DSK_SUPPORT_LEGACY_CREATESHADER_PTR=1",
			"-DSK_SUPPORT_LEGACY_TYPEFACE_PTR=1",
		],
		"objdir":"${srcPath}/out/tmp/wkexe/${targetDir}",
		"outdir":"${srcPath}/out/${targetDir}",
		"target":"wkexe",
		"beginLibs":[
			"${sysroot}/usr/lib/x86_64-linux-gnu/crt1.o",
			"${sysroot}/usr/lib/x86_64-linux-gnu/crti.o",
			"${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/crtbegin.o",
			"${sysroot}/usr/lib/x86_64-linux-gnu/libc_nonshared.a",
			"${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/libgcc_eh.a",
			"${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/libgcc.a",
			"${sysroot}/usr/lib/x86_64-linux-gnu/libffi.a"
		],
		"linkerCmd":[
			"-strip-all",
			//"-dynamic-linker /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2",
            "-dynamic-linker /lib64/ld-linux-x86-64.so.2",
			"-l${sysroot}/lib/x86_64-linux-gnu/libc-2.27.so",
			"-l${sysroot}/usr/lib/x86_64-linux-gnu/libglib-2.0.so.0.6200.3",
			"-l${sysroot}/usr/lib/x86_64-linux-gnu/libgtk-3.so.0.2404.9",
			"-l${sysroot}/usr/lib/x86_64-linux-gnu/libgdk-3.so.0.2404.9",
			"-l${sysroot}/usr/lib/x86_64-linux-gnu/libcairo.so.2.11600.0",
			"-l${sysroot}/usr/lib/x86_64-linux-gnu/libpthread.so",
			//"-l${sysroot}/usr/lib/x86_64-linux-gnu/libpcreposix.so.3.13.3",
			"-l${sysroot}/usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.28",
			"-l${sysroot}/usr/lib/x86_64-linux-gnu/libgobject-2.0.so.0.6200.3",
			"-lC:/cygwin64/usr/local/x86_64-unknown-linux-gnu/x86_64-unknown-linux-gnu/sysroot/lib/libdl.so.2",
			"-lC:/cygwin64/usr/local/x86_64-unknown-linux-gnu/x86_64-unknown-linux-gnu/sysroot/lib/libgcc_s.so.1",
			"-l${sysroot}/lib/x86_64-linux-gnu/libm-2.27.so"
			],
		"endLibs":[
			"${sysroot}/usr/lib/x86_64-linux-gnu/crtn.o",
			"${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/crtend.o"
		],
		"linker":constVal.linker//"${ndkBinPath}/ld.gold.exe"
	}
}];

// 默认编译成electron，带参数则编译成so
//if (!constVal.isBuildElectronMode) {
//	json[0].compile.target = "miniblink.so";
//	json[0].compile.cmd.push("-shared");
//}

buildCommonSetting(json);
