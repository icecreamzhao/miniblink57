
#include "content/browser/WebSharedBitmapManager.h"
#include "base/memory/ptr_util.h"
#include "ui/gfx/geometry/size.h"

namespace content {

WebSharedBitmapManager::WebSharedBitmapManager()
{
}

WebSharedBitmapManager::~WebSharedBitmapManager()
{
    for (size_t i = 0; i < m_memorys.size(); ++i) {
        free(m_memorys[i]);
    }
}

std::unique_ptr<cc::SharedBitmap> WebSharedBitmapManager::AllocateSharedBitmap(const gfx::Size& size)
{
    base::AutoLock lock(m_lock);
    size_t memory_size;
    if (!cc::SharedBitmap::SizeInBytes(size, &memory_size))
        return std::unique_ptr<cc::SharedBitmap>();
    cc::SharedBitmapId id = cc::SharedBitmap::GenerateId();

    uint8* memory = static_cast<uint8*>(malloc(memory_size));
    m_memorys.push_back(memory);

    cc::SharedBitmap* result = new cc::SharedBitmap(static_cast<uint8*>(memory), id);
    m_sharedBitmapMap.insert(std::pair<cc::SharedBitmapId, cc::SharedBitmap*>(result->id(), result));
    return std::unique_ptr<cc::SharedBitmap>(result);
}

std::unique_ptr<cc::SharedBitmap> WebSharedBitmapManager::GetSharedBitmapFromId(const gfx::Size&, const cc::SharedBitmapId& id)
{
    base::AutoLock lock(m_lock);
    std::map<cc::SharedBitmapId, cc::SharedBitmap*>::iterator it = m_sharedBitmapMap.find(id);
    if (it == m_sharedBitmapMap.end())
        return nullptr;

    cc::SharedBitmap* result = it->second;
    return base::MakeUnique<cc::SharedBitmap>(result->pixels(), id);
}

} // content
