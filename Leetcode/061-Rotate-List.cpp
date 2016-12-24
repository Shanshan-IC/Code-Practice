
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next)   return head;
        ListNode* curr = head;
        int len = 0;
        while (curr) {
            curr = curr->next;
            len++;
        }
        k %= len;
        if (k==0)   return head;
        curr = head;
        ListNode* prev = head;
        while (curr->next) {
            curr = curr->next;
            if (k)
                k--;
            else
                prev=prev->next;
        }
        curr->next = head;
        head = prev->next;
        prev->next = NULL;
        return head;
    }
};