/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "win_dbghelp.h"
#include "windows.h"
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
=======
#include "windows.h"
#include "win_dbghelp.h"
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
>>>>>>> miniblink49

// Remove prefix addresses. 18 = 2 * (8 digit hexa + 1 space).
// e.g. "abcd1234 abcd1234 render_pdf!processInput
#define CDB_CALLSTACK_PREFIX (18)

// CDB.EXE prints a lot of garbage and there is no argument to pass which
// would remove all that noise.
// Using eval feature that evaluates a number in hex and prints it to stdout
// to mark where the callstack is printed.
// For example, each thread's callstack will be marked with "12340000" at
// the beginning and "12340001" at the end.
// We just made up these numbers; they could be anything, as long as they
// match up with their decimal equivalents.

#define MARKER_THREAD_CALLSTACK_START_NUMBER "12340000"
#define MARKER_THREAD_CALLSTACK_START "Evaluate expression: 305397760 = 12340000"

#define MARKER_THREAD_CALLSTACK_STOP_NUMBER "12340001"
#define MARKER_THREAD_CALLSTACK_STOP "Evaluate expression: 305397761 = 12340001"

#define MARKER_EXCEPTION_CALLSTACK_START_NUMBER "12340002"
#define MARKER_EXCEPTION_CALLSTACK_START "Evaluate expression: 305397762 = 12340002"

#define MARKER_EXCEPTION_CALLSTACK_STOP_NUMBER "12340003"
#define MARKER_EXCEPTION_CALLSTACK_STOP "Evaluate expression: 305397763 = 12340003"

// k - print stack
// ? val - evaluate expression. Used to mark the log file.
// .ecxr - load exception, if exception was thrown.
// k - print the resolved stack by .ecxr
// q - quit cdb.exe
#define CDB_PRINT_CALLSTACK_CURRENT_THREAD "? " MARKER_THREAD_CALLSTACK_START_NUMBER "; k; ? " MARKER_THREAD_CALLSTACK_STOP_NUMBER "; .ecxr; ? " MARKER_EXCEPTION_CALLSTACK_START_NUMBER "; k; ? " MARKER_EXCEPTION_CALLSTACK_STOP_NUMBER "; q"

<<<<<<< HEAD
static void strncpyOrSetBlank(char* dest, const char* src, size_t len)
{
    const char* srcOrEmptyString = (nullptr == src) ? "" : src;
    strncpy(dest, srcOrEmptyString, len);
}

char debug_app_name[MAX_PATH] = "";
void setAppName(const char* app_name)
{
    strncpyOrSetBlank(debug_app_name, app_name, sizeof(debug_app_name));
}

