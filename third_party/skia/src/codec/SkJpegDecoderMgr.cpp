/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkJpegDecoderMgr.h"
<<<<<<< HEAD

#include "SkJpegUtility.h"
=======
#include "SkJpegUtility_codec.h"
>>>>>>> miniblink49

/*
 * Print information, warning, and error messages
 */
<<<<<<< HEAD
static void print_message(const j_common_ptr info, const char caller[])
{
=======
static void print_message(const j_common_ptr info, const char caller[]) {
>>>>>>> miniblink49
    char buffer[JMSG_LENGTH_MAX];
    info->err->format_message(info, buffer);
    SkCodecPrintf("libjpeg error %d <%s> from %s\n", info->err->msg_code, buffer, caller);
}

/*
<<<<<<< HEAD
 * Reporting function for error and warning messages.
 */
static void output_message(j_common_ptr info)
{
    print_message(info, "output_message");
}

bool JpegDecoderMgr::returnFalse(const char caller[])
{
    print_message((j_common_ptr)&fDInfo, caller);
    return false;
}

SkCodec::Result JpegDecoderMgr::returnFailure(const char caller[], SkCodec::Result result)
{
    print_message((j_common_ptr)&fDInfo, caller);
    return result;
}

bool JpegDecoderMgr::getEncodedColor(SkEncodedInfo::Color* outColor)
{
    switch (fDInfo.jpeg_color_space) {
    case JCS_GRAYSCALE:
        *outColor = SkEncodedInfo::kGray_Color;
        return true;
    case JCS_YCbCr:
        *outColor = SkEncodedInfo::kYUV_Color;
        return true;
    case JCS_RGB:
        *outColor = SkEncodedInfo::kRGB_Color;
        return true;
    case JCS_YCCK:
        *outColor = SkEncodedInfo::kYCCK_Color;
        return true;
    case JCS_CMYK:
        *outColor = SkEncodedInfo::kInvertedCMYK_Color;
        return true;
    default:
        return false;
=======
 * Reporting functions for libjpeg
 */
static void emit_message(j_common_ptr info, int) {
    print_message(info, "emit_message");
}
static void output_message(j_common_ptr info) {
    print_message(info, "output_message");
}

bool JpegDecoderMgr::returnFalse(const char caller[]) {
    print_message((j_common_ptr) &fDInfo, caller);
    return false;
}

SkCodec::Result JpegDecoderMgr::returnFailure(const char caller[], SkCodec::Result result) {
    print_message((j_common_ptr) &fDInfo, caller);
    return result;
}

SkColorType JpegDecoderMgr::getColorType() {
    switch (fDInfo.jpeg_color_space) {
        case JCS_GRAYSCALE:
            return kGray_8_SkColorType;
        default:
            return kN32_SkColorType;
>>>>>>> miniblink49
    }
}

JpegDecoderMgr::JpegDecoderMgr(SkStream* stream)
    : fSrcMgr(stream)
    , fInit(false)
{
    // Error manager must be set before any calls to libjeg in order to handle failures
<<<<<<< HEAD
    fDInfo.err = jpeg_std_error(&fErrorMgr);
    fErrorMgr.error_exit = skjpeg_err_exit;
}

void JpegDecoderMgr::init()
{
    jpeg_create_decompress(&fDInfo);
    fInit = true;
    fDInfo.src = &fSrcMgr;
    fDInfo.err->output_message = &output_message;
}

JpegDecoderMgr::~JpegDecoderMgr()
{
=======
    fDInfo.err = turbo_jpeg_std_error(&fErrorMgr);
    fErrorMgr.error_exit = skjpeg_err_exit;
}

void JpegDecoderMgr::init() {
    jpeg_create_decompress(&fDInfo);
    fInit = true;
    fDInfo.src = &fSrcMgr;
    fDInfo.err->emit_message = &emit_message;
    fDInfo.err->output_message = &output_message;
}

JpegDecoderMgr::~JpegDecoderMgr() {
>>>>>>> miniblink49
    if (fInit) {
        jpeg_destroy_decompress(&fDInfo);
    }
}

<<<<<<< HEAD
jmp_buf& JpegDecoderMgr::getJmpBuf()
{
    return fErrorMgr.fJmpBuf;
}

jpeg_decompress_struct* JpegDecoderMgr::dinfo()
{
=======
jmp_buf& JpegDecoderMgr::getJmpBuf() {
    return fErrorMgr.fJmpBuf;
}

jpeg_decompress_struct* JpegDecoderMgr::dinfo() {
>>>>>>> miniblink49
    return &fDInfo;
}
