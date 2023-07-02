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

void printLL(node* head){
    if(head==nullptr){
        return;
    }
    // cout<<head->data<<" ";
    // for(node* i=head->next;i!=head;i=i->next){
    //     cout<<i->data<<" ";
    // }
    node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
}

node* insertBegin(node* head,int x){
    node* new_node=new node(x);
    if(head==nullptr){
        new_node->next=new_node;
        return new_node;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=head;
    return new_node;
}

node* insertEnd(node* head, int x){
    node* new_node=new node(x);
    if(head==nullptr){
        new_node->next=new_node;
        return new_node;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=head;
    return head;
}


int main(){
    node* head=new node(10);
    node* second=new node(20);
    node* third=new node(30);
    node* fourth=new node(40);
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=head;
    printLL(head);
    cout<<endl;
    head=insertBegin(head,0);
    printLL(head);
    cout<<endl;
    head=insertEnd(head,50);
    printLL(head);
    return 0;
}