#include <iostream>
#include "list_array.h"

namespace data_structures{
namespace list_array{

void test_list_array(){
    printf("=== test_list_array() ===\n");
    List<12> l1;

    l1.Show();

    l1.Insert(3);
    l1.Insert(35);
    l1.Insert(24);
    l1.Show();

    l1.Sort();
    l1.Show();

    l1.Remove(10);
    l1.Remove(24);
    l1.Show();
}

}
}