#include "Smart_Pointer.h"
#include <iostream>
#include <memory>


void Smart_Pointer::unique_ptr_test(){

    printf("=== unique_ptr_test ===\n");

    // std::cout << std::endl << std::endl;
    std::cout << "################## TEST1 初始化 Start #######################" << std::endl;

    std::unique_ptr<int> p1; //! 创建一个空的 unique_ptr 对象
    if(p1 == nullptr){
        std::cout << " This is a null ptr." << std::endl;
    }

    // std::unique_ptr<int> p2 = std::make_unique<int>(10); //! C++14引入

    std::unique_ptr<int> p3(new int(10));
    std::cout << "*p3: " << *p3 << std::endl;

    std::cout << "################## TEST1 初始化 End #######################" << std::endl;


    std::cout << std::endl << std::endl;
    std::cout << "################## TEST2 自定义类 Start #######################" << std::endl;

    std::unique_ptr<DemoCls> pDC1(new DemoCls(1, 2, "A"));

    //! 使用get()·函数获取管理对象的指针。
    DemoCls* pt1 = pDC1.get();

    //! unique_ptr 对象不可复制， 只可转移其所有权
    // std::unique_ptr<DemoCls> pDC2(pDC1); //! 编译错误
    
    // std::unique_ptr<DemoCls> pDC3 = std::move(pDC1);
    std::unique_ptr<DemoCls> pDC3(std::move(pDC1));
    if(pDC3 == nullptr){
        std::cout << "pDC3 is nullptr" << std::endl;
    }

    if(pDC1 == nullptr){
        std::cout << "pDC1 is nullptr" << std::endl;
    }

    //! 重置 unique_ptr 对象
    //! 该函数将重置它，即它将释放delete关联的原始指针并使unique_ptr 对象为空。
    pDC3.reset();
    

    std::cout << "################## TEST2 自定义类 End #######################" << std::endl;

    std::cout << std::endl << std::endl;
    std::cout << "################## TEST3 Start #######################" << std::endl;

    DemoCls* p4 = new DemoCls(3, 4, "B");
    std::unique_ptr<DemoCls> pDC4(p4);
    // delete p4; //! 赋值给unique_ptr之后，不应该自行释放堆内存，否则有可能程序崩溃。

    std::cout << "################## TEST3 End #######################" << std::endl;

    std::cout << std::endl << std::endl;
    std::cout << "################## TEST4 Start #######################" << std::endl;

    std::unique_ptr<DemoCls> pDC5(new DemoCls(5, 6, "C"));
    //! 调用 release()将释放其关联的原始指针的所有权，并返回原始指针。这里是释放所有权，并没有delete原始指针，reset()会delete原始指针。
    DemoCls* p5 = pDC5.release();

    delete p5;

    std::cout << "################## TEST4 End #######################" << std::endl;


    std::cout << std::endl << std::endl;
    std::cout << "################## TEST5 Start #######################" << std::endl;

    //! std::unique_ptr<DemoCls> p6(new DemoCls[3], [](DemoCls* p){delete[] p;}); //! Error 编译错误

    std::cout << "################## TEST5 End #######################" << std::endl;

}