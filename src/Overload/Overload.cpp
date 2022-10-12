#include <iostream>
#include <cstring>
#include "Overload/Overload.h"


Overload::MyString::MyString(const char* str){

    this->_size = strlen(str);
    this->_ptr = new char[this->_size+1];
    strcpy(this->_ptr, str);

}

Overload::MyString::~MyString(){

    if(this->_ptr){
        delete[] this->_ptr;
    }
    this->_ptr = nullptr;
    this->_size = 0;

}

Overload::MyString& Overload::MyString::operator=(const Overload::MyString& other){

    if(this != &other){
        if(this->_ptr){
            delete[] this->_ptr;
        }

        this->_size = other._size;
        this->_ptr = new char[this->_size+1];
        strcpy(this->_ptr, other._ptr);
    }

    return *this;

}

void Overload::MyString::display(){
    std::cout << this->_ptr << std::endl;
}


Overload::MyArray::MyArray(int a1, int a2, int a3, int a4){
    this->arr[0] = a1;
    this->arr[1] = a2;
    this->arr[2] = a3;
    this->arr[3] = a4;
}

Overload::MyArray::~MyArray(){
    
}

int& Overload::MyArray::operator[](int idx){
    if(idx < 0 || idx > 3){
        std::cout << "idx error. reset to 0." << std::endl;
        idx = 0;
    }

    return this->arr[idx];
}

