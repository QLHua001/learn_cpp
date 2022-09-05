#include <vector>

//! 不稳定排序 O(nlogn)
// void Shell_Sort(std::vector<int>& a){
//     int count = a.size();
    
//     int d = count;

//     while(d > 1){
//         d = d / 2;
//         for (int x = 0; x < d; x++)
//         {
//             for (int i = x; i < count - d; i = i+d)
//             {
//                 int j = i;
//                 int temp = a[i+d];
//                 while(j >= 0 && a[j] > temp){
//                     a[j+d] = a[j];
//                     j = j - d;
//                 }
//                 a[j+d] = temp;
//             }
//         }
//     }
// }

void Shell_Sort(std::vector<int>& a){
    int count = a.size();
    
    int d = count;

    while(d > 1){
        d = d / 2;
        for (int x = 0; x < d; x++)
        {
            for (int i = x + d; i < count; i = i+d)
            {
                int j = i;
                int temp = a[j];
                for(j = j - d; j >= 0 && a[j] > temp; j = j - d){
                    a[j + d] = a[j];
                }
                a[j+d] = temp;
            }
        }
    }
}