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
            "${srcPath}/linux"
        ],
        "prebuildSrc":[            
            //"${srcPath}/wkexe/vip/wkexe_linux.cpp",
            "${srcPath}/wkexe/vip/wkexe_linux_exp.cpp",
            "${srcPath}/linux/linuxwindows.cpp",
        ],
        "src":[
            //"${srcPath}/wkexe/vip/wkexe_linux.cpp",
            "${srcPath}/wkexe/vip/wkexe_linux_exp.cpp",
            "${srcPath}/linux/linuxwindows.cpp",
            //"${srcPath}/linux/linuxgdi.cpp",

            "${srcPath}/webdriver/WebDriver.cpp",
            "${srcPath}/webdriver/MBServer.cpp",
            "${srcPath}/webdriver/MBSession.cpp",
            "${srcPath}/webdriver/MBCommandExecutor.cpp",
            "${srcPath}/webdriver/MBCommandHandler.cpp",
            "${srcPath}/webdriver/server/command.cpp",
            "${srcPath}/webdriver/server/response.cpp",
            "${srcPath}/webdriver/server/server.cpp",
            "${srcPath}/webdriver/jsoncpp/jsoncpp.cpp",
            "${srcPath}/webdriver/civetweb/civetweb.c",
            "${srcPath}/webdriver/server/uri_info.cpp",
            "${srcPath}/webdriver/CommandHandlerRepository.cpp",
            "${srcPath}/webdriver/CommandHandlers/NewSessionCommandHandler.cpp",
            "${srcPath}/webdriver/CommandLineArguments.cpp",
            "${srcPath}/webdriver/StringUtilities.cpp",
            "${srcPath}/webdriver/CommandHandlers/GoToUrlCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/FindElementsCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/FindElementCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/ElementUtil.cpp",
            "${srcPath}/webdriver/js.cpp",
            "${srcPath}/webdriver/atoms.cpp",
            "${srcPath}/webdriver/CommandHandlers/SendKeysCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/ClickElementCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetElementTextCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GoForwardCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GoBackCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/RefreshCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/ExecuteScriptCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetTitleCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetElementAttributeCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetTimeoutsCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetCurrentWindowHandleCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/CloseWindowCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/SwitchToWindowCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetAllWindowHandlesCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/CreateNewWindowCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/SetWindowRectCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/ExecuteAsyncScriptCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/ReleaseActionsCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/ScreenshotCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/SetTimeoutsCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetAlertTextCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/AcceptAlertCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/DismissAlertCommandHandler.cpp",
        ],
        "cmd":[
            "-fno-exceptions",
            "--target=x86_64-linux-guneabi", 
            "-std=c++14",
            "-fms-extensions",
            "-Dunix=1",
            "-D_GLIBCXX17_INLINE=inline",
            "-D_GNU_SOURCE",
            "-DUSE_AURA",
            "-DOS_LINUX_FOR_WIN",
        ],
        "objdir":"${srcPath}/out/tmp/wkexe/${targetDir}",
        "outdir":"${srcPath}/out/${targetDir}",
        "target":"chromedriver",
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
//    json[0].compile.target = "miniblink.so";
//    json[0].compile.cmd.push("-shared");
//}

buildCommonSetting(json);
