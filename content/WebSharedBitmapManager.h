#ifndef WebSharedBitmapManager_h
#define WebSharedBitmapManager_h

#include "base/memory/ref_counted.h"
#include "base/memory/shared_memory.h"
#include "cc/resources/shared_bitmap_manager.h"

namespace content {

class WebSharedBitmapManager : public cc::SharedBitmapManager {
public:
    WebSharedBitmapManager();
    virtual ~WebSharedBitmapManager();

    virtual std::unique_ptr<cc::SharedBitmap> AllocateSharedBitmap(const gfx::Size& size) override;
    virtual std::unique_ptr<cc::SharedBitmap> GetSharedBitmapFromId(const gfx::Size&, const cc::SharedBitmapId&) override;
    //virtual scoped_ptr<cc::SharedBitmap> GetBitmapForSharedMemory(base::SharedMemory* mem) OVERRIDE;

    struct SharedMemoryItem;
    std::vector<SharedMemoryItem*>* getMaps() { return &m_maps; }

    struct SharedMemoryItem {
        uint8* memory;
        gfx::Size size;
        cc::SharedBitmapId id;
        int ref;
    };

private:
    std::vector<SharedMemoryItem*> m_maps;
    DISALLOW_COPY_AND_ASSIGN(WebSharedBitmapManager);
};

} // content

#endif // WebSharedBitmapManager_h