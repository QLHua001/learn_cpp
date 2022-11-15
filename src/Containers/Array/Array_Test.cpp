#include <iostream>
#include <array>
#include "Array_Test.h"

//! Array 总结
//! 和其它容器不同，array 容器的大小是固定的，无法动态的扩展或收缩，
//! 这也就意味着，在使用该容器的过程无法借由增加或移除元素而改变其大小，它只允许访问或者替换存储的元素。

//! at() : 返回容器中 n 位置处元素的引用，该函数自动检查 n 是否在有效的范围内，如果不是则抛出 out_of_range 异常。
//! 正是由于 array 容器中包含了 at() 这样的成员函数，使得操作元素时比普通数组更安全。

//! 用 array 容器替换普通数组的好处是，array 模板类中已经封装好了大量实用的方法，在提高开发效率的同时，代码的运行效率也会大幅提高。

void Array_Test::test(){
    printf("=== Array_Test::test() ===\n");

    // int n = 102;
    std::array<int, 10> arr1{}; // 将所有的元素初始化为 0

    int val = 1;
    for(auto it = arr1.rbegin(); it != arr1.rend(); it++){
        *it = val++;
    }

    for(auto it = arr1.begin(); it != arr1.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "end." << std::endl;
}