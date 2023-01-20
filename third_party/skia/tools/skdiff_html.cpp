/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "skdiff_html.h"
#include "SkStream.h"
#include "SkTime.h"
#include "skdiff.h"

/// Make layout more consistent by scaling image to 240 height, 360 width,
/// or natural size, whichever is smallest.
static int compute_image_height(int height, int width)
{
=======
#include "skdiff.h"
#include "skdiff_html.h"
#include "SkStream.h"
#include "SkTime.h"

/// Make layout more consistent by scaling image to 240 height, 360 width,
/// or natural size, whichever is smallest.
static int compute_image_height(int height, int width) {
>>>>>>> miniblink49
    int retval = 240;
    if (height < retval) {
        retval = height;
    }
<<<<<<< HEAD
    float scale = (float)retval / height;
    if (width * scale > 360) {
        scale = (float)360 / width;
=======
    float scale = (float) retval / height;
    if (width * scale > 360) {
        scale = (float) 360 / width;
>>>>>>> miniblink49
        retval = static_cast<int>(height * scale);
    }
    return retval;
}

static void print_table_header(SkFILEWStream* stream,
<<<<<<< HEAD
    const int matchCount,
    const int colorThreshold,
    const RecordArray& differences,
    const SkString& baseDir,
    const SkString& comparisonDir,
    bool doOutputDate = false)
{
=======
                               const int matchCount,
                               const int colorThreshold,
                               const RecordArray& differences,
                               const SkString &baseDir,
                               const SkString &comparisonDir,
                               bool doOutputDate = false) {
>>>>>>> miniblink49
    stream->writeText("<table>\n");
    stream->writeText("<tr><th>");
    stream->writeText("select image</th>\n<th>");
    if (doOutputDate) {
        SkTime::DateTime dt;
        SkTime::GetDateTime(&dt);
        stream->writeText("SkDiff run at ");
        stream->writeDecAsText(dt.fHour);
        stream->writeText(":");
        if (dt.fMinute < 10) {
            stream->writeText("0");
        }
        stream->writeDecAsText(dt.fMinute);
        stream->writeText(":");
        if (dt.fSecond < 10) {
            stream->writeText("0");
        }
        stream->writeDecAsText(dt.fSecond);
        stream->writeText("<br>");
    }
    stream->writeDecAsText(matchCount);
    stream->writeText(" of ");
    stream->writeDecAsText(differences.count());
    stream->writeText(" diffs matched ");
    if (colorThreshold == 0) {
        stream->writeText("exactly");
    } else {
        stream->writeText("within ");
        stream->writeDecAsText(colorThreshold);
        stream->writeText(" color units per component");
    }
    stream->writeText(".<br>");
    stream->writeText("</th>\n<th>");
    stream->writeText("every different pixel shown in white");
    stream->writeText("</th>\n<th>");
    stream->writeText("color difference at each pixel");
    stream->writeText("</th>\n<th>baseDir: ");
    stream->writeText(baseDir.c_str());
    stream->writeText("</th>\n<th>comparisonDir: ");
    stream->writeText(comparisonDir.c_str());
    stream->writeText("</th>\n");
    stream->writeText("</tr>\n");
}

<<<<<<< HEAD
static void print_pixel_count(SkFILEWStream* stream, const DiffRecord& diff)
{
    stream->writeText("<br>(");
    stream->writeDecAsText(static_cast<int>(diff.fFractionDifference * diff.fBase.fBitmap.width() * diff.fBase.fBitmap.height()));
    stream->writeText(" pixels)");
    /*
=======
static void print_pixel_count(SkFILEWStream* stream, const DiffRecord& diff) {
    stream->writeText("<br>(");
    stream->writeDecAsText(static_cast<int>(diff.fFractionDifference *
                                            diff.fBase.fBitmap.width() *
                                            diff.fBase.fBitmap.height()));
    stream->writeText(" pixels)");
/*
>>>>>>> miniblink49
    stream->writeDecAsText(diff.fWeightedFraction *
                           diff.fBaseWidth *
                           diff.fBaseHeight);
    stream->writeText(" weighted pixels)");
*/
}

<<<<<<< HEAD
static void print_checkbox_cell(SkFILEWStream* stream, const DiffRecord& diff)
{
=======
static void print_checkbox_cell(SkFILEWStream* stream, const DiffRecord& diff) {
>>>>>>> miniblink49
    stream->writeText("<td><input type=\"checkbox\" name=\"");
    stream->writeText(diff.fBase.fFilename.c_str());
    stream->writeText("\" checked=\"yes\"></td>");
}

<<<<<<< HEAD
static void print_label_cell(SkFILEWStream* stream, const DiffRecord& diff)
{
    char metricBuf[20];
=======
static void print_label_cell(SkFILEWStream* stream, const DiffRecord& diff) {
    char metricBuf [20];
>>>>>>> miniblink49

    stream->writeText("<td><b>");
    stream->writeText(diff.fBase.fFilename.c_str());
    stream->writeText("</b><br>");
    switch (diff.fResult) {
<<<<<<< HEAD
    case DiffRecord::kEqualBits_Result:
        SkDEBUGFAIL("should not encounter DiffRecord with kEqualBits here");
        return;
    case DiffRecord::kEqualPixels_Result:
        SkDEBUGFAIL("should not encounter DiffRecord with kEqualPixels here");
        return;
    case DiffRecord::kDifferentSizes_Result:
        stream->writeText("Image sizes differ</td>");
        return;
    case DiffRecord::kDifferentPixels_Result:
=======
      case DiffRecord::kEqualBits_Result:
        SkDEBUGFAIL("should not encounter DiffRecord with kEqualBits here");
        return;
      case DiffRecord::kEqualPixels_Result:
        SkDEBUGFAIL("should not encounter DiffRecord with kEqualPixels here");
        return;
      case DiffRecord::kDifferentSizes_Result:
        stream->writeText("Image sizes differ</td>");
        return;
      case DiffRecord::kDifferentPixels_Result:
>>>>>>> miniblink49
        sprintf(metricBuf, "%.4f%%", 100 * diff.fFractionDifference);
        stream->writeText(metricBuf);
        stream->writeText(" of pixels differ");
        stream->writeText("\n  (");
        sprintf(metricBuf, "%.4f%%", 100 * diff.fWeightedFraction);
        stream->writeText(metricBuf);
        stream->writeText(" weighted)");
        // Write the actual number of pixels that differ if it's < 1%
        if (diff.fFractionDifference < 0.01) {
            print_pixel_count(stream, diff);
        }
        stream->writeText("<br>");
        if (SkScalarRoundToInt(diff.fAverageMismatchA) > 0) {
<<<<<<< HEAD
            stream->writeText("<br>Average alpha channel mismatch ");
            stream->writeDecAsText(SkScalarRoundToInt(diff.fAverageMismatchA));
=======
          stream->writeText("<br>Average alpha channel mismatch ");
          stream->writeDecAsText(SkScalarRoundToInt(diff.fAverageMismatchA));
>>>>>>> miniblink49
        }

        stream->writeText("<br>Max alpha channel mismatch ");
        stream->writeDecAsText(SkScalarRoundToInt(diff.fMaxMismatchA));

        stream->writeText("<br>Total alpha channel mismatch ");
        stream->writeDecAsText(static_cast<int>(diff.fTotalMismatchA));

        stream->writeText("<br>");
        stream->writeText("<br>Average color mismatch ");
        stream->writeDecAsText(SkScalarRoundToInt(MAX3(diff.fAverageMismatchR,
<<<<<<< HEAD
            diff.fAverageMismatchG,
            diff.fAverageMismatchB)));
        stream->writeText("<br>Max color mismatch ");
        stream->writeDecAsText(MAX3(diff.fMaxMismatchR,
            diff.fMaxMismatchG,
            diff.fMaxMismatchB));
        stream->writeText("</td>");
        break;
    case DiffRecord::kCouldNotCompare_Result:
=======
                                                       diff.fAverageMismatchG,
                                                       diff.fAverageMismatchB)));
        stream->writeText("<br>Max color mismatch ");
        stream->writeDecAsText(MAX3(diff.fMaxMismatchR,
                                    diff.fMaxMismatchG,
                                    diff.fMaxMismatchB));
        stream->writeText("</td>");
        break;
      case DiffRecord::kCouldNotCompare_Result:
>>>>>>> miniblink49
        stream->writeText("Could not compare.<br>base: ");
        stream->writeText(DiffResource::getStatusDescription(diff.fBase.fStatus));
        stream->writeText("<br>comparison: ");
        stream->writeText(DiffResource::getStatusDescription(diff.fComparison.fStatus));
        stream->writeText("</td>");
        return;
<<<<<<< HEAD
    default:
=======
      default:
>>>>>>> miniblink49
        SkDEBUGFAIL("encountered DiffRecord with unknown result type");
        return;
    }
}

<<<<<<< HEAD
static void print_image_cell(SkFILEWStream* stream, const SkString& path, int height)
{
=======
static void print_image_cell(SkFILEWStream* stream, const SkString& path, int height) {
>>>>>>> miniblink49
    stream->writeText("<td><a href=\"");
    stream->writeText(path.c_str());
    stream->writeText("\"><img src=\"");
    stream->writeText(path.c_str());
    stream->writeText("\" height=\"");
    stream->writeDecAsText(height);
    stream->writeText("px\"></a></td>");
}

<<<<<<< HEAD
static void print_link_cell(SkFILEWStream* stream, const SkString& path, const char* text)
{
=======
static void print_link_cell(SkFILEWStream* stream, const SkString& path, const char* text) {
>>>>>>> miniblink49
    stream->writeText("<td><a href=\"");
    stream->writeText(path.c_str());
    stream->writeText("\">");
    stream->writeText(text);
    stream->writeText("</a></td>");
}

static void print_diff_resource_cell(SkFILEWStream* stream, DiffResource& resource,
<<<<<<< HEAD
    const SkString& relativePath, bool local)
{
=======
                                     const SkString& relativePath, bool local) {
>>>>>>> miniblink49
    if (resource.fBitmap.empty()) {
        if (DiffResource::kCouldNotDecode_Status == resource.fStatus) {
            if (local && !resource.fFilename.isEmpty()) {
                print_link_cell(stream, resource.fFilename, "N/A");
                return;
            }
            if (!resource.fFullPath.isEmpty()) {
                if (!resource.fFullPath.startsWith(PATH_DIV_STR)) {
                    resource.fFullPath.prepend(relativePath);
                }
                print_link_cell(stream, resource.fFullPath, "N/A");
                return;
            }
        }
        stream->writeText("<td>N/A</td>");
        return;
    }

    int height = compute_image_height(resource.fBitmap.height(), resource.fBitmap.width());
    if (local) {
        print_image_cell(stream, resource.fFilename, height);
        return;
    }
    if (!resource.fFullPath.startsWith(PATH_DIV_STR)) {
        resource.fFullPath.prepend(relativePath);
    }
    print_image_cell(stream, resource.fFullPath, height);
}

<<<<<<< HEAD
static void print_diff_row(SkFILEWStream* stream, DiffRecord& diff, const SkString& relativePath)
{
=======
static void print_diff_row(SkFILEWStream* stream, DiffRecord& diff, const SkString& relativePath) {
>>>>>>> miniblink49
    stream->writeText("<tr>\n");
    print_checkbox_cell(stream, diff);
    print_label_cell(stream, diff);
    print_diff_resource_cell(stream, diff.fWhite, relativePath, true);
    print_diff_resource_cell(stream, diff.fDifference, relativePath, true);
    print_diff_resource_cell(stream, diff.fBase, relativePath, false);
    print_diff_resource_cell(stream, diff.fComparison, relativePath, false);
    stream->writeText("</tr>\n");
    stream->flush();
}

void print_diff_page(const int matchCount,
<<<<<<< HEAD
    const int colorThreshold,
    const RecordArray& differences,
    const SkString& baseDir,
    const SkString& comparisonDir,
    const SkString& outputDir)
{
=======
                     const int colorThreshold,
                     const RecordArray& differences,
                     const SkString& baseDir,
                     const SkString& comparisonDir,
                     const SkString& outputDir) {
>>>>>>> miniblink49

    SkASSERT(!baseDir.isEmpty());
    SkASSERT(!comparisonDir.isEmpty());
    SkASSERT(!outputDir.isEmpty());

    SkString outputPath(outputDir);
    outputPath.append("index.html");
    //SkFILEWStream outputStream ("index.html");
    SkFILEWStream outputStream(outputPath.c_str());

    // Need to convert paths from relative-to-cwd to relative-to-outputDir
    // FIXME this doesn't work if there are '..' inside the outputDir

    bool isPathAbsolute = false;
    // On Windows or Linux, a path starting with PATH_DIV_CHAR is absolute.
    if (outputDir.size() > 0 && PATH_DIV_CHAR == outputDir[0]) {
        isPathAbsolute = true;
    }
#ifdef SK_BUILD_FOR_WIN32
    // On Windows, absolute paths can also start with "x:", where x is any
    // drive letter.
    if (outputDir.size() > 1 && ':' == outputDir[1]) {
        isPathAbsolute = true;
    }
#endif

    SkString relativePath;
    if (!isPathAbsolute) {
        unsigned int ui;
        for (ui = 0; ui < outputDir.size(); ui++) {
            if (outputDir[ui] == PATH_DIV_CHAR) {
                relativePath.append(".." PATH_DIV_STR);
            }
        }
    }

    outputStream.writeText(
        "<html>\n<head>\n"
        "<script src=\"https://ajax.googleapis.com/ajax/"
        "libs/jquery/1.7.2/jquery.min.js\"></script>\n"
        "<script type=\"text/javascript\">\n"
        "function generateCheckedList() {\n"
        "var boxes = $(\":checkbox:checked\");\n"
        "var fileCmdLineString = '';\n"
        "var fileMultiLineString = '';\n"
        "for (var i = 0; i < boxes.length; i++) {\n"
        "fileMultiLineString += boxes[i].name + '<br>';\n"
        "fileCmdLineString += boxes[i].name + '&nbsp;';\n"
        "}\n"
        "$(\"#checkedList\").html(fileCmdLineString + "
        "'<br><br>' + fileMultiLineString);\n"
        "}\n"
        "</script>\n</head>\n<body>\n");
    print_table_header(&outputStream, matchCount, colorThreshold, differences,
<<<<<<< HEAD
        baseDir, comparisonDir);
=======
                       baseDir, comparisonDir);
>>>>>>> miniblink49
    int i;
    for (i = 0; i < differences.count(); i++) {
        DiffRecord* diff = differences[i];

        switch (diff->fResult) {
<<<<<<< HEAD
        // Cases in which there is no diff to report.
        case DiffRecord::kEqualBits_Result:
        case DiffRecord::kEqualPixels_Result:
            continue;
        // Cases in which we want a detailed pixel diff.
        case DiffRecord::kDifferentPixels_Result:
        case DiffRecord::kDifferentSizes_Result:
        case DiffRecord::kCouldNotCompare_Result:
            print_diff_row(&outputStream, *diff, relativePath);
            continue;
        default:
=======
          // Cases in which there is no diff to report.
          case DiffRecord::kEqualBits_Result:
          case DiffRecord::kEqualPixels_Result:
            continue;
          // Cases in which we want a detailed pixel diff.
          case DiffRecord::kDifferentPixels_Result:
          case DiffRecord::kDifferentSizes_Result:
          case DiffRecord::kCouldNotCompare_Result:
            print_diff_row(&outputStream, *diff, relativePath);
            continue;
          default:
>>>>>>> miniblink49
            SkDEBUGFAIL("encountered DiffRecord with unknown result type");
            continue;
        }
    }
    outputStream.writeText(
        "</table>\n"
        "<input type=\"button\" "
        "onclick=\"generateCheckedList()\" "
        "value=\"Create Rebaseline List\">\n"
        "<div id=\"checkedList\"></div>\n"
        "</body>\n</html>\n");
    outputStream.flush();
}
