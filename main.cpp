#include <iostream>
#include <vector>

#include "learn_cpp.h"
#include "sort.h"

int main(int, char**) {
    std::cout << "Hello, world!\n";

    // // 内存四区
    // for (size_t i = 0; i < 100; i++)
    // {
    //     memory_storage();
    // }

    // const_test();

    std::vector<int> a({3, 5, 1, 22, 13, 34, 45, 33, 22, 101, 100, 99, 13});
    // int b[] = {3, 5, 1, 22, 13, 34, 45, 33, 22, 101, 100, 99, 13};

    // Bubble_Sort(a);

    // Selection_Sort(a);

    // Insertion_Sort(a);

    // Shell_Sort(a);

    // Quick_Sort(a);

    Merge_Sort(a, 0, a.size()-1);

    for (size_t i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << "\t";
    }
    std::cout << std::endl;






}
