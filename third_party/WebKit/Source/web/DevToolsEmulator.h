// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DevToolsEmulator_h
#define DevToolsEmulator_h

<<<<<<< HEAD
#include "platform/heap/Handle.h"
#include "public/platform/PointerProperties.h"
#include "public/platform/WebFloatPoint.h"
#include "public/platform/WebViewportStyle.h"
#include "public/web/WebDeviceEmulationParams.h"
#include "web/WebExport.h"
#include "wtf/Forward.h"
#include "wtf/Optional.h"
#include <memory>

namespace blink {

class IntPoint;
class IntRect;
class TransformationMatrix;
class WebInputEvent;
class WebViewImpl;

class WEB_EXPORT DevToolsEmulator final
    : public GarbageCollectedFinalized<DevToolsEmulator> {
public:
    ~DevToolsEmulator();
    static DevToolsEmulator* create(WebViewImpl*);
    DECLARE_TRACE();
=======
#include "wtf/Forward.h"
#include "wtf/OwnPtr.h"

namespace blink {

class InspectorEmulationAgent;
class IntPoint;
class WebInputEvent;
class WebViewImpl;

struct WebDeviceEmulationParams;

class DevToolsEmulator final {
public:
    explicit DevToolsEmulator(WebViewImpl*);
    ~DevToolsEmulator();

    void setEmulationAgent(InspectorEmulationAgent*);
    void viewportChanged();
>>>>>>> miniblink49

    // Settings overrides.
    void setTextAutosizingEnabled(bool);
    void setDeviceScaleAdjustment(float);
    void setPreferCompositingToLCDTextEnabled(bool);
<<<<<<< HEAD
    void setViewportStyle(WebViewportStyle);
=======
    void setUseMobileViewportStyle(bool);
>>>>>>> miniblink49
    void setPluginsEnabled(bool);
    void setScriptEnabled(bool);
    void setDoubleTapToZoomEnabled(bool);
    bool doubleTapToZoomEnabled() const;
<<<<<<< HEAD
    void setAvailablePointerTypes(int);
    void setPrimaryPointerType(PointerType);
    void setAvailableHoverTypes(int);
    void setPrimaryHoverType(HoverType);
    void setMainFrameResizesAreOrientationChanges(bool);
=======
>>>>>>> miniblink49

    // Emulation.
    void enableDeviceEmulation(const WebDeviceEmulationParams&);
    void disableDeviceEmulation();
<<<<<<< HEAD
    // Position is given in CSS pixels, scale relative to a page scale of 1.0.
    void forceViewport(const WebFloatPoint& position, float scale);
    void resetViewport();
    bool resizeIsDeviceSizeChange();
=======
    bool deviceEmulationEnabled() { return m_deviceMetricsEnabled; }
>>>>>>> miniblink49
    void setTouchEventEmulationEnabled(bool);
    bool handleInputEvent(const WebInputEvent&);
    void setScriptExecutionDisabled(bool);

<<<<<<< HEAD
    // Notify the DevToolsEmulator about a scroll or scale change of the main
    // frame. Updates the transform for a viewport override.
    void mainFrameScrollOrScaleChanged();

    // Returns a custom visible content rect if a viewport override is active.
    // This ensures that all content inside the forced viewport is painted.
    WTF::Optional<IntRect> visibleContentRectForPainting() const;

private:
    explicit DevToolsEmulator(WebViewImpl*);

    void enableMobileEmulation();
    void disableMobileEmulation();

    // Returns the original device scale factor when overridden by DevTools, or
    // deviceScaleFactor() otherwise.
    float compositorDeviceScaleFactor() const;

    void applyDeviceEmulationTransform(TransformationMatrix*);
    void applyViewportOverride(TransformationMatrix*);
    void updateRootLayerTransform();

    WebViewImpl* m_webViewImpl;

    bool m_deviceMetricsEnabled;
    bool m_emulateMobileEnabled;
    WebDeviceEmulationParams m_emulationParams;

    struct ViewportOverride {
        WebFloatPoint position;
        double scale;
        bool originalVisualViewportMasking;
    };
    WTF::Optional<ViewportOverride> m_viewportOverride;

    bool m_isOverlayScrollbarsEnabled;
    bool m_isOrientationEventEnabled;
    bool m_isMobileLayoutThemeEnabled;
=======
private:
    void enableMobileEmulation();
    void disableMobileEmulation();


    WebViewImpl* m_webViewImpl;
#ifdef IMPLEMENTED_NEWEST_BLINK
    InspectorEmulationAgent* m_emulationAgent;
#endif // IMPLEMENTED_NEWEST_BLINK
    bool m_deviceMetricsEnabled;
    bool m_emulateMobileEnabled;
    bool m_isOverlayScrollbarsEnabled;
>>>>>>> miniblink49
    float m_originalDefaultMinimumPageScaleFactor;
    float m_originalDefaultMaximumPageScaleFactor;
    bool m_embedderTextAutosizingEnabled;
    float m_embedderDeviceScaleAdjustment;
    bool m_embedderPreferCompositingToLCDTextEnabled;
<<<<<<< HEAD
    WebViewportStyle m_embedderViewportStyle;
    bool m_embedderPluginsEnabled;
    int m_embedderAvailablePointerTypes;
    PointerType m_embedderPrimaryPointerType;
    int m_embedderAvailableHoverTypes;
    HoverType m_embedderPrimaryHoverType;
    bool m_embedderMainFrameResizesAreOrientationChanges;

    bool m_touchEventEmulationEnabled;
    bool m_doubleTapToZoomEnabled;
    bool m_originalTouchEventFeatureDetectionEnabled;
    bool m_originalDeviceSupportsTouch;
    int m_originalMaxTouchPoints;
    std::unique_ptr<IntPoint> m_lastPinchAnchorCss;
    std::unique_ptr<IntPoint> m_lastPinchAnchorDip;
=======
    bool m_embedderUseMobileViewport;
    bool m_embedderPluginsEnabled;

    bool m_touchEventEmulationEnabled;
    bool m_doubleTapToZoomEnabled;
    bool m_originalTouchEnabled;
    bool m_originalDeviceSupportsMouse;
    bool m_originalDeviceSupportsTouch;
    int m_originalMaxTouchPoints;
    OwnPtr<IntPoint> m_lastPinchAnchorCss;
    OwnPtr<IntPoint> m_lastPinchAnchorDip;
>>>>>>> miniblink49

    bool m_embedderScriptEnabled;
    bool m_scriptExecutionDisabled;
};

} // namespace blink

#endif
