
#include <string>
#include <iostream>
#include "file_handling.h"
#include "Array.h"
#include "TestArray.h"

/*
 *Array.h has the interface of the class and Array.tpp has all the implementations
 * file_handling.h/.cpp handles opening and closing the input file and write the data to the array
 * TestArray.h/.cpp was just written to see if the Array class was working as it should.
 */

int main() {

  const std::string input_file {"../input.txt"};

  File file(input_file); //open file

  Array<int> data_array = file.read_data(); //read data and store in array

  std::cout << "\nArray after reading input file\n";

  data_array.print();

  std::cout << "\n";

  TestArray test(data_array);
  test.print_result(test.start_test()); //result was printed in tests.txt which should be in build folder.

  return 0;

}








