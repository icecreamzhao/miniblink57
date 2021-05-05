/*
 * Copyright 2015 Skia
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_skia_SkiaSampleRenderer */

#ifndef _Included_com_skia_SkiaSampleRenderer
#define _Included_com_skia_SkiaSampleRenderer
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    init
 * Signature: (Lcom/skia/SkiaSampleActivity;Ljava/lang/String;I)V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_init(JNIEnv*, jobject, jobject, jstring, jint);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    term
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_term(JNIEnv*, jobject);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    draw
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_draw(JNIEnv*, jobject);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    updateSize
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_updateSize(JNIEnv*, jobject, jint, jint);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    handleClick
 * Signature: (IFFI)V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_handleClick(JNIEnv*, jobject, jint, jfloat, jfloat, jint);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    showOverview
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_showOverview(JNIEnv*, jobject);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    nextSample
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_nextSample(JNIEnv*, jobject);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    previousSample
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_previousSample(JNIEnv*, jobject);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    goToSample
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_goToSample(JNIEnv*, jobject, jint);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    toggleRenderingMode
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_toggleRenderingMode(JNIEnv*, jobject);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    toggleSlideshow
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_toggleSlideshow(JNIEnv*, jobject);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    toggleFPS
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_toggleFPS(JNIEnv*, jobject);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    toggleTiling
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_toggleTiling(JNIEnv*, jobject);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    toggleBBox
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_toggleBBox(JNIEnv*, jobject);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    processSkEvent
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_processSkEvent(JNIEnv*, jobject);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    serviceQueueTimer
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_serviceQueueTimer(JNIEnv*, jobject);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    saveToPdf
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_saveToPDF(JNIEnv*, jobject);

/*
 * Class:     com_skia_SkiaSampleRenderer
 * Method:    postInval
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_skia_SkiaSampleRenderer_postInval(JNIEnv*, jobject);

#ifdef __cplusplus
}
#endif
#endif
