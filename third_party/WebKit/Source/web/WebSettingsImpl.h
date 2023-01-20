/*
 * Copyright (C) 2009 Google Inc. All rights reserved.
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

#ifndef WebSettingsImpl_h
#define WebSettingsImpl_h

<<<<<<< HEAD
#include "third_party/WebKit/Source/config.h"
#include "platform/heap/Handle.h"
#include "public/web/WebSettings.h"
#include "web/WebExport.h"
#include "wtf/Compiler.h"
=======
#include "public/web/WebSettings.h"
>>>>>>> miniblink49

namespace blink {

class DevToolsEmulator;
class Settings;

<<<<<<< HEAD
class WEB_EXPORT WebSettingsImpl final : NON_EXPORTED_BASE(public WebSettings) {
=======
class WebSettingsImpl final : public WebSettings {
>>>>>>> miniblink49
public:
    WebSettingsImpl(Settings*, DevToolsEmulator*);
    virtual ~WebSettingsImpl() { }

    void setFromStrings(const WebString& name, const WebString& value) override;

<<<<<<< HEAD
    bool shrinksViewportContentToFit() const override;
    bool viewportEnabled() const override;
=======
    bool mainFrameResizesAreOrientationChanges() const override;
    bool shrinksViewportContentToFit() const override;
    int availablePointerTypes() const override;
    PointerType primaryPointerType() const override;
    int availableHoverTypes() const override;
    HoverType primaryHoverType() const override;
    bool viewportEnabled() const override;
    void setAccelerated2dCanvasEnabled(bool) override;
>>>>>>> miniblink49
    void setAccelerated2dCanvasMSAASampleCount(int) override;
    void setAcceleratedCompositingEnabled(bool) override;
    void setPreferCompositingToLCDTextEnabled(bool) override;
    void setAccessibilityEnabled(bool) override;
    void setAccessibilityPasswordValuesEnabled(bool) override;
<<<<<<< HEAD
    void setAllowFileAccessFromFileURLs(bool) override;
    void setAllowCustomScrollbarInMainFrame(bool) override;
    void setAllowGeolocationOnInsecureOrigins(bool) override;
    void setAllowRunningOfInsecureContent(bool) override;
    void setAllowScriptsToCloseWindows(bool) override;
    void setAllowUniversalAccessFromFileURLs(bool) override;
    void setAlwaysShowContextMenuOnTouch(bool) override;
    void setAntialiased2dCanvasEnabled(bool) override;
    void setAntialiasedClips2dCanvasEnabled(bool) override;
    void setAutoZoomFocusedNodeToLegibleScale(bool) override;
    void setBrowserSideNavigationEnabled(bool) override;
    void setClobberUserAgentInitialScaleQuirk(bool) override;
    void setCookieEnabled(bool) override;
    void setCrossOriginMediaPlaybackRequiresUserGesture(bool) override;
    void setNavigateOnDragDrop(bool) override;
    void setCursiveFontFamily(const WebString&,
        UScriptCode = USCRIPT_COMMON) override;
    void setDNSPrefetchingEnabled(bool) override;
    void setDataSaverEnabled(bool) override;
=======
    void setAllowDisplayOfInsecureContent(bool) override;
    void setAllowFileAccessFromFileURLs(bool) override;
    void setAllowCustomScrollbarInMainFrame(bool) override;
    void setAllowRunningOfInsecureContent(bool) override;
    void setAllowScriptsToCloseWindows(bool) override;
    void setAllowUniversalAccessFromFileURLs(bool) override;
    void setAntialiased2dCanvasEnabled(bool) override;
    void setAntialiasedClips2dCanvasEnabled(bool) override;
    void setAsynchronousSpellCheckingEnabled(bool) override;
    void setAutoZoomFocusedNodeToLegibleScale(bool) override;
    void setCaretBrowsingEnabled(bool) override;
    void setClobberUserAgentInitialScaleQuirk(bool) override;
    void setCookieEnabled(bool) override;
    void setNavigateOnDragDrop(bool) override;
    void setCursiveFontFamily(const WebString&, UScriptCode = USCRIPT_COMMON) override;
    void setDNSPrefetchingEnabled(bool) override;
>>>>>>> miniblink49
    void setDOMPasteAllowed(bool) override;
    void setDefaultFixedFontSize(int) override;
    void setDefaultFontSize(int) override;
    void setDefaultTextEncodingName(const WebString&) override;
    void setDefaultVideoPosterURL(const WebString&) override;
    void setDeviceScaleAdjustment(float) override;

<<<<<<< HEAD
    // FIXME: Replace this with pointer/hover queries? crbug.com/441813
=======
    // FIXME: Replace these two with pointer/hover queries? crbug.com/441813
    void setDeviceSupportsMouse(bool) override;
>>>>>>> miniblink49
    void setDeviceSupportsTouch(bool) override;

    void setDisableReadingFromCanvas(bool) override;
    void setDoubleTapToZoomEnabled(bool) override;
    void setDownloadableBinaryFontsEnabled(bool) override;
    void setEditingBehavior(EditingBehavior) override;
    void setEnableScrollAnimator(bool) override;
    void setEnableTouchAdjustment(bool) override;
    bool multiTargetTapNotificationEnabled() override;
    void setMultiTargetTapNotificationEnabled(bool) override;
    void setExperimentalWebGLEnabled(bool) override;
<<<<<<< HEAD
    void setFantasyFontFamily(const WebString&,
        UScriptCode = USCRIPT_COMMON) override;
    void setFixedFontFamily(const WebString&,
        UScriptCode = USCRIPT_COMMON) override;
    void setForcePreloadNoneForMediaElements(bool) override;
    void setForceZeroLayoutHeight(bool) override;
    void setFullscreenSupported(bool) override;
    void setHideDownloadUI(bool) override;
    void setPresentationReceiver(bool) override;
    void setHistoryEntryRequiresUserGesture(bool) override;
=======
    void setFantasyFontFamily(const WebString&, UScriptCode = USCRIPT_COMMON) override;
    void setFixedFontFamily(const WebString&, UScriptCode = USCRIPT_COMMON) override;
    void setReportWheelOverscroll(bool) override;
    void setForceZeroLayoutHeight(bool) override;
    void setFullscreenSupported(bool) override;
>>>>>>> miniblink49
    void setHyperlinkAuditingEnabled(bool) override;
    void setIgnoreMainFrameOverflowHiddenQuirk(bool) override;
    void setImageAnimationPolicy(ImageAnimationPolicy) override;
    void setImagesEnabled(bool) override;
    void setInlineTextBoxAccessibilityEnabled(bool) override;
<<<<<<< HEAD
    void setInertVisualViewport(bool) override;
=======
    void setInvertViewportScrollOrder(bool) override;
    void setJavaEnabled(bool) override;
>>>>>>> miniblink49
    void setJavaScriptCanAccessClipboard(bool) override;
    void setJavaScriptCanOpenWindowsAutomatically(bool) override;
    void setJavaScriptEnabled(bool) override;
    void setLoadsImagesAutomatically(bool) override;
    void setLoadWithOverviewMode(bool) override;
<<<<<<< HEAD
    void setShouldReuseGlobalForUnownedMainFrame(bool) override;
    void setProgressBarCompletion(ProgressBarCompletion) override;
=======
>>>>>>> miniblink49
    void setLocalStorageEnabled(bool) override;
    void setMainFrameClipsContent(bool) override;
    void setMainFrameResizesAreOrientationChanges(bool) override;
    void setMaxTouchPoints(int) override;
    void setMediaControlsOverlayPlayButtonEnabled(bool) override;
    void setMediaPlaybackRequiresUserGesture(bool) override;
<<<<<<< HEAD
    void setPresentationRequiresUserGesture(bool) override;
=======
>>>>>>> miniblink49
    void setMinimumAccelerated2dCanvasSize(int) override;
    void setMinimumFontSize(int) override;
    void setMinimumLogicalFontSize(int) override;
    void setMockScrollbarsEnabled(bool) override;
<<<<<<< HEAD
    void setHideScrollbars(bool) override;
    void setOfflineWebApplicationCacheEnabled(bool) override;
    void setPassiveEventListenerDefault(PassiveEventListenerDefault) override;
    void setPasswordEchoDurationInSeconds(double) override;
    void setPasswordEchoEnabled(bool) override;
    void setPerTilePaintingEnabled(bool) override;
    void setPictographFontFamily(const WebString&,
        UScriptCode = USCRIPT_COMMON) override;
    void setPluginsEnabled(bool) override;
    void setEncryptedMediaEnabled(bool) override;
=======
    void setOfflineWebApplicationCacheEnabled(bool) override;
    void setOpenGLMultisamplingEnabled(bool) override;
    void setPasswordEchoDurationInSeconds(double) override;
    void setPasswordEchoEnabled(bool) override;
    void setPerTilePaintingEnabled(bool) override;
    void setPictographFontFamily(const WebString&, UScriptCode = USCRIPT_COMMON) override;
    void setPinchOverlayScrollbarThickness(int) override;
    void setPluginsEnabled(bool) override;
>>>>>>> miniblink49
    void setAvailablePointerTypes(int) override;
    void setPrimaryPointerType(PointerType) override;
    void setAvailableHoverTypes(int) override;
    void setPrimaryHoverType(HoverType) override;
<<<<<<< HEAD
    void setPreferHiddenVolumeControls(bool) override;
    void setRenderVSyncNotificationEnabled(bool) override;
    void setReportScreenSizeInPhysicalPixelsQuirk(bool) override;
    void setRubberBandingOnCompositorThread(bool) override;
    void setSansSerifFontFamily(const WebString&,
        UScriptCode = USCRIPT_COMMON) override;
    void setSelectTrailingWhitespaceEnabled(bool override);
    void setSelectionIncludesAltImageText(bool) override;
    void setSelectionStrategy(SelectionStrategyType) override;
    void setSerifFontFamily(const WebString&,
        UScriptCode = USCRIPT_COMMON) override;
=======
    void setRenderVSyncNotificationEnabled(bool) override;
    void setReportScreenSizeInPhysicalPixelsQuirk(bool) override;
    void setRootLayerScrolls(bool) override;
    void setRubberBandingOnCompositorThread(bool) override;
    void setSansSerifFontFamily(const WebString&, UScriptCode = USCRIPT_COMMON) override;
    void setSelectTrailingWhitespaceEnabled(bool) override;
    void setSelectionIncludesAltImageText(bool) override;
    void setSelectionStrategy(SelectionStrategyType) override;
    void setSerifFontFamily(const WebString&, UScriptCode = USCRIPT_COMMON) override;
>>>>>>> miniblink49
    void setShouldPrintBackgrounds(bool) override;
    void setShouldClearDocumentBackground(bool) override;
    void setShouldRespectImageOrientation(bool) override;
    void setShowContextMenuOnMouseUp(bool) override;
    void setShowFPSCounter(bool) override;
    void setShowPaintRects(bool) override;
    void setShrinksViewportContentToFit(bool) override;
    void setSmartInsertDeleteEnabled(bool) override;
    void setSpatialNavigationEnabled(bool) override;
<<<<<<< HEAD
    void setSpellCheckEnabledByDefault(bool) override;
    void setStandardFontFamily(const WebString&,
        UScriptCode = USCRIPT_COMMON) override;
    void setStrictMixedContentChecking(bool) override;
    void setStrictMixedContentCheckingForPlugin(bool) override;
    void setStrictPowerfulFeatureRestrictions(bool) override;
    void setStrictlyBlockBlockableMixedContent(bool) override;
=======
    void setStandardFontFamily(const WebString&, UScriptCode = USCRIPT_COMMON) override;
    void setStrictMixedContentChecking(bool) override;
    void setStrictPowerfulFeatureRestrictions(bool) override;
>>>>>>> miniblink49
    void setSupportDeprecatedTargetDensityDPI(bool) override;
    void setSupportsMultipleWindows(bool) override;
    void setSyncXHRInDocumentsEnabled(bool) override;
    void setTextAreasAreResizable(bool) override;
    void setTextAutosizingEnabled(bool) override;
    void setAccessibilityFontScaleFactor(float) override;
    void setTextTrackKindUserPreference(TextTrackKindUserPreference) override;
    void setTextTrackBackgroundColor(const WebString&) override;
    void setTextTrackFontFamily(const WebString&) override;
    void setTextTrackFontStyle(const WebString&) override;
    void setTextTrackFontVariant(const WebString&) override;
<<<<<<< HEAD
    void setTextTrackMarginPercentage(float) override;
=======
>>>>>>> miniblink49
    void setTextTrackTextColor(const WebString&) override;
    void setTextTrackTextShadow(const WebString&) override;
    void setTextTrackTextSize(const WebString&) override;
    void setThreadedScrollingEnabled(bool) override;
    void setTouchDragDropEnabled(bool) override;
<<<<<<< HEAD
    void setUseLegacyBackgroundSizeShorthandBehavior(bool) override;
    void setViewportStyle(WebViewportStyle) override;
    void setUseSolidColorScrollbars(bool) override;
    void setUseWideViewport(bool) override;
    void setV8CacheOptions(V8CacheOptions) override;
    void setV8CacheStrategiesForCacheStorage(
        V8CacheStrategiesForCacheStorage) override;
=======
    void setTouchEditingEnabled(bool) override;
    void setUnifiedTextCheckerEnabled(bool) override;
    void setUnsafePluginPastingEnabled(bool) override;
    void setUsesEncodingDetector(bool) override;
    void setUseLegacyBackgroundSizeShorthandBehavior(bool) override;
    void setUseMobileViewportStyle(bool) override;
    void setUseSolidColorScrollbars(bool) override;
    void setUseWideViewport(bool) override;
    void setV8CacheOptions(V8CacheOptions) override;
>>>>>>> miniblink49
    void setValidationMessageTimerMagnification(int) override;
    void setViewportEnabled(bool) override;
    void setViewportMetaEnabled(bool) override;
    void setViewportMetaLayoutSizeQuirk(bool) override;
    void setViewportMetaMergeContentQuirk(bool) override;
    void setViewportMetaNonUserScalableQuirk(bool) override;
    void setViewportMetaZeroValuesQuirk(bool) override;
<<<<<<< HEAD
=======
    void setWebAudioEnabled(bool) override;
>>>>>>> miniblink49
    void setWebGLErrorsToConsoleEnabled(bool) override;
    void setWebSecurityEnabled(bool) override;
    void setWideViewportQuirkEnabled(bool) override;
    void setXSSAuditorEnabled(bool) override;
<<<<<<< HEAD
    void setExpensiveBackgroundThrottlingCPUBudget(float) override;
    void setExpensiveBackgroundThrottlingInitialBudget(float) override;
    void setExpensiveBackgroundThrottlingMaxBudget(float) override;
    void setExpensiveBackgroundThrottlingMaxDelay(float) override;

    bool showFPSCounter() const { return m_showFPSCounter; }
    bool showPaintRects() const { return m_showPaintRects; }
    bool renderVSyncNotificationEnabled() const
    {
        return m_renderVSyncNotificationEnabled;
    }
    bool autoZoomFocusedNodeToLegibleScale() const
    {
        return m_autoZoomFocusedNodeToLegibleScale;
    }
    bool doubleTapToZoomEnabled() const;
    bool perTilePaintingEnabled() const { return m_perTilePaintingEnabled; }
    bool supportDeprecatedTargetDensityDPI() const
    {
        return m_supportDeprecatedTargetDensityDPI;
    }
    bool viewportMetaEnabled() const;
    bool viewportMetaLayoutSizeQuirk() const
    {
        return m_viewportMetaLayoutSizeQuirk;
    }
    bool viewportMetaNonUserScalableQuirk() const
    {
        return m_viewportMetaNonUserScalableQuirk;
    }
    bool clobberUserAgentInitialScaleQuirk() const
    {
        return m_clobberUserAgentInitialScaleQuirk;
    }
    float expensiveBackgroundThrottlingCPUBudget() const
    {
        return m_expensiveBackgroundThrottlingCPUBudget;
    }
    float expensiveBackgroundThrottlingInitialBudget() const
    {
        return m_expensiveBackgroundThrottlingInitialBudget;
    }
    float expensiveBackgroundThrottlingMaxDelay() const
    {
        return m_expensiveBackgroundThrottlingMaxDelay;
    }
    float expensiveBackgroundThrottlingMaxBudget() const
    {
        return m_expensiveBackgroundThrottlingMaxBudget;
    }
=======

    bool showFPSCounter() const { return m_showFPSCounter; }
    bool showPaintRects() const { return m_showPaintRects; }
    bool renderVSyncNotificationEnabled() const { return m_renderVSyncNotificationEnabled; }
    bool autoZoomFocusedNodeToLegibleScale() const { return m_autoZoomFocusedNodeToLegibleScale; }
    bool doubleTapToZoomEnabled() const;
    bool perTilePaintingEnabled() const { return m_perTilePaintingEnabled; }
    bool supportDeprecatedTargetDensityDPI() const { return m_supportDeprecatedTargetDensityDPI; }
    bool viewportMetaEnabled() const;
    bool viewportMetaLayoutSizeQuirk() const { return m_viewportMetaLayoutSizeQuirk; }
    bool viewportMetaNonUserScalableQuirk() const { return m_viewportMetaNonUserScalableQuirk; }
    bool clobberUserAgentInitialScaleQuirk() const { return m_clobberUserAgentInitialScaleQuirk; }
>>>>>>> miniblink49

    void setMockGestureTapHighlightsEnabled(bool);
    bool mockGestureTapHighlightsEnabled() const;

<<<<<<< HEAD
#ifdef TENCENT_FITSCREEN
    virtual bool getFitScreenEnabled() const override;
    virtual void setFitScreenEnabled(bool) override;
#endif

private:
    Settings* m_settings;
    UntracedMember<DevToolsEmulator> m_devToolsEmulator;
=======
private:
    Settings* m_settings;
    DevToolsEmulator* m_devToolsEmulator;
>>>>>>> miniblink49
    bool m_showFPSCounter;
    bool m_showPaintRects;
    bool m_renderVSyncNotificationEnabled;
    bool m_autoZoomFocusedNodeToLegibleScale;
    bool m_perTilePaintingEnabled;
    bool m_supportDeprecatedTargetDensityDPI;
    bool m_shrinksViewportContentToFit;
    // This quirk is to maintain compatibility with Android apps built on
    // the Android SDK prior to and including version 18. Presumably, this
    // can be removed any time after 2015. See http://crbug.com/277369.
    bool m_viewportMetaLayoutSizeQuirk;
    // This quirk is to maintain compatibility with Android apps built on
    // the Android SDK prior to and including version 18. Presumably, this
    // can be removed any time after 2015. See http://crbug.com/312691.
    bool m_viewportMetaNonUserScalableQuirk;
    // This quirk is to maintain compatibility with Android apps built on
    // the Android SDK prior to and including version 18. Presumably, this
    // can be removed any time after 2015. See http://crbug.com/313754.
    bool m_clobberUserAgentInitialScaleQuirk;
<<<<<<< HEAD
    float m_expensiveBackgroundThrottlingCPUBudget;
    float m_expensiveBackgroundThrottlingInitialBudget;
    float m_expensiveBackgroundThrottlingMaxBudget;
    float m_expensiveBackgroundThrottlingMaxDelay;
=======
    bool m_mainFrameResizesAreOrientationChanges;
>>>>>>> miniblink49
};

} // namespace blink

#endif
