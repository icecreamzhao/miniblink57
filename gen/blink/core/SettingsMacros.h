// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SettingsMacros_h
#define SettingsMacros_h

#define SETTINGS_GETTERS_AND_SETTERS                                                                                                                          \
    bool getDOMPasteAllowed() const { return m_DOMPasteAllowed; }                                                                                             \
    void setDOMPasteAllowed(bool DOMPasteAllowed);                                                                                                            \
    int getAccelerated2dCanvasMSAASampleCount() const { return m_accelerated2dCanvasMSAASampleCount; }                                                        \
    void setAccelerated2dCanvasMSAASampleCount(int accelerated2dCanvasMSAASampleCount);                                                                       \
    bool getAcceleratedCompositingEnabled() const { return m_acceleratedCompositingEnabled; }                                                                 \
    void setAcceleratedCompositingEnabled(bool acceleratedCompositingEnabled);                                                                                \
    bool getAccessibilityEnabled() const { return m_accessibilityEnabled; }                                                                                   \
    void setAccessibilityEnabled(bool accessibilityEnabled);                                                                                                  \
    double getAccessibilityFontScaleFactor() const { return m_accessibilityFontScaleFactor; }                                                                 \
    void setAccessibilityFontScaleFactor(double accessibilityFontScaleFactor);                                                                                \
    bool getAccessibilityPasswordValuesEnabled() const { return m_accessibilityPasswordValuesEnabled; }                                                       \
    void setAccessibilityPasswordValuesEnabled(bool accessibilityPasswordValuesEnabled);                                                                      \
    bool getAllowCustomScrollbarInMainFrame() const { return m_allowCustomScrollbarInMainFrame; }                                                             \
    void setAllowCustomScrollbarInMainFrame(bool allowCustomScrollbarInMainFrame);                                                                            \
    bool getAllowFileAccessFromFileURLs() const { return m_allowFileAccessFromFileURLs; }                                                                     \
    void setAllowFileAccessFromFileURLs(bool allowFileAccessFromFileURLs);                                                                                    \
    bool getAllowGeolocationOnInsecureOrigins() const { return m_allowGeolocationOnInsecureOrigins; }                                                         \
    void setAllowGeolocationOnInsecureOrigins(bool allowGeolocationOnInsecureOrigins);                                                                        \
    bool getAllowRunningOfInsecureContent() const { return m_allowRunningOfInsecureContent; }                                                                 \
    void setAllowRunningOfInsecureContent(bool allowRunningOfInsecureContent);                                                                                \
    bool getAllowScriptsToCloseWindows() const { return m_allowScriptsToCloseWindows; }                                                                       \
    void setAllowScriptsToCloseWindows(bool allowScriptsToCloseWindows);                                                                                      \
    bool getAllowUniversalAccessFromFileURLs() const { return m_allowUniversalAccessFromFileURLs; }                                                           \
    void setAllowUniversalAccessFromFileURLs(bool allowUniversalAccessFromFileURLs);                                                                          \
    bool getAlwaysShowContextMenuOnTouch() const { return m_alwaysShowContextMenuOnTouch; }                                                                   \
    void setAlwaysShowContextMenuOnTouch(bool alwaysShowContextMenuOnTouch);                                                                                  \
    bool getAntialiased2dCanvasEnabled() const { return m_antialiased2dCanvasEnabled; }                                                                       \
    void setAntialiased2dCanvasEnabled(bool antialiased2dCanvasEnabled);                                                                                      \
    bool getAntialiasedClips2dCanvasEnabled() const { return m_antialiasedClips2dCanvasEnabled; }                                                             \
    void setAntialiasedClips2dCanvasEnabled(bool antialiasedClips2dCanvasEnabled);                                                                            \
    int getAvailableHoverTypes() const { return m_availableHoverTypes; }                                                                                      \
    void setAvailableHoverTypes(int availableHoverTypes);                                                                                                     \
    int getAvailablePointerTypes() const { return m_availablePointerTypes; }                                                                                  \
    void setAvailablePointerTypes(int availablePointerTypes);                                                                                                 \
    unsigned getBackgroundHtmlParserOutstandingTokenLimit() const { return m_backgroundHtmlParserOutstandingTokenLimit; }                                     \
    void setBackgroundHtmlParserOutstandingTokenLimit(unsigned backgroundHtmlParserOutstandingTokenLimit);                                                    \
    unsigned getBackgroundHtmlParserPendingTokenLimit() const { return m_backgroundHtmlParserPendingTokenLimit; }                                             \
    void setBackgroundHtmlParserPendingTokenLimit(unsigned backgroundHtmlParserPendingTokenLimit);                                                            \
    bool getBrowserSideNavigationEnabled() const { return m_browserSideNavigationEnabled; }                                                                   \
    void setBrowserSideNavigationEnabled(bool browserSideNavigationEnabled);                                                                                  \
    bool getCookieEnabled() const { return m_cookieEnabled; }                                                                                                 \
    void setCookieEnabled(bool cookieEnabled);                                                                                                                \
    bool getCrossOriginMediaPlaybackRequiresUserGesture() const { return m_crossOriginMediaPlaybackRequiresUserGesture; }                                     \
    void setCrossOriginMediaPlaybackRequiresUserGesture(bool crossOriginMediaPlaybackRequiresUserGesture);                                                    \
    bool getCSSExternalScannerNoPreload() const { return m_cssExternalScannerNoPreload; }                                                                     \
    void setCSSExternalScannerNoPreload(bool cssExternalScannerNoPreload);                                                                                    \
    bool getCSSExternalScannerPreload() const { return m_cssExternalScannerPreload; }                                                                         \
    void setCSSExternalScannerPreload(bool cssExternalScannerPreload);                                                                                        \
    bool getDataSaverEnabled() const { return m_dataSaverEnabled; }                                                                                           \
    void setDataSaverEnabled(bool dataSaverEnabled);                                                                                                          \
    int getDefaultFixedFontSize() const { return m_defaultFixedFontSize; }                                                                                    \
    void setDefaultFixedFontSize(int defaultFixedFontSize);                                                                                                   \
    int getDefaultFontSize() const { return m_defaultFontSize; }                                                                                              \
    void setDefaultFontSize(int defaultFontSize);                                                                                                             \
    const String& getDefaultTextEncodingName() const { return m_defaultTextEncodingName; }                                                                    \
    void setDefaultTextEncodingName(const String& defaultTextEncodingName);                                                                                   \
    const String& getDefaultVideoPosterURL() const { return m_defaultVideoPosterURL; }                                                                        \
    void setDefaultVideoPosterURL(const String& defaultVideoPosterURL);                                                                                       \
    double getDeviceScaleAdjustment() const { return m_deviceScaleAdjustment; }                                                                               \
    void setDeviceScaleAdjustment(double deviceScaleAdjustment);                                                                                              \
    bool getDeviceSupportsTouch() const { return m_deviceSupportsTouch; }                                                                                     \
    void setDeviceSupportsTouch(bool deviceSupportsTouch);                                                                                                    \
    bool getDisableReadingFromCanvas() const { return m_disableReadingFromCanvas; }                                                                           \
    void setDisableReadingFromCanvas(bool disableReadingFromCanvas);                                                                                          \
    bool getDisallowFetchForDocWrittenScriptsInMainFrame() const { return m_disallowFetchForDocWrittenScriptsInMainFrame; }                                   \
    void setDisallowFetchForDocWrittenScriptsInMainFrame(bool disallowFetchForDocWrittenScriptsInMainFrame);                                                  \
    bool getDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G() const { return m_disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G; }     \
    void setDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(bool disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G);                    \
    bool getDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections() const { return m_disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections; } \
    void setDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(bool disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections);                \
    WebDisplayMode getDisplayModeOverride() const { return m_displayModeOverride; }                                                                           \
    void setDisplayModeOverride(WebDisplayMode displayModeOverride);                                                                                          \
    bool getDNSPrefetchingEnabled() const { return m_dnsPrefetchingEnabled; }                                                                                 \
    void setDNSPrefetchingEnabled(bool dnsPrefetchingEnabled);                                                                                                \
    bool getDoHtmlPreloadScanning() const { return m_doHtmlPreloadScanning; }                                                                                 \
    void setDoHtmlPreloadScanning(bool doHtmlPreloadScanning);                                                                                                \
    bool getDownloadableBinaryFontsEnabled() const { return m_downloadableBinaryFontsEnabled; }                                                               \
    void setDownloadableBinaryFontsEnabled(bool downloadableBinaryFontsEnabled);                                                                              \
    EditingBehaviorType getEditingBehaviorType() const { return m_editingBehaviorType; }                                                                      \
    void setEditingBehaviorType(EditingBehaviorType editingBehaviorType);                                                                                     \
    bool getEncryptedMediaEnabled() const { return m_encryptedMediaEnabled; }                                                                                 \
    void setEncryptedMediaEnabled(bool encryptedMediaEnabled);                                                                                                \
    bool getFetchImagePlaceholders() const { return m_fetchImagePlaceholders; }                                                                               \
    void setFetchImagePlaceholders(bool fetchImagePlaceholders);                                                                                              \
    bool getForceMainWorldInitialization() const { return m_forceMainWorldInitialization; }                                                                   \
    void setForceMainWorldInitialization(bool forceMainWorldInitialization);                                                                                  \
    bool getForcePreloadNoneForMediaElements() const { return m_forcePreloadNoneForMediaElements; }                                                           \
    void setForcePreloadNoneForMediaElements(bool forcePreloadNoneForMediaElements);                                                                          \
    bool getForceZeroLayoutHeight() const { return m_forceZeroLayoutHeight; }                                                                                 \
    void setForceZeroLayoutHeight(bool forceZeroLayoutHeight);                                                                                                \
    bool getFullscreenSupported() const { return m_fullscreenSupported; }                                                                                     \
    void setFullscreenSupported(bool fullscreenSupported);                                                                                                    \
    bool getHideDownloadUI() const { return m_hideDownloadUI; }                                                                                               \
    void setHideDownloadUI(bool hideDownloadUI);                                                                                                              \
    bool getHideScrollbars() const { return m_hideScrollbars; }                                                                                               \
    void setHideScrollbars(bool hideScrollbars);                                                                                                              \
    bool getHistoryEntryRequiresUserGesture() const { return m_historyEntryRequiresUserGesture; }                                                             \
    void setHistoryEntryRequiresUserGesture(bool historyEntryRequiresUserGesture);                                                                            \
    bool getHyperlinkAuditingEnabled() const { return m_hyperlinkAuditingEnabled; }                                                                           \
    void setHyperlinkAuditingEnabled(bool hyperlinkAuditingEnabled);                                                                                          \
    bool getIgnoreMainFrameOverflowHiddenQuirk() const { return m_ignoreMainFrameOverflowHiddenQuirk; }                                                       \
    void setIgnoreMainFrameOverflowHiddenQuirk(bool ignoreMainFrameOverflowHiddenQuirk);                                                                      \
    ImageAnimationPolicy getImageAnimationPolicy() const { return m_imageAnimationPolicy; }                                                                   \
    void setImageAnimationPolicy(ImageAnimationPolicy imageAnimationPolicy);                                                                                  \
    bool getImagesEnabled() const { return m_imagesEnabled; }                                                                                                 \
    void setImagesEnabled(bool imagesEnabled);                                                                                                                \
    bool getInertVisualViewport() const { return m_inertVisualViewport; }                                                                                     \
    void setInertVisualViewport(bool inertVisualViewport);                                                                                                    \
    bool getInlineTextBoxAccessibilityEnabled() const { return m_inlineTextBoxAccessibilityEnabled; }                                                         \
    void setInlineTextBoxAccessibilityEnabled(bool inlineTextBoxAccessibilityEnabled);                                                                        \
    bool getJavaScriptCanAccessClipboard() const { return m_javaScriptCanAccessClipboard; }                                                                   \
    void setJavaScriptCanAccessClipboard(bool javaScriptCanAccessClipboard);                                                                                  \
    bool getJavaScriptCanOpenWindowsAutomatically() const { return m_javaScriptCanOpenWindowsAutomatically; }                                                 \
    void setJavaScriptCanOpenWindowsAutomatically(bool javaScriptCanOpenWindowsAutomatically);                                                                \
    bool getLayerSquashingEnabled() const { return m_layerSquashingEnabled; }                                                                                 \
    void setLayerSquashingEnabled(bool layerSquashingEnabled);                                                                                                \
    bool getLoadWithOverviewMode() const { return m_loadWithOverviewMode; }                                                                                   \
    void setLoadWithOverviewMode(bool loadWithOverviewMode);                                                                                                  \
    bool getLoadsImagesAutomatically() const { return m_loadsImagesAutomatically; }                                                                           \
    void setLoadsImagesAutomatically(bool loadsImagesAutomatically);                                                                                          \
    bool getLocalStorageEnabled() const { return m_localStorageEnabled; }                                                                                     \
    void setLocalStorageEnabled(bool localStorageEnabled);                                                                                                    \
    bool getLogDnsPrefetchAndPreconnect() const { return m_logDnsPrefetchAndPreconnect; }                                                                     \
    void setLogDnsPrefetchAndPreconnect(bool logDnsPrefetchAndPreconnect);                                                                                    \
    bool getLogPreload() const { return m_logPreload; }                                                                                                       \
    void setLogPreload(bool logPreload);                                                                                                                      \
    bool getLowPriorityIframes() const { return m_lowPriorityIframes; }                                                                                       \
    void setLowPriorityIframes(bool lowPriorityIframes);                                                                                                      \
    bool getMainFrameClipsContent() const { return m_mainFrameClipsContent; }                                                                                 \
    void setMainFrameClipsContent(bool mainFrameClipsContent);                                                                                                \
    bool getMainFrameResizesAreOrientationChanges() const { return m_mainFrameResizesAreOrientationChanges; }                                                 \
    void setMainFrameResizesAreOrientationChanges(bool mainFrameResizesAreOrientationChanges);                                                                \
    int getMaxBeaconTransmission() const { return m_maxBeaconTransmission; }                                                                                  \
    void setMaxBeaconTransmission(int maxBeaconTransmission);                                                                                                 \
    int getMaxTouchPoints() const { return m_maxTouchPoints; }                                                                                                \
    void setMaxTouchPoints(int maxTouchPoints);                                                                                                               \
    bool getMediaControlsOverlayPlayButtonEnabled() const { return m_mediaControlsOverlayPlayButtonEnabled; }                                                 \
    void setMediaControlsOverlayPlayButtonEnabled(bool mediaControlsOverlayPlayButtonEnabled);                                                                \
    bool getMediaPlaybackRequiresUserGesture() const { return m_mediaPlaybackRequiresUserGesture; }                                                           \
    void setMediaPlaybackRequiresUserGesture(bool mediaPlaybackRequiresUserGesture);                                                                          \
    const String& getMediaTypeOverride() const { return m_mediaTypeOverride; }                                                                                \
    void setMediaTypeOverride(const String& mediaTypeOverride);                                                                                               \
    int getMinimumAccelerated2dCanvasSize() const { return m_minimumAccelerated2dCanvasSize; }                                                                \
    void setMinimumAccelerated2dCanvasSize(int minimumAccelerated2dCanvasSize);                                                                               \
    int getMinimumFontSize() const { return m_minimumFontSize; }                                                                                              \
    void setMinimumFontSize(int minimumFontSize);                                                                                                             \
    int getMinimumLogicalFontSize() const { return m_minimumLogicalFontSize; }                                                                                \
    void setMinimumLogicalFontSize(int minimumLogicalFontSize);                                                                                               \
    bool getMockGestureTapHighlightsEnabled() const { return m_mockGestureTapHighlightsEnabled; }                                                             \
    void setMockGestureTapHighlightsEnabled(bool mockGestureTapHighlightsEnabled);                                                                            \
    bool getMultiTargetTapNotificationEnabled() const { return m_multiTargetTapNotificationEnabled; }                                                         \
    void setMultiTargetTapNotificationEnabled(bool multiTargetTapNotificationEnabled);                                                                        \
    bool getNavigateOnDragDrop() const { return m_navigateOnDragDrop; }                                                                                       \
    void setNavigateOnDragDrop(bool navigateOnDragDrop);                                                                                                      \
    bool getOfflineWebApplicationCacheEnabled() const { return m_offlineWebApplicationCacheEnabled; }                                                         \
    void setOfflineWebApplicationCacheEnabled(bool offlineWebApplicationCacheEnabled);                                                                        \
    bool getParseHTMLOnMainThreadCoalesceChunks() const { return m_parseHTMLOnMainThreadCoalesceChunks; }                                                     \
    void setParseHTMLOnMainThreadCoalesceChunks(bool parseHTMLOnMainThreadCoalesceChunks);                                                                    \
    bool getParseHTMLOnMainThreadSyncTokenize() const { return m_parseHTMLOnMainThreadSyncTokenize; }                                                         \
    void setParseHTMLOnMainThreadSyncTokenize(bool parseHTMLOnMainThreadSyncTokenize);                                                                        \
    PassiveListenerDefault getPassiveListenerDefault() const { return m_passiveListenerDefault; }                                                             \
    void setPassiveListenerDefault(PassiveListenerDefault passiveListenerDefault);                                                                            \
    double getPasswordEchoDurationInSeconds() const { return m_passwordEchoDurationInSeconds; }                                                               \
    void setPasswordEchoDurationInSeconds(double passwordEchoDurationInSeconds);                                                                              \
    bool getPasswordEchoEnabled() const { return m_passwordEchoEnabled; }                                                                                     \
    void setPasswordEchoEnabled(bool passwordEchoEnabled);                                                                                                    \
    bool getPluginsEnabled() const { return m_pluginsEnabled; }                                                                                               \
    void setPluginsEnabled(bool pluginsEnabled);                                                                                                              \
    bool getPreferCompositingToLCDTextEnabled() const { return m_preferCompositingToLCDTextEnabled; }                                                         \
    void setPreferCompositingToLCDTextEnabled(bool preferCompositingToLCDTextEnabled);                                                                        \
    bool getPreferHiddenVolumeControls() const { return m_preferHiddenVolumeControls; }                                                                       \
    void setPreferHiddenVolumeControls(bool preferHiddenVolumeControls);                                                                                      \
    bool getPresentationReceiver() const { return m_presentationReceiver; }                                                                                   \
    void setPresentationReceiver(bool presentationReceiver);                                                                                                  \
    bool getPresentationRequiresUserGesture() const { return m_presentationRequiresUserGesture; }                                                             \
    void setPresentationRequiresUserGesture(bool presentationRequiresUserGesture);                                                                            \
    HoverType getPrimaryHoverType() const { return m_primaryHoverType; }                                                                                      \
    void setPrimaryHoverType(HoverType primaryHoverType);                                                                                                     \
    PointerType getPrimaryPointerType() const { return m_primaryPointerType; }                                                                                \
    void setPrimaryPointerType(PointerType primaryPointerType);                                                                                               \
    ProgressBarCompletion getProgressBarCompletion() const { return m_progressBarCompletion; }                                                                \
    void setProgressBarCompletion(ProgressBarCompletion progressBarCompletion);                                                                               \
    bool getReportScreenSizeInPhysicalPixelsQuirk() const { return m_reportScreenSizeInPhysicalPixelsQuirk; }                                                 \
    void setReportScreenSizeInPhysicalPixelsQuirk(bool reportScreenSizeInPhysicalPixelsQuirk);                                                                \
    bool getRubberBandingOnCompositorThread() const { return m_rubberBandingOnCompositorThread; }                                                             \
    void setRubberBandingOnCompositorThread(bool rubberBandingOnCompositorThread);                                                                            \
    bool getScriptEnabled() const { return m_scriptEnabled; }                                                                                                 \
    void setScriptEnabled(bool scriptEnabled);                                                                                                                \
    bool getScrollAnimatorEnabled() const { return m_scrollAnimatorEnabled; }                                                                                 \
    void setScrollAnimatorEnabled(bool scrollAnimatorEnabled);                                                                                                \
    bool getSelectTrailingWhitespaceEnabled() const { return m_selectTrailingWhitespaceEnabled; }                                                             \
    void setSelectTrailingWhitespaceEnabled(bool selectTrailingWhitespaceEnabled);                                                                            \
    bool getSelectionIncludesAltImageText() const { return m_selectionIncludesAltImageText; }                                                                 \
    void setSelectionIncludesAltImageText(bool selectionIncludesAltImageText);                                                                                \
    SelectionStrategy getSelectionStrategy() const { return m_selectionStrategy; }                                                                            \
    void setSelectionStrategy(SelectionStrategy selectionStrategy);                                                                                           \
    bool getShouldClearDocumentBackground() const { return m_shouldClearDocumentBackground; }                                                                 \
    void setShouldClearDocumentBackground(bool shouldClearDocumentBackground);                                                                                \
    bool getShouldPrintBackgrounds() const { return m_shouldPrintBackgrounds; }                                                                               \
    void setShouldPrintBackgrounds(bool shouldPrintBackgrounds);                                                                                              \
    bool getShouldRespectImageOrientation() const { return m_shouldRespectImageOrientation; }                                                                 \
    void setShouldRespectImageOrientation(bool shouldRespectImageOrientation);                                                                                \
    bool getShouldReuseGlobalForUnownedMainFrame() const { return m_shouldReuseGlobalForUnownedMainFrame; }                                                   \
    void setShouldReuseGlobalForUnownedMainFrame(bool shouldReuseGlobalForUnownedMainFrame);                                                                  \
    bool getShowContextMenuOnMouseUp() const { return m_showContextMenuOnMouseUp; }                                                                           \
    void setShowContextMenuOnMouseUp(bool showContextMenuOnMouseUp);                                                                                          \
    bool getSmartInsertDeleteEnabled() const { return m_smartInsertDeleteEnabled; }                                                                           \
    void setSmartInsertDeleteEnabled(bool smartInsertDeleteEnabled);                                                                                          \
    bool getSpatialNavigationEnabled() const { return m_spatialNavigationEnabled; }                                                                           \
    void setSpatialNavigationEnabled(bool spatialNavigationEnabled);                                                                                          \
    bool getSpellCheckEnabledByDefault() const { return m_spellCheckEnabledByDefault; }                                                                       \
    void setSpellCheckEnabledByDefault(bool spellCheckEnabledByDefault);                                                                                      \
    bool getStrictMixedContentChecking() const { return m_strictMixedContentChecking; }                                                                       \
    void setStrictMixedContentChecking(bool strictMixedContentChecking);                                                                                      \
    bool getStrictMixedContentCheckingForPlugin() const { return m_strictMixedContentCheckingForPlugin; }                                                     \
    void setStrictMixedContentCheckingForPlugin(bool strictMixedContentCheckingForPlugin);                                                                    \
    bool getStrictPowerfulFeatureRestrictions() const { return m_strictPowerfulFeatureRestrictions; }                                                         \
    void setStrictPowerfulFeatureRestrictions(bool strictPowerfulFeatureRestrictions);                                                                        \
    bool getStrictlyBlockBlockableMixedContent() const { return m_strictlyBlockBlockableMixedContent; }                                                       \
    void setStrictlyBlockBlockableMixedContent(bool strictlyBlockBlockableMixedContent);                                                                      \
    bool getSupportsMultipleWindows() const { return m_supportsMultipleWindows; }                                                                             \
    void setSupportsMultipleWindows(bool supportsMultipleWindows);                                                                                            \
    bool getSyncXHRInDocumentsEnabled() const { return m_syncXHRInDocumentsEnabled; }                                                                         \
    void setSyncXHRInDocumentsEnabled(bool syncXHRInDocumentsEnabled);                                                                                        \
    bool getTextAreasAreResizable() const { return m_textAreasAreResizable; }                                                                                 \
    void setTextAreasAreResizable(bool textAreasAreResizable);                                                                                                \
    const String& getTextTrackBackgroundColor() const { return m_textTrackBackgroundColor; }                                                                  \
    void setTextTrackBackgroundColor(const String& textTrackBackgroundColor);                                                                                 \
    const String& getTextTrackFontFamily() const { return m_textTrackFontFamily; }                                                                            \
    void setTextTrackFontFamily(const String& textTrackFontFamily);                                                                                           \
    const String& getTextTrackFontStyle() const { return m_textTrackFontStyle; }                                                                              \
    void setTextTrackFontStyle(const String& textTrackFontStyle);                                                                                             \
    const String& getTextTrackFontVariant() const { return m_textTrackFontVariant; }                                                                          \
    void setTextTrackFontVariant(const String& textTrackFontVariant);                                                                                         \
    TextTrackKindUserPreference getTextTrackKindUserPreference() const { return m_textTrackKindUserPreference; }                                              \
    void setTextTrackKindUserPreference(TextTrackKindUserPreference textTrackKindUserPreference);                                                             \
    double getTextTrackMarginPercentage() const { return m_textTrackMarginPercentage; }                                                                       \
    void setTextTrackMarginPercentage(double textTrackMarginPercentage);                                                                                      \
    const String& getTextTrackTextColor() const { return m_textTrackTextColor; }                                                                              \
    void setTextTrackTextColor(const String& textTrackTextColor);                                                                                             \
    const String& getTextTrackTextShadow() const { return m_textTrackTextShadow; }                                                                            \
    void setTextTrackTextShadow(const String& textTrackTextShadow);                                                                                           \
    const String& getTextTrackTextSize() const { return m_textTrackTextSize; }                                                                                \
    void setTextTrackTextSize(const String& textTrackTextSize);                                                                                               \
    bool getThreadedScrollingEnabled() const { return m_threadedScrollingEnabled; }                                                                           \
    void setThreadedScrollingEnabled(bool threadedScrollingEnabled);                                                                                          \
    bool getTouchAdjustmentEnabled() const { return m_touchAdjustmentEnabled; }                                                                               \
    void setTouchAdjustmentEnabled(bool touchAdjustmentEnabled);                                                                                              \
    bool getTouchDragDropEnabled() const { return m_touchDragDropEnabled; }                                                                                   \
    void setTouchDragDropEnabled(bool touchDragDropEnabled);                                                                                                  \
    bool getTouchEditingEnabled() const { return m_touchEditingEnabled; }                                                                                     \
    void setTouchEditingEnabled(bool touchEditingEnabled);                                                                                                    \
    bool getUseDefaultImageInterpolationQuality() const { return m_useDefaultImageInterpolationQuality; }                                                     \
    void setUseDefaultImageInterpolationQuality(bool useDefaultImageInterpolationQuality);                                                                    \
    bool getUseLegacyBackgroundSizeShorthandBehavior() const { return m_useLegacyBackgroundSizeShorthandBehavior; }                                           \
    void setUseLegacyBackgroundSizeShorthandBehavior(bool useLegacyBackgroundSizeShorthandBehavior);                                                          \
    bool getUseSolidColorScrollbars() const { return m_useSolidColorScrollbars; }                                                                             \
    void setUseSolidColorScrollbars(bool useSolidColorScrollbars);                                                                                            \
    bool getUseWideViewport() const { return m_useWideViewport; }                                                                                             \
    void setUseWideViewport(bool useWideViewport);                                                                                                            \
    V8CacheOptions getV8CacheOptions() const { return m_v8CacheOptions; }                                                                                     \
    void setV8CacheOptions(V8CacheOptions v8CacheOptions);                                                                                                    \
    V8CacheStrategiesForCacheStorage getV8CacheStrategiesForCacheStorage() const { return m_v8CacheStrategiesForCacheStorage; }                               \
    void setV8CacheStrategiesForCacheStorage(V8CacheStrategiesForCacheStorage v8CacheStrategiesForCacheStorage);                                              \
    int getValidationMessageTimerMagnification() const { return m_validationMessageTimerMagnification; }                                                      \
    void setValidationMessageTimerMagnification(int validationMessageTimerMagnification);                                                                     \
    bool getViewportEnabled() const { return m_viewportEnabled; }                                                                                             \
    void setViewportEnabled(bool viewportEnabled);                                                                                                            \
    bool getViewportMetaEnabled() const { return m_viewportMetaEnabled; }                                                                                     \
    void setViewportMetaEnabled(bool viewportMetaEnabled);                                                                                                    \
    bool getViewportMetaMergeContentQuirk() const { return m_viewportMetaMergeContentQuirk; }                                                                 \
    void setViewportMetaMergeContentQuirk(bool viewportMetaMergeContentQuirk);                                                                                \
    bool getViewportMetaZeroValuesQuirk() const { return m_viewportMetaZeroValuesQuirk; }                                                                     \
    void setViewportMetaZeroValuesQuirk(bool viewportMetaZeroValuesQuirk);                                                                                    \
    WebViewportStyle getViewportStyle() const { return m_viewportStyle; }                                                                                     \
    void setViewportStyle(WebViewportStyle viewportStyle);                                                                                                    \
    bool getWebGLEnabled() const { return m_webGLEnabled; }                                                                                                   \
    void setWebGLEnabled(bool webGLEnabled);                                                                                                                  \
    bool getWebGLErrorsToConsoleEnabled() const { return m_webGLErrorsToConsoleEnabled; }                                                                     \
    void setWebGLErrorsToConsoleEnabled(bool webGLErrorsToConsoleEnabled);                                                                                    \
    bool getWebSecurityEnabled() const { return m_webSecurityEnabled; }                                                                                       \
    void setWebSecurityEnabled(bool webSecurityEnabled);                                                                                                      \
    bool getWideViewportQuirkEnabled() const { return m_wideViewportQuirkEnabled; }                                                                           \
    void setWideViewportQuirkEnabled(bool wideViewportQuirkEnabled);                                                                                          \
    bool getXSSAuditorEnabled() const { return m_xssAuditorEnabled; }                                                                                         \
    void setXSSAuditorEnabled(bool xssAuditorEnabled);                                                                                                        \
    void setFromStrings(const String& name, const String& value);
