// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "InternalSettingsGenerated.h"

#include "core/frame/Settings.h"
#include "core/page/Page.h"

namespace blink {

InternalSettingsGenerated::InternalSettingsGenerated(Page* page)
    : m_page(page)
    , m_DOMPasteAllowed(page->settings().getDOMPasteAllowed())
    , m_accelerated2dCanvasMSAASampleCount(page->settings().getAccelerated2dCanvasMSAASampleCount())
    , m_acceleratedCompositingEnabled(page->settings().getAcceleratedCompositingEnabled())
    , m_accessibilityEnabled(page->settings().getAccessibilityEnabled())
    , m_accessibilityFontScaleFactor(page->settings().getAccessibilityFontScaleFactor())
    , m_accessibilityPasswordValuesEnabled(page->settings().getAccessibilityPasswordValuesEnabled())
    , m_allowCustomScrollbarInMainFrame(page->settings().getAllowCustomScrollbarInMainFrame())
    , m_allowFileAccessFromFileURLs(page->settings().getAllowFileAccessFromFileURLs())
    , m_allowGeolocationOnInsecureOrigins(page->settings().getAllowGeolocationOnInsecureOrigins())
    , m_allowRunningOfInsecureContent(page->settings().getAllowRunningOfInsecureContent())
    , m_allowScriptsToCloseWindows(page->settings().getAllowScriptsToCloseWindows())
    , m_allowUniversalAccessFromFileURLs(page->settings().getAllowUniversalAccessFromFileURLs())
    , m_alwaysShowContextMenuOnTouch(page->settings().getAlwaysShowContextMenuOnTouch())
    , m_antialiased2dCanvasEnabled(page->settings().getAntialiased2dCanvasEnabled())
    , m_antialiasedClips2dCanvasEnabled(page->settings().getAntialiasedClips2dCanvasEnabled())
    , m_availableHoverTypes(page->settings().getAvailableHoverTypes())
    , m_availablePointerTypes(page->settings().getAvailablePointerTypes())
    , m_backgroundHtmlParserOutstandingTokenLimit(page->settings().getBackgroundHtmlParserOutstandingTokenLimit())
    , m_backgroundHtmlParserPendingTokenLimit(page->settings().getBackgroundHtmlParserPendingTokenLimit())
    , m_browserSideNavigationEnabled(page->settings().getBrowserSideNavigationEnabled())
    , m_cookieEnabled(page->settings().getCookieEnabled())
    , m_crossOriginMediaPlaybackRequiresUserGesture(page->settings().getCrossOriginMediaPlaybackRequiresUserGesture())
    , m_cssExternalScannerNoPreload(page->settings().getCSSExternalScannerNoPreload())
    , m_cssExternalScannerPreload(page->settings().getCSSExternalScannerPreload())
    , m_dataSaverEnabled(page->settings().getDataSaverEnabled())
    , m_defaultFixedFontSize(page->settings().getDefaultFixedFontSize())
    , m_defaultFontSize(page->settings().getDefaultFontSize())
    , m_defaultTextEncodingName(page->settings().getDefaultTextEncodingName())
    , m_defaultVideoPosterURL(page->settings().getDefaultVideoPosterURL())
    , m_deviceScaleAdjustment(page->settings().getDeviceScaleAdjustment())
    , m_deviceSupportsTouch(page->settings().getDeviceSupportsTouch())
    , m_disableReadingFromCanvas(page->settings().getDisableReadingFromCanvas())
    , m_disallowFetchForDocWrittenScriptsInMainFrame(page->settings().getDisallowFetchForDocWrittenScriptsInMainFrame())
    , m_disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(page->settings().getDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G())
    , m_disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(page->settings().getDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections())
    , m_dnsPrefetchingEnabled(page->settings().getDNSPrefetchingEnabled())
    , m_doHtmlPreloadScanning(page->settings().getDoHtmlPreloadScanning())
    , m_downloadableBinaryFontsEnabled(page->settings().getDownloadableBinaryFontsEnabled())
    , m_encryptedMediaEnabled(page->settings().getEncryptedMediaEnabled())
    , m_fetchImagePlaceholders(page->settings().getFetchImagePlaceholders())
    , m_forceMainWorldInitialization(page->settings().getForceMainWorldInitialization())
    , m_forcePreloadNoneForMediaElements(page->settings().getForcePreloadNoneForMediaElements())
    , m_forceZeroLayoutHeight(page->settings().getForceZeroLayoutHeight())
    , m_fullscreenSupported(page->settings().getFullscreenSupported())
    , m_hideDownloadUI(page->settings().getHideDownloadUI())
    , m_hideScrollbars(page->settings().getHideScrollbars())
    , m_historyEntryRequiresUserGesture(page->settings().getHistoryEntryRequiresUserGesture())
    , m_hyperlinkAuditingEnabled(page->settings().getHyperlinkAuditingEnabled())
    , m_ignoreMainFrameOverflowHiddenQuirk(page->settings().getIgnoreMainFrameOverflowHiddenQuirk())
    , m_imagesEnabled(page->settings().getImagesEnabled())
    , m_inertVisualViewport(page->settings().getInertVisualViewport())
    , m_inlineTextBoxAccessibilityEnabled(page->settings().getInlineTextBoxAccessibilityEnabled())
    , m_javaScriptCanAccessClipboard(page->settings().getJavaScriptCanAccessClipboard())
    , m_javaScriptCanOpenWindowsAutomatically(page->settings().getJavaScriptCanOpenWindowsAutomatically())
    , m_layerSquashingEnabled(page->settings().getLayerSquashingEnabled())
    , m_loadWithOverviewMode(page->settings().getLoadWithOverviewMode())
    , m_loadsImagesAutomatically(page->settings().getLoadsImagesAutomatically())
    , m_localStorageEnabled(page->settings().getLocalStorageEnabled())
    , m_logDnsPrefetchAndPreconnect(page->settings().getLogDnsPrefetchAndPreconnect())
    , m_logPreload(page->settings().getLogPreload())
    , m_lowPriorityIframes(page->settings().getLowPriorityIframes())
    , m_mainFrameClipsContent(page->settings().getMainFrameClipsContent())
    , m_mainFrameResizesAreOrientationChanges(page->settings().getMainFrameResizesAreOrientationChanges())
    , m_maxBeaconTransmission(page->settings().getMaxBeaconTransmission())
    , m_maxTouchPoints(page->settings().getMaxTouchPoints())
    , m_mediaControlsOverlayPlayButtonEnabled(page->settings().getMediaControlsOverlayPlayButtonEnabled())
    , m_mediaPlaybackRequiresUserGesture(page->settings().getMediaPlaybackRequiresUserGesture())
    , m_mediaTypeOverride(page->settings().getMediaTypeOverride())
    , m_minimumAccelerated2dCanvasSize(page->settings().getMinimumAccelerated2dCanvasSize())
    , m_minimumFontSize(page->settings().getMinimumFontSize())
    , m_minimumLogicalFontSize(page->settings().getMinimumLogicalFontSize())
    , m_mockGestureTapHighlightsEnabled(page->settings().getMockGestureTapHighlightsEnabled())
    , m_multiTargetTapNotificationEnabled(page->settings().getMultiTargetTapNotificationEnabled())
    , m_navigateOnDragDrop(page->settings().getNavigateOnDragDrop())
    , m_offlineWebApplicationCacheEnabled(page->settings().getOfflineWebApplicationCacheEnabled())
    , m_parseHTMLOnMainThreadCoalesceChunks(page->settings().getParseHTMLOnMainThreadCoalesceChunks())
    , m_parseHTMLOnMainThreadSyncTokenize(page->settings().getParseHTMLOnMainThreadSyncTokenize())
    , m_passwordEchoDurationInSeconds(page->settings().getPasswordEchoDurationInSeconds())
    , m_passwordEchoEnabled(page->settings().getPasswordEchoEnabled())
    , m_pluginsEnabled(page->settings().getPluginsEnabled())
    , m_preferCompositingToLCDTextEnabled(page->settings().getPreferCompositingToLCDTextEnabled())
    , m_preferHiddenVolumeControls(page->settings().getPreferHiddenVolumeControls())
    , m_presentationReceiver(page->settings().getPresentationReceiver())
    , m_presentationRequiresUserGesture(page->settings().getPresentationRequiresUserGesture())
    , m_reportScreenSizeInPhysicalPixelsQuirk(page->settings().getReportScreenSizeInPhysicalPixelsQuirk())
    , m_rubberBandingOnCompositorThread(page->settings().getRubberBandingOnCompositorThread())
    , m_scriptEnabled(page->settings().getScriptEnabled())
    , m_scrollAnimatorEnabled(page->settings().getScrollAnimatorEnabled())
    , m_selectTrailingWhitespaceEnabled(page->settings().getSelectTrailingWhitespaceEnabled())
    , m_selectionIncludesAltImageText(page->settings().getSelectionIncludesAltImageText())
    , m_shouldClearDocumentBackground(page->settings().getShouldClearDocumentBackground())
    , m_shouldPrintBackgrounds(page->settings().getShouldPrintBackgrounds())
    , m_shouldRespectImageOrientation(page->settings().getShouldRespectImageOrientation())
    , m_shouldReuseGlobalForUnownedMainFrame(page->settings().getShouldReuseGlobalForUnownedMainFrame())
    , m_showContextMenuOnMouseUp(page->settings().getShowContextMenuOnMouseUp())
    , m_smartInsertDeleteEnabled(page->settings().getSmartInsertDeleteEnabled())
    , m_spatialNavigationEnabled(page->settings().getSpatialNavigationEnabled())
    , m_spellCheckEnabledByDefault(page->settings().getSpellCheckEnabledByDefault())
    , m_strictMixedContentChecking(page->settings().getStrictMixedContentChecking())
    , m_strictMixedContentCheckingForPlugin(page->settings().getStrictMixedContentCheckingForPlugin())
    , m_strictPowerfulFeatureRestrictions(page->settings().getStrictPowerfulFeatureRestrictions())
    , m_strictlyBlockBlockableMixedContent(page->settings().getStrictlyBlockBlockableMixedContent())
    , m_supportsMultipleWindows(page->settings().getSupportsMultipleWindows())
    , m_syncXHRInDocumentsEnabled(page->settings().getSyncXHRInDocumentsEnabled())
    , m_textAreasAreResizable(page->settings().getTextAreasAreResizable())
    , m_textTrackBackgroundColor(page->settings().getTextTrackBackgroundColor())
    , m_textTrackFontFamily(page->settings().getTextTrackFontFamily())
    , m_textTrackFontStyle(page->settings().getTextTrackFontStyle())
    , m_textTrackFontVariant(page->settings().getTextTrackFontVariant())
    , m_textTrackMarginPercentage(page->settings().getTextTrackMarginPercentage())
    , m_textTrackTextColor(page->settings().getTextTrackTextColor())
    , m_textTrackTextShadow(page->settings().getTextTrackTextShadow())
    , m_textTrackTextSize(page->settings().getTextTrackTextSize())
    , m_threadedScrollingEnabled(page->settings().getThreadedScrollingEnabled())
    , m_touchAdjustmentEnabled(page->settings().getTouchAdjustmentEnabled())
    , m_touchDragDropEnabled(page->settings().getTouchDragDropEnabled())
    , m_touchEditingEnabled(page->settings().getTouchEditingEnabled())
    , m_useDefaultImageInterpolationQuality(page->settings().getUseDefaultImageInterpolationQuality())
    , m_useLegacyBackgroundSizeShorthandBehavior(page->settings().getUseLegacyBackgroundSizeShorthandBehavior())
    , m_useSolidColorScrollbars(page->settings().getUseSolidColorScrollbars())
    , m_useWideViewport(page->settings().getUseWideViewport())
    , m_validationMessageTimerMagnification(page->settings().getValidationMessageTimerMagnification())
    , m_viewportEnabled(page->settings().getViewportEnabled())
    , m_viewportMetaEnabled(page->settings().getViewportMetaEnabled())
    , m_viewportMetaMergeContentQuirk(page->settings().getViewportMetaMergeContentQuirk())
    , m_viewportMetaZeroValuesQuirk(page->settings().getViewportMetaZeroValuesQuirk())
    , m_webGLEnabled(page->settings().getWebGLEnabled())
    , m_webGLErrorsToConsoleEnabled(page->settings().getWebGLErrorsToConsoleEnabled())
    , m_webSecurityEnabled(page->settings().getWebSecurityEnabled())
    , m_wideViewportQuirkEnabled(page->settings().getWideViewportQuirkEnabled())
    , m_xssAuditorEnabled(page->settings().getXSSAuditorEnabled())
{
}

InternalSettingsGenerated::~InternalSettingsGenerated() { }

void InternalSettingsGenerated::resetToConsistentState()
{
    m_page->settings().setDOMPasteAllowed(m_DOMPasteAllowed);
    m_page->settings().setAccelerated2dCanvasMSAASampleCount(m_accelerated2dCanvasMSAASampleCount);
    m_page->settings().setAcceleratedCompositingEnabled(m_acceleratedCompositingEnabled);
    m_page->settings().setAccessibilityEnabled(m_accessibilityEnabled);
    m_page->settings().setAccessibilityFontScaleFactor(m_accessibilityFontScaleFactor);
    m_page->settings().setAccessibilityPasswordValuesEnabled(m_accessibilityPasswordValuesEnabled);
    m_page->settings().setAllowCustomScrollbarInMainFrame(m_allowCustomScrollbarInMainFrame);
    m_page->settings().setAllowFileAccessFromFileURLs(m_allowFileAccessFromFileURLs);
    m_page->settings().setAllowGeolocationOnInsecureOrigins(m_allowGeolocationOnInsecureOrigins);
    m_page->settings().setAllowRunningOfInsecureContent(m_allowRunningOfInsecureContent);
    m_page->settings().setAllowScriptsToCloseWindows(m_allowScriptsToCloseWindows);
    m_page->settings().setAllowUniversalAccessFromFileURLs(m_allowUniversalAccessFromFileURLs);
    m_page->settings().setAlwaysShowContextMenuOnTouch(m_alwaysShowContextMenuOnTouch);
    m_page->settings().setAntialiased2dCanvasEnabled(m_antialiased2dCanvasEnabled);
    m_page->settings().setAntialiasedClips2dCanvasEnabled(m_antialiasedClips2dCanvasEnabled);
    m_page->settings().setAvailableHoverTypes(m_availableHoverTypes);
    m_page->settings().setAvailablePointerTypes(m_availablePointerTypes);
    m_page->settings().setBackgroundHtmlParserOutstandingTokenLimit(m_backgroundHtmlParserOutstandingTokenLimit);
    m_page->settings().setBackgroundHtmlParserPendingTokenLimit(m_backgroundHtmlParserPendingTokenLimit);
    m_page->settings().setBrowserSideNavigationEnabled(m_browserSideNavigationEnabled);
    m_page->settings().setCookieEnabled(m_cookieEnabled);
    m_page->settings().setCrossOriginMediaPlaybackRequiresUserGesture(m_crossOriginMediaPlaybackRequiresUserGesture);
    m_page->settings().setCSSExternalScannerNoPreload(m_cssExternalScannerNoPreload);
    m_page->settings().setCSSExternalScannerPreload(m_cssExternalScannerPreload);
    m_page->settings().setDataSaverEnabled(m_dataSaverEnabled);
    m_page->settings().setDefaultFixedFontSize(m_defaultFixedFontSize);
    m_page->settings().setDefaultFontSize(m_defaultFontSize);
    m_page->settings().setDefaultTextEncodingName(m_defaultTextEncodingName);
    m_page->settings().setDefaultVideoPosterURL(m_defaultVideoPosterURL);
    m_page->settings().setDeviceScaleAdjustment(m_deviceScaleAdjustment);
    m_page->settings().setDeviceSupportsTouch(m_deviceSupportsTouch);
    m_page->settings().setDisableReadingFromCanvas(m_disableReadingFromCanvas);
    m_page->settings().setDisallowFetchForDocWrittenScriptsInMainFrame(m_disallowFetchForDocWrittenScriptsInMainFrame);
    m_page->settings().setDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(m_disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G);
    m_page->settings().setDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(m_disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections);
    m_page->settings().setDNSPrefetchingEnabled(m_dnsPrefetchingEnabled);
    m_page->settings().setDoHtmlPreloadScanning(m_doHtmlPreloadScanning);
    m_page->settings().setDownloadableBinaryFontsEnabled(m_downloadableBinaryFontsEnabled);
    m_page->settings().setEncryptedMediaEnabled(m_encryptedMediaEnabled);
    m_page->settings().setFetchImagePlaceholders(m_fetchImagePlaceholders);
    m_page->settings().setForceMainWorldInitialization(m_forceMainWorldInitialization);
    m_page->settings().setForcePreloadNoneForMediaElements(m_forcePreloadNoneForMediaElements);
    m_page->settings().setForceZeroLayoutHeight(m_forceZeroLayoutHeight);
    m_page->settings().setFullscreenSupported(m_fullscreenSupported);
    m_page->settings().setHideDownloadUI(m_hideDownloadUI);
    m_page->settings().setHideScrollbars(m_hideScrollbars);
    m_page->settings().setHistoryEntryRequiresUserGesture(m_historyEntryRequiresUserGesture);
    m_page->settings().setHyperlinkAuditingEnabled(m_hyperlinkAuditingEnabled);
    m_page->settings().setIgnoreMainFrameOverflowHiddenQuirk(m_ignoreMainFrameOverflowHiddenQuirk);
    m_page->settings().setImagesEnabled(m_imagesEnabled);
    m_page->settings().setInertVisualViewport(m_inertVisualViewport);
    m_page->settings().setInlineTextBoxAccessibilityEnabled(m_inlineTextBoxAccessibilityEnabled);
    m_page->settings().setJavaScriptCanAccessClipboard(m_javaScriptCanAccessClipboard);
    m_page->settings().setJavaScriptCanOpenWindowsAutomatically(m_javaScriptCanOpenWindowsAutomatically);
    m_page->settings().setLayerSquashingEnabled(m_layerSquashingEnabled);
    m_page->settings().setLoadWithOverviewMode(m_loadWithOverviewMode);
    m_page->settings().setLoadsImagesAutomatically(m_loadsImagesAutomatically);
    m_page->settings().setLocalStorageEnabled(m_localStorageEnabled);
    m_page->settings().setLogDnsPrefetchAndPreconnect(m_logDnsPrefetchAndPreconnect);
    m_page->settings().setLogPreload(m_logPreload);
    m_page->settings().setLowPriorityIframes(m_lowPriorityIframes);
    m_page->settings().setMainFrameClipsContent(m_mainFrameClipsContent);
    m_page->settings().setMainFrameResizesAreOrientationChanges(m_mainFrameResizesAreOrientationChanges);
    m_page->settings().setMaxBeaconTransmission(m_maxBeaconTransmission);
    m_page->settings().setMaxTouchPoints(m_maxTouchPoints);
    m_page->settings().setMediaControlsOverlayPlayButtonEnabled(m_mediaControlsOverlayPlayButtonEnabled);
    m_page->settings().setMediaPlaybackRequiresUserGesture(m_mediaPlaybackRequiresUserGesture);
    m_page->settings().setMediaTypeOverride(m_mediaTypeOverride);
    m_page->settings().setMinimumAccelerated2dCanvasSize(m_minimumAccelerated2dCanvasSize);
    m_page->settings().setMinimumFontSize(m_minimumFontSize);
    m_page->settings().setMinimumLogicalFontSize(m_minimumLogicalFontSize);
    m_page->settings().setMockGestureTapHighlightsEnabled(m_mockGestureTapHighlightsEnabled);
    m_page->settings().setMultiTargetTapNotificationEnabled(m_multiTargetTapNotificationEnabled);
    m_page->settings().setNavigateOnDragDrop(m_navigateOnDragDrop);
    m_page->settings().setOfflineWebApplicationCacheEnabled(m_offlineWebApplicationCacheEnabled);
    m_page->settings().setParseHTMLOnMainThreadCoalesceChunks(m_parseHTMLOnMainThreadCoalesceChunks);
    m_page->settings().setParseHTMLOnMainThreadSyncTokenize(m_parseHTMLOnMainThreadSyncTokenize);
    m_page->settings().setPasswordEchoDurationInSeconds(m_passwordEchoDurationInSeconds);
    m_page->settings().setPasswordEchoEnabled(m_passwordEchoEnabled);
    m_page->settings().setPluginsEnabled(m_pluginsEnabled);
    m_page->settings().setPreferCompositingToLCDTextEnabled(m_preferCompositingToLCDTextEnabled);
    m_page->settings().setPreferHiddenVolumeControls(m_preferHiddenVolumeControls);
    m_page->settings().setPresentationReceiver(m_presentationReceiver);
    m_page->settings().setPresentationRequiresUserGesture(m_presentationRequiresUserGesture);
    m_page->settings().setReportScreenSizeInPhysicalPixelsQuirk(m_reportScreenSizeInPhysicalPixelsQuirk);
    m_page->settings().setRubberBandingOnCompositorThread(m_rubberBandingOnCompositorThread);
    m_page->settings().setScriptEnabled(m_scriptEnabled);
    m_page->settings().setScrollAnimatorEnabled(m_scrollAnimatorEnabled);
    m_page->settings().setSelectTrailingWhitespaceEnabled(m_selectTrailingWhitespaceEnabled);
    m_page->settings().setSelectionIncludesAltImageText(m_selectionIncludesAltImageText);
    m_page->settings().setShouldClearDocumentBackground(m_shouldClearDocumentBackground);
    m_page->settings().setShouldPrintBackgrounds(m_shouldPrintBackgrounds);
    m_page->settings().setShouldRespectImageOrientation(m_shouldRespectImageOrientation);
    m_page->settings().setShouldReuseGlobalForUnownedMainFrame(m_shouldReuseGlobalForUnownedMainFrame);
    m_page->settings().setShowContextMenuOnMouseUp(m_showContextMenuOnMouseUp);
    m_page->settings().setSmartInsertDeleteEnabled(m_smartInsertDeleteEnabled);
    m_page->settings().setSpatialNavigationEnabled(m_spatialNavigationEnabled);
    m_page->settings().setSpellCheckEnabledByDefault(m_spellCheckEnabledByDefault);
    m_page->settings().setStrictMixedContentChecking(m_strictMixedContentChecking);
    m_page->settings().setStrictMixedContentCheckingForPlugin(m_strictMixedContentCheckingForPlugin);
    m_page->settings().setStrictPowerfulFeatureRestrictions(m_strictPowerfulFeatureRestrictions);
    m_page->settings().setStrictlyBlockBlockableMixedContent(m_strictlyBlockBlockableMixedContent);
    m_page->settings().setSupportsMultipleWindows(m_supportsMultipleWindows);
    m_page->settings().setSyncXHRInDocumentsEnabled(m_syncXHRInDocumentsEnabled);
    m_page->settings().setTextAreasAreResizable(m_textAreasAreResizable);
    m_page->settings().setTextTrackBackgroundColor(m_textTrackBackgroundColor);
    m_page->settings().setTextTrackFontFamily(m_textTrackFontFamily);
    m_page->settings().setTextTrackFontStyle(m_textTrackFontStyle);
    m_page->settings().setTextTrackFontVariant(m_textTrackFontVariant);
    m_page->settings().setTextTrackMarginPercentage(m_textTrackMarginPercentage);
    m_page->settings().setTextTrackTextColor(m_textTrackTextColor);
    m_page->settings().setTextTrackTextShadow(m_textTrackTextShadow);
    m_page->settings().setTextTrackTextSize(m_textTrackTextSize);
    m_page->settings().setThreadedScrollingEnabled(m_threadedScrollingEnabled);
    m_page->settings().setTouchAdjustmentEnabled(m_touchAdjustmentEnabled);
    m_page->settings().setTouchDragDropEnabled(m_touchDragDropEnabled);
    m_page->settings().setTouchEditingEnabled(m_touchEditingEnabled);
    m_page->settings().setUseDefaultImageInterpolationQuality(m_useDefaultImageInterpolationQuality);
    m_page->settings().setUseLegacyBackgroundSizeShorthandBehavior(m_useLegacyBackgroundSizeShorthandBehavior);
    m_page->settings().setUseSolidColorScrollbars(m_useSolidColorScrollbars);
    m_page->settings().setUseWideViewport(m_useWideViewport);
    m_page->settings().setValidationMessageTimerMagnification(m_validationMessageTimerMagnification);
    m_page->settings().setViewportEnabled(m_viewportEnabled);
    m_page->settings().setViewportMetaEnabled(m_viewportMetaEnabled);
    m_page->settings().setViewportMetaMergeContentQuirk(m_viewportMetaMergeContentQuirk);
    m_page->settings().setViewportMetaZeroValuesQuirk(m_viewportMetaZeroValuesQuirk);
    m_page->settings().setWebGLEnabled(m_webGLEnabled);
    m_page->settings().setWebGLErrorsToConsoleEnabled(m_webGLErrorsToConsoleEnabled);
    m_page->settings().setWebSecurityEnabled(m_webSecurityEnabled);
    m_page->settings().setWideViewportQuirkEnabled(m_wideViewportQuirkEnabled);
    m_page->settings().setXSSAuditorEnabled(m_xssAuditorEnabled);
}

void InternalSettingsGenerated::setDOMPasteAllowed(bool DOMPasteAllowed)
{
    m_page->settings().setDOMPasteAllowed(DOMPasteAllowed);
}

void InternalSettingsGenerated::setAccelerated2dCanvasMSAASampleCount(int accelerated2dCanvasMSAASampleCount)
{
    m_page->settings().setAccelerated2dCanvasMSAASampleCount(accelerated2dCanvasMSAASampleCount);
}

void InternalSettingsGenerated::setAcceleratedCompositingEnabled(bool acceleratedCompositingEnabled)
{
    m_page->settings().setAcceleratedCompositingEnabled(acceleratedCompositingEnabled);
}

void InternalSettingsGenerated::setAccessibilityEnabled(bool accessibilityEnabled)
{
    m_page->settings().setAccessibilityEnabled(accessibilityEnabled);
}

void InternalSettingsGenerated::setAccessibilityFontScaleFactor(double accessibilityFontScaleFactor)
{
    m_page->settings().setAccessibilityFontScaleFactor(accessibilityFontScaleFactor);
}

void InternalSettingsGenerated::setAccessibilityPasswordValuesEnabled(bool accessibilityPasswordValuesEnabled)
{
    m_page->settings().setAccessibilityPasswordValuesEnabled(accessibilityPasswordValuesEnabled);
}

void InternalSettingsGenerated::setAllowCustomScrollbarInMainFrame(bool allowCustomScrollbarInMainFrame)
{
    m_page->settings().setAllowCustomScrollbarInMainFrame(allowCustomScrollbarInMainFrame);
}

void InternalSettingsGenerated::setAllowFileAccessFromFileURLs(bool allowFileAccessFromFileURLs)
{
    m_page->settings().setAllowFileAccessFromFileURLs(allowFileAccessFromFileURLs);
}

void InternalSettingsGenerated::setAllowGeolocationOnInsecureOrigins(bool allowGeolocationOnInsecureOrigins)
{
    m_page->settings().setAllowGeolocationOnInsecureOrigins(allowGeolocationOnInsecureOrigins);
}

void InternalSettingsGenerated::setAllowRunningOfInsecureContent(bool allowRunningOfInsecureContent)
{
    m_page->settings().setAllowRunningOfInsecureContent(allowRunningOfInsecureContent);
}

void InternalSettingsGenerated::setAllowScriptsToCloseWindows(bool allowScriptsToCloseWindows)
{
    m_page->settings().setAllowScriptsToCloseWindows(allowScriptsToCloseWindows);
}

void InternalSettingsGenerated::setAllowUniversalAccessFromFileURLs(bool allowUniversalAccessFromFileURLs)
{
    m_page->settings().setAllowUniversalAccessFromFileURLs(allowUniversalAccessFromFileURLs);
}

void InternalSettingsGenerated::setAlwaysShowContextMenuOnTouch(bool alwaysShowContextMenuOnTouch)
{
    m_page->settings().setAlwaysShowContextMenuOnTouch(alwaysShowContextMenuOnTouch);
}

void InternalSettingsGenerated::setAntialiased2dCanvasEnabled(bool antialiased2dCanvasEnabled)
{
    m_page->settings().setAntialiased2dCanvasEnabled(antialiased2dCanvasEnabled);
}

void InternalSettingsGenerated::setAntialiasedClips2dCanvasEnabled(bool antialiasedClips2dCanvasEnabled)
{
    m_page->settings().setAntialiasedClips2dCanvasEnabled(antialiasedClips2dCanvasEnabled);
}

void InternalSettingsGenerated::setAvailableHoverTypes(int availableHoverTypes)
{
    m_page->settings().setAvailableHoverTypes(availableHoverTypes);
}

void InternalSettingsGenerated::setAvailablePointerTypes(int availablePointerTypes)
{
    m_page->settings().setAvailablePointerTypes(availablePointerTypes);
}

void InternalSettingsGenerated::setBackgroundHtmlParserOutstandingTokenLimit(unsigned backgroundHtmlParserOutstandingTokenLimit)
{
    m_page->settings().setBackgroundHtmlParserOutstandingTokenLimit(backgroundHtmlParserOutstandingTokenLimit);
}

void InternalSettingsGenerated::setBackgroundHtmlParserPendingTokenLimit(unsigned backgroundHtmlParserPendingTokenLimit)
{
    m_page->settings().setBackgroundHtmlParserPendingTokenLimit(backgroundHtmlParserPendingTokenLimit);
}

void InternalSettingsGenerated::setBrowserSideNavigationEnabled(bool browserSideNavigationEnabled)
{
    m_page->settings().setBrowserSideNavigationEnabled(browserSideNavigationEnabled);
}

void InternalSettingsGenerated::setCookieEnabled(bool cookieEnabled)
{
    m_page->settings().setCookieEnabled(cookieEnabled);
}

void InternalSettingsGenerated::setCrossOriginMediaPlaybackRequiresUserGesture(bool crossOriginMediaPlaybackRequiresUserGesture)
{
    m_page->settings().setCrossOriginMediaPlaybackRequiresUserGesture(crossOriginMediaPlaybackRequiresUserGesture);
}

void InternalSettingsGenerated::setCSSExternalScannerNoPreload(bool cssExternalScannerNoPreload)
{
    m_page->settings().setCSSExternalScannerNoPreload(cssExternalScannerNoPreload);
}

void InternalSettingsGenerated::setCSSExternalScannerPreload(bool cssExternalScannerPreload)
{
    m_page->settings().setCSSExternalScannerPreload(cssExternalScannerPreload);
}

void InternalSettingsGenerated::setDataSaverEnabled(bool dataSaverEnabled)
{
    m_page->settings().setDataSaverEnabled(dataSaverEnabled);
}

void InternalSettingsGenerated::setDefaultFixedFontSize(int defaultFixedFontSize)
{
    m_page->settings().setDefaultFixedFontSize(defaultFixedFontSize);
}

void InternalSettingsGenerated::setDefaultFontSize(int defaultFontSize)
{
    m_page->settings().setDefaultFontSize(defaultFontSize);
}

void InternalSettingsGenerated::setDefaultTextEncodingName(const String& defaultTextEncodingName)
{
    m_page->settings().setDefaultTextEncodingName(defaultTextEncodingName);
}

void InternalSettingsGenerated::setDefaultVideoPosterURL(const String& defaultVideoPosterURL)
{
    m_page->settings().setDefaultVideoPosterURL(defaultVideoPosterURL);
}

void InternalSettingsGenerated::setDeviceScaleAdjustment(double deviceScaleAdjustment)
{
    m_page->settings().setDeviceScaleAdjustment(deviceScaleAdjustment);
}

void InternalSettingsGenerated::setDeviceSupportsTouch(bool deviceSupportsTouch)
{
    m_page->settings().setDeviceSupportsTouch(deviceSupportsTouch);
}

void InternalSettingsGenerated::setDisableReadingFromCanvas(bool disableReadingFromCanvas)
{
    m_page->settings().setDisableReadingFromCanvas(disableReadingFromCanvas);
}

void InternalSettingsGenerated::setDisallowFetchForDocWrittenScriptsInMainFrame(bool disallowFetchForDocWrittenScriptsInMainFrame)
{
    m_page->settings().setDisallowFetchForDocWrittenScriptsInMainFrame(disallowFetchForDocWrittenScriptsInMainFrame);
}

void InternalSettingsGenerated::setDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(bool disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G)
{
    m_page->settings().setDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G);
}

