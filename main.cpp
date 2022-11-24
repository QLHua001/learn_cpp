#include <iostream>
#include <vector>

#include "learn_cpp.h"
#include "sort.h"
#include "data_structures/list_array/list_array.h"
#include "algorithms/Search/Search.h"
#include "algorithms/Sort/Sort.h"
#include "C_Cpp_Mixup/func1.h"
#include "C_Cpp_Mixup/func2.h"
#include "C_Cpp_Mixup/Test_C.h"
#include "Class_Object/Class_Object.h"
#include "List_Initialization/List_Initialization.h"
#include "ConstExpr/ConstExpr.h"
#include "Const/Const.h"
#include "Reference/Reference.h"
#include "New_Delete/New_Delete.h"
#include "Inline/Inline.h"
#include "multi_thread/multi_thread.h"
#include "Containers/Array/Array_Test.h"
#include "Containers/Vector/Vector_Test.h"
#include "Containers/Deque/Deque_Test.h"
#include "Containers/List/List_Test.h"
#include "Containers/Forward_List/Forward_List_Test.h"
#include "Containers/Map/Map_Test.h"
#include "Containers/Set/Set_Test.h"
#include "Containers/String/String_Test.h"
#include "Overload/Overload.h"
#include "Smart_Pointer/Smart_Pointer.h"
#include "Lambda/Lambda.h"
#include "Regex/Regex.h"
#include "TypeID/TypeID.h"

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

//! http://c.biancheng.net/view/vip_2110.html
//! extern
// int square(int n); //! 等价于 extern int square(int n); 变量和函数不同，编译器只能根据 extern 来区分，有 extern 才是声明，没有 extern 就是定义。
// extern "C" {
//     void func1(); //! 等价于 extern void func1();
// }

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

    // data_structures
    // list_array
    // data_structures::list_array::test_list_array();// 命名空间:命名空间:普通全局函数

    // Algorithms
    // Search
    // std::vector<int> v1{2, 3, 5, 11, 34, 51, 102, 222};
    // int idx = algorithms::Search::Test_BinSearch(v1, 11);// 命名空间:类空间:成员函数

    // Sort
    std::vector<int> v2{233, 32, 535, 101, 15, 51, 102, 222};
    algorithms::Sort::Test_BubbleSort(v2); // 命名空间:类空间:成员函数
    for(auto& val : v2) std::cout << val << "\t";

    //! C_Cpp_Mixup
    // func1();
    // func2();
    // Test_C();

    //! Class_Object
    // Class_Object::Test_Polymorphism();

    //! List_Initialization
    // List_Initialization::list_initialization_test();

    //! ConstExpr
    // ConstExpr::constexpr_test();

    //! Const
    // Const::Const_Test();
    // Const::Const_Test_2();

    //! Reference
    // Reference::Reference_Test();

    //! New_Delete
    // New_Delete::New_Delete_Test();

    //! inline
    // Inline::Inline_Test();

    //! multi_thread
    // multi_thread::thread_test();

    //! Containers
    // Array
    // Array_Test::test();

    // Vector
    // Vector_Test::push_back_emplace_back();
    // Vector_Test::move_constructor();
    // Vector_Test::test();

    // Deque
    // Deque_Test::test();
    // Deque_Test::emplace_test();

    // List
    // List_Test::test();

    // Forward_List
    // Forward_List_Test::test();

    // Map
    // Map_Test::pair_test();
    // Map_Test::test();

    // Set
    // Set_Test::test();

    // String
    // String_Test::test();

    //! Overload
    // Overload::test_overload_assignment_operator();
    // Overload::test_overload_bracket_operator();

    //! Smart_Pointer
    // Smart_Pointer::shared_ptr_test();
    // Smart_Pointer::unique_ptr_test();
    // Smart_Pointer::weak_ptr_test();

    //! Lambda
    // Lambda::lambda_test();

    //! Regex
    // Regex::Regex_Test();

    // int val = square(3);
    // std::cout << "val: " << val << std::endl;

    //! typeid
    // TypeID::test_typeid();
    // TypeID::test_typeid_class();

}
