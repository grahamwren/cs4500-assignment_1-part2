# CS4500 - Assignment 1 - Part 2

[@grahamwren](https://github.com/grahamwren)

[@jagen31](https://github.com/jagen31)

## Map

We chose to design a `Map` interface. This interface provides these methods:

```cpp
// map.h
Object *get(String *key);
void set(String *key, Object *value);
void remove(String *key);
bool has(String *key);
void clear();
size_t size();
void keys(String **dest);
```

For simplicity and memory safety our `Map` interface and tests expect that the
implementation of `Map` does not own any of the values or keys stored in it.
This means that pointers returned by `get` and `keys` point to the same memory
as the pointer which was set by `set`. Simillarly `clear` and the destructor
should not delete any of the memory which was passed in via `set`.
