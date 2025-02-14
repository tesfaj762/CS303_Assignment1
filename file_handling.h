#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include <string>
#include <fstream>
#include "Array.h"

class File {
public:
  //constructor opens the file for reading
  explicit File(const std::string &filename);

  //closes the file at end of scope
  ~File();

  //reads the data from the input file
  Array<int> read_data();

private:

  std::fstream m_file;

};

#endif