<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkSVGElements_DEFINED
#define SkSVGElements_DEFINED

#include "SkSVGPaintState.h"
#include "SkSVGTypes.h"
#include "SkTDArray.h"

class SkSVGParser;

<<<<<<< HEAD
#define DECLARE_SVG_INFO(_type)                                 \
public:                                                         \
    virtual ~SkSVG##_type();                                    \
    static const SkSVGAttribute gAttributes[];                  \
    virtual int getAttributes(const SkSVGAttribute** attrPtr);  \
    virtual SkSVGTypes getType() const;                         \
    virtual void translate(SkSVGParser& parser, bool defState); \
    typedef SkSVG##_type BASE_CLASS

#define DEFINE_SVG_INFO(_type)                                      \
    SkSVG##_type::~SkSVG##_type() { }                               \
    int SkSVG##_type::getAttributes(const SkSVGAttribute** attrPtr) \
    {                                                               \
        *attrPtr = gAttributes;                                     \
        return SK_ARRAY_COUNT(gAttributes);                         \
    }                                                               \
    SkSVGTypes SkSVG##_type::getType() const { return SkSVGType_##_type; }

#define DEFINE_SVG_NO_INFO(_type)                                         \
    SkSVG##_type::~SkSVG##_type() { }                                     \
    int SkSVG##_type::getAttributes(const SkSVGAttribute**) { return 0; } \
    SkSVGTypes SkSVG##_type::getType() const { return SkSVGType_##_type; }

=======
#define DECLARE_SVG_INFO(_type) \
public: \
    virtual ~SkSVG##_type(); \
    static const SkSVGAttribute gAttributes[]; \
    virtual int getAttributes(const SkSVGAttribute** attrPtr); \
    virtual SkSVGTypes getType() const; \
    virtual void translate(SkSVGParser& parser, bool defState); \
    typedef SkSVG##_type BASE_CLASS

#define DEFINE_SVG_INFO(_type) \
    SkSVG##_type::~SkSVG##_type() {} \
    int SkSVG##_type::getAttributes(const SkSVGAttribute** attrPtr) { \
        *attrPtr = gAttributes; \
        return SK_ARRAY_COUNT(gAttributes); \
    } \
    SkSVGTypes SkSVG##_type::getType() const { return SkSVGType_##_type; }

#define DEFINE_SVG_NO_INFO(_type) \
    SkSVG##_type::~SkSVG##_type() {} \
    int SkSVG##_type::getAttributes(const SkSVGAttribute** ) { return 0; } \
    SkSVGTypes SkSVG##_type::getType() const { return SkSVGType_##_type; }


>>>>>>> miniblink49
struct SkSVGTypeName {
    const char* fName;
    SkSVGTypes fType;
};

class SkSVGElement : public SkSVGBase {
public:
    SkSVGElement();
    virtual ~SkSVGElement();
    virtual SkSVGElement* getGradient();
<<<<<<< HEAD
    virtual SkSVGTypes getType() const = 0;
=======
    virtual SkSVGTypes getType() const  = 0;
>>>>>>> miniblink49
    virtual bool isDef();
    virtual bool isFlushable();
    virtual bool isGroup();
    virtual bool isNotDef();
    virtual bool onEndElement(SkSVGParser& parser);
    virtual bool onStartElement(SkSVGElement* child);
    void setIsDef();
<<<<<<< HEAD
    //  void setIsNotDef();
    virtual void translate(SkSVGParser& parser, bool defState);
    virtual void write(SkSVGParser&, SkString& color);
=======
//  void setIsNotDef();
    virtual void translate(SkSVGParser& parser, bool defState);
    virtual void write(SkSVGParser& , SkString& color);
>>>>>>> miniblink49
    SkString f_id;
    SkSVGPaint fPaintState;
    SkTDArray<SkSVGElement*> fChildren;
    SkSVGElement* fParent;
    bool fIsDef;
    bool fIsNotDef;
<<<<<<< HEAD

=======
>>>>>>> miniblink49
private:
    bool isGroupParent();
};

#endif // SkSVGElements_DEFINED
