#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
    node(int x){
        data=x;
        next=prev=nullptr;
    }
};

void printLL(node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}

node* reverse(node* head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    node* previous=nullptr;
    node* curr=head;
    while(curr!=nullptr){
        previous=curr->prev;
        curr->prev=curr->next;
        curr->next=previous;
        curr=curr->prev;
    }
    return previous->prev;
}

int main(){
    node* head=new node(10);
    node* second=new node(20);
    node* third=new node(30);
    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    printLL(head);
    head=reverse(head);
    cout<<endl;
    printLL(head);
    return 0;
}