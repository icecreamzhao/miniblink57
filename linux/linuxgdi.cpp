

#if !defined(WIN32)
#include "linux/linuxgdi.h"
#include "mbvip/common/StringUtil.h"
#include "mbvip/common/ThreadCall.h"
#include "third_party/WebKit/Source/wtf/Assertions.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <sys/types.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms-compat.h>
#include <map>

std::map<int, WNDCLASSEXW*>* HwndLinux::s_wndClassMap = nullptr;
std::set<HWND>* HwndLinux::s_hwnds = nullptr;
pthread_mutex_t HwndLinux::s_hwndMutex;

class CrossThreadUiState {
public:
    POINT m_cursorPos;

    static CrossThreadUiState* get()
    {
        if (!m_inst)
            m_inst = new CrossThreadUiState();
        return m_inst;
    }

    CrossThreadUiState()
    {
        m_isCapsLock = false;
        m_isNumLock = false;
        m_isScrollLock = false;
        m_isShift = false;
        m_isCtrl = false;
        m_isAtl = false;
        m_cursorPos.x = 0;
        m_cursorPos.y = 0;
        pthread_mutex_init(&m_mutex, nullptr);
    }

    ~CrossThreadUiState()
    {
        pthread_mutex_destroy(&m_mutex);
    }

    void updata(const guint* state)
    {
        GdkDisplay* display = gdk_display_get_default();
        GdkSeat* deviceManager = gdk_display_get_default_seat(display);
        GdkDevice* device = gdk_seat_get_pointer(deviceManager);

        GdkKeymap* keymap = gdk_keymap_get_for_display(display);
        gboolean isCapsLock = gdk_keymap_get_caps_lock_state(keymap);
        gboolean isNumLock = gdk_keymap_get_num_lock_state(keymap);
        gboolean isScrollLock = gdk_keymap_get_scroll_lock_state(keymap);

        pthread_mutex_lock(&m_mutex);

        gdk_device_get_position(device, NULL, &m_cursorPos.x, &m_cursorPos.y);// 获取指针在屏幕上的绝对坐标

        bool isShift = false;
        bool isCtrl = false;
        bool isAtl = false;

        if (state) {
            isShift = !!(*state & GDK_SHIFT_MASK);
            isCtrl = !!(*state & GDK_CONTROL_MASK);
            isAtl = !!(*state & GDK_MOD1_MASK);
        }
//         GdkModifierType type = gdk_keymap_get_modifier_mask(keymap, GDK_MODIFIER_INTENT_SHIFT_GROUP);
//         if (type & GDK_SHIFT_MASK)
//             isShift = true;
// 
//         type = gdk_keymap_get_modifier_mask(keymap, GDK_MODIFIER_INTENT_DEFAULT_MOD_MASK);
//         if (type & GDK_CONTROL_MASK)
//             isCtrl = true;
// 
//         type = gdk_keymap_get_modifier_mask(keymap, GDK_MODIFIER_INTENT_CONTEXT_MENU);
//         if (type & GDK_MOD1_MASK)
//             isAtl = true;

        m_isCapsLock = isCapsLock;
        m_isNumLock = isNumLock;
        m_isScrollLock = isScrollLock;
        m_isShift = isShift;
        m_isCtrl = isCtrl;
        m_isAtl = isAtl;

        pthread_mutex_unlock(&m_mutex);
    }

    void getState(bool* isCapsLock, bool* isNumLock, bool* isScrollLock, bool* isShift, bool* isCtrl, bool* isAtl)
    {
        pthread_mutex_lock(&m_mutex);
        if (isCapsLock)
            *isCapsLock = m_isCapsLock;
        if (isNumLock)
            *isNumLock = m_isNumLock;
        if (isScrollLock)
            *isScrollLock = m_isScrollLock;
        if (isShift)
            *isShift = m_isShift;
        if (isCtrl)
            *isCtrl = m_isCtrl;
        if (isAtl)
            *isAtl = m_isAtl;
        pthread_mutex_unlock(&m_mutex);
    }

private:
    bool m_isCapsLock;
    bool m_isNumLock;
    bool m_isScrollLock;
    bool m_isShift;
    bool m_isCtrl;
    bool m_isAtl;
    pthread_mutex_t m_mutex;
    static CrossThreadUiState* m_inst;
};

CrossThreadUiState* CrossThreadUiState::m_inst = nullptr;

