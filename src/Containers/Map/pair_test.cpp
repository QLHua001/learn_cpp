#include <iostream>
#include <utility> //! pairs
#include <string>
#include "Map_Test.h"

void Map_Test::pair_test(){
    printf("=== Map_Test::pair_test() ===\n");

    //! 生成键值对元素
    // 默认构造函数
    std::pair<std::string, double> pair1;

    // 
    std::pair<std::string, double> pair2("AAA", 3.35);

    // 拷贝构造函数
    std::pair<std::string, double> pair3(pair2);

    // 移动构造函数
    std::pair<std::string, double> pair4(std::make_pair("BBB", 6.8));

    std::pair<std::string, double> pair5(std::string("CCC"), 83.5);

    std::pair<std::string, double> pair6{"DDD", 830.3};
    

    std::cout << "end." << std::endl;
    
}