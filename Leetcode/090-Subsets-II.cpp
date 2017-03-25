class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        helper(res, curr, nums, 0);
        return res;
    }
    
    void helper(vector<vector<int>> &res, vector<int> &curr, vector<int> &nums, int pos) {
        res.push_back(curr);
        for (int i=pos; i<nums.size(); i++) {
            curr.push_back(nums[i]);
            helper(res, curr, nums, i+1);
            while (nums[i]==nums[i+1])  i++;
            curr.pop_back();
        }
    }
};