#include <iostream>
#include "linked_list.h"

namespace data_structures{
namespace linked_list{
    
bool List::IsEmpty(){
    // if(!this->last_) return true;
    // return false;
    if(this->length_ == 0) return true;
    else return false;
}

int List::GetLen(){
    return this->length_;
}

void List::PushFront(int val){
    if(this->IsEmpty()){
        this->head_->next_ = std::make_shared<Link>(val);
        this->last_ = this->head_->next_;
        this->length_++;
    }else{
        std::shared_ptr<Link> link = std::make_shared<Link>(val);
        link->next_ = this->head_->next_;
        this->head_->next_ = link;
        this->length_++;
    }
}

void List::PushBack(int val){
    if(this->IsEmpty()){
        this->head_->next_ = std::make_shared<Link>(val);
        this->last_ = this->head_->next_;
        this->length_++;
    }else{
        this->last_->next_ = std::make_shared<Link>(val);
        this->last_ = this->last_->next_;
        this->length_++;
    }
}

bool List::GetNode(int pos, std::shared_ptr<Link>& ptr){
    if(pos < 0 || pos > this->length_-1) return false;

    std::shared_ptr<Link> p = this->head_->next_;
    int cur = 0;
    while(cur < pos){
        p = p->next_;
        cur++;
    }
    ptr = p;
    return true;
}

// 返回第一个值域等于 val 的节点，若不存在返回nullptr
void List::Search(int val, std::shared_ptr<Link>& ptr){
    std::shared_ptr<Link> p = this->head_->next_;
    while(p != nullptr){
        if(p->val_ == val){
            ptr = p;
            return;
        }
        p = p->next_;
    }
    ptr = nullptr;
}

bool List::Insert(int pos, int val){
    if(pos < 0 || pos > this->length_) return false;

    std::shared_ptr<Link> pre = this->head_;
    std::shared_ptr<Link> p = pre->next_;
    int cur = 0;
    while(cur < pos){
        pre = p;
        p = p->next_;
        cur++;
    }

    // cur == pos
    std::shared_ptr<Link> link = std::make_shared<Link>(val);
    link->next_ = p;
    pre->next_ = link;

    if(pos == this->length_){
        this->last_ = p;
    }

    this->length_++;

    return true;
}

bool List::Delete(int pos, int& val){
    if(pos < 0 || pos > this->length_-1) return false;

    std::shared_ptr<Link> pre = this->head_;
    std::shared_ptr<Link> p = pre->next_;
    int cur = 0;
    while(cur < pos){
        pre = p;
        p = p->next_;
        cur++;
    }

    // cur == pos
    pre->next_ = p->next_;
    val = p->val_;

    if(pos == this->length_-1){
        this->last_ = pre;
    }

    p.reset();
    this->length_--;

    return true;
}

void List::Reverse(){
    // if(!this->head_->next_ || !this->head_->next_->next_) return;
    if(this->length_ == 0 || this->length_ == 1) return;

    std::shared_ptr<Link> cur = this->head_->next_;
    std::shared_ptr<Link> prior = nullptr;
    std::shared_ptr<Link> next = cur->next_;

    this->last_ = cur;
    while(next != nullptr){
        cur->next_ = prior;
        prior = cur;
        cur = next;
        next = next->next_;
    }

    cur->next_ = prior;
    this->head_->next_ = cur;

}

void List::Display(){
    std::shared_ptr<Link> p = this->head_->next_;
    while(p != nullptr){
        std::cout << p->val_ << "\t";
        p = p->next_;
    }
    std::cout << std::endl;
}

} // namespace linked_list     
} // namespace data_structures
