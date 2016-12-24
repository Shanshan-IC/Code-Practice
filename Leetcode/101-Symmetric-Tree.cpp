class Solution {
public:
    bool isEqual(TreeNode* p, TreeNode* q) {
        if (!p && !q)   return true;
        if (!p || !q ||p->val != q->val)    return false;
        return isEqual(p->left, q->right) && isEqual(p->right, q->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root)  return true;
        return isEqual(root->left, root->right);
    }
};