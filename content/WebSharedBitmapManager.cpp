
#include "content/WebSharedBitmapManager.h"
#include "ui/gfx/geometry/size.h"

namespace content {

WebSharedBitmapManager::WebSharedBitmapManager()
{
}

WebSharedBitmapManager::~WebSharedBitmapManager()
{
}

class SharedMemoryBitmap : public cc::SharedBitmap {
public:
    SharedMemoryBitmap(WebSharedBitmapManager* mgr, uint8* pixels, const cc::SharedBitmapId& id)
        : cc::SharedBitmap(pixels, id)
        , m_mgr(mgr)
    {
    }

    ~SharedMemoryBitmap()
    {
        std::vector<WebSharedBitmapManager::SharedMemoryItem*>* maps = m_mgr->getMaps();
        for (size_t i = 0; i < maps->size(); ++i) {
            WebSharedBitmapManager::SharedMemoryItem* it = maps->at(i);
            if (it->id != id())
                continue;
            it->ref--;

            if (0 == it->ref) {
                free(pixels());
                delete it;
                maps->erase(maps->begin() + i);
                return;
            }
        }
    }

private:
    WebSharedBitmapManager* m_mgr;
};

std::unique_ptr<cc::SharedBitmap> WebSharedBitmapManager::AllocateSharedBitmap(const gfx::Size& size)
{
    size_t memorySize;
    if (!cc::SharedBitmap::SizeInBytes(size, &memorySize))
        return nullptr;

    uint8* memory = static_cast<uint8*>(malloc(memorySize));
    cc::SharedBitmapId id = cc::SharedBitmap::GenerateId();

    SharedMemoryItem* item = new SharedMemoryItem();
    item->memory = memory;
    item->size = size;
    item->id = id;
    item->ref = 1;
    m_maps.push_back(item);

    return std::unique_ptr<cc::SharedBitmap>(new SharedMemoryBitmap(this, memory, id));
}

std::unique_ptr<cc::SharedBitmap> WebSharedBitmapManager::GetSharedBitmapFromId(const gfx::Size& size, const cc::SharedBitmapId& id)
{
    for (size_t i = 0; i < m_maps.size(); ++i) {
        SharedMemoryItem* item = m_maps[i];
        if (item->id == id && item->size == size) {
            item->ref++;
            return std::unique_ptr<cc::SharedBitmap>(new SharedMemoryBitmap(this, item->memory, item->id));
        }
    }

    return nullptr;
}

} // content
