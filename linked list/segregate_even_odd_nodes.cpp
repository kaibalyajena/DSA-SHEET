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

// Node *segregate(Node *head){
//     Node *eS=NULL,*eE=NULL,*oS=NULL,*oE=NULL;
//     for(Node *curr=head;curr!=NULL;curr=curr->next){
//         int x=curr->data;
//         if(x%2==0){
//             if(eS==NULL){
//                 eS=curr;
//                 eE=eS;
//             }else{
//                 eE->next=curr;
//                 eE=eE->next;
//             }
//         }else{
//             if(oS==NULL){
//                 oS=curr;
//                 oE=oS;
//             }else{
//                 oE->next=curr;
//                 oE=oE->next;
//             }
//         }
//     }
//     if(oS==NULL||eS==NULL)
//         return head;
//     eE->next=oS;
//     oE->next=NULL;
//     return eS;
// }


//coded myself
Node* segregate(Node* head){
    Node* curr=head;
    Node* prev=nullptr;
    Node* tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    //to know we have traversed all nodes once
    Node* stop=tail;
    while(prev!=stop){
        //to check if it is our last traversal
        //allow the processeing to happen and if curr and stop were equal at the start then this should be the last processing to just terminate the loop at the end
        Node* last=curr;
        Node* stop2=stop;
        if(curr->data%2!=0){
            Node* del=curr;
            if(prev==nullptr){
                head=head->next;
                curr=curr->next; 
            }else{
                curr=curr->next;
                prev->next=del->next;   
            }
            tail->next=del;
            del->next=nullptr;
            tail=del;

        }else{
            prev=curr;
            curr=curr->next;  
        }
        if(last==stop2){
            break;
        }
    }
    return head;
}

int main() 
{ 
	Node *head=new Node(17);
	head->next=new Node(15);
	head->next->next=new Node(8);
	head->next->next->next=new Node(12);
	head->next->next->next->next=new Node(10);
	head->next->next->next->next->next=new Node(5);
	head->next->next->next->next->next->next=new Node(4);
	printlist(head);
	head=segregate(head);
	printlist(head);
	return 0;
} 
