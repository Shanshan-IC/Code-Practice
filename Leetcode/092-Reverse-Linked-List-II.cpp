class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        ListNode* tail = prehead;
        n -= m;
        while(--m > 0) tail = tail->next;
        ListNode* curr = tail->next;
        while(n-- > 0){ // pull one out to tail
            ListNode* temp = curr->next;
            curr->next = temp->next; 
            temp->next = tail->next; // easy to make mistake
            tail->next = temp;
        }
        return prehead->next;
    }
};
