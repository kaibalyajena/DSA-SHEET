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

node* deleteBegin(node* head){
  if(head==nullptr||head->next==head){
    return nullptr;
  }
  node* temp=head;
  while(temp->next!=head){
    temp=temp->next;
  }
  node* new_head=head->next;
  temp->next=new_head;
  delete head;
  return new_head;
}

node* deleteEnd(node* head){
   if(head==nullptr||head->next==head){
    return nullptr;
   }
   node* temp=head;
   while(temp->next->next!=head){
    temp=temp->next;
   }
   node* del=temp->next;
   temp->next=head;
   delete del;
   return head;
}

node* deletePos(node* head,int pos){
    if(head==nullptr){
        return head;
    }
    if(head->next==head && pos==1){
        return nullptr;
    }
    if(pos==1){
        head=deleteBegin(head);
        return head;
    }
    node* temp=head;
    for(int i=1;i<=pos-2;i++){
        temp=temp->next;
    }
    node* del=temp->next;
    temp->next=del->next;
    delete del;
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
    head=deletePos(head,4);
    // head=deleteBegin(head);
    // printLL(head);
    // cout<<endl;
    // head=deleteEnd(head);
    printLL(head);
    return 0;
}