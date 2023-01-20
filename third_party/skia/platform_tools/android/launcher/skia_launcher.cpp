/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <dlfcn.h>
#include <stdio.h>

<<<<<<< HEAD
void usage()
{
=======
void usage() {
>>>>>>> miniblink49
    printf("[USAGE] skia_launcher program_name [options]\n");
    printf("  program_name: the skia program you want to launch (e.g. tests, bench)\n");
    printf("  options: options specific to the program you are launching\n");
}

<<<<<<< HEAD
bool file_exists(const char* fileName)
{
=======
bool file_exists(const char* fileName) {
>>>>>>> miniblink49
    FILE* file = fopen(fileName, "r");
    if (file) {
        fclose(file);
        return true;
    }
    return false;
}

int launch_app(int (*app_main)(int, const char**), int argc,
<<<<<<< HEAD
    const char** argv)
{
=======
        const char** argv) {
>>>>>>> miniblink49
    return (*app_main)(argc, argv);
}

void* load_library(const char* appLocation, const char* libraryName)
{
<<<<<<< HEAD
    // attempt to lookup the location of the shared libraries
=======
     // attempt to lookup the location of the shared libraries
>>>>>>> miniblink49
    char libraryLocation[100];
    sprintf(libraryLocation, "%s/lib%s.so", appLocation, libraryName);
    if (!file_exists(libraryLocation)) {
        printf("ERROR: Unable to find the '%s' library in the Skia App.\n", libraryName);
        printf("ERROR: Did you provide the correct program_name?\n");
        usage();
        return NULL;
    }

    // load the appropriate library
    void* appLibrary = dlopen(libraryLocation, RTLD_LOCAL | RTLD_LAZY);
    if (!appLibrary) {
        printf("ERROR: Unable to open the shared library.\n");
        printf("ERROR: %s", dlerror());
        return NULL;
    }

    return appLibrary;
}

<<<<<<< HEAD
int main(int argc, const char** argv)
{
=======
int main(int argc, const char** argv) {
>>>>>>> miniblink49

    // check that the program name was specified
    if (argc < 2) {
        printf("ERROR: No program_name was specified\n");
        usage();
        return -1;
    }

    // attempt to lookup the location of the skia app
    const char* appLocation = "/data/local/tmp";
    if (!file_exists(appLocation)) {
        printf("ERROR: Unable to find /data/local/tmp on the device.\n");
        return -1;
    }

<<<<<<< HEAD
#if defined(SKIA_DLL)
    // load the local skia shared library
    void* skiaLibrary = load_library(appLocation, "skia_android");
    if (NULL == skiaLibrary) {
=======
    void* skiaLibrary;

#if defined(SKIA_DLL)
    // load the local skia shared library
    skiaLibrary = load_library(appLocation, "skia_android");
    if (NULL == skiaLibrary)
    {
>>>>>>> miniblink49
        return -1;
    }
#endif

    // load the appropriate library
    void* appLibrary = load_library(appLocation, argv[1]);
    if (NULL == appLibrary) {
        return -1;
    }

<<<<<<< HEAD
    // find the address of the main function
    int (*app_main)(int, const char**);
    *(void**)(&app_main) = dlsym(appLibrary, "main");
=======
#if !defined(SKIA_DLL)
    skiaLibrary = appLibrary;
#endif

    // find the address of the main function
    int (*app_main)(int, const char**);
    *(void **) (&app_main) = dlsym(appLibrary, "main");
>>>>>>> miniblink49

    if (!app_main) {
        printf("ERROR: Unable to load the main function of the selected program.\n");
        printf("ERROR: %s\n", dlerror());
        return -1;
    }

    // pass all additional arguments to the main function
    return launch_app(app_main, argc - 1, ++argv);
}
