class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward = nullptr;
        head = head->next;
        while (curr != nullptr && curr->next != nullptr) {
            forward = curr->next;
            curr->next = forward->next;
            forward->next = curr;
            if (prev != nullptr) {
                prev->next = forward;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};