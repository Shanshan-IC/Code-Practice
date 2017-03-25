class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        helper(res, curr, nums, 0);
        return res;
    }
    
    void helper(vector<vector<int>> &res, vector<int> &curr, vector<int> &nums, int pos) {
        res.push_back(curr);
        for (int i=pos; i<nums.size(); i++) {
            curr.push_back(nums[i]);
            helper(res, curr, nums, i+1);
            curr.pop_back();
        }
    }
};