
#ifndef content_browser_PageNavController_h
#define content_browser_PageNavController_h

#include "third_party/WebKit/public/web/WebHistoryItem.h"
#include "third_party/WebKit/public/web/WebHistoryCommitType.h"
#include "third_party/WebKit/Source/platform/heap/GarbageCollected.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/Source/wtf/Vector.h"

namespace blink {
class WebLocalFrame;
class WebFrame;
}

namespace content {

class WebPageImpl;
class HistoryEntry;
//class FrameNavController;

class PageNavController : public blink::GarbageCollectedFinalized<PageNavController> {
public:
    PageNavController(WebPageImpl* page);
    ~PageNavController();

    int historyBackListCount();
    int historyForwardListCount();
    void navigateBackForwardSoon(int offset);
    void navigateToIndex(int index);

    void insertOrReplaceEntry(blink::WebLocalFrame* frame, const blink::WebHistoryItem& item, blink::WebHistoryCommitType type, bool isSameDocument);
    blink::WebHistoryItem historyItemForNewChildFrame(blink::WebFrame* frame);

    int getCurrentOffset() const { return m_currentOffset; }
    void navigate(int offset);

    DECLARE_TRACE();

private:
    struct FrameHistoryItem : public GarbageCollectedFinalized<FrameHistoryItem> {
        FrameHistoryItem(const String& name, const blink::WebHistoryItem& item)
        {
            uniqueName = name;
            copyHistoryItem(item);
        }

        FrameHistoryItem(const FrameHistoryItem& other)
        {
            uniqueName = other.uniqueName;
            copyHistoryItem(other.historyItem);
            isSameDocument = other.isSameDocument;
        }

        ~FrameHistoryItem()
        {

        }

        void copyHistoryItem(const blink::WebHistoryItem& item); // ���ֱ����WebHistoryItem���ᵼ��GC�޷�����

        String uniqueName;
        blink::WebHistoryItem historyItem;
        bool isSameDocument;

        DECLARE_TRACE();
    };

    struct AllFrameHistoryItemSet : public GarbageCollectedFinalized<AllFrameHistoryItemSet> {
        void insertOrReplaceEntry(blink::WebLocalFrame* frame, const blink::WebHistoryItem& item, blink::WebHistoryCommitType type, bool isSameDocument);
        void clearRemovedFrame(const blink::WebLocalFrame* frame);

        AllFrameHistoryItemSet* clone() const;

        std::vector<FrameHistoryItem*> m_frameHistoryItems;

    private:
        DECLARE_TRACE();
    };

    bool findEntryImpl(blink::WebLocalFrame* frame, const blink::WebHistoryItem& item, const AllFrameHistoryItemSet& itemSet) const;
    int findEntry(blink::WebLocalFrame* frame, const blink::WebHistoryItem& item) const;
    static bool shouldDoSameDocumentNavigationTo(const FrameHistoryItem* curItem, const FrameHistoryItem* otherItem);
    
private:
    WebPageImpl* m_page;

    std::vector<AllFrameHistoryItemSet*> m_frameHistoryStates;
    int m_currentOffset;
    bool m_protectReentryBackForwardCommit; // ��sub frame��ʱ����һ���������N��BackForwardCommit
};

}

#endif // content_browser_PageNavController_h