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

node* insertBegin(node* head,int data){
    node* new_node=new node(data);
    if(head==nullptr){
        return new_node;
    }
    new_node->next=head;
    head->prev=new_node;
    return new_node;
}

node* insertEnd(node* head,int data){
    node* new_node=new node(data);
    if(head==nullptr){
        return new_node;
    }
    node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;
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
    head=insertBegin(head,0);
    printLL(head);
    cout<<endl;
    head=insertEnd(head,40);
    printLL(head);
    return 0;
}