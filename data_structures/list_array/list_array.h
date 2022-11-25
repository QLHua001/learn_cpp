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
                // 二分查找法
                int pos = -1; //元素插入位置
                int left = 0;
                int right = this->top_ - 1;
                while(left <= right){
                    int mid = (left + right) / 2;
                    if(this->data_[mid] < val) left = mid + 1;
                    else if(this->data_[mid] > val) right = mid - 1;
                    else{
                        pos = mid;
                        break;
                    }
                }

                if(pos == -1) pos = right + 1;

                for (size_t i = this->top_-1; i >= pos; i--)
                {
                    this->data_[i+1] = this->data_[i];
                }
                this->data_[pos] = val;
            }
            this->top_++;
        }

        void Remove(const uint64_t &val){
            if(!this->is_sorted_){
                this->Sort();
            }

            uint64_t pos = this->Search(val);

            if(pos == -1){
                std::cout << "Element " << val << " does not present int the array.\n";
                return;
            }

            int p;
            //! 确定左边界
            int left = pos;
            for (p = pos - 1; p >= 0; p--)
            {
                if(this->data_[p] != val){
                    left = p + 1;
                    break;
                }
            }
            if(p == -1) left = 0;

            //! 确定右边界
            int right = pos;
            for (p = pos + 1; p < this->top_; p++)
            {
                if(this->data_[p] != val){
                    right = p - 1;
                    break;
                }
            }
            if(p == this->top_) right = this->top_ - 1;
            
            int remove_count = right - left + 1;
            
            std::cout << this->data_[pos] << " deleted.\n";

            for (int rit = right + 1; rit < this->top_; rit++)
            {
                this->data_[left++] = this->data_[rit];
            }
            
            this->top_ -= remove_count;

        }

        void Show(){
            for (int i = 0; i < this->top_; i++)
            {
                std::cout << this->data_[i] << "\t";
            }
            std::cout << std::endl;
        }
        
    };

    void test_list_array();

}
}