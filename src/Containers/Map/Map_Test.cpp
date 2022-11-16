#include <iostream>
#include <map>
#include "Map_Test.h"

// map 总结

// 使用 map 容器存储的各个键值对，键的值既不能重复也不能被修改。
// 换句话说，map 容器中存储的各个键值对不仅键的值独一无二，键的类型也会用 const 修饰，
// 这意味着只要键值对被存储到 map 容器中，其键的值将不能再做任何修改。

// 各个键值对的键和值可以是任意数据类型，包括 C++ 基本数据类型（int、double 等）、使用结构体或类自定义的类型。

// 向map容器中增添元素，insert()效率更高; 更新map容器中的键值对，operator[]效率更高
// map 容器的 emplace() 和 emplace_hint() 的基本用法时，还遗留了一个问题，即为什么 emplace() 和 emplace_hint() 的执行效率会比 insert() 高？
// 原因很简单，它们向 map 容器插入键值对时，底层的实现方式不同：
//      使用 insert() 向 map 容器中插入键值对的过程是，先创建该键值对，然后再将该键值对复制或者移动到 map 容器中的指定位置；
//      使用 emplace() 或 emplace_hint() 插入键值对的过程是，直接在 map 容器中的指定位置构造该键值对。
//      因此，在实现向 map 容器中插入键值对时，应优先考虑使用 emplace() 或者 emplace_hint()。

void Map_Test::test(){
    printf("=== Map_Test::test() === \n");

    //! 各个键值对的键和值可以是任意数据类型，包括 C++ 基本数据类型（int、double 等）、使用结构体或类自定义的类型。
    std::map<double, double> map1;
    map1[33.2] = 335;

    std::map<std::string, double> map2{{"语文", 28.38}, {"数学", 38.8}, {"英语", 78.3}};
    std::map<std::string, double> map3{std::make_pair("语文", 83.51), std::make_pair("数学", 88.35)};

    std::map<std::string, double> map4(map3);

    std::map<std::string, int> map5(std::map<std::string, int>{{"数学", 88}, {"语文", 883}});

    std::map<std::string, int> map6{{"C语言教程",10},{"STL教程",20}};
    // 与下面的式子等价
    std::map<std::string, int, std::less<std::string>> map7{{"C语言教程",10},{"STL教程",20}};
    for(std::map<std::string, int>::iterator it = map7.begin(); it != map7.end(); it++){
        std::cout << it->first << " " << it->second << std::endl;
    }

    std::map<std::string, int, std::greater<std::string>> map8{{"C语言教程",10},{"STL教程",20}};
    for(std::map<std::string, int>::iterator it = map8.begin(); it != map8.end(); it++){
        std::cout << it->first << " " << it->second << std::endl;
    }

    for(std::map<std::string, int>::const_reverse_iterator it = map8.crbegin(); it != map8.crend(); it++){
        std::cout << it->first << " " << it->second << std::endl;
    }

    std::cout << "#####################################" << std::endl;

    std::map<std::string, double> map9{{"语文", 98.39},
                                    {"数学", 100},
                                    {"英语", 30.4},
                                    {"物理", 89.3},
                                    {"化学", 99.38}};
    
    for(auto it = map9.begin(); it != map9.end(); it++){
        std::cout << it->first << ": " << it->second << std::endl;
    }

    std::cout << "=== lower_bound === " << std::endl;
    auto it1 = map9.lower_bound("数学");
    while(it1 != map9.end()){
        std::cout << it1->first << " " << it1->second << std::endl;
        it1++;
    }

    std::cout << "=== upper_bound ===" << std::endl;
    auto it2 = map9.upper_bound("数学");
    while(it2 != map9.end()){
        std::cout << it2->first << " " << it2->second << std::endl;
        it2++;
    }

    std::cout << "=== equal_range ===" << std::endl;
    auto it_pair = map9.equal_range("数学");
    for(auto it = it_pair.first; it != it_pair.second; it++){
        std::cout << it->first << " " << it->second << std::endl;
    }

    std::cout << "map获取键对应值的几种方法" << std::endl;
    // []



    std::cout << "end." << std::endl;
}