HwndLinux::HwndLinux()
{
    m_widget = nullptr;
    m_drawingArea = nullptr;
    m_wndProc = nullptr;
    m_userdata = nullptr;
    m_surface = nullptr;
    m_style = 0;
    m_styleex = 0;
    m_rootX = 0;
    m_rootY = 0;
    m_isDestroying = false;
    m_threadId = ::GetCurrentThreadId();

    CrossThreadUiState::get()->updata(nullptr);

    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&m_propsMutex, &attr);
}

HwndLinux::~HwndLinux()
{
    pthread_mutex_destroy(&m_propsMutex);
}

void HwndLinux::updataPosOnScreen()
{
    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    gtk_window_get_position(GTK_WINDOW(m_widget), &m_rootX, &m_rootY);
    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
}

static gboolean testDraw(cairo_t* cr)
{
    //     int width, height;
    //     gtk_window_get_size(GTK_WINDOW(widget), &width, &height);

    cairo_set_source_rgb(cr, 0.3, 0.5, 1);
    cairo_rectangle(cr, 20.0, 20.0, 100.0, 100.0);
    cairo_fill(cr);
// 
//     cairo_set_source_rgb(cr, 0.6, 0.6, 0.6);
//     cairo_rectangle(cr, 150, 20, 100, 100);
//     cairo_fill(cr);
// 
//     cairo_set_source_rgb(cr, 0, 0.3, 0);
//     cairo_rectangle(cr, 20, 140, 100, 100);
//     cairo_fill(cr);
// 
//     cairo_set_source_rgb(cr, 1, 0, 0.5);
//     cairo_rectangle(cr, 150, 140, 100, 100);
//     cairo_fill(cr);

    return FALSE;
}

//extern cairo_surface_t* g_test_surface;

gboolean HwndLinux::onDraw(GtkWidget* widget, cairo_t* cr, gpointer data)
{
    HwndLinux* self = (HwndLinux*)data;

    CrossThreadUiState::get()->updata(nullptr);

    int width = gtk_widget_get_allocated_width(widget);
    int height = gtk_widget_get_allocated_height(widget);

    self->m_wndProc(self, WM_SIZE, 0, MAKELPARAM(width, height));
    
    PAINTSTRUCT paintStrct = { 0 };
    paintStrct.hdc = (HDC)cr;
    paintStrct.fErase = TRUE;
    paintStrct.rcPaint.left = 0;
    paintStrct.rcPaint.top = 0;
    paintStrct.rcPaint.right = width;
    paintStrct.rcPaint.bottom = height;
    paintStrct.fRestore = FALSE;
    paintStrct.fIncUpdate = FALSE;

    self->m_msgPtr = &paintStrct;
    self->m_wndProc(self, WM_PAINT, (WPARAM)cr, 0); // -> MbWebView::onPaint
    self->m_msgPtr = nullptr;

//     static cairo_surface_t* g_surface = nullptr;
//     if (!g_surface)
//         g_surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 800, 600);
//     if (g_test_surface) {
//         printf("HwndLinux::onDraw 1\n");
//         cairo_t* memoryCr = cairo_create(g_test_surface);
// 
//         testDraw(memoryCr);
//         cairo_destroy(memoryCr);
// 
//         cairo_set_source_surface(cr, g_test_surface, 0, 0);
//     } else
//         printf("HwndLinux::onDraw 2\n");

    cairo_paint(cr);

    return FALSE;
}

// 先调用onDeleteEvent再onDestroy
gboolean HwndLinux::onDeleteEvent(GtkWidget* widget, GdkEvent* event, gpointer data)
{
    printf("onDeleteEvent:%p\n", data);
    HwndLinux* self = (HwndLinux*)data;
    self->m_wndProc(self, WM_CLOSE, 0, 0);
    if (!self->m_isDestroying)
        return TRUE;
    return FALSE;
}

void HwndLinux::onDestroy(GtkWidget* widget, gpointer data)
{
    printf("onDestroy\n");
    HwndLinux* self = (HwndLinux*)data;
    self->m_wndProc(self, WM_NCDESTROY, 0, 0);
}

gboolean HwndLinux::onConfigureEvent(GtkWidget* widget, GdkEventConfigure* event, gpointer data)
{
    HwndLinux* self = (HwndLinux*)data;
    //         if (self->m_surface)
    //             cairo_surface_destroy(self->m_surface);
    // 
    //         self->m_surface = gdk_window_create_similar_surface(
    //             gtk_widget_get_window(widget),
    //             CAIRO_CONTENT_COLOR,
    //             gtk_widget_get_allocated_width(widget),
    //             gtk_widget_get_allocated_height(widget));
    // 
    //         /* Initialize the surface to white */
    //         self->clearSurface();

    /* We've handled the configure event, no need for further processing. */
    return TRUE;
}

