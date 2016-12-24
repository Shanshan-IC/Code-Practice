class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)  return true;
        int left = depth(root->left);
        int right = depth(root->right);
        return abs(left-right)<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
    
    int depth(TreeNode* root) {
        if (!root)  return 0;
        return 1+max(depth(root->left), depth(root->right));
    }
};