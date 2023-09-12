#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }

};

void InsertAtFirst(Node* head, int data) {
    Node temp = new Node(data);
    temp -> next = head;
    head = temp; 
}

void InsertAtLast(Node* tail, int data) {
    Node temp = new Node(data);
    tail = head -> next;
    tail = head;
}

void print(Node* head) {
    if (head == NULL) {
        cout << "Empty list";
    }
    Node* temp = head;
    cout << temp;
    temp = temp->next;

}

int main() {
    Node* node = new Node(1);
    cout << node->data << " " << node -> next << endl;

    return 0;
}