#include "ConstExpr.h"
#include <iostream>

static void test1(){

    int len{12};
    int nums[len]{1, 2, 3, 4, 8, 9};
    for(auto num : nums){
        std::cout << num << " ";
    }
    std::cout << std::endl;

}

static constexpr int mul(int x, int y){
    return x * y;
}

static void test2(){

    constexpr int a = 10;
    constexpr int b = 12;
    int c = 15;
    int val1 = mul(a, b);
    int val2 = mul(a, c);

}

void ConstExpr::constexpr_test(){
    printf("=== constexpr_test ===\n");

    // test1();

    test2();

}