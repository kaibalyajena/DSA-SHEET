#include <bits/stdc++.h> 
#include<unordered_set>
using namespace std; 

struct Node{
    int data;
    Node* next;
    //bool visited;
    Node(int x){
        data=x;
        next=NULL;
        //visited=false;
    }
};

//method 1
//traverse every node and while doing that again traverse all the nodes before it check if curr->next=prev_node.
// bool isLoop(Node* head){
//     Node* temp=head;
//     while(temp!=nullptr){
//         Node* back=head;
//         while(back!=temp){
//             if(back==temp->next){
//                 return true;
//             }
//             back=back->next;
//         }
//         temp=temp->next;
//     }
//     return false;
// }

// method 2 change the linked list node structure to add visited field
// bool isLoop(Node* head){
//     Node* temp=head;
//     while(temp!=nullptr){
//         if(temp->visited==true){
//             return true;
//         }
//         temp->visited=true;
//         temp=temp->next;
//     }
//     return false;
// }


//method 3
//change the pointers to a dummy node and check if node->next->next=dummy_node
// bool isLoop(Node* head){
//     Node* dummy_node=new Node(0);
//     while(head!=nullptr){
//         if(head->next==nullptr){
//             return false;
//         }
//         if(head->next->next==dummy_node){
//             return true;
//         }
//         Node* forw=head->next;;
//         head->next=dummy_node;
//         head=forw;
//     }
//     return false;
// } 

//method 4 
//hashing
// bool isLoop(Node* head){
//     unordered_set<Node*> s;
//     while(head!=nullptr){
//         if(s.find(head)!=s.end()){
//             return true;
//         }
//         s.insert(head);
//         head=head->next;
//     }
//     return false;
// }

//floyd cycle detection
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

int main() 
{ 
	Node *head=new Node(15);
	head->next=new Node(10);
	head->next->next=new Node(12);
	head->next->next->next=new Node(20);
	head->next->next->next->next=head->next;
	if (isLoop(head)) 
        cout << "Loop found"; 
    else
        cout << "No Loop"; 
	return 0;
} 
