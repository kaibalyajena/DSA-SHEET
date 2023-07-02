#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node(int x){
        data=x;
        next=nullptr;
    }
};

//iterative
void printLL(node* head){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

node* sortedInsert(node* head,int x){
    node* new_node=new node(x);
    if(head==nullptr){
        return new_node;
    }
    node* temp=head;
    node* prev=nullptr;
    while(temp!=nullptr&&temp->data<x){
        prev=temp;
        temp=temp->next;
    }
    if(prev==nullptr){
        new_node->next=head;
        return new_node;
    }
    new_node->next=prev->next;
    prev->next=new_node;
    return head;
}

int main(){
    node* head=new node(10);
    // node* second=new node(20);
    // node* third=new node(30);
    // node* fourth=new node(40);
    // head->next=second;
    // second->next=third;
    // third->next=fourth;
    //node* head=nullptr;
    printLL(head);
    cout<<endl;
    head=sortedInsert(head,25);
    printLL(head);
    return 0;
}