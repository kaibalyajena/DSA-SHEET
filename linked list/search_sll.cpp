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

bool search(node* head,int x){
    node* temp=head;
    while(temp!=nullptr){
        if(temp->data==x){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

bool searchRec(node* head, int x){
    if(head==nullptr){
        return false;
    }
    if(head->data==x){
        return true;
    }
    return searchRec(head->next,x);
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
    cout<<search(head,20)<<endl;
    cout<<searchRec(head,60)<<endl;
    return 0;
}