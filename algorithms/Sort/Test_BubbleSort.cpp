#include "Sort.h"

namespace algorithms{

void Sort::Test_BubbleSort(std::vector<int>& vec){
    int size = vec.size();
    for (size_t i = 0; i < size-1; i++)
    {
        for (size_t j = 0; j < size-i-1; j++)
        {
            if(vec[j] > vec[j+1]){
                std::swap(vec[j], vec[j+1]);
            }
        }
    }
    
}

}