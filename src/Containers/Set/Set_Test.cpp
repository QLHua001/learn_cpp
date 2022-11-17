#include <iostream>
#include <set>
#include <vector>
#include "Set_Test.h"

// set 总结
// set里面的元素是唯一的

// set容器可用于去重操作(元素唯一性)

void Set_Test::test(){
    printf("=== Set_Test::test() ===\n");

    std::set<int> s1;

    std::set<int> s2{1, 3, 5, 7};

    std::set<int> s3(s2);

    std::vector<int> v1{3, 5, 7, 4, 11, 2, 3};
    std::set<int> s4(v1.begin(), v1.end());

    std::cout << "end." << std::endl;
}