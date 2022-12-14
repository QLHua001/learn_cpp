#include "Reference.h"
#include <iostream>

//! 总结 C++ 引用
/*
    引用，能减少数据的拷贝，提高数据传递的效率。
    引用可以看做是数据的一个别名，通过这个别名和原来的名字都能够找到这份数据。

    引用必须在定义的同时初始化，并且以后也要从一而终，不能再引用其它数据，这有点类似于常量（const 变量）。
*/
//! 引用作为函数参数
//  在定义或声明函数时，我们可以将函数的形参指定为引用的形式，这样在调用函数时就会将实参和形参绑定在一起，让它们都指代同一份数据。
//  如此一来，如果在函数体中修改了形参的数据，那么实参的数据也会被修改，从而拥有“在函数内部影响函数外部数据”的效果。

//! 引用作为函数返回值
//  在将引用作为函数返回值时应该注意一个小问题，就是不能返回局部数据（例如局部变量、局部对象、局部数组等）的引用，因为当函数调用完成后局部数据就会被销毁。

//! 引用变量也是占用独立的内存的
//  其实引用只是对指针进行了简单的封装，它的底层依然是通过指针实现的，引用占用的内存和指针占用的内存长度一样，
//  在 32 位环境下是 4 个字节，在 64 位环境下是 8 个字节

//! 引用和指针的其他区别
//  1. 引用必须在定义时初始化，并且以后也要从一而终，不能再指向其他数据；而指针没有这个限制，指针在定义时不必赋值，以后也能指向任意数据。
//  2. 指针和引用的自增（++）自减（--）运算意义不一样。
//      对指针使用 ++ 表示指向下一份数据，对引用使用 ++ 表示它所指代的数据本身加 1；自减（--）也是类似的道理。

//! 总结 C++ 引用
void Reference::Reference_Test(){
    printf("=== Reference_Test ===\n");

    int a = 100;
    int& v = a;
    
}