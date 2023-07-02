#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

//another approach can be finding the length then forwarding len-n+1 times

void printNthFromEnd(Node * head,int n){
    if(head==nullptr){
        return;
    }
    Node* forward=head;
    Node* backward=head;
    for(int i=0;i<n;i++){
        if(forward==nullptr){
            return;
        }
        forward=forward->next;
    }
    while(forward!=nullptr){
        forward=forward->next;
        backward=backward->next;
    }
    cout<<backward->data<<endl;
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
	printlist(head);
	cout<<"Nth node from end of Linked List: ";
	printNthFromEnd(head,4);
	return 0;
} 