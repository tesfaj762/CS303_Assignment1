

#include "file_handling.h"
#include <iostream>
#include <stdexcept>
#include <sstream>

template class Array<int>;

File::File(const std::string &filename) {

  m_file.open(filename);

  if (!m_file.is_open()) {
    throw std::runtime_error("File unable to open");
  }

}

File::~File() {

  m_file.close();

}

Array<int> File::read_data() {

  Array<int> arr;

  std::string buffer;
  while (getline(m_file, buffer)) {
    std::stringstream ss(buffer);

    std::string buffer2;
    while (getline(ss, buffer2, ' ')) {
      arr.push_back(stoi(buffer2));
    }

    buffer.clear();

  }

  return arr;

}