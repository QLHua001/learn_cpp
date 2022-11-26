#pragma once 

#include <memory>

namespace data_structures{
namespace linked_list
{
    
struct Link{
    int val_;
    std::shared_ptr<Link> next_;

    explicit Link(int val = 0) : val_(val), next_(nullptr){};
};

class List{
public:
    explicit List(){
        this->head_ = std::make_shared<Link>();
        this->last_ = nullptr;
        this->length_ = 0;
    }

    bool IsEmpty(); // 判断链表是否为空
    int GetLen();   // 返回链表的长度
    void PushFront(int val);    //头部插入元素
    void PushBack(int val);     //尾部插入元素
    bool GetNode(int pos, std::shared_ptr<Link>& ptr);//返回 pos 位置的节点
    void Search(int val, std::shared_ptr<Link>& ptr); // 返回第一个值域等于 val 的节点，若不存在返回nullptr
    bool Insert(int pos, int val);// 在pos位置插入val
    bool Delete(int pos, int& val);// 删除pos位置的节点元素，并返回其值
    void Reverse();
    void Display();

private:
    std::shared_ptr<Link> head_;
    std::shared_ptr<Link> last_;
    int length_;
};

void test_linked_list();

} // namespace linked_list
} //namespace data_structures