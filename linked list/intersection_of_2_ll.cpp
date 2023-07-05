#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int data; 
	Node* next; 
	Node (int x){
	    data=x;
	    next=NULL;
	}
}; 

int getIntersection(Node* head1, Node* head2) 
{ 
    unordered_set<Node*> s;
    Node* curr=head1;
    while(curr!=NULL){
        s.insert(curr);
        curr=curr->next;
    }
    curr=head2;
    while(curr!=NULL){
        if(s.find(curr)!=s.end())
            return curr->data;
        curr=curr->next;
    }
    return -1;
} 

int main() 
{ 
	Node* newNode; 
	Node* head1 = new Node(10); 
	Node* head2 = new Node(3); 
	newNode = new Node(6); 
	head2->next = newNode; 
	newNode = new Node(9); 
	head2->next->next = newNode; 
	newNode = new Node(15); 
	head1->next = newNode; 
	head2->next->next->next = newNode; 
	newNode = new Node(30); 
	head1->next->next = newNode; 
	head1->next->next->next = NULL; 
	cout <<getIntersection(head1, head2); 
}






class Solution {
public:
    int length(ListNode* head){
        int len=0;
        while(head!=nullptr){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr||headB==nullptr){
            return nullptr;
        }
        int lenA=length(headA);
        int lenB=length(headB);
        if(lenA>lenB){
            while(lenA>lenB){
                headA=headA->next;
                lenA--;
            }
        }else if(lenB>lenA){
            while(lenB>lenA){
                headB=headB->next;
                lenB--;
            }
        }
        while(headA!=nullptr&&headB!=nullptr){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return nullptr;
    }
};