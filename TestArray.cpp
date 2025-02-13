//
// Created by jeremiah tesfaye on 2/13/25.
//

#include "TestArray.h"


void TestArray::test_search(const int value) const {

    out << "\n\n-----------------------------------------------------\n";
    out << "\n search() test, searching for value: " << value << "\n";

    if (const int index = arr.search(value) > 0) {

        out << "\nFound " << value << " at index: " << index << "\n";

    } else {

        out << "\nDid not find " << value << "\n";

    }
}

void TestArray::test_insert(size_t index, int value) {

    out << "\n\n-----------------------------------------------------\n";
    out << "\nInsert() test for value: " << value << " at index: " << index << "\n";

    int value_before_shift = arr.get(index);
    arr.insert(index, value);

    out << "\nNew Size: " << arr.size() << "\n";

    if (int val = arr.get(index) == value) {
        out << "\nValue: " << value << " was inserted successfully at index: " << index << "\n";
    } else {
        out << "\nValue did not insert correctly\n";
    }

    if (index == arr.size()) {
        out << "\nValue inserted at end so no need to check shifting\n";
        return;
    }

    if (int val = arr.get(index + 1) == value_before_shift) {
        out << "\nArray was shifted correctly\n";
    } else {
        out << "\nArray did not shift correctly\n";
    }


}

void TestArray::test_remove(size_t index) {

    out << "\n\n-----------------------------------------------------\n";
    out << "\nTest for Remove() on index: " << index << "\n";

    const int val = arr.get(index + 1);

    arr.remove(index);

    if (arr.get(index) == val) {
        out << "Value at index was removed and shifted correctly\n";
    } else {
        out << "Value did not shift correctly\n";
    }


}

void TestArray::test_modify(size_t index, int value) {

    out << "\n\n-----------------------------------------------------\n";
    out << "\nTest for modify() on index: " << index << " using value: " << value << "\n";

    int old_val = arr.get(index);

    std::pair<int, int> values;

    values = arr.modify(index, value);

    if (values.first == value) {
        out << "New value returned correctly\n";
    } else {
        out << "New value did not return correctly\n";
    }

    if (values.second == old_val) {
        out << "Old value returned correctly\n";
    } else {
        out << "Old value returned incorrectly\n";
    }


}

void TestArray::print_result(int val) {

    out << "\n-------------------------------------------------\n";
    out << "\nRESULT: \n";
    if (val == 0) {

        out << "Array passed tests\n";

    } else {

        out << "test failed\n";

    }
}


int TestArray::start_test() {

    try {

        test_search(55);
        test_search(100);
        test_search(200);

        test_insert(5, 400);
        test_insert(6, 500);
        test_insert(40, 1000);
        test_insert(100, 222);

        out << "New size: " << arr.size();

        test_remove(5);
        test_remove(5);
        test_remove(38);
        test_remove(97);

        out << "New size: " << arr.size();

        test_modify(0, 10);
        test_modify(10, 100);
        test_modify(99, 232);

        out << "New size: " << arr.size();

        test_modify(0 , 1);
        test_modify(10, 11);
        test_modify(99, 100);

        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i) != original_array.get(i)) {
                return -1;
            }
        }

        return 0;

    } catch (std::out_of_range &e) {

        std::cout << e.what();
        return -1;
    }
}
