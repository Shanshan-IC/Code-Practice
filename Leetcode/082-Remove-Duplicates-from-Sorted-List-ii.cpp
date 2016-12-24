/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prevhead = new ListNode(0);
        ListNode* prev = head;
        ListNode* point = prevhead;
        
        while (prev) {
            if (prev->next && prev->val == prev->next->val)
                while (prev->next && prev->val == prev->next->val)
                    prev = prev->next;
            else {
                point->next = prev;
                point = point ->next;
            }
            prev = prev->next;
        }
        point->next = NULL;
        return prevhead->next;
    }
};