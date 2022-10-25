#include <iostream>
#include <algorithm>
#include "Lambda.h"

int test1(){

    int num[4] = {4, 2, 3, 1};
    //对 a 数组中的元素进行排序
    std::sort(num, num+4, [](int x, int y) -> bool{ return x < y; } );
    for(int n : num){
        std::cout << n << " ";
    }
    return 0;

}

int all_num = 13;

//! 值传递和引用传递
int test2(){

    //局部变量
    int num_1 = 1;
    int num_2 = 2;
    int num_3 = 3;
    std::cout << "lambda1:\n";
    //! lambda1 匿名函数是以 [=] 值传递的方式导入的局部变量，这意味着默认情况下，此函数内部无法修改这 3 个局部变量的值，但全局变量 all_num 除外
    auto lambda1 = [=]{
        //全局变量可以访问甚至修改
        all_num = 10;

        // num_1 = 1234; //! 编译错误
        //函数体内只能使用外部变量，而无法对它们进行修改
        std::cout << num_1 << " "
             << num_2 << " "
             << num_3 << std::endl;
    };
    lambda1();
    std::cout << all_num <<std::endl;
    std::cout << "lambda2:\n";
    auto lambda2 = [&]{
        all_num = 100;
        num_1 = 10;
        num_2 = 20;
        num_3 = 30;
        std::cout << num_1 << " "
             << num_2 << " "
             << num_3 << std::endl;
    };
    lambda2();
    std::cout << all_num << std::endl;
    std::cout << num_1 << " "
             << num_2 << " "
             << num_3 << std::endl; 

    std::cout << "lambda3:\n";
    auto lambda3 = [=]()mutable{
        //全局变量可以访问甚至修改
        all_num = 222;

        num_1 = 1234; //! 加上mutable,就可以在 lambda1 匿名函数中修改外部变量的值。但需要注意的是，这里修改的仅是 num_1、num_2、num_3 拷贝的那一份的值，真正外部变量的值并不会发生改变。
        std::cout << num_1 << " "
             << num_2 << " "
             << num_3 << std::endl;
    };
    lambda3();
    std::cout << all_num <<std::endl;
    std::cout << num_1 << " "
             << num_2 << " "
             << num_3 << std::endl;

    std::cout << "lambda4:\n";
    auto lambda4 = []{
        //全局变量可以访问甚至修改
        all_num = 333;
    };
    lambda4();
    std::cout << all_num <<std::endl;
    std::cout << num_1 << " "
             << num_2 << " "
             << num_3 << std::endl;

    return 0;
}

//! lambda 匿名函数
void Lambda::lambda_test(){

    printf("=== lambda_test ===\n");

    // test1();

    //! 值传递和引用传递
    test2();

}