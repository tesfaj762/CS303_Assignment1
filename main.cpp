
#include <string>
#include <iostream>
#include "file_handling.h"
#include "Array.h"
#include "TestArray.h"

int main() {
  const std::string input_file {"input.txt"};

  File file(input_file);

  Array<int> data_array = file.read_data();

  std::cout << "\nArray after reading input file\n";

  data_array.print();

  std::cout << "\n";

  TestArray test(data_array);
  test.print_result(test.start_test());

  return 0;

}








