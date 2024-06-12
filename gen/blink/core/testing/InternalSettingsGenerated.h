// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef InternalSettingsGenerated_h
#define InternalSettingsGenerated_h

#include "bindings/core/v8/ScriptWrappable.h"
#include "platform/heap/Handle.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RefCounted.h"
#include "wtf/text/WTFString.h"

namespace blink {

class Page;

class InternalSettingsGenerated
    : public GarbageCollectedFinalized<InternalSettingsGenerated>,
      public ScriptWrappable {
    DEFINE_WRAPPERTYPEINFO();

public:
    explicit InternalSettingsGenerated(Page*);
    virtual ~InternalSettingsGenerated();
    void resetToConsistentState();
    void setDOMPasteAllowed(bool DOMPasteAllowed);
    void setAccelerated2dCanvasMSAASampleCount(int accelerated2dCanvasMSAASampleCount);
    void setAcceleratedCompositingEnabled(bool acceleratedCompositingEnabled);
    void setAccessibilityEnabled(bool accessibilityEnabled);
    void setAccessibilityFontScaleFactor(double accessibilityFontScaleFactor);
    void setAccessibilityPasswordValuesEnabled(bool accessibilityPasswordValuesEnabled);
    void setAllowCustomScrollbarInMainFrame(bool allowCustomScrollbarInMainFrame);
    void setAllowFileAccessFromFileURLs(bool allowFileAccessFromFileURLs);
    void setAllowGeolocationOnInsecureOrigins(bool allowGeolocationOnInsecureOrigins);
    void setAllowRunningOfInsecureContent(bool allowRunningOfInsecureContent);
    void setAllowScriptsToCloseWindows(bool allowScriptsToCloseWindows);
    void setAllowUniversalAccessFromFileURLs(bool allowUniversalAccessFromFileURLs);
    void setAlwaysShowContextMenuOnTouch(bool alwaysShowContextMenuOnTouch);
    void setAntialiased2dCanvasEnabled(bool antialiased2dCanvasEnabled);
    void setAntialiasedClips2dCanvasEnabled(bool antialiasedClips2dCanvasEnabled);
    void setAvailableHoverTypes(int availableHoverTypes);
    void setAvailablePointerTypes(int availablePointerTypes);
    void setBackgroundHtmlParserOutstandingTokenLimit(unsigned backgroundHtmlParserOutstandingTokenLimit);
    void setBackgroundHtmlParserPendingTokenLimit(unsigned backgroundHtmlParserPendingTokenLimit);
    void setBrowserSideNavigationEnabled(bool browserSideNavigationEnabled);
    void setCookieEnabled(bool cookieEnabled);
    void setCrossOriginMediaPlaybackRequiresUserGesture(bool crossOriginMediaPlaybackRequiresUserGesture);
    void setCSSExternalScannerNoPreload(bool cssExternalScannerNoPreload);
    void setCSSExternalScannerPreload(bool cssExternalScannerPreload);
    void setDataSaverEnabled(bool dataSaverEnabled);
    void setDefaultFixedFontSize(int defaultFixedFontSize);
    void setDefaultFontSize(int defaultFontSize);
    void setDefaultTextEncodingName(const String& defaultTextEncodingName);
    void setDefaultVideoPosterURL(const String& defaultVideoPosterURL);
    void setDeviceScaleAdjustment(double deviceScaleAdjustment);
    void setDeviceSupportsTouch(bool deviceSupportsTouch);
    void setDisableReadingFromCanvas(bool disableReadingFromCanvas);
    void setDisallowFetchForDocWrittenScriptsInMainFrame(bool disallowFetchForDocWrittenScriptsInMainFrame);
    void setDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(bool disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G);
    void setDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(bool disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections);
    void setDNSPrefetchingEnabled(bool dnsPrefetchingEnabled);
    void setDoHtmlPreloadScanning(bool doHtmlPreloadScanning);
    void setDownloadableBinaryFontsEnabled(bool downloadableBinaryFontsEnabled);
    void setEncryptedMediaEnabled(bool encryptedMediaEnabled);
    void setFetchImagePlaceholders(bool fetchImagePlaceholders);
    void setForceMainWorldInitialization(bool forceMainWorldInitialization);
    void setForcePreloadNoneForMediaElements(bool forcePreloadNoneForMediaElements);
    void setForceZeroLayoutHeight(bool forceZeroLayoutHeight);
    void setFullscreenSupported(bool fullscreenSupported);
    void setHideDownloadUI(bool hideDownloadUI);
    void setHideScrollbars(bool hideScrollbars);
    void setHistoryEntryRequiresUserGesture(bool historyEntryRequiresUserGesture);
    void setHyperlinkAuditingEnabled(bool hyperlinkAuditingEnabled);
    void setIgnoreMainFrameOverflowHiddenQuirk(bool ignoreMainFrameOverflowHiddenQuirk);
    void setImagesEnabled(bool imagesEnabled);
    void setInertVisualViewport(bool inertVisualViewport);
    void setInlineTextBoxAccessibilityEnabled(bool inlineTextBoxAccessibilityEnabled);
    void setJavaScriptCanAccessClipboard(bool javaScriptCanAccessClipboard);
    void setJavaScriptCanOpenWindowsAutomatically(bool javaScriptCanOpenWindowsAutomatically);
    void setLayerSquashingEnabled(bool layerSquashingEnabled);
    void setLoadWithOverviewMode(bool loadWithOverviewMode);
    void setLoadsImagesAutomatically(bool loadsImagesAutomatically);
    void setLocalStorageEnabled(bool localStorageEnabled);
    void setLogDnsPrefetchAndPreconnect(bool logDnsPrefetchAndPreconnect);
    void setLogPreload(bool logPreload);
    void setLowPriorityIframes(bool lowPriorityIframes);
    void setMainFrameClipsContent(bool mainFrameClipsContent);
    void setMainFrameResizesAreOrientationChanges(bool mainFrameResizesAreOrientationChanges);
    void setMaxBeaconTransmission(int maxBeaconTransmission);
    void setMaxTouchPoints(int maxTouchPoints);
    void setMediaControlsOverlayPlayButtonEnabled(bool mediaControlsOverlayPlayButtonEnabled);
    void setMediaPlaybackRequiresUserGesture(bool mediaPlaybackRequiresUserGesture);
    void setMediaTypeOverride(const String& mediaTypeOverride);
    void setMinimumAccelerated2dCanvasSize(int minimumAccelerated2dCanvasSize);
    void setMinimumFontSize(int minimumFontSize);
    void setMinimumLogicalFontSize(int minimumLogicalFontSize);
    void setMockGestureTapHighlightsEnabled(bool mockGestureTapHighlightsEnabled);
    void setMultiTargetTapNotificationEnabled(bool multiTargetTapNotificationEnabled);
    void setNavigateOnDragDrop(bool navigateOnDragDrop);
    void setOfflineWebApplicationCacheEnabled(bool offlineWebApplicationCacheEnabled);
    void setParseHTMLOnMainThreadCoalesceChunks(bool parseHTMLOnMainThreadCoalesceChunks);
    void setParseHTMLOnMainThreadSyncTokenize(bool parseHTMLOnMainThreadSyncTokenize);
    void setPasswordEchoDurationInSeconds(double passwordEchoDurationInSeconds);
    void setPasswordEchoEnabled(bool passwordEchoEnabled);
    void setPluginsEnabled(bool pluginsEnabled);
    void setPreferCompositingToLCDTextEnabled(bool preferCompositingToLCDTextEnabled);
    void setPreferHiddenVolumeControls(bool preferHiddenVolumeControls);
    void setPresentationReceiver(bool presentationReceiver);
    void setPresentationRequiresUserGesture(bool presentationRequiresUserGesture);
    void setReportScreenSizeInPhysicalPixelsQuirk(bool reportScreenSizeInPhysicalPixelsQuirk);
    void setRubberBandingOnCompositorThread(bool rubberBandingOnCompositorThread);
    void setScriptEnabled(bool scriptEnabled);
    void setScrollAnimatorEnabled(bool scrollAnimatorEnabled);
    void setSelectTrailingWhitespaceEnabled(bool selectTrailingWhitespaceEnabled);
    void setSelectionIncludesAltImageText(bool selectionIncludesAltImageText);
    void setShouldClearDocumentBackground(bool shouldClearDocumentBackground);
    void setShouldPrintBackgrounds(bool shouldPrintBackgrounds);
    void setShouldRespectImageOrientation(bool shouldRespectImageOrientation);
    void setShouldReuseGlobalForUnownedMainFrame(bool shouldReuseGlobalForUnownedMainFrame);
    void setShowContextMenuOnMouseUp(bool showContextMenuOnMouseUp);
    void setSmartInsertDeleteEnabled(bool smartInsertDeleteEnabled);
    void setSpatialNavigationEnabled(bool spatialNavigationEnabled);
    void setSpellCheckEnabledByDefault(bool spellCheckEnabledByDefault);
    void setStrictMixedContentChecking(bool strictMixedContentChecking);
    void setStrictMixedContentCheckingForPlugin(bool strictMixedContentCheckingForPlugin);
    void setStrictPowerfulFeatureRestrictions(bool strictPowerfulFeatureRestrictions);
    void setStrictlyBlockBlockableMixedContent(bool strictlyBlockBlockableMixedContent);
    void setSupportsMultipleWindows(bool supportsMultipleWindows);
    void setSyncXHRInDocumentsEnabled(bool syncXHRInDocumentsEnabled);
    void setTextAreasAreResizable(bool textAreasAreResizable);
    void setTextTrackBackgroundColor(const String& textTrackBackgroundColor);
    void setTextTrackFontFamily(const String& textTrackFontFamily);
    void setTextTrackFontStyle(const String& textTrackFontStyle);
    void setTextTrackFontVariant(const String& textTrackFontVariant);
    void setTextTrackMarginPercentage(double textTrackMarginPercentage);
    void setTextTrackTextColor(const String& textTrackTextColor);
    void setTextTrackTextShadow(const String& textTrackTextShadow);
    void setTextTrackTextSize(const String& textTrackTextSize);
    void setThreadedScrollingEnabled(bool threadedScrollingEnabled);
    void setTouchAdjustmentEnabled(bool touchAdjustmentEnabled);
    void setTouchDragDropEnabled(bool touchDragDropEnabled);
    void setTouchEditingEnabled(bool touchEditingEnabled);
    void setUseDefaultImageInterpolationQuality(bool useDefaultImageInterpolationQuality);
    void setUseLegacyBackgroundSizeShorthandBehavior(bool useLegacyBackgroundSizeShorthandBehavior);
    void setUseSolidColorScrollbars(bool useSolidColorScrollbars);
    void setUseWideViewport(bool useWideViewport);
    void setValidationMessageTimerMagnification(int validationMessageTimerMagnification);
    void setViewportEnabled(bool viewportEnabled);
    void setViewportMetaEnabled(bool viewportMetaEnabled);
    void setViewportMetaMergeContentQuirk(bool viewportMetaMergeContentQuirk);
    void setViewportMetaZeroValuesQuirk(bool viewportMetaZeroValuesQuirk);
    void setWebGLEnabled(bool webGLEnabled);
    void setWebGLErrorsToConsoleEnabled(bool webGLErrorsToConsoleEnabled);
    void setWebSecurityEnabled(bool webSecurityEnabled);
    void setWideViewportQuirkEnabled(bool wideViewportQuirkEnabled);
    void setXSSAuditorEnabled(bool xssAuditorEnabled);

    DECLARE_VIRTUAL_TRACE();

private:
    Member<Page> m_page;

    bool m_DOMPasteAllowed;
    int m_accelerated2dCanvasMSAASampleCount;
    bool m_acceleratedCompositingEnabled;
    bool m_accessibilityEnabled;
    double m_accessibilityFontScaleFactor;
    bool m_accessibilityPasswordValuesEnabled;
    bool m_allowCustomScrollbarInMainFrame;
    bool m_allowFileAccessFromFileURLs;
    bool m_allowGeolocationOnInsecureOrigins;
    bool m_allowRunningOfInsecureContent;
    bool m_allowScriptsToCloseWindows;
    bool m_allowUniversalAccessFromFileURLs;
    bool m_alwaysShowContextMenuOnTouch;
    bool m_antialiased2dCanvasEnabled;
    bool m_antialiasedClips2dCanvasEnabled;
    int m_availableHoverTypes;
    int m_availablePointerTypes;
    unsigned m_backgroundHtmlParserOutstandingTokenLimit;
    unsigned m_backgroundHtmlParserPendingTokenLimit;
    bool m_browserSideNavigationEnabled;
    bool m_cookieEnabled;
    bool m_crossOriginMediaPlaybackRequiresUserGesture;
    bool m_cssExternalScannerNoPreload;
    bool m_cssExternalScannerPreload;
    bool m_dataSaverEnabled;
    int m_defaultFixedFontSize;
    int m_defaultFontSize;
    String m_defaultTextEncodingName;
    String m_defaultVideoPosterURL;
    double m_deviceScaleAdjustment;
    bool m_deviceSupportsTouch;
    bool m_disableReadingFromCanvas;
    bool m_disallowFetchForDocWrittenScriptsInMainFrame;
    bool m_disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G;
    bool m_disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections;
    bool m_dnsPrefetchingEnabled;
    bool m_doHtmlPreloadScanning;
    bool m_downloadableBinaryFontsEnabled;
    bool m_encryptedMediaEnabled;
    bool m_fetchImagePlaceholders;
    bool m_forceMainWorldInitialization;
    bool m_forcePreloadNoneForMediaElements;
    bool m_forceZeroLayoutHeight;
    bool m_fullscreenSupported;
    bool m_hideDownloadUI;
    bool m_hideScrollbars;
    bool m_historyEntryRequiresUserGesture;
    bool m_hyperlinkAuditingEnabled;
    bool m_ignoreMainFrameOverflowHiddenQuirk;
    bool m_imagesEnabled;
    bool m_inertVisualViewport;
    bool m_inlineTextBoxAccessibilityEnabled;
    bool m_javaScriptCanAccessClipboard;
    bool m_javaScriptCanOpenWindowsAutomatically;
    bool m_layerSquashingEnabled;
    bool m_loadWithOverviewMode;
    bool m_loadsImagesAutomatically;
    bool m_localStorageEnabled;
    bool m_logDnsPrefetchAndPreconnect;
    bool m_logPreload;
    bool m_lowPriorityIframes;
    bool m_mainFrameClipsContent;
    bool m_mainFrameResizesAreOrientationChanges;
    int m_maxBeaconTransmission;
    int m_maxTouchPoints;
    bool m_mediaControlsOverlayPlayButtonEnabled;
    bool m_mediaPlaybackRequiresUserGesture;
    String m_mediaTypeOverride;
    int m_minimumAccelerated2dCanvasSize;
    int m_minimumFontSize;
    int m_minimumLogicalFontSize;
    bool m_mockGestureTapHighlightsEnabled;
    bool m_multiTargetTapNotificationEnabled;
    bool m_navigateOnDragDrop;
    bool m_offlineWebApplicationCacheEnabled;
    bool m_parseHTMLOnMainThreadCoalesceChunks;
    bool m_parseHTMLOnMainThreadSyncTokenize;
    double m_passwordEchoDurationInSeconds;
    bool m_passwordEchoEnabled;
    bool m_pluginsEnabled;
    bool m_preferCompositingToLCDTextEnabled;
    bool m_preferHiddenVolumeControls;
    bool m_presentationReceiver;
    bool m_presentationRequiresUserGesture;
    bool m_reportScreenSizeInPhysicalPixelsQuirk;
    bool m_rubberBandingOnCompositorThread;
    bool m_scriptEnabled;
    bool m_scrollAnimatorEnabled;
    bool m_selectTrailingWhitespaceEnabled;
    bool m_selectionIncludesAltImageText;
    bool m_shouldClearDocumentBackground;
    bool m_shouldPrintBackgrounds;
    bool m_shouldRespectImageOrientation;
    bool m_shouldReuseGlobalForUnownedMainFrame;
    bool m_showContextMenuOnMouseUp;
    bool m_smartInsertDeleteEnabled;
    bool m_spatialNavigationEnabled;
    bool m_spellCheckEnabledByDefault;
    bool m_strictMixedContentChecking;
    bool m_strictMixedContentCheckingForPlugin;
    bool m_strictPowerfulFeatureRestrictions;
    bool m_strictlyBlockBlockableMixedContent;
    bool m_supportsMultipleWindows;
    bool m_syncXHRInDocumentsEnabled;
    bool m_textAreasAreResizable;
    String m_textTrackBackgroundColor;
    String m_textTrackFontFamily;
    String m_textTrackFontStyle;
    String m_textTrackFontVariant;
    double m_textTrackMarginPercentage;
    String m_textTrackTextColor;
    String m_textTrackTextShadow;
    String m_textTrackTextSize;
    bool m_threadedScrollingEnabled;
    bool m_touchAdjustmentEnabled;
    bool m_touchDragDropEnabled;
    bool m_touchEditingEnabled;
    bool m_useDefaultImageInterpolationQuality;
    bool m_useLegacyBackgroundSizeShorthandBehavior;
    bool m_useSolidColorScrollbars;
    bool m_useWideViewport;
    int m_validationMessageTimerMagnification;
    bool m_viewportEnabled;
    bool m_viewportMetaEnabled;
    bool m_viewportMetaMergeContentQuirk;
    bool m_viewportMetaZeroValuesQuirk;
    bool m_webGLEnabled;
    bool m_webGLErrorsToConsoleEnabled;
    bool m_webSecurityEnabled;
    bool m_wideViewportQuirkEnabled;
    bool m_xssAuditorEnabled;
};

} // namespace blink

#endif // InternalSettingsGenerated_h
