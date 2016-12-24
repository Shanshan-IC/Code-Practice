class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        
        helper(result, 0, num);
        return result;
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
        }
    }
};