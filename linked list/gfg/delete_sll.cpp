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

node* deleteEnd(node* head){
    if(head==nullptr){
        return head;
    }
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}

node* deleteBegin(node* head){
    if(head==nullptr){
        return head;
    }
    node* new_head=head->next;
    delete head;
    return new_head;
}

int main(){
    node* head=new node(10);
    node* second=new node(20);
    node* third=new node(30);
    node* fourth=new node(40);
    head->next=second;
    second->next=third;
    third->next=fourth;
    //node* head=nullptr;
    head=deleteBegin(head);
    printLL(head);
    cout<<endl;
    head=deleteEnd(head);
    printLL(head);
    return 0;
}