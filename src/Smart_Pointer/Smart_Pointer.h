#pragma once

#include <iostream>
#include "Smart_Pointer.h"

class Smart_Pointer{

private:

    class DemoCls{
        public: 
            DemoCls():_id1(0), _id2(0), _name(nullptr){printf("调用默认无参构造函数.\n");}

            // 构造函数
            DemoCls(int id1, int id2, const char* name);

            // 拷贝构造函数
            DemoCls(const DemoCls& other);

            // 移动构造函数
            DemoCls(DemoCls&& other);

            ~DemoCls();

        private:

            int _id1;
            int _id2;
            char* _name;

    };

public:

//! shared_ptr
static void shared_ptr_test();

//! unique_ptr
static void unique_ptr_test();

//! weak_ptr
static void weak_ptr_test();

};