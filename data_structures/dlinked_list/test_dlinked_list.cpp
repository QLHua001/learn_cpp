#include <iostream>
#include "dlinked_list.h"

namespace data_structures{
namespace dlinked_list{
    
void test_dlinked_list(){
    DList dlist;
    dlist.Display();

    dlist.PushFront(111);
    dlist.Display();

    dlist.Insert(3, 25);
    dlist.Display();

    dlist.Insert(0, 35);
    dlist.Display();

    dlist.PushBack(667);
    dlist.Display();

    dlist.PushFront(888);
    dlist.Display();

    int len = dlist.GetLen();
    std::cout << "len: " << len << std::endl;

    dlist.Insert(3, 666);
    dlist.Display();

    int val;
    dlist.Delete(1, val);
    std::cout << "removed val: " << val << std::endl;
    dlist.Display();

    dlist.PushBack(55);
    dlist.Display();

}

}
}