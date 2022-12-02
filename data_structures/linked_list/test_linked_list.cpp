#include <iostream>
#include "linked_list.h"

namespace data_structures{
namespace linked_list{
    
void test_linked_list(){
    printf("=== test_linked_list ===\n");
    List list;

    list.PushBack(1);
    list.Display();
    
    list.PushFront(2);
    list.Display();

    list.Insert(4, 3);
    list.Display();

    list.Insert(2, 5);
    list.Display();

    int len = list.GetLen();
    std::cout << "len: " << len << std::endl;

    std::shared_ptr<Link> p;
    list.Search(1, p);
    std::cout << p->val_ << std::endl;

    list.Display();

    list.Reverse();
    list.Display();

    list.PushBack(3);
    list.PushFront(4);
    list.Insert(2, 7);
    list.Display();

    list.Reverse();
    list.Display();

    int val1;
    list.Delete(3, val1);
    list.Display();
    std::cout << "val1: " << val1 << std::endl;
}

} // namespace linked_list
} // namespace data_structures
