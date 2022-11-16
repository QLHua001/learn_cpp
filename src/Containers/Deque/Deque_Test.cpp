#include <iostream>
#include <deque> //! 双端队列
#include <array>
#include "Deque_Test.h"

//! deque 总结
//! 和 vector 不同的是，deque 还擅长在序列头部添加或删除元素，所耗费的时间复杂度也为常数阶O(1)。
//! 并且更重要的一点是， deque 容器中存储元素并不能保证所有元素都存储到连续的内存空间中。
//! 当需要向序列两端频繁的添加或删除元素时，应首选 deque 容器。
//! 当向 deque 容器添加元素时，deque 容器会申请更多的内存空间，同时其包含的所有元素可能会被复制或移动到新的内存地址（原来占用的内存会释放），这会导致之前创建的迭代器失效。
//!
//! 注意，和 vector 容器不同，deque 容器没有提供 data() 成员函数，同时 deque 容器在存储元素时，也无法保证其会将元素存储在连续的内存空间中，
//! 因此尝试使用指针去访问 deque 容器中指定位置处的元素，是非常危险的。
//!
//! 了解了 deque 容器底层存储序列的结构，以及 deque 容器迭代器的内部结构

void Deque_Test::test(){
    printf("=== Deque_Test::test() ===\n");

    // 初始化
    std::array<int, 10> a1{1, 2, 3};
    std::deque<int> d1(a1.begin()+1, a1.end());

    std::deque<int> d2(d1);

    std::deque<int> d3(24, 8);

    std::deque<int> d4;
    d4.push_back(2);
    d4.emplace_back(3);
    d4.push_front(1);
    d4.emplace_front(5);

    for(auto it = d4.begin(); it != d4.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "end." << std::endl;

}

void Deque_Test::emplace_test(){
    std::deque<testDemo> d1;


    std::cout << "###1. push_back" << std::endl;
    d1.push_back(3);
    std::cout << "###2. emplace_back" << std::endl;
    d1.emplace_back(4);

    std::cout << "###3. emplace" << std::endl;
    d1.emplace(d1.begin(), 5);
    std::cout << "###4. insert" << std::endl;
    d1.insert(d1.begin(), 6);

}