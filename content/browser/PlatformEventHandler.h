
#ifndef content_browser_PlatformEventHandler_h
#define content_browser_PlatformEventHandler_h

#include "third_party/WebKit/public/platform/WebInputEvent.h"
#include "third_party/WebKit/Source/platform/geometry/IntRect.h"
#include "third_party/WebKit/Source/platform/geometry/FloatPoint.h"
#include "third_party/WebKit/Source/platform/Timer.h"
#include "third_party/WebKit/Source/wtf/OwnPtr.h"

namespace blink {
class WebViewImpl;
class WebWidget;
class WebTouchEvent;
class WebTouchPoint;
}

namespace content {

class TouchEmulator {
public:
    TouchEmulator(blink::WebWidget* webWidget);

    void handleMouseDown(HWND hWnd, blink::WebTouchEvent* touchEvent, blink::WebTouchPoint* touchPoint);
    void handleMouseUp(HWND hWnd, blink::WebTouchEvent* touchEvent, blink::WebTouchPoint* touchPoint);
    void handleMouseMove(HWND hWnd, blink::WebTouchEvent* touchEvent, blink::WebTouchPoint* touchPoint);

private:
    void gestureShowPressTimer(blink::TimerBase*);
    void gestureLongPressTimer(blink::TimerBase*);

    blink::WebWidget* m_webWidget;

    blink::Timer<TouchEmulator> m_gestureShowPressTimer;
    blink::Timer<TouchEmulator> m_gestureLongPressTimer;
    bool m_isLongPress; // ������Ϊtrue��ֱ��̧����ָ
    bool m_isPressState;
    bool m_isScrollState;

    blink::FloatPoint m_lastTouchDownPoint;
    bool m_isValidLastTouchDownPoint;
};

class PlatformEventHandler {
public:
    PlatformEventHandler(blink::WebWidget* webWidget, blink::WebViewImpl* webViewImpl);
    static blink::WebKeyboardEvent buildKeyboardEvent(blink::WebInputEvent::Type type, UINT message, WPARAM wParam, LPARAM lParam);

    struct MouseEvtInfo {
        bool isNeedSetFocus;
        bool isWillDestroy;
        HRGN draggableRegion;
    };
    LRESULT fireMouseEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, const MouseEvtInfo& info, BOOL* bHandle);
    LRESULT fireWheelEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void fireCaptureChangedEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void fireTouchEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void fireRealTouchEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void fireRealTouchEventTest(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    
    void checkMouseLeave(blink::TimerBase*);

    bool fireMouseUpEventIfNeeded(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, const MouseEvtInfo& info, BOOL* bHandle);
    void buildMousePosInfo(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, bool* handle, blink::IntPoint* pos, blink::IntPoint* globalPos);

    void setIsDraggableNodeMousedown();

    void setTouchSimulateEnabled(bool b) { m_enableTouchSimulate = b; }
    void setSystemTouchEnabled(bool b) { m_enableSystemTouch = b; }

    void setHwndRenderOffset(const blink::IntPoint& offset) { m_offset = offset; }
    blink::IntPoint getHwndRenderOffset() const { return m_offset; }

private:
    bool isDraggableRegionNcHitTest(HWND hWnd, const blink::IntPoint& pos, HRGN draggableRegion);
    bool m_isDraggableRegionNcHitTest;
    bool m_postMouseLeave;
    bool m_mouseInWindow;
    bool m_isAlert;
    bool m_isDraggableNodeMousedown;
    bool m_isLeftMousedown;
    double m_lastTimeMouseDown;
    blink::IntPoint m_offset;
    blink::IntPoint m_lastPosMouseDown;
    blink::IntPoint m_lastPosMouseMove;
    blink::IntRect m_lastPosForDrag;
    blink::WebViewImpl* m_webViewImpl;
    blink::WebWidget* m_webWidget;
    bool m_enableTouchSimulate;
    bool m_enableSystemTouch;

    TouchEmulator m_touchEmulator;

    blink::FloatPoint m_lastTouchDownPoint;
    bool m_isValidLastTouchDownPoint;

    HWND m_hWnd;
    blink::Timer<PlatformEventHandler> m_checkMouseLeaveTimer;
};

} // content

#endif // content_browser_PlatformEventHandler_h