class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> curr;
        if (!root)  return res;
        helper(res, curr, root, sum, 0);
        return res;
    }
    
    void helper(vector<vector<int>> &res, vector<int> &curr, TreeNode* root, int sum, int total) {
        if (!root)  return;
        curr.push_back(root->val);
        total += root->val;
        if (!root->left && !root->right) {
            if (total == sum)   res.push_back(curr);
            curr.pop_back();
            return;
        }
        helper(res, curr, root->left, sum, total);
        helper(res, curr, root->right, sum, total);
        curr.pop_back();
    }
};