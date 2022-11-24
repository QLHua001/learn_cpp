#include <vector>

namespace algorithms{

class Sort{

public:
    //! 冒泡排序 稳定排序 O(n^2)
    static void Test_BubbleSort(std::vector<int>& vec);

    //! 插入排序 稳定排序 O(n^2)
    static void Test_InsertSort(std::vector<int>& vec);

};

}