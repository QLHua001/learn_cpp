#include <array>

namespace data_structures{
namespace list_array{

    template <uint64_t N>
    struct List {
        std::array<uint64_t, N> data_{};
        uint64_t last_;
        bool is_sorted_{false};
    
        uint64_t BinarySearch(const std::array<uint64_t, N> &array_data,
                              const uint64_t &first,
                              const uint64_t &last,
                              const uint64_t &val);
        
        uint64_t LinearSearch(const std::array<uint64_t, N> &array_data,
                              const uint64_t &val);
        
        uint64_t Search(const uint64_t &val);

        void Sort();

        void Insert(const uint64_t &val);

        void Remove(const uint64_t &val);

        void Show();

        
    };

    void test_list_array();

}
}