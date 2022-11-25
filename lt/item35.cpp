#include <iostream>
#include <vector>

namespace lt{

/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。
*/

static int item35(std::vector<int>& vec, int target){

    int left = 0;
    int right = vec.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(vec[mid] > target) right = mid - 1;
        else if(vec[mid] < target) left = mid + 1;
        else return mid;
    }

    //! 当target 小于所有 vec 元素时, [left, right]=[0, -1];
    //! 当target 大于所有 vec 元素时, [left, right]=[vec.size(), vec.size()-1]
    //! 当target 等于某个 vec 元素时, return mid;
    //! 当target 插入 vec 中间位置时, return right + 1;
    return right+1;
}

void item35(){
    std::vector<int> v1{3, 4, 6, 7, 33, 100, 101, 102};

    int index = item35(v1, 103);
    std::cout << index << std::endl;
}

}