void InternalSettingsGenerated::setDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(bool disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections)
{
    m_page->settings().setDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections);
}

void InternalSettingsGenerated::setDNSPrefetchingEnabled(bool dnsPrefetchingEnabled)
{
    m_page->settings().setDNSPrefetchingEnabled(dnsPrefetchingEnabled);
}

void InternalSettingsGenerated::setDoHtmlPreloadScanning(bool doHtmlPreloadScanning)
{
    m_page->settings().setDoHtmlPreloadScanning(doHtmlPreloadScanning);
}

void InternalSettingsGenerated::setDownloadableBinaryFontsEnabled(bool downloadableBinaryFontsEnabled)
{
    m_page->settings().setDownloadableBinaryFontsEnabled(downloadableBinaryFontsEnabled);
}

void InternalSettingsGenerated::setEncryptedMediaEnabled(bool encryptedMediaEnabled)
{
    m_page->settings().setEncryptedMediaEnabled(encryptedMediaEnabled);
}

void InternalSettingsGenerated::setFetchImagePlaceholders(bool fetchImagePlaceholders)
{
    m_page->settings().setFetchImagePlaceholders(fetchImagePlaceholders);
}

void InternalSettingsGenerated::setForceMainWorldInitialization(bool forceMainWorldInitialization)
{
    m_page->settings().setForceMainWorldInitialization(forceMainWorldInitialization);
}

