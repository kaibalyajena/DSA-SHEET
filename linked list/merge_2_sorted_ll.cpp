class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;
        if(list1->val <= list2->val){
            head=list1;
            tail=list1;
            list1=list1->next;
        }else{
            head=list2;
            tail=list2;
            list2=list2->next;
        }
        while(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val){
                tail->next=list1;
                tail=list1;
                list1=list1->next;
            }else{
                tail->next=list2;
                tail=list2;
                list2=list2->next;
            }
        }
        if(list1==NULL){
            tail->next=list2;
        }else{
            tail->next=list1;
        }
        return head;
    }
};