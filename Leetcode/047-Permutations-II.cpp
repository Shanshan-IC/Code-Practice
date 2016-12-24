class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res, 0, nums);
        return res;
    }
    
    void helper(vector<vector<int>> &res, int begin, vector<int>& nums) {
        if (begin >= nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i=begin; i<nums.size(); i++) {
            
            swap(nums[i], nums[begin]);
            helper(res, begin+1, nums);
            swap(nums[i], nums[begin]);
            while (i<nums.size() && nums[i]==nums[i-1])
                i++;
        }
    }
};