void InternalSettingsGenerated::setForcePreloadNoneForMediaElements(bool forcePreloadNoneForMediaElements)
{
    m_page->settings().setForcePreloadNoneForMediaElements(forcePreloadNoneForMediaElements);
}

void InternalSettingsGenerated::setForceZeroLayoutHeight(bool forceZeroLayoutHeight)
{
    m_page->settings().setForceZeroLayoutHeight(forceZeroLayoutHeight);
}

void InternalSettingsGenerated::setFullscreenSupported(bool fullscreenSupported)
{
    m_page->settings().setFullscreenSupported(fullscreenSupported);
}

void InternalSettingsGenerated::setHideDownloadUI(bool hideDownloadUI)
{
    m_page->settings().setHideDownloadUI(hideDownloadUI);
}

void InternalSettingsGenerated::setHideScrollbars(bool hideScrollbars)
{
    m_page->settings().setHideScrollbars(hideScrollbars);
}

void InternalSettingsGenerated::setHistoryEntryRequiresUserGesture(bool historyEntryRequiresUserGesture)
{
    m_page->settings().setHistoryEntryRequiresUserGesture(historyEntryRequiresUserGesture);
}

void InternalSettingsGenerated::setHyperlinkAuditingEnabled(bool hyperlinkAuditingEnabled)
{
    m_page->settings().setHyperlinkAuditingEnabled(hyperlinkAuditingEnabled);
}

