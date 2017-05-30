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
    int res = 0;
    int getHeight(TreeNode* root) {
        if (!root)  return -1;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        int temp = leftHeight+rightHeight+2;
        res = max(res, temp);
        return max(leftHeight, rightHeight)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);
        return res;
    }
};