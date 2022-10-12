#pragma once 

class Vector_Test{

    class DemoCls{
        public: 
            // 构造函数
            DemoCls(int id1, int id2, char* name);

            // 拷贝构造函数
            DemoCls(const Vector_Test::DemoCls& other);

            // 移动构造函数
            DemoCls(Vector_Test::DemoCls&& other);

            ~DemoCls();

        private:

            int _id1;
            int _id2;
            char* _name;

    };

public:

    static void push_back_emplace_back();

private:

};