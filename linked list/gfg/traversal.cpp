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

//recursive
void printLLRec(node* head){
    if(head==nullptr){
        return;
    }
    cout<<head->data<<" ";
    printLLRec(head->next);
}

int main(){
    node* head=new node(10);
    node* second=new node(20);
    node* third=new node(30);
    node* fourth=new node(40);
    head->next=second;
    second->next=third;
    third->next=fourth;
    printLL(head);
    cout<<endl;
    printLLRec(head);
    return 0;
}