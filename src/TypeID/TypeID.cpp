#include <iostream>
#include <typeinfo>
#include "TypeID.h"

void TypeID::test_typeid(){
    printf("=== test_typeid ===\n");
    int n = 100;
    const std::type_info & nInfo = typeid(n);
    std::cout<<nInfo.name()<<" | "<<nInfo.hash_code()<<std::endl;

    double m = 99.9;
    const std::type_info & mInfo = typeid(m);
    std::cout<<mInfo.name()<<" | "<<mInfo.hash_code()<<std::endl;
}


void TypeID::test_typeid_class(){

    //! 类 的 typeid 比较
    //! RTTI, Run-Time Type Identification, 运行时类型识别

    Card card1;
    Card* pCard1 = new Card();
    ACard aCard2;
    ACard* pACard2 = new ACard();
    pCard1 = pACard2;

    std::cout << (typeid(*pCard1)==typeid(ACard)) << std::endl;
    std::cout << (typeid(card1)==typeid(aCard2)) << std::endl;
    std::cout << (typeid(ACard)==typeid(aCard2)) << std::endl;

    std::cout << "###################################" << std::endl;

    int type;
    Card* p;

    std::cin >> type;

    if(type < 100){
        p = new Card();
    }else{
        p = new ACard();
    }

    std::cout<<typeid(*p).name()<<std::endl;

}