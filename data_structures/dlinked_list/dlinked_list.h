#pragma once

#include <memory>

namespace data_structures{
namespace dlinked_list{

struct DNode{
    int val_;
    std::shared_ptr<DNode> prior_;
    std::shared_ptr<DNode> next_;

    explicit DNode(int val = 0):val_(val), prior_(nullptr), next_(nullptr){}
};

class DList{
public:
    explicit DList(){
        this->head_ = std::make_shared<DNode>();
        this->last_ = nullptr;
        this->length_ = 0;
    }

    bool IsEmpty();
    int GetLen();
    void PushFront(int val);
    void PushBack(int val);
    bool GetNode(int pos, std::shared_ptr<DNode>& ptr);
    void Search(int val, std::shared_ptr<DNode>& ptr);
    bool Insert(int pos ,int val);
    bool Delete(int pos ,int& val);
    void Reverse();
    void Display();

private:
    std::shared_ptr<DNode> head_;
    std::shared_ptr<DNode> last_;
    int length_;

};

void test_dlinked_list();

}
} // namespace data_structures
