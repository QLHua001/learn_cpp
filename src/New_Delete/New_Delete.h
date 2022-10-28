#pragma once

class New_Delete{
private:
    class DemoCls{
        public: 
            // 构造函数
            DemoCls(int id1, int id2, const char* name);

            // 拷贝构造函数
            DemoCls(const New_Delete::DemoCls& other);

            // 移动构造函数
            DemoCls(New_Delete::DemoCls&& other);

            ~DemoCls();

            void setVal(const int& id1, const int& id2, const char* name);

        private:

            int _id1;
            int _id2;
            char* _name;

    };

public:

    static void New_Delete_Test();

};