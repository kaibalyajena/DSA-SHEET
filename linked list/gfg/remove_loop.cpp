#include <bits/stdc++.h> 
#include<unordered_set>
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

bool isLoop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false; 
}

Node* removeLoop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    if(slow!=fast){
        return head;
    }
    slow=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=nullptr;
    return head;
}

int main() 
{ 
	Node *head=new Node(15);
	head->next=new Node(10);
	head->next->next=new Node(12);
	head->next->next->next=new Node(20);
	head->next->next->next->next=head->next;
	if (isLoop(head)) 
        cout << "Loop found"<<endl; 
    else
        cout << "No Loop";
    head=removeLoop(head);
    if (isLoop(head)) 
        cout << "Loop found"; 
    else
        cout << "No Loop";
	return 0;
} 
