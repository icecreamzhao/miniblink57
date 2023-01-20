// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DevToolsHostFileSystem_h
#define DevToolsHostFileSystem_h

#include "platform/heap/Handle.h"
<<<<<<< HEAD
#include "wtf/Allocator.h"
=======
>>>>>>> miniblink49
#include "wtf/text/WTFString.h"

namespace blink {

class DOMFileSystem;
class DevToolsHost;

class DevToolsHostFileSystem {
<<<<<<< HEAD
    STATIC_ONLY(DevToolsHostFileSystem);

public:
    static DOMFileSystem* isolatedFileSystem(DevToolsHost&,
        const String& fileSystemName,
        const String& rootURL);
    static void upgradeDraggedFileSystemPermissions(DevToolsHost&,
        DOMFileSystem*);
=======
public:
    static DOMFileSystem* isolatedFileSystem(DevToolsHost&, const String& fileSystemName, const String& rootURL);
    static void upgradeDraggedFileSystemPermissions(DevToolsHost&, DOMFileSystem*);
private:
    DevToolsHostFileSystem();
    ~DevToolsHostFileSystem();
>>>>>>> miniblink49
};

} // namespace blink

#endif // !defined(DevToolsHostFileSystem_h)
