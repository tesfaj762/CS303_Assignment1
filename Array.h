
#ifndef ARRAY_H
#define ARRAY_H

#include <utility>
#include <memory>

template<class Type>
class Array {
public:

  Array();
  explicit Array(int size);

  Array& operator=(const Array& arr);
  Array(const Array& arr);

  Array& operator=(Array&& other) noexcept;

  ~Array();

  //inserts a value at an index
  void insert(size_t index, Type value);

  //returns a value at a given index
  Type get(size_t index);

  //Checks if a value exits in the array, returns index if it exists otherwise returns -1
  int search(Type value);

  //Takes an index and a value, and replaces the value at that index with the new value
  //Returns the new value and the old value
  std::pair<Type, Type> modify(size_t index, Type value);

  //insert value at the end of the array
  void push_back(Type value);

  //removes a value at index if value exists
  void remove(size_t index);

  void print();

  [[nodiscard]] int size() const { return m_size; }

  [[nodiscard]] int capacity() const {return m_capacity;}

private:

  //doubles the size of the array when its full
  void reallocate();

  //contiguous block of memory stored here
  std::unique_ptr<Type[]> array;

  int m_size;
  int m_capacity;

};

#include "Array.tpp"


#endif