class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev=nullptr;
        while(node->next!=nullptr){
            int temp=node->val;
            node->val=node->next->val;
            node->next->val=temp;
            if(prev==nullptr){
                prev=node;
            }else{
                prev=prev->next;
            }
            node=node->next;
        }
        delete node;
        prev->next=nullptr;
    }
};