void HwndLinux::clearSurface(void)
{
    cairo_t* cr;
    cr = cairo_create(m_surface);
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);
    cairo_destroy(cr);
}

gboolean HwndLinux::onMotionNotifyEvent(GtkWidget* widget, GdkEventMotion* event, gpointer data)
{
    HwndLinux* self = (HwndLinux*)data;
    self->updataPosOnScreen();
    CrossThreadUiState::get()->updata(&event->state);

    LPARAM lParam = MAKELPARAM((int)event->x, (int)event->y);
    WPARAM wParam = 0;

    if (event->state & GDK_BUTTON1_MASK)
        wParam |= MK_LBUTTON;

    if (event->state & GDK_BUTTON2_MASK)
        wParam |= MK_MBUTTON;

    if (event->state & GDK_BUTTON3_MASK)
        wParam |= MK_RBUTTON;

    self->m_wndProc(self, WM_MOUSEMOVE, wParam, lParam);
    self->m_wndProc(self, WM_SETCURSOR, 0, 0);

    /* We've handled it, stop processing */
    return TRUE;
}

gboolean HwndLinux::onButtonReleaseEvent(GtkWidget* widget, GdkEventButton* event, gpointer data)
{
    HwndLinux* self = (HwndLinux*)data;
    self->updataPosOnScreen();
    CrossThreadUiState::get()->updata(&event->state);

    LPARAM lParam = MAKELPARAM((int)event->x, (int)event->y);

    if (event->button == GDK_BUTTON_PRIMARY) { // 左键
        printf("onButtonReleaseEvent, GDK_BUTTON_PRIMARY\n");
        self->m_wndProc(self, WM_LBUTTONUP, 0, lParam);
    } else if (event->button == GDK_BUTTON_SECONDARY) { // 右键
        printf("onButtonReleaseEvent, GDK_BUTTON_SECONDARY\n");
        self->m_wndProc(self, WM_RBUTTONUP, 0, lParam);
    }

    return TRUE;
}

gboolean HwndLinux::onButtonPressEvent(GtkWidget* widget, GdkEventButton* event, gpointer data)
{
    gtk_widget_grab_focus(widget);
    HwndLinux* self = (HwndLinux*)data;
    self->updataPosOnScreen();
    CrossThreadUiState::get()->updata(&event->state);

    LPARAM lParam = MAKELPARAM((int)event->x, (int)event->y);
    if (event->button == GDK_BUTTON_PRIMARY) { // 左键按下
        printf("onButtonPressEvent, GDK_BUTTON_PRIMARY\n");
        self->m_wndProc(self, WM_LBUTTONDOWN, 0, lParam);
    } else  if (event->button == GDK_BUTTON_SECONDARY) { // 右键按下
        printf("onButtonPressEvent, GDK_BUTTON_SECONDARY\n");
        self->m_wndProc(self, WM_RBUTTONDOWN, 0, lParam);
    }

    return TRUE; // We've handled the event, stop processing
}

gboolean HwndLinux::onKeyRelease(GtkWidget* widget, GdkEventKey* event, gpointer data)
{
    HwndLinux* self = (HwndLinux*)data;
    int key = event->keyval;
    printf("onKeyRelease, keyval = %d\n", key);
    self->m_wndProc(self, WM_KEYUP, (WPARAM)key, 0);

    return TRUE;
}

gboolean HwndLinux::onKeyPress(GtkWidget* widget, GdkEventKey* event, gpointer data)
{
    HwndLinux* self = (HwndLinux*)data;
    int key = event->keyval;
    switch (key) {
    case GDK_Up:
        key = VK_UP;
        break;
    case GDK_Left:
        key = VK_LEFT;
        break;
    case GDK_Right:
        key = VK_RIGHT;
        break;
    case GDK_Down:
        key = VK_DOWN;
        break;
    case GDK_Next:
        key = VK_NEXT;
        break;
    case GDK_Prior:
        key = VK_PRIOR;
        break;
    case GDK_Home:
        key = VK_HOME;
        break;
    case GDK_End:
        key = VK_END;
        break;
    case GDK_BackSpace:
        key = VK_BACK;
        break;   
    case GDK_Tab:
        key = VK_TAB;
        break;
    case GDK_Back:
        key = VK_BACK;
        break;
    case GDK_Escape:
        key = VK_ESCAPE;
        break;
    case GDK_Return:
        key = VK_RETURN;
        break;
    }    
    printf("onKeyPress, keyval = %x\n", key);
    self->m_wndProc(self, WM_KEYDOWN, (WPARAM)key, 0);
    self->m_wndProc(self, WM_CHAR, (WPARAM)key, 0);
    
    return TRUE;
}

