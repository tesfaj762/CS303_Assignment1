#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include <string>
#include <fstream>
#include "Array.h"

class File {
public:
  explicit File(const std::string &filename);

  ~File();

  Array<int> read_data();

private:

  std::fstream m_file;

};

#endif