// End of SETTINGS_GETTERS_AND_SETTERS.

#define SETTINGS_MEMBER_VARIABLES                                             \
    int m_accelerated2dCanvasMSAASampleCount;                                 \
    double m_accessibilityFontScaleFactor;                                    \
    int m_availableHoverTypes;                                                \
    int m_availablePointerTypes;                                              \
    unsigned m_backgroundHtmlParserOutstandingTokenLimit;                     \
    unsigned m_backgroundHtmlParserPendingTokenLimit;                         \
    int m_defaultFixedFontSize;                                               \
    int m_defaultFontSize;                                                    \
    String m_defaultTextEncodingName;                                         \
    String m_defaultVideoPosterURL;                                           \
    double m_deviceScaleAdjustment;                                           \
    WebDisplayMode m_displayModeOverride;                                     \
    EditingBehaviorType m_editingBehaviorType;                                \
    ImageAnimationPolicy m_imageAnimationPolicy;                              \
    int m_maxBeaconTransmission;                                              \
    int m_maxTouchPoints;                                                     \
    String m_mediaTypeOverride;                                               \
    int m_minimumAccelerated2dCanvasSize;                                     \
    int m_minimumFontSize;                                                    \
    int m_minimumLogicalFontSize;                                             \
    PassiveListenerDefault m_passiveListenerDefault;                          \
    double m_passwordEchoDurationInSeconds;                                   \
    HoverType m_primaryHoverType;                                             \
    PointerType m_primaryPointerType;                                         \
    ProgressBarCompletion m_progressBarCompletion;                            \
    SelectionStrategy m_selectionStrategy;                                    \
    String m_textTrackBackgroundColor;                                        \
    String m_textTrackFontFamily;                                             \
    String m_textTrackFontStyle;                                              \
    String m_textTrackFontVariant;                                            \
    TextTrackKindUserPreference m_textTrackKindUserPreference;                \
    double m_textTrackMarginPercentage;                                       \
    String m_textTrackTextColor;                                              \
    String m_textTrackTextShadow;                                             \
    String m_textTrackTextSize;                                               \
    V8CacheOptions m_v8CacheOptions;                                          \
    V8CacheStrategiesForCacheStorage m_v8CacheStrategiesForCacheStorage;      \
    int m_validationMessageTimerMagnification;                                \
    WebViewportStyle m_viewportStyle;                                         \
    bool m_DOMPasteAllowed : 1;                                               \
    bool m_acceleratedCompositingEnabled : 1;                                 \
    bool m_accessibilityEnabled : 1;                                          \
    bool m_accessibilityPasswordValuesEnabled : 1;                            \
    bool m_allowCustomScrollbarInMainFrame : 1;                               \
    bool m_allowFileAccessFromFileURLs : 1;                                   \
    bool m_allowGeolocationOnInsecureOrigins : 1;                             \
    bool m_allowRunningOfInsecureContent : 1;                                 \
    bool m_allowScriptsToCloseWindows : 1;                                    \
    bool m_allowUniversalAccessFromFileURLs : 1;                              \
    bool m_alwaysShowContextMenuOnTouch : 1;                                  \
    bool m_antialiased2dCanvasEnabled : 1;                                    \
    bool m_antialiasedClips2dCanvasEnabled : 1;                               \
    bool m_browserSideNavigationEnabled : 1;                                  \
    bool m_cookieEnabled : 1;                                                 \
    bool m_crossOriginMediaPlaybackRequiresUserGesture : 1;                   \
    bool m_cssExternalScannerNoPreload : 1;                                   \
    bool m_cssExternalScannerPreload : 1;                                     \
    bool m_dataSaverEnabled : 1;                                              \
    bool m_deviceSupportsTouch : 1;                                           \
    bool m_disableReadingFromCanvas : 1;                                      \
    bool m_disallowFetchForDocWrittenScriptsInMainFrame : 1;                  \
    bool m_disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G : 1;   \
    bool m_disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections : 1; \
    bool m_dnsPrefetchingEnabled : 1;                                         \
    bool m_doHtmlPreloadScanning : 1;                                         \
    bool m_downloadableBinaryFontsEnabled : 1;                                \
    bool m_encryptedMediaEnabled : 1;                                         \
    bool m_fetchImagePlaceholders : 1;                                        \
    bool m_forceMainWorldInitialization : 1;                                  \
    bool m_forcePreloadNoneForMediaElements : 1;                              \
    bool m_forceZeroLayoutHeight : 1;                                         \
    bool m_fullscreenSupported : 1;                                           \
    bool m_hideDownloadUI : 1;                                                \
    bool m_hideScrollbars : 1;                                                \
    bool m_historyEntryRequiresUserGesture : 1;                               \
    bool m_hyperlinkAuditingEnabled : 1;                                      \
    bool m_ignoreMainFrameOverflowHiddenQuirk : 1;                            \
    bool m_imagesEnabled : 1;                                                 \
    bool m_inertVisualViewport : 1;                                           \
    bool m_inlineTextBoxAccessibilityEnabled : 1;                             \
    bool m_javaScriptCanAccessClipboard : 1;                                  \
    bool m_javaScriptCanOpenWindowsAutomatically : 1;                         \
    bool m_layerSquashingEnabled : 1;                                         \
    bool m_loadWithOverviewMode : 1;                                          \
    bool m_loadsImagesAutomatically : 1;                                      \
    bool m_localStorageEnabled : 1;                                           \
    bool m_logDnsPrefetchAndPreconnect : 1;                                   \
    bool m_logPreload : 1;                                                    \
    bool m_lowPriorityIframes : 1;                                            \
    bool m_mainFrameClipsContent : 1;                                         \
    bool m_mainFrameResizesAreOrientationChanges : 1;                         \
    bool m_mediaControlsOverlayPlayButtonEnabled : 1;                         \
    bool m_mediaPlaybackRequiresUserGesture : 1;                              \
    bool m_mockGestureTapHighlightsEnabled : 1;                               \
    bool m_multiTargetTapNotificationEnabled : 1;                             \
    bool m_navigateOnDragDrop : 1;                                            \
    bool m_offlineWebApplicationCacheEnabled : 1;                             \
    bool m_parseHTMLOnMainThreadCoalesceChunks : 1;                           \
    bool m_parseHTMLOnMainThreadSyncTokenize : 1;                             \
    bool m_passwordEchoEnabled : 1;                                           \
    bool m_pluginsEnabled : 1;                                                \
    bool m_preferCompositingToLCDTextEnabled : 1;                             \
    bool m_preferHiddenVolumeControls : 1;                                    \
    bool m_presentationReceiver : 1;                                          \
    bool m_presentationRequiresUserGesture : 1;                               \
    bool m_reportScreenSizeInPhysicalPixelsQuirk : 1;                         \
    bool m_rubberBandingOnCompositorThread : 1;                               \
    bool m_scriptEnabled : 1;                                                 \
    bool m_scrollAnimatorEnabled : 1;                                         \
    bool m_selectTrailingWhitespaceEnabled : 1;                               \
    bool m_selectionIncludesAltImageText : 1;                                 \
    bool m_shouldClearDocumentBackground : 1;                                 \
    bool m_shouldPrintBackgrounds : 1;                                        \
    bool m_shouldRespectImageOrientation : 1;                                 \
    bool m_shouldReuseGlobalForUnownedMainFrame : 1;                          \
    bool m_showContextMenuOnMouseUp : 1;                                      \
    bool m_smartInsertDeleteEnabled : 1;                                      \
    bool m_spatialNavigationEnabled : 1;                                      \
    bool m_spellCheckEnabledByDefault : 1;                                    \
    bool m_strictMixedContentChecking : 1;                                    \
    bool m_strictMixedContentCheckingForPlugin : 1;                           \
    bool m_strictPowerfulFeatureRestrictions : 1;                             \
    bool m_strictlyBlockBlockableMixedContent : 1;                            \
    bool m_supportsMultipleWindows : 1;                                       \
    bool m_syncXHRInDocumentsEnabled : 1;                                     \
    bool m_textAreasAreResizable : 1;                                         \
    bool m_threadedScrollingEnabled : 1;                                      \
    bool m_touchAdjustmentEnabled : 1;                                        \
    bool m_touchDragDropEnabled : 1;                                          \
    bool m_touchEditingEnabled : 1;                                           \
    bool m_useDefaultImageInterpolationQuality : 1;                           \
    bool m_useLegacyBackgroundSizeShorthandBehavior : 1;                      \
    bool m_useSolidColorScrollbars : 1;                                       \
    bool m_useWideViewport : 1;                                               \
    bool m_viewportEnabled : 1;                                               \
    bool m_viewportMetaEnabled : 1;                                           \
    bool m_viewportMetaMergeContentQuirk : 1;                                 \
    bool m_viewportMetaZeroValuesQuirk : 1;                                   \
    bool m_webGLEnabled : 1;                                                  \
    bool m_webGLErrorsToConsoleEnabled : 1;                                   \
    bool m_webSecurityEnabled : 1;                                            \
    bool m_wideViewportQuirkEnabled : 1;                                      \
    bool m_xssAuditorEnabled : 1;                                             \
    // End of SETTINGS_MEMBER_VARIABLES.

