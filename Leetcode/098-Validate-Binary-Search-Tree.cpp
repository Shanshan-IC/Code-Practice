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
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
    
    bool helper(TreeNode* root, TreeNode* minN, TreeNode* maxN) {
        if (!root)  return true;
        if (minN && root->val <= minN->val || maxN && root->val >= maxN->val)   return false;
        return helper(root->left, minN, root) && helper(root->right, root, maxN);
    }
};