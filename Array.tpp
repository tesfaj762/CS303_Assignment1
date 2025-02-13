#pragma once
#include <cstddef>
#include <memory>
#include <utility>
#include <iostream>


template<class Type>
Array<Type>::Array() 
: 
array(std::make_unique<Type[]>(10)),
m_size(0),
m_capacity(10) {}



template<class Type>
Array<Type>::Array(int size) 
:
array(std::make_unique<Type[]>(size)),
m_size(0),
m_capacity(size) {}



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



template<class Type>
Array<Type>& Array<Type>::operator=(Array&& other)  noexcept {

  if (this != &other) {
    array.swap(other.array);
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
  }

  return *this;

}


template<class Type>
Array<Type>::~Array() = default;




template<class Type>
Type Array<Type>::get(size_t index) {

  if (index > m_capacity - 1) {
    throw std::out_of_range("Invalid array access");
  }

  return array[index];

}



template<class Type>
void Array<Type>::insert(size_t index, Type value) {

  if (index > m_size) {
    throw std::out_of_range("index to insert is out of range");
  }

  if (m_size == m_capacity) {
    reallocate();
  }

  for (int i = m_size; i > index; i--) {
    array[i] = array[i - 1];
  }

  array[index] = value;
  m_size++;

}



template<class Type>
int Array<Type>::search(Type value) {

  for (size_t i = 0; i < m_size; i++) {

    if (array[i] == value) {
      return i;
    }

  }

  return -1;

}



template<class Type>
void Array<Type>::reallocate() {

  m_capacity *= 2;

  std::unique_ptr<Type[]> new_array(std::make_unique<Type[]>(m_capacity));

  for (int i = 0; i < m_size; i++) {
    new_array[i] = array[i];
  }

  array.swap(new_array);

}



template<class Type>
void Array<Type>::push_back(Type value) {

  if (m_size == m_capacity) {
    reallocate();
  }

  array[m_size] = value;
  m_size++;

}



template<class Type>
void Array<Type>::remove(size_t index) {

  if (index > m_capacity - 1) {
    throw std::out_of_range("out of range");
  }

  for (size_t i = index; i < m_size; i++) {

    array[i] = array[i + 1];

  }

  m_size--;

}



template<class Type>
std::pair<Type, Type> Array<Type>::modify(size_t index, Type value) {

  if (index > m_capacity - 1) {
    throw std::out_of_range("Out of range");
  }

  Type old_val = array[index];
  array[index] = value;

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


