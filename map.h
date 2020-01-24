#pragma once
#include "object.h"
#include "string.h"

class Array;

const int NOT_IN_MAP = 1;

/**
 * A dictionary of string keys and object values.  All keys and values are owned by the caller,
 * and none of the map's methods will modify them.  Keys which are .equals are equal, i.e.
 * the map will never contain two keys which are extensionally equivalent at the same time.
 */
class Map : public Object {
public:

  virtual ~Map() {};

  /**
   * Set the given pointer to the address of the corresponding value in this
   * map.  Return `NOT_IN_MAP` if the key is not in this map.
   */
  virtual int get(String* key, Object* const& obj) = 0;

  /**
   * Set the value at the given key in this map.
   */
  virtual void set(String* key, Object* value) = 0;

  /**
   * Remove the value at the given key in this map.  Return `NOT_IN_MAP` if the key is not in this map.
   */
  virtual int remove(String* key) = 0;

  /**
   * Determine if the given key is in this map.
   */
  virtual bool has(String* key) = 0;

  /**
   * Remove all keys from this map.
   */
  virtual void clear() = 0;

  /**
   * Return the number of entries in this map.
   */
  virtual size_t size() = 0;

  /**
   * Store keys in the given array.
   */
  virtual void keys(String** dest) = 0;

};

