#pragma once
#include <iostream>
#include <string>

class List_Initialization{
private:

    class Bar{

        public:
            Bar(){printf("调用 Bar 无参构造函数\n");}

            Bar(const std::string& s, const float& v){
                this->_s = s;
                this->_v = v;
            }

            Bar(const Bar& other){
                printf("调用 Bar 拷贝构造函数\n");
                this->_s = other._s;
                this->_v = other._v;
            }

            Bar& operator=(const Bar& other){
                printf("调用 Bar 赋值构造函数\n");
                this->_s = other._s;
                this->_v = other._v;
                return *this;
            }
        private:

            std::string _s;
            float _v;
    };

    class Foo{
        public:
            Foo(int a);

            Foo(int x, int y);

            Foo(int x, int y, const Bar& bar1);

            void set(double d);

            
        private:
            Foo(const Foo& other);


        private:
            int _x;
            int _y;
            Bar _bar1;

            const int _c1;
            const int& _c2;

            double _d1;
            double& _d2;
    };


public:

    static void list_initialization_test();

};