void InternalSettingsGenerated::setIgnoreMainFrameOverflowHiddenQuirk(bool ignoreMainFrameOverflowHiddenQuirk)
{
    m_page->settings().setIgnoreMainFrameOverflowHiddenQuirk(ignoreMainFrameOverflowHiddenQuirk);
}

void InternalSettingsGenerated::setImagesEnabled(bool imagesEnabled)
{
    m_page->settings().setImagesEnabled(imagesEnabled);
}

void InternalSettingsGenerated::setInertVisualViewport(bool inertVisualViewport)
{
    m_page->settings().setInertVisualViewport(inertVisualViewport);
}

void InternalSettingsGenerated::setInlineTextBoxAccessibilityEnabled(bool inlineTextBoxAccessibilityEnabled)
{
    m_page->settings().setInlineTextBoxAccessibilityEnabled(inlineTextBoxAccessibilityEnabled);
}

void InternalSettingsGenerated::setJavaScriptCanAccessClipboard(bool javaScriptCanAccessClipboard)
{
    m_page->settings().setJavaScriptCanAccessClipboard(javaScriptCanAccessClipboard);
}

void InternalSettingsGenerated::setJavaScriptCanOpenWindowsAutomatically(bool javaScriptCanOpenWindowsAutomatically)
{
    m_page->settings().setJavaScriptCanOpenWindowsAutomatically(javaScriptCanOpenWindowsAutomatically);
}

