#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
 
struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }
    //iterative
    void reverse(){
        Node* current=head;
        Node* prev=nullptr;
        Node* next=nullptr;
        while(current!=nullptr){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
    }
    //recursive
    Node* reverseRec(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        /* reverse the rest list and put
          the first element at the end */
        Node* rest = reverseRec(head->next);
        head->next->next = head;
 
        /* tricky step -- see the diagram */
        head->next = NULL;
 
        /* fix the head pointer */
        return rest;
    }
    void print(){
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void push(int data){
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main(){
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
    cout << "Given linked list\n";
    ll.print();
    ll.reverseRec(ll.head);
    cout << "\nReversed linked list \n";
    ll.print();
    return 0;
}
