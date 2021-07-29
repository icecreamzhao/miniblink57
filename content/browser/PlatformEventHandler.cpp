
#include "content/browser/PlatformEventHandler.h"

#include "third_party/WebKit/Source/web/WebViewImpl.h"
#include "third_party/WebKit/public/platform/WebMouseWheelEvent.h"
#include "third_party/WebKit/public/platform/WebInputEvent.h"
#include "third_party/WebKit/public/platform/WebMouseEvent.h"
#include "third_party/WebKit/public/web/WebLocalFrame.h"
#include "third_party/WebKit/public/web/WebFrameWidget.h"

#include "wtf/text/WTFString.h"
#include "wke/wkeGlobalVar.h"
#include "content/browser/TouchStruct.h"

using namespace blink;

namespace content {

static const unsigned short HIGH_BIT_MASK_SHORT = 0x8000;

// Source\WebCore\platform\win\KeyEventWin.cpp
static bool isKeypadEvent(WPARAM code, LPARAM keyData, WebInputEvent::Type type)
{
    if (type != WebInputEvent::RawKeyDown && type != WebInputEvent::KeyUp)
        return false;

    switch (code) {
    case VK_NUMLOCK:
    case VK_NUMPAD0:
    case VK_NUMPAD1:
    case VK_NUMPAD2:
    case VK_NUMPAD3:
    case VK_NUMPAD4:
    case VK_NUMPAD5:
    case VK_NUMPAD6:
    case VK_NUMPAD7:
    case VK_NUMPAD8:
    case VK_NUMPAD9:
    case VK_MULTIPLY:
    case VK_ADD:
    case VK_SEPARATOR:
    case VK_SUBTRACT:
    case VK_DECIMAL:
    case VK_DIVIDE:
        return true;
    case VK_RETURN:
        return HIWORD(keyData) & KF_EXTENDED;
    case VK_INSERT:
    case VK_DELETE:
    case VK_PRIOR:
    case VK_NEXT:
    case VK_END:
    case VK_HOME:
    case VK_LEFT:
    case VK_UP:
    case VK_RIGHT:
    case VK_DOWN:
        return !(HIWORD(keyData) & KF_EXTENDED);
    default:
        return false;
    }
}

static inline String singleCharacterString(UChar c) { return String(&c, 1); }

bool isShiftPressed()
{
    return (::GetKeyState(VK_SHIFT) & 0x8000) == 0x8000;
}

bool isCtrlPressed()
{
    return (::GetKeyState(VK_CONTROL) & 0x8000) == 0x8000;
}

bool isAltPressed()
{
    return (::GetKeyState(VK_MENU) & 0x8000) == 0x8000;
}

bool isAltGrPressed()
{
    return (::GetKeyState(VK_MENU) & 0x8000) == 0x8000 && (::GetKeyState(VK_CONTROL) & 0x8000) == 0x8000;
}

bool isWindowsKeyPressed()
{
    return (::GetKeyState(VK_LWIN) & 0x8000) == 0x8000 || (::GetKeyState(VK_RWIN) & 0x8000) == 0x8000;
}

bool isCapsLockOn()
{
    return (::GetKeyState(VK_CAPITAL) & 0x0001) == 0x0001;
}

bool isNumLockOn()
{
    return (::GetKeyState(VK_NUMLOCK) & 0x0001) == 0x0001;
}

bool isScrollLockOn()
{
    return (::GetKeyState(VK_SCROLL) & 0x0001) == 0x0001;
}

// src\ui\events\blink\blink_event_util.cc
// src\ui\events\win\events_win.cc
// src\ui\events\keycodes\dom\keycode_converter.cc
static void buildModifiers(WebInputEvent* evt)
{
    if (GetKeyState(VK_SHIFT) & HIGH_BIT_MASK_SHORT)
        evt->setModifiers(evt->modifiers() | ((int)WebInputEvent::ShiftKey));
    if (GetKeyState(VK_CONTROL) & HIGH_BIT_MASK_SHORT)
        evt->setModifiers(evt->modifiers() | ((int)WebInputEvent::ControlKey));
    if (GetKeyState(VK_MENU) & HIGH_BIT_MASK_SHORT)
        evt->setModifiers(evt->modifiers() | ((int)WebInputEvent::AltKey));
    if (isCapsLockOn())
        evt->setModifiers(evt->modifiers() | ((int)WebInputEvent::CapsLockOn));
    if (isNumLockOn())
        evt->setModifiers(evt->modifiers() | ((int)WebInputEvent::NumLockOn));
}

WebKeyboardEvent PlatformEventHandler::buildKeyboardEvent(WebInputEvent::Type type, UINT message, WPARAM wParam, LPARAM lParam)
{
//     unsigned int flags = 0;
//     if (HIWORD(lParam) & KF_REPEAT)
//         flags |= KF_REPEAT;
//     if (HIWORD(lParam) & KF_EXTENDED)
//         flags |= KF_REPEAT;

    LPARAM keyData = lParam; // MAKELPARAM(0, (WORD)flags);
    WebKeyboardEvent keyEvent;
    keyEvent.windowsKeyCode = (type == WebInputEvent::RawKeyDown || type == WebInputEvent::KeyUp) ? wParam : 0;
    keyEvent.nativeKeyCode = wParam;
    keyEvent.domCode = keyEvent.windowsKeyCode;
    keyEvent.domKey = keyEvent.windowsKeyCode;
    keyEvent.setTimeStampSeconds(WTF::currentTime());
    keyEvent.setSize(sizeof(WebKeyboardEvent));
    keyEvent.setType(type);

    buildModifiers(&keyEvent);
    if (isKeypadEvent(wParam, keyData, type))
        keyEvent.setModifiers(keyEvent.modifiers() | WebInputEvent::IsKeyPad);

    if (VK_LEFT == keyEvent.windowsKeyCode)
        wcscpy(keyEvent.text, L"Left");
    else if (VK_UP == keyEvent.windowsKeyCode)
        wcscpy(keyEvent.text, L"Up");
    else if (VK_UP == keyEvent.windowsKeyCode)
        wcscpy(keyEvent.text, L"Up");
    else if (VK_RIGHT == keyEvent.windowsKeyCode)
        wcscpy(keyEvent.text, L"Right");
    else if (VK_DOWN == keyEvent.windowsKeyCode)
        wcscpy(keyEvent.text, L"Down");

    else if (VK_NEXT == keyEvent.windowsKeyCode)
        wcscpy(keyEvent.text, L"PageDown");
    else if (VK_PRIOR == keyEvent.windowsKeyCode)
        wcscpy(keyEvent.text, L"PageUp");

    else if (VK_HOME == keyEvent.windowsKeyCode)
        wcscpy(keyEvent.text, L"Home");
    else if (VK_END == keyEvent.windowsKeyCode)
        wcscpy(keyEvent.text, L"End");

    else if (VK_TAB == keyEvent.windowsKeyCode)
        wcscpy(keyEvent.text, L"U+0009");
    else if (VK_BACK == keyEvent.windowsKeyCode)
        wcscpy(keyEvent.text, L"U+0008");
    else if (VK_ESCAPE == keyEvent.windowsKeyCode)
        wcscpy(keyEvent.text, L"U+001B");
    else if (VK_RETURN == keyEvent.windowsKeyCode)
        wcscpy(keyEvent.text, L"Enter");

    memset(keyEvent.text, 0, sizeof(WebUChar) * WebKeyboardEvent::textLengthCap);
    keyEvent.text[0] = (WebUChar)wParam;
    return keyEvent;
}

static void makeDraggableRegionNcHitTest(HWND hWnd, LPARAM lParam, bool* isDraggableRegionNcHitTest, IntPoint& lastPosForDrag)
{
    int xPos = ((int)(short)LOWORD(lParam));
    int yPos = ((int)(short)HIWORD(lParam));
    if (true == *isDraggableRegionNcHitTest) {
        //::PostMessage(hWnd, WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(xPos, yPos));
        ::PostMessage(hWnd, WM_SYSCOMMAND, SC_MOVE | HTCAPTION, 0);
        lastPosForDrag = IntPoint(xPos, yPos);
    } else {
        if (hWnd)
            ::SetCapture(hWnd);
    }
    //*isDraggableRegionNcHitTest = false;
}

PlatformEventHandler::PlatformEventHandler(WebWidget* webWidget, WebViewImpl* webViewImpl)
    : m_checkMouseLeaveTimer(this, &PlatformEventHandler::checkMouseLeave)
    , m_touchEmulator(webWidget)
{
    m_isDraggableRegionNcHitTest = false;
    m_postMouseLeave = false;
    m_mouseInWindow = false;
    m_isAlert = false;
    m_isDraggableRegionNcHitTest = false;
    m_isDraggableNodeMousedown = false;
    m_isLeftMousedown = false;
    m_lastTimeMouseDown = 0;
    m_isValidLastTouchDownPoint = false;
    m_webWidget = webWidget;
    m_webViewImpl = webViewImpl;
    m_enableTouchSimulate = false;
    m_enableSystemTouch = false;
}

void PlatformEventHandler::fireCaptureChangedEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (m_isDraggableRegionNcHitTest) {
        ::ReleaseCapture();
        m_isDraggableRegionNcHitTest = false;

        MouseEvtInfo info = { true, false, nullptr };
        lParam = MAKELONG(m_lastPosForDrag.x(), m_lastPosForDrag.y());
        fireMouseEvent(hWnd, WM_LBUTTONUP, wParam, lParam, info, nullptr);
    }
}

