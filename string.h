#pragma once

// lang::CwC

#include "object.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

class String : public Object {
public:
  char *chars_;
  size_t len_;

  String(const char *chars) {
    size_t inputLen = strlen(chars) + 1;
    chars_ = new char[inputLen];
    memcpy(chars_, chars, inputLen);

    len_ = inputLen - 1;
  }

  ~String() { delete[] chars_; }

  size_t length() { return len_; }

  bool equals(Object *o) {

    String *otherString = dynamic_cast<String *>(o);

    if (otherString == this) {
      return true;
    }

    return strcmp(chars_, otherString->chars_) == 0;
  }

  size_t hash() { return 42; }
};
