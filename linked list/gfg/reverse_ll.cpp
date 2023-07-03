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
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//iterative approach
node* reverse(node* head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    node* curr=head;
    node* prev=nullptr;
    node* forw=nullptr;
    while(curr!=nullptr){
        forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    return prev;
}

//recursive approach
node* reverseRec(node* head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    node* rest=reverseRec(head->next);
    head->next->next=head;
    head->next=nullptr;
    return rest;
}

//pass head and null as parameters
node* recursiveRec2(node* curr,node* prev){
    if(curr==nullptr){
        return prev;
    }
    node* forw=curr->next;
    curr->next=prev;
    return recursiveRec2(forw,curr);
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
    head=reverse(head);
    printLL(head);
    head=reverseRec(head);
    printLL(head);
    return 0;
}