void InternalSettingsGenerated::setLayerSquashingEnabled(bool layerSquashingEnabled)
{
    m_page->settings().setLayerSquashingEnabled(layerSquashingEnabled);
}

void InternalSettingsGenerated::setLoadWithOverviewMode(bool loadWithOverviewMode)
{
    m_page->settings().setLoadWithOverviewMode(loadWithOverviewMode);
}

void InternalSettingsGenerated::setLoadsImagesAutomatically(bool loadsImagesAutomatically)
{
    m_page->settings().setLoadsImagesAutomatically(loadsImagesAutomatically);
}

void InternalSettingsGenerated::setLocalStorageEnabled(bool localStorageEnabled)
{
    m_page->settings().setLocalStorageEnabled(localStorageEnabled);
}

void InternalSettingsGenerated::setLogDnsPrefetchAndPreconnect(bool logDnsPrefetchAndPreconnect)
{
    m_page->settings().setLogDnsPrefetchAndPreconnect(logDnsPrefetchAndPreconnect);
}

void InternalSettingsGenerated::setLogPreload(bool logPreload)
{
    m_page->settings().setLogPreload(logPreload);
}

void InternalSettingsGenerated::setLowPriorityIframes(bool lowPriorityIframes)
{
    m_page->settings().setLowPriorityIframes(lowPriorityIframes);
}

