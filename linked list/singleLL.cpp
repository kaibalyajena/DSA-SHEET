class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

class singlyLinkedList{
    public:
    node* head;
    singlyLinkedList(){
        this->head=nullptr;
    }
    void addNode(int data){
        node* new_node=new node(data);
        new_node->next=this->head;
        this->head=new_node;
    }
};