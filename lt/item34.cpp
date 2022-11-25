#include <iostream>
#include <vector>

namespace lt{
/*
在排序数组中查找元素的第一个和最后一个位置
*/

static std::vector<int> item34(const std::vector<int>& vec, int target){

    int left = 0;
    int right = vec.size() - 1;
    int it = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(vec[mid] < target) left = mid + 1;
        else if(vec[mid] > target) right = mid - 1;
        else{
            it = mid;
            break;
        }
    }

    std::vector<int> res{it, it};

    if(it != -1){
        for (size_t i = it-1; i >= 0; i--)
        {
            if(vec[i] != target){
                res[0] = i+1;
                break;
            }
        }
        
        for (size_t i = it+1; i < vec.size(); i++)
        {
            if(vec[i] != target){
                res[1] = i-1;
                break;
            }
        }
    }

    return std::move(res);
}

void item34(){
    // std::vector<int> v1{3, 3, 3, 4, 6, 7, 33, 100, 100, 100, 101, 102};
    std::vector<int> v1;
    auto res = item34(v1, 3);
    for(auto& item : res) std::cout << item << "\t";
    std::cout << std::endl;
}

}