#define SETTINGS_INITIALIZER_LIST \
    , m_accelerated2dCanvasMSAASampleCount(0), m_accessibilityFontScaleFactor(1.0), m_availableHoverTypes(HoverTypeNone), m_availablePointerTypes(PointerTypeNone), m_backgroundHtmlParserOutstandingTokenLimit(0), m_backgroundHtmlParserPendingTokenLimit(0), m_defaultFixedFontSize(0), m_defaultFontSize(0), m_deviceScaleAdjustment(1.0), m_displayModeOverride(WebDisplayModeUndefined), m_editingBehaviorType(editingBehaviorTypeForPlatform()), m_imageAnimationPolicy(ImageAnimationPolicyAllowed), m_maxBeaconTransmission(65536), m_maxTouchPoints(0), m_mediaTypeOverride(""), m_minimumAccelerated2dCanvasSize(257 * 256), m_minimumFontSize(0), m_minimumLogicalFontSize(0), m_passiveListenerDefault(PassiveListenerDefault::False), m_passwordEchoDurationInSeconds(1), m_primaryHoverType(HoverTypeNone), m_primaryPointerType(PointerTypeNone), m_progressBarCompletion(ProgressBarCompletion::LoadEvent), m_selectionStrategy(SelectionStrategy::Character), m_textTrackKindUserPreference(TextTrackKindUserPreference::Default), m_textTrackMarginPercentage(0), m_v8CacheOptions(V8CacheOptionsDefault), m_v8CacheStrategiesForCacheStorage(V8CacheStrategiesForCacheStorage::Default), m_validationMessageTimerMagnification(50), m_viewportStyle(WebViewportStyle::Default), m_DOMPasteAllowed(false), m_acceleratedCompositingEnabled(true), m_accessibilityEnabled(false), m_accessibilityPasswordValuesEnabled(false), m_allowCustomScrollbarInMainFrame(true), m_allowFileAccessFromFileURLs(true), m_allowGeolocationOnInsecureOrigins(false), m_allowRunningOfInsecureContent(true), m_allowScriptsToCloseWindows(false), m_allowUniversalAccessFromFileURLs(true), m_alwaysShowContextMenuOnTouch(true), m_antialiased2dCanvasEnabled(true), m_antialiasedClips2dCanvasEnabled(true), m_browserSideNavigationEnabled(false), m_cookieEnabled(true), m_crossOriginMediaPlaybackRequiresUserGesture(false), m_cssExternalScannerNoPreload(false), m_cssExternalScannerPreload(false), m_dataSaverEnabled(false), m_deviceSupportsTouch(false), m_disableReadingFromCanvas(false), m_disallowFetchForDocWrittenScriptsInMainFrame(false), m_disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(false), m_disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(false), m_dnsPrefetchingEnabled(false), m_doHtmlPreloadScanning(true), m_downloadableBinaryFontsEnabled(true), m_encryptedMediaEnabled(true), m_fetchImagePlaceholders(false), m_forceMainWorldInitialization(false), m_forcePreloadNoneForMediaElements(false), m_forceZeroLayoutHeight(false), m_fullscreenSupported(true), m_hideDownloadUI(false), m_hideScrollbars(false), m_historyEntryRequiresUserGesture(false), m_hyperlinkAuditingEnabled(false), m_ignoreMainFrameOverflowHiddenQuirk(false), m_imagesEnabled(true), m_inertVisualViewport(false), m_inlineTextBoxAccessibilityEnabled(false), m_javaScriptCanAccessClipboard(false), m_javaScriptCanOpenWindowsAutomatically(false), m_layerSquashingEnabled(false), m_loadWithOverviewMode(true), m_loadsImagesAutomatically(false), m_localStorageEnabled(false), m_logDnsPrefetchAndPreconnect(false), m_logPreload(false), m_lowPriorityIframes(false), m_mainFrameClipsContent(true), m_mainFrameResizesAreOrientationChanges(false), m_mediaControlsOverlayPlayButtonEnabled(false), m_mediaPlaybackRequiresUserGesture(false), m_mockGestureTapHighlightsEnabled(false), m_multiTargetTapNotificationEnabled(true), m_navigateOnDragDrop(true), m_offlineWebApplicationCacheEnabled(true), m_parseHTMLOnMainThreadCoalesceChunks(false), m_parseHTMLOnMainThreadSyncTokenize(false), m_passwordEchoEnabled(false), m_pluginsEnabled(false), m_preferCompositingToLCDTextEnabled(false), m_preferHiddenVolumeControls(false), m_presentationReceiver(false), m_presentationRequiresUserGesture(true), m_reportScreenSizeInPhysicalPixelsQuirk(false), m_rubberBandingOnCompositorThread(false), m_scriptEnabled(false), m_scrollAnimatorEnabled(true), m_selectTrailingWhitespaceEnabled(defaultSelectTrailingWhitespaceEnabled), m_selectionIncludesAltImageText(false), m_shouldClearDocumentBackground(true), m_shouldPrintBackgrounds(false), m_shouldRespectImageOrientation(false), m_shouldReuseGlobalForUnownedMainFrame(false), m_showContextMenuOnMouseUp(false), m_smartInsertDeleteEnabled(false), m_spatialNavigationEnabled(false), m_spellCheckEnabledByDefault(true), m_strictMixedContentChecking(false), m_strictMixedContentCheckingForPlugin(false), m_strictPowerfulFeatureRestrictions(false), m_strictlyBlockBlockableMixedContent(false), m_supportsMultipleWindows(true), m_syncXHRInDocumentsEnabled(true), m_textAreasAreResizable(false), m_threadedScrollingEnabled(true), m_touchAdjustmentEnabled(true), m_touchDragDropEnabled(false), m_touchEditingEnabled(false), m_useDefaultImageInterpolationQuality(false), m_useLegacyBackgroundSizeShorthandBehavior(false), m_useSolidColorScrollbars(false), m_useWideViewport(true), m_viewportEnabled(false), m_viewportMetaEnabled(false), m_viewportMetaMergeContentQuirk(false), m_viewportMetaZeroValuesQuirk(false), m_webGLEnabled(false), m_webGLErrorsToConsoleEnabled(true), m_webSecurityEnabled(true), m_wideViewportQuirkEnabled(false), m_xssAuditorEnabled(false) // End of SETTINGS_INITIALIZER_LIST.

