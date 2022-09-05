#include <vector>

//! 稳定排序 O(n^2)
void Insertion_Sort(std::vector<int>& a){

    int count = a.size();
    for (int i = 0; i < count - 1; i++)
    {
        int j = i;
        int temp = a[i+1];
        while(j >= 0 && a[j] > temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    

}