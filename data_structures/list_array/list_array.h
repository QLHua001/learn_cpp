#pragma once 

#include <array>

namespace data_structures{
namespace list_array{

    template <uint64_t N>
    struct List {
        std::array<uint64_t, N> data_{};
        uint64_t top_{0};
        bool is_sorted_{false};
    
        // uint64_t BinarySearch(
        // const std::array<uint64_t, N> &array_data,
        // const uint64_t &first,
        // const uint64_t &last,
        // const uint64_t &val){

        //     // 递归方式
        //     return -1;
        // }
        
        uint64_t BinarySearch(
        const uint64_t &val) const{

            uint64_t left = 0;
            uint64_t right = this->top_ - 1;
            while(left <= right){
                int mid = (left + right) / 2;
                if(this->data_[mid] > val){
                    right = mid - 1;
                }else if(this->data_[mid] < val){
                    left = mid + 1;
                }else{
                    return mid;
                }
            }

            return -1;
        }
        
        uint64_t LinearSearch(
        const uint64_t &val) const{

            for (size_t i = 0; i < this->top_; i++)
            {
                if(this->data_[i] == val) return i;
            }
            
            return -1;
        }
        
        uint64_t Search(const uint64_t &val){

            if(this->is_sorted_){
                return this->BinarySearch(val);
            }else{
                return this->LinearSearch(val);
            }
        }

        void Sort(){
            // Bubble Sort
            int size = this->top_;
            for (size_t i = 0; i < size-1; i++)
            {
                for (size_t j = 0; j < size-i-1; j++)
                {
                    if(this->data_[j] > this->data_[j+1]) std::swap(this->data_[j], this->data_[j+1]);
                }
            }

            this->is_sorted_ = true;
        }

        void Insert(const uint64_t &val){
            if(this->top_ == N){
                std::cout << "Overflow.\n";
                return;
            }

            if(!this->is_sorted_){
                this->data_[this->top_] = val;
            }else{
                //todo 排序数组的插入
            }
            this->top_++;
        }

        void Remove(const uint64_t &val){
            uint64_t pos = this->Search(val);

            if(pos == -1){
                std::cout << "Element " << val << " does not present int the array.\n";
                return;
            }
            std::cout << this->data_[pos] << " deleted.\n";

            for (size_t i = pos; i < this->top_-1; i++)
            {
                this->data_[i] = this->data_[i+1];
            }
            this->top_--;
        }

        void Show(){
            for (size_t i = 0; i < this->top_; i++)
            {
                std::cout << this->data_[i] << "\t";
            }
            std::cout << std::endl;
        }
        
    };

    void test_list_array();

}
}