#include <vector>

//! 不稳定排序 O(n^2)
void Selection_Sort(std::vector<int>& a){
    int len = a.size();
    for (size_t i = 0; i < len - 1; i++)
    {
        int min_index = i;
        for (size_t j = i+1; j < len; j++)
        {
            if(a[min_index] > a[j]){
                min_index = j;
            }
        }

        std::swap(a[min_index], a[i]);
        
    }
    
}