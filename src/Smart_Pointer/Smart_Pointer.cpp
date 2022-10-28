#include <iostream>
#include <cstring>
#include "Smart_Pointer.h"

// DemoCls
Smart_Pointer::DemoCls::DemoCls(int id1, int id2, const char* name){
    printf("调用有参构造函数\n");

    _id1 = id1;
    _id2 = id2;

    _name = new char[strlen(name)+1];
    strcpy(_name, name);

}

//! 深拷贝与浅拷贝
Smart_Pointer::DemoCls::DemoCls(const Smart_Pointer::DemoCls& other){
    printf("调用拷贝构造函数\n");

    _id1 = other._id1;
    _id2 = other._id2;

    _name = new char[strlen(other._name)+1];
    strcpy(_name, other._name);
}

//! 移动构造函数
Smart_Pointer::DemoCls::DemoCls(Smart_Pointer::DemoCls&& other){
    printf("调用移动构造函数\n");
    _id1 = other._id1;
    _id2 = other._id2;

    _name = other._name;
    other._name = nullptr;
}

Smart_Pointer::DemoCls::~DemoCls(){
    printf("调用析构函数\n");
    if(_name){
        delete[] _name;
    }
    _name = nullptr;
}