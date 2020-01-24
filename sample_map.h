#pragma once
#include "map.h"
#include "object.h"
#include "string.h"

class SampleMap : public Map {
public:
  ~SampleMap() {}

  Object *get(String *key) { return nullptr; }

  void set(String *key, Object *value) {}

  void remove(String *key) {}

  bool has(String *key) { return false; }

  void clear() {}

  size_t size() { return 0; }

  void keys(String **dest) {}

  size_t hash() { return 42; }

  bool equals(Object *o) { return false; }
};
