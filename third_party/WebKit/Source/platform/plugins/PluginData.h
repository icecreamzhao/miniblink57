/*
    Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies)

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef PluginData_h
#define PluginData_h

#include "platform/PlatformExport.h"
<<<<<<< HEAD
#include "platform/weborigin/SecurityOrigin.h"
#include "wtf/Noncopyable.h"
=======
>>>>>>> miniblink49
#include "wtf/RefCounted.h"
#include "wtf/Vector.h"
#include "wtf/text/WTFString.h"

namespace blink {

<<<<<<< HEAD
=======
class Page;
>>>>>>> miniblink49
struct PluginInfo;

struct MimeClassInfo {
    String type;
    String desc;
    Vector<String> extensions;
};

inline bool operator==(const MimeClassInfo& a, const MimeClassInfo& b)
{
    return a.type == b.type && a.desc == b.desc && a.extensions == b.extensions;
}

struct PluginInfo {
    String name;
    String file;
    String desc;
    Vector<MimeClassInfo> mimes;
};

class PLATFORM_EXPORT PluginData : public RefCounted<PluginData> {
<<<<<<< HEAD
    WTF_MAKE_NONCOPYABLE(PluginData);

public:
    static PassRefPtr<PluginData> create(SecurityOrigin* mainFrameOrigin)
    {
        return adoptRef(new PluginData(mainFrameOrigin));
    }

    const Vector<PluginInfo>& plugins() const { return m_plugins; }
    const Vector<MimeClassInfo>& mimes() const { return m_mimes; }
    const Vector<size_t>& mimePluginIndices() const
    {
        return m_mimePluginIndices;
    }
    const SecurityOrigin* origin() const { return m_mainFrameOrigin.get(); }
=======
public:
    static PassRefPtr<PluginData> create(const Page* page) { return adoptRef(new PluginData(page)); }

    const Vector<PluginInfo>& plugins() const { return m_plugins; }
    const Vector<MimeClassInfo>& mimes() const { return m_mimes; }
    const Vector<size_t>& mimePluginIndices() const { return m_mimePluginIndices; }
>>>>>>> miniblink49

    bool supportsMimeType(const String& mimeType) const;
    String pluginNameForMimeType(const String& mimeType) const;

<<<<<<< HEAD
    // refreshBrowserSidePluginCache doesn't update existent instances of
    // PluginData.
    static void refreshBrowserSidePluginCache();

private:
    explicit PluginData(SecurityOrigin* mainFrameOrigin);
=======
    static void refresh();

private:
    explicit PluginData(const Page*);
    void initPlugins(const Page*);
>>>>>>> miniblink49
    const PluginInfo* pluginInfoForMimeType(const String& mimeType) const;

    Vector<PluginInfo> m_plugins;
    Vector<MimeClassInfo> m_mimes;
    Vector<size_t> m_mimePluginIndices;
<<<<<<< HEAD
    RefPtr<SecurityOrigin> m_mainFrameOrigin;
};

} // namespace blink
=======
};

// Checks if any of the plugins handle this extension, and if so returns the
// plugin's mime type for this extension. Otherwise returns an empty string.
PLATFORM_EXPORT String getPluginMimeTypeFromExtension(const String& extension);

}
>>>>>>> miniblink49

#endif
