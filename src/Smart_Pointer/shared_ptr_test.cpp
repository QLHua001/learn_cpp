#include <iostream>
#include <memory>
#include "Smart_Pointer.h"

//!
/*
成员方法名	                    功 能
operator=()	        重载赋值号，使得同一类型的 shared_ptr 智能指针可以相互赋值。
operator*()	        重载 * 号，获取当前 shared_ptr 智能指针对象指向的数据。
operator->()	    重载 -> 号，当智能指针指向的数据类型为自定义的结构体时，通过 -> 运算符可以获取其内部的指定成员。
swap()	            交 换 2 个相同类型 shared_ptr 智能指针的内容。
reset()	            当函数没有实参时，该函数会使当前 shared_ptr 所指堆内存的引用计数减 1，同时将当前对象重置为一个空指针；当为函数传递一个新申请的堆内存时，则调用该函数的 shared_ptr 对象会获得该存储空间的所有权，并且引用计数的初始值为 1。
get()	            获得 shared_ptr 对象内部包含的普通指针。
use_count()	        返回同当前 shared_ptr 对象（包括它）指向相同的所有 shared_ptr 对象的数量。
unique()	        判断当前 shared_ptr 对象指向的堆内存，是否不再有其它 shared_ptr 对象再指向它。
operator bool()	    判断当前 shared_ptr 对象是否为空智能指针，如果是空指针，返回 false；反之，返回 true。
*/
//!

void Smart_Pointer::shared_ptr_test(){
    printf("=== shared_ptr_test ===\n");

    // 初始化
    std::shared_ptr<int> p1(new int(10));
    std::cout << "p1: " << *p1 << std::endl;

    //! 移动构造函数，move将p1从左值转换成右值，赋值给p2之后，不再指向该堆内存
    // std::shared_ptr<int> p2(std::move(p1));
    std::shared_ptr<int> p2 = std::move(p1);
    *p2 = 100;
    // std::cout << "p1: " << *p1 << std::endl; //! 程序错误
    std::cout << "p2: " << *p2 << std::endl;

    //! 拷贝构造函数
    std::shared_ptr<int> p3(p2);
    std::cout << "p2: " << *p2 << std::endl;
    std::cout << "p3: " << *p3 << std::endl;

    std::cout << "################## TEST1 自定义类智能指针 Start #######################" << std::endl;

    std::shared_ptr<DemoCls> pD1;
    pD1 = std::make_shared<DemoCls>(1, 2, "A");

    std::cout << ">>> !!! 重新赋值1" << std::endl;
    pD1 = std::make_shared<DemoCls>(3, 4, "B");

    std::cout << ">>> !!! 重新赋值2" << std::endl;
    pD1 = std::make_shared<DemoCls>(DemoCls(5, 6, "C"));

    std::cout << ">>> !!! 重新赋值3" << std::endl;
    DemoCls DC1(7, 8, "D");
    pD1 = std::make_shared<DemoCls>(DC1);

    std::cout << "################## TEST1 自定义类智能指针 End #######################" << std::endl;

    std::cout << std::endl << std::endl;
    std::cout << "################## TEST2 Start #######################" << std::endl;

    std::cout << "//! 注意，同一普通指针不能同时为多个 shared_ptr 对象赋值，否则会导致程序发生异常。"<< std::endl;
    int* ptr = new int;
    std::shared_ptr<int> p4(ptr);
    // std::shared_ptr<int> p5(ptr);//错误
    // delete ptr; //! 赋值给智能指针之后，不能释放。

    std::cout << "################## TEST2 End #######################" << std::endl;

    std::cout << std::endl << std::endl;
    std::cout << "################## TEST3 自定义释放规则 Start #######################" << std::endl;

    std::cout << " //! 在某些场景中, 自定义释放规则是很有必要的。比如, 对于申请的动态数组来说, shared_ptr 指针默认的释放规则是不支持释放数组的, 只能自定义对应的释放规则, 才能正确地释放申请的堆内存." << std::endl;
    std::shared_ptr<int> p6(new int[10], [](int* p){delete[] p;});
    
    std::cout << "################## TEST3 自定义释放规则 End #######################" << std::endl;


    std::cout << std::endl << std::endl;
    std::cout << "################## TEST4 Start #######################" << std::endl;
    std::cout << "################## TEST4 End #######################" << std::endl;
}