void InternalSettingsGenerated::setMainFrameClipsContent(bool mainFrameClipsContent)
{
    m_page->settings().setMainFrameClipsContent(mainFrameClipsContent);
}

void InternalSettingsGenerated::setMainFrameResizesAreOrientationChanges(bool mainFrameResizesAreOrientationChanges)
{
    m_page->settings().setMainFrameResizesAreOrientationChanges(mainFrameResizesAreOrientationChanges);
}

void InternalSettingsGenerated::setMaxBeaconTransmission(int maxBeaconTransmission)
{
    m_page->settings().setMaxBeaconTransmission(maxBeaconTransmission);
}

void InternalSettingsGenerated::setMaxTouchPoints(int maxTouchPoints)
{
    m_page->settings().setMaxTouchPoints(maxTouchPoints);
}

void InternalSettingsGenerated::setMediaControlsOverlayPlayButtonEnabled(bool mediaControlsOverlayPlayButtonEnabled)
{
    m_page->settings().setMediaControlsOverlayPlayButtonEnabled(mediaControlsOverlayPlayButtonEnabled);
}

void InternalSettingsGenerated::setMediaPlaybackRequiresUserGesture(bool mediaPlaybackRequiresUserGesture)
{
    m_page->settings().setMediaPlaybackRequiresUserGesture(mediaPlaybackRequiresUserGesture);
}

void InternalSettingsGenerated::setMediaTypeOverride(const String& mediaTypeOverride)
{
    m_page->settings().setMediaTypeOverride(mediaTypeOverride);
}

