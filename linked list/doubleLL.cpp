class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};

class doubleLinkedList{
    public:
    node* head;
    doubleLinkedList(){
        this->head=nullptr;
    }
    void addNode(int data){
        node* new_node=new node(data);
        new_node->next=this->head;
        if(this->head!=nullptr){
            this->head->prev=new_node;
        }
        this->head=new_node;
    }
};