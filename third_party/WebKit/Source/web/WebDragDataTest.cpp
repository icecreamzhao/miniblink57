// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "public/platform/WebDragData.h"

#include "core/clipboard/DataObject.h"
#include "public/platform/WebVector.h"
<<<<<<< HEAD
#include "testing/gtest/include/gtest/gtest.h"
=======
#include <gtest/gtest.h>
>>>>>>> miniblink49

namespace blink {

TEST(WebDragDataTest, items)
{
    DataObject* dataObject = DataObject::create();

    // Native file.
    dataObject->add(File::create("/native/path"));

    // Blob file.
    const RefPtr<BlobDataHandle> blobDataHandle = BlobDataHandle::create();
    dataObject->add(File::create("name", 0.0, blobDataHandle));

    // User visible snapshot file.
    {
        FileMetadata metadata;
        metadata.platformPath = "/native/visible/snapshot";
<<<<<<< HEAD
        dataObject->add(
            File::createForFileSystemFile("name", metadata, File::IsUserVisible));
=======
        dataObject->add(File::createForFileSystemFile("name", metadata, File::IsUserVisible));
>>>>>>> miniblink49
    }

    // Not user visible snapshot file.
    {
        FileMetadata metadata;
        metadata.platformPath = "/native/not-visible/snapshot";
<<<<<<< HEAD
        dataObject->add(File::createForFileSystemFile("name", metadata,
            File::IsNotUserVisible));
=======
        dataObject->add(File::createForFileSystemFile("name", metadata, File::IsNotUserVisible));
>>>>>>> miniblink49
    }

    // User visible file system URL file.
    {
        FileMetadata metadata;
        metadata.length = 1234;
<<<<<<< HEAD
        KURL url(
            ParsedURLStringTag(),
            "filesystem:http://example.com/isolated/hash/visible-non-native-file");
        dataObject->add(
            File::createForFileSystemFile(url, metadata, File::IsUserVisible));
=======
        KURL url(ParsedURLStringTag(), "filesystem:http://example.com/isolated/hash/visible-non-native-file");
        dataObject->add(File::createForFileSystemFile(url, metadata, File::IsUserVisible));
>>>>>>> miniblink49
    }

    // Not user visible file system URL file.
    {
        FileMetadata metadata;
        metadata.length = 1234;
<<<<<<< HEAD
        KURL url(ParsedURLStringTag(),
            "filesystem:http://example.com/isolated/hash/"
            "not-visible-non-native-file");
        dataObject->add(
            File::createForFileSystemFile(url, metadata, File::IsNotUserVisible));
=======
        KURL url(ParsedURLStringTag(), "filesystem:http://example.com/isolated/hash/not-visible-non-native-file");
        dataObject->add(File::createForFileSystemFile(url, metadata, File::IsNotUserVisible));
>>>>>>> miniblink49
    }

    WebDragData data = dataObject->toWebDragData();
    WebVector<WebDragData::Item> items = data.items();
    ASSERT_EQ(6u, items.size());

    EXPECT_EQ(WebDragData::Item::StorageTypeFilename, items[0].storageType);
    EXPECT_EQ("/native/path", items[0].filenameData);
    EXPECT_EQ("path", items[0].displayNameData);

    EXPECT_EQ(WebDragData::Item::StorageTypeString, items[1].storageType);
    EXPECT_EQ("text/plain", items[1].stringType);
    EXPECT_EQ("name", items[1].stringData);

    EXPECT_EQ(WebDragData::Item::StorageTypeFilename, items[2].storageType);
    EXPECT_EQ("/native/visible/snapshot", items[2].filenameData);
    EXPECT_EQ("name", items[2].displayNameData);

    EXPECT_EQ(WebDragData::Item::StorageTypeFilename, items[3].storageType);
    EXPECT_EQ("/native/not-visible/snapshot", items[3].filenameData);
    EXPECT_EQ("name", items[3].displayNameData);

    EXPECT_EQ(WebDragData::Item::StorageTypeFileSystemFile, items[4].storageType);
<<<<<<< HEAD
    EXPECT_EQ(
        "filesystem:http://example.com/isolated/hash/visible-non-native-file",
        items[4].fileSystemURL);
    EXPECT_EQ(1234, items[4].fileSystemFileSize);

    EXPECT_EQ(WebDragData::Item::StorageTypeFileSystemFile, items[5].storageType);
    EXPECT_EQ(
        "filesystem:http://example.com/isolated/hash/not-visible-non-native-file",
        items[5].fileSystemURL);
=======
    EXPECT_EQ("filesystem:http://example.com/isolated/hash/visible-non-native-file", items[4].fileSystemURL);
    EXPECT_EQ(1234, items[4].fileSystemFileSize);

    EXPECT_EQ(WebDragData::Item::StorageTypeFileSystemFile, items[5].storageType);
    EXPECT_EQ("filesystem:http://example.com/isolated/hash/not-visible-non-native-file", items[5].fileSystemURL);
>>>>>>> miniblink49
    EXPECT_EQ(1234, items[5].fileSystemFileSize);
}

} // namespace blink
