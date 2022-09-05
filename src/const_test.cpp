#include <iostream>
#include <string>
void const_test(){
    //! 使用值传递初始化时，被初始化的对象是否为const与初始化对象是否为const无关。也即，const对象与非const对象可以互为初始化。
    int i = 0;
    int j = i;       // 正确，非const初始化非const
    const int k = i; // 正确，非const初始化const

    const int x = 22;
    int y = x;       // 正确，const初始化非const
    const int z = x; // 正确，const初始化const
    printf("i: %d, j: %d, k: %d\n", i, j, k);
    printf("x: %d, y: %d, z: %d\n", x, y, z);

    int a = 2;
    int& b = a;

    std::string str = "ABC";
    std::string& str1 = str;

    const int &i11 = 2;    // 正确：i是常量引用
    const int &j11 = a * 2; // 正确：j是常量引用
    
}