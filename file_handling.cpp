

#include "file_handling.h"
#include <iostream>
#include <stdexcept>
#include <sstream>

template class Array<int>;

File::File(const std::string &filename) {

  m_file.open(filename); //open file then check if its open

  if (!m_file.is_open()) {
    throw std::runtime_error("File unable to open");
  }

}

File::~File() {

  m_file.close();

}

Array<int> File::read_data() {

  Array<int> arr;

  //getline reads entire line into buffer
  std::string buffer;
  while (getline(m_file, buffer)) {

    //parse indiviual numbers using string stream
    std::stringstream ss(buffer);

    std::string buffer2;
    while (getline(ss, buffer2, ' ')) {
      //add indiviual numbers to array
      arr.push_back(stoi(buffer2));
    }

    buffer.clear();

  }

  return arr;

}