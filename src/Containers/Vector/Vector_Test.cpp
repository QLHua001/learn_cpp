#include <iostream>
#include <vector>
#include "Vector_Test.h"
#include <cstring>

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
    // vecB.emplace_back(4, 5, str2); // ! 直接调用构造函数， 对比push_back, 减少了一次拷贝构造函数
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