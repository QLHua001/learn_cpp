#include <iostream>
#include <vector>
#include <chrono>
#include "Vector_Test.h"
#include <cstring>

//! vector 总结
//! vector 容器是 STL 中最常用的容器之一，它和 array 容器非常类似，都可以看做是对 C++ 普通数组的“升级版”。
//! 不同之处在于，array 实现的是静态数组（容量固定的数组），
//! 而 vector 实现的是一个动态数组，即可以进行元素的插入和删除，在此过程中，vector 会动态调整所占用的内存空间，整个过程无需人工干预。

//! http://c.biancheng.net/view/6846.html
//! remove(), 删除容器中所有和指定元素值相等的元素，并返回指向最后一个元素下一个位置的迭代器。值得一提的是，调用该函数不会改变容器的大小和容量。
//! remove()用于删除容器中指定元素时，常和 erase() 成员函数搭配使用。

//! 如何避免vector容器进行不必要的扩容？
//! 要实现这个目标，可以借助 vector 模板类中提供的 reserve() 成员方法。避免 vector 容器执行不必要的扩容操作的关键在于，在使用 vector 容器初期，就要将其容量设为足够大的值。
//! 换句话说，在 vector 容器刚刚构造出来的那一刻，就应该借助 reserve() 成员方法为其扩充足够大的容量。



// DemoCls
Vector_Test::DemoCls::DemoCls(int id1, int id2, char* name){
    printf("调用构造函数\n");

    _id1 = id1;
    _id2 = id2;

    _name = new char[strlen(name)+1];
    strcpy(_name, name);

}

//! 深拷贝与浅拷贝
Vector_Test::DemoCls::DemoCls(const Vector_Test::DemoCls& other){
    printf("调用拷贝构造函数\n");

    _id1 = other._id1;
    _id2 = other._id2;

    _name = new char[strlen(other._name)+1];
    strcpy(_name, other._name);
}

//! 移动构造函数
Vector_Test::DemoCls::DemoCls(Vector_Test::DemoCls&& other){
    printf("调用移动构造函数\n");
    _id1 = other._id1;
    _id2 = other._id2;

    _name = other._name;
    other._name = nullptr;
}

Vector_Test::DemoCls::~DemoCls(){
    printf("调用析构函数\n");
    if(_name){
        delete[] _name;
    }
    _name = nullptr;
}

void Vector_Test::push_back_emplace_back(){
    printf("=== push_back_emplace_back ===\n");

    std::vector<Vector_Test::DemoCls> vecA;
    std::vector<Vector_Test::DemoCls> vecB;

    vecA.reserve(10);
    vecB.reserve(10);

    char str1[] = "one";
    char str2[] = "two";

    Vector_Test::DemoCls cls1(1, 2, str1);
    Vector_Test::DemoCls cls2(3, 4, str2);


    printf("1. ***********************\n");

    printf("--- push_back \n");
    // vecA.push_back(cls1); //! 如果参数是左值，调用拷贝构造函数
    // vecA.push_back(cls1);
    // vecA.push_back(cls1);
    // vecA.push_back(Vector_Test::DemoCls(1, 2, str2));//! 如果参数是右值，调用移动构造函数
    // vecA.push_back({5, 6, str1}); // //!! 1. 调用构造函数构造临时对象; 2. 如果有移动构造函数，调用移动构造函数，否则调用拷贝构造函数; 3. 调用析构函数析构临时对象。 
    // vecA.push_back(5, 6, str1); // 不能通过编译
    printf("--- emplace_back \n");
    // vecB.emplace_back(cls2);//! 如果参数是左值，调用拷贝构造函数
    // vecB.emplace_back(Vector_Test::DemoCls(4, 5, str2));//! 如果参数是右值，调用移动构造函数
    vecB.emplace_back(4, 5, str2); // ! 直接调用构造函数， 对比push_back, 减少了一次拷贝构造函数
    // vecB.emplace_back(4, 5, str2);
    // vecB.emplace_back(4, 5, str2);

    printf("2. ***********************\n");

    //! std::move 将左值对象转换成右值形式。
    //! 左值: 有名的，可寻址的变量
    //! 右值: 无名的， 不可寻址的临时变量
    printf("--- push_back \n");
    vecA.push_back(std::move(cls1));

    printf("--- emplace_back \n");
    vecB.emplace_back(std::move(cls2));

    printf("end ***********************\n");

}

void Vector_Test::move_constructor(){
    printf("=== move_constructor ===\n");

    for (size_t i = 0; i < 100; i++)
    {
        // auto btime1 = std::chrono::steady_clock::now();
        // std::vector<int> v1(1000000, 5);
        // std::vector<int> v2 = std::move(v1);
        // // std::vector<int> v2 = v1; 
        // auto etime1 = std::chrono::steady_clock::now();
        // std::cout << "1. cost time: " << std::chrono::duration_cast<std::chrono::milliseconds>(etime1-btime1).count() << " ms" << std::endl;

        auto btime2 = std::chrono::steady_clock::now();
        std::vector<int> v3 = std::vector<int>(1000000, 5); 
        auto etime2 = std::chrono::steady_clock::now();
        std::cout << "2. cost time: " << std::chrono::duration_cast<std::chrono::milliseconds>(etime2-btime2).count() << " ms" << std::endl;
    }
    
}

void Vector_Test::test(){
    // int n = 102;
    // int a[n];

    std::vector<double> v1{};
    std::cout << "v1.capacity(): " << v1.capacity() << std::endl;
    v1.push_back(2.3);
    std::cout << "v1.capacity(): " << v1.capacity() << std::endl;
    v1.push_back(23.4);
    std::cout << "v1.capacity(): " << v1.capacity() << std::endl;
    v1.push_back(35.1);
    std::cout << "v1.capacity(): " << v1.capacity() << std::endl;
}