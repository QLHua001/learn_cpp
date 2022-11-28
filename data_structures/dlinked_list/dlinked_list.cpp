#include <iostream>
#include "dlinked_list.h"

namespace data_structures{
namespace dlinked_list{

bool DList::IsEmpty(){
    return (this->length_ == 0);
}

int DList::GetLen(){
    return this->length_;
}

void DList::PushFront(int val){
    std::shared_ptr<DNode> dnode = std::make_shared<DNode>(val);
    if(this->IsEmpty()){
        dnode->prior_ = this->head_;
        this->head_->next_ = dnode;
        this->last_ = dnode;
    }else{
        dnode->prior_ = this->head_;
        dnode->next_ = this->head_->next_;
        this->head_->next_->prior_ = dnode;
        this->head_->next_ = dnode;
    }
    this->length_++;
}

void DList::PushBack(int val){
    std::shared_ptr<DNode> dnode = std::make_shared<DNode>(val);
    if(this->IsEmpty()){
        dnode->prior_ = this->head_;
        this->head_->next_ = dnode;
    }else{
        dnode->prior_ = this->last_;
        this->last_->next_ = dnode;
        this->last_ = dnode;
    }
    this->length_++;
}

bool DList::GetNode(int pos, std::shared_ptr<DNode>& ptr){
    if(pos < 0 || pos > this->length_-1) return false;

    std::shared_ptr<DNode> p = this->head_->next_;
    int cur = 0;
    while(cur < pos){
        p = p->next_;
        cur++;
    }
    ptr = p;
    return true;
}

void DList::Search(int val, std::shared_ptr<DNode>& ptr){
    std::shared_ptr<DNode> p = this->head_->next_;

    while(p != nullptr){
        if(p->val_ == val){
            ptr = p;
            return;
        }
        p = p->next_;
    }
    ptr = nullptr;
}

bool DList::Insert(int pos ,int val){
    if(pos < 0 || pos > this->length_) return false;

    std::shared_ptr<DNode> dnode = std::make_shared<DNode>(val);
    std::shared_ptr<DNode> p = this->head_->next_;
    int cur = 0;
    while(cur < pos){
        p = p->next_;
        cur++;
    }

    if(p == nullptr){
        dnode->prior_ = this->last_;
        this->last_->next_ = dnode;
        this->last_ = dnode;
        this->length_++;
    }else{
        dnode->prior_ = p->prior_;
        dnode->next_ = p;
        p->prior_->next_ = dnode;
        p->prior_ = dnode;
        this->length_++;
    }

    return true;
}

bool DList::Delete(int pos ,int& val){
    if(pos < 0 || pos > this->length_-1) return false;

    std::shared_ptr<DNode> p = this->head_->next_;
    int cur = 0;
    while(cur < pos){
        p = p->next_;
        cur++;  
    }

    if(pos == this->length_-1){
        this->last_ = p->prior_;
        this->last_->next_ = nullptr;
    }

    val = p->val_;
    p->prior_->next_ = p->next_;
    p->next_->prior_ = p->prior_;
    p.reset();
    this->length_--;
    return true;
}

void DList::Reverse(){
    //todo
}
    
void DList::Display(){
    std::shared_ptr<DNode> p = this->head_->next_;
    while(p != nullptr){
        std::cout << p->val_ << "\t";
        p = p->next_;
    }
    std::cout << std::endl;
}


}
}