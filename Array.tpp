#pragma once
#include <cstddef>
#include <memory>
#include <utility>
#include <iostream>


template<class Type>
Array<Type>::Array() 
: 
array(std::make_unique<Type[]>(10)), //inital size of array is 10
m_size(0),
m_capacity(10) {}



template<class Type>
Array<Type>::Array(int size) 
:
array(std::make_unique<Type[]>(size)), //user can specify size of array
m_size(0),
m_capacity(size) {}


//copy constructor
template<class Type>
Array<Type>::Array(const Array& arr)
:
array(std::make_unique<Type[]> (arr.m_capacity)),
m_size(arr.m_size),
m_capacity(arr.m_capacity) {

  for (int i = 0; i < m_size; i++) {
    array[i] = arr.array[i];
  }

}


//copy assignment operator
template<class Type>
Array<Type>& Array<Type>::operator=(const Array& arr) {

  if (this == &arr) {
    return *this;
  }

  std::unique_ptr<Type[]> temp(std::make_unique<Type[]>(arr.m_capacity));

  array.swap(temp);

  for (int i = 0; i < arr.m_size; i++) {
    temp[i] = arr.array[i];
  }

  array.swap(temp);

  this->m_capacity = arr.m_capacity;
  this->m_size = arr.m_size;

  return *this;

}


//move assignment operator
template<class Type>
Array<Type>& Array<Type>::operator=(Array&& other)  noexcept {

  if (this != &other) {
    array.swap(other.array);
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
  }

  return *this;

}

//deconstructor is set to default since unique_ptr will automatically free allocated memory for array
template<class Type>
Array<Type>::~Array() = default;



//returns a value based on index
template<class Type>
Type Array<Type>::get(size_t index) {

  if (index > m_capacity - 1) {
    throw std::out_of_range("Invalid array access");
  }

  return array[index];

}


//user can insert a value by passing an index and value
template<class Type>
void Array<Type>::insert(size_t index, Type value) {

  //check bounds
  if (index > m_size) {
    throw std::out_of_range("index to insert is out of range");
  }

  //check if theres enough space, otherwise resize
  if (m_size == m_capacity) {
    reallocate();
  }

  //shift over all the values
  for (int i = m_size; i > index; i--) {
    array[i] = array[i - 1];
  }

  //once shifted, insert new value
  array[index] = value;
  m_size++;

}


//checks whther a value exists in the array using linear search, index is returned if found
//otherwise it returns -1
template<class Type>
int Array<Type>::search(Type value) {

  for (size_t i = 0; i < m_size; i++) {

    if (array[i] == value) {
      return i;
    }

  }

  return -1;

}


//doubles the size of array whenever capacity is reached
template<class Type>
void Array<Type>::reallocate() {

  m_capacity *= 2;

  //create a new array with double the size
  std::unique_ptr<Type[]> new_array(std::make_unique<Type[]>(m_capacity));

  for (int i = 0; i < m_size; i++) {
    new_array[i] = array[i];
  }

  //swap old array with new array, when function exits,
  //the old array will be in the temporary unique ptr, so memory will be freed then
  array.swap(new_array);

}



template<class Type>
void Array<Type>::push_back(Type value) {

  try {

    //check if array is full
    if (m_size == m_capacity) {
      reallocate();
    }
    //then add value to end of array
    array[m_size] = value;
    m_size++;


  } catch (...) {
    throw std::runtime_error("Error with push_back");
  }



}



template<class Type>
void Array<Type>::remove(size_t index) {

  //check the bounds
  if (index > m_capacity - 1) {
    throw std::out_of_range("out of range");
  }

  //shift over the values starting at the index being removed
  for (size_t i = index; i < m_size; i++) {

    array[i] = array[i + 1];

  }

  m_size--;

}



template<class Type>
std::pair<Type, Type> Array<Type>::modify(size_t index, Type value) {

  //check bounds
  if (index > m_capacity - 1) {
    throw std::out_of_range("Out of range");
  }

  //store old value before reassigning
  Type old_val = array[index];
  array[index] = value;

  // store both new value then old value
  return std::pair<Type, Type> {value, old_val};
}

template<class Type>
void Array<Type>::print() {

  for (int i = 0; i < this->size(); i++) {

    if (i % 10 == 0 && i != 0) {
      std::cout << "\n";
    }

    std::cout << this->get(i) << " ";

  }
}


