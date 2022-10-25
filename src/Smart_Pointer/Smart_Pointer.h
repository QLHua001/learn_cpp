#pragma once


#include "Smart_Pointer.h"

class Smart_Pointer{

private:

    class DemoCls{
        public: 
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