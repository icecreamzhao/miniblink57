// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "platform/RuntimeEnabledFeatures.h"

#include "wtf/Assertions.h"
#include "wtf/text/WTFString.h"

namespace blink {

RuntimeEnabledFeatures::Backup::Backup()
    : m_accelerated2dCanvas(RuntimeEnabledFeatures::accelerated2dCanvasEnabled())
    , m_audioOutputDevices(RuntimeEnabledFeatures::audioOutputDevicesEnabled())
    , m_audioVideoTracks(RuntimeEnabledFeatures::audioVideoTracksEnabled())
    , m_audioWorklet(RuntimeEnabledFeatures::audioWorkletEnabled())
    , m_auxclick(RuntimeEnabledFeatures::auxclickEnabled())
    , m_coalescedEvents(RuntimeEnabledFeatures::coalescedEventsEnabled())
    , m_backgroundSync(RuntimeEnabledFeatures::backgroundSyncEnabled())
    , m_backspaceDefaultHandler(RuntimeEnabledFeatures::backspaceDefaultHandlerEnabled())
    , m_broadcastChannel(RuntimeEnabledFeatures::broadcastChannelEnabled())
    , m_budget(RuntimeEnabledFeatures::budgetEnabled())
    , m_canvas2dFixedRenderingMode(RuntimeEnabledFeatures::canvas2dFixedRenderingModeEnabled())
    , m_enableCanvas2dDynamicRenderingModeSwitching(RuntimeEnabledFeatures::enableCanvas2dDynamicRenderingModeSwitchingEnabled())
    , m_canMakePayment(RuntimeEnabledFeatures::canMakePaymentEnabled())
    , m_canvas2dImageChromium(RuntimeEnabledFeatures::canvas2dImageChromiumEnabled())
    , m_clientHints(RuntimeEnabledFeatures::clientHintsEnabled())
    , m_compositeOpaqueFixedPosition(RuntimeEnabledFeatures::compositeOpaqueFixedPositionEnabled())
    , m_compositeOpaqueScrollers(RuntimeEnabledFeatures::compositeOpaqueScrollersEnabled())
    , m_colorCorrectRendering(RuntimeEnabledFeatures::colorCorrectRenderingEnabled())
    , m_colorCorrectRenderingDefaultMode(RuntimeEnabledFeatures::colorCorrectRenderingDefaultModeEnabled())
    , m_compositedSelectionUpdate(RuntimeEnabledFeatures::compositedSelectionUpdateEnabled())
    , m_compositorWorker(RuntimeEnabledFeatures::compositorWorkerEnabled())
    , m_contextMenu(RuntimeEnabledFeatures::contextMenuEnabled())
    , m_corsRFC1918(RuntimeEnabledFeatures::corsRFC1918Enabled())
    , m_credentialManager(RuntimeEnabledFeatures::credentialManagerEnabled())
    , m_css3Text(RuntimeEnabledFeatures::css3TextEnabled())
    , m_css3TextDecorations(RuntimeEnabledFeatures::css3TextDecorationsEnabled())
    , m_cssApplyAtRules(RuntimeEnabledFeatures::cssApplyAtRulesEnabled())
    , m_cssAdditiveAnimations(RuntimeEnabledFeatures::cssAdditiveAnimationsEnabled())
    , m_cssBackdropFilter(RuntimeEnabledFeatures::cssBackdropFilterEnabled())
    , m_cssHexAlphaColor(RuntimeEnabledFeatures::cssHexAlphaColorEnabled())
    , m_cssContainment(RuntimeEnabledFeatures::cssContainmentEnabled())
    , m_cssFontDisplay(RuntimeEnabledFeatures::cssFontDisplayEnabled())
    , m_cssFontSizeAdjust(RuntimeEnabledFeatures::cssFontSizeAdjustEnabled())
    , m_cssGridLayout(RuntimeEnabledFeatures::cssGridLayoutEnabled())
    , m_cssDisplayContents(RuntimeEnabledFeatures::cssDisplayContentsEnabled())
    , m_cssHyphens(RuntimeEnabledFeatures::cssHyphensEnabled())
    , m_cssInBodyDoesNotBlockPaint(RuntimeEnabledFeatures::cssInBodyDoesNotBlockPaintEnabled())
    , m_cssIndependentTransformProperties(RuntimeEnabledFeatures::cssIndependentTransformPropertiesEnabled())
    , m_cssMaskSourceType(RuntimeEnabledFeatures::cssMaskSourceTypeEnabled())
    , m_cssomSmoothScroll(RuntimeEnabledFeatures::cssomSmoothScrollEnabled())
    , m_cssOffsetPositionAnchor(RuntimeEnabledFeatures::cssOffsetPositionAnchorEnabled())
    , m_cssOffsetRotate(RuntimeEnabledFeatures::cssOffsetRotateEnabled())
    , m_cssOffsetRotation(RuntimeEnabledFeatures::cssOffsetRotationEnabled())
    , m_cssPaintAPI(RuntimeEnabledFeatures::cssPaintAPIEnabled())
    , m_cssPaintAPIArguments(RuntimeEnabledFeatures::cssPaintAPIArgumentsEnabled())
    , m_cssSnapSize(RuntimeEnabledFeatures::cssSnapSizeEnabled())
    , m_cssStickyPosition(RuntimeEnabledFeatures::cssStickyPositionEnabled())
    , m_cssTouchActionPanDirections(RuntimeEnabledFeatures::cssTouchActionPanDirectionsEnabled())
    , m_cssTouchActionPinchZoom(RuntimeEnabledFeatures::cssTouchActionPinchZoomEnabled())
    , m_cssTypedOM(RuntimeEnabledFeatures::cssTypedOMEnabled())
    , m_cssVariableFonts(RuntimeEnabledFeatures::cssVariableFontsEnabled())
    , m_cssVariables2(RuntimeEnabledFeatures::cssVariables2Enabled())
    , m_cssViewport(RuntimeEnabledFeatures::cssViewportEnabled())
    , m_cssScrollSnapPoints(RuntimeEnabledFeatures::cssScrollSnapPointsEnabled())
    , m_customElementsBuiltin(RuntimeEnabledFeatures::customElementsBuiltinEnabled())
    , m_customElementsV1(RuntimeEnabledFeatures::customElementsV1Enabled())
    , m_customSchemeHandler(RuntimeEnabledFeatures::customSchemeHandlerEnabled())
    , m_database(RuntimeEnabledFeatures::databaseEnabled())
    , m_decodeToYUV(RuntimeEnabledFeatures::decodeToYUVEnabled())
    , m_desktopCaptureDisableLocalEchoControl(RuntimeEnabledFeatures::desktopCaptureDisableLocalEchoControlEnabled())
    , m_deviceLight(RuntimeEnabledFeatures::deviceLightEnabled())
    , m_displayList2dCanvas(RuntimeEnabledFeatures::displayList2dCanvasEnabled())
    , m_documentCookie(RuntimeEnabledFeatures::documentCookieEnabled())
    , m_documentDomain(RuntimeEnabledFeatures::documentDomainEnabled())
    , m_documentWrite(RuntimeEnabledFeatures::documentWriteEnabled())
    , m_documentWriteEvaluator(RuntimeEnabledFeatures::documentWriteEvaluatorEnabled())
    , m_dOMConvenienceAPI(RuntimeEnabledFeatures::dOMConvenienceAPIEnabled())
    , m_durableStorage(RuntimeEnabledFeatures::durableStorageEnabled())
    , m_expensiveBackgroundTimerThrottling(RuntimeEnabledFeatures::expensiveBackgroundTimerThrottlingEnabled())
    , m_fasterLocationReload(RuntimeEnabledFeatures::fasterLocationReloadEnabled())
    , m_fontCacheScaling(RuntimeEnabledFeatures::fontCacheScalingEnabled())
    , m_forceDisplayList2dCanvas(RuntimeEnabledFeatures::forceDisplayList2dCanvasEnabled())
    , m_forceDisable2dCanvasCopyOnWrite(RuntimeEnabledFeatures::forceDisable2dCanvasCopyOnWriteEnabled())
    , m_embedderCSPEnforcement(RuntimeEnabledFeatures::embedderCSPEnforcementEnabled())
    , m_execCommandInJavaScript(RuntimeEnabledFeatures::execCommandInJavaScriptEnabled())
    , m_computedAccessibilityInfo(RuntimeEnabledFeatures::computedAccessibilityInfoEnabled())
    , m_experimentalCanvasFeatures(RuntimeEnabledFeatures::experimentalCanvasFeaturesEnabled())
    , m_experimentalContentSecurityPolicyFeatures(RuntimeEnabledFeatures::experimentalContentSecurityPolicyFeaturesEnabled())
    , m_experimentalV8Extras(RuntimeEnabledFeatures::experimentalV8ExtrasEnabled())
    , m_fastMobileScrolling(RuntimeEnabledFeatures::fastMobileScrollingEnabled())
    , m_featurePolicy(RuntimeEnabledFeatures::featurePolicyEnabled())
    , m_fileAPIBlobClose(RuntimeEnabledFeatures::fileAPIBlobCloseEnabled())
    , m_fileSystem(RuntimeEnabledFeatures::fileSystemEnabled())
    , m_foreignFetch(RuntimeEnabledFeatures::foreignFetchEnabled())
    , m_framebustingNeedsSameOriginOrUserGesture(RuntimeEnabledFeatures::framebustingNeedsSameOriginOrUserGestureEnabled())
    , m_fullscreenUnprefixed(RuntimeEnabledFeatures::fullscreenUnprefixedEnabled())
    , m_frameTimingSupport(RuntimeEnabledFeatures::frameTimingSupportEnabled())
    , m_gamepadExtensions(RuntimeEnabledFeatures::gamepadExtensionsEnabled())
    , m_geometryInterfaces(RuntimeEnabledFeatures::geometryInterfacesEnabled())
    , m_getUserMedia(RuntimeEnabledFeatures::getUserMediaEnabled())
    , m_globalCacheStorage(RuntimeEnabledFeatures::globalCacheStorageEnabled())
    , m_heapCompaction(RuntimeEnabledFeatures::heapCompactionEnabled())
    , m_iDBObserver(RuntimeEnabledFeatures::iDBObserverEnabled())
    , m_idleTimeSpellChecking(RuntimeEnabledFeatures::idleTimeSpellCheckingEnabled())
    , m_imageCapture(RuntimeEnabledFeatures::imageCaptureEnabled())
    , m_imageOrientation(RuntimeEnabledFeatures::imageOrientationEnabled())
    , m_indexedDBExperimental(RuntimeEnabledFeatures::indexedDBExperimentalEnabled())
    , m_inertTopControls(RuntimeEnabledFeatures::inertTopControlsEnabled())
    , m_inputEvent(RuntimeEnabledFeatures::inputEventEnabled())
    , m_inputModeAttribute(RuntimeEnabledFeatures::inputModeAttributeEnabled())
    , m_inputMultipleFieldsUI(RuntimeEnabledFeatures::inputMultipleFieldsUIEnabled())
    , m_installedApp(RuntimeEnabledFeatures::installedAppEnabled())
    , m_intersectionObserver(RuntimeEnabledFeatures::intersectionObserverEnabled())
    , m_langAttributeAwareFormControlUI(RuntimeEnabledFeatures::langAttributeAwareFormControlUIEnabled())
    , m_layoutNG(RuntimeEnabledFeatures::layoutNGEnabled())
    , m_layoutNGInline(RuntimeEnabledFeatures::layoutNGInlineEnabled())
    , m_linkServiceWorker(RuntimeEnabledFeatures::linkServiceWorkerEnabled())
    , m_longTaskObserver(RuntimeEnabledFeatures::longTaskObserverEnabled())
    , m_fractionalScrollOffsets(RuntimeEnabledFeatures::fractionalScrollOffsetsEnabled())
    , m_loadingWithMojo(RuntimeEnabledFeatures::loadingWithMojoEnabled())
    , m_mediaCapture(RuntimeEnabledFeatures::mediaCaptureEnabled())
    , m_mediaCaptureFromCanvas(RuntimeEnabledFeatures::mediaCaptureFromCanvasEnabled())
    , m_mediaCaptureFromVideo(RuntimeEnabledFeatures::mediaCaptureFromVideoEnabled())
    , m_mediaConstraints(RuntimeEnabledFeatures::mediaConstraintsEnabled())
    , m_mediaDocumentDownloadButton(RuntimeEnabledFeatures::mediaDocumentDownloadButtonEnabled())
    , m_mediaGetSettings(RuntimeEnabledFeatures::mediaGetSettingsEnabled())
    , m_mediaSession(RuntimeEnabledFeatures::mediaSessionEnabled())
    , m_mediaSourceExperimental(RuntimeEnabledFeatures::mediaSourceExperimentalEnabled())
    , m_mediaSourceNewAbortAndDuration(RuntimeEnabledFeatures::mediaSourceNewAbortAndDurationEnabled())
    , m_mediaStreamSpeech(RuntimeEnabledFeatures::mediaStreamSpeechEnabled())
    , m_mediaQueryShape(RuntimeEnabledFeatures::mediaQueryShapeEnabled())
    , m_mediaStreamTrackContentHint(RuntimeEnabledFeatures::mediaStreamTrackContentHintEnabled())
    , m_memoryInfoInWorkers(RuntimeEnabledFeatures::memoryInfoInWorkersEnabled())
    , m_middleClickAutoscroll(RuntimeEnabledFeatures::middleClickAutoscrollEnabled())
    , m_mobileLayoutTheme(RuntimeEnabledFeatures::mobileLayoutThemeEnabled())
    , m_moduleScripts(RuntimeEnabledFeatures::moduleScriptsEnabled())
    , m_navigatorContentUtils(RuntimeEnabledFeatures::navigatorContentUtilsEnabled())
    , m_webNFC(RuntimeEnabledFeatures::webNFCEnabled())
    , m_networkInformation(RuntimeEnabledFeatures::networkInformationEnabled())
    , m_netInfoDownlinkMax(RuntimeEnabledFeatures::netInfoDownlinkMaxEnabled())
    , m_notificationConstructor(RuntimeEnabledFeatures::notificationConstructorEnabled())
    , m_notificationBadge(RuntimeEnabledFeatures::notificationBadgeEnabled())
    , m_notificationContentImage(RuntimeEnabledFeatures::notificationContentImageEnabled())
    , m_notificationInlineReplies(RuntimeEnabledFeatures::notificationInlineRepliesEnabled())
    , m_notifications(RuntimeEnabledFeatures::notificationsEnabled())
    , m_onDeviceChange(RuntimeEnabledFeatures::onDeviceChangeEnabled())
    , m_orientationEvent(RuntimeEnabledFeatures::orientationEventEnabled())
    , m_originTrials(RuntimeEnabledFeatures::originTrialsEnabled())
    , m_originTrialsSampleAPI(RuntimeEnabledFeatures::originTrialsSampleAPIEnabled())
    , m_forceOverlayFullscreenVideo(RuntimeEnabledFeatures::forceOverlayFullscreenVideoEnabled())
    , m_overlayScrollbars(RuntimeEnabledFeatures::overlayScrollbarsEnabled())
    , m_pagePopup(RuntimeEnabledFeatures::pagePopupEnabled())
    , m_paintUnderInvalidationChecking(RuntimeEnabledFeatures::paintUnderInvalidationCheckingEnabled())
    , m_passiveDocumentEventListeners(RuntimeEnabledFeatures::passiveDocumentEventListenersEnabled())
    , m_passPaintVisualRectToCompositor(RuntimeEnabledFeatures::passPaintVisualRectToCompositorEnabled())
    , m_paymentApp(RuntimeEnabledFeatures::paymentAppEnabled())
    , m_paymentDetailsError(RuntimeEnabledFeatures::paymentDetailsErrorEnabled())
    , m_paymentDetailsModifierData(RuntimeEnabledFeatures::paymentDetailsModifierDataEnabled())
    , m_paymentRequest(RuntimeEnabledFeatures::paymentRequestEnabled())
    , m_paymentRequestBasicCard(RuntimeEnabledFeatures::paymentRequestBasicCardEnabled())
    , m_paymentRequestPayerName(RuntimeEnabledFeatures::paymentRequestPayerNameEnabled())
    , m_performanceObserver(RuntimeEnabledFeatures::performanceObserverEnabled())
    , m_permissionDelegation(RuntimeEnabledFeatures::permissionDelegationEnabled())
    , m_permissions(RuntimeEnabledFeatures::permissionsEnabled())
    , m_permissionsRequestRevoke(RuntimeEnabledFeatures::permissionsRequestRevokeEnabled())
    , m_pointerEvent(RuntimeEnabledFeatures::pointerEventEnabled())
    , m_preciseMemoryInfo(RuntimeEnabledFeatures::preciseMemoryInfoEnabled())
    , m_preferredImageRasterBounds(RuntimeEnabledFeatures::preferredImageRasterBoundsEnabled())
    , m_prefixedVideoFullscreen(RuntimeEnabledFeatures::prefixedVideoFullscreenEnabled())
    , m_presentation(RuntimeEnabledFeatures::presentationEnabled())
    , m_presentationReceiver(RuntimeEnabledFeatures::presentationReceiverEnabled())
    , m_pushMessaging(RuntimeEnabledFeatures::pushMessagingEnabled())
    , m_quotaPromise(RuntimeEnabledFeatures::quotaPromiseEnabled())
    , m_reducedReferrerGranularity(RuntimeEnabledFeatures::reducedReferrerGranularityEnabled())
    , m_remotePlayback(RuntimeEnabledFeatures::remotePlaybackEnabled())
    , m_renderingPipelineThrottling(RuntimeEnabledFeatures::renderingPipelineThrottlingEnabled())
    , m_renderingPipelineThrottlingLoadingIframes(RuntimeEnabledFeatures::renderingPipelineThrottlingLoadingIframesEnabled())
    , m_renderUnicodeControlCharacters(RuntimeEnabledFeatures::renderUnicodeControlCharactersEnabled())
    , m_resizeObserver(RuntimeEnabledFeatures::resizeObserverEnabled())
    , m_rootLayerScrolling(RuntimeEnabledFeatures::rootLayerScrollingEnabled())
    , m_rTCPeerConnectionNewGetStats(RuntimeEnabledFeatures::rTCPeerConnectionNewGetStatsEnabled())
    , m_scriptedSpeech(RuntimeEnabledFeatures::scriptedSpeechEnabled())
    , m_scrollAnchoring(RuntimeEnabledFeatures::scrollAnchoringEnabled())
    , m_scrollTopLeftInterop(RuntimeEnabledFeatures::scrollTopLeftInteropEnabled())
    , m_sensor(RuntimeEnabledFeatures::sensorEnabled())
    , m_serviceWorkerNavigationPreload(RuntimeEnabledFeatures::serviceWorkerNavigationPreloadEnabled())
    , m_setRootScroller(RuntimeEnabledFeatures::setRootScrollerEnabled())
    , m_shadowPiercingDescendantCombinator(RuntimeEnabledFeatures::shadowPiercingDescendantCombinatorEnabled())
    , m_shapeDetection(RuntimeEnabledFeatures::shapeDetectionEnabled())
    , m_sharedArrayBuffer(RuntimeEnabledFeatures::sharedArrayBufferEnabled())
    , m_sharedWorker(RuntimeEnabledFeatures::sharedWorkerEnabled())
    , m_slimmingPaintInvalidation(RuntimeEnabledFeatures::slimmingPaintInvalidationEnabled())
    , m_slimmingPaintV2(RuntimeEnabledFeatures::slimmingPaintV2Enabled())
    , m_slimmingPaintStrictCullRectClipping(RuntimeEnabledFeatures::slimmingPaintStrictCullRectClippingEnabled())
    , m_stableBlinkFeatures(RuntimeEnabledFeatures::stableBlinkFeaturesEnabled())
    , m_stackedCSSPropertyAnimations(RuntimeEnabledFeatures::stackedCSSPropertyAnimationsEnabled())
    , m_styleSharing(RuntimeEnabledFeatures::styleSharingEnabled())
    , m_speculativeLaunchServiceWorker(RuntimeEnabledFeatures::speculativeLaunchServiceWorkerEnabled())
    , m_storageEstimate(RuntimeEnabledFeatures::storageEstimateEnabled())
    , m_suborigins(RuntimeEnabledFeatures::suboriginsEnabled())
    , m_timerThrottlingForBackgroundTabs(RuntimeEnabledFeatures::timerThrottlingForBackgroundTabsEnabled())
    , m_timerThrottlingForHiddenFrames(RuntimeEnabledFeatures::timerThrottlingForHiddenFramesEnabled())
    , m_topNavWithUserActivationInSandbox(RuntimeEnabledFeatures::topNavWithUserActivationInSandboxEnabled())
    , m_touchEventFeatureDetection(RuntimeEnabledFeatures::touchEventFeatureDetectionEnabled())
    , m_traceWrappables(RuntimeEnabledFeatures::traceWrappablesEnabled())
    , m_trueColorRendering(RuntimeEnabledFeatures::trueColorRenderingEnabled())
    , m_trustedEventsDefaultAction(RuntimeEnabledFeatures::trustedEventsDefaultActionEnabled())
    , m_userSelectAll(RuntimeEnabledFeatures::userSelectAllEnabled())
    , m_webAnimationsAPI(RuntimeEnabledFeatures::webAnimationsAPIEnabled())
    , m_webAnimationsSVG(RuntimeEnabledFeatures::webAnimationsSVGEnabled())
    , m_webAssemblySerialization(RuntimeEnabledFeatures::webAssemblySerializationEnabled())
    , m_webBluetooth(RuntimeEnabledFeatures::webBluetoothEnabled())
    , m_webGLDraftExtensions(RuntimeEnabledFeatures::webGLDraftExtensionsEnabled())
    , m_webGLImageChromium(RuntimeEnabledFeatures::webGLImageChromiumEnabled())
    , m_webUSB(RuntimeEnabledFeatures::webUSBEnabled())
    , m_webVR(RuntimeEnabledFeatures::webVREnabled())
    , m_webVTTRegions(RuntimeEnabledFeatures::webVTTRegionsEnabled())
    , m_v8BasedStructuredClone(RuntimeEnabledFeatures::v8BasedStructuredCloneEnabled())
    , m_v8IdleTasks(RuntimeEnabledFeatures::v8IdleTasksEnabled())
    , m_videoFullscreenOrientationLock(RuntimeEnabledFeatures::videoFullscreenOrientationLockEnabled())
    , m_visibilityChangeOnUnload(RuntimeEnabledFeatures::visibilityChangeOnUnloadEnabled())
    , m_xslt(RuntimeEnabledFeatures::xsltEnabled())
    , m_smil(RuntimeEnabledFeatures::smilEnabled())
    , m_scrollCustomization(RuntimeEnabledFeatures::scrollCustomizationEnabled())
    , m_autoplayMutedVideos(RuntimeEnabledFeatures::autoplayMutedVideosEnabled())
    , m_visualViewportAPI(RuntimeEnabledFeatures::visualViewportAPIEnabled())
    , m_wakeLock(RuntimeEnabledFeatures::wakeLockEnabled())
    , m_webFontsCacheAwareTimeoutAdaptation(RuntimeEnabledFeatures::webFontsCacheAwareTimeoutAdaptationEnabled())
    , m_webFontsInterventionV2With2G(RuntimeEnabledFeatures::webFontsInterventionV2With2GEnabled())
    , m_webFontsInterventionV2With3G(RuntimeEnabledFeatures::webFontsInterventionV2With3GEnabled())
    , m_webFontsInterventionV2WithSlow2G(RuntimeEnabledFeatures::webFontsInterventionV2WithSlow2GEnabled())
    , m_webFontsInterventionTrigger(RuntimeEnabledFeatures::webFontsInterventionTriggerEnabled())
    , m_webShare(RuntimeEnabledFeatures::webShareEnabled())
    , m_worklet(RuntimeEnabledFeatures::workletEnabled())
    , m_lazyParseCSS(RuntimeEnabledFeatures::lazyParseCSSEnabled())
    , m_parseHTMLOnMainThread(RuntimeEnabledFeatures::parseHTMLOnMainThreadEnabled())
    , m_sendBeaconThrowForBlobWithNonSimpleType(RuntimeEnabledFeatures::sendBeaconThrowForBlobWithNonSimpleTypeEnabled())
    , m_performanceNavigationTiming2(RuntimeEnabledFeatures::performanceNavigationTiming2Enabled())
    , m_backgroundVideoTrackOptimization(RuntimeEnabledFeatures::backgroundVideoTrackOptimizationEnabled())
    , m_performancePaintTiming(RuntimeEnabledFeatures::performancePaintTimingEnabled())
    , m_hideNonceContentAttribute(RuntimeEnabledFeatures::hideNonceContentAttributeEnabled())
    , m_unclosedFormControlIsInvalid(RuntimeEnabledFeatures::unclosedFormControlIsInvalidEnabled())
    , m_restrictCompleteURLCharacterSet(RuntimeEnabledFeatures::restrictCompleteURLCharacterSetEnabled())
{
}

void RuntimeEnabledFeatures::Backup::restore()
{
    RuntimeEnabledFeatures::setAccelerated2dCanvasEnabled(m_accelerated2dCanvas);
    RuntimeEnabledFeatures::setAudioOutputDevicesEnabled(m_audioOutputDevices);
    RuntimeEnabledFeatures::setAudioVideoTracksEnabled(m_audioVideoTracks);
    RuntimeEnabledFeatures::setAudioWorkletEnabled(m_audioWorklet);
    RuntimeEnabledFeatures::setAuxclickEnabled(m_auxclick);
    RuntimeEnabledFeatures::setCoalescedEventsEnabled(m_coalescedEvents);
    RuntimeEnabledFeatures::setBackgroundSyncEnabled(m_backgroundSync);
    RuntimeEnabledFeatures::setBackspaceDefaultHandlerEnabled(m_backspaceDefaultHandler);
    RuntimeEnabledFeatures::setBroadcastChannelEnabled(m_broadcastChannel);
    RuntimeEnabledFeatures::setBudgetEnabled(m_budget);
    RuntimeEnabledFeatures::setCanvas2dFixedRenderingModeEnabled(m_canvas2dFixedRenderingMode);
    RuntimeEnabledFeatures::setEnableCanvas2dDynamicRenderingModeSwitchingEnabled(m_enableCanvas2dDynamicRenderingModeSwitching);
    RuntimeEnabledFeatures::setCanMakePaymentEnabled(m_canMakePayment);
    RuntimeEnabledFeatures::setCanvas2dImageChromiumEnabled(m_canvas2dImageChromium);
    RuntimeEnabledFeatures::setClientHintsEnabled(m_clientHints);
    RuntimeEnabledFeatures::setCompositeOpaqueFixedPositionEnabled(m_compositeOpaqueFixedPosition);
    RuntimeEnabledFeatures::setCompositeOpaqueScrollersEnabled(m_compositeOpaqueScrollers);
    RuntimeEnabledFeatures::setColorCorrectRenderingEnabled(m_colorCorrectRendering);
    RuntimeEnabledFeatures::setColorCorrectRenderingDefaultModeEnabled(m_colorCorrectRenderingDefaultMode);
    RuntimeEnabledFeatures::setCompositedSelectionUpdateEnabled(m_compositedSelectionUpdate);
    RuntimeEnabledFeatures::setCompositorWorkerEnabled(m_compositorWorker);
    RuntimeEnabledFeatures::setContextMenuEnabled(m_contextMenu);
    RuntimeEnabledFeatures::setCorsRFC1918Enabled(m_corsRFC1918);
    RuntimeEnabledFeatures::setCredentialManagerEnabled(m_credentialManager);
    RuntimeEnabledFeatures::setCSS3TextEnabled(m_css3Text);
    RuntimeEnabledFeatures::setCSS3TextDecorationsEnabled(m_css3TextDecorations);
    RuntimeEnabledFeatures::setCSSApplyAtRulesEnabled(m_cssApplyAtRules);
    RuntimeEnabledFeatures::setCSSAdditiveAnimationsEnabled(m_cssAdditiveAnimations);
    RuntimeEnabledFeatures::setCSSBackdropFilterEnabled(m_cssBackdropFilter);
    RuntimeEnabledFeatures::setCSSHexAlphaColorEnabled(m_cssHexAlphaColor);
    RuntimeEnabledFeatures::setCSSContainmentEnabled(m_cssContainment);
    RuntimeEnabledFeatures::setCSSFontDisplayEnabled(m_cssFontDisplay);
    RuntimeEnabledFeatures::setCSSFontSizeAdjustEnabled(m_cssFontSizeAdjust);
    RuntimeEnabledFeatures::setCSSGridLayoutEnabled(m_cssGridLayout);
    RuntimeEnabledFeatures::setCSSDisplayContentsEnabled(m_cssDisplayContents);
    RuntimeEnabledFeatures::setCSSHyphensEnabled(m_cssHyphens);
    RuntimeEnabledFeatures::setCSSInBodyDoesNotBlockPaintEnabled(m_cssInBodyDoesNotBlockPaint);
    RuntimeEnabledFeatures::setCSSIndependentTransformPropertiesEnabled(m_cssIndependentTransformProperties);
    RuntimeEnabledFeatures::setCSSMaskSourceTypeEnabled(m_cssMaskSourceType);
    RuntimeEnabledFeatures::setCSSOMSmoothScrollEnabled(m_cssomSmoothScroll);
    RuntimeEnabledFeatures::setCSSOffsetPositionAnchorEnabled(m_cssOffsetPositionAnchor);
    RuntimeEnabledFeatures::setCSSOffsetRotateEnabled(m_cssOffsetRotate);
    RuntimeEnabledFeatures::setCSSOffsetRotationEnabled(m_cssOffsetRotation);
    RuntimeEnabledFeatures::setCSSPaintAPIEnabled(m_cssPaintAPI);
    RuntimeEnabledFeatures::setCSSPaintAPIArgumentsEnabled(m_cssPaintAPIArguments);
    RuntimeEnabledFeatures::setCSSSnapSizeEnabled(m_cssSnapSize);
    RuntimeEnabledFeatures::setCSSStickyPositionEnabled(m_cssStickyPosition);
    RuntimeEnabledFeatures::setCSSTouchActionPanDirectionsEnabled(m_cssTouchActionPanDirections);
    RuntimeEnabledFeatures::setCSSTouchActionPinchZoomEnabled(m_cssTouchActionPinchZoom);
    RuntimeEnabledFeatures::setCSSTypedOMEnabled(m_cssTypedOM);
    RuntimeEnabledFeatures::setCSSVariableFontsEnabled(m_cssVariableFonts);
    RuntimeEnabledFeatures::setCSSVariables2Enabled(m_cssVariables2);
    RuntimeEnabledFeatures::setCSSViewportEnabled(m_cssViewport);
    RuntimeEnabledFeatures::setCSSScrollSnapPointsEnabled(m_cssScrollSnapPoints);
    RuntimeEnabledFeatures::setCustomElementsBuiltinEnabled(m_customElementsBuiltin);
    RuntimeEnabledFeatures::setCustomElementsV1Enabled(m_customElementsV1);
    RuntimeEnabledFeatures::setCustomSchemeHandlerEnabled(m_customSchemeHandler);
    RuntimeEnabledFeatures::setDatabaseEnabled(m_database);
    RuntimeEnabledFeatures::setDecodeToYUVEnabled(m_decodeToYUV);
    RuntimeEnabledFeatures::setDesktopCaptureDisableLocalEchoControlEnabled(m_desktopCaptureDisableLocalEchoControl);
    RuntimeEnabledFeatures::setDeviceLightEnabled(m_deviceLight);
    RuntimeEnabledFeatures::setDisplayList2dCanvasEnabled(m_displayList2dCanvas);
    RuntimeEnabledFeatures::setDocumentCookieEnabled(m_documentCookie);
    RuntimeEnabledFeatures::setDocumentDomainEnabled(m_documentDomain);
    RuntimeEnabledFeatures::setDocumentWriteEnabled(m_documentWrite);
    RuntimeEnabledFeatures::setDocumentWriteEvaluatorEnabled(m_documentWriteEvaluator);
    RuntimeEnabledFeatures::setDOMConvenienceAPIEnabled(m_dOMConvenienceAPI);
    RuntimeEnabledFeatures::setDurableStorageEnabled(m_durableStorage);
    RuntimeEnabledFeatures::setExpensiveBackgroundTimerThrottlingEnabled(m_expensiveBackgroundTimerThrottling);
    RuntimeEnabledFeatures::setFasterLocationReloadEnabled(m_fasterLocationReload);
    RuntimeEnabledFeatures::setFontCacheScalingEnabled(m_fontCacheScaling);
    RuntimeEnabledFeatures::setForceDisplayList2dCanvasEnabled(m_forceDisplayList2dCanvas);
    RuntimeEnabledFeatures::setForceDisable2dCanvasCopyOnWriteEnabled(m_forceDisable2dCanvasCopyOnWrite);
    RuntimeEnabledFeatures::setEmbedderCSPEnforcementEnabled(m_embedderCSPEnforcement);
    RuntimeEnabledFeatures::setExecCommandInJavaScriptEnabled(m_execCommandInJavaScript);
    RuntimeEnabledFeatures::setComputedAccessibilityInfoEnabled(m_computedAccessibilityInfo);
    RuntimeEnabledFeatures::setExperimentalCanvasFeaturesEnabled(m_experimentalCanvasFeatures);
    RuntimeEnabledFeatures::setExperimentalContentSecurityPolicyFeaturesEnabled(m_experimentalContentSecurityPolicyFeatures);
    RuntimeEnabledFeatures::setExperimentalV8ExtrasEnabled(m_experimentalV8Extras);
    RuntimeEnabledFeatures::setFastMobileScrollingEnabled(m_fastMobileScrolling);
    RuntimeEnabledFeatures::setFeaturePolicyEnabled(m_featurePolicy);
    RuntimeEnabledFeatures::setFileAPIBlobCloseEnabled(m_fileAPIBlobClose);
    RuntimeEnabledFeatures::setFileSystemEnabled(m_fileSystem);
    RuntimeEnabledFeatures::setForeignFetchEnabled(m_foreignFetch);
    RuntimeEnabledFeatures::setFramebustingNeedsSameOriginOrUserGestureEnabled(m_framebustingNeedsSameOriginOrUserGesture);
    RuntimeEnabledFeatures::setFullscreenUnprefixedEnabled(m_fullscreenUnprefixed);
    RuntimeEnabledFeatures::setFrameTimingSupportEnabled(m_frameTimingSupport);
    RuntimeEnabledFeatures::setGamepadExtensionsEnabled(m_gamepadExtensions);
    RuntimeEnabledFeatures::setGeometryInterfacesEnabled(m_geometryInterfaces);
    RuntimeEnabledFeatures::setGetUserMediaEnabled(m_getUserMedia);
    RuntimeEnabledFeatures::setGlobalCacheStorageEnabled(m_globalCacheStorage);
    RuntimeEnabledFeatures::setHeapCompactionEnabled(m_heapCompaction);
    RuntimeEnabledFeatures::setIDBObserverEnabled(m_iDBObserver);
    RuntimeEnabledFeatures::setIdleTimeSpellCheckingEnabled(m_idleTimeSpellChecking);
    RuntimeEnabledFeatures::setImageCaptureEnabled(m_imageCapture);
    RuntimeEnabledFeatures::setImageOrientationEnabled(m_imageOrientation);
    RuntimeEnabledFeatures::setIndexedDBExperimentalEnabled(m_indexedDBExperimental);
    RuntimeEnabledFeatures::setInertTopControlsEnabled(m_inertTopControls);
    RuntimeEnabledFeatures::setInputEventEnabled(m_inputEvent);
    RuntimeEnabledFeatures::setInputModeAttributeEnabled(m_inputModeAttribute);
    RuntimeEnabledFeatures::setInputMultipleFieldsUIEnabled(m_inputMultipleFieldsUI);
    RuntimeEnabledFeatures::setInstalledAppEnabled(m_installedApp);
    RuntimeEnabledFeatures::setIntersectionObserverEnabled(m_intersectionObserver);
    RuntimeEnabledFeatures::setLangAttributeAwareFormControlUIEnabled(m_langAttributeAwareFormControlUI);
    RuntimeEnabledFeatures::setLayoutNGEnabled(m_layoutNG);
    RuntimeEnabledFeatures::setLayoutNGInlineEnabled(m_layoutNGInline);
    RuntimeEnabledFeatures::setLinkServiceWorkerEnabled(m_linkServiceWorker);
    RuntimeEnabledFeatures::setLongTaskObserverEnabled(m_longTaskObserver);
    RuntimeEnabledFeatures::setFractionalScrollOffsetsEnabled(m_fractionalScrollOffsets);
    RuntimeEnabledFeatures::setLoadingWithMojoEnabled(m_loadingWithMojo);
    RuntimeEnabledFeatures::setMediaCaptureEnabled(m_mediaCapture);
    RuntimeEnabledFeatures::setMediaCaptureFromCanvasEnabled(m_mediaCaptureFromCanvas);
    RuntimeEnabledFeatures::setMediaCaptureFromVideoEnabled(m_mediaCaptureFromVideo);
    RuntimeEnabledFeatures::setMediaConstraintsEnabled(m_mediaConstraints);
    RuntimeEnabledFeatures::setMediaDocumentDownloadButtonEnabled(m_mediaDocumentDownloadButton);
    RuntimeEnabledFeatures::setMediaGetSettingsEnabled(m_mediaGetSettings);
    RuntimeEnabledFeatures::setMediaSessionEnabled(m_mediaSession);
    RuntimeEnabledFeatures::setMediaSourceExperimentalEnabled(m_mediaSourceExperimental);
    RuntimeEnabledFeatures::setMediaSourceNewAbortAndDurationEnabled(m_mediaSourceNewAbortAndDuration);
    RuntimeEnabledFeatures::setMediaStreamSpeechEnabled(m_mediaStreamSpeech);
    RuntimeEnabledFeatures::setMediaQueryShapeEnabled(m_mediaQueryShape);
    RuntimeEnabledFeatures::setMediaStreamTrackContentHintEnabled(m_mediaStreamTrackContentHint);
    RuntimeEnabledFeatures::setMemoryInfoInWorkersEnabled(m_memoryInfoInWorkers);
    RuntimeEnabledFeatures::setMiddleClickAutoscrollEnabled(m_middleClickAutoscroll);
    RuntimeEnabledFeatures::setMobileLayoutThemeEnabled(m_mobileLayoutTheme);
    RuntimeEnabledFeatures::setModuleScriptsEnabled(m_moduleScripts);
    RuntimeEnabledFeatures::setNavigatorContentUtilsEnabled(m_navigatorContentUtils);
    RuntimeEnabledFeatures::setWebNFCEnabled(m_webNFC);
    RuntimeEnabledFeatures::setNetworkInformationEnabled(m_networkInformation);
    RuntimeEnabledFeatures::setNetInfoDownlinkMaxEnabled(m_netInfoDownlinkMax);
    RuntimeEnabledFeatures::setNotificationConstructorEnabled(m_notificationConstructor);
    RuntimeEnabledFeatures::setNotificationBadgeEnabled(m_notificationBadge);
    RuntimeEnabledFeatures::setNotificationContentImageEnabled(m_notificationContentImage);
    RuntimeEnabledFeatures::setNotificationInlineRepliesEnabled(m_notificationInlineReplies);
    RuntimeEnabledFeatures::setNotificationsEnabled(m_notifications);
    RuntimeEnabledFeatures::setOnDeviceChangeEnabled(m_onDeviceChange);
    RuntimeEnabledFeatures::setOrientationEventEnabled(m_orientationEvent);
    RuntimeEnabledFeatures::setOriginTrialsEnabled(m_originTrials);
    RuntimeEnabledFeatures::setOriginTrialsSampleAPIEnabled(m_originTrialsSampleAPI);
    RuntimeEnabledFeatures::setForceOverlayFullscreenVideoEnabled(m_forceOverlayFullscreenVideo);
    RuntimeEnabledFeatures::setOverlayScrollbarsEnabled(m_overlayScrollbars);
    RuntimeEnabledFeatures::setPagePopupEnabled(m_pagePopup);
    RuntimeEnabledFeatures::setPaintUnderInvalidationCheckingEnabled(m_paintUnderInvalidationChecking);
    RuntimeEnabledFeatures::setPassiveDocumentEventListenersEnabled(m_passiveDocumentEventListeners);
    RuntimeEnabledFeatures::setPassPaintVisualRectToCompositorEnabled(m_passPaintVisualRectToCompositor);
    RuntimeEnabledFeatures::setPaymentAppEnabled(m_paymentApp);
    RuntimeEnabledFeatures::setPaymentDetailsErrorEnabled(m_paymentDetailsError);
    RuntimeEnabledFeatures::setPaymentDetailsModifierDataEnabled(m_paymentDetailsModifierData);
    RuntimeEnabledFeatures::setPaymentRequestEnabled(m_paymentRequest);
    RuntimeEnabledFeatures::setPaymentRequestBasicCardEnabled(m_paymentRequestBasicCard);
    RuntimeEnabledFeatures::setPaymentRequestPayerNameEnabled(m_paymentRequestPayerName);
    RuntimeEnabledFeatures::setPerformanceObserverEnabled(m_performanceObserver);
    RuntimeEnabledFeatures::setPermissionDelegationEnabled(m_permissionDelegation);
    RuntimeEnabledFeatures::setPermissionsEnabled(m_permissions);
    RuntimeEnabledFeatures::setPermissionsRequestRevokeEnabled(m_permissionsRequestRevoke);
    RuntimeEnabledFeatures::setPointerEventEnabled(m_pointerEvent);
    RuntimeEnabledFeatures::setPreciseMemoryInfoEnabled(m_preciseMemoryInfo);
    RuntimeEnabledFeatures::setPreferredImageRasterBoundsEnabled(m_preferredImageRasterBounds);
    RuntimeEnabledFeatures::setPrefixedVideoFullscreenEnabled(m_prefixedVideoFullscreen);
    RuntimeEnabledFeatures::setPresentationEnabled(m_presentation);
    RuntimeEnabledFeatures::setPresentationReceiverEnabled(m_presentationReceiver);
    RuntimeEnabledFeatures::setPushMessagingEnabled(m_pushMessaging);
    RuntimeEnabledFeatures::setQuotaPromiseEnabled(m_quotaPromise);
    RuntimeEnabledFeatures::setReducedReferrerGranularityEnabled(m_reducedReferrerGranularity);
    RuntimeEnabledFeatures::setRemotePlaybackEnabled(m_remotePlayback);
    RuntimeEnabledFeatures::setRenderingPipelineThrottlingEnabled(m_renderingPipelineThrottling);
    RuntimeEnabledFeatures::setRenderingPipelineThrottlingLoadingIframesEnabled(m_renderingPipelineThrottlingLoadingIframes);
    RuntimeEnabledFeatures::setRenderUnicodeControlCharactersEnabled(m_renderUnicodeControlCharacters);
    RuntimeEnabledFeatures::setResizeObserverEnabled(m_resizeObserver);
    RuntimeEnabledFeatures::setRootLayerScrollingEnabled(m_rootLayerScrolling);
    RuntimeEnabledFeatures::setRTCPeerConnectionNewGetStatsEnabled(m_rTCPeerConnectionNewGetStats);
    RuntimeEnabledFeatures::setScriptedSpeechEnabled(m_scriptedSpeech);
    RuntimeEnabledFeatures::setScrollAnchoringEnabled(m_scrollAnchoring);
    RuntimeEnabledFeatures::setScrollTopLeftInteropEnabled(m_scrollTopLeftInterop);
    RuntimeEnabledFeatures::setSensorEnabled(m_sensor);
    RuntimeEnabledFeatures::setServiceWorkerNavigationPreloadEnabled(m_serviceWorkerNavigationPreload);
    RuntimeEnabledFeatures::setSetRootScrollerEnabled(m_setRootScroller);
    RuntimeEnabledFeatures::setShadowPiercingDescendantCombinatorEnabled(m_shadowPiercingDescendantCombinator);
    RuntimeEnabledFeatures::setShapeDetectionEnabled(m_shapeDetection);
    RuntimeEnabledFeatures::setSharedArrayBufferEnabled(m_sharedArrayBuffer);
    RuntimeEnabledFeatures::setSharedWorkerEnabled(m_sharedWorker);
    RuntimeEnabledFeatures::setSlimmingPaintInvalidationEnabled(m_slimmingPaintInvalidation);
    RuntimeEnabledFeatures::setSlimmingPaintV2Enabled(m_slimmingPaintV2);
    RuntimeEnabledFeatures::setSlimmingPaintStrictCullRectClippingEnabled(m_slimmingPaintStrictCullRectClipping);
    RuntimeEnabledFeatures::setStableBlinkFeaturesEnabled(m_stableBlinkFeatures);
    RuntimeEnabledFeatures::setStackedCSSPropertyAnimationsEnabled(m_stackedCSSPropertyAnimations);
    RuntimeEnabledFeatures::setStyleSharingEnabled(m_styleSharing);
    RuntimeEnabledFeatures::setSpeculativeLaunchServiceWorkerEnabled(m_speculativeLaunchServiceWorker);
    RuntimeEnabledFeatures::setStorageEstimateEnabled(m_storageEstimate);
    RuntimeEnabledFeatures::setSuboriginsEnabled(m_suborigins);
    RuntimeEnabledFeatures::setTimerThrottlingForBackgroundTabsEnabled(m_timerThrottlingForBackgroundTabs);
    RuntimeEnabledFeatures::setTimerThrottlingForHiddenFramesEnabled(m_timerThrottlingForHiddenFrames);
    RuntimeEnabledFeatures::setTopNavWithUserActivationInSandboxEnabled(m_topNavWithUserActivationInSandbox);
    RuntimeEnabledFeatures::setTouchEventFeatureDetectionEnabled(m_touchEventFeatureDetection);
    RuntimeEnabledFeatures::setTraceWrappablesEnabled(m_traceWrappables);
    RuntimeEnabledFeatures::setTrueColorRenderingEnabled(m_trueColorRendering);
    RuntimeEnabledFeatures::setTrustedEventsDefaultActionEnabled(m_trustedEventsDefaultAction);
    RuntimeEnabledFeatures::setUserSelectAllEnabled(m_userSelectAll);
    RuntimeEnabledFeatures::setWebAnimationsAPIEnabled(m_webAnimationsAPI);
    RuntimeEnabledFeatures::setWebAnimationsSVGEnabled(m_webAnimationsSVG);
    RuntimeEnabledFeatures::setWebAssemblySerializationEnabled(m_webAssemblySerialization);
    RuntimeEnabledFeatures::setWebBluetoothEnabled(m_webBluetooth);
    RuntimeEnabledFeatures::setWebGLDraftExtensionsEnabled(m_webGLDraftExtensions);
    RuntimeEnabledFeatures::setWebGLImageChromiumEnabled(m_webGLImageChromium);
    RuntimeEnabledFeatures::setWebUSBEnabled(m_webUSB);
    RuntimeEnabledFeatures::setWebVREnabled(m_webVR);
    RuntimeEnabledFeatures::setWebVTTRegionsEnabled(m_webVTTRegions);
    RuntimeEnabledFeatures::setV8BasedStructuredCloneEnabled(m_v8BasedStructuredClone);
    RuntimeEnabledFeatures::setV8IdleTasksEnabled(m_v8IdleTasks);
    RuntimeEnabledFeatures::setVideoFullscreenOrientationLockEnabled(m_videoFullscreenOrientationLock);
    RuntimeEnabledFeatures::setVisibilityChangeOnUnloadEnabled(m_visibilityChangeOnUnload);
    RuntimeEnabledFeatures::setXSLTEnabled(m_xslt);
    RuntimeEnabledFeatures::setsmilEnabled(m_smil);
    RuntimeEnabledFeatures::setScrollCustomizationEnabled(m_scrollCustomization);
    RuntimeEnabledFeatures::setAutoplayMutedVideosEnabled(m_autoplayMutedVideos);
    RuntimeEnabledFeatures::setVisualViewportAPIEnabled(m_visualViewportAPI);
    RuntimeEnabledFeatures::setWakeLockEnabled(m_wakeLock);
    RuntimeEnabledFeatures::setWebFontsCacheAwareTimeoutAdaptationEnabled(m_webFontsCacheAwareTimeoutAdaptation);
    RuntimeEnabledFeatures::setWebFontsInterventionV2With2GEnabled(m_webFontsInterventionV2With2G);
    RuntimeEnabledFeatures::setWebFontsInterventionV2With3GEnabled(m_webFontsInterventionV2With3G);
    RuntimeEnabledFeatures::setWebFontsInterventionV2WithSlow2GEnabled(m_webFontsInterventionV2WithSlow2G);
    RuntimeEnabledFeatures::setWebFontsInterventionTriggerEnabled(m_webFontsInterventionTrigger);
    RuntimeEnabledFeatures::setWebShareEnabled(m_webShare);
    RuntimeEnabledFeatures::setWorkletEnabled(m_worklet);
    RuntimeEnabledFeatures::setLazyParseCSSEnabled(m_lazyParseCSS);
    RuntimeEnabledFeatures::setParseHTMLOnMainThreadEnabled(m_parseHTMLOnMainThread);
    RuntimeEnabledFeatures::setSendBeaconThrowForBlobWithNonSimpleTypeEnabled(m_sendBeaconThrowForBlobWithNonSimpleType);
    RuntimeEnabledFeatures::setPerformanceNavigationTiming2Enabled(m_performanceNavigationTiming2);
    RuntimeEnabledFeatures::setBackgroundVideoTrackOptimizationEnabled(m_backgroundVideoTrackOptimization);
    RuntimeEnabledFeatures::setPerformancePaintTimingEnabled(m_performancePaintTiming);
    RuntimeEnabledFeatures::setHideNonceContentAttributeEnabled(m_hideNonceContentAttribute);
    RuntimeEnabledFeatures::setUnclosedFormControlIsInvalidEnabled(m_unclosedFormControlIsInvalid);
    RuntimeEnabledFeatures::setRestrictCompleteURLCharacterSetEnabled(m_restrictCompleteURLCharacterSet);
}

void RuntimeEnabledFeatures::setStableFeaturesEnabled(bool enable)
{
    setAccelerated2dCanvasEnabled(enable);
    setAudioOutputDevicesEnabled(enable);
    setAuxclickEnabled(enable);
    setBackgroundSyncEnabled(enable);
    setBroadcastChannelEnabled(enable);
    setCanMakePaymentEnabled(enable);
    setClientHintsEnabled(enable);
    setCompositeOpaqueScrollersEnabled(enable);
    setCredentialManagerEnabled(enable);
    setCSS3TextDecorationsEnabled(enable);
    setCSSContainmentEnabled(enable);
    setCSSGridLayoutEnabled(enable);
    setCSSHyphensEnabled(enable);
    setCSSOffsetRotateEnabled(enable);
    setCSSOffsetRotationEnabled(enable);
    setCSSStickyPositionEnabled(enable);
    setCSSTouchActionPanDirectionsEnabled(enable);
    setCSSTouchActionPinchZoomEnabled(enable);
    setCustomElementsV1Enabled(enable);
    setDatabaseEnabled(enable);
    setDisplayList2dCanvasEnabled(enable);
    setDOMConvenienceAPIEnabled(enable);
    setDurableStorageEnabled(enable);
    setFileSystemEnabled(enable);
    setGetUserMediaEnabled(enable);
    setGlobalCacheStorageEnabled(enable);
    setInertTopControlsEnabled(enable);
    setInputMultipleFieldsUIEnabled(enable);
    setIntersectionObserverEnabled(enable);
    setMediaCaptureFromCanvasEnabled(enable);
    setMediaConstraintsEnabled(enable);
    setNetworkInformationEnabled(enable);
    setNetInfoDownlinkMaxEnabled(enable);
    setNotificationConstructorEnabled(enable);
    setNotificationBadgeEnabled(enable);
    setNotificationContentImageEnabled(enable);
    setNotificationsEnabled(enable);
    setOnDeviceChangeEnabled(enable);
    setOriginTrialsEnabled(enable);
    setPagePopupEnabled(enable);
    setPassiveDocumentEventListenersEnabled(enable);
    setPaymentDetailsErrorEnabled(enable);
    setPaymentRequestBasicCardEnabled(enable);
    setPaymentRequestPayerNameEnabled(enable);
    setPerformanceObserverEnabled(enable);
    setPermissionsEnabled(enable);
    setPointerEventEnabled(enable);
    setPrefixedVideoFullscreenEnabled(enable);
    setPresentationEnabled(enable);
    setPushMessagingEnabled(enable);
    setRemotePlaybackEnabled(enable);
    setRenderingPipelineThrottlingEnabled(enable);
    setRenderingPipelineThrottlingLoadingIframesEnabled(enable);
    setRenderUnicodeControlCharactersEnabled(enable);
    setScriptedSpeechEnabled(enable);
    setSharedWorkerEnabled(enable);
    setStableBlinkFeaturesEnabled(enable);
    setStyleSharingEnabled(enable);
    setTimerThrottlingForBackgroundTabsEnabled(enable);
    setTimerThrottlingForHiddenFramesEnabled(enable);
    setTouchEventFeatureDetectionEnabled(enable);
    setTraceWrappablesEnabled(enable);
    setTrustedEventsDefaultActionEnabled(enable);
    setUserSelectAllEnabled(enable);
    setV8BasedStructuredCloneEnabled(enable);
    setVisibilityChangeOnUnloadEnabled(enable);
    setXSLTEnabled(enable);
    setsmilEnabled(enable);
    setPerformanceNavigationTiming2Enabled(enable);
    setBackgroundVideoTrackOptimizationEnabled(enable);
}

void RuntimeEnabledFeatures::setExperimentalFeaturesEnabled(bool enable)
{
    setAudioVideoTracksEnabled(enable);
    setAudioWorkletEnabled(enable);
    setCoalescedEventsEnabled(enable);
    setBudgetEnabled(enable);
    setEnableCanvas2dDynamicRenderingModeSwitchingEnabled(enable);
    setCanvas2dImageChromiumEnabled(enable);
    setColorCorrectRenderingEnabled(enable);
    setColorCorrectRenderingDefaultModeEnabled(enable);
    setCompositorWorkerEnabled(enable);
    setCSS3TextEnabled(enable);
    setCSSApplyAtRulesEnabled(enable);
    setCSSAdditiveAnimationsEnabled(enable);
    setCSSBackdropFilterEnabled(enable);
    setCSSHexAlphaColorEnabled(enable);
    setCSSFontDisplayEnabled(enable);
    setCSSFontSizeAdjustEnabled(enable);
    setCSSDisplayContentsEnabled(enable);
    setCSSInBodyDoesNotBlockPaintEnabled(enable);
    setCSSIndependentTransformPropertiesEnabled(enable);
    setCSSMaskSourceTypeEnabled(enable);
    setCSSOMSmoothScrollEnabled(enable);
    setCSSOffsetPositionAnchorEnabled(enable);
    setCSSPaintAPIEnabled(enable);
    setCSSPaintAPIArgumentsEnabled(enable);
    setCSSSnapSizeEnabled(enable);
    setCSSTypedOMEnabled(enable);
    setCSSVariableFontsEnabled(enable);
    setCSSVariables2Enabled(enable);
    setCSSViewportEnabled(enable);
    setCustomSchemeHandlerEnabled(enable);
    setDecodeToYUVEnabled(enable);
    setDesktopCaptureDisableLocalEchoControlEnabled(enable);
    setDeviceLightEnabled(enable);
    setExpensiveBackgroundTimerThrottlingEnabled(enable);
    setFasterLocationReloadEnabled(enable);
    setEmbedderCSPEnforcementEnabled(enable);
    setComputedAccessibilityInfoEnabled(enable);
    setExperimentalContentSecurityPolicyFeaturesEnabled(enable);
    setExperimentalV8ExtrasEnabled(enable);
    setFeaturePolicyEnabled(enable);
    setFileAPIBlobCloseEnabled(enable);
    setForeignFetchEnabled(enable);
    setFramebustingNeedsSameOriginOrUserGestureEnabled(enable);
    setFrameTimingSupportEnabled(enable);
    setGeometryInterfacesEnabled(enable);
    setHeapCompactionEnabled(enable);
    setIDBObserverEnabled(enable);
    setImageCaptureEnabled(enable);
    setIndexedDBExperimentalEnabled(enable);
    setInputEventEnabled(enable);
    setInputModeAttributeEnabled(enable);
    setInstalledAppEnabled(enable);
    setLinkServiceWorkerEnabled(enable);
    setLongTaskObserverEnabled(enable);
    setMediaCaptureFromVideoEnabled(enable);
    setMediaSourceExperimentalEnabled(enable);
    setMediaSourceNewAbortAndDurationEnabled(enable);
    setMediaStreamSpeechEnabled(enable);
    setMediaQueryShapeEnabled(enable);
    setMediaStreamTrackContentHintEnabled(enable);
    setMemoryInfoInWorkersEnabled(enable);
    setMiddleClickAutoscrollEnabled(enable);
    setWebNFCEnabled(enable);
    setNotificationInlineRepliesEnabled(enable);
    setPaymentAppEnabled(enable);
    setPaymentDetailsModifierDataEnabled(enable);
    setPaymentRequestEnabled(enable);
    setPermissionsRequestRevokeEnabled(enable);
    setQuotaPromiseEnabled(enable);
    setResizeObserverEnabled(enable);
    setRTCPeerConnectionNewGetStatsEnabled(enable);
    setScrollAnchoringEnabled(enable);
    setScrollTopLeftInteropEnabled(enable);
    setSensorEnabled(enable);
    setSetRootScrollerEnabled(enable);
    setShadowPiercingDescendantCombinatorEnabled(enable);
    setShapeDetectionEnabled(enable);
    setSlimmingPaintInvalidationEnabled(enable);
    setStackedCSSPropertyAnimationsEnabled(enable);
    setStorageEstimateEnabled(enable);
    setSuboriginsEnabled(enable);
    setTopNavWithUserActivationInSandboxEnabled(enable);
    setTrueColorRenderingEnabled(enable);
    setWebAnimationsAPIEnabled(enable);
    setWebAnimationsSVGEnabled(enable);
    setWebBluetoothEnabled(enable);
    setWebGLDraftExtensionsEnabled(enable);
    setWebUSBEnabled(enable);
    setWebVTTRegionsEnabled(enable);
    setVisualViewportAPIEnabled(enable);
    setWakeLockEnabled(enable);
    setWebFontsCacheAwareTimeoutAdaptationEnabled(enable);
    setWebShareEnabled(enable);
    setWorkletEnabled(enable);
    setLazyParseCSSEnabled(enable);
    setSendBeaconThrowForBlobWithNonSimpleTypeEnabled(enable);
    setHideNonceContentAttributeEnabled(enable);
    setUnclosedFormControlIsInvalidEnabled(enable);
    setRestrictCompleteURLCharacterSetEnabled(enable);
}

void RuntimeEnabledFeatures::setTestFeaturesEnabled(bool enable)
{
    setBackspaceDefaultHandlerEnabled(enable);
    setCanvas2dFixedRenderingModeEnabled(enable);
    setCompositeOpaqueFixedPositionEnabled(enable);
    setContextMenuEnabled(enable);
    setCorsRFC1918Enabled(enable);
    setCSSScrollSnapPointsEnabled(enable);
    setCustomElementsBuiltinEnabled(enable);
    setFontCacheScalingEnabled(enable);
    setExecCommandInJavaScriptEnabled(enable);
    setExperimentalCanvasFeaturesEnabled(enable);
    setFullscreenUnprefixedEnabled(enable);
    setGamepadExtensionsEnabled(enable);
    setImageOrientationEnabled(enable);
    setMediaGetSettingsEnabled(enable);
    setMediaSessionEnabled(enable);
    setModuleScriptsEnabled(enable);
    setPermissionDelegationEnabled(enable);
    setPresentationReceiverEnabled(enable);
    setWebAssemblySerializationEnabled(enable);
    setWebVREnabled(enable);
    setParseHTMLOnMainThreadEnabled(enable);
    setPerformancePaintTimingEnabled(enable);
}

void RuntimeEnabledFeatures::setFeatureEnabledFromString(
    const std::string& name, bool isEnabled)
{
    if (name == "Accelerated2dCanvas") {
        setAccelerated2dCanvasEnabled(isEnabled);
        return;
    }
    if (name == "AudioOutputDevices") {
        setAudioOutputDevicesEnabled(isEnabled);
        return;
    }
    if (name == "AudioVideoTracks") {
        setAudioVideoTracksEnabled(isEnabled);
        return;
    }
    if (name == "AudioWorklet") {
        setAudioWorkletEnabled(isEnabled);
        return;
    }
    if (name == "Auxclick") {
        setAuxclickEnabled(isEnabled);
        return;
    }
    if (name == "CoalescedEvents") {
        setCoalescedEventsEnabled(isEnabled);
        return;
    }
    if (name == "BackgroundSync") {
        setBackgroundSyncEnabled(isEnabled);
        return;
    }
    if (name == "BackspaceDefaultHandler") {
        setBackspaceDefaultHandlerEnabled(isEnabled);
        return;
    }
    if (name == "BroadcastChannel") {
        setBroadcastChannelEnabled(isEnabled);
        return;
    }
    if (name == "Budget") {
        setBudgetEnabled(isEnabled);
        return;
    }
    if (name == "Canvas2dFixedRenderingMode") {
        setCanvas2dFixedRenderingModeEnabled(isEnabled);
        return;
    }
    if (name == "EnableCanvas2dDynamicRenderingModeSwitching") {
        setEnableCanvas2dDynamicRenderingModeSwitchingEnabled(isEnabled);
        return;
    }
    if (name == "CanMakePayment") {
        setCanMakePaymentEnabled(isEnabled);
        return;
    }
    if (name == "Canvas2dImageChromium") {
        setCanvas2dImageChromiumEnabled(isEnabled);
        return;
    }
    if (name == "ClientHints") {
        setClientHintsEnabled(isEnabled);
        return;
    }
    if (name == "CompositeOpaqueFixedPosition") {
        setCompositeOpaqueFixedPositionEnabled(isEnabled);
        return;
    }
    if (name == "CompositeOpaqueScrollers") {
        setCompositeOpaqueScrollersEnabled(isEnabled);
        return;
    }
    if (name == "ColorCorrectRendering") {
        setColorCorrectRenderingEnabled(isEnabled);
        return;
    }
    if (name == "ColorCorrectRenderingDefaultMode") {
        setColorCorrectRenderingDefaultModeEnabled(isEnabled);
        return;
    }
    if (name == "CompositedSelectionUpdate") {
        setCompositedSelectionUpdateEnabled(isEnabled);
        return;
    }
    if (name == "CompositorWorker") {
        setCompositorWorkerEnabled(isEnabled);
        return;
    }
    if (name == "ContextMenu") {
        setContextMenuEnabled(isEnabled);
        return;
    }
    if (name == "CorsRFC1918") {
        setCorsRFC1918Enabled(isEnabled);
        return;
    }
    if (name == "CredentialManager") {
        setCredentialManagerEnabled(isEnabled);
        return;
    }
    if (name == "CSS3Text") {
        setCSS3TextEnabled(isEnabled);
        return;
    }
    if (name == "CSS3TextDecorations") {
        setCSS3TextDecorationsEnabled(isEnabled);
        return;
    }
    if (name == "CSSApplyAtRules") {
        setCSSApplyAtRulesEnabled(isEnabled);
        return;
    }
    if (name == "CSSAdditiveAnimations") {
        setCSSAdditiveAnimationsEnabled(isEnabled);
        return;
    }
    if (name == "CSSBackdropFilter") {
        setCSSBackdropFilterEnabled(isEnabled);
        return;
    }
    if (name == "CSSHexAlphaColor") {
        setCSSHexAlphaColorEnabled(isEnabled);
        return;
    }
    if (name == "CSSContainment") {
        setCSSContainmentEnabled(isEnabled);
        return;
    }
    if (name == "CSSFontDisplay") {
        setCSSFontDisplayEnabled(isEnabled);
        return;
    }
    if (name == "CSSFontSizeAdjust") {
        setCSSFontSizeAdjustEnabled(isEnabled);
        return;
    }
    if (name == "CSSGridLayout") {
        setCSSGridLayoutEnabled(isEnabled);
        return;
    }
    if (name == "CSSDisplayContents") {
        setCSSDisplayContentsEnabled(isEnabled);
        return;
    }
    if (name == "CSSHyphens") {
        setCSSHyphensEnabled(isEnabled);
        return;
    }
    if (name == "CSSInBodyDoesNotBlockPaint") {
        setCSSInBodyDoesNotBlockPaintEnabled(isEnabled);
        return;
    }
    if (name == "CSSIndependentTransformProperties") {
        setCSSIndependentTransformPropertiesEnabled(isEnabled);
        return;
    }
    if (name == "CSSMaskSourceType") {
        setCSSMaskSourceTypeEnabled(isEnabled);
        return;
    }
    if (name == "CSSOMSmoothScroll") {
        setCSSOMSmoothScrollEnabled(isEnabled);
        return;
    }
    if (name == "CSSOffsetPositionAnchor") {
        setCSSOffsetPositionAnchorEnabled(isEnabled);
        return;
    }
    if (name == "CSSOffsetRotate") {
        setCSSOffsetRotateEnabled(isEnabled);
        return;
    }
    if (name == "CSSOffsetRotation") {
        setCSSOffsetRotationEnabled(isEnabled);
        return;
    }
    if (name == "CSSPaintAPI") {
        setCSSPaintAPIEnabled(isEnabled);
        return;
    }
    if (name == "CSSPaintAPIArguments") {
        setCSSPaintAPIArgumentsEnabled(isEnabled);
        return;
    }
    if (name == "CSSSnapSize") {
        setCSSSnapSizeEnabled(isEnabled);
        return;
    }
    if (name == "CSSStickyPosition") {
        setCSSStickyPositionEnabled(isEnabled);
        return;
    }
    if (name == "CSSTouchActionPanDirections") {
        setCSSTouchActionPanDirectionsEnabled(isEnabled);
        return;
    }
    if (name == "CSSTouchActionPinchZoom") {
        setCSSTouchActionPinchZoomEnabled(isEnabled);
        return;
    }
    if (name == "CSSTypedOM") {
        setCSSTypedOMEnabled(isEnabled);
        return;
    }
    if (name == "CSSVariableFonts") {
        setCSSVariableFontsEnabled(isEnabled);
        return;
    }
    if (name == "CSSVariables2") {
        setCSSVariables2Enabled(isEnabled);
        return;
    }
    if (name == "CSSViewport") {
        setCSSViewportEnabled(isEnabled);
        return;
    }
    if (name == "CSSScrollSnapPoints") {
        setCSSScrollSnapPointsEnabled(isEnabled);
        return;
    }
    if (name == "CustomElementsBuiltin") {
        setCustomElementsBuiltinEnabled(isEnabled);
        return;
    }
    if (name == "CustomElementsV1") {
        setCustomElementsV1Enabled(isEnabled);
        return;
    }
    if (name == "CustomSchemeHandler") {
        setCustomSchemeHandlerEnabled(isEnabled);
        return;
    }
    if (name == "Database") {
        setDatabaseEnabled(isEnabled);
        return;
    }
    if (name == "DecodeToYUV") {
        setDecodeToYUVEnabled(isEnabled);
        return;
    }
    if (name == "DesktopCaptureDisableLocalEchoControl") {
        setDesktopCaptureDisableLocalEchoControlEnabled(isEnabled);
        return;
    }
    if (name == "DeviceLight") {
        setDeviceLightEnabled(isEnabled);
        return;
    }
    if (name == "DisplayList2dCanvas") {
        setDisplayList2dCanvasEnabled(isEnabled);
        return;
    }
    if (name == "DocumentCookie") {
        setDocumentCookieEnabled(isEnabled);
        return;
    }
    if (name == "DocumentDomain") {
        setDocumentDomainEnabled(isEnabled);
        return;
    }
    if (name == "DocumentWrite") {
        setDocumentWriteEnabled(isEnabled);
        return;
    }
    if (name == "DocumentWriteEvaluator") {
        setDocumentWriteEvaluatorEnabled(isEnabled);
        return;
    }
    if (name == "DOMConvenienceAPI") {
        setDOMConvenienceAPIEnabled(isEnabled);
        return;
    }
    if (name == "DurableStorage") {
        setDurableStorageEnabled(isEnabled);
        return;
    }
    if (name == "ExpensiveBackgroundTimerThrottling") {
        setExpensiveBackgroundTimerThrottlingEnabled(isEnabled);
        return;
    }
    if (name == "FasterLocationReload") {
        setFasterLocationReloadEnabled(isEnabled);
        return;
    }
    if (name == "FontCacheScaling") {
        setFontCacheScalingEnabled(isEnabled);
        return;
    }
    if (name == "ForceDisplayList2dCanvas") {
        setForceDisplayList2dCanvasEnabled(isEnabled);
        return;
    }
    if (name == "ForceDisable2dCanvasCopyOnWrite") {
        setForceDisable2dCanvasCopyOnWriteEnabled(isEnabled);
        return;
    }
    if (name == "EmbedderCSPEnforcement") {
        setEmbedderCSPEnforcementEnabled(isEnabled);
        return;
    }
    if (name == "ExecCommandInJavaScript") {
        setExecCommandInJavaScriptEnabled(isEnabled);
        return;
    }
    if (name == "ComputedAccessibilityInfo") {
        setComputedAccessibilityInfoEnabled(isEnabled);
        return;
    }
    if (name == "ExperimentalCanvasFeatures") {
        setExperimentalCanvasFeaturesEnabled(isEnabled);
        return;
    }
    if (name == "ExperimentalContentSecurityPolicyFeatures") {
        setExperimentalContentSecurityPolicyFeaturesEnabled(isEnabled);
        return;
    }
    if (name == "ExperimentalV8Extras") {
        setExperimentalV8ExtrasEnabled(isEnabled);
        return;
    }
    if (name == "FastMobileScrolling") {
        setFastMobileScrollingEnabled(isEnabled);
        return;
    }
    if (name == "FeaturePolicy") {
        setFeaturePolicyEnabled(isEnabled);
        return;
    }
    if (name == "FileAPIBlobClose") {
        setFileAPIBlobCloseEnabled(isEnabled);
        return;
    }
    if (name == "FileSystem") {
        setFileSystemEnabled(isEnabled);
        return;
    }
    if (name == "ForeignFetch") {
        setForeignFetchEnabled(isEnabled);
        return;
    }
    if (name == "FramebustingNeedsSameOriginOrUserGesture") {
        setFramebustingNeedsSameOriginOrUserGestureEnabled(isEnabled);
        return;
    }
    if (name == "FullscreenUnprefixed") {
        setFullscreenUnprefixedEnabled(isEnabled);
        return;
    }
    if (name == "FrameTimingSupport") {
        setFrameTimingSupportEnabled(isEnabled);
        return;
    }
    if (name == "GamepadExtensions") {
        setGamepadExtensionsEnabled(isEnabled);
        return;
    }
    if (name == "GeometryInterfaces") {
        setGeometryInterfacesEnabled(isEnabled);
        return;
    }
    if (name == "GetUserMedia") {
        setGetUserMediaEnabled(isEnabled);
        return;
    }
    if (name == "GlobalCacheStorage") {
        setGlobalCacheStorageEnabled(isEnabled);
        return;
    }
    if (name == "HeapCompaction") {
        setHeapCompactionEnabled(isEnabled);
        return;
    }
    if (name == "IDBObserver") {
        setIDBObserverEnabled(isEnabled);
        return;
    }
    if (name == "IdleTimeSpellChecking") {
        setIdleTimeSpellCheckingEnabled(isEnabled);
        return;
    }
    if (name == "ImageCapture") {
        setImageCaptureEnabled(isEnabled);
        return;
    }
    if (name == "ImageOrientation") {
        setImageOrientationEnabled(isEnabled);
        return;
    }
    if (name == "IndexedDBExperimental") {
        setIndexedDBExperimentalEnabled(isEnabled);
        return;
    }
    if (name == "InertTopControls") {
        setInertTopControlsEnabled(isEnabled);
        return;
    }
    if (name == "InputEvent") {
        setInputEventEnabled(isEnabled);
        return;
    }
    if (name == "InputModeAttribute") {
        setInputModeAttributeEnabled(isEnabled);
        return;
    }
    if (name == "InputMultipleFieldsUI") {
        setInputMultipleFieldsUIEnabled(isEnabled);
        return;
    }
    if (name == "InstalledApp") {
        setInstalledAppEnabled(isEnabled);
        return;
    }
    if (name == "IntersectionObserver") {
        setIntersectionObserverEnabled(isEnabled);
        return;
    }
    if (name == "LangAttributeAwareFormControlUI") {
        setLangAttributeAwareFormControlUIEnabled(isEnabled);
        return;
    }
    if (name == "LayoutNG") {
        setLayoutNGEnabled(isEnabled);
        return;
    }
    if (name == "LayoutNGInline") {
        setLayoutNGInlineEnabled(isEnabled);
        return;
    }
    if (name == "LinkServiceWorker") {
        setLinkServiceWorkerEnabled(isEnabled);
        return;
    }
    if (name == "LongTaskObserver") {
        setLongTaskObserverEnabled(isEnabled);
        return;
    }
    if (name == "FractionalScrollOffsets") {
        setFractionalScrollOffsetsEnabled(isEnabled);
        return;
    }
    if (name == "LoadingWithMojo") {
        setLoadingWithMojoEnabled(isEnabled);
        return;
    }
    if (name == "MediaCapture") {
        setMediaCaptureEnabled(isEnabled);
        return;
    }
    if (name == "MediaCaptureFromCanvas") {
        setMediaCaptureFromCanvasEnabled(isEnabled);
        return;
    }
    if (name == "MediaCaptureFromVideo") {
        setMediaCaptureFromVideoEnabled(isEnabled);
        return;
    }
    if (name == "MediaConstraints") {
        setMediaConstraintsEnabled(isEnabled);
        return;
    }
    if (name == "MediaDocumentDownloadButton") {
        setMediaDocumentDownloadButtonEnabled(isEnabled);
        return;
    }
    if (name == "MediaGetSettings") {
        setMediaGetSettingsEnabled(isEnabled);
        return;
    }
    if (name == "MediaSession") {
        setMediaSessionEnabled(isEnabled);
        return;
    }
    if (name == "MediaSourceExperimental") {
        setMediaSourceExperimentalEnabled(isEnabled);
        return;
    }
    if (name == "MediaSourceNewAbortAndDuration") {
        setMediaSourceNewAbortAndDurationEnabled(isEnabled);
        return;
    }
    if (name == "MediaStreamSpeech") {
        setMediaStreamSpeechEnabled(isEnabled);
        return;
    }
    if (name == "MediaQueryShape") {
        setMediaQueryShapeEnabled(isEnabled);
        return;
    }
    if (name == "MediaStreamTrackContentHint") {
        setMediaStreamTrackContentHintEnabled(isEnabled);
        return;
    }
    if (name == "MemoryInfoInWorkers") {
        setMemoryInfoInWorkersEnabled(isEnabled);
        return;
    }
    if (name == "MiddleClickAutoscroll") {
        setMiddleClickAutoscrollEnabled(isEnabled);
        return;
    }
    if (name == "MobileLayoutTheme") {
        setMobileLayoutThemeEnabled(isEnabled);
        return;
    }
    if (name == "ModuleScripts") {
        setModuleScriptsEnabled(isEnabled);
        return;
    }
    if (name == "NavigatorContentUtils") {
        setNavigatorContentUtilsEnabled(isEnabled);
        return;
    }
    if (name == "WebNFC") {
        setWebNFCEnabled(isEnabled);
        return;
    }
    if (name == "NetworkInformation") {
        setNetworkInformationEnabled(isEnabled);
        return;
    }
    if (name == "NetInfoDownlinkMax") {
        setNetInfoDownlinkMaxEnabled(isEnabled);
        return;
    }
    if (name == "NotificationConstructor") {
        setNotificationConstructorEnabled(isEnabled);
        return;
    }
    if (name == "NotificationBadge") {
        setNotificationBadgeEnabled(isEnabled);
        return;
    }
    if (name == "NotificationContentImage") {
        setNotificationContentImageEnabled(isEnabled);
        return;
    }
    if (name == "NotificationInlineReplies") {
        setNotificationInlineRepliesEnabled(isEnabled);
        return;
    }
    if (name == "Notifications") {
        setNotificationsEnabled(isEnabled);
        return;
    }
    if (name == "OnDeviceChange") {
        setOnDeviceChangeEnabled(isEnabled);
        return;
    }
    if (name == "OrientationEvent") {
        setOrientationEventEnabled(isEnabled);
        return;
    }
    if (name == "OriginTrials") {
        setOriginTrialsEnabled(isEnabled);
        return;
    }
    if (name == "OriginTrialsSampleAPI") {
        setOriginTrialsSampleAPIEnabled(isEnabled);
        return;
    }
    if (name == "ForceOverlayFullscreenVideo") {
        setForceOverlayFullscreenVideoEnabled(isEnabled);
        return;
    }
    if (name == "OverlayScrollbars") {
        setOverlayScrollbarsEnabled(isEnabled);
        return;
    }
    if (name == "PagePopup") {
        setPagePopupEnabled(isEnabled);
        return;
    }
    if (name == "PaintUnderInvalidationChecking") {
        setPaintUnderInvalidationCheckingEnabled(isEnabled);
        return;
    }
    if (name == "PassiveDocumentEventListeners") {
        setPassiveDocumentEventListenersEnabled(isEnabled);
        return;
    }
    if (name == "PassPaintVisualRectToCompositor") {
        setPassPaintVisualRectToCompositorEnabled(isEnabled);
        return;
    }
    if (name == "PaymentApp") {
        setPaymentAppEnabled(isEnabled);
        return;
    }
    if (name == "PaymentDetailsError") {
        setPaymentDetailsErrorEnabled(isEnabled);
        return;
    }
    if (name == "PaymentDetailsModifierData") {
        setPaymentDetailsModifierDataEnabled(isEnabled);
        return;
    }
    if (name == "PaymentRequest") {
        setPaymentRequestEnabled(isEnabled);
        return;
    }
    if (name == "PaymentRequestBasicCard") {
        setPaymentRequestBasicCardEnabled(isEnabled);
        return;
    }
    if (name == "PaymentRequestPayerName") {
        setPaymentRequestPayerNameEnabled(isEnabled);
        return;
    }
    if (name == "PerformanceObserver") {
        setPerformanceObserverEnabled(isEnabled);
        return;
    }
    if (name == "PermissionDelegation") {
        setPermissionDelegationEnabled(isEnabled);
        return;
    }
    if (name == "Permissions") {
        setPermissionsEnabled(isEnabled);
        return;
    }
    if (name == "PermissionsRequestRevoke") {
        setPermissionsRequestRevokeEnabled(isEnabled);
        return;
    }
    if (name == "PointerEvent") {
        setPointerEventEnabled(isEnabled);
        return;
    }
    if (name == "PreciseMemoryInfo") {
        setPreciseMemoryInfoEnabled(isEnabled);
        return;
    }
    if (name == "PreferredImageRasterBounds") {
        setPreferredImageRasterBoundsEnabled(isEnabled);
        return;
    }
    if (name == "PrefixedVideoFullscreen") {
        setPrefixedVideoFullscreenEnabled(isEnabled);
        return;
    }
    if (name == "Presentation") {
        setPresentationEnabled(isEnabled);
        return;
    }
    if (name == "PresentationReceiver") {
        setPresentationReceiverEnabled(isEnabled);
        return;
    }
    if (name == "PushMessaging") {
        setPushMessagingEnabled(isEnabled);
        return;
    }
    if (name == "QuotaPromise") {
        setQuotaPromiseEnabled(isEnabled);
        return;
    }
    if (name == "ReducedReferrerGranularity") {
        setReducedReferrerGranularityEnabled(isEnabled);
        return;
    }
    if (name == "RemotePlayback") {
        setRemotePlaybackEnabled(isEnabled);
        return;
    }
    if (name == "RenderingPipelineThrottling") {
        setRenderingPipelineThrottlingEnabled(isEnabled);
        return;
    }
    if (name == "RenderingPipelineThrottlingLoadingIframes") {
        setRenderingPipelineThrottlingLoadingIframesEnabled(isEnabled);
        return;
    }
    if (name == "RenderUnicodeControlCharacters") {
        setRenderUnicodeControlCharactersEnabled(isEnabled);
        return;
    }
    if (name == "ResizeObserver") {
        setResizeObserverEnabled(isEnabled);
        return;
    }
    if (name == "RootLayerScrolling") {
        setRootLayerScrollingEnabled(isEnabled);
        return;
    }
    if (name == "RTCPeerConnectionNewGetStats") {
        setRTCPeerConnectionNewGetStatsEnabled(isEnabled);
        return;
    }
    if (name == "ScriptedSpeech") {
        setScriptedSpeechEnabled(isEnabled);
        return;
    }
    if (name == "ScrollAnchoring") {
        setScrollAnchoringEnabled(isEnabled);
        return;
    }
    if (name == "ScrollTopLeftInterop") {
        setScrollTopLeftInteropEnabled(isEnabled);
        return;
    }
    if (name == "Sensor") {
        setSensorEnabled(isEnabled);
        return;
    }
    if (name == "ServiceWorkerNavigationPreload") {
        setServiceWorkerNavigationPreloadEnabled(isEnabled);
        return;
    }
    if (name == "SetRootScroller") {
        setSetRootScrollerEnabled(isEnabled);
        return;
    }
    if (name == "ShadowPiercingDescendantCombinator") {
        setShadowPiercingDescendantCombinatorEnabled(isEnabled);
        return;
    }
    if (name == "ShapeDetection") {
        setShapeDetectionEnabled(isEnabled);
        return;
    }
    if (name == "SharedArrayBuffer") {
        setSharedArrayBufferEnabled(isEnabled);
        return;
    }
    if (name == "SharedWorker") {
        setSharedWorkerEnabled(isEnabled);
        return;
    }
    if (name == "SlimmingPaintInvalidation") {
        setSlimmingPaintInvalidationEnabled(isEnabled);
        return;
    }
    if (name == "SlimmingPaintV2") {
        setSlimmingPaintV2Enabled(isEnabled);
        return;
    }
    if (name == "SlimmingPaintStrictCullRectClipping") {
        setSlimmingPaintStrictCullRectClippingEnabled(isEnabled);
        return;
    }
    if (name == "StableBlinkFeatures") {
        setStableBlinkFeaturesEnabled(isEnabled);
        return;
    }
    if (name == "StackedCSSPropertyAnimations") {
        setStackedCSSPropertyAnimationsEnabled(isEnabled);
        return;
    }
    if (name == "StyleSharing") {
        setStyleSharingEnabled(isEnabled);
        return;
    }
    if (name == "SpeculativeLaunchServiceWorker") {
        setSpeculativeLaunchServiceWorkerEnabled(isEnabled);
        return;
    }
    if (name == "StorageEstimate") {
        setStorageEstimateEnabled(isEnabled);
        return;
    }
    if (name == "Suborigins") {
        setSuboriginsEnabled(isEnabled);
        return;
    }
    if (name == "TimerThrottlingForBackgroundTabs") {
        setTimerThrottlingForBackgroundTabsEnabled(isEnabled);
        return;
    }
    if (name == "TimerThrottlingForHiddenFrames") {
        setTimerThrottlingForHiddenFramesEnabled(isEnabled);
        return;
    }
    if (name == "TopNavWithUserActivationInSandbox") {
        setTopNavWithUserActivationInSandboxEnabled(isEnabled);
        return;
    }
    if (name == "TouchEventFeatureDetection") {
        setTouchEventFeatureDetectionEnabled(isEnabled);
        return;
    }
    if (name == "TraceWrappables") {
        setTraceWrappablesEnabled(isEnabled);
        return;
    }
    if (name == "TrueColorRendering") {
        setTrueColorRenderingEnabled(isEnabled);
        return;
    }
    if (name == "TrustedEventsDefaultAction") {
        setTrustedEventsDefaultActionEnabled(isEnabled);
        return;
    }
    if (name == "UserSelectAll") {
        setUserSelectAllEnabled(isEnabled);
        return;
    }
    if (name == "WebAnimationsAPI") {
        setWebAnimationsAPIEnabled(isEnabled);
        return;
    }
    if (name == "WebAnimationsSVG") {
        setWebAnimationsSVGEnabled(isEnabled);
        return;
    }
    if (name == "WebAssemblySerialization") {
        setWebAssemblySerializationEnabled(isEnabled);
        return;
    }
    if (name == "WebBluetooth") {
        setWebBluetoothEnabled(isEnabled);
        return;
    }
    if (name == "WebGLDraftExtensions") {
        setWebGLDraftExtensionsEnabled(isEnabled);
        return;
    }
    if (name == "WebGLImageChromium") {
        setWebGLImageChromiumEnabled(isEnabled);
        return;
    }
    if (name == "WebUSB") {
        setWebUSBEnabled(isEnabled);
        return;
    }
    if (name == "WebVR") {
        setWebVREnabled(isEnabled);
        return;
    }
    if (name == "WebVTTRegions") {
        setWebVTTRegionsEnabled(isEnabled);
        return;
    }
    if (name == "V8BasedStructuredClone") {
        setV8BasedStructuredCloneEnabled(isEnabled);
        return;
    }
    if (name == "V8IdleTasks") {
        setV8IdleTasksEnabled(isEnabled);
        return;
    }
    if (name == "VideoFullscreenOrientationLock") {
        setVideoFullscreenOrientationLockEnabled(isEnabled);
        return;
    }
    if (name == "VisibilityChangeOnUnload") {
        setVisibilityChangeOnUnloadEnabled(isEnabled);
        return;
    }
    if (name == "XSLT") {
        setXSLTEnabled(isEnabled);
        return;
    }
    if (name == "smil") {
        setsmilEnabled(isEnabled);
        return;
    }
    if (name == "ScrollCustomization") {
        setScrollCustomizationEnabled(isEnabled);
        return;
    }
    if (name == "AutoplayMutedVideos") {
        setAutoplayMutedVideosEnabled(isEnabled);
        return;
    }
    if (name == "VisualViewportAPI") {
        setVisualViewportAPIEnabled(isEnabled);
        return;
    }
    if (name == "WakeLock") {
        setWakeLockEnabled(isEnabled);
        return;
    }
    if (name == "WebFontsCacheAwareTimeoutAdaptation") {
        setWebFontsCacheAwareTimeoutAdaptationEnabled(isEnabled);
        return;
    }
    if (name == "WebFontsInterventionV2With2G") {
        setWebFontsInterventionV2With2GEnabled(isEnabled);
        return;
    }
    if (name == "WebFontsInterventionV2With3G") {
        setWebFontsInterventionV2With3GEnabled(isEnabled);
        return;
    }
    if (name == "WebFontsInterventionV2WithSlow2G") {
        setWebFontsInterventionV2WithSlow2GEnabled(isEnabled);
        return;
    }
    if (name == "WebFontsInterventionTrigger") {
        setWebFontsInterventionTriggerEnabled(isEnabled);
        return;
    }
    if (name == "WebShare") {
        setWebShareEnabled(isEnabled);
        return;
    }
    if (name == "Worklet") {
        setWorkletEnabled(isEnabled);
        return;
    }
    if (name == "LazyParseCSS") {
        setLazyParseCSSEnabled(isEnabled);
        return;
    }
    if (name == "ParseHTMLOnMainThread") {
        setParseHTMLOnMainThreadEnabled(isEnabled);
        return;
    }
    if (name == "SendBeaconThrowForBlobWithNonSimpleType") {
        setSendBeaconThrowForBlobWithNonSimpleTypeEnabled(isEnabled);
        return;
    }
    if (name == "PerformanceNavigationTiming2") {
        setPerformanceNavigationTiming2Enabled(isEnabled);
        return;
    }
    if (name == "BackgroundVideoTrackOptimization") {
        setBackgroundVideoTrackOptimizationEnabled(isEnabled);
        return;
    }
    if (name == "PerformancePaintTiming") {
        setPerformancePaintTimingEnabled(isEnabled);
        return;
    }
    if (name == "HideNonceContentAttribute") {
        setHideNonceContentAttributeEnabled(isEnabled);
        return;
    }
    if (name == "UnclosedFormControlIsInvalid") {
        setUnclosedFormControlIsInvalidEnabled(isEnabled);
        return;
    }
    if (name == "RestrictCompleteURLCharacterSet") {
        setRestrictCompleteURLCharacterSetEnabled(isEnabled);
        return;
    }
    DLOG(ERROR) << "RuntimeEnabledFeature not recognized: " << name;
}

bool RuntimeEnabledFeatures::isAccelerated2dCanvasEnabled = true;
bool RuntimeEnabledFeatures::isAudioOutputDevicesEnabled = true;
bool RuntimeEnabledFeatures::isAudioVideoTracksEnabled = false;
bool RuntimeEnabledFeatures::isAudioWorkletEnabled = false;
bool RuntimeEnabledFeatures::isAuxclickEnabled = true;
bool RuntimeEnabledFeatures::isCoalescedEventsEnabled = false;
bool RuntimeEnabledFeatures::isBackgroundSyncEnabled = true;
bool RuntimeEnabledFeatures::isBackspaceDefaultHandlerEnabled = false;
bool RuntimeEnabledFeatures::isBroadcastChannelEnabled = true;
bool RuntimeEnabledFeatures::isBudgetEnabled = false;
bool RuntimeEnabledFeatures::isCanvas2dFixedRenderingModeEnabled = false;
bool RuntimeEnabledFeatures::isEnableCanvas2dDynamicRenderingModeSwitchingEnabled = false;
bool RuntimeEnabledFeatures::isCanMakePaymentEnabled = true;
bool RuntimeEnabledFeatures::isCanvas2dImageChromiumEnabled = false;
bool RuntimeEnabledFeatures::isClientHintsEnabled = true;
bool RuntimeEnabledFeatures::isCompositeOpaqueFixedPositionEnabled = false;
bool RuntimeEnabledFeatures::isCompositeOpaqueScrollersEnabled = true;
bool RuntimeEnabledFeatures::isColorCorrectRenderingEnabled = false;
bool RuntimeEnabledFeatures::isColorCorrectRenderingDefaultModeEnabled = false;
bool RuntimeEnabledFeatures::isCompositedSelectionUpdateEnabled = false;
bool RuntimeEnabledFeatures::isCompositorWorkerEnabled = false;
bool RuntimeEnabledFeatures::isContextMenuEnabled = false;
bool RuntimeEnabledFeatures::isCorsRFC1918Enabled = false;
bool RuntimeEnabledFeatures::isCredentialManagerEnabled = true;
bool RuntimeEnabledFeatures::isCSS3TextEnabled = false;
bool RuntimeEnabledFeatures::isCSS3TextDecorationsEnabled = true;
bool RuntimeEnabledFeatures::isCSSApplyAtRulesEnabled = false;
bool RuntimeEnabledFeatures::isCSSAdditiveAnimationsEnabled = false;
bool RuntimeEnabledFeatures::isCSSBackdropFilterEnabled = false;
bool RuntimeEnabledFeatures::isCSSHexAlphaColorEnabled = false;
bool RuntimeEnabledFeatures::isCSSContainmentEnabled = true;
bool RuntimeEnabledFeatures::isCSSFontDisplayEnabled = false;
bool RuntimeEnabledFeatures::isCSSFontSizeAdjustEnabled = false;
bool RuntimeEnabledFeatures::isCSSGridLayoutEnabled = true;
bool RuntimeEnabledFeatures::isCSSDisplayContentsEnabled = false;
bool RuntimeEnabledFeatures::isCSSHyphensEnabled = true;
bool RuntimeEnabledFeatures::isCSSInBodyDoesNotBlockPaintEnabled = false;
bool RuntimeEnabledFeatures::isCSSIndependentTransformPropertiesEnabled = false;
bool RuntimeEnabledFeatures::isCSSMaskSourceTypeEnabled = false;
bool RuntimeEnabledFeatures::isCSSOMSmoothScrollEnabled = false;
bool RuntimeEnabledFeatures::isCSSOffsetPositionAnchorEnabled = false;
bool RuntimeEnabledFeatures::isCSSOffsetRotateEnabled = true;
bool RuntimeEnabledFeatures::isCSSOffsetRotationEnabled = true;
bool RuntimeEnabledFeatures::isCSSPaintAPIEnabled = false;
bool RuntimeEnabledFeatures::isCSSPaintAPIArgumentsEnabled = false;
bool RuntimeEnabledFeatures::isCSSSnapSizeEnabled = false;
bool RuntimeEnabledFeatures::isCSSStickyPositionEnabled = true;
bool RuntimeEnabledFeatures::isCSSTouchActionPanDirectionsEnabled = true;
bool RuntimeEnabledFeatures::isCSSTouchActionPinchZoomEnabled = true;
bool RuntimeEnabledFeatures::isCSSTypedOMEnabled = false;
bool RuntimeEnabledFeatures::isCSSVariableFontsEnabled = false;
bool RuntimeEnabledFeatures::isCSSVariables2Enabled = false;
bool RuntimeEnabledFeatures::isCSSViewportEnabled = false;
bool RuntimeEnabledFeatures::isCSSScrollSnapPointsEnabled = false;
bool RuntimeEnabledFeatures::isCustomElementsBuiltinEnabled = false;
bool RuntimeEnabledFeatures::isCustomElementsV1Enabled = true;
bool RuntimeEnabledFeatures::isCustomSchemeHandlerEnabled = false;
bool RuntimeEnabledFeatures::isDatabaseEnabled = true;
bool RuntimeEnabledFeatures::isDecodeToYUVEnabled = false;
bool RuntimeEnabledFeatures::isDesktopCaptureDisableLocalEchoControlEnabled = false;
bool RuntimeEnabledFeatures::isDeviceLightEnabled = false;
bool RuntimeEnabledFeatures::isDisplayList2dCanvasEnabled = true;
bool RuntimeEnabledFeatures::isDocumentCookieEnabled = false;
bool RuntimeEnabledFeatures::isDocumentDomainEnabled = false;
bool RuntimeEnabledFeatures::isDocumentWriteEnabled = false;
bool RuntimeEnabledFeatures::isDocumentWriteEvaluatorEnabled = false;
bool RuntimeEnabledFeatures::isDOMConvenienceAPIEnabled = true;
bool RuntimeEnabledFeatures::isDurableStorageEnabled = true;
bool RuntimeEnabledFeatures::isExpensiveBackgroundTimerThrottlingEnabled = false;
bool RuntimeEnabledFeatures::isFasterLocationReloadEnabled = false;
bool RuntimeEnabledFeatures::isFontCacheScalingEnabled = false;
bool RuntimeEnabledFeatures::isForceDisplayList2dCanvasEnabled = false;
bool RuntimeEnabledFeatures::isForceDisable2dCanvasCopyOnWriteEnabled = false;
bool RuntimeEnabledFeatures::isEmbedderCSPEnforcementEnabled = false;
bool RuntimeEnabledFeatures::isExecCommandInJavaScriptEnabled = false;
bool RuntimeEnabledFeatures::isComputedAccessibilityInfoEnabled = false;
bool RuntimeEnabledFeatures::isExperimentalCanvasFeaturesEnabled = false;
bool RuntimeEnabledFeatures::isExperimentalContentSecurityPolicyFeaturesEnabled = false;
bool RuntimeEnabledFeatures::isExperimentalV8ExtrasEnabled = false;
bool RuntimeEnabledFeatures::isFastMobileScrollingEnabled = false;
bool RuntimeEnabledFeatures::isFeaturePolicyEnabled = false;
bool RuntimeEnabledFeatures::isFileAPIBlobCloseEnabled = false;
bool RuntimeEnabledFeatures::isFileSystemEnabled = true;
bool RuntimeEnabledFeatures::isForeignFetchEnabled = false;
bool RuntimeEnabledFeatures::isFramebustingNeedsSameOriginOrUserGestureEnabled = false;
bool RuntimeEnabledFeatures::isFullscreenUnprefixedEnabled = false;
bool RuntimeEnabledFeatures::isFrameTimingSupportEnabled = false;
bool RuntimeEnabledFeatures::isGamepadExtensionsEnabled = false;
bool RuntimeEnabledFeatures::isGeometryInterfacesEnabled = false;
bool RuntimeEnabledFeatures::isGetUserMediaEnabled = true;
bool RuntimeEnabledFeatures::isGlobalCacheStorageEnabled = true;
bool RuntimeEnabledFeatures::isHeapCompactionEnabled = false;
bool RuntimeEnabledFeatures::isIDBObserverEnabled = false;
bool RuntimeEnabledFeatures::isIdleTimeSpellCheckingEnabled = false;
bool RuntimeEnabledFeatures::isImageCaptureEnabled = false;
bool RuntimeEnabledFeatures::isImageOrientationEnabled = false;
bool RuntimeEnabledFeatures::isIndexedDBExperimentalEnabled = false;
bool RuntimeEnabledFeatures::isInertTopControlsEnabled = true;
bool RuntimeEnabledFeatures::isInputEventEnabled = false;
bool RuntimeEnabledFeatures::isInputModeAttributeEnabled = false;
bool RuntimeEnabledFeatures::isInputMultipleFieldsUIEnabled = true;
bool RuntimeEnabledFeatures::isInstalledAppEnabled = false;
bool RuntimeEnabledFeatures::isIntersectionObserverEnabled = true;
bool RuntimeEnabledFeatures::isLangAttributeAwareFormControlUIEnabled = false;
bool RuntimeEnabledFeatures::isLayoutNGEnabled = false;
bool RuntimeEnabledFeatures::isLayoutNGInlineEnabled = false;
bool RuntimeEnabledFeatures::isLinkServiceWorkerEnabled = false;
bool RuntimeEnabledFeatures::isLongTaskObserverEnabled = false;
bool RuntimeEnabledFeatures::isFractionalScrollOffsetsEnabled = false;
bool RuntimeEnabledFeatures::isLoadingWithMojoEnabled = false;
bool RuntimeEnabledFeatures::isMediaCaptureEnabled = false;
bool RuntimeEnabledFeatures::isMediaCaptureFromCanvasEnabled = true;
bool RuntimeEnabledFeatures::isMediaCaptureFromVideoEnabled = false;
bool RuntimeEnabledFeatures::isMediaConstraintsEnabled = true;
bool RuntimeEnabledFeatures::isMediaDocumentDownloadButtonEnabled = false;
bool RuntimeEnabledFeatures::isMediaGetSettingsEnabled = false;
bool RuntimeEnabledFeatures::isMediaSessionEnabled = false;
bool RuntimeEnabledFeatures::isMediaSourceExperimentalEnabled = false;
bool RuntimeEnabledFeatures::isMediaSourceNewAbortAndDurationEnabled = false;
bool RuntimeEnabledFeatures::isMediaStreamSpeechEnabled = false;
bool RuntimeEnabledFeatures::isMediaQueryShapeEnabled = false;
bool RuntimeEnabledFeatures::isMediaStreamTrackContentHintEnabled = false;
bool RuntimeEnabledFeatures::isMemoryInfoInWorkersEnabled = false;
bool RuntimeEnabledFeatures::isMiddleClickAutoscrollEnabled = false;
bool RuntimeEnabledFeatures::isMobileLayoutThemeEnabled = false;
bool RuntimeEnabledFeatures::isModuleScriptsEnabled = false;
bool RuntimeEnabledFeatures::isNavigatorContentUtilsEnabled = false;
bool RuntimeEnabledFeatures::isWebNFCEnabled = false;
bool RuntimeEnabledFeatures::isNetworkInformationEnabled = true;
bool RuntimeEnabledFeatures::isNetInfoDownlinkMaxEnabled = true;
bool RuntimeEnabledFeatures::isNotificationConstructorEnabled = true;
bool RuntimeEnabledFeatures::isNotificationBadgeEnabled = true;
bool RuntimeEnabledFeatures::isNotificationContentImageEnabled = true;
bool RuntimeEnabledFeatures::isNotificationInlineRepliesEnabled = false;
bool RuntimeEnabledFeatures::isNotificationsEnabled = true;
bool RuntimeEnabledFeatures::isOnDeviceChangeEnabled = true;
bool RuntimeEnabledFeatures::isOrientationEventEnabled = false;
bool RuntimeEnabledFeatures::isOriginTrialsEnabled = true;
bool RuntimeEnabledFeatures::isOriginTrialsSampleAPIEnabled = false;
bool RuntimeEnabledFeatures::isForceOverlayFullscreenVideoEnabled = false;
bool RuntimeEnabledFeatures::isOverlayScrollbarsEnabled = false;
bool RuntimeEnabledFeatures::isPagePopupEnabled = true;
bool RuntimeEnabledFeatures::isPaintUnderInvalidationCheckingEnabled = false;
bool RuntimeEnabledFeatures::isPassiveDocumentEventListenersEnabled = true;
bool RuntimeEnabledFeatures::isPassPaintVisualRectToCompositorEnabled = false;
bool RuntimeEnabledFeatures::isPaymentAppEnabled = false;
bool RuntimeEnabledFeatures::isPaymentDetailsErrorEnabled = true;
bool RuntimeEnabledFeatures::isPaymentDetailsModifierDataEnabled = false;
bool RuntimeEnabledFeatures::isPaymentRequestEnabled = false;
bool RuntimeEnabledFeatures::isPaymentRequestBasicCardEnabled = true;
bool RuntimeEnabledFeatures::isPaymentRequestPayerNameEnabled = true;
bool RuntimeEnabledFeatures::isPerformanceObserverEnabled = true;
bool RuntimeEnabledFeatures::isPermissionDelegationEnabled = false;
bool RuntimeEnabledFeatures::isPermissionsEnabled = true;
bool RuntimeEnabledFeatures::isPermissionsRequestRevokeEnabled = false;
bool RuntimeEnabledFeatures::isPointerEventEnabled = true;
bool RuntimeEnabledFeatures::isPreciseMemoryInfoEnabled = false;
bool RuntimeEnabledFeatures::isPreferredImageRasterBoundsEnabled = false;
bool RuntimeEnabledFeatures::isPrefixedVideoFullscreenEnabled = true;
bool RuntimeEnabledFeatures::isPresentationEnabled = true;
bool RuntimeEnabledFeatures::isPresentationReceiverEnabled = false;
bool RuntimeEnabledFeatures::isPushMessagingEnabled = true;
bool RuntimeEnabledFeatures::isQuotaPromiseEnabled = false;
bool RuntimeEnabledFeatures::isReducedReferrerGranularityEnabled = false;
bool RuntimeEnabledFeatures::isRemotePlaybackEnabled = true;
bool RuntimeEnabledFeatures::isRenderingPipelineThrottlingEnabled = true;
bool RuntimeEnabledFeatures::isRenderingPipelineThrottlingLoadingIframesEnabled = true;
bool RuntimeEnabledFeatures::isRenderUnicodeControlCharactersEnabled = true;
bool RuntimeEnabledFeatures::isResizeObserverEnabled = false;
bool RuntimeEnabledFeatures::isRootLayerScrollingEnabled = false;
bool RuntimeEnabledFeatures::isRTCPeerConnectionNewGetStatsEnabled = false;
bool RuntimeEnabledFeatures::isScriptedSpeechEnabled = true;
bool RuntimeEnabledFeatures::isScrollAnchoringEnabled = false;
bool RuntimeEnabledFeatures::isScrollTopLeftInteropEnabled = false;
bool RuntimeEnabledFeatures::isSensorEnabled = false;
bool RuntimeEnabledFeatures::isServiceWorkerNavigationPreloadEnabled = false;
bool RuntimeEnabledFeatures::isSetRootScrollerEnabled = false;
bool RuntimeEnabledFeatures::isShadowPiercingDescendantCombinatorEnabled = false;
bool RuntimeEnabledFeatures::isShapeDetectionEnabled = false;
bool RuntimeEnabledFeatures::isSharedArrayBufferEnabled = false;
bool RuntimeEnabledFeatures::isSharedWorkerEnabled = true;
bool RuntimeEnabledFeatures::isSlimmingPaintInvalidationEnabled = false;
bool RuntimeEnabledFeatures::isSlimmingPaintV2Enabled = false;
bool RuntimeEnabledFeatures::isSlimmingPaintStrictCullRectClippingEnabled = false;
bool RuntimeEnabledFeatures::isStableBlinkFeaturesEnabled = true;
bool RuntimeEnabledFeatures::isStackedCSSPropertyAnimationsEnabled = false;
bool RuntimeEnabledFeatures::isStyleSharingEnabled = true;
bool RuntimeEnabledFeatures::isSpeculativeLaunchServiceWorkerEnabled = false;
bool RuntimeEnabledFeatures::isStorageEstimateEnabled = false;
bool RuntimeEnabledFeatures::isSuboriginsEnabled = false;
bool RuntimeEnabledFeatures::isTimerThrottlingForBackgroundTabsEnabled = true;
bool RuntimeEnabledFeatures::isTimerThrottlingForHiddenFramesEnabled = true;
bool RuntimeEnabledFeatures::isTopNavWithUserActivationInSandboxEnabled = false;
bool RuntimeEnabledFeatures::isTouchEventFeatureDetectionEnabled = true;
bool RuntimeEnabledFeatures::isTraceWrappablesEnabled = true;
bool RuntimeEnabledFeatures::isTrueColorRenderingEnabled = false;
bool RuntimeEnabledFeatures::isTrustedEventsDefaultActionEnabled = true;
bool RuntimeEnabledFeatures::isUserSelectAllEnabled = true;
bool RuntimeEnabledFeatures::isWebAnimationsAPIEnabled = false;
bool RuntimeEnabledFeatures::isWebAnimationsSVGEnabled = false;
bool RuntimeEnabledFeatures::isWebAssemblySerializationEnabled = false;
bool RuntimeEnabledFeatures::isWebBluetoothEnabled = false;
bool RuntimeEnabledFeatures::isWebGLDraftExtensionsEnabled = false;
bool RuntimeEnabledFeatures::isWebGLImageChromiumEnabled = false;
bool RuntimeEnabledFeatures::isWebUSBEnabled = false;
bool RuntimeEnabledFeatures::isWebVREnabled = false;
bool RuntimeEnabledFeatures::isWebVTTRegionsEnabled = false;
bool RuntimeEnabledFeatures::isV8BasedStructuredCloneEnabled = true;
bool RuntimeEnabledFeatures::isV8IdleTasksEnabled = false;
bool RuntimeEnabledFeatures::isVideoFullscreenOrientationLockEnabled = false;
bool RuntimeEnabledFeatures::isVisibilityChangeOnUnloadEnabled = true;
bool RuntimeEnabledFeatures::isXSLTEnabled = true;
bool RuntimeEnabledFeatures::issmilEnabled = true;
bool RuntimeEnabledFeatures::isScrollCustomizationEnabled = false;
bool RuntimeEnabledFeatures::isAutoplayMutedVideosEnabled = false;
bool RuntimeEnabledFeatures::isVisualViewportAPIEnabled = false;
bool RuntimeEnabledFeatures::isWakeLockEnabled = false;
bool RuntimeEnabledFeatures::isWebFontsCacheAwareTimeoutAdaptationEnabled = false;
bool RuntimeEnabledFeatures::isWebFontsInterventionV2With2GEnabled = false;
bool RuntimeEnabledFeatures::isWebFontsInterventionV2With3GEnabled = false;
bool RuntimeEnabledFeatures::isWebFontsInterventionV2WithSlow2GEnabled = false;
bool RuntimeEnabledFeatures::isWebFontsInterventionTriggerEnabled = false;
bool RuntimeEnabledFeatures::isWebShareEnabled = false;
bool RuntimeEnabledFeatures::isWorkletEnabled = false;
bool RuntimeEnabledFeatures::isLazyParseCSSEnabled = false;
bool RuntimeEnabledFeatures::isParseHTMLOnMainThreadEnabled = false;
bool RuntimeEnabledFeatures::isSendBeaconThrowForBlobWithNonSimpleTypeEnabled = false;
bool RuntimeEnabledFeatures::isPerformanceNavigationTiming2Enabled = true;
bool RuntimeEnabledFeatures::isBackgroundVideoTrackOptimizationEnabled = true;
bool RuntimeEnabledFeatures::isPerformancePaintTimingEnabled = false;
bool RuntimeEnabledFeatures::isHideNonceContentAttributeEnabled = false;
bool RuntimeEnabledFeatures::isUnclosedFormControlIsInvalidEnabled = false;
bool RuntimeEnabledFeatures::isRestrictCompleteURLCharacterSetEnabled = false;

} // namespace blink
