#include <iostream>
#include "Const.h"

void Const::Const_Test(){

    printf("=== Const_Test ===\n");

    //! const对象必须初始化
    const int bufSize = 512; 

    int len1 = 192;
    const int& len2 = len1;

    len1 = 256;

    //! 总结 修饰指针本身的const称为顶层const，修饰指针所指向变量的const成为底层const。底层const与顶层const是两个互相独立的修饰符，互不影响。
    //! const 与 指针
    int i = 100;
    int j = 200;
    int* p1 = &i;
    const int* p2 = &i; //! 指针p2指向i变量，const修饰的是p2指向的变量，即不能通过指针p2修改i变量的值
    // (*p2) = 200; // error
    p2 = &j; //! 但p2可以指向其他变量

    int* const p3 = &i; //! 指针p3指向i变量，const修饰的是p3指针本身，即可以通过指针p3修改i变量的值
    (*p3) = 102; // ok
    // p3 = &j; //! p3不可以指向其他变量

    const int* const p4 = &i; //! 指针p4指向i变量，既不能通过指针p4修改i变量的值，也不能修改p4的指向
    // (*p4) = 103;
    // p4 = &j;


    //! const 与 引用
    int x = 123;
    int& y1 = x;

    y1 = 124;

    const int& y2 = x;
    // y2 = 125; //! 不允许使用 y2 修改 x 的值

    //! 总结
    //! 可以将底层const的指针（或引用）指向（或绑定）到非const对象，
    //! 但不允许非底层const的指针（或引用）指向（或绑定）到const对象。 （即：const对象不允许通过任何方式（指针/引用）被修改。）
    int w1 = 500;
    const int w2 = 600;
    
    const int* v1 = &w1;
    // int* v2 = &w2;//! error 不允许 非底层const 指向 const对象

    int& u1 = w1;
    // int& u2 = w2; //! error 不允许 非const对象 指向 const对象
    const int& u2 = w2;



    //! const 与 函数
    //! 1. 值传递的const形参  :    void fcn(const int i) { /* ... */ }
    //! 2. const指针/引用的形参  : 
    //!        void fcn2(const int &x) { /* ... */ } // 接受const或非const的int引用，但是不允许通过x修改传入的对象
    //!        void fcn2(const int *y) { /* ... */ } // 接受const或非const的int指针，但是不允许通过y修改传入的对象
    //! 当函数不修改参数值时，尽可能将形式参数定义为（底层）const参数，
    //! 因为（底层）const参数可以接受常量与非常量对象，但非（底层）const参数只能接受非常量对象。
    

    //! const 与 类
    //! 当函数不修改成员变量时，尽可能的将函数声明为const函数，因为const函数可以被非const对象和const对象调用，而非const函数只能被非const对象调用。
    //! const函数并不意味着数据安全，虽然不能通过const函数修改成员变量，但是这样的const仅为顶层const，若成员变量包含非底层const的指针/引用，
    //! 则依然可以通过这些指针/引用修改其指向/绑定的对象。

}
#include <array>
//! const 与 constexprt
//! 总的来说在 C++ 11 标准中，const 用于为修饰的变量添加“只读”属性；
//! 而 constexpr 关键字则用于指明其后是一个常量（或者常量表达式），编译器在编译程序时可以顺带将其结果计算出来，而无需等到程序运行阶段，
//! 这样的优化极大地提高了程序的执行效率。

//! C++ 11标准中，为了解决 const 关键字的双重语义问题，保留了 const 表示“只读”的语义，而将“常量”的语义划分给了新添加的 constexpr 关键字。
//! 因此 C++11 标准中，建议将 const 和 constexpr 的功能区分开，即凡是表达“只读”语义的场景都使用 const，表达“常量”语义的场景都使用 constexpr。
//! const 与 constexprt

// static void dis_1(const int x){
//     //错误，x是只读的变量
//     std::array <int,x> myarr{1,2,3,4,5};
//     std::cout << myarr[1] << std::endl;
// }

static void dis_2(){
    constexpr int x = 5;
    std::array <int,x> myarr{1,2,3,4,5};
    std::cout << myarr[1] << std::endl;
}

void Const::Const_Test_2(){

    // dis_1();
    dis_2();

}