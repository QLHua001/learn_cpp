#include <vector>

//! 不稳定排序， O(nlogn)
void QSort(std::vector<int>& a, int left, int right){
    if(left >= right){
        return;
    }

    int i = left;
    int j = right;
    int temp = a[i];

    while(i != j){
        while(i < j && a[j] >= temp){
            j--;
        }
        std::swap(a[i], a[j]);

        while(i < j && a[i] <= temp){
            i++;
        }
        std::swap(a[i], a[j]);
    }
    QSort(a, i+1, right);
    QSort(a, left, i-1);
}

void Quick_Sort(std::vector<int>& a){

    QSort(a, 0, a.size()-1);

}