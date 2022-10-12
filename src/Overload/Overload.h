#pragma once

class Overload{
private:

    class MyString{
        
        public:
            MyString(const char* str);
            ~MyString();

            void display();


            //! 通常情况下编译器提供的默认重载赋值运算符函数能够解决对象间赋值的问题，但是当类中含有指针数据成员时，容易引起指针悬挂的问题，
            //! 所以这种情况下有必要进行赋值运算符重载。
            MyString& operator=(const MyString& other);


        private:
            char* _ptr;
            int _size;

    };

    class MyArray{
        public:
            MyArray(int a1, int a2, int a3, int a4);
            ~MyArray();

            //! 由于[]既可以作为左值又可以作为右值,所以重载下标运算符函数通常返回引用。
            //! 重载的下标运算符函数只能有一个参数，即使用的方式只能是 Aclss[para],不能没有参数或者是Aclss[para1, para2]多参数的形式。
            int& operator[](int idx);

        private:
            int arr[5];
    };

public:

    //! 重载赋值运算符
    static void test_overload_assignment_operator();

    //! 重载下标(中括号)运算符
    static void test_overload_bracket_operator();


};