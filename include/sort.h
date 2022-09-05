#pragma once
#include <vector>

void Bubble_Sort(std::vector<int>& a);
void Selection_Sort(std::vector<int>& a);
void Insertion_Sort(std::vector<int>& a);
void Shell_Sort(std::vector<int>& a);
void Quick_Sort(std::vector<int>& a);

//! 归并排序是用分治思想，分治模式在每一层递归上有三个步骤：
//! 分解（Divide）：将n个元素分成个含n/2个元素的子序列。
//! 解决（Conquer）：用合并排序法对两个子序列递归的排序。
//! 合并（Combine）：合并两个已排序的子序列已得到排序结果。
void Merge_Sort(std::vector<int>& arr, int low,int high);