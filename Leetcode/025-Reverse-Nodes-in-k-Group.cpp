class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k==1)  return head;
        int cnt = 0;
        ListNode* curr = head;
        while (curr && cnt != k) {
            curr = curr ->next;
            cnt++;
        }
        if (cnt == k) {
            curr = reverseKGroup(curr, k);
            while (cnt-- >0){
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
            }
            head = curr;
        }
        return head;
    }
};