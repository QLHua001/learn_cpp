#include <iostream>
#include <vector>

#include "learn_cpp.h"
#include "sort.h"
#include "multi_thread/multi_thread.h"
#include "Containers/Vector/Vector_Test.h"
#include "Overload/Overload.h"

static float intersection_area(const Object& obj1, const Object& obj2){
    cv::Rect_<float> inter_area = obj1.rect & obj2.rect;
    return inter_area.area();
}

static void Bubble_Sort_0907(std::vector<int>& a){
    printf("===Bubble_Sort_0907===\n");
    int count = a.size();

    for (size_t i = 0; i < count-1; i++)    
    {
        for (size_t j = 0; j < count-i-1; j++)
        {
            if(a[j] > a[j+1]){
                std::swap(a[j], a[j+1]);
            }
        }
        
    }
    
}

static void Insertion_Sort_0907(std::vector<int>& a){
    int count = a.size();

    for (size_t i = 0; i < count-1; i++)
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

static void qsort_0907(std::vector<int>& a, int left, int right){
    if(left >= right) return;

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
    qsort_0907(a, left, i-1);
    qsort_0907(a, i+1, right);
}

static void Quick_Sort_0907(std::vector<int>& a){
    printf("===Quick Sort===\n");
    qsort_0907(a, 0, a.size()-1);
}

static void nms_0907(std::vector<Object>& sorted_boxes, std::vector<int>& picked, float nms_threshold){
    picked.clear();

    int count = sorted_boxes.size();

    std::vector<float> areas(count);
    for (size_t i = 0; i < sorted_boxes.size(); i++)
    {
        areas[i] = sorted_boxes[i].rect.area();
    }

    for (size_t i = 0; i < sorted_boxes.size(); i++)
    {
        const Object& obj1 = sorted_boxes[i];

        bool keep = true;
        for (size_t j = 0; j < picked.size(); j++)
        {
            const Object& obj2 = sorted_boxes[picked[j]];

            float inter_area = intersection_area(obj1, obj2);
            float union_area = areas[i] + areas[picked[j]] - inter_area;
            if((inter_area / union_area) > nms_threshold){
                keep = false;
            }
        }
        if(keep) picked.push_back(i);
        
    }
    
    
}

int main(int, char**) {
    std::cout << "Hello, world!\n";

    // // // 内存四区
    // // for (size_t i = 0; i < 100; i++)
    // // {
    // //     memory_storage();
    // // }

    // // const_test();

    // std::vector<int> a({3, 5, 1, 22, 13, 34, 45, 33, 22, 101, 100, 99, 13});
    // // int b[] = {3, 5, 1, 22, 13, 34, 45, 33, 22, 101, 100, 99, 13};

    // // Bubble_Sort(a);

    // // Selection_Sort(a);

    // // Insertion_Sort(a);

    // // Shell_Sort(a);

    // // Quick_Sort(a);

    // // Merge_Sort(a, 0, a.size()-1);

    // // --------------- 20220907 -------------------

    // // Bubble_Sort_0907(a);

    // // Insertion_Sort_0907(a);

    // // Quick_Sort_0907(a);

    // // --------------- 20220907 -------------------

    // for (size_t i = 0; i < a.size(); i++)
    // {
    //     std::cout << a[i] << "\t";
    // }
    // std::cout << std::endl;

    //! multi_thread
    // multi_thread::thread_test();

    //! Containers
    // Vector
    // Vector_Test::push_back_emplace_back();

    //! Overload
    // Overload::test_overload_assignment_operator();
    Overload::test_overload_bracket_operator();


}
