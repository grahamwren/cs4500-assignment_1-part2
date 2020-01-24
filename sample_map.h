#pragma once
#include "object.h"
#include "map.h"
#include "string.h"

class Array;

class SampleMap : public Map {
public:

  ~SampleMap() {}

  int get(String* key, Object* const& obj) { return NOT_IN_MAP; }

  void set(String* key, Object* value) {}

  int remove(String* key) { return NOT_IN_MAP; }

  bool has(String* key) { return false; }

  void clear() {}

  size_t size() { return 0; }

  void keys(String** dest) {}

  size_t hash() { return 42; }

  bool equals(Object* o) { return false; }
};

