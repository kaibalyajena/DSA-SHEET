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

node* insertBegin(node* head,int data){
    node* new_node=new node(data);
    if(head==nullptr){
        return new_node;
    }
    new_node->next=head;
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
    return head;
}

node* insertPos(node* head,int pos,int data){
    node* new_node=new node(data);
    if(pos==1){
        new_node->next=head;
        return new_node;
    }
    node* curr=head;
    for(int i=1;i<=pos-2&&curr!=nullptr;i++){
        curr=curr->next;
    }
    if(curr==nullptr){
        return head;
    }
    new_node->next=curr->next;
    curr->next=new_node;
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
    //node* head=nullptr;
    head=insertBegin(head,0);
    printLL(head);
    cout<<endl;
    head=insertEnd(head,50);
    printLL(head);
    cout<<endl;
    head=insertPos(head,2,25);
    printLL(head);
    return 0;
}