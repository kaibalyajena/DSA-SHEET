class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // ListNode* temp=head;
        // ListNode* del;
        // while(temp!=NULL){
        //     if((temp->next!=NULL)&&(temp->val==temp->next->val)){
        //         del=temp->next;
        //         temp->next=del->next;
        //         delete del;
        //     }else{
        //         temp=temp->next;
        //     }
        // }
        // return head;
        ListNode* temp=head;
        while(temp!=NULL){
            if((temp->next!=NULL) && (temp->val==temp->next->val)){
                ListNode* del=temp->next;
                temp->next=del->next;
                delete del;
            }else{
                temp=temp->next;
            }
        }
        return head;
    }
};