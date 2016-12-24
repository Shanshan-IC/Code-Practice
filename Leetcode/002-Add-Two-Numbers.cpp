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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)    return l2;
        if (!l2)    return l1;
        int carry = 0;
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* res = new ListNode(0);
        ListNode* prev = res;
        while (l1 || l2 || carry) {
            int sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (carry) {
                sum += carry;
                carry = 0;
            }
            if (sum>9) {
                sum -= 10;
                carry = 1;
            }
            prev->next = new ListNode(sum);
            prev = prev->next;
        }
        return res->next;
    }
};