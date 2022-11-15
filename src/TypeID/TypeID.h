#pragma once
#include <iostream>

class TypeID{
private:

    class Card{
    public:
        virtual void display(){std::cout << "Card" << std::endl;}
    };

    class ACard : public Card{
    public:
        virtual void display(){std::cout << "ACard" << std::endl;}
    };

public:
    static void test_typeid();

    static void test_typeid_class();

};