gboolean HwndLinux::onFocusOut(GtkWidget *widget, GdkEventFocus *event, gpointer data)
{
    HwndLinux *self = (HwndLinux *)data;
    self->m_wndProc(self, WM_KILLFOCUS, 0, 0);
    return TRUE;
}

gboolean HwndLinux::onScroll(GtkWidget* widget, GdkEventScroll* event, gpointer data)
{
    HwndLinux* self = (HwndLinux*)data;
    self->updataPosOnScreen();
    CrossThreadUiState::get()->updata(&event->state);

    WPARAM wParam = 0;
    LPARAM lParam = 0;

    int flags = 0;
    if (event->state & GDK_SHIFT_MASK)
        flags |= MK_SHIFT;
    if (event->state & GDK_CONTROL_MASK)
        flags |= MK_CONTROL;
    if (event->state & GDK_BUTTON1_MASK)
        flags |= MK_LBUTTON;
    if (event->state & GDK_BUTTON2_MASK)
        flags |= MK_MBUTTON;
    if (event->state & GDK_BUTTON3_MASK)
        flags |= MK_RBUTTON;
    if (event->state & GDK_MOD1_MASK)
        printf("alt is press\n");
    else
        printf("alt is not press\n");

    int delta = 0;

    if (event->direction == GDK_SCROLL_UP) { // 滑轮上滑
        delta = 120;
    } else if (event->direction == GDK_SCROLL_DOWN) { // 滑轮下滑
        delta = -120;
    }

    bool isCapsLock = false;
    bool isNumLock = false;
    bool isScrollLock = false;
    bool isShift = false;
    bool isCtrl = false;
    bool isAtl = false;
    CrossThreadUiState::get()->getState(&isCapsLock, &isNumLock, &isScrollLock, &isShift, &isCtrl, &isAtl);

    // ctrl: 14, atl:18, shift:11, none:10

    GdkDisplay* display = gdk_display_get_default();
    GdkKeymap* keymap = gdk_keymap_get_for_display(display);
    GdkModifierType type1 = gdk_keymap_get_modifier_mask(keymap, GDK_MODIFIER_INTENT_DEFAULT_MOD_MASK);
    GdkModifierType type2 = gdk_keymap_get_modifier_mask(keymap, GDK_MODIFIER_INTENT_PRIMARY_ACCELERATOR);
    GdkModifierType type3 = gdk_keymap_get_modifier_mask(keymap, GDK_MODIFIER_INTENT_CONTEXT_MENU);
    GdkModifierType type4 = gdk_keymap_get_modifier_mask(keymap, GDK_MODIFIER_INTENT_MODIFY_SELECTION);

    printf("type1:%d, type2:%d, type3:%d, type4:%d, state:%d, isCtrl: %d, flags:%d\n", 
        type1, type2, type3, type4, event->state, isCtrl, flags);

    if (isCtrl)
      flags |= MK_CONTROL;

    wParam = MAKEWPARAM(flags, delta);
    lParam = MAKELPARAM(((int)event->x), ((int)event->y));

    self->m_wndProc(self, WM_MOUSEWHEEL, wParam, lParam);
    return TRUE;
}

//////////////////////////////////////////////////////////////////////////

cairo_surface_t* createSurfaceByHwnd(HWND hwnd, int w, int h)
{
    HwndLinux* self = (HwndLinux*)hwnd;
    GdkWindow* window = gtk_widget_get_window(self->m_drawingArea);
    //cairo_surface_t* surface = gdk_window_create_similar_surface(window, CAIRO_CONTENT_COLOR, w, h);
    cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, w, h);
    unsigned char* byteData = cairo_image_surface_get_data(surface);
    return surface;
}

//////////////////////////////////////////////////////////////////////////

LONG SetWindowLongW(HWND hwnd, int nIndex, LONG dwNewLong)
{
    printf("SetWindowLongW\n");
    return 0;
}

LONG GetWindowLongW(HWND hwnd, int nIndex)
{
    HwndLinux* self = (HwndLinux*)hwnd;
    if (GWL_EXSTYLE == nIndex)
        return self->m_styleex;
    else if (GWL_STYLE == nIndex)
        return self->m_style;
    else
        printf("GetWindowLongW fail\n");

    return 0;
}

