#include <iostream>
#include <forward_list>
#include <deque>
#include "Forward_List_Test.h"

// forward_list 总结
// 由于单链表没有双向链表那样灵活，因此相比 list 容器，forward_list 容器的功能受到了很多限制。
// 比如，由于单链表只能从前向后遍历，而不支持反向遍历，因此 forward_list 容器只提供前向迭代器，而不是双向迭代器。
// 这意味着，forward_list 容器不具有 rbegin()、rend() 之类的成员函数。

// 效率高是选用 forward_list 而弃用 list 容器最主要的原因，
// 换句话说，只要是 list 容器和 forward_list 容器都能实现的操作，应优先选择 forward_list 容器。

void Forward_List_Test::test(){
    printf("=== Forward_List_Test::test() ===\n");

    std::deque<int> d1{2, 3, 4, 5};
    std::forward_list<int> fl1(d1.begin(), d1.end());

    std::cout << "end." << std::endl;
}