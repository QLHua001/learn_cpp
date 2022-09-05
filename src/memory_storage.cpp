#include <iostream>
#include "TestClass.h"

// 全局变量
// 初始化
int g_a = 111;
// 未初始化
int g_b;

// 全局常量
const int c_g_a = 222;
// 静态全局变量 static表示在本文件可见
static int s_g_a = 333;
// 静态全局常量 static表示在本文件可见
static const int sc_g_a = 444;

void memory_storage(){

    printf("全局变量 g_a 的地址: %p, 值为: %d\n", &g_a, g_a);
    printf("全局变量 g_b 的地址: %p, 值为: %d\n", &g_b, g_b);

    printf("全局常量 c_g_a 的地址: %p, 值为: %d\n", &c_g_a, c_g_a);

    printf("静态全局变量 s_g_a 的地址: %p, 值为: %d\n", &s_g_a, s_g_a);
    printf("静态全局常量 sc_g_a 的地址: %p, 值为: %d\n", &sc_g_a, sc_g_a);

    // 局部变量
    int a = 555;
    int b = 666;

    // 局部常量 //? 栈区??
    const int c = 777;
    printf("局部常量 c 的地址: %p, 值为: %d\n", &c, c);

    TestClass testclass;
    // TestClass::s_a = 34825;
    std::cout << testclass.s_a << std::endl;

}