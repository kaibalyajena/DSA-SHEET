//iterative
class Solution {
public:
    int length(ListNode* head){
        int len=0;
        while(head!=nullptr){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        ListNode* prevFirst=nullptr;
        bool isFirstPass=true;
        while(curr!=nullptr){
            int len=length(curr);
            if(len>=k){
                ListNode* first=curr;
                ListNode* prev=nullptr;
                int count=0;
                while(curr!=nullptr&&count<k){
                    ListNode* forw=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=forw;
                    count++;
                }
                if(isFirstPass==true){
                    head=prev;
                    isFirstPass=false;
                }else{
                    prevFirst->next=prev;
                }
                prevFirst=first;
            }else{
                prevFirst->next=curr;
                return head;
            }
        }
        return head;
    }
};
//recursive
class Solution {
public:
    int length(ListNode* head){
        int len=0;
        while(head!=nullptr){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* forw=nullptr;
        int len=length(head);
        if(len>=k){
            while(curr!=nullptr&&count<k){
                forw=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forw;
                count++;
            }
            if(forw!=nullptr){
                head->next=reverseKGroup(forw,k);
            }
            return prev;
        }else{
            return head;
        }
    }
};