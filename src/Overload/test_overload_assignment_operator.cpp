#include <iostream>
#include "Overload/Overload.h"

void Overload::test_overload_assignment_operator(){
    printf("=== test_overload_assignment_operator ===\n");

    Overload::MyString str1("Hello");
    Overload::MyString str2("World");

    str1.display();
    str2.display();

    str1 = str2;

    str1.display();
    str2.display();

}