static uint32_t s_uniqueTouchEventId = 0;

void PlatformEventHandler::fireRealTouchEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (!m_enableSystemTouch)
        return;
    s_uniqueTouchEventId++;

    unsigned int numInputs = (unsigned int)wParam;
    if (numInputs > blink::WebTouchEvent::kTouchesLengthCap)
        numInputs = blink::WebTouchEvent::kTouchesLengthCap;

    TOUCHINPUT ti[blink::WebTouchEvent::kTouchesLengthCap];
    if (!::GetTouchInputInfoXp((HTOUCHINPUT)lParam, numInputs, ti, sizeof(TOUCHINPUT)))
        return;

    double time = WTF::currentTime();
    WebTouchEvent touchEvent;
    touchEvent.setTimeStampSeconds(time);
    touchEvent.setSize(sizeof(WebTouchEvent));
    touchEvent.setModifiers(0);
    touchEvent.touchesLength = 1;
    //touchEvent.cancelable = true;
    //touchEvent.causesScrollingIfUncanceled = false;
    touchEvent.uniqueTouchEventId = s_uniqueTouchEventId;

    POINT screenPt = { 0 };
    POINT point = { 0 };

    touchEvent.touchesLength = numInputs > blink::WebTouchEvent::kTouchesLengthCap ? blink::WebTouchEvent::kTouchesLengthCap : numInputs;
    for (unsigned int i = 0; i < touchEvent.touchesLength; ++i) {
        blink::WebTouchPoint& touchPoint = touchEvent.touches[i];
        touchPoint.id = ti[i].dwID;

        point = { ti[i].x,  ti[i].y };
        screenPt = point;
        ::ClientToScreen(hWnd, &screenPt);

        touchPoint.screenPosition.x = screenPt.x / 100.0;
        touchPoint.screenPosition.y = screenPt.y / 100.0;

        touchPoint.position.x = point.x / 100.0;
        touchPoint.position.y = point.y / 100.0;

        touchPoint.radiusX = 10;
        touchPoint.radiusY = 10;
        touchPoint.rotationAngle = 0;

        blink::WebGestureEvent gestureEvent;
        gestureEvent.setTimeStampSeconds(time);
        gestureEvent.setSize(sizeof(blink::WebGestureEvent));
        gestureEvent.setModifiers(0);

        gestureEvent.x = point.x / 100.0;
        gestureEvent.y = point.y / 100.0;
        gestureEvent.globalX = screenPt.x / 100.0;
        gestureEvent.globalY = screenPt.x / 100.0;
        gestureEvent.sourceDevice = blink::WebGestureDeviceTouchpad;

        if (ti[i].dwFlags & TOUCHEVENTF_DOWN) {
            touchEvent.setType(blink::WebInputEvent::TouchStart);
            touchPoint.state = blink::WebTouchPoint::StatePressed;

            m_lastTouchDownPoint = blink::FloatPoint(touchPoint.position);
            m_isValidLastTouchDownPoint = true;
            
            gestureEvent.setType(blink::WebInputEvent::GestureScrollBegin);
            gestureEvent.data.scrollBegin.deltaXHint = 0;
            gestureEvent.data.scrollBegin.deltaYHint = 0;
            gestureEvent.data.scrollBegin.targetViewport = true;
        } else if (ti[i].dwFlags & TOUCHEVENTF_MOVE) {
            touchEvent.setType(WebInputEvent::TouchMove);
            touchPoint.state = WebTouchPoint::StateMoved;

            gestureEvent.setType(blink::WebInputEvent::GestureScrollUpdate);
            if (m_isValidLastTouchDownPoint) {
                gestureEvent.data.scrollUpdate.deltaX = touchPoint.position.x - m_lastTouchDownPoint.x();
                gestureEvent.data.scrollUpdate.deltaY = touchPoint.position.y - m_lastTouchDownPoint.y();
                m_lastTouchDownPoint = blink::FloatPoint(touchPoint.position);
                m_isValidLastTouchDownPoint = true;
            }
            gestureEvent.data.scrollUpdate.velocityX = 0;
            gestureEvent.data.scrollUpdate.velocityY = 0;
            gestureEvent.data.scrollUpdate.previousUpdateInSequencePrevented = false;
            gestureEvent.data.scrollUpdate.preventPropagation = false;
            //gestureEvent.data.scrollUpdate.inertial = false;

        } else if (ti[i].dwFlags & TOUCHEVENTF_UP) {
            touchEvent.setType(WebInputEvent::TouchEnd);
            touchPoint.state = WebTouchPoint::StateReleased;

            gestureEvent.setType(blink::WebInputEvent::GestureScrollEnd);
            m_isValidLastTouchDownPoint = false;
        }

        if (0 == i && (m_isValidLastTouchDownPoint || blink::WebInputEvent::GestureScrollUpdate != gestureEvent.type())) {
            m_webWidget->handleInputEvent(gestureEvent);
        }
    }

    ::CloseTouchInputHandleXp((HTOUCHINPUT)lParam);
    m_webWidget->handleInputEvent(touchEvent);
}