#define SETTINGS_SETTER_BODIES                                                                                                                          \
    void Settings::setDOMPasteAllowed(bool DOMPasteAllowed)                                                                                             \
    {                                                                                                                                                   \
        if (m_DOMPasteAllowed == DOMPasteAllowed)                                                                                                       \
            return;                                                                                                                                     \
        m_DOMPasteAllowed = DOMPasteAllowed;                                                                                                            \
    }                                                                                                                                                   \
    void Settings::setAccelerated2dCanvasMSAASampleCount(int accelerated2dCanvasMSAASampleCount)                                                        \
    {                                                                                                                                                   \
        if (m_accelerated2dCanvasMSAASampleCount == accelerated2dCanvasMSAASampleCount)                                                                 \
            return;                                                                                                                                     \
        m_accelerated2dCanvasMSAASampleCount = accelerated2dCanvasMSAASampleCount;                                                                      \
    }                                                                                                                                                   \
    void Settings::setAcceleratedCompositingEnabled(bool acceleratedCompositingEnabled)                                                                 \
    {                                                                                                                                                   \
        if (m_acceleratedCompositingEnabled == acceleratedCompositingEnabled)                                                                           \
            return;                                                                                                                                     \
        m_acceleratedCompositingEnabled = acceleratedCompositingEnabled;                                                                                \
        invalidate(SettingsDelegate::AcceleratedCompositingChange);                                                                                     \
    }                                                                                                                                                   \
    void Settings::setAccessibilityEnabled(bool accessibilityEnabled)                                                                                   \
    {                                                                                                                                                   \
        if (m_accessibilityEnabled == accessibilityEnabled)                                                                                             \
            return;                                                                                                                                     \
        m_accessibilityEnabled = accessibilityEnabled;                                                                                                  \
        invalidate(SettingsDelegate::AccessibilityStateChange);                                                                                         \
    }                                                                                                                                                   \
    void Settings::setAccessibilityFontScaleFactor(double accessibilityFontScaleFactor)                                                                 \
    {                                                                                                                                                   \
        if (m_accessibilityFontScaleFactor == accessibilityFontScaleFactor)                                                                             \
            return;                                                                                                                                     \
        m_accessibilityFontScaleFactor = accessibilityFontScaleFactor;                                                                                  \
        invalidate(SettingsDelegate::TextAutosizingChange);                                                                                             \
    }                                                                                                                                                   \
    void Settings::setAccessibilityPasswordValuesEnabled(bool accessibilityPasswordValuesEnabled)                                                       \
    {                                                                                                                                                   \
        if (m_accessibilityPasswordValuesEnabled == accessibilityPasswordValuesEnabled)                                                                 \
            return;                                                                                                                                     \
        m_accessibilityPasswordValuesEnabled = accessibilityPasswordValuesEnabled;                                                                      \
    }                                                                                                                                                   \
    void Settings::setAllowCustomScrollbarInMainFrame(bool allowCustomScrollbarInMainFrame)                                                             \
    {                                                                                                                                                   \
        if (m_allowCustomScrollbarInMainFrame == allowCustomScrollbarInMainFrame)                                                                       \
            return;                                                                                                                                     \
        m_allowCustomScrollbarInMainFrame = allowCustomScrollbarInMainFrame;                                                                            \
    }                                                                                                                                                   \
    void Settings::setAllowFileAccessFromFileURLs(bool allowFileAccessFromFileURLs)                                                                     \
    {                                                                                                                                                   \
        if (m_allowFileAccessFromFileURLs == allowFileAccessFromFileURLs)                                                                               \
            return;                                                                                                                                     \
        m_allowFileAccessFromFileURLs = allowFileAccessFromFileURLs;                                                                                    \
    }                                                                                                                                                   \
    void Settings::setAllowGeolocationOnInsecureOrigins(bool allowGeolocationOnInsecureOrigins)                                                         \
    {                                                                                                                                                   \
        if (m_allowGeolocationOnInsecureOrigins == allowGeolocationOnInsecureOrigins)                                                                   \
            return;                                                                                                                                     \
        m_allowGeolocationOnInsecureOrigins = allowGeolocationOnInsecureOrigins;                                                                        \
    }                                                                                                                                                   \
    void Settings::setAllowRunningOfInsecureContent(bool allowRunningOfInsecureContent)                                                                 \
    {                                                                                                                                                   \
        if (m_allowRunningOfInsecureContent == allowRunningOfInsecureContent)                                                                           \
            return;                                                                                                                                     \
        m_allowRunningOfInsecureContent = allowRunningOfInsecureContent;                                                                                \
    }                                                                                                                                                   \
    void Settings::setAllowScriptsToCloseWindows(bool allowScriptsToCloseWindows)                                                                       \
    {                                                                                                                                                   \
        if (m_allowScriptsToCloseWindows == allowScriptsToCloseWindows)                                                                                 \
            return;                                                                                                                                     \
        m_allowScriptsToCloseWindows = allowScriptsToCloseWindows;                                                                                      \
    }                                                                                                                                                   \
    void Settings::setAllowUniversalAccessFromFileURLs(bool allowUniversalAccessFromFileURLs)                                                           \
    {                                                                                                                                                   \
        if (m_allowUniversalAccessFromFileURLs == allowUniversalAccessFromFileURLs)                                                                     \
            return;                                                                                                                                     \
        m_allowUniversalAccessFromFileURLs = allowUniversalAccessFromFileURLs;                                                                          \
    }                                                                                                                                                   \
    void Settings::setAlwaysShowContextMenuOnTouch(bool alwaysShowContextMenuOnTouch)                                                                   \
    {                                                                                                                                                   \
        if (m_alwaysShowContextMenuOnTouch == alwaysShowContextMenuOnTouch)                                                                             \
            return;                                                                                                                                     \
        m_alwaysShowContextMenuOnTouch = alwaysShowContextMenuOnTouch;                                                                                  \
    }                                                                                                                                                   \
    void Settings::setAntialiased2dCanvasEnabled(bool antialiased2dCanvasEnabled)                                                                       \
    {                                                                                                                                                   \
        if (m_antialiased2dCanvasEnabled == antialiased2dCanvasEnabled)                                                                                 \
            return;                                                                                                                                     \
        m_antialiased2dCanvasEnabled = antialiased2dCanvasEnabled;                                                                                      \
    }                                                                                                                                                   \
    void Settings::setAntialiasedClips2dCanvasEnabled(bool antialiasedClips2dCanvasEnabled)                                                             \
    {                                                                                                                                                   \
        if (m_antialiasedClips2dCanvasEnabled == antialiasedClips2dCanvasEnabled)                                                                       \
            return;                                                                                                                                     \
        m_antialiasedClips2dCanvasEnabled = antialiasedClips2dCanvasEnabled;                                                                            \
    }                                                                                                                                                   \
    void Settings::setAvailableHoverTypes(int availableHoverTypes)                                                                                      \
    {                                                                                                                                                   \
        if (m_availableHoverTypes == availableHoverTypes)                                                                                               \
            return;                                                                                                                                     \
        m_availableHoverTypes = availableHoverTypes;                                                                                                    \
        invalidate(SettingsDelegate::MediaQueryChange);                                                                                                 \
    }                                                                                                                                                   \
    void Settings::setAvailablePointerTypes(int availablePointerTypes)                                                                                  \
    {                                                                                                                                                   \
        if (m_availablePointerTypes == availablePointerTypes)                                                                                           \
            return;                                                                                                                                     \
        m_availablePointerTypes = availablePointerTypes;                                                                                                \
        invalidate(SettingsDelegate::MediaQueryChange);                                                                                                 \
    }                                                                                                                                                   \
    void Settings::setBackgroundHtmlParserOutstandingTokenLimit(unsigned backgroundHtmlParserOutstandingTokenLimit)                                     \
    {                                                                                                                                                   \
        if (m_backgroundHtmlParserOutstandingTokenLimit == backgroundHtmlParserOutstandingTokenLimit)                                                   \
            return;                                                                                                                                     \
        m_backgroundHtmlParserOutstandingTokenLimit = backgroundHtmlParserOutstandingTokenLimit;                                                        \
    }                                                                                                                                                   \
    void Settings::setBackgroundHtmlParserPendingTokenLimit(unsigned backgroundHtmlParserPendingTokenLimit)                                             \
    {                                                                                                                                                   \
        if (m_backgroundHtmlParserPendingTokenLimit == backgroundHtmlParserPendingTokenLimit)                                                           \
            return;                                                                                                                                     \
        m_backgroundHtmlParserPendingTokenLimit = backgroundHtmlParserPendingTokenLimit;                                                                \
    }                                                                                                                                                   \
    void Settings::setBrowserSideNavigationEnabled(bool browserSideNavigationEnabled)                                                                   \
    {                                                                                                                                                   \
        if (m_browserSideNavigationEnabled == browserSideNavigationEnabled)                                                                             \
            return;                                                                                                                                     \
        m_browserSideNavigationEnabled = browserSideNavigationEnabled;                                                                                  \
    }                                                                                                                                                   \
    void Settings::setCookieEnabled(bool cookieEnabled)                                                                                                 \
    {                                                                                                                                                   \
        if (m_cookieEnabled == cookieEnabled)                                                                                                           \
            return;                                                                                                                                     \
        m_cookieEnabled = cookieEnabled;                                                                                                                \
    }                                                                                                                                                   \
    void Settings::setCrossOriginMediaPlaybackRequiresUserGesture(bool crossOriginMediaPlaybackRequiresUserGesture)                                     \
    {                                                                                                                                                   \
        if (m_crossOriginMediaPlaybackRequiresUserGesture == crossOriginMediaPlaybackRequiresUserGesture)                                               \
            return;                                                                                                                                     \
        m_crossOriginMediaPlaybackRequiresUserGesture = crossOriginMediaPlaybackRequiresUserGesture;                                                    \
    }                                                                                                                                                   \
    void Settings::setCSSExternalScannerNoPreload(bool cssExternalScannerNoPreload)                                                                     \
    {                                                                                                                                                   \
        if (m_cssExternalScannerNoPreload == cssExternalScannerNoPreload)                                                                               \
            return;                                                                                                                                     \
        m_cssExternalScannerNoPreload = cssExternalScannerNoPreload;                                                                                    \
    }                                                                                                                                                   \
    void Settings::setCSSExternalScannerPreload(bool cssExternalScannerPreload)                                                                         \
    {                                                                                                                                                   \
        if (m_cssExternalScannerPreload == cssExternalScannerPreload)                                                                                   \
            return;                                                                                                                                     \
        m_cssExternalScannerPreload = cssExternalScannerPreload;                                                                                        \
    }                                                                                                                                                   \
    void Settings::setDataSaverEnabled(bool dataSaverEnabled)                                                                                           \
    {                                                                                                                                                   \
        if (m_dataSaverEnabled == dataSaverEnabled)                                                                                                     \
            return;                                                                                                                                     \
        m_dataSaverEnabled = dataSaverEnabled;                                                                                                          \
    }                                                                                                                                                   \
    void Settings::setDefaultFixedFontSize(int defaultFixedFontSize)                                                                                    \
    {                                                                                                                                                   \
        if (m_defaultFixedFontSize == defaultFixedFontSize)                                                                                             \
            return;                                                                                                                                     \
        m_defaultFixedFontSize = defaultFixedFontSize;                                                                                                  \
        invalidate(SettingsDelegate::StyleChange);                                                                                                      \
    }                                                                                                                                                   \
    void Settings::setDefaultFontSize(int defaultFontSize)                                                                                              \
    {                                                                                                                                                   \
        if (m_defaultFontSize == defaultFontSize)                                                                                                       \
            return;                                                                                                                                     \
        m_defaultFontSize = defaultFontSize;                                                                                                            \
        invalidate(SettingsDelegate::StyleChange);                                                                                                      \
    }                                                                                                                                                   \
    void Settings::setDefaultTextEncodingName(const String& defaultTextEncodingName)                                                                    \
    {                                                                                                                                                   \
        if (m_defaultTextEncodingName == defaultTextEncodingName)                                                                                       \
            return;                                                                                                                                     \
        m_defaultTextEncodingName = defaultTextEncodingName;                                                                                            \
    }                                                                                                                                                   \
    void Settings::setDefaultVideoPosterURL(const String& defaultVideoPosterURL)                                                                        \
    {                                                                                                                                                   \
        if (m_defaultVideoPosterURL == defaultVideoPosterURL)                                                                                           \
            return;                                                                                                                                     \
        m_defaultVideoPosterURL = defaultVideoPosterURL;                                                                                                \
    }                                                                                                                                                   \
    void Settings::setDeviceScaleAdjustment(double deviceScaleAdjustment)                                                                               \
    {                                                                                                                                                   \
        if (m_deviceScaleAdjustment == deviceScaleAdjustment)                                                                                           \
            return;                                                                                                                                     \
        m_deviceScaleAdjustment = deviceScaleAdjustment;                                                                                                \
        invalidate(SettingsDelegate::TextAutosizingChange);                                                                                             \
    }                                                                                                                                                   \
    void Settings::setDeviceSupportsTouch(bool deviceSupportsTouch)                                                                                     \
    {                                                                                                                                                   \
        if (m_deviceSupportsTouch == deviceSupportsTouch)                                                                                               \
            return;                                                                                                                                     \
        m_deviceSupportsTouch = deviceSupportsTouch;                                                                                                    \
    }                                                                                                                                                   \
    void Settings::setDisableReadingFromCanvas(bool disableReadingFromCanvas)                                                                           \
    {                                                                                                                                                   \
        if (m_disableReadingFromCanvas == disableReadingFromCanvas)                                                                                     \
            return;                                                                                                                                     \
        m_disableReadingFromCanvas = disableReadingFromCanvas;                                                                                          \
    }                                                                                                                                                   \
    void Settings::setDisallowFetchForDocWrittenScriptsInMainFrame(bool disallowFetchForDocWrittenScriptsInMainFrame)                                   \
    {                                                                                                                                                   \
        if (m_disallowFetchForDocWrittenScriptsInMainFrame == disallowFetchForDocWrittenScriptsInMainFrame)                                             \
            return;                                                                                                                                     \
        m_disallowFetchForDocWrittenScriptsInMainFrame = disallowFetchForDocWrittenScriptsInMainFrame;                                                  \
    }                                                                                                                                                   \
    void Settings::setDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(bool disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G)     \
    {                                                                                                                                                   \
        if (m_disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G == disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G)               \
            return;                                                                                                                                     \
        m_disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G = disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G;                    \
    }                                                                                                                                                   \
    void Settings::setDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(bool disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections) \
    {                                                                                                                                                   \
        if (m_disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections == disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections)           \
            return;                                                                                                                                     \
        m_disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections = disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections;                \
    }                                                                                                                                                   \
    void Settings::setDisplayModeOverride(WebDisplayMode displayModeOverride)                                                                           \
    {                                                                                                                                                   \
        if (m_displayModeOverride == displayModeOverride)                                                                                               \
            return;                                                                                                                                     \
        m_displayModeOverride = displayModeOverride;                                                                                                    \
        invalidate(SettingsDelegate::MediaQueryChange);                                                                                                 \
    }                                                                                                                                                   \
    void Settings::setDNSPrefetchingEnabled(bool dnsPrefetchingEnabled)                                                                                 \
    {                                                                                                                                                   \
        if (m_dnsPrefetchingEnabled == dnsPrefetchingEnabled)                                                                                           \
            return;                                                                                                                                     \
        m_dnsPrefetchingEnabled = dnsPrefetchingEnabled;                                                                                                \
        invalidate(SettingsDelegate::DNSPrefetchingChange);                                                                                             \
    }                                                                                                                                                   \
    void Settings::setDoHtmlPreloadScanning(bool doHtmlPreloadScanning)                                                                                 \
    {                                                                                                                                                   \
        if (m_doHtmlPreloadScanning == doHtmlPreloadScanning)                                                                                           \
            return;                                                                                                                                     \
        m_doHtmlPreloadScanning = doHtmlPreloadScanning;                                                                                                \
    }                                                                                                                                                   \
    void Settings::setDownloadableBinaryFontsEnabled(bool downloadableBinaryFontsEnabled)                                                               \
    {                                                                                                                                                   \
        if (m_downloadableBinaryFontsEnabled == downloadableBinaryFontsEnabled)                                                                         \
            return;                                                                                                                                     \
        m_downloadableBinaryFontsEnabled = downloadableBinaryFontsEnabled;                                                                              \
    }                                                                                                                                                   \
    void Settings::setEditingBehaviorType(EditingBehaviorType editingBehaviorType)                                                                      \
    {                                                                                                                                                   \
        if (m_editingBehaviorType == editingBehaviorType)                                                                                               \
            return;                                                                                                                                     \
        m_editingBehaviorType = editingBehaviorType;                                                                                                    \
    }                                                                                                                                                   \
    void Settings::setEncryptedMediaEnabled(bool encryptedMediaEnabled)                                                                                 \
    {                                                                                                                                                   \
        if (m_encryptedMediaEnabled == encryptedMediaEnabled)                                                                                           \
            return;                                                                                                                                     \
        m_encryptedMediaEnabled = encryptedMediaEnabled;                                                                                                \
    }                                                                                                                                                   \
    void Settings::setFetchImagePlaceholders(bool fetchImagePlaceholders)                                                                               \
    {                                                                                                                                                   \
        if (m_fetchImagePlaceholders == fetchImagePlaceholders)                                                                                         \
            return;                                                                                                                                     \
        m_fetchImagePlaceholders = fetchImagePlaceholders;                                                                                              \
    }                                                                                                                                                   \
    void Settings::setForceMainWorldInitialization(bool forceMainWorldInitialization)                                                                   \
    {                                                                                                                                                   \
        if (m_forceMainWorldInitialization == forceMainWorldInitialization)                                                                             \
            return;                                                                                                                                     \
        m_forceMainWorldInitialization = forceMainWorldInitialization;                                                                                  \
        invalidate(SettingsDelegate::DOMWorldsChange);                                                                                                  \
    }                                                                                                                                                   \
    void Settings::setForcePreloadNoneForMediaElements(bool forcePreloadNoneForMediaElements)                                                           \
    {                                                                                                                                                   \
        if (m_forcePreloadNoneForMediaElements == forcePreloadNoneForMediaElements)                                                                     \
            return;                                                                                                                                     \
        m_forcePreloadNoneForMediaElements = forcePreloadNoneForMediaElements;                                                                          \
    }                                                                                                                                                   \
    void Settings::setForceZeroLayoutHeight(bool forceZeroLayoutHeight)                                                                                 \
    {                                                                                                                                                   \
        if (m_forceZeroLayoutHeight == forceZeroLayoutHeight)                                                                                           \
            return;                                                                                                                                     \
        m_forceZeroLayoutHeight = forceZeroLayoutHeight;                                                                                                \
        invalidate(SettingsDelegate::ViewportDescriptionChange);                                                                                        \
    }                                                                                                                                                   \
    void Settings::setFullscreenSupported(bool fullscreenSupported)                                                                                     \
    {                                                                                                                                                   \
        if (m_fullscreenSupported == fullscreenSupported)                                                                                               \
            return;                                                                                                                                     \
        m_fullscreenSupported = fullscreenSupported;                                                                                                    \
    }                                                                                                                                                   \
    void Settings::setHideDownloadUI(bool hideDownloadUI)                                                                                               \
    {                                                                                                                                                   \
        if (m_hideDownloadUI == hideDownloadUI)                                                                                                         \
            return;                                                                                                                                     \
        m_hideDownloadUI = hideDownloadUI;                                                                                                              \
    }                                                                                                                                                   \
    void Settings::setHideScrollbars(bool hideScrollbars)                                                                                               \
    {                                                                                                                                                   \
        if (m_hideScrollbars == hideScrollbars)                                                                                                         \
            return;                                                                                                                                     \
        m_hideScrollbars = hideScrollbars;                                                                                                              \
    }                                                                                                                                                   \
    void Settings::setHistoryEntryRequiresUserGesture(bool historyEntryRequiresUserGesture)                                                             \
    {                                                                                                                                                   \
        if (m_historyEntryRequiresUserGesture == historyEntryRequiresUserGesture)                                                                       \
            return;                                                                                                                                     \
        m_historyEntryRequiresUserGesture = historyEntryRequiresUserGesture;                                                                            \
    }                                                                                                                                                   \
    void Settings::setHyperlinkAuditingEnabled(bool hyperlinkAuditingEnabled)                                                                           \
    {                                                                                                                                                   \
        if (m_hyperlinkAuditingEnabled == hyperlinkAuditingEnabled)                                                                                     \
            return;                                                                                                                                     \
        m_hyperlinkAuditingEnabled = hyperlinkAuditingEnabled;                                                                                          \
    }                                                                                                                                                   \
    void Settings::setIgnoreMainFrameOverflowHiddenQuirk(bool ignoreMainFrameOverflowHiddenQuirk)                                                       \
    {                                                                                                                                                   \
        if (m_ignoreMainFrameOverflowHiddenQuirk == ignoreMainFrameOverflowHiddenQuirk)                                                                 \
            return;                                                                                                                                     \
        m_ignoreMainFrameOverflowHiddenQuirk = ignoreMainFrameOverflowHiddenQuirk;                                                                      \
    }                                                                                                                                                   \
    void Settings::setImageAnimationPolicy(ImageAnimationPolicy imageAnimationPolicy)                                                                   \
    {                                                                                                                                                   \
        if (m_imageAnimationPolicy == imageAnimationPolicy)                                                                                             \
            return;                                                                                                                                     \
        m_imageAnimationPolicy = imageAnimationPolicy;                                                                                                  \
    }                                                                                                                                                   \
    void Settings::setImagesEnabled(bool imagesEnabled)                                                                                                 \
    {                                                                                                                                                   \
        if (m_imagesEnabled == imagesEnabled)                                                                                                           \
            return;                                                                                                                                     \
        m_imagesEnabled = imagesEnabled;                                                                                                                \
        invalidate(SettingsDelegate::ImageLoadingChange);                                                                                               \
    }                                                                                                                                                   \
    void Settings::setInertVisualViewport(bool inertVisualViewport)                                                                                     \
    {                                                                                                                                                   \
        if (m_inertVisualViewport == inertVisualViewport)                                                                                               \
            return;                                                                                                                                     \
        m_inertVisualViewport = inertVisualViewport;                                                                                                    \
    }                                                                                                                                                   \
    void Settings::setInlineTextBoxAccessibilityEnabled(bool inlineTextBoxAccessibilityEnabled)                                                         \
    {                                                                                                                                                   \
        if (m_inlineTextBoxAccessibilityEnabled == inlineTextBoxAccessibilityEnabled)                                                                   \
            return;                                                                                                                                     \
        m_inlineTextBoxAccessibilityEnabled = inlineTextBoxAccessibilityEnabled;                                                                        \
    }                                                                                                                                                   \
    void Settings::setJavaScriptCanAccessClipboard(bool javaScriptCanAccessClipboard)                                                                   \
    {                                                                                                                                                   \
        if (m_javaScriptCanAccessClipboard == javaScriptCanAccessClipboard)                                                                             \
            return;                                                                                                                                     \
        m_javaScriptCanAccessClipboard = javaScriptCanAccessClipboard;                                                                                  \
    }                                                                                                                                                   \
    void Settings::setJavaScriptCanOpenWindowsAutomatically(bool javaScriptCanOpenWindowsAutomatically)                                                 \
    {                                                                                                                                                   \
        if (m_javaScriptCanOpenWindowsAutomatically == javaScriptCanOpenWindowsAutomatically)                                                           \
            return;                                                                                                                                     \
        m_javaScriptCanOpenWindowsAutomatically = javaScriptCanOpenWindowsAutomatically;                                                                \
    }                                                                                                                                                   \
    void Settings::setLayerSquashingEnabled(bool layerSquashingEnabled)                                                                                 \
    {                                                                                                                                                   \
        if (m_layerSquashingEnabled == layerSquashingEnabled)                                                                                           \
            return;                                                                                                                                     \
        m_layerSquashingEnabled = layerSquashingEnabled;                                                                                                \
    }                                                                                                                                                   \
    void Settings::setLoadWithOverviewMode(bool loadWithOverviewMode)                                                                                   \
    {                                                                                                                                                   \
        if (m_loadWithOverviewMode == loadWithOverviewMode)                                                                                             \
            return;                                                                                                                                     \
        m_loadWithOverviewMode = loadWithOverviewMode;                                                                                                  \
        invalidate(SettingsDelegate::ViewportDescriptionChange);                                                                                        \
    }                                                                                                                                                   \
    void Settings::setLoadsImagesAutomatically(bool loadsImagesAutomatically)                                                                           \
    {                                                                                                                                                   \
        if (m_loadsImagesAutomatically == loadsImagesAutomatically)                                                                                     \
            return;                                                                                                                                     \
        m_loadsImagesAutomatically = loadsImagesAutomatically;                                                                                          \
        invalidate(SettingsDelegate::ImageLoadingChange);                                                                                               \
    }                                                                                                                                                   \
    void Settings::setLocalStorageEnabled(bool localStorageEnabled)                                                                                     \
    {                                                                                                                                                   \
        if (m_localStorageEnabled == localStorageEnabled)                                                                                               \
            return;                                                                                                                                     \
        m_localStorageEnabled = localStorageEnabled;                                                                                                    \
    }                                                                                                                                                   \
    void Settings::setLogDnsPrefetchAndPreconnect(bool logDnsPrefetchAndPreconnect)                                                                     \
    {                                                                                                                                                   \
        if (m_logDnsPrefetchAndPreconnect == logDnsPrefetchAndPreconnect)                                                                               \
            return;                                                                                                                                     \
        m_logDnsPrefetchAndPreconnect = logDnsPrefetchAndPreconnect;                                                                                    \
    }                                                                                                                                                   \
    void Settings::setLogPreload(bool logPreload)                                                                                                       \
    {                                                                                                                                                   \
        if (m_logPreload == logPreload)                                                                                                                 \
            return;                                                                                                                                     \
        m_logPreload = logPreload;                                                                                                                      \
    }                                                                                                                                                   \
    void Settings::setLowPriorityIframes(bool lowPriorityIframes)                                                                                       \
    {                                                                                                                                                   \
        if (m_lowPriorityIframes == lowPriorityIframes)                                                                                                 \
            return;                                                                                                                                     \
        m_lowPriorityIframes = lowPriorityIframes;                                                                                                      \
    }                                                                                                                                                   \
    void Settings::setMainFrameClipsContent(bool mainFrameClipsContent)                                                                                 \
    {                                                                                                                                                   \
        if (m_mainFrameClipsContent == mainFrameClipsContent)                                                                                           \
            return;                                                                                                                                     \
        m_mainFrameClipsContent = mainFrameClipsContent;                                                                                                \
    }                                                                                                                                                   \
    void Settings::setMainFrameResizesAreOrientationChanges(bool mainFrameResizesAreOrientationChanges)                                                 \
    {                                                                                                                                                   \
        if (m_mainFrameResizesAreOrientationChanges == mainFrameResizesAreOrientationChanges)                                                           \
            return;                                                                                                                                     \
        m_mainFrameResizesAreOrientationChanges = mainFrameResizesAreOrientationChanges;                                                                \
    }                                                                                                                                                   \
    void Settings::setMaxBeaconTransmission(int maxBeaconTransmission)                                                                                  \
    {                                                                                                                                                   \
        if (m_maxBeaconTransmission == maxBeaconTransmission)                                                                                           \
            return;                                                                                                                                     \
        m_maxBeaconTransmission = maxBeaconTransmission;                                                                                                \
    }                                                                                                                                                   \
    void Settings::setMaxTouchPoints(int maxTouchPoints)                                                                                                \
    {                                                                                                                                                   \
        if (m_maxTouchPoints == maxTouchPoints)                                                                                                         \
            return;                                                                                                                                     \
        m_maxTouchPoints = maxTouchPoints;                                                                                                              \
    }                                                                                                                                                   \
    void Settings::setMediaControlsOverlayPlayButtonEnabled(bool mediaControlsOverlayPlayButtonEnabled)                                                 \
    {                                                                                                                                                   \
        if (m_mediaControlsOverlayPlayButtonEnabled == mediaControlsOverlayPlayButtonEnabled)                                                           \
            return;                                                                                                                                     \
        m_mediaControlsOverlayPlayButtonEnabled = mediaControlsOverlayPlayButtonEnabled;                                                                \
    }                                                                                                                                                   \
    void Settings::setMediaPlaybackRequiresUserGesture(bool mediaPlaybackRequiresUserGesture)                                                           \
    {                                                                                                                                                   \
        if (m_mediaPlaybackRequiresUserGesture == mediaPlaybackRequiresUserGesture)                                                                     \
            return;                                                                                                                                     \
        m_mediaPlaybackRequiresUserGesture = mediaPlaybackRequiresUserGesture;                                                                          \
    }                                                                                                                                                   \
    void Settings::setMediaTypeOverride(const String& mediaTypeOverride)                                                                                \
    {                                                                                                                                                   \
        if (m_mediaTypeOverride == mediaTypeOverride)                                                                                                   \
            return;                                                                                                                                     \
        m_mediaTypeOverride = mediaTypeOverride;                                                                                                        \
        invalidate(SettingsDelegate::MediaQueryChange);                                                                                                 \
    }                                                                                                                                                   \
    void Settings::setMinimumAccelerated2dCanvasSize(int minimumAccelerated2dCanvasSize)                                                                \
    {                                                                                                                                                   \
        if (m_minimumAccelerated2dCanvasSize == minimumAccelerated2dCanvasSize)                                                                         \
            return;                                                                                                                                     \
        m_minimumAccelerated2dCanvasSize = minimumAccelerated2dCanvasSize;                                                                              \
    }                                                                                                                                                   \
    void Settings::setMinimumFontSize(int minimumFontSize)                                                                                              \
    {                                                                                                                                                   \
        if (m_minimumFontSize == minimumFontSize)                                                                                                       \
            return;                                                                                                                                     \
        m_minimumFontSize = minimumFontSize;                                                                                                            \
        invalidate(SettingsDelegate::StyleChange);                                                                                                      \
    }                                                                                                                                                   \
    void Settings::setMinimumLogicalFontSize(int minimumLogicalFontSize)                                                                                \
    {                                                                                                                                                   \
        if (m_minimumLogicalFontSize == minimumLogicalFontSize)                                                                                         \
            return;                                                                                                                                     \
        m_minimumLogicalFontSize = minimumLogicalFontSize;                                                                                              \
        invalidate(SettingsDelegate::StyleChange);                                                                                                      \
    }                                                                                                                                                   \
    void Settings::setMockGestureTapHighlightsEnabled(bool mockGestureTapHighlightsEnabled)                                                             \
    {                                                                                                                                                   \
        if (m_mockGestureTapHighlightsEnabled == mockGestureTapHighlightsEnabled)                                                                       \
            return;                                                                                                                                     \
        m_mockGestureTapHighlightsEnabled = mockGestureTapHighlightsEnabled;                                                                            \
    }                                                                                                                                                   \
    void Settings::setMultiTargetTapNotificationEnabled(bool multiTargetTapNotificationEnabled)                                                         \
    {                                                                                                                                                   \
        if (m_multiTargetTapNotificationEnabled == multiTargetTapNotificationEnabled)                                                                   \
            return;                                                                                                                                     \
        m_multiTargetTapNotificationEnabled = multiTargetTapNotificationEnabled;                                                                        \
    }                                                                                                                                                   \
    void Settings::setNavigateOnDragDrop(bool navigateOnDragDrop)                                                                                       \
    {                                                                                                                                                   \
        if (m_navigateOnDragDrop == navigateOnDragDrop)                                                                                                 \
            return;                                                                                                                                     \
        m_navigateOnDragDrop = navigateOnDragDrop;                                                                                                      \
    }                                                                                                                                                   \
    void Settings::setOfflineWebApplicationCacheEnabled(bool offlineWebApplicationCacheEnabled)                                                         \
    {                                                                                                                                                   \
        if (m_offlineWebApplicationCacheEnabled == offlineWebApplicationCacheEnabled)                                                                   \
            return;                                                                                                                                     \
        m_offlineWebApplicationCacheEnabled = offlineWebApplicationCacheEnabled;                                                                        \
    }                                                                                                                                                   \
    void Settings::setParseHTMLOnMainThreadCoalesceChunks(bool parseHTMLOnMainThreadCoalesceChunks)                                                     \
    {                                                                                                                                                   \
        if (m_parseHTMLOnMainThreadCoalesceChunks == parseHTMLOnMainThreadCoalesceChunks)                                                               \
            return;                                                                                                                                     \
        m_parseHTMLOnMainThreadCoalesceChunks = parseHTMLOnMainThreadCoalesceChunks;                                                                    \
    }                                                                                                                                                   \
    void Settings::setParseHTMLOnMainThreadSyncTokenize(bool parseHTMLOnMainThreadSyncTokenize)                                                         \
    {                                                                                                                                                   \
        if (m_parseHTMLOnMainThreadSyncTokenize == parseHTMLOnMainThreadSyncTokenize)                                                                   \
            return;                                                                                                                                     \
        m_parseHTMLOnMainThreadSyncTokenize = parseHTMLOnMainThreadSyncTokenize;                                                                        \
    }                                                                                                                                                   \
    void Settings::setPassiveListenerDefault(PassiveListenerDefault passiveListenerDefault)                                                             \
    {                                                                                                                                                   \
        if (m_passiveListenerDefault == passiveListenerDefault)                                                                                         \
            return;                                                                                                                                     \
        m_passiveListenerDefault = passiveListenerDefault;                                                                                              \
    }                                                                                                                                                   \
    void Settings::setPasswordEchoDurationInSeconds(double passwordEchoDurationInSeconds)                                                               \
    {                                                                                                                                                   \
        if (m_passwordEchoDurationInSeconds == passwordEchoDurationInSeconds)                                                                           \
            return;                                                                                                                                     \
        m_passwordEchoDurationInSeconds = passwordEchoDurationInSeconds;                                                                                \
    }                                                                                                                                                   \
    void Settings::setPasswordEchoEnabled(bool passwordEchoEnabled)                                                                                     \
    {                                                                                                                                                   \
        if (m_passwordEchoEnabled == passwordEchoEnabled)                                                                                               \
            return;                                                                                                                                     \
        m_passwordEchoEnabled = passwordEchoEnabled;                                                                                                    \
    }                                                                                                                                                   \
    void Settings::setPluginsEnabled(bool pluginsEnabled)                                                                                               \
    {                                                                                                                                                   \
        if (m_pluginsEnabled == pluginsEnabled)                                                                                                         \
            return;                                                                                                                                     \
        m_pluginsEnabled = pluginsEnabled;                                                                                                              \
    }                                                                                                                                                   \
    void Settings::setPreferCompositingToLCDTextEnabled(bool preferCompositingToLCDTextEnabled)                                                         \
    {                                                                                                                                                   \
        if (m_preferCompositingToLCDTextEnabled == preferCompositingToLCDTextEnabled)                                                                   \
            return;                                                                                                                                     \
        m_preferCompositingToLCDTextEnabled = preferCompositingToLCDTextEnabled;                                                                        \
        invalidate(SettingsDelegate::AcceleratedCompositingChange);                                                                                     \
    }                                                                                                                                                   \
    void Settings::setPreferHiddenVolumeControls(bool preferHiddenVolumeControls)                                                                       \
    {                                                                                                                                                   \
        if (m_preferHiddenVolumeControls == preferHiddenVolumeControls)                                                                                 \
            return;                                                                                                                                     \
        m_preferHiddenVolumeControls = preferHiddenVolumeControls;                                                                                      \
    }                                                                                                                                                   \
    void Settings::setPresentationReceiver(bool presentationReceiver)                                                                                   \
    {                                                                                                                                                   \
        if (m_presentationReceiver == presentationReceiver)                                                                                             \
            return;                                                                                                                                     \
        m_presentationReceiver = presentationReceiver;                                                                                                  \
    }                                                                                                                                                   \
    void Settings::setPresentationRequiresUserGesture(bool presentationRequiresUserGesture)                                                             \
    {                                                                                                                                                   \
        if (m_presentationRequiresUserGesture == presentationRequiresUserGesture)                                                                       \
            return;                                                                                                                                     \
        m_presentationRequiresUserGesture = presentationRequiresUserGesture;                                                                            \
    }                                                                                                                                                   \
    void Settings::setPrimaryHoverType(HoverType primaryHoverType)                                                                                      \
    {                                                                                                                                                   \
        if (m_primaryHoverType == primaryHoverType)                                                                                                     \
            return;                                                                                                                                     \
        m_primaryHoverType = primaryHoverType;                                                                                                          \
        invalidate(SettingsDelegate::MediaQueryChange);                                                                                                 \
    }                                                                                                                                                   \
    void Settings::setPrimaryPointerType(PointerType primaryPointerType)                                                                                \
    {                                                                                                                                                   \
        if (m_primaryPointerType == primaryPointerType)                                                                                                 \
            return;                                                                                                                                     \
        m_primaryPointerType = primaryPointerType;                                                                                                      \
        invalidate(SettingsDelegate::MediaQueryChange);                                                                                                 \
    }                                                                                                                                                   \
    void Settings::setProgressBarCompletion(ProgressBarCompletion progressBarCompletion)                                                                \
    {                                                                                                                                                   \
        if (m_progressBarCompletion == progressBarCompletion)                                                                                           \
            return;                                                                                                                                     \
        m_progressBarCompletion = progressBarCompletion;                                                                                                \
    }                                                                                                                                                   \
    void Settings::setReportScreenSizeInPhysicalPixelsQuirk(bool reportScreenSizeInPhysicalPixelsQuirk)                                                 \
    {                                                                                                                                                   \
        if (m_reportScreenSizeInPhysicalPixelsQuirk == reportScreenSizeInPhysicalPixelsQuirk)                                                           \
            return;                                                                                                                                     \
        m_reportScreenSizeInPhysicalPixelsQuirk = reportScreenSizeInPhysicalPixelsQuirk;                                                                \
    }                                                                                                                                                   \
    void Settings::setRubberBandingOnCompositorThread(bool rubberBandingOnCompositorThread)                                                             \
    {                                                                                                                                                   \
        if (m_rubberBandingOnCompositorThread == rubberBandingOnCompositorThread)                                                                       \
            return;                                                                                                                                     \
        m_rubberBandingOnCompositorThread = rubberBandingOnCompositorThread;                                                                            \
    }                                                                                                                                                   \
    void Settings::setScriptEnabled(bool scriptEnabled)                                                                                                 \
    {                                                                                                                                                   \
        if (m_scriptEnabled == scriptEnabled)                                                                                                           \
            return;                                                                                                                                     \
        m_scriptEnabled = scriptEnabled;                                                                                                                \
    }                                                                                                                                                   \
    void Settings::setScrollAnimatorEnabled(bool scrollAnimatorEnabled)                                                                                 \
    {                                                                                                                                                   \
        if (m_scrollAnimatorEnabled == scrollAnimatorEnabled)                                                                                           \
            return;                                                                                                                                     \
        m_scrollAnimatorEnabled = scrollAnimatorEnabled;                                                                                                \
    }                                                                                                                                                   \
    void Settings::setSelectTrailingWhitespaceEnabled(bool selectTrailingWhitespaceEnabled)                                                             \
    {                                                                                                                                                   \
        if (m_selectTrailingWhitespaceEnabled == selectTrailingWhitespaceEnabled)                                                                       \
            return;                                                                                                                                     \
        m_selectTrailingWhitespaceEnabled = selectTrailingWhitespaceEnabled;                                                                            \
    }                                                                                                                                                   \
    void Settings::setSelectionIncludesAltImageText(bool selectionIncludesAltImageText)                                                                 \
    {                                                                                                                                                   \
        if (m_selectionIncludesAltImageText == selectionIncludesAltImageText)                                                                           \
            return;                                                                                                                                     \
        m_selectionIncludesAltImageText = selectionIncludesAltImageText;                                                                                \
    }                                                                                                                                                   \
    void Settings::setSelectionStrategy(SelectionStrategy selectionStrategy)                                                                            \
    {                                                                                                                                                   \
        if (m_selectionStrategy == selectionStrategy)                                                                                                   \
            return;                                                                                                                                     \
        m_selectionStrategy = selectionStrategy;                                                                                                        \
    }                                                                                                                                                   \
    void Settings::setShouldClearDocumentBackground(bool shouldClearDocumentBackground)                                                                 \
    {                                                                                                                                                   \
        if (m_shouldClearDocumentBackground == shouldClearDocumentBackground)                                                                           \
            return;                                                                                                                                     \
        m_shouldClearDocumentBackground = shouldClearDocumentBackground;                                                                                \
    }                                                                                                                                                   \
    void Settings::setShouldPrintBackgrounds(bool shouldPrintBackgrounds)                                                                               \
    {                                                                                                                                                   \
        if (m_shouldPrintBackgrounds == shouldPrintBackgrounds)                                                                                         \
            return;                                                                                                                                     \
        m_shouldPrintBackgrounds = shouldPrintBackgrounds;                                                                                              \
    }                                                                                                                                                   \
    void Settings::setShouldRespectImageOrientation(bool shouldRespectImageOrientation)                                                                 \
    {                                                                                                                                                   \
        if (m_shouldRespectImageOrientation == shouldRespectImageOrientation)                                                                           \
            return;                                                                                                                                     \
        m_shouldRespectImageOrientation = shouldRespectImageOrientation;                                                                                \
    }                                                                                                                                                   \
    void Settings::setShouldReuseGlobalForUnownedMainFrame(bool shouldReuseGlobalForUnownedMainFrame)                                                   \
    {                                                                                                                                                   \
        if (m_shouldReuseGlobalForUnownedMainFrame == shouldReuseGlobalForUnownedMainFrame)                                                             \
            return;                                                                                                                                     \
        m_shouldReuseGlobalForUnownedMainFrame = shouldReuseGlobalForUnownedMainFrame;                                                                  \
    }                                                                                                                                                   \
    void Settings::setShowContextMenuOnMouseUp(bool showContextMenuOnMouseUp)                                                                           \
    {                                                                                                                                                   \
        if (m_showContextMenuOnMouseUp == showContextMenuOnMouseUp)                                                                                     \
            return;                                                                                                                                     \
        m_showContextMenuOnMouseUp = showContextMenuOnMouseUp;                                                                                          \
    }                                                                                                                                                   \
    void Settings::setSmartInsertDeleteEnabled(bool smartInsertDeleteEnabled)                                                                           \
    {                                                                                                                                                   \
        if (m_smartInsertDeleteEnabled == smartInsertDeleteEnabled)                                                                                     \
            return;                                                                                                                                     \
        m_smartInsertDeleteEnabled = smartInsertDeleteEnabled;                                                                                          \
    }                                                                                                                                                   \
    void Settings::setSpatialNavigationEnabled(bool spatialNavigationEnabled)                                                                           \
    {                                                                                                                                                   \
        if (m_spatialNavigationEnabled == spatialNavigationEnabled)                                                                                     \
            return;                                                                                                                                     \
        m_spatialNavigationEnabled = spatialNavigationEnabled;                                                                                          \
    }                                                                                                                                                   \
    void Settings::setSpellCheckEnabledByDefault(bool spellCheckEnabledByDefault)                                                                       \
    {                                                                                                                                                   \
        if (m_spellCheckEnabledByDefault == spellCheckEnabledByDefault)                                                                                 \
            return;                                                                                                                                     \
        m_spellCheckEnabledByDefault = spellCheckEnabledByDefault;                                                                                      \
    }                                                                                                                                                   \
    void Settings::setStrictMixedContentChecking(bool strictMixedContentChecking)                                                                       \
    {                                                                                                                                                   \
        if (m_strictMixedContentChecking == strictMixedContentChecking)                                                                                 \
            return;                                                                                                                                     \
        m_strictMixedContentChecking = strictMixedContentChecking;                                                                                      \
    }                                                                                                                                                   \
    void Settings::setStrictMixedContentCheckingForPlugin(bool strictMixedContentCheckingForPlugin)                                                     \
    {                                                                                                                                                   \
        if (m_strictMixedContentCheckingForPlugin == strictMixedContentCheckingForPlugin)                                                               \
            return;                                                                                                                                     \
        m_strictMixedContentCheckingForPlugin = strictMixedContentCheckingForPlugin;                                                                    \
    }                                                                                                                                                   \
    void Settings::setStrictPowerfulFeatureRestrictions(bool strictPowerfulFeatureRestrictions)                                                         \
    {                                                                                                                                                   \
        if (m_strictPowerfulFeatureRestrictions == strictPowerfulFeatureRestrictions)                                                                   \
            return;                                                                                                                                     \
        m_strictPowerfulFeatureRestrictions = strictPowerfulFeatureRestrictions;                                                                        \
    }                                                                                                                                                   \
    void Settings::setStrictlyBlockBlockableMixedContent(bool strictlyBlockBlockableMixedContent)                                                       \
    {                                                                                                                                                   \
        if (m_strictlyBlockBlockableMixedContent == strictlyBlockBlockableMixedContent)                                                                 \
            return;                                                                                                                                     \
        m_strictlyBlockBlockableMixedContent = strictlyBlockBlockableMixedContent;                                                                      \
    }                                                                                                                                                   \
    void Settings::setSupportsMultipleWindows(bool supportsMultipleWindows)                                                                             \
    {                                                                                                                                                   \
        if (m_supportsMultipleWindows == supportsMultipleWindows)                                                                                       \
            return;                                                                                                                                     \
        m_supportsMultipleWindows = supportsMultipleWindows;                                                                                            \
    }                                                                                                                                                   \
    void Settings::setSyncXHRInDocumentsEnabled(bool syncXHRInDocumentsEnabled)                                                                         \
    {                                                                                                                                                   \
        if (m_syncXHRInDocumentsEnabled == syncXHRInDocumentsEnabled)                                                                                   \
            return;                                                                                                                                     \
        m_syncXHRInDocumentsEnabled = syncXHRInDocumentsEnabled;                                                                                        \
    }                                                                                                                                                   \
    void Settings::setTextAreasAreResizable(bool textAreasAreResizable)                                                                                 \
    {                                                                                                                                                   \
        if (m_textAreasAreResizable == textAreasAreResizable)                                                                                           \
            return;                                                                                                                                     \
        m_textAreasAreResizable = textAreasAreResizable;                                                                                                \
        invalidate(SettingsDelegate::StyleChange);                                                                                                      \
    }                                                                                                                                                   \
    void Settings::setTextTrackBackgroundColor(const String& textTrackBackgroundColor)                                                                  \
    {                                                                                                                                                   \
        if (m_textTrackBackgroundColor == textTrackBackgroundColor)                                                                                     \
            return;                                                                                                                                     \
        m_textTrackBackgroundColor = textTrackBackgroundColor;                                                                                          \
    }                                                                                                                                                   \
    void Settings::setTextTrackFontFamily(const String& textTrackFontFamily)                                                                            \
    {                                                                                                                                                   \
        if (m_textTrackFontFamily == textTrackFontFamily)                                                                                               \
            return;                                                                                                                                     \
        m_textTrackFontFamily = textTrackFontFamily;                                                                                                    \
    }                                                                                                                                                   \
    void Settings::setTextTrackFontStyle(const String& textTrackFontStyle)                                                                              \
    {                                                                                                                                                   \
        if (m_textTrackFontStyle == textTrackFontStyle)                                                                                                 \
            return;                                                                                                                                     \
        m_textTrackFontStyle = textTrackFontStyle;                                                                                                      \
    }                                                                                                                                                   \
    void Settings::setTextTrackFontVariant(const String& textTrackFontVariant)                                                                          \
    {                                                                                                                                                   \
        if (m_textTrackFontVariant == textTrackFontVariant)                                                                                             \
            return;                                                                                                                                     \
        m_textTrackFontVariant = textTrackFontVariant;                                                                                                  \
    }                                                                                                                                                   \
    void Settings::setTextTrackKindUserPreference(TextTrackKindUserPreference textTrackKindUserPreference)                                              \
    {                                                                                                                                                   \
        if (m_textTrackKindUserPreference == textTrackKindUserPreference)                                                                               \
            return;                                                                                                                                     \
        m_textTrackKindUserPreference = textTrackKindUserPreference;                                                                                    \
        invalidate(SettingsDelegate::TextTrackKindUserPreferenceChange);                                                                                \
    }                                                                                                                                                   \
    void Settings::setTextTrackMarginPercentage(double textTrackMarginPercentage)                                                                       \
    {                                                                                                                                                   \
        if (m_textTrackMarginPercentage == textTrackMarginPercentage)                                                                                   \
            return;                                                                                                                                     \
        m_textTrackMarginPercentage = textTrackMarginPercentage;                                                                                        \
    }                                                                                                                                                   \
    void Settings::setTextTrackTextColor(const String& textTrackTextColor)                                                                              \
    {                                                                                                                                                   \
        if (m_textTrackTextColor == textTrackTextColor)                                                                                                 \
            return;                                                                                                                                     \
        m_textTrackTextColor = textTrackTextColor;                                                                                                      \
    }                                                                                                                                                   \
    void Settings::setTextTrackTextShadow(const String& textTrackTextShadow)                                                                            \
    {                                                                                                                                                   \
        if (m_textTrackTextShadow == textTrackTextShadow)                                                                                               \
            return;                                                                                                                                     \
        m_textTrackTextShadow = textTrackTextShadow;                                                                                                    \
    }                                                                                                                                                   \
    void Settings::setTextTrackTextSize(const String& textTrackTextSize)                                                                                \
    {                                                                                                                                                   \
        if (m_textTrackTextSize == textTrackTextSize)                                                                                                   \
            return;                                                                                                                                     \
        m_textTrackTextSize = textTrackTextSize;                                                                                                        \
    }                                                                                                                                                   \
    void Settings::setThreadedScrollingEnabled(bool threadedScrollingEnabled)                                                                           \
    {                                                                                                                                                   \
        if (m_threadedScrollingEnabled == threadedScrollingEnabled)                                                                                     \
            return;                                                                                                                                     \
        m_threadedScrollingEnabled = threadedScrollingEnabled;                                                                                          \
        invalidate(SettingsDelegate::StyleChange);                                                                                                      \
    }                                                                                                                                                   \
    void Settings::setTouchAdjustmentEnabled(bool touchAdjustmentEnabled)                                                                               \
    {                                                                                                                                                   \
        if (m_touchAdjustmentEnabled == touchAdjustmentEnabled)                                                                                         \
            return;                                                                                                                                     \
        m_touchAdjustmentEnabled = touchAdjustmentEnabled;                                                                                              \
    }                                                                                                                                                   \
    void Settings::setTouchDragDropEnabled(bool touchDragDropEnabled)                                                                                   \
    {                                                                                                                                                   \
        if (m_touchDragDropEnabled == touchDragDropEnabled)                                                                                             \
            return;                                                                                                                                     \
        m_touchDragDropEnabled = touchDragDropEnabled;                                                                                                  \
    }                                                                                                                                                   \
    void Settings::setTouchEditingEnabled(bool touchEditingEnabled)                                                                                     \
    {                                                                                                                                                   \
        if (m_touchEditingEnabled == touchEditingEnabled)                                                                                               \
            return;                                                                                                                                     \
        m_touchEditingEnabled = touchEditingEnabled;                                                                                                    \
    }                                                                                                                                                   \
    void Settings::setUseDefaultImageInterpolationQuality(bool useDefaultImageInterpolationQuality)                                                     \
    {                                                                                                                                                   \
        if (m_useDefaultImageInterpolationQuality == useDefaultImageInterpolationQuality)                                                               \
            return;                                                                                                                                     \
        m_useDefaultImageInterpolationQuality = useDefaultImageInterpolationQuality;                                                                    \
    }                                                                                                                                                   \
    void Settings::setUseLegacyBackgroundSizeShorthandBehavior(bool useLegacyBackgroundSizeShorthandBehavior)                                           \
    {                                                                                                                                                   \
        if (m_useLegacyBackgroundSizeShorthandBehavior == useLegacyBackgroundSizeShorthandBehavior)                                                     \
            return;                                                                                                                                     \
        m_useLegacyBackgroundSizeShorthandBehavior = useLegacyBackgroundSizeShorthandBehavior;                                                          \
    }                                                                                                                                                   \
    void Settings::setUseSolidColorScrollbars(bool useSolidColorScrollbars)                                                                             \
    {                                                                                                                                                   \
        if (m_useSolidColorScrollbars == useSolidColorScrollbars)                                                                                       \
            return;                                                                                                                                     \
        m_useSolidColorScrollbars = useSolidColorScrollbars;                                                                                            \
    }                                                                                                                                                   \
    void Settings::setUseWideViewport(bool useWideViewport)                                                                                             \
    {                                                                                                                                                   \
        if (m_useWideViewport == useWideViewport)                                                                                                       \
            return;                                                                                                                                     \
        m_useWideViewport = useWideViewport;                                                                                                            \
        invalidate(SettingsDelegate::ViewportDescriptionChange);                                                                                        \
    }                                                                                                                                                   \
    void Settings::setV8CacheOptions(V8CacheOptions v8CacheOptions)                                                                                     \
    {                                                                                                                                                   \
        if (m_v8CacheOptions == v8CacheOptions)                                                                                                         \
            return;                                                                                                                                     \
        m_v8CacheOptions = v8CacheOptions;                                                                                                              \
    }                                                                                                                                                   \
    void Settings::setV8CacheStrategiesForCacheStorage(V8CacheStrategiesForCacheStorage v8CacheStrategiesForCacheStorage)                               \
    {                                                                                                                                                   \
        if (m_v8CacheStrategiesForCacheStorage == v8CacheStrategiesForCacheStorage)                                                                     \
            return;                                                                                                                                     \
        m_v8CacheStrategiesForCacheStorage = v8CacheStrategiesForCacheStorage;                                                                          \
    }                                                                                                                                                   \
    void Settings::setValidationMessageTimerMagnification(int validationMessageTimerMagnification)                                                      \
    {                                                                                                                                                   \
        if (m_validationMessageTimerMagnification == validationMessageTimerMagnification)                                                               \
            return;                                                                                                                                     \
        m_validationMessageTimerMagnification = validationMessageTimerMagnification;                                                                    \
    }                                                                                                                                                   \
    void Settings::setViewportEnabled(bool viewportEnabled)                                                                                             \
    {                                                                                                                                                   \
        if (m_viewportEnabled == viewportEnabled)                                                                                                       \
            return;                                                                                                                                     \
        m_viewportEnabled = viewportEnabled;                                                                                                            \
        invalidate(SettingsDelegate::ViewportDescriptionChange);                                                                                        \
    }                                                                                                                                                   \
    void Settings::setViewportMetaEnabled(bool viewportMetaEnabled)                                                                                     \
    {                                                                                                                                                   \
        if (m_viewportMetaEnabled == viewportMetaEnabled)                                                                                               \
            return;                                                                                                                                     \
        m_viewportMetaEnabled = viewportMetaEnabled;                                                                                                    \
        invalidate(SettingsDelegate::ViewportDescriptionChange);                                                                                        \
    }                                                                                                                                                   \
    void Settings::setViewportMetaMergeContentQuirk(bool viewportMetaMergeContentQuirk)                                                                 \
    {                                                                                                                                                   \
        if (m_viewportMetaMergeContentQuirk == viewportMetaMergeContentQuirk)                                                                           \
            return;                                                                                                                                     \
        m_viewportMetaMergeContentQuirk = viewportMetaMergeContentQuirk;                                                                                \
    }                                                                                                                                                   \
    void Settings::setViewportMetaZeroValuesQuirk(bool viewportMetaZeroValuesQuirk)                                                                     \
    {                                                                                                                                                   \
        if (m_viewportMetaZeroValuesQuirk == viewportMetaZeroValuesQuirk)                                                                               \
            return;                                                                                                                                     \
        m_viewportMetaZeroValuesQuirk = viewportMetaZeroValuesQuirk;                                                                                    \
    }                                                                                                                                                   \
    void Settings::setViewportStyle(WebViewportStyle viewportStyle)                                                                                     \
    {                                                                                                                                                   \
        if (m_viewportStyle == viewportStyle)                                                                                                           \
            return;                                                                                                                                     \
        m_viewportStyle = viewportStyle;                                                                                                                \
        invalidate(SettingsDelegate::ViewportRuleChange);                                                                                               \
    }                                                                                                                                                   \
    void Settings::setWebGLEnabled(bool webGLEnabled)                                                                                                   \
    {                                                                                                                                                   \
        if (m_webGLEnabled == webGLEnabled)                                                                                                             \
            return;                                                                                                                                     \
        m_webGLEnabled = webGLEnabled;                                                                                                                  \
    }                                                                                                                                                   \
    void Settings::setWebGLErrorsToConsoleEnabled(bool webGLErrorsToConsoleEnabled)                                                                     \
    {                                                                                                                                                   \
        if (m_webGLErrorsToConsoleEnabled == webGLErrorsToConsoleEnabled)                                                                               \
            return;                                                                                                                                     \
        m_webGLErrorsToConsoleEnabled = webGLErrorsToConsoleEnabled;                                                                                    \
    }                                                                                                                                                   \
    void Settings::setWebSecurityEnabled(bool webSecurityEnabled)                                                                                       \
    {                                                                                                                                                   \
        if (m_webSecurityEnabled == webSecurityEnabled)                                                                                                 \
            return;                                                                                                                                     \
        m_webSecurityEnabled = webSecurityEnabled;                                                                                                      \
    }                                                                                                                                                   \
    void Settings::setWideViewportQuirkEnabled(bool wideViewportQuirkEnabled)                                                                           \
    {                                                                                                                                                   \
        if (m_wideViewportQuirkEnabled == wideViewportQuirkEnabled)                                                                                     \
            return;                                                                                                                                     \
        m_wideViewportQuirkEnabled = wideViewportQuirkEnabled;                                                                                          \
    }                                                                                                                                                   \
    void Settings::setXSSAuditorEnabled(bool xssAuditorEnabled)                                                                                         \
    {                                                                                                                                                   \
        if (m_xssAuditorEnabled == xssAuditorEnabled)                                                                                                   \
            return;                                                                                                                                     \
        m_xssAuditorEnabled = xssAuditorEnabled;                                                                                                        \
    }                                                                                                                                                   \
    void Settings::setFromStrings(const String& name, const String& value)                                                                              \
    {                                                                                                                                                   \
        if (name == "DOMPasteAllowed") {                                                                                                                \
            setDOMPasteAllowed(                                                                                                                         \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "accelerated2dCanvasMSAASampleCount") {                                                                                             \
            setAccelerated2dCanvasMSAASampleCount(                                                                                                      \
                value.toInt());                                                                                                                         \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "acceleratedCompositingEnabled") {                                                                                                  \
            setAcceleratedCompositingEnabled(                                                                                                           \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "accessibilityEnabled") {                                                                                                           \
            setAccessibilityEnabled(                                                                                                                    \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "accessibilityFontScaleFactor") {                                                                                                   \
            setAccessibilityFontScaleFactor(                                                                                                            \
                value.toDouble());                                                                                                                      \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "accessibilityPasswordValuesEnabled") {                                                                                             \
            setAccessibilityPasswordValuesEnabled(                                                                                                      \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "allowCustomScrollbarInMainFrame") {                                                                                                \
            setAllowCustomScrollbarInMainFrame(                                                                                                         \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "allowFileAccessFromFileURLs") {                                                                                                    \
            setAllowFileAccessFromFileURLs(                                                                                                             \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "allowGeolocationOnInsecureOrigins") {                                                                                              \
            setAllowGeolocationOnInsecureOrigins(                                                                                                       \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "allowRunningOfInsecureContent") {                                                                                                  \
            setAllowRunningOfInsecureContent(                                                                                                           \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "allowScriptsToCloseWindows") {                                                                                                     \
            setAllowScriptsToCloseWindows(                                                                                                              \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "allowUniversalAccessFromFileURLs") {                                                                                               \
            setAllowUniversalAccessFromFileURLs(                                                                                                        \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "alwaysShowContextMenuOnTouch") {                                                                                                   \
            setAlwaysShowContextMenuOnTouch(                                                                                                            \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "antialiased2dCanvasEnabled") {                                                                                                     \
            setAntialiased2dCanvasEnabled(                                                                                                              \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "antialiasedClips2dCanvasEnabled") {                                                                                                \
            setAntialiasedClips2dCanvasEnabled(                                                                                                         \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "availableHoverTypes") {                                                                                                            \
            setAvailableHoverTypes(                                                                                                                     \
                value.toInt());                                                                                                                         \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "availablePointerTypes") {                                                                                                          \
            setAvailablePointerTypes(                                                                                                                   \
                value.toInt());                                                                                                                         \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "backgroundHtmlParserOutstandingTokenLimit") {                                                                                      \
            setBackgroundHtmlParserOutstandingTokenLimit(                                                                                               \
                static_cast<unsigned>(value.toInt()));                                                                                                  \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "backgroundHtmlParserPendingTokenLimit") {                                                                                          \
            setBackgroundHtmlParserPendingTokenLimit(                                                                                                   \
                static_cast<unsigned>(value.toInt()));                                                                                                  \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "browserSideNavigationEnabled") {                                                                                                   \
            setBrowserSideNavigationEnabled(                                                                                                            \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "cookieEnabled") {                                                                                                                  \
            setCookieEnabled(                                                                                                                           \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "crossOriginMediaPlaybackRequiresUserGesture") {                                                                                    \
            setCrossOriginMediaPlaybackRequiresUserGesture(                                                                                             \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "cssExternalScannerNoPreload") {                                                                                                    \
            setCSSExternalScannerNoPreload(                                                                                                             \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "cssExternalScannerPreload") {                                                                                                      \
            setCSSExternalScannerPreload(                                                                                                               \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "dataSaverEnabled") {                                                                                                               \
            setDataSaverEnabled(                                                                                                                        \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "defaultFixedFontSize") {                                                                                                           \
            setDefaultFixedFontSize(                                                                                                                    \
                value.toInt());                                                                                                                         \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "defaultFontSize") {                                                                                                                \
            setDefaultFontSize(                                                                                                                         \
                value.toInt());                                                                                                                         \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "defaultTextEncodingName") {                                                                                                        \
            setDefaultTextEncodingName(                                                                                                                 \
                value);                                                                                                                                 \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "defaultVideoPosterURL") {                                                                                                          \
            setDefaultVideoPosterURL(                                                                                                                   \
                value);                                                                                                                                 \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "deviceScaleAdjustment") {                                                                                                          \
            setDeviceScaleAdjustment(                                                                                                                   \
                value.toDouble());                                                                                                                      \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "deviceSupportsTouch") {                                                                                                            \
            setDeviceSupportsTouch(                                                                                                                     \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "disableReadingFromCanvas") {                                                                                                       \
            setDisableReadingFromCanvas(                                                                                                                \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "disallowFetchForDocWrittenScriptsInMainFrame") {                                                                                   \
            setDisallowFetchForDocWrittenScriptsInMainFrame(                                                                                            \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G") {                                                                    \
            setDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(                                                                             \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections") {                                                                  \
            setDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(                                                                           \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "displayModeOverride") {                                                                                                            \
            setDisplayModeOverride(                                                                                                                     \
                static_cast<WebDisplayMode>(value.toInt()));                                                                                            \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "dnsPrefetchingEnabled") {                                                                                                          \
            setDNSPrefetchingEnabled(                                                                                                                   \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "doHtmlPreloadScanning") {                                                                                                          \
            setDoHtmlPreloadScanning(                                                                                                                   \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "downloadableBinaryFontsEnabled") {                                                                                                 \
            setDownloadableBinaryFontsEnabled(                                                                                                          \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "editingBehaviorType") {                                                                                                            \
            setEditingBehaviorType(                                                                                                                     \
                static_cast<EditingBehaviorType>(value.toInt()));                                                                                       \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "encryptedMediaEnabled") {                                                                                                          \
            setEncryptedMediaEnabled(                                                                                                                   \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "fetchImagePlaceholders") {                                                                                                         \
            setFetchImagePlaceholders(                                                                                                                  \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "forceMainWorldInitialization") {                                                                                                   \
            setForceMainWorldInitialization(                                                                                                            \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "forcePreloadNoneForMediaElements") {                                                                                               \
            setForcePreloadNoneForMediaElements(                                                                                                        \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "forceZeroLayoutHeight") {                                                                                                          \
            setForceZeroLayoutHeight(                                                                                                                   \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "fullscreenSupported") {                                                                                                            \
            setFullscreenSupported(                                                                                                                     \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "hideDownloadUI") {                                                                                                                 \
            setHideDownloadUI(                                                                                                                          \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "hideScrollbars") {                                                                                                                 \
            setHideScrollbars(                                                                                                                          \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "historyEntryRequiresUserGesture") {                                                                                                \
            setHistoryEntryRequiresUserGesture(                                                                                                         \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "hyperlinkAuditingEnabled") {                                                                                                       \
            setHyperlinkAuditingEnabled(                                                                                                                \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "ignoreMainFrameOverflowHiddenQuirk") {                                                                                             \
            setIgnoreMainFrameOverflowHiddenQuirk(                                                                                                      \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "imageAnimationPolicy") {                                                                                                           \
            setImageAnimationPolicy(                                                                                                                    \
                static_cast<ImageAnimationPolicy>(value.toInt()));                                                                                      \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "imagesEnabled") {                                                                                                                  \
            setImagesEnabled(                                                                                                                           \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "inertVisualViewport") {                                                                                                            \
            setInertVisualViewport(                                                                                                                     \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "inlineTextBoxAccessibilityEnabled") {                                                                                              \
            setInlineTextBoxAccessibilityEnabled(                                                                                                       \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "javaScriptCanAccessClipboard") {                                                                                                   \
            setJavaScriptCanAccessClipboard(                                                                                                            \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "javaScriptCanOpenWindowsAutomatically") {                                                                                          \
            setJavaScriptCanOpenWindowsAutomatically(                                                                                                   \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "layerSquashingEnabled") {                                                                                                          \
            setLayerSquashingEnabled(                                                                                                                   \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "loadWithOverviewMode") {                                                                                                           \
            setLoadWithOverviewMode(                                                                                                                    \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "loadsImagesAutomatically") {                                                                                                       \
            setLoadsImagesAutomatically(                                                                                                                \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "localStorageEnabled") {                                                                                                            \
            setLocalStorageEnabled(                                                                                                                     \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "logDnsPrefetchAndPreconnect") {                                                                                                    \
            setLogDnsPrefetchAndPreconnect(                                                                                                             \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "logPreload") {                                                                                                                     \
            setLogPreload(                                                                                                                              \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "lowPriorityIframes") {                                                                                                             \
            setLowPriorityIframes(                                                                                                                      \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "mainFrameClipsContent") {                                                                                                          \
            setMainFrameClipsContent(                                                                                                                   \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "mainFrameResizesAreOrientationChanges") {                                                                                          \
            setMainFrameResizesAreOrientationChanges(                                                                                                   \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "maxBeaconTransmission") {                                                                                                          \
            setMaxBeaconTransmission(                                                                                                                   \
                value.toInt());                                                                                                                         \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "maxTouchPoints") {                                                                                                                 \
            setMaxTouchPoints(                                                                                                                          \
                value.toInt());                                                                                                                         \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "mediaControlsOverlayPlayButtonEnabled") {                                                                                          \
            setMediaControlsOverlayPlayButtonEnabled(                                                                                                   \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "mediaPlaybackRequiresUserGesture") {                                                                                               \
            setMediaPlaybackRequiresUserGesture(                                                                                                        \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "mediaTypeOverride") {                                                                                                              \
            setMediaTypeOverride(                                                                                                                       \
                value);                                                                                                                                 \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "minimumAccelerated2dCanvasSize") {                                                                                                 \
            setMinimumAccelerated2dCanvasSize(                                                                                                          \
                value.toInt());                                                                                                                         \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "minimumFontSize") {                                                                                                                \
            setMinimumFontSize(                                                                                                                         \
                value.toInt());                                                                                                                         \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "minimumLogicalFontSize") {                                                                                                         \
            setMinimumLogicalFontSize(                                                                                                                  \
                value.toInt());                                                                                                                         \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "mockGestureTapHighlightsEnabled") {                                                                                                \
            setMockGestureTapHighlightsEnabled(                                                                                                         \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "multiTargetTapNotificationEnabled") {                                                                                              \
            setMultiTargetTapNotificationEnabled(                                                                                                       \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "navigateOnDragDrop") {                                                                                                             \
            setNavigateOnDragDrop(                                                                                                                      \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "offlineWebApplicationCacheEnabled") {                                                                                              \
            setOfflineWebApplicationCacheEnabled(                                                                                                       \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "parseHTMLOnMainThreadCoalesceChunks") {                                                                                            \
            setParseHTMLOnMainThreadCoalesceChunks(                                                                                                     \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "parseHTMLOnMainThreadSyncTokenize") {                                                                                              \
            setParseHTMLOnMainThreadSyncTokenize(                                                                                                       \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "passiveListenerDefault") {                                                                                                         \
            setPassiveListenerDefault(                                                                                                                  \
                static_cast<PassiveListenerDefault>(value.toInt()));                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "passwordEchoDurationInSeconds") {                                                                                                  \
            setPasswordEchoDurationInSeconds(                                                                                                           \
                value.toDouble());                                                                                                                      \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "passwordEchoEnabled") {                                                                                                            \
            setPasswordEchoEnabled(                                                                                                                     \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "pluginsEnabled") {                                                                                                                 \
            setPluginsEnabled(                                                                                                                          \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "preferCompositingToLCDTextEnabled") {                                                                                              \
            setPreferCompositingToLCDTextEnabled(                                                                                                       \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "preferHiddenVolumeControls") {                                                                                                     \
            setPreferHiddenVolumeControls(                                                                                                              \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "presentationReceiver") {                                                                                                           \
            setPresentationReceiver(                                                                                                                    \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "presentationRequiresUserGesture") {                                                                                                \
            setPresentationRequiresUserGesture(                                                                                                         \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "primaryHoverType") {                                                                                                               \
            setPrimaryHoverType(                                                                                                                        \
                static_cast<HoverType>(value.toInt()));                                                                                                 \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "primaryPointerType") {                                                                                                             \
            setPrimaryPointerType(                                                                                                                      \
                static_cast<PointerType>(value.toInt()));                                                                                               \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "progressBarCompletion") {                                                                                                          \
            setProgressBarCompletion(                                                                                                                   \
                static_cast<ProgressBarCompletion>(value.toInt()));                                                                                     \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "reportScreenSizeInPhysicalPixelsQuirk") {                                                                                          \
            setReportScreenSizeInPhysicalPixelsQuirk(                                                                                                   \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "rubberBandingOnCompositorThread") {                                                                                                \
            setRubberBandingOnCompositorThread(                                                                                                         \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "scriptEnabled") {                                                                                                                  \
            setScriptEnabled(                                                                                                                           \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "scrollAnimatorEnabled") {                                                                                                          \
            setScrollAnimatorEnabled(                                                                                                                   \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "selectTrailingWhitespaceEnabled") {                                                                                                \
            setSelectTrailingWhitespaceEnabled(                                                                                                         \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "selectionIncludesAltImageText") {                                                                                                  \
            setSelectionIncludesAltImageText(                                                                                                           \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "selectionStrategy") {                                                                                                              \
            setSelectionStrategy(                                                                                                                       \
                static_cast<SelectionStrategy>(value.toInt()));                                                                                         \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "shouldClearDocumentBackground") {                                                                                                  \
            setShouldClearDocumentBackground(                                                                                                           \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "shouldPrintBackgrounds") {                                                                                                         \
            setShouldPrintBackgrounds(                                                                                                                  \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "shouldRespectImageOrientation") {                                                                                                  \
            setShouldRespectImageOrientation(                                                                                                           \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "shouldReuseGlobalForUnownedMainFrame") {                                                                                           \
            setShouldReuseGlobalForUnownedMainFrame(                                                                                                    \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "showContextMenuOnMouseUp") {                                                                                                       \
            setShowContextMenuOnMouseUp(                                                                                                                \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "smartInsertDeleteEnabled") {                                                                                                       \
            setSmartInsertDeleteEnabled(                                                                                                                \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "spatialNavigationEnabled") {                                                                                                       \
            setSpatialNavigationEnabled(                                                                                                                \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "spellCheckEnabledByDefault") {                                                                                                     \
            setSpellCheckEnabledByDefault(                                                                                                              \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "strictMixedContentChecking") {                                                                                                     \
            setStrictMixedContentChecking(                                                                                                              \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "strictMixedContentCheckingForPlugin") {                                                                                            \
            setStrictMixedContentCheckingForPlugin(                                                                                                     \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "strictPowerfulFeatureRestrictions") {                                                                                              \
            setStrictPowerfulFeatureRestrictions(                                                                                                       \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "strictlyBlockBlockableMixedContent") {                                                                                             \
            setStrictlyBlockBlockableMixedContent(                                                                                                      \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "supportsMultipleWindows") {                                                                                                        \
            setSupportsMultipleWindows(                                                                                                                 \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "syncXHRInDocumentsEnabled") {                                                                                                      \
            setSyncXHRInDocumentsEnabled(                                                                                                               \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "textAreasAreResizable") {                                                                                                          \
            setTextAreasAreResizable(                                                                                                                   \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "textTrackBackgroundColor") {                                                                                                       \
            setTextTrackBackgroundColor(                                                                                                                \
                value);                                                                                                                                 \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "textTrackFontFamily") {                                                                                                            \
            setTextTrackFontFamily(                                                                                                                     \
                value);                                                                                                                                 \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "textTrackFontStyle") {                                                                                                             \
            setTextTrackFontStyle(                                                                                                                      \
                value);                                                                                                                                 \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "textTrackFontVariant") {                                                                                                           \
            setTextTrackFontVariant(                                                                                                                    \
                value);                                                                                                                                 \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "textTrackKindUserPreference") {                                                                                                    \
            setTextTrackKindUserPreference(                                                                                                             \
                static_cast<TextTrackKindUserPreference>(value.toInt()));                                                                               \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "textTrackMarginPercentage") {                                                                                                      \
            setTextTrackMarginPercentage(                                                                                                               \
                value.toDouble());                                                                                                                      \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "textTrackTextColor") {                                                                                                             \
            setTextTrackTextColor(                                                                                                                      \
                value);                                                                                                                                 \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "textTrackTextShadow") {                                                                                                            \
            setTextTrackTextShadow(                                                                                                                     \
                value);                                                                                                                                 \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "textTrackTextSize") {                                                                                                              \
            setTextTrackTextSize(                                                                                                                       \
                value);                                                                                                                                 \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "threadedScrollingEnabled") {                                                                                                       \
            setThreadedScrollingEnabled(                                                                                                                \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "touchAdjustmentEnabled") {                                                                                                         \
            setTouchAdjustmentEnabled(                                                                                                                  \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "touchDragDropEnabled") {                                                                                                           \
            setTouchDragDropEnabled(                                                                                                                    \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "touchEditingEnabled") {                                                                                                            \
            setTouchEditingEnabled(                                                                                                                     \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "useDefaultImageInterpolationQuality") {                                                                                            \
            setUseDefaultImageInterpolationQuality(                                                                                                     \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "useLegacyBackgroundSizeShorthandBehavior") {                                                                                       \
            setUseLegacyBackgroundSizeShorthandBehavior(                                                                                                \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "useSolidColorScrollbars") {                                                                                                        \
            setUseSolidColorScrollbars(                                                                                                                 \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "useWideViewport") {                                                                                                                \
            setUseWideViewport(                                                                                                                         \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "v8CacheOptions") {                                                                                                                 \
            setV8CacheOptions(                                                                                                                          \
                static_cast<V8CacheOptions>(value.toInt()));                                                                                            \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "v8CacheStrategiesForCacheStorage") {                                                                                               \
            setV8CacheStrategiesForCacheStorage(                                                                                                        \
                static_cast<V8CacheStrategiesForCacheStorage>(value.toInt()));                                                                          \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "validationMessageTimerMagnification") {                                                                                            \
            setValidationMessageTimerMagnification(                                                                                                     \
                value.toInt());                                                                                                                         \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "viewportEnabled") {                                                                                                                \
            setViewportEnabled(                                                                                                                         \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "viewportMetaEnabled") {                                                                                                            \
            setViewportMetaEnabled(                                                                                                                     \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "viewportMetaMergeContentQuirk") {                                                                                                  \
            setViewportMetaMergeContentQuirk(                                                                                                           \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "viewportMetaZeroValuesQuirk") {                                                                                                    \
            setViewportMetaZeroValuesQuirk(                                                                                                             \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "viewportStyle") {                                                                                                                  \
            setViewportStyle(                                                                                                                           \
                static_cast<WebViewportStyle>(value.toInt()));                                                                                          \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "webGLEnabled") {                                                                                                                   \
            setWebGLEnabled(                                                                                                                            \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "webGLErrorsToConsoleEnabled") {                                                                                                    \
            setWebGLErrorsToConsoleEnabled(                                                                                                             \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "webSecurityEnabled") {                                                                                                             \
            setWebSecurityEnabled(                                                                                                                      \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "wideViewportQuirkEnabled") {                                                                                                       \
            setWideViewportQuirkEnabled(                                                                                                                \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
        if (name == "xssAuditorEnabled") {                                                                                                              \
            setXSSAuditorEnabled(                                                                                                                       \
                value.isEmpty() || value == "true");                                                                                                    \
            return;                                                                                                                                     \
        }                                                                                                                                               \
    }
// End of SETTINGS_SETTER_BODIES.

#endif // SettingsMacros_h
