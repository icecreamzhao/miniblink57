Windows
=======

Prerequisites
-------------

Make sure the following have been installed:

<<<<<<< HEAD
*   [Visual C++ 2015u2 or later, available for
    free](https://www.visualstudio.com/downloads/download-visual-studio-vs)

*   [Chromium depot_tools](https://www.chromium.org/developers/how-tos/depottools)

*   Git
    -   Either use the mysygit installed by depot_tools
    -   Or [install git-for-windows
        yourself](https://git-for-windows.github.io/).

*   Python 2.7.x (if you're not planning to use cygwin)
    -   available for free download at
        [python.org](https://www.python.org/download/releases/)
    -   make sure the installer changes your %PATH% environment variable
        to include the directory with the "python.exe" binary

*   Cygwin (**optional**, but useful if you want to use git)
    -   Download from https://www.cygwin.com/setup-x86.exe or
        https://www.cygwin.com/setup-x86_64.exe
    -   Use any mirror you like; http://lug.mtu.edu works well
    -   Cygwin installs a minimum of options. Add these packages if they
        aren't already selected:
        +   Devel git
        +   Devel subversion
        +   Editors vim
            *   to fix arrows in insert, copy
                `/usr/share/vim/vim73/vimrc_example.vim` to `~/.vimrc`
        +   Net ca-certificates
        +   Python python
        +   Utils patch
        +   Utils util-linux
    -   Set the windows envionment variable CYGWIN to nodosfilewarning
=======
  * Visual C++ 2013 Express or later, available for free
    * http://www.visualstudio.com/downloads/download-visual-studio-vs#d-express-windows-8

  * Chromium depot_tools
    * http://www.chromium.org/developers/how-tos/depottools
  * git
    * Either use the mysygit installed by depot_tools
    * Or install msys git: http://msysgit.github.io/ yourself
  * Python 2.7.x (if you're not planning to use cygwin)
    * available for free download at http://www.python.org/download/releases/
    * make sure the installer changes your %PATH% environment variable to include the directory with the "python.exe" binary
  * Cygwin (optional, but useful if you want to use git)
    * Download from  http://cygwin.org/setup.exe
    * use any mirror you like; http://lug.mtu.edu works well
    * Cygwin installs a minimum of options. Add these packages if they aren't already selected:
      * Devel git
      * Devel subversion
      * Editors vim
        * to fix arrows in insert, copy /usr/share/vim/vim73/vimrc_example.vim to ~/.vimrc
      * Net ca-certificates
      * Python python
      * Utils patch
      * Utils util-linux
    * set the windows envionment variable CYGWIN to nodosfilewarning
>>>>>>> miniblink49

Check out the source code
-------------------------

<<<<<<< HEAD
Follow the instructions [here](../download) for downloading the Skia source.

Gyp Generators on Windows
-------------------------

We use the open-source Gyp tool to generate Visual Studio projects (and
analogous build scripts on other platforms) from our multi-platform "gyp"
files.

Three Gyp generators are used on Windows:

*   `ninja` - Run ninja yourself, without VisualStudio  project files,

*   `msvs-ninja` - Develop from a fully-integrated Visual Studio.
    Gyp generates Visual-Studio-compatible project files that still
    ultimately build using ninja. This is the preferred and better maintained
    way of using Visual Studio.

*   `msvs` - Use Visual Studio's own (slower) build system. This is not as well
     maintained as msvs-ninja. The msvs and ninja output can clobber each other
     so building from both the command line and Visual Studio can produce bad
     states that can be fixed by deleting the out directory and rerunning
     gyp_skia.

To choose which ones to use, set the `GYP_GENERATORS` environment
variable to a comma-delimited list of generators before running
sync-and-gyp. The default value for `GYP_GENERATORS` is
`ninja,msvs-ninja`.  For example to enable the `ninja` and `msvs`
generators:

<a name="env"></a>Setting Enviroment Variables in Windows CMD.EXE
-----------------------------------------------------------------

    cd %SKIA_CHECKOUT_DIR%
    SET "GYP_GENERATORS=ninja,msvs"
    python bin/sync-and-gyp
    SET "GYP_GENERATORS="
=======
see https://skia.org/user/download

Generate Visual Studio projects
-------------------------------

We use the open-source gyp tool to generate Visual Studio projects (and
analogous build scripts on other platforms) from our multi-platform "gyp"
files.

You can generate the Visual Studio projects by running gyp_skia, as follows:

    cd %SKIA_CHECKOUT_DIR%
    python gyp_skia

This will produce Visual Studio projects in the `%SKIA_CHECKOUT_DIR%\out` directory.
>>>>>>> miniblink49

Build and run tests from the command line
-----------------------------------------

<<<<<<< HEAD
    ninja -C out/Debug dm
    out\Debug\dm

See [this page for running Skia tests on all desktop](./desktop)
=======
    ninja -C out\Debug dm
    out\Debug\dm

Normally you should run tests in Debug mode (SK_DEBUG is defined, and debug
symbols are included in the binary). If you would like to build the Release
version instead:

    ninja -C out\Release dm
    out\Release\dm
>>>>>>> miniblink49

Build and run tests in the Visual Studio IDE
--------------------------------------------

<<<<<<< HEAD
1.  Generate the Visual Studio project files by running `sync-and-gyp` as
    described above

2.  Open a File Explorer window pointing at the
    `%SKIA_CHECKOUT_DIR%\out\gyp` directory

3.  Double-click on dm.sln to start Visual Studio and load the project

4.  When Visual Studio starts, you may see an error dialog stating that
    "One or more projects in the solution were not loaded
    correctly"... but there's probably nothing to worry about.

5.  In the "Solution Explorer" window, right-click on the "dm" project
    and select "Set as StartUp Project".

6.  In the "Debug" menu, click on "Start Debugging" (or just press
    F5). If you get a dialog saying that the project is out of date,
    click on "Yes" to rebuild it.

7.  Once the build is complete, you should see console output from the
    tests in the "Output" window at lower right.
=======
  * Generate the Visual Studio project files by running gyp_skia as described above
  * Open a File Explorer window pointing at the %SKIA_CHECKOUT_DIR%\out\gyp directory
  * Double-click on dm.sln to start Visual Studio and load the project
  * When Visual Studio starts, you may see an error dialog stating that "One or more projects in the solution were not loaded correctly"... but there's probably nothing to worry about.
  * In the "Solution Explorer" window, right-click on the "dm" project and select "Set as StartUp Project".
  * In the "Debug" menu, click on "Start Debugging" (or just press F5). If you get a dialog saying that the project is out of date, click on "Yes" to rebuild it.
  * Once the build is complete, you should see console output from the tests in the "Output" window at lower right.
>>>>>>> miniblink49

Build and run SampleApp in Visual Studio
----------------------------------------

<<<<<<< HEAD
1.  Generate the Visual Studio project files by running `sync-and-gyp`
    as described above

2.  Open a File Explorer window pointing at the
    `%SKIA_INSTALLDIR%\trunk\out\gyp` directory

3.  Double-click on SampleApp.sln

4.  When Visual Studio starts, you may see an error dialog stating
    that "One or more project s in the solution were not loaded
    correctly"... but there's probably nothing to worry about.

5.  In the "Debug" menu, click on "Start Debugging" (or just press
    F5). If you get a dialog saying that the project is out of date,
    click on "Yes" to rebuild it.

6.  Once the build is complete, you should see a window with various
    example graphics. To move through the sample app, use the
    following keypresses:
    -    right- and left-arrow key: cycle through different test pages
    -    'D' key: cycle through rendering methods for each test page
    -    other keys are defined in SampleApp.cpp’s
         SampleWindow::onHandleKey() and SampleWindow::onHandleChar()
         methods
=======
  * Generate the Visual Studio project files by running gyp_skia as described above
  * Open a File Explorer window pointing at the %SKIA_INSTALLDIR%\trunk\out\gyp directory
  * Double-click on SampleApp.sln
  * When Visual Studio starts, you may see an error dialog stating that "One or more projects in the solution were not loaded correctly"... but there's probably nothing to worry about.
  * In the "Debug" menu, click on "Start Debugging" (or just press F5). If you get a dialog saying that the project is out of date, click on "Yes" to rebuild it.
  * Once the build is complete, you should see a window with various example graphics. To move through the sample app, use the following keypresses:
    * right-arrow key: cycle through different test pages
    * left-arrow key: cycle through rendering methods for each test page
    * other keys are defined in SampleApp.cpp’s SampleWindow::onHandleKey() and SampleWindow::onHandleChar() methods

Build and run nanobench (performance testbench) from the command line
---------------------------------------------------------------------

Since nanobench tests performance, it usually makes more sense to run it in Release mode.

    ninja -C out\Release nanobench
    out\Release\nanobench
>>>>>>> miniblink49
