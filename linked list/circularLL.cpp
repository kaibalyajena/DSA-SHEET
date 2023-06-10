class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

class circularLinkedList{
    public:
    node* head;
    circularLinkedList(){
        this->head=nullptr;
    }
    void addNode(int data){
        node* new_node=new node(data);
        if(this->head==nullptr){
            this->head=new_node;
            new_node->next=this->head;
            return;
        }
        node* current=head;
        while(current->next!=head){
            current=current->next;
        }
        current->next=new_node;
        new_node->next=this->head;
        this->head=new_node;
    }
};