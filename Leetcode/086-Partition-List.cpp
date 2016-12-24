class Solution {
public:
    ListNode* partition(ListNode* root, int x) {
        if (!root || !root->next)  return root;
        ListNode* l1 = new ListNode(0);
        ListNode* p1 = l1;
        ListNode* l2 = new ListNode(0);
        ListNode* p2 = l2;
        while (root) {
            if (root->val < x) {
                p1->next = root;
                p1 = p1->next;
            }
            else {
                p2->next = root;
                p2 = p2->next;
            }
            root = root->next;
        }
        p2->next = NULL;
        p1->next = l2->next;
        return l1->next;
    }
};