void PlatformEventHandler::fireRealTouchEventTest(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    s_uniqueTouchEventId++;

    unsigned int numInputs = 1;
    if (numInputs > blink::WebTouchEvent::kTouchesLengthCap)
        numInputs = blink::WebTouchEvent::kTouchesLengthCap;

    double time = WTF::currentTime();
    WebTouchEvent touchEvent;
    touchEvent.setTimeStampSeconds(time);
    touchEvent.setSize(sizeof(WebTouchEvent));
    touchEvent.setModifiers(0);
    touchEvent.touchesLength = 1;
//     touchEvent.cancelable = true;
//     touchEvent.causesScrollingIfUncanceled = false;
    touchEvent.uniqueTouchEventId = s_uniqueTouchEventId;

    POINT screenPt;
    ::GetCursorPos(&screenPt);

    POINT point = { screenPt.x,  screenPt.y };
    ::ScreenToClient(hWnd, &point);

    touchEvent.touchesLength = numInputs > blink::WebTouchEvent::kTouchesLengthCap ? blink::WebTouchEvent::kTouchesLengthCap : numInputs;
    for (unsigned int i = 0; i < touchEvent.touchesLength; ++i) {
        blink::WebTouchPoint& touchPoint = touchEvent.touches[i];
        touchPoint.id = 0;

        touchPoint.screenPosition.x = screenPt.x;
        touchPoint.screenPosition.y = screenPt.y;

        touchPoint.position.x = point.x;
        touchPoint.position.y = point.y;

        touchPoint.radiusX = 10;
        touchPoint.radiusY = 10;
        touchPoint.rotationAngle = 0;

        blink::WebGestureEvent gestureEvent;
        gestureEvent.setTimeStampSeconds(time);
        gestureEvent.setSize(sizeof(blink::WebGestureEvent));
        gestureEvent.setModifiers(0);

        gestureEvent.x = point.x;
        gestureEvent.y = point.y;
        gestureEvent.globalX = screenPt.x;
        gestureEvent.globalY = screenPt.x;
        gestureEvent.sourceDevice = blink::WebGestureDeviceTouchpad;

        if (message == WM_LBUTTONDOWN) {
            touchEvent.setType(blink::WebInputEvent::TouchStart);
            touchPoint.state = blink::WebTouchPoint::StatePressed;

            m_lastTouchDownPoint = blink::FloatPoint(touchPoint.position);
            m_isValidLastTouchDownPoint = true;

            gestureEvent.setType(blink::WebInputEvent::GestureScrollBegin);
            gestureEvent.data.scrollBegin.deltaXHint = 0;
            gestureEvent.data.scrollBegin.deltaYHint = 0;
            gestureEvent.data.scrollBegin.targetViewport = true;
        } else if (message == WM_MOUSEMOVE) {
            touchEvent.setType(WebInputEvent::TouchMove);
            touchPoint.state = WebTouchPoint::StateMoved;

            gestureEvent.setType(blink::WebInputEvent::GestureScrollUpdate);

            if (m_isValidLastTouchDownPoint) {
                gestureEvent.data.scrollUpdate.deltaX = touchPoint.position.x - m_lastTouchDownPoint.x();
                gestureEvent.data.scrollUpdate.deltaY = touchPoint.position.y - m_lastTouchDownPoint.y();
                m_lastTouchDownPoint = blink::FloatPoint(touchPoint.position);
                m_isValidLastTouchDownPoint = true;
            }
            gestureEvent.data.scrollUpdate.velocityX = 0;
            gestureEvent.data.scrollUpdate.velocityY = 0;
            gestureEvent.data.scrollUpdate.previousUpdateInSequencePrevented = true;
            gestureEvent.data.scrollUpdate.preventPropagation = false;
            //gestureEvent.data.scrollUpdate.inertial = false;

        } else if (message == WM_LBUTTONUP) {
            touchEvent.setType(WebInputEvent::TouchEnd);
            touchPoint.state = WebTouchPoint::StateReleased;

            gestureEvent.setType(blink::WebInputEvent::GestureScrollEnd);
            m_isValidLastTouchDownPoint = false;
        }

        if (0 == i && (m_isValidLastTouchDownPoint || blink::WebInputEvent::GestureScrollUpdate != gestureEvent.type()))
            m_webWidget->handleInputEvent(gestureEvent);
    }

    m_webWidget->handleInputEvent(touchEvent);
}

