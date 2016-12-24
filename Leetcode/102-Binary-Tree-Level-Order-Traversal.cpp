class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)  return res;
        helper(root, res, 0);
        return res;
    }
    
    void helper(TreeNode* root, vector<vector<int>> &res, int depth) {
        if (!root)  return;
        if (res.size() <depth+1)
            res.push_back(vector<int>());
        res[depth].push_back(root->val);
        helper(root->left, res, depth+1);
        helper(root->right, res, depth+1);
    }
};