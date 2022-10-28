#include <iostream>
#include <cstring>
#include "New_Delete.h"

//! C++ new delete 总结
/*

在C++中，建议使用 new 和 delete 来管理内存，它们可以使用C++的一些新特性，//!最明显的是可以自动调用构造函数和析构函数

*/
//! C++ new delete 总结
// DemoCls
New_Delete::DemoCls::DemoCls(int id1, int id2, const char* name){
    printf("调用构造函数\n");

    _id1 = id1;
    _id2 = id2;

    _name = new char[strlen(name)+1];
    strcpy(_name, name);

}

//! 深拷贝与浅拷贝
New_Delete::DemoCls::DemoCls(const New_Delete::DemoCls& other){
    printf("调用拷贝构造函数\n");

    _id1 = other._id1;
    _id2 = other._id2;

    _name = new char[strlen(other._name)+1];
    strcpy(_name, other._name);
}

//! 移动构造函数
New_Delete::DemoCls::DemoCls(New_Delete::DemoCls&& other){
    printf("调用移动构造函数\n");
    _id1 = other._id1;
    _id2 = other._id2;

    _name = other._name;
    other._name = nullptr;
}

New_Delete::DemoCls::~DemoCls(){
    printf("调用析构函数\n");
    if(_name){
        delete[] _name;
    }
    _name = nullptr;
}

void New_Delete::DemoCls::setVal(const int& id1, const int& id2, const char* name){
    this->_id1 = id1;
    this->_id2 = id2;
    
    if(this->_name) delete[] this->_name;
    
    this->_name = new char[strlen(name)+1];
    strcpy(this->_name, name);
}


void New_Delete::New_Delete_Test(){
    printf("=== New_Delete_Test ===\n");

    DemoCls* pDC1 = new DemoCls(1, 2, "hello");

    pDC1->setVal(5, 6, "world");

    delete pDC1;

    // DemoCls* pDC2 = (DemoCls*)malloc(sizeof(DemoCls));

    // pDC2->setVal(3, 4, "world");

    // free(pDC2);
}