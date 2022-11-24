#include <iostream>
#include "Search.h"

namespace algorithms{

static int test1(std::vector<int>& nums, int target){
    printf("=== test1 ===\n");
    int left = 0;
    int right = nums.size() - 1; 
    //! 区间的定义就是不变量，在循环中坚持根据查找区间的定义来做边界处理，就是循环不变量规则。
    //! 左闭右闭区间
    while(left <= right){ //! left == right 是有意义的
        int mid = (left + right) / 2;
        if(target < nums[mid]){
            right = mid - 1;
        }else if(target > nums[mid]){
            left = mid + 1;
        }else{
            return mid;
        }
    }

    return -1;
}

/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
*/
int Search::Test_BinSearch(std::vector<int>& nums, int target){
    printf("=== Test_BinSearch ===\n");
    return test1(nums, target);
}

}