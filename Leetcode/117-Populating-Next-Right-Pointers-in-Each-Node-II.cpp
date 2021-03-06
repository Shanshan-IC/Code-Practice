/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)  return;
        TreeLinkNode dummy(INT_MIN);
        for (TreeLinkNode *cur = root, *pre = &dummy; cur; cur = cur->next) {
            if (cur -> left) {
                pre -> next = cur -> left;
                pre = pre -> next;
            } 
            if (cur -> right) {
                pre -> next = cur -> right;
                pre = pre -> next;
            }
        }
        connect(dummy.next);
        
    }
};