//////////////////////////////////////////////////////////////////////////

TouchEmulator::TouchEmulator(blink::WebWidget* webWidget)
    : m_gestureShowPressTimer(this, &TouchEmulator::gestureShowPressTimer)
    , m_gestureLongPressTimer(this, &TouchEmulator::gestureLongPressTimer)
{
    m_webWidget = webWidget;
    m_isLongPress = false;
    m_isPressState = false;
    m_isScrollState = false;
    m_isValidLastTouchDownPoint = false;
}

void TouchEmulator::handleMouseDown(HWND hWnd, blink::WebTouchEvent* touchEvent, blink::WebTouchPoint* touchPoint)
{
    m_lastTouchDownPoint = blink::FloatPoint(touchPoint->position);
    m_isValidLastTouchDownPoint = true;

    touchEvent->setType(WebInputEvent::TouchStart);
    touchPoint->state = WebTouchPoint::StatePressed;
    m_webWidget->handleInputEvent(*touchEvent);

    s_uniqueTouchEventId++;

    touchEvent->setType(WebInputEvent::GestureTapDown);
    touchPoint->state = WebTouchPoint::StatePressed;
    m_webWidget->handleInputEvent(*touchEvent);

    m_gestureShowPressTimer.stop();
    m_gestureLongPressTimer.stop();
    m_isLongPress = false;
    m_isPressState = true;
    m_isScrollState = false;
    m_gestureShowPressTimer.startOneShot(0.01, FROM_HERE);
}

