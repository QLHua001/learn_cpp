#include <vector>

//! 稳定排序 O(n^2)
void Bubble_Sort(std::vector<int>& a){
    for (size_t i = 0; i < a.size() - 1; i++)
    {
        for (size_t j = 0; j < a.size() - 1 - i; j++)
        {
            if(a[j] > a[j+1]){
                std::swap(a[j], a[j+1]);
            }
        }
        
    }
    
}