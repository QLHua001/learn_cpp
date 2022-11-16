#include <iostream>
#include <list> //! 双向链表
#include <vector>
#include "List_Test.h"

// list 总结
// list 容器，又称双向链表容器，即该容器的底层是以双向链表的形式实现的。
// 这意味着，list 容器中的元素可以分散存储在内存空间里，而不是必须存储在一整块连续的内存空间中。

// list 容器中各个元素的前后顺序是靠指针来维系的，每个元素都配备了 2 个指针，分别指向它的前一个元素和后一个元素。
// 其中第一个元素的前向指针总为 null，因为它前面没有元素；同样，尾部元素的后向指针也总为 null。

// 基于这样的存储结构，list 容器具有一些其它容器（array、vector 和 deque）所不具备的优势，
// 即它可以在序列已知的任何位置快速插入或删除元素（时间复杂度为O(1)）。并且在 list 容器中移动元素，也比其它容器的效率高。

// 使用 list 容器的缺点是，它不能像 array 和 vector 那样，通过位置直接访问元素。举个例子，如果要访问 list 容器中的第 6 个元素，它不支持容器对象名[6]这种语法格式，
// 正确的做法是从容器中第一个元素或最后一个元素开始遍历容器，直到找到该位置。(不支持随机访问)
// (即list 容器迭代器最大的不同在于，其配备的迭代器类型为双向迭代器，而不再是随机访问迭代器。)

// 使用场景：实际场景中，如何需要对序列进行大量添加或删除元素的操作，而直接访问元素的需求却很少，这种情况建议使用 list 容器存储序列。

// remove(val)	    删除容器中所有等于 val 的元素。
// remove_if()	    删除容器中满足条件的元素。
// unique()	        删除容器中相邻的重复元素，只保留一个。
// merge()	        合并两个事先已排好序的 list 容器，并且合并之后的 list 容器依然是有序的。
// sort()	        通过更改容器中元素的位置，将它们进行排序。
// reverse()	    反转容器中元素的顺序。

// 学习过程中，读者是否想过一个问题，即这些容器的模板类中都提供了 empty() 成员方法和 size() 成员方法，它们都可以用来判断容器是否为空。
// 那么，在实际场景中，到底应该使用哪一种呢？
// 建议使用 empty() 成员方法。理由很简单，无论是哪种容器，只要其模板类中提供了 empty() 成员方法，使用此方法都可以保证在 O(1) 时间复杂度内完成对“容器是否为空”的判断；
// 但对于 list 容器来说，使用 size() 成员方法判断“容器是否为空”，可能要消耗 O(n) 的时间复杂度。
void List_Test::test(){
    printf("=== List_Test::test() ===\n");

    std::list<int> l1;

    std::list<int> l2(10, 1);
    std::list<int> l3(l2);

    std::vector<int> v1{1,2,3};
    std::list<int> l4(v1.begin(), v1.end());

    //! it 为双向迭代器， 不是随机迭代器
    for(auto it = l4.begin(); it != l4.end(); it++){
        std::cout << *it << std::endl;
    }

    std::list<int> l5{3,5,1,11,2,42,53,33,45};
    std::list<int> l6(l5);
    l6.reverse();
    
    std::list<int> l7(l5);
    l7.sort();

    std::list<int> l8{3,42,121,985};
    l7.merge(l8);
    std::cout << "l8.size(): " << l8.size() << std::endl;

    l7.unique();

    std::list<int> l9{1, 2, 3, 3, 4, 5, 6, 6, 7, 3};
    //! 删除容器中相邻的重复元素，只保留一个, 注意是 相邻的重复元素
    l9.unique();


    std::list<char> l10{'h','t','t','p',':','/','/','c','.','b','i','a','n','c','h','e','n','g','.','n','e','t'};
    for(std::list<char>::iterator it = l10.begin(); it != l10.end(); it++){
        std::cout << *it;
    }
    std::cout << std::endl;

    for(std::list<char>::reverse_iterator it = l10.rbegin(); it != l10.rend(); it++){
        std::cout << *it;
    }
    std::cout << std::endl;

    for(std::list<char>::const_iterator it = l10.cbegin(); it != l10.cend(); it++){
        std::cout << *it;
    }
    std::cout << std::endl;

    for(std::list<char>::const_reverse_iterator it = l10.crbegin(); it != l10.crend(); it++){
        std::cout << *it;
    }
    std::cout << std::endl;

    const std::list<int> l11{6,7,8,9};
    std::list<int>::const_iterator it1 = l11.begin();
    std::list<int>::const_iterator it2 = l11.end();
    while(it1 != it2){
        std::cout << *it1 << " ";
        it1++;
    }
    std::cout << std::endl;

    std::list<int> l12(l11);
    l12.insert(l12.end(), {10, 11});
    std::list<int> l13{100, 101, 102};
    l12.splice(l12.begin(), l13);

    std::list<int> l14{ 15, 36, 7, 17, 20, 39, 4, 1 };
    l14.remove_if([](int val){return val < 10;});

    std::cout << "end." << std::endl;

}