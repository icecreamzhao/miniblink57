/*
* Copyright (C) 1997-2005, International Business Machines Corporation and others. All Rights Reserved.
*******************************************************************************
*
* File PARSEPOS.H
*
* Modification History:
*
*   Date        Name        Description
*   07/09/97    helena      Converted from java.
*   07/17/98    stephen     Added errorIndex support.
*   05/11/99    stephen     Cleaned up.
*******************************************************************************
*/

#ifndef PARSEPOS_H
#define PARSEPOS_H

<<<<<<< HEAD
#include "unicode/uobject.h"
#include "unicode/utypes.h"

=======
#include "unicode/utypes.h"
#include "unicode/uobject.h"

 
>>>>>>> miniblink49
U_NAMESPACE_BEGIN

/**
 * \file
 * \brief C++ API: Canonical Iterator
 */
/** 
 * <code>ParsePosition</code> is a simple class used by <code>Format</code>
 * and its subclasses to keep track of the current position during parsing.
 * The <code>parseObject</code> method in the various <code>Format</code>
 * classes requires a <code>ParsePosition</code> object as an argument.
 *
 * <p>
 * By design, as you parse through a string with different formats,
 * you can use the same <code>ParsePosition</code>, since the index parameter
 * records the current position.
 *
 * The ParsePosition class is not suitable for subclassing.
 *
 * @version     1.3 10/30/97
 * @author      Mark Davis, Helena Shih
 * @see         java.text.Format
 */

class U_COMMON_API ParsePosition : public UObject {
public:
    /**
     * Default constructor, the index starts with 0 as default.
     * @stable ICU 2.0
     */
    ParsePosition()
<<<<<<< HEAD
        : UObject()
        , index(0)
        , errorIndex(-1)
    {
    }
=======
        : UObject(),
        index(0),
        errorIndex(-1)
      {}
>>>>>>> miniblink49

    /**
     * Create a new ParsePosition with the given initial index.
     * @param newIndex the new text offset.
     * @stable ICU 2.0
     */
    ParsePosition(int32_t newIndex)
<<<<<<< HEAD
        : UObject()
        , index(newIndex)
        , errorIndex(-1)
    {
    }
=======
        : UObject(),
        index(newIndex),
        errorIndex(-1)
      {}
>>>>>>> miniblink49

    /**
     * Copy constructor
     * @param copy the object to be copied from.
     * @stable ICU 2.0
     */
    ParsePosition(const ParsePosition& copy)
<<<<<<< HEAD
        : UObject(copy)
        , index(copy.index)
        , errorIndex(copy.errorIndex)
    {
    }
=======
        : UObject(copy),
        index(copy.index),
        errorIndex(copy.errorIndex)
      {}
>>>>>>> miniblink49

    /**
     * Destructor
     * @stable ICU 2.0
     */
    virtual ~ParsePosition();

    /**
     * Assignment operator
     * @stable ICU 2.0
     */
<<<<<<< HEAD
    ParsePosition& operator=(const ParsePosition& copy);
=======
    ParsePosition&      operator=(const ParsePosition& copy);
>>>>>>> miniblink49

    /**
     * Equality operator.
     * @return TRUE if the two parse positions are equal, FALSE otherwise.
     * @stable ICU 2.0
     */
<<<<<<< HEAD
    UBool operator==(const ParsePosition& that) const;
=======
    UBool              operator==(const ParsePosition& that) const;
>>>>>>> miniblink49

    /**
     * Equality operator.
     * @return TRUE if the two parse positions are not equal, FALSE otherwise.
     * @stable ICU 2.0
     */
<<<<<<< HEAD
    UBool operator!=(const ParsePosition& that) const;
=======
    UBool              operator!=(const ParsePosition& that) const;
>>>>>>> miniblink49

    /**
     * Clone this object.
     * Clones can be used concurrently in multiple threads.
     * If an error occurs, then NULL is returned.
     * The caller must delete the clone.
     *
     * @return a clone of this object
     *
     * @see getDynamicClassID
     * @stable ICU 2.8
     */
<<<<<<< HEAD
    ParsePosition* clone() const;
=======
    ParsePosition *clone() const;
>>>>>>> miniblink49

    /**
     * Retrieve the current parse position.  On input to a parse method, this
     * is the index of the character at which parsing will begin; on output, it
     * is the index of the character following the last character parsed.
     * @return the current index.
     * @stable ICU 2.0
     */
    int32_t getIndex(void) const;

    /**
     * Set the current parse position.
     * @param index the new index.
     * @stable ICU 2.0
     */
    void setIndex(int32_t index);

    /**
     * Set the index at which a parse error occurred.  Formatters
     * should set this before returning an error code from their
     * parseObject method.  The default value is -1 if this is not
     * set.
     * @stable ICU 2.0
     */
    void setErrorIndex(int32_t ei);

    /**
     * Retrieve the index at which an error occurred, or -1 if the
     * error index has not been set.
     * @stable ICU 2.0
     */
    int32_t getErrorIndex(void) const;

    /**
     * ICU "poor man's RTTI", returns a UClassID for this class.
     *
     * @stable ICU 2.2
     */
    static UClassID U_EXPORT2 getStaticClassID();

    /**
     * ICU "poor man's RTTI", returns a UClassID for the actual class.
     *
     * @stable ICU 2.2
     */
    virtual UClassID getDynamicClassID() const;

private:
    /**
     * Input: the place you start parsing.
     * <br>Output: position where the parse stopped.
     * This is designed to be used serially,
     * with each call setting index up for the next one.
     */
    int32_t index;

    /**
     * The index at which a parse error occurred.
     */
    int32_t errorIndex;
<<<<<<< HEAD
=======

>>>>>>> miniblink49
};

inline ParsePosition&
ParsePosition::operator=(const ParsePosition& copy)
{
<<<<<<< HEAD
    index = copy.index;
    errorIndex = copy.errorIndex;
    return *this;
=======
  index = copy.index;
  errorIndex = copy.errorIndex;
  return *this;
>>>>>>> miniblink49
}

inline UBool
ParsePosition::operator==(const ParsePosition& copy) const
{
<<<<<<< HEAD
    if (index != copy.index || errorIndex != copy.errorIndex)
        return FALSE;
    else
        return TRUE;
=======
  if(index != copy.index || errorIndex != copy.errorIndex)
  return FALSE;
  else
  return TRUE;
>>>>>>> miniblink49
}

inline UBool
ParsePosition::operator!=(const ParsePosition& copy) const
{
<<<<<<< HEAD
    return !operator==(copy);
=======
  return !operator==(copy);
>>>>>>> miniblink49
}

inline int32_t
ParsePosition::getIndex() const
{
<<<<<<< HEAD
    return index;
=======
  return index;
>>>>>>> miniblink49
}

inline void
ParsePosition::setIndex(int32_t offset)
{
<<<<<<< HEAD
    this->index = offset;
=======
  this->index = offset;
>>>>>>> miniblink49
}

inline int32_t
ParsePosition::getErrorIndex() const
{
<<<<<<< HEAD
    return errorIndex;
=======
  return errorIndex;
>>>>>>> miniblink49
}

inline void
ParsePosition::setErrorIndex(int32_t ei)
{
<<<<<<< HEAD
    this->errorIndex = ei;
=======
  this->errorIndex = ei;
>>>>>>> miniblink49
}
U_NAMESPACE_END

#endif
