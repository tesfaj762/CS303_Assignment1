//
// Created by jeremiah tesfaye on 2/13/25.
//

#ifndef TESTARRAY_H
#define TESTARRAY_H

#include <iostream>
#include <fstream>
#include "Array.h"

template class Array<int>;

class TestArray {
public:

    using print = std::ostream&;
    print out = std::clog;

    TestArray(Array<int>& array)
    : arr(array)
    , original_array(array) {

        output_file.open("tests.txt");
        std::clog.rdbuf(output_file.rdbuf());
    }

    int start_test();

    void print_result(int val);


    ~TestArray() {
        output_file.close();
    }


private:

    void test_search(int value) const;
    void test_insert(size_t index, int value);
    void test_remove(size_t index);
    void test_modify(size_t index, int value);

    std::fstream output_file;
    Array<int>& arr;
    Array<int> original_array;

};



#endif //TESTARRAY_H
