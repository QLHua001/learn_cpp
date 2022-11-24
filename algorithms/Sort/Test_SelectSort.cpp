#include "Sort.h"

namespace algorithms{

void Sort::Test_SelectSort(std::vector<int>& vec){
    size_t size = vec.size();
    for (size_t i = 0; i < size-1; i++)
    {
        int idx = i;
        for (size_t j = i+1; j < size; j++)
        {
            if(vec[j] < vec[idx]) idx = j;
        }

        std::swap(vec[i], vec[idx]);
    }
}

}