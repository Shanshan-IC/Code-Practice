class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* prehead = prev;
        while (n--) head = head->next;
        ListNode* curr = head;
        while (head) {
            prehead=prehead->next;
            head=head->next;
        }
        prehead->next = prehead->next->next;
        return prev->next;
    }
};