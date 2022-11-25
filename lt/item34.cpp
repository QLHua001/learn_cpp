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
        int p;
        for (p = it-1; p >= 0; p--)
        {
            if(vec[p] != target){
                res[0] = p+1;
                break;
            }
        }
        if(p == -1){
            res[0] = 0;
        }
        
        for (p = it+1; p < vec.size(); p++)
        {
            if(vec[p] != target){
                res[1] = p-1;
                break;
            }
        }
        if(p == vec.size()){
            res[1] = vec.size() - 1;
        }
    }

    return std::move(res);
}

void item34(){
    std::vector<int> v1{3, 3, 3, 4, 6, 7, 33, 100, 100, 100, 101, 102, 102, 102};
    // std::vector<int> v1;
    auto res = item34(v1, 102);
    for(auto& item : res) std::cout << item << "\t";
    std::cout << std::endl;
}

}