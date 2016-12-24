class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)  return NULL;
        if (!head->next)    return new TreeNode(head->val);
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* tail = NULL;
        while (fast && fast->next) {
            tail = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        tail->next = NULL;
        TreeNode* node = new TreeNode(slow->val);
        node->left = sortedListToBST(head);
        node->right = sortedListToBST(slow->next);
        return node;
    }
};