void InternalSettingsGenerated::setMinimumAccelerated2dCanvasSize(int minimumAccelerated2dCanvasSize)
{
    m_page->settings().setMinimumAccelerated2dCanvasSize(minimumAccelerated2dCanvasSize);
}

void InternalSettingsGenerated::setMinimumFontSize(int minimumFontSize)
{
    m_page->settings().setMinimumFontSize(minimumFontSize);
}

void InternalSettingsGenerated::setMinimumLogicalFontSize(int minimumLogicalFontSize)
{
    m_page->settings().setMinimumLogicalFontSize(minimumLogicalFontSize);
}

void InternalSettingsGenerated::setMockGestureTapHighlightsEnabled(bool mockGestureTapHighlightsEnabled)
{
    m_page->settings().setMockGestureTapHighlightsEnabled(mockGestureTapHighlightsEnabled);
}

void InternalSettingsGenerated::setMultiTargetTapNotificationEnabled(bool multiTargetTapNotificationEnabled)
{
    m_page->settings().setMultiTargetTapNotificationEnabled(multiTargetTapNotificationEnabled);
}

void InternalSettingsGenerated::setNavigateOnDragDrop(bool navigateOnDragDrop)
{
    m_page->settings().setNavigateOnDragDrop(navigateOnDragDrop);
}

void InternalSettingsGenerated::setOfflineWebApplicationCacheEnabled(bool offlineWebApplicationCacheEnabled)
{
    m_page->settings().setOfflineWebApplicationCacheEnabled(offlineWebApplicationCacheEnabled);
}

void InternalSettingsGenerated::setParseHTMLOnMainThreadCoalesceChunks(bool parseHTMLOnMainThreadCoalesceChunks)
{
    m_page->settings().setParseHTMLOnMainThreadCoalesceChunks(parseHTMLOnMainThreadCoalesceChunks);
}

void InternalSettingsGenerated::setParseHTMLOnMainThreadSyncTokenize(bool parseHTMLOnMainThreadSyncTokenize)
{
    m_page->settings().setParseHTMLOnMainThreadSyncTokenize(parseHTMLOnMainThreadSyncTokenize);
}

void InternalSettingsGenerated::setPasswordEchoDurationInSeconds(double passwordEchoDurationInSeconds)
{
    m_page->settings().setPasswordEchoDurationInSeconds(passwordEchoDurationInSeconds);
}

void InternalSettingsGenerated::setPasswordEchoEnabled(bool passwordEchoEnabled)
{
    m_page->settings().setPasswordEchoEnabled(passwordEchoEnabled);
}

void InternalSettingsGenerated::setPluginsEnabled(bool pluginsEnabled)
{
    m_page->settings().setPluginsEnabled(pluginsEnabled);
}

void InternalSettingsGenerated::setPreferCompositingToLCDTextEnabled(bool preferCompositingToLCDTextEnabled)
{
    m_page->settings().setPreferCompositingToLCDTextEnabled(preferCompositingToLCDTextEnabled);
}

void InternalSettingsGenerated::setPreferHiddenVolumeControls(bool preferHiddenVolumeControls)
{
    m_page->settings().setPreferHiddenVolumeControls(preferHiddenVolumeControls);
}

void InternalSettingsGenerated::setPresentationReceiver(bool presentationReceiver)
{
    m_page->settings().setPresentationReceiver(presentationReceiver);
}

void InternalSettingsGenerated::setPresentationRequiresUserGesture(bool presentationRequiresUserGesture)
{
    m_page->settings().setPresentationRequiresUserGesture(presentationRequiresUserGesture);
}

void InternalSettingsGenerated::setReportScreenSizeInPhysicalPixelsQuirk(bool reportScreenSizeInPhysicalPixelsQuirk)
{
    m_page->settings().setReportScreenSizeInPhysicalPixelsQuirk(reportScreenSizeInPhysicalPixelsQuirk);
}

void InternalSettingsGenerated::setRubberBandingOnCompositorThread(bool rubberBandingOnCompositorThread)
{
    m_page->settings().setRubberBandingOnCompositorThread(rubberBandingOnCompositorThread);
}

void InternalSettingsGenerated::setScriptEnabled(bool scriptEnabled)
{
    m_page->settings().setScriptEnabled(scriptEnabled);
}

void InternalSettingsGenerated::setScrollAnimatorEnabled(bool scrollAnimatorEnabled)
{
    m_page->settings().setScrollAnimatorEnabled(scrollAnimatorEnabled);
}

void InternalSettingsGenerated::setSelectTrailingWhitespaceEnabled(bool selectTrailingWhitespaceEnabled)
{
    m_page->settings().setSelectTrailingWhitespaceEnabled(selectTrailingWhitespaceEnabled);
}

void InternalSettingsGenerated::setSelectionIncludesAltImageText(bool selectionIncludesAltImageText)
{
    m_page->settings().setSelectionIncludesAltImageText(selectionIncludesAltImageText);
}

void InternalSettingsGenerated::setShouldClearDocumentBackground(bool shouldClearDocumentBackground)
{
    m_page->settings().setShouldClearDocumentBackground(shouldClearDocumentBackground);
}

void InternalSettingsGenerated::setShouldPrintBackgrounds(bool shouldPrintBackgrounds)
{
    m_page->settings().setShouldPrintBackgrounds(shouldPrintBackgrounds);
}

void InternalSettingsGenerated::setShouldRespectImageOrientation(bool shouldRespectImageOrientation)
{
    m_page->settings().setShouldRespectImageOrientation(shouldRespectImageOrientation);
}

void InternalSettingsGenerated::setShouldReuseGlobalForUnownedMainFrame(bool shouldReuseGlobalForUnownedMainFrame)
{
    m_page->settings().setShouldReuseGlobalForUnownedMainFrame(shouldReuseGlobalForUnownedMainFrame);
}

void InternalSettingsGenerated::setShowContextMenuOnMouseUp(bool showContextMenuOnMouseUp)
{
    m_page->settings().setShowContextMenuOnMouseUp(showContextMenuOnMouseUp);
}

void InternalSettingsGenerated::setSmartInsertDeleteEnabled(bool smartInsertDeleteEnabled)
{
    m_page->settings().setSmartInsertDeleteEnabled(smartInsertDeleteEnabled);
}

void InternalSettingsGenerated::setSpatialNavigationEnabled(bool spatialNavigationEnabled)
{
    m_page->settings().setSpatialNavigationEnabled(spatialNavigationEnabled);
}

void InternalSettingsGenerated::setSpellCheckEnabledByDefault(bool spellCheckEnabledByDefault)
{
    m_page->settings().setSpellCheckEnabledByDefault(spellCheckEnabledByDefault);
}

void InternalSettingsGenerated::setStrictMixedContentChecking(bool strictMixedContentChecking)
{
    m_page->settings().setStrictMixedContentChecking(strictMixedContentChecking);
}

