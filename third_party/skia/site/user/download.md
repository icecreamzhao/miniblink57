How to download Skia
====================

<<<<<<< HEAD
Install depot_tools and Git
---------------------------

Follow the instructions on [Installing Chromium's
depot_tools](http://www.chromium.org/developers/how-tos/install-depot-tools)
to download depot_tools (which includes gclient, git-cl, and Ninja).

<!--?prettify lang=sh?-->

    git clone 'https://chromium.googlesource.com/chromium/tools/depot_tools.git'
    export PATH="${PWD}/depot_tools:${PATH}"

depot_tools will also install Git on your system, if it wasn't installed
already.

Clone the Skia repository
-------------------------

<!--?prettify lang=sh?-->

    git clone https://skia.googlesource.com/skia.git
    cd skia

Getting started with Skia
-------------------------

Try out more things from the [desktop](./quick/desktop),
[Android](./quick/android), and [iOS](./quick/ios)-specific Skia
guides.

Changing and contributing to Skia
---------------------------------

At this point, you have everything you need to build and use Skia!  If
you want to make changes, and possibly contribute them back to the Skia
project, read [How To Submit a Patch](../dev/contrib/submit).
=======
Install gclient and git
-----------------------

Follow the instructions on
http://www.chromium.org/developers/how-tos/install-depot-tools to download
chromium's depot_tools (which includes gclient ).

depot_tools will also install git on your system, if it wasn't installed
already.



Configure git
-------------

    $ git config --global user.name "Your Name"
    $ git config --global user.email you@example.com

Download your tree
------------------

    $ mkdir skia
    $ cd skia
    $ gclient config --name . --unmanaged https://skia.googlesource.com/skia.git
    $ gclient sync
    $ git checkout master

At this point, you have everything you need to build and use Skia!  If
you want to make changes, and possibly contribute them back to the Skia
project, read on...

Making changes
--------------

First create a branch for your changes:

    $ git checkout --track origin/master -b my_feature master

After making your changes, create a commit

    $ git add [file1] [file2] ...
    $ git commit

If your branch gets out of date, you will need to update it:

    $ git pull --rebase
    $ gclient sync

Uploading changes for review
----------------------------

    $ git cl upload

You may have to enter a Google Account username and password to authenticate
yourself to codereview.chromium.org. A free gmail account will do fine, or any
other type of Google account.  It does not have to match the email address you
configured using git config --global user.email above, but it can.

The command output should include a URL (similar to
https://codereview.chromium.org/111893004/ ) indicating where your changelist
can be reviewed.

Once your change has received an LGTM ("looks good to me"), you can check the
"Commit" box on the codereview page and it will be committed on your behalf.

Once your commit has gone in, you should delete the branch containing your
change:

    $ git checkout master
    $ git branch -D my_feature

>>>>>>> miniblink49
