#pragma once

// lang::CwC

#include <stdlib.h>

/**
 * This represents a general object in the language.  It is the parent class of
 * all Objects.
 */
class Object
{
public:
  virtual ~Object(){};

  /**
   * Test this object for equality to another object.  No object is equal to
   * null.
   */
  virtual bool equals(Object *other) = 0;

  /**
   * Get a hash code representing the object.  Two objects which are not equal
   * must always have different hash codes.
   */
  virtual size_t hash() = 0;
};
