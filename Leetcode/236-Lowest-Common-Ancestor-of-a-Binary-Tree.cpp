class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if (!root || root==p || root == q) return root;
         TreeNode* t1 = lowestCommonAncestor(root->left, p, q);
         TreeNode* t2 = lowestCommonAncestor(root->right, p, q);
         if (t1 && t2)  return root;
         return t1 ? t1:t2;
    }
};