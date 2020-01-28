#pragma once

// lang::CwC

#include "object.h"
#include "string.h"

/**
 * A dictionary of string keys and object values.  All keys and values are owned
 * by the caller, and none of the map's methods will modify them.  Keys which
 * are .equals are equal, i.e. the map will never contain two keys which are
 * extensionally equivalent at the same time.
 */
class Map : public Object
{
public:
  virtual ~Map(){};

  /**
   * @brief Gets the Object at the given @param key
   * 
   * @param key the key to lookup the Object to retrieve
   * @return Object* the retrieved Object
   */
  virtual Object *get(Object *key) = 0;

  /**
   * @brief Sets the Object at the given @param key to the given @param value
   * and returns the Object that was there originally
   * 
   * @param key the key to lookup the Object to replace
   * @param value the value to set at the given @param key
   * @return Object* the Object that was replaced
   */
  virtual Object *set(Object *key, Object *value) = 0;

  /**
   * @brief Removes the Object at the given @param key and returns it
   * 
   * @param key the key too lookup the Object to remove
   * @return Object* the removed Object
   */
  virtual Object *remove(Object *key) = 0;

  /**
   * @brief Checks if the given key has a value in this Map
   * 
   * @param key the key to check for a corresponding value
   * @return true if the given key maps to a value in this Map
   * @return false if the given key does NOT map to a value in this Map
   */
  virtual bool has(Object *key) = 0;

  /**
   * @brief Removes all keys from this map
   * 
   */
  virtual void clear() = 0;

  /**
   * @brief Gets the number of entries (i.e. key/value pairs) in this Map
   * 
   * @return size_t the number of entries
   */
  virtual size_t size() = 0;

  /**
   * Store keys in the given array. Caller responsible for allocating at least
   * Map::size() elements.
   */
  virtual void keys(Object **dest) = 0;
};

/**
 * A dictionary of string keys and object values.  All keys and values are owned
 * by the caller, and none of the map's methods will modify them.  Keys which
 * are .equals are equal, i.e. the map will never contain two keys which are
 * extensionally equivalent at the same time.
 */
class StringMap : public Object
{
public:
  virtual ~StringMap(){};

  /**
   * @brief Gets the String at the given @param key
   * 
   * @param key the key to lookup the String to retrieve
   * @return String* the retrieved String
   */
  virtual String *get(String *key) = 0;

  /**
   * @brief Sets the String at the given @param key to the given @param value
   * and returns the String that was there originally
   * 
   * @param key the key to lookup the String to replace
   * @param value the value to set at the given @param key
   * @return String* the String that was replaced
   */
  virtual String *set(String *key, String *value) = 0;

  /**
   * @brief Removes the String at the given @param key and returns it
   * 
   * @param key the key too lookup the String to remove
   * @return String* the removed String
   */
  virtual String *remove(String *key) = 0;

  /**
   * @brief Checks if the given key has a value in this Map
   * 
   * @param key the key to check for a corresponding value
   * @return true if the given key maps to a value in this Map
   * @return false if the given key does NOT map to a value in this Map
   */
  virtual bool has(String *key) = 0;

  /**
   * @brief Removes all keys from this map
   * 
   */
  virtual void clear() = 0;

  /**
   * @brief Gets the number of entries (i.e. key/value pairs) in this Map
   * 
   * @return size_t the number of entries
   */
  virtual size_t size() = 0;

  /**
   * Store keys in the given array. Caller responsible for allocating at least
   * Map::size() elements.
   */
  virtual void keys(String **dest) = 0;
};