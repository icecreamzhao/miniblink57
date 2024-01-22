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
            ...constVal.includePaths,
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
//            "${srcPath}/linux/linuxwindows.cpp",
//            "${srcPath}/linux/linuxgdi.cpp",
//            "${srcPath}/linux/testmain.cpp",
//            "${srcPath}/skia/ext/convolver_SSE2.cc",
            
            "${srcPath}/wkexe/vip/wkexe_linux.cpp",
            "${srcPath}/wkexe/vip/wkexe_linux_exp.cpp",
        ],
        "src":[
            "${srcPath}/wkexe/vip/wkexe_linux.cpp",
            "${srcPath}/wkexe/vip/wkexe_linux_exp.cpp",
        ],
        "cmd":[
            "-fno-exceptions",
            //"--target=x86_64-linux-guneabi", 
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
//            "${sysroot}/usr/lib/x86_64-linux-gnu/crt1.o",
//            "${sysroot}/usr/lib/x86_64-linux-gnu/crti.o",
//            "${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/crtbegin.o",
//            "${sysroot}/usr/lib/x86_64-linux-gnu/libc_nonshared.a",
//            "${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/libgcc_eh.a",
//            "${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/libgcc.a",
//            "${sysroot}/usr/lib/x86_64-linux-gnu/libffi.a"
        ],
        "linkerCmd":[
//            "-strip-all",
//            //"-dynamic-linker /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2",
//            "-dynamic-linker /lib64/ld-linux-x86-64.so.2",
//            "-l${sysroot}/lib/x86_64-linux-gnu/libc-2.27.so",
//            "-l${sysroot}/usr/lib/x86_64-linux-gnu/libglib-2.0.so.0.6200.3",
//            "-l${sysroot}/usr/lib/x86_64-linux-gnu/libgtk-3.so.0.2404.9",
//            "-l${sysroot}/usr/lib/x86_64-linux-gnu/libgdk-3.so.0.2404.9",
//            "-l${sysroot}/usr/lib/x86_64-linux-gnu/libcairo.so.2.11600.0",
//            "-l${sysroot}/usr/lib/x86_64-linux-gnu/libpthread.so",
//            //"-l${sysroot}/usr/lib/x86_64-linux-gnu/libpcreposix.so.3.13.3",
//            "-l${sysroot}/usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.28",
//            "-l${sysroot}/usr/lib/x86_64-linux-gnu/libgobject-2.0.so.0.6200.3",
//            "-l${sdkPath}/sysroot/lib/libdl.so.2",
//            "-l${sdkPath}/sysroot/lib/libgcc_s.so.1",
//            "-l${sysroot}/lib/x86_64-linux-gnu/libm-2.27.so"
            ],
        "endLibs":[
//            "${sysroot}/usr/lib/x86_64-linux-gnu/crtn.o",
//            "${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/crtend.o"
        ],
        "linker":constVal.linker//"${ndkBinPath}/ld.gold.exe"
    }
}];


var endLibs = [];