void TouchEmulator::handleMouseMove(HWND hWnd, blink::WebTouchEvent* touchEvent, blink::WebTouchPoint* touchPoint)
{
    m_gestureShowPressTimer.stop();
    m_gestureLongPressTimer.stop();
    m_isLongPress = false;

    if (!m_isPressState)
        return;

    POINT screenPt;
    ::GetCursorPos(&screenPt);

    POINT point = { screenPt.x,  screenPt.y };
    ::ScreenToClient(hWnd, &point);

    touchEvent->setType(WebInputEvent::TouchMove);
    touchPoint->state = WebTouchPoint::StateMoved;

    m_webWidget->handleInputEvent(*touchEvent);

    blink::WebGestureEvent gestureEvent;
    gestureEvent.setTimeStampSeconds(WTF::currentTime());
    gestureEvent.setSize(sizeof(blink::WebGestureEvent));
    gestureEvent.setModifiers(0);

    gestureEvent.x = point.x;
    gestureEvent.y = point.y;
    gestureEvent.globalX = screenPt.x;
    gestureEvent.globalY = screenPt.x;
    gestureEvent.sourceDevice = blink::WebGestureDeviceTouchpad;

    if (m_isValidLastTouchDownPoint) {
        gestureEvent.data.scrollUpdate.deltaX = touchPoint->position.x - m_lastTouchDownPoint.x();
        gestureEvent.data.scrollUpdate.deltaY = touchPoint->position.y - m_lastTouchDownPoint.y();
        m_lastTouchDownPoint = blink::FloatPoint(touchPoint->position);
        m_isValidLastTouchDownPoint = true;
    }

    gestureEvent.data.scrollUpdate.velocityX = 0;
    gestureEvent.data.scrollUpdate.velocityY = 0;
    gestureEvent.data.scrollUpdate.previousUpdateInSequencePrevented = true;
    gestureEvent.data.scrollUpdate.preventPropagation = false;
    //gestureEvent.data.scrollUpdate.inertial = false;

    if (!m_isScrollState) {
        s_uniqueTouchEventId++;
        gestureEvent.setType(WebInputEvent::GestureTapCancel);
        m_webWidget->handleInputEvent(gestureEvent);

        s_uniqueTouchEventId++;
        gestureEvent.setType(WebInputEvent::GestureScrollBegin);
        m_webWidget->handleInputEvent(gestureEvent);
    }
    m_isScrollState = true;

    s_uniqueTouchEventId++;

    gestureEvent.setType(WebInputEvent::GestureScrollUpdate);
    m_webWidget->handleInputEvent(gestureEvent);
}

void TouchEmulator::handleMouseUp(HWND hWnd, blink::WebTouchEvent* touchEvent, blink::WebTouchPoint* touchPoint)
{
    m_isValidLastTouchDownPoint = false;
    touchEvent->setType(WebInputEvent::TouchEnd);
    touchPoint->state = WebTouchPoint::StateReleased;
    m_webWidget->handleInputEvent(*touchEvent);

    m_gestureShowPressTimer.stop();
    m_gestureLongPressTimer.stop();

    if (m_isLongPress) {
        s_uniqueTouchEventId++;
        touchEvent->setType(WebInputEvent::GestureLongTap);
        m_webWidget->handleInputEvent(*touchEvent);
    }

    if (m_isScrollState) {
        s_uniqueTouchEventId++;
        touchEvent->setType(WebInputEvent::GestureScrollEnd);
        m_webWidget->handleInputEvent(*touchEvent);
    }

    m_isLongPress = false;
    m_isPressState = false;
    m_isScrollState = false;
}

void TouchEmulator::gestureShowPressTimer(blink::TimerBase*)
{
    s_uniqueTouchEventId++;

    double time = WTF::currentTime();
    WebTouchEvent touchEvent;
    touchEvent.setTimeStampSeconds(WTF::currentTime());
    touchEvent.setSize(sizeof(WebTouchEvent));
    touchEvent.setModifiers(0);
    touchEvent.touchesLength = 1;
//     touchEvent.cancelable = true;
//     touchEvent.causesScrollingIfUncanceled = false;
    touchEvent.uniqueTouchEventId = s_uniqueTouchEventId;

    touchEvent.setType(WebInputEvent::GestureShowPress);
    m_webWidget->handleInputEvent(touchEvent);

    m_gestureShowPressTimer.stop();
    m_gestureLongPressTimer.stop();
    m_isLongPress = true;
    m_gestureLongPressTimer.startOneShot(1, FROM_HERE);
}

void TouchEmulator::gestureLongPressTimer(blink::TimerBase*)
{
    s_uniqueTouchEventId++;

    double time = WTF::currentTime();
    WebTouchEvent touchEvent;
    touchEvent.setTimeStampSeconds(WTF::currentTime());
    touchEvent.setSize(sizeof(WebTouchEvent));
    touchEvent.setModifiers(0);
    touchEvent.touchesLength = 1;
//     touchEvent.cancelable = true;
//     touchEvent.causesScrollingIfUncanceled = false;
    touchEvent.uniqueTouchEventId = s_uniqueTouchEventId;

    touchEvent.setType(WebInputEvent::GestureLongPress);
    m_webWidget->handleInputEvent(touchEvent);

    m_gestureShowPressTimer.stop();
    m_gestureLongPressTimer.stop();
    m_isLongPress = false;
}

//////////////////////////////////////////////////////////////////////////

void PlatformEventHandler::fireTouchEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //return fireRealTouchEventTest(hWnd, message, wParam, lParam);

    double time = WTF::currentTime();
    WebTouchEvent touchEvent;
    touchEvent.setTimeStampSeconds(time);
    touchEvent.setSize(sizeof(WebTouchEvent));
    touchEvent.setModifiers(0);
    touchEvent.touchesLength = 1;
