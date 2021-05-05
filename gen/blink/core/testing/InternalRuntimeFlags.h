// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef InternalRuntimeFlags_h
#define InternalRuntimeFlags_h

#include "bindings/core/v8/ScriptWrappable.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/heap/Handle.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RefCounted.h"
#include "wtf/RefPtr.h"

namespace blink {

class InternalRuntimeFlags : public GarbageCollected<InternalRuntimeFlags>,
                             public ScriptWrappable {
    DEFINE_WRAPPERTYPEINFO();

public:
    static InternalRuntimeFlags* create()
    {
        return new InternalRuntimeFlags;
    }

    // These are reset between layout tests from Internals::resetToConsistentState
    // using RuntimeEnabledFeatures::Backup.
    void setAccelerated2dCanvasEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::setAccelerated2dCanvasEnabled(isEnabled);
    }
    void setCompositeOpaqueFixedPositionEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::setCompositeOpaqueFixedPositionEnabled(isEnabled);
    }
    void setCompositeOpaqueScrollersEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::setCompositeOpaqueScrollersEnabled(isEnabled);
    }
    void setCSSGridLayoutEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::setCSSGridLayoutEnabled(isEnabled);
    }
    void setFramebustingNeedsSameOriginOrUserGestureEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::setFramebustingNeedsSameOriginOrUserGestureEnabled(isEnabled);
    }
    void setFullscreenUnprefixedEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::setFullscreenUnprefixedEnabled(isEnabled);
    }
    void setPaintUnderInvalidationCheckingEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::setPaintUnderInvalidationCheckingEnabled(isEnabled);
    }
    void setPreferredImageRasterBoundsEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::setPreferredImageRasterBoundsEnabled(isEnabled);
    }
    void setScrollAnchoringEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::setScrollAnchoringEnabled(isEnabled);
    }
    void setAutoplayMutedVideosEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::setAutoplayMutedVideosEnabled(isEnabled);
    }

    bool accelerated2dCanvasEnabled()
    {
        return RuntimeEnabledFeatures::accelerated2dCanvasEnabled();
    }
    bool audioOutputDevicesEnabled()
    {
        return RuntimeEnabledFeatures::audioOutputDevicesEnabled();
    }
    bool audioVideoTracksEnabled()
    {
        return RuntimeEnabledFeatures::audioVideoTracksEnabled();
    }
    bool audioWorkletEnabled()
    {
        return RuntimeEnabledFeatures::audioWorkletEnabled();
    }
    bool auxclickEnabled()
    {
        return RuntimeEnabledFeatures::auxclickEnabled();
    }
    bool coalescedEventsEnabled()
    {
        return RuntimeEnabledFeatures::coalescedEventsEnabled();
    }
    bool backgroundSyncEnabled()
    {
        return RuntimeEnabledFeatures::backgroundSyncEnabled();
    }
    bool backspaceDefaultHandlerEnabled()
    {
        return RuntimeEnabledFeatures::backspaceDefaultHandlerEnabled();
    }
    bool broadcastChannelEnabled()
    {
        return RuntimeEnabledFeatures::broadcastChannelEnabled();
    }
    bool budgetEnabled()
    {
        return RuntimeEnabledFeatures::budgetEnabled();
    }
    bool canvas2dFixedRenderingModeEnabled()
    {
        return RuntimeEnabledFeatures::canvas2dFixedRenderingModeEnabled();
    }
    bool enableCanvas2dDynamicRenderingModeSwitchingEnabled()
    {
        return RuntimeEnabledFeatures::enableCanvas2dDynamicRenderingModeSwitchingEnabled();
    }
    bool canMakePaymentEnabled()
    {
        return RuntimeEnabledFeatures::canMakePaymentEnabled();
    }
    bool canvas2dImageChromiumEnabled()
    {
        return RuntimeEnabledFeatures::canvas2dImageChromiumEnabled();
    }
    bool clientHintsEnabled()
    {
        return RuntimeEnabledFeatures::clientHintsEnabled();
    }
    bool compositeOpaqueFixedPositionEnabled()
    {
        return RuntimeEnabledFeatures::compositeOpaqueFixedPositionEnabled();
    }
    bool compositeOpaqueScrollersEnabled()
    {
        return RuntimeEnabledFeatures::compositeOpaqueScrollersEnabled();
    }
    bool colorCorrectRenderingEnabled()
    {
        return RuntimeEnabledFeatures::colorCorrectRenderingEnabled();
    }
    bool colorCorrectRenderingDefaultModeEnabled()
    {
        return RuntimeEnabledFeatures::colorCorrectRenderingDefaultModeEnabled();
    }
    bool compositedSelectionUpdateEnabled()
    {
        return RuntimeEnabledFeatures::compositedSelectionUpdateEnabled();
    }
    bool compositorWorkerEnabled()
    {
        return RuntimeEnabledFeatures::compositorWorkerEnabled();
    }
    bool contextMenuEnabled()
    {
        return RuntimeEnabledFeatures::contextMenuEnabled();
    }
    bool corsRFC1918Enabled()
    {
        return RuntimeEnabledFeatures::corsRFC1918Enabled();
    }
    bool credentialManagerEnabled()
    {
        return RuntimeEnabledFeatures::credentialManagerEnabled();
    }
    bool css3TextEnabled()
    {
        return RuntimeEnabledFeatures::css3TextEnabled();
    }
    bool css3TextDecorationsEnabled()
    {
        return RuntimeEnabledFeatures::css3TextDecorationsEnabled();
    }
    bool cssApplyAtRulesEnabled()
    {
        return RuntimeEnabledFeatures::cssApplyAtRulesEnabled();
    }
    bool cssAdditiveAnimationsEnabled()
    {
        return RuntimeEnabledFeatures::cssAdditiveAnimationsEnabled();
    }
    bool cssBackdropFilterEnabled()
    {
        return RuntimeEnabledFeatures::cssBackdropFilterEnabled();
    }
    bool cssHexAlphaColorEnabled()
    {
        return RuntimeEnabledFeatures::cssHexAlphaColorEnabled();
    }
    bool cssContainmentEnabled()
    {
        return RuntimeEnabledFeatures::cssContainmentEnabled();
    }
    bool cssFontDisplayEnabled()
    {
        return RuntimeEnabledFeatures::cssFontDisplayEnabled();
    }
    bool cssFontSizeAdjustEnabled()
    {
        return RuntimeEnabledFeatures::cssFontSizeAdjustEnabled();
    }
    bool cssGridLayoutEnabled()
    {
        return RuntimeEnabledFeatures::cssGridLayoutEnabled();
    }
    bool cssDisplayContentsEnabled()
    {
        return RuntimeEnabledFeatures::cssDisplayContentsEnabled();
    }
    bool cssHyphensEnabled()
    {
        return RuntimeEnabledFeatures::cssHyphensEnabled();
    }
    bool cssInBodyDoesNotBlockPaintEnabled()
    {
        return RuntimeEnabledFeatures::cssInBodyDoesNotBlockPaintEnabled();
    }
    bool cssIndependentTransformPropertiesEnabled()
    {
        return RuntimeEnabledFeatures::cssIndependentTransformPropertiesEnabled();
    }
    bool cssMaskSourceTypeEnabled()
    {
        return RuntimeEnabledFeatures::cssMaskSourceTypeEnabled();
    }
    bool cssomSmoothScrollEnabled()
    {
        return RuntimeEnabledFeatures::cssomSmoothScrollEnabled();
    }
    bool cssOffsetPositionAnchorEnabled()
    {
        return RuntimeEnabledFeatures::cssOffsetPositionAnchorEnabled();
    }
    bool cssOffsetRotateEnabled()
    {
        return RuntimeEnabledFeatures::cssOffsetRotateEnabled();
    }
    bool cssOffsetRotationEnabled()
    {
        return RuntimeEnabledFeatures::cssOffsetRotationEnabled();
    }
    bool cssPaintAPIEnabled()
    {
        return RuntimeEnabledFeatures::cssPaintAPIEnabled();
    }
    bool cssPaintAPIArgumentsEnabled()
    {
        return RuntimeEnabledFeatures::cssPaintAPIArgumentsEnabled();
    }
    bool cssSnapSizeEnabled()
    {
        return RuntimeEnabledFeatures::cssSnapSizeEnabled();
    }
    bool cssStickyPositionEnabled()
    {
        return RuntimeEnabledFeatures::cssStickyPositionEnabled();
    }
    bool cssTouchActionPanDirectionsEnabled()
    {
        return RuntimeEnabledFeatures::cssTouchActionPanDirectionsEnabled();
    }
    bool cssTouchActionPinchZoomEnabled()
    {
        return RuntimeEnabledFeatures::cssTouchActionPinchZoomEnabled();
    }
    bool cssTypedOMEnabled()
    {
        return RuntimeEnabledFeatures::cssTypedOMEnabled();
    }
    bool cssVariableFontsEnabled()
    {
        return RuntimeEnabledFeatures::cssVariableFontsEnabled();
    }
    bool cssVariables2Enabled()
    {
        return RuntimeEnabledFeatures::cssVariables2Enabled();
    }
    bool cssViewportEnabled()
    {
        return RuntimeEnabledFeatures::cssViewportEnabled();
    }
    bool cssScrollSnapPointsEnabled()
    {
        return RuntimeEnabledFeatures::cssScrollSnapPointsEnabled();
    }
    bool customElementsBuiltinEnabled()
    {
        return RuntimeEnabledFeatures::customElementsBuiltinEnabled();
    }
    bool customElementsV1Enabled()
    {
        return RuntimeEnabledFeatures::customElementsV1Enabled();
    }
    bool customSchemeHandlerEnabled()
    {
        return RuntimeEnabledFeatures::customSchemeHandlerEnabled();
    }
    bool databaseEnabled()
    {
        return RuntimeEnabledFeatures::databaseEnabled();
    }
    bool decodeToYUVEnabled()
    {
        return RuntimeEnabledFeatures::decodeToYUVEnabled();
    }
    bool desktopCaptureDisableLocalEchoControlEnabled()
    {
        return RuntimeEnabledFeatures::desktopCaptureDisableLocalEchoControlEnabled();
    }
    bool deviceLightEnabled()
    {
        return RuntimeEnabledFeatures::deviceLightEnabled();
    }
    bool displayList2dCanvasEnabled()
    {
        return RuntimeEnabledFeatures::displayList2dCanvasEnabled();
    }
    bool documentCookieEnabled()
    {
        return RuntimeEnabledFeatures::documentCookieEnabled();
    }
    bool documentDomainEnabled()
    {
        return RuntimeEnabledFeatures::documentDomainEnabled();
    }
    bool documentWriteEnabled()
    {
        return RuntimeEnabledFeatures::documentWriteEnabled();
    }
    bool documentWriteEvaluatorEnabled()
    {
        return RuntimeEnabledFeatures::documentWriteEvaluatorEnabled();
    }
    bool dOMConvenienceAPIEnabled()
    {
        return RuntimeEnabledFeatures::dOMConvenienceAPIEnabled();
    }
    bool durableStorageEnabled()
    {
        return RuntimeEnabledFeatures::durableStorageEnabled();
    }
    bool expensiveBackgroundTimerThrottlingEnabled()
    {
        return RuntimeEnabledFeatures::expensiveBackgroundTimerThrottlingEnabled();
    }
    bool fasterLocationReloadEnabled()
    {
        return RuntimeEnabledFeatures::fasterLocationReloadEnabled();
    }
    bool fontCacheScalingEnabled()
    {
        return RuntimeEnabledFeatures::fontCacheScalingEnabled();
    }
    bool forceDisplayList2dCanvasEnabled()
    {
        return RuntimeEnabledFeatures::forceDisplayList2dCanvasEnabled();
    }
    bool forceDisable2dCanvasCopyOnWriteEnabled()
    {
        return RuntimeEnabledFeatures::forceDisable2dCanvasCopyOnWriteEnabled();
    }
    bool embedderCSPEnforcementEnabled()
    {
        return RuntimeEnabledFeatures::embedderCSPEnforcementEnabled();
    }
    bool execCommandInJavaScriptEnabled()
    {
        return RuntimeEnabledFeatures::execCommandInJavaScriptEnabled();
    }
    bool computedAccessibilityInfoEnabled()
    {
        return RuntimeEnabledFeatures::computedAccessibilityInfoEnabled();
    }
    bool experimentalCanvasFeaturesEnabled()
    {
        return RuntimeEnabledFeatures::experimentalCanvasFeaturesEnabled();
    }
    bool experimentalContentSecurityPolicyFeaturesEnabled()
    {
        return RuntimeEnabledFeatures::experimentalContentSecurityPolicyFeaturesEnabled();
    }
    bool experimentalV8ExtrasEnabled()
    {
        return RuntimeEnabledFeatures::experimentalV8ExtrasEnabled();
    }
    bool fastMobileScrollingEnabled()
    {
        return RuntimeEnabledFeatures::fastMobileScrollingEnabled();
    }
    bool featurePolicyEnabled()
    {
        return RuntimeEnabledFeatures::featurePolicyEnabled();
    }
    bool fileAPIBlobCloseEnabled()
    {
        return RuntimeEnabledFeatures::fileAPIBlobCloseEnabled();
    }
    bool fileSystemEnabled()
    {
        return RuntimeEnabledFeatures::fileSystemEnabled();
    }
    bool foreignFetchEnabled()
    {
        return RuntimeEnabledFeatures::foreignFetchEnabled();
    }
    bool framebustingNeedsSameOriginOrUserGestureEnabled()
    {
        return RuntimeEnabledFeatures::framebustingNeedsSameOriginOrUserGestureEnabled();
    }
    bool fullscreenUnprefixedEnabled()
    {
        return RuntimeEnabledFeatures::fullscreenUnprefixedEnabled();
    }
    bool frameTimingSupportEnabled()
    {
        return RuntimeEnabledFeatures::frameTimingSupportEnabled();
    }
    bool gamepadExtensionsEnabled()
    {
        return RuntimeEnabledFeatures::gamepadExtensionsEnabled();
    }
    bool geometryInterfacesEnabled()
    {
        return RuntimeEnabledFeatures::geometryInterfacesEnabled();
    }
    bool getUserMediaEnabled()
    {
        return RuntimeEnabledFeatures::getUserMediaEnabled();
    }
    bool globalCacheStorageEnabled()
    {
        return RuntimeEnabledFeatures::globalCacheStorageEnabled();
    }
    bool heapCompactionEnabled()
    {
        return RuntimeEnabledFeatures::heapCompactionEnabled();
    }
    bool iDBObserverEnabled()
    {
        return RuntimeEnabledFeatures::iDBObserverEnabled();
    }
    bool idleTimeSpellCheckingEnabled()
    {
        return RuntimeEnabledFeatures::idleTimeSpellCheckingEnabled();
    }
    bool imageCaptureEnabled()
    {
        return RuntimeEnabledFeatures::imageCaptureEnabled();
    }
    bool imageOrientationEnabled()
    {
        return RuntimeEnabledFeatures::imageOrientationEnabled();
    }
    bool indexedDBExperimentalEnabled()
    {
        return RuntimeEnabledFeatures::indexedDBExperimentalEnabled();
    }
    bool inertTopControlsEnabled()
    {
        return RuntimeEnabledFeatures::inertTopControlsEnabled();
    }
    bool inputEventEnabled()
    {
        return RuntimeEnabledFeatures::inputEventEnabled();
    }
    bool inputModeAttributeEnabled()
    {
        return RuntimeEnabledFeatures::inputModeAttributeEnabled();
    }
    bool inputMultipleFieldsUIEnabled()
    {
        return RuntimeEnabledFeatures::inputMultipleFieldsUIEnabled();
    }
    bool installedAppEnabled()
    {
        return RuntimeEnabledFeatures::installedAppEnabled();
    }
    bool intersectionObserverEnabled()
    {
        return RuntimeEnabledFeatures::intersectionObserverEnabled();
    }
    bool langAttributeAwareFormControlUIEnabled()
    {
        return RuntimeEnabledFeatures::langAttributeAwareFormControlUIEnabled();
    }
    bool layoutNGEnabled()
    {
        return RuntimeEnabledFeatures::layoutNGEnabled();
    }
    bool layoutNGInlineEnabled()
    {
        return RuntimeEnabledFeatures::layoutNGInlineEnabled();
    }
    bool linkServiceWorkerEnabled()
    {
        return RuntimeEnabledFeatures::linkServiceWorkerEnabled();
    }
    bool longTaskObserverEnabled()
    {
        return RuntimeEnabledFeatures::longTaskObserverEnabled();
    }
    bool fractionalScrollOffsetsEnabled()
    {
        return RuntimeEnabledFeatures::fractionalScrollOffsetsEnabled();
    }
    bool loadingWithMojoEnabled()
    {
        return RuntimeEnabledFeatures::loadingWithMojoEnabled();
    }
    bool mediaCaptureEnabled()
    {
        return RuntimeEnabledFeatures::mediaCaptureEnabled();
    }
    bool mediaCaptureFromCanvasEnabled()
    {
        return RuntimeEnabledFeatures::mediaCaptureFromCanvasEnabled();
    }
    bool mediaCaptureFromVideoEnabled()
    {
        return RuntimeEnabledFeatures::mediaCaptureFromVideoEnabled();
    }
    bool mediaConstraintsEnabled()
    {
        return RuntimeEnabledFeatures::mediaConstraintsEnabled();
    }
    bool mediaDocumentDownloadButtonEnabled()
    {
        return RuntimeEnabledFeatures::mediaDocumentDownloadButtonEnabled();
    }
    bool mediaGetSettingsEnabled()
    {
        return RuntimeEnabledFeatures::mediaGetSettingsEnabled();
    }
    bool mediaSessionEnabled()
    {
        return RuntimeEnabledFeatures::mediaSessionEnabled();
    }
    bool mediaSourceExperimentalEnabled()
    {
        return RuntimeEnabledFeatures::mediaSourceExperimentalEnabled();
    }
    bool mediaSourceNewAbortAndDurationEnabled()
    {
        return RuntimeEnabledFeatures::mediaSourceNewAbortAndDurationEnabled();
    }
    bool mediaStreamSpeechEnabled()
    {
        return RuntimeEnabledFeatures::mediaStreamSpeechEnabled();
    }
    bool mediaQueryShapeEnabled()
    {
        return RuntimeEnabledFeatures::mediaQueryShapeEnabled();
    }
    bool mediaStreamTrackContentHintEnabled()
    {
        return RuntimeEnabledFeatures::mediaStreamTrackContentHintEnabled();
    }
    bool memoryInfoInWorkersEnabled()
    {
        return RuntimeEnabledFeatures::memoryInfoInWorkersEnabled();
    }
    bool middleClickAutoscrollEnabled()
    {
        return RuntimeEnabledFeatures::middleClickAutoscrollEnabled();
    }
    bool mobileLayoutThemeEnabled()
    {
        return RuntimeEnabledFeatures::mobileLayoutThemeEnabled();
    }
    bool moduleScriptsEnabled()
    {
        return RuntimeEnabledFeatures::moduleScriptsEnabled();
    }
    bool navigatorContentUtilsEnabled()
    {
        return RuntimeEnabledFeatures::navigatorContentUtilsEnabled();
    }
    bool webNFCEnabled()
    {
        return RuntimeEnabledFeatures::webNFCEnabled();
    }
    bool networkInformationEnabled()
    {
        return RuntimeEnabledFeatures::networkInformationEnabled();
    }
    bool netInfoDownlinkMaxEnabled()
    {
        return RuntimeEnabledFeatures::netInfoDownlinkMaxEnabled();
    }
    bool notificationConstructorEnabled()
    {
        return RuntimeEnabledFeatures::notificationConstructorEnabled();
    }
    bool notificationBadgeEnabled()
    {
        return RuntimeEnabledFeatures::notificationBadgeEnabled();
    }
    bool notificationContentImageEnabled()
    {
        return RuntimeEnabledFeatures::notificationContentImageEnabled();
    }
    bool notificationInlineRepliesEnabled()
    {
        return RuntimeEnabledFeatures::notificationInlineRepliesEnabled();
    }
    bool notificationsEnabled()
    {
        return RuntimeEnabledFeatures::notificationsEnabled();
    }
    bool onDeviceChangeEnabled()
    {
        return RuntimeEnabledFeatures::onDeviceChangeEnabled();
    }
    bool orientationEventEnabled()
    {
        return RuntimeEnabledFeatures::orientationEventEnabled();
    }
    bool originTrialsEnabled()
    {
        return RuntimeEnabledFeatures::originTrialsEnabled();
    }
    bool originTrialsSampleAPIEnabled()
    {
        return RuntimeEnabledFeatures::originTrialsSampleAPIEnabled();
    }
    bool forceOverlayFullscreenVideoEnabled()
    {
        return RuntimeEnabledFeatures::forceOverlayFullscreenVideoEnabled();
    }
    bool overlayScrollbarsEnabled()
    {
        return RuntimeEnabledFeatures::overlayScrollbarsEnabled();
    }
    bool pagePopupEnabled()
    {
        return RuntimeEnabledFeatures::pagePopupEnabled();
    }
    bool paintUnderInvalidationCheckingEnabled()
    {
        return RuntimeEnabledFeatures::paintUnderInvalidationCheckingEnabled();
    }
    bool passiveDocumentEventListenersEnabled()
    {
        return RuntimeEnabledFeatures::passiveDocumentEventListenersEnabled();
    }
    bool passPaintVisualRectToCompositorEnabled()
    {
        return RuntimeEnabledFeatures::passPaintVisualRectToCompositorEnabled();
    }
    bool paymentAppEnabled()
    {
        return RuntimeEnabledFeatures::paymentAppEnabled();
    }
    bool paymentDetailsErrorEnabled()
    {
        return RuntimeEnabledFeatures::paymentDetailsErrorEnabled();
    }
    bool paymentDetailsModifierDataEnabled()
    {
        return RuntimeEnabledFeatures::paymentDetailsModifierDataEnabled();
    }
    bool paymentRequestEnabled()
    {
        return RuntimeEnabledFeatures::paymentRequestEnabled();
    }
    bool paymentRequestBasicCardEnabled()
    {
        return RuntimeEnabledFeatures::paymentRequestBasicCardEnabled();
    }
    bool paymentRequestPayerNameEnabled()
    {
        return RuntimeEnabledFeatures::paymentRequestPayerNameEnabled();
    }
    bool performanceObserverEnabled()
    {
        return RuntimeEnabledFeatures::performanceObserverEnabled();
    }
    bool permissionDelegationEnabled()
    {
        return RuntimeEnabledFeatures::permissionDelegationEnabled();
    }
    bool permissionsEnabled()
    {
        return RuntimeEnabledFeatures::permissionsEnabled();
    }
    bool permissionsRequestRevokeEnabled()
    {
        return RuntimeEnabledFeatures::permissionsRequestRevokeEnabled();
    }
    bool pointerEventEnabled()
    {
        return RuntimeEnabledFeatures::pointerEventEnabled();
    }
    bool preciseMemoryInfoEnabled()
    {
        return RuntimeEnabledFeatures::preciseMemoryInfoEnabled();
    }
    bool preferredImageRasterBoundsEnabled()
    {
        return RuntimeEnabledFeatures::preferredImageRasterBoundsEnabled();
    }
    bool prefixedVideoFullscreenEnabled()
    {
        return RuntimeEnabledFeatures::prefixedVideoFullscreenEnabled();
    }
    bool presentationEnabled()
    {
        return RuntimeEnabledFeatures::presentationEnabled();
    }
    bool presentationReceiverEnabled()
    {
        return RuntimeEnabledFeatures::presentationReceiverEnabled();
    }
    bool pushMessagingEnabled()
    {
        return RuntimeEnabledFeatures::pushMessagingEnabled();
    }
    bool quotaPromiseEnabled()
    {
        return RuntimeEnabledFeatures::quotaPromiseEnabled();
    }
    bool reducedReferrerGranularityEnabled()
    {
        return RuntimeEnabledFeatures::reducedReferrerGranularityEnabled();
    }
    bool remotePlaybackEnabled()
    {
        return RuntimeEnabledFeatures::remotePlaybackEnabled();
    }
    bool renderingPipelineThrottlingEnabled()
    {
        return RuntimeEnabledFeatures::renderingPipelineThrottlingEnabled();
    }
    bool renderingPipelineThrottlingLoadingIframesEnabled()
    {
        return RuntimeEnabledFeatures::renderingPipelineThrottlingLoadingIframesEnabled();
    }
    bool renderUnicodeControlCharactersEnabled()
    {
        return RuntimeEnabledFeatures::renderUnicodeControlCharactersEnabled();
    }
    bool resizeObserverEnabled()
    {
        return RuntimeEnabledFeatures::resizeObserverEnabled();
    }
    bool rootLayerScrollingEnabled()
    {
        return RuntimeEnabledFeatures::rootLayerScrollingEnabled();
    }
    bool rTCPeerConnectionNewGetStatsEnabled()
    {
        return RuntimeEnabledFeatures::rTCPeerConnectionNewGetStatsEnabled();
    }
    bool scriptedSpeechEnabled()
    {
        return RuntimeEnabledFeatures::scriptedSpeechEnabled();
    }
    bool scrollAnchoringEnabled()
    {
        return RuntimeEnabledFeatures::scrollAnchoringEnabled();
    }
    bool scrollTopLeftInteropEnabled()
    {
        return RuntimeEnabledFeatures::scrollTopLeftInteropEnabled();
    }
    bool sensorEnabled()
    {
        return RuntimeEnabledFeatures::sensorEnabled();
    }
    bool serviceWorkerNavigationPreloadEnabled()
    {
        return RuntimeEnabledFeatures::serviceWorkerNavigationPreloadEnabled();
    }
    bool setRootScrollerEnabled()
    {
        return RuntimeEnabledFeatures::setRootScrollerEnabled();
    }
    bool shadowPiercingDescendantCombinatorEnabled()
    {
        return RuntimeEnabledFeatures::shadowPiercingDescendantCombinatorEnabled();
    }
    bool shapeDetectionEnabled()
    {
        return RuntimeEnabledFeatures::shapeDetectionEnabled();
    }
    bool sharedArrayBufferEnabled()
    {
        return RuntimeEnabledFeatures::sharedArrayBufferEnabled();
    }
    bool sharedWorkerEnabled()
    {
        return RuntimeEnabledFeatures::sharedWorkerEnabled();
    }
    bool slimmingPaintInvalidationEnabled()
    {
        return RuntimeEnabledFeatures::slimmingPaintInvalidationEnabled();
    }
    bool slimmingPaintV2Enabled()
    {
        return RuntimeEnabledFeatures::slimmingPaintV2Enabled();
    }
    bool slimmingPaintStrictCullRectClippingEnabled()
    {
        return RuntimeEnabledFeatures::slimmingPaintStrictCullRectClippingEnabled();
    }
    bool stableBlinkFeaturesEnabled()
    {
        return RuntimeEnabledFeatures::stableBlinkFeaturesEnabled();
    }
    bool stackedCSSPropertyAnimationsEnabled()
    {
        return RuntimeEnabledFeatures::stackedCSSPropertyAnimationsEnabled();
    }
    bool styleSharingEnabled()
    {
        return RuntimeEnabledFeatures::styleSharingEnabled();
    }
    bool speculativeLaunchServiceWorkerEnabled()
    {
        return RuntimeEnabledFeatures::speculativeLaunchServiceWorkerEnabled();
    }
    bool storageEstimateEnabled()
    {
        return RuntimeEnabledFeatures::storageEstimateEnabled();
    }
    bool suboriginsEnabled()
    {
        return RuntimeEnabledFeatures::suboriginsEnabled();
    }
    bool timerThrottlingForBackgroundTabsEnabled()
    {
        return RuntimeEnabledFeatures::timerThrottlingForBackgroundTabsEnabled();
    }
    bool timerThrottlingForHiddenFramesEnabled()
    {
        return RuntimeEnabledFeatures::timerThrottlingForHiddenFramesEnabled();
    }
    bool topNavWithUserActivationInSandboxEnabled()
    {
        return RuntimeEnabledFeatures::topNavWithUserActivationInSandboxEnabled();
    }
    bool touchEventFeatureDetectionEnabled()
    {
        return RuntimeEnabledFeatures::touchEventFeatureDetectionEnabled();
    }
    bool traceWrappablesEnabled()
    {
        return RuntimeEnabledFeatures::traceWrappablesEnabled();
    }
    bool trueColorRenderingEnabled()
    {
        return RuntimeEnabledFeatures::trueColorRenderingEnabled();
    }
    bool trustedEventsDefaultActionEnabled()
    {
        return RuntimeEnabledFeatures::trustedEventsDefaultActionEnabled();
    }
    bool userSelectAllEnabled()
    {
        return RuntimeEnabledFeatures::userSelectAllEnabled();
    }
    bool webAnimationsAPIEnabled()
    {
        return RuntimeEnabledFeatures::webAnimationsAPIEnabled();
    }
    bool webAnimationsSVGEnabled()
    {
        return RuntimeEnabledFeatures::webAnimationsSVGEnabled();
    }
    bool webAssemblySerializationEnabled()
    {
        return RuntimeEnabledFeatures::webAssemblySerializationEnabled();
    }
    bool webBluetoothEnabled()
    {
        return RuntimeEnabledFeatures::webBluetoothEnabled();
    }
    bool webGLDraftExtensionsEnabled()
    {
        return RuntimeEnabledFeatures::webGLDraftExtensionsEnabled();
    }
    bool webGLImageChromiumEnabled()
    {
        return RuntimeEnabledFeatures::webGLImageChromiumEnabled();
    }
    bool webUSBEnabled()
    {
        return RuntimeEnabledFeatures::webUSBEnabled();
    }
    bool webVREnabled()
    {
        return RuntimeEnabledFeatures::webVREnabled();
    }
    bool webVTTRegionsEnabled()
    {
        return RuntimeEnabledFeatures::webVTTRegionsEnabled();
    }
    bool v8BasedStructuredCloneEnabled()
    {
        return RuntimeEnabledFeatures::v8BasedStructuredCloneEnabled();
    }
    bool v8IdleTasksEnabled()
    {
        return RuntimeEnabledFeatures::v8IdleTasksEnabled();
    }
    bool videoFullscreenOrientationLockEnabled()
    {
        return RuntimeEnabledFeatures::videoFullscreenOrientationLockEnabled();
    }
    bool visibilityChangeOnUnloadEnabled()
    {
        return RuntimeEnabledFeatures::visibilityChangeOnUnloadEnabled();
    }
    bool xsltEnabled()
    {
        return RuntimeEnabledFeatures::xsltEnabled();
    }
    bool smilEnabled()
    {
        return RuntimeEnabledFeatures::smilEnabled();
    }
    bool scrollCustomizationEnabled()
    {
        return RuntimeEnabledFeatures::scrollCustomizationEnabled();
    }
    bool autoplayMutedVideosEnabled()
    {
        return RuntimeEnabledFeatures::autoplayMutedVideosEnabled();
    }
    bool visualViewportAPIEnabled()
    {
        return RuntimeEnabledFeatures::visualViewportAPIEnabled();
    }
    bool wakeLockEnabled()
    {
        return RuntimeEnabledFeatures::wakeLockEnabled();
    }
    bool webFontsCacheAwareTimeoutAdaptationEnabled()
    {
        return RuntimeEnabledFeatures::webFontsCacheAwareTimeoutAdaptationEnabled();
    }
    bool webFontsInterventionV2With2GEnabled()
    {
        return RuntimeEnabledFeatures::webFontsInterventionV2With2GEnabled();
    }
    bool webFontsInterventionV2With3GEnabled()
    {
        return RuntimeEnabledFeatures::webFontsInterventionV2With3GEnabled();
    }
    bool webFontsInterventionV2WithSlow2GEnabled()
    {
        return RuntimeEnabledFeatures::webFontsInterventionV2WithSlow2GEnabled();
    }
    bool webFontsInterventionTriggerEnabled()
    {
        return RuntimeEnabledFeatures::webFontsInterventionTriggerEnabled();
    }
    bool webShareEnabled()
    {
        return RuntimeEnabledFeatures::webShareEnabled();
    }
    bool workletEnabled()
    {
        return RuntimeEnabledFeatures::workletEnabled();
    }
    bool lazyParseCSSEnabled()
    {
        return RuntimeEnabledFeatures::lazyParseCSSEnabled();
    }
    bool parseHTMLOnMainThreadEnabled()
    {
        return RuntimeEnabledFeatures::parseHTMLOnMainThreadEnabled();
    }
    bool sendBeaconThrowForBlobWithNonSimpleTypeEnabled()
    {
        return RuntimeEnabledFeatures::sendBeaconThrowForBlobWithNonSimpleTypeEnabled();
    }
    bool performanceNavigationTiming2Enabled()
    {
        return RuntimeEnabledFeatures::performanceNavigationTiming2Enabled();
    }
    bool backgroundVideoTrackOptimizationEnabled()
    {
        return RuntimeEnabledFeatures::backgroundVideoTrackOptimizationEnabled();
    }
    bool performancePaintTimingEnabled()
    {
        return RuntimeEnabledFeatures::performancePaintTimingEnabled();
    }
    bool hideNonceContentAttributeEnabled()
    {
        return RuntimeEnabledFeatures::hideNonceContentAttributeEnabled();
    }
    bool unclosedFormControlIsInvalidEnabled()
    {
        return RuntimeEnabledFeatures::unclosedFormControlIsInvalidEnabled();
    }
    bool restrictCompleteURLCharacterSetEnabled()
    {
        return RuntimeEnabledFeatures::restrictCompleteURLCharacterSetEnabled();
    }

    DEFINE_INLINE_TRACE() { }

private:
    InternalRuntimeFlags() { }
};

} // namespace blink

#endif // InternalRuntimeFlags_h
