#include "Sort.h"

namespace algorithms{

void Sort::Test_BubbleSort(std::vector<int>& vec){
    // #1
    // int size = vec.size();
    // for (size_t i = 0; i < size-1; i++)
    // {
    //     for (size_t j = 0; j < size-i-1; j++)
    //     {
    //         if(vec[j] > vec[j+1]){
    //             std::swap(vec[j], vec[j+1]);
    //         }
    //     }
    // }
    
    // #2
    int size = vec.size();
    for (size_t i = 0; i < size-1; i++) //! 总共需要确定 size-1 个位置的元素
    {
        for (size_t j = size-1; j > i; j--) //! 前 i 个位置已经确定了
        {
            if(vec[j] < vec[j-1]) std::swap(vec[j], vec[j-1]);
        }
        
    }
    
}

}