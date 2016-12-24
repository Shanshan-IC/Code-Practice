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
    TreeNode* invertTree(TreeNode* tree) {
        if (!tree)  return tree;
        TreeNode* temp = tree->left;
        tree->left = invertTree(tree->right);
        tree->right = invertTree(temp);
        return tree;
    }
};