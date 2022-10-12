#include <iostream>
#include <thread>
#include <vector>

#include "multi_thread.h"

static void do_some_work(int thread_idx){
    std::cout<<"thread: "<<thread_idx<<std::endl;
}

static int test_create_thread(){

    int thread_nums = 3;

    int count1 = std::thread::hardware_concurrency(); //! 静态成员函数，返回当前计算机最大的硬件并发线程数目。基本上可以视为处理器的核心数目。
    std::cout << "hardware_concurrency count: " << count1 << std::endl;

    std::vector<std::thread> threadList;
    threadList.reserve(thread_nums);

    for (size_t i = 0; i < thread_nums; i++)
    {
        threadList.emplace_back(do_some_work, i);
    }

    std::cout<<"work in main thread"<<std::endl;

    for (size_t i = 0; i < thread_nums; i++)
    {
        threadList[i].join();
    }
    
    std::cout<<"main thread end"<<std::endl;
    

    return 0;
}

int multi_thread::thread_test(){

    std::cout << "hello thread_test." << std::endl;


    test_create_thread();

    return 0;
}