#include<stdlib.h>
#include<assert.h>
#include "object.h"
#include "sample_map.h"
#include "string.h"

void test_get() {
  SampleMap theMap;

  String* key = new String("Hello");
  String* value = new String("World");

  theMap.set(key, value);

  String* str;

  int result = theMap.get(key, str);
  assert(result == 0);
  assert(str == value);

  String* wrongKey = new String("Goodbye");
  int result2 = theMap.get(wrongKey, str);
  assert(result == NOT_IN_MAP);
  // str should not change on an invalid lookup
  assert(str == value);
}

void test_remove() {
  SampleMap theMap;

  String* key = new String("Hello");
  String* value = new String("World");

  String* key2 = new String("Design");
  String* value2 = new String("Recipe");

  theMap.set(key, value);
  theMap.set(key2, value2);

  theMap.remove(key);

  String* str = nullptr;
  int result = theMap.get(key, str);

  String* str2 = nullptr;
  theMap.get(key2, str2);

  // successfully removes one entry
  assert(result == NOT_IN_MAP);
  assert(str2 == value2);

  String* wrongKey = new String("Goodbye");
  int badResult = theMap.remove(wrongKey);
  assert(badResult == NOT_IN_MAP);
}

void test_has() {
  SampleMap theMap;

  String* key = new String("Hello");
  String* value = new String("World");

  theMap.set(key, value);

  assert(theMap.has(key));

  String* wrongKey = new String("Goodbye");
  assert(!theMap.has(wrongKey));
}

void test_clear() {
  SampleMap theMap;

  String* key = new String("Hello");
  String* value = new String("World");

  String* key2 = new String("Design");
  String* value2 = new String("Recipe");

  theMap.set(key, value);
  theMap.set(key2, value2);

  theMap.clear();

  String* str = nullptr;
  int result = theMap.get(key, str);

  String* str2 = nullptr;
  int result2 = theMap.get(key2, str2);

  // successfully clears all entries
  assert(result == NOT_IN_MAP);
  assert(result2 == NOT_IN_MAP);
}

void test_size() {
  SampleMap theMap;

  assert(theMap.size() == 0);

  String* key = new String("Hello");
  String* value = new String("World");

  theMap.set(key, value);
  assert(theMap.size() == 1);

  theMap.remove(key);
  assert(theMap.size() == 0);
}

void test_keys() {
  SampleMap theMap;

  String* key = new String("Hello");
  String* value = new String("World");

  String* key2 = new String("Design");
  String* value2 = new String("Recipe");

  theMap.set(key, value);
  theMap.set(key2, value2);

  String** keys = new String*[2];
  theMap.keys(keys);

  // the keys array contains both keys in the map, in either order
  assert(keys[0] == key || keys[1] == key);
  assert(keys[0] == key2 || keys[1] == key2);
}

// make sure setting a key which was already in the map behaves properly
void test_overwrite() {
  SampleMap theMap;

  String* key = new String("Hello");
  String* value = new String("World");

  theMap.set(key, value);

  String* str = nullptr;
  theMap.get(key, str);

  String* value2 = new String("Darkness");

  theMap.set(key, value2);

  String* str2 = nullptr;
  theMap.get(key, str2);

  // the map successfully overwrites values
  assert(str2 == value2);
  // the map does not delete the old value
  assert(value);
}

void test_equals_and_hash() {
  SampleMap theMap1;
  SampleMap theMap2;

  assert(theMap1.equals(&theMap2) && theMap2.equals(&theMap1));

  String* key1 = new String("Hello");
  String* key2 = new String("Hello");

  String* value1 = new String("World");
  String* value2 = new String("World");

  String* key3 = new String("Design");
  String* key4 = new String("Design");

  String* value3 = new String("Recipe");
  String* value4 = new String("Recipe");

  theMap1.set(key1, value1);
  theMap2.set(key2, value2);

  theMap1.set(key3, value3);
  theMap2.set(key4, value4);

  // equal maps are equal
  assert(theMap1.equals(&theMap2) && theMap2.equals(&theMap1));

  theMap1.remove(key1);
  theMap2.remove(key4);
  // unequal maps are unequal
  assert(!theMap1.equals(&theMap2) && !theMap2.equals(&theMap1));
  // unequal maps have unequal hashes
  assert(theMap1.hash() != theMap2.hash());
}

// make sure keys that are .equals equivalent are treated the same,
// for has, get, set, remove
void test_keys_extensional() {
  SampleMap theMap;

  String* key = new String("Hello");
  String* value = new String("World");

  String* key2 = new String("Design");
  String* value2 = new String("Recipe");

  theMap.set(key, value);
  theMap.set(key2, value2);

  String* sameKey = new String("Hello");
  String* value3 = new String("Darkness");

  // testing has
  // make sure the map has both keys
  assert(theMap.has(key));
  assert(theMap.has(sameKey));

  // set the value at sameKey, which is extensionally equivalent to key
  theMap.set(sameKey, value3);

  // make sure the map STILL has both keys
  assert(theMap.has(key));
  assert(theMap.has(sameKey));
  
  String* str;
  theMap.get(key, str);

  String* str2;
  theMap.get(sameKey, str2);

  // testing get and set
  // the values corresponding to the .equals keys are both reference equivalent
  assert(str == value3);
  assert(str == str2);

  String* sameKey2 = new String("World");
  int result = theMap.remove(sameKey2);

  // the .equals key was in the map
  assert(result == 0);

  String* str3;
  int result2 = theMap.get(key2, str3);

  String* str4;
  int result3 = theMap.get(sameKey2, str4);

  // testing remove
  // both .equals keys are no longer in the map
  assert(result2 == NOT_IN_MAP);
  assert(result3 == NOT_IN_MAP);
}

int main(int argc, char** argv) {
  test_get();
  test_remove();
  test_has();
  test_clear();
  test_size();
  test_keys();
  test_overwrite();
  test_equals_and_hash();
  test_keys_extensional();
  return 0;
}
