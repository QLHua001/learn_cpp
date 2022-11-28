#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "Sort.h"

namespace algorithms{

void Sort::Benchmark(){
    std::srand((unsigned)std::time(NULL));
    auto stime = std::chrono::steady_clock::now();
    auto etime = std::chrono::steady_clock::now();

    std::vector<int> v1(10000);
    for(auto& val : v1) val = std::rand();
    // for(auto& val : v1) std::cout << val << "\t";
    // std::cout << std::endl;
    std::vector<int> t1;

    t1 = v1;
    stime = std::chrono::steady_clock::now();
    Test_QuickSort(t1);
    etime = std::chrono::steady_clock::now();
    std::cout << "Test_QuickSort time: " << std::chrono::duration_cast<std::chrono::milliseconds>(etime-stime).count() << " ms" << std::endl;

    t1 = v1;
    stime = std::chrono::steady_clock::now();
    Test_BubbleSort(t1);
    etime = std::chrono::steady_clock::now();
    std::cout << "Test_BubbleSort time: " << std::chrono::duration_cast<std::chrono::milliseconds>(etime-stime).count() << " ms" << std::endl;

    t1 = v1;
    stime = std::chrono::steady_clock::now();
    Test_InsertSort(t1);
    etime = std::chrono::steady_clock::now();
    std::cout << "Test_InsertSort time: " << std::chrono::duration_cast<std::chrono::milliseconds>(etime-stime).count() << " ms" << std::endl;

    t1 = v1;
    stime = std::chrono::steady_clock::now();
    Test_SelectSort(t1);
    etime = std::chrono::steady_clock::now();
    std::cout << "Test_SelectSort time: " << std::chrono::duration_cast<std::chrono::milliseconds>(etime-stime).count() << " ms" << std::endl;

    t1 = v1;
    stime = std::chrono::steady_clock::now();
    Test_MergeSort(t1, 0, t1.size()-1);
    etime = std::chrono::steady_clock::now();
    std::cout << "Test_MergeSort time: " << std::chrono::duration_cast<std::chrono::milliseconds>(etime-stime).count() << " ms" << std::endl;

}

}