BOOL SetPropW(HWND hwnd, LPCWSTR lpString, HANDLE hData)
{
    if (!lpString)
        return FALSE;

    unsigned int hash = common::hashStringW(lpString);
    HwndLinux* self = (HwndLinux*)hwnd;
    pthread_mutex_lock(&self->m_propsMutex);
    
    std::map<unsigned int, void *>::iterator it = self->m_props.find(hash);
    if (it != self->m_props.end()) {
        it->second = hData;
    } else {
        self->m_props.insert(std::pair<unsigned int, void *>(hash, hData));
    }
    pthread_mutex_unlock(&self->m_propsMutex);

    return TRUE;
}

HANDLE GetPropW(HWND hwnd, LPCWSTR lpString)
{
    HANDLE ret = nullptr;
    unsigned int hash = common::hashStringW(lpString);
    HwndLinux* self = (HwndLinux*)hwnd;

    pthread_mutex_lock(&self->m_propsMutex);
    std::map<unsigned int, void*>::iterator it = self->m_props.find(hash);
    if (it != self->m_props.end())
        ret = it->second;    
    pthread_mutex_unlock(&self->m_propsMutex);

    return ret;
}

LRESULT DefWindowProcW(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    return 0;
}

HWND CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
    if (!HwndLinux::s_hwnds) {
        HwndLinux::s_hwnds = new std::set<HWND>();
        pthread_mutexattr_t attr;
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init(&HwndLinux::s_hwndMutex, &attr);
    }

    if ((dwStyle & WS_CHILD) != 0)
        DebugBreak();

    if (nWidth == -1)
        nWidth = 800;
    if (nHeight == -1)
        nHeight = 600;

    HwndLinux* self = new HwndLinux();
    self->m_userdata = lpParam;

    self->m_style = dwStyle;
    self->m_styleex = dwExStyle;

    unsigned int hash = common::hashStringW(lpClassName);
    std::map<int, WNDCLASSEXW *>::iterator it = HwndLinux::s_wndClassMap->find(hash);
    if (it == HwndLinux::s_wndClassMap->end())
        DebugBreak();
    self->m_wndProc = it->second->lpfnWndProc;

    GtkWidget* widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widget), "Drawing Area");
    gtk_container_set_border_width(GTK_CONTAINER(widget), 16);

    // 画个框子
    GtkWidget* frame = gtk_frame_new(NULL);
    gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);
    gtk_container_add(GTK_CONTAINER(widget), frame);

    GtkWidget* drawingArea = gtk_drawing_area_new();

    gtk_widget_set_size_request(drawingArea, nWidth, nHeight);
    gtk_container_add(GTK_CONTAINER(frame), drawingArea);

    g_signal_connect(drawingArea, "draw", G_CALLBACK(&HwndLinux::onDraw), self);
    g_signal_connect(drawingArea, "configure-event", G_CALLBACK(&HwndLinux::onConfigureEvent), self);
    g_signal_connect(drawingArea, "motion-notify-event", G_CALLBACK(&HwndLinux::onMotionNotifyEvent), self);
    g_signal_connect(drawingArea, "button-press-event", G_CALLBACK(&HwndLinux::onButtonPressEvent), self);
    g_signal_connect(drawingArea, "button-release-event", G_CALLBACK(&HwndLinux::onButtonReleaseEvent), self);
    g_signal_connect(drawingArea, "scroll-event", G_CALLBACK(&HwndLinux::onScroll), self);

    g_signal_connect(GTK_WINDOW(widget), "destroy", G_CALLBACK(&HwndLinux::onDestroy), self);
    g_signal_connect(GTK_WINDOW(widget), "delete-event", G_CALLBACK(&HwndLinux::onDeleteEvent), self);
    g_signal_connect(GTK_WINDOW(widget), "key-press-event", G_CALLBACK(&HwndLinux::onKeyPress), self);
    g_signal_connect(GTK_WINDOW(widget), "key-release-event", G_CALLBACK(&HwndLinux::onKeyRelease), self);

    //Ask to receive events the drawing area doesn't normally subscribe to. In particular, 
    //we need to ask for the button press and motion notify events that want to handle.
    gtk_widget_set_events(drawingArea, gtk_widget_get_events(drawingArea) | GDK_BUTTON_PRESS_MASK | GDK_POINTER_MOTION_MASK | GDK_BUTTON_RELEASE_MASK | GDK_SCROLL_MASK);

    CREATESTRUCTW createStruct = { 0 };
    createStruct.lpCreateParams = lpParam;
    self->m_wndProc(self, WM_CREATE, 0, (LPARAM)&createStruct);

    self->m_widget = widget;
    self->m_drawingArea = drawingArea;

    printf("CreateWindowExW: %d, %d", nWidth, nHeight);

    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    HwndLinux::s_hwnds->insert(self); // TODO: delete
    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    return self;
}

