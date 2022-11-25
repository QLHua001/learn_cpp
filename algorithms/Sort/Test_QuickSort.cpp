#include "Sort.h"

namespace algorithms{

static void quick_sort(std::vector<int>& vec, int left, int right){
    if(left >= right) return; //! 递归终止条件

    int i = left, j = right;
    int base = vec[i]; //! 基准元素

    while(i != j){
        while(j > i && vec[j] >= base) j--;
        std::swap(vec[j], vec[i]);

        while(i < j && vec[i] <= base) i++;
        std::swap(vec[i], vec[j]);
    }
    quick_sort(vec, left, i-1);
    quick_sort(vec, i+1, right);
}

void Sort::Test_QuickSort(std::vector<int>& vec){
    quick_sort(vec, 0, vec.size()-1);
}

}