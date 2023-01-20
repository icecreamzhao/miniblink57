// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HitRegion_h
#define HitRegion_h

#include "core/dom/Element.h"
#include "modules/canvas2d/HitRegionOptions.h"
#include "platform/graphics/Path.h"
#include "platform/heap/Handle.h"
#include "wtf/Noncopyable.h"
<<<<<<< HEAD
=======
#include "wtf/OwnPtr.h"
#include "wtf/PassOwnPtr.h"
>>>>>>> miniblink49
#include "wtf/PassRefPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

<<<<<<< HEAD
class HitRegion final : public GarbageCollectedFinalized<HitRegion> {
public:
    static HitRegion* create(const Path& path, const HitRegionOptions& options)
    {
        return new HitRegion(path, options);
=======
class HitRegion final : public RefCountedWillBeGarbageCollectedFinalized<HitRegion> {
public:
    static PassRefPtrWillBeRawPtr<HitRegion> create(const Path& path, const HitRegionOptions& options)
    {
        return adoptRefWillBeNoop(new HitRegion(path, options));
>>>>>>> miniblink49
    }

    virtual ~HitRegion() { }

    void removePixels(const Path&);
<<<<<<< HEAD

=======
    void updateAccessibility(Element* canvas);

    bool contains(const LayoutPoint&) const;
>>>>>>> miniblink49
    bool contains(const FloatPoint&) const;

    const String& id() const { return m_id; }
    const Path& path() const { return m_path; }
    Element* control() const { return m_control.get(); }
<<<<<<< HEAD
=======
    WindRule fillRule() const { return m_fillRule; }
>>>>>>> miniblink49

    DECLARE_TRACE();

private:
    HitRegion(const Path&, const HitRegionOptions&);

    String m_id;
<<<<<<< HEAD
    Member<Element> m_control;
=======
    RefPtrWillBeMember<Element> m_control;
>>>>>>> miniblink49
    Path m_path;
    WindRule m_fillRule;
};

<<<<<<< HEAD
class HitRegionManager final : public GarbageCollected<HitRegionManager> {
    WTF_MAKE_NONCOPYABLE(HitRegionManager);

public:
    static HitRegionManager* create() { return new HitRegionManager; }

    void addHitRegion(HitRegion*);

    void removeHitRegion(HitRegion*);
    void removeHitRegionById(const String& id);
    void removeHitRegionByControl(const Element*);
=======
class HitRegionManager final : public GarbageCollectedFinalized<HitRegionManager> {
    WTF_MAKE_NONCOPYABLE(HitRegionManager);
public:
    static HitRegionManager* create() { return new HitRegionManager; }
    ~HitRegionManager() { }

    void addHitRegion(PassRefPtrWillBeRawPtr<HitRegion>);

    void removeHitRegion(HitRegion*);
    void removeHitRegionById(const String& id);
    void removeHitRegionByControl(Element*);
>>>>>>> miniblink49
    void removeHitRegionsInRect(const FloatRect&, const AffineTransform&);
    void removeAllHitRegions();

    HitRegion* getHitRegionById(const String& id) const;
<<<<<<< HEAD
    HitRegion* getHitRegionByControl(const Element*) const;
    HitRegion* getHitRegionAtPoint(const FloatPoint&) const;
=======
    HitRegion* getHitRegionByControl(Element*) const;
    HitRegion* getHitRegionAtPoint(const LayoutPoint&) const;
>>>>>>> miniblink49

    unsigned getHitRegionsCount() const;

    DECLARE_TRACE();

private:
    HitRegionManager() { }

<<<<<<< HEAD
    typedef HeapListHashSet<Member<HitRegion>> HitRegionList;
    typedef HitRegionList::const_reverse_iterator HitRegionIterator;
    typedef HeapHashMap<String, Member<HitRegion>> HitRegionIdMap;
    typedef HeapHashMap<Member<const Element>, Member<HitRegion>>
        HitRegionControlMap;
=======
    typedef WillBeHeapListHashSet<RefPtrWillBeMember<HitRegion>> HitRegionList;
    typedef HitRegionList::const_reverse_iterator HitRegionIterator;
    typedef WillBeHeapHashMap<String, RefPtrWillBeMember<HitRegion>> HitRegionIdMap;
    typedef WillBeHeapHashMap<RefPtrWillBeMember<Element>, RefPtrWillBeMember<HitRegion>> HitRegionControlMap;
>>>>>>> miniblink49

    HitRegionList m_hitRegionList;
    HitRegionIdMap m_hitRegionIdMap;
    HitRegionControlMap m_hitRegionControlMap;
};

} // namespace blink

#endif
