#include <vector>
namespace algorithms{

class Search{
public:
    /*
    给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
    */
    static int Test_BinSearch(std::vector<int>& nums, int target);
};

}