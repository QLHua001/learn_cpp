#include <iostream>
#include "Overload/Overload.h"

void Overload::test_overload_bracket_operator(){

    printf("=== test_overload_bracket_operator ===\n");

    Overload::MyArray arr1(1, 2, 3, 4);

    std::cout << arr1[2] << std::endl;

    arr1[2] = 200;

    std::cout << arr1[2] << std::endl;

}