//     touchEvent.cancelable = true;
//     touchEvent.causesScrollingIfUncanceled = false;
    touchEvent.uniqueTouchEventId = s_uniqueTouchEventId;

    WebTouchPoint& touchPoint = touchEvent.touches[0];
    touchPoint.id = 0;

    POINT ptCursor;
    ::GetCursorPos(&ptCursor);

    touchPoint.screenPosition.x = ptCursor.x;
    touchPoint.screenPosition.y = ptCursor.y;

    touchPoint.position.x = ((int)(short)LOWORD(lParam));
    touchPoint.position.y = ((int)(short)HIWORD(lParam));

    touchPoint.radiusX = 10;
    touchPoint.radiusY = 10;
    touchPoint.rotationAngle = 0;

    if (WM_LBUTTONDOWN == message) {
        m_touchEmulator.handleMouseDown(m_hWnd, &touchEvent, &touchPoint);
    } else if (WM_LBUTTONUP == message) {
        m_touchEmulator.handleMouseUp(m_hWnd, &touchEvent, &touchPoint);
    } else if (WM_MOUSEMOVE == message) {
        m_touchEmulator.handleMouseMove(m_hWnd, &touchEvent, &touchPoint);
    } else if (WM_MOUSELEAVE == message) {

    } else if (WM_TOUCH == message) {
        fireRealTouchEvent(hWnd, message, wParam, lParam);
    }
}

static bool isNearPos(const blink::IntPoint& a, const blink::IntPoint& b)
{
    return std::abs(a.x() - b.x()) + std::abs(a.y() - b.y()) < 15;
}

static void WKE_CALL_TYPE postDragMessageImpl(HWND hWnd, void* param)
{
    ::ReleaseCapture();
    ::PostMessage(hWnd, WM_SYSCOMMAND, SC_MOVE | HTCAPTION, 0);
}

static void postDragMessage(HWND hWnd)
{
    HWND hRootWnd = hWnd;
    while (true)  {
        hWnd = ::GetParent(hWnd);
        if (!hWnd)
            break;
        hRootWnd = hWnd;
    }

    if (!hRootWnd)
        return;
    
    if (!/*blink::RuntimeEnabledFeatures::updataInOtherThreadEnabled()*/true) {
        postDragMessageImpl(hRootWnd, nullptr);
        return;
    }

    if (wke::g_wkeUiThreadPostTaskCallback)
        wke::g_wkeUiThreadPostTaskCallback(hRootWnd, postDragMessageImpl, nullptr);
}

void PlatformEventHandler::buildMousePosInfo(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, bool* handle, IntPoint* pos, IntPoint* globalPos)
{
    if (WM_MOUSELEAVE == message) {
        *handle = true;
        m_postMouseLeave = true;

        POINT ptCursor;
        ::GetCursorPos(&ptCursor);
        *globalPos = IntPoint(ptCursor.x, ptCursor.y);
        ::ScreenToClient(hWnd, &ptCursor);
        if (ptCursor.x < 2)
            ptCursor.x = -1;
        else if (ptCursor.x > 10)
            ptCursor.x += 2;

        if (ptCursor.y < 2)
            ptCursor.y = -1;
        else if (ptCursor.y > 10)
            ptCursor.y += 2;

        *pos = IntPoint(ptCursor.x, ptCursor.y);

        lParam = MAKELPARAM(ptCursor.x, ptCursor.y);
    } else {
        m_postMouseLeave = false;
        pos->setX(/*m_offset.x() +*/ ((int)(short)LOWORD(lParam)));
        pos->setY(/*m_offset.y() +*/ ((int)(short)HIWORD(lParam)));

        POINT widgetPoint = { pos->x(), pos->y() };
        ::ClientToScreen(hWnd, &widgetPoint);

        *globalPos = IntPoint(widgetPoint.x, widgetPoint.y);
    }
}

// 鼠标点击标题栏时，收不到up消息，所以要模拟一次
bool PlatformEventHandler::fireMouseUpEventIfNeeded(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, const MouseEvtInfo& info, BOOL* bHandle)
{
    if ((WM_MOUSEMOVE != message && WM_MOUSELEAVE != message) || !m_isLeftMousedown)
        return false;

    if ((wParam & MK_LBUTTON))
        return false;

    fireMouseEvent(hWnd, WM_LBUTTONUP, 0, lParam, info, nullptr);
    if (bHandle)
        *bHandle = true;
    return true;
}

void PlatformEventHandler::checkMouseLeave(blink::TimerBase*)
{
    if (!m_hWnd || !::IsWindow(m_hWnd)) {
        m_checkMouseLeaveTimer.stop();
        return;
    }

    POINT pt = { 0 };
    ::GetCursorPos(&pt);

    RECT rc;
    ::GetClientRect(m_hWnd, &rc);
    ::ScreenToClient(m_hWnd, &pt);

    if ((!::PtInRect(&rc, pt) || !::IsWindowVisible(m_hWnd))) {
        if (!m_isLeftMousedown) {
            MouseEvtInfo info = { true, false, nullptr };
            LPARAM lParam = MAKELONG(pt.x, pt.y);

            if (m_enableTouchSimulate)
                fireTouchEvent(m_hWnd, WM_MOUSELEAVE, lParam, 0);

            fireMouseEvent(m_hWnd, WM_MOUSELEAVE, 0, lParam, info, nullptr);
        }
        m_checkMouseLeaveTimer.stop();
    }
}

