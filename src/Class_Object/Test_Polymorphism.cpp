#include <iostream>
#include <vector>
#include "Class_Object.h"

void Class_Object::Test_Polymorphism(){
    printf("=== Test_Polymorphism ===\n");

    std::vector<Card*> vc;
    vc.emplace_back(new ACard());
    vc.emplace_back(new BCard());
    vc.emplace_back(new ACard());

    std::cout << "###############################" << std::endl;

    for (size_t i = 0; i < vc.size(); i++)
    {
        delete vc[i];
    }
    
}