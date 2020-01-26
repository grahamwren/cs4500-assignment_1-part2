#pragma once

// lang::CwC

#include "object.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

class String : public Object
{
public:
  String() {}

  ~String() {}

  size_t length() {}

  bool equals(Object *o) {}

  size_t hash() {}
};