void InternalSettingsGenerated::setStrictMixedContentCheckingForPlugin(bool strictMixedContentCheckingForPlugin)
{
    m_page->settings().setStrictMixedContentCheckingForPlugin(strictMixedContentCheckingForPlugin);
}

void InternalSettingsGenerated::setStrictPowerfulFeatureRestrictions(bool strictPowerfulFeatureRestrictions)
{
    m_page->settings().setStrictPowerfulFeatureRestrictions(strictPowerfulFeatureRestrictions);
}

void InternalSettingsGenerated::setStrictlyBlockBlockableMixedContent(bool strictlyBlockBlockableMixedContent)
{
    m_page->settings().setStrictlyBlockBlockableMixedContent(strictlyBlockBlockableMixedContent);
}

void InternalSettingsGenerated::setSupportsMultipleWindows(bool supportsMultipleWindows)
{
    m_page->settings().setSupportsMultipleWindows(supportsMultipleWindows);
}

void InternalSettingsGenerated::setSyncXHRInDocumentsEnabled(bool syncXHRInDocumentsEnabled)
{
    m_page->settings().setSyncXHRInDocumentsEnabled(syncXHRInDocumentsEnabled);
}

void InternalSettingsGenerated::setTextAreasAreResizable(bool textAreasAreResizable)
{
    m_page->settings().setTextAreasAreResizable(textAreasAreResizable);
}

void InternalSettingsGenerated::setTextTrackBackgroundColor(const String& textTrackBackgroundColor)
{
    m_page->settings().setTextTrackBackgroundColor(textTrackBackgroundColor);
}

void InternalSettingsGenerated::setTextTrackFontFamily(const String& textTrackFontFamily)
{
    m_page->settings().setTextTrackFontFamily(textTrackFontFamily);
}

void InternalSettingsGenerated::setTextTrackFontStyle(const String& textTrackFontStyle)
{
    m_page->settings().setTextTrackFontStyle(textTrackFontStyle);
}

void InternalSettingsGenerated::setTextTrackFontVariant(const String& textTrackFontVariant)
{
    m_page->settings().setTextTrackFontVariant(textTrackFontVariant);
}

void InternalSettingsGenerated::setTextTrackMarginPercentage(double textTrackMarginPercentage)
{
    m_page->settings().setTextTrackMarginPercentage(textTrackMarginPercentage);
}

void InternalSettingsGenerated::setTextTrackTextColor(const String& textTrackTextColor)
{
    m_page->settings().setTextTrackTextColor(textTrackTextColor);
}

void InternalSettingsGenerated::setTextTrackTextShadow(const String& textTrackTextShadow)
{
    m_page->settings().setTextTrackTextShadow(textTrackTextShadow);
}

void InternalSettingsGenerated::setTextTrackTextSize(const String& textTrackTextSize)
{
    m_page->settings().setTextTrackTextSize(textTrackTextSize);
}

void InternalSettingsGenerated::setThreadedScrollingEnabled(bool threadedScrollingEnabled)
{
    m_page->settings().setThreadedScrollingEnabled(threadedScrollingEnabled);
}

void InternalSettingsGenerated::setTouchAdjustmentEnabled(bool touchAdjustmentEnabled)
{
    m_page->settings().setTouchAdjustmentEnabled(touchAdjustmentEnabled);
}

void InternalSettingsGenerated::setTouchDragDropEnabled(bool touchDragDropEnabled)
{
    m_page->settings().setTouchDragDropEnabled(touchDragDropEnabled);
}

void InternalSettingsGenerated::setTouchEditingEnabled(bool touchEditingEnabled)
{
    m_page->settings().setTouchEditingEnabled(touchEditingEnabled);
}

void InternalSettingsGenerated::setUseDefaultImageInterpolationQuality(bool useDefaultImageInterpolationQuality)
{
    m_page->settings().setUseDefaultImageInterpolationQuality(useDefaultImageInterpolationQuality);
}

void InternalSettingsGenerated::setUseLegacyBackgroundSizeShorthandBehavior(bool useLegacyBackgroundSizeShorthandBehavior)
{
    m_page->settings().setUseLegacyBackgroundSizeShorthandBehavior(useLegacyBackgroundSizeShorthandBehavior);
}

void InternalSettingsGenerated::setUseSolidColorScrollbars(bool useSolidColorScrollbars)
{
    m_page->settings().setUseSolidColorScrollbars(useSolidColorScrollbars);
}

void InternalSettingsGenerated::setUseWideViewport(bool useWideViewport)
{
    m_page->settings().setUseWideViewport(useWideViewport);
}

void InternalSettingsGenerated::setValidationMessageTimerMagnification(int validationMessageTimerMagnification)
{
    m_page->settings().setValidationMessageTimerMagnification(validationMessageTimerMagnification);
}

void InternalSettingsGenerated::setViewportEnabled(bool viewportEnabled)
{
    m_page->settings().setViewportEnabled(viewportEnabled);
}

void InternalSettingsGenerated::setViewportMetaEnabled(bool viewportMetaEnabled)
{
    m_page->settings().setViewportMetaEnabled(viewportMetaEnabled);
}

void InternalSettingsGenerated::setViewportMetaMergeContentQuirk(bool viewportMetaMergeContentQuirk)
{
    m_page->settings().setViewportMetaMergeContentQuirk(viewportMetaMergeContentQuirk);
}

void InternalSettingsGenerated::setViewportMetaZeroValuesQuirk(bool viewportMetaZeroValuesQuirk)
{
    m_page->settings().setViewportMetaZeroValuesQuirk(viewportMetaZeroValuesQuirk);
}

void InternalSettingsGenerated::setWebGLEnabled(bool webGLEnabled)
{
    m_page->settings().setWebGLEnabled(webGLEnabled);
}

void InternalSettingsGenerated::setWebGLErrorsToConsoleEnabled(bool webGLErrorsToConsoleEnabled)
{
    m_page->settings().setWebGLErrorsToConsoleEnabled(webGLErrorsToConsoleEnabled);
}

void InternalSettingsGenerated::setWebSecurityEnabled(bool webSecurityEnabled)
{
    m_page->settings().setWebSecurityEnabled(webSecurityEnabled);
}

void InternalSettingsGenerated::setWideViewportQuirkEnabled(bool wideViewportQuirkEnabled)
{
    m_page->settings().setWideViewportQuirkEnabled(wideViewportQuirkEnabled);
}

void InternalSettingsGenerated::setXSSAuditorEnabled(bool xssAuditorEnabled)
{
    m_page->settings().setXSSAuditorEnabled(xssAuditorEnabled);
}

DEFINE_TRACE(InternalSettingsGenerated)
{
    visitor->trace(m_page);
}

} // namespace blink
