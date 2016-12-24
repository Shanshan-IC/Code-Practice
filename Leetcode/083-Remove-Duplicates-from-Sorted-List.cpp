class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = head;
        while (prev) {
            if (prev->next && prev->val == prev->next->val)
                prev->next = prev->next->next;
            else
                prev = prev->next;
        }
        
        return head;
    }
};