HWND BindWindowByGTK(void* rootWindow, void* drawingArea, DWORD dwExStyle, LPCWSTR lpClassName, DWORD dwStyle, int nWidth, int nHeight, LPVOID lpParam)
{
    if (!HwndLinux::s_hwnds) {
        HwndLinux::s_hwnds = new std::set<HWND>();
        pthread_mutexattr_t attr;
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init(&HwndLinux::s_hwndMutex, &attr);
    }

    if ((dwStyle & WS_CHILD) != 0)
        DebugBreak();

    if (nWidth == -1)
        nWidth = 1000;
    if (nHeight == -1)
        nHeight = 800;

    HwndLinux* self = new HwndLinux();
    self->m_userdata = lpParam;

    self->m_style = dwStyle;
    self->m_styleex = dwExStyle;

    unsigned int hash = common::hashStringW(lpClassName);
    std::map<int, WNDCLASSEXW *>::iterator it = HwndLinux::s_wndClassMap->find(hash);
    if (it == HwndLinux::s_wndClassMap->end())
        DebugBreak();
    self->m_wndProc = it->second->lpfnWndProc;

    gtk_widget_set_size_request((GtkWidget*)drawingArea, nWidth, nHeight);

    g_signal_connect(drawingArea, "draw", G_CALLBACK(&HwndLinux::onDraw), self);
    g_signal_connect(drawingArea, "configure-event", G_CALLBACK(&HwndLinux::onConfigureEvent), self);
    g_signal_connect(drawingArea, "motion-notify-event", G_CALLBACK(&HwndLinux::onMotionNotifyEvent), self);
    g_signal_connect(drawingArea, "button-press-event", G_CALLBACK(&HwndLinux::onButtonPressEvent), self);
    g_signal_connect(drawingArea, "button-release-event", G_CALLBACK(&HwndLinux::onButtonReleaseEvent), self);
    g_signal_connect(drawingArea, "scroll-event", G_CALLBACK(&HwndLinux::onScroll), self);
    g_signal_connect(drawingArea, "key-press-event", G_CALLBACK(&HwndLinux::onKeyPress), self);
    g_signal_connect(drawingArea, "key-release-event", G_CALLBACK(&HwndLinux::onKeyRelease), self);
    g_signal_connect(drawingArea, "focus-out-event", G_CALLBACK(&HwndLinux::onFocusOut), self);
    g_object_set(G_OBJECT(drawingArea), "can-focus", TRUE, NULL);

    g_signal_connect(GTK_WINDOW((GtkWidget*)rootWindow), "destroy", G_CALLBACK(&HwndLinux::onDestroy), self);
    g_signal_connect(GTK_WINDOW((GtkWidget*)rootWindow), "delete-event", G_CALLBACK(&HwndLinux::onDeleteEvent), self);


    gtk_widget_set_events((GtkWidget*)drawingArea, gtk_widget_get_events((GtkWidget*)drawingArea) | GDK_BUTTON_PRESS_MASK | GDK_POINTER_MOTION_MASK | GDK_BUTTON_RELEASE_MASK | GDK_SCROLL_MASK);

    CREATESTRUCTW createStruct = { 0 };
    createStruct.lpCreateParams = lpParam;
    self->m_wndProc(self, WM_CREATE, 0, (LPARAM)&createStruct);

    self->m_widget = (GtkWidget*)rootWindow;
    self->m_drawingArea = (GtkWidget*)drawingArea;

    //printf("BindWindow: %d, %d", nWidth, nHeight);

    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    HwndLinux::s_hwnds->insert(self); // TODO: delete
    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    return self;
}

BOOL GetClassInfoExW(HINSTANCE hInstance, LPCWSTR lpszClass, LPWNDCLASSEXW lpwcx)
{
    RELEASE_ASSERT(common::ThreadCall::isUiThread());
    printf("GetClassInfoExW");
    return FALSE;
}

BOOL InvalidateRect(HWND hWnd, CONST RECT* lpRect, BOOL bErase)
{
    RELEASE_ASSERT(common::ThreadCall::isUiThread());
    HwndLinux* self = (HwndLinux*)hWnd;
    gtk_widget_queue_draw_area(self->m_drawingArea, lpRect->left, lpRect->top, lpRect->right - lpRect->left, lpRect->bottom - lpRect->top);
    return TRUE;
}

