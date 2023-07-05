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

node* deleteBegin(node* head){
    if(head==nullptr){
        return nullptr;
    }
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    node* temp=head;
    head=head->next;
    head->prev=nullptr;
    delete temp;
    return head;
}

node* deleteEnd(node* head){
    if(head==nullptr){
        return nullptr;
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

int main(){
    node* head=new node(10);
    node* second=new node(20);
    node* third=new node(30);
    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    printLL(head);
    cout<<endl;
    head=deleteBegin(head);
    printLL(head);
    cout<<endl;
    head=deleteEnd(head);
    printLL(head);
    return 0;
}