LRESULT PlatformEventHandler::fireMouseEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, const MouseEvtInfo& info, BOOL* bHandle)
{
    m_hWnd = hWnd;
    bool handle = false;

    m_isDraggableRegionNcHitTest = false;
    if (true == m_isAlert)
        return 0;

    bool isValideWindow = ::IsWindow(hWnd) && !info.isWillDestroy;

    if (fireMouseUpEventIfNeeded(hWnd, message, wParam, lParam, info, bHandle))
        return 0;

    bool shift = false, ctrl = false, alt = false, meta = false;
    int clickCount = 0;

    IntPoint pos;
    IntPoint globalPos;

    buildMousePosInfo(hWnd, message, wParam, lParam, &handle, &pos, &globalPos);

    if (!m_checkMouseLeaveTimer.isActive())
        m_checkMouseLeaveTimer.startRepeating(0.2, FROM_HERE);
    if (WM_MOUSELEAVE == message)
        m_checkMouseLeaveTimer.stop();

    double time = WTF::currentTime();
    WebMouseEvent webMouseEvent;
    webMouseEvent.setTimeStampSeconds(time);
    webMouseEvent.setSize(sizeof(WebMouseEvent));
    webMouseEvent.setModifiers(0);
    webMouseEvent.x = pos.x();
    webMouseEvent.y = pos.y();

    webMouseEvent.movementX = pos.x() - m_lastPosMouseMove.x();
    webMouseEvent.movementY = pos.y() - m_lastPosMouseMove.y();
    m_lastPosMouseMove = pos;

    webMouseEvent.windowX = pos.x();
    webMouseEvent.windowY = pos.y();
    webMouseEvent.globalX = globalPos.x();
    webMouseEvent.globalY = globalPos.y();
    webMouseEvent.clickCount = 1;
    buildModifiers(&webMouseEvent);

    if (WM_LBUTTONDOWN == message || WM_MBUTTONDOWN == message || WM_RBUTTONDOWN == message || WM_LBUTTONDBLCLK == message) {
        handle = true;

        const static double minInterval = GetDoubleClickTime() / 1000.0;

        if (time - m_lastTimeMouseDown < minInterval && isNearPos(m_lastPosMouseDown, pos))
            webMouseEvent.clickCount = 2;
        
        m_lastTimeMouseDown = time;
        m_lastPosMouseDown = pos;

        if (hWnd && info.isNeedSetFocus) {
            if (isValideWindow && ::GetFocus() != hWnd) {
                ::SetFocus(hWnd);
                m_webViewImpl->setFocus(true);
                m_webViewImpl->setIsActive(true);
            }
            if (wke::g_enableNativeSetCapture && isValideWindow)
                ::SetCapture(hWnd);
        }
        switch (message) {
        case WM_LBUTTONDOWN:
        case WM_LBUTTONDBLCLK:
            m_isLeftMousedown = true;
            webMouseEvent.button = WebPointerProperties::Button::Left;
            webMouseEvent.setModifiers(webMouseEvent.modifiers() | WebMouseEvent::LeftButtonDown);
            break;
        case WM_MBUTTONDOWN:
            webMouseEvent.button = WebPointerProperties::Button::Middle;
            webMouseEvent.setModifiers(webMouseEvent.modifiers() | WebMouseEvent::MiddleButtonDown);
            break;
        case WM_RBUTTONDOWN:
            webMouseEvent.button = WebPointerProperties::Button::Right;
            webMouseEvent.setModifiers(webMouseEvent.modifiers() | WebMouseEvent::RightButtonDown);
            break;
        }
        m_isDraggableRegionNcHitTest = false;
        webMouseEvent.setType(WebInputEvent::MouseDown);
        bool b = m_webWidget->handleInputEvent(webMouseEvent) != WebInputEventResult::NotHandled;

        bool isDraggable = false;
        if (WM_LBUTTONDOWN == message)
            isDraggable = isDraggableRegionNcHitTest(hWnd, pos, info.draggableRegion);

        if (isValideWindow && isDraggable)
            postDragMessage(hWnd);
        m_isDraggableNodeMousedown = false;
    } else if (WM_LBUTTONUP == message || WM_MBUTTONUP == message || WM_RBUTTONUP == message) {
        handle = true;
        
        switch (message) {
        case WM_LBUTTONUP:
            m_isLeftMousedown = false;
            webMouseEvent.button = WebPointerProperties::Button::Left;
            webMouseEvent.setModifiers(webMouseEvent.modifiers() | WebMouseEvent::LeftButtonDown);
            break;
        case WM_MBUTTONUP:
            webMouseEvent.button = WebPointerProperties::Button::Middle;
            webMouseEvent.setModifiers(webMouseEvent.modifiers() | WebMouseEvent::MiddleButtonDown);
            break;
        case WM_RBUTTONUP:
            webMouseEvent.button = WebPointerProperties::Button::Right;
            webMouseEvent.setModifiers(webMouseEvent.modifiers() | WebMouseEvent::RightButtonDown);
            break;
        }
        if (isValideWindow)
            ::ReleaseCapture();
        if (m_webViewImpl) {
            WebLocalFrame* frame = (WebLocalFrame*)m_webViewImpl->mainFrame();
            if (frame && frame->frameWidget())
                frame->frameWidget()->dragSourceSystemDragEnded();
        }
        webMouseEvent.setType(WebInputEvent::MouseUp);
        m_webWidget->handleInputEvent(webMouseEvent);        
    } else if (WM_MOUSEMOVE == message || WM_MOUSELEAVE == message) {
        handle = true;
        if (wParam & MK_LBUTTON) {
            webMouseEvent.button = WebPointerProperties::Button::Left;
            webMouseEvent.setModifiers(webMouseEvent.modifiers() | WebMouseEvent::LeftButtonDown);
        } else if (wParam & MK_MBUTTON) {
            webMouseEvent.button = WebPointerProperties::Button::Middle;
            webMouseEvent.setModifiers(webMouseEvent.modifiers() | WebMouseEvent::MiddleButtonDown);
        } else if (wParam & MK_RBUTTON) {
            webMouseEvent.button = WebPointerProperties::Button::Right;
            webMouseEvent.setModifiers(webMouseEvent.modifiers() | WebMouseEvent::RightButtonDown);
        } else {
            ASSERT(!m_isLeftMousedown);
            webMouseEvent.button = WebPointerProperties::Button::Eraser;
        }

        bool b = false;
        switch (message) {
        case WM_MOUSEMOVE:
            if (!m_mouseInWindow) {
                webMouseEvent.setType(WebInputEvent::MouseEnter);
                m_mouseInWindow = true;
            } else
                webMouseEvent.setType(WebInputEvent::MouseMove);

            b = m_webWidget->handleInputEvent(webMouseEvent) != WebInputEventResult::NotHandled;
            break;
        case WM_MOUSELEAVE:
            webMouseEvent.setType(WebInputEvent::MouseLeave);

            if (m_webViewImpl) {
                WebLocalFrame* frame = (WebLocalFrame*)m_webViewImpl->mainFrame();
                if (frame && frame->frameWidget())
                    frame->frameWidget()->dragSourceSystemDragEnded();
            }
            b = m_webWidget->handleInputEvent(webMouseEvent) != WebInputEventResult::NotHandled;
            m_mouseInWindow = false;
            break;
        }
    }

    if (bHandle)
        *bHandle = handle;
    return 0;
}

