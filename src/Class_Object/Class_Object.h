#pragma once
#include <iostream>
#include <string>

class Class_Object{

    struct Card{
    public:
        Card(int id):id_(id){std::cout << "Card 构造函数。" << std::endl;}
        virtual ~Card(){std::cout << "Card 析构函数。" << std::endl;}
    private:
        int id_{0};
    };

    struct ACard : public Card{
    public:
        ACard():Card(0){std::cout << "ACard 构造函数。" << std::endl;}
        ~ACard(){std::cout << "ACard 析构函数。" << std::endl;}
    private:
        std::string type_{"A"};
    };

    struct BCard : public Card{
    public:
        BCard():Card(1){std::cout << "BCard 构造函数。" << std::endl;}
        ~BCard(){std::cout << "BCard 析构函数。" << std::endl;}
    private:
        std::string type_{"B"};
    };

public:
    static void Test_Polymorphism();

};