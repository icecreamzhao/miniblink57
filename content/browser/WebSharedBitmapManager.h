#ifndef WebSharedBitmapManager_h
#define WebSharedBitmapManager_h

#include "base/memory/ref_counted.h"
#include "base/memory/shared_memory.h"
#include "base/synchronization/lock.h"
#include "cc/resources/shared_bitmap_manager.h"
#include "gpu/command_buffer/common/mailbox.h"

namespace content {

class WebSharedBitmapManager : public cc::SharedBitmapManager {
public:
    WebSharedBitmapManager();
    virtual ~WebSharedBitmapManager();

    virtual std::unique_ptr<cc::SharedBitmap> AllocateSharedBitmap(const gfx::Size& size) override;
    virtual std::unique_ptr<cc::SharedBitmap> GetSharedBitmapFromId(const gfx::Size&, const cc::SharedBitmapId&) override;
    //virtual scoped_ptr<cc::SharedBitmap> GetBitmapForSharedMemory(base::SharedMemory* mem) OVERRIDE;

private:
    DISALLOW_COPY_AND_ASSIGN(WebSharedBitmapManager);
    std::vector<uint8*> m_memorys;
    std::map<cc::SharedBitmapId, cc::SharedBitmap*> m_sharedBitmapMap;
    base::Lock m_lock;
};

} // content

#endif // WebSharedBitmapManager_h