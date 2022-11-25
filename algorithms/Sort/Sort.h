#pragma once 

#include <vector>

namespace algorithms{

class Sort{

public:
    //! Benchmark
    static void Benchmark();

    //! 冒泡排序 稳定排序 O(n^2)
    static void Test_BubbleSort(std::vector<int>& vec);

    //! 插入排序 稳定排序 O(n^2)
    static void Test_InsertSort(std::vector<int>& vec);

    //! 选择排序 不稳定排序 O(n^2)
    static void Test_SelectSort(std::vector<int>& vec);

    //! 快速排序 不稳定排序 O(nlogn)
    static void Test_QuickSort(std::vector<int>& vec);

};

}