BOOL GetMessageW(MSG* lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
{
    usleep(1000);
    gtk_main_iteration();
    return TRUE;
}

BOOL TranslateMessage(CONST MSG* lpMsg)
{
    return TRUE;
}

LRESULT DispatchMessageW(CONST MSG* lpMsg)
{
    return 0;
}

BOOL PeekMessageW(MSG* lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg)
{
    usleep(1000);
    printf("PeekMessageW\n");
    return TRUE;
}

HDC BeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint)
{
    HwndLinux* self = (HwndLinux*)hWnd;
    *lpPaint = *(LPPAINTSTRUCT)self->m_msgPtr;
    return lpPaint->hdc;
}

BOOL EndPaint(HWND hWnd, CONST PAINTSTRUCT* lpPaint)
{
    return TRUE;
}

BOOL ShowWindow(HWND hWnd, int nCmdShow)
{
    HwndLinux* self = (HwndLinux*)hWnd;
    RELEASE_ASSERT(common::ThreadCall::isUiThread());

    if (SW_SHOW == nCmdShow || SW_SHOWNORMAL == nCmdShow || SW_SHOWNOACTIVATE == nCmdShow) {
        gtk_widget_show_all(self->m_widget);
        printf("ShowWindow show: %p\n", self->m_widget);
    } else {
        printf("ShowWindow hide\n");
        gtk_widget_hide(self->m_widget);
    }
    return TRUE;
}

BOOL GetClientRect(HWND hWnd, LPRECT lpRect)
{
    RELEASE_ASSERT(common::ThreadCall::isUiThread());
    HwndLinux* self = (HwndLinux*)hWnd;
    
    lpRect->left = 0;
    lpRect->top = 0;
    lpRect->right = gtk_widget_get_allocated_width(self->m_drawingArea);
    lpRect->bottom = gtk_widget_get_allocated_height(self->m_drawingArea);

    return TRUE;
}

ATOM RegisterClassW(CONST WNDCLASSW* wndClass)
{
    printf("RegisterClassW\n");
    return 0;
}

ATOM RegisterClassExW(CONST WNDCLASSEXW* wndClass)
{
    RELEASE_ASSERT(common::ThreadCall::isUiThread());
    if (!HwndLinux::s_wndClassMap)
        HwndLinux::s_wndClassMap = new std::map<int, WNDCLASSEXW*>();

    WNDCLASSEXW* wndClassCopy = new WNDCLASSEXW();
    wndClassCopy->lpfnWndProc = wndClass->lpfnWndProc;

    unsigned int hash = common::hashStringW(wndClass->lpszClassName);
    std::map<int, WNDCLASSEXW*>::iterator it = HwndLinux::s_wndClassMap->find(hash);
    if (it != HwndLinux::s_wndClassMap->end())
        return 0;

    HwndLinux::s_wndClassMap->insert(std::pair<int, WNDCLASSEXW*>(hash, wndClassCopy));

    return 0;
}

BOOL IsWindow(HWND hWnd)
{
    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find(hWnd);
    bool b = it != HwndLinux::s_hwnds->end();
    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    return b;
}

DWORD GetWindowThreadProcessId(HWND hWnd, LPDWORD lpdwProcessId)
{
    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    HwndLinux* self = (HwndLinux*)hWnd;
    std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find(hWnd);
    bool b = it != HwndLinux::s_hwnds->end();
    if (!b) {
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        return 0;
    }
    DWORD threadId = self->m_threadId;
    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    return threadId;
}

BOOL GetCursorPos(POINT* lpPoint)
{
    if (common::ThreadCall::isUiThread())
        CrossThreadUiState::get()->updata(nullptr);

    lpPoint->x = CrossThreadUiState::get()->m_cursorPos.x;
    lpPoint->y = CrossThreadUiState::get()->m_cursorPos.y;

    return TRUE;
}

BOOL ScreenToClient(HWND hWnd, LPPOINT lpPoint)
{
    pthread_mutex_lock(&HwndLinux::s_hwndMutex);

    HwndLinux* self = (HwndLinux*)hWnd;

    std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find(hWnd);
    bool b = it != HwndLinux::s_hwnds->end();
    if (!b) {
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        return FALSE;
    }

    if (common::ThreadCall::isUiThread()) {
        gtk_window_get_position(GTK_WINDOW(self->m_widget), &self->m_rootX, &self->m_rootY);
    }

    lpPoint->x -= self->m_rootX;
    lpPoint->y -= self->m_rootY;

    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    return TRUE;
}

