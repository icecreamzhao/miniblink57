/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
#include "public/web/WebRuntimeFeatures.h"

#include "platform/RuntimeEnabledFeatures.h"
#include "wtf/Assertions.h"
=======
#include "config.h"
#include "public/web/WebRuntimeFeatures.h"

#include "platform/RuntimeEnabledFeatures.h"
#include "web/WebMediaPlayerClientImpl.h"
>>>>>>> miniblink49

namespace blink {

void WebRuntimeFeatures::enableExperimentalFeatures(bool enable)
{
    RuntimeEnabledFeatures::setExperimentalFeaturesEnabled(enable);
}

void WebRuntimeFeatures::enableWebBluetooth(bool enable)
{
    RuntimeEnabledFeatures::setWebBluetoothEnabled(enable);
}

<<<<<<< HEAD
void WebRuntimeFeatures::enableWebAssemblySerialization(bool enable)
{
    RuntimeEnabledFeatures::setWebAssemblySerializationEnabled(enable);
}

void WebRuntimeFeatures::enableWebUsb(bool enable)
{
    RuntimeEnabledFeatures::setWebUSBEnabled(enable);
}

void WebRuntimeFeatures::enableFeatureFromString(const std::string& name,
    bool enable)
=======
void WebRuntimeFeatures::enableFeatureFromString(const WebString& name, bool enable)
>>>>>>> miniblink49
{
    RuntimeEnabledFeatures::setFeatureEnabledFromString(name, enable);
}

<<<<<<< HEAD
=======
void WebRuntimeFeatures::enableBleedingEdgeFastPaths(bool enable)
{
    ASSERT(enable);
    RuntimeEnabledFeatures::setBleedingEdgeFastPathsEnabled(enable);
    RuntimeEnabledFeatures::setWebAnimationsAPIEnabled(enable);
}

void WebRuntimeFeatures::enableBlinkScheduler(bool enable)
{
    RuntimeEnabledFeatures::setBlinkSchedulerEnabled(enable);
}

void WebRuntimeFeatures::enableCompositorAnimationTimelines(bool enable)
{
    RuntimeEnabledFeatures::setCompositorAnimationTimelinesEnabled(enable);
}

>>>>>>> miniblink49
void WebRuntimeFeatures::enableTestOnlyFeatures(bool enable)
{
    RuntimeEnabledFeatures::setTestFeaturesEnabled(enable);
}

<<<<<<< HEAD
void WebRuntimeFeatures::enableAccelerated2dCanvas(bool enable)
{
    RuntimeEnabledFeatures::setAccelerated2dCanvasEnabled(enable);
}

void WebRuntimeFeatures::enableAudioOutputDevices(bool enable)
{
    RuntimeEnabledFeatures::setAudioOutputDevicesEnabled(enable);
}

void WebRuntimeFeatures::enableCanvas2dImageChromium(bool enable)
{
    RuntimeEnabledFeatures::setCanvas2dImageChromiumEnabled(enable);
}

void WebRuntimeFeatures::enableColorCorrectRendering(bool enable)
{
    RuntimeEnabledFeatures::setColorCorrectRenderingEnabled(enable);
}

void WebRuntimeFeatures::enableColorCorrectRenderingDefaultMode(bool enable)
{
    RuntimeEnabledFeatures::setColorCorrectRenderingDefaultModeEnabled(enable);
}

void WebRuntimeFeatures::enableTrueColorRendering(bool enable)
{
    RuntimeEnabledFeatures::setTrueColorRenderingEnabled(enable);
=======
void WebRuntimeFeatures::enableApplicationCache(bool enable)
{
    RuntimeEnabledFeatures::setApplicationCacheEnabled(enable);
>>>>>>> miniblink49
}

void WebRuntimeFeatures::enableCompositedSelectionUpdate(bool enable)
{
    RuntimeEnabledFeatures::setCompositedSelectionUpdateEnabled(enable);
}

bool WebRuntimeFeatures::isCompositedSelectionUpdateEnabled()
{
    return RuntimeEnabledFeatures::compositedSelectionUpdateEnabled();
}

void WebRuntimeFeatures::enableDatabase(bool enable)
{
    RuntimeEnabledFeatures::setDatabaseEnabled(enable);
}

void WebRuntimeFeatures::enableDecodeToYUV(bool enable)
{
    RuntimeEnabledFeatures::setDecodeToYUVEnabled(enable);
}

void WebRuntimeFeatures::forceDisplayList2dCanvas(bool enable)
{
    RuntimeEnabledFeatures::setForceDisplayList2dCanvasEnabled(enable);
}

<<<<<<< HEAD
void WebRuntimeFeatures::forceDisable2dCanvasCopyOnWrite(bool enable)
{
    RuntimeEnabledFeatures::setForceDisable2dCanvasCopyOnWriteEnabled(enable);
}

=======
>>>>>>> miniblink49
void WebRuntimeFeatures::enableDisplayList2dCanvas(bool enable)
{
    RuntimeEnabledFeatures::setDisplayList2dCanvasEnabled(enable);
}

<<<<<<< HEAD
void WebRuntimeFeatures::enableCanvas2dDynamicRenderingModeSwitching(
    bool enable)
{
    RuntimeEnabledFeatures::setEnableCanvas2dDynamicRenderingModeSwitchingEnabled(
        enable);
}

void WebRuntimeFeatures::enableDocumentWriteEvaluator(bool enable)
{
    RuntimeEnabledFeatures::setDocumentWriteEvaluatorEnabled(enable);
=======
void WebRuntimeFeatures::enableEncryptedMedia(bool enable)
{
    RuntimeEnabledFeatures::setEncryptedMediaEnabled(enable);
}

bool WebRuntimeFeatures::isEncryptedMediaEnabled()
{
    return RuntimeEnabledFeatures::encryptedMediaEnabled();
}

void WebRuntimeFeatures::enablePrefixedEncryptedMedia(bool enable)
{
    RuntimeEnabledFeatures::setPrefixedEncryptedMediaEnabled(enable);
}

bool WebRuntimeFeatures::isPrefixedEncryptedMediaEnabled()
{
    return RuntimeEnabledFeatures::prefixedEncryptedMediaEnabled();
>>>>>>> miniblink49
}

void WebRuntimeFeatures::enableExperimentalCanvasFeatures(bool enable)
{
    RuntimeEnabledFeatures::setExperimentalCanvasFeaturesEnabled(enable);
}

<<<<<<< HEAD
void WebRuntimeFeatures::enableFasterLocationReload(bool enable)
{
    RuntimeEnabledFeatures::setFasterLocationReloadEnabled(enable);
}

=======
>>>>>>> miniblink49
void WebRuntimeFeatures::enableFastMobileScrolling(bool enable)
{
    RuntimeEnabledFeatures::setFastMobileScrollingEnabled(enable);
}

<<<<<<< HEAD
void WebRuntimeFeatures::enableFeaturePolicy(bool enable)
{
    RuntimeEnabledFeatures::setFeaturePolicyEnabled(enable);
}

=======
>>>>>>> miniblink49
void WebRuntimeFeatures::enableFileSystem(bool enable)
{
    RuntimeEnabledFeatures::setFileSystemEnabled(enable);
}

<<<<<<< HEAD
void WebRuntimeFeatures::enableGamepadExtensions(bool enable)
{
    RuntimeEnabledFeatures::setGamepadExtensionsEnabled(enable);
}

void WebRuntimeFeatures::enableGenericSensor(bool enable)
{
    RuntimeEnabledFeatures::setSensorEnabled(enable);
}

void WebRuntimeFeatures::enableHeapCompaction(bool enable)
{
    RuntimeEnabledFeatures::setHeapCompactionEnabled(enable);
}

void WebRuntimeFeatures::enableInputMultipleFieldsUI(bool enable)
{
    RuntimeEnabledFeatures::setInputMultipleFieldsUIEnabled(enable);
}

void WebRuntimeFeatures::enableLazyParseCSS(bool enable)
{
    RuntimeEnabledFeatures::setLazyParseCSSEnabled(enable);
=======
void WebRuntimeFeatures::enableImageColorProfiles(bool enable)
{
    RuntimeEnabledFeatures::setImageColorProfilesEnabled(enable);
}

void WebRuntimeFeatures::enableMediaPlayer(bool enable)
{
    RuntimeEnabledFeatures::setMediaEnabled(enable);
>>>>>>> miniblink49
}

void WebRuntimeFeatures::enableMediaCapture(bool enable)
{
    RuntimeEnabledFeatures::setMediaCaptureEnabled(enable);
}

<<<<<<< HEAD
void WebRuntimeFeatures::enableMediaDocumentDownloadButton(bool enable)
{
    RuntimeEnabledFeatures::setMediaDocumentDownloadButtonEnabled(enable);
}

void WebRuntimeFeatures::enableMediaSession(bool enable)
{
    RuntimeEnabledFeatures::setMediaSessionEnabled(enable);
=======
void WebRuntimeFeatures::enableMediaSource(bool enable)
{
    RuntimeEnabledFeatures::setMediaSourceEnabled(enable);
>>>>>>> miniblink49
}

void WebRuntimeFeatures::enableNotificationConstructor(bool enable)
{
    RuntimeEnabledFeatures::setNotificationConstructorEnabled(enable);
}

<<<<<<< HEAD
void WebRuntimeFeatures::enableNotificationContentImage(bool enable)
{
    RuntimeEnabledFeatures::setNotificationContentImageEnabled(enable);
}

=======
>>>>>>> miniblink49
void WebRuntimeFeatures::enableNotifications(bool enable)
{
    RuntimeEnabledFeatures::setNotificationsEnabled(enable);
}

void WebRuntimeFeatures::enableNavigatorContentUtils(bool enable)
{
    RuntimeEnabledFeatures::setNavigatorContentUtilsEnabled(enable);
}

void WebRuntimeFeatures::enableNetworkInformation(bool enable)
{
    RuntimeEnabledFeatures::setNetworkInformationEnabled(enable);
}

<<<<<<< HEAD
void WebRuntimeFeatures::enableOnDeviceChange(bool enable)
{
    RuntimeEnabledFeatures::setOnDeviceChangeEnabled(enable);
}

=======
>>>>>>> miniblink49
void WebRuntimeFeatures::enableOrientationEvent(bool enable)
{
    RuntimeEnabledFeatures::setOrientationEventEnabled(enable);
}

<<<<<<< HEAD
void WebRuntimeFeatures::enableOriginTrials(bool enable)
{
    RuntimeEnabledFeatures::setOriginTrialsEnabled(enable);
}

bool WebRuntimeFeatures::isOriginTrialsEnabled()
{
    return RuntimeEnabledFeatures::originTrialsEnabled();
}

=======
>>>>>>> miniblink49
void WebRuntimeFeatures::enablePagePopup(bool enable)
{
    RuntimeEnabledFeatures::setPagePopupEnabled(enable);
}

<<<<<<< HEAD
void WebRuntimeFeatures::enableMiddleClickAutoscroll(bool enable)
{
    RuntimeEnabledFeatures::setMiddleClickAutoscrollEnabled(enable);
}

void WebRuntimeFeatures::enableParseHTMLOnMainThread(bool enable)
{
    RuntimeEnabledFeatures::setParseHTMLOnMainThreadEnabled(enable);
}

void WebRuntimeFeatures::enablePassiveDocumentEventListeners(bool enable)
{
    RuntimeEnabledFeatures::setPassiveDocumentEventListenersEnabled(enable);
}

void WebRuntimeFeatures::enablePaymentRequest(bool enable)
{
    RuntimeEnabledFeatures::setPaymentRequestEnabled(enable);
}

=======
>>>>>>> miniblink49
void WebRuntimeFeatures::enablePermissionsAPI(bool enable)
{
    RuntimeEnabledFeatures::setPermissionsEnabled(enable);
}

<<<<<<< HEAD
void WebRuntimeFeatures::enablePointerEvent(bool enable)
{
    RuntimeEnabledFeatures::setPointerEventEnabled(enable);
=======
void WebRuntimeFeatures::enableRequestAutocomplete(bool enable)
{
    RuntimeEnabledFeatures::setRequestAutocompleteEnabled(enable);
}

void WebRuntimeFeatures::enableScreenOrientation(bool enable)
{
    RuntimeEnabledFeatures::setScreenOrientationEnabled(enable);
>>>>>>> miniblink49
}

void WebRuntimeFeatures::enableScriptedSpeech(bool enable)
{
    RuntimeEnabledFeatures::setScriptedSpeechEnabled(enable);
}

<<<<<<< HEAD
void WebRuntimeFeatures::enableSlimmingPaintV2(bool enable)
{
    RuntimeEnabledFeatures::setSlimmingPaintV2Enabled(enable);
}

void WebRuntimeFeatures::enableSlimmingPaintInvalidation(bool enable)
{
    RuntimeEnabledFeatures::setSlimmingPaintInvalidationEnabled(enable);
}

void WebRuntimeFeatures::enableSpeculativeLaunchServiceWorker(bool enable)
{
    RuntimeEnabledFeatures::setSpeculativeLaunchServiceWorkerEnabled(enable);
}

void WebRuntimeFeatures::enableTouchEventFeatureDetection(bool enable)
{
    RuntimeEnabledFeatures::setTouchEventFeatureDetectionEnabled(enable);
=======
void WebRuntimeFeatures::enableSlimmingPaint(bool enable)
{
    RuntimeEnabledFeatures::setSlimmingPaintEnabled(enable);
}

void WebRuntimeFeatures::enableTouch(bool enable)
{
    RuntimeEnabledFeatures::setTouchEnabled(enable);
}

void WebRuntimeFeatures::enableTouchIconLoading(bool enable)
{
    RuntimeEnabledFeatures::setTouchIconLoadingEnabled(enable);
}

void WebRuntimeFeatures::enableWebAudio(bool enable)
{
    RuntimeEnabledFeatures::setWebAudioEnabled(enable);
>>>>>>> miniblink49
}

void WebRuntimeFeatures::enableWebGLDraftExtensions(bool enable)
{
    RuntimeEnabledFeatures::setWebGLDraftExtensionsEnabled(enable);
}

void WebRuntimeFeatures::enableWebGLImageChromium(bool enable)
{
    RuntimeEnabledFeatures::setWebGLImageChromiumEnabled(enable);
}

void WebRuntimeFeatures::enableXSLT(bool enable)
{
    RuntimeEnabledFeatures::setXSLTEnabled(enable);
}

void WebRuntimeFeatures::enableOverlayScrollbars(bool enable)
{
    RuntimeEnabledFeatures::setOverlayScrollbarsEnabled(enable);
}

<<<<<<< HEAD
void WebRuntimeFeatures::forceOverlayFullscreenVideo(bool enable)
{
    RuntimeEnabledFeatures::setForceOverlayFullscreenVideoEnabled(enable);
}

void WebRuntimeFeatures::enableSharedArrayBuffer(bool enable)
{
    RuntimeEnabledFeatures::setSharedArrayBufferEnabled(enable);
=======
void WebRuntimeFeatures::enableOverlayFullscreenVideo(bool enable)
{
    RuntimeEnabledFeatures::setOverlayFullscreenVideoEnabled(enable);
>>>>>>> miniblink49
}

void WebRuntimeFeatures::enableSharedWorker(bool enable)
{
    RuntimeEnabledFeatures::setSharedWorkerEnabled(enable);
}

void WebRuntimeFeatures::enablePreciseMemoryInfo(bool enable)
{
    RuntimeEnabledFeatures::setPreciseMemoryInfoEnabled(enable);
}

void WebRuntimeFeatures::enableCredentialManagerAPI(bool enable)
{
    RuntimeEnabledFeatures::setCredentialManagerEnabled(enable);
}

<<<<<<< HEAD
=======
void WebRuntimeFeatures::enableTextBlobs(bool enable)
{
    RuntimeEnabledFeatures::setTextBlobEnabled(enable);
}

void WebRuntimeFeatures::enableCSSViewport(bool enable)
{
    RuntimeEnabledFeatures::setCSSViewportEnabled(enable);
}

>>>>>>> miniblink49
void WebRuntimeFeatures::enableV8IdleTasks(bool enable)
{
    RuntimeEnabledFeatures::setV8IdleTasksEnabled(enable);
}

<<<<<<< HEAD
=======
void WebRuntimeFeatures::enableSVG1DOM(bool enable)
{
    RuntimeEnabledFeatures::setSVG1DOMEnabled(enable);
}

>>>>>>> miniblink49
void WebRuntimeFeatures::enableReducedReferrerGranularity(bool enable)
{
    RuntimeEnabledFeatures::setReducedReferrerGranularityEnabled(enable);
}

void WebRuntimeFeatures::enablePushMessaging(bool enable)
{
    RuntimeEnabledFeatures::setPushMessagingEnabled(enable);
}

<<<<<<< HEAD
=======
void WebRuntimeFeatures::enablePushMessagingData(bool enable)
{
    RuntimeEnabledFeatures::setPushMessagingDataEnabled(enable);
}

void WebRuntimeFeatures::enableStaleWhileRevalidateCacheControl(bool enable)
{
    RuntimeEnabledFeatures::setStaleWhileRevalidateCacheControlEnabled(enable);
}

void WebRuntimeFeatures::enableUnsafeES3APIs(bool enable)
{
    RuntimeEnabledFeatures::setUnsafeES3APIsEnabled(enable);
}

>>>>>>> miniblink49
void WebRuntimeFeatures::enableWebVR(bool enable)
{
    RuntimeEnabledFeatures::setWebVREnabled(enable);
}

<<<<<<< HEAD
void WebRuntimeFeatures::enablePresentationAPI(bool enable)
{
    RuntimeEnabledFeatures::setPresentationEnabled(enable);
}

void WebRuntimeFeatures::enableWebFontsInterventionV2With2G(bool enable)
{
    RuntimeEnabledFeatures::setWebFontsInterventionV2With2GEnabled(enable);
}

void WebRuntimeFeatures::enableWebFontsInterventionV2With3G(bool enable)
{
    RuntimeEnabledFeatures::setWebFontsInterventionV2With3GEnabled(enable);
}

void WebRuntimeFeatures::enableWebFontsInterventionV2WithSlow2G(bool enable)
{
    RuntimeEnabledFeatures::setWebFontsInterventionV2WithSlow2GEnabled(enable);
}

void WebRuntimeFeatures::enableWebFontsInterventionTrigger(bool enable)
{
    RuntimeEnabledFeatures::setWebFontsInterventionTriggerEnabled(enable);
}

void WebRuntimeFeatures::enableRenderingPipelineThrottling(bool enable)
{
    RuntimeEnabledFeatures::setRenderingPipelineThrottlingEnabled(enable);
}

void WebRuntimeFeatures::enableExpensiveBackgroundTimerThrottling(bool enable)
{
    RuntimeEnabledFeatures::setExpensiveBackgroundTimerThrottlingEnabled(enable);
}

void WebRuntimeFeatures::enableRootLayerScrolling(bool enable)
{
    RuntimeEnabledFeatures::setRootLayerScrollingEnabled(enable);
}

void WebRuntimeFeatures::enableScrollAnchoring(bool enable)
{
    RuntimeEnabledFeatures::setScrollAnchoringEnabled(enable);
}

void WebRuntimeFeatures::enableServiceWorkerNavigationPreload(bool enable)
{
    RuntimeEnabledFeatures::setServiceWorkerNavigationPreloadEnabled(enable);
}

void WebRuntimeFeatures::enableAutoplayMutedVideos(bool enable)
{
    RuntimeEnabledFeatures::setAutoplayMutedVideosEnabled(enable);
}

void WebRuntimeFeatures::enableTimerThrottlingForBackgroundTabs(bool enable)
{
    RuntimeEnabledFeatures::setTimerThrottlingForBackgroundTabsEnabled(enable);
}

void WebRuntimeFeatures::enableTimerThrottlingForHiddenFrames(bool enable)
{
    RuntimeEnabledFeatures::setTimerThrottlingForHiddenFramesEnabled(enable);
}

void WebRuntimeFeatures::enableSendBeaconThrowForBlobWithNonSimpleType(
    bool enable)
{
    RuntimeEnabledFeatures::setSendBeaconThrowForBlobWithNonSimpleTypeEnabled(
        enable);
}

void WebRuntimeFeatures::enableBackgroundVideoTrackOptimization(bool enable)
{
    RuntimeEnabledFeatures::setBackgroundVideoTrackOptimizationEnabled(enable);
}

void WebRuntimeFeatures::enableRemotePlaybackAPI(bool enable)
{
    RuntimeEnabledFeatures::setRemotePlaybackEnabled(enable);
}

void WebRuntimeFeatures::enableVideoFullscreenOrientationLock(bool enable)
{
    RuntimeEnabledFeatures::setVideoFullscreenOrientationLockEnabled(enable);
}

=======
>>>>>>> miniblink49
} // namespace blink
