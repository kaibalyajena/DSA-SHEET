class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* temp=head;
        while(temp!=nullptr){
            s.push(temp->val);
            temp=temp->next;
        }
        ListNode* temp2=head;
        while(temp2!=nullptr){
            if(s.top()!=temp2->val){
                return false;
            }
            s.pop();
        }
        return true;
    }
};


class Solution {
public:
    ListNode* reverse(ListNode *head){
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* forw=nullptr;
        while(curr!=nullptr){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* middle=head;
        ListNode* fast=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
            fast=fast->next->next;
            middle=middle->next;
        }
        ListNode* reversed=reverse(middle->next);
        while(reversed!=nullptr){
            if(head->val!=reversed->val){
                return false;
            }
            head=head->next;
            reversed=reversed->next;
        }
        return true;
    }
};