if ("aarch64-linux-guneabi" == constVal.target) { // ARM64
    json[0].compile.linkerCmd = [
        //"-z defs",
        //"-fPIC",
        "-dynamic-linker /usr/lib/ld-linux-aarch64.so.1",
        "-l${sysroot}/lib/aarch64-linux-gnu/libc-2.31.so",
        "-l${sysroot}/usr/lib/aarch64-linux-gnu/libglib-2.0.so.0.6600.7",
        "-l${sysroot}/usr/lib/aarch64-linux-gnu/libgtk-3.so.0.2404.20",
        "-l${sysroot}/usr/lib/aarch64-linux-gnu/libgdk-3.so.0.2404.20",
        "-l${sysroot}/usr/lib/aarch64-linux-gnu/libcairo.so.2.11600.0",
        "-l${sysroot}/usr/lib/aarch64-linux-gnu/libpthread.so",
        "-l${sysroot}/usr/lib/aarch64-linux-gnu/libstdc++.so.6.0.28",
        "-l${sysroot}/usr/lib/aarch64-linux-gnu/libgobject-2.0.so.0.6600.7",
        "-l${sdkPath}/aarch64-linux-gnu/libc/lib/libdl.so.2",
        "-l${sdkPath}/aarch64-linux-gnu/libc/lib/libgcc_s.so.1",
        "-l${sysroot}/lib/aarch64-linux-gnu/libm-2.31.so"];
        
    json[0].compile.beginLibs = [
        "${sysroot}/usr/lib/aarch64-linux-gnu/crt1.o",
        "${sysroot}/usr/lib/aarch64-linux-gnu/crti.o",
        "${sysroot}/usr/lib/aarch64-linux-gnu/libc_nonshared.a",
        "${sysroot}/usr/lib/gcc/aarch64-linux-gnu/10/libgcc_eh.a",
        "${sysroot}/usr/lib/gcc/aarch64-linux-gnu/10/libgcc.a",
        "${sysroot}/usr/lib/aarch64-linux-gnu/libffi.a"
    ];

    json[0].compile.endLibs.push("${sysroot}/usr/lib/aarch64-linux-gnu/crtn.o");
    json[0].compile.endLibs.push("${sysroot}/usr/lib/gcc/aarch64-linux-gnu/10/crtend.o");
} else {  // X64
    json[0].compile.linkerCmd = [
        //"-LD:/usr/lib/gcc/i586-linux-gnu/4.9",
        //"-LD:/usr/lib/i386-linux-gnu",
        //"-strip-all",
        "-z defs",
        "-fPIC",
        //"-dynamic-linker /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2",
        //"-rpath=/home/daniel/Desktop/test_web",
        "-dynamic-linker /lib64/ld-linux-x86-64.so.2",
        "-l${sysroot}/lib/x86_64-linux-gnu/libc-2.27.so",
        "-l${sysroot}/usr/lib/x86_64-linux-gnu/libglib-2.0.so.0.6200.3",
        //"-lG:/chromium/M84/build/linux/debian_sid_amd64-sysroot/usr/lib/x86_64-linux-gnu/libffi.so.6.0.4",
        "-l${sysroot}/usr/lib/x86_64-linux-gnu/libgtk-3.so.0.2404.9",
        "-l${sysroot}/usr/lib/x86_64-linux-gnu/libgdk-3.so.0.2404.9",
        "-l${sysroot}/usr/lib/x86_64-linux-gnu/libcairo.so.2.11600.0",
        "-l${sysroot}/usr/lib/x86_64-linux-gnu/libpthread.so",
        //"-l${sysroot}/usr/lib/x86_64-linux-gnu/libpcreposix.so.3.13.3",
        "-l${sysroot}/usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.28",
        "-l${sysroot}/usr/lib/x86_64-linux-gnu/libgobject-2.0.so.0.6200.3",
        //"-l${sysroot}/lib/x86_64-linux-gnu/libdl.so.2",
        //"-l${sysroot}/lib/x86_64-linux-gnu/libgcc_s.so.1",
        "-l${sdkPath}/sysroot/lib/libdl.so.2",
        "-l${sdkPath}/sysroot/lib/libgcc_s.so.1",
        "-l${sysroot}/lib/x86_64-linux-gnu/libm-2.27.so"];
        
    json[0].compile.beginLibs = [
        "${sysroot}/usr/lib/x86_64-linux-gnu/crt1.o",
        "${sysroot}/usr/lib/x86_64-linux-gnu/crti.o",
        "${sysroot}/usr/lib/x86_64-linux-gnu/libc_nonshared.a",
        "${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/libgcc_eh.a",
        "${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/libgcc.a",
        "${sysroot}/usr/lib/x86_64-linux-gnu/libffi.a"
    ];
    json[0].compile.endLibs.push("${sysroot}/usr/lib/x86_64-linux-gnu/crtn.o");
    json[0].compile.endLibs.push("${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/crtend.o");
}


if ("aarch64-linux-guneabi" == constVal.target) // ARM64
    json[0].compile.beginLibs.push("${sysroot}/usr/lib/gcc/aarch64-linux-gnu/10/crtbeginS.o");
else
    json[0].compile.beginLibs.push("${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/crtbeginS.o");

json[0].compile.target = "wkexe";
//json[0].compile.linkerCmd.push("-shared");


buildCommonSetting(json);
