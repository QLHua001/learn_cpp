#include <iostream>
#include "List_Initialization.h"

//! C++类的初始化列表 总结
/*

1.  初始化类的成员有两种方式，一是使用初始化列表，二是在构造函数体内进行赋值操作。
    使用初始化列表主要是基于性能问题，对于内置类型，如int, float等，使用初始化类表和在构造函数体内初始化差别不是很大，
    但是对于类类型成员变量来说，最好使用初始化列表，为什么呢？由测试可知，使用初始化列表少了一次调用默认构造函数的过程，
    这对于数据密集型的类来说，是非常高效的。

2.  常量成员，因为常量只能初始化不能赋值，所以必须放在初始化列表里面

3.  引用类型，引用必须在定义的时候初始化，并且不能重新赋值，所以也要写在初始化列表里面

4.  没有默认构造函数的类类型，因为使用初始化列表可以不必调用默认构造函数来初始化，而是直接调用拷贝构造函数初始化。
*/
//! C++类的初始化列表 总结

List_Initialization::Foo::Foo(int a) : _x(a), _y(a), _c1(4), _c2(_c1), _d1(0.1), _d2(_d1){
    printf("--> call Foo Construct Func. [Foo(int a)]\n");
    // this->_x = a;
    // this->_y = a;
}

List_Initialization::Foo::Foo(int x, int y) : _x(x), _y(y), _c1(4), _c2(_c1), _d1(0.1), _d2(_d1){
    printf("--> call Foo Construct Func. [Foo(int x, int y)]\n");
    // this->_x = x;
    // this->_y = y;
}

List_Initialization::Foo::Foo(int x, int y, const Bar& bar1) : _x(x), _y(y), _c1(4), _c2(_c1), _d1(0.1), _d2(_d1){
    printf("--> call Foo Construct Func. [Foo(int x, int y, const Bar& bar1)]\n");
    this->_bar1 = bar1;
}

List_Initialization::Foo::Foo(const Foo& other):_c1(4), _c2(_c1), _d1(0.1), _d2(_d1){
    printf("--> Call Foo Copy_Construct Func.\n");
    this->_x = other._x;
    this->_y = other._y;
}

void List_Initialization::Foo::set(double d){
    this->_d2 = d;
}



void List_Initialization::list_initialization_test(){
    printf("=== list_initialization_test ===\n");

    // Foo a(1, 2);

    Bar bar1("Hello", 1.2);

    Foo a1(1, 2, bar1);

    a1.set(0.314);

    // Foo b = {3, 4};
    // Foo c{5, 6};

    // Foo f{2};

    // Foo d(a);
    // Foo d2 = a;

    // Foo e = 2; //! error Foo的拷贝构造函数声明为私有的，该处的初始化方式是隐式调用Foo(int)构造函数生成一个临时的匿名对象，再调用拷贝构造函数完成初始化

    
}