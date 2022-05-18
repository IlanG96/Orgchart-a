#pragma once
#include <iostream>
#include<string>
#include<vector>
namespace ariel{


//template <typename T>
class Node
    {
        std::string role_name;
        public:
            std::vector<Node*> subordinate;
            Node(const std::string& role):role_name(role){}
            Node(const Node* other);
            std::string getrole()const{return role_name;}
            void setrole(const std::string role){this->role_name=role;}
            Node* Find(const std::string role);
            int size(){return subordinate.size();}
    };
class OrgChart
{
    public:
    class Iterator;
    // class Iterator
    // {
    // private:
    //     uint index;
    //     Node *_ptr;  
    //     std::vector<Node*>* order_vec;
    // public:
    //     Iterator(uint place, std::vector<Node*> *order):order_vec(order){
    //         order_vec->clear();
    //         order_vec=std::move(order);;
    //         this->index=place;
    //     }//_ptr(order->front())
    //     ~Iterator(){}
    //     std::string operator*(){
    //             return this->order_vec->at(index)->getrole();
    //         }
    //     Iterator& operator++(){
    //         this->index++;
    //         return *this;
    //     } 
    //     Iterator operator++(int){
    //         Iterator it=*this;
    //         ++this->index;
    //         return it;
    //     }
    //     Iterator& operator--(){
    //         this->index--;
    //         return *this;
    //     } 
    //     Iterator operator--(int){
    //         Iterator it=*this;
    //         --this->index;
    //         return it;
    //     }
    //     Node *operator->(){return this->order_vec->at(index);}
    //     //Iterator begin(){return head;}  

    //     // bool operator==(const Iterator& other)const{
    //     //     return other._ptr==this->_ptr;
    //     // }
    //     friend bool operator == (Iterator const &lhs, Iterator const &rhs);
    //     bool operator!=(const Iterator& other)const{
    //         return !(other==*this);
    //     }                     
    // };

//OrgChart class    
private:
    Node * head;
        std::vector<std::string> level_or_rev_list;
        //std::vector<Node *> rev_list;
        std::vector<std::string> pre_list;
public:

    OrgChart(/* args */){head=nullptr;}
    ~OrgChart(){}
    std::vector<std::string>::iterator begin(){return begin_level_order();}
    std::vector<std::string>::iterator end(){return end_level_order();}
    void level_or_reverse_order(bool revrese_flag);
    std::vector<std::string>::iterator begin_level_order(){return level_or_rev_list.begin();}
    std::vector<std::string>::iterator end_level_order(){return level_or_rev_list.end();}//{
         //return Iterator(level_or_rev_list.size()-1,&level_or_rev_list);
        //}
    void start_reverse_order();
    std::vector<std::string>::iterator begin_reverse_order(){return level_or_rev_list.begin();}
    std::vector<std::string>::iterator reverse_order(){return level_or_rev_list.end();}
    //;{return Iterator(0,&level_or_rev_list);}
    void start_preorder();
    std::vector<std::string>::iterator begin_preorder(){return level_or_rev_list.begin();}//{return Iterator(0,&pre_list);}
    std::vector<std::string>::iterator end_preorder(){return level_or_rev_list.end();}//{return Iterator(pre_list.size()-1,&pre_list);}
    OrgChart &add_root(const std::string& role){return *this;}
    OrgChart &add_sub(const std::string& boss_role,const std::string& sub_role){return *this;}
    friend std::ostream &operator<<(std::ostream &COUT, const OrgChart& org){return COUT;}
    // friend Iterator begin();
    // friend Iterator end();
};
}
