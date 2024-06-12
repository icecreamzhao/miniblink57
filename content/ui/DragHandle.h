
#ifndef content_browser_DragHandle_h
#define content_browser_DragHandle_h

//#include "third_party/WebKit/public/web/WebDragOperation.h"
#include "third_party/WebKit/public/platform/WebDragData.h"
#include "third_party/WebKit/public/platform/WebDragData.h"
#include "third_party/WebKit/public/platform/WebTraceLocation.h"
#include "third_party/WebKit/public/platform/WebDragOperation.h"
#include "third_party/WebKit/Source/wtf/OwnPtr.h"
#include "third_party/WebKit/Source/wtf/PassOwnPtr.h"
#include "third_party/WebKit/Source/wtf/Functional.h"

#include "base/COMPtr.h"
#include <shlobj.h>
//#include <oleidl.h>
#include <functional>
#include <vector>

namespace blink {
class WebViewImpl;
class WebImage;
class WebLocalFrame;
struct WebPoint;
class Task;
}

typedef struct _wkeWebDragData wkeWebDragData;

namespace content {

class DragHandle : public IDropTarget {
public:
    DragHandle(
        std::function<void(void)>&& notifOnEnterDrag,
        std::function<void(void)>&& notifOnLeaveDrag,
        std::function<void(void)>&& notifOnDragging
        );
    ~DragHandle() {}

    void setViewWindow(HWND viewWindow, blink::WebViewImpl* webViewImpl);

    static DWORD draggingSourceOperationMaskToDragCursors(blink::WebDragOperationsMask op);

    blink::WebDragOperation keyStateToDragOperation(DWORD grfKeyState) const;

    static bool containsPlainText(IDataObject* pDataObject);

    blink::WebDragData dropDataToWebDragData(IDataObject* pDataObject);

    static DWORD dragOperationToDragCursor(blink::WebDragOperation op);
    static blink::WebDragOperation dragCursorTodragOperation(DWORD op);

    void startDragging(blink::WebLocalFrame* frame,
        const wkeWebDragData* data,
        const blink::WebDragOperationsMask mask,
        const blink::WebImage& image,
        const blink::WebPoint& dragImageOffset);

    blink::WebDragOperation startDraggingInUiThread(blink::WebLocalFrame* frame,
        const wkeWebDragData* data,
        const blink::WebDragOperationsMask mask,
        const blink::WebImage* image,
        const blink::WebPoint* dragImageOffset);
    
    // IDropTarget
    HRESULT __stdcall DragEnter(     
        /* [unique][in] */ IDataObject* pDataObj,
        /* [in] */ DWORD grfKeyState,
        /* [in] */ POINTL pt,
        /* [out][in] */ DWORD* pdwEffect) override;
    HRESULT __stdcall DragOver(
    
        /* [in] */ DWORD grfKeyState,
        /* [in] */ POINTL pt,
        /* [out][in] */ DWORD* pdwEffect
    
    ) override;
    HRESULT __stdcall DragLeave() override;
    HRESULT __stdcall Drop(
        /* [unique][in] */ IDataObject* pDataObj,
        /* [in] */ DWORD grfKeyState,
        /* [in] */ POINTL pt,
        /* [out][in] */ DWORD* pdwEffect
    ) override;
    HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject) override;

    ULONG __stdcall AddRef() override;
    ULONG __stdcall Release() override;

    ULONG getRefCount() const;

    IDataObject* getDragData() const { return m_dragData.get(); }

private:
    void postMainThreadTask(const blink::WebTraceLocation& location, std::function<void(void)>&& closure);
    void runMainThreadTasks();
    void simulateDrag();

    long m_refCount;
    int m_taskCount;

    bool m_isDragTargetDragEnter;

    blink::WebViewImpl* m_webViewImpl;

    HWND m_viewWindow;
    COMPtr<IDataObject> m_dragData;
    COMPtr<IDropTargetHelper> m_dropTargetHelper;
    // FIXME: This variable is part of a workaround. The drop effect (pdwEffect) passed to Drop is incorrect. 
    // We set this variable in DragEnter and DragOver so that it can be used in Drop to set the correct drop effect. 
    // Thus, on return from DoDragDrop we have the correct pdwEffect for the drag-and-drop operation.
    // (see https://bugs.webkit.org/show_bug.cgi?id=29264)
    DWORD m_lastDropEffect{ 0 };

    blink::WebDragOperationsMask m_mask;

    std::function<void(void)> m_notifOnEnterDrag;
    std::function<void(void)> m_notifOnLeaveDrag;
    std::function<void(void)> m_notifOnDragging;

    COMPtr<IDataObject> m_tempDataObjectForSimulate;

    WTF::RecursiveMutex m_tasksLock;
    std::vector<std::function<void(void)>*> m_tasks;
};

}

#endif // content_browser_DragHandle_h