BOOL ClientToScreen(HWND hWnd, POINT* lpPoint)
{
    pthread_mutex_lock(&HwndLinux::s_hwndMutex);

    HwndLinux* self = (HwndLinux*)hWnd;

    std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find(hWnd);
    bool b = it != HwndLinux::s_hwnds->end();
    if (!b) {
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        return FALSE;
    }

    if (common::ThreadCall::isUiThread()) {
        gtk_window_get_position(GTK_WINDOW(self->m_widget), &self->m_rootX, &self->m_rootY);
    }

    lpPoint->x += self->m_rootX;
    lpPoint->y += self->m_rootY;

    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    return TRUE;
}

BOOL DestroyWindow(HWND hWnd)
{
    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    HwndLinux* self = (HwndLinux*)hWnd;
    std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find(hWnd);
    bool b = it != HwndLinux::s_hwnds->end();
    if (!b) {
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        return FALSE;
    }

    self->m_isDestroying = true;
    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
    return TRUE;
}

HCURSOR linuxSetCursor(HWND hWnd, HCURSOR hCursor)
{
    if (!hCursor)
        return nullptr;

    GdkCursor* cursor = (GdkCursor*)(hCursor);

    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    HwndLinux* self = (HwndLinux*)hWnd;
    std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find(hWnd);
    bool b = it != HwndLinux::s_hwnds->end();
    if (!b) {
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        return nullptr;
    }
    GdkWindow* window = gtk_widget_get_window(self->m_drawingArea);
    gdk_window_set_cursor(window, cursor);
    g_object_unref(cursor);

    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    return nullptr;
}

HCURSOR LoadCursorW(HINSTANCE hInstance, LPCWSTR lpCursorName)
{
    GdkDisplay* display = gdk_display_get_default();

    if (IDC_ARROW == lpCursorName)
        return gdk_cursor_new_for_display(display, GDK_ARROW);
    if (IDC_IBEAM == lpCursorName)
        return gdk_cursor_new_from_name(display, "text");
    if (IDC_APPSTARTING == lpCursorName)
        return gdk_cursor_new_from_name(display, "wait");
    if (IDC_CROSS == lpCursorName)
        return gdk_cursor_new_for_display(display, GDK_CROSS);
    if (IDC_SIZEALL == lpCursorName)
        return gdk_cursor_new_for_display(display, GDK_FLEUR);
    if (IDC_SIZEWE == lpCursorName)
        return gdk_cursor_new_from_name(display, "ew-resize");
    if (IDC_SIZENS == lpCursorName)
        return gdk_cursor_new_from_name(display, "ns-resize");
    if (IDC_HAND == lpCursorName)
        return gdk_cursor_new_from_name(display, "grab");
    if (IDC_WAIT == lpCursorName)
        return gdk_cursor_new_from_name(display, "wait");
    if (IDC_HELP == lpCursorName)
        return gdk_cursor_new_from_name(display, "help");
    if (IDC_SIZEALL == lpCursorName)
        return gdk_cursor_new_from_name(display, "move");
    if (IDC_NO == lpCursorName)
        return gdk_cursor_new_from_name(display, "not-allowed");  
    return NULL;
}

SHORT GetKeyState(int nVirtKey)
{
    bool isCapsLock = false;
    bool isNumLock = false;
    bool isScrollLock = false;
    bool isShift = false;
    bool isCtrl = false;
    bool isAtl = false;
    CrossThreadUiState::get()->getState(&isCapsLock, &isNumLock, &isScrollLock, &isShift, &isCtrl, &isAtl);

    if (VK_SHIFT == nVirtKey) {
        return isShift ? 0x8000 : 0;
    } else if (VK_CONTROL == nVirtKey) {
        return isCtrl ? 0x8000 : 0;
    } else if (VK_MENU == nVirtKey) {
        return isAtl ? 0x8000 : 0;
    } else if (VK_CAPITAL == nVirtKey) {
        return isCapsLock ? 0x0001 : 0;
    } else if (VK_NUMLOCK == nVirtKey) {
        return isNumLock ? 0x0001 : 0;
    }

    printf("GetKeyState is not impl\n");
    __debugbreak();
    return 0;
}

// int main(int argc, char* argv[])
// {
//     gtk_init(&argc, &argv);
//     return 0;
// }

#endif // WIN32