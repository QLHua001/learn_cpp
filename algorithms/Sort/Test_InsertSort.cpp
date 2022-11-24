#include "Sort.h"

namespace algorithms{

//! 插入排序
void Sort::Test_InsertSort(std::vector<int>& vec){
    int size = vec.size();
    for (size_t i = 1; i < size; i++)
    {
        int temp = vec[i];
        int j = i - 1;
        while(j >= 0 && vec[j] > temp){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = temp;
    }
    
}

}