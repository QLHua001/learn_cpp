#pragma once 

class Deque_Test{
private:

    class testDemo
    {
    public:
        testDemo(int num) :num(num) {
            std::cout << "调用构造函数" << std::endl;
        }
        testDemo(const testDemo& other) :num(other.num) {
            std::cout << "调用拷贝构造函数" << std::endl;
        }
        testDemo(testDemo&& other) :num(other.num) {
            std::cout << "调用移动构造函数" << std::endl;
        }
        testDemo& operator=(const testDemo& other){
            this->num = other.num;
            return *this;
        }
    private:
        int num;
    };

public:

    static void test();

    static void emplace_test();

};
