#include "OrgChart.hpp"
#include <iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

// namespace ariel{
// Node::Node(const Node * other){
//     if(other != nullptr) {
//         this->role_name = other->role_name;
//         this->subordinate=other->subordinate;
//     }
// }
// Node* Node::Find(const string role){
//     if (this->getrole()==role)
//     {
//         return this;
//     }
//     Node * ans = nullptr;
//         for (auto it = this->subordinate.begin();it != this->subordinate.end();++it)
//         {
//             ans=(*it)->Find(role);
//             if (ans!=nullptr)
//             {
//                 return ans;
//             }
            
//         }
//         return ans; 
// }



// // OrgChart::Node::Node(string& role){
// //     this->role_name=role;
// // }

// OrgChart& OrgChart::add_root(const string& role){
//     if (this->head==nullptr){
//         this->head = new Node(role);
//     }
//     else
//         this->head->setrole(role);

//     return *this;   
// }
// OrgChart& OrgChart::add_sub(const std::string& boss_role,const std::string& sub_role){
//     Node * p=this->head->Find(boss_role);
//     if (p==nullptr)
//     {
//         throw ("Cant find the patent you are searching for");
//     }
//     Node *new_role=new Node(sub_role);
//     p->subordinate.push_back(new_role);
//     return *this;

// }

// bool operator == (OrgChart::Iterator const &lhs, OrgChart::Iterator  const &rhs) {
//         return lhs.order_vec->at(lhs.index) == rhs.order_vec->at(rhs.index);
//     }

// OrgChart::Iterator OrgChart::begin_level_order(){
//     level_or_reverse_order(false);
//     return Iterator(0,&level_or_rev_list);
// }
// OrgChart::Iterator OrgChart::begin_reverse_order(){
//     level_or_reverse_order(true);
//     return Iterator(0,&level_or_rev_list);
// }

// void OrgChart::level_or_reverse_order(bool revrese_flag){
//     this->level_or_rev_list.clear();
//     if (this->head==nullptr)
//         return;
//     queue<Node *> q;  // Create a queue
//     q.push(this->head); // Enqueue root
//     while (!q.empty())
//     {
//             // Dequeue an item from queue and print it
//             Node * curr_node=q.front();
//             this->level_or_rev_list.push_back(curr_node);
//             q.pop();
//             // Enqueue all children of the dequeued item
//             if(!revrese_flag){
//                 for (auto child : curr_node->subordinate)
//                     q.push(child);
//             }
//             else{
//                 for (vector<Node*>::reverse_iterator revrese_child = curr_node->subordinate.rbegin(); revrese_child != curr_node->subordinate.rend(); ++revrese_child ) {
//                     q.push(*revrese_child);    
//                 }
//             }
//             if(revrese_flag){
//                 reverse(this->level_or_rev_list.begin(), this->level_or_rev_list.end());
//             }
//             this->level_or_rev_list.push_back(nullptr);        
//     }

// }
// }

