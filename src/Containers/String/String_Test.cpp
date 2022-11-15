#include <iostream>
#include <string>
#include "String_Test.h"

void String_Test::test(){
    printf("=== String_Test::test() ===\n");

    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::cout << s1 << " " << s2 << std::endl;

}