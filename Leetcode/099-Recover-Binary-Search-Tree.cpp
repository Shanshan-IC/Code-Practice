/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* one = NULL;
    TreeNode* two = NULL;
    TreeNode* pre = new TreeNode(INT_MIN);
    
    void recoverTree(TreeNode* root) {
        help(root);
        swap(one->val, two->val);
    }
    
    void help(TreeNode* root) {
        if (!root)  return;
        help(root->left);
        if (!one && pre->val >= root->val)  one = pre;
        if (one && pre->val >= root->val)  two = root;
        pre = root;
        help(root->right);
    }
};