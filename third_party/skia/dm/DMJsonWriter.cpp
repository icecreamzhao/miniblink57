/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "DMJsonWriter.h"

#include "ProcStats.h"
#include "SkCommonFlags.h"
#include "SkData.h"
#include "SkJSONCPP.h"
#include "SkMutex.h"
#include "SkOSFile.h"
#include "SkStream.h"
#include "SkTArray.h"

namespace DM {

SkTArray<JsonWriter::BitmapResult> gBitmapResults;
SK_DECLARE_STATIC_MUTEX(gBitmapResultLock);

<<<<<<< HEAD
void JsonWriter::AddBitmapResult(const BitmapResult& result)
{
=======
void JsonWriter::AddBitmapResult(const BitmapResult& result) {
>>>>>>> miniblink49
    SkAutoMutexAcquire lock(&gBitmapResultLock);
    gBitmapResults.push_back(result);
}

SkTArray<skiatest::Failure> gFailures;
SK_DECLARE_STATIC_MUTEX(gFailureLock);

<<<<<<< HEAD
void JsonWriter::AddTestFailure(const skiatest::Failure& failure)
{
=======
void JsonWriter::AddTestFailure(const skiatest::Failure& failure) {
>>>>>>> miniblink49
    SkAutoMutexAcquire lock(gFailureLock);
    gFailures.push_back(failure);
}

<<<<<<< HEAD
void JsonWriter::DumpJson()
{
=======
void JsonWriter::DumpJson() {
>>>>>>> miniblink49
    if (FLAGS_writePath.isEmpty()) {
        return;
    }

    Json::Value root;

    for (int i = 1; i < FLAGS_properties.count(); i += 2) {
<<<<<<< HEAD
        root[FLAGS_properties[i - 1]] = FLAGS_properties[i];
    }
    for (int i = 1; i < FLAGS_key.count(); i += 2) {
        root["key"][FLAGS_key[i - 1]] = FLAGS_key[i];
=======
        root[FLAGS_properties[i-1]] = FLAGS_properties[i];
    }
    for (int i = 1; i < FLAGS_key.count(); i += 2) {
        root["key"][FLAGS_key[i-1]] = FLAGS_key[i];
>>>>>>> miniblink49
    }

    {
        SkAutoMutexAcquire lock(&gBitmapResultLock);
        for (int i = 0; i < gBitmapResults.count(); i++) {
            Json::Value result;
<<<<<<< HEAD
            result["key"]["name"] = gBitmapResults[i].name.c_str();
            result["key"]["config"] = gBitmapResults[i].config.c_str();
            result["key"]["source_type"] = gBitmapResults[i].sourceType.c_str();
            result["options"]["ext"] = gBitmapResults[i].ext.c_str();
            result["options"]["gamma_correct"] = gBitmapResults[i].gammaCorrect ? "yes" : "no";
            result["md5"] = gBitmapResults[i].md5.c_str();
=======
            result["key"]["name"]        = gBitmapResults[i].name.c_str();
            result["key"]["config"]      = gBitmapResults[i].config.c_str();
            result["key"]["source_type"] = gBitmapResults[i].sourceType.c_str();
            result["options"]["ext"]     = gBitmapResults[i].ext.c_str();
            result["md5"]                = gBitmapResults[i].md5.c_str();
>>>>>>> miniblink49

            // Source options only need to be part of the key if they exist.
            // Source type by source type, we either always set options or never set options.
            if (!gBitmapResults[i].sourceOptions.isEmpty()) {
                result["key"]["source_options"] = gBitmapResults[i].sourceOptions.c_str();
            }

            root["results"].append(result);
        }
    }

    {
        SkAutoMutexAcquire lock(gFailureLock);
        for (int i = 0; i < gFailures.count(); i++) {
            Json::Value result;
<<<<<<< HEAD
            result["file_name"] = gFailures[i].fileName;
            result["line_no"] = gFailures[i].lineNo;
            result["condition"] = gFailures[i].condition;
            result["message"] = gFailures[i].message.c_str();
=======
            result["file_name"]     = gFailures[i].fileName;
            result["line_no"]       = gFailures[i].lineNo;
            result["condition"]     = gFailures[i].condition;
            result["message"]       = gFailures[i].message.c_str();
>>>>>>> miniblink49

            root["test_results"]["failures"].append(result);
        }
    }

    int maxResidentSetSizeMB = sk_tools::getMaxResidentSetSizeMB();
    if (maxResidentSetSizeMB != -1) {
        root["max_rss_MB"] = sk_tools::getMaxResidentSetSizeMB();
    }

    SkString path = SkOSPath::Join(FLAGS_writePath[0], "dm.json");
    sk_mkdir(FLAGS_writePath[0]);
    SkFILEWStream stream(path.c_str());
    stream.writeText(Json::StyledWriter().write(root).c_str());
    stream.flush();
}

<<<<<<< HEAD
bool JsonWriter::ReadJson(const char* path, void (*callback)(BitmapResult))
{
=======
bool JsonWriter::ReadJson(const char* path, void(*callback)(BitmapResult)) {
>>>>>>> miniblink49
    SkAutoTUnref<SkData> json(SkData::NewFromFileName(path));
    if (!json) {
        return false;
    }

    Json::Reader reader;
    Json::Value root;
    const char* data = (const char*)json->data();
<<<<<<< HEAD
    if (!reader.parse(data, data + json->size(), root)) {
=======
    if (!reader.parse(data, data+json->size(), root)) {
>>>>>>> miniblink49
        return false;
    }

    const Json::Value& results = root["results"];
    BitmapResult br;
    for (unsigned i = 0; i < results.size(); i++) {
        const Json::Value& r = results[i];
<<<<<<< HEAD
        br.name = r["key"]["name"].asCString();
        br.config = r["key"]["config"].asCString();
        br.sourceType = r["key"]["source_type"].asCString();
        br.ext = r["options"]["ext"].asCString();
        br.gammaCorrect = 0 == strcmp("yes", r["options"]["gamma_correct"].asCString());
        br.md5 = r["md5"].asCString();
=======
        br.name       = r["key"]["name"].asCString();
        br.config     = r["key"]["config"].asCString();
        br.sourceType = r["key"]["source_type"].asCString();
        br.ext        = r["options"]["ext"].asCString();
        br.md5        = r["md5"].asCString();
>>>>>>> miniblink49

        if (!r["key"]["source_options"].isNull()) {
            br.sourceOptions = r["key"]["source_options"].asCString();
        }
        callback(br);
    }
    return true;
}

} // namespace DM