const char* getAppName()
{
=======
static void strncpyOrSetBlank(char* dest, const char* src, size_t len) {
  const char* srcOrEmptyString = (NULL == src) ? "" : src;
  strncpy(dest, srcOrEmptyString, len);
}

char debug_app_name[MAX_PATH] = "";
void setAppName(const char* app_name) {
    strncpyOrSetBlank(debug_app_name, app_name, sizeof(debug_app_name));
}

const char* getAppName() {
>>>>>>> miniblink49
    return debug_app_name;
}

char debug_binaries_path[MAX_PATH] = "";
<<<<<<< HEAD
void setBinariesPath(const char* binaries_path)
{
    strncpyOrSetBlank(debug_binaries_path, binaries_path,
        sizeof(debug_binaries_path));
}

const char* getBinariesPath()
{
=======
void setBinariesPath(const char* binaries_path) {
    strncpyOrSetBlank(debug_binaries_path, binaries_path,
                      sizeof(debug_binaries_path));
}

const char* getBinariesPath() {
>>>>>>> miniblink49
    return debug_binaries_path;
}

char debug_app_version[100] = "";
<<<<<<< HEAD
void setAppVersion(const char* version)
{
    strncpyOrSetBlank(debug_app_version, version, sizeof(debug_app_version));
}

const char* getAppVersion()
{
=======
void setAppVersion(const char* version) {
    strncpyOrSetBlank(debug_app_version, version, sizeof(debug_app_version));
}

const char* getAppVersion() {
>>>>>>> miniblink49
    return debug_app_version;
}

char debug_cdb_path[MAX_PATH] = "";
<<<<<<< HEAD
void setCdbPath(const char* path)
{
    strncpyOrSetBlank(debug_cdb_path, path, sizeof(debug_cdb_path));
}

const char* getCdbPath()
{
=======
void setCdbPath(const char* path) {
  strncpyOrSetBlank(debug_cdb_path, path, sizeof(debug_cdb_path));
}

const char* getCdbPath() {
>>>>>>> miniblink49
    return debug_cdb_path;
}

/** Print all the lines of a CDB k command whicha are callstacks.
 *  Callstack lines are marked by start and stop markers and they are prefixed
 *  byt 2 hex adresses, which will not be reported.
 */
static void printCallstack(const char* filename,
<<<<<<< HEAD
    const char* start,
    const char* stop)
{
=======
                           const char* start,
                           const char* stop) {
>>>>>>> miniblink49
    FILE* file = fopen(filename, "rt");
    char line[1000];
    bool started = false;
    // Not the most performant code, but this will be used only to collect
    // the callstack from a log files, only when the application had failed.
    while (fgets(line, sizeof(line), file)) {
        if (!started && strncmp(start, line, strlen(start)) == 0) {
            started = true;
        } else if (started && strncmp(stop, line, strlen(stop)) == 0) {
            break;
        } else if (started) {
            // Filter messages. Calstack lines contain "exe/dll!function"
<<<<<<< HEAD
            if (strchr(line, '!') != nullptr && strlen(line) > CDB_CALLSTACK_PREFIX) {
                printf("%s", line + CDB_CALLSTACK_PREFIX); // fgets includes \n already.
=======
            if (strchr(line, '!') != NULL && strlen(line) > CDB_CALLSTACK_PREFIX) {
                printf("%s", line + CDB_CALLSTACK_PREFIX);  // fgets includes \n already.
>>>>>>> miniblink49
            }
        }
    }
    fclose(file);
}

#define BUILD_UNIQUE_FILENAME(var, ext, szPath, szAppName, szVersion, stLocalTime) \
<<<<<<< HEAD
    sprintf(szFileName, "%s%s\\%s-%04d%02d%02d-%02d%02d%02d-%ld-%ld" ext,          \
        szPath, szAppName, szVersion,                                              \
        stLocalTime.wYear, stLocalTime.wMonth, stLocalTime.wDay,                   \
        stLocalTime.wHour, stLocalTime.wMinute, stLocalTime.wSecond,               \
        GetCurrentProcessId(), GetCurrentThreadId());
=======
    sprintf(szFileName, "%s%s\\%s-%04d%02d%02d-%02d%02d%02d-%ld-%ld" ext, \
           szPath, szAppName, szVersion, \
           stLocalTime.wYear, stLocalTime.wMonth, stLocalTime.wDay, \
           stLocalTime.wHour, stLocalTime.wMinute, stLocalTime.wSecond, \
           GetCurrentProcessId(), GetCurrentThreadId());
>>>>>>> miniblink49

// Exception execution handler.  Exception is recognized. Transfer control to
// the exception handler by executing the __except compound statement,
// then continue execution after the __except block.
<<<<<<< HEAD
int GenerateDumpAndPrintCallstack(EXCEPTION_POINTERS* pExceptionPointers)
{
=======
int GenerateDumpAndPrintCallstack(EXCEPTION_POINTERS* pExceptionPointers) {
>>>>>>> miniblink49
    BOOL bMiniDumpSuccessful;
    char szPath[MAX_PATH];
    char szFileName[MAX_PATH];
    char szFileNameOutput[MAX_PATH];
    const char* szAppName = getAppName();
    const char* szVersion = getAppVersion();
    DWORD dwBufferSize = MAX_PATH;
    HANDLE hDumpFile;
    SYSTEMTIME stLocalTime;
    MINIDUMP_EXCEPTION_INFORMATION ExpParam;

<<<<<<< HEAD
    GetLocalTime(&stLocalTime);
    GetTempPath(dwBufferSize, szPath);

    sprintf(szFileName, "%s%s", szPath, szAppName);
    CreateDirectory(szFileName, nullptr);
=======
    GetLocalTime( &stLocalTime );
    GetTempPath( dwBufferSize, szPath );

    sprintf( szFileName, "%s%s", szPath, szAppName );
    CreateDirectory( szFileName, NULL );
>>>>>>> miniblink49

    BUILD_UNIQUE_FILENAME(szFileName, ".dmp", szPath, szAppName, szVersion, stLocalTime);
    BUILD_UNIQUE_FILENAME(szFileNameOutput, ".out", szPath, szAppName, szVersion, stLocalTime);

    hDumpFile = CreateFile(szFileName,
<<<<<<< HEAD
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_WRITE | FILE_SHARE_READ,
        0,
        CREATE_ALWAYS,
        0,
        0);
=======
                           GENERIC_READ|GENERIC_WRITE,
                           FILE_SHARE_WRITE|FILE_SHARE_READ,
                           0,
                           CREATE_ALWAYS,
                           0,
                           0);
>>>>>>> miniblink49

    ExpParam.ThreadId = GetCurrentThreadId();
    ExpParam.ExceptionPointers = pExceptionPointers;
    ExpParam.ClientPointers = TRUE;

    bMiniDumpSuccessful = MiniDumpWriteDump(GetCurrentProcess(),
<<<<<<< HEAD
        GetCurrentProcessId(),
        hDumpFile,
        MiniDumpWithDataSegs,
        &ExpParam,
        nullptr,
        nullptr);
=======
                                            GetCurrentProcessId(),
                                            hDumpFile,
                                            MiniDumpWithDataSegs,
                                            &ExpParam,
                                            NULL,
                                            NULL);
>>>>>>> miniblink49

    printf("MiniDump file:    %s\n", szFileName);
    printf("App exe and pdb:  %s\n", getBinariesPath());

    const char* cdbExePath = getCdbPath();
    if (cdbExePath && *cdbExePath != '\0') {
        printf("Cdb exe:          %s\n", cdbExePath);

        char command[MAX_PATH * 4];
        sprintf(command, "%s -y \"%s\" -i \"%s\" -z \"%s\" -c \"%s\" -kqm >\"%s\"",
<<<<<<< HEAD
            cdbExePath,
            getBinariesPath(),
            getBinariesPath(),
            szFileName,
            CDB_PRINT_CALLSTACK_CURRENT_THREAD,
            szFileNameOutput);
=======
                cdbExePath,
                getBinariesPath(),
                getBinariesPath(),
                szFileName,
                CDB_PRINT_CALLSTACK_CURRENT_THREAD,
                szFileNameOutput);
>>>>>>> miniblink49
        system(command);

        printf("\nThread Callstack:\n");
        printCallstack(szFileNameOutput,
<<<<<<< HEAD
            MARKER_THREAD_CALLSTACK_START,
            MARKER_THREAD_CALLSTACK_STOP);

        printf("\nException Callstack:\n");
        printCallstack(szFileNameOutput,
            MARKER_EXCEPTION_CALLSTACK_START,
            MARKER_EXCEPTION_CALLSTACK_STOP);
=======
                       MARKER_THREAD_CALLSTACK_START,
                       MARKER_THREAD_CALLSTACK_STOP);

        printf("\nException Callstack:\n");
        printCallstack(szFileNameOutput,
                       MARKER_EXCEPTION_CALLSTACK_START,
                       MARKER_EXCEPTION_CALLSTACK_STOP);
>>>>>>> miniblink49
    } else {
        printf("Warning: CDB path not set up.\n");
    }

    return EXCEPTION_EXECUTE_HANDLER;
}

/** Sets the debugging variables. Input parameter is app location.
 *  e.g out\Debug\render_pdfs.exe
 *  This function expects the .pdb file to be in the same directory.
 */
<<<<<<< HEAD
void setUpDebuggingFromArgs(const char* vargs0)
{
=======
void setUpDebuggingFromArgs(const char* vargs0) {
>>>>>>> miniblink49
    size_t i = strlen(vargs0);

    if (i >= 4 && _stricmp(vargs0 - 4, ".exe") == 0) {
        // Ignore .exe
        i -= 4;
    }

    size_t pos_period = i;

    // Find last \ in path - this is Windows!
    while (i >= 0 && vargs0[i] != '\\') {
        i--;
    }

    size_t pos_last_slash = i;

    char app_name[MAX_PATH];
    strncpy(app_name, vargs0 + pos_last_slash + 1, pos_period - pos_last_slash - 1);
    app_name[pos_period - pos_last_slash] = '\0';
    setAppName(app_name);

    char binaries_path[MAX_PATH];
    strncpy(binaries_path, vargs0, pos_last_slash);
    binaries_path[pos_last_slash] = '\0';
    setBinariesPath(binaries_path);

<<<<<<< HEAD
    setAppVersion("1.0"); // Dummy for now, but use revision instead if we use
        // the minidump for anything else other than
        // collecting the callstack.
=======
    setAppVersion("1.0");  // Dummy for now, but use revision instead if we use
                           // the minidump for anything else other than
                           // collecting the callstack.
>>>>>>> miniblink49

    // cdb.exe is the app used to load the minidump which prints the callstack.
    char cdbExePath[MAX_PATH];
#ifdef _WIN64
    sprintf(cdbExePath, "%s\\x64\\cdb.exe", SK_CDB_PATH);
#else
    sprintf(cdbExePath, "%s\\cdb.exe", SK_CDB_PATH);
#endif
    setCdbPath(cdbExePath);
}
