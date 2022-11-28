#include "Sort.h"
namespace algorithms{

static void merge(std::vector<int>& vec, int left, int mid, int right){
    int i = left, j = mid + 1, k = 0;
    int *temp = new int[right-left+1];
    while(i<=mid && j<=right){
        if(vec[i] <= vec[j]){
            temp[k++] = vec[i++];
        }else{
            temp[k++] = vec[j++];
        }
    }
    while(i <= mid){
        temp[k++] = vec[i++];
    }

    while(j <= right){
        temp[k++] = vec[j++];
    }

    for(i = left, k = 0; i <= right; i++, k++){
        vec[i] = temp[k];
    }

    delete[] temp;
}

void Sort::Test_MergeSort(std::vector<int>& vec, int left, int right){
    if(left >= right) return;
    int mid = (left + right) / 2;
    Sort::Test_MergeSort(vec, left, mid);
    Sort::Test_MergeSort(vec, mid+1, right);
    merge(vec, left, mid, right);
}

}