void PlatformEventHandler::setIsDraggableNodeMousedown()
{
    m_isDraggableNodeMousedown = true;
}

bool PlatformEventHandler::isDraggableRegionNcHitTest(HWND hWnd, const blink::IntPoint& pos, HRGN draggableRegion)
{
    // 单线程情况下，直接在mb内部处理拖拽。多线程渲染时，必须在ui线程处理，否则blink线程卡了，会导致拖拽也很卡
    if (!/*blink::RuntimeEnabledFeatures::updataInOtherThreadEnabled()*/true)
        return m_isDraggableNodeMousedown;
    return false;

//     if (!draggableRegion)
//         return false;
// 
//     return ::PtInRegion(draggableRegion, pos.x(), pos.y());
}

int verticalScrollLines()
{
    static ULONG scrollLines = 0;
    if (!scrollLines && !SystemParametersInfo(SPI_GETWHEELSCROLLLINES, 0, &scrollLines, 0))
        scrollLines = 3;
    return scrollLines;
}

int horizontalScrollChars()
{
    static ULONG scrollChars = 0;
    if (!scrollChars && !SystemParametersInfo(SPI_GETWHEELSCROLLCHARS, 0, &scrollChars, 0))
        scrollChars = 1;
    return scrollChars;
}

LRESULT PlatformEventHandler::fireWheelEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int x = LOWORD(lParam);
    int y = HIWORD(lParam);
    POINT point = { x, y };
    ::ScreenToClient(hWnd, &point);
    x = point.x;
    y = point.y;

    int wheelDelta = GET_WHEEL_DELTA_WPARAM(wParam);
    int modifiers = 0;
    static const float cScrollbarPixelsPerLine = 100.0f / 3.0f;
    float delta = wheelDelta / static_cast<float>(WHEEL_DELTA);

    float deltaX = 0.f;
    float deltaY = 0.f;

    bool shiftKey = wParam & MK_SHIFT;
    bool ctrlKey = wParam & MK_CONTROL;

    //blink::PlatformWheelEventGranularity granularity = blink::ScrollByPageWheelEvent;

    if (shiftKey) {
        deltaX = delta * static_cast<float>(horizontalScrollChars()) * cScrollbarPixelsPerLine;
        deltaY = 0;
        //granularity = blink::ScrollByPixelWheelEvent;
        modifiers |= WebInputEvent::ShiftKey;
    } else {
        deltaX = 0;
        deltaY = delta;
        int verticalMultiplier = verticalScrollLines();
//         granularity = (verticalMultiplier == WHEEL_PAGESCROLL) ? blink::ScrollByPageWheelEvent : blink::ScrollByPixelWheelEvent;
//         if (granularity == blink::ScrollByPixelWheelEvent)
        if (verticalMultiplier != WHEEL_PAGESCROLL)
            deltaY *= static_cast<float>(verticalMultiplier)* cScrollbarPixelsPerLine;
    }
   
    if (ctrlKey)
        modifiers |= WebInputEvent::ControlKey;
    
    WebMouseWheelEvent webWheelEvent;
    webWheelEvent.setType(WebInputEvent::MouseWheel);
    webWheelEvent.x = x;
    webWheelEvent.y = y;
    webWheelEvent.globalX = x;
    webWheelEvent.globalY = y;
    webWheelEvent.deltaX = deltaX;
    webWheelEvent.deltaY = deltaY;
    webWheelEvent.wheelTicksX = 0.f;
    webWheelEvent.wheelTicksY = delta;
    webWheelEvent.hasPreciseScrollingDeltas = true;
    webWheelEvent.setModifiers(modifiers);
    m_webWidget->handleInputEvent(webWheelEvent);

    return 0;
}

}